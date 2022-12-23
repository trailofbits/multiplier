// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <functional>
#include <memory>

namespace mx {

class ThreadLocalBaseImpl;

class ThreadLocalBase {
 private:
  ThreadLocalBase(const ThreadLocalBase &) = delete;
  ThreadLocalBase &operator=(const ThreadLocalBase &) = delete;

 protected:

  std::function<void *(unsigned)> allocator;
  std::shared_ptr<ThreadLocalBaseImpl> impl;

  ThreadLocalBase(void) = delete;

  explicit ThreadLocalBase(std::function<void *(unsigned)> allocator_);

  template <typename Allocator>
  ThreadLocalBase(Allocator alloc_)
      : ThreadLocalBase([alloc = std::move(alloc_)] (unsigned index) -> void * {
          return alloc(index);
        }) {}

  void *GetOrInit(void) &;
};

// Allows per-instance thread-local data.
template <typename T>
class ThreadLocal : public ThreadLocalBase {
 private:

  ThreadLocal(const ThreadLocal<T> &) = delete;
  ThreadLocal<T> &operator=(const ThreadLocal<T> &) = delete;

 public:
  template <typename Allocator>
  explicit ThreadLocal(Allocator allocator_)
      : ThreadLocalBase(std::move(allocator_)) {}

  ThreadLocal(void)
      : ThreadLocal([] (unsigned) -> T * { return new T; }) {}

  inline std::shared_ptr<T> Lock(void) & {
    return std::shared_ptr<T>(impl, reinterpret_cast<T *>(GetOrInit()));
  }
};

}  // namespace mx
