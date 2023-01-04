// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ThreadLocal.h"

#include <atomic>
#include <cassert>
#include <shared_mutex>
#include <thread>
#include <unordered_map>
#include <vector>

namespace mx {

class ThreadLocalBaseImpl {
 public:
  std::atomic<unsigned> next_worker_index;
  std::shared_mutex data_lock;

  // NOTE(pag): It is not the responsibility of `ThreadLocalBaseImpl` to
  //            destroy the elements in `data`, instead it is `ThreadLocalGC`.
  std::unordered_map<std::thread::id, void *> data;

  std::function<void *(unsigned)> allocator;
  std::function<void(void *)> deleter;

  ThreadLocalBaseImpl(std::function<void *(unsigned)> allocator_,
                      std::function<void(void *)> deleter_)
      : next_worker_index(0u),
        allocator(std::move(allocator_)),
        deleter(std::move(deleter_)) {}
};

namespace {

static thread_local void *tInstance = nullptr;
static thread_local void *tThreadData = nullptr;

// A thread-local garbage collector for the thread-local data.
class ThreadLocalGC {
 public:
  using Test = std::weak_ptr<ThreadLocalBaseImpl>;
  using Cleanup = std::function<void(void)>;

  std::vector<std::pair<Test, Cleanup>> cleanups;
  std::vector<std::pair<Test, Cleanup>> next_cleanups;

  ~ThreadLocalGC(void);

  template <typename T>
  void Track(Test test, T func) {
    cleanups.emplace_back(std::move(test), std::move(func));
  }

  void Collect(void);
};

// Try to collect stuff for expired instances of `ThreadLocal<T>`.
void ThreadLocalGC::Collect(void) {
  for (std::pair<Test, Cleanup> &test_cleanup : cleanups) {
    if (!test_cleanup.first.lock()) {
      test_cleanup.second();
    } else {
      next_cleanups.emplace_back(std::move(test_cleanup));
    }
  }
  next_cleanups.swap(cleanups);
  next_cleanups.clear();
}

ThreadLocalGC::~ThreadLocalGC(void) {
  auto thread_id = std::this_thread::get_id();
  for (std::pair<Test, Cleanup> &test_cleanup : cleanups) {
    if (auto impl = test_cleanup.first.lock()) {
      std::lock_guard<std::shared_mutex> locker(impl->data_lock);
      impl->data[thread_id] = nullptr;
    }
    test_cleanup.second();
  }
}

// If there are any instances of `ThreadLocal<T>`, and if any of those instances
// has been used in a given thread, then that thread's `tCleanups` will be
// initialized. Upon each access, we'll try to cleanup expired thred-local
// data. A key is that we need to try to clean up thread-local data in the
// thread in which it was created.
static thread_local std::unique_ptr<ThreadLocalGC> tCleanups;

}  // namespace

// Initialize with a specific allocator and deleter. Both the allocator
// and delete are guaranteed to be called in the thread invoking `GetOrInit`.
ThreadLocalBase::ThreadLocalBase(std::function<void *(unsigned)> allocator_,
                                 std::function<void(void *)> deleter_,
                                 int)
    : impl(std::make_shared<ThreadLocalBaseImpl>(
          std::move(allocator_), std::move(deleter_))) {}

// Get or initialize the thread-local data.
void *ThreadLocalBase::GetOrInit(void) & {

  // Fast-path: Ideally, we just have a single instance of `ThreadLocal<T>`.
  if (tInstance == this) {
    return tThreadData;
  }

  auto thread_id = std::this_thread::get_id();
  void *data = nullptr;
  ThreadLocalBaseImpl &self = *impl;
  if (tInstance) {
    std::shared_lock<std::shared_mutex> locker(self.data_lock);
    data = self.data[thread_id];
  }

  ThreadLocalGC *cleanups = tCleanups.get();
  if (!cleanups) {
    cleanups = new ThreadLocalGC;
    tCleanups.reset(cleanups);
  } else {
    cleanups->Collect();
  }

  if (!tThreadData) {
    data = impl->allocator(self.next_worker_index.fetch_add(1u));
    assert(data != nullptr);

    cleanups->Track(
        impl,
        [ptr = data, del = self.deleter] (void) {
          del(ptr);
        });

    std::lock_guard<std::shared_mutex> locker(self.data_lock);
    self.data[thread_id] = data;
  }

  tThreadData = data;
  tInstance = this;
  return data;
}

}  // namespace mx
