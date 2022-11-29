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
#include <map>
#include <memory>
#include <multiplier/PersistentMap.h>
#include <multiplier/Types.h>
#include <multiplier/IndexStorage.h>
#include <mutex>
#include <pasta/Util/File.h>
#include <pasta/Util/FileManager.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <deque>

#include "Codegen.h"
#include "Executor.h"
#include "ProgressBar.h"

namespace mx {
class Executor;
class ProgressBar;
enum class DeclKind : unsigned char;
}  // namespace mx
namespace indexer {

enum WorkerId : unsigned;

class GlobalIndexingState;
class CodeGenerator;

struct EntityIdMap final : public std::unordered_map<const void *, mx::EntityId> {};
struct FileIdMap final : public std::unordered_map<pasta::File, mx::RawEntityId> {};
struct FileHashMap final : public std::unordered_map<pasta::File, std::string> {};
using TypeKey = std::pair<const void *, uint32_t>;
struct TypeIdMap final : public std::map<TypeKey, mx::EntityId> {};
struct PseudoOffsetMap final : public std::unordered_map<const void *, uint32_t> {};

// State that lives at least as long as the server itself.
class alignas(64) WorkerIndexingState {
 public:
  sqlite::Connection db;

  // Access to the database, shared with the API.
  mx::IndexStorage storage;

  // Worker-local next counters for IDs. There is a global version of these
  // that is an atomic counter. There is a deliberate race condition when
  // assigning IDs to things like fragments. There may be two or more worker
  // threads vying to assign the same fragment different IDs, and only one can
  // win. So, what ends up happening is that when we fail, we save off the ID
  // that didn't get assigned, and try to use it for the next thing. In general,
  // we want a dense ID space, as there are only so many bits allocated to
  // differerent things inside of a packed `RawEntityId`.
  std::optional<mx::RawEntityId> local_next_file_id;
  std::optional<mx::RawEntityId> local_next_small_fragment_id;
  std::optional<mx::RawEntityId> local_next_big_fragment_id;

  void Flush(void);

  ~WorkerIndexingState(void);

  explicit WorkerIndexingState(std::filesystem::path db_path);

  inline mx::IndexStorage &ClientSharedStorage(void) {
    return storage;
  }
};

// State that needs to live only as long as there are active indexing jobs
// underway.
class GlobalIndexingState {
 public:
  std::deque<WorkerIndexingState> server_context;

  inline WorkerIndexingState &PerWorkerState(WorkerId wid) {
    return server_context[wid];
  }

  // Tracks progress in parsing compile commands and turning them into compile
  // jobs.
  std::unique_ptr<ProgressBar> command_progress;

  // Tracks progress in running compile jobs to produce ASTs.
  std::unique_ptr<ProgressBar> ast_progress;

  // Tracks progress in partitioning an AST into fragments.
  std::unique_ptr<ProgressBar> partitioning_progress;

  // Tracks progress in identifying fragments with IDs.
  std::unique_ptr<ProgressBar> identification_progress;

  // Tracks progress in serializing fragments.
  std::unique_ptr<ProgressBar> serialization_progress;

  // Tracks progress in saving tokenized files.
  std::unique_ptr<ProgressBar> file_progress;

  const unsigned num_workers;

  Executor executor;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  //
  // NOTE(pag): This is an in-memory "fast" version that is meant to hold
  //            the next state for `IndexStorage::next_file_id`.
  std::atomic<mx::RawEntityId> next_file_id;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  //
  // NOTE(pag): This is an in-memory "fast" version that is meant to hold
  //            the next state for `IndexStorage::next_small_fragment_id`.
  std::atomic<mx::RawEntityId> next_small_fragment_id;

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
  std::atomic<mx::RawEntityId> next_big_fragment_id;

  // MLIR code generator.
  CodeGenerator codegen;

  explicit GlobalIndexingState(std::filesystem::path db_path,
                               const Executor &exe_);

  ~GlobalIndexingState(void);

  void InitializeProgressBars(void);

  // Get or create a file ID for the file at `file_path` with contents
  // `contents_hash`.
  std::pair<mx::RawEntityId, bool> GetOrCreateFileId(
      WorkerId worker_id, std::filesystem::path file_path,
      const std::string &contents_hash);

  // Get or create a code ID for the top-level declarations that hash to
  // `code_hash`.
  std::pair<mx::RawEntityId, bool> GetOrCreateFragmentId(
      WorkerId worker_id, const std::string &code_hash,
      uint64_t num_tokens);

  // Save the serialized contents of a file as a token list.
  void PutSerializedFile(WorkerId worker_id_, mx::RawEntityId file_id,
                         std::string);

  // Save the serialized top-level entities and the parsed tokens.
  void PutSerializedFragment(WorkerId worker_id_, mx::RawEntityId id,
                             std::string);

  // Link fragment declarations.
  void LinkDeclarations(WorkerId worker_id_, mx::RawEntityId a,
                        mx::RawEntityId b);

  // Link the mangled name of something to its entity ID.
  void LinkMangledName(WorkerId worker_id_, const std::string &name,
                       mx::RawEntityId eid);

  // Link an entity to the fragment that uses the entity.
  void LinkUseInFragment(WorkerId worker_id_, mx::RawEntityId use,
                         mx::RawEntityId user);

  // Link a direct reference to an entity from another entity.
  void LinkReferenceInFragment(WorkerId worker_id_, mx::RawEntityId use,
                               mx::RawEntityId user);

  // Save an entries of the form `(file_id, line_number, fragment_id)` over
  // the inclusive range `[start_line, end_line]` so that we can figure out
  // which fragments overlap which lines.
  void PutFragmentLineCoverage(WorkerId worker_id_, mx::RawEntityId file_id,
                               mx::RawEntityId fragment_id,
                               unsigned start_line, unsigned end_line);
};

}  // namespace indexer
