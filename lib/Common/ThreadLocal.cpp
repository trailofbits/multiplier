// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ThreadLocal.h"

#include <atomic>
#include <shared_mutex>
#include <vector>

namespace mx {
namespace {

static thread_local unsigned tThreadId = 0u;

static std::atomic<unsigned> gNextWorkerId(1u);

}  // namespace

class ThreadLocalBaseImpl {
 public:
  std::atomic<unsigned> next_worker_index;
  std::shared_mutex data_lock;
  std::vector<void *> data;
  std::function<void(void *)> deleter;

  ThreadLocalBaseImpl(std::function<void(void *)> deleter_)
      : deleter(std::move(deleter_)) {}

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
  ThreadLocalBaseImpl &self = *impl;
  if (!tThreadId) {
    void *new_data = allocator(self.next_worker_index.fetch_add(1u));
    std::unique_lock<std::shared_mutex> locker(self.data_lock);
    tThreadId = gNextWorkerId.fetch_add(1u);
    self.data.resize(tThreadId);
    self.data[tThreadId - 1u] = new_data;
    return new_data;
  } else {
    std::shared_lock<std::shared_mutex> locker(self.data_lock);
    return self.data[tThreadId - 1u];
  }
}

}  // namespace mx
