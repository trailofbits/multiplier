// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Database.h"
#include "Entities/Attr.h"
#include "Entities/CXXBaseSpecifier.h"
#include "Entities/DefineMacroDirective.h"
#include "Entities/Designator.h"
#include "Entities/Macro.h"
#include "Entities/NamedDecl.h"
#include "Entities/Stmt.h"
#include "Entities/TemplateArgument.h"
#include "Entities/TemplateParameterList.h"
#include "Entities/Type.h"
#include "Fragment.h"
#include "Iterator.h"
#include "Query.h"
#include "Reference.h"

namespace mx {

class CachingEntityProvider;
class EntityProvider;
class File;
class Fragment;
class IncludeLikeMacroDirective;
class Index;
class InvalidEntityProvider;
class ReadMacroTokensFromFragment;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryMatch;
class Token;
class TokenReader;
class WeggliQuery;
class WeggliQueryMatch;

#define MX_FORWARD_DECLARE_IMPL_CLASS(type_name, ln, e, c) \
    class type_name ## Impl; \
    using type_name ## ImplPtr = std::shared_ptr<const type_name ## Impl>; \
    using Weak ## type_name ## ImplPtr = std::weak_ptr<const type_name ## Impl>;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE_IMPL_CLASS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_FORWARD_DECLARE_IMPL_CLASS,
                              MX_FORWARD_DECLARE_IMPL_CLASS)
#undef MX_FORWARD_DECLARE_IMPL_CLASS

using FilePathMap = std::map<std::filesystem::path, PackedFileId>;
using FragmentIdList = std::vector<PackedFragmentId>;
using DeclIdList = std::vector<PackedDeclId>;
using RawEntityIdList = std::vector<RawEntityId>;

using NamedEntity = std::variant<NamedDecl, DefineMacroDirective>;
using NamedEntityList = std::vector<NamedEntity>;

// Provides the APIs with entities.
class EntityProvider {
 public:
  using Ptr = std::shared_ptr<EntityProvider>;

  virtual ~EntityProvider(void) noexcept;

  // Create an in-memory caching entity provider.
  static Ptr in_memory_cache(Ptr next, unsigned timeout_s=1u);

  static Ptr from_database(std::filesystem::path path);

 private:
  friend class CachingEntityProvider;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class IncludeLikeMacroDirective;
  friend class Index;
  friend class Macro;
  friend class ReadMacroTokensFromFragment;
  friend class ReadParsedTokensFromFragment;
  friend class Reference;
  friend class RegexQuery;
  friend class RegexQueryResultImpl;
  friend class RemoteEntityProvider;
  friend class Token;
  friend class TokenReader;
  friend class TokenContext;
  friend class WeggliQuery;
  friend class WeggliQueryResultImpl;

 public:

  // Clients may make requests while the indexer is still running. For many
  // things this doesn't generally matter, but for others it does. For example,
  // if the indexer is still running, the the returned file list may be
  // incomplete. Similarly, a redeclaration list may be incomplete. Caching is
  // done client side, and we coarsely communicate whether or not the entire
  // cache is out-of-date via non-decreasing version numbers returned by client-
  // to-indexer requests.
  virtual unsigned VersionNumber(const Ptr &) = 0;
  virtual unsigned VersionNumber(void) = 0;

  // Update the version number. This is basically a signal to invalidate any
  // caches.
  virtual void VersionNumberChanged(unsigned new_version_number) = 0;

  // Clear the cache.
  virtual void ClearCache(void) = 0;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual FilePathMap ListFiles(const Ptr &) = 0;

  // Download a list of fragment IDs contained in a specific file.
  virtual FragmentIdList ListFragmentsInFile(const Ptr &, PackedFileId id) = 0;

  // Get a token by its entity ID.
  Token TokenFor(const Ptr &, RawEntityId id);

  // Get a token by its entity ID, and given the presence of an existing reader
  // that can be used as a hint for being the current reader for the token.
  Token TokenFor(const Ptr &, const std::shared_ptr<const TokenReader> &,
                 RawEntityId id);

#define MX_DECLARE_ENTITY_METHODS(type_name, lower_name, enum_name, category) \
    friend class type_name ## Impl; \
    \
    virtual gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, PackedFragmentId id) = 0; \
    \
    virtual type_name ## ImplPtr type_name ## For( \
        const Ptr &, PackedFragmentId id, EntityOffset offset) = 0; \
    \
    virtual type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, RawEntityId id) = 0; \
    \
    inline type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, Packed ## type_name ## Id id) { \
      return ep->type_name ## For(ep, id.Pack()); \
    }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_METHODS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_METHODS,
                              MX_DECLARE_ENTITY_METHODS)
#undef MX_DECLARE_ENTITY_METHODS

  // Return the list of fragments covering / overlapping some tokens in a file.
  virtual FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset> tokens) = 0;

  // Return the redeclarations of a given declaration.
  virtual RawEntityIdList Redeclarations(
      const Ptr &, SpecificEntityId<DeclId> eid) = 0;

  // Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
  // to analyze when looking for uses.
  //
  // NOTE(pag): `fragment_ids_out` will always contain the fragment associated
  //            with `eid` if `eid` resides in a fragment.
  virtual void FillUses(const Ptr &, RawEntityId eid,
                        RawEntityIdList &redecl_ids_out,
                        FragmentIdList &fragment_ids_out) = 0;

  // Fill out `redecl_ids_out` and `references_ids_out` with the set of things
  // to analyze when looking for references.
  virtual void FillReferences(const Ptr &, RawEntityId eid,
                              RawEntityIdList &redecl_ids_out,
                              RawEntityIdList &references_ids_out) = 0;

  // Find the entity ids matching the name
  virtual void FindSymbol(const Ptr &, std::string name,
                          RawEntityIdList &ids_out) = 0;
};

#define MX_DECLARE_ENTITY_VARIANT(type_name, lower_name, enum_name, category) \
    , type_name

using VariantEntity = std::variant<
    NotAnEntity MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT,
                                            MX_DECLARE_ENTITY_VARIANT)>;
#undef MX_DECLARE_ENTITY_VARIANT

enum class IndexStatus : unsigned {
  UNINITIALIZED,
  INDEXING_IN_PROGRESS,
  INDEXED
};

inline static const char *EnumerationName(IndexStatus) {
  return "IndexStatus";
}

inline constexpr unsigned NumEnumerators(IndexStatus) {
  return 3u;
}

const char *EnumeratorName(IndexStatus);

// Access to the indexed code.
class Index {
 private:
  friend class File;
  friend class Fragment;

  EntityProvider::Ptr impl;

 public:
  ~Index(void);
  Index(void);

  Index(const Index &) = default;
  Index(Index &&) noexcept = default;

  Index &operator=(const Index &) = default;
  Index &operator=(Index &&) noexcept = default;

  /* implicit */ inline Index(EntityProvider::Ptr impl_)
      : impl(std::move(impl_)) {}

  static Index containing(const Fragment &entity);
  static Index containing(const File &entity);
  static Index containing(const Decl &entity);
  static Index containing(const Stmt &entity);
  static Index containing(const Type &entity);
  static Index containing(const Attr &entity);
  static Index containing(const Macro &entity);
  static Index containing(const Designator &entity);
  static std::optional<Index> containing(const Token &entity);

  // Return the status of the index.
  IndexStatus status(bool block=false) const;

  // Clear any internal caches.
  void clear_caches(void) const;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathMap file_paths(void) const;

#define MX_DECLARE_GETTER(type_name, lower_name, enum_name, category) \
  std::optional<type_name> lower_name(RawEntityId id) const; \
  \
  inline std::optional<type_name> lower_name( \
      Packed ## type_name ## Id id) const { \
    return lower_name(id.Pack()); \
  }

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_GETTER, MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_GETTER, MX_DECLARE_GETTER)
#undef MX_DECLARE_GETTER

  // Download a fragment based off of an entity ID.
  std::optional<Fragment> fragment_containing(EntityId) const;

  template <typename T>
  inline std::optional<EntityType<T>> entity(T eid) const {
    VariantEntity vent = entity(eid.Pack());
    if (std::holds_alternative<EntityType<T>>(vent)) {
      return std::move(std::get<EntityType<T>>(vent));
    } else {
      return std::nullopt;
    }
  }

  template <typename T>
  inline std::optional<EntityType<T>> entity(SpecificEntityId<T> eid) const {
    VariantEntity vent = entity(eid.Pack());
    if (std::holds_alternative<EntityType<T>>(vent)) {
      return std::move(std::get<EntityType<T>>(vent));
    } else {
      return std::nullopt;
    }
  }

  // Return an entity given its ID.
  VariantEntity entity(EntityId eid) const;

  // Return all files in the index.
  gap::generator<File> files(void) const;

  // Return an entity given its ID.
  template <typename T>
  inline auto
  entity(const std::optional<T> &id) const -> decltype(entity(T())) {
    if (id) {
      return entity(id.value());
    } else {
      return NotAnEntity{};
    }
  }

  // Search for entities by their name and category.
  NamedEntityList query_entities(std::string name) const;
};

}  // namespace mx
