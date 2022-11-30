// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <set>
#include <string>
#include <string_view>
#include <vector>

#include "Iterator.h"
#include "Use.h"
#include "Fragment.h"
#include "Query.h"
#include "Entities/NamedDecl.h"

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
class InvalidEntityProvider;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryResultIterator;
class RegexQueryMatch;
class RegexQueryResultImpl;
class RegexQueryResult;
class TokenReader;
class WeggliQuery;
class WeggliQueryMatch;
class WeggliQueryResultIterator;
class WeggliQueryResult;
class WeggliQueryResultImpl;
struct ASTNode;

class SyntexNodeKind;
class SyntexGrammarNode;
class SyntexQuery;
class SyntexQueryImpl;

using SyntexGrammarLeaves = std::unordered_map<SyntexNodeKind, SyntexGrammarNode>;

using DeclUse = Use<DeclUseSelector>;
using StmtUse = Use<StmtUseSelector>;
using TypeUse = Use<TypeUseSelector>;

using ParentDeclIterator = ParentDeclIteratorImpl<Decl>;
using ParentStmtIterator = ParentStmtIteratorImpl<Stmt>;

using FilePathList = std::set<std::pair<std::filesystem::path, RawEntityId>>;

using NamedDeclList = std::vector<NamedDecl>;

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

  // Create an in-memory caching entity provider.
  static Ptr in_memory_cache(Ptr next, unsigned timeout_s=1u);

  static Ptr from_database(std::filesystem::path path);

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
  friend class TokenReader;
  friend class UseIteratorImpl;
  friend class WeggliQueryResultImpl;
  friend class WeggliQueryResultIterator;
  friend class SyntexQuery;
  friend class SyntexQueryImpl;

 protected:

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

 private:

  // Clear the cache.
  virtual void ClearCache(void) = 0;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual FilePathList ListFiles(const Ptr &) = 0;

  // Download a list of fragment IDs contained in a specific file.
  virtual std::vector<EntityId>
  ListFragmentsInFile(const Ptr &, RawEntityId id) = 0;

  // Download a file by its unique ID.
  //
  // NOTE(pag): The `id` is *NOT* a packed representation, is the underlying/
  //            raw file id.
  virtual std::shared_ptr<const FileImpl>
  FileFor(const Ptr &, RawEntityId id) = 0;

  // Download a fragment by its unique ID.
  //
  // NOTE(pag): The `id` is *NOT* a packed representation, is the underlying/
  //            raw fragment id.
  virtual std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, RawEntityId id) = 0;

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
                        std::vector<RawEntityId> &fragment_ids_out) = 0;

  // Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
  // to analyze when looking for references.
  virtual void FillReferences(const Ptr &, RawEntityId eid,
                              std::vector<RawEntityId> &redecl_ids_out,
                              std::vector<RawEntityId> &fragment_ids_out) = 0;

  // Find the entity ids matching the name
  virtual void FindSymbol(const Ptr &, std::string name,
                          mx::DeclCategory category,
                          std::vector<RawEntityId> &ids_out) = 0;

  virtual std::optional<mx::TokenKind>
  TokenKindOf(std::string_view spelling) = 0;

  virtual void LoadGrammarRoot(SyntexGrammarLeaves &root) = 0;

  virtual std::vector<RawEntityId> GetFragmentsInAST(void) = 0;
  virtual ASTNode GetASTNode(std::uint64_t id) = 0;
  virtual std::vector<std::uint64_t> GetASTNodeChildren(std::uint64_t id) = 0;
  virtual std::vector<std::uint64_t> GetASTNodesInFragment(RawEntityId frag) = 0;
  virtual std::optional<std::uint64_t> GetASTNodeWithKind(RawEntityId frag, unsigned short kind) = 0;
};

using VariantEntity = std::variant<NotAnEntity, Decl, Stmt, Type, Attr,
                                   Token, MacroSubstitution,
                                   Designator, Fragment, File>;

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

  static Index containing(const Fragment &fragment);
  static Index containing(const File &file);

  // Return the version number of the index. A version number of `0` is
  // invalid, a version number of `1` means we've connected to a fresh/empty
  // indexer with nothing indexed, a version number `2 * n` for `n >= 1` means
  // that indexing is underway, and a version number of `(2 * n) + 1` for
  // `n >= 1` means that indexing is done.
  unsigned version_number(bool block=false) const;

  // Clear any internal caches.
  void clear_caches(void) const;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathList file_paths(void) const;

  // Download a file by its unique ID.
  std::optional<File> file(FileId id) const;
  std::optional<File> file(RawEntityId id) const;

  // Download a fragment by its unique ID.
  std::optional<Fragment> fragment(FragmentId id) const;
  std::optional<Fragment> fragment(RawEntityId id) const;

  // Download a fragment based off of an entity ID.
  std::optional<Fragment> fragment_containing(EntityId) const;

  // Return an entity given its ID.
  VariantEntity entity(EntityId eid) const;

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

  // Run a Weggli search over the fragments in the index.
  //
  // NOTE(pag): This will only match inside of indexed code, i.e. fragments.
  WeggliQueryResult query_fragments(const WeggliQuery &query) const;

  // Run a regular expression search over the fragments in the index.
  //
  // NOTE(pag): This will only match inside of indexed code, i.e. fragments.
  RegexQueryResult query_fragments(const RegexQuery &query) const;

  // Search for entities by their name and category.
  NamedDeclList query_entities(std::string name,
                               mx::DeclCategory category) const;

  SyntexQuery parse_syntex_query(std::string_view query);
};

}  // namespace mx
