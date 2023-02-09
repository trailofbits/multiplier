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

#include "CallingConv.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class FunctionType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FunctionType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<FunctionType> in(const Fragment &frag);
  static gap::generator<FunctionType> in(const Index &index);
  static gap::generator<FunctionType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<FunctionType> by(const Index &, EntityId);

  inline static std::optional<FunctionType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<FunctionType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<FunctionType> from(const Type &parent);

  inline static std::optional<FunctionType> from(const std::optional<Type> &parent) {
    if (parent) {
      return FunctionType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CallingConv call_conv(void) const;
  Type call_result_type(void) const;
  bool cmse_ns_call_attribute(void) const;
  bool has_reg_parm(void) const;
  bool no_return_attribute(void) const;
  Type return_type(void) const;
  bool is_const(void) const;
  bool is_restrict(void) const;
  bool is_volatile(void) const;
};

static_assert(sizeof(FunctionType) == sizeof(Type));

#endif
} // namespace mx
