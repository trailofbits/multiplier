// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Result.h>
#include <multiplier/Types.h>

#include <drlojekyll/Runtime/Runtime.h>
#include <optional>
#include <string>

namespace mx {

class StorageImpl;

// A file to be stored in the storage.
struct File final {
  FileId id;
  std::string path;
  hyde::rt::Bytes tokens;
};

// Persistent storage for the backing relations.
class Storage final {
 private:
  std::shared_ptr<StorageImpl> impl;

 public:
  ~Storage(void);
  Storage(void);

  void StoreFile(File file);

  // Reserve `num_ids_to_reserve` file ids, starting at or after
  // `prev_max_id`.
  Result<FileId, std::string> ReserveFileIds(
      FileId prev_max_id, uint32_t num_ids_to_reserve);
};

}  // namespace mx
