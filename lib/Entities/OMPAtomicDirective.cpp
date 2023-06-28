// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPAtomicDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPAtomicDirective> OMPAtomicDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPAtomicDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPAtomicDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPAtomicDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPAtomicDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPAtomicDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPAtomicDirective::contains(const Decl &decl) {
  for (auto &parent : OMPAtomicDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPAtomicDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPAtomicDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPAtomicDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPAtomicDirectiveDerivedKinds[] = {
    OMPAtomicDirective::static_kind(),
};

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPAtomicDirective::static_kind():
      return reinterpret_cast<const OMPAtomicDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPAtomicDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPAtomicDirective> e = OMPAtomicDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPAtomicDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPAtomicDirective> e = OMPAtomicDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPAtomicDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPAtomicDirective> e = OMPAtomicDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const Reference &r) {
  return OMPAtomicDirective::from(r.as_statement());
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const TokenContext &t) {
  return OMPAtomicDirective::from(t.as_statement());
}

Expr OMPAtomicDirective::condition_expression(void) const {
  RawEntityId eid = impl->reader.getVal15();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPAtomicDirective::d(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPAtomicDirective::expression(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPAtomicDirective::r(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPAtomicDirective::update_expression(void) const {
  RawEntityId eid = impl->reader.getVal21();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPAtomicDirective::v(void) const {
  RawEntityId eid = impl->reader.getVal22();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Expr OMPAtomicDirective::x(void) const {
  RawEntityId eid = impl->reader.getVal23();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool OMPAtomicDirective::is_fail_only(void) const {
  return impl->reader.getVal24();
}

bool OMPAtomicDirective::is_postfix_update(void) const {
  return impl->reader.getVal25();
}

bool OMPAtomicDirective::is_xlhs_in_rhs_part(void) const {
  return impl->reader.getVal26();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
