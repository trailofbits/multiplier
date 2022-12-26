// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Database.h>

#include <cassert>
#include <deque>
#include <mutex>
#include <thread>
#include <variant>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <blockingconcurrentqueue.h>
#pragma GCC diagnostic pop

#include "SQLiteStore.h"
#include "ThreadLocal.h"

namespace mx {

static constexpr size_t kMaxTransactionSize = 10000;

#define MX_RECORD_VARIANT_ENTRY(name) , name

struct ExitSignal {};
struct FlushSignal {};
using QueueItem = std::variant<
    std::monostate, ExitSignal, FlushSignal
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_RECORD_VARIANT_ENTRY) >;
#undef MX_RECORD_VARIANT_ENTRY

// Thread-local database connection.
class alignas(64) WriterThreadState {
 private:
  sqlite::Connection db;

 public:
  std::optional<RawEntityId> available_file_id;
  std::optional<RawEntityId> available_small_fragment_id;
  std::optional<RawEntityId> available_big_fragment_id;

  // Get a file ID given a file hash.
  sqlite::Statement::Ptr set_file_id;
  sqlite::Statement::Ptr get_file_id;

  // Get a fragment ID given a file hash.
  sqlite::Statement::Ptr set_fragment_id;
  sqlite::Statement::Ptr get_fragment_id;

  ~WriterThreadState(void) {
    db.Close();
  }

  WriterThreadState(const std::filesystem::path &path)
      : db(path) {
    set_file_id = db.Prepare(
        "INSERT OR IGNORE INTO file_hash (file_id, hash) VALUES (?1, ?2)");
    get_file_id = db.Prepare(
        "SELECT file_id FROM file_hash WHERE hash = ?1");

    set_fragment_id = db.Prepare(
        R"(INSERT OR IGNORE INTO fragment_hash (fragment_id, file_token_id, hash)
           VALUES (?1, ?2, ?3))");
    get_fragment_id = db.Prepare(
        "SELECT fragment_id FROM fragment_hash WHERE hash = ?1");
  }

  RawEntityId GetOrCreateFileId(RawEntityId id, std::string hash) {
    set_file_id->BindValues(id, hash);
    db.Begin(false);
    set_file_id->ExecuteStep();
    get_file_id->BindValues(hash);
    get_file_id->ExecuteStep();
    db.Commit();
    get_file_id->GetResult().Columns(id);
    return id;
  }

  RawEntityId GetOrCreateFragmentId(
      RawEntityId frag_id, RawEntityId file_tok_id, std::string hash) {
    set_fragment_id->BindValues(frag_id, file_tok_id, hash);
    db.Begin(false);
    set_fragment_id->ExecuteStep();
    get_fragment_id->BindValues(hash);
    get_fragment_id->ExecuteStep();
    db.Commit();
    get_file_id->GetResult().Columns(frag_id);
    return frag_id;
  }
};

class DatabaseWriterImpl {
 public:

  const std::filesystem::path db_path;

  // Per-thread connection state with the database.
  ThreadLocal<WriterThreadState> thread_state;

  // The connection used on construction.
  sqlite::Connection init_exit_db;

  // Add some version info to the database. The number of records in the
  // versions table tells us whether or not we're currently indexing.
  sqlite::Statement::Ptr add_version;

  // A thread and it's multiple-producer, single-consumer
  std::thread bulk_insertion_thread;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;

  // Conditions on whether or not the bulk insertion queue main loop should
  // partially or fully exit.
  alignas(64) struct Conditions {
    bool should_exit{false};
    bool should_flush{false};
  } conditions;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  //
  // NOTE(pag): This is an in-memory "fast" version that is meant to hold
  //            the next state for `IndexStorage::next_file_id`.
  std::atomic<RawEntityId> next_file_id;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  //
  // NOTE(pag): This is an in-memory "fast" version that is meant to hold
  //            the next state for `IndexStorage::next_small_fragment_id`.
  std::atomic<RawEntityId> next_small_fragment_id;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  //
  // NOTE(pag): This is an in-memory "fast" version that is meant to hold
  //            the next state for `IndexStorage::next_big_fragment_id`.
  std::atomic<RawEntityId> next_big_fragment_id;

  struct {
    // The `async.db` can only be used inside of the `bulk_insertion_thread`.
    std::optional<sqlite::Connection> db;

    // Prepared statement for updating the database with the present values of
    // the above values.
    sqlite::Statement::Ptr update_metadata;

#define MX_DECLARE_INSERT_STMT(record) \
    sqlite::Statement::Ptr INSERT_INTO_ ## record;
  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_STMT)
#undef MX_DECLARE_INSERT_STMT

  } async;

#define MX_DECLARE_INSERT_METHOD(record) \
    void DoInsertAsync(const record &r) { \
      if (InsertAsync(r, *async.INSERT_INTO_ ## record)) { \
        async.INSERT_INTO_ ## record->ExecuteStep(); \
      } \
      async.INSERT_INTO_ ## record->Reset(); \
    } \
    bool InsertAsync(const record &, sqlite::Statement &);

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_INSERT_METHOD)
#undef MX_DECLARE_INSERT_METHOD

  DatabaseWriterImpl(const std::filesystem::path &db_path);
  ~DatabaseWriterImpl(void);

  void InitBulkInserter(const std::filesystem::path &path);

  void InitMetadata(void);
  void ExitMetadata(void);

  void UpdateMetadata(void);

  void InitRecords(void);
  void ExitRecords(void);
};

void DatabaseWriterImpl::ExitMetadata(void) {
  add_version->BindValues(0u);
  add_version->Execute();
}

// Initialize the metadata table. It only stores one row of data.
void DatabaseWriterImpl::InitMetadata(void) {

  add_version = init_exit_db.Prepare(
      R"(INSERT INTO version (action) VALUES (?1))");

  std::optional<sqlite::QueryResult> res;

  do {
    sqlite::Transaction transaction(init_exit_db);

    // Initialize the default metadata. The trick we use here is that we hard-code
    // a `rowid` of `1`, and so the implicit primary key constraint on `rowid`
    // will cause repeated initializations to be ignored.
    sqlite::Statement::Ptr meta_stmt = init_exit_db.Prepare(
        R"(INSERT OR IGNORE INTO metadata 
           (rowid, next_file_id, next_small_fragment_id, next_big_fragment_id)
           VALUES (1, 1, ?1, 1))");

    meta_stmt->BindValues(mx::kMaxBigFragmentId  /* next_small_fragment_id */);
    meta_stmt->ExecuteStep();

    add_version->BindValues(1u);
    add_version->Execute();

    res.emplace(init_exit_db.ExecuteAndGet(
        R"(SELECT next_file_id, next_small_fragment_id, next_big_fragment_id
           FROM metadata
           WHERE rowid = 1)"));
  } while (false);

  RawEntityId file_id = kInvalidEntityId;
  RawEntityId small_id = kInvalidEntityId;
  RawEntityId big_id = kInvalidEntityId;
  res->Columns(file_id, small_id, big_id);
  next_file_id.store(file_id);
  next_small_fragment_id.store(small_id);
  next_big_fragment_id.store(big_id);
}

// Update the metadata. We do this on every flush signal, as well as on the
// exit signal.
void DatabaseWriterImpl::UpdateMetadata(void) {
  async.update_metadata->BindValues(next_file_id.load(),
                                    next_small_fragment_id.load(),
                                    next_big_fragment_id.load());
  async.update_metadata->ExecuteStep();
}

// Create the bulk inserter thread and start it.
void DatabaseWriterImpl::InitBulkInserter(const std::filesystem::path &path) {

  auto bulk_inserter = [this] (void) {
    async.db.emplace(db_path);
    async.update_metadata = async.db->Prepare(
        R"(UPDATE metadata 
           SET next_file_id = MAX(next_file_id, ?1),
               next_small_fragment_id = MAX(next_small_fragment_id, ?2),
               next_big_fragment_id = MAX(next_big_fragment_id, ?3)
           WHERE rowid=1)");

#define MX_DEFINE_STMT(record) \
    async.INSERT_INTO_ ## record = \
        async.db->Prepare(record::kInsertStatement);
    MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DEFINE_STMT)
#undef MX_DEFINE_STMT

    for (; !conditions.should_exit; conditions.should_flush = false) {

      QueueItem item;

      // Go get the first thing.
      insertion_queue.wait_dequeue(item);

      sqlite::Transaction transaction(init_exit_db);

      unsigned transaction_size = 0u;

      do {
        std::visit(
            [this] (const auto &arg) {
              using arg_t = std::decay_t<decltype(arg)>;

              // Shouldn't happen.
              if constexpr (std::is_same_v<std::monostate, arg_t>) {

              // Exit signal.
              } else if constexpr (std::is_same_v<ExitSignal, arg_t>) {
                UpdateMetadata();
                conditions.should_exit = true;
                conditions.should_flush = true;

              // Flush signal.
              } else if constexpr (std::is_same_v<FlushSignal, arg_t>) {
                UpdateMetadata();
                conditions.should_flush = true;

              } else {
                DoInsertAsync(arg);
              }
            },
            item);

        if (transaction_size >= kMaxTransactionSize) {
          conditions.should_flush = true;
        }

        if (conditions.should_flush) {
          break;
        }

      // Try to get the next thing.
      } while (insertion_queue.try_dequeue(item) ||
               insertion_queue.wait_dequeue_timed(item, 10 * 1000));
    }

    async.db->Close();
    async.db.reset();
  };

  bulk_insertion_thread = std::thread(bulk_inserter);
}

DatabaseWriterImpl::~DatabaseWriterImpl(void) {
  insertion_queue.enqueue(ExitSignal{});
  bulk_insertion_thread.join();

//  for (const char *stmt : DatabaseWriter::kExitStatments) {
//    init_exit_db.Execute(stmt);
//  }

  ExitRecords();
  ExitMetadata();
}

DatabaseWriterImpl::DatabaseWriterImpl(
    const std::filesystem::path &db_path_)
    : db_path(db_path_),
      thread_state(
          [this] (unsigned) -> WriterThreadState * {
            return new WriterThreadState(db_path);
          },
          [] (void *ptr) {
            delete reinterpret_cast<WriterThreadState *>(ptr);
          }),
      init_exit_db(db_path),
      insertion_queue() {

  for (const char *stmt : DatabaseWriter::kInitStatements) {
    init_exit_db.Execute(stmt);
  }

  InitMetadata();
  InitRecords();


  InitBulkInserter(db_path);
}

bool DatabaseWriterImpl::InsertAsync(
    const FilePathRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.file_id.Pack(), record.path.lexically_normal());
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const FragmentLineCoverageRecord &record, sqlite::Statement &insert) {
  auto raw_file_id = record.file_id.Pack();
  if (raw_file_id != mx::kInvalidEntityId && record.first_line_number &&
      record.first_line_number <= record.last_line_number) {
    insert.BindValues(record.fragment_id.Pack(), raw_file_id,
                      record.first_line_number, record.last_line_number);
    return true;
  }
  return false;
}

bool DatabaseWriterImpl::InsertAsync(
    const SerializedFileRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.file_id.Pack(), record.data);
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const SerializedFragmentRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.data);
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const RedeclarationRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.decl_id.Pack(), record.redecl_id.Pack());
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const MangledNameRecord &record, sqlite::Statement &insert) {
  if (record.entity_id != mx::kInvalidEntityId &&
      !record.mangled_name.empty()) {
    insert.BindValues(record.entity_id, record.mangled_name);
    return true;
  }
  return false;
}

bool DatabaseWriterImpl::InsertAsync(
    const FragmentUsingEntityRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.entity_id);
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const EntityReferenceRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.entity_id);
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const SymbolNameRecord &record, sqlite::Statement &insert) {
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
  RawEntityId proposed_id;

  // Try to reuse a previously generated but unused file id.
  if (!writer->available_file_id) {
    proposed_id = impl->next_file_id.fetch_add(1u);
  } else {
    proposed_id = writer->available_file_id.value();
    writer->available_file_id.reset();
  }

  RawEntityId found_id = writer->GetOrCreateFileId(
      proposed_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_file_id.emplace(proposed_id);
  }

  return FileId(found_id);
}

// Get, or create and return, a fragment ID for the specific fragment hash.
SpecificEntityId<FragmentId>
DatabaseWriter::GetOrCreateSmallFragmentIdForHash(
    RawEntityId tok_id, std::string hash, bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_id;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_small_fragment_id) {
    proposed_id = impl->next_small_fragment_id.fetch_add(1u);
  } else {
    proposed_id = writer->available_small_fragment_id.value();
    writer->available_small_fragment_id.reset();
  }

  RawEntityId found_id = writer->GetOrCreateFragmentId(
      proposed_id, tok_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_small_fragment_id.emplace(proposed_id);
  }

  return FragmentId(found_id);
}

// Get, or create and return, a fragment ID for the specific fragment hash.
SpecificEntityId<FragmentId>
DatabaseWriter::GetOrCreateLargeFragmentIdForHash(
    RawEntityId tok_id, std::string hash, bool &is_new) {

  std::shared_ptr<WriterThreadState> writer = impl->thread_state.Lock();
  RawEntityId proposed_id;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer->available_big_fragment_id) {
    proposed_id = impl->next_big_fragment_id.fetch_add(1u);
  } else {
    proposed_id = writer->available_big_fragment_id.value();
    writer->available_big_fragment_id.reset();
  }

  RawEntityId found_id = writer->GetOrCreateFragmentId(
      proposed_id, tok_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer->available_big_fragment_id.emplace(proposed_id);
  }

  return FragmentId(found_id);
}

void DatabaseWriterImpl::InitRecords(void) {
#define MX_EXEC_INITS(record) \
  for (const char *stmt : record::kInitStatements) { \
    if (stmt) { \
      init_exit_db.Execute(stmt); \
    } \
  }

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_EXEC_INITS)
#undef MX_EXEC_INITS
}

void DatabaseWriterImpl::ExitRecords(void) {
#define MX_EXEC_TEARDOWNS(record) \
  for (const char *stmt : record::kExitStatements) { \
    if (stmt) { \
      init_exit_db.Execute(stmt); \
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
