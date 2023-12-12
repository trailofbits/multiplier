// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AccessSpecDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kAccessSpecDeclDerivedKinds[] = {
    AccessSpecDecl::static_kind(),
};
}  // namespace

gap::generator<AccessSpecDecl> AccessSpecDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AccessSpecDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AccessSpecDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AccessSpecDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

#ifndef MX_DISABLE_VAST
std::optional<AccessSpecDecl> AccessSpecDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<AccessSpecDecl, ir::Operation>> AccessSpecDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kAccessSpecDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<AccessSpecDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

gap::generator<AccessSpecDecl> AccessSpecDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = AccessSpecDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AccessSpecDecl> AccessSpecDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AccessSpecDecl> AccessSpecDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = AccessSpecDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AccessSpecDecl> AccessSpecDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AccessSpecDecl::contains(const Decl &decl) {
  for (auto &parent : AccessSpecDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool AccessSpecDecl::contains(const Stmt &stmt) {
  for (auto &parent : AccessSpecDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

AccessSpecDecl AccessSpecDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (AccessSpecDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<AccessSpecDecl> AccessSpecDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<AccessSpecDecl> AccessSpecDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<AccessSpecDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<AccessSpecDecl> AccessSpecDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<AccessSpecDecl> AccessSpecDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<AccessSpecDecl> AccessSpecDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case AccessSpecDecl::static_kind():
      return reinterpret_cast<const AccessSpecDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AccessSpecDecl> AccessSpecDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kAccessSpecDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<AccessSpecDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AccessSpecDecl> AccessSpecDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kAccessSpecDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<AccessSpecDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AccessSpecDecl> AccessSpecDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kAccessSpecDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<AccessSpecDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AccessSpecDecl> AccessSpecDecl::from(const Reference &r) {
  return AccessSpecDecl::from(r.as_declaration());
}

std::optional<AccessSpecDecl> AccessSpecDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<AccessSpecDecl> AccessSpecDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token AccessSpecDecl::access_specifier_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal49());
}

Token AccessSpecDecl::colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal56());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
