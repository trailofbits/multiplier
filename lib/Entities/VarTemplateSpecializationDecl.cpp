// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VarTemplateSpecializationDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueDecl.h>
#include <multiplier/Entities/VarDecl.h>
#include <multiplier/Entities/VarTemplateDecl.h>
#include <multiplier/Entities/VarTemplatePartialSpecializationDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VarTemplateSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VarTemplateSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VarTemplateSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool VarTemplateSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : VarTemplateSpecializationDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool VarTemplateSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : VarTemplateSpecializationDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<VarTemplateSpecializationDecl> dr = VarTemplateSpecializationDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return VarTemplateSpecializationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kVarTemplateSpecializationDeclDerivedKinds[] = {
    VarTemplateSpecializationDecl::static_kind(),
    VarTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case VarTemplateSpecializationDecl::static_kind():
    case VarTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const VarTemplateSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kVarTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<VarTemplateSpecializationDecl> e = VarTemplateSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kVarTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<VarTemplateSpecializationDecl> e = VarTemplateSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kVarTemplateSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<VarTemplateSpecializationDecl> e = VarTemplateSpecializationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const Reference &r) {
  return VarTemplateSpecializationDecl::from(r.as_declaration());
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const TokenContext &t) {
  return VarTemplateSpecializationDecl::from(t.as_declaration());
}

Token VarTemplateSpecializationDecl::extern_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal123());
}

TemplateSpecializationKind VarTemplateSpecializationDecl::specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal126());
}

VarTemplateDecl VarTemplateSpecializationDecl::specialized_template(void) const {
  RawEntityId eid = impl->reader.getVal124();
  return VarTemplateDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

unsigned VarTemplateSpecializationDecl::num_template_arguments(void) const {
  return impl->reader.getVal48().size();
}

std::optional<TemplateArgument> VarTemplateSpecializationDecl::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal48();
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

gap::generator<TemplateArgument> VarTemplateSpecializationDecl::template_arguments(void) const & {
  auto list = impl->reader.getVal48();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d48 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d48));
    }
  }
  co_return;
}

unsigned VarTemplateSpecializationDecl::num_template_instantiation_arguments(void) const {
  return impl->reader.getVal58().size();
}

std::optional<TemplateArgument> VarTemplateSpecializationDecl::nth_template_instantiation_argument(unsigned n) const {
  auto list = impl->reader.getVal58();
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

gap::generator<TemplateArgument> VarTemplateSpecializationDecl::template_instantiation_arguments(void) const & {
  auto list = impl->reader.getVal58();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d58 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d58));
    }
  }
  co_return;
}

Token VarTemplateSpecializationDecl::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal125());
}

Type VarTemplateSpecializationDecl::type_as_written(void) const {
  RawEntityId eid = impl->reader.getVal127();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool VarTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const {
  return impl->reader.getVal129();
}

bool VarTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const {
  return impl->reader.getVal130();
}

bool VarTemplateSpecializationDecl::is_explicit_specialization(void) const {
  return impl->reader.getVal131();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
