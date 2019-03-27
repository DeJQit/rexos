/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#include "rtc.h"

TIME* rtc_get(TIME* time)
{
    IPC ipc;
    ipc.cmd = HAL_REQ(HAL_RTC, RTC_GET);
    ipc.process = KERNEL_HANDLE;
    call(&ipc);
    time->day = ipc.param1;
    time->ms = ipc.param2;
    return time;
}

void rtc_set(TIME* time)
{
    ipc_post_exo(HAL_CMD(HAL_RTC, RTC_SET), (unsigned int)time->day, (unsigned int)time->ms, 0);
}
