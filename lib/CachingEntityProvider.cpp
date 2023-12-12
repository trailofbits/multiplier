// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CachingEntityProvider.h"

#include <cassert>
#include <chrono>
#include <thread>

#include "Types.h"

namespace mx {

CachingEntityProvider::~CachingEntityProvider(void) noexcept {}

// Clear any caches.
void CachingEntityProvider::ClearCache(void) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  ClearCacheLocked(version_number);
  next->ClearCache();
}

unsigned CachingEntityProvider::VersionNumber(void) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  return version_number;
}

unsigned CachingEntityProvider::VersionNumber(const Ptr &self) {
  return next->VersionNumber(self);
}

void CachingEntityProvider::ClearCacheLocked(unsigned new_version_number) {

  // More file may have been added, or or fragments might have been added to
  // specific files.
  file_fragments.clear();
  file_list.clear();

  // The set of redeclarations might have grown.
  redeclarations.clear();

  has_file_list = false;
  version_number = new_version_number;

  next->VersionNumberChanged(new_version_number);
}

void CachingEntityProvider::VersionNumberChanged(unsigned new_version_number) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }
}

FilePathMap CachingEntityProvider::ListFiles(const Ptr &self) {
  do {
    std::lock_guard<std::recursive_mutex> locker(lock);
    if (!has_file_list) {
      has_file_list = true;
      file_list = next->ListFiles(self);
    }
  } while (false);
  return file_list;
}

// Get the list of paths associated with a given file id.
gap::generator<std::filesystem::path> CachingEntityProvider::ListPathsForFile(
    const Ptr &self, PackedFileId id) {
  return next->ListPathsForFile(self, id);
}

// Get the list nested fragments for a given fragment.
FragmentIdList CachingEntityProvider::ListNestedFragmentIds(
    const Ptr &self, PackedFragmentId id) {
  return next->ListNestedFragmentIds(self, id);
}

// Get the current list of fragment IDs associated with a file.
//
// TODO(pag): Re-evaluate if caching this is beneficial/useful.
FragmentIdList CachingEntityProvider::ListFragmentsInFile(
    const Ptr &self, PackedFileId id) {
  RawEntityId raw_id = id.Pack();
  std::lock_guard<std::recursive_mutex> locker(lock);
  if (auto it = file_fragments.find(raw_id); it != file_fragments.end()) {
    return it->second;
  } else {
    auto fragment_ids = next->ListFragmentsInFile(self, id);
    file_fragments.emplace(raw_id, fragment_ids);  // Cache it.
    return fragment_ids;
  }
}

// Return the list of fragments covering / overlapping some tokens in a file.
FragmentIdList CachingEntityProvider::FragmentsCoveringTokens(
    const Ptr &self, PackedFileId file_id, std::vector<EntityOffset> tokens) {
  return next->FragmentsCoveringTokens(self, file_id, std::move(tokens));
}

ReferenceKindImplPtr
CachingEntityProvider::ReferenceKindFor(const Ptr &self, RawEntityId kind_id) {
  ReferenceKindImplPtr ret;
  do {
    std::lock_guard<std::recursive_mutex> locker(lock);
    if (auto it = reference_kinds.find(kind_id); it != reference_kinds.end()) {
      ret = it->second.lock();
    }
  } while (false);

  if (ret) {
    return ret;
  }

  ret = next->ReferenceKindFor(self, kind_id);
  if (!ret) {
    assert(false);
    return {};
  }

  std::lock_guard<std::recursive_mutex> locker(lock);
  reference_kinds[kind_id] = ret;
  return ret;
}

ReferenceKindImplPtr
CachingEntityProvider::ReferenceKindFor(const Ptr &self,
                                        std::string_view kind_data) {
  return next->ReferenceKindFor(self, kind_data);
}

bool CachingEntityProvider::AddReference(const Ptr &ep, RawEntityId kind_id,
                                         RawEntityId from_id,
                                         RawEntityId to_id,
                                         RawEntityId context_id) {
  return next->AddReference(ep, kind_id, from_id, to_id, context_id);
}

gap::generator<RawEntityId> CachingEntityProvider::Redeclarations(
    const Ptr &self, RawEntityId raw_id) & {

  EntityCategory category = CategoryFromEntityId(raw_id);
  if (EntityCategory::NOT_AN_ENTITY == category) {
    assert(false);
    co_return;
  }

  std::shared_ptr<RawEntityIdList> redecls;
  do {
    std::lock_guard<std::recursive_mutex> locker(lock);
    auto redecl_it = redeclarations.find(raw_id);
    if (redecl_it != redeclarations.end()) {
      redecls = redecl_it->second;
    }
  } while (false);

  if (!redecls) {
    redecls = std::make_shared<RawEntityIdList>();
    for (RawEntityId raw_redecl_id : next->Redeclarations(self, raw_id)) {
      assert(CategoryFromEntityId(raw_redecl_id) == category);
      redecls->push_back(raw_redecl_id);
    }

    std::lock_guard<std::recursive_mutex> locker(lock);
    redeclarations.emplace(raw_id, redecls);
  }

  auto seen_raw_id = false;
  for (RawEntityId redecl_id : *redecls) {
    if (!seen_raw_id) {
      seen_raw_id = redecl_id == raw_id;
    }

    co_yield redecl_id;
  }

  if (!seen_raw_id) {
    co_yield raw_id;
  }
}

gap::generator<std::tuple<RawEntityId, RawEntityId, RawEntityId>>
CachingEntityProvider::References(
    const Ptr &self, RawEntityId eid,
    EntityProvider::ReferenceDirection direction) & {
  return next->References(self, eid, direction);
}

gap::generator<RawEntityId> CachingEntityProvider::FindSymbol(
    const Ptr &self, std::string name) & {
  return next->FindSymbol(self, std::move(name));
}

// Returns an entity provider that gets entities from a UNIX domain socket.
EntityProviderPtr EntityProvider::CreateInMemoryCache(
    Ptr next, unsigned timeout_s_) {
  auto ret = std::make_shared<CachingEntityProvider>(std::move(next));

  // Run a reclaimer thread that will extend the lifetimes of entities in
  // the cache.
  std::thread reclaimer_thread(
      [] (std::weak_ptr<CachingEntityProvider> weak_self, unsigned timeout_s) {
        std::vector<std::shared_ptr<const void>> next_entities;
        while (true) {
          
          // Clear out the prior set of entities. This might be the last thing
          // keeping the entitiy provider alive if we're "just past the end"
          // of the program.
          next_entities.clear();

          do {
            // Get a strong pointer to the entity provider. If it's being used
            // then it's also keeping itself alive with reference cycles in
            // `entities`, which we need to steal.
            auto self = weak_self.lock();
            if (!self) {
              return;
            }

            // Steal the next set of entities to cache from the entity
            // provider.
            std::lock_guard<std::recursive_mutex> locker(self->lock);
            next_entities.swap(self->entities);
          } while (false);

          using namespace std::chrono_literals;
          std::this_thread::sleep_for (1s * timeout_s);
        }
      },
      ret,
      timeout_s_);
  reclaimer_thread.detach();
  return ret;
}

#define MX_DECLARE_ENTITY_GETTER(ns_path, type_name, lower_name, enum_name, category) \
    type_name ## ImplPtr CachingEntityProvider::type_name ## For( \
        const Ptr &self, RawEntityId raw_id) { \
      if (raw_id == kInvalidEntityId) { \
        return {}; \
      } \
      do { \
        std::lock_guard<std::recursive_mutex> locker(lock); \
        if (auto it = lower_name ## s.find(raw_id); \
            it != lower_name ## s.end()) { \
          if (type_name ## ImplPtr ptr = it->second.lock()) { \
            entities.emplace_back(ptr, ptr.get()); \
            return ptr; \
          } \
        } \
      } while (false); \
      \
      type_name ## ImplPtr ptr = next->type_name ## For(self, raw_id); \
      if (!ptr) { \
        return ptr; \
      } \
      \
      std::lock_guard<std::recursive_mutex> locker(lock); \
      lower_name ## s[raw_id] = ptr; \
      entities.emplace_back(ptr, ptr.get()); \
      \
      return ptr; \
    } \
    \
    gap::generator<type_name ## ImplPtr> CachingEntityProvider::type_name ## sFor( \
        const Ptr &self) & { \
      return next->type_name ## sFor(self); \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_GETTER

#define MX_DECLARE_ENTITY_LISTERS(ns_path, type_name, lower_name, enum_name, category) \
  gap::generator<type_name ## ImplPtr> CachingEntityProvider::type_name ## sFor( \
      const Ptr &self, type_name ## Kind kind) & { \
    return next->type_name ## sFor(self, kind); \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS

}  // namespace mx
