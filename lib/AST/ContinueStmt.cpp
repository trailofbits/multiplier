// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ContinueStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kContinueStmtDerivedKinds[] = {
    ContinueStmt::static_kind(),
};
}  // namespace

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

std::optional<ContinueStmt> ContinueStmt::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ContinueStmt, ir::hl::Operation>> ContinueStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kContinueStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ContinueStmt, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ContinueStmt> ContinueStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ContinueStmt> ContinueStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case ContinueStmt::static_kind():
      return reinterpret_cast<const ContinueStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ContinueStmt> ContinueStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kContinueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ContinueStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kContinueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ContinueStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ContinueStmt> ContinueStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kContinueStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ContinueStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ContinueStmt> ContinueStmt::from(const Reference &r) {
  return ContinueStmt::from(r.as_statement());
}

std::optional<ContinueStmt> ContinueStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<ContinueStmt> ContinueStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ContinueStmt::continue_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
