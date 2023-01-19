// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"

#include <cctype>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Macro.h>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/AST.h>
#include <mutex>

#include "Fragment.h"
#include "Re2Impl.h"
#include "Use.h"
#include "WeggliImpl.h"

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

  const FileImpl *file_ptr = maybe_file_token.impl->OwningFile();
  if (!file_ptr) {
    return std::nullopt;
  }

  File file(std::shared_ptr<const FileImpl>(std::move(maybe_file_token.impl),
                                            file_ptr));
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

  const FileImpl *file_ptr = maybe_file_token.impl->OwningFile();
  if (!file_ptr) {
    return std::nullopt;
  }

  File file(std::shared_ptr<const FileImpl>(std::move(maybe_file_token.impl),
                                            file_ptr));
  const FileLocationVector &vec = cache.impl->Add(std::move(file));

  if ((maybe_file_token.offset + 1u) >= vec.size()) {
    return std::nullopt;
  }

  return vec[maybe_file_token.offset + 1u];
}

// Return the file containing a specific fragment.
std::optional<File> File::containing(const Fragment &fragment) {
  const auto &ep = fragment.impl->ep;
  if (auto fp = ep->FileFor(ep, fragment.impl->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing a specific token substitution.
std::optional<File> File::containing(const Designator &entity) {
  const auto &ep = entity.fragment->ep;
  if (auto fp = ep->FileFor(ep, entity.fragment->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing the fragment containing a specific entity.
std::optional<File> File::containing(const Decl &entity) {
  const auto &ep = entity.fragment->ep;
  if (auto fp = ep->FileFor(ep, entity.fragment->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing the fragment containing a specific entity.
std::optional<File> File::containing(const Stmt &entity) {
  const auto &ep = entity.fragment->ep;
  if (auto fp = ep->FileFor(ep, entity.fragment->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing the fragment containing a specific entity.
std::optional<File> File::containing(const Type &entity) {
  const auto &ep = entity.fragment->ep;
  if (auto fp = ep->FileFor(ep, entity.fragment->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing a specific fragment.
std::optional<File> File::containing(const Attr &entity) {
  const auto &ep = entity.fragment->ep;
  if (auto fp = ep->FileFor(ep, entity.fragment->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing a specific fragment.
std::optional<File> File::containing(const Macro &entity) {
  const auto &ep = entity.fragment->ep;
  if (auto fp = ep->FileFor(ep, entity.fragment->FileContaingFirstToken())) {
    return File(std::move(fp));
  }
  return std::nullopt;
}

// Return the file containing a specific token.
std::optional<File> File::containing(const Token &token) {

  if (auto file = token.impl->OwningFile()) {
    return File(FileImpl::Ptr(token.impl, file));

  } else if (auto frag = token.impl->OwningFragment()) {
    return File::containing(Fragment(FragmentImpl::Ptr(token.impl, frag)));

  } else {
    return std::nullopt;
  }
}

// Return the file containing a regex match.
std::optional<File> File::containing(const RegexQueryMatch &match) {
  if (auto file = match.impl->OwningFile()) {
    return File(FileImpl::Ptr(match.impl, file));

  } else {
    return File::containing(Fragment::containing(match));
  }
}

// Return the file containing a specific fragment.
std::optional<File> File::containing(const WeggliQueryMatch &match) {
  if (auto file = match.impl->OwningFile()) {
    return File(FileImpl::Ptr(match.impl, file));

  } else {
    return File::containing(Fragment::containing(match));
  }
}

// Return all files in a given index.
gap::generator<File> File::in(const Index &index) {
  return index.files();
}

// Return the ID of this file.
SpecificEntityId<FileId> File::id(void) const noexcept {
  return FileId{impl->file_id};
}

gap::generator<Fragment> File::fragments(void) const {
  FileId fid(impl->file_id);
  auto &ep = impl->ep;
  auto ids = ep->ListFragmentsInFile(ep, fid);
  for (auto id : ids) {
    auto frag = ep->FragmentFor(ep, id);
    if (frag) {
      co_yield frag;
    }
  }
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

gap::generator<Use<FileUseSelector>> File::uses(void) const {
  UseIteratorImpl it(impl->ep, *this);
  for (auto use : it.Enumerate<FileUseSelector>()) {
    co_yield use;
  }
}

// References of this file.
gap::generator<MacroReference> File::references(void) const {
  ReferenceIteratorImpl it(impl->ep, *this);
  for (auto ref : it.EnumerateMacros()) {
    co_yield ref;
  }
}

}  // namespace mx
