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
#include "TypeMapper.h"
#include "Util.h"

namespace indexer {
namespace {

using MXCodeGenContext = vast::cg::CodeGenContext;

template <typename Derived>
struct TypeCompressingGenVisitor
    : vast::cg::CodeGenTypeVisitorWithDataLayout< Derived > {
 public:

  // The base class is logically our "next" class in the proxy pattern.
  using Base = vast::cg::CodeGenTypeVisitorWithDataLayout< Derived >;

  // Apply the `TypeMapper`s type compression, which eagerly desugars things
  // like `AutoType`, `ElaboratedType`, etc. (but isn't as aggressive when
  // the types are incomplete / dependent on template parameters), then ask
  // VAST's default type code generator to handle things.
  //
  // E.g. if there was an `AutoType` that wrapped a `PointerType`, then here
  // we'd forward the pointer type to `Base`, then when `Base` gets around to
  // lifting the pointer element type into an MLIR type, it will call
  // `Derived::visit`, the most derived type, and represents the "top" code
  // generator visitor, which will lead us back into here to apply compression
  // on the pointer element type.
  vast::cg::mlir_type Visit(clang::QualType type) {
    return Base::Visit(TypeMapper::Compress(Base::acontext(), type));
  }

  vast::cg::mlir_type Visit(const clang::Type *type) {
    auto new_qtype = TypeMapper::Compress(Base::acontext(), type);
    auto new_type = new_qtype.getTypePtrOrNull();
    if (new_type != type) {
      if (new_qtype.hasQualifiers()) {
        return Base::Visit(new_qtype);
      }
    } else {
      assert(!new_qtype.hasQualifiers());
    }

    return Base::Visit(new_type);
  }
};

template< typename Derived >
struct MXDefaultCodeGenVisitor
    : vast::cg::CodeGenDeclVisitor< Derived >
    , vast::cg::CodeGenStmtVisitor< Derived >
    , TypeCompressingGenVisitor< Derived >
{
    using DeclVisitor = vast::cg::CodeGenDeclVisitor< Derived >;
    using StmtVisitor = vast::cg::CodeGenStmtVisitor< Derived >;
    using TypeVisitor = TypeCompressingGenVisitor< Derived >;

    using DeclVisitor::Visit;
    using StmtVisitor::Visit;
    using TypeVisitor::Visit;
};

template< typename Derived >
using MXVisitorConfig = vast::cg::FallBackVisitor< Derived,
    MXDefaultCodeGenVisitor,
    vast::cg::UnsupportedVisitor,
    vast::cg::UnreachableVisitor
>;

using MXCodeGenVisitor = vast::cg::CodeGenVisitor<
    vast::cg::CodeGenContext, MXVisitorConfig, MetaGenerator
    >;

using MXCodeGenerator = vast::cg::CodeGenBase<MXCodeGenVisitor, MXCodeGenContext>;

}  // namespace

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

  MetaGenerator meta(ast, context, em);
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
