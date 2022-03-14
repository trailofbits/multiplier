// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <cstdint>
#include <filesystem>
#include <memory>
#include <multiplier/KeyValueStore.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/Types.h>

#include <pasta/Util/FileManager.h>

#include <string>
#include <unordered_map>

namespace mx {
class Executor;
class ProgressBar;
}  // namespace mx
namespace indexer {

class IndexingContext {
 private:
  // Maps a sha256 hash of a file's contents to an ID for that file.
  mx::KeyValueStore file_hash_to_file_id;

  // Maps an absolute path to a file's ID. Multiple files may map to the same
  // ID if their contents are identical.
  mx::KeyValueStore file_path_to_file_id;

  // Maps an aggregate key of the form
  //
  //    <file hash>:<line>:<column>:<tokens hash>:<odr hash 0>:...:<odr hash N>
  //
  // to "code ids," that is, the ID of the serialized code containing one or
  // more top-level declarations.
  mx::KeyValueStore decl_hash_to_code_id;

  std::atomic<mx::FileId> next_file_id;
  std::atomic<mx::CodeId> next_code_id;

 public:

  std::unique_ptr<mx::ProgressBar> command_progress;
  std::unique_ptr<mx::ProgressBar> ast_progress;
  std::unique_ptr<mx::ProgressBar> tokenizer_progress;

  explicit IndexingContext(std::filesystem::path workspace_dir);

  void InitializeProgressBars(const mx::Executor &exe_);

  std::pair<mx::FileId, bool> GetOrCreateFileId(
      std::filesystem::path file_path,
      const std::string &contents_hash);

  std::pair<mx::CodeId, bool> GetOrCreateCodeId(const std::string &decl_hash);
};

}  // namespace indexer
