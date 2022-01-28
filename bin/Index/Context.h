// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <memory>
#include <mutex>
#include <pasta/Util/FileManager.h>
#include <string>
#include <unordered_set>

namespace mx {
class DatalogClient;  // Auto-generated from Datalog.
class Executor;
class ProgressBar;
}  // namespace mx
namespace indexer {

class GlobalContext {
 private:
  std::mutex tokenized_files_lock;
  std::unordered_set<std::string> tokenized_files;

 public:

  std::unique_ptr<mx::ProgressBar> command_progress;
  std::unique_ptr<mx::ProgressBar> ast_progress;
  std::unique_ptr<mx::ProgressBar> tokenizer_progress;

  explicit GlobalContext(const mx::Executor &exe_);
  bool AddFileToSet(std::string path);
};

class UpdateContext {
 private:
  UpdateContext(void) = delete;

 public:
  const mx::DatalogClient &client;
  const pasta::FileManager file_manager;
  std::shared_ptr<GlobalContext> global_context;

  mx::ProgressBar * const command_progress;
  mx::ProgressBar * const ast_progress;
  mx::ProgressBar * const tokenizer_progress;

  ~UpdateContext(void);
  UpdateContext(const mx::DatalogClient &client_,
                std::shared_ptr<GlobalContext> indexed_files_);

  inline bool AddFileToSet(std::string path) {
    return global_context->AddFileToSet(std::move(path));
  }
};

}  // namespace indexer
