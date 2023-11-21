// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/GetBuiltinTypeError.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(GetBuiltinTypeError e) {
  switch (e) {
    case GetBuiltinTypeError::NONE: return "NONE";
    case GetBuiltinTypeError::MISSING_TYPE: return "MISSING_TYPE";
    case GetBuiltinTypeError::MISSING_STDIO: return "MISSING_STDIO";
    case GetBuiltinTypeError::MISSING: return "MISSING";
    case GetBuiltinTypeError::MISSING_UCONTEXT: return "MISSING_UCONTEXT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
