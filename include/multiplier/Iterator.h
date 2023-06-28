// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <memory>

#include "Types.h"

namespace mx {

class Attr;
class CXXBaseSpecifier;
class Decl;
class Designator;
class FragmentImpl;
class Macro;
class Stmt;
class TemplateArgument;
class TemplateParameterList;
class Token;
class TokenContextReader;
class Type;

#define MX_FORWARD_DECLARE_ENTITY(type_name, lower_name, enum_name, category) \
    class type_name; \
    class type_name ## Impl;

MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY,
                            MX_FORWARD_DECLARE_ENTITY)
#undef MX_FORWARD_DECLARE_ENTITY

class IteratorEnd {};

template <typename Enum>
class EnumeratorIterator {
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
class EnumerationRange {
 public:
  inline EnumeratorIterator<Enum> begin(void) const noexcept {
    return EnumeratorIterator<Enum>();
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

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
class DerivedEntityRange {
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

// An edge from tokens to AST nodes containing those tokens. Only parsed tokens
// have token contexts. Multiple contexts may share the same parents. The token
// context tree is a sort of DAG, via mechanism called "aliases." This is to
// handle the challenges of C's bizarre declaration syntax. For example:
//
//   int foo(void (*func_ptr)(...));
//
// This declares `func_ptr` as a function pointer-typed parameter of `foo`. The
// token contexts for this would have `func_ptr` link to something like:
//
//   foo ----------------------------------------------------.
//   ...                                                     |
//   func_ptr -> ParmVarDecl -> FunctionType -> ParmVarDecl -+-> FunctionDecl
//                    |                              ^
//                    '----------- alias ------------'
class TokenContext {
 private:
  friend class Token;

  std::shared_ptr<const TokenContextReader> reader;

  // Offset of this token context inside of the fragment.
  unsigned offset{0};

  // Offset of this token context's parent within the fragment.
  std::optional<unsigned> parent_offset;

  // Offset of this context's alias within the fragment.
  std::optional<unsigned> alias_offset;

  // Entity to which this token context refers. In general, this belongs to
  // the current fragment, but in rare instances it may not.
  RawEntityId entity_id{kInvalidEntityId};

  inline TokenContext(std::shared_ptr<const TokenContextReader> reader_)
      : reader(std::move(reader_)) {}

 public:
  inline bool has_parent(void) const noexcept {
    return parent_offset.has_value();
  }

  inline bool is_alias(void) const noexcept {
    return alias_offset.has_value();
  }

  // NOTE(pag): This is sort of an internal API, though it makes it convenient
  //            to identify token contexts.
  inline unsigned index_in_fragment(void) const noexcept {
    return offset;
  }

  // Return the token context associated with a token.
  //
  // NOTE(pag): This only works with parsed tokens, and not all parsed tokens
  //            are guaranteed to have a context.
  __attribute__((deprecated("Use Token::context() instead.")))
  static std::optional<TokenContext> of(const Token &tok);

#define MX_FORWARD_DECLARE_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> as_ ## lower_name(void) const;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_FORWARD_DECLARE_GETTER)
#undef MX_FORWARD_DECLARE_GETTER

  // Return the aliased context, if any.
  std::optional<TokenContext> aliasee(void) const;

  // Return the parent context, if any.
  std::optional<TokenContext> parent(void) const;
};

}  // namespace mx
