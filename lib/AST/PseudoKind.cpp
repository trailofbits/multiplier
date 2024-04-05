// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PseudoKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PseudoKind e) {
  switch (e) {
    case PseudoKind::TEMPLATE_ARGUMENT: return "TEMPLATE_ARGUMENT";
    case PseudoKind::TEMPLATE_PARAMETER_LIST: return "TEMPLATE_PARAMETER_LIST";
    case PseudoKind::CXX_BASE_SPECIFIER: return "CXX_BASE_SPECIFIER";
    case PseudoKind::DESIGNATOR: return "DESIGNATOR";
    case PseudoKind::CXX_CTOR_INITIALIZER: return "CXX_CTOR_INITIALIZER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
