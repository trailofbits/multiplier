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
#include <multiplier/Entities/TokenKind.h>
#include <multiplier/Index.h>
#include <multiplier/Weggli.h>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "Index.h"

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_string(query, "", "Query pattern to be searched");
DEFINE_uint64(file_id, 0, "ID of the file in which to perform the search");
DEFINE_uint64(fragment_id, 0, "ID of the fragment in which to perform the search");
DEFINE_bool(c_plus_plus, false, "Should we interpret the query as C++ code?");
DEFINE_bool(print_matches, false, "Print variable matches found for the syntax");

static std::unordered_map<mx::PackedFileId, std::filesystem::path>
    file_id_to_paths;

static void DumpMatch(const mx::WeggliQueryMatch &match) {
  mx::Fragment frag = mx::Fragment::containing(match);
  std::optional<mx::File> file = mx::File::containing(frag);
  std::cout
      << frag.id() << '\t'
      << file->id() << '\t'
      << file_id_to_paths.find(file->id())->second
      << "\n";

  if (FLAGS_print_matches) {
    std::cout << "Tokens:\n";
    for (mx::Token tok : match) {
      std::cout
          << '\t' << tok.id() << '\t' << mx::EnumeratorName(tok.kind())
          << '\t' << tok.data() << '\n';
    }

    std::cout << "Captures:\n";
    for (std::string var : match.captured_variables()) {
      std::cout << "\t[" << var << "]:\n";
      if (auto capture = match.captured_tokens(var)) {
        for (mx::Token tok : *capture) {
          std::cout
            << "\t\t" << tok.id() << '\t' << mx::EnumeratorName(tok.kind())
            << '\t' << tok.data() << '\n';
        }
      }
    }
  }

  RenderFragment(std::cout, frag, match, "\t\t", true);

  std::cout << "\n\n";
}

extern "C" int main(int argc, char *argv[]) {
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

  mx::WeggliQuery query(FLAGS_query, FLAGS_c_plus_plus);
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

    for (mx::WeggliQueryMatch match : query.match_fragments(file.value())) {
      DumpMatch(match);
    }

  } else if (FLAGS_fragment_id) {
    auto frag = index.fragment(FLAGS_fragment_id);
    if (!frag) {
      std::cerr
          << "Invalid fragment id '" << FLAGS_fragment_id << "'." << std::endl;
      return EXIT_FAILURE;
    }

    for (mx::WeggliQueryMatch match : query.match_fragments(frag.value())) {
      DumpMatch(match);
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::WeggliQueryMatch match : query.match_fragments(file)) {
        DumpMatch(match);
      }
    }
  }

  return EXIT_SUCCESS;
}

