/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * base.h - Base definitions and macros
 */

#ifndef XTHREAD_BASE_H
#define XTHREAD_BASE_H

#ifdef __cplusplus
#define XCAPI(T) extern "C" T
#else
#define XCAPI(T) T

#endif

#define XSTRUCT(T)                                                             \
  typedef struct T T;                                                          \
  struct T

#define XENUM(T)                                                               \
  typedef int T;                                                               \
  enum

#define XHANDLE(T) typedef void *T

#ifdef __STDC_VERSION__ /* C99 and later */
#include <stdbool.h>
#elif !defined(bool)
#define bool  _Bool
#define true  1
#define false 0
#endif

#endif // XTHREAD_BASE_H
