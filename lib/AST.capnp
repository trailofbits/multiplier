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
  accessUcSpec @0 $Cxx.name("access_spec");
  baseUcUsing @1 $Cxx.name("base_using");
  binding @2 $Cxx.name("binding");
  block @3 $Cxx.name("block");
  builtinUcTemplate @4 $Cxx.name("builtin_template");
  cxxUcConstructor @5 $Cxx.name("cxx_constructor");
  cxxUcConversion @6 $Cxx.name("cxx_conversion");
  cxxUcDeductionUcGuide @7 $Cxx.name("cxx_deduction_guide");
  cxxUcDestructor @8 $Cxx.name("cxx_destructor");
  cxxUcMethod @9 $Cxx.name("cxx_method");
  cxxUcRecord @10 $Cxx.name("cxx_record");
  captured @11 $Cxx.name("captured");
  classUcScopeUcFunctionUcSpecialization @12 $Cxx.name("class_scope_function_specialization");
  classUcTemplate @13 $Cxx.name("class_template");
  classUcTemplateUcPartialUcSpecialization @14 $Cxx.name("class_template_partial_specialization");
  classUcTemplateUcSpecialization @15 $Cxx.name("class_template_specialization");
  concept @16 $Cxx.name("concept");
  constructorUcUsingUcShadow @17 $Cxx.name("constructor_using_shadow");
  declarator @18 $Cxx.name("declarator");
  decomposition @19 $Cxx.name("decomposition");
  empty @20 $Cxx.name("empty");
  enumUcConstant @21 $Cxx.name("enum_constant");
  enum @22 $Cxx.name("enum");
  export @23 $Cxx.name("export");
  externUcCUcContext @24 $Cxx.name("extern_c_context");
  field @25 $Cxx.name("field");
  fileUcScopeUcAsm @26 $Cxx.name("file_scope_asm");
  friend @27 $Cxx.name("friend");
  friendUcTemplate @28 $Cxx.name("friend_template");
  function @29 $Cxx.name("function");
  functionUcTemplate @30 $Cxx.name("function_template");
  implicitUcParam @31 $Cxx.name("implicit_param");
  import @32 $Cxx.name("import");
  indirectUcField @33 $Cxx.name("indirect_field");
  label @34 $Cxx.name("label");
  lifetimeUcExtendedUcTemporary @35 $Cxx.name("lifetime_extended_temporary");
  linkageUcSpec @36 $Cxx.name("linkage_spec");
  msUcGuid @37 $Cxx.name("ms_guid");
  msUcProperty @38 $Cxx.name("ms_property");
  named @39 $Cxx.name("named");
  namespaceUcAlias @40 $Cxx.name("namespace_alias");
  namespace @41 $Cxx.name("namespace");
  nonUcTypeUcTemplateUcParm @42 $Cxx.name("non_type_template_parm");
  ompUcAllocate @43 $Cxx.name("omp_allocate");
  ompUcCapturedUcExpr @44 $Cxx.name("omp_captured_expr");
  ompUcDeclareUcMapper @45 $Cxx.name("omp_declare_mapper");
  ompUcDeclareUcReduction @46 $Cxx.name("omp_declare_reduction");
  ompUcRequires @47 $Cxx.name("omp_requires");
  ompUcThreadUcPrivate @48 $Cxx.name("omp_thread_private");
  objUcCUcAtUcDefsUcField @49 $Cxx.name("obj_c_at_defs_field");
  objUcCUcCategory @50 $Cxx.name("obj_c_category");
  objUcCUcCategoryUcImpl @51 $Cxx.name("obj_c_category_impl");
  objUcCUcCompatibleUcAlias @52 $Cxx.name("obj_c_compatible_alias");
  objUcCUcContainer @53 $Cxx.name("obj_c_container");
  objUcCUcImpl @54 $Cxx.name("obj_c_impl");
  objUcCUcImplementation @55 $Cxx.name("obj_c_implementation");
  objUcCUcInterface @56 $Cxx.name("obj_c_interface");
  objUcCUcIvar @57 $Cxx.name("obj_c_ivar");
  objUcCUcMethod @58 $Cxx.name("obj_c_method");
  objUcCUcProperty @59 $Cxx.name("obj_c_property");
  objUcCUcPropertyUcImpl @60 $Cxx.name("obj_c_property_impl");
  objUcCUcProtocol @61 $Cxx.name("obj_c_protocol");
  objUcCUcTypeUcParam @62 $Cxx.name("obj_c_type_param");
  parmUcVar @63 $Cxx.name("parm_var");
  pragmaUcComment @64 $Cxx.name("pragma_comment");
  pragmaUcDetectUcMismatch @65 $Cxx.name("pragma_detect_mismatch");
  record @66 $Cxx.name("record");
  redeclarableUcTemplate @67 $Cxx.name("redeclarable_template");
  requiresUcExprUcBody @68 $Cxx.name("requires_expr_body");
  staticUcAssert @69 $Cxx.name("static_assert");
  tag @70 $Cxx.name("tag");
  template @71 $Cxx.name("template");
  templateUcParamUcObject @72 $Cxx.name("template_param_object");
  templateUcTemplateUcParm @73 $Cxx.name("template_template_parm");
  templateUcTypeUcParm @74 $Cxx.name("template_type_parm");
  translationUcUnit @75 $Cxx.name("translation_unit");
  typeUcAlias @76 $Cxx.name("type_alias");
  typeUcAliasUcTemplate @77 $Cxx.name("type_alias_template");
  type @78 $Cxx.name("type");
  typedef @79 $Cxx.name("typedef");
  typedefUcName @80 $Cxx.name("typedef_name");
  unresolvedUcUsingUcIfUcExists @81 $Cxx.name("unresolved_using_if_exists");
  unresolvedUcUsingUcTypename @82 $Cxx.name("unresolved_using_typename");
  unresolvedUcUsingUcValue @83 $Cxx.name("unresolved_using_value");
  using @84 $Cxx.name("using");
  usingUcDirective @85 $Cxx.name("using_directive");
  usingUcEnum @86 $Cxx.name("using_enum");
  usingUcPack @87 $Cxx.name("using_pack");
  usingUcShadow @88 $Cxx.name("using_shadow");
  value @89 $Cxx.name("value");
  var @90 $Cxx.name("var");
  varUcTemplate @91 $Cxx.name("var_template");
  varUcTemplateUcPartialUcSpecialization @92 $Cxx.name("var_template_partial_specialization");
  varUcTemplateUcSpecialization @93 $Cxx.name("var_template_specialization");
}

enum ArrayTypeArraySizeModifier @0x9c0c34c182208936 {
  normal @0 $Cxx.name("normal");
  static @1 $Cxx.name("static");
  star @2 $Cxx.name("star");
}

enum AtomicExprAtomicOp @0xbd6e82229eede8ee {
  c11UcAtomicUcInitializer @0 $Cxx.name("c11_atomic_initializer");
  c11UcAtomicUcLoad @1 $Cxx.name("c11_atomic_load");
  c11UcAtomicUcStore @2 $Cxx.name("c11_atomic_store");
  c11UcAtomicUcExchange @3 $Cxx.name("c11_atomic_exchange");
  c11UcAtomicUcCompareUcExchangeUcStrong @4 $Cxx.name("c11_atomic_compare_exchange_strong");
  c11UcAtomicUcCompareUcExchangeUcWeak @5 $Cxx.name("c11_atomic_compare_exchange_weak");
  c11UcAtomicUcFetchUcAdd @6 $Cxx.name("c11_atomic_fetch_add");
  c11UcAtomicUcFetchUcSub @7 $Cxx.name("c11_atomic_fetch_sub");
  c11UcAtomicUcFetchUcAnd @8 $Cxx.name("c11_atomic_fetch_and");
  c11UcAtomicUcFetchUcOr @9 $Cxx.name("c11_atomic_fetch_or");
  c11UcAtomicUcFetchUcXor @10 $Cxx.name("c11_atomic_fetch_xor");
  c11UcAtomicUcFetchUcMax @11 $Cxx.name("c11_atomic_fetch_max");
  c11UcAtomicUcFetchUcMin @12 $Cxx.name("c11_atomic_fetch_min");
  atomicUcLoad @13 $Cxx.name("atomic_load");
  atomicUcLoadUcN @14 $Cxx.name("atomic_load_n");
  atomicUcStore @15 $Cxx.name("atomic_store");
  atomicUcStoreUcN @16 $Cxx.name("atomic_store_n");
  atomicUcExchange @17 $Cxx.name("atomic_exchange");
  atomicUcExchangeUcN @18 $Cxx.name("atomic_exchange_n");
  atomicUcCompareUcExchange @19 $Cxx.name("atomic_compare_exchange");
  atomicUcCompareUcExchangeUcN @20 $Cxx.name("atomic_compare_exchange_n");
  atomicUcFetchUcAdd @21 $Cxx.name("atomic_fetch_add");
  atomicUcFetchUcSub @22 $Cxx.name("atomic_fetch_sub");
  atomicUcFetchUcAnd @23 $Cxx.name("atomic_fetch_and");
  atomicUcFetchUcOr @24 $Cxx.name("atomic_fetch_or");
  atomicUcFetchUcXor @25 $Cxx.name("atomic_fetch_xor");
  atomicUcFetchUcNand @26 $Cxx.name("atomic_fetch_nand");
  atomicUcAddUcFetch @27 $Cxx.name("atomic_add_fetch");
  atomicUcSubUcFetch @28 $Cxx.name("atomic_sub_fetch");
  atomicUcAndUcFetch @29 $Cxx.name("atomic_and_fetch");
  atomicUcOrUcFetch @30 $Cxx.name("atomic_or_fetch");
  atomicUcXorUcFetch @31 $Cxx.name("atomic_xor_fetch");
  atomicUcMaxUcFetch @32 $Cxx.name("atomic_max_fetch");
  atomicUcMinUcFetch @33 $Cxx.name("atomic_min_fetch");
  atomicUcNandUcFetch @34 $Cxx.name("atomic_nand_fetch");
  openclUcAtomicUcInitializer @35 $Cxx.name("opencl_atomic_initializer");
  openclUcAtomicUcLoad @36 $Cxx.name("opencl_atomic_load");
  openclUcAtomicUcStore @37 $Cxx.name("opencl_atomic_store");
  openclUcAtomicUcExchange @38 $Cxx.name("opencl_atomic_exchange");
  openclUcAtomicUcCompareUcExchangeUcStrong @39 $Cxx.name("opencl_atomic_compare_exchange_strong");
  openclUcAtomicUcCompareUcExchangeUcWeak @40 $Cxx.name("opencl_atomic_compare_exchange_weak");
  openclUcAtomicUcFetchUcAdd @41 $Cxx.name("opencl_atomic_fetch_add");
  openclUcAtomicUcFetchUcSub @42 $Cxx.name("opencl_atomic_fetch_sub");
  openclUcAtomicUcFetchUcAnd @43 $Cxx.name("opencl_atomic_fetch_and");
  openclUcAtomicUcFetchUcOr @44 $Cxx.name("opencl_atomic_fetch_or");
  openclUcAtomicUcFetchUcXor @45 $Cxx.name("opencl_atomic_fetch_xor");
  openclUcAtomicUcFetchUcMin @46 $Cxx.name("opencl_atomic_fetch_min");
  openclUcAtomicUcFetchUcMax @47 $Cxx.name("opencl_atomic_fetch_max");
  atomicUcFetchUcMin @48 $Cxx.name("atomic_fetch_min");
  atomicUcFetchUcMax @49 $Cxx.name("atomic_fetch_max");
}

enum BuiltinTypeKind @0xaab624b457b4ccb7 {
  oclUcImage1UcDro @0 $Cxx.name("ocl_image1_dro");
  oclUcImage1UcDarrayUcRo @1 $Cxx.name("ocl_image1_darray_ro");
  oclUcImage1UcDbufferUcRo @2 $Cxx.name("ocl_image1_dbuffer_ro");
  oclUcImage2UcDro @3 $Cxx.name("ocl_image2_dro");
  oclUcImage2UcDarrayUcRo @4 $Cxx.name("ocl_image2_darray_ro");
  oclUcImage2UcDdepthUcRo @5 $Cxx.name("ocl_image2_ddepth_ro");
  oclUcImage2UcDarrayUcDepthUcRo @6 $Cxx.name("ocl_image2_darray_depth_ro");
  oclUcImage2UcDmsaaro @7 $Cxx.name("ocl_image2_dmsaaro");
  oclUcImage2UcDarrayUcMsaaro @8 $Cxx.name("ocl_image2_darray_msaaro");
  oclUcImage2UcDmsaaUcDepthUcRo @9 $Cxx.name("ocl_image2_dmsaa_depth_ro");
  oclUcImage2UcDarrayUcMsaaUcDepthUcRo @10 $Cxx.name("ocl_image2_darray_msaa_depth_ro");
  oclUcImage3UcDro @11 $Cxx.name("ocl_image3_dro");
  oclUcImage1UcDwo @12 $Cxx.name("ocl_image1_dwo");
  oclUcImage1UcDarrayUcWo @13 $Cxx.name("ocl_image1_darray_wo");
  oclUcImage1UcDbufferUcWo @14 $Cxx.name("ocl_image1_dbuffer_wo");
  oclUcImage2UcDwo @15 $Cxx.name("ocl_image2_dwo");
  oclUcImage2UcDarrayUcWo @16 $Cxx.name("ocl_image2_darray_wo");
  oclUcImage2UcDdepthUcWo @17 $Cxx.name("ocl_image2_ddepth_wo");
  oclUcImage2UcDarrayUcDepthUcWo @18 $Cxx.name("ocl_image2_darray_depth_wo");
  oclUcImage2UcDmsaawo @19 $Cxx.name("ocl_image2_dmsaawo");
  oclUcImage2UcDarrayUcMsaawo @20 $Cxx.name("ocl_image2_darray_msaawo");
  oclUcImage2UcDmsaaUcDepthUcWo @21 $Cxx.name("ocl_image2_dmsaa_depth_wo");
  oclUcImage2UcDarrayUcMsaaUcDepthUcWo @22 $Cxx.name("ocl_image2_darray_msaa_depth_wo");
  oclUcImage3UcDwo @23 $Cxx.name("ocl_image3_dwo");
  oclUcImage1UcDrw @24 $Cxx.name("ocl_image1_drw");
  oclUcImage1UcDarrayUcRw @25 $Cxx.name("ocl_image1_darray_rw");
  oclUcImage1UcDbufferUcRw @26 $Cxx.name("ocl_image1_dbuffer_rw");
  oclUcImage2UcDrw @27 $Cxx.name("ocl_image2_drw");
  oclUcImage2UcDarrayUcRw @28 $Cxx.name("ocl_image2_darray_rw");
  oclUcImage2UcDdepthUcRw @29 $Cxx.name("ocl_image2_ddepth_rw");
  oclUcImage2UcDarrayUcDepthUcRw @30 $Cxx.name("ocl_image2_darray_depth_rw");
  oclUcImage2UcDmsaarw @31 $Cxx.name("ocl_image2_dmsaarw");
  oclUcImage2UcDarrayUcMsaarw @32 $Cxx.name("ocl_image2_darray_msaarw");
  oclUcImage2UcDmsaaUcDepthUcRw @33 $Cxx.name("ocl_image2_dmsaa_depth_rw");
  oclUcImage2UcDarrayUcMsaaUcDepthUcRw @34 $Cxx.name("ocl_image2_darray_msaa_depth_rw");
  oclUcImage3UcDrw @35 $Cxx.name("ocl_image3_drw");
  oclUcIntelUcSubgroupUcAvcUcMceUcPayload @36 $Cxx.name("ocl_intel_subgroup_avc_mce_payload");
  oclUcIntelUcSubgroupUcAvcUcImeUcPayload @37 $Cxx.name("ocl_intel_subgroup_avc_ime_payload");
  oclUcIntelUcSubgroupUcAvcUcRefUcPayload @38 $Cxx.name("ocl_intel_subgroup_avc_ref_payload");
  oclUcIntelUcSubgroupUcAvcUcSicUcPayload @39 $Cxx.name("ocl_intel_subgroup_avc_sic_payload");
  oclUcIntelUcSubgroupUcAvcUcMceUcResult @40 $Cxx.name("ocl_intel_subgroup_avc_mce_result");
  oclUcIntelUcSubgroupUcAvcUcImeUcResult @41 $Cxx.name("ocl_intel_subgroup_avc_ime_result");
  oclUcIntelUcSubgroupUcAvcUcRefUcResult @42 $Cxx.name("ocl_intel_subgroup_avc_ref_result");
  oclUcIntelUcSubgroupUcAvcUcSicUcResult @43 $Cxx.name("ocl_intel_subgroup_avc_sic_result");
  oclUcIntelUcSubgroupUcAvcUcImeUcResultUcSingleUcReferenceUcStreamout @44 $Cxx.name("ocl_intel_subgroup_avc_ime_result_single_reference_streamout");
  oclUcIntelUcSubgroupUcAvcUcImeUcResultUcDualUcReferenceUcStreamout @45 $Cxx.name("ocl_intel_subgroup_avc_ime_result_dual_reference_streamout");
  oclUcIntelUcSubgroupUcAvcUcImeUcSingleUcReferenceUcStreamin @46 $Cxx.name("ocl_intel_subgroup_avc_ime_single_reference_streamin");
  oclUcIntelUcSubgroupUcAvcUcImeUcDualUcReferenceUcStreamin @47 $Cxx.name("ocl_intel_subgroup_avc_ime_dual_reference_streamin");
  sveUcInt8 @48 $Cxx.name("sve_int8");
  sveUcInt16 @49 $Cxx.name("sve_int16");
  sveUcInt32 @50 $Cxx.name("sve_int32");
  sveUcInt64 @51 $Cxx.name("sve_int64");
  sveUcUint8 @52 $Cxx.name("sve_uint8");
  sveUcUint16 @53 $Cxx.name("sve_uint16");
  sveUcUint32 @54 $Cxx.name("sve_uint32");
  sveUcUint64 @55 $Cxx.name("sve_uint64");
  sveUcFloat16 @56 $Cxx.name("sve_float16");
  sveUcFloat32 @57 $Cxx.name("sve_float32");
  sveUcFloat64 @58 $Cxx.name("sve_float64");
  sveUcBUcFloat16 @59 $Cxx.name("sve_b_float16");
  sveUcInt8UcX2 @60 $Cxx.name("sve_int8_x2");
  sveUcInt16UcX2 @61 $Cxx.name("sve_int16_x2");
  sveUcInt32UcX2 @62 $Cxx.name("sve_int32_x2");
  sveUcInt64UcX2 @63 $Cxx.name("sve_int64_x2");
  sveUcUint8UcX2 @64 $Cxx.name("sve_uint8_x2");
  sveUcUint16UcX2 @65 $Cxx.name("sve_uint16_x2");
  sveUcUint32UcX2 @66 $Cxx.name("sve_uint32_x2");
  sveUcUint64UcX2 @67 $Cxx.name("sve_uint64_x2");
  sveUcFloat16UcX2 @68 $Cxx.name("sve_float16_x2");
  sveUcFloat32UcX2 @69 $Cxx.name("sve_float32_x2");
  sveUcFloat64UcX2 @70 $Cxx.name("sve_float64_x2");
  sveUcBUcFloat16UcX2 @71 $Cxx.name("sve_b_float16_x2");
  sveUcInt8UcX3 @72 $Cxx.name("sve_int8_x3");
  sveUcInt16UcX3 @73 $Cxx.name("sve_int16_x3");
  sveUcInt32UcX3 @74 $Cxx.name("sve_int32_x3");
  sveUcInt64UcX3 @75 $Cxx.name("sve_int64_x3");
  sveUcUint8UcX3 @76 $Cxx.name("sve_uint8_x3");
  sveUcUint16UcX3 @77 $Cxx.name("sve_uint16_x3");
  sveUcUint32UcX3 @78 $Cxx.name("sve_uint32_x3");
  sveUcUint64UcX3 @79 $Cxx.name("sve_uint64_x3");
  sveUcFloat16UcX3 @80 $Cxx.name("sve_float16_x3");
  sveUcFloat32UcX3 @81 $Cxx.name("sve_float32_x3");
  sveUcFloat64UcX3 @82 $Cxx.name("sve_float64_x3");
  sveUcBUcFloat16UcX3 @83 $Cxx.name("sve_b_float16_x3");
  sveUcInt8UcX4 @84 $Cxx.name("sve_int8_x4");
  sveUcInt16UcX4 @85 $Cxx.name("sve_int16_x4");
  sveUcInt32UcX4 @86 $Cxx.name("sve_int32_x4");
  sveUcInt64UcX4 @87 $Cxx.name("sve_int64_x4");
  sveUcUint8UcX4 @88 $Cxx.name("sve_uint8_x4");
  sveUcUint16UcX4 @89 $Cxx.name("sve_uint16_x4");
  sveUcUint32UcX4 @90 $Cxx.name("sve_uint32_x4");
  sveUcUint64UcX4 @91 $Cxx.name("sve_uint64_x4");
  sveUcFloat16UcX4 @92 $Cxx.name("sve_float16_x4");
  sveUcFloat32UcX4 @93 $Cxx.name("sve_float32_x4");
  sveUcFloat64UcX4 @94 $Cxx.name("sve_float64_x4");
  sveUcBUcFloat16UcX4 @95 $Cxx.name("sve_b_float16_x4");
  sveUcBoolean @96 $Cxx.name("sve_boolean");
  vectorUcQuad @97 $Cxx.name("vector_quad");
  vectorUcPair @98 $Cxx.name("vector_pair");
  rvvUcInt8UcMf8 @99 $Cxx.name("rvv_int8_mf8");
  rvvUcInt8UcMf4 @100 $Cxx.name("rvv_int8_mf4");
  rvvUcInt8UcMf2 @101 $Cxx.name("rvv_int8_mf2");
  rvvUcInt8UcM1 @102 $Cxx.name("rvv_int8_m1");
  rvvUcInt8UcM2 @103 $Cxx.name("rvv_int8_m2");
  rvvUcInt8UcM4 @104 $Cxx.name("rvv_int8_m4");
  rvvUcInt8UcM8 @105 $Cxx.name("rvv_int8_m8");
  rvvUcUint8UcMf8 @106 $Cxx.name("rvv_uint8_mf8");
  rvvUcUint8UcMf4 @107 $Cxx.name("rvv_uint8_mf4");
  rvvUcUint8UcMf2 @108 $Cxx.name("rvv_uint8_mf2");
  rvvUcUint8UcM1 @109 $Cxx.name("rvv_uint8_m1");
  rvvUcUint8UcM2 @110 $Cxx.name("rvv_uint8_m2");
  rvvUcUint8UcM4 @111 $Cxx.name("rvv_uint8_m4");
  rvvUcUint8UcM8 @112 $Cxx.name("rvv_uint8_m8");
  rvvUcInt16UcMf4 @113 $Cxx.name("rvv_int16_mf4");
  rvvUcInt16UcMf2 @114 $Cxx.name("rvv_int16_mf2");
  rvvUcInt16UcM1 @115 $Cxx.name("rvv_int16_m1");
  rvvUcInt16UcM2 @116 $Cxx.name("rvv_int16_m2");
  rvvUcInt16UcM4 @117 $Cxx.name("rvv_int16_m4");
  rvvUcInt16UcM8 @118 $Cxx.name("rvv_int16_m8");
  rvvUcUint16UcMf4 @119 $Cxx.name("rvv_uint16_mf4");
  rvvUcUint16UcMf2 @120 $Cxx.name("rvv_uint16_mf2");
  rvvUcUint16UcM1 @121 $Cxx.name("rvv_uint16_m1");
  rvvUcUint16UcM2 @122 $Cxx.name("rvv_uint16_m2");
  rvvUcUint16UcM4 @123 $Cxx.name("rvv_uint16_m4");
  rvvUcUint16UcM8 @124 $Cxx.name("rvv_uint16_m8");
  rvvUcInt32UcMf2 @125 $Cxx.name("rvv_int32_mf2");
  rvvUcInt32UcM1 @126 $Cxx.name("rvv_int32_m1");
  rvvUcInt32UcM2 @127 $Cxx.name("rvv_int32_m2");
  rvvUcInt32UcM4 @128 $Cxx.name("rvv_int32_m4");
  rvvUcInt32UcM8 @129 $Cxx.name("rvv_int32_m8");
  rvvUcUint32UcMf2 @130 $Cxx.name("rvv_uint32_mf2");
  rvvUcUint32UcM1 @131 $Cxx.name("rvv_uint32_m1");
  rvvUcUint32UcM2 @132 $Cxx.name("rvv_uint32_m2");
  rvvUcUint32UcM4 @133 $Cxx.name("rvv_uint32_m4");
  rvvUcUint32UcM8 @134 $Cxx.name("rvv_uint32_m8");
  rvvUcInt64UcM1 @135 $Cxx.name("rvv_int64_m1");
  rvvUcInt64UcM2 @136 $Cxx.name("rvv_int64_m2");
  rvvUcInt64UcM4 @137 $Cxx.name("rvv_int64_m4");
  rvvUcInt64UcM8 @138 $Cxx.name("rvv_int64_m8");
  rvvUcUint64UcM1 @139 $Cxx.name("rvv_uint64_m1");
  rvvUcUint64UcM2 @140 $Cxx.name("rvv_uint64_m2");
  rvvUcUint64UcM4 @141 $Cxx.name("rvv_uint64_m4");
  rvvUcUint64UcM8 @142 $Cxx.name("rvv_uint64_m8");
  rvvUcFloat16UcMf4 @143 $Cxx.name("rvv_float16_mf4");
  rvvUcFloat16UcMf2 @144 $Cxx.name("rvv_float16_mf2");
  rvvUcFloat16UcM1 @145 $Cxx.name("rvv_float16_m1");
  rvvUcFloat16UcM2 @146 $Cxx.name("rvv_float16_m2");
  rvvUcFloat16UcM4 @147 $Cxx.name("rvv_float16_m4");
  rvvUcFloat16UcM8 @148 $Cxx.name("rvv_float16_m8");
  rvvUcFloat32UcMf2 @149 $Cxx.name("rvv_float32_mf2");
  rvvUcFloat32UcM1 @150 $Cxx.name("rvv_float32_m1");
  rvvUcFloat32UcM2 @151 $Cxx.name("rvv_float32_m2");
  rvvUcFloat32UcM4 @152 $Cxx.name("rvv_float32_m4");
  rvvUcFloat32UcM8 @153 $Cxx.name("rvv_float32_m8");
  rvvUcFloat64UcM1 @154 $Cxx.name("rvv_float64_m1");
  rvvUcFloat64UcM2 @155 $Cxx.name("rvv_float64_m2");
  rvvUcFloat64UcM4 @156 $Cxx.name("rvv_float64_m4");
  rvvUcFloat64UcM8 @157 $Cxx.name("rvv_float64_m8");
  rvvUcBool1 @158 $Cxx.name("rvv_bool1");
  rvvUcBool2 @159 $Cxx.name("rvv_bool2");
  rvvUcBool4 @160 $Cxx.name("rvv_bool4");
  rvvUcBool8 @161 $Cxx.name("rvv_bool8");
  rvvUcBool16 @162 $Cxx.name("rvv_bool16");
  rvvUcBool32 @163 $Cxx.name("rvv_bool32");
  rvvUcBool64 @164 $Cxx.name("rvv_bool64");
  void @165 $Cxx.name("void");
  boolean @166 $Cxx.name("boolean");
  characterUcU @167 $Cxx.name("character_u");
  uUcChar @168 $Cxx.name("u_char");
  wUcCharUcU @169 $Cxx.name("w_char_u");
  char8 @170 $Cxx.name("char8");
  char16 @171 $Cxx.name("char16");
  char32 @172 $Cxx.name("char32");
  uUcShort @173 $Cxx.name("u_short");
  uUcInt @174 $Cxx.name("u_int");
  uUcLong @175 $Cxx.name("u_long");
  uUcLongUcLong @176 $Cxx.name("u_long_long");
  uUcInt128 @177 $Cxx.name("u_int128");
  characterUcS @178 $Cxx.name("character_s");
  sUcChar @179 $Cxx.name("s_char");
  wUcCharUcS @180 $Cxx.name("w_char_s");
  short @181 $Cxx.name("short");
  int @182 $Cxx.name("int");
  long @183 $Cxx.name("long");
  longUcLong @184 $Cxx.name("long_long");
  int128 @185 $Cxx.name("int128");
  shortUcAccum @186 $Cxx.name("short_accum");
  accum @187 $Cxx.name("accum");
  longUcAccum @188 $Cxx.name("long_accum");
  uUcShortUcAccum @189 $Cxx.name("u_short_accum");
  uUcAccum @190 $Cxx.name("u_accum");
  uUcLongUcAccum @191 $Cxx.name("u_long_accum");
  shortUcFract @192 $Cxx.name("short_fract");
  fract @193 $Cxx.name("fract");
  longUcFract @194 $Cxx.name("long_fract");
  uUcShortUcFract @195 $Cxx.name("u_short_fract");
  uUcFract @196 $Cxx.name("u_fract");
  uUcLongUcFract @197 $Cxx.name("u_long_fract");
  satUcShortUcAccum @198 $Cxx.name("sat_short_accum");
  satUcAccum @199 $Cxx.name("sat_accum");
  satUcLongUcAccum @200 $Cxx.name("sat_long_accum");
  satUcUUcShortUcAccum @201 $Cxx.name("sat_u_short_accum");
  satUcUUcAccum @202 $Cxx.name("sat_u_accum");
  satUcUUcLongUcAccum @203 $Cxx.name("sat_u_long_accum");
  satUcShortUcFract @204 $Cxx.name("sat_short_fract");
  satUcFract @205 $Cxx.name("sat_fract");
  satUcLongUcFract @206 $Cxx.name("sat_long_fract");
  satUcUUcShortUcFract @207 $Cxx.name("sat_u_short_fract");
  satUcUUcFract @208 $Cxx.name("sat_u_fract");
  satUcUUcLongUcFract @209 $Cxx.name("sat_u_long_fract");
  half @210 $Cxx.name("half");
  float @211 $Cxx.name("float");
  double @212 $Cxx.name("double");
  longUcDouble @213 $Cxx.name("long_double");
  float16 @214 $Cxx.name("float16");
  bUcFloat16 @215 $Cxx.name("b_float16");
  float128 @216 $Cxx.name("float128");
  nullUcPointer @217 $Cxx.name("null_pointer");
  objUcCUcId @218 $Cxx.name("obj_c_id");
  objUcCUcClass @219 $Cxx.name("obj_c_class");
  objUcCUcSel @220 $Cxx.name("obj_c_sel");
  oclUcSampler @221 $Cxx.name("ocl_sampler");
  oclUcEvent @222 $Cxx.name("ocl_event");
  oclUcClkUcEvent @223 $Cxx.name("ocl_clk_event");
  oclUcQueue @224 $Cxx.name("ocl_queue");
  oclUcReserveUcId @225 $Cxx.name("ocl_reserve_id");
  dependent @226 $Cxx.name("dependent");
  overload @227 $Cxx.name("overload");
  boundUcMember @228 $Cxx.name("bound_member");
  pseudoUcObject @229 $Cxx.name("pseudo_object");
  unknownUcAny @230 $Cxx.name("unknown_any");
  builtinUcFn @231 $Cxx.name("builtin_fn");
  arcUcUnbridgedUcCast @232 $Cxx.name("arc_unbridged_cast");
  incompleteUcMatrixUcIndex @233 $Cxx.name("incomplete_matrix_index");
  ompUcArrayUcSection @234 $Cxx.name("omp_array_section");
  ompUcArrayUcShaping @235 $Cxx.name("omp_array_shaping");
  ompUcIterator @236 $Cxx.name("omp_iterator");
}

enum CXXConstructExprConstructionKind @0xe62e66817849443b {
  complete @0 $Cxx.name("complete");
  nonUcVirtualUcBase @1 $Cxx.name("non_virtual_base");
  virtualUcBase @2 $Cxx.name("virtual_base");
  delegating @3 $Cxx.name("delegating");
}

enum CXXNewExprInitializationStyle @0xba6c83e98380bd05 {
  noUcInitializer @0 $Cxx.name("no_initializer");
  callUcInitializer @1 $Cxx.name("call_initializer");
  listUcInitializer @2 $Cxx.name("list_initializer");
}

enum CallExprADLCallKind @0x82a3f08354a7009d {
  notUcAdl @0 $Cxx.name("not_adl");
  usesUcAdl @1 $Cxx.name("uses_adl");
}

enum CapturedStmtVariableCaptureKind @0x9c79628470fad762 {
  this @0 $Cxx.name("this");
  byUcReference @1 $Cxx.name("by_reference");
  byUcCopy @2 $Cxx.name("by_copy");
  vlaUcType @3 $Cxx.name("vla_type");
}

enum CharacterLiteralCharacterKind @0xc0c13e28937e938c {
  ascii @0 $Cxx.name("ascii");
  wide @1 $Cxx.name("wide");
  utUcF8 @2 $Cxx.name("ut_f8");
  utUcF16 @3 $Cxx.name("ut_f16");
  utUcF32 @4 $Cxx.name("ut_f32");
}

enum ConstantExprResultStorageKind @0xc4786f8c026b3e39 {
  none @0 $Cxx.name("none");
  int64 @1 $Cxx.name("int64");
  apUcValue @2 $Cxx.name("ap_value");
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
  objUcCUcProtocol @6 $Cxx.name("obj_c_protocol");
  ordinaryUcFriend @7 $Cxx.name("ordinary_friend");
  tagUcFriend @8 $Cxx.name("tag_friend");
  using @9 $Cxx.name("using");
  nonUcMemberUcOperator @10 $Cxx.name("non_member_operator");
  localUcExtern @11 $Cxx.name("local_extern");
  ompUcReduction @12 $Cxx.name("omp_reduction");
  ompUcMapper @13 $Cxx.name("omp_mapper");
}

enum DeclModuleOwnershipKind @0xf10e8db874427fd3 {
  unowned @0 $Cxx.name("unowned");
  visible @1 $Cxx.name("visible");
  visibleUcWhenUcImported @2 $Cxx.name("visible_when_imported");
  moduleUcPrivate @3 $Cxx.name("module_private");
}

enum DeclObjCDeclQualifier @0xe906258f1cf38dde {
  none @0 $Cxx.name("none");
  in @1 $Cxx.name("in");
  inout @2 $Cxx.name("inout");
  out @3 $Cxx.name("out");
  bycopy @4 $Cxx.name("bycopy");
  byref @5 $Cxx.name("byref");
  oneway @6 $Cxx.name("oneway");
  csUcNullability @7 $Cxx.name("cs_nullability");
}

enum ExprConstantExprKind @0xe07297cbddd20026 {
  normal @0 $Cxx.name("normal");
  nonUcClassUcTemplateUcArgument @1 $Cxx.name("non_class_template_argument");
  classUcTemplateUcArgument @2 $Cxx.name("class_template_argument");
  immediateUcInvocation @3 $Cxx.name("immediate_invocation");
}

enum ExprLValueClassification @0xce30839288fdca09 {
  valid @0 $Cxx.name("valid");
  notUcObjectUcType @1 $Cxx.name("not_object_type");
  incompleteUcVoidUcType @2 $Cxx.name("incomplete_void_type");
  duplicateUcVectorUcComponents @3 $Cxx.name("duplicate_vector_components");
  invalidUcExpression @4 $Cxx.name("invalid_expression");
  invalidUcMessageUcExpression @5 $Cxx.name("invalid_message_expression");
  memberUcFunction @6 $Cxx.name("member_function");
  subUcObjUcCUcPropertyUcSetting @7 $Cxx.name("sub_obj_c_property_setting");
  classUcTemporary @8 $Cxx.name("class_temporary");
  arrayUcTemporary @9 $Cxx.name("array_temporary");
}

enum ExprNullPointerConstantKind @0xf1f8486254f579e2 {
  notUcNull @0 $Cxx.name("not_null");
  zeroUcExpression @1 $Cxx.name("zero_expression");
  zeroUcLiteral @2 $Cxx.name("zero_literal");
  cxUcX11UcNullptr @3 $Cxx.name("cx_x11_nullptr");
  gnuUcNull @4 $Cxx.name("gnu_null");
}

enum ExprNullPointerConstantValueDependence @0xe67d9538211e3de4 {
  neverUcValueUcDependent @0 $Cxx.name("never_value_dependent");
  valueUcDependentUcIsUcNull @1 $Cxx.name("value_dependent_is_null");
  valueUcDependentUcIsUcNotUcNull @2 $Cxx.name("value_dependent_is_not_null");
}

enum ExprSideEffectsKind @0xd01186f73a889ba9 {
  noUcSideUcEffects @0 $Cxx.name("no_side_effects");
  allowUcUndefinedUcBehavior @1 $Cxx.name("allow_undefined_behavior");
  allowUcSideUcEffects @2 $Cxx.name("allow_side_effects");
}

enum ExprisModifiableLvalueResult @0xc9f80b8bd2f90317 {
  valid @0 $Cxx.name("valid");
  notUcObjectUcType @1 $Cxx.name("not_object_type");
  incompleteUcVoidUcType @2 $Cxx.name("incomplete_void_type");
  duplicateUcVectorUcComponents @3 $Cxx.name("duplicate_vector_components");
  invalidUcExpression @4 $Cxx.name("invalid_expression");
  lUcValueUcCast @5 $Cxx.name("l_value_cast");
  incompleteUcType @6 $Cxx.name("incomplete_type");
  constUcQualified @7 $Cxx.name("const_qualified");
  constUcQualifiedUcField @8 $Cxx.name("const_qualified_field");
  constUcAddrUcSpace @9 $Cxx.name("const_addr_space");
  arrayUcType @10 $Cxx.name("array_type");
  noUcSetterUcProperty @11 $Cxx.name("no_setter_property");
  memberUcFunction @12 $Cxx.name("member_function");
  subUcObjUcCUcPropertyUcSetting @13 $Cxx.name("sub_obj_c_property_setting");
  invalidUcMessageUcExpression @14 $Cxx.name("invalid_message_expression");
  classUcTemporary @15 $Cxx.name("class_temporary");
  arrayUcTemporary @16 $Cxx.name("array_temporary");
}

enum FunctionDeclTemplatedKind @0xb81ebd6c42642771 {
  nonUcTemplate @0 $Cxx.name("non_template");
  functionUcTemplate @1 $Cxx.name("function_template");
  memberUcSpecialization @2 $Cxx.name("member_specialization");
  functionUcTemplateUcSpecialization @3 $Cxx.name("function_template_specialization");
  dependentUcFunctionUcTemplateUcSpecialization @4 $Cxx.name("dependent_function_template_specialization");
}

enum ImplicitCastExprOnStack @0xc0020b2c8aef2dd6 {
  onUcStack @0 $Cxx.name("on_stack");
}

enum ImplicitParamDeclImplicitParamKind @0xb9686cbfe824fde1 {
  objUcCUcSelf @0 $Cxx.name("obj_c_self");
  objUcCUcCmd @1 $Cxx.name("obj_c_cmd");
  cxxUcThis @2 $Cxx.name("cxx_this");
  cxxvtt @3 $Cxx.name("cxxvtt");
  capturedUcContext @4 $Cxx.name("captured_context");
  other @5 $Cxx.name("other");
}

enum LinkageSpecDeclLanguageIDs @0xddc7f9e7e59fdf94 {
  c @0 $Cxx.name("c");
  cxx @1 $Cxx.name("cxx");
}

enum NamedDeclExplicitVisibilityKind @0xbf22a9b63202e46f {
  visibilityUcForUcType @0 $Cxx.name("visibility_for_type");
  visibilityUcForUcValue @1 $Cxx.name("visibility_for_value");
}

enum OMPDeclareReductionDeclInitKind @0xd48c50a665b4c434 {
  callUcInitializer @0 $Cxx.name("call_initializer");
  directUcInitializer @1 $Cxx.name("direct_initializer");
  copyUcInitializer @2 $Cxx.name("copy_initializer");
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
  superUcClass @2 $Cxx.name("super_class");
  superUcInstance @3 $Cxx.name("super_instance");
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
  lUcFunction @2 $Cxx.name("l_function");
  funcUcDUcName @3 $Cxx.name("func_d_name");
  funcUcSig @4 $Cxx.name("func_sig");
  lUcFuncUcSig @5 $Cxx.name("l_func_sig");
  prettyUcFunction @6 $Cxx.name("pretty_function");
  prettyUcFunctionUcNoUcVirtual @7 $Cxx.name("pretty_function_no_virtual");
}

enum QualTypeDestructionKind @0xb67f958f72909186 {
  none @0 $Cxx.name("none");
  cxxUcDestructor @1 $Cxx.name("cxx_destructor");
  objcUcStrongUcLifetime @2 $Cxx.name("objc_strong_lifetime");
  objcUcWeakUcLifetime @3 $Cxx.name("objc_weak_lifetime");
  nontrivialUcCUcStruct @4 $Cxx.name("nontrivial_c_struct");
}

enum QualTypePrimitiveCopyKind @0xb1229b89086f1937 {
  trivial @0 $Cxx.name("trivial");
  volatileUcTrivial @1 $Cxx.name("volatile_trivial");
  arcUcStrong @2 $Cxx.name("arc_strong");
  arcUcWeak @3 $Cxx.name("arc_weak");
  struct @4 $Cxx.name("struct");
}

enum QualTypePrimitiveDefaultInitializeKind @0xd6c7633f16b32289 {
  trivial @0 $Cxx.name("trivial");
  arcUcStrong @1 $Cxx.name("arc_strong");
  arcUcWeak @2 $Cxx.name("arc_weak");
  struct @3 $Cxx.name("struct");
}

enum RecordDeclArgPassingKind @0xbec42547911ce41c {
  canUcPassUcInUcRegs @0 $Cxx.name("can_pass_in_regs");
  cannotUcPassUcInUcRegs @1 $Cxx.name("cannot_pass_in_regs");
  canUcNeverUcPassUcInUcRegs @2 $Cxx.name("can_never_pass_in_regs");
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
  gccUcAsmUcStmt @0 $Cxx.name("gcc_asm_stmt");
  msUcAsmUcStmt @1 $Cxx.name("ms_asm_stmt");
  breakUcStmt @2 $Cxx.name("break_stmt");
  cxxUcCatchUcStmt @3 $Cxx.name("cxx_catch_stmt");
  cxxUcForUcRangeUcStmt @4 $Cxx.name("cxx_for_range_stmt");
  cxxUcTryUcStmt @5 $Cxx.name("cxx_try_stmt");
  capturedUcStmt @6 $Cxx.name("captured_stmt");
  compoundUcStmt @7 $Cxx.name("compound_stmt");
  continueUcStmt @8 $Cxx.name("continue_stmt");
  coreturnUcStmt @9 $Cxx.name("coreturn_stmt");
  coroutineUcBodyUcStmt @10 $Cxx.name("coroutine_body_stmt");
  declUcStmt @11 $Cxx.name("decl_stmt");
  doUcStmt @12 $Cxx.name("do_stmt");
  forUcStmt @13 $Cxx.name("for_stmt");
  gotoUcStmt @14 $Cxx.name("goto_stmt");
  ifUcStmt @15 $Cxx.name("if_stmt");
  indirectUcGotoUcStmt @16 $Cxx.name("indirect_goto_stmt");
  msUcDependentUcExistsUcStmt @17 $Cxx.name("ms_dependent_exists_stmt");
  nullUcStmt @18 $Cxx.name("null_stmt");
  ompUcCanonicalUcLoop @19 $Cxx.name("omp_canonical_loop");
  ompUcAtomicUcDirective @20 $Cxx.name("omp_atomic_directive");
  ompUcBarrierUcDirective @21 $Cxx.name("omp_barrier_directive");
  ompUcCancelUcDirective @22 $Cxx.name("omp_cancel_directive");
  ompUcCancellationUcPointUcDirective @23 $Cxx.name("omp_cancellation_point_directive");
  ompUcCriticalUcDirective @24 $Cxx.name("omp_critical_directive");
  ompUcDepobjUcDirective @25 $Cxx.name("omp_depobj_directive");
  ompUcDispatchUcDirective @26 $Cxx.name("omp_dispatch_directive");
  ompUcFlushUcDirective @27 $Cxx.name("omp_flush_directive");
  ompUcInteropUcDirective @28 $Cxx.name("omp_interop_directive");
  ompUcDistributeUcDirective @29 $Cxx.name("omp_distribute_directive");
  ompUcDistributeUcParallelUcForUcDirective @30 $Cxx.name("omp_distribute_parallel_for_directive");
  ompUcDistributeUcParallelUcForUcSimdUcDirective @31 $Cxx.name("omp_distribute_parallel_for_simd_directive");
  ompUcDistributeUcSimdUcDirective @32 $Cxx.name("omp_distribute_simd_directive");
  ompUcForUcDirective @33 $Cxx.name("omp_for_directive");
  ompUcForUcSimdUcDirective @34 $Cxx.name("omp_for_simd_directive");
  ompUcMasterUcTaskUcLoopUcDirective @35 $Cxx.name("omp_master_task_loop_directive");
  ompUcMasterUcTaskUcLoopUcSimdUcDirective @36 $Cxx.name("omp_master_task_loop_simd_directive");
  ompUcParallelUcForUcDirective @37 $Cxx.name("omp_parallel_for_directive");
  ompUcParallelUcForUcSimdUcDirective @38 $Cxx.name("omp_parallel_for_simd_directive");
  ompUcParallelUcMasterUcTaskUcLoopUcDirective @39 $Cxx.name("omp_parallel_master_task_loop_directive");
  ompUcParallelUcMasterUcTaskUcLoopUcSimdUcDirective @40 $Cxx.name("omp_parallel_master_task_loop_simd_directive");
  ompUcSimdUcDirective @41 $Cxx.name("omp_simd_directive");
  ompUcTargetUcParallelUcForUcSimdUcDirective @42 $Cxx.name("omp_target_parallel_for_simd_directive");
  ompUcTargetUcSimdUcDirective @43 $Cxx.name("omp_target_simd_directive");
  ompUcTargetUcTeamsUcDistributeUcDirective @44 $Cxx.name("omp_target_teams_distribute_directive");
  ompUcTargetUcTeamsUcDistributeUcParallelUcForUcDirective @45 $Cxx.name("omp_target_teams_distribute_parallel_for_directive");
  ompUcTargetUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @46 $Cxx.name("omp_target_teams_distribute_parallel_for_simd_directive");
  ompUcTargetUcTeamsUcDistributeUcSimdUcDirective @47 $Cxx.name("omp_target_teams_distribute_simd_directive");
  ompUcTaskUcLoopUcDirective @48 $Cxx.name("omp_task_loop_directive");
  ompUcTaskUcLoopUcSimdUcDirective @49 $Cxx.name("omp_task_loop_simd_directive");
  ompUcTeamsUcDistributeUcDirective @50 $Cxx.name("omp_teams_distribute_directive");
  ompUcTeamsUcDistributeUcParallelUcForUcDirective @51 $Cxx.name("omp_teams_distribute_parallel_for_directive");
  ompUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @52 $Cxx.name("omp_teams_distribute_parallel_for_simd_directive");
  ompUcTeamsUcDistributeUcSimdUcDirective @53 $Cxx.name("omp_teams_distribute_simd_directive");
  ompUcTileUcDirective @54 $Cxx.name("omp_tile_directive");
  ompUcUnrollUcDirective @55 $Cxx.name("omp_unroll_directive");
  ompUcMaskedUcDirective @56 $Cxx.name("omp_masked_directive");
  ompUcMasterUcDirective @57 $Cxx.name("omp_master_directive");
  ompUcOrderedUcDirective @58 $Cxx.name("omp_ordered_directive");
  ompUcParallelUcDirective @59 $Cxx.name("omp_parallel_directive");
  ompUcParallelUcMasterUcDirective @60 $Cxx.name("omp_parallel_master_directive");
  ompUcParallelUcSectionsUcDirective @61 $Cxx.name("omp_parallel_sections_directive");
  ompUcScanUcDirective @62 $Cxx.name("omp_scan_directive");
  ompUcSectionUcDirective @63 $Cxx.name("omp_section_directive");
  ompUcSectionsUcDirective @64 $Cxx.name("omp_sections_directive");
  ompUcSingleUcDirective @65 $Cxx.name("omp_single_directive");
  ompUcTargetUcDataUcDirective @66 $Cxx.name("omp_target_data_directive");
  ompUcTargetUcDirective @67 $Cxx.name("omp_target_directive");
  ompUcTargetUcEnterUcDataUcDirective @68 $Cxx.name("omp_target_enter_data_directive");
  ompUcTargetUcExitUcDataUcDirective @69 $Cxx.name("omp_target_exit_data_directive");
  ompUcTargetUcParallelUcDirective @70 $Cxx.name("omp_target_parallel_directive");
  ompUcTargetUcParallelUcForUcDirective @71 $Cxx.name("omp_target_parallel_for_directive");
  ompUcTargetUcTeamsUcDirective @72 $Cxx.name("omp_target_teams_directive");
  ompUcTargetUcUpdateUcDirective @73 $Cxx.name("omp_target_update_directive");
  ompUcTaskUcDirective @74 $Cxx.name("omp_task_directive");
  ompUcTaskgroupUcDirective @75 $Cxx.name("omp_taskgroup_directive");
  ompUcTaskwaitUcDirective @76 $Cxx.name("omp_taskwait_directive");
  ompUcTaskyieldUcDirective @77 $Cxx.name("omp_taskyield_directive");
  ompUcTeamsUcDirective @78 $Cxx.name("omp_teams_directive");
  objUcCUcAtUcCatchUcStmt @79 $Cxx.name("obj_c_at_catch_stmt");
  objUcCUcAtUcFinallyUcStmt @80 $Cxx.name("obj_c_at_finally_stmt");
  objUcCUcAtUcSynchronizedUcStmt @81 $Cxx.name("obj_c_at_synchronized_stmt");
  objUcCUcAtUcThrowUcStmt @82 $Cxx.name("obj_c_at_throw_stmt");
  objUcCUcAtUcTryUcStmt @83 $Cxx.name("obj_c_at_try_stmt");
  objUcCUcAutoreleaseUcPoolUcStmt @84 $Cxx.name("obj_c_autorelease_pool_stmt");
  objUcCUcForUcCollectionUcStmt @85 $Cxx.name("obj_c_for_collection_stmt");
  returnUcStmt @86 $Cxx.name("return_stmt");
  sehUcExceptUcStmt @87 $Cxx.name("seh_except_stmt");
  sehUcFinallyUcStmt @88 $Cxx.name("seh_finally_stmt");
  sehUcLeaveUcStmt @89 $Cxx.name("seh_leave_stmt");
  sehUcTryUcStmt @90 $Cxx.name("seh_try_stmt");
  caseUcStmt @91 $Cxx.name("case_stmt");
  defaultUcStmt @92 $Cxx.name("default_stmt");
  switchUcStmt @93 $Cxx.name("switch_stmt");
  attributedUcStmt @94 $Cxx.name("attributed_stmt");
  binaryUcConditionalUcOperator @95 $Cxx.name("binary_conditional_operator");
  conditionalUcOperator @96 $Cxx.name("conditional_operator");
  addrUcLabelUcExpr @97 $Cxx.name("addr_label_expr");
  arrayUcInitUcIndexUcExpr @98 $Cxx.name("array_init_index_expr");
  arrayUcInitUcLoopUcExpr @99 $Cxx.name("array_init_loop_expr");
  arrayUcSubscriptUcExpr @100 $Cxx.name("array_subscript_expr");
  arrayUcTypeUcTraitUcExpr @101 $Cxx.name("array_type_trait_expr");
  asUcTypeUcExpr @102 $Cxx.name("as_type_expr");
  atomicUcExpr @103 $Cxx.name("atomic_expr");
  binaryUcOperator @104 $Cxx.name("binary_operator");
  compoundUcAssignUcOperator @105 $Cxx.name("compound_assign_operator");
  blockUcExpr @106 $Cxx.name("block_expr");
  cxxUcBindUcTemporaryUcExpr @107 $Cxx.name("cxx_bind_temporary_expr");
  cxxUcBoolUcLiteralUcExpr @108 $Cxx.name("cxx_bool_literal_expr");
  cxxUcConstructUcExpr @109 $Cxx.name("cxx_construct_expr");
  cxxUcTemporaryUcObjectUcExpr @110 $Cxx.name("cxx_temporary_object_expr");
  cxxUcDefaultUcArgUcExpr @111 $Cxx.name("cxx_default_arg_expr");
  cxxUcDefaultUcInitUcExpr @112 $Cxx.name("cxx_default_init_expr");
  cxxUcDeleteUcExpr @113 $Cxx.name("cxx_delete_expr");
  cxxUcDependentUcScopeUcMemberUcExpr @114 $Cxx.name("cxx_dependent_scope_member_expr");
  cxxUcFoldUcExpr @115 $Cxx.name("cxx_fold_expr");
  cxxUcInheritedUcCtorUcInitUcExpr @116 $Cxx.name("cxx_inherited_ctor_init_expr");
  cxxUcNewUcExpr @117 $Cxx.name("cxx_new_expr");
  cxxUcNoexceptUcExpr @118 $Cxx.name("cxx_noexcept_expr");
  cxxUcNullUcPtrUcLiteralUcExpr @119 $Cxx.name("cxx_null_ptr_literal_expr");
  cxxUcPseudoUcDestructorUcExpr @120 $Cxx.name("cxx_pseudo_destructor_expr");
  cxxUcRewrittenUcBinaryUcOperator @121 $Cxx.name("cxx_rewritten_binary_operator");
  cxxUcScalarUcValueUcInitUcExpr @122 $Cxx.name("cxx_scalar_value_init_expr");
  cxxUcStdUcInitializerUcListUcExpr @123 $Cxx.name("cxx_std_initializer_list_expr");
  cxxUcThisUcExpr @124 $Cxx.name("cxx_this_expr");
  cxxUcThrowUcExpr @125 $Cxx.name("cxx_throw_expr");
  cxxUcTypeidUcExpr @126 $Cxx.name("cxx_typeid_expr");
  cxxUcUnresolvedUcConstructUcExpr @127 $Cxx.name("cxx_unresolved_construct_expr");
  cxxUcUuidofUcExpr @128 $Cxx.name("cxx_uuidof_expr");
  callUcExpr @129 $Cxx.name("call_expr");
  cudaUcKernelUcCallUcExpr @130 $Cxx.name("cuda_kernel_call_expr");
  cxxUcMemberUcCallUcExpr @131 $Cxx.name("cxx_member_call_expr");
  cxxUcOperatorUcCallUcExpr @132 $Cxx.name("cxx_operator_call_expr");
  userUcDefinedUcLiteral @133 $Cxx.name("user_defined_literal");
  builtinUcBitUcCastUcExpr @134 $Cxx.name("builtin_bit_cast_expr");
  cUcStyleUcCastUcExpr @135 $Cxx.name("c_style_cast_expr");
  cxxUcFunctionalUcCastUcExpr @136 $Cxx.name("cxx_functional_cast_expr");
  cxxUcAddrspaceUcCastUcExpr @137 $Cxx.name("cxx_addrspace_cast_expr");
  cxxUcConstUcCastUcExpr @138 $Cxx.name("cxx_const_cast_expr");
  cxxUcDynamicUcCastUcExpr @139 $Cxx.name("cxx_dynamic_cast_expr");
  cxxUcReinterpretUcCastUcExpr @140 $Cxx.name("cxx_reinterpret_cast_expr");
  cxxUcStaticUcCastUcExpr @141 $Cxx.name("cxx_static_cast_expr");
  objUcCUcBridgedUcCastUcExpr @142 $Cxx.name("obj_c_bridged_cast_expr");
  implicitUcCastUcExpr @143 $Cxx.name("implicit_cast_expr");
  characterUcLiteral @144 $Cxx.name("character_literal");
  chooseUcExpr @145 $Cxx.name("choose_expr");
  compoundUcLiteralUcExpr @146 $Cxx.name("compound_literal_expr");
  conceptUcSpecializationUcExpr @147 $Cxx.name("concept_specialization_expr");
  convertUcVectorUcExpr @148 $Cxx.name("convert_vector_expr");
  coawaitUcExpr @149 $Cxx.name("coawait_expr");
  coyieldUcExpr @150 $Cxx.name("coyield_expr");
  declUcRefUcExpr @151 $Cxx.name("decl_ref_expr");
  dependentUcCoawaitUcExpr @152 $Cxx.name("dependent_coawait_expr");
  dependentUcScopeUcDeclUcRefUcExpr @153 $Cxx.name("dependent_scope_decl_ref_expr");
  designatedUcInitUcExpr @154 $Cxx.name("designated_init_expr");
  designatedUcInitUcUpdateUcExpr @155 $Cxx.name("designated_init_update_expr");
  expressionUcTraitUcExpr @156 $Cxx.name("expression_trait_expr");
  extUcVectorUcElementUcExpr @157 $Cxx.name("ext_vector_element_expr");
  fixedUcPointUcLiteral @158 $Cxx.name("fixed_point_literal");
  floatingUcLiteral @159 $Cxx.name("floating_literal");
  constantUcExpr @160 $Cxx.name("constant_expr");
  exprUcWithUcCleanups @161 $Cxx.name("expr_with_cleanups");
  functionUcParmUcPackUcExpr @162 $Cxx.name("function_parm_pack_expr");
  gnuUcNullUcExpr @163 $Cxx.name("gnu_null_expr");
  genericUcSelectionUcExpr @164 $Cxx.name("generic_selection_expr");
  imaginaryUcLiteral @165 $Cxx.name("imaginary_literal");
  implicitUcValueUcInitUcExpr @166 $Cxx.name("implicit_value_init_expr");
  initUcListUcExpr @167 $Cxx.name("init_list_expr");
  integerUcLiteral @168 $Cxx.name("integer_literal");
  lambdaUcExpr @169 $Cxx.name("lambda_expr");
  msUcPropertyUcRefUcExpr @170 $Cxx.name("ms_property_ref_expr");
  msUcPropertyUcSubscriptUcExpr @171 $Cxx.name("ms_property_subscript_expr");
  materializeUcTemporaryUcExpr @172 $Cxx.name("materialize_temporary_expr");
  matrixUcSubscriptUcExpr @173 $Cxx.name("matrix_subscript_expr");
  memberUcExpr @174 $Cxx.name("member_expr");
  noUcInitUcExpr @175 $Cxx.name("no_init_expr");
  ompUcArrayUcSectionUcExpr @176 $Cxx.name("omp_array_section_expr");
  ompUcArrayUcShapingUcExpr @177 $Cxx.name("omp_array_shaping_expr");
  ompUcIteratorUcExpr @178 $Cxx.name("omp_iterator_expr");
  objUcCUcArrayUcLiteral @179 $Cxx.name("obj_c_array_literal");
  objUcCUcAvailabilityUcCheckUcExpr @180 $Cxx.name("obj_c_availability_check_expr");
  objUcCUcBoolUcLiteralUcExpr @181 $Cxx.name("obj_c_bool_literal_expr");
  objUcCUcBoxedUcExpr @182 $Cxx.name("obj_c_boxed_expr");
  objUcCUcDictionaryUcLiteral @183 $Cxx.name("obj_c_dictionary_literal");
  objUcCUcEncodeUcExpr @184 $Cxx.name("obj_c_encode_expr");
  objUcCUcIndirectUcCopyUcRestoreUcExpr @185 $Cxx.name("obj_c_indirect_copy_restore_expr");
  objUcCUcIsaUcExpr @186 $Cxx.name("obj_c_isa_expr");
  objUcCUcIvarUcRefUcExpr @187 $Cxx.name("obj_c_ivar_ref_expr");
  objUcCUcMessageUcExpr @188 $Cxx.name("obj_c_message_expr");
  objUcCUcPropertyUcRefUcExpr @189 $Cxx.name("obj_c_property_ref_expr");
  objUcCUcProtocolUcExpr @190 $Cxx.name("obj_c_protocol_expr");
  objUcCUcSelectorUcExpr @191 $Cxx.name("obj_c_selector_expr");
  objUcCUcStringUcLiteral @192 $Cxx.name("obj_c_string_literal");
  objUcCUcSubscriptUcRefUcExpr @193 $Cxx.name("obj_c_subscript_ref_expr");
  offsetUcOfUcExpr @194 $Cxx.name("offset_of_expr");
  opaqueUcValueUcExpr @195 $Cxx.name("opaque_value_expr");
  unresolvedUcLookupUcExpr @196 $Cxx.name("unresolved_lookup_expr");
  unresolvedUcMemberUcExpr @197 $Cxx.name("unresolved_member_expr");
  packUcExpansionUcExpr @198 $Cxx.name("pack_expansion_expr");
  parenUcExpr @199 $Cxx.name("paren_expr");
  parenUcListUcExpr @200 $Cxx.name("paren_list_expr");
  predefinedUcExpr @201 $Cxx.name("predefined_expr");
  pseudoUcObjectUcExpr @202 $Cxx.name("pseudo_object_expr");
  recoveryUcExpr @203 $Cxx.name("recovery_expr");
  requiresUcExpr @204 $Cxx.name("requires_expr");
  syclUcUniqueUcStableUcNameUcExpr @205 $Cxx.name("sycl_unique_stable_name_expr");
  shuffleUcVectorUcExpr @206 $Cxx.name("shuffle_vector_expr");
  sizeUcOfUcPackUcExpr @207 $Cxx.name("size_of_pack_expr");
  sourceUcLocUcExpr @208 $Cxx.name("source_loc_expr");
  stmtUcExpr @209 $Cxx.name("stmt_expr");
  stringUcLiteral @210 $Cxx.name("string_literal");
  substUcNonUcTypeUcTemplateUcParmUcExpr @211 $Cxx.name("subst_non_type_template_parm_expr");
  substUcNonUcTypeUcTemplateUcParmUcPackUcExpr @212 $Cxx.name("subst_non_type_template_parm_pack_expr");
  typeUcTraitUcExpr @213 $Cxx.name("type_trait_expr");
  typoUcExpr @214 $Cxx.name("typo_expr");
  unaryUcExprUcOrUcTypeUcTraitUcExpr @215 $Cxx.name("unary_expr_or_type_trait_expr");
  unaryUcOperator @216 $Cxx.name("unary_operator");
  vaUcArgUcExpr @217 $Cxx.name("va_arg_expr");
  labelUcStmt @218 $Cxx.name("label_stmt");
  whileUcStmt @219 $Cxx.name("while_stmt");
}

enum StringLiteralStringKind @0xbde9cca58b227666 {
  ascii @0 $Cxx.name("ascii");
  wide @1 $Cxx.name("wide");
  utUcF8 @2 $Cxx.name("ut_f8");
  utUcF16 @3 $Cxx.name("ut_f16");
  utUcF32 @4 $Cxx.name("ut_f32");
}

enum TemplateArgumentKind @0xf54459e1b953e2aa {
  empty @0 $Cxx.name("empty");
  type @1 $Cxx.name("type");
  declaration @2 $Cxx.name("declaration");
  nullUcPointer @3 $Cxx.name("null_pointer");
  integral @4 $Cxx.name("integral");
  template @5 $Cxx.name("template");
  templateUcExpansion @6 $Cxx.name("template_expansion");
  expression @7 $Cxx.name("expression");
  pack @8 $Cxx.name("pack");
}

enum TypeScalarTypeKind @0xb29bd5077056707b {
  cUcPointer @0 $Cxx.name("c_pointer");
  blockUcPointer @1 $Cxx.name("block_pointer");
  objUcCUcObjectUcPointer @2 $Cxx.name("obj_c_object_pointer");
  memberUcPointer @3 $Cxx.name("member_pointer");
  boolean @4 $Cxx.name("boolean");
  integral @5 $Cxx.name("integral");
  floating @6 $Cxx.name("floating");
  integralUcComplex @7 $Cxx.name("integral_complex");
  floatingUcComplex @8 $Cxx.name("floating_complex");
  fixedUcPoint @9 $Cxx.name("fixed_point");
}

enum TypeKind @0x8eb229be4c525aa3 {
  adjusted @0 $Cxx.name("adjusted");
  decayed @1 $Cxx.name("decayed");
  constantUcArray @2 $Cxx.name("constant_array");
  dependentUcSizedUcArray @3 $Cxx.name("dependent_sized_array");
  incompleteUcArray @4 $Cxx.name("incomplete_array");
  variableUcArray @5 $Cxx.name("variable_array");
  atomic @6 $Cxx.name("atomic");
  attributed @7 $Cxx.name("attributed");
  blockUcPointer @8 $Cxx.name("block_pointer");
  builtin @9 $Cxx.name("builtin");
  complex @10 $Cxx.name("complex");
  decltype @11 $Cxx.name("decltype");
  auto @12 $Cxx.name("auto");
  deducedUcTemplateUcSpecialization @13 $Cxx.name("deduced_template_specialization");
  dependentUcAddressUcSpace @14 $Cxx.name("dependent_address_space");
  dependentUcExtUcInt @15 $Cxx.name("dependent_ext_int");
  dependentUcName @16 $Cxx.name("dependent_name");
  dependentUcSizedUcExtUcVector @17 $Cxx.name("dependent_sized_ext_vector");
  dependentUcTemplateUcSpecialization @18 $Cxx.name("dependent_template_specialization");
  dependentUcVector @19 $Cxx.name("dependent_vector");
  elaborated @20 $Cxx.name("elaborated");
  extUcInt @21 $Cxx.name("ext_int");
  functionUcNoUcProto @22 $Cxx.name("function_no_proto");
  functionUcProto @23 $Cxx.name("function_proto");
  injectedUcClassUcName @24 $Cxx.name("injected_class_name");
  macroUcQualified @25 $Cxx.name("macro_qualified");
  constantUcMatrix @26 $Cxx.name("constant_matrix");
  dependentUcSizedUcMatrix @27 $Cxx.name("dependent_sized_matrix");
  memberUcPointer @28 $Cxx.name("member_pointer");
  objUcCUcObjectUcPointer @29 $Cxx.name("obj_c_object_pointer");
  objUcCUcObject @30 $Cxx.name("obj_c_object");
  objUcCUcInterface @31 $Cxx.name("obj_c_interface");
  objUcCUcTypeUcParam @32 $Cxx.name("obj_c_type_param");
  packUcExpansion @33 $Cxx.name("pack_expansion");
  paren @34 $Cxx.name("paren");
  pipe @35 $Cxx.name("pipe");
  pointer @36 $Cxx.name("pointer");
  lUcValueUcReference @37 $Cxx.name("l_value_reference");
  rUcValueUcReference @38 $Cxx.name("r_value_reference");
  substUcTemplateUcTypeUcParmUcPack @39 $Cxx.name("subst_template_type_parm_pack");
  substUcTemplateUcTypeUcParm @40 $Cxx.name("subst_template_type_parm");
  enum @41 $Cxx.name("enum");
  record @42 $Cxx.name("record");
  templateUcSpecialization @43 $Cxx.name("template_specialization");
  templateUcTypeUcParm @44 $Cxx.name("template_type_parm");
  typeUcOfUcExpr @45 $Cxx.name("type_of_expr");
  typeUcOf @46 $Cxx.name("type_of");
  typedef @47 $Cxx.name("typedef");
  unaryUcTransform @48 $Cxx.name("unary_transform");
  unresolvedUcUsing @49 $Cxx.name("unresolved_using");
  vector @50 $Cxx.name("vector");
  extUcVector @51 $Cxx.name("ext_vector");
}

enum UnaryTransformTypeUTTKind @0xac82f433159c374e {
  enumUcUnderlyingUcType @0 $Cxx.name("enum_underlying_type");
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
  declarationUcOnly @0 $Cxx.name("declaration_only");
  tentativeUcDefinition @1 $Cxx.name("tentative_definition");
  definition @2 $Cxx.name("definition");
}

enum VarDeclInitializationStyle @0x88cefeefc7e74217 {
  cUcInit @0 $Cxx.name("c_init");
  callUcInitializer @1 $Cxx.name("call_initializer");
  listUcInitializer @2 $Cxx.name("list_initializer");
}

enum VarDeclTLSKind @0xac49397b15ce1472 {
  none @0 $Cxx.name("none");
  static @1 $Cxx.name("static");
  dynamic @2 $Cxx.name("dynamic");
}

enum VectorTypeVectorKind @0xce32479a723baa9b {
  genericUcVector @0 $Cxx.name("generic_vector");
  altiUcVecUcVector @1 $Cxx.name("alti_vec_vector");
  altiUcVecUcPixel @2 $Cxx.name("alti_vec_pixel");
  altiUcVecUcBoolean @3 $Cxx.name("alti_vec_boolean");
  neonUcVector @4 $Cxx.name("neon_vector");
  neonUcPolyUcVector @5 $Cxx.name("neon_poly_vector");
  sveUcFixedUcLengthUcDataUcVector @6 $Cxx.name("sve_fixed_length_data_vector");
  sveUcFixedUcLengthUcPredicateUcVector @7 $Cxx.name("sve_fixed_length_predicate_vector");
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
  ompUcNullUcMemoryUcAlloc @0 $Cxx.name("omp_null_memory_alloc");
  ompUcDefaultUcMemoryUcAlloc @1 $Cxx.name("omp_default_memory_alloc");
  ompUcLargeUcCapUcMemoryUcAlloc @2 $Cxx.name("omp_large_cap_memory_alloc");
  ompUcConstUcMemoryUcAlloc @3 $Cxx.name("omp_const_memory_alloc");
  ompUcHighUcBwUcMemoryUcAlloc @4 $Cxx.name("omp_high_bw_memory_alloc");
  ompUcLowUcLatUcMemoryUcAlloc @5 $Cxx.name("omp_low_lat_memory_alloc");
  ompcUcGroupUcMemoryUcAlloc @6 $Cxx.name("ompc_group_memory_alloc");
  omppUcTeamUcMemoryUcAlloc @7 $Cxx.name("ompp_team_memory_alloc");
  ompUcThreadUcMemoryUcAlloc @8 $Cxx.name("omp_thread_memory_alloc");
  ompUcUserUcDefinedUcMemoryUcAlloc @9 $Cxx.name("omp_user_defined_memory_alloc");
}

enum AltivecSrcCompatKind @0x8c349d9881ec7b8f {
  mixed @0 $Cxx.name("mixed");
  gcc @1 $Cxx.name("gcc");
  xl @2 $Cxx.name("xl");
  # Skipped repeat pasta::kDefault
}

enum ArgumentKind @0xdb7d5e1e19e8e847 {
  stdUcString @0 $Cxx.name("std_string");
  cUcString @1 $Cxx.name("c_string");
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
  qualtypeUcPair @13 $Cxx.name("qualtype_pair");
  attribute @14 $Cxx.name("attribute");
}

enum ArrayTypeTrait @0xd6960ffdc6f9f29f {
  arrayUcRank @0 $Cxx.name("array_rank");
  arrayUcExtent @1 $Cxx.name("array_extent");
}

enum AtomicScopeModelKind @0x993fec1348243c85 {
  none @0 $Cxx.name("none");
  openUcCl @1 $Cxx.name("open_cl");
}

enum AttributeKind @0xea12979c4469acdf {
  addressUcSpace @0 $Cxx.name("address_space");
  armUcMveUcStrictUcPolymorphism @1 $Cxx.name("arm_mve_strict_polymorphism");
  cmseUcNsUcCall @2 $Cxx.name("cmse_ns_call");
  noUcDeref @3 $Cxx.name("no_deref");
  objUcCgc @4 $Cxx.name("obj_cgc");
  objUcCUcInertUcUnsafeUcUnretained @5 $Cxx.name("obj_c_inert_unsafe_unretained");
  objUcCUcKindUcOf @6 $Cxx.name("obj_c_kind_of");
  openUcClUcConstantUcAddressUcSpace @7 $Cxx.name("open_cl_constant_address_space");
  openUcClUcGenericUcAddressUcSpace @8 $Cxx.name("open_cl_generic_address_space");
  openUcClUcGlobalUcAddressUcSpace @9 $Cxx.name("open_cl_global_address_space");
  openUcClUcGlobalUcDeviceUcAddressUcSpace @10 $Cxx.name("open_cl_global_device_address_space");
  openUcClUcGlobalUcHostUcAddressUcSpace @11 $Cxx.name("open_cl_global_host_address_space");
  openUcClUcLocalUcAddressUcSpace @12 $Cxx.name("open_cl_local_address_space");
  openUcClUcPrivateUcAddressUcSpace @13 $Cxx.name("open_cl_private_address_space");
  ptr32 @14 $Cxx.name("ptr32");
  ptr64 @15 $Cxx.name("ptr64");
  sUcPtr @16 $Cxx.name("s_ptr");
  typeUcNonUcNull @17 $Cxx.name("type_non_null");
  typeUcNullUcUnspecified @18 $Cxx.name("type_null_unspecified");
  typeUcNullable @19 $Cxx.name("type_nullable");
  typeUcNullableUcResult @20 $Cxx.name("type_nullable_result");
  uUcPtr @21 $Cxx.name("u_ptr");
  fallUcThrough @22 $Cxx.name("fall_through");
  likely @23 $Cxx.name("likely");
  mustUcTail @24 $Cxx.name("must_tail");
  openUcClUcUnrollUcHint @25 $Cxx.name("open_cl_unroll_hint");
  suppress @26 $Cxx.name("suppress");
  unlikely @27 $Cxx.name("unlikely");
  noUcMerge @28 $Cxx.name("no_merge");
  aUcArch64UcVectorUcPcs @29 $Cxx.name("a_arch64_vector_pcs");
  acquireUcHandle @30 $Cxx.name("acquire_handle");
  anyUcX86UcNoUcCfUcCheck @31 $Cxx.name("any_x86_no_cf_check");
  cUcDecl @32 $Cxx.name("c_decl");
  fastUcCall @33 $Cxx.name("fast_call");
  intelUcOclUcBicc @34 $Cxx.name("intel_ocl_bicc");
  lifetimeUcBound @35 $Cxx.name("lifetime_bound");
  msabi @36 $Cxx.name("msabi");
  nsUcReturnsUcRetained @37 $Cxx.name("ns_returns_retained");
  objUcCUcOwnership @38 $Cxx.name("obj_c_ownership");
  pascal @39 $Cxx.name("pascal");
  pcs @40 $Cxx.name("pcs");
  preserveUcAll @41 $Cxx.name("preserve_all");
  preserveUcMost @42 $Cxx.name("preserve_most");
  regUcCall @43 $Cxx.name("reg_call");
  stdUcCall @44 $Cxx.name("std_call");
  swiftUcAsyncUcCall @45 $Cxx.name("swift_async_call");
  swiftUcCall @46 $Cxx.name("swift_call");
  sysUcVabi @47 $Cxx.name("sys_vabi");
  thisUcCall @48 $Cxx.name("this_call");
  vectorUcCall @49 $Cxx.name("vector_call");
  swiftUcAsyncUcContext @50 $Cxx.name("swift_async_context");
  swiftUcContext @51 $Cxx.name("swift_context");
  swiftUcErrorUcResult @52 $Cxx.name("swift_error_result");
  swiftUcIndirectUcResult @53 $Cxx.name("swift_indirect_result");
  annotate @54 $Cxx.name("annotate");
  cfUcConsumed @55 $Cxx.name("cf_consumed");
  carriesUcDependency @56 $Cxx.name("carries_dependency");
  nsUcConsumed @57 $Cxx.name("ns_consumed");
  nonUcNull @58 $Cxx.name("non_null");
  osUcConsumed @59 $Cxx.name("os_consumed");
  passUcObjectUcSize @60 $Cxx.name("pass_object_size");
  releaseUcHandle @61 $Cxx.name("release_handle");
  useUcHandle @62 $Cxx.name("use_handle");
  amdgpuUcFlatUcWorkUcGroupUcSize @63 $Cxx.name("amdgpu_flat_work_group_size");
  amdgpuUcNumUcSgpr @64 $Cxx.name("amdgpu_num_sgpr");
  amdgpuUcNumUcVgpr @65 $Cxx.name("amdgpu_num_vgpr");
  amdgpuUcWavesUcPerUcEu @66 $Cxx.name("amdgpu_waves_per_eu");
  armUcInterrupt @67 $Cxx.name("arm_interrupt");
  avrUcInterrupt @68 $Cxx.name("avr_interrupt");
  avrUcSignal @69 $Cxx.name("avr_signal");
  acquireUcCapability @70 $Cxx.name("acquire_capability");
  acquiredUcAfter @71 $Cxx.name("acquired_after");
  acquiredUcBefore @72 $Cxx.name("acquired_before");
  alignUcMac68UcK @73 $Cxx.name("align_mac68_k");
  alignUcNatural @74 $Cxx.name("align_natural");
  aligned @75 $Cxx.name("aligned");
  allocUcAlign @76 $Cxx.name("alloc_align");
  allocUcSize @77 $Cxx.name("alloc_size");
  alwaysUcDestroy @78 $Cxx.name("always_destroy");
  alwaysUcInline @79 $Cxx.name("always_inline");
  analyzerUcNoUcReturn @80 $Cxx.name("analyzer_no_return");
  anyUcX86UcInterrupt @81 $Cxx.name("any_x86_interrupt");
  anyUcX86UcNoUcCallerUcSavedUcRegisters @82 $Cxx.name("any_x86_no_caller_saved_registers");
  arcUcWeakrefUcUnavailable @83 $Cxx.name("arc_weakref_unavailable");
  argumentUcWithUcTypeUcTag @84 $Cxx.name("argument_with_type_tag");
  armUcBuiltinUcAlias @85 $Cxx.name("arm_builtin_alias");
  artificial @86 $Cxx.name("artificial");
  assemblyUcLabel @87 $Cxx.name("assembly_label");
  assertUcCapability @88 $Cxx.name("assert_capability");
  assertUcExclusiveUcLock @89 $Cxx.name("assert_exclusive_lock");
  assertUcSharedUcLock @90 $Cxx.name("assert_shared_lock");
  assumeUcAligned @91 $Cxx.name("assume_aligned");
  assumption @92 $Cxx.name("assumption");
  availability @93 $Cxx.name("availability");
  bpfUcPreserveUcAccessUcIndex @94 $Cxx.name("bpf_preserve_access_index");
  blocks @95 $Cxx.name("blocks");
  builtin @96 $Cxx.name("builtin");
  c11UcNoUcReturn @97 $Cxx.name("c11_no_return");
  cfUcAuditedUcTransfer @98 $Cxx.name("cf_audited_transfer");
  cfUcGuard @99 $Cxx.name("cf_guard");
  cfiUcCanonicalUcJumpUcTable @100 $Cxx.name("cfi_canonical_jump_table");
  cfUcReturnsUcNotUcRetained @101 $Cxx.name("cf_returns_not_retained");
  cfUcReturnsUcRetained @102 $Cxx.name("cf_returns_retained");
  cfUcUnknownUcTransfer @103 $Cxx.name("cf_unknown_transfer");
  cpuUcDispatch @104 $Cxx.name("cpu_dispatch");
  cpuUcSpecific @105 $Cxx.name("cpu_specific");
  cudaUcConstant @106 $Cxx.name("cuda_constant");
  cudaUcDevice @107 $Cxx.name("cuda_device");
  cudaUcDeviceUcBuiltinUcSurfaceUcType @108 $Cxx.name("cuda_device_builtin_surface_type");
  cudaUcDeviceUcBuiltinUcTextureUcType @109 $Cxx.name("cuda_device_builtin_texture_type");
  cudaUcGlobal @110 $Cxx.name("cuda_global");
  cudaUcHost @111 $Cxx.name("cuda_host");
  cudaUcInvalidUcTarget @112 $Cxx.name("cuda_invalid_target");
  cudaUcLaunchUcBounds @113 $Cxx.name("cuda_launch_bounds");
  cudaUcShared @114 $Cxx.name("cuda_shared");
  cxUcX11UcNoUcReturn @115 $Cxx.name("cx_x11_no_return");
  callableUcWhen @116 $Cxx.name("callable_when");
  callback @117 $Cxx.name("callback");
  capability @118 $Cxx.name("capability");
  capturedUcRecord @119 $Cxx.name("captured_record");
  cleanup @120 $Cxx.name("cleanup");
  cmseUcNsUcEntry @121 $Cxx.name("cmse_ns_entry");
  codeUcSeg @122 $Cxx.name("code_seg");
  cold @123 $Cxx.name("cold");
  common @124 $Cxx.name("common");
  const @125 $Cxx.name("const");
  constUcInitializer @126 $Cxx.name("const_initializer");
  constructor @127 $Cxx.name("constructor");
  consumable @128 $Cxx.name("consumable");
  consumableUcAutoUcCast @129 $Cxx.name("consumable_auto_cast");
  consumableUcSetUcOnUcRead @130 $Cxx.name("consumable_set_on_read");
  convergent @131 $Cxx.name("convergent");
  dllUcExport @132 $Cxx.name("dll_export");
  dllUcExportUcStaticUcLocal @133 $Cxx.name("dll_export_static_local");
  dllUcImport @134 $Cxx.name("dll_import");
  dllUcImportUcStaticUcLocal @135 $Cxx.name("dll_import_static_local");
  deprecated @136 $Cxx.name("deprecated");
  destructor @137 $Cxx.name("destructor");
  diagnoseUcIf @138 $Cxx.name("diagnose_if");
  disableUcTailUcCalls @139 $Cxx.name("disable_tail_calls");
  emptyUcBases @140 $Cxx.name("empty_bases");
  enableUcIf @141 $Cxx.name("enable_if");
  enforceUcTcb @142 $Cxx.name("enforce_tcb");
  enforceUcTcbUcLeaf @143 $Cxx.name("enforce_tcb_leaf");
  enumUcExtensibility @144 $Cxx.name("enum_extensibility");
  excludeUcFromUcExplicitUcInstantiation @145 $Cxx.name("exclude_from_explicit_instantiation");
  exclusiveUcTrylockUcFunction @146 $Cxx.name("exclusive_trylock_function");
  externalUcSourceUcSymbol @147 $Cxx.name("external_source_symbol");
  final @148 $Cxx.name("final");
  flagUcEnum @149 $Cxx.name("flag_enum");
  flatten @150 $Cxx.name("flatten");
  format @151 $Cxx.name("format");
  formatUcArgument @152 $Cxx.name("format_argument");
  gnuUcInline @153 $Cxx.name("gnu_inline");
  guardedUcBy @154 $Cxx.name("guarded_by");
  guardedUcVariable @155 $Cxx.name("guarded_variable");
  hipUcManaged @156 $Cxx.name("hip_managed");
  hot @157 $Cxx.name("hot");
  ibUcAction @158 $Cxx.name("ib_action");
  ibUcOutlet @159 $Cxx.name("ib_outlet");
  ibUcOutletUcCollection @160 $Cxx.name("ib_outlet_collection");
  initializerUcPriority @161 $Cxx.name("initializer_priority");
  internalUcLinkage @162 $Cxx.name("internal_linkage");
  ltoUcVisibilityUcPublic @163 $Cxx.name("lto_visibility_public");
  layoutUcVersion @164 $Cxx.name("layout_version");
  leaf @165 $Cxx.name("leaf");
  lockUcReturned @166 $Cxx.name("lock_returned");
  locksUcExcluded @167 $Cxx.name("locks_excluded");
  m68UcKinterrupt @168 $Cxx.name("m68_kinterrupt");
  migUcServerUcRoutine @169 $Cxx.name("mig_server_routine");
  msUcAllocator @170 $Cxx.name("ms_allocator");
  msUcInheritance @171 $Cxx.name("ms_inheritance");
  msUcNoUcVUcTable @172 $Cxx.name("ms_no_v_table");
  msUcP430UcInterrupt @173 $Cxx.name("ms_p430_interrupt");
  msUcStruct @174 $Cxx.name("ms_struct");
  msUcVtorUcDisp @175 $Cxx.name("ms_vtor_disp");
  maxUcFieldUcAlignment @176 $Cxx.name("max_field_alignment");
  mayUcAlias @177 $Cxx.name("may_alias");
  microUcMips @178 $Cxx.name("micro_mips");
  minUcSize @179 $Cxx.name("min_size");
  minUcVectorUcWidth @180 $Cxx.name("min_vector_width");
  mips16 @181 $Cxx.name("mips16");
  mipsUcInterrupt @182 $Cxx.name("mips_interrupt");
  mipsUcLongUcCall @183 $Cxx.name("mips_long_call");
  mipsUcShortUcCall @184 $Cxx.name("mips_short_call");
  nsUcConsumesUcSelf @185 $Cxx.name("ns_consumes_self");
  nsUcErrorUcDomain @186 $Cxx.name("ns_error_domain");
  nsUcReturnsUcAutoreleased @187 $Cxx.name("ns_returns_autoreleased");
  nsUcReturnsUcNotUcRetained @188 $Cxx.name("ns_returns_not_retained");
  naked @189 $Cxx.name("naked");
  noUcAlias @190 $Cxx.name("no_alias");
  noUcCommon @191 $Cxx.name("no_common");
  noUcDebug @192 $Cxx.name("no_debug");
  noUcDestroy @193 $Cxx.name("no_destroy");
  noUcDuplicate @194 $Cxx.name("no_duplicate");
  noUcInline @195 $Cxx.name("no_inline");
  noUcInstrumentUcFunction @196 $Cxx.name("no_instrument_function");
  noUcMicroUcMips @197 $Cxx.name("no_micro_mips");
  noUcMips16 @198 $Cxx.name("no_mips16");
  noUcProfileUcFunction @199 $Cxx.name("no_profile_function");
  noUcReturn @200 $Cxx.name("no_return");
  noUcSanitize @201 $Cxx.name("no_sanitize");
  noUcSpeculativeUcLoadUcHardening @202 $Cxx.name("no_speculative_load_hardening");
  noUcSplitUcStack @203 $Cxx.name("no_split_stack");
  noUcStackUcProtector @204 $Cxx.name("no_stack_protector");
  noUcThreadUcSafetyUcAnalysis @205 $Cxx.name("no_thread_safety_analysis");
  noUcThrow @206 $Cxx.name("no_throw");
  noUcUniqueUcAddress @207 $Cxx.name("no_unique_address");
  notUcTailUcCalled @208 $Cxx.name("not_tail_called");
  ompUcAllocateUcDeclaration @209 $Cxx.name("omp_allocate_declaration");
  ompUcCaptureUcNoUcInitializer @210 $Cxx.name("omp_capture_no_initializer");
  ompUcDeclareUcTargetUcDeclaration @211 $Cxx.name("omp_declare_target_declaration");
  ompUcDeclareUcVariant @212 $Cxx.name("omp_declare_variant");
  ompUcThreadUcPrivateUcDeclaration @213 $Cxx.name("omp_thread_private_declaration");
  osUcConsumesUcThis @214 $Cxx.name("os_consumes_this");
  osUcReturnsUcNotUcRetained @215 $Cxx.name("os_returns_not_retained");
  osUcReturnsUcRetained @216 $Cxx.name("os_returns_retained");
  osUcReturnsUcRetainedUcOnUcNonUcZero @217 $Cxx.name("os_returns_retained_on_non_zero");
  osUcReturnsUcRetainedUcOnUcZero @218 $Cxx.name("os_returns_retained_on_zero");
  objUcCUcBridge @219 $Cxx.name("obj_c_bridge");
  objUcCUcBridgeUcMutable @220 $Cxx.name("obj_c_bridge_mutable");
  objUcCUcBridgeUcRelated @221 $Cxx.name("obj_c_bridge_related");
  objUcCUcException @222 $Cxx.name("obj_c_exception");
  objUcCUcExplicitUcProtocolUcImplementation @223 $Cxx.name("obj_c_explicit_protocol_implementation");
  objUcCUcExternallyUcRetained @224 $Cxx.name("obj_c_externally_retained");
  objUcCUcIndependentUcClass @225 $Cxx.name("obj_c_independent_class");
  objUcCUcMethodUcFamily @226 $Cxx.name("obj_c_method_family");
  objUcCnsUcObject @227 $Cxx.name("obj_cns_object");
  objUcCUcPreciseUcLifetime @228 $Cxx.name("obj_c_precise_lifetime");
  objUcCUcRequiresUcPropertyUcDefinitions @229 $Cxx.name("obj_c_requires_property_definitions");
  objUcCUcRequiresUcSuper @230 $Cxx.name("obj_c_requires_super");
  objUcCUcReturnsUcInnerUcPointer @231 $Cxx.name("obj_c_returns_inner_pointer");
  objUcCUcRootUcClass @232 $Cxx.name("obj_c_root_class");
  objUcCUcSubclassingUcRestricted @233 $Cxx.name("obj_c_subclassing_restricted");
  openUcClUcIntelUcReqdUcSubUcGroupUcSize @234 $Cxx.name("open_cl_intel_reqd_sub_group_size");
  openUcClUcKernel @235 $Cxx.name("open_cl_kernel");
  optimizeUcNone @236 $Cxx.name("optimize_none");
  override @237 $Cxx.name("override");
  owner @238 $Cxx.name("owner");
  ownership @239 $Cxx.name("ownership");
  packed @240 $Cxx.name("packed");
  paramUcTypestate @241 $Cxx.name("param_typestate");
  patchableUcFunctionUcEntry @242 $Cxx.name("patchable_function_entry");
  pointer @243 $Cxx.name("pointer");
  pragmaUcClangUcBssUcSection @244 $Cxx.name("pragma_clang_bss_section");
  pragmaUcClangUcDataUcSection @245 $Cxx.name("pragma_clang_data_section");
  pragmaUcClangUcRelroUcSection @246 $Cxx.name("pragma_clang_relro_section");
  pragmaUcClangUcRodataUcSection @247 $Cxx.name("pragma_clang_rodata_section");
  pragmaUcClangUcTextUcSection @248 $Cxx.name("pragma_clang_text_section");
  preferredUcName @249 $Cxx.name("preferred_name");
  ptUcGuardedUcBy @250 $Cxx.name("pt_guarded_by");
  ptUcGuardedUcVariable @251 $Cxx.name("pt_guarded_variable");
  pure @252 $Cxx.name("pure");
  riscvUcInterrupt @253 $Cxx.name("riscv_interrupt");
  reinitializes @254 $Cxx.name("reinitializes");
  releaseUcCapability @255 $Cxx.name("release_capability");
  reqdUcWorkUcGroupUcSize @256 $Cxx.name("reqd_work_group_size");
  requiresUcCapability @257 $Cxx.name("requires_capability");
  restrict @258 $Cxx.name("restrict");
  retain @259 $Cxx.name("retain");
  returnUcTypestate @260 $Cxx.name("return_typestate");
  returnsUcNonUcNull @261 $Cxx.name("returns_non_null");
  returnsUcTwice @262 $Cxx.name("returns_twice");
  syclUcKernel @263 $Cxx.name("sycl_kernel");
  scopedUcLockable @264 $Cxx.name("scoped_lockable");
  section @265 $Cxx.name("section");
  selectUcAny @266 $Cxx.name("select_any");
  sentinel @267 $Cxx.name("sentinel");
  setUcTypestate @268 $Cxx.name("set_typestate");
  sharedUcTrylockUcFunction @269 $Cxx.name("shared_trylock_function");
  speculativeUcLoadUcHardening @270 $Cxx.name("speculative_load_hardening");
  standaloneUcDebug @271 $Cxx.name("standalone_debug");
  strictUcFp @272 $Cxx.name("strict_fp");
  swiftUcAsync @273 $Cxx.name("swift_async");
  swiftUcAsyncUcError @274 $Cxx.name("swift_async_error");
  swiftUcAsyncUcName @275 $Cxx.name("swift_async_name");
  swiftUcAttribute @276 $Cxx.name("swift_attribute");
  swiftUcBridge @277 $Cxx.name("swift_bridge");
  swiftUcBridgedUcTypedef @278 $Cxx.name("swift_bridged_typedef");
  swiftUcError @279 $Cxx.name("swift_error");
  swiftUcName @280 $Cxx.name("swift_name");
  swiftUcNewUcType @281 $Cxx.name("swift_new_type");
  swiftUcPrivate @282 $Cxx.name("swift_private");
  tlsUcModel @283 $Cxx.name("tls_model");
  target @284 $Cxx.name("target");
  testUcTypestate @285 $Cxx.name("test_typestate");
  transparentUcUnion @286 $Cxx.name("transparent_union");
  trivialUcAbi @287 $Cxx.name("trivial_abi");
  tryUcAcquireUcCapability @288 $Cxx.name("try_acquire_capability");
  typeUcTagUcForUcDatatype @289 $Cxx.name("type_tag_for_datatype");
  typeUcVisibility @290 $Cxx.name("type_visibility");
  unavailable @291 $Cxx.name("unavailable");
  uninitialized @292 $Cxx.name("uninitialized");
  unused @293 $Cxx.name("unused");
  used @294 $Cxx.name("used");
  usingUcIfUcExists @295 $Cxx.name("using_if_exists");
  uuid @296 $Cxx.name("uuid");
  vecUcReturn @297 $Cxx.name("vec_return");
  vecUcTypeUcHint @298 $Cxx.name("vec_type_hint");
  visibility @299 $Cxx.name("visibility");
  warnUcUnused @300 $Cxx.name("warn_unused");
  warnUcUnusedUcResult @301 $Cxx.name("warn_unused_result");
  weak @302 $Cxx.name("weak");
  weakUcImport @303 $Cxx.name("weak_import");
  weakUcReference @304 $Cxx.name("weak_reference");
  webUcAssemblyUcExportUcName @305 $Cxx.name("web_assembly_export_name");
  webUcAssemblyUcImportUcModule @306 $Cxx.name("web_assembly_import_module");
  webUcAssemblyUcImportUcName @307 $Cxx.name("web_assembly_import_name");
  workUcGroupUcSizeUcHint @308 $Cxx.name("work_group_size_hint");
  x86UcForceUcAlignUcArgumentUcPointer @309 $Cxx.name("x86_force_align_argument_pointer");
  xUcRayUcInstrument @310 $Cxx.name("x_ray_instrument");
  xUcRayUcLogUcArguments @311 $Cxx.name("x_ray_log_arguments");
  abiUcTag @312 $Cxx.name("abi_tag");
  alias @313 $Cxx.name("alias");
  alignUcValue @314 $Cxx.name("align_value");
  builtinUcAlias @315 $Cxx.name("builtin_alias");
  calledUcOnce @316 $Cxx.name("called_once");
  iUcFunc @317 $Cxx.name("i_func");
  initializerUcSeg @318 $Cxx.name("initializer_seg");
  loaderUcUninitialized @319 $Cxx.name("loader_uninitialized");
  loopUcHint @320 $Cxx.name("loop_hint");
  mode @321 $Cxx.name("mode");
  noUcBuiltin @322 $Cxx.name("no_builtin");
  noUcEscape @323 $Cxx.name("no_escape");
  ompUcCaptureUcKind @324 $Cxx.name("omp_capture_kind");
  ompUcDeclareUcSimdUcDeclaration @325 $Cxx.name("omp_declare_simd_declaration");
  ompUcReferencedUcVariable @326 $Cxx.name("omp_referenced_variable");
  objUcCUcBoxable @327 $Cxx.name("obj_c_boxable");
  objUcCUcClassUcStub @328 $Cxx.name("obj_c_class_stub");
  objUcCUcDesignatedUcInitializer @329 $Cxx.name("obj_c_designated_initializer");
  objUcCUcDirect @330 $Cxx.name("obj_c_direct");
  objUcCUcDirectUcMembers @331 $Cxx.name("obj_c_direct_members");
  objUcCUcNonUcLazyUcClass @332 $Cxx.name("obj_c_non_lazy_class");
  objUcCUcNonUcRuntimeUcProtocol @333 $Cxx.name("obj_c_non_runtime_protocol");
  objUcCUcRuntimeUcName @334 $Cxx.name("obj_c_runtime_name");
  objUcCUcRuntimeUcVisible @335 $Cxx.name("obj_c_runtime_visible");
  openUcClUcAccess @336 $Cxx.name("open_cl_access");
  overloadable @337 $Cxx.name("overloadable");
  renderUcScriptUcKernel @338 $Cxx.name("render_script_kernel");
  swiftUcObjUcCUcMembers @339 $Cxx.name("swift_obj_c_members");
  thread @340 $Cxx.name("thread");
}

enum AutoTypeKeyword @0x8f3df89531320c02 {
  auto @0 $Cxx.name("auto");
  decltypeUcAuto @1 $Cxx.name("decltype_auto");
  gnuUcAutoUcType @2 $Cxx.name("gnu_auto_type");
}

enum AvailabilityResult @0xe8c6cd388f86c217 {
  available @0 $Cxx.name("available");
  notUcYetUcIntroduced @1 $Cxx.name("not_yet_introduced");
  deprecated @2 $Cxx.name("deprecated");
  unavailable @3 $Cxx.name("unavailable");
}

enum BinaryOperatorKind @0xbb08cc41f7a56597 {
  pointerUcMemoryUcD @0 $Cxx.name("pointer_memory_d");
  pointerUcMemoryUcI @1 $Cxx.name("pointer_memory_i");
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
  lUcAnd @19 $Cxx.name("l_and");
  lUcOr @20 $Cxx.name("l_or");
  assign @21 $Cxx.name("assign");
  mulUcAssign @22 $Cxx.name("mul_assign");
  divUcAssign @23 $Cxx.name("div_assign");
  remUcAssign @24 $Cxx.name("rem_assign");
  addUcAssign @25 $Cxx.name("add_assign");
  subUcAssign @26 $Cxx.name("sub_assign");
  shlUcAssign @27 $Cxx.name("shl_assign");
  shrUcAssign @28 $Cxx.name("shr_assign");
  andUcAssign @29 $Cxx.name("and_assign");
  xorUcAssign @30 $Cxx.name("xor_assign");
  orUcAssign @31 $Cxx.name("or_assign");
  comma @32 $Cxx.name("comma");
}

enum Bits @0x87be10d300b35eda {
  none @0 $Cxx.name("none");
  unexpandedUcPack @1 $Cxx.name("unexpanded_pack");
  instantiation @2 $Cxx.name("instantiation");
  type @3 $Cxx.name("type");
  value @4 $Cxx.name("value");
  dependent @5 $Cxx.name("dependent");
  error @6 $Cxx.name("error");
  variablyUcModified @7 $Cxx.name("variably_modified");
  syntactic @8 $Cxx.name("syntactic");
}

enum BlockType @0xa51084915663634e {
  byUcReference @0 $Cxx.name("by_reference");
}

enum BranchStateTy @0xd5619d872098bf4c {
  undefined @0 $Cxx.name("undefined");
  inbranch @1 $Cxx.name("inbranch");
  notinbranch @2 $Cxx.name("notinbranch");
}

enum CallingConv @0xfc49dab6441b4ebd {
  c @0 $Cxx.name("c");
  x86UcStdUcCall @1 $Cxx.name("x86_std_call");
  x86UcFastUcCall @2 $Cxx.name("x86_fast_call");
  x86UcThisUcCall @3 $Cxx.name("x86_this_call");
  x86UcVectorUcCall @4 $Cxx.name("x86_vector_call");
  x86UcPascal @5 $Cxx.name("x86_pascal");
  win64 @6 $Cxx.name("win64");
  x8664UcSysUcV @7 $Cxx.name("x8664_sys_v");
  x86UcRegUcCall @8 $Cxx.name("x86_reg_call");
  aapcs @9 $Cxx.name("aapcs");
  aapcsvfp @10 $Cxx.name("aapcsvfp");
  intelUcOclUcBicc @11 $Cxx.name("intel_ocl_bicc");
  spirUcFunction @12 $Cxx.name("spir_function");
  openUcClUcKernel @13 $Cxx.name("open_cl_kernel");
  swift @14 $Cxx.name("swift");
  swiftUcAsync @15 $Cxx.name("swift_async");
  preserveUcMost @16 $Cxx.name("preserve_most");
  preserveUcAll @17 $Cxx.name("preserve_all");
  aUcArch64UcVectorUcCall @18 $Cxx.name("a_arch64_vector_call");
}

enum CanThrowResult @0xade719c14c0fa1a7 {
  cannot @0 $Cxx.name("cannot");
  dependent @1 $Cxx.name("dependent");
  can @2 $Cxx.name("can");
}

enum CapturedRegionKind @0x9c1102e218ed4271 {
  default @0 $Cxx.name("default");
  objUcCUcAtUcFinally @1 $Cxx.name("obj_c_at_finally");
  openUcMp @2 $Cxx.name("open_mp");
}

enum CastKind @0xc1c8bbecc0c79f1b {
  dependent @0 $Cxx.name("dependent");
  bitUcCast @1 $Cxx.name("bit_cast");
  lUcValueUcBitUcCast @2 $Cxx.name("l_value_bit_cast");
  lUcValueUcToUcRUcValueUcBitUcCast @3 $Cxx.name("l_value_to_r_value_bit_cast");
  lUcValueUcToUcRUcValue @4 $Cxx.name("l_value_to_r_value");
  noUcOperation @5 $Cxx.name("no_operation");
  baseUcToUcDerived @6 $Cxx.name("base_to_derived");
  derivedUcToUcBase @7 $Cxx.name("derived_to_base");
  uncheckedUcDerivedUcToUcBase @8 $Cxx.name("unchecked_derived_to_base");
  dynamic @9 $Cxx.name("dynamic");
  toUcUnion @10 $Cxx.name("to_union");
  arrayUcToUcPointerUcDecay @11 $Cxx.name("array_to_pointer_decay");
  functionUcToUcPointerUcDecay @12 $Cxx.name("function_to_pointer_decay");
  nullUcToUcPointer @13 $Cxx.name("null_to_pointer");
  nullUcToUcMemberUcPointer @14 $Cxx.name("null_to_member_pointer");
  baseUcToUcDerivedUcMemberUcPointer @15 $Cxx.name("base_to_derived_member_pointer");
  derivedUcToUcBaseUcMemberUcPointer @16 $Cxx.name("derived_to_base_member_pointer");
  memberUcPointerUcToUcBoolean @17 $Cxx.name("member_pointer_to_boolean");
  reinterpretUcMemberUcPointer @18 $Cxx.name("reinterpret_member_pointer");
  userUcDefinedUcConversion @19 $Cxx.name("user_defined_conversion");
  constructorUcConversion @20 $Cxx.name("constructor_conversion");
  integralUcToUcPointer @21 $Cxx.name("integral_to_pointer");
  pointerUcToUcIntegral @22 $Cxx.name("pointer_to_integral");
  pointerUcToUcBoolean @23 $Cxx.name("pointer_to_boolean");
  toUcVoid @24 $Cxx.name("to_void");
  matrixUcCast @25 $Cxx.name("matrix_cast");
  vectorUcSplat @26 $Cxx.name("vector_splat");
  integralUcCast @27 $Cxx.name("integral_cast");
  integralUcToUcBoolean @28 $Cxx.name("integral_to_boolean");
  integralUcToUcFloating @29 $Cxx.name("integral_to_floating");
  floatingUcToUcFixedUcPoint @30 $Cxx.name("floating_to_fixed_point");
  fixedUcPointUcToUcFloating @31 $Cxx.name("fixed_point_to_floating");
  fixedUcPointUcCast @32 $Cxx.name("fixed_point_cast");
  fixedUcPointUcToUcIntegral @33 $Cxx.name("fixed_point_to_integral");
  integralUcToUcFixedUcPoint @34 $Cxx.name("integral_to_fixed_point");
  fixedUcPointUcToUcBoolean @35 $Cxx.name("fixed_point_to_boolean");
  floatingUcToUcIntegral @36 $Cxx.name("floating_to_integral");
  floatingUcToUcBoolean @37 $Cxx.name("floating_to_boolean");
  booleanUcToUcSignedUcIntegral @38 $Cxx.name("boolean_to_signed_integral");
  floatingUcCast @39 $Cxx.name("floating_cast");
  cUcPointerUcToUcObjUcCUcPointerUcCast @40 $Cxx.name("c_pointer_to_obj_c_pointer_cast");
  blockUcPointerUcToUcObjUcCUcPointerUcCast @41 $Cxx.name("block_pointer_to_obj_c_pointer_cast");
  anyUcPointerUcToUcBlockUcPointerUcCast @42 $Cxx.name("any_pointer_to_block_pointer_cast");
  objUcCUcObjectUcLUcValueUcCast @43 $Cxx.name("obj_c_object_l_value_cast");
  floatingUcRealUcToUcComplex @44 $Cxx.name("floating_real_to_complex");
  floatingUcComplexUcToUcReal @45 $Cxx.name("floating_complex_to_real");
  floatingUcComplexUcToUcBoolean @46 $Cxx.name("floating_complex_to_boolean");
  floatingUcComplexUcCast @47 $Cxx.name("floating_complex_cast");
  floatingUcComplexUcToUcIntegralUcComplex @48 $Cxx.name("floating_complex_to_integral_complex");
  integralUcRealUcToUcComplex @49 $Cxx.name("integral_real_to_complex");
  integralUcComplexUcToUcReal @50 $Cxx.name("integral_complex_to_real");
  integralUcComplexUcToUcBoolean @51 $Cxx.name("integral_complex_to_boolean");
  integralUcComplexUcCast @52 $Cxx.name("integral_complex_cast");
  integralUcComplexUcToUcFloatingUcComplex @53 $Cxx.name("integral_complex_to_floating_complex");
  arcUcProduceUcObject @54 $Cxx.name("arc_produce_object");
  arcUcConsumeUcObject @55 $Cxx.name("arc_consume_object");
  arcUcReclaimUcReturnedUcObject @56 $Cxx.name("arc_reclaim_returned_object");
  arcUcExtendUcBlockUcObject @57 $Cxx.name("arc_extend_block_object");
  atomicUcToUcNonUcAtomic @58 $Cxx.name("atomic_to_non_atomic");
  nonUcAtomicUcToUcAtomic @59 $Cxx.name("non_atomic_to_atomic");
  copyUcAndUcAutoreleaseUcBlockUcObject @60 $Cxx.name("copy_and_autorelease_block_object");
  builtinUcFnUcToUcFnUcPointer @61 $Cxx.name("builtin_fn_to_fn_pointer");
  zeroUcToUcOclUcOpaqueUcType @62 $Cxx.name("zero_to_ocl_opaque_type");
  addressUcSpaceUcConversion @63 $Cxx.name("address_space_conversion");
  intUcToUcOclUcSampler @64 $Cxx.name("int_to_ocl_sampler");
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
  ordinaryUcBcpl @1 $Cxx.name("ordinary_bcpl");
  ordinaryUcC @2 $Cxx.name("ordinary_c");
  bcplUcSlash @3 $Cxx.name("bcpl_slash");
  bcplUcExcl @4 $Cxx.name("bcpl_excl");
  javaUcDoc @5 $Cxx.name("java_doc");
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
  partialUcOrdering @0 $Cxx.name("partial_ordering");
  weakUcOrdering @1 $Cxx.name("weak_ordering");
  strongUcOrdering @2 $Cxx.name("strong_ordering");
}

enum CompilingModuleKind @0xdb213b290b8b6c8c {
  none @0 $Cxx.name("none");
  moduleUcMap @1 $Cxx.name("module_map");
  headerUcModule @2 $Cxx.name("header_module");
  moduleUcInterface @3 $Cxx.name("module_interface");
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
  nonUcNullUcError @1 $Cxx.name("non_null_error");
  zeroUcArgument @2 $Cxx.name("zero_argument");
  nonUcZeroUcArgument @3 $Cxx.name("non_zero_argument");
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
  cUcDecl @1 $Cxx.name("c_decl");
  fastUcCall @2 $Cxx.name("fast_call");
  stdUcCall @3 $Cxx.name("std_call");
  vectorUcCall @4 $Cxx.name("vector_call");
  regUcCall @5 $Cxx.name("reg_call");
}

enum DevTypeTy @0xfbcfe96906c04575 {
  host @0 $Cxx.name("host");
  noUcHost @1 $Cxx.name("no_host");
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
  embedUcOff @0 $Cxx.name("embed_off");
  embedUcAll @1 $Cxx.name("embed_all");
  embedUcBitcode @2 $Cxx.name("embed_bitcode");
  embedUcMarker @3 $Cxx.name("embed_marker");
}

enum ExceptionHandlingKind @0x81f79c655bf98919 {
  none @0 $Cxx.name("none");
  sjUcLj @1 $Cxx.name("sj_lj");
  winUcEh @2 $Cxx.name("win_eh");
  dwarfUcCfi @3 $Cxx.name("dwarf_cfi");
  wasm @4 $Cxx.name("wasm");
}

enum ExceptionSpecificationType @0xd5391f397240ed4d {
  none @0 $Cxx.name("none");
  dynamicUcNone @1 $Cxx.name("dynamic_none");
  dynamic @2 $Cxx.name("dynamic");
  msUcAny @3 $Cxx.name("ms_any");
  noUcThrow @4 $Cxx.name("no_throw");
  basicUcNoexcept @5 $Cxx.name("basic_noexcept");
  dependentUcNoexcept @6 $Cxx.name("dependent_noexcept");
  noexceptUcFalse @7 $Cxx.name("noexcept_false");
  noexceptUcTrue @8 $Cxx.name("noexcept_true");
  unevaluated @9 $Cxx.name("unevaluated");
  uninstantiated @10 $Cxx.name("uninstantiated");
  unparsed @11 $Cxx.name("unparsed");
}

enum ExplicitSpecKind @0xd9d0a0f08007648c {
  resolvedUcFalse @0 $Cxx.name("resolved_false");
  resolvedUcTrue @1 $Cxx.name("resolved_true");
  unresolved @2 $Cxx.name("unresolved");
}

enum ExprDependence @0xb34e9e74770b1892 {
  unexpandedUcPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  type @2 $Cxx.name("type");
  value @3 $Cxx.name("value");
  error @4 $Cxx.name("error");
  none @5 $Cxx.name("none");
  all @6 $Cxx.name("all");
  typeUcValue @7 $Cxx.name("type_value");
  typeUcInstantiation @8 $Cxx.name("type_instantiation");
  valueUcInstantiation @9 $Cxx.name("value_instantiation");
  typeUcValueUcInstantiation @10 $Cxx.name("type_value_instantiation");
  errorUcDependent @11 $Cxx.name("error_dependent");
}

enum ExprObjectKind @0xf9211f9356023995 {
  ordinary @0 $Cxx.name("ordinary");
  bitUcField @1 $Cxx.name("bit_field");
  vectorUcComponent @2 $Cxx.name("vector_component");
  objUcCUcProperty @3 $Cxx.name("obj_c_property");
  objUcCUcSubscript @4 $Cxx.name("obj_c_subscript");
  matrixUcComponent @5 $Cxx.name("matrix_component");
}

enum ExprOffsets @0xbd73e54b08c98af9 {
  allocator @0 $Cxx.name("allocator");
  allocatorUcTraits @1 $Cxx.name("allocator_traits");
  total @2 $Cxx.name("total");
}

enum ExprValueKind @0xb10e40f0a807354a {
  prUcValue @0 $Cxx.name("pr_value");
  lUcValue @1 $Cxx.name("l_value");
  xUcValue @2 $Cxx.name("x_value");
}

enum ExpressionTrait @0xc0206beabf974c92 {
  isUcLUcValueUcExpression @0 $Cxx.name("is_l_value_expression");
  isUcRUcValueUcExpression @1 $Cxx.name("is_r_value_expression");
}

enum ExtKind @0xd611294447eb8124 {
  always @0 $Cxx.name("always");
  never @1 $Cxx.name("never");
  replyUcHazy @2 $Cxx.name("reply_hazy");
}

enum ExtendArgsKind @0xdfdce259f47bbf96 {
  extendUcTo32 @0 $Cxx.name("extend_to32");
  extendUcTo64 @1 $Cxx.name("extend_to64");
}

enum FPExceptionModeKind @0xd10dc4052db0928d {
  ignore @0 $Cxx.name("ignore");
  mayUcTrap @1 $Cxx.name("may_trap");
  strict @2 $Cxx.name("strict");
}

enum FPModeKind @0xfd73335cff2b1987 {
  off @0 $Cxx.name("off");
  on @1 $Cxx.name("on");
  fast @2 $Cxx.name("fast");
  fastUcHonorUcPragmas @3 $Cxx.name("fast_honor_pragmas");
}

enum FamilyKind @0xd065ba2fb1eb0ca8 {
  none @0 $Cxx.name("none");
  alloc @1 $Cxx.name("alloc");
  copy @2 $Cxx.name("copy");
  initializer @3 $Cxx.name("initializer");
  mutableUcCopy @4 $Cxx.name("mutable_copy");
  new @5 $Cxx.name("new");
}

enum FiniteLoopsKind @0xe7c6ec0d3ed97659 {
  language @0 $Cxx.name("language");
  always @1 $Cxx.name("always");
  never @2 $Cxx.name("never");
}

enum FramePointerKind @0xf0c60fc0c9560ac5 {
  none @0 $Cxx.name("none");
  nonUcLeaf @1 $Cxx.name("non_leaf");
  all @2 $Cxx.name("all");
}

enum GC @0x9a94d869fc1a75e8 {
  gcUcNone @0 $Cxx.name("gc_none");
  weak @1 $Cxx.name("weak");
  strong @2 $Cxx.name("strong");
}

enum GCMode @0x9152ea17e5b3f9a0 {
  nonUcGc @0 $Cxx.name("non_gc");
  gcUcOnly @1 $Cxx.name("gc_only");
  hybridUcGc @2 $Cxx.name("hybrid_gc");
}

enum GVALinkage @0x9bb9f73a64abe308 {
  internal @0 $Cxx.name("internal");
  availableUcExternally @1 $Cxx.name("available_externally");
  discardableUcOdr @2 $Cxx.name("discardable_odr");
  strongUcExternal @3 $Cxx.name("strong_external");
  strongUcOdr @4 $Cxx.name("strong_odr");
}

enum GetBuiltinTypeError @0xa22d3ea619595e5e {
  none @0 $Cxx.name("none");
  missingUcType @1 $Cxx.name("missing_type");
  missingUcStdio @2 $Cxx.name("missing_stdio");
  missing @3 $Cxx.name("missing");
  missingUcUcontext @4 $Cxx.name("missing_ucontext");
}

enum GuardArg @0xe7ff733be842e115 {
  nocf @0 $Cxx.name("nocf");
}

enum ID @0xecc2ff5d6d583342 {
  workUcGroup @0 $Cxx.name("work_group");
  device @1 $Cxx.name("device");
  allUcSvmUcDevices @2 $Cxx.name("all_svm_devices");
  subUcGroup @3 $Cxx.name("sub_group");
}

enum IdentifierInfoFlag @0x974855f046125808 {
  zeroUcArgument @0 $Cxx.name("zero_argument");
  oneUcArgument @1 $Cxx.name("one_argument");
  multiUcArgument @2 $Cxx.name("multi_argument");
  # Skipped repeat pasta::kArgumentFlags
}

enum ImbueAttribute @0xdd8ae71e2c4749bf {
  none @0 $Cxx.name("none");
  always @1 $Cxx.name("always");
  never @2 $Cxx.name("never");
  alwaysarUcG1 @3 $Cxx.name("alwaysar_g1");
}

enum ImplicitReason @0x89f711fa7c0ef6d0 {
  none @0 $Cxx.name("none");
  arcUcForbiddenUcType @1 $Cxx.name("arc_forbidden_type");
  forbiddenUcWeak @2 $Cxx.name("forbidden_weak");
  arcUcForbiddenUcConversion @3 $Cxx.name("arc_forbidden_conversion");
  arcUcInitUcReturnsUcUnrelated @4 $Cxx.name("arc_init_returns_unrelated");
  arcUcFieldUcWithUcOwnership @5 $Cxx.name("arc_field_with_ownership");
}

enum InClassInitStyle @0xfd30164f4a13d25c {
  noUcInitializer @0 $Cxx.name("no_initializer");
  copyUcInitializer @1 $Cxx.name("copy_initializer");
  listUcInitializer @2 $Cxx.name("list_initializer");
}

enum InheritedDesignatedInitializersState @0x80bfbb38bcb7d4b7 {
  unknown @0 $Cxx.name("unknown");
  inherited @1 $Cxx.name("inherited");
  notUcInherited @2 $Cxx.name("not_inherited");
}

enum InitStorageKind @0xecf08a0982b00e9c {
  noUcInitializer @0 $Cxx.name("no_initializer");
  inUcClassUcCopyUcInitializer @1 $Cxx.name("in_class_copy_initializer");
  inUcClassUcListUcInitializer @2 $Cxx.name("in_class_list_initializer");
  capturedUcVlaUcType @3 $Cxx.name("captured_vla_type");
}

enum InlineVariableDefinitionKind @0xccf5d722e580b02d {
  none @0 $Cxx.name("none");
  weak @1 $Cxx.name("weak");
  weakUcUnknown @2 $Cxx.name("weak_unknown");
  strong @3 $Cxx.name("strong");
}

enum InliningMethod @0xeed1dbfe0541b900 {
  normalUcInlining @0 $Cxx.name("normal_inlining");
  onlyUcHintUcInlining @1 $Cxx.name("only_hint_inlining");
  onlyUcAlwaysUcInlining @2 $Cxx.name("only_always_inlining");
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
  lUcValue @0 $Cxx.name("l_value");
  xUcValue @1 $Cxx.name("x_value");
  function @2 $Cxx.name("function");
  void @3 $Cxx.name("void");
  addressableUcVoid @4 $Cxx.name("addressable_void");
  duplicateUcVectorUcComponents @5 $Cxx.name("duplicate_vector_components");
  memberUcFunction @6 $Cxx.name("member_function");
  subUcObjUcCUcPropertyUcSetting @7 $Cxx.name("sub_obj_c_property_setting");
  classUcTemporary @8 $Cxx.name("class_temporary");
  arrayUcTemporary @9 $Cxx.name("array_temporary");
  objUcCUcMessageUcRUcValue @10 $Cxx.name("obj_c_message_r_value");
  prUcValue @11 $Cxx.name("pr_value");
}

enum LambdaCaptureDefault @0xc5ffb9f76dbfab4d {
  none @0 $Cxx.name("none");
  byUcCopy @1 $Cxx.name("by_copy");
  byUcReference @2 $Cxx.name("by_reference");
}

enum LambdaCaptureKind @0xa68f8e856ba4e11d {
  this @0 $Cxx.name("this");
  starUcThis @1 $Cxx.name("star_this");
  byUcCopy @2 $Cxx.name("by_copy");
  byUcReference @3 $Cxx.name("by_reference");
  vlaUcType @4 $Cxx.name("vla_type");
}

enum LangAS @0xbe9184d23b40adbf {
  default @0 $Cxx.name("default");
  openclUcGlobal @1 $Cxx.name("opencl_global");
  openclUcLocal @2 $Cxx.name("opencl_local");
  openclUcConstant @3 $Cxx.name("opencl_constant");
  openclUcPrivate @4 $Cxx.name("opencl_private");
  openclUcGeneric @5 $Cxx.name("opencl_generic");
  openclUcGlobalUcDevice @6 $Cxx.name("opencl_global_device");
  openclUcGlobalUcHost @7 $Cxx.name("opencl_global_host");
  cudaUcDevice @8 $Cxx.name("cuda_device");
  cudaUcConstant @9 $Cxx.name("cuda_constant");
  cudaUcShared @10 $Cxx.name("cuda_shared");
  syclUcGlobal @11 $Cxx.name("sycl_global");
  syclUcGlobalUcDevice @12 $Cxx.name("sycl_global_device");
  syclUcGlobalUcHost @13 $Cxx.name("sycl_global_host");
  syclUcLocal @14 $Cxx.name("sycl_local");
  syclUcPrivate @15 $Cxx.name("sycl_private");
  ptr32UcSptr @16 $Cxx.name("ptr32_sptr");
  ptr32UcUptr @17 $Cxx.name("ptr32_uptr");
  ptr64 @18 $Cxx.name("ptr64");
}

enum LangFeatures @0x9d065077a2c3ac3d {
  lineUcComment @0 $Cxx.name("line_comment");
  c99 @1 $Cxx.name("c99");
  c11 @2 $Cxx.name("c11");
  c17 @3 $Cxx.name("c17");
  c2UcX @4 $Cxx.name("c2_x");
  cUcPlusUcPlus @5 $Cxx.name("c_plus_plus");
  cUcPlusUcPlus11 @6 $Cxx.name("c_plus_plus11");
  cUcPlusUcPlus14 @7 $Cxx.name("c_plus_plus14");
  cUcPlusUcPlus17 @8 $Cxx.name("c_plus_plus17");
  cUcPlusUcPlus20 @9 $Cxx.name("c_plus_plus20");
  cUcPlusUcPlus2UcB @10 $Cxx.name("c_plus_plus2_b");
  digraphs @11 $Cxx.name("digraphs");
  gnuUcMode @12 $Cxx.name("gnu_mode");
  hexUcFloat @13 $Cxx.name("hex_float");
  implicitUcInt @14 $Cxx.name("implicit_int");
  openUcCl @15 $Cxx.name("open_cl");
}

enum Language @0xf4615837a299503e {
  unknown @0 $Cxx.name("unknown");
  assembly @1 $Cxx.name("assembly");
  llvmir @2 $Cxx.name("llvmir");
  c @3 $Cxx.name("c");
  cxx @4 $Cxx.name("cxx");
  objUcC @5 $Cxx.name("obj_c");
  objUcCxx @6 $Cxx.name("obj_cxx");
  openUcCl @7 $Cxx.name("open_cl");
  openUcClcxx @8 $Cxx.name("open_clcxx");
  cuda @9 $Cxx.name("cuda");
  renderUcScript @10 $Cxx.name("render_script");
  hip @11 $Cxx.name("hip");
}

enum LanguageLinkage @0xa1e45a6941f17018 {
  cUcLanguageUcLinkage @0 $Cxx.name("c_language_linkage");
  cxxUcLanguageUcLinkage @1 $Cxx.name("cxx_language_linkage");
  noUcLanguageUcLinkage @2 $Cxx.name("no_language_linkage");
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
  noUcLinkage @0 $Cxx.name("no_linkage");
  internalUcLinkage @1 $Cxx.name("internal_linkage");
  uniqueUcExternalUcLinkage @2 $Cxx.name("unique_external_linkage");
  visibleUcNoUcLinkage @3 $Cxx.name("visible_no_linkage");
  moduleUcInternalUcLinkage @4 $Cxx.name("module_internal_linkage");
  moduleUcLinkage @5 $Cxx.name("module_linkage");
  externalUcLinkage @6 $Cxx.name("external_linkage");
}

enum LoopHintState @0xcb899bf31e9a23a1 {
  enable @0 $Cxx.name("enable");
  disable @1 $Cxx.name("disable");
  numeric @2 $Cxx.name("numeric");
  fixedUcWidth @3 $Cxx.name("fixed_width");
  scalableUcWidth @4 $Cxx.name("scalable_width");
  assumeUcSafety @5 $Cxx.name("assume_safety");
  full @6 $Cxx.name("full");
}

enum MSInheritanceModel @0x9e63c392cec08405 {
  single @0 $Cxx.name("single");
  multiple @1 $Cxx.name("multiple");
  virtual @2 $Cxx.name("virtual");
  unspecified @3 $Cxx.name("unspecified");
}

enum MSVCMajorVersion @0x95c4e85c8b049651 {
  msvUcC2010 @0 $Cxx.name("msv_c2010");
  msvUcC2012 @1 $Cxx.name("msv_c2012");
  msvUcC2013 @2 $Cxx.name("msv_c2013");
  msvUcC2015 @3 $Cxx.name("msv_c2015");
  msvUcC2017 @4 $Cxx.name("msv_c2017");
  msvUcC20175 @5 $Cxx.name("msv_c20175");
  msvUcC20177 @6 $Cxx.name("msv_c20177");
  msvUcC2019 @7 $Cxx.name("msv_c2019");
  msvUcC20198 @8 $Cxx.name("msv_c20198");
}

enum MSVtorDispMode @0xd30e950dab28014f {
  never @0 $Cxx.name("never");
  forUcVirtualUcBaseUcOverride @1 $Cxx.name("for_virtual_base_override");
  forUcVfUcTable @2 $Cxx.name("for_vf_table");
}

enum MapTypeTy @0xa12c4931ebd969e4 {
  to @0 $Cxx.name("to");
  link @1 $Cxx.name("link");
}

enum MethodRefFlags @0xf4e25430af1260cc {
  methodUcReferenceUcNone @0 $Cxx.name("method_reference_none");
  methodUcReferenceUcGetter @1 $Cxx.name("method_reference_getter");
  methodUcReferenceUcSetter @2 $Cxx.name("method_reference_setter");
}

enum ModifiableType @0xc45afde4959d91fe {
  untested @0 $Cxx.name("untested");
  modifiable @1 $Cxx.name("modifiable");
  rUcValue @2 $Cxx.name("r_value");
  function @3 $Cxx.name("function");
  lUcValueUcCast @4 $Cxx.name("l_value_cast");
  noUcSetterUcProperty @5 $Cxx.name("no_setter_property");
  constUcQualified @6 $Cxx.name("const_qualified");
  constUcQualifiedUcField @7 $Cxx.name("const_qualified_field");
  constUcAddrUcSpace @8 $Cxx.name("const_addr_space");
  arrayUcType @9 $Cxx.name("array_type");
  incompleteUcType @10 $Cxx.name("incomplete_type");
}

enum MultiVersionKind @0xd6aa1ba55a8d79af {
  none @0 $Cxx.name("none");
  target @1 $Cxx.name("target");
  cpuUcSpecific @2 $Cxx.name("cpu_specific");
  cpuUcDispatch @3 $Cxx.name("cpu_dispatch");
}

enum NameKind @0xd8c87b12039cdd9d {
  template @0 $Cxx.name("template");
  overloadedUcTemplate @1 $Cxx.name("overloaded_template");
  assumedUcTemplate @2 $Cxx.name("assumed_template");
  qualifiedUcTemplate @3 $Cxx.name("qualified_template");
  dependentUcTemplate @4 $Cxx.name("dependent_template");
  substUcTemplateUcTemplateUcParm @5 $Cxx.name("subst_template_template_parm");
  substUcTemplateUcTemplateUcParmUcPack @6 $Cxx.name("subst_template_template_parm_pack");
}

enum NeedExtraManglingDecl @0xabe9f759c85ffd44 {
  needUcExtraUcManglingUcDeclaration @0 $Cxx.name("need_extra_mangling_declaration");
}

enum NestedNameSpecifierDependence @0xb58b426c7eb181ac {
  unexpandedUcPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  error @3 $Cxx.name("error");
  none @4 $Cxx.name("none");
  dependentUcInstantiation @5 $Cxx.name("dependent_instantiation");
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
  objUcCUcInterface @0 $Cxx.name("obj_c_interface");
}

enum NullabilityKind @0xa6da973fb1968963 {
  nonUcNull @0 $Cxx.name("non_null");
  nullable @1 $Cxx.name("nullable");
  unspecified @2 $Cxx.name("unspecified");
  nullableUcResult @3 $Cxx.name("nullable_result");
}

enum ObjCBridgeCastKind @0xfe79ee651274349f {
  bridge @0 $Cxx.name("bridge");
  bridgeUcTransfer @1 $Cxx.name("bridge_transfer");
  bridgeUcRetained @2 $Cxx.name("bridge_retained");
}

enum ObjCDispatchMethodKind @0xa708d587fb93a359 {
  legacy @0 $Cxx.name("legacy");
  nonUcLegacy @1 $Cxx.name("non_legacy");
  mixed @2 $Cxx.name("mixed");
}

enum ObjCInstanceTypeFamily @0xae0101c36e5b5d4f {
  none @0 $Cxx.name("none");
  array @1 $Cxx.name("array");
  dictionary @2 $Cxx.name("dictionary");
  singleton @3 $Cxx.name("singleton");
  initializer @4 $Cxx.name("initializer");
  returnsUcSelf @5 $Cxx.name("returns_self");
}

enum ObjCKeywordKind @0x994b0b2bc1ef881d {
  notUcKeyword @0 $Cxx.name("not_keyword");
  class @1 $Cxx.name("class");
  compatibilityUcAlias @2 $Cxx.name("compatibility_alias");
  definitions @3 $Cxx.name("definitions");
  encode @4 $Cxx.name("encode");
  objcUcEnd @5 $Cxx.name("objc_end");
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
  explicitUcNone @1 $Cxx.name("explicit_none");
  strong @2 $Cxx.name("strong");
  weak @3 $Cxx.name("weak");
  autoreleasing @4 $Cxx.name("autoreleasing");
}

enum ObjCMethodFamily @0xce49434a6017454c {
  none @0 $Cxx.name("none");
  alloc @1 $Cxx.name("alloc");
  copy @2 $Cxx.name("copy");
  initializer @3 $Cxx.name("initializer");
  mutableUcCopy @4 $Cxx.name("mutable_copy");
  new @5 $Cxx.name("new");
  autorelease @6 $Cxx.name("autorelease");
  dealloc @7 $Cxx.name("dealloc");
  finalize @8 $Cxx.name("finalize");
  release @9 $Cxx.name("release");
  retain @10 $Cxx.name("retain");
  retainUcCount @11 $Cxx.name("retain_count");
  self @12 $Cxx.name("self");
  initialize @13 $Cxx.name("initialize");
  performUcSelector @14 $Cxx.name("perform_selector");
}

enum ObjCPropertyQueryKind @0xa276e57d28cfccfe {
  queryUcUnknown @0 $Cxx.name("query_unknown");
  queryUcInstance @1 $Cxx.name("query_instance");
  queryUcClass @2 $Cxx.name("query_class");
}

enum ObjCStringFormatFamily @0xdde65f902899f0f0 {
  none @0 $Cxx.name("none");
  nsUcString @1 $Cxx.name("ns_string");
  cfUcString @2 $Cxx.name("cf_string");
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
  onUcStack @0 $Cxx.name("on_stack");
}

enum OpenMPAtomicDefaultMemOrderClauseKind @0xa615f421034ff656 {
  seqUcCst @0 $Cxx.name("seq_cst");
  acqUcRel @1 $Cxx.name("acq_rel");
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
  deviceUcNum @1 $Cxx.name("device_num");
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
  motionmodifierUcMapper @0 $Cxx.name("motionmodifier_mapper");
  motionmodifierUcPresent @1 $Cxx.name("motionmodifier_present");
  motionmodifierUcUnknown @2 $Cxx.name("motionmodifier_unknown");
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
  vectorizeUcWidth @1 $Cxx.name("vectorize_width");
  interleave @2 $Cxx.name("interleave");
  interleaveUcCount @3 $Cxx.name("interleave_count");
  unroll @4 $Cxx.name("unroll");
  unrollUcCount @5 $Cxx.name("unroll_count");
  unrollUcAndUcJam @6 $Cxx.name("unroll_and_jam");
  unrollUcAndUcJamUcCount @7 $Cxx.name("unroll_and_jam_count");
  pipelineUcDisabled @8 $Cxx.name("pipeline_disabled");
  pipelineUcInitiationUcInterval @9 $Cxx.name("pipeline_initiation_interval");
  distribute @10 $Cxx.name("distribute");
  vectorizeUcPredicate @11 $Cxx.name("vectorize_predicate");
}

enum OverloadedOperatorKind @0x899b59d4c33ece1a {
  none @0 $Cxx.name("none");
  new @1 $Cxx.name("new");
  delete @2 $Cxx.name("delete");
  arrayUcNew @3 $Cxx.name("array_new");
  arrayUcDelete @4 $Cxx.name("array_delete");
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
  plusUcEqual @18 $Cxx.name("plus_equal");
  minusUcEqual @19 $Cxx.name("minus_equal");
  starUcEqual @20 $Cxx.name("star_equal");
  slashUcEqual @21 $Cxx.name("slash_equal");
  percentUcEqual @22 $Cxx.name("percent_equal");
  caretUcEqual @23 $Cxx.name("caret_equal");
  ampUcEqual @24 $Cxx.name("amp_equal");
  pipeUcEqual @25 $Cxx.name("pipe_equal");
  lessUcLess @26 $Cxx.name("less_less");
  greaterUcGreater @27 $Cxx.name("greater_greater");
  lessUcLessUcEqual @28 $Cxx.name("less_less_equal");
  greaterUcGreaterUcEqual @29 $Cxx.name("greater_greater_equal");
  equalUcEqual @30 $Cxx.name("equal_equal");
  exclaimUcEqual @31 $Cxx.name("exclaim_equal");
  lessUcEqual @32 $Cxx.name("less_equal");
  greaterUcEqual @33 $Cxx.name("greater_equal");
  spaceship @34 $Cxx.name("spaceship");
  ampUcAmp @35 $Cxx.name("amp_amp");
  pipeUcPipe @36 $Cxx.name("pipe_pipe");
  plusUcPlus @37 $Cxx.name("plus_plus");
  minusUcMinus @38 $Cxx.name("minus_minus");
  comma @39 $Cxx.name("comma");
  arrowUcStar @40 $Cxx.name("arrow_star");
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
  notUcKeyword @0 $Cxx.name("not_keyword");
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
  ucUcIncludeUcMacros @11 $Cxx.name("__include_macros");
  define @12 $Cxx.name("define");
  undef @13 $Cxx.name("undef");
  line @14 $Cxx.name("line");
  error @15 $Cxx.name("error");
  pragma @16 $Cxx.name("pragma");
  import @17 $Cxx.name("import");
  includeUcNext @18 $Cxx.name("include_next");
  warning @19 $Cxx.name("warning");
  identifier @20 $Cxx.name("identifier");
  sccs @21 $Cxx.name("sccs");
  assert @22 $Cxx.name("assert");
  unassert @23 $Cxx.name("unassert");
  ucUcPublicUcMacro @24 $Cxx.name("__public_macro");
  ucUcPrivateUcMacro @25 $Cxx.name("__private_macro");
}

enum ParameterABI @0xd71450dc2327753a {
  ordinary @0 $Cxx.name("ordinary");
  swiftUcIndirectUcResult @1 $Cxx.name("swift_indirect_result");
  swiftUcErrorUcResult @2 $Cxx.name("swift_error_result");
  swiftUcContext @3 $Cxx.name("swift_context");
  swiftUcAsyncUcContext @4 $Cxx.name("swift_async_context");
}

enum ParenLocsOffsets @0xeee42a89fc6e7409 {
  lUcParen @0 $Cxx.name("l_paren");
  rUcParen @1 $Cxx.name("r_paren");
  total @2 $Cxx.name("total");
}

enum PragmaFloatControlKind @0xc8a5f773a4e7a749 {
  unknown @0 $Cxx.name("unknown");
  precise @1 $Cxx.name("precise");
  noUcPrecise @2 $Cxx.name("no_precise");
  except @3 $Cxx.name("except");
  noUcExcept @4 $Cxx.name("no_except");
  push @5 $Cxx.name("push");
  pop @6 $Cxx.name("pop");
}

enum PragmaMSCommentKind @0xe09b297844ff08bb {
  unknown @0 $Cxx.name("unknown");
  linker @1 $Cxx.name("linker");
  lib @2 $Cxx.name("lib");
  compiler @3 $Cxx.name("compiler");
  exeUcString @4 $Cxx.name("exe_string");
  user @5 $Cxx.name("user");
}

enum PragmaMSPointersToMembersKind @0xbadad4917533bd3c {
  bestUcCase @0 $Cxx.name("best_case");
  fullUcGeneralityUcSingleUcInheritance @1 $Cxx.name("full_generality_single_inheritance");
  fullUcGeneralityUcMultipleUcInheritance @2 $Cxx.name("full_generality_multiple_inheritance");
  fullUcGeneralityUcVirtualUcInheritance @3 $Cxx.name("full_generality_virtual_inheritance");
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
  zeroUcInitializer @5 $Cxx.name("zero_initializer");
  invalid @6 $Cxx.name("invalid");
}

enum ProfileInstrKind @0xf19d1c8c04608ab9 {
  profileUcNone @0 $Cxx.name("profile_none");
  profileUcClangUcInstr @1 $Cxx.name("profile_clang_instr");
  profileUcIrUcInstr @2 $Cxx.name("profile_ir_instr");
  profileUcCsirUcInstr @3 $Cxx.name("profile_csir_instr");
}

enum RangeExprOffset @0x8dea69908fbb2749 {
  begin @0 $Cxx.name("begin");
  end @1 $Cxx.name("end");
  step @2 $Cxx.name("step");
  total @3 $Cxx.name("total");
}

enum RangeLocOffset @0xfb9e64d9c6c761c0 {
  assignUcToken @0 $Cxx.name("assign_token");
  secondUcColonUcToken @1 $Cxx.name("second_colon_token");
  total @2 $Cxx.name("total");
}

enum RefQualifierKind @0xe49bd7951a6ae539 {
  none @0 $Cxx.name("none");
  lUcValue @1 $Cxx.name("l_value");
  rUcValue @2 $Cxx.name("r_value");
}

enum RemarkKind @0xb3388fa0a2e99dd9 {
  missing @0 $Cxx.name("missing");
  enabled @1 $Cxx.name("enabled");
  enabledUcEverything @2 $Cxx.name("enabled_everything");
  disabled @3 $Cxx.name("disabled");
  disabledUcEverything @4 $Cxx.name("disabled_everything");
  withUcPattern @5 $Cxx.name("with_pattern");
}

enum ReservedIdentifierStatus @0xd4129a1d4a376c46 {
  notUcReserved @0 $Cxx.name("not_reserved");
  startsUcWithUcUnderscoreUcAtUcGlobalUcScope @1 $Cxx.name("starts_with_underscore_at_global_scope");
  startsUcWithUcDoubleUcUnderscore @2 $Cxx.name("starts_with_double_underscore");
  startsUcWithUcUnderscoreUcFollowedUcByUcCapitalUcLetter @3 $Cxx.name("starts_with_underscore_followed_by_capital_letter");
  containsUcDoubleUcUnderscore @4 $Cxx.name("contains_double_underscore");
}

enum SFINAEResponse @0xdb0cea818b80588c {
  substitutionUcFailure @0 $Cxx.name("substitution_failure");
  suppress @1 $Cxx.name("suppress");
  report @2 $Cxx.name("report");
  accessUcControl @3 $Cxx.name("access_control");
}

enum SYCLMajorVersion @0xa2f704290d385caa {
  versionUcNone @0 $Cxx.name("version_none");
  version2017 @1 $Cxx.name("version2017");
  version2020 @2 $Cxx.name("version2020");
  # Skipped repeat pasta::kDefault
}

enum SanitizerOrdinal @0xff7feae60091ee8e {
  address @0 $Cxx.name("address");
  pointerUcCompare @1 $Cxx.name("pointer_compare");
  pointerUcSubtract @2 $Cxx.name("pointer_subtract");
  kernelUcAddress @3 $Cxx.name("kernel_address");
  hwUcAddress @4 $Cxx.name("hw_address");
  kernelUcHwUcAddress @5 $Cxx.name("kernel_hw_address");
  memoryUcTag @6 $Cxx.name("memory_tag");
  memory @7 $Cxx.name("memory");
  kernelUcMemory @8 $Cxx.name("kernel_memory");
  fuzzer @9 $Cxx.name("fuzzer");
  fuzzerUcNoUcLink @10 $Cxx.name("fuzzer_no_link");
  thread @11 $Cxx.name("thread");
  leak @12 $Cxx.name("leak");
  alignment @13 $Cxx.name("alignment");
  arrayUcBounds @14 $Cxx.name("array_bounds");
  boolean @15 $Cxx.name("boolean");
  builtin @16 $Cxx.name("builtin");
  enum @17 $Cxx.name("enum");
  floatUcCastUcOverflow @18 $Cxx.name("float_cast_overflow");
  floatUcDivideUcByUcZero @19 $Cxx.name("float_divide_by_zero");
  function @20 $Cxx.name("function");
  integerUcDivideUcByUcZero @21 $Cxx.name("integer_divide_by_zero");
  nonnullUcAttribute @22 $Cxx.name("nonnull_attribute");
  null @23 $Cxx.name("null__");
  nullabilityUcArgument @24 $Cxx.name("nullability_argument");
  nullabilityUcAssign @25 $Cxx.name("nullability_assign");
  nullabilityUcReturn @26 $Cxx.name("nullability_return");
  nullabilityUcGroup @27 $Cxx.name("nullability_group");
  objectUcSize @28 $Cxx.name("object_size");
  pointerUcOverflow @29 $Cxx.name("pointer_overflow");
  return @30 $Cxx.name("return");
  returnsUcNonnullUcAttribute @31 $Cxx.name("returns_nonnull_attribute");
  shiftUcBase @32 $Cxx.name("shift_base");
  shiftUcExponent @33 $Cxx.name("shift_exponent");
  shiftUcGroup @34 $Cxx.name("shift_group");
  signedUcIntegerUcOverflow @35 $Cxx.name("signed_integer_overflow");
  unreachable @36 $Cxx.name("unreachable");
  vlaUcBound @37 $Cxx.name("vla_bound");
  vptr @38 $Cxx.name("vptr");
  unsignedUcIntegerUcOverflow @39 $Cxx.name("unsigned_integer_overflow");
  unsignedUcShiftUcBase @40 $Cxx.name("unsigned_shift_base");
  dataUcFlow @41 $Cxx.name("data_flow");
  cfiUcCastUcStrict @42 $Cxx.name("cfi_cast_strict");
  cfiUcDerivedUcCast @43 $Cxx.name("cfi_derived_cast");
  cfiiUcCall @44 $Cxx.name("cfii_call");
  cfimfUcCall @45 $Cxx.name("cfimf_call");
  cfiUcUnrelatedUcCast @46 $Cxx.name("cfi_unrelated_cast");
  cfinvUcCall @47 $Cxx.name("cfinv_call");
  cfivUcCall @48 $Cxx.name("cfiv_call");
  cfiUcGroup @49 $Cxx.name("cfi_group");
  safeUcStack @50 $Cxx.name("safe_stack");
  shadowUcCallUcStack @51 $Cxx.name("shadow_call_stack");
  undefinedUcGroup @52 $Cxx.name("undefined_group");
  undefinedUcTrapUcGroup @53 $Cxx.name("undefined_trap_group");
  implicitUcUnsignedUcIntegerUcTruncation @54 $Cxx.name("implicit_unsigned_integer_truncation");
  implicitUcSignedUcIntegerUcTruncation @55 $Cxx.name("implicit_signed_integer_truncation");
  implicitUcIntegerUcTruncationUcGroup @56 $Cxx.name("implicit_integer_truncation_group");
  implicitUcIntegerUcSignUcChange @57 $Cxx.name("implicit_integer_sign_change");
  implicitUcIntegerUcArithmeticUcValueUcChangeUcGroup @58 $Cxx.name("implicit_integer_arithmetic_value_change_group");
  objUcCUcCast @59 $Cxx.name("obj_c_cast");
  implicitUcConversionUcGroup @60 $Cxx.name("implicit_conversion_group");
  integerUcGroup @61 $Cxx.name("integer_group");
  localUcBounds @62 $Cxx.name("local_bounds");
  boundsUcGroup @63 $Cxx.name("bounds_group");
  scudo @64 $Cxx.name("scudo");
  allUcGroup @65 $Cxx.name("all_group");
  count @66 $Cxx.name("count");
}

enum SelectorLocationsKind @0xd0f319ff56604d2e {
  nonUcStandard @0 $Cxx.name("non_standard");
  standardUcNoUcSpace @1 $Cxx.name("standard_no_space");
  standardUcWithUcSpace @2 $Cxx.name("standard_with_space");
}

enum SignReturnAddressKeyKind @0xbb405a4adf266b91 {
  aUcKey @0 $Cxx.name("a_key");
  bUcKey @1 $Cxx.name("b_key");
}

enum SignReturnAddressScopeKind @0xbb64d86408f6c857 {
  none @0 $Cxx.name("none");
  nonUcLeaf @1 $Cxx.name("non_leaf");
  all @2 $Cxx.name("all");
}

enum SignedOverflowBehaviorTy @0xf8fa6a5b5e06e1ba {
  undefined @0 $Cxx.name("undefined");
  defined @1 $Cxx.name("defined");
  trapping @2 $Cxx.name("trapping");
}

enum SpecialMemberFlags @0xad56be604aa3d69a {
  defaultUcConstructor @0 $Cxx.name("default_constructor");
  copyUcConstructor @1 $Cxx.name("copy_constructor");
  moveUcConstructor @2 $Cxx.name("move_constructor");
  copyUcAssignment @3 $Cxx.name("copy_assignment");
  moveUcAssignment @4 $Cxx.name("move_assignment");
  destructor @5 $Cxx.name("destructor");
  all @6 $Cxx.name("all");
}

enum SpecifierKind @0xa0dfdbbf2ab2d652 {
  identifier @0 $Cxx.name("identifier");
  namespace @1 $Cxx.name("namespace");
  namespaceUcAlias @2 $Cxx.name("namespace_alias");
  typeUcSpec @3 $Cxx.name("type_spec");
  typeUcSpecUcWithUcTemplate @4 $Cxx.name("type_spec_with_template");
  global @5 $Cxx.name("global");
  super @6 $Cxx.name("super");
}

enum Spelling @0xf75ee4f457170972 {
  gnuUcAarch64UcVectorUcPcs @0 $Cxx.name("gnu_aarch64_vector_pcs");
  cxUcX11UcClangUcAarch64UcVectorUcPcs @1 $Cxx.name("cx_x11_clang_aarch64_vector_pcs");
  c2UcXclangUcAarch64UcVectorUcPcs @2 $Cxx.name("c2_xclang_aarch64_vector_pcs");
  spellingUcNotUcCalculated @3 $Cxx.name("spelling_not_calculated");
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
  privateUcExtern @3 $Cxx.name("private_extern");
  auto @4 $Cxx.name("auto");
  register @5 $Cxx.name("register");
}

enum StorageDuration @0xe1a5462cfd90bc60 {
  fullUcExpression @0 $Cxx.name("full_expression");
  automatic @1 $Cxx.name("automatic");
  thread @2 $Cxx.name("thread");
  static @3 $Cxx.name("static");
  dynamic @4 $Cxx.name("dynamic");
}

enum StoredNameKind @0xc3f93be84426e780 {
  storedUcIdentifier @0 $Cxx.name("stored_identifier");
  storedUcObjUcCUcZeroUcArgumentUcSelector @1 $Cxx.name("stored_obj_c_zero_argument_selector");
  storedUcObjUcCUcOneUcArgumentUcSelector @2 $Cxx.name("stored_obj_c_one_argument_selector");
  storedUcCxxUcConstructorUcName @3 $Cxx.name("stored_cxx_constructor_name");
  storedUcCxxUcDestructorUcName @4 $Cxx.name("stored_cxx_destructor_name");
  storedUcCxxUcConversionUcFunctionUcName @5 $Cxx.name("stored_cxx_conversion_function_name");
  storedUcCxxUcOperatorUcName @6 $Cxx.name("stored_cxx_operator_name");
  storedUcDeclarationUcNameUcExtra @7 $Cxx.name("stored_declaration_name_extra");
  # Skipped repeat pasta::kPointerMask
  uncommonUcNameUcKindUcOffset @8 $Cxx.name("uncommon_name_kind_offset");
}

enum StoredSpecifierKind @0xee14b80df2376eb6 {
  storedUcIdentifier @0 $Cxx.name("stored_identifier");
  storedUcDeclaration @1 $Cxx.name("stored_declaration");
  storedUcTypeUcSpec @2 $Cxx.name("stored_type_spec");
  storedUcTypeUcSpecUcWithUcTemplate @3 $Cxx.name("stored_type_spec_with_template");
}

enum StructReturnConventionKind @0x92e3ba5b6fbf9355 {
  default @0 $Cxx.name("default");
  onUcStack @1 $Cxx.name("on_stack");
  inUcRegs @2 $Cxx.name("in_regs");
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
  initializerUcSuspend @2 $Cxx.name("initializer_suspend");
  finalUcSuspend @3 $Cxx.name("final_suspend");
  onUcException @4 $Cxx.name("on_exception");
  onUcFallthrough @5 $Cxx.name("on_fallthrough");
  allocate @6 $Cxx.name("allocate");
  deallocate @7 $Cxx.name("deallocate");
  returnUcValue @8 $Cxx.name("return_value");
  resultUcDeclaration @9 $Cxx.name("result_declaration");
  returnUcStatement @10 $Cxx.name("return_statement");
  returnUcStatementUcOnUcAllocUcFailure @11 $Cxx.name("return_statement_on_alloc_failure");
}

enum SyncScope @0xa360f2801c53e118 {
  openUcClUcWorkUcGroup @0 $Cxx.name("open_cl_work_group");
  openUcClUcDevice @1 $Cxx.name("open_cl_device");
  openUcClUcAllUcSvmUcDevices @2 $Cxx.name("open_cl_all_svm_devices");
  openUcClUcSubUcGroup @3 $Cxx.name("open_cl_sub_group");
}

enum Syntax @0xfabc370c94a4c08b {
  gnu @0 $Cxx.name("gnu");
  cxUcX11 @1 $Cxx.name("cx_x11");
  c2UcX @2 $Cxx.name("c2_x");
  declspec @3 $Cxx.name("declspec");
  microsoft @4 $Cxx.name("microsoft");
  keyword @5 $Cxx.name("keyword");
  pragma @6 $Cxx.name("pragma");
  contextUcSensitiveUcKeyword @7 $Cxx.name("context_sensitive_keyword");
}

enum TLSModel @0xe03f72019c3fce6b {
  generalUcDynamicUcTlsUcModel @0 $Cxx.name("general_dynamic_tls_model");
  localUcDynamicUcTlsUcModel @1 $Cxx.name("local_dynamic_tls_model");
  initialUcExecUcTlsUcModel @2 $Cxx.name("initial_exec_tls_model");
  localUcExecUcTlsUcModel @3 $Cxx.name("local_exec_tls_model");
}

enum TQ @0xcc22be3ea9b39aac {
  const @0 $Cxx.name("const");
  restrict @1 $Cxx.name("restrict");
  volatile @2 $Cxx.name("volatile");
  cvrUcMask @3 $Cxx.name("cvr_mask");
}

enum TagTypeKind @0xbfa845fcdbd00864 {
  struct @0 $Cxx.name("struct");
  interface @1 $Cxx.name("interface");
  union @2 $Cxx.name("union");
  class @3 $Cxx.name("class");
  enum @4 $Cxx.name("enum");
}

enum TailPaddingUseRules @0xde3a19dc88518d95 {
  alwaysUcUseUcTailUcPadding @0 $Cxx.name("always_use_tail_padding");
  useUcTailUcPaddingUcUnlessUcPoUcD03 @1 $Cxx.name("use_tail_padding_unless_po_d03");
  useUcTailUcPaddingUcUnlessUcPoUcD11 @2 $Cxx.name("use_tail_padding_unless_po_d11");
}

enum TemplateArgumentDependence @0x97cee4d7054bd6cf {
  unexpandedUcPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  error @3 $Cxx.name("error");
  none @4 $Cxx.name("none");
  dependentUcInstantiation @5 $Cxx.name("dependent_instantiation");
  all @6 $Cxx.name("all");
}

enum TemplateNameDependence @0xb934bbc3751c811e {
  unexpandedUcPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  error @3 $Cxx.name("error");
  none @4 $Cxx.name("none");
  dependentUcInstantiation @5 $Cxx.name("dependent_instantiation");
  all @6 $Cxx.name("all");
}

enum TemplateSpecializationKind @0xc45c2bfe2b2d2105 {
  undeclared @0 $Cxx.name("undeclared");
  implicitUcInstantiation @1 $Cxx.name("implicit_instantiation");
  explicitUcSpecialization @2 $Cxx.name("explicit_specialization");
  explicitUcInstantiationUcDeclaration @3 $Cxx.name("explicit_instantiation_declaration");
  explicitUcInstantiationUcDefinition @4 $Cxx.name("explicit_instantiation_definition");
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
  threadUcLocal @2 $Cxx.name("thread_local");
  ucThreadUcLocal @3 $Cxx.name("_thread_local");
}

enum TokenKind @0xedc5e766e7f89f15 {
  unknown @0 $Cxx.name("unknown");
  endUcOfUcFile @1 $Cxx.name("end_of_file");
  endUcOfUcDirective @2 $Cxx.name("end_of_directive");
  codeUcCompletion @3 $Cxx.name("code_completion");
  comment @4 $Cxx.name("comment");
  identifier @5 $Cxx.name("identifier");
  whitespace @6 $Cxx.name("whitespace");
  numericUcConstant @7 $Cxx.name("numeric_constant");
  characterUcConstant @8 $Cxx.name("character_constant");
  wideUcCharacterUcConstant @9 $Cxx.name("wide_character_constant");
  utf8UcCharacterUcConstant @10 $Cxx.name("utf8_character_constant");
  utf16UcCharacterUcConstant @11 $Cxx.name("utf16_character_constant");
  utf32UcCharacterUcConstant @12 $Cxx.name("utf32_character_constant");
  stringUcLiteral @13 $Cxx.name("string_literal");
  wideUcStringUcLiteral @14 $Cxx.name("wide_string_literal");
  headerUcName @15 $Cxx.name("header_name");
  utf8UcStringUcLiteral @16 $Cxx.name("utf8_string_literal");
  utf16UcStringUcLiteral @17 $Cxx.name("utf16_string_literal");
  utf32UcStringUcLiteral @18 $Cxx.name("utf32_string_literal");
  lUcSquare @19 $Cxx.name("l_square");
  rUcSquare @20 $Cxx.name("r_square");
  lUcParenthesis @21 $Cxx.name("l_parenthesis");
  rUcParenthesis @22 $Cxx.name("r_parenthesis");
  lUcBrace @23 $Cxx.name("l_brace");
  rUcBrace @24 $Cxx.name("r_brace");
  period @25 $Cxx.name("period");
  ellipsis @26 $Cxx.name("ellipsis");
  amp @27 $Cxx.name("amp");
  ampUcAmp @28 $Cxx.name("amp_amp");
  ampUcEqual @29 $Cxx.name("amp_equal");
  star @30 $Cxx.name("star");
  starUcEqual @31 $Cxx.name("star_equal");
  plus @32 $Cxx.name("plus");
  plusUcPlus @33 $Cxx.name("plus_plus");
  plusUcEqual @34 $Cxx.name("plus_equal");
  minus @35 $Cxx.name("minus");
  arrow @36 $Cxx.name("arrow");
  minusUcMinus @37 $Cxx.name("minus_minus");
  minusUcEqual @38 $Cxx.name("minus_equal");
  tilde @39 $Cxx.name("tilde");
  exclaim @40 $Cxx.name("exclaim");
  exclaimUcEqual @41 $Cxx.name("exclaim_equal");
  slash @42 $Cxx.name("slash");
  slashUcEqual @43 $Cxx.name("slash_equal");
  percent @44 $Cxx.name("percent");
  percentUcEqual @45 $Cxx.name("percent_equal");
  less @46 $Cxx.name("less");
  lessUcLess @47 $Cxx.name("less_less");
  lessUcEqual @48 $Cxx.name("less_equal");
  lessUcLessUcEqual @49 $Cxx.name("less_less_equal");
  spaceship @50 $Cxx.name("spaceship");
  greater @51 $Cxx.name("greater");
  greaterUcGreater @52 $Cxx.name("greater_greater");
  greaterUcEqual @53 $Cxx.name("greater_equal");
  greaterUcGreaterUcEqual @54 $Cxx.name("greater_greater_equal");
  caret @55 $Cxx.name("caret");
  caretUcEqual @56 $Cxx.name("caret_equal");
  pipe @57 $Cxx.name("pipe");
  pipeUcPipe @58 $Cxx.name("pipe_pipe");
  pipeUcEqual @59 $Cxx.name("pipe_equal");
  question @60 $Cxx.name("question");
  colon @61 $Cxx.name("colon");
  semi @62 $Cxx.name("semi");
  equal @63 $Cxx.name("equal");
  equalUcEqual @64 $Cxx.name("equal_equal");
  comma @65 $Cxx.name("comma");
  hash @66 $Cxx.name("hash");
  hashUcHash @67 $Cxx.name("hash_hash");
  hashat @68 $Cxx.name("hashat");
  periodUcStar @69 $Cxx.name("period_star");
  arrowUcStar @70 $Cxx.name("arrow_star");
  colonUcColon @71 $Cxx.name("colon_colon");
  at @72 $Cxx.name("at");
  lessUcLessUcLess @73 $Cxx.name("less_less_less");
  greaterUcGreaterUcGreater @74 $Cxx.name("greater_greater_greater");
  caretcaret @75 $Cxx.name("caretcaret");
  keywordUcAuto @76 $Cxx.name("keyword_auto");
  keywordUcBreak @77 $Cxx.name("keyword_break");
  keywordUcCase @78 $Cxx.name("keyword_case");
  keywordUcCharacter @79 $Cxx.name("keyword_character");
  keywordUcConst @80 $Cxx.name("keyword_const");
  keywordUcContinue @81 $Cxx.name("keyword_continue");
  keywordUcDefault @82 $Cxx.name("keyword_default");
  keywordUcDo @83 $Cxx.name("keyword_do");
  keywordUcDouble @84 $Cxx.name("keyword_double");
  keywordUcElse @85 $Cxx.name("keyword_else");
  keywordUcEnum @86 $Cxx.name("keyword_enum");
  keywordUcExtern @87 $Cxx.name("keyword_extern");
  keywordUcFloat @88 $Cxx.name("keyword_float");
  keywordUcFor @89 $Cxx.name("keyword_for");
  keywordUcGoto @90 $Cxx.name("keyword_goto");
  keywordUcIf @91 $Cxx.name("keyword_if");
  keywordUcInline @92 $Cxx.name("keyword_inline");
  keywordUcInt @93 $Cxx.name("keyword_int");
  keywordUcUcExtUcInt @94 $Cxx.name("keyword__ext_int");
  keywordUcLong @95 $Cxx.name("keyword_long");
  keywordUcRegister @96 $Cxx.name("keyword_register");
  keywordUcRestrict @97 $Cxx.name("keyword_restrict");
  keywordUcReturn @98 $Cxx.name("keyword_return");
  keywordUcShort @99 $Cxx.name("keyword_short");
  keywordUcSigned @100 $Cxx.name("keyword_signed");
  keywordUcSizeof @101 $Cxx.name("keyword_sizeof");
  keywordUcStatic @102 $Cxx.name("keyword_static");
  keywordUcStruct @103 $Cxx.name("keyword_struct");
  keywordUcSwitch @104 $Cxx.name("keyword_switch");
  keywordUcTypedef @105 $Cxx.name("keyword_typedef");
  keywordUcUnion @106 $Cxx.name("keyword_union");
  keywordUcUnsigned @107 $Cxx.name("keyword_unsigned");
  keywordUcVoid @108 $Cxx.name("keyword_void");
  keywordUcVolatile @109 $Cxx.name("keyword_volatile");
  keywordUcWhile @110 $Cxx.name("keyword_while");
  keywordUcUcAlignas @111 $Cxx.name("keyword__alignas");
  keywordUcUcAlignof @112 $Cxx.name("keyword__alignof");
  keywordUcUcAtomic @113 $Cxx.name("keyword__atomic");
  keywordUcUcBoolean @114 $Cxx.name("keyword__boolean");
  keywordUcUcComplex @115 $Cxx.name("keyword__complex");
  keywordUcUcGeneric @116 $Cxx.name("keyword__generic");
  keywordUcUcImaginary @117 $Cxx.name("keyword__imaginary");
  keywordUcUcNoreturn @118 $Cxx.name("keyword__noreturn");
  keywordUcUcStaticUcAssert @119 $Cxx.name("keyword__static_assert");
  keywordUcUcThreadUcLocal @120 $Cxx.name("keyword__thread_local");
  keywordUcUcUcFunc @121 $Cxx.name("keyword___func__");
  keywordUcUcUcObjcUcYes @122 $Cxx.name("keyword___objc_yes");
  keywordUcUcUcObjcUcNo @123 $Cxx.name("keyword___objc_no");
  keywordUcAssembly @124 $Cxx.name("keyword_assembly");
  keywordUcBoolean @125 $Cxx.name("keyword_boolean");
  keywordUcCatch @126 $Cxx.name("keyword_catch");
  keywordUcClass @127 $Cxx.name("keyword_class");
  keywordUcConstUcCast @128 $Cxx.name("keyword_const_cast");
  keywordUcDelete @129 $Cxx.name("keyword_delete");
  keywordUcDynamicUcCast @130 $Cxx.name("keyword_dynamic_cast");
  keywordUcExplicit @131 $Cxx.name("keyword_explicit");
  keywordUcExport @132 $Cxx.name("keyword_export");
  keywordUcFalse @133 $Cxx.name("keyword_false");
  keywordUcFriend @134 $Cxx.name("keyword_friend");
  keywordUcMutable @135 $Cxx.name("keyword_mutable");
  keywordUcNamespace @136 $Cxx.name("keyword_namespace");
  keywordUcNew @137 $Cxx.name("keyword_new");
  keywordUcOperator @138 $Cxx.name("keyword_operator");
  keywordUcPrivate @139 $Cxx.name("keyword_private");
  keywordUcProtected @140 $Cxx.name("keyword_protected");
  keywordUcPublic @141 $Cxx.name("keyword_public");
  keywordUcReinterpretUcCast @142 $Cxx.name("keyword_reinterpret_cast");
  keywordUcStaticUcCast @143 $Cxx.name("keyword_static_cast");
  keywordUcTemplate @144 $Cxx.name("keyword_template");
  keywordUcThis @145 $Cxx.name("keyword_this");
  keywordUcThrow @146 $Cxx.name("keyword_throw");
  keywordUcTrue @147 $Cxx.name("keyword_true");
  keywordUcTry @148 $Cxx.name("keyword_try");
  keywordUcTypename @149 $Cxx.name("keyword_typename");
  keywordUcTypeid @150 $Cxx.name("keyword_typeid");
  keywordUcUsing @151 $Cxx.name("keyword_using");
  keywordUcVirtual @152 $Cxx.name("keyword_virtual");
  keywordUcWcharUcT @153 $Cxx.name("keyword_wchar_t");
  keywordUcAlignas @154 $Cxx.name("keyword_alignas");
  keywordUcAlignof @155 $Cxx.name("keyword_alignof");
  keywordUcChar16UcT @156 $Cxx.name("keyword_char16_t");
  keywordUcChar32UcT @157 $Cxx.name("keyword_char32_t");
  keywordUcConstexpr @158 $Cxx.name("keyword_constexpr");
  keywordUcDecltype @159 $Cxx.name("keyword_decltype");
  keywordUcNoexcept @160 $Cxx.name("keyword_noexcept");
  keywordUcNullptr @161 $Cxx.name("keyword_nullptr");
  keywordUcStaticUcAssert @162 $Cxx.name("keyword_static_assert");
  keywordUcThreadUcLocal @163 $Cxx.name("keyword_thread_local");
  keywordUcConcept @164 $Cxx.name("keyword_concept");
  keywordUcRequires @165 $Cxx.name("keyword_requires");
  keywordUcCoUcAwait @166 $Cxx.name("keyword_co_await");
  keywordUcCoUcReturn @167 $Cxx.name("keyword_co_return");
  keywordUcCoUcYield @168 $Cxx.name("keyword_co_yield");
  keywordUcModule @169 $Cxx.name("keyword_module");
  keywordUcImport @170 $Cxx.name("keyword_import");
  keywordUcConsteval @171 $Cxx.name("keyword_consteval");
  keywordUcConstinit @172 $Cxx.name("keyword_constinit");
  keywordUcChar8UcT @173 $Cxx.name("keyword_char8_t");
  keywordUcUcFloat16 @174 $Cxx.name("keyword__float16");
  keywordUcUcAccum @175 $Cxx.name("keyword__accum");
  keywordUcUcFract @176 $Cxx.name("keyword__fract");
  keywordUcUcSat @177 $Cxx.name("keyword__sat");
  keywordUcUcDecimal32 @178 $Cxx.name("keyword__decimal32");
  keywordUcUcDecimal64 @179 $Cxx.name("keyword__decimal64");
  keywordUcUcDecimal128 @180 $Cxx.name("keyword__decimal128");
  keywordUcUcUcNull @181 $Cxx.name("keyword___null");
  keywordUcUcUcAlignof @182 $Cxx.name("keyword___alignof");
  keywordUcUcUcAttribute @183 $Cxx.name("keyword___attribute");
  keywordUcUcUcBuiltinUcChooseUcExpression @184 $Cxx.name("keyword___builtin_choose_expression");
  keywordUcUcUcBuiltinUcOffsetof @185 $Cxx.name("keyword___builtin_offsetof");
  keywordUcUcUcBuiltinUcFile @186 $Cxx.name("keyword___builtin_file");
  keywordUcUcUcBuiltinUcFunction @187 $Cxx.name("keyword___builtin_function");
  keywordUcUcUcBuiltinUcLine @188 $Cxx.name("keyword___builtin_line");
  keywordUcUcUcBuiltinUcColumn @189 $Cxx.name("keyword___builtin_column");
  keywordUcUcUcBuiltinUcTypesUcCompatibleUcP @190 $Cxx.name("keyword___builtin_types_compatible_p");
  keywordUcUcUcBuiltinUcVaUcArgument @191 $Cxx.name("keyword___builtin_va_argument");
  keywordUcUcUcExtension @192 $Cxx.name("keyword___extension__");
  keywordUcUcUcFloat128 @193 $Cxx.name("keyword___float128");
  keywordUcUcUcImag @194 $Cxx.name("keyword___imag");
  keywordUcUcUcInt128 @195 $Cxx.name("keyword___int128");
  keywordUcUcUcLabel @196 $Cxx.name("keyword___label__");
  keywordUcUcUcReal @197 $Cxx.name("keyword___real");
  keywordUcUcUcThread @198 $Cxx.name("keyword___thread");
  keywordUcUcUcFunction @199 $Cxx.name("keyword___function__");
  keywordUcUcUcPrettyfunction @200 $Cxx.name("keyword___prettyfunction__");
  keywordUcUcUcAutoUcType @201 $Cxx.name("keyword___auto_type");
  keywordUcTypeof @202 $Cxx.name("keyword_typeof");
  keywordUcUcUcFuncdname @203 $Cxx.name("keyword___funcdname__");
  keywordUcUcUcFuncsig @204 $Cxx.name("keyword___funcsig__");
  keywordUcLfunction @205 $Cxx.name("keyword_lfunction__");
  keywordUcLfuncsig @206 $Cxx.name("keyword_lfuncsig__");
  keywordUcUcUcIsUcInterfaceUcClass @207 $Cxx.name("keyword___is_interface_class");
  keywordUcUcUcIsUcSealed @208 $Cxx.name("keyword___is_sealed");
  keywordUcUcUcIsUcDestructible @209 $Cxx.name("keyword___is_destructible");
  keywordUcUcUcIsUcTriviallyUcDestructible @210 $Cxx.name("keyword___is_trivially_destructible");
  keywordUcUcUcIsUcNothrowUcDestructible @211 $Cxx.name("keyword___is_nothrow_destructible");
  keywordUcUcUcIsUcNothrowUcAssignable @212 $Cxx.name("keyword___is_nothrow_assignable");
  keywordUcUcUcIsUcConstructible @213 $Cxx.name("keyword___is_constructible");
  keywordUcUcUcIsUcNothrowUcConstructible @214 $Cxx.name("keyword___is_nothrow_constructible");
  keywordUcUcUcIsUcAssignable @215 $Cxx.name("keyword___is_assignable");
  keywordUcUcUcHasUcNothrowUcMoveUcAssign @216 $Cxx.name("keyword___has_nothrow_move_assign");
  keywordUcUcUcHasUcTrivialUcMoveUcAssign @217 $Cxx.name("keyword___has_trivial_move_assign");
  keywordUcUcUcHasUcTrivialUcMoveUcConstructor @218 $Cxx.name("keyword___has_trivial_move_constructor");
  keywordUcUcUcHasUcNothrowUcAssign @219 $Cxx.name("keyword___has_nothrow_assign");
  keywordUcUcUcHasUcNothrowUcCopy @220 $Cxx.name("keyword___has_nothrow_copy");
  keywordUcUcUcHasUcNothrowUcConstructor @221 $Cxx.name("keyword___has_nothrow_constructor");
  keywordUcUcUcHasUcTrivialUcAssign @222 $Cxx.name("keyword___has_trivial_assign");
  keywordUcUcUcHasUcTrivialUcCopy @223 $Cxx.name("keyword___has_trivial_copy");
  keywordUcUcUcHasUcTrivialUcConstructor @224 $Cxx.name("keyword___has_trivial_constructor");
  keywordUcUcUcHasUcTrivialUcDestructor @225 $Cxx.name("keyword___has_trivial_destructor");
  keywordUcUcUcHasUcVirtualUcDestructor @226 $Cxx.name("keyword___has_virtual_destructor");
  keywordUcUcUcIsUcAbstract @227 $Cxx.name("keyword___is_abstract");
  keywordUcUcUcIsUcAggregate @228 $Cxx.name("keyword___is_aggregate");
  keywordUcUcUcIsUcBaseUcOf @229 $Cxx.name("keyword___is_base_of");
  keywordUcUcUcIsUcClass @230 $Cxx.name("keyword___is_class");
  keywordUcUcUcIsUcConvertibleUcTo @231 $Cxx.name("keyword___is_convertible_to");
  keywordUcUcUcIsUcEmpty @232 $Cxx.name("keyword___is_empty");
  keywordUcUcUcIsUcEnum @233 $Cxx.name("keyword___is_enum");
  keywordUcUcUcIsUcFinal @234 $Cxx.name("keyword___is_final");
  keywordUcUcUcIsUcLiteral @235 $Cxx.name("keyword___is_literal");
  keywordUcUcUcIsUcPod @236 $Cxx.name("keyword___is_pod");
  keywordUcUcUcIsUcPolymorphic @237 $Cxx.name("keyword___is_polymorphic");
  keywordUcUcUcIsUcStandardUcLayout @238 $Cxx.name("keyword___is_standard_layout");
  keywordUcUcUcIsUcTrivial @239 $Cxx.name("keyword___is_trivial");
  keywordUcUcUcIsUcTriviallyUcAssignable @240 $Cxx.name("keyword___is_trivially_assignable");
  keywordUcUcUcIsUcTriviallyUcConstructible @241 $Cxx.name("keyword___is_trivially_constructible");
  keywordUcUcUcIsUcTriviallyUcCopyable @242 $Cxx.name("keyword___is_trivially_copyable");
  keywordUcUcUcIsUcUnion @243 $Cxx.name("keyword___is_union");
  keywordUcUcUcHasUcUniqueUcObjectUcRepresentations @244 $Cxx.name("keyword___has_unique_object_representations");
  keywordUcUcUcUnderlyingUcType @245 $Cxx.name("keyword___underlying_type");
  keywordUcUcUcReferenceUcBindsUcToUcTemporary @246 $Cxx.name("keyword___reference_binds_to_temporary");
  keywordUcUcUcIsUcLvalueUcExpression @247 $Cxx.name("keyword___is_lvalue_expression");
  keywordUcUcUcIsUcRvalueUcExpression @248 $Cxx.name("keyword___is_rvalue_expression");
  keywordUcUcUcIsUcArithmetic @249 $Cxx.name("keyword___is_arithmetic");
  keywordUcUcUcIsUcFloatingUcPoint @250 $Cxx.name("keyword___is_floating_point");
  keywordUcUcUcIsUcIntegral @251 $Cxx.name("keyword___is_integral");
  keywordUcUcUcIsUcCompleteUcType @252 $Cxx.name("keyword___is_complete_type");
  keywordUcUcUcIsUcVoid @253 $Cxx.name("keyword___is_void");
  keywordUcUcUcIsUcArray @254 $Cxx.name("keyword___is_array");
  keywordUcUcUcIsUcFunction @255 $Cxx.name("keyword___is_function");
  keywordUcUcUcIsUcReference @256 $Cxx.name("keyword___is_reference");
  keywordUcUcUcIsUcLvalueUcReference @257 $Cxx.name("keyword___is_lvalue_reference");
  keywordUcUcUcIsUcRvalueUcReference @258 $Cxx.name("keyword___is_rvalue_reference");
  keywordUcUcUcIsUcFundamental @259 $Cxx.name("keyword___is_fundamental");
  keywordUcUcUcIsUcObject @260 $Cxx.name("keyword___is_object");
  keywordUcUcUcIsUcScalar @261 $Cxx.name("keyword___is_scalar");
  keywordUcUcUcIsUcCompound @262 $Cxx.name("keyword___is_compound");
  keywordUcUcUcIsUcPointer @263 $Cxx.name("keyword___is_pointer");
  keywordUcUcUcIsUcMemberUcObjectUcPointer @264 $Cxx.name("keyword___is_member_object_pointer");
  keywordUcUcUcIsUcMemberUcFunctionUcPointer @265 $Cxx.name("keyword___is_member_function_pointer");
  keywordUcUcUcIsUcMemberUcPointer @266 $Cxx.name("keyword___is_member_pointer");
  keywordUcUcUcIsUcConst @267 $Cxx.name("keyword___is_const");
  keywordUcUcUcIsUcVolatile @268 $Cxx.name("keyword___is_volatile");
  keywordUcUcUcIsUcSigned @269 $Cxx.name("keyword___is_signed");
  keywordUcUcUcIsUcUnsigned @270 $Cxx.name("keyword___is_unsigned");
  keywordUcUcUcIsUcSame @271 $Cxx.name("keyword___is_same");
  keywordUcUcUcIsUcConvertible @272 $Cxx.name("keyword___is_convertible");
  keywordUcUcUcArrayUcRank @273 $Cxx.name("keyword___array_rank");
  keywordUcUcUcArrayUcExtent @274 $Cxx.name("keyword___array_extent");
  keywordUcUcUcPrivateUcExtern @275 $Cxx.name("keyword___private_extern__");
  keywordUcUcUcModuleUcPrivate @276 $Cxx.name("keyword___module_private__");
  keywordUcUcUcDeclspec @277 $Cxx.name("keyword___declspec");
  keywordUcUcUcCdecl @278 $Cxx.name("keyword___cdecl");
  keywordUcUcUcStdcall @279 $Cxx.name("keyword___stdcall");
  keywordUcUcUcFastcall @280 $Cxx.name("keyword___fastcall");
  keywordUcUcUcThiscall @281 $Cxx.name("keyword___thiscall");
  keywordUcUcUcRegcall @282 $Cxx.name("keyword___regcall");
  keywordUcUcUcVectorcall @283 $Cxx.name("keyword___vectorcall");
  keywordUcUcUcForceinline @284 $Cxx.name("keyword___forceinline");
  keywordUcUcUcUnaligned @285 $Cxx.name("keyword___unaligned");
  keywordUcUcUcSuper @286 $Cxx.name("keyword___super");
  keywordUcUcUcGlobal @287 $Cxx.name("keyword___global");
  keywordUcUcUcLocal @288 $Cxx.name("keyword___local");
  keywordUcUcUcConstant @289 $Cxx.name("keyword___constant");
  keywordUcUcUcPrivate @290 $Cxx.name("keyword___private");
  keywordUcUcUcGeneric @291 $Cxx.name("keyword___generic");
  keywordUcUcUcKernel @292 $Cxx.name("keyword___kernel");
  keywordUcUcUcReadUcOnly @293 $Cxx.name("keyword___read_only");
  keywordUcUcUcWriteUcOnly @294 $Cxx.name("keyword___write_only");
  keywordUcUcUcReadUcWrite @295 $Cxx.name("keyword___read_write");
  keywordUcUcUcBuiltinUcAstype @296 $Cxx.name("keyword___builtin_astype");
  keywordUcVecUcStep @297 $Cxx.name("keyword_vec_step");
  keywordUcImage1UcDt @298 $Cxx.name("keyword_image1_dt");
  keywordUcImage1UcDarrayUcT @299 $Cxx.name("keyword_image1_darray_t");
  keywordUcImage1UcDbufferUcT @300 $Cxx.name("keyword_image1_dbuffer_t");
  keywordUcImage2UcDt @301 $Cxx.name("keyword_image2_dt");
  keywordUcImage2UcDarrayUcT @302 $Cxx.name("keyword_image2_darray_t");
  keywordUcImage2UcDdepthUcT @303 $Cxx.name("keyword_image2_ddepth_t");
  keywordUcImage2UcDarrayUcDepthUcT @304 $Cxx.name("keyword_image2_darray_depth_t");
  keywordUcImage2UcDmsaaUcT @305 $Cxx.name("keyword_image2_dmsaa_t");
  keywordUcImage2UcDarrayUcMsaaUcT @306 $Cxx.name("keyword_image2_darray_msaa_t");
  keywordUcImage2UcDmsaaUcDepthUcT @307 $Cxx.name("keyword_image2_dmsaa_depth_t");
  keywordUcImage2UcDarrayUcMsaaUcDepthUcT @308 $Cxx.name("keyword_image2_darray_msaa_depth_t");
  keywordUcImage3UcDt @309 $Cxx.name("keyword_image3_dt");
  keywordUcPipe @310 $Cxx.name("keyword_pipe");
  keywordUcAddrspaceUcCast @311 $Cxx.name("keyword_addrspace_cast");
  keywordUcUcUcBuiltinUcOmpUcRequiredUcSimdUcAlign @312 $Cxx.name("keyword___builtin_omp_required_simd_align");
  keywordUcUcUcPascal @313 $Cxx.name("keyword___pascal");
  keywordUcUcUcVector @314 $Cxx.name("keyword___vector");
  keywordUcUcUcPixel @315 $Cxx.name("keyword___pixel");
  keywordUcUcUcBoolean @316 $Cxx.name("keyword___boolean");
  keywordUcUcUcBf16 @317 $Cxx.name("keyword___bf16");
  keywordUcHalf @318 $Cxx.name("keyword_half");
  keywordUcUcUcBridge @319 $Cxx.name("keyword___bridge");
  keywordUcUcUcBridgeUcTransfer @320 $Cxx.name("keyword___bridge_transfer");
  keywordUcUcUcBridgeUcRetained @321 $Cxx.name("keyword___bridge_retained");
  keywordUcUcUcBridgeUcRetain @322 $Cxx.name("keyword___bridge_retain");
  keywordUcUcUcCovariant @323 $Cxx.name("keyword___covariant");
  keywordUcUcUcContravariant @324 $Cxx.name("keyword___contravariant");
  keywordUcUcUcKindof @325 $Cxx.name("keyword___kindof");
  keywordUcUcNonnull @326 $Cxx.name("keyword__nonnull");
  keywordUcUcNullable @327 $Cxx.name("keyword__nullable");
  keywordUcUcNullableUcResult @328 $Cxx.name("keyword__nullable_result");
  keywordUcUcNullUcUnspecified @329 $Cxx.name("keyword__null_unspecified");
  keywordUcUcUcPtr64 @330 $Cxx.name("keyword___ptr64");
  keywordUcUcUcPtr32 @331 $Cxx.name("keyword___ptr32");
  keywordUcUcUcSptr @332 $Cxx.name("keyword___sptr");
  keywordUcUcUcUptr @333 $Cxx.name("keyword___uptr");
  keywordUcUcUcW64 @334 $Cxx.name("keyword___w64");
  keywordUcUcUcUuidof @335 $Cxx.name("keyword___uuidof");
  keywordUcUcUcTry @336 $Cxx.name("keyword___try");
  keywordUcUcUcFinally @337 $Cxx.name("keyword___finally");
  keywordUcUcUcLeave @338 $Cxx.name("keyword___leave");
  keywordUcUcUcInt64 @339 $Cxx.name("keyword___int64");
  keywordUcUcUcIfUcExists @340 $Cxx.name("keyword___if_exists");
  keywordUcUcUcIfUcNotUcExists @341 $Cxx.name("keyword___if_not_exists");
  keywordUcUcUcSingleUcInheritance @342 $Cxx.name("keyword___single_inheritance");
  keywordUcUcUcMultipleUcInheritance @343 $Cxx.name("keyword___multiple_inheritance");
  keywordUcUcUcVirtualUcInheritance @344 $Cxx.name("keyword___virtual_inheritance");
  keywordUcUcUcInterface @345 $Cxx.name("keyword___interface");
  keywordUcUcUcBuiltinUcConvertvector @346 $Cxx.name("keyword___builtin_convertvector");
  keywordUcUcUcBuiltinUcBitUcCast @347 $Cxx.name("keyword___builtin_bit_cast");
  keywordUcUcUcBuiltinUcAvailable @348 $Cxx.name("keyword___builtin_available");
  keywordUcUcUcBuiltinUcSyclUcUniqueUcStableUcName @349 $Cxx.name("keyword___builtin_sycl_unique_stable_name");
  keywordUcUcUcUnknownUcAnytype @350 $Cxx.name("keyword___unknown_anytype");
  annotUcCxxscope @351 $Cxx.name("annot_cxxscope");
  annotUcTypename @352 $Cxx.name("annot_typename");
  annotUcTemplateUcId @353 $Cxx.name("annot_template_id");
  annotUcNonUcType @354 $Cxx.name("annot_non_type");
  annotUcNonUcTypeUcUndeclared @355 $Cxx.name("annot_non_type_undeclared");
  annotUcNonUcTypeUcDependent @356 $Cxx.name("annot_non_type_dependent");
  annotUcOverload @357 $Cxx.name("annot_overload");
  annotUcPrimaryUcExpression @358 $Cxx.name("annot_primary_expression");
  annotUcDecltype @359 $Cxx.name("annot_decltype");
  annotUcPragmaUcUnused @360 $Cxx.name("annot_pragma_unused");
  annotUcPragmaUcVis @361 $Cxx.name("annot_pragma_vis");
  annotUcPragmaUcPack @362 $Cxx.name("annot_pragma_pack");
  annotUcPragmaUcParserUcCrash @363 $Cxx.name("annot_pragma_parser_crash");
  annotUcPragmaUcCaptured @364 $Cxx.name("annot_pragma_captured");
  annotUcPragmaUcDump @365 $Cxx.name("annot_pragma_dump");
  annotUcPragmaUcMsstruct @366 $Cxx.name("annot_pragma_msstruct");
  annotUcPragmaUcAlign @367 $Cxx.name("annot_pragma_align");
  annotUcPragmaUcWeak @368 $Cxx.name("annot_pragma_weak");
  annotUcPragmaUcWeakalias @369 $Cxx.name("annot_pragma_weakalias");
  annotUcPragmaUcRedefineUcExtname @370 $Cxx.name("annot_pragma_redefine_extname");
  annotUcPragmaUcFpUcContract @371 $Cxx.name("annot_pragma_fp_contract");
  annotUcPragmaUcFenvUcAccess @372 $Cxx.name("annot_pragma_fenv_access");
  annotUcPragmaUcFenvUcRound @373 $Cxx.name("annot_pragma_fenv_round");
  annotUcPragmaUcFloatUcControl @374 $Cxx.name("annot_pragma_float_control");
  annotUcPragmaUcMsUcPointersUcToUcMembers @375 $Cxx.name("annot_pragma_ms_pointers_to_members");
  annotUcPragmaUcMsUcVtordisp @376 $Cxx.name("annot_pragma_ms_vtordisp");
  annotUcPragmaUcMsUcPragma @377 $Cxx.name("annot_pragma_ms_pragma");
  annotUcPragmaUcOpenclUcExtension @378 $Cxx.name("annot_pragma_opencl_extension");
  annotUcAttributeUcOpenmp @379 $Cxx.name("annot_attribute_openmp");
  annotUcPragmaUcOpenmp @380 $Cxx.name("annot_pragma_openmp");
  annotUcPragmaUcOpenmpUcEnd @381 $Cxx.name("annot_pragma_openmp_end");
  annotUcPragmaUcLoopUcHint @382 $Cxx.name("annot_pragma_loop_hint");
  annotUcPragmaUcFp @383 $Cxx.name("annot_pragma_fp");
  annotUcPragmaUcAttribute @384 $Cxx.name("annot_pragma_attribute");
  annotUcModuleUcInclude @385 $Cxx.name("annot_module_include");
  annotUcModuleUcBegin @386 $Cxx.name("annot_module_begin");
  annotUcModuleUcEnd @387 $Cxx.name("annot_module_end");
  annotUcHeaderUcUnit @388 $Cxx.name("annot_header_unit");
}

enum TrailingAllocKind @0xa00e8d253383f16f {
  takUcInheritsUcConstructor @0 $Cxx.name("tak_inherits_constructor");
  takUcHasUcTailUcExplicit @1 $Cxx.name("tak_has_tail_explicit");
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
  unexpandedUcPack @0 $Cxx.name("unexpanded_pack");
  instantiation @1 $Cxx.name("instantiation");
  dependent @2 $Cxx.name("dependent");
  variablyUcModified @3 $Cxx.name("variably_modified");
  error @4 $Cxx.name("error");
  none @5 $Cxx.name("none");
  all @6 $Cxx.name("all");
  dependentUcInstantiation @7 $Cxx.name("dependent_instantiation");
}

enum TypeLocClass @0xd26f9faf6191a9d9 {
  adjusted @0 $Cxx.name("adjusted");
  decayed @1 $Cxx.name("decayed");
  constantUcArray @2 $Cxx.name("constant_array");
  dependentUcSizedUcArray @3 $Cxx.name("dependent_sized_array");
  incompleteUcArray @4 $Cxx.name("incomplete_array");
  variableUcArray @5 $Cxx.name("variable_array");
  atomic @6 $Cxx.name("atomic");
  attributed @7 $Cxx.name("attributed");
  blockUcPointer @8 $Cxx.name("block_pointer");
  builtin @9 $Cxx.name("builtin");
  complex @10 $Cxx.name("complex");
  decltype @11 $Cxx.name("decltype");
  auto @12 $Cxx.name("auto");
  deducedUcTemplateUcSpecialization @13 $Cxx.name("deduced_template_specialization");
  dependentUcAddressUcSpace @14 $Cxx.name("dependent_address_space");
  dependentUcExtUcInt @15 $Cxx.name("dependent_ext_int");
  dependentUcName @16 $Cxx.name("dependent_name");
  dependentUcSizedUcExtUcVector @17 $Cxx.name("dependent_sized_ext_vector");
  dependentUcTemplateUcSpecialization @18 $Cxx.name("dependent_template_specialization");
  dependentUcVector @19 $Cxx.name("dependent_vector");
  elaborated @20 $Cxx.name("elaborated");
  extUcInt @21 $Cxx.name("ext_int");
  functionUcNoUcProto @22 $Cxx.name("function_no_proto");
  functionUcProto @23 $Cxx.name("function_proto");
  injectedUcClassUcName @24 $Cxx.name("injected_class_name");
  macroUcQualified @25 $Cxx.name("macro_qualified");
  constantUcMatrix @26 $Cxx.name("constant_matrix");
  dependentUcSizedUcMatrix @27 $Cxx.name("dependent_sized_matrix");
  memberUcPointer @28 $Cxx.name("member_pointer");
  objUcCUcObjectUcPointer @29 $Cxx.name("obj_c_object_pointer");
  objUcCUcObject @30 $Cxx.name("obj_c_object");
  objUcCUcInterface @31 $Cxx.name("obj_c_interface");
  objUcCUcTypeUcParam @32 $Cxx.name("obj_c_type_param");
  packUcExpansion @33 $Cxx.name("pack_expansion");
  parenthesis @34 $Cxx.name("parenthesis");
  pipe @35 $Cxx.name("pipe");
  pointer @36 $Cxx.name("pointer");
  lUcValueUcReference @37 $Cxx.name("l_value_reference");
  rUcValueUcReference @38 $Cxx.name("r_value_reference");
  substUcTemplateUcTypeUcParmUcPack @39 $Cxx.name("subst_template_type_parm_pack");
  substUcTemplateUcTypeUcParm @40 $Cxx.name("subst_template_type_parm");
  enum @41 $Cxx.name("enum");
  record @42 $Cxx.name("record");
  templateUcSpecialization @43 $Cxx.name("template_specialization");
  templateUcTypeUcParm @44 $Cxx.name("template_type_parm");
  typeUcOfUcExpression @45 $Cxx.name("type_of_expression");
  typeUcOf @46 $Cxx.name("type_of");
  typedef @47 $Cxx.name("typedef");
  unaryUcTransform @48 $Cxx.name("unary_transform");
  unresolvedUcUsing @49 $Cxx.name("unresolved_using");
  vector @50 $Cxx.name("vector");
  extUcVector @51 $Cxx.name("ext_vector");
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
  bUcFloat16 @14 $Cxx.name("b_float16");
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
  typeofUcType @28 $Cxx.name("typeof_type");
  typeofUcExpression @29 $Cxx.name("typeof_expression");
  decltype @30 $Cxx.name("decltype");
  underlyingUcType @31 $Cxx.name("underlying_type");
  auto @32 $Cxx.name("auto");
  decltypeUcAuto @33 $Cxx.name("decltype_auto");
  autoUcType @34 $Cxx.name("auto_type");
  unknownUcAnytype @35 $Cxx.name("unknown_anytype");
  atomic @36 $Cxx.name("atomic");
  image1UcDt @37 $Cxx.name("image1_dt");
  image1UcDarrayUcT @38 $Cxx.name("image1_darray_t");
  image1UcDbufferUcT @39 $Cxx.name("image1_dbuffer_t");
  image2UcDt @40 $Cxx.name("image2_dt");
  image2UcDarrayUcT @41 $Cxx.name("image2_darray_t");
  image2UcDdepthUcT @42 $Cxx.name("image2_ddepth_t");
  image2UcDarrayUcDepthUcT @43 $Cxx.name("image2_darray_depth_t");
  image2UcDmsaaUcT @44 $Cxx.name("image2_dmsaa_t");
  image2UcDarrayUcMsaaUcT @45 $Cxx.name("image2_darray_msaa_t");
  image2UcDmsaaUcDepthUcT @46 $Cxx.name("image2_dmsaa_depth_t");
  image2UcDarrayUcMsaaUcDepthUcT @47 $Cxx.name("image2_darray_msaa_depth_t");
  image3UcDt @48 $Cxx.name("image3_dt");
  error @49 $Cxx.name("error");
}

enum TypeSpecifierWidth @0xb35db4de9d1c4558 {
  unspecified @0 $Cxx.name("unspecified");
  short @1 $Cxx.name("short");
  long @2 $Cxx.name("long");
  longUcLong @3 $Cxx.name("long_long");
}

enum TypeSpecifiersPipe @0xff56fb78fb39ce87 {
  unspecified @0 $Cxx.name("unspecified");
  pipe @1 $Cxx.name("pipe");
}

enum TypeTrait @0xf7e0a1b4b1fe1e7a {
  isUcInterfaceUcClass @0 $Cxx.name("is_interface_class");
  isUcSealed @1 $Cxx.name("is_sealed");
  isUcDestructible @2 $Cxx.name("is_destructible");
  isUcTriviallyUcDestructible @3 $Cxx.name("is_trivially_destructible");
  isUcNothrowUcDestructible @4 $Cxx.name("is_nothrow_destructible");
  hasUcNothrowUcMoveUcAssign @5 $Cxx.name("has_nothrow_move_assign");
  hasUcTrivialUcMoveUcAssign @6 $Cxx.name("has_trivial_move_assign");
  hasUcTrivialUcMoveUcConstructor @7 $Cxx.name("has_trivial_move_constructor");
  hasUcNothrowUcAssign @8 $Cxx.name("has_nothrow_assign");
  hasUcNothrowUcCopy @9 $Cxx.name("has_nothrow_copy");
  hasUcNothrowUcConstructor @10 $Cxx.name("has_nothrow_constructor");
  hasUcTrivialUcAssign @11 $Cxx.name("has_trivial_assign");
  hasUcTrivialUcCopy @12 $Cxx.name("has_trivial_copy");
  hasUcTrivialUcDefaultUcConstructor @13 $Cxx.name("has_trivial_default_constructor");
  hasUcTrivialUcDestructor @14 $Cxx.name("has_trivial_destructor");
  hasUcVirtualUcDestructor @15 $Cxx.name("has_virtual_destructor");
  isUcAbstract @16 $Cxx.name("is_abstract");
  isUcAggregate @17 $Cxx.name("is_aggregate");
  isUcClass @18 $Cxx.name("is_class");
  isUcEmpty @19 $Cxx.name("is_empty");
  isUcEnum @20 $Cxx.name("is_enum");
  isUcFinal @21 $Cxx.name("is_final");
  isUcLiteral @22 $Cxx.name("is_literal");
  isUcPod @23 $Cxx.name("is_pod");
  isUcPolymorphic @24 $Cxx.name("is_polymorphic");
  isUcStandardUcLayout @25 $Cxx.name("is_standard_layout");
  isUcTrivial @26 $Cxx.name("is_trivial");
  isUcTriviallyUcCopyable @27 $Cxx.name("is_trivially_copyable");
  isUcUnion @28 $Cxx.name("is_union");
  hasUcUniqueUcObjectUcRepresentations @29 $Cxx.name("has_unique_object_representations");
  isUcArithmetic @30 $Cxx.name("is_arithmetic");
  isUcFloatingUcPoint @31 $Cxx.name("is_floating_point");
  isUcIntegral @32 $Cxx.name("is_integral");
  isUcCompleteUcType @33 $Cxx.name("is_complete_type");
  isUcVoid @34 $Cxx.name("is_void");
  isUcArray @35 $Cxx.name("is_array");
  isUcFunction @36 $Cxx.name("is_function");
  isUcReference @37 $Cxx.name("is_reference");
  isUcLvalueUcReference @38 $Cxx.name("is_lvalue_reference");
  isUcRvalueUcReference @39 $Cxx.name("is_rvalue_reference");
  isUcFundamental @40 $Cxx.name("is_fundamental");
  isUcObject @41 $Cxx.name("is_object");
  isUcScalar @42 $Cxx.name("is_scalar");
  isUcCompound @43 $Cxx.name("is_compound");
  isUcPointer @44 $Cxx.name("is_pointer");
  isUcMemberUcObjectUcPointer @45 $Cxx.name("is_member_object_pointer");
  isUcMemberUcFunctionUcPointer @46 $Cxx.name("is_member_function_pointer");
  isUcMemberUcPointer @47 $Cxx.name("is_member_pointer");
  isUcConst @48 $Cxx.name("is_const");
  isUcVolatile @49 $Cxx.name("is_volatile");
  isUcSigned @50 $Cxx.name("is_signed");
  isUcUnsigned @51 $Cxx.name("is_unsigned");
  typeUcCompatible @52 $Cxx.name("type_compatible");
  isUcNothrowUcAssignable @53 $Cxx.name("is_nothrow_assignable");
  isUcAssignable @54 $Cxx.name("is_assignable");
  isUcBaseUcOf @55 $Cxx.name("is_base_of");
  isUcConvertibleUcTo @56 $Cxx.name("is_convertible_to");
  isUcTriviallyUcAssignable @57 $Cxx.name("is_trivially_assignable");
  referenceUcBindsUcToUcTemporary @58 $Cxx.name("reference_binds_to_temporary");
  isUcSame @59 $Cxx.name("is_same");
  isUcConvertible @60 $Cxx.name("is_convertible");
  isUcConstructible @61 $Cxx.name("is_constructible");
  isUcNothrowUcConstructible @62 $Cxx.name("is_nothrow_constructible");
  isUcTriviallyUcConstructible @63 $Cxx.name("is_trivially_constructible");
}

enum UnaryExprOrTypeTrait @0xd2af3deda0a5bfd2 {
  sizeUcOf @0 $Cxx.name("size_of");
  alignUcOf @1 $Cxx.name("align_of");
  preferredUcAlignUcOf @2 $Cxx.name("preferred_align_of");
  vecUcStep @3 $Cxx.name("vec_step");
  openUcMpUcRequiredUcSimdUcAlign @4 $Cxx.name("open_mp_required_simd_align");
}

enum UnaryOperatorKind @0xd9e4cf844656d8e6 {
  postUcIncrement @0 $Cxx.name("post_increment");
  postUcDec @1 $Cxx.name("post_dec");
  preUcIncrement @2 $Cxx.name("pre_increment");
  preUcDec @3 $Cxx.name("pre_dec");
  addrUcOf @4 $Cxx.name("addr_of");
  deref @5 $Cxx.name("deref");
  plus @6 $Cxx.name("plus");
  minus @7 $Cxx.name("minus");
  not @8 $Cxx.name("not");
  lUcNot @9 $Cxx.name("l_not");
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
  fixedUcPoint @4 $Cxx.name("fixed_point");
  complexUcInt @5 $Cxx.name("complex_int");
  complexUcFloat @6 $Cxx.name("complex_float");
  lUcValue @7 $Cxx.name("l_value");
  vector @8 $Cxx.name("vector");
  array @9 $Cxx.name("array");
  struct @10 $Cxx.name("struct");
  union @11 $Cxx.name("union");
  memberUcPointer @12 $Cxx.name("member_pointer");
  addrUcLabelUcDiff @13 $Cxx.name("addr_label_diff");
}

enum VectorLibrary @0x9344c5d64c16cbe4 {
  noUcLibrary @0 $Cxx.name("no_library");
  accelerate @1 $Cxx.name("accelerate");
  libmvec @2 $Cxx.name("libmvec");
  massv @3 $Cxx.name("massv");
  svml @4 $Cxx.name("svml");
  darwinUcLibsystemUcM @5 $Cxx.name("darwin_libsystem_m");
}

enum Visibility @0x9f55e79df4f9996e {
  hiddenUcVisibility @0 $Cxx.name("hidden_visibility");
  protectedUcVisibility @1 $Cxx.name("protected_visibility");
  defaultUcVisibility @2 $Cxx.name("default_visibility");
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
  notUcFound @1 $Cxx.name("not_found");
  regular @2 $Cxx.name("regular");
  directory @3 $Cxx.name("directory");
  symbolicUcLink @4 $Cxx.name("symbolic_link");
  block @5 $Cxx.name("block");
  character @6 $Cxx.name("character");
  firstUcInUcFirstUcOut @7 $Cxx.name("first_in_first_out");
  socket @8 $Cxx.name("socket");
  knknown @9 $Cxx.name("knknown");
}

enum CompilerName @0xa57e0439dbff0947 {
  unknown @0 $Cxx.name("unknown");
  clang @1 $Cxx.name("clang");
  appleUcClang @2 $Cxx.name("apple_clang");
  clangUcCl @3 $Cxx.name("clang_cl");
  cl @4 $Cxx.name("cl");
  gnu @5 $Cxx.name("gnu");
}

enum IncludePathLocation @0xde297748edec6a08 {
  absolute @0 $Cxx.name("absolute");
  sysrootUcRelative @1 $Cxx.name("sysroot_relative");
}

enum TargetLanguage @0xeabe5088e5bc86fc {
  c @0 $Cxx.name("c");
  cxx @1 $Cxx.name("cxx");
}

struct Decl @0xfb5879761ffaedb6 {
  access @0 :AccessSpecifier;
  accessUcUnsafe @1 :AccessSpecifier;
  availability @2 :AvailabilityResult;
  beginUcToken @3 :Token;
  bodyUcRUcBrace @4 :Token;
  endUcToken @5 :Token;
  friendUcObjectUcKind @6 :DeclFriendObjectKind;
  moduleUcOwnershipUcKind @7 :DeclModuleOwnershipKind;
  hasUcAttributes @8 :Bool;
  hasUcBody @9 :Bool;
  hasUcDefiningUcAttribute @10 :Bool;
  hasUcOwningUcModule @11 :Bool;
  hasUcTagUcIdentifierUcNamespace @12 :Bool;
  isUcCanonicalUcDeclaration @13 :Bool;
  isUcDefinedUcOutsideUcFunctionUcOrUcMethod @14 :Bool;
  isUcDeprecated @15 :Bool;
  isUcFirstUcDeclaration @16 :Bool;
  isUcFromUcAstUcFile @17 :Bool;
  isUcFunctionUcOrUcFunctionUcTemplate @18 :Bool;
  isUcImplicit @19 :Bool;
  isUcInUcAnonymousUcNamespace @20 :Bool;
  isUcInUcLocalUcScopeUcForUcInstantiation @21 :Bool;
  isUcInUcStdUcNamespace @22 :Bool;
  isUcInvalidUcDeclaration @23 :Bool;
  isUcModuleUcPrivate @24 :Bool;
  isUcOutUcOfUcLine @25 :Bool;
  isUcParameterUcPack @26 :Bool;
  isUcReferenced @27 :Bool;
  isUcTemplateUcDeclaration @28 :Bool;
  isUcTemplateUcParameter @29 :Bool;
  isUcTemplateUcParameterUcPack @30 :Bool;
  isUcTemplated @31 :Bool;
  isUcThisUcDeclarationUcReferenced @32 :Bool;
  isUcTopUcLevelUcDeclarationUcInUcObjUcCUcContainer @33 :Bool;
  isUcUnavailable @34 :Bool;
  isUcUnconditionallyUcVisible @35 :Bool;
  isUcUsed @36 :Bool;
  isUcWeakUcImported @37 :Bool;
  kind @38 :DeclKind;
  token @39 :Token;
  tokenUcRange @40 :TokenRange;
}

struct ClassScopeFunctionSpecializationDecl @0x99eb38d6a1065986 {
  decl @0:Decl;
  hasUcExplicitUcTemplateUcArguments @1 :Bool;
}

struct CapturedDecl @0xa1c847e4871d0b0a {
  decl @0:Decl;
  isUcNothrow @1 :Bool;
}

struct BlockDecl @0xd21c906a9e197a51 {
  decl @0:Decl;
  blockUcMissingUcReturnUcType @1 :Bool;
  canUcAvoidUcCopyUcToUcHeap @2 :Bool;
  capturesUcCxxUcThis @3 :Bool;
  doesUcNotUcEscape @4 :Bool;
  caretUcToken @5 :Token;
  hasUcCaptures @6 :Bool;
  isUcConversionUcFromUcLambda @7 :Bool;
  isUcVariadic @8 :Bool;
}

struct AccessSpecDecl @0xe671324616f83d3c {
  decl @0:Decl;
  accessUcSpecifierUcToken @1 :Token;
  colonUcToken @2 :Token;
}

struct TranslationUnitDecl @0x84ba694d5be7caa3 {
  decl @0:Decl;
}

struct StaticAssertDecl @0xe3ab98945466226a {
  decl @0:Decl;
  rUcParenUcToken @1 :Token;
  isUcFailed @2 :Bool;
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
  commentUcKind @2 :PragmaMSCommentKind;
}

struct ObjCPropertyImplDecl @0x9c45df6dc848c200 {
  decl @0:Decl;
  propertyUcImplementation @1 :ObjCPropertyImplDeclKind;
  propertyUcInstanceUcVariableUcDeclarationUcToken @2 :Token;
  isUcInstanceUcVariableUcNameUcSpecified @3 :Bool;
}

struct NamedDecl @0xee8ff2639c85feae {
  decl @0:Decl;
  formalUcLinkage @1 :Linkage;
  linkageUcInternal @2 :Linkage;
  name @3 :Text;
  objUcCfUcStringUcFormattingUcFamily @4 :ObjCStringFormatFamily;
  qualifiedUcNameUcAsUcString @5 :Text;
  visibility @6 :Visibility;
  hasUcExternalUcFormalUcLinkage @7 :Bool;
  hasUcLinkage @8 :Bool;
  hasUcLinkageUcBeenUcComputed @9 :Bool;
  isUcCxxUcClassUcMember @10 :Bool;
  isUcCxxUcInstanceUcMember @11 :Bool;
  isUcExternallyUcDeclarable @12 :Bool;
  isUcExternallyUcVisible @13 :Bool;
  isUcLinkageUcValid @14 :Bool;
}

struct LabelDecl @0x959116a0b50f04fe {
  namedUcDecl @0:NamedDecl;
  msUcAssemblyUcLabel @1 :Text;
  isUcGnuUcLocal @2 :Bool;
  isUcMsUcAssemblyUcLabel @3 :Bool;
  isUcResolvedUcMsUcAssemblyUcLabel @4 :Bool;
}

struct BaseUsingDecl @0xd779d676819e5d07 {
  namedUcDecl @0:NamedDecl;
}

struct UsingEnumDecl @0xa824f691f72f9236 {
  baseUcUsingUcDecl @0:BaseUsingDecl;
  enumUcToken @1 :Token;
  usingUcToken @2 :Token;
}

struct UsingDecl @0xb8602dcb3f95c179 {
  baseUcUsingUcDecl @0:BaseUsingDecl;
  usingUcToken @1 :Token;
  hasUcTypename @2 :Bool;
  isUcAccessUcDeclaration @3 :Bool;
}

struct ValueDecl @0xe2704a366b05e616 {
  namedUcDecl @0:NamedDecl;
  isUcWeak @1 :Bool;
}

struct UnresolvedUsingValueDecl @0x8ad2fc298aa43ab1 {
  valueUcDecl @0:ValueDecl;
  ellipsisUcToken @1 :Token;
  usingUcToken @2 :Token;
  isUcAccessUcDeclaration @3 :Bool;
  isUcPackUcExpansion @4 :Bool;
}

struct TemplateParamObjectDecl @0xd09f17939d7cc847 {
  valueUcDecl @0:ValueDecl;
}

struct OMPDeclareReductionDecl @0xf59daefbeeafc092 {
  valueUcDecl @0:ValueDecl;
  initializerUcKind @1 :OMPDeclareReductionDeclInitKind;
}

struct MSGuidDecl @0x9ef09ebc4be76711 {
  valueUcDecl @0:ValueDecl;
}

struct IndirectFieldDecl @0xf8f906fde6cb040f {
  valueUcDecl @0:ValueDecl;
}

struct EnumConstantDecl @0xe2b34f222cdb8877 {
  valueUcDecl @0:ValueDecl;
}

struct DeclaratorDecl @0xb95593a177af5810 {
  valueUcDecl @0:ValueDecl;
  innerUcTokenUcStart @1 :Token;
  outerUcTokenUcStart @2 :Token;
  typeUcSpecUcEndUcToken @3 :Token;
  typeUcSpecUcStartUcToken @4 :Token;
}

struct VarDecl @0xcf9adcbc59a4e339 {
  declaratorUcDecl @0:DeclaratorDecl;
  initializerUcStyle @1 :VarDeclInitializationStyle;
  languageUcLinkage @2 :LanguageLinkage;
  pointUcOfUcInstantiation @3 :Token;
  storageUcClass @4 :StorageClass;
  storageUcDuration @5 :StorageDuration;
  tlsUcKind @6 :VarDeclTLSKind;
  tscUcSpec @7 :ThreadStorageClassSpecifier;
  templateUcSpecializationUcKind @8 :TemplateSpecializationKind;
  templateUcSpecializationUcKindUcForUcInstantiation @9 :TemplateSpecializationKind;
  hasUcConstantUcInitialization @10 :Bool;
  hasUcDependentUcAlignment @11 :Bool;
  hasUcExternalUcStorage @12 :Bool;
  hasUcGlobalUcStorage @13 :Bool;
  hasUcIceUcInitializer @14 :Bool;
  hasUcInitializer @15 :Bool;
  hasUcLocalUcStorage @16 :Bool;
  isUcArcUcPseudoUcStrong @17 :Bool;
  isUcCxxUcForUcRangeUcDeclaration @18 :Bool;
  isUcConstexpr @19 :Bool;
  isUcDirectUcInitializer @20 :Bool;
  isUcEscapingUcByref @21 :Bool;
  isUcExceptionUcVariable @22 :Bool;
  isUcExternUcC @23 :Bool;
  isUcFileUcVariableUcDeclaration @24 :Bool;
  isUcFunctionUcOrUcMethodUcVariableUcDeclaration @25 :Bool;
  isUcInUcExternUcCUcContext @26 :Bool;
  isUcInUcExternUcCxxUcContext @27 :Bool;
  isUcInitializerUcCapture @28 :Bool;
  isUcInline @29 :Bool;
  isUcInlineUcSpecified @30 :Bool;
  isUcKnownUcToUcBeUcDefined @31 :Bool;
  isUcLocalUcVariableUcDeclaration @32 :Bool;
  isUcLocalUcVariableUcDeclarationUcOrUcParm @33 :Bool;
  isUcNrvoUcVariable @34 :Bool;
  isUcNoUcDestroy @35 :Bool;
  isUcNonUcEscapingUcByref @36 :Bool;
  isUcObjUcCUcForUcDeclaration @37 :Bool;
  isUcPreviousUcDeclarationUcInUcSameUcBlockUcScope @38 :Bool;
  isUcStaticUcDataUcMember @39 :Bool;
  isUcStaticUcLocal @40 :Bool;
  isUcThisUcDeclarationUcAUcDemotedUcDefinition @41 :Bool;
  isUcUsableUcInUcConstantUcExpressions @42 :Bool;
  mightUcBeUcUsableUcInUcConstantUcExpressions @43 :Bool;
  needsUcDestruction @44 :QualTypeDestructionKind;
}

struct ParmVarDecl @0xedf01c1d7684de38 {
  varUcDecl @0:VarDecl;
  defaultUcArgumentUcRange @1 :TokenRange;
  objUcCUcDeclUcQualifier @2 :DeclObjCDeclQualifier;
  hasUcDefaultUcArgument @3 :Bool;
  hasUcInheritedUcDefaultUcArgument @4 :Bool;
  hasUcUninstantiatedUcDefaultUcArgument @5 :Bool;
  hasUcUnparsedUcDefaultUcArgument @6 :Bool;
  isUcDestroyedUcInUcCallee @7 :Bool;
  isUcKnrUcPromoted @8 :Bool;
  isUcObjUcCUcMethodUcParameter @9 :Bool;
}

struct OMPCapturedExprDecl @0x8dae8ad443b5cf77 {
  varUcDecl @0:VarDecl;
}

struct ImplicitParamDecl @0x9482ac8d963f562c {
  varUcDecl @0:VarDecl;
  parameterUcKind @1 :ImplicitParamDeclImplicitParamKind;
}

struct DecompositionDecl @0xd32bcfb0d1a2facb {
  varUcDecl @0:VarDecl;
}

struct VarTemplateSpecializationDecl @0xbaf3e3ed90ea85e0 {
  varUcDecl @0:VarDecl;
  externUcToken @1 :Token;
  specializationUcKind @2 :TemplateSpecializationKind;
  templateUcKeywordUcToken @3 :Token;
  isUcClassUcScopeUcExplicitUcSpecialization @4 :Bool;
  isUcExplicitUcInstantiationUcOrUcSpecialization @5 :Bool;
  isUcExplicitUcSpecialization @6 :Bool;
}

struct VarTemplatePartialSpecializationDecl @0xe1d0f96cb9fa250f {
  varUcTemplateUcSpecializationUcDecl @0:VarTemplateSpecializationDecl;
  hasUcAssociatedUcConstraints @1 :Bool;
}

struct NonTypeTemplateParmDecl @0x964d2872d52f2d65 {
  declaratorUcDecl @0:DeclaratorDecl;
  defaultUcArgumentUcWasUcInherited @1 :Bool;
  defaultUcArgumentUcToken @2 :Token;
  hasUcDefaultUcArgument @3 :Bool;
  hasUcPlaceholderUcTypeUcConstraint @4 :Bool;
  isUcExpandedUcParameterUcPack @5 :Bool;
  isUcPackUcExpansion @6 :Bool;
}

struct MSPropertyDecl @0x9a46ca50a3ae900f {
  declaratorUcDecl @0:DeclaratorDecl;
  hasUcGetter @1 :Bool;
  hasUcSetter @2 :Bool;
}

struct FunctionDecl @0x92bd4789888f8ccb {
  declaratorUcDecl @0:DeclaratorDecl;
  doesUcDeclarationUcForceUcExternallyUcVisibleUcDefinition @1 :Bool;
  doesUcThisUcDeclarationUcHaveUcAUcBody @2 :Bool;
  constexprUcKind @3 :ConstexprSpecKind;
  ellipsisUcToken @4 :Token;
  exceptionUcSpecUcSourceUcRange @5 :TokenRange;
  exceptionUcSpecUcType @6 :ExceptionSpecificationType;
  languageUcLinkage @7 :LanguageLinkage;
  multiUcVersionUcKind @8 :MultiVersionKind;
  overloadedUcOperator @9 :OverloadedOperatorKind;
  parametersUcSourceUcRange @10 :TokenRange;
  pointUcOfUcInstantiation @11 :Token;
  returnUcTypeUcSourceUcRange @12 :TokenRange;
  storageUcClass @13 :StorageClass;
  templateUcSpecializationUcKind @14 :TemplateSpecializationKind;
  templateUcSpecializationUcKindUcForUcInstantiation @15 :TemplateSpecializationKind;
  templatedUcKind @16 :FunctionDeclTemplatedKind;
  hasUcImplicitUcReturnUcZero @17 :Bool;
  hasUcInheritedUcPrototype @18 :Bool;
  hasUcOneUcParamUcOrUcDefaultUcArguments @19 :Bool;
  hasUcPrototype @20 :Bool;
  hasUcSkippedUcBody @21 :Bool;
  hasUcTrivialUcBody @22 :Bool;
  hasUcWrittenUcPrototype @23 :Bool;
  instantiationUcIsUcPending @24 :Bool;
  isUcCpuUcDispatchUcMultiUcVersion @25 :Bool;
  isUcCpuUcSpecificUcMultiUcVersion @26 :Bool;
  isUcConsteval @27 :Bool;
  isUcConstexpr @28 :Bool;
  isUcConstexprUcSpecified @29 :Bool;
  isUcDefaulted @30 :Bool;
  isUcDeleted @31 :Bool;
  isUcDeletedUcAsUcWritten @32 :Bool;
  isUcDestroyingUcOperatorUcDelete @33 :Bool;
  isUcExplicitlyUcDefaulted @34 :Bool;
  isUcExternUcC @35 :Bool;
  isUcFunctionUcTemplateUcSpecialization @36 :Bool;
  isUcGlobal @37 :Bool;
  isUcImplicitlyUcInstantiable @38 :Bool;
  isUcInUcExternUcCUcContext @39 :Bool;
  isUcInUcExternUcCxxUcContext @40 :Bool;
  isUcInlineUcBuiltinUcDeclaration @41 :Bool;
  isUcInlineUcDefinitionUcExternallyUcVisible @42 :Bool;
  isUcInlineUcSpecified @43 :Bool;
  isUcInlined @44 :Bool;
  isUcLateUcTemplateUcParsed @45 :Bool;
  isUcMsUcExternUcInline @46 :Bool;
  isUcMsvcrtUcEntryUcPoint @47 :Bool;
  isUcMain @48 :Bool;
  isUcMultiUcVersion @49 :Bool;
  isUcNoUcReturn @50 :Bool;
  isUcOverloadedUcOperator @51 :Bool;
  isUcPure @52 :Bool;
  isUcReplaceableUcGlobalUcAllocationUcFunction @53 :Bool;
  isUcReservedUcGlobalUcPlacementUcOperator @54 :Bool;
  isUcStatic @55 :Bool;
  isUcTargetUcMultiUcVersion @56 :Bool;
  isUcTemplateUcInstantiation @57 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @58 :Bool;
  isUcThisUcDeclarationUcInstantiatedUcFromUcAUcFriendUcDefinition @59 :Bool;
  isUcTrivial @60 :Bool;
  isUcTrivialUcForUcCall @61 :Bool;
  isUcUserUcProvided @62 :Bool;
  isUcVariadic @63 :Bool;
  isUcVirtualUcAsUcWritten @64 :Bool;
  usesUcSehUcTry @65 :Bool;
  willUcHaveUcBody @66 :Bool;
}

struct CXXMethodDecl @0xd83d5835cf6512db {
  functionUcDecl @0:FunctionDecl;
  referenceUcQualifier @1 :RefQualifierKind;
  hasUcInlineUcBody @2 :Bool;
  isUcConst @3 :Bool;
  isUcCopyUcAssignmentUcOperator @4 :Bool;
  isUcInstance @5 :Bool;
  isUcLambdaUcStaticUcInvoker @6 :Bool;
  isUcMoveUcAssignmentUcOperator @7 :Bool;
  isUcVirtual @8 :Bool;
  isUcVolatile @9 :Bool;
}

struct CXXDestructorDecl @0xee0fd0438430a21c {
  cxxUcMethodUcDecl @0:CXXMethodDecl;
}

struct CXXConversionDecl @0xac531836739115b2 {
  cxxUcMethodUcDecl @0:CXXMethodDecl;
  isUcExplicit @1 :Bool;
  isUcLambdaUcToUcBlockUcPointerUcConversion @2 :Bool;
}

struct CXXConstructorDecl @0xc6bfa2c4650464b8 {
  cxxUcMethodUcDecl @0:CXXMethodDecl;
  isUcConvertingUcConstructor @1 :Bool;
  isUcDefaultUcConstructor @2 :Bool;
  isUcDelegatingUcConstructor @3 :Bool;
  isUcExplicit @4 :Bool;
  isUcInheritingUcConstructor @5 :Bool;
  isUcSpecializationUcCopyingUcObject @6 :Bool;
}

struct CXXDeductionGuideDecl @0xca6c78b5c1634d9d {
  functionUcDecl @0:FunctionDecl;
  isUcCopyUcDeductionUcCandidate @1 :Bool;
  isUcExplicit @2 :Bool;
}

struct FieldDecl @0xec8d79b82b91a5eb {
  declaratorUcDecl @0:DeclaratorDecl;
  inUcClassUcInitializerUcStyle @1 :InClassInitStyle;
  hasUcCapturedUcVlaUcType @2 :Bool;
  hasUcInUcClassUcInitializer @3 :Bool;
  isUcAnonymousUcStructUcOrUcUnion @4 :Bool;
  isUcBitUcField @5 :Bool;
  isUcMutable @6 :Bool;
  isUcUnnamedUcBitfield @7 :Bool;
  isUcZeroUcLengthUcBitUcField @8 :Bool;
  isUcZeroUcSize @9 :Bool;
}

struct ObjCIvarDecl @0xfd0f42a085839510 {
  fieldUcDecl @0:FieldDecl;
  accessUcControl @1 :ObjCIvarDeclAccessControl;
  canonicalUcAccessUcControl @2 :ObjCIvarDeclAccessControl;
  synthesize @3 :Bool;
}

struct ObjCAtDefsFieldDecl @0xd8b002eb70c258c6 {
  fieldUcDecl @0:FieldDecl;
}

struct BindingDecl @0xe77651068f3e1703 {
  valueUcDecl @0:ValueDecl;
}

struct UsingShadowDecl @0xef25bc2e71e7534e {
  namedUcDecl @0:NamedDecl;
}

struct ConstructorUsingShadowDecl @0x8a43df80c48b7033 {
  usingUcShadowUcDecl @0:UsingShadowDecl;
  constructsUcVirtualUcBase @1 :Bool;
}

struct UsingPackDecl @0xf68edcc97d568bee {
  namedUcDecl @0:NamedDecl;
}

struct UsingDirectiveDecl @0xf383b9039044d6f8 {
  namedUcDecl @0:NamedDecl;
  identifierUcToken @1 :Token;
  namespaceUcKeyUcToken @2 :Token;
  usingUcToken @3 :Token;
}

struct UnresolvedUsingIfExistsDecl @0x82421c5826bd81e2 {
  namedUcDecl @0:NamedDecl;
}

struct TypeDecl @0xd349fa911db2de42 {
  namedUcDecl @0:NamedDecl;
}

struct TemplateTypeParmDecl @0x87eba729b34d198a {
  typeUcDecl @0:TypeDecl;
  defaultUcArgumentUcWasUcInherited @1 :Bool;
  defaultUcArgumentUcToken @2 :Token;
  hasUcDefaultUcArgument @3 :Bool;
  hasUcTypeUcConstraint @4 :Bool;
  isUcExpandedUcParameterUcPack @5 :Bool;
  isUcPackUcExpansion @6 :Bool;
  wasUcDeclaredUcWithUcTypename @7 :Bool;
}

struct TagDecl @0x8e30dcc81a0377d1 {
  typeUcDecl @0:TypeDecl;
  braceUcRange @1 :TokenRange;
  innerUcTokenUcStart @2 :Token;
  outerUcTokenUcStart @3 :Token;
  tagUcKind @4 :TagTypeKind;
  hasUcNameUcForUcLinkage @5 :Bool;
  isUcBeingUcDefined @6 :Bool;
  isUcClass @7 :Bool;
  isUcCompleteUcDefinition @8 :Bool;
  isUcCompleteUcDefinitionUcRequired @9 :Bool;
  isUcDependentUcType @10 :Bool;
  isUcEmbeddedUcInUcDeclarator @11 :Bool;
  isUcEnum @12 :Bool;
  isUcFreeUcStanding @13 :Bool;
  isUcInterface @14 :Bool;
  isUcStruct @15 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @16 :Bool;
  isUcUnion @17 :Bool;
  mayUcHaveUcOutUcOfUcDateUcDefinition @18 :Bool;
}

struct RecordDecl @0xae6dc96296678f51 {
  tagUcDecl @0:TagDecl;
  canUcPassUcInUcRegisters @1 :Bool;
  argumentUcPassingUcRestrictions @2 :RecordDeclArgPassingKind;
  hasUcFlexibleUcArrayUcMember @3 :Bool;
  hasUcLoadedUcFieldsUcFromUcExternalUcStorage @4 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcCopyUcCUcUnion @5 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitializeUcCUcUnion @6 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDestructUcCUcUnion @7 :Bool;
  hasUcObjectUcMember @8 :Bool;
  hasUcVolatileUcMember @9 :Bool;
  isUcAnonymousUcStructUcOrUcUnion @10 :Bool;
  isUcCapturedUcRecord @11 :Bool;
  isUcInjectedUcClassUcName @12 :Bool;
  isUcLambda @13 :Bool;
  isUcMsUcStruct @14 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcCopy @15 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitialize @16 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcDestroy @17 :Bool;
  isUcOrUcContainsUcUnion @18 :Bool;
  isUcParamUcDestroyedUcInUcCallee @19 :Bool;
  mayUcInsertUcExtraUcPadding @20 :Bool;
}

struct CXXRecordDecl @0x9ecc9c9b6a1f56fc {
  recordUcDecl @0:RecordDecl;
  allowUcConstUcDefaultUcInitializer @1 :Bool;
  calculateUcInheritanceUcModel @2 :MSInheritanceModel;
  defaultedUcCopyUcConstructorUcIsUcDeleted @3 :Bool;
  defaultedUcDefaultUcConstructorUcIsUcConstexpr @4 :Bool;
  defaultedUcDestructorUcIsUcConstexpr @5 :Bool;
  defaultedUcDestructorUcIsUcDeleted @6 :Bool;
  defaultedUcMoveUcConstructorUcIsUcDeleted @7 :Bool;
  lambdaUcCaptureUcDefault @8 :LambdaCaptureDefault;
  msUcInheritanceUcModel @9 :MSInheritanceModel;
  msUcVtorUcDispUcMode @10 :MSVtorDispMode;
  templateUcSpecializationUcKind @11 :TemplateSpecializationKind;
  hasUcAnyUcDependentUcBases @12 :Bool;
  hasUcConstexprUcDefaultUcConstructor @13 :Bool;
  hasUcConstexprUcDestructor @14 :Bool;
  hasUcConstexprUcNonUcCopyUcMoveUcConstructor @15 :Bool;
  hasUcCopyUcAssignmentUcWithUcConstUcParam @16 :Bool;
  hasUcCopyUcConstructorUcWithUcConstUcParam @17 :Bool;
  hasUcDefaultUcConstructor @18 :Bool;
  hasUcDefinition @19 :Bool;
  hasUcDirectUcFields @20 :Bool;
  hasUcFriends @21 :Bool;
  hasUcInUcClassUcInitializer @22 :Bool;
  hasUcInheritedUcAssignment @23 :Bool;
  hasUcInheritedUcConstructor @24 :Bool;
  hasUcIrrelevantUcDestructor @25 :Bool;
  hasUcKnownUcLambdaUcInternalUcLinkage @26 :Bool;
  hasUcMoveUcAssignment @27 :Bool;
  hasUcMoveUcConstructor @28 :Bool;
  hasUcMutableUcFields @29 :Bool;
  hasUcNonUcLiteralUcTypeUcFieldsUcOrUcBases @30 :Bool;
  hasUcNonUcTrivialUcCopyUcAssignment @31 :Bool;
  hasUcNonUcTrivialUcCopyUcConstructor @32 :Bool;
  hasUcNonUcTrivialUcCopyUcConstructorUcForUcCall @33 :Bool;
  hasUcNonUcTrivialUcDefaultUcConstructor @34 :Bool;
  hasUcNonUcTrivialUcDestructor @35 :Bool;
  hasUcNonUcTrivialUcDestructorUcForUcCall @36 :Bool;
  hasUcNonUcTrivialUcMoveUcAssignment @37 :Bool;
  hasUcNonUcTrivialUcMoveUcConstructor @38 :Bool;
  hasUcNonUcTrivialUcMoveUcConstructorUcForUcCall @39 :Bool;
  hasUcPrivateUcFields @40 :Bool;
  hasUcProtectedUcFields @41 :Bool;
  hasUcSimpleUcCopyUcAssignment @42 :Bool;
  hasUcSimpleUcCopyUcConstructor @43 :Bool;
  hasUcSimpleUcDestructor @44 :Bool;
  hasUcSimpleUcMoveUcAssignment @45 :Bool;
  hasUcSimpleUcMoveUcConstructor @46 :Bool;
  hasUcTrivialUcCopyUcAssignment @47 :Bool;
  hasUcTrivialUcCopyUcConstructor @48 :Bool;
  hasUcTrivialUcCopyUcConstructorUcForUcCall @49 :Bool;
  hasUcTrivialUcDefaultUcConstructor @50 :Bool;
  hasUcTrivialUcDestructor @51 :Bool;
  hasUcTrivialUcDestructorUcForUcCall @52 :Bool;
  hasUcTrivialUcMoveUcAssignment @53 :Bool;
  hasUcTrivialUcMoveUcConstructor @54 :Bool;
  hasUcTrivialUcMoveUcConstructorUcForUcCall @55 :Bool;
  hasUcUninitializedUcReferenceUcMember @56 :Bool;
  hasUcUserUcDeclaredUcConstructor @57 :Bool;
  hasUcUserUcDeclaredUcCopyUcAssignment @58 :Bool;
  hasUcUserUcDeclaredUcCopyUcConstructor @59 :Bool;
  hasUcUserUcDeclaredUcDestructor @60 :Bool;
  hasUcUserUcDeclaredUcMoveUcAssignment @61 :Bool;
  hasUcUserUcDeclaredUcMoveUcConstructor @62 :Bool;
  hasUcUserUcDeclaredUcMoveUcOperation @63 :Bool;
  hasUcUserUcProvidedUcDefaultUcConstructor @64 :Bool;
  hasUcVariantUcMembers @65 :Bool;
  implicitUcCopyUcAssignmentUcHasUcConstUcParam @66 :Bool;
  implicitUcCopyUcConstructorUcHasUcConstUcParam @67 :Bool;
  isUcAbstract @68 :Bool;
  isUcAggregate @69 :Bool;
  isUcAnyUcDestructorUcNoUcReturn @70 :Bool;
  isUcCUcLike @71 :Bool;
  isUcCxUcX11UcStandardUcLayout @72 :Bool;
  isUcDependentUcLambda @73 :Bool;
  isUcDynamicUcClass @74 :Bool;
  isUcEffectivelyUcFinal @75 :Bool;
  isUcEmpty @76 :Bool;
  isUcGenericUcLambda @77 :Bool;
  isUcInterfaceUcLike @78 :Bool;
  isUcLiteral @79 :Bool;
  isUcPod @80 :Bool;
  isUcParsingUcBaseUcSpecifiers @81 :Bool;
  isUcPolymorphic @82 :Bool;
  isUcStandardUcLayout @83 :Bool;
  isUcStructural @84 :Bool;
  isUcTrivial @85 :Bool;
  isUcTriviallyUcCopyable @86 :Bool;
  lambdaUcIsUcDefaultUcConstructibleUcAndUcAssignable @87 :Bool;
  mayUcBeUcAbstract @88 :Bool;
  mayUcBeUcDynamicUcClass @89 :Bool;
  mayUcBeUcNonUcDynamicUcClass @90 :Bool;
  needsUcImplicitUcCopyUcAssignment @91 :Bool;
  needsUcImplicitUcCopyUcConstructor @92 :Bool;
  needsUcImplicitUcDefaultUcConstructor @93 :Bool;
  needsUcImplicitUcDestructor @94 :Bool;
  needsUcImplicitUcMoveUcAssignment @95 :Bool;
  needsUcImplicitUcMoveUcConstructor @96 :Bool;
  needsUcOverloadUcResolutionUcForUcCopyUcAssignment @97 :Bool;
  needsUcOverloadUcResolutionUcForUcCopyUcConstructor @98 :Bool;
  needsUcOverloadUcResolutionUcForUcDestructor @99 :Bool;
  needsUcOverloadUcResolutionUcForUcMoveUcAssignment @100 :Bool;
  needsUcOverloadUcResolutionUcForUcMoveUcConstructor @101 :Bool;
  nullUcFieldUcOffsetUcIsUcZero @102 :Bool;
}

struct ClassTemplateSpecializationDecl @0xa81be8b0845933da {
  cxxUcRecordUcDecl @0:CXXRecordDecl;
  externUcToken @1 :Token;
  pointUcOfUcInstantiation @2 :Token;
  specializationUcKind @3 :TemplateSpecializationKind;
  templateUcKeywordUcToken @4 :Token;
  isUcClassUcScopeUcExplicitUcSpecialization @5 :Bool;
  isUcExplicitUcInstantiationUcOrUcSpecialization @6 :Bool;
  isUcExplicitUcSpecialization @7 :Bool;
}

struct ClassTemplatePartialSpecializationDecl @0x9492104c4b2eff2e {
  classUcTemplateUcSpecializationUcDecl @0:ClassTemplateSpecializationDecl;
  hasUcAssociatedUcConstraints @1 :Bool;
}

struct EnumDecl @0x93540bfa73a13c84 {
  tagUcDecl @0:TagDecl;
  integerUcTypeUcRange @1 :TokenRange;
  templateUcSpecializationUcKind @2 :TemplateSpecializationKind;
  isUcClosed @3 :Bool;
  isUcClosedUcFlag @4 :Bool;
  isUcClosedUcNonUcFlag @5 :Bool;
  isUcComplete @6 :Bool;
  isUcFixed @7 :Bool;
  isUcScoped @8 :Bool;
  isUcScopedUcUsingUcClassUcTag @9 :Bool;
}

struct UnresolvedUsingTypenameDecl @0x8b74c3415940bb24 {
  typeUcDecl @0:TypeDecl;
  ellipsisUcToken @1 :Token;
  typenameUcToken @2 :Token;
  usingUcToken @3 :Token;
  isUcPackUcExpansion @4 :Bool;
}

struct TypedefNameDecl @0xe8f3a8fa9f84b388 {
  typeUcDecl @0:TypeDecl;
  isUcModed @1 :Bool;
  isUcTransparentUcTag @2 :Bool;
}

struct TypedefDecl @0xcabfd592ecdf73ec {
  typedefUcNameUcDecl @0:TypedefNameDecl;
}

struct TypeAliasDecl @0x98b3c141fd82bbdd {
  typedefUcNameUcDecl @0:TypedefNameDecl;
}

struct ObjCTypeParamDecl @0xfea48cce2b1c50cd {
  typedefUcNameUcDecl @0:TypedefNameDecl;
  colonUcToken @1 :Token;
  variance @2 :ObjCTypeParamVariance;
  varianceUcToken @3 :Token;
  hasUcExplicitUcBound @4 :Bool;
}

struct TemplateDecl @0x8794861cbdf44fcd {
  namedUcDecl @0:NamedDecl;
  hasUcAssociatedUcConstraints @1 :Bool;
}

struct RedeclarableTemplateDecl @0xeae96325d22b861f {
  templateUcDecl @0:TemplateDecl;
  isUcMemberUcSpecialization @1 :Bool;
}

struct FunctionTemplateDecl @0xc88144c3067080ac {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
  isUcAbbreviated @1 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @2 :Bool;
}

struct ClassTemplateDecl @0xd77c8a2532fd776e {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
  isUcThisUcDeclarationUcAUcDefinition @1 :Bool;
}

struct VarTemplateDecl @0x983bd212ec53c1f3 {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
  isUcThisUcDeclarationUcAUcDefinition @1 :Bool;
}

struct TypeAliasTemplateDecl @0xcafc2a5c9d4a2d22 {
  redeclarableUcTemplateUcDecl @0:RedeclarableTemplateDecl;
}

struct ConceptDecl @0xdbe7c6781c4169e0 {
  templateUcDecl @0:TemplateDecl;
  isUcTypeUcConcept @1 :Bool;
}

struct BuiltinTemplateDecl @0xa84039c6df79998d {
  templateUcDecl @0:TemplateDecl;
}

struct TemplateTemplateParmDecl @0x8481be080ff800b8 {
  templateUcDecl @0:TemplateDecl;
  defaultUcArgumentUcWasUcInherited @1 :Bool;
  defaultUcArgumentUcToken @2 :Token;
  hasUcDefaultUcArgument @3 :Bool;
  isUcExpandedUcParameterUcPack @4 :Bool;
  isUcPackUcExpansion @5 :Bool;
}

struct ObjCPropertyDecl @0x9eb7f76b62290548 {
  namedUcDecl @0:NamedDecl;
  atUcToken @1 :Token;
  getterUcNameUcToken @2 :Token;
  lUcParenUcToken @3 :Token;
  propertyUcImplementation @4 :ObjCPropertyDeclPropertyControl;
  queryUcKind @5 :ObjCPropertyQueryKind;
  setterUcKind @6 :ObjCPropertyDeclSetterKind;
  setterUcNameUcToken @7 :Token;
  isUcAtomic @8 :Bool;
  isUcClassUcProperty @9 :Bool;
  isUcDirectUcProperty @10 :Bool;
  isUcInstanceUcProperty @11 :Bool;
  isUcOptional @12 :Bool;
  isUcReadUcOnly @13 :Bool;
  isUcRetaining @14 :Bool;
}

struct ObjCMethodDecl @0xf8c8c7d3c113456e {
  namedUcDecl @0:NamedDecl;
  definedUcInUcNsUcObject @1 :Bool;
  declaratorUcEndUcToken @2 :Token;
  implementationUcControl @3 :ObjCMethodDeclImplementationControl;
  methodUcFamily @4 :ObjCMethodFamily;
  objUcCUcDeclUcQualifier @5 :DeclObjCDeclQualifier;
  returnUcTypeUcSourceUcRange @6 :TokenRange;
  selectorUcStartUcToken @7 :Token;
  hasUcRedeclaration @8 :Bool;
  hasUcRelatedUcResultUcType @9 :Bool;
  hasUcSkippedUcBody @10 :Bool;
  isUcClassUcMethod @11 :Bool;
  isUcDefined @12 :Bool;
  isUcDesignatedUcInitializerUcForUcTheUcInterface @13 :Bool;
  isUcDirectUcMethod @14 :Bool;
  isUcInstanceUcMethod @15 :Bool;
  isUcOptional @16 :Bool;
  isUcOverriding @17 :Bool;
  isUcPropertyUcAccessor @18 :Bool;
  isUcRedeclaration @19 :Bool;
  isUcSynthesizedUcAccessorUcStub @20 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @21 :Bool;
  isUcThisUcDeclarationUcAUcDesignatedUcInitializer @22 :Bool;
  isUcVariadic @23 :Bool;
}

struct ObjCContainerDecl @0xaf9db5ae0b65ce9e {
  namedUcDecl @0:NamedDecl;
  atUcEndUcRange @1 :TokenRange;
  atUcStartUcToken @2 :Token;
}

struct ObjCCategoryDecl @0xb673566cbe41a76d {
  objUcCUcContainerUcDecl @0:ObjCContainerDecl;
  isUcClassUcExtension @1 :Bool;
  categoryUcNameUcToken @2 :Token;
  instanceUcVariableUcLUcBraceUcToken @3 :Token;
  instanceUcVariableUcRUcBraceUcToken @4 :Token;
}

struct ObjCProtocolDecl @0xa8d0b0128e3a36e1 {
  objUcCUcContainerUcDecl @0:ObjCContainerDecl;
  objUcCUcRuntimeUcNameUcAsUcString @1 :Text;
  hasUcDefinition @2 :Bool;
  isUcNonUcRuntimeUcProtocol @3 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @4 :Bool;
}

struct ObjCInterfaceDecl @0x851a7195d7b1d15e {
  objUcCUcContainerUcDecl @0:ObjCContainerDecl;
  declaresUcOrUcInheritsUcDesignatedUcInitializers @1 :Bool;
  endUcOfUcDefinitionUcToken @2 :Token;
  objUcCUcRuntimeUcNameUcAsUcString @3 :Text;
  superUcClassUcToken @4 :Token;
  hasUcDefinition @5 :Bool;
  hasUcDesignatedUcInitializers @6 :Bool;
  isUcArcUcWeakrefUcUnavailable @7 :Bool;
  isUcImplicitUcInterfaceUcDeclaration @8 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @9 :Bool;
}

struct ObjCImplDecl @0xfbf2d2598582b4f4 {
  objUcCUcContainerUcDecl @0:ObjCContainerDecl;
}

struct ObjCCategoryImplDecl @0xb972fe178fc59d16 {
  objUcCUcImplUcDecl @0:ObjCImplDecl;
  categoryUcNameUcToken @1 :Token;
}

struct ObjCImplementationDecl @0xf2e56fe062561acd {
  objUcCUcImplUcDecl @0:ObjCImplDecl;
  instanceUcVariableUcLUcBraceUcToken @1 :Token;
  instanceUcVariableUcRUcBraceUcToken @2 :Token;
  objUcCUcRuntimeUcNameUcAsUcString @3 :Text;
  superUcClassUcToken @4 :Token;
  hasUcDestructors @5 :Bool;
  hasUcNonUcZeroUcConstructors @6 :Bool;
}

struct ObjCCompatibleAliasDecl @0xc484be73cf6be95b {
  namedUcDecl @0:NamedDecl;
}

struct NamespaceDecl @0xd4713edcad196585 {
  namedUcDecl @0:NamedDecl;
  rUcBraceUcToken @1 :Token;
  isUcAnonymousUcNamespace @2 :Bool;
  isUcInline @3 :Bool;
  isUcOriginalUcNamespace @4 :Bool;
}

struct NamespaceAliasDecl @0xd8966652a484c480 {
  namedUcDecl @0:NamedDecl;
  aliasUcToken @1 :Token;
  namespaceUcToken @2 :Token;
  targetUcNameUcToken @3 :Token;
}

struct LinkageSpecDecl @0xb0f84c4a56c95eec {
  decl @0:Decl;
  externUcToken @1 :Token;
  language @2 :LinkageSpecDeclLanguageIDs;
  rUcBraceUcToken @3 :Token;
  hasUcBraces @4 :Bool;
}

struct LifetimeExtendedTemporaryDecl @0x829a6a0ac2b5baa8 {
  decl @0:Decl;
  storageUcDuration @1 :StorageDuration;
}

struct ImportDecl @0x84f826d506def833 {
  decl @0:Decl;
}

struct FriendTemplateDecl @0x82a920109bdb2178 {
  decl @0:Decl;
  friendUcToken @1 :Token;
}

struct FriendDecl @0xe6545eb838d810d0 {
  decl @0:Decl;
  friendUcToken @1 :Token;
  isUcUnsupportedUcFriend @2 :Bool;
}

struct FileScopeAsmDecl @0xa91b82b590024228 {
  decl @0:Decl;
  assemblyUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ExternCContextDecl @0xd79e4560c3f80cbd {
  decl @0:Decl;
}

struct ExportDecl @0xb9bc9642842c6d81 {
  decl @0:Decl;
  exportUcToken @1 :Token;
  rUcBraceUcToken @2 :Token;
  hasUcBraces @3 :Bool;
}

struct EmptyDecl @0xdb55f7b2f60fd2a7 {
  decl @0:Decl;
}

struct Stmt @0x91127d30fade9a32 {
  beginUcToken @0 :Token;
  endUcToken @1 :Token;
  tokenUcRange @2 :TokenRange;
  kind @3 :StmtKind;
}

struct SEHTryStmt @0xf24201c85c654a91 {
  stmt @0:Stmt;
  isUcCxxUcTry @1 :Bool;
  tryUcToken @2 :Token;
}

struct SEHLeaveStmt @0xc4e4ea7e9d86c292 {
  stmt @0:Stmt;
  leaveUcToken @1 :Token;
}

struct SEHFinallyStmt @0x8331103206247bcd {
  stmt @0:Stmt;
  finallyUcToken @1 :Token;
}

struct SEHExceptStmt @0xec2050c67aa8fa46 {
  stmt @0:Stmt;
  exceptUcToken @1 :Token;
}

struct ReturnStmt @0xa64f08dfd7dbc80a {
  stmt @0:Stmt;
  returnUcToken @1 :Token;
}

struct ObjCForCollectionStmt @0x9eba75a6b3c891a0 {
  stmt @0:Stmt;
  forUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ObjCAutoreleasePoolStmt @0x9762e1f9121378d2 {
  stmt @0:Stmt;
  atUcToken @1 :Token;
}

struct ObjCAtTryStmt @0x8a11f497922c60fa {
  stmt @0:Stmt;
  atUcTryUcToken @1 :Token;
}

struct ObjCAtThrowStmt @0xd0de9b13bfbb829d {
  stmt @0:Stmt;
  throwUcToken @1 :Token;
}

struct ObjCAtSynchronizedStmt @0xc002bd58ce946b42 {
  stmt @0:Stmt;
  atUcSynchronizedUcToken @1 :Token;
}

struct ObjCAtFinallyStmt @0xb4641f5dbb7b9c51 {
  stmt @0:Stmt;
  atUcFinallyUcToken @1 :Token;
}

struct ObjCAtCatchStmt @0xea4d614d29e03f4e {
  stmt @0:Stmt;
  atUcCatchUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  hasUcEllipsis @3 :Bool;
}

struct OMPExecutableDirective @0xd9ecc0e6e88a888e {
  stmt @0:Stmt;
  hasUcAssociatedUcStatement @1 :Bool;
  isUcStandaloneUcDirective @2 :Bool;
}

struct OMPDispatchDirective @0xf2ebe316be280493 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  targetUcCallUcToken @1 :Token;
}

struct OMPDepobjDirective @0xf7901aaea1e59da5 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCriticalDirective @0xaae7b90454a167f2 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCancellationPointDirective @0xbd3f65af25cb05ac {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCancelDirective @0xe9fe3be8b3920583 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPBarrierDirective @0xa561ecfd48037b9f {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPAtomicDirective @0xccfc4e254a9ca2ef {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  isUcPostfixUcUpdate @1 :Bool;
  isUcXlhsUcInUcRhsUcPart @2 :Bool;
}

struct OMPTeamsDirective @0xb09cbd39c14f104d {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskyieldDirective @0xeda0fa85f0053b41 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskwaitDirective @0xfab570caa675ad05 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskgroupDirective @0x997a52791bc1d2cb {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTaskDirective @0xad4854dc66276a11 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetUpdateDirective @0xce201c1bda195171 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetTeamsDirective @0xcad5df87230fb5e1 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetParallelDirective @0xe053102edf992ab7 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetExitDataDirective @0xd3f73d9d66855b7c {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetEnterDataDirective @0xfaddabf39d71573c {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetDirective @0xe61e25c74d351171 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPTargetDataDirective @0xffdf74d960adebc3 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPSingleDirective @0x9e31c9d771d11457 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPSectionsDirective @0xa007966bd69b3ef4 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPSectionDirective @0xabfbf1faadf3da79 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPScanDirective @0x8048cf331a56b6fb {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPParallelSectionsDirective @0xdab61036a2e612d3 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPParallelMasterDirective @0xa7869fbfbcb75e30 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPParallelDirective @0xb6332105b1f2102a {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  hasUcCancel @1 :Bool;
}

struct OMPOrderedDirective @0xb97823fb2b0a2176 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPMasterDirective @0xb7b87dfe2df187cd {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPMaskedDirective @0xc1e20133fca4bab7 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPLoopBasedDirective @0xebd7e00926927a85 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPUnrollDirective @0xfde8548a895efed2 {
  ompUcLoopUcBasedUcDirective @0:OMPLoopBasedDirective;
}

struct OMPTileDirective @0x955f68d0ea4dad7c {
  ompUcLoopUcBasedUcDirective @0:OMPLoopBasedDirective;
}

struct OMPLoopDirective @0x996557610848d25e {
  ompUcLoopUcBasedUcDirective @0:OMPLoopBasedDirective;
}

struct OMPForSimdDirective @0xb5d719f282f43408 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPForDirective @0xafaaf1c5631fa3da {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPDistributeSimdDirective @0xfe653c77e8d8d7f8 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPDistributeParallelForSimdDirective @0xed219e924604e032 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPDistributeParallelForDirective @0xd4f84c1343cddbc3 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPDistributeDirective @0xa3b58e2e947f68cb {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeSimdDirective @0xdd9b68bf972afa51 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeParallelForSimdDirective @0xb1d522d25bf5e8db {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTeamsDistributeParallelForDirective @0x8113915845154e06 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTeamsDistributeDirective @0xd57fd7f310c3591a {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTaskLoopSimdDirective @0xf8f593871dfacede {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTaskLoopDirective @0xbeea33eaf08e61de {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetTeamsDistributeSimdDirective @0xf160e61a5edc1ff2 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetTeamsDistributeParallelForSimdDirective @0x804e195502d62e5b {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetTeamsDistributeParallelForDirective @0xb9ef1d4c32f58988 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPTargetTeamsDistributeDirective @0xdb91542417a3e11b {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetSimdDirective @0x82400c65f487fb8a {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetParallelForSimdDirective @0x92be3b840fda6c34 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPTargetParallelForDirective @0xb14634030f2d8708 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPSimdDirective @0xb48cdcd37571e590 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPParallelMasterTaskLoopSimdDirective @0xbbcba5847ff5ba48 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPParallelMasterTaskLoopDirective @0xa53ad6a3233e8b9d {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPParallelForSimdDirective @0xecdb69f0bce900de {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPParallelForDirective @0x8e1e3b1821c0515a {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPMasterTaskLoopSimdDirective @0xea7bac26edd3f458 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
}

struct OMPMasterTaskLoopDirective @0x826300eb6228e8f0 {
  ompUcLoopUcDirective @0:OMPLoopDirective;
  hasUcCancel @1 :Bool;
}

struct OMPInteropDirective @0x86d3370fbc5f7dd0 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPFlushDirective @0xfa2df93386e63fbe {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
}

struct OMPCanonicalLoop @0xf3cf896ddd7c46d1 {
  stmt @0:Stmt;
}

struct NullStmt @0xb57ca05aaf806566 {
  stmt @0:Stmt;
  semiUcToken @1 :Token;
  hasUcLeadingUcEmptyUcMacro @2 :Bool;
}

struct MSDependentExistsStmt @0xb5d9dfc73eeb0939 {
  stmt @0:Stmt;
  keywordUcToken @1 :Token;
  isUcIfUcExists @2 :Bool;
  isUcIfUcNotUcExists @3 :Bool;
}

struct IndirectGotoStmt @0xca063608491ba1fa {
  stmt @0:Stmt;
  gotoUcToken @1 :Token;
  starUcToken @2 :Token;
}

struct IfStmt @0xfc829da66c4e6bb1 {
  stmt @0:Stmt;
  elseUcToken @1 :Token;
  ifUcToken @2 :Token;
  lUcParenUcToken @3 :Token;
  rUcParenUcToken @4 :Token;
  hasUcElseUcStorage @5 :Bool;
  hasUcInitializerUcStorage @6 :Bool;
  hasUcVariableUcStorage @7 :Bool;
  isUcConstexpr @8 :Bool;
  isUcObjUcCUcAvailabilityUcCheck @9 :Bool;
}

struct GotoStmt @0xf542902873fc6c2b {
  stmt @0:Stmt;
  gotoUcToken @1 :Token;
  labelUcToken @2 :Token;
}

struct ForStmt @0xb6591c23541f6a1e {
  stmt @0:Stmt;
  forUcToken @1 :Token;
  lUcParenUcToken @2 :Token;
  rUcParenUcToken @3 :Token;
}

struct DoStmt @0xf6407ae4f3214356 {
  stmt @0:Stmt;
  doUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  whileUcToken @3 :Token;
}

struct DeclStmt @0xa672643824ce0ba3 {
  stmt @0:Stmt;
  isUcSingleUcDeclaration @1 :Bool;
}

struct CoroutineBodyStmt @0xac9fd8887bfea7d8 {
  stmt @0:Stmt;
  hasUcDependentUcPromiseUcType @1 :Bool;
}

struct CoreturnStmt @0xfada897216b226f1 {
  stmt @0:Stmt;
  keywordUcToken @1 :Token;
  isUcImplicit @2 :Bool;
}

struct ContinueStmt @0xb364bd3d9a19cd05 {
  stmt @0:Stmt;
  continueUcToken @1 :Token;
}

struct CompoundStmt @0xd080c9192fa41c92 {
  stmt @0:Stmt;
  lUcBracUcToken @1 :Token;
  rUcBracUcToken @2 :Token;
}

struct CapturedStmt @0xa60fffc1366b48e6 {
  stmt @0:Stmt;
  capturedUcRegionUcKind @1 :CapturedRegionKind;
}

struct CXXTryStmt @0xf98f02d4cdc2dd3b {
  stmt @0:Stmt;
  tryUcToken @1 :Token;
}

struct CXXForRangeStmt @0xa23a75b3c0fa7d86 {
  stmt @0:Stmt;
  coawaitUcToken @1 :Token;
  colonUcToken @2 :Token;
  forUcToken @3 :Token;
  rUcParenUcToken @4 :Token;
}

struct CXXCatchStmt @0xac4b9e8390fd3a85 {
  stmt @0:Stmt;
  catchUcToken @1 :Token;
}

struct BreakStmt @0x940efd4e9770cb41 {
  stmt @0:Stmt;
  breakUcToken @1 :Token;
}

struct AsmStmt @0xa47714ac2d00fb21 {
  stmt @0:Stmt;
  generateUcAssemblyUcString @1 :Text;
  assemblyUcToken @2 :Token;
  isUcSimple @3 :Bool;
  isUcVolatile @4 :Bool;
}

struct MSAsmStmt @0xc504268dee34a98f {
  asmUcStmt @0:AsmStmt;
  assemblyUcString @1 :Text;
  lUcBraceUcToken @2 :Token;
  hasUcBraces @3 :Bool;
}

struct GCCAsmStmt @0x9d046a0d94b425db {
  asmUcStmt @0:AsmStmt;
  rUcParenUcToken @1 :Token;
  isUcAssemblyUcGoto @2 :Bool;
}

struct WhileStmt @0x8f0fb0e808ef8cd3 {
  stmt @0:Stmt;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  whileUcToken @3 :Token;
  hasUcVariableUcStorage @4 :Bool;
}

struct ValueStmt @0xc78a8bda41f72525 {
  stmt @0:Stmt;
}

struct LabelStmt @0xed2b87febf6a7cc9 {
  valueUcStmt @0:ValueStmt;
  identifierUcToken @1 :Token;
  name @2 :Text;
  isUcSideUcEntry @3 :Bool;
}

struct Expr @0x9e4316b5a505b8d6 {
  valueUcStmt @0:ValueStmt;
  classifyUcLUcValue @1 :ExprLValueClassification;
  hasUcSideUcEffects @2 :Bool;
  containsUcErrors @3 :Bool;
  containsUcUnexpandedUcParameterUcPack @4 :Bool;
  expressionUcToken @5 :Token;
  objectUcKind @6 :ExprObjectKind;
  valueUcKind @7 :ExprValueKind;
  hasUcNonUcTrivialUcCall @8 :Bool;
  isUcBoundUcMemberUcFunction @9 :Bool;
  isUcCxUcX11UcConstantUcExpression @10 :Bool;
  isUcCxUcX98UcIntegralUcConstantUcExpression @11 :Bool;
  isUcDefaultUcArgument @12 :Bool;
  isUcEvaluatable @13 :Bool;
  isUcGlUcValue @14 :Bool;
  isUcImplicitUcCxxUcThis @15 :Bool;
  isUcInstantiationUcDependent @16 :Bool;
  isUcIntegerUcConstantUcExpression @17 :Bool;
  isUcKnownUcToUcHaveUcBooleanUcValue @18 :Bool;
  isUcLUcValue @19 :Bool;
  isUcModifiableUcLvalue @20 :ExprisModifiableLvalueResult;
  isUcObjcgcUcCandidate @21 :Bool;
  isUcObjUcCUcSelfUcExpression @22 :Bool;
  isUcOrdinaryUcOrUcBitUcFieldUcObject @23 :Bool;
  isUcPrUcValue @24 :Bool;
  isUcReadUcIfUcDiscardedUcInUcCUcPlusUcPlus11 @25 :Bool;
  isUcTypeUcDependent @26 :Bool;
  isUcValueUcDependent @27 :Bool;
  isUcXUcValue @28 :Bool;
  refersUcToUcBitUcField @29 :Bool;
  refersUcToUcGlobalUcRegisterUcVariable @30 :Bool;
  refersUcToUcMatrixUcElement @31 :Bool;
  refersUcToUcVectorUcElement @32 :Bool;
}

struct DesignatedInitUpdateExpr @0xaa6c77a8da7c4fba {
  expr @0:Expr;
}

struct DesignatedInitExpr @0xeff2c52d9c942ab2 {
  expr @0:Expr;
  designatorsUcSourceUcRange @1 :TokenRange;
  equalUcOrUcColonUcToken @2 :Token;
  isUcDirectUcInitializer @3 :Bool;
  usesUcGnuUcSyntax @4 :Bool;
}

struct DependentScopeDeclRefExpr @0x8fbb6ccb95a3509d {
  expr @0:Expr;
  lUcAngleUcToken @1 :Token;
  rUcAngleUcToken @2 :Token;
  templateUcKeywordUcToken @3 :Token;
  hasUcExplicitUcTemplateUcArguments @4 :Bool;
  hasUcTemplateUcKeyword @5 :Bool;
}

struct DependentCoawaitExpr @0x8fd8a27becb59315 {
  expr @0:Expr;
  keywordUcToken @1 :Token;
}

struct DeclRefExpr @0xec5119d27610b166 {
  expr @0:Expr;
  lUcAngleUcToken @1 :Token;
  rUcAngleUcToken @2 :Token;
  templateUcKeywordUcToken @3 :Token;
  hadUcMultipleUcCandidates @4 :Bool;
  hasUcExplicitUcTemplateUcArguments @5 :Bool;
  hasUcQualifier @6 :Bool;
  hasUcTemplateUcKwUcAndUcArgumentsUcInfo @7 :Bool;
  hasUcTemplateUcKeyword @8 :Bool;
  isUcNonUcOdrUcUse @9 :NonOdrUseReason;
  refersUcToUcEnclosingUcVariableUcOrUcCapture @10 :Bool;
}

struct CoroutineSuspendExpr @0xbd92ba696775fd54 {
  expr @0:Expr;
  keywordUcToken @1 :Token;
}

struct CoawaitExpr @0xab62e23bf872526e {
  coroutineUcSuspendUcExpr @0:CoroutineSuspendExpr;
  isUcImplicit @1 :Bool;
}

struct CoyieldExpr @0xe587a5c6d1b766ed {
  coroutineUcSuspendUcExpr @0:CoroutineSuspendExpr;
}

struct ConvertVectorExpr @0x9d71128cb240a509 {
  expr @0:Expr;
  builtinUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ConceptSpecializationExpr @0xfed5bd9e47227653 {
  expr @0:Expr;
  isUcSatisfied @1 :Bool;
}

struct CompoundLiteralExpr @0x9865eabaf4e2ef8c {
  expr @0:Expr;
  lUcParenUcToken @1 :Token;
  isUcFileUcScope @2 :Bool;
}

struct ChooseExpr @0xd4a658caf5a1339e {
  expr @0:Expr;
  builtinUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  isUcConditionUcDependent @3 :Bool;
  isUcConditionUcTrue @4 :Bool;
}

struct CharacterLiteral @0xbe144b3e9bdba5d9 {
  expr @0:Expr;
  token @1 :Token;
}

struct CastExpr @0x8cabd91ab4a4dcb3 {
  expr @0:Expr;
  castUcKind @1 :CastKind;
  castUcKindUcName @2 :Text;
  hasUcStoredUcFpUcFeatures @3 :Bool;
}

struct ImplicitCastExpr @0xf4659a194c7adcda {
  castUcExpr @0:CastExpr;
  isUcPartUcOfUcExplicitUcCast @1 :Bool;
}

struct ExplicitCastExpr @0xf68e68ae1ee44e91 {
  castUcExpr @0:CastExpr;
}

struct CXXNamedCastExpr @0x9edfd291691d4a7d {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  angleUcBrackets @1 :TokenRange;
  castUcName @2 :Text;
  operatorUcToken @3 :Token;
  rUcParenUcToken @4 :Token;
}

struct CXXDynamicCastExpr @0xb48d513e0fa1452b {
  cxxUcNamedUcCastUcExpr @0:CXXNamedCastExpr;
  isUcAlwaysUcNull @1 :Bool;
}

struct CXXConstCastExpr @0x8ee388e71866e008 {
  cxxUcNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXAddrspaceCastExpr @0x8065afafedfafb6a {
  cxxUcNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXStaticCastExpr @0xd307133180b20a1a {
  cxxUcNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXReinterpretCastExpr @0x9ff4423f70d9541a {
  cxxUcNamedUcCastUcExpr @0:CXXNamedCastExpr;
}

struct CXXFunctionalCastExpr @0xf2c246adc881d86c {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  isUcListUcInitialization @3 :Bool;
}

struct CStyleCastExpr @0xddb96d0ba671cd89 {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct BuiltinBitCastExpr @0xc4d665f00ba3fa8b {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
}

struct ObjCBridgedCastExpr @0xad38ef321a1ce1e3 {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  bridgeUcKeywordUcToken @1 :Token;
  bridgeUcKind @2 :ObjCBridgeCastKind;
  bridgeUcKindUcName @3 :Text;
  lUcParenUcToken @4 :Token;
}

struct CallExpr @0x8cff24c7f68e334b {
  expr @0:Expr;
  adlUcCallUcKind @1 :CallExprADLCallKind;
  rUcParenUcToken @2 :Token;
  hasUcStoredUcFpUcFeatures @3 :Bool;
  hasUcUnusedUcResultUcAttribute @4 :Bool;
  isUcBuiltinUcAssumeUcFalse @5 :Bool;
  isUcCallUcToUcStdUcMove @6 :Bool;
  isUcUnevaluatedUcBuiltinUcCall @7 :Bool;
  usesUcAdl @8 :Bool;
}

struct CXXOperatorCallExpr @0xb6a5653b33cdf0c5 {
  callUcExpr @0:CallExpr;
  operator @1 :OverloadedOperatorKind;
  operatorUcToken @2 :Token;
  isUcAssignmentUcOperation @3 :Bool;
  isUcComparisonUcOperation @4 :Bool;
  isUcInfixUcBinaryUcOperation @5 :Bool;
}

struct CXXMemberCallExpr @0x9a761539349dc02f {
  callUcExpr @0:CallExpr;
}

struct CUDAKernelCallExpr @0xd0bc1c26ca1e132f {
  callUcExpr @0:CallExpr;
}

struct UserDefinedLiteral @0xa1af860a6baa1029 {
  callUcExpr @0:CallExpr;
  literalUcOperatorUcKind @1 :UserDefinedLiteralLiteralOperatorKind;
  udUcSuffixUcToken @2 :Token;
}

struct CXXUuidofExpr @0xcdde7d28fc7931f6 {
  expr @0:Expr;
  isUcTypeUcOperand @1 :Bool;
}

struct CXXUnresolvedConstructExpr @0x9fbb7e373f171f86 {
  expr @0:Expr;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  isUcListUcInitialization @3 :Bool;
}

struct CXXTypeidExpr @0xf325d3531a387183 {
  expr @0:Expr;
  isUcMostUcDerived @1 :Bool;
  isUcPotentiallyUcEvaluated @2 :Bool;
  isUcTypeUcOperand @3 :Bool;
}

struct CXXThrowExpr @0x852a841374684e1e {
  expr @0:Expr;
  throwUcToken @1 :Token;
  isUcThrownUcVariableUcInUcScope @2 :Bool;
}

struct CXXThisExpr @0x959ba6d5fec8b422 {
  expr @0:Expr;
  token @1 :Token;
  isUcImplicit @2 :Bool;
}

struct CXXStdInitializerListExpr @0xd199eb3b19c592fa {
  expr @0:Expr;
}

struct CXXScalarValueInitExpr @0x9fd4b7d4985831e7 {
  expr @0:Expr;
  rUcParenUcToken @1 :Token;
}

struct CXXRewrittenBinaryOperator @0xd00648fa0bd5ccc4 {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeUcString @2 :Text;
  operator @3 :BinaryOperatorKind;
  operatorUcToken @4 :Token;
  isUcAssignmentUcOperation @5 :Bool;
  isUcComparisonUcOperation @6 :Bool;
  isUcReversed @7 :Bool;
}

struct CXXPseudoDestructorExpr @0xfb788932e740ac07 {
  expr @0:Expr;
  colonUcColonUcToken @1 :Token;
  destroyedUcTypeUcToken @2 :Token;
  operatorUcToken @3 :Token;
  tildeUcToken @4 :Token;
  hasUcQualifier @5 :Bool;
  isUcArrow @6 :Bool;
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
  doesUcUsualUcArrayUcDeleteUcWantUcSize @1 :Bool;
  directUcInitializerUcRange @2 :TokenRange;
  initializationUcStyle @3 :CXXNewExprInitializationStyle;
  typeUcIdUcParentheses @4 :TokenRange;
  hasUcInitializer @5 :Bool;
  isUcArray @6 :Bool;
  isUcGlobalUcNew @7 :Bool;
  isUcParenthesisUcTypeUcId @8 :Bool;
  passUcAlignment @9 :Bool;
  shouldUcNullUcCheckUcAllocation @10 :Bool;
}

struct CXXInheritedCtorInitExpr @0xd5db83de022b1ee3 {
  expr @0:Expr;
  constructsUcVirtualUcBase @1 :Bool;
  constructionUcKind @2 :CXXConstructExprConstructionKind;
  token @3 :Token;
  inheritedUcFromUcVirtualUcBase @4 :Bool;
}

struct CXXFoldExpr @0x8a593922e3ea9d50 {
  expr @0:Expr;
  ellipsisUcToken @1 :Token;
  lUcParenUcToken @2 :Token;
  operator @3 :BinaryOperatorKind;
  rUcParenUcToken @4 :Token;
  isUcLeftUcFold @5 :Bool;
  isUcRightUcFold @6 :Bool;
}

struct CXXDependentScopeMemberExpr @0xa1a21ac74e691c1f {
  expr @0:Expr;
  lUcAngleUcToken @1 :Token;
  memberUcToken @2 :Token;
  operatorUcToken @3 :Token;
  rUcAngleUcToken @4 :Token;
  templateUcKeywordUcToken @5 :Token;
  hasUcExplicitUcTemplateUcArguments @6 :Bool;
  hasUcTemplateUcKeyword @7 :Bool;
  isUcArrow @8 :Bool;
  isUcImplicitUcAccess @9 :Bool;
}

struct CXXDeleteExpr @0x80f6cd450a27b9d4 {
  expr @0:Expr;
  doesUcUsualUcArrayUcDeleteUcWantUcSize @1 :Bool;
  isUcArrayUcForm @2 :Bool;
  isUcArrayUcFormUcAsUcWritten @3 :Bool;
  isUcGlobalUcDelete @4 :Bool;
}

struct CXXDefaultInitExpr @0xa78e81b7ba8da8e6 {
  expr @0:Expr;
  usedUcToken @1 :Token;
}

struct CXXDefaultArgExpr @0x9f9ee9dcf349cbcf {
  expr @0:Expr;
  usedUcToken @1 :Token;
}

struct CXXConstructExpr @0xb3d036394c09ed48 {
  expr @0:Expr;
  constructionUcKind @1 :CXXConstructExprConstructionKind;
  token @2 :Token;
  parenthesisUcOrUcBraceUcRange @3 :TokenRange;
  hadUcMultipleUcCandidates @4 :Bool;
  isUcElidable @5 :Bool;
  isUcListUcInitialization @6 :Bool;
  isUcStdUcInitializerUcListUcInitialization @7 :Bool;
  requiresUcZeroUcInitialization @8 :Bool;
}

struct CXXTemporaryObjectExpr @0xb4be9b66753a2671 {
  cxxUcConstructUcExpr @0:CXXConstructExpr;
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
  caretUcToken @1 :Token;
}

struct BinaryOperator @0xd858b89bd116f05f {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeUcString @2 :Text;
  operatorUcToken @3 :Token;
  hasUcStoredUcFpUcFeatures @4 :Bool;
  isUcAdditiveUcOperation @5 :Bool;
  isUcAssignmentUcOperation @6 :Bool;
  isUcBitwiseUcOperation @7 :Bool;
  isUcCommaUcOperation @8 :Bool;
  isUcComparisonUcOperation @9 :Bool;
  isUcCompoundUcAssignmentUcOperation @10 :Bool;
  isUcEqualityUcOperation @11 :Bool;
  isUcLogicalUcOperation @12 :Bool;
  isUcMultiplicativeUcOperation @13 :Bool;
  isUcPointerUcMemoryUcOperation @14 :Bool;
  isUcRelationalUcOperation @15 :Bool;
  isUcShiftUcAssignUcOperation @16 :Bool;
  isUcShiftUcOperation @17 :Bool;
}

struct CompoundAssignOperator @0xe6e7bc711d327cb9 {
  binaryUcOperator @0:BinaryOperator;
}

struct AtomicExpr @0xc730b6c3f33ecb9f {
  expr @0:Expr;
  builtinUcToken @1 :Token;
  operation @2 :AtomicExprAtomicOp;
  rUcParenUcToken @3 :Token;
  isUcCmpUcXUcChg @4 :Bool;
  isUcOpenUcCl @5 :Bool;
  isUcVolatile @6 :Bool;
}

struct AsTypeExpr @0xf646590167dcf1ab {
  expr @0:Expr;
  builtinUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ArrayTypeTraitExpr @0xcbcb35a78956a3cc {
  expr @0:Expr;
  trait @1 :ArrayTypeTrait;
}

struct ArraySubscriptExpr @0xb5bb680da7ccce33 {
  expr @0:Expr;
  rUcBracketUcToken @1 :Token;
}

struct ArrayInitLoopExpr @0xbe95601783117ebe {
  expr @0:Expr;
}

struct ArrayInitIndexExpr @0xc9bc62bebe2cdbb8 {
  expr @0:Expr;
}

struct AddrLabelExpr @0xc1abc55fece6aa91 {
  expr @0:Expr;
  ampUcAmpUcToken @1 :Token;
  labelUcToken @2 :Token;
}

struct AbstractConditionalOperator @0xee7097774f7aaa45 {
  expr @0:Expr;
  colonUcToken @1 :Token;
  questionUcToken @2 :Token;
}

struct ConditionalOperator @0xd3810312a3bd13c7 {
  abstractUcConditionalUcOperator @0:AbstractConditionalOperator;
}

struct BinaryConditionalOperator @0xde5f047672b1ac84 {
  abstractUcConditionalUcOperator @0:AbstractConditionalOperator;
}

struct VAArgExpr @0x8fa746d782ee27c9 {
  expr @0:Expr;
  builtinUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  isUcMicrosoftUcAbi @3 :Bool;
}

struct UnaryOperator @0xaa78820aaa7f22b8 {
  expr @0:Expr;
  canUcOverflow @1 :Bool;
  opcode @2 :UnaryOperatorKind;
  operatorUcToken @3 :Token;
  hasUcStoredUcFpUcFeatures @4 :Bool;
  isUcArithmeticUcOperation @5 :Bool;
  isUcDecrementUcOperation @6 :Bool;
  isUcIncrementUcDecrementUcOperation @7 :Bool;
  isUcIncrementUcOperation @8 :Bool;
  isUcPostfix @9 :Bool;
  isUcPrefix @10 :Bool;
}

struct UnaryExprOrTypeTraitExpr @0xbc37e32561d53a59 {
  expr @0:Expr;
  operatorUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  isUcArgumentUcType @3 :Bool;
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
  parameterUcPackUcToken @1 :Token;
}

struct SubstNonTypeTemplateParmExpr @0xad38ba4bfe617a6f {
  expr @0:Expr;
  nameUcToken @1 :Token;
  isUcReferenceUcParameter @2 :Bool;
}

struct StringLiteral @0xd0cec44e02f59cf2 {
  expr @0:Expr;
  containsUcNonUcAscii @1 :Bool;
  containsUcNonUcAsciiUcOrUcNull @2 :Bool;
  bytes @3 :Text;
  string @4 :Text;
  isUcAscii @5 :Bool;
  isUcPascal @6 :Bool;
  isUcUtUcF16 @7 :Bool;
  isUcUtUcF32 @8 :Bool;
  isUcUtUcF8 @9 :Bool;
  isUcWide @10 :Bool;
}

struct StmtExpr @0xe3606abe04461b8a {
  expr @0:Expr;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct SourceLocExpr @0xd4bebb374e1e6d58 {
  expr @0:Expr;
  builtinUcString @1 :Text;
  identifierUcKind @2 :SourceLocExprIdentKind;
  token @3 :Token;
  isUcIntUcType @4 :Bool;
  isUcStringUcType @5 :Bool;
}

struct SizeOfPackExpr @0xa4f777d7b3ce890c {
  expr @0:Expr;
  operatorUcToken @1 :Token;
  packUcToken @2 :Token;
  rUcParenUcToken @3 :Token;
  isUcPartiallyUcSubstituted @4 :Bool;
}

struct ShuffleVectorExpr @0xdfa87964ccc4abd6 {
  expr @0:Expr;
  builtinUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct SYCLUniqueStableNameExpr @0xfa67d59d16f9a78a {
  expr @0:Expr;
  computeUcName @1 :Text;
  lUcParenUcToken @2 :Token;
  token @3 :Token;
  rUcParenUcToken @4 :Token;
}

struct RequiresExpr @0xe4f5db5ba506ab26 {
  expr @0:Expr;
  rUcBraceUcToken @1 :Token;
  requiresUcKwUcToken @2 :Token;
  isUcSatisfied @3 :Bool;
}

struct RecoveryExpr @0xa9e048a5bbe9f6bd {
  expr @0:Expr;
}

struct PseudoObjectExpr @0xf7795b8660a50a1e {
  expr @0:Expr;
}

struct PredefinedExpr @0xf512f62d75089164 {
  expr @0:Expr;
  identifierUcKind @1 :PredefinedExprIdentKind;
  identifierUcKindUcName @2 :Text;
  token @3 :Token;
}

struct ParenListExpr @0xc7ba76bb20cf6201 {
  expr @0:Expr;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ParenExpr @0x821bf890921895cd {
  expr @0:Expr;
  lUcParen @1 :Token;
  rUcParen @2 :Token;
}

struct PackExpansionExpr @0xbf1eafc846bba2e0 {
  expr @0:Expr;
  ellipsisUcToken @1 :Token;
}

struct OverloadExpr @0xe1320ca92341cff5 {
  expr @0:Expr;
  lUcAngleUcToken @1 :Token;
  nameUcToken @2 :Token;
  rUcAngleUcToken @3 :Token;
  templateUcKeywordUcToken @4 :Token;
  hasUcExplicitUcTemplateUcArguments @5 :Bool;
  hasUcTemplateUcKeyword @6 :Bool;
}

struct UnresolvedMemberExpr @0xbd4aeea6486879d1 {
  overloadUcExpr @0:OverloadExpr;
  memberUcToken @1 :Token;
  operatorUcToken @2 :Token;
  hasUcUnresolvedUcUsing @3 :Bool;
  isUcArrow @4 :Bool;
  isUcImplicitUcAccess @5 :Bool;
}

struct UnresolvedLookupExpr @0xd04212a95a4ab25d {
  overloadUcExpr @0:OverloadExpr;
  isUcOverloaded @1 :Bool;
  requiresUcAdl @2 :Bool;
}

struct OpaqueValueExpr @0xd0ebba3413f46f6d {
  expr @0:Expr;
  token @1 :Token;
  isUcUnique @2 :Bool;
}

struct OffsetOfExpr @0xe74e51b681474f08 {
  expr @0:Expr;
  operatorUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ObjCSubscriptRefExpr @0x827d6564c3126c7a {
  expr @0:Expr;
  rUcBracket @1 :Token;
  isUcArrayUcSubscriptUcReferenceUcExpression @2 :Bool;
}

struct ObjCStringLiteral @0x84470e968f7365fb {
  expr @0:Expr;
  atUcToken @1 :Token;
}

struct ObjCSelectorExpr @0xa6687e4a6275988d {
  expr @0:Expr;
  atUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ObjCProtocolExpr @0xb07709e6d6281804 {
  expr @0:Expr;
  atUcToken @1 :Token;
  protocolUcIdUcToken @2 :Token;
  rUcParenUcToken @3 :Token;
}

struct ObjCPropertyRefExpr @0x9f75c18ee7f1c7a2 {
  expr @0:Expr;
  token @1 :Token;
  receiverUcToken @2 :Token;
  isUcClassUcReceiver @3 :Bool;
  isUcExplicitUcProperty @4 :Bool;
  isUcImplicitUcProperty @5 :Bool;
  isUcMessagingUcGetter @6 :Bool;
  isUcMessagingUcSetter @7 :Bool;
  isUcObjectUcReceiver @8 :Bool;
  isUcSuperUcReceiver @9 :Bool;
}

struct ObjCMessageExpr @0xc53f62c71ed8d723 {
  expr @0:Expr;
  leftUcToken @1 :Token;
  methodUcFamily @2 :ObjCMethodFamily;
  receiverUcKind @3 :ObjCMessageExprReceiverKind;
  receiverUcRange @4 :TokenRange;
  rightUcToken @5 :Token;
  selectorUcStartUcToken @6 :Token;
  superUcToken @7 :Token;
  isUcClassUcMessage @8 :Bool;
  isUcDelegateUcInitializerUcCall @9 :Bool;
  isUcImplicit @10 :Bool;
  isUcInstanceUcMessage @11 :Bool;
}

struct ObjCIvarRefExpr @0xec7058b5b38773dd {
  expr @0:Expr;
  token @1 :Token;
  operationUcToken @2 :Token;
  isUcArrow @3 :Bool;
  isUcFreeUcInstanceUcVariable @4 :Bool;
}

struct ObjCIsaExpr @0xe3c04c83aef329c8 {
  expr @0:Expr;
  baseUcTokenUcEnd @1 :Token;
  isaUcMemberUcToken @2 :Token;
  operationUcToken @3 :Token;
  isUcArrow @4 :Bool;
}

struct ObjCIndirectCopyRestoreExpr @0x9475cc6d12ba1afb {
  expr @0:Expr;
  shouldUcCopy @1 :Bool;
}

struct ObjCEncodeExpr @0x911855b6fa2d9812 {
  expr @0:Expr;
  atUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct ObjCDictionaryLiteral @0xaef4d291186415b7 {
  expr @0:Expr;
}

struct ObjCBoxedExpr @0xae80861f1a63c950 {
  expr @0:Expr;
  atUcToken @1 :Token;
  isUcExpressibleUcAsUcConstantUcInitializer @2 :Bool;
}

struct ObjCBoolLiteralExpr @0xb2d027f2c8cad1fb {
  expr @0:Expr;
  token @1 :Token;
  value @2 :Bool;
}

struct ObjCAvailabilityCheckExpr @0xbd477d54907fe95a {
  expr @0:Expr;
  hasUcVersion @1 :Bool;
}

struct ObjCArrayLiteral @0xa36b5cac081b468a {
  expr @0:Expr;
}

struct OMPIteratorExpr @0xd52a7668addb282d {
  expr @0:Expr;
  iteratorUcKwUcToken @1 :Token;
  lUcParenUcToken @2 :Token;
  rUcParenUcToken @3 :Token;
}

struct OMPArrayShapingExpr @0xcddd3cf38d603be1 {
  expr @0:Expr;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
}

struct OMPArraySectionExpr @0xca2808db37aea2e0 {
  expr @0:Expr;
  colonUcTokenUcFirst @1 :Token;
  colonUcTokenUcSecond @2 :Token;
  rUcBracketUcToken @3 :Token;
}

struct NoInitExpr @0xadedf240a5b5d3d1 {
  expr @0:Expr;
}

struct MemberExpr @0xd8c89de1fe446ed0 {
  expr @0:Expr;
  lUcAngleUcToken @1 :Token;
  memberUcToken @2 :Token;
  operatorUcToken @3 :Token;
  rUcAngleUcToken @4 :Token;
  templateUcKeywordUcToken @5 :Token;
  hadUcMultipleUcCandidates @6 :Bool;
  hasUcExplicitUcTemplateUcArguments @7 :Bool;
  hasUcQualifier @8 :Bool;
  hasUcTemplateUcKeyword @9 :Bool;
  isUcArrow @10 :Bool;
  isUcImplicitUcAccess @11 :Bool;
  isUcNonUcOdrUcUse @12 :NonOdrUseReason;
}

struct MatrixSubscriptExpr @0xc6e8f0398e560e56 {
  expr @0:Expr;
  rUcBracketUcToken @1 :Token;
  isUcIncomplete @2 :Bool;
}

struct MaterializeTemporaryExpr @0x81f0ffa9f501c48d {
  expr @0:Expr;
  storageUcDuration @1 :StorageDuration;
  isUcBoundUcToUcLvalueUcReference @2 :Bool;
  isUcUsableUcInUcConstantUcExpressions @3 :Bool;
}

struct MSPropertySubscriptExpr @0xdca78c710e8a0bc9 {
  expr @0:Expr;
  rUcBracketUcToken @1 :Token;
}

struct MSPropertyRefExpr @0xb14da9f10b21425d {
  expr @0:Expr;
  memberUcToken @1 :Token;
  isUcArrow @2 :Bool;
  isUcImplicitUcAccess @3 :Bool;
}

struct LambdaExpr @0xd1773aeaaf57de49 {
  expr @0:Expr;
  captureUcDefault @1 :LambdaCaptureDefault;
  captureUcDefaultUcToken @2 :Token;
  introducerUcRange @3 :TokenRange;
  hasUcExplicitUcParameters @4 :Bool;
  hasUcExplicitUcResultUcType @5 :Bool;
  isUcGenericUcLambda @6 :Bool;
  isUcMutable @7 :Bool;
}

struct IntegerLiteral @0x9555503bb691c665 {
  expr @0:Expr;
  token @1 :Token;
}

struct InitListExpr @0xee5bc39a46a85bfd {
  expr @0:Expr;
  lUcBraceUcToken @1 :Token;
  rUcBraceUcToken @2 :Token;
  hadUcArrayUcRangeUcDesignator @3 :Bool;
  hasUcArrayUcFiller @4 :Bool;
  isUcExplicit @5 :Bool;
  isUcSemanticUcForm @6 :Bool;
  isUcStringUcLiteralUcInitializer @7 :Bool;
  isUcSyntacticUcForm @8 :Bool;
  isUcTransparent @9 :Bool;
}

struct ImplicitValueInitExpr @0xa74a9776ddeaccc0 {
  expr @0:Expr;
}

struct ImaginaryLiteral @0xe6373a2b8f6af5f3 {
  expr @0:Expr;
}

struct GenericSelectionExpr @0xb9c714e9030a2703 {
  expr @0:Expr;
  defaultUcToken @1 :Token;
  genericUcToken @2 :Token;
  rUcParenUcToken @3 :Token;
  isUcResultUcDependent @4 :Bool;
}

struct GNUNullExpr @0xed67a32bfb3e1820 {
  expr @0:Expr;
  tokenUcToken @1 :Token;
}

struct FunctionParmPackExpr @0x9b1418ed71492c60 {
  expr @0:Expr;
  parameterUcPackUcToken @1 :Token;
}

struct FullExpr @0x823209f8d52ac4fb {
  expr @0:Expr;
}

struct ExprWithCleanups @0x8caff3daad0879d0 {
  fullUcExpr @0:FullExpr;
  cleanupsUcHaveUcSideUcEffects @1 :Bool;
}

struct ConstantExpr @0xb118d0dca5dbdf6e {
  fullUcExpr @0:FullExpr;
  resultUcStorageUcKind @1 :ConstantExprResultStorageKind;
  hasUcApUcValueUcResult @2 :Bool;
  isUcImmediateUcInvocation @3 :Bool;
}

struct FloatingLiteral @0xf9afab4b69f8f504 {
  expr @0:Expr;
  token @1 :Token;
  isUcExact @2 :Bool;
}

struct FixedPointLiteral @0xb376f274c18baf5a {
  expr @0:Expr;
  token @1 :Token;
}

struct ExtVectorElementExpr @0xba6c9e86786ed31a {
  expr @0:Expr;
  containsUcDuplicateUcElements @1 :Bool;
  accessorUcToken @2 :Token;
  isUcArrow @3 :Bool;
}

struct ExpressionTraitExpr @0xf53890283fc830c0 {
  expr @0:Expr;
  trait @1 :ExpressionTrait;
  value @2 :Bool;
}

struct AttributedStmt @0xc33cd79cc9238608 {
  valueUcStmt @0:ValueStmt;
  attributeUcToken @1 :Token;
}

struct SwitchStmt @0x8f2566a2d81612cd {
  stmt @0:Stmt;
  lUcParenUcToken @1 :Token;
  rUcParenUcToken @2 :Token;
  switchUcToken @3 :Token;
  hasUcInitializerUcStorage @4 :Bool;
  hasUcVariableUcStorage @5 :Bool;
  isUcAllUcEnumUcCasesUcCovered @6 :Bool;
}

struct SwitchCase @0xeecb8bb11e4c8ed7 {
  stmt @0:Stmt;
  colonUcToken @1 :Token;
  keywordUcToken @2 :Token;
}

struct DefaultStmt @0xf8ae119f01317845 {
  switchUcCase @0:SwitchCase;
  defaultUcToken @1 :Token;
}

struct CaseStmt @0x829897c890006599 {
  switchUcCase @0:SwitchCase;
  caseUcStatementUcIsUcGnuUcRange @1 :Bool;
  caseUcToken @2 :Token;
  ellipsisUcToken @3 :Token;
}

struct Type @0xd739e808bc1b3fd7 {
  acceptsUcObjUcCUcTypeUcParams @0 :Bool;
  canUcDecayUcToUcPointerUcType @1 :Bool;
  canUcHaveUcNullability @2 :Bool;
  containsUcErrors @3 :Bool;
  containsUcUnexpandedUcParameterUcPack @4 :Bool;
  linkage @5 :Linkage;
  scalarUcTypeUcKind @6 :TypeScalarTypeKind;
  kind @7 :TypeKind;
  visibility @8 :Visibility;
  hasUcAutoUcForUcTrailingUcReturnUcType @9 :Bool;
  hasUcFloatingUcRepresentation @10 :Bool;
  hasUcIntegerUcRepresentation @11 :Bool;
  hasUcObjUcCUcPointerUcRepresentation @12 :Bool;
  hasUcPointerUcRepresentation @13 :Bool;
  hasUcSignedUcIntegerUcRepresentation @14 :Bool;
  hasUcSizedUcVlaUcType @15 :Bool;
  hasUcUnnamedUcOrUcLocalUcType @16 :Bool;
  hasUcUnsignedUcIntegerUcRepresentation @17 :Bool;
  isUcAggregateUcType @18 :Bool;
  isUcAlignUcValUcT @19 :Bool;
  isUcAnyUcCharacterUcType @20 :Bool;
  isUcAnyUcComplexUcType @21 :Bool;
  isUcAnyUcPointerUcType @22 :Bool;
  isUcArithmeticUcType @23 :Bool;
  isUcArrayUcType @24 :Bool;
  isUcAtomicUcType @25 :Bool;
  isUcBUcFloat16UcType @26 :Bool;
  isUcBlockUcCompatibleUcObjUcCUcPointerUcType @27 :Bool;
  isUcBlockUcPointerUcType @28 :Bool;
  isUcBooleanUcType @29 :Bool;
  isUcBuiltinUcType @30 :Bool;
  isUcCarcUcBridgableUcType @31 :Bool;
  isUcCudaUcDeviceUcBuiltinUcSurfaceUcType @32 :Bool;
  isUcCudaUcDeviceUcBuiltinUcTextureUcType @33 :Bool;
  isUcCanonicalUcUnqualified @34 :Bool;
  isUcChar16UcType @35 :Bool;
  isUcChar32UcType @36 :Bool;
  isUcChar8UcType @37 :Bool;
  isUcCharacterUcType @38 :Bool;
  isUcClassUcType @39 :Bool;
  isUcClkUcEventUcT @40 :Bool;
  isUcComplexUcIntegerUcType @41 :Bool;
  isUcComplexUcType @42 :Bool;
  isUcCompoundUcType @43 :Bool;
  isUcConstantUcArrayUcType @44 :Bool;
  isUcConstantUcMatrixUcType @45 :Bool;
  isUcConstantUcSizeUcType @46 :Bool;
  isUcDecltypeUcType @47 :Bool;
  isUcDependentUcAddressUcSpaceUcType @48 :Bool;
  isUcDependentUcSizedUcArrayUcType @49 :Bool;
  isUcDependentUcType @50 :Bool;
  isUcElaboratedUcTypeUcSpecifier @51 :Bool;
  isUcEnumeralUcType @52 :Bool;
  isUcEventUcT @53 :Bool;
  isUcExtUcIntUcType @54 :Bool;
  isUcExtUcVectorUcType @55 :Bool;
  isUcFixedUcPointUcOrUcIntegerUcType @56 :Bool;
  isUcFixedUcPointUcType @57 :Bool;
  isUcFloat128UcType @58 :Bool;
  isUcFloat16UcType @59 :Bool;
  isUcFloatingUcType @60 :Bool;
  isUcFromUcAst @61 :Bool;
  isUcFunctionUcNoUcProtoUcType @62 :Bool;
  isUcFunctionUcPointerUcType @63 :Bool;
  isUcFunctionUcProtoUcType @64 :Bool;
  isUcFunctionUcReferenceUcType @65 :Bool;
  isUcFunctionUcType @66 :Bool;
  isUcFundamentalUcType @67 :Bool;
  isUcHalfUcType @68 :Bool;
  isUcImageUcType @69 :Bool;
  isUcIncompleteUcArrayUcType @70 :Bool;
  isUcIncompleteUcOrUcObjectUcType @71 :Bool;
  isUcIncompleteUcType @72 :Bool;
  isUcInstantiationUcDependentUcType @73 :Bool;
  isUcIntegerUcType @74 :Bool;
  isUcIntegralUcOrUcEnumerationUcType @75 :Bool;
  isUcIntegralUcOrUcUnscopedUcEnumerationUcType @76 :Bool;
  isUcIntegralUcType @77 :Bool;
  isUcInterfaceUcType @78 :Bool;
  isUcLUcValueUcReferenceUcType @79 :Bool;
  isUcLinkageUcValid @80 :Bool;
  isUcLiteralUcType @81 :Bool;
  isUcMatrixUcType @82 :Bool;
  isUcMemberUcDataUcPointerUcType @83 :Bool;
  isUcMemberUcFunctionUcPointerUcType @84 :Bool;
  isUcMemberUcPointerUcType @85 :Bool;
  isUcNonUcOverloadUcPlaceholderUcType @86 :Bool;
  isUcNothrowUcT @87 :Bool;
  isUcNullUcPointerUcType @88 :Bool;
  isUcOclUcExtUcOpaqueUcType @89 :Bool;
  isUcOclUcImage1UcDarrayUcRoUcType @90 :Bool;
  isUcOclUcImage1UcDarrayUcRwUcType @91 :Bool;
  isUcOclUcImage1UcDarrayUcWoUcType @92 :Bool;
  isUcOclUcImage1UcDbufferUcRoUcType @93 :Bool;
  isUcOclUcImage1UcDbufferUcRwUcType @94 :Bool;
  isUcOclUcImage1UcDbufferUcWoUcType @95 :Bool;
  isUcOclUcImage1UcDroUcType @96 :Bool;
  isUcOclUcImage1UcDrwUcType @97 :Bool;
  isUcOclUcImage1UcDwoUcType @98 :Bool;
  isUcOclUcImage2UcDarrayUcDepthUcRoUcType @99 :Bool;
  isUcOclUcImage2UcDarrayUcDepthUcRwUcType @100 :Bool;
  isUcOclUcImage2UcDarrayUcDepthUcWoUcType @101 :Bool;
  isUcOclUcImage2UcDarrayUcMsaaUcDepthUcRoUcType @102 :Bool;
  isUcOclUcImage2UcDarrayUcMsaaUcDepthUcRwUcType @103 :Bool;
  isUcOclUcImage2UcDarrayUcMsaaUcDepthUcWoUcType @104 :Bool;
  isUcOclUcImage2UcDarrayUcMsaaroUcType @105 :Bool;
  isUcOclUcImage2UcDarrayUcMsaarwUcType @106 :Bool;
  isUcOclUcImage2UcDarrayUcMsaawoUcType @107 :Bool;
  isUcOclUcImage2UcDarrayUcRoUcType @108 :Bool;
  isUcOclUcImage2UcDarrayUcRwUcType @109 :Bool;
  isUcOclUcImage2UcDarrayUcWoUcType @110 :Bool;
  isUcOclUcImage2UcDdepthUcRoUcType @111 :Bool;
  isUcOclUcImage2UcDdepthUcRwUcType @112 :Bool;
  isUcOclUcImage2UcDdepthUcWoUcType @113 :Bool;
  isUcOclUcImage2UcDmsaaUcDepthUcRoUcType @114 :Bool;
  isUcOclUcImage2UcDmsaaUcDepthUcRwUcType @115 :Bool;
  isUcOclUcImage2UcDmsaaUcDepthUcWoUcType @116 :Bool;
  isUcOclUcImage2UcDmsaaroUcType @117 :Bool;
  isUcOclUcImage2UcDmsaarwUcType @118 :Bool;
  isUcOclUcImage2UcDmsaawoUcType @119 :Bool;
  isUcOclUcImage2UcDroUcType @120 :Bool;
  isUcOclUcImage2UcDrwUcType @121 :Bool;
  isUcOclUcImage2UcDwoUcType @122 :Bool;
  isUcOclUcImage3UcDroUcType @123 :Bool;
  isUcOclUcImage3UcDrwUcType @124 :Bool;
  isUcOclUcImage3UcDwoUcType @125 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcDualUcReferenceUcStreaminUcType @126 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcPayloadUcType @127 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcResultUcDualUcReferenceUcStreamoutUcType @128 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcResultUcSingleUcReferenceUcStreamoutUcType @129 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcResultUcType @130 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcSingleUcReferenceUcStreaminUcType @131 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcMceUcPayloadUcType @132 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcMceUcResultUcType @133 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcRefUcPayloadUcType @134 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcRefUcResultUcType @135 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcSicUcPayloadUcType @136 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcSicUcResultUcType @137 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcType @138 :Bool;
  isUcObjUcCarcUcBridgableUcType @139 :Bool;
  isUcObjUcCarcUcImplicitlyUcUnretainedUcType @140 :Bool;
  isUcObjUcCUcBoxableUcRecordUcType @141 :Bool;
  isUcObjUcCUcBuiltinUcType @142 :Bool;
  isUcObjUcCUcClassUcOrUcClassUcKindUcOfUcType @143 :Bool;
  isUcObjUcCUcClassUcType @144 :Bool;
  isUcObjUcCUcIdUcType @145 :Bool;
  isUcObjUcCUcIndependentUcClassUcType @146 :Bool;
  isUcObjUcCUcIndirectUcLifetimeUcType @147 :Bool;
  isUcObjUcCUcInertUcUnsafeUcUnretainedUcType @148 :Bool;
  isUcObjUcCUcLifetimeUcType @149 :Bool;
  isUcObjUcCnsUcObjectUcType @150 :Bool;
  isUcObjUcCUcObjectUcOrUcInterfaceUcType @151 :Bool;
  isUcObjUcCUcObjectUcPointerUcType @152 :Bool;
  isUcObjUcCUcObjectUcType @153 :Bool;
  isUcObjUcCUcQualifiedUcClassUcType @154 :Bool;
  isUcObjUcCUcQualifiedUcIdUcType @155 :Bool;
  isUcObjUcCUcQualifiedUcInterfaceUcType @156 :Bool;
  isUcObjUcCUcRetainableUcType @157 :Bool;
  isUcObjUcCUcSelUcType @158 :Bool;
  isUcObjectUcPointerUcType @159 :Bool;
  isUcObjectUcType @160 :Bool;
  isUcOpenUcClUcSpecificUcType @161 :Bool;
  isUcOverloadableUcType @162 :Bool;
  isUcPipeUcType @163 :Bool;
  isUcPlaceholderUcType @164 :Bool;
  isUcPointerUcType @165 :Bool;
  isUcPromotableUcIntegerUcType @166 :Bool;
  isUcQueueUcT @167 :Bool;
  isUcRUcValueUcReferenceUcType @168 :Bool;
  isUcRealUcFloatingUcType @169 :Bool;
  isUcRealUcType @170 :Bool;
  isUcRecordUcType @171 :Bool;
  isUcReferenceUcType @172 :Bool;
  isUcReserveUcIdt @173 :Bool;
  isUcSamplerUcT @174 :Bool;
  isUcSaturatedUcFixedUcPointUcType @175 :Bool;
  isUcScalarUcType @176 :Bool;
  isUcScopedUcEnumeralUcType @177 :Bool;
  isUcSignedUcFixedUcPointUcType @178 :Bool;
  isUcSignedUcIntegerUcOrUcEnumerationUcType @179 :Bool;
  isUcSignedUcIntegerUcType @180 :Bool;
  isUcSizelessUcBuiltinUcType @181 :Bool;
  isUcSizelessUcType @182 :Bool;
  isUcSpecifierUcType @183 :Bool;
  isUcStandardUcLayoutUcType @184 :Bool;
  isUcStdUcByteUcType @185 :Bool;
  isUcStructuralUcType @186 :Bool;
  isUcStructureUcOrUcClassUcType @187 :Bool;
  isUcStructureUcType @188 :Bool;
  isUcTemplateUcTypeUcParmUcType @189 :Bool;
  isUcTypedefUcNameUcType @190 :Bool;
  isUcUndeducedUcAutoUcType @191 :Bool;
  isUcUndeducedUcType @192 :Bool;
  isUcUnionUcType @193 :Bool;
  isUcUnsaturatedUcFixedUcPointUcType @194 :Bool;
  isUcUnscopedUcEnumerationUcType @195 :Bool;
  isUcUnsignedUcFixedUcPointUcType @196 :Bool;
  isUcUnsignedUcIntegerUcOrUcEnumerationUcType @197 :Bool;
  isUcUnsignedUcIntegerUcType @198 :Bool;
  isUcVlstUcBuiltinUcType @199 :Bool;
  isUcVariableUcArrayUcType @200 :Bool;
  isUcVariablyUcModifiedUcType @201 :Bool;
  isUcVectorUcType @202 :Bool;
  isUcVisibilityUcExplicit @203 :Bool;
  isUcVoidUcPointerUcType @204 :Bool;
  isUcVoidUcType @205 :Bool;
  isUcWideUcCharacterUcType @206 :Bool;
  isUcQualified @207 :Bool;
  addressUcSpace @208 :LangAS;
  hasUcAddressUcSpace @209 :Bool;
  hasUcLocalUcNonUcFastUcQualifiers @210 :Bool;
  hasUcLocalUcQualifiers @211 :Bool;
  hasUcNonUcTrivialUcObjUcCUcLifetime @212 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcCopyUcCUcUnion @213 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitializeUcCUcUnion @214 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDestructUcCUcUnion @215 :Bool;
  hasUcQualifiers @216 :Bool;
  hasUcStrongUcOrUcWeakUcObjUcCUcLifetime @217 :Bool;
  isUcCUcForbiddenUcLUcValueUcType @218 :Bool;
  isUcCxUcX11UcPodUcType @219 :Bool;
  isUcCxUcX98UcPodUcType @220 :Bool;
  isUcCanonical @221 :Bool;
  isUcCanonicalUcAsUcParam @222 :Bool;
  isUcConstUcQualified @223 :Bool;
  isUcConstant @224 :Bool;
  isUcDestructedUcType @225 :QualTypeDestructionKind;
  isUcLocalUcConstUcQualified @226 :Bool;
  isUcLocalUcRestrictUcQualified @227 :Bool;
  isUcLocalUcVolatileUcQualified @228 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcCopy @229 :QualTypePrimitiveCopyKind;
  isUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitialize @230 :QualTypePrimitiveDefaultInitializeKind;
  isUcNonUcTrivialUcToUcPrimitiveUcDestructiveUcMove @231 :QualTypePrimitiveCopyKind;
  isUcNonUcWeakUcInUcMrrUcWithUcObjUcCUcWeak @232 :Bool;
  isUcNull @233 :Bool;
  isUcObjUcCgcUcStrong @234 :Bool;
  isUcObjUcCgcUcWeak @235 :Bool;
  isUcPodUcType @236 :Bool;
  isUcRestrictUcQualified @237 :Bool;
  isUcTrivialUcType @238 :Bool;
  isUcTriviallyUcCopyableUcType @239 :Bool;
  isUcVolatileUcQualified @240 :Bool;
  mayUcBeUcDynamicUcClass @241 :Bool;
  mayUcBeUcNotUcDynamicUcClass @242 :Bool;
}

struct TemplateTypeParmType @0xe786690ae408805f {
  type @0:Type;
  isUcParameterUcPack @1 :Bool;
  isUcSugared @2 :Bool;
}

struct TemplateSpecializationType @0xfa056c60dc6c1e09 {
  type @0:Type;
  isUcCurrentUcInstantiation @1 :Bool;
  isUcSugared @2 :Bool;
  isUcTypeUcAlias @3 :Bool;
}

struct TagType @0xc5f6e35856974d9c {
  type @0:Type;
  isUcBeingUcDefined @1 :Bool;
}

struct RecordType @0xa5a5c23895050f69 {
  tagUcType @0:TagType;
  hasUcConstUcFields @1 :Bool;
  isUcSugared @2 :Bool;
}

struct EnumType @0xeceb1819da64112c {
  tagUcType @0:TagType;
  isUcSugared @1 :Bool;
}

struct SubstTemplateTypeParmType @0x8be567616218a913 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct SubstTemplateTypeParmPackType @0x8e845eb2b04a7eee {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ReferenceType @0xf0b00042a60e0b80 {
  type @0:Type;
  isUcInnerUcReference @1 :Bool;
  isUcSpelledUcAsUcLUcValue @2 :Bool;
}

struct RValueReferenceType @0xbecf2238a530256c {
  referenceUcType @0:ReferenceType;
  isUcSugared @1 :Bool;
}

struct LValueReferenceType @0xc3ffdde8d840e1f8 {
  referenceUcType @0:ReferenceType;
  isUcSugared @1 :Bool;
}

struct PointerType @0xbfb931627d65b65e {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct PipeType @0xa153518ebe860937 {
  type @0:Type;
  isUcReadUcOnly @1 :Bool;
  isUcSugared @2 :Bool;
}

struct ParenType @0xff7efc28ab285ec4 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct PackExpansionType @0xd267d004a8c359b6 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ObjCTypeParamType @0xac0ad54259298e1c {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ObjCObjectType @0xdb7630160ba51f56 {
  type @0:Type;
  isUcKindUcOfUcType @1 :Bool;
  isUcKindUcOfUcTypeUcAsUcWritten @2 :Bool;
  isUcObjUcCUcClass @3 :Bool;
  isUcObjUcCUcId @4 :Bool;
  isUcObjUcCUcQualifiedUcClass @5 :Bool;
  isUcObjUcCUcQualifiedUcId @6 :Bool;
  isUcObjUcCUcUnqualifiedUcClass @7 :Bool;
  isUcObjUcCUcUnqualifiedUcId @8 :Bool;
  isUcObjUcCUcUnqualifiedUcIdUcOrUcClass @9 :Bool;
  isUcSpecialized @10 :Bool;
  isUcSpecializedUcAsUcWritten @11 :Bool;
  isUcSugared @12 :Bool;
  isUcUnspecialized @13 :Bool;
  isUcUnspecializedUcAsUcWritten @14 :Bool;
}

struct ObjCInterfaceType @0xeaf73283b88684f2 {
  objUcCUcObjectUcType @0:ObjCObjectType;
}

struct ObjCObjectPointerType @0x83fd17147f556ba9 {
  type @0:Type;
  isUcKindUcOfUcType @1 :Bool;
  isUcObjUcCUcIdUcOrUcClassUcType @2 :Bool;
  isUcSpecialized @3 :Bool;
  isUcSpecializedUcAsUcWritten @4 :Bool;
  isUcSugared @5 :Bool;
  isUcUnspecialized @6 :Bool;
  isUcUnspecializedUcAsUcWritten @7 :Bool;
}

struct MemberPointerType @0xcd7316ac3d809b66 {
  type @0:Type;
  isUcMemberUcDataUcPointer @1 :Bool;
  isUcMemberUcFunctionUcPointer @2 :Bool;
  isUcSugared @3 :Bool;
}

struct MatrixType @0xfce6c7a94952d4ac {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct DependentSizedMatrixType @0xa068a0de73cc64b1 {
  matrixUcType @0:MatrixType;
  attributeUcToken @1 :Token;
}

struct ConstantMatrixType @0x9fe8639dcd3a4d9e {
  matrixUcType @0:MatrixType;
}

struct MacroQualifiedType @0x8494e2a4b85c9f19 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct InjectedClassNameType @0xa6c2e5edfcbf618a {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct FunctionType @0x948975919b3cdebd {
  type @0:Type;
  callUcConv @1 :CallingConv;
  cmseUcNsUcCallUcAttribute @2 :Bool;
  hasUcRegUcParm @3 :Bool;
  noUcReturnUcAttribute @4 :Bool;
  isUcConst @5 :Bool;
  isUcRestrict @6 :Bool;
  isUcVolatile @7 :Bool;
}

struct FunctionProtoType @0xfbd27cbfbac5efbb {
  functionUcType @0:FunctionType;
  canUcThrow @1 :CanThrowResult;
  ellipsisUcToken @2 :Token;
  exceptionUcSpecUcType @3 :ExceptionSpecificationType;
  referenceUcQualifier @4 :RefQualifierKind;
  hasUcDependentUcExceptionUcSpec @5 :Bool;
  hasUcDynamicUcExceptionUcSpec @6 :Bool;
  hasUcExceptionUcSpec @7 :Bool;
  hasUcExtUcParameterUcInfos @8 :Bool;
  hasUcInstantiationUcDependentUcExceptionUcSpec @9 :Bool;
  hasUcNoexceptUcExceptionUcSpec @10 :Bool;
  hasUcTrailingUcReturn @11 :Bool;
  isUcNothrow @12 :Bool;
  isUcSugared @13 :Bool;
  isUcTemplateUcVariadic @14 :Bool;
  isUcVariadic @15 :Bool;
}

struct FunctionNoProtoType @0x8290ca5570d70e02 {
  functionUcType @0:FunctionType;
  isUcSugared @1 :Bool;
}

struct ExtIntType @0xc48fbfce9c3676d5 {
  type @0:Type;
  isUcSigned @1 :Bool;
  isUcSugared @2 :Bool;
  isUcUnsigned @3 :Bool;
}

struct DependentVectorType @0xc6ccf5cfae8940a4 {
  type @0:Type;
  attributeUcToken @1 :Token;
  vectorUcKind @2 :VectorTypeVectorKind;
  isUcSugared @3 :Bool;
}

struct DependentSizedExtVectorType @0xd1e2872240f527b7 {
  type @0:Type;
  attributeUcToken @1 :Token;
  isUcSugared @2 :Bool;
}

struct DependentExtIntType @0xedfca4126b0a36ef {
  type @0:Type;
  isUcSigned @1 :Bool;
  isUcSugared @2 :Bool;
  isUcUnsigned @3 :Bool;
}

struct DependentAddressSpaceType @0xadb13a8d42ac14c8 {
  type @0:Type;
  attributeUcToken @1 :Token;
  isUcSugared @2 :Bool;
}

struct DeducedType @0x9b62aead3bf58839 {
  type @0:Type;
  isUcDeduced @1 :Bool;
  isUcSugared @2 :Bool;
}

struct DeducedTemplateSpecializationType @0x9a096862188ecc6e {
  deducedUcType @0:DeducedType;
}

struct AutoType @0x84e063e662c52b4b {
  deducedUcType @0:DeducedType;
  keyword @1 :AutoTypeKeyword;
  isUcConstrained @2 :Bool;
  isUcDecltypeUcAuto @3 :Bool;
}

struct DecltypeType @0x8167d2682b1df777 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ComplexType @0xedb0c5447bfbabbd {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct BuiltinType @0xb9df1f7a0b9bd785 {
  type @0:Type;
  isUcFloatingUcPoint @1 :Bool;
  isUcInteger @2 :Bool;
  isUcSignedUcInteger @3 :Bool;
  isUcSugared @4 :Bool;
  isUcUnsignedUcInteger @5 :Bool;
}

struct BlockPointerType @0xcf1a6a054f3aaac3 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct AttributedType @0xfae2a754903efb8f {
  type @0:Type;
  attributeUcKind @1 :AttributeKind;
  isUcCallingUcConv @2 :Bool;
  isUcMsUcTypeUcSpec @3 :Bool;
  isUcQualifier @4 :Bool;
  isUcSugared @5 :Bool;
}

struct AtomicType @0x856d35fbcc3358de {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct ArrayType @0xf51c56dc11dd4d5a {
  type @0:Type;
  sizeUcModifier @1 :ArrayTypeArraySizeModifier;
}

struct VariableArrayType @0x82d4d76c013109f5 {
  arrayUcType @0:ArrayType;
  bracketsUcRange @1 :TokenRange;
  lUcBracketUcToken @2 :Token;
  rUcBracketUcToken @3 :Token;
  isUcSugared @4 :Bool;
}

struct IncompleteArrayType @0xd4f7a93527ce975e {
  arrayUcType @0:ArrayType;
  isUcSugared @1 :Bool;
}

struct DependentSizedArrayType @0xeb3238fd4299c322 {
  arrayUcType @0:ArrayType;
  bracketsUcRange @1 :TokenRange;
  lUcBracketUcToken @2 :Token;
  rUcBracketUcToken @3 :Token;
  isUcSugared @4 :Bool;
}

struct ConstantArrayType @0xa122a9fa825e1120 {
  arrayUcType @0:ArrayType;
  isUcSugared @1 :Bool;
}

struct AdjustedType @0x85459004973a94cc {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct DecayedType @0x9500bc81a552e7af {
  adjustedUcType @0:AdjustedType;
}

struct VectorType @0xeb831d4f2ea047d6 {
  type @0:Type;
  vectorUcKind @1 :VectorTypeVectorKind;
  isUcSugared @2 :Bool;
}

struct ExtVectorType @0x9822bb6b9f91b427 {
  vectorUcType @0:VectorType;
}

struct UnresolvedUsingType @0xb008cd48c50f310f {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct UnaryTransformType @0xf3f137ad71547e38 {
  type @0:Type;
  uttUcKind @1 :UnaryTransformTypeUTTKind;
  isUcSugared @2 :Bool;
}

struct TypedefType @0x9983fc1d3106ae9c {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct TypeOfType @0xc82d0038e5e0ea52 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct TypeOfExprType @0x9be487fb240a6fe1 {
  type @0:Type;
  isUcSugared @1 :Bool;
}

struct EntityList @0xf26db0d046aab9c9 {
  classUcScopeUcFunctionUcSpecializationUcDecl @0 :List(ClassScopeFunctionSpecializationDecl);
  capturedUcDecl @1 :List(CapturedDecl);
  blockUcDecl @2 :List(BlockDecl);
  accessUcSpecUcDecl @3 :List(AccessSpecDecl);
  translationUcUnitUcDecl @4 :List(TranslationUnitDecl);
  staticUcAssertUcDecl @5 :List(StaticAssertDecl);
  requiresUcExprUcBodyUcDecl @6 :List(RequiresExprBodyDecl);
  pragmaUcDetectUcMismatchUcDecl @7 :List(PragmaDetectMismatchDecl);
  pragmaUcCommentUcDecl @8 :List(PragmaCommentDecl);
  objUcCUcPropertyUcImplUcDecl @9 :List(ObjCPropertyImplDecl);
  namedUcDecl @10 :List(NamedDecl);
  labelUcDecl @11 :List(LabelDecl);
  baseUcUsingUcDecl @12 :List(BaseUsingDecl);
  usingUcEnumUcDecl @13 :List(UsingEnumDecl);
  usingUcDecl @14 :List(UsingDecl);
  valueUcDecl @15 :List(ValueDecl);
  unresolvedUcUsingUcValueUcDecl @16 :List(UnresolvedUsingValueDecl);
  templateUcParamUcObjectUcDecl @17 :List(TemplateParamObjectDecl);
  ompUcDeclareUcReductionUcDecl @18 :List(OMPDeclareReductionDecl);
  msUcGuidUcDecl @19 :List(MSGuidDecl);
  indirectUcFieldUcDecl @20 :List(IndirectFieldDecl);
  enumUcConstantUcDecl @21 :List(EnumConstantDecl);
  declaratorUcDecl @22 :List(DeclaratorDecl);
  varUcDecl @23 :List(VarDecl);
  parmUcVarUcDecl @24 :List(ParmVarDecl);
  ompUcCapturedUcExprUcDecl @25 :List(OMPCapturedExprDecl);
  implicitUcParamUcDecl @26 :List(ImplicitParamDecl);
  decompositionUcDecl @27 :List(DecompositionDecl);
  varUcTemplateUcSpecializationUcDecl @28 :List(VarTemplateSpecializationDecl);
  varUcTemplateUcPartialUcSpecializationUcDecl @29 :List(VarTemplatePartialSpecializationDecl);
  nonUcTypeUcTemplateUcParmUcDecl @30 :List(NonTypeTemplateParmDecl);
  msUcPropertyUcDecl @31 :List(MSPropertyDecl);
  functionUcDecl @32 :List(FunctionDecl);
  cxxUcMethodUcDecl @33 :List(CXXMethodDecl);
  cxxUcDestructorUcDecl @34 :List(CXXDestructorDecl);
  cxxUcConversionUcDecl @35 :List(CXXConversionDecl);
  cxxUcConstructorUcDecl @36 :List(CXXConstructorDecl);
  cxxUcDeductionUcGuideUcDecl @37 :List(CXXDeductionGuideDecl);
  fieldUcDecl @38 :List(FieldDecl);
  objUcCUcIvarUcDecl @39 :List(ObjCIvarDecl);
  objUcCUcAtUcDefsUcFieldUcDecl @40 :List(ObjCAtDefsFieldDecl);
  bindingUcDecl @41 :List(BindingDecl);
  usingUcShadowUcDecl @42 :List(UsingShadowDecl);
  constructorUcUsingUcShadowUcDecl @43 :List(ConstructorUsingShadowDecl);
  usingUcPackUcDecl @44 :List(UsingPackDecl);
  usingUcDirectiveUcDecl @45 :List(UsingDirectiveDecl);
  unresolvedUcUsingUcIfUcExistsUcDecl @46 :List(UnresolvedUsingIfExistsDecl);
  typeUcDecl @47 :List(TypeDecl);
  templateUcTypeUcParmUcDecl @48 :List(TemplateTypeParmDecl);
  tagUcDecl @49 :List(TagDecl);
  recordUcDecl @50 :List(RecordDecl);
  cxxUcRecordUcDecl @51 :List(CXXRecordDecl);
  classUcTemplateUcSpecializationUcDecl @52 :List(ClassTemplateSpecializationDecl);
  classUcTemplateUcPartialUcSpecializationUcDecl @53 :List(ClassTemplatePartialSpecializationDecl);
  enumUcDecl @54 :List(EnumDecl);
  unresolvedUcUsingUcTypenameUcDecl @55 :List(UnresolvedUsingTypenameDecl);
  typedefUcNameUcDecl @56 :List(TypedefNameDecl);
  typedefUcDecl @57 :List(TypedefDecl);
  typeUcAliasUcDecl @58 :List(TypeAliasDecl);
  objUcCUcTypeUcParamUcDecl @59 :List(ObjCTypeParamDecl);
  templateUcDecl @60 :List(TemplateDecl);
  redeclarableUcTemplateUcDecl @61 :List(RedeclarableTemplateDecl);
  functionUcTemplateUcDecl @62 :List(FunctionTemplateDecl);
  classUcTemplateUcDecl @63 :List(ClassTemplateDecl);
  varUcTemplateUcDecl @64 :List(VarTemplateDecl);
  typeUcAliasUcTemplateUcDecl @65 :List(TypeAliasTemplateDecl);
  conceptUcDecl @66 :List(ConceptDecl);
  builtinUcTemplateUcDecl @67 :List(BuiltinTemplateDecl);
  templateUcTemplateUcParmUcDecl @68 :List(TemplateTemplateParmDecl);
  objUcCUcPropertyUcDecl @69 :List(ObjCPropertyDecl);
  objUcCUcMethodUcDecl @70 :List(ObjCMethodDecl);
  objUcCUcContainerUcDecl @71 :List(ObjCContainerDecl);
  objUcCUcCategoryUcDecl @72 :List(ObjCCategoryDecl);
  objUcCUcProtocolUcDecl @73 :List(ObjCProtocolDecl);
  objUcCUcInterfaceUcDecl @74 :List(ObjCInterfaceDecl);
  objUcCUcImplUcDecl @75 :List(ObjCImplDecl);
  objUcCUcCategoryUcImplUcDecl @76 :List(ObjCCategoryImplDecl);
  objUcCUcImplementationUcDecl @77 :List(ObjCImplementationDecl);
  objUcCUcCompatibleUcAliasUcDecl @78 :List(ObjCCompatibleAliasDecl);
  namespaceUcDecl @79 :List(NamespaceDecl);
  namespaceUcAliasUcDecl @80 :List(NamespaceAliasDecl);
  linkageUcSpecUcDecl @81 :List(LinkageSpecDecl);
  lifetimeUcExtendedUcTemporaryUcDecl @82 :List(LifetimeExtendedTemporaryDecl);
  importUcDecl @83 :List(ImportDecl);
  friendUcTemplateUcDecl @84 :List(FriendTemplateDecl);
  friendUcDecl @85 :List(FriendDecl);
  fileUcScopeUcAsmUcDecl @86 :List(FileScopeAsmDecl);
  externUcCUcContextUcDecl @87 :List(ExternCContextDecl);
  exportUcDecl @88 :List(ExportDecl);
  emptyUcDecl @89 :List(EmptyDecl);
  sehUcTryUcStmt @90 :List(SEHTryStmt);
  sehUcLeaveUcStmt @91 :List(SEHLeaveStmt);
  sehUcFinallyUcStmt @92 :List(SEHFinallyStmt);
  sehUcExceptUcStmt @93 :List(SEHExceptStmt);
  returnUcStmt @94 :List(ReturnStmt);
  objUcCUcForUcCollectionUcStmt @95 :List(ObjCForCollectionStmt);
  objUcCUcAutoreleaseUcPoolUcStmt @96 :List(ObjCAutoreleasePoolStmt);
  objUcCUcAtUcTryUcStmt @97 :List(ObjCAtTryStmt);
  objUcCUcAtUcThrowUcStmt @98 :List(ObjCAtThrowStmt);
  objUcCUcAtUcSynchronizedUcStmt @99 :List(ObjCAtSynchronizedStmt);
  objUcCUcAtUcFinallyUcStmt @100 :List(ObjCAtFinallyStmt);
  objUcCUcAtUcCatchUcStmt @101 :List(ObjCAtCatchStmt);
  ompUcDispatchUcDirective @102 :List(OMPDispatchDirective);
  ompUcDepobjUcDirective @103 :List(OMPDepobjDirective);
  ompUcCriticalUcDirective @104 :List(OMPCriticalDirective);
  ompUcCancellationUcPointUcDirective @105 :List(OMPCancellationPointDirective);
  ompUcCancelUcDirective @106 :List(OMPCancelDirective);
  ompUcBarrierUcDirective @107 :List(OMPBarrierDirective);
  ompUcAtomicUcDirective @108 :List(OMPAtomicDirective);
  ompUcTeamsUcDirective @109 :List(OMPTeamsDirective);
  ompUcTaskyieldUcDirective @110 :List(OMPTaskyieldDirective);
  ompUcTaskwaitUcDirective @111 :List(OMPTaskwaitDirective);
  ompUcTaskgroupUcDirective @112 :List(OMPTaskgroupDirective);
  ompUcTaskUcDirective @113 :List(OMPTaskDirective);
  ompUcTargetUcUpdateUcDirective @114 :List(OMPTargetUpdateDirective);
  ompUcTargetUcTeamsUcDirective @115 :List(OMPTargetTeamsDirective);
  ompUcTargetUcParallelUcDirective @116 :List(OMPTargetParallelDirective);
  ompUcTargetUcExitUcDataUcDirective @117 :List(OMPTargetExitDataDirective);
  ompUcTargetUcEnterUcDataUcDirective @118 :List(OMPTargetEnterDataDirective);
  ompUcTargetUcDirective @119 :List(OMPTargetDirective);
  ompUcTargetUcDataUcDirective @120 :List(OMPTargetDataDirective);
  ompUcSingleUcDirective @121 :List(OMPSingleDirective);
  ompUcSectionsUcDirective @122 :List(OMPSectionsDirective);
  ompUcSectionUcDirective @123 :List(OMPSectionDirective);
  ompUcScanUcDirective @124 :List(OMPScanDirective);
  ompUcParallelUcSectionsUcDirective @125 :List(OMPParallelSectionsDirective);
  ompUcParallelUcMasterUcDirective @126 :List(OMPParallelMasterDirective);
  ompUcParallelUcDirective @127 :List(OMPParallelDirective);
  ompUcOrderedUcDirective @128 :List(OMPOrderedDirective);
  ompUcMasterUcDirective @129 :List(OMPMasterDirective);
  ompUcMaskedUcDirective @130 :List(OMPMaskedDirective);
  ompUcUnrollUcDirective @131 :List(OMPUnrollDirective);
  ompUcTileUcDirective @132 :List(OMPTileDirective);
  ompUcForUcSimdUcDirective @133 :List(OMPForSimdDirective);
  ompUcForUcDirective @134 :List(OMPForDirective);
  ompUcDistributeUcSimdUcDirective @135 :List(OMPDistributeSimdDirective);
  ompUcDistributeUcParallelUcForUcSimdUcDirective @136 :List(OMPDistributeParallelForSimdDirective);
  ompUcDistributeUcParallelUcForUcDirective @137 :List(OMPDistributeParallelForDirective);
  ompUcDistributeUcDirective @138 :List(OMPDistributeDirective);
  ompUcTeamsUcDistributeUcSimdUcDirective @139 :List(OMPTeamsDistributeSimdDirective);
  ompUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @140 :List(OMPTeamsDistributeParallelForSimdDirective);
  ompUcTeamsUcDistributeUcParallelUcForUcDirective @141 :List(OMPTeamsDistributeParallelForDirective);
  ompUcTeamsUcDistributeUcDirective @142 :List(OMPTeamsDistributeDirective);
  ompUcTaskUcLoopUcSimdUcDirective @143 :List(OMPTaskLoopSimdDirective);
  ompUcTaskUcLoopUcDirective @144 :List(OMPTaskLoopDirective);
  ompUcTargetUcTeamsUcDistributeUcSimdUcDirective @145 :List(OMPTargetTeamsDistributeSimdDirective);
  ompUcTargetUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @146 :List(OMPTargetTeamsDistributeParallelForSimdDirective);
  ompUcTargetUcTeamsUcDistributeUcParallelUcForUcDirective @147 :List(OMPTargetTeamsDistributeParallelForDirective);
  ompUcTargetUcTeamsUcDistributeUcDirective @148 :List(OMPTargetTeamsDistributeDirective);
  ompUcTargetUcSimdUcDirective @149 :List(OMPTargetSimdDirective);
  ompUcTargetUcParallelUcForUcSimdUcDirective @150 :List(OMPTargetParallelForSimdDirective);
  ompUcTargetUcParallelUcForUcDirective @151 :List(OMPTargetParallelForDirective);
  ompUcSimdUcDirective @152 :List(OMPSimdDirective);
  ompUcParallelUcMasterUcTaskUcLoopUcSimdUcDirective @153 :List(OMPParallelMasterTaskLoopSimdDirective);
  ompUcParallelUcMasterUcTaskUcLoopUcDirective @154 :List(OMPParallelMasterTaskLoopDirective);
  ompUcParallelUcForUcSimdUcDirective @155 :List(OMPParallelForSimdDirective);
  ompUcParallelUcForUcDirective @156 :List(OMPParallelForDirective);
  ompUcMasterUcTaskUcLoopUcSimdUcDirective @157 :List(OMPMasterTaskLoopSimdDirective);
  ompUcMasterUcTaskUcLoopUcDirective @158 :List(OMPMasterTaskLoopDirective);
  ompUcInteropUcDirective @159 :List(OMPInteropDirective);
  ompUcFlushUcDirective @160 :List(OMPFlushDirective);
  ompUcCanonicalUcLoop @161 :List(OMPCanonicalLoop);
  nullUcStmt @162 :List(NullStmt);
  msUcDependentUcExistsUcStmt @163 :List(MSDependentExistsStmt);
  indirectUcGotoUcStmt @164 :List(IndirectGotoStmt);
  ifUcStmt @165 :List(IfStmt);
  gotoUcStmt @166 :List(GotoStmt);
  forUcStmt @167 :List(ForStmt);
  doUcStmt @168 :List(DoStmt);
  declUcStmt @169 :List(DeclStmt);
  coroutineUcBodyUcStmt @170 :List(CoroutineBodyStmt);
  coreturnUcStmt @171 :List(CoreturnStmt);
  continueUcStmt @172 :List(ContinueStmt);
  compoundUcStmt @173 :List(CompoundStmt);
  capturedUcStmt @174 :List(CapturedStmt);
  cxxUcTryUcStmt @175 :List(CXXTryStmt);
  cxxUcForUcRangeUcStmt @176 :List(CXXForRangeStmt);
  cxxUcCatchUcStmt @177 :List(CXXCatchStmt);
  breakUcStmt @178 :List(BreakStmt);
  msUcAsmUcStmt @179 :List(MSAsmStmt);
  gccUcAsmUcStmt @180 :List(GCCAsmStmt);
  whileUcStmt @181 :List(WhileStmt);
  labelUcStmt @182 :List(LabelStmt);
  designatedUcInitUcUpdateUcExpr @183 :List(DesignatedInitUpdateExpr);
  designatedUcInitUcExpr @184 :List(DesignatedInitExpr);
  dependentUcScopeUcDeclUcRefUcExpr @185 :List(DependentScopeDeclRefExpr);
  dependentUcCoawaitUcExpr @186 :List(DependentCoawaitExpr);
  declUcRefUcExpr @187 :List(DeclRefExpr);
  coawaitUcExpr @188 :List(CoawaitExpr);
  coyieldUcExpr @189 :List(CoyieldExpr);
  convertUcVectorUcExpr @190 :List(ConvertVectorExpr);
  conceptUcSpecializationUcExpr @191 :List(ConceptSpecializationExpr);
  compoundUcLiteralUcExpr @192 :List(CompoundLiteralExpr);
  chooseUcExpr @193 :List(ChooseExpr);
  characterUcLiteral @194 :List(CharacterLiteral);
  implicitUcCastUcExpr @195 :List(ImplicitCastExpr);
  cxxUcDynamicUcCastUcExpr @196 :List(CXXDynamicCastExpr);
  cxxUcConstUcCastUcExpr @197 :List(CXXConstCastExpr);
  cxxUcAddrspaceUcCastUcExpr @198 :List(CXXAddrspaceCastExpr);
  cxxUcStaticUcCastUcExpr @199 :List(CXXStaticCastExpr);
  cxxUcReinterpretUcCastUcExpr @200 :List(CXXReinterpretCastExpr);
  cxxUcFunctionalUcCastUcExpr @201 :List(CXXFunctionalCastExpr);
  cUcStyleUcCastUcExpr @202 :List(CStyleCastExpr);
  builtinUcBitUcCastUcExpr @203 :List(BuiltinBitCastExpr);
  objUcCUcBridgedUcCastUcExpr @204 :List(ObjCBridgedCastExpr);
  callUcExpr @205 :List(CallExpr);
  cxxUcOperatorUcCallUcExpr @206 :List(CXXOperatorCallExpr);
  cxxUcMemberUcCallUcExpr @207 :List(CXXMemberCallExpr);
  cudaUcKernelUcCallUcExpr @208 :List(CUDAKernelCallExpr);
  userUcDefinedUcLiteral @209 :List(UserDefinedLiteral);
  cxxUcUuidofUcExpr @210 :List(CXXUuidofExpr);
  cxxUcUnresolvedUcConstructUcExpr @211 :List(CXXUnresolvedConstructExpr);
  cxxUcTypeidUcExpr @212 :List(CXXTypeidExpr);
  cxxUcThrowUcExpr @213 :List(CXXThrowExpr);
  cxxUcThisUcExpr @214 :List(CXXThisExpr);
  cxxUcStdUcInitializerUcListUcExpr @215 :List(CXXStdInitializerListExpr);
  cxxUcScalarUcValueUcInitUcExpr @216 :List(CXXScalarValueInitExpr);
  cxxUcRewrittenUcBinaryUcOperator @217 :List(CXXRewrittenBinaryOperator);
  cxxUcPseudoUcDestructorUcExpr @218 :List(CXXPseudoDestructorExpr);
  cxxUcNullUcPtrUcLiteralUcExpr @219 :List(CXXNullPtrLiteralExpr);
  cxxUcNoexceptUcExpr @220 :List(CXXNoexceptExpr);
  cxxUcNewUcExpr @221 :List(CXXNewExpr);
  cxxUcInheritedUcCtorUcInitUcExpr @222 :List(CXXInheritedCtorInitExpr);
  cxxUcFoldUcExpr @223 :List(CXXFoldExpr);
  cxxUcDependentUcScopeUcMemberUcExpr @224 :List(CXXDependentScopeMemberExpr);
  cxxUcDeleteUcExpr @225 :List(CXXDeleteExpr);
  cxxUcDefaultUcInitUcExpr @226 :List(CXXDefaultInitExpr);
  cxxUcDefaultUcArgUcExpr @227 :List(CXXDefaultArgExpr);
  cxxUcConstructUcExpr @228 :List(CXXConstructExpr);
  cxxUcTemporaryUcObjectUcExpr @229 :List(CXXTemporaryObjectExpr);
  cxxUcBoolUcLiteralUcExpr @230 :List(CXXBoolLiteralExpr);
  cxxUcBindUcTemporaryUcExpr @231 :List(CXXBindTemporaryExpr);
  blockUcExpr @232 :List(BlockExpr);
  binaryUcOperator @233 :List(BinaryOperator);
  compoundUcAssignUcOperator @234 :List(CompoundAssignOperator);
  atomicUcExpr @235 :List(AtomicExpr);
  asUcTypeUcExpr @236 :List(AsTypeExpr);
  arrayUcTypeUcTraitUcExpr @237 :List(ArrayTypeTraitExpr);
  arrayUcSubscriptUcExpr @238 :List(ArraySubscriptExpr);
  arrayUcInitUcLoopUcExpr @239 :List(ArrayInitLoopExpr);
  arrayUcInitUcIndexUcExpr @240 :List(ArrayInitIndexExpr);
  addrUcLabelUcExpr @241 :List(AddrLabelExpr);
  conditionalUcOperator @242 :List(ConditionalOperator);
  binaryUcConditionalUcOperator @243 :List(BinaryConditionalOperator);
  vaUcArgUcExpr @244 :List(VAArgExpr);
  unaryUcOperator @245 :List(UnaryOperator);
  unaryUcExprUcOrUcTypeUcTraitUcExpr @246 :List(UnaryExprOrTypeTraitExpr);
  typoUcExpr @247 :List(TypoExpr);
  typeUcTraitUcExpr @248 :List(TypeTraitExpr);
  substUcNonUcTypeUcTemplateUcParmUcPackUcExpr @249 :List(SubstNonTypeTemplateParmPackExpr);
  substUcNonUcTypeUcTemplateUcParmUcExpr @250 :List(SubstNonTypeTemplateParmExpr);
  stringUcLiteral @251 :List(StringLiteral);
  stmtUcExpr @252 :List(StmtExpr);
  sourceUcLocUcExpr @253 :List(SourceLocExpr);
  sizeUcOfUcPackUcExpr @254 :List(SizeOfPackExpr);
  shuffleUcVectorUcExpr @255 :List(ShuffleVectorExpr);
  syclUcUniqueUcStableUcNameUcExpr @256 :List(SYCLUniqueStableNameExpr);
  requiresUcExpr @257 :List(RequiresExpr);
  recoveryUcExpr @258 :List(RecoveryExpr);
  pseudoUcObjectUcExpr @259 :List(PseudoObjectExpr);
  predefinedUcExpr @260 :List(PredefinedExpr);
  parenUcListUcExpr @261 :List(ParenListExpr);
  parenUcExpr @262 :List(ParenExpr);
  packUcExpansionUcExpr @263 :List(PackExpansionExpr);
  unresolvedUcMemberUcExpr @264 :List(UnresolvedMemberExpr);
  unresolvedUcLookupUcExpr @265 :List(UnresolvedLookupExpr);
  opaqueUcValueUcExpr @266 :List(OpaqueValueExpr);
  offsetUcOfUcExpr @267 :List(OffsetOfExpr);
  objUcCUcSubscriptUcRefUcExpr @268 :List(ObjCSubscriptRefExpr);
  objUcCUcStringUcLiteral @269 :List(ObjCStringLiteral);
  objUcCUcSelectorUcExpr @270 :List(ObjCSelectorExpr);
  objUcCUcProtocolUcExpr @271 :List(ObjCProtocolExpr);
  objUcCUcPropertyUcRefUcExpr @272 :List(ObjCPropertyRefExpr);
  objUcCUcMessageUcExpr @273 :List(ObjCMessageExpr);
  objUcCUcIvarUcRefUcExpr @274 :List(ObjCIvarRefExpr);
  objUcCUcIsaUcExpr @275 :List(ObjCIsaExpr);
  objUcCUcIndirectUcCopyUcRestoreUcExpr @276 :List(ObjCIndirectCopyRestoreExpr);
  objUcCUcEncodeUcExpr @277 :List(ObjCEncodeExpr);
  objUcCUcDictionaryUcLiteral @278 :List(ObjCDictionaryLiteral);
  objUcCUcBoxedUcExpr @279 :List(ObjCBoxedExpr);
  objUcCUcBoolUcLiteralUcExpr @280 :List(ObjCBoolLiteralExpr);
  objUcCUcAvailabilityUcCheckUcExpr @281 :List(ObjCAvailabilityCheckExpr);
  objUcCUcArrayUcLiteral @282 :List(ObjCArrayLiteral);
  ompUcIteratorUcExpr @283 :List(OMPIteratorExpr);
  ompUcArrayUcShapingUcExpr @284 :List(OMPArrayShapingExpr);
  ompUcArrayUcSectionUcExpr @285 :List(OMPArraySectionExpr);
  noUcInitUcExpr @286 :List(NoInitExpr);
  memberUcExpr @287 :List(MemberExpr);
  matrixUcSubscriptUcExpr @288 :List(MatrixSubscriptExpr);
  materializeUcTemporaryUcExpr @289 :List(MaterializeTemporaryExpr);
  msUcPropertyUcSubscriptUcExpr @290 :List(MSPropertySubscriptExpr);
  msUcPropertyUcRefUcExpr @291 :List(MSPropertyRefExpr);
  lambdaUcExpr @292 :List(LambdaExpr);
  integerUcLiteral @293 :List(IntegerLiteral);
  initUcListUcExpr @294 :List(InitListExpr);
  implicitUcValueUcInitUcExpr @295 :List(ImplicitValueInitExpr);
  imaginaryUcLiteral @296 :List(ImaginaryLiteral);
  genericUcSelectionUcExpr @297 :List(GenericSelectionExpr);
  gnuUcNullUcExpr @298 :List(GNUNullExpr);
  functionUcParmUcPackUcExpr @299 :List(FunctionParmPackExpr);
  exprUcWithUcCleanups @300 :List(ExprWithCleanups);
  constantUcExpr @301 :List(ConstantExpr);
  floatingUcLiteral @302 :List(FloatingLiteral);
  fixedUcPointUcLiteral @303 :List(FixedPointLiteral);
  extUcVectorUcElementUcExpr @304 :List(ExtVectorElementExpr);
  expressionUcTraitUcExpr @305 :List(ExpressionTraitExpr);
  attributedUcStmt @306 :List(AttributedStmt);
  switchUcStmt @307 :List(SwitchStmt);
  defaultUcStmt @308 :List(DefaultStmt);
  caseUcStmt @309 :List(CaseStmt);
  templateUcTypeUcParmUcType @310 :List(TemplateTypeParmType);
  templateUcSpecializationUcType @311 :List(TemplateSpecializationType);
  tagUcType @312 :List(TagType);
  recordUcType @313 :List(RecordType);
  enumUcType @314 :List(EnumType);
  substUcTemplateUcTypeUcParmUcType @315 :List(SubstTemplateTypeParmType);
  substUcTemplateUcTypeUcParmUcPackUcType @316 :List(SubstTemplateTypeParmPackType);
  referenceUcType @317 :List(ReferenceType);
  rUcValueUcReferenceUcType @318 :List(RValueReferenceType);
  lUcValueUcReferenceUcType @319 :List(LValueReferenceType);
  pointerUcType @320 :List(PointerType);
  pipeUcType @321 :List(PipeType);
  parenUcType @322 :List(ParenType);
  packUcExpansionUcType @323 :List(PackExpansionType);
  objUcCUcTypeUcParamUcType @324 :List(ObjCTypeParamType);
  objUcCUcObjectUcType @325 :List(ObjCObjectType);
  objUcCUcInterfaceUcType @326 :List(ObjCInterfaceType);
  objUcCUcObjectUcPointerUcType @327 :List(ObjCObjectPointerType);
  memberUcPointerUcType @328 :List(MemberPointerType);
  matrixUcType @329 :List(MatrixType);
  dependentUcSizedUcMatrixUcType @330 :List(DependentSizedMatrixType);
  constantUcMatrixUcType @331 :List(ConstantMatrixType);
  macroUcQualifiedUcType @332 :List(MacroQualifiedType);
  injectedUcClassUcNameUcType @333 :List(InjectedClassNameType);
  functionUcType @334 :List(FunctionType);
  functionUcProtoUcType @335 :List(FunctionProtoType);
  functionUcNoUcProtoUcType @336 :List(FunctionNoProtoType);
  extUcIntUcType @337 :List(ExtIntType);
  dependentUcVectorUcType @338 :List(DependentVectorType);
  dependentUcSizedUcExtUcVectorUcType @339 :List(DependentSizedExtVectorType);
  dependentUcExtUcIntUcType @340 :List(DependentExtIntType);
  dependentUcAddressUcSpaceUcType @341 :List(DependentAddressSpaceType);
  deducedUcType @342 :List(DeducedType);
  deducedUcTemplateUcSpecializationUcType @343 :List(DeducedTemplateSpecializationType);
  autoUcType @344 :List(AutoType);
  decltypeUcType @345 :List(DecltypeType);
  complexUcType @346 :List(ComplexType);
  builtinUcType @347 :List(BuiltinType);
  blockUcPointerUcType @348 :List(BlockPointerType);
  attributedUcType @349 :List(AttributedType);
  atomicUcType @350 :List(AtomicType);
  arrayUcType @351 :List(ArrayType);
  variableUcArrayUcType @352 :List(VariableArrayType);
  incompleteUcArrayUcType @353 :List(IncompleteArrayType);
  dependentUcSizedUcArrayUcType @354 :List(DependentSizedArrayType);
  constantUcArrayUcType @355 :List(ConstantArrayType);
  adjustedUcType @356 :List(AdjustedType);
  decayedUcType @357 :List(DecayedType);
  vectorUcType @358 :List(VectorType);
  extUcVectorUcType @359 :List(ExtVectorType);
  unresolvedUcUsingUcType @360 :List(UnresolvedUsingType);
  unaryUcTransformUcType @361 :List(UnaryTransformType);
  typedefUcType @362 :List(TypedefType);
  typeUcOfUcType @363 :List(TypeOfType);
  typeUcOfUcExprUcType @364 :List(TypeOfExprType);
}
