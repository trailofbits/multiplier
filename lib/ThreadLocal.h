// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <functional>
#include <memory>

#pragma GCC visibility push(hidden)
namespace mx {

template <typename T>
class ThreadLocal;

class ThreadLocalBaseImpl;

class ThreadLocalBase {
 private:
  template <typename>
  friend class ThreadLocal;

  ThreadLocalBase(const ThreadLocalBase &) = delete;
  ThreadLocalBase &operator=(const ThreadLocalBase &) = delete;

  // Initialize with a specific allocator and deleter. Both the allocator
  // and delete are guaranteed to be called in the thread invoking `GetOrInit`.
  explicit ThreadLocalBase(std::function<void *(unsigned)> allocator_,
                           std::function<void(void *)> deleter_,
                           int);

  // Get or initialize the thread-local data.
  void *GetOrInit(void) &;

 protected:
  std::shared_ptr<ThreadLocalBaseImpl> impl;

  ThreadLocalBase(void) = delete;

  template <typename Allocator, typename Deleter>
  ThreadLocalBase(Allocator alloc_, Deleter deleter_)
      : ThreadLocalBase(std::move(alloc_), std::move(deleter_), 0) {}
};

// Allows per-instance thread-local data.
template <typename T>
class ThreadLocal : public ThreadLocalBase {
 private:

  ThreadLocal(const ThreadLocal<T> &) = delete;
  ThreadLocal<T> &operator=(const ThreadLocal<T> &) = delete;

  ThreadLocal(void) = delete;

 public:
  template <typename Allocator, typename Deleter>
  explicit ThreadLocal(Allocator allocator_, Deleter deleter_)
      : ThreadLocalBase(std::move(allocator_), std::move(deleter_)) {}

  inline std::shared_ptr<T> Lock(void) & {
    return std::shared_ptr<T>(impl, reinterpret_cast<T *>(GetOrInit()));
  }
};

}  // namespace mx
#pragma GCC visibility pop
