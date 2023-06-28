// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SEHExceptStmt.h>

#include <multiplier/Entities/CompoundStmt.h>
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

gap::generator<SEHExceptStmt> SEHExceptStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SEHExceptStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SEHExceptStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SEHExceptStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SEHExceptStmt> SEHExceptStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHExceptStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHExceptStmt> SEHExceptStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SEHExceptStmt> SEHExceptStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SEHExceptStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SEHExceptStmt> SEHExceptStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SEHExceptStmt::contains(const Decl &decl) {
  for (auto &parent : SEHExceptStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SEHExceptStmt::contains(const Stmt &stmt) {
  for (auto &parent : SEHExceptStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SEHExceptStmt> SEHExceptStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SEHExceptStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSEHExceptStmtDerivedKinds[] = {
    SEHExceptStmt::static_kind(),
};

std::optional<SEHExceptStmt> SEHExceptStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case SEHExceptStmt::static_kind():
      return reinterpret_cast<const SEHExceptStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SEHExceptStmt> SEHExceptStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kSEHExceptStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SEHExceptStmt> e = SEHExceptStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHExceptStmt> SEHExceptStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSEHExceptStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SEHExceptStmt> e = SEHExceptStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SEHExceptStmt> SEHExceptStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSEHExceptStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SEHExceptStmt> e = SEHExceptStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SEHExceptStmt> SEHExceptStmt::from(const Reference &r) {
  return SEHExceptStmt::from(r.as_statement());
}

std::optional<SEHExceptStmt> SEHExceptStmt::from(const TokenContext &t) {
  return SEHExceptStmt::from(t.as_statement());
}

CompoundStmt SEHExceptStmt::block(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return CompoundStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token SEHExceptStmt::except_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

Expr SEHExceptStmt::filter_expression(void) const {
  RawEntityId eid = impl->reader.getVal12();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
