// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SwitchCase.h>

#include <multiplier/Entities/CaseStmt.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DefaultStmt.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SwitchCase> SwitchCase::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SwitchCase::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SwitchCase::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SwitchCase::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<SwitchCase> SwitchCase::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SwitchCase::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SwitchCase> SwitchCase::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SwitchCase> SwitchCase::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SwitchCase::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SwitchCase> SwitchCase::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SwitchCase::contains(const Decl &decl) {
  for (auto &parent : SwitchCase::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool SwitchCase::contains(const Stmt &stmt) {
  for (auto &parent : SwitchCase::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<SwitchCase> SwitchCase::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return SwitchCase::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kSwitchCaseDerivedKinds[] = {
    CaseStmt::static_kind(),
    DefaultStmt::static_kind(),
};

std::optional<SwitchCase> SwitchCase::from(const Stmt &parent) {
  switch (parent.kind()) {
    case CaseStmt::static_kind():
    case DefaultStmt::static_kind():
      return reinterpret_cast<const SwitchCase &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SwitchCase> SwitchCase::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kSwitchCaseDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SwitchCase> e = SwitchCase::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwitchCase> SwitchCase::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSwitchCaseDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SwitchCase> e = SwitchCase::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwitchCase> SwitchCase::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSwitchCaseDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SwitchCase> e = SwitchCase::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SwitchCase> SwitchCase::from(const Reference &r) {
  return SwitchCase::from(r.as_statement());
}

std::optional<SwitchCase> SwitchCase::from(const TokenContext &t) {
  return SwitchCase::from(t.as_statement());
}

Token SwitchCase::colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Token SwitchCase::keyword_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

std::optional<SwitchCase> SwitchCase::next_switch_case(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal11();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return SwitchCase::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Stmt SwitchCase::sub_statement(void) const {
  RawEntityId eid = impl->reader.getVal13();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
