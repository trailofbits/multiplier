// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Fragment.h"

namespace mx {

class EntityProvider;
class File;
class FileImpl;
class Fragment;
class FragmentImpl;
class Index;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryImpl;
class RegexQueryResultIterator;
class RegexQueryMatch;
class RegexQueryResultImpl;
class RegexQueryResult;
class InvalidEntityProvider;
class WeggliQuery;
class WeggliQueryMatch;
class WeggliQueryResultIterator;
class WeggliQueryResult;
class WeggliQueryResultImpl;

// The range of tokens of a match.
class WeggliQueryMatch : public TokenRange {
 private:
  friend class File;
  friend class Fragment;
  friend class WeggliQueryResult;
  friend class WeggliQueryResultImpl;

  // Fragment with the match
  std::shared_ptr<const FragmentImpl> frag;
  
  // The whole match.
  std::string_view match_data;

  // Map variables with token range.
  std::vector<std::string> variables;
  std::vector<std::string_view> matched_data;
  std::vector<TokenRange> matched_tokens;

  WeggliQueryMatch(void) = delete;

 public:
  WeggliQueryMatch(
      std::shared_ptr<const FragmentImpl> frag_,
      std::shared_ptr<const TokenReader> impl_,
      unsigned index_, unsigned num_tokens_,
      std::string_view match_data_,
      std::vector<std::string> variables_,
      std::vector<std::string_view> matched_data_,
      std::vector<TokenRange> matched_tokens_);

  // Return the captured tokens for a given named capture group.
  std::optional<TokenRange> captured_tokens(const std::string &var) const;

  // Return the captured data for a given named capture group.
  std::optional<std::string_view> captured_data(const std::string &var) const;

  // Return the captured tokens for a given indexed capture group.
  std::optional<TokenRange> captured_tokens(size_t capture_index) const;

  // Return the captured data for a given indexed capture group.
  std::optional<std::string_view> captured_data(size_t capture_index) const;

  // Return a list of matched variables.
  inline const std::vector<std::string> &captured_variables(void) const & {
    return variables;
  }

  // Return the index of a captured variable.
  std::optional<size_t> index_of_captured_variable(
    const std::string &var) const;

  // Return the number of capture groups.
  inline size_t num_captures(void) const {
    return 1u + matched_tokens.size();
  }
};

class WeggliQueryResultIterator {
 private:
  friend class WeggliQueryResult;

  std::shared_ptr<WeggliQueryResultImpl> impl;

  unsigned index;
  unsigned num_fragments;
  std::optional<WeggliQueryMatch> result;

  // Try to advance to the next result. There can be multiple results per
  // fragment.
  void Advance(void);

  inline WeggliQueryResultIterator(
      std::shared_ptr<WeggliQueryResultImpl> impl_,
      unsigned index_, unsigned num_fragments_)
      : impl(std::move(impl_)),
        index(index_),
        num_fragments(num_fragments_) {
    Advance();
  }

 public:
  inline WeggliQueryMatch operator*(void) && noexcept {
    return std::move(result.value());
  }

  inline const WeggliQueryMatch &operator*(void) const & noexcept {
    return result.value();
  }

  inline const WeggliQueryMatch *operator->(void) const & noexcept {
    return std::addressof(result.value());
  }

  inline bool operator==(IteratorEnd) const noexcept {
    return index >= num_fragments;
  }

  inline bool operator!=(IteratorEnd) const noexcept {
    return index < num_fragments;
  }

  // Pre-increment.
  inline WeggliQueryResultIterator &operator++(void) noexcept {
    Advance();
    return *this;
  }
};

// NOTE(pag): The iterators from this are *NOT* restartable.
class WeggliQueryResult {
 private:

  using Ptr = std::shared_ptr<const WeggliQueryResult>;

  friend class EntityProvider;
  friend class RemoteEntityProvider;
  friend class InvalidEntityProvider;
  friend class WeggliQueryResultIterator;

  std::shared_ptr<WeggliQueryResultImpl> impl;
  unsigned num_fragments{0u};

 public:
  WeggliQueryResult(void) = default;
  WeggliQueryResult(std::shared_ptr<WeggliQueryResultImpl> impl_);

  // Return an iterator pointing at the first token in this list.
  inline WeggliQueryResultIterator begin(void) && noexcept {
    return WeggliQueryResultIterator(std::move(impl), 0, num_fragments);
  }

  // Return an iterator pointing at the first token in this list.
  inline WeggliQueryResultIterator begin(void) const & noexcept {
    return WeggliQueryResultIterator(impl, 0, num_fragments);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

// The range of tokens that matches a regular expression.
class RegexQueryMatch : public TokenRange {
 private:
  friend class File;
  friend class Fragment;
  friend class RegexQuery;
  friend class RegexQueryResult;
  friend class RegexQueryResultImpl;

  // The actual range of matched data. This is possibly a sub-sequence of
  // `this->TokenRange::data()`.
  std::vector<std::string_view> matched_ranges;

  // Fragment with the match.
  std::shared_ptr<const FragmentImpl> frag;

  // The regular expression used.
  std::shared_ptr<RegexQueryImpl> query;

  // Translate a data capture into a token range capture.
  std::optional<TokenRange> TranslateCapture(std::string_view capture) const;

  RegexQueryMatch(TokenRange range_, std::string_view data_range_,
                  std::shared_ptr<const FragmentImpl> frag_,
                  const RegexQuery &query_);

  RegexQueryMatch(void) = delete;

 public:
  ~RegexQueryMatch(void);

  // The actual range of matched data. This is possibly a sub-sequence of
  // `this->TokenRange::data()`.
  inline std::string_view data(void) const noexcept {
    return matched_ranges[0];
  }

  // Return the index of a capture variable.
  std::optional<size_t> index_of_captured_variable(const std::string &var) const;

  // Return the captured tokens for a given named capture group.
  std::optional<TokenRange> captured_tokens(const std::string &var) const;

  // Return the captured data for a given named capture group.
  std::optional<std::string_view> captured_data(const std::string &var) const;

  // Return the captured tokens for a given indexed capture group.
  std::optional<TokenRange> captured_tokens(size_t catpture_index) const;

  // Return the captured data for a given indexed capture group.
  std::optional<std::string_view> captured_data(size_t capture_index) const;

  // Return a list of named capture groups.
  std::vector<std::string> captured_variables(void) const;

  // Return the number of capture groups.
  size_t num_captures(void) const;
};

class RegexQueryResultIterator {
 private:
  friend class RegexQueryResult;

  std::shared_ptr<RegexQueryResultImpl> impl;

  unsigned index;
  unsigned num_matches;

  std::optional<RegexQueryMatch> result;

  // Try to advance to the next result. There can be multiple results per
  // fragment.
  void Advance(void);

  inline RegexQueryResultIterator(
      std::shared_ptr<RegexQueryResultImpl> impl_,
      unsigned index_, unsigned num_matches_)
      : impl(std::move(impl_)),
        index(index_),
        num_matches(num_matches_) {
    Advance();
  }

 public:
  inline RegexQueryMatch operator*(void) && noexcept {
    return std::move(result.value());
  }

  inline const RegexQueryMatch &operator*(void) const & noexcept {
    return result.value();
  }

  inline const RegexQueryMatch *operator->(void) const & noexcept {
    return std::addressof(result.value());
  }

  inline bool operator==(IteratorEnd) const noexcept {
    return index >= num_matches;
  }

  inline bool operator!=(IteratorEnd) const noexcept {
    return index < num_matches;
  }

  // Pre-increment.
  inline RegexQueryResultIterator &operator++(void) noexcept {
    Advance();
    return *this;
  }
};

// NOTE(pag): The iterators from this are *NOT* restartable.
class RegexQueryResult {
 private:

  using Ptr = std::shared_ptr<const RegexQueryResult>;

  friend class EntityProvider;
  friend class RemoteEntityProvider;
  friend class InvalidEntityProvider;
  friend class RegexQueryResultIterator;

  std::shared_ptr<RegexQueryResultImpl> impl;
  unsigned num_fragments{0u};

 public:
  RegexQueryResult(void) = default;

  RegexQueryResult(std::shared_ptr<RegexQueryResultImpl> impl_);

  // Return an iterator pointing at the first token in this list.
  inline RegexQueryResultIterator begin(void) && noexcept {
    return RegexQueryResultIterator(std::move(impl), 0, num_fragments);
  }

  // Return an iterator pointing at the first token in this list.
  inline RegexQueryResultIterator begin(void) const & noexcept {
    return RegexQueryResultIterator(impl, 0, num_fragments);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

}  // namespace mx
