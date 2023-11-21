// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CFUnknownTransferAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFUnknownTransferAttrSpelling e) {
  switch (e) {
    case CFUnknownTransferAttrSpelling::GNU_CF_UNKNOWN_TRANSFER: return "GNU_CF_UNKNOWN_TRANSFER";
    case CFUnknownTransferAttrSpelling::CXX11_CLANG_CF_UNKNOWN_TRANSFER: return "CXX11_CLANG_CF_UNKNOWN_TRANSFER";
    case CFUnknownTransferAttrSpelling::C2X_CLANG_CF_UNKNOWN_TRANSFER: return "C2X_CLANG_CF_UNKNOWN_TRANSFER";
    case CFUnknownTransferAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
