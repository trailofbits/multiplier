// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPDeclareReductionDecl.h>
#include "../Reference.h"
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kOMPDeclareReductionDeclDerivedKinds[] = {
    OMPDeclareReductionDecl::static_kind(),
};
}  // namespace

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kOMPDeclareReductionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<OMPDeclareReductionDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kOMPDeclareReductionDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclareReductionDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kOMPDeclareReductionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclareReductionDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclareReductionDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclareReductionDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclareReductionDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPDeclareReductionDecl, ir::Operation>> OMPDeclareReductionDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kOMPDeclareReductionDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPDeclareReductionDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclareReductionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = OMPDeclareReductionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDeclareReductionDecl::contains(const Decl &decl) {
  for (auto &parent : OMPDeclareReductionDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPDeclareReductionDecl::contains(const Stmt &stmt) {
  for (auto &parent : OMPDeclareReductionDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

OMPDeclareReductionDecl OMPDeclareReductionDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (OMPDeclareReductionDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<OMPDeclareReductionDecl> OMPDeclareReductionDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<OMPDeclareReductionDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case OMPDeclareReductionDecl::static_kind():
      return reinterpret_cast<const OMPDeclareReductionDecl &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const Reference &r) {
  return OMPDeclareReductionDecl::from(r.as_declaration());
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr OMPDeclareReductionDecl::combiner(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPDeclareReductionDecl::combiner_in(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPDeclareReductionDecl::combiner_out(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPDeclareReductionDecl::initializer_original(void) const {
  RawEntityId eid = impl->reader.getVal57();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPDeclareReductionDecl::initializer_private(void) const {
  RawEntityId eid = impl->reader.getVal67();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPDeclareReductionDecl::initializer(void) const {
  RawEntityId eid = impl->reader.getVal68();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

OMPDeclareReductionInitKind OMPDeclareReductionDecl::initializer_kind(void) const {
  return static_cast<OMPDeclareReductionInitKind>(impl->reader.getVal69());
}

gap::generator<Decl> OMPDeclareReductionDecl::contained_declarations(void) const & {
  return BuiltinDeclReferences<Decl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::CONTAINS,
      EntityProvider::kReferenceFrom, false  /* redecls */);
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
