// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DeclCategory.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DeclCategory e) {
  switch (e) {
    case DeclCategory::UNKNOWN: return "UNKNOWN";
    case DeclCategory::LOCAL_VARIABLE: return "LOCAL_VARIABLE";
    case DeclCategory::GLOBAL_VARIABLE: return "GLOBAL_VARIABLE";
    case DeclCategory::PARAMETER_VARIABLE: return "PARAMETER_VARIABLE";
    case DeclCategory::FUNCTION: return "FUNCTION";
    case DeclCategory::INSTANCE_METHOD: return "INSTANCE_METHOD";
    case DeclCategory::INSTANCE_MEMBER: return "INSTANCE_MEMBER";
    case DeclCategory::CLASS_METHOD: return "CLASS_METHOD";
    case DeclCategory::CLASS_MEMBER: return "CLASS_MEMBER";
    case DeclCategory::THIS: return "THIS";
    case DeclCategory::CLASS: return "CLASS";
    case DeclCategory::STRUCTURE: return "STRUCTURE";
    case DeclCategory::UNION: return "UNION";
    case DeclCategory::CONCEPT: return "CONCEPT";
    case DeclCategory::INTERFACE: return "INTERFACE";
    case DeclCategory::ENUMERATION: return "ENUMERATION";
    case DeclCategory::ENUMERATOR: return "ENUMERATOR";
    case DeclCategory::NAMESPACE: return "NAMESPACE";
    case DeclCategory::TYPE_ALIAS: return "TYPE_ALIAS";
    case DeclCategory::TEMPLATE_TYPE_PARAMETER: return "TEMPLATE_TYPE_PARAMETER";
    case DeclCategory::TEMPLATE_VALUE_PARAMETER: return "TEMPLATE_VALUE_PARAMETER";
    case DeclCategory::LABEL: return "LABEL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
