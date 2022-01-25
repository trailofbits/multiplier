// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Action.h>
#include <pasta/Compile/Job.h>

namespace indexer {

class Context;

class IndexCompileJobAction final : public mx::Action {
 private:
  const std::shared_ptr<Context> context;
  const pasta::CompileJob job;

 public:
  virtual ~IndexCompileJobAction(void);

  IndexCompileJobAction(std::shared_ptr<Context> context_,
                        pasta::CompileJob job_);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};

}  // namespace indexer
