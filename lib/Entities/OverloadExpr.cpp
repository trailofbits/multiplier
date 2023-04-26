// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OverloadExpr.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UnresolvedLookupExpr.h>
#include <multiplier/Entities/UnresolvedMemberExpr.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OverloadExpr> OverloadExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OverloadExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OverloadExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OverloadExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OverloadExpr> OverloadExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OverloadExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OverloadExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OverloadExpr::contains(const Decl &decl) {
  for (auto &parent : OverloadExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OverloadExpr::contains(const Stmt &stmt) {
  for (auto &parent : OverloadExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OverloadExpr> OverloadExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OverloadExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOverloadExprDerivedKinds[] = {
    UnresolvedLookupExpr::static_kind(),
    UnresolvedMemberExpr::static_kind(),
};

std::optional<OverloadExpr> OverloadExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case UnresolvedLookupExpr::static_kind():
    case UnresolvedMemberExpr::static_kind():
      return reinterpret_cast<const OverloadExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OverloadExpr> OverloadExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOverloadExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OverloadExpr> e = OverloadExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOverloadExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OverloadExpr> e = OverloadExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OverloadExpr> OverloadExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOverloadExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OverloadExpr> e = OverloadExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OverloadExpr> OverloadExpr::from(const Reference &r) {
  return OverloadExpr::from(r.as_statement());
}

std::optional<OverloadExpr> OverloadExpr::from(const TokenContext &t) {
  return OverloadExpr::from(t.as_statement());
}

Token OverloadExpr::l_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

Token OverloadExpr::name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

std::optional<CXXRecordDecl> OverloadExpr::naming_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal40();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token OverloadExpr::r_angle_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

Token OverloadExpr::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal42());
}

bool OverloadExpr::has_explicit_template_arguments(void) const {
  return impl->reader.getVal89();
}

bool OverloadExpr::has_template_keyword(void) const {
  return impl->reader.getVal90();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
