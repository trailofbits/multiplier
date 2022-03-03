// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/KeyValueStore.h>

#include <glog/logging.h>

#include <mutex>
#include <sstream>
#include <thread>

// So that rocksdb::Slice has std::string_view conversion functions.
#ifndef __cpp_lib_string_view
# define __cpp_lib_string_view
#endif

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

namespace mx {

// Implementation wrapper around RocksDB.
class KeyValueStore::KeyValueEngine {
 public:
  ~KeyValueEngine(void);
  explicit KeyValueEngine(std::filesystem::path kv_dir);

  void Erase(const std::string &key);
  void EraseMatchingPrefix(const std::string &key);

  bool TryGet(const std::string &key, std::string *val);
  void Set(const std::string &key, const std::string &val);
  void MatchCommonPrefix(
      const std::string &key_prefix,
      std::function<bool(const std::string &, const std::string &)> cb);

  void MatchRangesContainingKey(
      const std::string &search_key_with_pfx,
      std::function<bool(std::string_view low,
                         std::string_view high,
                         std::string_view key_suffix,
                         std::string_view value)> cb);

 private:
  KeyValueEngine(void) = delete;

  std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle *cf_handle;
};

namespace {

// Weak pointer to the global key-value storage engine shared by all instances.
static std::weak_ptr<KeyValueStore::KeyValueEngine> gEngine;
static std::mutex gEngineLock;

enum : size_t {
  kNumKeyShards = 1024UL
};

// When doing `GetOrSet` or `UpdateOrSet`,
// we hash the key and grab a lock based on that hash.
static std::mutex gKeyShards[kNumKeyShards];

// NOTE(pag): Make sure all key prefixes are length exactly 4, as we used a
//            fixed prefix extractor for the column family.
static const char *IDToKeyPrefix(KeyValueStore::KeyValueStoreID id) {
  switch (id) {
    case KeyValueStore::kPathToFileId:
      return "fid:";
    case KeyValueStore::kHashToTopLevelDeclId:
      return "tld:";
  }
}

// Gets or creates a new key-value storage engine.
static std::shared_ptr<KeyValueStore::KeyValueEngine>
GetEngine(KeyValueStore::KeyValueStoreID id, std::filesystem::path path) {
  std::lock_guard<std::mutex> locker(gEngineLock);
  auto ret = gEngine.lock();
  if (ret) {
    return ret;
  }

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

  ret = std::make_shared<KeyValueStore::KeyValueEngine>(kv_dir);
  gEngine = ret;
  return ret;
}

}  // namespace

KeyValueStore::KeyValueEngine::~KeyValueEngine(void) {
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

//  status = rocks_db->Close();
//  LOG_IF(ERROR, !status.ok())
//      << "Error closing key/value store: " << status.ToString();

  // NOTE(pag): Intentional memory leak here.
  (void) rocks_db.release();
}

KeyValueStore::KeyValueEngine::KeyValueEngine(std::filesystem::path kv_dir)
    : cf_handle(nullptr) {

  rocksdb::DBOptions options;
  options.create_if_missing = true;
  options.create_missing_column_families = true;
  options.IncreaseParallelism(static_cast<int>(
      std::thread::hardware_concurrency()));

  std::vector<rocksdb::ColumnFamilyDescriptor> cf_descs;
  rocksdb::ColumnFamilyOptions cf_options;
  cf_options.compression = rocksdb::kZlibCompression;
  cf_options.bottommost_compression = rocksdb::kZlibCompression;
//  cf_options.compression_opts = rocksdb::CompressionOptions(
//      15  /* MAX_WBITS */,
//      9  /* Z_BEST_COMPRESSION */,
//      0 /* Z_DEFAULT_STRATEGY */,
//      0, 0, true);
//  cf_options.bottommost_compression_opts = cf_options.compression_opts;
  cf_options.prefix_extractor.reset(rocksdb::NewFixedPrefixTransform(4));
  cf_descs.emplace_back(rocksdb::kDefaultColumnFamilyName, cf_options);

  std::vector<rocksdb::ColumnFamilyHandle *> cf_handles;
  rocksdb::DB *rocks_db_ptr = nullptr;
  auto db_path = kv_dir.string();
  auto status = rocksdb::DB::Open(options, db_path, cf_descs,
                                  &cf_handles, &rocks_db_ptr);
  CHECK(status.ok())
      << "Unable to open RocksDB database at " << db_path << ": "
      << status.ToString();

  CHECK_EQ(cf_handles.size(), 1);

  rocks_db.reset(rocks_db_ptr);
  cf_handle = cf_handles[0];
}

void KeyValueStore::KeyValueEngine::Erase(const std::string &key_) {
  rocksdb::Slice key(key_);
  rocksdb::WriteOptions options;

  const auto status = rocks_db->Delete(options, key);
  CHECK(status.ok())
      << "Unable to remove key '" << key_ << "' in key-value store: "
      << status.ToString();
}

// NOTE(pag): `full_key_prefix_` includes `KeyValueStore::key_prefix`.
void KeyValueStore::KeyValueEngine::EraseMatchingPrefix(
    const std::string &full_key_prefix_) {
  rocksdb::Slice full_key_prefix(full_key_prefix_);
  rocksdb::ReadOptions read_options;
  read_options.prefix_same_as_start = true;
  rocksdb::WriteOptions write_options;
  rocksdb::WriteBatch batch;

  std::unique_ptr<rocksdb::Iterator> it(
      rocks_db->NewIterator(read_options, cf_handle));

  auto num_found = 0;
  for (it->Seek(full_key_prefix); it->Valid(); it->Next()) {
    auto key = it->key();
    if (!key.starts_with(full_key_prefix)) {
      break;
    }
    ++num_found;
    batch.Delete(cf_handle, key);
  }

  it.reset();

  if (!num_found) {
    return;
  }

  const auto status = rocks_db->Write(write_options, &batch);
  CHECK(status.ok())
      << "Unable to remove all keys sharing prefix '" << full_key_prefix_
      << "' in key-value store: " << status.ToString();
}

bool KeyValueStore::KeyValueEngine::TryGet(const std::string &key_,
                                           std::string *val_) {
  rocksdb::Slice key(key_);
  rocksdb::ReadOptions options;
  const auto status = rocks_db->Get(options, cf_handle, key, val_);
  if (status.IsNotFound()) {
    return false;
  }

  CHECK(status.ok())
      << "Unable to value for key '" << key_ << "' in key-value store: "
      << status.ToString();

  return true;
}

void KeyValueStore::KeyValueEngine::Set(const std::string &key_,
                                        const std::string &val_) {
  const rocksdb::Slice key(key_);
  const rocksdb::Slice val(val_);
  const rocksdb::WriteOptions options;

  const auto status = rocks_db->Put(options, cf_handle, key, val);
  CHECK(status.ok())
      << "Unable to map key '" << key_ << "' to value '" << val_
      << "' in key-value store: " << status.ToString();
}

// Invoke a callback for each key/value pair, where all the keys share a
// common prefix.
void KeyValueStore::KeyValueEngine::MatchCommonPrefix(
    const std::string &full_key_prefix_,
    std::function<bool(const std::string &, const std::string &)> cb) {

  rocksdb::ReadOptions options;
  options.prefix_same_as_start = true;

  const rocksdb::Slice full_key_prefix(full_key_prefix_);

  std::unique_ptr<rocksdb::Iterator> it(
      rocks_db->NewIterator(options, cf_handle));

  for (it->Seek(full_key_prefix); it->Valid(); it->Next()) {
    auto key = it->key();
    if (!key.starts_with(full_key_prefix)) {
      break;
    }
    key.remove_prefix(4);
    if (!cb(key.ToString(), it->value().ToString())) {
      break;
    }
  }
}

void KeyValueStore::KeyValueEngine::MatchRangesContainingKey(
    const std::string &search_key_with_pfx,
    std::function<bool(std::string_view low,
                       std::string_view high,
                       std::string_view key_suffix,
                       std::string_view value)> cb) {

  rocksdb::ReadOptions options;

  std::unique_ptr<rocksdb::Iterator> it(
      rocks_db->NewIterator(options, cf_handle));

  std::string_view search_key = search_key_with_pfx;
  search_key.remove_prefix(4);
  auto search_key_length = search_key.length();

  for (it->Seek(search_key_with_pfx); it->Valid(); it->Next()) {
    auto key = it->key().ToStringView();
    key.remove_prefix(4);

    auto high = key.substr(0, search_key_length);
    key.remove_prefix(search_key_length);
    CHECK_EQ(key[0], ':');
    key.remove_prefix(1);

    auto low = key.substr(0, search_key_length);
    key.remove_prefix(search_key_length);
    CHECK_EQ(key[0], ':');
    key.remove_prefix(1);

    CHECK(low <= high);

    if (!(low <= search_key && search_key <= high)) {
      continue;
    }

    auto value = it->value().ToStringView();
    if (!cb(low, high, key, value)) {
      break;
    }
  }
}

KeyValueStore::~KeyValueStore(void) {}

KeyValueStore::KeyValueStore(KeyValueStoreID id, std::filesystem::path path)
    : engine(GetEngine(id, path)),
      key_prefix(IDToKeyPrefix(id)) {}

// Erase a key/value pair with the key `key`.
void KeyValueStore::Erase(const std::string &key) {
  std::stringstream ss;
  ss << key_prefix << key;
  engine->Erase(ss.str());
}

// Erase all key/value pair with whose key matches the prefix `key_prefix`.
void KeyValueStore::EraseMatchingPrefix(const std::string &key_prefix_) {
  std::stringstream ss;
  ss << key_prefix << key_prefix_;
  engine->EraseMatchingPrefix(ss.str());
}

// Try to get the value associated with `key` in the store. If the value
// exists, then `val` is updated, and `true` is returned. Otherwise `false`
// is returned.
bool KeyValueStore::TryGetImpl(const std::string &key, std::string *val) {
  std::stringstream ss;
  ss << key_prefix << key;
  return engine->TryGet(ss.str(), val);
}

// Set the value associated with `key` in the store to `val`.
void KeyValueStore::SetImpl(const std::string &key, const std::string &val) {
  std::stringstream ss;
  ss << key_prefix << key;
  engine->Set(ss.str(), val);
}

// Invoke a callback for each key/value pair.
void KeyValueStore::MatchAll(
    std::function<bool(const std::string &, const std::string &)> cb) {
  engine->MatchCommonPrefix(key_prefix, cb);
}

// Invoke a callback for each key/value pair, where all the keys share a
// common prefix.
void KeyValueStore::MatchCommonPrefix(
    const std::string &key_prefix_,
    std::function<bool(const std::string &, const std::string &)> cb) {
  std::stringstream ss;
  ss << key_prefix << key_prefix_;
  engine->MatchCommonPrefix(ss.str(), cb);
}

void KeyValueStore::MatchRangesContainingKey(
    const std::string &search_key,
    std::function<bool(std::string_view low,
                       std::string_view high,
                       std::string_view key_suffix,
                       std::string_view value)> cb) {
  std::stringstream ss;
  ss << key_prefix << search_key;
  engine->MatchRangesContainingKey(ss.str(), cb);
}

// Implements an atomic set if the value is missing. Returns `true` if the
// value was missing.
//
// NOTE(pag): This is only atomic with respect to other `GetOrSet` calls.
bool KeyValueStore::SetIfMissing(
    const std::string &key, std::function<std::string(void)> get_val_for_set) {

  std::stringstream ss;
  ss << key_prefix << key;
  const auto real_key = ss.str();

  std::string ret;
  if (engine->TryGet(real_key, &ret)) {
    return false;
  }

  std::hash<std::string> hasher;
  const auto hash_val = hasher(real_key);
  std::lock_guard<std::mutex> locker(gKeyShards[hash_val % kNumKeyShards]);

  if (engine->TryGet(real_key, &ret)) {
    return false;
  }

  ret = get_val_for_set();
  engine->Set(real_key, ret);
  return true;
}

// Implements an atomic get or set.
//
// NOTE(pag): This is only atomic with respect to other `GetOrSet` calls.
// NOTE(ppalka): And also with respect to `UpdateOrSet` calls.
std::string KeyValueStore::GetOrSet(
    const std::string &key, std::function<std::string(void)> get_val_for_set) {

  std::stringstream ss;
  ss << key_prefix << key;
  const auto real_key = ss.str();

  std::string ret;
  if (engine->TryGet(real_key, &ret)) {
    return ret;
  }

  std::hash<std::string> hasher;
  const auto hash_val = hasher(real_key);
  std::lock_guard<std::mutex> locker(gKeyShards[hash_val % kNumKeyShards]);

  if (engine->TryGet(real_key, &ret)) {
    return ret;
  }

  ret = get_val_for_set();
  engine->Set(real_key, ret);

  return ret;
}

std::string KeyValueStore::UpdateOrSet(
    const std::string &key,
    std::function<std::string(const std::string *)> update_val) {

  std::stringstream ss;
  ss << key_prefix << key;
  const auto real_key = ss.str();

  std::hash<std::string> hasher;
  const auto hash_val = hasher(real_key);
  std::lock_guard<std::mutex> locker(gKeyShards[hash_val % kNumKeyShards]);

  std::string ret;
  bool exists = engine->TryGet(real_key, &ret);

  ret = update_val(exists ? &ret : nullptr);
  engine->Set(real_key, ret);

  return ret;
}

}  // namespace mx
