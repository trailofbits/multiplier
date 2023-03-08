// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DeclIdentifierNamespace.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DeclIdentifierNamespace e) {
  switch (e) {
    case DeclIdentifierNamespace::LABEL: return "LABEL";
    case DeclIdentifierNamespace::TAG: return "TAG";
    case DeclIdentifierNamespace::TYPE: return "TYPE";
    case DeclIdentifierNamespace::MEMBER: return "MEMBER";
    case DeclIdentifierNamespace::NAMESPACE: return "NAMESPACE";
    case DeclIdentifierNamespace::ORDINARY: return "ORDINARY";
    case DeclIdentifierNamespace::OBJ_C_PROTOCOL: return "OBJ_C_PROTOCOL";
    case DeclIdentifierNamespace::ORDINARY_FRIEND: return "ORDINARY_FRIEND";
    case DeclIdentifierNamespace::TAG_FRIEND: return "TAG_FRIEND";
    case DeclIdentifierNamespace::USING: return "USING";
    case DeclIdentifierNamespace::NON_MEMBER_OPERATOR: return "NON_MEMBER_OPERATOR";
    case DeclIdentifierNamespace::LOCAL_EXTERN: return "LOCAL_EXTERN";
    case DeclIdentifierNamespace::OMP_REDUCTION: return "OMP_REDUCTION";
    case DeclIdentifierNamespace::OMP_MAPPER: return "OMP_MAPPER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
