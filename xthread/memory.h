/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * memory.h - Memory allocation and management
 */

#ifndef XTHREAD_MEMORY_H
#define XTHREAD_MEMORY_H

#include <xthread/base.h>

#define XVTABLENAME(T)     T##VTable
#define XVTABLE(T)         static xVTable XVTABLENAME(T) =
#define XMALLOC(T)         (T *)xAlloc(#T, sizeof(T), &XVTABLENAME(T))
#define XMALLOCEX(T, ex)   (T *)xAlloc(#T, sizeof(T) + (ex), &XVTABLENAME(T))
#define XMALLOCARRAY(T, n) (T *)xAlloc(#T, sizeof(T) * (n), &XVTABLENAME(T))

/**
 * @brief Size type for memory allocations.
 * @ingroup xObject
 */
typedef unsigned long xSize;

/**
 * @brief Virtual table for object lifecycle management.
 * @ingroup xObject
 */
XSTRUCT(xVTable) {
  void (*ctor)(void *ptr);
  void (*dtor)(void *ptr);
  void (*retain)(void *ptr);
  void (*release)(void *ptr);
  void (*copy)(void *ptr, void *other);
  void (*move)(void *ptr, void *other);
};

/**
 * @brief Allocate an object with the given size and vtable.
 * @ingroup xObject
 * @param name The name of the object type.
 * @param size The size of the object to allocate.
 * @param vtab The virtual table for the object.
 * @return A pointer to the allocated object.
 */
XCAPI(void *) xAlloc(const char *name, xSize size, xVTable *vtab);

/**
 * @brief Free an allocated object.
 * @ingroup xObject
 * @param ptr The pointer to the object to free.
 */
XCAPI(void) xFree(void *ptr);

/**
 * @brief Retain a reference to an object.
 * @ingroup xObject
 * @param ptr The pointer to the object.
 */
XCAPI(void) xRetain(void *ptr);

/**
 * @brief Release a reference to an object.
 * @ingroup xObject
 * @param ptr The pointer to the object.
 */
XCAPI(void) xRelease(void *ptr);

/**
 * @brief Copy an object.
 * @ingroup xObject
 * @param ptr The pointer to the object to copy.
 * @param other The pointer to the object to copy to.
 */
XCAPI(void) xCopy(void *ptr, void *other);

/**
 * @brief Move an object.
 * @ingroup xObject
 * @param ptr The pointer to the object to move.
 * @param other The pointer to the object to move to.
 */
XCAPI(void) xMove(void *ptr, void *other);

#endif // XTHREAD_MEMORY_H
