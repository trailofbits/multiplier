// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BindingDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BindingDecl> BindingDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BindingDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BindingDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BindingDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<BindingDecl> BindingDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BindingDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BindingDecl> BindingDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<BindingDecl> BindingDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BindingDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BindingDecl> BindingDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool BindingDecl::contains(const Decl &decl) {
  for (auto &parent : BindingDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool BindingDecl::contains(const Stmt &stmt) {
  for (auto &parent : BindingDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<BindingDecl> BindingDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<BindingDecl> dr = BindingDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<BindingDecl> BindingDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return BindingDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kBindingDeclDerivedKinds[] = {
    BindingDecl::static_kind(),
};

std::optional<BindingDecl> BindingDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case BindingDecl::static_kind():
      return reinterpret_cast<const BindingDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BindingDecl> BindingDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kBindingDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<BindingDecl> e = BindingDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BindingDecl> BindingDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kBindingDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<BindingDecl> e = BindingDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BindingDecl> BindingDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kBindingDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<BindingDecl> e = BindingDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BindingDecl> BindingDecl::from(const Reference &r) {
  return BindingDecl::from(r.as_declaration());
}

std::optional<BindingDecl> BindingDecl::from(const TokenContext &t) {
  return BindingDecl::from(t.as_declaration());
}

Expr BindingDecl::binding(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ValueDecl BindingDecl::decomposed_declaration(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return ValueDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

VarDecl BindingDecl::holding_variable(void) const {
  RawEntityId eid = impl->reader.getVal64();
  return VarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
