// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <capnp/message.h>
#include <cstdint>
#include <filesystem>
#include <kj/array.h>
#include <memory>
#include <multiplier/PersistentMap.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/Types.h>
#include <multiplier/IndexStorage.h>
#include <mutex>
#include <pasta/Util/FileManager.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

#include "Codegen.h"

namespace mx {
class Executor;
class ProgressBar;
enum WorkerId : unsigned;
enum class DeclKind : unsigned char;
}  // namespace mx
namespace indexer {

enum CounterType : unsigned {
  kStatCompileCommand = 0u,
  kStatCompileJob,
  kStatAST,
  kStatCodeFragment,
  kStatUniqueCodeFragment,
  kStatSourceIRFragment
};

class IndexingContext;
class CodeGenerator;

template <typename T>
struct alignas(64) NextId {
  std::optional<T> id;
};

// State that lives at least as long as the server itself.
class ServerContext {
 public:
  sqlite::Connection db;
  mx::IndexStorage storage;

  void Flush(void);

  ~ServerContext(void);

  explicit ServerContext(std::filesystem::path db_path);
};

// Indexing Context counter
class IndexingCounter {
 public:
  virtual ~IndexingCounter() {
    PrintAll();
  }

  explicit IndexingCounter(void) {
    ResetAll();
  }

  uint64_t Increament(CounterType id) {
    if (id < kStatSourceIRFragment + 1) {
      return counter[id].fetch_add(mx::kMinEntityIdIncrement);
    }
    return 0ull;
  }

  uint64_t Decrement(CounterType id) {
    if (id < kStatSourceIRFragment + 1) {
      return counter[id].fetch_sub(mx::kMinEntityIdIncrement);
    }
    return 0ull;
  }

  private :

  void ResetAll(void);
  void PrintAll(void);

  std::atomic<uint64_t> counter[kStatSourceIRFragment + 1];
};

class IndexingCounterRes {
 public:
  inline explicit IndexingCounterRes(
      IndexingCounter &stat_, CounterType id) {
    stat_.Increament(id);
  }
};

// State that needs to live only as long as there are active indexing jobs
// underway.
class IndexingContext {
 public:
  ServerContext &server_context;

  IndexingCounter stat;

  // Tracks progress in parsing compile commands and turning them into compile
  // jobs.
  std::unique_ptr<mx::ProgressBar> command_progress;

  // Tracks progress in running compile jobs to produce ASTs.
  std::unique_ptr<mx::ProgressBar> ast_progress;

  // Tracks progress in partitioning an AST into fragments.
  std::unique_ptr<mx::ProgressBar> partitioning_progress;

  // Tracks progress in identifying fragments with IDs.
  std::unique_ptr<mx::ProgressBar> identification_progress;

  // Tracks progress in serializing fragments.
  std::unique_ptr<mx::ProgressBar> serialization_progress;

  // Tracks progress in saving tokenized files.
  std::unique_ptr<mx::ProgressBar> file_progress;

  const unsigned num_workers;

  // Version number to assign to all created fragments.
  //
  // NOTE(pag): This is explicitly out-of-data w.r.t. the backing storage. The
  //            purpose is to save an older version number so that when a client
  //            requests a fragment, we can see if we need to fixup the
  //            canonical declarations of things.
  const unsigned version_number;

  // Worker-local next counters for IDs.
  std::vector<NextId<mx::RawEntityId>> local_next_file_id;
  std::vector<NextId<mx::RawEntityId>> local_next_small_fragment_id;
  std::vector<NextId<mx::RawEntityId>> local_next_big_fragment_id;

  CodeGenerator codegen;

  explicit IndexingContext(ServerContext &server_context_,
                           const mx::Executor &exe_);

  ~IndexingContext(void);

  void InitializeProgressBars(void);

  // Get or create a file ID for the file at `file_path` with contents
  // `contents_hash`.
  std::pair<mx::RawEntityId, bool> GetOrCreateFileId(
      mx::WorkerId worker_id, std::filesystem::path file_path,
      const std::string &contents_hash);

  // Get or create a code ID for the top-level declarations that hash to
  // `code_hash`.
  std::pair<mx::RawEntityId, bool> GetOrCreateFragmentId(
      mx::WorkerId worker_id, const std::string &code_hash,
      uint64_t num_tokens);

  // Save the serialized contents of a file as a token list.
  void PutSerializedFile(mx::RawEntityId file_id, std::string);

  // Save the serialized top-level entities and the parsed tokens.
  void PutSerializedFragment(mx::RawEntityId id, std::string);

  // Link fragment declarations.
  void LinkDeclarations(mx::RawEntityId a, mx::RawEntityId b);

  // Link the mangled name of something to its entity ID.
  void LinkMangledName(const std::string &name, mx::RawEntityId eid);

  // Link an entity to the fragment that uses the entity.
  void LinkUseInFragment(mx::RawEntityId use, mx::RawEntityId user);

  // Link a direct reference to an entity from another entity.
  void LinkReferenceInFragment(mx::RawEntityId use, mx::RawEntityId user);

  // Save an entries of the form `(file_id, line_number, fragment_id)` over
  // the inclusive range `[start_line, end_line]` so that we can figure out
  // which fragments overlap which lines.
  void PutFragmentLineCoverage(mx::RawEntityId file_id,
                               mx::RawEntityId fragment_id,
                               unsigned start_line, unsigned end_line);
};

class SearchingContext {
 public:
  ServerContext &server_context;

  explicit SearchingContext(ServerContext &server_context_);
  virtual ~SearchingContext(void);

  // Next file ID for any `SearchingAction` to look at.
  std::atomic<mx::RawEntityId> local_next_file_id;

  // Set of `file_id:line_number` pairs where matches were approximately
  // found.
  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
  std::mutex line_results_lock;

  std::optional<std::string>
  GetSerializedFile(mx::RawEntityId file_id);
};

}  // namespace indexer
