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

Context::~Context(void) {}

Context::Context(const mx::Executor &exe_, const mx::DatalogClient &client_)
  : client(client_),
    file_manager(pasta::FileSystem::CreateNative()) {
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

}  // namespace indexer
