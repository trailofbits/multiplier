// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenMPDeviceType.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenMPDeviceType e) {
  switch (e) {
    case OpenMPDeviceType::HOST: return "HOST";
    case OpenMPDeviceType::NOHOST: return "NOHOST";
    case OpenMPDeviceType::ANY: return "ANY";
    case OpenMPDeviceType::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
