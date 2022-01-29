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
#include <pasta/Util/File.h>

namespace indexer {

class UpdateContext;

class TokenizeFileAction final : public mx::Action {
 private:
  const std::shared_ptr<UpdateContext> context;
  const mx::ProgressBarWork progress;
  const mx::FileId file_id;
  const pasta::File file;

 public:
  virtual ~TokenizeFileAction(void);

  TokenizeFileAction(std::shared_ptr<UpdateContext> context_,
                     mx::FileId file_id_, pasta::File file_);

  // Tokenize the file.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};

}  // namespace indexer
