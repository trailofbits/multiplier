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

template <typename Derived>
struct TypeCompressingGenVisitor : vast::cg::type_visitor_with_dl< Derived > {
 public:

  // The base class is logically our "next" class in the proxy pattern.
  using Base = vast::cg::type_visitor_with_dl< Derived >;

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
  vast::mlir_type Visit(clang::QualType type) {
    return Base::Visit(TypeMapper::Compress(Base::acontext(), type));
  }

  vast::mlir_type Visit(const clang::Type *type) {
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
    : vast::cg::decl_visitor_with_attrs< Derived >
    , vast::cg::default_stmt_visitor< Derived >
    , TypeCompressingGenVisitor< Derived >
    , vast::cg::default_attr_visitor< Derived >
{
    using DeclVisitor = vast::cg::decl_visitor_with_attrs< Derived >;
    using StmtVisitor = vast::cg::default_stmt_visitor< Derived >;
    using TypeVisitor = TypeCompressingGenVisitor< Derived >;
    using AttrVisitor = vast::cg::default_attr_visitor< Derived >;

    using DeclVisitor::Visit;
    using StmtVisitor::Visit;
    using TypeVisitor::Visit;
    using AttrVisitor::Visit;
};

template< typename Derived >
using MXVisitorConfig = vast::cg::fallback_visitor<
    Derived,
    MXDefaultCodeGenVisitor,
    vast::cg::unsup_visitor,
    vast::cg::unreach_visitor
>;

static vast::cg::source_language GetSourceLanguage(
    const vast::cc::language_options &opts) {
  using ClangStd = clang::LangStandard;

  if (opts.CPlusPlus || opts.CPlusPlus11 || opts.CPlusPlus14 ||
      opts.CPlusPlus17 || opts.CPlusPlus20 || opts.CPlusPlus23 ||
      opts.CPlusPlus26) {
    return vast::cg::source_language::CXX;
  }

  if (opts.C99 || opts.C11 || opts.C17 || opts.C2x ||
      opts.LangStd == ClangStd::lang_c89) {
    return vast::cg::source_language::C;
  }

  // TODO: support remaining source languages.
  vast::vast_error() << "VAST does not yet support the given source language";
  return vast::cg::source_language::C;
}

}  // namespace

class CodeGeneratorImpl {
 public:
  bool disabled{false};

  // NOTE(pag): The first use of the VAST code generator will load in all
  //            the necessary dialects.
  mlir::DialectRegistry registry;
};

CodeGenerator::CodeGenerator(void)
    : impl(new CodeGeneratorImpl) {}

void CodeGenerator::Disable(void) {
  impl->disabled = true;
}

bool CodeGenerator::IsEnabled(void) const noexcept {
  return !impl->disabled;
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

  auto &actx = ast.UnderlyingAST();
  auto &opts = actx.getLangOpts();

  vast::mcontext_t mctx(impl->registry);
  vast::cg::codegen_context cgctx(mctx, actx, GetSourceLanguage(opts));
  MetaGenerator meta(ast, mctx, em);
  vast::cg::codegen_instance<MXVisitorConfig> codegen(cgctx, meta);
  llvm::raw_string_ostream os(ret);

  try {
    codegen.emit_data_layout();
    codegen.Visit(const_cast<clang::TranslationUnitDecl *>(
        ast.TranslationUnit().RawDecl()));
    codegen.verify_module();
    cgctx.mod->print(os, flags);

  } catch (std::exception &e) {
    LOG(ERROR) << e.what();
  }

  return ret;
}

} // namespace indexer
