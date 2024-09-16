// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/coro/generator.hpp>
#include <memory>
#include <optional>
#include <string_view>

#include "TypeKind.h"
#include "../Compiler.h"

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
class MX_EXPORT Type {
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
  Type(mlir::MLIRContext *context, const mlir::TypeStorage *type)
      : context_(std::move(context)),
        type_(const_cast<mlir::TypeStorage *>(type)),
        kind_(classify(type_)) {}

  static TypeKind classify(mlir::TypeStorage *type);

  inline TypeKind kind(void) const noexcept {
    return kind_;
  }

  inline mlir::TypeStorage *underlying_type(void) const noexcept {
    return type_;
  }

  inline bool operator==(const Type &that) const noexcept {
    return type_ == that.type_;
  }

  inline bool operator!=(const Type &that) const noexcept {
    return type_ != that.type_;
  }
};

}  // namespace mx::ir
