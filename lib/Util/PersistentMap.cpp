// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/PersistentMap.h>

#include <glog/logging.h>
#include <mutex>
#include <system_error>
#include <thread>
#include <unordered_map>

#ifndef __cpp_lib_string_view
# define __cpp_lib_string_view
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wgnu-redeclared-enum"
#include <rocksdb/cache.h>
#include <rocksdb/db.h>
#include <rocksdb/comparator.h>
#include <rocksdb/convenience.h>
#include <rocksdb/filter_policy.h>
#include <rocksdb/merge_operator.h>
#include <rocksdb/options.h>
#include <rocksdb/slice_transform.h>
#include <rocksdb/table.h>
#pragma GCC diagnostic pop

namespace mx {
namespace {

enum : size_t {
  kNumKeyShards = 1024UL
};

// When doing `Set`, `GetOrSet` or `UpdateOrSet`, we hash the key and grab a
// lock based on that hash.
//
// NOTE(pag): We need a recursive mutex because we might be holding a lock while
//            trying to update another value that hashes to the same lock shard.
static std::recursive_mutex gKeyShards[kNumKeyShards];

// Hash keys to index into `gKeyShards`.
static const std::hash<std::string_view> kKeyHasher;

static std::recursive_mutex &KeyShardGuard(std::string_view key) {
  return gKeyShards[kKeyHasher(key) % kNumKeyShards];
}

class PersistentMapImpl {
 public:
  const std::string path;
  std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle *cf_handle{nullptr};

  ~PersistentMapImpl(void);
  PersistentMapImpl(std::string path_);

  // Maps paths to instances of this class.
  static std::unordered_map<std::string, std::weak_ptr<PersistentMapImpl>>
      gImpls;

  // Lock on above.
  static std::mutex gImplsLock;

  // Get or create instances of this class.
  static std::shared_ptr<rocksdb::DB> Get(std::filesystem::path path);
};

std::unordered_map<std::string, std::weak_ptr<PersistentMapImpl>>
PersistentMapImpl::gImpls;
std::mutex PersistentMapImpl::gImplsLock;

PersistentMapImpl::~PersistentMapImpl(void) {
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

PersistentMapImpl::PersistentMapImpl(std::string path_)
    : path(path_) {
  rocksdb::DBOptions options;
  options.create_if_missing = true;
  options.create_missing_column_families = true;
  options.IncreaseParallelism(static_cast<int>(
      std::thread::hardware_concurrency()));

  std::vector<rocksdb::ColumnFamilyDescriptor> cf_descs;
  rocksdb::ColumnFamilyOptions cf_options;
//  cf_options.compression = rocksdb::kZlibCompression;
//  cf_options.bottommost_compression = rocksdb::kZlibCompression;
//  cf_options.compression_opts.enabled = true;
  cf_descs.emplace_back(rocksdb::kDefaultColumnFamilyName, cf_options);

  std::vector<rocksdb::ColumnFamilyHandle *> cf_handles;
  rocksdb::DB *rocks_db_ptr = nullptr;
  auto status = rocksdb::DB::Open(options, path, cf_descs,
                                  &cf_handles, &rocks_db_ptr);
  CHECK(status.ok())
      << "Unable to open RocksDB database at " << path << ": "
      << status.ToString();

  CHECK_EQ(cf_handles.size(), 1);

  rocks_db.reset(rocks_db_ptr);
  cf_handle = cf_handles[0];
}

std::shared_ptr<rocksdb::DB> PersistentMapImpl::Get(
    std::filesystem::path path) {

  std::error_code ec;

  if (path.empty()) {
    path = std::filesystem::current_path(ec);
    CHECK(!ec)
        << "Unable to determine the current working directory: "
        << ec.message();
  }

  if (!std::filesystem::is_directory(path)) {
    CHECK(std::filesystem::create_directory(path, ec))
        << "Unable to create directory '" << path.generic_string()
        << "' for key-value storage: " << ec.message();
  }

  std::filesystem::directory_iterator it(path, ec);
  CHECK(!ec)
      << "Specified directory '" << path.generic_string()
      << "' for key-value storage is not iterable: " << ec.message();

  // Make sure we can list the directory.
  for (auto entry : it) {
    CHECK(!ec)
        << "Specified directory '" << path.generic_string()
        << "' for key-value storage is not iterable: " << ec.message();
    break;
  }

  auto kv_dir = path / "kv";
  if (!std::filesystem::is_directory(kv_dir)) {
    CHECK(std::filesystem::create_directory(kv_dir, ec))
        << "Unable to create directory '" << kv_dir.string()
        << "' for key-value storage: " << ec.message();
  }

  auto abs_kvdir = std::filesystem::canonical(kv_dir, ec);
  CHECK(!ec)
      << "Specified directory '" << kv_dir.generic_string()
      << "' for key-value storage cannot be canonicalized: " << ec.message();

  auto impl_key = abs_kvdir.generic_string();

  std::unique_lock<std::mutex> locker(gImplsLock);
  auto &impl = gImpls[impl_key];
  auto ret = impl.lock();
  if (!ret) {
    ret = std::make_shared<PersistentMapImpl>(std::move(impl_key));
    impl = ret;
  }

  // Alias the RocksDB database pointer to the ref counter of the
  // `PersistentMapImpl`.
  return std::shared_ptr<rocksdb::DB>(std::move(ret), ret->rocks_db.get());
}

}  // namespace

PersistentMapBase::~PersistentMapBase(void) {}

PersistentMapBase::PersistentMapBase(std::filesystem::path workspace_dir)
    : impl(PersistentMapImpl::Get(std::move(workspace_dir))),
      cf_handle(impl->DefaultColumnFamily()) {}

void PersistentMapBase::Set(std::string_view key, std::string_view val) const {
  const rocksdb::WriteOptions options;
  std::lock_guard<std::recursive_mutex> locker(KeyShardGuard(key));
  if (auto status = impl->Put(options, cf_handle, key, val); !status.ok()) {
    LOG(FATAL)
        << "Unable to map key '" << key << "' to value '" << val
        << "' in key-value store: " << status.ToString();
  }
}

void PersistentMapBase::MatchCommonPrefix(
    std::string key_prefix_,
    std::function<bool(std::string_view, std::string_view)> cb) const {

  rocksdb::ReadOptions options;
  options.prefix_same_as_start = true;

  const rocksdb::Slice key_prefix(key_prefix_);

  std::unique_ptr<rocksdb::Iterator> it(impl->NewIterator(options, cf_handle));

  for (it->Seek(key_prefix); it->Valid(); it->Next()) {
    rocksdb::Slice key = it->key();
    if (!key.starts_with(key_prefix)) {
      break;
    }
    rocksdb::Slice value = it->value();
    std::string_view key_view(key.data(), key.size());
    std::string_view value_view(value.data(), value.size());
    if (!cb(key_view, value_view)) {
      break;
    }
  }
}

bool PersistentMapBase::GetOrSet(std::string_view key,
                                 std::string *val) const {
  const rocksdb::ReadOptions read_options;
  const rocksdb::WriteOptions write_options;
  auto status = impl->Get(read_options, cf_handle, key, val);
  if (status.IsNotFound()) {
    std::lock_guard<std::recursive_mutex> locker(KeyShardGuard(key));
    status = impl->Get(read_options, cf_handle, key, val);
    if (status.IsNotFound()) {
      impl->Put(write_options, key, *val);
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool PersistentMapBase::TryGet(std::string_view key, std::string *val) const {
  rocksdb::ReadOptions options;
  const auto status = impl->Get(options, cf_handle, key, val);
  if (status.IsNotFound()) {
    return false;
  } else if (!status.ok()) {
    LOG(FATAL)
        << "Unable to value for key '" << key << "' in key-value store: "
        << status.ToString();
    return false;
  } else {
    return true;
  }
}

}  // namespace mx
