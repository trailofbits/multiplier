// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/BuiltinTemplateDecl.h>
#include <multiplier/AST/ClassTemplateDecl.h>
#include <multiplier/AST/ConceptDecl.h>
#include <multiplier/AST/FunctionTemplateDecl.h>
#include <multiplier/AST/TemplateTemplateParmDecl.h>
#include <multiplier/AST/TypeAliasTemplateDecl.h>
#include <multiplier/AST/VarTemplateDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kTemplateDeclDerivedKinds[] = {
    TemplateTemplateParmDecl::static_kind(),
    BuiltinTemplateDecl::static_kind(),
    ConceptDecl::static_kind(),
    TypeAliasTemplateDecl::static_kind(),
    VarTemplateDecl::static_kind(),
    ClassTemplateDecl::static_kind(),
    FunctionTemplateDecl::static_kind(),
};
}  // namespace

gap::generator<TemplateDecl> TemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TemplateDecl> TemplateDecl::from(const ir::hl::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<TemplateDecl, ir::hl::Operation>> TemplateDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::hl::Operation> res : Decl::in(tu, kTemplateDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<TemplateDecl, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TemplateDecl::contains(const Decl &decl) {
  for (auto &parent : TemplateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : TemplateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TemplateDecl TemplateDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TemplateDecl> TemplateDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<TemplateDecl> TemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TemplateDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TemplateDecl> TemplateDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<TemplateDecl> TemplateDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TemplateDecl> TemplateDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case TemplateTemplateParmDecl::static_kind():
    case BuiltinTemplateDecl::static_kind():
    case ConceptDecl::static_kind():
    case TypeAliasTemplateDecl::static_kind():
    case VarTemplateDecl::static_kind():
    case ClassTemplateDecl::static_kind():
    case FunctionTemplateDecl::static_kind():
      return reinterpret_cast<const TemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TemplateDecl> TemplateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TemplateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TemplateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateDecl> TemplateDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TemplateDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TemplateDecl> TemplateDecl::from(const Reference &r) {
  return TemplateDecl::from(r.as_declaration());
}

std::optional<TemplateDecl> TemplateDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<TemplateDecl> TemplateDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TemplateParameterList TemplateDecl::template_parameters(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return TemplateParameterList(impl->ep->TemplateParameterListFor(impl->ep, eid));
}

NamedDecl TemplateDecl::templated_declaration(void) const {
  RawEntityId eid = impl->reader.getVal57();
  return NamedDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool TemplateDecl::has_associated_constraints(void) const {
  return impl->reader.getVal74();
}

bool TemplateDecl::is_type_alias(void) const {
  return impl->reader.getVal75();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
