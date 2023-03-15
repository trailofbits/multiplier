// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTeamsDirective.h>

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

gap::generator<OMPTeamsDirective> OMPTeamsDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTeamsDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTeamsDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTeamsDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTeamsDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTeamsDirective::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPTeamsDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTeamsDirective::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPTeamsDirective> OMPTeamsDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTeamsDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTeamsDirectiveDerivedKinds[] = {
    OMPTeamsDirective::static_kind(),
};

std::optional<OMPTeamsDirective> OMPTeamsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTeamsDirective::static_kind():
      return reinterpret_cast<const OMPTeamsDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTeamsDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTeamsDirective> e = OMPTeamsDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTeamsDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTeamsDirective> e = OMPTeamsDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDirective> OMPTeamsDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTeamsDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTeamsDirective> e = OMPTeamsDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTeamsDirective> OMPTeamsDirective::from(const Reference &r) {
  return OMPTeamsDirective::from(r.as_statement());
}

std::optional<OMPTeamsDirective> OMPTeamsDirective::from(const TokenContext &t) {
  return OMPTeamsDirective::from(t.as_statement());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
