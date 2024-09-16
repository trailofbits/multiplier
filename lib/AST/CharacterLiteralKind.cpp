// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CharacterLiteralKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CharacterLiteralKind e) {
  switch (e) {
    case CharacterLiteralKind::ASCII: return "ASCII";
    case CharacterLiteralKind::WIDE: return "WIDE";
    case CharacterLiteralKind::UTF8: return "UTF8";
    case CharacterLiteralKind::UTF16: return "UTF16";
    case CharacterLiteralKind::UTF32: return "UTF32";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
