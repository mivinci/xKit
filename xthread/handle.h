/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * handle.h - Handle definitions
 */

#ifndef XTHREAD_HANDLE_H
#define XTHREAD_HANDLE_H

#include <xthread/base.h>

/**
 * @brief Opaque handle to a task.
 * @ingroup xTask
 */
XDEF_HANDLE(xTask);

/**
 * @brief Opaque handle to a process.
 * @ingroup xProc
 */
XDEF_HANDLE(xProc);

/**
 * @brief Opaque handle to a queue.
 * @ingroup xQueue
 */
XDEF_HANDLE(xQueue);

/**
 * @brief Generic function pointer type.
 * @ingroup xFunc
 */
typedef void *(*xFunc)(void *);

#endif // XTHREAD_HANDLE_H
