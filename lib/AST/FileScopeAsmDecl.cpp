// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FileScopeAsmDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/StringLiteral.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kFileScopeAsmDeclDerivedKinds[] = {
    FileScopeAsmDecl::static_kind(),
};
}  // namespace

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

#ifndef MX_DISABLE_VAST
std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<FileScopeAsmDecl, ir::Operation>> FileScopeAsmDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kFileScopeAsmDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<FileScopeAsmDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

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
    if (*this == parent) { return true; }
  }
  return false;
}

bool FileScopeAsmDecl::contains(const Stmt &stmt) {
  for (auto &parent : FileScopeAsmDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

FileScopeAsmDecl FileScopeAsmDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FileScopeAsmDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FileScopeAsmDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case FileScopeAsmDecl::static_kind():
      return reinterpret_cast<const FileScopeAsmDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFileScopeAsmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FileScopeAsmDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFileScopeAsmDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FileScopeAsmDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FileScopeAsmDecl> FileScopeAsmDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFileScopeAsmDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FileScopeAsmDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const Reference &r) {
  return FileScopeAsmDecl::from(r.as_declaration());
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token FileScopeAsmDecl::assembly_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal49());
}

StringLiteral FileScopeAsmDecl::assembly_string(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return StringLiteral::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token FileScopeAsmDecl::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal57());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
