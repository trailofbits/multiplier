// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPAllocateDeclAttrAllocatorTypeTy.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OMPAllocateDeclAttrAllocatorTypeTy e) {
  switch (e) {
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_NULL_MEMORY_ALLOC: return "OMP_NULL_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_DEFAULT_MEMORY_ALLOC: return "OMP_DEFAULT_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_LARGE_CAP_MEMORY_ALLOC: return "OMP_LARGE_CAP_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_CONST_MEMORY_ALLOC: return "OMP_CONST_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_HIGH_BW_MEMORY_ALLOC: return "OMP_HIGH_BW_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_LOW_LAT_MEMORY_ALLOC: return "OMP_LOW_LAT_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMPC_GROUP_MEMORY_ALLOC: return "OMPC_GROUP_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMPP_TEAM_MEMORY_ALLOC: return "OMPP_TEAM_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_THREAD_MEMORY_ALLOC: return "OMP_THREAD_MEMORY_ALLOC";
    case OMPAllocateDeclAttrAllocatorTypeTy::OMP_USER_DEFINED_MEMORY_ALLOC: return "OMP_USER_DEFINED_MEMORY_ALLOC";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
