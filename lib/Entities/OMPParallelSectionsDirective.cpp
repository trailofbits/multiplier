// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPParallelSectionsDirective.h>

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

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPParallelSectionsDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPParallelSectionsDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPParallelSectionsDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPParallelSectionsDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPParallelSectionsDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPParallelSectionsDirective::contains(const Decl &decl) {
  for (auto &parent : OMPParallelSectionsDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPParallelSectionsDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPParallelSectionsDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPParallelSectionsDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPParallelSectionsDirectiveDerivedKinds[] = {
    OMPParallelSectionsDirective::static_kind(),
};

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPParallelSectionsDirective::static_kind():
      return reinterpret_cast<const OMPParallelSectionsDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPParallelSectionsDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPParallelSectionsDirective> e = OMPParallelSectionsDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPParallelSectionsDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPParallelSectionsDirective> e = OMPParallelSectionsDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPParallelSectionsDirective> OMPParallelSectionsDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPParallelSectionsDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPParallelSectionsDirective> e = OMPParallelSectionsDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::from(const Reference &r) {
  return OMPParallelSectionsDirective::from(r.as_statement());
}

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::from(const TokenContext &t) {
  return OMPParallelSectionsDirective::from(t.as_statement());
}

Expr OMPParallelSectionsDirective::task_reduction_reference_expression(void) const {
  RawEntityId eid = impl->reader.getVal14();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool OMPParallelSectionsDirective::has_cancel(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
