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

unsigned CachingEntityProvider::VersionNumber(const Ptr &self) {
  return next->VersionNumber(self);
}

void CachingEntityProvider::ClearCacheLocked(unsigned new_version_number) {
  fragments.clear();
  files.clear();
  file_fragments.clear();
  file_list.clear();
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
  std::lock_guard<std::recursive_mutex> locker(lock);
  if (!has_file_list) {
    has_file_list = true;
    file_list = next->ListFiles(self);
  }
  return file_list;
}

// Get the current list of fragment IDs associated with a file.
FragmentIdList CachingEntityProvider::ListFragmentsInFile(
    const Ptr &self, SpecificEntityId<FileId> id) {
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

FileImpl::Ptr CachingEntityProvider::FileFor(
    const Ptr &self, SpecificEntityId<FileId> id) {
  
  RawEntityId raw_id = id.Pack();
  std::lock_guard<std::recursive_mutex> locker(lock);
  FileImpl::Ptr ptr;
  if (auto it = files.find(raw_id); it != files.end()) {
    ptr = it->second.lock();
  }

  // NOTE(pag): This may lead to `files` being wiped out due to a cache
  //            invalidation.
  if (!ptr) {
    ptr = next->FileFor(self, id);
    files[raw_id] = ptr;
  }

  // Extend liftime of `ptr`.
  entities.emplace_back(ptr, ptr.get());

  return ptr;
}

FragmentImpl::Ptr CachingEntityProvider::FragmentFor(
    const Ptr &self, SpecificEntityId<FragmentId> id) {
  
  RawEntityId raw_id = id.Pack();
  std::lock_guard<std::recursive_mutex> locker(lock);
  FragmentImpl::Ptr ptr;
  if (auto it = fragments.find(raw_id); it != fragments.end()) {
    ptr = it->second.lock();
  }

  // NOTE(pag): This may lead to `fragments` being wiped out due to a cache
  //            invalidation.
  if (!ptr) {
    ptr = next->FragmentFor(self, id);
    fragments[raw_id] = ptr;
  }

  // Extend the liftime of `ptr`.
  entities.emplace_back(ptr, ptr.get());
  
  return ptr;
}

// Return the list of fragments covering / overlapping some tokens in a file.
FragmentIdList CachingEntityProvider::FragmentsCoveringTokens(
    const Ptr &self, PackedFileId file_id, std::vector<EntityOffset> tokens) {
  return next->FragmentsCoveringTokens(self, file_id, std::move(tokens));
}

RawEntityIdList CachingEntityProvider::Redeclarations(
    const Ptr &self, SpecificEntityId<DeclarationId> eid) {

  auto raw_id = eid.Pack();

  std::shared_ptr<RawEntityIdList> redecls;
  do {
    std::lock_guard<std::recursive_mutex> locker(lock);
    auto redecl_it = redeclarations.find(raw_id);
    if (redecl_it != redeclarations.end()) {
      redecls = redecl_it->second;
    }
  } while (false);

  if (!redecls) {
    redecls = std::make_shared<RawEntityIdList>(
        next->Redeclarations(self, eid));

    std::lock_guard<std::recursive_mutex> locker(lock);
    redeclarations.emplace(raw_id, redecls);
  }

  return *redecls;
}

void CachingEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid,
    RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {

  if (!std::holds_alternative<DeclarationId>(EntityId(eid).Unpack())) {
    next->FillUses(self, eid, redecl_ids_out, fragment_ids_out);
    return;
  }

  std::shared_ptr<RawEntityIdList> redecls;
  do {
    std::lock_guard<std::recursive_mutex> locker(lock);
    auto redecl_it = redeclarations.find(eid);
    if (redecl_it != redeclarations.end()) {
      redecls = redecl_it->second;
    }
  } while (false);

  if (!redecls) {
    next->FillUses(self, eid, redecl_ids_out, fragment_ids_out);
    redecls = std::make_shared<RawEntityIdList>(redecl_ids_out);

    std::lock_guard<std::recursive_mutex> locker(lock);
    redeclarations.emplace(eid, std::move(redecls));

  } else {
    redecl_ids_out = *redecls;
    next->FillUses(self, eid, redecl_ids_out, fragment_ids_out);
  }
}

void CachingEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid,
    RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {

  if (!std::holds_alternative<DeclarationId>(EntityId(eid).Unpack())) {
    next->FillReferences(self, eid, redecl_ids_out, fragment_ids_out);
    return;
  }

  std::shared_ptr<RawEntityIdList> redecls;
  do {
    std::lock_guard<std::recursive_mutex> locker(lock);
    auto redecl_it = redeclarations.find(eid);
    if (redecl_it != redeclarations.end()) {
      redecls = redecl_it->second;
    }
  } while (false);

  if (!redecls) {
    next->FillReferences(self, eid, redecl_ids_out, fragment_ids_out);
    redecls = std::make_shared<RawEntityIdList>(redecl_ids_out);

    std::lock_guard<std::recursive_mutex> locker(lock);
    redeclarations.emplace(eid, std::move(redecls));

  } else {
    redecl_ids_out = *redecls;
    next->FillReferences(self, eid, redecl_ids_out, fragment_ids_out);
  }
}

void CachingEntityProvider::FindSymbol(
    const Ptr &self, std::string name, std::vector<RawEntityId> &ids_out) {
  return next->FindSymbol(self, std::move(name), ids_out);
}

gap::generator<EntityImplPtr> CachingEntityProvider::DeclsFor(
  const Ptr &self, PackedFragmentId id) { return next->DeclsFor(self, id); }
gap::generator<EntityImplPtr> CachingEntityProvider::TypesFor(
  const Ptr &self, PackedFragmentId id) { return next->TypesFor(self, id); }
gap::generator<EntityImplPtr> CachingEntityProvider::StmtsFor(
  const Ptr &self, PackedFragmentId id) { return next->StmtsFor(self, id); }
gap::generator<EntityImplPtr> CachingEntityProvider::AttrsFor(
  const Ptr &self, PackedFragmentId id) { return next->AttrsFor(self, id); }
gap::generator<EntityImplPtr> CachingEntityProvider::MacrosFor(
  const Ptr &self, PackedFragmentId id) { return next->MacrosFor(self, id); }
gap::generator<EntityImplPtr> CachingEntityProvider::PseudosFor(
  const Ptr &self, PackedFragmentId id) { return next->PseudosFor(self, id); }
std::optional<EntityImplPtr> CachingEntityProvider::DeclFor(
  const Ptr &self, PackedFragmentId id, unsigned offset) { return next->DeclFor(self, id, offset); }
std::optional<EntityImplPtr> CachingEntityProvider::TypeFor(
  const Ptr &self, PackedFragmentId id, unsigned offset) { return next->TypeFor(self, id, offset); }
std::optional<EntityImplPtr> CachingEntityProvider::StmtFor(
  const Ptr &self, PackedFragmentId id, unsigned offset) { return next->StmtFor(self, id, offset); }
std::optional<EntityImplPtr> CachingEntityProvider::AttrFor(
  const Ptr &self, PackedFragmentId id, unsigned offset) { return next->AttrFor(self, id, offset); }
std::optional<EntityImplPtr> CachingEntityProvider::MacroFor(
  const Ptr &self, PackedFragmentId id, unsigned offset) { return next->MacroFor(self, id, offset); }
std::optional<EntityImplPtr> CachingEntityProvider::PseudoFor(
  const Ptr &self, PackedFragmentId id, unsigned offset) { return next->PseudoFor(self, id, offset); }

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
          std::this_thread::sleep_for (1s * timeout_s);
        }
      },
      ret,
      timeout_s_);
  reclaimer_thread.detach();
  return ret;
}

}  // namespace mx
