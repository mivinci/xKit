/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * proc.c -
 */

#include <xthread/handle.h>
#include <xthread/memory.h>
#include <xthread/mpsc.h>
#include <xthread/queue.h>
#include <xthread/task.h>

#include <stddef.h>

XDEF_STRUCT(Task) {
  xTaskFlag flag;
  xFunc     func;
  void     *arg;
  void     *res;
  xMpsc    *link;
};

XDEF_VTABLE(Task){
  .ctor    = NULL,
  .dtor    = NULL,
  .copy    = NULL,
  .move    = NULL,
  .retain  = NULL,
  .release = NULL,
};

XDEF_STRUCT(Queue) {
  const char *name;
  xQueueQos   qos;
  xMpsc      *head;
  xMpsc      *tail;
  xTask       next_task;
};

XDEF_CTOR(Queue) {
  self->head = NULL;
  self->tail = NULL;
}

XDEF_VTABLE(Queue){
  .ctor    = XSYM_CTOR(Queue),
  .dtor    = NULL,
  .copy    = NULL,
  .move    = NULL,
  .retain  = NULL,
  .release = NULL,
};

Queue *QueueCreate(const char *name, const xQueueQos qos) {
  Queue *qp;

  qp = XMALLOC(Queue);
  if (qp == NULL) {
    return NULL;
  }
  qp->name = name;
  qp->qos  = qos;
  return qp;
}

static xResult QueuePush(Queue *qp, const Task *tp) {
  xMpscPush(&qp->head, &qp->tail, tp->link);
  return xResult_Ok;
}
