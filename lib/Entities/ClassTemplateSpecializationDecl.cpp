// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ClassTemplateSpecializationDecl.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/ClassTemplateDecl.h>
#include <multiplier/Entities/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ClassTemplateSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ClassTemplateSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ClassTemplateSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplateSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ClassTemplateSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : ClassTemplateSpecializationDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ClassTemplateSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ClassTemplateSpecializationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ClassTemplateSpecializationDecl ClassTemplateSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = ClassTemplateSpecializationDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ClassTemplateSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::definition(void) const {
  return ClassTemplateSpecializationDecl::from(this->Decl::definition());
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ClassTemplateSpecializationDecl> dr = ClassTemplateSpecializationDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ClassTemplateSpecializationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kClassTemplateSpecializationDeclDerivedKinds[] = {
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const ClassTemplateSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kClassTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ClassTemplateSpecializationDecl> e = ClassTemplateSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kClassTemplateSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ClassTemplateSpecializationDecl> e = ClassTemplateSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kClassTemplateSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ClassTemplateSpecializationDecl> e = ClassTemplateSpecializationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const Reference &r) {
  return ClassTemplateSpecializationDecl::from(r.as_declaration());
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const TokenContext &t) {
  return ClassTemplateSpecializationDecl::from(t.as_declaration());
}

Token ClassTemplateSpecializationDecl::extern_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal145());
}

Token ClassTemplateSpecializationDecl::point_of_instantiation(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal164());
}

TemplateSpecializationKind ClassTemplateSpecializationDecl::specialization_kind(void) const {
  return static_cast<TemplateSpecializationKind>(impl->reader.getVal94());
}

ClassTemplateDecl ClassTemplateSpecializationDecl::specialized_template(void) const {
  RawEntityId eid = impl->reader.getVal166();
  return ClassTemplateDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

unsigned ClassTemplateSpecializationDecl::num_template_arguments(void) const {
  return impl->reader.getVal353().size();
}

std::optional<TemplateArgument> ClassTemplateSpecializationDecl::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal353();
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

gap::generator<TemplateArgument> ClassTemplateSpecializationDecl::template_arguments(void) const & {
  auto list = impl->reader.getVal353();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d353 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d353));
    }
  }
  co_return;
}

unsigned ClassTemplateSpecializationDecl::num_template_instantiation_arguments(void) const {
  return impl->reader.getVal354().size();
}

std::optional<TemplateArgument> ClassTemplateSpecializationDecl::nth_template_instantiation_argument(unsigned n) const {
  auto list = impl->reader.getVal354();
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

gap::generator<TemplateArgument> ClassTemplateSpecializationDecl::template_instantiation_arguments(void) const & {
  auto list = impl->reader.getVal354();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d354 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d354));
    }
  }
  co_return;
}

Token ClassTemplateSpecializationDecl::template_keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal167());
}

std::optional<Type> ClassTemplateSpecializationDecl::type_as_written(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal177();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool ClassTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const {
  return impl->reader.getVal355();
}

bool ClassTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const {
  return impl->reader.getVal356();
}

bool ClassTemplateSpecializationDecl::is_explicit_specialization(void) const {
  return impl->reader.getVal357();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
