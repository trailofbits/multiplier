// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <functional>
#include <memory>
#include <type_traits>

namespace mx {
class BlockingConcurrentQueue;
class Semaphore;
class QueuePointer;

// The base class of a generic worker pool that can pass around pointers.
class WorkerThreadPoolBase {
 public:
  explicit WorkerThreadPoolBase(unsigned num_workers_);

  virtual ~WorkerThreadPoolBase(void);

  // Invoke the function `func` when all workers have been paused.
  void CallWithWorkersPaused(std::function<void(void)> func);

  // Waits for all queues to empty, then return.
  //
  // NOTE(pag): Depending on how the pool is used, it's possible for another
  //            task to be added after `Wait` returns.
  void Wait(void) const;

  // Wait for all workers to join. No work can be added after this point.
  void Join(void) const;

  // Start up teh worker pool.
  void Start(void) const;

  // Tell the worker pool to stop.
  void Stop(void);

 protected:
  class Impl;

  // Invoked when the worker is started.
  virtual void OnStart(unsigned worker_id);

  // Invoked when the worker is paused.
  virtual void OnPause(unsigned worker_id);

  // Invoked when the worker is resumed from a pause, but where it won't be
  // doing more work, and instead will stop.
  virtual void OnResumeToStop(unsigned worker_id);

  // Invoked when the worker is resumed from a pause in order to do more
  // work.
  virtual void OnResumeToStep(unsigned worker_id);

  // Invoked when the worker is stopped and won't do anything more.
  virtual void OnStop(unsigned worker_id);

  // Invoked when the program is signaled and we're going to stop.
  //
  // NOTE(pag): This is not executed in the context of any worker, and
  // therefore
  //            it is not safe to access thread-local state at this point, nor
  //            "effectively" thread-local state (keyed by worker ID).
  //
  //            However, after this function is called, the workers will be
  //            paused, and then later stopped.
  virtual void OnSignalToStop(void);

  virtual void StepInternal(unsigned worker_id, void *work) = 0;
  virtual void DrainInternal(void *work) = 0;

  bool AddWorkInternal(void *work);

 private:
  friend class QueuePointer;

  WorkerThreadPoolBase(void) = delete;
  WorkerThreadPoolBase(const WorkerThreadPoolBase &) = delete;
  WorkerThreadPoolBase(WorkerThreadPoolBase &&) noexcept = delete;
  WorkerThreadPoolBase &operator=(const WorkerThreadPoolBase &) = delete;
  WorkerThreadPoolBase &operator=(WorkerThreadPoolBase &&) noexcept = delete;

  // Invoked by a signal observer. This triggers the worker threads to
  // stop, but it doesn't trigger the `is_joined` state change.
  void OnSignalToStopInternal(void);

  // Main loop of the worker thread.
  static void *ThreadMain(void *);
  void DoWork(unsigned worker_id);

  const std::unique_ptr<Impl> d;
};

// Manages a worker pool of threads that listen for a specific type of work.
//
// NOTE(pag): Only one of these should be running at a time.
template <typename T>
class WorkerThreadPool : public WorkerThreadPoolBase {
 public:
  using WorkerThreadPoolBase::WorkerThreadPoolBase;

  virtual ~WorkerThreadPool(void) = default;

  // Add work to the queue. Returns `false` if the work will not be added
  // and instead will be drained.
  bool AddWork(std::unique_ptr<T> work) {
    return AddWorkInternal(reinterpret_cast<void *>(work.release()));
  }

 protected:
  // Invoked each time we can perform another step of work.
  virtual void Step(unsigned worker_id, std::unique_ptr<T> work) = 0;

  // Invoked on each remaining work item after the pool has been stopped.
  virtual void Drain(std::unique_ptr<T> work) {}

 private:
  WorkerThreadPool(void) = delete;
  WorkerThreadPool(const WorkerThreadPool &) = delete;
  WorkerThreadPool(WorkerThreadPool &&) noexcept = delete;

  void StepInternal(unsigned worker_id, void *work_) override final {
    std::unique_ptr<T> work(reinterpret_cast<T *>(work_));
    Step(worker_id, std::move(work));
  }

  void DrainInternal(void *work_) override final {
    std::unique_ptr<T> work(reinterpret_cast<T *>(work_));
    Drain(std::move(work));
  }
};

}  // namespace mx
