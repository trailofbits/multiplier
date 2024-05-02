// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AVRSignalAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AVRSignalAttrSpelling e) {
  switch (e) {
    case AVRSignalAttrSpelling::GNU_SIGNAL: return "GNU_SIGNAL";
    case AVRSignalAttrSpelling::CXX11_GNU_SIGNAL: return "CXX11_GNU_SIGNAL";
    case AVRSignalAttrSpelling::C23_GNU_SIGNAL: return "C23_GNU_SIGNAL";
    case AVRSignalAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
