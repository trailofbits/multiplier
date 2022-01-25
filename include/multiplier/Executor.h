// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <type_traits>

namespace mx {

// Options for configuring the executor.
struct ExecutorOptions {
 public:
  // Number of worker threads for the executor.
  int num_workers{-1};
};

class Action;
class ExecutorImpl;

// The main executor that does all the things.
class Executor {
 public:
  Executor(const Executor &) = default;
  Executor &operator=(const Executor &) = default;
  Executor(Executor &&) noexcept = default;
  Executor &operator=(Executor &&) noexcept = default;

  Executor(const ExecutorOptions &options=ExecutorOptions());
  ~Executor(void);

  // Add a new action to the executor.
  void AddAction(std::unique_ptr<Action> action) const;

  // Add a new action to the executor.
  template <typename Act, typename... Args>
  inline void EmplaceAction(Args&&... args) const {
    std::unique_ptr<Action> action(new Act(std::forward<Args>(args)...));
    AddAction(std::move(action));
  }

  // Return the number of workers in this executor.
  unsigned NumWorkers(void) const noexcept;

  // Run the executor.
  void Start(void);

  // Wait for all work in the executor to finish.
  void Wait(void);

 private:
  friend class ExecutorImpl;

  explicit Executor(const std::shared_ptr<ExecutorImpl> &d_);

  std::shared_ptr<ExecutorImpl> d;
};

}  // namespace mx
