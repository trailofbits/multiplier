// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SwitchStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclStmt.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/SwitchCase.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/VarDecl.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SwitchStmt> SwitchStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SwitchStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SwitchStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SwitchStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SwitchStmt> SwitchStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SwitchStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SwitchStmt> SwitchStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SwitchStmt> SwitchStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SwitchStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SwitchStmt> SwitchStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SwitchStmt::contains(const Decl &decl) {
  for (auto &parent : SwitchStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SwitchStmt::contains(const Stmt &stmt) {
  for (auto &parent : SwitchStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SwitchStmt> SwitchStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SwitchStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSwitchStmtDerivedKinds[] = {
    SwitchStmt::static_kind(),
};

std::optional<SwitchStmt> SwitchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case SwitchStmt::static_kind():
      return reinterpret_cast<const SwitchStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SwitchStmt> SwitchStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kSwitchStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SwitchStmt> e = SwitchStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwitchStmt> SwitchStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSwitchStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SwitchStmt> e = SwitchStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwitchStmt> SwitchStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSwitchStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SwitchStmt> e = SwitchStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SwitchStmt> SwitchStmt::from(const Reference &r) {
  return SwitchStmt::from(r.as_statement());
}

std::optional<SwitchStmt> SwitchStmt::from(const TokenContext &t) {
  return SwitchStmt::from(t.as_statement());
}

Stmt SwitchStmt::body(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr SwitchStmt::condition(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

std::optional<VarDecl> SwitchStmt::condition_variable(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return VarDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<DeclStmt> SwitchStmt::condition_variable_declaration_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal13();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return DeclStmt::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<Stmt> SwitchStmt::initializer(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal14();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Stmt(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token SwitchStmt::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal17());
}

Token SwitchStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal18());
}

std::optional<SwitchCase> SwitchStmt::first_switch_case(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal19();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return SwitchCase::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token SwitchStmt::switch_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal20());
}

bool SwitchStmt::has_initializer_storage(void) const {
  return impl->reader.getVal12();
}

bool SwitchStmt::has_variable_storage(void) const {
  return impl->reader.getVal16();
}

bool SwitchStmt::is_all_enum_cases_covered(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
