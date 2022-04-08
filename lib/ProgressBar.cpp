// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/ProgressBar.h>

#include <atomic>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <blockingconcurrentqueue.h>
#include <llvm/Support/raw_ostream.h>

namespace mx {
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

// Free a previously allocated line.
static void FreeLine(size_t index) {
  std::unique_lock<std::mutex> locker(gProgressLinesLock);
  if (gNumProgressBars.fetch_sub(1u) == 1) {
    gReportSem->signal(1u);
    gReportSem = nullptr;
  }
  gProgressLines[index].reset();
}

}  // namespace

struct ProgressBar::Impl {
  Impl(const char *label_, std::chrono::seconds report_freq_);
  ~Impl(void);

  void Report(uint32_t curr, uint32_t max, std::string &line,
              std::string &next_line);

  const char * const label;
  const std::chrono::seconds report_frequency;

  std::atomic<uint64_t> step;
  std::atomic<bool> done;
  std::atomic<uint64_t> sum_of_elapsed_time_ms_squared;
  std::atomic<uint64_t> sum_of_elapsed_time_ms;
  unsigned num_workers;
  Semaphore has_work_sem;
  std::thread progress_reporter_thread;
};

ProgressBar::Impl::Impl(const char *label_, std::chrono::seconds report_freq_)
    : label(label_),
      report_frequency(report_freq_),
      step(0),
      done(false),
      sum_of_elapsed_time_ms_squared(0),
      sum_of_elapsed_time_ms(0),
      num_workers(1),
      has_work_sem(),
      progress_reporter_thread(
          [=] (void) {
            auto [line_index, line_ptr] = AllocateLine();
            std::string next_line(1024ull, '\0');

            uint32_t curr = 0;
            uint32_t max = 0;
            while (1) {
              has_work_sem.wait();
              for (; ; std::this_thread::sleep_for(report_frequency)) {
                if (done.load()) {
                  FreeLine(line_index);
                  return;
                }
                const auto max_step = step.load();
                curr = static_cast<uint32_t>(max_step);
                max = static_cast<uint32_t>(max_step >> 32UL);
                Report(curr, max, *line_ptr, next_line);
                if (curr >= max) {
                  break;
                }
              }
            }
          }) {}

ProgressBar::Impl::~Impl(void) {
  done.store(true);
  step.store(0);
  has_work_sem.signal(1);

  if (progress_reporter_thread.joinable()) {
    progress_reporter_thread.join();
  }
}

void ProgressBar::Impl::Report(uint32_t curr, uint32_t max, std::string &line,
                               std::string &next_line) {
  if (!max) {
    return;
  }
  const auto steps_done = static_cast<double>(curr);
  const auto steps_total = static_cast<double>(max);

  double estimated_remaining_time_seconds = 0;
  if (steps_done > 0) {
    // Our estimate of the remaining time is an extrapolation based on the
    // 95th-percentile upper bound on the expected elapsed time of a job, using
    // the elapsed times of the jobs that have already finished as our sample.
    const auto average_elapsed_time_ms =
        static_cast<double>(sum_of_elapsed_time_ms.load()) / steps_done;
    const auto elapsed_time_ms_variance =
        (static_cast<double>(sum_of_elapsed_time_ms_squared.load()) /
         steps_done) - pow(average_elapsed_time_ms, 2);
    const auto z_score = 1.96;
    const auto average_elapsed_time_ms_upper_bound =
        average_elapsed_time_ms +
        z_score * sqrt(elapsed_time_ms_variance) / sqrt(steps_done);
    estimated_remaining_time_seconds =
        average_elapsed_time_ms_upper_bound * (steps_total - steps_done) /
        (1000 * num_workers);
  }

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
          "%s%*s (%*" PRIu32 " / %" PRIu32 ")%*s %3d%% [%.*s%*s]  "
          "%.2f minutes remaining\n",
          label, static_cast<int>(label_rpad), "",
          num_digits, curr, max, static_cast<int>(div_rpad), "",
          static_cast<int>(percentage * 100.0),
          lpad, kProgressBars, rpad, "",
          estimated_remaining_time_seconds / 60);
  if (0 < len) {
    next_line[static_cast<unsigned>(len)] = '\0';
  }

  std::unique_lock<std::mutex> locker(gProgressLinesLock);

  // Publish `next_line` into `gProgressLines`, wherever it is meant to be
  // in there.
  line.swap(next_line);

  gReportSem->signal(1);
}

ProgressBar::ProgressBar(const char *label_, std::chrono::seconds report_freq_)
    : d(new Impl(label_, report_freq_)) {}

ProgressBar::~ProgressBar(void) {}

void ProgressBar::Advance(std::chrono::duration<double> elapsed_time) const {
  d->step.fetch_add(1);

  const auto elapsed_time_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time)
          .count();
  if (0 < elapsed_time_ms) {
    d->sum_of_elapsed_time_ms.fetch_add(static_cast<uint64_t>(elapsed_time_ms));

    const auto elapsed_time_ms_squared = std::pow(
        static_cast<double>(elapsed_time_ms), 2);
    d->sum_of_elapsed_time_ms_squared.fetch_add(
        static_cast<uint64_t>(elapsed_time_ms_squared));
  }
}

void ProgressBar::AddWork(uint64_t num_steps) const {
  const auto prev = d->step.fetch_add(num_steps << 32ULL);
  const auto prev_curr = static_cast<uint32_t>(prev);
  const auto prev_max = static_cast<uint32_t>(prev >> 32ULL);
  if (prev_curr >= prev_max) {
    d->has_work_sem.signal(1);
  }
}

void ProgressBar::SetNumWorkers(unsigned num_workers) const {
  d->num_workers = num_workers;
};

}  // namespace mx
