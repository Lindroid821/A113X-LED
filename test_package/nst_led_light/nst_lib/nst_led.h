#ifndef __CLIENT_H
#define __CLIENT_H

#include <stdio.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
*  Function: int nst_led_init(void);
*  Description: leds init function
*  Input: none
*  Output:
*  Return: led init state. sucess: 0  fail: -1
*  Others:
**********************************************************************/
int nst_led_init(void);

/*********************************************************************
*  Function: int nst_led_light(int mic_index);
*  Description: leds set action function
*  Input:
*      mic_index: the number of led. range: [0 ~ 6]
*  Output:
*  Return: led set state. sucess: 0  fail: -1
*  Others:
**********************************************************************/
int nst_led_light(int mic_index);

/*********************************************************************
*  Function: int ledRelease(void);
*  Description: leds release function
*  Input:
*  Output:
*  Return: led release state. sucess: 0  fail: -1
*  Others:
**********************************************************************/
int nst_led_release(void);

#ifdef __cplusplus
}
#endif
#endif

