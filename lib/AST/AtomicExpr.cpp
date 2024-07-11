// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AtomicExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kAtomicExprDerivedKinds[] = {
    AtomicExpr::static_kind(),
};
}  // namespace

gap::generator<AtomicExpr> AtomicExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kAtomicExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AtomicExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAtomicExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AtomicExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAtomicExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AtomicExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AtomicExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AtomicExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AtomicExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AtomicExpr> AtomicExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<AtomicExpr, ir::Operation>> AtomicExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kAtomicExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<AtomicExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AtomicExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AtomicExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AtomicExpr> AtomicExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AtomicExpr::contains(const Decl &decl) {
  for (auto &parent : AtomicExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool AtomicExpr::contains(const Stmt &stmt) {
  for (auto &parent : AtomicExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<AtomicExpr> AtomicExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<AtomicExpr> AtomicExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<AtomicExpr> AtomicExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case AtomicExpr::static_kind():
      return reinterpret_cast<const AtomicExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<AtomicExpr> AtomicExpr::from(const Reference &r) {
  return AtomicExpr::from(r.as_statement());
}

std::optional<AtomicExpr> AtomicExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<AtomicExpr> AtomicExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token AtomicExpr::builtin_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

AtomicExprAtomicOp AtomicExpr::operation(void) const {
  return static_cast<AtomicExprAtomicOp>(impl->reader.getVal89());
}

std::string_view AtomicExpr::operation_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Expr AtomicExpr::order(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

std::optional<Expr> AtomicExpr::order_fail(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal40();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Expr AtomicExpr::pointer(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token AtomicExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

std::optional<Expr> AtomicExpr::scope(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal43();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Expr> AtomicExpr::value1(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal44();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Expr> AtomicExpr::value2(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal45();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type AtomicExpr::value_type(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Expr> AtomicExpr::weak(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal47();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool AtomicExpr::is_cmp_x_chg(void) const {
  return impl->reader.getVal84();
}

bool AtomicExpr::is_open_cl(void) const {
  return impl->reader.getVal85();
}

bool AtomicExpr::is_volatile(void) const {
  return impl->reader.getVal86();
}

unsigned AtomicExpr::num_sub_expressions(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> AtomicExpr::nth_sub_expression(unsigned n) const {
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

gap::generator<Expr> AtomicExpr::sub_expressions(void) const & {
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

#pragma GCC diagnostic pop
#endif
}  // namespace mx
