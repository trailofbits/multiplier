// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ImaginaryLiteral.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ImaginaryLiteral> ImaginaryLiteral::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ImaginaryLiteral::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ImaginaryLiteral::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ImaginaryLiteral::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ImaginaryLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ImaginaryLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ImaginaryLiteral::contains(const Decl &decl) {
  for (auto &parent : ImaginaryLiteral::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ImaginaryLiteral::contains(const Stmt &stmt) {
  for (auto &parent : ImaginaryLiteral::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ImaginaryLiteral::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kImaginaryLiteralDerivedKinds[] = {
    ImaginaryLiteral::static_kind(),
};

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ImaginaryLiteral::static_kind():
      return reinterpret_cast<const ImaginaryLiteral &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kImaginaryLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ImaginaryLiteral> e = ImaginaryLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kImaginaryLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ImaginaryLiteral> e = ImaginaryLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImaginaryLiteral> ImaginaryLiteral::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kImaginaryLiteralDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ImaginaryLiteral> e = ImaginaryLiteral::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const Reference &r) {
  return ImaginaryLiteral::from(r.as_statement());
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const TokenContext &t) {
  return ImaginaryLiteral::from(t.as_statement());
}

Expr ImaginaryLiteral::sub_expression(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
