// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ThreadStorageClassSpecifier.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ThreadStorageClassSpecifier e) {
  switch (e) {
    case ThreadStorageClassSpecifier::UNSPECIFIED: return "UNSPECIFIED";
    case ThreadStorageClassSpecifier::__THREAD: return "__THREAD";
    case ThreadStorageClassSpecifier::THREAD_LOCAL: return "THREAD_LOCAL";
    case ThreadStorageClassSpecifier::_THREAD_LOCAL: return "_THREAD_LOCAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
