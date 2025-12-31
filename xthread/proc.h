/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * proc.h - Process definitions
 */

#ifndef XTHREAD_PROC_H
#define XTHREAD_PROC_H

#include <xthread/base.h>
#include <xthread/handle.h>
#include <xthread/memory.h>

/**
 * @brief Process flags.
 * @ingroup xProc
 */
XENUM(xProcFlag){
  xProcFlag_None     = 0,
  xProcFlag_Detached = 1,
};

/**
 * @brief Create a process.
 * @param func process function
 * @param arg process argument
 * @param stacksize process stack size
 * @param flag process flag
 * @return xProc process handle
 */
XCAPI(xProc)
xProcCreate(xFunc func, void *arg, xSize stacksize, xProcFlag flag);

/**
 * @brief Destroy a process.
 * @param proc process handle
 */
XCAPI(void) xProcDestroy(xProc proc);

/**
 * @brief Join a process.
 * @param proc process handle
 * @return process return value
 */
XCAPI(void *) xProcJoin(xProc proc);

/**
 * @brief Detach a process.
 * @param proc process handle
 */
XCAPI(void) xProcDetach(xProc proc);

#endif // XTHREAD_PROC_H
