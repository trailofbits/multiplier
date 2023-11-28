// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PragmaMSCommentKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PragmaMSCommentKind e) {
  switch (e) {
    case PragmaMSCommentKind::UNKNOWN: return "UNKNOWN";
    case PragmaMSCommentKind::LINKER: return "LINKER";
    case PragmaMSCommentKind::LIB: return "LIB";
    case PragmaMSCommentKind::COMPILER: return "COMPILER";
    case PragmaMSCommentKind::EXE_STRING: return "EXE_STRING";
    case PragmaMSCommentKind::USER: return "USER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
