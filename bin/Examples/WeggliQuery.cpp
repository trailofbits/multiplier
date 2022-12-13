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
#include <multiplier/Macro.h>
#include <multiplier/Weggli.h>
#include <fstream>
#include <sstream>

DECLARE_bool(help);
DEFINE_bool(c_plus_plus, false, "Should we interpret the query as C++ code?");
DECLARE_string(db);
DEFINE_string(query, "", "Query pattern to be searched");
DEFINE_bool(print_matches, false, "Print variable matches found for the syntax");

static void PrintUnparsedTokens(gap::generator<mx::MacroSubstitutionEntry> nodes) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      auto tok = std::get<mx::Token>(node);
      std::cout << tok.data();
    } else {
      auto sub = std::get<mx::MacroSubstitution>(node);
      PrintUnparsedTokens(sub.before());
    }
  }
}

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
    std::cerr
        << "Invalid weggli query.\n";
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_database(FLAGS_db));

  for (mx::WeggliQueryMatch match : index.query_fragments(query)) {
    mx::Fragment frag = mx::Fragment::containing(match);
    mx::File file = mx::File::containing(frag);
    auto sep = "\t";
    std::cout
        << frag.id() << sep << GetFileContaining(index, file.id())
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
    std::cerr << "TODO\n";
    return EXIT_FAILURE;
//    PrintUnparsedTokens(frag.substitutions());
    std::cout << "\n\n";
  }
  return EXIT_SUCCESS;
}
