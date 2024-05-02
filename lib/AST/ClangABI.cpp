// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ClangABI.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ClangABI e) {
  switch (e) {
    case ClangABI::VER38: return "VER38";
    case ClangABI::VER4: return "VER4";
    case ClangABI::VER6: return "VER6";
    case ClangABI::VER7: return "VER7";
    case ClangABI::VER9: return "VER9";
    case ClangABI::VER11: return "VER11";
    case ClangABI::VER12: return "VER12";
    case ClangABI::VER14: return "VER14";
    case ClangABI::VER15: return "VER15";
    case ClangABI::VER17: return "VER17";
    case ClangABI::LATEST: return "LATEST";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
