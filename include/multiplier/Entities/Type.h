// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclUseSelector.h"
#include "LangAS.h"
#include "Linkage.h"
#include "NullabilityKind.h"
#include "QualTypeDestructionKind.h"
#include "QualTypePrimitiveCopyKind.h"
#include "QualTypePrimitiveDefaultInitializeKind.h"
#include "TypeKind.h"
#include "TypeScalarTypeKind.h"
#include "TypeUseSelector.h"
#include "Visibility.h"

namespace mx {
class AutoType;
class BuiltinType;
class CXXRecordDecl;
class ComplexType;
class DeducedType;
class ObjCObjectPointerType;
class ObjCObjectType;
class RecordDecl;
class RecordType;
class TagDecl;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeRange = DerivedEntityRange<TypeIterator, Type>;
using TypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, Type>;
class Type {
 protected:
  friend class Attr;
  friend class AttrIterator;
  friend class Decl;
  friend class DeclIterator;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class ReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  friend class TypeIterator;
  friend class UseBase;
  friend class UseIteratorImpl;
  template <typename> friend class UseIterator;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  Type(Type &&) noexcept = default;
  Type(const Type &) = default;
  Type &operator=(Type &&) noexcept = default;
  Type &operator=(const Type &) = default;

  inline Type(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : fragment(std::move(fragment_)),
        offset_(offset__) {}

  inline static std::optional<Type> from(const Type &self) {
    return self;
  }

  inline static std::optional<Type> from(const std::optional<Type> &self) {
    return self;
  }

  inline static std::optional<Type> from(const TokenContext &c) {
    return c.as_type();
  }

  EntityId id(void) const;
  UseRange<TypeUseSelector> uses(void) const;

 protected:
  static TypeIterator in_internal(const Fragment &fragment);

 public:
  inline static TypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : Type::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  bool is_qualified(void) const;
  Type unqualified_type(void) const;
  bool accepts_obj_c_type_parameters(void) const;
  bool can_decay_to_pointer_type(void) const;
  bool can_have_nullability(void) const;
  bool contains_errors(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  std::optional<Type> array_element_type_no_type_qualified(void) const;
  std::optional<CXXRecordDecl> as_cxx_record_declaration(void) const;
  std::optional<ComplexType> as_complex_integer_type(void) const;
  std::optional<ObjCObjectPointerType> as_obj_c_interface_pointer_type(void) const;
  std::optional<ObjCObjectType> as_obj_c_interface_type(void) const;
  std::optional<ObjCObjectPointerType> as_obj_c_qualified_class_type(void) const;
  std::optional<ObjCObjectPointerType> as_obj_c_qualified_id_type(void) const;
  std::optional<ObjCObjectType> as_obj_c_qualified_interface_type(void) const;
  std::optional<BuiltinType> as_placeholder_type(void) const;
  std::optional<RecordDecl> as_record_declaration(void) const;
  std::optional<RecordType> as_structure_type(void) const;
  std::optional<TagDecl> as_tag_declaration(void) const;
  std::optional<RecordType> as_union_type(void) const;
  std::optional<AutoType> contained_auto_type(void) const;
  std::optional<DeducedType> contained_deduced_type(void) const;
  Linkage linkage(void) const;
  Type locally_unqualified_single_step_desugared_type(void) const;
  std::optional<NullabilityKind> nullability(void) const;
  std::optional<CXXRecordDecl> pointee_cxx_record_declaration(void) const;
  std::optional<Type> pointee_or_array_element_type(void) const;
  std::optional<Type> pointee_type(void) const;
  std::optional<TypeScalarTypeKind> scalar_type_kind(void) const;
  std::optional<Type> sve_element_type(void) const;
  TypeKind kind(void) const;
  Type unqualified_desugared_type(void) const;
  Visibility visibility(void) const;
  bool has_auto_for_trailing_return_type(void) const;
  bool has_floating_representation(void) const;
  bool has_integer_representation(void) const;
  bool has_obj_c_pointer_representation(void) const;
  bool has_pointer_representation(void) const;
  bool has_signed_integer_representation(void) const;
  bool has_sized_vla_type(void) const;
  bool has_unnamed_or_local_type(void) const;
  bool has_unsigned_integer_representation(void) const;
  std::optional<bool> is_aggregate_type(void) const;
  bool is_align_value_t(void) const;
  bool is_any_character_type(void) const;
  bool is_any_complex_type(void) const;
  bool is_any_pointer_type(void) const;
  bool is_arithmetic_type(void) const;
  bool is_array_type(void) const;
  bool is_atomic_type(void) const;
  bool is_b_float16_type(void) const;
  bool is_bit_int_type(void) const;
  bool is_block_compatible_obj_c_pointer_type(void) const;
  bool is_block_pointer_type(void) const;
  bool is_boolean_type(void) const;
  bool is_builtin_type(void) const;
  bool is_carc_bridgable_type(void) const;
  bool is_cuda_device_builtin_surface_type(void) const;
  bool is_cuda_device_builtin_texture_type(void) const;
  bool is_canonical_unqualified(void) const;
  bool is_char16_type(void) const;
  bool is_char32_type(void) const;
  bool is_char8_type(void) const;
  bool is_character_type(void) const;
  bool is_class_type(void) const;
  bool is_clk_event_t(void) const;
  bool is_complex_integer_type(void) const;
  bool is_complex_type(void) const;
  bool is_compound_type(void) const;
  bool is_constant_array_type(void) const;
  bool is_constant_matrix_type(void) const;
  std::optional<bool> is_constant_size_type(void) const;
  bool is_decltype_type(void) const;
  bool is_dependent_address_space_type(void) const;
  bool is_dependent_sized_array_type(void) const;
  bool is_dependent_type(void) const;
  bool is_elaborated_type_specifier(void) const;
  bool is_enumeral_type(void) const;
  bool is_event_t(void) const;
  bool is_ext_vector_boolean_type(void) const;
  bool is_ext_vector_type(void) const;
  bool is_fixed_point_or_integer_type(void) const;
  bool is_fixed_point_type(void) const;
  bool is_float128_type(void) const;
  bool is_float16_type(void) const;
  bool is_floating_type(void) const;
  bool is_from_ast(void) const;
  bool is_function_no_proto_type(void) const;
  bool is_function_pointer_type(void) const;
  bool is_function_proto_type(void) const;
  bool is_function_reference_type(void) const;
  bool is_function_type(void) const;
  bool is_fundamental_type(void) const;
  bool is_half_type(void) const;
  bool is_ibm128_type(void) const;
  bool is_image_type(void) const;
  bool is_incomplete_array_type(void) const;
  bool is_incomplete_or_object_type(void) const;
  bool is_incomplete_type(void) const;
  bool is_instantiation_dependent_type(void) const;
  bool is_integer_type(void) const;
  bool is_integral_or_enumeration_type(void) const;
  bool is_integral_or_unscoped_enumeration_type(void) const;
  bool is_integral_type(void) const;
  bool is_interface_type(void) const;
  bool is_l_value_reference_type(void) const;
  bool is_linkage_valid(void) const;
  std::optional<bool> is_literal_type(void) const;
  bool is_matrix_type(void) const;
  bool is_member_data_pointer_type(void) const;
  bool is_member_function_pointer_type(void) const;
  bool is_member_pointer_type(void) const;
  bool is_non_overload_placeholder_type(void) const;
  bool is_nothrow_t(void) const;
  bool is_null_pointer_type(void) const;
  bool is_ocl_ext_opaque_type(void) const;
  bool is_ocl_image_1d_array_ro_type(void) const;
  bool is_ocl_image_1d_array_rw_type(void) const;
  bool is_ocl_image_1d_array_wo_type(void) const;
  bool is_ocl_image_1d_buffer_ro_type(void) const;
  bool is_ocl_image_1d_buffer_rw_type(void) const;
  bool is_ocl_image_1d_buffer_wo_type(void) const;
  bool is_ocl_image_1d_ro_type(void) const;
  bool is_ocl_image_1d_rw_type(void) const;
  bool is_ocl_image_1d_wo_type(void) const;
  bool is_ocl_image_2d_array_depth_ro_type(void) const;
  bool is_ocl_image_2d_array_depth_rw_type(void) const;
  bool is_ocl_image_2d_array_depth_wo_type(void) const;
  bool is_ocl_image_2d_array_msaa_depth_ro_type(void) const;
  bool is_ocl_image_2d_array_msaa_depth_rw_type(void) const;
  bool is_ocl_image_2d_array_msaa_depth_wo_type(void) const;
  bool is_ocl_image_2d_array_msaaro_type(void) const;
  bool is_ocl_image_2d_array_msaarw_type(void) const;
  bool is_ocl_image_2d_array_msaawo_type(void) const;
  bool is_ocl_image_2d_array_ro_type(void) const;
  bool is_ocl_image_2d_array_rw_type(void) const;
  bool is_ocl_image_2d_array_wo_type(void) const;
  bool is_ocl_image_2d_depth_ro_type(void) const;
  bool is_ocl_image_2d_depth_rw_type(void) const;
  bool is_ocl_image_2d_depth_wo_type(void) const;
  bool is_ocl_image_2d_msaa_depth_ro_type(void) const;
  bool is_ocl_image_2d_msaa_depth_rw_type(void) const;
  bool is_ocl_image_2d_msaa_depth_wo_type(void) const;
  bool is_ocl_image_2d_msaaro_type(void) const;
  bool is_ocl_image_2d_msaarw_type(void) const;
  bool is_ocl_image_2d_msaawo_type(void) const;
  bool is_ocl_image_2d_ro_type(void) const;
  bool is_ocl_image_2d_rw_type(void) const;
  bool is_ocl_image_2d_wo_type(void) const;
  bool is_ocl_image_3d_ro_type(void) const;
  bool is_ocl_image_3d_rw_type(void) const;
  bool is_ocl_image_3d_wo_type(void) const;
  bool is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type(void) const;
  bool is_ocl_intel_subgroup_avc_ime_payload_type(void) const;
  bool is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type(void) const;
  bool is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type(void) const;
  bool is_ocl_intel_subgroup_avc_ime_result_type(void) const;
  bool is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type(void) const;
  bool is_ocl_intel_subgroup_avc_mce_payload_type(void) const;
  bool is_ocl_intel_subgroup_avc_mce_result_type(void) const;
  bool is_ocl_intel_subgroup_avc_ref_payload_type(void) const;
  bool is_ocl_intel_subgroup_avc_ref_result_type(void) const;
  bool is_ocl_intel_subgroup_avc_sic_payload_type(void) const;
  bool is_ocl_intel_subgroup_avc_sic_result_type(void) const;
  bool is_ocl_intel_subgroup_avc_type(void) const;
  bool is_obj_carc_bridgable_type(void) const;
  std::optional<bool> is_obj_carc_implicitly_unretained_type(void) const;
  bool is_obj_c_boxable_record_type(void) const;
  bool is_obj_c_builtin_type(void) const;
  bool is_obj_c_class_or_class_kind_of_type(void) const;
  bool is_obj_c_class_type(void) const;
  bool is_obj_c_id_type(void) const;
  bool is_obj_c_independent_class_type(void) const;
  bool is_obj_c_indirect_lifetime_type(void) const;
  bool is_obj_c_inert_unsafe_unretained_type(void) const;
  bool is_obj_c_lifetime_type(void) const;
  bool is_obj_cns_object_type(void) const;
  bool is_obj_c_object_or_interface_type(void) const;
  bool is_obj_c_object_pointer_type(void) const;
  bool is_obj_c_object_type(void) const;
  bool is_obj_c_qualified_class_type(void) const;
  bool is_obj_c_qualified_id_type(void) const;
  bool is_obj_c_qualified_interface_type(void) const;
  bool is_obj_c_retainable_type(void) const;
  bool is_obj_c_sel_type(void) const;
  bool is_object_pointer_type(void) const;
  bool is_object_type(void) const;
  bool is_open_cl_specific_type(void) const;
  bool is_overloadable_type(void) const;
  bool is_pipe_type(void) const;
  bool is_placeholder_type(void) const;
  bool is_pointer_type(void) const;
  bool is_promotable_integer_type(void) const;
  bool is_queue_t(void) const;
  bool is_r_value_reference_type(void) const;
  bool is_real_floating_type(void) const;
  bool is_real_type(void) const;
  bool is_record_type(void) const;
  bool is_reference_type(void) const;
  bool is_reserve_idt(void) const;
  bool is_sampler_t(void) const;
  bool is_saturated_fixed_point_type(void) const;
  bool is_scalar_type(void) const;
  bool is_scoped_enumeral_type(void) const;
  bool is_signed_fixed_point_type(void) const;
  bool is_signed_integer_or_enumeration_type(void) const;
  bool is_signed_integer_type(void) const;
  bool is_sizeless_builtin_type(void) const;
  bool is_sizeless_type(void) const;
  bool is_specifier_type(void) const;
  std::optional<bool> is_standard_layout_type(void) const;
  bool is_std_byte_type(void) const;
  std::optional<bool> is_structural_type(void) const;
  bool is_structure_or_class_type(void) const;
  bool is_structure_type(void) const;
  bool is_template_type_parm_type(void) const;
  bool is_typedef_name_type(void) const;
  bool is_undeduced_auto_type(void) const;
  bool is_undeduced_type(void) const;
  bool is_union_type(void) const;
  bool is_unsaturated_fixed_point_type(void) const;
  bool is_unscoped_enumeration_type(void) const;
  bool is_unsigned_fixed_point_type(void) const;
  bool is_unsigned_integer_or_enumeration_type(void) const;
  bool is_unsigned_integer_type(void) const;
  bool is_vlst_builtin_type(void) const;
  bool is_variable_array_type(void) const;
  bool is_variably_modified_type(void) const;
  bool is_vector_type(void) const;
  bool is_visibility_explicit(void) const;
  bool is_void_pointer_type(void) const;
  bool is_void_type(void) const;
  bool is_wide_character_type(void) const;
  Type ignore_parentheses(void) const;
  LangAS address_space(void) const;
  Type atomic_unqualified_type(void) const;
  Type canonical_type(void) const;
  Type desugared_type(void) const;
  Type local_unqualified_type(void) const;
  Type non_l_value_expression_type(void) const;
  Type non_pack_expansion_type(void) const;
  Type non_reference_type(void) const;
  Type single_step_desugared_type(void) const;
  bool has_address_space(void) const;
  bool has_local_non_fast_qualifiers(void) const;
  bool has_local_qualifiers(void) const;
  bool has_non_trivial_obj_c_lifetime(void) const;
  bool has_non_trivial_to_primitive_copy_c_union(void) const;
  bool has_non_trivial_to_primitive_default_initialize_c_union(void) const;
  bool has_non_trivial_to_primitive_destruct_c_union(void) const;
  bool has_qualifiers(void) const;
  bool has_strong_or_weak_obj_c_lifetime(void) const;
  bool is_c_forbidden_l_value_type(void) const;
  bool is_cxx11_pod_type(void) const;
  bool is_cxx98_pod_type(void) const;
  bool is_canonical(void) const;
  bool is_canonical_as_parameter(void) const;
  bool is_const_qualified(void) const;
  bool is_constant(void) const;
  QualTypeDestructionKind is_destructed_type(void) const;
  bool is_local_const_qualified(void) const;
  bool is_local_restrict_qualified(void) const;
  bool is_local_volatile_qualified(void) const;
  QualTypePrimitiveCopyKind is_non_trivial_to_primitive_copy(void) const;
  QualTypePrimitiveDefaultInitializeKind is_non_trivial_to_primitive_default_initialize(void) const;
  QualTypePrimitiveCopyKind is_non_trivial_to_primitive_destructive_move(void) const;
  bool is_non_weak_in_mrr_with_obj_c_weak(void) const;
  bool is_null(void) const;
  bool is_obj_cgc_strong(void) const;
  bool is_obj_cgc_weak(void) const;
  bool is_pod_type(void) const;
  bool is_restrict_qualified(void) const;
  bool is_trivial_type(void) const;
  bool is_trivially_copyable_type(void) const;
  bool is_trivially_relocatable_type(void) const;
  bool is_volatile_qualified(void) const;
  bool may_be_dynamic_class(void) const;
  bool may_be_not_dynamic_class(void) const;
  Type strip_obj_c_kind_of_type(void) const;
  Type with_const(void) const;
  Type with_restrict(void) const;
  Type with_volatile(void) const;
  Type without_local_fast_qualifiers(void) const;
};

#endif
} // namespace mx
