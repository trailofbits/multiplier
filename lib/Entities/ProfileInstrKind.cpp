// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ProfileInstrKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ProfileInstrKind e) {
  switch (e) {
    case ProfileInstrKind::PROFILE_NONE: return "PROFILE_NONE";
    case ProfileInstrKind::PROFILE_CLANG_INSTR: return "PROFILE_CLANG_INSTR";
    case ProfileInstrKind::PROFILE_IR_INSTR: return "PROFILE_IR_INSTR";
    case ProfileInstrKind::PROFILE_CSIR_INSTR: return "PROFILE_CSIR_INSTR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
