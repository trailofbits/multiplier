// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IdStore.h"

#include <algorithm>
#include <atomic>
#include <deque>
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

// For internal limits, e.g. `kMaxBigFragmentId`.
#include "../../lib/Types.h"

namespace indexer {
namespace {

static const rocksdb::ReadOptions kReadOptions;
static const rocksdb::WriteOptions kWriteOptions;

static constexpr size_t kNumKeyShards = 1024UL;

// When doing `GetOrSet` we hash the key and grab a lock based on that hash.
static std::mutex gKeyShards[kNumKeyShards];

// Guards the set of open databases.
static std::mutex gOpenDbsLock;
static std::unordered_map<std::string, std::weak_ptr<IdStoreImpl>> gOpenDbs;

inline static rocksdb::Options DBOptions(void) {
  rocksdb::Options options;
  options.create_if_missing = true;
  options.compression = rocksdb::kZSTD;
  options.bottommost_compression = rocksdb::kZSTD;
  options.compression_opts.enabled = true;
  options.OptimizeForPointLookup(2048  /* MiB */);
  options.IncreaseParallelism(static_cast<int>(
      std::thread::hardware_concurrency()));
  return options;
}

inline static std::unique_lock<std::mutex> KeyShardGuard(std::string_view key) {
  return std::unique_lock<std::mutex>(gKeyShards[Hash32(key) % kNumKeyShards]);
}

// Convert an entity ID into big endian.
inline static mx::RawEntityId Canonicalize(mx::RawEntityId id) {
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

// NOTE(pag): `val` can be quite long. That's overall not a big issue for
//            RocksDB, and it can apply compression to reduce the problem. For
//            now, though, there's usually enough context being fed into
//            keys via other values for us to reduce the `val` string down into
//            two opaque summary integers without risk of collisions.
//
// NOTE(pag): The `32` size thing is a bit of a dumb hack. For file IDs, we use
//            SHA256, which we definitely *do* want to preserve, as we don't
//            have additional context (as mentioned above).
static void AccumulateValIntoKey(llvm::raw_string_ostream &os,
                                 const std::string &val) {
  if (val.size() > 32) {
    os << ':' << Hash64(val) << ':' << Hash32(val);
  } else {
    os << ':' << val;
  }
}

template <typename T>
static void AccumulateValIntoKey(llvm::raw_string_ostream &os, T val) {
  os << ':';
  if constexpr (std::is_enum_v<T>) {
    os << static_cast<std::underlying_type_t<T>>(val);
  } else if constexpr (std::is_integral_v<T>) {
    os << val;
  }
}

template <typename T>
struct Tag {};

// NOTE(pag): The parameter lists (following the tag and `index`) of the
//            following functions must be compatible with the parameter lists
//            of the `IdStore::GetOrCreate*` methods.

static mx::FragmentId MakeId(Tag<mx::FragmentId>, mx::RawEntityId index) {
  return mx::FragmentId(index);
}

static mx::FileId MakeId(Tag<mx::FileId>, mx::RawEntityId index,
                         const std::string & /* hash */) {
  return mx::FileId(index);
}

static mx::CompilationId MakeId(Tag<mx::CompilationId>, mx::RawEntityId index,
                                mx::RawEntityId file_id,
                                const std::string & /* hash */) {
  auto fid = mx::EntityId(file_id).Extract<mx::FileId>();
  CHECK(fid.has_value());

  return mx::CompilationId(index);
}

static mx::TypeId MakeId(Tag<mx::TypeId>, mx::RawEntityId index,
                         mx::TypeKind type_kind, uint32_t /* type_qualifiers */,
                         size_t /* num_tokens */,
                         const std::string & /* hash */) {
  return mx::TypeId(index, type_kind);
}

static bool IsReplaceable(const std::string &val) {
  if (val.size() <= sizeof(mx::RawEntityId)) {
    return false;
  }

  return val[sizeof(mx::RawEntityId)];
}

}  // namespace

struct IdConfig {
  // The key in the k/v store where the last value of this ID is stored.
  // A new database has no last value, so we initialize it to the
  // `min_value_inclusive`. When we close the database, we persist the present
  // value back into the k/v store.
  //
  // NOTE(pag): `metadata_name` should be prefixed by the `META:` namespace.
  const std::string metadata_name;

  // All IDs generated from this configuration will be "namespaced" by this
  // prefix in the k/v store. Namespacing aviods the potential for collisions.
  const std::string_view key_prefix;

  // `[min_value_inclusive, max_value_exclusive)` range of valid values that
  // we allow to be generated by `next_index`. These values correspond to
  // constraints in how we do bit packing of IDs in `mx::EntityId`.
  const mx::RawEntityId min_value_inclusive;
  const mx::RawEntityId max_value_exclusive;

  // The present value of this ID.
  std::atomic<mx::RawEntityId> next_index;

  inline IdConfig(const char *metadata_name_,
                  const char *key_prefix_,
                  mx::RawEntityId min_value_inclusive_,
                  mx::RawEntityId max_value_exclusive_)
      : metadata_name(metadata_name_),
        key_prefix(key_prefix_),
        min_value_inclusive(min_value_inclusive_),
        max_value_exclusive(max_value_exclusive_) {

    CHECK(metadata_name.starts_with("META:"));
    CHECK_NE(key_prefix, "META");
  }

  void Load(IdStoreImpl &);
  void Store(IdStoreImpl &);

  mx::RawEntityId NextProposedIndex(void) {
    auto proposed_index = next_index.fetch_add(1u);
    CHECK_GE(proposed_index, min_value_inclusive);
    CHECK_LT(proposed_index, max_value_exclusive);
    return proposed_index;
  }

  // Create a key for the KV store by concatenating several elements, separated
  // by `:`s.
  template <typename... Args>
  inline std::string Key(const Args&... args) {
    std::string key;
    llvm::raw_string_ostream key_os(key);
    key_os << key_prefix;
    (void(AccumulateValIntoKey(key_os, args)), ...);
    return key;
  }

  template <typename IdType, typename... Args>
  mx::RawEntityId PackAndCheckId(const Args&... args) {
    IdType id = MakeId(Tag<IdType>{}, NextProposedIndex(), args...);
    mx::EntityId eid(id);
    auto packed_id = eid.Pack();
    CHECK_NE(packed_id, mx::kInvalidEntityId);

    auto unpack = eid.Extract<IdType>();
    CHECK(unpack.has_value());
    CHECK(id == unpack.value());
    return packed_id;
  }
};

class IdStoreImpl {
 public:
  const std::unique_ptr<rocksdb::DB> rocks_db;
  rocksdb::ColumnFamilyHandle * const cf_handle;

  std::deque<IdConfig> configs;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  IdConfig &next_file_index;

  // The next translation unit ID that can be assigned.
  IdConfig &next_compilation_index;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  IdConfig &next_small_fragment_index;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  IdConfig &next_big_fragment_index;

  // The next type ID that can be assigned.
  IdConfig &next_small_type_index;
  IdConfig &next_big_type_index;

  // Initialize the `next_*` ids from the k/v store.
  void EnterNextIndices(void);

  // Store the `next_*` ids back to the k/v store.
  void ExitNextIndices(void);

  // Safely close RocksDB.
  void ExitRocksDB(void);

  static std::shared_ptr<IdStoreImpl> Open(std::filesystem::path path);

  ~IdStoreImpl(void) {
    ExitNextIndices();
    ExitRocksDB();
  }

  IdStoreImpl(rocksdb::DB *rocks_db_)
      : rocks_db(rocks_db_),
        cf_handle(rocks_db->DefaultColumnFamily()),
        next_file_index(configs.emplace_back(
            "META:NEXT_FILE_INDEX", "FID", 1u, mx::kMaxFileId)),
        next_compilation_index(configs.emplace_back(
            "META::NEXT_COMPILATION_INDEX", "CID", 1, mx::kMaxCompilationId)),
        next_small_fragment_index(configs.emplace_back(
            "META:NEXT_SMALL_FRAGMENT_INDEX", "SFI", mx::kMaxBigFragmentId,
            mx::MaxSmallFragmentId())),
        next_big_fragment_index(configs.emplace_back(
            "META:NEXT_BIG_FRAGMENT_INDEX", "BFI", 1, mx::kMaxBigFragmentId)),
        next_small_type_index(configs.emplace_back(
            "META::NEXT_SMALL_TYPE_INDEX", "STI", mx::kMaxBigTypeId,
            mx::kMaxSmallTypeId)),
        next_big_type_index(configs.emplace_back(
            "META::NEXT_BIG_TYPE_INDEX", "BTI", 1, mx::kMaxBigTypeId)) {
    EnterNextIndices();
  }

  // Set `val` to `key`.
  void UnlockedSet(const std::string &key, mx::RawEntityId val,
                   bool is_replaceable=false);

  // Implements a transactional get or set operation.
  template <typename MakeId>
  MaybeNewId<mx::RawEntityId> GetOrSet(
      const std::string &key, MakeId make_id, bool is_replaceable=false);

  template <typename IdType, typename... Args>
  MaybeNewId<mx::SpecificEntityId<IdType>> GetOrCreateId(
      IdConfig &config, Args&... args) {

    auto [found_id, is_new] = GetOrSet(
        config.Key(args...),
        [&] (void) {
          return config.PackAndCheckId<IdType>(args...);
        });

    auto maybe_eid = mx::EntityId(found_id).Extract<IdType>();
    CHECK(maybe_eid.has_value());
    return {maybe_eid.value(), is_new};
  }
};

// Load the current value of this id from the persistent k/v store.
void IdConfig::Load(IdStoreImpl &kv) {
  next_index.store(kv.GetOrSet(
      metadata_name,
      [=, this] (void) {
        return min_value_inclusive;
      }).first);
}

// Store the current value fo this id back to the persistent k/v store.
void IdConfig::Store(IdStoreImpl &kv) {
  kv.UnlockedSet(metadata_name, next_index.load());
}

// Initialize the `next_*` ids from the k/v store.
void IdStoreImpl::EnterNextIndices(void) {
  for (auto &config : configs) {
    config.Load(*this);
  }
}

// Store the metadata back to the database so that future executions of the
// indexer don't re-use already allocated indices.
void IdStoreImpl::ExitNextIndices(void) {
  for (auto &config : configs) {
    config.Store(*this);
  }
}

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

  rocksdb::DB *rocks_db_ptr = nullptr;
  auto status = rocksdb::DB::Open(DBOptions(), name, &rocks_db_ptr);

  CHECK(status.ok())
      << "Unable to open RocksDB database at " << abs_kvdir << ": "
      << status.ToString();

  auto db_ptr = std::make_shared<IdStoreImpl>(rocks_db_ptr);
  db_ptr_ref = db_ptr;
  return db_ptr;
}

// Safely close RocksDB.
void IdStoreImpl::ExitRocksDB(void) {
  LOG(INFO)
    << "Shutting down key-value engine";

  rocksdb::WaitForCompactOptions opts;
  opts.flush = true;
  opts.close_db = true;
  auto status = rocks_db->WaitForCompact(opts);
  LOG_IF(ERROR, !status.ok())
      << "Error closing key/value store: " << status.ToString();
}

// Set `val` to `key`.
void IdStoreImpl::UnlockedSet(const std::string &key, mx::RawEntityId id,
                              bool is_replaceable) {
  std::string val;
  IDMarshaller id_marshal;
  id_marshal.Store(id);
  id_marshal.LoadInto(val);
  if (is_replaceable) {
    val.push_back('\1');
  }
  CHECK(rocks_db->Put(kWriteOptions, key, val).ok());
}

// Core `GetOrSet` primitive used by higher-level APIs. If the request to create
// a new ID is marked as *not* replaceable, but it conflicts with a previous ID
// that *was* marked as replaceable, then we will pretend that the old ID is new
// and we'll unmark it.
template <typename MakeId>
MaybeNewId<mx::RawEntityId> IdStoreImpl::GetOrSet(
    const std::string &key, MakeId make_id, bool is_replaceable) {

  IDMarshaller id_marshal;
  std::string val;

  // Racy read, relying on RocksDB to implement the concurrency control.
  auto racy_get_status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (racy_get_status.ok() && val.size() >= sizeof(id_marshal)) {
    id_marshal.Store(val);
    IdStatus status = IdStatus::kExisting;
    auto found_id = id_marshal.Load();
    if (IsReplaceable(val) && !is_replaceable) {
      auto locker = KeyShardGuard(key);
      UnlockedSet(key, found_id, false  /* is_replaceable */);
      status = IdStatus::kExistingButReplaced;
    }
    return {found_id, status};
  }

  auto locker = KeyShardGuard(key);

  // Uncontended read, synchronized with concurrent `Put`s.
  auto locked_get_status = rocks_db->Get(kReadOptions, cf_handle, key, &val);
  if (locked_get_status.ok() && val.size() >= sizeof(id_marshal)) {
    id_marshal.Store(val);
    IdStatus status = IdStatus::kExisting;
    auto found_id = id_marshal.Load();
    if (IsReplaceable(val) && !is_replaceable) {
      UnlockedSet(key, found_id, false  /* is_replaceable */);
      status = IdStatus::kExistingButReplaced;
    }
    return {found_id, status};
  }

  auto invented_id = make_id();
  UnlockedSet(key, invented_id, is_replaceable);
  return {invented_id, IdStatus::kNew};
}

IdStore::~IdStore(void) {}

IdStore::IdStore(std::filesystem::path path) 
    : impl(IdStoreImpl::Open(path)) {}

// NOTE(pag): Here we need to track whether or not we can replace a fragment.
MaybeNewId<mx::PackedFragmentId> IdStore::GetOrCreateFragmentIdForHash(
    mx::RawEntityId context_id, std::string hash, size_t num_tokens,
    bool is_replaceable) {

  // "Big fragments" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  auto is_big_frag = num_tokens >= mx::kNumTokensInBigFragment;
  auto &config = is_big_frag ? impl->next_big_fragment_index :
                 impl->next_small_fragment_index;
  mx::RawEntityId max_id_val = is_big_frag ? mx::kMaxBigFragmentId : ~0ull;

  auto [found_id, is_new] = impl->GetOrSet(
        config.Key(context_id, num_tokens, hash),
        [&] (void) {
          return config.PackAndCheckId<mx::FragmentId>();
        },
        is_replaceable);

  auto maybe_eid = mx::EntityId(found_id).Extract<mx::FragmentId>();
  CHECK(maybe_eid.has_value());
  CHECK_LT(maybe_eid->fragment_id, max_id_val);

  return {maybe_eid.value(), is_new};
}

MaybeNewId<mx::PackedTypeId> IdStore::GetOrCreateTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers,
    std::string hash, size_t num_tokens) {

  // Big types will have IDs in the range [1, mx::kMaxBigTypeId) and small types
  // will have ids [mx::kMaxBigTypeId: 2^36 + mx::kMaxBigTypeId)
  return impl->GetOrCreateId<mx::TypeId>(
      (num_tokens >= mx::kNumTokensInBigType ? impl->next_big_type_index :
                                               impl->next_small_type_index),
      type_kind, type_qualifiers, num_tokens, hash);
}

// Get, or create and return, a file ID for the specific file contents hash.
MaybeNewId<mx::PackedFileId> IdStore::GetOrCreateFileIdForHash(
    std::string hash) {
  return impl->GetOrCreateId<mx::FileId>(impl->next_file_index, hash);
}

MaybeNewId<mx::PackedCompilationId> IdStore::GetOrCreateCompilationId(
    mx::RawEntityId file_id, std::string hash) {
  return impl->GetOrCreateId<mx::CompilationId>(
      impl->next_compilation_index, file_id, hash);
}

}  // namespace indexer