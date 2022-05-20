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
 private:
  const Ptr next;

  std::recursive_mutex version_number_lock;
  unsigned version_number;

  FilePathList file_list;
  bool has_file_list{false};

  std::unordered_map<FragmentId, FragmentImpl::WeakPtr> fragments;
  std::unordered_map<FileId, FileImpl::WeakPtr> files;
  
  std::unordered_map<RawEntityId, std::shared_ptr<std::vector<RawEntityId>>>
      redeclarations;
  std::unordered_map<RawEntityId, std::shared_ptr<std::vector<FragmentId>>>
      uses;
  std::unordered_map<RawEntityId, std::shared_ptr<std::vector<FragmentId>>>
      references;

  void ClearCacheLocked(unsigned new_version_number);

 public:
  inline CachingEntityProvider(Ptr next_)
      : next(std::move(next_)),
        version_number(next->VersionNumber()) {}

  virtual ~CachingEntityProvider(void) noexcept;

  unsigned VersionNumber(void) final;

  void VersionNumberChanged(unsigned) final;

  FilePathList ListFiles(const Ptr &) final;

  std::shared_ptr<const FileImpl> FileFor(const Ptr &, FileId id) final;

  // Download a fragment by its unique ID.
  std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, FragmentId id) final;

  std::shared_ptr<WeggliQueryResultImpl>
  Query(const Ptr &, const WeggliQuery &) final;

  std::shared_ptr<RegexQueryResultImpl> Query(
      const Ptr &, const RegexQuery &) final;

  std::vector<RawEntityId> Redeclarations(const Ptr &, RawEntityId) final;

  void FillUses(const Ptr &, RawEntityId eid,
                std::vector<RawEntityId> &redecl_ids_out,
                std::vector<FragmentId> &fragment_ids_out) final;

  void FillReferences(const Ptr &, RawEntityId eid,
                      std::vector<RawEntityId> &redecl_ids_out,
                      std::vector<FragmentId> &fragment_ids_out) final;

  void CacheFileList(const FilePathList &, unsigned) final;
  void CacheRedeclarations(const std::vector<RawEntityId> &, unsigned) final;
  void CacheUses(
      const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
      unsigned) final;
  void CacheReferences(
      const std::vector<RawEntityId> &, const std::vector<FragmentId> &,
      unsigned) final;
};

}  // namespace mx
