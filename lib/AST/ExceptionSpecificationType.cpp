// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExceptionSpecificationType.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExceptionSpecificationType e) {
  switch (e) {
    case ExceptionSpecificationType::NONE: return "NONE";
    case ExceptionSpecificationType::DYNAMIC_NONE: return "DYNAMIC_NONE";
    case ExceptionSpecificationType::DYNAMIC: return "DYNAMIC";
    case ExceptionSpecificationType::MS_ANY: return "MS_ANY";
    case ExceptionSpecificationType::NO_THROW: return "NO_THROW";
    case ExceptionSpecificationType::BASIC_NOEXCEPT: return "BASIC_NOEXCEPT";
    case ExceptionSpecificationType::DEPENDENT_NOEXCEPT: return "DEPENDENT_NOEXCEPT";
    case ExceptionSpecificationType::NOEXCEPT_FALSE: return "NOEXCEPT_FALSE";
    case ExceptionSpecificationType::NOEXCEPT_TRUE: return "NOEXCEPT_TRUE";
    case ExceptionSpecificationType::UNEVALUATED: return "UNEVALUATED";
    case ExceptionSpecificationType::UNINSTANTIATED: return "UNINSTANTIATED";
    case ExceptionSpecificationType::UNPARSED: return "UNPARSED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
