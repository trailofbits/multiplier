// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ImplicitParamDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
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

gap::generator<ImplicitParamDecl> ImplicitParamDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ImplicitParamDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ImplicitParamDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ImplicitParamDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ImplicitParamDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ImplicitParamDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ImplicitParamDecl::contains(const Decl &decl) {
  for (auto &parent : ImplicitParamDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ImplicitParamDecl::contains(const Stmt &stmt) {
  for (auto &parent : ImplicitParamDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ImplicitParamDecl> dr = ImplicitParamDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ImplicitParamDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kImplicitParamDeclDerivedKinds[] = {
    ImplicitParamDecl::static_kind(),
};

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ImplicitParamDecl::static_kind():
      return reinterpret_cast<const ImplicitParamDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kImplicitParamDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ImplicitParamDecl> e = ImplicitParamDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kImplicitParamDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ImplicitParamDecl> e = ImplicitParamDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImplicitParamDecl> ImplicitParamDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kImplicitParamDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ImplicitParamDecl> e = ImplicitParamDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const Reference &r) {
  return ImplicitParamDecl::from(r.as_declaration());
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const TokenContext &t) {
  return ImplicitParamDecl::from(t.as_declaration());
}

ImplicitParamDeclImplicitParamKind ImplicitParamDecl::parameter_kind(void) const {
  return static_cast<ImplicitParamDeclImplicitParamKind>(impl->reader.getVal128());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
