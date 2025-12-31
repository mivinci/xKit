/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * task.h - Task definitions
 */

#ifndef XTHREAD_TASK_H
#define XTHREAD_TASK_H

#include <xthread/base.h>
#include <xthread/error.h>
#include <xthread/handle.h>

XDEF_ENUM(xTaskFlag){
  xTaskFlag_Mandatory = 1,
};

/**
 * @brief Create a task.
 * @param func task function
 * @param arg task argument
 * @param flag task flag
 * @return xTask task handle
 */
XCAPI(xTask) xTaskCreate(xFunc func, void *arg, xTaskFlag flag);

/**
 * @brief Destroy a task.
 * @param task task handle
 */
XCAPI(void) xTaskDestroy(xTask task);

/**
 * @brief Perform a task on the current thread.
 * @param task task handle
 * @return xResult result
 */
XCAPI(xResult) xTaskPerform(xTask task);

/**
 * @brief Cancel a task.
 * @param task task handle
 */
XCAPI(void) xTaskCancel(xTask task);

/**
 * @brief Wait for a task to finish.
 * @param task task handle
 * @param timeout timeout in milliseconds
 * @return true if the task finished, false if timeout
 */
XCAPI(bool) xTaskWait(xTask task, long timeout);

#endif // XTHREAD_TASK_H
