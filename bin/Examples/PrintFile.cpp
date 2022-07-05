// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Index.h>
#include <sstream>

DECLARE_bool(help);
DECLARE_string(host);
DECLARE_string(port);
DEFINE_uint64(file_id, 0, "ID of the file to print");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --file_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));
  std::optional<mx::File> file = index.file(FLAGS_file_id);
  if (!file) {
    std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << file->data();

  return EXIT_SUCCESS;
}
