// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <map>

#include "AST.h"  // Auto-generated, brings in `Iterator.h` and `Use.h`.
#include "Fragment.h"
#include "Query.h"

namespace mx {

class CachingEntityProvider;
class EntityProvider;
class File;
class FragmentList;
class FileFragmentListIterator;
class FileImpl;
class FileListImpl;
class Fragment;
class FragmentImpl;
class Index;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryResultIterator;
class RegexQueryMatch;
class RegexQueryResultImpl;
class RegexQueryResult;
class InvalidEntityProvider;
class WeggliQuery;
class WeggliQueryMatch;
class WeggliQueryResultIterator;
class WeggliQueryResult;
class WeggliQueryResultImpl;

using DeclUse = Use<DeclUseSelector>;
using StmtUse = Use<StmtUseSelector>;
using TypeUse = Use<TypeUseSelector>;

using ParentDeclIterator = ParentDeclIteratorImpl<Decl>;
using ParentStmtIterator = ParentStmtIteratorImpl<Stmt>;

using FilePathList = std::map<std::filesystem::path, FileId>;

template <typename T>
inline ParentDeclIteratorImpl<T> &
ParentDeclIteratorImpl<T>::operator++(void) & {
  impl = impl->parent_declaration();
  return *this;
}

template <typename T>
inline ParentStmtIteratorImpl<T> &
ParentStmtIteratorImpl<T>::operator++(void) & {
  impl = impl->parent_statement();
  return *this;
}

// Provides the APIs with entities.
class EntityProvider {
 public:
  using Ptr = std::shared_ptr<EntityProvider>;

  virtual ~EntityProvider(void) noexcept;

  // Returns an entity provider that gets entities from a remote host.
  static Ptr from_remote(std::string host, std::string port);

  // Returns an entity provider that gets entities from a UNIX domain socket.
  static Ptr from_socket(std::filesystem::path path);

  // Create an in-memory caching entity provider.
  static Ptr in_memory_cache(Ptr next);

 private:
  friend class CachingEntityProvider;
  friend class Decl;
  friend class File;
  friend class FileImpl;
  friend class FileListIterator;
  friend class FileFragmentListIterator;
  friend class FileListImpl;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class PackedFileImpl;
  friend class PackedFragmentImpl;
  friend class ReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class RegexQueryResultImpl;
  friend class RegexQueryResultIterator;
  friend class RemoteEntityProvider;
  friend class UseIteratorImpl;
  friend class WeggliQueryResultImpl;
  friend class WeggliQueryResultIterator;

 protected:

  // Clients may make requests while the indexer is still running. For many
  // things this doesn't generally matter, but for others it does. For example,
  // if the indexer is still running, the the returned file list may be
  // incomplete. Similarly, a redeclaration list may be incomplete. Caching is
  // done client side, and we coarsely communicate whether or not the entire
  // cache is out-of-date via non-decreasing version numbers returned by client-
  // to-indexer requests.
  virtual unsigned VersionNumber(void) = 0;

  // Update the version number. This is basically a signal to invalidate any
  // caches.
  virtual void VersionNumberChanged(unsigned new_version_number) = 0;

  // Cache a returned file list.
  virtual void CacheFileList(const FilePathList &, unsigned) = 0;

  // Cache a returned list of redeclarations.
  virtual void CacheRedeclarations(
      const std::vector<RawEntityId> &, unsigned) = 0;

  // Cache a returned set of uses for a given set of redeclarations.
  virtual void CacheUses(
      const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
      unsigned) = 0;

  // Cache a returned set of references for a given set of redeclarations.
  virtual void CacheReferences(
      const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
      unsigned) = 0;

 private:

  // Clear the cache.
  virtual void ClearCache(void) = 0;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual FilePathList ListFiles(const Ptr &) = 0;

  // Download a file by its unique ID.
  virtual std::shared_ptr<const FileImpl>
  FileFor(const Ptr &, FileId id) = 0;

  // Download a fragment by its unique ID.
  virtual std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, FragmentId id) = 0;

  virtual std::shared_ptr<WeggliQueryResultImpl>
  Query(const Ptr &, const WeggliQuery &query) = 0;

  virtual std::shared_ptr<RegexQueryResultImpl>
  Query(const Ptr &, const RegexQuery &query) = 0;

  // Return the redeclarations of a given declaration.
  virtual std::vector<RawEntityId> Redeclarations(
      const Ptr &, RawEntityId eid) = 0;

  // Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
  // to analyze when looking for uses.
  virtual void FillUses(const Ptr &, RawEntityId eid,
                        std::vector<RawEntityId> &redecl_ids_out,
                        std::vector<FragmentId> &fragment_ids_out) = 0;

  // Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
  // to analyze when looking for references.
  virtual void FillReferences(const Ptr &, RawEntityId eid,
                              std::vector<RawEntityId> &redecl_ids_out,
                              std::vector<FragmentId> &fragment_ids_out) = 0;
};

class NotAnEntity {};

// Access to the indexed code.
class Index {
 private:
  friend class File;
  friend class Fragment;

  EntityProvider::Ptr impl;

 public:
  ~Index(void);
  Index(void);

  /* implicit */ inline Index(EntityProvider::Ptr impl_)
      : impl(std::move(impl_)) {}

  // Clear any internal caches.
  void clear_caches(void) const;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathList file_paths(void) const;

  // Download a file by its unique ID.
  std::optional<File> file(FileId id) const;

  // Download a fragment by its unique ID.
  std::optional<Fragment> fragment(FragmentId id) const;

  // Download a fragment based off of an entity ID.
  std::optional<Fragment> fragment_containing(EntityId) const;

  // Return an entity given its ID.
  std::variant<Decl, Stmt, Type, Token, TokenSubstitution, NotAnEntity>
  entity(EntityId) const;

  // Run a Weggli search over the fragments in the index.
  //
  // NOTE(pag): This will only match inside of indexed code, i.e. fragments.
  WeggliQueryResult query_fragments(const WeggliQuery &query) const;

  // Run a regular expression search over the fragments in the index.
  //
  // NOTE(pag): This will only match inside of indexed code, i.e. fragments.
  RegexQueryResult query_fragments(const RegexQuery &query) const;
};

}  // namespace mx
