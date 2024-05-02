// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/coro/generator.hpp>
#include <memory>
#include <optional>
#include <type_traits>
#include <utility>

#include "../Compiler.h"

namespace mlir {
class Value;
namespace detail {
class BlockArgumentImpl;
class OpResultImpl;
class ValueImpl;
}  // namespace detail
}  // namespace mlir
namespace mx::ir {

class Operation;
class Block;
class Argument;
class Operand;
class Result;
class SourceIRImpl;
class Type;

enum ValueKind : unsigned char {
  OPERATION_RESULT,
  BLOCK_ARGUMENT
};

inline static const char *EnumerationName(ValueKind) {
  return "ValueKind";
}

MX_EXPORT const char *EnumeratorName(ValueKind);

inline static constexpr unsigned NumEnumerators(ValueKind) {
  return 2;
}

// The result of an operation, or an argument to a block. Values can
// have an arbitrary number of users.
class MX_EXPORT Value {
 protected:
  friend class Operand;
  friend class Operation;
  friend class Block;
  friend class Argument;
  friend class Result;

  std::shared_ptr<const SourceIRImpl> module_;

  union Impl {
    void *opaque;
    mlir::detail::ValueImpl *value;
    mlir::detail::BlockArgumentImpl *arg;
    mlir::detail::OpResultImpl *result;

    inline Impl(void *opaque_)
        : opaque(opaque_) {}

  } impl_;

 public:

  inline Value(std::shared_ptr<const SourceIRImpl> module, void *value)
      : module_(std::move(module)),
        impl_(value) {}

  ValueKind kind(void) const noexcept;

  Type type(void) const noexcept;

  // Generate the uses of this value.
  gap::generator<Operand> uses(void) const & noexcept;

  inline void *underlying_value(void) const noexcept {
    return impl_.opaque;
  }

  bool operator==(const Value &that) const noexcept;
  bool operator!=(const Value &that) const noexcept = default;
};

// A value with a specific type.
template <typename T>
class MX_EXPORT TypedValue : public Value {
 public:
  static_assert(std::is_base_of_v<Type, T>);

  inline T type(void) const noexcept {
    return reinterpret_cast<const T &>(Value::type());
  }
};

}  // namespace mx::ir
