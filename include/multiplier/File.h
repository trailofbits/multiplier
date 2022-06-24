// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string_view>

#include "Reference.h"
#include "Token.h"

namespace mx {

class EntityProvider;
class File;
class FileImpl;
class FileListImpl;
class FileLocationCache;
class FileLocationCacheImpl;
class FileFragmentListIterator;
class Fragment;
class FragmentImpl;
class FragmentList;
class Index;
class RegexQueryMatch;
class WeggliQueryMatch;

class FileLocationConfiguration {
 public:
  // Tab width, in terms of number of spaces.
  unsigned tab_width{4};

  // Whether or not to use tab stops. This means that tabs align to the next
  // multiple of the tab width, and as a result, sometimes the effective width
  // of a tab will be less than the configured width.
  bool use_tab_stops{true};
};

// Represents a cache of files to pre-computed line/column number locations.
class FileLocationCache {
 private:
  friend class Token;

  std::shared_ptr<FileLocationCacheImpl> impl;

 public:
  ~FileLocationCache(void);

  FileLocationCache(
    const FileLocationConfiguration &config=FileLocationConfiguration());

  // Add a file to the cache.
  void add(const File &);

  // Remove a file from the cache.
  void remove(const File &);

  // Clear the cache.
  void clear(void);
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

  FileListIterator(std::shared_ptr<FileListImpl> impl_, 
                   std::shared_ptr<const FileImpl> file_,
                   unsigned index_, unsigned num_files_)
      : impl(std::move(impl_)),
        file(std::move(file_)),
        index(index_),
        num_files(num_files_) {
    Advance();
  }

 public:
  using EndIteratorType = IteratorEnd;

  inline File operator*(void) && noexcept;
  inline File operator*(void) const & noexcept;

  // Pre-increment.
  inline FileListIterator &operator++(void) noexcept {
    ++index;
    Advance();
    return *this;
  }

  // Post-increment.
  inline FileListIterator operator++(int) noexcept {
    FileListIterator ret(impl, file, index, num_files);
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
  FileListIterator begin(void) &&;
  FileListIterator begin(void) const &;

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
  friend class FileLocationCache;
  friend class FileLocationCacheImpl;
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

  // Return the file containing a regex match.
  static File containing(const RegexQueryMatch &match);

  // Return the file containing a specific fragment.
  static File containing(const WeggliQueryMatch &match);

  // Return the file containing a specific fragment.
  static File containing(const Fragment &fragment);

  // Return the file containing the fragment containing a specific entity.
  static File containing(const Decl &entity);

  // Return the file containing the fragment containing a specific entity.
  static File containing(const Stmt &entity);

  // Return the file containing the fragment containing a specific entity.
  static File containing(const Type &type);

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

inline File FileListIterator::operator*(void) && noexcept {
  return File(std::move(file));
}

inline File FileListIterator::operator*(void) const & noexcept {
  return File(file);
}

class FileManager {
 private:
  std::shared_ptr<EntityProvider> ep;
};

}  // namespace mx
