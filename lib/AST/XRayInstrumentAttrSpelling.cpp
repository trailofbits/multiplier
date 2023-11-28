// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/XRayInstrumentAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(XRayInstrumentAttrSpelling e) {
  switch (e) {
    case XRayInstrumentAttrSpelling::GNU_XRAY_ALWAYS_INSTRUMENT: return "GNU_XRAY_ALWAYS_INSTRUMENT";
    case XRayInstrumentAttrSpelling::CXX11_CLANG_XRAY_ALWAYS_INSTRUMENT: return "CXX11_CLANG_XRAY_ALWAYS_INSTRUMENT";
    case XRayInstrumentAttrSpelling::C2X_CLANG_XRAY_ALWAYS_INSTRUMENT: return "C2X_CLANG_XRAY_ALWAYS_INSTRUMENT";
    case XRayInstrumentAttrSpelling::GNU_XRAY_NEVER_INSTRUMENT: return "GNU_XRAY_NEVER_INSTRUMENT";
    case XRayInstrumentAttrSpelling::CXX11_CLANG_XRAY_NEVER_INSTRUMENT: return "CXX11_CLANG_XRAY_NEVER_INSTRUMENT";
    case XRayInstrumentAttrSpelling::C2X_CLANG_XRAY_NEVER_INSTRUMENT: return "C2X_CLANG_XRAY_NEVER_INSTRUMENT";
    case XRayInstrumentAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
