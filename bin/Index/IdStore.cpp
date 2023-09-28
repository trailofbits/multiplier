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

using AtomicEntityId = std::atomic<mx::RawEntityId>;

// Used for temporary storage of values read from RocksDB.
static thread_local std::string tKey;
static thread_local std::string tValue;

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

// Guards the set of open databases.
static std::mutex gOpenDbsLock;
static std::unordered_map<std::string, std::weak_ptr<IdStoreImpl>> gOpenDbs;

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
static mx::RawEntityId NextProposedIndex(AtomicEntityId &global_next) {
  return global_next.fetch_add(1u);
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

static mx::RawEntityId MakeOne(void) {
  return 1u;
}

static mx::RawEntityId MakeMaxBigFragmentId(void) {
  return mx::kMaxBigFragmentId;
}

static mx::RawEntityId MakeMaxBigTypeId(void) {
  return mx::kMaxBigTypeId;
}

}  // namespace

class IdStoreImpl {
 private:
  const std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle * const cf_handle;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  AtomicEntityId next_file_index;

  // The next translation unit ID that can be assigned.
  AtomicEntityId next_compilation_index;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  AtomicEntityId next_small_fragment_index;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  AtomicEntityId next_big_fragment_index;

  // The next type ID that can be assigned.
  AtomicEntityId next_small_type_index;
  AtomicEntityId next_big_type_index;

  // Store the `next_*` ids back to the database.
  void ExitNextIndices(void);

  // Safely close RocksDB.
  void ExitRocksDB(void);

  // Set `val` to `key`.
  void UnlockedSet(const std::string &key, mx::RawEntityId val);

  // Core `GetOrSet` primitive used by higher-level APIs.
  template <typename MakeId>
  MaybeNewId<mx::RawEntityId> GetOrSet(const std::string &key, MakeId make_id);

 public:
  static std::shared_ptr<IdStoreImpl> Open(std::filesystem::path path);

  ~IdStoreImpl(void) {
    ExitNextIndices();
    ExitRocksDB();
  }

  IdStoreImpl(rocksdb::DB *rocks_db_)
      : rocks_db(rocks_db_),
        cf_handle(rocks_db->DefaultColumnFamily()),
        next_file_index(
            GetOrSet(kNextFileIndex, MakeOne).first),
        next_compilation_index(
            GetOrSet(kNextCompilationIndex, MakeOne).first),
        next_small_fragment_index(
            GetOrSet(kNextSmallFragmentIndex, MakeMaxBigFragmentId).first),
        next_big_fragment_index(
            GetOrSet(kNextBigFragmentIndex, MakeOne).first),
        next_small_type_index(
            GetOrSet(kNextSmallTypeIndex, MakeMaxBigTypeId).first),
        next_big_type_index(
            GetOrSet(kNextBigTypeIndex, MakeOne).first) {}

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

  MaybeNewId<mx::PackedFileId> GetOrCreateFileIdForHash(std::string hash);

  MaybeNewId<mx::PackedCompilationId> GetOrCreateCompilationId(
      mx::RawEntityId file_id, std::string hash);
};

std::shared_ptr<IdStoreImpl> IdStoreImpl::Open(std::filesystem::path path) {
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

  std::string name = abs_kvdir.generic_string();

  std::unique_lock<std::mutex> locker(gOpenDbsLock);
  auto &db_ptr_ref = gOpenDbs[name];
  if (auto already_open_db = db_ptr_ref.lock()) {
    return already_open_db;
  }

  std::vector<rocksdb::ColumnFamilyDescriptor> cf_descs;
  
  cf_descs.emplace_back(rocksdb::kDefaultColumnFamilyName, CFOptions());

  std::vector<rocksdb::ColumnFamilyHandle *> cf_handles;
  rocksdb::DB *rocks_db_ptr = nullptr;
  auto status = rocksdb::DB::Open(DBOptions(), abs_kvdir, cf_descs,
                                  &cf_handles, &rocks_db_ptr);

  CHECK(status.ok())
      << "Unable to open RocksDB database at " << abs_kvdir << ": "
      << status.ToString();

  CHECK_EQ(cf_handles.size(), 1);

  auto db_ptr = std::make_shared<IdStoreImpl>(rocks_db_ptr);
  db_ptr_ref = db_ptr;
  return db_ptr;
}

// Store the metadata back to the database so that future executions of the
// indexer don't re-use already allocated indices.
void IdStoreImpl::ExitNextIndices(void) {
  UnlockedSet(kNextFileIndex, next_file_index.load());
  UnlockedSet(kNextCompilationIndex, next_compilation_index.load());
  UnlockedSet(kNextSmallFragmentIndex, next_small_fragment_index.load());
  UnlockedSet(kNextBigFragmentIndex, next_big_fragment_index.load());
  UnlockedSet(kNextSmallTypeIndex, next_small_type_index.load());
  UnlockedSet(kNextBigTypeIndex, next_big_type_index.load());
}

// Safely close RocksDB.
void IdStoreImpl::ExitRocksDB(void) {
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

// Set `val` to `key`.
void IdStoreImpl::UnlockedSet(const std::string &key, mx::RawEntityId id) {
  IDMarshaller id_marshal;
  id_marshal.Store(id);
  id_marshal.LoadInto(tValue);
  CHECK(rocks_db->Put(kWriteOptions, key, tValue).ok());
}

// Core `GetOrSet` primitive used by higher-level APIs.
template <typename MakeId>
MaybeNewId<mx::RawEntityId> IdStoreImpl::GetOrSet(
    const std::string &key, MakeId make_id) {

  IDMarshaller id_marshal;
  std::string &val = tValue;
  val.clear();

  // Racy read, relying on RocksDB to implement the concurrency control.
  auto racy_get_status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (racy_get_status.ok() && val.size() == sizeof(id_marshal)) {
    id_marshal.Store(val);
    return {id_marshal.Load(), false};
  }

  auto locker = KeyShardGuard(key);

  // Uncontended read, synchronized with concurrent `Put`s.
  auto locked_get_status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (locked_get_status.ok() && val.size() == sizeof(id_marshal)) {
    id_marshal.Store(val);
    return {id_marshal.Load(), false};
  }

  auto invented_id = make_id();
  UnlockedSet(key, invented_id);
  return {invented_id, true};
}

// Get, or create and return, a fragment ID for the specific fragment hash.
MaybeNewId<mx::PackedFragmentId> IdStoreImpl::GetOrCreateSmallFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens) {

  auto [found_id, is_new] = GetOrSet(
      Key("SFI", tok_id, num_tokens, Hash64(hash), Hash32(hash)),
      [=, this] (void) {
        auto proposed_index = NextProposedIndex(next_small_fragment_index);
        CHECK_GE(proposed_index, mx::kMaxBigFragmentId);
        return PackAndCheckId(mx::FragmentId(proposed_index));
      });

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FragmentId>();
  CHECK(maybe_eid.has_value());
  CHECK_GE(maybe_eid->fragment_id, mx::kMaxBigFragmentId);
  return {maybe_eid.value(), is_new};
}

// Get, or create and return, a fragment ID for the specific fragment hash.
MaybeNewId<mx::PackedFragmentId> IdStoreImpl::GetOrCreateBigFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens) {

  auto [found_id, is_new] = GetOrSet(
      Key("BFI", tok_id, num_tokens, Hash64(hash), Hash32(hash)),
      [=, this] (void) {
        auto proposed_index = NextProposedIndex(next_big_fragment_index);
        CHECK_LT(proposed_index, mx::kMaxBigFragmentId);
        return PackAndCheckId(mx::FragmentId(proposed_index));
      });

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FragmentId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->fragment_id, mx::kMaxBigFragmentId);
  return {maybe_eid.value(), is_new};
}

MaybeNewId<mx::PackedTypeId> IdStoreImpl::GetOrCreateSmallTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
    std::string hash) {

  auto [found_id, is_new] = GetOrSet(
      Key("STI", int(type_kind), type_qualifiers, num_tokens,
          Hash64(hash), Hash32(hash)),
      [=, this] (void) { 
        auto proposed_index = NextProposedIndex(next_small_type_index);
        CHECK_GE(proposed_index, mx::kMaxBigTypeId);
        CHECK_LT(proposed_index, mx::kMaxSmallTypeId);
        return PackAndCheckId(mx::TypeId(proposed_index, type_kind));
      });

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::TypeId>();
  CHECK(maybe_eid.has_value());
  CHECK_GE(maybe_eid->type_id, mx::kMaxBigTypeId);
  CHECK_LT(maybe_eid->type_id, mx::kMaxSmallTypeId);
  CHECK(maybe_eid->kind == type_kind);

  return {maybe_eid.value(), is_new};
}

MaybeNewId<mx::PackedTypeId> IdStoreImpl::GetOrCreateBigTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, size_t num_tokens,
    std::string hash) {

  auto [found_id, is_new] = GetOrSet(
      Key("BTI", int(type_kind), type_qualifiers, num_tokens,
          Hash64(hash), Hash32(hash)),
      [=, this] (void) {
        auto proposed_index = NextProposedIndex(next_big_type_index);
        CHECK_LT(proposed_index, mx::kMaxBigTypeId);
        return PackAndCheckId(mx::TypeId(proposed_index, type_kind));
      });

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::TypeId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->type_id, mx::kMaxBigTypeId);
  CHECK(maybe_eid->kind == type_kind);
  return {maybe_eid.value(), is_new};
}

// Get, or create and return, a file ID for the specific file contents hash.
MaybeNewId<mx::PackedFileId> IdStoreImpl::GetOrCreateFileIdForHash(
    std::string hash) {

  auto [found_id, is_new] = GetOrSet(
      Key("FID", hash),
      [=, this] (void) {
        auto proposed_index = NextProposedIndex(next_file_index);
        CHECK_LT(proposed_index, mx::kMaxFileId);
        return PackAndCheckId(mx::FileId(proposed_index));
      });

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FileId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->file_id, mx::kMaxFileId);
  return {maybe_eid.value(), is_new};
}

MaybeNewId<mx::PackedCompilationId> IdStoreImpl::GetOrCreateCompilationId(
    mx::RawEntityId file_id, std::string hash) {

  auto fid = mx::EntityId(file_id).Extract<mx::FileId>();
  CHECK(fid.has_value());

  auto [found_id, is_new] = GetOrSet(
      Key("CID", file_id, hash),
      [=, this] (void) {
        auto proposed_index = NextProposedIndex(next_compilation_index);
        CHECK_LT(proposed_index, mx::kMaxCompilationId);
        return PackAndCheckId(mx::CompilationId(proposed_index, fid->file_id));
      });

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::CompilationId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->compilation_id, mx::kMaxCompilationId);
  CHECK_EQ(maybe_eid->file_id, fid->file_id);
  return {maybe_eid.value(), is_new};
}

IdStore::~IdStore(void) {}

IdStore::IdStore(std::filesystem::path path) 
    : impl(IdStoreImpl::Open(path)) {}

MaybeNewId<mx::PackedFragmentId> IdStore::GetOrCreateFragmentIdForHash(
    mx::RawEntityId tok_id, std::string hash, size_t num_tokens) {

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  //
  // NOTE(pag): We have a fudge factor here of `3x` to account for macro
  //            expansions.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    return impl->GetOrCreateBigFragmentIdForHash(tok_id, std::move(hash), num_tokens);
  } else {
    return impl->GetOrCreateSmallFragmentIdForHash(
        tok_id, std::move(hash), num_tokens);
  }
}

MaybeNewId<mx::PackedTypeId> IdStore::GetOrCreateTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers,
    std::string hash, size_t num_tokens) {

  // Big types will have IDs in the range [1, mx::kMaxBigTypeId) and small types
  // will have ids [mx::kMaxBigTypeId: 2^36 + mx::kMaxBigTypeId)
  if (num_tokens >= mx::kNumTokensInBigType) {
    return impl->GetOrCreateBigTypeIdForHash(type_kind, type_qualifiers, num_tokens,
                                       std::move(hash));
  } else {
    return impl->GetOrCreateSmallTypeIdForHash(type_kind, type_qualifiers, num_tokens,
                                         std::move(hash));
  }
}

// Get, or create and return, a file ID for the specific file contents hash.
MaybeNewId<mx::PackedFileId> IdStore::GetOrCreateFileIdForHash(
    std::string hash) {
  return impl->GetOrCreateFileIdForHash(std::move(hash));
}

MaybeNewId<mx::PackedCompilationId> IdStore::GetOrCreateCompilationId(
    mx::RawEntityId file_id, std::string hash) {
  return impl->GetOrCreateCompilationId(file_id, std::move(hash));
}

}  // namespace indexer