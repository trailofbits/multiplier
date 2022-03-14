// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Result.h>
#include <multiplier/Types.h>

#include <filesystem>
#include <optional>
#include <string>

namespace indexer {

class StorageImpl;

struct StorageOptions {
  // Should we disable aynchronous insertions to the database? Where possible, we
  // enqueue stuff to be bulk-inserted into the database in a single transaction.
  bool disable_async_inserts{false};

  // Should we disable asynchronous mode, and instead synchronize the SQLite
  // engine with the underlying storage (typically the file system)?
  bool disable_async_writes{false};

  // Location where the database is stored.
  std::filesystem::path path;
};

//// A file to be stored in the storage.
//struct File final {
//  mx::FileId id;
//  std::string path;
//  hyde::rt::Bytes tokens;
//};

// Persistent storage for the backing relations.
class Storage final {
 private:
  std::shared_ptr<StorageImpl> impl;

 public:
  ~Storage(void);
  explicit Storage(const StorageOptions &options);

//  void StoreFile(mx::FileId id, std::filesystem::path path,
//                 kj::ArrayPtr<capnp::word> data);
};

}  // namespace indexer
