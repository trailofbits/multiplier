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
#include <vast/CodeGen/CodeGenPolicy.hpp>
#include <vast/CodeGen/CodeGenVisitorList.hpp>
#include <vast/CodeGen/DefaultVisitor.hpp>
#include <vast/CodeGen/UnsupportedVisitor.hpp>
#include <vast/CodeGen/DataLayout.hpp>
#include <vast/CodeGen/DefaultCodeGenPolicy.hpp>
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

#include "../../lib/IR/SourceIR.h"

namespace indexer {
namespace {

class CodeGeneratorError final : public std::runtime_error {
public:
  explicit CodeGeneratorError(const std::string &message)
      : std::runtime_error(message) {}

  CodeGeneratorError(void)
      : std::runtime_error("Code generation error occurred") {}
};

// Generate `mlir::Location`s for Clang decls/stmts/etc. The location isn't
// the typical `file:line:col`, but instead embeds the entity ID for the Clang
// object, so that we can then correlate VAST-produced MLIR entities saved
// by Multiplier to its database.
class MetaGenerator final : public vast::cg::meta_generator {
  // Entity mapper; The entity id gets embedded as metadata
  const EntityMapper &em;

  // MLIR context for generating the MLIR location from source location
  mlir::MLIRContext * const mctx;

  mlir::Location unknown_location;

public:

  MetaGenerator(mlir::MLIRContext &mctx_, const EntityMapper &em_)
      : em(em_),
        mctx(&mctx_),
        unknown_location(mlir::UnknownLoc::get(mctx)) {}

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
      if constexpr (std::is_same_v<T, clang::Stmt> ||
                    std::is_same_v<T, clang::Expr>) {
        if (auto dre = clang::dyn_cast<clang::DeclRefExpr>(data)) {
          dre->dumpColor();
          assert(false);
        }
      }
      return unknown_location;
    }

    auto attr = vast::meta::IdentifierAttr::get(mctx, raw_entity_id);
    return mlir::FusedLoc::get({}, attr, mctx);
  }
};

// Produce symbol names based on entity IDs, as Multiplier's name mangler won't
// produce named for all the same thing;s that VAST's default symbol name
// generator will.
class SymbolGenerator final : public vast::cg::symbol_generator {
 private:
  const EntityMapper &em;

  std::unordered_map<const vast::cg::clang_decl *, std::string> names;
  std::string id_name;
  llvm::raw_string_ostream os;

  std::optional<vast::cg::symbol_name> mangle(
      const vast::cg::clang_decl *decl_) {

    auto decl = decl_->getCanonicalDecl();
    auto it = names.find(decl);
    if (it != names.end()) {
      return it->second;
    }

    // TODO(pag): This won't be good enough for namespaces, as they are
    //            internalized into fragments.
    auto id = em.EntityId(decl);
    if (id == mx::kInvalidEntityId) {
      return std::nullopt;
    }

    id_name.clear();
    os << id;
    it = names.emplace(decl, std::move(id_name)).first;
    return it->second;
  }

 public:
  virtual ~SymbolGenerator(void) = default;

  inline SymbolGenerator(const EntityMapper &em_)
      : em(em_),
        os(id_name) {}

  std::optional<vast::cg::symbol_name> symbol(
      vast::cg::clang_global global) final {
    return mangle(global.getCanonicalDecl().getDecl());
  }

  std::optional<vast::cg::symbol_name> symbol(
      const vast::cg::clang_decl_ref_expr *ref) {
    return mangle(ref->getDecl());
  }
};


class ErrorReportVisitorProxy
    : public vast::cg::fallthrough_list_node {
  using base = vast::cg::fallthrough_visitor;

  template <typename EntityType, typename NameFunc>
  auto visit_impl(EntityType entity, vast::cg::scope_context &scope,
                  const std::string &type, NameFunc name) {
    auto unsup = next->visit(entity, scope);

    if constexpr (std::is_same_v<EntityType, const vast::cg::clang_type *>
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

  void log(std::string_view type, std::string_view name,
           const auto *entity) const {
    LOG(WARNING)
        << "Cannot codegen unsupported " << type << " " << name
        << PrefixedLocation(ast.Adopt(entity), " at or near ")
        << " on main job file "
        << ast.MainFile().Path().generic_string();
  }

  void log_type(std::string_view type, std::string_view name) const {
    LOG(WARNING)
        << "Cannot codegen unsupported " << type << " " << name
        << " on main job file "
        << ast.MainFile().Path().generic_string();
  }

public:
  ErrorReportVisitorProxy(const pasta::AST &ast_)
      : ast(ast_) {}

  vast::operation visit(const vast::cg::clang_decl *raw_decl,
                        vast::cg::scope_context &scope) override {
    return visit_impl(raw_decl, scope, "declaration",
                      [] (auto &ast, auto *raw) {
                        return ast.Adopt(raw).KindName();
                      });
  }

  vast::operation visit(const vast::cg::clang_stmt *raw_stmt,
                        vast::cg::scope_context &scope) override {
    return visit_impl(raw_stmt, scope, "statement",
                      [] (auto &ast, auto *raw) {
                        return ast.Adopt(raw).KindName();
                      });
  }

  vast::mlir_type visit(const vast::cg::clang_type *type,
                        vast::cg::scope_context &scope) override {
    return visit_impl(type, scope, "type",
                      [] (auto &, auto *t) {
                        return vast::cg::clang_qual_type(t, 0).getAsString();
                      });
  }

  vast::mlir_type visit(vast::cg::clang_qual_type type,
                        vast::cg::scope_context &scope) override {
    return visit_impl(type, scope, "type",
                      [] (auto &, auto t) {
                        return t.getAsString();
                      });
  }

  std::optional<vast::named_attr> visit(
      const vast::cg::clang_attr *raw_attr,
      vast::cg::scope_context &scope) override {
    return visit_impl(raw_attr, scope, "attribute", [](auto &ast, auto *raw) {
      return ast.Adopt(raw).KindName();
    });
  }

  vast::operation visit_prototype(const vast::cg::clang_function *raw_decl,
                                  vast::cg::scope_context &scope) override {
    return visit_impl(raw_decl, scope, "function prototype",
                      [] (auto &, auto *raw) {
                        return raw->getNameAsString();
                      });
  }

private:
  const pasta::AST &ast;
};

class PreprocessingVisitorProxy : public vast::cg::fallthrough_list_node {
 private:
  clang::ASTContext &ast_context;
  const EntityMapper &em;

  int in_ce{0};
  const vast::cg::clang_stmt *expected_ce{nullptr};

 public:
  PreprocessingVisitorProxy(clang::ASTContext &ast_context_,
                            const EntityMapper &em_)
      : ast_context(ast_context_),
        em(em_) {}

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
  vast::mlir_type visit(const vast::cg::clang_type *type,
                        vast::cg::scope_context &scope) override {
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

  vast::mlir_type visit(vast::cg::clang_qual_type type,
                        vast::cg::scope_context &scope) override {
    return next->visit(compress(type), scope);
  }

  // Don't codegen statements for fragments that aren't indexed as part of this
  // translation unit.
  vast::operation visit(const vast::cg::clang_stmt *raw_stmt,
                        vast::cg::scope_context &scope) override {
    auto eid = em.EntityId(raw_stmt);
    if (eid != mx::kInvalidEntityId) {
      return next->visit(raw_stmt, scope);
    }

    if (clang::isa<clang::ConstantExpr>(raw_stmt) ||
        expected_ce == raw_stmt) {
      ++in_ce;
      auto ret = next->visit(raw_stmt, scope);
      --in_ce;
      return ret;
    }

    if (in_ce ||
        clang::isa<clang::IntegerLiteral>(raw_stmt) ||
        clang::isa<clang::ImaginaryLiteral>(raw_stmt) ||
        clang::isa<clang::FloatingLiteral>(raw_stmt) ||
        clang::isa<clang::FixedPointLiteral>(raw_stmt) ||
        clang::isa<clang::CharacterLiteral>(raw_stmt) ||
        clang::isa<clang::StringLiteral>(raw_stmt) ||
        clang::isa<clang::ObjCStringLiteral>(raw_stmt) ||
        clang::isa<clang::ObjCDictionaryLiteral>(raw_stmt) ||
        clang::isa<clang::ObjCArrayLiteral>(raw_stmt)) {
      return next->visit(raw_stmt, scope);
    }

    raw_stmt->dumpColor();
    return {};
  }

  vast::operation visit(const vast::cg::clang_decl *raw_decl,
                        vast::cg::scope_context &scope) override {

    // Avoid having to lift constant expressions in enumerators. These will
    // often be in different fragments.
    if (auto enumerator = clang::dyn_cast<clang::EnumConstantDecl>(
            const_cast<vast::cg::clang_decl *>(raw_decl))) {
      auto old_init = enumerator->getInitExpr();
      enumerator->setInitExpr(nullptr);
      auto ret = next->visit(raw_decl, scope);
      enumerator->setInitExpr(old_init);
      return ret;
    }

    const auto old_expected_ce = expected_ce;

    // VAST doesn't (yet) lift the field bitfield expressions, but if it
    // eventually does, then mark them as expected constant expressions. They
    // might be in different fragments. The expressions do, however, need to be
    // present for the calculation of the bitfield with.
    if (auto field = clang::dyn_cast<clang::FieldDecl>(raw_decl)) {
      expected_ce = field->getBitWidth();
    }

    auto ret = next->visit(raw_decl, scope);
    expected_ce = old_expected_ce;

    // VAST will sometimes set the wrong visibility. We don't really care about
    // the visibility.
    if (clang::isa<clang::FunctionDecl>(raw_decl)) {
      if (auto fn = mlir::dyn_cast<vast::hl::FuncOp>(ret)) {
        mlir::SymbolTable::setSymbolVisibility(
            fn, vast::cg::mlir_visibility::Public);
      }
    }

    return ret;
  }

 private:

  vast::cg::clang_qual_type compress(const vast::cg::clang_type *type) {
    return TypeMapper::Compress(ast_context, type);
  }

  vast::cg::clang_qual_type compress(vast::cg::clang_qual_type type) {
    return TypeMapper::Compress(ast_context, type);
  }
};

class CodeGenPolicy final : public vast::cg::policy_base {
 private:
  const EntityMapper &em;
  std::unordered_set<mx::RawEntityId> fragment_indexes;

 public:
  CodeGenPolicy(const EntityMapper &em_,
                std::vector<mx::PackedFragmentId> fragment_ids)
      : em(em_) {

    for (auto fid : fragment_ids) {
      fragment_indexes.insert(fid.Unpack().fragment_id);
    }
  }

  virtual ~CodeGenPolicy(void) = default;

  bool emit_strict_function_return(
      const vast::cg::clang_function *) const final {
    return false;
  };

  enum vast::cg::missing_return_policy missing_return_policy(
      const vast::cg::clang_function *) const final {
    return vast::cg::missing_return_policy::emit_trap;
  }

  bool SkipDeclBody(const void *decl) const {
    auto eid = em.EntityId(decl);
    if (eid == mx::kInvalidEntityId) {
      assert(false);
      return true;
    }

    auto decl_id = mx::EntityId(eid).Extract<mx::DeclId>();
    if (!decl_id) {
      assert(false);
      return false;
    }

    return !fragment_indexes.contains(decl_id->fragment_id);
  }

  bool skip_function_body(const vast::cg::clang_function *decl) const final {
    return SkipDeclBody(decl);
  }

  bool skip_global_initializer(
      const vast::cg::clang_var_decl *decl) const final {
    return SkipDeclBody(decl);
  }
};

static std::optional<vast::owning_module_ref> CreateModule(
    const pasta::AST &ast, const EntityMapper &em,
    std::vector<mx::PackedFragmentId> fragment_ids) try {

  auto &actx = ast.UnderlyingAST();
  auto &mctx = mx::ir::GlobalMLIRContext();
  auto bld = vast::cg::mk_codegen_builder(mctx);
  auto mg = std::make_shared<MetaGenerator>(mctx, em);
  auto sg = std::make_shared<SymbolGenerator>(em);
  auto cp = std::make_shared<CodeGenPolicy>(em, std::move(fragment_ids));
  using vast::cg::as_node;
  using vast::cg::as_node_with_list_ref;

  auto visitors =
      std::make_shared<vast::cg::visitor_list>() |
      as_node<PreprocessingVisitorProxy>(ast.UnderlyingAST(), em) |
      as_node_with_list_ref<vast::cg::attr_visitor_proxy>() |
      as_node<vast::cg::type_caching_proxy>() |
      as_node_with_list_ref<vast::cg::default_visitor>(
          mctx, actx, *bld, mg, sg, cp) |
      as_node<ErrorReportVisitorProxy>(ast) |
      as_node_with_list_ref<vast::cg::unsup_visitor>(mctx, *bld, mg) |
      as_node<vast::cg::fallthrough_visitor>();

  vast::cg::driver driver(actx, mctx, std::move(bld), visitors);
  driver.enable_verifier(true);

  auto decls = GenerateDeclarationsInDeclContext(ast.TranslationUnit());
  for (const auto &decl : decls) {
    driver.emit(const_cast<clang::Decl *>(decl.RawDecl()));
  }

  driver.finalize();
  return std::make_optional(driver.freeze());

} catch (const CodeGeneratorError &e) {
  LOG(ERROR) << "Error generating Source IR: " << e.what();
  return std::nullopt;
} catch (const std::exception &e) {
  LOG(ERROR) << "Error verifying Source IR: " << e.what();
  return std::nullopt;
}

static std::optional<std::string> DumpToString(
    vast::owning_module_ref &mlir_module) {
  std::string result;
  llvm::raw_string_ostream os(result);
  mlir::BytecodeWriterConfig config("MX");

  if (mlir::failed(mlir::writeBytecodeToFile(mlir_module.get(), os, config))) {
    return std::nullopt;
  }

  return std::make_optional(std::move(result));
}

} // namespace

class CodeGeneratorImpl {
 public:
  bool enabled = true;
};

CodeGenerator::CodeGenerator(void)
    : impl(std::make_unique<CodeGeneratorImpl>()) {}

void CodeGenerator::Disable(void) { impl->enabled = false; }

bool CodeGenerator::IsEnabled(void) const { return impl->enabled; }

CodeGenerator::~CodeGenerator(void) {
  if (impl) {
    impl.reset();
  }
}

std::string CodeGenerator::GenerateSourceIR(
    const pasta::AST &ast, const EntityMapper &em, const NameMangler &,
    std::vector<mx::PackedFragmentId> fragment_ids) {

  if (!IsEnabled()) {
    return "";
  }

  auto mod = CreateModule(ast, em, std::move(fragment_ids));
  if (!mod) {
    return "";
  }

  // Set the flag to enable printing of debug information. The prettyForm
  // flag passed to the function is set to false to avoid printing them in
  // `pretty` form. This is because the IR generated in pretty form is not
  // parsable.
  auto flags = mlir::OpPrintingFlags();
  flags.enableDebugInfo(true, false);

  // Nifty for debugging, to see what the MLIR looked like.
  if (true) {
    std::error_code ec;
    std::string out_file =
        (std::filesystem::path("/tmp/src/") / ast.MainFile().Path().filename()).generic_string();
    llvm::raw_fd_ostream os(out_file, ec);
    if (!ec) {
      (*mod)->print(os, flags);
    } else {
      LOG(ERROR) << ec.message();
    }
  }

  if (auto result = DumpToString(mod.value())) {
    return result.value();
  }

  LOG(ERROR)
      << "Could not serialize module to bytecode on main job file "
      << ast.MainFile().Path().generic_string();

  return "";
}

} // namespace indexer
