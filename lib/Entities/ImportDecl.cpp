// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ImportDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ImportDecl> ImportDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ImportDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ImportDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ImportDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ImportDecl> ImportDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ImportDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImportDecl> ImportDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ImportDecl> ImportDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ImportDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ImportDecl> ImportDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ImportDecl::contains(const Decl &decl) {
  for (auto &parent : ImportDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ImportDecl::contains(const Stmt &stmt) {
  for (auto &parent : ImportDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ImportDecl> ImportDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ImportDecl> dr = ImportDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ImportDecl> ImportDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ImportDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kImportDeclDerivedKinds[] = {
    ImportDecl::static_kind(),
};

std::optional<ImportDecl> ImportDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ImportDecl::static_kind():
      return reinterpret_cast<const ImportDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ImportDecl> ImportDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kImportDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ImportDecl> e = ImportDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImportDecl> ImportDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kImportDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ImportDecl> e = ImportDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ImportDecl> ImportDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kImportDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ImportDecl> e = ImportDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ImportDecl> ImportDecl::from(const Reference &r) {
  return ImportDecl::from(r.as_declaration());
}

std::optional<ImportDecl> ImportDecl::from(const TokenContext &t) {
  return ImportDecl::from(t.as_declaration());
}

unsigned ImportDecl::num_identifier_tokens(void) const {
  return impl->reader.getVal49().size();
}

std::optional<Token> ImportDecl::nth_identifier_token(unsigned n) const {
  auto list = impl->reader.getVal49();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TokenFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Token(std::move(e));
}

gap::generator<Token> ImportDecl::identifier_tokens(void) const & {
  auto list = impl->reader.getVal49();
  EntityProvider::Ptr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t49 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t49;
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
