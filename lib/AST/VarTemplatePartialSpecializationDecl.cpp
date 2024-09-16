// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueDecl.h>
#include <multiplier/AST/VarDecl.h>
#include <multiplier/AST/VarTemplateSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kVarTemplatePartialSpecializationDeclDerivedKinds[] = {
    VarTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kVarTemplatePartialSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<VarTemplatePartialSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kVarTemplatePartialSpecializationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<VarTemplatePartialSpecializationDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kVarTemplatePartialSpecializationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<VarTemplatePartialSpecializationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VarTemplatePartialSpecializationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VarTemplatePartialSpecializationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VarTemplatePartialSpecializationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<VarTemplatePartialSpecializationDecl, ir::Operation>> VarTemplatePartialSpecializationDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kVarTemplatePartialSpecializationDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<VarTemplatePartialSpecializationDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplatePartialSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = VarTemplatePartialSpecializationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool VarTemplatePartialSpecializationDecl::contains(const Decl &decl) {
  for (auto &parent : VarTemplatePartialSpecializationDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool VarTemplatePartialSpecializationDecl::contains(const Stmt &stmt) {
  for (auto &parent : VarTemplatePartialSpecializationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

VarTemplatePartialSpecializationDecl VarTemplatePartialSpecializationDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (VarTemplatePartialSpecializationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<VarTemplatePartialSpecializationDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case VarTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const VarTemplatePartialSpecializationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const Reference &r) {
  return VarTemplatePartialSpecializationDecl::from(r.as_declaration());
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TemplateParameterList VarTemplatePartialSpecializationDecl::template_parameters(void) const {
  RawEntityId eid = impl->reader.getVal116();
  return TemplateParameterList(impl->ep->TemplateParameterListFor(impl->ep, eid));
}

bool VarTemplatePartialSpecializationDecl::has_associated_constraints(void) const {
  return impl->reader.getVal124();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
