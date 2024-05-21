// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <filesystem>
#include <memory>
#include <multiplier/Types.h>
#include <string>
#include <utility>

#include "Util.h"

namespace indexer {

template <typename T>
using MaybeNewId = std::pair<T, IdStatus>;

class IdStoreImpl;

// Persistent mapping from keys to values.
class IdStore {
 private:
  std::shared_ptr<IdStoreImpl> impl;

  IdStore(void) = delete;

  inline IdStore(std::shared_ptr<IdStoreImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  ~IdStore(void);

  explicit IdStore(std::filesystem::path workspace_dir);

  // Get, or create and return, a type ID for the specific fragment details.
  //
  // NOTE(pag): `context_id` is either a file token ID, identifying where this
  //            fragment is located, or it is the parent fragment id.
  MaybeNewId<mx::PackedFragmentId> GetOrCreateFragmentIdForHash(
      mx::RawEntityId context_id, std::string hash, size_t num_tokens,
      bool is_replaceable);

  // Get, or create and return, a type ID for the specific type details.
  MaybeNewId<mx::PackedTypeId> GetOrCreateTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers,
      std::string hash, size_t num_tokens);

  // Get, or create and return, a file ID for the specific file contents hash.
  MaybeNewId<mx::PackedFileId> GetOrCreateFileIdForHash(std::string hash);

  // Get, or create and return, a translation unit ID for the specific compile
  // command hash.
  MaybeNewId<mx::PackedCompilationId> GetOrCreateCompilationId(
      mx::RawEntityId file_id, std::string hash);
};

}  // namespace indexer
