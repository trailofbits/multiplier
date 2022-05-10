// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"
#include "Fragment.h"

namespace mx {

FileImpl::~FileImpl(void) noexcept {}

// Return the file containing a specific fragment.
File File::containing(const Fragment &fragment) {
  auto &fp = fragment.impl->containing_file;
  if (fp) {
    return File(fp);
  }

  const auto frag_id = fragment.impl->id;
  const auto &ep = fragment.impl->ep;
  fp = ep->FileFor(ep, fragment.impl->FileContaingFirstToken());

  // Save the file <-> fragment mapping.
  for (auto &[file_frag_id, frag_wp] : fp->fragments) {
    if (frag_id == file_frag_id) {
      frag_wp = fragment.impl;
      break;
    }
  }

  return fp;
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

// Return all files in a given index.
FileList File::in(const Index &index) {
  return FileList(std::make_shared<FileListImpl>(index.impl));
}

// Return the ID of this file.
FileId File::id(void) const noexcept {
  return impl->id;
}

// Return the file tokens for the file.
TokenList File::tokens(void) const noexcept {
  auto tokens = impl->TokenReader(impl);
  auto num_tokens = tokens->NumTokens();
  return TokenList(std::move(tokens), num_tokens);
}

// Return the contents of the file as a UTF-8 string.
std::string_view File::data(void) const noexcept {
  return impl->Data();
}

// Advance to the next valid fragment.
void FileFragmentListIterator::Advance(void) {
  for (; index < num_fragments; ++index) {
    auto &wf = impl->fragments[index].second;
    frag = wf.lock();
    if (frag) {
      frag->containing_file = impl;
      return;
    }

    frag = impl->ep->FragmentFor(impl->ep, impl->fragments[index].first);
    if (!frag) {
      continue;  // Failed to get the fragment, skip over it.
    }

    wf = frag;
    frag->containing_file = impl;  // Save the file <-> fragment mapping.
    return;
  }
}

}  // namespace mx
