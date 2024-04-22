// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <capnp/c++.capnp.h>
#include <capnp/message.h>
#include <cstdint>
#include <gap/core/generator.hpp>
#include <iosfwd>
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
class CXXCtorInitializer;
class Decl;
class DeclContext;
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
using DerivedToken = std::variant<std::monostate, pasta::MacroToken, pasta::FileToken>;
enum class TemplateSpecializationKind : unsigned int;
}  // namespace pasta
namespace mx {
enum class TokenKind : unsigned short;
}  // namespace mx
namespace indexer {

using Entity = std::variant<std::monostate, pasta::Decl, pasta::Macro>;
using EntityLocation = std::pair<uint32_t, uint32_t>;
struct EntityIdMap final : public std::unordered_map<const void *, mx::EntityId> {};
struct EntityParentMap final : public std::unordered_map<const void *, const void *> {};
struct FileIdMap final : public std::unordered_map<const void *, mx::SpecificEntityId<mx::FileId>> {};
struct FileHashMap final : public std::unordered_map<pasta::File, std::string> {};
using TypeKey = std::pair<const void *, uint32_t>;
struct TypeIdMap final : public std::map<TypeKey, mx::SpecificEntityId<mx::TypeId>> {};
struct PseudoOffsetMap final : public std::unordered_map<const void *, uint32_t> {};
struct EntityLocationMap final : public std::unordered_map<const void*, EntityLocation> {};
class EntityMapper;
class TokenTree;
class TokenTreeNode;

// Return `true` of `tok` is in the context of `decl`.
bool TokenIsInContextOfDecl(const pasta::Token &tok, const pasta::Decl &decl);

// Returns the `pasta::FileToken` if this is a top-level token in the parse.
std::optional<pasta::FileToken> AsTopLevelFileToken(const pasta::Token &tok);

// Tell us if this was a token that was actually parsed, and thus should have
// a fragment token ID.
//
// NOTE(pag): This logic is similarly reflected in `EntityLabeller::Label`.
bool IsParsedToken(const pasta::Token &tok);

// Like `IsParsedToken`, but returns `false` for whitespace and comments that
// were made visible to Clang's preprocessor.
bool IsParsedTokenExcludingWhitespaceAndComments(const pasta::Token &tok);

// Compute the last token of a macro.
std::optional<pasta::MacroToken> EndToken(const pasta::Macro &macro);

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

mx::TokenKind TokenKindFromPasta(pasta::TokenKind kind, std::string_view data);

pasta::DerivedToken DerivedLocation(const pasta::DerivedToken &tok);

// Returns `true` if `decl` is a definition.
bool IsDefinition(const pasta::Decl &decl);

// Generate the token contexts associated with a printed token.
gap::generator<pasta::TokenContext> TokenContexts(pasta::PrintedToken tok);

// Checks if the declaration is valid and serializable
bool IsSerializableDecl(const pasta::Decl &decl);

// This the specialization kind explicit? This corresponds to something like
// `extern template class foo<type>;`.
bool IsExplicitInstantiation(const pasta::TemplateSpecializationKind &kind);

// Is the specialization kind explicit? This corresponds to a template
// specialization being fully spelled out in the code, rather than being derived
// from a template pattern or a partial specialization pattern.
bool IsExplicitSpecialization(const pasta::TemplateSpecializationKind &kind);

// Is the specialization kind explicit? This corresponds to a template
// specialization being fully spelled out in the code, rather than being derived
// from a template pattern or a partial specialization pattern.
bool IsExplicitSpecialization(const pasta::Decl &kind);

// Returns whether or not `decl` is a specialization of a template. Clang
// reports methods derived from methods inside of class templates as being
// specializations, but this function focuses on determining that something is
// actually derived from a template, i.e. a method is a specialization if it is
// derived from a method inside of a function template.
bool IsSpecialization(const pasta::Decl &decl);

// Is this decl a specialization of a template? If so, then we will want
// to render the printed tokens of the specialization into the fragment, rather
// than the parsed tokens. If this is something like a function inside of a
// specialization, then we'll also want to do the same thing.
bool IsSpecializationOrInSpecialization(const pasta::Decl &decl);

// Is this decl a template or template pattern?
bool IsTemplateOrPattern(const pasta::Decl &decl);

// Check of the declaration is Out of Line
bool IsOutOfLine(const pasta::Decl &decl);

// Returns `true` if this declaration is a method inside of a class template
// specialization.
bool IsMethodLexicallyInSpecialization(const pasta::Decl &decl);

// If `decl` is a declaration context, then this will return `true` if `decl`
// should be internalized into the fragment, otherwise `false`. Returns `false`
// if `decl` isn't a declaration context.
bool ShouldInternalizeDeclContextIntoFragment(const pasta::Decl &decl);

// Determines whether or not a TLM is likely to have to go into a floating
// fragment. This generally happens when a TLM is a directive.
bool ShouldGoInFloatingFragment(const pasta::Macro &macro);

// Returns `true` if a macro is visible across fragments, and should have an
// entity id stored in the global mapper.
bool IsVisibleAcrossFragments(const pasta::Macro &macro);

// Tells us if a given decl is probably a use that also acts as a forward
// declaration.
bool IsInjectedForwardDeclaration(const pasta::Decl &decl);

// Should a declaration be hidden from the indexer?
bool ShouldHideFromIndexer(const pasta::Decl &decl);

// Does `decl` look like a lambda?
bool IsLambda(const pasta::Decl &decl);

// List the indexable declarations in this declcontext.
std::vector<pasta::Decl> DeclarationsInDeclContext(const pasta::DeclContext &dc);

template <typename T>
inline static bool ShouldHideFromIndexer(const T &) {
  return false;
}

// Return an opaque pointer to the underlying representation of a given entity.
// This uniquely identifies the entity.
const void *RawEntity(const pasta::Token &entity);
const void *RawEntity(const pasta::PrintedToken &entity);
const void *RawEntity(const pasta::File &entity);
const void *RawEntity(const pasta::FileToken &entity);
const void *RawEntity(const pasta::Decl &entity);
const void *RawEntity(const pasta::DeclContext &entity);
const void *RawEntity(const pasta::Stmt &entity);
const void *RawEntity(const pasta::Attr &entity);
const void *RawEntity(const pasta::Macro &entity);
const void *RawEntity(const pasta::Designator &entity);
const void *RawEntity(const pasta::CXXBaseSpecifier &entity);
const void *RawEntity(const pasta::CXXCtorInitializer &entity);
const void *RawEntity(const pasta::TemplateArgument &entity);
const void *RawEntity(const pasta::TemplateParameterList &entity);
const void *RawEntity(const TokenTree &entity);
const void *RawEntity(const TokenTreeNode &entity);
const void *RawEntity(const pasta::DerivedToken &entity);

template <typename T>
inline static const void *RawEntity(const std::optional<T> &entity) {
  return entity ? RawEntity(entity.value()) : nullptr;
}

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

// Helpful function to be called from a debugger where a `std::ostream`
// argument is needed.
std::ostream &StdErr(void);

// This is a helpful function to be called from a debugger.
std::string DiagnosePrintedTokens(const pasta::PrintedTokenRange &);

// Returns `c` if `c` isn't an alias, otherwise `c.Aliasee().value()`.
pasta::TokenContext UnaliasedContext(const pasta::TokenContext &c);

pasta::Macro RootMacroFrom(const pasta::Macro &node);

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

// Generate all specializations of a template. Our Clang patches will sometimes
// create specializations that are linked into redecl chains but not linked into
// the template's specialization list due to it being a set and not being
// prepared to handle duplicates.
template <typename S>
static std::vector<S> ExpandSpecializations(std::vector<S> specs) {
  auto size = specs.size();
  for (auto i = 0u; i < size; ++i) {
    for (const auto &redecl : specs[i].Redeclarations()) {
      if (redecl != specs[i]) {
        if (auto derived = S::From(redecl)) {
          specs.emplace_back(derived.value());
        }
      }
    }
  }

  std::sort(specs.begin(), specs.end(), [] (const S &a, const S &b) {
    return RawEntity(a) < RawEntity(b);
  });

  auto it = std::unique(specs.begin(), specs.end(), [] (const S &a, const S &b) {
    return RawEntity(a) == RawEntity(b);
  });

  specs.erase(it, specs.end());

  return specs;
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

template <typename T>
class PrevValueTracker {
  T const prev_dc;
  T &dc_ref;
  const bool is_new;
 public:
  inline PrevValueTracker(T &dc_ref_, T new_dc)
      : prev_dc(dc_ref_),
        dc_ref(dc_ref_),
        is_new(prev_dc != new_dc) {
    dc_ref = new_dc;
  }

  inline operator bool(void) const noexcept {
    return is_new;
  }

  inline ~PrevValueTracker(void) {
    dc_ref = prev_dc;
  }
};

// If this is a debug build, then invoke Clang's `clang::Decl::dumpColor()` on
// `decl`.
void Dump(const pasta::Decl &decl);

}  // namespace indexer
