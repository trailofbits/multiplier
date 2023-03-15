// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <compare>
#include <cstdint>
#include <filesystem>
#include <gap/core/generator.hpp>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"

#include "Linkage.h"
#include "NullabilityKind.h"
#include "TypeKind.h"
#include "TypeScalarTypeKind.h"
#include "Visibility.h"

namespace mx {
class EntityProvider;
class Index;
class CXXRecordDecl;
class File;
class Fragment;
class Index;
class Reference;
class SourceIR;
class Token;
class Type;
class TypeImpl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Type {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class SourceIR;
  friend class Stmt;
  friend class TokenContext;
  friend class TypeImpl;
  std::shared_ptr<const TypeImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Type(Type &&) noexcept = default;
  Type(const Type &) = default;
  Type &operator=(Type &&) noexcept = default;
  Type &operator=(const Type &) = default;

  friend inline std::strong_ordering operator<=>(const Type &lhs, const Type &rhs) noexcept {
    return lhs.id().Pack() <=> rhs.id().Pack();
  }

  bool operator==(const Type &) const noexcept = default;
  bool operator!=(const Type &) const noexcept = default;

  /* implicit */ inline Type(std::shared_ptr<const TypeImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::TYPE;
  }

  PackedTypeId id(void) const;
  gap::generator<Reference> references(void) const &;

 public:
  static gap::generator<Type> in(const Fragment &frag, std::span<TypeKind> kinds);
  static gap::generator<Type> in(const File &file, std::span<TypeKind> kinds);
  static gap::generator<Type> in(const Index &index, std::span<TypeKind> kinds);
  static gap::generator<Type> in(const Fragment &frag);
  static gap::generator<Type> in(const File &file);
  static gap::generator<Type> in(const Index &index);
  static gap::generator<Type> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Type> by_id(const Index &, EntityId);

  inline static std::optional<Type> from(const Type &self) {
    return self;
  }

  inline static std::optional<Type> from(const std::optional<Type> &self) {
    return self;
  }

  static std::optional<Type> from(const Reference &r);

  static std::optional<Type> from(const TokenContext &t);

  Type desugared_type(void) const;
  Type canonical_type(void) const;
  bool is_qualified(void) const;
  Type unqualified_type(void) const;
  bool accepts_obj_c_type_parameters(void) const;
  bool can_decay_to_pointer_type(void) const;
  bool can_have_nullability(void) const;
  bool contains_errors(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  std::optional<Type> array_element_type_no_type_qualified(void) const;
  Linkage linkage(void) const;
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
};

#endif
} // namespace mx
