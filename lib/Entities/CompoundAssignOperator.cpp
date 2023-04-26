// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CompoundAssignOperator.h>

#include <multiplier/Entities/BinaryOperator.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<CompoundAssignOperator> CompoundAssignOperator::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = CompoundAssignOperator::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool CompoundAssignOperator::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : CompoundAssignOperator::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CompoundAssignOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = CompoundAssignOperator::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool CompoundAssignOperator::contains(const Decl &decl) {
  for (auto &parent : CompoundAssignOperator::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool CompoundAssignOperator::contains(const Stmt &stmt) {
  for (auto &parent : CompoundAssignOperator::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return CompoundAssignOperator::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kCompoundAssignOperatorDerivedKinds[] = {
    CompoundAssignOperator::static_kind(),
};

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CompoundAssignOperator::static_kind():
      return reinterpret_cast<const CompoundAssignOperator &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kCompoundAssignOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<CompoundAssignOperator> e = CompoundAssignOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kCompoundAssignOperatorDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<CompoundAssignOperator> e = CompoundAssignOperator::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<CompoundAssignOperator> CompoundAssignOperator::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kCompoundAssignOperatorDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<CompoundAssignOperator> e = CompoundAssignOperator::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const Reference &r) {
  return CompoundAssignOperator::from(r.as_statement());
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const TokenContext &t) {
  return CompoundAssignOperator::from(t.as_statement());
}

Type CompoundAssignOperator::computation_lhs_type(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type CompoundAssignOperator::computation_result_type(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
