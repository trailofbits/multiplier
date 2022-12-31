// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Database.h>

#include <cassert>
#include <chrono>
#include <deque>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>
#include <variant>

#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <blockingconcurrentqueue.h>
#pragma GCC diagnostic pop

#include "SQLiteStore.h"
#include "ThreadLocal.h"

namespace mx {

// Fragment hashes are sharded by the file token index and with the file ID.
//
// In WAL journalling mode, SQLite locks B-Trees. Each table gets its own
// B-Tree root, and so by sharding the fragment hash table, which gets a lot
// of concurrent writes during indexing, we try to spread the load.
static constexpr size_t kNumFragmentShards = 256u;

static constexpr size_t kMaxTransactionSize = 10000u;

#define MX_RECORD_VARIANT_ENTRY(name) , name

struct ExitSignal {};
struct FlushSignal {};
using QueueItem = std::variant<
    std::monostate, ExitSignal, FlushSignal
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_RECORD_VARIANT_ENTRY) >;
#undef MX_RECORD_VARIANT_ENTRY

// Thread-local database connection.
class WriterThreadState {
 private:
  sqlite::Connection db;

 public:
  std::optional<RawEntityId> available_file_index;
  std::optional<RawEntityId> available_small_fragment_index;
  std::optional<RawEntityId> available_big_fragment_index;

  // Get a file ID index given a file hash.
  sqlite::Statement get_file_index;
  sqlite::Statement set_file_index;

  // Get a fragment ID index given a file hash.
  std::vector<std::optional<sqlite::Statement>> get_fragment_index;
  std::vector<std::optional<sqlite::Statement>> set_fragment_index;

  ~WriterThreadState(void) {}

  WriterThreadState(const std::filesystem::path &path)
      : db(path),
        get_file_index(db.Prepare(
            R"(SELECT file_index FROM file_hash
               WHERE hash = ?1)")),
        set_file_index(db.Prepare(
            R"(INSERT INTO file_hash (file_index, hash) VALUES (?1, ?2)
               ON CONFLICT DO UPDATE SET file_index = file_index
               RETURNING file_index, hash)")) {
    get_fragment_index.resize(kNumFragmentShards);
    set_fragment_index.resize(kNumFragmentShards);
  }


  RawEntityId GetOrCreateFileId(RawEntityId proposed_index,
                                const std::string &hash);

  RawEntityId GetOrCreateFragmentId(RawEntityId proposed_index,
                                    RawEntityId file_tok_id,
                                    const std::string &hash);
};

RawEntityId WriterThreadState::GetOrCreateFileId(
    RawEntityId proposed_index, const std::string &hash) {
  RawEntityId index_out = kInvalidEntityId;

  get_file_index.BindValues(hash);
  if (get_file_index.ExecuteStep()) {
    get_file_index.Row().Columns(index_out);
  }
  get_file_index.Reset();

  while (index_out == kInvalidEntityId) {
    set_file_index.BindValues(proposed_index, hash);
    if (set_file_index.ExecuteStep()) {
      set_file_index.Row().Columns(index_out);
    }
    set_file_index.Reset();
  }

  return index_out;
}

RawEntityId WriterThreadState::GetOrCreateFragmentId(
    RawEntityId proposed_index, RawEntityId file_tok_id,
    const std::string &hash) {

  // Calculate which fragment table to index into. Hopefully the XOR of the
  // file ID and the file token offset is evenly distributed.
  VariantId vid = EntityId(file_tok_id).Unpack();
  size_t table = 0u;
  if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);
    table = (tid.file_id ^ tid.offset) % kNumFragmentShards;
  }

  std::optional<sqlite::Statement> &get = get_fragment_index[table];
  std::optional<sqlite::Statement> &set = set_fragment_index[table];

  if (!get) {
    auto table_name = "fragment_hash_" + std::to_string(table);
    get.emplace(db.Prepare(
        R"(SELECT fragment_index FROM fragment_hash
           WHERE file_token_id = ?1 AND hash = ?2)")),
    set.emplace(db.Prepare(
        R"(INSERT INTO fragment_hash (fragment_index, file_token_id, hash)
           VALUES (?1, ?2, ?3)
           ON CONFLICT DO UPDATE SET fragment_index = fragment_index 
           RETURNING fragment_index, file_token_id, hash)"));
  }

  RawEntityId index_out = kInvalidEntityId;
  get->BindValues(file_tok_id, hash);
  if (get->ExecuteStep()) {
    get->Row().Columns(index_out);
  }
  get->Reset();

  while (index_out == kInvalidEntityId) {
    set->BindValues(proposed_index, file_tok_id, hash);
    if (set->ExecuteStep()) {
      set->Row().Columns(index_out);
    }
    set->Reset();
  }

  return index_out;
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
      } \
    } \
    bool InsertAsync(record, sqlite::Statement &);
  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
#undef MX_DECLARE_INSERT_STMT

  BulkInserterState(std::filesystem::path db_path)
      : db(std::move(db_path))

#define MX_DEFINE_STMT(record) \
      , INSERT_INTO_ ## record(db.Prepare( \
        record::kInsertStatement))
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_STMT)
#undef MX_DEFINE_STMT
      {}  // End of constructor
};

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

  // A thread and it's multiple-producer, single-consumer.
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;
  std::thread bulk_insertion_thread;

  DatabaseWriterImpl(const std::filesystem::path &db_path);
  ~DatabaseWriterImpl(void);

  void BulkInserter(void);

  void InitMetadata(void);
  void ExitMetadata(void);

  void InitRecords(void);
  void ExitRecords(void);
};

void DatabaseWriterImpl::ExitMetadata(void) {
  add_version.BindValues(0u);
  add_version.Execute();
}

// Initialize the metadata table. It only stores one row of data.
void DatabaseWriterImpl::InitMetadata(void) {

  // Initialize the default metadata. The trick we use here is that we hard-code
  // a `rowid` of `1`, and so the implicit primary key constraint on `rowid`
  // will cause repeated initializations to be ignored.
  sqlite::Statement set_meta_stmt = db.Prepare(
      R"(INSERT OR IGNORE INTO metadata 
         (rowid, next_file_index, next_small_fragment_index, next_big_fragment_index)
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

  for (; !should_exit; should_flush = false) {

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

            // Flush signal.
            } else if constexpr (std::is_same_v<FlushSignal, arg_t>) {
              should_flush = true;

            } else {
              async.DoInsertAsync(std::move(arg));
            }
          },
          std::move(item));

      ++transaction_size;
      if (transaction_size >= kMaxTransactionSize) {
        should_flush = true;
      }

      if (should_flush) {
        break;
      }

    // Try to get the next thing.
    } while (insertion_queue.try_dequeue(item) ||
             insertion_queue.wait_dequeue_timed(item, 10 * 1000));
  }
}

namespace {

sqlite::Connection CreateDatabase(const std::filesystem::path &db_path_) {
  sqlite::Connection db(db_path_);
  for (const char *stmt : DatabaseWriter::kInitStatements) {
    db.Execute(std::string(stmt));
  }
  for (size_t i = 0u; i < kNumFragmentShards; ++i) {
    db.Execute(
        "CREATE TABLE IF NOT EXISTS fragment_hash_" + std::to_string(i) + " ("
        "  fragment_index INT NOT NULL,"
        "  file_token_id INT NOT NULL,"
        "  hash BLOB NOT NULL,"
        "  PRIMARY KEY(file_token_id, hash)"
        ") WITHOUT rowid");
  }
  return db;
}

}  // namespace

DatabaseWriterImpl::~DatabaseWriterImpl(void) {
  insertion_queue.enqueue(ExitSignal{});
  bulk_insertion_thread.join();

//  for (const char *stmt : DatabaseWriter::kExitStatments) {
//    db.Execute(stmt);
//  }

  ExitRecords();
  ExitMetadata();
  db.Optimize();
}

DatabaseWriterImpl::DatabaseWriterImpl(
    const std::filesystem::path &db_path_)
    : db_path(db_path_),
      db(CreateDatabase(db_path)),
      add_version(db.Prepare(
          R"(INSERT INTO version (action) VALUES (?1))")),
      get_ids(db.Prepare(
          R"(SELECT next_file_index, next_small_fragment_index, next_big_fragment_index
             FROM metadata
             WHERE rowid = 1
             LIMIT 1)")),
      thread_state(
          [this] (unsigned i) -> WriterThreadState * {
             return new WriterThreadState(db_path);
          },
          [] (void *ptr) {
            delete reinterpret_cast<WriterThreadState *>(ptr);
          }),
      insertion_queue() {

  InitMetadata();
  InitRecords();
  bulk_insertion_thread = std::thread([this] (void) {
    this->BulkInserter();
  });
}

bool BulkInserterState::InsertAsync(
    FilePathRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.file_id.Pack(), record.path.lexically_normal());
  return true;
}

bool BulkInserterState::InsertAsync(
    FragmentLineCoverageRecord record, sqlite::Statement &insert) {
  auto raw_file_id = record.file_id.Pack();
  if (raw_file_id != mx::kInvalidEntityId && record.first_line_number &&
      record.first_line_number <= record.last_line_number) {
    insert.BindValues(record.fragment_id.Pack(), raw_file_id,
                      record.first_line_number, record.last_line_number);
    return true;
  }
  return false;
}

bool BulkInserterState::InsertAsync(
    SerializedFileRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.file_id.Pack(), record.data);
  return true;
}

bool BulkInserterState::InsertAsync(
    SerializedFragmentRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.data);
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
  insert.BindValues(record.fragment_id.Pack(), record.entity_id);
  return true;
}

bool BulkInserterState::InsertAsync(
    ReferenceRecord record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.entity_id);
  return true;
}

bool BulkInserterState::InsertAsync(
    SymbolNameRecord record, sqlite::Statement &insert) {
  if (!record.name.empty()) {
    insert.BindValues(record.entity_id, record.name);
    return true;
  }
  return false;
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

  RawEntityId found_index = writer->GetOrCreateFileId(proposed_index, hash);
  is_new = found_index == proposed_index;
  if (!is_new) {
    writer->available_file_index.emplace(proposed_index);
  }

  assert(found_index != kInvalidEntityId);

  FileId ret(found_index);
  return ret;
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

  RawEntityId found_index = writer->GetOrCreateFragmentId(
      proposed_index, tok_id, hash);
  is_new = found_index == proposed_index;
  if (!is_new) {
    writer->available_small_fragment_index.emplace(proposed_index);
  }

  assert(found_index != kInvalidEntityId);

  return FragmentId(found_index);
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

  RawEntityId found_index = writer->GetOrCreateFragmentId(
      proposed_index, tok_id, std::move(hash));
  is_new = found_index == proposed_index;
  if (!is_new) {
    writer->available_big_fragment_index.emplace(proposed_index);
  }

  assert(found_index != kInvalidEntityId);

  return FragmentId(found_index);
}

void DatabaseWriterImpl::InitRecords(void) {
#define MX_EXEC_INITS(record) \
  for (const char *stmt : record::kInitStatements) { \
    if (stmt) { \
      db.Execute(stmt); \
    } \
  }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_EXEC_INITS)
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
#undef MX_EXEC_TEARDOWNS
}

#define MX_DEFINE_ADD_RECORD(name) \
    void DatabaseWriter::AddAsync(name record) { \
      impl->insertion_queue.enqueue(std::move(record)); \
    }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_ADD_RECORD)

#undef MX_DECLARE_ADD_RECORD

} // namespace mx
