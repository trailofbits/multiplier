// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeSpecifierType.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeSpecifierType e) {
  switch (e) {
    case TypeSpecifierType::UNSPECIFIED: return "UNSPECIFIED";
    case TypeSpecifierType::VOID: return "VOID";
    case TypeSpecifierType::CHARACTER: return "CHARACTER";
    case TypeSpecifierType::WCHAR: return "WCHAR";
    case TypeSpecifierType::CHAR8: return "CHAR8";
    case TypeSpecifierType::CHAR16: return "CHAR16";
    case TypeSpecifierType::CHAR32: return "CHAR32";
    case TypeSpecifierType::INT: return "INT";
    case TypeSpecifierType::INT128: return "INT128";
    case TypeSpecifierType::BITINT: return "BITINT";
    case TypeSpecifierType::HALF: return "HALF";
    case TypeSpecifierType::FLOAT16: return "FLOAT16";
    case TypeSpecifierType::ACCUM: return "ACCUM";
    case TypeSpecifierType::FRACT: return "FRACT";
    case TypeSpecifierType::B_FLOAT16: return "B_FLOAT16";
    case TypeSpecifierType::FLOAT: return "FLOAT";
    case TypeSpecifierType::DOUBLE: return "DOUBLE";
    case TypeSpecifierType::FLOAT128: return "FLOAT128";
    case TypeSpecifierType::IBM128: return "IBM128";
    case TypeSpecifierType::BOOLEAN: return "BOOLEAN";
    case TypeSpecifierType::DECIMAL32: return "DECIMAL32";
    case TypeSpecifierType::DECIMAL64: return "DECIMAL64";
    case TypeSpecifierType::DECIMAL128: return "DECIMAL128";
    case TypeSpecifierType::ENUM: return "ENUM";
    case TypeSpecifierType::UNION: return "UNION";
    case TypeSpecifierType::STRUCT: return "STRUCT";
    case TypeSpecifierType::CLASS: return "CLASS";
    case TypeSpecifierType::INTERFACE: return "INTERFACE";
    case TypeSpecifierType::TYPENAME: return "TYPENAME";
    case TypeSpecifierType::TYPEOF_TYPE: return "TYPEOF_TYPE";
    case TypeSpecifierType::TYPEOF_EXPRESSION: return "TYPEOF_EXPRESSION";
    case TypeSpecifierType::DECLTYPE: return "DECLTYPE";
    case TypeSpecifierType::UNDERLYING_TYPE: return "UNDERLYING_TYPE";
    case TypeSpecifierType::AUTO: return "AUTO";
    case TypeSpecifierType::DECLTYPE_AUTO: return "DECLTYPE_AUTO";
    case TypeSpecifierType::AUTO_TYPE: return "AUTO_TYPE";
    case TypeSpecifierType::UNKNOWN_ANYTYPE: return "UNKNOWN_ANYTYPE";
    case TypeSpecifierType::ATOMIC: return "ATOMIC";
    case TypeSpecifierType::IMAGE_1D_T: return "IMAGE_1D_T";
    case TypeSpecifierType::IMAGE_1D_ARRAY_T: return "IMAGE_1D_ARRAY_T";
    case TypeSpecifierType::IMAGE_1D_BUFFER_T: return "IMAGE_1D_BUFFER_T";
    case TypeSpecifierType::IMAGE_2D_T: return "IMAGE_2D_T";
    case TypeSpecifierType::IMAGE_2D_ARRAY_T: return "IMAGE_2D_ARRAY_T";
    case TypeSpecifierType::IMAGE_2D_DEPTH_T: return "IMAGE_2D_DEPTH_T";
    case TypeSpecifierType::IMAGE_2D_ARRAY_DEPTH_T: return "IMAGE_2D_ARRAY_DEPTH_T";
    case TypeSpecifierType::IMAGE_2D_MSAA_T: return "IMAGE_2D_MSAA_T";
    case TypeSpecifierType::IMAGE_2D_ARRAY_MSAA_T: return "IMAGE_2D_ARRAY_MSAA_T";
    case TypeSpecifierType::IMAGE_2D_MSAA_DEPTH_T: return "IMAGE_2D_MSAA_DEPTH_T";
    case TypeSpecifierType::IMAGE_2D_ARRAY_MSAA_DEPTH_T: return "IMAGE_2D_ARRAY_MSAA_DEPTH_T";
    case TypeSpecifierType::IMAGE_3D_T: return "IMAGE_3D_T";
    case TypeSpecifierType::ERROR: return "ERROR";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
