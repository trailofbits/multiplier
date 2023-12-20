// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXNewExpr.h>
#include <multiplier/AST/CXXConstructExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kCXXNewExprDerivedKinds[] = {
    CXXNewExpr::static_kind(),
};
}  // namespace

gap::generator<CXXNewExpr> CXXNewExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXNewExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXNewExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXNewExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXNewExpr> CXXNewExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXNewExpr, ir::Operation>> CXXNewExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCXXNewExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXNewExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXNewExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXNewExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXNewExpr::contains(const Decl &decl) {
  for (auto &parent : CXXNewExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXNewExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXNewExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXNewExpr> CXXNewExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CXXNewExpr> CXXNewExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXNewExpr> CXXNewExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXNewExpr::static_kind():
      return reinterpret_cast<const CXXNewExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXNewExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXNewExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXNewExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXNewExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXNewExpr> CXXNewExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXNewExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXNewExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXNewExpr> CXXNewExpr::from(const Reference &r) {
  return CXXNewExpr::from(r.as_statement());
}

std::optional<CXXNewExpr> CXXNewExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXNewExpr> CXXNewExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool CXXNewExpr::does_usual_array_delete_want_size(void) const {
  return impl->reader.getVal89();
}

Type CXXNewExpr::allocated_type(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Expr> CXXNewExpr::array_size(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<CXXConstructExpr> CXXNewExpr::construct_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal39();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return CXXConstructExpr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TokenRange CXXNewExpr::direct_initializer_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal40(), impl->reader.getVal41());
}

CXXNewExprInitializationStyle CXXNewExpr::initialization_style(void) const {
  return static_cast<CXXNewExprInitializationStyle>(impl->reader.getVal95());
}

std::optional<Expr> CXXNewExpr::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal42();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

FunctionDecl CXXNewExpr::operator_delete(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return FunctionDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

FunctionDecl CXXNewExpr::operator_new(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return FunctionDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

TokenRange CXXNewExpr::type_id_parentheses(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal45(), impl->reader.getVal46());
}

bool CXXNewExpr::has_initializer(void) const {
  return impl->reader.getVal90();
}

bool CXXNewExpr::is_array(void) const {
  return impl->reader.getVal91();
}

bool CXXNewExpr::is_global_new(void) const {
  return impl->reader.getVal92();
}

bool CXXNewExpr::is_parenthesis_type_id(void) const {
  return impl->reader.getVal93();
}

bool CXXNewExpr::pass_alignment(void) const {
  return impl->reader.getVal94();
}

unsigned CXXNewExpr::num_placement_arguments(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> CXXNewExpr::nth_placement_argument(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> CXXNewExpr::placement_arguments(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

bool CXXNewExpr::should_null_check_allocation(void) const {
  return impl->reader.getVal96();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
