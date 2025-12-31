/*
 * Copyright 2025 The xKit Authors. All rights reserved.
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 *
 * atomic.h - Atomic operations
 */

#ifndef XTHREAD_ATOMIC_H
#define XTHREAD_ATOMIC_H

#define xAtomicAcquire __ATOMIC_ACQUIRE
#define xAtomicRelease __ATOMIC_RELEASE
#define xAtomicSeqCst  __ATOMIC_SEQ_CST
#define xAtomicRelaxed __ATOMIC_RELAXED
#define xAtomicConsume __ATOMIC_CONSUME
#define xAtomicAcqRel  __ATOMIC_ACQ_REL

#define xAtomicLoad(p, o)            __atomic_load_n(p, o)
#define xAtomicStore(p, v, o)        __atomic_store_n(p, v, o)
#define xAtomicXchg(p, v, o)         __atomic_exchange_n(p, v, o)
#define xAtomicCasWeak(p, e, d, o)   xAtomicCas(p, e, d, true, o)
#define xAtomicCasStrong(p, e, d, o) xAtomicCas(p, e, d, false, o)
#define xAtomicCas(p, e, d, w, o)                                              \
  __atomic_compare_exchange_n(p, e, d, w, o, xAtomicRelaxed)

#endif // XTHREAD_ATOMIC_H
