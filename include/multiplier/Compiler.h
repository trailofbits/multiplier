// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

namespace mx {

#ifdef NDEBUG
#  define MX_LIKELY(...) __builtin_expect(!!(__VA_ARGS__), 1)
#  define MX_UNLIKELY(...) __builtin_expect(!!(__VA_ARGS__), 0)
#  define MX_NEVER_INLINE [[gnu::noinline]]
#  define MX_INLINE inline
#  define MX_ALWAYS_INLINE [[gnu::always_inline]] MX_INLINE
#  define MX_FLATTEN [[gnu::flatten]]
#else
#  define MX_LIKELY(...) __VA_ARGS__
#  define MX_UNLIKELY(...) __VA_ARGS__
#  define MX_NEVER_INLINE [[gnu::noinline]]
#  define MX_INLINE MX_NEVER_INLINE
#  define MX_ALWAYS_INLINE MX_INLINE
#  define MX_FLATTEN
#endif

#if defined(__has_feature)
#  if __has_feature(undefined_behavior_sanitizer)
#    define MX_DISALLOW_UNALIGNED_ACCESS
#  endif
#endif

}  // namespace mx
