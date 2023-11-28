// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CoreFoundationABI.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CoreFoundationABI e) {
  switch (e) {
    case CoreFoundationABI::UNSPECIFIED: return "UNSPECIFIED";
    case CoreFoundationABI::STANDALONE: return "STANDALONE";
    case CoreFoundationABI::OBJECTIVE_C: return "OBJECTIVE_C";
    case CoreFoundationABI::SWIFT: return "SWIFT";
    case CoreFoundationABI::SWIFT50: return "SWIFT50";
    case CoreFoundationABI::SWIFT42: return "SWIFT42";
    case CoreFoundationABI::SWIFT41: return "SWIFT41";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
