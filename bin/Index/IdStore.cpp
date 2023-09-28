// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IdStore.h"

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

#include <llvm/Support/raw_ostream.h>

#include "Endian.h"
#include "Util.h"

// For internal limits, e.g. `kMaxBigFragmentId`.
#include "../../lib/Types.h"

namespace indexer {
namespace {

// Used for temporary storage of values read from RocksDB.
static thread_local std::string tKey;
static thread_local std::string tValue;

// Used to ensure only one instance of `IdStore` exists, otherwise we need to
// bring back old logic (from Git history) for mapping workspace paths to
// `rocksdb::DB`s.
static std::atomic_flag gSingleton = ATOMIC_FLAG_INIT;

// Available indices that we have "allocated" by aren't yet using. We
// opportunistically allocate IDs, then race with the other indexer threads
// to try to create various IDs. If we lose the race, then we leave an unused
// hole in the (precious) ID space. So we keep the holes around for the next
// allocation.
//
// NOTE(pag): Move to using `ThreadLocal` if we ever migrate away from
//            `gSingleton`.
static thread_local std::optional<mx::RawEntityId> tAvailableFileIndex;
static thread_local std::optional<mx::RawEntityId> tAvailableCompilationIndex;
static thread_local std::optional<mx::RawEntityId> tAvailableSmallFragmentIndex;
static thread_local std::optional<mx::RawEntityId> tAvailableBigFragmentIndex;
static thread_local std::optional<mx::RawEntityId> tAvailableSmallTypeIndex;
static thread_local std::optional<mx::RawEntityId> tAvailableBigTypeIndex;

// Keys in the ID store to hold current values for the IDs.
static const std::string kNextFileIndex = "meta:NEXT_FILE_INDEX";
static const std::string kNextCompilationIndex = "meta:NEXT_COMPILATION_INDEX";
static const std::string kNextSmallFragmentIndex = "meta:NEXT_SMALL_FRAGMENT_INDEX";
static const std::string kNextBigFragmentIndex = "meta:NEXT_BIG_FRAGMENT_INDEX";
static const std::string kNextSmallTypeIndex = "meta:NEXT_SMALL_TYPE_INDEX";
static const std::string kNextBigTypeIndex = "meta:NEXT_BIG_TYPE_INDEX";

static const rocksdb::ReadOptions kReadOptions;
static const rocksdb::WriteOptions kWriteOptions;

enum : size_t {
  kNumKeyShards = 1024UL
};

// When doing `GetOrSet` we hash the key and grab a lock based on that hash.
static std::mutex gKeyShards[kNumKeyShards];

static std::unique_lock<std::mutex> KeyShardGuard(std::string_view key) {
  return std::unique_lock<std::mutex>(gKeyShards[Hash32(key) % kNumKeyShards]);
}

// Convert an entity ID into big endian.
static mx::RawEntityId Canonicalize(mx::RawEntityId id) {
  if MX_CONSTEXPR_ENDIAN (MX_LITTLE_ENDIAN) {
    return __builtin_bswap64(id);
  }
  return id;
}

// Marshal an 8-byte integer ID into a sequence of bytes.
union alignas(mx::RawEntityId) IDMarshaller {
  mx::RawEntityId as_id;
  char as_bytes[sizeof(mx::RawEntityId)];

  void Store(mx::RawEntityId val) {
    as_id = Canonicalize(val);
  }

  void Store(const std::string &view) {
    memcpy(as_bytes, view.data(), sizeof(as_id));
  }

  mx::RawEntityId Load(void) const {
    return Canonicalize(as_id);
  }

  void LoadInto(std::string &out) const {
    out.clear();
    out.insert(out.end(), as_bytes, &(as_bytes[sizeof(as_id)]));
  }
};

static_assert(sizeof(IDMarshaller) == sizeof(mx::RawEntityId));

}  // namespace

IdStore::~IdStore(void) {
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

IdStore::IdStore(std::filesystem::path path) {
  
  // Only allow one instance; reduces logic needed to merge "connections"
  // based on directories.
  CHECK(!gSingleton.test_and_set())
      << "Can only have one instance of IdStore at a time.";

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

  auto abs_kvdir = std::filesystem::canonical(path, ec);
  CHECK(!ec)
      << "Specified directory '" << path.generic_string()
      << "' for key-value storage cannot be canonicalized: " << ec.message();

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

  // Initialize the default metadata.
  next_file_index.store(GetOrSet(kNextFileIndex, 1u));
  next_compilation_index.store(GetOrSet(kNextCompilationIndex, 1u));
  next_small_fragment_index.store(GetOrSet(kNextSmallFragmentIndex, mx::kMaxBigFragmentId));
  next_big_fragment_index.store(GetOrSet(kNextBigFragmentIndex, 1u));
  next_small_type_index.store(GetOrSet(kNextSmallTypeIndex, mx::kMaxBigTypeId));
  next_big_type_index.store(GetOrSet(kNextBigTypeIndex, 1u));
}

// Core `GetOrSet` primitive used by higher-level APIs.
mx::RawEntityId IdStore::GetOrSet(const std::string &key, mx::RawEntityId id) {

  IDMarshaller id_marshal;

  std::string &val = tValue;

  // Racy read, relying on RocksDB to implement the concurrency control.
  auto status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (status.ok() && val.size() == sizeof(id)) {
    id_marshal.Store(val);
    return id_marshal.Load();
  }

  auto locker = KeyShardGuard(key);

  // Uncontended read, synchronized with concurrent `Put`s.
  status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (status.ok() && val.size() == sizeof(id)) {
    id_marshal.Store(val);
    return id_marshal.Load();
  }

  id_marshal.Store(id);
  id_marshal.LoadInto(val);
  status = rocks_db->Put(kWriteOptions, key, val);
  CHECK(status.ok());

  return id;
}

// Get, or create and return, a fragment ID for the specific fragment hash.
mx::PackedFragmentId IdStore::GetOrCreateSmallFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new) {

  mx::RawEntityId proposed_index = {};

  // Try to reuse a previously generated but unused fragment id.
  if (!tAvailableSmallFragmentIndex) {
    proposed_index = next_small_fragment_index.fetch_add(1u);
  } else {
    proposed_index = tAvailableSmallFragmentIndex.value();
    tAvailableSmallFragmentIndex.reset();
  }

  mx::FragmentId eid(proposed_index);

  // NOTE(pag): The maximum value for a small fragment ID is calculated relative
  //            to other things in its packed storage format.
  auto roundtrip_eid = mx::EntityId(eid).Extract<mx::FragmentId>();
  CHECK(roundtrip_eid.has_value());
  CHECK_EQ(roundtrip_eid->fragment_id, eid.fragment_id);
  auto proposed_id = mx::EntityId(eid).Pack();
  CHECK_NE(proposed_id, mx::kInvalidEntityId);

  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  key_os << "SFI:" << tok_id << ':' << num_tokens << ':'
         << Hash64(hash) << ':' << Hash32(hash);

  auto found_id = GetOrSet(tKey, proposed_id);
  is_new = found_id == proposed_id;
  if (!is_new) {
    tAvailableSmallFragmentIndex.emplace(proposed_index);

    mx::VariantId vid = mx::EntityId(found_id).Unpack();
    CHECK(std::holds_alternative<mx::FragmentId>(vid));

    eid = std::get<mx::FragmentId>(vid);
    CHECK_GE(eid.fragment_id, mx::kMaxBigFragmentId);
  }

  return eid;
}

// Get, or create and return, a fragment ID for the specific fragment hash.
mx::PackedFragmentId IdStore::GetOrCreateBigFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new) {

  mx::RawEntityId proposed_index = {};

  // Try to reuse a previously generated but unused fragment id.
  if (!tAvailableBigFragmentIndex) {
    proposed_index = next_big_fragment_index.fetch_add(1u);
  } else {
    proposed_index = tAvailableBigFragmentIndex.value();
    tAvailableBigFragmentIndex.reset();
  }

  CHECK_LT(proposed_index, mx::kMaxBigFragmentId);
  mx::FragmentId eid(proposed_index);
  auto proposed_id = mx::EntityId(eid).Pack();
  CHECK_NE(proposed_id, mx::kInvalidEntityId);

  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  key_os << "BFI:" << tok_id << ':' << num_tokens << ':'
         << Hash64(hash) << ':' << Hash32(hash);

  auto found_id = GetOrSet(tKey, proposed_id);
  is_new = found_id == proposed_id;
  if (!is_new) {
    tAvailableBigFragmentIndex.emplace(proposed_index);

    mx::VariantId vid = mx::EntityId(found_id).Unpack();
    CHECK(std::holds_alternative<mx::FragmentId>(vid));

    eid = std::get<mx::FragmentId>(vid);
    CHECK_LT(eid.fragment_id, mx::kMaxBigFragmentId);
  }

  return eid;
}

mx::PackedFragmentId IdStore::GetOrCreateFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new) {

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  //
  // NOTE(pag): We have a fudge factor here of `3x` to account for macro
  //            expansions.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    return GetOrCreateBigFragmentIdForHash(
        tok_id, std::move(hash), num_tokens, is_new);
  } else {
    return GetOrCreateSmallFragmentIdForHash(
        tok_id, std::move(hash), num_tokens, is_new);
  }
}

mx::PackedTypeId IdStore::GetOrCreateSmallTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
    std::string hash, bool &is_new) {

  mx::RawEntityId proposed_index = {};

  // Try to reuse a previously generated but unused type id.
  if (!tAvailableSmallTypeIndex) {
    proposed_index = next_small_type_index.fetch_add(1u);
  } else {
    proposed_index = tAvailableSmallTypeIndex.value();
    tAvailableSmallTypeIndex.reset();
  }

  CHECK_LT(proposed_index, mx::kMaxSmallTypeId);
  mx::TypeId eid(proposed_index, type_kind);
  auto proposed_id = mx::EntityId(eid).Pack();
  CHECK_NE(proposed_id, mx::kInvalidEntityId);

  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  key_os << "STI:" << int(type_kind) << ':' << type_qualifiers
         << ':' << num_tokens << ':' << Hash64(hash) << ':' << Hash32(hash);

  auto found_id = GetOrSet(tKey, proposed_id);
  is_new = found_id == proposed_id;
  if (!is_new) {
    tAvailableSmallTypeIndex.emplace(proposed_index);

    mx::VariantId vid = mx::EntityId(found_id).Unpack();
    CHECK(std::holds_alternative<mx::TypeId>(vid));

    eid = std::get<mx::TypeId>(vid);
    CHECK_GE(eid.type_id, mx::kMaxBigTypeId);
    CHECK_LT(eid.type_id, mx::kMaxSmallTypeId);
    CHECK(eid.kind == type_kind);
  }

  return eid;
}

mx::PackedTypeId IdStore::GetOrCreateBigTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
    std::string hash, bool &is_new) {

  mx::RawEntityId proposed_index = {};

  // Try to reuse a previously generated but unused type id.
  if (!tAvailableBigTypeIndex) {
    proposed_index = next_big_type_index.fetch_add(1u);
  } else {
    proposed_index = tAvailableBigTypeIndex.value();
    tAvailableBigTypeIndex.reset();
  }

  CHECK_LT(proposed_index, mx::kMaxBigTypeId);
  mx::TypeId eid(proposed_index, type_kind);
  auto proposed_id = mx::EntityId(eid).Pack();
  CHECK_NE(proposed_id, mx::kInvalidEntityId);

  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  key_os << "BTI:" << int(type_kind) << ':' << type_qualifiers
         << ':' << num_tokens << ':' << Hash64(hash) << ':' << Hash32(hash);

  auto found_id = GetOrSet(tKey, proposed_id);
  is_new = found_id == proposed_id;
  if (!is_new) {
    tAvailableBigTypeIndex.emplace(proposed_index);

    mx::VariantId vid = mx::EntityId(found_id).Unpack();
    CHECK(std::holds_alternative<mx::TypeId>(vid));

    eid = std::get<mx::TypeId>(vid);
    CHECK_LT(eid.type_id, mx::kMaxBigTypeId);
    CHECK(eid.kind == type_kind);
  }

  return eid;
}

mx::PackedTypeId IdStore::GetOrCreateTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers,
    std::string hash, size_t num_tokens,
    bool &is_new) {

  // Big types will have IDs in the range [1, mx::kMaxBigTypeId) and small types
  // will have ids [mx::kMaxBigTypeId: 2^36 + mx::kMaxBigTypeId)
  if (num_tokens >= mx::kNumTokensInBigType) {
    return GetOrCreateBigTypeIdForHash(type_kind, type_qualifiers, num_tokens,
                                       std::move(hash), is_new);
  } else {
    return GetOrCreateSmallTypeIdForHash(type_kind, type_qualifiers, num_tokens,
                                         std::move(hash), is_new);
  }
}

// Get, or create and return, a file ID for the specific file contents hash.
mx::PackedFileId IdStore::GetOrCreateFileIdForHash(
    std::string hash, bool &is_new) {

  mx::RawEntityId proposed_index = {};

  // Try to reuse a previously generated but unused file id.
  if (!tAvailableFileIndex) {
    proposed_index = next_file_index.fetch_add(1u);
  } else {
    proposed_index = tAvailableFileIndex.value();
    tAvailableFileIndex.reset();
  }

  CHECK_LT(proposed_index, mx::kMaxFileId);

  mx::FileId eid(proposed_index);
  auto proposed_id = mx::EntityId(eid).Pack();
  CHECK_NE(proposed_id, mx::kInvalidEntityId);

  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  key_os << "FID:" << hash;

  auto found_id = GetOrSet(tKey, proposed_id);
  is_new = found_id == proposed_id;
  if (!is_new) {
    tAvailableFileIndex.emplace(proposed_index);

    mx::VariantId vid = mx::EntityId(found_id).Unpack();
    CHECK(std::holds_alternative<mx::FileId>(vid));

    eid = std::get<mx::FileId>(vid);
    CHECK_LT(eid.file_id, mx::kMaxFileId);
  }

  return eid;
}

mx::PackedCompilationId IdStore::GetOrCreateCompilationId(
    mx::RawEntityId file_id, std::string hash, bool &is_new) {

  mx::RawEntityId proposed_index = {};

  // Try to reuse a previously generated but unused compilation id.
  if (!tAvailableCompilationIndex) {
    proposed_index = next_compilation_index.fetch_add(1u);
  } else {
    proposed_index = tAvailableCompilationIndex.value();
    tAvailableCompilationIndex.reset();
  }

  auto fid = mx::EntityId(file_id).Extract<mx::FileId>();
  CHECK(fid.has_value());

  CHECK_LT(proposed_index, mx::kMaxCompilationId);
  mx::CompilationId eid;
  eid.compilation_id = proposed_index;
  eid.file_id = fid->file_id;
  auto proposed_id = mx::EntityId(eid).Pack();
  CHECK_NE(proposed_id, mx::kInvalidEntityId);

  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  key_os << "CID:" << file_id << ':' << hash;

  auto found_id = GetOrSet(tKey, proposed_id);
  is_new = found_id == proposed_id;
  if (!is_new) {
    tAvailableCompilationIndex.emplace(proposed_index);

    mx::VariantId vid = mx::EntityId(found_id).Unpack();
    CHECK(std::holds_alternative<mx::CompilationId>(vid));

    eid = std::get<mx::CompilationId>(vid);
    CHECK_LT(eid.compilation_id, mx::kMaxCompilationId);
    CHECK_EQ(eid.file_id, fid->file_id);
  }

  return eid;
}

}  // namespace indexer