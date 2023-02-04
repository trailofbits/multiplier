// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Database.h>

#include <array>
#include <cassert>
#include <chrono>
#include <deque>
#include <thread>
#include <unordered_map>
#include <vector>
#include <variant>
#include <zdict.h>
#include <zstd.h>

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
static constexpr size_t kNumFileShards = 256u;
static constexpr size_t kNumFragmentShards = 256u;

// TODO(pag): Use a hash function that is the same across platforms.
static const std::hash<std::string> kHasher;

// Number of INSERT statements to try to add in a single transaction.
static constexpr size_t kMaxTransactionSize = 10000u;

// Upper bound on the size of a trained entity dictionary.
static constexpr size_t kMaxDictionarySize = 112640;  // 110 KiB.

// The minimum size of the buffer used for training entity dictionaries.
static constexpr size_t kMinTrainingSetSize = 128ull * (1ull << 20ul);

static constexpr size_t kNumEntityCategories = NumEnumerators(EntityCategory{});

#define MX_RECORD_VARIANT_ENTRY(name) , name

struct ExitSignal {};
struct FlushSignal {};
using QueueItem = std::variant<
    std::monostate, ExitSignal, FlushSignal, EntityRecord
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_RECORD_VARIANT_ENTRY) >;
#undef MX_RECORD_VARIANT_ENTRY

using Queue = moodycamel::BlockingConcurrentQueue<QueueItem>;

// Thread-local database connection.
class WriterThreadState {
 private:
  sqlite::Connection db;

 public:
  std::optional<RawEntityId> available_file_index;
  std::optional<RawEntityId> available_small_fragment_index;
  std::optional<RawEntityId> available_big_fragment_index;

  // Get a file ID index given a file hash.
  std::array<std::optional<sqlite::Statement>, kNumFileShards>
      get_file_index, set_file_index;

  // Get/set a fragment ID index given a file hash.
  std::array<std::optional<sqlite::Statement>, kNumFragmentShards>
      get_fragment_index, set_fragment_index;

  ~WriterThreadState(void) {}

  WriterThreadState(
      const std::filesystem::path &path)
      : db(path) {}

  RawEntityId GetOrCreateFileId(RawEntityId proposed_id,
                                const std::string &hash);

  RawEntityId GetOrCreateFragmentId(RawEntityId proposed_id,
                                    RawEntityId file_tok_id,
                                    const std::string &hash);
};

RawEntityId WriterThreadState::GetOrCreateFileId(
    RawEntityId proposed_id, const std::string &hash) {

  // Calculate which file table to index into.
  const size_t table = kHasher(hash) % kNumFileShards;
  std::optional<sqlite::Statement> &get = get_file_index[table];
  std::optional<sqlite::Statement> &set = set_file_index[table];

  // We might not have prepared these statements for the current thread yet.
  if (!get) {
    auto table_name = "file_hash_" + std::to_string(table);
    get.emplace(db.Prepare(
        "SELECT file_id FROM " + table_name + " WHERE hash = ?1")),

    set.emplace(db.Prepare(
        "INSERT INTO " + table_name + " (file_id, hash) "
        "VALUES (?1, ?2) "
        "ON CONFLICT DO UPDATE SET file_id = file_id "
        "RETURNING file_id"));
  }

  RawEntityId id_out = kInvalidEntityId;

  get->BindValues(hash);
  if (get->ExecuteStep()) {
    get->Row().Columns(id_out);
  }
  get->Reset();


  while (id_out == kInvalidEntityId) {
    set->BindValues(proposed_id, hash);
    if (set->ExecuteStep()) {
      set->Row().Columns(id_out);
    }
    set->Reset();
  }

  return id_out;
}

RawEntityId WriterThreadState::GetOrCreateFragmentId(
    RawEntityId proposed_id, RawEntityId file_tok_id,
    const std::string &hash) {

  // Calculate which fragment table to index into.
  const size_t table = kHasher(hash) % kNumFragmentShards;
  std::optional<sqlite::Statement> &get = get_fragment_index[table];
  std::optional<sqlite::Statement> &set = set_fragment_index[table];

  // We might not have prepared these statements for the current thread yet.
  if (!get) {
    auto table_name = "fragment_hash_" + std::to_string(table);
    get.emplace(db.Prepare(
        "SELECT fragment_id FROM " + table_name +
        " WHERE file_token_id = ?1 AND hash = ?2")),

    set.emplace(db.Prepare(
        "INSERT INTO " + table_name + " (fragment_id, file_token_id, hash) "
        "VALUES (?1, ?2, ?3) "
        "ON CONFLICT DO UPDATE SET fragment_id = fragment_id "
        "RETURNING fragment_id"));
  }

  RawEntityId id_out = kInvalidEntityId;

  get->BindValues(file_tok_id, hash);
  if (get->ExecuteStep()) {
    get->Row().Columns(id_out);
  }
  get->Reset();

  while (id_out == kInvalidEntityId) {
    set->BindValues(proposed_id, file_tok_id, hash);
    if (set->ExecuteStep()) {
      set->Row().Columns(id_out);
    }
    set->Reset();
  }

  return id_out;
}

class BulkInserterState {
 public:

  // The `async.db` can only be used inside of the `bulk_insertion_thread`.
  sqlite::Connection db;

#define MX_DECLARE_INSERT_STMT(record) \
    sqlite::Statement INSERT_INTO_ ## record; \
    void DoInsertAsync(record r) { \
      if (InsertAsync(std::move(r), INSERT_INTO_ ## record)) { \
        INSERT_INTO_ ## record.Execute(); \
      } else { \
        INSERT_INTO_ ## record.Reset(); \
      } \
    } \
    bool InsertAsync(record, sqlite::Statement &);
  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
  MX_DECLARE_INSERT_STMT(EntityRecord)
#undef MX_DECLARE_INSERT_STMT

  BulkInserterState(std::filesystem::path db_path)
      : db(std::move(db_path))

#define MX_DEFINE_STMT(record) \
      , INSERT_INTO_ ## record(db.Prepare( \
        record::kInsertStatement))
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_STMT)
    MX_DEFINE_STMT(EntityRecord)
#undef MX_DEFINE_STMT
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
  void Build(Queue &queue, DictionaryContext &context,
             std::unique_lock<std::mutex> locker);

  // Add `record`, either as a pending item for training a dictionary, or passed
  // through to `CompressAndAdd`.
  void Add(Queue &queue, DictionaryContext &context, EntityRecord record);

  void CompressAndAdd(Queue &queue, DictionaryContext &context,
                      EntityRecord record, ZSTD_CDict *d);

  void CompressAndAdd(Queue &queue, DictionaryContext &context,
                      RawEntityId id, const void *data,
                      size_t data_size, ZSTD_CDict *d);

  void CompressAndAdd(Queue &queue, RawEntityId id, const void *data,
                      size_t data_size, ZSTD_CDict *d, ZSTD_CCtx *context);
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
    Queue &queue, RawEntityId id, const void *data, size_t data_size,
    ZSTD_CDict *d, ZSTD_CCtx *context) {

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
  queue.enqueue(std::move(record));
}

void DictionaryCompressor::CompressAndAdd(
    Queue &queue, DictionaryContext &context, RawEntityId id,
    const void *data, size_t data_size, ZSTD_CDict *d) {
  auto context_and_index = context.AcquireContext();
  CompressAndAdd(queue, id, data, data_size, d, context_and_index.first);
  context.ReleaseContext(context_and_index);
}

// Compress the data from `record`, then add it to our insertion queue.
void DictionaryCompressor::CompressAndAdd(
    Queue &queue, DictionaryContext &context, EntityRecord record,
    ZSTD_CDict *d) {
  CompressAndAdd(queue, context, record.id, record.data.data(), record.data.size(), d);
}

// Add `record`, either as a pending item for training a dictionary, or passed
// through to `CompressAndAdd`.
void DictionaryCompressor::Add(Queue &queue, DictionaryContext &context,
                               EntityRecord record) {

  // If we already have a dictionary, then use it.
  if (ZSTD_CDict *d = dict.load(std::memory_order_acquire)) {
    CompressAndAdd(queue, context, std::move(record), d);
    return;
  }

  std::unique_lock<std::mutex> locker(lock);

  // If there was a race condition and if the dictionary has been created in the
  // time that it took to acquire the lock, then use it to add the record.
  if (ZSTD_CDict *d = dict.load(std::memory_order_relaxed)) {
    locker.unlock();
    CompressAndAdd(queue, context, std::move(record), d);
    return;
  }

  // We don't yet have a dictionary. In this case, we collect the data into
  // a format that allows us to reconstruct the (compressed) records later,
  // while also being able to traint a ZSTD dictionary.
  training_data.append(record.data);
  data_sizes.push_back(record.data.size());
  entity_ids.push_back(record.id);

  // If we haven't yet collected enough training data then stop here.
  if (training_data.size() < kMinTrainingSetSize) {
    return;
  }

  Build(queue, context, std::move(locker));
}

// Build the dictionary if it hasn't yet been built. This will enqueue any
// pending records to `queue`.
void DictionaryCompressor::Build(Queue &queue, DictionaryContext &context,
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
  size_t dictionary_size = ZDICT_trainFromBuffer(
      dictionary.data.data(), kMaxDictionarySize,
      record_data, data_sizes.data(), num_records);

  assert(!ZSTD_isError(dictionary_size));
  dictionary.data.resize(dictionary_size);

  // Publish the newly trained dictionary so that other threads can immediately
  // benefit from it. This will unlock the mutex and let any blocked threads
  // proceed with the new dictionary. Their racy check will pick up the now-
  // published dictionary.
  auto d = ZSTD_createCDict(dictionary.data.data(), dictionary_size,
                            ZSTD_maxCLevel());
  dict.store(d, std::memory_order_release);
  locker.unlock();

  // Persist the dictionary.
  queue.enqueue(std::move(dictionary));

  // Now use it locally.
  auto context_and_index = context.AcquireContext();

  // Compress and add all of the training records.
  for (auto i = 0u; i < num_records; ++i) {
    auto record_id = entity_ids[i];
    auto record_data_size = data_sizes[i];
    CompressAndAdd(queue, record_id, record_data, record_data_size, d,
                   context_and_index.first);
    record_data = &(record_data[record_data_size]);
  }

  context.ReleaseContext(context_and_index);

  // Force free the training resources.
  std::vector<RawEntityId>().swap(entity_ids);
  std::vector<size_t>().swap(data_sizes);
  std::string().swap(training_data);
}

}  // namespace

class DatabaseWriterImpl {
 public:
  const std::filesystem::path db_path;

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

  // Entity-specific compression dictionaries.
  DictionaryContext dictionary_context;
  std::array<DictionaryCompressor, kNumEntityCategories> entity_dictionaries;

  // Number of rows pending insertion.
  std::atomic<size_t> num_pending_rows;

  // A thread and it's multiple-producer, single-consumer.
  Queue insertion_queue;
  std::thread bulk_insertion_thread;

  DatabaseWriterImpl(const std::filesystem::path &db_path);
  ~DatabaseWriterImpl(void);

  void BulkInserter(void);

  void InitDictionaries(void);
  void ExitDictionaries(void);

  void InitMetadata(void);
  void ExitMetadata(void);

  void InitRecords(void);
  void ExitRecords(void);
};

void DatabaseWriterImpl::ExitMetadata(void) {
  add_version.BindValues(0u);
  add_version.Execute();

  // Update the metadata.
  update_meta_stmt.BindValues(
      next_file_index.load(),
      next_small_fragment_index.load(),
      next_big_fragment_index.load());
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

    // ZSTD dictionaries must be at least 8 bytes (for the header).
    if (8u < data.size()) {
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
    dict.Build(insertion_queue, dictionary_context,
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
          next_big_fragment_index)
         VALUES (1, 1, ?1, 1))");

  set_meta_stmt.BindValues(
      mx::kMaxBigFragmentId  /* next_small_fragment_index */);
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

  if (get_ids.ExecuteStep()) {
    get_ids.Row().Columns(file_id, small_id, big_id);

    assert(1u <= file_id);
    assert(mx::kMaxBigFragmentId <= small_id);
    assert(1u <= big_id);
    assert(big_id < mx::kMaxBigFragmentId);

    next_file_index.store(file_id);
    next_small_fragment_index.store(small_id);
    next_big_fragment_index.store(big_id);

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

  for (; !should_exit || num_added_rows < num_pending_rows.load();
      should_flush = false) {

    QueueItem item;

    // Go get the first thing.
    insertion_queue.wait_dequeue(item);

    sqlite::Transaction transaction(async.db);
    size_t transaction_size = 0u;

    do {
      std::visit(
          [&] (auto arg) {
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

            } else {
              async.DoInsertAsync(std::move(arg));
              ++transaction_size;
            }
          },
          std::move(item));

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
  sqlite::Connection db(db_path_);
  for (const char *stmt : DatabaseWriter::kInitStatements) {
    db.Execute(std::string(stmt));
  }
  for (size_t i = 0u; i < kNumFileShards; ++i) {
    db.Execute(
        "CREATE TABLE IF NOT EXISTS file_hash_" + std::to_string(i) + " ("
        "  file_id INT NOT NULL,"
        "  hash BLOB NOT NULL,"
        "  PRIMARY KEY(hash)"
        ") WITHOUT rowid");
  }

  for (size_t i = 0u; i < kNumFragmentShards; ++i) {
    db.Execute(
        "CREATE TABLE IF NOT EXISTS fragment_hash_" + std::to_string(i) + " ("
        "  fragment_id INT NOT NULL,"
        "  file_token_id INT NOT NULL,"
        "  hash BLOB NOT NULL,"
        "  PRIMARY KEY(file_token_id, hash)"
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

DatabaseWriterImpl::DatabaseWriterImpl(
    const std::filesystem::path &db_path_)
    : db_path(db_path_),
      db(CreateDatabase(db_path)),
      add_version(db.Prepare(
          R"(INSERT INTO version (action) VALUES (?1))")),
      get_ids(db.Prepare(
          R"(SELECT next_file_index, next_small_fragment_index, 
                    next_big_fragment_index
             FROM metadata
             WHERE rowid = 1
             LIMIT 1)")),
      update_meta_stmt(db.Prepare(
          R"(UPDATE metadata
             SET next_file_index = ?1,
                 next_small_fragment_index = ?2,
                 next_big_fragment_index = ?3
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

bool BulkInserterState::InsertAsync(
    DictionaryRecord record, sqlite::Statement &insert) {
  insert.BindValues(static_cast<unsigned>(record.category), record.data);
  return true;
}

bool BulkInserterState::InsertAsync(
    FilePathRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.file_id.Pack(), record.path.lexically_normal());
  return true;
}

bool BulkInserterState::InsertAsync(
    FragmentFileRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.file_id.Pack());
  return true;
}

bool BulkInserterState::InsertAsync(
    FragmentFileRangeRecord record, sqlite::Statement &insert) {
  FileTokenId begin = record.first_file_token.Unpack();
  FileTokenId end = record.last_file_token.Unpack();
  assert(begin.file_id == end.file_id);
  FileId fid(begin.file_id);
  insert.BindValues(
      record.fragment_id.Pack(), begin.offset, end.offset,
      EntityId(fid).Pack());
  return true;
}

bool BulkInserterState::InsertAsync(
    RedeclarationRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.decl_id.Pack(), record.redecl_id.Pack());
  return true;
}

bool BulkInserterState::InsertAsync(
    MangledNameRecord record, sqlite::Statement &insert) {
  if (record.entity_id != mx::kInvalidEntityId &&
      !record.mangled_name.empty()) {
    insert.BindValues(record.entity_id, record.mangled_name);
    return true;
  }
  return false;
}

bool BulkInserterState::InsertAsync(
    UseRecord record, sqlite::Statement &insert) {
  if (auto raw_frag_id = record.fragment_id.Pack();
      record.entity_id != kInvalidEntityId) {
    insert.BindValues(raw_frag_id, record.entity_id);
    return true;
  }
  return false;
}

bool BulkInserterState::InsertAsync(
    ReferenceRecord record, sqlite::Statement &insert) {
  if (record.from_entity_id != kInvalidEntityId &&
      record.to_entity_id != kInvalidEntityId) {
    insert.BindValues(record.from_entity_id, record.to_entity_id);
    return true;
  }
  return false;
}

bool BulkInserterState::InsertAsync(
    SymbolNameRecord record, sqlite::Statement &insert) {
  if (!record.name.empty()) {
    insert.BindValues(record.entity_id, record.name);
    return true;
  }
  return false;
}

bool BulkInserterState::InsertAsync(EntityRecord record,
                                    sqlite::Statement &insert) {
  insert.BindValues(record.id, record.data);
  return true;
}

DatabaseWriter::DatabaseWriter(
    std::filesystem::path db_path)
    : impl(std::make_shared<DatabaseWriterImpl>(db_path)) {}

DatabaseWriter::~DatabaseWriter(void) {}

void DatabaseWriter::AsyncFlush(void) {
  impl->insertion_queue.enqueue(FlushSignal{});
}

// Get, or create and return, a file ID for the specific file contents hash.
SpecificEntityId<FileId> DatabaseWriter::GetOrCreateFileIdForHash(
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
  RawEntityId found_id = writer->GetOrCreateFileId(proposed_id, hash);
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_file_index.emplace(proposed_index);
  }

  VariantId vid = EntityId(found_id).Unpack();
  assert(std::holds_alternative<FileId>(vid));
  return std::get<FileId>(vid);
}

// Get, or create and return, a fragment ID for the specific fragment hash.
SpecificEntityId<FragmentId>
DatabaseWriter::GetOrCreateSmallFragmentIdForHash(
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
      proposed_id, tok_id, hash);
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
SpecificEntityId<FragmentId>
DatabaseWriter::GetOrCreateLargeFragmentIdForHash(
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

void DatabaseWriterImpl::InitRecords(void) {
#define MX_EXEC_INITS(record) \
  for (const char *stmt : record::kInitStatements) { \
    if (stmt) { \
      db.Execute(stmt); \
    } \
  }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_EXEC_INITS)
  MX_EXEC_INITS(EntityRecord)
#undef MX_EXEC_INITS
}

void DatabaseWriterImpl::ExitRecords(void) {
#define MX_EXEC_TEARDOWNS(record) \
  for (const char *stmt : record::kExitStatements) { \
    if (stmt) { \
      db.Execute(stmt); \
    } \
  }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_EXEC_TEARDOWNS)
  MX_EXEC_TEARDOWNS(EntityRecord)
#undef MX_EXEC_TEARDOWNS
}

#define MX_DEFINE_ADD_RECORD(name) \
    void DatabaseWriter::AddAsync(name record) { \
      impl->num_pending_rows.fetch_add(1u); \
      impl->insertion_queue.enqueue(std::move(record)); \
    }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_ADD_RECORD)

#undef MX_DECLARE_ADD_RECORD

void DatabaseWriter::AddAsync(EntityRecord record) {
  EntityCategory category = CategoryFromEntityId(record.id);
  assert(category != EntityCategory::NOT_AN_ENTITY);
  impl->num_pending_rows.fetch_add(1u);
  impl->entity_dictionaries[static_cast<unsigned>(category)].Add(
      impl->insertion_queue, impl->dictionary_context, std::move(record));
}

} // namespace mx
