// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "RecordDeclArgPassingKind.h"
#include "TagDecl.h"

namespace mx {
class Decl;
class FieldDecl;
class NamedDecl;
class RecordDecl;
class TagDecl;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RecordDeclRange = DerivedEntityRange<DeclIterator, RecordDecl>;
using RecordDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, RecordDecl>;
using RecordDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, RecordDecl>;

class RecordDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static RecordDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RecordDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : RecordDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::RECORD;
  }

  static RecordDeclContainingDeclRange containing(const Decl &decl);
  static RecordDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<RecordDecl> from(const TokenContext &c);
  static std::optional<RecordDecl> from(const TagDecl &parent);

  inline static std::optional<RecordDecl> from(const std::optional<TagDecl> &parent) {
    if (parent) {
      return RecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RecordDecl> from(const TypeDecl &parent);

  inline static std::optional<RecordDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return RecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RecordDecl> from(const NamedDecl &parent);

  inline static std::optional<RecordDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return RecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RecordDecl> from(const Decl &parent);

  inline static std::optional<RecordDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return RecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool can_pass_in_registers(void) const;
  std::vector<FieldDecl> fields(void) const;
  RecordDeclArgPassingKind argument_passing_restrictions(void) const;
  bool has_flexible_array_member(void) const;
  bool has_loaded_fields_from_external_storage(void) const;
  bool has_non_trivial_to_primitive_copy_c_union(void) const;
  bool has_non_trivial_to_primitive_default_initialize_c_union(void) const;
  bool has_non_trivial_to_primitive_destruct_c_union(void) const;
  bool has_object_member(void) const;
  bool has_volatile_member(void) const;
  bool is_anonymous_struct_or_union(void) const;
  bool is_captured_record(void) const;
  bool is_injected_class_name(void) const;
  bool is_lambda(void) const;
  bool is_ms_struct(void) const;
  bool is_non_trivial_to_primitive_copy(void) const;
  bool is_non_trivial_to_primitive_default_initialize(void) const;
  bool is_non_trivial_to_primitive_destroy(void) const;
  bool is_or_contains_union(void) const;
  bool is_parameter_destroyed_in_callee(void) const;
  bool is_randomized(void) const;
  bool may_insert_extra_padding(void) const;
};

static_assert(sizeof(RecordDecl) == sizeof(TagDecl));

#endif
} // namespace mx
