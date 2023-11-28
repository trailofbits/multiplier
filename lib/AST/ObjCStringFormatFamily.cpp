// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCStringFormatFamily.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ObjCStringFormatFamily e) {
  switch (e) {
    case ObjCStringFormatFamily::NONE: return "NONE";
    case ObjCStringFormatFamily::NS_STRING: return "NS_STRING";
    case ObjCStringFormatFamily::CF_STRING: return "CF_STRING";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
