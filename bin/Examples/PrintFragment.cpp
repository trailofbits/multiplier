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
DEFINE_uint64(id, 0, "ID of the fragment to print");
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
    << " [--host HOST] [--port PORT]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::EntityProvider::Ptr api = mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port);
  mx::Fragment fragment = api->fragment(FLAGS_id);
  if (!fragment) {
    std::cerr << "Invalid file id " << FLAGS_id << std::endl;
    return EXIT_FAILURE;
  }

  if (FLAGS_unparsed) {
    PrintUnparsedTokens(fragment.unparsed_tokens());

  } else {
    for (mx::Token token : fragment.tokens()) {
      std::cout << token.data();
    }
  }

  return EXIT_SUCCESS;
}
