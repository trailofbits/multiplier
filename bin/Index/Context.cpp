// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/Executor.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Util/FileSystem.h>

DEFINE_bool(show_progress, false, "Show progress bars");

namespace indexer {

GlobalContext::GlobalContext(const mx::Executor &exe_,
                             const mx::DatalogClient &client) {
  if (FLAGS_show_progress) {
    publish_progress.reset(new mx::ProgressBar("Publishing",
                                               std::chrono::seconds(1)));
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

  auto reserved_file_ids = client.reserve_file_ids_bbf(0, 1 << 20ul);
  CHECK(reserved_file_ids);

  next_file_id.store(reserved_file_ids->NextFileId());
}

std::pair<mx::FileId, bool> GlobalContext::AddFileToSet(std::string path) {
  std::unique_lock<std::mutex> locker(tokenized_files_lock);
  auto [it, added] = tokenized_files.try_emplace(std::move(path), 0);
  if (added) {
    auto next_id = next_file_id.fetch_add(1u);
    it->second = next_id;
    return {next_id, true};
  } else {
    DCHECK_NE(it->second, 0u);
    return {it->second, false};
  }
}

UpdateContext::~UpdateContext(void) {
  if (builder.HasAnyMessages()) {
    if (!client.Publish(builder)) {
      LOG(ERROR)
          << "Error sending messages to mx-server";
    }
  }
}

UpdateContext::UpdateContext(const mx::DatalogClient &client_,
                             std::shared_ptr<GlobalContext> global_context_)
  : client(client_),
    file_manager(pasta::FileSystem::CreateNative()),
    global_context(std::move(global_context_)),
    publish_progress(global_context->publish_progress.get()),
    command_progress(global_context->command_progress.get()),
    ast_progress(global_context->ast_progress.get()),
    tokenizer_progress(global_context->tokenizer_progress.get()) {}

}  // namespace indexer
