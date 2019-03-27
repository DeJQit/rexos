/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2018, Alexey Kramarenko
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#ifndef LPC_PIN_H
#define LPC_PIN_H

#include <stdbool.h>
#include "../../userspace/cc_macro.h"
#include "../../userspace/gpio.h"
#include "../../userspace/ipc.h"

void lpc_pin_init();
void lpc_pin_request(IPC* ipc);

void lpc_pin_enable(unsigned int pin, unsigned int mode);
void lpc_pin_disable(unsigned int pin);

#endif // LPC_PIN_H
