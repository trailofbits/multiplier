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
class Type;

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

class DeclIterator {
 private:
  friend class Decl;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index{0};
  unsigned num_decls{0};

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

  inline operator bool(void) const noexcept {
    return index < num_decls;
  }

  // Return the current declaration pointed to by the iterator.
  Decl operator*(void) && noexcept;
  Decl operator*(void) const & noexcept;

  // Pre-increment.
  inline DeclIterator &operator++(void) & noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline DeclIterator operator++(int) && noexcept {
    return DeclIterator(std::move(impl), index + 1u, num_decls);
  }

  // Post-increment.
  inline DeclIterator operator++(int) & noexcept {
    return DeclIterator(impl, index++, num_decls);
  }
};

class StmtIterator {
 private:
  friend class Stmt;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index{0};
  unsigned num_stmts{0};

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

  inline operator bool(void) const noexcept {
    return index < num_stmts;
  }

  // Return the current statement pointed to by the iterator.
  Stmt operator*(void) && noexcept;
  Stmt operator*(void) const & noexcept;

  // Pre-increment.
  inline StmtIterator &operator++(void) & noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline StmtIterator operator++(int) && noexcept {
    return StmtIterator(std::move(impl), index + 1u, num_stmts);
  }

  // Post-increment.
  inline StmtIterator operator++(int) & noexcept {
    return StmtIterator(impl, index++, num_stmts);
  }
};

class TypeIterator {
 private:
  friend class Type;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index{0};
  unsigned num_types{0};

  bool operator==(const TypeIterator &) = delete;
  bool operator!=(const TypeIterator &) = delete;

  inline TypeIterator(std::shared_ptr<const FragmentImpl> impl_,
                      unsigned index_, unsigned num_types_)
      : impl(std::move(impl_)),
        index(index_),
        num_types(num_types_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_types;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_types;
  }

  inline operator bool(void) const noexcept {
    return index < num_types;
  }

  // Return the current type pointed to by the iterator.
  Type operator*(void) && noexcept;
  Type operator*(void) const & noexcept;

  // Pre-increment.
  inline TypeIterator &operator++(void) & noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline TypeIterator operator++(int) && noexcept {
    return TypeIterator(std::move(impl), index + 1u, num_types);
  }

  // Post-increment.
  inline TypeIterator operator++(int) & noexcept {
    return TypeIterator(impl, index++, num_types);
  }
};

class AttrIterator {
 private:
  friend class Attr;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index{0};
  unsigned num_attrs{0};

  bool operator==(const AttrIterator &) = delete;
  bool operator!=(const AttrIterator &) = delete;

  inline AttrIterator(std::shared_ptr<const FragmentImpl> impl_,
                      unsigned index_, unsigned num_attrs_)
      : impl(std::move(impl_)),
        index(index_),
        num_attrs(num_attrs_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_attrs;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_attrs;
  }

  inline operator bool(void) const noexcept {
    return index < num_attrs;
  }

  // Return the current type pointed to by the iterator.
  Attr operator*(void) && noexcept;
  Attr operator*(void) const & noexcept;

  // Pre-increment.
  inline AttrIterator &operator++(void) & noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline AttrIterator operator++(int) && noexcept {
    return AttrIterator(std::move(impl), index + 1u, num_attrs);
  }

  // Post-increment.
  inline AttrIterator operator++(int) & noexcept {
    return AttrIterator(impl, index++, num_attrs);
  }
};

class MacroIterator {
 private:
  friend class Macro;

  std::shared_ptr<const FragmentImpl> impl;
  unsigned index{0};
  unsigned num_macros{0};

  bool operator==(const MacroIterator &) = delete;
  bool operator!=(const MacroIterator &) = delete;

  inline MacroIterator(std::shared_ptr<const FragmentImpl> impl_,
                       unsigned index_, unsigned num_macros_)
      : impl(std::move(impl_)),
        index(index_),
        num_macros(num_macros_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_macros;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_macros;
  }

  inline operator bool(void) const noexcept {
    return index < num_macros;
  }

  // Return the current type pointed to by the iterator.
  Macro operator*(void) && noexcept;
  Macro operator*(void) const & noexcept;

  // Pre-increment.
  inline MacroIterator &operator++(void) & noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline MacroIterator operator++(int) && noexcept {
    return MacroIterator(std::move(impl), index + 1u, num_macros);
  }

  // Post-increment.
  inline MacroIterator operator++(int) & noexcept {
    return MacroIterator(impl, index++, num_macros);
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

  std::shared_ptr<const FragmentImpl> impl;

  // Offset of this token context inside of the fragment.
  unsigned offset{0};

  // Offset of this token context's parent within the fragment.
  std::optional<unsigned> parent_offset;

  // Offset of this context's alias within the fragment.
  std::optional<unsigned> alias_offset;

  // Entity to which this token context refers. In general, this belongs to
  // the current fragment, but in rare instances it may not.
  RawEntityId entity_id{kInvalidEntityId};

  inline TokenContext(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

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

  // Return the declaration associated with this context, if any.
  std::optional<Decl> as_declaration(void) const;

  // Return the statement associated with this context, if any.
  std::optional<Stmt> as_statement(void) const;

  // Return the type associated with this context, if any.
  std::optional<Type> as_type(void) const;

  // Return the attribute associated with this context, if any.
  std::optional<Attr> as_attribute(void) const;

  // Return the designator associated with the designated initializer, if any.
  std::optional<Designator> as_designator(void) const;

  // Return the aliased context, if any.
  std::optional<TokenContext> aliasee(void) const;

  // Return the parent context, if any.
  std::optional<TokenContext> parent(void) const;
};

class TokenContextIterator {
 private:
  std::optional<TokenContext> impl;

  bool operator==(const TokenContextIterator &) = delete;
  bool operator!=(const TokenContextIterator &) = delete;

 public:
  using EndIteratorType = IteratorEnd;

  inline TokenContextIterator(std::optional<TokenContext> impl_)
      : impl(std::move(impl_)) {}

  inline bool operator==(EndIteratorType) const noexcept {
    return !impl.has_value();
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.has_value();
  }

  inline operator bool(void) const noexcept {
    return impl.has_value();
  }

  // Return the current token context pointed to by the iterator.
  TokenContext operator*(void) && noexcept {
    return std::move(impl.value());
  }

  // Return the current token context pointed to by the iterator.
  const TokenContext &operator*(void) const & noexcept {
    return impl.value();
  }

  // Return the current token context pointed to by the iterator.
  const TokenContext *operator->(void) const & noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline TokenContextIterator &operator++(void) & noexcept {
    impl = impl->parent();
    return *this;
  }
};

template <typename T>
class ParentDeclIteratorImpl {
 private:
  std::optional<T> impl;

  bool operator==(const ParentDeclIteratorImpl<T> &) = delete;
  bool operator!=(const ParentDeclIteratorImpl<T> &) = delete;

 public:
  using EndIteratorType = IteratorEnd;

  inline ParentDeclIteratorImpl(std::optional<T> impl_)
      : impl(std::move(impl_)) {}

  inline bool operator==(EndIteratorType) const noexcept {
    return !impl.has_value();
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.has_value();
  }

  inline operator bool(void) const noexcept {
    return impl.has_value();
  }

  inline bool has_value(void) const noexcept {
    return impl.has_value();
  }

  // Return the current declaration pointed to by the iterator.
  inline T value(void) && noexcept {
    return std::move(impl.value());
  }

  // Return the current declaration pointed to by the iterator.
  inline const T &value(void) const & noexcept {
    return impl.value();
  }

  // Return the current declaration pointed to by the iterator.
  inline T operator*(void) && noexcept {
    return std::move(impl.value());
  }

  // Return the current declaration pointed to by the iterator.
  inline const T &operator*(void) const & noexcept {
    return impl.value();
  }

  // Return the current declaration pointed to by the iterator.
  inline const T *operator->(void) const & noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline ParentDeclIteratorImpl<T> &operator++(void) &;
};

template <typename T>
class ParentStmtIteratorImpl {
 private:
  std::optional<T> impl;

  bool operator==(const TokenContextIterator &) = delete;
  bool operator!=(const TokenContextIterator &) = delete;

 public:
  using EndIteratorType = IteratorEnd;

  inline ParentStmtIteratorImpl(std::optional<T> impl_)
      : impl(std::move(impl_)) {}

  inline bool operator==(EndIteratorType) const noexcept {
    return !impl.has_value();
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.has_value();
  }

  inline operator bool(void) const noexcept {
    return impl.has_value();
  }

  // Return the current statement pointed to by the iterator.
  T operator*(void) && noexcept {
    return std::move(impl.value());
  }

  // Return the current statement pointed to by the iterator.
  const T &operator*(void) const & noexcept {
    return impl.value();
  }

  // Return the current statement pointed to by the iterator.
  const T *operator->(void) const & noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline ParentStmtIteratorImpl<T> &operator++(void) &;
};

template <typename T>
class ParentMacroIteratorImpl {
 private:
  std::optional<T> impl;

 public:
  using EndIteratorType = IteratorEnd;

  inline ParentMacroIteratorImpl(std::optional<T> impl_)
      : impl(std::move(impl_)) {}

  inline bool operator==(EndIteratorType) const noexcept {
    return !impl.has_value();
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.has_value();
  }

  inline operator bool(void) const noexcept {
    return impl.has_value();
  }

  // Return the current statement pointed to by the iterator.
  T operator*(void) && noexcept {
    return std::move(impl.value());
  }

  // Return the current statement pointed to by the iterator.
  const T &operator*(void) const & noexcept {
    return impl.value();
  }

  // Return the current statement pointed to by the iterator.
  const T *operator->(void) const & noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline ParentMacroIteratorImpl<T> &operator++(void) &;
};

}  // namespace mx
