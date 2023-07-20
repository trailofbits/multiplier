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
  if (ast_progress) {
    return;
  }

  std::chrono::seconds report_freq = std::chrono::seconds(1);

  command_progress.reset(new ProgressBar("Commands",
                                         report_freq));

  eval_command_progress.reset(new ProgressBar("Evaluated commands",
                                              report_freq));

  ast_progress.reset(new ProgressBar("Parsing",
                                     report_freq));

  file_progress.reset(new ProgressBar("File serialization",
                                      report_freq));

  partitioning_progress.reset(new ProgressBar("AST partitioning",
                                              report_freq));

  fragment_progress.reset(new ProgressBar("Fragment serialization",
                                          report_freq));

  type_progress.reset(new ProgressBar("Type serialization",
                                      report_freq));

  sourceir_progress.reset(new ProgressBar("SourceIR", report_freq));
}

}  // namespace indexer
