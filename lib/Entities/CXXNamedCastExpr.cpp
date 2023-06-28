// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXNamedCastExpr.h>

#include <multiplier/Entities/CXXAddrspaceCastExpr.h>
#include <multiplier/Entities/CXXConstCastExpr.h>
#include <multiplier/Entities/CXXDynamicCastExpr.h>
#include <multiplier/Entities/CXXReinterpretCastExpr.h>
#include <multiplier/Entities/CXXStaticCastExpr.h>
#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ExplicitCastExpr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

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
    return CXXNamedCastExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXNamedCastExprDerivedKinds[] = {
    CXXReinterpretCastExpr::static_kind(),
    CXXStaticCastExpr::static_kind(),
    CXXAddrspaceCastExpr::static_kind(),
    CXXConstCastExpr::static_kind(),
    CXXDynamicCastExpr::static_kind(),
};

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const Stmt &parent) {
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
      if (std::optional<CXXNamedCastExpr> e = CXXNamedCastExpr::from(Stmt(std::move(eptr)))) {
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
      if (std::optional<CXXNamedCastExpr> e = CXXNamedCastExpr::from(Stmt(std::move(eptr)))) {
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
        if (std::optional<CXXNamedCastExpr> e = CXXNamedCastExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const Reference &r) {
  return CXXNamedCastExpr::from(r.as_statement());
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const TokenContext &t) {
  return CXXNamedCastExpr::from(t.as_statement());
}

TokenRange CXXNamedCastExpr::angle_brackets(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal44(), impl->reader.getVal45());
}

std::string_view CXXNamedCastExpr::cast_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal66();
  return std::string_view(data.cStr(), data.size());
}

Token CXXNamedCastExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal46());
}

Token CXXNamedCastExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal47());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
