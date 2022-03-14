// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#if defined(__has_include) && __has_include(<endian.h>)
#  include <endian.h>
#endif

#if defined(__has_include) && __has_include(<sys/param.h>)
#  include <sys/param.h>
#endif

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
namespace mx {
static const unsigned short kEndian = 0xFFEE;
}  // namespace mx
#  define MX_LITTLE_ENDIAN ((*reinterpret_cast<const unsigned char *>(&::hyde::rt::kEndian)) == 0xEE)
#  define MX_BIG_ENDIAN ((*reinterpret_cast<const unsigned char *>(&::hyde::rt::kEndian)) == 0xFF)
#endif
