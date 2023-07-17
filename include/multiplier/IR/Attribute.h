// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <memory>
#include <optional>

namespace mlir {
namespace detail {
class AttributeStorage;
}  // namespace detail
}  // namespace mlir
namespace mx::ir {

class Operation;
class Block;
class Argument;
class SourceIRImpl;
class Type;

enum AttributeKind : unsigned;

// The type of some operation / value.
class Attribute final {
 private:
  friend class Operation;
  friend class Block;
  friend class Argument;
  friend class Value;

  std::shared_ptr<const SourceIRImpl> module_;
  mlir::detail::AttributeStorage *attr_;
  AttributeKind kind_;

  inline Attribute(std::shared_ptr<const SourceIRImpl> module,
                   mlir::detail::AttributeStorage *attr)
      : module_(std::move(module)),
        attr_(attr),
        kind_(classify(attr)) {}

 public:
  inline Attribute(std::shared_ptr<const SourceIRImpl> module,
                   void *attr)
      : Attribute(std::move(module),
                  reinterpret_cast<mlir::detail::AttributeStorage *>(attr)) {}

  static AttributeKind classify(mlir::detail::AttributeStorage *attr);

  inline AttributeKind kind(void) const noexcept {
    return kind_;
  }
};

}  // namespace mx::ir
