// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Types.h>

#include <chrono>

#include <pasta/AST/Forward.h>

namespace mx {

TokenKind FromPasta(pasta::TokenKind tk) {
  if (pasta::TokenKind::kRawIdentifier == tk) {
    return TokenKind::TK_identifier;

  } else {
    return static_cast<TokenKind>(tk);
  }
}

pasta::TokenKind ToPasta(TokenKind tk) {
  switch (tk) {
    case TokenKind::TK_whitespace:
      return pasta::TokenKind::kUnknown;

    // These are derived from PASTA token roles, so they don't actually exist
    // in Clang's token kinds.
    case TokenKind::TK_begin_macro_expansion:
    case TokenKind::TK_end_macro_expansion:
    case TokenKind::TK_begin_file:
    case TokenKind::TK_end_file:
    case TokenKind::TK_begin_directive:
    case TokenKind::TK_end_directive:
      return pasta::TokenKind::kUnknown;

#define PPKEYWORD(X) \
    case TokenKind::TK_pp_ ## X: return pasta::TokenKind::kIdentifier;
#include "clang/Basic/TokenKinds.def"

#define OBJC_AT_KEYWORD(X) \
    case TokenKind::TK_objc_ ## X: return pasta::TokenKind::kIdentifier;
#include "clang/Basic/TokenKinds.def"

    default:
      return static_cast<pasta::TokenKind>(tk);
  }
}

// Return the current time.
Time TimeNow(void) noexcept {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

}  // namespace mx
