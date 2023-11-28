// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StringLiteralStringKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StringLiteralStringKind e) {
  switch (e) {
    case StringLiteralStringKind::ORDINARY: return "ORDINARY";
    case StringLiteralStringKind::WIDE: return "WIDE";
    case StringLiteralStringKind::UTF8: return "UTF8";
    case StringLiteralStringKind::UTF16: return "UTF16";
    case StringLiteralStringKind::UTF32: return "UTF32";
    case StringLiteralStringKind::UNEVALUATED: return "UNEVALUATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
