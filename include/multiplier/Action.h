// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

#include "Executor.h"

namespace mx {

enum WorkerId : unsigned;

// An executor action.
class Action {
 public:
  Action(void) = default;
  virtual ~Action(void);

  // Run this action in the worker `worker_id`. The action itself may need to
  // add more work to the executor, and so it's given a reference to the
  // executor for this reason.
  virtual void Run(Executor exe, WorkerId worker_id) = 0;

 private:
  friend class Executor;

  Action(const Action &) = delete;
  Action(Action &&) noexcept = delete;
  Action &operator=(const Action &) = delete;
  Action &operator=(Action &&) noexcept = delete;
};

}  // namespace mx
