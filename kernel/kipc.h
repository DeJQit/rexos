/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#ifndef KIPC_H
#define KIPC_H

#include "../userspace/ipc.h"
#include "kprocess.h"

//called from kprocess
void kipc_init(KPROCESS* process);
void kipc_lock_release(KPROCESS* process);

void kipc_post(HANDLE sender, IPC* ipc);
void kipc_wait(HANDLE process, HANDLE wait_process, unsigned int cmd, unsigned int param1);
void kipc_call(HANDLE process, IPC* ipc);


#endif // KIPC_H
