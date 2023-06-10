// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Type.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/File.h>
#include <multiplier/Entities/Fragment.h>
#include <multiplier/Entities/Index.h>
#include <multiplier/Entities/Reference.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../File.h"
#include "../Fragment.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::shared_ptr<EntityProvider> Type::entity_provider_of(const Index &index_) {
  return index_.impl;
}

std::shared_ptr<EntityProvider> Type::entity_provider_of(const Fragment &frag_) {
  return frag_.impl->ep;
}

std::shared_ptr<EntityProvider> Type::entity_provider_of(const File &file_) {
  return file_.impl->ep;
}

gap::generator<Type> Type::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = Type::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool Type::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : Type::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<Type> Type::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    index.type(eid.Pack());
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

gap::generator<Type> Type::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeImplPtr eptr : ep->TypesFor(ep)) {
    if (std::optional<Type> e = Type::from(Type(std::move(eptr)))) {
      co_yield std::move(e.value());
    }
  }
}

gap::generator<Type> Type::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeImplPtr eptr : ep->TypesFor(ep, frag_id)) {
    if (std::optional<Type> e = Type::from(Type(std::move(eptr)))) {
      co_yield std::move(e.value());
    }
  }
}

gap::generator<Type> Type::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, frag_id)) {
      if (std::optional<Type> e = Type::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<Type> Type::in(const Index &index, std::span<TypeKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      co_yield Type(std::move(eptr));
    }
  }
}

gap::generator<Type> Type::in(const Fragment &frag, std::span<TypeKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      co_yield Type(std::move(eptr));
    }
  }
}

gap::generator<Type> Type::in(const File &file, std::span<TypeKind> kinds) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        co_yield Type(std::move(eptr));
      }
    }
  }
}

std::optional<Type> Type::from(const Reference &r) {
  return r.as_type();
}

std::optional<Type> Type::from(const TokenContext &t) {
  return t.as_type();
}

Type Type::desugared_type(void) const {
  RawEntityId eid = impl->reader.getVal0();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type Type::canonical_type(void) const {
  RawEntityId eid = impl->reader.getVal1();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool Type::is_qualified(void) const {
  return impl->reader.getVal2();
}

Type Type::unqualified_type(void) const {
  RawEntityId eid = impl->reader.getVal3();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool Type::accepts_obj_c_type_parameters(void) const {
  return impl->reader.getVal4();
}

bool Type::can_decay_to_pointer_type(void) const {
  return impl->reader.getVal5();
}

bool Type::can_have_nullability(void) const {
  return impl->reader.getVal6();
}

bool Type::contains_errors(void) const {
  return impl->reader.getVal7();
}

bool Type::contains_unexpanded_parameter_pack(void) const {
  return impl->reader.getVal8();
}

std::optional<Type> Type::array_element_type_no_type_qualified(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

Linkage Type::linkage(void) const {
  return static_cast<Linkage>(impl->reader.getVal10());
}

std::optional<NullabilityKind> Type::nullability(void) const {
  if (!impl->reader.getVal12()) {
    return std::nullopt;
  } else {
    return static_cast<NullabilityKind>(impl->reader.getVal11());
  }
  return std::nullopt;
}

std::optional<CXXRecordDecl> Type::pointee_cxx_record_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal13();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return CXXRecordDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<Type> Type::pointee_or_array_element_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal14();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<Type> Type::pointee_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal15();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<TypeScalarTypeKind> Type::scalar_type_kind(void) const {
  if (!impl->reader.getVal17()) {
    return std::nullopt;
  } else {
    return static_cast<TypeScalarTypeKind>(impl->reader.getVal16());
  }
  return std::nullopt;
}

std::optional<Type> Type::sve_element_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal18();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

TypeKind Type::kind(void) const {
  return static_cast<TypeKind>(impl->reader.getVal19());
}

Type Type::unqualified_desugared_type(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Visibility Type::visibility(void) const {
  return static_cast<Visibility>(impl->reader.getVal21());
}

bool Type::has_auto_for_trailing_return_type(void) const {
  return impl->reader.getVal22();
}

bool Type::has_floating_representation(void) const {
  return impl->reader.getVal23();
}

bool Type::has_integer_representation(void) const {
  return impl->reader.getVal24();
}

bool Type::has_obj_c_pointer_representation(void) const {
  return impl->reader.getVal25();
}

bool Type::has_pointer_representation(void) const {
  return impl->reader.getVal26();
}

bool Type::has_signed_integer_representation(void) const {
  return impl->reader.getVal27();
}

bool Type::has_sized_vla_type(void) const {
  return impl->reader.getVal28();
}

bool Type::has_unnamed_or_local_type(void) const {
  return impl->reader.getVal29();
}

bool Type::has_unsigned_integer_representation(void) const {
  return impl->reader.getVal30();
}

std::optional<bool> Type::is_aggregate_type(void) const {
  if (!impl->reader.getVal32()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal31());
  }
  return std::nullopt;
}

bool Type::is_align_value_t(void) const {
  return impl->reader.getVal33();
}

bool Type::is_any_character_type(void) const {
  return impl->reader.getVal34();
}

bool Type::is_any_complex_type(void) const {
  return impl->reader.getVal35();
}

bool Type::is_any_pointer_type(void) const {
  return impl->reader.getVal36();
}

bool Type::is_arithmetic_type(void) const {
  return impl->reader.getVal37();
}

bool Type::is_array_type(void) const {
  return impl->reader.getVal38();
}

bool Type::is_atomic_type(void) const {
  return impl->reader.getVal39();
}

bool Type::is_b_float16_type(void) const {
  return impl->reader.getVal40();
}

bool Type::is_bit_int_type(void) const {
  return impl->reader.getVal41();
}

bool Type::is_block_compatible_obj_c_pointer_type(void) const {
  return impl->reader.getVal42();
}

bool Type::is_block_pointer_type(void) const {
  return impl->reader.getVal43();
}

bool Type::is_boolean_type(void) const {
  return impl->reader.getVal44();
}

bool Type::is_builtin_type(void) const {
  return impl->reader.getVal45();
}

bool Type::is_carc_bridgable_type(void) const {
  return impl->reader.getVal46();
}

bool Type::is_cuda_device_builtin_surface_type(void) const {
  return impl->reader.getVal47();
}

bool Type::is_cuda_device_builtin_texture_type(void) const {
  return impl->reader.getVal48();
}

bool Type::is_canonical_unqualified(void) const {
  return impl->reader.getVal49();
}

bool Type::is_char16_type(void) const {
  return impl->reader.getVal50();
}

bool Type::is_char32_type(void) const {
  return impl->reader.getVal51();
}

bool Type::is_char8_type(void) const {
  return impl->reader.getVal52();
}

bool Type::is_character_type(void) const {
  return impl->reader.getVal53();
}

bool Type::is_class_type(void) const {
  return impl->reader.getVal54();
}

bool Type::is_clk_event_t(void) const {
  return impl->reader.getVal55();
}

bool Type::is_complex_integer_type(void) const {
  return impl->reader.getVal56();
}

bool Type::is_complex_type(void) const {
  return impl->reader.getVal57();
}

bool Type::is_compound_type(void) const {
  return impl->reader.getVal58();
}

bool Type::is_constant_array_type(void) const {
  return impl->reader.getVal59();
}

bool Type::is_constant_matrix_type(void) const {
  return impl->reader.getVal60();
}

std::optional<bool> Type::is_constant_size_type(void) const {
  if (!impl->reader.getVal62()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal61());
  }
  return std::nullopt;
}

bool Type::is_decltype_type(void) const {
  return impl->reader.getVal63();
}

bool Type::is_dependent_address_space_type(void) const {
  return impl->reader.getVal64();
}

bool Type::is_dependent_sized_array_type(void) const {
  return impl->reader.getVal65();
}

bool Type::is_dependent_type(void) const {
  return impl->reader.getVal66();
}

bool Type::is_elaborated_type_specifier(void) const {
  return impl->reader.getVal67();
}

bool Type::is_enumeral_type(void) const {
  return impl->reader.getVal68();
}

bool Type::is_event_t(void) const {
  return impl->reader.getVal69();
}

bool Type::is_ext_vector_boolean_type(void) const {
  return impl->reader.getVal70();
}

bool Type::is_ext_vector_type(void) const {
  return impl->reader.getVal71();
}

bool Type::is_fixed_point_or_integer_type(void) const {
  return impl->reader.getVal72();
}

bool Type::is_fixed_point_type(void) const {
  return impl->reader.getVal73();
}

bool Type::is_float128_type(void) const {
  return impl->reader.getVal74();
}

bool Type::is_float16_type(void) const {
  return impl->reader.getVal75();
}

bool Type::is_floating_type(void) const {
  return impl->reader.getVal76();
}

bool Type::is_from_ast(void) const {
  return impl->reader.getVal77();
}

bool Type::is_function_no_proto_type(void) const {
  return impl->reader.getVal78();
}

bool Type::is_function_pointer_type(void) const {
  return impl->reader.getVal79();
}

bool Type::is_function_proto_type(void) const {
  return impl->reader.getVal80();
}

bool Type::is_function_reference_type(void) const {
  return impl->reader.getVal81();
}

bool Type::is_function_type(void) const {
  return impl->reader.getVal82();
}

bool Type::is_fundamental_type(void) const {
  return impl->reader.getVal83();
}

bool Type::is_half_type(void) const {
  return impl->reader.getVal84();
}

bool Type::is_ibm128_type(void) const {
  return impl->reader.getVal85();
}

bool Type::is_image_type(void) const {
  return impl->reader.getVal86();
}

bool Type::is_incomplete_array_type(void) const {
  return impl->reader.getVal87();
}

bool Type::is_incomplete_or_object_type(void) const {
  return impl->reader.getVal88();
}

bool Type::is_incomplete_type(void) const {
  return impl->reader.getVal89();
}

bool Type::is_instantiation_dependent_type(void) const {
  return impl->reader.getVal90();
}

bool Type::is_integer_type(void) const {
  return impl->reader.getVal91();
}

bool Type::is_integral_or_enumeration_type(void) const {
  return impl->reader.getVal92();
}

bool Type::is_integral_or_unscoped_enumeration_type(void) const {
  return impl->reader.getVal93();
}

bool Type::is_integral_type(void) const {
  return impl->reader.getVal94();
}

bool Type::is_interface_type(void) const {
  return impl->reader.getVal95();
}

bool Type::is_l_value_reference_type(void) const {
  return impl->reader.getVal96();
}

bool Type::is_linkage_valid(void) const {
  return impl->reader.getVal97();
}

std::optional<bool> Type::is_literal_type(void) const {
  if (!impl->reader.getVal99()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal98());
  }
  return std::nullopt;
}

bool Type::is_matrix_type(void) const {
  return impl->reader.getVal100();
}

bool Type::is_member_data_pointer_type(void) const {
  return impl->reader.getVal101();
}

bool Type::is_member_function_pointer_type(void) const {
  return impl->reader.getVal102();
}

bool Type::is_member_pointer_type(void) const {
  return impl->reader.getVal103();
}

bool Type::is_non_overload_placeholder_type(void) const {
  return impl->reader.getVal104();
}

bool Type::is_nothrow_t(void) const {
  return impl->reader.getVal105();
}

bool Type::is_null_pointer_type(void) const {
  return impl->reader.getVal106();
}

bool Type::is_ocl_ext_opaque_type(void) const {
  return impl->reader.getVal107();
}

bool Type::is_ocl_image_1d_array_ro_type(void) const {
  return impl->reader.getVal108();
}

bool Type::is_ocl_image_1d_array_rw_type(void) const {
  return impl->reader.getVal109();
}

bool Type::is_ocl_image_1d_array_wo_type(void) const {
  return impl->reader.getVal110();
}

bool Type::is_ocl_image_1d_buffer_ro_type(void) const {
  return impl->reader.getVal111();
}

bool Type::is_ocl_image_1d_buffer_rw_type(void) const {
  return impl->reader.getVal112();
}

bool Type::is_ocl_image_1d_buffer_wo_type(void) const {
  return impl->reader.getVal113();
}

bool Type::is_ocl_image_1d_ro_type(void) const {
  return impl->reader.getVal114();
}

bool Type::is_ocl_image_1d_rw_type(void) const {
  return impl->reader.getVal115();
}

bool Type::is_ocl_image_1d_wo_type(void) const {
  return impl->reader.getVal116();
}

bool Type::is_ocl_image_2d_array_depth_ro_type(void) const {
  return impl->reader.getVal117();
}

bool Type::is_ocl_image_2d_array_depth_rw_type(void) const {
  return impl->reader.getVal118();
}

bool Type::is_ocl_image_2d_array_depth_wo_type(void) const {
  return impl->reader.getVal119();
}

bool Type::is_ocl_image_2d_array_msaa_depth_ro_type(void) const {
  return impl->reader.getVal120();
}

bool Type::is_ocl_image_2d_array_msaa_depth_rw_type(void) const {
  return impl->reader.getVal121();
}

bool Type::is_ocl_image_2d_array_msaa_depth_wo_type(void) const {
  return impl->reader.getVal122();
}

bool Type::is_ocl_image_2d_array_msaaro_type(void) const {
  return impl->reader.getVal123();
}

bool Type::is_ocl_image_2d_array_msaarw_type(void) const {
  return impl->reader.getVal124();
}

bool Type::is_ocl_image_2d_array_msaawo_type(void) const {
  return impl->reader.getVal125();
}

bool Type::is_ocl_image_2d_array_ro_type(void) const {
  return impl->reader.getVal126();
}

bool Type::is_ocl_image_2d_array_rw_type(void) const {
  return impl->reader.getVal127();
}

bool Type::is_ocl_image_2d_array_wo_type(void) const {
  return impl->reader.getVal128();
}

bool Type::is_ocl_image_2d_depth_ro_type(void) const {
  return impl->reader.getVal129();
}

bool Type::is_ocl_image_2d_depth_rw_type(void) const {
  return impl->reader.getVal130();
}

bool Type::is_ocl_image_2d_depth_wo_type(void) const {
  return impl->reader.getVal131();
}

bool Type::is_ocl_image_2d_msaa_depth_ro_type(void) const {
  return impl->reader.getVal132();
}

bool Type::is_ocl_image_2d_msaa_depth_rw_type(void) const {
  return impl->reader.getVal133();
}

bool Type::is_ocl_image_2d_msaa_depth_wo_type(void) const {
  return impl->reader.getVal134();
}

bool Type::is_ocl_image_2d_msaaro_type(void) const {
  return impl->reader.getVal135();
}

bool Type::is_ocl_image_2d_msaarw_type(void) const {
  return impl->reader.getVal136();
}

bool Type::is_ocl_image_2d_msaawo_type(void) const {
  return impl->reader.getVal137();
}

bool Type::is_ocl_image_2d_ro_type(void) const {
  return impl->reader.getVal138();
}

bool Type::is_ocl_image_2d_rw_type(void) const {
  return impl->reader.getVal139();
}

bool Type::is_ocl_image_2d_wo_type(void) const {
  return impl->reader.getVal140();
}

bool Type::is_ocl_image_3d_ro_type(void) const {
  return impl->reader.getVal141();
}

bool Type::is_ocl_image_3d_rw_type(void) const {
  return impl->reader.getVal142();
}

bool Type::is_ocl_image_3d_wo_type(void) const {
  return impl->reader.getVal143();
}

bool Type::is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type(void) const {
  return impl->reader.getVal144();
}

bool Type::is_ocl_intel_subgroup_avc_ime_payload_type(void) const {
  return impl->reader.getVal145();
}

bool Type::is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type(void) const {
  return impl->reader.getVal146();
}

bool Type::is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type(void) const {
  return impl->reader.getVal147();
}

bool Type::is_ocl_intel_subgroup_avc_ime_result_type(void) const {
  return impl->reader.getVal148();
}

bool Type::is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type(void) const {
  return impl->reader.getVal149();
}

bool Type::is_ocl_intel_subgroup_avc_mce_payload_type(void) const {
  return impl->reader.getVal150();
}

bool Type::is_ocl_intel_subgroup_avc_mce_result_type(void) const {
  return impl->reader.getVal151();
}

bool Type::is_ocl_intel_subgroup_avc_ref_payload_type(void) const {
  return impl->reader.getVal152();
}

bool Type::is_ocl_intel_subgroup_avc_ref_result_type(void) const {
  return impl->reader.getVal153();
}

bool Type::is_ocl_intel_subgroup_avc_sic_payload_type(void) const {
  return impl->reader.getVal154();
}

bool Type::is_ocl_intel_subgroup_avc_sic_result_type(void) const {
  return impl->reader.getVal155();
}

bool Type::is_ocl_intel_subgroup_avc_type(void) const {
  return impl->reader.getVal156();
}

bool Type::is_obj_carc_bridgable_type(void) const {
  return impl->reader.getVal157();
}

std::optional<bool> Type::is_obj_carc_implicitly_unretained_type(void) const {
  if (!impl->reader.getVal159()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal158());
  }
  return std::nullopt;
}

bool Type::is_obj_c_boxable_record_type(void) const {
  return impl->reader.getVal160();
}

bool Type::is_obj_c_builtin_type(void) const {
  return impl->reader.getVal161();
}

bool Type::is_obj_c_class_or_class_kind_of_type(void) const {
  return impl->reader.getVal162();
}

bool Type::is_obj_c_class_type(void) const {
  return impl->reader.getVal163();
}

bool Type::is_obj_c_id_type(void) const {
  return impl->reader.getVal164();
}

bool Type::is_obj_c_independent_class_type(void) const {
  return impl->reader.getVal165();
}

bool Type::is_obj_c_indirect_lifetime_type(void) const {
  return impl->reader.getVal166();
}

bool Type::is_obj_c_inert_unsafe_unretained_type(void) const {
  return impl->reader.getVal167();
}

bool Type::is_obj_c_lifetime_type(void) const {
  return impl->reader.getVal168();
}

bool Type::is_obj_cns_object_type(void) const {
  return impl->reader.getVal169();
}

bool Type::is_obj_c_object_or_interface_type(void) const {
  return impl->reader.getVal170();
}

bool Type::is_obj_c_object_pointer_type(void) const {
  return impl->reader.getVal171();
}

bool Type::is_obj_c_object_type(void) const {
  return impl->reader.getVal172();
}

bool Type::is_obj_c_qualified_class_type(void) const {
  return impl->reader.getVal173();
}

bool Type::is_obj_c_qualified_id_type(void) const {
  return impl->reader.getVal174();
}

bool Type::is_obj_c_qualified_interface_type(void) const {
  return impl->reader.getVal175();
}

bool Type::is_obj_c_retainable_type(void) const {
  return impl->reader.getVal176();
}

bool Type::is_obj_c_sel_type(void) const {
  return impl->reader.getVal177();
}

bool Type::is_object_pointer_type(void) const {
  return impl->reader.getVal178();
}

bool Type::is_object_type(void) const {
  return impl->reader.getVal179();
}

bool Type::is_open_cl_specific_type(void) const {
  return impl->reader.getVal180();
}

bool Type::is_overloadable_type(void) const {
  return impl->reader.getVal181();
}

bool Type::is_pipe_type(void) const {
  return impl->reader.getVal182();
}

bool Type::is_placeholder_type(void) const {
  return impl->reader.getVal183();
}

bool Type::is_pointer_type(void) const {
  return impl->reader.getVal184();
}

bool Type::is_queue_t(void) const {
  return impl->reader.getVal185();
}

bool Type::is_rvv_type(void) const {
  return impl->reader.getVal186();
}

bool Type::is_r_value_reference_type(void) const {
  return impl->reader.getVal187();
}

bool Type::is_real_floating_type(void) const {
  return impl->reader.getVal188();
}

bool Type::is_real_type(void) const {
  return impl->reader.getVal189();
}

bool Type::is_record_type(void) const {
  return impl->reader.getVal190();
}

bool Type::is_reference_type(void) const {
  return impl->reader.getVal191();
}

bool Type::is_reserve_idt(void) const {
  return impl->reader.getVal192();
}

bool Type::is_sve_sizeless_builtin_type(void) const {
  return impl->reader.getVal193();
}

bool Type::is_sampler_t(void) const {
  return impl->reader.getVal194();
}

bool Type::is_saturated_fixed_point_type(void) const {
  return impl->reader.getVal195();
}

bool Type::is_scalar_type(void) const {
  return impl->reader.getVal196();
}

bool Type::is_scoped_enumeral_type(void) const {
  return impl->reader.getVal197();
}

bool Type::is_signed_fixed_point_type(void) const {
  return impl->reader.getVal198();
}

bool Type::is_signed_integer_or_enumeration_type(void) const {
  return impl->reader.getVal199();
}

bool Type::is_signed_integer_type(void) const {
  return impl->reader.getVal200();
}

bool Type::is_sizeless_builtin_type(void) const {
  return impl->reader.getVal201();
}

bool Type::is_sizeless_type(void) const {
  return impl->reader.getVal202();
}

bool Type::is_specifier_type(void) const {
  return impl->reader.getVal203();
}

std::optional<bool> Type::is_standard_layout_type(void) const {
  if (!impl->reader.getVal205()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal204());
  }
  return std::nullopt;
}

bool Type::is_std_byte_type(void) const {
  return impl->reader.getVal206();
}

std::optional<bool> Type::is_structural_type(void) const {
  if (!impl->reader.getVal208()) {
    return std::nullopt;
  } else {
    return static_cast<bool>(impl->reader.getVal207());
  }
  return std::nullopt;
}

bool Type::is_structure_or_class_type(void) const {
  return impl->reader.getVal209();
}

bool Type::is_structure_type(void) const {
  return impl->reader.getVal210();
}

bool Type::is_template_type_parm_type(void) const {
  return impl->reader.getVal211();
}

bool Type::is_typedef_name_type(void) const {
  return impl->reader.getVal212();
}

bool Type::is_undeduced_auto_type(void) const {
  return impl->reader.getVal213();
}

bool Type::is_undeduced_type(void) const {
  return impl->reader.getVal214();
}

bool Type::is_union_type(void) const {
  return impl->reader.getVal215();
}

bool Type::is_unsaturated_fixed_point_type(void) const {
  return impl->reader.getVal216();
}

bool Type::is_unscoped_enumeration_type(void) const {
  return impl->reader.getVal217();
}

bool Type::is_unsigned_fixed_point_type(void) const {
  return impl->reader.getVal218();
}

bool Type::is_unsigned_integer_or_enumeration_type(void) const {
  return impl->reader.getVal219();
}

bool Type::is_unsigned_integer_type(void) const {
  return impl->reader.getVal220();
}

bool Type::is_vlst_builtin_type(void) const {
  return impl->reader.getVal221();
}

bool Type::is_variable_array_type(void) const {
  return impl->reader.getVal222();
}

bool Type::is_variably_modified_type(void) const {
  return impl->reader.getVal223();
}

bool Type::is_vector_type(void) const {
  return impl->reader.getVal224();
}

bool Type::is_visibility_explicit(void) const {
  return impl->reader.getVal225();
}

bool Type::is_void_pointer_type(void) const {
  return impl->reader.getVal226();
}

bool Type::is_void_type(void) const {
  return impl->reader.getVal227();
}

bool Type::is_wide_character_type(void) const {
  return impl->reader.getVal228();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
