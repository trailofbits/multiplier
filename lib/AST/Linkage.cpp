// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Linkage.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Linkage e) {
  switch (e) {
    case Linkage::INVALID: return "INVALID";
    case Linkage::NONE: return "NONE";
    case Linkage::INTERNAL: return "INTERNAL";
    case Linkage::UNIQUE_EXTERNAL: return "UNIQUE_EXTERNAL";
    case Linkage::VISIBLE_NONE: return "VISIBLE_NONE";
    case Linkage::MODULE: return "MODULE";
    case Linkage::EXTERNAL: return "EXTERNAL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
