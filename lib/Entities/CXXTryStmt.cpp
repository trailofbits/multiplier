// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXTryStmt.h>

#include <multiplier/Entities/CXXCatchStmt.h>
#include <multiplier/Entities/CompoundStmt.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXTryStmt> CXXTryStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXTryStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXTryStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXTryStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXTryStmt> CXXTryStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXTryStmt> CXXTryStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXTryStmt> CXXTryStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CXXTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXTryStmt> CXXTryStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXTryStmt::contains(const Decl &decl) {
  for (auto &parent : CXXTryStmt::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXTryStmt::contains(const Stmt &stmt) {
  for (auto &parent : CXXTryStmt::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<CXXTryStmt> CXXTryStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CXXTryStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCXXTryStmtDerivedKinds[] = {
    CXXTryStmt::static_kind(),
};

std::optional<CXXTryStmt> CXXTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CXXTryStmt::static_kind():
      return reinterpret_cast<const CXXTryStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXTryStmt> CXXTryStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCXXTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CXXTryStmt> e = CXXTryStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXTryStmt> CXXTryStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCXXTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CXXTryStmt> e = CXXTryStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXTryStmt> CXXTryStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCXXTryStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CXXTryStmt> e = CXXTryStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

CompoundStmt CXXTryStmt::try_block(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return CompoundStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token CXXTryStmt::try_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

std::optional<CXXCatchStmt> CXXTryStmt::nth_handler(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return CXXCatchStmt::from(Stmt(std::move(e)));
}

gap::generator<CXXCatchStmt> CXXTryStmt::handlers(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = CXXCatchStmt::from(Stmt(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
