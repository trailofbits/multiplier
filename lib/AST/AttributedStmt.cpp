// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AttributedStmt.h>

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AttributedStmt> AttributedStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AttributedStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AttributedStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AttributedStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<AttributedStmt> AttributedStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AttributedStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AttributedStmt> AttributedStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AttributedStmt> AttributedStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AttributedStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AttributedStmt> AttributedStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AttributedStmt::contains(const Decl &decl) {
  for (auto &parent : AttributedStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool AttributedStmt::contains(const Stmt &stmt) {
  for (auto &parent : AttributedStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<AttributedStmt> AttributedStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<AttributedStmt> AttributedStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kAttributedStmtDerivedKinds[] = {
    AttributedStmt::static_kind(),
};

}  // namespace

std::optional<AttributedStmt> AttributedStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case AttributedStmt::static_kind():
      return reinterpret_cast<const AttributedStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AttributedStmt> AttributedStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kAttributedStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AttributedStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AttributedStmt> AttributedStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAttributedStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AttributedStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AttributedStmt> AttributedStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAttributedStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AttributedStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AttributedStmt> AttributedStmt::from(const Reference &r) {
  return AttributedStmt::from(r.as_statement());
}

std::optional<AttributedStmt> AttributedStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<AttributedStmt> AttributedStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token AttributedStmt::attribute_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

unsigned AttributedStmt::num_attributes(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Attr> AttributedStmt::nth_attribute(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->AttrFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Attr(std::move(e));
}

gap::generator<Attr> AttributedStmt::attributes(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->AttrFor(ep, v)) {
      co_yield Attr(std::move(d15));
    }
  }
  co_return;
}

Stmt AttributedStmt::sub_statement(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
