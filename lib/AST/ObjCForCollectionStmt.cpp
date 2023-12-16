// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCForCollectionStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kObjCForCollectionStmtDerivedKinds[] = {
    ObjCForCollectionStmt::static_kind(),
};
}  // namespace

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCForCollectionStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCForCollectionStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCForCollectionStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

#ifndef MX_DISABLE_VAST
std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCForCollectionStmt, ir::Operation>> ObjCForCollectionStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kObjCForCollectionStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCForCollectionStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCForCollectionStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCForCollectionStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCForCollectionStmt::contains(const Decl &decl) {
  for (auto &parent : ObjCForCollectionStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCForCollectionStmt::contains(const Stmt &stmt) {
  for (auto &parent : ObjCForCollectionStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCForCollectionStmt::static_kind():
      return reinterpret_cast<const ObjCForCollectionStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kObjCForCollectionStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCForCollectionStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCForCollectionStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCForCollectionStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCForCollectionStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCForCollectionStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const Reference &r) {
  return ObjCForCollectionStmt::from(r.as_statement());
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Stmt ObjCForCollectionStmt::body(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr ObjCForCollectionStmt::collection(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Stmt ObjCForCollectionStmt::element(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Token ObjCForCollectionStmt::for_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal13());
}

Token ObjCForCollectionStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
