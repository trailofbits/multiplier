// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SubStmt.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SubStmt e) {
  switch (e) {
    case SubStmt::BODY: return "BODY";
    case SubStmt::PROMISE: return "PROMISE";
    case SubStmt::INITIALIZER_SUSPEND: return "INITIALIZER_SUSPEND";
    case SubStmt::FINAL_SUSPEND: return "FINAL_SUSPEND";
    case SubStmt::ON_EXCEPTION: return "ON_EXCEPTION";
    case SubStmt::ON_FALLTHROUGH: return "ON_FALLTHROUGH";
    case SubStmt::ALLOCATE: return "ALLOCATE";
    case SubStmt::DEALLOCATE: return "DEALLOCATE";
    case SubStmt::RESULT_DECLARATION: return "RESULT_DECLARATION";
    case SubStmt::RETURN_VALUE: return "RETURN_VALUE";
    case SubStmt::RETURN_STATEMENT: return "RETURN_STATEMENT";
    case SubStmt::RETURN_STATEMENT_ON_ALLOC_FAILURE: return "RETURN_STATEMENT_ON_ALLOC_FAILURE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
