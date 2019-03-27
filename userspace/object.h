/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2019, RExOS team
    All rights reserved.

    author: Alexey E. Kramarenko (alexeyk13@yandex.ru)
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "svc.h"
#include "error.h"
#include "process.h"

__STATIC_INLINE void object_set(int idx, HANDLE object)
{
    svc_call(SVC_OBJECT_SET, idx, (unsigned int)object, 0);
}

__STATIC_INLINE void object_set_self(int idx)
{
    svc_call(SVC_OBJECT_SET, idx, (unsigned int)process_get_current(), 0);
}

__STATIC_INLINE HANDLE object_get(int idx)
{
    HANDLE object = INVALID_HANDLE;
    svc_call(SVC_OBJECT_GET, idx, (unsigned int)&object, 0);
    return object;
}

#endif // OBJECT_H
