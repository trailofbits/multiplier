// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LabelDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/LabelStmt.h>
#include <multiplier/AST/NamedDecl.h>
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
static const DeclKind kLabelDeclDerivedKinds[] = {
    LabelDecl::static_kind(),
};
}  // namespace

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

#ifndef MX_DISABLE_VAST
std::optional<LabelDecl> LabelDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<LabelDecl, ir::Operation>> LabelDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kLabelDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<LabelDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (LabelDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<LabelDecl> LabelDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<LabelDecl> LabelDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<LabelDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<LabelDecl> LabelDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<LabelDecl> LabelDecl::from_base(const Decl &parent) {
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
      if (std::optional<LabelDecl> e = from_base(std::move(eptr))) {
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
      if (std::optional<LabelDecl> e = from_base(std::move(eptr))) {
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
        if (std::optional<LabelDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LabelDecl> LabelDecl::from(const Reference &r) {
  return LabelDecl::from(r.as_declaration());
}

std::optional<LabelDecl> LabelDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<LabelDecl> LabelDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::string_view LabelDecl::ms_assembly_label(void) const {
  capnp::Text::Reader data = impl->reader.getVal73();
  return std::string_view(data.cStr(), data.size());
}

LabelStmt LabelDecl::statement(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return LabelStmt::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
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
