// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTaskLoopDirective.h>

#include <multiplier/Entities/Decl.h>
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

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTaskLoopDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTaskLoopDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTaskLoopDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTaskLoopDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTaskLoopDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTaskLoopDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTaskLoopDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPTaskLoopDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTaskLoopDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTaskLoopDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTaskLoopDirectiveDerivedKinds[] = {
    OMPTaskLoopDirective::static_kind(),
};

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTaskLoopDirective::static_kind():
      return reinterpret_cast<const OMPTaskLoopDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTaskLoopDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTaskLoopDirective> e = OMPTaskLoopDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTaskLoopDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTaskLoopDirective> e = OMPTaskLoopDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTaskLoopDirective> OMPTaskLoopDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTaskLoopDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTaskLoopDirective> e = OMPTaskLoopDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const Reference &r) {
  return OMPTaskLoopDirective::from(r.as_statement());
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const TokenContext &t) {
  return OMPTaskLoopDirective::from(t.as_statement());
}

bool OMPTaskLoopDirective::has_cancel(void) const {
  return impl->reader.getVal24();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
