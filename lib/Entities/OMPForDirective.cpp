// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPForDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/OMPLoopBasedDirective.h>
#include <multiplier/Entities/OMPLoopDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPForDirective> OMPForDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPForDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPForDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPForDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPForDirective> OMPForDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPForDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPForDirective> OMPForDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPForDirective> OMPForDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPForDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPForDirective> OMPForDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPForDirective::contains(const Decl &decl) {
  for (auto &parent : OMPForDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPForDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPForDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPForDirective> OMPForDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPForDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPForDirectiveDerivedKinds[] = {
    OMPForDirective::static_kind(),
};

std::optional<OMPForDirective> OMPForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPForDirective::static_kind():
      return reinterpret_cast<const OMPForDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPForDirective> OMPForDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPForDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPForDirective> e = OMPForDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPForDirective> OMPForDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPForDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPForDirective> e = OMPForDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPForDirective> OMPForDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPForDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPForDirective> e = OMPForDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPForDirective> OMPForDirective::from(const Reference &r) {
  return OMPForDirective::from(r.as_statement());
}

std::optional<OMPForDirective> OMPForDirective::from(const TokenContext &t) {
  return OMPForDirective::from(t.as_statement());
}

Expr OMPForDirective::task_reduction_reference_expression(void) const {
  RawEntityId eid = impl->reader.getVal58();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool OMPForDirective::has_cancel(void) const {
  return impl->reader.getVal26();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
