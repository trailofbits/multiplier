// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SubStmt : unsigned char {
  BODY,
  PROMISE,
  INITIALIZER_SUSPEND,
  FINAL_SUSPEND,
  ON_EXCEPTION,
  ON_FALLTHROUGH,
  ALLOCATE,
  DEALLOCATE,
  RETURN_VALUE,
  RESULT_DECLARATION,
  RETURN_STATEMENT,
  RETURN_STATEMENT_ON_ALLOC_FAILURE,
};

inline static const char *EnumerationName(SubStmt) {
  return "SubStmt";
}

inline static constexpr unsigned NumEnumerators(SubStmt) {
  return 12;
}

const char *EnumeratorName(SubStmt);

} // namespace mx
