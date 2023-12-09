// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionTemplateDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/RedeclarableTemplateDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateDecl.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kFunctionTemplateDeclDerivedKinds[] = {
    FunctionTemplateDecl::static_kind(),
};
}  // namespace

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const ir::hl::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<FunctionTemplateDecl, ir::hl::Operation>> FunctionTemplateDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::hl::Operation> res : Decl::in(tu, kFunctionTemplateDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<FunctionTemplateDecl, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FunctionTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FunctionTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FunctionTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : FunctionTemplateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool FunctionTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : FunctionTemplateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

FunctionTemplateDecl FunctionTemplateDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FunctionTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FunctionTemplateDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case FunctionTemplateDecl::static_kind():
      return reinterpret_cast<const FunctionTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFunctionTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FunctionTemplateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFunctionTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FunctionTemplateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FunctionTemplateDecl> FunctionTemplateDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFunctionTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FunctionTemplateDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const Reference &r) {
  return FunctionTemplateDecl::from(r.as_declaration());
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool FunctionTemplateDecl::is_abbreviated(void) const {
  return impl->reader.getVal77();
}

bool FunctionTemplateDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal94();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
