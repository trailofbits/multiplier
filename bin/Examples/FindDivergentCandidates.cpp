// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"

DEFINE_uint64(file_id, 0, "ID of the file from which to check for potential candidates of divergent representations");
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to check for potential candidates of divergent representations");
DEFINE_bool(show_locations, false, "Show the locations of candidates?");

static void FindDivergentCandidates(const mx::Fragment fragment) {
  /*
   * - int variable defined/declared outside of the for or while loop
   * - variable is incremented or decrement in the loop, or in the loop's 
   *   increment section
   * - variable is used to index into an array
   * - variable is also used elsewhere, e.g. in a comparison operator, or 
   *   outside of the loop.
   */
  return;
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--file_id ID]\n";
    
  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(FLAGS_show_locations);

  if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : mx::Fragment::in(*file)) {
      FindDivergentCandidates(std::move(fragment));
    }
  } else {
    for (mx::File file : mx::File::in(index)) {
      for (mx::Fragment fragment : mx::Fragment::in(file)) {
        FindDivergentCandidates(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}