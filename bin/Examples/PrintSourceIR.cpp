// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <sstream>

#include <multiplier/Index.h>
#include <multiplier/Fragment.h>
#include <multiplier/IR/MLIR/Builtin/ModuleOp.h>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::Index::from_database(FLAGS_db));
  std::optional<mx::Fragment> fragment = index.fragment(FLAGS_fragment_id);
  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  if (std::optional<mx::ir::builtin::ModuleOp> mlir = fragment->ir()) {
    std::cout << mlir->kind_name();
  }

  return EXIT_SUCCESS;
}
