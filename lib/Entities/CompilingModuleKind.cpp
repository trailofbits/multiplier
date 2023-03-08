// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CompilingModuleKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CompilingModuleKind e) {
  switch (e) {
    case CompilingModuleKind::NONE: return "NONE";
    case CompilingModuleKind::MODULE_MAP: return "MODULE_MAP";
    case CompilingModuleKind::HEADER_MODULE: return "HEADER_MODULE";
    case CompilingModuleKind::HEADER_UNIT: return "HEADER_UNIT";
    case CompilingModuleKind::MODULE_INTERFACE: return "MODULE_INTERFACE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
