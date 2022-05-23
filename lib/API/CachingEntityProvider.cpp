// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CachingEntityProvider.h"

#include <cassert>
#include <chrono>
#include <thread>

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

void CachingEntityProvider::ClearCacheLocked(unsigned new_version_number) {
  fragments.clear();
  files.clear();
  file_list.clear();
  redeclarations.clear();
  uses.clear();
  references.clear();
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

FilePathList CachingEntityProvider::ListFiles(const Ptr &self) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  if (has_file_list) {
    return file_list;
  }

  return next->ListFiles(self);
}

FileImpl::Ptr CachingEntityProvider::FileFor(const Ptr &self, FileId id) {
  
  std::lock_guard<std::recursive_mutex> locker(lock);
  FileImpl::Ptr ptr;
  if (auto it = files.find(id); it != files.end()) {
    ptr = it->second.lock();
  }

  // NOTE(pag): This may lead to `files` being wiped out due to a cache
  //            invalidation.
  if (!ptr) {
    ptr = next->FileFor(self, id);
    files[id] = ptr;
  }

  // Extend liftime of `ptr`.
  entities.emplace_back(ptr, ptr.get());

  return ptr;
}

FragmentImpl::Ptr CachingEntityProvider::FragmentFor(
    const Ptr &self, FragmentId id) {
  
  std::lock_guard<std::recursive_mutex> locker(lock);
  FragmentImpl::Ptr ptr;
  if (auto it = fragments.find(id); it != fragments.end()) {
    ptr = it->second.lock();
  }

  // NOTE(pag): This may lead to `fragments` being wiped out due to a cache
  //            invalidation.
  if (!ptr) {
    ptr = next->FragmentFor(self, id);
    fragments[id] = ptr;
  }

  // Extend the liftime of `ptr`.
  entities.emplace_back(ptr, ptr.get());
  
  return ptr;
}

WeggliQueryResultImpl::Ptr CachingEntityProvider::Query(
    const Ptr &self, const WeggliQuery &query) {
  return next->Query(self, query);
}

RegexQueryResultImpl::Ptr CachingEntityProvider::Query(
    const Ptr &self, const RegexQuery &query) {
  return next->Query(self, query);
}

std::vector<RawEntityId> CachingEntityProvider::Redeclarations(
    const Ptr &self, RawEntityId eid) {

  std::lock_guard<std::recursive_mutex> locker(lock);
  if (auto it = redeclarations.find(eid); it != redeclarations.end()) {
    return *(it->second);
  } else {
    return next->Redeclarations(self, eid);
  }
}

void CachingEntityProvider::CacheFileList(
    const FilePathList &new_file_list, unsigned new_version_number) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  if (!has_file_list) {
    has_file_list = true;
    file_list = new_file_list;
  }

  next->CacheFileList(new_file_list, new_version_number);
}

void CachingEntityProvider::CacheRedeclarations(
    const std::vector<RawEntityId> &redecl_eids, unsigned new_version_number) {

  std::lock_guard<std::recursive_mutex> locker(lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  auto cached_redecl_eids =
      std::make_shared<std::vector<RawEntityId>>(redecl_eids);
  for (auto eid : redecl_eids) {
    (void) redeclarations.emplace(eid, cached_redecl_eids);
  }

  next->CacheRedeclarations(redecl_eids, new_version_number);
}

void CachingEntityProvider::CacheUses(
    const std::vector<RawEntityId> &redecl_eids,
    const std::vector<FragmentId> &use_fragment_ids,
    unsigned new_version_number) {

  std::lock_guard<std::recursive_mutex> locker(lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  auto cached_fragment_ids =
      std::make_shared<std::vector<FragmentId>>(use_fragment_ids);
  for (auto eid : redecl_eids) {
    (void) uses.emplace(eid, cached_fragment_ids);
  }

  next->CacheUses(redecl_eids, use_fragment_ids, new_version_number);
}

void CachingEntityProvider::CacheReferences(
    const std::vector<RawEntityId> &redecl_eids,
    const std::vector<FragmentId> &ref_fragment_ids,
    unsigned new_version_number) {

  std::lock_guard<std::recursive_mutex> locker(lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  auto cached_fragment_ids =
      std::make_shared<std::vector<FragmentId>>(ref_fragment_ids);
  for (auto eid : redecl_eids) {
    (void) references.emplace(eid, cached_fragment_ids);
  }

  next->CacheReferences(redecl_eids, ref_fragment_ids, new_version_number);
}

void CachingEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  
  std::lock_guard<std::recursive_mutex> locker(lock);
  if (auto redecl_it = redeclarations.find(eid);
      redecl_it != redeclarations.end()) {
    if (auto uses_it = uses.find(eid); uses_it != uses.end()) {
      redecl_ids_out = *(redecl_it->second);
      fragment_ids_out = *(uses_it->second);
      return;
    }
  }

  next->FillUses(self, eid, redecl_ids_out, fragment_ids_out);
}

void CachingEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {

  std::lock_guard<std::recursive_mutex> locker(lock);
  if (auto redecl_it = redeclarations.find(eid);
      redecl_it != redeclarations.end()) {
    if (auto refs_it = references.find(eid); refs_it != uses.end()) {
      redecl_ids_out = *(redecl_it->second);
      fragment_ids_out = *(refs_it->second);
      return;
    }
  }

  next->FillReferences(self, eid, redecl_ids_out, fragment_ids_out);
}

// Returns an entity provider that gets entities from a UNIX domain socket.
EntityProvider::Ptr EntityProvider::in_memory_cache(Ptr next) {
  auto ret = std::make_shared<CachingEntityProvider>(std::move(next));

  // Run a reclaimer thread that will extend the lifetimes of entities in
  // the cache.
  std::thread reclaimer_thread(
      [] (std::weak_ptr<CachingEntityProvider> weak_self) {
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
          std::this_thread::sleep_for(1000ms);
        }
      },
      ret);
  reclaimer_thread.detach();
  return ret;
}

}  // namespace mx
