// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnresolvedUsingTypenameDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kUnresolvedUsingTypenameDeclDerivedKinds[] = {
    UnresolvedUsingTypenameDecl::static_kind(),
};
}  // namespace

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedUsingTypenameDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedUsingTypenameDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedUsingTypenameDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<UnresolvedUsingTypenameDecl, ir::Operation>> UnresolvedUsingTypenameDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kUnresolvedUsingTypenameDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<UnresolvedUsingTypenameDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingTypenameDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingTypenameDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedUsingTypenameDecl::contains(const Decl &decl) {
  for (auto &parent : UnresolvedUsingTypenameDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UnresolvedUsingTypenameDecl::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedUsingTypenameDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

UnresolvedUsingTypenameDecl UnresolvedUsingTypenameDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UnresolvedUsingTypenameDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UnresolvedUsingTypenameDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case UnresolvedUsingTypenameDecl::static_kind():
      return reinterpret_cast<const UnresolvedUsingTypenameDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kUnresolvedUsingTypenameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UnresolvedUsingTypenameDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUnresolvedUsingTypenameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedUsingTypenameDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUnresolvedUsingTypenameDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedUsingTypenameDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const Reference &r) {
  return UnresolvedUsingTypenameDecl::from(r.as_declaration());
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token UnresolvedUsingTypenameDecl::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal46());
}

Token UnresolvedUsingTypenameDecl::typename_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal47());
}

Token UnresolvedUsingTypenameDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal55());
}

bool UnresolvedUsingTypenameDecl::is_pack_expansion(void) const {
  return impl->reader.getVal64();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
