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
class FragmentList;
class FileFragmentListIterator;
class FileImpl;
class FileListImpl;
class Fragment;
class FragmentImpl;
class Index;

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

  inline static File containing(const FragmentList &fragment_list);

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
