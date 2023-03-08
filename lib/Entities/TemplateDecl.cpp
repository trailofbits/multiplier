// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateDecl.h>

#include <multiplier/Entities/BuiltinTemplateDecl.h>
#include <multiplier/Entities/ClassTemplateDecl.h>
#include <multiplier/Entities/ConceptDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/FunctionTemplateDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/TemplateTemplateParmDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeAliasTemplateDecl.h>
#include <multiplier/Entities/VarTemplateDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TemplateDecl> TemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TemplateDecl> TemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TemplateDecl::contains(const Decl &decl) {
  for (auto &parent : TemplateDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool TemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : TemplateDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<TemplateDecl> TemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TemplateDecl> dr = TemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TemplateDecl> TemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return TemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kTemplateDeclDerivedKinds[] = {
    TemplateTemplateParmDecl::static_kind(),
    BuiltinTemplateDecl::static_kind(),
    ConceptDecl::static_kind(),
    TypeAliasTemplateDecl::static_kind(),
    VarTemplateDecl::static_kind(),
    ClassTemplateDecl::static_kind(),
    FunctionTemplateDecl::static_kind(),
};

std::optional<TemplateDecl> TemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case TemplateTemplateParmDecl::static_kind():
    case BuiltinTemplateDecl::static_kind():
    case ConceptDecl::static_kind():
    case TypeAliasTemplateDecl::static_kind():
    case VarTemplateDecl::static_kind():
    case ClassTemplateDecl::static_kind():
    case FunctionTemplateDecl::static_kind():
      return reinterpret_cast<const TemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TemplateDecl> TemplateDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TemplateDecl> e = TemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TemplateDecl> e = TemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TemplateDecl> e = TemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

TemplateParameterList TemplateDecl::template_parameters(void) const {
  RawEntityId eid = impl->reader.getVal52();
  return TemplateParameterList(impl->ep->TemplateParameterListFor(impl->ep, eid));
}

NamedDecl TemplateDecl::templated_declaration(void) const {
  RawEntityId eid = impl->reader.getVal53();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool TemplateDecl::has_associated_constraints(void) const {
  return impl->reader.getVal70();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
