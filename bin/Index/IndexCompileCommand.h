// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Action.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Compile/Command.h>

namespace mx {
struct CompileCommand;  // Auto-generated from Datalog.
}  // namespace mx
namespace indexer {

class UpdateContext;

using CompileCommandPtr = std::shared_ptr<const mx::CompileCommand>;

class IndexCompileCommandAction final : public mx::Action {
 private:
  const std::shared_ptr<UpdateContext> context;
  const mx::ProgressBarWork progress;
  const CompileCommandPtr command;

 public:
  virtual ~IndexCompileCommandAction(void);

  IndexCompileCommandAction(std::shared_ptr<UpdateContext> context_,
                            CompileCommandPtr command_);

  // Run the compile command, which should create a single compile job.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};

}  // namespace indexer
