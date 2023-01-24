// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <memory>

namespace indexer {

// An executor action.
class Action {
 public:
  Action(void) = default;
  virtual ~Action(void);

  // Run this action in the worker `worker_id`. The action itself may need to
  // add more work to the executor, and so it's given a reference to the
  // executor for this reason.
  virtual void Run(void) = 0;

  // Return the priority of this action. A higher value means higher priority.
  // Default value is `0`.
  virtual unsigned Priority(void) const;

 private:
  friend class Executor;
  friend class ExecutorImpl;

  std::unique_ptr<Action> next;

  Action(const Action &) = delete;
  Action(Action &&) noexcept = delete;
  Action &operator=(const Action &) = delete;
  Action &operator=(Action &&) noexcept = delete;
};

}  // namespace indexer
