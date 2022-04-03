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
#include <unordered_map>
#include <vector>
#include <map>
#include <mutex>
#include <iostream>

#include "AST.h"
#include "Iterator.h"
#include "Types.h"

namespace mx {

class EntityProvider;
class File;
class FragmentList;
class FileFragmentListIterator;
class FileImpl;
class FileListImpl;
class Fragment;
class FragmentImpl;
class Index;
class RemoteEntityProvider;
class InvalidEntityProvider;
class SyntaxQueryMatch;
class SyntaxQueryResult;
class SyntaxQueryResultImpl;
class SyntaxQueryResultIterator;
class Token;
class TokenList;
class TokenListIterator;
class TokenRange;
class TokenReader;
class TokenSubstitution;
class TokenSubstitutionList;
class TokenSubstitutionListImpl;

using FilePathList = std::map<std::filesystem::path, FileId>;

// A single token, e.g. from a file or from a macro expansion.
class Token {
 private:
  friend class Fragment;
  friend class FragmentImpl;
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
  friend class SyntaxQueryResultIterator;
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

  // Return an iterator pointing at the first token in this list.
  inline TokenListIterator begin(void) const noexcept {
    return TokenListIterator(impl, index, num_tokens);
  }

  inline TokenListIterator::EndIteratorType end(void) const noexcept {
    return {};
  }
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

// Iterate over the fragments from a file.
class FileFragmentListIterator {
 private:
  friend class File;
  friend class FragmentList;

  std::shared_ptr<const FileImpl> impl;
  std::shared_ptr<const FragmentImpl> frag;
  unsigned index;
  unsigned num_fragments;

  bool operator==(const FileFragmentListIterator &) = delete;
  bool operator!=(const FileFragmentListIterator &) = delete;

  inline FileFragmentListIterator(std::shared_ptr<const FileImpl> impl_,
                                  unsigned index_, unsigned num_fragments_)
      : impl(std::move(impl_)),
        index(index_),
        num_fragments(num_fragments_) {
    Advance();
  }

  void Advance(void);

 public:
  using EndIteratorType = IteratorEnd;

  inline Fragment operator*(void) const noexcept;

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

  std::shared_ptr<const FileImpl> impl;
  unsigned num_fragments;

  inline FragmentList(std::shared_ptr<const FileImpl> impl_,
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

  inline FileFragmentListIterator::EndIteratorType end(void) const noexcept {
    return {};
  }
};

class FileListIterator {
 private:
  friend class FileList;

  std::shared_ptr<FileListImpl> impl;
  std::shared_ptr<const FileImpl> file;
  unsigned index;
  unsigned num_files;

  void Advance(void);

  bool operator==(const FileListIterator &) = delete;
  bool operator!=(const FileListIterator &) = delete;

  FileListIterator(std::shared_ptr<FileListImpl> impl_, unsigned index_,
               unsigned num_files_)
      : impl(std::move(impl_)),
        index(index_),
        num_files(num_files_) {
    Advance();
  }

 public:
  using EndIteratorType = IteratorEnd;

  inline File operator*(void) const noexcept;

  // Pre-increment.
  inline FileListIterator &operator++(void) noexcept {
    ++index;
    Advance();
    return *this;
  }

  // Post-increment.
  inline FileListIterator operator++(int) noexcept {
    FileListIterator ret(impl, index, num_files);
    ++index;
    Advance();
    return ret;
  }

  inline bool operator==(EndIteratorType) const noexcept {
    return index >= num_files;
  }

  inline bool operator!=(EndIteratorType) const noexcept {
    return index < num_files;
  }
};

// A range of all files.
class FileList {
 private:
  friend class File;

  std::shared_ptr<FileListImpl> impl;

  inline FileList(std::shared_ptr<FileListImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  FileListIterator begin(void) const;

  inline FileListIterator::EndIteratorType end(void) const {
    return {};
  }
};

// Represents a file. A given file may have many associated paths. We
// de-duplicate via a hash of the contents.
class File {
 private:
  using Ptr = std::shared_ptr<const FileImpl>;

  friend class EntityProvider;
  friend class Fragment;
  friend class FragmentList;
  friend class FileListIterator;
  friend class FragmentImpl;
  friend class Index;
  friend class RemoteEntityProvider;
  friend class Token;
  friend class TokenSubstitutionListIterator;

  Ptr impl;

  inline File(std::shared_ptr<const FileImpl> impl_)
      : impl(std::move(impl_)) {}

 public:

  inline static File containing(const FragmentList &fragment_list) {
    return File(fragment_list.impl);
  }

  // Return the file containing a specific fragment.
  static File containing(const Fragment &fragment);

  // Return all files in a given index.
  static FileList in(const Index &index);

  // Return the ID of this file.
  FileId id(void) const noexcept;

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

  inline TokenSubstitutionListIterator::EndIteratorType
  end(void) const noexcept {
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
  friend class RemoteEntityProvider;
  friend class Stmt;
  friend class Token;
  friend class TokenSubstitutionListIterator;
  friend class SyntaxQueryResultImpl;
  friend class SyntaxQueryResultIterator;

  std::shared_ptr<const FragmentImpl> impl;

  inline Fragment(std::shared_ptr<const FragmentImpl> impl_)
      : impl(std::move(impl_)) {}

 public:
  // Return the list of fragments in a file.
  static FragmentList in(const File &);

  // Return the fragment containing a query match.
  static Fragment containing(const SyntaxQueryMatch &);

  // Return the ID of this fragment.
  FragmentId id(void) const noexcept;

  // The smallest line of the file for which one of the tokens from this
  // fragment resides.
  unsigned first_line(void) const;

  // The largest line of the file for which one of the tokens from this
  // fragment resides.
  unsigned last_line(void) const;

  // Return the list of token substitutions.
  TokenSubstitutionList unparsed_tokens(void) const;

  // Return the list of top-level declarations in this fragment.
  std::vector<Decl> top_level_declarations(void) const;

  // Returns source IR for the fragments
  std::optional<std::string_view> source_ir(void) const noexcept;

  inline bool operator==(const Fragment &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const Fragment &that) const noexcept {
    return id() != that.id();
  }
};

// The range of tokens of a match.
class SyntaxQueryMatch : public TokenRange {
 private:
  friend class Fragment;
  friend class SyntaxQueryResult;
  friend class SyntaxQueryResultImpl;

  std::shared_ptr<const FragmentImpl> frag;
  std::unordered_map<std::string, TokenRange> var_matches;

 public:
  SyntaxQueryMatch(
      std::shared_ptr<const FragmentImpl> frag_,
      std::shared_ptr<const TokenReader> impl_,
      unsigned index_, unsigned num_tokens_,
      std::unordered_map<std::string, TokenRange> var_matches_);

  // Return the match results for a specific meta-variable.
  std::optional<TokenRange> MatchFor(const std::string &var) const;

  // Return a list of matched variables.
  std::vector<std::string> MatchedVariables(void) const;
};

class SyntaxQueryResultIterator {
 private:
  friend class SyntaxQueryResult;

  std::shared_ptr<const SyntaxQueryResultImpl> impl;
  unsigned index;
  unsigned num_fragments;
  std::optional<SyntaxQueryMatch> result;

  // Try to advance to the next result. There can be multiple results per
  // fragment.
  void Advance(void);

  inline SyntaxQueryResultIterator(
      std::shared_ptr<const SyntaxQueryResultImpl> impl_,
      unsigned index_, unsigned num_fragments_)
      : impl(std::move(impl_)),
        index(index_),
        num_fragments(num_fragments_) {
    Advance();
  }

 public:
  inline const SyntaxQueryMatch &operator*(void) const noexcept {
    return result.value();
  }

  inline const SyntaxQueryMatch *operator->(void) const noexcept {
    return std::addressof(result.value());
  }

  inline bool operator==(IteratorEnd) const noexcept {
    return index >= num_fragments;
  }

  inline bool operator!=(IteratorEnd) const noexcept {
    return index < num_fragments;
  }

  // Pre-increment.
  inline SyntaxQueryResultIterator &operator++(void) noexcept {
    Advance();
    return *this;
  }
};

class SyntaxQueryResult {
 private:

  using Ptr = std::shared_ptr<const SyntaxQueryResult>;

  friend class EntityProvider;
  friend class RemoteEntityProvider;
  friend class InvalidEntityProvider;
  friend class SyntaxQueryResultIterator;

  std::shared_ptr<const SyntaxQueryResultImpl> impl;
  unsigned num_fragments;

 public:
  SyntaxQueryResult(std::shared_ptr<const SyntaxQueryResultImpl> impl_);

  // Return an iterator pointing at the first token in this list.
  inline SyntaxQueryResultIterator begin(void) const noexcept {
    return SyntaxQueryResultIterator(impl, 0, num_fragments);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

inline Fragment FileFragmentListIterator::operator*(void) const noexcept {
  return Fragment(frag);
}

inline File FileListIterator::operator*(void) const noexcept {
  return File(file);
}

// Provides the APIs with entities.
class EntityProvider {
 public:
  using Ptr = std::shared_ptr<EntityProvider>;

  virtual ~EntityProvider(void) noexcept;

  // Returns an entity provider that gets entities from a remote host.
  static Ptr from_remote(std::string host, std::string port);

  // Returns an entity provider that gets entities from a UNIX domain socket.
  static Ptr from_socket(std::filesystem::path path);

 private:
  friend class Index;
  friend class File;
  friend class FileImpl;
  friend class FileListIterator;
  friend class FileFragmentListIterator;
  friend class FileListImpl;
  friend class Fragment;
  friend class FragmentImpl;
  friend class PackedFileImpl;
  friend class PackedFragmentImpl;
  friend class SyntaxQueryResultImpl;

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual FilePathList ListFiles(void) = 0;

  // Download a file by its unique ID.
  virtual std::shared_ptr<const FileImpl>
  FileFor(const Ptr &, FileId id) = 0;

  // Download a fragment by its unique ID.
  virtual std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, FragmentId id) = 0;

  virtual std::shared_ptr<const SyntaxQueryResultImpl>
  SyntaxQuery(const Ptr &, std::string query, bool is_cpp) = 0;
};

// Access to the indexed code.
class Index {
 private:
  friend class File;
  friend class Fragment;

  EntityProvider::Ptr impl;

 public:
  ~Index(void);
  Index(void);

  /* implicit */ inline Index(EntityProvider::Ptr impl_)
      : impl(std::move(impl_)) {}

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  FilePathList file_paths(void) const;

  // Download a file by its unique ID.
  std::optional<File> file(FileId id) const;

  // Download a fragment by its unique ID.
  std::optional<Fragment> fragment(FragmentId id) const;

  // Download a fragment based off of an entity ID.
  std::optional<Fragment> fragment_containing(EntityId) const;

  SyntaxQueryResult syntax_query(std::string query, bool is_cpp=false) const;
};

class FileManager {
 private:
  EntityProvider::Ptr ep;
};

}  // namespace mx
