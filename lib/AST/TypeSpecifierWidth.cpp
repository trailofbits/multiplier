// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeSpecifierWidth.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeSpecifierWidth e) {
  switch (e) {
    case TypeSpecifierWidth::UNSPECIFIED: return "UNSPECIFIED";
    case TypeSpecifierWidth::SHORT: return "SHORT";
    case TypeSpecifierWidth::LONG: return "LONG";
    case TypeSpecifierWidth::LONG_LONG: return "LONG_LONG";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
