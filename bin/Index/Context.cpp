// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <filesystem>
#include <glog/logging.h>
#include <multiplier/AST.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <string>
#include <system_error>
#include <utility>
#include <vector>
#include <mutex>

#include "Codegen.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {

WorkerIndexingState::WorkerIndexingState(std::filesystem::path db_path)
    : db(db_path),
      storage(db) {}

WorkerIndexingState::~WorkerIndexingState(void) {
  Flush();
}

void WorkerIndexingState::Flush(void) {
  ClientSharedStorage().Flush();
}

GlobalIndexingState::GlobalIndexingState(std::filesystem::path db_path,
                                 const mx::Executor &exe_)
    : num_workers(exe_.NumWorkers()),
      executor(exe_) {
  for(size_t i = 0; i < num_workers; ++i) {
    server_context.emplace_back(db_path);
  }

  WorkerIndexingState &worker = server_context.front();
  mx::IndexStorage &storage = worker.ClientSharedStorage();

  // Clients all default-initialize their version numbers to `0`, so we
  // default the server to `1` so that clients are always out-of-date.
  storage.version_number.store_if_empty(1u);
  storage.next_file_id.store_if_empty(mx::kMinEntityIdIncrement);
  storage.next_small_fragment_id.store_if_empty(mx::kMaxBigFragmentId);
  storage.next_big_fragment_id.store_if_empty(mx::kMinEntityIdIncrement);

  storage.version_number.fetch_add(1);

  // Load the in the most recent versions of the IDs.
  next_file_id.store(storage.next_file_id.load());
  next_small_fragment_id.store(storage.next_small_fragment_id.load());
  next_big_fragment_id.store(storage.next_big_fragment_id.load());
}

GlobalIndexingState::~GlobalIndexingState(void) {
  WorkerIndexingState &worker = server_context.front();
  mx::IndexStorage &storage = worker.ClientSharedStorage();
  storage.version_number.fetch_add(1);

  // Store the most up-to-date versions of the IDs to the db.
  storage.next_file_id.store(next_file_id.load());
  storage.next_small_fragment_id.store(next_small_fragment_id.load());
  storage.next_big_fragment_id.store(next_big_fragment_id.load());
}

void GlobalIndexingState::InitializeProgressBars(void) {
  std::chrono::seconds report_freq = std::chrono::seconds(1);
  command_progress.reset(new mx::ProgressBar("1) Command interpretation",
                                             report_freq));
  ast_progress.reset(new mx::ProgressBar("2) Parsing / AST building",
                                         report_freq));
  file_progress.reset(new mx::ProgressBar("3) File serialization",
                                          report_freq));
  partitioning_progress.reset(new mx::ProgressBar("4) Fragment partitioning",
                                                  report_freq));
  identification_progress.reset(new mx::ProgressBar("5) Fragment identification",
                                                    report_freq));
  serialization_progress.reset(new mx::ProgressBar("6) Fragment serialization",
                                                   report_freq));

  command_progress->SetNumWorkers(num_workers);
  ast_progress->SetNumWorkers(num_workers);
  file_progress->SetNumWorkers(num_workers);
  partitioning_progress->SetNumWorkers(num_workers);
  identification_progress->SetNumWorkers(num_workers);
  serialization_progress->SetNumWorkers(num_workers);
}

// Get or create a file ID for the file at `file_path` with contents
// `contents_hash`.
std::pair<mx::RawEntityId, bool> GlobalIndexingState::GetOrCreateFileId(
    mx::WorkerId worker_id, std::filesystem::path file_path,
    const std::string &contents_hash) {

  WorkerIndexingState &worker = PerWorkerState(worker_id);
  mx::IndexStorage &storage = worker.ClientSharedStorage();

  std::optional<mx::RawEntityId> &maybe_id = worker.local_next_file_id;
  mx::RawEntityId created_id = mx::kInvalidEntityId;
  if (!maybe_id.has_value()) {
    created_id = next_file_id.fetch_add(mx::kMinEntityIdIncrement);
  } else {
    created_id = std::move(maybe_id.value());
    maybe_id.reset();
  }

  mx::RawEntityId file_id = storage.file_hash_to_file_id.GetOrSet(
      contents_hash, created_id);

  CHECK_LT(file_id, mx::kMaxFileId);

  std::string path_str = file_path.lexically_normal().generic_string();
  storage.file_id_to_path.Insert(file_id, path_str);
  if (file_id == created_id) {
    return {file_id, true};

  } else {
    maybe_id = created_id;  // Put it back in the worker-specific cache.
    return {file_id, false};
  }
}

// Get or create a code ID for the top-level declarations that hash to
// `code_hash`.
std::pair<mx::RawEntityId, bool> GlobalIndexingState::GetOrCreateFragmentId(
    mx::WorkerId worker_id, const std::string &code_hash,
    uint64_t num_tokens) {

  WorkerIndexingState &worker = PerWorkerState(worker_id);
  mx::IndexStorage &storage = worker.ClientSharedStorage();

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  //
  // NOTE(pag): We have a fudge factor here of `3x` to account for macro
  //            expansions.
  if ((num_tokens * 3u) >= mx::kNumTokensInBigFragment) {
    auto &maybe_id = worker.local_next_big_fragment_id;
    mx::RawEntityId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = next_big_fragment_id.fetch_add(mx::kMinEntityIdIncrement);
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id.reset();
    }

    mx::RawEntityId code_id = storage.code_hash_to_fragment_id.GetOrSet(
        code_hash, created_id);

    CHECK_LT(code_id, mx::kMaxBigFragmentId);
    if (code_id == created_id) {
      return {code_id, true};

    } else {
      maybe_id = created_id;  // Put it back in the worker-specific cache.
      return {code_id, false};
    }

  // "Small codes" have IDs in the range
  // `[mx::mx::kMaxNumBigPendingFragments, ...)`.
  } else {
    auto &maybe_id = worker.local_next_small_fragment_id;
    mx::RawEntityId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = next_small_fragment_id.fetch_add(mx::kMinEntityIdIncrement);
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id.reset();
    }

    mx::RawEntityId code_id = storage.code_hash_to_fragment_id.GetOrSet(
        code_hash, created_id);

    CHECK_GE(code_id, mx::kMaxBigFragmentId);
    if (code_id == created_id) {
      return {code_id, true};

    } else {
      maybe_id = created_id;  // Put it back in the worker-specific cache.
      return {code_id, false};
    }
  }
}

// Save the tokenized contents of a file.
void GlobalIndexingState::PutSerializedFile(
    mx::WorkerId worker_id, mx::RawEntityId id, std::string data) {
  WorkerIndexingState &worker = PerWorkerState(worker_id);
  mx::IndexStorage &storage = worker.ClientSharedStorage();
  storage.file_id_to_serialized_file.Set(id, std::move(data));
}

// Save the serialized top-level entities and the parsed tokens.
void GlobalIndexingState::PutSerializedFragment(mx::WorkerId worker_id,
                                            mx::RawEntityId id,
                                            std::string data) {
  WorkerIndexingState &worker = PerWorkerState(worker_id);
  mx::IndexStorage &storage = worker.ClientSharedStorage();
  storage.fragment_id_to_serialized_fragment.Set(id, std::move(data));
}

// Link fragment declarations.
void GlobalIndexingState::LinkDeclarations(mx::WorkerId worker_id,
                                           mx::RawEntityId a,
                                           mx::RawEntityId b) {
  if (a != b && a != mx::kInvalidEntityId && b != mx::kInvalidEntityId) {
    WorkerIndexingState &worker = PerWorkerState(worker_id);
    mx::IndexStorage &storage = worker.ClientSharedStorage();
    storage.entity_redecls.Insert(a, b);
    storage.entity_redecls.Insert(b, a);
  }
}

// Link the mangled name of something to its entity ID.
void GlobalIndexingState::LinkMangledName(mx::WorkerId worker_id,
                                          const std::string &name,
                                          mx::RawEntityId eid) {
  if (!name.empty() && eid != mx::kInvalidEntityId) {
    WorkerIndexingState &worker = PerWorkerState(worker_id);
    mx::IndexStorage &storage = worker.ClientSharedStorage();
    storage.entity_id_to_mangled_name.Insert(eid, name);
    storage.mangled_name_to_entity_id.Insert(name, eid);
  }
}

// Link an entity to the fragment that uses the entity.
void GlobalIndexingState::LinkUseInFragment(mx::WorkerId worker_id,
                                            mx::RawEntityId use,
                                            mx::RawEntityId user) {
  if (use != mx::kInvalidEntityId && user != mx::kInvalidEntityId) {
    WorkerIndexingState &worker = PerWorkerState(worker_id);
    mx::IndexStorage &storage = worker.ClientSharedStorage();
    storage.entity_id_use_to_fragment_id.Insert(use, user);
  }
}

// Link a direct reference to an entity from another entity.
void GlobalIndexingState::LinkReferenceInFragment(mx::WorkerId worker_id,
                                                  mx::RawEntityId use,
                                                  mx::RawEntityId user) {
  if (use != mx::kInvalidEntityId && user != mx::kInvalidEntityId) {
    WorkerIndexingState &worker = PerWorkerState(worker_id);
    mx::IndexStorage &storage = worker.ClientSharedStorage();
    storage.entity_id_reference.Insert(use, user);
  }
}

// Save an entries of the form `(file_id, line_number, fragment_id)` over
// the inclusive range `[start_line, end_line]` so that we can figure out
// which fragments overlap which lines. We use this index to go from regular
// expression matches or Weggli syntax matches on files into matches inside of
// fragments.
void GlobalIndexingState::PutFragmentLineCoverage(
    mx::WorkerId worker_id,
    mx::RawEntityId file_id, mx::RawEntityId fragment_id,
    unsigned start_line, unsigned end_line) {

  WorkerIndexingState &worker = PerWorkerState(worker_id);
  mx::IndexStorage &storage = worker.ClientSharedStorage();
  storage.file_fragment_ids.Insert(file_id, fragment_id);
  for (auto i = start_line; i <= end_line; ++i) {
    storage.file_fragment_lines.Insert(file_id, i, fragment_id);
  }
}

}  // namespace indexer
