// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IdStore.h"

#include <atomic>
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

using AtomicEntityId = std::atomic<mx::RawEntityId>;

// The next file ID that can be assigned. This represents an upper bound on
// the total number of file IDs.
static AtomicEntityId gNextFileIndex;

// The next ID for a "small fragment." A small fragment has fewer than
// `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
// are more common, and require fewer bits to encode token offsets inside of
// the packed `mx::EntityId` for tokens.
static AtomicEntityId gNextSmallFragmentIndex;

// The next ID for a "big fragment." A big fragment has at least
// `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
// are less common, so we reserve space for fewer of them (typically there is
// a maximum of 2^16 big fragments allowed). Big fragments require more bits
// to represent token offsets inside of the packed `mx::EntityId` for tokens,
// but because we reserve the low ID space for big fragment IDs, we know that
// we need fewer bits to represent the fragment IDs. Thus, we trade fragment
// bit for token offset bits.
static AtomicEntityId gNextBigFragmentIdex;

// The next type ID that can be assigned.
static AtomicEntityId gNextSmallTypeIndex;
static AtomicEntityId gNextBigTypeIndex;

// The next translation unit ID that can be assigned.
static AtomicEntityId gNextCompilationIndex;

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

// Create a key for the KV store by concatenating several elements, separated
// by `:`s.
//
// NOTE(pag): This accesses thread-
template <typename... Args>
inline static const std::string &Key(const Args&... args) {
  tKey.clear();
  llvm::raw_string_ostream key_os(tKey);
  ((key_os << args << ':'), ...);
  return tKey;
}

// Calculate the next proposed index. This might re-used a local cached index.
static mx::RawEntityId NextProposedIndex(
    std::optional<mx::RawEntityId> &local_unused_index,
    AtomicEntityId &global_next) {
  if (local_unused_index) {
    auto index = local_unused_index.value();
    local_unused_index.reset();
    return index;
  }

  return global_next.fetch_add(1u);
}

static rocksdb::DBOptions DBOptions(void) {
  rocksdb::DBOptions options;
  options.create_if_missing = true;
  options.create_missing_column_families = true;
  options.IncreaseParallelism(static_cast<int>(
      std::thread::hardware_concurrency()));
  return options;
}

static rocksdb::ColumnFamilyOptions CFOptions(void) {
  rocksdb::ColumnFamilyOptions cf_options;
  cf_options.compression = rocksdb::kZSTD;
  cf_options.bottommost_compression = rocksdb::kZSTD;
  cf_options.compression_opts.enabled = true;
  cf_options.OptimizeForPointLookup(2048  /* MiB */);
  return cf_options;
}

template <typename T>
static mx::RawEntityId PackAndCheckId(T id) {
  mx::EntityId eid(id);
  auto packed_id = eid.Pack();
  CHECK_NE(packed_id, mx::kInvalidEntityId);

  auto unpack = eid.Extract<T>();
  CHECK(unpack.has_value());
  CHECK(id == unpack.value());
  return packed_id;
}

}  // namespace

IdStore::~IdStore(void) {
  ExitNextIndices();

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

  std::vector<rocksdb::ColumnFamilyDescriptor> cf_descs;
  
  cf_descs.emplace_back(rocksdb::kDefaultColumnFamilyName, CFOptions());

  std::vector<rocksdb::ColumnFamilyHandle *> cf_handles;
  rocksdb::DB *rocks_db_ptr = nullptr;
  auto status = rocksdb::DB::Open(DBOptions(), abs_kvdir, cf_descs,
                                  &cf_handles, &rocks_db_ptr);
  rocks_db.reset(rocks_db_ptr);

  CHECK(status.ok())
      << "Unable to open RocksDB database at " << abs_kvdir << ": "
      << status.ToString();

  CHECK_EQ(cf_handles.size(), 1);

  cf_handle = cf_handles[0];

  InitNextIndices();
}

// Initialize the default metadata, or get its current state to continue on.
void IdStore::InitNextIndices(void) {
  gNextFileIndex.store(GetOrSet(kNextFileIndex, 1u).first);
  gNextCompilationIndex.store(GetOrSet(kNextCompilationIndex, 1u).first);
  gNextSmallFragmentIndex.store(GetOrSet(kNextSmallFragmentIndex,
                                           mx::kMaxBigFragmentId).first);
  gNextBigFragmentIdex.store(GetOrSet(kNextBigFragmentIndex, 1u).first);
  gNextSmallTypeIndex.store(
      GetOrSet(kNextSmallTypeIndex, mx::kMaxBigTypeId).first);
  gNextBigTypeIndex.store(GetOrSet(kNextBigTypeIndex, 1u).first);
}

// Store the metadata back to the database so that future executions of the
// indexer don't re-use already allocated indices.
void IdStore::ExitNextIndices(void) {
  UnlockedSet(kNextFileIndex, gNextFileIndex.load());
  UnlockedSet(kNextCompilationIndex, gNextCompilationIndex.load());
  UnlockedSet(kNextSmallFragmentIndex, gNextSmallFragmentIndex.load());
  UnlockedSet(kNextBigFragmentIndex, gNextBigFragmentIdex.load());
  UnlockedSet(kNextSmallTypeIndex, gNextSmallTypeIndex.load());
  UnlockedSet(kNextBigTypeIndex, gNextBigTypeIndex.load());
}

// Set `val` to `key`.
void IdStore::UnlockedSet(const std::string &key, mx::RawEntityId id) {
  IDMarshaller id_marshal;
  std::string &val = tValue;
  id_marshal.Store(id);
  id_marshal.LoadInto(val);
  auto status = rocks_db->Put(kWriteOptions, key, val);
  CHECK(status.ok());
}

// Core `GetOrSet` primitive used by higher-level APIs.
MaybeNewId<mx::RawEntityId> IdStore::GetOrSet(
    const std::string &key, mx::RawEntityId id) {

  IDMarshaller id_marshal;

  std::string &val = tValue;

  // Racy read, relying on RocksDB to implement the concurrency control.
  auto status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (status.ok() && val.size() == sizeof(id)) {
    id_marshal.Store(val);
    auto new_id = id_marshal.Load();
    CHECK_NE(id, new_id);
    return {new_id, false};
  }

  auto locker = KeyShardGuard(key);

  // Uncontended read, synchronized with concurrent `Put`s.
  status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (status.ok() && val.size() == sizeof(id)) {
    id_marshal.Store(val);
    auto new_id = id_marshal.Load();
    CHECK_NE(id, new_id);
    return {new_id, false};
  }

  id_marshal.Store(id);
  id_marshal.LoadInto(val);
  status = rocks_db->Put(kWriteOptions, key, val);
  CHECK(status.ok());

  return {id, true};
}

// Get, or create and return, a fragment ID for the specific fragment hash.
MaybeNewId<mx::PackedFragmentId> IdStore::GetOrCreateSmallFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens) {

  auto proposed_index = NextProposedIndex(
      tAvailableSmallFragmentIndex, gNextSmallFragmentIndex);

  CHECK_GE(proposed_index, mx::kMaxBigFragmentId);

  auto eid = mx::FragmentId(proposed_index);
  auto proposed_id = PackAndCheckId(eid);
  auto [found_id, is_new] = GetOrSet(
      Key("SFI", tok_id, num_tokens, Hash64(hash), Hash32(hash)),
      proposed_id);

  if (is_new) {
    return {eid, true};
  }

  tAvailableSmallFragmentIndex.emplace(proposed_index);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FragmentId>();
  CHECK(maybe_eid.has_value());
  CHECK_GE(maybe_eid->fragment_id, mx::kMaxBigFragmentId);
  return {maybe_eid.value(), false};
}

// Get, or create and return, a fragment ID for the specific fragment hash.
MaybeNewId<mx::PackedFragmentId> IdStore::GetOrCreateBigFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens) {

  auto proposed_index = NextProposedIndex(
      tAvailableBigFragmentIndex, gNextBigFragmentIdex);

  CHECK_LT(proposed_index, mx::kMaxBigFragmentId);
  
  auto eid = mx::FragmentId(proposed_index);
  auto proposed_id = PackAndCheckId(eid);
  auto [found_id, is_new] = GetOrSet(
      Key("BFI", tok_id, num_tokens, Hash64(hash), Hash32(hash)),
      proposed_id);

  if (is_new) {
    return {eid, true};
  }

  tAvailableBigFragmentIndex.emplace(proposed_index);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FragmentId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->fragment_id, mx::kMaxBigFragmentId);
  return {maybe_eid.value(), false};
}

MaybeNewId<mx::PackedFragmentId> IdStore::GetOrCreateFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens) {

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  //
  // NOTE(pag): We have a fudge factor here of `3x` to account for macro
  //            expansions.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    return GetOrCreateBigFragmentIdForHash(tok_id, std::move(hash), num_tokens);
  } else {
    return GetOrCreateSmallFragmentIdForHash(
        tok_id, std::move(hash), num_tokens);
  }
}

MaybeNewId<mx::PackedTypeId> IdStore::GetOrCreateSmallTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
    std::string hash) {

  auto proposed_index = NextProposedIndex(
      tAvailableSmallTypeIndex, gNextSmallTypeIndex);

  CHECK_GE(proposed_index, mx::kMaxBigTypeId);
  CHECK_LT(proposed_index, mx::kMaxSmallTypeId);

  auto eid = mx::TypeId(proposed_index, type_kind);
  auto proposed_id = PackAndCheckId(eid);
  auto [found_id, is_new] = GetOrSet(
      Key("STI", int(type_kind), type_qualifiers, num_tokens,
          Hash64(hash), Hash32(hash)),
      proposed_id);

  if (is_new) {
    return {eid, true};
  }

  tAvailableSmallTypeIndex.emplace(proposed_index);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::TypeId>();
  CHECK(maybe_eid.has_value());
  CHECK_GE(maybe_eid->type_id, mx::kMaxBigTypeId);
  CHECK_LT(maybe_eid->type_id, mx::kMaxSmallTypeId);
  CHECK(maybe_eid->kind == type_kind);

  return {maybe_eid.value(), false};
}

MaybeNewId<mx::PackedTypeId> IdStore::GetOrCreateBigTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
    std::string hash) {

  auto proposed_index = NextProposedIndex(
      tAvailableBigTypeIndex, gNextBigTypeIndex);

  CHECK_LT(proposed_index, mx::kMaxBigTypeId);

  auto eid = mx::TypeId(proposed_index, type_kind);
  auto proposed_id = PackAndCheckId(eid);
  auto [found_id, is_new] = GetOrSet(
      Key("BTI", int(type_kind), type_qualifiers, num_tokens,
          Hash64(hash), Hash32(hash)),
      proposed_id);

  if (is_new) {
    return {eid, true};
  }

  tAvailableBigTypeIndex.emplace(proposed_index);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::TypeId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->type_id, mx::kMaxBigTypeId);
  CHECK(maybe_eid->kind == type_kind);

  return {maybe_eid.value(), false};
}

MaybeNewId<mx::PackedTypeId> IdStore::GetOrCreateTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers,
    std::string hash, size_t num_tokens) {

  // Big types will have IDs in the range [1, mx::kMaxBigTypeId) and small types
  // will have ids [mx::kMaxBigTypeId: 2^36 + mx::kMaxBigTypeId)
  if (num_tokens >= mx::kNumTokensInBigType) {
    return GetOrCreateBigTypeIdForHash(type_kind, type_qualifiers, num_tokens,
                                       std::move(hash));
  } else {
    return GetOrCreateSmallTypeIdForHash(type_kind, type_qualifiers, num_tokens,
                                         std::move(hash));
  }
}

// Get, or create and return, a file ID for the specific file contents hash.
MaybeNewId<mx::PackedFileId> IdStore::GetOrCreateFileIdForHash(
    std::string hash) {

  auto proposed_index = NextProposedIndex(tAvailableFileIndex, gNextFileIndex);

  CHECK_LT(proposed_index, mx::kMaxFileId);

  auto eid = mx::FileId(proposed_index);
  auto proposed_id = PackAndCheckId(eid);
  auto [found_id, is_new] = GetOrSet(Key("FID", hash), proposed_id);
  if (is_new) {
    return {eid, true};
  }

  tAvailableFileIndex.emplace(proposed_index);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FileId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->file_id, mx::kMaxFileId);
  return {maybe_eid.value(), false};
}

MaybeNewId<mx::PackedCompilationId> IdStore::GetOrCreateCompilationId(
    mx::RawEntityId file_id, std::string hash) {

  auto fid = mx::EntityId(file_id).Extract<mx::FileId>();
  CHECK(fid.has_value());

  auto proposed_index = NextProposedIndex(
      tAvailableCompilationIndex, gNextCompilationIndex);

  CHECK_LT(proposed_index, mx::kMaxCompilationId);

  auto eid = mx::CompilationId(proposed_index, fid->file_id);
  auto proposed_id = PackAndCheckId(eid);
  auto [found_id, is_new] = GetOrSet(Key("CID", file_id, hash), proposed_id);
  if (is_new) {
    return {eid, true};
  }

  tAvailableCompilationIndex.emplace(proposed_index);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::CompilationId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->compilation_id, mx::kMaxCompilationId);
  CHECK_EQ(maybe_eid->file_id, fid->file_id);
  return {maybe_eid.value(), false};
}

}  // namespace indexer