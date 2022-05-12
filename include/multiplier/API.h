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

#include "AST.h"  // Auto-generated.
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
class Token;
class TokenList;
class TokenListIterator;
class TokenRange;
class TokenReader;
class TokenSubstitution;
class TokenSubstitutionList;
class TokenSubstitutionListImpl;

using FilePathList = std::map<std::filesystem::path, FileId>;

using ParentDeclIterator = ParentDeclIteratorImpl<Decl>;
using ParentStmtIterator = ParentStmtIteratorImpl<Stmt>;

template <typename T>
inline ParentDeclIteratorImpl<T> &ParentDeclIteratorImpl<T>::operator++(void) {
  impl = impl->parent_declaration();
  return *this;
}

template <typename T>
inline ParentStmtIteratorImpl<T> &ParentStmtIteratorImpl<T>::operator++(void) {
  impl = impl->parent_statement();
  return *this;
}

// A single token, e.g. from a file or from a macro expansion.
class Token {
 private:
  friend class File;
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

  // Return the version of this token from a file, if any.
  std::optional<Token> file_token(void) const;
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
  inline TokenListIterator begin(void) const noexcept {
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
  friend class RegexQueryResultIterator;
  friend class RegexQueryResultImpl;
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

  // Return the file containing a specific token.
  //
  // NOTE(pag): In the case of tokens from fragments, this returns the file
  //            containing the fragment itself.
  static std::optional<File> containing(const Token &token);

  // Return all files in a given index.
  static FileList in(const Index &index);

  // Return the ID of this file.
  FileId id(void) const noexcept;

  // Return the file tokens for the file.
  TokenList tokens(void) const noexcept;

  // Return the contents of the file as a UTF-8 string.
  std::string_view data(void) const noexcept;

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
};

// The range of tokens of a match.
class WeggliQueryMatch : public TokenRange {
 private:
  friend class Fragment;
  friend class WeggliQueryResult;
  friend class WeggliQueryResultImpl;

  // Fragment with the match
  std::shared_ptr<const FragmentImpl> frag;
  // Map variables with token range
  std::unordered_map<std::string, TokenRange> var_matches;

 public:
  WeggliQueryMatch(
      std::shared_ptr<const FragmentImpl> frag_,
      std::shared_ptr<const TokenReader> impl_,
      unsigned index_, unsigned num_tokens_,
      std::unordered_map<std::string, TokenRange> var_matches_);

  // Return the match results for a specific meta-variable.
  std::optional<TokenRange> variable_capture(const std::string &var) const;

  // Return a list of matched variables.
  std::vector<std::string> captured_variables(void) const;
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
  inline const WeggliQueryMatch &operator*(void) const noexcept {
    return result.value();
  }

  inline const WeggliQueryMatch *operator->(void) const noexcept {
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
    ++index;
    Advance();
    return *this;
  }
};

class WeggliQueryResult {
 private:

  using Ptr = std::shared_ptr<const WeggliQueryResult>;

  friend class EntityProvider;
  friend class RemoteEntityProvider;
  friend class InvalidEntityProvider;
  friend class WeggliQueryResultIterator;

  std::shared_ptr<WeggliQueryResultImpl> impl;
  unsigned num_fragments;

 public:
  WeggliQueryResult(std::shared_ptr<WeggliQueryResultImpl> impl_);

  // Return an iterator pointing at the first token in this list.
  inline WeggliQueryResultIterator begin(void) const noexcept {
    return WeggliQueryResultIterator(impl, 0, num_fragments);
  }

  inline IteratorEnd end(void) const noexcept {
    return {};
  }
};

// The range of tokens that matches a regular expression.
class RegexQueryMatch : public TokenRange {
 private:
  friend class Fragment;
  friend class File;
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

 public:
  ~RegexQueryMatch(void);

  // The actual range of matched data. This is possibly a sub-sequence of
  // `this->TokenRange::data()`.
  inline std::string_view data(void) const noexcept {
    return matched_ranges[0];
  }

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
  inline const RegexQueryMatch &operator*(void) const noexcept {
    return result.value();
  }

  inline const RegexQueryMatch *operator->(void) const noexcept {
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
    ++index;
    Advance();
    return *this;
  }
};

class RegexQueryResult {
 private:

  using Ptr = std::shared_ptr<const RegexQueryResult>;

  friend class EntityProvider;
  friend class RemoteEntityProvider;
  friend class InvalidEntityProvider;
  friend class RegexQueryResultIterator;

  std::shared_ptr<RegexQueryResultImpl> impl;
  unsigned num_fragments;

 public:
  RegexQueryResult(std::shared_ptr<RegexQueryResultImpl> impl_);

  // Return an iterator pointing at the first token in this list.
  inline RegexQueryResultIterator begin(void) const noexcept {
    return RegexQueryResultIterator(impl, 0, num_fragments);
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
  friend class Decl;
  friend class File;
  friend class FileImpl;
  friend class FileListIterator;
  friend class FileFragmentListIterator;
  friend class FileListImpl;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class PackedFileImpl;
  friend class PackedFragmentImpl;
  friend class RegexQueryResultImpl;
  friend class RegexQueryResultIterator;
  friend class RemoteEntityProvider;
  friend class WeggliQueryResultImpl;
  friend class WeggliQueryResultIterator;

 protected:

  // Clients may make requests while the indexer is still running. For many
  // things this doesn't generally matter, but for others it does. For example,
  // if the indexer is still running, the the returned file list may be
  // incomplete. Similarly, a redeclaration list may be incomplete. Caching is
  // done client side, and we coarsely communicate whether or not the entire
  // cache is out-of-date via non-decreasing version numbers returned by client-
  // to-indexer requests.
  virtual unsigned VersionNumber(void) = 0;

  // Update the version number. This is basically a signal to invalidate any
  // caches.
  virtual void VersionNumberChanged(unsigned new_version_number) = 0;

  // Cache a returned file list.
  virtual FilePathList CacheFileList(FilePathList, unsigned) = 0;

  // Cache a returned list of redeclarations.
  virtual std::vector<RawEntityId> CacheRedeclarations(
      std::vector<RawEntityId>, unsigned) = 0;

 private:

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual FilePathList ListFiles(const Ptr &) = 0;

  // Download a file by its unique ID.
  virtual std::shared_ptr<const FileImpl>
  FileFor(const Ptr &, FileId id) = 0;

  // Download a fragment by its unique ID.
  virtual std::shared_ptr<const FragmentImpl>
  FragmentFor(const Ptr &, FragmentId id) = 0;

  virtual std::shared_ptr<WeggliQueryResultImpl>
  Query(const Ptr &, const WeggliQuery &query) = 0;

  virtual std::shared_ptr<RegexQueryResultImpl>
  Query(const Ptr &, const RegexQuery &query) = 0;

  // Return the redeclarations of a given declaration.
  virtual std::vector<RawEntityId> Redeclarations(
      const Ptr &, RawEntityId eid) = 0;
};

class NotAnEntity {};

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

  // Return an entity given its ID.
  std::variant<Decl, Stmt, Type, Token, TokenSubstitution, NotAnEntity>
  entity(EntityId) const;

  // Run a Weggli search over the fragments in the index.
  //
  // NOTE(pag): This will only match inside of indexed code, i.e. fragments.
  WeggliQueryResult query_fragments(const WeggliQuery &query) const;

  // Run a regular expression search over the fragments in the index.
  //
  // NOTE(pag): This will only match inside of indexed code, i.e. fragments.
  RegexQueryResult query_fragments(const RegexQuery &query) const;
};

class FileManager {
 private:
  EntityProvider::Ptr ep;
};

}  // namespace mx
