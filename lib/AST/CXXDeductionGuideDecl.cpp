// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXDeductionGuideDecl.h>
#include <multiplier/AST/CXXConstructorDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateDecl.h>
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
static const DeclKind kCXXDeductionGuideDeclDerivedKinds[] = {
    CXXDeductionGuideDecl::static_kind(),
};
}  // namespace

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXDeductionGuideDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXDeductionGuideDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXDeductionGuideDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<CXXDeductionGuideDecl, ir::Operation>> CXXDeductionGuideDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kCXXDeductionGuideDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<CXXDeductionGuideDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXDeductionGuideDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXDeductionGuideDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXDeductionGuideDecl::contains(const Decl &decl) {
  for (auto &parent : CXXDeductionGuideDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CXXDeductionGuideDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXDeductionGuideDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

CXXDeductionGuideDecl CXXDeductionGuideDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (CXXDeductionGuideDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXDeductionGuideDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case CXXDeductionGuideDecl::static_kind():
      return reinterpret_cast<const CXXDeductionGuideDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kCXXDeductionGuideDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXDeductionGuideDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXDeductionGuideDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXDeductionGuideDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXDeductionGuideDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXDeductionGuideDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const Reference &r) {
  return CXXDeductionGuideDecl::from(r.as_declaration());
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<CXXConstructorDecl> CXXDeductionGuideDecl::corresponding_constructor(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal170();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXConstructorDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

TemplateDecl CXXDeductionGuideDecl::deduced_template(void) const {
  RawEntityId eid = impl->reader.getVal171();
  return TemplateDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

DeductionCandidate CXXDeductionGuideDecl::deduction_candidate_kind(void) const {
  return static_cast<DeductionCandidate>(impl->reader.getVal169());
}

bool CXXDeductionGuideDecl::is_explicit(void) const {
  return impl->reader.getVal172();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
