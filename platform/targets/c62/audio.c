#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include "AudioSystem.h"
#include "AudioTrack.h"
#include "AudioRecord.h"
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>


#define SAMPLE_RATE (16000)    // Sample rate in Hz
#define CHANNEL_CNT (1)
#define RECORD_SECS       (5)
#define RECORD_SAMPLE_CNT (SAMPLE_RATE * RECORD_SECS)

#define C62_AUDIO_CHANNEL_MIC     CHANNEL_IN_LEFT
#define C62_AUDIO_CHANNEL_SPK     CHANNEL_OUT_MONO

static const struct gpio_dt_spec btn = GPIO_DT_SPEC_GET(DT_NODELABEL(sidekey), gpios);
static const struct gpio_dt_spec led_green = GPIO_DT_SPEC_GET(DT_ALIAS(ledgreen), gpios);
static struct gpio_callback btn_cb_data;

static AudioRecord s_record_obj;
static AudioTrack s_track_obj;

static struct k_sem s_sem_record;
static volatile bool s_busy;

__attribute__((section(".psram_section"))) static uint8_t
	recording[sizeof(uint16_t) * RECORD_SAMPLE_CNT * CHANNEL_CNT];


#define FREQUENCY 440        // Frequency of the sine wave in Hz (A4)

static void fillSineWave(uint8_t *buffer, size_t size) {
    // Calculate the sine wave
    for (size_t i = 0; i < size / sizeof(int16_t); i++) {
        // Calculate sample value
        double sample = sin(2.0 * M_PI * FREQUENCY * (i / (double)SAMPLE_RATE));

        // Scale to 16-bit PCM range (-32768 to 32767)
        int16_t pcmValue = (int16_t)(sample * 32767);
        
        // Store the PCM value in the buffer
        buffer[2 * i] = (uint8_t)(pcmValue & 0xFF);          // LSB
        buffer[2 * i + 1] = (uint8_t)((pcmValue >> 8) & 0xFF); // MSB
    }
}

static void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());

	if (!s_busy) {
		k_sem_give(&s_sem_record);
	}
}

void test_audio_loop(void)
{
	int ret;

	printk("test_audio_loop\n");

	k_sem_init(&s_sem_record, 0, 1);

	ret = gpio_pin_configure_dt(&btn, GPIO_INPUT);
	assert(0 == ret);

	ret = gpio_pin_configure_dt(&led_green, GPIO_OUTPUT_INACTIVE);
	assert(0 == ret);

	String8 param;
	String8_ctor_char(&param, "ADC_PDM_GAIN_A_LEFT=6;"
				  "ADC_PDM_GAIN_D_LEFT=20;"
				  "ADC_PDM_GAIN_A_RIGHT=6;"
				  "ADC_PDM_GAIN_D_RIGHT=20");
	ret = AudioSystem_setParameters(0, &param);
	String8_dtor(&param);
	assert(0 == ret);

	AudioRecord *record = &s_record_obj;
	ret = AudioRecord_ctor(record, 0, SAMPLE_RATE, PCM_16_BIT, C62_AUDIO_CHANNEL_MIC, 0, NULL);
	assert(0 == ret);

	AudioTrack *track = &s_track_obj;
	ret = AudioTrack_ctor(track, SAMPLE_RATE, PCM_16_BIT, C62_AUDIO_CHANNEL_SPK, 0, NULL);
	assert(0 == ret);

	ret = gpio_pin_interrupt_configure_dt(&btn, GPIO_INT_EDGE_TO_ACTIVE);
	assert(0 == ret);

	gpio_init_callback(&btn_cb_data, button_pressed, BIT(btn.pin));
	gpio_add_callback(btn.port, &btn_cb_data);

	ssize_t size;
	while (1) {

		printk("Press the button\n");
		gpio_pin_set_dt(&led_green, 1);

		k_sem_take(&s_sem_record, K_FOREVER);
		s_busy = true;

		printk("Records 5 seconds...\n");

		AudioRecord_start(record);
		size = AudioRecord_read(record, recording,
					sizeof(int16_t) * RECORD_SAMPLE_CNT * CHANNEL_CNT);
		AudioRecord_stop(record);
		assert(size > 0);

		gpio_pin_set_dt(&led_green, 0);

		//For testing purposes, fill the buffer with a sine wave instead of the recorded audio
		//fillSineWave(recording, sizeof(int16_t) * RECORD_SAMPLE_CNT * CHANNEL_CNT);

		printk("Plays 5 seconds...\n");

		AudioTrack_start(track);
		size = AudioTrack_write(track, recording, size);
		assert(size > 0);
		AudioTrack_stop(track);
        
		s_busy = false;
	}

    assert(0 == gpio_remove_callback(btn.port, &btn_cb_data) );
}
