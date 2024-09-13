// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPAtomicDirective.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/OMPExecutableDirective.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kOMPAtomicDirectiveDerivedKinds[] = {
    OMPAtomicDirective::static_kind(),
};
}  // namespace

gap::generator<OMPAtomicDirective> OMPAtomicDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPAtomicDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPAtomicDirective> e = from_base(std::move(eptr))) {
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
        if (std::optional<OMPAtomicDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<OMPAtomicDirective> OMPAtomicDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPAtomicDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPAtomicDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPAtomicDirective, ir::Operation>> OMPAtomicDirective::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kOMPAtomicDirectiveDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPAtomicDirective, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPAtomicDirective::static_kind():
      return reinterpret_cast<const OMPAtomicDirective &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const Reference &r) {
  return OMPAtomicDirective::from(r.as_statement());
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr OMPAtomicDirective::condition_expression(void) const {
  RawEntityId eid = impl->reader.getVal14();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPAtomicDirective::d(void) const {
  RawEntityId eid = impl->reader.getVal17();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPAtomicDirective::expression(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPAtomicDirective::r(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPAtomicDirective::update_expression(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPAtomicDirective::v(void) const {
  RawEntityId eid = impl->reader.getVal21();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPAtomicDirective::x(void) const {
  RawEntityId eid = impl->reader.getVal22();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool OMPAtomicDirective::is_fail_only(void) const {
  return impl->reader.getVal23();
}

bool OMPAtomicDirective::is_postfix_update(void) const {
  return impl->reader.getVal24();
}

bool OMPAtomicDirective::is_xlhs_in_rhs_part(void) const {
  return impl->reader.getVal25();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
