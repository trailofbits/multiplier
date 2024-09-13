// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AsmStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/GCCAsmStmt.h>
#include <multiplier/AST/MSAsmStmt.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kAsmStmtDerivedKinds[] = {
    GCCAsmStmt::static_kind(),
    MSAsmStmt::static_kind(),
};
}  // namespace

gap::generator<AsmStmt> AsmStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AsmStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AsmStmt> AsmStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAsmStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AsmStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<AsmStmt> AsmStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AsmStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AsmStmt> AsmStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AsmStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AsmStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AsmStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AsmStmt> AsmStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<AsmStmt, ir::Operation>> AsmStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kAsmStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<AsmStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<AsmStmt> AsmStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AsmStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AsmStmt> AsmStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<AsmStmt> AsmStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = AsmStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<AsmStmt> AsmStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool AsmStmt::contains(const Decl &decl) {
  for (auto &parent : AsmStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool AsmStmt::contains(const Stmt &stmt) {
  for (auto &parent : AsmStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<AsmStmt> AsmStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<AsmStmt> AsmStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<AsmStmt> AsmStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case GCCAsmStmt::static_kind():
    case MSAsmStmt::static_kind():
      return reinterpret_cast<const AsmStmt &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<AsmStmt> AsmStmt::from(const Reference &r) {
  return AsmStmt::from(r.as_statement());
}

std::optional<AsmStmt> AsmStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<AsmStmt> AsmStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::string_view AsmStmt::generate_assembly_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Token AsmStmt::assembly_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

unsigned AsmStmt::num_inputs(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> AsmStmt::nth_input(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> AsmStmt::inputs(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

bool AsmStmt::is_simple(void) const {
  return impl->reader.getVal12();
}

bool AsmStmt::is_volatile(void) const {
  return impl->reader.getVal16();
}

unsigned AsmStmt::num_outputs(void) const {
  return impl->reader.getVal27().size();
}

std::optional<Expr> AsmStmt::nth_output(unsigned n) const {
  auto list = impl->reader.getVal27();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> AsmStmt::outputs(void) const & {
  auto list = impl->reader.getVal27();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d27 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d27))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> AsmStmt::output_constraints(void) const & {
  auto list = impl->reader.getVal62();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned AsmStmt::num_output_expressions(void) const {
  return impl->reader.getVal28().size();
}

std::optional<Expr> AsmStmt::nth_output_expression(unsigned n) const {
  auto list = impl->reader.getVal28();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> AsmStmt::output_expressions(void) const & {
  auto list = impl->reader.getVal28();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d28 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d28))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> AsmStmt::input_constraints(void) const & {
  auto list = impl->reader.getVal63();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned AsmStmt::num_input_expressions(void) const {
  return impl->reader.getVal29().size();
}

std::optional<Expr> AsmStmt::nth_input_expression(unsigned n) const {
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
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> AsmStmt::input_expressions(void) const & {
  auto list = impl->reader.getVal29();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d29 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d29))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> AsmStmt::clobbers(void) const & {
  auto list = impl->reader.getVal64();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
