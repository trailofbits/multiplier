// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ProgressBar.h"

#include <atomic>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <blockingconcurrentqueue.h>
#pragma GCC diagnostic pop

#include <llvm/Support/raw_ostream.h>

namespace indexer {
namespace {

class Semaphore : public moodycamel::LightweightSemaphore {
 public:
  using moodycamel::LightweightSemaphore::LightweightSemaphore;
};

static std::string gOutput;
static std::atomic<unsigned> gNumProgressBars;
static std::mutex gProgressLinesLock;
static Semaphore *gReportSem = nullptr;
static std::vector<std::unique_ptr<std::string>> gProgressLines;

static const auto kProgressBars = \
    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";

static const double kNumProgressBars = 40;

static int NumDigits(uint64_t val) {
  if (!val) {
    return 1;
  } else {
    int num_digits = 0;
    while (val) {
      val /= 10;
      num_digits++;
    }
    return num_digits;
  }
}

// Report the results of things.
static void Report(Semaphore *sem_) {
  std::unique_ptr<Semaphore> sem(sem_);
  while (sem->wait()) {
    if (!gNumProgressBars.load()) {
      return;
    }
    gOutput.clear();
    llvm::raw_string_ostream os(gOutput);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
    os << "\r\e[1;1H\e[2J";
#pragma GCC diagnostic pop
    {
      std::unique_lock<std::mutex> locker(gProgressLinesLock);
      for (const auto &line : gProgressLines) {
        if (line && !line->empty() && line->front()) {
          os << line->data();
        }
      }
    }
    os.flush();
    gOutput.push_back('\n');
    gOutput.push_back('\0');
    fputs(gOutput.data(), stderr);
    fflush(stderr);
  }
}

// Allocate a line.
static std::pair<size_t, std::string *> AllocateLine(void) {
  auto line_data = new std::string(1024ull, '\0');
  std::unique_lock<std::mutex> locker(gProgressLinesLock);
  if (!gNumProgressBars.fetch_add(1u)) {
    gReportSem = new Semaphore;
    std::thread(Report, gReportSem).detach();
  }
  auto index = gProgressLines.size();
  gProgressLines.emplace_back(line_data);
  return {index, line_data};
}

//// Free a previously allocated line.
//static void FreeLine(size_t index) {
//  std::unique_lock<std::mutex> locker(gProgressLinesLock);
//  if (gNumProgressBars.fetch_sub(1u) == 1) {
//    gReportSem->signal(1u);
//    gReportSem = nullptr;
//  }
//  gProgressLines[index].reset();
//}

}  // namespace

struct ProgressBar::Impl {
  Impl(const char *label_, std::chrono::seconds report_freq_);
  ~Impl(void);

  void Report(void) {
    const auto max_step = step.load();
    const auto curr = static_cast<uint32_t>(max_step);
    const auto max = static_cast<uint32_t>(max_step >> 32UL);
    Report(curr, max, *line.second, next_line_data);
  }

  void Report(uint32_t curr, uint32_t max, std::string &line,
              std::string &next_line);

  const char * const label;
  const std::chrono::seconds report_frequency;

  std::atomic<uint64_t> step;
  std::atomic<bool> done;
  std::string next_line_data;
  std::pair<size_t, std::string *> line;
  std::thread progress_reporter_thread;
};

ProgressBar::Impl::Impl(const char *label_, std::chrono::seconds report_freq_)
    : label(label_),
      report_frequency(report_freq_),
      step(0),
      done(false),
      next_line_data(1024ull, '\0'),
      line(AllocateLine()),
      progress_reporter_thread(
          [this] (void) {
            while (!done.load()) {
              Report();
              std::this_thread::sleep_for(report_frequency);
            }
          }) {}

ProgressBar::Impl::~Impl(void) {
  done.store(true);

  if (progress_reporter_thread.joinable()) {
    progress_reporter_thread.join();
  }

  Report();

  // NOTE(pag): We'll let it leak.
  // FreeLine(line.first);
}

void ProgressBar::Impl::Report(uint32_t curr, uint32_t max,
                               std::string &curr_line,
                               std::string &next_line) {
  if (!max) {
    return;
  }

  const auto steps_done = static_cast<double>(curr);
  const auto steps_total = static_cast<double>(max);
  const auto percentage = std::min<double>(1.0, steps_done / steps_total);
  const auto lpad = static_cast<int>(
      std::min(kNumProgressBars, (percentage * kNumProgressBars)));
  const auto rpad = static_cast<int>(std::max(0.0, kNumProgressBars - lpad));
  assert((lpad + rpad) == static_cast<int>(kNumProgressBars));
  const auto num_digits = NumDigits(max);
  const auto label_len = strlen(label);
  const auto label_rpad = label_len < 30ull ? 30ull - label_len : 0;
  const auto div_rpad = num_digits < 8 ? 16 - (num_digits * 2) : 0;

  // Write into `next_line`, which is "local" to the owning thread.
  auto len = snprintf(next_line.data(), next_line.size() - 2u,
          "%s%*s (%*" PRIu32 " / %" PRIu32 ")%*s %3d%% [%.*s%*s]\n",
          label, static_cast<int>(label_rpad), "",
          num_digits, curr, max, static_cast<int>(div_rpad), "",
          static_cast<int>(percentage * 100.0),
          lpad, kProgressBars, rpad, "");
  if (0 < len) {
    next_line[static_cast<unsigned>(len)] = '\0';
  }

  std::unique_lock<std::mutex> locker(gProgressLinesLock);

  // Publish `next_line` into `gProgressLines`, wherever it is meant to be
  // in there.
  curr_line.swap(next_line);

  gReportSem->signal(1);
}

ProgressBar::ProgressBar(const char *label_, std::chrono::seconds report_freq_)
    : d(new Impl(label_, report_freq_)) {}

ProgressBar::~ProgressBar(void) {}

void ProgressBar::Advance(void) const {
  d->step.fetch_add(1ULL);
}

void ProgressBar::AddWork(uint64_t num_steps) const {
  auto old_val = d->step.fetch_add(num_steps << 32ULL);
  (void) old_val;
  (void) old_val;
}

}  // namespace indexer
