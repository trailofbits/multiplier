// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CaseStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/SwitchCase.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CaseStmt> CaseStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CaseStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CaseStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CaseStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CaseStmt> CaseStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CaseStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CaseStmt> CaseStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CaseStmt> CaseStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CaseStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CaseStmt> CaseStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CaseStmt::contains(const Decl &decl) {
  for (auto &parent : CaseStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CaseStmt::contains(const Stmt &stmt) {
  for (auto &parent : CaseStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CaseStmt> CaseStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CaseStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCaseStmtDerivedKinds[] = {
    CaseStmt::static_kind(),
};

std::optional<CaseStmt> CaseStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CaseStmt::static_kind():
      return reinterpret_cast<const CaseStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CaseStmt> CaseStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCaseStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CaseStmt> e = CaseStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CaseStmt> CaseStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCaseStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CaseStmt> e = CaseStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CaseStmt> CaseStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCaseStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CaseStmt> e = CaseStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CaseStmt> CaseStmt::from(const Reference &r) {
  return CaseStmt::from(r.as_statement());
}

std::optional<CaseStmt> CaseStmt::from(const TokenContext &t) {
  return CaseStmt::from(t.as_statement());
}

bool CaseStmt::case_statement_is_gnu_range(void) const {
  return impl->reader.getVal15();
}

Token CaseStmt::case_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal17());
}

Token CaseStmt::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal20());
}

Expr CaseStmt::lhs(void) const {
  RawEntityId eid = impl->reader.getVal21();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

std::optional<Expr> CaseStmt::rhs(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal22();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
