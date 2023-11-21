// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/IfStmt.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclStmt.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/VarDecl.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IfStmt> IfStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = IfStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool IfStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : IfStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<IfStmt> IfStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = IfStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<IfStmt> IfStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<IfStmt> IfStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = IfStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<IfStmt> IfStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool IfStmt::contains(const Decl &decl) {
  for (auto &parent : IfStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool IfStmt::contains(const Stmt &stmt) {
  for (auto &parent : IfStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<IfStmt> IfStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<IfStmt> IfStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kIfStmtDerivedKinds[] = {
    IfStmt::static_kind(),
};

}  // namespace

std::optional<IfStmt> IfStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case IfStmt::static_kind():
      return reinterpret_cast<const IfStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IfStmt> IfStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kIfStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<IfStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IfStmt> IfStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kIfStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<IfStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IfStmt> IfStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kIfStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<IfStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<IfStmt> IfStmt::from(const Reference &r) {
  return IfStmt::from(r.as_statement());
}

std::optional<IfStmt> IfStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<IfStmt> IfStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr IfStmt::condition(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

std::optional<VarDecl> IfStmt::condition_variable(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal10();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<DeclStmt> IfStmt::condition_variable_declaration_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return DeclStmt::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Stmt> IfStmt::else_(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal13();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token IfStmt::else_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

Token IfStmt::if_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal17());
}

std::optional<Stmt> IfStmt::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal18();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token IfStmt::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal19());
}

std::optional<Stmt> IfStmt::nondiscarded_case(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal20();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token IfStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal21());
}

IfStatementKind IfStmt::statement_kind(void) const {
  return static_cast<IfStatementKind>(impl->reader.getVal56());
}

Stmt IfStmt::then(void) const {
  RawEntityId eid = impl->reader.getVal22();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

bool IfStmt::has_else_storage(void) const {
  return impl->reader.getVal12();
}

bool IfStmt::has_initializer_storage(void) const {
  return impl->reader.getVal16();
}

bool IfStmt::has_variable_storage(void) const {
  return impl->reader.getVal23();
}

bool IfStmt::is_consteval(void) const {
  return impl->reader.getVal24();
}

bool IfStmt::is_constexpr(void) const {
  return impl->reader.getVal25();
}

bool IfStmt::is_negated_consteval(void) const {
  return impl->reader.getVal57();
}

bool IfStmt::is_non_negated_consteval(void) const {
  return impl->reader.getVal58();
}

bool IfStmt::is_obj_c_availability_check(void) const {
  return impl->reader.getVal59();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
