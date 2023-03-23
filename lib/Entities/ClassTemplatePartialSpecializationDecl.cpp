// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ClassTemplatePartialSpecializationDecl.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/ClassTemplateSpecializationDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ClassTemplatePartialSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ClassTemplatePartialSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ClassTemplatePartialSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplatePartialSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplatePartialSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ClassTemplatePartialSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : ClassTemplatePartialSpecializationDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ClassTemplatePartialSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ClassTemplatePartialSpecializationDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ClassTemplatePartialSpecializationDecl> dr = ClassTemplatePartialSpecializationDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ClassTemplatePartialSpecializationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kClassTemplatePartialSpecializationDeclDerivedKinds[] = {
    ClassTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const ClassTemplatePartialSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kClassTemplatePartialSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ClassTemplatePartialSpecializationDecl> e = ClassTemplatePartialSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kClassTemplatePartialSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ClassTemplatePartialSpecializationDecl> e = ClassTemplatePartialSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kClassTemplatePartialSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ClassTemplatePartialSpecializationDecl> e = ClassTemplatePartialSpecializationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const Reference &r) {
  return ClassTemplatePartialSpecializationDecl::from(r.as_declaration());
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const TokenContext &t) {
  return ClassTemplatePartialSpecializationDecl::from(t.as_declaration());
}

Type ClassTemplatePartialSpecializationDecl::injected_specialization_type(void) const {
  RawEntityId eid = impl->reader.getVal142();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::instantiated_from_member(void) const {
  RawEntityId eid = impl->reader.getVal143();
  return ClassTemplatePartialSpecializationDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::instantiated_from_member_template(void) const {
  RawEntityId eid = impl->reader.getVal144();
  return ClassTemplatePartialSpecializationDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

TemplateParameterList ClassTemplatePartialSpecializationDecl::template_parameters(void) const {
  RawEntityId eid = impl->reader.getVal163();
  return TemplateParameterList(impl->ep->TemplateParameterListFor(impl->ep, eid));
}

bool ClassTemplatePartialSpecializationDecl::has_associated_constraints(void) const {
  return impl->reader.getVal346();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
