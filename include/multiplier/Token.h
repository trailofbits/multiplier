// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <optional>
#include <string_view>
#include <utility>
#include <variant>

#include "Types.h"
#include "Use.h"

namespace mx {

class EntityProvider;
class File;
class Fragment;
class FragmentImpl;
class Index;
class TokenContext;
class TokenList;
class TokenListIterator;
class TokenRange;
class TokenReader;
class TokenSubstitutionList;
class TokenSubstitutionListImpl;
class TokenSubstitutionListIterator;

enum class TokenKind : unsigned short;
using TokenUse = Use<TokenUseSelector>;

// A single token, e.g. from a file or from a macro expansion.
class Token {
 private:
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class TokenContext;
  friend class TokenList;
  friend class TokenListIterator;
  friend class TokenRange;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const TokenReader> impl;
  unsigned index;

  inline Token(std::shared_ptr<const TokenReader> impl_, unsigned index_)
      : impl(std::move(impl_)),
        index(index_) {}

 public:
  Token(void);

  // Return `true` if this is a valid token.
  operator bool(void) const;

  // Return the list of parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  static TokenList in(const Fragment &);

  // Return the list of tokens in this file.
  static TokenList in(const File &);

  // Kind of this token.
  TokenKind kind(void) const;

  // Return the data of this token.
  std::string_view data(void) const;

  // Return the ID of this token.
  EntityId id(void) const;

  // Return the version of this token from a file, if any.
  std::optional<Token> file_token(void) const;

  // Return the set of all uses of this token within its fragment (if it's a
  // fragment token).
  UseRange<TokenUseSelector> uses(void) const;
};

// Forward-only iterator over a sequence of tokens.
class TokenListIterator {
 private:
  friend class TokenList;
  friend class TokenRange;

  Token impl;
  unsigned num_tokens;

  bool operator==(const TokenListIterator &) = delete;
  bool operator!=(const TokenListIterator &) = delete;

  inline TokenListIterator(std::shared_ptr<const class TokenReader> impl_,
                           unsigned index_, unsigned num_tokens_)
      : impl(std::move(impl_), index_),
        num_tokens(num_tokens_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return impl.index >= num_tokens;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.index < num_tokens;
  }

  // Return the current token pointed to by the iterator.
  inline const Token &operator*(void) const noexcept {
    return impl;
  }

  inline const Token *operator->(void) const noexcept {
    return &impl;
  }

  // Pre-increment.
  inline TokenListIterator &operator++(void) noexcept {
    ++impl.index;
    return *this;
  }

  // Post-increment.
  inline TokenListIterator operator++(int) noexcept {
    return TokenListIterator(impl.impl, impl.index++, num_tokens);
  }
};

// A range of tokens.
class TokenRange {
 protected:
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class RegexQueryResultIterator;
  friend class WeggliQueryResultIterator;
  friend class TokenList;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const TokenReader> impl;
  unsigned index;
  unsigned num_tokens;

  inline TokenRange(std::shared_ptr<const TokenReader> impl_,
                    unsigned index_, unsigned num_tokens_)
      : impl(std::move(impl_)),
        index(index_),
        num_tokens(num_tokens_) {}

 public:
  TokenRange(void);

  // Return the number of tokens in this token list.
  inline size_t size(void) const noexcept {
    return num_tokens - index;
  }

  // Return the token at index `index`.
  Token operator[](size_t index) const;

  // Return the underlying token data associated with the tokens covered by this
  // token range.
  std::string_view data(void) const;

  // Return an iterator pointing at the first token in this list.
  inline TokenListIterator begin(void) && noexcept {
    return TokenListIterator(std::move(impl), index, num_tokens);
  }

  // Return an iterator pointing at the first token in this list.
  inline TokenListIterator begin(void) const & noexcept {
    return TokenListIterator(impl, index, num_tokens);
  }

  inline TokenListIterator::EndIteratorType end(void) const noexcept {
    return {};
  }

  // Return a slice of this token range. If the indices given are invalid, then
  // an empty token range is returned. The indices cover the tokens in the
  // exclusive range `[start_index, end_index)`.
  TokenRange slice(size_t start_index, size_t end_index) const noexcept;
};

// List of tokens.
class TokenList : public TokenRange {
 private:
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Token;
  friend class TokenSubstitutionListIterator;

  inline TokenList(std::shared_ptr<const TokenReader> impl_,
                   unsigned num_tokens_)
      : TokenRange(std::move(impl_), 0, num_tokens_) {}

 public:
  TokenList(void) = default;

  // Return the token list containing a particular token.
  static TokenList containing(Token tok);

  // Return the token list containing a particular token range.
  static TokenList containing(const TokenRange &range);
};


// A token substitution gives access to the before and after tokens of a
// substitution. There can be one-or-more `before` tokens (e.g. function-like
// macro expansions, file inclusions) and zero-or-more `after` tokens.
class TokenSubstitution {
 private:
  friend class Fragment;
  friend class Index;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const FragmentImpl> impl;
  const unsigned offset;
  const TokenSubstitutionKind kind_;

  inline TokenSubstitution(
      std::shared_ptr<const FragmentImpl> impl_,
      unsigned offset_, TokenSubstitutionKind kind__)
      : impl(std::move(impl_)),
        offset(offset_),
        kind_(kind__) {}

 public:
  inline TokenSubstitutionKind kind(void) const noexcept {
    return kind_;
  }

  TokenSubstitutionList before(void) const;
  TokenSubstitutionList after(void) const;
};

class TokenSubstitutionListIterator;

using TokenSubstitutionEnty = std::variant<Token, TokenSubstitution>;

// Iterate over a list of token or token substitution nodes.
class TokenSubstitutionListIterator {
 private:
  friend class TokenSubstitutionList;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const TokenSubstitutionListImpl> impl;
  unsigned index;
  unsigned num_nodes;

  bool operator==(const TokenSubstitutionListIterator &) = delete;
  bool operator!=(const TokenSubstitutionListIterator &) = delete;

  inline TokenSubstitutionListIterator(
      std::shared_ptr<const TokenSubstitutionListImpl> impl_,
      unsigned index_, unsigned num_nodes_)
      : impl(std::move(impl_)),
        index(index_),
        num_nodes(num_nodes_) {}

 public:
  using EndIteratorType = IteratorEnd;

  std::variant<Token, TokenSubstitution> operator*(void) const;

  // Pre-increment.
  inline TokenSubstitutionListIterator &operator++(void) noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline TokenSubstitutionListIterator operator++(int) noexcept {
    return TokenSubstitutionListIterator(impl, index++, num_nodes);
  }

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_nodes;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_nodes;
  }
};

// List of token or substitution nodes.
class TokenSubstitutionList {
 private:
  friend class Fragment;
  friend class TokenSubstitution;

  std::shared_ptr<const TokenSubstitutionListImpl> impl;
  unsigned num_nodes{0u};

  inline TokenSubstitutionList(
      std::shared_ptr<const TokenSubstitutionListImpl> impl_,
      unsigned num_nodes_)
      : impl(std::move(impl_)),
        num_nodes(num_nodes_) {}

 public:
  TokenSubstitutionList(void) = default;

  inline TokenSubstitutionListIterator begin(void) && noexcept {
    return TokenSubstitutionListIterator(std::move(impl), 0, num_nodes);
  }

  inline TokenSubstitutionListIterator begin(void) const & noexcept {
    return TokenSubstitutionListIterator(impl, 0, num_nodes);
  }

  inline TokenSubstitutionListIterator::EndIteratorType
  end(void) const noexcept {
    return {};
  }
};

}  // namespace mx
