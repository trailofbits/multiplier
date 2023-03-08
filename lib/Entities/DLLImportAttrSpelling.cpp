// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DLLImportAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DLLImportAttrSpelling e) {
  switch (e) {
    case DLLImportAttrSpelling::DECLSPEC_DLLIMPORT: return "DECLSPEC_DLLIMPORT";
    case DLLImportAttrSpelling::GNU_DLLIMPORT: return "GNU_DLLIMPORT";
    case DLLImportAttrSpelling::CXX11_GNU_DLLIMPORT: return "CXX11_GNU_DLLIMPORT";
    case DLLImportAttrSpelling::C2X_GNU_DLLIMPORT: return "C2X_GNU_DLLIMPORT";
    case DLLImportAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
