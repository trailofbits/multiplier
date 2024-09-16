// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RemarkKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RemarkKind e) {
  switch (e) {
    case RemarkKind::MISSING: return "MISSING";
    case RemarkKind::ENABLED: return "ENABLED";
    case RemarkKind::ENABLED_EVERYTHING: return "ENABLED_EVERYTHING";
    case RemarkKind::DISABLED: return "DISABLED";
    case RemarkKind::DISABLED_EVERYTHING: return "DISABLED_EVERYTHING";
    case RemarkKind::WITH_PATTERN: return "WITH_PATTERN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
