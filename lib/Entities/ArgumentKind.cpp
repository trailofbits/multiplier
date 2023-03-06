// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ArgumentKind.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ArgumentKind e) {
  switch (e) {
    case ArgumentKind::STD_STRING: return "STD_STRING";
    case ArgumentKind::C_STRING: return "C_STRING";
    case ArgumentKind::SINT: return "SINT";
    case ArgumentKind::UINT: return "UINT";
    case ArgumentKind::TOKENKIND: return "TOKENKIND";
    case ArgumentKind::IDENTIFIERINFO: return "IDENTIFIERINFO";
    case ArgumentKind::ADDRSPACE: return "ADDRSPACE";
    case ArgumentKind::QUALIFIED: return "QUALIFIED";
    case ArgumentKind::QUALTYPE: return "QUALTYPE";
    case ArgumentKind::DECLARATIONNAME: return "DECLARATIONNAME";
    case ArgumentKind::NAMEDDECL: return "NAMEDDECL";
    case ArgumentKind::NESTEDNAMESPEC: return "NESTEDNAMESPEC";
    case ArgumentKind::DECLCONTEXT: return "DECLCONTEXT";
    case ArgumentKind::QUALTYPE_PAIR: return "QUALTYPE_PAIR";
    case ArgumentKind::ATTRIBUTE: return "ATTRIBUTE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
