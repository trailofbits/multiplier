// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPOrderedDirective.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/OMPExecutableDirective.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPOrderedDirective> OMPOrderedDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPOrderedDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPOrderedDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPOrderedDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPOrderedDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPOrderedDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPOrderedDirective::contains(const Decl &decl) {
  for (auto &parent : OMPOrderedDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPOrderedDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPOrderedDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kOMPOrderedDirectiveDerivedKinds[] = {
    OMPOrderedDirective::static_kind(),
};

}  // namespace

std::optional<OMPOrderedDirective> OMPOrderedDirective::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPOrderedDirective::static_kind():
      return reinterpret_cast<const OMPOrderedDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPOrderedDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPOrderedDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPOrderedDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPOrderedDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPOrderedDirective> OMPOrderedDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPOrderedDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPOrderedDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const Reference &r) {
  return OMPOrderedDirective::from(r.as_statement());
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
