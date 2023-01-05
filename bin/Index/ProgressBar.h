// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <chrono>
#include <memory>

namespace indexer {

class ProgressBar {
 public:
  ProgressBar(const char *label_, std::chrono::seconds report_freq_);

  ~ProgressBar(void);

  void Advance(std::chrono::duration<double> elapsed_time) const;
  void AddWork(uint64_t num_steps) const;

  void SetNumWorkers(unsigned num_workers) const;
 private:
  ProgressBar(void) = delete;
  ProgressBar(const ProgressBar &) = delete;
  ProgressBar &operator=(const ProgressBar &) = delete;

  struct Impl;

  const std::unique_ptr<Impl> d;
};

class ProgressBarStep {
 public:
  inline explicit ProgressBarStep(const ProgressBar &bar_)
      : ProgressBarStep(&bar_) {}

  inline explicit ProgressBarStep(const std::unique_ptr<ProgressBar> &bar_)
      : ProgressBarStep(bar_.get()) {}

  inline explicit ProgressBarStep(const ProgressBar *bar_)
      : bar(bar_),
        start_time(std::chrono::system_clock::now()) {}

  inline ~ProgressBarStep(void) {
    auto finish_time = std::chrono::system_clock::now();
    if (bar) {
      bar->Advance(finish_time - start_time);
    }
  }

 private:
  ProgressBarStep(void) = delete;
  ProgressBarStep(const ProgressBarStep &) = delete;
  ProgressBarStep &operator=(const ProgressBarStep &) = delete;

 protected:
  const ProgressBar * const bar;
  std::chrono::system_clock::time_point start_time;
};

// Like a `ProgressBarStep`, but also adds work to the bar.
class ProgressBarWork : public ProgressBarStep {
 private:
  using ProgressBarStep::ProgressBarStep;

 public:
  template <typename T>
  inline explicit ProgressBarWork(const std::unique_ptr<T> &bar_)
      : ProgressBarStep(bar_.get()) {
    if (bar) {
      bar->AddWork(1);
    }
  }
  template <typename T>
  inline explicit ProgressBarWork(const T &bar_)
      : ProgressBarStep(bar_) {
    if (bar) {
      bar->AddWork(1);
    }
  }
};

}  // namespace indexer
