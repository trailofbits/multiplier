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
  kind @0 :TokenKind;
  data @1 :Text;
}

struct TokenRange @0xfaaa666ba10b6696 {
  beginId @0 :UInt64;
  endId @1 :UInt64;  # Inclusive.
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
  utf8 @2 $Cxx.name("utf8");
  utf16 @3 $Cxx.name("utf16");
  utf32 @4 $Cxx.name("utf32");
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
  cxx11Nullptr @3 $Cxx.name("cxx11_nullptr");
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
  utf8 @2 $Cxx.name("utf8");
  utf16 @3 $Cxx.name("utf16");
  utf32 @4 $Cxx.name("utf32");
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
  cxx11NoReturn @115 $Cxx.name("cxx11_no_return");
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
  msp430Interrupt @173 $Cxx.name("msp430_interrupt");
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
  parameterTypestate @241 $Cxx.name("parameter_typestate");
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
  alwaysarg1 @3 $Cxx.name("alwaysarg1");
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
  msvc2010 @0 $Cxx.name("msvc2010");
  msvc2012 @1 $Cxx.name("msvc2012");
  msvc2013 @2 $Cxx.name("msvc2013");
  msvc2015 @3 $Cxx.name("msvc2015");
  msvc2017 @4 $Cxx.name("msvc2017");
  msvc20175 @5 $Cxx.name("msvc20175");
  msvc20177 @6 $Cxx.name("msvc20177");
  msvc2019 @7 $Cxx.name("msvc2019");
  msvc20198 @8 $Cxx.name("msvc20198");
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
  cxx11ClangAarch64VectorPcs @1 $Cxx.name("cxx11_clang_aarch64_vector_pcs");
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
  cxx11 @1 $Cxx.name("cxx11");
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
  useTailPaddingUnlessPod03 @1 $Cxx.name("use_tail_padding_unless_pod03");
  useTailPaddingUnlessPod11 @2 $Cxx.name("use_tail_padding_unless_pod11");
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
  objCTypeParameter @32 $Cxx.name("obj_c_type_parameter");
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

struct Compiler @0x848f89979be4f62d {
  name @0 :CompilerName;
  targetLanguage @1 :TargetLanguage;
  hostTargetTriple @2 :Text;
  targetTriple @3 :Text;
  executablePath @4 :Text;
  resourceDirectory @5 :Text;
  systemRootDirectory @6 :Text;
  systemRootIncludeDirectory @7 :Text;
  installationDirectory @8 :Text;
  systemIncludeDirectories @9 :List(IncludePath);
  userIncludeDirectories @10 :List(IncludePath);
  frameworkDirectories @11 :List(IncludePath);
}

struct IncludePath @0x956b138aef6183ee {
  path @0 :Text;
  location @1 :IncludePathLocation;
}

struct CompileCommand @0xd13fdf9a06e1cf47 {
  arguments @0 :List(Text);
  workingDirectory @1 :Text;
}

struct CompileJob @0xa4db2371361c41ba {
  arguments @0 :List(Text);
  workingDirectory @1 :Text;
  resourceDirectory @2 :Text;
  systemRootDirectory @3 :Text;
  systemRootIncludeDirectory @4 :Text;
  targetTriple @5 :Text;
  auxiliaryTargetTriple @6 :Text;
}

struct FileToken @0xca57e1a97ecb7687 {
  kind @0 :TokenKind;
  preProcessorKeywordKind @1 :PPKeywordKind;
  objectiveCAtKeywordKind @2 :ObjCKeywordKind;
  line @3 :UInt32;
  column @4 :UInt32;
  data @5 :Text;
}

struct TemplateParameterList @0xee0d4e6aba92fdde {
  numParameters @0 :UInt32;
  numRequiredParameters @1 :UInt32;
  depth @2 :UInt32;
  hasUnexpandedParameterPack @3 :Bool;
  hasParameterPack @4 :Bool;
  templateKeywordToken @5 :UInt64;
  leftAngleToken @6 :UInt64;
  rightAngleToken @7 :UInt64;
  tokenRange @8 :TokenRange;
  parameters @9 :List(UInt64);
}

struct TemplateArgument @0xb5127dad01992f67 {
  kind @0 :TemplateArgumentKind;
  isNull @1 :Bool;
  isDependent @2 :Bool;
  isInstantiationDependent @3 :Bool;
  containsUnexpandedParameterPack @4 :Bool;
  isPackExpansion @5 :Bool;
  asDeclaration @6 :UInt64;
  asDeclarationIsPresent @7 :UInt64;
}

struct CXXBaseSpecifier @0x8e0e4024ab6be99f {
  tokenRange @0 :TokenRange;
  baseTypeToken @1 :UInt64;
  isVirtual @2 :Bool;
  baseKind @3 :TagTypeKind;
  isPackExpansion @4 :Bool;
  constructorsAreInherited @5 :Bool;
  ellipsis @6 :UInt64;
  ellipsisIsPresent @7 :UInt64;
  semanticAccessSpecifier @8 :AccessSpecifier;
  lexicalAccessSpecifier @9 :AccessSpecifier;
}

struct Stmt @0x91127d30fade9a32 {
  beginToken @0 :UInt64;
  endToken @1 :UInt64;
  tokenRange @2 :TokenRange;
  kind @3 :StmtKind;
}

struct SEHTryStmt @0xf24201c85c654a91 {
  stmt @0:Stmt;
  exceptHandler @1 :UInt64;
  finallyHandler @2 :UInt64;
  isCxxTry @3 :Bool;
  tryBlock @4 :UInt64;
  tryToken @5 :UInt64;
}

struct SEHLeaveStmt @0xc4e4ea7e9d86c292 {
  stmt @0:Stmt;
  leaveToken @1 :UInt64;
}

struct SEHFinallyStmt @0x8331103206247bcd {
  stmt @0:Stmt;
  block @1 :UInt64;
  finallyToken @2 :UInt64;
}

struct SEHExceptStmt @0xec2050c67aa8fa46 {
  stmt @0:Stmt;
  block @1 :UInt64;
  exceptToken @2 :UInt64;
}

struct ReturnStmt @0xa64f08dfd7dbc80a {
  stmt @0:Stmt;
  nrvoCandidate @1 :UInt64;
  returnToken @2 :UInt64;
}

struct ObjCForCollectionStmt @0x9eba75a6b3c891a0 {
  stmt @0:Stmt;
  forToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ObjCAutoreleasePoolStmt @0x9762e1f9121378d2 {
  stmt @0:Stmt;
  atToken @1 :UInt64;
}

struct ObjCAtTryStmt @0x8a11f497922c60fa {
  stmt @0:Stmt;
  atTryToken @1 :UInt64;
  finallyStatement @2 :UInt64;
  catchStatements @3 :List(UInt64);
}

struct ObjCAtThrowStmt @0xd0de9b13bfbb829d {
  stmt @0:Stmt;
  throwToken @1 :UInt64;
}

struct ObjCAtSynchronizedStmt @0xc002bd58ce946b42 {
  stmt @0:Stmt;
  atSynchronizedToken @1 :UInt64;
  synchBody @2 :UInt64;
}

struct ObjCAtFinallyStmt @0xb4641f5dbb7b9c51 {
  stmt @0:Stmt;
  atFinallyToken @1 :UInt64;
}

struct ObjCAtCatchStmt @0xea4d614d29e03f4e {
  stmt @0:Stmt;
  atCatchToken @1 :UInt64;
  catchParameterDeclaration @2 :UInt64;
  rParenToken @3 :UInt64;
  hasEllipsis @4 :Bool;
}

struct OMPExecutableDirective @0xd9ecc0e6e88a888e {
  stmt @0:Stmt;
  innermostCapturedStatement @1 :UInt64;
  hasAssociatedStatement @2 :Bool;
  isStandaloneDirective @3 :Bool;
}

struct OMPDispatchDirective @0xf2ebe316be280493 {
  ompExecutableDirective @0:OMPExecutableDirective;
  targetCallToken @1 :UInt64;
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
  distanceFunc @1 :UInt64;
  loopVariableFunc @2 :UInt64;
  loopVariableReference @3 :UInt64;
}

struct NullStmt @0xb57ca05aaf806566 {
  stmt @0:Stmt;
  semiToken @1 :UInt64;
  hasLeadingEmptyMacro @2 :Bool;
}

struct MSDependentExistsStmt @0xb5d9dfc73eeb0939 {
  stmt @0:Stmt;
  keywordToken @1 :UInt64;
  subStatement @2 :UInt64;
  isIfExists @3 :Bool;
  isIfNotExists @4 :Bool;
}

struct IndirectGotoStmt @0xca063608491ba1fa {
  stmt @0:Stmt;
  constantTarget @1 :UInt64;
  gotoToken @2 :UInt64;
  starToken @3 :UInt64;
}

struct IfStmt @0xfc829da66c4e6bb1 {
  stmt @0:Stmt;
  conditionVariable @1 :UInt64;
  conditionVariableDeclarationStatement @2 :UInt64;
  elseToken @3 :UInt64;
  ifToken @4 :UInt64;
  lParenToken @5 :UInt64;
  rParenToken @6 :UInt64;
  hasElseStorage @7 :Bool;
  hasInitializerStorage @8 :Bool;
  hasVariableStorage @9 :Bool;
  isConstexpr @10 :Bool;
  isObjCAvailabilityCheck @11 :Bool;
}

struct GotoStmt @0xf542902873fc6c2b {
  stmt @0:Stmt;
  gotoToken @1 :UInt64;
  label @2 :UInt64;
  labelToken @3 :UInt64;
}

struct ForStmt @0xb6591c23541f6a1e {
  stmt @0:Stmt;
  conditionVariable @1 :UInt64;
  conditionVariableDeclarationStatement @2 :UInt64;
  forToken @3 :UInt64;
  lParenToken @4 :UInt64;
  rParenToken @5 :UInt64;
}

struct DoStmt @0xf6407ae4f3214356 {
  stmt @0:Stmt;
  doToken @1 :UInt64;
  rParenToken @2 :UInt64;
  whileToken @3 :UInt64;
}

struct DeclStmt @0xa672643824ce0ba3 {
  stmt @0:Stmt;
  isSingleDeclaration @1 :Bool;
}

struct CoroutineBodyStmt @0xac9fd8887bfea7d8 {
  stmt @0:Stmt;
  promiseDeclaration @1 :UInt64;
  hasDependentPromiseType @2 :Bool;
}

struct CoreturnStmt @0xfada897216b226f1 {
  stmt @0:Stmt;
  keywordToken @1 :UInt64;
  isImplicit @2 :Bool;
}

struct ContinueStmt @0xb364bd3d9a19cd05 {
  stmt @0:Stmt;
  continueToken @1 :UInt64;
}

struct CompoundStmt @0xd080c9192fa41c92 {
  stmt @0:Stmt;
  lBracToken @1 :UInt64;
  rBracToken @2 :UInt64;
}

struct CapturedStmt @0xa60fffc1366b48e6 {
  stmt @0:Stmt;
  capturedDeclaration @1 :UInt64;
  capturedRecordDeclaration @2 :UInt64;
  capturedRegionKind @3 :CapturedRegionKind;
}

struct CXXTryStmt @0xf98f02d4cdc2dd3b {
  stmt @0:Stmt;
  tryBlock @1 :UInt64;
  tryToken @2 :UInt64;
  handlers @3 :List(UInt64);
}

struct CXXForRangeStmt @0xa23a75b3c0fa7d86 {
  stmt @0:Stmt;
  beginStatement @1 :UInt64;
  coawaitToken @2 :UInt64;
  colonToken @3 :UInt64;
  endStatement @4 :UInt64;
  forToken @5 :UInt64;
  loopVariableStatement @6 :UInt64;
  loopVariable @7 :UInt64;
  rParenToken @8 :UInt64;
  rangeStatement @9 :UInt64;
}

struct CXXCatchStmt @0xac4b9e8390fd3a85 {
  stmt @0:Stmt;
  catchToken @1 :UInt64;
  exceptionDeclaration @2 :UInt64;
}

struct BreakStmt @0x940efd4e9770cb41 {
  stmt @0:Stmt;
  breakToken @1 :UInt64;
}

struct AsmStmt @0xa47714ac2d00fb21 {
  stmt @0:Stmt;
  generateAssemblyString @1 :Text;
  assemblyToken @2 :UInt64;
  isSimple @3 :Bool;
  isVolatile @4 :Bool;
  outputConstraints @5 :List(Text);
  inputConstraints @6 :List(Text);
  clobbers @7 :List(Text);
}

struct MSAsmStmt @0xc504268dee34a98f {
  asmStmt @0:AsmStmt;
  allConstraints @1 :List(Text);
  assemblyString @2 :Text;
  lBraceToken @3 :UInt64;
  hasBraces @4 :Bool;
}

struct GCCAsmStmt @0x9d046a0d94b425db {
  asmStmt @0:AsmStmt;
  assemblyString @1 :UInt64;
  rParenToken @2 :UInt64;
  isAssemblyGoto @3 :Bool;
  labels @4 :List(UInt64);
  outputConstraintLiterals @5 :List(UInt64);
  outputNames @6 :List(Text);
  inputConstraintLiterals @7 :List(UInt64);
  inputNames @8 :List(Text);
  clobberStringLiterals @9 :List(UInt64);
  labelExpressions @10 :List(UInt64);
  labelNames @11 :List(Text);
}

struct WhileStmt @0x8f0fb0e808ef8cd3 {
  stmt @0:Stmt;
  conditionVariable @1 :UInt64;
  conditionVariableDeclarationStatement @2 :UInt64;
  lParenToken @3 :UInt64;
  rParenToken @4 :UInt64;
  whileToken @5 :UInt64;
  hasVariableStorage @6 :Bool;
}

struct ValueStmt @0xc78a8bda41f72525 {
  stmt @0:Stmt;
}

struct LabelStmt @0xed2b87febf6a7cc9 {
  valueStmt @0:ValueStmt;
  declaration @1 :UInt64;
  identifierToken @2 :UInt64;
  name @3 :Text;
  isSideEntry @4 :Bool;
}

struct Expr @0x9e4316b5a505b8d6 {
  valueStmt @0:ValueStmt;
  hasSideEffects @1 :Bool;
  containsErrors @2 :Bool;
  containsUnexpandedParameterPack @3 :Bool;
  bestDynamicClassType @4 :UInt64;
  expressionToken @5 :UInt64;
  objCProperty @6 :UInt64;
  objectKind @7 :ExprObjectKind;
  sourceBitField @8 :UInt64;
  valueKind @9 :ExprValueKind;
  hasNonTrivialCall @10 :Bool;
  isDefaultArgument @11 :Bool;
  isGlValue @12 :Bool;
  isImplicitCxxThis @13 :Bool;
  isInstantiationDependent @14 :Bool;
  isKnownToHaveBooleanValue @15 :Bool;
  isLValue @16 :Bool;
  isObjcgcCandidate @17 :Bool;
  isObjCSelfExpression @18 :Bool;
  isOrdinaryOrBitFieldObject @19 :Bool;
  isPrValue @20 :Bool;
  isReadIfDiscardedInCPlusPlus11 @21 :Bool;
  isTypeDependent @22 :Bool;
  isValueDependent @23 :Bool;
  isXValue @24 :Bool;
  refersToBitField @25 :Bool;
  refersToGlobalRegisterVariable @26 :Bool;
  refersToMatrixElement @27 :Bool;
  refersToVectorElement @28 :Bool;
}

struct DesignatedInitUpdateExpr @0xaa6c77a8da7c4fba {
  expr @0:Expr;
  updater @1 :UInt64;
}

struct DesignatedInitExpr @0xeff2c52d9c942ab2 {
  expr @0:Expr;
  designatorsSourceRange @1 :TokenRange;
  equalOrColonToken @2 :UInt64;
  isDirectInitializer @3 :Bool;
  usesGnuSyntax @4 :Bool;
}

struct DependentScopeDeclRefExpr @0x8fbb6ccb95a3509d {
  expr @0:Expr;
  lAngleToken @1 :UInt64;
  rAngleToken @2 :UInt64;
  templateKeywordToken @3 :UInt64;
  hasExplicitTemplateArguments @4 :Bool;
  hasTemplateKeyword @5 :Bool;
}

struct DependentCoawaitExpr @0x8fd8a27becb59315 {
  expr @0:Expr;
  keywordToken @1 :UInt64;
  operatorCoawaitLookup @2 :UInt64;
}

struct DeclRefExpr @0xec5119d27610b166 {
  expr @0:Expr;
  declaration @1 :UInt64;
  foundDeclaration @2 :UInt64;
  lAngleToken @3 :UInt64;
  rAngleToken @4 :UInt64;
  templateKeywordToken @5 :UInt64;
  hadMultipleCandidates @6 :Bool;
  hasExplicitTemplateArguments @7 :Bool;
  hasQualifier @8 :Bool;
  hasTemplateKwAndArgumentsInfo @9 :Bool;
  hasTemplateKeyword @10 :Bool;
  isNonOdrUse @11 :NonOdrUseReason;
  refersToEnclosingVariableOrCapture @12 :Bool;
}

struct CoroutineSuspendExpr @0xbd92ba696775fd54 {
  expr @0:Expr;
  keywordToken @1 :UInt64;
  opaqueValue @2 :UInt64;
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
  builtinToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ConceptSpecializationExpr @0xfed5bd9e47227653 {
  expr @0:Expr;
  templateArguments @1 :List(TemplateArgument);
  isSatisfied @2 :Bool;
}

struct CompoundLiteralExpr @0x9865eabaf4e2ef8c {
  expr @0:Expr;
  lParenToken @1 :UInt64;
  isFileScope @2 :Bool;
}

struct ChooseExpr @0xd4a658caf5a1339e {
  expr @0:Expr;
  builtinToken @1 :UInt64;
  rParenToken @2 :UInt64;
  isConditionDependent @3 :Bool;
  isConditionTrue @4 :Bool;
}

struct CharacterLiteral @0xbe144b3e9bdba5d9 {
  expr @0:Expr;
  token @1 :UInt64;
}

struct CastExpr @0x8cabd91ab4a4dcb3 {
  expr @0:Expr;
  castKind @1 :CastKind;
  castKindName @2 :Text;
  conversionFunction @3 :UInt64;
  targetUnionField @4 :UInt64;
  hasStoredFpFeatures @5 :Bool;
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
  operatorToken @3 :UInt64;
  rParenToken @4 :UInt64;
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
  lParenToken @1 :UInt64;
  rParenToken @2 :UInt64;
  isListInitialization @3 :Bool;
}

struct CStyleCastExpr @0xddb96d0ba671cd89 {
  explicitCastExpr @0:ExplicitCastExpr;
  lParenToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct BuiltinBitCastExpr @0xc4d665f00ba3fa8b {
  explicitCastExpr @0:ExplicitCastExpr;
}

struct ObjCBridgedCastExpr @0xad38ef321a1ce1e3 {
  explicitCastExpr @0:ExplicitCastExpr;
  bridgeKeywordToken @1 :UInt64;
  bridgeKind @2 :ObjCBridgeCastKind;
  bridgeKindName @3 :Text;
  lParenToken @4 :UInt64;
}

struct CallExpr @0x8cff24c7f68e334b {
  expr @0:Expr;
  adlCallKind @1 :CallExprADLCallKind;
  directCallee @2 :UInt64;
  rParenToken @3 :UInt64;
  hasStoredFpFeatures @4 :Bool;
  hasUnusedResultAttribute @5 :Bool;
  isBuiltinAssumeFalse @6 :Bool;
  isCallToStdMove @7 :Bool;
  isUnevaluatedBuiltinCall @8 :Bool;
  usesAdl @9 :Bool;
}

struct CXXOperatorCallExpr @0xb6a5653b33cdf0c5 {
  callExpr @0:CallExpr;
  operator @1 :OverloadedOperatorKind;
  operatorToken @2 :UInt64;
  isAssignmentOperation @3 :Bool;
  isComparisonOperation @4 :Bool;
  isInfixBinaryOperation @5 :Bool;
}

struct CXXMemberCallExpr @0x9a761539349dc02f {
  callExpr @0:CallExpr;
  methodDeclaration @1 :UInt64;
  recordDeclaration @2 :UInt64;
}

struct CUDAKernelCallExpr @0xd0bc1c26ca1e132f {
  callExpr @0:CallExpr;
  config @1 :UInt64;
}

struct UserDefinedLiteral @0xa1af860a6baa1029 {
  callExpr @0:CallExpr;
  literalOperatorKind @1 :UserDefinedLiteralLiteralOperatorKind;
  udSuffixToken @2 :UInt64;
}

struct CXXUuidofExpr @0xcdde7d28fc7931f6 {
  expr @0:Expr;
  guidDeclaration @1 :UInt64;
  isTypeOperand @2 :Bool;
}

struct CXXUnresolvedConstructExpr @0x9fbb7e373f171f86 {
  expr @0:Expr;
  lParenToken @1 :UInt64;
  rParenToken @2 :UInt64;
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
  throwToken @1 :UInt64;
  isThrownVariableInScope @2 :Bool;
}

struct CXXThisExpr @0x959ba6d5fec8b422 {
  expr @0:Expr;
  token @1 :UInt64;
  isImplicit @2 :Bool;
}

struct CXXStdInitializerListExpr @0xd199eb3b19c592fa {
  expr @0:Expr;
}

struct CXXScalarValueInitExpr @0x9fd4b7d4985831e7 {
  expr @0:Expr;
  rParenToken @1 :UInt64;
}

struct CXXRewrittenBinaryOperator @0xd00648fa0bd5ccc4 {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeString @2 :Text;
  operator @3 :BinaryOperatorKind;
  operatorToken @4 :UInt64;
  isAssignmentOperation @5 :Bool;
  isComparisonOperation @6 :Bool;
  isReversed @7 :Bool;
}

struct CXXPseudoDestructorExpr @0xfb788932e740ac07 {
  expr @0:Expr;
  colonColonToken @1 :UInt64;
  destroyedTypeToken @2 :UInt64;
  operatorToken @3 :UInt64;
  tildeToken @4 :UInt64;
  hasQualifier @5 :Bool;
  isArrow @6 :Bool;
}

struct CXXNullPtrLiteralExpr @0x80352ea6175b520f {
  expr @0:Expr;
  token @1 :UInt64;
}

struct CXXNoexceptExpr @0x97e76c7f0648cbe4 {
  expr @0:Expr;
  value @1 :Bool;
}

struct CXXNewExpr @0x9dca0c0f9404e2b5 {
  expr @0:Expr;
  doesUsualArrayDeleteWantSize @1 :Bool;
  constructExpression @2 :UInt64;
  directInitializerRange @3 :TokenRange;
  initializationStyle @4 :CXXNewExprInitializationStyle;
  operatorDelete @5 :UInt64;
  operatorNew @6 :UInt64;
  typeIdParentheses @7 :TokenRange;
  hasInitializer @8 :Bool;
  isArray @9 :Bool;
  isGlobalNew @10 :Bool;
  isParenthesisTypeId @11 :Bool;
  passAlignment @12 :Bool;
  shouldNullCheckAllocation @13 :Bool;
}

struct CXXInheritedCtorInitExpr @0xd5db83de022b1ee3 {
  expr @0:Expr;
  constructsVirtualBase @1 :Bool;
  constructionKind @2 :CXXConstructExprConstructionKind;
  constructor @3 :UInt64;
  token @4 :UInt64;
  inheritedFromVirtualBase @5 :Bool;
}

struct CXXFoldExpr @0x8a593922e3ea9d50 {
  expr @0:Expr;
  callee @1 :UInt64;
  ellipsisToken @2 :UInt64;
  lParenToken @3 :UInt64;
  operator @4 :BinaryOperatorKind;
  rParenToken @5 :UInt64;
  isLeftFold @6 :Bool;
  isRightFold @7 :Bool;
}

struct CXXDependentScopeMemberExpr @0xa1a21ac74e691c1f {
  expr @0:Expr;
  firstQualifierFoundInScope @1 :UInt64;
  lAngleToken @2 :UInt64;
  memberToken @3 :UInt64;
  operatorToken @4 :UInt64;
  rAngleToken @5 :UInt64;
  templateKeywordToken @6 :UInt64;
  hasExplicitTemplateArguments @7 :Bool;
  hasTemplateKeyword @8 :Bool;
  isArrow @9 :Bool;
  isImplicitAccess @10 :Bool;
}

struct CXXDeleteExpr @0x80f6cd450a27b9d4 {
  expr @0:Expr;
  doesUsualArrayDeleteWantSize @1 :Bool;
  operatorDelete @2 :UInt64;
  isArrayForm @3 :Bool;
  isArrayFormAsWritten @4 :Bool;
  isGlobalDelete @5 :Bool;
}

struct CXXDefaultInitExpr @0xa78e81b7ba8da8e6 {
  expr @0:Expr;
  field @1 :UInt64;
  usedToken @2 :UInt64;
}

struct CXXDefaultArgExpr @0x9f9ee9dcf349cbcf {
  expr @0:Expr;
  parameter @1 :UInt64;
  usedToken @2 :UInt64;
}

struct CXXConstructExpr @0xb3d036394c09ed48 {
  expr @0:Expr;
  constructionKind @1 :CXXConstructExprConstructionKind;
  constructor @2 :UInt64;
  token @3 :UInt64;
  parenthesisOrBraceRange @4 :TokenRange;
  hadMultipleCandidates @5 :Bool;
  isElidable @6 :Bool;
  isListInitialization @7 :Bool;
  isStdInitializerListInitialization @8 :Bool;
  requiresZeroInitialization @9 :Bool;
}

struct CXXTemporaryObjectExpr @0xb4be9b66753a2671 {
  cxxConstructExpr @0:CXXConstructExpr;
}

struct CXXBoolLiteralExpr @0x862b8d87bd2905e0 {
  expr @0:Expr;
  token @1 :UInt64;
  value @2 :Bool;
}

struct CXXBindTemporaryExpr @0xc6a96978d42dc702 {
  expr @0:Expr;
}

struct BlockExpr @0xc2ae5be0934c61f3 {
  expr @0:Expr;
  blockDeclaration @1 :UInt64;
  caretToken @2 :UInt64;
}

struct BinaryOperator @0xd858b89bd116f05f {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeString @2 :Text;
  operatorToken @3 :UInt64;
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
  builtinToken @1 :UInt64;
  operation @2 :AtomicExprAtomicOp;
  rParenToken @3 :UInt64;
  isCmpXChg @4 :Bool;
  isOpenCl @5 :Bool;
  isVolatile @6 :Bool;
}

struct AsTypeExpr @0xf646590167dcf1ab {
  expr @0:Expr;
  builtinToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ArrayTypeTraitExpr @0xcbcb35a78956a3cc {
  expr @0:Expr;
  trait @1 :ArrayTypeTrait;
}

struct ArraySubscriptExpr @0xb5bb680da7ccce33 {
  expr @0:Expr;
  rBracketToken @1 :UInt64;
}

struct ArrayInitLoopExpr @0xbe95601783117ebe {
  expr @0:Expr;
  commonExpression @1 :UInt64;
}

struct ArrayInitIndexExpr @0xc9bc62bebe2cdbb8 {
  expr @0:Expr;
}

struct AddrLabelExpr @0xc1abc55fece6aa91 {
  expr @0:Expr;
  ampAmpToken @1 :UInt64;
  label @2 :UInt64;
  labelToken @3 :UInt64;
}

struct AbstractConditionalOperator @0xee7097774f7aaa45 {
  expr @0:Expr;
  colonToken @1 :UInt64;
  questionToken @2 :UInt64;
}

struct ConditionalOperator @0xd3810312a3bd13c7 {
  abstractConditionalOperator @0:AbstractConditionalOperator;
}

struct BinaryConditionalOperator @0xde5f047672b1ac84 {
  abstractConditionalOperator @0:AbstractConditionalOperator;
  opaqueValue @1 :UInt64;
}

struct VAArgExpr @0x8fa746d782ee27c9 {
  expr @0:Expr;
  builtinToken @1 :UInt64;
  rParenToken @2 :UInt64;
  isMicrosoftAbi @3 :Bool;
}

struct UnaryOperator @0xaa78820aaa7f22b8 {
  expr @0:Expr;
  canOverflow @1 :Bool;
  opcode @2 :UnaryOperatorKind;
  operatorToken @3 :UInt64;
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
  operatorToken @1 :UInt64;
  rParenToken @2 :UInt64;
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
  parameterPack @1 :UInt64;
  parameterPackToken @2 :UInt64;
}

struct SubstNonTypeTemplateParmExpr @0xad38ba4bfe617a6f {
  expr @0:Expr;
  nameToken @1 :UInt64;
  parameter @2 :UInt64;
  isReferenceParameter @3 :Bool;
}

struct StringLiteral @0xd0cec44e02f59cf2 {
  expr @0:Expr;
  containsNonAscii @1 :Bool;
  containsNonAsciiOrNull @2 :Bool;
  bytes @3 :Text;
  string @4 :Text;
  isAscii @5 :Bool;
  isPascal @6 :Bool;
  isUtf16 @7 :Bool;
  isUtf32 @8 :Bool;
  isUtf8 @9 :Bool;
  isWide @10 :Bool;
}

struct StmtExpr @0xe3606abe04461b8a {
  expr @0:Expr;
  lParenToken @1 :UInt64;
  rParenToken @2 :UInt64;
  subStatement @3 :UInt64;
}

struct SourceLocExpr @0xd4bebb374e1e6d58 {
  expr @0:Expr;
  builtinString @1 :Text;
  identifierKind @2 :SourceLocExprIdentKind;
  token @3 :UInt64;
  isIntType @4 :Bool;
  isStringType @5 :Bool;
}

struct SizeOfPackExpr @0xa4f777d7b3ce890c {
  expr @0:Expr;
  operatorToken @1 :UInt64;
  pack @2 :UInt64;
  packToken @3 :UInt64;
  partialArguments @4 :List(TemplateArgument);
  rParenToken @5 :UInt64;
  isPartiallySubstituted @6 :Bool;
}

struct ShuffleVectorExpr @0xdfa87964ccc4abd6 {
  expr @0:Expr;
  builtinToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct SYCLUniqueStableNameExpr @0xfa67d59d16f9a78a {
  expr @0:Expr;
  computeName @1 :Text;
  lParenToken @2 :UInt64;
  token @3 :UInt64;
  rParenToken @4 :UInt64;
}

struct RequiresExpr @0xe4f5db5ba506ab26 {
  expr @0:Expr;
  body @1 :UInt64;
  localParameters @2 :List(UInt64);
  rBraceToken @3 :UInt64;
  requiresKwToken @4 :UInt64;
  isSatisfied @5 :Bool;
}

struct RecoveryExpr @0xa9e048a5bbe9f6bd {
  expr @0:Expr;
}

struct PseudoObjectExpr @0xf7795b8660a50a1e {
  expr @0:Expr;
}

struct PredefinedExpr @0xf512f62d75089164 {
  expr @0:Expr;
  functionName @1 :UInt64;
  identifierKind @2 :PredefinedExprIdentKind;
  identifierKindName @3 :Text;
  token @4 :UInt64;
}

struct ParenListExpr @0xc7ba76bb20cf6201 {
  expr @0:Expr;
  lParenToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ParenExpr @0x821bf890921895cd {
  expr @0:Expr;
  lParen @1 :UInt64;
  rParen @2 :UInt64;
}

struct PackExpansionExpr @0xbf1eafc846bba2e0 {
  expr @0:Expr;
  ellipsisToken @1 :UInt64;
}

struct OverloadExpr @0xe1320ca92341cff5 {
  expr @0:Expr;
  lAngleToken @1 :UInt64;
  nameToken @2 :UInt64;
  namingClass @3 :UInt64;
  rAngleToken @4 :UInt64;
  templateKeywordToken @5 :UInt64;
  hasExplicitTemplateArguments @6 :Bool;
  hasTemplateKeyword @7 :Bool;
}

struct UnresolvedMemberExpr @0xbd4aeea6486879d1 {
  overloadExpr @0:OverloadExpr;
  memberToken @1 :UInt64;
  operatorToken @2 :UInt64;
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
  token @1 :UInt64;
  isUnique @2 :Bool;
}

struct OffsetOfExpr @0xe74e51b681474f08 {
  expr @0:Expr;
  operatorToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ObjCSubscriptRefExpr @0x827d6564c3126c7a {
  expr @0:Expr;
  atIndexMethodDeclaration @1 :UInt64;
  rBracket @2 :UInt64;
  isArraySubscriptReferenceExpression @3 :Bool;
}

struct ObjCStringLiteral @0x84470e968f7365fb {
  expr @0:Expr;
  atToken @1 :UInt64;
  string @2 :UInt64;
}

struct ObjCSelectorExpr @0xa6687e4a6275988d {
  expr @0:Expr;
  atToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ObjCProtocolExpr @0xb07709e6d6281804 {
  expr @0:Expr;
  atToken @1 :UInt64;
  protocol @2 :UInt64;
  protocolIdToken @3 :UInt64;
  rParenToken @4 :UInt64;
}

struct ObjCPropertyRefExpr @0x9f75c18ee7f1c7a2 {
  expr @0:Expr;
  classReceiver @1 :UInt64;
  explicitProperty @2 :UInt64;
  implicitPropertyGetter @3 :UInt64;
  implicitPropertySetter @4 :UInt64;
  token @5 :UInt64;
  receiverToken @6 :UInt64;
  isClassReceiver @7 :Bool;
  isExplicitProperty @8 :Bool;
  isImplicitProperty @9 :Bool;
  isMessagingGetter @10 :Bool;
  isMessagingSetter @11 :Bool;
  isObjectReceiver @12 :Bool;
  isSuperReceiver @13 :Bool;
}

struct ObjCMessageExpr @0xc53f62c71ed8d723 {
  expr @0:Expr;
  leftToken @1 :UInt64;
  methodDeclaration @2 :UInt64;
  methodFamily @3 :ObjCMethodFamily;
  receiverInterface @4 :UInt64;
  receiverKind @5 :ObjCMessageExprReceiverKind;
  receiverRange @6 :TokenRange;
  rightToken @7 :UInt64;
  selectorStartToken @8 :UInt64;
  superToken @9 :UInt64;
  isClassMessage @10 :Bool;
  isDelegateInitializerCall @11 :Bool;
  isImplicit @12 :Bool;
  isInstanceMessage @13 :Bool;
  selectorTokens @14 :List(UInt64);
}

struct ObjCIvarRefExpr @0xec7058b5b38773dd {
  expr @0:Expr;
  declaration @1 :UInt64;
  token @2 :UInt64;
  operationToken @3 :UInt64;
  isArrow @4 :Bool;
  isFreeInstanceVariable @5 :Bool;
}

struct ObjCIsaExpr @0xe3c04c83aef329c8 {
  expr @0:Expr;
  baseTokenEnd @1 :UInt64;
  isaMemberToken @2 :UInt64;
  operationToken @3 :UInt64;
  isArrow @4 :Bool;
}

struct ObjCIndirectCopyRestoreExpr @0x9475cc6d12ba1afb {
  expr @0:Expr;
  shouldCopy @1 :Bool;
}

struct ObjCEncodeExpr @0x911855b6fa2d9812 {
  expr @0:Expr;
  atToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct ObjCDictionaryLiteral @0xaef4d291186415b7 {
  expr @0:Expr;
  dictionaryWithObjectsMethod @1 :UInt64;
}

struct ObjCBoxedExpr @0xae80861f1a63c950 {
  expr @0:Expr;
  atToken @1 :UInt64;
  boxingMethod @2 :UInt64;
  isExpressibleAsConstantInitializer @3 :Bool;
}

struct ObjCBoolLiteralExpr @0xb2d027f2c8cad1fb {
  expr @0:Expr;
  token @1 :UInt64;
  value @2 :Bool;
}

struct ObjCAvailabilityCheckExpr @0xbd477d54907fe95a {
  expr @0:Expr;
  hasVersion @1 :Bool;
}

struct ObjCArrayLiteral @0xa36b5cac081b468a {
  expr @0:Expr;
  arrayWithObjectsMethod @1 :UInt64;
}

struct OMPIteratorExpr @0xd52a7668addb282d {
  expr @0:Expr;
  iteratorKwToken @1 :UInt64;
  lParenToken @2 :UInt64;
  rParenToken @3 :UInt64;
}

struct OMPArrayShapingExpr @0xcddd3cf38d603be1 {
  expr @0:Expr;
  lParenToken @1 :UInt64;
  rParenToken @2 :UInt64;
}

struct OMPArraySectionExpr @0xca2808db37aea2e0 {
  expr @0:Expr;
  colonTokenFirst @1 :UInt64;
  colonTokenSecond @2 :UInt64;
  rBracketToken @3 :UInt64;
}

struct NoInitExpr @0xadedf240a5b5d3d1 {
  expr @0:Expr;
}

struct MemberExpr @0xd8c89de1fe446ed0 {
  expr @0:Expr;
  lAngleToken @1 :UInt64;
  memberDeclaration @2 :UInt64;
  memberToken @3 :UInt64;
  operatorToken @4 :UInt64;
  rAngleToken @5 :UInt64;
  templateKeywordToken @6 :UInt64;
  hadMultipleCandidates @7 :Bool;
  hasExplicitTemplateArguments @8 :Bool;
  hasQualifier @9 :Bool;
  hasTemplateKeyword @10 :Bool;
  isArrow @11 :Bool;
  isImplicitAccess @12 :Bool;
  isNonOdrUse @13 :NonOdrUseReason;
}

struct MatrixSubscriptExpr @0xc6e8f0398e560e56 {
  expr @0:Expr;
  rBracketToken @1 :UInt64;
  isIncomplete @2 :Bool;
}

struct MaterializeTemporaryExpr @0x81f0ffa9f501c48d {
  expr @0:Expr;
  extendingDeclaration @1 :UInt64;
  lifetimeExtendedTemporaryDeclaration @2 :UInt64;
  storageDuration @3 :StorageDuration;
  isBoundToLvalueReference @4 :Bool;
  isUsableInConstantExpressions @5 :Bool;
}

struct MSPropertySubscriptExpr @0xdca78c710e8a0bc9 {
  expr @0:Expr;
  rBracketToken @1 :UInt64;
}

struct MSPropertyRefExpr @0xb14da9f10b21425d {
  expr @0:Expr;
  memberToken @1 :UInt64;
  propertyDeclaration @2 :UInt64;
  isArrow @3 :Bool;
  isImplicitAccess @4 :Bool;
}

struct LambdaExpr @0xd1773aeaaf57de49 {
  expr @0:Expr;
  callOperator @1 :UInt64;
  captureDefault @2 :LambdaCaptureDefault;
  captureDefaultToken @3 :UInt64;
  compoundStatementBody @4 :UInt64;
  dependentCallOperator @5 :UInt64;
  explicitTemplateParameters @6 :List(UInt64);
  introducerRange @7 :TokenRange;
  lambdaClass @8 :UInt64;
  templateParameterList @9 :TemplateParameterList;
  hasExplicitParameters @10 :Bool;
  hasExplicitResultType @11 :Bool;
  isGenericLambda @12 :Bool;
  isMutable @13 :Bool;
}

struct IntegerLiteral @0x9555503bb691c665 {
  expr @0:Expr;
  token @1 :UInt64;
}

struct InitListExpr @0xee5bc39a46a85bfd {
  expr @0:Expr;
  initializedFieldInUnion @1 :UInt64;
  lBraceToken @2 :UInt64;
  rBraceToken @3 :UInt64;
  semanticForm @4 :UInt64;
  syntacticForm @5 :UInt64;
  hadArrayRangeDesignator @6 :Bool;
  hasArrayFiller @7 :Bool;
  isExplicit @8 :Bool;
  isSemanticForm @9 :Bool;
  isStringLiteralInitializer @10 :Bool;
  isSyntacticForm @11 :Bool;
  isTransparent @12 :Bool;
}

struct ImplicitValueInitExpr @0xa74a9776ddeaccc0 {
  expr @0:Expr;
}

struct ImaginaryLiteral @0xe6373a2b8f6af5f3 {
  expr @0:Expr;
}

struct GenericSelectionExpr @0xb9c714e9030a2703 {
  expr @0:Expr;
  defaultToken @1 :UInt64;
  genericToken @2 :UInt64;
  rParenToken @3 :UInt64;
  isResultDependent @4 :Bool;
}

struct GNUNullExpr @0xed67a32bfb3e1820 {
  expr @0:Expr;
  tokenToken @1 :UInt64;
}

struct FunctionParmPackExpr @0x9b1418ed71492c60 {
  expr @0:Expr;
  parameterPack @1 :UInt64;
  parameterPackToken @2 :UInt64;
  expansions @3 :List(UInt64);
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
  token @1 :UInt64;
  isExact @2 :Bool;
}

struct FixedPointLiteral @0xb376f274c18baf5a {
  expr @0:Expr;
  token @1 :UInt64;
}

struct ExtVectorElementExpr @0xba6c9e86786ed31a {
  expr @0:Expr;
  containsDuplicateElements @1 :Bool;
  accessorToken @2 :UInt64;
  isArrow @3 :Bool;
}

struct ExpressionTraitExpr @0xf53890283fc830c0 {
  expr @0:Expr;
  trait @1 :ExpressionTrait;
  value @2 :Bool;
}

struct AttributedStmt @0xc33cd79cc9238608 {
  valueStmt @0:ValueStmt;
  attributeToken @1 :UInt64;
}

struct SwitchStmt @0x8f2566a2d81612cd {
  stmt @0:Stmt;
  conditionVariable @1 :UInt64;
  conditionVariableDeclarationStatement @2 :UInt64;
  lParenToken @3 :UInt64;
  rParenToken @4 :UInt64;
  switchToken @5 :UInt64;
  hasInitializerStorage @6 :Bool;
  hasVariableStorage @7 :Bool;
  isAllEnumCasesCovered @8 :Bool;
}

struct SwitchCase @0xeecb8bb11e4c8ed7 {
  stmt @0:Stmt;
  colonToken @1 :UInt64;
  keywordToken @2 :UInt64;
}

struct DefaultStmt @0xf8ae119f01317845 {
  switchCase @0:SwitchCase;
  defaultToken @1 :UInt64;
}

struct CaseStmt @0x829897c890006599 {
  switchCase @0:SwitchCase;
  caseStatementIsGnuRange @1 :Bool;
  caseToken @2 :UInt64;
  ellipsisToken @3 :UInt64;
}

struct Decl @0xfb5879761ffaedb6 {
  access @0 :AccessSpecifier;
  accessUnsafe @1 :AccessSpecifier;
  availability @2 :AvailabilityResult;
  beginToken @3 :UInt64;
  bodyRBrace @4 :UInt64;
  describedTemplate @5 :UInt64;
  describedTemplateIsPresent @6 :UInt64;
  endToken @7 :UInt64;
  friendObjectKind @8 :DeclFriendObjectKind;
  moduleOwnershipKind @9 :DeclModuleOwnershipKind;
  hasAttributes @10 :Bool;
  hasDefiningAttribute @11 :Bool;
  hasOwningModule @12 :Bool;
  hasTagIdentifierNamespace @13 :Bool;
  isCanonicalDeclaration @14 :Bool;
  isDefinedOutsideFunctionOrMethod @15 :Bool;
  isDeprecated @16 :Bool;
  isFirstDeclaration @17 :Bool;
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
  token @39 :UInt64;
  tokenRange @40 :TokenRange;
}

struct ClassScopeFunctionSpecializationDecl @0x99eb38d6a1065986 {
  decl @0:Decl;
  specialization @1 :UInt64;
  hasExplicitTemplateArguments @2 :Bool;
}

struct CapturedDecl @0xa1c847e4871d0b0a {
  decl @0:Decl;
  contextParameter @1 :UInt64;
  isNothrow @2 :Bool;
  parameters @3 :List(UInt64);
  declarationsInContext @4 :List(UInt64);
}

struct BlockDecl @0xd21c906a9e197a51 {
  decl @0:Decl;
  blockMissingReturnType @1 :Bool;
  canAvoidCopyToHeap @2 :Bool;
  capturesCxxThis @3 :Bool;
  doesNotEscape @4 :Bool;
  caretToken @5 :UInt64;
  compoundBody @6 :UInt64;
  hasCaptures @7 :Bool;
  isConversionFromLambda @8 :Bool;
  isVariadic @9 :Bool;
  parameters @10 :List(UInt64);
  parameterDeclarations @11 :List(UInt64);
  declarationsInContext @12 :List(UInt64);
}

struct AccessSpecDecl @0xe671324616f83d3c {
  decl @0:Decl;
  accessSpecifierToken @1 :UInt64;
  colonToken @2 :UInt64;
}

struct OMPDeclarativeDirectiveDecl @0xfdc732b6f8da601e {
  decl @0:Decl;
}

struct OMPThreadPrivateDecl @0xa91fd10d3da452b5 {
  ompDeclarativeDirectiveDecl @0:OMPDeclarativeDirectiveDecl;
}

struct OMPRequiresDecl @0xd5d3ec3fbc91423c {
  ompDeclarativeDirectiveDecl @0:OMPDeclarativeDirectiveDecl;
}

struct OMPAllocateDecl @0xe7eb4cee19c86540 {
  ompDeclarativeDirectiveDecl @0:OMPDeclarativeDirectiveDecl;
}

struct TranslationUnitDecl @0x84ba694d5be7caa3 {
  decl @0:Decl;
  anonymousNamespace @1 :UInt64;
  declarationsInContext @2 :List(UInt64);
}

struct StaticAssertDecl @0xe3ab98945466226a {
  decl @0:Decl;
  message @1 :UInt64;
  rParenToken @2 :UInt64;
  isFailed @3 :Bool;
}

struct RequiresExprBodyDecl @0x9eea1ed94972a3a6 {
  decl @0:Decl;
  declarationsInContext @1 :List(UInt64);
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
  getterMethodDeclaration @1 :UInt64;
  propertyDeclaration @2 :UInt64;
  propertyImplementation @3 :ObjCPropertyImplDeclKind;
  propertyInstanceVariableDeclaration @4 :UInt64;
  propertyInstanceVariableDeclarationToken @5 :UInt64;
  setterMethodDeclaration @6 :UInt64;
  isInstanceVariableNameSpecified @7 :Bool;
}

struct NamedDecl @0xee8ff2639c85feae {
  decl @0:Decl;
  formalLinkage @1 :Linkage;
  linkageInternal @2 :Linkage;
  name @3 :Text;
  objCfStringFormattingFamily @4 :ObjCStringFormatFamily;
  qualifiedNameAsString @5 :Text;
  underlyingDeclaration @6 :UInt64;
  visibility @7 :Visibility;
  hasExternalFormalLinkage @8 :Bool;
  hasLinkage @9 :Bool;
  hasLinkageBeenComputed @10 :Bool;
  isCxxClassMember @11 :Bool;
  isCxxInstanceMember @12 :Bool;
  isExternallyDeclarable @13 :Bool;
  isExternallyVisible @14 :Bool;
  isLinkageValid @15 :Bool;
}

struct LabelDecl @0x959116a0b50f04fe {
  namedDecl @0:NamedDecl;
  msAssemblyLabel @1 :Text;
  statement @2 :UInt64;
  isGnuLocal @3 :Bool;
  isMsAssemblyLabel @4 :Bool;
  isResolvedMsAssemblyLabel @5 :Bool;
}

struct BaseUsingDecl @0xd779d676819e5d07 {
  namedDecl @0:NamedDecl;
  shadows @1 :List(UInt64);
}

struct UsingEnumDecl @0xa824f691f72f9236 {
  baseUsingDecl @0:BaseUsingDecl;
  enumDeclaration @1 :UInt64;
  enumToken @2 :UInt64;
  usingToken @3 :UInt64;
}

struct UsingDecl @0xb8602dcb3f95c179 {
  baseUsingDecl @0:BaseUsingDecl;
  usingToken @1 :UInt64;
  hasTypename @2 :Bool;
  isAccessDeclaration @3 :Bool;
}

struct ValueDecl @0xe2704a366b05e616 {
  namedDecl @0:NamedDecl;
  isWeak @1 :Bool;
}

struct UnresolvedUsingValueDecl @0x8ad2fc298aa43ab1 {
  valueDecl @0:ValueDecl;
  ellipsisToken @1 :UInt64;
  usingToken @2 :UInt64;
  isAccessDeclaration @3 :Bool;
  isPackExpansion @4 :Bool;
}

struct TemplateParamObjectDecl @0xd09f17939d7cc847 {
  valueDecl @0:ValueDecl;
}

struct OMPDeclareReductionDecl @0xf59daefbeeafc092 {
  valueDecl @0:ValueDecl;
  initializerKind @1 :OMPDeclareReductionDeclInitKind;
  prevDeclarationInScope @2 :UInt64;
  declarationsInContext @3 :List(UInt64);
}

struct MSGuidDecl @0x9ef09ebc4be76711 {
  valueDecl @0:ValueDecl;
}

struct IndirectFieldDecl @0xf8f906fde6cb040f {
  valueDecl @0:ValueDecl;
  chain @1 :List(UInt64);
  anonymousField @2 :UInt64;
  variableDeclaration @3 :UInt64;
}

struct EnumConstantDecl @0xe2b34f222cdb8877 {
  valueDecl @0:ValueDecl;
}

struct DeclaratorDecl @0xb95593a177af5810 {
  valueDecl @0:ValueDecl;
  innerTokenStart @1 :UInt64;
  outerTokenStart @2 :UInt64;
  typeSpecEndToken @3 :UInt64;
  typeSpecStartToken @4 :UInt64;
  templateParameterLists @5 :List(TemplateParameterList);
}

struct VarDecl @0xcf9adcbc59a4e339 {
  declaratorDecl @0:DeclaratorDecl;
  actingDefinition @1 :UInt64;
  actingDefinitionIsPresent @2 :UInt64;
  describedVariableTemplate @3 :UInt64;
  describedVariableTemplateIsPresent @4 :UInt64;
  initializerStyle @5 :VarDeclInitializationStyle;
  initializingDeclaration @6 :UInt64;
  initializingDeclarationIsPresent @7 :UInt64;
  instantiatedFromStaticDataMember @8 :UInt64;
  instantiatedFromStaticDataMemberIsPresent @9 :UInt64;
  languageLinkage @10 :LanguageLinkage;
  pointOfInstantiation @11 :UInt64;
  storageClass @12 :StorageClass;
  storageDuration @13 :StorageDuration;
  tlsKind @14 :VarDeclTLSKind;
  tscSpec @15 :ThreadStorageClassSpecifier;
  templateInstantiationPattern @16 :UInt64;
  templateInstantiationPatternIsPresent @17 :UInt64;
  templateSpecializationKind @18 :TemplateSpecializationKind;
  templateSpecializationKindForInstantiation @19 :TemplateSpecializationKind;
  hasConstantInitialization @20 :Bool;
  hasDependentAlignment @21 :Bool;
  hasExternalStorage @22 :Bool;
  hasGlobalStorage @23 :Bool;
  hasInitializer @24 :Bool;
  hasLocalStorage @25 :Bool;
  isArcPseudoStrong @26 :Bool;
  isCxxForRangeDeclaration @27 :Bool;
  isConstexpr @28 :Bool;
  isDirectInitializer @29 :Bool;
  isEscapingByref @30 :Bool;
  isExceptionVariable @31 :Bool;
  isExternUcC @32 :Bool;
  isFileVariableDeclaration @33 :Bool;
  isFunctionOrMethodVariableDeclaration @34 :Bool;
  isInExternCContext @35 :Bool;
  isInExternCxxContext @36 :Bool;
  isInitializerCapture @37 :Bool;
  isInline @38 :Bool;
  isInlineSpecified @39 :Bool;
  isKnownToBeDefined @40 :Bool;
  isLocalVariableDeclaration @41 :Bool;
  isLocalVariableDeclarationOrParm @42 :Bool;
  isNrvoVariable @43 :Bool;
  isNoDestroy @44 :Bool;
  isNonEscapingByref @45 :Bool;
  isObjCForDeclaration @46 :Bool;
  isPreviousDeclarationInSameBlockScope @47 :Bool;
  isStaticDataMember @48 :Bool;
  isStaticLocal @49 :Bool;
  isThisDeclarationADemotedDefinition @50 :Bool;
  isUsableInConstantExpressions @51 :Bool;
  mightBeUsableInConstantExpressions @52 :Bool;
  needsDestruction @53 :QualTypeDestructionKind;
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
  bindings @1 :List(UInt64);
}

struct VarTemplateSpecializationDecl @0xbaf3e3ed90ea85e0 {
  varDecl @0:VarDecl;
  externToken @1 :UInt64;
  specializationKind @2 :TemplateSpecializationKind;
  specializedTemplate @3 :UInt64;
  templateArguments @4 :List(TemplateArgument);
  templateInstantiationArguments @5 :List(TemplateArgument);
  templateKeywordToken @6 :UInt64;
  isClassScopeExplicitSpecialization @7 :Bool;
  isExplicitInstantiationOrSpecialization @8 :Bool;
  isExplicitSpecialization @9 :Bool;
}

struct VarTemplatePartialSpecializationDecl @0xe1d0f96cb9fa250f {
  varTemplateSpecializationDecl @0:VarTemplateSpecializationDecl;
  instantiatedFromMember @1 :UInt64;
  templateParameters @2 :TemplateParameterList;
  hasAssociatedConstraints @3 :Bool;
}

struct NonTypeTemplateParmDecl @0x964d2872d52f2d65 {
  declaratorDecl @0:DeclaratorDecl;
  defaultArgumentWasInherited @1 :Bool;
  defaultArgumentToken @2 :UInt64;
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
  doesThisDeclarationHaveABody @1 :Bool;
  constexprKind @2 :ConstexprSpecKind;
  definition @3 :UInt64;
  describedFunctionTemplate @4 :UInt64;
  describedFunctionTemplateIsPresent @5 :UInt64;
  ellipsisToken @6 :UInt64;
  exceptionSpecSourceRange @7 :TokenRange;
  exceptionSpecType @8 :ExceptionSpecificationType;
  instantiatedFromMemberFunction @9 :UInt64;
  instantiatedFromMemberFunctionIsPresent @10 :UInt64;
  languageLinkage @11 :LanguageLinkage;
  multiVersionKind @12 :MultiVersionKind;
  overloadedOperator @13 :OverloadedOperatorKind;
  parametersSourceRange @14 :TokenRange;
  pointOfInstantiation @15 :UInt64;
  primaryTemplate @16 :UInt64;
  primaryTemplateIsPresent @17 :UInt64;
  returnTypeSourceRange @18 :TokenRange;
  storageClass @19 :StorageClass;
  templateInstantiationPattern @20 :UInt64;
  templateInstantiationPatternIsPresent @21 :UInt64;
  templateSpecializationKind @22 :TemplateSpecializationKind;
  templateSpecializationKindForInstantiation @23 :TemplateSpecializationKind;
  templatedKind @24 :FunctionDeclTemplatedKind;
  hasImplicitReturnZero @25 :Bool;
  hasInheritedPrototype @26 :Bool;
  hasOneParameterOrDefaultArguments @27 :Bool;
  hasPrototype @28 :Bool;
  hasSkippedBody @29 :Bool;
  hasTrivialBody @30 :Bool;
  hasWrittenPrototype @31 :Bool;
  instantiationIsPending @32 :Bool;
  isCpuDispatchMultiVersion @33 :Bool;
  isCpuSpecificMultiVersion @34 :Bool;
  isConsteval @35 :Bool;
  isConstexpr @36 :Bool;
  isConstexprSpecified @37 :Bool;
  isDefaulted @38 :Bool;
  isDeleted @39 :Bool;
  isDeletedAsWritten @40 :Bool;
  isDestroyingOperatorDelete @41 :Bool;
  isExplicitlyDefaulted @42 :Bool;
  isExternUcC @43 :Bool;
  isFunctionTemplateSpecialization @44 :Bool;
  isGlobal @45 :Bool;
  isImplicitlyInstantiable @46 :Bool;
  isInExternCContext @47 :Bool;
  isInExternCxxContext @48 :Bool;
  isInlineBuiltinDeclaration @49 :Bool;
  isInlineSpecified @50 :Bool;
  isInlined @51 :Bool;
  isLateTemplateParsed @52 :Bool;
  isMsvcrtEntryPoint @53 :Bool;
  isMain @54 :Bool;
  isMultiVersion @55 :Bool;
  isNoReturn @56 :Bool;
  isOverloadedOperator @57 :Bool;
  isPure @58 :Bool;
  isReplaceableGlobalAllocationFunction @59 :Bool;
  isStatic @60 :Bool;
  isTargetMultiVersion @61 :Bool;
  isTemplateInstantiation @62 :Bool;
  isThisDeclarationADefinition @63 :Bool;
  isThisDeclarationInstantiatedFromAFriendDefinition @64 :Bool;
  isTrivial @65 :Bool;
  isTrivialForCall @66 :Bool;
  isUserProvided @67 :Bool;
  isVariadic @68 :Bool;
  isVirtualAsWritten @69 :Bool;
  parameters @70 :List(UInt64);
  usesSehTry @71 :Bool;
  willHaveBody @72 :Bool;
  parameterDeclarations @73 :List(UInt64);
  declarationsInContext @74 :List(UInt64);
}

struct CXXMethodDecl @0xd83d5835cf6512db {
  functionDecl @0:FunctionDecl;
  parent @1 :UInt64;
  referenceQualifier @2 :RefQualifierKind;
  hasInlineBody @3 :Bool;
  isConst @4 :Bool;
  isCopyAssignmentOperator @5 :Bool;
  isInstance @6 :Bool;
  isLambdaStaticInvoker @7 :Bool;
  isMoveAssignmentOperator @8 :Bool;
  isVirtual @9 :Bool;
  isVolatile @10 :Bool;
  overriddenMethods @11 :List(UInt64);
}

struct CXXDestructorDecl @0xee0fd0438430a21c {
  cxxMethodDecl @0:CXXMethodDecl;
  operatorDelete @1 :UInt64;
}

struct CXXConversionDecl @0xac531836739115b2 {
  cxxMethodDecl @0:CXXMethodDecl;
  isExplicit @1 :Bool;
  isLambdaToBlockPointerConversion @2 :Bool;
}

struct CXXConstructorDecl @0xc6bfa2c4650464b8 {
  cxxMethodDecl @0:CXXMethodDecl;
  targetConstructor @1 :UInt64;
  isDefaultConstructor @2 :Bool;
  isDelegatingConstructor @3 :Bool;
  isExplicit @4 :Bool;
  isInheritingConstructor @5 :Bool;
  isSpecializationCopyingObject @6 :Bool;
}

struct CXXDeductionGuideDecl @0xca6c78b5c1634d9d {
  functionDecl @0:FunctionDecl;
  correspondingConstructor @1 :UInt64;
  deducedTemplate @2 :UInt64;
  isCopyDeductionCandidate @3 :Bool;
  isExplicit @4 :Bool;
}

struct FieldDecl @0xec8d79b82b91a5eb {
  declaratorDecl @0:DeclaratorDecl;
  inClassInitializerStyle @1 :InClassInitStyle;
  parent @2 :UInt64;
  hasCapturedVlaType @3 :Bool;
  hasInClassInitializer @4 :Bool;
  isAnonymousStructOrUnion @5 :Bool;
  isBitField @6 :Bool;
  isMutable @7 :Bool;
  isUnnamedBitfield @8 :Bool;
  isZeroLengthBitField @9 :Bool;
  isZeroSize @10 :Bool;
}

struct ObjCIvarDecl @0xfd0f42a085839510 {
  fieldDecl @0:FieldDecl;
  accessControl @1 :ObjCIvarDeclAccessControl;
  canonicalAccessControl @2 :ObjCIvarDeclAccessControl;
  containingInterface @3 :UInt64;
  nextInstanceVariable @4 :UInt64;
  synthesize @5 :Bool;
}

struct ObjCAtDefsFieldDecl @0xd8b002eb70c258c6 {
  fieldDecl @0:FieldDecl;
}

struct BindingDecl @0xe77651068f3e1703 {
  valueDecl @0:ValueDecl;
  decomposedDeclaration @1 :UInt64;
  holdingVariable @2 :UInt64;
}

struct OMPDeclarativeDirectiveValueDecl @0xc2c7acb8e7dbee6f {
  valueDecl @0:ValueDecl;
}

struct OMPDeclareMapperDecl @0xa1fda623202f7e38 {
  ompDeclarativeDirectiveValueDecl @0:OMPDeclarativeDirectiveValueDecl;
  prevDeclarationInScope @1 :UInt64;
  declarationsInContext @2 :List(UInt64);
}

struct UsingShadowDecl @0xef25bc2e71e7534e {
  namedDecl @0:NamedDecl;
  introducer @1 :UInt64;
  nextUsingShadowDeclaration @2 :UInt64;
  targetDeclaration @3 :UInt64;
}

struct ConstructorUsingShadowDecl @0x8a43df80c48b7033 {
  usingShadowDecl @0:UsingShadowDecl;
  constructsVirtualBase @1 :Bool;
  constructedBaseClass @2 :UInt64;
  constructedBaseClassShadowDeclaration @3 :UInt64;
  constructedBaseClassShadowDeclarationIsPresent @4 :UInt64;
  nominatedBaseClass @5 :UInt64;
  nominatedBaseClassShadowDeclaration @6 :UInt64;
  nominatedBaseClassShadowDeclarationIsPresent @7 :UInt64;
  parent @8 :UInt64;
}

struct UsingPackDecl @0xf68edcc97d568bee {
  namedDecl @0:NamedDecl;
  expansions @1 :List(UInt64);
  instantiatedFromUsingDeclaration @2 :UInt64;
}

struct UsingDirectiveDecl @0xf383b9039044d6f8 {
  namedDecl @0:NamedDecl;
  identifierToken @1 :UInt64;
  namespaceKeyToken @2 :UInt64;
  nominatedNamespace @3 :UInt64;
  nominatedNamespaceAsWritten @4 :UInt64;
  usingToken @5 :UInt64;
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
  defaultArgumentToken @2 :UInt64;
  hasDefaultArgument @3 :Bool;
  hasTypeConstraint @4 :Bool;
  isExpandedParameterPack @5 :Bool;
  isPackExpansion @6 :Bool;
  wasDeclaredWithTypename @7 :Bool;
}

struct TagDecl @0x8e30dcc81a0377d1 {
  typeDecl @0:TypeDecl;
  braceRange @1 :TokenRange;
  definition @2 :UInt64;
  definitionIsPresent @3 :UInt64;
  innerTokenStart @4 :UInt64;
  outerTokenStart @5 :UInt64;
  tagKind @6 :TagTypeKind;
  typedefNameForAnonymousDeclaration @7 :UInt64;
  hasNameForLinkage @8 :Bool;
  isBeingDefined @9 :Bool;
  isClass @10 :Bool;
  isCompleteDefinition @11 :Bool;
  isCompleteDefinitionRequired @12 :Bool;
  isDependentType @13 :Bool;
  isEmbeddedInDeclarator @14 :Bool;
  isEnum @15 :Bool;
  isFreeStanding @16 :Bool;
  isInterface @17 :Bool;
  isStruct @18 :Bool;
  isThisDeclarationADefinition @19 :Bool;
  isUnion @20 :Bool;
  mayHaveOutOfDateDefinition @21 :Bool;
  templateParameterLists @22 :List(TemplateParameterList);
  declarationsInContext @23 :List(UInt64);
}

struct RecordDecl @0xae6dc96296678f51 {
  tagDecl @0:TagDecl;
  canPassInRegisters @1 :Bool;
  fields @2 :List(UInt64);
  findFirstNamedDataMember @3 :UInt64;
  findFirstNamedDataMemberIsPresent @4 :UInt64;
  argumentPassingRestrictions @5 :RecordDeclArgPassingKind;
  hasFlexibleArrayMember @6 :Bool;
  hasLoadedFieldsFromExternalStorage @7 :Bool;
  hasNonTrivialToPrimitiveCopyCUnion @8 :Bool;
  hasNonTrivialToPrimitiveDefaultInitializeCUnion @9 :Bool;
  hasNonTrivialToPrimitiveDestructCUnion @10 :Bool;
  hasObjectMember @11 :Bool;
  hasVolatileMember @12 :Bool;
  isAnonymousStructOrUnion @13 :Bool;
  isCapturedRecord @14 :Bool;
  isInjectedClassName @15 :Bool;
  isLambda @16 :Bool;
  isMsStruct @17 :Bool;
  isNonTrivialToPrimitiveCopy @18 :Bool;
  isNonTrivialToPrimitiveDefaultInitialize @19 :Bool;
  isNonTrivialToPrimitiveDestroy @20 :Bool;
  isOrContainsUnion @21 :Bool;
  isParameterDestroyedInCallee @22 :Bool;
  mayInsertExtraPadding @23 :Bool;
}

struct CXXRecordDecl @0x9ecc9c9b6a1f56fc {
  recordDecl @0:RecordDecl;
  allowConstDefaultInitializer @1 :Bool;
  bases @2 :List(CXXBaseSpecifier);
  calculateInheritanceModel @3 :MSInheritanceModel;
  constructors @4 :List(UInt64);
  defaultedCopyConstructorIsDeleted @5 :Bool;
  defaultedDefaultConstructorIsConstexpr @6 :Bool;
  defaultedDestructorIsConstexpr @7 :Bool;
  defaultedDestructorIsDeleted @8 :Bool;
  defaultedMoveConstructorIsDeleted @9 :Bool;
  friends @10 :List(UInt64);
  dependentLambdaCallOperator @11 :UInt64;
  describedClassTemplate @12 :UInt64;
  destructor @13 :UInt64;
  genericLambdaTemplateParameterList @14 :TemplateParameterList;
  instantiatedFromMemberClass @15 :UInt64;
  lambdaCallOperator @16 :UInt64;
  lambdaCaptureDefault @17 :LambdaCaptureDefault;
  lambdaExplicitTemplateParameters @18 :List(UInt64);
  msInheritanceModel @19 :MSInheritanceModel;
  msVtorDispMode @20 :MSVtorDispMode;
  mostRecentNonInjectedDeclaration @21 :UInt64;
  templateInstantiationPattern @22 :UInt64;
  templateSpecializationKind @23 :TemplateSpecializationKind;
  hasAnyDependentBases @24 :Bool;
  hasConstexprDefaultConstructor @25 :Bool;
  hasConstexprDestructor @26 :Bool;
  hasConstexprNonCopyMoveConstructor @27 :Bool;
  hasCopyAssignmentWithConstParameter @28 :Bool;
  hasCopyConstructorWithConstParameter @29 :Bool;
  hasDefaultConstructor @30 :Bool;
  hasDefinition @31 :Bool;
  hasDirectFields @32 :Bool;
  hasFriends @33 :Bool;
  hasInClassInitializer @34 :Bool;
  hasInheritedAssignment @35 :Bool;
  hasInheritedConstructor @36 :Bool;
  hasIrrelevantDestructor @37 :Bool;
  hasKnownLambdaInternalLinkage @38 :Bool;
  hasMoveAssignment @39 :Bool;
  hasMoveConstructor @40 :Bool;
  hasMutableFields @41 :Bool;
  hasNonLiteralTypeFieldsOrBases @42 :Bool;
  hasNonTrivialCopyAssignment @43 :Bool;
  hasNonTrivialCopyConstructor @44 :Bool;
  hasNonTrivialCopyConstructorForCall @45 :Bool;
  hasNonTrivialDefaultConstructor @46 :Bool;
  hasNonTrivialDestructor @47 :Bool;
  hasNonTrivialDestructorForCall @48 :Bool;
  hasNonTrivialMoveAssignment @49 :Bool;
  hasNonTrivialMoveConstructor @50 :Bool;
  hasNonTrivialMoveConstructorForCall @51 :Bool;
  hasPrivateFields @52 :Bool;
  hasProtectedFields @53 :Bool;
  hasSimpleCopyAssignment @54 :Bool;
  hasSimpleCopyConstructor @55 :Bool;
  hasSimpleDestructor @56 :Bool;
  hasSimpleMoveAssignment @57 :Bool;
  hasSimpleMoveConstructor @58 :Bool;
  hasTrivialCopyAssignment @59 :Bool;
  hasTrivialCopyConstructor @60 :Bool;
  hasTrivialCopyConstructorForCall @61 :Bool;
  hasTrivialDefaultConstructor @62 :Bool;
  hasTrivialDestructor @63 :Bool;
  hasTrivialDestructorForCall @64 :Bool;
  hasTrivialMoveAssignment @65 :Bool;
  hasTrivialMoveConstructor @66 :Bool;
  hasTrivialMoveConstructorForCall @67 :Bool;
  hasUninitializedReferenceMember @68 :Bool;
  hasUserDeclaredConstructor @69 :Bool;
  hasUserDeclaredCopyAssignment @70 :Bool;
  hasUserDeclaredCopyConstructor @71 :Bool;
  hasUserDeclaredDestructor @72 :Bool;
  hasUserDeclaredMoveAssignment @73 :Bool;
  hasUserDeclaredMoveConstructor @74 :Bool;
  hasUserDeclaredMoveOperation @75 :Bool;
  hasUserProvidedDefaultConstructor @76 :Bool;
  hasVariantMembers @77 :Bool;
  implicitCopyAssignmentHasConstParameter @78 :Bool;
  implicitCopyConstructorHasConstParameter @79 :Bool;
  isAbstract @80 :Bool;
  isAggregate @81 :Bool;
  isAnyDestructorNoReturn @82 :Bool;
  isCLike @83 :Bool;
  isCxx11StandardLayout @84 :Bool;
  isDependentLambda @85 :Bool;
  isDynamicClass @86 :Bool;
  isEffectivelyFinal @87 :Bool;
  isEmpty @88 :Bool;
  isGenericLambda @89 :Bool;
  isInterfaceLike @90 :Bool;
  isLiteral @91 :Bool;
  isLocalClass @92 :UInt64;
  isPod @93 :Bool;
  isParsingBaseSpecifiers @94 :Bool;
  isPolymorphic @95 :Bool;
  isStandardLayout @96 :Bool;
  isStructural @97 :Bool;
  isTrivial @98 :Bool;
  isTriviallyCopyable @99 :Bool;
  lambdaIsDefaultConstructibleAndAssignable @100 :Bool;
  mayBeAbstract @101 :Bool;
  mayBeDynamicClass @102 :Bool;
  mayBeNonDynamicClass @103 :Bool;
  methods @104 :List(UInt64);
  needsImplicitCopyAssignment @105 :Bool;
  needsImplicitCopyConstructor @106 :Bool;
  needsImplicitDefaultConstructor @107 :Bool;
  needsImplicitDestructor @108 :Bool;
  needsImplicitMoveAssignment @109 :Bool;
  needsImplicitMoveConstructor @110 :Bool;
  needsOverloadResolutionForCopyAssignment @111 :Bool;
  needsOverloadResolutionForCopyConstructor @112 :Bool;
  needsOverloadResolutionForDestructor @113 :Bool;
  needsOverloadResolutionForMoveAssignment @114 :Bool;
  needsOverloadResolutionForMoveConstructor @115 :Bool;
  nullFieldOffsetIsZero @116 :Bool;
  virtualBases @117 :List(CXXBaseSpecifier);
}

struct ClassTemplateSpecializationDecl @0xa81be8b0845933da {
  cxxRecordDecl @0:CXXRecordDecl;
  externToken @1 :UInt64;
  pointOfInstantiation @2 :UInt64;
  specializationKind @3 :TemplateSpecializationKind;
  specializedTemplate @4 :UInt64;
  templateArguments @5 :List(TemplateArgument);
  templateInstantiationArguments @6 :List(TemplateArgument);
  templateKeywordToken @7 :UInt64;
  isClassScopeExplicitSpecialization @8 :Bool;
  isExplicitInstantiationOrSpecialization @9 :Bool;
  isExplicitSpecialization @10 :Bool;
}

struct ClassTemplatePartialSpecializationDecl @0x9492104c4b2eff2e {
  classTemplateSpecializationDecl @0:ClassTemplateSpecializationDecl;
  instantiatedFromMember @1 :UInt64;
  instantiatedFromMemberTemplate @2 :UInt64;
  templateParameters @3 :TemplateParameterList;
  hasAssociatedConstraints @4 :Bool;
}

struct EnumDecl @0x93540bfa73a13c84 {
  tagDecl @0:TagDecl;
  enumerators @1 :List(UInt64);
  instantiatedFromMemberEnum @2 :UInt64;
  instantiatedFromMemberEnumIsPresent @3 :UInt64;
  integerTypeRange @4 :TokenRange;
  templateInstantiationPattern @5 :UInt64;
  templateInstantiationPatternIsPresent @6 :UInt64;
  templateSpecializationKind @7 :TemplateSpecializationKind;
  isClosed @8 :Bool;
  isClosedFlag @9 :Bool;
  isClosedNonFlag @10 :Bool;
  isComplete @11 :Bool;
  isFixed @12 :Bool;
  isScoped @13 :Bool;
  isScopedUsingClassTag @14 :Bool;
}

struct UnresolvedUsingTypenameDecl @0x8b74c3415940bb24 {
  typeDecl @0:TypeDecl;
  ellipsisToken @1 :UInt64;
  typenameToken @2 :UInt64;
  usingToken @3 :UInt64;
  isPackExpansion @4 :Bool;
}

struct TypedefNameDecl @0xe8f3a8fa9f84b388 {
  typeDecl @0:TypeDecl;
  anonymousDeclarationWithTypedefName @1 :UInt64;
  anonymousDeclarationWithTypedefNameIsPresent @2 :UInt64;
  isModed @3 :Bool;
  isTransparentTag @4 :Bool;
}

struct TypedefDecl @0xcabfd592ecdf73ec {
  typedefNameDecl @0:TypedefNameDecl;
}

struct TypeAliasDecl @0x98b3c141fd82bbdd {
  typedefNameDecl @0:TypedefNameDecl;
  describedAliasTemplate @1 :UInt64;
  describedAliasTemplateIsPresent @2 :UInt64;
}

struct ObjCTypeParamDecl @0xfea48cce2b1c50cd {
  typedefNameDecl @0:TypedefNameDecl;
  colonToken @1 :UInt64;
  variance @2 :ObjCTypeParamVariance;
  varianceToken @3 :UInt64;
  hasExplicitBound @4 :Bool;
}

struct TemplateDecl @0x8794861cbdf44fcd {
  namedDecl @0:NamedDecl;
  templateParameters @1 :TemplateParameterList;
  templatedDeclaration @2 :UInt64;
  hasAssociatedConstraints @3 :Bool;
}

struct RedeclarableTemplateDecl @0xeae96325d22b861f {
  templateDecl @0:TemplateDecl;
  instantiatedFromMemberTemplate @1 :UInt64;
  isMemberSpecialization @2 :Bool;
}

struct FunctionTemplateDecl @0xc88144c3067080ac {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
  isAbbreviated @1 :Bool;
  isThisDeclarationADefinition @2 :Bool;
  specializations @3 :List(UInt64);
}

struct ClassTemplateDecl @0xd77c8a2532fd776e {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
  isThisDeclarationADefinition @1 :Bool;
  specializations @2 :List(UInt64);
}

struct VarTemplateDecl @0x983bd212ec53c1f3 {
  redeclarableTemplateDecl @0:RedeclarableTemplateDecl;
  isThisDeclarationADefinition @1 :Bool;
  specializations @2 :List(UInt64);
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
  defaultArgumentToken @2 :UInt64;
  hasDefaultArgument @3 :Bool;
  isExpandedParameterPack @4 :Bool;
  isPackExpansion @5 :Bool;
}

struct ObjCPropertyDecl @0x9eb7f76b62290548 {
  namedDecl @0:NamedDecl;
  atToken @1 :UInt64;
  getterMethodDeclaration @2 :UInt64;
  getterNameToken @3 :UInt64;
  lParenToken @4 :UInt64;
  propertyImplementation @5 :ObjCPropertyDeclPropertyControl;
  propertyInstanceVariableDeclaration @6 :UInt64;
  queryKind @7 :ObjCPropertyQueryKind;
  setterKind @8 :ObjCPropertyDeclSetterKind;
  setterMethodDeclaration @9 :UInt64;
  setterNameToken @10 :UInt64;
  isAtomic @11 :Bool;
  isClassProperty @12 :Bool;
  isDirectProperty @13 :Bool;
  isInstanceProperty @14 :Bool;
  isOptional @15 :Bool;
  isReadOnly @16 :Bool;
  isRetaining @17 :Bool;
}

struct ObjCMethodDecl @0xf8c8c7d3c113456e {
  namedDecl @0:NamedDecl;
  definedInNsObject @1 :Bool;
  findPropertyDeclaration @2 :UInt64;
  category @3 :UInt64;
  classInterface @4 :UInt64;
  cmdDeclaration @5 :UInt64;
  declaratorEndToken @6 :UInt64;
  implementationControl @7 :ObjCMethodDeclImplementationControl;
  methodFamily @8 :ObjCMethodFamily;
  objCDeclQualifier @9 :DeclObjCDeclQualifier;
  returnTypeSourceRange @10 :TokenRange;
  selectorStartToken @11 :UInt64;
  selfDeclaration @12 :UInt64;
  hasRedeclaration @13 :Bool;
  hasRelatedResultType @14 :Bool;
  hasSkippedBody @15 :Bool;
  isClassMethod @16 :Bool;
  isDefined @17 :Bool;
  isDesignatedInitializerForTheInterface @18 :Bool;
  isDirectMethod @19 :Bool;
  isInstanceMethod @20 :Bool;
  isOptional @21 :Bool;
  isOverriding @22 :Bool;
  isPropertyAccessor @23 :Bool;
  isRedeclaration @24 :Bool;
  isSynthesizedAccessorStub @25 :Bool;
  isThisDeclarationADefinition @26 :Bool;
  isThisDeclarationADesignatedInitializer @27 :Bool;
  isVariadic @28 :Bool;
  parameters @29 :List(UInt64);
  selectorTokens @30 :List(UInt64);
  declarationsInContext @31 :List(UInt64);
}

struct ObjCContainerDecl @0xaf9db5ae0b65ce9e {
  namedDecl @0:NamedDecl;
  classMethods @1 :List(UInt64);
  classProperties @2 :List(UInt64);
  atEndRange @3 :TokenRange;
  atStartToken @4 :UInt64;
  instanceMethods @5 :List(UInt64);
  instanceProperties @6 :List(UInt64);
  methods @7 :List(UInt64);
  properties @8 :List(UInt64);
  declarationsInContext @9 :List(UInt64);
}

struct ObjCCategoryDecl @0xb673566cbe41a76d {
  objCContainerDecl @0:ObjCContainerDecl;
  isClassExtension @1 :Bool;
  categoryNameToken @2 :UInt64;
  classInterface @3 :UInt64;
  implementation @4 :UInt64;
  instanceVariableLBraceToken @5 :UInt64;
  instanceVariableRBraceToken @6 :UInt64;
  nextClassCategory @7 :UInt64;
  nextClassCategoryRaw @8 :UInt64;
  instanceVariables @9 :List(UInt64);
  protocolTokens @10 :List(UInt64);
  protocols @11 :List(UInt64);
}

struct ObjCProtocolDecl @0xa8d0b0128e3a36e1 {
  objCContainerDecl @0:ObjCContainerDecl;
  definition @1 :UInt64;
  objCRuntimeNameAsString @2 :Text;
  hasDefinition @3 :Bool;
  isNonRuntimeProtocol @4 :Bool;
  isThisDeclarationADefinition @5 :Bool;
  protocolTokens @6 :List(UInt64);
  protocols @7 :List(UInt64);
}

struct ObjCInterfaceDecl @0x851a7195d7b1d15e {
  objCContainerDecl @0:ObjCContainerDecl;
  allReferencedProtocols @1 :List(UInt64);
  declaresOrInheritsDesignatedInitializers @2 :Bool;
  categoryListRaw @3 :UInt64;
  definition @4 :UInt64;
  endOfDefinitionToken @5 :UInt64;
  implementation @6 :UInt64;
  objCRuntimeNameAsString @7 :Text;
  superClass @8 :UInt64;
  superClassToken @9 :UInt64;
  hasDefinition @10 :Bool;
  hasDesignatedInitializers @11 :Bool;
  isArcWeakrefUnavailable @12 :Bool;
  isImplicitInterfaceDeclaration @13 :Bool;
  isObjCRequiresPropertyDefinitions @14 :UInt64;
  isThisDeclarationADefinition @15 :Bool;
  instanceVariables @16 :List(UInt64);
  knownCategories @17 :List(UInt64);
  knownExtensions @18 :List(UInt64);
  protocolTokens @19 :List(UInt64);
  protocols @20 :List(UInt64);
  visibleCategories @21 :List(UInt64);
  visibleExtensions @22 :List(UInt64);
}

struct ObjCImplDecl @0xfbf2d2598582b4f4 {
  objCContainerDecl @0:ObjCContainerDecl;
  classInterface @1 :UInt64;
  propertyImplementations @2 :List(UInt64);
}

struct ObjCCategoryImplDecl @0xb972fe178fc59d16 {
  objCImplDecl @0:ObjCImplDecl;
  categoryDeclaration @1 :UInt64;
  categoryNameToken @2 :UInt64;
}

struct ObjCImplementationDecl @0xf2e56fe062561acd {
  objCImplDecl @0:ObjCImplDecl;
  instanceVariableLBraceToken @1 :UInt64;
  instanceVariableRBraceToken @2 :UInt64;
  objCRuntimeNameAsString @3 :Text;
  superClass @4 :UInt64;
  superClassToken @5 :UInt64;
  hasDestructors @6 :Bool;
  hasNonZeroConstructors @7 :Bool;
  instanceVariables @8 :List(UInt64);
}

struct ObjCCompatibleAliasDecl @0xc484be73cf6be95b {
  namedDecl @0:NamedDecl;
  classInterface @1 :UInt64;
}

struct NamespaceDecl @0xd4713edcad196585 {
  namedDecl @0:NamedDecl;
  anonymousNamespace @1 :UInt64;
  originalNamespace @2 :UInt64;
  rBraceToken @3 :UInt64;
  isAnonymousNamespace @4 :Bool;
  isInline @5 :Bool;
  isOriginalNamespace @6 :Bool;
  declarationsInContext @7 :List(UInt64);
}

struct NamespaceAliasDecl @0xd8966652a484c480 {
  namedDecl @0:NamedDecl;
  aliasToken @1 :UInt64;
  aliasedNamespace @2 :UInt64;
  namespace @3 :UInt64;
  namespaceToken @4 :UInt64;
  targetNameToken @5 :UInt64;
}

struct LinkageSpecDecl @0xb0f84c4a56c95eec {
  decl @0:Decl;
  externToken @1 :UInt64;
  language @2 :LinkageSpecDeclLanguageIDs;
  rBraceToken @3 :UInt64;
  hasBraces @4 :Bool;
  declarationsInContext @5 :List(UInt64);
}

struct LifetimeExtendedTemporaryDecl @0x829a6a0ac2b5baa8 {
  decl @0:Decl;
  extendingDeclaration @1 :UInt64;
  storageDuration @2 :StorageDuration;
}

struct ImportDecl @0x84f826d506def833 {
  decl @0:Decl;
  identifierTokens @1 :List(UInt64);
}

struct FriendTemplateDecl @0x82a920109bdb2178 {
  decl @0:Decl;
  friendDeclaration @1 :UInt64;
  friendToken @2 :UInt64;
  templateParameterLists @3 :List(TemplateParameterList);
}

struct FriendDecl @0xe6545eb838d810d0 {
  decl @0:Decl;
  friendDeclaration @1 :UInt64;
  friendToken @2 :UInt64;
  isUnsupportedFriend @3 :Bool;
  friendTypeTemplateParameterLists @4 :List(TemplateParameterList);
}

struct FileScopeAsmDecl @0xa91b82b590024228 {
  decl @0:Decl;
  assemblyToken @1 :UInt64;
  assemblyString @2 :UInt64;
  rParenToken @3 :UInt64;
}

struct ExternCContextDecl @0xd79e4560c3f80cbd {
  decl @0:Decl;
  declarationsInContext @1 :List(UInt64);
}

struct ExportDecl @0xb9bc9642842c6d81 {
  decl @0:Decl;
  exportToken @1 :UInt64;
  rBraceToken @2 :UInt64;
  hasBraces @3 :Bool;
  declarationsInContext @4 :List(UInt64);
}

struct EmptyDecl @0xdb55f7b2f60fd2a7 {
  decl @0:Decl;
}

struct EntityList @0xf26db0d046aab9c9 {
  vaArgExpr @0 :List(VAArgExpr);
  unresolvedLookupExpr @1 :List(UnresolvedLookupExpr);
  unaryOperator @2 :List(UnaryOperator);
  typoExpr @3 :List(TypoExpr);
  typeTraitExpr @4 :List(TypeTraitExpr);
  switchStmt @5 :List(SwitchStmt);
  stmtExpr @6 :List(StmtExpr);
  sourceLocExpr @7 :List(SourceLocExpr);
  shuffleVectorExpr @8 :List(ShuffleVectorExpr);
  syclUniqueStableNameExpr @9 :List(SYCLUniqueStableNameExpr);
  returnStmt @10 :List(ReturnStmt);
  recoveryExpr @11 :List(RecoveryExpr);
  pseudoObjectExpr @12 :List(PseudoObjectExpr);
  parenListExpr @13 :List(ParenListExpr);
  parenExpr @14 :List(ParenExpr);
  opaqueValueExpr @15 :List(OpaqueValueExpr);
  offsetOfExpr @16 :List(OffsetOfExpr);
  objCSubscriptRefExpr @17 :List(ObjCSubscriptRefExpr);
  objCStringLiteral @18 :List(ObjCStringLiteral);
  objCPropertyRefExpr @19 :List(ObjCPropertyRefExpr);
  objCIvarRefExpr @20 :List(ObjCIvarRefExpr);
  objCIsaExpr @21 :List(ObjCIsaExpr);
  objCIndirectCopyRestoreExpr @22 :List(ObjCIndirectCopyRestoreExpr);
  objCEncodeExpr @23 :List(ObjCEncodeExpr);
  objCBridgedCastExpr @24 :List(ObjCBridgedCastExpr);
  objCAvailabilityCheckExpr @25 :List(ObjCAvailabilityCheckExpr);
  objCAutoreleasePoolStmt @26 :List(ObjCAutoreleasePoolStmt);
  objCAtTryStmt @27 :List(ObjCAtTryStmt);
  objCAtThrowStmt @28 :List(ObjCAtThrowStmt);
  objCAtSynchronizedStmt @29 :List(ObjCAtSynchronizedStmt);
  objCArrayLiteral @30 :List(ObjCArrayLiteral);
  unresolvedMemberExpr @31 :List(UnresolvedMemberExpr);
  ompTeamsDistributeParallelForSimdDirective @32 :List(OMPTeamsDistributeParallelForSimdDirective);
  ompTeamsDistributeParallelForDirective @33 :List(OMPTeamsDistributeParallelForDirective);
  objCSelectorExpr @34 :List(ObjCSelectorExpr);
  ompTeamsDistributeDirective @35 :List(OMPTeamsDistributeDirective);
  ompTeamsDirective @36 :List(OMPTeamsDirective);
  ompTaskgroupDirective @37 :List(OMPTaskgroupDirective);
  ompTaskLoopSimdDirective @38 :List(OMPTaskLoopSimdDirective);
  ompTaskLoopDirective @39 :List(OMPTaskLoopDirective);
  ompTargetUpdateDirective @40 :List(OMPTargetUpdateDirective);
  ompTargetTeamsDistributeParallelForSimdDirective @41 :List(OMPTargetTeamsDistributeParallelForSimdDirective);
  ompTargetTeamsDistributeParallelForDirective @42 :List(OMPTargetTeamsDistributeParallelForDirective);
  ompTargetTeamsDistributeDirective @43 :List(OMPTargetTeamsDistributeDirective);
  ompTargetTeamsDirective @44 :List(OMPTargetTeamsDirective);
  ompTargetParallelForSimdDirective @45 :List(OMPTargetParallelForSimdDirective);
  ompTargetParallelDirective @46 :List(OMPTargetParallelDirective);
  ompTargetExitDataDirective @47 :List(OMPTargetExitDataDirective);
  ompTargetEnterDataDirective @48 :List(OMPTargetEnterDataDirective);
  ompTargetDirective @49 :List(OMPTargetDirective);
  ompSimdDirective @50 :List(OMPSimdDirective);
  ompSectionsDirective @51 :List(OMPSectionsDirective);
  ompSectionDirective @52 :List(OMPSectionDirective);
  ompScanDirective @53 :List(OMPScanDirective);
  ompParallelMasterTaskLoopSimdDirective @54 :List(OMPParallelMasterTaskLoopSimdDirective);
  ompParallelMasterTaskLoopDirective @55 :List(OMPParallelMasterTaskLoopDirective);
  unaryExprOrTypeTraitExpr @56 :List(UnaryExprOrTypeTraitExpr);
  ompParallelMasterDirective @57 :List(OMPParallelMasterDirective);
  ompParallelForSimdDirective @58 :List(OMPParallelForSimdDirective);
  ompParallelForDirective @59 :List(OMPParallelForDirective);
  ompMasterDirective @60 :List(OMPMasterDirective);
  ompInteropDirective @61 :List(OMPInteropDirective);
  sehTryStmt @62 :List(SEHTryStmt);
  predefinedExpr @63 :List(PredefinedExpr);
  ompForSimdDirective @64 :List(OMPForSimdDirective);
  ompForDirective @65 :List(OMPForDirective);
  ompFlushDirective @66 :List(OMPFlushDirective);
  ompDistributeParallelForDirective @67 :List(OMPDistributeParallelForDirective);
  ompDispatchDirective @68 :List(OMPDispatchDirective);
  ompCanonicalLoop @69 :List(OMPCanonicalLoop);
  ompCancellationPointDirective @70 :List(OMPCancellationPointDirective);
  ompCancelDirective @71 :List(OMPCancelDirective);
  ompBarrierDirective @72 :List(OMPBarrierDirective);
  sehLeaveStmt @73 :List(SEHLeaveStmt);
  ompAtomicDirective @74 :List(OMPAtomicDirective);
  ompArrayShapingExpr @75 :List(OMPArrayShapingExpr);
  nullStmt @76 :List(NullStmt);
  ompTargetDataDirective @77 :List(OMPTargetDataDirective);
  ompDeclareMapperDecl @78 :List(OMPDeclareMapperDecl);
  cxxThisExpr @79 :List(CXXThisExpr);
  matrixSubscriptExpr @80 :List(MatrixSubscriptExpr);
  dependentScopeDeclRefExpr @81 :List(DependentScopeDeclRefExpr);
  msPropertySubscriptExpr @82 :List(MSPropertySubscriptExpr);
  msPropertyRefExpr @83 :List(MSPropertyRefExpr);
  cxxForRangeStmt @84 :List(CXXForRangeStmt);
  lambdaExpr @85 :List(LambdaExpr);
  initListExpr @86 :List(InitListExpr);
  imaginaryLiteral @87 :List(ImaginaryLiteral);
  implicitValueInitExpr @88 :List(ImplicitValueInitExpr);
  ifStmt @89 :List(IfStmt);
  addrLabelExpr @90 :List(AddrLabelExpr);
  gotoStmt @91 :List(GotoStmt);
  substNonTypeTemplateParmExpr @92 :List(SubstNonTypeTemplateParmExpr);
  gnuNullExpr @93 :List(GNUNullExpr);
  floatingLiteral @94 :List(FloatingLiteral);
  cxxDefaultInitExpr @95 :List(CXXDefaultInitExpr);
  usingPackDecl @96 :List(UsingPackDecl);
  fixedPointLiteral @97 :List(FixedPointLiteral);
  expressionTraitExpr @98 :List(ExpressionTraitExpr);
  usingShadowDecl @99 :List(UsingShadowDecl);
  implicitCastExpr @100 :List(ImplicitCastExpr);
  objCAtCatchStmt @101 :List(ObjCAtCatchStmt);
  ompMaskedDirective @102 :List(OMPMaskedDirective);
  exprWithCleanups @103 :List(ExprWithCleanups);
  doStmt @104 :List(DoStmt);
  ompTaskyieldDirective @105 :List(OMPTaskyieldDirective);
  designatedInitUpdateExpr @106 :List(DesignatedInitUpdateExpr);
  extVectorElementExpr @107 :List(ExtVectorElementExpr);
  lifetimeExtendedTemporaryDecl @108 :List(LifetimeExtendedTemporaryDecl);
  designatedInitExpr @109 :List(DesignatedInitExpr);
  dependentCoawaitExpr @110 :List(DependentCoawaitExpr);
  declStmt @111 :List(DeclStmt);
  memberExpr @112 :List(MemberExpr);
  defaultStmt @113 :List(DefaultStmt);
  coyieldExpr @114 :List(CoyieldExpr);
  compoundStmt @115 :List(CompoundStmt);
  coreturnStmt @116 :List(CoreturnStmt);
  convertVectorExpr @117 :List(ConvertVectorExpr);
  cxxRewrittenBinaryOperator @118 :List(CXXRewrittenBinaryOperator);
  constantExpr @119 :List(ConstantExpr);
  objCAtDefsFieldDecl @120 :List(ObjCAtDefsFieldDecl);
  objCContainerDecl @121 :List(ObjCContainerDecl);
  conceptSpecializationExpr @122 :List(ConceptSpecializationExpr);
  attributedStmt @123 :List(AttributedStmt);
  compoundAssignOperator @124 :List(CompoundAssignOperator);
  chooseExpr @125 :List(ChooseExpr);
  objCProtocolExpr @126 :List(ObjCProtocolExpr);
  caseStmt @127 :List(CaseStmt);
  coawaitExpr @128 :List(CoawaitExpr);
  ompDistributeDirective @129 :List(OMPDistributeDirective);
  capturedStmt @130 :List(CapturedStmt);
  callExpr @131 :List(CallExpr);
  objCDictionaryLiteral @132 :List(ObjCDictionaryLiteral);
  cxxTypeidExpr @133 :List(CXXTypeidExpr);
  integerLiteral @134 :List(IntegerLiteral);
  cxxThrowExpr @135 :List(CXXThrowExpr);
  ompSingleDirective @136 :List(OMPSingleDirective);
  noInitExpr @137 :List(NoInitExpr);
  pragmaCommentDecl @138 :List(PragmaCommentDecl);
  characterLiteral @139 :List(CharacterLiteral);
  ompDepobjDirective @140 :List(OMPDepobjDirective);
  cxxFoldExpr @141 :List(CXXFoldExpr);
  cxxTemporaryObjectExpr @142 :List(CXXTemporaryObjectExpr);
  cxxStdInitializerListExpr @143 :List(CXXStdInitializerListExpr);
  cxxUuidofExpr @144 :List(CXXUuidofExpr);
  cxxReinterpretCastExpr @145 :List(CXXReinterpretCastExpr);
  fieldDecl @146 :List(FieldDecl);
  staticAssertDecl @147 :List(StaticAssertDecl);
  gccAsmStmt @148 :List(GCCAsmStmt);
  ompOrderedDirective @149 :List(OMPOrderedDirective);
  ompAllocateDecl @150 :List(OMPAllocateDecl);
  cxxPseudoDestructorExpr @151 :List(CXXPseudoDestructorExpr);
  cxxNoexceptExpr @152 :List(CXXNoexceptExpr);
  cxxMemberCallExpr @153 :List(CXXMemberCallExpr);
  cxxConstructExpr @154 :List(CXXConstructExpr);
  cxxNullPtrLiteralExpr @155 :List(CXXNullPtrLiteralExpr);
  cxxConstCastExpr @156 :List(CXXConstCastExpr);
  cxxBoolLiteralExpr @157 :List(CXXBoolLiteralExpr);
  implicitParamDecl @158 :List(ImplicitParamDecl);
  cxxBindTemporaryExpr @159 :List(CXXBindTemporaryExpr);
  cxxAddrspaceCastExpr @160 :List(CXXAddrspaceCastExpr);
  enumConstantDecl @161 :List(EnumConstantDecl);
  functionParmPackExpr @162 :List(FunctionParmPackExpr);
  ompDistributeSimdDirective @163 :List(OMPDistributeSimdDirective);
  namespaceDecl @164 :List(NamespaceDecl);
  builtinBitCastExpr @165 :List(BuiltinBitCastExpr);
  continueStmt @166 :List(ContinueStmt);
  ompTileDirective @167 :List(OMPTileDirective);
  breakStmt @168 :List(BreakStmt);
  arrayInitIndexExpr @169 :List(ArrayInitIndexExpr);
  binaryOperator @170 :List(BinaryOperator);
  ompTargetSimdDirective @171 :List(OMPTargetSimdDirective);
  binaryConditionalOperator @172 :List(BinaryConditionalOperator);
  typedefDecl @173 :List(TypedefDecl);
  arraySubscriptExpr @174 :List(ArraySubscriptExpr);
  cxxInheritedCtorInitExpr @175 :List(CXXInheritedCtorInitExpr);
  objCCategoryImplDecl @176 :List(ObjCCategoryImplDecl);
  atomicExpr @177 :List(AtomicExpr);
  functionTemplateDecl @178 :List(FunctionTemplateDecl);
  cxxFunctionalCastExpr @179 :List(CXXFunctionalCastExpr);
  labelStmt @180 :List(LabelStmt);
  typeAliasDecl @181 :List(TypeAliasDecl);
  parmVarDecl @182 :List(ParmVarDecl);
  ompTaskwaitDirective @183 :List(OMPTaskwaitDirective);
  objCImplementationDecl @184 :List(ObjCImplementationDecl);
  usingEnumDecl @185 :List(UsingEnumDecl);
  usingDirectiveDecl @186 :List(UsingDirectiveDecl);
  msAsmStmt @187 :List(MSAsmStmt);
  objCMessageExpr @188 :List(ObjCMessageExpr);
  unresolvedUsingValueDecl @189 :List(UnresolvedUsingValueDecl);
  objCIvarDecl @190 :List(ObjCIvarDecl);
  unresolvedUsingIfExistsDecl @191 :List(UnresolvedUsingIfExistsDecl);
  builtinTemplateDecl @192 :List(BuiltinTemplateDecl);
  templateTypeParmDecl @193 :List(TemplateTypeParmDecl);
  cxxConstructorDecl @194 :List(CXXConstructorDecl);
  ompDistributeParallelForSimdDirective @195 :List(OMPDistributeParallelForSimdDirective);
  namespaceAliasDecl @196 :List(NamespaceAliasDecl);
  templateTemplateParmDecl @197 :List(TemplateTemplateParmDecl);
  ompTaskDirective @198 :List(OMPTaskDirective);
  indirectGotoStmt @199 :List(IndirectGotoStmt);
  tagDecl @200 :List(TagDecl);
  recordDecl @201 :List(RecordDecl);
  templateParamObjectDecl @202 :List(TemplateParamObjectDecl);
  conceptDecl @203 :List(ConceptDecl);
  redeclarableTemplateDecl @204 :List(RedeclarableTemplateDecl);
  pragmaDetectMismatchDecl @205 :List(PragmaDetectMismatchDecl);
  ompMasterTaskLoopSimdDirective @206 :List(OMPMasterTaskLoopSimdDirective);
  objCTypeParamDecl @207 :List(ObjCTypeParamDecl);
  externCContextDecl @208 :List(ExternCContextDecl);
  objCProtocolDecl @209 :List(ObjCProtocolDecl);
  unresolvedUsingTypenameDecl @210 :List(UnresolvedUsingTypenameDecl);
  packExpansionExpr @211 :List(PackExpansionExpr);
  objCPropertyDecl @212 :List(ObjCPropertyDecl);
  token @213 :List(Token);
  importDecl @214 :List(ImportDecl);
  objCMethodDecl @215 :List(ObjCMethodDecl);
  objCBoolLiteralExpr @216 :List(ObjCBoolLiteralExpr);
  cxxConversionDecl @217 :List(CXXConversionDecl);
  cxxStaticCastExpr @218 :List(CXXStaticCastExpr);
  arrayTypeTraitExpr @219 :List(ArrayTypeTraitExpr);
  typedefNameDecl @220 :List(TypedefNameDecl);
  ompDeclareReductionDecl @221 :List(OMPDeclareReductionDecl);
  valueDecl @222 :List(ValueDecl);
  cxxTryStmt @223 :List(CXXTryStmt);
  objCInterfaceDecl @224 :List(ObjCInterfaceDecl);
  emptyDecl @225 :List(EmptyDecl);
  cxxOperatorCallExpr @226 :List(CXXOperatorCallExpr);
  objCCategoryDecl @227 :List(ObjCCategoryDecl);
  coroutineBodyStmt @228 :List(CoroutineBodyStmt);
  declRefExpr @229 :List(DeclRefExpr);
  varDecl @230 :List(VarDecl);
  forStmt @231 :List(ForStmt);
  substNonTypeTemplateParmPackExpr @232 :List(SubstNonTypeTemplateParmPackExpr);
  ompMasterTaskLoopDirective @233 :List(OMPMasterTaskLoopDirective);
  cxxScalarValueInitExpr @234 :List(CXXScalarValueInitExpr);
  msGuidDecl @235 :List(MSGuidDecl);
  ompThreadPrivateDecl @236 :List(OMPThreadPrivateDecl);
  varTemplateDecl @237 :List(VarTemplateDecl);
  baseUsingDecl @238 :List(BaseUsingDecl);
  declaratorDecl @239 :List(DeclaratorDecl);
  varTemplateSpecializationDecl @240 :List(VarTemplateSpecializationDecl);
  blockExpr @241 :List(BlockExpr);
  usingDecl @242 :List(UsingDecl);
  arrayInitLoopExpr @243 :List(ArrayInitLoopExpr);
  cxxDefaultArgExpr @244 :List(CXXDefaultArgExpr);
  msPropertyDecl @245 :List(MSPropertyDecl);
  objCImplDecl @246 :List(ObjCImplDecl);
  materializeTemporaryExpr @247 :List(MaterializeTemporaryExpr);
  requiresExpr @248 :List(RequiresExpr);
  blockDecl @249 :List(BlockDecl);
  indirectFieldDecl @250 :List(IndirectFieldDecl);
  cStyleCastExpr @251 :List(CStyleCastExpr);
  asTypeExpr @252 :List(AsTypeExpr);
  ompUnrollDirective @253 :List(OMPUnrollDirective);
  objCCompatibleAliasDecl @254 :List(ObjCCompatibleAliasDecl);
  typeDecl @255 :List(TypeDecl);
  cxxMethodDecl @256 :List(CXXMethodDecl);
  compoundLiteralExpr @257 :List(CompoundLiteralExpr);
  linkageSpecDecl @258 :List(LinkageSpecDecl);
  cxxDependentScopeMemberExpr @259 :List(CXXDependentScopeMemberExpr);
  classTemplateSpecializationDecl @260 :List(ClassTemplateSpecializationDecl);
  enumDecl @261 :List(EnumDecl);
  namedDecl @262 :List(NamedDecl);
  cxxDeleteExpr @263 :List(CXXDeleteExpr);
  objCForCollectionStmt @264 :List(ObjCForCollectionStmt);
  labelDecl @265 :List(LabelDecl);
  friendDecl @266 :List(FriendDecl);
  whileStmt @267 :List(WhileStmt);
  ompIteratorExpr @268 :List(OMPIteratorExpr);
  ompArraySectionExpr @269 :List(OMPArraySectionExpr);
  varTemplatePartialSpecializationDecl @270 :List(VarTemplatePartialSpecializationDecl);
  constructorUsingShadowDecl @271 :List(ConstructorUsingShadowDecl);
  genericSelectionExpr @272 :List(GenericSelectionExpr);
  classScopeFunctionSpecializationDecl @273 :List(ClassScopeFunctionSpecializationDecl);
  cxxUnresolvedConstructExpr @274 :List(CXXUnresolvedConstructExpr);
  ompTeamsDistributeSimdDirective @275 :List(OMPTeamsDistributeSimdDirective);
  ompParallelSectionsDirective @276 :List(OMPParallelSectionsDirective);
  decompositionDecl @277 :List(DecompositionDecl);
  cxxNewExpr @278 :List(CXXNewExpr);
  objCPropertyImplDecl @279 :List(ObjCPropertyImplDecl);
  userDefinedLiteral @280 :List(UserDefinedLiteral);
  ompTargetParallelForDirective @281 :List(OMPTargetParallelForDirective);
  nonTypeTemplateParmDecl @282 :List(NonTypeTemplateParmDecl);
  functionDecl @283 :List(FunctionDecl);
  templateDecl @284 :List(TemplateDecl);
  fileScopeAsmDecl @285 :List(FileScopeAsmDecl);
  ompCriticalDirective @286 :List(OMPCriticalDirective);
  exportDecl @287 :List(ExportDecl);
  sehExceptStmt @288 :List(SEHExceptStmt);
  ompParallelDirective @289 :List(OMPParallelDirective);
  classTemplateDecl @290 :List(ClassTemplateDecl);
  objCAtFinallyStmt @291 :List(ObjCAtFinallyStmt);
  conditionalOperator @292 :List(ConditionalOperator);
  translationUnitDecl @293 :List(TranslationUnitDecl);
  ompRequiresDecl @294 :List(OMPRequiresDecl);
  cxxDestructorDecl @295 :List(CXXDestructorDecl);
  classTemplatePartialSpecializationDecl @296 :List(ClassTemplatePartialSpecializationDecl);
  capturedDecl @297 :List(CapturedDecl);
  sizeOfPackExpr @298 :List(SizeOfPackExpr);
  ompCapturedExprDecl @299 :List(OMPCapturedExprDecl);
  typeAliasTemplateDecl @300 :List(TypeAliasTemplateDecl);
  ompTargetTeamsDistributeSimdDirective @301 :List(OMPTargetTeamsDistributeSimdDirective);
  cxxRecordDecl @302 :List(CXXRecordDecl);
  cxxDeductionGuideDecl @303 :List(CXXDeductionGuideDecl);
  msDependentExistsStmt @304 :List(MSDependentExistsStmt);
  cxxDynamicCastExpr @305 :List(CXXDynamicCastExpr);
  sehFinallyStmt @306 :List(SEHFinallyStmt);
  objCBoxedExpr @307 :List(ObjCBoxedExpr);
  cxxCatchStmt @308 :List(CXXCatchStmt);
  cudaKernelCallExpr @309 :List(CUDAKernelCallExpr);
  stringLiteral @310 :List(StringLiteral);
  friendTemplateDecl @311 :List(FriendTemplateDecl);
  requiresExprBodyDecl @312 :List(RequiresExprBodyDecl);
  bindingDecl @313 :List(BindingDecl);
  accessSpecDecl @314 :List(AccessSpecDecl);
}
