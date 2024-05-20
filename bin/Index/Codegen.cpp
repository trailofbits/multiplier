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
#include <mlir/Bytecode/BytecodeWriter.h>
#include <mlir/IR/Builders.h>
#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/OperationSupport.h>
#include <mlir/InitAllDialects.h>
#include <mlir/IR/Verifier.h>
VAST_UNRELAX_WARNINGS

#include <exception>
#include <glog/logging.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>

#include <vast/CodeGen/CodeGenBuilder.hpp>
#include <vast/CodeGen/CodeGenDriver.hpp>
#include <vast/CodeGen/CodeGenMeta.hpp>
#include <vast/CodeGen/CodeGenOptions.hpp>
#include <vast/CodeGen/CodeGenVisitor.hpp>
#include <vast/CodeGen/DataLayout.hpp>
#include <vast/CodeGen/DefaultVisitor.hpp>
#include <vast/CodeGen/FallBackVisitor.hpp>
#include <vast/CodeGen/ScopeContext.hpp>
#include <vast/CodeGen/SymbolGenerator.hpp>
#include <vast/CodeGen/UnsupportedVisitor.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Frontend/Options.hpp>
#include <vast/Util/DataLayout.hpp>
#include <vast/Util/Common.hpp>

#include "EntityMapper.h"
#include "NameMangler.h"
#include "TypeMapper.h"
#include "Util.h"

namespace indexer {
namespace {

// Generate `mlir::Location`s for Clang decls/stmts/etc. The location isn't
// the typical `file:line:col`, but instead embeds the entity ID for the Clang
// object, so that we can then correlate VAST-produced MLIR entities saved by
// Multiplier to its database.
class MetaGenerator final : public vast::cg::meta_generator {
 private:

  // Entity mapper; The entity id gets embedded as meta data
  const EntityMapper &em;

  // MLIR context for generating the mlir location from source loc
  mlir::MLIRContext * const mctx;

  const mlir::Location unknown_location;

 public:
  virtual ~MetaGenerator(void) = default;

  MetaGenerator(mlir::MLIRContext &mctx_, const EntityMapper &em)
      : em(em),
        mctx(&mctx_),
        unknown_location(mlir::UnknownLoc::get(mctx)) {}

  mlir::Location location(const clang::Decl *data) const final {
    return Location(data);
  }

  mlir::Location location(const clang::Expr *data) const final {
    return Location(data);
  }

  mlir::Location location(const clang::Stmt *data) const final {
    return Location(data);
  }

  mlir::Location location(const clang::Attr *data) const {
    return Location(data);
  }

  mlir::Location location(const clang::Type *type) const {
    return Location(type, 0u);
  }

  mlir::Location location(const clang::QualType type) const {
    return Location(type.getTypePtrOrNull(),
                    type.getQualifiers().getAsOpaqueValue());
  }

  mlir::Location location(auto token) const {
    return {unknown_location};
  }

 private:
  template <typename T>
  inline mlir::Location Location(const T *data) const {
    auto raw_entity_id = em.EntityId(data);
    if (raw_entity_id == mx::kInvalidEntityId) {
      return unknown_location;
    }

    auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
    return mlir::FusedLoc::get({}, attr, mctx);
  }

  mlir::Location Location(const clang::Type *type, uint32_t quals) const {
    auto raw_entity_id = em.EntityIdOfType(type, quals);
    if (raw_entity_id == mx::kInvalidEntityId) {
      return unknown_location;
    }

    auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
    return mlir::FusedLoc::get({}, attr, mctx);
  }
};

// Produce mangled symbol names. We use Multiplier's name mangler, as it will
// embed translation unit IDs in certain places.
//
// TODO(pag): VAST's name mangler does some special stuff with respect to
//            `clang::CXXConstructorDecl`s. Evaluate porting that here.
class SymbolGenerator final : public vast::cg::symbol_generator {
 private:
  const NameMangler &nm;

 public:
  virtual ~SymbolGenerator(void) = default;

  inline SymbolGenerator(const NameMangler &nm_)
      : nm(nm_) {}

  std::optional<vast::cg::symbol_name> symbol(
      vast::cg::clang_global decl) final {
    const std::string &name = nm.Mangle(decl.getCanonicalDecl().getDecl());
    if (name.empty()) {
      return std::nullopt;
    }

    return name;
  }

  std::optional<vast::cg::symbol_name> symbol(
      const vast::cg::clang_decl_ref_expr *ref) {
    const std::string &name = nm.Mangle(ref->getDecl());
    if (name.empty()) {
      return std::nullopt;
    }

    return name;
  }
};

class CodeGeneratorError final : public std::exception {};

// Main code generation visitor. Manually combines the default and unsupported
// visitors in a way that is similar in spirit to VAST's fallback visitor,
// except that it injects specific error reporting in-between so that we can
// know when we're falling back to the unsupported visitor, as well as applies
// "type compression" prior to visiting types, so that the types that VAST sees
// correspond to those that Multiplier persists.
class CodeGenVisitor final : public vast::cg::visitor_base {
 private:
  const pasta::AST &ast;
  clang::ASTContext &ast_context;

  vast::cg::visitor_view self;
  vast::cg::default_visitor default_visitor;
  vast::cg::unsup_decl_visitor backup_visit_decl;
  vast::cg::unsup_stmt_visitor backup_visit_stmt;
  vast::cg::unsup_type_visitor backup_visit_type;
  vast::cg::unsup_attr_visitor backup_visit_attr;

 public:
  virtual ~CodeGenVisitor(void) = default;

  CodeGenVisitor(const pasta::AST &ast_,
                 clang::ASTContext &ast_context_,
                 vast::mcontext_t &mctx,
                 vast::cg::codegen_builder &bld,
                 vast::cg::meta_generator &mg,
                 vast::cg::symbol_generator &sg,
                 vast::cg::options_t &opts)
      : vast::cg::visitor_base(mctx, mg, sg, opts),
        ast(ast_),
        ast_context(ast_context_),
        self(*this),
        default_visitor(mctx, bld, mg, sg, self),
        backup_visit_decl(bld, self),
        backup_visit_stmt(bld, self),
        backup_visit_type(bld, self),
        backup_visit_attr(bld, self) {}

  using base = vast::cg::default_visitor;

  vast::dl::DataLayoutBlueprint dl_blueprint;

  vast::operation visit(const vast::cg::clang_decl *raw_decl,
                        vast::cg::scope_context &scope) final {
    auto lifted_decl = default_visitor.visit(raw_decl, scope);
    if (lifted_decl) {
      return lifted_decl;
    }

    lifted_decl = backup_visit_decl.visit(raw_decl, scope);

    auto decl = ast.Adopt(raw_decl);
    LOG(ERROR)
        << "Cannot codegen unsupported declaration " << decl.KindName()
        << PrefixedLocation(decl, " at or near ")
        << " on main job file " << ast.MainFile().Path().generic_string();

    if (lifted_decl) {
      return lifted_decl;
    }

    throw CodeGeneratorError();
  }

  vast::operation visit(const vast::cg::clang_stmt *raw_stmt,
                        vast::cg::scope_context &scope) final {
    auto lifted_stmt = default_visitor.visit(raw_stmt, scope);
    if (lifted_stmt) {
      return lifted_stmt;
    }

    lifted_stmt = backup_visit_stmt.visit(raw_stmt, scope);

    auto stmt = ast.Adopt(raw_stmt);
    LOG(ERROR)
        << "Cannot codegen unsupported statement " << stmt.KindName()
        << PrefixedLocation(stmt, " at or near ")
        << " on main job file " << ast.MainFile().Path().generic_string();

    if (lifted_stmt) {
      return lifted_stmt;
    }

    throw CodeGeneratorError();
  }

  vast::mlir_attr visit(const vast::cg::clang_attr *raw_attr,
                        vast::cg::scope_context &scope) final {
    auto lifted_attr = default_visitor.visit(raw_attr, scope);
    if (lifted_attr) {
      return lifted_attr;
    }

    lifted_attr = backup_visit_attr.visit(raw_attr, scope);

    auto attr = ast.Adopt(raw_attr);
    LOG(ERROR)
        << "Cannot codegen unsupported attribute " << attr.KindName()
        << PrefixedLocation(attr, " at or near ")
        << " on main job file " << ast.MainFile().Path().generic_string();

    if (lifted_attr) {
      return lifted_attr;
    }

    throw CodeGeneratorError();
  }

  vast::operation visit_prototype(const vast::cg::clang_function *raw_decl,
                                  vast::cg::scope_context &scope) final {
    auto lifted_decl = default_visitor.visit_prototype(raw_decl, scope);
    if (lifted_decl) {
      return lifted_decl;
    }

    lifted_decl = backup_visit_decl.visit(raw_decl, scope);

    auto decl = ast.Adopt(raw_decl);
    LOG(ERROR)
        << "Cannot codegen prototype of function "
        << raw_decl->getNameAsString()
        << PrefixedLocation(decl, " at or near ")
        << " on main job file " << ast.MainFile().Path().generic_string();

    if (lifted_decl) {
      return lifted_decl;
    }

    throw CodeGeneratorError();
  }

  // Apply the `TypeMapper`s type compression, which eagerly desugars things
  // like `AutoType`, `ElaboratedType`, etc. (but isn't as aggressive when
  // the types are incomplete / dependent on template parameters), then ask
  // VAST's default type code generator to handle things.
  //
  // E.g. if there was an `AutoType` that wrapped a `PointerType`, then here
  // we'd forward the pointer type to `base`, then when `base` gets around to
  // lifting the pointer element type into an MLIR type, it will call
  // `Derived::visit`, the most derived type, and represents the "top" code
  // generator visitor, which will lead us back into here to apply compression
  // on the pointer element type.
  vast::mlir_type visit(vast::cg::clang_qual_type qtype,
                        vast::cg::scope_context &scope) final {
    auto new_qtype = TypeMapper::Compress(ast_context, qtype);
    auto lifted_type = default_visitor.visit(new_qtype, scope);
    if (lifted_type) {
      return lifted_type;
    }

    LOG(ERROR)
        << "Cannot codegen unsupported type " << new_qtype.getAsString()
        << " on main job file " << ast.MainFile().Path().generic_string();

    lifted_type = backup_visit_type.visit(new_qtype, scope);
    if (lifted_type) {
      return lifted_type;
    }

    throw CodeGeneratorError();
  }

  vast::mlir_type visit(const vast::cg::clang_type *type,
                        vast::cg::scope_context &scope) final {
    auto new_qtype = TypeMapper::Compress(ast_context, type);
    auto new_type = new_qtype.getTypePtrOrNull();
    if (new_type != type) {
      if (new_qtype.hasQualifiers()) {
        return visit(new_qtype, scope);
      }
    } else {
      assert(!new_qtype.hasQualifiers());
    }

    auto lifted_type = default_visitor.visit(new_type, scope);
    if (lifted_type) {
      dl_blueprint.try_emplace(lifted_type, new_type, ast_context);
      return lifted_type;
    }

    LOG(ERROR)
        << "Cannot codegen unsupported type " << new_qtype.getAsString()
        << " on main job file " << ast.MainFile().Path().generic_string();

    lifted_type = backup_visit_type.visit(new_qtype, scope);
    if (lifted_type) {
      return lifted_type;
    }

    throw CodeGeneratorError();
  }
};

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
    const pasta::AST &ast, const EntityMapper &em, const NameMangler &nm) {

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

  auto &ast_context = ast.UnderlyingAST();

  vast::cg::options_t options = {
      .lang = vast::cc::get_source_language(ast_context.getLangOpts()),
      .optimization_level = 0u,
      .has_strict_return = false,
      .disable_unsupported = false,
  };

  vast::mcontext_t mlir_context(impl->registry);
  mlir::registerAllDialects(mlir_context);
  vast::registerAllDialects(mlir_context);
  mlir_context.loadAllAvailableDialects();

  vast::cg::codegen_builder builder(&mlir_context);

  auto path = ast.MainFile().Path().generic_string();
  auto loc = mlir::FileLineColLoc::get(&mlir_context, path, 0, 0);
  vast::owning_module_ref mlir_module(vast::vast_module::create(loc));
  mlir_module->setSymName(path);

  builder.module = mlir_module.get();
  builder.set_insertion_point_to_start(&(mlir_module->getBodyRegion()));

  vast::cg::set_target_triple(
      mlir_module, ast_context.getTargetInfo().getTriple().str());
  vast::cg::set_source_language(mlir_module, options.lang);

  vast::cg::symbol_tables symbols;
  vast::cg::module_scope scope(symbols);

  MetaGenerator meta_generator(mlir_context, em);
  SymbolGenerator symbol_generator(nm);
  CodeGenVisitor codegen(ast, ast_context, mlir_context, builder,
                         meta_generator, symbol_generator, options);

  vast::cg::scoped_visitor_view visitor(codegen, scope);
  vast::cg::module_generator generator(builder, visitor, options);

  try {
    generator.emit(const_cast<clang::TranslationUnitDecl *>(
        ast.TranslationUnit().RawDecl()));
    generator.finalize();
    vast::cg::emit_data_layout(mlir_context, mlir_module, codegen.dl_blueprint);

  } catch (CodeGeneratorError &) {
    ret.clear();
  }

  if (mlir::verify(mlir_module.get()).succeeded()) {
    LOG(ERROR)
        << "Could not verify module on main job file " << path;
    return ret;
  }

  llvm::raw_string_ostream os(ret);
  mlir::BytecodeWriterConfig config("MX");
  if (!mlir::writeBytecodeToFile(mlir_module.get(), os, config).succeeded()) {
    LOG(ERROR)
        << "Could not serialize module to bytecode on main job file " << path;
    ret.clear();
  }

  return ret;
}

} // namespace indexer
