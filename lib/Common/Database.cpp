// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Database.h>

#include <cassert>
#include <deque>
#include <multiplier/SQLiteStore.h>
//#include <multiplier/SymbolDatabase.h>
//#include <multiplier/Entities/DeclKind.h>
#include <mutex>
#include <thread>
#include <variant>

//#include "PersistentMap.h"
//#include "PersistentAtomicStorage.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <blockingconcurrentqueue.h>
#pragma GCC diagnostic pop

namespace mx {
//namespace {
//
//enum MetadataName : char {
//  // The next file ID that we can assign. File IDs are assigned in generally
//  // increasing order. The assignment isn't necessarily strictly linear, i.e.
//  // there may be some gaps, mostly just due to benign race conditions when
//  // multiple indexer threads are used.
//  kNextFileId,
//
//  // The next ID for a "small code" fragment. Small code fragments have less
//  // than 2^16 tokens in them, i.e. most fragments are small code fragments.
//  // Fragment IDs for small code fragments fall in the range `[2^16, inf)`.
//  kNextSmallCodeId,
//
//  // The next ID for a "big code" fragment. Big code fragments have at least
//  // 2^16 tokens in them. Most fragments do not fit this category; likely this
//  // is the result of auto-generated code. We rely on there being fewer than
//  // 2^16 of such fragments, and the IDs for these fall in the range of
//  // `[1, 2^16)`,
//  kNextBigCodeId,
//};
//
//}  // namespace
//
//class SynchronousIndexStorageImpl {
// public:
//  sqlite::Connection &db;
//
//  // The next file ID that can be assigned. This represents an upper bound on
//  // the total number of file IDs.
//  PersistentAtomicStorage<kNextFileId, RawEntityId>
//      next_file_id;
//
//  // The next ID for a "small fragment." A small fragment has fewer than
//  // `kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
//  // are more common, and require fewer bits to encode token offsets inside of
//  // the packed `EntityId` for tokens.
//  PersistentAtomicStorage<kNextSmallCodeId, RawEntityId>
//      next_small_fragment_id;
//
//  // The next ID for a "big fragment." A big fragment has at least
//  // `kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
//  // are less common, so we reserve space for fewer of them (typically there is
//  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
//  // to represent token offsets inside of the packed `EntityId` for tokens,
//  // but because we reserve the low ID space for big fragment IDs, we know that
//  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
//  // bit for token offset bits.
//  PersistentAtomicStorage<kNextBigCodeId, RawEntityId>
//      next_big_fragment_id;
//
//  // The next indexing version number. This is incremented prior to starting
//  // an indexing run, and just after. The double-increment is there just in
//  // case some clients come along and issue some queries prior to indexing being
//  // finished. We want best-effort resolution of definitions/redeclarations
//  // during this time, but we don't want to commit to those results, just in
//  // case there are more redeclarations that come in betwween the client request
//  // and finishing indexing.
//  PersistentAtomic<kIndexingVersion, unsigned> version_number;
//
//  // Maps file IDs to their absolute path, as well as to their token lists.
//  PersistentSet<kFileIdToPath, RawEntityId, std::string>
//      file_id_to_path;
//
//  // Maps file IDs to a serialized `rpc::File` data structure.
//  PersistentMap<kFileIdToSerializedFile, RawEntityId, std::string>
//      file_id_to_serialized_file;
//
//  // A set of `(file_id, fragment_id)` pairs for mapping from files to the
//  // fragments contained in those files.
//  PersistentSet<kFileIdToFragmentId,
//                    RawEntityId  /* file id */,
//                    RawEntityId  /* fragment id */>
//      file_fragment_ids;
//
//  // A set of `(file_id, line number, fragment_id)` triples for mapping from
//  // search results to the fragments that might overlap with those search
//  // results.
//  PersistentSet<kFileIdAndLineNumberToFragmentId,
//                    RawEntityId  /* file id */,
//                    unsigned  /* line number */,
//                    RawEntityId  /* fragment id */>
//      file_fragment_lines;
//
//  // Maps a hash of a file's contents to an ID for that file.
//  PersistentMap<kFileHashToFileId, std::string, RawEntityId>
//      file_hash_to_file_id;
//
//  // Maps an aggregate key of the form
//  //
//  //    <file hash>:<line>:<column>:<tokens hash>:<odr hash 0>:...:<odr hash N>
//  //
//  // to "fragment ids," that is, the ID of the serialized code containing one or
//  // more top-level declarations.
//  PersistentMap<kFragmentHashToFragmentId, std::string, RawEntityId>
//      code_hash_to_fragment_id;
//
//  // Maps a fragment ID to the serialized `rpc::Fragment` data structure.
//  PersistentMap<kFragmentIdToSerializedFragment,
//                    RawEntityId, std::string>
//      fragment_id_to_serialized_fragment;
//
//  // Each time we come across a redeclarable declaration, we add in the TU-
//  // specific complete graph of `(redecl_i, redecl_j)` pairs to this set, so
//  // that given a declaration ID, we can try to expand out and find the set of
//  // all redeclarations by hopping from one of these graphs to another.
//  PersistentSet<kEntityIdRedecls, RawEntityId, RawEntityId>
//      entity_redecls;
//
//  // Maps entity IDs of functions and (non-local) variables to their mangled
//  // names. We use this in combination with `mangled_name_to_entity_id` to
//  // find redeclarations of a given entity.
//  PersistentSet<kEntityIdToMangledName, RawEntityId, std::string>
//      entity_id_to_mangled_name;
//
//  // Maps mangled names of functions and (non-local) variables to their
//  // entity IDs.
//  PersistentSet<kMangledNameToEntityId, std::string, RawEntityId>
//      mangled_name_to_entity_id;
//
//  // Maps uses of entities to the IDs of fragments that use the entities.
//  PersistentSet<kEntityIdUseToFragmentId, RawEntityId, RawEntityId>
//      entity_id_use_to_fragment_id;
//
//  // Keeps track of references, e.g. `DeclRefExpr`, the fields accessed by
//  // `MemberExpr`, etc.
//  PersistentSet<kEntityIdReference, RawEntityId, RawEntityId>
//      entity_id_reference;
//
//  // SQLite database. Used for things like symbol searches.
//  SymbolDatabase database;
//};
//
//SynchronousIndexStorage::SynchronousIndexStorage(sqlite::Connection &db)
//    : db(db),
//      next_file_id(db),
//      next_small_fragment_id(db),
//      next_big_fragment_id(db),
//      version_number(db),
//      file_id_to_path(db),
//      file_id_to_serialized_file(db),
//      file_fragment_ids(db),
//      file_fragment_lines(db),
//      file_hash_to_file_id(db),
//      code_hash_to_fragment_id(db),
//      fragment_id_to_serialized_fragment(db),
//      entity_redecls(db),
//      entity_id_to_mangled_name(db),
//      mangled_name_to_entity_id(db),
//      entity_id_use_to_fragment_id(db),
//      entity_id_reference(db),
//      database(db) {}
//
//SynchronousIndexStorage::~SynchronousIndexStorage(void) {}
//
//void SynchronousIndexStorage::Flush(void) {
//  database.Flush();
//}
//
//// Return the set of redeclarations of an entity.
//std::vector<RawEntityId> SynchronousIndexStorage::FindRedeclarations(
//    EntityId eid) {
//  VariantId vid = eid.Unpack();
//  assert(std::holds_alternative<DeclarationId>(vid));
//
//  // All of the declaration kinds need to actually match.
//  DeclarationId did = std::get<DeclarationId>(vid);
//  std::vector<RawEntityId> next_new_ids;
//  std::vector<RawEntityId> all_ids;
//  std::vector<RawEntityId> new_ids;
//  next_new_ids.reserve(16);
//  all_ids.reserve(16);
//  new_ids.reserve(16);
//  next_new_ids.push_back(eid);
//
//  // Expand the set of IDs via name mangling.
//  switch (did.kind) {
//    case DeclKind::FUNCTION:
//    case DeclKind::CXX_METHOD:
//    case DeclKind::CXX_DESTRUCTOR:
//    case DeclKind::CXX_CONVERSION:
//    case DeclKind::CXX_CONSTRUCTOR:
//    case DeclKind::CXX_DEDUCTION_GUIDE:
//
//    case DeclKind::VAR:
//    case DeclKind::DECOMPOSITION:
//    case DeclKind::IMPLICIT_PARAM:
//    case DeclKind::OMP_CAPTURED_EXPR:
//    case DeclKind::PARM_VAR:
//    case DeclKind::VAR_TEMPLATE_SPECIALIZATION:
//    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
//      entity_id_to_mangled_name.GetByField<0>(
//          next_new_ids[0],
//          [&next_new_ids, this] (RawEntityId, std::string mangled_name) {
//
//            mangled_name_to_entity_id.GetByField<0>(
//                std::move(mangled_name),
//                [&next_new_ids] (std::string, RawEntityId new_id) {
//                  next_new_ids.push_back(new_id);
//                  return true;
//                });
//            return true;
//          });
//      break;
//
//    default:
//      break;
//  }
//
//  all_ids.reserve(next_new_ids.size());
//
//  // Expand the set of declarations via fixpoint using the redeclaration
//  // graph.
//  while (!next_new_ids.empty()) {
//    next_new_ids.swap(new_ids);
//    next_new_ids.clear();
//    for (RawEntityId new_id : new_ids) {
//      if (std::find(all_ids.begin(), all_ids.end(), new_id) != all_ids.end()) {
//        continue;
//      }
//
//      const EntityId new_eid(new_id);
//      const VariantId new_vid = new_eid.Unpack();
//      if (!std::holds_alternative<DeclarationId>(new_vid)) {
//        assert(false);
//        continue;
//      }
//
//      const DeclarationId new_did = std::get<DeclarationId>(new_vid);
//      if (new_did.kind != did.kind) {
//        assert(false);
//        continue;
//      }
//
//      all_ids.push_back(new_id);
//
//      entity_redecls.GetByField<0>(
//          new_id,
//          [&next_new_ids] (RawEntityId, RawEntityId other_id) {
//            next_new_ids.push_back(other_id);
//            return true;
//          });
//    }
//  }
//
//  // Sort the redeclaration IDs to that they are always in the same order,
//  // regardless of which one we ask for first, then partition them and move
//  // the definitions before the declarations.
//  std::sort(all_ids.begin(), all_ids.end());
//  std::partition(
//      all_ids.begin(), all_ids.end(),
//      [] (RawEntityId eid) {
//        return std::get<DeclarationId>(
//            EntityId(eid).Unpack()).is_definition;
//      });
//
//  return all_ids;
//}
//
//std::optional<std::string>
//SynchronousIndexStorage::GetSerializedFile(RawEntityId file_id) {
//  return file_id_to_serialized_file.TryGet(file_id);
//}


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
        R"(INSERT OR IGNORE INTO fragment_hash (fragment_id, file_id, hash)
           VALUES (?1, ?2, ?3))");
    get_fragment_id = db.Prepare(
        "SELECT fragment_id FROM fragment_hash WHERE hash = ?1");
  }

  RawEntityId GetOrCreateFileId(RawEntityId id, std::string hash) {
    db.Begin(false);
    set_file_id->BindValues(id, hash);
    set_file_id->ExecuteStep();
    get_file_id->BindValues(hash);
    get_file_id->ExecuteStep();
    db.Commit();
    get_file_id->GetResult().Columns(id);
    return id;
  }

  RawEntityId GetOrCreateFragmentId(RawEntityId frag_id, RawEntityId file_id,
                                    std::string hash) {
    db.Begin(false);
    set_fragment_id->BindValues(frag_id, file_id, hash);
    set_fragment_id->ExecuteStep();
    get_fragment_id->BindValues(hash);
    get_fragment_id->ExecuteStep();
    db.Commit();
    get_file_id->GetResult().Columns(frag_id);
    return frag_id;
  }

  static WriterThreadState &From(const std::shared_ptr<DatabaseWriterImpl> &);
};

class DatabaseWriterImpl {
 public:
  // TODO(pag): This approach precludes having more than one database open.
  static thread_local std::shared_ptr<WriterThreadState> tWriterThreadState;

  std::mutex writer_threads_lock;
  std::deque<WriterThreadState> writer_thread_state;

  const std::filesystem::path db_path;

  // The connection used on construction.
  sqlite::Connection init_exit_db;

  std::thread bulk_insertion_thread;
  moodycamel::BlockingConcurrentQueue<QueueItem> insertion_queue;

  alignas(64) struct Conditions {
    bool should_exit{false};
    bool should_flush{false};
  } conditions;

  // Are any of the below bits of metadata in a dirty state?
  std::atomic_flag metadata_is_dirty;

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
  void UpdateMetadata(void);

  void InitRecords(void);
  void ExitRecords(void);
};

// Initialize the metadata table. It only stores one row of data.
void DatabaseWriterImpl::InitMetadata(void) {
  std::optional<sqlite::QueryResult> res;

  do {
    sqlite::Transaction transaction(init_exit_db);
    init_exit_db.Execute(
        R"(CREATE TABLE metadata IF NOT EXISTS ("
             next_file_id INT,
             next_small_fragment_id INT,
             next_big_fragment_id INT
         "))");

    // Initialize the default metadata. The trick we use here is that we hard-code
    // a `rowid` of `1`, and so the implicit primary key constraint on `rowid`
    // will cause repeated initializations to be ignored.
    sqlite::Statement::Ptr stmt = init_exit_db.Prepare(
        R"(INSERT OR IGNORE INTO metadata 
           (rowid, next_file_id, next_small_fragment_id, next_big_fragment_id)
           VALUES (1, 1, ?1, 1)");

    stmt->BindValues(mx::kMaxBigFragmentId  /* next_small_fragment_id */);
    stmt->ExecuteStep();

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

        if (transaction_size >= 10000) {
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
}

DatabaseWriterImpl::DatabaseWriterImpl(
    const std::filesystem::path &db_path_)
    : db_path(db_path_),
      init_exit_db(db_path) {

  InitMetadata();
  InitRecords();

  for (const char *stmt : DatabaseWriter::kInitStatements) {
    init_exit_db.Execute(stmt);
  }

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
    const SerializedFragmentRecord &record, sqlite::Statement &insert) {
  insert.BindValues(record.fragment_id.Pack(), record.file_id.Pack(),
                    record.data);
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
  insert.BindValues(record.from_id, record.to_id);
  return true;
}

bool DatabaseWriterImpl::InsertAsync(
    const SymbolNameRecord &record, sqlite::Statement &insert) {
  if (!record.symbol_name.empty()) {
    insert.BindValues(record.entity_id, record.symbol_name);
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

  WriterThreadState &writer = WriterThreadState::From(impl);
  RawEntityId proposed_id;

  // Try to reuse a previously generated but unused file id.
  if (!writer.available_file_id) {
    proposed_id = impl->next_file_id.fetch_add(1u);
  } else {
    proposed_id = writer.available_file_id.value();
    writer.available_file_id.reset();
  }

  RawEntityId found_id = writer.GetOrCreateFileId(
      proposed_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer.available_file_id.emplace(proposed_id);
  }

  return FileId(found_id);
}

// Get, or create and return, a fragment ID for the specific fragment hash.
SpecificEntityId<FragmentId>
DatabaseWriter::GetOrCreateSmallFragmentIdForHash(
    SpecificEntityId<FileTokenId> tok_id, std::string hash, bool &is_new) {

  WriterThreadState &writer = WriterThreadState::From(impl);
  RawEntityId proposed_id;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer.available_small_fragment_id) {
    proposed_id = impl->next_small_fragment_id.fetch_add(1u);
  } else {
    proposed_id = writer.available_small_fragment_id.value();
    writer.available_small_fragment_id.reset();
  }

  RawEntityId found_id = writer.GetOrCreateFragmentId(
      proposed_id, tok_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer.available_small_fragment_id.emplace(proposed_id);
  }

  return FragmentId(found_id);
}

// Get, or create and return, a fragment ID for the specific fragment hash.
SpecificEntityId<FragmentId>
DatabaseWriter::GetOrCreateLargeFragmentIdForHash(
    SpecificEntityId<FileTokenId> tok_id, std::string hash, bool &is_new) {

  WriterThreadState &writer = WriterThreadState::From(impl);
  RawEntityId proposed_id;

  // Try to reuse a previously generated but unused fragment id.
  if (!writer.available_big_fragment_id) {
    proposed_id = impl->next_big_fragment_id.fetch_add(1u);
  } else {
    proposed_id = writer.available_big_fragment_id.value();
    writer.available_big_fragment_id.reset();
  }

  RawEntityId found_id = writer.GetOrCreateFragmentId(
      proposed_id, tok_id, std::move(hash));
  is_new = found_id == proposed_id;
  if (!is_new) {
    writer.available_big_fragment_id.emplace(proposed_id);
  }

  return FragmentId(found_id);
}

// Return the thread-local writer thread state from this
WriterThreadState &WriterThreadState::From(
    const std::shared_ptr<DatabaseWriterImpl> &self) {
  if (DatabaseWriterImpl::tWriterThreadState) {
    return *DatabaseWriterImpl::tWriterThreadState;
  }

  std::lock_guard<std::mutex> locker(self->writer_threads_lock);
  WriterThreadState &writer =
      self->writer_thread_state.emplace_back(self->db_path);
  std::shared_ptr<WriterThreadState> ptr(self, &writer);
  DatabaseWriterImpl::tWriterThreadState = std::move(ptr);
  return writer;
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
