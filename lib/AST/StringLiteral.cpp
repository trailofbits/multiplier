// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StringLiteral.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
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
static const StmtKind kStringLiteralDerivedKinds[] = {
    StringLiteral::static_kind(),
};
}  // namespace

gap::generator<StringLiteral> StringLiteral::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kStringLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<StringLiteral> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StringLiteral> StringLiteral::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kStringLiteralDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<StringLiteral> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<StringLiteral> StringLiteral::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kStringLiteralDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<StringLiteral> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StringLiteral> StringLiteral::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = StringLiteral::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool StringLiteral::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : StringLiteral::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<StringLiteral> StringLiteral::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<StringLiteral, ir::Operation>> StringLiteral::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kStringLiteralDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<StringLiteral, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<StringLiteral> StringLiteral::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = StringLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<StringLiteral> StringLiteral::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<StringLiteral> StringLiteral::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = StringLiteral::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<StringLiteral> StringLiteral::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool StringLiteral::contains(const Decl &decl) {
  for (auto &parent : StringLiteral::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool StringLiteral::contains(const Stmt &stmt) {
  for (auto &parent : StringLiteral::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<StringLiteral> StringLiteral::by_id(const Index &index, EntityId eid) {
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

std::optional<StringLiteral> StringLiteral::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<StringLiteral> StringLiteral::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case StringLiteral::static_kind():
      return reinterpret_cast<const StringLiteral &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<StringLiteral> StringLiteral::from(const Reference &r) {
  return StringLiteral::from(r.as_statement());
}

std::optional<StringLiteral> StringLiteral::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<StringLiteral> StringLiteral::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<bool> StringLiteral::contains_non_ascii(void) const {
  if (!impl->reader.getVal85()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal84());
  }
  return std::nullopt;
}

std::optional<bool> StringLiteral::contains_non_ascii_or_null(void) const {
  if (!impl->reader.getVal87()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal86());
  }
  return std::nullopt;
}

uint32_t StringLiteral::byte_length(void) const {
  return impl->reader.getVal26();
}

std::string_view StringLiteral::bytes(void) const {
  capnp::Text::Reader data = impl->reader.getVal61();
  return std::string_view(data.cStr(), data.size());
}

uint32_t StringLiteral::character_byte_width(void) const {
  return impl->reader.getVal100();
}

StringLiteralKind StringLiteral::literal_kind(void) const {
  return static_cast<StringLiteralKind>(impl->reader.getVal89());
}

uint32_t StringLiteral::length(void) const {
  return impl->reader.getVal101();
}

uint32_t StringLiteral::num_concatenated(void) const {
  return impl->reader.getVal102();
}

std::optional<std::string_view> StringLiteral::string(void) const {
  if (!impl->reader.getVal88()) {
    return std::nullopt;
  } else {
    capnp::Text::Reader data = impl->reader.getVal66();
    return std::string_view(data.cStr(), data.size());
  }
  return std::nullopt;
}

bool StringLiteral::is_ordinary(void) const {
  return impl->reader.getVal90();
}

bool StringLiteral::is_pascal(void) const {
  return impl->reader.getVal92();
}

bool StringLiteral::is_utf16(void) const {
  return impl->reader.getVal93();
}

bool StringLiteral::is_utf32(void) const {
  return impl->reader.getVal94();
}

bool StringLiteral::is_utf8(void) const {
  return impl->reader.getVal95();
}

bool StringLiteral::is_unevaluated(void) const {
  return impl->reader.getVal96();
}

bool StringLiteral::is_wide(void) const {
  return impl->reader.getVal97();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
