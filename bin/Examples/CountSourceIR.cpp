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
#include <multiplier/Compilation.h>
#include <multiplier/IR/MLIR/Builtin/ModuleOp.h>

DECLARE_bool(help);
DECLARE_string(db);

int main(int argc, char *argv[]) {
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

  uint64_t num_tus = 0u;
  uint64_t num_mlir = 0u;
  uint64_t num_files = 0u;
  uint64_t num_frags = 0u;
  uint64_t num_errors = 0u;
  uint64_t num_macros = 0u;

  for (mx::Compilation tu : index.compilations()) {
    ++num_tus;
    if (std::optional<mx::ir::builtin::ModuleOp> mlir = tu.ir()) {
      ++num_mlir;
    } else {
      ++num_errors;
    }
  }

  for (mx::File file: index.files()) {
    ++num_files;

    for (mx::Fragment frag : file.fragments()) {
      ++num_frags;

      auto has_tld = false;
      for (auto tld : frag.top_level_declarations()) {
        has_tld = true;
        break;
      }

      if (!has_tld) {
        ++num_macros;
      }
    }
  }

  std::cout
      << "File count: " << num_files
      << "\nCompilation unit count: " << num_tus
      << "\nCompilation units with MLIR: " << num_mlir
      << "\nCompilation units without MLIR: " << num_errors
      << "\nFragment count: " << num_frags
      << "\nMacro fragments: " << num_macros
      << "\n";

  return EXIT_SUCCESS;
}
