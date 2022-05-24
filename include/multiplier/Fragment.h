// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "File.h"

namespace mx {

class Decl;
class EntityProvider;
class File;
class FileFragmentListIterator;
class Fragment;
class FragmentImpl;
class FragmentList;
class FragmentListImpl;
class Index;
class InvalidEntityProvider;
class ReferenceIterator;
class ReferenceIteratorImpl;
class RemoteEntityProvider;
class RegexQuery;
class RegexQueryMatch;
class RegexQueryResult;
class RegexQueryResultImpl;
class RegexQueryResultIterator;
class Stmt;
class Token;
class TokenSubstitutionListIterator;
class Type;
class WeggliQuery;
class WeggliQueryMatch;
class WeggliQueryResult;
class WeggliQueryResultImpl;
class WeggliQueryResultIterator;
class WeggliQueryResultIterator;

// Iterate over the fragments from a file.
class FileFragmentListIterator {
 private:
  friend class FragmentList;

  std::shared_ptr<const FragmentListImpl> impl;
  std::shared_ptr<const FragmentImpl> frag;
  unsigned index{0u};
  unsigned num_fragments{0u};

  bool operator==(const FileFragmentListIterator &) = delete;
  bool operator!=(const FileFragmentListIterator &) = delete;

  inline FileFragmentListIterator(std::shared_ptr<const FragmentListImpl> impl_,
                                  unsigned index_, unsigned num_fragments_)
      : impl(std::move(impl_)),
        index(index_),
        num_fragments(num_fragments_) {
    Advance();
  }

  void Advance(void);

 public:
  using EndIteratorType = IteratorEnd;

  inline Fragment operator*(void) && noexcept;
  inline Fragment operator*(void) const & noexcept;

  // Pre-increment.
  inline FileFragmentListIterator &operator++(void) {
    ++index;
    Advance();
    return *this;
  }

  // Post-increment.
  inline FileFragmentListIterator operator++(int) {
    return FileFragmentListIterator(impl, index++, num_fragments);
  }

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_fragments;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_fragments;
  }
};

// List of fragments asociated with a file.
class FragmentList {
 private:
  friend class File;
  friend class Fragment;

  std::shared_ptr<const FragmentListImpl> impl;
  unsigned num_fragments{0};

  inline FragmentList(std::shared_ptr<const FragmentListImpl> impl_,
                      unsigned num_fragments_)
      : impl(std::move(impl_)),
        num_fragments(num_fragments_) {}

 public:
  // Return the number of fragments in this token list.
  inline size_t size(void) const noexcept {
    return num_fragments;
  }

  // Return an iterator pointing at the first token in this list.
  inline FileFragmentListIterator begin(void) && noexcept {
    return FileFragmentListIterator(std::move(impl), 0, num_fragments);
  }

  // Return an iterator pointing at the first token in this list.
  inline FileFragmentListIterator begin(void) const & noexcept {
    return FileFragmentListIterator(impl, 0, num_fragments);
  }

  inline FileFragmentListIterator::EndIteratorType end(void) const noexcept {
    return {};
  }
};

// A fragment of code containing one or more top-level declarations, the
// associated declaration and statement entities, macro expansion/substitution
// trees, and tokens.
class Fragment {
 private:
  friend class Decl;
  friend class EntityProvider;
  friend class File;
  friend class FileFragmentListIterator;
  friend class FragmentImpl;
  friend class FragmentList;
  friend class Index;
  friend class ReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class RemoteEntityProvider;
  friend class RegexQueryResultImpl;
  friend class RegexQueryResultIterator;
  friend class Stmt;
  friend class Token;
  friend class TokenSubstitutionListIterator;
  friend class Type;
  friend class WeggliQueryResultImpl;
  friend class WeggliQueryResultIterator;

  std::shared_ptr<const FragmentImpl> impl;

  inline Fragment(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  // Return the list of fragments in a file.
  static FragmentList in(const File &);

  // Return the fragment containing a query match.
  static Fragment containing(const WeggliQueryMatch &);

  static Fragment containing(const RegexQueryMatch &);

  static Fragment containing(const Decl &);
  static Fragment containing(const Stmt &);
  static Fragment containing(const Type &);
  static std::optional<Fragment> containing(const Token &);
  static Fragment containing(const TokenSubstitution &);
  static Fragment containing(const UseBase &);
  static Fragment containing(const Reference &);

  // Return the ID of this fragment.
  FragmentId id(void) const noexcept;

  // The range of file tokens in this fragment.
  TokenRange file_tokens(void) const;

  // The range of parsed tokens in this fragment. This is equivalent to
  // `Token::in(fragment)`.
  TokenList parsed_tokens(void) const;

  // Return the list of token substitutions. The original file tokens can be
  // recovered by choosing `.before()` on all substitution objets.
  TokenSubstitutionList substitutions(void) const;

  // Return the list of top-level declarations in this fragment.
  std::vector<Decl> top_level_declarations(void) const;

  // Returns source IR for the fragment.
  std::optional<std::string_view> source_ir(void) const noexcept;

  inline bool operator==(const Fragment &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const Fragment &that) const noexcept {
    return id() != that.id();
  }

  // Run a Weggli search over this fragment.
  WeggliQueryResult query(const WeggliQuery &query) const;

  // Run a regular expression search over this fragment.
  RegexQueryResult query(const RegexQuery &query) const;
};

inline Fragment FileFragmentListIterator::operator*(void) && noexcept {
  return Fragment(std::move(frag));
}

inline Fragment FileFragmentListIterator::operator*(void) const & noexcept {
  return Fragment(frag);
}

}  // namespace mx
