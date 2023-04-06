// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <capnp/c++.capnp.h>
#include <capnp/message.h>
#include <gap/core/generator.hpp>
#include <map>
#include <multiplier/Types.h>
#include <optional>
#include <pasta/Util/File.h>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>

namespace pasta {
class AST;
class Decl;
class File;
class FileToken;
class Macro;
class MacroToken;
class Stmt;
class Token;
class Type;
}  // namespace pasta
namespace mx {
enum class TokenKind : unsigned short;
}  // namespace mx
namespace indexer {

using Entity = std::variant<pasta::Decl, pasta::Macro>;
struct EntityIdMap final : public std::unordered_map<const void *, mx::EntityId> {};
struct FileIdMap final : public std::unordered_map<const void *, mx::SpecificEntityId<mx::FileId>> {};
struct FileHashMap final : public std::unordered_map<pasta::File, std::string> {};
using TypeKey = std::pair<const void *, uint32_t>;
struct TypeIdMap final : public std::map<TypeKey, mx::SpecificEntityId<mx::TypeId>> {};
struct PseudoOffsetMap final : public std::unordered_map<const void *, uint32_t> {};
class EntityMapper;

// Return `true` of `tok` is in the context of `decl`.
bool TokenIsInContextOfDecl(const pasta::Token &tok, const pasta::Decl &decl);

// Returns the `pasta::FileToken` if this is a top-level token in the parse.
std::optional<pasta::FileToken> AsTopLevelFileToken(const pasta::Token &tok);

// Tell us if this was a token that was actually parsed, and thus should have
// a fragment token ID.
//
// NOTE(pag): This logic is similarly reflected in `EntityLabeller::Label`.
bool IsParsedToken(const pasta::Token &tok);

// Print a declaration; useful for error reporting.
std::string DeclToString(const pasta::Decl &decl);

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

// Try to find the `Decl` referenced by a particular `stmt`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Decl decl);

// Try to find the `Decl` referenced by a particular `stmt`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Stmt stmt);

// Try to find the `Decl` referenced by a particular `type`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Type type);

using RelatedEntityIds = std::unordered_map<const void *, mx::RawEntityId>;

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::Token &tok,
    uint64_t min_tok_index, uint64_t max_tok_index,
    RelatedEntityIds &related_ids,
    const RelatedEntityIds &hint_ids);

// Figure out the token from which this token is derived.
mx::RawEntityId DerivedTokenId(
    EntityMapper &em, const pasta::FileToken &tok, RelatedEntityIds &);

// Figure out the token from which this token is derived. This may drill down
// through macro tokens that are elided from the `TokenTree` because of merging
// of expansions with their argument pre-expansion phase. These two phases are
// represented as separate expansions in PASTA.
mx::RawEntityId DerivedTokenId(
    EntityMapper &em, const pasta::Token &tok,
    RelatedEntityIds &derived_map);

template <typename T>
struct EntityBuilder {
  capnp::MallocMessageBuilder message;
  typename T::Builder builder;

  inline EntityBuilder(void)
      : builder(message.initRoot<T>()) {}
};

std::string GetSerializedData(capnp::MessageBuilder &builder);

}  // namespace indexer
