// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

#include "Entities/Macro.h"
#include "Entities/Stmt.h"

namespace mx {

class Decl;
class File;
class MacroReferenceIterator;
class MacroReferenceRange;
class ReferenceIteratorImpl;
class StmtReferenceIterator;
class StmtReferenceRange;

// A reference from a statement to a declaration.
class StmtReference {
 private:
  friend class Fragment;
  friend class StmtReferenceIterator;
  friend class ReferenceIteratorImpl;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0u};

  StmtReference(void) = default;

 public:

  Stmt statement(void) && noexcept;
  Stmt statement(void) const & noexcept;
  operator Stmt(void) && noexcept;
  operator Stmt(void) const & noexcept;
};

class StmtReferenceIterator {
 private:
  friend class StmtReferenceRange;

  std::shared_ptr<ReferenceIteratorImpl> impl;
  StmtReference user;
  unsigned fragment_offset{0u};

  void Advance(void);

  inline /* implicit */ StmtReferenceIterator(
      std::shared_ptr<ReferenceIteratorImpl> impl_)
      : impl(std::move(impl_)) {
    Advance();
  }

 public:
  using Self = StmtReferenceIterator;

  StmtReferenceIterator(void) = default;
  ~StmtReferenceIterator(void);

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

  // Return the reference pointed to by the iterator.
  inline StmtReference operator*(void) && noexcept {
    return std::move(user);
  }

  // Return the reference pointed to by the iterator.
  inline const StmtReference &operator*(void) const & noexcept {
    return user;
  }

  inline const StmtReference *operator->(void) const & noexcept {
    return &user;
  }

  // Pre-increment.
  inline Self &operator++(void) & noexcept{
    Advance();
    return *this;
  }
};

class StmtReferenceRange {
 private:
  friend class Decl;

  std::shared_ptr<ReferenceIteratorImpl> impl;

  inline /* implicit */ StmtReferenceRange(
      std::shared_ptr<ReferenceIteratorImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  StmtReferenceRange(void) = default;
  StmtReferenceRange(const StmtReferenceRange &) = default;
  StmtReferenceRange(StmtReferenceRange &&) noexcept = default;
  StmtReferenceRange &operator=(const StmtReferenceRange &) = default;
  StmtReferenceRange &operator=(StmtReferenceRange &&) noexcept = default;

  inline StmtReferenceIterator begin(void) && noexcept {
    return StmtReferenceIterator(std::move(impl));
  }

  inline StmtReferenceIterator begin(void) const & noexcept {
    return StmtReferenceIterator(impl);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

// A reference
class MacroReference {
 private:
  friend class Fragment;
  friend class MacroReferenceIterator;
  friend class ReferenceIteratorImpl;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0u};

  MacroReference(void) = default;

 public:
  Macro macro(void) && noexcept;
  Macro macro(void) const & noexcept;
  operator Macro(void) && noexcept;
  operator Macro(void) const & noexcept;
};

class MacroReferenceIterator {
 private:
  friend class MacroReferenceRange;

  std::shared_ptr<ReferenceIteratorImpl> impl;
  MacroReference user;
  unsigned fragment_offset{0u};

  void Advance(void);

  inline /* implicit */ MacroReferenceIterator(
      std::shared_ptr<ReferenceIteratorImpl> impl_)
      : impl(std::move(impl_)) {
    Advance();
  }

 public:
  using Self = MacroReferenceIterator;

  MacroReferenceIterator(void) = default;
  ~MacroReferenceIterator(void);

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

  // Return the reference pointed to by the iterator.
  inline MacroReference operator*(void) && noexcept {
    return std::move(user);
  }

  // Return the reference pointed to by the iterator.
  inline const MacroReference &operator*(void) const & noexcept {
    return user;
  }

  inline const MacroReference *operator->(void) const & noexcept {
    return &user;
  }

  // Pre-increment.
  inline Self &operator++(void) & noexcept{
    Advance();
    return *this;
  }
};

class MacroReferenceRange {
 private:
  friend class DefineMacroDirective;
  friend class File;

  std::shared_ptr<ReferenceIteratorImpl> impl;

  inline /* implicit */ MacroReferenceRange(
      std::shared_ptr<ReferenceIteratorImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  MacroReferenceRange(void) = default;
  MacroReferenceRange(const MacroReferenceRange &) = default;
  MacroReferenceRange(MacroReferenceRange &&) noexcept = default;
  MacroReferenceRange &operator=(const MacroReferenceRange &) = default;
  MacroReferenceRange &operator=(MacroReferenceRange &&) noexcept = default;

  inline MacroReferenceIterator begin(void) && noexcept {
    return MacroReferenceIterator(std::move(impl));
  }

  inline MacroReferenceIterator begin(void) const & noexcept {
    return MacroReferenceIterator(impl);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

}  // namespace mx
