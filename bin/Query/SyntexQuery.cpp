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

static void PrintMatch(mx::Index index, const mx::syntex::Match &match)
{
  if (FLAGS_suppress_output) {
    return;
  }

  auto entity = index.entity(match.Entity());
  auto fragment = *index.fragment_containing(match.Entity());
  mx::TokenRange tok_range;
  if(std::holds_alternative<mx::Token>(entity)) {
    tok_range = std::get<mx::Token>(entity);
  } else if(std::holds_alternative<mx::Stmt>(entity)) {
    tok_range = std::get<mx::Stmt>(entity).tokens();
  } else if(std::holds_alternative<mx::Decl>(entity)) {
    tok_range = std::get<mx::Decl>(entity).tokens();
  }

  // Print matching fragment ID
  std::cout << "Match in " << fragment.id() << ":\n";
  for (auto token : fragment.parsed_tokens()) {
    if (token.id() == tok_range.front().id()) {
      // Switch to ANSI red for the first matching token
      std::cout << ANSI_RED;
    }

    std::cout << token.data() << " ";

    if (token.id() == tok_range.back().id()) {
      // Reset color after last matching token
      std::cout << ANSI_RESET;
    }
  }

  std::cout << "\n";

  for (auto &metavar : match.MetavarMatches()) {
    std::cout << "Matching metavar " << metavar.Name() << "\n";
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

  // Parse query

  auto res = index.query_syntex(FLAGS_query);

  if (!res.has_value()) {
    std::cerr << "Query `" << FLAGS_query << "` has no valid parses\n";
    return EXIT_FAILURE;
  }

  for(auto match : *res) {
    PrintMatch(index, match);
  }

  return EXIT_SUCCESS;
}
