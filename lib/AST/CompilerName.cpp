// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CompilerName.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CompilerName e) {
  switch (e) {
    case CompilerName::UNKNOWN: return "UNKNOWN";
    case CompilerName::CLANG: return "CLANG";
    case CompilerName::APPLE_CLANG: return "APPLE_CLANG";
    case CompilerName::CLANG_CL: return "CLANG_CL";
    case CompilerName::CL: return "CL";
    case CompilerName::GNU: return "GNU";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
