// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SourceLocExprIdentKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SourceLocExprIdentKind e) {
  switch (e) {
    case SourceLocExprIdentKind::FUNCTION: return "FUNCTION";
    case SourceLocExprIdentKind::FUNC_SIG: return "FUNC_SIG";
    case SourceLocExprIdentKind::FILE: return "FILE";
    case SourceLocExprIdentKind::FILE_NAME: return "FILE_NAME";
    case SourceLocExprIdentKind::LINE: return "LINE";
    case SourceLocExprIdentKind::COLUMN: return "COLUMN";
    case SourceLocExprIdentKind::SOURCE_TOKEN_STRUCT: return "SOURCE_TOKEN_STRUCT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
