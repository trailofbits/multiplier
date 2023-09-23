// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConceptDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConceptDecl> ConceptDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConceptDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConceptDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConceptDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ConceptDecl> ConceptDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ConceptDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConceptDecl> ConceptDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ConceptDecl> ConceptDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ConceptDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConceptDecl> ConceptDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ConceptDecl::contains(const Decl &decl) {
  for (auto &parent : ConceptDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ConceptDecl::contains(const Stmt &stmt) {
  for (auto &parent : ConceptDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ConceptDecl ConceptDecl::canonical_declaration(void) const {
  if (auto canon = ConceptDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ConceptDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ConceptDecl> ConceptDecl::definition(void) const {
  return ConceptDecl::from(this->Decl::definition());
}

gap::generator<ConceptDecl> ConceptDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ConceptDecl> dr = ConceptDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ConceptDecl> ConceptDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ConceptDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kConceptDeclDerivedKinds[] = {
    ConceptDecl::static_kind(),
};

std::optional<ConceptDecl> ConceptDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ConceptDecl::static_kind():
      return reinterpret_cast<const ConceptDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConceptDecl> ConceptDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kConceptDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ConceptDecl> e = ConceptDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConceptDecl> ConceptDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kConceptDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ConceptDecl> e = ConceptDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConceptDecl> ConceptDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kConceptDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ConceptDecl> e = ConceptDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ConceptDecl> ConceptDecl::from(const Reference &r) {
  return ConceptDecl::from(r.as_declaration());
}

std::optional<ConceptDecl> ConceptDecl::from(const TokenContext &t) {
  return ConceptDecl::from(t.as_declaration());
}

Expr ConceptDecl::constraint_expression(void) const {
  RawEntityId eid = impl->reader.getVal61();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool ConceptDecl::is_type_concept(void) const {
  return impl->reader.getVal79();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
