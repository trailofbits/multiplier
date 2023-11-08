// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExplicitCastExpr.h>

#include <multiplier/Entities/BuiltinBitCastExpr.h>
#include <multiplier/Entities/CStyleCastExpr.h>
#include <multiplier/Entities/CXXAddrspaceCastExpr.h>
#include <multiplier/Entities/CXXConstCastExpr.h>
#include <multiplier/Entities/CXXDynamicCastExpr.h>
#include <multiplier/Entities/CXXFunctionalCastExpr.h>
#include <multiplier/Entities/CXXReinterpretCastExpr.h>
#include <multiplier/Entities/CXXStaticCastExpr.h>
#include <multiplier/Entities/CastExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCBridgedCastExpr.h>
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

gap::generator<ExplicitCastExpr> ExplicitCastExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExplicitCastExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExplicitCastExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExplicitCastExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExplicitCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ExplicitCastExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ExplicitCastExpr::contains(const Decl &decl) {
  for (auto &parent : ExplicitCastExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ExplicitCastExpr::contains(const Stmt &stmt) {
  for (auto &parent : ExplicitCastExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ExplicitCastExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kExplicitCastExprDerivedKinds[] = {
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

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCBridgedCastExpr::static_kind():
    case BuiltinBitCastExpr::static_kind():
    case CStyleCastExpr::static_kind():
    case CXXFunctionalCastExpr::static_kind():
    case CXXReinterpretCastExpr::static_kind():
    case CXXStaticCastExpr::static_kind():
    case CXXAddrspaceCastExpr::static_kind():
    case CXXConstCastExpr::static_kind():
    case CXXDynamicCastExpr::static_kind():
      return reinterpret_cast<const ExplicitCastExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kExplicitCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ExplicitCastExpr> e = ExplicitCastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kExplicitCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ExplicitCastExpr> e = ExplicitCastExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExplicitCastExpr> ExplicitCastExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kExplicitCastExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ExplicitCastExpr> e = ExplicitCastExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const Reference &r) {
  return ExplicitCastExpr::from(r.as_statement());
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const TokenContext &t) {
  return ExplicitCastExpr::from(t.as_statement());
}

Type ExplicitCastExpr::type_as_written(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
