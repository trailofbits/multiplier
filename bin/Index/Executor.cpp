// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Executor.h"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <pthread.h>
#include <thread>
#include <map>

#include "Action.h"
#include "Signal.h"

#define D(...)

namespace indexer {
namespace {

enum State : int {
  kNotRunning,
  kRunning,
  kWaiting,
};

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
class ExecutorImpl final : public std::enable_shared_from_this<ExecutorImpl> {
 public:
  ~ExecutorImpl(void);

  // Initialize the executor's worker pool.
  explicit ExecutorImpl(const ExecutorOptions &options_);

  // Number of worker threads.
  const unsigned num_workers;

  // How many actions to accumulate into a given worker?
  std::map<unsigned, unsigned> priority_batch_size;

  // Map of priorities to the first action with that priority. Actions have
  // a `next` pointer, so we can find the next action with that priority.
  std::map<unsigned, std::unique_ptr<Action>> prioritized_actions;

  std::atomic<size_t> num_pending_actions;
  std::atomic<size_t> num_actions;
  std::atomic<State> state;
  std::mutex wait_lock;

  std::vector<pthread_t> workers;

  std::mutex lock;
  std::condition_variable state_change;

  void Run(void);

 private:
  ExecutorImpl(void) = delete;
};

ExecutorImpl::~ExecutorImpl(void) {
  state.store(State::kWaiting);
  state_change.notify_all();
  for (pthread_t &worker : workers) {
    void *data = nullptr;
    pthread_join(worker, &data);
  }
}

// Initialize the executor's worker pool.
ExecutorImpl::ExecutorImpl(const ExecutorOptions &options_)
    : num_workers(NumWorkers(options_)),
      priority_batch_size(options_.priority_batch_size),
      num_actions(0u),
      state(State::kNotRunning) {
  workers.reserve(num_workers);
}

void ExecutorImpl::Run(void) {
  std::vector<std::unique_ptr<Action>> actions_to_run;
  actions_to_run.reserve(64u);

  auto cond = [this] (void) {
    return state.load() != State::kRunning || 0u < num_actions.load();
  };

  for (; state.load() != State::kNotRunning; ) {
    actions_to_run.clear();

    do {
      std::unique_lock<std::mutex> locker(lock);

      // If we state is not running or waiting, or if there are actions to
      // process, then grab the lock.
      state_change.wait_for(locker, std::chrono::milliseconds(100), cond);

      D( LOG(ERROR)
          << reinterpret_cast<void *>(this)
          << " Worker " << worker_id << " woke up: "
          << "state=" << state.load() << " num_actions="
          << num_actions.load() << " num_pending_actions="
          << num_pending_actions.load(); )

      std::unique_ptr<Action> action;

      // Go find the highest priority actions and pull them out.
      for (auto it = prioritized_actions.rbegin();
           it != prioritized_actions.rend(); ++it) {

        // Try to take the first action. The first action owns the rest of
        // the action list.
        action.swap(it->second);
        if (!action) {
          continue;
        }

        // Get the batch size for this priority.
        unsigned batch_size = priority_batch_size[it->first];
        if (!batch_size) {
          batch_size = 1u;
        }

        // Accumulate a few actions to run in this worker.
        auto i = 0u;
        for (; action && i < batch_size; ++i) {
          actions_to_run.emplace_back(std::move(action));
          action.swap(actions_to_run.back()->next);
        }

        // Put the next action back.
        action.swap(it->second);
        num_pending_actions.fetch_add(i);
        num_actions.fetch_sub(i);
        break;
      }
    } while (false);

    // Run each action. We don't check if we're not running here because we
    // committed to running these actions when we pulled them out of the
    // priority lists, so there's no reasonable way to return them out to the
    // caller on a call to `Stop`.
    for (std::unique_ptr<Action> &action : actions_to_run) {
      action->Run();
      action.reset();
      num_pending_actions.fetch_sub(1u);
    }

    // If we didn't run any actions, and if we're in a waiting state, then
    // exit the thread.
    //
    // NOTE(pag): The waiter thread tries to be very careful about the
    //            possibility that only one action is left, and so a number of
    //            threads are idle while that action is being processed, but
    //            where that action goes and spawns a bunch more work. We don't
    //            want to prematurely destroy the remaining threads in this
    //            situation.
    if (actions_to_run.empty() && state.load() == State::kWaiting) {
      break;
    }
  }

  D( LOG(ERROR)
      << reinterpret_cast<void *>(this)
      << " Worker " << worker_id << " exiting: "
      << "state=" << state.load() << " num_actions="
      << num_actions.load() << " num_pending_actions="
      << num_pending_actions.load(); )
}

Executor::~Executor(void) {}

Executor::Executor(const ExecutorOptions &options)
    : d(std::make_shared<ExecutorImpl>(options)) {

  if (!options.stop_if_signalled) {
    return;
  }

  WeakExecutor we(*this);
  auto stop_work = [we = std::move(we)] (int) {
    if (auto self = we.Lock()) {
      std::vector<std::unique_ptr<Action>> remaining_actions;
      self->Stop(remaining_actions);
    }
  };

  Signal::AddAsyncObserver(SIGINT, stop_work);
  Signal::AddAsyncObserver(SIGQUIT, stop_work);
  Signal::AddAsyncObserver(SIGTERM, stop_work);
}

Executor::Executor(std::shared_ptr<ExecutorImpl> d_)
    : d(std::move(d_)) {}

// Add a new action to the executor.
void Executor::AddAction(std::unique_ptr<Action> action) const {
  do {
    auto action_priority = action->Priority();

    std::unique_lock<std::mutex> locker(d->lock);
    auto &next_action = d->prioritized_actions[action_priority];
    action->next.swap(next_action);
    next_action.swap(action);

    d->num_actions.fetch_add(1u);

    // If we aren't running, then don't fall through to notify any threads.
    if (d->state.load() == State::kNotRunning) {
      return;
    }
  } while (false);

  d->state_change.notify_one();
}

// Return the number of workers in this executor.
unsigned Executor::NumWorkers(void) const noexcept {
  return d->num_workers;
}

// Run the executor. The executor must be in the stopped state. If the
// executor is currently waiting, or running, then this is a NOP.
void Executor::Start(void) {
  std::unique_lock<std::mutex> locker(d->lock);
  if (d->state.load() != State::kNotRunning) {
    return;
  }

  d->state.store(State::kRunning);
  d->workers.clear();
  d->workers.resize(d->num_workers);
  for (auto i = 0u; i < d->num_workers; ++i) {

    // NOTE(pag): In debug builds, the stack can get quite big, especially
    //            in Clang's parser, so we use pthreads and an attribute to set
    //            large stacks.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, (1ull << 20) * 32ull);

    pthread_t &thread = d->workers[i];
    pthread_create(
        &thread,
        &attr,
        +[] (void *d_) -> void * {
          std::shared_ptr<ExecutorImpl> self =
              reinterpret_cast<ExecutorImpl *>(d_)->shared_from_this();
          self->Run();
          return nullptr;
        },
        d.get());

    pthread_attr_destroy(&attr);
  }
}

// Stop the executor. `remaining_actions` is filled with all actions that
// have not yet executed. The first remaining action is the highest priority
// action to run, and the last one is the lowest priority to run.
//
// NOTE(pag): If two concurrent threads concurrently `Stop`, then one will
//            end up returning immediately, while another will wait for the
//            queues to be flushed.
void Executor::Stop(std::vector<std::unique_ptr<Action>> &remaining_actions) {

  std::vector<pthread_t> workers;
  std::map<unsigned, std::unique_ptr<Action>> prioritized_actions;

  do {
    std::lock_guard<std::mutex> locker(d->lock);
    State old_state = d->state.exchange(State::kNotRunning);

    // If a concurrent thread is waiting for completion, then they have already
    // stole the workers.
    if (old_state == State::kRunning) {
      workers = std::move(d->workers);

    // Nothing to do.
    } else if (old_state == State::kNotRunning) {
      return;
    }

    // Steal the actions. It's possible we're stealing actions from a concurrent
    // thread that is waiting. We consider a `Stop` to take higher priority than
    // a `Wait`.
    prioritized_actions = std::move(d->prioritized_actions);
  } while (false);

  d->state_change.notify_all();

  // Vacuum up all the actions into `remaining_actions`, putting them in
  // priority order for running.
  for (auto it = prioritized_actions.rbegin();
       it != prioritized_actions.rend(); ++it) {
    std::unique_ptr<Action> action;

    // Try to take the first action. The first action owns the rest of
    // the action list.
    action.swap(it->second);
    if (!action) {
      continue;
    }

    // Vacuum up all the actions.
    while (action->next) {
      remaining_actions.emplace_back(std::move(action));
      action.swap(remaining_actions.back()->next);
    }
  }

  // Join the stolen workers.
  for (pthread_t &worker : workers) {
    void *data = nullptr;
    pthread_join(worker, &data);
  }
}

// Wait for all work in the executor to finish.
//
// NOTE(pag): If a `Stop` happens concurrently with a `Wait`, then the
//            `Stop` takes precedence, and any pending work still in the
//            queue will be skipped and passed to the `Stop`.
void Executor::Wait(void) {
  std::unique_lock<std::mutex> wait_locker(d->wait_lock);

  std::vector<pthread_t> workers;

  do {
    std::unique_lock<std::mutex> locker(d->lock);
    if (d->state.load() != State::kRunning) {
      return;
    }

    // First, steal the worker threads, but not the actions.
    workers = std::move(d->workers);
  } while (false);

  auto cond = [this] (void) {
    return d->state.load() != State::kRunning ||
           !(d->num_actions.load() + d->num_pending_actions.load());
  };

  for (auto done = false; !done; ) {
    std::unique_lock<std::mutex> locker(d->lock);
    d->state_change.wait_for(locker, std::chrono::milliseconds(100), cond);

    D( LOG(ERROR)
        << reinterpret_cast<void *>(d.get())
        << " Waiter woke up: "
        << "state=" << d->state.load() << " num_actions="
        << d->num_actions.load() << " num_pending_actions="
        << d->num_pending_actions.load(); )

    switch (d->state.load()) {
      case State::kNotRunning:
      case State::kWaiting:
        done = true;
        break;
      case State::kRunning:
        if (!(d->num_actions.load() + d->num_pending_actions.load())) {
          d->state.store(State::kWaiting);
        }
        break;
    }
  }

  D( LOG(ERROR)
      << reinterpret_cast<void *>(d.get())
      << " Waiter unblocked; notifying workers: "
      << "state=" << d->state.load() << " num_actions="
      << d->num_actions.load() << " num_pending_actions="
      << d->num_pending_actions.load(); )

  d->state_change.notify_all();

  // Join the worker threads.
  for (pthread_t &worker : workers) {
    void *data = nullptr;
    pthread_join(worker, &data);
  }

  std::unique_lock<std::mutex> locker(d->lock);
  if (d->state.load() == State::kWaiting) {
    d->state.store(State::kNotRunning);
  }
}

}  // namespace indexer
