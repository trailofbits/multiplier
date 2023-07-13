// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CoreturnStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CoreturnStmt> CoreturnStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CoreturnStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CoreturnStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CoreturnStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CoreturnStmt> CoreturnStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CoreturnStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CoreturnStmt> CoreturnStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CoreturnStmt> CoreturnStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CoreturnStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CoreturnStmt> CoreturnStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CoreturnStmt::contains(const Decl &decl) {
  for (auto &parent : CoreturnStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CoreturnStmt::contains(const Stmt &stmt) {
  for (auto &parent : CoreturnStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CoreturnStmt> CoreturnStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CoreturnStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCoreturnStmtDerivedKinds[] = {
    CoreturnStmt::static_kind(),
};

std::optional<CoreturnStmt> CoreturnStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CoreturnStmt::static_kind():
      return reinterpret_cast<const CoreturnStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CoreturnStmt> CoreturnStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kCoreturnStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CoreturnStmt> e = CoreturnStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CoreturnStmt> CoreturnStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCoreturnStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CoreturnStmt> e = CoreturnStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CoreturnStmt> CoreturnStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCoreturnStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CoreturnStmt> e = CoreturnStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CoreturnStmt> CoreturnStmt::from(const Reference &r) {
  return CoreturnStmt::from(r.as_statement());
}

std::optional<CoreturnStmt> CoreturnStmt::from(const TokenContext &t) {
  return CoreturnStmt::from(t.as_statement());
}

Token CoreturnStmt::keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Expr CoreturnStmt::operand(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr CoreturnStmt::promise_call(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool CoreturnStmt::is_implicit(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
