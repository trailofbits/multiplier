// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DLLExportAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DLLExportAttrSpelling e) {
  switch (e) {
    case DLLExportAttrSpelling::DECLSPEC_DLLEXPORT: return "DECLSPEC_DLLEXPORT";
    case DLLExportAttrSpelling::GNU_DLLEXPORT: return "GNU_DLLEXPORT";
    case DLLExportAttrSpelling::CXX11_GNU_DLLEXPORT: return "CXX11_GNU_DLLEXPORT";
    case DLLExportAttrSpelling::C2X_GNU_DLLEXPORT: return "C2X_GNU_DLLEXPORT";
    case DLLExportAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
