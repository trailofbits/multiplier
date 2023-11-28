// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ImplicitConceptSpecializationDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool ImplicitConceptSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ImplicitConceptSpecializationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ImplicitConceptSpecializationDecl ImplicitConceptSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ImplicitConceptSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ImplicitConceptSpecializationDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kImplicitConceptSpecializationDeclDerivedKinds[] = {
    ImplicitConceptSpecializationDecl::static_kind(),
};

}  // namespace

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ImplicitConceptSpecializationDecl::static_kind():
      return reinterpret_cast<const ImplicitConceptSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kImplicitConceptSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ImplicitConceptSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kImplicitConceptSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ImplicitConceptSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kImplicitConceptSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ImplicitConceptSpecializationDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const Reference &r) {
  return ImplicitConceptSpecializationDecl::from(r.as_declaration());
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ImplicitConceptSpecializationDecl> ImplicitConceptSpecializationDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned ImplicitConceptSpecializationDecl::num_template_arguments(void) const {
  return impl->reader.getVal51().size();
}

std::optional<TemplateArgument> ImplicitConceptSpecializationDecl::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal51();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> ImplicitConceptSpecializationDecl::template_arguments(void) const & {
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d51));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
