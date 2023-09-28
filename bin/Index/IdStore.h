// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <multiplier/Types.h>
#include <string>
#include <utility>

namespace rocksdb {
class ColumnFamilyHandle;
class DB;
}  // namespace rocksdb
namespace indexer {


template <typename T>
using MaybeNewId = std::pair<T, bool>;

// Persistent mapping from keys to values.
class IdStore {
 private:
  std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle *cf_handle;

  void InitNextIndices(void);
  void ExitNextIndices(void);

  // Set `val` to `key`.
  void UnlockedSet(const std::string &key, mx::RawEntityId val);

  // Core `GetOrSet` primitive used by higher-level APIs.
  MaybeNewId<mx::RawEntityId> GetOrSet(const std::string &key,
                                       mx::RawEntityId val);

  MaybeNewId<mx::PackedFragmentId> GetOrCreateSmallFragmentIdForHash(
      mx::RawEntityId tok_id, std::string hash, size_t num_tokens);

  MaybeNewId<mx::PackedFragmentId> GetOrCreateBigFragmentIdForHash(
      mx::RawEntityId tok_id, std::string hash, size_t num_tokens);

  MaybeNewId<mx::PackedTypeId> GetOrCreateSmallTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
      std::string hash);

  MaybeNewId<mx::PackedTypeId> GetOrCreateBigTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
      std::string hash);

 public:
  ~IdStore(void);
  IdStore(std::filesystem::path workspace_dir);

  // Get, or create and return, a file ID for the specific file contents hash.
  MaybeNewId<mx::PackedFileId> GetOrCreateFileIdForHash(std::string hash);

  MaybeNewId<mx::PackedFragmentId> GetOrCreateFragmentIdForHash(
      mx::RawEntityId tok_id, std::string hash, size_t num_tokens);

  MaybeNewId<mx::PackedTypeId> GetOrCreateTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers,
      std::string hash, size_t num_tokens);

  // Get, or create and return, a translation unit ID for the specific compile
  // command hash.
  MaybeNewId<mx::PackedCompilationId> GetOrCreateCompilationId(
      mx::RawEntityId file_id, std::string hash);
};

}  // namespace indexer
