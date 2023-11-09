// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AddressSpaceAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AddressSpaceAttrSpelling e) {
  switch (e) {
    case AddressSpaceAttrSpelling::GNU_ADDRESS_SPACE: return "GNU_ADDRESS_SPACE";
    case AddressSpaceAttrSpelling::CXX11_CLANG_ADDRESS_SPACE: return "CXX11_CLANG_ADDRESS_SPACE";
    case AddressSpaceAttrSpelling::C2X_CLANG_ADDRESS_SPACE: return "C2X_CLANG_ADDRESS_SPACE";
    case AddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
