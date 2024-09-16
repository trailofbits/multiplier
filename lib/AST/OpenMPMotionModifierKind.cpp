// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenMPMotionModifierKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPMotionModifierKind e) {
  switch (e) {
    case OpenMPMotionModifierKind::MOTIONMODIFIER_MAPPER: return "MOTIONMODIFIER_MAPPER";
    case OpenMPMotionModifierKind::MOTIONMODIFIER_PRESENT: return "MOTIONMODIFIER_PRESENT";
    case OpenMPMotionModifierKind::MOTIONMODIFIER_UNKNOWN: return "MOTIONMODIFIER_UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
