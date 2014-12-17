/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2014, Alexey Kramarenko
    All rights reserved.
*/

#ifndef SYS_CONFIG_H
#define SYS_CONFIG_H

/*
    config.h - userspace config
 */

//add some debug info in SYS
#define SYS_INFO                                            0

//will save few bytes, but not recommended to disable
#define LIB_CHECK_PRESENCE                                  0
//----------------------------- objects ----------------------------------------------
//make sure, you know what are you doing, before change
#define SYS_OBJ_STDOUT                                      0
#define SYS_OBJ_CORE                                        1
#define SYS_OBJ_USBD                                        2

#define SYS_OBJ_I2C                                         SYS_OBJ_CORE
#define SYS_OBJ_UART                                        SYS_OBJ_CORE
#define SYS_OBJ_USB                                         SYS_OBJ_CORE
#define SYS_OBJ_STDIN                                       INVALID_HANDLE
//------------------------------ stdio -----------------------------------------------
#define STDIO_STREAM_SIZE                                   16
//-------------------------------- USB -----------------------------------------------
#define USB_EP_COUNT_MAX                                    3
//low-level USB debug. Turn on only in case of IO problems
#define USB_DEBUG_REQUESTS                                  1
#define USB_DEBUG_CLASS_REQUESTS                            1
#define USB_DEBUG_CLASS_IO                                  1
#define USB_DEBUG_ERRORS                                    1
//USB test mode support. Not all hardware supported.
#define USB_TEST_MODE                                       0

//----------------------------- USB device--------------------------------------------
#define USBD_PROCESS_SIZE                                   800
#define USBD_BLOCK_SIZE                                     128

#define USBD_CDC_CLASS                                      1

//----------------------------- CDC class --------------------------------------------
//At least EP size required, or data will be lost. Double EP size is recommended
#define USB_CDC_TX_STREAM_SIZE                              64
#define USB_CDC_RX_STREAM_SIZE                              64

#endif // SYS_CONFIG_H
