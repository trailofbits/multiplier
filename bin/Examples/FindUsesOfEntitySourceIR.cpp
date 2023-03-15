// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SourceIR.h>
#include <multiplier/AST.h>
#include <multiplier/Analysis/IRAnalysis.h>
#include <gap/core/generator.hpp>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/Parser/Parser.h>

#include "Index.h"

DECLARE_bool(help);
DECLARE_string(db);
DEFINE_uint64(fragment_id, 0, "ID of the fragment from which to print variable names");
DEFINE_uint64(entity_id, 0, "ID of the fragment from which to print variable names");
DEFINE_string(entity_name, "", "Name of the entity to be matched.");

// Go and find the entity that will be the source of dependency analysis.
static std::optional<mx::VariantEntity> FindEntity(const mx::Index &index) {
  if (!FLAGS_entity_name.empty()) {
    for (mx::NamedEntity ne : index.query_entities(FLAGS_entity_name)) {
      if (std::holds_alternative<mx::NamedDecl>(ne)) {
        mx::NamedDecl nd = std::move(std::get<mx::NamedDecl>(ne));
        if (nd.name() == FLAGS_entity_name) {
          return nd;
        }
      }
    }
  } else if (FLAGS_entity_id) {
    return index.entity(FLAGS_entity_id);
  }
  return std::nullopt;
}

void PrintEdge(const mx::SourceIR &ir, const mx::DependencyTrackingEdge &edge) {
  std::string op_string;
  llvm::raw_string_ostream os(op_string);
  auto op = edge.as_operation();
  const_cast<mlir::Operation*>(op)->print(os);
  std::cout << op_string << std::endl;
  (void)ir;
}

void PrintNext(const mx::SourceIR &ir,
               mx::DependencyAnalysis &tracker,
               mx::DependencyTrackingResult res,
               int depth) {
  for (auto i = 0; i < depth; ++i) {
    std::cout << "  ";
  }
  if (std::holds_alternative<mx::DependencyTrackingStep>(res)) {
    const auto &step = std::get<mx::DependencyTrackingStep>(res);
    PrintEdge(ir, step);

    for (mx::DependencyTrackingResult next_res : tracker.dependents(step)) {
      PrintNext(ir, tracker, std::move(next_res), depth + 1);
    }

  } else if (std::holds_alternative<mx::DependencyTrackingCondition>(res)) {
    const auto &cond = std::get<mx::DependencyTrackingCondition>(res);
    PrintEdge(ir, cond);
    std::cout << " <condition>\n";

  } else if (std::holds_alternative<mx::DependencyTrackingSink>(res)) {
    std::cout << std::get<mx::DependencyTrackingSink>(res).message() << '\n';
  }
}

void PrintSource(const mx::SourceIR &ir, mx::VariantEntity entity) {
  std::string op_string;
  llvm::raw_string_ostream os(op_string);
  if (std::holds_alternative<mx::Decl>(entity)) {
    mx::Decl decl = std::get<mx::Decl>(entity);
    mx::OperationRange range = ir.for_declaration(decl);
    for (auto iter = range.begin(); iter != range.end(); iter++) {
      auto op = *iter;
      const_cast<mlir::Operation*>(op.get())->print(os);
    }
  } else if (std::holds_alternative<mx::Stmt>(entity)) {
    mx::Stmt stmt = std::get<mx::Stmt>(entity);
    mx::OperationRange range = ir.for_statement(stmt);
    for (auto iter = range.begin(); iter != range.end(); iter++) {
      auto op = *iter;
      const_cast<mlir::Operation*>(op.get())->print(os);
    }
  }

  if (!op_string.empty()) {
    std::cout << "Taint source entity>" << std::endl
              << op_string << std::endl;
    std::cout << " <source>\n";
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

  mx::Index index = InitExample();
  mx::DependencyAnalysis tracker(index);
  int depth = 0;

  auto fragment = index.fragment(FLAGS_fragment_id);
  if (!fragment) {
    std::cerr << "Could not find fragment by id " << FLAGS_fragment_id << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_sourceir = fragment->ir();
  if (!maybe_sourceir) {
    std::cerr << "Failed to get SourceIR for the fragment" << std::endl;
    return EXIT_FAILURE;
  }

  auto sourceir = maybe_sourceir.value();
  sourceir.print(std::cout);

  std::optional<mx::VariantEntity> mabe_entity = FindEntity(index);
  if (!mabe_entity) {
    std::cerr << "Could not find entity by id or name.\n";
    return EXIT_FAILURE;
  }

  auto entity = mabe_entity.value();
  PrintSource(sourceir, entity);
  auto range = sourceir.for_entity(entity);
  for (auto iter = range.begin(); iter != range.end(); iter++) {
    auto ir_operation = *iter;
    for (mx::DependencyTrackingResult res : tracker.dependents(ir_operation.get())) {
      PrintNext(sourceir, tracker, std::move(res), depth + 1);
    }
  }

  return EXIT_SUCCESS;
}

