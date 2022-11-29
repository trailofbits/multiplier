// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <type_traits>

#include "Executor.h"

namespace mx {

enum WorkerId : unsigned;

// An executor action.
class Action {
 public:
  Action(void) = default;
  virtual ~Action(void);

  // Run this action in the worker `worker_id`. The action itself may need to
  // add more work to the executor, and so it's given a reference to the
  // executor for this reason.
  virtual void Run(Executor exe, WorkerId worker_id) = 0;

 private:
  friend class Executor;

  Action(const Action &) = delete;
  Action(Action &&) noexcept = delete;
  Action &operator=(const Action &) = delete;
  Action &operator=(Action &&) noexcept = delete;
};

// Represents a deferred action, i.e. when a `DeferredAction::Ptr` expires,
// the contained action will be emplaced onto the executor and run.
class DeferredAction : public std::enable_shared_from_this<DeferredAction> {
 private:
  Executor exe;
  std::unique_ptr<Action> action;

  inline DeferredAction(const Executor &exe_, Action *action_)
      : exe(exe_),
        action(action_) {}

 public:
  using Ptr = std::shared_ptr<DeferredAction>;

  ~DeferredAction(void) {
    exe.AddAction(std::move(action));
  }

  static Ptr Create(const Executor &exe_, std::unique_ptr<Action> action_) {
    auto act = new DeferredAction(exe_, action_.release());
    return act->shared_from_this();
  }

  template<typename T, typename ... Args>
  static Ptr Emplace(const Executor &exe_, Args &&... args) {
    static_assert(std::is_base_of_v<T, Action>);
    auto act = new DeferredAction(exe_, new T(std::forward<Args>(args)...));
    return act->shared_from_this();
  }

  template <typename T>
  std::shared_ptr<T> Lock(
      std::enable_if_t<std::is_base_of_v<T, Action>, int> = 0) {
    if (auto casted = dynamic_cast<T *>(action.get())) {
      std::shared_ptr<T> ret(this->shared_from_this(), casted);
      return ret;
    } else {
      return {};
    }
  }
};

}  // namespace mx
