/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * task.c - Task implementation
 */

#include <xthread/error.h>
#include <xthread/memory.h>
#include <xthread/task.h>

#include <stddef.h>

XSTRUCT(Task) {
  xTaskFlag flag;
  xFunc     func;
  void     *arg;
  void     *res;
};

XVTABLE(Task){
  .ctor    = NULL,
  .dtor    = NULL,
  .copy    = NULL,
  .move    = NULL,
  .retain  = NULL,
  .release = NULL,
};

static xResult performTask(Task *tp) {
  tp->res = tp->func(tp->arg);
  return xResult_Ok;
}

xTask xTaskCreate(const xFunc func, void *arg, const xTaskFlag flag) {
  Task *tp;

  tp       = XMALLOC(Task);
  tp->flag = flag;
  tp->func = func;
  tp->arg  = arg;
  return tp;
}

void xTaskDestroy(xTask task) {
  Task *tp;

  tp = (Task *)task;
  if (tp->flag & xTaskFlag_Mandatory) {
    performTask(tp);
  }
  xFree(task);
}

xResult xTaskPerform(xTask task) { return performTask((Task *)task); }
