// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "FunctionType.h"

namespace mx {
class EntityProvider;
class Index;
class FunctionNoProtoType;
class FunctionType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FunctionNoProtoType : public FunctionType {
 private:
  friend class FragmentImpl;
  friend class FunctionType;
  friend class Type;
 public:
  static gap::generator<FunctionNoProtoType> in(const Index &index);
  static gap::generator<FunctionNoProtoType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FunctionNoProtoType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::FUNCTION_NO_PROTO;
  }

  static std::optional<FunctionNoProtoType> from(const Type &parent);

  inline static std::optional<FunctionNoProtoType> from(const std::optional<Type> &parent) {
    if (parent) {
      return FunctionNoProtoType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionNoProtoType> from(const Reference &r);
  static std::optional<FunctionNoProtoType> from(const TokenContext &t);

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(FunctionNoProtoType) == sizeof(FunctionType));

#endif
} // namespace mx
