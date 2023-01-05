// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Database.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/FileManager.h>
#include <unordered_map>

#include "Action.h"
#include "Context.h"
#include "ProgressBar.h"

namespace pasta {
class AST;
class File;
class TokenRange;
}  // namespace pasta
namespace indexer {


class IndexCompileJobAction final : public Action {
 private:
  const std::shared_ptr<GlobalIndexingState> context;
  const pasta::FileManager file_manager;
  const pasta::CompileJob job;

 public:
  virtual ~IndexCompileJobAction(void);

  IndexCompileJobAction(std::shared_ptr<GlobalIndexingState> context_,
                        pasta::FileManager file_manager_,
                        pasta::CompileJob job_);

  // Build and index the AST.
  void Run(Executor exe, WorkerId worker_id) final;
};

}  // namespace indexer
