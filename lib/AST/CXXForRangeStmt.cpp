// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXForRangeStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclStmt.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/VarDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kCXXForRangeStmtDerivedKinds[] = {
    CXXForRangeStmt::static_kind(),
};
}  // namespace

gap::generator<CXXForRangeStmt> CXXForRangeStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXForRangeStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXForRangeStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXForRangeStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXForRangeStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXForRangeStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXForRangeStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXForRangeStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXForRangeStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXForRangeStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXForRangeStmt, ir::Operation>> CXXForRangeStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCXXForRangeStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXForRangeStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXForRangeStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXForRangeStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXForRangeStmt> CXXForRangeStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXForRangeStmt::contains(const Decl &decl) {
  for (auto &parent : CXXForRangeStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXForRangeStmt::contains(const Stmt &stmt) {
  for (auto &parent : CXXForRangeStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXForRangeStmt::static_kind():
      return reinterpret_cast<const CXXForRangeStmt &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const Reference &r) {
  return CXXForRangeStmt::from(r.as_statement());
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<DeclStmt> CXXForRangeStmt::begin_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return DeclStmt::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Stmt CXXForRangeStmt::body(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Token CXXForRangeStmt::coawait_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

Token CXXForRangeStmt::colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal13());
}

std::optional<Expr> CXXForRangeStmt::condition(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal14();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<DeclStmt> CXXForRangeStmt::end_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal17();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return DeclStmt::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token CXXForRangeStmt::for_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal18());
}

std::optional<Expr> CXXForRangeStmt::increment(void) const {
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

std::optional<Stmt> CXXForRangeStmt::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal20();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

DeclStmt CXXForRangeStmt::loop_variable_statement(void) const {
  RawEntityId eid = impl->reader.getVal21();
  return DeclStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

VarDecl CXXForRangeStmt::loop_variable(void) const {
  RawEntityId eid = impl->reader.getVal22();
  return VarDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token CXXForRangeStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal31());
}

Expr CXXForRangeStmt::range_initializer(void) const {
  RawEntityId eid = impl->reader.getVal32();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

DeclStmt CXXForRangeStmt::range_statement(void) const {
  RawEntityId eid = impl->reader.getVal33();
  return DeclStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
