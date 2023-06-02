// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Codegen.h"

#ifdef MX_ENABLE_SOURCEIR

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

#include <vast/Util/Common.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenVisitor.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGen.hpp>

#include "CodegenMetaGenerator.h"
#include "CodegenVisitor.h"

#endif  // MX_ENABLE_SOURCEIR

#include <pasta/AST/Decl.h>

#include "Context.h"
#include "EntityMapper.h"

namespace indexer {

#ifdef MX_ENABLE_SOURCEIR

template<typename Derived>
using VisitorConfig =  vast::cg::CodeGenFallBackVisitorMixin<
    Derived, vast::cg::DefaultCodeGenVisitorMixin, FallBackVisitor >;

using CodeGenVisitor = vast::cg::CodeGenVisitor<VisitorConfig, MetaGenerator>;

#endif

class CodeGeneratorImpl {
 public:
  bool disabled{false};

#ifdef MX_ENABLE_SOURCEIR
  mlir::DialectRegistry registry;

  CodeGeneratorImpl(void) {
    registry.insert<vast::hl::HighLevelDialect,
                    vast::meta::MetaDialect,
                    vast::core::CoreDialect>();
  }
#endif  // MX_ENABLE_SOURCEIR
};

CodeGenerator::CodeGenerator(void)
    : impl(new CodeGeneratorImpl) {}

void CodeGenerator::Disable(void) {
  impl->disabled = true;
}

CodeGenerator::~CodeGenerator(void) {}

std::string CodeGenerator::GenerateSourceIRFromTLDs(
    const pasta::AST &ast,
    mx::RawEntityId fragment_id,
    const EntityMapper &em,
    const std::vector<pasta::Decl> &decls,
    unsigned num_decls) {

  (void) ast;
  (void) fragment_id;
  (void) em;
  (void) decls;
  (void) num_decls;

  std::string ret;
#ifdef MX_ENABLE_SOURCEIR
  if (impl->disabled || decls.empty()) {
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
    for (const pasta::Decl &decl : decls) {
      codegen.append_to_module(const_cast<clang::Decl *>(decl.RawDecl()));
    }
  } catch (std::exception &e) {
    LOG(ERROR) << e.what();
    return ret;
  }

  auto mod = codegen.freeze();
  llvm::raw_string_ostream os(ret);
  mod->print(os, flags);
#endif

  return ret;
}

} // namespace indexer
