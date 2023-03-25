// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ImplicitConceptSpecializationDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ImplicitConceptSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ImplicitConceptSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ImplicitConceptSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ImplicitConceptSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ImplicitConceptSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ImplicitConceptSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : ImplicitConceptSpecializationDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ImplicitConceptSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ImplicitConceptSpecializationDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

ImplicitConceptSpecializationDecl ImplicitConceptSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = ImplicitConceptSpecializationDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ImplicitConceptSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::definition(void) const {
  return ImplicitConceptSpecializationDecl::from(this->Decl::definition());
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ImplicitConceptSpecializationDecl> dr = ImplicitConceptSpecializationDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ImplicitConceptSpecializationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kImplicitConceptSpecializationDeclDerivedKinds[] = {
    ImplicitConceptSpecializationDecl::static_kind(),
};

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ImplicitConceptSpecializationDecl::static_kind():
      return reinterpret_cast<const ImplicitConceptSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kImplicitConceptSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ImplicitConceptSpecializationDecl> e = ImplicitConceptSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kImplicitConceptSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ImplicitConceptSpecializationDecl> e = ImplicitConceptSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kImplicitConceptSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ImplicitConceptSpecializationDecl> e = ImplicitConceptSpecializationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const Reference &r) {
  return ImplicitConceptSpecializationDecl::from(r.as_declaration());
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const TokenContext &t) {
  return ImplicitConceptSpecializationDecl::from(t.as_declaration());
}

unsigned ImplicitConceptSpecializationDecl::num_template_arguments(void) const {
  return impl->reader.getVal49().size();
}

std::optional<TemplateArgument> ImplicitConceptSpecializationDecl::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal49();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> ImplicitConceptSpecializationDecl::template_arguments(void) const & {
  auto list = impl->reader.getVal49();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d49 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d49));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
