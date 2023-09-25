// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Index.h>
#include <multiplier/Re2.h>
#include <fstream>
#include <sstream>
#include <unordered_map>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_string(query, "", "Query pattern to be searched");
DEFINE_uint64(file_id, 0, "ID of the file in which to perform the search");
DEFINE_uint64(fragment_id, 0, "ID of the fragment in which to perform the search");

static std::unordered_map<mx::PackedFileId, std::filesystem::path>
    file_id_to_paths;

static void DumpMatch(const mx::RegexQueryMatch &match) {
  mx::Fragment frag = mx::Fragment::containing(match);
  std::optional<mx::File> file = mx::File::containing(frag);
  std::cout
      << frag.id() << '\t'
      << file->id() << '\t'
      << file_id_to_paths.find(file->id())->second
      << '\n';

  for (size_t i = 0u, max_i = match.num_captures(); i < max_i; ++i) {
    if (auto data = match.captured_data(i)) {
      std::cout << "\t[" << i << "] = \t" << *data << '\n';
    }
  }

  std::cout << "\n\n";
}

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--file_id ID] [--fragment_id ID]\n"
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
        << "Must specify regular expression string to be searched for."
        << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::Index::in_memory_cache(
      mx::Index::from_database(FLAGS_db)));

  for (auto [path, id] : index.file_paths()) {
    file_id_to_paths.emplace(id, path);
  }

  mx::RegexQuery query(FLAGS_query);
  if (!query.is_valid()) {
    std::cerr
        << "Invalid regular expresssion string '" << FLAGS_query << "'."
        << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr
          << "Invalid file id '" << FLAGS_file_id << "'." << std::endl;
      return EXIT_FAILURE;
    }

    for (mx::RegexQueryMatch match : query.match_fragments(file.value())) {
      DumpMatch(match);
    }

  } else if (FLAGS_fragment_id) {
    auto frag = index.fragment(FLAGS_fragment_id);
    if (!frag) {
      std::cerr
          << "Invalid fragment id '" << FLAGS_fragment_id << "'." << std::endl;
      return EXIT_FAILURE;
    }

    for (mx::RegexQueryMatch match : query.match_fragments(frag.value())) {
      DumpMatch(match);
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::RegexQueryMatch match : query.match_fragments(file)) {
        DumpMatch(match);
      }
    }
  }

  return EXIT_SUCCESS;
}
