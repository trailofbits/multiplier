// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXNamedCastExpr.h>
#include <multiplier/AST/CastExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/ExplicitCastExpr.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/CXXAddrspaceCastExpr.h>
#include <multiplier/AST/CXXConstCastExpr.h>
#include <multiplier/AST/CXXDynamicCastExpr.h>
#include <multiplier/AST/CXXReinterpretCastExpr.h>
#include <multiplier/AST/CXXStaticCastExpr.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXNamedCastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXNamedCastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXNamedCastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXNamedCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXNamedCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXNamedCastExpr::contains(const Decl &decl) {
  for (auto &parent : CXXNamedCastExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXNamedCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : CXXNamedCastExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kCXXNamedCastExprDerivedKinds[] = {
    CXXReinterpretCastExpr::static_kind(),
    CXXStaticCastExpr::static_kind(),
    CXXAddrspaceCastExpr::static_kind(),
    CXXConstCastExpr::static_kind(),
    CXXDynamicCastExpr::static_kind(),
};

}  // namespace

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXReinterpretCastExpr::static_kind():
    case CXXStaticCastExpr::static_kind():
    case CXXAddrspaceCastExpr::static_kind():
    case CXXConstCastExpr::static_kind():
    case CXXDynamicCastExpr::static_kind():
      return reinterpret_cast<const CXXNamedCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCXXNamedCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXNamedCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXNamedCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXNamedCastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXNamedCastExpr> CXXNamedCastExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXNamedCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXNamedCastExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const Reference &r) {
  return CXXNamedCastExpr::from(r.as_statement());
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TokenRange CXXNamedCastExpr::angle_brackets(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal42(), impl->reader.getVal43());
}

std::string_view CXXNamedCastExpr::cast_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal65();
  return std::string_view(data.cStr(), data.size());
}

Token CXXNamedCastExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

Token CXXNamedCastExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
