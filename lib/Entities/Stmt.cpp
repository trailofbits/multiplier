// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Stmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/File.h>
#include <multiplier/Entities/Fragment.h>
#include <multiplier/Entities/Index.h>
#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::optional<Decl> Stmt::parent_declaration(void) const {
  if (auto id = impl->reader.getVal0(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

std::optional<Stmt> Stmt::parent_statement(void) const {
  if (auto id = impl->reader.getVal1(); id != kInvalidEntityId) {
    if (auto eptr = impl->ep->StmtFor(impl->ep, id)) {
      return Stmt(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}
std::shared_ptr<EntityProvider> Stmt::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Stmt::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Stmt::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

std::optional<PackedDeclId> Stmt::referenced_declaration_id(void) const {
  if (auto id = impl->reader.getVal2();
      id != kInvalidEntityId) {
    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<DeclId>(vid)) {
      return std::get<DeclId>(vid);
    }
    assert(false);
  }
  return std::nullopt;
}

std::optional<Decl> Stmt::referenced_declaration(void) const {
  if (auto id = impl->reader.getVal2();
      id != kInvalidEntityId) {
    if (auto eptr = impl->ep->DeclFor(impl->ep, id)) {
      return Decl(std::move(eptr));
    }
    assert(false);
  }
  return std::nullopt;
}

gap::generator<Stmt> Stmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = Stmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool Stmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : Stmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<Stmt> Stmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = Stmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<Stmt> Stmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<Stmt> Stmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = Stmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<Stmt> Stmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool Stmt::contains(const Decl &decl) {
  for (auto &parent : Stmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool Stmt::contains(const Stmt &stmt) {
  for (auto &parent : Stmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<Stmt> Stmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    index.statement(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

gap::generator<Stmt> Stmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtImplPtr eptr : ep->StmtsFor(ep)) {
    if (std::optional<Stmt> e = Stmt::from(Stmt(std::move(eptr)))) {
      co_yield std::move(e.value());
    }
  }
}

gap::generator<Stmt> Stmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtImplPtr eptr : ep->StmtsFor(ep, frag_id)) {
    if (std::optional<Stmt> e = Stmt::from(Stmt(std::move(eptr)))) {
      co_yield std::move(e.value());
    }
  }
}

gap::generator<Stmt> Stmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, frag_id)) {
      if (std::optional<Stmt> e = Stmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<Stmt> Stmt::in(const Index &index, std::span<StmtKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      co_yield Stmt(std::move(eptr));
    }
  }
}

gap::generator<Stmt> Stmt::in(const Fragment &frag, std::span<StmtKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      co_yield Stmt(std::move(eptr));
    }
  }
}

gap::generator<Stmt> Stmt::in(const File &file, std::span<StmtKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        co_yield Stmt(std::move(eptr));
      }
    }
  }
}

std::optional<Stmt> Stmt::from(const Reference &r) {
  return r.as_statement();
}

std::optional<Stmt> Stmt::from(const TokenContext &t) {
  return t.as_statement();
}

Stmt Stmt::ignore_containers(void) const {
  RawEntityId eid = impl->reader.getVal3();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

gap::generator<Stmt> Stmt::children(void) const & {
  auto list = impl->reader.getVal4();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d4 = ep->StmtFor(ep, v)) {
      co_yield Stmt(std::move(d4));
    }
  }
  co_return;
}

TokenRange Stmt::tokens(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal5(), impl->reader.getVal6());
}

StmtKind Stmt::kind(void) const {
  return static_cast<StmtKind>(impl->reader.getVal7());
}

Stmt Stmt::strip_label_like_statements(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
