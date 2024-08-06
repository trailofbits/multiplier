// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CastExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>
#include <multiplier/AST/BuiltinBitCastExpr.h>
#include <multiplier/AST/CStyleCastExpr.h>
#include <multiplier/AST/CXXAddrspaceCastExpr.h>
#include <multiplier/AST/CXXConstCastExpr.h>
#include <multiplier/AST/CXXDynamicCastExpr.h>
#include <multiplier/AST/CXXFunctionalCastExpr.h>
#include <multiplier/AST/CXXReinterpretCastExpr.h>
#include <multiplier/AST/CXXStaticCastExpr.h>
#include <multiplier/AST/ImplicitCastExpr.h>
#include <multiplier/AST/ObjCBridgedCastExpr.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
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
}  // namespace

gap::generator<CastExpr> CastExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CastExpr> e = from_base(std::move(eptr))) {
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
        if (std::optional<CastExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<CastExpr> CastExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCastExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CastExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<CastExpr> CastExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CastExpr, ir::Operation>> CastExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kCastExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CastExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<CastExpr> CastExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CastExpr> CastExpr::from_base(const Stmt &parent) {
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

std::optional<CastExpr> CastExpr::from(const Reference &r) {
  return CastExpr::from(r.as_statement());
}

std::optional<CastExpr> CastExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<CastExpr> CastExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool CastExpr::changes_volatile_qualification(void) const {
  return impl->reader.getVal84();
}

CastKind CastExpr::cast_kind(void) const {
  return static_cast<CastKind>(impl->reader.getVal89());
}

std::string_view CastExpr::cast_kind_name(void) const {
  capnp::Text::Reader data = impl->reader.getVal61();
  return std::string_view(data.cStr(), data.size());
}

std::optional<NamedDecl> CastExpr::conversion_function(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return NamedDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Expr CastExpr::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr CastExpr::sub_expression_as_written(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

std::optional<FieldDecl> CastExpr::target_union_field(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal41();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return FieldDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool CastExpr::has_stored_fp_features(void) const {
  return impl->reader.getVal85();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
