// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "File.h"

namespace mx {

FileListImpl::FileListImpl(EntityProvider::Ptr ep_)
    : ep(std::move(ep_)) {

  auto list = ep->ListFiles(ep);
  files.reserve(list.size());
  for (const auto &[path, fid] : list) {
    files.emplace_back(fid, FileImpl::WeakPtr());
  }
}

// Advance to the next valid file.
void FileListIterator::Advance(void) {
  for (; index < num_files; ++index) {
    auto &wf = impl->files[index].second;
    file = wf.lock();
    if (file) {
      return;
    }

    file = impl->ep->FileFor(impl->ep, impl->files[index].first);
    if (!file) {
      continue;  // Failed to get the file, skip over it.
    }

    wf = file;
    return;
  }
}

FileListIterator FileList::begin(void) && {
  auto num_files = impl->files.size();
  return FileListIterator(std::move(impl), 0, num_files);
}

FileListIterator FileList::begin(void) const & {
  return FileListIterator(impl, 0, impl->files.size());
}

}  // namespace mx
