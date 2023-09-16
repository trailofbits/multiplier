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

  // NOTE(pag): These are not reset upon version updates. Entity data is
  //            read-only once written, and so these don't generally change.
#define DECLARE_ENTITY_CACHE(type_name, lower_name, ...) \
    std::unordered_map<RawEntityId, Weak ## type_name ## ImplPtr> \
        lower_name ## s;

  MX_FOR_EACH_ENTITY_CATEGORY(DECLARE_ENTITY_CACHE,
                              MX_IGNORE_ENTITY_CATEGORY,
                              DECLARE_ENTITY_CACHE,
                              DECLARE_ENTITY_CACHE,
                              DECLARE_ENTITY_CACHE,
                              DECLARE_ENTITY_CACHE,
                              DECLARE_ENTITY_CACHE)
#undef DECLARE_ENTITY_CACHE

  // Cached list of fragments inside of files.
  std::unordered_map<RawEntityId, FragmentIdList> file_fragments;

  // Caches reference kinds.
  std::unordered_map<RawEntityId, WeakReferenceKindImplPtr> reference_kinds;

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

  // Get the list of paths associated with a given file id.
  gap::generator<std::filesystem::path> ListPathsForFile(
      const Ptr &, PackedFileId id) final;

  // Get the list nested fragments for a given fragment.
  FragmentIdList ListNestedFragmentIds(const Ptr &, PackedFragmentId id) final;

  FragmentIdList ListFragmentsInFile(const Ptr &, PackedFileId id) final;

  // Return the list of fragments covering / overlapping some tokens in a file.
  FragmentIdList FragmentsCoveringTokens(
      const Ptr &, PackedFileId, std::vector<EntityOffset>) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, RawEntityId kind_id) final;

  ReferenceKindImplPtr
  ReferenceKindFor(const Ptr &, std::string_view kind_data) final;

  bool AddReference(const Ptr &ep, RawEntityId kind_id,
                    RawEntityId from_id, RawEntityId to_id,
                    RawEntityId context_id) final;

  gap::generator<RawEntityId> Redeclarations(const Ptr &, RawEntityId) & final;

  gap::generator<std::tuple<RawEntityId, RawEntityId, RawEntityId>>
  References(const Ptr &, RawEntityId eid) & final;

  gap::generator<RawEntityId> FindSymbol(const Ptr &, std::string name) & final;

#define MX_DECLARE_ENTITY_GETTER(type_name, lower_name, enum_name, category) \
    friend class type_name ## Impl; \
    \
    type_name ## ImplPtr type_name ## For( \
        const Ptr &ep, RawEntityId id) final; \
    \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &ep) & final;

MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER)
#undef MX_DECLARE_ENTITY_GETTER

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, type_name ## Kind) & final;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, type_name ## Kind, PackedFragmentId) & final;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
    gap::generator<type_name ## ImplPtr> type_name ## sFor( \
        const Ptr &, PackedFragmentId) & final;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS
};

}  // namespace mx
