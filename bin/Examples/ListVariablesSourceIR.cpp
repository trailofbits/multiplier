// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SourceIR.h>
#include <multiplier/AST.h>

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>

#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/Parser/Parser.h>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print variable names");
DEFINE_bool(show_locations, false, "Show the file locations of the variable?");


static void PrintVariableNames(mx::Index index, const mx::SourceIR &ir) {
  for (mx::FunctionDecl func : mx::FunctionDecl::in(index)) {
    auto fragment = mx::Fragment::containing(func);
    if (fragment.id().Pack() == FLAGS_fragment_id) {
      for (const mx::Decl &var : func.declarations_in_context()) {
        auto var_id =  var.id().Pack();
        auto var_op = ir.for_declaration(var);
        for (auto iter = var_op.begin(); iter != var_op.end(); iter++) {
          auto op = *iter;
          (const_cast<mlir::Operation*>(op.get()))->dump();
        }

        std::cout
            << "\t\t" << var_id << '\t' << mx::EnumeratorName(var.kind());

        if (auto named_decl = mx::NamedDecl::from(var)) {
          std::cout << '\t' << named_decl->name();
        }
      }
    }
  }
}


extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n"
    << " [--fragment_id FRAGMENT_ID]\n"
    << " [--show_locations SHOW_LOCATIONS]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index idx(mx::EntityProvider::from_database(FLAGS_db));
  auto fragment = idx.fragment(FLAGS_fragment_id);
  if (!fragment) {
    std::cerr << "Invalid fragment id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  if (auto maybe_sourceir = fragment->ir(); maybe_sourceir) {
    auto sourceir = maybe_sourceir.value();
    sourceir.print(std::cout);
    PrintVariableNames(idx, sourceir);
  }

  return EXIT_SUCCESS;
}


