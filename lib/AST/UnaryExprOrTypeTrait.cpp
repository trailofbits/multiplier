// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnaryExprOrTypeTrait.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnaryExprOrTypeTrait e) {
  switch (e) {
    case UnaryExprOrTypeTrait::SIZE_OF: return "SIZE_OF";
    case UnaryExprOrTypeTrait::DATA_SIZE_OF: return "DATA_SIZE_OF";
    case UnaryExprOrTypeTrait::ALIGN_OF: return "ALIGN_OF";
    case UnaryExprOrTypeTrait::PREFERRED_ALIGN_OF: return "PREFERRED_ALIGN_OF";
    case UnaryExprOrTypeTrait::POINTER_AUTH_TYPE_DISCRIMINATOR: return "POINTER_AUTH_TYPE_DISCRIMINATOR";
    case UnaryExprOrTypeTrait::XNU_TYPE_SIGNATURE: return "XNU_TYPE_SIGNATURE";
    case UnaryExprOrTypeTrait::XNU_TYPE_SUMMARY: return "XNU_TYPE_SUMMARY";
    case UnaryExprOrTypeTrait::TMO_TYPE_GET_METADATA: return "TMO_TYPE_GET_METADATA";
    case UnaryExprOrTypeTrait::VEC_STEP: return "VEC_STEP";
    case UnaryExprOrTypeTrait::OPEN_MP_REQUIRED_SIMD_ALIGN: return "OPEN_MP_REQUIRED_SIMD_ALIGN";
    case UnaryExprOrTypeTrait::VECTOR_ELEMENTS: return "VECTOR_ELEMENTS";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
