// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"

#include <algorithm>

namespace mx {

FileListImpl::FileListImpl(EntityProvider::Ptr ep_)
    : ep(std::move(ep_)) {

  auto file_paths = ep->ListFiles(ep);
  file_ids.reserve(file_paths.size());
  for (const auto &[path, file_id] : file_paths) {
    file_ids.push_back(file_id);
  }

  std::sort(file_ids.begin(), file_ids.end());
  auto it = std::unique(file_ids.begin(), file_ids.end());
  file_ids.erase(it, file_ids.end());
}

// Advance to the next valid file.
void FileListIterator::Advance(void) {
  for (; index < num_files; ++index) {
    file = impl->ep->FileFor(impl->ep, impl->file_ids[index]);
    if (file) {
      return;
    }
  }
}

FileListIterator FileList::begin(void) && {
  auto num_files = impl->file_ids.size();
  return FileListIterator(std::move(impl), 0, num_files);
}

FileListIterator FileList::begin(void) const & {
  return FileListIterator(impl, 0, impl->file_ids.size());
}

}  // namespace mx
