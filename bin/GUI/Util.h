// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

namespace mx {
class Decl;
class Token;

enum class TokenKind : unsigned short;

namespace gui {

enum class TokenClass {
  kUnknown,
  kIdentifier,
  kMacroName,
  kKeyword,
  kObjectiveCKeyword,
  kPreProcessorKeyword,
  kBuiltinTypeName,
  kPunctuation,
  kLiteral,
  kComment
};

// Classify a token kind into a `TokenClass`. Token classes are good baseline
// indicators for syntax coloring.
TokenClass ClassifyToken(const Token &token);

// Try to determine the declarations associated with this token.
std::optional<Decl> DeclForToken(const Token &token);

}  // namespace gui
}  // namespace mx
