// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/WorkerPool.h>

#include <atomic>
#include <cassert>
#include <cstdint>
#include <mutex>
#include <pthread.h>
#include <thread>
#include <vector>
#include <csignal>

#include <blockingconcurrentqueue.h>

#include <multiplier/Signal.h>

namespace mx {
namespace {

static thread_local bool gInWorkerThread = false;

// Basic worker. We use pthreads instead of `std::thread` for the worker
// stack as that lets us set the stack size. On macOS, the stack sizes
// of non-main threads are usually limited to about 128 pages.
struct Worker {
  pthread_t thread;
  WorkerThreadPoolBase *pool{nullptr};
  unsigned id{0};
};

}  // namespace

template <typename T>
using BlockingQueue = moodycamel::BlockingConcurrentQueue<T>;

template <typename T>
using NonBlockingQueue = moodycamel::ConcurrentQueue<T>;

class Semaphore : public moodycamel::LightweightSemaphore {
 public:
  using moodycamel::LightweightSemaphore::LightweightSemaphore;
};

// An opaque wrapper around a pointer that keeps track of the queue to which
// it belongs.
class QueuePointer {
 public:
  ~QueuePointer(void) {
    if (pool && ptr) {
      pool->DrainInternal(ptr);
    }
    pool = nullptr;
    ptr = nullptr;
  }

  inline QueuePointer(void)
      : pool(nullptr),
        ptr(nullptr) {}

  inline QueuePointer(std::nullptr_t)
      : pool(nullptr),
        ptr(nullptr) {}

  inline explicit QueuePointer(WorkerThreadPoolBase *pool_, void *ptr_)
      : pool(pool_),
        ptr(ptr_) {}

  inline QueuePointer(QueuePointer &&that) noexcept
      : pool(that.pool),
        ptr(that.ptr) {
    that.pool = nullptr;
    that.ptr = nullptr;
  }

  inline QueuePointer &operator=(QueuePointer &&that) noexcept {
    assert(!ptr);
    pool = that.pool;
    ptr = that.ptr;
    that.pool = nullptr;
    that.ptr = nullptr;
    return *this;
  }

  inline operator bool(void) const {
    return ptr != nullptr;
  }

  void *Release(void) {
    auto ret = ptr;
    ptr = nullptr;
    pool = nullptr;
    return ret;
  }

 private:
  QueuePointer(const QueuePointer &) = delete;
  QueuePointer &operator=(const QueuePointer &) = delete;

  WorkerThreadPoolBase *pool;
  void *ptr;
};

class BlockingConcurrentQueue : public BlockingQueue<QueuePointer> {};

// Data that lets the worker pool syncrhonize and manage itself.
class WorkerThreadPoolBase::Impl {
 public:
  Impl(WorkerThreadPoolBase *pool_, unsigned num_workers_);

  // Initialize the implementation. This is split from the constructor
  // as the workers need to be able to call back into `pool`.
  void Start(void);

  WorkerThreadPoolBase * const pool;
  const unsigned num_workers;

  // Tell the workers that they should synchronize.
  std::atomic_bool should_synchronize;

  // Whether or not we are still running.
  std::atomic_bool is_running;
  std::atomic_bool is_joined;
  std::atomic<unsigned> num_joined;
  std::mutex state_lock;

  // Used to synchronize all worker threads so that some non-thread-safe
  // operations can be performed on the `db` or `excutor`.
  std::mutex block_work_lock;
  std::unique_ptr<Semaphore> stop_work_sem;
  std::unique_ptr<Semaphore> continue_work_sem;

  std::atomic_bool signal_handled;

  std::unique_ptr<BlockingConcurrentQueue> queue;
  std::unique_ptr<Semaphore> queue_empty_sem;
  std::atomic<uint64_t> queue_size;
  std::atomic<unsigned> queue_waiters;

  std::vector<Worker> workers;

  void SignalWaiters(void);

  // Enqueue `num_workers` many dummy work items.  Used to wake up any waiting
  // workers after setting `should_synchronize` or `is_running`.
  void EnqueueDummyWorkItems(void);

 private:
  Impl(void) = delete;
  Impl(const Impl &) = delete;
  Impl(Impl &&) noexcept = delete;
};

WorkerThreadPoolBase::Impl::Impl(WorkerThreadPoolBase *pool_,
                                 unsigned num_workers_)
    : pool(pool_),
      num_workers(num_workers_),
      should_synchronize(false),
      is_running(false),
      is_joined(true),
      num_joined(num_workers),
      stop_work_sem(new Semaphore(0)),
      continue_work_sem(new Semaphore(0)),
      signal_handled(false),
      queue(new BlockingConcurrentQueue),
      queue_empty_sem(new Semaphore(0)),
      queue_size(0) {}

// Initialize the implementation. This is split from the constructor
// as the workers need to be able to call back into `pool`.
void WorkerThreadPoolBase::Impl::Start(void) {
  if (is_running.exchange(true)) {
    return;
  }

  assert(0ULL < num_workers);

  workers.clear();
  workers.resize(num_workers);
  for (auto i = 0U; i < num_workers; ++i) {
    auto &worker = workers[i];
    worker.pool = pool;
    worker.id = i;
  }

  num_joined.store(0);
  is_joined.store(false);

  for (auto &worker : workers) {
    pthread_attr_t attrs;
    pthread_attr_init(&attrs);
    pthread_attr_setstacksize(&attrs, 8UL << 20UL  /* 8 MiB */);
    pthread_create(&(worker.thread), &attrs, &ThreadMain, &worker);
  }
}

void WorkerThreadPoolBase::Impl::SignalWaiters(void) {
  if (auto num_waiters = queue_waiters.exchange(0)) {
    queue_empty_sem->signal(static_cast<ssize_t>(num_waiters));
  }
}

void WorkerThreadPoolBase::Impl::EnqueueDummyWorkItems(void) {
  for (auto i = 0U; i < num_workers; i++) {
    (void) queue->enqueue(nullptr);
  }
}

WorkerThreadPoolBase::~WorkerThreadPoolBase(void) {
  Join();
}

WorkerThreadPoolBase::WorkerThreadPoolBase(unsigned num_workers_)
    : d(new Impl(this, num_workers_)) {

  auto stop_work = [this] (int) {
    OnSignalToStopInternal();
  };

  Signal::AddAsyncObserver(SIGINT, stop_work);
  Signal::AddAsyncObserver(SIGQUIT, stop_work);
  Signal::AddAsyncObserver(SIGTERM, stop_work);
}

// Waits for all queues to empty, then return.
//
// NOTE(pag): Depending on how the pool is used, it's possible for another
//            task to be added after `Wait` returns.
void WorkerThreadPoolBase::Wait(void) const {
  if (!d->queue_size.load(std::memory_order_acquire)) {
    return;
  }

  // TODO(pag): There is probably a race condition here.
  d->queue_waiters.fetch_add(1);
  d->queue_empty_sem->wait();
}

// Wait for all workers to join. No work can be added after this point.
void WorkerThreadPoolBase::Join(void) const {
  assert(!gInWorkerThread);

  std::lock_guard<std::mutex> locker(d->state_lock);

  if (!d->is_running.exchange(false)) {
    return;  // It was not running.
  }

  if (d->is_joined.exchange(true)) {
    return;  // Already joined.
  }

  d->EnqueueDummyWorkItems();

  // Wait for all workers to join.
  for (auto &worker : d->workers) {
    void *val = nullptr;
    pthread_join(worker.thread, &val);
  }

  assert(d->num_joined.load() == d->num_workers);

  // We are now joined; delete the queue. This will call the destructors
  // of any `QueuePointer` types, thereby draining whatever remains from
  // inside the queue.
  d->queue.reset();
  d->queue_size.store(0);
  d->should_synchronize.store(false);
  d->signal_handled.store(false);
  d->SignalWaiters();
}

// Start up teh worker pool.
void WorkerThreadPoolBase::Start(void) const {
  d->Start();
}

// Tell the worker pool to stop.
void WorkerThreadPoolBase::Stop(void) {
  if (!gInWorkerThread) {
    Join();
  } else {
    OnSignalToStopInternal();
  }
}

void WorkerThreadPoolBase::OnStart(unsigned) {}
void WorkerThreadPoolBase::OnPause(unsigned) {}
void WorkerThreadPoolBase::OnResumeToStop(unsigned) {}
void WorkerThreadPoolBase::OnResumeToStep(unsigned) {}
void WorkerThreadPoolBase::OnStop(unsigned) {}
void WorkerThreadPoolBase::OnSignalToStop(void) {}

// TODO(pag): There is a pretty blatant race condition here if the queue
//            is not used correctly.
bool WorkerThreadPoolBase::AddWorkInternal(void *ptr_) {
  QueuePointer ptr(this, ptr_);

  // NOTE(pag): The queue can return `false` if there's a problem allocating
  //            memory. My assumption is that `ptr` will be destroyed, and
  //            that its destructor will invoke `DrainInternal` as a
  //            consequence.
  (void) d->queue_size.fetch_add(1);
  if (d->queue->enqueue(std::move(ptr))) {
    return true;
  }

  if (1 == d->queue_size.fetch_sub(1)) {
    d->SignalWaiters();
  }

  return false;
}

// Invoke the function `func` when all workers have been paused.
void WorkerThreadPoolBase::CallWithWorkersPaused(
    std::function<void(void)> func) {
  assert(!gInWorkerThread);

  std::lock_guard<std::mutex> locker(d->block_work_lock);
  d->should_synchronize.store(true);

  // Spam thethe various workers until they all check in.
  const auto num_workers = d->num_workers;
  const ssize_t max_counted = static_cast<ssize_t>(num_workers);
  ssize_t counted = 0;
  do {
    d->EnqueueDummyWorkItems();
    counted += d->stop_work_sem->waitMany(max_counted - counted, 1000);
  } while (counted < max_counted);

  func();

  // Now let them all go again.
  d->should_synchronize.store(false);
  d->continue_work_sem->signal(static_cast<ssize_t>(num_workers));
}

// Main loop of the worker thread.
void *WorkerThreadPoolBase::ThreadMain(void *worker_) {
  const auto worker = reinterpret_cast<Worker *>(worker_);
  worker->pool->DoWork(worker->id);
  pthread_exit(nullptr);
  return nullptr;
}

// Main loop of the worker thread.
void WorkerThreadPoolBase::DoWork(unsigned worker_id) {
  gInWorkerThread = true;

  this->OnStart(worker_id);
  while (d->is_running.load(std::memory_order_acquire)) {

    // We need to synchronize all workers, e.g. so that we can update
    if (d->should_synchronize.load(std::memory_order_acquire)) {
      d->stop_work_sem->signal();
      this->OnPause(worker_id);
      d->continue_work_sem->wait();
      if (!d->is_running.load(std::memory_order_acquire)) {
        this->OnResumeToStop(worker_id);
        break;
      } else {
        this->OnResumeToStep(worker_id);
      }
    }

    QueuePointer work_item;
    d->queue->wait_dequeue(work_item);
    if (work_item) {
      this->StepInternal(worker_id, work_item.Release());
      if (1 == d->queue_size.fetch_sub(1)) {
        d->SignalWaiters();
      }
    }
  }
  this->OnStop(worker_id);
  d->num_joined.fetch_add(1);
}

// Invoked by a signal observer. This triggers the worker threads to
// stop, but it doesn't trigger the `is_joined` state change.
void WorkerThreadPoolBase::OnSignalToStopInternal(void) {
  auto expected = false;
  if (!d->signal_handled.compare_exchange_strong(expected, true)) {
    return;
  }

  std::lock_guard<std::mutex> locker(d->state_lock);

  OnSignalToStop();
  d->is_running.store(false);
  d->EnqueueDummyWorkItems();
}

}  // namespace mx
