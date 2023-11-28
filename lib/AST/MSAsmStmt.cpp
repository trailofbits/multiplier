// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSAsmStmt.h>
#include <multiplier/AST/AsmStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MSAsmStmt> MSAsmStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MSAsmStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MSAsmStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MSAsmStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<MSAsmStmt> MSAsmStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MSAsmStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSAsmStmt> MSAsmStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<MSAsmStmt> MSAsmStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = MSAsmStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<MSAsmStmt> MSAsmStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool MSAsmStmt::contains(const Decl &decl) {
  for (auto &parent : MSAsmStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool MSAsmStmt::contains(const Stmt &stmt) {
  for (auto &parent : MSAsmStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<MSAsmStmt> MSAsmStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<MSAsmStmt> MSAsmStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const StmtKind kMSAsmStmtDerivedKinds[] = {
    MSAsmStmt::static_kind(),
};

}  // namespace

std::optional<MSAsmStmt> MSAsmStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case MSAsmStmt::static_kind():
      return reinterpret_cast<const MSAsmStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MSAsmStmt> MSAsmStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kMSAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<MSAsmStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSAsmStmt> MSAsmStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kMSAsmStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<MSAsmStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSAsmStmt> MSAsmStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kMSAsmStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<MSAsmStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MSAsmStmt> MSAsmStmt::from(const Reference &r) {
  return MSAsmStmt::from(r.as_statement());
}

std::optional<MSAsmStmt> MSAsmStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<MSAsmStmt> MSAsmStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

gap::generator<std::string_view> MSAsmStmt::all_constraints(void) const & {
  auto list = impl->reader.getVal64();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
co_yield std::string_view(v.cStr(), v.size());
  }
  co_return;
}

unsigned MSAsmStmt::num_all_expressions(void) const {
  return impl->reader.getVal29().size();
}

std::optional<Expr> MSAsmStmt::nth_all_expression(unsigned n) const {
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

gap::generator<Expr> MSAsmStmt::all_expressions(void) const & {
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

std::string_view MSAsmStmt::assembly_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal65();
  return std::string_view(data.cStr(), data.size());
}

Token MSAsmStmt::l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal10());
}

bool MSAsmStmt::has_braces(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
