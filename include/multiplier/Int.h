// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

#if defined(__SIZEOF_INT128__)
typedef __uint128_t uint128_t;
typedef __int128_t int128_t;
#elif defined(__x86_64__) || defined(__i386__) || defined(_M_X86) || defined (__arm__)
typedef unsigned uint128_t __attribute__((mode(TI)));
typedef int int128_t __attribute__((mode(TI)));
#elif defined(__aarch64__)
typedef __uint128_t uint128_t;
typedef __int128_t int128_t;
#elif defined(__sparc__)
typedef __uint128_t uint128_t;
typedef __int128_t int128_t;
#elif defined(__is_identifier)
#  if __is_identifier(_ExtInt)
typedef unsigned _ExtInt(128) uint128_t;
typedef signed _ExtInt(128) int128_t;
#  else
#    define MX_MISSING_INT128
#  endif
#else
#  define MX_MISSING_INT128
#endif

#ifndef MX_MISSING_INT128
static_assert(sizeof(int128_t) == 16, "Invalid size for `int128_t`.");
static_assert(sizeof(uint128_t) == 16, "Invalid size for `uint128_t`.");
#endif
