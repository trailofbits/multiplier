// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Executor.h"

#include <thread>

#include "Action.h"
#include "WorkerPool.h"

namespace indexer {
namespace {

// Figure out how many worker threads to use based off of the `ExecutorOptions`.
static unsigned NumWorkers(const ExecutorOptions &options) {
  if (0 >= options.num_workers) {
    return std::thread::hardware_concurrency();
  } else {
    return static_cast<unsigned>(options.num_workers);
  }
}

}  // namespace

// Implementation of the executor, which is a worker pool that processes
// actions.
class ExecutorImpl final : public std::enable_shared_from_this<ExecutorImpl>,
                           public WorkerThreadPool<Action> {
 public:
  virtual ~ExecutorImpl(void);

  // Initialize the executor's worker pool.
  explicit ExecutorImpl(const ExecutorOptions &options_);

  // Perform a single action in the worker thread with ID `worker_id`.
  void Step(unsigned worker_id, std::unique_ptr<Action> work) override;

  const ExecutorOptions options;

 private:
  ExecutorImpl(void) = delete;
};

ExecutorImpl::~ExecutorImpl(void) {}

// Initialize the executor's worker pool.
ExecutorImpl::ExecutorImpl(const ExecutorOptions &options_)
    : WorkerThreadPool<Action>(NumWorkers(options_)),
      options(options_) {}

// Perform a single action in the worker thread with ID `worker_id`.
void ExecutorImpl::Step(unsigned worker_id, std::unique_ptr<Action> work) {
  Executor exe(this->shared_from_this());
  work->Run(std::move(exe), static_cast<WorkerId>(worker_id));
}

Executor::~Executor(void) {}

Executor::Executor(const ExecutorOptions &options)
    : d(std::make_shared<ExecutorImpl>(options)) {}

Executor::Executor(const std::shared_ptr<ExecutorImpl> &d_)
    : d(d_) {}

// Add a new action to the executor.
void Executor::AddAction(std::unique_ptr<Action> action) const {
  d->AddWork(std::move(action));
}

// Return the number of workers in this executor.
unsigned Executor::NumWorkers(void) const noexcept {
  return ::indexer::NumWorkers(d->options);
}

// Run the executor.
void Executor::Start(void) {
  d->Start();
}

// Wait for all work in the executor to finish.
void Executor::Wait(void) {
  d->Wait();
  d->Join();
}

}  // namespace indexer
