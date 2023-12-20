// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CaseStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/SwitchCase.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kCaseStmtDerivedKinds[] = {
    CaseStmt::static_kind(),
};
}  // namespace

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

std::optional<CaseStmt> CaseStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CaseStmt, ir::Operation>> CaseStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCaseStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CaseStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CaseStmt> CaseStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CaseStmt> CaseStmt::from_base(const Stmt &parent) {
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
      if (std::optional<CaseStmt> e = from_base(std::move(eptr))) {
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
      if (std::optional<CaseStmt> e = from_base(std::move(eptr))) {
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
        if (std::optional<CaseStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CaseStmt> CaseStmt::from(const Reference &r) {
  return CaseStmt::from(r.as_statement());
}

std::optional<CaseStmt> CaseStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CaseStmt> CaseStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool CaseStmt::case_statement_is_gnu_range(void) const {
  return impl->reader.getVal12();
}

Token CaseStmt::case_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

Token CaseStmt::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal17());
}

Expr CaseStmt::lhs(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

std::optional<Expr> CaseStmt::rhs(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal19();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
