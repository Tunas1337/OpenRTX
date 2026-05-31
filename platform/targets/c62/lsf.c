/*
 * Copyright(c) 2023 LISTENAI
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT lsf_service_controller

#include <zephyr/device.h>
#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(lsf, LOG_LEVEL_DBG);

#include <lsf.h>
#include <ic_proxy.h>
#include <ic_fence.h>

#include <controller.h>
#include <service.h>
#include "cache.h"

static volatile bool inited = false;

int lsf_controller_init(void)
{
	int ret;

	if (inited) {
		return 0;
	}

	printk("=== LSF Controller Init Start ===\n");
	printk("Checking DSP boot status (0x30700000): 0x%08x\n", *(volatile uint32_t *)0x30700000);
	printk("Checking DSP magic (0x30700004): 0x%08x\n", *(volatile uint32_t *)0x30700004);
	printk("Checking DSP diag (0x3070000C): 0x%08x\n", *(volatile uint32_t *)0x3070000C);
	printk("Checking DSP check2 (0x30700018): 0x%08x\n", *(volatile uint32_t *)0x30700018);

	/* Initialize LSF */
	lsf_init();
	printk("LSF Initialized. Connecting...\n");
	lsf_connect();
	printk("LSF Connected. Monitoring DSP diag...\n");

	while (1) {
		k_sleep(K_MSEC(1000));
		dcache_invalidate_range(0x30700000, 0x30700020);
		uint32_t d = *(volatile uint32_t *)0x3070000C;
		printk("[DSP] diag=0x%08x\n", d);
	}

	STRUCT_SECTION_FOREACH(lsf_service, service) {
		LOG_DBG("Initializing service %s", service->name);

		ret = service->init();
		if (ret != 0) {
			LOG_ERR("Failed to initialize service %s: %d", service->name, ret);
			return ret;
		}
	}

	LOG_DBG("All services initialized");

	inited = true;

	return 0;
}

static int lsf_controller_init_internal(const struct device *dev)
{
	ARG_UNUSED(dev);

#if DT_HAS_CHOSEN(lsf_dsp_firmware)
	return lsf_controller_init();
#else  /* DT_HAS_CHOSEN(lsf_dsp_firmware) */
	return 0;
#endif /* DT_HAS_CHOSEN(lsf_dsp_firmware) */
}

DEVICE_DT_INST_DEFINE(0, lsf_controller_init_internal, NULL, NULL, NULL, APPLICATION,
		      CONFIG_APPLICATION_INIT_PRIORITY, NULL);
