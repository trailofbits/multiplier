// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AsmStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/GCCAsmStmt.h>
#include <multiplier/Entities/MSAsmStmt.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    if (parent == *this) { return true; }
  }
  return false;
}

bool AsmStmt::contains(const Stmt &stmt) {
  for (auto &parent : AsmStmt::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<AsmStmt> AsmStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return AsmStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kAsmStmtDerivedKinds[] = {
    GCCAsmStmt::static_kind(),
    MSAsmStmt::static_kind(),
};

std::optional<AsmStmt> AsmStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case GCCAsmStmt::static_kind():
    case MSAsmStmt::static_kind():
      return reinterpret_cast<const AsmStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AsmStmt> AsmStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<AsmStmt> e = AsmStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AsmStmt> AsmStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<AsmStmt> e = AsmStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AsmStmt> AsmStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kAsmStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<AsmStmt> e = AsmStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AsmStmt> AsmStmt::from(const Reference &r) {
  return AsmStmt::from(r.as_statement());
}

std::optional<AsmStmt> AsmStmt::from(const TokenContext &t) {
  return AsmStmt::from(t.as_statement());
}

std::string_view AsmStmt::generate_assembly_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal60();
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
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> AsmStmt::inputs(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d15)))) {
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
  return impl->reader.getVal26().size();
}

std::optional<Expr> AsmStmt::nth_output(unsigned n) const {
  auto list = impl->reader.getVal26();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> AsmStmt::outputs(void) const & {
  auto list = impl->reader.getVal26();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d26 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d26)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> AsmStmt::output_constraints(void) const & {
  auto list = impl->reader.getVal61();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned AsmStmt::num_output_expressions(void) const {
  return impl->reader.getVal27().size();
}

std::optional<Expr> AsmStmt::nth_output_expression(unsigned n) const {
  auto list = impl->reader.getVal27();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> AsmStmt::output_expressions(void) const & {
  auto list = impl->reader.getVal27();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d27 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d27)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> AsmStmt::input_constraints(void) const & {
  auto list = impl->reader.getVal62();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned AsmStmt::num_input_expressions(void) const {
  return impl->reader.getVal28().size();
}

std::optional<Expr> AsmStmt::nth_input_expression(unsigned n) const {
  auto list = impl->reader.getVal28();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from(Stmt(std::move(e)));
}

gap::generator<Expr> AsmStmt::input_expressions(void) const & {
  auto list = impl->reader.getVal28();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d28 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from(Stmt(std::move(d28)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<std::string_view> AsmStmt::clobbers(void) const & {
  auto list = impl->reader.getVal63();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
