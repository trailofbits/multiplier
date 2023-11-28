// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <type_traits>

#pragma GCC visibility push(hidden)
namespace mx {

enum class StmtKind : unsigned char;

template <typename ForwardIterator, typename T>
static ForwardIterator LowerBound(ForwardIterator first, ForwardIterator last,
                                  const T &val) {
  for (auto count = last - first; count > 0; ) {
    auto step = count / 2;
    ForwardIterator it = first + step;
    if (*it < val ) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

template <typename ForwardIterator, typename T>
static ForwardIterator UpperBound(ForwardIterator first, ForwardIterator last,
                                  const T &val) {
  for (auto count = last - first; count > 0; ) {
    auto step = count / 2;
    ForwardIterator it = first + step;
    if (!(val < *it)) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

// Returns `true` if it seems like we've hit something that can't possibly
// return a value. This is usually a good stopping point to say "this thing
// isn't a line of code".
bool IsNonValueStatement(StmtKind kind);

}  // namespace mx
#pragma GCC visibility pop
