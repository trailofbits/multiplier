// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"

#include <cctype>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Designator.h>
#include <multiplier/AST/Type.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/Query.h>
#include <multiplier/IR/Operation.h>
#include <mutex>

#include "Attr.h"
#include "Decl.h"
#include "Fragment.h"
#include "Macro.h"
#include "Pseudo.h"
#include "Reference.h"
#include "Re2Impl.h"
#include "Stmt.h"
#include "Type.h"

namespace mx {

FileLocationCache::~FileLocationCache(void) {}

FileLocationCache::FileLocationCache(const FileLocationConfiguration &config)
    : impl(std::make_shared<FileLocationCacheImpl>(config)) {}

// Add a file to the cache.
const FileLocationVector &FileLocationCacheImpl::Add(File file) {
  std::unique_lock<std::mutex> locker(lock);

  FileLocationVector &vec = cache[file.impl->file_id];
  if (!vec.empty()) {
    return vec;
  }

  auto tokens = file.tokens();
  vec.reserve(tokens.size() + 1u);

  auto curr_line = 1u;
  auto curr_col = 1u;
  const auto tab_width = config.tab_width;
  const auto use_tab_stops = config.use_tab_stops;

  for (const Token &token : tokens) {
    vec.emplace_back(curr_line, curr_col);

    auto data = token.data();
    for (size_t i = 0u, max_i = data.size(); i < max_i; ++i) {
      const int ch = static_cast<signed char>(data[i]);
      if (ch == '\n') {
        curr_col = 1u;
        ++curr_line;

      // Carriage return.
      } else if (ch == '\r') {

      } else if (ch == '\t') {
        
        if (use_tab_stops) {
          if (1u < tab_width) {
            curr_col += (tab_width + 1u);
            curr_col = (curr_col / tab_width) * tab_width;

          } else {
            curr_col += tab_width; 
          }
        } else {
          curr_col += tab_width;
        }


      } else if (ch == ' ') {
        ++curr_col;

      // Four byte UTF-8.
      } else if (-1 == (ch >> 4)) {
        ++curr_col;
        i += 3;

      // Three byte UTF-8.
      } else if (-1 == (ch >> 3)) {
        ++curr_col;
        i += 2;

      // Two byte UTF-8.
      } else if (-1 == (ch >> 2)) {
        ++curr_col;
        i += 1;

      // Maybe ascii.
      } else {
        if (std::isgraph(ch)) {
          ++curr_col;
        }
      }
    }
  }

  vec.emplace_back(curr_line, curr_col);

  return vec;
}

// Add a file to the cache.
void FileLocationCache::add(const File &file) const {
  impl->Add(file);
}

// Remove a file from the cache.
void FileLocationCache::remove(const File &file) const {
  impl->cache.erase(file.impl->file_id);
}

// Clear the cache.
void FileLocationCache::clear(void) {
  impl->cache.clear();
}

// Return the line and column number for this token, if any.
std::optional<std::pair<unsigned, unsigned>> Token::location(
    const FileLocationCache &cache) const {

  Token maybe_file_token = file_token();
  if (!maybe_file_token) {
    return std::nullopt;
  }

  const FileImpl *file_ptr = maybe_file_token.impl->NthOwningFile(
      maybe_file_token.offset);
  if (!file_ptr) {
    return std::nullopt;
  }

  File file(FileImplPtr(std::move(maybe_file_token.impl), file_ptr));
  const FileLocationVector &vec = cache.impl->Add(std::move(file));

  if (maybe_file_token.offset >= vec.size()) {
    return std::nullopt;
  }

  return vec[maybe_file_token.offset];
}

// Return the line and column number for this token, if any.
std::optional<std::pair<unsigned, unsigned>> Token::next_location(
    const FileLocationCache &cache) const {

  Token maybe_file_token = file_token();
  if (!maybe_file_token) {
    return std::nullopt;
  }

  const FileImpl *file_ptr = maybe_file_token.impl->NthOwningFile(
      maybe_file_token.offset);
  if (!file_ptr) {
    return std::nullopt;
  }

  File file(FileImplPtr(std::move(maybe_file_token.impl), file_ptr));
  const FileLocationVector &vec = cache.impl->Add(std::move(file));

  if ((maybe_file_token.offset + 1u) >= vec.size()) {
    return std::nullopt;
  }

  return vec[maybe_file_token.offset + 1u];
}

// Return the file containing a specific fragment.
std::optional<File> File::containing(const Fragment &fragment) noexcept {
  const auto &ep = fragment.impl->ep;
  RawEntityId ftid = fragment.impl->FileContaingFirstToken();
  if (FileImplPtr fp = ep->FileFor(ep, ftid)) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing a specific token.
std::optional<File> File::containing(const Token &token) noexcept {

  if (auto file = token.impl->NthOwningFile(token.offset)) {
    return File(FileImplPtr(token.impl, file));

  } else if (auto frag = token.impl->NthOwningFragment(token.offset)) {
    return File::containing(Fragment(FragmentImplPtr(token.impl, frag)));

  } else {
    return std::nullopt;
  }
}

// Go through the tokens of the iterator and return the first file found.
std::optional<File> File::containing(const TokenRange &tokens) noexcept {
  for (Token tok : tokens.file_tokens()) {
    if (auto file = File::containing(tok)) {
      return file;
    }
  }
  for (Token tok : tokens) {
    if (auto file = File::containing(tok)) {
      return file;
    }
  }
  return std::nullopt;
}

// Return the file containing a regex match.
std::optional<File> File::containing(const RegexQueryMatch &match) noexcept {
  if (auto file = match.impl->OwningFile()) {
    return File(FileImplPtr(match.impl, file));

  } else {
    return File::containing(Fragment::containing(match));
  }
}

#define MX_DEFINE_CONTAINING(ns_path, type_name, lower_name, enum_name, category) \
    std::optional<File> File::containing(const type_name &entity) noexcept { \
      auto &ep = entity.impl->ep; \
      RawEntityId fid = entity.impl->fragment_id.Pack(); \
      if (FragmentImplPtr fptr = ep->FragmentFor(ep, fid)) { \
        RawEntityId ftid = fptr->FileContaingFirstToken(); \
        if (ftid == kInvalidEntityId) { \
          return std::nullopt; \
        } \
        if (FileImplPtr fp = ep->FileFor(ep, ftid)) { \
          return File(std::move(fp)); \
        } \
      } \
      assert(false); \
      return std::nullopt; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DEFINE_CONTAINING,
                            MX_DEFINE_CONTAINING,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DEFINE_CONTAINING

// Return the file containing an operation.
std::optional<File> File::containing(const ir::Operation &op) noexcept {
  if (auto decl = Decl::from(op)) {
    return File::containing(decl.value());
  } else if (auto stmt = Stmt::from(op)) {
    return File::containing(stmt.value());
  } else {
    return std::nullopt;
  }
}

std::optional<File> File::containing(const VariantEntity &entity) noexcept {
#define GET_FILE(ns_path, type_name, lower_name, enum_name, category) \
    if (auto lower_name ## _ptr = std::get_if<ns_path type_name>(&entity)) { \
      return File::containing(*lower_name ## _ptr); \
    }

  MX_FOR_EACH_ENTITY_CATEGORY(GET_FILE, GET_FILE, MX_IGNORE_ENTITY_CATEGORY,
                              GET_FILE, GET_FILE, GET_FILE,
                              MX_IGNORE_ENTITY_CATEGORY, GET_FILE)
  return std::nullopt;
#undef GET_FILE
}

// Return the file containing the token tree.
std::optional<File> File::containing(const TokenTree &tree) noexcept {
  if (tree.impl->file) {
    return File(tree.impl->file);
  } else if (tree.impl->fragment) {
    return File::containing(Fragment(tree.impl->fragment));
  } else {
    return std::nullopt;
  }
}

// Try to convert a variant entity into a file.
std::optional<File> File::from(const VariantEntity &entity) noexcept {
  if (std::holds_alternative<File>(entity)) {
    return std::get<File>(entity);
  }
  return std::nullopt;
}

// Return the ID of this file.
SpecificEntityId<FileId> File::id(void) const noexcept {
  return FileId{impl->file_id};
}

// Generate all files in the index.
gap::generator<File> File::in(const Index &index_) {
  Index index = index_;
  for (auto file : index.files()) {
    co_yield std::move(file);
  }
}

gap::generator<Fragment> File::fragments(void) const & {
  FileId fid(impl->file_id);
  EntityProviderPtr ep = impl->ep;
  auto ids = ep->ListFragmentsInFile(ep, fid);
  for (PackedFragmentId id : ids) {
    if (FragmentImplPtr frag = ep->FragmentFor(ep, id.Pack())) {
      co_yield Fragment(std::move(frag));
    } else {
      assert(false);
    }
  }
}

// Return all file paths associated with this file.
gap::generator<std::filesystem::path> File::paths(void) const & {
  return impl->ep->ListPathsForFile(impl->ep, FileId(impl->file_id));
}

FragmentIdList File::fragment_ids(void) const {
  FileId fid(impl->file_id);
  return impl->ep->ListFragmentsInFile(impl->ep, fid);
}

// Return the file tokens for the file.
TokenRange File::tokens(void) const noexcept {
  return TokenRange(impl->TokenReader(impl), 0u, impl->num_tokens);
}

// Return the contents of the file as a UTF-8 string.
std::string_view File::data(void) const noexcept {
  return impl->Data();
}

}  // namespace mx
