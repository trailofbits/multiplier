// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

namespace mx {

class Decl;
class FragmentImpl;
class Stmt;

class IteratorEnd {};

template <typename Iter, typename Derived>
class DerivedEntityIterator {
 private:
  Iter iter;
  std::optional<Derived> item;

 public:
  using Self = DerivedEntityIterator<Iter, Derived>;
  using EndIteratorType = typename Iter::EndIteratorType;

  bool operator==(const Self &) = delete;
  bool operator!=(const Self &) = delete;

  inline DerivedEntityIterator(Iter iter_)
      : iter(std::move(iter_)) {
    Advance();
  }

  inline bool operator!=(EndIteratorType that) const {
    return iter != that;
  }

  template <typename T>
  inline bool operator==(EndIteratorType that) const {
    return iter == that;
  }

  // Return the current token pointed to by the iterator.
  inline const Derived &operator*(void) const noexcept {
    return item.value();
  }

  inline const Derived *operator->(void) const noexcept {
    return std::addressof(item.value());
  }

  // Pre-increment.
  inline Self &operator++(void) noexcept {
    ++iter;
    Advance();
    return *this;
  }

 private:
  void Advance(void) {
    for (; iter != EndIteratorType(); ++iter) {
      item = Derived::from(*iter);
      if (item) {
        break;
      }
    }
  }
};

template <typename Iter, typename Derived>
class DerivedEntityRange {
 private:
  Iter iter;

 public:
  using DerivedEntityIter = DerivedEntityIterator<Iter, Derived>;
  using EndIteratorType = typename Iter::EndIteratorType;

  inline DerivedEntityRange(Iter iter_)
      : iter(std::move(iter_)) {}

  inline DerivedEntityIter begin(void) const {
    return DerivedEntityIter(iter);
  }

  inline EndIteratorType end(void) const noexcept {
    return {};
  }
};


class DeclIterator {
 private:
  friend class Decl;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index;
  unsigned num_decls;

  bool operator==(const DeclIterator &) = delete;
  bool operator!=(const DeclIterator &) = delete;

  inline DeclIterator(std::shared_ptr<const FragmentImpl> impl_,
                      unsigned index_, unsigned num_decls_)
      : impl(std::move(impl_)),
        index(index_),
        num_decls(num_decls_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_decls;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_decls;
  }

  // Return the current declaration pointed to by the iterator.
  Decl operator*(void) const noexcept;

  // Pre-increment.
  inline DeclIterator &operator++(void) noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline DeclIterator operator++(int) noexcept {
    return DeclIterator(impl, index++, num_decls);
  }
};

class StmtIterator {
 private:
  friend class Stmt;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index;
  unsigned num_stmts;

  bool operator==(const StmtIterator &) = delete;
  bool operator!=(const StmtIterator &) = delete;

  inline StmtIterator(std::shared_ptr<const FragmentImpl> impl_,
                      unsigned index_, unsigned num_stmts_)
      : impl(std::move(impl_)),
        index(index_),
        num_stmts(num_stmts_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_stmts;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_stmts;
  }

  // Return the current statement pointed to by the iterator.
  Stmt operator*(void) const noexcept;

  // Pre-increment.
  inline StmtIterator &operator++(void) noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline StmtIterator operator++(int) noexcept {
    return StmtIterator(impl, index++, num_stmts);
  }
};

}  // namespace mx
