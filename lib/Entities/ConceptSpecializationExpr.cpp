// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConceptSpecializationExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConceptSpecializationExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConceptSpecializationExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConceptSpecializationExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ConceptSpecializationExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ConceptSpecializationExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ConceptSpecializationExpr::contains(const Decl &decl) {
  for (auto &parent : ConceptSpecializationExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ConceptSpecializationExpr::contains(const Stmt &stmt) {
  for (auto &parent : ConceptSpecializationExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ConceptSpecializationExpr> ConceptSpecializationExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ConceptSpecializationExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kConceptSpecializationExprDerivedKinds[] = {
    ConceptSpecializationExpr::static_kind(),
};

std::optional<ConceptSpecializationExpr> ConceptSpecializationExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ConceptSpecializationExpr::static_kind():
      return reinterpret_cast<const ConceptSpecializationExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kConceptSpecializationExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ConceptSpecializationExpr> e = ConceptSpecializationExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kConceptSpecializationExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ConceptSpecializationExpr> e = ConceptSpecializationExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConceptSpecializationExpr> ConceptSpecializationExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kConceptSpecializationExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ConceptSpecializationExpr> e = ConceptSpecializationExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

unsigned ConceptSpecializationExpr::num_template_arguments(void) const {
  return impl->reader.getVal15().size();
}

std::optional<TemplateArgument> ConceptSpecializationExpr::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> ConceptSpecializationExpr::template_arguments(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d15));
    }
  }
  co_return;
}

bool ConceptSpecializationExpr::is_satisfied(void) const {
  return impl->reader.getVal88();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
