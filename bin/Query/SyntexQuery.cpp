// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>
#include <mutex>
#include <thread>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/Index.h>
#include <multiplier/Syntex.h>

#define ANSI_RED    "\x1b[1;31m"
#define ANSI_RESET  "\x1b[1;0m"

DECLARE_bool(help);
DEFINE_string(db, "", "Path to Multiplier database.");
DEFINE_string(query, "", "Use argument value as query");
DEFINE_uint64(threads, 0, "Use this number of threads");
DEFINE_bool(suppress_output, false, "Don't print matches to stdout");

static std::mutex gMatchPrintingMutex;

static void PrintMatch(const mx::syntex::Match &match)
{
  if (FLAGS_suppress_output) {
    return;
  }

  {
    std::lock_guard<std::mutex> guard(gMatchPrintingMutex);

    // Print matching fragment ID
    std::cout << "Match in " << match.Fragment().id() << ":\n";

    for (auto token : match.Fragment().parsed_tokens()) {
      if (token.id() == match.FirstTokenId()) {
        // Switch to ANSI red for the first matching token
        std::cout << ANSI_RED;
      }

      std::cout << token.data() << " ";

      if (token.id() == match.LastTokenId()) {
        // Reset color after last matching token
        std::cout << ANSI_RESET;
      }
    }

    std::cout << "\n";

    for (auto &metavar : match.MetavarMatches()) {
      std::cout << "Matching metavar " << metavar.Name() << "\n";
    }
  }
}

static void ProcessFragmentRange(const mx::syntex::ParsedQuery &parsed_query,
                                  const mx::RawEntityId *begin,
                                  const mx::RawEntityId *end)
{
  for (; begin < end; ++begin) {
    std::vector<mx::syntex::Match> matches =
      parsed_query.FindInFragment(*begin);

    for (const mx::syntex::Match &match : matches) {
      PrintMatch(match);
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_db.empty()) {
    std::cerr << "Need to specify a database using --db" << std::endl;
    return EXIT_FAILURE;
  }

  // Setup index and grammar

  mx::Index index = mx::EntityProvider::from_database(FLAGS_db);
  mx::syntex::Grammar grammar(index, FLAGS_db);

  // Parse query

  mx::syntex::ParsedQuery parsed_query(grammar, FLAGS_query);

  if (!parsed_query.IsValid()) {
    std::cerr << "Query `" << FLAGS_query << "` has no valid parses\n";
    return EXIT_FAILURE;
  }

  // Choose number of threads

  size_t threads = FLAGS_threads ?: std::thread::hardware_concurrency();
  std::cout << "starting matcher with " << threads << " threads\n";

  // Collect all fragments to process

  std::vector<mx::RawEntityId> fragment_ids;

  for (const mx::File &file : mx::File::in(index)) {
    for (mx::RawEntityId fragment_id : file.fragment_ids()) {
      fragment_ids.push_back(fragment_id);
    }
  }

  // Find the ideal number of fragments per thread

  size_t fragments_per_thread = fragment_ids.size() / threads;


  // Create workers

  std::vector<std::thread> thread_pool;

  auto cur = &fragment_ids.front();
  auto last = &fragment_ids.back();

  while (cur < last) {
    auto end = cur + fragments_per_thread;
    if (end > last) {
      end = last;
    }
    thread_pool.emplace_back(ProcessFragmentRange, parsed_query, cur, end);
    cur = end;
  }

  // Wait for all workers to finish

  for (auto &thread : thread_pool) {
    thread.join();
  }

  return EXIT_SUCCESS;
}
