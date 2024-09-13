// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <memory>

#include "Types.h"

namespace mx {
namespace ir {
class Operation;
}  // namespace ir

class FragmentImpl;
class TokenContextReader;

#define MX_FORWARD_DECLARE_ENTITY(ns_path, type_name, ...) \
    class type_name; \
    class type_name ## Impl;

MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE_ENTITY

class IteratorEnd {};

template <typename Enum>
class MX_EXPORT EnumeratorIterator {
 private:
  using IType = std::underlying_type_t<Enum>;
  unsigned val{0};
  static constexpr auto kMaxValue = NumEnumerators(Enum{});

  inline EnumeratorIterator(unsigned val_)
      : val(val_) {}

 public:

  EnumeratorIterator(void) = default;

  using Self = EnumeratorIterator<Enum>;

  inline bool operator!=(IteratorEnd) const {
    return val < kMaxValue;
  }

  inline bool operator==(IteratorEnd) const {
    return val >= kMaxValue;
  }

  inline bool operator!=(Self that) const {
    return val != that.val;
  }

  inline bool operator==(Self that) const {
    return val == that.val;
  }

  // Return the current token pointed to by the iterator.
  inline Enum operator*(void) const noexcept {
    return static_cast<Enum>(val);
  }

  // Pre-increment.
  inline Self &operator++(void) & noexcept{
    ++val;
    return *this;
  }

  // Post-increment.
  inline Self operator++(int) & noexcept{
    return Self(val++);
  }
};

template <typename Enum>
class MX_EXPORT EnumerationRange {
 public:
  inline EnumeratorIterator<Enum> begin(void) const noexcept {
    return EnumeratorIterator<Enum>();
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

template <typename Iter, typename Derived>
class MX_EXPORT DerivedEntityIterator {
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

  inline bool operator!=(EndIteratorType) const {
    return item.has_value();
  }

  inline bool operator==(EndIteratorType) const {
    return !item.has_value();
  }

  inline operator bool(void) const {
    return item.has_value();
  }

  // Return the current token pointed to by the iterator.
  inline Derived operator*(void) && noexcept {
    return std::move(item.value());
  }

  // Return the current token pointed to by the iterator.
  inline const Derived &operator*(void) const & noexcept {
    return item.value();
  }

  inline const Derived *operator->(void) const & noexcept {
    return std::addressof(item.value());
  }

  // Pre-increment.
  inline Self &operator++(void) & noexcept{
    ++iter;
    Advance();
    return *this;
  }

 private:
  void Advance(void) {
    for (item.reset(); iter != EndIteratorType(); ++iter) {
      item = Derived::from(*iter);
      if (item) {
        break;
      }
    }
  }
};

template <typename Iter, typename Derived>
class MX_EXPORT DerivedEntityRange {
 public:
  using DerivedEntityIter = DerivedEntityIterator<Iter, Derived>;
  using EndIteratorType = typename Iter::EndIteratorType;

 private:
  DerivedEntityIter iter;

 public:
  inline DerivedEntityRange(Iter iter_)
      : iter(std::move(iter_)) {}

  inline DerivedEntityIter begin(void) && {
    return std::move(iter);
  }

  inline DerivedEntityIter begin(void) const & {
    return iter;
  }

  inline operator bool(void) const {
    return !!iter;
  }

  inline bool has_value(void) const {
    return !!iter;
  }

  // Return the current token pointed to by the iterator.
  inline Derived value(void) && noexcept {
    return std::move(*iter);
  }

  // Return the current token pointed to by the iterator.
  inline const Derived &value(void) const & noexcept {
    return *iter;
  }

  // Return the current token pointed to by the iterator.
  inline Derived operator*(void) && noexcept {
    return std::move(*iter);
  }

  // Return the current token pointed to by the iterator.
  inline const Derived &operator*(void) const & noexcept {
    return *iter;
  }

  inline const Derived *operator->(void) const & noexcept {
    return std::addressof(*iter);
  }

  inline EndIteratorType end(void) const noexcept {
    return {};
  }
};

}  // namespace mx
