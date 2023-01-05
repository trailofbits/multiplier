// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print function names");
DEFINE_uint64(file_id, 0, "ID of the file from which to print function names");

static void FindSwitchCases(mx::Fragment fragment) {
  for (mx::SwitchStmt sw : mx::SwitchStmt::in(fragment)) {
    std::cout << fragment.id() << std::endl;

    auto containing_funcs = mx::FunctionDecl::containing(sw);
    auto containing_func = containing_funcs.begin();
    CHECK(containing_func != containing_funcs.end());

    for (auto cs = sw.first_switch_case(); cs; cs = cs->next_switch_case()) {
      if (auto case_ = mx::CaseStmt::from(*cs)) {
        if (case_->rhs()) {
          continue;  // Range-based switch.
        }

        std::cout << '\t' << containing_func->name();
        auto sep = "\tcase\t";
        for (mx::Token tok : case_->lhs().tokens()) {
          PrintToken(std::cout, std::move(tok));
          sep = " ";
        }
        std::cout << std::endl;
      }
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE] [--fragment_id ID | --file_id ID]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  if (FLAGS_fragment_id) {
    auto fragment = index.fragment(FLAGS_fragment_id);
    if (!fragment) {
      std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
      return EXIT_FAILURE;
    }
    FindSwitchCases(std::move(*fragment));

  } else if (FLAGS_file_id) {
    auto file = index.file(FLAGS_file_id);
    if (!file) {
      std::cerr << "Invalid file id " << FLAGS_file_id << std::endl;
      return EXIT_FAILURE;
    }
    for (mx::Fragment fragment : file->fragments()) {
      FindSwitchCases(std::move(fragment));
    }

  } else {
    for (mx::File file : index.files()) {
      for (mx::Fragment fragment : file.fragments()) {
        FindSwitchCases(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
