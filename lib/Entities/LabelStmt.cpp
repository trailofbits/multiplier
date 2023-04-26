// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LabelStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/LabelDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return LabelStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kLabelStmtDerivedKinds[] = {
    LabelStmt::static_kind(),
};

std::optional<LabelStmt> LabelStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case LabelStmt::static_kind():
      return reinterpret_cast<const LabelStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LabelStmt> LabelStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kLabelStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<LabelStmt> e = LabelStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LabelStmt> LabelStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kLabelStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<LabelStmt> e = LabelStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LabelStmt> LabelStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kLabelStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<LabelStmt> e = LabelStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LabelStmt> LabelStmt::from(const Reference &r) {
  return LabelStmt::from(r.as_statement());
}

std::optional<LabelStmt> LabelStmt::from(const TokenContext &t) {
  return LabelStmt::from(t.as_statement());
}

LabelDecl LabelStmt::declaration(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return LabelDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token LabelStmt::identifier_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal11());
}

std::string_view LabelStmt::name(void) const {
  capnp::Text::Reader data = impl->reader.getVal60();
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
