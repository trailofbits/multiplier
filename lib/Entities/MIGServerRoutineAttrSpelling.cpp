// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MIGServerRoutineAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MIGServerRoutineAttrSpelling e) {
  switch (e) {
    case MIGServerRoutineAttrSpelling::GNU_MIG_SERVER_ROUTINE: return "GNU_MIG_SERVER_ROUTINE";
    case MIGServerRoutineAttrSpelling::CXX11_CLANG_MIG_SERVER_ROUTINE: return "CXX11_CLANG_MIG_SERVER_ROUTINE";
    case MIGServerRoutineAttrSpelling::C23_CLANG_MIG_SERVER_ROUTINE: return "C23_CLANG_MIG_SERVER_ROUTINE";
    case MIGServerRoutineAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
