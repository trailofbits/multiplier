// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/AttributeKind.h>

namespace mx {

const char *EnumeratorName(ir::AttributeKind kind) {
  switch (kind) {
    default: return "UNKNOWN";
    case ir::AttributeKind::CCONVATTR: return "CCONVATTR";
    case ir::AttributeKind::DIBASICTYPEATTR: return "DIBASICTYPEATTR";
    case ir::AttributeKind::DICOMPILEUNITATTR: return "DICOMPILEUNITATTR";
    case ir::AttributeKind::DICOMPOSITETYPEATTR: return "DICOMPOSITETYPEATTR";
    case ir::AttributeKind::DIDERIVEDTYPEATTR: return "DIDERIVEDTYPEATTR";
    case ir::AttributeKind::DIFILEATTR: return "DIFILEATTR";
    case ir::AttributeKind::DILEXICALBLOCKATTR: return "DILEXICALBLOCKATTR";
    case ir::AttributeKind::DILEXICALBLOCKFILEATTR: return "DILEXICALBLOCKFILEATTR";
    case ir::AttributeKind::DILOCALVARIABLEATTR: return "DILOCALVARIABLEATTR";
    case ir::AttributeKind::DISUBPROGRAMATTR: return "DISUBPROGRAMATTR";
    case ir::AttributeKind::DISUBRANGEATTR: return "DISUBRANGEATTR";
    case ir::AttributeKind::DISUBROUTINETYPEATTR: return "DISUBROUTINETYPEATTR";
    case ir::AttributeKind::DIVOIDRESULTTYPEATTR: return "DIVOIDRESULTTYPEATTR";
    case ir::AttributeKind::FASTMATHFLAGSATTR: return "FASTMATHFLAGSATTR";
    case ir::AttributeKind::MEMORYEFFECTSATTR: return "MEMORYEFFECTSATTR";
    case ir::AttributeKind::LINKAGEATTR: return "LINKAGEATTR";
    case ir::AttributeKind::LOOPOPTIONSATTR: return "LOOPOPTIONSATTR";
    case ir::AttributeKind::ANNOTATIONATTR: return "ANNOTATIONATTR";
    case ir::AttributeKind::BOOLEANATTR: return "BOOLEANATTR";
    case ir::AttributeKind::CVQUALIFIERSATTR: return "CVQUALIFIERSATTR";
    case ir::AttributeKind::CVRQUALIFIERSATTR: return "CVRQUALIFIERSATTR";
    case ir::AttributeKind::FLOATATTR: return "FLOATATTR";
    case ir::AttributeKind::INTEGERATTR: return "INTEGERATTR";
    case ir::AttributeKind::STRINGATTR: return "STRINGATTR";
    case ir::AttributeKind::STRINGLITERALATTR: return "STRINGLITERALATTR";
    case ir::AttributeKind::UCVQUALIFIERSATTR: return "UCVQUALIFIERSATTR";
    case ir::AttributeKind::IDENTIFIERATTR: return "IDENTIFIERATTR";
  }
}

}  // namespace mx
