// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <glog/logging.h>
#include <multiplier/Executor.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <string>
#include <system_error>

#include "Codegen.h"

namespace indexer {

ServerContext::ServerContext(std::filesystem::path workspace_dir_)
    : workspace_dir(std::move(workspace_dir_)),
      meta_to_id(workspace_dir),
      file_id_to_path(workspace_dir),
      file_id_to_serialized_file(workspace_dir),
      file_fragment_ids(workspace_dir),
      file_fragment_lines(workspace_dir),
      file_hash_to_file_id(workspace_dir),
      file_path_to_file_id(workspace_dir),
      code_hash_to_fragment_id(workspace_dir),
      fragment_id_to_serialized_fragment(workspace_dir),
      code_id_to_source_ir(workspace_dir) {

  next_file_id.store(meta_to_id.GetOrSet(
      MetadataName::kNextFileId, mx::kMinEntityIdIncrement));
  next_small_fragment_id.store(meta_to_id.GetOrSet(
      MetadataName::kNextSmallCodeId, mx::kMaxBigFragmentId));
  next_big_fragment_id.store(meta_to_id.GetOrSet(
      MetadataName::kNextBigCodeId, mx::kMinEntityIdIncrement));
}

ServerContext::~ServerContext(void) {
  Flush();
}

void ServerContext::Flush(void) {
  meta_to_id.Set(MetadataName::kNextFileId, next_file_id.load());
  meta_to_id.Set(MetadataName::kNextSmallCodeId, next_small_fragment_id.load());
  meta_to_id.Set(MetadataName::kNextBigCodeId, next_big_fragment_id.load());
}

void IndexingCounter::ResetAll(void) {
  for(auto id = 0u; id < kStatSourceIRFragment + 1; id++) {
    counter[id].store(mx::kInvalidEntityId);
  }
}

void IndexingCounter::PrintAll(void) {
  const char *id_name[6] = {
      "StatCompileCommand", "StatCompileJob", "StatAST",
      "StatCodeFragment", "StatUniqueCodeFragment",
      "StatSourceIRFragment"
  };
  for(auto id = 0u; id < kStatSourceIRFragment + 1; id++) {
    std::cerr << id_name[id] << " : " <<  counter[id].load() << "\n";
  }
}



IndexingContext::IndexingContext(ServerContext &server_context_,
                                 const mx::Executor &exe_)
    : server_context(server_context_),
      num_workers(exe_.NumWorkers()),
      local_next_file_id(num_workers),
      local_next_small_fragment_id(num_workers),
      local_next_big_fragment_id(num_workers),
      codegen(nullptr) {}

IndexingContext::~IndexingContext(void) {
  server_context.Flush();
}

void IndexingContext::InitializeProgressBars(void) {
  command_progress.reset(new mx::ProgressBar("1) Command interpretation",
                                             std::chrono::seconds(1)));
  ast_progress.reset(new mx::ProgressBar("2) Parsing / AST building",
                                         std::chrono::seconds(1)));
  partitioning_progress.reset(new mx::ProgressBar("4) Fragment partitioning",
                                                  std::chrono::seconds(1)));
  identification_progress.reset(new mx::ProgressBar("5) Fragment identification",
                                                    std::chrono::seconds(1)));
  serialization_progress.reset(new mx::ProgressBar("6) Fragment serialization",
                                              std::chrono::seconds(1)));
  file_progress.reset(new mx::ProgressBar("3) File serialization",
                                          std::chrono::seconds(1)));

  command_progress->SetNumWorkers(num_workers);
  ast_progress->SetNumWorkers(num_workers);
  file_progress->SetNumWorkers(num_workers);
}

void IndexingContext::InitializeCodeGenerator(void) {
  codegen = std::make_unique<CodeGenerator>();
}


// Get or create a file ID for the file at `file_path` with contents
// `contents_hash`.
std::pair<mx::FileId, bool> IndexingContext::GetOrCreateFileId(
    mx::WorkerId worker_id_, std::filesystem::path file_path,
    const std::string &contents_hash) {

  const auto worker_id = static_cast<unsigned>(worker_id_);
  auto &maybe_id = this->local_next_file_id[worker_id].id;
  mx::FileId created_id = mx::kInvalidEntityId;
  if (!maybe_id.has_value()) {
    created_id = server_context.next_file_id.fetch_add(
        mx::kMinEntityIdIncrement);;
  } else {
    created_id = std::move(maybe_id.value());
    maybe_id = {};
  }

  mx::FileId file_id = server_context.file_hash_to_file_id.GetOrSet(
      contents_hash, created_id);

  CHECK_LT(file_id, mx::kMaxFileId);

  std::string path_str = file_path.lexically_normal().generic_string();
  server_context.file_id_to_path.Insert(file_id, path_str);
  server_context.file_path_to_file_id.Set(path_str, file_id);
  if (file_id == created_id) {
    return {file_id, true};

  } else {
    maybe_id = created_id;  // Put it back in the worker-specific cache.
    return {file_id, false};
  }
}

// Get or create a code ID for the top-level declarations that hash to
// `code_hash`.
std::pair<mx::FragmentId, bool> IndexingContext::GetOrCreateFragmentId(
    mx::WorkerId worker_id_, const std::string &code_hash,
    uint64_t num_tokens) {

  std::string prefix;
  prefix.reserve(32);
  if (code_hash.size() > 32) {
    prefix.insert(prefix.end(), &(code_hash[0]), &(code_hash[32]));
  } else {
    prefix = code_hash;
  }

  code_hash_to_fragment_id_maps.lock();
  auto &cache = code_hash_to_fragment_id_maps[std::move(prefix)];
  code_hash_to_fragment_id_maps.unlock();

  std::unique_lock<std::mutex> locker(cache);
  mx::FragmentId &code_id = cache[code_hash];
  if (code_id != mx::kInvalidEntityId) {
    return {code_id, false};
  }

  const auto worker_id = static_cast<unsigned>(worker_id_);

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    auto &maybe_id = this->local_next_big_fragment_id[worker_id].id;
    mx::FileId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = server_context.next_big_fragment_id.fetch_add(
          mx::kMinEntityIdIncrement);;
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id = {};
    }

    code_id = server_context.code_hash_to_fragment_id.GetOrSet(
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
    mx::FileId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = server_context.next_small_fragment_id.fetch_add(
          mx::kMinEntityIdIncrement);;
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id = {};
    }
    code_id = server_context.code_hash_to_fragment_id.GetOrSet(
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
void IndexingContext::PutSerializedFile(mx::FileId id, std::string data) {
  server_context.file_id_to_serialized_file.Set(id, std::move(data));
}

// Save the serialized top-level entities and the parsed tokens.
void IndexingContext::PutSerializedFragment(mx::FragmentId id,
                                            std::string data) {
  server_context.fragment_id_to_serialized_fragment.Set(id, std::move(data));
}

// Save an entries of the form `(file_id, line_number, fragment_id)` over
// the inclusive range `[start_line, end_line]` so that we can figure out
// which fragments overlap which lines.
//
// TODO(pag): Eventually implement an async writer for `PersistentMap` and
//            `PersistentSet` using a RocksDB `WriteBatch`.
void IndexingContext::PutFragmentLineCoverage(
    mx::FileId file_id, mx::FragmentId fragment_id,
    unsigned start_line, unsigned end_line) {
  server_context.file_fragment_ids.Insert(file_id, fragment_id);
  for (auto i = start_line; i <= end_line; ++i) {
    server_context.file_fragment_lines.Insert(file_id, i, fragment_id);
  }
}

// Save the source IRs for top-level decl.
void IndexingContext::PutSourceIRs(
    mx::FragmentId code_id, std::string source_ir) {
  server_context.code_id_to_source_ir.Set(code_id, source_ir);
}

SearchingContext::SearchingContext(ServerContext &server_context_,
                                 const mx::Executor &exe_)
    : server_context(server_context_),
      num_workers(exe_.NumWorkers()){
  local_next_file_id.store(mx::kMinEntityIdIncrement);
}

SearchingContext::~SearchingContext(void) {
  server_context.Flush();
}

std::pair<mx::FileId, bool> SearchingContext::GetNextFileId(void) {
  if (local_next_file_id < server_context.next_file_id) {
    auto next_file_id = local_next_file_id.fetch_add(1ull);
    return {next_file_id, true};
  }

  return {0, false};
}

std::optional<mx::FileId> SearchingContext::GetMaxFileId(void) {
  auto file_id = server_context.next_file_id.load();
  if (file_id > 1) {
    return file_id -1;
  }
  return std::nullopt;
}

std::optional<std::string>
SearchingContext::GetSerializedFile(mx::FileId file_id) {
  return server_context.file_id_to_serialized_file.TryGet(file_id);
}

std::optional<std::string>
SearchingContext::GetSerializedFragment(mx::FragmentId fragment_id) {
  return server_context.fragment_id_to_serialized_fragment.TryGet(fragment_id);
}


}  // namespace indexer
