// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Database.h>

#include <array>
#include <atomic>
#include <cassert>
#include <chrono>
#include <deque>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>
#include <variant>
#include <zdict.h>
#include <zstd.h>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wuseless-cast"
#include <blockingconcurrentqueue.h>
#pragma GCC diagnostic pop

#include "SQLiteStore.h"
#include "ThreadLocal.h"
#include "Types.h"

namespace mx {
namespace {

// Fragment hashes are sharded by the file token index and with the file ID.
//
// In WAL journalling mode, SQLite locks B-Trees. Each table gets its own
// B-Tree root, and so by sharding the fragment hash table, which gets a lot
// of concurrent writes during indexing, we try to spread the load.
static constexpr size_t kNumIdShards = 256u;

// TODO(pag): Use a hash function that is the same across platforms.
static const std::hash<std::string> kStringHasher;

// Number of INSERT statements to try to add in a single transaction.
static constexpr size_t kMaxTransactionSize = 10000000u;

// Upper bound on the size of a trained entity dictionary.
static constexpr size_t kMaxDictionarySize = 112640;  // 110 KiB.

// The minimum size of the buffer used for training entity dictionaries.
static constexpr size_t kMinTrainingSetSize = 128ull * (1ull << 20ul);

static constexpr size_t kNumEntityCategories = NumEnumerators(EntityCategory{});

static std::mutex gDatabaseInitializationLock;

// Array of table names, so we aren't always recomputing them.
static std::array<std::string, kNumIdShards> gIndexToHashTableName;

struct PushbackSignal {};
struct ExitSignal {};
struct FlushSignal {};
using QueueItem = std::variant<
    std::monostate, ExitSignal, FlushSignal, PushbackSignal, EntityRecord
#ifndef __CDT_PARSER__
#define MX_RECORD_VARIANT_ENTRY(name) , name
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_RECORD_VARIANT_ENTRY)
#undef MX_RECORD_VARIANT_ENTRY
#endif
    >;

using Queue = moodycamel::BlockingConcurrentQueue<QueueItem>;

class Semaphore : public moodycamel::LightweightSemaphore {
 public:
  using moodycamel::LightweightSemaphore::LightweightSemaphore;
};

// Thread-local database connection.
class WriterThreadState {
 private:
  sqlite::Connection db;

  // Get/set a file/fragment/compilation ID index given a hash and a
  // contextual ID.
  std::array<std::optional<sqlite::Statement>, kNumIdShards>
      get_index, set_index;

  RawEntityId GetOrCreateId(
      RawEntityId proposed_id, RawEntityId context_id, std::string hash);

  RawEntityId GetOrCreateId(
      RawEntityId proposed_id, RawEntityId hash_a, RawEntityId hash_b,
      RawEntityId hash_c, size_t table);

 public:
  std::optional<RawEntityId> available_file_index;
  std::optional<RawEntityId> available_compilation_index;
  std::optional<RawEntityId> available_small_fragment_index;
  std::optional<RawEntityId> available_big_fragment_index;
  std::optional<RawEntityId> available_small_type_index;
  std::optional<RawEntityId> available_big_type_index;

  ~WriterThreadState(void) {}

  WriterThreadState(
      const std::filesystem::path &path)
      : db(path) {}

  RawEntityId GetOrCreateFileId(RawEntityId proposed_id, std::string hash);

  RawEntityId GetOrCreateFragmentId(RawEntityId proposed_id,
                                    RawEntityId file_tok_id,
                                    std::string hash);

  RawEntityId GetOrCreateTypeId(RawEntityId proposed_id,
                                mx::TypeKind type_kind,
                                uint32_t type_qualifiers,
                                std::string hash);

  RawEntityId GetOrCreateCompilationId(RawEntityId proposed_id,
                                       RawEntityId file_tok_id,
                                       std::string hash);
};

RawEntityId WriterThreadState::GetOrCreateId(
    RawEntityId proposed_id, RawEntityId hash_a, RawEntityId hash_b,
    RawEntityId hash_c, size_t table) {

  std::optional<sqlite::Statement> &get = get_index[table];
  std::optional<sqlite::Statement> &set = set_index[table];

  // We might not have prepared these statements for the current thread yet.
  if (!get) {
    get.emplace(db.Prepare(
        "SELECT index_ FROM " + gIndexToHashTableName[table] +
        " WHERE hash_a = ?1 AND hash_b = ?2 AND hash_c = ?3")),

    set.emplace(db.Prepare(
        "INSERT INTO " + gIndexToHashTableName[table] +
        " (index_, hash_a, hash_b, hash_c) "
        "VALUES (?1, ?2, ?3, ?4) "
        "ON CONFLICT DO UPDATE SET index_ = index_ "
        "RETURNING index_"));
  }

  RawEntityId id_out = kInvalidEntityId;

  // NOTE(pag): Use `BindValuesWithoutCopying` if we go back to BLOB-based
  //            hashes.

  // Racy read.
  get->BindValues(hash_a, hash_b, hash_c);
  if (get->ExecuteStep()) {
    get->Row().Columns(id_out);
  }
  get->Reset();

  // Transactional get/set.
  while (id_out == kInvalidEntityId) {
    set->BindValues(proposed_id, hash_a, hash_b, hash_c);
    if (set->ExecuteStep()) {
      set->Row().Columns(id_out);
    }
    set->Reset();
  }

  return id_out;
}

RawEntityId WriterThreadState::GetOrCreateId(
    RawEntityId proposed_id, RawEntityId context_id, std::string hash) {

  // Calculate which file table to index into.
  const uint64_t base_hash = kStringHasher(hash);
  const size_t table = base_hash % kNumIdShards;

  std::reverse(hash.begin(), hash.end());
  const uint64_t rev_hash = kStringHasher(hash);

  // Some bits of `base_hash` are already utilized for deduping in the table
  // name itself, so we'll go and bring in "new" bits from the `rev_hash`.
  uint64_t real_hash = ((base_hash / kNumIdShards) * kNumIdShards) +
                       (rev_hash % kNumIdShards);

  for (auto &c : hash) {
    c = ~c;
  }

  auto inv_hash = kStringHasher(hash);
  return GetOrCreateId(proposed_id, context_id, real_hash, inv_hash, table);
}

RawEntityId WriterThreadState::GetOrCreateFileId(
    RawEntityId proposed_id, std::string hash) {
  return GetOrCreateId(proposed_id, mx::kInvalidEntityId, std::move(hash));
}

RawEntityId WriterThreadState::GetOrCreateFragmentId(
    RawEntityId proposed_id, RawEntityId file_tok_id, std::string hash) {
  return GetOrCreateId(proposed_id, file_tok_id, std::move(hash));
}

RawEntityId WriterThreadState::GetOrCreateTypeId(RawEntityId proposed_id,
                                                 mx::TypeKind type_kind,
                                                 uint32_t type_qualifiers,
                                                 std::string hash) {
  uint64_t context_id = static_cast<uint64_t>(type_kind);
  context_id <<= 32u;
  context_id |= type_qualifiers;
  return GetOrCreateId(proposed_id, context_id, std::move(hash));
}

RawEntityId WriterThreadState::GetOrCreateCompilationId(
    RawEntityId proposed_id, RawEntityId file_id, std::string hash) {
  return GetOrCreateId(proposed_id, file_id, std::move(hash));
}

class BulkInserterState {
 public:

  // The `async.db` can only be used inside of the `bulk_insertion_thread`.
  sqlite::Connection db;

#define MX_DECLARE_INSERT_STMT(record) \
    sqlite::Statement INSERT_INTO_ ## record; \
    void DoInsertAsync(const record &r) { \
      if (InsertAsync(r, INSERT_INTO_ ## record)) { \
        INSERT_INTO_ ## record.Execute(); \
      } else { \
        INSERT_INTO_ ## record.Reset(); \
      } \
    } \
    bool InsertAsync(const record &, sqlite::Statement &); \
    static size_t SizeOfRecord(const record &r);

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
  MX_DECLARE_INSERT_STMT(EntityRecord)
#undef MX_DECLARE_INSERT_STMT

  BulkInserterState(std::filesystem::path db_path)
      : db(std::move(db_path))

#ifndef __CDT_PARSER__
#define MX_DEFINE_STMT(record) \
      , INSERT_INTO_ ## record(db.Prepare( \
        record::kInsertStatement))
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_STMT)
    MX_DEFINE_STMT(EntityRecord)
#undef MX_DEFINE_STMT
#endif
      {}  // End of constructor
};

// A set of compression contexts. Compression contexts aren't thread safe. We
// implement a lock-free mechanism using `AcquireContext` and `ReleaseContext`
// to get the next available context for a given thread.
struct DictionaryContext {

  // Should ideally more than the number of indexing threads.
  static constexpr size_t kNumContexts = 256u;

  std::atomic<size_t> next_context_index;
  std::array<std::atomic<ZSTD_CCtx *>, kNumContexts> contexts;

  DictionaryContext(void);
  ~DictionaryContext(void);

  // A kind of ticket-based busy loop to get a thread-specific context.
  std::pair<ZSTD_CCtx *, size_t> AcquireContext(void);

  // Put the context back for another thread to use.
  void ReleaseContext(std::pair<ZSTD_CCtx *, size_t> c);
};

DictionaryContext::DictionaryContext(void) {
  for (auto &context : contexts) {
    context.store(ZSTD_createCCtx(), std::memory_order_relaxed);
  }
}

DictionaryContext::~DictionaryContext(void) {
  for (auto &context : contexts) {
    ZSTD_freeCCtx(context.load(std::memory_order_relaxed));
  }
}

// A kind of ticket-based busy loop to get a thread-specific context.
std::pair<ZSTD_CCtx *, size_t> DictionaryContext::AcquireContext(void) {
  ZSTD_CCtx *context = nullptr;
  size_t context_index = 0u;

  for (auto num_failed = 0u; !context; ++num_failed) {
    context_index = next_context_index.fetch_add(1u) % kNumContexts;
    context = contexts[context_index].load(std::memory_order_acquire);
    if (!context) {
      continue;
    }

    if (num_failed > 8u) {
      if (!contexts[context_index].compare_exchange_strong(context, nullptr)) {
        context = nullptr;
      }
    } else {
      if (!contexts[context_index].compare_exchange_weak(context, nullptr)) {
        context = nullptr;
      }
    }
  }

  return {context, context_index};
}

// Put the context back for another thread to use.
void DictionaryContext::ReleaseContext(std::pair<ZSTD_CCtx *, size_t> c) {
  contexts[c.second].store(c.first, std::memory_order_release);
}

}  // namespace


struct DictionaryCompressor {

  // The ZSTD dictionary to use to compress an entity record. If this contains
  // `nullptr` then it means we're in training mode and we haven't yet made the
  // dictionary.
  std::atomic<ZSTD_CDict *> dict;

  // Lock over `training_data`, etc.
  std::mutex lock;

  // Training data. We accumulate the (uncompressed) `EntityRecord::data` into
  // `training_data`. `data_sizes` contains the size of each record entry, and
  // `entity_ids` holds the entity IDs of each record. This is a format that
  // is compatible with ZSTD dictionary training, as well as `CompressAndAdd`.
  std::string training_data;
  std::vector<size_t> data_sizes;
  std::vector<RawEntityId> entity_ids;

  DictionaryCompressor(void);
  ~DictionaryCompressor(void);

  // Initialize this `EntityDictionary` with a pre-trained dictionary taken
  // from the database.
  void InitFromSavedDictionary(std::string data);

  // Empty initialization, we have no dictionary and we need to create one.
  void InitWithoutDictionary(void);

  // Build the dictionary if it hasn't yet been built. This will enqueue any
  // pending records to `queue`.
  void Build(DatabaseWriterImpl &impl, DictionaryContext &context,
             std::unique_lock<std::mutex> locker);

  // Add `record`, either as a pending item for training a dictionary, or passed
  // through to `CompressAndAdd`.
  void Add(DatabaseWriterImpl &impl, DictionaryContext &context,
           EntityRecord record);

  void CompressAndAdd(DatabaseWriterImpl &impl, DictionaryContext &context,
                      EntityRecord record, ZSTD_CDict *d);

  void CompressAndAdd(DatabaseWriterImpl &impl, DictionaryContext &context,
                      RawEntityId id, const void *data,
                      size_t data_size, ZSTD_CDict *d);

  void CompressAndAdd(DatabaseWriterImpl &impl, RawEntityId id,
                      const void *data,
                      size_t data_size, ZSTD_CDict *d, ZSTD_CCtx *context);
};

class DatabaseWriterImpl {
 public:
  const std::filesystem::path db_path;

  // Maximum size in bytes of the writer queue.
  const size_t max_queue_size_in_bytes;

  // Semaphore to wake up a blocked writer thread.
  Semaphore pushback_signal;

  // The connection used on construction.
  sqlite::Connection db;

  // Add some version info to the database. The number of records in the
  // versions table tells us whether or not we're currently indexing.
  sqlite::Statement add_version;

  // Get the latest copies of file and fragment ids.
  sqlite::Statement get_ids;

  // Update the metadata.
  sqlite::Statement update_meta_stmt;

  // Per-thread connection state with the database.
  ThreadLocal<WriterThreadState> thread_state;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  std::atomic<RawEntityId> next_file_index;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  std::atomic<RawEntityId> next_small_fragment_index;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  std::atomic<RawEntityId> next_big_fragment_index;

  // The next type ID that can be assigned.
  std::atomic<RawEntityId> next_small_type_index;
  std::atomic<RawEntityId> next_big_type_index;

  // The next translation unit ID that can be assigned. This
  std::atomic<RawEntityId> next_compilation_index;

  // Entity-specific compression dictionaries.
  DictionaryContext dictionary_context;
  std::array<DictionaryCompressor, kNumEntityCategories> entity_dictionaries;

  // Number of rows pending insertion.
  std::atomic<size_t> num_total_rows;

  // A thread and it's multiple-producer, single-consumer.
  Queue insertion_queue;
  std::thread bulk_insertion_thread;

  // Number of bytes that in the queue, and number that are in-flight.
  std::atomic<size_t> pending_bytes;

  DatabaseWriterImpl(const std::filesystem::path &db_path_,
                     size_t max_queue_size_in_bytes_);

  ~DatabaseWriterImpl(void);

  void BulkInserter(void);

  void InitDictionaries(void);
  void ExitDictionaries(void);

  void InitMetadata(void);
  void ExitMetadata(void);

  void InitRecords(void);
  void ExitRecords(void);

#define MX_DECLARE_INSERT_STMT(record) \
    void DoAddAsync(record r);

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
  MX_DECLARE_INSERT_STMT(EntityRecord)
#undef MX_DECLARE_INSERT_STMT
};

DictionaryCompressor::DictionaryCompressor(void)
    : dict(nullptr) {}

DictionaryCompressor::~DictionaryCompressor(void) {
  if (auto d = dict.load()) {
    ZSTD_freeCDict(d);
  }
}

// Initialize this `EntityDictionary` with a pre-trained dictionary taken
// from the database.
void DictionaryCompressor::InitFromSavedDictionary(std::string data) {
  assert(data.size() <= kMaxDictionarySize);
  dict.store(ZSTD_createCDict(data.data(), data.size(), ZSTD_maxCLevel()));
}

// Empty initialization, we have no dictionary and we need to create one.
void DictionaryCompressor::InitWithoutDictionary(void) {
  training_data.reserve(kMinTrainingSetSize + 8192u);
}

void DictionaryCompressor::CompressAndAdd(
    DatabaseWriterImpl &impl, RawEntityId id, const void *data,
    size_t data_size, ZSTD_CDict *d, ZSTD_CCtx *context) {

  EntityRecord record;
  record.id = id;

  const size_t maybe_compressed_data_size = ZSTD_compressBound(data_size);
  record.data.resize(maybe_compressed_data_size);

  auto compressed_data_size = ZSTD_compress_usingCDict(
      context,
      record.data.data(), maybe_compressed_data_size,
      data, data_size,
      d);

  assert(!ZSTD_isError(compressed_data_size));
  record.data.resize(compressed_data_size);

  // Swap the uncompressed data with the compressed data, and add it to the
  // bulk insertion queue.
  impl.DoAddAsync(std::move(record));
}

void DictionaryCompressor::CompressAndAdd(
    DatabaseWriterImpl &impl, DictionaryContext &context, RawEntityId id,
    const void *data, size_t data_size, ZSTD_CDict *d) {
  auto context_and_index = context.AcquireContext();
  CompressAndAdd(impl, id, data, data_size, d, context_and_index.first);
  context.ReleaseContext(context_and_index);
}

// Compress the data from `record`, then add it to our insertion queue.
void DictionaryCompressor::CompressAndAdd(
    DatabaseWriterImpl &impl, DictionaryContext &context, EntityRecord record,
    ZSTD_CDict *d) {
  CompressAndAdd(impl, context, record.id, record.data.data(),
                 record.data.size(), d);
}

// Add `record`, either as a pending item for training a dictionary, or passed
// through to `CompressAndAdd`.
void DictionaryCompressor::Add(DatabaseWriterImpl &impl,
                               DictionaryContext &context,
                               EntityRecord record) {

  // If we already have a dictionary, then use it.
  if (ZSTD_CDict *d = dict.load(std::memory_order_acquire)) {
    CompressAndAdd(impl, context, std::move(record), d);
    return;
  }

  std::unique_lock<std::mutex> locker(lock);

  // If there was a race condition and if the dictionary has been created in the
  // time that it took to acquire the lock, then use it to add the record.
  if (ZSTD_CDict *d = dict.load(std::memory_order_relaxed)) {
    locker.unlock();
    CompressAndAdd(impl, context, std::move(record), d);
    return;
  }

  // We don't yet have a dictionary. In this case, we collect the data into
  // a format that allows us to reconstruct the (compressed) records later,
  // while also being able to train a ZSTD dictionary.
  training_data.append(record.data);
  data_sizes.push_back(record.data.size());
  entity_ids.push_back(record.id);

  // If we haven't yet collected enough training data then stop here.
  if (training_data.size() < kMinTrainingSetSize) {
    return;
  }

  Build(impl, context, std::move(locker));
}

// Build the dictionary if it hasn't yet been built. This will enqueue any
// pending records to `queue`.
void DictionaryCompressor::Build(DatabaseWriterImpl &impl,
                                 DictionaryContext &context,
                                 std::unique_lock<std::mutex> locker) {

  if (dict.load(std::memory_order_relaxed)) {
    return;  // Don't re-build a dictionary.
  }

  const char *record_data = training_data.data();
  const auto num_records = static_cast<unsigned>(data_sizes.size());

  if (!num_records) {
    return;  // Don't build an empty dictionary.
  }

  DictionaryRecord dictionary;
  dictionary.category = CategoryFromEntityId(entity_ids[0]);

  // Train a ZSTD dictionary on our training set of entity records.
  dictionary.data.resize(kMaxDictionarySize);

  size_t dictionary_size = 0;

  if (training_data.size() <= kMaxDictionarySize) {
    dictionary_size = ZDICT_trainFromBuffer(
        dictionary.data.data(), training_data.size(),
        record_data, data_sizes.data(), num_records);

  } else {
    dictionary_size = ZDICT_trainFromBuffer(
        dictionary.data.data(), kMaxDictionarySize,
        record_data, data_sizes.data(), num_records);
  }

  ZSTD_CDict *compression_dict = nullptr;

  // Likely the training set is too small; this is unfortunate because it means
  // we commit to an empty dictionary forevermore.
  if (ZSTD_isError(dictionary_size)) {
    compression_dict = ZSTD_createCDict("", 0, ZSTD_maxCLevel());
    dictionary.data.clear();

  } else {
    assert(dictionary_size <= dictionary.data.size());

    // TODO(pag): Try `ZDICT_finalizeDictionary`?
    // ZDICT_params_t params;
    // params.compressionLevel = ZSTD_maxCLevel();
    // params.notificationLevel = 0;
    // params.dictID = static_cast<unsigned>(dictionary.category);

    dictionary.data.resize(dictionary_size);

    // Publish the newly trained dictionary so that other threads can immediately
    // benefit from it. This will unlock the mutex and let any blocked threads
    // proceed with the new dictionary. Their racy check will pick up the now-
    // published dictionary.
    compression_dict = ZSTD_createCDict(
        dictionary.data.data(), dictionary_size,
        ZSTD_maxCLevel());
  }

  dict.store(compression_dict, std::memory_order_release);
  locker.unlock();

  // Persist the dictionary.
  impl.DoAddAsync(std::move(dictionary));

  // Now use it locally.
  auto context_and_index = context.AcquireContext();

  // Compress and add all of the training records.
  for (auto i = 0u; i < num_records; ++i) {
    auto record_id = entity_ids[i];
    auto record_data_size = data_sizes[i];
    CompressAndAdd(impl, record_id, record_data, record_data_size,
                   compression_dict, context_and_index.first);
    record_data = &(record_data[record_data_size]);
  }

  context.ReleaseContext(context_and_index);

  // Force free the training resources.
  std::vector<RawEntityId>().swap(entity_ids);
  std::vector<size_t>().swap(data_sizes);
  std::string().swap(training_data);
}

void DatabaseWriterImpl::ExitMetadata(void) {
  add_version.BindValues(0u);
  add_version.Execute();

  // Update the metadata.
  update_meta_stmt.BindValues(
      next_file_index.load(),
      next_small_fragment_index.load(),
      next_big_fragment_index.load(),
      next_small_type_index.load(),
      next_big_type_index.load(),
      next_compilation_index.load());
  update_meta_stmt.Execute();
}

// Load in the dictionaries.
void DatabaseWriterImpl::InitDictionaries(void) {
  sqlite::Statement dictionaries = db.Prepare(
      "SELECT entity_category, data FROM entity_dictionary");

  while (dictionaries.ExecuteStep()) {
    unsigned category = 0u;
    std::string data;
    dictionaries.Row().Columns(category, data);
    if (!category || category >= kNumEntityCategories) {
      assert(false);
      continue;
    }

    DictionaryCompressor &dict = entity_dictionaries[category];
    dict.InitFromSavedDictionary(std::move(data));
  }

  dictionaries.Reset();

  // Initialize the empty dictionaries.
  for (auto i = 1u; i < kNumEntityCategories; ++i) {
    DictionaryCompressor &dict = entity_dictionaries[i];
    if (!dict.dict.load(std::memory_order_relaxed)) {
      dict.InitWithoutDictionary();
    }
  }
}

void DatabaseWriterImpl::ExitDictionaries(void) {
  for (auto i = 1u; i < kNumEntityCategories; ++i) {
    DictionaryCompressor &dict = entity_dictionaries[i];
    dict.Build(*this, dictionary_context,
               std::unique_lock<std::mutex>(dict.lock));
  }
}

// Initialize the metadata table. It only stores one row of data.
void DatabaseWriterImpl::InitMetadata(void) {

  // Initialize the default metadata. The trick we use here is that we hard-code
  // a `rowid` of `1`, and so the implicit primary key constraint on `rowid`
  // will cause repeated initializations to be ignored.
  sqlite::Statement set_meta_stmt = db.Prepare(
      R"(INSERT OR IGNORE INTO metadata 
         (rowid, next_file_index, next_small_fragment_index,
          next_big_fragment_index, next_small_type_index,
          next_big_type_index, next_compilation_index)
          VALUES (1, 1, ?1, 1, ?2, 1, 1))");

  set_meta_stmt.BindValues(
      mx::kMaxBigFragmentId  /* next_small_fragment_index */,
      mx::kMaxBigTypeId /* next_small_type_index */);
  set_meta_stmt.Execute();

  add_version.BindValues(1u);
  add_version.Execute();

  // TODO(pag): Really, we need a way to "reserve" some ranges of IDs for
  //            use to support concurrent writers. We could achieve this by
  //            doing an UPDATE that atomically increments all the IDs by
  //            the reservation amount, or having multiple rows in the
  //            metadata table, where each row is a reservation.
  RawEntityId file_id = kInvalidEntityId;
  RawEntityId small_id = kInvalidEntityId;
  RawEntityId big_id = kInvalidEntityId;
  RawEntityId small_type_id = kInvalidEntityId;
  RawEntityId big_type_id = kInvalidEntityId;
  RawEntityId tu_id = kInvalidEntityId;

  if (get_ids.ExecuteStep()) {
    get_ids.Row().Columns(file_id, small_id, big_id, small_type_id, big_type_id,
                          tu_id);

    assert(1u <= file_id);
    assert(mx::kMaxBigFragmentId <= small_id);
    assert(1u <= big_id);
    assert(big_id < mx::kMaxBigFragmentId);
    assert(mx::kMaxBigTypeId <= small_type_id);
    assert(1u <= big_type_id);
    assert(big_type_id < mx::kMaxBigTypeId);
    assert(1u <= tu_id);

    next_file_index.store(file_id);
    next_small_fragment_index.store(small_id);
    next_big_fragment_index.store(big_id);
    next_small_type_index.store(small_type_id);
    next_big_type_index.store(big_type_id);
    next_compilation_index.store(tu_id);

  // TODO(pag): Throw an exception?
  } else {
    assert(false);
  }

  get_ids.Reset();
}

void DatabaseWriterImpl::BulkInserter(void) {
  BulkInserterState async(db_path);

  bool should_exit{false};
  bool should_flush{false};
  size_t num_added_rows = 0u;
  size_t num_in_flight_bytes = 0u;
  ssize_t num_pushbacks = 0;

  std::vector<QueueItem> pending_items;
  std::vector<Semaphore *> pushback_signals;

  for (; !should_exit || num_added_rows < num_total_rows.load();
       should_flush = false) {

//    std::cerr
//        << "should_exit=" << should_exit << " num_added_rows="
//        << num_added_rows << " num_total_rows=" << num_total_rows.load()
//        << " num_in_flight_bytes=" << num_in_flight_bytes
//        << " num_pushbacks=" << num_pushbacks << '\n';

    // Get rid of the last transaction's data.
    pending_items.clear();
    pending_bytes.fetch_sub(num_in_flight_bytes);
    num_in_flight_bytes = 0u;

    // Signal blocked threads that they can wake up now. They wait until a
    // timeout is reached, or until the write queue is empty.
    //
    // TODO(pag): There is a race condition where the `signal` might execute
    //            prior to the `wait`. The issue is that the writer adds a
    //            `PushbackSignal` to our queue, then the writer `wait`s on
    //            `pushback_signal`. The writer could be interrupted prior to
    //            the `wait`, and the signal here could be sent out prior to
    //            the writer resuming its execution. To try to mitigate this,
    //            we have a 10s timed wait in the writer, and then the writer
    //            wakes up. That might result in other problems, where there
    //            are more signals than waits.. but I don't have a good solution
    //            for this.
    if (num_pushbacks &&
        (num_added_rows + kMaxTransactionSize) >= num_total_rows.load()) {
      pushback_signal.signal(num_pushbacks);
      num_pushbacks = 0;
    }

    // Go get the first thing.
    QueueItem item;
    if (!insertion_queue.wait_dequeue_timed(item, 10 * 1000)) {
      continue;
    }

    sqlite::Transaction transaction(async.db);
    size_t transaction_size = 0u;

    do {

      // Keep the data alive as long as this transaction is alive.
      const QueueItem &saved_item = pending_items.emplace_back(std::move(item));

      std::visit(
          [&] (const auto &arg) {
            using arg_t = std::decay_t<decltype(arg)>;

            // Shouldn't happen.
            if constexpr (std::is_same_v<std::monostate, arg_t>) {

            // Exit signal.
            } else if constexpr (std::is_same_v<ExitSignal, arg_t>) {
              should_exit = true;
              should_flush = true;

            // Build signal.
            } else if constexpr (std::is_same_v<FlushSignal, arg_t>) {
              should_flush = true;

            // Signal a blocked inserter that they can retry.
            } else if constexpr (std::is_same_v<PushbackSignal, arg_t>) {
              num_pushbacks++;

            } else {
              num_in_flight_bytes += async.SizeOfRecord(arg);
              async.DoInsertAsync(arg);
              ++transaction_size;
            }
          },
          saved_item);

      if (transaction_size >= kMaxTransactionSize) {
        should_flush = true;
      }

      if (should_flush) {
        break;
      }

    // Try to get the next thing.
    } while (insertion_queue.try_dequeue(item) ||
             insertion_queue.wait_dequeue_timed(item, 10 * 1000));

    num_added_rows += transaction_size;
  }

  pending_bytes.fetch_sub(num_in_flight_bytes);
  if (num_pushbacks) {
    pushback_signal.signal(num_pushbacks);
  }
}

namespace {

// XREF(pag): Issue #251: we see issues when we try to prepare statements in
//            other threads. The initial mitigation was to always put the
//            database for indexing in `/tmp`, which is memory-backed.
//
// NOTE(frabert): Solution idea was to close the connection that created the
//                database first. We achieve that via the destruction of
//                `db` here, and returning the path to re-open to the caller.
std::filesystem::path CreateDatabase(const std::filesystem::path &db_path_) {
  std::unique_lock<std::mutex> locker(gDatabaseInitializationLock);

  sqlite::Connection db(db_path_);
  for (const char *stmt : DatabaseWriter::kInitStatements) {
    db.Execute(std::string(stmt));
  }
  for (size_t i = 0u; i < kNumIdShards; ++i) {
    std::string &name = gIndexToHashTableName[i];
    if (name.empty()) {
      name = "index_for_hash_" + std::to_string(i);
    }

    db.Execute(
        "CREATE TABLE IF NOT EXISTS " + name + " ("
        "  index_ INT NOT NULL,"
        "  hash_a INT NOT NULL,"
        "  hash_b INT NOT NULL,"
        "  hash_c INT NOT NULL,"
        "  PRIMARY KEY(hash_a, hash_b, hash_c)"
        ") WITHOUT rowid");


  }

  db.Execute("PRAGMA wal_checkpoint(FULL)");

  return db_path_;
}

}  // namespace

DatabaseWriterImpl::~DatabaseWriterImpl(void) {

  ExitDictionaries();

  insertion_queue.enqueue(ExitSignal{});
  bulk_insertion_thread.join();

//  for (const char *stmt : DatabaseWriter::kExitStatments) {
//    db.Execute(stmt);
//  }

  ExitRecords();
  ExitMetadata();
  db.Execute("PRAGMA wal_checkpoint(FULL)");
  db.Optimize();
}

DatabaseWriterImpl::DatabaseWriterImpl(const std::filesystem::path &db_path_,
                                       size_t max_queue_size_in_bytes_)
    : db_path(db_path_),
      max_queue_size_in_bytes(max_queue_size_in_bytes_),
      db(CreateDatabase(db_path)),
      add_version(db.Prepare(
          R"(INSERT INTO version (action) VALUES (?1))")),
      get_ids(db.Prepare(
          R"(SELECT next_file_index, next_small_fragment_index, 
                    next_big_fragment_index, next_small_type_index,
                    next_big_type_index, next_compilation_index
             FROM metadata
             WHERE rowid = 1
             LIMIT 1)")),
      update_meta_stmt(db.Prepare(
          R"(UPDATE metadata
             SET next_file_index = ?1,
                 next_small_fragment_index = ?2,
                 next_big_fragment_index = ?3,
                 next_small_type_index = ?4,
                 next_big_type_index = ?5,
                 next_compilation_index = ?6
             WHERE rowid = 1)")),
      thread_state(
          [this] (unsigned) -> WriterThreadState * {
             return new WriterThreadState(db_path);
          },
          [] (void *ptr) {
            delete reinterpret_cast<WriterThreadState *>(ptr);
          }),
      insertion_queue(kMaxTransactionSize) {

  InitMetadata();
  InitRecords();
  InitDictionaries();

  bulk_insertion_thread = std::thread([this] (void) {
    this->BulkInserter();
  });
}

size_t BulkInserterState::SizeOfRecord(const DictionaryRecord &record) {
  return sizeof(record) + record.data.size();
}

bool BulkInserterState::InsertAsync(
    const DictionaryRecord &record, sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(static_cast<unsigned>(record.category),
                                  record.data);
  return true;
}

size_t BulkInserterState::SizeOfRecord(const FilePathRecord &record) {
  return sizeof(record) + record.path.size();
}

bool BulkInserterState::InsertAsync(
    const FilePathRecord &record, sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(record.file_id.Pack(), record.path);
  return true;
}

size_t BulkInserterState::SizeOfRecord(const FragmentFileRecord &record) {
  return sizeof(record);
}

bool BulkInserterState::InsertAsync(
    const FragmentFileRecord &record, sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(record.fragment_id.Pack(),
                                  record.file_id.Pack());
  return true;
}

size_t BulkInserterState::SizeOfRecord(const NestedFragmentRecord &record) {
  return sizeof(record);
}

bool BulkInserterState::InsertAsync(
    const NestedFragmentRecord &record, sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(record.parent_id.Pack(),
                                  record.child_id.Pack());
  return true;
}

size_t BulkInserterState::SizeOfRecord(const FragmentFileRangeRecord &record) {
  return sizeof(record);
}

bool BulkInserterState::InsertAsync(
    const FragmentFileRangeRecord &record, sqlite::Statement &insert) {
  FileTokenId begin = record.first_file_token.Unpack();
  FileTokenId end = record.last_file_token.Unpack();
  assert(begin.file_id == end.file_id);
  FileId fid(begin.file_id);
  insert.BindValuesWithoutCopying(
      record.fragment_id.Pack(), begin.offset, end.offset,
      EntityId(fid).Pack());
  return true;
}

size_t BulkInserterState::SizeOfRecord(const RedeclarationRecord &record) {
  return sizeof(record);
}

bool BulkInserterState::InsertAsync(
    const RedeclarationRecord &record, sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(
      record.decl_id.Pack(), record.redecl_id.Pack());
  return true;
}

size_t BulkInserterState::SizeOfRecord(const MangledNameRecord &record) {
  return sizeof(record) + record.mangled_name.size();
}

bool BulkInserterState::InsertAsync(
    const MangledNameRecord &record, sqlite::Statement &insert) {
  if (record.entity_id != mx::kInvalidEntityId &&
      !record.mangled_name.empty()) {
    insert.BindValuesWithoutCopying(record.entity_id, record.mangled_name);
    return true;
  }
  return false;
}

size_t BulkInserterState::SizeOfRecord(const ReferenceRecord &record) {
  return sizeof(record);
}

bool BulkInserterState::InsertAsync(
    const ReferenceRecord &record, sqlite::Statement &insert) {
  if (record.from_entity_id != kInvalidEntityId &&
      record.to_entity_id != kInvalidEntityId) {
    insert.BindValuesWithoutCopying(record.from_entity_id,
                                    record.to_entity_id,
                                    record.context_id,
                                    static_cast<unsigned>(record.kind));
    return true;
  }
  return false;
}

size_t BulkInserterState::SizeOfRecord(const NamedEntityRecord &record) {
  return sizeof(record) + record.name.size();
}

bool BulkInserterState::InsertAsync(
    const NamedEntityRecord &record, sqlite::Statement &insert) {
  if (!record.name.empty()) {
    insert.BindValuesWithoutCopying(record.entity_id, record.name);
    return true;
  }
  return false;
}

size_t BulkInserterState::SizeOfRecord(const EntityRecord &record) {
  return sizeof(record) + record.data.size();
}

bool BulkInserterState::InsertAsync(const EntityRecord &record,
                                    sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(record.id, record.data);
  return true;
}

DatabaseWriter::DatabaseWriter(std::filesystem::path db_path,
                               size_t max_queue_size_in_bytes)
    : impl(std::make_shared<DatabaseWriterImpl>(
          db_path, max_queue_size_in_bytes)) {}

DatabaseWriter::~DatabaseWriter(void) {}

void DatabaseWriter::AsyncFlush(void) {
  impl->insertion_queue.enqueue(FlushSignal{});
}

// Get, or create and return, a file ID for the specific file contents hash.
PackedFileId DatabaseWriter::GetOrCreateFileIdForHash(
    std::string hash, bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_index = kInvalidEntityId;

  // Try to reuse a previously generated but unused file id.
  if (!writer->available_file_index) {
    proposed_index = impl->next_file_index.fetch_add(1u);
  } else {
    proposed_index = writer->available_file_index.value();
    writer->available_file_index.reset();
  }

  RawEntityId proposed_id = EntityId(FileId(proposed_index)).Pack();
  RawEntityId found_id = writer->GetOrCreateFileId(proposed_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_file_index.emplace(proposed_index);
  }

  VariantId vid = EntityId(found_id).Unpack();
  assert(std::holds_alternative<FileId>(vid));
  return std::get<FileId>(vid);
}

// Get, or create and return, a fragment ID for the specific fragment hash.
PackedFragmentId DatabaseWriter::GetOrCreateSmallFragmentIdForHash(
    RawEntityId tok_id, std::string hash, bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_index = kInvalidEntityId;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_small_fragment_index) {
    proposed_index = impl->next_small_fragment_index.fetch_add(1u);
  } else {
    proposed_index = writer->available_small_fragment_index.value();
    writer->available_small_fragment_index.reset();
  }
  assert(proposed_index >= kMaxBigFragmentId);

  RawEntityId proposed_id = EntityId(FragmentId(proposed_index)).Pack();
  RawEntityId found_id = writer->GetOrCreateFragmentId(
      proposed_id, tok_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_small_fragment_index.emplace(proposed_index);
  }

  VariantId vid = EntityId(found_id).Unpack();
  assert(std::holds_alternative<FragmentId>(vid));
  FragmentId fid = std::get<FragmentId>(vid);
  assert(fid.fragment_id >= kMaxBigFragmentId);
  return fid;
}

// Get, or create and return, a fragment ID for the specific fragment hash.
PackedFragmentId DatabaseWriter::GetOrCreateBigFragmentIdForHash(
    RawEntityId tok_id, std::string hash, bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_index = kInvalidEntityId;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_big_fragment_index) {
    proposed_index = impl->next_big_fragment_index.fetch_add(1u);
  } else {
    proposed_index = writer->available_big_fragment_index.value();
    writer->available_big_fragment_index.reset();
  }

  assert(proposed_index < kMaxBigFragmentId);

  RawEntityId proposed_id = EntityId(FragmentId(proposed_index)).Pack();
  RawEntityId found_id = writer->GetOrCreateFragmentId(
      proposed_id, tok_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_big_fragment_index.emplace(proposed_index);
  }

  VariantId vid = EntityId(found_id).Unpack();
  assert(std::holds_alternative<FragmentId>(vid));
  FragmentId fid = std::get<FragmentId>(vid);
  assert(fid.fragment_id < kMaxBigFragmentId);
  return fid;
}

PackedFragmentId DatabaseWriter::GetOrCreateFragmentIdForHash(
    RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new) {

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  //
  // NOTE(pag): We have a fudge factor here of `3x` to account for macro
  //            expansions.
  if ((num_tokens * 3u) >= kNumTokensInBigFragment) {
    return GetOrCreateBigFragmentIdForHash(tok_id, std::move(hash), is_new);
  } else {
    return GetOrCreateSmallFragmentIdForHash(tok_id, std::move(hash), is_new);
  }
}

PackedTypeId DatabaseWriter::GetOrCreateSmallTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, std::string hash,
    bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_index = kInvalidEntityId;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_small_type_index) {
    proposed_index = impl->next_small_type_index.fetch_add(1u);
  } else {
    proposed_index = writer->available_small_type_index.value();
    writer->available_small_type_index.reset();
  }
  assert(proposed_index >= kMaxBigTypeId);

  RawEntityId proposed_id = EntityId(TypeId(proposed_index, type_kind)).Pack();
  RawEntityId found_id = writer->GetOrCreateTypeId(
      proposed_id, type_kind, type_qualifiers, std::move(hash));

  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_small_type_index.emplace(proposed_index);
  }

  VariantId vid = EntityId(found_id).Unpack();
  assert(std::holds_alternative<TypeId>(vid));
  return std::get<TypeId>(vid);
}

PackedTypeId DatabaseWriter::GetOrCreateBigTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers, std::string hash,
    bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_index = kInvalidEntityId;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_big_type_index) {
    proposed_index = impl->next_big_type_index.fetch_add(1u);
  } else {
    proposed_index = writer->available_big_type_index.value();
    writer->available_big_type_index.reset();
  }
  assert(proposed_index < kMaxBigTypeId);

  RawEntityId proposed_id = EntityId(TypeId(proposed_index, type_kind)).Pack();
  RawEntityId found_id = writer->GetOrCreateTypeId(
      proposed_id, type_kind, type_qualifiers, std::move(hash));

  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_big_type_index.emplace(proposed_index);
  }

  VariantId vid = EntityId(found_id).Unpack();
  assert(std::holds_alternative<TypeId>(vid));
  return std::get<TypeId>(vid);
}

PackedTypeId DatabaseWriter::GetOrCreateTypeIdForHash(
    mx::TypeKind type_kind, uint32_t type_qualifiers,
    std::string hash, size_t num_tokens,
    bool &is_new) {

  // Big types will have IDs in the range [1, mx::kMaxBigTypeId) and small types
  // will have ids [mx::kMaxBigTypeId: 2^36 + mx::kMaxBigTypeId)
  if (num_tokens >= kNumMinTokensInBigType) {
    return GetOrCreateBigTypeIdForHash(type_kind, type_qualifiers,
                                       std::move(hash), is_new);
  } else {
    return GetOrCreateSmallTypeIdForHash(type_kind, type_qualifiers,
                                         std::move(hash), is_new);
  }
}

PackedCompilationId DatabaseWriter::GetOrCreateCompilationId(
    RawEntityId file_id, std::string hash, bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_index = kInvalidEntityId;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_compilation_index) {
    proposed_index = impl->next_compilation_index.fetch_add(1u);
  } else {
    proposed_index = writer->available_compilation_index.value();
    writer->available_compilation_index.reset();
  }

  assert(proposed_index < kMaxCompilationId);

  std::optional<FileId> fid = EntityId(file_id).Extract<FileId>();
  assert(fid.has_value());

  CompilationId cid;
  cid.compilation_id = proposed_index;
  cid.file_id = fid->file_id;

  RawEntityId proposed_id = EntityId(cid).Pack();
  RawEntityId found_id = writer->GetOrCreateCompilationId(
      proposed_id, file_id, std::move(hash));

  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_compilation_index.emplace(proposed_index);

    VariantId vid = EntityId(found_id).Unpack();
    assert(std::holds_alternative<CompilationId>(vid));
    cid = std::get<CompilationId>(vid);
    assert(cid.compilation_id < kMaxCompilationId);
  }

  return cid;
}

void DatabaseWriterImpl::InitRecords(void) {
#ifndef __CDT_PARSER__
#define MX_EXEC_INITS(record) \
  for (const char *stmt : record::kInitStatements) { \
    if (stmt) { \
      db.Execute(stmt); \
    } \
  }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_EXEC_INITS)
  MX_EXEC_INITS(EntityRecord)
#undef MX_EXEC_INITS
#endif
}

void DatabaseWriterImpl::ExitRecords(void) {
#ifndef __CDT_PARSER__
#define MX_EXEC_TEARDOWNS(record) \
  for (const char *stmt : record::kExitStatements) { \
    if (stmt) { \
      db.Execute(stmt); \
    } \
  }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_EXEC_TEARDOWNS)
  MX_EXEC_TEARDOWNS(EntityRecord)
#undef MX_EXEC_TEARDOWNS
#endif
}

#define MX_DEFINE_ADD_RECORD(name) \
    void DatabaseWriterImpl::DoAddAsync(name record) { \
      auto record_size = BulkInserterState::SizeOfRecord(record); \
      auto queue_size = pending_bytes.fetch_add(record_size) + record_size; \
      num_total_rows.fetch_add(1u); \
      insertion_queue.enqueue(std::move(record)); \
      if (queue_size > max_queue_size_in_bytes) { \
        insertion_queue.enqueue(PushbackSignal{}); \
        pushback_signal.wait(10000000 /* 10s */); \
      } \
    }

MX_DEFINE_ADD_RECORD(EntityRecord)
MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_ADD_RECORD)

#undef MX_DEFINE_ADD_RECORD

#define MX_DEFINE_ADD_RECORD(name) \
    void DatabaseWriter::AddAsync(name record) { \
      impl->DoAddAsync(std::move(record)); \
    }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_ADD_RECORD)

#undef MX_DEFINE_ADD_RECORD

void DatabaseWriter::AddAsync(EntityRecord record) {
  EntityCategory category = CategoryFromEntityId(record.id);
  assert(category != EntityCategory::NOT_AN_ENTITY);
  impl->entity_dictionaries[static_cast<unsigned>(category)].Add(
      *impl, impl->dictionary_context, std::move(record));
}

} // namespace mx
