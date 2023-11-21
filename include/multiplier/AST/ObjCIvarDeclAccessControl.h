// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCIvarDeclAccessControl : unsigned char {
  NONE,
  PRIVATE,
  PROTECTED,
  PUBLIC,
  PACKAGE,
};

inline static const char *EnumerationName(ObjCIvarDeclAccessControl) {
  return "ObjCIvarDeclAccessControl";
}

inline static constexpr unsigned NumEnumerators(ObjCIvarDeclAccessControl) {
  return 5;
}

const char *EnumeratorName(ObjCIvarDeclAccessControl);

} // namespace mx
