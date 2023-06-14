// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <memory>

namespace mlir {
class Block;
}  // namespace mlir
namespace mx::ir {

class BlockArgument;
class Operation;
class Region;

// A region is owned by an operation (not all operations own regions)
// and contain one or more blocks.
class Block final {
 private:
  friend class Operation;
  friend class Region;
  friend class BlockArgument;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::Block *block_;

 public:
  inline Value(std::shared_ptr<const SourceIRImpl> module,
               mlir::Block *block)
      : module_(std::move(module)),
        block_(block) {}

  gap::generator<Operation> operations(void) const & noexcept;
};

}  // namespace mx::ir