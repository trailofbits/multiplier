// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LabelStmt.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/LabelDecl.h>
#include <multiplier/AST/Stmt.h>
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
static const StmtKind kLabelStmtDerivedKinds[] = {
    LabelStmt::static_kind(),
};
}  // namespace

gap::generator<LabelStmt> LabelStmt::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kLabelStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<LabelStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LabelStmt> LabelStmt::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kLabelStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<LabelStmt> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<LabelStmt> LabelStmt::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kLabelStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<LabelStmt> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LabelStmt> LabelStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LabelStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LabelStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LabelStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<LabelStmt> LabelStmt::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<LabelStmt, ir::Operation>> LabelStmt::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kLabelStmtDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<LabelStmt, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<LabelStmt> LabelStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = LabelStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LabelStmt> LabelStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LabelStmt> LabelStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = LabelStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LabelStmt> LabelStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LabelStmt::contains(const Decl &decl) {
  for (auto &parent : LabelStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LabelStmt::contains(const Stmt &stmt) {
  for (auto &parent : LabelStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<LabelStmt> LabelStmt::by_id(const Index &index, EntityId eid) {
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

std::optional<LabelStmt> LabelStmt::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<LabelStmt> LabelStmt::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case LabelStmt::static_kind():
      return reinterpret_cast<const LabelStmt &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<LabelStmt> LabelStmt::from(const Reference &r) {
  return LabelStmt::from(r.as_statement());
}

std::optional<LabelStmt> LabelStmt::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<LabelStmt> LabelStmt::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

LabelDecl LabelStmt::declaration(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return LabelDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token LabelStmt::identifier_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

std::string_view LabelStmt::name(void) const {
  capnp::Text::Reader data = impl->reader.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Stmt LabelStmt::sub_statement(void) const {
  RawEntityId eid = impl->reader.getVal13();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

bool LabelStmt::is_side_entry(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
