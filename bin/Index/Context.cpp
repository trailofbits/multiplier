// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
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
      file_id_to_hash(workspace_dir),
      file_id_to_tokens(workspace_dir),
      file_hash_to_file_id(workspace_dir),
      file_path_to_file_id(workspace_dir),
      code_hash_to_code_id(workspace_dir) {

  next_file_id.store(meta_to_id.GetOrSet(MetadataName::kNextFileId, 1u));
  next_code_id.store(meta_to_id.GetOrSet(MetadataName::kNextCodeId, 1u));
}

ServerContext::~ServerContext(void) {
  meta_to_id.Set(MetadataName::kNextFileId, next_file_id.load());
  meta_to_id.Set(MetadataName::kNextCodeId, next_code_id.load());
}

IndexingContext::IndexingContext(
    std::shared_ptr<ServerContext> server_context_)
    :  server_context(std::move(server_context_)) {}

IndexingContext::~IndexingContext(void) {}

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
  mx::FileId file_id = server_context->file_hash_to_file_id.LazyGetOrSet(
      contents_hash,
      [this, &created_id] (void) -> mx::FileId {
        created_id = server_context->next_file_id.fetch_add(1u);
        return created_id;
      });

  if (file_id != created_id) {
    return {file_id, false};
  }

  server_context->file_path_to_file_id.Set(file_path.generic_string(), file_id);
  return {file_id, true};
}

// Get or create a code ID for the top-level declarations that hash to
// `code_hash`.
std::pair<mx::CodeId, bool> IndexingContext::GetOrCreateCodeId(
    const std::string &code_hash) {
  mx::CodeId created_id = 0u;
  mx::CodeId decl_id = server_context->code_hash_to_code_id.LazyGetOrSet(
      code_hash,
      [this, &created_id] (void) -> mx::CodeId {
        created_id = server_context->next_code_id.fetch_add(1u);
        return created_id;
      });

  return {decl_id, decl_id == created_id};
}

// Save the tokenized contents of a file.
void IndexingContext::PutFileTokens(
    mx::FileId file_id, kj::Array<capnp::word> tokens) {
  server_context->file_id_to_tokens.Set(file_id, kj::mv(tokens));
}

}  // namespace indexer
