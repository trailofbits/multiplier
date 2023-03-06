// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ModifiableType.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ModifiableType e) {
  switch (e) {
    case ModifiableType::UNTESTED: return "UNTESTED";
    case ModifiableType::MODIFIABLE: return "MODIFIABLE";
    case ModifiableType::R_VALUE: return "R_VALUE";
    case ModifiableType::FUNCTION: return "FUNCTION";
    case ModifiableType::L_VALUE_CAST: return "L_VALUE_CAST";
    case ModifiableType::NO_SETTER_PROPERTY: return "NO_SETTER_PROPERTY";
    case ModifiableType::CONST_QUALIFIED: return "CONST_QUALIFIED";
    case ModifiableType::CONST_QUALIFIED_FIELD: return "CONST_QUALIFIED_FIELD";
    case ModifiableType::CONST_ADDRESS_SPACE: return "CONST_ADDRESS_SPACE";
    case ModifiableType::ARRAY_TYPE: return "ARRAY_TYPE";
    case ModifiableType::INCOMPLETE_TYPE: return "INCOMPLETE_TYPE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
