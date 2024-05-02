// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Syntax.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Syntax e) {
  switch (e) {
    case Syntax::GNU: return "GNU";
    case Syntax::CXX11: return "CXX11";
    case Syntax::C23: return "C23";
    case Syntax::DECLSPEC: return "DECLSPEC";
    case Syntax::MICROSOFT: return "MICROSOFT";
    case Syntax::KEYWORD: return "KEYWORD";
    case Syntax::PRAGMA: return "PRAGMA";
    case Syntax::CONTEXT_SENSITIVE_KEYWORD: return "CONTEXT_SENSITIVE_KEYWORD";
    case Syntax::HLSL_SEMANTIC: return "HLSL_SEMANTIC";
    case Syntax::IMPLICIT: return "IMPLICIT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
