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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "BuiltinTypeKind.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class BuiltinType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BuiltinType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<BuiltinType> in(const Fragment &frag);
  static gap::generator<BuiltinType> in(const File &file);
  static gap::generator<BuiltinType> in(const Index &index);
  static gap::generator<BuiltinType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BuiltinType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN;
  }

  static std::optional<BuiltinType> from(const Type &parent);

  inline static std::optional<BuiltinType> from(const std::optional<Type> &parent) {
    if (parent) {
      return BuiltinType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<BuiltinType> from(const Reference &r) {
    return BuiltinType::from(r.as_type());
  }

  inline static std::optional<BuiltinType> from(const TokenContext &t) {
    return BuiltinType::from(t.as_type());
  }

  Type desugar(void) const;
  BuiltinTypeKind builtin_kind(void) const;
  bool is_floating_point(void) const;
  bool is_integer(void) const;
  bool is_sve_bool(void) const;
  bool is_signed_integer(void) const;
  bool is_sugared(void) const;
  bool is_unsigned_integer(void) const;
};

static_assert(sizeof(BuiltinType) == sizeof(Type));

#endif
} // namespace mx
