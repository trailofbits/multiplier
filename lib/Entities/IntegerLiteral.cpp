// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IntegerLiteral.h>

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

gap::generator<IntegerLiteral> IntegerLiteral::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = IntegerLiteral::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool IntegerLiteral::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : IntegerLiteral::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IntegerLiteral> IntegerLiteral::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = IntegerLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<IntegerLiteral> IntegerLiteral::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<IntegerLiteral> IntegerLiteral::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = IntegerLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<IntegerLiteral> IntegerLiteral::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool IntegerLiteral::contains(const Decl &decl) {
  for (auto &parent : IntegerLiteral::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool IntegerLiteral::contains(const Stmt &stmt) {
  for (auto &parent : IntegerLiteral::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<IntegerLiteral> IntegerLiteral::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return IntegerLiteral::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kIntegerLiteralDerivedKinds[] = {
    IntegerLiteral::static_kind(),
};

std::optional<IntegerLiteral> IntegerLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case IntegerLiteral::static_kind():
      return reinterpret_cast<const IntegerLiteral &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IntegerLiteral> IntegerLiteral::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kIntegerLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<IntegerLiteral> e = IntegerLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IntegerLiteral> IntegerLiteral::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kIntegerLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<IntegerLiteral> e = IntegerLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IntegerLiteral> IntegerLiteral::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kIntegerLiteralDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<IntegerLiteral> e = IntegerLiteral::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IntegerLiteral> IntegerLiteral::from(const Reference &r) {
  return IntegerLiteral::from(r.as_statement());
}

std::optional<IntegerLiteral> IntegerLiteral::from(const TokenContext &t) {
  return IntegerLiteral::from(t.as_statement());
}

Token IntegerLiteral::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
