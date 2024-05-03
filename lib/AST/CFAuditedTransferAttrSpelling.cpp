// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CFAuditedTransferAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFAuditedTransferAttrSpelling e) {
  switch (e) {
    case CFAuditedTransferAttrSpelling::GNU_CF_AUDITED_TRANSFER: return "GNU_CF_AUDITED_TRANSFER";
    case CFAuditedTransferAttrSpelling::CXX11_CLANG_CF_AUDITED_TRANSFER: return "CXX11_CLANG_CF_AUDITED_TRANSFER";
    case CFAuditedTransferAttrSpelling::C23_CLANG_CF_AUDITED_TRANSFER: return "C23_CLANG_CF_AUDITED_TRANSFER";
    case CFAuditedTransferAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
