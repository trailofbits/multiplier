// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CXXConversionDecl.h>

#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/FunctionDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CXXConversionDecl> CXXConversionDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CXXConversionDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CXXConversionDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CXXConversionDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CXXConversionDecl> CXXConversionDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXConversionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConversionDecl> CXXConversionDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CXXConversionDecl> CXXConversionDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = CXXConversionDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CXXConversionDecl> CXXConversionDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CXXConversionDecl::contains(const Decl &decl) {
  for (auto &parent : CXXConversionDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool CXXConversionDecl::contains(const Stmt &stmt) {
  for (auto &parent : CXXConversionDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<CXXConversionDecl> CXXConversionDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<CXXConversionDecl> dr = CXXConversionDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<CXXConversionDecl> CXXConversionDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return CXXConversionDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kCXXConversionDeclDerivedKinds[] = {
    CXXConversionDecl::static_kind(),
};

std::optional<CXXConversionDecl> CXXConversionDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case CXXConversionDecl::static_kind():
      return reinterpret_cast<const CXXConversionDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CXXConversionDecl> CXXConversionDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kCXXConversionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<CXXConversionDecl> e = CXXConversionDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConversionDecl> CXXConversionDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kCXXConversionDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<CXXConversionDecl> e = CXXConversionDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CXXConversionDecl> CXXConversionDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kCXXConversionDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<CXXConversionDecl> e = CXXConversionDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const Reference &r) {
  return CXXConversionDecl::from(r.as_declaration());
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const TokenContext &t) {
  return CXXConversionDecl::from(t.as_declaration());
}

Type CXXConversionDecl::conversion_type(void) const {
  RawEntityId eid = impl->reader.getVal175();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool CXXConversionDecl::is_explicit(void) const {
  return impl->reader.getVal177();
}

bool CXXConversionDecl::is_lambda_to_block_pointer_conversion(void) const {
  return impl->reader.getVal178();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
