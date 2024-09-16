// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AssumeAlignedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AssumeAlignedAttrSpelling e) {
  switch (e) {
    case AssumeAlignedAttrSpelling::GNU_ASSUME_ALIGNED: return "GNU_ASSUME_ALIGNED";
    case AssumeAlignedAttrSpelling::CXX11_GNU_ASSUME_ALIGNED: return "CXX11_GNU_ASSUME_ALIGNED";
    case AssumeAlignedAttrSpelling::C23_GNU_ASSUME_ALIGNED: return "C23_GNU_ASSUME_ALIGNED";
    case AssumeAlignedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
