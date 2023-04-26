// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ContinueStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ContinueStmt> ContinueStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ContinueStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ContinueStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ContinueStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ContinueStmt> ContinueStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ContinueStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ContinueStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ContinueStmt::contains(const Decl &decl) {
  for (auto &parent : ContinueStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ContinueStmt::contains(const Stmt &stmt) {
  for (auto &parent : ContinueStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ContinueStmt> ContinueStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ContinueStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kContinueStmtDerivedKinds[] = {
    ContinueStmt::static_kind(),
};

std::optional<ContinueStmt> ContinueStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ContinueStmt::static_kind():
      return reinterpret_cast<const ContinueStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ContinueStmt> ContinueStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kContinueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ContinueStmt> e = ContinueStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kContinueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ContinueStmt> e = ContinueStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kContinueStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ContinueStmt> e = ContinueStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ContinueStmt> ContinueStmt::from(const Reference &r) {
  return ContinueStmt::from(r.as_statement());
}

std::optional<ContinueStmt> ContinueStmt::from(const TokenContext &t) {
  return ContinueStmt::from(t.as_statement());
}

Token ContinueStmt::continue_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
