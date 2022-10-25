// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <glog/logging.h>
#include <multiplier/AST.h>
#include <multiplier/Executor.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

#include "Codegen.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {

ServerContext::ServerContext(std::filesystem::path db_path)
    : db(db_path),
      storage(db) {

  // Clients all default-initialize their version numbers to `0`, so we default
  // the server to `1` so that clients are always out-of-date.
  storage.version_number.store(static_cast<unsigned>(storage.meta_to_value.GetOrSet(
      mx::MetadataName::kIndexingVersion, 1u)));

  storage.next_file_id.store(storage.meta_to_value.GetOrSet(
      mx::MetadataName::kNextFileId, mx::kMinEntityIdIncrement));
  storage.next_small_fragment_id.store(storage.meta_to_value.GetOrSet(
      mx::MetadataName::kNextSmallCodeId, mx::kMaxBigFragmentId));
  storage.next_big_fragment_id.store(storage.meta_to_value.GetOrSet(
      mx::MetadataName::kNextBigCodeId, mx::kMinEntityIdIncrement));
}

ServerContext::~ServerContext(void) {
  Flush();
}

void ServerContext::Flush(void) {
  storage.meta_to_value.Set(mx::MetadataName::kIndexingVersion, storage.version_number.load());
  storage.meta_to_value.Set(mx::MetadataName::kNextFileId, storage.next_file_id.load());
  storage.meta_to_value.Set(mx::MetadataName::kNextSmallCodeId, storage.next_small_fragment_id.load());
  storage.meta_to_value.Set(mx::MetadataName::kNextBigCodeId, storage.next_big_fragment_id.load());
  storage.database.Flush();
}

void IndexingCounter::ResetAll(void) {
  for(auto id = 0u; id < kStatSourceIRFragment + 1u; id++) {
    counter[id].store(mx::kInvalidEntityId);
  }
}

void IndexingCounter::PrintAll(void) {
  const char *id_name[6] = {
      "StatCompileCommand", "StatCompileJob", "StatAST",
      "StatCodeFragment", "StatUniqueCodeFragment",
      "StatSourceIRFragment"
  };
  for(auto id = 0u; id < kStatSourceIRFragment + 1u; id++) {
    std::cerr << id_name[id] << " : " <<  counter[id].load() << "\n";
  }
}

IndexingContext::IndexingContext(ServerContext &server_context_,
                                 const mx::Executor &exe_)
    : server_context(server_context_),
      num_workers(exe_.NumWorkers()),
      version_number(static_cast<unsigned>(
          server_context.storage.version_number.fetch_add(1u))),
      local_next_file_id(num_workers),
      local_next_small_fragment_id(num_workers),
      local_next_big_fragment_id(num_workers) {

  // Save the updated version number.
  server_context.Flush();
}

IndexingContext::~IndexingContext(void) {

  // Second increment (first is in constructor) so that client requests during
  // the indexing process can be re-refreshed later for possibly newer info.
  server_context.storage.version_number.fetch_add(1u);

  // Save the updated version number.
  server_context.Flush();
}

void IndexingContext::InitializeProgressBars(void) {
  command_progress.reset(new mx::ProgressBar("1) Command interpretation",
                                             std::chrono::seconds(1)));
  ast_progress.reset(new mx::ProgressBar("2) Parsing / AST building",
                                         std::chrono::seconds(1)));
  file_progress.reset(new mx::ProgressBar("3) File serialization",
                                          std::chrono::seconds(1)));
  partitioning_progress.reset(new mx::ProgressBar("4) Fragment partitioning",
                                                  std::chrono::seconds(1)));
  identification_progress.reset(new mx::ProgressBar("5) Fragment identification",
                                                    std::chrono::seconds(1)));
  serialization_progress.reset(new mx::ProgressBar("6) Fragment serialization",
                                              std::chrono::seconds(1)));

  command_progress->SetNumWorkers(num_workers);
  ast_progress->SetNumWorkers(num_workers);
  file_progress->SetNumWorkers(num_workers);
  partitioning_progress->SetNumWorkers(num_workers);
  identification_progress->SetNumWorkers(num_workers);
  serialization_progress->SetNumWorkers(num_workers);
}

// Get or create a file ID for the file at `file_path` with contents
// `contents_hash`.
std::pair<mx::RawEntityId, bool> IndexingContext::GetOrCreateFileId(
    mx::WorkerId worker_id_, std::filesystem::path file_path,
    const std::string &contents_hash) {

  const auto worker_id = static_cast<unsigned>(worker_id_);
  auto &maybe_id = this->local_next_file_id[worker_id].id;
  mx::RawEntityId created_id = mx::kInvalidEntityId;
  if (!maybe_id.has_value()) {
    created_id = server_context.storage.next_file_id.fetch_add(
        mx::kMinEntityIdIncrement);;
  } else {
    created_id = std::move(maybe_id.value());
    maybe_id = {};
  }

  mx::RawEntityId file_id = server_context.storage.file_hash_to_file_id.GetOrSet(
      contents_hash, created_id);

  CHECK_LT(file_id, mx::kMaxFileId);

  std::string path_str = file_path.lexically_normal().generic_string();
  server_context.storage.file_id_to_path.Insert(file_id, path_str);
  if (file_id == created_id) {
    return {file_id, true};

  } else {
    maybe_id = created_id;  // Put it back in the worker-specific cache.
    return {file_id, false};
  }
}

// Get or create a code ID for the top-level declarations that hash to
// `code_hash`.
std::pair<mx::RawEntityId, bool> IndexingContext::GetOrCreateFragmentId(
    mx::WorkerId worker_id_, const std::string &code_hash,
    uint64_t num_tokens) {

  const auto worker_id = static_cast<unsigned>(worker_id_);

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    auto &maybe_id = this->local_next_big_fragment_id[worker_id].id;
    mx::RawEntityId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = server_context.storage.next_big_fragment_id.fetch_add(
          mx::kMinEntityIdIncrement);;
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id = {};
    }

    mx::RawEntityId code_id = server_context.storage.code_hash_to_fragment_id.GetOrSet(
        code_hash, created_id);

    CHECK_LT(code_id, mx::kMaxBigFragmentId);
    if (code_id == created_id) {
      return {code_id, true};

    } else {
      maybe_id = created_id;  // Put it back in the worker-specific cache.
      return {code_id, false};
    }

  // "Small codes" have IDs in the range `[mx::mx::kMaxNumBigPendingFragments, ...)`.
  } else {
    auto &maybe_id = this->local_next_small_fragment_id[worker_id].id;
    mx::RawEntityId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = server_context.storage.next_small_fragment_id.fetch_add(
          mx::kMinEntityIdIncrement);;
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id = {};
    }

    mx::RawEntityId code_id = server_context.storage.code_hash_to_fragment_id.GetOrSet(
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
void IndexingContext::PutSerializedFile(mx::RawEntityId id, std::string data) {
  server_context.storage.file_id_to_serialized_file.Set(id, std::move(data));
}

// Save the serialized top-level entities and the parsed tokens.
void IndexingContext::PutSerializedFragment(mx::RawEntityId id,
                                            std::string data) {
  server_context.storage.fragment_id_to_serialized_fragment.Set(id, std::move(data));
}

// Link fragment declarations.
void IndexingContext::LinkDeclarations(mx::RawEntityId a, mx::RawEntityId b) {
  if (a != b && a != mx::kInvalidEntityId && b != mx::kInvalidEntityId) {
    server_context.storage.entity_redecls.Insert(a, b);
    server_context.storage.entity_redecls.Insert(b, a);
  }
}

// Link the mangled name of something to its entity ID.
void IndexingContext::LinkMangledName(const std::string &name,
                                      mx::RawEntityId eid) {
  if (!name.empty() && eid != mx::kInvalidEntityId) {
    server_context.storage.entity_id_to_mangled_name.Insert(eid, name);
    server_context.storage.mangled_name_to_entity_id.Insert(name, eid);
  }
}

// Link an entity to the fragment that uses the entity.
void IndexingContext::LinkUseInFragment(mx::RawEntityId use,
                                        mx::RawEntityId user) {
  if (use != mx::kInvalidEntityId && user != mx::kInvalidEntityId) {
    server_context.storage.entity_id_use_to_fragment_id.Insert(use, user);
  }
}

// Link a direct reference to an entity from another entity.
void IndexingContext::LinkReferenceInFragment(mx::RawEntityId use,
                                              mx::RawEntityId user) {
  if (use != mx::kInvalidEntityId && user != mx::kInvalidEntityId) {
    server_context.storage.entity_id_reference.Insert(use, user);
  }
}

// Save an entries of the form `(file_id, line_number, fragment_id)` over
// the inclusive range `[start_line, end_line]` so that we can figure out
// which fragments overlap which lines. We use this index to go from regular
// expression matches or Weggli syntax matches on files into matches inside of
// fragments.
//
// TODO(pag): Eventually implement an async writer for `PersistentMap` and
//            `PersistentSet` using a RocksDB `WriteBatch`.
void IndexingContext::PutFragmentLineCoverage(
    mx::RawEntityId file_id, mx::RawEntityId fragment_id,
    unsigned start_line, unsigned end_line) {
  server_context.storage.file_fragment_ids.Insert(file_id, fragment_id);
  for (auto i = start_line; i <= end_line; ++i) {
    server_context.storage.file_fragment_lines.Insert(file_id, i, fragment_id);
  }
}

SearchingContext::SearchingContext(ServerContext &server_context_)
    : server_context(server_context_),
      local_next_file_id(mx::kMinEntityIdIncrement) {}

SearchingContext::~SearchingContext(void) {}

}  // namespace indexer
