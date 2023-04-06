// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FileScopeAsmDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/StringLiteral.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FileScopeAsmDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FileScopeAsmDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FileScopeAsmDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FileScopeAsmDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FileScopeAsmDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FileScopeAsmDecl::contains(const Decl &decl) {
  for (auto &parent : FileScopeAsmDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool FileScopeAsmDecl::contains(const Stmt &stmt) {
  for (auto &parent : FileScopeAsmDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

FileScopeAsmDecl FileScopeAsmDecl::canonical_declaration(void) const {
  if (auto canon = FileScopeAsmDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FileScopeAsmDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::definition(void) const {
  return FileScopeAsmDecl::from(this->Decl::definition());
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FileScopeAsmDecl> dr = FileScopeAsmDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return FileScopeAsmDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kFileScopeAsmDeclDerivedKinds[] = {
    FileScopeAsmDecl::static_kind(),
};

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case FileScopeAsmDecl::static_kind():
      return reinterpret_cast<const FileScopeAsmDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kFileScopeAsmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FileScopeAsmDecl> e = FileScopeAsmDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFileScopeAsmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FileScopeAsmDecl> e = FileScopeAsmDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFileScopeAsmDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FileScopeAsmDecl> e = FileScopeAsmDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const Reference &r) {
  return FileScopeAsmDecl::from(r.as_declaration());
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const TokenContext &t) {
  return FileScopeAsmDecl::from(t.as_declaration());
}

Token FileScopeAsmDecl::assembly_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal47());
}

StringLiteral FileScopeAsmDecl::assembly_string(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return StringLiteral::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Token FileScopeAsmDecl::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal55());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
