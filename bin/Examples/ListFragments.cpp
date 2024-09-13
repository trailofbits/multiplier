// Copyright (c) 2022-present, Trail of Bits, Inc.
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
DECLARE_string(db);
DEFINE_uint64(file_id, 0, "ID of the file from which to print fragments.");

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db FILE] --file_id FILE_ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::Index::from_database(FLAGS_db));

  // List all fragment IDs in a specific file.
  if (FLAGS_file_id) {
    std::optional<mx::File> file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }

    for (mx::PackedFragmentId frag_id : file->fragment_ids()) {
      std::cout << frag_id << std::endl;
    }

  // List all fragment IDs.
  } else {
    for (mx::File file : index.files()) {
      for (mx::PackedFragmentId frag_id : file.fragment_ids()) {
        std::cout << frag_id << std::endl;
      }
    }
  }

  return EXIT_SUCCESS;
}
