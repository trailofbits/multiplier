// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TextDiagnosticFormat.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TextDiagnosticFormat e) {
  switch (e) {
    case TextDiagnosticFormat::CLANG: return "CLANG";
    case TextDiagnosticFormat::MSVC: return "MSVC";
    case TextDiagnosticFormat::VI: return "VI";
    case TextDiagnosticFormat::SARIF: return "SARIF";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
