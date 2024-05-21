// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/RecordArgPassingKind.h>
#include <multiplier/AST/TagDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Decl;
class FieldDecl;
class NamedDecl;
class RecordDecl;
class Stmt;
class TagDecl;
class Token;
class TypeDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT RecordDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<RecordDecl> in(const Index &index);
  static gap::generator<RecordDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RecordDecl> by_id(const Index &, EntityId);
  static gap::generator<RecordDecl> in(const Fragment &frag);
  static gap::generator<RecordDecl> in(const File &file);

  static std::optional<RecordDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<RecordDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::RECORD;
  }

  static gap::generator<RecordDecl> containing(const Decl &decl);
  static gap::generator<RecordDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<RecordDecl> containing(const Stmt &stmt);
  static gap::generator<RecordDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  RecordDecl canonical_declaration(void) const;
  std::optional<RecordDecl> definition(void) const;
  gap::generator<RecordDecl> redeclarations(void) const &;
  static std::optional<RecordDecl> from_base(const Decl &parent);
  inline static std::optional<RecordDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<RecordDecl> from(const std::optional<Decl> &parent);
  static std::optional<RecordDecl> from(const Reference &r);
  static std::optional<RecordDecl> from(const VariantEntity &e);
  static std::optional<RecordDecl> from(const TokenContext &t);

  bool can_pass_in_registers(void) const;
  std::optional<FieldDecl> nth_field(unsigned n) const;
  unsigned num_fields(void) const;
  gap::generator<FieldDecl> fields(void) const &;
  RecordArgPassingKind argument_passing_restrictions(void) const;
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
  std::optional<uint64_t> size(void) const;
  std::optional<uint64_t> alignment(void) const;
  std::optional<uint64_t> size_without_trailing_padding(void) const;
};

static_assert(sizeof(RecordDecl) == sizeof(TagDecl));

#endif
} // namespace mx
