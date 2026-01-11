/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * memory.h - Memory allocation and management
 */

#ifndef XTHREAD_MEMORY_H
#define XTHREAD_MEMORY_H

#include <stddef.h>
#include <xthread/base.h>

#define XSYM_VTABLE(T) T##VTable
#define XSYM_CTOR(T)   T##Ctor
#define XSYM_DTOR(T)   T##Dtor

#define XDEF_VTABLE(T) static xVTable XSYM_VTABLE(T) =
#define XDEF_CTOR(T)   static void XSYM_CTOR(T)(T * self)
#define XDEF_DTOR(T)   static void XSYM_DTOR(T)(T * self)

#define XMALLOC(T)         (T *)xAlloc(#T, sizeof(T), &XSYM_VTABLE(T))
#define XMALLOCEX(T, ex)   (T *)xAlloc(#T, sizeof(T) + (ex), &XSYM_VTABLE(T))
#define XMALLOCARRAY(T, n) (T *)xAlloc(#T, sizeof(T) * (n), &XSYM_VTABLE(T))

/**
 * @brief Virtual table for object lifecycle management.
 * @ingroup xMemory
 */
XDEF_STRUCT(xVTable) {
  void (*ctor)(void *ptr);
  void (*dtor)(void *ptr);
  void (*retain)(void *ptr);
  void (*release)(void *ptr);
  void (*copy)(void *ptr, void *other);
  void (*move)(void *ptr, void *other);
};

/**
 * @brief Allocate an object with the given size and vtable.
 * @ingroup xMemory
 * @param name The name of the object type.
 * @param size The size of the object to allocate.
 * @param vtab The virtual table for the object.
 * @return A pointer to the allocated object.
 */
XCAPI(void *) xAlloc(const char *name, size_t size, xVTable *vtab);

/**
 * @brief Free an allocated object.
 * @ingroup xMemory
 * @param ptr The pointer to the object to free.
 */
XCAPI(void) xFree(void *ptr);

/**
 * @brief Retain a reference to an object.
 * @ingroup xMemory
 * @param ptr The pointer to the object.
 */
XCAPI(void) xRetain(void *ptr);

/**
 * @brief Release a reference to an object.
 * @ingroup xMemory
 * @param ptr The pointer to the object.
 */
XCAPI(void) xRelease(void *ptr);

/**
 * @brief Copy an object.
 * @ingroup xMemory
 * @param ptr The pointer to the object to copy.
 * @param other The pointer to the object to copy to.
 */
XCAPI(void) xCopy(void *ptr, void *other);

/**
 * @brief Move an object.
 * @ingroup xMemory
 * @param ptr The pointer to the object to move.
 * @param other The pointer to the object to move to.
 */
XCAPI(void) xMove(void *ptr, void *other);

#endif // XTHREAD_MEMORY_H
