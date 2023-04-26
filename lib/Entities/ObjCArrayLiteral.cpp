// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCArrayLiteral.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCArrayLiteral::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCArrayLiteral::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCArrayLiteral::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCArrayLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCArrayLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCArrayLiteral::contains(const Decl &decl) {
  for (auto &parent : ObjCArrayLiteral::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCArrayLiteral::contains(const Stmt &stmt) {
  for (auto &parent : ObjCArrayLiteral::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCArrayLiteral::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCArrayLiteralDerivedKinds[] = {
    ObjCArrayLiteral::static_kind(),
};

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCArrayLiteral::static_kind():
      return reinterpret_cast<const ObjCArrayLiteral &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCArrayLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCArrayLiteral> e = ObjCArrayLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCArrayLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCArrayLiteral> e = ObjCArrayLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCArrayLiteral> ObjCArrayLiteral::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCArrayLiteralDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCArrayLiteral> e = ObjCArrayLiteral::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const Reference &r) {
  return ObjCArrayLiteral::from(r.as_statement());
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const TokenContext &t) {
  return ObjCArrayLiteral::from(t.as_statement());
}

ObjCMethodDecl ObjCArrayLiteral::array_with_objects_method(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

unsigned ObjCArrayLiteral::num_elements(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> ObjCArrayLiteral::nth_element(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> ObjCArrayLiteral::elements(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
