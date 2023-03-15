// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPSectionsDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPSectionsDirective> OMPSectionsDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPSectionsDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPSectionsDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPSectionsDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPSectionsDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPSectionsDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPSectionsDirective::contains(const Decl &decl) {
  for (auto &parent : OMPSectionsDirective::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPSectionsDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPSectionsDirective::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPSectionsDirective> OMPSectionsDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPSectionsDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPSectionsDirectiveDerivedKinds[] = {
    OMPSectionsDirective::static_kind(),
};

std::optional<OMPSectionsDirective> OMPSectionsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPSectionsDirective::static_kind():
      return reinterpret_cast<const OMPSectionsDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPSectionsDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPSectionsDirective> e = OMPSectionsDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPSectionsDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPSectionsDirective> e = OMPSectionsDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPSectionsDirective> OMPSectionsDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPSectionsDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPSectionsDirective> e = OMPSectionsDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPSectionsDirective> OMPSectionsDirective::from(const Reference &r) {
  return OMPSectionsDirective::from(r.as_statement());
}

std::optional<OMPSectionsDirective> OMPSectionsDirective::from(const TokenContext &t) {
  return OMPSectionsDirective::from(t.as_statement());
}

Expr OMPSectionsDirective::task_reduction_reference_expression(void) const {
  RawEntityId eid = impl->reader.getVal14();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool OMPSectionsDirective::has_cancel(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
