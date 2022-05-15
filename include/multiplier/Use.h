// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <bitset>

#include "Iterator.h"

namespace mx {

class CXXBaseSpecifier;
class Decl;
class EntityProvider;
class FragmentImpl;
class Stmt;
class TemplateArgument;
class TemplateParameterList;
class Token;
class Type;

using UseSelectorSet = std::bitset<256>;

enum class UseKind : unsigned char {
  DECLARATION,
  STATEMENT,
  TYPE,
  CXX_BASE_SPECIFIER,
  TEMPLATE_ARGUMENT,
  TEMPLATE_PARAMETER_LIST
};

inline static const char *EnumerationName(UseKind) {
  return "UseKind";
}

inline static constexpr unsigned NumEnumerators(UseKind) {
  return 6u;
}

// Base for uses. Uses represent AST methods that return a specific entity
// ID.
class UseBase {
 private:
  friend class Decl;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Stmt;

 protected:
  UseSelectorSet selectors;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset;
  UseKind kind;

 public:
  UseBase(Decl decl, UseSelectorSet selectors_);
  UseBase(Stmt decl, UseSelectorSet selectors_);
  UseBase(Type decl, UseSelectorSet selectors_);
  UseBase(CXXBaseSpecifier decl, UseSelectorSet selectors_);
  UseBase(TemplateArgument decl, UseSelectorSet selectors_);
  UseBase(TemplateParameterList decl, UseSelectorSet selectors_);

  ~UseBase(void);

  std::optional<Decl> as_declaration(void) const;
  std::optional<Stmt> as_statement(void) const;
  std::optional<Type> as_type(void) const;
  std::optional<CXXBaseSpecifier> as_cxx_base_specifier(void) const;
  std::optional<TemplateArgument> as_template_argument(void) const;
  std::optional<TemplateParameterList> as_template_parameter_list(void) const;
};

enum class DeclUseSelector : unsigned short;
enum class StmtUseSelector : unsigned short;
enum class TypeUseSelector : unsigned short;
enum class TokenUseSelector : unsigned short;

// A declaration or statement use, along with the usage selector.
template <typename Selector>
class Use : public UseBase {
 private:
  friend class Decl;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Stmt;

 protected:
  using UseBase::UseBase;

 public:
  inline bool has_selector(Selector sel0) const noexcept {
    return selectors.test(static_cast<unsigned>(sel0));
  }

  template <typename... S>
  inline bool has_any_selector(Selector sel0, S... selN) const noexcept {
    return has_selector(sel0) || (has_selector(selN) || ...);
  }
};

class UseIteratorImpl;

class UseIteratorBase {
 protected:
  std::shared_ptr<UseIteratorImpl> impl;
  std::optional<UseBase> use;

  inline UseIteratorBase(std::shared_ptr<UseIteratorImpl> impl_)
      : impl(std::move(impl_)) {
    Advance();
  }

  void Advance(void);
};

template <typename Selector>
class UseIterator : public UseIteratorBase {
 private:
  using UseIteratorBase::UseIteratorBase;

 public:
  using UseT = Use<Selector>;
  using Self = UseIterator<Selector>;

  static_assert(sizeof(UseT) == sizeof(UseBase));

  bool operator==(const Self &) = delete;
  bool operator!=(const Self &) = delete;

  UseIterator(void) = default;

  inline bool operator!=(IteratorEnd) const {
    return impl;
  }

  inline bool operator==(IteratorEnd) const {
    return !impl;
  }

  inline operator bool(void) const {
    return impl;
  }

  // Return the current token pointed to by the iterator.
  inline UseT operator*(void) && noexcept {
    return std::move(reinterpret_cast<const UseT &>(use.value()));
  }

  // Return the current token pointed to by the iterator.
  inline const UseT &operator*(void) const & noexcept {
    return reinterpret_cast<const UseT &>(use.value());
  }

  inline const UseT *operator->(void) const & noexcept {
    return std::addressof(use.value());
  }

  // Pre-increment.
  inline Self &operator++(void) & noexcept{
    Advance();
    return *this;
  }
};

}  // namespace mx
