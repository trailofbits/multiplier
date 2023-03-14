// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Index.h"

namespace mlir {
class ModuleOp;
class Operation;
class Value;
} // namespace mlir

namespace mx {

class SourceIRImpl;

// Forward-only iterator that traverses through the vector of operations
class OperationRangeIterator {
 public:
  using OpVec     = std::vector<const mlir::Operation *>;
  using OpVecPtr  = std::shared_ptr<const OpVec>;
  using OpPtr     = std::shared_ptr<const mlir::Operation>;

  using EndIteratorType = IteratorEnd;

 private:
  OpVecPtr ops;
  unsigned offset;
  unsigned num_elements;

  bool operator==(const OperationRangeIterator &) = delete;
  bool operator!=(const OperationRangeIterator &) = delete;

  inline OperationRangeIterator(OpVecPtr ops_, unsigned offset_, unsigned num_elem)
      : ops(ops_), offset(offset_), num_elements(num_elem) {}

 public:
  inline OperationRangeIterator(OpVecPtr ops_)
      : ops(ops_), offset(0),
        num_elements(ops_ ? static_cast<unsigned>(ops_->size()) : 0){}

  inline OperationRangeIterator(void)
      : ops(nullptr), offset(0), num_elements(0) {}

  inline bool operator==(EndIteratorType) const noexcept {
    return offset >= num_elements;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return offset < num_elements;
  }

  inline operator bool(void) const {
    return offset < num_elements;
  }

  inline OpPtr operator*(void) && noexcept {
    const mlir::Operation *op = (*ops)[offset];
    return OpPtr(std::move(ops), op);
  }

  inline OpPtr operator*(void) const & noexcept {
    return OpPtr(ops, (*ops)[offset]);
  }

  // Pre-increment
  inline OperationRangeIterator &operator++(void) & noexcept {
    ++offset;
    return *this;
  }

  // Post increment
  inline OperationRangeIterator operator++(int) noexcept {
    return OperationRangeIterator(ops, offset++, num_elements);
  }
};

class OperationRange {
 public:
  using Iter            = OperationRangeIterator;
  using EndIteratorType = Iter::EndIteratorType;

  using OpVec           = Iter::OpVec;
  using OpVecPtr        = Iter::OpVecPtr;
  using OpPtr           = Iter::OpPtr;

 private:
  OperationRangeIterator iter;

 public:
  inline OperationRange(Iter iter_)
      : iter(std::move(iter_)) {}

  inline OperationRange(void)
      : iter(OperationRangeIterator()) {}

  inline Iter begin(void) && {
    return std::move(iter);
  }

  inline Iter begin(void) const & {
    return iter;
  }

  inline operator bool(void) const {
    return !!iter;
  }

  inline bool has_value(void) const {
    return !!iter;
  }

  inline OpPtr value(void) const & noexcept {
    return *iter;
  }

  inline OpPtr operator*(void) const & noexcept {
    return *iter;
  }

  inline EndIteratorType end(void) const noexcept {
    return {};
  }
};

using MLIRModulePtr = std::shared_ptr<const mlir::Operation>;
using MLIROperationPtr = std::shared_ptr<const mlir::Operation>;
using MLIRValuePtr = std::shared_ptr<const mlir::Value>;

class SourceIR {
 private:
  friend class Fragment;

  using SourceIRImplPtr = std::shared_ptr<const SourceIRImpl>;

  SourceIRImplPtr impl;

  inline SourceIR(SourceIRImplPtr impl_)
      : impl(std::move(impl_)) {}

 public:
  MLIRModulePtr module(void) const;

  VariantEntity entity_for(const mlir::Operation *op) const;

  VariantEntity entity_for(const MLIROperationPtr &op) const;

  OperationRange for_entity(const VariantEntity &entity) const;

#define MX_DECLARE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
  OperationRange for_##lower_name(const type_name &lower_name) const; \

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_FUNCTION,
                              MX_DECLARE_ENTITY_FUNCTION)
#undef MX_DECLARE_ENTITY_FUNCTION


#define MX_DECLARE_ENTITY_FUNCTION(type_name, lower_name, e, v) \
  std::optional<mx::type_name> lower_name ##_for \
    (const mlir::Operation *op) const; \
  std::optional<mx::type_name> lower_name ##_for \
    (const std::shared_ptr<const mlir::Operation> &op) const;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_FUNCTION,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_ENTITY_FUNCTION,
                              MX_DECLARE_ENTITY_FUNCTION,
                              MX_DECLARE_ENTITY_FUNCTION)
#undef MX_DECLARE_ENTITY_FUNCTION

  void print(std::ostream &os) const;
};

} // namespace mx
