// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <string>
#include <string_view>

#include "Pseudo.h"

namespace pasta {
class AST;
class Decl;
class FileToken;
class MacroToken;
class Stmt;
class Token;
class Type;
}  // namespace pasta
namespace mx {
enum class TokenKind : unsigned short;
}  // namespace mx
namespace indexer {

// Print a declaration; useful for error reporting.
std::string DeclToString(const pasta::Decl &decl);

std::string DeclToString(const pasta::AST &ast, const pasta::Decl &decl);

// Return the name of a declaration with a leading `prefix`, or nothing.
std::string PrefixedName(const pasta::Decl &decl, const char *prefix=" ");

// Return the location of a declaration with a leading `prefix`, or nothing.
std::string PrefixedLocation(const pasta::Decl &decl, const char *prefix=" ");

// Returns `true` if `data` contains only whitespace or is empty.
bool IsWhitespaceOrEmpty(std::string_view data);

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::MacroToken &entity);

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::FileToken &entity);

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::Token &entity);

// Returns `true` if `decl` is a definition.
bool IsDefinition(const pasta::Decl &decl);

// Try to find the `Decl` referenced by a particular `type`.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Type &type);

// Try to find the `Decl` referenced by a particular `stmt`.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Stmt &stmt);

}  // namespace indexer
