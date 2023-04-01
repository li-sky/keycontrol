#ifndef __INC_REG52_H
#include <REG52.H>
#endif

#ifndef __INC_KEYCONTROL_H
#define uchar unsigned char
#define NULL 0
typedef void (*key_callback) (int *count, int* countStep, unsigned char timer, unsigned int * TimerConfigure) reentrant;
// keystatus : 0x01: isKeyReady
//            0x02: isKeyPressed
extern unsigned char keyStatus;

void KeyPressHandler(key_callback onKeydownBeginCallback, key_callback onKeydownReadyCallback, key_callback onKeyupBeginCallback, key_callback onKeyupReadyCallback, unsigned long *count, int *countStep, unsigned char timer, unsigned int * TimerConfigure);
void defaultKeyDownBeginCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure);
void defaultKeyDownReadyCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure);
void defaultKeyUpBeginCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure);
void defaultKeyUpReadyCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure);
#endif