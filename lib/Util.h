// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <type_traits>

namespace mx {

template <typename ForwardIterator, typename T>
ForwardIterator LowerBound(ForwardIterator first, ForwardIterator last,
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
ForwardIterator UpperBound(ForwardIterator first, ForwardIterator last,
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

}  // namespace mx
