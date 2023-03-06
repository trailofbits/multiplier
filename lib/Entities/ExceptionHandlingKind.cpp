// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExceptionHandlingKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExceptionHandlingKind e) {
  switch (e) {
    case ExceptionHandlingKind::NONE: return "NONE";
    case ExceptionHandlingKind::SJ_LJ: return "SJ_LJ";
    case ExceptionHandlingKind::WIN_EH: return "WIN_EH";
    case ExceptionHandlingKind::DWARF_CFI: return "DWARF_CFI";
    case ExceptionHandlingKind::WASM: return "WASM";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
