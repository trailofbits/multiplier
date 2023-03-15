// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/EnumConstantDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<EnumConstantDecl> EnumConstantDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = EnumConstantDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool EnumConstantDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : EnumConstantDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<EnumConstantDecl> EnumConstantDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = EnumConstantDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<EnumConstantDecl> EnumConstantDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<EnumConstantDecl> EnumConstantDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = EnumConstantDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<EnumConstantDecl> EnumConstantDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool EnumConstantDecl::contains(const Decl &decl) {
  for (auto &parent : EnumConstantDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool EnumConstantDecl::contains(const Stmt &stmt) {
  for (auto &parent : EnumConstantDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<EnumConstantDecl> EnumConstantDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<EnumConstantDecl> dr = EnumConstantDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<EnumConstantDecl> EnumConstantDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return EnumConstantDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kEnumConstantDeclDerivedKinds[] = {
    EnumConstantDecl::static_kind(),
};

std::optional<EnumConstantDecl> EnumConstantDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case EnumConstantDecl::static_kind():
      return reinterpret_cast<const EnumConstantDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<EnumConstantDecl> EnumConstantDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kEnumConstantDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<EnumConstantDecl> e = EnumConstantDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<EnumConstantDecl> EnumConstantDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kEnumConstantDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<EnumConstantDecl> e = EnumConstantDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<EnumConstantDecl> EnumConstantDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kEnumConstantDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<EnumConstantDecl> e = EnumConstantDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<EnumConstantDecl> EnumConstantDecl::from(const Reference &r) {
  return EnumConstantDecl::from(r.as_declaration());
}

std::optional<EnumConstantDecl> EnumConstantDecl::from(const TokenContext &t) {
  return EnumConstantDecl::from(t.as_declaration());
}

std::optional<Expr> EnumConstantDecl::initializer_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal53();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
