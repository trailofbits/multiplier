// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MSVCMajorVersion : unsigned char {
  MSVC2010,
  MSVC2012,
  MSVC2013,
  MSVC2015,
  MSVC2017,
  MSVC20175,
  MSVC20177,
  MSVC2019,
  MSVC20195,
  MSVC20198,
};

inline static const char *EnumerationName(MSVCMajorVersion) {
  return "MSVCMajorVersion";
}

inline static constexpr unsigned NumEnumerators(MSVCMajorVersion) {
  return 10;
}

const char *EnumeratorName(MSVCMajorVersion);

} // namespace mx
