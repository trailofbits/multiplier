// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenCLAccessAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLAccessAttrSpelling e) {
  switch (e) {
    case OpenCLAccessAttrSpelling::KEYWORD_READ_ONLY: return "KEYWORD_READ_ONLY";
    case OpenCLAccessAttrSpelling::KEYWORD_WRITE_ONLY: return "KEYWORD_WRITE_ONLY";
    case OpenCLAccessAttrSpelling::KEYWORD_READ_WRITE: return "KEYWORD_READ_WRITE";
    case OpenCLAccessAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
