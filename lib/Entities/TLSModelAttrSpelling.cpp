// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TLSModelAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TLSModelAttrSpelling e) {
  switch (e) {
    case TLSModelAttrSpelling::GNU_TLS_MODEL: return "GNU_TLS_MODEL";
    case TLSModelAttrSpelling::CXX11_GNU_TLS_MODEL: return "CXX11_GNU_TLS_MODEL";
    case TLSModelAttrSpelling::C2X_GNU_TLS_MODEL: return "C2X_GNU_TLS_MODEL";
    case TLSModelAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
