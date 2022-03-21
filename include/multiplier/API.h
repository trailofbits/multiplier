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
#include <set>

#include "AST.h"
#include "Types.h"

namespace mx {

class EntityProvider;
class FileImpl;
class Fragment;
class FragmentImpl;
class InvalidEntityProvider;
class RemoteEntityProvider;
class RemoteEntityProviderImpl;
class Token;
class TokenList;
class TokenListIterator;
class TokenReaderImpl;

// A single token, e.g. from a file or from a macro expansion.
class Token {
 private:
  friend class Fragment;
  friend class FragmentImpl;
  friend class TokenList;
  friend class TokenListIterator;

  std::shared_ptr<const TokenReaderImpl> impl;
  unsigned index;

  inline Token(std::shared_ptr<const TokenReaderImpl> impl_, unsigned index_)
      : impl(std::move(impl_)),
        index(index_) {}

 public:
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

  inline TokenListIterator(std::shared_ptr<const TokenReaderImpl> impl_,
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

  std::shared_ptr<const TokenReaderImpl> impl;
  unsigned num_tokens;

  inline TokenList(std::shared_ptr<const TokenReaderImpl> impl_,
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

// Represents a file. A given file may have many associated paths. We
// de-duplicate via a hash of the contents.
class File {
 private:
  friend class EntityProvider;
  friend class Token;
  friend class RemoteEntityProvider;

  std::shared_ptr<const FileImpl> impl;

  inline File(std::shared_ptr<const FileImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  // Return the file containing a specific fragment.
  static File containing(const Fragment &fragment);

  // Return `true` if this is a valid file.
  operator bool(void) const noexcept;

  // Return the ID of this file.
  FileId id(void) const noexcept;

  // Return the list of tokens in this file.
  TokenList tokens(void) const noexcept;

  inline bool operator==(const File &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const File &that) const noexcept {
    return id() != that.id();
  }
};

// A fragment of code containing one or more top-level declarations, the
// associated declaration and statement entities, macro expansion/substitution
// trees, and tokens.
class Fragment {
 private:
  friend class EntityProvider;
  friend class File;
  friend class RemoteEntityProvider;
  friend class Token;

  std::shared_ptr<const FragmentImpl> impl;

  inline Fragment(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  // Return `true` if this is a valid fragment.
  operator bool(void) const noexcept;

  // Return the ID of this fragment.
  FragmentId id(void) const noexcept;

  // Return the list of parsed tokens in the fragment. This doesn't
  // include all tokens, i.e. macro use tokens, comments, etc.
  TokenList tokens(void) const noexcept;

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

  using Ptr = std::shared_ptr<const EntityProvider>;

  virtual ~EntityProvider(void);

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual std::set<std::pair<std::filesystem::path, FileId>>
  list_files(void) const = 0;

  // Download a file by its unique ID.
  virtual File file(FileId id) const noexcept = 0;

  // Download a fragment by its unique ID.
  virtual Fragment fragment(FragmentId id) const noexcept = 0;

  // Download a fragment based off of an entity ID.
  Fragment fragment_containing(EntityId) const noexcept;
};

// Provides entities from a remote source, i.e. a remote
// server available via `host:port`, or another process
// available over a UNIX domain socket `unix:/path`.
class RemoteEntityProvider final : public EntityProvider {
 private:
  const std::unique_ptr<RemoteEntityProviderImpl> impl;

 public:
  RemoteEntityProvider(RemoteEntityProviderImpl *impl_);

  virtual ~RemoteEntityProvider(void);

  static Ptr Create(std::string host, std::string port);

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  std::set<std::pair<std::filesystem::path, FileId>>
  list_files(void) const final;

  // Download a file by its unique ID.
  File file(FileId id) const noexcept final;

  // Download a fragment by its unique ID.
  Fragment fragment(FragmentId id) const noexcept final;
};

class FileManager {
 private:
  EntityProvider::Ptr ep;
};

}  // namespace mx
