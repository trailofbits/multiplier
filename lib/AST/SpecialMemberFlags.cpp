// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SpecialMemberFlags.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SpecialMemberFlags e) {
  switch (e) {
    case SpecialMemberFlags::DEFAULT_CONSTRUCTOR: return "DEFAULT_CONSTRUCTOR";
    case SpecialMemberFlags::COPY_CONSTRUCTOR: return "COPY_CONSTRUCTOR";
    case SpecialMemberFlags::MOVE_CONSTRUCTOR: return "MOVE_CONSTRUCTOR";
    case SpecialMemberFlags::COPY_ASSIGNMENT: return "COPY_ASSIGNMENT";
    case SpecialMemberFlags::MOVE_ASSIGNMENT: return "MOVE_ASSIGNMENT";
    case SpecialMemberFlags::DESTRUCTOR: return "DESTRUCTOR";
    case SpecialMemberFlags::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
