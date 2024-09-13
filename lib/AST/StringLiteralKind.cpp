// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StringLiteralKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StringLiteralKind e) {
  switch (e) {
    case StringLiteralKind::ORDINARY: return "ORDINARY";
    case StringLiteralKind::WIDE: return "WIDE";
    case StringLiteralKind::UTF8: return "UTF8";
    case StringLiteralKind::UTF16: return "UTF16";
    case StringLiteralKind::UTF32: return "UTF32";
    case StringLiteralKind::UNEVALUATED: return "UNEVALUATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
