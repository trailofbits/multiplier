// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InterestingIdentifierKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(InterestingIdentifierKind e) {
  switch (e) {
    case InterestingIdentifierKind::NOT_INTERESTING: return "NOT_INTERESTING";
    case InterestingIdentifierKind::FILE: return "FILE";
    case InterestingIdentifierKind::JMP_BUF: return "JMP_BUF";
    case InterestingIdentifierKind::SIGJMP_BUF: return "SIGJMP_BUF";
    case InterestingIdentifierKind::UCONTEXT_T: return "UCONTEXT_T";
    case InterestingIdentifierKind::FLOAT_T: return "FLOAT_T";
    case InterestingIdentifierKind::DOUBLE_T: return "DOUBLE_T";
    case InterestingIdentifierKind::NUMINTERESTINGIDENTIFIERS: return "NUMINTERESTINGIDENTIFIERS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
