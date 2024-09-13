// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DefaultVisiblityExportMapping.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DefaultVisiblityExportMapping e) {
  switch (e) {
    case DefaultVisiblityExportMapping::NONE: return "NONE";
    case DefaultVisiblityExportMapping::EXPLICIT: return "EXPLICIT";
    case DefaultVisiblityExportMapping::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
