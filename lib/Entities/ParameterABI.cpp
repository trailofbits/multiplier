// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ParameterABI.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ParameterABI e) {
  switch (e) {
    case ParameterABI::ORDINARY: return "ORDINARY";
    case ParameterABI::SWIFT_INDIRECT_RESULT: return "SWIFT_INDIRECT_RESULT";
    case ParameterABI::SWIFT_ERROR_RESULT: return "SWIFT_ERROR_RESULT";
    case ParameterABI::SWIFT_CONTEXT: return "SWIFT_CONTEXT";
    case ParameterABI::SWIFT_ASYNC_CONTEXT: return "SWIFT_ASYNC_CONTEXT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
