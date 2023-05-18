/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-07     yangjie      first implementation
 * 2023-05-18			ALanStewart  add Parity judgment
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/* 配置 LED 灯引脚 */
#define LED_PIN     PIN_LED_R

/* 判断奇偶 */
int odd_even(uint16_t i)
{
	if(i%2 == 0)
		return 1;
	else	
		return 0;
}


int main(void)
{
    unsigned int count = 1;
		

    /* 设置 LED 引脚为输出模式 */
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
		

    while (count > 0)
    {
        /* LED 灯亮 */
			if(odd_even(count))
			{
        rt_pin_write(LED_PIN, PIN_LOW);
        LOG_D("led on, count: %d", count);
        rt_thread_mdelay(500);

        /* LED 灯灭 */
        rt_pin_write(LED_PIN, PIN_HIGH);
        LOG_D("led off");
        rt_thread_mdelay(500);

        //count++;
			}
			count++;
    }

    return 0;
}
