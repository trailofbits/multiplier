// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ThreadLocal.h"

#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

#include <iostream>

namespace mx {
namespace {

static thread_local unsigned tThreadId = 0u;
static thread_local void *tInstance = nullptr;
static thread_local void *tThreadData = nullptr;
static std::atomic<unsigned> gNextWorkerId(1u);

}  // namespace

class ThreadLocalBaseImpl {
 public:
  std::atomic<unsigned> next_worker_index;
  std::shared_mutex data_lock;
  std::vector<void *> data;
  std::function<void(void *)> deleter;

  ThreadLocalBaseImpl(std::function<void(void *)> deleter_)
      : next_worker_index(0u),
        deleter(std::move(deleter_)) {}

  ~ThreadLocalBaseImpl(void) {
    for (auto ptr : data) {
      deleter(ptr);
    }
  }
};

ThreadLocalBase::ThreadLocalBase(std::function<void *(unsigned)> allocator_,
                                 std::function<void(void *)> deleter_,
                                 int)
    : allocator(std::move(allocator_)),
      impl(std::make_shared<ThreadLocalBaseImpl>(std::move(deleter_))) {
  impl->data.reserve(gNextWorkerId.load() + 64u);
}

void *ThreadLocalBase::GetOrInit(void) & {
  if (tInstance == this) {
    return tThreadData;
  }

  ThreadLocalBaseImpl &self = *impl;
  if (!tThreadId) {
    tThreadData = allocator(self.next_worker_index.fetch_add(1u));

    std::lock_guard<std::shared_mutex> locker(self.data_lock);
    tThreadId = gNextWorkerId.fetch_add(1u);
    assert(tThreadId != 0u);
    assert(tThreadId > self.data.size());
    self.data.resize(tThreadId);
    self.data[tThreadId - 1u] = tThreadData;

  } else {
    std::shared_lock<std::shared_mutex> locker(self.data_lock);
    tThreadData = self.data[tThreadId - 1u];
  }

  tInstance = this;
  return tThreadData;
}

}  // namespace mx
