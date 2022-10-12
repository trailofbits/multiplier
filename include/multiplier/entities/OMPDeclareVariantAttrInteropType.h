// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OMPDeclareVariantAttrInteropType : unsigned char {
  TARGET,
  TARGET_SYNC,
  TARGET_TARGET_SYNC,
};

inline static const char *EnumerationName(OMPDeclareVariantAttrInteropType) {
  return "OMPDeclareVariantAttrInteropType";
}

inline static constexpr unsigned NumEnumerators(OMPDeclareVariantAttrInteropType) {
  return 3;
}

const char *EnumeratorName(OMPDeclareVariantAttrInteropType);

} // namespace mx
