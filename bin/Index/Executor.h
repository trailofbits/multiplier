// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <map>
#include <memory>
#include <optional>
#include <type_traits>
#include <vector>

namespace indexer {

// Options for configuring the executor.
struct ExecutorOptions {
 public:
  // Number of worker threads for the executor.
  int num_workers{-1};

  // Stop if this process receives a signal?
  bool stop_if_signalled{true};

  // How many actions to accumulate into a given worker? For coarse-grained
  // actions, you want a low number (minimum 1). For many fine-grained actions,
  // a higher number can reduce contention.
  std::map<unsigned, unsigned> priority_batch_size;
};

class Action;
class ExecutorImpl;
class WeakExecutor;

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

  // Run the executor. The executor must be in the stopped state. If the
  // executor is currently waiting, or running, then this is a NOP.
  void Start(void);

  // Wait for all work in the executor to finish.
  //
  // NOTE(pag): If a `Stop` happens concurrently with a `Wait`, then the
  //            `Stop` takes precedence, and any pending work still in the
  //            queue will be skipped and passed to the `Stop`.
  void Wait(void);

  // Stop the executor. `remaining_actions` is filled with all actions that
  // have not yet executed. The first remaining action is the highest priority
  // action to run, and the last one is the lowest priority to run.
  //
  // NOTE(pag): If two concurrent threads concurrently `Stop`, then one will
  //            end up returning immediately, while another will wait for the
  //            queues to be flushed.
  void Stop(std::vector<std::unique_ptr<Action>> &remaining_actions);

 private:
  friend class ExecutorImpl;
  friend class WeakExecutor;

  explicit Executor(std::shared_ptr<ExecutorImpl> d_);

  std::shared_ptr<ExecutorImpl> d;
};

// A weak handle to an executor.
class WeakExecutor {
 private:
  std::weak_ptr<ExecutorImpl> d;

 public:
  inline /* implicit */ WeakExecutor(const Executor &exe)
      : d(exe.d) {}

  inline std::optional<Executor> Lock(void) const {
    if (auto full_d = d.lock()) {
      return Executor(std::move(full_d));
    } else {
      return std::nullopt;
    }
  }
};

}  // namespace indexer
