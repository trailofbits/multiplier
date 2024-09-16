// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/FileType.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FileType e) {
  switch (e) {
    case FileType::NONE: return "NONE";
    case FileType::NOT_FOUND: return "NOT_FOUND";
    case FileType::REGULAR: return "REGULAR";
    case FileType::DIRECTORY: return "DIRECTORY";
    case FileType::SYMBOLIC_LINK: return "SYMBOLIC_LINK";
    case FileType::BLOCK: return "BLOCK";
    case FileType::CHARACTER: return "CHARACTER";
    case FileType::FIRST_IN_FIRST_OUT: return "FIRST_IN_FIRST_OUT";
    case FileType::SOCKET: return "SOCKET";
    case FileType::KNKNOWN: return "KNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
