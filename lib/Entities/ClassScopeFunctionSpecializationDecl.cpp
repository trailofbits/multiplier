// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ClassScopeFunctionSpecializationDecl.h>

#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ClassScopeFunctionSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ClassScopeFunctionSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ClassScopeFunctionSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassScopeFunctionSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ClassScopeFunctionSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ClassScopeFunctionSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : ClassScopeFunctionSpecializationDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ClassScopeFunctionSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ClassScopeFunctionSpecializationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ClassScopeFunctionSpecializationDecl ClassScopeFunctionSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = ClassScopeFunctionSpecializationDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ClassScopeFunctionSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::definition(void) const {
  return ClassScopeFunctionSpecializationDecl::from(this->Decl::definition());
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ClassScopeFunctionSpecializationDecl> dr = ClassScopeFunctionSpecializationDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ClassScopeFunctionSpecializationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kClassScopeFunctionSpecializationDeclDerivedKinds[] = {
    ClassScopeFunctionSpecializationDecl::static_kind(),
};

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ClassScopeFunctionSpecializationDecl::static_kind():
      return reinterpret_cast<const ClassScopeFunctionSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kClassScopeFunctionSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ClassScopeFunctionSpecializationDecl> e = ClassScopeFunctionSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kClassScopeFunctionSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ClassScopeFunctionSpecializationDecl> e = ClassScopeFunctionSpecializationDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kClassScopeFunctionSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ClassScopeFunctionSpecializationDecl> e = ClassScopeFunctionSpecializationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::from(const Reference &r) {
  return ClassScopeFunctionSpecializationDecl::from(r.as_declaration());
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::from(const TokenContext &t) {
  return ClassScopeFunctionSpecializationDecl::from(t.as_declaration());
}

CXXMethodDecl ClassScopeFunctionSpecializationDecl::specialization(void) const {
  RawEntityId eid = impl->reader.getVal49();
  return CXXMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool ClassScopeFunctionSpecializationDecl::has_explicit_template_arguments(void) const {
  return impl->reader.getVal50();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
