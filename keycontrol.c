#include "keycontrol.h"


void KeyPressHandler(key_callback onKeydownBeginCallback, key_callback onKeydownReadyCallback, key_callback onKeyupBeginCallback, key_callback onKeyupReadyCallback, unsigned long *count, int *countStep, unsigned char timer, unsigned int * TimerConfigure)
{
		P3 = 0xFF;
    if (P3 == 0xFF) {
        // key up
        switch (keyStatus)
        {
            case 0x00:
                //key is not pressed, and is not ready, so check is count to 10ms, and if yes change keystate; if not do nothing
                if (*count == (unsigned long)0x0000000A) {
                    if (onKeyupReadyCallback != NULL)
                    onKeyupReadyCallback(count, countStep, timer, TimerConfigure);
                    else defaultKeyUpReadyCallback(count, countStep, timer, TimerConfigure);
                }
                break;
            case 0x01:
                //key is ready
                //nothing to be done
                break;
            case 0x02:
                //key is pressed, and is not ready, but key is now up, so this has to be ignored
                break;
            case 0x03:
                //key is pressed, and is ready, but key is now up, so begin key 
                if (onKeyupBeginCallback != NULL)
                onKeyupBeginCallback(count, countStep, timer, TimerConfigure);
                else defaultKeyUpBeginCallback(count, countStep, timer, TimerConfigure);
                break;
        }
    } else {
        switch (keyStatus)
        {
            case 0x00:
                //key is not pressed, and is not ready, but key is now down, so this has to be ignored
                break;
            case 0x01:
                //key is ready, but key is now down, so begin key down
                if (onKeydownBeginCallback != NULL)
                onKeydownBeginCallback(count, countStep, timer, TimerConfigure);
                else defaultKeyDownBeginCallback(count, countStep, timer, TimerConfigure);
                break;
            case 0x02:
                //key is pressed, and is not ready, so check is count to 10ms, and if yes change keystate; if not do nothing
                if (*count == (unsigned long)0x0000000A) {
                    if (onKeydownReadyCallback != NULL)
                    onKeydownReadyCallback(count, countStep, timer, TimerConfigure);
                    else defaultKeyDownReadyCallback(count, countStep, timer, TimerConfigure);
                }
                break;
            case 0x03:
                //key is pressed, and is ready
                //nothing to be done
                break;
        }
    }
}

void defaultKeyDownBeginCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure)
{
    keyStatus = 0x02;
    *count = 0;
    *countStep = 1;
    TimerConfigure = 0xD120;
    if (timer == 0) {
        TR0 = 1;
    } else {
        TR1 = 1;
    }
}

void defaultKeyDownReadyCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure)
{
    keyStatus = 0x03;
    *count = 0;
    *countStep = 0;
    if (timer == 0) {
        TR0 = 0;
    } else {
        TR1 = 0;
    }
}

void defaultKeyUpBeginCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure)
{
    keyStatus = 0x00;
    *count = 0;
    *countStep = 1;
    TimerConfigure = 0xD120;
    if (timer == 0) {
        TR0 = 1;
    } else {
        TR1 = 1;
    }
}

void defaultKeyUpReadyCallback(int *count, int* countStep, unsigned char timer, unsigned int *TimerConfigure)
{
    keyStatus = 0x01;
    *count = 0;
    *countStep = 0;
    if (timer == 0) {
        TR0 = 0;
    } else {
        TR1 = 0;
    }
}