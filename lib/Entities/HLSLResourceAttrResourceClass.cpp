// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLResourceAttrResourceClass.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(HLSLResourceAttrResourceClass e) {
  switch (e) {
    case HLSLResourceAttrResourceClass::SRV: return "SRV";
    case HLSLResourceAttrResourceClass::UAV: return "UAV";
    case HLSLResourceAttrResourceClass::C_BUFFER: return "C_BUFFER";
    case HLSLResourceAttrResourceClass::SAMPLER: return "SAMPLER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
