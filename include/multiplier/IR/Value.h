// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <memory>
#include <optional>

namespace mlir {
class Value;
class ValueImpl;
}  // namespace mlir
namespace mx::ir {

class Operation;
class Block;
class BlockArgument;

// The result of an operation, or an argument to a block. Values can
// have an arbitrary number of users.
class Value final {
 private:
  friend class Operation;
  friend class Block;
  friend class BlockArgument;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::ValueImpl *value_;
 public:
  inline Value(std::shared_ptr<const SourceIRImpl> module,
               mlir::ValueImpl *value)
      : module_(std::move(module)),
        value_(value) {}

  std::optional<Operation> as_result(void) const noexcept;
  std::optional<BlockArgument> as_argument(void) const noexcept;
  Type type(void) const noexcept;
};

}  // namespace mx::ir