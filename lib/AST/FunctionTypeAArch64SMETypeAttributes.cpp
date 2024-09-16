// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionTypeAArch64SMETypeAttributes.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FunctionTypeAArch64SMETypeAttributes e) {
  switch (e) {
    case FunctionTypeAArch64SMETypeAttributes::SME_NORMAL_FUNCTION: return "SME_NORMAL_FUNCTION";
    case FunctionTypeAArch64SMETypeAttributes::SMEP_STATE_SM_ENABLED_MASK: return "SMEP_STATE_SM_ENABLED_MASK";
    case FunctionTypeAArch64SMETypeAttributes::SMEP_STATE_SM_COMPATIBLE_MASK: return "SMEP_STATE_SM_COMPATIBLE_MASK";
    case FunctionTypeAArch64SMETypeAttributes::SMEZA_MASK: return "SMEZA_MASK";
    case FunctionTypeAArch64SMETypeAttributes::SMEZT0_SHIFT: return "SMEZT0_SHIFT";
    case FunctionTypeAArch64SMETypeAttributes::SMEZT0_MASK: return "SMEZT0_MASK";
    case FunctionTypeAArch64SMETypeAttributes::SME_ATTRIBUTE_MASK: return "SME_ATTRIBUTE_MASK";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
