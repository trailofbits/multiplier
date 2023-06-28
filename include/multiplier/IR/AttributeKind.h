// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

namespace mx {
namespace ir {
enum class AttributeKind : unsigned {
  UNKNOWN,
  CCONVATTR,
  DIBASICTYPEATTR,
  DICOMPILEUNITATTR,
  DICOMPOSITETYPEATTR,
  DIDERIVEDTYPEATTR,
  DIFILEATTR,
  DILEXICALBLOCKATTR,
  DILEXICALBLOCKFILEATTR,
  DILOCALVARIABLEATTR,
  DISUBPROGRAMATTR,
  DISUBRANGEATTR,
  DISUBROUTINETYPEATTR,
  DIVOIDRESULTTYPEATTR,
  FASTMATHFLAGSATTR,
  MEMORYEFFECTSATTR,
  LINKAGEATTR,
  LOOPOPTIONSATTR,
  ANNOTATIONATTR,
  BOOLEANATTR,
  CVQUALIFIERSATTR,
  CVRQUALIFIERSATTR,
  FLOATATTR,
  INTEGERATTR,
  STRINGATTR,
  STRINGLITERALATTR,
  UCVQUALIFIERSATTR,
  IDENTIFIERATTR,
};

}  // namespace ir

inline static const char *EnumerationName(ir::AttributeKind) {
  return "AttributeKind";
}

inline static constexpr unsigned NumEnumerators(ir::AttributeKind) {
  return 27;
}

const char *EnumeratorName(ir::AttributeKind);

}  // namespace mx
