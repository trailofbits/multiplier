// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <gap/coro/generator.hpp>
#include <memory>
#include <string_view>

#include "../Entity.h"

#include "Token.h"

namespace mx {
namespace ir {
class Operation;
}  // namespace ir

class EntityProvider;
class FileLocationCache;
class FileLocationCacheImpl;
class Index;
class Reference;
class RegexQueryMatch;
class TokenRange;
class TokenTree;

#define MX_FORWARD_DECLARE(ns_path, type_name, ln, e, c) \
    class type_name; \
    class type_name ## Impl;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_FORWARD_DECLARE,
                              MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE

using FragmentIdList = std::vector<PackedFragmentId>;

class MX_EXPORT FileLocationConfiguration {
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
class MX_EXPORT FileLocationCache {
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
class MX_EXPORT File {
 private:
  friend class CompilationImpl;
  friend class EntityProvider;
  friend class FileLocationCache;
  friend class FileLocationCacheImpl;
  friend class FragmentImpl;
  friend class IncludeLikeMacroDirective;
  friend class Index;
  friend class RemoteEntityProvider;
  friend class RegexQuery;
  friend class RegexQueryResultIterator;
  friend class RegexQueryResultImpl;
  friend class TokenRange;
  friend class TokenTree;
  friend class TokenTreeImpl;

#define MX_FRIEND(ns_path, type_name, ln, e, c) \
    friend class ns_path type_name;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND,
                              MX_FRIEND)
#undef MX_FRIEND

  FileImplPtr impl;

 public:

  /* implicit */ inline File(FileImplPtr impl_)
      : impl(std::move(impl_)) {}

  // Return the file containing a regex query match.
  static std::optional<File> containing(const RegexQueryMatch &match) noexcept;

  inline static File containing(const File &file) noexcept {
    return file;
  }

#define MX_DECLARE_CONTAINING(ns_path, type_name, lower_name, enum_name, category) \
    static std::optional<File> containing( \
        const ns_path type_name &entity) noexcept;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_CONTAINING,
                              MX_DECLARE_CONTAINING,
                              MX_DECLARE_CONTAINING,
                              MX_IGNORE_ENTITY_CATEGORY,
                              MX_DECLARE_CONTAINING)
#undef MX_DECLARE_CONTAINING

  // Return the file containing a specific token.
  //
  // NOTE(pag): In the case of tokens from fragments, this returns the file
  //            containing the fragment itself. That might be very different
  //            than the file from which the token came. For that, once should
  //            use `File::containing` on the result of `Token::file_token`.
  static std::optional<File> containing(const Token &token) noexcept;

  // Go through the tokens of the iterator and return the first file found.
  static std::optional<File> containing(const TokenRange &tokens) noexcept;

  // Return the file containing the token tree. Token trees can cover multiple
  // files, e.g. in the case of x-macro like includes (e.g. within an `enum`
  // declaration). This will return the "top" file.
  static std::optional<File> containing(const TokenTree &tokens) noexcept;

  // Return the file holding a generic entity.
  static std::optional<File> containing(const VariantEntity &) noexcept;

  // Try to convert a variant entity into a file.
  static std::optional<File> from(const VariantEntity &) noexcept;

  inline static constexpr EntityCategory entity_category(void) {
    return EntityCategory::FILE;
  }

  // Generate all files in the index.
  static gap::generator<File> in(const Index &index);

  // Return the entity ID of this file.
  PackedFileId id(void) const noexcept;

  // Return a list of fragments in this file.
  gap::generator<Fragment> fragments(void) const &;

  // Return all file paths associated with this file.
  gap::generator<std::filesystem::path> paths(void) const &;

  // Return the list of fragment ids in the file
  FragmentIdList fragment_ids(void) const;

  // Return the file tokens for the file.
  TokenRange tokens(void) const noexcept;

  // Return the contents of the file as a UTF-8 string.
  std::string_view data(void) const noexcept;

  inline bool operator==(const File &that) const noexcept {
    return id() == that.id();
  }

  inline bool operator!=(const File &that) const noexcept {
    return id() != that.id();
  }
};

}  // namespace mx
