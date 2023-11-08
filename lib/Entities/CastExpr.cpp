// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CastExpr.h>

#include <multiplier/Entities/BuiltinBitCastExpr.h>
#include <multiplier/Entities/CStyleCastExpr.h>
#include <multiplier/Entities/CXXAddrspaceCastExpr.h>
#include <multiplier/Entities/CXXConstCastExpr.h>
#include <multiplier/Entities/CXXDynamicCastExpr.h>
#include <multiplier/Entities/CXXFunctionalCastExpr.h>
#include <multiplier/Entities/CXXReinterpretCastExpr.h>
#include <multiplier/Entities/CXXStaticCastExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCBridgedCastExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CastExpr> CastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CastExpr> CastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CastExpr> CastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CastExpr> CastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CastExpr> CastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CastExpr::contains(const Decl &decl) {
  for (auto &parent : CastExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CastExpr::contains(const Stmt &stmt) {
  for (auto &parent : CastExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CastExpr> CastExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CastExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCastExprDerivedKinds[] = {
    ImplicitCastExpr::static_kind(),
    ObjCBridgedCastExpr::static_kind(),
    BuiltinBitCastExpr::static_kind(),
    CStyleCastExpr::static_kind(),
    CXXFunctionalCastExpr::static_kind(),
    CXXReinterpretCastExpr::static_kind(),
    CXXStaticCastExpr::static_kind(),
    CXXAddrspaceCastExpr::static_kind(),
    CXXConstCastExpr::static_kind(),
    CXXDynamicCastExpr::static_kind(),
};

std::optional<CastExpr> CastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ImplicitCastExpr::static_kind():
    case ObjCBridgedCastExpr::static_kind():
    case BuiltinBitCastExpr::static_kind():
    case CStyleCastExpr::static_kind():
    case CXXFunctionalCastExpr::static_kind():
    case CXXReinterpretCastExpr::static_kind():
    case CXXStaticCastExpr::static_kind():
    case CXXAddrspaceCastExpr::static_kind():
    case CXXConstCastExpr::static_kind():
    case CXXDynamicCastExpr::static_kind():
      return reinterpret_cast<const CastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CastExpr> CastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CastExpr> e = CastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CastExpr> CastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CastExpr> e = CastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CastExpr> CastExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CastExpr> e = CastExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CastExpr> CastExpr::from(const Reference &r) {
  return CastExpr::from(r.as_statement());
}

std::optional<CastExpr> CastExpr::from(const TokenContext &t) {
  return CastExpr::from(t.as_statement());
}

CastKind CastExpr::cast_kind(void) const {
  return static_cast<CastKind>(impl->reader.getVal95());
}

std::string_view CastExpr::cast_kind_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal60();
  return std::string_view(data.cStr(), data.size());
}

std::optional<NamedDecl> CastExpr::conversion_function(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal37();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return NamedDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Expr CastExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr CastExpr::sub_expression_as_written(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

std::optional<FieldDecl> CastExpr::target_union_field(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal40();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool CastExpr::has_stored_fp_features(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
