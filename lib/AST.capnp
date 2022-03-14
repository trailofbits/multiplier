# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

# Auto-generated file; do not modify!

@0xa04be7b45e95b659;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::ast");

struct Token @0xdf7bccc629d6dcf9 {
  offset @0 :UInt32 $Cxx.name("offset");
}

struct TokenRange @0xfaaa666ba10b6696 {
  beginOffset @0 :UInt32 $Cxx.name("begin_offset");
  endOffset @1 :UInt32 $Cxx.name("end_offset");  # Inclusive.
}

enum DeclKind @0x96ac187aac5afe4d {
  accessSpec @0 $Cxx.name("access_spec");
  baseUsing @1 $Cxx.name("base_using");
  binding @2 $Cxx.name("binding");
  block @3 $Cxx.name("block");
  builtinTemplate @4 $Cxx.name("builtin_template");
  cxxConstructor @5 $Cxx.name("cxx_constructor");
  cxxConversion @6 $Cxx.name("cxx_conversion");
  cxxDeductionGuide @7 $Cxx.name("cxx_deduction_guide");
  cxxDestructor @8 $Cxx.name("cxx_destructor");
  cxxMethod @9 $Cxx.name("cxx_method");
  cxxRecord @10 $Cxx.name("cxx_record");
  captured @11 $Cxx.name("captured");
  classScopeFunctionSpecialization @12 $Cxx.name("class_scope_function_specialization");
  classTemplate @13 $Cxx.name("class_template");
  classTemplatePartialSpecialization @14 $Cxx.name("class_template_partial_specialization");
  classTemplateSpecialization @15 $Cxx.name("class_template_specialization");
  concept @16 $Cxx.name("concept");
  constructorUsingShadow @17 $Cxx.name("constructor_using_shadow");
  declarator @18 $Cxx.name("declarator");
  decomposition @19 $Cxx.name("decomposition");
  empty @20 $Cxx.name("empty");
  enumConstant @21 $Cxx.name("enum_constant");
  enum @22 $Cxx.name("enum");
  export @23 $Cxx.name("export");
  externCContext @24 $Cxx.name("extern_c_context");
  field @25 $Cxx.name("field");
  fileScopeAsm @26 $Cxx.name("file_scope_asm");
  friend @27 $Cxx.name("friend");
  friendTemplate @28 $Cxx.name("friend_template");
  function @29 $Cxx.name("function");
  functionTemplate @30 $Cxx.name("function_template");
  implicitParam @31 $Cxx.name("implicit_param");
  import @32 $Cxx.name("import");
  indirectField @33 $Cxx.name("indirect_field");
  label @34 $Cxx.name("label");
  lifetimeExtendedTemporary @35 $Cxx.name("lifetime_extended_temporary");
  linkageSpec @36 $Cxx.name("linkage_spec");
  msGuid @37 $Cxx.name("ms_guid");
  msProperty @38 $Cxx.name("ms_property");
  named @39 $Cxx.name("named");
  namespaceAlias @40 $Cxx.name("namespace_alias");
  namespace @41 $Cxx.name("namespace");
  nonTypeTemplateParm @42 $Cxx.name("non_type_template_parm");
  ompAllocate @43 $Cxx.name("omp_allocate");
  ompCapturedExpr @44 $Cxx.name("omp_captured_expr");
  ompDeclareMapper @45 $Cxx.name("omp_declare_mapper");
  ompDeclareReduction @46 $Cxx.name("omp_declare_reduction");
  ompRequires @47 $Cxx.name("omp_requires");
  ompThreadPrivate @48 $Cxx.name("omp_thread_private");
  objCAtDefsField @49 $Cxx.name("obj_c_at_defs_field");
  objCCategory @50 $Cxx.name("obj_c_category");
  objCCategoryImpl @51 $Cxx.name("obj_c_category_impl");
  objCCompatibleAlias @52 $Cxx.name("obj_c_compatible_alias");
  objCContainer @53 $Cxx.name("obj_c_container");
  objCImpl @54 $Cxx.name("obj_c_impl");
  objCImplementation @55 $Cxx.name("obj_c_implementation");
  objCInterface @56 $Cxx.name("obj_c_interface");
  objCIvar @57 $Cxx.name("obj_c_ivar");
  objCMethod @58 $Cxx.name("obj_c_method");
  objCProperty @59 $Cxx.name("obj_c_property");
  objCPropertyImpl @60 $Cxx.name("obj_c_property_impl");
  objCProtocol @61 $Cxx.name("obj_c_protocol");
  objCTypeParam @62 $Cxx.name("obj_c_type_param");
  parmVar @63 $Cxx.name("parm_var");
  pragmaComment @64 $Cxx.name("pragma_comment");
  pragmaDetectMismatch @65 $Cxx.name("pragma_detect_mismatch");
  record @66 $Cxx.name("record");
  redeclarableTemplate @67 $Cxx.name("redeclarable_template");
  requiresExprBody @68 $Cxx.name("requires_expr_body");
  staticAssert @69 $Cxx.name("static_assert");
  tag @70 $Cxx.name("tag");
  template @71 $Cxx.name("template");
  templateParamObject @72 $Cxx.name("template_param_object");
  templateTemplateParm @73 $Cxx.name("template_template_parm");
  templateTypeParm @74 $Cxx.name("template_type_parm");
  translationUnit @75 $Cxx.name("translation_unit");
  typeAlias @76 $Cxx.name("type_alias");
  typeAliasTemplate @77 $Cxx.name("type_alias_template");
  type @78 $Cxx.name("type");
  typedef @79 $Cxx.name("typedef");
  typedefName @80 $Cxx.name("typedef_name");
  unresolvedUsingIfExists @81 $Cxx.name("unresolved_using_if_exists");
  unresolvedUsingTypename @82 $Cxx.name("unresolved_using_typename");
  unresolvedUsingValue @83 $Cxx.name("unresolved_using_value");
  using @84 $Cxx.name("using");
  usingDirective @85 $Cxx.name("using_directive");
  usingEnum @86 $Cxx.name("using_enum");
  usingPack @87 $Cxx.name("using_pack");
  usingShadow @88 $Cxx.name("using_shadow");
  value @89 $Cxx.name("value");
  var @90 $Cxx.name("var");
  varTemplate @91 $Cxx.name("var_template");
  varTemplatePartialSpecialization @92 $Cxx.name("var_template_partial_specialization");
  varTemplateSpecialization @93 $Cxx.name("var_template_specialization");
}

enum ArrayTypeArraySizeModifier @0x9c0c34c182208936 {
  normal @0 $Cxx.name("normal");
  static @1 $Cxx.name("static");
  star @2 $Cxx.name("star");
}

enum AtomicExprAtomicOp @0xbd6e82229eede8ee {
  c11AtomicInitializer @0 $Cxx.name("c11_atomic_initializer");
  c11AtomicLoad @1 $Cxx.name("c11_atomic_load");
  c11AtomicStore @2 $Cxx.name("c11_atomic_store");
  c11AtomicExchange @3 $Cxx.name("c11_atomic_exchange");
  c11AtomicCompareExchangeStrong @4 $Cxx.name("c11_atomic_compare_exchange_strong");
  c11AtomicCompareExchangeWeak @5 $Cxx.name("c11_atomic_compare_exchange_weak");
  c11AtomicFetchAdd @6 $Cxx.name("c11_atomic_fetch_add");
  c11AtomicFetchSub @7 $Cxx.name("c11_atomic_fetch_sub");
  c11AtomicFetchAnd @8 $Cxx.name("c11_atomic_fetch_and");
  c11AtomicFetchOr @9 $Cxx.name("c11_atomic_fetch_or");
  c11AtomicFetchXor @10 $Cxx.name("c11_atomic_fetch_xor");
  c11AtomicFetchMax @11 $Cxx.name("c11_atomic_fetch_max");
  c11AtomicFetchMin @12 $Cxx.name("c11_atomic_fetch_min");
  atomicLoad @13 $Cxx.name("atomic_load");
  atomicLoadUcN @14 $Cxx.name("atomic_load_n");
  atomicStore @15 $Cxx.name("atomic_store");
  atomicStoreUcN @16 $Cxx.name("atomic_store_n");
  atomicExchange @17 $Cxx.name("atomic_exchange");
  atomicExchangeUcN @18 $Cxx.name("atomic_exchange_n");
  atomicCompareExchange @19 $Cxx.name("atomic_compare_exchange");
  atomicCompareExchangeUcN @20 $Cxx.name("atomic_compare_exchange_n");
  atomicFetchAdd @21 $Cxx.name("atomic_fetch_add");
  atomicFetchSub @22 $Cxx.name("atomic_fetch_sub");
  atomicFetchAnd @23 $Cxx.name("atomic_fetch_and");
  atomicFetchOr @24 $Cxx.name("atomic_fetch_or");
  atomicFetchXor @25 $Cxx.name("atomic_fetch_xor");
  atomicFetchNand @26 $Cxx.name("atomic_fetch_nand");
  atomicAddFetch @27 $Cxx.name("atomic_add_fetch");
  atomicSubFetch @28 $Cxx.name("atomic_sub_fetch");
  atomicAndFetch @29 $Cxx.name("atomic_and_fetch");
  atomicOrFetch @30 $Cxx.name("atomic_or_fetch");
  atomicXorFetch @31 $Cxx.name("atomic_xor_fetch");
  atomicMaxFetch @32 $Cxx.name("atomic_max_fetch");
  atomicMinFetch @33 $Cxx.name("atomic_min_fetch");
  atomicNandFetch @34 $Cxx.name("atomic_nand_fetch");
  openclAtomicInitializer @35 $Cxx.name("opencl_atomic_initializer");
  openclAtomicLoad @36 $Cxx.name("opencl_atomic_load");
  openclAtomicStore @37 $Cxx.name("opencl_atomic_store");
  openclAtomicExchange @38 $Cxx.name("opencl_atomic_exchange");
  openclAtomicCompareExchangeStrong @39 $Cxx.name("opencl_atomic_compare_exchange_strong");
  openclAtomicCompareExchangeWeak @40 $Cxx.name("opencl_atomic_compare_exchange_weak");
  openclAtomicFetchAdd @41 $Cxx.name("opencl_atomic_fetch_add");
  openclAtomicFetchSub @42 $Cxx.name("opencl_atomic_fetch_sub");
  openclAtomicFetchAnd @43 $Cxx.name("opencl_atomic_fetch_and");
  openclAtomicFetchOr @44 $Cxx.name("opencl_atomic_fetch_or");
  openclAtomicFetchXor @45 $Cxx.name("opencl_atomic_fetch_xor");
  openclAtomicFetchMin @46 $Cxx.name("opencl_atomic_fetch_min");
  openclAtomicFetchMax @47 $Cxx.name("opencl_atomic_fetch_max");
  atomicFetchMin @48 $Cxx.name("atomic_fetch_min");
  atomicFetchMax @49 $Cxx.name("atomic_fetch_max");
}

enum BuiltinTypeKind @0xaab624b457b4ccb7 {
  oclImage1Dro @0 $Cxx.name("ocl_image1_dro");
  oclImage1DarrayRo @1 $Cxx.name("ocl_image1_darray_ro");
  oclImage1DbufferRo @2 $Cxx.name("ocl_image1_dbuffer_ro");
  oclImage2Dro @3 $Cxx.name("ocl_image2_dro");
  oclImage2DarrayRo @4 $Cxx.name("ocl_image2_darray_ro");
  oclImage2DdepthRo @5 $Cxx.name("ocl_image2_ddepth_ro");
  oclImage2DarrayDepthRo @6 $Cxx.name("ocl_image2_darray_depth_ro");
  oclImage2Dmsaaro @7 $Cxx.name("ocl_image2_dmsaaro");
  oclImage2DarrayMsaaro @8 $Cxx.name("ocl_image2_darray_msaaro");
  oclImage2DmsaaDepthRo @9 $Cxx.name("ocl_image2_dmsaa_depth_ro");
  oclImage2DarrayMsaaDepthRo @10 $Cxx.name("ocl_image2_darray_msaa_depth_ro");
  oclImage3Dro @11 $Cxx.name("ocl_image3_dro");
  oclImage1Dwo @12 $Cxx.name("ocl_image1_dwo");
  oclImage1DarrayWo @13 $Cxx.name("ocl_image1_darray_wo");
  oclImage1DbufferWo @14 $Cxx.name("ocl_image1_dbuffer_wo");
  oclImage2Dwo @15 $Cxx.name("ocl_image2_dwo");
  oclImage2DarrayWo @16 $Cxx.name("ocl_image2_darray_wo");
  oclImage2DdepthWo @17 $Cxx.name("ocl_image2_ddepth_wo");
  oclImage2DarrayDepthWo @18 $Cxx.name("ocl_image2_darray_depth_wo");
  oclImage2Dmsaawo @19 $Cxx.name("ocl_image2_dmsaawo");
  oclImage2DarrayMsaawo @20 $Cxx.name("ocl_image2_darray_msaawo");
  oclImage2DmsaaDepthWo @21 $Cxx.name("ocl_image2_dmsaa_depth_wo");
  oclImage2DarrayMsaaDepthWo @22 $Cxx.name("ocl_image2_darray_msaa_depth_wo");
  oclImage3Dwo @23 $Cxx.name("ocl_image3_dwo");
  oclImage1Drw @24 $Cxx.name("ocl_image1_drw");
  oclImage1DarrayRw @25 $Cxx.name("ocl_image1_darray_rw");
  oclImage1DbufferRw @26 $Cxx.name("ocl_image1_dbuffer_rw");
  oclImage2Drw @27 $Cxx.name("ocl_image2_drw");
  oclImage2DarrayRw @28 $Cxx.name("ocl_image2_darray_rw");
  oclImage2DdepthRw @29 $Cxx.name("ocl_image2_ddepth_rw");
  oclImage2DarrayDepthRw @30 $Cxx.name("ocl_image2_darray_depth_rw");
  oclImage2Dmsaarw @31 $Cxx.name("ocl_image2_dmsaarw");
  oclImage2DarrayMsaarw @32 $Cxx.name("ocl_image2_darray_msaarw");
  oclImage2DmsaaDepthRw @33 $Cxx.name("ocl_image2_dmsaa_depth_rw");
  oclImage2DarrayMsaaDepthRw @34 $Cxx.name("ocl_image2_darray_msaa_depth_rw");
  oclImage3Drw @35 $Cxx.name("ocl_image3_drw");
  oclIntelSubgroupAvcMcePayload @36 $Cxx.name("ocl_intel_subgroup_avc_mce_payload");
  oclIntelSubgroupAvcImePayload @37 $Cxx.name("ocl_intel_subgroup_avc_ime_payload");
  oclIntelSubgroupAvcRefPayload @38 $Cxx.name("ocl_intel_subgroup_avc_ref_payload");
  oclIntelSubgroupAvcSicPayload @39 $Cxx.name("ocl_intel_subgroup_avc_sic_payload");
  oclIntelSubgroupAvcMceResult @40 $Cxx.name("ocl_intel_subgroup_avc_mce_result");
  oclIntelSubgroupAvcImeResult @41 $Cxx.name("ocl_intel_subgroup_avc_ime_result");
  oclIntelSubgroupAvcRefResult @42 $Cxx.name("ocl_intel_subgroup_avc_ref_result");
  oclIntelSubgroupAvcSicResult @43 $Cxx.name("ocl_intel_subgroup_avc_sic_result");
  oclIntelSubgroupAvcImeResultSingleReferenceStreamout @44 $Cxx.name("ocl_intel_subgroup_avc_ime_result_single_reference_streamout");
  oclIntelSubgroupAvcImeResultDualReferenceStreamout @45 $Cxx.name("ocl_intel_subgroup_avc_ime_result_dual_reference_streamout");
  oclIntelSubgroupAvcImeSingleReferenceStreamin @46 $Cxx.name("ocl_intel_subgroup_avc_ime_single_reference_streamin");
  oclIntelSubgroupAvcImeDualReferenceStreamin @47 $Cxx.name("ocl_intel_subgroup_avc_ime_dual_reference_streamin");
  sveInt8 @48 $Cxx.name("sve_int8");
  sveInt16 @49 $Cxx.name("sve_int16");
  sveInt32 @50 $Cxx.name("sve_int32");
  sveInt64 @51 $Cxx.name("sve_int64");
  sveUint8 @52 $Cxx.name("sve_uint8");
  sveUint16 @53 $Cxx.name("sve_uint16");
  sveUint32 @54 $Cxx.name("sve_uint32");
  sveUint64 @55 $Cxx.name("sve_uint64");
  sveFloat16 @56 $Cxx.name("sve_float16");
  sveFloat32 @57 $Cxx.name("sve_float32");
  sveFloat64 @58 $Cxx.name("sve_float64");
  sveBFloat16 @59 $Cxx.name("sve_b_float16");
  sveInt8X2 @60 $Cxx.name("sve_int8_x2");
  sveInt16X2 @61 $Cxx.name("sve_int16_x2");
  sveInt32X2 @62 $Cxx.name("sve_int32_x2");
  sveInt64X2 @63 $Cxx.name("sve_int64_x2");
  sveUint8X2 @64 $Cxx.name("sve_uint8_x2");
  sveUint16X2 @65 $Cxx.name("sve_uint16_x2");
  sveUint32X2 @66 $Cxx.name("sve_uint32_x2");
  sveUint64X2 @67 $Cxx.name("sve_uint64_x2");
  sveFloat16X2 @68 $Cxx.name("sve_float16_x2");
  sveFloat32X2 @69 $Cxx.name("sve_float32_x2");
  sveFloat64X2 @70 $Cxx.name("sve_float64_x2");
  sveBFloat16X2 @71 $Cxx.name("sve_b_float16_x2");
  sveInt8X3 @72 $Cxx.name("sve_int8_x3");
  sveInt16X3 @73 $Cxx.name("sve_int16_x3");
  sveInt32X3 @74 $Cxx.name("sve_int32_x3");
  sveInt64X3 @75 $Cxx.name("sve_int64_x3");
  sveUint8X3 @76 $Cxx.name("sve_uint8_x3");
  sveUint16X3 @77 $Cxx.name("sve_uint16_x3");
  sveUint32X3 @78 $Cxx.name("sve_uint32_x3");
  sveUint64X3 @79 $Cxx.name("sve_uint64_x3");
  sveFloat16X3 @80 $Cxx.name("sve_float16_x3");
  sveFloat32X3 @81 $Cxx.name("sve_float32_x3");
  sveFloat64X3 @82 $Cxx.name("sve_float64_x3");
  sveBFloat16X3 @83 $Cxx.name("sve_b_float16_x3");
  sveInt8X4 @84 $Cxx.name("sve_int8_x4");
  sveInt16X4 @85 $Cxx.name("sve_int16_x4");
  sveInt32X4 @86 $Cxx.name("sve_int32_x4");
  sveInt64X4 @87 $Cxx.name("sve_int64_x4");
  sveUint8X4 @88 $Cxx.name("sve_uint8_x4");
  sveUint16X4 @89 $Cxx.name("sve_uint16_x4");
  sveUint32X4 @90 $Cxx.name("sve_uint32_x4");
  sveUint64X4 @91 $Cxx.name("sve_uint64_x4");
  sveFloat16X4 @92 $Cxx.name("sve_float16_x4");
  sveFloat32X4 @93 $Cxx.name("sve_float32_x4");
  sveFloat64X4 @94 $Cxx.name("sve_float64_x4");
  sveBFloat16X4 @95 $Cxx.name("sve_b_float16_x4");
  sveBoolean @96 $Cxx.name("sve_boolean");
  vectorQuad @97 $Cxx.name("vector_quad");
  vectorPair @98 $Cxx.name("vector_pair");
  rvvInt8Mf8 @99 $Cxx.name("rvv_int8_mf8");
  rvvInt8Mf4 @100 $Cxx.name("rvv_int8_mf4");
  rvvInt8Mf2 @101 $Cxx.name("rvv_int8_mf2");
  rvvInt8M1 @102 $Cxx.name("rvv_int8_m1");
  rvvInt8M2 @103 $Cxx.name("rvv_int8_m2");
  rvvInt8M4 @104 $Cxx.name("rvv_int8_m4");
  rvvInt8M8 @105 $Cxx.name("rvv_int8_m8");
  rvvUint8Mf8 @106 $Cxx.name("rvv_uint8_mf8");
  rvvUint8Mf4 @107 $Cxx.name("rvv_uint8_mf4");
  rvvUint8Mf2 @108 $Cxx.name("rvv_uint8_mf2");
  rvvUint8M1 @109 $Cxx.name("rvv_uint8_m1");
  rvvUint8M2 @110 $Cxx.name("rvv_uint8_m2");
  rvvUint8M4 @111 $Cxx.name("rvv_uint8_m4");
  rvvUint8M8 @112 $Cxx.name("rvv_uint8_m8");
  rvvInt16Mf4 @113 $Cxx.name("rvv_int16_mf4");
  rvvInt16Mf2 @114 $Cxx.name("rvv_int16_mf2");
  rvvInt16M1 @115 $Cxx.name("rvv_int16_m1");
  rvvInt16M2 @116 $Cxx.name("rvv_int16_m2");
  rvvInt16M4 @117 $Cxx.name("rvv_int16_m4");
  rvvInt16M8 @118 $Cxx.name("rvv_int16_m8");
  rvvUint16Mf4 @119 $Cxx.name("rvv_uint16_mf4");
  rvvUint16Mf2 @120 $Cxx.name("rvv_uint16_mf2");
  rvvUint16M1 @121 $Cxx.name("rvv_uint16_m1");
  rvvUint16M2 @122 $Cxx.name("rvv_uint16_m2");
  rvvUint16M4 @123 $Cxx.name("rvv_uint16_m4");
  rvvUint16M8 @124 $Cxx.name("rvv_uint16_m8");
  rvvInt32Mf2 @125 $Cxx.name("rvv_int32_mf2");
  rvvInt32M1 @126 $Cxx.name("rvv_int32_m1");
  rvvInt32M2 @127 $Cxx.name("rvv_int32_m2");
  rvvInt32M4 @128 $Cxx.name("rvv_int32_m4");
  rvvInt32M8 @129 $Cxx.name("rvv_int32_m8");
  rvvUint32Mf2 @130 $Cxx.name("rvv_uint32_mf2");
  rvvUint32M1 @131 $Cxx.name("rvv_uint32_m1");
  rvvUint32M2 @132 $Cxx.name("rvv_uint32_m2");
  rvvUint32M4 @133 $Cxx.name("rvv_uint32_m4");
  rvvUint32M8 @134 $Cxx.name("rvv_uint32_m8");
  rvvInt64M1 @135 $Cxx.name("rvv_int64_m1");
  rvvInt64M2 @136 $Cxx.name("rvv_int64_m2");
  rvvInt64M4 @137 $Cxx.name("rvv_int64_m4");
  rvvInt64M8 @138 $Cxx.name("rvv_int64_m8");
  rvvUint64M1 @139 $Cxx.name("rvv_uint64_m1");
  rvvUint64M2 @140 $Cxx.name("rvv_uint64_m2");
  rvvUint64M4 @141 $Cxx.name("rvv_uint64_m4");
  rvvUint64M8 @142 $Cxx.name("rvv_uint64_m8");
  rvvFloat16Mf4 @143 $Cxx.name("rvv_float16_mf4");
  rvvFloat16Mf2 @144 $Cxx.name("rvv_float16_mf2");
  rvvFloat16M1 @145 $Cxx.name("rvv_float16_m1");
  rvvFloat16M2 @146 $Cxx.name("rvv_float16_m2");
  rvvFloat16M4 @147 $Cxx.name("rvv_float16_m4");
  rvvFloat16M8 @148 $Cxx.name("rvv_float16_m8");
  rvvFloat32Mf2 @149 $Cxx.name("rvv_float32_mf2");
  rvvFloat32M1 @150 $Cxx.name("rvv_float32_m1");
  rvvFloat32M2 @151 $Cxx.name("rvv_float32_m2");
  rvvFloat32M4 @152 $Cxx.name("rvv_float32_m4");
  rvvFloat32M8 @153 $Cxx.name("rvv_float32_m8");
  rvvFloat64M1 @154 $Cxx.name("rvv_float64_m1");
  rvvFloat64M2 @155 $Cxx.name("rvv_float64_m2");
  rvvFloat64M4 @156 $Cxx.name("rvv_float64_m4");
  rvvFloat64M8 @157 $Cxx.name("rvv_float64_m8");
  rvvBool1 @158 $Cxx.name("rvv_bool1");
  rvvBool2 @159 $Cxx.name("rvv_bool2");
  rvvBool4 @160 $Cxx.name("rvv_bool4");
  rvvBool8 @161 $Cxx.name("rvv_bool8");
  rvvBool16 @162 $Cxx.name("rvv_bool16");
  rvvBool32 @163 $Cxx.name("rvv_bool32");
  rvvBool64 @164 $Cxx.name("rvv_bool64");
  void @165 $Cxx.name("void");
  boolean @166 $Cxx.name("boolean");
  characterUcU @167 $Cxx.name("character_u");
  uChar @168 $Cxx.name("u_char");
  wCharUcU @169 $Cxx.name("w_char_u");
  char8 @170 $Cxx.name("char8");
  char16 @171 $Cxx.name("char16");
  char32 @172 $Cxx.name("char32");
  uShort @173 $Cxx.name("u_short");
  uInt @174 $Cxx.name("u_int");
  uLong @175 $Cxx.name("u_long");
  uLongLong @176 $Cxx.name("u_long_long");
  uInt128 @177 $Cxx.name("u_int128");
  characterUcS @178 $Cxx.name("character_s");
  sChar @179 $Cxx.name("s_char");
  wCharUcS @180 $Cxx.name("w_char_s");
  short @181 $Cxx.name("short");
  int @182 $Cxx.name("int");
  long @183 $Cxx.name("long");
  longLong @184 $Cxx.name("long_long");
  int128 @185 $Cxx.name("int128");
  shortAccum @186 $Cxx.name("short_accum");
  accum @187 $Cxx.name("accum");
  longAccum @188 $Cxx.name("long_accum");
  uShortAccum @189 $Cxx.name("u_short_accum");
  uAccum @190 $Cxx.name("u_accum");
  uLongAccum @191 $Cxx.name("u_long_accum");
  shortFract @192 $Cxx.name("short_fract");
  fract @193 $Cxx.name("fract");
  longFract @194 $Cxx.name("long_fract");
  uShortFract @195 $Cxx.name("u_short_fract");
  uFract @196 $Cxx.name("u_fract");
  uLongFract @197 $Cxx.name("u_long_fract");
  satShortAccum @198 $Cxx.name("sat_short_accum");
  satAccum @199 $Cxx.name("sat_accum");
  satLongAccum @200 $Cxx.name("sat_long_accum");
  satUShortAccum @201 $Cxx.name("sat_u_short_accum");
  satUAccum @202 $Cxx.name("sat_u_accum");
  satULongAccum @203 $Cxx.name("sat_u_long_accum");
  satShortFract @204 $Cxx.name("sat_short_fract");
  satFract @205 $Cxx.name("sat_fract");
  satLongFract @206 $Cxx.name("sat_long_fract");
  satUShortFract @207 $Cxx.name("sat_u_short_fract");
  satUFract @208 $Cxx.name("sat_u_fract");
  satULongFract @209 $Cxx.name("sat_u_long_fract");
  half @210 $Cxx.name("half");
  float @211 $Cxx.name("float");
  double @212 $Cxx.name("double");
  longDouble @213 $Cxx.name("long_double");
  float16 @214 $Cxx.name("float16");
  bFloat16 @215 $Cxx.name("b_float16");
  float128 @216 $Cxx.name("float128");
  nullPointer @217 $Cxx.name("null_pointer");
  objCId @218 $Cxx.name("obj_c_id");
  objCClass @219 $Cxx.name("obj_c_class");
  objCSel @220 $Cxx.name("obj_c_sel");
  oclSampler @221 $Cxx.name("ocl_sampler");
  oclEvent @222 $Cxx.name("ocl_event");
  oclClkEvent @223 $Cxx.name("ocl_clk_event");
  oclQueue @224 $Cxx.name("ocl_queue");
  oclReserveId @225 $Cxx.name("ocl_reserve_id");
  dependent @226 $Cxx.name("dependent");
  overload @227 $Cxx.name("overload");
  boundMember @228 $Cxx.name("bound_member");
  pseudoObject @229 $Cxx.name("pseudo_object");
  unknownAny @230 $Cxx.name("unknown_any");
  builtinFn @231 $Cxx.name("builtin_fn");
  arcUnbridgedCast @232 $Cxx.name("arc_unbridged_cast");
  incompleteMatrixIndex @233 $Cxx.name("incomplete_matrix_index");
  ompArraySection @234 $Cxx.name("omp_array_section");
  ompArrayShaping @235 $Cxx.name("omp_array_shaping");
  ompIterator @236 $Cxx.name("omp_iterator");
}

enum CXXConstructExprConstructionKind @0xe62e66817849443b {
  complete @0 $Cxx.name("complete");
  nonVirtualBase @1 $Cxx.name("non_virtual_base");
  virtualBase @2 $Cxx.name("virtual_base");
  delegating @3 $Cxx.name("delegating");
}

enum CXXNewExprInitializationStyle @0xba6c83e98380bd05 {
  noInitializer @0 $Cxx.name("no_initializer");
  callInitializer @1 $Cxx.name("call_initializer");
  listInitializer @2 $Cxx.name("list_initializer");
}

enum CallExprADLCallKind @0x82a3f08354a7009d {
  notAdl @0 $Cxx.name("not_adl");
  usesAdl @1 $Cxx.name("uses_adl");
}

enum CapturedStmtVariableCaptureKind @0x9c79628470fad762 {
  this @0 $Cxx.name("this");
  byReference @1 $Cxx.name("by_reference");
  byCopy @2 $Cxx.name("by_copy");
  vlaType @3 $Cxx.name("vla_type");
}

enum CharacterLiteralCharacterKind @0xc0c13e28937e938c {
  ascii @0 $Cxx.name("ascii");
  wide @1 $Cxx.name("wide");
  utF8 @2 $Cxx.name("ut_f8");
  utF16 @3 $Cxx.name("ut_f16");
  utF32 @4 $Cxx.name("ut_f32");
}

enum ConstantExprResultStorageKind @0xc4786f8c026b3e39 {
  none @0 $Cxx.name("none");
  int64 @1 $Cxx.name("int64");
  apValue @2 $Cxx.name("ap_value");
}

enum DeclFriendObjectKind @0x858fc3d0fc6c5910 {
  none @0 $Cxx.name("none");
  declared @1 $Cxx.name("declared");
  undeclared @2 $Cxx.name("undeclared");
}

enum DeclIdentifierNamespace @0xd581641260f0c55c {
  label @0 $Cxx.name("label");
  tag @1 $Cxx.name("tag");
  type @2 $Cxx.name("type");
  member @3 $Cxx.name("member");
  namespace @4 $Cxx.name("namespace");
  ordinary @5 $Cxx.name("ordinary");
  objCProtocol @6 $Cxx.name("obj_c_protocol");
  ordinaryFriend @7 $Cxx.name("ordinary_friend");
  tagFriend @8 $Cxx.name("tag_friend");
  using @9 $Cxx.name("using");
  nonMemberOperator @10 $Cxx.name("non_member_operator");
  localExtern @11 $Cxx.name("local_extern");
  ompReduction @12 $Cxx.name("omp_reduction");
  ompMapper @13 $Cxx.name("omp_mapper");
}

enum DeclModuleOwnershipKind @0xf10e8db874427fd3 {
  unowned @0 $Cxx.name("unowned");
  visible @1 $Cxx.name("visible");
  visibleWhenImported @2 $Cxx.name("visible_when_imported");
  modulePrivate @3 $Cxx.name("module_private");
}

enum DeclObjCDeclQualifier @0xe906258f1cf38dde {
  none @0 $Cxx.name("none");
  in @1 $Cxx.name("in");
  inout @2 $Cxx.name("inout");
  out @3 $Cxx.name("out");
  bycopy @4 $Cxx.name("bycopy");
  byref @5 $Cxx.name("byref");
  oneway @6 $Cxx.name("oneway");
  csNullability @7 $Cxx.name("cs_nullability");
}

enum ExprConstantExprKind @0xe07297cbddd20026 {
  normal @0 $Cxx.name("normal");
  nonClassTemplateArgument @1 $Cxx.name("non_class_template_argument");
  classTemplateArgument @2 $Cxx.name("class_template_argument");
  immediateInvocation @3 $Cxx.name("immediate_invocation");
}

enum ExprLValueClassification @0xce30839288fdca09 {
  valid @0 $Cxx.name("valid");
  notObjectType @1 $Cxx.name("not_object_type");
  incompleteVoidType @2 $Cxx.name("incomplete_void_type");
  duplicateVectorComponents @3 $Cxx.name("duplicate_vector_components");
  invalidExpression @4 $Cxx.name("invalid_expression");
  invalidMessageExpression @5 $Cxx.name("invalid_message_expression");
  memberFunction @6 $Cxx.name("member_function");
  subObjCPropertySetting @7 $Cxx.name("sub_obj_c_property_setting");
  classTemporary @8 $Cxx.name("class_temporary");
  arrayTemporary @9 $Cxx.name("array_temporary");
}

enum ExprNullPointerConstantKind @0xf1f8486254f579e2 {
  notNull @0 $Cxx.name("not_null");
  zeroExpression @1 $Cxx.name("zero_expression");
  zeroLiteral @2 $Cxx.name("zero_literal");
  cxX11Nullptr @3 $Cxx.name("cx_x11_nullptr");
  gnuNull @4 $Cxx.name("gnu_null");
}

enum ExprNullPointerConstantValueDependence @0xe67d9538211e3de4 {
  neverValueDependent @0 $Cxx.name("never_value_dependent");
  valueDependentIsNull @1 $Cxx.name("value_dependent_is_null");
  valueDependentIsNotNull @2 $Cxx.name("value_dependent_is_not_null");
}

enum ExprSideEffectsKind @0xd01186f73a889ba9 {
  noSideEffects @0 $Cxx.name("no_side_effects");
  allowUndefinedBehavior @1 $Cxx.name("allow_undefined_behavior");
  allowSideEffects @2 $Cxx.name("allow_side_effects");
}

enum ExprisModifiableLvalueResult @0xc9f80b8bd2f90317 {
  valid @0 $Cxx.name("valid");
  notObjectType @1 $Cxx.name("not_object_type");
  incompleteVoidType @2 $Cxx.name("incomplete_void_type");
  duplicateVectorComponents @3 $Cxx.name("duplicate_vector_components");
  invalidExpression @4 $Cxx.name("invalid_expression");
  lValueCast @5 $Cxx.name("l_value_cast");
  incompleteType @6 $Cxx.name("incomplete_type");
  constQualified @7 $Cxx.name("const_qualified");
  constQualifiedField @8 $Cxx.name("const_qualified_field");
  constAddrSpace @9 $Cxx.name("const_addr_space");
  arrayType @10 $Cxx.name("array_type");
  noSetterProperty @11 $Cxx.name("no_setter_property");
  memberFunction @12 $Cxx.name("member_function");
  subObjCPropertySetting @13 $Cxx.name("sub_obj_c_property_setting");
  invalidMessageExpression @14 $Cxx.name("invalid_message_expression");
  classTemporary @15 $Cxx.name("class_temporary");
  arrayTemporary @16 $Cxx.name("array_temporary");
}

enum FunctionDeclTemplatedKind @0xb81ebd6c42642771 {
  nonTemplate @0 $Cxx.name("non_template");
  functionTemplate @1 $Cxx.name("function_template");
  memberSpecialization @2 $Cxx.name("member_specialization");
  functionTemplateSpecialization @3 $Cxx.name("function_template_specialization");
  dependentFunctionTemplateSpecialization @4 $Cxx.name("dependent_function_template_specialization");
}

enum ImplicitCastExprOnStack @0xc0020b2c8aef2dd6 {
  onStack @0 $Cxx.name("on_stack");
}

enum ImplicitParamDeclImplicitParamKind @0xb9686cbfe824fde1 {
  objCSelf @0 $Cxx.name("obj_c_self");
  objCCmd @1 $Cxx.name("obj_c_cmd");
  cxxThis @2 $Cxx.name("cxx_this");
  cxxvtt @3 $Cxx.name("cxxvtt");
  capturedContext @4 $Cxx.name("captured_context");
  other @5 $Cxx.name("other");
}

enum LinkageSpecDeclLanguageIDs @0xddc7f9e7e59fdf94 {
  c @0 $Cxx.name("c");
  cxx @1 $Cxx.name("cxx");
}

enum NamedDeclExplicitVisibilityKind @0xbf22a9b63202e46f {
  visibilityForType @0 $Cxx.name("visibility_for_type");
  visibilityForValue @1 $Cxx.name("visibility_for_value");
}

enum OMPDeclareReductionDeclInitKind @0xd48c50a665b4c434 {
  callInitializer @0 $Cxx.name("call_initializer");
  directInitializer @1 $Cxx.name("direct_initializer");
  copyInitializer @2 $Cxx.name("copy_initializer");
}

enum ObjCIvarDeclAccessControl @0x8ccbd3568fbf327d {
  none @0 $Cxx.name("none");
  private @1 $Cxx.name("private");
  protected @2 $Cxx.name("protected");
  public @3 $Cxx.name("public");
  package @4 $Cxx.name("package");
}

enum ObjCMessageExprReceiverKind @0x87cf67c762795198 {
  class @0 $Cxx.name("class");
  instance @1 $Cxx.name("instance");
  superClass @2 $Cxx.name("super_class");
  superInstance @3 $Cxx.name("super_instance");
}

enum ObjCMethodDeclImplementationControl @0xc799746a14d87df8 {
  none @0 $Cxx.name("none");
  required @1 $Cxx.name("required");
  optional @2 $Cxx.name("optional");
}

enum ObjCPropertyDeclPropertyControl @0x99ab582b9b112425 {
  none @0 $Cxx.name("none");
  required @1 $Cxx.name("required");
  optional @2 $Cxx.name("optional");
}

enum ObjCPropertyDeclSetterKind @0xc32919cff7976d3f {
  assign @0 $Cxx.name("assign");
  retain @1 $Cxx.name("retain");
  copy @2 $Cxx.name("copy");
  weak @3 $Cxx.name("weak");
}

enum ObjCPropertyImplDeclKind @0xe041c9aebab7579c {
  synthesize @0 $Cxx.name("synthesize");
  dynamic @1 $Cxx.name("dynamic");
}

enum PredefinedExprIdentKind @0xbf49ced320c54b4e {
  func @0 $Cxx.name("func");
  function @1 $Cxx.name("function");
  lFunction @2 $Cxx.name("l_function");
  funcDName @3 $Cxx.name("func_d_name");
  funcSig @4 $Cxx.name("func_sig");
  lFuncSig @5 $Cxx.name("l_func_sig");
  prettyFunction @6 $Cxx.name("pretty_function");
  prettyFunctionNoVirtual @7 $Cxx.name("pretty_function_no_virtual");
}

enum QualTypeDestructionKind @0xb67f958f72909186 {
  none @0 $Cxx.name("none");
  cxxDestructor @1 $Cxx.name("cxx_destructor");
  objcStrongLifetime @2 $Cxx.name("objc_strong_lifetime");
  objcWeakLifetime @3 $Cxx.name("objc_weak_lifetime");
  nontrivialCStruct @4 $Cxx.name("nontrivial_c_struct");
}

enum QualTypePrimitiveCopyKind @0xb1229b89086f1937 {
  trivial @0 $Cxx.name("trivial");
  volatileTrivial @1 $Cxx.name("volatile_trivial");
  arcStrong @2 $Cxx.name("arc_strong");
  arcWeak @3 $Cxx.name("arc_weak");
  struct @4 $Cxx.name("struct");
}

enum QualTypePrimitiveDefaultInitializeKind @0xd6c7633f16b32289 {
  trivial @0 $Cxx.name("trivial");
  arcStrong @1 $Cxx.name("arc_strong");
  arcWeak @2 $Cxx.name("arc_weak");
  struct @3 $Cxx.name("struct");
}

enum RecordDeclArgPassingKind @0xbec42547911ce41c {
  canPassInRegs @0 $Cxx.name("can_pass_in_regs");
  cannotPassInRegs @1 $Cxx.name("cannot_pass_in_regs");
  canNeverPassInRegs @2 $Cxx.name("can_never_pass_in_regs");
}

enum SourceLocExprIdentKind @0xec16d0af007addef {
  function @0 $Cxx.name("function");
  file @1 $Cxx.name("file");
  line @2 $Cxx.name("line");
  column @3 $Cxx.name("column");
}

enum StmtLikelihood @0xf7120a5833af7ac1 {
  unlikely @0 $Cxx.name("unlikely");
  none @1 $Cxx.name("none");
  likely @2 $Cxx.name("likely");
}

enum StmtKind @0xc9755b9a053563b9 {
  gccAsmStmt @0 $Cxx.name("gcc_asm_stmt");
  msAsmStmt @1 $Cxx.name("ms_asm_stmt");
  breakStmt @2 $Cxx.name("break_stmt");
  cxxCatchStmt @3 $Cxx.name("cxx_catch_stmt");
  cxxForRangeStmt @4 $Cxx.name("cxx_for_range_stmt");
  cxxTryStmt @5 $Cxx.name("cxx_try_stmt");
  capturedStmt @6 $Cxx.name("captured_stmt");
  compoundStmt @7 $Cxx.name("compound_stmt");
  continueStmt @8 $Cxx.name("continue_stmt");
  coreturnStmt @9 $Cxx.name("coreturn_stmt");
  coroutineBodyStmt @10 $Cxx.name("coroutine_body_stmt");
  declStmt @11 $Cxx.name("decl_stmt");
  doStmt @12 $Cxx.name("do_stmt");
  forStmt @13 $Cxx.name("for_stmt");
  gotoStmt @14 $Cxx.name("goto_stmt");
  ifStmt @15 $Cxx.name("if_stmt");
  indirectGotoStmt @16 $Cxx.name("indirect_goto_stmt");
  msDependentExistsStmt @17 $Cxx.name("ms_dependent_exists_stmt");
  nullStmt @18 $Cxx.name("null_stmt");
  ompCanonicalLoop @19 $Cxx.name("omp_canonical_loop");
  ompAtomicDirective @20 $Cxx.name("omp_atomic_directive");
  ompBarrierDirective @21 $Cxx.name("omp_barrier_directive");
  ompCancelDirective @22 $Cxx.name("omp_cancel_directive");
  ompCancellationPointDirective @23 $Cxx.name("omp_cancellation_point_directive");
  ompCriticalDirective @24 $Cxx.name("omp_critical_directive");
  ompDepobjDirective @25 $Cxx.name("omp_depobj_directive");
  ompDispatchDirective @26 $Cxx.name("omp_dispatch_directive");
  ompFlushDirective @27 $Cxx.name("omp_flush_directive");
  ompInteropDirective @28 $Cxx.name("omp_interop_directive");
  ompDistributeDirective @29 $Cxx.name("omp_distribute_directive");
  ompDistributeParallelForDirective @30 $Cxx.name("omp_distribute_parallel_for_directive");
  ompDistributeParallelForSimdDirective @31 $Cxx.name("omp_distribute_parallel_for_simd_directive");
  ompDistributeSimdDirective @32 $Cxx.name("omp_distribute_simd_directive");
  ompForDirective @33 $Cxx.name("omp_for_directive");
  ompForSimdDirective @34 $Cxx.name("omp_for_simd_directive");
  ompMasterTaskLoopDirective @35 $Cxx.name("omp_master_task_loop_directive");
  ompMasterTaskLoopSimdDirective @36 $Cxx.name("omp_master_task_loop_simd_directive");
  ompParallelForDirective @37 $Cxx.name("omp_parallel_for_directive");
  ompParallelForSimdDirective @38 $Cxx.name("omp_parallel_for_simd_directive");
  ompParallelMasterTaskLoopDirective @39 $Cxx.name("omp_parallel_master_task_loop_directive");
  ompParallelMasterTaskLoopSimdDirective @40 $Cxx.name("omp_parallel_master_task_loop_simd_directive");
  ompSimdDirective @41 $Cxx.name("omp_simd_directive");
  ompTargetParallelForSimdDirective @42 $Cxx.name("omp_target_parallel_for_simd_directive");
  ompTargetSimdDirective @43 $Cxx.name("omp_target_simd_directive");
  ompTargetTeamsDistributeDirective @44 $Cxx.name("omp_target_teams_distribute_directive");
  ompTargetTeamsDistributeParallelForDirective @45 $Cxx.name("omp_target_teams_distribute_parallel_for_directive");
  ompTargetTeamsDistributeParallelForSimdDirective @46 $Cxx.name("omp_target_teams_distribute_parallel_for_simd_directive");
  ompTargetTeamsDistributeSimdDirective @47 $Cxx.name("omp_target_teams_distribute_simd_directive");
  ompTaskLoopDirective @48 $Cxx.name("omp_task_loop_directive");
  ompTaskLoopSimdDirective @49 $Cxx.name("omp_task_loop_simd_directive");
  ompTeamsDistributeDirective @50 $Cxx.name("omp_teams_distribute_directive");
  ompTeamsDistributeParallelForDirective @51 $Cxx.name("omp_teams_distribute_parallel_for_directive");
  ompTeamsDistributeParallelForSimdDirective @52 $Cxx.name("omp_teams_distribute_parallel_for_simd_directive");
  ompTeamsDistributeSimdDirective @53 $Cxx.name("omp_teams_distribute_simd_directive");
  ompTileDirective @54 $Cxx.name("omp_tile_directive");
  ompUnrollDirective @55 $Cxx.name("omp_unroll_directive");
  ompMaskedDirective @56 $Cxx.name("omp_masked_directive");
  ompMasterDirective @57 $Cxx.name("omp_master_directive");
  ompOrderedDirective @58 $Cxx.name("omp_ordered_directive");
  ompParallelDirective @59 $Cxx.name("omp_parallel_directive");
  ompParallelMasterDirective @60 $Cxx.name("omp_parallel_master_directive");
  ompParallelSectionsDirective @61 $Cxx.name("omp_parallel_sections_directive");
  ompScanDirective @62 $Cxx.name("omp_scan_directive");
  ompSectionDirective @63 $Cxx.name("omp_section_directive");
  ompSectionsDirective @64 $Cxx.name("omp_sections_directive");
  ompSingleDirective @65 $Cxx.name("omp_single_directive");
  ompTargetDataDirective @66 $Cxx.name("omp_target_data_directive");
  ompTargetDirective @67 $Cxx.name("omp_target_directive");
  ompTargetEnterDataDirective @68 $Cxx.name("omp_target_enter_data_directive");
  ompTargetExitDataDirective @69 $Cxx.name("omp_target_exit_data_directive");
  ompTargetParallelDirective @70 $Cxx.name("omp_target_parallel_directive");
  ompTargetParallelForDirective @71 $Cxx.name("omp_target_parallel_for_directive");
  ompTargetTeamsDirective @72 $Cxx.name("omp_target_teams_directive");
  ompTargetUpdateDirective @73 $Cxx.name("omp_target_update_directive");
  ompTaskDirective @74 $Cxx.name("omp_task_directive");
  ompTaskgroupDirective @75 $Cxx.name("omp_taskgroup_directive");
  ompTaskwaitDirective @76 $Cxx.name("omp_taskwait_directive");
  ompTaskyieldDirective @77 $Cxx.name("omp_taskyield_directive");
  ompTeamsDirective @78 $Cxx.name("omp_teams_directive");
  objCAtCatchStmt @79 $Cxx.name("obj_c_at_catch_stmt");
  objCAtFinallyStmt @80 $Cxx.name("obj_c_at_finally_stmt");
  objCAtSynchronizedStmt @81 $Cxx.name("obj_c_at_synchronized_stmt");
  objCAtThrowStmt @82 $Cxx.name("obj_c_at_throw_stmt");
  objCAtTryStmt @83 $Cxx.name("obj_c_at_try_stmt");
  objCAutoreleasePoolStmt @84 $Cxx.name("obj_c_autorelease_pool_stmt");
  objCForCollectionStmt @85 $Cxx.name("obj_c_for_collection_stmt");
  returnStmt @86 $Cxx.name("return_stmt");
  sehExceptStmt @87 $Cxx.name("seh_except_stmt");
  sehFinallyStmt @88 $Cxx.name("seh_finally_stmt");
  sehLeaveStmt @89 $Cxx.name("seh_leave_stmt");
  sehTryStmt @90 $Cxx.name("seh_try_stmt");
  caseStmt @91 $Cxx.name("case_stmt");
  defaultStmt @92 $Cxx.name("default_stmt");
  switchStmt @93 $Cxx.name("switch_stmt");
  attributedStmt @94 $Cxx.name("attributed_stmt");
  binaryConditionalOperator @95 $Cxx.name("binary_conditional_operator");
  conditionalOperator @96 $Cxx.name("conditional_operator");
  addrLabelExpr @97 $Cxx.name("addr_label_expr");
  arrayInitIndexExpr @98 $Cxx.name("array_init_index_expr");
  arrayInitLoopExpr @99 $Cxx.name("array_init_loop_expr");
  arraySubscriptExpr @100 $Cxx.name("array_subscript_expr");
  arrayTypeTraitExpr @101 $Cxx.name("array_type_trait_expr");
  asTypeExpr @102 $Cxx.name("as_type_expr");
  atomicExpr @103 $Cxx.name("atomic_expr");
  binaryOperator @104 $Cxx.name("binary_operator");
  compoundAssignOperator @105 $Cxx.name("compound_assign_operator");
  blockExpr @106 $Cxx.name("block_expr");
  cxxBindTemporaryExpr @107 $Cxx.name("cxx_bind_temporary_expr");
  cxxBoolLiteralExpr @108 $Cxx.name("cxx_bool_literal_expr");
  cxxConstructExpr @109 $Cxx.name("cxx_construct_expr");
  cxxTemporaryObjectExpr @110 $Cxx.name("cxx_temporary_object_expr");
  cxxDefaultArgExpr @111 $Cxx.name("cxx_default_arg_expr");
  cxxDefaultInitExpr @112 $Cxx.name("cxx_default_init_expr");
  cxxDeleteExpr @113 $Cxx.name("cxx_delete_expr");
  cxxDependentScopeMemberExpr @114 $Cxx.name("cxx_dependent_scope_member_expr");
  cxxFoldExpr @115 $Cxx.name("cxx_fold_expr");
  cxxInheritedCtorInitExpr @116 $Cxx.name("cxx_inherited_ctor_init_expr");
  cxxNewExpr @117 $Cxx.name("cxx_new_expr");
  cxxNoexceptExpr @118 $Cxx.name("cxx_noexcept_expr");
  cxxNullPtrLiteralExpr @119 $Cxx.name("cxx_null_ptr_literal_expr");
  cxxPseudoDestructorExpr @120 $Cxx.name("cxx_pseudo_destructor_expr");
  cxxRewrittenBinaryOperator @121 $Cxx.name("cxx_rewritten_binary_operator");
  cxxScalarValueInitExpr @122 $Cxx.name("cxx_scalar_value_init_expr");
  cxxStdInitializerListExpr @123 $Cxx.name("cxx_std_initializer_list_expr");
  cxxThisExpr @124 $Cxx.name("cxx_this_expr");
  cxxThrowExpr @125 $Cxx.name("cxx_throw_expr");
  cxxTypeidExpr @126 $Cxx.name("cxx_typeid_expr");
  cxxUnresolvedConstructExpr @127 $Cxx.name("cxx_unresolved_construct_expr");
  cxxUuidofExpr @128 $Cxx.name("cxx_uuidof_expr");
  callExpr @129 $Cxx.name("call_expr");
  cudaKernelCallExpr @130 $Cxx.name("cuda_kernel_call_expr");
  cxxMemberCallExpr @131 $Cxx.name("cxx_member_call_expr");
  cxxOperatorCallExpr @132 $Cxx.name("cxx_operator_call_expr");
  userDefinedLiteral @133 $Cxx.name("user_defined_literal");
  builtinBitCastExpr @134 $Cxx.name("builtin_bit_cast_expr");
  cStyleCastExpr @135 $Cxx.name("c_style_cast_expr");
  cxxFunctionalCastExpr @136 $Cxx.name("cxx_functional_cast_expr");
  cxxAddrspaceCastExpr @137 $Cxx.name("cxx_addrspace_cast_expr");
  cxxConstCastExpr @138 $Cxx.name("cxx_const_cast_expr");
  cxxDynamicCastExpr @139 $Cxx.name("cxx_dynamic_cast_expr");
  cxxReinterpretCastExpr @140 $Cxx.name("cxx_reinterpret_cast_expr");
  cxxStaticCastExpr @141 $Cxx.name("cxx_static_cast_expr");
  objCBridgedCastExpr @142 $Cxx.name("obj_c_bridged_cast_expr");
  implicitCastExpr @143 $Cxx.name("implicit_cast_expr");
  characterLiteral @144 $Cxx.name("character_literal");
  chooseExpr @145 $Cxx.name("choose_expr");
  compoundLiteralExpr @146 $Cxx.name("compound_literal_expr");
  conceptSpecializationExpr @147 $Cxx.name("concept_specialization_expr");
  convertVectorExpr @148 $Cxx.name("convert_vector_expr");
  coawaitExpr @149 $Cxx.name("coawait_expr");
  coyieldExpr @150 $Cxx.name("coyield_expr");
  declRefExpr @151 $Cxx.name("decl_ref_expr");
  dependentCoawaitExpr @152 $Cxx.name("dependent_coawait_expr");
  dependentScopeDeclRefExpr @153 $Cxx.name("dependent_scope_decl_ref_expr");
  designatedInitExpr @154 $Cxx.name("designated_init_expr");
  designatedInitUpdateExpr @155 $Cxx.name("designated_init_update_expr");
  expressionTraitExpr @156 $Cxx.name("expression_trait_expr");
  extVectorElementExpr @157 $Cxx.name("ext_vector_element_expr");
  fixedPointLiteral @158 $Cxx.name("fixed_point_literal");
  floatingLiteral @159 $Cxx.name("floating_literal");
  constantExpr @160 $Cxx.name("constant_expr");
  exprWithCleanups @161 $Cxx.name("expr_with_cleanups");
  functionParmPackExpr @162 $Cxx.name("function_parm_pack_expr");
  gnuNullExpr @163 $Cxx.name("gnu_null_expr");
  genericSelectionExpr @164 $Cxx.name("generic_selection_expr");
  imaginaryLiteral @165 $Cxx.name("imaginary_literal");
  implicitValueInitExpr @166 $Cxx.name("implicit_value_init_expr");
  initListExpr @167 $Cxx.name("init_list_expr");
  integerLiteral @168 $Cxx.name("integer_literal");
  lambdaExpr @169 $Cxx.name("lambda_expr");
  msPropertyRefExpr @170 $Cxx.name("ms_property_ref_expr");
  msPropertySubscriptExpr @171 $Cxx.name("ms_property_subscript_expr");
  materializeTemporaryExpr @172 $Cxx.name("materialize_temporary_expr");
  matrixSubscriptExpr @173 $Cxx.name("matrix_subscript_expr");
  memberExpr @174 $Cxx.name("member_expr");
  noInitExpr @175 $Cxx.name("no_init_expr");
  ompArraySectionExpr @176 $Cxx.name("omp_array_section_expr");
  ompArrayShapingExpr @177 $Cxx.name("omp_array_shaping_expr");
  ompIteratorExpr @178 $Cxx.name("omp_iterator_expr");
  objCArrayLiteral @179 $Cxx.name("obj_c_array_literal");
  objCAvailabilityCheckExpr @180 $Cxx.name("obj_c_availability_check_expr");
  objCBoolLiteralExpr @181 $Cxx.name("obj_c_bool_literal_expr");
  objCBoxedExpr @182 $Cxx.name("obj_c_boxed_expr");
  objCDictionaryLiteral @183 $Cxx.name("obj_c_dictionary_literal");
  objCEncodeExpr @184 $Cxx.name("obj_c_encode_expr");
  objCIndirectCopyRestoreExpr @185 $Cxx.name("obj_c_indirect_copy_restore_expr");
  objCIsaExpr @186 $Cxx.name("obj_c_isa_expr");
  objCIvarRefExpr @187 $Cxx.name("obj_c_ivar_ref_expr");
  objCMessageExpr @188 $Cxx.name("obj_c_message_expr");
  objCPropertyRefExpr @189 $Cxx.name("obj_c_property_ref_expr");
  objCProtocolExpr @190 $Cxx.name("obj_c_protocol_expr");
  objCSelectorExpr @191 $Cxx.name("obj_c_selector_expr");
  objCStringLiteral @192 $Cxx.name("obj_c_string_literal");
  objCSubscriptRefExpr @193 $Cxx.name("obj_c_subscript_ref_expr");
  offsetOfExpr @194 $Cxx.name("offset_of_expr");
  opaqueValueExpr @195 $Cxx.name("opaque_value_expr");
  unresolvedLookupExpr @196 $Cxx.name("unresolved_lookup_expr");
  unresolvedMemberExpr @197 $Cxx.name("unresolved_member_expr");
  packExpansionExpr @198 $Cxx.name("pack_expansion_expr");
  parenExpr @199 $Cxx.name("paren_expr");
  parenListExpr @200 $Cxx.name("paren_list_expr");
  predefinedExpr @201 $Cxx.name("predefined_expr");
  pseudoObjectExpr @202 $Cxx.name("pseudo_object_expr");
  recoveryExpr @203 $Cxx.name("recovery_expr");
  requiresExpr @204 $Cxx.name("requires_expr");
  syclUniqueStableNameExpr @205 $Cxx.name("sycl_unique_stable_name_expr");
  shuffleVectorExpr @206 $Cxx.name("shuffle_vector_expr");
  sizeOfPackExpr @207 $Cxx.name("size_of_pack_expr");
  sourceLocExpr @208 $Cxx.name("source_loc_expr");
  stmtExpr @209 $Cxx.name("stmt_expr");
  stringLiteral @210 $Cxx.name("string_literal");
  substNonTypeTemplateParmExpr @211 $Cxx.name("subst_non_type_template_parm_expr");
  substNonTypeTemplateParmPackExpr @212 $Cxx.name("subst_non_type_template_parm_pack_expr");
  typeTraitExpr @213 $Cxx.name("type_trait_expr");
  typoExpr @214 $Cxx.name("typo_expr");
  unaryExprOrTypeTraitExpr @215 $Cxx.name("unary_expr_or_type_trait_expr");
  unaryOperator @216 $Cxx.name("unary_operator");
  vaArgExpr @217 $Cxx.name("va_arg_expr");
  labelStmt @218 $Cxx.name("label_stmt");
  whileStmt @219 $Cxx.name("while_stmt");
}

enum StringLiteralStringKind @0xbde9cca58b227666 {
  ascii @0 $Cxx.name("ascii");
  wide @1 $Cxx.name("wide");
  utF8 @2 $Cxx.name("ut_f8");
  utF16 @3 $Cxx.name("ut_f16");
  utF32 @4 $Cxx.name("ut_f32");
}

enum TemplateArgumentKind @0xf54459e1b953e2aa {
  empty @0 $Cxx.name("empty");
  type @1 $Cxx.name("type");
  declaration @2 $Cxx.name("declaration");
  nullPointer @3 $Cxx.name("null_pointer");
  integral @4 $Cxx.name("integral");
  template @5 $Cxx.name("template");
  templateExpansion @6 $Cxx.name("template_expansion");
  expression @7 $Cxx.name("expression");
  pack @8 $Cxx.name("pack");
}

enum TypeScalarTypeKind @0xb29bd5077056707b {
  cPointer @0 $Cxx.name("c_pointer");
  blockPointer @1 $Cxx.name("block_pointer");
  objCObjectPointer @2 $Cxx.name("obj_c_object_pointer");
  memberPointer @3 $Cxx.name("member_pointer");
  boolean @4 $Cxx.name("boolean");
  integral @5 $Cxx.name("integral");
  floating @6 $Cxx.name("floating");
  integralComplex @7 $Cxx.name("integral_complex");
  floatingComplex @8 $Cxx.name("floating_complex");
  fixedPoint @9 $Cxx.name("fixed_point");
}

enum TypeKind @0x8eb229be4c525aa3 {
  adjusted @0 $Cxx.name("adjusted");
  decayed @1 $Cxx.name("decayed");
  constantArray @2 $Cxx.name("constant_array");
  dependentSizedArray @3 $Cxx.name("dependent_sized_array");
  incompleteArray @4 $Cxx.name("incomplete_array");
  variableArray @5 $Cxx.name("variable_array");
  atomic @6 $Cxx.name("atomic");
  attributed @7 $Cxx.name("attributed");
  blockPointer @8 $Cxx.name("block_pointer");
  builtin @9 $Cxx.name("builtin");
  complex @10 $Cxx.name("complex");
  decltype @11 $Cxx.name("decltype");
  auto @12 $Cxx.name("auto");
  deducedTemplateSpecialization @13 $Cxx.name("deduced_template_specialization");
  dependentAddressSpace @14 $Cxx.name("dependent_address_space");
  dependentExtInt @15 $Cxx.name("dependent_ext_int");
  dependentName @16 $Cxx.name("dependent_name");
  dependentSizedExtVector @17 $Cxx.name("dependent_sized_ext_vector");
  dependentTemplateSpecialization @18 $Cxx.name("dependent_template_specialization");
  dependentVector @19 $Cxx.name("dependent_vector");
  elaborated @20 $Cxx.name("elaborated");
  extInt @21 $Cxx.name("ext_int");
  functionNoProto @22 $Cxx.name("function_no_proto");
  functionProto @23 $Cxx.name("function_proto");
  injectedClassName @24 $Cxx.name("injected_class_name");
  macroQualified @25 $Cxx.name("macro_qualified");
  constantMatrix @26 $Cxx.name("constant_matrix");
  dependentSizedMatrix @27 $Cxx.name("dependent_sized_matrix");
  memberPointer @28 $Cxx.name("member_pointer");
  objCObjectPointer @29 $Cxx.name("obj_c_object_pointer");
  objCObject @30 $Cxx.name("obj_c_object");
  objCInterface @31 $Cxx.name("obj_c_interface");
  objCTypeParam @32 $Cxx.name("obj_c_type_param");
  packExpansion @33 $Cxx.name("pack_expansion");
  paren @34 $Cxx.name("paren");
  pipe @35 $Cxx.name("pipe");
  pointer @36 $Cxx.name("pointer");
  lValueReference @37 $Cxx.name("l_value_reference");
  rValueReference @38 $Cxx.name("r_value_reference");
  substTemplateTypeParmPack @39 $Cxx.name("subst_template_type_parm_pack");
  substTemplateTypeParm @40 $Cxx.name("subst_template_type_parm");
  enum @41 $Cxx.name("enum");
  record @42 $Cxx.name("record");
  templateSpecialization @43 $Cxx.name("template_specialization");
  templateTypeParm @44 $Cxx.name("template_type_parm");
  typeOfExpr @45 $Cxx.name("type_of_expr");
  typeOf @46 $Cxx.name("type_of");
  typedef @47 $Cxx.name("typedef");
  unaryTransform @48 $Cxx.name("unary_transform");
  unresolvedUsing @49 $Cxx.name("unresolved_using");
  vector @50 $Cxx.name("vector");
  extVector @51 $Cxx.name("ext_vector");
}

enum UnaryTransformTypeUTTKind @0xac82f433159c374e {
  enumUnderlyingType @0 $Cxx.name("enum_underlying_type");
}

enum UserDefinedLiteralLiteralOperatorKind @0x8135eca6c9cc66e4 {
  raw @0 $Cxx.name("raw");
  template @1 $Cxx.name("template");
  integer @2 $Cxx.name("integer");
  floating @3 $Cxx.name("floating");
  string @4 $Cxx.name("string");
  character @5 $Cxx.name("character");
}

enum VarDeclDefinitionKind @0xe332c76b6d1d3e37 {
  declarationOnly @0 $Cxx.name("declaration_only");
  tentativeDefinition @1 $Cxx.name("tentative_definition");
  definition @2 $Cxx.name("definition");
}

enum VarDeclInitializationStyle @0x88cefeefc7e74217 {
  cInit @0 $Cxx.name("c_init");
  callInitializer @1 $Cxx.name("call_initializer");
  listInitializer @2 $Cxx.name("list_initializer");
}

enum VarDeclTLSKind @0xac49397b15ce1472 {
  none @0 $Cxx.name("none");
  static @1 $Cxx.name("static");
  dynamic @2 $Cxx.name("dynamic");
}

enum VectorTypeVectorKind @0xce32479a723baa9b {
  genericVector @0 $Cxx.name("generic_vector");
  altiVecVector @1 $Cxx.name("alti_vec_vector");
  altiVecPixel @2 $Cxx.name("alti_vec_pixel");
  altiVecBoolean @3 $Cxx.name("alti_vec_boolean");
  neonVector @4 $Cxx.name("neon_vector");
  neonPolyVector @5 $Cxx.name("neon_poly_vector");
  sveFixedLengthDataVector @6 $Cxx.name("sve_fixed_length_data_vector");
  sveFixedLengthPredicateVector @7 $Cxx.name("sve_fixed_length_predicate_vector");
}

enum ASTDumpOutputFormat @0xaec5d60a9e3cb42b {
  default @0 $Cxx.name("default");
  json @1 $Cxx.name("json");
}

enum AccessSpecifier @0xea31fabcef869ac6 {
  public @0 $Cxx.name("public");
  protected @1 $Cxx.name("protected");
  private @2 $Cxx.name("private");
  none @3 $Cxx.name("none");
}

enum AddrSpaceMapMangling @0xde742feea4951eb4 {
  target @0 $Cxx.name("target");
  on @1 $Cxx.name("on");
  off @2 $Cxx.name("off");
}

enum AllocatorTypeTy @0x83bf462d99efede2 {
  ompNullMemoryAlloc @0 $Cxx.name("omp_null_memory_alloc");
  ompDefaultMemoryAlloc @1 $Cxx.name("omp_default_memory_alloc");
  ompLargeCapMemoryAlloc @2 $Cxx.name("omp_large_cap_memory_alloc");
  ompConstMemoryAlloc @3 $Cxx.name("omp_const_memory_alloc");
  ompHighBwMemoryAlloc @4 $Cxx.name("omp_high_bw_memory_alloc");
  ompLowLatMemoryAlloc @5 $Cxx.name("omp_low_lat_memory_alloc");
  ompcGroupMemoryAlloc @6 $Cxx.name("ompc_group_memory_alloc");
  omppTeamMemoryAlloc @7 $Cxx.name("ompp_team_memory_alloc");
  ompThreadMemoryAlloc @8 $Cxx.name("omp_thread_memory_alloc");
  ompUserDefinedMemoryAlloc @9 $Cxx.name("omp_user_defined_memory_alloc");
}

enum AltivecSrcCompatKind @0x8c349d9881ec7b8f {
  mixed @0 $Cxx.name("mixed");
  gcc @1 $Cxx.name("gcc");
  xl @2 $Cxx.name("xl");
  # Skipped repeat pasta::kDefault
}

enum ArgumentKind @0xdb7d5e1e19e8e847 {
  stdString @0 $Cxx.name("std_string");
  cString @1 $Cxx.name("c_string");
  sint @2 $Cxx.name("sint");
  uint @3 $Cxx.name("uint");
  tokenkind @4 $Cxx.name("tokenkind");
  identifierinfo @5 $Cxx.name("identifierinfo");
  addrspace @6 $Cxx.name("addrspace");
  qualified @7 $Cxx.name("qualified");
  qualtype @8 $Cxx.name("qualtype");
  declarationname @9 $Cxx.name("declarationname");
  nameddecl @10 $Cxx.name("nameddecl");
  nestednamespec @11 $Cxx.name("nestednamespec");
  declcontext @12 $Cxx.name("declcontext");
  qualtypePair @13 $Cxx.name("qualtype_pair");
  attribute @14 $Cxx.name("attribute");
}

enum ArrayTypeTrait @0xd6960ffdc6f9f29f {
  arrayRank @0 $Cxx.name("array_rank");
  arrayExtent @1 $Cxx.name("array_extent");
}

enum AtomicScopeModelKind @0x993fec1348243c85 {
  none @0 $Cxx.name("none");
  openCl @1 $Cxx.name("open_cl");
}

enum AttributeKind @0xea12979c4469acdf {
  addressSpace @0 $Cxx.name("address_space");
  armMveStrictPolymorphism @1 $Cxx.name("arm_mve_strict_polymorphism");
  cmseNsCall @2 $Cxx.name("cmse_ns_call");
  noDeref @3 $Cxx.name("no_deref");
  objCgc @4 $Cxx.name("obj_cgc");
  objCInertUnsafeUnretained @5 $Cxx.name("obj_c_inert_unsafe_unretained");
  objCKindOf @6 $Cxx.name("obj_c_kind_of");
  openClConstantAddressSpace @7 $Cxx.name("open_cl_constant_address_space");
  openClGenericAddressSpace @8 $Cxx.name("open_cl_generic_address_space");
  openClGlobalAddressSpace @9 $Cxx.name("open_cl_global_address_space");
  openClGlobalDeviceAddressSpace @10 $Cxx.name("open_cl_global_device_address_space");
  openClGlobalHostAddressSpace @11 $Cxx.name("open_cl_global_host_address_space");
  openClLocalAddressSpace @12 $Cxx.name("open_cl_local_address_space");
  openClPrivateAddressSpace @13 $Cxx.name("open_cl_private_address_space");
  ptr32 @14 $Cxx.name("ptr32");
  ptr64 @15 $Cxx.name("ptr64");
  sPtr @16 $Cxx.name("s_ptr");
  typeNonNull @17 $Cxx.name("type_non_null");
  typeNullUnspecified @18 $Cxx.name("type_null_unspecified");
  typeNullable @19 $Cxx.name("type_nullable");
  typeNullableResult @20 $Cxx.name("type_nullable_result");
  uPtr @21 $Cxx.name("u_ptr");
  fallThrough @22 $Cxx.name("fall_through");
  likely @23 $Cxx.name("likely");
  mustTail @24 $Cxx.name("must_tail");
  openClUnrollHint @25 $Cxx.name("open_cl_unroll_hint");
  suppress @26 $Cxx.name("suppress");
  unlikely @27 $Cxx.name("unlikely");
  noMerge @28 $Cxx.name("no_merge");
  aArch64VectorPcs @29 $Cxx.name("a_arch64_vector_pcs");
  acquireHandle @30 $Cxx.name("acquire_handle");
  anyX86NoCfCheck @31 $Cxx.name("any_x86_no_cf_check");
  cDecl @32 $Cxx.name("c_decl");
  fastCall @33 $Cxx.name("fast_call");
  intelOclBicc @34 $Cxx.name("intel_ocl_bicc");
  lifetimeBound @35 $Cxx.name("lifetime_bound");
  msabi @36 $Cxx.name("msabi");
  nsReturnsRetained @37 $Cxx.name("ns_returns_retained");
  objCOwnership @38 $Cxx.name("obj_c_ownership");
  pascal @39 $Cxx.name("pascal");
  pcs @40 $Cxx.name("pcs");
  preserveAll @41 $Cxx.name("preserve_all");
  preserveMost @42 $Cxx.name("preserve_most");
  regCall @43 $Cxx.name("reg_call");
  stdCall @44 $Cxx.name("std_call");
  swiftAsyncCall @45 $Cxx.name("swift_async_call");
  swiftCall @46 $Cxx.name("swift_call");
  sysVabi @47 $Cxx.name("sys_vabi");
  thisCall @48 $Cxx.name("this_call");
  vectorCall @49 $Cxx.name("vector_call");
  swiftAsyncContext @50 $Cxx.name("swift_async_context");
  swiftContext @51 $Cxx.name("swift_context");
  swiftErrorResult @52 $Cxx.name("swift_error_result");
  swiftIndirectResult @53 $Cxx.name("swift_indirect_result");
  annotate @54 $Cxx.name("annotate");
  cfConsumed @55 $Cxx.name("cf_consumed");
  carriesDependency @56 $Cxx.name("carries_dependency");
  nsConsumed @57 $Cxx.name("ns_consumed");
  nonNull @58 $Cxx.name("non_null");
  osConsumed @59 $Cxx.name("os_consumed");
  passObjectSize @60 $Cxx.name("pass_object_size");
  releaseHandle @61 $Cxx.name("release_handle");
  useHandle @62 $Cxx.name("use_handle");
  amdgpuFlatWorkGroupSize @63 $Cxx.name("amdgpu_flat_work_group_size");
  amdgpuNumSgpr @64 $Cxx.name("amdgpu_num_sgpr");
  amdgpuNumVgpr @65 $Cxx.name("amdgpu_num_vgpr");
  amdgpuWavesPerEu @66 $Cxx.name("amdgpu_waves_per_eu");
  armInterrupt @67 $Cxx.name("arm_interrupt");
  avrInterrupt @68 $Cxx.name("avr_interrupt");
  avrSignal @69 $Cxx.name("avr_signal");
  acquireCapability @70 $Cxx.name("acquire_capability");
  acquiredAfter @71 $Cxx.name("acquired_after");
  acquiredBefore @72 $Cxx.name("acquired_before");
  alignMac68UcK @73 $Cxx.name("align_mac68_k");
  alignNatural @74 $Cxx.name("align_natural");
  aligned @75 $Cxx.name("aligned");
  allocAlign @76 $Cxx.name("alloc_align");
  allocSize @77 $Cxx.name("alloc_size");
  alwaysDestroy @78 $Cxx.name("always_destroy");
  alwaysInline @79 $Cxx.name("always_inline");
  analyzerNoReturn @80 $Cxx.name("analyzer_no_return");
  anyX86Interrupt @81 $Cxx.name("any_x86_interrupt");
  anyX86NoCallerSavedRegisters @82 $Cxx.name("any_x86_no_caller_saved_registers");
  arcWeakrefUnavailable @83 $Cxx.name("arc_weakref_unavailable");
  argumentWithTypeTag @84 $Cxx.name("argument_with_type_tag");
  armBuiltinAlias @85 $Cxx.name("arm_builtin_alias");
  artificial @86 $Cxx.name("artificial");
  assemblyLabel @87 $Cxx.name("assembly_label");
  assertCapability @88 $Cxx.name("assert_capability");
  assertExclusiveLock @89 $Cxx.name("assert_exclusive_lock");
  assertSharedLock @90 $Cxx.name("assert_shared_lock");
  assumeAligned @91 $Cxx.name("assume_aligned");
  assumption @92 $Cxx.name("assumption");
  availability @93 $Cxx.name("availability");
  bpfPreserveAccessIndex @94 $Cxx.name("bpf_preserve_access_index");
  blocks @95 $Cxx.name("blocks");
  builtin @96 $Cxx.name("builtin");
  c11NoReturn @97 $Cxx.name("c11_no_return");
  cfAuditedTransfer @98 $Cxx.name("cf_audited_transfer");
  cfGuard @99 $Cxx.name("cf_guard");
  cfiCanonicalJumpTable @100 $Cxx.name("cfi_canonical_jump_table");
  cfReturnsNotRetained @101 $Cxx.name("cf_returns_not_retained");
  cfReturnsRetained @102 $Cxx.name("cf_returns_retained");
  cfUnknownTransfer @103 $Cxx.name("cf_unknown_transfer");
  cpuDispatch @104 $Cxx.name("cpu_dispatch");
  cpuSpecific @105 $Cxx.name("cpu_specific");
  cudaConstant @106 $Cxx.name("cuda_constant");
  cudaDevice @107 $Cxx.name("cuda_device");
  cudaDeviceBuiltinSurfaceType @108 $Cxx.name("cuda_device_builtin_surface_type");
  cudaDeviceBuiltinTextureType @109 $Cxx.name("cuda_device_builtin_texture_type");
  cudaGlobal @110 $Cxx.name("cuda_global");
  cudaHost @111 $Cxx.name("cuda_host");
  cudaInvalidTarget @112 $Cxx.name("cuda_invalid_target");
  cudaLaunchBounds @113 $Cxx.name("cuda_launch_bounds");
  cudaShared @114 $Cxx.name("cuda_shared");
  cxX11NoReturn @115 $Cxx.name("cx_x11_no_return");
  callableWhen @116 $Cxx.name("callable_when");
  callback @117 $Cxx.name("callback");
  capability @118 $Cxx.name("capability");
  capturedRecord @119 $Cxx.name("captured_record");
  cleanup @120 $Cxx.name("cleanup");
  cmseNsEntry @121 $Cxx.name("cmse_ns_entry");
  codeSeg @122 $Cxx.name("code_seg");
  cold @123 $Cxx.name("cold");
  common @124 $Cxx.name("common");
  const @125 $Cxx.name("const");
  constInitializer @126 $Cxx.name("const_initializer");
  constructor @127 $Cxx.name("constructor");
  consumable @128 $Cxx.name("consumable");
  consumableAutoCast @129 $Cxx.name("consumable_auto_cast");
  consumableSetOnRead @130 $Cxx.name("consumable_set_on_read");
  convergent @131 $Cxx.name("convergent");
  dllExport @132 $Cxx.name("dll_export");
  dllExportStaticLocal @133 $Cxx.name("dll_export_static_local");
  dllImport @134 $Cxx.name("dll_import");
  dllImportStaticLocal @135 $Cxx.name("dll_import_static_local");
  deprecated @136 $Cxx.name("deprecated");
  destructor @137 $Cxx.name("destructor");
  diagnoseIf @138 $Cxx.name("diagnose_if");
  disableTailCalls @139 $Cxx.name("disable_tail_calls");
  emptyBases @140 $Cxx.name("empty_bases");
  enableIf @141 $Cxx.name("enable_if");
  enforceTcb @142 $Cxx.name("enforce_tcb");
  enforceTcbLeaf @143 $Cxx.name("enforce_tcb_leaf");
  enumExtensibility @144 $Cxx.name("enum_extensibility");
  excludeFromExplicitInstantiation @145 $Cxx.name("exclude_from_explicit_instantiation");
  exclusiveTrylockFunction @146 $Cxx.name("exclusive_trylock_function");
  externalSourceSymbol @147 $Cxx.name("external_source_symbol");
  final @148 $Cxx.name("final");
  flagEnum @149 $Cxx.name("flag_enum");
  flatten @150 $Cxx.name("flatten");
  format @151 $Cxx.name("format");
  formatArgument @152 $Cxx.name("format_argument");
  gnuInline @153 $Cxx.name("gnu_inline");
  guardedBy @154 $Cxx.name("guarded_by");
  guardedVariable @155 $Cxx.name("guarded_variable");
  hipManaged @156 $Cxx.name("hip_managed");
  hot @157 $Cxx.name("hot");
  ibAction @158 $Cxx.name("ib_action");
  ibOutlet @159 $Cxx.name("ib_outlet");
  ibOutletCollection @160 $Cxx.name("ib_outlet_collection");
  initializerPriority @161 $Cxx.name("initializer_priority");
  internalLinkage @162 $Cxx.name("internal_linkage");
  ltoVisibilityPublic @163 $Cxx.name("lto_visibility_public");
  layoutVersion @164 $Cxx.name("layout_version");
  leaf @165 $Cxx.name("leaf");
  lockReturned @166 $Cxx.name("lock_returned");
  locksExcluded @167 $Cxx.name("locks_excluded");
  m68Kinterrupt @168 $Cxx.name("m68_kinterrupt");
  migServerRoutine @169 $Cxx.name("mig_server_routine");
  msAllocator @170 $Cxx.name("ms_allocator");
  msInheritance @171 $Cxx.name("ms_inheritance");
  msNoVTable @172 $Cxx.name("ms_no_v_table");
  msP430Interrupt @173 $Cxx.name("ms_p430_interrupt");
  msStruct @174 $Cxx.name("ms_struct");
  msVtorDisp @175 $Cxx.name("ms_vtor_disp");
  maxFieldAlignment @176 $Cxx.name("max_field_alignment");
  mayAlias @177 $Cxx.name("may_alias");
  microMips @178 $Cxx.name("micro_mips");
  minSize @179 $Cxx.name("min_size");
  minVectorWidth @180 $Cxx.name("min_vector_width");
  mips16 @181 $Cxx.name("mips16");
  mipsInterrupt @182 $Cxx.name("mips_interrupt");
  mipsLongCall @183 $Cxx.name("mips_long_call");
  mipsShortCall @184 $Cxx.name("mips_short_call");
  nsConsumesSelf @185 $Cxx.name("ns_consumes_self");
  nsErrorDomain @186 $Cxx.name("ns_error_domain");
  nsReturnsAutoreleased @187 $Cxx.name("ns_returns_autoreleased");
  nsReturnsNotRetained @188 $Cxx.name("ns_returns_not_retained");
  naked @189 $Cxx.name("naked");
  noAlias @190 $Cxx.name("no_alias");
  noCommon @191 $Cxx.name("no_common");
  noDebug @192 $Cxx.name("no_debug");
  noDestroy @193 $Cxx.name("no_destroy");
  noDuplicate @194 $Cxx.name("no_duplicate");
  noInline @195 $Cxx.name("no_inline");
  noInstrumentFunction @196 $Cxx.name("no_instrument_function");
  noMicroMips @197 $Cxx.name("no_micro_mips");
  noMips16 @198 $Cxx.name("no_mips16");
  noProfileFunction @199 $Cxx.name("no_profile_function");
  noReturn @200 $Cxx.name("no_return");
  noSanitize @201 $Cxx.name("no_sanitize");
  noSpeculativeLoadHardening @202 $Cxx.name("no_speculative_load_hardening");
  noSplitStack @203 $Cxx.name("no_split_stack");
  noStackProtector @204 $Cxx.name("no_stack_protector");
  noThreadSafetyAnalysis @205 $Cxx.name("no_thread_safety_analysis");
  noThrow @206 $Cxx.name("no_throw");
  noUniqueAddress @207 $Cxx.name("no_unique_address");
  notTailCalled @208 $Cxx.name("not_tail_called");
  ompAllocateDeclaration @209 $Cxx.name("omp_allocate_declaration");
  ompCaptureNoInitializer @210 $Cxx.name("omp_capture_no_initializer");
  ompDeclareTargetDeclaration @211 $Cxx.name("omp_declare_target_declaration");
  ompDeclareVariant @212 $Cxx.name("omp_declare_variant");
  ompThreadPrivateDeclaration @213 $Cxx.name("omp_thread_private_declaration");
  osConsumesThis @214 $Cxx.name("os_consumes_this");
  osReturnsNotRetained @215 $Cxx.name("os_returns_not_retained");
  osReturnsRetained @216 $Cxx.name("os_returns_retained");
  osReturnsRetainedOnNonZero @217 $Cxx.name("os_returns_retained_on_non_zero");
  osReturnsRetainedOnZero @218 $Cxx.name("os_returns_retained_on_zero");
  objCBridge @219 $Cxx.name("obj_c_bridge");
  objCBridgeMutable @220 $Cxx.name("obj_c_bridge_mutable");
  objCBridgeRelated @221 $Cxx.name("obj_c_bridge_related");
  objCException @222 $Cxx.name("obj_c_exception");
  objCExplicitProtocolImplementation @223 $Cxx.name("obj_c_explicit_protocol_implementation");
  objCExternallyRetained @224 $Cxx.name("obj_c_externally_retained");
  objCIndependentClass @225 $Cxx.name("obj_c_independent_class");
  objCMethodFamily @226 $Cxx.name("obj_c_method_family");
  objCnsObject @227 $Cxx.name("obj_cns_object");
  objCPreciseLifetime @228 $Cxx.name("obj_c_precise_lifetime");
  objCRequiresPropertyDefinitions @229 $Cxx.name("obj_c_requires_property_definitions");
  objCRequiresSuper @230 $Cxx.name("obj_c_requires_super");
  objCReturnsInnerPointer @231 $Cxx.name("obj_c_returns_inner_pointer");
  objCRootClass @232 $Cxx.name("obj_c_root_class");
  objCSubclassingRestricted @233 $Cxx.name("obj_c_subclassing_restricted");
  openClIntelReqdSubGroupSize @234 $Cxx.name("open_cl_intel_reqd_sub_group_size");
  openClKernel @235 $Cxx.name("open_cl_kernel");
  optimizeNone @236 $Cxx.name("optimize_none");
  override @237 $Cxx.name("override");
  owner @238 $Cxx.name("owner");
  ownership @239 $Cxx.name("ownership");
  packed @240 $Cxx.name("packed");
  paramTypestate @241 $Cxx.name("param_typestate");
  patchableFunctionEntry @242 $Cxx.name("patchable_function_entry");
  pointer @243 $Cxx.name("pointer");
  pragmaClangBssSection @244 $Cxx.name("pragma_clang_bss_section");
  pragmaClangDataSection @245 $Cxx.name("pragma_clang_data_section");
  pragmaClangRelroSection @246 $Cxx.name("pragma_clang_relro_section");
  pragmaClangRodataSection @247 $Cxx.name("pragma_clang_rodata_section");
  pragmaClangTextSection @248 $Cxx.name("pragma_clang_text_section");
  preferredName @249 $Cxx.name("preferred_name");
  ptGuardedBy @250 $Cxx.name("pt_guarded_by");
  ptGuardedVariable @251 $Cxx.name("pt_guarded_variable");
  pure @252 $Cxx.name("pure");
  riscvInterrupt @253 $Cxx.name("riscv_interrupt");
  reinitializes @254 $Cxx.name("reinitializes");
  releaseCapability @255 $Cxx.name("release_capability");
  reqdWorkGroupSize @256 $Cxx.name("reqd_work_group_size");
  requiresCapability @257 $Cxx.name("requires_capability");
  restrict @258 $Cxx.name("restrict");
  retain @259 $Cxx.name("retain");
  returnTypestate @260 $Cxx.name("return_typestate");
  returnsNonNull @261 $Cxx.name("returns_non_null");
  returnsTwice @262 $Cxx.name("returns_twice");
  syclKernel @263 $Cxx.name("sycl_kernel");
  scopedLockable @264 $Cxx.name("scoped_lockable");
  section @265 $Cxx.name("section");
  selectAny @266 $Cxx.name("select_any");
  sentinel @267 $Cxx.name("sentinel");
  setTypestate @268 $Cxx.name("set_typestate");
  sharedTrylockFunction @269 $Cxx.name("shared_trylock_function");
  speculativeLoadHardening @270 $Cxx.name("speculative_load_hardening");
  standaloneDebug @271 $Cxx.name("standalone_debug");
  strictFp @272 $Cxx.name("strict_fp");
  swiftAsync @273 $Cxx.name("swift_async");
  swiftAsyncError @274 $Cxx.name("swift_async_error");
  swiftAsyncName @275 $Cxx.name("swift_async_name");
  swiftAttribute @276 $Cxx.name("swift_attribute");
  swiftBridge @277 $Cxx.name("swift_bridge");
  swiftBridgedTypedef @278 $Cxx.name("swift_bridged_typedef");
  swiftError @279 $Cxx.name("swift_error");
  swiftName @280 $Cxx.name("swift_name");
  swiftNewType @281 $Cxx.name("swift_new_type");
  swiftPrivate @282 $Cxx.name("swift_private");
  tlsModel @283 $Cxx.name("tls_model");
  target @284 $Cxx.name("target");
  testTypestate @285 $Cxx.name("test_typestate");
  transparentUnion @286 $Cxx.name("transparent_union");
  trivialAbi @287 $Cxx.name("trivial_abi");
  tryAcquireCapability @288 $Cxx.name("try_acquire_capability");
  typeTagForDatatype @289 $Cxx.name("type_tag_for_datatype");
  typeVisibility @290 $Cxx.name("type_visibility");
  unavailable @291 $Cxx.name("unavailable");
  uninitialized @292 $Cxx.name("uninitialized");
  unused @293 $Cxx.name("unused");
  used @294 $Cxx.name("used");
  usingIfExists @295 $Cxx.name("using_if_exists");
  uuid @296 $Cxx.name("uuid");
  vecReturn @297 $Cxx.name("vec_return");
  vecTypeHint @298 $Cxx.name("vec_type_hint");
  visibility @299 $Cxx.name("visibility");
  warnUnused @300 $Cxx.name("warn_unused");
  warnUnusedResult @301 $Cxx.name("warn_unused_result");
  weak @302 $Cxx.name("weak");
  weakImport @303 $Cxx.name("weak_import");
  weakReference @304 $Cxx.name("weak_reference");
  webAssemblyExportName @305 $Cxx.name("web_assembly_export_name");
  webAssemblyImportModule @306 $Cxx.name("web_assembly_import_module");
  webAssemblyImportName @307 $Cxx.name("web_assembly_import_name");
  workGroupSizeHint @308 $Cxx.name("work_group_size_hint");
  x86ForceAlignArgumentPointer @309 $Cxx.name("x86_force_align_argument_pointer");
  xRayInstrument @310 $Cxx.name("x_ray_instrument");
  xRayLogArguments @311 $Cxx.name("x_ray_log_arguments");
  abiTag @312 $Cxx.name("abi_tag");
  alias @313 $Cxx.name("alias");
  alignValue @314 $Cxx.name("align_value");
  builtinAlias @315 $Cxx.name("builtin_alias");
  calledOnce @316 $Cxx.name("called_once");
  iFunc @317 $Cxx.name("i_func");
  initializerSeg @318 $Cxx.name("initializer_seg");
  loaderUninitialized @319 $Cxx.name("loader_uninitialized");
  loopHint @320 $Cxx.name("loop_hint");
  mode @321 $Cxx.name("mode");
  noBuiltin @322 $Cxx.name("no_builtin");
  noEscape @323 $Cxx.name("no_escape");
  ompCaptureKind @324 $Cxx.name("omp_capture_kind");
  ompDeclareSimdDeclaration @325 $Cxx.name("omp_declare_simd_declaration");
  ompReferencedVariable @326 $Cxx.name("omp_referenced_variable");
  objCBoxable @327 $Cxx.name("obj_c_boxable");
  objCClassStub @328 $Cxx.name("obj_c_class_stub");
  objCDesignatedInitializer @329 $Cxx.name("obj_c_designated_initializer");
  objCDirect @330 $Cxx.name("obj_c_direct");
  objCDirectMembers @331 $Cxx.name("obj_c_direct_members");
  objCNonLazyClass @332 $Cxx.name("obj_c_non_lazy_class");
  objCNonRuntimeProtocol @333 $Cxx.name("obj_c_non_runtime_protocol");
  objCRuntimeName @334 $Cxx.name("obj_c_runtime_name");
  objCRuntimeVisible @335 $Cxx.name("obj_c_runtime_visible");
  openClAccess @336 $Cxx.name("open_cl_access");
  overloadable @337 $Cxx.name("overloadable");
  renderScriptKernel @338 $Cxx.name("render_script_kernel");
  swiftObjCMembers @339 $Cxx.name("swift_obj_c_members");
  thread @340 $Cxx.name("thread");
}

enum AutoTypeKeyword @0x8f3df89531320c02 {
  auto @0 $Cxx.name("auto");
  decltypeAuto @1 $Cxx.name("decltype_auto");
  gnuAutoType @2 $Cxx.name("gnu_auto_type");
}

enum AvailabilityResult @0xe8c6cd388f86c217 {
  available @0 $Cxx.name("available");
  notYetIntroduced @1 $Cxx.name("not_yet_introduced");
  deprecated @2 $Cxx.name("deprecated");
  unavailable @3 $Cxx.name("unavailable");
}

enum BinaryOperatorKind @0xbb08cc41f7a56597 {
  pointerMemoryUcD @0 $Cxx.name("pointer_memory_d");
  pointerMemoryUcI @1 $Cxx.name("pointer_memory_i");
  mul @2 $Cxx.name("mul");
  div @3 $Cxx.name("div");
  rem @4 $Cxx.name("rem");
  add @5 $Cxx.name("add");
  sub @6 $Cxx.name("sub");
  shl @7 $Cxx.name("shl");
  shr @8 $Cxx.name("shr");
  cmp @9 $Cxx.name("cmp");
  lt @10 $Cxx.name("lt");
  gt @11 $Cxx.name("gt");
  le @12 $Cxx.name("le");
  ge @13 $Cxx.name("ge");
  eq @14 $Cxx.name("eq");
  ne @15 $Cxx.name("ne");
  and @16 $Cxx.name("and");
  xor @17 $Cxx.name("xor");
  or @18 $Cxx.name("or");
  lAnd @19 $Cxx.name("l_and");
  lOr @20 $Cxx.name("l_or");
  assign @21 $Cxx.name("assign");
  mulAssign @22 $Cxx.name("mul_assign");
  divAssign @23 $Cxx.name("div_assign");
  remAssign @24 $Cxx.name("rem_assign");
  addAssign @25 $Cxx.name("add_assign");
  subAssign @26 $Cxx.name("sub_assign");
  shlAssign @27 $Cxx.name("shl_assign");
  shrAssign @28 $Cxx.name("shr_assign");
  andAssign @29 $Cxx.name("and_assign");
  xorAssign @30 $Cxx.name("xor_assign");
  orAssign @31 $Cxx.name("or_assign");
  comma @32 $Cxx.name("comma");
}

enum Bits @0x87be10d300b35eda {
  none @0 $Cxx.name("none");
  unexpandedPack @1 $Cxx.name("unexpanded_pack");
  instantiation @2 $Cxx.name("instantiation");
  type @3 $Cxx.name("type");
  value @4 $Cxx.name("value");
  dependent @5 $Cxx.name("dependent");
  error @6 $Cxx.name("error");
  variablyModified @7 $Cxx.name("variably_modified");
  syntactic @8 $Cxx.name("syntactic");
}

enum BlockType @0xa51084915663634e {
  byReference @0 $Cxx.name("by_reference");
}

enum BranchStateTy @0xd5619d872098bf4c {
  undefined @0 $Cxx.name("undefined");
  inbranch @1 $Cxx.name("inbranch");
  notinbranch @2 $Cxx.name("notinbranch");
}

enum CallingConv @0xfc49dab6441b4ebd {
  c @0 $Cxx.name("c");
  x86StdCall @1 $Cxx.name("x86_std_call");
  x86FastCall @2 $Cxx.name("x86_fast_call");
  x86ThisCall @3 $Cxx.name("x86_this_call");
  x86VectorCall @4 $Cxx.name("x86_vector_call");
  x86Pascal @5 $Cxx.name("x86_pascal");
  win64 @6 $Cxx.name("win64");
  x8664SysUcV @7 $Cxx.name("x8664_sys_v");
  x86RegCall @8 $Cxx.name("x86_reg_call");
  aapcs @9 $Cxx.name("aapcs");
  aapcsvfp @10 $Cxx.name("aapcsvfp");
  intelOclBicc @11 $Cxx.name("intel_ocl_bicc");
  spirFunction @12 $Cxx.name("spir_function");
  openClKernel @13 $Cxx.name("open_cl_kernel");
  swift @14 $Cxx.name("swift");
  swiftAsync @15 $Cxx.name("swift_async");
  preserveMost @16 $Cxx.name("preserve_most");
  preserveAll @17 $Cxx.name("preserve_all");
  aArch64VectorCall @18 $Cxx.name("a_arch64_vector_call");
}

enum CanThrowResult @0xade719c14c0fa1a7 {
  cannot @0 $Cxx.name("cannot");
  dependent @1 $Cxx.name("dependent");
  can @2 $Cxx.name("can");
}

enum CapturedRegionKind @0x9c1102e218ed4271 {
  default @0 $Cxx.name("default");
  objCAtFinally @1 $Cxx.name("obj_c_at_finally");
  openMp @2 $Cxx.name("open_mp");
}

enum CastKind @0xc1c8bbecc0c79f1b {
  dependent @0 $Cxx.name("dependent");
  bitCast @1 $Cxx.name("bit_cast");
  lValueBitCast @2 $Cxx.name("l_value_bit_cast");
  lValueToRValueBitCast @3 $Cxx.name("l_value_to_r_value_bit_cast");
  lValueToRValue @4 $Cxx.name("l_value_to_r_value");
  noOperation @5 $Cxx.name("no_operation");
  baseToDerived @6 $Cxx.name("base_to_derived");
  derivedToBase @7 $Cxx.name("derived_to_base");
  uncheckedDerivedToBase @8 $Cxx.name("unchecked_derived_to_base");
  dynamic @9 $Cxx.name("dynamic");
  toUnion @10 $Cxx.name("to_union");
  arrayToPointerDecay @11 $Cxx.name("array_to_pointer_decay");
  functionToPointerDecay @12 $Cxx.name("function_to_pointer_decay");
  nullToPointer @13 $Cxx.name("null_to_pointer");
  nullToMemberPointer @14 $Cxx.name("null_to_member_pointer");
  baseToDerivedMemberPointer @15 $Cxx.name("base_to_derived_member_pointer");
  derivedToBaseMemberPointer @16 $Cxx.name("derived_to_base_member_pointer");
  memberPointerToBoolean @17 $Cxx.name("member_pointer_to_boolean");
  reinterpretMemberPointer @18 $Cxx.name("reinterpret_member_pointer");
  userDefinedConversion @19 $Cxx.name("user_defined_conversion");
  constructorConversion @20 $Cxx.name("constructor_conversion");
  integralToPointer @21 $Cxx.name("integral_to_pointer");
  pointerToIntegral @22 $Cxx.name("pointer_to_integral");
  pointerToBoolean @23 $Cxx.name("pointer_to_boolean");
  toVoid @24 $Cxx.name("to_void");
  matrixCast @25 $Cxx.name("matrix_cast");
  vectorSplat @26 $Cxx.name("vector_splat");
  integralCast @27 $Cxx.name("integral_cast");
  integralToBoolean @28 $Cxx.name("integral_to_boolean");
  integralToFloating @29 $Cxx.name("integral_to_floating");
  floatingToFixedPoint @30 $Cxx.name("floating_to_fixed_point");
  fixedPointToFloating @31 $Cxx.name("fixed_point_to_floating");
  fixedPointCast @32 $Cxx.name("fixed_point_cast");
  fixedPointToIntegral @33 $Cxx.name("fixed_point_to_integral");
  integralToFixedPoint @34 $Cxx.name("integral_to_fixed_point");
  fixedPointToBoolean @35 $Cxx.name("fixed_point_to_boolean");
  floatingToIntegral @36 $Cxx.name("floating_to_integral");
  floatingToBoolean @37 $Cxx.name("floating_to_boolean");
  booleanToSignedIntegral @38 $Cxx.name("boolean_to_signed_integral");
  floatingCast @39 $Cxx.name("floating_cast");
  cPointerToObjCPointerCast @40 $Cxx.name("c_pointer_to_obj_c_pointer_cast");
  blockPointerToObjCPointerCast @41 $Cxx.name("block_pointer_to_obj_c_pointer_cast");
  anyPointerToBlockPointerCast @42 $Cxx.name("any_pointer_to_block_pointer_cast");
  objCObjectLValueCast @43 $Cxx.name("obj_c_object_l_value_cast");
  floatingRealToComplex @44 $Cxx.name("floating_real_to_complex");
  floatingComplexToReal @45 $Cxx.name("floating_complex_to_real");
  floatingComplexToBoolean @46 $Cxx.name("floating_complex_to_boolean");
  floatingComplexCast @47 $Cxx.name("floating_complex_cast");
  floatingComplexToIntegralComplex @48 $Cxx.name("floating_complex_to_integral_complex");
  integralRealToComplex @49 $Cxx.name("integral_real_to_complex");
  integralComplexToReal @50 $Cxx.name("integral_complex_to_real");
  integralComplexToBoolean @51 $Cxx.name("integral_complex_to_boolean");
  integralComplexCast @52 $Cxx.name("integral_complex_cast");
  integralComplexToFloatingComplex @53 $Cxx.name("integral_complex_to_floating_complex");
  arcProduceObject @54 $Cxx.name("arc_produce_object");
  arcConsumeObject @55 $Cxx.name("arc_consume_object");
  arcReclaimReturnedObject @56 $Cxx.name("arc_reclaim_returned_object");
  arcExtendBlockObject @57 $Cxx.name("arc_extend_block_object");
  atomicToNonAtomic @58 $Cxx.name("atomic_to_non_atomic");
  nonAtomicToAtomic @59 $Cxx.name("non_atomic_to_atomic");
  copyAndAutoreleaseBlockObject @60 $Cxx.name("copy_and_autorelease_block_object");
  builtinFnToFnPointer @61 $Cxx.name("builtin_fn_to_fn_pointer");
  zeroToOclOpaqueType @62 $Cxx.name("zero_to_ocl_opaque_type");
  addressSpaceConversion @63 $Cxx.name("address_space_conversion");
  intToOclSampler @64 $Cxx.name("int_to_ocl_sampler");
}

enum ClangABI @0xecbba2912ae04f24 {
  ver38 @0 $Cxx.name("ver38");
  ver4 @1 $Cxx.name("ver4");
  ver6 @2 $Cxx.name("ver6");
  ver7 @3 $Cxx.name("ver7");
  ver9 @4 $Cxx.name("ver9");
  ver11 @5 $Cxx.name("ver11");
  ver12 @6 $Cxx.name("ver12");
  latest @7 $Cxx.name("latest");
}

enum CommentKind @0xeaf4ee39de8680a5 {
  invalid @0 $Cxx.name("invalid");
  ordinaryBcpl @1 $Cxx.name("ordinary_bcpl");
  ordinaryUcC @2 $Cxx.name("ordinary_c");
  bcplSlash @3 $Cxx.name("bcpl_slash");
  bcplExcl @4 $Cxx.name("bcpl_excl");
  javaDoc @5 $Cxx.name("java_doc");
  qt @6 $Cxx.name("qt");
  merged @7 $Cxx.name("merged");
}

enum ComparisonCategoryResult @0x86a49ccc02dc9f27 {
  equal @0 $Cxx.name("equal");
  equivalent @1 $Cxx.name("equivalent");
  less @2 $Cxx.name("less");
  greater @3 $Cxx.name("greater");
  unordered @4 $Cxx.name("unordered");
}

enum ComparisonCategoryType @0xd0839efab1f9a4b1 {
  partialOrdering @0 $Cxx.name("partial_ordering");
  weakOrdering @1 $Cxx.name("weak_ordering");
  strongOrdering @2 $Cxx.name("strong_ordering");
}

enum CompilingModuleKind @0xdb213b290b8b6c8c {
  none @0 $Cxx.name("none");
  moduleMap @1 $Cxx.name("module_map");
  headerModule @2 $Cxx.name("header_module");
  moduleInterface @3 $Cxx.name("module_interface");
}

enum ConstexprSpecKind @0x9b968674fb4c29be {
  unspecified @0 $Cxx.name("unspecified");
  constexpr @1 $Cxx.name("constexpr");
  consteval @2 $Cxx.name("consteval");
  constinit @3 $Cxx.name("constinit");
}

enum ConsumedState @0xa636e7b99e2144ce {
  unknown @0 $Cxx.name("unknown");
  consumed @1 $Cxx.name("consumed");
  unconsumed @2 $Cxx.name("unconsumed");
}

enum ConventionKind @0xa6a3607298c93bba {
  none @0 $Cxx.name("none");
  nonNullError @1 $Cxx.name("non_null_error");
  zeroArgument @2 $Cxx.name("zero_argument");
  nonZeroArgument @3 $Cxx.name("non_zero_argument");
}

enum CoreFoundationABI @0xaa0f7fecce7bde72 {
  unspecified @0 $Cxx.name("unspecified");
  standalone @1 $Cxx.name("standalone");
  objectiveUcC @2 $Cxx.name("objective_c");
  swift @3 $Cxx.name("swift");
  swift50 @4 $Cxx.name("swift50");
  swift42 @5 $Cxx.name("swift42");
  swift41 @6 $Cxx.name("swift41");
}

enum DefaultArgKind @0xcc392850dcfe18d3 {
  none @0 $Cxx.name("none");
  unparsed @1 $Cxx.name("unparsed");
  uninstantiated @2 $Cxx.name("uninstantiated");
  normal @3 $Cxx.name("normal");
}

enum DefaultCallingConvention @0x8bfd86e7c2858a55 {
  none @0 $Cxx.name("none");
  cDecl @1 $Cxx.name("c_decl");
  fastCall @2 $Cxx.name("fast_call");
  stdCall @3 $Cxx.name("std_call");
  vectorCall @4 $Cxx.name("vector_call");
  regCall @5 $Cxx.name("reg_call");
}

enum DevTypeTy @0xfbcfe96906c04575 {
  host @0 $Cxx.name("host");
  noHost @1 $Cxx.name("no_host");
  any @2 $Cxx.name("any");
}

enum DiagnosticLevelMask @0xf08ecf7d4869e270 {
  none @0 $Cxx.name("none");
  note @1 $Cxx.name("note");
  remark @2 $Cxx.name("remark");
  warning @3 $Cxx.name("warning");
  error @4 $Cxx.name("error");
  all @5 $Cxx.name("all");
}

enum DiagnosticType @0xf3507e3988fc705c {
  error @0 $Cxx.name("error");
  warning @1 $Cxx.name("warning");
}

enum ElaboratedTypeKeyword @0xa1d6585ce07b0b05 {
  struct @0 $Cxx.name("struct");
  interface @1 $Cxx.name("interface");
  union @2 $Cxx.name("union");
  class @3 $Cxx.name("class");
  enum @4 $Cxx.name("enum");
  typename @5 $Cxx.name("typename");
  none @6 $Cxx.name("none");
}

enum EmbedBitcodeKind @0x8a15aa7f6145c686 {
  embedOff @0 $Cxx.name("embed_off");
  embedAll @1 $Cxx.name("embed_all");
  embedBitcode @2 $Cxx.name("embed_bitcode");
  embedMarker @3 $Cxx.name("embed_marker");
}

enum ExceptionHandlingKind @0x81f79c655bf98919 {
  none @0 $Cxx.name("none");
  sjLj @1 $Cxx.name("sj_lj");
  winEh @2 $Cxx.name("win_eh");
  dwarfCfi @3 $Cxx.name("dwarf_cfi");
  wasm @4 $Cxx.name("wasm");
}

enum ExceptionSpecificationType @0xd5391f397240ed4d {
  none @0 $Cxx.name("none");
  dynamicNone @1 $Cxx.name("dynamic_none");
  dynamic @2 $Cxx.name("dynamic");
  msAny @3 $Cxx.name("ms_any");
  noThrow @4 $Cxx.name("no_throw");
  basicNoexcept @5 $Cxx.name("basic_noexcept");
  dependentNoexcept @6 $Cxx.name("dependent_noexcept");
  noexceptFalse @7 $Cxx.name("noexcept_false");
  noexceptTrue @8 $Cxx.name("noexcept_true");
  unevaluated @9 $Cxx.name("unevaluated");
  uninstantiated @10 $Cxx.name("uninstantiated");
  unparsed @11 $Cxx.name("unparsed");
}

enum ExplicitSpecKind @0xd9d0a0f08007648c {
  resolvedFalse @0 $Cxx.name("resolved_false");
  resolvedTrue @1 $Cxx.name("resolved_true");
  unresolved @2 $Cxx.name("unresolved");
}

enum ExprDependence @0xb34e9e74770b1892 {
  unexpandedPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  type @2 $Cxx.name("type");
  value @3 $Cxx.name("value");
  error @4 $Cxx.name("error");
  none @5 $Cxx.name("none");
  all @6 $Cxx.name("all");
  typeValue @7 $Cxx.name("type_value");
  typeInstantiation @8 $Cxx.name("type_instantiation");
  valueInstantiation @9 $Cxx.name("value_instantiation");
  typeValueInstantiation @10 $Cxx.name("type_value_instantiation");
  errorDependent @11 $Cxx.name("error_dependent");
}

enum ExprObjectKind @0xf9211f9356023995 {
  ordinary @0 $Cxx.name("ordinary");
  bitField @1 $Cxx.name("bit_field");
  vectorComponent @2 $Cxx.name("vector_component");
  objCProperty @3 $Cxx.name("obj_c_property");
  objCSubscript @4 $Cxx.name("obj_c_subscript");
  matrixComponent @5 $Cxx.name("matrix_component");
}

enum ExprOffsets @0xbd73e54b08c98af9 {
  allocator @0 $Cxx.name("allocator");
  allocatorTraits @1 $Cxx.name("allocator_traits");
  total @2 $Cxx.name("total");
}

enum ExprValueKind @0xb10e40f0a807354a {
  prValue @0 $Cxx.name("pr_value");
  lValue @1 $Cxx.name("l_value");
  xValue @2 $Cxx.name("x_value");
}

enum ExpressionTrait @0xc0206beabf974c92 {
  isLValueExpression @0 $Cxx.name("is_l_value_expression");
  isRValueExpression @1 $Cxx.name("is_r_value_expression");
}

enum ExtKind @0xd611294447eb8124 {
  always @0 $Cxx.name("always");
  never @1 $Cxx.name("never");
  replyHazy @2 $Cxx.name("reply_hazy");
}

enum ExtendArgsKind @0xdfdce259f47bbf96 {
  extendTo32 @0 $Cxx.name("extend_to32");
  extendTo64 @1 $Cxx.name("extend_to64");
}

enum FPExceptionModeKind @0xd10dc4052db0928d {
  ignore @0 $Cxx.name("ignore");
  mayTrap @1 $Cxx.name("may_trap");
  strict @2 $Cxx.name("strict");
}

enum FPModeKind @0xfd73335cff2b1987 {
  off @0 $Cxx.name("off");
  on @1 $Cxx.name("on");
  fast @2 $Cxx.name("fast");
  fastHonorPragmas @3 $Cxx.name("fast_honor_pragmas");
}

enum FamilyKind @0xd065ba2fb1eb0ca8 {
  none @0 $Cxx.name("none");
  alloc @1 $Cxx.name("alloc");
  copy @2 $Cxx.name("copy");
  initializer @3 $Cxx.name("initializer");
  mutableCopy @4 $Cxx.name("mutable_copy");
  new @5 $Cxx.name("new");
}

enum FiniteLoopsKind @0xe7c6ec0d3ed97659 {
  language @0 $Cxx.name("language");
  always @1 $Cxx.name("always");
  never @2 $Cxx.name("never");
}

enum FramePointerKind @0xf0c60fc0c9560ac5 {
  none @0 $Cxx.name("none");
  nonLeaf @1 $Cxx.name("non_leaf");
  all @2 $Cxx.name("all");
}

enum GC @0x9a94d869fc1a75e8 {
  gcNone @0 $Cxx.name("gc_none");
  weak @1 $Cxx.name("weak");
  strong @2 $Cxx.name("strong");
}

enum GCMode @0x9152ea17e5b3f9a0 {
  nonGc @0 $Cxx.name("non_gc");
  gcOnly @1 $Cxx.name("gc_only");
  hybridGc @2 $Cxx.name("hybrid_gc");
}

enum GVALinkage @0x9bb9f73a64abe308 {
  internal @0 $Cxx.name("internal");
  availableExternally @1 $Cxx.name("available_externally");
  discardableOdr @2 $Cxx.name("discardable_odr");
  strongExternal @3 $Cxx.name("strong_external");
  strongOdr @4 $Cxx.name("strong_odr");
}

enum GetBuiltinTypeError @0xa22d3ea619595e5e {
  none @0 $Cxx.name("none");
  missingType @1 $Cxx.name("missing_type");
  missingStdio @2 $Cxx.name("missing_stdio");
  missing @3 $Cxx.name("missing");
  missingUcontext @4 $Cxx.name("missing_ucontext");
}

enum GuardArg @0xe7ff733be842e115 {
  nocf @0 $Cxx.name("nocf");
}

enum ID @0xecc2ff5d6d583342 {
  workGroup @0 $Cxx.name("work_group");
  device @1 $Cxx.name("device");
  allSvmDevices @2 $Cxx.name("all_svm_devices");
  subGroup @3 $Cxx.name("sub_group");
}

enum IdentifierInfoFlag @0x974855f046125808 {
  zeroArgument @0 $Cxx.name("zero_argument");
  oneArgument @1 $Cxx.name("one_argument");
  multiArgument @2 $Cxx.name("multi_argument");
  # Skipped repeat pasta::kArgumentFlags
}

enum ImbueAttribute @0xdd8ae71e2c4749bf {
  none @0 $Cxx.name("none");
  always @1 $Cxx.name("always");
  never @2 $Cxx.name("never");
  alwaysarG1 @3 $Cxx.name("alwaysar_g1");
}

enum ImplicitReason @0x89f711fa7c0ef6d0 {
  none @0 $Cxx.name("none");
  arcForbiddenType @1 $Cxx.name("arc_forbidden_type");
  forbiddenWeak @2 $Cxx.name("forbidden_weak");
  arcForbiddenConversion @3 $Cxx.name("arc_forbidden_conversion");
  arcInitReturnsUnrelated @4 $Cxx.name("arc_init_returns_unrelated");
  arcFieldWithOwnership @5 $Cxx.name("arc_field_with_ownership");
}

enum InClassInitStyle @0xfd30164f4a13d25c {
  noInitializer @0 $Cxx.name("no_initializer");
  copyInitializer @1 $Cxx.name("copy_initializer");
  listInitializer @2 $Cxx.name("list_initializer");
}

enum InheritedDesignatedInitializersState @0x80bfbb38bcb7d4b7 {
  unknown @0 $Cxx.name("unknown");
  inherited @1 $Cxx.name("inherited");
  notInherited @2 $Cxx.name("not_inherited");
}

enum InitStorageKind @0xecf08a0982b00e9c {
  noInitializer @0 $Cxx.name("no_initializer");
  inClassCopyInitializer @1 $Cxx.name("in_class_copy_initializer");
  inClassListInitializer @2 $Cxx.name("in_class_list_initializer");
  capturedVlaType @3 $Cxx.name("captured_vla_type");
}

enum InlineVariableDefinitionKind @0xccf5d722e580b02d {
  none @0 $Cxx.name("none");
  weak @1 $Cxx.name("weak");
  weakUnknown @2 $Cxx.name("weak_unknown");
  strong @3 $Cxx.name("strong");
}

enum InliningMethod @0xeed1dbfe0541b900 {
  normalInlining @0 $Cxx.name("normal_inlining");
  onlyHintInlining @1 $Cxx.name("only_hint_inlining");
  onlyAlwaysInlining @2 $Cxx.name("only_always_inlining");
}

enum InterruptType @0x8c9ad7d0a027ebb7 {
  irq @0 $Cxx.name("irq");
  fiq @1 $Cxx.name("fiq");
  swi @2 $Cxx.name("swi");
  abort @3 $Cxx.name("abort");
  undef @4 $Cxx.name("undef");
  generic @5 $Cxx.name("generic");
}

enum Kinds @0xc3c6bd22449e6d65 {
  lValue @0 $Cxx.name("l_value");
  xValue @1 $Cxx.name("x_value");
  function @2 $Cxx.name("function");
  void @3 $Cxx.name("void");
  addressableVoid @4 $Cxx.name("addressable_void");
  duplicateVectorComponents @5 $Cxx.name("duplicate_vector_components");
  memberFunction @6 $Cxx.name("member_function");
  subObjCPropertySetting @7 $Cxx.name("sub_obj_c_property_setting");
  classTemporary @8 $Cxx.name("class_temporary");
  arrayTemporary @9 $Cxx.name("array_temporary");
  objCMessageRValue @10 $Cxx.name("obj_c_message_r_value");
  prValue @11 $Cxx.name("pr_value");
}

enum LambdaCaptureDefault @0xc5ffb9f76dbfab4d {
  none @0 $Cxx.name("none");
  byCopy @1 $Cxx.name("by_copy");
  byReference @2 $Cxx.name("by_reference");
}

enum LambdaCaptureKind @0xa68f8e856ba4e11d {
  this @0 $Cxx.name("this");
  starThis @1 $Cxx.name("star_this");
  byCopy @2 $Cxx.name("by_copy");
  byReference @3 $Cxx.name("by_reference");
  vlaType @4 $Cxx.name("vla_type");
}

enum LangAS @0xbe9184d23b40adbf {
  default @0 $Cxx.name("default");
  openclGlobal @1 $Cxx.name("opencl_global");
  openclLocal @2 $Cxx.name("opencl_local");
  openclConstant @3 $Cxx.name("opencl_constant");
  openclPrivate @4 $Cxx.name("opencl_private");
  openclGeneric @5 $Cxx.name("opencl_generic");
  openclGlobalDevice @6 $Cxx.name("opencl_global_device");
  openclGlobalHost @7 $Cxx.name("opencl_global_host");
  cudaDevice @8 $Cxx.name("cuda_device");
  cudaConstant @9 $Cxx.name("cuda_constant");
  cudaShared @10 $Cxx.name("cuda_shared");
  syclGlobal @11 $Cxx.name("sycl_global");
  syclGlobalDevice @12 $Cxx.name("sycl_global_device");
  syclGlobalHost @13 $Cxx.name("sycl_global_host");
  syclLocal @14 $Cxx.name("sycl_local");
  syclPrivate @15 $Cxx.name("sycl_private");
  ptr32Sptr @16 $Cxx.name("ptr32_sptr");
  ptr32Uptr @17 $Cxx.name("ptr32_uptr");
  ptr64 @18 $Cxx.name("ptr64");
}

enum LangFeatures @0x9d065077a2c3ac3d {
  lineComment @0 $Cxx.name("line_comment");
  c99 @1 $Cxx.name("c99");
  c11 @2 $Cxx.name("c11");
  c17 @3 $Cxx.name("c17");
  c2UcX @4 $Cxx.name("c2_x");
  cPlusPlus @5 $Cxx.name("c_plus_plus");
  cPlusPlus11 @6 $Cxx.name("c_plus_plus11");
  cPlusPlus14 @7 $Cxx.name("c_plus_plus14");
  cPlusPlus17 @8 $Cxx.name("c_plus_plus17");
  cPlusPlus20 @9 $Cxx.name("c_plus_plus20");
  cPlusPlus2UcB @10 $Cxx.name("c_plus_plus2_b");
  digraphs @11 $Cxx.name("digraphs");
  gnuMode @12 $Cxx.name("gnu_mode");
  hexFloat @13 $Cxx.name("hex_float");
  implicitInt @14 $Cxx.name("implicit_int");
  openCl @15 $Cxx.name("open_cl");
}

enum Language @0xf4615837a299503e {
  unknown @0 $Cxx.name("unknown");
  assembly @1 $Cxx.name("assembly");
  llvmir @2 $Cxx.name("llvmir");
  c @3 $Cxx.name("c");
  cxx @4 $Cxx.name("cxx");
  objUcC @5 $Cxx.name("obj_c");
  objCxx @6 $Cxx.name("obj_cxx");
  openCl @7 $Cxx.name("open_cl");
  openClcxx @8 $Cxx.name("open_clcxx");
  cuda @9 $Cxx.name("cuda");
  renderScript @10 $Cxx.name("render_script");
  hip @11 $Cxx.name("hip");
}

enum LanguageLinkage @0xa1e45a6941f17018 {
  cLanguageLinkage @0 $Cxx.name("c_language_linkage");
  cxxLanguageLinkage @1 $Cxx.name("cxx_language_linkage");
  noLanguageLinkage @2 $Cxx.name("no_language_linkage");
}

enum LaxVectorConversionKind @0xb0919523fe59bfa9 {
  none @0 $Cxx.name("none");
  integer @1 $Cxx.name("integer");
  all @2 $Cxx.name("all");
}

enum Level @0xa36af006ece7db45 {
  ignored @0 $Cxx.name("ignored");
  note @1 $Cxx.name("note");
  remark @2 $Cxx.name("remark");
  warning @3 $Cxx.name("warning");
  error @4 $Cxx.name("error");
  fatal @5 $Cxx.name("fatal");
}

enum Linkage @0xd7f90485cbd67b8c {
  noLinkage @0 $Cxx.name("no_linkage");
  internalLinkage @1 $Cxx.name("internal_linkage");
  uniqueExternalLinkage @2 $Cxx.name("unique_external_linkage");
  visibleNoLinkage @3 $Cxx.name("visible_no_linkage");
  moduleInternalLinkage @4 $Cxx.name("module_internal_linkage");
  moduleLinkage @5 $Cxx.name("module_linkage");
  externalLinkage @6 $Cxx.name("external_linkage");
}

enum LoopHintState @0xcb899bf31e9a23a1 {
  enable @0 $Cxx.name("enable");
  disable @1 $Cxx.name("disable");
  numeric @2 $Cxx.name("numeric");
  fixedWidth @3 $Cxx.name("fixed_width");
  scalableWidth @4 $Cxx.name("scalable_width");
  assumeSafety @5 $Cxx.name("assume_safety");
  full @6 $Cxx.name("full");
}

enum MSInheritanceModel @0x9e63c392cec08405 {
  single @0 $Cxx.name("single");
  multiple @1 $Cxx.name("multiple");
  virtual @2 $Cxx.name("virtual");
  unspecified @3 $Cxx.name("unspecified");
}

enum MSVCMajorVersion @0x95c4e85c8b049651 {
  msvC2010 @0 $Cxx.name("msv_c2010");
  msvC2012 @1 $Cxx.name("msv_c2012");
  msvC2013 @2 $Cxx.name("msv_c2013");
  msvC2015 @3 $Cxx.name("msv_c2015");
  msvC2017 @4 $Cxx.name("msv_c2017");
  msvC20175 @5 $Cxx.name("msv_c20175");
  msvC20177 @6 $Cxx.name("msv_c20177");
  msvC2019 @7 $Cxx.name("msv_c2019");
  msvC20198 @8 $Cxx.name("msv_c20198");
}

enum MSVtorDispMode @0xd30e950dab28014f {
  never @0 $Cxx.name("never");
  forVirtualBaseOverride @1 $Cxx.name("for_virtual_base_override");
  forVfTable @2 $Cxx.name("for_vf_table");
}

enum MapTypeTy @0xa12c4931ebd969e4 {
  to @0 $Cxx.name("to");
  link @1 $Cxx.name("link");
}

enum MethodRefFlags @0xf4e25430af1260cc {
  methodReferenceNone @0 $Cxx.name("method_reference_none");
  methodReferenceGetter @1 $Cxx.name("method_reference_getter");
  methodReferenceSetter @2 $Cxx.name("method_reference_setter");
}

enum ModifiableType @0xc45afde4959d91fe {
  untested @0 $Cxx.name("untested");
  modifiable @1 $Cxx.name("modifiable");
  rValue @2 $Cxx.name("r_value");
  function @3 $Cxx.name("function");
  lValueCast @4 $Cxx.name("l_value_cast");
  noSetterProperty @5 $Cxx.name("no_setter_property");
  constQualified @6 $Cxx.name("const_qualified");
  constQualifiedField @7 $Cxx.name("const_qualified_field");
  constAddrSpace @8 $Cxx.name("const_addr_space");
  arrayType @9 $Cxx.name("array_type");
  incompleteType @10 $Cxx.name("incomplete_type");
}

enum MultiVersionKind @0xd6aa1ba55a8d79af {
  none @0 $Cxx.name("none");
  target @1 $Cxx.name("target");
  cpuSpecific @2 $Cxx.name("cpu_specific");
  cpuDispatch @3 $Cxx.name("cpu_dispatch");
}

enum NameKind @0xd8c87b12039cdd9d {
  template @0 $Cxx.name("template");
  overloadedTemplate @1 $Cxx.name("overloaded_template");
  assumedTemplate @2 $Cxx.name("assumed_template");
  qualifiedTemplate @3 $Cxx.name("qualified_template");
  dependentTemplate @4 $Cxx.name("dependent_template");
  substTemplateTemplateParm @5 $Cxx.name("subst_template_template_parm");
  substTemplateTemplateParmPack @6 $Cxx.name("subst_template_template_parm_pack");
}

enum NeedExtraManglingDecl @0xabe9f759c85ffd44 {
  needExtraManglingDeclaration @0 $Cxx.name("need_extra_mangling_declaration");
}

enum NestedNameSpecifierDependence @0xb58b426c7eb181ac {
  unexpandedPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  error @3 $Cxx.name("error");
  none @4 $Cxx.name("none");
  dependentInstantiation @5 $Cxx.name("dependent_instantiation");
  all @6 $Cxx.name("all");
}

enum NewtypeKind @0x95c6c19824f23a5b {
  struct @0 $Cxx.name("struct");
  enum @1 $Cxx.name("enum");
}

enum NonOdrUseReason @0xbc90b6da0c76be85 {
  none @0 $Cxx.name("none");
  unevaluated @1 $Cxx.name("unevaluated");
  constant @2 $Cxx.name("constant");
  discarded @3 $Cxx.name("discarded");
}

enum NonceObjCInterface @0xadf095cf68be4795 {
  objCInterface @0 $Cxx.name("obj_c_interface");
}

enum NullabilityKind @0xa6da973fb1968963 {
  nonNull @0 $Cxx.name("non_null");
  nullable @1 $Cxx.name("nullable");
  unspecified @2 $Cxx.name("unspecified");
  nullableResult @3 $Cxx.name("nullable_result");
}

enum ObjCBridgeCastKind @0xfe79ee651274349f {
  bridge @0 $Cxx.name("bridge");
  bridgeTransfer @1 $Cxx.name("bridge_transfer");
  bridgeRetained @2 $Cxx.name("bridge_retained");
}

enum ObjCDispatchMethodKind @0xa708d587fb93a359 {
  legacy @0 $Cxx.name("legacy");
  nonLegacy @1 $Cxx.name("non_legacy");
  mixed @2 $Cxx.name("mixed");
}

enum ObjCInstanceTypeFamily @0xae0101c36e5b5d4f {
  none @0 $Cxx.name("none");
  array @1 $Cxx.name("array");
  dictionary @2 $Cxx.name("dictionary");
  singleton @3 $Cxx.name("singleton");
  initializer @4 $Cxx.name("initializer");
  returnsSelf @5 $Cxx.name("returns_self");
}

enum ObjCKeywordKind @0x994b0b2bc1ef881d {
  notKeyword @0 $Cxx.name("not_keyword");
  class @1 $Cxx.name("class");
  compatibilityAlias @2 $Cxx.name("compatibility_alias");
  definitions @3 $Cxx.name("definitions");
  encode @4 $Cxx.name("encode");
  objcEnd @5 $Cxx.name("objc_end");
  implementation @6 $Cxx.name("implementation");
  interface @7 $Cxx.name("interface");
  private @8 $Cxx.name("private");
  protected @9 $Cxx.name("protected");
  protocol @10 $Cxx.name("protocol");
  public @11 $Cxx.name("public");
  selector @12 $Cxx.name("selector");
  throw @13 $Cxx.name("throw");
  try @14 $Cxx.name("try");
  catch @15 $Cxx.name("catch");
  finally @16 $Cxx.name("finally");
  synchronized @17 $Cxx.name("synchronized");
  autoreleasepool @18 $Cxx.name("autoreleasepool");
  property @19 $Cxx.name("property");
  package @20 $Cxx.name("package");
  required @21 $Cxx.name("required");
  optional @22 $Cxx.name("optional");
  synthesize @23 $Cxx.name("synthesize");
  dynamic @24 $Cxx.name("dynamic");
  import @25 $Cxx.name("import");
  available @26 $Cxx.name("available");
}

enum ObjCLifetime @0xa408eab661edd8cd {
  none @0 $Cxx.name("none");
  explicitNone @1 $Cxx.name("explicit_none");
  strong @2 $Cxx.name("strong");
  weak @3 $Cxx.name("weak");
  autoreleasing @4 $Cxx.name("autoreleasing");
}

enum ObjCMethodFamily @0xce49434a6017454c {
  none @0 $Cxx.name("none");
  alloc @1 $Cxx.name("alloc");
  copy @2 $Cxx.name("copy");
  initializer @3 $Cxx.name("initializer");
  mutableCopy @4 $Cxx.name("mutable_copy");
  new @5 $Cxx.name("new");
  autorelease @6 $Cxx.name("autorelease");
  dealloc @7 $Cxx.name("dealloc");
  finalize @8 $Cxx.name("finalize");
  release @9 $Cxx.name("release");
  retain @10 $Cxx.name("retain");
  retainCount @11 $Cxx.name("retain_count");
  self @12 $Cxx.name("self");
  initialize @13 $Cxx.name("initialize");
  performSelector @14 $Cxx.name("perform_selector");
}

enum ObjCPropertyQueryKind @0xa276e57d28cfccfe {
  queryUnknown @0 $Cxx.name("query_unknown");
  queryInstance @1 $Cxx.name("query_instance");
  queryClass @2 $Cxx.name("query_class");
}

enum ObjCStringFormatFamily @0xdde65f902899f0f0 {
  none @0 $Cxx.name("none");
  nsString @1 $Cxx.name("ns_string");
  cfString @2 $Cxx.name("cf_string");
}

enum ObjCSubstitutionContext @0xfe76f31aa6ffcc0f {
  ordinary @0 $Cxx.name("ordinary");
  result @1 $Cxx.name("result");
  parameter @2 $Cxx.name("parameter");
  property @3 $Cxx.name("property");
  superclass @4 $Cxx.name("superclass");
}

enum ObjCTypeParamVariance @0x922a77f8ad69d2ca {
  invariant @0 $Cxx.name("invariant");
  covariant @1 $Cxx.name("covariant");
  contravariant @2 $Cxx.name("contravariant");
}

enum OnOffSwitch @0xc03acca21f78a637 {
  on @0 $Cxx.name("on");
  off @1 $Cxx.name("off");
  default @2 $Cxx.name("default");
}

enum OnStackType @0xc9934c62a8ffff41 {
  onStack @0 $Cxx.name("on_stack");
}

enum OpenMPAtomicDefaultMemOrderClauseKind @0xa615f421034ff656 {
  seqCst @0 $Cxx.name("seq_cst");
  acqRel @1 $Cxx.name("acq_rel");
  relaxed @2 $Cxx.name("relaxed");
  unknown @3 $Cxx.name("unknown");
}

enum OpenMPDefaultmapClauseKind @0xfcda07ef98ba7b58 {
  scalar @0 $Cxx.name("scalar");
  aggregate @1 $Cxx.name("aggregate");
  pointer @2 $Cxx.name("pointer");
  unknown @3 $Cxx.name("unknown");
}

enum OpenMPDefaultmapClauseModifier @0xdab3b8e73bafb20c {
  unknown @0 $Cxx.name("unknown");
  alloc @1 $Cxx.name("alloc");
  to @2 $Cxx.name("to");
  from @3 $Cxx.name("from");
  tofrom @4 $Cxx.name("tofrom");
  none @5 $Cxx.name("none");
  default @6 $Cxx.name("default");
  present @7 $Cxx.name("present");
}

enum OpenMPDependClauseKind @0x8e062ba0663aa345 {
  in @0 $Cxx.name("in");
  out @1 $Cxx.name("out");
  inout @2 $Cxx.name("inout");
  mutexinoutset @3 $Cxx.name("mutexinoutset");
  depobj @4 $Cxx.name("depobj");
  source @5 $Cxx.name("source");
  sink @6 $Cxx.name("sink");
  unknown @7 $Cxx.name("unknown");
}

enum OpenMPDeviceClauseModifier @0x90610da33778f759 {
  ancestor @0 $Cxx.name("ancestor");
  deviceNum @1 $Cxx.name("device_num");
  unknown @2 $Cxx.name("unknown");
}

enum OpenMPDeviceType @0xc2e0afcebc6f55d3 {
  host @0 $Cxx.name("host");
  nohost @1 $Cxx.name("nohost");
  any @2 $Cxx.name("any");
  unknown @3 $Cxx.name("unknown");
}

enum OpenMPDistScheduleClauseKind @0xcc204d15ba14701e {
  static @0 $Cxx.name("static");
  unknown @1 $Cxx.name("unknown");
}

enum OpenMPLastprivateModifier @0xa590c4c8530c16f5 {
  conditional @0 $Cxx.name("conditional");
  unknown @1 $Cxx.name("unknown");
}

enum OpenMPLinearClauseKind @0xc7e9028a318529ff {
  val @0 $Cxx.name("val");
  reference @1 $Cxx.name("reference");
  uval @2 $Cxx.name("uval");
  unknown @3 $Cxx.name("unknown");
}

enum OpenMPMapClauseKind @0x8f12c8db1934f6d4 {
  alloc @0 $Cxx.name("alloc");
  to @1 $Cxx.name("to");
  from @2 $Cxx.name("from");
  tofrom @3 $Cxx.name("tofrom");
  delete @4 $Cxx.name("delete");
  release @5 $Cxx.name("release");
  unknown @6 $Cxx.name("unknown");
}

enum OpenMPMapModifierKind @0xbd3a16ac761804b8 {
  unknown @0 $Cxx.name("unknown");
  always @1 $Cxx.name("always");
  close @2 $Cxx.name("close");
  mapper @3 $Cxx.name("mapper");
  present @4 $Cxx.name("present");
}

enum OpenMPMotionModifierKind @0xf350ab19bd5ebeb4 {
  motionmodifierMapper @0 $Cxx.name("motionmodifier_mapper");
  motionmodifierPresent @1 $Cxx.name("motionmodifier_present");
  motionmodifierUnknown @2 $Cxx.name("motionmodifier_unknown");
}

enum OpenMPOrderClauseKind @0xf5282f5ff7defab1 {
  concurrent @0 $Cxx.name("concurrent");
  unknown @1 $Cxx.name("unknown");
}

enum OpenMPReductionClauseModifier @0xd7ad612d57501935 {
  default @0 $Cxx.name("default");
  inscan @1 $Cxx.name("inscan");
  task @2 $Cxx.name("task");
  unknown @3 $Cxx.name("unknown");
}

enum OpenMPScheduleClauseKind @0xaba351464fdd7064 {
  static @0 $Cxx.name("static");
  dynamic @1 $Cxx.name("dynamic");
  guided @2 $Cxx.name("guided");
  auto @3 $Cxx.name("auto");
  runtime @4 $Cxx.name("runtime");
  unknown @5 $Cxx.name("unknown");
}

enum OpenMPScheduleClauseModifier @0x9c6f03057cad41f3 {
  unknown @0 $Cxx.name("unknown");
  monotonic @1 $Cxx.name("monotonic");
  nonmonotonic @2 $Cxx.name("nonmonotonic");
  simd @3 $Cxx.name("simd");
}

enum OptionType @0xdfce49417fa83014 {
  vectorize @0 $Cxx.name("vectorize");
  vectorizeWidth @1 $Cxx.name("vectorize_width");
  interleave @2 $Cxx.name("interleave");
  interleaveCount @3 $Cxx.name("interleave_count");
  unroll @4 $Cxx.name("unroll");
  unrollCount @5 $Cxx.name("unroll_count");
  unrollAndJam @6 $Cxx.name("unroll_and_jam");
  unrollAndJamCount @7 $Cxx.name("unroll_and_jam_count");
  pipelineDisabled @8 $Cxx.name("pipeline_disabled");
  pipelineInitiationInterval @9 $Cxx.name("pipeline_initiation_interval");
  distribute @10 $Cxx.name("distribute");
  vectorizePredicate @11 $Cxx.name("vectorize_predicate");
}

enum OverloadedOperatorKind @0x899b59d4c33ece1a {
  none @0 $Cxx.name("none");
  new @1 $Cxx.name("new");
  delete @2 $Cxx.name("delete");
  arrayNew @3 $Cxx.name("array_new");
  arrayDelete @4 $Cxx.name("array_delete");
  plus @5 $Cxx.name("plus");
  minus @6 $Cxx.name("minus");
  star @7 $Cxx.name("star");
  slash @8 $Cxx.name("slash");
  percent @9 $Cxx.name("percent");
  caret @10 $Cxx.name("caret");
  amp @11 $Cxx.name("amp");
  pipe @12 $Cxx.name("pipe");
  tilde @13 $Cxx.name("tilde");
  exclaim @14 $Cxx.name("exclaim");
  equal @15 $Cxx.name("equal");
  less @16 $Cxx.name("less");
  greater @17 $Cxx.name("greater");
  plusEqual @18 $Cxx.name("plus_equal");
  minusEqual @19 $Cxx.name("minus_equal");
  starEqual @20 $Cxx.name("star_equal");
  slashEqual @21 $Cxx.name("slash_equal");
  percentEqual @22 $Cxx.name("percent_equal");
  caretEqual @23 $Cxx.name("caret_equal");
  ampEqual @24 $Cxx.name("amp_equal");
  pipeEqual @25 $Cxx.name("pipe_equal");
  lessLess @26 $Cxx.name("less_less");
  greaterGreater @27 $Cxx.name("greater_greater");
  lessLessEqual @28 $Cxx.name("less_less_equal");
  greaterGreaterEqual @29 $Cxx.name("greater_greater_equal");
  equalEqual @30 $Cxx.name("equal_equal");
  exclaimEqual @31 $Cxx.name("exclaim_equal");
  lessEqual @32 $Cxx.name("less_equal");
  greaterEqual @33 $Cxx.name("greater_equal");
  spaceship @34 $Cxx.name("spaceship");
  ampAmp @35 $Cxx.name("amp_amp");
  pipePipe @36 $Cxx.name("pipe_pipe");
  plusPlus @37 $Cxx.name("plus_plus");
  minusMinus @38 $Cxx.name("minus_minus");
  comma @39 $Cxx.name("comma");
  arrowStar @40 $Cxx.name("arrow_star");
  arrow @41 $Cxx.name("arrow");
  call @42 $Cxx.name("call");
  subscript @43 $Cxx.name("subscript");
  conditional @44 $Cxx.name("conditional");
  coawait @45 $Cxx.name("coawait");
}

enum OverloadsShown @0xa12bd43253c78cd7 {
  all @0 $Cxx.name("all");
  best @1 $Cxx.name("best");
}

enum OwnershipKind @0xc9713bca971b62c9 {
  holds @0 $Cxx.name("holds");
  returns @1 $Cxx.name("returns");
  takes @2 $Cxx.name("takes");
}

enum PCSType @0x984d4daccbec5f31 {
  aapcs @0 $Cxx.name("aapcs");
  vfp @1 $Cxx.name("vfp");
}

enum PPKeywordKind @0x82effa20815955c8 {
  notKeyword @0 $Cxx.name("not_keyword");
  if @1 $Cxx.name("if");
  ifdef @2 $Cxx.name("ifdef");
  ifndef @3 $Cxx.name("ifndef");
  elif @4 $Cxx.name("elif");
  elifdef @5 $Cxx.name("elifdef");
  elifndef @6 $Cxx.name("elifndef");
  else @7 $Cxx.name("else");
  endif @8 $Cxx.name("endif");
  defined @9 $Cxx.name("defined");
  include @10 $Cxx.name("include");
  ucUcIncludeMacros @11 $Cxx.name("__include_macros");
  define @12 $Cxx.name("define");
  undef @13 $Cxx.name("undef");
  line @14 $Cxx.name("line");
  error @15 $Cxx.name("error");
  pragma @16 $Cxx.name("pragma");
  import @17 $Cxx.name("import");
  includeNext @18 $Cxx.name("include_next");
  warning @19 $Cxx.name("warning");
  identifier @20 $Cxx.name("identifier");
  sccs @21 $Cxx.name("sccs");
  assert @22 $Cxx.name("assert");
  unassert @23 $Cxx.name("unassert");
  ucUcPublicMacro @24 $Cxx.name("__public_macro");
  ucUcPrivateMacro @25 $Cxx.name("__private_macro");
}

enum ParameterABI @0xd71450dc2327753a {
  ordinary @0 $Cxx.name("ordinary");
  swiftIndirectResult @1 $Cxx.name("swift_indirect_result");
  swiftErrorResult @2 $Cxx.name("swift_error_result");
  swiftContext @3 $Cxx.name("swift_context");
  swiftAsyncContext @4 $Cxx.name("swift_async_context");
}

enum ParenLocsOffsets @0xeee42a89fc6e7409 {
  lParen @0 $Cxx.name("l_paren");
  rParen @1 $Cxx.name("r_paren");
  total @2 $Cxx.name("total");
}

enum PragmaFloatControlKind @0xc8a5f773a4e7a749 {
  unknown @0 $Cxx.name("unknown");
  precise @1 $Cxx.name("precise");
  noPrecise @2 $Cxx.name("no_precise");
  except @3 $Cxx.name("except");
  noExcept @4 $Cxx.name("no_except");
  push @5 $Cxx.name("push");
  pop @6 $Cxx.name("pop");
}

enum PragmaMSCommentKind @0xe09b297844ff08bb {
  unknown @0 $Cxx.name("unknown");
  linker @1 $Cxx.name("linker");
  lib @2 $Cxx.name("lib");
  compiler @3 $Cxx.name("compiler");
  exeString @4 $Cxx.name("exe_string");
  user @5 $Cxx.name("user");
}

enum PragmaMSPointersToMembersKind @0xbadad4917533bd3c {
  bestCase @0 $Cxx.name("best_case");
  fullGeneralitySingleInheritance @1 $Cxx.name("full_generality_single_inheritance");
  fullGeneralityMultipleInheritance @2 $Cxx.name("full_generality_multiple_inheritance");
  fullGeneralityVirtualInheritance @3 $Cxx.name("full_generality_virtual_inheritance");
}

enum PragmaMSStructKind @0xfab23c522e2afed4 {
  off @0 $Cxx.name("off");
  on @1 $Cxx.name("on");
}

enum PragmaSectionFlag @0xaaacf25f0079678e {
  none @0 $Cxx.name("none");
  read @1 $Cxx.name("read");
  write @2 $Cxx.name("write");
  execute @3 $Cxx.name("execute");
  implicit @4 $Cxx.name("implicit");
  zeroInitializer @5 $Cxx.name("zero_initializer");
  invalid @6 $Cxx.name("invalid");
}

enum ProfileInstrKind @0xf19d1c8c04608ab9 {
  profileNone @0 $Cxx.name("profile_none");
  profileClangInstr @1 $Cxx.name("profile_clang_instr");
  profileIrInstr @2 $Cxx.name("profile_ir_instr");
  profileCsirInstr @3 $Cxx.name("profile_csir_instr");
}

enum RangeExprOffset @0x8dea69908fbb2749 {
  begin @0 $Cxx.name("begin");
  end @1 $Cxx.name("end");
  step @2 $Cxx.name("step");
  total @3 $Cxx.name("total");
}

enum RangeLocOffset @0xfb9e64d9c6c761c0 {
  assignToken @0 $Cxx.name("assign_token");
  secondColonToken @1 $Cxx.name("second_colon_token");
  total @2 $Cxx.name("total");
}

enum RefQualifierKind @0xe49bd7951a6ae539 {
  none @0 $Cxx.name("none");
  lValue @1 $Cxx.name("l_value");
  rValue @2 $Cxx.name("r_value");
}

enum RemarkKind @0xb3388fa0a2e99dd9 {
  missing @0 $Cxx.name("missing");
  enabled @1 $Cxx.name("enabled");
  enabledEverything @2 $Cxx.name("enabled_everything");
  disabled @3 $Cxx.name("disabled");
  disabledEverything @4 $Cxx.name("disabled_everything");
  withPattern @5 $Cxx.name("with_pattern");
}

enum ReservedIdentifierStatus @0xd4129a1d4a376c46 {
  notReserved @0 $Cxx.name("not_reserved");
  startsWithUnderscoreAtGlobalScope @1 $Cxx.name("starts_with_underscore_at_global_scope");
  startsWithDoubleUnderscore @2 $Cxx.name("starts_with_double_underscore");
  startsWithUnderscoreFollowedByCapitalLetter @3 $Cxx.name("starts_with_underscore_followed_by_capital_letter");
  containsDoubleUnderscore @4 $Cxx.name("contains_double_underscore");
}

enum SFINAEResponse @0xdb0cea818b80588c {
  substitutionFailure @0 $Cxx.name("substitution_failure");
  suppress @1 $Cxx.name("suppress");
  report @2 $Cxx.name("report");
  accessControl @3 $Cxx.name("access_control");
}

enum SYCLMajorVersion @0xa2f704290d385caa {
  versionNone @0 $Cxx.name("version_none");
  version2017 @1 $Cxx.name("version2017");
  version2020 @2 $Cxx.name("version2020");
  # Skipped repeat pasta::kDefault
}

enum SanitizerOrdinal @0xff7feae60091ee8e {
  address @0 $Cxx.name("address");
  pointerCompare @1 $Cxx.name("pointer_compare");
  pointerSubtract @2 $Cxx.name("pointer_subtract");
  kernelAddress @3 $Cxx.name("kernel_address");
  hwAddress @4 $Cxx.name("hw_address");
  kernelHwAddress @5 $Cxx.name("kernel_hw_address");
  memoryTag @6 $Cxx.name("memory_tag");
  memory @7 $Cxx.name("memory");
  kernelMemory @8 $Cxx.name("kernel_memory");
  fuzzer @9 $Cxx.name("fuzzer");
  fuzzerNoLink @10 $Cxx.name("fuzzer_no_link");
  thread @11 $Cxx.name("thread");
  leak @12 $Cxx.name("leak");
  alignment @13 $Cxx.name("alignment");
  arrayBounds @14 $Cxx.name("array_bounds");
  boolean @15 $Cxx.name("boolean");
  builtin @16 $Cxx.name("builtin");
  enum @17 $Cxx.name("enum");
  floatCastOverflow @18 $Cxx.name("float_cast_overflow");
  floatDivideByZero @19 $Cxx.name("float_divide_by_zero");
  function @20 $Cxx.name("function");
  integerDivideByZero @21 $Cxx.name("integer_divide_by_zero");
  nonnullAttribute @22 $Cxx.name("nonnull_attribute");
  null @23 $Cxx.name("null__");
  nullabilityArgument @24 $Cxx.name("nullability_argument");
  nullabilityAssign @25 $Cxx.name("nullability_assign");
  nullabilityReturn @26 $Cxx.name("nullability_return");
  nullabilityGroup @27 $Cxx.name("nullability_group");
  objectSize @28 $Cxx.name("object_size");
  pointerOverflow @29 $Cxx.name("pointer_overflow");
  return @30 $Cxx.name("return");
  returnsNonnullAttribute @31 $Cxx.name("returns_nonnull_attribute");
  shiftBase @32 $Cxx.name("shift_base");
  shiftExponent @33 $Cxx.name("shift_exponent");
  shiftGroup @34 $Cxx.name("shift_group");
  signedIntegerOverflow @35 $Cxx.name("signed_integer_overflow");
  unreachable @36 $Cxx.name("unreachable");
  vlaBound @37 $Cxx.name("vla_bound");
  vptr @38 $Cxx.name("vptr");
  unsignedIntegerOverflow @39 $Cxx.name("unsigned_integer_overflow");
  unsignedShiftBase @40 $Cxx.name("unsigned_shift_base");
  dataFlow @41 $Cxx.name("data_flow");
  cfiCastStrict @42 $Cxx.name("cfi_cast_strict");
  cfiDerivedCast @43 $Cxx.name("cfi_derived_cast");
  cfiiCall @44 $Cxx.name("cfii_call");
  cfimfCall @45 $Cxx.name("cfimf_call");
  cfiUnrelatedCast @46 $Cxx.name("cfi_unrelated_cast");
  cfinvCall @47 $Cxx.name("cfinv_call");
  cfivCall @48 $Cxx.name("cfiv_call");
  cfiGroup @49 $Cxx.name("cfi_group");
  safeStack @50 $Cxx.name("safe_stack");
  shadowCallStack @51 $Cxx.name("shadow_call_stack");
  undefinedGroup @52 $Cxx.name("undefined_group");
  undefinedTrapGroup @53 $Cxx.name("undefined_trap_group");
  implicitUnsignedIntegerTruncation @54 $Cxx.name("implicit_unsigned_integer_truncation");
  implicitSignedIntegerTruncation @55 $Cxx.name("implicit_signed_integer_truncation");
  implicitIntegerTruncationGroup @56 $Cxx.name("implicit_integer_truncation_group");
  implicitIntegerSignChange @57 $Cxx.name("implicit_integer_sign_change");
  implicitIntegerArithmeticValueChangeGroup @58 $Cxx.name("implicit_integer_arithmetic_value_change_group");
  objCCast @59 $Cxx.name("obj_c_cast");
  implicitConversionGroup @60 $Cxx.name("implicit_conversion_group");
  integerGroup @61 $Cxx.name("integer_group");
  localBounds @62 $Cxx.name("local_bounds");
  boundsGroup @63 $Cxx.name("bounds_group");
  scudo @64 $Cxx.name("scudo");
  allGroup @65 $Cxx.name("all_group");
  count @66 $Cxx.name("count");
}

enum SelectorLocationsKind @0xd0f319ff56604d2e {
  nonStandard @0 $Cxx.name("non_standard");
  standardNoSpace @1 $Cxx.name("standard_no_space");
  standardWithSpace @2 $Cxx.name("standard_with_space");
}

enum SignReturnAddressKeyKind @0xbb405a4adf266b91 {
  aKey @0 $Cxx.name("a_key");
  bKey @1 $Cxx.name("b_key");
}

enum SignReturnAddressScopeKind @0xbb64d86408f6c857 {
  none @0 $Cxx.name("none");
  nonLeaf @1 $Cxx.name("non_leaf");
  all @2 $Cxx.name("all");
}

enum SignedOverflowBehaviorTy @0xf8fa6a5b5e06e1ba {
  undefined @0 $Cxx.name("undefined");
  defined @1 $Cxx.name("defined");
  trapping @2 $Cxx.name("trapping");
}

enum SpecialMemberFlags @0xad56be604aa3d69a {
  defaultConstructor @0 $Cxx.name("default_constructor");
  copyConstructor @1 $Cxx.name("copy_constructor");
  moveConstructor @2 $Cxx.name("move_constructor");
  copyAssignment @3 $Cxx.name("copy_assignment");
  moveAssignment @4 $Cxx.name("move_assignment");
  destructor @5 $Cxx.name("destructor");
  all @6 $Cxx.name("all");
}

enum SpecifierKind @0xa0dfdbbf2ab2d652 {
  identifier @0 $Cxx.name("identifier");
  namespace @1 $Cxx.name("namespace");
  namespaceAlias @2 $Cxx.name("namespace_alias");
  typeSpec @3 $Cxx.name("type_spec");
  typeSpecWithTemplate @4 $Cxx.name("type_spec_with_template");
  global @5 $Cxx.name("global");
  super @6 $Cxx.name("super");
}

enum Spelling @0xf75ee4f457170972 {
  gnuAarch64VectorPcs @0 $Cxx.name("gnu_aarch64_vector_pcs");
  cxX11ClangAarch64VectorPcs @1 $Cxx.name("cx_x11_clang_aarch64_vector_pcs");
  c2XclangAarch64VectorPcs @2 $Cxx.name("c2_xclang_aarch64_vector_pcs");
  spellingNotCalculated @3 $Cxx.name("spelling_not_calculated");
}

enum StackProtectorMode @0xcaa41999a995d82c {
  off @0 $Cxx.name("off");
  on @1 $Cxx.name("on");
  strong @2 $Cxx.name("strong");
  req @3 $Cxx.name("req");
}

enum StorageClass @0xda0542391be3aa63 {
  none @0 $Cxx.name("none");
  extern @1 $Cxx.name("extern");
  static @2 $Cxx.name("static");
  privateExtern @3 $Cxx.name("private_extern");
  auto @4 $Cxx.name("auto");
  register @5 $Cxx.name("register");
}

enum StorageDuration @0xe1a5462cfd90bc60 {
  fullExpression @0 $Cxx.name("full_expression");
  automatic @1 $Cxx.name("automatic");
  thread @2 $Cxx.name("thread");
  static @3 $Cxx.name("static");
  dynamic @4 $Cxx.name("dynamic");
}

enum StoredNameKind @0xc3f93be84426e780 {
  storedIdentifier @0 $Cxx.name("stored_identifier");
  storedObjCZeroArgumentSelector @1 $Cxx.name("stored_obj_c_zero_argument_selector");
  storedObjCOneArgumentSelector @2 $Cxx.name("stored_obj_c_one_argument_selector");
  storedCxxConstructorName @3 $Cxx.name("stored_cxx_constructor_name");
  storedCxxDestructorName @4 $Cxx.name("stored_cxx_destructor_name");
  storedCxxConversionFunctionName @5 $Cxx.name("stored_cxx_conversion_function_name");
  storedCxxOperatorName @6 $Cxx.name("stored_cxx_operator_name");
  storedDeclarationNameExtra @7 $Cxx.name("stored_declaration_name_extra");
  # Skipped repeat pasta::kPointerMask
  uncommonNameKindOffset @8 $Cxx.name("uncommon_name_kind_offset");
}

enum StoredSpecifierKind @0xee14b80df2376eb6 {
  storedIdentifier @0 $Cxx.name("stored_identifier");
  storedDeclaration @1 $Cxx.name("stored_declaration");
  storedTypeSpec @2 $Cxx.name("stored_type_spec");
  storedTypeSpecWithTemplate @3 $Cxx.name("stored_type_spec_with_template");
}

enum StructReturnConventionKind @0x92e3ba5b6fbf9355 {
  default @0 $Cxx.name("default");
  onStack @1 $Cxx.name("on_stack");
  inRegs @2 $Cxx.name("in_regs");
}

enum SubExpr @0x81f7bd3f8a7bb376 {
  callee @0 $Cxx.name("callee");
  lhs @1 $Cxx.name("lhs");
  rhs @2 $Cxx.name("rhs");
  count @3 $Cxx.name("count");
}

enum SubStmt @0xda7583e7923eba0b {
  body @0 $Cxx.name("body");
  promise @1 $Cxx.name("promise");
  initializerSuspend @2 $Cxx.name("initializer_suspend");
  finalSuspend @3 $Cxx.name("final_suspend");
  onException @4 $Cxx.name("on_exception");
  onFallthrough @5 $Cxx.name("on_fallthrough");
  allocate @6 $Cxx.name("allocate");
  deallocate @7 $Cxx.name("deallocate");
  returnValue @8 $Cxx.name("return_value");
  resultDeclaration @9 $Cxx.name("result_declaration");
  returnStatement @10 $Cxx.name("return_statement");
  returnStatementOnAllocFailure @11 $Cxx.name("return_statement_on_alloc_failure");
}

enum SyncScope @0xa360f2801c53e118 {
  openClWorkGroup @0 $Cxx.name("open_cl_work_group");
  openClDevice @1 $Cxx.name("open_cl_device");
  openClAllSvmDevices @2 $Cxx.name("open_cl_all_svm_devices");
  openClSubGroup @3 $Cxx.name("open_cl_sub_group");
}

enum Syntax @0xfabc370c94a4c08b {
  gnu @0 $Cxx.name("gnu");
  cxX11 @1 $Cxx.name("cx_x11");
  c2UcX @2 $Cxx.name("c2_x");
  declspec @3 $Cxx.name("declspec");
  microsoft @4 $Cxx.name("microsoft");
  keyword @5 $Cxx.name("keyword");
  pragma @6 $Cxx.name("pragma");
  contextSensitiveKeyword @7 $Cxx.name("context_sensitive_keyword");
}

enum TLSModel @0xe03f72019c3fce6b {
  generalDynamicTlsModel @0 $Cxx.name("general_dynamic_tls_model");
  localDynamicTlsModel @1 $Cxx.name("local_dynamic_tls_model");
  initialExecTlsModel @2 $Cxx.name("initial_exec_tls_model");
  localExecTlsModel @3 $Cxx.name("local_exec_tls_model");
}

enum TQ @0xcc22be3ea9b39aac {
  const @0 $Cxx.name("const");
  restrict @1 $Cxx.name("restrict");
  volatile @2 $Cxx.name("volatile");
  cvrMask @3 $Cxx.name("cvr_mask");
}

enum TagTypeKind @0xbfa845fcdbd00864 {
  struct @0 $Cxx.name("struct");
  interface @1 $Cxx.name("interface");
  union @2 $Cxx.name("union");
  class @3 $Cxx.name("class");
  enum @4 $Cxx.name("enum");
}

enum TailPaddingUseRules @0xde3a19dc88518d95 {
  alwaysUseTailPadding @0 $Cxx.name("always_use_tail_padding");
  useTailPaddingUnlessPoD03 @1 $Cxx.name("use_tail_padding_unless_po_d03");
  useTailPaddingUnlessPoD11 @2 $Cxx.name("use_tail_padding_unless_po_d11");
}

enum TemplateArgumentDependence @0x97cee4d7054bd6cf {
  unexpandedPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  error @3 $Cxx.name("error");
  none @4 $Cxx.name("none");
  dependentInstantiation @5 $Cxx.name("dependent_instantiation");
  all @6 $Cxx.name("all");
}

enum TemplateNameDependence @0xb934bbc3751c811e {
  unexpandedPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  error @3 $Cxx.name("error");
  none @4 $Cxx.name("none");
  dependentInstantiation @5 $Cxx.name("dependent_instantiation");
  all @6 $Cxx.name("all");
}

enum TemplateSpecializationKind @0xc45c2bfe2b2d2105 {
  undeclared @0 $Cxx.name("undeclared");
  implicitInstantiation @1 $Cxx.name("implicit_instantiation");
  explicitSpecialization @2 $Cxx.name("explicit_specialization");
  explicitInstantiationDeclaration @3 $Cxx.name("explicit_instantiation_declaration");
  explicitInstantiationDefinition @4 $Cxx.name("explicit_instantiation_definition");
}

enum TextDiagnosticFormat @0x9fd371c8db18c101 {
  clang @0 $Cxx.name("clang");
  msvc @1 $Cxx.name("msvc");
  vi @2 $Cxx.name("vi");
}

enum ThreadModelKind @0xf118796360bfd7be {
  posix @0 $Cxx.name("posix");
  single @1 $Cxx.name("single");
}

enum ThreadStorageClassSpecifier @0xa5e43d0340490a97 {
  unspecified @0 $Cxx.name("unspecified");
  ucUcThread @1 $Cxx.name("__thread");
  threadLocal @2 $Cxx.name("thread_local");
  ucThreadLocal @3 $Cxx.name("_thread_local");
}

enum TokenKind @0xedc5e766e7f89f15 {
  unknown @0 $Cxx.name("unknown");
  endOfFile @1 $Cxx.name("end_of_file");
  endOfDirective @2 $Cxx.name("end_of_directive");
  codeCompletion @3 $Cxx.name("code_completion");
  comment @4 $Cxx.name("comment");
  identifier @5 $Cxx.name("identifier");
  whitespace @6 $Cxx.name("whitespace");
  numericConstant @7 $Cxx.name("numeric_constant");
  characterConstant @8 $Cxx.name("character_constant");
  wideCharacterConstant @9 $Cxx.name("wide_character_constant");
  utf8CharacterConstant @10 $Cxx.name("utf8_character_constant");
  utf16CharacterConstant @11 $Cxx.name("utf16_character_constant");
  utf32CharacterConstant @12 $Cxx.name("utf32_character_constant");
  stringLiteral @13 $Cxx.name("string_literal");
  wideStringLiteral @14 $Cxx.name("wide_string_literal");
  headerName @15 $Cxx.name("header_name");
  utf8StringLiteral @16 $Cxx.name("utf8_string_literal");
  utf16StringLiteral @17 $Cxx.name("utf16_string_literal");
  utf32StringLiteral @18 $Cxx.name("utf32_string_literal");
  lSquare @19 $Cxx.name("l_square");
  rSquare @20 $Cxx.name("r_square");
  lParenthesis @21 $Cxx.name("l_parenthesis");
  rParenthesis @22 $Cxx.name("r_parenthesis");
  lBrace @23 $Cxx.name("l_brace");
  rBrace @24 $Cxx.name("r_brace");
  period @25 $Cxx.name("period");
  ellipsis @26 $Cxx.name("ellipsis");
  amp @27 $Cxx.name("amp");
  ampAmp @28 $Cxx.name("amp_amp");
  ampEqual @29 $Cxx.name("amp_equal");
  star @30 $Cxx.name("star");
  starEqual @31 $Cxx.name("star_equal");
  plus @32 $Cxx.name("plus");
  plusPlus @33 $Cxx.name("plus_plus");
  plusEqual @34 $Cxx.name("plus_equal");
  minus @35 $Cxx.name("minus");
  arrow @36 $Cxx.name("arrow");
  minusMinus @37 $Cxx.name("minus_minus");
  minusEqual @38 $Cxx.name("minus_equal");
  tilde @39 $Cxx.name("tilde");
  exclaim @40 $Cxx.name("exclaim");
  exclaimEqual @41 $Cxx.name("exclaim_equal");
  slash @42 $Cxx.name("slash");
  slashEqual @43 $Cxx.name("slash_equal");
  percent @44 $Cxx.name("percent");
  percentEqual @45 $Cxx.name("percent_equal");
  less @46 $Cxx.name("less");
  lessLess @47 $Cxx.name("less_less");
  lessEqual @48 $Cxx.name("less_equal");
  lessLessEqual @49 $Cxx.name("less_less_equal");
  spaceship @50 $Cxx.name("spaceship");
  greater @51 $Cxx.name("greater");
  greaterGreater @52 $Cxx.name("greater_greater");
  greaterEqual @53 $Cxx.name("greater_equal");
  greaterGreaterEqual @54 $Cxx.name("greater_greater_equal");
  caret @55 $Cxx.name("caret");
  caretEqual @56 $Cxx.name("caret_equal");
  pipe @57 $Cxx.name("pipe");
  pipePipe @58 $Cxx.name("pipe_pipe");
  pipeEqual @59 $Cxx.name("pipe_equal");
  question @60 $Cxx.name("question");
  colon @61 $Cxx.name("colon");
  semi @62 $Cxx.name("semi");
  equal @63 $Cxx.name("equal");
  equalEqual @64 $Cxx.name("equal_equal");
  comma @65 $Cxx.name("comma");
  hash @66 $Cxx.name("hash");
  hashHash @67 $Cxx.name("hash_hash");
  hashat @68 $Cxx.name("hashat");
  periodStar @69 $Cxx.name("period_star");
  arrowStar @70 $Cxx.name("arrow_star");
  colonColon @71 $Cxx.name("colon_colon");
  at @72 $Cxx.name("at");
  lessLessLess @73 $Cxx.name("less_less_less");
  greaterGreaterGreater @74 $Cxx.name("greater_greater_greater");
  caretcaret @75 $Cxx.name("caretcaret");
  keywordAuto @76 $Cxx.name("keyword_auto");
  keywordBreak @77 $Cxx.name("keyword_break");
  keywordCase @78 $Cxx.name("keyword_case");
  keywordCharacter @79 $Cxx.name("keyword_character");
  keywordConst @80 $Cxx.name("keyword_const");
  keywordContinue @81 $Cxx.name("keyword_continue");
  keywordDefault @82 $Cxx.name("keyword_default");
  keywordDo @83 $Cxx.name("keyword_do");
  keywordDouble @84 $Cxx.name("keyword_double");
  keywordElse @85 $Cxx.name("keyword_else");
  keywordEnum @86 $Cxx.name("keyword_enum");
  keywordExtern @87 $Cxx.name("keyword_extern");
  keywordFloat @88 $Cxx.name("keyword_float");
  keywordFor @89 $Cxx.name("keyword_for");
  keywordGoto @90 $Cxx.name("keyword_goto");
  keywordIf @91 $Cxx.name("keyword_if");
  keywordInline @92 $Cxx.name("keyword_inline");
  keywordInt @93 $Cxx.name("keyword_int");
  keywordUcExtInt @94 $Cxx.name("keyword__ext_int");
  keywordLong @95 $Cxx.name("keyword_long");
  keywordRegister @96 $Cxx.name("keyword_register");
  keywordRestrict @97 $Cxx.name("keyword_restrict");
  keywordReturn @98 $Cxx.name("keyword_return");
  keywordShort @99 $Cxx.name("keyword_short");
  keywordSigned @100 $Cxx.name("keyword_signed");
  keywordSizeof @101 $Cxx.name("keyword_sizeof");
  keywordStatic @102 $Cxx.name("keyword_static");
  keywordStruct @103 $Cxx.name("keyword_struct");
  keywordSwitch @104 $Cxx.name("keyword_switch");
  keywordTypedef @105 $Cxx.name("keyword_typedef");
  keywordUnion @106 $Cxx.name("keyword_union");
  keywordUnsigned @107 $Cxx.name("keyword_unsigned");
  keywordVoid @108 $Cxx.name("keyword_void");
  keywordVolatile @109 $Cxx.name("keyword_volatile");
  keywordWhile @110 $Cxx.name("keyword_while");
  keywordUcAlignas @111 $Cxx.name("keyword__alignas");
  keywordUcAlignof @112 $Cxx.name("keyword__alignof");
  keywordUcAtomic @113 $Cxx.name("keyword__atomic");
  keywordUcBoolean @114 $Cxx.name("keyword__boolean");
  keywordUcComplex @115 $Cxx.name("keyword__complex");
  keywordUcGeneric @116 $Cxx.name("keyword__generic");
  keywordUcImaginary @117 $Cxx.name("keyword__imaginary");
  keywordUcNoreturn @118 $Cxx.name("keyword__noreturn");
  keywordUcStaticAssert @119 $Cxx.name("keyword__static_assert");
  keywordUcThreadLocal @120 $Cxx.name("keyword__thread_local");
  keywordUcUcFunc @121 $Cxx.name("keyword___func__");
  keywordUcUcObjcYes @122 $Cxx.name("keyword___objc_yes");
  keywordUcUcObjcNo @123 $Cxx.name("keyword___objc_no");
  keywordAssembly @124 $Cxx.name("keyword_assembly");
  keywordBoolean @125 $Cxx.name("keyword_boolean");
  keywordCatch @126 $Cxx.name("keyword_catch");
  keywordClass @127 $Cxx.name("keyword_class");
  keywordConstCast @128 $Cxx.name("keyword_const_cast");
  keywordDelete @129 $Cxx.name("keyword_delete");
  keywordDynamicCast @130 $Cxx.name("keyword_dynamic_cast");
  keywordExplicit @131 $Cxx.name("keyword_explicit");
  keywordExport @132 $Cxx.name("keyword_export");
  keywordFalse @133 $Cxx.name("keyword_false");
  keywordFriend @134 $Cxx.name("keyword_friend");
  keywordMutable @135 $Cxx.name("keyword_mutable");
  keywordNamespace @136 $Cxx.name("keyword_namespace");
  keywordNew @137 $Cxx.name("keyword_new");
  keywordOperator @138 $Cxx.name("keyword_operator");
  keywordPrivate @139 $Cxx.name("keyword_private");
  keywordProtected @140 $Cxx.name("keyword_protected");
  keywordPublic @141 $Cxx.name("keyword_public");
  keywordReinterpretCast @142 $Cxx.name("keyword_reinterpret_cast");
  keywordStaticCast @143 $Cxx.name("keyword_static_cast");
  keywordTemplate @144 $Cxx.name("keyword_template");
  keywordThis @145 $Cxx.name("keyword_this");
  keywordThrow @146 $Cxx.name("keyword_throw");
  keywordTrue @147 $Cxx.name("keyword_true");
  keywordTry @148 $Cxx.name("keyword_try");
  keywordTypename @149 $Cxx.name("keyword_typename");
  keywordTypeid @150 $Cxx.name("keyword_typeid");
  keywordUsing @151 $Cxx.name("keyword_using");
  keywordVirtual @152 $Cxx.name("keyword_virtual");
  keywordWcharUcT @153 $Cxx.name("keyword_wchar_t");
  keywordAlignas @154 $Cxx.name("keyword_alignas");
  keywordAlignof @155 $Cxx.name("keyword_alignof");
  keywordChar16UcT @156 $Cxx.name("keyword_char16_t");
  keywordChar32UcT @157 $Cxx.name("keyword_char32_t");
  keywordConstexpr @158 $Cxx.name("keyword_constexpr");
  keywordDecltype @159 $Cxx.name("keyword_decltype");
  keywordNoexcept @160 $Cxx.name("keyword_noexcept");
  keywordNullptr @161 $Cxx.name("keyword_nullptr");
  keywordStaticAssert @162 $Cxx.name("keyword_static_assert");
  keywordThreadLocal @163 $Cxx.name("keyword_thread_local");
  keywordConcept @164 $Cxx.name("keyword_concept");
  keywordRequires @165 $Cxx.name("keyword_requires");
  keywordCoAwait @166 $Cxx.name("keyword_co_await");
  keywordCoReturn @167 $Cxx.name("keyword_co_return");
  keywordCoYield @168 $Cxx.name("keyword_co_yield");
  keywordModule @169 $Cxx.name("keyword_module");
  keywordImport @170 $Cxx.name("keyword_import");
  keywordConsteval @171 $Cxx.name("keyword_consteval");
  keywordConstinit @172 $Cxx.name("keyword_constinit");
  keywordChar8UcT @173 $Cxx.name("keyword_char8_t");
  keywordUcFloat16 @174 $Cxx.name("keyword__float16");
  keywordUcAccum @175 $Cxx.name("keyword__accum");
  keywordUcFract @176 $Cxx.name("keyword__fract");
  keywordUcSat @177 $Cxx.name("keyword__sat");
  keywordUcDecimal32 @178 $Cxx.name("keyword__decimal32");
  keywordUcDecimal64 @179 $Cxx.name("keyword__decimal64");
  keywordUcDecimal128 @180 $Cxx.name("keyword__decimal128");
  keywordUcUcNull @181 $Cxx.name("keyword___null");
  keywordUcUcAlignof @182 $Cxx.name("keyword___alignof");
  keywordUcUcAttribute @183 $Cxx.name("keyword___attribute");
  keywordUcUcBuiltinChooseExpression @184 $Cxx.name("keyword___builtin_choose_expression");
  keywordUcUcBuiltinOffsetof @185 $Cxx.name("keyword___builtin_offsetof");
  keywordUcUcBuiltinFile @186 $Cxx.name("keyword___builtin_file");
  keywordUcUcBuiltinFunction @187 $Cxx.name("keyword___builtin_function");
  keywordUcUcBuiltinLine @188 $Cxx.name("keyword___builtin_line");
  keywordUcUcBuiltinColumn @189 $Cxx.name("keyword___builtin_column");
  keywordUcUcBuiltinTypesCompatibleUcP @190 $Cxx.name("keyword___builtin_types_compatible_p");
  keywordUcUcBuiltinVaArgument @191 $Cxx.name("keyword___builtin_va_argument");
  keywordUcUcExtension @192 $Cxx.name("keyword___extension__");
  keywordUcUcFloat128 @193 $Cxx.name("keyword___float128");
  keywordUcUcImag @194 $Cxx.name("keyword___imag");
  keywordUcUcInt128 @195 $Cxx.name("keyword___int128");
  keywordUcUcLabel @196 $Cxx.name("keyword___label__");
  keywordUcUcReal @197 $Cxx.name("keyword___real");
  keywordUcUcThread @198 $Cxx.name("keyword___thread");
  keywordUcUcFunction @199 $Cxx.name("keyword___function__");
  keywordUcUcPrettyfunction @200 $Cxx.name("keyword___prettyfunction__");
  keywordUcUcAutoType @201 $Cxx.name("keyword___auto_type");
  keywordTypeof @202 $Cxx.name("keyword_typeof");
  keywordUcUcFuncdname @203 $Cxx.name("keyword___funcdname__");
  keywordUcUcFuncsig @204 $Cxx.name("keyword___funcsig__");
  keywordLfunction @205 $Cxx.name("keyword_lfunction__");
  keywordLfuncsig @206 $Cxx.name("keyword_lfuncsig__");
  keywordUcUcIsInterfaceClass @207 $Cxx.name("keyword___is_interface_class");
  keywordUcUcIsSealed @208 $Cxx.name("keyword___is_sealed");
  keywordUcUcIsDestructible @209 $Cxx.name("keyword___is_destructible");
  keywordUcUcIsTriviallyDestructible @210 $Cxx.name("keyword___is_trivially_destructible");
  keywordUcUcIsNothrowDestructible @211 $Cxx.name("keyword___is_nothrow_destructible");
  keywordUcUcIsNothrowAssignable @212 $Cxx.name("keyword___is_nothrow_assignable");
  keywordUcUcIsConstructible @213 $Cxx.name("keyword___is_constructible");
  keywordUcUcIsNothrowConstructible @214 $Cxx.name("keyword___is_nothrow_constructible");
  keywordUcUcIsAssignable @215 $Cxx.name("keyword___is_assignable");
  keywordUcUcHasNothrowMoveAssign @216 $Cxx.name("keyword___has_nothrow_move_assign");
  keywordUcUcHasTrivialMoveAssign @217 $Cxx.name("keyword___has_trivial_move_assign");
  keywordUcUcHasTrivialMoveConstructor @218 $Cxx.name("keyword___has_trivial_move_constructor");
  keywordUcUcHasNothrowAssign @219 $Cxx.name("keyword___has_nothrow_assign");
  keywordUcUcHasNothrowCopy @220 $Cxx.name("keyword___has_nothrow_copy");
  keywordUcUcHasNothrowConstructor @221 $Cxx.name("keyword___has_nothrow_constructor");
  keywordUcUcHasTrivialAssign @222 $Cxx.name("keyword___has_trivial_assign");
  keywordUcUcHasTrivialCopy @223 $Cxx.name("keyword___has_trivial_copy");
  keywordUcUcHasTrivialConstructor @224 $Cxx.name("keyword___has_trivial_constructor");
  keywordUcUcHasTrivialDestructor @225 $Cxx.name("keyword___has_trivial_destructor");
  keywordUcUcHasVirtualDestructor @226 $Cxx.name("keyword___has_virtual_destructor");
  keywordUcUcIsAbstract @227 $Cxx.name("keyword___is_abstract");
  keywordUcUcIsAggregate @228 $Cxx.name("keyword___is_aggregate");
  keywordUcUcIsBaseOf @229 $Cxx.name("keyword___is_base_of");
  keywordUcUcIsClass @230 $Cxx.name("keyword___is_class");
  keywordUcUcIsConvertibleTo @231 $Cxx.name("keyword___is_convertible_to");
  keywordUcUcIsEmpty @232 $Cxx.name("keyword___is_empty");
  keywordUcUcIsEnum @233 $Cxx.name("keyword___is_enum");
  keywordUcUcIsFinal @234 $Cxx.name("keyword___is_final");
  keywordUcUcIsLiteral @235 $Cxx.name("keyword___is_literal");
  keywordUcUcIsPod @236 $Cxx.name("keyword___is_pod");
  keywordUcUcIsPolymorphic @237 $Cxx.name("keyword___is_polymorphic");
  keywordUcUcIsStandardLayout @238 $Cxx.name("keyword___is_standard_layout");
  keywordUcUcIsTrivial @239 $Cxx.name("keyword___is_trivial");
  keywordUcUcIsTriviallyAssignable @240 $Cxx.name("keyword___is_trivially_assignable");
  keywordUcUcIsTriviallyConstructible @241 $Cxx.name("keyword___is_trivially_constructible");
  keywordUcUcIsTriviallyCopyable @242 $Cxx.name("keyword___is_trivially_copyable");
  keywordUcUcIsUnion @243 $Cxx.name("keyword___is_union");
  keywordUcUcHasUniqueObjectRepresentations @244 $Cxx.name("keyword___has_unique_object_representations");
  keywordUcUcUnderlyingType @245 $Cxx.name("keyword___underlying_type");
  keywordUcUcReferenceBindsToTemporary @246 $Cxx.name("keyword___reference_binds_to_temporary");
  keywordUcUcIsLvalueExpression @247 $Cxx.name("keyword___is_lvalue_expression");
  keywordUcUcIsRvalueExpression @248 $Cxx.name("keyword___is_rvalue_expression");
  keywordUcUcIsArithmetic @249 $Cxx.name("keyword___is_arithmetic");
  keywordUcUcIsFloatingPoint @250 $Cxx.name("keyword___is_floating_point");
  keywordUcUcIsIntegral @251 $Cxx.name("keyword___is_integral");
  keywordUcUcIsCompleteType @252 $Cxx.name("keyword___is_complete_type");
  keywordUcUcIsVoid @253 $Cxx.name("keyword___is_void");
  keywordUcUcIsArray @254 $Cxx.name("keyword___is_array");
  keywordUcUcIsFunction @255 $Cxx.name("keyword___is_function");
  keywordUcUcIsReference @256 $Cxx.name("keyword___is_reference");
  keywordUcUcIsLvalueReference @257 $Cxx.name("keyword___is_lvalue_reference");
  keywordUcUcIsRvalueReference @258 $Cxx.name("keyword___is_rvalue_reference");
  keywordUcUcIsFundamental @259 $Cxx.name("keyword___is_fundamental");
  keywordUcUcIsObject @260 $Cxx.name("keyword___is_object");
  keywordUcUcIsScalar @261 $Cxx.name("keyword___is_scalar");
  keywordUcUcIsCompound @262 $Cxx.name("keyword___is_compound");
  keywordUcUcIsPointer @263 $Cxx.name("keyword___is_pointer");
  keywordUcUcIsMemberObjectPointer @264 $Cxx.name("keyword___is_member_object_pointer");
  keywordUcUcIsMemberFunctionPointer @265 $Cxx.name("keyword___is_member_function_pointer");
  keywordUcUcIsMemberPointer @266 $Cxx.name("keyword___is_member_pointer");
  keywordUcUcIsConst @267 $Cxx.name("keyword___is_const");
  keywordUcUcIsVolatile @268 $Cxx.name("keyword___is_volatile");
  keywordUcUcIsSigned @269 $Cxx.name("keyword___is_signed");
  keywordUcUcIsUnsigned @270 $Cxx.name("keyword___is_unsigned");
  keywordUcUcIsSame @271 $Cxx.name("keyword___is_same");
  keywordUcUcIsConvertible @272 $Cxx.name("keyword___is_convertible");
  keywordUcUcArrayRank @273 $Cxx.name("keyword___array_rank");
  keywordUcUcArrayExtent @274 $Cxx.name("keyword___array_extent");
  keywordUcUcPrivateExtern @275 $Cxx.name("keyword___private_extern__");
  keywordUcUcModulePrivate @276 $Cxx.name("keyword___module_private__");
  keywordUcUcDeclspec @277 $Cxx.name("keyword___declspec");
  keywordUcUcCdecl @278 $Cxx.name("keyword___cdecl");
  keywordUcUcStdcall @279 $Cxx.name("keyword___stdcall");
  keywordUcUcFastcall @280 $Cxx.name("keyword___fastcall");
  keywordUcUcThiscall @281 $Cxx.name("keyword___thiscall");
  keywordUcUcRegcall @282 $Cxx.name("keyword___regcall");
  keywordUcUcVectorcall @283 $Cxx.name("keyword___vectorcall");
  keywordUcUcForceinline @284 $Cxx.name("keyword___forceinline");
  keywordUcUcUnaligned @285 $Cxx.name("keyword___unaligned");
  keywordUcUcSuper @286 $Cxx.name("keyword___super");
  keywordUcUcGlobal @287 $Cxx.name("keyword___global");
  keywordUcUcLocal @288 $Cxx.name("keyword___local");
  keywordUcUcConstant @289 $Cxx.name("keyword___constant");
  keywordUcUcPrivate @290 $Cxx.name("keyword___private");
  keywordUcUcGeneric @291 $Cxx.name("keyword___generic");
  keywordUcUcKernel @292 $Cxx.name("keyword___kernel");
  keywordUcUcReadOnly @293 $Cxx.name("keyword___read_only");
  keywordUcUcWriteOnly @294 $Cxx.name("keyword___write_only");
  keywordUcUcReadWrite @295 $Cxx.name("keyword___read_write");
  keywordUcUcBuiltinAstype @296 $Cxx.name("keyword___builtin_astype");
  keywordVecStep @297 $Cxx.name("keyword_vec_step");
  keywordImage1Dt @298 $Cxx.name("keyword_image1_dt");
  keywordImage1DarrayUcT @299 $Cxx.name("keyword_image1_darray_t");
  keywordImage1DbufferUcT @300 $Cxx.name("keyword_image1_dbuffer_t");
  keywordImage2Dt @301 $Cxx.name("keyword_image2_dt");
  keywordImage2DarrayUcT @302 $Cxx.name("keyword_image2_darray_t");
  keywordImage2DdepthUcT @303 $Cxx.name("keyword_image2_ddepth_t");
  keywordImage2DarrayDepthUcT @304 $Cxx.name("keyword_image2_darray_depth_t");
  keywordImage2DmsaaUcT @305 $Cxx.name("keyword_image2_dmsaa_t");
  keywordImage2DarrayMsaaUcT @306 $Cxx.name("keyword_image2_darray_msaa_t");
  keywordImage2DmsaaDepthUcT @307 $Cxx.name("keyword_image2_dmsaa_depth_t");
  keywordImage2DarrayMsaaDepthUcT @308 $Cxx.name("keyword_image2_darray_msaa_depth_t");
  keywordImage3Dt @309 $Cxx.name("keyword_image3_dt");
  keywordPipe @310 $Cxx.name("keyword_pipe");
  keywordAddrspaceCast @311 $Cxx.name("keyword_addrspace_cast");
  keywordUcUcBuiltinOmpRequiredSimdAlign @312 $Cxx.name("keyword___builtin_omp_required_simd_align");
  keywordUcUcPascal @313 $Cxx.name("keyword___pascal");
  keywordUcUcVector @314 $Cxx.name("keyword___vector");
  keywordUcUcPixel @315 $Cxx.name("keyword___pixel");
  keywordUcUcBoolean @316 $Cxx.name("keyword___boolean");
  keywordUcUcBf16 @317 $Cxx.name("keyword___bf16");
  keywordHalf @318 $Cxx.name("keyword_half");
  keywordUcUcBridge @319 $Cxx.name("keyword___bridge");
  keywordUcUcBridgeTransfer @320 $Cxx.name("keyword___bridge_transfer");
  keywordUcUcBridgeRetained @321 $Cxx.name("keyword___bridge_retained");
  keywordUcUcBridgeRetain @322 $Cxx.name("keyword___bridge_retain");
  keywordUcUcCovariant @323 $Cxx.name("keyword___covariant");
  keywordUcUcContravariant @324 $Cxx.name("keyword___contravariant");
  keywordUcUcKindof @325 $Cxx.name("keyword___kindof");
  keywordUcNonnull @326 $Cxx.name("keyword__nonnull");
  keywordUcNullable @327 $Cxx.name("keyword__nullable");
  keywordUcNullableResult @328 $Cxx.name("keyword__nullable_result");
  keywordUcNullUnspecified @329 $Cxx.name("keyword__null_unspecified");
  keywordUcUcPtr64 @330 $Cxx.name("keyword___ptr64");
  keywordUcUcPtr32 @331 $Cxx.name("keyword___ptr32");
  keywordUcUcSptr @332 $Cxx.name("keyword___sptr");
  keywordUcUcUptr @333 $Cxx.name("keyword___uptr");
  keywordUcUcW64 @334 $Cxx.name("keyword___w64");
  keywordUcUcUuidof @335 $Cxx.name("keyword___uuidof");
  keywordUcUcTry @336 $Cxx.name("keyword___try");
  keywordUcUcFinally @337 $Cxx.name("keyword___finally");
  keywordUcUcLeave @338 $Cxx.name("keyword___leave");
  keywordUcUcInt64 @339 $Cxx.name("keyword___int64");
  keywordUcUcIfExists @340 $Cxx.name("keyword___if_exists");
  keywordUcUcIfNotExists @341 $Cxx.name("keyword___if_not_exists");
  keywordUcUcSingleInheritance @342 $Cxx.name("keyword___single_inheritance");
  keywordUcUcMultipleInheritance @343 $Cxx.name("keyword___multiple_inheritance");
  keywordUcUcVirtualInheritance @344 $Cxx.name("keyword___virtual_inheritance");
  keywordUcUcInterface @345 $Cxx.name("keyword___interface");
  keywordUcUcBuiltinConvertvector @346 $Cxx.name("keyword___builtin_convertvector");
  keywordUcUcBuiltinBitCast @347 $Cxx.name("keyword___builtin_bit_cast");
  keywordUcUcBuiltinAvailable @348 $Cxx.name("keyword___builtin_available");
  keywordUcUcBuiltinSyclUniqueStableName @349 $Cxx.name("keyword___builtin_sycl_unique_stable_name");
  keywordUcUcUnknownAnytype @350 $Cxx.name("keyword___unknown_anytype");
  annotCxxscope @351 $Cxx.name("annot_cxxscope");
  annotTypename @352 $Cxx.name("annot_typename");
  annotTemplateId @353 $Cxx.name("annot_template_id");
  annotNonType @354 $Cxx.name("annot_non_type");
  annotNonTypeUndeclared @355 $Cxx.name("annot_non_type_undeclared");
  annotNonTypeDependent @356 $Cxx.name("annot_non_type_dependent");
  annotOverload @357 $Cxx.name("annot_overload");
  annotPrimaryExpression @358 $Cxx.name("annot_primary_expression");
  annotDecltype @359 $Cxx.name("annot_decltype");
  annotPragmaUnused @360 $Cxx.name("annot_pragma_unused");
  annotPragmaVis @361 $Cxx.name("annot_pragma_vis");
  annotPragmaPack @362 $Cxx.name("annot_pragma_pack");
  annotPragmaParserCrash @363 $Cxx.name("annot_pragma_parser_crash");
  annotPragmaCaptured @364 $Cxx.name("annot_pragma_captured");
  annotPragmaDump @365 $Cxx.name("annot_pragma_dump");
  annotPragmaMsstruct @366 $Cxx.name("annot_pragma_msstruct");
  annotPragmaAlign @367 $Cxx.name("annot_pragma_align");
  annotPragmaWeak @368 $Cxx.name("annot_pragma_weak");
  annotPragmaWeakalias @369 $Cxx.name("annot_pragma_weakalias");
  annotPragmaRedefineExtname @370 $Cxx.name("annot_pragma_redefine_extname");
  annotPragmaFpContract @371 $Cxx.name("annot_pragma_fp_contract");
  annotPragmaFenvAccess @372 $Cxx.name("annot_pragma_fenv_access");
  annotPragmaFenvRound @373 $Cxx.name("annot_pragma_fenv_round");
  annotPragmaFloatControl @374 $Cxx.name("annot_pragma_float_control");
  annotPragmaMsPointersToMembers @375 $Cxx.name("annot_pragma_ms_pointers_to_members");
  annotPragmaMsVtordisp @376 $Cxx.name("annot_pragma_ms_vtordisp");
  annotPragmaMsPragma @377 $Cxx.name("annot_pragma_ms_pragma");
  annotPragmaOpenclExtension @378 $Cxx.name("annot_pragma_opencl_extension");
  annotAttributeOpenmp @379 $Cxx.name("annot_attribute_openmp");
  annotPragmaOpenmp @380 $Cxx.name("annot_pragma_openmp");
  annotPragmaOpenmpEnd @381 $Cxx.name("annot_pragma_openmp_end");
  annotPragmaLoopHint @382 $Cxx.name("annot_pragma_loop_hint");
  annotPragmaFp @383 $Cxx.name("annot_pragma_fp");
  annotPragmaAttribute @384 $Cxx.name("annot_pragma_attribute");
  annotModuleInclude @385 $Cxx.name("annot_module_include");
  annotModuleBegin @386 $Cxx.name("annot_module_begin");
  annotModuleEnd @387 $Cxx.name("annot_module_end");
  annotHeaderUnit @388 $Cxx.name("annot_header_unit");
}

enum TrailingAllocKind @0xa00e8d253383f16f {
  takInheritsConstructor @0 $Cxx.name("tak_inherits_constructor");
  takHasTailExplicit @1 $Cxx.name("tak_has_tail_explicit");
}

enum TranslationUnitKind @0xf1688fb0ace106da {
  complete @0 $Cxx.name("complete");
  prefix @1 $Cxx.name("prefix");
  module @2 $Cxx.name("module");
  incremental @3 $Cxx.name("incremental");
}

enum TrivialAutoVarInitKind @0xb3988e89982a2875 {
  uninitialized @0 $Cxx.name("uninitialized");
  zero @1 $Cxx.name("zero");
  pattern @2 $Cxx.name("pattern");
}

enum TypeDependence @0xcba0ba47ac5b69e3 {
  unexpandedPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  variablyModified @3 $Cxx.name("variably_modified");
  error @4 $Cxx.name("error");
  none @5 $Cxx.name("none");
  all @6 $Cxx.name("all");
  dependentInstantiation @7 $Cxx.name("dependent_instantiation");
}

enum TypeLocClass @0xd26f9faf6191a9d9 {
  adjusted @0 $Cxx.name("adjusted");
  decayed @1 $Cxx.name("decayed");
  constantArray @2 $Cxx.name("constant_array");
  dependentSizedArray @3 $Cxx.name("dependent_sized_array");
  incompleteArray @4 $Cxx.name("incomplete_array");
  variableArray @5 $Cxx.name("variable_array");
  atomic @6 $Cxx.name("atomic");
  attributed @7 $Cxx.name("attributed");
  blockPointer @8 $Cxx.name("block_pointer");
  builtin @9 $Cxx.name("builtin");
  complex @10 $Cxx.name("complex");
  decltype @11 $Cxx.name("decltype");
  auto @12 $Cxx.name("auto");
  deducedTemplateSpecialization @13 $Cxx.name("deduced_template_specialization");
  dependentAddressSpace @14 $Cxx.name("dependent_address_space");
  dependentExtInt @15 $Cxx.name("dependent_ext_int");
  dependentName @16 $Cxx.name("dependent_name");
  dependentSizedExtVector @17 $Cxx.name("dependent_sized_ext_vector");
  dependentTemplateSpecialization @18 $Cxx.name("dependent_template_specialization");
  dependentVector @19 $Cxx.name("dependent_vector");
  elaborated @20 $Cxx.name("elaborated");
  extInt @21 $Cxx.name("ext_int");
  functionNoProto @22 $Cxx.name("function_no_proto");
  functionProto @23 $Cxx.name("function_proto");
  injectedClassName @24 $Cxx.name("injected_class_name");
  macroQualified @25 $Cxx.name("macro_qualified");
  constantMatrix @26 $Cxx.name("constant_matrix");
  dependentSizedMatrix @27 $Cxx.name("dependent_sized_matrix");
  memberPointer @28 $Cxx.name("member_pointer");
  objCObjectPointer @29 $Cxx.name("obj_c_object_pointer");
  objCObject @30 $Cxx.name("obj_c_object");
  objCInterface @31 $Cxx.name("obj_c_interface");
  objCTypeParam @32 $Cxx.name("obj_c_type_param");
  packExpansion @33 $Cxx.name("pack_expansion");
  parenthesis @34 $Cxx.name("parenthesis");
  pipe @35 $Cxx.name("pipe");
  pointer @36 $Cxx.name("pointer");
  lValueReference @37 $Cxx.name("l_value_reference");
  rValueReference @38 $Cxx.name("r_value_reference");
  substTemplateTypeParmPack @39 $Cxx.name("subst_template_type_parm_pack");
  substTemplateTypeParm @40 $Cxx.name("subst_template_type_parm");
  enum @41 $Cxx.name("enum");
  record @42 $Cxx.name("record");
  templateSpecialization @43 $Cxx.name("template_specialization");
  templateTypeParm @44 $Cxx.name("template_type_parm");
  typeOfExpression @45 $Cxx.name("type_of_expression");
  typeOf @46 $Cxx.name("type_of");
  typedef @47 $Cxx.name("typedef");
  unaryTransform @48 $Cxx.name("unary_transform");
  unresolvedUsing @49 $Cxx.name("unresolved_using");
  vector @50 $Cxx.name("vector");
  extVector @51 $Cxx.name("ext_vector");
  qualified @52 $Cxx.name("qualified");
}

enum TypeSpecifierSign @0xc2e5a09f08dbaad2 {
  unspecified @0 $Cxx.name("unspecified");
  signed @1 $Cxx.name("signed");
  unsigned @2 $Cxx.name("unsigned");
}

enum TypeSpecifierType @0x9cc3e16b6e88a740 {
  unspecified @0 $Cxx.name("unspecified");
  void @1 $Cxx.name("void");
  character @2 $Cxx.name("character");
  wchar @3 $Cxx.name("wchar");
  char8 @4 $Cxx.name("char8");
  char16 @5 $Cxx.name("char16");
  char32 @6 $Cxx.name("char32");
  int @7 $Cxx.name("int");
  int128 @8 $Cxx.name("int128");
  extint @9 $Cxx.name("extint");
  half @10 $Cxx.name("half");
  float16 @11 $Cxx.name("float16");
  accum @12 $Cxx.name("accum");
  fract @13 $Cxx.name("fract");
  bFloat16 @14 $Cxx.name("b_float16");
  float @15 $Cxx.name("float");
  double @16 $Cxx.name("double");
  float128 @17 $Cxx.name("float128");
  boolean @18 $Cxx.name("boolean");
  decimal32 @19 $Cxx.name("decimal32");
  decimal64 @20 $Cxx.name("decimal64");
  decimal128 @21 $Cxx.name("decimal128");
  enum @22 $Cxx.name("enum");
  union @23 $Cxx.name("union");
  struct @24 $Cxx.name("struct");
  class @25 $Cxx.name("class");
  interface @26 $Cxx.name("interface");
  typename @27 $Cxx.name("typename");
  typeofType @28 $Cxx.name("typeof_type");
  typeofExpression @29 $Cxx.name("typeof_expression");
  decltype @30 $Cxx.name("decltype");
  underlyingType @31 $Cxx.name("underlying_type");
  auto @32 $Cxx.name("auto");
  decltypeAuto @33 $Cxx.name("decltype_auto");
  autoType @34 $Cxx.name("auto_type");
  unknownAnytype @35 $Cxx.name("unknown_anytype");
  atomic @36 $Cxx.name("atomic");
  image1Dt @37 $Cxx.name("image1_dt");
  image1DarrayUcT @38 $Cxx.name("image1_darray_t");
  image1DbufferUcT @39 $Cxx.name("image1_dbuffer_t");
  image2Dt @40 $Cxx.name("image2_dt");
  image2DarrayUcT @41 $Cxx.name("image2_darray_t");
  image2DdepthUcT @42 $Cxx.name("image2_ddepth_t");
  image2DarrayDepthUcT @43 $Cxx.name("image2_darray_depth_t");
  image2DmsaaUcT @44 $Cxx.name("image2_dmsaa_t");
  image2DarrayMsaaUcT @45 $Cxx.name("image2_darray_msaa_t");
  image2DmsaaDepthUcT @46 $Cxx.name("image2_dmsaa_depth_t");
  image2DarrayMsaaDepthUcT @47 $Cxx.name("image2_darray_msaa_depth_t");
  image3Dt @48 $Cxx.name("image3_dt");
  error @49 $Cxx.name("error");
}

enum TypeSpecifierWidth @0xb35db4de9d1c4558 {
  unspecified @0 $Cxx.name("unspecified");
  short @1 $Cxx.name("short");
  long @2 $Cxx.name("long");
  longLong @3 $Cxx.name("long_long");
}

enum TypeSpecifiersPipe @0xff56fb78fb39ce87 {
  unspecified @0 $Cxx.name("unspecified");
  pipe @1 $Cxx.name("pipe");
}

enum TypeTrait @0xf7e0a1b4b1fe1e7a {
  isInterfaceClass @0 $Cxx.name("is_interface_class");
  isSealed @1 $Cxx.name("is_sealed");
  isDestructible @2 $Cxx.name("is_destructible");
  isTriviallyDestructible @3 $Cxx.name("is_trivially_destructible");
  isNothrowDestructible @4 $Cxx.name("is_nothrow_destructible");
  hasNothrowMoveAssign @5 $Cxx.name("has_nothrow_move_assign");
  hasTrivialMoveAssign @6 $Cxx.name("has_trivial_move_assign");
  hasTrivialMoveConstructor @7 $Cxx.name("has_trivial_move_constructor");
  hasNothrowAssign @8 $Cxx.name("has_nothrow_assign");
  hasNothrowCopy @9 $Cxx.name("has_nothrow_copy");
  hasNothrowConstructor @10 $Cxx.name("has_nothrow_constructor");
  hasTrivialAssign @11 $Cxx.name("has_trivial_assign");
  hasTrivialCopy @12 $Cxx.name("has_trivial_copy");
  hasTrivialDefaultConstructor @13 $Cxx.name("has_trivial_default_constructor");
  hasTrivialDestructor @14 $Cxx.name("has_trivial_destructor");
  hasVirtualDestructor @15 $Cxx.name("has_virtual_destructor");
  isAbstract @16 $Cxx.name("is_abstract");
  isAggregate @17 $Cxx.name("is_aggregate");
  isClass @18 $Cxx.name("is_class");
  isEmpty @19 $Cxx.name("is_empty");
  isEnum @20 $Cxx.name("is_enum");
  isFinal @21 $Cxx.name("is_final");
  isLiteral @22 $Cxx.name("is_literal");
  isPod @23 $Cxx.name("is_pod");
  isPolymorphic @24 $Cxx.name("is_polymorphic");
  isStandardLayout @25 $Cxx.name("is_standard_layout");
  isTrivial @26 $Cxx.name("is_trivial");
  isTriviallyCopyable @27 $Cxx.name("is_trivially_copyable");
  isUnion @28 $Cxx.name("is_union");
  hasUniqueObjectRepresentations @29 $Cxx.name("has_unique_object_representations");
  isArithmetic @30 $Cxx.name("is_arithmetic");
  isFloatingPoint @31 $Cxx.name("is_floating_point");
  isIntegral @32 $Cxx.name("is_integral");
  isCompleteType @33 $Cxx.name("is_complete_type");
  isVoid @34 $Cxx.name("is_void");
  isArray @35 $Cxx.name("is_array");
  isFunction @36 $Cxx.name("is_function");
  isReference @37 $Cxx.name("is_reference");
  isLvalueReference @38 $Cxx.name("is_lvalue_reference");
  isRvalueReference @39 $Cxx.name("is_rvalue_reference");
  isFundamental @40 $Cxx.name("is_fundamental");
  isObject @41 $Cxx.name("is_object");
  isScalar @42 $Cxx.name("is_scalar");
  isCompound @43 $Cxx.name("is_compound");
  isPointer @44 $Cxx.name("is_pointer");
  isMemberObjectPointer @45 $Cxx.name("is_member_object_pointer");
  isMemberFunctionPointer @46 $Cxx.name("is_member_function_pointer");
  isMemberPointer @47 $Cxx.name("is_member_pointer");
  isConst @48 $Cxx.name("is_const");
  isVolatile @49 $Cxx.name("is_volatile");
  isSigned @50 $Cxx.name("is_signed");
  isUnsigned @51 $Cxx.name("is_unsigned");
  typeCompatible @52 $Cxx.name("type_compatible");
  isNothrowAssignable @53 $Cxx.name("is_nothrow_assignable");
  isAssignable @54 $Cxx.name("is_assignable");
  isBaseOf @55 $Cxx.name("is_base_of");
  isConvertibleTo @56 $Cxx.name("is_convertible_to");
  isTriviallyAssignable @57 $Cxx.name("is_trivially_assignable");
  referenceBindsToTemporary @58 $Cxx.name("reference_binds_to_temporary");
  isSame @59 $Cxx.name("is_same");
  isConvertible @60 $Cxx.name("is_convertible");
  isConstructible @61 $Cxx.name("is_constructible");
  isNothrowConstructible @62 $Cxx.name("is_nothrow_constructible");
  isTriviallyConstructible @63 $Cxx.name("is_trivially_constructible");
}

enum UnaryExprOrTypeTrait @0xd2af3deda0a5bfd2 {
  sizeOf @0 $Cxx.name("size_of");
  alignOf @1 $Cxx.name("align_of");
  preferredAlignOf @2 $Cxx.name("preferred_align_of");
  vecStep @3 $Cxx.name("vec_step");
  openMpRequiredSimdAlign @4 $Cxx.name("open_mp_required_simd_align");
}

enum UnaryOperatorKind @0xd9e4cf844656d8e6 {
  postIncrement @0 $Cxx.name("post_increment");
  postDec @1 $Cxx.name("post_dec");
  preIncrement @2 $Cxx.name("pre_increment");
  preDec @3 $Cxx.name("pre_dec");
  addrOf @4 $Cxx.name("addr_of");
  deref @5 $Cxx.name("deref");
  plus @6 $Cxx.name("plus");
  minus @7 $Cxx.name("minus");
  not @8 $Cxx.name("not");
  lNot @9 $Cxx.name("l_not");
  real @10 $Cxx.name("real");
  imag @11 $Cxx.name("imag");
  extension @12 $Cxx.name("extension");
  coawait @13 $Cxx.name("coawait");
}

enum APValueKind @0xcb98d416d4611f2f {
  none @0 $Cxx.name("none");
  indeterminate @1 $Cxx.name("indeterminate");
  int @2 $Cxx.name("int");
  float @3 $Cxx.name("float");
  fixedPoint @4 $Cxx.name("fixed_point");
  complexInt @5 $Cxx.name("complex_int");
  complexFloat @6 $Cxx.name("complex_float");
  lValue @7 $Cxx.name("l_value");
  vector @8 $Cxx.name("vector");
  array @9 $Cxx.name("array");
  struct @10 $Cxx.name("struct");
  union @11 $Cxx.name("union");
  memberPointer @12 $Cxx.name("member_pointer");
  addrLabelDiff @13 $Cxx.name("addr_label_diff");
}

enum VectorLibrary @0x9344c5d64c16cbe4 {
  noLibrary @0 $Cxx.name("no_library");
  accelerate @1 $Cxx.name("accelerate");
  libmvec @2 $Cxx.name("libmvec");
  massv @3 $Cxx.name("massv");
  svml @4 $Cxx.name("svml");
  darwinLibsystemUcM @5 $Cxx.name("darwin_libsystem_m");
}

enum Visibility @0x9f55e79df4f9996e {
  hiddenVisibility @0 $Cxx.name("hidden_visibility");
  protectedVisibility @1 $Cxx.name("protected_visibility");
  defaultVisibility @2 $Cxx.name("default_visibility");
}

enum VisibilityType @0xf2166c9fc7592282 {
  default @0 $Cxx.name("default");
  hidden @1 $Cxx.name("hidden");
  protected @2 $Cxx.name("protected");
}

enum PathKind @0xeee7ae4dc1753912 {
  unix @0 $Cxx.name("unix");
  windows @1 $Cxx.name("windows");
}

enum FileType @0xe5e5e79bb59eb81d {
  none @0 $Cxx.name("none");
  notFound @1 $Cxx.name("not_found");
  regular @2 $Cxx.name("regular");
  directory @3 $Cxx.name("directory");
  symbolicLink @4 $Cxx.name("symbolic_link");
  block @5 $Cxx.name("block");
  character @6 $Cxx.name("character");
  firstInFirstOut @7 $Cxx.name("first_in_first_out");
  socket @8 $Cxx.name("socket");
  knknown @9 $Cxx.name("knknown");
}

enum CompilerName @0xa57e0439dbff0947 {
  unknown @0 $Cxx.name("unknown");
  clang @1 $Cxx.name("clang");
  appleClang @2 $Cxx.name("apple_clang");
  clangCl @3 $Cxx.name("clang_cl");
  cl @4 $Cxx.name("cl");
  gnu @5 $Cxx.name("gnu");
}

enum IncludePathLocation @0xde297748edec6a08 {
  absolute @0 $Cxx.name("absolute");
  sysrootRelative @1 $Cxx.name("sysroot_relative");
}

enum TargetLanguage @0xeabe5088e5bc86fc {
  c @0 $Cxx.name("c");
  cxx @1 $Cxx.name("cxx");
}

struct Decl @0xfb5879761ffaedb6 {
  access @0 :AccessSpecifier;
  accessUnsafe @1 :AccessSpecifier;
  availability @2 :AvailabilityResult;
  beginToken @3 :Token;
  bodyRBrace @4 :Token;
  endToken @5 :Token;
  friendObjectKind @6 :DeclFriendObjectKind;
  moduleOwnershipKind @7 :DeclModuleOwnershipKind;
  hasAttributes @8 :Bool;
  hasBody @9 :Bool;
  hasDefiningAttribute @10 :Bool;
  hasOwningModule @11 :Bool;
  hasTagIdentifierNamespace @12 :Bool;
  isCanonicalDeclaration @13 :Bool;
  isDefinedOutsideFunctionOrMethod @14 :Bool;
  isDeprecated @15 :Bool;
  isFirstDeclaration @16 :Bool;
  isFromAstFile @17 :Bool;
  isFunctionOrFunctionTemplate @18 :Bool;
  isImplicit @19 :Bool;
  isInAnonymousNamespace @20 :Bool;
  isInLocalScopeForInstantiation @21 :Bool;
  isInStdNamespace @22 :Bool;
  isInvalidDeclaration @23 :Bool;
  isModulePrivate @24 :Bool;
  isOutOfLine @25 :Bool;
  isParameterPack @26 :Bool;
  isReferenced @27 :Bool;
  isTemplateDeclaration @28 :Bool;
  isTemplateParameter @29 :Bool;
  isTemplateParameterPack @30 :Bool;
  isTemplated @31 :Bool;
  isThisDeclarationReferenced @32 :Bool;
  isTopLevelDeclarationInObjCContainer @33 :Bool;
  isUnavailable @34 :Bool;
  isUnconditionallyVisible @35 :Bool;
  isUsed @36 :Bool;
  isWeakImported @37 :Bool;
  kind @38 :DeclKind;
  token @39 :Token;
  tokenRange @40 :TokenRange;
}

struct ClassScopeFunctionSpecializationDecl @0x99eb38d6a1065986 {
  decl @0:Decl;
  hasExplicitTemplateArguments @1 :Bool;
}

struct CapturedDecl @0xa1c847e4871d0b0a {
  decl @0:Decl;
  isNothrow @1 :Bool;
}

struct BlockDecl @0xd21c906a9e197a51 {
  decl @0:Decl;
  blockMissingReturnType @1 :Bool;
  canAvoidCopyToHeap @2 :Bool;
  capturesCxxThis @3 :Bool;
  doesNotEscape @4 :Bool;
  caretToken @5 :Token;
  hasCaptures @6 :Bool;
  isConversionFromLambda @7 :Bool;
  isVariadic @8 :Bool;
}

struct AccessSpecDecl @0xe671324616f83d3c {
  decl @0:Decl;
  accessSpecifierToken @1 :Token;
  colonToken @2 :Token;
}

struct TranslationUnitDecl @0x84ba694d5be7caa3 {
  decl @0:Decl;
}

struct StaticAssertDecl @0xe3ab98945466226a {
  decl @0:Decl;
  rParenToken @1 :Token;
  isFailed @2 :Bool;
}

struct RequiresExprBodyDecl @0x9eea1ed94972a3a6 {
  decl @0:Decl;
}

struct PragmaDetectMismatchDecl @0xc2be564c48472f5d {
  decl @0:Decl;
  name @1 :Text;
  value @2 :Text;
}

struct PragmaCommentDecl @0xa32a66c4f91015cb {
  decl @0:Decl;
  argument @1 :Text;
  commentKind @2 :PragmaMSCommentKind;
}

struct ObjCPropertyImplDecl @0x9c45df6dc848c200 {
  decl @0:Decl;
  propertyImplementation @1 :ObjCPropertyImplDeclKind;
  propertyInstanceVariableDeclarationToken @2 :Token;
  isInstanceVariableNameSpecified @3 :Bool;
}

struct NamedDecl @0xee8ff2639c85feae {
  decl @0:Decl;
  formalLinkage @1 :Linkage;
  linkageInternal @2 :Linkage;
  name @3 :Text;
  objCfStringFormattingFamily @4 :ObjCStringFormatFamily;
  qualifiedNameAsString @5 :Text;
  visibility @6 :Visibility;
  hasExternalFormalLinkage @7 :Bool;
  hasLinkage @8 :Bool;
  hasLinkageBeenComputed @9 :Bool;
  isCxxClassMember @10 :Bool;
  isCxxInstanceMember @11 :Bool;
  isExternallyDeclarable @12 :Bool;
  isExternallyVisible @13 :Bool;
  isLinkageValid @14 :Bool;
}

struct LabelDecl @0x959116a0b50f04fe {
  namedDecl @0:NamedDecl;
  msAssemblyLabel @1 :Text;
  isGnuLocal @2 :Bool;
  isMsAssemblyLabel @3 :Bool;
  isResolvedMsAssemblyLabel @4 :Bool;
}

struct BaseUsingDecl @0xd779d676819e5d07 {
  namedDecl @0:NamedDecl;
}

struct UsingEnumDecl @0xa824f691f72f9236 {
  baseUsingDecl @0:BaseUsingDecl;
  enumToken @1 :Token;
  usingToken @2 :Token;
}

struct UsingDecl @0xb8602dcb3f95c179 {
  baseUsingDecl @0:BaseUsingDecl;
  usingToken @1 :Token;
  hasTypename @2 :Bool;
  isAccessDeclaration @3 :Bool;
}

struct ValueDecl @0xe2704a366b05e616 {
  namedDecl @0:NamedDecl;
  isWeak @1 :Bool;
}

struct UnresolvedUsingValueDecl @0x8ad2fc298aa43ab1 {
  valueDecl @0:ValueDecl;
  ellipsisToken @1 :Token;
  usingToken @2 :Token;
  isAccessDeclaration @3 :Bool;
  isPackExpansion @4 :Bool;
}

struct TemplateParamObjectDecl @0xd09f17939d7cc847 {
  valueDecl @0:ValueDecl;
}

struct OMPDeclareReductionDecl @0xf59daefbeeafc092 {
  valueDecl @0:ValueDecl;
  initializerKind @1 :OMPDeclareReductionDeclInitKind;
}

struct MSGuidDecl @0x9ef09ebc4be76711 {
  valueDecl @0:ValueDecl;
}

struct IndirectFieldDecl @0xf8f906fde6cb040f {
  valueDecl @0:ValueDecl;
}

struct EnumConstantDecl @0xe2b34f222cdb8877 {
  valueDecl @0:ValueDecl;
}

struct DeclaratorDecl @0xb95593a177af5810 {
  valueDecl @0:ValueDecl;
  innerTokenStart @1 :Token;
  outerTokenStart @2 :Token;
  typeSpecEndToken @3 :Token;
  typeSpecStartToken @4 :Token;
}

struct VarDecl @0xcf9adcbc59a4e339 {
  declaratorDecl @0:DeclaratorDecl;
  initializerStyle @1 :VarDeclInitializationStyle;
  languageLinkage @2 :LanguageLinkage;
  pointOfInstantiation @3 :Token;
  storageClass @4 :StorageClass;
  storageDuration @5 :StorageDuration;
  tlsKind @6 :VarDeclTLSKind;
  tscSpec @7 :ThreadStorageClassSpecifier;
  templateSpecializationKind @8 :TemplateSpecializationKind;
  templateSpecializationKindForInstantiation @9 :TemplateSpecializationKind;
  hasConstantInitialization @10 :Bool;
  hasDependentAlignment @11 :Bool;
  hasExternalStorage @12 :Bool;
  hasGlobalStorage @13 :Bool;
  hasIceInitializer @14 :Bool;
  hasInitializer @15 :Bool;
  hasLocalStorage @16 :Bool;
  isArcPseudoStrong @17 :Bool;
  isCxxForRangeDeclaration @18 :Bool;
  isConstexpr @19 :Bool;
  isDirectInitializer @20 :Bool;
  isEscapingByref @21 :Bool;
  isExceptionVariable @22 :Bool;
  isExternUcC @23 :Bool;
  isFileVariableDeclaration @24 :Bool;
  isFunctionOrMethodVariableDeclaration @25 :Bool;
  isInExternCContext @26 :Bool;
  isInExternCxxContext @27 :Bool;
  isInitializerCapture @28 :Bool;
  isInline @29 :Bool;
  isInlineSpecified @30 :Bool;
  isKnownToBeDefined @31 :Bool;
  isLocalVariableDeclaration @32 :Bool;
  isLocalVariableDeclarationOrParm @33 :Bool;
  isNrvoVariable @34 :Bool;
  isNoDestroy @35 :Bool;
  isNonEscapingByref @36 :Bool;
  isObjCForDeclaration @37 :Bool;
  isPreviousDeclarationInSameBlockScope @38 :Bool;
  isStaticDataMember @39 :Bool;
  isStaticLocal @40 :Bool;
  isThisDeclarationADemotedDefinition @41 :Bool;
  isUsableInConstantExpressions @42 :Bool;
  mightBeUsableInConstantExpressions @43 :Bool;
  needsDestruction @44 :QualTypeDestructionKind;
}

struct ParmVarDecl @0xedf01c1d7684de38 {
  varDecl @0:VarDecl;
  defaultArgumentRange @1 :TokenRange;
  objCDeclQualifier @2 :DeclObjCDeclQualifier;
  hasDefaultArgument @3 :Bool;
  hasInheritedDefaultArgument @4 :Bool;
  hasUninstantiatedDefaultArgument @5 :Bool;
  hasUnparsedDefaultArgument @6 :Bool;
  isDestroyedInCallee @7 :Bool;
  isKnrPromoted @8 :Bool;
  isObjCMethodParameter @9 :Bool;
}

struct OMPCapturedExprDecl @0x8dae8ad443b5cf77 {
  varDecl @0:VarDecl;
}

struct ImplicitParamDecl @0x9482ac8d963f562c {
  varDecl @0:VarDecl;
  parameterKind @1 :ImplicitParamDeclImplicitParamKind;
}

struct DecompositionDecl @0xd32bcfb0d1a2facb {
  varDecl @0:VarDecl;
}

struct VarTemplateSpecializationDecl @0xbaf3e3ed90ea85e0 {
  varDecl @0:VarDecl;
  externToken @1 :Token;
  specializationKind @2 :TemplateSpecializationKind;
  templateKeywordToken @3 :Token;
  isClassScopeExplicitSpecialization @4 :Bool;
  isExplicitInstantiationOrSpecialization @5 :Bool;
  isExplicitSpecialization @6 :Bool;
}

struct VarTemplatePartialSpecializationDecl @0xe1d0f96cb9fa250f {
  varTemplateSpecializationDecl @0:VarTemplateSpecializationDecl;
  hasAssociatedConstraints @1 :Bool;
}

struct NonTypeTemplateParmDecl @0x964d2872d52f2d65 {
  declaratorDecl @0:DeclaratorDecl;
  defaultArgumentWasInherited @1 :Bool;
  defaultArgumentToken @2 :Token;
  hasDefaultArgument @3 :Bool;
  hasPlaceholderTypeConstraint @4 :Bool;
  isExpandedParameterPack @5 :Bool;
  isPackExpansion @6 :Bool;
}

struct MSPropertyDecl @0x9a46ca50a3ae900f {
  declaratorDecl @0:DeclaratorDecl;
  hasGetter @1 :Bool;
  hasSetter @2 :Bool;
}

struct FunctionDecl @0x92bd4789888f8ccb {
  declaratorDecl @0:DeclaratorDecl;
  doesDeclarationForceExternallyVisibleDefinition @1 :Bool;
  doesThisDeclarationHaveABody @2 :Bool;
  constexprKind @3 :ConstexprSpecKind;
  ellipsisToken @4 :Token;
  exceptionSpecSourceRange @5 :TokenRange;
  exceptionSpecType @6 :ExceptionSpecificationType;
  languageLinkage @7 :LanguageLinkage;
  multiVersionKind @8 :MultiVersionKind;
  overloadedOperator @9 :OverloadedOperatorKind;
  parametersSourceRange @10 :TokenRange;
  pointOfInstantiation @11 :Token;
  returnTypeSourceRange @12 :TokenRange;
  storageClass @13 :StorageClass;
  templateSpecializationKind @14 :TemplateSpecializationKind;
  templateSpecializationKindForInstantiation @15 :TemplateSpecializationKind;
  templatedKind @16 :FunctionDeclTemplatedKind;
  hasImplicitReturnZero @17 :Bool;
  hasInheritedPrototype @18 :Bool;
  hasOneParamOrDefaultArguments @19 :Bool;
  hasPrototype @20 :Bool;
  hasSkippedBody @21 :Bool;
  hasTrivialBody @22 :Bool;
  hasWrittenPrototype @23 :Bool;
  instantiationIsPending @24 :Bool;
  isCpuDispatchMultiVersion @25 :Bool;
  isCpuSpecificMultiVersion @26 :Bool;
  isConsteval @27 :Bool;
  isConstexpr @28 :Bool;
  isConstexprSpecified @29 :Bool;
  isDefaulted @30 :Bool;
  isDeleted @31 :Bool;
  isDeletedAsWritten @32 :Bool;
  isDestroyingOperatorDelete @33 :Bool;
  isExplicitlyDefaulted @34 :Bool;
  isExternUcC @35 :Bool;
  isFunctionTemplateSpecialization @36 :Bool;
  isGlobal @37 :Bool;
  isImplicitlyInstantiable @38 :Bool;
  isInExternCContext @39 :Bool;
  isInExternCxxContext @40 :Bool;
  isInlineBuiltinDeclaration @41 :Bool;
  isInlineDefinitionExternallyVisible @42 :Bool;
  isInlineSpecified @43 :Bool;
  isInlined @44 :Bool;
  isLateTemplateParsed @45 :Bool;
  isMsExternInline @46 :Bool;
  isMsvcrtEntryPoint @47 :Bool;
  isMain @48 :Bool;
  isMultiVersion @49 :Bool;
  isNoReturn @50 :Bool;
  isOverloadedOperator @51 :Bool;
  isPure @52 :Bool;
  isReplaceableGlobalAllocationFunction @53 :Bool;
  isReservedGlobalPlacementOperator @54 :Bool;
  isStatic @55 :Bool;
  isTargetMultiVersion @56 :Bool;
  isTemplateInstantiation @57 :Bool;
  isThisDeclarationADefinition @58 :Bool;
  isThisDeclarationInstantiatedFromAFriendDefinition @59 :Bool;
  isTrivial @60 :Bool;
  isTrivialForCall @61 :Bool;
  isUserProvided @62 :Bool;
  isVariadic @63 :Bool;
  isVirtualAsWritten @64 :Bool;
  usesSehTry @65 :Bool;
  willHaveBody @66 :Bool;
}

struct CXXMethodDecl @0xd83d5835cf6512db {
  functionDecl @0:FunctionDecl;
  referenceQualifier @1 :RefQualifierKind;
  hasInlineBody @2 :Bool;
  isConst @3 :Bool;
  isCopyAssignmentOperator @4 :Bool;
  isInstance @5 :Bool;
  isLambdaStaticInvoker @6 :Bool;
  isMoveAssignmentOperator @7 :Bool;
  isVirtual @8 :Bool;
  isVolatile @9 :Bool;
}

struct CXXDestructorDecl @0xee0fd0438430a21c {
  cxxMethodDecl @0:CXXMethodDecl;
}

struct CXXConversionDecl @0xac531836739115b2 {
  cxxMethodDecl @0:CXXMethodDecl;
  isExplicit @1 :Bool;
  isLambdaToBlockPointerConversion @2 :Bool;
}

struct CXXConstructorDecl @0xc6bfa2c4650464b8 {
  cxxMethodDecl @0:CXXMethodDecl;
  isConvertingConstructor @1 :Bool;
  isDefaultConstructor @2 :Bool;
  isDelegatingConstructor @3 :Bool;
  isExplicit @4 :Bool;
  isInheritingConstructor @5 :Bool;
  isSpecializationCopyingObject @6 :Bool;
}

struct CXXDeductionGuideDecl @0xca6c78b5c1634d9d {
  functionDecl @0:FunctionDecl;
  isCopyDeductionCandidate @1 :Bool;
  isExplicit @2 :Bool;
}

struct FieldDecl @0xec8d79b82b91a5eb {
  declaratorDecl @0:DeclaratorDecl;
  inClassInitializerStyle @1 :InClassInitStyle;
  hasCapturedVlaType @2 :Bool;
  hasInClassInitializer @3 :Bool;
  isAnonymousStructOrUnion @4 :Bool;
  isBitField @5 :Bool;
  isMutable @6 :Bool;
  isUnnamedBitfield @7 :Bool;
  isZeroLengthBitField @8 :Bool;
  isZeroSize @9 :Bool;
}

struct ObjCIvarDecl @0xfd0f42a085839510 {
  fieldDecl @0:FieldDecl;
  accessControl @1 :ObjCIvarDeclAccessControl;
  canonicalAccessControl @2 :ObjCIvarDeclAccessControl;
  synthesize @3 :Bool;
}

struct ObjCAtDefsFieldDecl @0xd8b002eb70c258c6 {
  fieldDecl @0:FieldDecl;
}

struct BindingDecl @0xe77651068f3e1703 {
  valueDecl @0:ValueDecl;
}

struct UsingShadowDecl @0xef25bc2e71e7534e {
  namedDecl @0:NamedDecl;
}

struct ConstructorUsingShadowDecl @0x8a43df80c48b7033 {
  usingShadowDecl @0:UsingShadowDecl;
  constructsVirtualBase @1 :Bool;
}

struct UsingPackDecl @0xf68edcc97d568bee {
  namedDecl @0:NamedDecl;
}

struct UsingDirectiveDecl @0xf383b9039044d6f8 {
  namedDecl @0:NamedDecl;
  identifierToken @1 :Token;
  namespaceKeyToken @2 :Token;
  usingToken @3 :Token;
}

struct UnresolvedUsingIfExistsDecl @0x82421c5826bd81e2 {
  namedDecl @0:NamedDecl;
}

struct TypeDecl @0xd349fa911db2de42 {
  namedDecl @0:NamedDecl;
}

struct TemplateTypeParmDecl @0x87eba729b34d198a {
  typeDecl @0:TypeDecl;
  defaultArgumentWasInherited @1 :Bool;
  defaultArgumentToken @2 :Token;
  hasDefaultArgument @3 :Bool;
  hasTypeConstraint @4 :Bool;
  isExpandedParameterPack @5 :Bool;
  isPackExpansion @6 :Bool;
  wasDeclaredWithTypename @7 :Bool;
}

struct TagDecl @0x8e30dcc81a0377d1 {
  typeDecl @0:TypeDecl;
  braceRange @1 :TokenRange;
  innerTokenStart @2 :Token;
  outerTokenStart @3 :Token;
  tagKind @4 :TagTypeKind;
  hasNameForLinkage @5 :Bool;
  isBeingDefined @6 :Bool;
  isClass @7 :Bool;
  isCompleteDefinition @8 :Bool;
  isCompleteDefinitionRequired @9 :Bool;
  isDependentType @10 :Bool;
  isEmbeddedInDeclarator @11 :Bool;
  isEnum @12 :Bool;
  isFreeStanding @13 :Bool;
  isInterface @14 :Bool;
  isStruct @15 :Bool;
  isThisDeclarationADefinition @16 :Bool;
  isUnion @17 :Bool;
  mayHaveOutOfDateDefinition @18 :Bool;
}

struct RecordDecl @0xae6dc96296678f51 {
  tagDecl @0:TagDecl;
  canPassInRegisters @1 :Bool;
  argumentPassingRestrictions @2 :RecordDeclArgPassingKind;
  hasFlexibleArrayMember @3 :Bool;
  hasLoadedFieldsFromExternalStorage @4 :Bool;
  hasNonTrivialToPrimitiveCopyCUnion @5 :Bool;
  hasNonTrivialToPrimitiveDefaultInitializeCUnion @6 :Bool;
  hasNonTrivialToPrimitiveDestructCUnion @7 :Bool;
  hasObjectMember @8 :Bool;
  hasVolatileMember @9 :Bool;
  isAnonymousStructOrUnion @10 :Bool;
  isCapturedRecord @11 :Bool;
  isInjectedClassName @12 :Bool;
  isLambda @13 :Bool;
  isMsStruct @14 :Bool;
  isNonTrivialToPrimitiveCopy @15 :Bool;
  isNonTrivialToPrimitiveDefaultInitialize @16 :Bool;
  isNonTrivialToPrimitiveDestroy @17 :Bool;
  isOrContainsUnion @18 :Bool;
  isParamDestroyedInCallee @19 :Bool;
  mayInsertExtraPadding @20 :Bool;
}

struct CXXRecordDecl @0x9ecc9c9b6a1f56fc {
  recordDecl @0:RecordDecl;
  allowConstDefaultInitializer @1 :Bool;
  calculateInheritanceModel @2 :MSInheritanceModel;
  defaultedCopyConstructorIsDeleted @3 :Bool;
  defaultedDefaultConstructorIsConstexpr @4 :Bool;
  defaultedDestructorIsConstexpr @5 :Bool;
  defaultedDestructorIsDeleted @6 :Bool;
  defaultedMoveConstructorIsDeleted @7 :Bool;
  lambdaCaptureDefault @8 :LambdaCaptureDefault;
  msInheritanceModel @9 :MSInheritanceModel;
  msVtorDispMode @10 :MSVtorDispMode;
  templateSpecializationKind @11 :TemplateSpecializationKind;
  hasAnyDependentBases @12 :Bool;
  hasConstexprDefaultConstructor @13 :Bool;
  hasConstexprDestructor @14 :Bool;
  hasConstexprNonCopyMoveConstructor @15 :Bool;
  hasCopyAssignmentWithConstParam @16 :Bool;
  hasCopyConstructorWithConstParam @17 :Bool;
  hasDefaultConstructor @18 :Bool;
  hasDefinition @19 :Bool;
  hasDirectFields @20 :Bool;
  hasFriends @21 :Bool;
  hasInClassInitializer @22 :Bool;
  hasInheritedAssignment @23 :Bool;
  hasInheritedConstructor @24 :Bool;
  hasIrrelevantDestructor @25 :Bool;
  hasKnownLambdaInternalLinkage @26 :Bool;
  hasMoveAssignment @27 :Bool;
  hasMoveConstructor @28 :Bool;
  hasMutableFields @29 :Bool;
  hasNonLiteralTypeFieldsOrBases @30 :Bool;
  hasNonTrivialCopyAssignment @31 :Bool;
  hasNonTrivialCopyConstructor @32 :Bool;
  hasNonTrivialCopyConstructorForCall @33 :Bool;
  hasNonTrivialDefaultConstructor @34 :Bool;
  hasNonTrivialDestructor @35 :Bool;
  hasNonTrivialDestructorForCall @36 :Bool;
  hasNonTrivialMoveAssignment @37 :Bool;
  hasNonTrivialMoveConstructor @38 :Bool;
  hasNonTrivialMoveConstructorForCall @39 :Bool;
  hasPrivateFields @40 :Bool;
  hasProtectedFields @41 :Bool;
  hasSimpleCopyAssignment @42 :Bool;
  hasSimpleCopyConstructor @43 :Bool;
  hasSimpleDestructor @44 :Bool;
  hasSimpleMoveAssignment @45 :Bool;
  hasSimpleMoveConstructor @46 :Bool;
  hasTrivialCopyAssignment @47 :Bool;
  hasTrivialCopyConstructor @48 :Bool;
  hasTrivialCopyConstructorForCall @49 :Bool;
  hasTrivialDefaultConstructor @50 :Bool;
  hasTrivialDestructor @51 :Bool;
  hasTrivialDestructorForCall @52 :Bool;
  hasTrivialMoveAssignment @53 :Bool;
  hasTrivialMoveConstructor @54 :Bool;
  hasTrivialMoveConstructorForCall @55 :Bool;
  hasUninitializedReferenceMember @56 :Bool;
  hasUserDeclaredConstructor @57 :Bool;
  hasUserDeclaredCopyAssignment @58 :Bool;
  hasUserDeclaredCopyConstructor @59 :Bool;
  hasUserDeclaredDestructor @60 :Bool;
  hasUserDeclaredMoveAssignment @61 :Bool;
  hasUserDeclaredMoveConstructor @62 :Bool;
  hasUserDeclaredMoveOperation @63 :Bool;
  hasUserProvidedDefaultConstructor @64 :Bool;
  hasVariantMembers @65 :Bool;
  implicitCopyAssignmentHasConstParam @66 :Bool;
  implicitCopyConstructorHasConstParam @67 :Bool;
  isAbstract @68 :Bool;
  isAggregate @69 :Bool;
  isAnyDestructorNoReturn @70 :Bool;
  isCLike @71 :Bool;
  isCxX11StandardLayout @72 :Bool;
  isDependentLambda @73 :Bool;
  isDynamicClass @74 :Bool;
  isEffectivelyFinal @75 :Bool;
  isEmpty @76 :Bool;
  isGenericLambda @77 :Bool;
  isInterfaceLike @78 :Bool;
  isLiteral @79 :Bool;
  isPod @80 :Bool;
  isParsingBaseSpecifiers @81 :Bool;
  isPolymorphic @82 :Bool;
  isStandardLayout @83 :Bool;
  isStructural @84 :Bool;
  isTrivial @85 :Bool;
  isTriviallyCopyable @86 :Bool;
  lambdaIsDefaultConstructibleAndAssignable @87 :Bool;
  mayBeAbstract @88 :Bool;
  mayBeDynamicClass @89 :Bool;
  mayBeNonDynamicClass @90 :Bool;
  needsImplicitCopyAssignment @91 :Bool;
  needsImplicitCopyConstructor @92 :Bool;
  needsImplicitDefaultConstructor @93 :Bool;
  needsImplicitDestructor @94 :Bool;
  needsImplicitMoveAssignment @95 :Bool;
  needsImplicitMoveConstructor @96 :Bool;
  needsOverloadResolutionForCopyAssignment @97 :Bool;
  needsOverloadResolutionForCopyConstructor @98 :Bool;
  needsOverloadResolutionForDestructor @99 :Bool;
  needsOverloadResolutionForMoveAssignment @100 :Bool;
  needsOverloadResolutionForMoveConstructor @101 :Bool;
  nullFieldOffsetIsZero @102 :Bool;
}

struct ClassTemplateSpecializationDecl @0xa81be8b0845933da {
  cxxRecordDecl @0:CXXRecordDecl;
  externToken @1 :Token;
  pointOfInstantiation @2 :Token;
  specializationKind @3 :TemplateSpecializationKind;
  templateKeywordToken @4 :Token;
  isClassScopeExplicitSpecialization @5 :Bool;
  isExplicitInstantiationOrSpecialization @6 :Bool;
  isExplicitSpecialization @7 :Bool;
}

struct ClassTemplatePartialSpecializationDecl @0x9492104c4b2eff2e {
  classTemplateSpecializationDecl @0:ClassTemplateSpecializationDecl;
  hasAssociatedConstraints @1 :Bool;
}

struct EnumDecl @0x93540bfa73a13c84 {
  tagDecl @0:TagDecl;
  integerTypeRange @1 :TokenRange;
  templateSpecializationKind @2 :TemplateSpecializationKind;
  isClosed @3 :Bool;
  isClosedFlag @4 :Bool;
  isClosedNonFlag @5 :Bool;
  isComplete @6 :Bool;
  isFixed @7 :Bool;
  isScoped @8 :Bool;
  isScopedUsingClassTag @9 :Bool;
}

struct UnresolvedUsingTypenameDecl @0x8b74c3415940bb24 {
  typeDecl @0:TypeDecl;
  ellipsisToken @1 :Token;
  typenameToken @2 :Token;
  usingToken @3 :Token;
  isPackExpansion @4 :Bool;
}

struct TypedefNameDecl @0xe8f3a8fa9f84b388 {
  typeDecl @0:TypeDecl;
  isModed @1 :Bool;
  isTransparentTag @2 :Bool;
}

struct TypedefDecl @0xcabfd592ecdf73ec {
  typedefNameDecl @0:TypedefNameDecl;
}

struct TypeAliasDecl @0x98b3c141fd82bbdd {
  typedefNameDecl @0:TypedefNameDecl;
}

struct ObjCTypeParamDecl @0xfea48cce2b1c50cd {
  typedefNameDecl @0:TypedefNameDecl;
  colonToken @1 :Token;
  variance @2 :ObjCTypeParamVariance;
  varianceToken @3 :Token;
  hasExplicitBound @4 :Bool;
}

struct TemplateDecl @0x8794861cbdf44fcd {
  namedDecl @0:NamedDecl;
  hasAssociatedConstraints @1 :Bool;
}

struct RedeclarableTemplateDecl @0xeae96325d22b861f {
  templateDecl @0:TemplateDecl;
  isMemberSpecialization @1 :Bool;
}

struct FunctionTemplateDecl @0xc88144c3067080ac {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
  isAbbreviated @1 :Bool;
  isThisDeclarationADefinition @2 :Bool;
}

struct ClassTemplateDecl @0xd77c8a2532fd776e {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
  isThisDeclarationADefinition @1 :Bool;
}

struct VarTemplateDecl @0x983bd212ec53c1f3 {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
  isThisDeclarationADefinition @1 :Bool;
}

struct TypeAliasTemplateDecl @0xcafc2a5c9d4a2d22 {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
}

struct ConceptDecl @0xdbe7c6781c4169e0 {
  templateDecl @0:TemplateDecl;
  isTypeConcept @1 :Bool;
}

struct BuiltinTemplateDecl @0xa84039c6df79998d {
  templateDecl @0:TemplateDecl;
}

struct TemplateTemplateParmDecl @0x8481be080ff800b8 {
  templateDecl @0:TemplateDecl;
  defaultArgumentWasInherited @1 :Bool;
  defaultArgumentToken @2 :Token;
  hasDefaultArgument @3 :Bool;
  isExpandedParameterPack @4 :Bool;
  isPackExpansion @5 :Bool;
}

struct ObjCPropertyDecl @0x9eb7f76b62290548 {
  namedDecl @0:NamedDecl;
  atToken @1 :Token;
  getterNameToken @2 :Token;
  lParenToken @3 :Token;
  propertyImplementation @4 :ObjCPropertyDeclPropertyControl;
  queryKind @5 :ObjCPropertyQueryKind;
  setterKind @6 :ObjCPropertyDeclSetterKind;
  setterNameToken @7 :Token;
  isAtomic @8 :Bool;
  isClassProperty @9 :Bool;
  isDirectProperty @10 :Bool;
  isInstanceProperty @11 :Bool;
  isOptional @12 :Bool;
  isReadOnly @13 :Bool;
  isRetaining @14 :Bool;
}

struct ObjCMethodDecl @0xf8c8c7d3c113456e {
  namedDecl @0:NamedDecl;
  definedInNsObject @1 :Bool;
  declaratorEndToken @2 :Token;
  implementationControl @3 :ObjCMethodDeclImplementationControl;
  methodFamily @4 :ObjCMethodFamily;
  objCDeclQualifier @5 :DeclObjCDeclQualifier;
  returnTypeSourceRange @6 :TokenRange;
  selectorStartToken @7 :Token;
  hasRedeclaration @8 :Bool;
  hasRelatedResultType @9 :Bool;
  hasSkippedBody @10 :Bool;
  isClassMethod @11 :Bool;
  isDefined @12 :Bool;
  isDesignatedInitializerForTheInterface @13 :Bool;
  isDirectMethod @14 :Bool;
  isInstanceMethod @15 :Bool;
  isOptional @16 :Bool;
  isOverriding @17 :Bool;
  isPropertyAccessor @18 :Bool;
  isRedeclaration @19 :Bool;
  isSynthesizedAccessorStub @20 :Bool;
  isThisDeclarationADefinition @21 :Bool;
  isThisDeclarationADesignatedInitializer @22 :Bool;
  isVariadic @23 :Bool;
}

struct ObjCContainerDecl @0xaf9db5ae0b65ce9e {
  namedDecl @0:NamedDecl;
  atEndRange @1 :TokenRange;
  atStartToken @2 :Token;
}

struct ObjCCategoryDecl @0xb673566cbe41a76d {
  objCContainerDecl @0:ObjCContainerDecl;
  isClassExtension @1 :Bool;
  categoryNameToken @2 :Token;
  instanceVariableLBraceToken @3 :Token;
  instanceVariableRBraceToken @4 :Token;
}

struct ObjCProtocolDecl @0xa8d0b0128e3a36e1 {
  objCContainerDecl @0:ObjCContainerDecl;
  objCRuntimeNameAsString @1 :Text;
  hasDefinition @2 :Bool;
  isNonRuntimeProtocol @3 :Bool;
  isThisDeclarationADefinition @4 :Bool;
}

struct ObjCInterfaceDecl @0x851a7195d7b1d15e {
  objCContainerDecl @0:ObjCContainerDecl;
  declaresOrInheritsDesignatedInitializers @1 :Bool;
  endOfDefinitionToken @2 :Token;
  objCRuntimeNameAsString @3 :Text;
  superClassToken @4 :Token;
  hasDefinition @5 :Bool;
  hasDesignatedInitializers @6 :Bool;
  isArcWeakrefUnavailable @7 :Bool;
  isImplicitInterfaceDeclaration @8 :Bool;
  isThisDeclarationADefinition @9 :Bool;
}

struct ObjCImplDecl @0xfbf2d2598582b4f4 {
  objCContainerDecl @0:ObjCContainerDecl;
}

struct ObjCCategoryImplDecl @0xb972fe178fc59d16 {
  objCImplDecl @0:ObjCImplDecl;
  categoryNameToken @1 :Token;
}

struct ObjCImplementationDecl @0xf2e56fe062561acd {
  objCImplDecl @0:ObjCImplDecl;
  instanceVariableLBraceToken @1 :Token;
  instanceVariableRBraceToken @2 :Token;
  objCRuntimeNameAsString @3 :Text;
  superClassToken @4 :Token;
  hasDestructors @5 :Bool;
  hasNonZeroConstructors @6 :Bool;
}

struct ObjCCompatibleAliasDecl @0xc484be73cf6be95b {
  namedDecl @0:NamedDecl;
}

struct NamespaceDecl @0xd4713edcad196585 {
  namedDecl @0:NamedDecl;
  rBraceToken @1 :Token;
  isAnonymousNamespace @2 :Bool;
  isInline @3 :Bool;
  isOriginalNamespace @4 :Bool;
}

struct NamespaceAliasDecl @0xd8966652a484c480 {
  namedDecl @0:NamedDecl;
  aliasToken @1 :Token;
  namespaceToken @2 :Token;
  targetNameToken @3 :Token;
}

struct LinkageSpecDecl @0xb0f84c4a56c95eec {
  decl @0:Decl;
  externToken @1 :Token;
  language @2 :LinkageSpecDeclLanguageIDs;
  rBraceToken @3 :Token;
  hasBraces @4 :Bool;
}

struct LifetimeExtendedTemporaryDecl @0x829a6a0ac2b5baa8 {
  decl @0:Decl;
  storageDuration @1 :StorageDuration;
}

struct ImportDecl @0x84f826d506def833 {
  decl @0:Decl;
}

struct FriendTemplateDecl @0x82a920109bdb2178 {
  decl @0:Decl;
  friendToken @1 :Token;
}

struct FriendDecl @0xe6545eb838d810d0 {
  decl @0:Decl;
  friendToken @1 :Token;
  isUnsupportedFriend @2 :Bool;
}

struct FileScopeAsmDecl @0xa91b82b590024228 {
  decl @0:Decl;
  assemblyToken @1 :Token;
  rParenToken @2 :Token;
}

struct ExternCContextDecl @0xd79e4560c3f80cbd {
  decl @0:Decl;
}

struct ExportDecl @0xb9bc9642842c6d81 {
  decl @0:Decl;
  exportToken @1 :Token;
  rBraceToken @2 :Token;
  hasBraces @3 :Bool;
}

struct EmptyDecl @0xdb55f7b2f60fd2a7 {
  decl @0:Decl;
}

struct Stmt @0x91127d30fade9a32 {
  beginToken @0 :Token;
  endToken @1 :Token;
  tokenRange @2 :TokenRange;
  kind @3 :StmtKind;
}

struct SEHTryStmt @0xf24201c85c654a91 {
  stmt @0:Stmt;
  isCxxTry @1 :Bool;
  tryToken @2 :Token;
}

struct SEHLeaveStmt @0xc4e4ea7e9d86c292 {
  stmt @0:Stmt;
  leaveToken @1 :Token;
}

struct SEHFinallyStmt @0x8331103206247bcd {
  stmt @0:Stmt;
  finallyToken @1 :Token;
}

struct SEHExceptStmt @0xec2050c67aa8fa46 {
  stmt @0:Stmt;
  exceptToken @1 :Token;
}

struct ReturnStmt @0xa64f08dfd7dbc80a {
  stmt @0:Stmt;
  returnToken @1 :Token;
}

struct ObjCForCollectionStmt @0x9eba75a6b3c891a0 {
  stmt @0:Stmt;
  forToken @1 :Token;
  rParenToken @2 :Token;
}

struct ObjCAutoreleasePoolStmt @0x9762e1f9121378d2 {
  stmt @0:Stmt;
  atToken @1 :Token;
}

struct ObjCAtTryStmt @0x8a11f497922c60fa {
  stmt @0:Stmt;
  atTryToken @1 :Token;
}

struct ObjCAtThrowStmt @0xd0de9b13bfbb829d {
  stmt @0:Stmt;
  throwToken @1 :Token;
}

struct ObjCAtSynchronizedStmt @0xc002bd58ce946b42 {
  stmt @0:Stmt;
  atSynchronizedToken @1 :Token;
}

struct ObjCAtFinallyStmt @0xb4641f5dbb7b9c51 {
  stmt @0:Stmt;
  atFinallyToken @1 :Token;
}

struct ObjCAtCatchStmt @0xea4d614d29e03f4e {
  stmt @0:Stmt;
  atCatchToken @1 :Token;
  rParenToken @2 :Token;
  hasEllipsis @3 :Bool;
}

struct OMPExecutableDirective @0xd9ecc0e6e88a888e {
  stmt @0:Stmt;
  hasAssociatedStatement @1 :Bool;
  isStandaloneDirective @2 :Bool;
}

struct OMPDispatchDirective @0xf2ebe316be280493 {
  ompExecutableDirective @0:OMPExecutableDirective;
  targetCallToken @1 :Token;
}

struct OMPDepobjDirective @0xf7901aaea1e59da5 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPCriticalDirective @0xaae7b90454a167f2 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPCancellationPointDirective @0xbd3f65af25cb05ac {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPCancelDirective @0xe9fe3be8b3920583 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPBarrierDirective @0xa561ecfd48037b9f {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPAtomicDirective @0xccfc4e254a9ca2ef {
  ompExecutableDirective @0:OMPExecutableDirective;
  isPostfixUpdate @1 :Bool;
  isXlhsInRhsPart @2 :Bool;
}

struct OMPTeamsDirective @0xb09cbd39c14f104d {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTaskyieldDirective @0xeda0fa85f0053b41 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTaskwaitDirective @0xfab570caa675ad05 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTaskgroupDirective @0x997a52791bc1d2cb {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTaskDirective @0xad4854dc66276a11 {
  ompExecutableDirective @0:OMPExecutableDirective;
  hasCancel @1 :Bool;
}

struct OMPTargetUpdateDirective @0xce201c1bda195171 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTargetTeamsDirective @0xcad5df87230fb5e1 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTargetParallelDirective @0xe053102edf992ab7 {
  ompExecutableDirective @0:OMPExecutableDirective;
  hasCancel @1 :Bool;
}

struct OMPTargetExitDataDirective @0xd3f73d9d66855b7c {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTargetEnterDataDirective @0xfaddabf39d71573c {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTargetDirective @0xe61e25c74d351171 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPTargetDataDirective @0xffdf74d960adebc3 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPSingleDirective @0x9e31c9d771d11457 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPSectionsDirective @0xa007966bd69b3ef4 {
  ompExecutableDirective @0:OMPExecutableDirective;
  hasCancel @1 :Bool;
}

struct OMPSectionDirective @0xabfbf1faadf3da79 {
  ompExecutableDirective @0:OMPExecutableDirective;
  hasCancel @1 :Bool;
}

struct OMPScanDirective @0x8048cf331a56b6fb {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPParallelSectionsDirective @0xdab61036a2e612d3 {
  ompExecutableDirective @0:OMPExecutableDirective;
  hasCancel @1 :Bool;
}

struct OMPParallelMasterDirective @0xa7869fbfbcb75e30 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPParallelDirective @0xb6332105b1f2102a {
  ompExecutableDirective @0:OMPExecutableDirective;
  hasCancel @1 :Bool;
}

struct OMPOrderedDirective @0xb97823fb2b0a2176 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPMasterDirective @0xb7b87dfe2df187cd {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPMaskedDirective @0xc1e20133fca4bab7 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPLoopBasedDirective @0xebd7e00926927a85 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPUnrollDirective @0xfde8548a895efed2 {
  ompLoopBasedDirective @0:OMPLoopBasedDirective;
}

struct OMPTileDirective @0x955f68d0ea4dad7c {
  ompLoopBasedDirective @0:OMPLoopBasedDirective;
}

struct OMPLoopDirective @0x996557610848d25e {
  ompLoopBasedDirective @0:OMPLoopBasedDirective;
}

struct OMPForSimdDirective @0xb5d719f282f43408 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPForDirective @0xafaaf1c5631fa3da {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPDistributeSimdDirective @0xfe653c77e8d8d7f8 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPDistributeParallelForSimdDirective @0xed219e924604e032 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPDistributeParallelForDirective @0xd4f84c1343cddbc3 {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPDistributeDirective @0xa3b58e2e947f68cb {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeSimdDirective @0xdd9b68bf972afa51 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeParallelForSimdDirective @0xb1d522d25bf5e8db {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeParallelForDirective @0x8113915845154e06 {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPTeamsDistributeDirective @0xd57fd7f310c3591a {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTaskLoopSimdDirective @0xf8f593871dfacede {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTaskLoopDirective @0xbeea33eaf08e61de {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPTargetTeamsDistributeSimdDirective @0xf160e61a5edc1ff2 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTargetTeamsDistributeParallelForSimdDirective @0x804e195502d62e5b {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTargetTeamsDistributeParallelForDirective @0xb9ef1d4c32f58988 {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPTargetTeamsDistributeDirective @0xdb91542417a3e11b {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTargetSimdDirective @0x82400c65f487fb8a {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTargetParallelForSimdDirective @0x92be3b840fda6c34 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPTargetParallelForDirective @0xb14634030f2d8708 {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPSimdDirective @0xb48cdcd37571e590 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPParallelMasterTaskLoopSimdDirective @0xbbcba5847ff5ba48 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPParallelMasterTaskLoopDirective @0xa53ad6a3233e8b9d {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPParallelForSimdDirective @0xecdb69f0bce900de {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPParallelForDirective @0x8e1e3b1821c0515a {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPMasterTaskLoopSimdDirective @0xea7bac26edd3f458 {
  ompLoopDirective @0:OMPLoopDirective;
}

struct OMPMasterTaskLoopDirective @0x826300eb6228e8f0 {
  ompLoopDirective @0:OMPLoopDirective;
  hasCancel @1 :Bool;
}

struct OMPInteropDirective @0x86d3370fbc5f7dd0 {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPFlushDirective @0xfa2df93386e63fbe {
  ompExecutableDirective @0:OMPExecutableDirective;
}

struct OMPCanonicalLoop @0xf3cf896ddd7c46d1 {
  stmt @0:Stmt;
}

struct NullStmt @0xb57ca05aaf806566 {
  stmt @0:Stmt;
  semiToken @1 :Token;
  hasLeadingEmptyMacro @2 :Bool;
}

struct MSDependentExistsStmt @0xb5d9dfc73eeb0939 {
  stmt @0:Stmt;
  keywordToken @1 :Token;
  isIfExists @2 :Bool;
  isIfNotExists @3 :Bool;
}

struct IndirectGotoStmt @0xca063608491ba1fa {
  stmt @0:Stmt;
  gotoToken @1 :Token;
  starToken @2 :Token;
}

struct IfStmt @0xfc829da66c4e6bb1 {
  stmt @0:Stmt;
  elseToken @1 :Token;
  ifToken @2 :Token;
  lParenToken @3 :Token;
  rParenToken @4 :Token;
  hasElseStorage @5 :Bool;
  hasInitializerStorage @6 :Bool;
  hasVariableStorage @7 :Bool;
  isConstexpr @8 :Bool;
  isObjCAvailabilityCheck @9 :Bool;
}

struct GotoStmt @0xf542902873fc6c2b {
  stmt @0:Stmt;
  gotoToken @1 :Token;
  labelToken @2 :Token;
}

struct ForStmt @0xb6591c23541f6a1e {
  stmt @0:Stmt;
  forToken @1 :Token;
  lParenToken @2 :Token;
  rParenToken @3 :Token;
}

struct DoStmt @0xf6407ae4f3214356 {
  stmt @0:Stmt;
  doToken @1 :Token;
  rParenToken @2 :Token;
  whileToken @3 :Token;
}

struct DeclStmt @0xa672643824ce0ba3 {
  stmt @0:Stmt;
  isSingleDeclaration @1 :Bool;
}

struct CoroutineBodyStmt @0xac9fd8887bfea7d8 {
  stmt @0:Stmt;
  hasDependentPromiseType @1 :Bool;
}

struct CoreturnStmt @0xfada897216b226f1 {
  stmt @0:Stmt;
  keywordToken @1 :Token;
  isImplicit @2 :Bool;
}

struct ContinueStmt @0xb364bd3d9a19cd05 {
  stmt @0:Stmt;
  continueToken @1 :Token;
}

struct CompoundStmt @0xd080c9192fa41c92 {
  stmt @0:Stmt;
  lBracToken @1 :Token;
  rBracToken @2 :Token;
}

struct CapturedStmt @0xa60fffc1366b48e6 {
  stmt @0:Stmt;
  capturedRegionKind @1 :CapturedRegionKind;
}

struct CXXTryStmt @0xf98f02d4cdc2dd3b {
  stmt @0:Stmt;
  tryToken @1 :Token;
}

struct CXXForRangeStmt @0xa23a75b3c0fa7d86 {
  stmt @0:Stmt;
  coawaitToken @1 :Token;
  colonToken @2 :Token;
  forToken @3 :Token;
  rParenToken @4 :Token;
}

struct CXXCatchStmt @0xac4b9e8390fd3a85 {
  stmt @0:Stmt;
  catchToken @1 :Token;
}

struct BreakStmt @0x940efd4e9770cb41 {
  stmt @0:Stmt;
  breakToken @1 :Token;
}

struct AsmStmt @0xa47714ac2d00fb21 {
  stmt @0:Stmt;
  generateAssemblyString @1 :Text;
  assemblyToken @2 :Token;
  isSimple @3 :Bool;
  isVolatile @4 :Bool;
}

struct MSAsmStmt @0xc504268dee34a98f {
  asmStmt @0:AsmStmt;
  assemblyString @1 :Text;
  lBraceToken @2 :Token;
  hasBraces @3 :Bool;
}

struct GCCAsmStmt @0x9d046a0d94b425db {
  asmStmt @0:AsmStmt;
  rParenToken @1 :Token;
  isAssemblyGoto @2 :Bool;
}

struct WhileStmt @0x8f0fb0e808ef8cd3 {
  stmt @0:Stmt;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
  whileToken @3 :Token;
  hasVariableStorage @4 :Bool;
}

struct ValueStmt @0xc78a8bda41f72525 {
  stmt @0:Stmt;
}

struct LabelStmt @0xed2b87febf6a7cc9 {
  valueStmt @0:ValueStmt;
  identifierToken @1 :Token;
  name @2 :Text;
  isSideEntry @3 :Bool;
}

struct Expr @0x9e4316b5a505b8d6 {
  valueStmt @0:ValueStmt;
  classifyLValue @1 :ExprLValueClassification;
  hasSideEffects @2 :Bool;
  containsErrors @3 :Bool;
  containsUnexpandedParameterPack @4 :Bool;
  expressionToken @5 :Token;
  objectKind @6 :ExprObjectKind;
  valueKind @7 :ExprValueKind;
  hasNonTrivialCall @8 :Bool;
  isBoundMemberFunction @9 :Bool;
  isCxX11ConstantExpression @10 :Bool;
  isCxX98IntegralConstantExpression @11 :Bool;
  isDefaultArgument @12 :Bool;
  isEvaluatable @13 :Bool;
  isGlValue @14 :Bool;
  isImplicitCxxThis @15 :Bool;
  isInstantiationDependent @16 :Bool;
  isIntegerConstantExpression @17 :Bool;
  isKnownToHaveBooleanValue @18 :Bool;
  isLValue @19 :Bool;
  isModifiableLvalue @20 :ExprisModifiableLvalueResult;
  isObjcgcCandidate @21 :Bool;
  isObjCSelfExpression @22 :Bool;
  isOrdinaryOrBitFieldObject @23 :Bool;
  isPrValue @24 :Bool;
  isReadIfDiscardedInCPlusPlus11 @25 :Bool;
  isTypeDependent @26 :Bool;
  isValueDependent @27 :Bool;
  isXValue @28 :Bool;
  refersToBitField @29 :Bool;
  refersToGlobalRegisterVariable @30 :Bool;
  refersToMatrixElement @31 :Bool;
  refersToVectorElement @32 :Bool;
}

struct DesignatedInitUpdateExpr @0xaa6c77a8da7c4fba {
  expr @0:Expr;
}

struct DesignatedInitExpr @0xeff2c52d9c942ab2 {
  expr @0:Expr;
  designatorsSourceRange @1 :TokenRange;
  equalOrColonToken @2 :Token;
  isDirectInitializer @3 :Bool;
  usesGnuSyntax @4 :Bool;
}

struct DependentScopeDeclRefExpr @0x8fbb6ccb95a3509d {
  expr @0:Expr;
  lAngleToken @1 :Token;
  rAngleToken @2 :Token;
  templateKeywordToken @3 :Token;
  hasExplicitTemplateArguments @4 :Bool;
  hasTemplateKeyword @5 :Bool;
}

struct DependentCoawaitExpr @0x8fd8a27becb59315 {
  expr @0:Expr;
  keywordToken @1 :Token;
}

struct DeclRefExpr @0xec5119d27610b166 {
  expr @0:Expr;
  lAngleToken @1 :Token;
  rAngleToken @2 :Token;
  templateKeywordToken @3 :Token;
  hadMultipleCandidates @4 :Bool;
  hasExplicitTemplateArguments @5 :Bool;
  hasQualifier @6 :Bool;
  hasTemplateKwAndArgumentsInfo @7 :Bool;
  hasTemplateKeyword @8 :Bool;
  isNonOdrUse @9 :NonOdrUseReason;
  refersToEnclosingVariableOrCapture @10 :Bool;
}

struct CoroutineSuspendExpr @0xbd92ba696775fd54 {
  expr @0:Expr;
  keywordToken @1 :Token;
}

struct CoawaitExpr @0xab62e23bf872526e {
  coroutineSuspendExpr @0:CoroutineSuspendExpr;
  isImplicit @1 :Bool;
}

struct CoyieldExpr @0xe587a5c6d1b766ed {
  coroutineSuspendExpr @0:CoroutineSuspendExpr;
}

struct ConvertVectorExpr @0x9d71128cb240a509 {
  expr @0:Expr;
  builtinToken @1 :Token;
  rParenToken @2 :Token;
}

struct ConceptSpecializationExpr @0xfed5bd9e47227653 {
  expr @0:Expr;
  isSatisfied @1 :Bool;
}

struct CompoundLiteralExpr @0x9865eabaf4e2ef8c {
  expr @0:Expr;
  lParenToken @1 :Token;
  isFileScope @2 :Bool;
}

struct ChooseExpr @0xd4a658caf5a1339e {
  expr @0:Expr;
  builtinToken @1 :Token;
  rParenToken @2 :Token;
  isConditionDependent @3 :Bool;
  isConditionTrue @4 :Bool;
}

struct CharacterLiteral @0xbe144b3e9bdba5d9 {
  expr @0:Expr;
  token @1 :Token;
}

struct CastExpr @0x8cabd91ab4a4dcb3 {
  expr @0:Expr;
  castKind @1 :CastKind;
  castKindName @2 :Text;
  hasStoredFpFeatures @3 :Bool;
}

struct ImplicitCastExpr @0xf4659a194c7adcda {
  castExpr @0:CastExpr;
  isPartOfExplicitCast @1 :Bool;
}

struct ExplicitCastExpr @0xf68e68ae1ee44e91 {
  castExpr @0:CastExpr;
}

struct CXXNamedCastExpr @0x9edfd291691d4a7d {
  explicitCastExpr @0:ExplicitCastExpr;
  angleBrackets @1 :TokenRange;
  castName @2 :Text;
  operatorToken @3 :Token;
  rParenToken @4 :Token;
}

struct CXXDynamicCastExpr @0xb48d513e0fa1452b {
  cxxNamedCastExpr @0:CXXNamedCastExpr;
  isAlwaysNull @1 :Bool;
}

struct CXXConstCastExpr @0x8ee388e71866e008 {
  cxxNamedCastExpr @0:CXXNamedCastExpr;
}

struct CXXAddrspaceCastExpr @0x8065afafedfafb6a {
  cxxNamedCastExpr @0:CXXNamedCastExpr;
}

struct CXXStaticCastExpr @0xd307133180b20a1a {
  cxxNamedCastExpr @0:CXXNamedCastExpr;
}

struct CXXReinterpretCastExpr @0x9ff4423f70d9541a {
  cxxNamedCastExpr @0:CXXNamedCastExpr;
}

struct CXXFunctionalCastExpr @0xf2c246adc881d86c {
  explicitCastExpr @0:ExplicitCastExpr;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
  isListInitialization @3 :Bool;
}

struct CStyleCastExpr @0xddb96d0ba671cd89 {
  explicitCastExpr @0:ExplicitCastExpr;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
}

struct BuiltinBitCastExpr @0xc4d665f00ba3fa8b {
  explicitCastExpr @0:ExplicitCastExpr;
}

struct ObjCBridgedCastExpr @0xad38ef321a1ce1e3 {
  explicitCastExpr @0:ExplicitCastExpr;
  bridgeKeywordToken @1 :Token;
  bridgeKind @2 :ObjCBridgeCastKind;
  bridgeKindName @3 :Text;
  lParenToken @4 :Token;
}

struct CallExpr @0x8cff24c7f68e334b {
  expr @0:Expr;
  adlCallKind @1 :CallExprADLCallKind;
  rParenToken @2 :Token;
  hasStoredFpFeatures @3 :Bool;
  hasUnusedResultAttribute @4 :Bool;
  isBuiltinAssumeFalse @5 :Bool;
  isCallToStdMove @6 :Bool;
  isUnevaluatedBuiltinCall @7 :Bool;
  usesAdl @8 :Bool;
}

struct CXXOperatorCallExpr @0xb6a5653b33cdf0c5 {
  callExpr @0:CallExpr;
  operator @1 :OverloadedOperatorKind;
  operatorToken @2 :Token;
  isAssignmentOperation @3 :Bool;
  isComparisonOperation @4 :Bool;
  isInfixBinaryOperation @5 :Bool;
}

struct CXXMemberCallExpr @0x9a761539349dc02f {
  callExpr @0:CallExpr;
}

struct CUDAKernelCallExpr @0xd0bc1c26ca1e132f {
  callExpr @0:CallExpr;
}

struct UserDefinedLiteral @0xa1af860a6baa1029 {
  callExpr @0:CallExpr;
  literalOperatorKind @1 :UserDefinedLiteralLiteralOperatorKind;
  udSuffixToken @2 :Token;
}

struct CXXUuidofExpr @0xcdde7d28fc7931f6 {
  expr @0:Expr;
  isTypeOperand @1 :Bool;
}

struct CXXUnresolvedConstructExpr @0x9fbb7e373f171f86 {
  expr @0:Expr;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
  isListInitialization @3 :Bool;
}

struct CXXTypeidExpr @0xf325d3531a387183 {
  expr @0:Expr;
  isMostDerived @1 :Bool;
  isPotentiallyEvaluated @2 :Bool;
  isTypeOperand @3 :Bool;
}

struct CXXThrowExpr @0x852a841374684e1e {
  expr @0:Expr;
  throwToken @1 :Token;
  isThrownVariableInScope @2 :Bool;
}

struct CXXThisExpr @0x959ba6d5fec8b422 {
  expr @0:Expr;
  token @1 :Token;
  isImplicit @2 :Bool;
}

struct CXXStdInitializerListExpr @0xd199eb3b19c592fa {
  expr @0:Expr;
}

struct CXXScalarValueInitExpr @0x9fd4b7d4985831e7 {
  expr @0:Expr;
  rParenToken @1 :Token;
}

struct CXXRewrittenBinaryOperator @0xd00648fa0bd5ccc4 {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeString @2 :Text;
  operator @3 :BinaryOperatorKind;
  operatorToken @4 :Token;
  isAssignmentOperation @5 :Bool;
  isComparisonOperation @6 :Bool;
  isReversed @7 :Bool;
}

struct CXXPseudoDestructorExpr @0xfb788932e740ac07 {
  expr @0:Expr;
  colonColonToken @1 :Token;
  destroyedTypeToken @2 :Token;
  operatorToken @3 :Token;
  tildeToken @4 :Token;
  hasQualifier @5 :Bool;
  isArrow @6 :Bool;
}

struct CXXNullPtrLiteralExpr @0x80352ea6175b520f {
  expr @0:Expr;
  token @1 :Token;
}

struct CXXNoexceptExpr @0x97e76c7f0648cbe4 {
  expr @0:Expr;
  value @1 :Bool;
}

struct CXXNewExpr @0x9dca0c0f9404e2b5 {
  expr @0:Expr;
  doesUsualArrayDeleteWantSize @1 :Bool;
  directInitializerRange @2 :TokenRange;
  initializationStyle @3 :CXXNewExprInitializationStyle;
  typeIdParentheses @4 :TokenRange;
  hasInitializer @5 :Bool;
  isArray @6 :Bool;
  isGlobalNew @7 :Bool;
  isParenthesisTypeId @8 :Bool;
  passAlignment @9 :Bool;
  shouldNullCheckAllocation @10 :Bool;
}

struct CXXInheritedCtorInitExpr @0xd5db83de022b1ee3 {
  expr @0:Expr;
  constructsVirtualBase @1 :Bool;
  constructionKind @2 :CXXConstructExprConstructionKind;
  token @3 :Token;
  inheritedFromVirtualBase @4 :Bool;
}

struct CXXFoldExpr @0x8a593922e3ea9d50 {
  expr @0:Expr;
  ellipsisToken @1 :Token;
  lParenToken @2 :Token;
  operator @3 :BinaryOperatorKind;
  rParenToken @4 :Token;
  isLeftFold @5 :Bool;
  isRightFold @6 :Bool;
}

struct CXXDependentScopeMemberExpr @0xa1a21ac74e691c1f {
  expr @0:Expr;
  lAngleToken @1 :Token;
  memberToken @2 :Token;
  operatorToken @3 :Token;
  rAngleToken @4 :Token;
  templateKeywordToken @5 :Token;
  hasExplicitTemplateArguments @6 :Bool;
  hasTemplateKeyword @7 :Bool;
  isArrow @8 :Bool;
  isImplicitAccess @9 :Bool;
}

struct CXXDeleteExpr @0x80f6cd450a27b9d4 {
  expr @0:Expr;
  doesUsualArrayDeleteWantSize @1 :Bool;
  isArrayForm @2 :Bool;
  isArrayFormAsWritten @3 :Bool;
  isGlobalDelete @4 :Bool;
}

struct CXXDefaultInitExpr @0xa78e81b7ba8da8e6 {
  expr @0:Expr;
  usedToken @1 :Token;
}

struct CXXDefaultArgExpr @0x9f9ee9dcf349cbcf {
  expr @0:Expr;
  usedToken @1 :Token;
}

struct CXXConstructExpr @0xb3d036394c09ed48 {
  expr @0:Expr;
  constructionKind @1 :CXXConstructExprConstructionKind;
  token @2 :Token;
  parenthesisOrBraceRange @3 :TokenRange;
  hadMultipleCandidates @4 :Bool;
  isElidable @5 :Bool;
  isListInitialization @6 :Bool;
  isStdInitializerListInitialization @7 :Bool;
  requiresZeroInitialization @8 :Bool;
}

struct CXXTemporaryObjectExpr @0xb4be9b66753a2671 {
  cxxConstructExpr @0:CXXConstructExpr;
}

struct CXXBoolLiteralExpr @0x862b8d87bd2905e0 {
  expr @0:Expr;
  token @1 :Token;
  value @2 :Bool;
}

struct CXXBindTemporaryExpr @0xc6a96978d42dc702 {
  expr @0:Expr;
}

struct BlockExpr @0xc2ae5be0934c61f3 {
  expr @0:Expr;
  caretToken @1 :Token;
}

struct BinaryOperator @0xd858b89bd116f05f {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeString @2 :Text;
  operatorToken @3 :Token;
  hasStoredFpFeatures @4 :Bool;
  isAdditiveOperation @5 :Bool;
  isAssignmentOperation @6 :Bool;
  isBitwiseOperation @7 :Bool;
  isCommaOperation @8 :Bool;
  isComparisonOperation @9 :Bool;
  isCompoundAssignmentOperation @10 :Bool;
  isEqualityOperation @11 :Bool;
  isLogicalOperation @12 :Bool;
  isMultiplicativeOperation @13 :Bool;
  isPointerMemoryOperation @14 :Bool;
  isRelationalOperation @15 :Bool;
  isShiftAssignOperation @16 :Bool;
  isShiftOperation @17 :Bool;
}

struct CompoundAssignOperator @0xe6e7bc711d327cb9 {
  binaryOperator @0:BinaryOperator;
}

struct AtomicExpr @0xc730b6c3f33ecb9f {
  expr @0:Expr;
  builtinToken @1 :Token;
  operation @2 :AtomicExprAtomicOp;
  rParenToken @3 :Token;
  isCmpXChg @4 :Bool;
  isOpenCl @5 :Bool;
  isVolatile @6 :Bool;
}

struct AsTypeExpr @0xf646590167dcf1ab {
  expr @0:Expr;
  builtinToken @1 :Token;
  rParenToken @2 :Token;
}

struct ArrayTypeTraitExpr @0xcbcb35a78956a3cc {
  expr @0:Expr;
  trait @1 :ArrayTypeTrait;
}

struct ArraySubscriptExpr @0xb5bb680da7ccce33 {
  expr @0:Expr;
  rBracketToken @1 :Token;
}

struct ArrayInitLoopExpr @0xbe95601783117ebe {
  expr @0:Expr;
}

struct ArrayInitIndexExpr @0xc9bc62bebe2cdbb8 {
  expr @0:Expr;
}

struct AddrLabelExpr @0xc1abc55fece6aa91 {
  expr @0:Expr;
  ampAmpToken @1 :Token;
  labelToken @2 :Token;
}

struct AbstractConditionalOperator @0xee7097774f7aaa45 {
  expr @0:Expr;
  colonToken @1 :Token;
  questionToken @2 :Token;
}

struct ConditionalOperator @0xd3810312a3bd13c7 {
  abstractConditionalOperator @0:AbstractConditionalOperator;
}

struct BinaryConditionalOperator @0xde5f047672b1ac84 {
  abstractConditionalOperator @0:AbstractConditionalOperator;
}

struct VAArgExpr @0x8fa746d782ee27c9 {
  expr @0:Expr;
  builtinToken @1 :Token;
  rParenToken @2 :Token;
  isMicrosoftAbi @3 :Bool;
}

struct UnaryOperator @0xaa78820aaa7f22b8 {
  expr @0:Expr;
  canOverflow @1 :Bool;
  opcode @2 :UnaryOperatorKind;
  operatorToken @3 :Token;
  hasStoredFpFeatures @4 :Bool;
  isArithmeticOperation @5 :Bool;
  isDecrementOperation @6 :Bool;
  isIncrementDecrementOperation @7 :Bool;
  isIncrementOperation @8 :Bool;
  isPostfix @9 :Bool;
  isPrefix @10 :Bool;
}

struct UnaryExprOrTypeTraitExpr @0xbc37e32561d53a59 {
  expr @0:Expr;
  operatorToken @1 :Token;
  rParenToken @2 :Token;
  isArgumentType @3 :Bool;
}

struct TypoExpr @0xb50d73d61e0fd90b {
  expr @0:Expr;
}

struct TypeTraitExpr @0xeeb042141bc436ae {
  expr @0:Expr;
  trait @1 :TypeTrait;
  value @2 :Bool;
}

struct SubstNonTypeTemplateParmPackExpr @0xbffc5dc4488326c8 {
  expr @0:Expr;
  parameterPackToken @1 :Token;
}

struct SubstNonTypeTemplateParmExpr @0xad38ba4bfe617a6f {
  expr @0:Expr;
  nameToken @1 :Token;
  isReferenceParameter @2 :Bool;
}

struct StringLiteral @0xd0cec44e02f59cf2 {
  expr @0:Expr;
  containsNonAscii @1 :Bool;
  containsNonAsciiOrNull @2 :Bool;
  bytes @3 :Text;
  string @4 :Text;
  isAscii @5 :Bool;
  isPascal @6 :Bool;
  isUtF16 @7 :Bool;
  isUtF32 @8 :Bool;
  isUtF8 @9 :Bool;
  isWide @10 :Bool;
}

struct StmtExpr @0xe3606abe04461b8a {
  expr @0:Expr;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
}

struct SourceLocExpr @0xd4bebb374e1e6d58 {
  expr @0:Expr;
  builtinString @1 :Text;
  identifierKind @2 :SourceLocExprIdentKind;
  token @3 :Token;
  isIntType @4 :Bool;
  isStringType @5 :Bool;
}

struct SizeOfPackExpr @0xa4f777d7b3ce890c {
  expr @0:Expr;
  operatorToken @1 :Token;
  packToken @2 :Token;
  rParenToken @3 :Token;
  isPartiallySubstituted @4 :Bool;
}

struct ShuffleVectorExpr @0xdfa87964ccc4abd6 {
  expr @0:Expr;
  builtinToken @1 :Token;
  rParenToken @2 :Token;
}

struct SYCLUniqueStableNameExpr @0xfa67d59d16f9a78a {
  expr @0:Expr;
  computeName @1 :Text;
  lParenToken @2 :Token;
  token @3 :Token;
  rParenToken @4 :Token;
}

struct RequiresExpr @0xe4f5db5ba506ab26 {
  expr @0:Expr;
  rBraceToken @1 :Token;
  requiresKwToken @2 :Token;
  isSatisfied @3 :Bool;
}

struct RecoveryExpr @0xa9e048a5bbe9f6bd {
  expr @0:Expr;
}

struct PseudoObjectExpr @0xf7795b8660a50a1e {
  expr @0:Expr;
}

struct PredefinedExpr @0xf512f62d75089164 {
  expr @0:Expr;
  identifierKind @1 :PredefinedExprIdentKind;
  identifierKindName @2 :Text;
  token @3 :Token;
}

struct ParenListExpr @0xc7ba76bb20cf6201 {
  expr @0:Expr;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
}

struct ParenExpr @0x821bf890921895cd {
  expr @0:Expr;
  lParen @1 :Token;
  rParen @2 :Token;
}

struct PackExpansionExpr @0xbf1eafc846bba2e0 {
  expr @0:Expr;
  ellipsisToken @1 :Token;
}

struct OverloadExpr @0xe1320ca92341cff5 {
  expr @0:Expr;
  lAngleToken @1 :Token;
  nameToken @2 :Token;
  rAngleToken @3 :Token;
  templateKeywordToken @4 :Token;
  hasExplicitTemplateArguments @5 :Bool;
  hasTemplateKeyword @6 :Bool;
}

struct UnresolvedMemberExpr @0xbd4aeea6486879d1 {
  overloadExpr @0:OverloadExpr;
  memberToken @1 :Token;
  operatorToken @2 :Token;
  hasUnresolvedUsing @3 :Bool;
  isArrow @4 :Bool;
  isImplicitAccess @5 :Bool;
}

struct UnresolvedLookupExpr @0xd04212a95a4ab25d {
  overloadExpr @0:OverloadExpr;
  isOverloaded @1 :Bool;
  requiresAdl @2 :Bool;
}

struct OpaqueValueExpr @0xd0ebba3413f46f6d {
  expr @0:Expr;
  token @1 :Token;
  isUnique @2 :Bool;
}

struct OffsetOfExpr @0xe74e51b681474f08 {
  expr @0:Expr;
  operatorToken @1 :Token;
  rParenToken @2 :Token;
}

struct ObjCSubscriptRefExpr @0x827d6564c3126c7a {
  expr @0:Expr;
  rBracket @1 :Token;
  isArraySubscriptReferenceExpression @2 :Bool;
}

struct ObjCStringLiteral @0x84470e968f7365fb {
  expr @0:Expr;
  atToken @1 :Token;
}

struct ObjCSelectorExpr @0xa6687e4a6275988d {
  expr @0:Expr;
  atToken @1 :Token;
  rParenToken @2 :Token;
}

struct ObjCProtocolExpr @0xb07709e6d6281804 {
  expr @0:Expr;
  atToken @1 :Token;
  protocolIdToken @2 :Token;
  rParenToken @3 :Token;
}

struct ObjCPropertyRefExpr @0x9f75c18ee7f1c7a2 {
  expr @0:Expr;
  token @1 :Token;
  receiverToken @2 :Token;
  isClassReceiver @3 :Bool;
  isExplicitProperty @4 :Bool;
  isImplicitProperty @5 :Bool;
  isMessagingGetter @6 :Bool;
  isMessagingSetter @7 :Bool;
  isObjectReceiver @8 :Bool;
  isSuperReceiver @9 :Bool;
}

struct ObjCMessageExpr @0xc53f62c71ed8d723 {
  expr @0:Expr;
  leftToken @1 :Token;
  methodFamily @2 :ObjCMethodFamily;
  receiverKind @3 :ObjCMessageExprReceiverKind;
  receiverRange @4 :TokenRange;
  rightToken @5 :Token;
  selectorStartToken @6 :Token;
  superToken @7 :Token;
  isClassMessage @8 :Bool;
  isDelegateInitializerCall @9 :Bool;
  isImplicit @10 :Bool;
  isInstanceMessage @11 :Bool;
}

struct ObjCIvarRefExpr @0xec7058b5b38773dd {
  expr @0:Expr;
  token @1 :Token;
  operationToken @2 :Token;
  isArrow @3 :Bool;
  isFreeInstanceVariable @4 :Bool;
}

struct ObjCIsaExpr @0xe3c04c83aef329c8 {
  expr @0:Expr;
  baseTokenEnd @1 :Token;
  isaMemberToken @2 :Token;
  operationToken @3 :Token;
  isArrow @4 :Bool;
}

struct ObjCIndirectCopyRestoreExpr @0x9475cc6d12ba1afb {
  expr @0:Expr;
  shouldCopy @1 :Bool;
}

struct ObjCEncodeExpr @0x911855b6fa2d9812 {
  expr @0:Expr;
  atToken @1 :Token;
  rParenToken @2 :Token;
}

struct ObjCDictionaryLiteral @0xaef4d291186415b7 {
  expr @0:Expr;
}

struct ObjCBoxedExpr @0xae80861f1a63c950 {
  expr @0:Expr;
  atToken @1 :Token;
  isExpressibleAsConstantInitializer @2 :Bool;
}

struct ObjCBoolLiteralExpr @0xb2d027f2c8cad1fb {
  expr @0:Expr;
  token @1 :Token;
  value @2 :Bool;
}

struct ObjCAvailabilityCheckExpr @0xbd477d54907fe95a {
  expr @0:Expr;
  hasVersion @1 :Bool;
}

struct ObjCArrayLiteral @0xa36b5cac081b468a {
  expr @0:Expr;
}

struct OMPIteratorExpr @0xd52a7668addb282d {
  expr @0:Expr;
  iteratorKwToken @1 :Token;
  lParenToken @2 :Token;
  rParenToken @3 :Token;
}

struct OMPArrayShapingExpr @0xcddd3cf38d603be1 {
  expr @0:Expr;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
}

struct OMPArraySectionExpr @0xca2808db37aea2e0 {
  expr @0:Expr;
  colonTokenFirst @1 :Token;
  colonTokenSecond @2 :Token;
  rBracketToken @3 :Token;
}

struct NoInitExpr @0xadedf240a5b5d3d1 {
  expr @0:Expr;
}

struct MemberExpr @0xd8c89de1fe446ed0 {
  expr @0:Expr;
  lAngleToken @1 :Token;
  memberToken @2 :Token;
  operatorToken @3 :Token;
  rAngleToken @4 :Token;
  templateKeywordToken @5 :Token;
  hadMultipleCandidates @6 :Bool;
  hasExplicitTemplateArguments @7 :Bool;
  hasQualifier @8 :Bool;
  hasTemplateKeyword @9 :Bool;
  isArrow @10 :Bool;
  isImplicitAccess @11 :Bool;
  isNonOdrUse @12 :NonOdrUseReason;
}

struct MatrixSubscriptExpr @0xc6e8f0398e560e56 {
  expr @0:Expr;
  rBracketToken @1 :Token;
  isIncomplete @2 :Bool;
}

struct MaterializeTemporaryExpr @0x81f0ffa9f501c48d {
  expr @0:Expr;
  storageDuration @1 :StorageDuration;
  isBoundToLvalueReference @2 :Bool;
  isUsableInConstantExpressions @3 :Bool;
}

struct MSPropertySubscriptExpr @0xdca78c710e8a0bc9 {
  expr @0:Expr;
  rBracketToken @1 :Token;
}

struct MSPropertyRefExpr @0xb14da9f10b21425d {
  expr @0:Expr;
  memberToken @1 :Token;
  isArrow @2 :Bool;
  isImplicitAccess @3 :Bool;
}

struct LambdaExpr @0xd1773aeaaf57de49 {
  expr @0:Expr;
  captureDefault @1 :LambdaCaptureDefault;
  captureDefaultToken @2 :Token;
  introducerRange @3 :TokenRange;
  hasExplicitParameters @4 :Bool;
  hasExplicitResultType @5 :Bool;
  isGenericLambda @6 :Bool;
  isMutable @7 :Bool;
}

struct IntegerLiteral @0x9555503bb691c665 {
  expr @0:Expr;
  token @1 :Token;
}

struct InitListExpr @0xee5bc39a46a85bfd {
  expr @0:Expr;
  lBraceToken @1 :Token;
  rBraceToken @2 :Token;
  hadArrayRangeDesignator @3 :Bool;
  hasArrayFiller @4 :Bool;
  isExplicit @5 :Bool;
  isSemanticForm @6 :Bool;
  isStringLiteralInitializer @7 :Bool;
  isSyntacticForm @8 :Bool;
  isTransparent @9 :Bool;
}

struct ImplicitValueInitExpr @0xa74a9776ddeaccc0 {
  expr @0:Expr;
}

struct ImaginaryLiteral @0xe6373a2b8f6af5f3 {
  expr @0:Expr;
}

struct GenericSelectionExpr @0xb9c714e9030a2703 {
  expr @0:Expr;
  defaultToken @1 :Token;
  genericToken @2 :Token;
  rParenToken @3 :Token;
  isResultDependent @4 :Bool;
}

struct GNUNullExpr @0xed67a32bfb3e1820 {
  expr @0:Expr;
  tokenToken @1 :Token;
}

struct FunctionParmPackExpr @0x9b1418ed71492c60 {
  expr @0:Expr;
  parameterPackToken @1 :Token;
}

struct FullExpr @0x823209f8d52ac4fb {
  expr @0:Expr;
}

struct ExprWithCleanups @0x8caff3daad0879d0 {
  fullExpr @0:FullExpr;
  cleanupsHaveSideEffects @1 :Bool;
}

struct ConstantExpr @0xb118d0dca5dbdf6e {
  fullExpr @0:FullExpr;
  resultStorageKind @1 :ConstantExprResultStorageKind;
  hasApValueResult @2 :Bool;
  isImmediateInvocation @3 :Bool;
}

struct FloatingLiteral @0xf9afab4b69f8f504 {
  expr @0:Expr;
  token @1 :Token;
  isExact @2 :Bool;
}

struct FixedPointLiteral @0xb376f274c18baf5a {
  expr @0:Expr;
  token @1 :Token;
}

struct ExtVectorElementExpr @0xba6c9e86786ed31a {
  expr @0:Expr;
  containsDuplicateElements @1 :Bool;
  accessorToken @2 :Token;
  isArrow @3 :Bool;
}

struct ExpressionTraitExpr @0xf53890283fc830c0 {
  expr @0:Expr;
  trait @1 :ExpressionTrait;
  value @2 :Bool;
}

struct AttributedStmt @0xc33cd79cc9238608 {
  valueStmt @0:ValueStmt;
  attributeToken @1 :Token;
}

struct SwitchStmt @0x8f2566a2d81612cd {
  stmt @0:Stmt;
  lParenToken @1 :Token;
  rParenToken @2 :Token;
  switchToken @3 :Token;
  hasInitializerStorage @4 :Bool;
  hasVariableStorage @5 :Bool;
  isAllEnumCasesCovered @6 :Bool;
}

struct SwitchCase @0xeecb8bb11e4c8ed7 {
  stmt @0:Stmt;
  colonToken @1 :Token;
  keywordToken @2 :Token;
}

struct DefaultStmt @0xf8ae119f01317845 {
  switchCase @0:SwitchCase;
  defaultToken @1 :Token;
}

struct CaseStmt @0x829897c890006599 {
  switchCase @0:SwitchCase;
  caseStatementIsGnuRange @1 :Bool;
  caseToken @2 :Token;
  ellipsisToken @3 :Token;
}

struct Type @0xd739e808bc1b3fd7 {
  acceptsObjCTypeParams @0 :Bool;
  canDecayToPointerType @1 :Bool;
  canHaveNullability @2 :Bool;
  containsErrors @3 :Bool;
  containsUnexpandedParameterPack @4 :Bool;
  linkage @5 :Linkage;
  scalarTypeKind @6 :TypeScalarTypeKind;
  kind @7 :TypeKind;
  visibility @8 :Visibility;
  hasAutoForTrailingReturnType @9 :Bool;
  hasFloatingRepresentation @10 :Bool;
  hasIntegerRepresentation @11 :Bool;
  hasObjCPointerRepresentation @12 :Bool;
  hasPointerRepresentation @13 :Bool;
  hasSignedIntegerRepresentation @14 :Bool;
  hasSizedVlaType @15 :Bool;
  hasUnnamedOrLocalType @16 :Bool;
  hasUnsignedIntegerRepresentation @17 :Bool;
  isAggregateType @18 :Bool;
  isAlignValUcT @19 :Bool;
  isAnyCharacterType @20 :Bool;
  isAnyComplexType @21 :Bool;
  isAnyPointerType @22 :Bool;
  isArithmeticType @23 :Bool;
  isArrayType @24 :Bool;
  isAtomicType @25 :Bool;
  isBFloat16Type @26 :Bool;
  isBlockCompatibleObjCPointerType @27 :Bool;
  isBlockPointerType @28 :Bool;
  isBooleanType @29 :Bool;
  isBuiltinType @30 :Bool;
  isCarcBridgableType @31 :Bool;
  isCudaDeviceBuiltinSurfaceType @32 :Bool;
  isCudaDeviceBuiltinTextureType @33 :Bool;
  isCanonicalUnqualified @34 :Bool;
  isChar16Type @35 :Bool;
  isChar32Type @36 :Bool;
  isChar8Type @37 :Bool;
  isCharacterType @38 :Bool;
  isClassType @39 :Bool;
  isClkEventUcT @40 :Bool;
  isComplexIntegerType @41 :Bool;
  isComplexType @42 :Bool;
  isCompoundType @43 :Bool;
  isConstantArrayType @44 :Bool;
  isConstantMatrixType @45 :Bool;
  isConstantSizeType @46 :Bool;
  isDecltypeType @47 :Bool;
  isDependentAddressSpaceType @48 :Bool;
  isDependentSizedArrayType @49 :Bool;
  isDependentType @50 :Bool;
  isElaboratedTypeSpecifier @51 :Bool;
  isEnumeralType @52 :Bool;
  isEventUcT @53 :Bool;
  isExtIntType @54 :Bool;
  isExtVectorType @55 :Bool;
  isFixedPointOrIntegerType @56 :Bool;
  isFixedPointType @57 :Bool;
  isFloat128Type @58 :Bool;
  isFloat16Type @59 :Bool;
  isFloatingType @60 :Bool;
  isFromAst @61 :Bool;
  isFunctionNoProtoType @62 :Bool;
  isFunctionPointerType @63 :Bool;
  isFunctionProtoType @64 :Bool;
  isFunctionReferenceType @65 :Bool;
  isFunctionType @66 :Bool;
  isFundamentalType @67 :Bool;
  isHalfType @68 :Bool;
  isImageType @69 :Bool;
  isIncompleteArrayType @70 :Bool;
  isIncompleteOrObjectType @71 :Bool;
  isIncompleteType @72 :Bool;
  isInstantiationDependentType @73 :Bool;
  isIntegerType @74 :Bool;
  isIntegralOrEnumerationType @75 :Bool;
  isIntegralOrUnscopedEnumerationType @76 :Bool;
  isIntegralType @77 :Bool;
  isInterfaceType @78 :Bool;
  isLValueReferenceType @79 :Bool;
  isLinkageValid @80 :Bool;
  isLiteralType @81 :Bool;
  isMatrixType @82 :Bool;
  isMemberDataPointerType @83 :Bool;
  isMemberFunctionPointerType @84 :Bool;
  isMemberPointerType @85 :Bool;
  isNonOverloadPlaceholderType @86 :Bool;
  isNothrowUcT @87 :Bool;
  isNullPointerType @88 :Bool;
  isOclExtOpaqueType @89 :Bool;
  isOclImage1DarrayRoType @90 :Bool;
  isOclImage1DarrayRwType @91 :Bool;
  isOclImage1DarrayWoType @92 :Bool;
  isOclImage1DbufferRoType @93 :Bool;
  isOclImage1DbufferRwType @94 :Bool;
  isOclImage1DbufferWoType @95 :Bool;
  isOclImage1DroType @96 :Bool;
  isOclImage1DrwType @97 :Bool;
  isOclImage1DwoType @98 :Bool;
  isOclImage2DarrayDepthRoType @99 :Bool;
  isOclImage2DarrayDepthRwType @100 :Bool;
  isOclImage2DarrayDepthWoType @101 :Bool;
  isOclImage2DarrayMsaaDepthRoType @102 :Bool;
  isOclImage2DarrayMsaaDepthRwType @103 :Bool;
  isOclImage2DarrayMsaaDepthWoType @104 :Bool;
  isOclImage2DarrayMsaaroType @105 :Bool;
  isOclImage2DarrayMsaarwType @106 :Bool;
  isOclImage2DarrayMsaawoType @107 :Bool;
  isOclImage2DarrayRoType @108 :Bool;
  isOclImage2DarrayRwType @109 :Bool;
  isOclImage2DarrayWoType @110 :Bool;
  isOclImage2DdepthRoType @111 :Bool;
  isOclImage2DdepthRwType @112 :Bool;
  isOclImage2DdepthWoType @113 :Bool;
  isOclImage2DmsaaDepthRoType @114 :Bool;
  isOclImage2DmsaaDepthRwType @115 :Bool;
  isOclImage2DmsaaDepthWoType @116 :Bool;
  isOclImage2DmsaaroType @117 :Bool;
  isOclImage2DmsaarwType @118 :Bool;
  isOclImage2DmsaawoType @119 :Bool;
  isOclImage2DroType @120 :Bool;
  isOclImage2DrwType @121 :Bool;
  isOclImage2DwoType @122 :Bool;
  isOclImage3DroType @123 :Bool;
  isOclImage3DrwType @124 :Bool;
  isOclImage3DwoType @125 :Bool;
  isOclIntelSubgroupAvcImeDualReferenceStreaminType @126 :Bool;
  isOclIntelSubgroupAvcImePayloadType @127 :Bool;
  isOclIntelSubgroupAvcImeResultDualReferenceStreamoutType @128 :Bool;
  isOclIntelSubgroupAvcImeResultSingleReferenceStreamoutType @129 :Bool;
  isOclIntelSubgroupAvcImeResultType @130 :Bool;
  isOclIntelSubgroupAvcImeSingleReferenceStreaminType @131 :Bool;
  isOclIntelSubgroupAvcMcePayloadType @132 :Bool;
  isOclIntelSubgroupAvcMceResultType @133 :Bool;
  isOclIntelSubgroupAvcRefPayloadType @134 :Bool;
  isOclIntelSubgroupAvcRefResultType @135 :Bool;
  isOclIntelSubgroupAvcSicPayloadType @136 :Bool;
  isOclIntelSubgroupAvcSicResultType @137 :Bool;
  isOclIntelSubgroupAvcType @138 :Bool;
  isObjCarcBridgableType @139 :Bool;
  isObjCarcImplicitlyUnretainedType @140 :Bool;
  isObjCBoxableRecordType @141 :Bool;
  isObjCBuiltinType @142 :Bool;
  isObjCClassOrClassKindOfType @143 :Bool;
  isObjCClassType @144 :Bool;
  isObjCIdType @145 :Bool;
  isObjCIndependentClassType @146 :Bool;
  isObjCIndirectLifetimeType @147 :Bool;
  isObjCInertUnsafeUnretainedType @148 :Bool;
  isObjCLifetimeType @149 :Bool;
  isObjCnsObjectType @150 :Bool;
  isObjCObjectOrInterfaceType @151 :Bool;
  isObjCObjectPointerType @152 :Bool;
  isObjCObjectType @153 :Bool;
  isObjCQualifiedClassType @154 :Bool;
  isObjCQualifiedIdType @155 :Bool;
  isObjCQualifiedInterfaceType @156 :Bool;
  isObjCRetainableType @157 :Bool;
  isObjCSelType @158 :Bool;
  isObjectPointerType @159 :Bool;
  isObjectType @160 :Bool;
  isOpenClSpecificType @161 :Bool;
  isOverloadableType @162 :Bool;
  isPipeType @163 :Bool;
  isPlaceholderType @164 :Bool;
  isPointerType @165 :Bool;
  isPromotableIntegerType @166 :Bool;
  isQueueUcT @167 :Bool;
  isRValueReferenceType @168 :Bool;
  isRealFloatingType @169 :Bool;
  isRealType @170 :Bool;
  isRecordType @171 :Bool;
  isReferenceType @172 :Bool;
  isReserveIdt @173 :Bool;
  isSamplerUcT @174 :Bool;
  isSaturatedFixedPointType @175 :Bool;
  isScalarType @176 :Bool;
  isScopedEnumeralType @177 :Bool;
  isSignedFixedPointType @178 :Bool;
  isSignedIntegerOrEnumerationType @179 :Bool;
  isSignedIntegerType @180 :Bool;
  isSizelessBuiltinType @181 :Bool;
  isSizelessType @182 :Bool;
  isSpecifierType @183 :Bool;
  isStandardLayoutType @184 :Bool;
  isStdByteType @185 :Bool;
  isStructuralType @186 :Bool;
  isStructureOrClassType @187 :Bool;
  isStructureType @188 :Bool;
  isTemplateTypeParmType @189 :Bool;
  isTypedefNameType @190 :Bool;
  isUndeducedAutoType @191 :Bool;
  isUndeducedType @192 :Bool;
  isUnionType @193 :Bool;
  isUnsaturatedFixedPointType @194 :Bool;
  isUnscopedEnumerationType @195 :Bool;
  isUnsignedFixedPointType @196 :Bool;
  isUnsignedIntegerOrEnumerationType @197 :Bool;
  isUnsignedIntegerType @198 :Bool;
  isVlstBuiltinType @199 :Bool;
  isVariableArrayType @200 :Bool;
  isVariablyModifiedType @201 :Bool;
  isVectorType @202 :Bool;
  isVisibilityExplicit @203 :Bool;
  isVoidPointerType @204 :Bool;
  isVoidType @205 :Bool;
  isWideCharacterType @206 :Bool;
  isQualified @207 :Bool;
  addressSpace @208 :LangAS;
  hasAddressSpace @209 :Bool;
  hasLocalNonFastQualifiers @210 :Bool;
  hasLocalQualifiers @211 :Bool;
  hasNonTrivialObjCLifetime @212 :Bool;
  hasNonTrivialToPrimitiveCopyCUnion @213 :Bool;
  hasNonTrivialToPrimitiveDefaultInitializeCUnion @214 :Bool;
  hasNonTrivialToPrimitiveDestructCUnion @215 :Bool;
  hasQualifiers @216 :Bool;
  hasStrongOrWeakObjCLifetime @217 :Bool;
  isCForbiddenLValueType @218 :Bool;
  isCxX11PodType @219 :Bool;
  isCxX98PodType @220 :Bool;
  isCanonical @221 :Bool;
  isCanonicalAsParam @222 :Bool;
  isConstQualified @223 :Bool;
  isConstant @224 :Bool;
  isDestructedType @225 :QualTypeDestructionKind;
  isLocalConstQualified @226 :Bool;
  isLocalRestrictQualified @227 :Bool;
  isLocalVolatileQualified @228 :Bool;
  isNonTrivialToPrimitiveCopy @229 :QualTypePrimitiveCopyKind;
  isNonTrivialToPrimitiveDefaultInitialize @230 :QualTypePrimitiveDefaultInitializeKind;
  isNonTrivialToPrimitiveDestructiveMove @231 :QualTypePrimitiveCopyKind;
  isNonWeakInMrrWithObjCWeak @232 :Bool;
  isNull @233 :Bool;
  isObjCgcStrong @234 :Bool;
  isObjCgcWeak @235 :Bool;
  isPodType @236 :Bool;
  isRestrictQualified @237 :Bool;
  isTrivialType @238 :Bool;
  isTriviallyCopyableType @239 :Bool;
  isVolatileQualified @240 :Bool;
  mayBeDynamicClass @241 :Bool;
  mayBeNotDynamicClass @242 :Bool;
}

struct TemplateTypeParmType @0xe786690ae408805f {
  type @0:Type;
  isParameterPack @1 :Bool;
  isSugared @2 :Bool;
}

struct TemplateSpecializationType @0xfa056c60dc6c1e09 {
  type @0:Type;
  isCurrentInstantiation @1 :Bool;
  isSugared @2 :Bool;
  isTypeAlias @3 :Bool;
}

struct TagType @0xc5f6e35856974d9c {
  type @0:Type;
  isBeingDefined @1 :Bool;
}

struct RecordType @0xa5a5c23895050f69 {
  tagType @0:TagType;
  hasConstFields @1 :Bool;
  isSugared @2 :Bool;
}

struct EnumType @0xeceb1819da64112c {
  tagType @0:TagType;
  isSugared @1 :Bool;
}

struct SubstTemplateTypeParmType @0x8be567616218a913 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct SubstTemplateTypeParmPackType @0x8e845eb2b04a7eee {
  type @0:Type;
  isSugared @1 :Bool;
}

struct ReferenceType @0xf0b00042a60e0b80 {
  type @0:Type;
  isInnerReference @1 :Bool;
  isSpelledAsLValue @2 :Bool;
}

struct RValueReferenceType @0xbecf2238a530256c {
  referenceType @0:ReferenceType;
  isSugared @1 :Bool;
}

struct LValueReferenceType @0xc3ffdde8d840e1f8 {
  referenceType @0:ReferenceType;
  isSugared @1 :Bool;
}

struct PointerType @0xbfb931627d65b65e {
  type @0:Type;
  isSugared @1 :Bool;
}

struct PipeType @0xa153518ebe860937 {
  type @0:Type;
  isReadOnly @1 :Bool;
  isSugared @2 :Bool;
}

struct ParenType @0xff7efc28ab285ec4 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct PackExpansionType @0xd267d004a8c359b6 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct ObjCTypeParamType @0xac0ad54259298e1c {
  type @0:Type;
  isSugared @1 :Bool;
}

struct ObjCObjectType @0xdb7630160ba51f56 {
  type @0:Type;
  isKindOfType @1 :Bool;
  isKindOfTypeAsWritten @2 :Bool;
  isObjCClass @3 :Bool;
  isObjCId @4 :Bool;
  isObjCQualifiedClass @5 :Bool;
  isObjCQualifiedId @6 :Bool;
  isObjCUnqualifiedClass @7 :Bool;
  isObjCUnqualifiedId @8 :Bool;
  isObjCUnqualifiedIdOrClass @9 :Bool;
  isSpecialized @10 :Bool;
  isSpecializedAsWritten @11 :Bool;
  isSugared @12 :Bool;
  isUnspecialized @13 :Bool;
  isUnspecializedAsWritten @14 :Bool;
}

struct ObjCInterfaceType @0xeaf73283b88684f2 {
  objCObjectType @0:ObjCObjectType;
}

struct ObjCObjectPointerType @0x83fd17147f556ba9 {
  type @0:Type;
  isKindOfType @1 :Bool;
  isObjCIdOrClassType @2 :Bool;
  isSpecialized @3 :Bool;
  isSpecializedAsWritten @4 :Bool;
  isSugared @5 :Bool;
  isUnspecialized @6 :Bool;
  isUnspecializedAsWritten @7 :Bool;
}

struct MemberPointerType @0xcd7316ac3d809b66 {
  type @0:Type;
  isMemberDataPointer @1 :Bool;
  isMemberFunctionPointer @2 :Bool;
  isSugared @3 :Bool;
}

struct MatrixType @0xfce6c7a94952d4ac {
  type @0:Type;
  isSugared @1 :Bool;
}

struct DependentSizedMatrixType @0xa068a0de73cc64b1 {
  matrixType @0:MatrixType;
  attributeToken @1 :Token;
}

struct ConstantMatrixType @0x9fe8639dcd3a4d9e {
  matrixType @0:MatrixType;
}

struct MacroQualifiedType @0x8494e2a4b85c9f19 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct InjectedClassNameType @0xa6c2e5edfcbf618a {
  type @0:Type;
  isSugared @1 :Bool;
}

struct FunctionType @0x948975919b3cdebd {
  type @0:Type;
  callConv @1 :CallingConv;
  cmseNsCallAttribute @2 :Bool;
  hasRegParm @3 :Bool;
  noReturnAttribute @4 :Bool;
  isConst @5 :Bool;
  isRestrict @6 :Bool;
  isVolatile @7 :Bool;
}

struct FunctionProtoType @0xfbd27cbfbac5efbb {
  functionType @0:FunctionType;
  canThrow @1 :CanThrowResult;
  ellipsisToken @2 :Token;
  exceptionSpecType @3 :ExceptionSpecificationType;
  referenceQualifier @4 :RefQualifierKind;
  hasDependentExceptionSpec @5 :Bool;
  hasDynamicExceptionSpec @6 :Bool;
  hasExceptionSpec @7 :Bool;
  hasExtParameterInfos @8 :Bool;
  hasInstantiationDependentExceptionSpec @9 :Bool;
  hasNoexceptExceptionSpec @10 :Bool;
  hasTrailingReturn @11 :Bool;
  isNothrow @12 :Bool;
  isSugared @13 :Bool;
  isTemplateVariadic @14 :Bool;
  isVariadic @15 :Bool;
}

struct FunctionNoProtoType @0x8290ca5570d70e02 {
  functionType @0:FunctionType;
  isSugared @1 :Bool;
}

struct ExtIntType @0xc48fbfce9c3676d5 {
  type @0:Type;
  isSigned @1 :Bool;
  isSugared @2 :Bool;
  isUnsigned @3 :Bool;
}

struct DependentVectorType @0xc6ccf5cfae8940a4 {
  type @0:Type;
  attributeToken @1 :Token;
  vectorKind @2 :VectorTypeVectorKind;
  isSugared @3 :Bool;
}

struct DependentSizedExtVectorType @0xd1e2872240f527b7 {
  type @0:Type;
  attributeToken @1 :Token;
  isSugared @2 :Bool;
}

struct DependentExtIntType @0xedfca4126b0a36ef {
  type @0:Type;
  isSigned @1 :Bool;
  isSugared @2 :Bool;
  isUnsigned @3 :Bool;
}

struct DependentAddressSpaceType @0xadb13a8d42ac14c8 {
  type @0:Type;
  attributeToken @1 :Token;
  isSugared @2 :Bool;
}

struct DeducedType @0x9b62aead3bf58839 {
  type @0:Type;
  isDeduced @1 :Bool;
  isSugared @2 :Bool;
}

struct DeducedTemplateSpecializationType @0x9a096862188ecc6e {
  deducedType @0:DeducedType;
}

struct AutoType @0x84e063e662c52b4b {
  deducedType @0:DeducedType;
  keyword @1 :AutoTypeKeyword;
  isConstrained @2 :Bool;
  isDecltypeAuto @3 :Bool;
}

struct DecltypeType @0x8167d2682b1df777 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct ComplexType @0xedb0c5447bfbabbd {
  type @0:Type;
  isSugared @1 :Bool;
}

struct BuiltinType @0xb9df1f7a0b9bd785 {
  type @0:Type;
  isFloatingPoint @1 :Bool;
  isInteger @2 :Bool;
  isSignedInteger @3 :Bool;
  isSugared @4 :Bool;
  isUnsignedInteger @5 :Bool;
}

struct BlockPointerType @0xcf1a6a054f3aaac3 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct AttributedType @0xfae2a754903efb8f {
  type @0:Type;
  attributeKind @1 :AttributeKind;
  isCallingConv @2 :Bool;
  isMsTypeSpec @3 :Bool;
  isQualifier @4 :Bool;
  isSugared @5 :Bool;
}

struct AtomicType @0x856d35fbcc3358de {
  type @0:Type;
  isSugared @1 :Bool;
}

struct ArrayType @0xf51c56dc11dd4d5a {
  type @0:Type;
  sizeModifier @1 :ArrayTypeArraySizeModifier;
}

struct VariableArrayType @0x82d4d76c013109f5 {
  arrayType @0:ArrayType;
  bracketsRange @1 :TokenRange;
  lBracketToken @2 :Token;
  rBracketToken @3 :Token;
  isSugared @4 :Bool;
}

struct IncompleteArrayType @0xd4f7a93527ce975e {
  arrayType @0:ArrayType;
  isSugared @1 :Bool;
}

struct DependentSizedArrayType @0xeb3238fd4299c322 {
  arrayType @0:ArrayType;
  bracketsRange @1 :TokenRange;
  lBracketToken @2 :Token;
  rBracketToken @3 :Token;
  isSugared @4 :Bool;
}

struct ConstantArrayType @0xa122a9fa825e1120 {
  arrayType @0:ArrayType;
  isSugared @1 :Bool;
}

struct AdjustedType @0x85459004973a94cc {
  type @0:Type;
  isSugared @1 :Bool;
}

struct DecayedType @0x9500bc81a552e7af {
  adjustedType @0:AdjustedType;
}

struct VectorType @0xeb831d4f2ea047d6 {
  type @0:Type;
  vectorKind @1 :VectorTypeVectorKind;
  isSugared @2 :Bool;
}

struct ExtVectorType @0x9822bb6b9f91b427 {
  vectorType @0:VectorType;
}

struct UnresolvedUsingType @0xb008cd48c50f310f {
  type @0:Type;
  isSugared @1 :Bool;
}

struct UnaryTransformType @0xf3f137ad71547e38 {
  type @0:Type;
  uttKind @1 :UnaryTransformTypeUTTKind;
  isSugared @2 :Bool;
}

struct TypedefType @0x9983fc1d3106ae9c {
  type @0:Type;
  isSugared @1 :Bool;
}

struct TypeOfType @0xc82d0038e5e0ea52 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct TypeOfExprType @0x9be487fb240a6fe1 {
  type @0:Type;
  isSugared @1 :Bool;
}

struct EntityList @0xf26db0d046aab9c9 {
  classScopeFunctionSpecializationDecl @0 :List(ClassScopeFunctionSpecializationDecl);
  capturedDecl @1 :List(CapturedDecl);
  blockDecl @2 :List(BlockDecl);
  accessSpecDecl @3 :List(AccessSpecDecl);
  translationUnitDecl @4 :List(TranslationUnitDecl);
  staticAssertDecl @5 :List(StaticAssertDecl);
  requiresExprBodyDecl @6 :List(RequiresExprBodyDecl);
  pragmaDetectMismatchDecl @7 :List(PragmaDetectMismatchDecl);
  pragmaCommentDecl @8 :List(PragmaCommentDecl);
  objCPropertyImplDecl @9 :List(ObjCPropertyImplDecl);
  namedDecl @10 :List(NamedDecl);
  labelDecl @11 :List(LabelDecl);
  baseUsingDecl @12 :List(BaseUsingDecl);
  usingEnumDecl @13 :List(UsingEnumDecl);
  usingDecl @14 :List(UsingDecl);
  valueDecl @15 :List(ValueDecl);
  unresolvedUsingValueDecl @16 :List(UnresolvedUsingValueDecl);
  templateParamObjectDecl @17 :List(TemplateParamObjectDecl);
  ompDeclareReductionDecl @18 :List(OMPDeclareReductionDecl);
  msGuidDecl @19 :List(MSGuidDecl);
  indirectFieldDecl @20 :List(IndirectFieldDecl);
  enumConstantDecl @21 :List(EnumConstantDecl);
  declaratorDecl @22 :List(DeclaratorDecl);
  varDecl @23 :List(VarDecl);
  parmVarDecl @24 :List(ParmVarDecl);
  ompCapturedExprDecl @25 :List(OMPCapturedExprDecl);
  implicitParamDecl @26 :List(ImplicitParamDecl);
  decompositionDecl @27 :List(DecompositionDecl);
  varTemplateSpecializationDecl @28 :List(VarTemplateSpecializationDecl);
  varTemplatePartialSpecializationDecl @29 :List(VarTemplatePartialSpecializationDecl);
  nonTypeTemplateParmDecl @30 :List(NonTypeTemplateParmDecl);
  msPropertyDecl @31 :List(MSPropertyDecl);
  functionDecl @32 :List(FunctionDecl);
  cxxMethodDecl @33 :List(CXXMethodDecl);
  cxxDestructorDecl @34 :List(CXXDestructorDecl);
  cxxConversionDecl @35 :List(CXXConversionDecl);
  cxxConstructorDecl @36 :List(CXXConstructorDecl);
  cxxDeductionGuideDecl @37 :List(CXXDeductionGuideDecl);
  fieldDecl @38 :List(FieldDecl);
  objCIvarDecl @39 :List(ObjCIvarDecl);
  objCAtDefsFieldDecl @40 :List(ObjCAtDefsFieldDecl);
  bindingDecl @41 :List(BindingDecl);
  usingShadowDecl @42 :List(UsingShadowDecl);
  constructorUsingShadowDecl @43 :List(ConstructorUsingShadowDecl);
  usingPackDecl @44 :List(UsingPackDecl);
  usingDirectiveDecl @45 :List(UsingDirectiveDecl);
  unresolvedUsingIfExistsDecl @46 :List(UnresolvedUsingIfExistsDecl);
  typeDecl @47 :List(TypeDecl);
  templateTypeParmDecl @48 :List(TemplateTypeParmDecl);
  tagDecl @49 :List(TagDecl);
  recordDecl @50 :List(RecordDecl);
  cxxRecordDecl @51 :List(CXXRecordDecl);
  classTemplateSpecializationDecl @52 :List(ClassTemplateSpecializationDecl);
  classTemplatePartialSpecializationDecl @53 :List(ClassTemplatePartialSpecializationDecl);
  enumDecl @54 :List(EnumDecl);
  unresolvedUsingTypenameDecl @55 :List(UnresolvedUsingTypenameDecl);
  typedefNameDecl @56 :List(TypedefNameDecl);
  typedefDecl @57 :List(TypedefDecl);
  typeAliasDecl @58 :List(TypeAliasDecl);
  objCTypeParamDecl @59 :List(ObjCTypeParamDecl);
  templateDecl @60 :List(TemplateDecl);
  redeclarableTemplateDecl @61 :List(RedeclarableTemplateDecl);
  functionTemplateDecl @62 :List(FunctionTemplateDecl);
  classTemplateDecl @63 :List(ClassTemplateDecl);
  varTemplateDecl @64 :List(VarTemplateDecl);
  typeAliasTemplateDecl @65 :List(TypeAliasTemplateDecl);
  conceptDecl @66 :List(ConceptDecl);
  builtinTemplateDecl @67 :List(BuiltinTemplateDecl);
  templateTemplateParmDecl @68 :List(TemplateTemplateParmDecl);
  objCPropertyDecl @69 :List(ObjCPropertyDecl);
  objCMethodDecl @70 :List(ObjCMethodDecl);
  objCContainerDecl @71 :List(ObjCContainerDecl);
  objCCategoryDecl @72 :List(ObjCCategoryDecl);
  objCProtocolDecl @73 :List(ObjCProtocolDecl);
  objCInterfaceDecl @74 :List(ObjCInterfaceDecl);
  objCImplDecl @75 :List(ObjCImplDecl);
  objCCategoryImplDecl @76 :List(ObjCCategoryImplDecl);
  objCImplementationDecl @77 :List(ObjCImplementationDecl);
  objCCompatibleAliasDecl @78 :List(ObjCCompatibleAliasDecl);
  namespaceDecl @79 :List(NamespaceDecl);
  namespaceAliasDecl @80 :List(NamespaceAliasDecl);
  linkageSpecDecl @81 :List(LinkageSpecDecl);
  lifetimeExtendedTemporaryDecl @82 :List(LifetimeExtendedTemporaryDecl);
  importDecl @83 :List(ImportDecl);
  friendTemplateDecl @84 :List(FriendTemplateDecl);
  friendDecl @85 :List(FriendDecl);
  fileScopeAsmDecl @86 :List(FileScopeAsmDecl);
  externCContextDecl @87 :List(ExternCContextDecl);
  exportDecl @88 :List(ExportDecl);
  emptyDecl @89 :List(EmptyDecl);
  sehTryStmt @90 :List(SEHTryStmt);
  sehLeaveStmt @91 :List(SEHLeaveStmt);
  sehFinallyStmt @92 :List(SEHFinallyStmt);
  sehExceptStmt @93 :List(SEHExceptStmt);
  returnStmt @94 :List(ReturnStmt);
  objCForCollectionStmt @95 :List(ObjCForCollectionStmt);
  objCAutoreleasePoolStmt @96 :List(ObjCAutoreleasePoolStmt);
  objCAtTryStmt @97 :List(ObjCAtTryStmt);
  objCAtThrowStmt @98 :List(ObjCAtThrowStmt);
  objCAtSynchronizedStmt @99 :List(ObjCAtSynchronizedStmt);
  objCAtFinallyStmt @100 :List(ObjCAtFinallyStmt);
  objCAtCatchStmt @101 :List(ObjCAtCatchStmt);
  ompDispatchDirective @102 :List(OMPDispatchDirective);
  ompDepobjDirective @103 :List(OMPDepobjDirective);
  ompCriticalDirective @104 :List(OMPCriticalDirective);
  ompCancellationPointDirective @105 :List(OMPCancellationPointDirective);
  ompCancelDirective @106 :List(OMPCancelDirective);
  ompBarrierDirective @107 :List(OMPBarrierDirective);
  ompAtomicDirective @108 :List(OMPAtomicDirective);
  ompTeamsDirective @109 :List(OMPTeamsDirective);
  ompTaskyieldDirective @110 :List(OMPTaskyieldDirective);
  ompTaskwaitDirective @111 :List(OMPTaskwaitDirective);
  ompTaskgroupDirective @112 :List(OMPTaskgroupDirective);
  ompTaskDirective @113 :List(OMPTaskDirective);
  ompTargetUpdateDirective @114 :List(OMPTargetUpdateDirective);
  ompTargetTeamsDirective @115 :List(OMPTargetTeamsDirective);
  ompTargetParallelDirective @116 :List(OMPTargetParallelDirective);
  ompTargetExitDataDirective @117 :List(OMPTargetExitDataDirective);
  ompTargetEnterDataDirective @118 :List(OMPTargetEnterDataDirective);
  ompTargetDirective @119 :List(OMPTargetDirective);
  ompTargetDataDirective @120 :List(OMPTargetDataDirective);
  ompSingleDirective @121 :List(OMPSingleDirective);
  ompSectionsDirective @122 :List(OMPSectionsDirective);
  ompSectionDirective @123 :List(OMPSectionDirective);
  ompScanDirective @124 :List(OMPScanDirective);
  ompParallelSectionsDirective @125 :List(OMPParallelSectionsDirective);
  ompParallelMasterDirective @126 :List(OMPParallelMasterDirective);
  ompParallelDirective @127 :List(OMPParallelDirective);
  ompOrderedDirective @128 :List(OMPOrderedDirective);
  ompMasterDirective @129 :List(OMPMasterDirective);
  ompMaskedDirective @130 :List(OMPMaskedDirective);
  ompUnrollDirective @131 :List(OMPUnrollDirective);
  ompTileDirective @132 :List(OMPTileDirective);
  ompForSimdDirective @133 :List(OMPForSimdDirective);
  ompForDirective @134 :List(OMPForDirective);
  ompDistributeSimdDirective @135 :List(OMPDistributeSimdDirective);
  ompDistributeParallelForSimdDirective @136 :List(OMPDistributeParallelForSimdDirective);
  ompDistributeParallelForDirective @137 :List(OMPDistributeParallelForDirective);
  ompDistributeDirective @138 :List(OMPDistributeDirective);
  ompTeamsDistributeSimdDirective @139 :List(OMPTeamsDistributeSimdDirective);
  ompTeamsDistributeParallelForSimdDirective @140 :List(OMPTeamsDistributeParallelForSimdDirective);
  ompTeamsDistributeParallelForDirective @141 :List(OMPTeamsDistributeParallelForDirective);
  ompTeamsDistributeDirective @142 :List(OMPTeamsDistributeDirective);
  ompTaskLoopSimdDirective @143 :List(OMPTaskLoopSimdDirective);
  ompTaskLoopDirective @144 :List(OMPTaskLoopDirective);
  ompTargetTeamsDistributeSimdDirective @145 :List(OMPTargetTeamsDistributeSimdDirective);
  ompTargetTeamsDistributeParallelForSimdDirective @146 :List(OMPTargetTeamsDistributeParallelForSimdDirective);
  ompTargetTeamsDistributeParallelForDirective @147 :List(OMPTargetTeamsDistributeParallelForDirective);
  ompTargetTeamsDistributeDirective @148 :List(OMPTargetTeamsDistributeDirective);
  ompTargetSimdDirective @149 :List(OMPTargetSimdDirective);
  ompTargetParallelForSimdDirective @150 :List(OMPTargetParallelForSimdDirective);
  ompTargetParallelForDirective @151 :List(OMPTargetParallelForDirective);
  ompSimdDirective @152 :List(OMPSimdDirective);
  ompParallelMasterTaskLoopSimdDirective @153 :List(OMPParallelMasterTaskLoopSimdDirective);
  ompParallelMasterTaskLoopDirective @154 :List(OMPParallelMasterTaskLoopDirective);
  ompParallelForSimdDirective @155 :List(OMPParallelForSimdDirective);
  ompParallelForDirective @156 :List(OMPParallelForDirective);
  ompMasterTaskLoopSimdDirective @157 :List(OMPMasterTaskLoopSimdDirective);
  ompMasterTaskLoopDirective @158 :List(OMPMasterTaskLoopDirective);
  ompInteropDirective @159 :List(OMPInteropDirective);
  ompFlushDirective @160 :List(OMPFlushDirective);
  ompCanonicalLoop @161 :List(OMPCanonicalLoop);
  nullStmt @162 :List(NullStmt);
  msDependentExistsStmt @163 :List(MSDependentExistsStmt);
  indirectGotoStmt @164 :List(IndirectGotoStmt);
  ifStmt @165 :List(IfStmt);
  gotoStmt @166 :List(GotoStmt);
  forStmt @167 :List(ForStmt);
  doStmt @168 :List(DoStmt);
  declStmt @169 :List(DeclStmt);
  coroutineBodyStmt @170 :List(CoroutineBodyStmt);
  coreturnStmt @171 :List(CoreturnStmt);
  continueStmt @172 :List(ContinueStmt);
  compoundStmt @173 :List(CompoundStmt);
  capturedStmt @174 :List(CapturedStmt);
  cxxTryStmt @175 :List(CXXTryStmt);
  cxxForRangeStmt @176 :List(CXXForRangeStmt);
  cxxCatchStmt @177 :List(CXXCatchStmt);
  breakStmt @178 :List(BreakStmt);
  msAsmStmt @179 :List(MSAsmStmt);
  gccAsmStmt @180 :List(GCCAsmStmt);
  whileStmt @181 :List(WhileStmt);
  labelStmt @182 :List(LabelStmt);
  designatedInitUpdateExpr @183 :List(DesignatedInitUpdateExpr);
  designatedInitExpr @184 :List(DesignatedInitExpr);
  dependentScopeDeclRefExpr @185 :List(DependentScopeDeclRefExpr);
  dependentCoawaitExpr @186 :List(DependentCoawaitExpr);
  declRefExpr @187 :List(DeclRefExpr);
  coawaitExpr @188 :List(CoawaitExpr);
  coyieldExpr @189 :List(CoyieldExpr);
  convertVectorExpr @190 :List(ConvertVectorExpr);
  conceptSpecializationExpr @191 :List(ConceptSpecializationExpr);
  compoundLiteralExpr @192 :List(CompoundLiteralExpr);
  chooseExpr @193 :List(ChooseExpr);
  characterLiteral @194 :List(CharacterLiteral);
  implicitCastExpr @195 :List(ImplicitCastExpr);
  cxxDynamicCastExpr @196 :List(CXXDynamicCastExpr);
  cxxConstCastExpr @197 :List(CXXConstCastExpr);
  cxxAddrspaceCastExpr @198 :List(CXXAddrspaceCastExpr);
  cxxStaticCastExpr @199 :List(CXXStaticCastExpr);
  cxxReinterpretCastExpr @200 :List(CXXReinterpretCastExpr);
  cxxFunctionalCastExpr @201 :List(CXXFunctionalCastExpr);
  cStyleCastExpr @202 :List(CStyleCastExpr);
  builtinBitCastExpr @203 :List(BuiltinBitCastExpr);
  objCBridgedCastExpr @204 :List(ObjCBridgedCastExpr);
  callExpr @205 :List(CallExpr);
  cxxOperatorCallExpr @206 :List(CXXOperatorCallExpr);
  cxxMemberCallExpr @207 :List(CXXMemberCallExpr);
  cudaKernelCallExpr @208 :List(CUDAKernelCallExpr);
  userDefinedLiteral @209 :List(UserDefinedLiteral);
  cxxUuidofExpr @210 :List(CXXUuidofExpr);
  cxxUnresolvedConstructExpr @211 :List(CXXUnresolvedConstructExpr);
  cxxTypeidExpr @212 :List(CXXTypeidExpr);
  cxxThrowExpr @213 :List(CXXThrowExpr);
  cxxThisExpr @214 :List(CXXThisExpr);
  cxxStdInitializerListExpr @215 :List(CXXStdInitializerListExpr);
  cxxScalarValueInitExpr @216 :List(CXXScalarValueInitExpr);
  cxxRewrittenBinaryOperator @217 :List(CXXRewrittenBinaryOperator);
  cxxPseudoDestructorExpr @218 :List(CXXPseudoDestructorExpr);
  cxxNullPtrLiteralExpr @219 :List(CXXNullPtrLiteralExpr);
  cxxNoexceptExpr @220 :List(CXXNoexceptExpr);
  cxxNewExpr @221 :List(CXXNewExpr);
  cxxInheritedCtorInitExpr @222 :List(CXXInheritedCtorInitExpr);
  cxxFoldExpr @223 :List(CXXFoldExpr);
  cxxDependentScopeMemberExpr @224 :List(CXXDependentScopeMemberExpr);
  cxxDeleteExpr @225 :List(CXXDeleteExpr);
  cxxDefaultInitExpr @226 :List(CXXDefaultInitExpr);
  cxxDefaultArgExpr @227 :List(CXXDefaultArgExpr);
  cxxConstructExpr @228 :List(CXXConstructExpr);
  cxxTemporaryObjectExpr @229 :List(CXXTemporaryObjectExpr);
  cxxBoolLiteralExpr @230 :List(CXXBoolLiteralExpr);
  cxxBindTemporaryExpr @231 :List(CXXBindTemporaryExpr);
  blockExpr @232 :List(BlockExpr);
  binaryOperator @233 :List(BinaryOperator);
  compoundAssignOperator @234 :List(CompoundAssignOperator);
  atomicExpr @235 :List(AtomicExpr);
  asTypeExpr @236 :List(AsTypeExpr);
  arrayTypeTraitExpr @237 :List(ArrayTypeTraitExpr);
  arraySubscriptExpr @238 :List(ArraySubscriptExpr);
  arrayInitLoopExpr @239 :List(ArrayInitLoopExpr);
  arrayInitIndexExpr @240 :List(ArrayInitIndexExpr);
  addrLabelExpr @241 :List(AddrLabelExpr);
  conditionalOperator @242 :List(ConditionalOperator);
  binaryConditionalOperator @243 :List(BinaryConditionalOperator);
  vaArgExpr @244 :List(VAArgExpr);
  unaryOperator @245 :List(UnaryOperator);
  unaryExprOrTypeTraitExpr @246 :List(UnaryExprOrTypeTraitExpr);
  typoExpr @247 :List(TypoExpr);
  typeTraitExpr @248 :List(TypeTraitExpr);
  substNonTypeTemplateParmPackExpr @249 :List(SubstNonTypeTemplateParmPackExpr);
  substNonTypeTemplateParmExpr @250 :List(SubstNonTypeTemplateParmExpr);
  stringLiteral @251 :List(StringLiteral);
  stmtExpr @252 :List(StmtExpr);
  sourceLocExpr @253 :List(SourceLocExpr);
  sizeOfPackExpr @254 :List(SizeOfPackExpr);
  shuffleVectorExpr @255 :List(ShuffleVectorExpr);
  syclUniqueStableNameExpr @256 :List(SYCLUniqueStableNameExpr);
  requiresExpr @257 :List(RequiresExpr);
  recoveryExpr @258 :List(RecoveryExpr);
  pseudoObjectExpr @259 :List(PseudoObjectExpr);
  predefinedExpr @260 :List(PredefinedExpr);
  parenListExpr @261 :List(ParenListExpr);
  parenExpr @262 :List(ParenExpr);
  packExpansionExpr @263 :List(PackExpansionExpr);
  unresolvedMemberExpr @264 :List(UnresolvedMemberExpr);
  unresolvedLookupExpr @265 :List(UnresolvedLookupExpr);
  opaqueValueExpr @266 :List(OpaqueValueExpr);
  offsetOfExpr @267 :List(OffsetOfExpr);
  objCSubscriptRefExpr @268 :List(ObjCSubscriptRefExpr);
  objCStringLiteral @269 :List(ObjCStringLiteral);
  objCSelectorExpr @270 :List(ObjCSelectorExpr);
  objCProtocolExpr @271 :List(ObjCProtocolExpr);
  objCPropertyRefExpr @272 :List(ObjCPropertyRefExpr);
  objCMessageExpr @273 :List(ObjCMessageExpr);
  objCIvarRefExpr @274 :List(ObjCIvarRefExpr);
  objCIsaExpr @275 :List(ObjCIsaExpr);
  objCIndirectCopyRestoreExpr @276 :List(ObjCIndirectCopyRestoreExpr);
  objCEncodeExpr @277 :List(ObjCEncodeExpr);
  objCDictionaryLiteral @278 :List(ObjCDictionaryLiteral);
  objCBoxedExpr @279 :List(ObjCBoxedExpr);
  objCBoolLiteralExpr @280 :List(ObjCBoolLiteralExpr);
  objCAvailabilityCheckExpr @281 :List(ObjCAvailabilityCheckExpr);
  objCArrayLiteral @282 :List(ObjCArrayLiteral);
  ompIteratorExpr @283 :List(OMPIteratorExpr);
  ompArrayShapingExpr @284 :List(OMPArrayShapingExpr);
  ompArraySectionExpr @285 :List(OMPArraySectionExpr);
  noInitExpr @286 :List(NoInitExpr);
  memberExpr @287 :List(MemberExpr);
  matrixSubscriptExpr @288 :List(MatrixSubscriptExpr);
  materializeTemporaryExpr @289 :List(MaterializeTemporaryExpr);
  msPropertySubscriptExpr @290 :List(MSPropertySubscriptExpr);
  msPropertyRefExpr @291 :List(MSPropertyRefExpr);
  lambdaExpr @292 :List(LambdaExpr);
  integerLiteral @293 :List(IntegerLiteral);
  initListExpr @294 :List(InitListExpr);
  implicitValueInitExpr @295 :List(ImplicitValueInitExpr);
  imaginaryLiteral @296 :List(ImaginaryLiteral);
  genericSelectionExpr @297 :List(GenericSelectionExpr);
  gnuNullExpr @298 :List(GNUNullExpr);
  functionParmPackExpr @299 :List(FunctionParmPackExpr);
  exprWithCleanups @300 :List(ExprWithCleanups);
  constantExpr @301 :List(ConstantExpr);
  floatingLiteral @302 :List(FloatingLiteral);
  fixedPointLiteral @303 :List(FixedPointLiteral);
  extVectorElementExpr @304 :List(ExtVectorElementExpr);
  expressionTraitExpr @305 :List(ExpressionTraitExpr);
  attributedStmt @306 :List(AttributedStmt);
  switchStmt @307 :List(SwitchStmt);
  defaultStmt @308 :List(DefaultStmt);
  caseStmt @309 :List(CaseStmt);
  templateTypeParmType @310 :List(TemplateTypeParmType);
  templateSpecializationType @311 :List(TemplateSpecializationType);
  tagType @312 :List(TagType);
  recordType @313 :List(RecordType);
  enumType @314 :List(EnumType);
  substTemplateTypeParmType @315 :List(SubstTemplateTypeParmType);
  substTemplateTypeParmPackType @316 :List(SubstTemplateTypeParmPackType);
  referenceType @317 :List(ReferenceType);
  rValueReferenceType @318 :List(RValueReferenceType);
  lValueReferenceType @319 :List(LValueReferenceType);
  pointerType @320 :List(PointerType);
  pipeType @321 :List(PipeType);
  parenType @322 :List(ParenType);
  packExpansionType @323 :List(PackExpansionType);
  objCTypeParamType @324 :List(ObjCTypeParamType);
  objCObjectType @325 :List(ObjCObjectType);
  objCInterfaceType @326 :List(ObjCInterfaceType);
  objCObjectPointerType @327 :List(ObjCObjectPointerType);
  memberPointerType @328 :List(MemberPointerType);
  matrixType @329 :List(MatrixType);
  dependentSizedMatrixType @330 :List(DependentSizedMatrixType);
  constantMatrixType @331 :List(ConstantMatrixType);
  macroQualifiedType @332 :List(MacroQualifiedType);
  injectedClassNameType @333 :List(InjectedClassNameType);
  functionType @334 :List(FunctionType);
  functionProtoType @335 :List(FunctionProtoType);
  functionNoProtoType @336 :List(FunctionNoProtoType);
  extIntType @337 :List(ExtIntType);
  dependentVectorType @338 :List(DependentVectorType);
  dependentSizedExtVectorType @339 :List(DependentSizedExtVectorType);
  dependentExtIntType @340 :List(DependentExtIntType);
  dependentAddressSpaceType @341 :List(DependentAddressSpaceType);
  deducedType @342 :List(DeducedType);
  deducedTemplateSpecializationType @343 :List(DeducedTemplateSpecializationType);
  autoType @344 :List(AutoType);
  decltypeType @345 :List(DecltypeType);
  complexType @346 :List(ComplexType);
  builtinType @347 :List(BuiltinType);
  blockPointerType @348 :List(BlockPointerType);
  attributedType @349 :List(AttributedType);
  atomicType @350 :List(AtomicType);
  arrayType @351 :List(ArrayType);
  variableArrayType @352 :List(VariableArrayType);
  incompleteArrayType @353 :List(IncompleteArrayType);
  dependentSizedArrayType @354 :List(DependentSizedArrayType);
  constantArrayType @355 :List(ConstantArrayType);
  adjustedType @356 :List(AdjustedType);
  decayedType @357 :List(DecayedType);
  vectorType @358 :List(VectorType);
  extVectorType @359 :List(ExtVectorType);
  unresolvedUsingType @360 :List(UnresolvedUsingType);
  unaryTransformType @361 :List(UnaryTransformType);
  typedefType @362 :List(TypedefType);
  typeOfType @363 :List(TypeOfType);
  typeOfExprType @364 :List(TypeOfExprType);
}
