// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LangFeatures.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LangFeatures e) {
  switch (e) {
    case LangFeatures::LINE_COMMENT: return "LINE_COMMENT";
    case LangFeatures::C99: return "C99";
    case LangFeatures::C11: return "C11";
    case LangFeatures::C17: return "C17";
    case LangFeatures::C23: return "C23";
    case LangFeatures::C_PLUS_PLUS: return "C_PLUS_PLUS";
    case LangFeatures::C_PLUS_PLUS11: return "C_PLUS_PLUS11";
    case LangFeatures::C_PLUS_PLUS14: return "C_PLUS_PLUS14";
    case LangFeatures::C_PLUS_PLUS17: return "C_PLUS_PLUS17";
    case LangFeatures::C_PLUS_PLUS20: return "C_PLUS_PLUS20";
    case LangFeatures::C_PLUS_PLUS23: return "C_PLUS_PLUS23";
    case LangFeatures::C_PLUS_PLUS26: return "C_PLUS_PLUS26";
    case LangFeatures::DIGRAPHS: return "DIGRAPHS";
    case LangFeatures::GNU_MODE: return "GNU_MODE";
    case LangFeatures::HEX_FLOAT: return "HEX_FLOAT";
    case LangFeatures::OPEN_CL: return "OPEN_CL";
    case LangFeatures::HLSL: return "HLSL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
