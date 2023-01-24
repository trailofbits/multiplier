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
#include <pasta/AST/Decl.h>
#include <map>

#include <vast/Util/Common.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenVisitor.hpp>
#include "CodegenVisitor.hpp"

#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGen.hpp>

#include "CodegenMetaGenerator.h"

#endif  // MX_ENABLE_SOURCEIR

#include "Context.h"
#include "EntityMapper.h"

namespace indexer {

#ifdef MX_ENABLE_SOURCEIR
class CodeGeneratorVisitor {
 public:

  template<typename Derived>
  using VisitorConfig =  vast::hl::CodeGenFallBackVisitorMixin<
      Derived, vast::hl::DefaultCodeGenVisitorMixin, FallBackVisitor >;

  using Visitor = vast::hl::CodeGenVisitor<VisitorConfig, MetaGenerator>;

  CodeGeneratorVisitor(const pasta::AST &ast, mlir::MLIRContext *mctx, const EntityMapper &em)
    : meta(ast, mctx, em), codegen(mctx, meta) {}

  void append_to_module(clang::Decl *decl) {
    codegen.append_to_module(decl);
  }

  vast::OwningModuleRef freeze() {
    return codegen.freeze();
  }

  MetaGenerator meta;
  vast::hl::CodeGenBase<Visitor> codegen;
};

#endif


class CodeGeneratorImpl {
 public:
  bool disabled{false};

#ifdef MX_ENABLE_SOURCEIR
  mlir::DialectRegistry registry;

  CodeGeneratorImpl(void) {
    registry.insert<vast::hl::HighLevelDialect,
                    vast::meta::MetaDialect>();
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
  flags.enableDebugInfo(true);

  mlir::MLIRContext context(impl->registry);
  CodeGeneratorVisitor codegen(ast, &context, em);

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
