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
class FileLocationCache;
class Fragment;
class FragmentImpl;
class Index;
class TokenContext;
class TokenRangeIterator;
class TokenRange;
class TokenReader;

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
  friend class TokenRangeIterator;
  friend class TokenRange;

  std::shared_ptr<const TokenReader> impl;
  unsigned offset;

  inline Token(std::shared_ptr<const TokenReader> impl_, unsigned offset_)
      : impl(std::move(impl_)),
        offset(offset_) {}

 public:
  Token(void);

  // Return `true` if this is a valid token.
  operator bool(void) const;

  // Kind of this token.
  TokenKind kind(void) const;

  // Return the data of this token.
  std::string_view data(void) const &;

  // Return the ID of this token.
  EntityId id(void) const;

  // Return the token from which this token was derived. This can be a macro
  // token or a file token.
  std::optional<Token> derived_token(void) const;

  // Return the version of this token from a file, if any. If this is a parsed
  // or macro token, then this will walk the derivation chain back to a file
  // token.
  std::optional<Token> file_token(void) const;

  // Return the version of this token from a file, if any. If there isn't a
  // one-to-one correspondence between this token and a file token, then it
  // likely means this token exists inside of a macro expansion. If that is the
  // case, then this will return the beginning token of the macro expansion.
  std::optional<Token> nearest_file_token(void) const;

  // Return the set of all uses of this token within its fragment (if it's a
  // fragment token).
  UseRange<TokenUseSelector> uses(void) const;

  // Return the line and column number for this token, if any.
  std::optional<std::pair<unsigned, unsigned>> location(
      const FileLocationCache &) const;

  // Return the line and column number for what immediately follows this token,
  // if any.
  std::optional<std::pair<unsigned, unsigned>> next_location(
      const FileLocationCache &) const;

  // Return the line and column number for the file token nearest to this token,
  // if any.
  inline std::optional<std::pair<unsigned, unsigned>> nearest_location(
      const FileLocationCache &cache) const {
    if (auto maybe_file_token = nearest_file_token()) {
      return maybe_file_token->location(cache);
    } else {
      return std::nullopt;
    }
  }
};

// Forward-only iterator over a sequence of tokens.
class TokenRangeIterator {
 private:
  friend class TokenRange;

  Token impl;
  unsigned num_tokens;

  bool operator==(const TokenRangeIterator &) = delete;
  bool operator!=(const TokenRangeIterator &) = delete;

  inline TokenRangeIterator(std::shared_ptr<const class TokenReader> impl_,
                           unsigned index_, unsigned num_tokens_)
      : impl(std::move(impl_), index_),
        num_tokens(num_tokens_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return impl.offset >= num_tokens;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.offset < num_tokens;
  }

  // Return the current token pointed to by the iterator.
  inline Token operator*(void) && noexcept {
    return std::move(impl);
  }

  // Return the current token pointed to by the iterator.
  inline const Token &operator*(void) const & noexcept {
    return impl;
  }

  inline const Token *operator->(void) const & noexcept {
    return &impl;
  }

  // Pre-increment.
  inline TokenRangeIterator operator++(void) && noexcept {
    auto next_offset = impl.offset + 1u;
    return TokenRangeIterator(std::move(impl.impl), next_offset, num_tokens);
  }

  // Pre-increment.
  inline TokenRangeIterator &operator++(void) & noexcept {
    ++impl.offset;
    return *this;
  }

  // Post-increment.
  inline TokenRangeIterator operator++(int) noexcept {
    return TokenRangeIterator(impl.impl, impl.offset++, num_tokens);
  }
};

// A range of tokens.
class TokenRange {
 protected:
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Macro;
  friend class RegexQueryResultIterator;
  friend class WeggliQueryResultIterator;

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

  TokenRange(const Token &);

  TokenRange(const TokenRange &) = default;
  TokenRange(TokenRange &&) noexcept = default;

  TokenRange &operator=(const TokenRange &) = default;
  TokenRange &operator=(TokenRange &&) noexcept = default;

  inline operator bool(void) const noexcept {
    return num_tokens && (num_tokens - index);
  }

  // Return the number of tokens in this token list.
  inline size_t size(void) const noexcept {
    return num_tokens - index;
  }

  // Return the token at index `index`.
  Token operator[](size_t index) const;

  // Return the first token.
  Token front(void) const;

  // Return the last token.
  Token back(void) const;

  // Return the underlying token data associated with the tokens covered by this
  // token range.
  std::string_view data(void) const &;

  // Return an iterator pointing at the first token in this list.
  inline TokenRangeIterator begin(void) && noexcept {
    return TokenRangeIterator(std::move(impl), index, num_tokens);
  }

  // Return an iterator pointing at the first token in this list.
  inline TokenRangeIterator begin(void) const & noexcept {
    return TokenRangeIterator(impl, index, num_tokens);
  }

  inline TokenRangeIterator::EndIteratorType end(void) && noexcept {
    return {};
  }

  inline TokenRangeIterator::EndIteratorType end(void) const & noexcept {
    return {};
  }

  // Return a slice of this token range. If the indices given are invalid, then
  // an empty token range is returned. The indices cover the tokens in the
  // exclusive range `[start_index, end_index)`.
  TokenRange slice(size_t start_index, size_t end_index) const noexcept;

  // Returns the index of `that` in this range, or `std::nullopt`.
  std::optional<unsigned> index_of(const Token &that) const noexcept;

  // Convert this token range into a file token range.
  //
  // NOTE(pag): This will not always work because it will use the derived token
  //            chain to locate the begin/end, and those may not represent the
  //            actual bounds of the entity. Consider the following macro:
  //
  //                #define DECLARE(end, name, type) type name end
  //                DECLARE(;, foo, int)
  //
  //            Here, the file token from which the end of the parsed token
  //            range is derived is the `;`, which precedes the file token
  //            derived from the first parsed token, `int`.
  TokenRange file_tokens(void) const noexcept;

  // Strip leading and trailing whitespace.
  TokenRange strip_whitespace(void) const noexcept;
};

}  // namespace mx
