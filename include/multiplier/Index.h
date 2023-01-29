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
#include "Iterator.h"
#include "Use.h"
#include "Fragment.h"
#include "Query.h"
#include "Entities/Attr.h"
#include "Entities/DefineMacroDirective.h"
#include "Entities/Designator.h"
#include "Entities/Macro.h"
#include "Entities/NamedDecl.h"
#include "Entities/Stmt.h"
#include "Entities/Type.h"

namespace mx {

class CachingEntityProvider;
class EntityProvider;
class File;
class FileImpl;
class Fragment;
class FragmentImpl;
class IncludeLikeMacroDirective;
class Index;
class InvalidEntityProvider;
class ReadMacroTokensFromFragment;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryMatch;
class TokenReader;
class WeggliQuery;
class WeggliQueryMatch;
class OffsetEntityImpl;

using EntityImplPtr = std::shared_ptr<OffsetEntityImpl>;
using WeakEntityImplPtr = std::weak_ptr<OffsetEntityImpl>;

using DeclUse = Use<DeclUseSelector>;
using StmtUse = Use<StmtUseSelector>;
using TypeUse = Use<TypeUseSelector>;
using FileUse = Use<FileUseSelector>;
using TokenUse = Use<TokenUseSelector>;
using MacroUse = Use<MacroUseSelector>;

using FilePathMap = std::map<std::filesystem::path, PackedFileId>;
using FragmentIdList = std::vector<PackedFragmentId>;
using DeclarationIdList = std::vector<PackedDeclarationId>;
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
  friend class FileImpl;
  friend class Fragment;
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class Index;
  friend class Macro;
  friend class ReadMacroTokensFromFragment;
  friend class ReadParsedTokensFromFragment;
  friend class ReferenceIteratorImpl;
  friend class RegexQuery;
  friend class RegexQueryResultImpl;
  friend class RemoteEntityProvider;
  friend class Token;
  friend class TokenReader;
  friend class TokenContext;
  friend class UseBase;
  friend class UseIteratorImpl;
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

  std::shared_ptr<const FileImpl> FileFor(const Ptr &self, RawEntityId id) {
    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FileId>(vid)) {
      return FileFor(self, PackedFileId(std::get<FileId>(vid)));
    } else {
      return {};
    }
  }

  std::shared_ptr<const FragmentImpl> FragmentFor(
      const Ptr &self, RawEntityId id) {
    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FragmentId>(vid)) {
      return FragmentFor(self, PackedFragmentId(std::get<FragmentId>(vid)));
    } else {
      return {};
    }
  }

  // Download a file by its unique ID.
  //
  // NOTE(pag): The `id` is *NOT* a packed representation, is the underlying/
  //            raw file id.
  virtual std::shared_ptr<const FileImpl>
  FileFor(const Ptr &, PackedFileId id) = 0;

  // Download a fragment by its unique ID.
  //
  // NOTE(pag): The `id` is *NOT* a packed representation, is the underlying/
  //            raw fragment id.
  virtual std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, PackedFragmentId id) = 0;


#define DECLARE_ENTITY_METHODS(name, lower_name) \
    virtual gap::generator<EntityImplPtr> \
    name ## sFor(const Ptr &, PackedFragmentId id) = 0; \
    virtual std::optional<EntityImplPtr> \
    name ## For(const Ptr &, PackedFragmentId id, EntityOffset offset) = 0; \
    virtual std::optional<EntityImplPtr> \
    name ## For(const Ptr &ep, RawEntityId id) = 0;

  MX_FOR_EACH_ENTITY_RECORD(DECLARE_ENTITY_METHODS)
#undef DECLARE_ENTITY_METHODS

  // Return the list of fragments covering / overlapping some tokens in a file.
  virtual FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset> tokens) = 0;

  // Return the redeclarations of a given declaration.
  virtual RawEntityIdList Redeclarations(
      const Ptr &, SpecificEntityId<DeclarationId> eid) = 0;

  // Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
  // to analyze when looking for uses.
  //
  // NOTE(pag): `fragment_ids_out` will always contain the fragment associated
  //            with `eid` if `eid` resides in a fragment.
  virtual void FillUses(const Ptr &, RawEntityId eid,
                        RawEntityIdList &redecl_ids_out,
                        FragmentIdList &fragment_ids_out) = 0;

  // Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
  // to analyze when looking for references.
  //
  // NOTE(pag): `fragment_ids_out` will always contain the fragment associated
  //            with `eid` if `eid` resides in a fragment.
  virtual void FillReferences(const Ptr &, RawEntityId eid,
                              RawEntityIdList &redecl_ids_out,
                              FragmentIdList &fragment_ids_out) = 0;

  // Find the entity ids matching the name
  virtual void FindSymbol(const Ptr &, std::string name,
                          RawEntityIdList &ids_out) = 0;
};

using VariantEntity = std::variant<NotAnEntity, Decl, Stmt, Type, Attr, Macro,
                                   Token, Designator, Fragment, File>;

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

  // Download a file by its unique ID.
  std::optional<File> file(SpecificEntityId<FileId> id) const;
  std::optional<File> file(FileId id) const;
  std::optional<File> file(RawEntityId id) const;

  // Download a fragment by its unique ID.
  std::optional<Fragment> fragment(SpecificEntityId<FragmentId> id) const;
  std::optional<Fragment> fragment(FragmentId id) const;
  std::optional<Fragment> fragment(RawEntityId id) const;

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
