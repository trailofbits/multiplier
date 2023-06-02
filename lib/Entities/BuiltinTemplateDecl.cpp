// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BuiltinTemplateDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BuiltinTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BuiltinTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BuiltinTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BuiltinTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BuiltinTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool BuiltinTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : BuiltinTemplateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool BuiltinTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : BuiltinTemplateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

BuiltinTemplateDecl BuiltinTemplateDecl::canonical_declaration(void) const {
  if (auto canon = BuiltinTemplateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (BuiltinTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::definition(void) const {
  return BuiltinTemplateDecl::from(this->Decl::definition());
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<BuiltinTemplateDecl> dr = BuiltinTemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return BuiltinTemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kBuiltinTemplateDeclDerivedKinds[] = {
    BuiltinTemplateDecl::static_kind(),
};

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case BuiltinTemplateDecl::static_kind():
      return reinterpret_cast<const BuiltinTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kBuiltinTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<BuiltinTemplateDecl> e = BuiltinTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kBuiltinTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<BuiltinTemplateDecl> e = BuiltinTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BuiltinTemplateDecl> BuiltinTemplateDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kBuiltinTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<BuiltinTemplateDecl> e = BuiltinTemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const Reference &r) {
  return BuiltinTemplateDecl::from(r.as_declaration());
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const TokenContext &t) {
  return BuiltinTemplateDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
