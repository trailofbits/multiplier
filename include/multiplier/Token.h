// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <iterator>
#include <memory>
#include <optional>
#include <string_view>

#include "Result.h"
#include "Types.h"

namespace pasta {
class FileTokenRange;
class TokenRange;
class PrintedTokenRange;
}  // namespace pasta
namespace mx {

enum class TokenKind : uint16_t;  // Auto-generated from Datalog.
struct CompressedTokenList;  // Auto-generated from Datalog.

class TokenList;
class TokenListImpl;
class TokenListIterator;

// A token from a token list.
class Token {
 private:
  friend class TokenList;
  friend class TokenListIterator;

  std::shared_ptr<TokenListImpl> impl;
  unsigned index{0};

  inline Token(std::shared_ptr<TokenListImpl> impl_, unsigned index_)
      : impl(std::move(impl_)),
        index(index_) {}

 public:

  Token(void) = default;
  ~Token(void);

  // Return the index of this token in its token list.
  inline unsigned Index(void) const noexcept {
    return index;
  }

  // Is this a valid token?
  bool IsValid(void) const noexcept;

  // Return the kind of this token.
  TokenKind Kind(void) const noexcept;

  // Return the data of this token.
  std::string_view Data(void) const noexcept;

  inline bool operator==(const Token &that) const noexcept {
    return Kind() == that.Kind() && Data() == that.Data();
  }

  inline bool operator!=(const Token &that) const noexcept {
    return Kind() != that.Kind() || Data() != that.Data();
  }

  // Try to update this token to point to the previous token information.
  inline bool TryUpdateToPrevious(void) noexcept {
    if (index) {
      --index;
      return true;
    } else {
      return false;
    }
  }

  // Try to update this token to point to the next token information. Returns
  // `true` if we made an update, not if the next token is actually valid.
  inline bool TryUpdateToNext(void) noexcept {
    if (IsValid()) {
      ++index;
      return true;
    } else {
      return false;
    }
  }
};

// Iterator for token lists.
class TokenListIterator {
 private:
  friend class TokenList;

  Token impl;

  inline TokenListIterator(std::shared_ptr<TokenListImpl> impl_, unsigned index_)
      : impl(impl_, 0) {}

 public:

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token &operator*(void) const noexcept {
    return impl;
  }

  // NOTE(pag): This is a bit sketchy; make sure not to let the reference to
  //            the token escape beyond a single iteration of the loop.
  inline const Token *operator->(void) const noexcept {
    return &impl;
  }

  inline TokenListIterator &operator++(void) noexcept {
    ++impl.index;
    return *this;
  }

  inline TokenListIterator &operator--(void) noexcept {
    --impl.index;
    return *this;
  }

  inline bool operator!=(const TokenListIterator &that) const noexcept {
    return impl.impl != that.impl.impl || impl.index != that.impl.index;
  }

  inline bool operator==(const TokenListIterator &that) const noexcept {
    return impl.impl == that.impl.impl && impl.index == that.impl.index;
  }

  inline bool operator<=(const TokenListIterator &that) const noexcept {
    if (impl.impl == that.impl.impl) {
      return impl.index <= that.impl.index;
    } else {
      return false;
    }
  }

  inline bool operator>=(const TokenListIterator &that) const noexcept {
    if (impl.impl == that.impl.impl) {
      return impl.index >= that.impl.index;
    } else {
      return false;
    }
  }

  inline bool operator<(const TokenListIterator &that) const noexcept {
    if (impl.impl == that.impl.impl) {
      return impl.index < that.impl.index;
    } else {
      return false;
    }
  }

  inline bool operator>(const TokenListIterator &that) const noexcept {
    if (impl.impl == that.impl.impl) {
      return impl.index > that.impl.index;
    } else {
      return false;
    }
  }
};

// Token list.
class TokenList {
 private:
  std::shared_ptr<TokenListImpl> impl;

  inline TokenList(std::shared_ptr<TokenListImpl> impl_)
      : impl(std::move(impl_)) {}

 public:

  TokenList(void);
  ~TokenList(void);

  // Return the token data as a single string.
  std::string_view Data(void) const noexcept;

  // Return the number of tokens in this token list.
  unsigned Size(void) const noexcept;

  inline size_t size(void) const noexcept {
    return Size();
  }

  // NOTE(pag): Might return an invalid token.
  Token operator[](size_t index) const noexcept {
    return Token(impl, static_cast<unsigned>(index));
  }

  inline TokenListIterator begin(void) const noexcept {
    return TokenListIterator(impl, 0);
  }

  inline TokenListIterator end(void) const noexcept {
    return TokenListIterator(impl, Size());
  }

  // Serialize this token list into a "compressed token list," as represented
  // by a Flatbuffers message.
  Result<flatbuffers::Offset<CompressedTokenList>, std::string> Compress(
      flatbuffers::FlatBufferBuilder &fbb);

  // Create a token list from a file token range.
  static TokenList Create(const pasta::FileTokenRange &toks);

  // Create a token list from a printed token range.
  static TokenList Create(const pasta::PrintedTokenRange &toks);

  // Create a token list from a parsed token range.
  static TokenList Create(const pasta::TokenRange &toks);

  // Uncompress a token list from its Flatbuffers-serialized form.
  static Result<TokenList, std::string> Create(const CompressedTokenList &toks);

  // Uncompress a token list from its Flatbuffers-serialized form.
  inline static Result<TokenList, std::string>
  Create(const CompressedTokenList *toks) {
    if (toks) {
      return Create(*toks);
    } else {
      return TokenList();
    }
  }
};

}  // namespace mx
namespace std {
template <>
struct iterator_traits<::mx::TokenListIterator> {
 public:
  typedef mx::Token value_type;
  typedef const mx::Token &reference;
  typedef const mx::Token *pointer;
  typedef std::forward_iterator_tag iterator_category;
};
}  // namespace std
