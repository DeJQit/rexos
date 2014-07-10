/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2014, Alexey Kramarenko
    All rights reserved.
*/

#ifndef STM32_TIMER_H
#define STM32_TIMER_H

/*
        timer for STM32
  */

typedef enum {
    TIM_1 = 0,
    TIM_2,
    TIM_3,
    TIM_4,
    TIM_5,
    TIM_6,
    TIM_7,
    TIM_8,
    TIM_9,
    TIM_10,
    TIM_11,
    TIM_12,
    TIM_13,
    TIM_14,
    TIM_15,
    TIM_16,
    TIM_17,
    TIM_18,
    TIM_19,
    TIM_20
}TIMER_CLASS;

#define TIMER_FLAG_ONE_PULSE_MODE                (1 << 0)

void timer_enable(TIMER_CLASS timer, int priority, unsigned int flags);
void timer_disable(TIMER_CLASS timer);
void timer_start(TIMER_CLASS timer, unsigned int time_us);
void timer_stop(TIMER_CLASS timer);
unsigned int timer_elapsed(TIMER_CLASS timer);
void timer_init_hw();

#endif // STM32_TIMER_H