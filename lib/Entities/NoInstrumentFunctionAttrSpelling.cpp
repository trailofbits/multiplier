// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NoInstrumentFunctionAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoInstrumentFunctionAttrSpelling e) {
  switch (e) {
    case NoInstrumentFunctionAttrSpelling::GNU_NO_INSTRUMENT_FUNCTION: return "GNU_NO_INSTRUMENT_FUNCTION";
    case NoInstrumentFunctionAttrSpelling::CXX11_GNU_NO_INSTRUMENT_FUNCTION: return "CXX11_GNU_NO_INSTRUMENT_FUNCTION";
    case NoInstrumentFunctionAttrSpelling::C2X_GNU_NO_INSTRUMENT_FUNCTION: return "C2X_GNU_NO_INSTRUMENT_FUNCTION";
    case NoInstrumentFunctionAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
