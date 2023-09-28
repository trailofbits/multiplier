// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <filesystem>
#include <memory>
#include <string>

#include <multiplier/Types.h>

namespace rocksdb {
class ColumnFamilyHandle;
class DB;
}  // namespace rocksdb
namespace indexer {

// Persistent mapping from keys to values.
class IdStore {
 private:
  std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle *cf_handle;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  std::atomic<mx::RawEntityId> next_file_index;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  std::atomic<mx::RawEntityId> next_small_fragment_index;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  std::atomic<mx::RawEntityId> next_big_fragment_index;

  // The next type ID that can be assigned.
  std::atomic<mx::RawEntityId> next_small_type_index;
  std::atomic<mx::RawEntityId> next_big_type_index;

  // The next translation unit ID that can be assigned. This
  std::atomic<mx::RawEntityId> next_compilation_index;

  // Core `GetOrSet` primitive used by higher-level APIs.
  mx::RawEntityId GetOrSet(const std::string &key, mx::RawEntityId val);

  mx::PackedFragmentId GetOrCreateSmallFragmentIdForHash(
      mx::RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new);

  mx::PackedFragmentId GetOrCreateBigFragmentIdForHash(
      mx::RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new);

  mx::PackedTypeId GetOrCreateSmallTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
      std::string hash, bool &is_new);

  mx::PackedTypeId GetOrCreateBigTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
      std::string hash, bool &is_new);

 public:
  ~IdStore(void);
  IdStore(std::filesystem::path workspace_dir);

  // Get, or create and return, a file ID for the specific file contents hash.
  mx::PackedFileId GetOrCreateFileIdForHash(
      std::string hash, bool &is_new);

  mx::PackedFragmentId GetOrCreateFragmentIdForHash(
      mx::RawEntityId tok_id, std::string hash, size_t num_tokens,
      bool &is_new);

  mx::PackedTypeId GetOrCreateTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers,
      std::string hash, size_t num_tokens, bool &is_new);

  // Get, or create and return, a translation unit ID for the specific compile
  // command hash.
  mx::PackedCompilationId GetOrCreateCompilationId(
      mx::RawEntityId file_id, std::string hash, bool &is_new);
};

}  // namespace indexer
