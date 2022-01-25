// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <glog/logging.h>
#include <pasta/AST/AST.h>
#include <pasta/Util/ArgumentVector.h>

#include "Context.h"

namespace indexer {

IndexCompileJobAction::~IndexCompileJobAction(void) {}

IndexCompileJobAction::IndexCompileJobAction(std::shared_ptr<Context> context_,
                                             pasta::CompileJob job_)
    : context(std::move(context_)),
      job(std::move(job_)) {
  context->ast_progress.AddWork(1);
}

// Build and index the AST.
void IndexCompileJobAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  mx::ProgressBarStep step(context->ast_progress);

  auto maybe_ast = job.Run();
  if (!maybe_ast.Succeeded()) {
    LOG(ERROR)
        << "Error building AST for command " << job.Arguments().Join()
        << "; error was: " << maybe_ast.TakeError();
    return;
  } else {
    LOG(INFO) << "Got AST for file " << job.SourceFile().Path().generic_string();
  }
}

}  // namespace indexer
