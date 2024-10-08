// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>
#include <variant>

#include "../Iterator.h"
#include "../Reference.h"

namespace mx {

class Compilation;
class CompilationImpl;
class CustomTokenReader;
class Designator;
class EntityProvider;
class File;
class FileLocationCache;
class Fragment;
class Index;
class MacroSubstitution;
class MacroVAOpt;
class NamedDecl;
class Reference;
class RegexQuery;
class RegexQueryMatch;
class RegexQueryMatchImpl;
class RegexQueryResultImpl;
class RegexQueryResultIterator;
class TokenContext;
class TokenRangeIterator;
class TokenRange;
class TokenReader;
class TokenTokenTreeNode;
class TokenTree;
class TokenTreeImpl;
class TypeImpl;

enum class TokenKind : unsigned short;
enum class TokenCategory : unsigned char;
class UserToken;  // Defined in Index.h due to `VariantEntity`.
using CustomToken = std::variant<UserToken, Token>;

// A single token, e.g. from a file or from a macro expansion. There are several
// types of tokens, and they can be distinguished by way of the token ID, when
// it is unpacked to a `VariantId`.
//
//    1)  File tokens: these are derived from the token stream when Clang lexed
//        a file. File tokens might not have the "most resolved" kinds. For
//        example, a file token might present itself as being a keyword, but
//        when it is pre-processed, it ends up being interpreted as an
//        identifier because a macro is defined with the same name. These tokens
//        are never referenced directly by AST nodes. These tokens are
//        identified by `FileTokenId`s.
//
//    2)  Macro tokens: these are how the C preprocessor sees the tokens. These
//        tokens are never referenced directly by AST nodes. These tokens are
//        identified by `MacroTokenId`s.
//        
//    3)  Parsed tokens: these tokens are the final result of pre-processing,
//        and thus there is a 1:1 mapping between each parsed token and a macro
//        token. These tokens are the only ones referenced by non-`Type` AST
//        nodes, i.e. `Decl`, `Stmt`, etc. These tokens are identified by
//        `ParsedTokenId`s.
//
//    4)  Type tokens: these tokens are used to visually represent `Type` AST
//        nodes. They should be the only tokens referenced by `Type`-related
//        AST nodes, and no other AST nodes should ever reference `Type` tokens.
//        These tokens are identified by `TypeTokenId`s.
class MX_EXPORT Token final {
 private:
  friend class Compilation;
  friend class CompilationImpl;
  friend class CustomTokenReader;
  friend class EntityProvider;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class NamedDecl;
  friend class Reference;
  friend class TokenContext;
  friend class TokenRangeIterator;
  friend class TokenRange;
  friend class TokenReader;
  friend class TokenTokenTreeNode;
  friend class TokenTree;
  friend class TokenTreeImpl;
  friend class TypeImpl;

  TokenImplPtr impl;
  EntityOffset offset;

  inline Token(std::shared_ptr<const TokenReader> impl_, EntityOffset offset_)
      : impl(std::move(impl_)),
        offset(offset_) {}

 public:
  Token(void);

  // Try to convert a variant entity into a token.
  static std::optional<Token> from(const VariantEntity &entity);

  inline static constexpr EntityCategory entity_category(void) {
    return EntityCategory::TOKEN;
  }

  // Return `true` if this is a valid token.
  operator bool(void) const;

  // Kind of this token.
  TokenKind kind(void) const;

  // Return the data of this token.
  std::string_view data(void) const &;

  // Return the ID of this token.
  EntityId id(void) const;

  inline bool operator==(const Token &that) const noexcept {
    return id().Pack() == that.id().Pack();
  }

  // Return the context node that identifies how this token relates to the AST.
  //
  // NOTE(pag): This only works with parsed tokens, and not all parsed tokens
  //            are guaranteed to have a context.
  std::optional<TokenContext> context(void) const;

  // Return the version of this token that was actually parsed. If this was a
  // macro token that only relates to a single parsed token, then that is
  // returned. If this is a macro token that doesn't relate to any parsed
  // tokens, or relates to more than one, then nothing is returned. If this
  // is a file token then nothing is returned.
  Token parsed_token(void) const;

  // Return the token from which this token was derived. This can be a macro
  // token or a file token.
  Token derived_token(void) const;

  // Return the version of this token from a file, if any. If this is a parsed
  // or macro token, then this will walk the derivation chain back to a file
  // token.
  Token file_token(void) const;

  // Return the version of this token from a file, if any. If there isn't a
  // one-to-one correspondence between this token and a file token, then it
  // likely means this token exists inside of a macro expansion. If that is the
  // case, then this will return the beginning token of the macro expansion.
  Token nearest_file_token(void) const;

  // Return the entity associated with this token.
  VariantEntity related_entity(void) const;

  // Return the ID entity associated with this token.
  EntityId related_entity_id(void) const;

  // The category of this token. This takes into account any related entities.
  TokenCategory category(void) const;

  // Categorize an entity into a token category. This is useful for creating
  // `UserToken`s.
  static TokenCategory categorize(const VariantEntity &entity) noexcept;

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
      return maybe_file_token.location(cache);
    } else {
      return std::nullopt;
    }
  }

  // The macro that immediately contains this token, if any.
  std::optional<Macro> containing_macro(void) const;
};

// Forward-only iterator over a sequence of tokens.
class MX_EXPORT TokenRangeIterator {
 private:
  friend class TokenRange;
  friend class TokenTree;

  Token impl;
  unsigned end_offset;

  bool operator==(const TokenRangeIterator &) = delete;
  bool operator!=(const TokenRangeIterator &) = delete;

  inline TokenRangeIterator(std::shared_ptr<const class TokenReader> impl_,
                           unsigned index_, unsigned end_offset_)
      : impl(std::move(impl_), index_),
        end_offset(end_offset_) {}

 public:
  using EndIteratorType = IteratorEnd;

  inline bool operator==(EndIteratorType) const noexcept {
    return impl.offset >= end_offset;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return impl.offset < end_offset;
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
    return TokenRangeIterator(std::move(impl.impl), next_offset, end_offset);
  }

  // Pre-increment.
  inline TokenRangeIterator &operator++(void) & noexcept {
    ++impl.offset;
    return *this;
  }

  // Post-increment.
  inline TokenRangeIterator operator++(int) noexcept {
    return TokenRangeIterator(impl.impl, impl.offset++, end_offset);
  }
};

// A range of tokens.
class MX_EXPORT TokenRange {
 protected:
  friend class CustomTokenReader;
  friend class EntityProvider;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Macro;
  friend class NamedDecl;
  friend class RegexQuery;
  friend class RegexQueryMatch;
  friend class RegexQueryMatchImpl;
  friend class RegexQueryResultImpl;
  friend class RegexQueryResultIterator;
  friend class TokenTree;
  friend class TokenTreeImpl;
  friend class TypeImpl;

  std::shared_ptr<const TokenReader> impl;
  EntityOffset index;

  // TokenRange contain end_index to identify the token offset
  // where it ends. The token with end_index offset is exclusive
  // to TokenRange
  EntityOffset end_index;

  inline TokenRange(std::shared_ptr<const TokenReader> impl_,
                    EntityOffset index_, EntityOffset end_index_)
      : impl(std::move(impl_)),
        index(index_),
        end_index(end_index_) {}

 public:
  TokenRange(void);

  TokenRange(const Token &);

  TokenRange(const TokenRange &) = default;
  TokenRange(TokenRange &&) noexcept = default;

  TokenRange &operator=(const TokenRange &) = default;
  TokenRange &operator=(TokenRange &&) noexcept = default;

  static TokenRange create(std::vector<CustomToken> tokens);
  static TokenRange create(const Token &first, const Token &last);

  bool operator==(const TokenRange &that) const noexcept;
  bool operator!=(const TokenRange &that) const noexcept = default;

  inline operator bool(void) const noexcept {
    return !empty();
  }

  inline bool empty(void) const noexcept {
    return index >= end_index;
  }

  // Return the number of tokens in this token list.
  inline size_t size(void) const noexcept {
    return end_index - index;
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
    return TokenRangeIterator(std::move(impl), index, end_index);
  }

  // Return an iterator pointing at the first token in this list.
  inline TokenRangeIterator begin(void) const & noexcept {
    return TokenRangeIterator(impl, index, end_index);
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

  // Generate declarations that share at least one overlapping parsed token
  // in common with the token range.
  gap::generator<Decl> overlapping_declarations(void) const & noexcept;

  // Try to return the declaration such that `decl.tokens() == range`, i.e.
  // this range covers all of the tokens of the declaration. if there are
  // more than one declaration that matches the criteria, it gets the deepest
  // one in the AST. Thereby allowing a caller to observe the
  // others by traversing the parent of the covering declaration.
  std::optional<Decl> covering_declaration(void) const & noexcept;

  // Generate statements that share at least one overlapping parsed token
  // in common with the token range.
  gap::generator<Stmt> overlapping_statements(void) const & noexcept;

  // Try to return the statement such that `stmt.tokens() == range`, i.e.
  // this range covers all of the tokens of the statement. if there are
  // more than one statement that matches the criteria, it gets the deepest
  // one in the AST. Thereby allowing a caller to observe the
  // others by traversing the parent of the covering statement.
  std::optional<Stmt> covering_statement(void) const & noexcept;
};

}  // namespace mx
