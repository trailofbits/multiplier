// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>
#include <optional>
#include <QString>
#include <utility>

namespace mx {
class Decl;
class Index;
class Token;

enum class TokenKind : unsigned short;
enum class DeclCategory : unsigned char;

namespace gui {

enum class TokenCategory : unsigned char;

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

// Categorize a token.
TokenCategory CategorizeToken(const Token &token, TokenClass tok_class,
                              DeclCategory decl_category);

// Categorize a token.
TokenCategory CategorizeToken(const Token &token, DeclCategory decl_category);

// Try to determine the declarations associated with this token.
std::optional<Decl> DeclForToken(const Token &token);

using EntityBaseOffsetPair = std::pair<RawEntityId, uint32_t>;

// Returns a pair of `(fragment_id, offset)` or `(kInvalidEntityId, 0)` for a
// given raw entity id.
EntityBaseOffsetPair GetFragmentOffset(RawEntityId id);

// Returns a pair of `(file_id, offset)` or `(kInvalidEntityId, 0)` for a
// given raw entity id.
EntityBaseOffsetPair GetFileOffset(RawEntityId id);

// Return the "canonical" ID of a declaration. This tries to get us the
// definition when possible.
RawEntityId CanonicalId(const Decl &decl);

// Return the "canonical" version of a declaration. This tries to get us the
// definition when possible.
Decl CanonicalDecl(const Decl &decl);

// Return some kind of name for a declaration.
QString DeclName(const Decl &decl);

// Return the file location of an entity.
RawEntityId EntityFileLocation(const Index &index, RawEntityId eid);

// Return the optional nearest fragment token associated with this declaration.
std::optional<Token> DeclFragmentToken(const Decl &decl);

// Return the optional nearest file token associated with this declaration.
std::optional<Token> DeclFileToken(const Decl &decl);

// Return the entity ID of the nearest file token associated with this
// declaration.
RawEntityId DeclFileLocation(const Decl &decl);

// Try to get the nearest declaration for `id`. Ideally, `id` is a declaration
// ID. Otherwise, it will find the nearest enclosing declaration, and return
// that.
std::optional<Decl> NearestDeclFor(const Index &index, RawEntityId id);

// Create a breadcrumbs string of the token contexts.
QString TokenBreadCrumbs(const Token &ent, bool run_length_encode=true);

}  // namespace gui
}  // namespace mx
