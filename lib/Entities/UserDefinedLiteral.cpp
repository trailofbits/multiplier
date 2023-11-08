// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UserDefinedLiteral.h>

#include <multiplier/Entities/CallExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UserDefinedLiteral> UserDefinedLiteral::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UserDefinedLiteral::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UserDefinedLiteral::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UserDefinedLiteral::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UserDefinedLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = UserDefinedLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UserDefinedLiteral::contains(const Decl &decl) {
  for (auto &parent : UserDefinedLiteral::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UserDefinedLiteral::contains(const Stmt &stmt) {
  for (auto &parent : UserDefinedLiteral::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return UserDefinedLiteral::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kUserDefinedLiteralDerivedKinds[] = {
    UserDefinedLiteral::static_kind(),
};

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case UserDefinedLiteral::static_kind():
      return reinterpret_cast<const UserDefinedLiteral &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kUserDefinedLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<UserDefinedLiteral> e = UserDefinedLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kUserDefinedLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<UserDefinedLiteral> e = UserDefinedLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UserDefinedLiteral> UserDefinedLiteral::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kUserDefinedLiteralDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<UserDefinedLiteral> e = UserDefinedLiteral::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const Reference &r) {
  return UserDefinedLiteral::from(r.as_statement());
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const TokenContext &t) {
  return UserDefinedLiteral::from(t.as_statement());
}

Expr UserDefinedLiteral::cooked_literal(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

UserDefinedLiteralLiteralOperatorKind UserDefinedLiteral::literal_operator_kind(void) const {
  return static_cast<UserDefinedLiteralLiteralOperatorKind>(impl->reader.getVal97());
}

Token UserDefinedLiteral::ud_suffix_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
