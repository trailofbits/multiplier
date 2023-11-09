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
    case ir::AttributeKind::COMDATATTR: return "COMDATATTR";
    case ir::AttributeKind::ACCESSGROUPATTR: return "ACCESSGROUPATTR";
    case ir::AttributeKind::ALIASSCOPEATTR: return "ALIASSCOPEATTR";
    case ir::AttributeKind::ALIASSCOPEDOMAINATTR: return "ALIASSCOPEDOMAINATTR";
    case ir::AttributeKind::DIBASICTYPEATTR: return "DIBASICTYPEATTR";
    case ir::AttributeKind::DICOMPILEUNITATTR: return "DICOMPILEUNITATTR";
    case ir::AttributeKind::DICOMPOSITETYPEATTR: return "DICOMPOSITETYPEATTR";
    case ir::AttributeKind::DIDERIVEDTYPEATTR: return "DIDERIVEDTYPEATTR";
    case ir::AttributeKind::DIFILEATTR: return "DIFILEATTR";
    case ir::AttributeKind::DILABELATTR: return "DILABELATTR";
    case ir::AttributeKind::DILEXICALBLOCKATTR: return "DILEXICALBLOCKATTR";
    case ir::AttributeKind::DILEXICALBLOCKFILEATTR: return "DILEXICALBLOCKFILEATTR";
    case ir::AttributeKind::DILOCALVARIABLEATTR: return "DILOCALVARIABLEATTR";
    case ir::AttributeKind::DINAMESPACEATTR: return "DINAMESPACEATTR";
    case ir::AttributeKind::DINULLTYPEATTR: return "DINULLTYPEATTR";
    case ir::AttributeKind::DISUBPROGRAMATTR: return "DISUBPROGRAMATTR";
    case ir::AttributeKind::DISUBRANGEATTR: return "DISUBRANGEATTR";
    case ir::AttributeKind::DISUBROUTINETYPEATTR: return "DISUBROUTINETYPEATTR";
    case ir::AttributeKind::FASTMATHFLAGSATTR: return "FASTMATHFLAGSATTR";
    case ir::AttributeKind::MEMORYEFFECTSATTR: return "MEMORYEFFECTSATTR";
    case ir::AttributeKind::TBAAMEMBERATTR: return "TBAAMEMBERATTR";
    case ir::AttributeKind::TBAAROOTATTR: return "TBAAROOTATTR";
    case ir::AttributeKind::TBAATAGATTR: return "TBAATAGATTR";
    case ir::AttributeKind::TBAATYPEDESCRIPTORATTR: return "TBAATYPEDESCRIPTORATTR";
    case ir::AttributeKind::LINKAGEATTR: return "LINKAGEATTR";
    case ir::AttributeKind::LOOPANNOTATIONATTR: return "LOOPANNOTATIONATTR";
    case ir::AttributeKind::LOOPDISTRIBUTEATTR: return "LOOPDISTRIBUTEATTR";
    case ir::AttributeKind::LOOPINTERLEAVEATTR: return "LOOPINTERLEAVEATTR";
    case ir::AttributeKind::LOOPLICMATTR: return "LOOPLICMATTR";
    case ir::AttributeKind::LOOPPEELEDATTR: return "LOOPPEELEDATTR";
    case ir::AttributeKind::LOOPPIPELINEATTR: return "LOOPPIPELINEATTR";
    case ir::AttributeKind::LOOPUNROLLANDJAMATTR: return "LOOPUNROLLANDJAMATTR";
    case ir::AttributeKind::LOOPUNROLLATTR: return "LOOPUNROLLATTR";
    case ir::AttributeKind::LOOPUNSWITCHATTR: return "LOOPUNSWITCHATTR";
    case ir::AttributeKind::LOOPVECTORIZEATTR: return "LOOPVECTORIZEATTR";
    case ir::AttributeKind::ALLOCALIGNATTR: return "ALLOCALIGNATTR";
    case ir::AttributeKind::ALLOCSIZEATTR: return "ALLOCSIZEATTR";
    case ir::AttributeKind::ANNOTATIONATTR: return "ANNOTATIONATTR";
    case ir::AttributeKind::ASMLABELATTR: return "ASMLABELATTR";
    case ir::AttributeKind::BUILTINATTR: return "BUILTINATTR";
    case ir::AttributeKind::CVQUALIFIERSATTR: return "CVQUALIFIERSATTR";
    case ir::AttributeKind::CVRQUALIFIERSATTR: return "CVRQUALIFIERSATTR";
    case ir::AttributeKind::CONSTATTR: return "CONSTATTR";
    case ir::AttributeKind::FORMATATTR: return "FORMATATTR";
    case ir::AttributeKind::LOADERUNINITIALIZEDATTR: return "LOADERUNINITIALIZEDATTR";
    case ir::AttributeKind::MODEATTR: return "MODEATTR";
    case ir::AttributeKind::NOINSTRUMENTFUNCTIONATTR: return "NOINSTRUMENTFUNCTIONATTR";
    case ir::AttributeKind::NOTHROWATTR: return "NOTHROWATTR";
    case ir::AttributeKind::NONNULLATTR: return "NONNULLATTR";
    case ir::AttributeKind::PACKEDATTR: return "PACKEDATTR";
    case ir::AttributeKind::PUREATTR: return "PUREATTR";
    case ir::AttributeKind::RESTRICTATTR: return "RESTRICTATTR";
    case ir::AttributeKind::SECTIONATTR: return "SECTIONATTR";
    case ir::AttributeKind::UCVQUALIFIERSATTR: return "UCVQUALIFIERSATTR";
    case ir::AttributeKind::WARNUNUSEDRESULTATTR: return "WARNUNUSEDRESULTATTR";
    case ir::AttributeKind::IDENTIFIERATTR: return "IDENTIFIERATTR";
  }
}

}  // namespace mx
