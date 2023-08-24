// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Codegen.h"

#define VAST_ENABLE_EXCEPTIONS
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
#include <vast/CodeGen/CodeGenContext.hpp>
#include <vast/CodeGen/CodeGenVisitor.hpp>
#include <vast/CodeGen/CodeGen.hpp>
#include <vast/Dialect/Dialects.hpp>

#include "CodegenMetaGenerator.h"
#include "Context.h"
#include "EntityMapper.h"
#include "PendingFragment.h"
#include "Util.h"

namespace indexer {

using MXCodeGenContext = vast::cg::CodeGenContext;

using MXCodeGenVisitor = vast::cg::CodeGenVisitor<
    vast::cg::CodeGenContext, vast::cg::DefaultVisitorConfig, MetaGenerator
    >;

using MXCodeGenerator = vast::cg::CodeGenBase<MXCodeGenVisitor, MXCodeGenContext>;

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

std::string CodeGenerator::GenerateSourceIR(
    const pasta::AST &ast, const EntityMapper &em) {

  std::string ret;
  if (impl->disabled) {
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
  MXCodeGenContext cgctx(context, ast.UnderlyingAST());
  MXCodeGenerator codegen(cgctx, meta);
  llvm::raw_string_ostream os(ret);

  try {
    auto mod = codegen.emit_module(
        const_cast<clang::TranslationUnitDecl *>(
            ast.TranslationUnit().RawDecl()));
    mod->print(os, flags);

  } catch (std::exception &e) {
    LOG(ERROR) << e.what();
  }

  return ret;
}

} // namespace indexer
