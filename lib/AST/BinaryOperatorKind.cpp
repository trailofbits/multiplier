// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BinaryOperatorKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(BinaryOperatorKind e) {
  switch (e) {
    case BinaryOperatorKind::POINTER_MEMORY_D: return "POINTER_MEMORY_D";
    case BinaryOperatorKind::POINTER_MEMORY_I: return "POINTER_MEMORY_I";
    case BinaryOperatorKind::MUL: return "MUL";
    case BinaryOperatorKind::DIV: return "DIV";
    case BinaryOperatorKind::REM: return "REM";
    case BinaryOperatorKind::ADD: return "ADD";
    case BinaryOperatorKind::SUB: return "SUB";
    case BinaryOperatorKind::SHL: return "SHL";
    case BinaryOperatorKind::SHR: return "SHR";
    case BinaryOperatorKind::CMP: return "CMP";
    case BinaryOperatorKind::LT: return "LT";
    case BinaryOperatorKind::GT: return "GT";
    case BinaryOperatorKind::LE: return "LE";
    case BinaryOperatorKind::GE: return "GE";
    case BinaryOperatorKind::EQ: return "EQ";
    case BinaryOperatorKind::NE: return "NE";
    case BinaryOperatorKind::AND: return "AND";
    case BinaryOperatorKind::XOR: return "XOR";
    case BinaryOperatorKind::OR: return "OR";
    case BinaryOperatorKind::L_AND: return "L_AND";
    case BinaryOperatorKind::L_OR: return "L_OR";
    case BinaryOperatorKind::ASSIGN: return "ASSIGN";
    case BinaryOperatorKind::MUL_ASSIGN: return "MUL_ASSIGN";
    case BinaryOperatorKind::DIV_ASSIGN: return "DIV_ASSIGN";
    case BinaryOperatorKind::REM_ASSIGN: return "REM_ASSIGN";
    case BinaryOperatorKind::ADD_ASSIGN: return "ADD_ASSIGN";
    case BinaryOperatorKind::SUB_ASSIGN: return "SUB_ASSIGN";
    case BinaryOperatorKind::SHL_ASSIGN: return "SHL_ASSIGN";
    case BinaryOperatorKind::SHR_ASSIGN: return "SHR_ASSIGN";
    case BinaryOperatorKind::AND_ASSIGN: return "AND_ASSIGN";
    case BinaryOperatorKind::XOR_ASSIGN: return "XOR_ASSIGN";
    case BinaryOperatorKind::OR_ASSIGN: return "OR_ASSIGN";
    case BinaryOperatorKind::COMMA: return "COMMA";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
