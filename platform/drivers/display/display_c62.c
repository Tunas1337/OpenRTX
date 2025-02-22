/***************************************************************************
 *   Copyright (C) 2023 by Federico Izzo IU2NUO,                           *
 *                         Niccolò Izzo IU2KIN,                            *
 *                         Silvano Seva IU2KWO                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(sample, LOG_LEVEL_INF);

#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/kernel.h>

#include <interfaces/display.h>
#include <hwconfig.h>
#include <stddef.h>

enum corner {
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_RIGHT,
	BOTTOM_LEFT
};

typedef void (*fill_buffer)(enum corner corner, uint8_t grey, uint8_t *buf, size_t buf_size);


static void fill_buffer_argb8888(enum corner corner, uint8_t grey, uint8_t *buf, size_t buf_size)
{
	uint32_t color = 0;

	switch (corner) {
	case TOP_LEFT:
		color = 0x00FF0000u;
		break;
	case TOP_RIGHT:
		color = 0x0000FF00u;
		break;
	case BOTTOM_RIGHT:
		color = 0x000000FFu;
		break;
	case BOTTOM_LEFT:
		color = grey << 16 | grey << 8 | grey;
		break;
	}

	for (size_t idx = 0; idx < buf_size; idx += 4) {
		*((uint32_t *)(buf + idx)) = color;
	}
}

static void fill_buffer_rgb888(enum corner corner, uint8_t grey, uint8_t *buf, size_t buf_size)
{
	uint32_t color = 0;

	switch (corner) {
	case TOP_LEFT:
		color = 0x00FF0000u;
		break;
	case TOP_RIGHT:
		color = 0x0000FF00u;
		break;
	case BOTTOM_RIGHT:
		color = 0x000000FFu;
		break;
	case BOTTOM_LEFT:
		color = grey << 16 | grey << 8 | grey;
		break;
	}

	for (size_t idx = 0; idx < buf_size; idx += 3) {
		*(buf + idx + 0) = color >> 16;
		*(buf + idx + 1) = color >> 8;
		*(buf + idx + 2) = color >> 0;
	}
}

static uint16_t get_rgb565_color(enum corner corner, uint8_t grey)
{
	uint16_t color = 0;
	uint16_t grey_5bit;

	switch (corner) {
	case TOP_LEFT:
		color = 0xF800u;
		break;
	case TOP_RIGHT:
		color = 0x07E0u;
		break;
	case BOTTOM_RIGHT:
		color = 0x001Fu;
		break;
	case BOTTOM_LEFT:
		grey_5bit = grey & 0x1Fu;
		/* shift the green an extra bit, it has 6 bits */
		color = grey_5bit << 11 | grey_5bit << (5 + 1) | grey_5bit;
		break;
	}
	return color;
}

static void fill_buffer_rgb565(enum corner corner, uint8_t grey, uint8_t *buf, size_t buf_size)
{
	uint16_t color = get_rgb565_color(corner, grey);

	for (size_t idx = 0; idx < buf_size; idx += 2) {
		*(buf + idx + 0) = (color >> 8) & 0xFFu;
		*(buf + idx + 1) = (color >> 0) & 0xFFu;
	}
}

static void fill_buffer_bgr565(enum corner corner, uint8_t grey, uint8_t *buf, size_t buf_size)
{
	uint16_t color = get_rgb565_color(corner, grey);

	for (size_t idx = 0; idx < buf_size; idx += 2) {
		*(uint16_t *)(buf + idx) = color;
	}
}

static void fill_buffer_mono(enum corner corner, uint8_t grey, uint8_t *buf, size_t buf_size)
{
	uint16_t color;

	switch (corner) {
	case BOTTOM_LEFT:
		color = (grey & 0x01u) ? 0xFFu : 0x00u;
		break;
	default:
		color = 0;
		break;
	}

	memset(buf, color, buf_size);
}

void display_init()
{
    size_t x;
    size_t y;
    size_t rect_w;
    size_t rect_h;
    size_t h_step;
    size_t scale;
    size_t grey_count;
    uint8_t *buf;
    int32_t grey_scale_sleep;
    const struct device *display_dev;
    struct display_capabilities capabilities;
    struct display_buffer_descriptor buf_desc;
    size_t buf_size = 0;
    fill_buffer fill_buffer_fnc = NULL;

  /* 获取display设备实例 */
    display_dev = DEVICE_DT_GET(DT_INST(0, sitronix_st7735r));

    if (display_dev == NULL) {
        LOG_ERR("Device not found. Aborting sample.");
        return;
    }

  /* 获取显示功能 */
    display_get_capabilities(display_dev, &capabilities);

    if (capabilities.screen_info & SCREEN_INFO_MONO_VTILED) {
        rect_w = 16;
        rect_h = 8;
    } else {
        rect_w = 2;
        rect_h = 1;
    }

    h_step = rect_h;
    scale = (capabilities.x_resolution / 8) / rect_h;

    rect_w *= scale;
    rect_h *= scale;

    if (capabilities.screen_info & SCREEN_INFO_EPD) {
        grey_scale_sleep = 10000;
    } else {
        grey_scale_sleep = 100;
    }

    buf_size = rect_w * rect_h;

    if (buf_size < (capabilities.x_resolution * h_step)) {
        buf_size = capabilities.x_resolution * h_step;
    }

  /* 色块配置 */
    switch (capabilities.current_pixel_format) {
    case PIXEL_FORMAT_ARGB_8888:
        fill_buffer_fnc = fill_buffer_argb8888;
        buf_size *= 4;
        break;
    case PIXEL_FORMAT_RGB_888:
        fill_buffer_fnc = fill_buffer_rgb888;
        buf_size *= 3;
        break;
    case PIXEL_FORMAT_RGB_565:
        fill_buffer_fnc = fill_buffer_rgb565;
        buf_size *= 2;
        break;
    case PIXEL_FORMAT_BGR_565:
        fill_buffer_fnc = fill_buffer_bgr565;
        buf_size *= 2;
        break;
    case PIXEL_FORMAT_MONO01:
    case PIXEL_FORMAT_MONO10:
        fill_buffer_fnc = fill_buffer_mono;
        buf_size /= 8;
        break;
    default:
        LOG_ERR("Unsupported pixel format. Aborting sample.");
        return;
    }

    buf = k_malloc(buf_size);

    if (buf == NULL) {
        LOG_ERR("Could not allocate memory. Aborting sample.");
        return;
    }

    (void)memset(buf, 0xFFu, buf_size);

    buf_desc.buf_size = buf_size;
    buf_desc.pitch = capabilities.x_resolution;
    buf_desc.width = capabilities.x_resolution;
    buf_desc.height = h_step;

  /*整屏填充白色背景*/
    for (int idx = 0; idx < capabilities.y_resolution; idx += h_step) {
        display_write(display_dev, 0, idx, &buf_desc, buf);
    }

    buf_desc.pitch = rect_w;
    buf_desc.width = rect_w;
    buf_desc.height = rect_h;

  /*左上角填充红色块*/
    fill_buffer_fnc(TOP_LEFT, 0, buf, buf_size);
    x = 0;
    y = 0;
    display_write(display_dev, x, y, &buf_desc, buf);

  /*右上角填充绿色块*/
    fill_buffer_fnc(TOP_RIGHT, 0, buf, buf_size);
    x = capabilities.x_resolution - rect_w;
    y = 0;
    display_write(display_dev, x, y, &buf_desc, buf);

  /*右下角填充蓝色块*/
    fill_buffer_fnc(BOTTOM_RIGHT, 0, buf, buf_size);
    x = capabilities.x_resolution - rect_w;
    y = capabilities.y_resolution - rect_h;
    display_write(display_dev, x, y, &buf_desc, buf);

  /* 关闭显示消隐 */
    display_blanking_off(display_dev);

    grey_count = 0;
    x = 0;
    y = capabilities.y_resolution - rect_h;

  /*左下角灰色动态色块*/
    while (1) {
        fill_buffer_fnc(BOTTOM_LEFT, grey_count, buf, buf_size);
        display_write(display_dev, x, y, &buf_desc, buf);
        ++grey_count;
        k_msleep(grey_scale_sleep);
    }
}

void display_terminate()
{

}

void display_renderRows(uint8_t startRow, uint8_t endRow, void *fb)
{
    (void) startRow;
    (void) endRow;
    (void) fb;
}

void display_render(void *fb)
{
    (void) fb;
}

void display_setContrast(uint8_t contrast)
{
    (void) contrast;
}

void display_setBacklightLevel(uint8_t level)
{
    (void) level;
}
