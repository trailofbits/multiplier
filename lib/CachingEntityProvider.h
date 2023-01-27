// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Fragment.h"
#include "File.h"

#include <mutex>
#include <unordered_map>

namespace mx {

class CachingEntityProvider final : public EntityProvider {
 public:
  // The next entity provider that we will invoke.
  const Ptr next;

  // Lock over the version number and all cached things.
  std::recursive_mutex lock;
  unsigned version_number;

  // Cache file list.
  FilePathMap file_list;
  bool has_file_list{false};

  // Cached entities. `entities` explicitly introduces a strong, non-reclaimable
  // reference cycle. However, we have a reclaimer thread behind the scenes
  // that periodically steals `entities`, thus extending the lifetimes of
  // things caches in `fragments` and `files`, and also breaking the reference
  // cycles.
  std::vector<std::shared_ptr<const void>> entities;

  EntityImplPtr x;
  std::unordered_map<RawEntityId, FragmentImpl::WeakPtr> fragments;
  std::unordered_map<RawEntityId, FileImpl::WeakPtr> files;

#define DECLARE_ENTITY_CACHE(name, lower_name) \
    std::unordered_map<RawEntityId, WeakEntityImplPtr> lower_name ## s;

  MX_FOR_EACH_ENTITY_RECORD(DECLARE_ENTITY_CACHE)
#undef DECLARE_ENTITY_CACHE


  // Cached list of fragments inside of files.
  std::unordered_map<RawEntityId, FragmentIdList> file_fragments;

  // Cached redeclarations.
  std::unordered_map<RawEntityId, std::shared_ptr<RawEntityIdList>>
      redeclarations;

  void ClearCacheLocked(unsigned new_version_number);

  inline CachingEntityProvider(Ptr next_)
      : next(std::move(next_)),
        version_number(next->VersionNumber()) {}

  virtual ~CachingEntityProvider(void) noexcept;

  // Clear any caches.
  void ClearCache(void) final;

  unsigned VersionNumber(void) final;
  unsigned VersionNumber(const Ptr &) final;

  void VersionNumberChanged(unsigned) final;

  FilePathMap ListFiles(const Ptr &) final;

  FragmentIdList ListFragmentsInFile(
      const Ptr &, SpecificEntityId<FileId> id) final;

  std::shared_ptr<const FileImpl> FileFor(
      const Ptr &, SpecificEntityId<FileId> id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, SpecificEntityId<FragmentId> id) final;

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset>) final;

  RawEntityIdList Redeclarations(
      const Ptr &, SpecificEntityId<DeclarationId>) final;

  void FillUses(const Ptr &, RawEntityId eid,
                RawEntityIdList &redecl_ids_out,
                FragmentIdList &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      RawEntityIdList &redecl_ids_out,
                      FragmentIdList &fragment_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  std::vector<RawEntityId> &ids_out) final;

#define DECLARE_ENTITY_METHODS(name, lower_name) \
    gap::generator<EntityImplPtr> \
    name ## sFor(const Ptr &, PackedFragmentId id) final; \
    std::optional<EntityImplPtr> \
    name ## For(const Ptr &, PackedFragmentId id, EntityOffset offset) final; \
    std::optional<EntityImplPtr> \
    name ## For(const Ptr &ep, RawEntityId id) final;

  MX_FOR_EACH_ENTITY_RECORD(DECLARE_ENTITY_METHODS)
#undef DECLARE_ENTITY_METHODS
};

}  // namespace mx
