// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>
#include <multiplier/Frontend/TokenTree.h>

DEFINE_uint64(fragment_id, mx::kInvalidEntityId, "ID of the fragment to print");
DEFINE_uint64(file_id, mx::kInvalidEntityId, "ID of the file to print");

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --fragment_id|--file_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  if (FLAGS_fragment_id != mx::kInvalidEntityId) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }

    mx::TokenTree tt = mx::TokenTree::create(fragment.value());
    tt.dump(std::cout);
  
  } else if (FLAGS_file_id != mx::kInvalidEntityId) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }

    mx::TokenTree tt = mx::TokenTree::create(file.value());
    tt.dump(std::cout);

  } else {
    std::cerr << "Must pass `--fragment_id` or `--file_id`." << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
