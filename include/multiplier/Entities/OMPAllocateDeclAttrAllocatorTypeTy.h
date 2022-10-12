// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OMPAllocateDeclAttrAllocatorTypeTy : unsigned char {
  OMP_NULL_MEMORY_ALLOC,
  OMP_DEFAULT_MEMORY_ALLOC,
  OMP_LARGE_CAP_MEMORY_ALLOC,
  OMP_CONST_MEMORY_ALLOC,
  OMP_HIGH_BW_MEMORY_ALLOC,
  OMP_LOW_LAT_MEMORY_ALLOC,
  OMPC_GROUP_MEMORY_ALLOC,
  OMPP_TEAM_MEMORY_ALLOC,
  OMP_THREAD_MEMORY_ALLOC,
  OMP_USER_DEFINED_MEMORY_ALLOC,
};

inline static const char *EnumerationName(OMPAllocateDeclAttrAllocatorTypeTy) {
  return "OMPAllocateDeclAttrAllocatorTypeTy";
}

inline static constexpr unsigned NumEnumerators(OMPAllocateDeclAttrAllocatorTypeTy) {
  return 10;
}

const char *EnumeratorName(OMPAllocateDeclAttrAllocatorTypeTy);

} // namespace mx
