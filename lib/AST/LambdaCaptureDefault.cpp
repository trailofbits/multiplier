// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LambdaCaptureDefault.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LambdaCaptureDefault e) {
  switch (e) {
    case LambdaCaptureDefault::NONE: return "NONE";
    case LambdaCaptureDefault::BY_COPY: return "BY_COPY";
    case LambdaCaptureDefault::BY_REFERENCE: return "BY_REFERENCE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
