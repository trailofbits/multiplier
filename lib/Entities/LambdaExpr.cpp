// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LambdaExpr.h>

#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/CompoundStmt.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FunctionTemplateDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<LambdaExpr> LambdaExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LambdaExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LambdaExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LambdaExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<LambdaExpr> LambdaExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = LambdaExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LambdaExpr> LambdaExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LambdaExpr> LambdaExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = LambdaExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LambdaExpr> LambdaExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LambdaExpr::contains(const Decl &decl) {
  for (auto &parent : LambdaExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LambdaExpr::contains(const Stmt &stmt) {
  for (auto &parent : LambdaExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<LambdaExpr> LambdaExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return LambdaExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kLambdaExprDerivedKinds[] = {
    LambdaExpr::static_kind(),
};

std::optional<LambdaExpr> LambdaExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case LambdaExpr::static_kind():
      return reinterpret_cast<const LambdaExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LambdaExpr> LambdaExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kLambdaExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<LambdaExpr> e = LambdaExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LambdaExpr> LambdaExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kLambdaExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<LambdaExpr> e = LambdaExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LambdaExpr> LambdaExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kLambdaExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<LambdaExpr> e = LambdaExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LambdaExpr> LambdaExpr::from(const Reference &r) {
  return LambdaExpr::from(r.as_statement());
}

std::optional<LambdaExpr> LambdaExpr::from(const TokenContext &t) {
  return LambdaExpr::from(t.as_statement());
}

Stmt LambdaExpr::body(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

CXXMethodDecl LambdaExpr::call_operator(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return CXXMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

LambdaCaptureDefault LambdaExpr::capture_default(void) const {
  return static_cast<LambdaCaptureDefault>(impl->reader.getVal94());
}

Token LambdaExpr::capture_default_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

CompoundStmt LambdaExpr::compound_statement_body(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return CompoundStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

std::optional<FunctionTemplateDecl> LambdaExpr::dependent_call_operator(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal42();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FunctionTemplateDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

unsigned LambdaExpr::num_explicit_template_parameters(void) const {
  return impl->reader.getVal15().size();
}

std::optional<NamedDecl> LambdaExpr::nth_explicit_template_parameter(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return NamedDecl::from(Decl(std::move(e)));
}

gap::generator<NamedDecl> LambdaExpr::explicit_template_parameters(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from(Decl(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

TokenRange LambdaExpr::introducer_range(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal43(), impl->reader.getVal44());
}

CXXRecordDecl LambdaExpr::lambda_class(void) const {
  RawEntityId eid = impl->reader.getVal45();
  return CXXRecordDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::optional<TemplateParameterList> LambdaExpr::template_parameter_list(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal46();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TemplateParameterListFor(impl->ep, eid)) {
      return TemplateParameterList(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Expr> LambdaExpr::trailing_requires_clause(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal47();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool LambdaExpr::has_explicit_parameters(void) const {
  return impl->reader.getVal89();
}

bool LambdaExpr::has_explicit_result_type(void) const {
  return impl->reader.getVal90();
}

bool LambdaExpr::is_generic_lambda(void) const {
  return impl->reader.getVal91();
}

bool LambdaExpr::is_mutable(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
