// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXUuidofExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/MSGuidDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXUuidofExpr> CXXUuidofExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXUuidofExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXUuidofExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXUuidofExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXUuidofExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXUuidofExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXUuidofExpr::contains(const Decl &decl) {
  for (auto &parent : CXXUuidofExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXUuidofExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXUuidofExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXUuidofExprDerivedKinds[] = {
    CXXUuidofExpr::static_kind(),
};

}  // namespace

std::optional<CXXUuidofExpr> CXXUuidofExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXUuidofExpr::static_kind():
      return reinterpret_cast<const CXXUuidofExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXUuidofExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXUuidofExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXUuidofExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXUuidofExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXUuidofExpr> CXXUuidofExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXUuidofExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXUuidofExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const Reference &r) {
  return CXXUuidofExpr::from(r.as_statement());
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Expr> CXXUuidofExpr::expression_operand(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal37();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

MSGuidDecl CXXUuidofExpr::guid_declaration(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return MSGuidDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Type CXXUuidofExpr::type_operand(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type CXXUuidofExpr::type_operand_source_info(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool CXXUuidofExpr::is_type_operand(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
