// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AttributeSyntax.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AttributeSyntax e) {
  switch (e) {
    case AttributeSyntax::GNU: return "GNU";
    case AttributeSyntax::CXX11: return "CXX11";
    case AttributeSyntax::C2X: return "C2X";
    case AttributeSyntax::DECLSPEC: return "DECLSPEC";
    case AttributeSyntax::MICROSOFT: return "MICROSOFT";
    case AttributeSyntax::KEYWORD: return "KEYWORD";
    case AttributeSyntax::PRAGMA: return "PRAGMA";
    case AttributeSyntax::CONTEXT_SENSITIVE_KEYWORD: return "CONTEXT_SENSITIVE_KEYWORD";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
