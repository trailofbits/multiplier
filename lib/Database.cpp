// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Database.h>

#include <array>
#include <atomic>
#include <cassert>
#include <chrono>
#include <deque>
#include <multiplier/AST/AttrKind.h>
#include <multiplier/AST/DeclKind.h>
#include <multiplier/AST/StmtKind.h>
#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/Iterator.h>
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

// Helps speed up debugging by making things happen faster.
static constexpr bool kDisableAddAsync = false;

// Number of INSERT statements to try to add in a single transaction.
static constexpr size_t kMaxTransactionSize = 10000000u;

// Upper bound on the size of a trained entity dictionary.
static constexpr size_t kMaxDictionarySize = 112640;  // 110 KiB.

// The minimum size of the buffer used for training entity dictionaries.
static constexpr size_t kMinTrainingSetSize = 128ull * (1ull << 20ul);

static constexpr size_t kNumEntityCategories = NumEnumerators(EntityCategory{});

static std::mutex gDatabaseInitializationLock;

struct FragmentIndexRecord {
  mx::RawEntityId entity_id;
};

struct PushbackSignal {};
struct ExitSignal {};
struct FlushSignal {};
using QueueItem = std::variant<
    std::monostate, ExitSignal, FlushSignal, PushbackSignal, FragmentIndexRecord
#ifndef __CDT_PARSER__
#define MX_RECORD_VARIANT_ENTRY(name) , name
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_RECORD_VARIANT_ENTRY)
    MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_RECORD_VARIANT_ENTRY)
    MX_RECORD_VARIANT_ENTRY(ReplacementFragmentRecord)
#undef MX_RECORD_VARIANT_ENTRY
#endif
    >;

using Queue = moodycamel::BlockingConcurrentQueue<QueueItem>;

class Semaphore : public moodycamel::LightweightSemaphore {
 public:
  using moodycamel::LightweightSemaphore::LightweightSemaphore;
};

template <typename Kind>
inline static uint64_t EncodeCategoryKind(EntityCategory category, Kind kind) {
  assert(category != EntityCategory::NOT_AN_ENTITY);
  return (uint64_t(category) << 32u) | unsigned(kind);
}

class BulkInserterState {
 public:

  // The `async.db` can only be used inside of the `bulk_insertion_thread`.
  sqlite::Connection db;

  // Entity-category-specific insertions.
  std::unordered_map<uint64_t, sqlite::Statement> INSERT_INTO_FRAGMNET_INDEX;

  inline static size_t SizeOfRecord(const FragmentIndexRecord &) {
    return sizeof(FragmentIndexRecord);
  }

  template <typename EntityKind>
  sqlite::Statement CreateEntityIndexInsertQuery(mx::EntityCategory category,
                                                 EntityKind kind) {
    std::string query = "INSERT OR IGNORE INTO fragment_with_";
    query += mx::EnumeratorName(category);
    query += "_";
    query += mx::EnumeratorName(kind);
    query += " (fragment_id) VALUES (?1)";
    return db.Prepare(query);
  }

  sqlite::Statement CreateEntityIndexInsertQuery(mx::EntityCategory category) {
    std::string query = "INSERT OR IGNORE INTO fragment_with_";
    query += mx::EnumeratorName(category);
    query += " (fragment_id) VALUES (?1)";
    return db.Prepare(query);
  }

  void DoInsertAsync(FragmentIndexRecord record);

#define MX_DECLARE_INSERT_STMT(record) \
    sqlite::Statement INSERT_INTO_ ## record; \
    void DoInsertAsync(const record &r) { \
      if constexpr (!kDisableAddAsync) { \
        if (InsertAsync(r, INSERT_INTO_ ## record)) { \
          INSERT_INTO_ ## record.Execute(); \
        } else { \
          INSERT_INTO_ ## record.Reset(); \
        } \
      } \
    } \
    bool InsertAsync(const record &, sqlite::Statement &); \
    static size_t SizeOfRecord(const record &r);

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
  MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
  MX_DECLARE_INSERT_STMT(ReplacementFragmentRecord)
#undef MX_DECLARE_INSERT_STMT

  BulkInserterState(std::filesystem::path db_path)
      : db(std::move(db_path))

#ifndef __CDT_PARSER__
#define MX_DEFINE_STMT(record) \
      , INSERT_INTO_ ## record(db.Prepare( \
        record::kInsertStatement))
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_STMT)
    MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_DEFINE_STMT)
    MX_DEFINE_STMT(ReplacementFragmentRecord)
#undef MX_DEFINE_STMT
#endif
      {

#define CREATE_FRAG_OFFSET_INDEX(ns_path, upper, lower, enum_, index) \
    for (auto kind : mx::EnumerationRange<mx::upper ## Kind>()) { \
      INSERT_INTO_FRAGMNET_INDEX.emplace( \
          EncodeCategoryKind(mx::EntityCategory::enum_, kind), \
          CreateEntityIndexInsertQuery(mx::EntityCategory::enum_, kind)); \
    }

// NOTE(pag): `-1` corresponds to return value of `KindFromEntityId` on an
//            entity ID of this category.
#define CREATE_PSEUDO_INDEX(ns_path, upper, lower, enum_, index) \
    INSERT_INTO_FRAGMNET_INDEX.emplace( \
        EncodeCategoryKind(mx::EntityCategory::enum_, -1), \
        CreateEntityIndexInsertQuery(mx::EntityCategory::enum_)); \

  MX_FOR_EACH_ENTITY_CATEGORY(
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY,
      CREATE_FRAG_OFFSET_INDEX,
      CREATE_PSEUDO_INDEX,
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY)

#undef CREATE_FRAG_OFFSET_INDEX
#undef CREATE_PSEUDO_INDEX

  }  // End of constructor.
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

  // Training data. We accumulate the (uncompressed)
  // `(Fragment/Type)Record::data` into `training_data`. `data_sizes` contains
  // the size of each record entry, and `entity_ids` holds the entity IDs of
  // each record. This is a format that is compatible with ZSTD dictionary
  // training, as well as `CompressAndAdd`.
  std::string training_data;
  std::vector<size_t> data_sizes;
  std::vector<RawEntityId> entity_ids;
  std::vector<bool> replacement_flags;

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
  template <typename EntityRecord>
  void Add(DatabaseWriterImpl &impl, DictionaryContext &context,
           EntityRecord record);

  template <typename EntityRecord>
  void CompressAndAdd(DatabaseWriterImpl &impl, DictionaryContext &context,
                      EntityRecord record, ZSTD_CDict *d);

  void CompressAndAdd(DatabaseWriterImpl &impl, DictionaryContext &context,
                      RawEntityId id, const void *data,
                      size_t data_size, bool is_replacement, ZSTD_CDict *d);

  void CompressAndAdd(DatabaseWriterImpl &impl, RawEntityId id,
                      const void *data, size_t data_size, bool is_replacement,
                      ZSTD_CDict *d, ZSTD_CCtx *context);
};

class DatabaseWriterImpl {
 public:
  // Path to the open database file.
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
  MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
  MX_DECLARE_INSERT_STMT(FragmentIndexRecord)
  MX_DECLARE_INSERT_STMT(ReplacementFragmentRecord)
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
    size_t data_size, bool is_replacement, ZSTD_CDict *d, ZSTD_CCtx *context) {

  const size_t maybe_compressed_data_size = ZSTD_compressBound(data_size);
  std::string compressed_data;
  compressed_data.resize(maybe_compressed_data_size);

  auto compressed_data_size = ZSTD_compress_usingCDict(
      context,
      compressed_data.data(), maybe_compressed_data_size,
      data, data_size,
      d);

  assert(!ZSTD_isError(compressed_data_size));
  compressed_data.resize(compressed_data_size);

  if (is_replacement) {
    impl.DoAddAsync(ReplacementFragmentRecord{id, std::move(compressed_data)});
    return;
  }

  // Swap the uncompressed data with the compressed data, and add it to the
  // bulk insertion queue.
  switch (CategoryFromEntityId(id)) {

#define MX_ADD_ENTITY_RECORD(name) \
    case name::kCategory: \
      impl.DoAddAsync(name{id, std::move(compressed_data)}); \
      break;

    MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_ADD_ENTITY_RECORD)
#undef MX_ADD_ENTITY_RECORD

    default:
      assert(false);
      break;
  }
}

void DictionaryCompressor::CompressAndAdd(
    DatabaseWriterImpl &impl, DictionaryContext &context, RawEntityId id,
    const void *data, size_t data_size, bool is_replacement, ZSTD_CDict *d) {
  auto context_and_index = context.AcquireContext();
  CompressAndAdd(impl, id, data, data_size, is_replacement, d,
                 context_and_index.first);
  context.ReleaseContext(context_and_index);
}

// Compress the data from `record`, then add it to our insertion queue.
template <typename EntityRecord>
void DictionaryCompressor::CompressAndAdd(
    DatabaseWriterImpl &impl, DictionaryContext &context, EntityRecord record,
    ZSTD_CDict *d) {
  CompressAndAdd(
      impl, context, record.id, record.data.data(), record.data.size(),
      std::is_same_v<EntityRecord, ReplacementFragmentRecord>, d);
}

// Add `record`, either as a pending item for training a dictionary, or passed
// through to `CompressAndAdd`.
template <typename EntityRecord>
void DictionaryCompressor::Add(DatabaseWriterImpl &impl,
                               DictionaryContext &context,
                               EntityRecord record) {

  if constexpr (kDisableAddAsync) {
    return;
  }

  // If we already have a dictionary, then use it.
  if (ZSTD_CDict *d = dict.load(std::memory_order_acquire)) {
    CompressAndAdd<EntityRecord>(impl, context, std::move(record), d);
    return;
  }

  std::unique_lock<std::mutex> locker(lock);

  // If there was a race condition and if the dictionary has been created in the
  // time that it took to acquire the lock, then use it to add the record.
  if (ZSTD_CDict *d = dict.load(std::memory_order_relaxed)) {
    locker.unlock();
    CompressAndAdd<EntityRecord>(impl, context, std::move(record), d);
    return;
  }

  // We don't yet have a dictionary. In this case, we collect the data into
  // a format that allows us to reconstruct the (compressed) records later,
  // while also being able to train a ZSTD dictionary.
  training_data.append(record.data);
  data_sizes.push_back(record.data.size());
  entity_ids.push_back(record.id);
  replacement_flags.push_back(
      std::is_same_v<ReplacementFragmentRecord, EntityRecord>);

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
    auto is_replacement = replacement_flags[i];
    CompressAndAdd(impl, record_id, record_data, record_data_size,
                   is_replacement, compression_dict, context_and_index.first);
    record_data = &(record_data[record_data_size]);
  }

  context.ReleaseContext(context_and_index);

  // Force free the training resources.
  std::vector<RawEntityId>().swap(entity_ids);
  std::vector<size_t>().swap(data_sizes);
  std::vector<bool>().swap(replacement_flags);
  std::string().swap(training_data);
}

void DatabaseWriterImpl::ExitMetadata(void) {
  add_version.BindValues(0u);
  add_version.Execute();
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
  add_version.BindValues(1u);
  add_version.Execute();
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

#define CREATE_FRAG_OFFSET_INDEX(ns_path, upper, lower, enum_, index) \
    for (auto enum_val : mx::EnumerationRange<mx::upper ## Kind>()) { \
      std::string query = "CREATE TABLE IF NOT EXISTS fragment_with_"; \
      query += mx::EnumeratorName(mx::EntityCategory::enum_); \
      query += "_"; \
      query += mx::EnumeratorName(enum_val); \
      query += " (fragment_id INTEGER NOT NULL PRIMARY KEY) WITHOUT ROWID"; \
      db.Execute(query); \
    }

#define CREATE_PSEUDO_INDEX(ns_path, upper, lower, enum_, index) \
    do { \
      std::string query = "CREATE TABLE IF NOT EXISTS fragment_with_"; \
      query += mx::EnumeratorName(mx::EntityCategory::enum_); \
      query += " (fragment_id INTEGER NOT NULL PRIMARY KEY) WITHOUT ROWID"; \
      db.Execute(query); \
    } while (false);

  MX_FOR_EACH_ENTITY_CATEGORY(
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY,
      CREATE_FRAG_OFFSET_INDEX,
      CREATE_PSEUDO_INDEX,
      MX_IGNORE_ENTITY_CATEGORY,
      MX_IGNORE_ENTITY_CATEGORY)

#undef CREATE_FRAG_OFFSET_INDEX
#undef CREATE_PSEUDO_INDEX

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
      insertion_queue(kMaxTransactionSize) {

  InitMetadata();
  InitRecords();
  InitDictionaries();

  bulk_insertion_thread = std::thread([this] (void) {
    this->BulkInserter();
  });
}

// Mark that a specific fragment contains an entity of a specific type and kind.
void BulkInserterState::DoInsertAsync(FragmentIndexRecord record) {
  auto fragment_id = FragmentIdFromEntityId(record.entity_id);
  if (!fragment_id) {
    assert(false);
    return;
  }

  uint64_t key = EncodeCategoryKind(CategoryFromEntityId(record.entity_id),
                                    KindFromEntityId(record.entity_id));

  auto stmt_it = INSERT_INTO_FRAGMNET_INDEX.find(key);
  if (stmt_it == INSERT_INTO_FRAGMNET_INDEX.end()) {
    assert(false);
    return;
  }

  stmt_it->second.BindValuesWithoutCopying(fragment_id->Pack());
  stmt_it->second.Execute();
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

size_t BulkInserterState::SizeOfRecord(
    const ReplacementFragmentRecord &record) {
  return sizeof(record) + record.data.size();
}

bool BulkInserterState::InsertAsync(
    const ReplacementFragmentRecord &record, sqlite::Statement &insert) {
  insert.BindValuesWithoutCopying(record.id, record.data);
  return true;
}

void DatabaseWriter::AddAsync(ReplacementFragmentRecord record) {
  static constexpr auto kEntityCategory =
      static_cast<unsigned>(EntityCategory::FRAGMENT);
  impl->entity_dictionaries[kEntityCategory].Add(
      *impl, impl->dictionary_context, std::move(record));
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
                                    record.context_entity_id,
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

#define DEFINE_ENTITY_INSERTERS(name) \
    size_t BulkInserterState::SizeOfRecord(const name &record) { \
      return sizeof(record) + record.data.size(); \
    } \
    \
    bool BulkInserterState::InsertAsync(const name &record, \
                                        sqlite::Statement &insert) { \
      insert.BindValuesWithoutCopying(record.id, record.data); \
      return true; \
    }

MX_FOR_EACH_ENTITY_RECORD_TYPE(DEFINE_ENTITY_INSERTERS)
#undef DEFINE_ENTITY_INSERTERS

DatabaseWriter::DatabaseWriter(std::filesystem::path db_path,
                               size_t max_queue_size_in_bytes)
    : impl(std::make_shared<DatabaseWriterImpl>(
          db_path, max_queue_size_in_bytes)) {}

DatabaseWriter::~DatabaseWriter(void) {}

void DatabaseWriter::AsyncFlush(void) {
  impl->insertion_queue.enqueue(FlushSignal{});
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
  MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_EXEC_INITS)
  MX_EXEC_INITS(ReplacementFragmentRecord)
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
  MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_EXEC_TEARDOWNS)
  MX_EXEC_TEARDOWNS(ReplacementFragmentRecord)
#undef MX_EXEC_TEARDOWNS
#endif
}

#define MX_DEFINE_ADD_RECORD(name) \
    void DatabaseWriterImpl::DoAddAsync(name record) { \
      if constexpr (!kDisableAddAsync) { \
        auto record_size = BulkInserterState::SizeOfRecord(record); \
        auto queue_size = pending_bytes.fetch_add(record_size) + record_size; \
        num_total_rows.fetch_add(1u); \
        insertion_queue.enqueue(std::move(record)); \
        if (queue_size > max_queue_size_in_bytes) { \
          insertion_queue.enqueue(PushbackSignal{}); \
          pushback_signal.wait(10000000 /* 10s */); \
        } \
      } \
    }

MX_DEFINE_ADD_RECORD(FragmentIndexRecord)
MX_DEFINE_ADD_RECORD(ReplacementFragmentRecord)
MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_DEFINE_ADD_RECORD)
MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_ADD_RECORD)

#undef MX_DEFINE_ADD_RECORD

#define MX_DEFINE_ADD_RECORD(name) \
    void DatabaseWriter::AddAsync(name record) { \
      if constexpr (!kDisableAddAsync) { \
        impl->DoAddAsync(std::move(record)); \
      } \
    }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_ADD_RECORD)

#undef MX_DEFINE_ADD_RECORD

#define MX_DEFINE_ADD_ENTITY_RECORD(name) \
    void DatabaseWriter::AddAsync(name record) { \
      if constexpr (!kDisableAddAsync) { \
        auto category = CategoryFromEntityId(record.id); \
        assert(mx::EntityCategory::NOT_AN_ENTITY != category); \
        impl->entity_dictionaries[static_cast<unsigned>(category)].Add( \
            *impl, impl->dictionary_context, std::move(record)); \
      } \
    }

MX_FOR_EACH_ENTITY_RECORD_TYPE(MX_DEFINE_ADD_ENTITY_RECORD)
#undef MX_DEFINE_ADD_ENTITY_RECORD

// Add an index record saying that the fragment containing the entity with ID
// `entity_id` contains the specific type and kind of entity.
void DatabaseWriter::AsyncIndexFragmentSpecificEntity(
    mx::RawEntityId entity_id) {
  if constexpr (!kDisableAddAsync) {
    impl->DoAddAsync(FragmentIndexRecord{entity_id});
  }
}

} // namespace mx
