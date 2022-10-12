// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

#include "Entities/Stmt.h"

namespace mx {

class Decl;
class ReferenceIterator;
class ReferenceIteratorImpl;
class ReferenceRange;

class Reference {
 private:
  friend class Fragment;
  friend class ReferenceIterator;
  friend class ReferenceIteratorImpl;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0u};

  Reference(void) = default;

 public:

  Stmt statement(void) && noexcept;
  Stmt statement(void) const & noexcept;
  operator Stmt(void) && noexcept;
  operator Stmt(void) const & noexcept;
};

class ReferenceIterator {
 private:
  friend class ReferenceRange;

  std::shared_ptr<ReferenceIteratorImpl> impl;
  Reference user;
  unsigned fragment_offset{0u};

  void Advance(void);

  inline /* implicit */ ReferenceIterator(
      std::shared_ptr<ReferenceIteratorImpl> impl_)
      : impl(std::move(impl_)) {
    Advance();
  }

 public:
  using Self = ReferenceIterator;

  ReferenceIterator(void) = default;
  ~ReferenceIterator(void);

  bool operator==(const Self &) = delete;
  bool operator!=(const Self &) = delete;

  inline bool operator!=(IteratorEnd) const {
    return !!impl;
  }

  inline bool operator==(IteratorEnd) const {
    return !impl;
  }

  inline operator bool(void) const {
    return !!impl;
  }

 // Return the current token pointed to by the iterator.
 inline Reference operator*(void) && noexcept {
   return std::move(user);
 }

  // Return the current token pointed to by the iterator.
  inline const Reference &operator*(void) const & noexcept {
    return user;
  }

  inline const Reference *operator->(void) const & noexcept {
    return &user;
  }

  // Pre-increment.
  inline Self &operator++(void) & noexcept{
    Advance();
    return *this;
  }
};

class ReferenceRange {
 private:
  friend class Decl;

  std::shared_ptr<ReferenceIteratorImpl> impl;

  inline /* implicit */ ReferenceRange(
      std::shared_ptr<ReferenceIteratorImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  ReferenceRange(void) = default;
  ReferenceRange(const ReferenceRange &) = default;
  ReferenceRange(ReferenceRange &&) noexcept = default;
  ReferenceRange &operator=(const ReferenceRange &) = default;
  ReferenceRange &operator=(ReferenceRange &&) noexcept = default;

  inline ReferenceIterator begin(void) && noexcept {
    return ReferenceIterator(std::move(impl));
  }

  inline ReferenceIterator begin(void) const & noexcept {
    return ReferenceIterator(impl);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

}  // namespace mx
