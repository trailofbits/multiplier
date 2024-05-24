// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/GCCAsmStmt.h>
#include <multiplier/AST/AddrLabelExpr.h>
#include <multiplier/AST/AsmStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/StringLiteral.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kGCCAsmStmtDerivedKinds[] = {
    GCCAsmStmt::static_kind(),
};
}  // namespace

gap::generator<GCCAsmStmt> GCCAsmStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kGCCAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<GCCAsmStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kGCCAsmStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<GCCAsmStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kGCCAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<GCCAsmStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = GCCAsmStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool GCCAsmStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : GCCAsmStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<GCCAsmStmt, ir::Operation>> GCCAsmStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kGCCAsmStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<GCCAsmStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GCCAsmStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = GCCAsmStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<GCCAsmStmt> GCCAsmStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool GCCAsmStmt::contains(const Decl &decl) {
  for (auto &parent : GCCAsmStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool GCCAsmStmt::contains(const Stmt &stmt) {
  for (auto &parent : GCCAsmStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<GCCAsmStmt> GCCAsmStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<GCCAsmStmt> GCCAsmStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<GCCAsmStmt> GCCAsmStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case GCCAsmStmt::static_kind():
      return reinterpret_cast<const GCCAsmStmt &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const Reference &r) {
  return GCCAsmStmt::from(r.as_statement());
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

StringLiteral GCCAsmStmt::assembly_string(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return StringLiteral::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token GCCAsmStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

bool GCCAsmStmt::is_assembly_goto(void) const {
  return impl->reader.getVal23();
}

unsigned GCCAsmStmt::num_labels(void) const {
  return impl->reader.getVal29().size();
}

std::optional<AddrLabelExpr> GCCAsmStmt::nth_label(unsigned n) const {
  auto list = impl->reader.getVal29();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return AddrLabelExpr::from_base(std::move(e));
}

gap::generator<AddrLabelExpr> GCCAsmStmt::labels(void) const & {
  auto list = impl->reader.getVal29();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d29 = ep->StmtFor(ep, v)) {
      if (auto e = AddrLabelExpr::from_base(std::move(d29))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned GCCAsmStmt::num_output_constraint_literals(void) const {
  return impl->reader.getVal52().size();
}

std::optional<StringLiteral> GCCAsmStmt::nth_output_constraint_literal(unsigned n) const {
  auto list = impl->reader.getVal52();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return StringLiteral::from_base(std::move(e));
}

gap::generator<StringLiteral> GCCAsmStmt::output_constraint_literals(void) const & {
  auto list = impl->reader.getVal52();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d52 = ep->StmtFor(ep, v)) {
      if (auto e = StringLiteral::from_base(std::move(d52))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> GCCAsmStmt::output_names(void) const & {
  auto list = impl->reader.getVal64();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned GCCAsmStmt::num_input_constraint_literals(void) const {
  return impl->reader.getVal53().size();
}

std::optional<StringLiteral> GCCAsmStmt::nth_input_constraint_literal(unsigned n) const {
  auto list = impl->reader.getVal53();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return StringLiteral::from_base(std::move(e));
}

gap::generator<StringLiteral> GCCAsmStmt::input_constraint_literals(void) const & {
  auto list = impl->reader.getVal53();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d53 = ep->StmtFor(ep, v)) {
      if (auto e = StringLiteral::from_base(std::move(d53))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> GCCAsmStmt::input_names(void) const & {
  auto list = impl->reader.getVal66();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned GCCAsmStmt::num_clobber_string_literals(void) const {
  return impl->reader.getVal54().size();
}

std::optional<StringLiteral> GCCAsmStmt::nth_clobber_string_literal(unsigned n) const {
  auto list = impl->reader.getVal54();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return StringLiteral::from_base(std::move(e));
}

gap::generator<StringLiteral> GCCAsmStmt::clobber_string_literals(void) const & {
  auto list = impl->reader.getVal54();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d54 = ep->StmtFor(ep, v)) {
      if (auto e = StringLiteral::from_base(std::move(d54))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned GCCAsmStmt::num_label_expressions(void) const {
  return impl->reader.getVal67().size();
}

std::optional<AddrLabelExpr> GCCAsmStmt::nth_label_expression(unsigned n) const {
  auto list = impl->reader.getVal67();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return AddrLabelExpr::from_base(std::move(e));
}

gap::generator<AddrLabelExpr> GCCAsmStmt::label_expressions(void) const & {
  auto list = impl->reader.getVal67();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d67 = ep->StmtFor(ep, v)) {
      if (auto e = AddrLabelExpr::from_base(std::move(d67))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> GCCAsmStmt::label_names(void) const & {
  auto list = impl->reader.getVal68();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
