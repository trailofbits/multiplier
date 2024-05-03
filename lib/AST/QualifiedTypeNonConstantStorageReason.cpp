// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/QualifiedTypeNonConstantStorageReason.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(QualifiedTypeNonConstantStorageReason e) {
  switch (e) {
    case QualifiedTypeNonConstantStorageReason::MUTABLE_FIELD: return "MUTABLE_FIELD";
    case QualifiedTypeNonConstantStorageReason::NON_CONST_NON_REFERENCE_TYPE: return "NON_CONST_NON_REFERENCE_TYPE";
    case QualifiedTypeNonConstantStorageReason::NON_TRIVIAL_CONSTRUCTOR: return "NON_TRIVIAL_CONSTRUCTOR";
    case QualifiedTypeNonConstantStorageReason::NON_TRIVIAL_DESTRUCTOR: return "NON_TRIVIAL_DESTRUCTOR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
