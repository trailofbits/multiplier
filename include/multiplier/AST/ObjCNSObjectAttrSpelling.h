// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCNSObjectAttrSpelling : unsigned char {
  GNUNS_OBJECT,
  CXX11_CLANG_NS_OBJECT,
  C2X_CLANG_NS_OBJECT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCNSObjectAttrSpelling) {
  return "ObjCNSObjectAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCNSObjectAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCNSObjectAttrSpelling);

} // namespace mx
