// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Codegen.h"

#include <vast/Util/Warnings.hpp>

VAST_RELAX_WARNINGS
#include <clang/AST/ASTContext.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/raw_ostream.h>
#include <mlir/IR/Builders.h>
#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/InitAllDialects.h>
#include <mlir/IR/OperationSupport.h>
VAST_UNRELAX_WARNINGS

#include <glog/logging.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>

#include <vast/Util/Common.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenVisitor.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGen.hpp>

#include "CodegenMetaGenerator.h"
#include "CodegenVisitor.h"
#include "Context.h"
#include "EntityMapper.h"
#include "PendingFragment.h"
#include "Util.h"

namespace indexer {

template<typename Derived>
using VisitorConfig =  vast::cg::CodeGenFallBackVisitorMixin<
    Derived, vast::cg::DefaultCodeGenVisitorMixin, FallBackVisitor >;

using CodeGenVisitor = vast::cg::CodeGenVisitor<VisitorConfig, MetaGenerator>;

class CodeGeneratorImpl {
 public:
  bool disabled{false};

  mlir::DialectRegistry registry;

  CodeGeneratorImpl(void) {
    registry.insert<vast::hl::HighLevelDialect,
                    vast::meta::MetaDialect,
                    vast::core::CoreDialect>();
  }
};

CodeGenerator::CodeGenerator(void)
    : impl(new CodeGeneratorImpl) {}

void CodeGenerator::Disable(void) {
  impl->disabled = true;
}

CodeGenerator::~CodeGenerator(void) {}

std::string CodeGenerator::GenerateSourceIRFromTLDs(
    const pasta::AST &ast, const EntityMapper &em, const PendingFragment &pf) {

  std::string ret;
  if (impl->disabled || pf.decls_to_serialize.empty()) {
    return ret;
  }

  auto flags = mlir::OpPrintingFlags();

  // Set the flag to enable printing of debug information. The prettyForm
  // flag passed to the function is set to false to avoid printing them in
  // `pretty` form. This is because the IR generated in pretty form is not
  // parsable.
  flags.enableDebugInfo(true, false);

  mlir::MLIRContext context(impl->registry);

  MetaGenerator meta(ast, &context, em);
  vast::cg::CodeGenBase<CodeGenVisitor> codegen(&context, meta);

  try {
    for (const pasta::Decl &decl : pf.top_level_decls) {
      codegen.append_to_module(const_cast<clang::Decl *>(decl.RawDecl()));
    }
  } catch (std::exception &e) {
    LOG(ERROR) << e.what();
    return ret;
  }

  auto mod = codegen.freeze();
  llvm::raw_string_ostream os(ret);
  mod->print(os, flags);

  return ret;
}

} // namespace indexer
