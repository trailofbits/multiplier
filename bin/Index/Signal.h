// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <csignal>
#include <functional>

namespace indexer {

using SignalAction = void(int);
using LibcSignalAction = void(int, siginfo_t *, void *);

class Signal {
 public:
  // Remove all observers.
  static void ClearAllObservers(void);

  // An observer function `func` which will be invoked any time the signal
  // with `signum` is triggered.
  //
  // This function is invoked asynchronously, i.e. it may be executed
  // arbitrarily long after the signal is actually delivered.
  //
  // Many signal observers are permitted to be added to the same signal
  // handler.
  //
  // NOTE(pag): Functionals added should be idempotent.
  static void AddAsyncObserver(int sig_num, std::function<SignalAction> func);

  // A signal handler. This function is executed on the signal stack.
  //
  // Only one handler is allowed per signal.
  static void AddHandler(int sig_num, SignalAction *handler);

  // A signal handler. This function is executed on the signal stack.
  //
  // Only one handler is allowed per signal.
  static void AddHandler(int sig_num, LibcSignalAction *handler);

 private:
  Signal(void) = delete;
};

}  // namespace indexer
