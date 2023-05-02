// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCDictionaryLiteral.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCDictionaryLiteral::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCDictionaryLiteral::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCDictionaryLiteral::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCDictionaryLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCDictionaryLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCDictionaryLiteral::contains(const Decl &decl) {
  for (auto &parent : ObjCDictionaryLiteral::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCDictionaryLiteral::contains(const Stmt &stmt) {
  for (auto &parent : ObjCDictionaryLiteral::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCDictionaryLiteral::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCDictionaryLiteralDerivedKinds[] = {
    ObjCDictionaryLiteral::static_kind(),
};

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCDictionaryLiteral::static_kind():
      return reinterpret_cast<const ObjCDictionaryLiteral &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCDictionaryLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCDictionaryLiteral> e = ObjCDictionaryLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCDictionaryLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCDictionaryLiteral> e = ObjCDictionaryLiteral::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCDictionaryLiteral> ObjCDictionaryLiteral::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCDictionaryLiteralDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCDictionaryLiteral> e = ObjCDictionaryLiteral::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const Reference &r) {
  return ObjCDictionaryLiteral::from(r.as_statement());
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const TokenContext &t) {
  return ObjCDictionaryLiteral::from(t.as_statement());
}

ObjCMethodDecl ObjCDictionaryLiteral::dictionary_with_objects_method(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
