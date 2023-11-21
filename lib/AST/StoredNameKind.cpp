// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StoredNameKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StoredNameKind e) {
  switch (e) {
    case StoredNameKind::STORED_IDENTIFIER: return "STORED_IDENTIFIER";
    case StoredNameKind::STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR: return "STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR";
    case StoredNameKind::STORED_OBJ_C_ONE_ARGUMENT_SELECTOR: return "STORED_OBJ_C_ONE_ARGUMENT_SELECTOR";
    case StoredNameKind::STORED_CXX_CONSTRUCTOR_NAME: return "STORED_CXX_CONSTRUCTOR_NAME";
    case StoredNameKind::STORED_CXX_DESTRUCTOR_NAME: return "STORED_CXX_DESTRUCTOR_NAME";
    case StoredNameKind::STORED_CXX_CONVERSION_FUNCTION_NAME: return "STORED_CXX_CONVERSION_FUNCTION_NAME";
    case StoredNameKind::STORED_CXX_OPERATOR_NAME: return "STORED_CXX_OPERATOR_NAME";
    case StoredNameKind::STORED_DECLARATION_NAME_EXTRA: return "STORED_DECLARATION_NAME_EXTRA";
    case StoredNameKind::UNCOMMON_NAME_KIND_OFFSET: return "UNCOMMON_NAME_KIND_OFFSET";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
