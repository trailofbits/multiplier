// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CallingConv.h>
#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class FunctionType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FunctionType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<FunctionType> in(const Index &index);
  static gap::generator<FunctionType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FunctionType> by_id(const Index &, EntityId);

  static std::optional<FunctionType> from_base(const Type &parent);
  inline static std::optional<FunctionType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<FunctionType> from(const std::optional<Type> &parent);
  static std::optional<FunctionType> from(const Reference &r);
  static std::optional<FunctionType> from(const VariantEntity &e);
  static std::optional<FunctionType> from(const TokenContext &t);

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
