// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXNewExprInitializationStyle.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CXXNewExprInitializationStyle e) {
  switch (e) {
    case CXXNewExprInitializationStyle::NO_INITIALIZER: return "NO_INITIALIZER";
    case CXXNewExprInitializationStyle::CALL_INITIALIZER: return "CALL_INITIALIZER";
    case CXXNewExprInitializationStyle::LIST_INITIALIZER: return "LIST_INITIALIZER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
