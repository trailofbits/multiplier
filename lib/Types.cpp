// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Types.h>

#include <chrono>
#include <clang/Basic/TokenKinds.h>

namespace mx {

TokenKind FromClang(clang::tok::TokenKind tk) {
  if (clang::tok::raw_identifier == tk) {
    return TokenKind::TK_identifier;
  } else {
    return static_cast<TokenKind>(tk);
  }
}

clang::tok::TokenKind ToClang(TokenKind tk) {
  switch (tk) {
    case TokenKind::TK_whitespace: return clang::tok::unknown;
#define PPKEYWORD(X) \
    case TokenKind::TK_pp_ ## X: return clang::tok::identifier;
#include "clang/Basic/TokenKinds.def"

#define OBJC_AT_KEYWORD(X) \
    case TokenKind::TK_objc_ ## X: return clang::tok::identifier;
#include "clang/Basic/TokenKinds.def"

    default:
      return static_cast<clang::tok::TokenKind>(tk);
  }
}

// Return the current time.
Time TimeNow(void) noexcept {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

}  // namespace mx
