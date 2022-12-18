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

#include "CallingConv.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class FunctionType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FunctionTypeRange = DerivedEntityRange<TypeIterator, FunctionType>;
using FunctionTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, FunctionType>;
class FunctionType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static FunctionTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FunctionTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FunctionType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static std::optional<FunctionType> from(const TokenContext &c);
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
