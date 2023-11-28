// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Kinds.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Kinds e) {
  switch (e) {
    case Kinds::L_VALUE: return "L_VALUE";
    case Kinds::X_VALUE: return "X_VALUE";
    case Kinds::FUNCTION: return "FUNCTION";
    case Kinds::VOID: return "VOID";
    case Kinds::ADDRESSABLE_VOID: return "ADDRESSABLE_VOID";
    case Kinds::DUPLICATE_VECTOR_COMPONENTS: return "DUPLICATE_VECTOR_COMPONENTS";
    case Kinds::MEMBER_FUNCTION: return "MEMBER_FUNCTION";
    case Kinds::SUB_OBJ_C_PROPERTY_SETTING: return "SUB_OBJ_C_PROPERTY_SETTING";
    case Kinds::CLASS_TEMPORARY: return "CLASS_TEMPORARY";
    case Kinds::ARRAY_TEMPORARY: return "ARRAY_TEMPORARY";
    case Kinds::OBJ_C_MESSAGE_R_VALUE: return "OBJ_C_MESSAGE_R_VALUE";
    case Kinds::PR_VALUE: return "PR_VALUE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
