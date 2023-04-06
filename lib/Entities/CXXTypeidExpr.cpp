// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXTypeidExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXTypeidExpr> CXXTypeidExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXTypeidExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXTypeidExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXTypeidExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXTypeidExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXTypeidExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXTypeidExpr::contains(const Decl &decl) {
  for (auto &parent : CXXTypeidExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXTypeidExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXTypeidExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXTypeidExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXTypeidExprDerivedKinds[] = {
    CXXTypeidExpr::static_kind(),
};

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXTypeidExpr::static_kind():
      return reinterpret_cast<const CXXTypeidExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXTypeidExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXTypeidExpr> e = CXXTypeidExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXTypeidExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXTypeidExpr> e = CXXTypeidExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXTypeidExpr> CXXTypeidExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXTypeidExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXTypeidExpr> e = CXXTypeidExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const Reference &r) {
  return CXXTypeidExpr::from(r.as_statement());
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const TokenContext &t) {
  return CXXTypeidExpr::from(t.as_statement());
}

std::optional<Expr> CXXTypeidExpr::expression_operand(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Type CXXTypeidExpr::type_operand(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type CXXTypeidExpr::type_operand_source_info(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<bool> CXXTypeidExpr::is_most_derived(void) const {
  if (!impl->reader.getVal90()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal89());
  }
  return std::nullopt;
}

bool CXXTypeidExpr::is_potentially_evaluated(void) const {
  return impl->reader.getVal91();
}

bool CXXTypeidExpr::is_type_operand(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
