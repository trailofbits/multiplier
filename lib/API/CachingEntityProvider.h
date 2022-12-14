// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Fragment.h"
#include "File.h"
#include "Re2.h"
#include "Weggli.h"

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
  FilePathList file_list;
  bool has_file_list{false};

  // Cached entities. `entities` explicitly introduces a strong, non-reclaimable
  // reference cycle. However, we have a reclaimer thread behind the scenes
  // that periodically steals `entities`, thus extending the lifetimes of
  // things caches in `fragments` and `files`, and also breaking the reference
  // cycles.
  std::vector<std::shared_ptr<const void>> entities;

  std::unordered_map<RawEntityId, FragmentImpl::WeakPtr> fragments;
  std::unordered_map<RawEntityId, FileImpl::WeakPtr> files;

  // Cached list of fragments inside of files.
  std::unordered_map<RawEntityId, std::vector<EntityId>> file_fragments;

  // Cached redeclarations/references/uses.
  std::unordered_map<RawEntityId, std::shared_ptr<std::vector<RawEntityId>>>
      redeclarations;
  std::unordered_map<RawEntityId, std::shared_ptr<std::vector<RawEntityId>>>
      uses;
  std::unordered_map<RawEntityId, std::shared_ptr<std::vector<RawEntityId>>>
      references;

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

  FilePathList ListFiles(const Ptr &) final;

  std::vector<EntityId> ListFragmentsInFile(const Ptr &, RawEntityId id) final;

  std::shared_ptr<const FileImpl> FileFor(const Ptr &, RawEntityId id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, RawEntityId id) final;

  gap::generator<WeggliQueryMatch>
  Query(const Ptr &, const WeggliQuery &) final;

  gap::generator<RegexQueryMatch> Query(
      const Ptr &, const RegexQuery &) final;

  std::vector<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  void FillUses(const Ptr &, RawEntityId eid,
                std::vector<RawEntityId> &redecl_ids_out,
                std::vector<RawEntityId> &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      std::vector<RawEntityId> &redecl_ids_out,
                      std::vector<RawEntityId> &fragment_ids_out) final;

  void FindSymbol(const Ptr &, std::string name,
                  mx::DeclCategory category,
                  std::vector<RawEntityId> &ids_out) final;

};

}  // namespace mx
