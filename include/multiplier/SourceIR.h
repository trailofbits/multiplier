// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <unordered_set>

#include "Index.h"
#include "Fragment.h"

namespace mlir {
class Operation;
} // namespace mlir

namespace mx {

class SourceIRImpl;

class OperationRangeIterator {
 public:
  using Set = std::unordered_set<const mlir::Operation*>;
  using Ptr = std::shared_ptr<const Set>;

 private:
  std::shared_ptr<const Set> ops;
  Set::const_iterator iter;

  bool operator==(const OperationRangeIterator &) = delete;
  bool operator!=(const OperationRangeIterator &) = delete;

  inline OperationRangeIterator(std::shared_ptr<const Set> ops_,
                                const Set::const_iterator iter_)
      : ops(ops_), iter(iter_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline OperationRangeIterator(std::shared_ptr<const Set> ops_)
      : ops(ops_) {
    if (ops) {
      iter = ops->begin();
    }
  }

  inline bool operator==(EndIteratorType) const noexcept {
    return ops.get() && iter == ops->end();
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return ops.get() && iter != ops->end();
  }

  inline operator bool(void) const {
    return ops.get() && iter != ops->end();
  }

  inline const mlir::Operation* operator*(void) && noexcept {
    return std::move(*iter);
  }

  inline const mlir::Operation* const &operator*(void) const & noexcept {
    return *iter;
  }

  inline OperationRangeIterator &operator++(void) & noexcept {
    ++iter;
    return *this;
  }

  inline OperationRangeIterator operator++(int) noexcept {
    return OperationRangeIterator(ops, iter++);
  }
};

class OperationRange {
 public:
  using Iter = OperationRangeIterator;
  using EndIteratorType = typename Iter::EndIteratorType;
  using Set = typename Iter::Set;

 private:
  OperationRangeIterator iter;

 public:
  inline OperationRange(Iter iter_)
      : iter(std::move(iter_)) {}

  inline OperationRange(void)
      : iter(OperationRangeIterator({})) {}

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

  inline const mlir::Operation* value(void) && noexcept {
    return std::move(*iter);
  }


  inline const mlir::Operation* const &value(void) const & noexcept {
    return *iter;
  }

  inline const mlir::Operation* operator*(void) && noexcept {
    return std::move(*iter);
  }

  inline const mlir::Operation* const &operator*(void) const & noexcept {
    return *iter;
  }

  inline const mlir::Operation* const *operator->(void) const & noexcept {
    return std::addressof(*iter);
  }

  inline EndIteratorType end(void) const noexcept {
    return {};
  }
};

class SourceIR {
 private:
  friend class Fragment;

  using SourceIRImplPtr = std::shared_ptr<const SourceIRImpl>;

  SourceIRImplPtr impl;

  inline SourceIR(SourceIRImplPtr impl_)
      : impl(std::move(impl_)) {}

 public:
  VariantEntity entity_for(const mlir::Operation *op) const;

  VariantEntity entity_for(const std::shared_ptr<const mlir::Operation> &op) const;

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
