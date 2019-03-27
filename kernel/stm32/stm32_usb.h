/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#ifndef STM32_USB_H
#define STM32_USB_H

#include "../../userspace/process.h"
#include "../../userspace/io.h"
#include "stm32_config.h"
#include "sys_config.h"
#include "stm32_exo.h"

typedef struct {
    IO* io;
    unsigned int size;
    uint16_t mps;
    uint8_t io_active;
} EP;

typedef struct {
  HANDLE device;
  EP* out[USB_EP_COUNT_MAX];
  EP* in[USB_EP_COUNT_MAX];
  uint8_t addr;
} USB_DRV;

void stm32_usb_init(EXO* exo);
void stm32_usb_request(EXO* exo, IPC* ipc);

#endif // STM32_USB_H
