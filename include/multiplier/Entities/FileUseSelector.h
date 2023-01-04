// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FileUseSelector : unsigned short {
  INCLUDED_FILE,
};

inline static const char *EnumerationName(FileUseSelector) {
  return "FileUseSelector";
}

inline static constexpr unsigned NumEnumerators(FileUseSelector) {
  return 1;
}

const char *EnumeratorName(FileUseSelector);

} // namespace mx
