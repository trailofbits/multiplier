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
  file_fragments.clear();
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
  if (!has_file_list) {
    has_file_list = true;
    file_list = next->ListFiles(self);
  }
  return file_list;
}

// Get the current list of fragment IDs associated with a file.
std::vector<FragmentId> CachingEntityProvider::ListFragmentsInFile(
    const Ptr &self, FileId id) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  if (auto it = file_fragments.find(id); it != file_fragments.end()) {
    return it->second;
  } else {
    auto fragment_ids = next->ListFragmentsInFile(self, id);
    file_fragments.emplace(id, fragment_ids);  // Cache it.
    return fragment_ids;
  }
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
  }

  auto redecl_ids_out = next->Redeclarations(self, eid);
  auto cached_redecl_eids =
      std::make_shared<std::vector<RawEntityId>>(redecl_ids_out);
  for (auto eid : redecl_ids_out) {
    redeclarations[eid] = cached_redecl_eids;
  }
  return redecl_ids_out;
}

void CachingEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  
  std::lock_guard<std::recursive_mutex> locker(lock);
  auto redecl_it = redeclarations.find(eid);
  if (redecl_it != redeclarations.end()) {
    if (auto uses_it = uses.find(eid); uses_it != uses.end()) {
      redecl_ids_out = *(redecl_it->second);
      fragment_ids_out = *(uses_it->second);
      return;
    }
  }

  next->FillUses(self, eid, redecl_ids_out, fragment_ids_out);

  // Double check and overwrite the redeclarations.
  redecl_it = redeclarations.find(eid);
  if (redecl_it == redeclarations.end()) {
    auto cached_redecl_eids =
        std::make_shared<std::vector<RawEntityId>>(redecl_ids_out);
    for (auto eid : redecl_ids_out) {
      redeclarations[eid] = cached_redecl_eids;
    }
  }

  // Cache the used fragments.
  auto cached_fragment_ids =
      std::make_shared<std::vector<FragmentId>>(fragment_ids_out);
  for (auto eid : redecl_ids_out) {
    uses[eid] = cached_fragment_ids;
  }
}

void CachingEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {

  std::lock_guard<std::recursive_mutex> locker(lock);
  auto redecl_it = redeclarations.find(eid);
  if (redecl_it != redeclarations.end()) {
    if (auto refs_it = references.find(eid); refs_it != uses.end()) {
      redecl_ids_out = *(redecl_it->second);
      fragment_ids_out = *(refs_it->second);
      return;
    }
  }

  next->FillReferences(self, eid, redecl_ids_out, fragment_ids_out);

  // Double check and overwrite the redeclarations.
  redecl_it = redeclarations.find(eid);
  if (redecl_it == redeclarations.end()) {
    auto cached_redecl_eids =
        std::make_shared<std::vector<RawEntityId>>(redecl_ids_out);
    for (auto eid : redecl_ids_out) {
      redeclarations[eid] = cached_redecl_eids;
    }
  }

  // Cache the referenced fragments.
  auto cached_fragment_ids =
      std::make_shared<std::vector<FragmentId>>(fragment_ids_out);
  for (auto eid : redecl_ids_out) {
    references[eid] = cached_fragment_ids;
  }
}

// Returns an entity provider that gets entities from a UNIX domain socket.
EntityProvider::Ptr EntityProvider::in_memory_cache(
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
          std::this_thread::sleep_for(1s * timeout_s);
        }
      },
      ret,
      timeout_s_);
  reclaimer_thread.detach();
  return ret;
}

}  // namespace mx
