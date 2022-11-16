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
VAST_UNRELAX_WARNINGS

#include <glog/logging.h>

#include <map>
#include <pasta/AST/Decl.h>

#include <vast/Util/Common.hpp>
#include <vast/Translation/Context.hpp>
#include <vast/Translation/HighLevelVisitor.hpp>

#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGen.hpp>
#endif  // MX_ENABLE_SOURCEIR

#include "Context.h"
#include "EntityMapper.h"

namespace indexer {

class CodeGeneratorImpl {
 public:
  bool disabled{false};

#ifdef MX_ENABLE_SOURCEIR
  mlir::DialectRegistry registry;

  CodeGeneratorImpl(void) {
    registry.insert<vast::hl::HighLevelDialect,
                    mlir::StandardOpsDialect,
                    mlir::DLTIDialect>();
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
    mx::RawEntityId fragment_id,
    const EntityMapper &em,
    const std::vector<pasta::Decl> &decls) {

  std::string ret;

#ifdef MX_ENABLE_SOURCEIR
  if (impl->disabled || decls.empty()) {
    return ret;
  }

  mlir::MLIRContext context(impl->registry);
  mlir::Builder builder(&context);

  context.loadDialect<vast::hl::HighLevelDialect>();
  context.loadDialect<mlir::StandardOpsDialect>();
  context.loadDialect<mlir::DLTIDialect>();

  clang::Decl *first_decl = const_cast<clang::Decl *>(decls[0].RawDecl());
  clang::ASTContext &ast_context = first_decl->getASTContext();

  mx::FragmentId id(fragment_id);
  auto loc = mlir::OpaqueLoc::get(
      reinterpret_cast<void *>(mx::EntityId(id).Pack()), &context);
  vast::OwningModuleRef mod = {mlir::ModuleOp::create(loc)};
  vast::hl::TranslationContext tctx(context, ast_context, mod);

  llvm::ScopedHashTableScope type_def_scope(tctx.type_defs);
  llvm::ScopedHashTableScope type_dec_scope(tctx.type_decls);
  llvm::ScopedHashTableScope enum_dec_scope(tctx.enum_decls);
  llvm::ScopedHashTableScope enum_constant_scope(tctx.enum_constants);
  llvm::ScopedHashTableScope func_scope(tctx.functions);
  llvm::ScopedHashTableScope glob_scope(tctx.vars);

  try {
    vast::hl::CodeGenVisitor visitor(tctx);
    for (const pasta::Decl &decl : decls) {
      vast::ValueOrStmt hl_decl =
          visitor.Visit(const_cast<clang::Decl *>(decl.RawDecl()));
      if (std::holds_alternative<vast::Value>(hl_decl)) {
        vast::Value val = std::get<vast::Value>(hl_decl);
        if (mx::RawEntityId id = em.EntityId(decl)) {
          val.setLoc(mlir::OpaqueLoc::get(reinterpret_cast<void *>(id), &context));
        }
      }
    }
  } catch (std::exception &e) {
    LOG(ERROR) << e.what();
    return ret;
  }

  llvm::raw_string_ostream os(ret);
  mod->print(os);
#endif

  return ret;
}

} // namespace indexer
