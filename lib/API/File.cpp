// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"

#include <cctype>
#include <multiplier/Entities/Designator.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Macro.h>

#include "Fragment.h"
#include "Re2.h"
#include "Weggli.h"

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

  std::optional<Token> maybe_file_token = file_token();
  if (!maybe_file_token) {
    return std::nullopt;
  }

  const PackedFileImpl *file_ptr = dynamic_cast<const PackedFileImpl *>(
      maybe_file_token->impl.get());
  if (!file_ptr) {
    return std::nullopt;
  }

  File file(std::shared_ptr<const FileImpl>(std::move(maybe_file_token->impl),
                                            file_ptr));
  const FileLocationVector &vec = cache.impl->Add(std::move(file));

  if (maybe_file_token->offset >= vec.size()) {
    return std::nullopt;
  }

  return vec[maybe_file_token->offset];
}

// Return the line and column number for this token, if any.
std::optional<std::pair<unsigned, unsigned>> Token::next_location(
    const FileLocationCache &cache) const {

  std::optional<Token> maybe_file_token = file_token();
  if (!maybe_file_token) {
    return std::nullopt;
  }

  const PackedFileImpl *file_ptr = dynamic_cast<const PackedFileImpl *>(
      maybe_file_token->impl.get());
  if (!file_ptr) {
    return std::nullopt;
  }

  File file(std::shared_ptr<const FileImpl>(std::move(maybe_file_token->impl),
                                            file_ptr));
  const FileLocationVector &vec = cache.impl->Add(std::move(file));

  if ((maybe_file_token->offset + 1u) >= vec.size()) {
    return std::nullopt;
  }

  return vec[maybe_file_token->offset + 1u];
}

FileImpl::~FileImpl(void) noexcept {}

// Return the file containing a specific fragment.
File File::containing(const Fragment &fragment) {
  const auto &ep = fragment.impl->ep;
  return File(ep->FileFor(ep, fragment.impl->FileContaingFirstToken()));
}

// Return the file containing a specific fragment.
File File::containing(const MacroSubstitution &entity) {
  const auto &ep = entity.impl->ep;
  return File(ep->FileFor(ep, entity.impl->FileContaingFirstToken()));
}

// Return the file containing a specific token substitution.
File File::containing(const Designator &entity) {
  const auto &ep = entity.fragment->ep;
  return File(ep->FileFor(ep, entity.fragment->FileContaingFirstToken()));
}

// Return the file containing the fragment containing a specific entity.
File File::containing(const Decl &entity) {
  const auto &ep = entity.fragment->ep;
  return File(ep->FileFor(ep, entity.fragment->FileContaingFirstToken()));
}

// Return the file containing the fragment containing a specific entity.
File File::containing(const Stmt &entity) {
  const auto &ep = entity.fragment->ep;
  return File(ep->FileFor(ep, entity.fragment->FileContaingFirstToken()));
}

// Return the file containing the fragment containing a specific entity.
File File::containing(const Type &entity) {
  const auto &ep = entity.fragment->ep;
  return File(ep->FileFor(ep, entity.fragment->FileContaingFirstToken()));
}

// Return the file containing a specific token.
std::optional<File> File::containing(const Token &token) {
  if (auto file = dynamic_cast<const PackedFileImpl *>(token.impl.get())) {
    return File(FileImpl::Ptr(token.impl, file));

  } else if (auto frag = dynamic_cast<const PackedFragmentImpl *>(token.impl.get())) {
    return File::containing(Fragment(FragmentImpl::Ptr(token.impl, frag)));

  } else {
    return std::nullopt;
  }
}

// Return the file containing a regex match.
File File::containing(const RegexQueryMatch &match) {
  if (auto file = dynamic_cast<const PackedFileImpl *>(match.impl.get())) {
    return File(FileImpl::Ptr(match.impl, file));

  } else {
    return File::containing(Fragment::containing(match));
  }
}

// Return the file containing a specific fragment.
File File::containing(const WeggliQueryMatch &match) {
  if (auto file = dynamic_cast<const PackedFileImpl *>(match.impl.get())) {
    return File(FileImpl::Ptr(match.impl, file));

  } else {
    return File::containing(Fragment::containing(match));
  }
}

// Return all files in a given index.
gap::generator<File> File::in(const Index &index) {
  std::vector<RawEntityId> file_ids;
  auto file_paths = index.impl->ListFiles(index.impl);
  file_ids.reserve(file_paths.size());
  for (const auto &[path, file_id] : file_paths) {
    file_ids.emplace_back(file_id);
  }

  std::sort(file_ids.begin(), file_ids.end());
  auto it = std::unique(file_ids.begin(), file_ids.end());
  file_ids.erase(it, file_ids.end());

  for (size_t i = 0; i < file_ids.size(); ++i) {
    VariantId vid = EntityId(file_ids[i]).Unpack();
    if (std::holds_alternative<FileId>(vid)) {
      auto file = index.impl->FileFor(index.impl, std::get<FileId>(vid).file_id);
      if (file) {
        co_yield file;
      }
    }
  }
}

// Return the ID of this file.
EntityId File::id(void) const noexcept {
  return EntityId(FileId{impl->file_id});
}

std::vector<EntityId> File::fragment_ids(void) const {
  auto fragment_ids = impl->ep->ListFragmentsInFile(impl->ep, impl->file_id);
  for (auto &fragment_id : fragment_ids) {
    fragment_id = EntityId(FragmentId(fragment_id));
  }
  return fragment_ids;
}

// Return the file tokens for the file.
TokenList File::tokens(void) const noexcept {
  return TokenList(impl->TokenReader(impl), impl->num_tokens);
}

// Return the contents of the file as a UTF-8 string.
std::string_view File::data(void) const noexcept {
  return impl->Data();
}

}  // namespace mx
