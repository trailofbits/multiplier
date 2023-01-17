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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "CanThrowResult.h"
#include "DeclUseSelector.h"
#include "ExceptionSpecificationType.h"
#include "FunctionType.h"
#include "RefQualifierKind.h"
#include "StmtUseSelector.h"
#include "TypeKind.h"

namespace mx {
class Expr;
class FunctionDecl;
class FunctionProtoType;
class FunctionType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FunctionProtoType : public FunctionType {
 private:
  friend class FragmentImpl;
  friend class FunctionType;
  friend class Type;
 public:
  inline static gap::generator<FunctionProtoType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<FunctionProtoType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FunctionProtoType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::FUNCTION_PROTO;
  }

  static std::optional<FunctionProtoType> from(const TokenContext &c);
  static std::optional<FunctionProtoType> from(const FunctionType &parent);

  inline static std::optional<FunctionProtoType> from(const std::optional<FunctionType> &parent) {
    if (parent) {
      return FunctionProtoType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionProtoType> from(const Type &parent);

  inline static std::optional<FunctionProtoType> from(const std::optional<Type> &parent) {
    if (parent) {
      return FunctionProtoType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<CanThrowResult> can_throw(void) const;
  Type desugar(void) const;
  Token ellipsis_token(void) const;
  std::optional<FunctionDecl> exception_spec_declaration(void) const;
  std::optional<FunctionDecl> exception_spec_template(void) const;
  ExceptionSpecificationType exception_spec_type(void) const;
  std::optional<Expr> noexcept_expression(void) const;
  std::vector<Type> parameter_types(void) const;
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
  std::vector<Type> exception_types(void) const;
};

static_assert(sizeof(FunctionProtoType) == sizeof(FunctionType));

#endif
} // namespace mx
