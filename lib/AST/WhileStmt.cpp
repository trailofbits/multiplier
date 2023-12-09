// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/WhileStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclStmt.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/VarDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kWhileStmtDerivedKinds[] = {
    WhileStmt::static_kind(),
};
}  // namespace

gap::generator<WhileStmt> WhileStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = WhileStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool WhileStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : WhileStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<WhileStmt> WhileStmt::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<WhileStmt, ir::hl::Operation>> WhileStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kWhileStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<WhileStmt, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<WhileStmt> WhileStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = WhileStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<WhileStmt> WhileStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<WhileStmt> WhileStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = WhileStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<WhileStmt> WhileStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool WhileStmt::contains(const Decl &decl) {
  for (auto &parent : WhileStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool WhileStmt::contains(const Stmt &stmt) {
  for (auto &parent : WhileStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<WhileStmt> WhileStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<WhileStmt> WhileStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<WhileStmt> WhileStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case WhileStmt::static_kind():
      return reinterpret_cast<const WhileStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<WhileStmt> WhileStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kWhileStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<WhileStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<WhileStmt> WhileStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kWhileStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<WhileStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<WhileStmt> WhileStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kWhileStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<WhileStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<WhileStmt> WhileStmt::from(const Reference &r) {
  return WhileStmt::from(r.as_statement());
}

std::optional<WhileStmt> WhileStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<WhileStmt> WhileStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Stmt WhileStmt::body(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr WhileStmt::condition(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

std::optional<VarDecl> WhileStmt::condition_variable(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<DeclStmt> WhileStmt::condition_variable_declaration_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal13();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return DeclStmt::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token WhileStmt::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

Token WhileStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal17());
}

Token WhileStmt::while_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal18());
}

bool WhileStmt::has_variable_storage(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
