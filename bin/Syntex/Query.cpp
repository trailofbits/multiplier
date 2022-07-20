// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <multiplier/Index.h>
#include <Syntex.h>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_string(index_dir, "", "Path to the directory where the SYNTEX index will be stored.");
DEFINE_bool(print_asts, false, "Should DOT digraphs of the ASTs be printed to CERR?");
DEFINE_string(query, "", "Use argument value as query");

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

  // Load index
  mx::Index index = mx::EntityProvider::in_memory_cache(
      mx::EntityProvider::from_remote(FLAGS_host, FLAGS_port));
  // Load grammar
  syntex::Grammar grammar(FLAGS_index_dir);

  // Parse query
  syntex::Query query(grammar, FLAGS_query);

  // Do search
  query.Execute(index);

  return EXIT_SUCCESS;
}
