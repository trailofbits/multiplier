// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDepobjDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPDepobjDirective> OMPDepobjDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDepobjDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDepobjDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDepobjDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPDepobjDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPDepobjDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPDepobjDirective::contains(const Decl &decl) {
  for (auto &parent : OMPDepobjDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPDepobjDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPDepobjDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPDepobjDirective> OMPDepobjDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPDepobjDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPDepobjDirectiveDerivedKinds[] = {
    OMPDepobjDirective::static_kind(),
};

std::optional<OMPDepobjDirective> OMPDepobjDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPDepobjDirective::static_kind():
      return reinterpret_cast<const OMPDepobjDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPDepobjDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPDepobjDirective> e = OMPDepobjDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPDepobjDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPDepobjDirective> e = OMPDepobjDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDepobjDirective> OMPDepobjDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPDepobjDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPDepobjDirective> e = OMPDepobjDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDepobjDirective> OMPDepobjDirective::from(const Reference &r) {
  return OMPDepobjDirective::from(r.as_statement());
}

std::optional<OMPDepobjDirective> OMPDepobjDirective::from(const TokenContext &t) {
  return OMPDepobjDirective::from(t.as_statement());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
