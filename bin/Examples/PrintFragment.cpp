// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");
DEFINE_bool(unparsed, false, "Show original source code?");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  auto fragment = index.fragment(FLAGS_fragment_id);
  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  // Print our the tokens of this fragment as they appear in the file.
  if (FLAGS_unparsed) {
    PrintUnparsedTokens(std::cout, fragment->preprocessed_code());

  // Print out the tokens of this fragment that were actually parsed. These
  // are post-macro expansion tokens, and generally don't include whitespace
  // or comments. There can be empty tokens, however.
  } else {

    std::cout << "Parsed data from tokens:";

    for (mx::Token token : fragment->parsed_tokens()) {
      std::cout
          << '\n' << token.id()
          << '\t' << token.related_entity_id()
          << '\t' << mx::EnumeratorName(token.kind())
          << '\t' << mx::EnumeratorName(token.category())
          << '\t' << token.data();
    }

    std::cout << "\n\n\nParsed data from token range:\n";
    std::cout << fragment->parsed_tokens().data();

    std::cout << "\n\nFile data from tokens:\n";
    for (mx::Token token : fragment->file_tokens()) {
      std::cout << token.data();
    }

    std::cout << "\n\nFile data from file token range:\n";
    std::cout << fragment->file_tokens().data();

    std::cout << '\n';
  }

  return EXIT_SUCCESS;
}
