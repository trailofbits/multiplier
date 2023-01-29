// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Entities/FileUseSelector.h>
#include <string_view>
#include <gap/core/generator.hpp>

#include "Token.h"

namespace mx {

class EntityProvider;
class File;
class FileImpl;
class FileLocationCache;
class FileLocationCacheImpl;
class Fragment;
class FragmentImpl;
class Index;
class Macro;
class RegexQueryMatch;
class WeggliQueryMatch;

using FragmentIdList = std::vector<PackedFragmentId>;

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
// The purpose of the cache is to allow us to configure a specific
// interpretation of tab width, as well as tab stop behavior.
class FileLocationCache {
 private:
  friend class Token;

  std::shared_ptr<FileLocationCacheImpl> impl;

 public:
  ~FileLocationCache(void);

  FileLocationCache(
    const FileLocationConfiguration &config=FileLocationConfiguration());

  // Add a file to the cache.
  void add(const File &) const;

  // Remove a file from the cache.
  void remove(const File &) const;

  // Clear the cache.
  void clear(void);
};

// Represents a file. A given file may have many associated paths. We
// de-duplicate via a hash of the contents.
class File {
 private:
  using Ptr = std::shared_ptr<const FileImpl>;

  friend class EntityProvider;
  friend class Fragment;
  friend class FileLocationCache;
  friend class FileLocationCacheImpl;
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class Index;
  friend class RemoteEntityProvider;
  friend class RegexQuery;
  friend class RegexQueryResultIterator;
  friend class RegexQueryResultImpl;
  friend class Token;
  friend class WeggliQuery;

  Ptr impl;

  inline File(std::shared_ptr<const FileImpl> impl_)
      : impl(std::move(impl_)) {}

 public:

  // Return the file containing a regex match.
  static std::optional<File> containing(const RegexQueryMatch &match);

  // Return the file containing a specific fragment.
  static std::optional<File> containing(const WeggliQueryMatch &match);

  // Return the file containing a specific fragment.
  static std::optional<File> containing(const Fragment &fragment);

  // Return the file containing a specific designator.
  static std::optional<File> containing(const Designator &entity);

  // Return the file containing the fragment containing a specific entity.
  static std::optional<File> containing(const Decl &entity);

  // Return the file containing the fragment containing a specific entity.
  static std::optional<File> containing(const Stmt &entity);

  // Return the file containing the fragment containing a specific entity.
  static std::optional<File> containing(const Type &type);

  // Return the file containing the fragment containing a specific entity.
  static std::optional<File> containing(const Attr &type);

  // Return the file containing a specific token substitution.
  static std::optional<File> containing(const Macro &entity);

  // Return the file containing a specific token.
  //
  // NOTE(pag): In the case of tokens from fragments, this returns the file
  //            containing the fragment itself.
  static std::optional<File> containing(const Token &token);

  // Return all files in a given index.
  [[deprecated("Use Index::files() instead.")]]
  static gap::generator<File> in(const Index &index);

  // Return the entity ID of this file.
  SpecificEntityId<FileId> id(void) const noexcept;

  // Return a list of fragments in this file.
  gap::generator<Fragment> fragments(void) const;

  // Return the list of fragment ids in the file
  FragmentIdList fragment_ids(void) const;

  // Return the file tokens for the file.
  TokenRange tokens(void) const noexcept;

  // Return the contents of the file as a UTF-8 string.
  std::string_view data(void) const noexcept;

  // Uses of this file.
  gap::generator<Use<FileUseSelector>> uses(void) const;

  // References of this file.
  gap::generator<Macro> references(void) const;

  inline bool operator==(const File &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const File &that) const noexcept {
    return id() != that.id();
  }
};

class FileManager {
 private:
  std::shared_ptr<EntityProvider> ep;
};

}  // namespace mx
