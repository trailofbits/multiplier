// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Action.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Job.h>
#include <unordered_map>

namespace pasta {
class File;
class TokenRange;
}  // namespace pasta
namespace indexer {

class UpdateContext;

class IndexCompileJobAction final : public mx::Action {
 private:
  const std::shared_ptr<UpdateContext> context;
  const mx::ProgressBarWork progress;
  const pasta::CompileJob job;

  std::unordered_map<pasta::File, mx::FileId> file_ids;

  // Look through all files referenced by the AST get their unique IDs. If this
  // is the first time seeing a file, then tokenize the file.
  void MaybeTokenizeFile(const mx::Executor &exe, pasta::File file);

 public:
  virtual ~IndexCompileJobAction(void);

  IndexCompileJobAction(std::shared_ptr<UpdateContext> context_,
                        pasta::CompileJob job_);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};

}  // namespace indexer
