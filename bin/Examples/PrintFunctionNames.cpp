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
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print function names");
DEFINE_uint64(file_id, 0, "ID of the file from which to print function names");
DEFINE_bool(unparsed, false, "Show original source code?");

static void PrintFunctionNames(mx::Fragment fragment) {
  for (mx::Decl decl : fragment.declarations()) {
    if (auto func = mx::FunctionDecl::from(decl)) {
      std::cout << fragment.id() << '\t' << func->name() << '\n';
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--fragment_id ID | --file_id ID]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::EntityProvider::Ptr api = mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port);

  if (FLAGS_fragment_id) {
    mx::Fragment fragment = api->fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    PrintFunctionNames(std::move(fragment));

  } else if (FLAGS_file_id) {
    mx::File file = api->file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : file.fragments()) {
      if (fragment) {
        PrintFunctionNames(std::move(fragment));
      }
    }

  } else {
    std::cerr << "One of --fragment_id or --file_id is required" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
