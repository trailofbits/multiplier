// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnsafeBufferUsageAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnsafeBufferUsageAttrSpelling e) {
  switch (e) {
    case UnsafeBufferUsageAttrSpelling::GNU_UNSAFE_BUFFER_USAGE: return "GNU_UNSAFE_BUFFER_USAGE";
    case UnsafeBufferUsageAttrSpelling::CXX11_CLANG_UNSAFE_BUFFER_USAGE: return "CXX11_CLANG_UNSAFE_BUFFER_USAGE";
    case UnsafeBufferUsageAttrSpelling::C23_CLANG_UNSAFE_BUFFER_USAGE: return "C23_CLANG_UNSAFE_BUFFER_USAGE";
    case UnsafeBufferUsageAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
