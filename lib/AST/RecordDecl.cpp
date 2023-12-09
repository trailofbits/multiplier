// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RecordDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/ClassTemplateSpecializationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kRecordDeclDerivedKinds[] = {
    RecordDecl::static_kind(),
    CXXRecordDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};
}  // namespace

gap::generator<RecordDecl> RecordDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RecordDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RecordDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RecordDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<RecordDecl> RecordDecl::from(const ir::hl::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<RecordDecl, ir::hl::Operation>> RecordDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::hl::Operation> res : Decl::in(tu, kRecordDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<RecordDecl, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<RecordDecl> RecordDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = RecordDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RecordDecl> RecordDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<RecordDecl> RecordDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = RecordDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<RecordDecl> RecordDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool RecordDecl::contains(const Decl &decl) {
  for (auto &parent : RecordDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool RecordDecl::contains(const Stmt &stmt) {
  for (auto &parent : RecordDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

RecordDecl RecordDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (RecordDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<RecordDecl> RecordDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<RecordDecl> RecordDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<RecordDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<RecordDecl> RecordDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<RecordDecl> RecordDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<RecordDecl> RecordDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case RecordDecl::static_kind():
    case CXXRecordDecl::static_kind():
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const RecordDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RecordDecl> RecordDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kRecordDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<RecordDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecordDecl> RecordDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kRecordDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<RecordDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecordDecl> RecordDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kRecordDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<RecordDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<RecordDecl> RecordDecl::from(const Reference &r) {
  return RecordDecl::from(r.as_declaration());
}

std::optional<RecordDecl> RecordDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<RecordDecl> RecordDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool RecordDecl::can_pass_in_registers(void) const {
  return impl->reader.getVal104();
}

unsigned RecordDecl::num_fields(void) const {
  return impl->reader.getVal62().size();
}

std::optional<FieldDecl> RecordDecl::nth_field(unsigned n) const {
  auto list = impl->reader.getVal62();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return FieldDecl::from_base(std::move(e));
}

gap::generator<FieldDecl> RecordDecl::fields(void) const & {
  auto list = impl->reader.getVal62();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d62 = ep->DeclFor(ep, v)) {
      if (auto e = FieldDecl::from_base(std::move(d62))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

RecordDeclArgPassingKind RecordDecl::argument_passing_restrictions(void) const {
  return static_cast<RecordDeclArgPassingKind>(impl->reader.getVal85());
}

bool RecordDecl::has_flexible_array_member(void) const {
  return impl->reader.getVal105();
}

bool RecordDecl::has_loaded_fields_from_external_storage(void) const {
  return impl->reader.getVal106();
}

bool RecordDecl::has_non_trivial_to_primitive_copy_c_union(void) const {
  return impl->reader.getVal107();
}

bool RecordDecl::has_non_trivial_to_primitive_default_initialize_c_union(void) const {
  return impl->reader.getVal108();
}

bool RecordDecl::has_non_trivial_to_primitive_destruct_c_union(void) const {
  return impl->reader.getVal109();
}

bool RecordDecl::has_object_member(void) const {
  return impl->reader.getVal110();
}

bool RecordDecl::has_volatile_member(void) const {
  return impl->reader.getVal111();
}

bool RecordDecl::is_anonymous_struct_or_union(void) const {
  return impl->reader.getVal112();
}

bool RecordDecl::is_captured_record(void) const {
  return impl->reader.getVal113();
}

bool RecordDecl::is_injected_class_name(void) const {
  return impl->reader.getVal114();
}

bool RecordDecl::is_lambda(void) const {
  return impl->reader.getVal115();
}

bool RecordDecl::is_ms_struct(void) const {
  return impl->reader.getVal116();
}

bool RecordDecl::is_non_trivial_to_primitive_copy(void) const {
  return impl->reader.getVal117();
}

bool RecordDecl::is_non_trivial_to_primitive_default_initialize(void) const {
  return impl->reader.getVal118();
}

bool RecordDecl::is_non_trivial_to_primitive_destroy(void) const {
  return impl->reader.getVal119();
}

bool RecordDecl::is_or_contains_union(void) const {
  return impl->reader.getVal120();
}

bool RecordDecl::is_parameter_destroyed_in_callee(void) const {
  return impl->reader.getVal121();
}

bool RecordDecl::is_randomized(void) const {
  return impl->reader.getVal122();
}

bool RecordDecl::may_insert_extra_padding(void) const {
  return impl->reader.getVal123();
}

std::optional<uint64_t> RecordDecl::size(void) const {
  if (!impl->reader.getVal124()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal78());
  }
  return std::nullopt;
}

std::optional<uint64_t> RecordDecl::alignment(void) const {
  if (!impl->reader.getVal125()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal79());
  }
  return std::nullopt;
}

std::optional<uint64_t> RecordDecl::size_without_trailing_padding(void) const {
  if (!impl->reader.getVal126()) {
    return std::nullopt;
  } else {
    return static_cast<uint64_t>(impl->reader.getVal81());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
