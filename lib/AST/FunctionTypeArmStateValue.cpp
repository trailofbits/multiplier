// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionTypeArmStateValue.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FunctionTypeArmStateValue e) {
  switch (e) {
    case FunctionTypeArmStateValue::ARM_NONE: return "ARM_NONE";
    case FunctionTypeArmStateValue::ARM_PRESERVES: return "ARM_PRESERVES";
    case FunctionTypeArmStateValue::ARM_IN: return "ARM_IN";
    case FunctionTypeArmStateValue::ARM_OUT: return "ARM_OUT";
    case FunctionTypeArmStateValue::ARM_IN_OUT: return "ARM_IN_OUT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
