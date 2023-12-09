// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPDistributeSimdDirective.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/OMPExecutableDirective.h>
#include <multiplier/AST/OMPLoopBasedDirective.h>
#include <multiplier/AST/OMPLoopDirective.h>
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
static const StmtKind kOMPDistributeSimdDirectiveDerivedKinds[] = {
    OMPDistributeSimdDirective::static_kind(),
};
}  // namespace

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDistributeSimdDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDistributeSimdDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDistributeSimdDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPDistributeSimdDirective, ir::hl::Operation>> OMPDistributeSimdDirective::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kOMPDistributeSimdDirectiveDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPDistributeSimdDirective, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPDistributeSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPDistributeSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDistributeSimdDirective::contains(const Decl &decl) {
  for (auto &parent : OMPDistributeSimdDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPDistributeSimdDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPDistributeSimdDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPDistributeSimdDirective::static_kind():
      return reinterpret_cast<const OMPDistributeSimdDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPDistributeSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPDistributeSimdDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPDistributeSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPDistributeSimdDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDistributeSimdDirective> OMPDistributeSimdDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPDistributeSimdDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPDistributeSimdDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const Reference &r) {
  return OMPDistributeSimdDirective::from(r.as_statement());
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
