// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DefaultStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/SwitchCase.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kDefaultStmtDerivedKinds[] = {
    DefaultStmt::static_kind(),
};
}  // namespace

gap::generator<DefaultStmt> DefaultStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DefaultStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DefaultStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DefaultStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DefaultStmt> DefaultStmt::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<DefaultStmt, ir::hl::Operation>> DefaultStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kDefaultStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<DefaultStmt, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<DefaultStmt> DefaultStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DefaultStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DefaultStmt> DefaultStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<DefaultStmt> DefaultStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = DefaultStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<DefaultStmt> DefaultStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool DefaultStmt::contains(const Decl &decl) {
  for (auto &parent : DefaultStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool DefaultStmt::contains(const Stmt &stmt) {
  for (auto &parent : DefaultStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<DefaultStmt> DefaultStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<DefaultStmt> DefaultStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DefaultStmt> DefaultStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case DefaultStmt::static_kind():
      return reinterpret_cast<const DefaultStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DefaultStmt> DefaultStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kDefaultStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<DefaultStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DefaultStmt> DefaultStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kDefaultStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<DefaultStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DefaultStmt> DefaultStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kDefaultStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<DefaultStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DefaultStmt> DefaultStmt::from(const Reference &r) {
  return DefaultStmt::from(r.as_statement());
}

std::optional<DefaultStmt> DefaultStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<DefaultStmt> DefaultStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token DefaultStmt::default_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
