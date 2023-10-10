// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VarDeclInitializationStyle.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VarDeclInitializationStyle e) {
  switch (e) {
    case VarDeclInitializationStyle::C_INIT: return "C_INIT";
    case VarDeclInitializationStyle::CALL_INITIALIZER: return "CALL_INITIALIZER";
    case VarDeclInitializationStyle::LIST_INITIALIZER: return "LIST_INITIALIZER";
    case VarDeclInitializationStyle::PARENTHESIS_LIST_INITIALIZER: return "PARENTHESIS_LIST_INITIALIZER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
