// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LinkageSpecDecl.h>
#include "../Reference.h"
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
static const DeclKind kLinkageSpecDeclDerivedKinds[] = {
    LinkageSpecDecl::static_kind(),
};
}  // namespace

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LinkageSpecDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LinkageSpecDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LinkageSpecDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<LinkageSpecDecl, ir::Operation>> LinkageSpecDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kLinkageSpecDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<LinkageSpecDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LinkageSpecDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LinkageSpecDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LinkageSpecDecl::contains(const Decl &decl) {
  for (auto &parent : LinkageSpecDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LinkageSpecDecl::contains(const Stmt &stmt) {
  for (auto &parent : LinkageSpecDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

LinkageSpecDecl LinkageSpecDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (LinkageSpecDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<LinkageSpecDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case LinkageSpecDecl::static_kind():
      return reinterpret_cast<const LinkageSpecDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kLinkageSpecDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<LinkageSpecDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kLinkageSpecDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<LinkageSpecDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kLinkageSpecDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<LinkageSpecDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const Reference &r) {
  return LinkageSpecDecl::from(r.as_declaration());
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token LinkageSpecDecl::extern_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal38());
}

LinkageSpecLanguageIDs LinkageSpecDecl::language(void) const {
  return static_cast<LinkageSpecLanguageIDs>(impl->reader.getVal54());
}

Token LinkageSpecDecl::r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

bool LinkageSpecDecl::has_braces(void) const {
  return impl->reader.getVal39();
}

gap::generator<Decl> LinkageSpecDecl::contained_declarations(void) const & {
  return BuiltinDeclReferences<Decl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::CONTAINS,
      EntityProvider::kReferenceFrom, false  /* redecls */);
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
