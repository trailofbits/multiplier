// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ImplicitParamDeclImplicitParamKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ImplicitParamDeclImplicitParamKind e) {
  switch (e) {
    case ImplicitParamDeclImplicitParamKind::OBJ_C_SELF: return "OBJ_C_SELF";
    case ImplicitParamDeclImplicitParamKind::OBJ_C_CMD: return "OBJ_C_CMD";
    case ImplicitParamDeclImplicitParamKind::CXX_THIS: return "CXX_THIS";
    case ImplicitParamDeclImplicitParamKind::CXXVTT: return "CXXVTT";
    case ImplicitParamDeclImplicitParamKind::CAPTURED_CONTEXT: return "CAPTURED_CONTEXT";
    case ImplicitParamDeclImplicitParamKind::THREAD_PRIVATE_VARIABLE: return "THREAD_PRIVATE_VARIABLE";
    case ImplicitParamDeclImplicitParamKind::OTHER: return "OTHER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
