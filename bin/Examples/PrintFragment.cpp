// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/API.h>
#include <sstream>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");
DEFINE_bool(unparsed, false, "Show original source code?");

static void PrintUnparsedTokens(mx::TokenSubstitutionList nodes) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      auto tok = std::get<mx::Token>(node);
      std::cout << tok.data();
    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      PrintUnparsedTokens(sub.before());
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));
  auto fragment = index.fragment(FLAGS_fragment_id);
  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  // Print our the tokens of this fragment as they appear in the file.
  if (FLAGS_unparsed) {
    PrintUnparsedTokens(fragment->substitutions());

  // Print out the tokens of this fragment that were actually parsed. These
  // are post-macro expansion tokens, and generally don't include whitespace
  // or comments. There can be empty tokens, however.
  } else {
    for (mx::Token token : mx::Token::in(*fragment)) {
      std::cout << ' ' << token.data();
    }
  }

  return EXIT_SUCCESS;
}
