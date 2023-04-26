// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTaskwaitDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTaskwaitDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTaskwaitDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTaskwaitDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTaskwaitDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTaskwaitDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTaskwaitDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTaskwaitDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPTaskwaitDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTaskwaitDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTaskwaitDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTaskwaitDirectiveDerivedKinds[] = {
    OMPTaskwaitDirective::static_kind(),
};

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTaskwaitDirective::static_kind():
      return reinterpret_cast<const OMPTaskwaitDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTaskwaitDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTaskwaitDirective> e = OMPTaskwaitDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTaskwaitDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTaskwaitDirective> e = OMPTaskwaitDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTaskwaitDirective> OMPTaskwaitDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTaskwaitDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTaskwaitDirective> e = OMPTaskwaitDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::from(const Reference &r) {
  return OMPTaskwaitDirective::from(r.as_statement());
}

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::from(const TokenContext &t) {
  return OMPTaskwaitDirective::from(t.as_statement());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
