// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TranslationUnitDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TranslationUnitDecl> TranslationUnitDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TranslationUnitDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TranslationUnitDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TranslationUnitDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TranslationUnitDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TranslationUnitDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TranslationUnitDecl::contains(const Decl &decl) {
  for (auto &parent : TranslationUnitDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TranslationUnitDecl::contains(const Stmt &stmt) {
  for (auto &parent : TranslationUnitDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TranslationUnitDecl TranslationUnitDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TranslationUnitDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TranslationUnitDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kTranslationUnitDeclDerivedKinds[] = {
    TranslationUnitDecl::static_kind(),
};

}  // namespace

std::optional<TranslationUnitDecl> TranslationUnitDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case TranslationUnitDecl::static_kind():
      return reinterpret_cast<const TranslationUnitDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTranslationUnitDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TranslationUnitDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTranslationUnitDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TranslationUnitDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TranslationUnitDecl> TranslationUnitDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTranslationUnitDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TranslationUnitDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const Reference &r) {
  return TranslationUnitDecl::from(r.as_declaration());
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

gap::generator<Decl> TranslationUnitDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
  auto list = impl->reader.getVal51();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
