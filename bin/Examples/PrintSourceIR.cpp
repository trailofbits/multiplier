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
#include <multiplier/IR/Block.h>
#include <multiplier/IR/MLIR/Builtin/ModuleOp.h>
#include <multiplier/IR/Region.h>

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_uint64(fragment_id, 0, "ID of the fragment to print");

static void DumpOperand(const mx::ir::Operand &op, std::ostream &os) {
  mx::ir::Value val = op.value();
  if (auto arg = mx::ir::Argument::from(val)) {
    os << '%' << arg->index();

  } else if (auto res = mx::ir::Result::from(val)) {

  } else {
    os << "??UNKNOWN_VALUE??";
  }
}

static void DumpBlock(const mx::ir::Block &b,
                       std::ostream &os, const std::string &indent) {

}

static void DumpRegion(const mx::ir::Region &r,
                       std::ostream &os, const std::string &indent) {
  for (mx::ir::Block block : r.blocks()) {
    DumpBlock(block, os, indent);
  }
}

static void DumpOperation(const mx::ir::Operation &op,
                          std::ostream &os, const std::string &indent) {
  os << indent;

  switch (op.num_results()) {
    case 0:
      break;
    case 1:
      os << " = ";
      break;
    default:
      os << "[";
      os << "] = ";
  }

  if (op.num_results()) {
    os << " = ";
  }

  os << op.kind_name();
  auto sep = "(";
  for (mx::ir::Operand operand : op.operands()) {
    os << sep;
    DumpOperand(operand, os);
    sep = ", ";
  }
  if (sep[0] == ',') {
    os << ")";
  }

  std::string next_indent = indent + "  ";

  if (op.num_regions()) {
    os << ":\n";
    auto is_first = true;
    for (mx::ir::Region reg : op.regions()) {
      if (!is_first) {
        os << next_indent << "--\n";
      }
      DumpRegion(reg, os, next_indent);
      is_first = false;
    }
  }
  os << "\n";
}

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
    DumpOperation(mlir.value(), std::cout, "");
    std::cout << mlir->kind_name();
  }

  return EXIT_SUCCESS;
}
