/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#include "uart.h"
#include "sys_config.h"
#include "object.h"
#include "ipc.h"

void uart_encode_baudrate(BAUD* baudrate, IPC* ipc)
{
    ipc->param2 = baudrate->baud;
    ipc->param3 = (baudrate->data_bits << 16) | (baudrate->parity << 8) | baudrate->stop_bits;
}

void uart_decode_baudrate(IPC* ipc, BAUD* baudrate)
{
    baudrate->baud = ipc->param2;
    baudrate->data_bits = (ipc->param3 >> 16) & 0xff;
    baudrate->parity = (ipc->param3 >> 8) & 0xff;
    baudrate->stop_bits = (ipc->param3) & 0xff;
}

void uart_setup_printk(int num)
{
    ipc_post_exo(HAL_CMD(HAL_UART, IPC_UART_SETUP_PRINTK), num, 0, 0);
}

void uart_setup_stdout(int num)
{
    object_set(SYS_OBJ_STDOUT, get_handle_exo(HAL_REQ(HAL_UART, IPC_GET_TX_STREAM), num, 0, 0));
}

void uart_setup_stdin(int num)
{
    object_set(SYS_OBJ_STDIN, get_handle_exo(HAL_REQ(HAL_UART, IPC_GET_RX_STREAM), num, 0, 0));
}

bool uart_open(int num, unsigned int mode)
{
    return get_handle_exo(HAL_REQ(HAL_UART, IPC_OPEN), num, mode, 0) != INVALID_HANDLE;
}

void uart_close(int num)
{
    ipc_post_exo(HAL_CMD(HAL_UART, IPC_CLOSE), num, 0, 0);
}

void uart_set_baudrate(int num, BAUD* baudrate)
{
    IPC ipc;
    uart_encode_baudrate(baudrate, &ipc);
    ipc.cmd = HAL_CMD(HAL_UART, IPC_UART_SET_BAUDRATE);
    ipc.param1 = num;
    ipc.process = KERNEL_HANDLE;
    ipc_post(&ipc);
}

void uart_set_comm_timeouts(int num, unsigned int char_timeout_us, unsigned int interleaved_timeout_us)
{
    get_exo(HAL_REQ(HAL_UART, IPC_UART_SET_COMM_TIMEOUTS), num, char_timeout_us, interleaved_timeout_us);
}

void uart_flush(int num)
{
    ipc_post_exo(HAL_CMD(HAL_UART, IPC_FLUSH), num, 0, 0);
}

int uart_get_last_error(int num)
{
    return (int)get_exo(HAL_REQ(HAL_UART, IPC_UART_GET_LAST_ERROR), num, 0, 0);
}

void uart_clear_error(int num)
{
    get_exo(HAL_REQ(HAL_UART, IPC_UART_CLEAR_ERROR), num, 0, 0);
}
