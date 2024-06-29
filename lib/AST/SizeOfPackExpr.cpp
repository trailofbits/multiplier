// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SizeOfPackExpr.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ValueStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kSizeOfPackExprDerivedKinds[] = {
    SizeOfPackExpr::static_kind(),
};
}  // namespace

gap::generator<SizeOfPackExpr> SizeOfPackExpr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kSizeOfPackExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<SizeOfPackExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kSizeOfPackExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<SizeOfPackExpr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kSizeOfPackExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<SizeOfPackExpr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SizeOfPackExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SizeOfPackExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SizeOfPackExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<SizeOfPackExpr, ir::Operation>> SizeOfPackExpr::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kSizeOfPackExprDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<SizeOfPackExpr, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SizeOfPackExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = SizeOfPackExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<SizeOfPackExpr> SizeOfPackExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool SizeOfPackExpr::contains(const Decl &decl) {
  for (auto &parent : SizeOfPackExpr::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool SizeOfPackExpr::contains(const Stmt &stmt) {
  for (auto &parent : SizeOfPackExpr::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::by_id(const Index &index, EntityId eid) {
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

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case SizeOfPackExpr::static_kind():
      return reinterpret_cast<const SizeOfPackExpr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const Reference &r) {
  return SizeOfPackExpr::from(r.as_statement());
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token SizeOfPackExpr::operator_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal37());
}

NamedDecl SizeOfPackExpr::pack(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return NamedDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

std::optional<uint32_t> SizeOfPackExpr::pack_length(void) const {
  if (!impl->reader.getVal83()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal99());
  }
  return std::nullopt;
}

Token SizeOfPackExpr::pack_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal39());
}

std::optional<std::vector<TemplateArgument>> SizeOfPackExpr::partial_arguments(void) const {
  if (!impl->reader.getVal84()) {
    return std::nullopt;
  }
  auto list = impl->reader.getVal15();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->TemplateArgumentFor(ep, v)) {
      vec.emplace_back(std::move(d15));
    }
  }
  return vec;
}

Token SizeOfPackExpr::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

bool SizeOfPackExpr::is_partially_substituted(void) const {
  return impl->reader.getVal85();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
