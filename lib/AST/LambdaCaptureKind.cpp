// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LambdaCaptureKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LambdaCaptureKind e) {
  switch (e) {
    case LambdaCaptureKind::THIS: return "THIS";
    case LambdaCaptureKind::STAR_THIS: return "STAR_THIS";
    case LambdaCaptureKind::BY_COPY: return "BY_COPY";
    case LambdaCaptureKind::BY_REFERENCE: return "BY_REFERENCE";
    case LambdaCaptureKind::VLA_TYPE: return "VLA_TYPE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
