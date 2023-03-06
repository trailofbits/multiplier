// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DefaultCallingConvention.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DefaultCallingConvention e) {
  switch (e) {
    case DefaultCallingConvention::NONE: return "NONE";
    case DefaultCallingConvention::C_DECL: return "C_DECL";
    case DefaultCallingConvention::FAST_CALL: return "FAST_CALL";
    case DefaultCallingConvention::STD_CALL: return "STD_CALL";
    case DefaultCallingConvention::VECTOR_CALL: return "VECTOR_CALL";
    case DefaultCallingConvention::REG_CALL: return "REG_CALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
