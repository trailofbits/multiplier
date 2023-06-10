// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RedeclarableTemplateDecl.h>

#include <multiplier/Entities/ClassTemplateDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/FunctionTemplateDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeAliasTemplateDecl.h>
#include <multiplier/Entities/VarTemplateDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RedeclarableTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RedeclarableTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RedeclarableTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = RedeclarableTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = RedeclarableTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool RedeclarableTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : RedeclarableTemplateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool RedeclarableTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : RedeclarableTemplateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

RedeclarableTemplateDecl RedeclarableTemplateDecl::canonical_declaration(void) const {
  if (auto canon = RedeclarableTemplateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (RedeclarableTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::definition(void) const {
  return RedeclarableTemplateDecl::from(this->Decl::definition());
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<RedeclarableTemplateDecl> dr = RedeclarableTemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return RedeclarableTemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kRedeclarableTemplateDeclDerivedKinds[] = {
    TypeAliasTemplateDecl::static_kind(),
    VarTemplateDecl::static_kind(),
    ClassTemplateDecl::static_kind(),
    FunctionTemplateDecl::static_kind(),
};

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case TypeAliasTemplateDecl::static_kind():
    case VarTemplateDecl::static_kind():
    case ClassTemplateDecl::static_kind():
    case FunctionTemplateDecl::static_kind():
      return reinterpret_cast<const RedeclarableTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kRedeclarableTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<RedeclarableTemplateDecl> e = RedeclarableTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kRedeclarableTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<RedeclarableTemplateDecl> e = RedeclarableTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RedeclarableTemplateDecl> RedeclarableTemplateDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kRedeclarableTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<RedeclarableTemplateDecl> e = RedeclarableTemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const Reference &r) {
  return RedeclarableTemplateDecl::from(r.as_declaration());
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const TokenContext &t) {
  return RedeclarableTemplateDecl::from(t.as_declaration());
}

RedeclarableTemplateDecl RedeclarableTemplateDecl::instantiated_from_member_template(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return RedeclarableTemplateDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool RedeclarableTemplateDecl::is_member_specialization(void) const {
  return impl->reader.getVal74();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
