// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <optional>
#include <string_view>

#include "TypeKind.h"

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

// The type of some operation / value.
class Type {
 private:
  friend class Operation;
  friend class Block;
  friend class Argument;
  friend class Value;
 
 protected:
  mlir::MLIRContext *context_;
  mlir::TypeStorage *type_;
  TypeKind kind_;

 public:
  inline Type(mlir::MLIRContext *context, const mlir::TypeStorage *type)
      : context_(std::move(context)),
        type_(const_cast<mlir::TypeStorage *>(type)),
        kind_(classify(type_)) {}

  static TypeKind classify(mlir::TypeStorage *type);

  inline TypeKind kind(void) const noexcept {
    return kind_;
  }
};

}  // namespace mx::ir
