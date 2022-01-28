// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <gflags/gflags.h>
#include <multiplier/Executor.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Util/FileSystem.h>

DEFINE_bool(show_progress, false, "Show progress bars");

namespace indexer {

GlobalContext::GlobalContext(const mx::Executor &exe_) {
  if (FLAGS_show_progress) {
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
}

bool GlobalContext::AddFileToSet(std::string path) {
  std::unique_lock<std::mutex> locker(tokenized_files_lock);
  auto [it, added] = tokenized_files.emplace(std::move(path));
  return added;
}

UpdateContext::~UpdateContext(void) {}

UpdateContext::UpdateContext(const mx::DatalogClient &client_,
                             std::shared_ptr<GlobalContext> global_context_)
  : client(client_),
    file_manager(pasta::FileSystem::CreateNative()),
    global_context(std::move(global_context_)),
    command_progress(global_context->command_progress.get()),
    ast_progress(global_context->ast_progress.get()),
    tokenizer_progress(global_context->tokenizer_progress.get()) {}

}  // namespace indexer
