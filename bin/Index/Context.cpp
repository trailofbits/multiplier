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
      fragment_id_to_serialized_fragment(workspace_dir) {

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

IndexingContext::IndexingContext(ServerContext &server_context_)
    : server_context(server_context_) {}

IndexingContext::~IndexingContext(void) {
  server_context.Flush();
}

void IndexingContext::InitializeProgressBars(const mx::Executor &exe_) {
  command_progress.reset(new mx::ProgressBar("Command parsing",
                                             std::chrono::seconds(1)));
  ast_progress.reset(new mx::ProgressBar("AST building",
                                         std::chrono::seconds(1)));
  tokenizer_progress.reset(new mx::ProgressBar("Tokenizer",
                                               std::chrono::seconds(1)));
  auto num_workers = exe_.NumWorkers();
  command_progress->SetNumWorkers(num_workers);
  ast_progress->SetNumWorkers(num_workers);
  tokenizer_progress->SetNumWorkers(num_workers);
}

// Get or create a file ID for the file at `file_path` with contents
// `contents_hash`.
std::pair<mx::FileId, bool> IndexingContext::GetOrCreateFileId(
    std::filesystem::path file_path, const std::string &contents_hash) {

  mx::FileId created_id = 0u;
  mx::FileId file_id = server_context.file_hash_to_file_id.LazyGetOrSet(
      contents_hash,
      [this, &created_id] (void) -> mx::FileId {
        created_id = server_context.next_file_id.fetch_add(
            mx::kMinEntityIdIncrement);
        return created_id;
      });

  CHECK_LT(file_id, mx::kMaxFileId);

  std::string path_str = file_path.lexically_normal().generic_string();
  server_context.file_id_to_path.Insert(file_id, path_str);
  server_context.file_path_to_file_id.Set(path_str, file_id);
  return {file_id, file_id == created_id};
}

// Get or create a code ID for the top-level declarations that hash to
// `code_hash`.
std::pair<mx::FragmentId, bool> IndexingContext::GetOrCreateFragmentId(
    const std::string &code_hash, uint64_t num_tokens) {

  mx::FragmentId created_id = 0u;
  mx::FragmentId code_id = 0u;

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigCodeChunks)`.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    code_id = server_context.code_hash_to_fragment_id.LazyGetOrSet(
        code_hash,
        [this, &created_id] (void) -> mx::FragmentId {
          created_id = server_context.next_big_fragment_id.fetch_add(
              mx::kMinEntityIdIncrement);
          return created_id;
        });

    CHECK_LT(code_id, mx::kMaxBigFragmentId);

  // "Small codes" have IDs in the range `[mx::mx::kMaxNumBigCodeChunks, ...)`.
  } else {
    code_id = server_context.code_hash_to_fragment_id.LazyGetOrSet(
        code_hash,
        [this, &created_id] (void) -> mx::FragmentId {
          created_id = server_context.next_small_fragment_id.fetch_add(
              mx::kMinEntityIdIncrement);
          return created_id;
        });

    CHECK_GE(code_id, mx::kMaxBigFragmentId);
  }

  return {code_id, code_id == created_id};
}

// Save the tokenized contents of a file.
void IndexingContext::PutSerializedFile(
    mx::FileId file_id, kj::Array<capnp::word> tokens) {
  server_context.file_id_to_serialized_file.Set(file_id, kj::mv(tokens));
}

// Save the serialized top-level entities and the parsed tokens.
void IndexingContext::PutSerializedFragment(mx::FragmentId code_id,
                                            kj::Array<capnp::word> code) {
  server_context.fragment_id_to_serialized_fragment.Set(code_id, kj::mv(code));
}

}  // namespace indexer
