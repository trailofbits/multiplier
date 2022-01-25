// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexCompileJob.h"

#include <glog/logging.h>
#include <pasta/Util/ArgumentVector.h>

namespace indexer {

IndexCompileJobAction::~IndexCompileJobAction(void) {}

// Build and index the AST.
void IndexCompileJobAction::Run(mx::Executor exe, mx::WorkerId worker_id) {
  LOG(INFO)
      << "Got job: " << job.Arguments().Join();
}

}  // namespace indexer
