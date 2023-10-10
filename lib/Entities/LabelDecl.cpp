// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LabelDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/LabelStmt.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<LabelDecl> LabelDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LabelDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LabelDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LabelDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<LabelDecl> LabelDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LabelDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LabelDecl> LabelDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LabelDecl> LabelDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LabelDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LabelDecl> LabelDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LabelDecl::contains(const Decl &decl) {
  for (auto &parent : LabelDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LabelDecl::contains(const Stmt &stmt) {
  for (auto &parent : LabelDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

LabelDecl LabelDecl::canonical_declaration(void) const {
  if (auto canon = LabelDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (LabelDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<LabelDecl> LabelDecl::definition(void) const {
  return LabelDecl::from(this->Decl::definition());
}

gap::generator<LabelDecl> LabelDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<LabelDecl> dr = LabelDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<LabelDecl> LabelDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return LabelDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kLabelDeclDerivedKinds[] = {
    LabelDecl::static_kind(),
};

std::optional<LabelDecl> LabelDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case LabelDecl::static_kind():
      return reinterpret_cast<const LabelDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LabelDecl> LabelDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kLabelDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<LabelDecl> e = LabelDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LabelDecl> LabelDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kLabelDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<LabelDecl> e = LabelDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LabelDecl> LabelDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kLabelDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<LabelDecl> e = LabelDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LabelDecl> LabelDecl::from(const Reference &r) {
  return LabelDecl::from(r.as_declaration());
}

std::optional<LabelDecl> LabelDecl::from(const TokenContext &t) {
  return LabelDecl::from(t.as_declaration());
}

std::string_view LabelDecl::ms_assembly_label(void) const {
  capnp::Text::Reader data = impl->reader.getVal73();
  return std::string_view(data.cStr(), data.size());
}

LabelStmt LabelDecl::statement(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return LabelStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool LabelDecl::is_gnu_local(void) const {
  return impl->reader.getVal74();
}

bool LabelDecl::is_ms_assembly_label(void) const {
  return impl->reader.getVal75();
}

bool LabelDecl::is_resolved_ms_assembly_label(void) const {
  return impl->reader.getVal76();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
