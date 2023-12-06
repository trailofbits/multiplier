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
#include <multiplier/Iterator.h>
#include <multiplier/Types.h>
#include <optional>
#include <pasta/Util/File.h>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>

namespace pasta {
class AST;
class Attr;
class CXXBaseSpecifier;
class Decl;
class Designator;
class File;
class FileToken;
class Macro;
class MacroToken;
class PrintedToken;
class PrintedTokenRange;
class Stmt;
class TemplateArgument;
class TemplateParameterList;
class Token;
class TokenContext;
class Type;
}  // namespace pasta
namespace mx {
enum class TokenKind : unsigned short;
}  // namespace mx
namespace indexer {

using Entity = std::variant<std::monostate, pasta::Decl, pasta::Macro>;
struct EntityIdMap final : public std::unordered_map<const void *, mx::EntityId> {};
struct EntityParentMap final : public std::unordered_map<const void *, const void *> {};
struct FileIdMap final : public std::unordered_map<const void *, mx::SpecificEntityId<mx::FileId>> {};
struct FileHashMap final : public std::unordered_map<pasta::File, std::string> {};
using TypeKey = std::pair<const void *, uint32_t>;
struct TypeIdMap final : public std::map<TypeKey, mx::SpecificEntityId<mx::TypeId>> {};
struct PseudoOffsetMap final : public std::unordered_map<const void *, uint32_t> {};
class EntityMapper;
class TokenTree;

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

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::PrintedToken &entity);

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

// Generate the token contexts associated with a printed token.
gap::generator<pasta::TokenContext> TokenContexts(pasta::PrintedToken tok);

// Checks if the declaration is valid and serializable
bool IsSerializableDecl(const pasta::Decl &decl);

// Determines whether or not a TLD is likely to have to go into a child
// fragment. This happens when the TLD is a forward declaration, e.g. of a
// struct.
bool ShouldGoInNestedFragment(const pasta::Decl &decl);

// Determines whether or not a TLM is likely to have to go into a child
// fragment. This generally happens when a TLM is a directive.
bool ShouldGoInNestedFragment(const pasta::Macro &macro);

// Returns `true` if a macro is visible across fragments, and should have an
// entity id stored in the global mapper.
bool AreVisibleAcrossFragments(const pasta::Macro &macro);

// Tells us if a given decl is probably a use that also acts as a forward
// declaration.
bool IsInjectedForwardDeclaration(const pasta::Decl &decl);

// Should a declaration be hidden from the indexer?
bool ShouldHideFromIndexer(const pasta::Decl &decl);

template <typename T>
inline static bool ShouldHideFromIndexer(const T &) {
  return false;
}

// Return an opaque pointer to the underlying representation of a given entity.
// This uniquely identifies the entity.
const void *RawEntity(const pasta::Token &entity);
const void *RawEntity(const pasta::Decl &entity);
const void *RawEntity(const pasta::Stmt &entity);
const void *RawEntity(const pasta::Attr &entity);
const void *RawEntity(const pasta::Macro &entity);
const void *RawEntity(const pasta::Designator &entity);
const void *RawEntity(const pasta::CXXBaseSpecifier &entity);
const void *RawEntity(const pasta::TemplateArgument &entity);
const void *RawEntity(const pasta::TemplateParameterList &entity);
const void *RawEntity(const TokenTree &entity);

template <typename T>
struct EntityBuilder {
  capnp::MallocMessageBuilder message;
  typename T::Builder builder;

  inline EntityBuilder(void)
      : builder(message.initRoot<T>()) {}
};

std::string GetSerializedData(capnp::MessageBuilder &builder);

template <typename Tok>
void AccumulateTokenData(std::string &data, const Tok &tok);

std::string DiagnosePrintedTokens(const pasta::PrintedTokenRange &);

// Returns `c` if `c` isn't an alias, otherwise `c.Aliasee().value()`.
pasta::TokenContext UnaliasedContext(const pasta::TokenContext &c);

uint32_t Hash32(std::string_view data);
uint64_t Hash64(std::string_view data);

template <typename Kind>
struct HashKind {
  inline constexpr unsigned operator()(Kind k) const noexcept {
    return static_cast<unsigned>(k);
  }
};

template <typename Entity>
using EntityList = std::vector<Entity>;

template <typename Kind, typename Entity>
using KindGroupedEntityLists = std::unordered_map<Kind, EntityList<Entity>, HashKind<Kind>>;

template <typename Entity>
inline static unsigned NumEntities(const EntityList<Entity> &entities) {
  return static_cast<unsigned>(entities.size());
}

template <typename Kind, typename Entity>
inline static unsigned NumEntities(
    const KindGroupedEntityLists<Kind, Entity> &entities_by_kind) {
  unsigned num_entities = 0u;
  for (const auto &[_, entities] : entities_by_kind) {
    num_entities += NumEntities(entities);
  }
  return num_entities;
}

// Figure out the minimum size needed for a serialized list-of-lists to hold
// the entities. This is the underlying integral value of the entity kind, plus
// one, as we use entity kinds as an index.
template <typename Kind, typename Entity>
unsigned SerializationListSize(
    const KindGroupedEntityLists<Kind, Entity> &entities_by_kind) {
  unsigned max_kind = 0u;
  auto has_kind = false;
  for (const auto &[kind, _] : entities_by_kind) {
    max_kind = std::max(static_cast<unsigned>(kind), max_kind);
    has_kind = true;
  }

  return has_kind ? max_kind + 1u : 0u;
}

// Generate the entities in kind-grouped entity lists.
//
// NOTE(pag): We don't use range based `for` loops in case the underlying size
//            of an entity list grows during iteration, or in case new lists
//            are added based on kinds.
template <typename Kind, typename Entity>
inline static gap::generator<Entity> Entities(
    const KindGroupedEntityLists<Kind, Entity> &entities_by_kind) {
  for (Kind kind : mx::EnumerationRange<Kind>()) {
    auto entities_it = entities_by_kind.find(kind);
    if (entities_it == entities_by_kind.end()) {
      continue;
    }

    const EntityList<Entity> &entities = entities_it->second;
    for (size_t i = 0u; i < entities.size(); ++i) {
      Entity entity = entities[i];
      co_yield std::move(entity);
    }
  }
}

// Generate the entities in an list.
//
// NOTE(pag): We don't use range based `for` loops in case the underlying size
//            of an entity list grows during iteration.
template <typename Entity>
inline static gap::generator<Entity> Entities(
    const EntityList<Entity> &entities) {
  for (size_t i = 0u; i < entities.size(); ++i) {
    Entity entity = entities[i];
    co_yield std::move(entity);
  }
}

}  // namespace indexer
