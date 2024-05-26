// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CanThrowResult.h>
#include <multiplier/AST/ExceptionSpecificationType.h>
#include <multiplier/AST/FunctionType.h>
#include <multiplier/AST/RefQualifierKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Expr;
class FunctionDecl;
class FunctionProtoType;
class FunctionType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FunctionProtoType : public FunctionType {
 private:
  friend class FragmentImpl;
  friend class FunctionType;
  friend class Type;
 public:
  static gap::generator<FunctionProtoType> in(const Index &index);
  static gap::generator<FunctionProtoType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::FUNCTION_PROTO;
  }

  static std::optional<FunctionProtoType> by_id(const Index &, EntityId);

  static std::optional<FunctionProtoType> from_base(const Type &parent);
  inline static std::optional<FunctionProtoType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<FunctionProtoType> from(const std::optional<Type> &parent);
  static std::optional<FunctionProtoType> from(const Reference &r);
  static std::optional<FunctionProtoType> from(const VariantEntity &e);
  static std::optional<FunctionProtoType> from(const TokenContext &t);

  std::optional<CanThrowResult> can_throw(void) const;
  Token ellipsis_token(void) const;
  std::optional<FunctionDecl> exception_spec_declaration(void) const;
  std::optional<FunctionDecl> exception_spec_template(void) const;
  ExceptionSpecificationType exception_spec_type(void) const;
  std::optional<Expr> noexcept_expression(void) const;
  std::optional<Type> nth_parameter_type(unsigned n) const;
  unsigned num_parameter_types(void) const;
  gap::generator<Type> parameter_types(void) const &;
  RefQualifierKind reference_qualifier(void) const;
  bool has_dependent_exception_spec(void) const;
  bool has_dynamic_exception_spec(void) const;
  bool has_exception_spec(void) const;
  bool has_ext_parameter_infos(void) const;
  bool has_instantiation_dependent_exception_spec(void) const;
  bool has_noexcept_exception_spec(void) const;
  bool has_trailing_return(void) const;
  std::optional<bool> is_nothrow(void) const;
  bool is_sugared(void) const;
  bool is_template_variadic(void) const;
  bool is_variadic(void) const;
  std::optional<Type> nth_exception_type(unsigned n) const;
  unsigned num_exception_types(void) const;
  gap::generator<Type> exception_types(void) const &;
};

static_assert(sizeof(FunctionProtoType) == sizeof(FunctionType));

#endif
} // namespace mx
