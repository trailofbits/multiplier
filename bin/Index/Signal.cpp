// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Signal.h"

#include <atomic>
#include <cstdint>
#include <vector>
#include <mutex>
#include <thread>
#include <unistd.h>

namespace mx {
namespace {

enum : int {
  kMaxSigNum = 48
};

static std::unique_ptr<std::thread> gObserverThread;
static std::vector<std::function<SignalAction>> gObservers[kMaxSigNum];
static std::mutex gObserversLock;

// The total number of delivered signals.
static std::atomic<uint64_t> gTotalHitCount(0);

// The total number of delivered signals per signal number.
static std::atomic<uint64_t> gHitCount[kMaxSigNum];

// Previous signal handlers that were registered.
static std::atomic<LibcSignalAction *> gPrevHandler[kMaxSigNum];
static std::atomic<LibcSignalAction *> gCurrHandler[kMaxSigNum];

// Invoked when a signal is received.
static void SignalHandler(int sig_num, siginfo_t *info, void *context) {
  if (0 <= sig_num && sig_num < kMaxSigNum) {
    gHitCount[sig_num].fetch_add(1);
    gTotalHitCount.fetch_add(1);
  }

  auto curr_handler = gCurrHandler[sig_num].load(std::memory_order_acquire);
  if (curr_handler) {
    curr_handler(sig_num, info, context);
  }

  auto prev_handler = gPrevHandler[sig_num].load(std::memory_order_acquire);
  if (prev_handler) {
    prev_handler(sig_num, info, context);
  }
}

// Runs the signal thread, waits to see if there are any pending observers to
// execute, and then executes them.
static void ExecuteObservers(void) {
  auto should_shutdown = false;
  do {
    while (!gTotalHitCount.load(std::memory_order_acquire)) {
      usleep(500000);  // 0.5 seconds.
    }

    std::lock_guard<std::mutex> locker(gObserversLock);

    int i = 0;
    for (auto &count : gHitCount) {
      const auto sig_num = i++;
      const auto old_count = count.exchange(0);
      if (!old_count) {
        continue;
      }

      // Shut down the signal thread on receipt of these signals.
      switch (sig_num) {
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
#ifdef SIGXCPU
        case SIGXCPU:
#endif
          should_shutdown = true;
          break;
        default:
          break;
      }

      gTotalHitCount.fetch_sub(old_count);

      if (gObservers[sig_num].empty()) {
        continue;
      }

      for (uint64_t j = 0; j < old_count; ++j) {
        for (auto &observer : gObservers[sig_num]) {
          observer(sig_num);
        }
      }
    }
  } while (!should_shutdown);
}

}  // namespace

// Remove all observers.
void Signal::ClearAllObservers(void) {
  std::lock_guard<std::mutex> locker(gObserversLock);
  for (auto &observers : gObservers) {
    observers.clear();
  }
}

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
void Signal::AddAsyncObserver(int sig_num, std::function<SignalAction> func) {
  std::lock_guard<std::mutex> locker(gObserversLock);

  if (!gObserverThread) {
    auto sig_thread = new std::thread(ExecuteObservers);
    sig_thread->detach();
    gObserverThread.reset(sig_thread);
  }

  if (gObservers[sig_num].empty()) {
    struct sigaction act;
    sigaction(sig_num, nullptr, &act);
    if (act.sa_sigaction) {
      if (act.sa_sigaction != SignalHandler) {
        gPrevHandler[sig_num].store(act.sa_sigaction);
      }
    } else {
      act.sa_flags = SA_RESTART | SA_SIGINFO;
      sigfillset(&(act.sa_mask));
    }
    act.sa_sigaction = SignalHandler;
    sigaction(sig_num, &act, nullptr);
  }

  gObservers[sig_num].push_back(func);
}

// A signal handler. This function is executed on the signal stack.
//
// Only one handler is allowed per signal.
void Signal::AddHandler(int sig_num, SignalAction *handler) {
  AddHandler(sig_num, reinterpret_cast<LibcSignalAction *>(handler));
}

// A signal handler. This function is executed on the signal stack.
//
// Only one handler is allowed per signal.
void Signal::AddHandler(int sig_num, LibcSignalAction *handler) {
  if (gCurrHandler[sig_num].exchange(handler)) {
    return;
  }

  struct sigaction act = {};
  sigaction(sig_num, nullptr, &act);
  if (act.sa_sigaction) {
    if (act.sa_sigaction != SignalHandler) {
      gPrevHandler[sig_num].store(act.sa_sigaction);
    }
  } else {
    switch (sig_num) {
      case SIGSEGV:
      case SIGILL:
      case SIGFPE:
#ifdef SIGBUS
      case SIGBUS:
#endif
#ifdef SIGSTKFLT
      case SIGSTKFLT:
#endif
        act.sa_flags = 0;
        break;
      default:
        act.sa_flags = SA_RESTART;
    }
    sigfillset(&(act.sa_mask));
  }
  act.sa_flags |= SA_SIGINFO;
  act.sa_sigaction = SignalHandler;
  sigaction(sig_num, &act, nullptr);
}

}  // namespace mx
