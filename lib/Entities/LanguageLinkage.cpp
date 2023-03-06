// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LanguageLinkage.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LanguageLinkage e) {
  switch (e) {
    case LanguageLinkage::C_LANGUAGE_LINKAGE: return "C_LANGUAGE_LINKAGE";
    case LanguageLinkage::CXX_LANGUAGE_LINKAGE: return "CXX_LANGUAGE_LINKAGE";
    case LanguageLinkage::NO_LANGUAGE_LINKAGE: return "NO_LANGUAGE_LINKAGE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
