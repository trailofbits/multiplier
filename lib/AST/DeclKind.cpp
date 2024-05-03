// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeclKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DeclKind e) {
  switch (e) {
    case DeclKind::ACCESS_SPEC: return "ACCESS_SPEC";
    case DeclKind::BINDING: return "BINDING";
    case DeclKind::BLOCK: return "BLOCK";
    case DeclKind::BUILTIN_TEMPLATE: return "BUILTIN_TEMPLATE";
    case DeclKind::CXX_CONSTRUCTOR: return "CXX_CONSTRUCTOR";
    case DeclKind::CXX_CONVERSION: return "CXX_CONVERSION";
    case DeclKind::CXX_DEDUCTION_GUIDE: return "CXX_DEDUCTION_GUIDE";
    case DeclKind::CXX_DESTRUCTOR: return "CXX_DESTRUCTOR";
    case DeclKind::CXX_METHOD: return "CXX_METHOD";
    case DeclKind::CXX_RECORD: return "CXX_RECORD";
    case DeclKind::CAPTURED: return "CAPTURED";
    case DeclKind::CLASS_TEMPLATE: return "CLASS_TEMPLATE";
    case DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION: return "CLASS_TEMPLATE_PARTIAL_SPECIALIZATION";
    case DeclKind::CLASS_TEMPLATE_SPECIALIZATION: return "CLASS_TEMPLATE_SPECIALIZATION";
    case DeclKind::CONCEPT: return "CONCEPT";
    case DeclKind::CONSTRUCTOR_USING_SHADOW: return "CONSTRUCTOR_USING_SHADOW";
    case DeclKind::DECOMPOSITION: return "DECOMPOSITION";
    case DeclKind::EMPTY: return "EMPTY";
    case DeclKind::ENUM_CONSTANT: return "ENUM_CONSTANT";
    case DeclKind::ENUM: return "ENUM";
    case DeclKind::EXPORT: return "EXPORT";
    case DeclKind::EXTERN_C_CONTEXT: return "EXTERN_C_CONTEXT";
    case DeclKind::FIELD: return "FIELD";
    case DeclKind::FILE_SCOPE_ASM: return "FILE_SCOPE_ASM";
    case DeclKind::FRIEND: return "FRIEND";
    case DeclKind::FRIEND_TEMPLATE: return "FRIEND_TEMPLATE";
    case DeclKind::FUNCTION: return "FUNCTION";
    case DeclKind::FUNCTION_TEMPLATE: return "FUNCTION_TEMPLATE";
    case DeclKind::HLSL_BUFFER: return "HLSL_BUFFER";
    case DeclKind::IMPLICIT_CONCEPT_SPECIALIZATION: return "IMPLICIT_CONCEPT_SPECIALIZATION";
    case DeclKind::IMPLICIT_PARAM: return "IMPLICIT_PARAM";
    case DeclKind::IMPORT: return "IMPORT";
    case DeclKind::INDIRECT_FIELD: return "INDIRECT_FIELD";
    case DeclKind::LABEL: return "LABEL";
    case DeclKind::LIFETIME_EXTENDED_TEMPORARY: return "LIFETIME_EXTENDED_TEMPORARY";
    case DeclKind::LINKAGE_SPEC: return "LINKAGE_SPEC";
    case DeclKind::MS_GUID: return "MS_GUID";
    case DeclKind::MS_PROPERTY: return "MS_PROPERTY";
    case DeclKind::NAMESPACE_ALIAS: return "NAMESPACE_ALIAS";
    case DeclKind::NAMESPACE: return "NAMESPACE";
    case DeclKind::NON_TYPE_TEMPLATE_PARM: return "NON_TYPE_TEMPLATE_PARM";
    case DeclKind::OMP_ALLOCATE: return "OMP_ALLOCATE";
    case DeclKind::OMP_CAPTURED_EXPR: return "OMP_CAPTURED_EXPR";
    case DeclKind::OMP_DECLARE_MAPPER: return "OMP_DECLARE_MAPPER";
    case DeclKind::OMP_DECLARE_REDUCTION: return "OMP_DECLARE_REDUCTION";
    case DeclKind::OMP_REQUIRES: return "OMP_REQUIRES";
    case DeclKind::OMP_THREAD_PRIVATE: return "OMP_THREAD_PRIVATE";
    case DeclKind::OBJ_C_AT_DEFS_FIELD: return "OBJ_C_AT_DEFS_FIELD";
    case DeclKind::OBJ_C_CATEGORY: return "OBJ_C_CATEGORY";
    case DeclKind::OBJ_C_CATEGORY_IMPL: return "OBJ_C_CATEGORY_IMPL";
    case DeclKind::OBJ_C_COMPATIBLE_ALIAS: return "OBJ_C_COMPATIBLE_ALIAS";
    case DeclKind::OBJ_C_IMPLEMENTATION: return "OBJ_C_IMPLEMENTATION";
    case DeclKind::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    case DeclKind::OBJ_C_IVAR: return "OBJ_C_IVAR";
    case DeclKind::OBJ_C_METHOD: return "OBJ_C_METHOD";
    case DeclKind::OBJ_C_PROPERTY: return "OBJ_C_PROPERTY";
    case DeclKind::OBJ_C_PROPERTY_IMPL: return "OBJ_C_PROPERTY_IMPL";
    case DeclKind::OBJ_C_PROTOCOL: return "OBJ_C_PROTOCOL";
    case DeclKind::OBJ_C_TYPE_PARAM: return "OBJ_C_TYPE_PARAM";
    case DeclKind::PARM_VAR: return "PARM_VAR";
    case DeclKind::PRAGMA_COMMENT: return "PRAGMA_COMMENT";
    case DeclKind::PRAGMA_DETECT_MISMATCH: return "PRAGMA_DETECT_MISMATCH";
    case DeclKind::RECORD: return "RECORD";
    case DeclKind::REQUIRES_EXPR_BODY: return "REQUIRES_EXPR_BODY";
    case DeclKind::STATIC_ASSERT: return "STATIC_ASSERT";
    case DeclKind::TEMPLATE_PARAM_OBJECT: return "TEMPLATE_PARAM_OBJECT";
    case DeclKind::TEMPLATE_TEMPLATE_PARM: return "TEMPLATE_TEMPLATE_PARM";
    case DeclKind::TEMPLATE_TYPE_PARM: return "TEMPLATE_TYPE_PARM";
    case DeclKind::TOP_LEVEL_STMT: return "TOP_LEVEL_STMT";
    case DeclKind::TRANSLATION_UNIT: return "TRANSLATION_UNIT";
    case DeclKind::TYPE_ALIAS: return "TYPE_ALIAS";
    case DeclKind::TYPE_ALIAS_TEMPLATE: return "TYPE_ALIAS_TEMPLATE";
    case DeclKind::TYPEDEF: return "TYPEDEF";
    case DeclKind::UNNAMED_GLOBAL_CONSTANT: return "UNNAMED_GLOBAL_CONSTANT";
    case DeclKind::UNRESOLVED_USING_IF_EXISTS: return "UNRESOLVED_USING_IF_EXISTS";
    case DeclKind::UNRESOLVED_USING_TYPENAME: return "UNRESOLVED_USING_TYPENAME";
    case DeclKind::UNRESOLVED_USING_VALUE: return "UNRESOLVED_USING_VALUE";
    case DeclKind::USING: return "USING";
    case DeclKind::USING_DIRECTIVE: return "USING_DIRECTIVE";
    case DeclKind::USING_ENUM: return "USING_ENUM";
    case DeclKind::USING_PACK: return "USING_PACK";
    case DeclKind::USING_SHADOW: return "USING_SHADOW";
    case DeclKind::VAR: return "VAR";
    case DeclKind::VAR_TEMPLATE: return "VAR_TEMPLATE";
    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION: return "VAR_TEMPLATE_PARTIAL_SPECIALIZATION";
    case DeclKind::VAR_TEMPLATE_SPECIALIZATION: return "VAR_TEMPLATE_SPECIALIZATION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
