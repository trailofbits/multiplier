// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <iostream>
#include <multiplier/Index.h>
#include <multiplier/Weggli.h>
#include <fstream>
#include <sstream>
#include <unordered_map>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_bool(c_plus_plus, false, "Should we interpret the query as C++ code?");
DEFINE_string(query, "", "Query pattern to be searched");
DEFINE_uint32(tab_size, 4, "Size of tabs in spaces");

// Dump out the text of a match
static void DumpMatch(
    const std::unordered_map<mx::RawEntityId, std::filesystem::path> &paths,
    const mx::FileLocationCache &cache,
    mx::WeggliQueryMatch match) {

  // Get the tokens for the whole match range. The data covered by the tokens
  // might exceed the data covered by the match.
  std::optional<mx::TokenRange> matched_toks = match.captured_tokens(0u);
  if (!matched_toks) {
    return;
  }

  // Get the file containing the match, and print out its path.
  if (auto file = mx::File::containing(match)) {
    if (auto path_it = paths.find(file->id()); path_it != paths.end()) {
      std::cout << "File: " << path_it->second.generic_string() << ":\n";
    }
  }

  // Get the file tokens coverage the matched data, then print out the line
  // numbers covered by the match.
  mx::TokenRange file_toks = matched_toks->file_tokens();
  if (file_toks.size()) {
    auto first_loc = file_toks.front().location(cache);
    auto last_loc = file_toks.back().location(cache);
    if (first_loc && last_loc) {
      std::cout
          << "Lines: " << first_loc->first << "-"
          << last_loc->first << '\n';
    }
  }

  // Print out the raw data of the entire capture.
  if (auto data = match.captured_data(0)) {
    std::cout << *data;
  }

  std::cout << "\n\n";
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " --query QUERY_STRING";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (1 >= argc || FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_query.empty()) {
    std::cerr
        << "Must specify query string to be searched for.\n";
    return EXIT_FAILURE;
  }

  mx::WeggliQuery query(FLAGS_query, FLAGS_c_plus_plus);
  if (!query.IsValid()) {
    std::cerr << "Invalid weggli query.\n";
    return EXIT_FAILURE;
  }

  mx::Index index = mx::EntityProvider::from_database(FLAGS_db);

  mx::FileLocationConfiguration config;
  if (FLAGS_tab_size) {
    config.tab_width = FLAGS_tab_size;
  }

  std::unordered_map<mx::RawEntityId, std::filesystem::path> file_paths;
  for (auto [path, id] : index.file_paths()) {
    file_paths[id] = path;
  }

  mx::FileLocationCache cache(config);
  for (mx::WeggliQueryMatch match : index.query_fragments(query)) {
    DumpMatch(file_paths, cache, std::move(match));
  }

  return EXIT_SUCCESS;
}
