// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FunctionTypeAArch64SMETypeAttributes : unsigned char {
  SME_NORMAL_FUNCTION,
  SMEP_STATE_SM_ENABLED_MASK,
  SMEP_STATE_SM_COMPATIBLE_MASK,
  SMEP_STATE_ZA_SHARED_MASK,
  SMEP_STATE_ZA_PRESERVED_MASK,
  SME_ATTRIBUTE_MASK,
};

inline static const char *EnumerationName(FunctionTypeAArch64SMETypeAttributes) {
  return "FunctionTypeAArch64SMETypeAttributes";
}

inline static constexpr unsigned NumEnumerators(FunctionTypeAArch64SMETypeAttributes) {
  return 6;
}

const char *EnumeratorName(FunctionTypeAArch64SMETypeAttributes);

} // namespace mx
