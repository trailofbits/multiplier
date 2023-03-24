// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXDeductionGuideDecl.h>

#include <multiplier/Entities/CXXConstructorDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXDeductionGuideDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXDeductionGuideDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXDeductionGuideDecl> dr = CXXDeductionGuideDecl::from(r)) {
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
    return CXXDeductionGuideDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kCXXDeductionGuideDeclDerivedKinds[] = {
    CXXDeductionGuideDecl::static_kind(),
};

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case CXXDeductionGuideDecl::static_kind():
      return reinterpret_cast<const CXXDeductionGuideDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kCXXDeductionGuideDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXDeductionGuideDecl> e = CXXDeductionGuideDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXDeductionGuideDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXDeductionGuideDecl> e = CXXDeductionGuideDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXDeductionGuideDecl> CXXDeductionGuideDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXDeductionGuideDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXDeductionGuideDecl> e = CXXDeductionGuideDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const Reference &r) {
  return CXXDeductionGuideDecl::from(r.as_declaration());
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const TokenContext &t) {
  return CXXDeductionGuideDecl::from(t.as_declaration());
}

CXXConstructorDecl CXXDeductionGuideDecl::corresponding_constructor(void) const {
  RawEntityId eid = impl->reader.getVal164();
  return CXXConstructorDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

TemplateDecl CXXDeductionGuideDecl::deduced_template(void) const {
  RawEntityId eid = impl->reader.getVal165();
  return TemplateDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool CXXDeductionGuideDecl::is_copy_deduction_candidate(void) const {
  return impl->reader.getVal166();
}

bool CXXDeductionGuideDecl::is_explicit(void) const {
  return impl->reader.getVal167();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
