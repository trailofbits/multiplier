// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CachingEntityProvider.h"
#include <iostream>
namespace mx {

CachingEntityProvider::~CachingEntityProvider(void) noexcept {}

unsigned CachingEntityProvider::VersionNumber(void) {
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
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
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }
}

FilePathList CachingEntityProvider::ListFiles(const Ptr &self) {
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  if (has_file_list) {
    return file_list;
  }

  return next->ListFiles(self);
}

void CachingEntityProvider::CacheFileList(
    const FilePathList &new_file_list, unsigned new_version_number) {
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  if (!has_file_list) {
    has_file_list = true;
    file_list = new_file_list;
  }
}

FileImpl::Ptr CachingEntityProvider::FileFor(const Ptr &self, FileId id) {
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  auto &weak_ptr = files[id];
  if (auto ptr = weak_ptr.lock()) {
    return ptr;
  } else {
    ptr = next->FileFor(self, id);
    weak_ptr = ptr;
    return ptr;
  }
}

FragmentImpl::Ptr CachingEntityProvider::FragmentFor(
    const Ptr &self, FragmentId id) {
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  // auto contains = fragments.count(id);
  auto &weak_ptr = fragments[id];
  if (auto ptr = weak_ptr.lock()) {
    return ptr;
  } else {
    // std::cerr << "Missed on fragment " << id << " contains=" << contains << '\n';
    ptr = next->FragmentFor(self, id);
    weak_ptr = ptr;
    return ptr;
  }
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

  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  if (auto it = redeclarations.find(eid); it != redeclarations.end()) {
    return *(it->second);
  } else {
    return next->Redeclarations(self, eid);
  }
}

void CachingEntityProvider::CacheRedeclarations(
    const std::vector<RawEntityId> &redecl_eids, unsigned new_version_number) {

  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  auto cached_redecl_eids =
      std::make_shared<std::vector<RawEntityId>>(redecl_eids);
  for (auto eid : redecl_eids) {
    (void) redeclarations.emplace(eid, cached_redecl_eids);
  }
}

void CachingEntityProvider::CacheUses(
    const std::vector<RawEntityId> &redecl_eids,
    const std::vector<FragmentId> &use_fragment_ids,
    unsigned new_version_number) {

  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  auto cached_fragment_ids =
      std::make_shared<std::vector<FragmentId>>(use_fragment_ids);
  for (auto eid : redecl_eids) {
    (void) uses.emplace(eid, cached_fragment_ids);
  }
}

void CachingEntityProvider::CacheReferences(
    const std::vector<RawEntityId> &redecl_eids,
    const std::vector<FragmentId> &ref_fragment_ids,
    unsigned new_version_number) {

  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
  if (new_version_number > version_number) {
    ClearCacheLocked(new_version_number);
  }

  auto cached_fragment_ids =
      std::make_shared<std::vector<FragmentId>>(ref_fragment_ids);
  for (auto eid : redecl_eids) {
    (void) references.emplace(eid, cached_fragment_ids);
  }
}

void CachingEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid,
    std::vector<RawEntityId> &redecl_ids_out,
    std::vector<FragmentId> &fragment_ids_out) {
  
  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
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

  std::lock_guard<std::recursive_mutex> locker(version_number_lock);
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
  return std::make_shared<CachingEntityProvider>(std::move(next));
}

}  // namespace mx
