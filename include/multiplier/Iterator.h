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
class Token;

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

  inline DerivedEntityIter begin(void) const {
    return iter;
  }

  inline operator bool(void) const {
    return !!iter;
  }

  // Return the current token pointed to by the iterator.
  inline const Derived &operator*(void) const noexcept {
    return *iter;
  }

  inline const Derived *operator->(void) const noexcept {
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

class TokenContext {
 private:
  std::shared_ptr<const FragmentImpl> impl;

  enum Kind {
    kInvalid,
    kDecl,
    kDeclAlias,
    kStmt,
    kStmtAlias
  } kind{kInvalid};

  // These represent the index and offset of the storage of this token context.
  unsigned index{0};
  unsigned offset{0};

  inline TokenContext(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  inline bool is_alias(void) const {
    return kind == kDeclAlias || kind == kStmtAlias;
  }

  inline unsigned id(void) const noexcept {
    return offset;
  }

  // Return the token context associated with a token.
  //
  // NOTE(pag): This only works with parsed tokens, and not all parsed tokens
  //            are guaranteed to have a context.
  static std::optional<TokenContext> of(const Token &tok);

  // Return the declaration associated with this context, if any.
  std::optional<Decl> as_decl(void) const;

  // Return the statement associated with this context, if any.
  std::optional<Stmt> as_stmt(void) const;

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
  const TokenContext &operator*(void) const noexcept {
    return impl.value();
  }

  // Return the current token context pointed to by the iterator.
  const TokenContext *operator->(void) const noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline TokenContextIterator &operator++(void) noexcept {
    impl = impl->parent();
    return *this;
  }
};

template <typename T>
class ParentDeclIteratorImpl {
 private:
  std::optional<T> impl;

  bool operator==(const TokenContextIterator &) = delete;
  bool operator!=(const TokenContextIterator &) = delete;

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

  // Return the current declaration pointed to by the iterator.
  const T &operator*(void) const noexcept {
    return impl.value();
  }

  // Return the current declaration pointed to by the iterator.
  const T *operator->(void) const noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline ParentDeclIteratorImpl<T> &operator++(void);
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
  const T &operator*(void) const noexcept {
    return impl.value();
  }

  // Return the current statement pointed to by the iterator.
  const T *operator->(void) const noexcept {
    return std::addressof(impl.value());
  }

  // Pre-increment.
  inline ParentStmtIteratorImpl<T> &operator++(void);
};

}  // namespace mx
