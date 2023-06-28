// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/core/generator.hpp>
#include <memory>
#include <optional>
#include <utility>

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

// The result of an operation, or an argument to a block. Values can
// have an arbitrary number of users.
class Value {
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

  inline Value(std::shared_ptr<const SourceIRImpl> module, void *value)
      : module_(std::move(module)),
        impl_(value) {}

 public:

  Type type(void) const noexcept;

  // Generate the uses of this value.
  gap::generator<Operand> uses(void) const & noexcept;
};

}  // namespace mx::ir