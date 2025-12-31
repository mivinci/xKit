/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * queue.h - Queue definitions
 */

#ifndef XTHREAD_QUEUE_H
#define XTHREAD_QUEUE_H

#include <xthread/base.h>
#include <xthread/error.h>
#include <xthread/handle.h>

/**
 * @brief Quality of Service levels for queues.
 * @ingroup xQueue
 */
XDEF_ENUM(xQueueQos){
  xQueueQoS_Default = 0,
  xQueueQoS_Low,
  xQueueQoS_High,
};

/**
 * @brief Create a queue.
 * @ingroup xQueue
 * @param name The name of the queue.
 * @param qos The quality of service level of the queue.
 * @return The handle to the queue.
 */
XCAPI(xQueue) xQueueCreate(const char *name, xQueueQos qos);

/**
 * @brief Push a task to a queue.
 * @ingroup xQueue
 * @param queue The handle to the queue.
 * @param task The task to push.
 * @return The result of the operation.
 */
XCAPI(xResult) xQueuePush(xQueue queue, xTask task);

/**
 * @brief Pop a task from a queue.
 * @ingroup xQueue
 * @param queue The handle to the queue.
 * @param[out] task The task to pop.
 * @return The result of the operation.
 */
XCAPI(xResult) xQueuePop(xQueue queue, xTask *task);

#endif // XTHREAD_QUEUE_H
