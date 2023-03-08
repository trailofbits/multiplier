// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NameKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NameKind e) {
  switch (e) {
    case NameKind::TEMPLATE: return "TEMPLATE";
    case NameKind::OVERLOADED_TEMPLATE: return "OVERLOADED_TEMPLATE";
    case NameKind::ASSUMED_TEMPLATE: return "ASSUMED_TEMPLATE";
    case NameKind::QUALIFIED_TEMPLATE: return "QUALIFIED_TEMPLATE";
    case NameKind::DEPENDENT_TEMPLATE: return "DEPENDENT_TEMPLATE";
    case NameKind::SUBST_TEMPLATE_TEMPLATE_PARM: return "SUBST_TEMPLATE_TEMPLATE_PARM";
    case NameKind::SUBST_TEMPLATE_TEMPLATE_PARM_PACK: return "SUBST_TEMPLATE_TEMPLATE_PARM_PACK";
    case NameKind::USING_TEMPLATE: return "USING_TEMPLATE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
