// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <deque>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <mutex>

#include "AST.h"
#include "Types.h"

namespace mx {

class EntityProvider;
class File;
class FileFragmentList;
class FileFragmentListIterator;
class FileImpl;
class Fragment;
class FragmentImpl;
class InvalidEntityProvider;
class RemoteEntityProvider;
class Token;
class TokenList;
class TokenListIterator;
class TokenReader;
class TokenSubstitution;
class TokenSubstitutionList;
class TokenSubstitutionListImpl;

using FileList = std::map<std::filesystem::path, FileId>;

// A single token, e.g. from a file or from a macro expansion.
class Token {
 private:
  friend class Fragment;
  friend class FragmentImpl;
  friend class TokenList;
  friend class TokenListIterator;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const TokenReader> impl;
  unsigned index;

  inline Token(std::shared_ptr<const TokenReader> impl_, unsigned index_)
      : impl(std::move(impl_)),
        index(index_) {}

 public:
  // Return an invalid token.
  static Token invalid(void) noexcept;

  // Return `true` if this is a valid token.
  operator bool(void) const noexcept;

  // Kind of this token.
  TokenKind kind(void) const noexcept;

  // Return the data of this token.
  std::string_view data(void) const noexcept;

  // Return the ID of this token.
  EntityId id(void) const noexcept;
};

class TokenListEnd {};

// Forward-only iterator over a sequence of tokens.
class TokenListIterator {
 private:
  friend class TokenList;

  Token impl;
  unsigned num_tokens;

  bool operator==(const TokenListIterator &) = delete;
  bool operator!=(const TokenListIterator &) = delete;

  inline TokenListIterator(std::shared_ptr<const TokenReader> impl_,
                           unsigned index_, unsigned num_tokens_)
      : impl(std::move(impl_), index_),
        num_tokens(num_tokens_) {}

 public:
  inline bool operator==(TokenListEnd) const noexcept {
    return impl.index >= num_tokens;
  }

  inline bool operator!=(TokenListEnd) const noexcept {
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

// List of tokens.
class TokenList {
 private:
  friend class File;
  friend class Fragment;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const TokenReader> impl;
  unsigned num_tokens;

  inline TokenList(std::shared_ptr<const TokenReader> impl_,
                   unsigned num_tokens_)
      : impl(std::move(impl_)),
        num_tokens(num_tokens_) {}

 public:
  // Return the token list containing a particular token.
  static TokenList containing(Token tok) noexcept;

  // Return the number of tokens in this token list.
  inline size_t size(void) const noexcept {
    return num_tokens;
  }

  // Return the token at index `index`.
  Token operator[](size_t index) const noexcept;

  // Return an iterator pointing at the first token in this list.
  inline TokenListIterator begin(void) const noexcept {
    return TokenListIterator(impl, 0, num_tokens);
  }

  inline TokenListEnd end(void) const noexcept {
    return {};
  }
};

class FileFragmentListEnd {};

// Iterate over the fragments from a file.
class FileFragmentListIterator {
 private:
  friend class File;
  friend class FileFragmentList;

  std::shared_ptr<const FileImpl> impl;
  unsigned index;
  unsigned num_fragments;

  inline FileFragmentListIterator(std::shared_ptr<const FileImpl> impl_,
                                  unsigned index_, unsigned num_fragments_)
      : impl(std::move(impl_)),
        index(index_),
        num_fragments(num_fragments_) {}

 public:

  Fragment operator*(void) const noexcept;

  // Pre-increment.
  inline FileFragmentListIterator &operator++(void) noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline FileFragmentListIterator operator++(int) noexcept {
    return FileFragmentListIterator(impl, index++, num_fragments);
  }

  inline bool operator==(FileFragmentListEnd) const noexcept {
    return index == num_fragments;
  }

  inline bool operator!=(FileFragmentListEnd) const noexcept {
    return index != num_fragments;
  }
};

// List of fragments asociated with a file.
class FileFragmentList {
 private:
  friend class File;

  std::shared_ptr<const FileImpl> impl;
  unsigned num_fragments;

  inline FileFragmentList(std::shared_ptr<const FileImpl> impl_,
                          unsigned num_fragments_)
      : impl(std::move(impl_)),
        num_fragments(num_fragments_) {}

 public:
  // Return the number of fragments in this token list.
  inline size_t size(void) const noexcept {
    return num_fragments;
  }

  // Return an iterator pointing at the first token in this list.
  inline FileFragmentListIterator begin(void) const noexcept {
    return FileFragmentListIterator(impl, 0, num_fragments);
  }

  inline FileFragmentListEnd end(void) const noexcept {
    return {};
  }
};

// Represents a file. A given file may have many associated paths. We
// de-duplicate via a hash of the contents.
class File {
 private:
  using Ptr = std::shared_ptr<const FileImpl>;

  friend class EntityProvider;
  friend class FileFragmentList;
  friend class RemoteEntityProvider;
  friend class Token;
  friend class TokenSubstitutionListIterator;

  Ptr impl;

  inline File(std::shared_ptr<const FileImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  inline static File containing(const FileFragmentList &fragment_list) {
    return File(fragment_list.impl);
  }

  // Return the file containing a specific fragment.
  static File containing(const Fragment &fragment);

  // Return `true` if this is a valid file.
  operator bool(void) const noexcept;

  // Return the ID of this file.
  FileId id(void) const noexcept;

  // Return the list of tokens in this file.
  TokenList tokens(void) const noexcept;

  // Return the list of fragments in this file.
  FileFragmentList fragments(void) const noexcept;

  inline bool operator==(const File &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const File &that) const noexcept {
    return id() != that.id();
  }
};

// A token substitution gives access to the before and after tokens of a
// substitution. There can be one-or-more `before` tokens (e.g. function-like
// macro expansions, file inclusions) and zero-or-more `after` tokens.
class TokenSubstitution {
 private:
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

  TokenSubstitutionList before(void) const noexcept;
  TokenSubstitutionList after(void) const noexcept;
};

class TokenSubstitutionListIterator;

using TokenSubstitutionEnty = std::variant<Token, TokenSubstitution>;

class TokenSubstitutionListEnd {};

// Iterate over a list of token or token substitution nodes.
class TokenSubstitutionListIterator {
 private:
  friend class TokenSubstitutionList;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const TokenSubstitutionListImpl> impl;
  unsigned index;
  unsigned num_nodes;

  inline TokenSubstitutionListIterator(
      std::shared_ptr<const TokenSubstitutionListImpl> impl_,
      unsigned index_, unsigned num_nodes_)
      : impl(std::move(impl_)),
        index(index_),
        num_nodes(num_nodes_) {}

 public:
  std::variant<Token, TokenSubstitution> operator*(void) const noexcept;

  // Pre-increment.
  inline TokenSubstitutionListIterator &operator++(void) noexcept {
    ++index;
    return *this;
  }

  // Post-increment.
  inline TokenSubstitutionListIterator operator++(int) noexcept {
    return TokenSubstitutionListIterator(impl, index++, num_nodes);
  }

  inline bool operator==(TokenSubstitutionListEnd) const noexcept {
    return index == num_nodes;
  }

  inline bool operator!=(TokenSubstitutionListEnd) const noexcept {
    return index != num_nodes;
  }
};

// List of token or substitution nodes.
class TokenSubstitutionList {
 private:
  friend class Fragment;
  friend class TokenSubstitution;

  std::shared_ptr<const TokenSubstitutionListImpl> impl;
  unsigned num_nodes;

  inline TokenSubstitutionList(
      std::shared_ptr<const TokenSubstitutionListImpl> impl_,
      unsigned num_nodes_)
      : impl(std::move(impl_)),
        num_nodes(num_nodes_) {}

 public:
  inline TokenSubstitutionListIterator begin(void) const noexcept {
    return TokenSubstitutionListIterator(impl, 0, num_nodes);
  }

  inline TokenSubstitutionListEnd end(void) const noexcept {
    return {};
  }
};

// A fragment of code containing one or more top-level declarations, the
// associated declaration and statement entities, macro expansion/substitution
// trees, and tokens.
class Fragment {
 private:
  friend class EntityProvider;
  friend class File;
  friend class FileFragmentListIterator;
  friend class RemoteEntityProvider;
  friend class Token;
  friend class TokenSubstitutionListIterator;

  std::shared_ptr<const FragmentImpl> impl;

  inline Fragment(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  // Return `true` if this is a valid fragment.
  operator bool(void) const noexcept;

  // Return the ID of this fragment.
  FragmentId id(void) const noexcept;

  // The smallest line of the file for which one of the tokens from this
  // fragment resides.
  unsigned first_line(void) const noexcept;

  // The largest line of the file for which one of the tokens from this
  // fragment resides.
  unsigned last_line(void) const noexcept;

  // Return the list of parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  TokenList tokens(void) const noexcept;

  // Return the list of token substitutions.
  TokenSubstitutionList unparsed_tokens(void) const noexcept;

  // Return the list of top-level declarations in this fragment.
  std::vector<Decl> declarations(void) const noexcept;

  inline bool operator==(const Fragment &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const Fragment &that) const noexcept {
    return id() != that.id();
  }
};

// Provides the APIs with entities.
class EntityProvider : public std::enable_shared_from_this<EntityProvider> {
 public:

  using Ptr = std::shared_ptr<EntityProvider>;

  virtual ~EntityProvider(void) noexcept;

  // Returns an entity provider that gets entities from a remote host.
  static Ptr from_remote(std::string host, std::string port);

  // Returns an entity provider that gets entities from a UNIX domain socket.
  static Ptr from_socket(std::filesystem::path path);

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual FileList list_files(void) noexcept = 0;

  // Download a file by its unique ID.
  virtual File file(FileId id) noexcept = 0;

  // Download a fragment by its unique ID.
  virtual Fragment fragment(FragmentId id) noexcept = 0;

  // Download a fragment based off of an entity ID.
  Fragment fragment_containing(EntityId) noexcept;
};

class FileManager {
 private:
  EntityProvider::Ptr ep;
};

}  // namespace mx
