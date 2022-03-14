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
#include <system_error>

namespace indexer {

IndexingContext::IndexingContext(std::filesystem::path workspace_dir)
    : file_hash_to_file_id(mx::KeyValueStore::kHashToFileId,
                           workspace_dir),
      file_path_to_file_id(mx::KeyValueStore::kPathToFileId,
                           workspace_dir),
      decl_hash_to_code_id(mx::KeyValueStore::kHashToCodeId,
                           workspace_dir) {
  next_file_id.store(1u);  // TODO(pag): Replace.
  next_code_id.store(1u);  // TODO(pag): Replace.
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

std::pair<mx::FileId, bool> IndexingContext::GetOrCreateFileId(
    std::filesystem::path file_path,
    const std::string &contents_hash) {
  bool is_new = false;
  auto file_id = file_hash_to_file_id.GetOrSet<mx::FileId>(
      contents_hash,
      [this, &is_new] (void) -> mx::FileId {
        is_new = true;
        return next_file_id.fetch_add(1u);
      });

  file_path_to_file_id.SetIfMissing(
      file_path.generic_string(), [=] (void) -> std::string {
    return std::to_string(file_id);
  });

  return {file_id, is_new};
}

std::pair<mx::CodeId, bool> IndexingContext::GetOrCreateCodeId(
    const std::string &decl_hash) {
  bool is_new = false;
  auto decl_id = decl_hash_to_code_id.GetOrSet<mx::CodeId>(
      decl_hash,
      [this, &is_new] (void) -> mx::CodeId {
        is_new = true;
        return next_code_id.fetch_add(1u);
      });
  return {decl_id, is_new};
}

}  // namespace indexer
