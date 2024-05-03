// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/XRayLogArgsAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(XRayLogArgsAttrSpelling e) {
  switch (e) {
    case XRayLogArgsAttrSpelling::GNU_XRAY_LOG_ARGUMENTS: return "GNU_XRAY_LOG_ARGUMENTS";
    case XRayLogArgsAttrSpelling::CXX11_CLANG_XRAY_LOG_ARGUMENTS: return "CXX11_CLANG_XRAY_LOG_ARGUMENTS";
    case XRayLogArgsAttrSpelling::C23_CLANG_XRAY_LOG_ARGUMENTS: return "C23_CLANG_XRAY_LOG_ARGUMENTS";
    case XRayLogArgsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
