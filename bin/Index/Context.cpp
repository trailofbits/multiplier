// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <filesystem>
#include <glog/logging.h>
#include <multiplier/AST.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <string>
#include <system_error>
#include <utility>
#include <vector>
#include <mutex>

#include "Codegen.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {

GlobalIndexingState::GlobalIndexingState(mx::DatabaseWriter &database_,
                                 const Executor &exe_)
    : num_workers(exe_.NumWorkers()),
      executor(exe_),
      database(database_) {}

GlobalIndexingState::~GlobalIndexingState(void) {}

void GlobalIndexingState::InitializeProgressBars(void) {
  if (command_progress) {
    return;
  }

  std::chrono::seconds report_freq = std::chrono::seconds(1);
  command_progress.reset(new ProgressBar("1) Command interpretation",
                                         report_freq));
  ast_progress.reset(new ProgressBar("2) Parsing / AST building",
                                     report_freq));
  file_progress.reset(new ProgressBar("3) File serialization",
                                      report_freq));
  partitioning_progress.reset(new ProgressBar("4) Fragment partitioning",
                                              report_freq));
  identification_progress.reset(new ProgressBar("5) Fragment identification",
                                                report_freq));
  serialization_progress.reset(new ProgressBar("6) Fragment serialization",
                                               report_freq));

  command_progress->SetNumWorkers(num_workers);
  ast_progress->SetNumWorkers(num_workers);
  file_progress->SetNumWorkers(num_workers);
  partitioning_progress->SetNumWorkers(num_workers);
  identification_progress->SetNumWorkers(num_workers);
  serialization_progress->SetNumWorkers(num_workers);
}

}  // namespace indexer
