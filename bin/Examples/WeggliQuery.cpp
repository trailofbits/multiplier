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
#include <multiplier/Weggli.h>
#include <fstream>
#include <sstream>

#include "Index.h"

DECLARE_bool(help);
DEFINE_bool(c_plus_plus, false, "Should we interpret the query as C++ code?");
DEFINE_string(query, "", "Query pattern to be searched");
DEFINE_bool(print_matches, false, "Print variable matches found for the syntax");

std::string GetFileContaining(mx::Index &index, mx::RawEntityId file_id) {
  for (auto [path, id] : index.file_paths()) {
    if (id == file_id) {
      return path.generic_string();
    }
  }
  return {};
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " --query QUERY_STRING [--print_matches PRINT_MATCHES]";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);


  if (1 >= argc) {
    FLAGS_help = true;
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

  mx::Index index = InitExample();

  for (mx::WeggliQueryMatch match : index.query_fragments(query)) {
    mx::Fragment frag = mx::Fragment::containing(match);
    auto file = mx::File::containing(frag);
    auto sep = "\t";
    std::cout
        << frag.id() << sep
        << GetFileContaining(
               index, (file ? file->id().Pack() : mx::kInvalidEntityId))
        << std::endl;

    if (FLAGS_print_matches) {
      for (mx::Token tok : match) {
        std::cout << sep << tok.data();
        sep = " ";
      }
      for (std::string var : match.captured_variables()) {
        std::cout << var;
        sep = "\t";
        if (auto capture = match.captured_tokens(var)) {
          for (mx::Token tok : *capture) {
            std::cout << sep << tok.data();
            sep = " ";
          }
        }
        std::cout << "\t";
      }
      std::cout << "\n\n";
    }
    PrintUnparsedTokens(std::cout, frag.preprocessed_code());
    std::cout << "\n\n";
  }
  return EXIT_SUCCESS;
}
