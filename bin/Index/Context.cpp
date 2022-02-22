// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/Executor.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Util/FileSystem.h>
#include <system_error>

DEFINE_bool(show_progress, false, "Show progress bars");

DEFINE_string(workspace_dir, "",
              "Path to the workspace into which semi-permanent indexer data "
              "should be stored. Defaults to the current working directory "
              "of `mx-index`.");

namespace indexer {


GlobalContext::GlobalContext(const mx::Executor &exe_,
                             const mx::DatalogClient &client)
    : tokenized_files(mx::KeyValueStore::kPathToFileId,
                      FLAGS_workspace_dir) {

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

  auto reserved_file_ids = client.reserve_file_ids_bbf(
      mx::TimeNow(), 1 << 13ul);
  CHECK(reserved_file_ids);

  const mx::FileId fid = reserved_file_ids->NextFileId();
  next_file_id.store(fid);

  LOG(INFO)
      << "Next file ID will be " << fid;
}

std::pair<mx::FileId, bool> GlobalContext::AddFileToSet(std::string path) {
  bool is_new = false;
  auto file_id = tokenized_files.GetOrSet<mx::FileId>(
      path,
      [this, &is_new] (void) -> mx::FileId {
        is_new = true;
        return next_file_id.fetch_add(1u);
      });
  return {file_id, is_new};
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
