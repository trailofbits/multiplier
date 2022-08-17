// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>

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
    : clang::ConstDeclVisitor< FallBackDeclVisitor< Derived >, vast::Operation* >
    , vast::hl::CodeGenVisitorLens< FallBackDeclVisitor< Derived >, Derived >
    , vast::hl::CodeGenBuilderMixin< FallBackDeclVisitor< Derived >, Derived >
{
      using LensType = vast::hl::CodeGenVisitorLens< FallBackDeclVisitor< Derived >, Derived >;

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
          return make< vast::hl::UnsupportedDeclOp >(loc, "StaticAssert", elements);
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
    : clang::ConstStmtVisitor< FallBackStmtVisitor< Derived >, vast::Operation* >
    , vast::hl::CodeGenVisitorLens< FallBackStmtVisitor< Derived >, Derived >
    , vast::hl::CodeGenBuilderMixin< FallBackStmtVisitor< Derived >, Derived >
{
      using LensType = vast::hl::CodeGenVisitorLens< FallBackStmtVisitor< Derived >, Derived >;

      using LensType::derived;
      using LensType::context;
      using LensType::mcontext;
      using LensType::acontext;

      using LensType::meta_location;
      using LensType::visit;

      using Builder = vast::hl::CodeGenBuilderMixin< FallBackStmtVisitor< Derived >, Derived >;

      using Builder::make_stmt_region;
      using Builder::make_region_builder;
      using Builder::make_value_yield_region;
      using Builder::set_insertion_point_to_start;
      using Builder::set_insertion_point_to_end;
      using Builder::insertion_guard;

      template< typename Op, typename... Args >
      auto make(Args &&...args) {
        return this->template create< Op >(std::forward< Args >(args)...);
      }

      vast::Operation* VisitPredefinedExpr(const clang::PredefinedExpr *expr) {
        auto loc  = meta_location(expr);
        auto [region, type] = make_value_yield_region(*(expr->child_begin()));
        return make< vast::hl::UnsupportedExprOp >(loc, "PredefinedExpr", type, std::move(region));
      }

      vast::Operation* VisitCompoundLiteralExpr(const clang::CompoundLiteralExpr *expr) {
        auto loc = meta_location(expr);
        auto [region, type] = make_value_yield_region(*(expr->child_begin()));
        return make< vast::hl::UnsupportedExprOp >(loc, "CompoundLiteralExpr", type, std::move(region));
      }

      vast::Operation* VisitCXXConstructExpr(const clang::CXXConstructExpr *expr) {
        auto loc  = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "CXXConstructExpr", type, std::move(region));
      }

      vast::Operation* VisitRecoveryExpr(const clang::RecoveryExpr *expr) {
        auto loc  = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "RecoveryExpr", type, std::move(region));
      }

      vast::Operation* VisitBinaryOperator(const clang::BinaryOperator *stmt) {
        auto loc = meta_location(stmt);
        auto [region, type] = make_value_yield_region(stmt->getRHS());
        return make< vast::hl::UnsupportedExprOp >(loc,  "BinaryOperator", type, std::move(region));
      }

      vast::Operation* VisitConditionalOperator(const clang::ConditionalOperator *stmt) {
        auto loc = meta_location(stmt);
        auto [region, type] = make_value_yield_region(stmt->getCond());
        return make <vast::hl::UnsupportedExprOp> (loc,  "ConditionalOperator", type, std::move(region));
      }

      vast::Operation* VisitCXXDependentScopeMemberExpr(const clang::CXXDependentScopeMemberExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "CXXDependentScopeMemberExpr", type, std::move(region));
      }

      vast::Operation* VisitUnresolvedLookupExpr(const clang::UnresolvedLookupExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "UnresolvedLookupExpr", type, std::move(region));
      }

      vast::Operation* VisitVAArgExpr(const clang::VAArgExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "VAArgExpr", type,  std::move(region));
      }

      vast::Operation* VisitStmtExpr(const clang::StmtExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "StmtExpr", type,  std::move(region));
      }

      vast::Operation* VisitDeclRefExpr(const clang::DeclRefExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "DeclRefExpr", type, std::move(region));
      }

      vast::Operation* VisitTypeTraitExpr(const clang::TypeTraitExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "TypeTraitExpr", type, std::move(region));
      }

      vast::Operation* VisitObjCAvailabilityCheckExpr(const clang::ObjCAvailabilityCheckExpr *expr){
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "ObjCAvailabilityCheckExpr", type, std::move(region));
      }

      vast::Operation* VisitOffsetOfExpr(const clang::OffsetOfExpr *expr){
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "OffsetOfExpr", type, std::move(region));
      }

      vast::Operation* VisitGCCAsmStmt(const clang::GCCAsmStmt *expr){
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "GCCAsmStmt", type, std::move(region));
      }

      vast::Operation* VisitImplicitValueInitExpr(const clang::ImplicitValueInitExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "ImplicitValueInitExpr", type, std::move(region));
      }

      vast::Operation* VisitAtomicExpr(const clang::AtomicExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "AtomicExpr", type, std::move(region));
      }

      vast::Operation* VisitGenericSelectionExpr(const clang::GenericSelectionExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "GenericSelectionExpr", type, std::move(region));
      }

      vast::Operation* VisitChooseExpr(const clang::ChooseExpr *expr) {
        auto loc = meta_location(expr);
        auto first_child = *(expr->child_begin());
        auto [region, type] = make_value_yield_region(first_child);
        return make< vast::hl::UnsupportedExprOp >(loc, "ChooseExpr", type, std::move(region));
      }
};

template< typename Derived >
struct FallBackTypeVisitor
    : clang::TypeVisitor< FallBackTypeVisitor< Derived >, vast::hl::Type >
    , vast::hl::CodeGenVisitorLens< FallBackTypeVisitor< Derived >, Derived >
    , vast::hl::CodeGenBuilderMixin< FallBackTypeVisitor< Derived >, Derived > {

      using LensType = vast::hl::CodeGenVisitorLens< FallBackTypeVisitor< Derived >, Derived >;
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
    : FallBackDeclVisitor< Derived >
    , FallBackStmtVisitor< Derived >
    , FallBackTypeVisitor< Derived >
    , vast::hl::DefaultFallBackVisitorMixin< Derived >
{
    using DeclVisitor = FallBackDeclVisitor< Derived >;
    using StmtVisitor = FallBackStmtVisitor< Derived >;
    using TypeVisitor = FallBackTypeVisitor< Derived >;

    using DeclVisitor::Visit;
    using StmtVisitor::Visit;
    using TypeVisitor::Visit;

    using DefaultFallbackVisitor =  vast::hl::DefaultFallBackVisitorMixin< Derived >;

    vast::Operation* Visit(const clang::Stmt *stmt) {
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
      if(auto result = TypeVisitor::Visit(type)) {
        return result;
      }

      THROW("unsupported type: {0}", type->getTypeClassName());
      return DefaultFallbackVisitor::Visit(type);
    }

    vast::hl::Type Visit(clang::QualType type) {
      if (!type.isNull()) {
        auto underlying_type = type.getTypePtr();
        if(auto result = TypeVisitor::Visit(underlying_type))
          return result;
      }

      THROW("unsupported type: {0}", type.getAsString());
      return DefaultFallbackVisitor::Visit(type);
    }
};

}
