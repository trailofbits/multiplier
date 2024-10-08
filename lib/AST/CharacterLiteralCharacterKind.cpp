// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CharacterLiteralCharacterKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CharacterLiteralCharacterKind e) {
  switch (e) {
    case CharacterLiteralCharacterKind::ASCII: return "ASCII";
    case CharacterLiteralCharacterKind::WIDE: return "WIDE";
    case CharacterLiteralCharacterKind::UTF8: return "UTF8";
    case CharacterLiteralCharacterKind::UTF16: return "UTF16";
    case CharacterLiteralCharacterKind::UTF32: return "UTF32";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
