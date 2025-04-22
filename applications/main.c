/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-12-13     RT-Thread    first version
 */

#include <rtthread.h>
#include "board.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <fal.h>
#include "rtdevice.h"
#include "drv_common.h"
#define LED_R GET_PIN(C, 13)

extern void wlan_autoconnect_init(void);
int main(void)
{
    int count = 1;
    static int pin_num1;
    rt_kprintf("HERE IS APP RUNNING ! V1.0.1\r\n");
    /* 设置PIN脚模式为输出 */
    pin_num1 = LED_R;
    rt_pin_mode(pin_num1, PIN_MODE_OUTPUT);
    /* init Wi-Fi auto connect feature */
    wlan_autoconnect_init();
    /* enable auto reconnect on WLAN device */
    rt_wlan_config_autoreconnect(RT_TRUE);
    while (count++)
    {
//        LOG_D("Hello RT-Thread!");
        rt_pin_write(pin_num1, PIN_LOW);
        rt_thread_mdelay(100);
        rt_pin_write(pin_num1, PIN_HIGH);
        rt_thread_mdelay(100);
    }

    return RT_EOK;
}
#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);
