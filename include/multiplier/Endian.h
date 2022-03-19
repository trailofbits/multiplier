// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

#if defined(__has_include) && __has_include(<endian.h>)
#  include <endian.h>
#endif

#if defined(__has_include) && __has_include(<sys/param.h>)
#  include <sys/param.h>
#endif

#include "Compiler.h"

namespace mx {
#if (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && \
     __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || \
    (defined(__LITTLE_ENDIAN__) && __LITTLE_ENDIAN__)
#  define MX_CONSTEXPR_ENDIAN constexpr
#  define MX_LITTLE_ENDIAN 1
#  define MX_BIG_ENDIAN 0
#elif (defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && \
       __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || \
       (defined(__BIG_ENDIAN__) && __BIG_ENDIAN__)
#  define MX_CONSTEXPR_ENDIAN constexpr
#  define MX_LITTLE_ENDIAN 0
#  define MX_BIG_ENDIAN 1
#else
#  define MX_CONSTEXPR_ENDIAN
#  define MX_LITTLE_ENDIAN 0
#  define MX_BIG_ENDIAN (!*(unsigned char *)&(unsigned short){1})

static const unsigned short kEndian = 0xFFEE;

#  define MX_LITTLE_ENDIAN ((*reinterpret_cast<const unsigned char *>(&::hyde::rt::kEndian)) == 0xEE)
#  define MX_BIG_ENDIAN ((*reinterpret_cast<const unsigned char *>(&::hyde::rt::kEndian)) == 0xFF)
#endif

MX_ALWAYS_INLINE MX_CONSTEXPR_ENDIAN static uint64_t ToBigEndian(uint64_t v) {
  if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
    return v;
  } else {
    return __builtin_bswap64(v);
  }
}

MX_ALWAYS_INLINE MX_CONSTEXPR_ENDIAN static uint64_t FromBigEndian(uint64_t v) {
  if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
    return v;
  } else {
    return __builtin_bswap64(v);
  }
}

MX_ALWAYS_INLINE MX_CONSTEXPR_ENDIAN static uint32_t ToBigEndian(uint32_t v) {
  if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
    return v;
  } else {
    return __builtin_bswap32(v);
  }
}

MX_ALWAYS_INLINE MX_CONSTEXPR_ENDIAN static uint32_t FromBigEndian(uint32_t v) {
  if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
    return v;
  } else {
    return __builtin_bswap32(v);
  }
}

MX_ALWAYS_INLINE MX_CONSTEXPR_ENDIAN static uint16_t ToBigEndian(uint16_t v) {
  if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
    return v;
  } else {
    return __builtin_bswap16(v);
  }
}

MX_ALWAYS_INLINE MX_CONSTEXPR_ENDIAN static uint16_t FromBigEndian(uint16_t v) {
  if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
    return v;
  } else {
    return __builtin_bswap16(v);
  }
}

}  // namespace mx
