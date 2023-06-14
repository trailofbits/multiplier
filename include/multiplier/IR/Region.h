// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gap/core/generator.hpp>
#include <memory>

namespace mlir {
class Region;
}  // namespace mlir
namespace mx::ir {

class Block;
class BlockArgument;
class Operation;

// A region is owned by an operation (not all operations own regions)
// and contain one or more blocks.
class Region final {
 private:
  friend class Operation;
  friend class Block;
  friend class BlockArgument;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::Region *region_;

 public:
  inline Value(std::shared_ptr<const SourceIRImpl> module,
               mlir::Region *region)
      : module_(std::move(module)),
        region_(region) {}

  static Region containing(const Block &);
  gap::generator<Block> blocks(void) const & noexcept;
};

}  // namespace mx::ir