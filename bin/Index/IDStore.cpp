// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IDStore.h"

#include <glog/logging.h>
#include <mutex>
#include <string>
#include <system_error>
#include <thread>
#include <unordered_map>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-redeclared-enum"
#include <rocksdb/cache.h>
#include <rocksdb/db.h>
#include <rocksdb/comparator.h>
#include <rocksdb/convenience.h>
#include <rocksdb/filter_policy.h>
#include <rocksdb/merge_operator.h>
#include <rocksdb/options.h>
#include <rocksdb/slice_transform.h>
#include <rocksdb/table.h>
#pragma clang diagnostic pop

#include "Endian.h"
#include "Util.h"

namespace indexer {
namespace {

// Used for temporary storage of values.
static thread_local std::string tValue;

static std::atomic_flag gSingleton = ATOMIC_FLAG_INIT;

enum : size_t {
  kNumKeyShards = 1024UL
};

// When doing `GetOrSet` we hash the key and grab a lock based on that hash.
static std::mutex gKeyShards[kNumKeyShards];

static std::unique_lock<std::mutex> KeyShardGuard(std::string_view key) {
  return std::unique_lock<std::mutex>(gKeyShards[Hash32(key) % kNumKeyShards]);
}

static mx::RawEntityId Canonicalize(mx::RawEntityId id) {
  if MX_CONSTEXPR_ENDIAN (MX_LITTLE_ENDIAN) {
    return __builtin_bswap64(id);
  }
  return id;
}

}  // namespace

IDStore::~IDStore(void) {
  LOG(INFO)
    << "Shutting down key-value engine";

  auto status = rocks_db->FlushWAL(true  /* sync */);
  LOG_IF(ERROR, !status.ok() && !status.IsNotSupported())
      << "Error flushing write-ahead log: " << status.ToString();

  rocksdb::FlushOptions options;
  options.wait = true;
  status = rocks_db->Flush(options, cf_handle);
  LOG_IF(ERROR, !status.ok())
      << "Error flushing key/value store: " << status.ToString();

  LOG(INFO)
      << "Canceling background RocksDB work";
  rocksdb::CancelAllBackgroundWork(rocks_db.get(), true  /* wait */);

  rocks_db->DestroyColumnFamilyHandle(cf_handle);

  status = rocks_db->Close();
  LOG_IF(ERROR, !status.ok())
      << "Error closing key/value store: " << status.ToString();
}

IDStore::IDStore(std::filesystem::path path) {
  
  // Only allow one instance; reduces logic needed to merge "connections"
  // based on directories.
  CHECK(!gSingleton.test_and_set())
      << "Can only have one instance of IDStore at a time.";

  std::error_code ec;

  if (path.empty()) {
    path = std::filesystem::current_path(ec);
    CHECK(!ec)
        << "Unable to determine the current working directory: "
        << ec.message();
  }

  auto abs_kvdir = std::filesystem::canonical(path, ec);
  CHECK(!ec)
      << "Specified directory '" << path.generic_string()
      << "' for key-value storage cannot be canonicalized: " << ec.message();

  if (!std::filesystem::is_directory(abs_kvdir)) {
    CHECK(std::filesystem::create_directory(abs_kvdir, ec))
        << "Unable to create directory '" << abs_kvdir.generic_string()
        << "' for key-value storage: " << ec.message();
  }

  std::filesystem::directory_iterator it(abs_kvdir, ec);
  CHECK(!ec)
      << "Specified directory '" << abs_kvdir.generic_string()
      << "' for key-value storage is not iterable: " << ec.message();

  // Make sure we can list the directory.
  for (auto entry : it) {
    CHECK(!ec)
        << "Specified directory '" << abs_kvdir.generic_string()
        << "' for key-value storage is not iterable: " << ec.message();
    break;
  }

  rocksdb::DBOptions options;
  options.create_if_missing = true;
  options.create_missing_column_families = true;
  options.IncreaseParallelism(static_cast<int>(
      std::thread::hardware_concurrency()));

  std::vector<rocksdb::ColumnFamilyDescriptor> cf_descs;
  rocksdb::ColumnFamilyOptions cf_options;
  cf_options.compression = rocksdb::kZSTD;
  cf_options.bottommost_compression = rocksdb::kZSTD;
  cf_options.compression_opts.enabled = true;
  cf_options.OptimizeForPointLookup(2048  /* MiB */);
  cf_descs.emplace_back(rocksdb::kDefaultColumnFamilyName, cf_options);

  std::vector<rocksdb::ColumnFamilyHandle *> cf_handles;
  rocksdb::DB *rocks_db_ptr = nullptr;
  auto status = rocksdb::DB::Open(options, abs_kvdir, cf_descs,
                                  &cf_handles, &rocks_db_ptr);
  CHECK(status.ok())
      << "Unable to open RocksDB database at " << abs_kvdir << ": "
      << status.ToString();

  CHECK_EQ(cf_handles.size(), 1);

  rocks_db.reset(rocks_db_ptr);
  cf_handle = cf_handles[0];
}

mx::RawEntityId IDStore::GetOrSet(std::string_view key, mx::RawEntityId id) {

  union alignas(mx::RawEntityId) {
    mx::RawEntityId as_id;
    char as_bytes[sizeof(mx::RawEntityId)];
  } id_marshal;

  static_assert(sizeof(id_marshal) == sizeof(id));

  id_marshal.as_id = Canonicalize(id);
  std::string_view value(id_marshal.as_bytes, sizeof(id));

  std::string &val = tValue;
  const rocksdb::ReadOptions read_options;
  const rocksdb::WriteOptions write_options;

  // Racy read, relying on RocksDB to implement the concurrency control.
  auto status = rocks_db->Get(read_options, cf_handle, key, &val);
  if (status.ok() && val.size() == sizeof(id)) {
    memcpy(id_marshal.as_bytes, val.data(), sizeof(id));
    return Canonicalize(id_marshal.as_id);
  }

  auto locker = KeyShardGuard(key);

  // Uncontended read, synchronized with concurrent `Put`s.
  status = rocks_db->Get(read_options, cf_handle, key, &val);
  if (status.ok() && val.size() == sizeof(id)) {
    memcpy(id_marshal.as_bytes, val.data(), sizeof(id));
    return Canonicalize(id_marshal.as_id);
  }

  id_marshal.as_id = Canonicalize(id);
  val.clear();
  val.insert(val.end(), id_marshal.as_bytes, &(id_marshal.as_bytes[sizeof(id)]));
  status = rocks_db->Put(write_options, key, val);
  CHECK(status.ok());

  return id;
}

}  // namespace indexer