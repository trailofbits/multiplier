// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ClassTemplateDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/RedeclarableTemplateDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ClassTemplateDecl> ClassTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ClassTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ClassTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ClassTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ClassTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : ClassTemplateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ClassTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : ClassTemplateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ClassTemplateDecl ClassTemplateDecl::canonical_declaration(void) const {
  if (auto canon = ClassTemplateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ClassTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::definition(void) const {
  return ClassTemplateDecl::from(this->Decl::definition());
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ClassTemplateDecl> dr = ClassTemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ClassTemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kClassTemplateDeclDerivedKinds[] = {
    ClassTemplateDecl::static_kind(),
};

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ClassTemplateDecl::static_kind():
      return reinterpret_cast<const ClassTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kClassTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ClassTemplateDecl> e = ClassTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kClassTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ClassTemplateDecl> e = ClassTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassTemplateDecl> ClassTemplateDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kClassTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ClassTemplateDecl> e = ClassTemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const Reference &r) {
  return ClassTemplateDecl::from(r.as_declaration());
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const TokenContext &t) {
  return ClassTemplateDecl::from(t.as_declaration());
}

bool ClassTemplateDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal75();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
