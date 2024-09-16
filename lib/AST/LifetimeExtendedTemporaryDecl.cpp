// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LifetimeExtendedTemporaryDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kLifetimeExtendedTemporaryDeclDerivedKinds[] = {
    LifetimeExtendedTemporaryDecl::static_kind(),
};
}  // namespace

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kLifetimeExtendedTemporaryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<LifetimeExtendedTemporaryDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kLifetimeExtendedTemporaryDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<LifetimeExtendedTemporaryDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kLifetimeExtendedTemporaryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<LifetimeExtendedTemporaryDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LifetimeExtendedTemporaryDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LifetimeExtendedTemporaryDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LifetimeExtendedTemporaryDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<LifetimeExtendedTemporaryDecl, ir::Operation>> LifetimeExtendedTemporaryDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kLifetimeExtendedTemporaryDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<LifetimeExtendedTemporaryDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LifetimeExtendedTemporaryDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LifetimeExtendedTemporaryDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LifetimeExtendedTemporaryDecl::contains(const Decl &decl) {
  for (auto &parent : LifetimeExtendedTemporaryDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LifetimeExtendedTemporaryDecl::contains(const Stmt &stmt) {
  for (auto &parent : LifetimeExtendedTemporaryDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

LifetimeExtendedTemporaryDecl LifetimeExtendedTemporaryDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (LifetimeExtendedTemporaryDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<LifetimeExtendedTemporaryDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case LifetimeExtendedTemporaryDecl::static_kind():
      return reinterpret_cast<const LifetimeExtendedTemporaryDecl &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const Reference &r) {
  return LifetimeExtendedTemporaryDecl::from(r.as_declaration());
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

gap::generator<Stmt> LifetimeExtendedTemporaryDecl::children(void) const & {
  auto list = impl->reader.getVal43();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d43 = ep->StmtFor(ep, v)) {
      co_yield Stmt(std::move(d43));
    }
  }
  co_return;
}

ValueDecl LifetimeExtendedTemporaryDecl::extending_declaration(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return ValueDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

uint32_t LifetimeExtendedTemporaryDecl::mangling_number(void) const {
  return impl->reader.getVal41();
}

StorageDuration LifetimeExtendedTemporaryDecl::storage_duration(void) const {
  return static_cast<StorageDuration>(impl->reader.getVal57());
}

Expr LifetimeExtendedTemporaryDecl::temporary_expression(void) const {
  RawEntityId eid = impl->reader.getVal48();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
