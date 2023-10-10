// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <memory>
#include <optional>

namespace mlir {
class MLIRContext;
class TypeStorage;
}  // namespace mlir
namespace mx::ir {

class Operation;
class Block;
class Argument;
class SourceIRImpl;
class Type;

enum TypeKind : unsigned;

// The type of some operation / value.
class Type final {
 private:
  friend class Operation;
  friend class Block;
  friend class Argument;
  friend class Value;

  mlir::MLIRContext *context_;
  const mlir::TypeStorage *type_;

 public:
  inline Type(mlir::MLIRContext *context, const void *type)
      : context_(std::move(context)),
        type_(reinterpret_cast<const mlir::TypeStorage *>(type)) {}

  TypeKind kind(void) const noexcept;
};

}  // namespace mx::ir
