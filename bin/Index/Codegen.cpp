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
#include <mlir/IR/Verifier.h>
#include <mlir/InitAllDialects.h>
VAST_UNRELAX_WARNINGS

#include <exception>
#include <glog/logging.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>

#include <vast/CodeGen/AttrVisitorProxy.hpp>
#include <vast/CodeGen/CodeGenBuilder.hpp>
#include <vast/CodeGen/CodeGenDriver.hpp>
#include <vast/CodeGen/CodeGenMetaGenerator.hpp>
#include <vast/CodeGen/CodeGenVisitorList.hpp>
#include <vast/CodeGen/DefaultVisitor.hpp>
#include <vast/CodeGen/UnsupportedVisitor.hpp>
#include <vast/CodeGen/DataLayout.hpp>
#include <vast/CodeGen/DefaultVisitor.hpp>
#include <vast/CodeGen/FallthroughVisitor.hpp>
#include <vast/CodeGen/ScopeContext.hpp>
#include <vast/CodeGen/SymbolGenerator.hpp>
#include <vast/CodeGen/TypeCachingProxy.hpp>
#include <vast/CodeGen/UnsupportedVisitor.hpp>

#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/Meta/MetaAttributes.hpp>

#include <vast/Frontend/Options.hpp>

#include <vast/Util/Common.hpp>
#include <vast/Util/DataLayout.hpp>

#include "EntityMapper.h"
#include "NameMangler.h"
#include "TypeMapper.h"
#include "Util.h"

namespace indexer {
namespace {

class CodeGeneratorError final : public std::runtime_error {
public:
  explicit CodeGeneratorError(const std::string &message)
      : std::runtime_error(message) {}

  CodeGeneratorError() : std::runtime_error("Code generation error occurred") {}
};

// Generate `mlir::Location`s for Clang decls/stmts/etc. The location isn't
// the typical `file:line:col`, but instead embeds the entity ID for the Clang
// object, so that we can then correlate VAST-produced MLIR entities saved
// by Multiplier to its database.
class MetaGenerator final : public vast::cg::meta_generator {
  // Entity mapper; The entity id gets embedded as metadata
  const EntityMapper &em;

  // MLIR context for generating the MLIR location from source location
  mlir::MLIRContext *const mctx;

public:

  MetaGenerator(mlir::MLIRContext &mctx, const EntityMapper &em)
      : em(em), mctx(&mctx) {}

  mlir::Location location(const clang::Decl *data) const {
    return location_impl(data);
  }

  mlir::Location location(const clang::Expr *data) const {
    return location_impl(data);
  }

  mlir::Location location(const clang::Stmt *data) const {
    return location_impl(data);
  }

private:
  template <typename T> mlir::Location location_impl(const T *data) const {
    auto raw_entity_id = em.EntityId(data);
    if (raw_entity_id == mx::kInvalidEntityId) {
      return mlir::UnknownLoc::get(mctx);
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
  const NameMangler &nm;
public:

  using symbol_name = vast::cg::symbol_name;

  explicit SymbolGenerator(const NameMangler &nm) : nm(nm) {}

  std::optional<symbol_name> symbol(vast::cg::clang_global decl) {
    const std::string &name = nm.Mangle(decl.getCanonicalDecl().getDecl());
    if (name.empty()) {
      return std::nullopt;
    }

    return name;
  }

  std::optional<symbol_name> symbol(const vast::cg::clang_decl_ref_expr *ref) {
    const std::string &name = nm.Mangle(ref->getDecl());
    if (name.empty()) {
      return std::nullopt;
    }

    return name;
  }
};


class MXErrorReportVisitorProxy : public vast::cg::fallthrough_list_node {
  using base = vast::cg::fallthrough_visitor;

  template <typename EntityType, typename NameFunc>
  auto visit_impl(EntityType entity, vast::cg::scope_context &scope, const std::string &type, NameFunc name) {
    auto unsup = next->visit(entity, scope);

    if constexpr (std::is_same_v<EntityType, const vast::cg::clang_type*>
              ||  std::is_same_v<EntityType, vast::cg::clang_qual_type>
    ) {
      log_type(type, name(ast, entity));
    } else {
      log(type, name(ast, entity), entity);
    }

    if (!unsup) {
      throw CodeGeneratorError();
    }

    return unsup;
  }

  void log(std::string_view type, std::string_view name, const auto *entity) const {
    LOG(ERROR) << "Cannot codegen unsupported " << type << " " << name
               << PrefixedLocation(ast.Adopt(entity), " at or near ")
               << " on main job file "
               << ast.MainFile().Path().generic_string();
  }

  void log_type(std::string_view type, std::string_view name) const {
    LOG(ERROR) << "Cannot codegen unsupported " << type << " " << name
               << " on main job file "
               << ast.MainFile().Path().generic_string();
  }

public:
  MXErrorReportVisitorProxy(const pasta::AST &ast_) : ast(ast_) {}

  vast::operation visit(const vast::cg::clang_decl *raw_decl, vast::cg::scope_context &scope) override {
    return visit_impl(raw_decl, scope, "declaration", [](auto &ast, auto *raw) {
      return ast.Adopt(raw).KindName();
    });
  }

  vast::operation visit(const vast::cg::clang_stmt *raw_stmt, vast::cg::scope_context &scope) override {
    return visit_impl(raw_stmt, scope, "statement", [](auto &ast, auto *raw) {
      return ast.Adopt(raw).KindName();
    });
  }

  vast::mlir_type visit(const vast::cg::clang_type *type, vast::cg::scope_context &scope) override {
    return visit_impl(type, scope, "type", [](auto &, auto *t) {
      return vast::cg::clang_qual_type(t, 0).getAsString();
    });
  }

  vast::mlir_type visit(vast::cg::clang_qual_type type, vast::cg::scope_context &scope) override {
    return visit_impl(type, scope, "type", [](auto &, auto t) {
      return t.getAsString();
    });
  }

  std::optional<vast::named_attr> visit(const vast::cg::clang_attr *raw_attr, vast::cg::scope_context &scope) override {
    return visit_impl(raw_attr, scope, "attribute", [](auto &ast, auto *raw) {
      return ast.Adopt(raw).KindName();
    });
  }

  vast::operation visit_prototype(const vast::cg::clang_function *raw_decl, vast::cg::scope_context &scope) override {
    return visit_impl(raw_decl, scope, "function prototype", [](auto &, auto *raw) {
      return raw->getNameAsString();
    });
  }

private:
  const pasta::AST &ast;
};

class MXPreprocessingVisitorProxy : public vast::cg::fallthrough_list_node {
public:
  MXPreprocessingVisitorProxy(clang::ASTContext &ast_context_)
      : ast_context(ast_context_)
  {}

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
  vast::mlir_type visit(const vast::cg::clang_type *type, vast::cg::scope_context &scope) override {
      auto compressed = compress(type);
      auto new_type = compressed.getTypePtrOrNull();
      if (new_type != type) {
          if (compressed.hasQualifiers()) {
              return visit(compressed, scope);
          }
      } else {
          assert(!compressed.hasQualifiers());
      }
      return next->visit(new_type, scope);
  }

  vast::mlir_type visit(vast::cg::clang_qual_type type, vast::cg::scope_context &scope) override {
      return next->visit(compress(type), scope);
  }

private:

  vast::cg::clang_qual_type compress(const vast::cg::clang_type *type) {
      return TypeMapper::Compress(ast_context, type);
  }

  vast::cg::clang_qual_type compress(vast::cg::clang_qual_type type) {
      return TypeMapper::Compress(ast_context, type);
  }

  clang::ASTContext &ast_context;
};


//
// VAST Driver Setup Functions
//

std::unique_ptr<mlir::MLIRContext> MakeMLIRContext() {
  return vast::cg::mk_mcontext();
}

std::unique_ptr<vast::cg::codegen_builder>
MakeCodeGenBuilder(mlir::MLIRContext *mctx) {
  return vast::cg::mk_codegen_builder(mctx);
}

std::shared_ptr<vast::cg::meta_generator>
MakeMetaGenerator(mlir::MLIRContext &mctx, const EntityMapper &em) {
  return std::make_shared<MetaGenerator>(mctx, em);
}

std::shared_ptr<vast::cg::symbol_generator>
MakeSymbolGenerator(const NameMangler &nm) {
  return std::make_shared<SymbolGenerator>(nm);
}

std::unique_ptr<vast::cg::driver> MakeCodeGenDriver(const pasta::AST &ast,
                                                    const EntityMapper &em,
                                                    const NameMangler &nm) {
  auto &actx = ast.UnderlyingAST();
  auto mctx  = MakeMLIRContext();
  auto bld   = MakeCodeGenBuilder(mctx.get());
  auto mg    = MakeMetaGenerator(*mctx, em);
  auto sg    = MakeSymbolGenerator(nm);

  using vast::cg::as_node;
  using vast::cg::as_node_with_list_ref;

  auto visitors = std::make_shared<vast::cg::visitor_list>()
    | as_node<MXPreprocessingVisitorProxy>(ast.UnderlyingAST())
    | as_node_with_list_ref<vast::cg::attr_visitor_proxy>()
    | as_node<vast::cg::type_caching_proxy>()
    | as_node_with_list_ref<vast::cg::default_visitor>(
      *mctx, *bld, mg, sg,
      /* strict return = */ false,
      vast::cg::missing_return_policy::emit_trap
    )
    | as_node<MXErrorReportVisitorProxy>(ast)
    | as_node_with_list_ref<vast::cg::unsup_visitor>(*mctx, *bld)
    | as_node<vast::cg::fallthrough_visitor>();

  auto drv = std::make_unique<vast::cg::driver>(
    actx, std::move(mctx), std::move(bld), visitors
  );

  drv->enable_verifier(true);
  return drv;
}

} // namespace

class CodeGeneratorImpl {
public:

  std::optional<vast::owning_module_ref> Process(const pasta::AST &ast);
  std::optional<std::string> DumpToString(vast::owning_module_ref &mod);

  bool enabled = true;
  std::unique_ptr<vast::cg::driver> driver;
};


std::optional<vast::owning_module_ref> CodeGeneratorImpl::Process(const pasta::AST &ast) {
  try {
    auto decls = GenerateDeclarationsInDeclContext(ast.TranslationUnit());

    for (const auto &decl : decls) {
      driver->emit(const_cast<clang::Decl *>(decl.RawDecl()));
    }

    driver->finalize();
    return std::make_optional(driver->freeze());

  } catch (const CodeGeneratorError &e) {
    LOG(ERROR) << "Error generating Source IR: " << e.what();
    return std::nullopt;
  } catch (const std::exception &e) {
    LOG(ERROR) << "Error verifying Source IR: " << e.what();
    return std::nullopt;
  }
}


CodeGenerator::CodeGenerator()
    : impl(std::make_unique<CodeGeneratorImpl>()) {}

void CodeGenerator::Disable() { impl->enabled = false; }

bool CodeGenerator::IsEnabled() const { return impl->enabled; }

CodeGenerator::~CodeGenerator() {
  if (impl) {
    impl.reset();
  }
}

std::optional<std::string> CodeGeneratorImpl::DumpToString(vast::owning_module_ref &mlir_module) {
  std::string result;
  llvm::raw_string_ostream os(result);
  mlir::BytecodeWriterConfig config("MX");

  if (mlir::failed(mlir::writeBytecodeToFile(mlir_module.get(), os, config))) {
    return std::nullopt;
  }

  return std::make_optional(result);
}

std::string CodeGenerator::GenerateSourceIR(const pasta::AST &ast,
                                            const EntityMapper &em,
                                            const NameMangler &nm) {
  if (!IsEnabled()) {
    return "";
  }

  impl->driver = MakeCodeGenDriver(ast, em, nm);
  if (auto mod = impl->Process(ast)) {
    if (auto result = impl->DumpToString(mod.value())) {
      return result.value();
    }

    LOG(ERROR) << "Could not serialize module to bytecode on main job file " << ast.MainFile().Path().generic_string();
  }

  return "";
}

} // namespace indexer
