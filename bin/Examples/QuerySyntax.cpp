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
#include <multiplier/API.h>
#include <fstream>
#include <sstream>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_string(query, "", "Query pattern to be searched");


extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT]\n"
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
        << "Must specify query string to be searched for.";
    return EXIT_FAILURE;
  }

  auto query_string = FLAGS_query;

  mx::EntityProvider::Ptr api = mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port);

  auto results = api->query_syntax(FLAGS_query);

  for (auto iter = results.begin(); iter != results.end(); iter++) {
    mx::Fragment fragment = *iter;
    if (!fragment) {
      std::cerr << "Invalid fragment \n";
      continue;
    }

    for (mx::Token token : fragment.tokens()) {
      std::cout << ' ' << token.data();
    }

  }

  return EXIT_SUCCESS;
}
