// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>

#if __has_include(<vast/Util/Common.hpp>)
#include <vast/Util/Common.hpp>
#include <vast/Translation/CodeGen.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenVisitor.hpp>
#include <vast/Translation/CodeGenBuilder.hpp>
#include <vast/Translation/CodeGenFallBackVisitor.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>

namespace indexer {

class Exception : public std::runtime_error {
 public:
  Exception(const std::string& what) : std::runtime_error(what) {}
  Exception(const char* what) : std::runtime_error(what) {}
};

template <typename T = Exception>
class ExceptionThrower {
  std::stringstream stream;
  bool triggered, moved = false;

 public:
  ExceptionThrower(bool cond = true, std::stringstream ss = std::stringstream())
    : stream(std::move(ss)), triggered(cond) {}

  ~ExceptionThrower() noexcept(false) {
      if (triggered && !moved) {
        throw T(stream.str());
      }
  }

  template <typename V>
  ExceptionThrower<T> operator<<(V&& s) {
      moved = true;
      stream << std::forward<V>(s);
      return ExceptionThrower<T>(triggered, std::move(stream));
  }
};

#define THROW_IF(cond, msg) ExceptionThrower<Exception>((cond)) << msg

#define THROW(fmt, ...) \
  THROW_IF(true, llvm::formatv(fmt __VA_OPT__(,) __VA_ARGS__).str().c_str();)


template< typename Derived >
struct FallBackDeclVisitor
    : clang::ConstDeclVisitor< FallBackDeclVisitor< Derived >, vast::Operation* >,
      vast::cg::CodeGenVisitorLens< FallBackDeclVisitor< Derived >, Derived >,
      vast::cg::CodeGenBuilderMixin< FallBackDeclVisitor< Derived >, Derived >
{
  using LensType = vast::cg::CodeGenVisitorLens< FallBackDeclVisitor< Derived >, Derived >;

  using LensType::derived;
  using LensType::context;
  using LensType::mcontext;
  using LensType::acontext;

  using LensType::meta_location;
  using LensType::visit;

  template< typename Op, typename... Args >
  auto make(Args &&...args) {
      return this->template create< Op >(std::forward< Args >(args)...);
  }

  vast::Operation* VisitFileScopeAsmDecl(const clang::FileScopeAsmDecl *decl) {
    auto loc = meta_location(decl);
    auto asm_string = decl->getAsmString();
    llvm::SmallVector< vast::Value > elements;
    return make< vast::hl::UnsupportedDeclOp >(loc, asm_string->getString(), elements);
  }

  vast::Operation* VisitNamespaceDecl(const clang::NamespaceDecl *decl) {
      auto loc  = meta_location(decl);
      auto name = context().get_decl_name(decl);
      llvm::SmallVector< vast::Value > elements;
      for (auto d = decl->decls_begin(), dend = decl->decls_end(); d != dend; ++d) {
        auto op = visit(*d);
        elements.push_back(op->getResult(0));
      }
      return make< vast::hl::UnsupportedDeclOp >(loc, name, elements);
  }

  vast::Operation* VisitStaticAssertDecl(const clang::StaticAssertDecl *decl) {
      auto loc  = meta_location(decl);
      llvm::SmallVector< vast::Value > elements;
      auto assert_expr  = decl->getAssertExpr();
      elements.push_back(visit(assert_expr)->getResult(0));
      return make< vast::hl::UnsupportedDeclOp >(loc, decl->getDeclKindName(), elements);
  }

  vast::Operation* VisitLinkageSpecDecl(const clang::LinkageSpecDecl *decl) {
     auto loc  = meta_location(decl);
     llvm::SmallVector< vast::Value > elements;
     for (auto d = decl->decls_begin(), dend = decl->decls_end(); d != dend; ++d) {
       auto op = visit(*d);
       elements.push_back(op->getResult(0));
     }
     return make< vast::hl::UnsupportedDeclOp >(loc, "LinkageSpec", elements);
  }

  vast::Operation* VisitParmVarDecl(const clang::ParmVarDecl *decl) {
    auto loc  = meta_location(decl);
    llvm::SmallVector< vast::Value > elements;
    return make< vast::hl::UnsupportedDeclOp >(loc, "ParmVar", elements);
  }
};

template< typename Derived >
struct FallBackStmtVisitor
    : clang::ConstStmtVisitor< FallBackStmtVisitor< Derived >, vast::Operation* >,
      vast::cg::CodeGenVisitorLens< FallBackStmtVisitor< Derived >, Derived >,
      vast::cg::CodeGenBuilderMixin< FallBackStmtVisitor< Derived >, Derived > {
  using LensType = vast::cg::CodeGenVisitorLens< FallBackStmtVisitor< Derived >, Derived >;

  using LensType::derived;
  using LensType::context;
  using LensType::mcontext;
  using LensType::acontext;

  using LensType::meta_location;
  using LensType::visit;

  using Builder = vast::cg::CodeGenBuilderMixin< FallBackStmtVisitor< Derived >, Derived >;

  using Builder::make_stmt_region;
  using Builder::make_region_builder;
  using Builder::make_cond_builder;
  using Builder::make_value_yield_region;
  using Builder::set_insertion_point_to_start;
  using Builder::set_insertion_point_to_end;
  using Builder::insertion_guard;

  template< typename Op, typename... Args >
  auto make(Args &&...args) {
    return this->template create< Op >(std::forward< Args >(args)...);
  }

  // NOTE: We only visit first child of the expression to avoid issue with
  // adding multiple blocks to mlir region. Updated/Add new Dialect that
  // should enable us to walk through all the child and add unsupported expr
  // node for them
  vast::Operation* VisitChildExpr(const clang::Expr *expr, std::string node) {
    auto loc  = meta_location(expr);
    if (expr->child_begin() != expr->child_end()) {
      auto first_child = *(expr->child_begin());
      auto [region, _] = make_value_yield_region(first_child);

      // Assign return type as expression type
      return make<vast::hl::UnsupportedExprOp>(loc, node, visit(expr->getType()), std::move(region));
    }
    return make<vast::hl::UnsupportedExprOp>(loc, node, visit(expr->getType()), nullptr);
  }

  vast::Operation* VisitOperands(const clang::Expr *expr, std::string node) {
    auto loc  = meta_location(expr);
    auto rtype =  visit(expr->getType());

    llvm::SmallVector<vast::Value> elements;
    for (auto it = expr->child_begin(); it != expr->child_end(); ++it) {
      elements.push_back(visit(*it)->getResult(0));
    }
    return  make<vast::hl::UnsupportedOp>(loc, rtype, node, elements);
  }

  vast::Operation* VisitPredefinedExpr(const clang::PredefinedExpr *expr) {
    return  VisitOperands(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitCompoundLiteralExpr(const clang::CompoundLiteralExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitCXXConstructExpr(const clang::CXXConstructExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitRecoveryExpr(const clang::RecoveryExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitBinaryOperator(const clang::BinaryOperator *stmt) {
    auto loc = meta_location(stmt);
    auto rtype =  visit(stmt->getType());

    llvm::SmallVector<vast::Value> elements;
    elements.push_back(visit(stmt->getLHS())->getResult(0));
    elements.push_back(visit(stmt->getRHS())->getResult(0));
    return  make<vast::hl::UnsupportedOp>(loc, rtype, stmt->getStmtClassName(), elements);
  }

  vast::Operation* VisitConditionalOperator(const clang::ConditionalOperator *stmt) {
    auto loc = meta_location(stmt);
    auto rtype =  visit(stmt->getType());

    llvm::SmallVector<vast::Value> elements;
    elements.push_back(visit(stmt->getCond())->getResult(0));
    elements.push_back(visit(stmt->getLHS())->getResult(0));
    elements.push_back(visit(stmt->getRHS())->getResult(0));
    return  make<vast::hl::UnsupportedOp>(loc, rtype, stmt->getStmtClassName(),  elements);

  }

  vast::Operation* VisitCXXDependentScopeMemberExpr(const clang::CXXDependentScopeMemberExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitUnresolvedLookupExpr(const clang::UnresolvedLookupExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitVAArgExpr(const clang::VAArgExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitStmtExpr(const clang::StmtExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitDeclRefExpr(const clang::DeclRefExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitTypeTraitExpr(const clang::TypeTraitExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitObjCAvailabilityCheckExpr(const clang::ObjCAvailabilityCheckExpr *expr){
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitOffsetOfExpr(const clang::OffsetOfExpr *expr){
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitGCCAsmStmt(const clang::GCCAsmStmt *expr){
    THROW("Unable to handle GCCASMStmt : {0}", expr->getStmtClassName());
    return nullptr;
  }

  vast::Operation* VisitImplicitValueInitExpr(const clang::ImplicitValueInitExpr *expr) {
    return VisitOperands(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitAtomicExpr(const clang::AtomicExpr *expr) {
    return VisitOperands(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitGenericSelectionExpr(const clang::GenericSelectionExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitChooseExpr(const clang::ChooseExpr *expr) {
    return VisitChildExpr(expr, expr->getStmtClassName());
  }

  vast::Operation* VisitUnaryOperator(const clang::UnaryOperator *expr) {
    auto loc = meta_location(expr);
    auto rtype =  visit(expr->getType());

    llvm::SmallVector<vast::Value> elements;
    elements.push_back(visit(expr->getSubExpr())->getResult(0));
    return make<vast::hl::UnsupportedOp>(loc, rtype, expr->getStmtClassName(), elements);
  }

  vast::Operation* VisitIndirectGotoStmt(const clang::IndirectGotoStmt *expr) {
    auto loc = meta_location(expr);
    auto target = expr->getTarget();
    auto [region, type] = make_value_yield_region(target);
    return make<vast::hl::UnsupportedExprOp>(loc, expr->getStmtClassName(), type, std::move(region));
  }

  // Note: vast handles FunctionDeclRefExpr node. However in some cases it may return null if
  //       FunctionDecl is not available in the top-level declarations. It will fallback to
  //       the visitor and throw an exception.
  vast::Operation* VisitFunctionDeclRefExpr(const clang::DeclRefExpr *expr) {
    THROW("Missing function decl : {0}", expr->getNameInfo().getAsString());
    return nullptr;
  }
};

template< typename Derived >
struct FallBackTypeVisitor
    : clang::TypeVisitor< FallBackTypeVisitor< Derived >, vast::hl::Type >,
      vast::cg::CodeGenVisitorLens< FallBackTypeVisitor< Derived >, Derived >,
      vast::cg::CodeGenBuilderMixin< FallBackTypeVisitor< Derived >, Derived > {

  using LensType = vast::cg::CodeGenVisitorLens< FallBackTypeVisitor< Derived >, Derived >;
  using base_type = clang::TypeVisitor< FallBackTypeVisitor< Derived >, Derived >;

  using LensType::derived;
  using LensType::context;
  using LensType::mcontext;
  using LensType::acontext;
  using LensType::visit;

  vast::hl::Type VisitAttributedType(const clang::AttributedType *type) {
    return visit(type->desugar());
  }

  vast::hl::Type VisitTypeOfExprType(const clang::TypeOfExprType *type) {
    return visit(type->desugar());
  }

  vast::hl::Type VisitTypeOfType(const clang::TypeOfType *type) {
    return visit(type->desugar());
  }
};

template< typename Derived >
struct FallBackVisitor
    : FallBackDeclVisitor< Derived >,
      FallBackStmtVisitor< Derived >,
      FallBackTypeVisitor< Derived >,
      vast::cg::DefaultFallBackVisitorMixin< Derived >
{
  using DeclVisitor = FallBackDeclVisitor< Derived >;
  using StmtVisitor = FallBackStmtVisitor< Derived >;
  using TypeVisitor = FallBackTypeVisitor< Derived >;

  using DeclVisitor::Visit;
  using StmtVisitor::Visit;
  using TypeVisitor::Visit;

  using DefaultFallbackVisitor =  vast::cg::DefaultFallBackVisitorMixin< Derived >;

  vast::Operation *Visit(const clang::Stmt *stmt) {
    if (auto result = StmtVisitor::Visit(stmt)) {
      return result;
    }

    // If the visitor return null; throw an exception with the class name
    THROW("unsupported stmt class : {0}", stmt->getStmtClassName());
    return DefaultFallbackVisitor::Visit(stmt);
  }

  vast::Operation* Visit(const clang::Decl *decl) {
    if (auto result = DeclVisitor::Visit(decl)) {
      return result;
    }

    // If the visitor return null; throw an exception with the class name
    THROW("unsupported decl kind : {0}", decl->getDeclKindName());
    return DefaultFallbackVisitor::Visit(decl);
  }

  vast::hl::Type Visit(const clang::Type *type) {
    if (auto result = TypeVisitor::Visit(type)) {
      return result;
    }

    THROW("unsupported type: {0}", type->getTypeClassName());
    return DefaultFallbackVisitor::Visit(type);
  }

  vast::hl::Type Visit(clang::QualType type) {
    if (!type.isNull()) {
      auto underlying_type = type.getTypePtr();
      if (auto result = TypeVisitor::Visit(underlying_type)) {
        return result;
      }
    }

    THROW("unsupported type: {0}", type.getAsString());
    return DefaultFallbackVisitor::Visit(type);
  }
};

}  // namespace indexer

#endif
