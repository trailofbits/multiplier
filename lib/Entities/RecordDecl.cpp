// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RecordDecl.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/Entities/ClassTemplateSpecializationDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    if (parent == *this) { return true; }
  }
  return false;
}

bool RecordDecl::contains(const Stmt &stmt) {
  for (auto &parent : RecordDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<RecordDecl> RecordDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<RecordDecl> dr = RecordDecl::from(r)) {
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
    return RecordDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kRecordDeclDerivedKinds[] = {
    RecordDecl::static_kind(),
    CXXRecordDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<RecordDecl> RecordDecl::from(const Decl &parent) {
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
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kRecordDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<RecordDecl> e = RecordDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecordDecl> RecordDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kRecordDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<RecordDecl> e = RecordDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<RecordDecl> RecordDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kRecordDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<RecordDecl> e = RecordDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

bool RecordDecl::can_pass_in_registers(void) const {
  return impl->reader.getVal100();
}

unsigned RecordDecl::num_fields(void) const {
  return impl->reader.getVal58().size();
}

std::optional<FieldDecl> RecordDecl::nth_field(unsigned n) const {
  auto list = impl->reader.getVal58();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return FieldDecl::from(Decl(std::move(e)));
}

gap::generator<FieldDecl> RecordDecl::fields(void) const & {
  auto list = impl->reader.getVal58();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d58 = ep->DeclFor(ep, v)) {
      if (auto e = FieldDecl::from(Decl(std::move(d58)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

RecordDeclArgPassingKind RecordDecl::argument_passing_restrictions(void) const {
  return static_cast<RecordDeclArgPassingKind>(impl->reader.getVal79());
}

bool RecordDecl::has_flexible_array_member(void) const {
  return impl->reader.getVal101();
}

bool RecordDecl::has_loaded_fields_from_external_storage(void) const {
  return impl->reader.getVal102();
}

bool RecordDecl::has_non_trivial_to_primitive_copy_c_union(void) const {
  return impl->reader.getVal103();
}

bool RecordDecl::has_non_trivial_to_primitive_default_initialize_c_union(void) const {
  return impl->reader.getVal104();
}

bool RecordDecl::has_non_trivial_to_primitive_destruct_c_union(void) const {
  return impl->reader.getVal105();
}

bool RecordDecl::has_object_member(void) const {
  return impl->reader.getVal106();
}

bool RecordDecl::has_volatile_member(void) const {
  return impl->reader.getVal107();
}

bool RecordDecl::is_anonymous_struct_or_union(void) const {
  return impl->reader.getVal108();
}

bool RecordDecl::is_captured_record(void) const {
  return impl->reader.getVal109();
}

bool RecordDecl::is_injected_class_name(void) const {
  return impl->reader.getVal110();
}

bool RecordDecl::is_lambda(void) const {
  return impl->reader.getVal111();
}

bool RecordDecl::is_ms_struct(void) const {
  return impl->reader.getVal112();
}

bool RecordDecl::is_non_trivial_to_primitive_copy(void) const {
  return impl->reader.getVal113();
}

bool RecordDecl::is_non_trivial_to_primitive_default_initialize(void) const {
  return impl->reader.getVal114();
}

bool RecordDecl::is_non_trivial_to_primitive_destroy(void) const {
  return impl->reader.getVal115();
}

bool RecordDecl::is_or_contains_union(void) const {
  return impl->reader.getVal116();
}

bool RecordDecl::is_parameter_destroyed_in_callee(void) const {
  return impl->reader.getVal117();
}

bool RecordDecl::is_randomized(void) const {
  return impl->reader.getVal118();
}

bool RecordDecl::may_insert_extra_padding(void) const {
  return impl->reader.getVal119();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
