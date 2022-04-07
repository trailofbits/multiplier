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

static void FindSwitchCases(mx::Fragment fragment) {
  for (mx::SwitchStmt sw : mx::SwitchStmt::in(fragment)) {
    std::cout << fragment.id() << std::endl;

    auto containing_func = mx::FunctionDecl::containing(sw);
    CHECK(containing_func);

    for (auto cs = sw.first_switch_case(); cs; cs = cs->next_switch_case()) {
      if (auto case_ = mx::CaseStmt::from(*cs)) {
        if (case_->rhs()) {
          continue;  // Range-based switch.
        }

        std::cout << '\t' << containing_func->name();
        auto sep = "\tcase\t";
        for (mx::Token tok : case_->lhs().token_range()) {
          std::cout << sep << tok.data();
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
    << " [--host HOST] [--port PORT] [--fragment_id ID | --file_id ID]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::from_remote(
      FLAGS_host, FLAGS_port));

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
    for (mx::Fragment fragment : mx::Fragment::in(*file)) {
      FindSwitchCases(std::move(fragment));
    }

  } else {
    for (mx::File file : mx::File::in(index)) {
      for (mx::Fragment fragment : mx::Fragment::in(file)) {
        FindSwitchCases(std::move(fragment));
      }
    }
  }

  return EXIT_SUCCESS;
}
