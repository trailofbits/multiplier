// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DoStmt.h>

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

gap::generator<DoStmt> DoStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DoStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DoStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DoStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<DoStmt> DoStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DoStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DoStmt> DoStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DoStmt> DoStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DoStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DoStmt> DoStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DoStmt::contains(const Decl &decl) {
  for (auto &parent : DoStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool DoStmt::contains(const Stmt &stmt) {
  for (auto &parent : DoStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<DoStmt> DoStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return DoStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kDoStmtDerivedKinds[] = {
    DoStmt::static_kind(),
};

std::optional<DoStmt> DoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case DoStmt::static_kind():
      return reinterpret_cast<const DoStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DoStmt> DoStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kDoStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DoStmt> e = DoStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DoStmt> DoStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDoStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DoStmt> e = DoStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DoStmt> DoStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDoStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DoStmt> e = DoStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DoStmt> DoStmt::from(const Reference &r) {
  return DoStmt::from(r.as_statement());
}

std::optional<DoStmt> DoStmt::from(const TokenContext &t) {
  return DoStmt::from(t.as_statement());
}

Stmt DoStmt::body(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr DoStmt::condition(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token DoStmt::do_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

Token DoStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal13());
}

Token DoStmt::while_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
