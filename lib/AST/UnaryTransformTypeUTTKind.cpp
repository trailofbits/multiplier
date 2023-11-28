// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnaryTransformTypeUTTKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnaryTransformTypeUTTKind e) {
  switch (e) {
    case UnaryTransformTypeUTTKind::ADD_LVALUE_REFERENCE: return "ADD_LVALUE_REFERENCE";
    case UnaryTransformTypeUTTKind::ADD_POINTER: return "ADD_POINTER";
    case UnaryTransformTypeUTTKind::ADD_RVALUE_REFERENCE: return "ADD_RVALUE_REFERENCE";
    case UnaryTransformTypeUTTKind::DECAY: return "DECAY";
    case UnaryTransformTypeUTTKind::MAKE_SIGNED: return "MAKE_SIGNED";
    case UnaryTransformTypeUTTKind::MAKE_UNSIGNED: return "MAKE_UNSIGNED";
    case UnaryTransformTypeUTTKind::REMOVE_ALL_EXTENTS: return "REMOVE_ALL_EXTENTS";
    case UnaryTransformTypeUTTKind::REMOVE_CONST: return "REMOVE_CONST";
    case UnaryTransformTypeUTTKind::REMOVE_CV: return "REMOVE_CV";
    case UnaryTransformTypeUTTKind::REMOVE_CV_REFERENCE: return "REMOVE_CV_REFERENCE";
    case UnaryTransformTypeUTTKind::REMOVE_EXTENT: return "REMOVE_EXTENT";
    case UnaryTransformTypeUTTKind::REMOVE_POINTER: return "REMOVE_POINTER";
    case UnaryTransformTypeUTTKind::REMOVE_REFERENCE: return "REMOVE_REFERENCE";
    case UnaryTransformTypeUTTKind::REMOVE_RESTRICT: return "REMOVE_RESTRICT";
    case UnaryTransformTypeUTTKind::REMOVE_VOLATILE: return "REMOVE_VOLATILE";
    case UnaryTransformTypeUTTKind::ENUM_UNDERLYING_TYPE: return "ENUM_UNDERLYING_TYPE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
