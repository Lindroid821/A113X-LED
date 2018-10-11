/*
 * This file is part of ledring.
 * Copyright (c) amlogic 2017
 * All rights reserved.
 * author:renjun.xu@amlogic.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software.
 *
 */
#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>
#include "ledStyle.h"
#include "nst_led.h"

#define DEV_LEDRING_NAME            "/dev/ledring"
#define DEFAULT_SPEED               230

#define CMD_LEDRING_ARG             0x100001
#define CMD_LED_MUTE_ARG            0x100002
#define CMD_LED_LISTENING_ARG       0x100003
#define LED_OFF                     0
#define LED_ON                      1
#define LED_4KEY                    1
#define LED_0KEY                    0

struct nst_led_operation{	
    int fp;
    int key_flag;
    int mic_id;
}nst_led_op = {0,-1,-1};;

struct leds{
    int num;   /*the number of leds*/
    int times; /*N: stop after action N times, 0: cycle action*/
    int speed; /*the speed of move. [0~N] ms*/
    int time; /*the timeout of move. [0 ~ N] s . 0s mean close timeout*/
    int style[12][12]; /*style data*/ 
} styleData = {6, 1, DEFAULT_SPEED, 0, {0}};

int nst_led_init(void) 
{
    int ret, mode;
    nst_led_op.fp = open(DEV_LEDRING_NAME, O_RDWR);
    if (nst_led_op.fp > 0) {
        ret = read(nst_led_op.fp, &mode, sizeof(mode));
        if (-1 == ret) {
            nst_led_op.key_flag = -1;
            printf("read ted node fail!\n");
        } else { 
	   nst_led_op.key_flag = mode;
	}
    } else {
        nst_led_op.key_flag = -1;
        printf("open \"%s\" fail!\n",DEV_LEDRING_NAME);
        return -1;
    }
    return 0;
}

int ledShow(int num, int times, int speed,
    int time, int style, int mute_led, int listen_led)
{
    int ret = 0;
    int mute_led_state, listen_led_state;

    styleData.num = num;
    styleData.speed = speed;
    styleData.time = time;
    styleData.times = times;
    mute_led_state = mute_led;
    listen_led_state = listen_led;
    
    switch (nst_led_op.key_flag) {
        case LED_4KEY:
            ret = ioctl(nst_led_op.fp,CMD_LED_LISTENING_ARG, &mute_led_state);
            ret = ioctl(nst_led_op.fp,CMD_LED_MUTE_ARG, &listen_led_state);
        break;
        case LED_0KEY:
            if ((style > (sizeof(m_style)/sizeof(m_style[0])-1)) || (style <0)) {
                printf("This signal color style is not supported, please check!\n");
                return -1;
            }
            if (num > 6) {
               styleData.num = 6;
               printf("signal color led num out of range,use default num,please check!\n");
            }
            memcpy((char*)&styleData.style, (char*)&m_style[style], sizeof(styleData.style));
            ret = ioctl(nst_led_op.fp,CMD_LEDRING_ARG,&styleData);
        break;
    }

    return 0;
}

int nst_led_light(int mic_id)
{
    int mute_led_state = 0, listen_led_state = 0;
    if(mic_id < 0 || mic_id > 6){
        printf("mic_id %d out of range[0~6]\n",mic_id);
        return 0;
    }
    if(nst_led_op.mic_id == mic_id){
        return 0;
    }
    nst_led_op.mic_id = mic_id;
    if(nst_led_op.mic_id != 0){
       mute_led_state = 1;
       listen_led_state = 1;
    }
    return ledShow(styleData.num,styleData.times,styleData.speed,styleData.time,
                   nst_led_op.mic_id,mute_led_state,listen_led_state);
}

int nst_led_release(void) 
{
    int ret = 0;
    if (nst_led_op.key_flag != -1) {
        ret = close(nst_led_op.fp);
        if (ret < 0) return -1;
    }
    return 0;
}
