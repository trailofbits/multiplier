// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <multiplier/AST.capnp.h>
#include <multiplier/Index.h>
#include <multiplier/RPC.capnp.h>
#include <optional>
#include <string>

#include "Entity.h"

namespace mx {

class Decl;

using EntityIdListReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;

// Provides the APIs with entities.
class EntityProvider {
 public:
  using Ptr = EntityProviderPtr;

  virtual ~EntityProvider(void) noexcept;

  // Create an in-memory caching entity provider.
  static Ptr CreateInMemoryCache(Ptr next, unsigned timeout_s=1u);

  static Ptr CreateFromDatabase(std::filesystem::path path);

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
  friend class ReferenceKind;
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

  // Get the list of paths associated with a given file id.
  virtual gap::generator<std::filesystem::path> ListPathsForFile(
      const Ptr &, PackedFileId id) = 0;

  // Download a list of fragment IDs contained in a specific file.
  virtual FragmentIdList ListFragmentsInFile(const Ptr &, PackedFileId id) = 0;

  virtual ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, RawEntityId kind_id) = 0;

  virtual ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, std::string_view kind_data) = 0;

  virtual bool AddReference(const Ptr &ep, RawEntityId kind_id,
                            RawEntityId from_id, RawEntityId to_id) = 0;

  // Get a token by its entity ID.
  Token TokenFor(const Ptr &, RawEntityId id);

  // Get a token by its entity ID, and given the presence of an existing reader
  // that can be used as a hint for being the current reader for the token.
  Token TokenFor(const Ptr &, const std::shared_ptr<const TokenReader> &,
                 RawEntityId id);

#define MX_DECLARE_ENTITY_GETTER(type_name, lower_name, enum_name, category) \
    friend class type_name ## Impl; \
    \
    virtual type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, RawEntityId id) = 0; \
    \
    inline type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, Packed ## type_name ## Id id) { \
      return ep->type_name ## For(ep, id.Pack()); \
    } \
    virtual gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &ep) & = 0;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_GETTER,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_DECLARE_ENTITY_GETTER,
                              MX_DECLARE_ENTITY_GETTER)
#undef MX_DECLARE_ENTITY_GETTER

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
    virtual gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, type_name ## Kind kind) & = 0; \
    \
    virtual gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, type_name ## Kind kind, PackedFragmentId id) & = 0;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_LISTERS,
                              MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
    virtual gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, PackedFragmentId id) & = 0;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_LISTERS,
                              MX_DECLARE_ENTITY_LISTERS)
#undef MX_DECLARE_ENTITY_LISTERS

  // Return the list of fragments covering / overlapping some tokens in a file.
  virtual FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset> tokens) = 0;

  // Return the redeclarations of a given declaration.
  virtual gap::generator<RawEntityId> Redeclarations(
      const Ptr &, RawEntityId eid) & = 0;

  // Fill out `redecl_ids_out` and `references_ids_out` with the set of things
  // to analyze when looking for references.
  virtual gap::generator<std::pair<RawEntityId, RawEntityId>>
  References(const Ptr &, RawEntityId eid) & = 0;

  // Find the entity ids matching the name
  virtual gap::generator<RawEntityId> FindSymbol(
      const Ptr &, std::string name) & = 0;
};

}  // namespace mx
