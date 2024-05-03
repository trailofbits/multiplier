// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CFAuditedTransferAttrSpelling : unsigned char {
  GNU_CF_AUDITED_TRANSFER,
  CXX11_CLANG_CF_AUDITED_TRANSFER,
  C23_CLANG_CF_AUDITED_TRANSFER,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CFAuditedTransferAttrSpelling) {
  return "CFAuditedTransferAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CFAuditedTransferAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(CFAuditedTransferAttrSpelling);

} // namespace mx
