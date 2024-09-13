// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NSConsumesSelfAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NSConsumesSelfAttrSpelling e) {
  switch (e) {
    case NSConsumesSelfAttrSpelling::GNU_NS_CONSUMES_SELF: return "GNU_NS_CONSUMES_SELF";
    case NSConsumesSelfAttrSpelling::CXX11_CLANG_NS_CONSUMES_SELF: return "CXX11_CLANG_NS_CONSUMES_SELF";
    case NSConsumesSelfAttrSpelling::C23_CLANG_NS_CONSUMES_SELF: return "C23_CLANG_NS_CONSUMES_SELF";
    case NSConsumesSelfAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
