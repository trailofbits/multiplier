// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/SQLite.h>

#include <unordered_map>

namespace mx::sqlite {
namespace detail {
namespace {
static thread_local std::unordered_map<void *,  void (*)(void *)> *
    tDeleter = nullptr;
}  // namespace

void DeferDelete(void *ptr, void (*deleter)(void *)) {
  if (!tDeleter) {
    tDeleter = new std::unordered_map<void *, void (*)(void *)>;
  }
  tDeleter->emplace(ptr, deleter);
}

void DeferredDelete(void *ptr) {
  if (tDeleter) {
    auto deleter = (*tDeleter)[ptr];
    if (deleter) {
      deleter(ptr);
    }
    tDeleter->erase(ptr);
  }
}

}  // namespace detail
}  // namespace mx::sqlite
