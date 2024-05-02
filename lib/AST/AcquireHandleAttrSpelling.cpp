// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AcquireHandleAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AcquireHandleAttrSpelling e) {
  switch (e) {
    case AcquireHandleAttrSpelling::GNU_ACQUIRE_HANDLE: return "GNU_ACQUIRE_HANDLE";
    case AcquireHandleAttrSpelling::CXX11_CLANG_ACQUIRE_HANDLE: return "CXX11_CLANG_ACQUIRE_HANDLE";
    case AcquireHandleAttrSpelling::C23_CLANG_ACQUIRE_HANDLE: return "C23_CLANG_ACQUIRE_HANDLE";
    case AcquireHandleAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
