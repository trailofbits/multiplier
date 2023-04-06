// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FunctionTemplateDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/RedeclarableTemplateDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FunctionTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FunctionTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FunctionTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : FunctionTemplateDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool FunctionTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : FunctionTemplateDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

FunctionTemplateDecl FunctionTemplateDecl::canonical_declaration(void) const {
  if (auto canon = FunctionTemplateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FunctionTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::definition(void) const {
  return FunctionTemplateDecl::from(this->Decl::definition());
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FunctionTemplateDecl> dr = FunctionTemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return FunctionTemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kFunctionTemplateDeclDerivedKinds[] = {
    FunctionTemplateDecl::static_kind(),
};

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case FunctionTemplateDecl::static_kind():
      return reinterpret_cast<const FunctionTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kFunctionTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FunctionTemplateDecl> e = FunctionTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFunctionTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FunctionTemplateDecl> e = FunctionTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFunctionTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FunctionTemplateDecl> e = FunctionTemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const Reference &r) {
  return FunctionTemplateDecl::from(r.as_declaration());
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const TokenContext &t) {
  return FunctionTemplateDecl::from(t.as_declaration());
}

bool FunctionTemplateDecl::is_abbreviated(void) const {
  return impl->reader.getVal75();
}

bool FunctionTemplateDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal92();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
