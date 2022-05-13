// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#ifndef MX_SERIALIZE_BOOL
#  define MX_SERIALIZE_BOOL(...)
#endif
#ifndef MX_SERIALIZE_INT
#  define MX_SERIALIZE_INT(...)
#endif
#ifndef MX_SERIALIZE_ENUM
#  define MX_SERIALIZE_ENUM(...)
#endif
#ifndef MX_SERIALIZE_TEXT
#  define MX_SERIALIZE_TEXT(...)
#endif
#ifndef MX_SERIALIZE_PATH
#  define MX_SERIALIZE_PATH(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_BOOL
#  define MX_SERIALIZE_OPTIONAL_BOOL(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_INT
#  define MX_SERIALIZE_OPTIONAL_INT(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_ENUM
#  define MX_SERIALIZE_OPTIONAL_ENUM(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_TEXT
#  define MX_SERIALIZE_OPTIONAL_TEXT(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_PATH
#  define MX_SERIALIZE_OPTIONAL_PATH(...)
#endif
#ifndef MX_SERIALIZE_BOOL_LIST
#  define MX_SERIALIZE_BOOL_LIST(...)
#endif
#ifndef MX_SERIALIZE_INT_LIST
#  define MX_SERIALIZE_INT_LIST(...)
#endif
#ifndef MX_SERIALIZE_ENUM_LIST
#  define MX_SERIALIZE_ENUM_LIST(...)
#endif
#ifndef MX_SERIALIZE_TEXT_LIST
#  define MX_SERIALIZE_TEXT_LIST(...)
#endif
#ifndef MX_SERIALIZE_PATH_LIST
#  define MX_SERIALIZE_PATH_LIST(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_BOOL_LIST
#  define MX_SERIALIZE_OPTIONAL_BOOL_LIST(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_INT_LIST
#  define MX_SERIALIZE_OPTIONAL_INT_LIST(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_ENUM_LIST
#  define MX_SERIALIZE_OPTIONAL_ENUM_LIST(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_TEXT_LIST
#  define MX_SERIALIZE_OPTIONAL_TEXT_LIST(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_PATH_LIST
#  define MX_SERIALIZE_OPTIONAL_PATH_LIST(...)
#endif
#ifndef MX_SERIALIZE_ENTITY
#  define MX_SERIALIZE_ENTITY(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_ENTITY
#  define MX_SERIALIZE_OPTIONAL_ENTITY(...)
#endif
#ifndef MX_SERIALIZE_ENTITY_LIST
#  define MX_SERIALIZE_ENTITY_LIST(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_ENTITY_LIST
#  define MX_SERIALIZE_OPTIONAL_ENTITY_LIST(...)
#endif
#ifndef MX_SERIALIZE_DECL_CONTEXT
#  define MX_SERIALIZE_DECL_CONTEXT(...)
#endif
#ifndef MX_SERIALIZE_PSEUDO
#  define MX_SERIALIZE_PSEUDO(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_PSEUDO
#  define MX_SERIALIZE_OPTIONAL_PSEUDO(...)
#endif
#ifndef MX_SERIALIZE_OPTIONAL_PSEUDO_LIST
#  define MX_SERIALIZE_OPTIONAL_PSEUDO_LIST(...)
#endif
#ifndef MX_SERIALIZE_PSEUDO_LIST
#  define MX_SERIALIZE_PSEUDO_LIST(...)
#endif
#ifndef MX_SERIALIZE_BASE
#  define MX_SERIALIZE_BASE(...)
#endif
#ifndef MX_SERIALIZE_DECL_LINK
#  define MX_SERIALIZE_DECL_LINK(...)
#endif
#ifndef MX_SERIALIZE_STMT_LINK
#  define MX_SERIALIZE_STMT_LINK(...)
#endif
#ifndef MX_BEGIN_SERIALIZE_DECL
#  define MX_BEGIN_SERIALIZE_DECL(...)
#endif
#ifndef MX_BEGIN_SERIALIZE_STMT
#  define MX_BEGIN_SERIALIZE_STMT(...)
#endif
#ifndef MX_BEGIN_SERIALIZE_TYPE
#  define MX_BEGIN_SERIALIZE_TYPE(...)
#endif
#ifndef MX_BEGIN_SERIALIZE_PSEUDO
#  define MX_BEGIN_SERIALIZE_PSEUDO(...)
#endif
#ifndef MX_END_SERIALIZE_DECL
#  define MX_END_SERIALIZE_DECL(...)
#endif
#ifndef MX_END_SERIALIZE_STMT
#  define MX_END_SERIALIZE_STMT(...)
#endif
#ifndef MX_END_SERIALIZE_TYPE
#  define MX_END_SERIALIZE_TYPE(...)
#endif
#ifndef MX_END_SERIALIZE_PSEUDO
#  define MX_END_SERIALIZE_PSEUDO(...)
#endif
#ifndef MX_SERIALIZE_PSEUDO_KIND
#  define MX_SERIALIZE_PSEUDO_KIND(...)
#endif

#ifndef MX_ENTER_SERIALIZE_TemplateParameterList
#  define MX_ENTER_SERIALIZE_TemplateParameterList
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateParameterList
#  define MX_EXIT_SERIALIZE_TemplateParameterList
#endif

MX_BEGIN_SERIALIZE_PSEUDO(TemplateParameterList)
  MX_ENTER_SERIALIZE_TemplateParameterList
  MX_SERIALIZE_PSEUDO_KIND(TemplateParameterList, getVal0, setVal0)
  MX_SERIALIZE_INT(TemplateParameterList, num_parameters, getVal1, setVal1, initVal1, NumParameters, unsigned, NthPseudo)
  MX_SERIALIZE_INT(TemplateParameterList, num_required_parameters, getVal2, setVal2, initVal2, NumRequiredParameters, unsigned, NthPseudo)
  MX_SERIALIZE_INT(TemplateParameterList, depth, getVal3, setVal3, initVal3, Depth, unsigned, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateParameterList, has_unexpanded_parameter_pack, getVal4, setVal4, initVal4, HasUnexpandedParameterPack, bool, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateParameterList, has_parameter_pack, getVal5, setVal5, initVal5, HasParameterPack, bool, NthPseudo)
  MX_SERIALIZE_OPTIONAL_ENTITY(TemplateParameterList, requires_clause, getVal6, setVal6, initVal6, RequiresClause, Expr, NthPseudo)
  MX_SERIALIZE_ENTITY(TemplateParameterList, template_keyword_token, getVal8, setVal8, initVal8, TemplateKeywordToken, Token, NthPseudo)
  MX_SERIALIZE_ENTITY(TemplateParameterList, left_angle_token, getVal9, setVal9, initVal9, LeftAngleToken, Token, NthPseudo)
  MX_SERIALIZE_ENTITY(TemplateParameterList, right_angle_token, getVal10, setVal10, initVal10, RightAngleToken, Token, NthPseudo)
  MX_SERIALIZE_ENTITY_LIST(TemplateParameterList, parameters, getVal13, setVal13, initVal13, Parameters, NamedDecl, NthPseudo)
  MX_EXIT_SERIALIZE_TemplateParameterList
MX_END_SERIALIZE_PSEUDO(TemplateParameterList)
#undef MX_ENTER_SERIALIZE_TemplateParameterList
#undef MX_EXIT_SERIALIZE_TemplateParameterList

#ifndef MX_ENTER_SERIALIZE_TemplateArgument
#  define MX_ENTER_SERIALIZE_TemplateArgument
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateArgument
#  define MX_EXIT_SERIALIZE_TemplateArgument
#endif

MX_BEGIN_SERIALIZE_PSEUDO(TemplateArgument)
  MX_ENTER_SERIALIZE_TemplateArgument
  MX_SERIALIZE_PSEUDO_KIND(TemplateArgument, getVal0, setVal0)
  MX_SERIALIZE_ENUM(TemplateArgument, kind, getVal14, setVal14, initVal14, Kind, TemplateArgumentKind, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateArgument, is_null, getVal4, setVal4, initVal4, IsNull, bool, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateArgument, is_dependent, getVal5, setVal5, initVal5, IsDependent, bool, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateArgument, is_instantiation_dependent, getVal7, setVal7, initVal7, IsInstantiationDependent, bool, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateArgument, contains_unexpanded_parameter_pack, getVal15, setVal15, initVal15, ContainsUnexpandedParameterPack, bool, NthPseudo)
  MX_SERIALIZE_BOOL(TemplateArgument, is_pack_expansion, getVal16, setVal16, initVal16, IsPackExpansion, bool, NthPseudo)
  MX_SERIALIZE_OPTIONAL_ENTITY(TemplateArgument, as_declaration, getVal6, setVal6, initVal6, AsDeclaration, ValueDecl, NthPseudo)
  MX_SERIALIZE_OPTIONAL_ENTITY(TemplateArgument, as_type, getVal8, setVal8, initVal8, AsType, Type, NthPseudo)
  MX_SERIALIZE_OPTIONAL_ENTITY(TemplateArgument, parameter_type_for_declaration, getVal9, setVal9, initVal9, ParameterTypeForDeclaration, Type, NthPseudo)
  MX_SERIALIZE_OPTIONAL_ENTITY(TemplateArgument, null_pointer_type, getVal10, setVal10, initVal10, NullPointerType, Type, NthPseudo)
  MX_EXIT_SERIALIZE_TemplateArgument
MX_END_SERIALIZE_PSEUDO(TemplateArgument)
#undef MX_ENTER_SERIALIZE_TemplateArgument
#undef MX_EXIT_SERIALIZE_TemplateArgument

#ifndef MX_ENTER_SERIALIZE_CXXBaseSpecifier
#  define MX_ENTER_SERIALIZE_CXXBaseSpecifier
#endif
#ifndef MX_EXIT_SERIALIZE_CXXBaseSpecifier
#  define MX_EXIT_SERIALIZE_CXXBaseSpecifier
#endif

MX_BEGIN_SERIALIZE_PSEUDO(CXXBaseSpecifier)
  MX_ENTER_SERIALIZE_CXXBaseSpecifier
  MX_SERIALIZE_PSEUDO_KIND(CXXBaseSpecifier, getVal0, setVal0)
  MX_SERIALIZE_ENTITY(CXXBaseSpecifier, base_type_token, getVal9, setVal9, initVal9, BaseTypeToken, Token, NthPseudo)
  MX_SERIALIZE_BOOL(CXXBaseSpecifier, is_virtual, getVal4, setVal4, initVal4, IsVirtual, bool, NthPseudo)
  MX_SERIALIZE_ENUM(CXXBaseSpecifier, base_kind, getVal14, setVal14, initVal14, BaseKind, TagTypeKind, NthPseudo)
  MX_SERIALIZE_BOOL(CXXBaseSpecifier, is_pack_expansion, getVal5, setVal5, initVal5, IsPackExpansion, bool, NthPseudo)
  MX_SERIALIZE_BOOL(CXXBaseSpecifier, constructors_are_inherited, getVal7, setVal7, initVal7, ConstructorsAreInherited, bool, NthPseudo)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXBaseSpecifier, ellipsis, getVal10, setVal10, initVal10, Ellipsis, Token, NthPseudo)
  MX_SERIALIZE_ENUM(CXXBaseSpecifier, semantic_access_specifier, getVal21, setVal21, initVal21, SemanticAccessSpecifier, AccessSpecifier, NthPseudo)
  MX_SERIALIZE_ENUM(CXXBaseSpecifier, lexical_access_specifier, getVal22, setVal22, initVal22, LexicalAccessSpecifier, AccessSpecifier, NthPseudo)
  MX_SERIALIZE_ENTITY(CXXBaseSpecifier, base_type, getVal11, setVal11, initVal11, BaseType, Type, NthPseudo)
  MX_EXIT_SERIALIZE_CXXBaseSpecifier
MX_END_SERIALIZE_PSEUDO(CXXBaseSpecifier)
#undef MX_ENTER_SERIALIZE_CXXBaseSpecifier
#undef MX_EXIT_SERIALIZE_CXXBaseSpecifier

#ifndef MX_ENTER_SERIALIZE_Type
#  define MX_ENTER_SERIALIZE_Type
#endif
#ifndef MX_EXIT_SERIALIZE_Type
#  define MX_EXIT_SERIALIZE_Type
#endif

MX_BEGIN_SERIALIZE_TYPE(Type)
  MX_ENTER_SERIALIZE_Type
  MX_SERIALIZE_BOOL(Type, is_qualified, getVal0, setVal0, initVal0, IsQualified, bool, NthType)
  MX_SERIALIZE_ENTITY(Type, unqualified_type, getVal1, setVal1, initVal1, UnqualifiedType, Type, NthType)
  MX_SERIALIZE_BOOL(Type, accepts_obj_c_type_parameters, getVal2, setVal2, initVal2, AcceptsObjCTypeParameters, bool, NthType)
  MX_SERIALIZE_BOOL(Type, can_decay_to_pointer_type, getVal3, setVal3, initVal3, CanDecayToPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, can_have_nullability, getVal4, setVal4, initVal4, CanHaveNullability, bool, NthType)
  MX_SERIALIZE_BOOL(Type, contains_errors, getVal5, setVal5, initVal5, ContainsErrors, bool, NthType)
  MX_SERIALIZE_BOOL(Type, contains_unexpanded_parameter_pack, getVal6, setVal6, initVal6, ContainsUnexpandedParameterPack, bool, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, array_element_type_no_type_qualified, getVal7, setVal7, initVal7, ArrayElementTypeNoTypeQualified, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_cxx_record_declaration, getVal9, setVal9, initVal9, AsCXXRecordDeclaration, CXXRecordDecl, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_complex_integer_type, getVal11, setVal11, initVal11, AsComplexIntegerType, ComplexType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_obj_c_interface_pointer_type, getVal13, setVal13, initVal13, AsObjCInterfacePointerType, ObjCObjectPointerType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_obj_c_interface_type, getVal15, setVal15, initVal15, AsObjCInterfaceType, ObjCObjectType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_obj_c_qualified_class_type, getVal17, setVal17, initVal17, AsObjCQualifiedClassType, ObjCObjectPointerType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_obj_c_qualified_id_type, getVal19, setVal19, initVal19, AsObjCQualifiedIdType, ObjCObjectPointerType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_obj_c_qualified_interface_type, getVal21, setVal21, initVal21, AsObjCQualifiedInterfaceType, ObjCObjectType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_placeholder_type, getVal23, setVal23, initVal23, AsPlaceholderType, BuiltinType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_record_declaration, getVal25, setVal25, initVal25, AsRecordDeclaration, RecordDecl, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_structure_type, getVal27, setVal27, initVal27, AsStructureType, RecordType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_tag_declaration, getVal29, setVal29, initVal29, AsTagDeclaration, TagDecl, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, as_union_type, getVal31, setVal31, initVal31, AsUnionType, RecordType, NthType)
  MX_SERIALIZE_ENTITY(Type, canonical_type_internal, getVal33, setVal33, initVal33, CanonicalTypeInternal, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, contained_auto_type, getVal34, setVal34, initVal34, ContainedAutoType, AutoType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, contained_deduced_type, getVal36, setVal36, initVal36, ContainedDeducedType, DeducedType, NthType)
  MX_SERIALIZE_ENUM(Type, linkage, getVal38, setVal38, initVal38, Linkage, Linkage, NthType)
  MX_SERIALIZE_ENTITY(Type, locally_unqualified_single_step_desugared_type, getVal39, setVal39, initVal39, LocallyUnqualifiedSingleStepDesugaredType, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENUM(Type, nullability, getVal40, setVal40, initVal40, Nullability, NullabilityKind, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, pointee_cxx_record_declaration, getVal42, setVal42, initVal42, PointeeCXXRecordDeclaration, CXXRecordDecl, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, pointee_or_array_element_type, getVal44, setVal44, initVal44, PointeeOrArrayElementType, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, pointee_type, getVal46, setVal46, initVal46, PointeeType, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENUM(Type, scalar_type_kind, getVal48, setVal48, initVal48, ScalarTypeKind, TypeScalarTypeKind, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(Type, sve_element_type, getVal50, setVal50, initVal50, SveElementType, Type, NthType)
  MX_SERIALIZE_ENUM(Type, kind, getVal52, setVal52, initVal52, Kind, TypeKind, NthType)
  MX_SERIALIZE_ENTITY(Type, unqualified_desugared_type, getVal53, setVal53, initVal53, UnqualifiedDesugaredType, Type, NthType)
  MX_SERIALIZE_ENUM(Type, visibility, getVal54, setVal54, initVal54, Visibility, Visibility, NthType)
  MX_SERIALIZE_BOOL(Type, has_auto_for_trailing_return_type, getVal55, setVal55, initVal55, HasAutoForTrailingReturnType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_floating_representation, getVal56, setVal56, initVal56, HasFloatingRepresentation, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_integer_representation, getVal57, setVal57, initVal57, HasIntegerRepresentation, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_obj_c_pointer_representation, getVal58, setVal58, initVal58, HasObjCPointerRepresentation, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_pointer_representation, getVal59, setVal59, initVal59, HasPointerRepresentation, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_signed_integer_representation, getVal60, setVal60, initVal60, HasSignedIntegerRepresentation, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_sized_vla_type, getVal61, setVal61, initVal61, HasSizedVLAType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_unnamed_or_local_type, getVal62, setVal62, initVal62, HasUnnamedOrLocalType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_unsigned_integer_representation, getVal63, setVal63, initVal63, HasUnsignedIntegerRepresentation, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_aggregate_type, getVal64, setVal64, initVal64, IsAggregateType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_align_value_t, getVal65, setVal65, initVal65, IsAlignValueT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_any_character_type, getVal66, setVal66, initVal66, IsAnyCharacterType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_any_complex_type, getVal67, setVal67, initVal67, IsAnyComplexType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_any_pointer_type, getVal68, setVal68, initVal68, IsAnyPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_arithmetic_type, getVal69, setVal69, initVal69, IsArithmeticType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_array_type, getVal70, setVal70, initVal70, IsArrayType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_atomic_type, getVal71, setVal71, initVal71, IsAtomicType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_b_float16_type, getVal72, setVal72, initVal72, IsBFloat16Type, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_block_compatible_obj_c_pointer_type, getVal73, setVal73, initVal73, IsBlockCompatibleObjCPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_block_pointer_type, getVal74, setVal74, initVal74, IsBlockPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_boolean_type, getVal75, setVal75, initVal75, IsBooleanType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_builtin_type, getVal76, setVal76, initVal76, IsBuiltinType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_carc_bridgable_type, getVal77, setVal77, initVal77, IsCARCBridgableType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_cuda_device_builtin_surface_type, getVal78, setVal78, initVal78, IsCUDADeviceBuiltinSurfaceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_cuda_device_builtin_texture_type, getVal79, setVal79, initVal79, IsCUDADeviceBuiltinTextureType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_canonical_unqualified, getVal80, setVal80, initVal80, IsCanonicalUnqualified, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_char16_type, getVal81, setVal81, initVal81, IsChar16Type, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_char32_type, getVal82, setVal82, initVal82, IsChar32Type, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_char8_type, getVal83, setVal83, initVal83, IsChar8Type, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_character_type, getVal84, setVal84, initVal84, IsCharacterType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_class_type, getVal85, setVal85, initVal85, IsClassType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_clk_event_t, getVal86, setVal86, initVal86, IsClkEventT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_complex_integer_type, getVal87, setVal87, initVal87, IsComplexIntegerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_complex_type, getVal88, setVal88, initVal88, IsComplexType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_compound_type, getVal89, setVal89, initVal89, IsCompoundType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_constant_array_type, getVal90, setVal90, initVal90, IsConstantArrayType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_constant_matrix_type, getVal91, setVal91, initVal91, IsConstantMatrixType, bool, NthType)
  MX_SERIALIZE_OPTIONAL_BOOL(Type, is_constant_size_type, getVal92, setVal92, initVal92, IsConstantSizeType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_decltype_type, getVal94, setVal94, initVal94, IsDecltypeType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_dependent_address_space_type, getVal95, setVal95, initVal95, IsDependentAddressSpaceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_dependent_sized_array_type, getVal96, setVal96, initVal96, IsDependentSizedArrayType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_dependent_type, getVal97, setVal97, initVal97, IsDependentType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_elaborated_type_specifier, getVal98, setVal98, initVal98, IsElaboratedTypeSpecifier, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_enumeral_type, getVal99, setVal99, initVal99, IsEnumeralType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_event_t, getVal100, setVal100, initVal100, IsEventT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ext_int_type, getVal101, setVal101, initVal101, IsExtIntType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ext_vector_type, getVal102, setVal102, initVal102, IsExtVectorType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_fixed_point_or_integer_type, getVal103, setVal103, initVal103, IsFixedPointOrIntegerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_fixed_point_type, getVal104, setVal104, initVal104, IsFixedPointType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_float128_type, getVal105, setVal105, initVal105, IsFloat128Type, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_float16_type, getVal106, setVal106, initVal106, IsFloat16Type, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_floating_type, getVal107, setVal107, initVal107, IsFloatingType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_from_ast, getVal108, setVal108, initVal108, IsFromAST, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_function_no_proto_type, getVal109, setVal109, initVal109, IsFunctionNoProtoType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_function_pointer_type, getVal110, setVal110, initVal110, IsFunctionPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_function_proto_type, getVal111, setVal111, initVal111, IsFunctionProtoType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_function_reference_type, getVal112, setVal112, initVal112, IsFunctionReferenceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_function_type, getVal113, setVal113, initVal113, IsFunctionType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_fundamental_type, getVal114, setVal114, initVal114, IsFundamentalType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_half_type, getVal115, setVal115, initVal115, IsHalfType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_image_type, getVal116, setVal116, initVal116, IsImageType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_incomplete_array_type, getVal117, setVal117, initVal117, IsIncompleteArrayType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_incomplete_or_object_type, getVal118, setVal118, initVal118, IsIncompleteOrObjectType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_incomplete_type, getVal119, setVal119, initVal119, IsIncompleteType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_instantiation_dependent_type, getVal120, setVal120, initVal120, IsInstantiationDependentType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_integer_type, getVal121, setVal121, initVal121, IsIntegerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_integral_or_enumeration_type, getVal122, setVal122, initVal122, IsIntegralOrEnumerationType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_integral_or_unscoped_enumeration_type, getVal123, setVal123, initVal123, IsIntegralOrUnscopedEnumerationType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_integral_type, getVal124, setVal124, initVal124, IsIntegralType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_interface_type, getVal125, setVal125, initVal125, IsInterfaceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_l_value_reference_type, getVal126, setVal126, initVal126, IsLValueReferenceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_linkage_valid, getVal127, setVal127, initVal127, IsLinkageValid, bool, NthType)
  MX_SERIALIZE_OPTIONAL_BOOL(Type, is_literal_type, getVal128, setVal128, initVal128, IsLiteralType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_matrix_type, getVal130, setVal130, initVal130, IsMatrixType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_member_data_pointer_type, getVal131, setVal131, initVal131, IsMemberDataPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_member_function_pointer_type, getVal132, setVal132, initVal132, IsMemberFunctionPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_member_pointer_type, getVal133, setVal133, initVal133, IsMemberPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_non_overload_placeholder_type, getVal134, setVal134, initVal134, IsNonOverloadPlaceholderType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_nothrow_t, getVal135, setVal135, initVal135, IsNothrowT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_null_pointer_type, getVal136, setVal136, initVal136, IsNullPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_ext_opaque_type, getVal137, setVal137, initVal137, IsOCLExtOpaqueType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_darray_ro_type, getVal138, setVal138, initVal138, IsOCLImage1dArrayROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_darray_rw_type, getVal139, setVal139, initVal139, IsOCLImage1dArrayRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_darray_wo_type, getVal140, setVal140, initVal140, IsOCLImage1dArrayWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_dbuffer_ro_type, getVal141, setVal141, initVal141, IsOCLImage1dBufferROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_dbuffer_rw_type, getVal142, setVal142, initVal142, IsOCLImage1dBufferRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_dbuffer_wo_type, getVal143, setVal143, initVal143, IsOCLImage1dBufferWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_dro_type, getVal144, setVal144, initVal144, IsOCLImage1dROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_drw_type, getVal145, setVal145, initVal145, IsOCLImage1dRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image1_dwo_type, getVal146, setVal146, initVal146, IsOCLImage1dWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_depth_ro_type, getVal147, setVal147, initVal147, IsOCLImage2dArrayDepthROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_depth_rw_type, getVal148, setVal148, initVal148, IsOCLImage2dArrayDepthRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_depth_wo_type, getVal149, setVal149, initVal149, IsOCLImage2dArrayDepthWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_msaa_depth_ro_type, getVal150, setVal150, initVal150, IsOCLImage2dArrayMSAADepthROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_msaa_depth_rw_type, getVal151, setVal151, initVal151, IsOCLImage2dArrayMSAADepthRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_msaa_depth_wo_type, getVal152, setVal152, initVal152, IsOCLImage2dArrayMSAADepthWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_msaaro_type, getVal153, setVal153, initVal153, IsOCLImage2dArrayMSAAROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_msaarw_type, getVal154, setVal154, initVal154, IsOCLImage2dArrayMSAARWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_msaawo_type, getVal155, setVal155, initVal155, IsOCLImage2dArrayMSAAWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_ro_type, getVal156, setVal156, initVal156, IsOCLImage2dArrayROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_rw_type, getVal157, setVal157, initVal157, IsOCLImage2dArrayRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_darray_wo_type, getVal158, setVal158, initVal158, IsOCLImage2dArrayWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_ddepth_ro_type, getVal159, setVal159, initVal159, IsOCLImage2dDepthROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_ddepth_rw_type, getVal160, setVal160, initVal160, IsOCLImage2dDepthRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_ddepth_wo_type, getVal161, setVal161, initVal161, IsOCLImage2dDepthWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dmsaa_depth_ro_type, getVal162, setVal162, initVal162, IsOCLImage2dMSAADepthROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dmsaa_depth_rw_type, getVal163, setVal163, initVal163, IsOCLImage2dMSAADepthRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dmsaa_depth_wo_type, getVal164, setVal164, initVal164, IsOCLImage2dMSAADepthWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dmsaaro_type, getVal165, setVal165, initVal165, IsOCLImage2dMSAAROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dmsaarw_type, getVal166, setVal166, initVal166, IsOCLImage2dMSAARWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dmsaawo_type, getVal167, setVal167, initVal167, IsOCLImage2dMSAAWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dro_type, getVal168, setVal168, initVal168, IsOCLImage2dROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_drw_type, getVal169, setVal169, initVal169, IsOCLImage2dRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image2_dwo_type, getVal170, setVal170, initVal170, IsOCLImage2dWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image3_dro_type, getVal171, setVal171, initVal171, IsOCLImage3dROType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image3_drw_type, getVal172, setVal172, initVal172, IsOCLImage3dRWType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_image3_dwo_type, getVal173, setVal173, initVal173, IsOCLImage3dWOType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type, getVal174, setVal174, initVal174, IsOCLIntelSubgroupAVCImeDualReferenceStreaminType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ime_payload_type, getVal175, setVal175, initVal175, IsOCLIntelSubgroupAVCImePayloadType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type, getVal176, setVal176, initVal176, IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type, getVal177, setVal177, initVal177, IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_type, getVal178, setVal178, initVal178, IsOCLIntelSubgroupAVCImeResultType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type, getVal179, setVal179, initVal179, IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_mce_payload_type, getVal180, setVal180, initVal180, IsOCLIntelSubgroupAVCMcePayloadType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_mce_result_type, getVal181, setVal181, initVal181, IsOCLIntelSubgroupAVCMceResultType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ref_payload_type, getVal182, setVal182, initVal182, IsOCLIntelSubgroupAVCRefPayloadType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_ref_result_type, getVal183, setVal183, initVal183, IsOCLIntelSubgroupAVCRefResultType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_sic_payload_type, getVal184, setVal184, initVal184, IsOCLIntelSubgroupAVCSicPayloadType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_sic_result_type, getVal185, setVal185, initVal185, IsOCLIntelSubgroupAVCSicResultType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_ocl_intel_subgroup_avc_type, getVal186, setVal186, initVal186, IsOCLIntelSubgroupAVCType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_carc_bridgable_type, getVal187, setVal187, initVal187, IsObjCARCBridgableType, bool, NthType)
  MX_SERIALIZE_OPTIONAL_BOOL(Type, is_obj_carc_implicitly_unretained_type, getVal188, setVal188, initVal188, IsObjCARCImplicitlyUnretainedType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_boxable_record_type, getVal190, setVal190, initVal190, IsObjCBoxableRecordType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_builtin_type, getVal191, setVal191, initVal191, IsObjCBuiltinType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_class_or_class_kind_of_type, getVal192, setVal192, initVal192, IsObjCClassOrClassKindOfType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_class_type, getVal193, setVal193, initVal193, IsObjCClassType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_id_type, getVal194, setVal194, initVal194, IsObjCIdType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_independent_class_type, getVal195, setVal195, initVal195, IsObjCIndependentClassType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_indirect_lifetime_type, getVal196, setVal196, initVal196, IsObjCIndirectLifetimeType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_inert_unsafe_unretained_type, getVal197, setVal197, initVal197, IsObjCInertUnsafeUnretainedType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_lifetime_type, getVal198, setVal198, initVal198, IsObjCLifetimeType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_cns_object_type, getVal199, setVal199, initVal199, IsObjCNSObjectType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_object_or_interface_type, getVal200, setVal200, initVal200, IsObjCObjectOrInterfaceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_object_pointer_type, getVal201, setVal201, initVal201, IsObjCObjectPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_object_type, getVal202, setVal202, initVal202, IsObjCObjectType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_qualified_class_type, getVal203, setVal203, initVal203, IsObjCQualifiedClassType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_qualified_id_type, getVal204, setVal204, initVal204, IsObjCQualifiedIdType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_qualified_interface_type, getVal205, setVal205, initVal205, IsObjCQualifiedInterfaceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_retainable_type, getVal206, setVal206, initVal206, IsObjCRetainableType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_c_sel_type, getVal207, setVal207, initVal207, IsObjCSelType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_object_pointer_type, getVal208, setVal208, initVal208, IsObjectPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_object_type, getVal209, setVal209, initVal209, IsObjectType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_open_cl_specific_type, getVal210, setVal210, initVal210, IsOpenCLSpecificType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_overloadable_type, getVal211, setVal211, initVal211, IsOverloadableType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_pipe_type, getVal212, setVal212, initVal212, IsPipeType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_placeholder_type, getVal213, setVal213, initVal213, IsPlaceholderType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_pointer_type, getVal214, setVal214, initVal214, IsPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_promotable_integer_type, getVal215, setVal215, initVal215, IsPromotableIntegerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_queue_t, getVal216, setVal216, initVal216, IsQueueT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_r_value_reference_type, getVal217, setVal217, initVal217, IsRValueReferenceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_real_floating_type, getVal218, setVal218, initVal218, IsRealFloatingType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_real_type, getVal219, setVal219, initVal219, IsRealType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_record_type, getVal220, setVal220, initVal220, IsRecordType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_reference_type, getVal221, setVal221, initVal221, IsReferenceType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_reserve_idt, getVal222, setVal222, initVal222, IsReserveIDT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_sampler_t, getVal223, setVal223, initVal223, IsSamplerT, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_saturated_fixed_point_type, getVal224, setVal224, initVal224, IsSaturatedFixedPointType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_scalar_type, getVal225, setVal225, initVal225, IsScalarType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_scoped_enumeral_type, getVal226, setVal226, initVal226, IsScopedEnumeralType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_signed_fixed_point_type, getVal227, setVal227, initVal227, IsSignedFixedPointType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_signed_integer_or_enumeration_type, getVal228, setVal228, initVal228, IsSignedIntegerOrEnumerationType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_signed_integer_type, getVal229, setVal229, initVal229, IsSignedIntegerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_sizeless_builtin_type, getVal230, setVal230, initVal230, IsSizelessBuiltinType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_sizeless_type, getVal231, setVal231, initVal231, IsSizelessType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_specifier_type, getVal232, setVal232, initVal232, IsSpecifierType, bool, NthType)
  MX_SERIALIZE_OPTIONAL_BOOL(Type, is_standard_layout_type, getVal233, setVal233, initVal233, IsStandardLayoutType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_std_byte_type, getVal235, setVal235, initVal235, IsStdByteType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_structural_type, getVal236, setVal236, initVal236, IsStructuralType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_structure_or_class_type, getVal237, setVal237, initVal237, IsStructureOrClassType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_structure_type, getVal238, setVal238, initVal238, IsStructureType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_template_type_parm_type, getVal239, setVal239, initVal239, IsTemplateTypeParmType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_typedef_name_type, getVal240, setVal240, initVal240, IsTypedefNameType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_undeduced_auto_type, getVal241, setVal241, initVal241, IsUndeducedAutoType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_undeduced_type, getVal242, setVal242, initVal242, IsUndeducedType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_union_type, getVal243, setVal243, initVal243, IsUnionType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_unsaturated_fixed_point_type, getVal244, setVal244, initVal244, IsUnsaturatedFixedPointType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_unscoped_enumeration_type, getVal245, setVal245, initVal245, IsUnscopedEnumerationType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_unsigned_fixed_point_type, getVal246, setVal246, initVal246, IsUnsignedFixedPointType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_unsigned_integer_or_enumeration_type, getVal247, setVal247, initVal247, IsUnsignedIntegerOrEnumerationType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_unsigned_integer_type, getVal248, setVal248, initVal248, IsUnsignedIntegerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_vlst_builtin_type, getVal249, setVal249, initVal249, IsVLSTBuiltinType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_variable_array_type, getVal250, setVal250, initVal250, IsVariableArrayType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_variably_modified_type, getVal251, setVal251, initVal251, IsVariablyModifiedType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_vector_type, getVal252, setVal252, initVal252, IsVectorType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_visibility_explicit, getVal253, setVal253, initVal253, IsVisibilityExplicit, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_void_pointer_type, getVal254, setVal254, initVal254, IsVoidPointerType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_void_type, getVal255, setVal255, initVal255, IsVoidType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_wide_character_type, getVal256, setVal256, initVal256, IsWideCharacterType, bool, NthType)
  MX_SERIALIZE_ENTITY(Type, ignore_parentheses, getVal257, setVal257, initVal257, IgnoreParentheses, Type, NthType)
  MX_SERIALIZE_ENUM(Type, address_space, getVal258, setVal258, initVal258, AddressSpace, LangAS, NthType)
  MX_SERIALIZE_ENTITY(Type, atomic_unqualified_type, getVal259, setVal259, initVal259, AtomicUnqualifiedType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, canonical_type, getVal260, setVal260, initVal260, CanonicalType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, desugared_type, getVal261, setVal261, initVal261, DesugaredType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, local_unqualified_type, getVal262, setVal262, initVal262, LocalUnqualifiedType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, non_l_value_expression_type, getVal263, setVal263, initVal263, NonLValueExpressionType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, non_pack_expansion_type, getVal264, setVal264, initVal264, NonPackExpansionType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, non_reference_type, getVal265, setVal265, initVal265, NonReferenceType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, single_step_desugared_type, getVal266, setVal266, initVal266, SingleStepDesugaredType, Type, NthType)
  MX_SERIALIZE_BOOL(Type, has_address_space, getVal267, setVal267, initVal267, HasAddressSpace, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_local_non_fast_qualifiers, getVal268, setVal268, initVal268, HasLocalNonFastQualifiers, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_local_qualifiers, getVal269, setVal269, initVal269, HasLocalQualifiers, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_non_trivial_obj_c_lifetime, getVal270, setVal270, initVal270, HasNonTrivialObjCLifetime, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_non_trivial_to_primitive_copy_c_union, getVal271, setVal271, initVal271, HasNonTrivialToPrimitiveCopyCUnion, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_non_trivial_to_primitive_default_initialize_c_union, getVal272, setVal272, initVal272, HasNonTrivialToPrimitiveDefaultInitializeCUnion, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_non_trivial_to_primitive_destruct_c_union, getVal273, setVal273, initVal273, HasNonTrivialToPrimitiveDestructCUnion, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_qualifiers, getVal274, setVal274, initVal274, HasQualifiers, bool, NthType)
  MX_SERIALIZE_BOOL(Type, has_strong_or_weak_obj_c_lifetime, getVal275, setVal275, initVal275, HasStrongOrWeakObjCLifetime, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_c_forbidden_l_value_type, getVal276, setVal276, initVal276, IsCForbiddenLValueType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_cxx11_pod_type, getVal277, setVal277, initVal277, IsCXX11PODType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_cxx98_pod_type, getVal278, setVal278, initVal278, IsCXX98PODType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_canonical, getVal279, setVal279, initVal279, IsCanonical, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_canonical_as_parameter, getVal280, setVal280, initVal280, IsCanonicalAsParameter, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_const_qualified, getVal281, setVal281, initVal281, IsConstQualified, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_constant, getVal282, setVal282, initVal282, IsConstant, bool, NthType)
  MX_SERIALIZE_ENUM(Type, is_destructed_type, getVal283, setVal283, initVal283, IsDestructedType, QualTypeDestructionKind, NthType)
  MX_SERIALIZE_BOOL(Type, is_local_const_qualified, getVal284, setVal284, initVal284, IsLocalConstQualified, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_local_restrict_qualified, getVal285, setVal285, initVal285, IsLocalRestrictQualified, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_local_volatile_qualified, getVal286, setVal286, initVal286, IsLocalVolatileQualified, bool, NthType)
  MX_SERIALIZE_ENUM(Type, is_non_trivial_to_primitive_copy, getVal287, setVal287, initVal287, IsNonTrivialToPrimitiveCopy, QualTypePrimitiveCopyKind, NthType)
  MX_SERIALIZE_ENUM(Type, is_non_trivial_to_primitive_default_initialize, getVal288, setVal288, initVal288, IsNonTrivialToPrimitiveDefaultInitialize, QualTypePrimitiveDefaultInitializeKind, NthType)
  MX_SERIALIZE_ENUM(Type, is_non_trivial_to_primitive_destructive_move, getVal289, setVal289, initVal289, IsNonTrivialToPrimitiveDestructiveMove, QualTypePrimitiveCopyKind, NthType)
  MX_SERIALIZE_BOOL(Type, is_non_weak_in_mrr_with_obj_c_weak, getVal290, setVal290, initVal290, IsNonWeakInMRRWithObjCWeak, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_null, getVal291, setVal291, initVal291, IsNull, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_cgc_strong, getVal292, setVal292, initVal292, IsObjCGCStrong, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_obj_cgc_weak, getVal293, setVal293, initVal293, IsObjCGCWeak, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_pod_type, getVal294, setVal294, initVal294, IsPODType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_restrict_qualified, getVal295, setVal295, initVal295, IsRestrictQualified, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_trivial_type, getVal296, setVal296, initVal296, IsTrivialType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_trivially_copyable_type, getVal297, setVal297, initVal297, IsTriviallyCopyableType, bool, NthType)
  MX_SERIALIZE_BOOL(Type, is_volatile_qualified, getVal298, setVal298, initVal298, IsVolatileQualified, bool, NthType)
  MX_SERIALIZE_BOOL(Type, may_be_dynamic_class, getVal299, setVal299, initVal299, MayBeDynamicClass, bool, NthType)
  MX_SERIALIZE_BOOL(Type, may_be_not_dynamic_class, getVal300, setVal300, initVal300, MayBeNotDynamicClass, bool, NthType)
  MX_SERIALIZE_ENTITY(Type, strip_obj_c_kind_of_type, getVal301, setVal301, initVal301, StripObjCKindOfType, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, with_const, getVal302, setVal302, initVal302, WithConst, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, with_restrict, getVal303, setVal303, initVal303, WithRestrict, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, with_volatile, getVal304, setVal304, initVal304, WithVolatile, Type, NthType)
  MX_SERIALIZE_ENTITY(Type, without_local_fast_qualifiers, getVal305, setVal305, initVal305, WithoutLocalFastQualifiers, Type, NthType)
  MX_EXIT_SERIALIZE_Type
MX_END_SERIALIZE_TYPE(Type)
#undef MX_ENTER_SERIALIZE_Type
#undef MX_EXIT_SERIALIZE_Type

#ifndef MX_ENTER_SERIALIZE_TemplateTypeParmType
#  define MX_ENTER_SERIALIZE_TemplateTypeParmType
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateTypeParmType
#  define MX_EXIT_SERIALIZE_TemplateTypeParmType
#endif

MX_BEGIN_SERIALIZE_TYPE(TemplateTypeParmType)
  MX_ENTER_SERIALIZE_TemplateTypeParmType
  MX_SERIALIZE_BASE(TemplateTypeParmType, Type)
  MX_SERIALIZE_ENTITY(TemplateTypeParmType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(TemplateTypeParmType, declaration, getVal307, setVal307, initVal307, Declaration, TemplateTypeParmDecl, NthType)
  MX_SERIALIZE_BOOL(TemplateTypeParmType, is_parameter_pack, getVal308, setVal308, initVal308, IsParameterPack, bool, NthType)
  MX_SERIALIZE_BOOL(TemplateTypeParmType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_TemplateTypeParmType
MX_END_SERIALIZE_TYPE(TemplateTypeParmType)
#undef MX_ENTER_SERIALIZE_TemplateTypeParmType
#undef MX_EXIT_SERIALIZE_TemplateTypeParmType

#ifndef MX_ENTER_SERIALIZE_TemplateSpecializationType
#  define MX_ENTER_SERIALIZE_TemplateSpecializationType
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateSpecializationType
#  define MX_EXIT_SERIALIZE_TemplateSpecializationType
#endif

MX_BEGIN_SERIALIZE_TYPE(TemplateSpecializationType)
  MX_ENTER_SERIALIZE_TemplateSpecializationType
  MX_SERIALIZE_BASE(TemplateSpecializationType, Type)
  MX_SERIALIZE_ENTITY(TemplateSpecializationType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(TemplateSpecializationType, aliased_type, getVal307, setVal307, initVal307, AliasedType, Type, NthType)
  MX_SERIALIZE_BOOL(TemplateSpecializationType, is_current_instantiation, getVal308, setVal308, initVal308, IsCurrentInstantiation, bool, NthType)
  MX_SERIALIZE_BOOL(TemplateSpecializationType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(TemplateSpecializationType, is_type_alias, getVal310, setVal310, initVal310, IsTypeAlias, bool, NthType)
  MX_SERIALIZE_PSEUDO_LIST(TemplateSpecializationType, template_arguments, getVal311, setVal311, initVal311, TemplateArguments, TemplateArgument, NthType)
  MX_EXIT_SERIALIZE_TemplateSpecializationType
MX_END_SERIALIZE_TYPE(TemplateSpecializationType)
#undef MX_ENTER_SERIALIZE_TemplateSpecializationType
#undef MX_EXIT_SERIALIZE_TemplateSpecializationType

#ifndef MX_ENTER_SERIALIZE_TagType
#  define MX_ENTER_SERIALIZE_TagType
#endif
#ifndef MX_EXIT_SERIALIZE_TagType
#  define MX_EXIT_SERIALIZE_TagType
#endif

MX_BEGIN_SERIALIZE_TYPE(TagType)
  MX_ENTER_SERIALIZE_TagType
  MX_SERIALIZE_BASE(TagType, Type)
  MX_SERIALIZE_ENTITY(TagType, declaration, getVal306, setVal306, initVal306, Declaration, TagDecl, NthType)
  MX_SERIALIZE_BOOL(TagType, is_being_defined, getVal308, setVal308, initVal308, IsBeingDefined, bool, NthType)
  MX_EXIT_SERIALIZE_TagType
MX_END_SERIALIZE_TYPE(TagType)
#undef MX_ENTER_SERIALIZE_TagType
#undef MX_EXIT_SERIALIZE_TagType

#ifndef MX_ENTER_SERIALIZE_RecordType
#  define MX_ENTER_SERIALIZE_RecordType
#endif
#ifndef MX_EXIT_SERIALIZE_RecordType
#  define MX_EXIT_SERIALIZE_RecordType
#endif

MX_BEGIN_SERIALIZE_TYPE(RecordType)
  MX_ENTER_SERIALIZE_RecordType
  MX_SERIALIZE_BASE(RecordType, TagType)
  MX_SERIALIZE_ENTITY(RecordType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(RecordType, has_const_fields, getVal309, setVal309, initVal309, HasConstFields, bool, NthType)
  MX_SERIALIZE_BOOL(RecordType, is_sugared, getVal310, setVal310, initVal310, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_RecordType
MX_END_SERIALIZE_TYPE(RecordType)
#undef MX_ENTER_SERIALIZE_RecordType
#undef MX_EXIT_SERIALIZE_RecordType

#ifndef MX_ENTER_SERIALIZE_EnumType
#  define MX_ENTER_SERIALIZE_EnumType
#endif
#ifndef MX_EXIT_SERIALIZE_EnumType
#  define MX_EXIT_SERIALIZE_EnumType
#endif

MX_BEGIN_SERIALIZE_TYPE(EnumType)
  MX_ENTER_SERIALIZE_EnumType
  MX_SERIALIZE_BASE(EnumType, TagType)
  MX_SERIALIZE_ENTITY(EnumType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(EnumType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_EnumType
MX_END_SERIALIZE_TYPE(EnumType)
#undef MX_ENTER_SERIALIZE_EnumType
#undef MX_EXIT_SERIALIZE_EnumType

#ifndef MX_ENTER_SERIALIZE_SubstTemplateTypeParmType
#  define MX_ENTER_SERIALIZE_SubstTemplateTypeParmType
#endif
#ifndef MX_EXIT_SERIALIZE_SubstTemplateTypeParmType
#  define MX_EXIT_SERIALIZE_SubstTemplateTypeParmType
#endif

MX_BEGIN_SERIALIZE_TYPE(SubstTemplateTypeParmType)
  MX_ENTER_SERIALIZE_SubstTemplateTypeParmType
  MX_SERIALIZE_BASE(SubstTemplateTypeParmType, Type)
  MX_SERIALIZE_ENTITY(SubstTemplateTypeParmType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(SubstTemplateTypeParmType, replaced_parameter, getVal307, setVal307, initVal307, ReplacedParameter, TemplateTypeParmType, NthType)
  MX_SERIALIZE_ENTITY(SubstTemplateTypeParmType, replacement_type, getVal312, setVal312, initVal312, ReplacementType, Type, NthType)
  MX_SERIALIZE_BOOL(SubstTemplateTypeParmType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_SubstTemplateTypeParmType
MX_END_SERIALIZE_TYPE(SubstTemplateTypeParmType)
#undef MX_ENTER_SERIALIZE_SubstTemplateTypeParmType
#undef MX_EXIT_SERIALIZE_SubstTemplateTypeParmType

#ifndef MX_ENTER_SERIALIZE_SubstTemplateTypeParmPackType
#  define MX_ENTER_SERIALIZE_SubstTemplateTypeParmPackType
#endif
#ifndef MX_EXIT_SERIALIZE_SubstTemplateTypeParmPackType
#  define MX_EXIT_SERIALIZE_SubstTemplateTypeParmPackType
#endif

MX_BEGIN_SERIALIZE_TYPE(SubstTemplateTypeParmPackType)
  MX_ENTER_SERIALIZE_SubstTemplateTypeParmPackType
  MX_SERIALIZE_BASE(SubstTemplateTypeParmPackType, Type)
  MX_SERIALIZE_ENTITY(SubstTemplateTypeParmPackType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(SubstTemplateTypeParmPackType, replaced_parameter, getVal307, setVal307, initVal307, ReplacedParameter, TemplateTypeParmType, NthType)
  MX_SERIALIZE_BOOL(SubstTemplateTypeParmPackType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_SubstTemplateTypeParmPackType
MX_END_SERIALIZE_TYPE(SubstTemplateTypeParmPackType)
#undef MX_ENTER_SERIALIZE_SubstTemplateTypeParmPackType
#undef MX_EXIT_SERIALIZE_SubstTemplateTypeParmPackType

#ifndef MX_ENTER_SERIALIZE_ReferenceType
#  define MX_ENTER_SERIALIZE_ReferenceType
#endif
#ifndef MX_EXIT_SERIALIZE_ReferenceType
#  define MX_EXIT_SERIALIZE_ReferenceType
#endif

MX_BEGIN_SERIALIZE_TYPE(ReferenceType)
  MX_ENTER_SERIALIZE_ReferenceType
  MX_SERIALIZE_BASE(ReferenceType, Type)
  MX_SERIALIZE_ENTITY(ReferenceType, pointee_type_as_written, getVal306, setVal306, initVal306, PointeeTypeAsWritten, Type, NthType)
  MX_SERIALIZE_BOOL(ReferenceType, is_inner_reference, getVal308, setVal308, initVal308, IsInnerReference, bool, NthType)
  MX_SERIALIZE_BOOL(ReferenceType, is_spelled_as_l_value, getVal309, setVal309, initVal309, IsSpelledAsLValue, bool, NthType)
  MX_EXIT_SERIALIZE_ReferenceType
MX_END_SERIALIZE_TYPE(ReferenceType)
#undef MX_ENTER_SERIALIZE_ReferenceType
#undef MX_EXIT_SERIALIZE_ReferenceType

#ifndef MX_ENTER_SERIALIZE_RValueReferenceType
#  define MX_ENTER_SERIALIZE_RValueReferenceType
#endif
#ifndef MX_EXIT_SERIALIZE_RValueReferenceType
#  define MX_EXIT_SERIALIZE_RValueReferenceType
#endif

MX_BEGIN_SERIALIZE_TYPE(RValueReferenceType)
  MX_ENTER_SERIALIZE_RValueReferenceType
  MX_SERIALIZE_BASE(RValueReferenceType, ReferenceType)
  MX_SERIALIZE_ENTITY(RValueReferenceType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(RValueReferenceType, is_sugared, getVal310, setVal310, initVal310, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_RValueReferenceType
MX_END_SERIALIZE_TYPE(RValueReferenceType)
#undef MX_ENTER_SERIALIZE_RValueReferenceType
#undef MX_EXIT_SERIALIZE_RValueReferenceType

#ifndef MX_ENTER_SERIALIZE_LValueReferenceType
#  define MX_ENTER_SERIALIZE_LValueReferenceType
#endif
#ifndef MX_EXIT_SERIALIZE_LValueReferenceType
#  define MX_EXIT_SERIALIZE_LValueReferenceType
#endif

MX_BEGIN_SERIALIZE_TYPE(LValueReferenceType)
  MX_ENTER_SERIALIZE_LValueReferenceType
  MX_SERIALIZE_BASE(LValueReferenceType, ReferenceType)
  MX_SERIALIZE_ENTITY(LValueReferenceType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(LValueReferenceType, is_sugared, getVal310, setVal310, initVal310, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_LValueReferenceType
MX_END_SERIALIZE_TYPE(LValueReferenceType)
#undef MX_ENTER_SERIALIZE_LValueReferenceType
#undef MX_EXIT_SERIALIZE_LValueReferenceType

#ifndef MX_ENTER_SERIALIZE_PointerType
#  define MX_ENTER_SERIALIZE_PointerType
#endif
#ifndef MX_EXIT_SERIALIZE_PointerType
#  define MX_EXIT_SERIALIZE_PointerType
#endif

MX_BEGIN_SERIALIZE_TYPE(PointerType)
  MX_ENTER_SERIALIZE_PointerType
  MX_SERIALIZE_BASE(PointerType, Type)
  MX_SERIALIZE_ENTITY(PointerType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(PointerType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_PointerType
MX_END_SERIALIZE_TYPE(PointerType)
#undef MX_ENTER_SERIALIZE_PointerType
#undef MX_EXIT_SERIALIZE_PointerType

#ifndef MX_ENTER_SERIALIZE_PipeType
#  define MX_ENTER_SERIALIZE_PipeType
#endif
#ifndef MX_EXIT_SERIALIZE_PipeType
#  define MX_EXIT_SERIALIZE_PipeType
#endif

MX_BEGIN_SERIALIZE_TYPE(PipeType)
  MX_ENTER_SERIALIZE_PipeType
  MX_SERIALIZE_BASE(PipeType, Type)
  MX_SERIALIZE_ENTITY(PipeType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(PipeType, element_type, getVal307, setVal307, initVal307, ElementType, Type, NthType)
  MX_SERIALIZE_BOOL(PipeType, is_read_only, getVal308, setVal308, initVal308, IsReadOnly, bool, NthType)
  MX_SERIALIZE_BOOL(PipeType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_PipeType
MX_END_SERIALIZE_TYPE(PipeType)
#undef MX_ENTER_SERIALIZE_PipeType
#undef MX_EXIT_SERIALIZE_PipeType

#ifndef MX_ENTER_SERIALIZE_ParenType
#  define MX_ENTER_SERIALIZE_ParenType
#endif
#ifndef MX_EXIT_SERIALIZE_ParenType
#  define MX_EXIT_SERIALIZE_ParenType
#endif

MX_BEGIN_SERIALIZE_TYPE(ParenType)
  MX_ENTER_SERIALIZE_ParenType
  MX_SERIALIZE_BASE(ParenType, Type)
  MX_SERIALIZE_ENTITY(ParenType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(ParenType, inner_type, getVal307, setVal307, initVal307, InnerType, Type, NthType)
  MX_SERIALIZE_BOOL(ParenType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_ParenType
MX_END_SERIALIZE_TYPE(ParenType)
#undef MX_ENTER_SERIALIZE_ParenType
#undef MX_EXIT_SERIALIZE_ParenType

#ifndef MX_ENTER_SERIALIZE_PackExpansionType
#  define MX_ENTER_SERIALIZE_PackExpansionType
#endif
#ifndef MX_EXIT_SERIALIZE_PackExpansionType
#  define MX_EXIT_SERIALIZE_PackExpansionType
#endif

MX_BEGIN_SERIALIZE_TYPE(PackExpansionType)
  MX_ENTER_SERIALIZE_PackExpansionType
  MX_SERIALIZE_BASE(PackExpansionType, Type)
  MX_SERIALIZE_ENTITY(PackExpansionType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_OPTIONAL_INT(PackExpansionType, num_expansions, getVal313, setVal313, initVal313, NumExpansions, unsigned, NthType)
  MX_SERIALIZE_ENTITY(PackExpansionType, pattern, getVal307, setVal307, initVal307, Pattern, Type, NthType)
  MX_SERIALIZE_BOOL(PackExpansionType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_PackExpansionType
MX_END_SERIALIZE_TYPE(PackExpansionType)
#undef MX_ENTER_SERIALIZE_PackExpansionType
#undef MX_EXIT_SERIALIZE_PackExpansionType

#ifndef MX_ENTER_SERIALIZE_ObjCTypeParamType
#  define MX_ENTER_SERIALIZE_ObjCTypeParamType
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCTypeParamType
#  define MX_EXIT_SERIALIZE_ObjCTypeParamType
#endif

MX_BEGIN_SERIALIZE_TYPE(ObjCTypeParamType)
  MX_ENTER_SERIALIZE_ObjCTypeParamType
  MX_SERIALIZE_BASE(ObjCTypeParamType, Type)
  MX_SERIALIZE_ENTITY(ObjCTypeParamType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(ObjCTypeParamType, declaration, getVal307, setVal307, initVal307, Declaration, ObjCTypeParamDecl, NthType)
  MX_SERIALIZE_BOOL(ObjCTypeParamType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_ObjCTypeParamType
MX_END_SERIALIZE_TYPE(ObjCTypeParamType)
#undef MX_ENTER_SERIALIZE_ObjCTypeParamType
#undef MX_EXIT_SERIALIZE_ObjCTypeParamType

#ifndef MX_ENTER_SERIALIZE_ObjCObjectType
#  define MX_ENTER_SERIALIZE_ObjCObjectType
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCObjectType
#  define MX_EXIT_SERIALIZE_ObjCObjectType
#endif

MX_BEGIN_SERIALIZE_TYPE(ObjCObjectType)
  MX_ENTER_SERIALIZE_ObjCObjectType
  MX_SERIALIZE_BASE(ObjCObjectType, Type)
  MX_SERIALIZE_ENTITY(ObjCObjectType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectType, base_type, getVal307, setVal307, initVal307, BaseType, Type, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectType, interface, getVal312, setVal312, initVal312, Interface, ObjCInterfaceDecl, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(ObjCObjectType, super_class_type, getVal314, setVal314, initVal314, SuperClassType, Type, NthType)
  MX_SERIALIZE_ENTITY_LIST(ObjCObjectType, type_arguments, getVal315, setVal315, initVal315, TypeArguments, Type, NthType)
  MX_SERIALIZE_ENTITY_LIST(ObjCObjectType, type_arguments_as_written, getVal316, setVal316, initVal316, TypeArgumentsAsWritten, Type, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_kind_of_type, getVal309, setVal309, initVal309, IsKindOfType, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_kind_of_type_as_written, getVal310, setVal310, initVal310, IsKindOfTypeAsWritten, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_class, getVal317, setVal317, initVal317, IsObjCClass, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_id, getVal318, setVal318, initVal318, IsObjCId, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_qualified_class, getVal319, setVal319, initVal319, IsObjCQualifiedClass, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_qualified_id, getVal320, setVal320, initVal320, IsObjCQualifiedId, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_unqualified_class, getVal321, setVal321, initVal321, IsObjCUnqualifiedClass, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_unqualified_id, getVal322, setVal322, initVal322, IsObjCUnqualifiedId, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_obj_c_unqualified_id_or_class, getVal323, setVal323, initVal323, IsObjCUnqualifiedIdOrClass, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_specialized, getVal324, setVal324, initVal324, IsSpecialized, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_specialized_as_written, getVal325, setVal325, initVal325, IsSpecializedAsWritten, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_sugared, getVal326, setVal326, initVal326, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_unspecialized, getVal327, setVal327, initVal327, IsUnspecialized, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectType, is_unspecialized_as_written, getVal328, setVal328, initVal328, IsUnspecializedAsWritten, bool, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectType, strip_obj_c_kind_of_type_and_qualifieds, getVal329, setVal329, initVal329, StripObjCKindOfTypeAndQualifieds, Type, NthType)
  MX_EXIT_SERIALIZE_ObjCObjectType
MX_END_SERIALIZE_TYPE(ObjCObjectType)
#undef MX_ENTER_SERIALIZE_ObjCObjectType
#undef MX_EXIT_SERIALIZE_ObjCObjectType

#ifndef MX_ENTER_SERIALIZE_ObjCInterfaceType
#  define MX_ENTER_SERIALIZE_ObjCInterfaceType
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCInterfaceType
#  define MX_EXIT_SERIALIZE_ObjCInterfaceType
#endif

MX_BEGIN_SERIALIZE_TYPE(ObjCInterfaceType)
  MX_ENTER_SERIALIZE_ObjCInterfaceType
  MX_SERIALIZE_BASE(ObjCInterfaceType, ObjCObjectType)
  MX_SERIALIZE_ENTITY(ObjCInterfaceType, declaration, getVal330, setVal330, initVal330, Declaration, ObjCInterfaceDecl, NthType)
  MX_EXIT_SERIALIZE_ObjCInterfaceType
MX_END_SERIALIZE_TYPE(ObjCInterfaceType)
#undef MX_ENTER_SERIALIZE_ObjCInterfaceType
#undef MX_EXIT_SERIALIZE_ObjCInterfaceType

#ifndef MX_ENTER_SERIALIZE_ObjCObjectPointerType
#  define MX_ENTER_SERIALIZE_ObjCObjectPointerType
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCObjectPointerType
#  define MX_EXIT_SERIALIZE_ObjCObjectPointerType
#endif

MX_BEGIN_SERIALIZE_TYPE(ObjCObjectPointerType)
  MX_ENTER_SERIALIZE_ObjCObjectPointerType
  MX_SERIALIZE_BASE(ObjCObjectPointerType, Type)
  MX_SERIALIZE_ENTITY(ObjCObjectPointerType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectPointerType, interface_declaration, getVal307, setVal307, initVal307, InterfaceDeclaration, ObjCInterfaceDecl, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectPointerType, interface_type, getVal312, setVal312, initVal312, InterfaceType, ObjCInterfaceType, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectPointerType, object_type, getVal314, setVal314, initVal314, ObjectType, ObjCObjectType, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectPointerType, super_class_type, getVal329, setVal329, initVal329, SuperClassType, Type, NthType)
  MX_SERIALIZE_ENTITY_LIST(ObjCObjectPointerType, type_arguments, getVal315, setVal315, initVal315, TypeArguments, Type, NthType)
  MX_SERIALIZE_ENTITY_LIST(ObjCObjectPointerType, type_arguments_as_written, getVal316, setVal316, initVal316, TypeArgumentsAsWritten, Type, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_kind_of_type, getVal308, setVal308, initVal308, IsKindOfType, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_obj_c_id_or_class_type, getVal309, setVal309, initVal309, IsObjCIdOrClassType, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_specialized, getVal310, setVal310, initVal310, IsSpecialized, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_specialized_as_written, getVal317, setVal317, initVal317, IsSpecializedAsWritten, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_sugared, getVal318, setVal318, initVal318, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_unspecialized, getVal319, setVal319, initVal319, IsUnspecialized, bool, NthType)
  MX_SERIALIZE_BOOL(ObjCObjectPointerType, is_unspecialized_as_written, getVal320, setVal320, initVal320, IsUnspecializedAsWritten, bool, NthType)
  MX_SERIALIZE_ENTITY_LIST(ObjCObjectPointerType, qualifieds, getVal331, setVal331, initVal331, Qualifieds, ObjCProtocolDecl, NthType)
  MX_SERIALIZE_ENTITY(ObjCObjectPointerType, strip_obj_c_kind_of_type_and_qualifieds, getVal330, setVal330, initVal330, StripObjCKindOfTypeAndQualifieds, ObjCObjectPointerType, NthType)
  MX_SERIALIZE_ENTITY_LIST(ObjCObjectPointerType, protocols, getVal332, setVal332, initVal332, Protocols, ObjCProtocolDecl, NthType)
  MX_EXIT_SERIALIZE_ObjCObjectPointerType
MX_END_SERIALIZE_TYPE(ObjCObjectPointerType)
#undef MX_ENTER_SERIALIZE_ObjCObjectPointerType
#undef MX_EXIT_SERIALIZE_ObjCObjectPointerType

#ifndef MX_ENTER_SERIALIZE_MemberPointerType
#  define MX_ENTER_SERIALIZE_MemberPointerType
#endif
#ifndef MX_EXIT_SERIALIZE_MemberPointerType
#  define MX_EXIT_SERIALIZE_MemberPointerType
#endif

MX_BEGIN_SERIALIZE_TYPE(MemberPointerType)
  MX_ENTER_SERIALIZE_MemberPointerType
  MX_SERIALIZE_BASE(MemberPointerType, Type)
  MX_SERIALIZE_ENTITY(MemberPointerType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(MemberPointerType, class_, getVal307, setVal307, initVal307, Class, Type, NthType)
  MX_SERIALIZE_ENTITY(MemberPointerType, most_recent_cxx_record_declaration, getVal312, setVal312, initVal312, MostRecentCXXRecordDeclaration, CXXRecordDecl, NthType)
  MX_SERIALIZE_BOOL(MemberPointerType, is_member_data_pointer, getVal308, setVal308, initVal308, IsMemberDataPointer, bool, NthType)
  MX_SERIALIZE_BOOL(MemberPointerType, is_member_function_pointer, getVal309, setVal309, initVal309, IsMemberFunctionPointer, bool, NthType)
  MX_SERIALIZE_BOOL(MemberPointerType, is_sugared, getVal310, setVal310, initVal310, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_MemberPointerType
MX_END_SERIALIZE_TYPE(MemberPointerType)
#undef MX_ENTER_SERIALIZE_MemberPointerType
#undef MX_EXIT_SERIALIZE_MemberPointerType

#ifndef MX_ENTER_SERIALIZE_MatrixType
#  define MX_ENTER_SERIALIZE_MatrixType
#endif
#ifndef MX_EXIT_SERIALIZE_MatrixType
#  define MX_EXIT_SERIALIZE_MatrixType
#endif

MX_BEGIN_SERIALIZE_TYPE(MatrixType)
  MX_ENTER_SERIALIZE_MatrixType
  MX_SERIALIZE_BASE(MatrixType, Type)
  MX_SERIALIZE_ENTITY(MatrixType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(MatrixType, element_type, getVal307, setVal307, initVal307, ElementType, Type, NthType)
  MX_SERIALIZE_BOOL(MatrixType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_MatrixType
MX_END_SERIALIZE_TYPE(MatrixType)
#undef MX_ENTER_SERIALIZE_MatrixType
#undef MX_EXIT_SERIALIZE_MatrixType

#ifndef MX_ENTER_SERIALIZE_DependentSizedMatrixType
#  define MX_ENTER_SERIALIZE_DependentSizedMatrixType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentSizedMatrixType
#  define MX_EXIT_SERIALIZE_DependentSizedMatrixType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentSizedMatrixType)
  MX_ENTER_SERIALIZE_DependentSizedMatrixType
  MX_SERIALIZE_BASE(DependentSizedMatrixType, MatrixType)
  MX_SERIALIZE_ENTITY(DependentSizedMatrixType, attribute_token, getVal312, setVal312, initVal312, AttributeToken, Token, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedMatrixType, column_expression, getVal314, setVal314, initVal314, ColumnExpression, Expr, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedMatrixType, row_expression, getVal329, setVal329, initVal329, RowExpression, Expr, NthType)
  MX_EXIT_SERIALIZE_DependentSizedMatrixType
MX_END_SERIALIZE_TYPE(DependentSizedMatrixType)
#undef MX_ENTER_SERIALIZE_DependentSizedMatrixType
#undef MX_EXIT_SERIALIZE_DependentSizedMatrixType

#ifndef MX_ENTER_SERIALIZE_ConstantMatrixType
#  define MX_ENTER_SERIALIZE_ConstantMatrixType
#endif
#ifndef MX_EXIT_SERIALIZE_ConstantMatrixType
#  define MX_EXIT_SERIALIZE_ConstantMatrixType
#endif

MX_BEGIN_SERIALIZE_TYPE(ConstantMatrixType)
  MX_ENTER_SERIALIZE_ConstantMatrixType
  MX_SERIALIZE_BASE(ConstantMatrixType, MatrixType)
  MX_EXIT_SERIALIZE_ConstantMatrixType
MX_END_SERIALIZE_TYPE(ConstantMatrixType)
#undef MX_ENTER_SERIALIZE_ConstantMatrixType
#undef MX_EXIT_SERIALIZE_ConstantMatrixType

#ifndef MX_ENTER_SERIALIZE_MacroQualifiedType
#  define MX_ENTER_SERIALIZE_MacroQualifiedType
#endif
#ifndef MX_EXIT_SERIALIZE_MacroQualifiedType
#  define MX_EXIT_SERIALIZE_MacroQualifiedType
#endif

MX_BEGIN_SERIALIZE_TYPE(MacroQualifiedType)
  MX_ENTER_SERIALIZE_MacroQualifiedType
  MX_SERIALIZE_BASE(MacroQualifiedType, Type)
  MX_SERIALIZE_ENTITY(MacroQualifiedType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(MacroQualifiedType, modified_type, getVal307, setVal307, initVal307, ModifiedType, Type, NthType)
  MX_SERIALIZE_ENTITY(MacroQualifiedType, underlying_type, getVal312, setVal312, initVal312, UnderlyingType, Type, NthType)
  MX_SERIALIZE_BOOL(MacroQualifiedType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_MacroQualifiedType
MX_END_SERIALIZE_TYPE(MacroQualifiedType)
#undef MX_ENTER_SERIALIZE_MacroQualifiedType
#undef MX_EXIT_SERIALIZE_MacroQualifiedType

#ifndef MX_ENTER_SERIALIZE_InjectedClassNameType
#  define MX_ENTER_SERIALIZE_InjectedClassNameType
#endif
#ifndef MX_EXIT_SERIALIZE_InjectedClassNameType
#  define MX_EXIT_SERIALIZE_InjectedClassNameType
#endif

MX_BEGIN_SERIALIZE_TYPE(InjectedClassNameType)
  MX_ENTER_SERIALIZE_InjectedClassNameType
  MX_SERIALIZE_BASE(InjectedClassNameType, Type)
  MX_SERIALIZE_ENTITY(InjectedClassNameType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(InjectedClassNameType, declaration, getVal307, setVal307, initVal307, Declaration, CXXRecordDecl, NthType)
  MX_SERIALIZE_ENTITY(InjectedClassNameType, injected_specialization_type, getVal312, setVal312, initVal312, InjectedSpecializationType, Type, NthType)
  MX_SERIALIZE_ENTITY(InjectedClassNameType, injected_tst, getVal314, setVal314, initVal314, InjectedTST, TemplateSpecializationType, NthType)
  MX_SERIALIZE_BOOL(InjectedClassNameType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_InjectedClassNameType
MX_END_SERIALIZE_TYPE(InjectedClassNameType)
#undef MX_ENTER_SERIALIZE_InjectedClassNameType
#undef MX_EXIT_SERIALIZE_InjectedClassNameType

#ifndef MX_ENTER_SERIALIZE_FunctionType
#  define MX_ENTER_SERIALIZE_FunctionType
#endif
#ifndef MX_EXIT_SERIALIZE_FunctionType
#  define MX_EXIT_SERIALIZE_FunctionType
#endif

MX_BEGIN_SERIALIZE_TYPE(FunctionType)
  MX_ENTER_SERIALIZE_FunctionType
  MX_SERIALIZE_BASE(FunctionType, Type)
  MX_SERIALIZE_ENUM(FunctionType, call_conv, getVal333, setVal333, initVal333, CallConv, CallingConv, NthType)
  MX_SERIALIZE_ENTITY(FunctionType, call_result_type, getVal306, setVal306, initVal306, CallResultType, Type, NthType)
  MX_SERIALIZE_BOOL(FunctionType, cmse_ns_call_attribute, getVal308, setVal308, initVal308, CmseNSCallAttribute, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionType, has_reg_parm, getVal309, setVal309, initVal309, HasRegParm, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionType, no_return_attribute, getVal310, setVal310, initVal310, NoReturnAttribute, bool, NthType)
  MX_SERIALIZE_ENTITY(FunctionType, return_type, getVal307, setVal307, initVal307, ReturnType, Type, NthType)
  MX_SERIALIZE_BOOL(FunctionType, is_const, getVal317, setVal317, initVal317, IsConst, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionType, is_restrict, getVal318, setVal318, initVal318, IsRestrict, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionType, is_volatile, getVal319, setVal319, initVal319, IsVolatile, bool, NthType)
  MX_EXIT_SERIALIZE_FunctionType
MX_END_SERIALIZE_TYPE(FunctionType)
#undef MX_ENTER_SERIALIZE_FunctionType
#undef MX_EXIT_SERIALIZE_FunctionType

#ifndef MX_ENTER_SERIALIZE_FunctionProtoType
#  define MX_ENTER_SERIALIZE_FunctionProtoType
#endif
#ifndef MX_EXIT_SERIALIZE_FunctionProtoType
#  define MX_EXIT_SERIALIZE_FunctionProtoType
#endif

MX_BEGIN_SERIALIZE_TYPE(FunctionProtoType)
  MX_ENTER_SERIALIZE_FunctionProtoType
  MX_SERIALIZE_BASE(FunctionProtoType, FunctionType)
  MX_SERIALIZE_ENUM(FunctionProtoType, can_throw, getVal334, setVal334, initVal334, CanThrow, CanThrowResult, NthType)
  MX_SERIALIZE_ENTITY(FunctionProtoType, desugar, getVal312, setVal312, initVal312, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY_LIST(FunctionProtoType, exceptions, getVal315, setVal315, initVal315, Exceptions, Type, NthType)
  MX_SERIALIZE_ENTITY(FunctionProtoType, ellipsis_token, getVal314, setVal314, initVal314, EllipsisToken, Token, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(FunctionProtoType, exception_spec_declaration, getVal329, setVal329, initVal329, ExceptionSpecDeclaration, FunctionDecl, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(FunctionProtoType, exception_spec_template, getVal330, setVal330, initVal330, ExceptionSpecTemplate, FunctionDecl, NthType)
  MX_SERIALIZE_ENUM(FunctionProtoType, exception_spec_type, getVal335, setVal335, initVal335, ExceptionSpecType, ExceptionSpecificationType, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(FunctionProtoType, noexcept_expression, getVal336, setVal336, initVal336, NoexceptExpression, Expr, NthType)
  MX_SERIALIZE_ENTITY_LIST(FunctionProtoType, parameter_types, getVal316, setVal316, initVal316, ParameterTypes, Type, NthType)
  MX_SERIALIZE_ENUM(FunctionProtoType, reference_qualifier, getVal337, setVal337, initVal337, ReferenceQualifier, RefQualifierKind, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_dependent_exception_spec, getVal323, setVal323, initVal323, HasDependentExceptionSpec, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_dynamic_exception_spec, getVal324, setVal324, initVal324, HasDynamicExceptionSpec, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_exception_spec, getVal325, setVal325, initVal325, HasExceptionSpec, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_ext_parameter_infos, getVal326, setVal326, initVal326, HasExtParameterInfos, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_instantiation_dependent_exception_spec, getVal327, setVal327, initVal327, HasInstantiationDependentExceptionSpec, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_noexcept_exception_spec, getVal328, setVal328, initVal328, HasNoexceptExceptionSpec, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, has_trailing_return, getVal338, setVal338, initVal338, HasTrailingReturn, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, is_nothrow, getVal339, setVal339, initVal339, IsNothrow, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, is_sugared, getVal340, setVal340, initVal340, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, is_template_variadic, getVal341, setVal341, initVal341, IsTemplateVariadic, bool, NthType)
  MX_SERIALIZE_BOOL(FunctionProtoType, is_variadic, getVal342, setVal342, initVal342, IsVariadic, bool, NthType)
  MX_SERIALIZE_ENTITY_LIST(FunctionProtoType, exception_types, getVal331, setVal331, initVal331, ExceptionTypes, Type, NthType)
  MX_EXIT_SERIALIZE_FunctionProtoType
MX_END_SERIALIZE_TYPE(FunctionProtoType)
#undef MX_ENTER_SERIALIZE_FunctionProtoType
#undef MX_EXIT_SERIALIZE_FunctionProtoType

#ifndef MX_ENTER_SERIALIZE_FunctionNoProtoType
#  define MX_ENTER_SERIALIZE_FunctionNoProtoType
#endif
#ifndef MX_EXIT_SERIALIZE_FunctionNoProtoType
#  define MX_EXIT_SERIALIZE_FunctionNoProtoType
#endif

MX_BEGIN_SERIALIZE_TYPE(FunctionNoProtoType)
  MX_ENTER_SERIALIZE_FunctionNoProtoType
  MX_SERIALIZE_BASE(FunctionNoProtoType, FunctionType)
  MX_SERIALIZE_ENTITY(FunctionNoProtoType, desugar, getVal312, setVal312, initVal312, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(FunctionNoProtoType, is_sugared, getVal320, setVal320, initVal320, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_FunctionNoProtoType
MX_END_SERIALIZE_TYPE(FunctionNoProtoType)
#undef MX_ENTER_SERIALIZE_FunctionNoProtoType
#undef MX_EXIT_SERIALIZE_FunctionNoProtoType

#ifndef MX_ENTER_SERIALIZE_ExtIntType
#  define MX_ENTER_SERIALIZE_ExtIntType
#endif
#ifndef MX_EXIT_SERIALIZE_ExtIntType
#  define MX_EXIT_SERIALIZE_ExtIntType
#endif

MX_BEGIN_SERIALIZE_TYPE(ExtIntType)
  MX_ENTER_SERIALIZE_ExtIntType
  MX_SERIALIZE_BASE(ExtIntType, Type)
  MX_SERIALIZE_ENTITY(ExtIntType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(ExtIntType, is_signed, getVal308, setVal308, initVal308, IsSigned, bool, NthType)
  MX_SERIALIZE_BOOL(ExtIntType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(ExtIntType, is_unsigned, getVal310, setVal310, initVal310, IsUnsigned, bool, NthType)
  MX_EXIT_SERIALIZE_ExtIntType
MX_END_SERIALIZE_TYPE(ExtIntType)
#undef MX_ENTER_SERIALIZE_ExtIntType
#undef MX_EXIT_SERIALIZE_ExtIntType

#ifndef MX_ENTER_SERIALIZE_DependentVectorType
#  define MX_ENTER_SERIALIZE_DependentVectorType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentVectorType
#  define MX_EXIT_SERIALIZE_DependentVectorType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentVectorType)
  MX_ENTER_SERIALIZE_DependentVectorType
  MX_SERIALIZE_BASE(DependentVectorType, Type)
  MX_SERIALIZE_ENTITY(DependentVectorType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentVectorType, attribute_token, getVal307, setVal307, initVal307, AttributeToken, Token, NthType)
  MX_SERIALIZE_ENTITY(DependentVectorType, element_type, getVal312, setVal312, initVal312, ElementType, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentVectorType, size_expression, getVal314, setVal314, initVal314, SizeExpression, Expr, NthType)
  MX_SERIALIZE_ENUM(DependentVectorType, vector_kind, getVal333, setVal333, initVal333, VectorKind, VectorTypeVectorKind, NthType)
  MX_SERIALIZE_BOOL(DependentVectorType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DependentVectorType
MX_END_SERIALIZE_TYPE(DependentVectorType)
#undef MX_ENTER_SERIALIZE_DependentVectorType
#undef MX_EXIT_SERIALIZE_DependentVectorType

#ifndef MX_ENTER_SERIALIZE_DependentSizedExtVectorType
#  define MX_ENTER_SERIALIZE_DependentSizedExtVectorType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentSizedExtVectorType
#  define MX_EXIT_SERIALIZE_DependentSizedExtVectorType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentSizedExtVectorType)
  MX_ENTER_SERIALIZE_DependentSizedExtVectorType
  MX_SERIALIZE_BASE(DependentSizedExtVectorType, Type)
  MX_SERIALIZE_ENTITY(DependentSizedExtVectorType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedExtVectorType, attribute_token, getVal307, setVal307, initVal307, AttributeToken, Token, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedExtVectorType, element_type, getVal312, setVal312, initVal312, ElementType, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedExtVectorType, size_expression, getVal314, setVal314, initVal314, SizeExpression, Expr, NthType)
  MX_SERIALIZE_BOOL(DependentSizedExtVectorType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DependentSizedExtVectorType
MX_END_SERIALIZE_TYPE(DependentSizedExtVectorType)
#undef MX_ENTER_SERIALIZE_DependentSizedExtVectorType
#undef MX_EXIT_SERIALIZE_DependentSizedExtVectorType

#ifndef MX_ENTER_SERIALIZE_DependentExtIntType
#  define MX_ENTER_SERIALIZE_DependentExtIntType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentExtIntType
#  define MX_EXIT_SERIALIZE_DependentExtIntType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentExtIntType)
  MX_ENTER_SERIALIZE_DependentExtIntType
  MX_SERIALIZE_BASE(DependentExtIntType, Type)
  MX_SERIALIZE_ENTITY(DependentExtIntType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentExtIntType, num_bits_expression, getVal307, setVal307, initVal307, NumBitsExpression, Expr, NthType)
  MX_SERIALIZE_BOOL(DependentExtIntType, is_signed, getVal308, setVal308, initVal308, IsSigned, bool, NthType)
  MX_SERIALIZE_BOOL(DependentExtIntType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(DependentExtIntType, is_unsigned, getVal310, setVal310, initVal310, IsUnsigned, bool, NthType)
  MX_EXIT_SERIALIZE_DependentExtIntType
MX_END_SERIALIZE_TYPE(DependentExtIntType)
#undef MX_ENTER_SERIALIZE_DependentExtIntType
#undef MX_EXIT_SERIALIZE_DependentExtIntType

#ifndef MX_ENTER_SERIALIZE_DependentAddressSpaceType
#  define MX_ENTER_SERIALIZE_DependentAddressSpaceType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentAddressSpaceType
#  define MX_EXIT_SERIALIZE_DependentAddressSpaceType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentAddressSpaceType)
  MX_ENTER_SERIALIZE_DependentAddressSpaceType
  MX_SERIALIZE_BASE(DependentAddressSpaceType, Type)
  MX_SERIALIZE_ENTITY(DependentAddressSpaceType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentAddressSpaceType, addr_space_expression, getVal307, setVal307, initVal307, AddrSpaceExpression, Expr, NthType)
  MX_SERIALIZE_ENTITY(DependentAddressSpaceType, attribute_token, getVal312, setVal312, initVal312, AttributeToken, Token, NthType)
  MX_SERIALIZE_BOOL(DependentAddressSpaceType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DependentAddressSpaceType
MX_END_SERIALIZE_TYPE(DependentAddressSpaceType)
#undef MX_ENTER_SERIALIZE_DependentAddressSpaceType
#undef MX_EXIT_SERIALIZE_DependentAddressSpaceType

#ifndef MX_ENTER_SERIALIZE_DeducedType
#  define MX_ENTER_SERIALIZE_DeducedType
#endif
#ifndef MX_EXIT_SERIALIZE_DeducedType
#  define MX_EXIT_SERIALIZE_DeducedType
#endif

MX_BEGIN_SERIALIZE_TYPE(DeducedType)
  MX_ENTER_SERIALIZE_DeducedType
  MX_SERIALIZE_BASE(DeducedType, Type)
  MX_SERIALIZE_ENTITY(DeducedType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DeducedType, resolved_type, getVal307, setVal307, initVal307, ResolvedType, Type, NthType)
  MX_SERIALIZE_BOOL(DeducedType, is_deduced, getVal308, setVal308, initVal308, IsDeduced, bool, NthType)
  MX_SERIALIZE_BOOL(DeducedType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DeducedType
MX_END_SERIALIZE_TYPE(DeducedType)
#undef MX_ENTER_SERIALIZE_DeducedType
#undef MX_EXIT_SERIALIZE_DeducedType

#ifndef MX_ENTER_SERIALIZE_DeducedTemplateSpecializationType
#  define MX_ENTER_SERIALIZE_DeducedTemplateSpecializationType
#endif
#ifndef MX_EXIT_SERIALIZE_DeducedTemplateSpecializationType
#  define MX_EXIT_SERIALIZE_DeducedTemplateSpecializationType
#endif

MX_BEGIN_SERIALIZE_TYPE(DeducedTemplateSpecializationType)
  MX_ENTER_SERIALIZE_DeducedTemplateSpecializationType
  MX_SERIALIZE_BASE(DeducedTemplateSpecializationType, DeducedType)
  MX_EXIT_SERIALIZE_DeducedTemplateSpecializationType
MX_END_SERIALIZE_TYPE(DeducedTemplateSpecializationType)
#undef MX_ENTER_SERIALIZE_DeducedTemplateSpecializationType
#undef MX_EXIT_SERIALIZE_DeducedTemplateSpecializationType

#ifndef MX_ENTER_SERIALIZE_AutoType
#  define MX_ENTER_SERIALIZE_AutoType
#endif
#ifndef MX_EXIT_SERIALIZE_AutoType
#  define MX_EXIT_SERIALIZE_AutoType
#endif

MX_BEGIN_SERIALIZE_TYPE(AutoType)
  MX_ENTER_SERIALIZE_AutoType
  MX_SERIALIZE_BASE(AutoType, DeducedType)
  MX_SERIALIZE_ENUM(AutoType, keyword, getVal333, setVal333, initVal333, Keyword, AutoTypeKeyword, NthType)
  MX_SERIALIZE_PSEUDO_LIST(AutoType, type_constraint_arguments, getVal311, setVal311, initVal311, TypeConstraintArguments, TemplateArgument, NthType)
  MX_SERIALIZE_ENTITY(AutoType, type_constraint_concept, getVal312, setVal312, initVal312, TypeConstraintConcept, ConceptDecl, NthType)
  MX_SERIALIZE_BOOL(AutoType, is_constrained, getVal310, setVal310, initVal310, IsConstrained, bool, NthType)
  MX_SERIALIZE_BOOL(AutoType, is_decltype_auto, getVal317, setVal317, initVal317, IsDecltypeAuto, bool, NthType)
  MX_EXIT_SERIALIZE_AutoType
MX_END_SERIALIZE_TYPE(AutoType)
#undef MX_ENTER_SERIALIZE_AutoType
#undef MX_EXIT_SERIALIZE_AutoType

#ifndef MX_ENTER_SERIALIZE_DecltypeType
#  define MX_ENTER_SERIALIZE_DecltypeType
#endif
#ifndef MX_EXIT_SERIALIZE_DecltypeType
#  define MX_EXIT_SERIALIZE_DecltypeType
#endif

MX_BEGIN_SERIALIZE_TYPE(DecltypeType)
  MX_ENTER_SERIALIZE_DecltypeType
  MX_SERIALIZE_BASE(DecltypeType, Type)
  MX_SERIALIZE_ENTITY(DecltypeType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DecltypeType, underlying_expression, getVal307, setVal307, initVal307, UnderlyingExpression, Expr, NthType)
  MX_SERIALIZE_ENTITY(DecltypeType, underlying_type, getVal312, setVal312, initVal312, UnderlyingType, Type, NthType)
  MX_SERIALIZE_BOOL(DecltypeType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DecltypeType
MX_END_SERIALIZE_TYPE(DecltypeType)
#undef MX_ENTER_SERIALIZE_DecltypeType
#undef MX_EXIT_SERIALIZE_DecltypeType

#ifndef MX_ENTER_SERIALIZE_ComplexType
#  define MX_ENTER_SERIALIZE_ComplexType
#endif
#ifndef MX_EXIT_SERIALIZE_ComplexType
#  define MX_EXIT_SERIALIZE_ComplexType
#endif

MX_BEGIN_SERIALIZE_TYPE(ComplexType)
  MX_ENTER_SERIALIZE_ComplexType
  MX_SERIALIZE_BASE(ComplexType, Type)
  MX_SERIALIZE_ENTITY(ComplexType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(ComplexType, element_type, getVal307, setVal307, initVal307, ElementType, Type, NthType)
  MX_SERIALIZE_BOOL(ComplexType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_ComplexType
MX_END_SERIALIZE_TYPE(ComplexType)
#undef MX_ENTER_SERIALIZE_ComplexType
#undef MX_EXIT_SERIALIZE_ComplexType

#ifndef MX_ENTER_SERIALIZE_BuiltinType
#  define MX_ENTER_SERIALIZE_BuiltinType
#endif
#ifndef MX_EXIT_SERIALIZE_BuiltinType
#  define MX_EXIT_SERIALIZE_BuiltinType
#endif

MX_BEGIN_SERIALIZE_TYPE(BuiltinType)
  MX_ENTER_SERIALIZE_BuiltinType
  MX_SERIALIZE_BASE(BuiltinType, Type)
  MX_SERIALIZE_ENTITY(BuiltinType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(BuiltinType, is_floating_point, getVal308, setVal308, initVal308, IsFloatingPoint, bool, NthType)
  MX_SERIALIZE_BOOL(BuiltinType, is_integer, getVal309, setVal309, initVal309, IsInteger, bool, NthType)
  MX_SERIALIZE_BOOL(BuiltinType, is_signed_integer, getVal310, setVal310, initVal310, IsSignedInteger, bool, NthType)
  MX_SERIALIZE_BOOL(BuiltinType, is_sugared, getVal317, setVal317, initVal317, IsSugared, bool, NthType)
  MX_SERIALIZE_BOOL(BuiltinType, is_unsigned_integer, getVal318, setVal318, initVal318, IsUnsignedInteger, bool, NthType)
  MX_EXIT_SERIALIZE_BuiltinType
MX_END_SERIALIZE_TYPE(BuiltinType)
#undef MX_ENTER_SERIALIZE_BuiltinType
#undef MX_EXIT_SERIALIZE_BuiltinType

#ifndef MX_ENTER_SERIALIZE_BlockPointerType
#  define MX_ENTER_SERIALIZE_BlockPointerType
#endif
#ifndef MX_EXIT_SERIALIZE_BlockPointerType
#  define MX_EXIT_SERIALIZE_BlockPointerType
#endif

MX_BEGIN_SERIALIZE_TYPE(BlockPointerType)
  MX_ENTER_SERIALIZE_BlockPointerType
  MX_SERIALIZE_BASE(BlockPointerType, Type)
  MX_SERIALIZE_ENTITY(BlockPointerType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(BlockPointerType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_BlockPointerType
MX_END_SERIALIZE_TYPE(BlockPointerType)
#undef MX_ENTER_SERIALIZE_BlockPointerType
#undef MX_EXIT_SERIALIZE_BlockPointerType

#ifndef MX_ENTER_SERIALIZE_AttributedType
#  define MX_ENTER_SERIALIZE_AttributedType
#endif
#ifndef MX_EXIT_SERIALIZE_AttributedType
#  define MX_EXIT_SERIALIZE_AttributedType
#endif

MX_BEGIN_SERIALIZE_TYPE(AttributedType)
  MX_ENTER_SERIALIZE_AttributedType
  MX_SERIALIZE_BASE(AttributedType, Type)
  MX_SERIALIZE_ENTITY(AttributedType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENUM(AttributedType, attribute_kind, getVal343, setVal343, initVal343, AttributeKind, AttributeKind, NthType)
  MX_SERIALIZE_ENTITY(AttributedType, equivalent_type, getVal307, setVal307, initVal307, EquivalentType, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENUM(AttributedType, immediate_nullability, getVal333, setVal333, initVal333, ImmediateNullability, NullabilityKind, NthType)
  MX_SERIALIZE_ENTITY(AttributedType, modified_type, getVal312, setVal312, initVal312, ModifiedType, Type, NthType)
  MX_SERIALIZE_BOOL(AttributedType, is_calling_conv, getVal309, setVal309, initVal309, IsCallingConv, bool, NthType)
  MX_SERIALIZE_BOOL(AttributedType, is_ms_type_spec, getVal310, setVal310, initVal310, IsMSTypeSpec, bool, NthType)
  MX_SERIALIZE_BOOL(AttributedType, is_qualifier, getVal317, setVal317, initVal317, IsQualifier, bool, NthType)
  MX_SERIALIZE_BOOL(AttributedType, is_sugared, getVal318, setVal318, initVal318, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_AttributedType
MX_END_SERIALIZE_TYPE(AttributedType)
#undef MX_ENTER_SERIALIZE_AttributedType
#undef MX_EXIT_SERIALIZE_AttributedType

#ifndef MX_ENTER_SERIALIZE_AtomicType
#  define MX_ENTER_SERIALIZE_AtomicType
#endif
#ifndef MX_EXIT_SERIALIZE_AtomicType
#  define MX_EXIT_SERIALIZE_AtomicType
#endif

MX_BEGIN_SERIALIZE_TYPE(AtomicType)
  MX_ENTER_SERIALIZE_AtomicType
  MX_SERIALIZE_BASE(AtomicType, Type)
  MX_SERIALIZE_ENTITY(AtomicType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(AtomicType, value_type, getVal307, setVal307, initVal307, ValueType, Type, NthType)
  MX_SERIALIZE_BOOL(AtomicType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_AtomicType
MX_END_SERIALIZE_TYPE(AtomicType)
#undef MX_ENTER_SERIALIZE_AtomicType
#undef MX_EXIT_SERIALIZE_AtomicType

#ifndef MX_ENTER_SERIALIZE_ArrayType
#  define MX_ENTER_SERIALIZE_ArrayType
#endif
#ifndef MX_EXIT_SERIALIZE_ArrayType
#  define MX_EXIT_SERIALIZE_ArrayType
#endif

MX_BEGIN_SERIALIZE_TYPE(ArrayType)
  MX_ENTER_SERIALIZE_ArrayType
  MX_SERIALIZE_BASE(ArrayType, Type)
  MX_SERIALIZE_ENTITY(ArrayType, element_type, getVal306, setVal306, initVal306, ElementType, Type, NthType)
  MX_SERIALIZE_ENUM(ArrayType, size_modifier, getVal333, setVal333, initVal333, SizeModifier, ArrayTypeArraySizeModifier, NthType)
  MX_EXIT_SERIALIZE_ArrayType
MX_END_SERIALIZE_TYPE(ArrayType)
#undef MX_ENTER_SERIALIZE_ArrayType
#undef MX_EXIT_SERIALIZE_ArrayType

#ifndef MX_ENTER_SERIALIZE_VariableArrayType
#  define MX_ENTER_SERIALIZE_VariableArrayType
#endif
#ifndef MX_EXIT_SERIALIZE_VariableArrayType
#  define MX_EXIT_SERIALIZE_VariableArrayType
#endif

MX_BEGIN_SERIALIZE_TYPE(VariableArrayType)
  MX_ENTER_SERIALIZE_VariableArrayType
  MX_SERIALIZE_BASE(VariableArrayType, ArrayType)
  MX_SERIALIZE_ENTITY(VariableArrayType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(VariableArrayType, l_bracket_token, getVal329, setVal329, initVal329, LBracketToken, Token, NthType)
  MX_SERIALIZE_ENTITY(VariableArrayType, r_bracket_token, getVal330, setVal330, initVal330, RBracketToken, Token, NthType)
  MX_SERIALIZE_ENTITY(VariableArrayType, size_expression, getVal336, setVal336, initVal336, SizeExpression, Expr, NthType)
  MX_SERIALIZE_BOOL(VariableArrayType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_VariableArrayType
MX_END_SERIALIZE_TYPE(VariableArrayType)
#undef MX_ENTER_SERIALIZE_VariableArrayType
#undef MX_EXIT_SERIALIZE_VariableArrayType

#ifndef MX_ENTER_SERIALIZE_IncompleteArrayType
#  define MX_ENTER_SERIALIZE_IncompleteArrayType
#endif
#ifndef MX_EXIT_SERIALIZE_IncompleteArrayType
#  define MX_EXIT_SERIALIZE_IncompleteArrayType
#endif

MX_BEGIN_SERIALIZE_TYPE(IncompleteArrayType)
  MX_ENTER_SERIALIZE_IncompleteArrayType
  MX_SERIALIZE_BASE(IncompleteArrayType, ArrayType)
  MX_SERIALIZE_ENTITY(IncompleteArrayType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(IncompleteArrayType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_IncompleteArrayType
MX_END_SERIALIZE_TYPE(IncompleteArrayType)
#undef MX_ENTER_SERIALIZE_IncompleteArrayType
#undef MX_EXIT_SERIALIZE_IncompleteArrayType

#ifndef MX_ENTER_SERIALIZE_DependentSizedArrayType
#  define MX_ENTER_SERIALIZE_DependentSizedArrayType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentSizedArrayType
#  define MX_EXIT_SERIALIZE_DependentSizedArrayType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentSizedArrayType)
  MX_ENTER_SERIALIZE_DependentSizedArrayType
  MX_SERIALIZE_BASE(DependentSizedArrayType, ArrayType)
  MX_SERIALIZE_ENTITY(DependentSizedArrayType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedArrayType, l_bracket_token, getVal329, setVal329, initVal329, LBracketToken, Token, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedArrayType, r_bracket_token, getVal330, setVal330, initVal330, RBracketToken, Token, NthType)
  MX_SERIALIZE_ENTITY(DependentSizedArrayType, size_expression, getVal336, setVal336, initVal336, SizeExpression, Expr, NthType)
  MX_SERIALIZE_BOOL(DependentSizedArrayType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DependentSizedArrayType
MX_END_SERIALIZE_TYPE(DependentSizedArrayType)
#undef MX_ENTER_SERIALIZE_DependentSizedArrayType
#undef MX_EXIT_SERIALIZE_DependentSizedArrayType

#ifndef MX_ENTER_SERIALIZE_ConstantArrayType
#  define MX_ENTER_SERIALIZE_ConstantArrayType
#endif
#ifndef MX_EXIT_SERIALIZE_ConstantArrayType
#  define MX_EXIT_SERIALIZE_ConstantArrayType
#endif

MX_BEGIN_SERIALIZE_TYPE(ConstantArrayType)
  MX_ENTER_SERIALIZE_ConstantArrayType
  MX_SERIALIZE_BASE(ConstantArrayType, ArrayType)
  MX_SERIALIZE_ENTITY(ConstantArrayType, desugar, getVal307, setVal307, initVal307, Desugar, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(ConstantArrayType, size_expression, getVal312, setVal312, initVal312, SizeExpression, Expr, NthType)
  MX_SERIALIZE_BOOL(ConstantArrayType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_ConstantArrayType
MX_END_SERIALIZE_TYPE(ConstantArrayType)
#undef MX_ENTER_SERIALIZE_ConstantArrayType
#undef MX_EXIT_SERIALIZE_ConstantArrayType

#ifndef MX_ENTER_SERIALIZE_AdjustedType
#  define MX_ENTER_SERIALIZE_AdjustedType
#endif
#ifndef MX_EXIT_SERIALIZE_AdjustedType
#  define MX_EXIT_SERIALIZE_AdjustedType
#endif

MX_BEGIN_SERIALIZE_TYPE(AdjustedType)
  MX_ENTER_SERIALIZE_AdjustedType
  MX_SERIALIZE_BASE(AdjustedType, Type)
  MX_SERIALIZE_ENTITY(AdjustedType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(AdjustedType, resolved_type, getVal307, setVal307, initVal307, ResolvedType, Type, NthType)
  MX_SERIALIZE_ENTITY(AdjustedType, original_type, getVal312, setVal312, initVal312, OriginalType, Type, NthType)
  MX_SERIALIZE_BOOL(AdjustedType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_AdjustedType
MX_END_SERIALIZE_TYPE(AdjustedType)
#undef MX_ENTER_SERIALIZE_AdjustedType
#undef MX_EXIT_SERIALIZE_AdjustedType

#ifndef MX_ENTER_SERIALIZE_DecayedType
#  define MX_ENTER_SERIALIZE_DecayedType
#endif
#ifndef MX_EXIT_SERIALIZE_DecayedType
#  define MX_EXIT_SERIALIZE_DecayedType
#endif

MX_BEGIN_SERIALIZE_TYPE(DecayedType)
  MX_ENTER_SERIALIZE_DecayedType
  MX_SERIALIZE_BASE(DecayedType, AdjustedType)
  MX_EXIT_SERIALIZE_DecayedType
MX_END_SERIALIZE_TYPE(DecayedType)
#undef MX_ENTER_SERIALIZE_DecayedType
#undef MX_EXIT_SERIALIZE_DecayedType

#ifndef MX_ENTER_SERIALIZE_TypeWithKeyword
#  define MX_ENTER_SERIALIZE_TypeWithKeyword
#endif
#ifndef MX_EXIT_SERIALIZE_TypeWithKeyword
#  define MX_EXIT_SERIALIZE_TypeWithKeyword
#endif

MX_BEGIN_SERIALIZE_TYPE(TypeWithKeyword)
  MX_ENTER_SERIALIZE_TypeWithKeyword
  MX_SERIALIZE_BASE(TypeWithKeyword, Type)
  MX_SERIALIZE_ENUM(TypeWithKeyword, keyword, getVal333, setVal333, initVal333, Keyword, ElaboratedTypeKeyword, NthType)
  MX_EXIT_SERIALIZE_TypeWithKeyword
MX_END_SERIALIZE_TYPE(TypeWithKeyword)
#undef MX_ENTER_SERIALIZE_TypeWithKeyword
#undef MX_EXIT_SERIALIZE_TypeWithKeyword

#ifndef MX_ENTER_SERIALIZE_ElaboratedType
#  define MX_ENTER_SERIALIZE_ElaboratedType
#endif
#ifndef MX_EXIT_SERIALIZE_ElaboratedType
#  define MX_EXIT_SERIALIZE_ElaboratedType
#endif

MX_BEGIN_SERIALIZE_TYPE(ElaboratedType)
  MX_ENTER_SERIALIZE_ElaboratedType
  MX_SERIALIZE_BASE(ElaboratedType, TypeWithKeyword)
  MX_SERIALIZE_ENTITY(ElaboratedType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(ElaboratedType, named_type, getVal307, setVal307, initVal307, NamedType, Type, NthType)
  MX_SERIALIZE_OPTIONAL_ENTITY(ElaboratedType, owned_tag_declaration, getVal312, setVal312, initVal312, OwnedTagDeclaration, TagDecl, NthType)
  MX_SERIALIZE_BOOL(ElaboratedType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_ElaboratedType
MX_END_SERIALIZE_TYPE(ElaboratedType)
#undef MX_ENTER_SERIALIZE_ElaboratedType
#undef MX_EXIT_SERIALIZE_ElaboratedType

#ifndef MX_ENTER_SERIALIZE_DependentTemplateSpecializationType
#  define MX_ENTER_SERIALIZE_DependentTemplateSpecializationType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentTemplateSpecializationType
#  define MX_EXIT_SERIALIZE_DependentTemplateSpecializationType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentTemplateSpecializationType)
  MX_ENTER_SERIALIZE_DependentTemplateSpecializationType
  MX_SERIALIZE_BASE(DependentTemplateSpecializationType, TypeWithKeyword)
  MX_SERIALIZE_ENTITY(DependentTemplateSpecializationType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(DependentTemplateSpecializationType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_SERIALIZE_PSEUDO_LIST(DependentTemplateSpecializationType, template_arguments, getVal311, setVal311, initVal311, TemplateArguments, TemplateArgument, NthType)
  MX_EXIT_SERIALIZE_DependentTemplateSpecializationType
MX_END_SERIALIZE_TYPE(DependentTemplateSpecializationType)
#undef MX_ENTER_SERIALIZE_DependentTemplateSpecializationType
#undef MX_EXIT_SERIALIZE_DependentTemplateSpecializationType

#ifndef MX_ENTER_SERIALIZE_DependentNameType
#  define MX_ENTER_SERIALIZE_DependentNameType
#endif
#ifndef MX_EXIT_SERIALIZE_DependentNameType
#  define MX_EXIT_SERIALIZE_DependentNameType
#endif

MX_BEGIN_SERIALIZE_TYPE(DependentNameType)
  MX_ENTER_SERIALIZE_DependentNameType
  MX_SERIALIZE_BASE(DependentNameType, TypeWithKeyword)
  MX_SERIALIZE_ENTITY(DependentNameType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_BOOL(DependentNameType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_DependentNameType
MX_END_SERIALIZE_TYPE(DependentNameType)
#undef MX_ENTER_SERIALIZE_DependentNameType
#undef MX_EXIT_SERIALIZE_DependentNameType

#ifndef MX_ENTER_SERIALIZE_VectorType
#  define MX_ENTER_SERIALIZE_VectorType
#endif
#ifndef MX_EXIT_SERIALIZE_VectorType
#  define MX_EXIT_SERIALIZE_VectorType
#endif

MX_BEGIN_SERIALIZE_TYPE(VectorType)
  MX_ENTER_SERIALIZE_VectorType
  MX_SERIALIZE_BASE(VectorType, Type)
  MX_SERIALIZE_ENTITY(VectorType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(VectorType, element_type, getVal307, setVal307, initVal307, ElementType, Type, NthType)
  MX_SERIALIZE_ENUM(VectorType, vector_kind, getVal333, setVal333, initVal333, VectorKind, VectorTypeVectorKind, NthType)
  MX_SERIALIZE_BOOL(VectorType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_VectorType
MX_END_SERIALIZE_TYPE(VectorType)
#undef MX_ENTER_SERIALIZE_VectorType
#undef MX_EXIT_SERIALIZE_VectorType

#ifndef MX_ENTER_SERIALIZE_ExtVectorType
#  define MX_ENTER_SERIALIZE_ExtVectorType
#endif
#ifndef MX_EXIT_SERIALIZE_ExtVectorType
#  define MX_EXIT_SERIALIZE_ExtVectorType
#endif

MX_BEGIN_SERIALIZE_TYPE(ExtVectorType)
  MX_ENTER_SERIALIZE_ExtVectorType
  MX_SERIALIZE_BASE(ExtVectorType, VectorType)
  MX_EXIT_SERIALIZE_ExtVectorType
MX_END_SERIALIZE_TYPE(ExtVectorType)
#undef MX_ENTER_SERIALIZE_ExtVectorType
#undef MX_EXIT_SERIALIZE_ExtVectorType

#ifndef MX_ENTER_SERIALIZE_UnresolvedUsingType
#  define MX_ENTER_SERIALIZE_UnresolvedUsingType
#endif
#ifndef MX_EXIT_SERIALIZE_UnresolvedUsingType
#  define MX_EXIT_SERIALIZE_UnresolvedUsingType
#endif

MX_BEGIN_SERIALIZE_TYPE(UnresolvedUsingType)
  MX_ENTER_SERIALIZE_UnresolvedUsingType
  MX_SERIALIZE_BASE(UnresolvedUsingType, Type)
  MX_SERIALIZE_ENTITY(UnresolvedUsingType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(UnresolvedUsingType, declaration, getVal307, setVal307, initVal307, Declaration, UnresolvedUsingTypenameDecl, NthType)
  MX_SERIALIZE_BOOL(UnresolvedUsingType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_UnresolvedUsingType
MX_END_SERIALIZE_TYPE(UnresolvedUsingType)
#undef MX_ENTER_SERIALIZE_UnresolvedUsingType
#undef MX_EXIT_SERIALIZE_UnresolvedUsingType

#ifndef MX_ENTER_SERIALIZE_UnaryTransformType
#  define MX_ENTER_SERIALIZE_UnaryTransformType
#endif
#ifndef MX_EXIT_SERIALIZE_UnaryTransformType
#  define MX_EXIT_SERIALIZE_UnaryTransformType
#endif

MX_BEGIN_SERIALIZE_TYPE(UnaryTransformType)
  MX_ENTER_SERIALIZE_UnaryTransformType
  MX_SERIALIZE_BASE(UnaryTransformType, Type)
  MX_SERIALIZE_ENTITY(UnaryTransformType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(UnaryTransformType, base_type, getVal307, setVal307, initVal307, BaseType, Type, NthType)
  MX_SERIALIZE_ENUM(UnaryTransformType, utt_kind, getVal333, setVal333, initVal333, UTTKind, UnaryTransformTypeUTTKind, NthType)
  MX_SERIALIZE_ENTITY(UnaryTransformType, underlying_type, getVal312, setVal312, initVal312, UnderlyingType, Type, NthType)
  MX_SERIALIZE_BOOL(UnaryTransformType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_UnaryTransformType
MX_END_SERIALIZE_TYPE(UnaryTransformType)
#undef MX_ENTER_SERIALIZE_UnaryTransformType
#undef MX_EXIT_SERIALIZE_UnaryTransformType

#ifndef MX_ENTER_SERIALIZE_TypedefType
#  define MX_ENTER_SERIALIZE_TypedefType
#endif
#ifndef MX_EXIT_SERIALIZE_TypedefType
#  define MX_EXIT_SERIALIZE_TypedefType
#endif

MX_BEGIN_SERIALIZE_TYPE(TypedefType)
  MX_ENTER_SERIALIZE_TypedefType
  MX_SERIALIZE_BASE(TypedefType, Type)
  MX_SERIALIZE_ENTITY(TypedefType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(TypedefType, declaration, getVal307, setVal307, initVal307, Declaration, TypedefNameDecl, NthType)
  MX_SERIALIZE_BOOL(TypedefType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_TypedefType
MX_END_SERIALIZE_TYPE(TypedefType)
#undef MX_ENTER_SERIALIZE_TypedefType
#undef MX_EXIT_SERIALIZE_TypedefType

#ifndef MX_ENTER_SERIALIZE_TypeOfType
#  define MX_ENTER_SERIALIZE_TypeOfType
#endif
#ifndef MX_EXIT_SERIALIZE_TypeOfType
#  define MX_EXIT_SERIALIZE_TypeOfType
#endif

MX_BEGIN_SERIALIZE_TYPE(TypeOfType)
  MX_ENTER_SERIALIZE_TypeOfType
  MX_SERIALIZE_BASE(TypeOfType, Type)
  MX_SERIALIZE_ENTITY(TypeOfType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(TypeOfType, underlying_type, getVal307, setVal307, initVal307, UnderlyingType, Type, NthType)
  MX_SERIALIZE_BOOL(TypeOfType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_TypeOfType
MX_END_SERIALIZE_TYPE(TypeOfType)
#undef MX_ENTER_SERIALIZE_TypeOfType
#undef MX_EXIT_SERIALIZE_TypeOfType

#ifndef MX_ENTER_SERIALIZE_TypeOfExprType
#  define MX_ENTER_SERIALIZE_TypeOfExprType
#endif
#ifndef MX_EXIT_SERIALIZE_TypeOfExprType
#  define MX_EXIT_SERIALIZE_TypeOfExprType
#endif

MX_BEGIN_SERIALIZE_TYPE(TypeOfExprType)
  MX_ENTER_SERIALIZE_TypeOfExprType
  MX_SERIALIZE_BASE(TypeOfExprType, Type)
  MX_SERIALIZE_ENTITY(TypeOfExprType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType)
  MX_SERIALIZE_ENTITY(TypeOfExprType, underlying_expression, getVal307, setVal307, initVal307, UnderlyingExpression, Expr, NthType)
  MX_SERIALIZE_BOOL(TypeOfExprType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_EXIT_SERIALIZE_TypeOfExprType
MX_END_SERIALIZE_TYPE(TypeOfExprType)
#undef MX_ENTER_SERIALIZE_TypeOfExprType
#undef MX_EXIT_SERIALIZE_TypeOfExprType

#ifndef MX_ENTER_SERIALIZE_Stmt
#  define MX_ENTER_SERIALIZE_Stmt
#endif
#ifndef MX_EXIT_SERIALIZE_Stmt
#  define MX_EXIT_SERIALIZE_Stmt
#endif

MX_BEGIN_SERIALIZE_STMT(Stmt)
  MX_ENTER_SERIALIZE_Stmt
  MX_SERIALIZE_DECL_LINK(Stmt, parent_declaration, getVal0, setVal0, initVal0)
  MX_SERIALIZE_STMT_LINK(Stmt, parent_statement, getVal1, setVal1, initVal1)
  MX_SERIALIZE_ENTITY(Stmt, ignore_containers, getVal2, setVal2, initVal2, IgnoreContainers, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(Stmt, children, getVal3, setVal3, initVal3, Children, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(Stmt, begin_token, getVal4, setVal4, initVal4, BeginToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(Stmt, end_token, getVal5, setVal5, initVal5, EndToken, Token, NthStmt)
  MX_SERIALIZE_ENUM(Stmt, kind, getVal8, setVal8, initVal8, Kind, StmtKind, NthStmt)
  MX_SERIALIZE_ENTITY(Stmt, strip_label_like_statements, getVal9, setVal9, initVal9, StripLabelLikeStatements, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_Stmt
MX_END_SERIALIZE_STMT(Stmt)
#undef MX_ENTER_SERIALIZE_Stmt
#undef MX_EXIT_SERIALIZE_Stmt

#ifndef MX_ENTER_SERIALIZE_SEHTryStmt
#  define MX_ENTER_SERIALIZE_SEHTryStmt
#endif
#ifndef MX_EXIT_SERIALIZE_SEHTryStmt
#  define MX_EXIT_SERIALIZE_SEHTryStmt
#endif

MX_BEGIN_SERIALIZE_STMT(SEHTryStmt)
  MX_ENTER_SERIALIZE_SEHTryStmt
  MX_SERIALIZE_BASE(SEHTryStmt, Stmt)
  MX_SERIALIZE_ENTITY(SEHTryStmt, except_handler, getVal10, setVal10, initVal10, ExceptHandler, SEHExceptStmt, NthStmt)
  MX_SERIALIZE_ENTITY(SEHTryStmt, finally_handler, getVal11, setVal11, initVal11, FinallyHandler, SEHFinallyStmt, NthStmt)
  MX_SERIALIZE_ENTITY(SEHTryStmt, handler, getVal12, setVal12, initVal12, Handler, Stmt, NthStmt)
  MX_SERIALIZE_BOOL(SEHTryStmt, is_cxx_try, getVal13, setVal13, initVal13, IsCXXTry, bool, NthStmt)
  MX_SERIALIZE_ENTITY(SEHTryStmt, try_block, getVal14, setVal14, initVal14, TryBlock, CompoundStmt, NthStmt)
  MX_SERIALIZE_ENTITY(SEHTryStmt, try_token, getVal15, setVal15, initVal15, TryToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_SEHTryStmt
MX_END_SERIALIZE_STMT(SEHTryStmt)
#undef MX_ENTER_SERIALIZE_SEHTryStmt
#undef MX_EXIT_SERIALIZE_SEHTryStmt

#ifndef MX_ENTER_SERIALIZE_SEHLeaveStmt
#  define MX_ENTER_SERIALIZE_SEHLeaveStmt
#endif
#ifndef MX_EXIT_SERIALIZE_SEHLeaveStmt
#  define MX_EXIT_SERIALIZE_SEHLeaveStmt
#endif

MX_BEGIN_SERIALIZE_STMT(SEHLeaveStmt)
  MX_ENTER_SERIALIZE_SEHLeaveStmt
  MX_SERIALIZE_BASE(SEHLeaveStmt, Stmt)
  MX_SERIALIZE_ENTITY(SEHLeaveStmt, leave_token, getVal10, setVal10, initVal10, LeaveToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_SEHLeaveStmt
MX_END_SERIALIZE_STMT(SEHLeaveStmt)
#undef MX_ENTER_SERIALIZE_SEHLeaveStmt
#undef MX_EXIT_SERIALIZE_SEHLeaveStmt

#ifndef MX_ENTER_SERIALIZE_SEHFinallyStmt
#  define MX_ENTER_SERIALIZE_SEHFinallyStmt
#endif
#ifndef MX_EXIT_SERIALIZE_SEHFinallyStmt
#  define MX_EXIT_SERIALIZE_SEHFinallyStmt
#endif

MX_BEGIN_SERIALIZE_STMT(SEHFinallyStmt)
  MX_ENTER_SERIALIZE_SEHFinallyStmt
  MX_SERIALIZE_BASE(SEHFinallyStmt, Stmt)
  MX_SERIALIZE_ENTITY(SEHFinallyStmt, block, getVal10, setVal10, initVal10, Block, CompoundStmt, NthStmt)
  MX_SERIALIZE_ENTITY(SEHFinallyStmt, finally_token, getVal11, setVal11, initVal11, FinallyToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_SEHFinallyStmt
MX_END_SERIALIZE_STMT(SEHFinallyStmt)
#undef MX_ENTER_SERIALIZE_SEHFinallyStmt
#undef MX_EXIT_SERIALIZE_SEHFinallyStmt

#ifndef MX_ENTER_SERIALIZE_SEHExceptStmt
#  define MX_ENTER_SERIALIZE_SEHExceptStmt
#endif
#ifndef MX_EXIT_SERIALIZE_SEHExceptStmt
#  define MX_EXIT_SERIALIZE_SEHExceptStmt
#endif

MX_BEGIN_SERIALIZE_STMT(SEHExceptStmt)
  MX_ENTER_SERIALIZE_SEHExceptStmt
  MX_SERIALIZE_BASE(SEHExceptStmt, Stmt)
  MX_SERIALIZE_ENTITY(SEHExceptStmt, block, getVal10, setVal10, initVal10, Block, CompoundStmt, NthStmt)
  MX_SERIALIZE_ENTITY(SEHExceptStmt, except_token, getVal11, setVal11, initVal11, ExceptToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SEHExceptStmt, filter_expression, getVal12, setVal12, initVal12, FilterExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_SEHExceptStmt
MX_END_SERIALIZE_STMT(SEHExceptStmt)
#undef MX_ENTER_SERIALIZE_SEHExceptStmt
#undef MX_EXIT_SERIALIZE_SEHExceptStmt

#ifndef MX_ENTER_SERIALIZE_ReturnStmt
#  define MX_ENTER_SERIALIZE_ReturnStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ReturnStmt
#  define MX_EXIT_SERIALIZE_ReturnStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ReturnStmt)
  MX_ENTER_SERIALIZE_ReturnStmt
  MX_SERIALIZE_BASE(ReturnStmt, Stmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ReturnStmt, nrvo_candidate, getVal10, setVal10, initVal10, NRVOCandidate, VarDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ReturnStmt, return_value, getVal11, setVal11, initVal11, ReturnValue, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ReturnStmt, return_token, getVal12, setVal12, initVal12, ReturnToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ReturnStmt
MX_END_SERIALIZE_STMT(ReturnStmt)
#undef MX_ENTER_SERIALIZE_ReturnStmt
#undef MX_EXIT_SERIALIZE_ReturnStmt

#ifndef MX_ENTER_SERIALIZE_ObjCForCollectionStmt
#  define MX_ENTER_SERIALIZE_ObjCForCollectionStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCForCollectionStmt
#  define MX_EXIT_SERIALIZE_ObjCForCollectionStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCForCollectionStmt)
  MX_ENTER_SERIALIZE_ObjCForCollectionStmt
  MX_SERIALIZE_BASE(ObjCForCollectionStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCForCollectionStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCForCollectionStmt, collection, getVal11, setVal11, initVal11, Collection, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCForCollectionStmt, element, getVal12, setVal12, initVal12, Element, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCForCollectionStmt, for_token, getVal14, setVal14, initVal14, ForToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCForCollectionStmt, r_paren_token, getVal15, setVal15, initVal15, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCForCollectionStmt
MX_END_SERIALIZE_STMT(ObjCForCollectionStmt)
#undef MX_ENTER_SERIALIZE_ObjCForCollectionStmt
#undef MX_EXIT_SERIALIZE_ObjCForCollectionStmt

#ifndef MX_ENTER_SERIALIZE_ObjCAutoreleasePoolStmt
#  define MX_ENTER_SERIALIZE_ObjCAutoreleasePoolStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAutoreleasePoolStmt
#  define MX_EXIT_SERIALIZE_ObjCAutoreleasePoolStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAutoreleasePoolStmt)
  MX_ENTER_SERIALIZE_ObjCAutoreleasePoolStmt
  MX_SERIALIZE_BASE(ObjCAutoreleasePoolStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCAutoreleasePoolStmt, at_token, getVal10, setVal10, initVal10, AtToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAutoreleasePoolStmt, sub_statement, getVal11, setVal11, initVal11, SubStatement, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAutoreleasePoolStmt
MX_END_SERIALIZE_STMT(ObjCAutoreleasePoolStmt)
#undef MX_ENTER_SERIALIZE_ObjCAutoreleasePoolStmt
#undef MX_EXIT_SERIALIZE_ObjCAutoreleasePoolStmt

#ifndef MX_ENTER_SERIALIZE_ObjCAtTryStmt
#  define MX_ENTER_SERIALIZE_ObjCAtTryStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAtTryStmt
#  define MX_EXIT_SERIALIZE_ObjCAtTryStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAtTryStmt)
  MX_ENTER_SERIALIZE_ObjCAtTryStmt
  MX_SERIALIZE_BASE(ObjCAtTryStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCAtTryStmt, at_try_token, getVal10, setVal10, initVal10, AtTryToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtTryStmt, finally_statement, getVal11, setVal11, initVal11, FinallyStatement, ObjCAtFinallyStmt, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtTryStmt, try_body, getVal12, setVal12, initVal12, TryBody, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(ObjCAtTryStmt, catch_statements, getVal17, setVal17, initVal17, CatchStatements, ObjCAtCatchStmt, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAtTryStmt
MX_END_SERIALIZE_STMT(ObjCAtTryStmt)
#undef MX_ENTER_SERIALIZE_ObjCAtTryStmt
#undef MX_EXIT_SERIALIZE_ObjCAtTryStmt

#ifndef MX_ENTER_SERIALIZE_ObjCAtThrowStmt
#  define MX_ENTER_SERIALIZE_ObjCAtThrowStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAtThrowStmt
#  define MX_EXIT_SERIALIZE_ObjCAtThrowStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAtThrowStmt)
  MX_ENTER_SERIALIZE_ObjCAtThrowStmt
  MX_SERIALIZE_BASE(ObjCAtThrowStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCAtThrowStmt, throw_expression, getVal10, setVal10, initVal10, ThrowExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtThrowStmt, throw_token, getVal11, setVal11, initVal11, ThrowToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAtThrowStmt
MX_END_SERIALIZE_STMT(ObjCAtThrowStmt)
#undef MX_ENTER_SERIALIZE_ObjCAtThrowStmt
#undef MX_EXIT_SERIALIZE_ObjCAtThrowStmt

#ifndef MX_ENTER_SERIALIZE_ObjCAtSynchronizedStmt
#  define MX_ENTER_SERIALIZE_ObjCAtSynchronizedStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAtSynchronizedStmt
#  define MX_EXIT_SERIALIZE_ObjCAtSynchronizedStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAtSynchronizedStmt)
  MX_ENTER_SERIALIZE_ObjCAtSynchronizedStmt
  MX_SERIALIZE_BASE(ObjCAtSynchronizedStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCAtSynchronizedStmt, at_synchronized_token, getVal10, setVal10, initVal10, AtSynchronizedToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtSynchronizedStmt, synch_body, getVal11, setVal11, initVal11, SynchBody, CompoundStmt, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtSynchronizedStmt, synch_expression, getVal12, setVal12, initVal12, SynchExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAtSynchronizedStmt
MX_END_SERIALIZE_STMT(ObjCAtSynchronizedStmt)
#undef MX_ENTER_SERIALIZE_ObjCAtSynchronizedStmt
#undef MX_EXIT_SERIALIZE_ObjCAtSynchronizedStmt

#ifndef MX_ENTER_SERIALIZE_ObjCAtFinallyStmt
#  define MX_ENTER_SERIALIZE_ObjCAtFinallyStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAtFinallyStmt
#  define MX_EXIT_SERIALIZE_ObjCAtFinallyStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAtFinallyStmt)
  MX_ENTER_SERIALIZE_ObjCAtFinallyStmt
  MX_SERIALIZE_BASE(ObjCAtFinallyStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCAtFinallyStmt, at_finally_token, getVal10, setVal10, initVal10, AtFinallyToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtFinallyStmt, finally_body, getVal11, setVal11, initVal11, FinallyBody, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAtFinallyStmt
MX_END_SERIALIZE_STMT(ObjCAtFinallyStmt)
#undef MX_ENTER_SERIALIZE_ObjCAtFinallyStmt
#undef MX_EXIT_SERIALIZE_ObjCAtFinallyStmt

#ifndef MX_ENTER_SERIALIZE_ObjCAtCatchStmt
#  define MX_ENTER_SERIALIZE_ObjCAtCatchStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAtCatchStmt
#  define MX_EXIT_SERIALIZE_ObjCAtCatchStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAtCatchStmt)
  MX_ENTER_SERIALIZE_ObjCAtCatchStmt
  MX_SERIALIZE_BASE(ObjCAtCatchStmt, Stmt)
  MX_SERIALIZE_ENTITY(ObjCAtCatchStmt, at_catch_token, getVal10, setVal10, initVal10, AtCatchToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtCatchStmt, catch_body, getVal11, setVal11, initVal11, CatchBody, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtCatchStmt, catch_parameter_declaration, getVal12, setVal12, initVal12, CatchParameterDeclaration, VarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCAtCatchStmt, r_paren_token, getVal14, setVal14, initVal14, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(ObjCAtCatchStmt, has_ellipsis, getVal13, setVal13, initVal13, HasEllipsis, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAtCatchStmt
MX_END_SERIALIZE_STMT(ObjCAtCatchStmt)
#undef MX_ENTER_SERIALIZE_ObjCAtCatchStmt
#undef MX_EXIT_SERIALIZE_ObjCAtCatchStmt

#ifndef MX_ENTER_SERIALIZE_OMPExecutableDirective
#  define MX_ENTER_SERIALIZE_OMPExecutableDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPExecutableDirective
#  define MX_EXIT_SERIALIZE_OMPExecutableDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPExecutableDirective)
  MX_ENTER_SERIALIZE_OMPExecutableDirective
  MX_SERIALIZE_BASE(OMPExecutableDirective, Stmt)
  MX_SERIALIZE_ENTITY(OMPExecutableDirective, associated_statement, getVal10, setVal10, initVal10, AssociatedStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPExecutableDirective, innermost_captured_statement, getVal11, setVal11, initVal11, InnermostCapturedStatement, CapturedStmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPExecutableDirective, raw_statement, getVal12, setVal12, initVal12, RawStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPExecutableDirective, structured_block, getVal14, setVal14, initVal14, StructuredBlock, Stmt, NthStmt)
  MX_SERIALIZE_BOOL(OMPExecutableDirective, has_associated_statement, getVal13, setVal13, initVal13, HasAssociatedStatement, bool, NthStmt)
  MX_SERIALIZE_BOOL(OMPExecutableDirective, is_standalone_directive, getVal16, setVal16, initVal16, IsStandaloneDirective, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPExecutableDirective
MX_END_SERIALIZE_STMT(OMPExecutableDirective)
#undef MX_ENTER_SERIALIZE_OMPExecutableDirective
#undef MX_EXIT_SERIALIZE_OMPExecutableDirective

#ifndef MX_ENTER_SERIALIZE_OMPDispatchDirective
#  define MX_ENTER_SERIALIZE_OMPDispatchDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDispatchDirective
#  define MX_EXIT_SERIALIZE_OMPDispatchDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPDispatchDirective)
  MX_ENTER_SERIALIZE_OMPDispatchDirective
  MX_SERIALIZE_BASE(OMPDispatchDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPDispatchDirective, target_call_token, getVal15, setVal15, initVal15, TargetCallToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_OMPDispatchDirective
MX_END_SERIALIZE_STMT(OMPDispatchDirective)
#undef MX_ENTER_SERIALIZE_OMPDispatchDirective
#undef MX_EXIT_SERIALIZE_OMPDispatchDirective

#ifndef MX_ENTER_SERIALIZE_OMPDepobjDirective
#  define MX_ENTER_SERIALIZE_OMPDepobjDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDepobjDirective
#  define MX_EXIT_SERIALIZE_OMPDepobjDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPDepobjDirective)
  MX_ENTER_SERIALIZE_OMPDepobjDirective
  MX_SERIALIZE_BASE(OMPDepobjDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPDepobjDirective
MX_END_SERIALIZE_STMT(OMPDepobjDirective)
#undef MX_ENTER_SERIALIZE_OMPDepobjDirective
#undef MX_EXIT_SERIALIZE_OMPDepobjDirective

#ifndef MX_ENTER_SERIALIZE_OMPCriticalDirective
#  define MX_ENTER_SERIALIZE_OMPCriticalDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPCriticalDirective
#  define MX_EXIT_SERIALIZE_OMPCriticalDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPCriticalDirective)
  MX_ENTER_SERIALIZE_OMPCriticalDirective
  MX_SERIALIZE_BASE(OMPCriticalDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPCriticalDirective
MX_END_SERIALIZE_STMT(OMPCriticalDirective)
#undef MX_ENTER_SERIALIZE_OMPCriticalDirective
#undef MX_EXIT_SERIALIZE_OMPCriticalDirective

#ifndef MX_ENTER_SERIALIZE_OMPCancellationPointDirective
#  define MX_ENTER_SERIALIZE_OMPCancellationPointDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPCancellationPointDirective
#  define MX_EXIT_SERIALIZE_OMPCancellationPointDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPCancellationPointDirective)
  MX_ENTER_SERIALIZE_OMPCancellationPointDirective
  MX_SERIALIZE_BASE(OMPCancellationPointDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPCancellationPointDirective
MX_END_SERIALIZE_STMT(OMPCancellationPointDirective)
#undef MX_ENTER_SERIALIZE_OMPCancellationPointDirective
#undef MX_EXIT_SERIALIZE_OMPCancellationPointDirective

#ifndef MX_ENTER_SERIALIZE_OMPCancelDirective
#  define MX_ENTER_SERIALIZE_OMPCancelDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPCancelDirective
#  define MX_EXIT_SERIALIZE_OMPCancelDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPCancelDirective)
  MX_ENTER_SERIALIZE_OMPCancelDirective
  MX_SERIALIZE_BASE(OMPCancelDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPCancelDirective
MX_END_SERIALIZE_STMT(OMPCancelDirective)
#undef MX_ENTER_SERIALIZE_OMPCancelDirective
#undef MX_EXIT_SERIALIZE_OMPCancelDirective

#ifndef MX_ENTER_SERIALIZE_OMPBarrierDirective
#  define MX_ENTER_SERIALIZE_OMPBarrierDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPBarrierDirective
#  define MX_EXIT_SERIALIZE_OMPBarrierDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPBarrierDirective)
  MX_ENTER_SERIALIZE_OMPBarrierDirective
  MX_SERIALIZE_BASE(OMPBarrierDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPBarrierDirective
MX_END_SERIALIZE_STMT(OMPBarrierDirective)
#undef MX_ENTER_SERIALIZE_OMPBarrierDirective
#undef MX_EXIT_SERIALIZE_OMPBarrierDirective

#ifndef MX_ENTER_SERIALIZE_OMPAtomicDirective
#  define MX_ENTER_SERIALIZE_OMPAtomicDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPAtomicDirective
#  define MX_EXIT_SERIALIZE_OMPAtomicDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPAtomicDirective)
  MX_ENTER_SERIALIZE_OMPAtomicDirective
  MX_SERIALIZE_BASE(OMPAtomicDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPAtomicDirective, expression, getVal15, setVal15, initVal15, Expression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPAtomicDirective, update_expression, getVal18, setVal18, initVal18, UpdateExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPAtomicDirective, v, getVal19, setVal19, initVal19, V, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPAtomicDirective, x, getVal20, setVal20, initVal20, X, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPAtomicDirective, is_postfix_update, getVal21, setVal21, initVal21, IsPostfixUpdate, bool, NthStmt)
  MX_SERIALIZE_BOOL(OMPAtomicDirective, is_xlhs_in_rhs_part, getVal22, setVal22, initVal22, IsXLHSInRHSPart, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPAtomicDirective
MX_END_SERIALIZE_STMT(OMPAtomicDirective)
#undef MX_ENTER_SERIALIZE_OMPAtomicDirective
#undef MX_EXIT_SERIALIZE_OMPAtomicDirective

#ifndef MX_ENTER_SERIALIZE_OMPTeamsDirective
#  define MX_ENTER_SERIALIZE_OMPTeamsDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTeamsDirective
#  define MX_EXIT_SERIALIZE_OMPTeamsDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTeamsDirective)
  MX_ENTER_SERIALIZE_OMPTeamsDirective
  MX_SERIALIZE_BASE(OMPTeamsDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTeamsDirective
MX_END_SERIALIZE_STMT(OMPTeamsDirective)
#undef MX_ENTER_SERIALIZE_OMPTeamsDirective
#undef MX_EXIT_SERIALIZE_OMPTeamsDirective

#ifndef MX_ENTER_SERIALIZE_OMPTaskyieldDirective
#  define MX_ENTER_SERIALIZE_OMPTaskyieldDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTaskyieldDirective
#  define MX_EXIT_SERIALIZE_OMPTaskyieldDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTaskyieldDirective)
  MX_ENTER_SERIALIZE_OMPTaskyieldDirective
  MX_SERIALIZE_BASE(OMPTaskyieldDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTaskyieldDirective
MX_END_SERIALIZE_STMT(OMPTaskyieldDirective)
#undef MX_ENTER_SERIALIZE_OMPTaskyieldDirective
#undef MX_EXIT_SERIALIZE_OMPTaskyieldDirective

#ifndef MX_ENTER_SERIALIZE_OMPTaskwaitDirective
#  define MX_ENTER_SERIALIZE_OMPTaskwaitDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTaskwaitDirective
#  define MX_EXIT_SERIALIZE_OMPTaskwaitDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTaskwaitDirective)
  MX_ENTER_SERIALIZE_OMPTaskwaitDirective
  MX_SERIALIZE_BASE(OMPTaskwaitDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTaskwaitDirective
MX_END_SERIALIZE_STMT(OMPTaskwaitDirective)
#undef MX_ENTER_SERIALIZE_OMPTaskwaitDirective
#undef MX_EXIT_SERIALIZE_OMPTaskwaitDirective

#ifndef MX_ENTER_SERIALIZE_OMPTaskgroupDirective
#  define MX_ENTER_SERIALIZE_OMPTaskgroupDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTaskgroupDirective
#  define MX_EXIT_SERIALIZE_OMPTaskgroupDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTaskgroupDirective)
  MX_ENTER_SERIALIZE_OMPTaskgroupDirective
  MX_SERIALIZE_BASE(OMPTaskgroupDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPTaskgroupDirective, reduction_reference, getVal15, setVal15, initVal15, ReductionReference, Expr, NthStmt)
  MX_EXIT_SERIALIZE_OMPTaskgroupDirective
MX_END_SERIALIZE_STMT(OMPTaskgroupDirective)
#undef MX_ENTER_SERIALIZE_OMPTaskgroupDirective
#undef MX_EXIT_SERIALIZE_OMPTaskgroupDirective

#ifndef MX_ENTER_SERIALIZE_OMPTaskDirective
#  define MX_ENTER_SERIALIZE_OMPTaskDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTaskDirective
#  define MX_EXIT_SERIALIZE_OMPTaskDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTaskDirective)
  MX_ENTER_SERIALIZE_OMPTaskDirective
  MX_SERIALIZE_BASE(OMPTaskDirective, OMPExecutableDirective)
  MX_SERIALIZE_BOOL(OMPTaskDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPTaskDirective
MX_END_SERIALIZE_STMT(OMPTaskDirective)
#undef MX_ENTER_SERIALIZE_OMPTaskDirective
#undef MX_EXIT_SERIALIZE_OMPTaskDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetUpdateDirective
#  define MX_ENTER_SERIALIZE_OMPTargetUpdateDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetUpdateDirective
#  define MX_EXIT_SERIALIZE_OMPTargetUpdateDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetUpdateDirective)
  MX_ENTER_SERIALIZE_OMPTargetUpdateDirective
  MX_SERIALIZE_BASE(OMPTargetUpdateDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTargetUpdateDirective
MX_END_SERIALIZE_STMT(OMPTargetUpdateDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetUpdateDirective
#undef MX_EXIT_SERIALIZE_OMPTargetUpdateDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetTeamsDirective
#  define MX_ENTER_SERIALIZE_OMPTargetTeamsDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetTeamsDirective
#  define MX_EXIT_SERIALIZE_OMPTargetTeamsDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetTeamsDirective)
  MX_ENTER_SERIALIZE_OMPTargetTeamsDirective
  MX_SERIALIZE_BASE(OMPTargetTeamsDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTargetTeamsDirective
MX_END_SERIALIZE_STMT(OMPTargetTeamsDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetTeamsDirective
#undef MX_EXIT_SERIALIZE_OMPTargetTeamsDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetParallelDirective
#  define MX_ENTER_SERIALIZE_OMPTargetParallelDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetParallelDirective
#  define MX_EXIT_SERIALIZE_OMPTargetParallelDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetParallelDirective)
  MX_ENTER_SERIALIZE_OMPTargetParallelDirective
  MX_SERIALIZE_BASE(OMPTargetParallelDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPTargetParallelDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPTargetParallelDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPTargetParallelDirective
MX_END_SERIALIZE_STMT(OMPTargetParallelDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetParallelDirective
#undef MX_EXIT_SERIALIZE_OMPTargetParallelDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetExitDataDirective
#  define MX_ENTER_SERIALIZE_OMPTargetExitDataDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetExitDataDirective
#  define MX_EXIT_SERIALIZE_OMPTargetExitDataDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetExitDataDirective)
  MX_ENTER_SERIALIZE_OMPTargetExitDataDirective
  MX_SERIALIZE_BASE(OMPTargetExitDataDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTargetExitDataDirective
MX_END_SERIALIZE_STMT(OMPTargetExitDataDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetExitDataDirective
#undef MX_EXIT_SERIALIZE_OMPTargetExitDataDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetEnterDataDirective
#  define MX_ENTER_SERIALIZE_OMPTargetEnterDataDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetEnterDataDirective
#  define MX_EXIT_SERIALIZE_OMPTargetEnterDataDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetEnterDataDirective)
  MX_ENTER_SERIALIZE_OMPTargetEnterDataDirective
  MX_SERIALIZE_BASE(OMPTargetEnterDataDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTargetEnterDataDirective
MX_END_SERIALIZE_STMT(OMPTargetEnterDataDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetEnterDataDirective
#undef MX_EXIT_SERIALIZE_OMPTargetEnterDataDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetDirective
#  define MX_ENTER_SERIALIZE_OMPTargetDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetDirective
#  define MX_EXIT_SERIALIZE_OMPTargetDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetDirective)
  MX_ENTER_SERIALIZE_OMPTargetDirective
  MX_SERIALIZE_BASE(OMPTargetDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTargetDirective
MX_END_SERIALIZE_STMT(OMPTargetDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetDirective
#undef MX_EXIT_SERIALIZE_OMPTargetDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetDataDirective
#  define MX_ENTER_SERIALIZE_OMPTargetDataDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetDataDirective
#  define MX_EXIT_SERIALIZE_OMPTargetDataDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetDataDirective)
  MX_ENTER_SERIALIZE_OMPTargetDataDirective
  MX_SERIALIZE_BASE(OMPTargetDataDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPTargetDataDirective
MX_END_SERIALIZE_STMT(OMPTargetDataDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetDataDirective
#undef MX_EXIT_SERIALIZE_OMPTargetDataDirective

#ifndef MX_ENTER_SERIALIZE_OMPSingleDirective
#  define MX_ENTER_SERIALIZE_OMPSingleDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPSingleDirective
#  define MX_EXIT_SERIALIZE_OMPSingleDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPSingleDirective)
  MX_ENTER_SERIALIZE_OMPSingleDirective
  MX_SERIALIZE_BASE(OMPSingleDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPSingleDirective
MX_END_SERIALIZE_STMT(OMPSingleDirective)
#undef MX_ENTER_SERIALIZE_OMPSingleDirective
#undef MX_EXIT_SERIALIZE_OMPSingleDirective

#ifndef MX_ENTER_SERIALIZE_OMPSectionsDirective
#  define MX_ENTER_SERIALIZE_OMPSectionsDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPSectionsDirective
#  define MX_EXIT_SERIALIZE_OMPSectionsDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPSectionsDirective)
  MX_ENTER_SERIALIZE_OMPSectionsDirective
  MX_SERIALIZE_BASE(OMPSectionsDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPSectionsDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPSectionsDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPSectionsDirective
MX_END_SERIALIZE_STMT(OMPSectionsDirective)
#undef MX_ENTER_SERIALIZE_OMPSectionsDirective
#undef MX_EXIT_SERIALIZE_OMPSectionsDirective

#ifndef MX_ENTER_SERIALIZE_OMPSectionDirective
#  define MX_ENTER_SERIALIZE_OMPSectionDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPSectionDirective
#  define MX_EXIT_SERIALIZE_OMPSectionDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPSectionDirective)
  MX_ENTER_SERIALIZE_OMPSectionDirective
  MX_SERIALIZE_BASE(OMPSectionDirective, OMPExecutableDirective)
  MX_SERIALIZE_BOOL(OMPSectionDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPSectionDirective
MX_END_SERIALIZE_STMT(OMPSectionDirective)
#undef MX_ENTER_SERIALIZE_OMPSectionDirective
#undef MX_EXIT_SERIALIZE_OMPSectionDirective

#ifndef MX_ENTER_SERIALIZE_OMPScanDirective
#  define MX_ENTER_SERIALIZE_OMPScanDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPScanDirective
#  define MX_EXIT_SERIALIZE_OMPScanDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPScanDirective)
  MX_ENTER_SERIALIZE_OMPScanDirective
  MX_SERIALIZE_BASE(OMPScanDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPScanDirective
MX_END_SERIALIZE_STMT(OMPScanDirective)
#undef MX_ENTER_SERIALIZE_OMPScanDirective
#undef MX_EXIT_SERIALIZE_OMPScanDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelSectionsDirective
#  define MX_ENTER_SERIALIZE_OMPParallelSectionsDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelSectionsDirective
#  define MX_EXIT_SERIALIZE_OMPParallelSectionsDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelSectionsDirective)
  MX_ENTER_SERIALIZE_OMPParallelSectionsDirective
  MX_SERIALIZE_BASE(OMPParallelSectionsDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPParallelSectionsDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPParallelSectionsDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPParallelSectionsDirective
MX_END_SERIALIZE_STMT(OMPParallelSectionsDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelSectionsDirective
#undef MX_EXIT_SERIALIZE_OMPParallelSectionsDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelMasterDirective
#  define MX_ENTER_SERIALIZE_OMPParallelMasterDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelMasterDirective
#  define MX_EXIT_SERIALIZE_OMPParallelMasterDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelMasterDirective)
  MX_ENTER_SERIALIZE_OMPParallelMasterDirective
  MX_SERIALIZE_BASE(OMPParallelMasterDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPParallelMasterDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_OMPParallelMasterDirective
MX_END_SERIALIZE_STMT(OMPParallelMasterDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelMasterDirective
#undef MX_EXIT_SERIALIZE_OMPParallelMasterDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelDirective
#  define MX_ENTER_SERIALIZE_OMPParallelDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelDirective
#  define MX_EXIT_SERIALIZE_OMPParallelDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelDirective)
  MX_ENTER_SERIALIZE_OMPParallelDirective
  MX_SERIALIZE_BASE(OMPParallelDirective, OMPExecutableDirective)
  MX_SERIALIZE_ENTITY(OMPParallelDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPParallelDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPParallelDirective
MX_END_SERIALIZE_STMT(OMPParallelDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelDirective
#undef MX_EXIT_SERIALIZE_OMPParallelDirective

#ifndef MX_ENTER_SERIALIZE_OMPOrderedDirective
#  define MX_ENTER_SERIALIZE_OMPOrderedDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPOrderedDirective
#  define MX_EXIT_SERIALIZE_OMPOrderedDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPOrderedDirective)
  MX_ENTER_SERIALIZE_OMPOrderedDirective
  MX_SERIALIZE_BASE(OMPOrderedDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPOrderedDirective
MX_END_SERIALIZE_STMT(OMPOrderedDirective)
#undef MX_ENTER_SERIALIZE_OMPOrderedDirective
#undef MX_EXIT_SERIALIZE_OMPOrderedDirective

#ifndef MX_ENTER_SERIALIZE_OMPMasterDirective
#  define MX_ENTER_SERIALIZE_OMPMasterDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPMasterDirective
#  define MX_EXIT_SERIALIZE_OMPMasterDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPMasterDirective)
  MX_ENTER_SERIALIZE_OMPMasterDirective
  MX_SERIALIZE_BASE(OMPMasterDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPMasterDirective
MX_END_SERIALIZE_STMT(OMPMasterDirective)
#undef MX_ENTER_SERIALIZE_OMPMasterDirective
#undef MX_EXIT_SERIALIZE_OMPMasterDirective

#ifndef MX_ENTER_SERIALIZE_OMPMaskedDirective
#  define MX_ENTER_SERIALIZE_OMPMaskedDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPMaskedDirective
#  define MX_EXIT_SERIALIZE_OMPMaskedDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPMaskedDirective)
  MX_ENTER_SERIALIZE_OMPMaskedDirective
  MX_SERIALIZE_BASE(OMPMaskedDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPMaskedDirective
MX_END_SERIALIZE_STMT(OMPMaskedDirective)
#undef MX_ENTER_SERIALIZE_OMPMaskedDirective
#undef MX_EXIT_SERIALIZE_OMPMaskedDirective

#ifndef MX_ENTER_SERIALIZE_OMPLoopBasedDirective
#  define MX_ENTER_SERIALIZE_OMPLoopBasedDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPLoopBasedDirective
#  define MX_EXIT_SERIALIZE_OMPLoopBasedDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPLoopBasedDirective)
  MX_ENTER_SERIALIZE_OMPLoopBasedDirective
  MX_SERIALIZE_BASE(OMPLoopBasedDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPLoopBasedDirective
MX_END_SERIALIZE_STMT(OMPLoopBasedDirective)
#undef MX_ENTER_SERIALIZE_OMPLoopBasedDirective
#undef MX_EXIT_SERIALIZE_OMPLoopBasedDirective

#ifndef MX_ENTER_SERIALIZE_OMPUnrollDirective
#  define MX_ENTER_SERIALIZE_OMPUnrollDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPUnrollDirective
#  define MX_EXIT_SERIALIZE_OMPUnrollDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPUnrollDirective)
  MX_ENTER_SERIALIZE_OMPUnrollDirective
  MX_SERIALIZE_BASE(OMPUnrollDirective, OMPLoopBasedDirective)
  MX_SERIALIZE_ENTITY(OMPUnrollDirective, pre_initializers, getVal15, setVal15, initVal15, PreInitializers, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPUnrollDirective, transformed_statement, getVal18, setVal18, initVal18, TransformedStatement, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_OMPUnrollDirective
MX_END_SERIALIZE_STMT(OMPUnrollDirective)
#undef MX_ENTER_SERIALIZE_OMPUnrollDirective
#undef MX_EXIT_SERIALIZE_OMPUnrollDirective

#ifndef MX_ENTER_SERIALIZE_OMPTileDirective
#  define MX_ENTER_SERIALIZE_OMPTileDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTileDirective
#  define MX_EXIT_SERIALIZE_OMPTileDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTileDirective)
  MX_ENTER_SERIALIZE_OMPTileDirective
  MX_SERIALIZE_BASE(OMPTileDirective, OMPLoopBasedDirective)
  MX_SERIALIZE_ENTITY(OMPTileDirective, pre_initializers, getVal15, setVal15, initVal15, PreInitializers, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPTileDirective, transformed_statement, getVal18, setVal18, initVal18, TransformedStatement, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_OMPTileDirective
MX_END_SERIALIZE_STMT(OMPTileDirective)
#undef MX_ENTER_SERIALIZE_OMPTileDirective
#undef MX_EXIT_SERIALIZE_OMPTileDirective

#ifndef MX_ENTER_SERIALIZE_OMPLoopDirective
#  define MX_ENTER_SERIALIZE_OMPLoopDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPLoopDirective
#  define MX_EXIT_SERIALIZE_OMPLoopDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPLoopDirective)
  MX_ENTER_SERIALIZE_OMPLoopDirective
  MX_SERIALIZE_BASE(OMPLoopDirective, OMPLoopBasedDirective)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, counters, getVal17, setVal17, initVal17, Counters, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, dependent_counters, getVal23, setVal23, initVal23, DependentCounters, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, dependent_initializers, getVal24, setVal24, initVal24, DependentInitializers, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, finals, getVal25, setVal25, initVal25, Finals, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, finals_conditions, getVal26, setVal26, initVal26, FinalsConditions, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, body, getVal15, setVal15, initVal15, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, calculate_last_iteration, getVal18, setVal18, initVal18, CalculateLastIteration, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_condition, getVal19, setVal19, initVal19, CombinedCondition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_distance_condition, getVal20, setVal20, initVal20, CombinedDistanceCondition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_ensure_upper_bound, getVal27, setVal27, initVal27, CombinedEnsureUpperBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_initializer, getVal28, setVal28, initVal28, CombinedInitializer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_lower_bound_variable, getVal29, setVal29, initVal29, CombinedLowerBoundVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_next_lower_bound, getVal30, setVal30, initVal30, CombinedNextLowerBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_next_upper_bound, getVal31, setVal31, initVal31, CombinedNextUpperBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_parallel_for_in_distance_condition, getVal32, setVal32, initVal32, CombinedParallelForInDistanceCondition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, combined_upper_bound_variable, getVal33, setVal33, initVal33, CombinedUpperBoundVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, condition, getVal34, setVal34, initVal34, Condition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, distance_increment, getVal35, setVal35, initVal35, DistanceIncrement, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, ensure_upper_bound, getVal36, setVal36, initVal36, EnsureUpperBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, increment, getVal37, setVal37, initVal37, Increment, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, initializer, getVal38, setVal38, initVal38, Initializer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, is_last_iteration_variable, getVal39, setVal39, initVal39, IsLastIterationVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, iteration_variable, getVal40, setVal40, initVal40, IterationVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, last_iteration, getVal41, setVal41, initVal41, LastIteration, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, lower_bound_variable, getVal42, setVal42, initVal42, LowerBoundVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, next_lower_bound, getVal43, setVal43, initVal43, NextLowerBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, next_upper_bound, getVal44, setVal44, initVal44, NextUpperBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, num_iterations, getVal45, setVal45, initVal45, NumIterations, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, pre_condition, getVal46, setVal46, initVal46, PreCondition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, pre_initializers, getVal47, setVal47, initVal47, PreInitializers, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, prev_ensure_upper_bound, getVal48, setVal48, initVal48, PrevEnsureUpperBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, prev_lower_bound_variable, getVal49, setVal49, initVal49, PrevLowerBoundVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, prev_upper_bound_variable, getVal50, setVal50, initVal50, PrevUpperBoundVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, stride_variable, getVal51, setVal51, initVal51, StrideVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPLoopDirective, upper_bound_variable, getVal52, setVal52, initVal52, UpperBoundVariable, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, initializers, getVal53, setVal53, initVal53, Initializers, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, private_counters, getVal54, setVal54, initVal54, PrivateCounters, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPLoopDirective, updates, getVal55, setVal55, initVal55, Updates, Expr, NthStmt)
  MX_EXIT_SERIALIZE_OMPLoopDirective
MX_END_SERIALIZE_STMT(OMPLoopDirective)
#undef MX_ENTER_SERIALIZE_OMPLoopDirective
#undef MX_EXIT_SERIALIZE_OMPLoopDirective

#ifndef MX_ENTER_SERIALIZE_OMPForSimdDirective
#  define MX_ENTER_SERIALIZE_OMPForSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPForSimdDirective
#  define MX_EXIT_SERIALIZE_OMPForSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPForSimdDirective)
  MX_ENTER_SERIALIZE_OMPForSimdDirective
  MX_SERIALIZE_BASE(OMPForSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPForSimdDirective
MX_END_SERIALIZE_STMT(OMPForSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPForSimdDirective
#undef MX_EXIT_SERIALIZE_OMPForSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPForDirective
#  define MX_ENTER_SERIALIZE_OMPForDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPForDirective
#  define MX_EXIT_SERIALIZE_OMPForDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPForDirective)
  MX_ENTER_SERIALIZE_OMPForDirective
  MX_SERIALIZE_BASE(OMPForDirective, OMPLoopDirective)
  MX_SERIALIZE_ENTITY(OMPForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPForDirective
MX_END_SERIALIZE_STMT(OMPForDirective)
#undef MX_ENTER_SERIALIZE_OMPForDirective
#undef MX_EXIT_SERIALIZE_OMPForDirective

#ifndef MX_ENTER_SERIALIZE_OMPDistributeSimdDirective
#  define MX_ENTER_SERIALIZE_OMPDistributeSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDistributeSimdDirective
#  define MX_EXIT_SERIALIZE_OMPDistributeSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPDistributeSimdDirective)
  MX_ENTER_SERIALIZE_OMPDistributeSimdDirective
  MX_SERIALIZE_BASE(OMPDistributeSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPDistributeSimdDirective
MX_END_SERIALIZE_STMT(OMPDistributeSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPDistributeSimdDirective
#undef MX_EXIT_SERIALIZE_OMPDistributeSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPDistributeParallelForSimdDirective
#  define MX_ENTER_SERIALIZE_OMPDistributeParallelForSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDistributeParallelForSimdDirective
#  define MX_EXIT_SERIALIZE_OMPDistributeParallelForSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPDistributeParallelForSimdDirective)
  MX_ENTER_SERIALIZE_OMPDistributeParallelForSimdDirective
  MX_SERIALIZE_BASE(OMPDistributeParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPDistributeParallelForSimdDirective
MX_END_SERIALIZE_STMT(OMPDistributeParallelForSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPDistributeParallelForSimdDirective
#undef MX_EXIT_SERIALIZE_OMPDistributeParallelForSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPDistributeParallelForDirective
#  define MX_ENTER_SERIALIZE_OMPDistributeParallelForDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDistributeParallelForDirective
#  define MX_EXIT_SERIALIZE_OMPDistributeParallelForDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPDistributeParallelForDirective)
  MX_ENTER_SERIALIZE_OMPDistributeParallelForDirective
  MX_SERIALIZE_BASE(OMPDistributeParallelForDirective, OMPLoopDirective)
  MX_SERIALIZE_ENTITY(OMPDistributeParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPDistributeParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPDistributeParallelForDirective
MX_END_SERIALIZE_STMT(OMPDistributeParallelForDirective)
#undef MX_ENTER_SERIALIZE_OMPDistributeParallelForDirective
#undef MX_EXIT_SERIALIZE_OMPDistributeParallelForDirective

#ifndef MX_ENTER_SERIALIZE_OMPDistributeDirective
#  define MX_ENTER_SERIALIZE_OMPDistributeDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDistributeDirective
#  define MX_EXIT_SERIALIZE_OMPDistributeDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPDistributeDirective)
  MX_ENTER_SERIALIZE_OMPDistributeDirective
  MX_SERIALIZE_BASE(OMPDistributeDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPDistributeDirective
MX_END_SERIALIZE_STMT(OMPDistributeDirective)
#undef MX_ENTER_SERIALIZE_OMPDistributeDirective
#undef MX_EXIT_SERIALIZE_OMPDistributeDirective

#ifndef MX_ENTER_SERIALIZE_OMPTeamsDistributeSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTeamsDistributeSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTeamsDistributeSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTeamsDistributeSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTeamsDistributeSimdDirective)
  MX_ENTER_SERIALIZE_OMPTeamsDistributeSimdDirective
  MX_SERIALIZE_BASE(OMPTeamsDistributeSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTeamsDistributeSimdDirective
MX_END_SERIALIZE_STMT(OMPTeamsDistributeSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTeamsDistributeSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTeamsDistributeSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTeamsDistributeParallelForSimdDirective)
  MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
  MX_SERIALIZE_BASE(OMPTeamsDistributeParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
MX_END_SERIALIZE_STMT(OMPTeamsDistributeParallelForSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForDirective
#  define MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForDirective
#  define MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTeamsDistributeParallelForDirective)
  MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForDirective
  MX_SERIALIZE_BASE(OMPTeamsDistributeParallelForDirective, OMPLoopDirective)
  MX_SERIALIZE_ENTITY(OMPTeamsDistributeParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPTeamsDistributeParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForDirective
MX_END_SERIALIZE_STMT(OMPTeamsDistributeParallelForDirective)
#undef MX_ENTER_SERIALIZE_OMPTeamsDistributeParallelForDirective
#undef MX_EXIT_SERIALIZE_OMPTeamsDistributeParallelForDirective

#ifndef MX_ENTER_SERIALIZE_OMPTeamsDistributeDirective
#  define MX_ENTER_SERIALIZE_OMPTeamsDistributeDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTeamsDistributeDirective
#  define MX_EXIT_SERIALIZE_OMPTeamsDistributeDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTeamsDistributeDirective)
  MX_ENTER_SERIALIZE_OMPTeamsDistributeDirective
  MX_SERIALIZE_BASE(OMPTeamsDistributeDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTeamsDistributeDirective
MX_END_SERIALIZE_STMT(OMPTeamsDistributeDirective)
#undef MX_ENTER_SERIALIZE_OMPTeamsDistributeDirective
#undef MX_EXIT_SERIALIZE_OMPTeamsDistributeDirective

#ifndef MX_ENTER_SERIALIZE_OMPTaskLoopSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTaskLoopSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTaskLoopSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTaskLoopSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTaskLoopSimdDirective)
  MX_ENTER_SERIALIZE_OMPTaskLoopSimdDirective
  MX_SERIALIZE_BASE(OMPTaskLoopSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTaskLoopSimdDirective
MX_END_SERIALIZE_STMT(OMPTaskLoopSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTaskLoopSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTaskLoopSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTaskLoopDirective
#  define MX_ENTER_SERIALIZE_OMPTaskLoopDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTaskLoopDirective
#  define MX_EXIT_SERIALIZE_OMPTaskLoopDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTaskLoopDirective)
  MX_ENTER_SERIALIZE_OMPTaskLoopDirective
  MX_SERIALIZE_BASE(OMPTaskLoopDirective, OMPLoopDirective)
  MX_SERIALIZE_BOOL(OMPTaskLoopDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPTaskLoopDirective
MX_END_SERIALIZE_STMT(OMPTaskLoopDirective)
#undef MX_ENTER_SERIALIZE_OMPTaskLoopDirective
#undef MX_EXIT_SERIALIZE_OMPTaskLoopDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetTeamsDistributeSimdDirective)
  MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
  MX_SERIALIZE_BASE(OMPTargetTeamsDistributeSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
MX_END_SERIALIZE_STMT(OMPTargetTeamsDistributeSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetTeamsDistributeParallelForSimdDirective)
  MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
  MX_SERIALIZE_BASE(OMPTargetTeamsDistributeParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
MX_END_SERIALIZE_STMT(OMPTargetTeamsDistributeParallelForSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
#  define MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
#  define MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetTeamsDistributeParallelForDirective)
  MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
  MX_SERIALIZE_BASE(OMPTargetTeamsDistributeParallelForDirective, OMPLoopDirective)
  MX_SERIALIZE_ENTITY(OMPTargetTeamsDistributeParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPTargetTeamsDistributeParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
MX_END_SERIALIZE_STMT(OMPTargetTeamsDistributeParallelForDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective
#undef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeParallelForDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeDirective
#  define MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeDirective
#  define MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetTeamsDistributeDirective)
  MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeDirective
  MX_SERIALIZE_BASE(OMPTargetTeamsDistributeDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeDirective
MX_END_SERIALIZE_STMT(OMPTargetTeamsDistributeDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetTeamsDistributeDirective
#undef MX_EXIT_SERIALIZE_OMPTargetTeamsDistributeDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTargetSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTargetSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetSimdDirective)
  MX_ENTER_SERIALIZE_OMPTargetSimdDirective
  MX_SERIALIZE_BASE(OMPTargetSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTargetSimdDirective
MX_END_SERIALIZE_STMT(OMPTargetSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTargetSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetParallelForSimdDirective
#  define MX_ENTER_SERIALIZE_OMPTargetParallelForSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetParallelForSimdDirective
#  define MX_EXIT_SERIALIZE_OMPTargetParallelForSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetParallelForSimdDirective)
  MX_ENTER_SERIALIZE_OMPTargetParallelForSimdDirective
  MX_SERIALIZE_BASE(OMPTargetParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPTargetParallelForSimdDirective
MX_END_SERIALIZE_STMT(OMPTargetParallelForSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetParallelForSimdDirective
#undef MX_EXIT_SERIALIZE_OMPTargetParallelForSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPTargetParallelForDirective
#  define MX_ENTER_SERIALIZE_OMPTargetParallelForDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPTargetParallelForDirective
#  define MX_EXIT_SERIALIZE_OMPTargetParallelForDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPTargetParallelForDirective)
  MX_ENTER_SERIALIZE_OMPTargetParallelForDirective
  MX_SERIALIZE_BASE(OMPTargetParallelForDirective, OMPLoopDirective)
  MX_SERIALIZE_ENTITY(OMPTargetParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPTargetParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPTargetParallelForDirective
MX_END_SERIALIZE_STMT(OMPTargetParallelForDirective)
#undef MX_ENTER_SERIALIZE_OMPTargetParallelForDirective
#undef MX_EXIT_SERIALIZE_OMPTargetParallelForDirective

#ifndef MX_ENTER_SERIALIZE_OMPSimdDirective
#  define MX_ENTER_SERIALIZE_OMPSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPSimdDirective
#  define MX_EXIT_SERIALIZE_OMPSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPSimdDirective)
  MX_ENTER_SERIALIZE_OMPSimdDirective
  MX_SERIALIZE_BASE(OMPSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPSimdDirective
MX_END_SERIALIZE_STMT(OMPSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPSimdDirective
#undef MX_EXIT_SERIALIZE_OMPSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
#  define MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
#  define MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelMasterTaskLoopSimdDirective)
  MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
  MX_SERIALIZE_BASE(OMPParallelMasterTaskLoopSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
MX_END_SERIALIZE_STMT(OMPParallelMasterTaskLoopSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective
#undef MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopDirective
#  define MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopDirective
#  define MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelMasterTaskLoopDirective)
  MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopDirective
  MX_SERIALIZE_BASE(OMPParallelMasterTaskLoopDirective, OMPLoopDirective)
  MX_SERIALIZE_BOOL(OMPParallelMasterTaskLoopDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopDirective
MX_END_SERIALIZE_STMT(OMPParallelMasterTaskLoopDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelMasterTaskLoopDirective
#undef MX_EXIT_SERIALIZE_OMPParallelMasterTaskLoopDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelForSimdDirective
#  define MX_ENTER_SERIALIZE_OMPParallelForSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelForSimdDirective
#  define MX_EXIT_SERIALIZE_OMPParallelForSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelForSimdDirective)
  MX_ENTER_SERIALIZE_OMPParallelForSimdDirective
  MX_SERIALIZE_BASE(OMPParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPParallelForSimdDirective
MX_END_SERIALIZE_STMT(OMPParallelForSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelForSimdDirective
#undef MX_EXIT_SERIALIZE_OMPParallelForSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPParallelForDirective
#  define MX_ENTER_SERIALIZE_OMPParallelForDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPParallelForDirective
#  define MX_EXIT_SERIALIZE_OMPParallelForDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPParallelForDirective)
  MX_ENTER_SERIALIZE_OMPParallelForDirective
  MX_SERIALIZE_BASE(OMPParallelForDirective, OMPLoopDirective)
  MX_SERIALIZE_ENTITY(OMPParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OMPParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPParallelForDirective
MX_END_SERIALIZE_STMT(OMPParallelForDirective)
#undef MX_ENTER_SERIALIZE_OMPParallelForDirective
#undef MX_EXIT_SERIALIZE_OMPParallelForDirective

#ifndef MX_ENTER_SERIALIZE_OMPMasterTaskLoopSimdDirective
#  define MX_ENTER_SERIALIZE_OMPMasterTaskLoopSimdDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPMasterTaskLoopSimdDirective
#  define MX_EXIT_SERIALIZE_OMPMasterTaskLoopSimdDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPMasterTaskLoopSimdDirective)
  MX_ENTER_SERIALIZE_OMPMasterTaskLoopSimdDirective
  MX_SERIALIZE_BASE(OMPMasterTaskLoopSimdDirective, OMPLoopDirective)
  MX_EXIT_SERIALIZE_OMPMasterTaskLoopSimdDirective
MX_END_SERIALIZE_STMT(OMPMasterTaskLoopSimdDirective)
#undef MX_ENTER_SERIALIZE_OMPMasterTaskLoopSimdDirective
#undef MX_EXIT_SERIALIZE_OMPMasterTaskLoopSimdDirective

#ifndef MX_ENTER_SERIALIZE_OMPMasterTaskLoopDirective
#  define MX_ENTER_SERIALIZE_OMPMasterTaskLoopDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPMasterTaskLoopDirective
#  define MX_EXIT_SERIALIZE_OMPMasterTaskLoopDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPMasterTaskLoopDirective)
  MX_ENTER_SERIALIZE_OMPMasterTaskLoopDirective
  MX_SERIALIZE_BASE(OMPMasterTaskLoopDirective, OMPLoopDirective)
  MX_SERIALIZE_BOOL(OMPMasterTaskLoopDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
  MX_EXIT_SERIALIZE_OMPMasterTaskLoopDirective
MX_END_SERIALIZE_STMT(OMPMasterTaskLoopDirective)
#undef MX_ENTER_SERIALIZE_OMPMasterTaskLoopDirective
#undef MX_EXIT_SERIALIZE_OMPMasterTaskLoopDirective

#ifndef MX_ENTER_SERIALIZE_OMPInteropDirective
#  define MX_ENTER_SERIALIZE_OMPInteropDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPInteropDirective
#  define MX_EXIT_SERIALIZE_OMPInteropDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPInteropDirective)
  MX_ENTER_SERIALIZE_OMPInteropDirective
  MX_SERIALIZE_BASE(OMPInteropDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPInteropDirective
MX_END_SERIALIZE_STMT(OMPInteropDirective)
#undef MX_ENTER_SERIALIZE_OMPInteropDirective
#undef MX_EXIT_SERIALIZE_OMPInteropDirective

#ifndef MX_ENTER_SERIALIZE_OMPFlushDirective
#  define MX_ENTER_SERIALIZE_OMPFlushDirective
#endif
#ifndef MX_EXIT_SERIALIZE_OMPFlushDirective
#  define MX_EXIT_SERIALIZE_OMPFlushDirective
#endif

MX_BEGIN_SERIALIZE_STMT(OMPFlushDirective)
  MX_ENTER_SERIALIZE_OMPFlushDirective
  MX_SERIALIZE_BASE(OMPFlushDirective, OMPExecutableDirective)
  MX_EXIT_SERIALIZE_OMPFlushDirective
MX_END_SERIALIZE_STMT(OMPFlushDirective)
#undef MX_ENTER_SERIALIZE_OMPFlushDirective
#undef MX_EXIT_SERIALIZE_OMPFlushDirective

#ifndef MX_ENTER_SERIALIZE_OMPCanonicalLoop
#  define MX_ENTER_SERIALIZE_OMPCanonicalLoop
#endif
#ifndef MX_EXIT_SERIALIZE_OMPCanonicalLoop
#  define MX_EXIT_SERIALIZE_OMPCanonicalLoop
#endif

MX_BEGIN_SERIALIZE_STMT(OMPCanonicalLoop)
  MX_ENTER_SERIALIZE_OMPCanonicalLoop
  MX_SERIALIZE_BASE(OMPCanonicalLoop, Stmt)
  MX_SERIALIZE_ENTITY(OMPCanonicalLoop, distance_func, getVal10, setVal10, initVal10, DistanceFunc, CapturedStmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPCanonicalLoop, loop_statement, getVal11, setVal11, initVal11, LoopStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPCanonicalLoop, loop_variable_func, getVal12, setVal12, initVal12, LoopVariableFunc, CapturedStmt, NthStmt)
  MX_SERIALIZE_ENTITY(OMPCanonicalLoop, loop_variable_reference, getVal14, setVal14, initVal14, LoopVariableReference, DeclRefExpr, NthStmt)
  MX_EXIT_SERIALIZE_OMPCanonicalLoop
MX_END_SERIALIZE_STMT(OMPCanonicalLoop)
#undef MX_ENTER_SERIALIZE_OMPCanonicalLoop
#undef MX_EXIT_SERIALIZE_OMPCanonicalLoop

#ifndef MX_ENTER_SERIALIZE_NullStmt
#  define MX_ENTER_SERIALIZE_NullStmt
#endif
#ifndef MX_EXIT_SERIALIZE_NullStmt
#  define MX_EXIT_SERIALIZE_NullStmt
#endif

MX_BEGIN_SERIALIZE_STMT(NullStmt)
  MX_ENTER_SERIALIZE_NullStmt
  MX_SERIALIZE_BASE(NullStmt, Stmt)
  MX_SERIALIZE_ENTITY(NullStmt, semi_token, getVal10, setVal10, initVal10, SemiToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(NullStmt, has_leading_empty_macro, getVal13, setVal13, initVal13, HasLeadingEmptyMacro, bool, NthStmt)
  MX_EXIT_SERIALIZE_NullStmt
MX_END_SERIALIZE_STMT(NullStmt)
#undef MX_ENTER_SERIALIZE_NullStmt
#undef MX_EXIT_SERIALIZE_NullStmt

#ifndef MX_ENTER_SERIALIZE_MSDependentExistsStmt
#  define MX_ENTER_SERIALIZE_MSDependentExistsStmt
#endif
#ifndef MX_EXIT_SERIALIZE_MSDependentExistsStmt
#  define MX_EXIT_SERIALIZE_MSDependentExistsStmt
#endif

MX_BEGIN_SERIALIZE_STMT(MSDependentExistsStmt)
  MX_ENTER_SERIALIZE_MSDependentExistsStmt
  MX_SERIALIZE_BASE(MSDependentExistsStmt, Stmt)
  MX_SERIALIZE_ENTITY(MSDependentExistsStmt, keyword_token, getVal10, setVal10, initVal10, KeywordToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MSDependentExistsStmt, sub_statement, getVal11, setVal11, initVal11, SubStatement, CompoundStmt, NthStmt)
  MX_SERIALIZE_BOOL(MSDependentExistsStmt, is_if_exists, getVal13, setVal13, initVal13, IsIfExists, bool, NthStmt)
  MX_SERIALIZE_BOOL(MSDependentExistsStmt, is_if_not_exists, getVal16, setVal16, initVal16, IsIfNotExists, bool, NthStmt)
  MX_EXIT_SERIALIZE_MSDependentExistsStmt
MX_END_SERIALIZE_STMT(MSDependentExistsStmt)
#undef MX_ENTER_SERIALIZE_MSDependentExistsStmt
#undef MX_EXIT_SERIALIZE_MSDependentExistsStmt

#ifndef MX_ENTER_SERIALIZE_IndirectGotoStmt
#  define MX_ENTER_SERIALIZE_IndirectGotoStmt
#endif
#ifndef MX_EXIT_SERIALIZE_IndirectGotoStmt
#  define MX_EXIT_SERIALIZE_IndirectGotoStmt
#endif

MX_BEGIN_SERIALIZE_STMT(IndirectGotoStmt)
  MX_ENTER_SERIALIZE_IndirectGotoStmt
  MX_SERIALIZE_BASE(IndirectGotoStmt, Stmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(IndirectGotoStmt, constant_target, getVal10, setVal10, initVal10, ConstantTarget, LabelDecl, NthStmt)
  MX_SERIALIZE_ENTITY(IndirectGotoStmt, goto_token, getVal11, setVal11, initVal11, GotoToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(IndirectGotoStmt, star_token, getVal12, setVal12, initVal12, StarToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(IndirectGotoStmt, target, getVal14, setVal14, initVal14, Target, Expr, NthStmt)
  MX_EXIT_SERIALIZE_IndirectGotoStmt
MX_END_SERIALIZE_STMT(IndirectGotoStmt)
#undef MX_ENTER_SERIALIZE_IndirectGotoStmt
#undef MX_EXIT_SERIALIZE_IndirectGotoStmt

#ifndef MX_ENTER_SERIALIZE_IfStmt
#  define MX_ENTER_SERIALIZE_IfStmt
#endif
#ifndef MX_EXIT_SERIALIZE_IfStmt
#  define MX_EXIT_SERIALIZE_IfStmt
#endif

MX_BEGIN_SERIALIZE_STMT(IfStmt)
  MX_ENTER_SERIALIZE_IfStmt
  MX_SERIALIZE_BASE(IfStmt, Stmt)
  MX_SERIALIZE_ENTITY(IfStmt, condition, getVal10, setVal10, initVal10, Condition, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(IfStmt, condition_variable, getVal11, setVal11, initVal11, ConditionVariable, VarDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(IfStmt, condition_variable_declaration_statement, getVal12, setVal12, initVal12, ConditionVariableDeclarationStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(IfStmt, else_, getVal14, setVal14, initVal14, Else, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(IfStmt, else_token, getVal15, setVal15, initVal15, ElseToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(IfStmt, if_token, getVal18, setVal18, initVal18, IfToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(IfStmt, initializer, getVal19, setVal19, initVal19, Initializer, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(IfStmt, l_paren_token, getVal20, setVal20, initVal20, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(IfStmt, r_paren_token, getVal27, setVal27, initVal27, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(IfStmt, then, getVal28, setVal28, initVal28, Then, Stmt, NthStmt)
  MX_SERIALIZE_BOOL(IfStmt, has_else_storage, getVal57, setVal57, initVal57, HasElseStorage, bool, NthStmt)
  MX_SERIALIZE_BOOL(IfStmt, has_initializer_storage, getVal58, setVal58, initVal58, HasInitializerStorage, bool, NthStmt)
  MX_SERIALIZE_BOOL(IfStmt, has_variable_storage, getVal59, setVal59, initVal59, HasVariableStorage, bool, NthStmt)
  MX_SERIALIZE_BOOL(IfStmt, is_constexpr, getVal60, setVal60, initVal60, IsConstexpr, bool, NthStmt)
  MX_SERIALIZE_BOOL(IfStmt, is_obj_c_availability_check, getVal61, setVal61, initVal61, IsObjCAvailabilityCheck, bool, NthStmt)
  MX_EXIT_SERIALIZE_IfStmt
MX_END_SERIALIZE_STMT(IfStmt)
#undef MX_ENTER_SERIALIZE_IfStmt
#undef MX_EXIT_SERIALIZE_IfStmt

#ifndef MX_ENTER_SERIALIZE_GotoStmt
#  define MX_ENTER_SERIALIZE_GotoStmt
#endif
#ifndef MX_EXIT_SERIALIZE_GotoStmt
#  define MX_EXIT_SERIALIZE_GotoStmt
#endif

MX_BEGIN_SERIALIZE_STMT(GotoStmt)
  MX_ENTER_SERIALIZE_GotoStmt
  MX_SERIALIZE_BASE(GotoStmt, Stmt)
  MX_SERIALIZE_ENTITY(GotoStmt, goto_token, getVal10, setVal10, initVal10, GotoToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(GotoStmt, label, getVal11, setVal11, initVal11, Label, LabelDecl, NthStmt)
  MX_SERIALIZE_ENTITY(GotoStmt, label_token, getVal12, setVal12, initVal12, LabelToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_GotoStmt
MX_END_SERIALIZE_STMT(GotoStmt)
#undef MX_ENTER_SERIALIZE_GotoStmt
#undef MX_EXIT_SERIALIZE_GotoStmt

#ifndef MX_ENTER_SERIALIZE_ForStmt
#  define MX_ENTER_SERIALIZE_ForStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ForStmt
#  define MX_EXIT_SERIALIZE_ForStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ForStmt)
  MX_ENTER_SERIALIZE_ForStmt
  MX_SERIALIZE_BASE(ForStmt, Stmt)
  MX_SERIALIZE_ENTITY(ForStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ForStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ForStmt, condition_variable, getVal12, setVal12, initVal12, ConditionVariable, VarDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ForStmt, condition_variable_declaration_statement, getVal14, setVal14, initVal14, ConditionVariableDeclarationStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_ENTITY(ForStmt, for_token, getVal15, setVal15, initVal15, ForToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ForStmt, increment, getVal18, setVal18, initVal18, Increment, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ForStmt, initializer, getVal19, setVal19, initVal19, Initializer, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(ForStmt, l_paren_token, getVal20, setVal20, initVal20, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ForStmt, r_paren_token, getVal27, setVal27, initVal27, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ForStmt
MX_END_SERIALIZE_STMT(ForStmt)
#undef MX_ENTER_SERIALIZE_ForStmt
#undef MX_EXIT_SERIALIZE_ForStmt

#ifndef MX_ENTER_SERIALIZE_DoStmt
#  define MX_ENTER_SERIALIZE_DoStmt
#endif
#ifndef MX_EXIT_SERIALIZE_DoStmt
#  define MX_EXIT_SERIALIZE_DoStmt
#endif

MX_BEGIN_SERIALIZE_STMT(DoStmt)
  MX_ENTER_SERIALIZE_DoStmt
  MX_SERIALIZE_BASE(DoStmt, Stmt)
  MX_SERIALIZE_ENTITY(DoStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(DoStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(DoStmt, do_token, getVal12, setVal12, initVal12, DoToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DoStmt, r_paren_token, getVal14, setVal14, initVal14, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DoStmt, while_token, getVal15, setVal15, initVal15, WhileToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_DoStmt
MX_END_SERIALIZE_STMT(DoStmt)
#undef MX_ENTER_SERIALIZE_DoStmt
#undef MX_EXIT_SERIALIZE_DoStmt

#ifndef MX_ENTER_SERIALIZE_DeclStmt
#  define MX_ENTER_SERIALIZE_DeclStmt
#endif
#ifndef MX_EXIT_SERIALIZE_DeclStmt
#  define MX_EXIT_SERIALIZE_DeclStmt
#endif

MX_BEGIN_SERIALIZE_STMT(DeclStmt)
  MX_ENTER_SERIALIZE_DeclStmt
  MX_SERIALIZE_BASE(DeclStmt, Stmt)
  MX_SERIALIZE_ENTITY_LIST(DeclStmt, declarations, getVal17, setVal17, initVal17, Declarations, Decl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(DeclStmt, single_declaration, getVal10, setVal10, initVal10, SingleDeclaration, Decl, NthStmt)
  MX_SERIALIZE_BOOL(DeclStmt, is_single_declaration, getVal16, setVal16, initVal16, IsSingleDeclaration, bool, NthStmt)
  MX_EXIT_SERIALIZE_DeclStmt
MX_END_SERIALIZE_STMT(DeclStmt)
#undef MX_ENTER_SERIALIZE_DeclStmt
#undef MX_EXIT_SERIALIZE_DeclStmt

#ifndef MX_ENTER_SERIALIZE_CoroutineBodyStmt
#  define MX_ENTER_SERIALIZE_CoroutineBodyStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CoroutineBodyStmt
#  define MX_EXIT_SERIALIZE_CoroutineBodyStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CoroutineBodyStmt)
  MX_ENTER_SERIALIZE_CoroutineBodyStmt
  MX_SERIALIZE_BASE(CoroutineBodyStmt, Stmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, allocate, getVal10, setVal10, initVal10, Allocate, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, body, getVal11, setVal11, initVal11, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, deallocate, getVal12, setVal12, initVal12, Deallocate, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, exception_handler, getVal14, setVal14, initVal14, ExceptionHandler, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, fallthrough_handler, getVal15, setVal15, initVal15, FallthroughHandler, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, final_suspend_statement, getVal18, setVal18, initVal18, FinalSuspendStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, initializer_suspend_statement, getVal19, setVal19, initVal19, InitializerSuspendStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(CoroutineBodyStmt, parameter_moves, getVal17, setVal17, initVal17, ParameterMoves, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, promise_declaration, getVal20, setVal20, initVal20, PromiseDeclaration, VarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, promise_declaration_statement, getVal27, setVal27, initVal27, PromiseDeclarationStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, result_declaration, getVal28, setVal28, initVal28, ResultDeclaration, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, return_statement, getVal29, setVal29, initVal29, ReturnStatement, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, return_statement_on_alloc_failure, getVal30, setVal30, initVal30, ReturnStatementOnAllocFailure, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineBodyStmt, return_value_initializer, getVal31, setVal31, initVal31, ReturnValueInitializer, Expr, NthStmt)
  MX_SERIALIZE_BOOL(CoroutineBodyStmt, has_dependent_promise_type, getVal13, setVal13, initVal13, HasDependentPromiseType, bool, NthStmt)
  MX_EXIT_SERIALIZE_CoroutineBodyStmt
MX_END_SERIALIZE_STMT(CoroutineBodyStmt)
#undef MX_ENTER_SERIALIZE_CoroutineBodyStmt
#undef MX_EXIT_SERIALIZE_CoroutineBodyStmt

#ifndef MX_ENTER_SERIALIZE_CoreturnStmt
#  define MX_ENTER_SERIALIZE_CoreturnStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CoreturnStmt
#  define MX_EXIT_SERIALIZE_CoreturnStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CoreturnStmt)
  MX_ENTER_SERIALIZE_CoreturnStmt
  MX_SERIALIZE_BASE(CoreturnStmt, Stmt)
  MX_SERIALIZE_ENTITY(CoreturnStmt, keyword_token, getVal10, setVal10, initVal10, KeywordToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CoreturnStmt, operand, getVal11, setVal11, initVal11, Operand, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CoreturnStmt, promise_call, getVal12, setVal12, initVal12, PromiseCall, Expr, NthStmt)
  MX_SERIALIZE_BOOL(CoreturnStmt, is_implicit, getVal13, setVal13, initVal13, IsImplicit, bool, NthStmt)
  MX_EXIT_SERIALIZE_CoreturnStmt
MX_END_SERIALIZE_STMT(CoreturnStmt)
#undef MX_ENTER_SERIALIZE_CoreturnStmt
#undef MX_EXIT_SERIALIZE_CoreturnStmt

#ifndef MX_ENTER_SERIALIZE_ContinueStmt
#  define MX_ENTER_SERIALIZE_ContinueStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ContinueStmt
#  define MX_EXIT_SERIALIZE_ContinueStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ContinueStmt)
  MX_ENTER_SERIALIZE_ContinueStmt
  MX_SERIALIZE_BASE(ContinueStmt, Stmt)
  MX_SERIALIZE_ENTITY(ContinueStmt, continue_token, getVal10, setVal10, initVal10, ContinueToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ContinueStmt
MX_END_SERIALIZE_STMT(ContinueStmt)
#undef MX_ENTER_SERIALIZE_ContinueStmt
#undef MX_EXIT_SERIALIZE_ContinueStmt

#ifndef MX_ENTER_SERIALIZE_CompoundStmt
#  define MX_ENTER_SERIALIZE_CompoundStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CompoundStmt
#  define MX_EXIT_SERIALIZE_CompoundStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CompoundStmt)
  MX_ENTER_SERIALIZE_CompoundStmt
  MX_SERIALIZE_BASE(CompoundStmt, Stmt)
  MX_SERIALIZE_ENTITY(CompoundStmt, left_brace_token, getVal10, setVal10, initVal10, LeftBraceToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CompoundStmt, right_brace_token, getVal11, setVal11, initVal11, RightBraceToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CompoundStmt, statement_expression_result, getVal12, setVal12, initVal12, StatementExpressionResult, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_CompoundStmt
MX_END_SERIALIZE_STMT(CompoundStmt)
#undef MX_ENTER_SERIALIZE_CompoundStmt
#undef MX_EXIT_SERIALIZE_CompoundStmt

#ifndef MX_ENTER_SERIALIZE_CapturedStmt
#  define MX_ENTER_SERIALIZE_CapturedStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CapturedStmt
#  define MX_EXIT_SERIALIZE_CapturedStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CapturedStmt)
  MX_ENTER_SERIALIZE_CapturedStmt
  MX_SERIALIZE_BASE(CapturedStmt, Stmt)
  MX_SERIALIZE_ENTITY(CapturedStmt, captured_declaration, getVal10, setVal10, initVal10, CapturedDeclaration, CapturedDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CapturedStmt, captured_record_declaration, getVal11, setVal11, initVal11, CapturedRecordDeclaration, RecordDecl, NthStmt)
  MX_SERIALIZE_ENUM(CapturedStmt, captured_region_kind, getVal62, setVal62, initVal62, CapturedRegionKind, CapturedRegionKind, NthStmt)
  MX_SERIALIZE_ENTITY(CapturedStmt, captured_statement, getVal12, setVal12, initVal12, CapturedStatement, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_CapturedStmt
MX_END_SERIALIZE_STMT(CapturedStmt)
#undef MX_ENTER_SERIALIZE_CapturedStmt
#undef MX_EXIT_SERIALIZE_CapturedStmt

#ifndef MX_ENTER_SERIALIZE_CXXTryStmt
#  define MX_ENTER_SERIALIZE_CXXTryStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CXXTryStmt
#  define MX_EXIT_SERIALIZE_CXXTryStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CXXTryStmt)
  MX_ENTER_SERIALIZE_CXXTryStmt
  MX_SERIALIZE_BASE(CXXTryStmt, Stmt)
  MX_SERIALIZE_ENTITY(CXXTryStmt, try_block, getVal10, setVal10, initVal10, TryBlock, CompoundStmt, NthStmt)
  MX_SERIALIZE_ENTITY(CXXTryStmt, try_token, getVal11, setVal11, initVal11, TryToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(CXXTryStmt, handlers, getVal17, setVal17, initVal17, Handlers, CXXCatchStmt, NthStmt)
  MX_EXIT_SERIALIZE_CXXTryStmt
MX_END_SERIALIZE_STMT(CXXTryStmt)
#undef MX_ENTER_SERIALIZE_CXXTryStmt
#undef MX_EXIT_SERIALIZE_CXXTryStmt

#ifndef MX_ENTER_SERIALIZE_CXXForRangeStmt
#  define MX_ENTER_SERIALIZE_CXXForRangeStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CXXForRangeStmt
#  define MX_EXIT_SERIALIZE_CXXForRangeStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CXXForRangeStmt)
  MX_ENTER_SERIALIZE_CXXForRangeStmt
  MX_SERIALIZE_BASE(CXXForRangeStmt, Stmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, begin_statement, getVal10, setVal10, initVal10, BeginStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, body, getVal11, setVal11, initVal11, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, coawait_token, getVal12, setVal12, initVal12, CoawaitToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, colon_token, getVal14, setVal14, initVal14, ColonToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, condition, getVal15, setVal15, initVal15, Condition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, end_statement, getVal18, setVal18, initVal18, EndStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, for_token, getVal19, setVal19, initVal19, ForToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, increment, getVal20, setVal20, initVal20, Increment, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXForRangeStmt, initializer, getVal27, setVal27, initVal27, Initializer, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, loop_variable_statement, getVal28, setVal28, initVal28, LoopVariableStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, loop_variable, getVal29, setVal29, initVal29, LoopVariable, VarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, r_paren_token, getVal30, setVal30, initVal30, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, range_initializer, getVal31, setVal31, initVal31, RangeInitializer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXForRangeStmt, range_statement, getVal32, setVal32, initVal32, RangeStatement, DeclStmt, NthStmt)
  MX_EXIT_SERIALIZE_CXXForRangeStmt
MX_END_SERIALIZE_STMT(CXXForRangeStmt)
#undef MX_ENTER_SERIALIZE_CXXForRangeStmt
#undef MX_EXIT_SERIALIZE_CXXForRangeStmt

#ifndef MX_ENTER_SERIALIZE_CXXCatchStmt
#  define MX_ENTER_SERIALIZE_CXXCatchStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CXXCatchStmt
#  define MX_EXIT_SERIALIZE_CXXCatchStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CXXCatchStmt)
  MX_ENTER_SERIALIZE_CXXCatchStmt
  MX_SERIALIZE_BASE(CXXCatchStmt, Stmt)
  MX_SERIALIZE_ENTITY(CXXCatchStmt, catch_token, getVal10, setVal10, initVal10, CatchToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXCatchStmt, caught_type, getVal11, setVal11, initVal11, CaughtType, Type, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXCatchStmt, exception_declaration, getVal12, setVal12, initVal12, ExceptionDeclaration, VarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXCatchStmt, handler_block, getVal14, setVal14, initVal14, HandlerBlock, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_CXXCatchStmt
MX_END_SERIALIZE_STMT(CXXCatchStmt)
#undef MX_ENTER_SERIALIZE_CXXCatchStmt
#undef MX_EXIT_SERIALIZE_CXXCatchStmt

#ifndef MX_ENTER_SERIALIZE_BreakStmt
#  define MX_ENTER_SERIALIZE_BreakStmt
#endif
#ifndef MX_EXIT_SERIALIZE_BreakStmt
#  define MX_EXIT_SERIALIZE_BreakStmt
#endif

MX_BEGIN_SERIALIZE_STMT(BreakStmt)
  MX_ENTER_SERIALIZE_BreakStmt
  MX_SERIALIZE_BASE(BreakStmt, Stmt)
  MX_SERIALIZE_ENTITY(BreakStmt, break_token, getVal10, setVal10, initVal10, BreakToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_BreakStmt
MX_END_SERIALIZE_STMT(BreakStmt)
#undef MX_ENTER_SERIALIZE_BreakStmt
#undef MX_EXIT_SERIALIZE_BreakStmt

#ifndef MX_ENTER_SERIALIZE_AsmStmt
#  define MX_ENTER_SERIALIZE_AsmStmt
#endif
#ifndef MX_EXIT_SERIALIZE_AsmStmt
#  define MX_EXIT_SERIALIZE_AsmStmt
#endif

MX_BEGIN_SERIALIZE_STMT(AsmStmt)
  MX_ENTER_SERIALIZE_AsmStmt
  MX_SERIALIZE_BASE(AsmStmt, Stmt)
  MX_SERIALIZE_TEXT(AsmStmt, generate_assembly_string, getVal63, setVal63, initVal63, GenerateAssemblyString, basic_string, NthStmt)
  MX_SERIALIZE_ENTITY(AsmStmt, assembly_token, getVal10, setVal10, initVal10, AssemblyToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(AsmStmt, inputs, getVal17, setVal17, initVal17, Inputs, Expr, NthStmt)
  MX_SERIALIZE_BOOL(AsmStmt, is_simple, getVal13, setVal13, initVal13, IsSimple, bool, NthStmt)
  MX_SERIALIZE_BOOL(AsmStmt, is_volatile, getVal16, setVal16, initVal16, IsVolatile, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(AsmStmt, outputs, getVal23, setVal23, initVal23, Outputs, Expr, NthStmt)
  MX_SERIALIZE_TEXT_LIST(AsmStmt, output_constraints, getVal64, setVal64, initVal64, OutputConstraints, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(AsmStmt, output_expressions, getVal24, setVal24, initVal24, OutputExpressions, Expr, NthStmt)
  MX_SERIALIZE_TEXT_LIST(AsmStmt, input_constraints, getVal65, setVal65, initVal65, InputConstraints, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(AsmStmt, input_expressions, getVal25, setVal25, initVal25, InputExpressions, Expr, NthStmt)
  MX_SERIALIZE_TEXT_LIST(AsmStmt, clobbers, getVal66, setVal66, initVal66, Clobbers, basic_string_view, NthStmt)
  MX_EXIT_SERIALIZE_AsmStmt
MX_END_SERIALIZE_STMT(AsmStmt)
#undef MX_ENTER_SERIALIZE_AsmStmt
#undef MX_EXIT_SERIALIZE_AsmStmt

#ifndef MX_ENTER_SERIALIZE_MSAsmStmt
#  define MX_ENTER_SERIALIZE_MSAsmStmt
#endif
#ifndef MX_EXIT_SERIALIZE_MSAsmStmt
#  define MX_EXIT_SERIALIZE_MSAsmStmt
#endif

MX_BEGIN_SERIALIZE_STMT(MSAsmStmt)
  MX_ENTER_SERIALIZE_MSAsmStmt
  MX_SERIALIZE_BASE(MSAsmStmt, AsmStmt)
  MX_SERIALIZE_TEXT_LIST(MSAsmStmt, all_constraints, getVal67, setVal67, initVal67, AllConstraints, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(MSAsmStmt, all_expressions, getVal26, setVal26, initVal26, AllExpressions, Expr, NthStmt)
  MX_SERIALIZE_TEXT(MSAsmStmt, assembly_string, getVal68, setVal68, initVal68, AssemblyString, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY(MSAsmStmt, l_brace_token, getVal11, setVal11, initVal11, LBraceToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(MSAsmStmt, has_braces, getVal21, setVal21, initVal21, HasBraces, bool, NthStmt)
  MX_EXIT_SERIALIZE_MSAsmStmt
MX_END_SERIALIZE_STMT(MSAsmStmt)
#undef MX_ENTER_SERIALIZE_MSAsmStmt
#undef MX_EXIT_SERIALIZE_MSAsmStmt

#ifndef MX_ENTER_SERIALIZE_GCCAsmStmt
#  define MX_ENTER_SERIALIZE_GCCAsmStmt
#endif
#ifndef MX_EXIT_SERIALIZE_GCCAsmStmt
#  define MX_EXIT_SERIALIZE_GCCAsmStmt
#endif

MX_BEGIN_SERIALIZE_STMT(GCCAsmStmt)
  MX_ENTER_SERIALIZE_GCCAsmStmt
  MX_SERIALIZE_BASE(GCCAsmStmt, AsmStmt)
  MX_SERIALIZE_ENTITY(GCCAsmStmt, assembly_string, getVal11, setVal11, initVal11, AssemblyString, StringLiteral, NthStmt)
  MX_SERIALIZE_ENTITY(GCCAsmStmt, r_paren_token, getVal12, setVal12, initVal12, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(GCCAsmStmt, is_assembly_goto, getVal21, setVal21, initVal21, IsAssemblyGoto, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(GCCAsmStmt, labels, getVal26, setVal26, initVal26, Labels, AddrLabelExpr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(GCCAsmStmt, output_constraint_literals, getVal53, setVal53, initVal53, OutputConstraintLiterals, StringLiteral, NthStmt)
  MX_SERIALIZE_TEXT_LIST(GCCAsmStmt, output_names, getVal67, setVal67, initVal67, OutputNames, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(GCCAsmStmt, input_constraint_literals, getVal54, setVal54, initVal54, InputConstraintLiterals, StringLiteral, NthStmt)
  MX_SERIALIZE_TEXT_LIST(GCCAsmStmt, input_names, getVal69, setVal69, initVal69, InputNames, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(GCCAsmStmt, clobber_string_literals, getVal55, setVal55, initVal55, ClobberStringLiterals, StringLiteral, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(GCCAsmStmt, label_expressions, getVal70, setVal70, initVal70, LabelExpressions, AddrLabelExpr, NthStmt)
  MX_SERIALIZE_TEXT_LIST(GCCAsmStmt, label_names, getVal71, setVal71, initVal71, LabelNames, basic_string_view, NthStmt)
  MX_EXIT_SERIALIZE_GCCAsmStmt
MX_END_SERIALIZE_STMT(GCCAsmStmt)
#undef MX_ENTER_SERIALIZE_GCCAsmStmt
#undef MX_EXIT_SERIALIZE_GCCAsmStmt

#ifndef MX_ENTER_SERIALIZE_WhileStmt
#  define MX_ENTER_SERIALIZE_WhileStmt
#endif
#ifndef MX_EXIT_SERIALIZE_WhileStmt
#  define MX_EXIT_SERIALIZE_WhileStmt
#endif

MX_BEGIN_SERIALIZE_STMT(WhileStmt)
  MX_ENTER_SERIALIZE_WhileStmt
  MX_SERIALIZE_BASE(WhileStmt, Stmt)
  MX_SERIALIZE_ENTITY(WhileStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(WhileStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(WhileStmt, condition_variable, getVal12, setVal12, initVal12, ConditionVariable, VarDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(WhileStmt, condition_variable_declaration_statement, getVal14, setVal14, initVal14, ConditionVariableDeclarationStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_ENTITY(WhileStmt, l_paren_token, getVal15, setVal15, initVal15, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(WhileStmt, r_paren_token, getVal18, setVal18, initVal18, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(WhileStmt, while_token, getVal19, setVal19, initVal19, WhileToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(WhileStmt, has_variable_storage, getVal21, setVal21, initVal21, HasVariableStorage, bool, NthStmt)
  MX_EXIT_SERIALIZE_WhileStmt
MX_END_SERIALIZE_STMT(WhileStmt)
#undef MX_ENTER_SERIALIZE_WhileStmt
#undef MX_EXIT_SERIALIZE_WhileStmt

#ifndef MX_ENTER_SERIALIZE_ValueStmt
#  define MX_ENTER_SERIALIZE_ValueStmt
#endif
#ifndef MX_EXIT_SERIALIZE_ValueStmt
#  define MX_EXIT_SERIALIZE_ValueStmt
#endif

MX_BEGIN_SERIALIZE_STMT(ValueStmt)
  MX_ENTER_SERIALIZE_ValueStmt
  MX_SERIALIZE_BASE(ValueStmt, Stmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(ValueStmt, expression_statement, getVal10, setVal10, initVal10, ExpressionStatement, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ValueStmt
MX_END_SERIALIZE_STMT(ValueStmt)
#undef MX_ENTER_SERIALIZE_ValueStmt
#undef MX_EXIT_SERIALIZE_ValueStmt

#ifndef MX_ENTER_SERIALIZE_LabelStmt
#  define MX_ENTER_SERIALIZE_LabelStmt
#endif
#ifndef MX_EXIT_SERIALIZE_LabelStmt
#  define MX_EXIT_SERIALIZE_LabelStmt
#endif

MX_BEGIN_SERIALIZE_STMT(LabelStmt)
  MX_ENTER_SERIALIZE_LabelStmt
  MX_SERIALIZE_BASE(LabelStmt, ValueStmt)
  MX_SERIALIZE_ENTITY(LabelStmt, declaration, getVal11, setVal11, initVal11, Declaration, LabelDecl, NthStmt)
  MX_SERIALIZE_ENTITY(LabelStmt, identifier_token, getVal12, setVal12, initVal12, IdentifierToken, Token, NthStmt)
  MX_SERIALIZE_TEXT(LabelStmt, name, getVal63, setVal63, initVal63, Name, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY(LabelStmt, sub_statement, getVal14, setVal14, initVal14, SubStatement, Stmt, NthStmt)
  MX_SERIALIZE_BOOL(LabelStmt, is_side_entry, getVal16, setVal16, initVal16, IsSideEntry, bool, NthStmt)
  MX_EXIT_SERIALIZE_LabelStmt
MX_END_SERIALIZE_STMT(LabelStmt)
#undef MX_ENTER_SERIALIZE_LabelStmt
#undef MX_EXIT_SERIALIZE_LabelStmt

#ifndef MX_ENTER_SERIALIZE_Expr
#  define MX_ENTER_SERIALIZE_Expr
#endif
#ifndef MX_EXIT_SERIALIZE_Expr
#  define MX_EXIT_SERIALIZE_Expr
#endif

MX_BEGIN_SERIALIZE_STMT(Expr)
  MX_ENTER_SERIALIZE_Expr
  MX_SERIALIZE_BASE(Expr, ValueStmt)
  MX_SERIALIZE_BOOL(Expr, has_side_effects, getVal16, setVal16, initVal16, HasSideEffects, bool, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_casts, getVal11, setVal11, initVal11, IgnoreCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_conversion_operator_single_step, getVal12, setVal12, initVal12, IgnoreConversionOperatorSingleStep, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_imp_casts, getVal14, setVal14, initVal14, IgnoreImpCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_implicit, getVal15, setVal15, initVal15, IgnoreImplicit, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_implicit_as_written, getVal18, setVal18, initVal18, IgnoreImplicitAsWritten, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_parenthesis_base_casts, getVal19, setVal19, initVal19, IgnoreParenthesisBaseCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_parenthesis_casts, getVal20, setVal20, initVal20, IgnoreParenthesisCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_parenthesis_imp_casts, getVal27, setVal27, initVal27, IgnoreParenthesisImpCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_parenthesis_l_value_casts, getVal28, setVal28, initVal28, IgnoreParenthesisLValueCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_parenthesis_noop_casts, getVal29, setVal29, initVal29, IgnoreParenthesisNoopCasts, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_parentheses, getVal30, setVal30, initVal30, IgnoreParentheses, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, ignore_unless_spelled_in_source, getVal31, setVal31, initVal31, IgnoreUnlessSpelledInSource, Expr, NthStmt)
  MX_SERIALIZE_BOOL(Expr, contains_errors, getVal21, setVal21, initVal21, ContainsErrors, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, contains_unexpanded_parameter_pack, getVal22, setVal22, initVal22, ContainsUnexpandedParameterPack, bool, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, best_dynamic_class_type_expression, getVal32, setVal32, initVal32, BestDynamicClassTypeExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, expression_token, getVal33, setVal33, initVal33, ExpressionToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(Expr, obj_c_property, getVal34, setVal34, initVal34, ObjCProperty, ObjCPropertyRefExpr, NthStmt)
  MX_SERIALIZE_ENUM(Expr, object_kind, getVal62, setVal62, initVal62, ObjectKind, ExprObjectKind, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(Expr, referenced_declaration_of_callee, getVal35, setVal35, initVal35, ReferencedDeclarationOfCallee, Decl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(Expr, source_bit_field, getVal36, setVal36, initVal36, SourceBitField, FieldDecl, NthStmt)
  MX_SERIALIZE_ENTITY(Expr, type, getVal37, setVal37, initVal37, Type, Type, NthStmt)
  MX_SERIALIZE_ENUM(Expr, value_kind, getVal72, setVal72, initVal72, ValueKind, ExprValueKind, NthStmt)
  MX_SERIALIZE_BOOL(Expr, has_non_trivial_call, getVal60, setVal60, initVal60, HasNonTrivialCall, bool, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(Expr, is_cxx11_constant_expression, getVal61, setVal61, initVal61, IsCXX11ConstantExpression, bool, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(Expr, is_cxx98_integral_constant_expression, getVal74, setVal74, initVal74, IsCXX98IntegralConstantExpression, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_default_argument, getVal76, setVal76, initVal76, IsDefaultArgument, bool, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(Expr, is_evaluatable, getVal77, setVal77, initVal77, IsEvaluatable, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_gl_value, getVal79, setVal79, initVal79, IsGLValue, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_implicit_cxx_this, getVal80, setVal80, initVal80, IsImplicitCXXThis, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_instantiation_dependent, getVal81, setVal81, initVal81, IsInstantiationDependent, bool, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(Expr, is_integer_constant_expression, getVal82, setVal82, initVal82, IsIntegerConstantExpression, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_known_to_have_boolean_value, getVal84, setVal84, initVal84, IsKnownToHaveBooleanValue, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_l_value, getVal85, setVal85, initVal85, IsLValue, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_objcgc_candidate, getVal86, setVal86, initVal86, IsOBJCGCCandidate, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_obj_c_self_expression, getVal87, setVal87, initVal87, IsObjCSelfExpression, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_ordinary_or_bit_field_object, getVal88, setVal88, initVal88, IsOrdinaryOrBitFieldObject, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_pr_value, getVal89, setVal89, initVal89, IsPRValue, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_read_if_discarded_in_c_plus_plus11, getVal90, setVal90, initVal90, IsReadIfDiscardedInCPlusPlus11, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_type_dependent, getVal91, setVal91, initVal91, IsTypeDependent, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_value_dependent, getVal92, setVal92, initVal92, IsValueDependent, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, is_x_value, getVal93, setVal93, initVal93, IsXValue, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, refers_to_bit_field, getVal94, setVal94, initVal94, RefersToBitField, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, refers_to_global_register_variable, getVal95, setVal95, initVal95, RefersToGlobalRegisterVariable, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, refers_to_matrix_element, getVal96, setVal96, initVal96, RefersToMatrixElement, bool, NthStmt)
  MX_SERIALIZE_BOOL(Expr, refers_to_vector_element, getVal97, setVal97, initVal97, RefersToVectorElement, bool, NthStmt)
  MX_EXIT_SERIALIZE_Expr
MX_END_SERIALIZE_STMT(Expr)
#undef MX_ENTER_SERIALIZE_Expr
#undef MX_EXIT_SERIALIZE_Expr

#ifndef MX_ENTER_SERIALIZE_DesignatedInitUpdateExpr
#  define MX_ENTER_SERIALIZE_DesignatedInitUpdateExpr
#endif
#ifndef MX_EXIT_SERIALIZE_DesignatedInitUpdateExpr
#  define MX_EXIT_SERIALIZE_DesignatedInitUpdateExpr
#endif

MX_BEGIN_SERIALIZE_STMT(DesignatedInitUpdateExpr)
  MX_ENTER_SERIALIZE_DesignatedInitUpdateExpr
  MX_SERIALIZE_BASE(DesignatedInitUpdateExpr, Expr)
  MX_SERIALIZE_ENTITY(DesignatedInitUpdateExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(DesignatedInitUpdateExpr, updater, getVal39, setVal39, initVal39, Updater, InitListExpr, NthStmt)
  MX_EXIT_SERIALIZE_DesignatedInitUpdateExpr
MX_END_SERIALIZE_STMT(DesignatedInitUpdateExpr)
#undef MX_ENTER_SERIALIZE_DesignatedInitUpdateExpr
#undef MX_EXIT_SERIALIZE_DesignatedInitUpdateExpr

#ifndef MX_ENTER_SERIALIZE_DesignatedInitExpr
#  define MX_ENTER_SERIALIZE_DesignatedInitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_DesignatedInitExpr
#  define MX_EXIT_SERIALIZE_DesignatedInitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(DesignatedInitExpr)
  MX_ENTER_SERIALIZE_DesignatedInitExpr
  MX_SERIALIZE_BASE(DesignatedInitExpr, Expr)
  MX_SERIALIZE_ENTITY(DesignatedInitExpr, equal_or_colon_token, getVal40, setVal40, initVal40, EqualOrColonToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DesignatedInitExpr, initializer, getVal41, setVal41, initVal41, Initializer, Expr, NthStmt)
  MX_SERIALIZE_BOOL(DesignatedInitExpr, is_direct_initializer, getVal98, setVal98, initVal98, IsDirectInitializer, bool, NthStmt)
  MX_SERIALIZE_BOOL(DesignatedInitExpr, uses_gnu_syntax, getVal99, setVal99, initVal99, UsesGNUSyntax, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(DesignatedInitExpr, sub_expressions, getVal17, setVal17, initVal17, SubExpressions, Expr, NthStmt)
  MX_EXIT_SERIALIZE_DesignatedInitExpr
MX_END_SERIALIZE_STMT(DesignatedInitExpr)
#undef MX_ENTER_SERIALIZE_DesignatedInitExpr
#undef MX_EXIT_SERIALIZE_DesignatedInitExpr

#ifndef MX_ENTER_SERIALIZE_DependentScopeDeclRefExpr
#  define MX_ENTER_SERIALIZE_DependentScopeDeclRefExpr
#endif
#ifndef MX_EXIT_SERIALIZE_DependentScopeDeclRefExpr
#  define MX_EXIT_SERIALIZE_DependentScopeDeclRefExpr
#endif

MX_BEGIN_SERIALIZE_STMT(DependentScopeDeclRefExpr)
  MX_ENTER_SERIALIZE_DependentScopeDeclRefExpr
  MX_SERIALIZE_BASE(DependentScopeDeclRefExpr, Expr)
  MX_SERIALIZE_ENTITY(DependentScopeDeclRefExpr, l_angle_token, getVal38, setVal38, initVal38, LAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DependentScopeDeclRefExpr, r_angle_token, getVal39, setVal39, initVal39, RAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DependentScopeDeclRefExpr, template_keyword_token, getVal40, setVal40, initVal40, TemplateKeywordToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(DependentScopeDeclRefExpr, has_explicit_template_arguments, getVal98, setVal98, initVal98, HasExplicitTemplateArguments, bool, NthStmt)
  MX_SERIALIZE_BOOL(DependentScopeDeclRefExpr, has_template_keyword, getVal99, setVal99, initVal99, HasTemplateKeyword, bool, NthStmt)
  MX_EXIT_SERIALIZE_DependentScopeDeclRefExpr
MX_END_SERIALIZE_STMT(DependentScopeDeclRefExpr)
#undef MX_ENTER_SERIALIZE_DependentScopeDeclRefExpr
#undef MX_EXIT_SERIALIZE_DependentScopeDeclRefExpr

#ifndef MX_ENTER_SERIALIZE_DependentCoawaitExpr
#  define MX_ENTER_SERIALIZE_DependentCoawaitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_DependentCoawaitExpr
#  define MX_EXIT_SERIALIZE_DependentCoawaitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(DependentCoawaitExpr)
  MX_ENTER_SERIALIZE_DependentCoawaitExpr
  MX_SERIALIZE_BASE(DependentCoawaitExpr, Expr)
  MX_SERIALIZE_ENTITY(DependentCoawaitExpr, keyword_token, getVal38, setVal38, initVal38, KeywordToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DependentCoawaitExpr, operand, getVal39, setVal39, initVal39, Operand, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(DependentCoawaitExpr, operator_coawait_lookup, getVal40, setVal40, initVal40, OperatorCoawaitLookup, UnresolvedLookupExpr, NthStmt)
  MX_EXIT_SERIALIZE_DependentCoawaitExpr
MX_END_SERIALIZE_STMT(DependentCoawaitExpr)
#undef MX_ENTER_SERIALIZE_DependentCoawaitExpr
#undef MX_EXIT_SERIALIZE_DependentCoawaitExpr

#ifndef MX_ENTER_SERIALIZE_DeclRefExpr
#  define MX_ENTER_SERIALIZE_DeclRefExpr
#endif
#ifndef MX_EXIT_SERIALIZE_DeclRefExpr
#  define MX_EXIT_SERIALIZE_DeclRefExpr
#endif

MX_BEGIN_SERIALIZE_STMT(DeclRefExpr)
  MX_ENTER_SERIALIZE_DeclRefExpr
  MX_SERIALIZE_BASE(DeclRefExpr, Expr)
  MX_SERIALIZE_ENTITY(DeclRefExpr, declaration, getVal38, setVal38, initVal38, Declaration, ValueDecl, NthStmt)
  MX_SERIALIZE_ENTITY(DeclRefExpr, found_declaration, getVal39, setVal39, initVal39, FoundDeclaration, NamedDecl, NthStmt)
  MX_SERIALIZE_ENTITY(DeclRefExpr, l_angle_token, getVal40, setVal40, initVal40, LAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DeclRefExpr, r_angle_token, getVal41, setVal41, initVal41, RAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(DeclRefExpr, template_keyword_token, getVal42, setVal42, initVal42, TemplateKeywordToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(DeclRefExpr, had_multiple_candidates, getVal98, setVal98, initVal98, HadMultipleCandidates, bool, NthStmt)
  MX_SERIALIZE_BOOL(DeclRefExpr, has_explicit_template_arguments, getVal99, setVal99, initVal99, HasExplicitTemplateArguments, bool, NthStmt)
  MX_SERIALIZE_BOOL(DeclRefExpr, has_qualifier, getVal100, setVal100, initVal100, HasQualifier, bool, NthStmt)
  MX_SERIALIZE_BOOL(DeclRefExpr, has_template_kw_and_arguments_info, getVal101, setVal101, initVal101, HasTemplateKWAndArgumentsInfo, bool, NthStmt)
  MX_SERIALIZE_BOOL(DeclRefExpr, has_template_keyword, getVal102, setVal102, initVal102, HasTemplateKeyword, bool, NthStmt)
  MX_SERIALIZE_ENUM(DeclRefExpr, is_non_odr_use, getVal103, setVal103, initVal103, IsNonOdrUse, NonOdrUseReason, NthStmt)
  MX_SERIALIZE_BOOL(DeclRefExpr, refers_to_enclosing_variable_or_capture, getVal104, setVal104, initVal104, RefersToEnclosingVariableOrCapture, bool, NthStmt)
  MX_EXIT_SERIALIZE_DeclRefExpr
MX_END_SERIALIZE_STMT(DeclRefExpr)
#undef MX_ENTER_SERIALIZE_DeclRefExpr
#undef MX_EXIT_SERIALIZE_DeclRefExpr

#ifndef MX_ENTER_SERIALIZE_CoroutineSuspendExpr
#  define MX_ENTER_SERIALIZE_CoroutineSuspendExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CoroutineSuspendExpr
#  define MX_EXIT_SERIALIZE_CoroutineSuspendExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CoroutineSuspendExpr)
  MX_ENTER_SERIALIZE_CoroutineSuspendExpr
  MX_SERIALIZE_BASE(CoroutineSuspendExpr, Expr)
  MX_SERIALIZE_ENTITY(CoroutineSuspendExpr, common_expression, getVal38, setVal38, initVal38, CommonExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineSuspendExpr, keyword_token, getVal39, setVal39, initVal39, KeywordToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineSuspendExpr, opaque_value, getVal40, setVal40, initVal40, OpaqueValue, OpaqueValueExpr, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineSuspendExpr, ready_expression, getVal41, setVal41, initVal41, ReadyExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineSuspendExpr, resume_expression, getVal42, setVal42, initVal42, ResumeExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CoroutineSuspendExpr, suspend_expression, getVal43, setVal43, initVal43, SuspendExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_CoroutineSuspendExpr
MX_END_SERIALIZE_STMT(CoroutineSuspendExpr)
#undef MX_ENTER_SERIALIZE_CoroutineSuspendExpr
#undef MX_EXIT_SERIALIZE_CoroutineSuspendExpr

#ifndef MX_ENTER_SERIALIZE_CoawaitExpr
#  define MX_ENTER_SERIALIZE_CoawaitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CoawaitExpr
#  define MX_EXIT_SERIALIZE_CoawaitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CoawaitExpr)
  MX_ENTER_SERIALIZE_CoawaitExpr
  MX_SERIALIZE_BASE(CoawaitExpr, CoroutineSuspendExpr)
  MX_SERIALIZE_ENTITY(CoawaitExpr, operand, getVal44, setVal44, initVal44, Operand, Expr, NthStmt)
  MX_SERIALIZE_BOOL(CoawaitExpr, is_implicit, getVal98, setVal98, initVal98, IsImplicit, bool, NthStmt)
  MX_EXIT_SERIALIZE_CoawaitExpr
MX_END_SERIALIZE_STMT(CoawaitExpr)
#undef MX_ENTER_SERIALIZE_CoawaitExpr
#undef MX_EXIT_SERIALIZE_CoawaitExpr

#ifndef MX_ENTER_SERIALIZE_CoyieldExpr
#  define MX_ENTER_SERIALIZE_CoyieldExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CoyieldExpr
#  define MX_EXIT_SERIALIZE_CoyieldExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CoyieldExpr)
  MX_ENTER_SERIALIZE_CoyieldExpr
  MX_SERIALIZE_BASE(CoyieldExpr, CoroutineSuspendExpr)
  MX_SERIALIZE_ENTITY(CoyieldExpr, operand, getVal44, setVal44, initVal44, Operand, Expr, NthStmt)
  MX_EXIT_SERIALIZE_CoyieldExpr
MX_END_SERIALIZE_STMT(CoyieldExpr)
#undef MX_ENTER_SERIALIZE_CoyieldExpr
#undef MX_EXIT_SERIALIZE_CoyieldExpr

#ifndef MX_ENTER_SERIALIZE_ConvertVectorExpr
#  define MX_ENTER_SERIALIZE_ConvertVectorExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ConvertVectorExpr
#  define MX_EXIT_SERIALIZE_ConvertVectorExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ConvertVectorExpr)
  MX_ENTER_SERIALIZE_ConvertVectorExpr
  MX_SERIALIZE_BASE(ConvertVectorExpr, Expr)
  MX_SERIALIZE_ENTITY(ConvertVectorExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ConvertVectorExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ConvertVectorExpr, src_expression, getVal40, setVal40, initVal40, SrcExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ConvertVectorExpr, type_source_info, getVal41, setVal41, initVal41, TypeSourceInfo, Type, NthStmt)
  MX_EXIT_SERIALIZE_ConvertVectorExpr
MX_END_SERIALIZE_STMT(ConvertVectorExpr)
#undef MX_ENTER_SERIALIZE_ConvertVectorExpr
#undef MX_EXIT_SERIALIZE_ConvertVectorExpr

#ifndef MX_ENTER_SERIALIZE_ConceptSpecializationExpr
#  define MX_ENTER_SERIALIZE_ConceptSpecializationExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ConceptSpecializationExpr
#  define MX_EXIT_SERIALIZE_ConceptSpecializationExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ConceptSpecializationExpr)
  MX_ENTER_SERIALIZE_ConceptSpecializationExpr
  MX_SERIALIZE_BASE(ConceptSpecializationExpr, Expr)
  MX_SERIALIZE_PSEUDO_LIST(ConceptSpecializationExpr, template_arguments, getVal105, setVal105, initVal105, TemplateArguments, TemplateArgument, NthStmt)
  MX_SERIALIZE_BOOL(ConceptSpecializationExpr, is_satisfied, getVal98, setVal98, initVal98, IsSatisfied, bool, NthStmt)
  MX_EXIT_SERIALIZE_ConceptSpecializationExpr
MX_END_SERIALIZE_STMT(ConceptSpecializationExpr)
#undef MX_ENTER_SERIALIZE_ConceptSpecializationExpr
#undef MX_EXIT_SERIALIZE_ConceptSpecializationExpr

#ifndef MX_ENTER_SERIALIZE_CompoundLiteralExpr
#  define MX_ENTER_SERIALIZE_CompoundLiteralExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CompoundLiteralExpr
#  define MX_EXIT_SERIALIZE_CompoundLiteralExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CompoundLiteralExpr)
  MX_ENTER_SERIALIZE_CompoundLiteralExpr
  MX_SERIALIZE_BASE(CompoundLiteralExpr, Expr)
  MX_SERIALIZE_ENTITY(CompoundLiteralExpr, initializer, getVal38, setVal38, initVal38, Initializer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CompoundLiteralExpr, l_paren_token, getVal39, setVal39, initVal39, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CompoundLiteralExpr, type_source_info, getVal40, setVal40, initVal40, TypeSourceInfo, Type, NthStmt)
  MX_SERIALIZE_BOOL(CompoundLiteralExpr, is_file_scope, getVal98, setVal98, initVal98, IsFileScope, bool, NthStmt)
  MX_EXIT_SERIALIZE_CompoundLiteralExpr
MX_END_SERIALIZE_STMT(CompoundLiteralExpr)
#undef MX_ENTER_SERIALIZE_CompoundLiteralExpr
#undef MX_EXIT_SERIALIZE_CompoundLiteralExpr

#ifndef MX_ENTER_SERIALIZE_ChooseExpr
#  define MX_ENTER_SERIALIZE_ChooseExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ChooseExpr
#  define MX_EXIT_SERIALIZE_ChooseExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ChooseExpr)
  MX_ENTER_SERIALIZE_ChooseExpr
  MX_SERIALIZE_BASE(ChooseExpr, Expr)
  MX_SERIALIZE_ENTITY(ChooseExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ChooseExpr, chosen_sub_expression, getVal39, setVal39, initVal39, ChosenSubExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ChooseExpr, condition, getVal40, setVal40, initVal40, Condition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ChooseExpr, lhs, getVal41, setVal41, initVal41, LHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ChooseExpr, rhs, getVal42, setVal42, initVal42, RHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ChooseExpr, r_paren_token, getVal43, setVal43, initVal43, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(ChooseExpr, is_condition_dependent, getVal98, setVal98, initVal98, IsConditionDependent, bool, NthStmt)
  MX_SERIALIZE_BOOL(ChooseExpr, is_condition_true, getVal99, setVal99, initVal99, IsConditionTrue, bool, NthStmt)
  MX_EXIT_SERIALIZE_ChooseExpr
MX_END_SERIALIZE_STMT(ChooseExpr)
#undef MX_ENTER_SERIALIZE_ChooseExpr
#undef MX_EXIT_SERIALIZE_ChooseExpr

#ifndef MX_ENTER_SERIALIZE_CharacterLiteral
#  define MX_ENTER_SERIALIZE_CharacterLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_CharacterLiteral
#  define MX_EXIT_SERIALIZE_CharacterLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(CharacterLiteral)
  MX_ENTER_SERIALIZE_CharacterLiteral
  MX_SERIALIZE_BASE(CharacterLiteral, Expr)
  MX_SERIALIZE_ENTITY(CharacterLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_EXIT_SERIALIZE_CharacterLiteral
MX_END_SERIALIZE_STMT(CharacterLiteral)
#undef MX_ENTER_SERIALIZE_CharacterLiteral
#undef MX_EXIT_SERIALIZE_CharacterLiteral

#ifndef MX_ENTER_SERIALIZE_CastExpr
#  define MX_ENTER_SERIALIZE_CastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CastExpr
#  define MX_EXIT_SERIALIZE_CastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CastExpr)
  MX_ENTER_SERIALIZE_CastExpr
  MX_SERIALIZE_BASE(CastExpr, Expr)
  MX_SERIALIZE_ENUM(CastExpr, cast_kind, getVal103, setVal103, initVal103, CastKind, CastKind, NthStmt)
  MX_SERIALIZE_TEXT(CastExpr, cast_kind_name, getVal63, setVal63, initVal63, CastKindName, basic_string_view, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CastExpr, conversion_function, getVal38, setVal38, initVal38, ConversionFunction, NamedDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CastExpr, sub_expression, getVal39, setVal39, initVal39, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CastExpr, sub_expression_as_written, getVal40, setVal40, initVal40, SubExpressionAsWritten, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CastExpr, target_union_field, getVal41, setVal41, initVal41, TargetUnionField, FieldDecl, NthStmt)
  MX_SERIALIZE_BOOL(CastExpr, has_stored_fp_features, getVal100, setVal100, initVal100, HasStoredFPFeatures, bool, NthStmt)
  MX_EXIT_SERIALIZE_CastExpr
MX_END_SERIALIZE_STMT(CastExpr)
#undef MX_ENTER_SERIALIZE_CastExpr
#undef MX_EXIT_SERIALIZE_CastExpr

#ifndef MX_ENTER_SERIALIZE_ImplicitCastExpr
#  define MX_ENTER_SERIALIZE_ImplicitCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ImplicitCastExpr
#  define MX_EXIT_SERIALIZE_ImplicitCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ImplicitCastExpr)
  MX_ENTER_SERIALIZE_ImplicitCastExpr
  MX_SERIALIZE_BASE(ImplicitCastExpr, CastExpr)
  MX_SERIALIZE_BOOL(ImplicitCastExpr, is_part_of_explicit_cast, getVal101, setVal101, initVal101, IsPartOfExplicitCast, bool, NthStmt)
  MX_EXIT_SERIALIZE_ImplicitCastExpr
MX_END_SERIALIZE_STMT(ImplicitCastExpr)
#undef MX_ENTER_SERIALIZE_ImplicitCastExpr
#undef MX_EXIT_SERIALIZE_ImplicitCastExpr

#ifndef MX_ENTER_SERIALIZE_ExplicitCastExpr
#  define MX_ENTER_SERIALIZE_ExplicitCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ExplicitCastExpr
#  define MX_EXIT_SERIALIZE_ExplicitCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ExplicitCastExpr)
  MX_ENTER_SERIALIZE_ExplicitCastExpr
  MX_SERIALIZE_BASE(ExplicitCastExpr, CastExpr)
  MX_SERIALIZE_ENTITY(ExplicitCastExpr, type_as_written, getVal42, setVal42, initVal42, TypeAsWritten, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ExplicitCastExpr, type_info_as_written, getVal43, setVal43, initVal43, TypeInfoAsWritten, Type, NthStmt)
  MX_EXIT_SERIALIZE_ExplicitCastExpr
MX_END_SERIALIZE_STMT(ExplicitCastExpr)
#undef MX_ENTER_SERIALIZE_ExplicitCastExpr
#undef MX_EXIT_SERIALIZE_ExplicitCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXNamedCastExpr
#  define MX_ENTER_SERIALIZE_CXXNamedCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXNamedCastExpr
#  define MX_EXIT_SERIALIZE_CXXNamedCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXNamedCastExpr)
  MX_ENTER_SERIALIZE_CXXNamedCastExpr
  MX_SERIALIZE_BASE(CXXNamedCastExpr, ExplicitCastExpr)
  MX_SERIALIZE_TEXT(CXXNamedCastExpr, cast_name, getVal68, setVal68, initVal68, CastName, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY(CXXNamedCastExpr, operator_token, getVal46, setVal46, initVal46, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXNamedCastExpr, r_paren_token, getVal47, setVal47, initVal47, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_CXXNamedCastExpr
MX_END_SERIALIZE_STMT(CXXNamedCastExpr)
#undef MX_ENTER_SERIALIZE_CXXNamedCastExpr
#undef MX_EXIT_SERIALIZE_CXXNamedCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXDynamicCastExpr
#  define MX_ENTER_SERIALIZE_CXXDynamicCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDynamicCastExpr
#  define MX_EXIT_SERIALIZE_CXXDynamicCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXDynamicCastExpr)
  MX_ENTER_SERIALIZE_CXXDynamicCastExpr
  MX_SERIALIZE_BASE(CXXDynamicCastExpr, CXXNamedCastExpr)
  MX_SERIALIZE_BOOL(CXXDynamicCastExpr, is_always_null, getVal101, setVal101, initVal101, IsAlwaysNull, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXDynamicCastExpr
MX_END_SERIALIZE_STMT(CXXDynamicCastExpr)
#undef MX_ENTER_SERIALIZE_CXXDynamicCastExpr
#undef MX_EXIT_SERIALIZE_CXXDynamicCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXConstCastExpr
#  define MX_ENTER_SERIALIZE_CXXConstCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXConstCastExpr
#  define MX_EXIT_SERIALIZE_CXXConstCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXConstCastExpr)
  MX_ENTER_SERIALIZE_CXXConstCastExpr
  MX_SERIALIZE_BASE(CXXConstCastExpr, CXXNamedCastExpr)
  MX_EXIT_SERIALIZE_CXXConstCastExpr
MX_END_SERIALIZE_STMT(CXXConstCastExpr)
#undef MX_ENTER_SERIALIZE_CXXConstCastExpr
#undef MX_EXIT_SERIALIZE_CXXConstCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXAddrspaceCastExpr
#  define MX_ENTER_SERIALIZE_CXXAddrspaceCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXAddrspaceCastExpr
#  define MX_EXIT_SERIALIZE_CXXAddrspaceCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXAddrspaceCastExpr)
  MX_ENTER_SERIALIZE_CXXAddrspaceCastExpr
  MX_SERIALIZE_BASE(CXXAddrspaceCastExpr, CXXNamedCastExpr)
  MX_EXIT_SERIALIZE_CXXAddrspaceCastExpr
MX_END_SERIALIZE_STMT(CXXAddrspaceCastExpr)
#undef MX_ENTER_SERIALIZE_CXXAddrspaceCastExpr
#undef MX_EXIT_SERIALIZE_CXXAddrspaceCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXStaticCastExpr
#  define MX_ENTER_SERIALIZE_CXXStaticCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXStaticCastExpr
#  define MX_EXIT_SERIALIZE_CXXStaticCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXStaticCastExpr)
  MX_ENTER_SERIALIZE_CXXStaticCastExpr
  MX_SERIALIZE_BASE(CXXStaticCastExpr, CXXNamedCastExpr)
  MX_EXIT_SERIALIZE_CXXStaticCastExpr
MX_END_SERIALIZE_STMT(CXXStaticCastExpr)
#undef MX_ENTER_SERIALIZE_CXXStaticCastExpr
#undef MX_EXIT_SERIALIZE_CXXStaticCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXReinterpretCastExpr
#  define MX_ENTER_SERIALIZE_CXXReinterpretCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXReinterpretCastExpr
#  define MX_EXIT_SERIALIZE_CXXReinterpretCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXReinterpretCastExpr)
  MX_ENTER_SERIALIZE_CXXReinterpretCastExpr
  MX_SERIALIZE_BASE(CXXReinterpretCastExpr, CXXNamedCastExpr)
  MX_EXIT_SERIALIZE_CXXReinterpretCastExpr
MX_END_SERIALIZE_STMT(CXXReinterpretCastExpr)
#undef MX_ENTER_SERIALIZE_CXXReinterpretCastExpr
#undef MX_EXIT_SERIALIZE_CXXReinterpretCastExpr

#ifndef MX_ENTER_SERIALIZE_CXXFunctionalCastExpr
#  define MX_ENTER_SERIALIZE_CXXFunctionalCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXFunctionalCastExpr
#  define MX_EXIT_SERIALIZE_CXXFunctionalCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXFunctionalCastExpr)
  MX_ENTER_SERIALIZE_CXXFunctionalCastExpr
  MX_SERIALIZE_BASE(CXXFunctionalCastExpr, ExplicitCastExpr)
  MX_SERIALIZE_ENTITY(CXXFunctionalCastExpr, l_paren_token, getVal44, setVal44, initVal44, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFunctionalCastExpr, r_paren_token, getVal45, setVal45, initVal45, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXFunctionalCastExpr, is_list_initialization, getVal101, setVal101, initVal101, IsListInitialization, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXFunctionalCastExpr
MX_END_SERIALIZE_STMT(CXXFunctionalCastExpr)
#undef MX_ENTER_SERIALIZE_CXXFunctionalCastExpr
#undef MX_EXIT_SERIALIZE_CXXFunctionalCastExpr

#ifndef MX_ENTER_SERIALIZE_CStyleCastExpr
#  define MX_ENTER_SERIALIZE_CStyleCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CStyleCastExpr
#  define MX_EXIT_SERIALIZE_CStyleCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CStyleCastExpr)
  MX_ENTER_SERIALIZE_CStyleCastExpr
  MX_SERIALIZE_BASE(CStyleCastExpr, ExplicitCastExpr)
  MX_SERIALIZE_ENTITY(CStyleCastExpr, l_paren_token, getVal44, setVal44, initVal44, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CStyleCastExpr, r_paren_token, getVal45, setVal45, initVal45, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_CStyleCastExpr
MX_END_SERIALIZE_STMT(CStyleCastExpr)
#undef MX_ENTER_SERIALIZE_CStyleCastExpr
#undef MX_EXIT_SERIALIZE_CStyleCastExpr

#ifndef MX_ENTER_SERIALIZE_BuiltinBitCastExpr
#  define MX_ENTER_SERIALIZE_BuiltinBitCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_BuiltinBitCastExpr
#  define MX_EXIT_SERIALIZE_BuiltinBitCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(BuiltinBitCastExpr)
  MX_ENTER_SERIALIZE_BuiltinBitCastExpr
  MX_SERIALIZE_BASE(BuiltinBitCastExpr, ExplicitCastExpr)
  MX_EXIT_SERIALIZE_BuiltinBitCastExpr
MX_END_SERIALIZE_STMT(BuiltinBitCastExpr)
#undef MX_ENTER_SERIALIZE_BuiltinBitCastExpr
#undef MX_EXIT_SERIALIZE_BuiltinBitCastExpr

#ifndef MX_ENTER_SERIALIZE_ObjCBridgedCastExpr
#  define MX_ENTER_SERIALIZE_ObjCBridgedCastExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCBridgedCastExpr
#  define MX_EXIT_SERIALIZE_ObjCBridgedCastExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCBridgedCastExpr)
  MX_ENTER_SERIALIZE_ObjCBridgedCastExpr
  MX_SERIALIZE_BASE(ObjCBridgedCastExpr, ExplicitCastExpr)
  MX_SERIALIZE_ENTITY(ObjCBridgedCastExpr, bridge_keyword_token, getVal44, setVal44, initVal44, BridgeKeywordToken, Token, NthStmt)
  MX_SERIALIZE_ENUM(ObjCBridgedCastExpr, bridge_kind, getVal106, setVal106, initVal106, BridgeKind, ObjCBridgeCastKind, NthStmt)
  MX_SERIALIZE_TEXT(ObjCBridgedCastExpr, bridge_kind_name, getVal68, setVal68, initVal68, BridgeKindName, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCBridgedCastExpr, l_paren_token, getVal45, setVal45, initVal45, LParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCBridgedCastExpr
MX_END_SERIALIZE_STMT(ObjCBridgedCastExpr)
#undef MX_ENTER_SERIALIZE_ObjCBridgedCastExpr
#undef MX_EXIT_SERIALIZE_ObjCBridgedCastExpr

#ifndef MX_ENTER_SERIALIZE_CallExpr
#  define MX_ENTER_SERIALIZE_CallExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CallExpr
#  define MX_EXIT_SERIALIZE_CallExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CallExpr)
  MX_ENTER_SERIALIZE_CallExpr
  MX_SERIALIZE_BASE(CallExpr, Expr)
  MX_SERIALIZE_ENTITY_LIST(CallExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_SERIALIZE_ENUM(CallExpr, adl_call_kind, getVal103, setVal103, initVal103, ADLCallKind, CallExprADLCallKind, NthStmt)
  MX_SERIALIZE_ENTITY(CallExpr, call_return_type, getVal38, setVal38, initVal38, CallReturnType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CallExpr, callee, getVal39, setVal39, initVal39, Callee, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CallExpr, callee_declaration, getVal40, setVal40, initVal40, CalleeDeclaration, Decl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CallExpr, direct_callee, getVal41, setVal41, initVal41, DirectCallee, FunctionDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CallExpr, r_paren_token, getVal42, setVal42, initVal42, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CallExpr, has_stored_fp_features, getVal100, setVal100, initVal100, HasStoredFPFeatures, bool, NthStmt)
  MX_SERIALIZE_BOOL(CallExpr, has_unused_result_attribute, getVal101, setVal101, initVal101, HasUnusedResultAttribute, bool, NthStmt)
  MX_SERIALIZE_BOOL(CallExpr, is_builtin_assume_false, getVal102, setVal102, initVal102, IsBuiltinAssumeFalse, bool, NthStmt)
  MX_SERIALIZE_BOOL(CallExpr, is_call_to_std_move, getVal104, setVal104, initVal104, IsCallToStdMove, bool, NthStmt)
  MX_SERIALIZE_BOOL(CallExpr, is_unevaluated_builtin_call, getVal107, setVal107, initVal107, IsUnevaluatedBuiltinCall, bool, NthStmt)
  MX_SERIALIZE_BOOL(CallExpr, uses_adl, getVal108, setVal108, initVal108, UsesADL, bool, NthStmt)
  MX_EXIT_SERIALIZE_CallExpr
MX_END_SERIALIZE_STMT(CallExpr)
#undef MX_ENTER_SERIALIZE_CallExpr
#undef MX_EXIT_SERIALIZE_CallExpr

#ifndef MX_ENTER_SERIALIZE_CXXOperatorCallExpr
#  define MX_ENTER_SERIALIZE_CXXOperatorCallExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXOperatorCallExpr
#  define MX_EXIT_SERIALIZE_CXXOperatorCallExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXOperatorCallExpr)
  MX_ENTER_SERIALIZE_CXXOperatorCallExpr
  MX_SERIALIZE_BASE(CXXOperatorCallExpr, CallExpr)
  MX_SERIALIZE_ENUM(CXXOperatorCallExpr, operator_, getVal106, setVal106, initVal106, Operator, OverloadedOperatorKind, NthStmt)
  MX_SERIALIZE_ENTITY(CXXOperatorCallExpr, operator_token, getVal43, setVal43, initVal43, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXOperatorCallExpr, is_assignment_operation, getVal109, setVal109, initVal109, IsAssignmentOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXOperatorCallExpr, is_comparison_operation, getVal110, setVal110, initVal110, IsComparisonOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXOperatorCallExpr, is_infix_binary_operation, getVal111, setVal111, initVal111, IsInfixBinaryOperation, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXOperatorCallExpr
MX_END_SERIALIZE_STMT(CXXOperatorCallExpr)
#undef MX_ENTER_SERIALIZE_CXXOperatorCallExpr
#undef MX_EXIT_SERIALIZE_CXXOperatorCallExpr

#ifndef MX_ENTER_SERIALIZE_CXXMemberCallExpr
#  define MX_ENTER_SERIALIZE_CXXMemberCallExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXMemberCallExpr
#  define MX_EXIT_SERIALIZE_CXXMemberCallExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXMemberCallExpr)
  MX_ENTER_SERIALIZE_CXXMemberCallExpr
  MX_SERIALIZE_BASE(CXXMemberCallExpr, CallExpr)
  MX_SERIALIZE_ENTITY(CXXMemberCallExpr, implicit_object_argument, getVal43, setVal43, initVal43, ImplicitObjectArgument, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXMemberCallExpr, method_declaration, getVal44, setVal44, initVal44, MethodDeclaration, CXXMethodDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXMemberCallExpr, object_type, getVal45, setVal45, initVal45, ObjectType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXMemberCallExpr, record_declaration, getVal46, setVal46, initVal46, RecordDeclaration, CXXRecordDecl, NthStmt)
  MX_EXIT_SERIALIZE_CXXMemberCallExpr
MX_END_SERIALIZE_STMT(CXXMemberCallExpr)
#undef MX_ENTER_SERIALIZE_CXXMemberCallExpr
#undef MX_EXIT_SERIALIZE_CXXMemberCallExpr

#ifndef MX_ENTER_SERIALIZE_CUDAKernelCallExpr
#  define MX_ENTER_SERIALIZE_CUDAKernelCallExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CUDAKernelCallExpr
#  define MX_EXIT_SERIALIZE_CUDAKernelCallExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CUDAKernelCallExpr)
  MX_ENTER_SERIALIZE_CUDAKernelCallExpr
  MX_SERIALIZE_BASE(CUDAKernelCallExpr, CallExpr)
  MX_SERIALIZE_ENTITY(CUDAKernelCallExpr, config, getVal43, setVal43, initVal43, Config, CallExpr, NthStmt)
  MX_EXIT_SERIALIZE_CUDAKernelCallExpr
MX_END_SERIALIZE_STMT(CUDAKernelCallExpr)
#undef MX_ENTER_SERIALIZE_CUDAKernelCallExpr
#undef MX_EXIT_SERIALIZE_CUDAKernelCallExpr

#ifndef MX_ENTER_SERIALIZE_UserDefinedLiteral
#  define MX_ENTER_SERIALIZE_UserDefinedLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_UserDefinedLiteral
#  define MX_EXIT_SERIALIZE_UserDefinedLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(UserDefinedLiteral)
  MX_ENTER_SERIALIZE_UserDefinedLiteral
  MX_SERIALIZE_BASE(UserDefinedLiteral, CallExpr)
  MX_SERIALIZE_ENTITY(UserDefinedLiteral, cooked_literal, getVal43, setVal43, initVal43, CookedLiteral, Expr, NthStmt)
  MX_SERIALIZE_ENUM(UserDefinedLiteral, literal_operator_kind, getVal106, setVal106, initVal106, LiteralOperatorKind, UserDefinedLiteralLiteralOperatorKind, NthStmt)
  MX_SERIALIZE_ENTITY(UserDefinedLiteral, ud_suffix_token, getVal44, setVal44, initVal44, UDSuffixToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_UserDefinedLiteral
MX_END_SERIALIZE_STMT(UserDefinedLiteral)
#undef MX_ENTER_SERIALIZE_UserDefinedLiteral
#undef MX_EXIT_SERIALIZE_UserDefinedLiteral

#ifndef MX_ENTER_SERIALIZE_CXXUuidofExpr
#  define MX_ENTER_SERIALIZE_CXXUuidofExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXUuidofExpr
#  define MX_EXIT_SERIALIZE_CXXUuidofExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXUuidofExpr)
  MX_ENTER_SERIALIZE_CXXUuidofExpr
  MX_SERIALIZE_BASE(CXXUuidofExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXUuidofExpr, expression_operand, getVal38, setVal38, initVal38, ExpressionOperand, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUuidofExpr, guid_declaration, getVal39, setVal39, initVal39, GuidDeclaration, MSGuidDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUuidofExpr, type_operand, getVal40, setVal40, initVal40, TypeOperand, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUuidofExpr, type_operand_source_info, getVal41, setVal41, initVal41, TypeOperandSourceInfo, Type, NthStmt)
  MX_SERIALIZE_BOOL(CXXUuidofExpr, is_type_operand, getVal99, setVal99, initVal99, IsTypeOperand, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXUuidofExpr
MX_END_SERIALIZE_STMT(CXXUuidofExpr)
#undef MX_ENTER_SERIALIZE_CXXUuidofExpr
#undef MX_EXIT_SERIALIZE_CXXUuidofExpr

#ifndef MX_ENTER_SERIALIZE_CXXUnresolvedConstructExpr
#  define MX_ENTER_SERIALIZE_CXXUnresolvedConstructExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXUnresolvedConstructExpr
#  define MX_EXIT_SERIALIZE_CXXUnresolvedConstructExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXUnresolvedConstructExpr)
  MX_ENTER_SERIALIZE_CXXUnresolvedConstructExpr
  MX_SERIALIZE_BASE(CXXUnresolvedConstructExpr, Expr)
  MX_SERIALIZE_ENTITY_LIST(CXXUnresolvedConstructExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUnresolvedConstructExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUnresolvedConstructExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUnresolvedConstructExpr, type_as_written, getVal40, setVal40, initVal40, TypeAsWritten, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXUnresolvedConstructExpr, type_source_info, getVal41, setVal41, initVal41, TypeSourceInfo, Type, NthStmt)
  MX_SERIALIZE_BOOL(CXXUnresolvedConstructExpr, is_list_initialization, getVal98, setVal98, initVal98, IsListInitialization, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXUnresolvedConstructExpr
MX_END_SERIALIZE_STMT(CXXUnresolvedConstructExpr)
#undef MX_ENTER_SERIALIZE_CXXUnresolvedConstructExpr
#undef MX_EXIT_SERIALIZE_CXXUnresolvedConstructExpr

#ifndef MX_ENTER_SERIALIZE_CXXTypeidExpr
#  define MX_ENTER_SERIALIZE_CXXTypeidExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXTypeidExpr
#  define MX_EXIT_SERIALIZE_CXXTypeidExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXTypeidExpr)
  MX_ENTER_SERIALIZE_CXXTypeidExpr
  MX_SERIALIZE_BASE(CXXTypeidExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXTypeidExpr, expression_operand, getVal38, setVal38, initVal38, ExpressionOperand, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXTypeidExpr, type_operand, getVal39, setVal39, initVal39, TypeOperand, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXTypeidExpr, type_operand_source_info, getVal40, setVal40, initVal40, TypeOperandSourceInfo, Type, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXTypeidExpr, is_most_derived, getVal99, setVal99, initVal99, IsMostDerived, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXTypeidExpr, is_potentially_evaluated, getVal101, setVal101, initVal101, IsPotentiallyEvaluated, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXTypeidExpr, is_type_operand, getVal102, setVal102, initVal102, IsTypeOperand, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXTypeidExpr
MX_END_SERIALIZE_STMT(CXXTypeidExpr)
#undef MX_ENTER_SERIALIZE_CXXTypeidExpr
#undef MX_EXIT_SERIALIZE_CXXTypeidExpr

#ifndef MX_ENTER_SERIALIZE_CXXThrowExpr
#  define MX_ENTER_SERIALIZE_CXXThrowExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXThrowExpr
#  define MX_EXIT_SERIALIZE_CXXThrowExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXThrowExpr)
  MX_ENTER_SERIALIZE_CXXThrowExpr
  MX_SERIALIZE_BASE(CXXThrowExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXThrowExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXThrowExpr, throw_token, getVal39, setVal39, initVal39, ThrowToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXThrowExpr, is_thrown_variable_in_scope, getVal99, setVal99, initVal99, IsThrownVariableInScope, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXThrowExpr
MX_END_SERIALIZE_STMT(CXXThrowExpr)
#undef MX_ENTER_SERIALIZE_CXXThrowExpr
#undef MX_EXIT_SERIALIZE_CXXThrowExpr

#ifndef MX_ENTER_SERIALIZE_CXXThisExpr
#  define MX_ENTER_SERIALIZE_CXXThisExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXThisExpr
#  define MX_EXIT_SERIALIZE_CXXThisExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXThisExpr)
  MX_ENTER_SERIALIZE_CXXThisExpr
  MX_SERIALIZE_BASE(CXXThisExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXThisExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXThisExpr, is_implicit, getVal98, setVal98, initVal98, IsImplicit, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXThisExpr
MX_END_SERIALIZE_STMT(CXXThisExpr)
#undef MX_ENTER_SERIALIZE_CXXThisExpr
#undef MX_EXIT_SERIALIZE_CXXThisExpr

#ifndef MX_ENTER_SERIALIZE_CXXStdInitializerListExpr
#  define MX_ENTER_SERIALIZE_CXXStdInitializerListExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXStdInitializerListExpr
#  define MX_EXIT_SERIALIZE_CXXStdInitializerListExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXStdInitializerListExpr)
  MX_ENTER_SERIALIZE_CXXStdInitializerListExpr
  MX_SERIALIZE_BASE(CXXStdInitializerListExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXStdInitializerListExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_CXXStdInitializerListExpr
MX_END_SERIALIZE_STMT(CXXStdInitializerListExpr)
#undef MX_ENTER_SERIALIZE_CXXStdInitializerListExpr
#undef MX_EXIT_SERIALIZE_CXXStdInitializerListExpr

#ifndef MX_ENTER_SERIALIZE_CXXScalarValueInitExpr
#  define MX_ENTER_SERIALIZE_CXXScalarValueInitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXScalarValueInitExpr
#  define MX_EXIT_SERIALIZE_CXXScalarValueInitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXScalarValueInitExpr)
  MX_ENTER_SERIALIZE_CXXScalarValueInitExpr
  MX_SERIALIZE_BASE(CXXScalarValueInitExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXScalarValueInitExpr, r_paren_token, getVal38, setVal38, initVal38, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXScalarValueInitExpr, type_source_info, getVal39, setVal39, initVal39, TypeSourceInfo, Type, NthStmt)
  MX_EXIT_SERIALIZE_CXXScalarValueInitExpr
MX_END_SERIALIZE_STMT(CXXScalarValueInitExpr)
#undef MX_ENTER_SERIALIZE_CXXScalarValueInitExpr
#undef MX_EXIT_SERIALIZE_CXXScalarValueInitExpr

#ifndef MX_ENTER_SERIALIZE_CXXRewrittenBinaryOperator
#  define MX_ENTER_SERIALIZE_CXXRewrittenBinaryOperator
#endif
#ifndef MX_EXIT_SERIALIZE_CXXRewrittenBinaryOperator
#  define MX_EXIT_SERIALIZE_CXXRewrittenBinaryOperator
#endif

MX_BEGIN_SERIALIZE_STMT(CXXRewrittenBinaryOperator)
  MX_ENTER_SERIALIZE_CXXRewrittenBinaryOperator
  MX_SERIALIZE_BASE(CXXRewrittenBinaryOperator, Expr)
  MX_SERIALIZE_ENTITY(CXXRewrittenBinaryOperator, lhs, getVal38, setVal38, initVal38, LHS, Expr, NthStmt)
  MX_SERIALIZE_ENUM(CXXRewrittenBinaryOperator, opcode, getVal103, setVal103, initVal103, Opcode, BinaryOperatorKind, NthStmt)
  MX_SERIALIZE_TEXT(CXXRewrittenBinaryOperator, opcode_string, getVal63, setVal63, initVal63, OpcodeString, basic_string_view, NthStmt)
  MX_SERIALIZE_ENUM(CXXRewrittenBinaryOperator, operator_, getVal106, setVal106, initVal106, Operator, BinaryOperatorKind, NthStmt)
  MX_SERIALIZE_ENTITY(CXXRewrittenBinaryOperator, operator_token, getVal39, setVal39, initVal39, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXRewrittenBinaryOperator, rhs, getVal40, setVal40, initVal40, RHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXRewrittenBinaryOperator, semantic_form, getVal41, setVal41, initVal41, SemanticForm, Expr, NthStmt)
  MX_SERIALIZE_BOOL(CXXRewrittenBinaryOperator, is_assignment_operation, getVal98, setVal98, initVal98, IsAssignmentOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXRewrittenBinaryOperator, is_comparison_operation, getVal99, setVal99, initVal99, IsComparisonOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXRewrittenBinaryOperator, is_reversed, getVal100, setVal100, initVal100, IsReversed, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXRewrittenBinaryOperator
MX_END_SERIALIZE_STMT(CXXRewrittenBinaryOperator)
#undef MX_ENTER_SERIALIZE_CXXRewrittenBinaryOperator
#undef MX_EXIT_SERIALIZE_CXXRewrittenBinaryOperator

#ifndef MX_ENTER_SERIALIZE_CXXPseudoDestructorExpr
#  define MX_ENTER_SERIALIZE_CXXPseudoDestructorExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXPseudoDestructorExpr
#  define MX_EXIT_SERIALIZE_CXXPseudoDestructorExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXPseudoDestructorExpr)
  MX_ENTER_SERIALIZE_CXXPseudoDestructorExpr
  MX_SERIALIZE_BASE(CXXPseudoDestructorExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, colon_colon_token, getVal39, setVal39, initVal39, ColonColonToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, destroyed_type, getVal40, setVal40, initVal40, DestroyedType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, destroyed_type_info, getVal41, setVal41, initVal41, DestroyedTypeInfo, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, destroyed_type_token, getVal42, setVal42, initVal42, DestroyedTypeToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, operator_token, getVal43, setVal43, initVal43, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, scope_type_info, getVal44, setVal44, initVal44, ScopeTypeInfo, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXPseudoDestructorExpr, tilde_token, getVal45, setVal45, initVal45, TildeToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXPseudoDestructorExpr, has_qualifier, getVal98, setVal98, initVal98, HasQualifier, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXPseudoDestructorExpr, is_arrow, getVal99, setVal99, initVal99, IsArrow, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXPseudoDestructorExpr
MX_END_SERIALIZE_STMT(CXXPseudoDestructorExpr)
#undef MX_ENTER_SERIALIZE_CXXPseudoDestructorExpr
#undef MX_EXIT_SERIALIZE_CXXPseudoDestructorExpr

#ifndef MX_ENTER_SERIALIZE_CXXNullPtrLiteralExpr
#  define MX_ENTER_SERIALIZE_CXXNullPtrLiteralExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXNullPtrLiteralExpr
#  define MX_EXIT_SERIALIZE_CXXNullPtrLiteralExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXNullPtrLiteralExpr)
  MX_ENTER_SERIALIZE_CXXNullPtrLiteralExpr
  MX_SERIALIZE_BASE(CXXNullPtrLiteralExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXNullPtrLiteralExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_EXIT_SERIALIZE_CXXNullPtrLiteralExpr
MX_END_SERIALIZE_STMT(CXXNullPtrLiteralExpr)
#undef MX_ENTER_SERIALIZE_CXXNullPtrLiteralExpr
#undef MX_EXIT_SERIALIZE_CXXNullPtrLiteralExpr

#ifndef MX_ENTER_SERIALIZE_CXXNoexceptExpr
#  define MX_ENTER_SERIALIZE_CXXNoexceptExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXNoexceptExpr
#  define MX_EXIT_SERIALIZE_CXXNoexceptExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXNoexceptExpr)
  MX_ENTER_SERIALIZE_CXXNoexceptExpr
  MX_SERIALIZE_BASE(CXXNoexceptExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXNoexceptExpr, operand, getVal38, setVal38, initVal38, Operand, Expr, NthStmt)
  MX_SERIALIZE_BOOL(CXXNoexceptExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXNoexceptExpr
MX_END_SERIALIZE_STMT(CXXNoexceptExpr)
#undef MX_ENTER_SERIALIZE_CXXNoexceptExpr
#undef MX_EXIT_SERIALIZE_CXXNoexceptExpr

#ifndef MX_ENTER_SERIALIZE_CXXNewExpr
#  define MX_ENTER_SERIALIZE_CXXNewExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXNewExpr
#  define MX_EXIT_SERIALIZE_CXXNewExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXNewExpr)
  MX_ENTER_SERIALIZE_CXXNewExpr
  MX_SERIALIZE_BASE(CXXNewExpr, Expr)
  MX_SERIALIZE_BOOL(CXXNewExpr, does_usual_array_delete_want_size, getVal98, setVal98, initVal98, DoesUsualArrayDeleteWantSize, bool, NthStmt)
  MX_SERIALIZE_ENTITY(CXXNewExpr, allocated_type, getVal38, setVal38, initVal38, AllocatedType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXNewExpr, allocated_type_source_info, getVal39, setVal39, initVal39, AllocatedTypeSourceInfo, Type, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXNewExpr, array_size, getVal40, setVal40, initVal40, ArraySize, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXNewExpr, construct_expression, getVal41, setVal41, initVal41, ConstructExpression, CXXConstructExpr, NthStmt)
  MX_SERIALIZE_ENUM(CXXNewExpr, initialization_style, getVal103, setVal103, initVal103, InitializationStyle, CXXNewExprInitializationStyle, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXNewExpr, initializer, getVal44, setVal44, initVal44, Initializer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXNewExpr, operator_delete, getVal45, setVal45, initVal45, OperatorDelete, FunctionDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXNewExpr, operator_new, getVal46, setVal46, initVal46, OperatorNew, FunctionDecl, NthStmt)
  MX_SERIALIZE_BOOL(CXXNewExpr, has_initializer, getVal102, setVal102, initVal102, HasInitializer, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXNewExpr, is_array, getVal104, setVal104, initVal104, IsArray, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXNewExpr, is_global_new, getVal107, setVal107, initVal107, IsGlobalNew, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXNewExpr, is_parenthesis_type_id, getVal108, setVal108, initVal108, IsParenthesisTypeId, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXNewExpr, pass_alignment, getVal109, setVal109, initVal109, PassAlignment, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(CXXNewExpr, placement_arguments, getVal17, setVal17, initVal17, PlacementArguments, Expr, NthStmt)
  MX_SERIALIZE_BOOL(CXXNewExpr, should_null_check_allocation, getVal110, setVal110, initVal110, ShouldNullCheckAllocation, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXNewExpr
MX_END_SERIALIZE_STMT(CXXNewExpr)
#undef MX_ENTER_SERIALIZE_CXXNewExpr
#undef MX_EXIT_SERIALIZE_CXXNewExpr

#ifndef MX_ENTER_SERIALIZE_CXXInheritedCtorInitExpr
#  define MX_ENTER_SERIALIZE_CXXInheritedCtorInitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXInheritedCtorInitExpr
#  define MX_EXIT_SERIALIZE_CXXInheritedCtorInitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXInheritedCtorInitExpr)
  MX_ENTER_SERIALIZE_CXXInheritedCtorInitExpr
  MX_SERIALIZE_BASE(CXXInheritedCtorInitExpr, Expr)
  MX_SERIALIZE_BOOL(CXXInheritedCtorInitExpr, constructs_virtual_base, getVal98, setVal98, initVal98, ConstructsVirtualBase, bool, NthStmt)
  MX_SERIALIZE_ENUM(CXXInheritedCtorInitExpr, construction_kind, getVal103, setVal103, initVal103, ConstructionKind, CXXConstructExprConstructionKind, NthStmt)
  MX_SERIALIZE_ENTITY(CXXInheritedCtorInitExpr, constructor, getVal38, setVal38, initVal38, Constructor, CXXConstructorDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXInheritedCtorInitExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXInheritedCtorInitExpr, inherited_from_virtual_base, getVal99, setVal99, initVal99, InheritedFromVirtualBase, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXInheritedCtorInitExpr
MX_END_SERIALIZE_STMT(CXXInheritedCtorInitExpr)
#undef MX_ENTER_SERIALIZE_CXXInheritedCtorInitExpr
#undef MX_EXIT_SERIALIZE_CXXInheritedCtorInitExpr

#ifndef MX_ENTER_SERIALIZE_CXXFoldExpr
#  define MX_ENTER_SERIALIZE_CXXFoldExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXFoldExpr
#  define MX_EXIT_SERIALIZE_CXXFoldExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXFoldExpr)
  MX_ENTER_SERIALIZE_CXXFoldExpr
  MX_SERIALIZE_BASE(CXXFoldExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, callee, getVal38, setVal38, initVal38, Callee, UnresolvedLookupExpr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, ellipsis_token, getVal39, setVal39, initVal39, EllipsisToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, initializer, getVal40, setVal40, initVal40, Initializer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, lhs, getVal41, setVal41, initVal41, LHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, l_paren_token, getVal42, setVal42, initVal42, LParenToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_INT(CXXFoldExpr, num_expansions, getVal112, setVal112, initVal112, NumExpansions, unsigned, NthStmt)
  MX_SERIALIZE_ENUM(CXXFoldExpr, operator_, getVal103, setVal103, initVal103, Operator, BinaryOperatorKind, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, pattern, getVal43, setVal43, initVal43, Pattern, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, rhs, getVal44, setVal44, initVal44, RHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXFoldExpr, r_paren_token, getVal45, setVal45, initVal45, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXFoldExpr, is_left_fold, getVal99, setVal99, initVal99, IsLeftFold, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXFoldExpr, is_right_fold, getVal100, setVal100, initVal100, IsRightFold, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXFoldExpr
MX_END_SERIALIZE_STMT(CXXFoldExpr)
#undef MX_ENTER_SERIALIZE_CXXFoldExpr
#undef MX_EXIT_SERIALIZE_CXXFoldExpr

#ifndef MX_ENTER_SERIALIZE_CXXDependentScopeMemberExpr
#  define MX_ENTER_SERIALIZE_CXXDependentScopeMemberExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDependentScopeMemberExpr
#  define MX_EXIT_SERIALIZE_CXXDependentScopeMemberExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXDependentScopeMemberExpr)
  MX_ENTER_SERIALIZE_CXXDependentScopeMemberExpr
  MX_SERIALIZE_BASE(CXXDependentScopeMemberExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, base_type, getVal39, setVal39, initVal39, BaseType, Type, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXDependentScopeMemberExpr, first_qualifier_found_in_scope, getVal40, setVal40, initVal40, FirstQualifierFoundInScope, NamedDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, l_angle_token, getVal41, setVal41, initVal41, LAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, member_token, getVal42, setVal42, initVal42, MemberToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, operator_token, getVal43, setVal43, initVal43, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, r_angle_token, getVal44, setVal44, initVal44, RAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDependentScopeMemberExpr, template_keyword_token, getVal45, setVal45, initVal45, TemplateKeywordToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXDependentScopeMemberExpr, has_explicit_template_arguments, getVal99, setVal99, initVal99, HasExplicitTemplateArguments, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXDependentScopeMemberExpr, has_template_keyword, getVal100, setVal100, initVal100, HasTemplateKeyword, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXDependentScopeMemberExpr, is_arrow, getVal101, setVal101, initVal101, IsArrow, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXDependentScopeMemberExpr, is_implicit_access, getVal102, setVal102, initVal102, IsImplicitAccess, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXDependentScopeMemberExpr
MX_END_SERIALIZE_STMT(CXXDependentScopeMemberExpr)
#undef MX_ENTER_SERIALIZE_CXXDependentScopeMemberExpr
#undef MX_EXIT_SERIALIZE_CXXDependentScopeMemberExpr

#ifndef MX_ENTER_SERIALIZE_CXXDeleteExpr
#  define MX_ENTER_SERIALIZE_CXXDeleteExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDeleteExpr
#  define MX_EXIT_SERIALIZE_CXXDeleteExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXDeleteExpr)
  MX_ENTER_SERIALIZE_CXXDeleteExpr
  MX_SERIALIZE_BASE(CXXDeleteExpr, Expr)
  MX_SERIALIZE_BOOL(CXXDeleteExpr, does_usual_array_delete_want_size, getVal98, setVal98, initVal98, DoesUsualArrayDeleteWantSize, bool, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDeleteExpr, argument, getVal38, setVal38, initVal38, Argument, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDeleteExpr, destroyed_type, getVal39, setVal39, initVal39, DestroyedType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDeleteExpr, operator_delete, getVal40, setVal40, initVal40, OperatorDelete, FunctionDecl, NthStmt)
  MX_SERIALIZE_BOOL(CXXDeleteExpr, is_array_form, getVal99, setVal99, initVal99, IsArrayForm, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXDeleteExpr, is_array_form_as_written, getVal100, setVal100, initVal100, IsArrayFormAsWritten, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXDeleteExpr, is_global_delete, getVal101, setVal101, initVal101, IsGlobalDelete, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXDeleteExpr
MX_END_SERIALIZE_STMT(CXXDeleteExpr)
#undef MX_ENTER_SERIALIZE_CXXDeleteExpr
#undef MX_EXIT_SERIALIZE_CXXDeleteExpr

#ifndef MX_ENTER_SERIALIZE_CXXDefaultInitExpr
#  define MX_ENTER_SERIALIZE_CXXDefaultInitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDefaultInitExpr
#  define MX_EXIT_SERIALIZE_CXXDefaultInitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXDefaultInitExpr)
  MX_ENTER_SERIALIZE_CXXDefaultInitExpr
  MX_SERIALIZE_BASE(CXXDefaultInitExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXDefaultInitExpr, expression, getVal38, setVal38, initVal38, Expression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDefaultInitExpr, field, getVal39, setVal39, initVal39, Field, FieldDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDefaultInitExpr, used_token, getVal40, setVal40, initVal40, UsedToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_CXXDefaultInitExpr
MX_END_SERIALIZE_STMT(CXXDefaultInitExpr)
#undef MX_ENTER_SERIALIZE_CXXDefaultInitExpr
#undef MX_EXIT_SERIALIZE_CXXDefaultInitExpr

#ifndef MX_ENTER_SERIALIZE_CXXDefaultArgExpr
#  define MX_ENTER_SERIALIZE_CXXDefaultArgExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDefaultArgExpr
#  define MX_EXIT_SERIALIZE_CXXDefaultArgExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXDefaultArgExpr)
  MX_ENTER_SERIALIZE_CXXDefaultArgExpr
  MX_SERIALIZE_BASE(CXXDefaultArgExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXDefaultArgExpr, expression, getVal38, setVal38, initVal38, Expression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDefaultArgExpr, parameter, getVal39, setVal39, initVal39, Parameter, ParmVarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXDefaultArgExpr, used_token, getVal40, setVal40, initVal40, UsedToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_CXXDefaultArgExpr
MX_END_SERIALIZE_STMT(CXXDefaultArgExpr)
#undef MX_ENTER_SERIALIZE_CXXDefaultArgExpr
#undef MX_EXIT_SERIALIZE_CXXDefaultArgExpr

#ifndef MX_ENTER_SERIALIZE_CXXConstructExpr
#  define MX_ENTER_SERIALIZE_CXXConstructExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXConstructExpr
#  define MX_EXIT_SERIALIZE_CXXConstructExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXConstructExpr)
  MX_ENTER_SERIALIZE_CXXConstructExpr
  MX_SERIALIZE_BASE(CXXConstructExpr, Expr)
  MX_SERIALIZE_ENTITY_LIST(CXXConstructExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_SERIALIZE_ENUM(CXXConstructExpr, construction_kind, getVal103, setVal103, initVal103, ConstructionKind, CXXConstructExprConstructionKind, NthStmt)
  MX_SERIALIZE_ENTITY(CXXConstructExpr, constructor, getVal38, setVal38, initVal38, Constructor, CXXConstructorDecl, NthStmt)
  MX_SERIALIZE_ENTITY(CXXConstructExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXConstructExpr, had_multiple_candidates, getVal98, setVal98, initVal98, HadMultipleCandidates, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXConstructExpr, is_elidable, getVal99, setVal99, initVal99, IsElidable, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXConstructExpr, is_list_initialization, getVal100, setVal100, initVal100, IsListInitialization, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXConstructExpr, is_std_initializer_list_initialization, getVal101, setVal101, initVal101, IsStdInitializerListInitialization, bool, NthStmt)
  MX_SERIALIZE_BOOL(CXXConstructExpr, requires_zero_initialization, getVal102, setVal102, initVal102, RequiresZeroInitialization, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXConstructExpr
MX_END_SERIALIZE_STMT(CXXConstructExpr)
#undef MX_ENTER_SERIALIZE_CXXConstructExpr
#undef MX_EXIT_SERIALIZE_CXXConstructExpr

#ifndef MX_ENTER_SERIALIZE_CXXTemporaryObjectExpr
#  define MX_ENTER_SERIALIZE_CXXTemporaryObjectExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXTemporaryObjectExpr
#  define MX_EXIT_SERIALIZE_CXXTemporaryObjectExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXTemporaryObjectExpr)
  MX_ENTER_SERIALIZE_CXXTemporaryObjectExpr
  MX_SERIALIZE_BASE(CXXTemporaryObjectExpr, CXXConstructExpr)
  MX_SERIALIZE_ENTITY(CXXTemporaryObjectExpr, type_source_info, getVal42, setVal42, initVal42, TypeSourceInfo, Type, NthStmt)
  MX_EXIT_SERIALIZE_CXXTemporaryObjectExpr
MX_END_SERIALIZE_STMT(CXXTemporaryObjectExpr)
#undef MX_ENTER_SERIALIZE_CXXTemporaryObjectExpr
#undef MX_EXIT_SERIALIZE_CXXTemporaryObjectExpr

#ifndef MX_ENTER_SERIALIZE_CXXBoolLiteralExpr
#  define MX_ENTER_SERIALIZE_CXXBoolLiteralExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXBoolLiteralExpr
#  define MX_EXIT_SERIALIZE_CXXBoolLiteralExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXBoolLiteralExpr)
  MX_ENTER_SERIALIZE_CXXBoolLiteralExpr
  MX_SERIALIZE_BASE(CXXBoolLiteralExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXBoolLiteralExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(CXXBoolLiteralExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
  MX_EXIT_SERIALIZE_CXXBoolLiteralExpr
MX_END_SERIALIZE_STMT(CXXBoolLiteralExpr)
#undef MX_ENTER_SERIALIZE_CXXBoolLiteralExpr
#undef MX_EXIT_SERIALIZE_CXXBoolLiteralExpr

#ifndef MX_ENTER_SERIALIZE_CXXBindTemporaryExpr
#  define MX_ENTER_SERIALIZE_CXXBindTemporaryExpr
#endif
#ifndef MX_EXIT_SERIALIZE_CXXBindTemporaryExpr
#  define MX_EXIT_SERIALIZE_CXXBindTemporaryExpr
#endif

MX_BEGIN_SERIALIZE_STMT(CXXBindTemporaryExpr)
  MX_ENTER_SERIALIZE_CXXBindTemporaryExpr
  MX_SERIALIZE_BASE(CXXBindTemporaryExpr, Expr)
  MX_SERIALIZE_ENTITY(CXXBindTemporaryExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_CXXBindTemporaryExpr
MX_END_SERIALIZE_STMT(CXXBindTemporaryExpr)
#undef MX_ENTER_SERIALIZE_CXXBindTemporaryExpr
#undef MX_EXIT_SERIALIZE_CXXBindTemporaryExpr

#ifndef MX_ENTER_SERIALIZE_BlockExpr
#  define MX_ENTER_SERIALIZE_BlockExpr
#endif
#ifndef MX_EXIT_SERIALIZE_BlockExpr
#  define MX_EXIT_SERIALIZE_BlockExpr
#endif

MX_BEGIN_SERIALIZE_STMT(BlockExpr)
  MX_ENTER_SERIALIZE_BlockExpr
  MX_SERIALIZE_BASE(BlockExpr, Expr)
  MX_SERIALIZE_ENTITY(BlockExpr, block_declaration, getVal38, setVal38, initVal38, BlockDeclaration, BlockDecl, NthStmt)
  MX_SERIALIZE_ENTITY(BlockExpr, body, getVal39, setVal39, initVal39, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(BlockExpr, caret_token, getVal40, setVal40, initVal40, CaretToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(BlockExpr, function_type, getVal41, setVal41, initVal41, FunctionType, FunctionProtoType, NthStmt)
  MX_EXIT_SERIALIZE_BlockExpr
MX_END_SERIALIZE_STMT(BlockExpr)
#undef MX_ENTER_SERIALIZE_BlockExpr
#undef MX_EXIT_SERIALIZE_BlockExpr

#ifndef MX_ENTER_SERIALIZE_BinaryOperator
#  define MX_ENTER_SERIALIZE_BinaryOperator
#endif
#ifndef MX_EXIT_SERIALIZE_BinaryOperator
#  define MX_EXIT_SERIALIZE_BinaryOperator
#endif

MX_BEGIN_SERIALIZE_STMT(BinaryOperator)
  MX_ENTER_SERIALIZE_BinaryOperator
  MX_SERIALIZE_BASE(BinaryOperator, Expr)
  MX_SERIALIZE_ENTITY(BinaryOperator, lhs, getVal38, setVal38, initVal38, LHS, Expr, NthStmt)
  MX_SERIALIZE_ENUM(BinaryOperator, opcode, getVal103, setVal103, initVal103, Opcode, BinaryOperatorKind, NthStmt)
  MX_SERIALIZE_TEXT(BinaryOperator, opcode_string, getVal63, setVal63, initVal63, OpcodeString, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY(BinaryOperator, operator_token, getVal39, setVal39, initVal39, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(BinaryOperator, rhs, getVal40, setVal40, initVal40, RHS, Expr, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, has_stored_fp_features, getVal98, setVal98, initVal98, HasStoredFPFeatures, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_additive_operation, getVal99, setVal99, initVal99, IsAdditiveOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_assignment_operation, getVal100, setVal100, initVal100, IsAssignmentOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_bitwise_operation, getVal101, setVal101, initVal101, IsBitwiseOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_comma_operation, getVal102, setVal102, initVal102, IsCommaOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_comparison_operation, getVal104, setVal104, initVal104, IsComparisonOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_compound_assignment_operation, getVal107, setVal107, initVal107, IsCompoundAssignmentOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_equality_operation, getVal108, setVal108, initVal108, IsEqualityOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_logical_operation, getVal109, setVal109, initVal109, IsLogicalOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_multiplicative_operation, getVal110, setVal110, initVal110, IsMultiplicativeOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_pointer_memory_operation, getVal111, setVal111, initVal111, IsPointerMemoryOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_relational_operation, getVal113, setVal113, initVal113, IsRelationalOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_shift_assign_operation, getVal114, setVal114, initVal114, IsShiftAssignOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(BinaryOperator, is_shift_operation, getVal115, setVal115, initVal115, IsShiftOperation, bool, NthStmt)
  MX_EXIT_SERIALIZE_BinaryOperator
MX_END_SERIALIZE_STMT(BinaryOperator)
#undef MX_ENTER_SERIALIZE_BinaryOperator
#undef MX_EXIT_SERIALIZE_BinaryOperator

#ifndef MX_ENTER_SERIALIZE_CompoundAssignOperator
#  define MX_ENTER_SERIALIZE_CompoundAssignOperator
#endif
#ifndef MX_EXIT_SERIALIZE_CompoundAssignOperator
#  define MX_EXIT_SERIALIZE_CompoundAssignOperator
#endif

MX_BEGIN_SERIALIZE_STMT(CompoundAssignOperator)
  MX_ENTER_SERIALIZE_CompoundAssignOperator
  MX_SERIALIZE_BASE(CompoundAssignOperator, BinaryOperator)
  MX_SERIALIZE_ENTITY(CompoundAssignOperator, computation_lhs_type, getVal41, setVal41, initVal41, ComputationLHSType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(CompoundAssignOperator, computation_result_type, getVal42, setVal42, initVal42, ComputationResultType, Type, NthStmt)
  MX_EXIT_SERIALIZE_CompoundAssignOperator
MX_END_SERIALIZE_STMT(CompoundAssignOperator)
#undef MX_ENTER_SERIALIZE_CompoundAssignOperator
#undef MX_EXIT_SERIALIZE_CompoundAssignOperator

#ifndef MX_ENTER_SERIALIZE_AtomicExpr
#  define MX_ENTER_SERIALIZE_AtomicExpr
#endif
#ifndef MX_EXIT_SERIALIZE_AtomicExpr
#  define MX_EXIT_SERIALIZE_AtomicExpr
#endif

MX_BEGIN_SERIALIZE_STMT(AtomicExpr)
  MX_ENTER_SERIALIZE_AtomicExpr
  MX_SERIALIZE_BASE(AtomicExpr, Expr)
  MX_SERIALIZE_ENTITY(AtomicExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt)
  MX_SERIALIZE_ENUM(AtomicExpr, operation, getVal103, setVal103, initVal103, Operation, AtomicExprAtomicOp, NthStmt)
  MX_SERIALIZE_ENTITY(AtomicExpr, order, getVal39, setVal39, initVal39, Order, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(AtomicExpr, order_fail, getVal40, setVal40, initVal40, OrderFail, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(AtomicExpr, pointer, getVal41, setVal41, initVal41, Pointer, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(AtomicExpr, r_paren_token, getVal42, setVal42, initVal42, RParenToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(AtomicExpr, scope, getVal43, setVal43, initVal43, Scope, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(AtomicExpr, value1, getVal44, setVal44, initVal44, Value1, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(AtomicExpr, value2, getVal45, setVal45, initVal45, Value2, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(AtomicExpr, value_type, getVal46, setVal46, initVal46, ValueType, Type, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(AtomicExpr, weak, getVal47, setVal47, initVal47, Weak, Expr, NthStmt)
  MX_SERIALIZE_BOOL(AtomicExpr, is_cmp_x_chg, getVal104, setVal104, initVal104, IsCmpXChg, bool, NthStmt)
  MX_SERIALIZE_BOOL(AtomicExpr, is_open_cl, getVal107, setVal107, initVal107, IsOpenCL, bool, NthStmt)
  MX_SERIALIZE_BOOL(AtomicExpr, is_volatile, getVal108, setVal108, initVal108, IsVolatile, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(AtomicExpr, sub_expressions, getVal17, setVal17, initVal17, SubExpressions, Expr, NthStmt)
  MX_EXIT_SERIALIZE_AtomicExpr
MX_END_SERIALIZE_STMT(AtomicExpr)
#undef MX_ENTER_SERIALIZE_AtomicExpr
#undef MX_EXIT_SERIALIZE_AtomicExpr

#ifndef MX_ENTER_SERIALIZE_AsTypeExpr
#  define MX_ENTER_SERIALIZE_AsTypeExpr
#endif
#ifndef MX_EXIT_SERIALIZE_AsTypeExpr
#  define MX_EXIT_SERIALIZE_AsTypeExpr
#endif

MX_BEGIN_SERIALIZE_STMT(AsTypeExpr)
  MX_ENTER_SERIALIZE_AsTypeExpr
  MX_SERIALIZE_BASE(AsTypeExpr, Expr)
  MX_SERIALIZE_ENTITY(AsTypeExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(AsTypeExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(AsTypeExpr, src_expression, getVal40, setVal40, initVal40, SrcExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_AsTypeExpr
MX_END_SERIALIZE_STMT(AsTypeExpr)
#undef MX_ENTER_SERIALIZE_AsTypeExpr
#undef MX_EXIT_SERIALIZE_AsTypeExpr

#ifndef MX_ENTER_SERIALIZE_ArrayTypeTraitExpr
#  define MX_ENTER_SERIALIZE_ArrayTypeTraitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ArrayTypeTraitExpr
#  define MX_EXIT_SERIALIZE_ArrayTypeTraitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ArrayTypeTraitExpr)
  MX_ENTER_SERIALIZE_ArrayTypeTraitExpr
  MX_SERIALIZE_BASE(ArrayTypeTraitExpr, Expr)
  MX_SERIALIZE_ENTITY(ArrayTypeTraitExpr, dimension_expression, getVal38, setVal38, initVal38, DimensionExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ArrayTypeTraitExpr, queried_type, getVal39, setVal39, initVal39, QueriedType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ArrayTypeTraitExpr, queried_type_source_info, getVal40, setVal40, initVal40, QueriedTypeSourceInfo, Type, NthStmt)
  MX_SERIALIZE_ENUM(ArrayTypeTraitExpr, trait, getVal103, setVal103, initVal103, Trait, ArrayTypeTrait, NthStmt)
  MX_EXIT_SERIALIZE_ArrayTypeTraitExpr
MX_END_SERIALIZE_STMT(ArrayTypeTraitExpr)
#undef MX_ENTER_SERIALIZE_ArrayTypeTraitExpr
#undef MX_EXIT_SERIALIZE_ArrayTypeTraitExpr

#ifndef MX_ENTER_SERIALIZE_ArraySubscriptExpr
#  define MX_ENTER_SERIALIZE_ArraySubscriptExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ArraySubscriptExpr
#  define MX_EXIT_SERIALIZE_ArraySubscriptExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ArraySubscriptExpr)
  MX_ENTER_SERIALIZE_ArraySubscriptExpr
  MX_SERIALIZE_BASE(ArraySubscriptExpr, Expr)
  MX_SERIALIZE_ENTITY(ArraySubscriptExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ArraySubscriptExpr, index, getVal39, setVal39, initVal39, Index, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ArraySubscriptExpr, lhs, getVal40, setVal40, initVal40, LHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ArraySubscriptExpr, r_bracket_token, getVal41, setVal41, initVal41, RBracketToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ArraySubscriptExpr, rhs, getVal42, setVal42, initVal42, RHS, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ArraySubscriptExpr
MX_END_SERIALIZE_STMT(ArraySubscriptExpr)
#undef MX_ENTER_SERIALIZE_ArraySubscriptExpr
#undef MX_EXIT_SERIALIZE_ArraySubscriptExpr

#ifndef MX_ENTER_SERIALIZE_ArrayInitLoopExpr
#  define MX_ENTER_SERIALIZE_ArrayInitLoopExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ArrayInitLoopExpr
#  define MX_EXIT_SERIALIZE_ArrayInitLoopExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ArrayInitLoopExpr)
  MX_ENTER_SERIALIZE_ArrayInitLoopExpr
  MX_SERIALIZE_BASE(ArrayInitLoopExpr, Expr)
  MX_SERIALIZE_ENTITY(ArrayInitLoopExpr, common_expression, getVal38, setVal38, initVal38, CommonExpression, OpaqueValueExpr, NthStmt)
  MX_SERIALIZE_ENTITY(ArrayInitLoopExpr, sub_expression, getVal39, setVal39, initVal39, SubExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ArrayInitLoopExpr
MX_END_SERIALIZE_STMT(ArrayInitLoopExpr)
#undef MX_ENTER_SERIALIZE_ArrayInitLoopExpr
#undef MX_EXIT_SERIALIZE_ArrayInitLoopExpr

#ifndef MX_ENTER_SERIALIZE_ArrayInitIndexExpr
#  define MX_ENTER_SERIALIZE_ArrayInitIndexExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ArrayInitIndexExpr
#  define MX_EXIT_SERIALIZE_ArrayInitIndexExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ArrayInitIndexExpr)
  MX_ENTER_SERIALIZE_ArrayInitIndexExpr
  MX_SERIALIZE_BASE(ArrayInitIndexExpr, Expr)
  MX_EXIT_SERIALIZE_ArrayInitIndexExpr
MX_END_SERIALIZE_STMT(ArrayInitIndexExpr)
#undef MX_ENTER_SERIALIZE_ArrayInitIndexExpr
#undef MX_EXIT_SERIALIZE_ArrayInitIndexExpr

#ifndef MX_ENTER_SERIALIZE_AddrLabelExpr
#  define MX_ENTER_SERIALIZE_AddrLabelExpr
#endif
#ifndef MX_EXIT_SERIALIZE_AddrLabelExpr
#  define MX_EXIT_SERIALIZE_AddrLabelExpr
#endif

MX_BEGIN_SERIALIZE_STMT(AddrLabelExpr)
  MX_ENTER_SERIALIZE_AddrLabelExpr
  MX_SERIALIZE_BASE(AddrLabelExpr, Expr)
  MX_SERIALIZE_ENTITY(AddrLabelExpr, amp_amp_token, getVal38, setVal38, initVal38, AmpAmpToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(AddrLabelExpr, label, getVal39, setVal39, initVal39, Label, LabelDecl, NthStmt)
  MX_SERIALIZE_ENTITY(AddrLabelExpr, label_token, getVal40, setVal40, initVal40, LabelToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_AddrLabelExpr
MX_END_SERIALIZE_STMT(AddrLabelExpr)
#undef MX_ENTER_SERIALIZE_AddrLabelExpr
#undef MX_EXIT_SERIALIZE_AddrLabelExpr

#ifndef MX_ENTER_SERIALIZE_AbstractConditionalOperator
#  define MX_ENTER_SERIALIZE_AbstractConditionalOperator
#endif
#ifndef MX_EXIT_SERIALIZE_AbstractConditionalOperator
#  define MX_EXIT_SERIALIZE_AbstractConditionalOperator
#endif

MX_BEGIN_SERIALIZE_STMT(AbstractConditionalOperator)
  MX_ENTER_SERIALIZE_AbstractConditionalOperator
  MX_SERIALIZE_BASE(AbstractConditionalOperator, Expr)
  MX_SERIALIZE_ENTITY(AbstractConditionalOperator, colon_token, getVal38, setVal38, initVal38, ColonToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(AbstractConditionalOperator, condition, getVal39, setVal39, initVal39, Condition, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(AbstractConditionalOperator, false_expression, getVal40, setVal40, initVal40, FalseExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(AbstractConditionalOperator, question_token, getVal41, setVal41, initVal41, QuestionToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(AbstractConditionalOperator, true_expression, getVal42, setVal42, initVal42, TrueExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_AbstractConditionalOperator
MX_END_SERIALIZE_STMT(AbstractConditionalOperator)
#undef MX_ENTER_SERIALIZE_AbstractConditionalOperator
#undef MX_EXIT_SERIALIZE_AbstractConditionalOperator

#ifndef MX_ENTER_SERIALIZE_ConditionalOperator
#  define MX_ENTER_SERIALIZE_ConditionalOperator
#endif
#ifndef MX_EXIT_SERIALIZE_ConditionalOperator
#  define MX_EXIT_SERIALIZE_ConditionalOperator
#endif

MX_BEGIN_SERIALIZE_STMT(ConditionalOperator)
  MX_ENTER_SERIALIZE_ConditionalOperator
  MX_SERIALIZE_BASE(ConditionalOperator, AbstractConditionalOperator)
  MX_SERIALIZE_ENTITY(ConditionalOperator, lhs, getVal43, setVal43, initVal43, LHS, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ConditionalOperator, rhs, getVal44, setVal44, initVal44, RHS, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ConditionalOperator
MX_END_SERIALIZE_STMT(ConditionalOperator)
#undef MX_ENTER_SERIALIZE_ConditionalOperator
#undef MX_EXIT_SERIALIZE_ConditionalOperator

#ifndef MX_ENTER_SERIALIZE_BinaryConditionalOperator
#  define MX_ENTER_SERIALIZE_BinaryConditionalOperator
#endif
#ifndef MX_EXIT_SERIALIZE_BinaryConditionalOperator
#  define MX_EXIT_SERIALIZE_BinaryConditionalOperator
#endif

MX_BEGIN_SERIALIZE_STMT(BinaryConditionalOperator)
  MX_ENTER_SERIALIZE_BinaryConditionalOperator
  MX_SERIALIZE_BASE(BinaryConditionalOperator, AbstractConditionalOperator)
  MX_SERIALIZE_ENTITY(BinaryConditionalOperator, common, getVal43, setVal43, initVal43, Common, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(BinaryConditionalOperator, opaque_value, getVal44, setVal44, initVal44, OpaqueValue, OpaqueValueExpr, NthStmt)
  MX_EXIT_SERIALIZE_BinaryConditionalOperator
MX_END_SERIALIZE_STMT(BinaryConditionalOperator)
#undef MX_ENTER_SERIALIZE_BinaryConditionalOperator
#undef MX_EXIT_SERIALIZE_BinaryConditionalOperator

#ifndef MX_ENTER_SERIALIZE_VAArgExpr
#  define MX_ENTER_SERIALIZE_VAArgExpr
#endif
#ifndef MX_EXIT_SERIALIZE_VAArgExpr
#  define MX_EXIT_SERIALIZE_VAArgExpr
#endif

MX_BEGIN_SERIALIZE_STMT(VAArgExpr)
  MX_ENTER_SERIALIZE_VAArgExpr
  MX_SERIALIZE_BASE(VAArgExpr, Expr)
  MX_SERIALIZE_ENTITY(VAArgExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(VAArgExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(VAArgExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(VAArgExpr, written_type_info, getVal41, setVal41, initVal41, WrittenTypeInfo, Type, NthStmt)
  MX_SERIALIZE_BOOL(VAArgExpr, is_microsoft_abi, getVal98, setVal98, initVal98, IsMicrosoftABI, bool, NthStmt)
  MX_EXIT_SERIALIZE_VAArgExpr
MX_END_SERIALIZE_STMT(VAArgExpr)
#undef MX_ENTER_SERIALIZE_VAArgExpr
#undef MX_EXIT_SERIALIZE_VAArgExpr

#ifndef MX_ENTER_SERIALIZE_UnaryOperator
#  define MX_ENTER_SERIALIZE_UnaryOperator
#endif
#ifndef MX_EXIT_SERIALIZE_UnaryOperator
#  define MX_EXIT_SERIALIZE_UnaryOperator
#endif

MX_BEGIN_SERIALIZE_STMT(UnaryOperator)
  MX_ENTER_SERIALIZE_UnaryOperator
  MX_SERIALIZE_BASE(UnaryOperator, Expr)
  MX_SERIALIZE_BOOL(UnaryOperator, can_overflow, getVal98, setVal98, initVal98, CanOverflow, bool, NthStmt)
  MX_SERIALIZE_ENUM(UnaryOperator, opcode, getVal103, setVal103, initVal103, Opcode, UnaryOperatorKind, NthStmt)
  MX_SERIALIZE_ENTITY(UnaryOperator, operator_token, getVal38, setVal38, initVal38, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(UnaryOperator, sub_expression, getVal39, setVal39, initVal39, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, has_stored_fp_features, getVal99, setVal99, initVal99, HasStoredFPFeatures, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, is_arithmetic_operation, getVal100, setVal100, initVal100, IsArithmeticOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, is_decrement_operation, getVal101, setVal101, initVal101, IsDecrementOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, is_increment_decrement_operation, getVal102, setVal102, initVal102, IsIncrementDecrementOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, is_increment_operation, getVal104, setVal104, initVal104, IsIncrementOperation, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, is_postfix, getVal107, setVal107, initVal107, IsPostfix, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnaryOperator, is_prefix, getVal108, setVal108, initVal108, IsPrefix, bool, NthStmt)
  MX_EXIT_SERIALIZE_UnaryOperator
MX_END_SERIALIZE_STMT(UnaryOperator)
#undef MX_ENTER_SERIALIZE_UnaryOperator
#undef MX_EXIT_SERIALIZE_UnaryOperator

#ifndef MX_ENTER_SERIALIZE_UnaryExprOrTypeTraitExpr
#  define MX_ENTER_SERIALIZE_UnaryExprOrTypeTraitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_UnaryExprOrTypeTraitExpr
#  define MX_EXIT_SERIALIZE_UnaryExprOrTypeTraitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(UnaryExprOrTypeTraitExpr)
  MX_ENTER_SERIALIZE_UnaryExprOrTypeTraitExpr
  MX_SERIALIZE_BASE(UnaryExprOrTypeTraitExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_expression, getVal38, setVal38, initVal38, ArgumentExpression, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_type, getVal39, setVal39, initVal39, ArgumentType, Type, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_type_info, getVal40, setVal40, initVal40, ArgumentTypeInfo, Type, NthStmt)
  MX_SERIALIZE_ENTITY(UnaryExprOrTypeTraitExpr, operator_token, getVal41, setVal41, initVal41, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(UnaryExprOrTypeTraitExpr, r_paren_token, getVal42, setVal42, initVal42, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(UnaryExprOrTypeTraitExpr, type_of_argument, getVal43, setVal43, initVal43, TypeOfArgument, Type, NthStmt)
  MX_SERIALIZE_BOOL(UnaryExprOrTypeTraitExpr, is_argument_type, getVal101, setVal101, initVal101, IsArgumentType, bool, NthStmt)
  MX_EXIT_SERIALIZE_UnaryExprOrTypeTraitExpr
MX_END_SERIALIZE_STMT(UnaryExprOrTypeTraitExpr)
#undef MX_ENTER_SERIALIZE_UnaryExprOrTypeTraitExpr
#undef MX_EXIT_SERIALIZE_UnaryExprOrTypeTraitExpr

#ifndef MX_ENTER_SERIALIZE_TypoExpr
#  define MX_ENTER_SERIALIZE_TypoExpr
#endif
#ifndef MX_EXIT_SERIALIZE_TypoExpr
#  define MX_EXIT_SERIALIZE_TypoExpr
#endif

MX_BEGIN_SERIALIZE_STMT(TypoExpr)
  MX_ENTER_SERIALIZE_TypoExpr
  MX_SERIALIZE_BASE(TypoExpr, Expr)
  MX_EXIT_SERIALIZE_TypoExpr
MX_END_SERIALIZE_STMT(TypoExpr)
#undef MX_ENTER_SERIALIZE_TypoExpr
#undef MX_EXIT_SERIALIZE_TypoExpr

#ifndef MX_ENTER_SERIALIZE_TypeTraitExpr
#  define MX_ENTER_SERIALIZE_TypeTraitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_TypeTraitExpr
#  define MX_EXIT_SERIALIZE_TypeTraitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(TypeTraitExpr)
  MX_ENTER_SERIALIZE_TypeTraitExpr
  MX_SERIALIZE_BASE(TypeTraitExpr, Expr)
  MX_SERIALIZE_ENUM(TypeTraitExpr, trait, getVal103, setVal103, initVal103, Trait, TypeTrait, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(TypeTraitExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(TypeTraitExpr, arguments, getVal17, setVal17, initVal17, Arguments, Type, NthStmt)
  MX_EXIT_SERIALIZE_TypeTraitExpr
MX_END_SERIALIZE_STMT(TypeTraitExpr)
#undef MX_ENTER_SERIALIZE_TypeTraitExpr
#undef MX_EXIT_SERIALIZE_TypeTraitExpr

#ifndef MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmPackExpr
#  define MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmPackExpr
#endif
#ifndef MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmPackExpr
#  define MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmPackExpr
#endif

MX_BEGIN_SERIALIZE_STMT(SubstNonTypeTemplateParmPackExpr)
  MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmPackExpr
  MX_SERIALIZE_BASE(SubstNonTypeTemplateParmPackExpr, Expr)
  MX_SERIALIZE_ENTITY(SubstNonTypeTemplateParmPackExpr, parameter_pack, getVal38, setVal38, initVal38, ParameterPack, NonTypeTemplateParmDecl, NthStmt)
  MX_SERIALIZE_ENTITY(SubstNonTypeTemplateParmPackExpr, parameter_pack_token, getVal39, setVal39, initVal39, ParameterPackToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmPackExpr
MX_END_SERIALIZE_STMT(SubstNonTypeTemplateParmPackExpr)
#undef MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmPackExpr
#undef MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmPackExpr

#ifndef MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmExpr
#  define MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmExpr
#endif
#ifndef MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmExpr
#  define MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmExpr
#endif

MX_BEGIN_SERIALIZE_STMT(SubstNonTypeTemplateParmExpr)
  MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmExpr
  MX_SERIALIZE_BASE(SubstNonTypeTemplateParmExpr, Expr)
  MX_SERIALIZE_ENTITY(SubstNonTypeTemplateParmExpr, name_token, getVal38, setVal38, initVal38, NameToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SubstNonTypeTemplateParmExpr, parameter, getVal39, setVal39, initVal39, Parameter, NonTypeTemplateParmDecl, NthStmt)
  MX_SERIALIZE_ENTITY(SubstNonTypeTemplateParmExpr, parameter_type, getVal40, setVal40, initVal40, ParameterType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(SubstNonTypeTemplateParmExpr, replacement, getVal41, setVal41, initVal41, Replacement, Expr, NthStmt)
  MX_SERIALIZE_BOOL(SubstNonTypeTemplateParmExpr, is_reference_parameter, getVal98, setVal98, initVal98, IsReferenceParameter, bool, NthStmt)
  MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmExpr
MX_END_SERIALIZE_STMT(SubstNonTypeTemplateParmExpr)
#undef MX_ENTER_SERIALIZE_SubstNonTypeTemplateParmExpr
#undef MX_EXIT_SERIALIZE_SubstNonTypeTemplateParmExpr

#ifndef MX_ENTER_SERIALIZE_StringLiteral
#  define MX_ENTER_SERIALIZE_StringLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_StringLiteral
#  define MX_EXIT_SERIALIZE_StringLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(StringLiteral)
  MX_ENTER_SERIALIZE_StringLiteral
  MX_SERIALIZE_BASE(StringLiteral, Expr)
  MX_SERIALIZE_OPTIONAL_BOOL(StringLiteral, contains_non_ascii, getVal98, setVal98, initVal98, ContainsNonAscii, bool, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(StringLiteral, contains_non_ascii_or_null, getVal100, setVal100, initVal100, ContainsNonAsciiOrNull, bool, NthStmt)
  MX_SERIALIZE_TEXT(StringLiteral, bytes, getVal63, setVal63, initVal63, Bytes, basic_string_view, NthStmt)
  MX_SERIALIZE_OPTIONAL_TEXT(StringLiteral, string, getVal68, setVal68, initVal68, String, basic_string_view, NthStmt)
  MX_SERIALIZE_BOOL(StringLiteral, is_ascii, getVal104, setVal104, initVal104, IsAscii, bool, NthStmt)
  MX_SERIALIZE_BOOL(StringLiteral, is_pascal, getVal107, setVal107, initVal107, IsPascal, bool, NthStmt)
  MX_SERIALIZE_BOOL(StringLiteral, is_utf16, getVal108, setVal108, initVal108, IsUTF16, bool, NthStmt)
  MX_SERIALIZE_BOOL(StringLiteral, is_utf32, getVal109, setVal109, initVal109, IsUTF32, bool, NthStmt)
  MX_SERIALIZE_BOOL(StringLiteral, is_utf8, getVal110, setVal110, initVal110, IsUTF8, bool, NthStmt)
  MX_SERIALIZE_BOOL(StringLiteral, is_wide, getVal111, setVal111, initVal111, IsWide, bool, NthStmt)
  MX_EXIT_SERIALIZE_StringLiteral
MX_END_SERIALIZE_STMT(StringLiteral)
#undef MX_ENTER_SERIALIZE_StringLiteral
#undef MX_EXIT_SERIALIZE_StringLiteral

#ifndef MX_ENTER_SERIALIZE_StmtExpr
#  define MX_ENTER_SERIALIZE_StmtExpr
#endif
#ifndef MX_EXIT_SERIALIZE_StmtExpr
#  define MX_EXIT_SERIALIZE_StmtExpr
#endif

MX_BEGIN_SERIALIZE_STMT(StmtExpr)
  MX_ENTER_SERIALIZE_StmtExpr
  MX_SERIALIZE_BASE(StmtExpr, Expr)
  MX_SERIALIZE_ENTITY(StmtExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(StmtExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(StmtExpr, sub_statement, getVal40, setVal40, initVal40, SubStatement, CompoundStmt, NthStmt)
  MX_EXIT_SERIALIZE_StmtExpr
MX_END_SERIALIZE_STMT(StmtExpr)
#undef MX_ENTER_SERIALIZE_StmtExpr
#undef MX_EXIT_SERIALIZE_StmtExpr

#ifndef MX_ENTER_SERIALIZE_SourceLocExpr
#  define MX_ENTER_SERIALIZE_SourceLocExpr
#endif
#ifndef MX_EXIT_SERIALIZE_SourceLocExpr
#  define MX_EXIT_SERIALIZE_SourceLocExpr
#endif

MX_BEGIN_SERIALIZE_STMT(SourceLocExpr)
  MX_ENTER_SERIALIZE_SourceLocExpr
  MX_SERIALIZE_BASE(SourceLocExpr, Expr)
  MX_SERIALIZE_TEXT(SourceLocExpr, builtin_string, getVal63, setVal63, initVal63, BuiltinString, basic_string_view, NthStmt)
  MX_SERIALIZE_ENUM(SourceLocExpr, identifier_kind, getVal103, setVal103, initVal103, IdentifierKind, SourceLocExprIdentKind, NthStmt)
  MX_SERIALIZE_ENTITY(SourceLocExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(SourceLocExpr, is_int_type, getVal98, setVal98, initVal98, IsIntType, bool, NthStmt)
  MX_SERIALIZE_BOOL(SourceLocExpr, is_string_type, getVal99, setVal99, initVal99, IsStringType, bool, NthStmt)
  MX_EXIT_SERIALIZE_SourceLocExpr
MX_END_SERIALIZE_STMT(SourceLocExpr)
#undef MX_ENTER_SERIALIZE_SourceLocExpr
#undef MX_EXIT_SERIALIZE_SourceLocExpr

#ifndef MX_ENTER_SERIALIZE_SizeOfPackExpr
#  define MX_ENTER_SERIALIZE_SizeOfPackExpr
#endif
#ifndef MX_EXIT_SERIALIZE_SizeOfPackExpr
#  define MX_EXIT_SERIALIZE_SizeOfPackExpr
#endif

MX_BEGIN_SERIALIZE_STMT(SizeOfPackExpr)
  MX_ENTER_SERIALIZE_SizeOfPackExpr
  MX_SERIALIZE_BASE(SizeOfPackExpr, Expr)
  MX_SERIALIZE_ENTITY(SizeOfPackExpr, operator_token, getVal38, setVal38, initVal38, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SizeOfPackExpr, pack, getVal39, setVal39, initVal39, Pack, NamedDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_INT(SizeOfPackExpr, pack_length, getVal112, setVal112, initVal112, PackLength, unsigned, NthStmt)
  MX_SERIALIZE_ENTITY(SizeOfPackExpr, pack_token, getVal40, setVal40, initVal40, PackToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_PSEUDO_LIST(SizeOfPackExpr, partial_arguments, getVal105, setVal105, initVal105, PartialArguments, TemplateArgument, NthStmt)
  MX_SERIALIZE_ENTITY(SizeOfPackExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(SizeOfPackExpr, is_partially_substituted, getVal100, setVal100, initVal100, IsPartiallySubstituted, bool, NthStmt)
  MX_EXIT_SERIALIZE_SizeOfPackExpr
MX_END_SERIALIZE_STMT(SizeOfPackExpr)
#undef MX_ENTER_SERIALIZE_SizeOfPackExpr
#undef MX_EXIT_SERIALIZE_SizeOfPackExpr

#ifndef MX_ENTER_SERIALIZE_ShuffleVectorExpr
#  define MX_ENTER_SERIALIZE_ShuffleVectorExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ShuffleVectorExpr
#  define MX_EXIT_SERIALIZE_ShuffleVectorExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ShuffleVectorExpr)
  MX_ENTER_SERIALIZE_ShuffleVectorExpr
  MX_SERIALIZE_BASE(ShuffleVectorExpr, Expr)
  MX_SERIALIZE_ENTITY(ShuffleVectorExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ShuffleVectorExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ShuffleVectorExpr
MX_END_SERIALIZE_STMT(ShuffleVectorExpr)
#undef MX_ENTER_SERIALIZE_ShuffleVectorExpr
#undef MX_EXIT_SERIALIZE_ShuffleVectorExpr

#ifndef MX_ENTER_SERIALIZE_SYCLUniqueStableNameExpr
#  define MX_ENTER_SERIALIZE_SYCLUniqueStableNameExpr
#endif
#ifndef MX_EXIT_SERIALIZE_SYCLUniqueStableNameExpr
#  define MX_EXIT_SERIALIZE_SYCLUniqueStableNameExpr
#endif

MX_BEGIN_SERIALIZE_STMT(SYCLUniqueStableNameExpr)
  MX_ENTER_SERIALIZE_SYCLUniqueStableNameExpr
  MX_SERIALIZE_BASE(SYCLUniqueStableNameExpr, Expr)
  MX_SERIALIZE_TEXT(SYCLUniqueStableNameExpr, compute_name, getVal63, setVal63, initVal63, ComputeName, basic_string, NthStmt)
  MX_SERIALIZE_ENTITY(SYCLUniqueStableNameExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SYCLUniqueStableNameExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SYCLUniqueStableNameExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SYCLUniqueStableNameExpr, type_source_info, getVal41, setVal41, initVal41, TypeSourceInfo, Type, NthStmt)
  MX_EXIT_SERIALIZE_SYCLUniqueStableNameExpr
MX_END_SERIALIZE_STMT(SYCLUniqueStableNameExpr)
#undef MX_ENTER_SERIALIZE_SYCLUniqueStableNameExpr
#undef MX_EXIT_SERIALIZE_SYCLUniqueStableNameExpr

#ifndef MX_ENTER_SERIALIZE_RequiresExpr
#  define MX_ENTER_SERIALIZE_RequiresExpr
#endif
#ifndef MX_EXIT_SERIALIZE_RequiresExpr
#  define MX_EXIT_SERIALIZE_RequiresExpr
#endif

MX_BEGIN_SERIALIZE_STMT(RequiresExpr)
  MX_ENTER_SERIALIZE_RequiresExpr
  MX_SERIALIZE_BASE(RequiresExpr, Expr)
  MX_SERIALIZE_ENTITY(RequiresExpr, body, getVal38, setVal38, initVal38, Body, RequiresExprBodyDecl, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(RequiresExpr, local_parameters, getVal17, setVal17, initVal17, LocalParameters, ParmVarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(RequiresExpr, r_brace_token, getVal39, setVal39, initVal39, RBraceToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(RequiresExpr, requires_kw_token, getVal40, setVal40, initVal40, RequiresKWToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(RequiresExpr, is_satisfied, getVal98, setVal98, initVal98, IsSatisfied, bool, NthStmt)
  MX_EXIT_SERIALIZE_RequiresExpr
MX_END_SERIALIZE_STMT(RequiresExpr)
#undef MX_ENTER_SERIALIZE_RequiresExpr
#undef MX_EXIT_SERIALIZE_RequiresExpr

#ifndef MX_ENTER_SERIALIZE_RecoveryExpr
#  define MX_ENTER_SERIALIZE_RecoveryExpr
#endif
#ifndef MX_EXIT_SERIALIZE_RecoveryExpr
#  define MX_EXIT_SERIALIZE_RecoveryExpr
#endif

MX_BEGIN_SERIALIZE_STMT(RecoveryExpr)
  MX_ENTER_SERIALIZE_RecoveryExpr
  MX_SERIALIZE_BASE(RecoveryExpr, Expr)
  MX_SERIALIZE_ENTITY_LIST(RecoveryExpr, sub_expressions, getVal17, setVal17, initVal17, SubExpressions, Expr, NthStmt)
  MX_EXIT_SERIALIZE_RecoveryExpr
MX_END_SERIALIZE_STMT(RecoveryExpr)
#undef MX_ENTER_SERIALIZE_RecoveryExpr
#undef MX_EXIT_SERIALIZE_RecoveryExpr

#ifndef MX_ENTER_SERIALIZE_PseudoObjectExpr
#  define MX_ENTER_SERIALIZE_PseudoObjectExpr
#endif
#ifndef MX_EXIT_SERIALIZE_PseudoObjectExpr
#  define MX_EXIT_SERIALIZE_PseudoObjectExpr
#endif

MX_BEGIN_SERIALIZE_STMT(PseudoObjectExpr)
  MX_ENTER_SERIALIZE_PseudoObjectExpr
  MX_SERIALIZE_BASE(PseudoObjectExpr, Expr)
  MX_SERIALIZE_ENTITY(PseudoObjectExpr, result_expression, getVal38, setVal38, initVal38, ResultExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(PseudoObjectExpr, syntactic_form, getVal39, setVal39, initVal39, SyntacticForm, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(PseudoObjectExpr, semantics, getVal17, setVal17, initVal17, Semantics, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(PseudoObjectExpr, semantic_expressions, getVal23, setVal23, initVal23, SemanticExpressions, Expr, NthStmt)
  MX_EXIT_SERIALIZE_PseudoObjectExpr
MX_END_SERIALIZE_STMT(PseudoObjectExpr)
#undef MX_ENTER_SERIALIZE_PseudoObjectExpr
#undef MX_EXIT_SERIALIZE_PseudoObjectExpr

#ifndef MX_ENTER_SERIALIZE_PredefinedExpr
#  define MX_ENTER_SERIALIZE_PredefinedExpr
#endif
#ifndef MX_EXIT_SERIALIZE_PredefinedExpr
#  define MX_EXIT_SERIALIZE_PredefinedExpr
#endif

MX_BEGIN_SERIALIZE_STMT(PredefinedExpr)
  MX_ENTER_SERIALIZE_PredefinedExpr
  MX_SERIALIZE_BASE(PredefinedExpr, Expr)
  MX_SERIALIZE_ENTITY(PredefinedExpr, function_name, getVal38, setVal38, initVal38, FunctionName, StringLiteral, NthStmt)
  MX_SERIALIZE_ENUM(PredefinedExpr, identifier_kind, getVal103, setVal103, initVal103, IdentifierKind, PredefinedExprIdentKind, NthStmt)
  MX_SERIALIZE_TEXT(PredefinedExpr, identifier_kind_name, getVal63, setVal63, initVal63, IdentifierKindName, basic_string_view, NthStmt)
  MX_SERIALIZE_ENTITY(PredefinedExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt)
  MX_EXIT_SERIALIZE_PredefinedExpr
MX_END_SERIALIZE_STMT(PredefinedExpr)
#undef MX_ENTER_SERIALIZE_PredefinedExpr
#undef MX_EXIT_SERIALIZE_PredefinedExpr

#ifndef MX_ENTER_SERIALIZE_ParenListExpr
#  define MX_ENTER_SERIALIZE_ParenListExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ParenListExpr
#  define MX_EXIT_SERIALIZE_ParenListExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ParenListExpr)
  MX_ENTER_SERIALIZE_ParenListExpr
  MX_SERIALIZE_BASE(ParenListExpr, Expr)
  MX_SERIALIZE_ENTITY(ParenListExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ParenListExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(ParenListExpr, expressions, getVal17, setVal17, initVal17, Expressions, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ParenListExpr
MX_END_SERIALIZE_STMT(ParenListExpr)
#undef MX_ENTER_SERIALIZE_ParenListExpr
#undef MX_EXIT_SERIALIZE_ParenListExpr

#ifndef MX_ENTER_SERIALIZE_ParenExpr
#  define MX_ENTER_SERIALIZE_ParenExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ParenExpr
#  define MX_EXIT_SERIALIZE_ParenExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ParenExpr)
  MX_ENTER_SERIALIZE_ParenExpr
  MX_SERIALIZE_BASE(ParenExpr, Expr)
  MX_SERIALIZE_ENTITY(ParenExpr, l_paren, getVal38, setVal38, initVal38, LParen, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ParenExpr, r_paren, getVal39, setVal39, initVal39, RParen, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ParenExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ParenExpr
MX_END_SERIALIZE_STMT(ParenExpr)
#undef MX_ENTER_SERIALIZE_ParenExpr
#undef MX_EXIT_SERIALIZE_ParenExpr

#ifndef MX_ENTER_SERIALIZE_PackExpansionExpr
#  define MX_ENTER_SERIALIZE_PackExpansionExpr
#endif
#ifndef MX_EXIT_SERIALIZE_PackExpansionExpr
#  define MX_EXIT_SERIALIZE_PackExpansionExpr
#endif

MX_BEGIN_SERIALIZE_STMT(PackExpansionExpr)
  MX_ENTER_SERIALIZE_PackExpansionExpr
  MX_SERIALIZE_BASE(PackExpansionExpr, Expr)
  MX_SERIALIZE_ENTITY(PackExpansionExpr, ellipsis_token, getVal38, setVal38, initVal38, EllipsisToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_INT(PackExpansionExpr, num_expansions, getVal112, setVal112, initVal112, NumExpansions, unsigned, NthStmt)
  MX_SERIALIZE_ENTITY(PackExpansionExpr, pattern, getVal39, setVal39, initVal39, Pattern, Expr, NthStmt)
  MX_EXIT_SERIALIZE_PackExpansionExpr
MX_END_SERIALIZE_STMT(PackExpansionExpr)
#undef MX_ENTER_SERIALIZE_PackExpansionExpr
#undef MX_EXIT_SERIALIZE_PackExpansionExpr

#ifndef MX_ENTER_SERIALIZE_OverloadExpr
#  define MX_ENTER_SERIALIZE_OverloadExpr
#endif
#ifndef MX_EXIT_SERIALIZE_OverloadExpr
#  define MX_EXIT_SERIALIZE_OverloadExpr
#endif

MX_BEGIN_SERIALIZE_STMT(OverloadExpr)
  MX_ENTER_SERIALIZE_OverloadExpr
  MX_SERIALIZE_BASE(OverloadExpr, Expr)
  MX_SERIALIZE_ENTITY(OverloadExpr, l_angle_token, getVal38, setVal38, initVal38, LAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OverloadExpr, name_token, getVal39, setVal39, initVal39, NameToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OverloadExpr, naming_class, getVal40, setVal40, initVal40, NamingClass, CXXRecordDecl, NthStmt)
  MX_SERIALIZE_ENTITY(OverloadExpr, r_angle_token, getVal41, setVal41, initVal41, RAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OverloadExpr, template_keyword_token, getVal42, setVal42, initVal42, TemplateKeywordToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(OverloadExpr, has_explicit_template_arguments, getVal98, setVal98, initVal98, HasExplicitTemplateArguments, bool, NthStmt)
  MX_SERIALIZE_BOOL(OverloadExpr, has_template_keyword, getVal99, setVal99, initVal99, HasTemplateKeyword, bool, NthStmt)
  MX_EXIT_SERIALIZE_OverloadExpr
MX_END_SERIALIZE_STMT(OverloadExpr)
#undef MX_ENTER_SERIALIZE_OverloadExpr
#undef MX_EXIT_SERIALIZE_OverloadExpr

#ifndef MX_ENTER_SERIALIZE_UnresolvedMemberExpr
#  define MX_ENTER_SERIALIZE_UnresolvedMemberExpr
#endif
#ifndef MX_EXIT_SERIALIZE_UnresolvedMemberExpr
#  define MX_EXIT_SERIALIZE_UnresolvedMemberExpr
#endif

MX_BEGIN_SERIALIZE_STMT(UnresolvedMemberExpr)
  MX_ENTER_SERIALIZE_UnresolvedMemberExpr
  MX_SERIALIZE_BASE(UnresolvedMemberExpr, OverloadExpr)
  MX_SERIALIZE_ENTITY(UnresolvedMemberExpr, base, getVal43, setVal43, initVal43, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(UnresolvedMemberExpr, base_type, getVal44, setVal44, initVal44, BaseType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(UnresolvedMemberExpr, member_token, getVal45, setVal45, initVal45, MemberToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(UnresolvedMemberExpr, operator_token, getVal46, setVal46, initVal46, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(UnresolvedMemberExpr, has_unresolved_using, getVal100, setVal100, initVal100, HasUnresolvedUsing, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnresolvedMemberExpr, is_arrow, getVal101, setVal101, initVal101, IsArrow, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnresolvedMemberExpr, is_implicit_access, getVal102, setVal102, initVal102, IsImplicitAccess, bool, NthStmt)
  MX_EXIT_SERIALIZE_UnresolvedMemberExpr
MX_END_SERIALIZE_STMT(UnresolvedMemberExpr)
#undef MX_ENTER_SERIALIZE_UnresolvedMemberExpr
#undef MX_EXIT_SERIALIZE_UnresolvedMemberExpr

#ifndef MX_ENTER_SERIALIZE_UnresolvedLookupExpr
#  define MX_ENTER_SERIALIZE_UnresolvedLookupExpr
#endif
#ifndef MX_EXIT_SERIALIZE_UnresolvedLookupExpr
#  define MX_EXIT_SERIALIZE_UnresolvedLookupExpr
#endif

MX_BEGIN_SERIALIZE_STMT(UnresolvedLookupExpr)
  MX_ENTER_SERIALIZE_UnresolvedLookupExpr
  MX_SERIALIZE_BASE(UnresolvedLookupExpr, OverloadExpr)
  MX_SERIALIZE_BOOL(UnresolvedLookupExpr, is_overloaded, getVal100, setVal100, initVal100, IsOverloaded, bool, NthStmt)
  MX_SERIALIZE_BOOL(UnresolvedLookupExpr, requires_adl, getVal101, setVal101, initVal101, RequiresADL, bool, NthStmt)
  MX_EXIT_SERIALIZE_UnresolvedLookupExpr
MX_END_SERIALIZE_STMT(UnresolvedLookupExpr)
#undef MX_ENTER_SERIALIZE_UnresolvedLookupExpr
#undef MX_EXIT_SERIALIZE_UnresolvedLookupExpr

#ifndef MX_ENTER_SERIALIZE_OpaqueValueExpr
#  define MX_ENTER_SERIALIZE_OpaqueValueExpr
#endif
#ifndef MX_EXIT_SERIALIZE_OpaqueValueExpr
#  define MX_EXIT_SERIALIZE_OpaqueValueExpr
#endif

MX_BEGIN_SERIALIZE_STMT(OpaqueValueExpr)
  MX_ENTER_SERIALIZE_OpaqueValueExpr
  MX_SERIALIZE_BASE(OpaqueValueExpr, Expr)
  MX_SERIALIZE_ENTITY(OpaqueValueExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OpaqueValueExpr, source_expression, getVal39, setVal39, initVal39, SourceExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(OpaqueValueExpr, is_unique, getVal98, setVal98, initVal98, IsUnique, bool, NthStmt)
  MX_EXIT_SERIALIZE_OpaqueValueExpr
MX_END_SERIALIZE_STMT(OpaqueValueExpr)
#undef MX_ENTER_SERIALIZE_OpaqueValueExpr
#undef MX_EXIT_SERIALIZE_OpaqueValueExpr

#ifndef MX_ENTER_SERIALIZE_OffsetOfExpr
#  define MX_ENTER_SERIALIZE_OffsetOfExpr
#endif
#ifndef MX_EXIT_SERIALIZE_OffsetOfExpr
#  define MX_EXIT_SERIALIZE_OffsetOfExpr
#endif

MX_BEGIN_SERIALIZE_STMT(OffsetOfExpr)
  MX_ENTER_SERIALIZE_OffsetOfExpr
  MX_SERIALIZE_BASE(OffsetOfExpr, Expr)
  MX_SERIALIZE_ENTITY(OffsetOfExpr, operator_token, getVal38, setVal38, initVal38, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OffsetOfExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OffsetOfExpr, type_source_info, getVal40, setVal40, initVal40, TypeSourceInfo, Type, NthStmt)
  MX_EXIT_SERIALIZE_OffsetOfExpr
MX_END_SERIALIZE_STMT(OffsetOfExpr)
#undef MX_ENTER_SERIALIZE_OffsetOfExpr
#undef MX_EXIT_SERIALIZE_OffsetOfExpr

#ifndef MX_ENTER_SERIALIZE_ObjCSubscriptRefExpr
#  define MX_ENTER_SERIALIZE_ObjCSubscriptRefExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCSubscriptRefExpr
#  define MX_EXIT_SERIALIZE_ObjCSubscriptRefExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCSubscriptRefExpr)
  MX_ENTER_SERIALIZE_ObjCSubscriptRefExpr
  MX_SERIALIZE_BASE(ObjCSubscriptRefExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCSubscriptRefExpr, at_index_method_declaration, getVal38, setVal38, initVal38, AtIndexMethodDeclaration, ObjCMethodDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCSubscriptRefExpr, base_expression, getVal39, setVal39, initVal39, BaseExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCSubscriptRefExpr, key_expression, getVal40, setVal40, initVal40, KeyExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCSubscriptRefExpr, r_bracket, getVal41, setVal41, initVal41, RBracket, Token, NthStmt)
  MX_SERIALIZE_BOOL(ObjCSubscriptRefExpr, is_array_subscript_reference_expression, getVal98, setVal98, initVal98, IsArraySubscriptReferenceExpression, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCSubscriptRefExpr
MX_END_SERIALIZE_STMT(ObjCSubscriptRefExpr)
#undef MX_ENTER_SERIALIZE_ObjCSubscriptRefExpr
#undef MX_EXIT_SERIALIZE_ObjCSubscriptRefExpr

#ifndef MX_ENTER_SERIALIZE_ObjCStringLiteral
#  define MX_ENTER_SERIALIZE_ObjCStringLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCStringLiteral
#  define MX_EXIT_SERIALIZE_ObjCStringLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCStringLiteral)
  MX_ENTER_SERIALIZE_ObjCStringLiteral
  MX_SERIALIZE_BASE(ObjCStringLiteral, Expr)
  MX_SERIALIZE_ENTITY(ObjCStringLiteral, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCStringLiteral, string, getVal39, setVal39, initVal39, String, StringLiteral, NthStmt)
  MX_EXIT_SERIALIZE_ObjCStringLiteral
MX_END_SERIALIZE_STMT(ObjCStringLiteral)
#undef MX_ENTER_SERIALIZE_ObjCStringLiteral
#undef MX_EXIT_SERIALIZE_ObjCStringLiteral

#ifndef MX_ENTER_SERIALIZE_ObjCSelectorExpr
#  define MX_ENTER_SERIALIZE_ObjCSelectorExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCSelectorExpr
#  define MX_EXIT_SERIALIZE_ObjCSelectorExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCSelectorExpr)
  MX_ENTER_SERIALIZE_ObjCSelectorExpr
  MX_SERIALIZE_BASE(ObjCSelectorExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCSelectorExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCSelectorExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCSelectorExpr
MX_END_SERIALIZE_STMT(ObjCSelectorExpr)
#undef MX_ENTER_SERIALIZE_ObjCSelectorExpr
#undef MX_EXIT_SERIALIZE_ObjCSelectorExpr

#ifndef MX_ENTER_SERIALIZE_ObjCProtocolExpr
#  define MX_ENTER_SERIALIZE_ObjCProtocolExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCProtocolExpr
#  define MX_EXIT_SERIALIZE_ObjCProtocolExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCProtocolExpr)
  MX_ENTER_SERIALIZE_ObjCProtocolExpr
  MX_SERIALIZE_BASE(ObjCProtocolExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCProtocolExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCProtocolExpr, protocol, getVal39, setVal39, initVal39, Protocol, ObjCProtocolDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCProtocolExpr, protocol_id_token, getVal40, setVal40, initVal40, ProtocolIdToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCProtocolExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCProtocolExpr
MX_END_SERIALIZE_STMT(ObjCProtocolExpr)
#undef MX_ENTER_SERIALIZE_ObjCProtocolExpr
#undef MX_EXIT_SERIALIZE_ObjCProtocolExpr

#ifndef MX_ENTER_SERIALIZE_ObjCPropertyRefExpr
#  define MX_ENTER_SERIALIZE_ObjCPropertyRefExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCPropertyRefExpr
#  define MX_EXIT_SERIALIZE_ObjCPropertyRefExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCPropertyRefExpr)
  MX_ENTER_SERIALIZE_ObjCPropertyRefExpr
  MX_SERIALIZE_BASE(ObjCPropertyRefExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, class_receiver, getVal39, setVal39, initVal39, ClassReceiver, ObjCInterfaceDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, explicit_property, getVal40, setVal40, initVal40, ExplicitProperty, ObjCPropertyDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, implicit_property_getter, getVal41, setVal41, initVal41, ImplicitPropertyGetter, ObjCMethodDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, implicit_property_setter, getVal42, setVal42, initVal42, ImplicitPropertySetter, ObjCMethodDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, token, getVal43, setVal43, initVal43, Token, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, receiver_token, getVal44, setVal44, initVal44, ReceiverToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, receiver_type, getVal45, setVal45, initVal45, ReceiverType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCPropertyRefExpr, super_receiver_type, getVal46, setVal46, initVal46, SuperReceiverType, Type, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_class_receiver, getVal98, setVal98, initVal98, IsClassReceiver, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_explicit_property, getVal99, setVal99, initVal99, IsExplicitProperty, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_implicit_property, getVal100, setVal100, initVal100, IsImplicitProperty, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_messaging_getter, getVal101, setVal101, initVal101, IsMessagingGetter, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_messaging_setter, getVal102, setVal102, initVal102, IsMessagingSetter, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_object_receiver, getVal104, setVal104, initVal104, IsObjectReceiver, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCPropertyRefExpr, is_super_receiver, getVal107, setVal107, initVal107, IsSuperReceiver, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCPropertyRefExpr
MX_END_SERIALIZE_STMT(ObjCPropertyRefExpr)
#undef MX_ENTER_SERIALIZE_ObjCPropertyRefExpr
#undef MX_EXIT_SERIALIZE_ObjCPropertyRefExpr

#ifndef MX_ENTER_SERIALIZE_ObjCMessageExpr
#  define MX_ENTER_SERIALIZE_ObjCMessageExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCMessageExpr
#  define MX_EXIT_SERIALIZE_ObjCMessageExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCMessageExpr)
  MX_ENTER_SERIALIZE_ObjCMessageExpr
  MX_SERIALIZE_BASE(ObjCMessageExpr, Expr)
  MX_SERIALIZE_ENTITY_LIST(ObjCMessageExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, call_return_type, getVal38, setVal38, initVal38, CallReturnType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, class_receiver, getVal39, setVal39, initVal39, ClassReceiver, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, class_receiver_type_info, getVal40, setVal40, initVal40, ClassReceiverTypeInfo, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, instance_receiver, getVal41, setVal41, initVal41, InstanceReceiver, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, left_token, getVal42, setVal42, initVal42, LeftToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, method_declaration, getVal43, setVal43, initVal43, MethodDeclaration, ObjCMethodDecl, NthStmt)
  MX_SERIALIZE_ENUM(ObjCMessageExpr, method_family, getVal103, setVal103, initVal103, MethodFamily, ObjCMethodFamily, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, receiver_interface, getVal44, setVal44, initVal44, ReceiverInterface, ObjCInterfaceDecl, NthStmt)
  MX_SERIALIZE_ENUM(ObjCMessageExpr, receiver_kind, getVal106, setVal106, initVal106, ReceiverKind, ObjCMessageExprReceiverKind, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, receiver_type, getVal47, setVal47, initVal47, ReceiverType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, right_token, getVal48, setVal48, initVal48, RightToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, selector_start_token, getVal49, setVal49, initVal49, SelectorStartToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, super_token, getVal50, setVal50, initVal50, SuperToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCMessageExpr, super_type, getVal51, setVal51, initVal51, SuperType, Type, NthStmt)
  MX_SERIALIZE_BOOL(ObjCMessageExpr, is_class_message, getVal98, setVal98, initVal98, IsClassMessage, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCMessageExpr, is_delegate_initializer_call, getVal99, setVal99, initVal99, IsDelegateInitializerCall, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCMessageExpr, is_implicit, getVal100, setVal100, initVal100, IsImplicit, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCMessageExpr, is_instance_message, getVal101, setVal101, initVal101, IsInstanceMessage, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(ObjCMessageExpr, selector_tokens, getVal23, setVal23, initVal23, SelectorTokens, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCMessageExpr
MX_END_SERIALIZE_STMT(ObjCMessageExpr)
#undef MX_ENTER_SERIALIZE_ObjCMessageExpr
#undef MX_EXIT_SERIALIZE_ObjCMessageExpr

#ifndef MX_ENTER_SERIALIZE_ObjCIvarRefExpr
#  define MX_ENTER_SERIALIZE_ObjCIvarRefExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCIvarRefExpr
#  define MX_EXIT_SERIALIZE_ObjCIvarRefExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCIvarRefExpr)
  MX_ENTER_SERIALIZE_ObjCIvarRefExpr
  MX_SERIALIZE_BASE(ObjCIvarRefExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCIvarRefExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCIvarRefExpr, declaration, getVal39, setVal39, initVal39, Declaration, ObjCIvarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCIvarRefExpr, token, getVal40, setVal40, initVal40, Token, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCIvarRefExpr, operation_token, getVal41, setVal41, initVal41, OperationToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(ObjCIvarRefExpr, is_arrow, getVal98, setVal98, initVal98, IsArrow, bool, NthStmt)
  MX_SERIALIZE_BOOL(ObjCIvarRefExpr, is_free_instance_variable, getVal99, setVal99, initVal99, IsFreeInstanceVariable, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCIvarRefExpr
MX_END_SERIALIZE_STMT(ObjCIvarRefExpr)
#undef MX_ENTER_SERIALIZE_ObjCIvarRefExpr
#undef MX_EXIT_SERIALIZE_ObjCIvarRefExpr

#ifndef MX_ENTER_SERIALIZE_ObjCIsaExpr
#  define MX_ENTER_SERIALIZE_ObjCIsaExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCIsaExpr
#  define MX_EXIT_SERIALIZE_ObjCIsaExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCIsaExpr)
  MX_ENTER_SERIALIZE_ObjCIsaExpr
  MX_SERIALIZE_BASE(ObjCIsaExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCIsaExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCIsaExpr, base_token_end, getVal39, setVal39, initVal39, BaseTokenEnd, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCIsaExpr, isa_member_token, getVal40, setVal40, initVal40, IsaMemberToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCIsaExpr, operation_token, getVal41, setVal41, initVal41, OperationToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(ObjCIsaExpr, is_arrow, getVal98, setVal98, initVal98, IsArrow, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCIsaExpr
MX_END_SERIALIZE_STMT(ObjCIsaExpr)
#undef MX_ENTER_SERIALIZE_ObjCIsaExpr
#undef MX_EXIT_SERIALIZE_ObjCIsaExpr

#ifndef MX_ENTER_SERIALIZE_ObjCIndirectCopyRestoreExpr
#  define MX_ENTER_SERIALIZE_ObjCIndirectCopyRestoreExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCIndirectCopyRestoreExpr
#  define MX_EXIT_SERIALIZE_ObjCIndirectCopyRestoreExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCIndirectCopyRestoreExpr)
  MX_ENTER_SERIALIZE_ObjCIndirectCopyRestoreExpr
  MX_SERIALIZE_BASE(ObjCIndirectCopyRestoreExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCIndirectCopyRestoreExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(ObjCIndirectCopyRestoreExpr, should_copy, getVal98, setVal98, initVal98, ShouldCopy, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCIndirectCopyRestoreExpr
MX_END_SERIALIZE_STMT(ObjCIndirectCopyRestoreExpr)
#undef MX_ENTER_SERIALIZE_ObjCIndirectCopyRestoreExpr
#undef MX_EXIT_SERIALIZE_ObjCIndirectCopyRestoreExpr

#ifndef MX_ENTER_SERIALIZE_ObjCEncodeExpr
#  define MX_ENTER_SERIALIZE_ObjCEncodeExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCEncodeExpr
#  define MX_EXIT_SERIALIZE_ObjCEncodeExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCEncodeExpr)
  MX_ENTER_SERIALIZE_ObjCEncodeExpr
  MX_SERIALIZE_BASE(ObjCEncodeExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCEncodeExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCEncodeExpr, encoded_type, getVal39, setVal39, initVal39, EncodedType, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCEncodeExpr, encoded_type_source_info, getVal40, setVal40, initVal40, EncodedTypeSourceInfo, Type, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCEncodeExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_ObjCEncodeExpr
MX_END_SERIALIZE_STMT(ObjCEncodeExpr)
#undef MX_ENTER_SERIALIZE_ObjCEncodeExpr
#undef MX_EXIT_SERIALIZE_ObjCEncodeExpr

#ifndef MX_ENTER_SERIALIZE_ObjCDictionaryLiteral
#  define MX_ENTER_SERIALIZE_ObjCDictionaryLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCDictionaryLiteral
#  define MX_EXIT_SERIALIZE_ObjCDictionaryLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCDictionaryLiteral)
  MX_ENTER_SERIALIZE_ObjCDictionaryLiteral
  MX_SERIALIZE_BASE(ObjCDictionaryLiteral, Expr)
  MX_SERIALIZE_ENTITY(ObjCDictionaryLiteral, dictionary_with_objects_method, getVal38, setVal38, initVal38, DictionaryWithObjectsMethod, ObjCMethodDecl, NthStmt)
  MX_EXIT_SERIALIZE_ObjCDictionaryLiteral
MX_END_SERIALIZE_STMT(ObjCDictionaryLiteral)
#undef MX_ENTER_SERIALIZE_ObjCDictionaryLiteral
#undef MX_EXIT_SERIALIZE_ObjCDictionaryLiteral

#ifndef MX_ENTER_SERIALIZE_ObjCBoxedExpr
#  define MX_ENTER_SERIALIZE_ObjCBoxedExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCBoxedExpr
#  define MX_EXIT_SERIALIZE_ObjCBoxedExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCBoxedExpr)
  MX_ENTER_SERIALIZE_ObjCBoxedExpr
  MX_SERIALIZE_BASE(ObjCBoxedExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCBoxedExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCBoxedExpr, boxing_method, getVal39, setVal39, initVal39, BoxingMethod, ObjCMethodDecl, NthStmt)
  MX_SERIALIZE_ENTITY(ObjCBoxedExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(ObjCBoxedExpr, is_expressible_as_constant_initializer, getVal98, setVal98, initVal98, IsExpressibleAsConstantInitializer, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCBoxedExpr
MX_END_SERIALIZE_STMT(ObjCBoxedExpr)
#undef MX_ENTER_SERIALIZE_ObjCBoxedExpr
#undef MX_EXIT_SERIALIZE_ObjCBoxedExpr

#ifndef MX_ENTER_SERIALIZE_ObjCBoolLiteralExpr
#  define MX_ENTER_SERIALIZE_ObjCBoolLiteralExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCBoolLiteralExpr
#  define MX_EXIT_SERIALIZE_ObjCBoolLiteralExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCBoolLiteralExpr)
  MX_ENTER_SERIALIZE_ObjCBoolLiteralExpr
  MX_SERIALIZE_BASE(ObjCBoolLiteralExpr, Expr)
  MX_SERIALIZE_ENTITY(ObjCBoolLiteralExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(ObjCBoolLiteralExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCBoolLiteralExpr
MX_END_SERIALIZE_STMT(ObjCBoolLiteralExpr)
#undef MX_ENTER_SERIALIZE_ObjCBoolLiteralExpr
#undef MX_EXIT_SERIALIZE_ObjCBoolLiteralExpr

#ifndef MX_ENTER_SERIALIZE_ObjCAvailabilityCheckExpr
#  define MX_ENTER_SERIALIZE_ObjCAvailabilityCheckExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAvailabilityCheckExpr
#  define MX_EXIT_SERIALIZE_ObjCAvailabilityCheckExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCAvailabilityCheckExpr)
  MX_ENTER_SERIALIZE_ObjCAvailabilityCheckExpr
  MX_SERIALIZE_BASE(ObjCAvailabilityCheckExpr, Expr)
  MX_SERIALIZE_BOOL(ObjCAvailabilityCheckExpr, has_version, getVal98, setVal98, initVal98, HasVersion, bool, NthStmt)
  MX_EXIT_SERIALIZE_ObjCAvailabilityCheckExpr
MX_END_SERIALIZE_STMT(ObjCAvailabilityCheckExpr)
#undef MX_ENTER_SERIALIZE_ObjCAvailabilityCheckExpr
#undef MX_EXIT_SERIALIZE_ObjCAvailabilityCheckExpr

#ifndef MX_ENTER_SERIALIZE_ObjCArrayLiteral
#  define MX_ENTER_SERIALIZE_ObjCArrayLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCArrayLiteral
#  define MX_EXIT_SERIALIZE_ObjCArrayLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(ObjCArrayLiteral)
  MX_ENTER_SERIALIZE_ObjCArrayLiteral
  MX_SERIALIZE_BASE(ObjCArrayLiteral, Expr)
  MX_SERIALIZE_ENTITY(ObjCArrayLiteral, array_with_objects_method, getVal38, setVal38, initVal38, ArrayWithObjectsMethod, ObjCMethodDecl, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(ObjCArrayLiteral, elements, getVal17, setVal17, initVal17, Elements, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ObjCArrayLiteral
MX_END_SERIALIZE_STMT(ObjCArrayLiteral)
#undef MX_ENTER_SERIALIZE_ObjCArrayLiteral
#undef MX_EXIT_SERIALIZE_ObjCArrayLiteral

#ifndef MX_ENTER_SERIALIZE_OMPIteratorExpr
#  define MX_ENTER_SERIALIZE_OMPIteratorExpr
#endif
#ifndef MX_EXIT_SERIALIZE_OMPIteratorExpr
#  define MX_EXIT_SERIALIZE_OMPIteratorExpr
#endif

MX_BEGIN_SERIALIZE_STMT(OMPIteratorExpr)
  MX_ENTER_SERIALIZE_OMPIteratorExpr
  MX_SERIALIZE_BASE(OMPIteratorExpr, Expr)
  MX_SERIALIZE_ENTITY(OMPIteratorExpr, iterator_kw_token, getVal38, setVal38, initVal38, IteratorKwToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OMPIteratorExpr, l_paren_token, getVal39, setVal39, initVal39, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OMPIteratorExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_OMPIteratorExpr
MX_END_SERIALIZE_STMT(OMPIteratorExpr)
#undef MX_ENTER_SERIALIZE_OMPIteratorExpr
#undef MX_EXIT_SERIALIZE_OMPIteratorExpr

#ifndef MX_ENTER_SERIALIZE_OMPArrayShapingExpr
#  define MX_ENTER_SERIALIZE_OMPArrayShapingExpr
#endif
#ifndef MX_EXIT_SERIALIZE_OMPArrayShapingExpr
#  define MX_EXIT_SERIALIZE_OMPArrayShapingExpr
#endif

MX_BEGIN_SERIALIZE_STMT(OMPArrayShapingExpr)
  MX_ENTER_SERIALIZE_OMPArrayShapingExpr
  MX_SERIALIZE_BASE(OMPArrayShapingExpr, Expr)
  MX_SERIALIZE_ENTITY(OMPArrayShapingExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(OMPArrayShapingExpr, dimensions, getVal17, setVal17, initVal17, Dimensions, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArrayShapingExpr, l_paren_token, getVal39, setVal39, initVal39, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArrayShapingExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_OMPArrayShapingExpr
MX_END_SERIALIZE_STMT(OMPArrayShapingExpr)
#undef MX_ENTER_SERIALIZE_OMPArrayShapingExpr
#undef MX_EXIT_SERIALIZE_OMPArrayShapingExpr

#ifndef MX_ENTER_SERIALIZE_OMPArraySectionExpr
#  define MX_ENTER_SERIALIZE_OMPArraySectionExpr
#endif
#ifndef MX_EXIT_SERIALIZE_OMPArraySectionExpr
#  define MX_EXIT_SERIALIZE_OMPArraySectionExpr
#endif

MX_BEGIN_SERIALIZE_STMT(OMPArraySectionExpr)
  MX_ENTER_SERIALIZE_OMPArraySectionExpr
  MX_SERIALIZE_BASE(OMPArraySectionExpr, Expr)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, colon_token_first, getVal39, setVal39, initVal39, ColonTokenFirst, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, colon_token_second, getVal40, setVal40, initVal40, ColonTokenSecond, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, length, getVal41, setVal41, initVal41, Length, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, lower_bound, getVal42, setVal42, initVal42, LowerBound, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, r_bracket_token, getVal43, setVal43, initVal43, RBracketToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(OMPArraySectionExpr, stride, getVal44, setVal44, initVal44, Stride, Expr, NthStmt)
  MX_EXIT_SERIALIZE_OMPArraySectionExpr
MX_END_SERIALIZE_STMT(OMPArraySectionExpr)
#undef MX_ENTER_SERIALIZE_OMPArraySectionExpr
#undef MX_EXIT_SERIALIZE_OMPArraySectionExpr

#ifndef MX_ENTER_SERIALIZE_NoInitExpr
#  define MX_ENTER_SERIALIZE_NoInitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_NoInitExpr
#  define MX_EXIT_SERIALIZE_NoInitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(NoInitExpr)
  MX_ENTER_SERIALIZE_NoInitExpr
  MX_SERIALIZE_BASE(NoInitExpr, Expr)
  MX_EXIT_SERIALIZE_NoInitExpr
MX_END_SERIALIZE_STMT(NoInitExpr)
#undef MX_ENTER_SERIALIZE_NoInitExpr
#undef MX_EXIT_SERIALIZE_NoInitExpr

#ifndef MX_ENTER_SERIALIZE_MemberExpr
#  define MX_ENTER_SERIALIZE_MemberExpr
#endif
#ifndef MX_EXIT_SERIALIZE_MemberExpr
#  define MX_EXIT_SERIALIZE_MemberExpr
#endif

MX_BEGIN_SERIALIZE_STMT(MemberExpr)
  MX_ENTER_SERIALIZE_MemberExpr
  MX_SERIALIZE_BASE(MemberExpr, Expr)
  MX_SERIALIZE_ENTITY(MemberExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(MemberExpr, l_angle_token, getVal39, setVal39, initVal39, LAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MemberExpr, member_declaration, getVal40, setVal40, initVal40, MemberDeclaration, ValueDecl, NthStmt)
  MX_SERIALIZE_ENTITY(MemberExpr, member_token, getVal41, setVal41, initVal41, MemberToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MemberExpr, operator_token, getVal42, setVal42, initVal42, OperatorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MemberExpr, r_angle_token, getVal43, setVal43, initVal43, RAngleToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MemberExpr, template_keyword_token, getVal44, setVal44, initVal44, TemplateKeywordToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(MemberExpr, had_multiple_candidates, getVal98, setVal98, initVal98, HadMultipleCandidates, bool, NthStmt)
  MX_SERIALIZE_BOOL(MemberExpr, has_explicit_template_arguments, getVal99, setVal99, initVal99, HasExplicitTemplateArguments, bool, NthStmt)
  MX_SERIALIZE_BOOL(MemberExpr, has_qualifier, getVal100, setVal100, initVal100, HasQualifier, bool, NthStmt)
  MX_SERIALIZE_BOOL(MemberExpr, has_template_keyword, getVal101, setVal101, initVal101, HasTemplateKeyword, bool, NthStmt)
  MX_SERIALIZE_BOOL(MemberExpr, is_arrow, getVal102, setVal102, initVal102, IsArrow, bool, NthStmt)
  MX_SERIALIZE_BOOL(MemberExpr, is_implicit_access, getVal104, setVal104, initVal104, IsImplicitAccess, bool, NthStmt)
  MX_SERIALIZE_ENUM(MemberExpr, is_non_odr_use, getVal103, setVal103, initVal103, IsNonOdrUse, NonOdrUseReason, NthStmt)
  MX_EXIT_SERIALIZE_MemberExpr
MX_END_SERIALIZE_STMT(MemberExpr)
#undef MX_ENTER_SERIALIZE_MemberExpr
#undef MX_EXIT_SERIALIZE_MemberExpr

#ifndef MX_ENTER_SERIALIZE_MatrixSubscriptExpr
#  define MX_ENTER_SERIALIZE_MatrixSubscriptExpr
#endif
#ifndef MX_EXIT_SERIALIZE_MatrixSubscriptExpr
#  define MX_EXIT_SERIALIZE_MatrixSubscriptExpr
#endif

MX_BEGIN_SERIALIZE_STMT(MatrixSubscriptExpr)
  MX_ENTER_SERIALIZE_MatrixSubscriptExpr
  MX_SERIALIZE_BASE(MatrixSubscriptExpr, Expr)
  MX_SERIALIZE_ENTITY(MatrixSubscriptExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(MatrixSubscriptExpr, column_index, getVal39, setVal39, initVal39, ColumnIndex, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(MatrixSubscriptExpr, r_bracket_token, getVal40, setVal40, initVal40, RBracketToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MatrixSubscriptExpr, row_index, getVal41, setVal41, initVal41, RowIndex, Expr, NthStmt)
  MX_SERIALIZE_BOOL(MatrixSubscriptExpr, is_incomplete, getVal98, setVal98, initVal98, IsIncomplete, bool, NthStmt)
  MX_EXIT_SERIALIZE_MatrixSubscriptExpr
MX_END_SERIALIZE_STMT(MatrixSubscriptExpr)
#undef MX_ENTER_SERIALIZE_MatrixSubscriptExpr
#undef MX_EXIT_SERIALIZE_MatrixSubscriptExpr

#ifndef MX_ENTER_SERIALIZE_MaterializeTemporaryExpr
#  define MX_ENTER_SERIALIZE_MaterializeTemporaryExpr
#endif
#ifndef MX_EXIT_SERIALIZE_MaterializeTemporaryExpr
#  define MX_EXIT_SERIALIZE_MaterializeTemporaryExpr
#endif

MX_BEGIN_SERIALIZE_STMT(MaterializeTemporaryExpr)
  MX_ENTER_SERIALIZE_MaterializeTemporaryExpr
  MX_SERIALIZE_BASE(MaterializeTemporaryExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(MaterializeTemporaryExpr, extending_declaration, getVal38, setVal38, initVal38, ExtendingDeclaration, ValueDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(MaterializeTemporaryExpr, lifetime_extended_temporary_declaration, getVal39, setVal39, initVal39, LifetimeExtendedTemporaryDeclaration, LifetimeExtendedTemporaryDecl, NthStmt)
  MX_SERIALIZE_ENUM(MaterializeTemporaryExpr, storage_duration, getVal103, setVal103, initVal103, StorageDuration, StorageDuration, NthStmt)
  MX_SERIALIZE_ENTITY(MaterializeTemporaryExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(MaterializeTemporaryExpr, is_bound_to_lvalue_reference, getVal100, setVal100, initVal100, IsBoundToLvalueReference, bool, NthStmt)
  MX_SERIALIZE_BOOL(MaterializeTemporaryExpr, is_usable_in_constant_expressions, getVal101, setVal101, initVal101, IsUsableInConstantExpressions, bool, NthStmt)
  MX_EXIT_SERIALIZE_MaterializeTemporaryExpr
MX_END_SERIALIZE_STMT(MaterializeTemporaryExpr)
#undef MX_ENTER_SERIALIZE_MaterializeTemporaryExpr
#undef MX_EXIT_SERIALIZE_MaterializeTemporaryExpr

#ifndef MX_ENTER_SERIALIZE_MSPropertySubscriptExpr
#  define MX_ENTER_SERIALIZE_MSPropertySubscriptExpr
#endif
#ifndef MX_EXIT_SERIALIZE_MSPropertySubscriptExpr
#  define MX_EXIT_SERIALIZE_MSPropertySubscriptExpr
#endif

MX_BEGIN_SERIALIZE_STMT(MSPropertySubscriptExpr)
  MX_ENTER_SERIALIZE_MSPropertySubscriptExpr
  MX_SERIALIZE_BASE(MSPropertySubscriptExpr, Expr)
  MX_SERIALIZE_ENTITY(MSPropertySubscriptExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(MSPropertySubscriptExpr, index, getVal39, setVal39, initVal39, Index, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(MSPropertySubscriptExpr, r_bracket_token, getVal40, setVal40, initVal40, RBracketToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_MSPropertySubscriptExpr
MX_END_SERIALIZE_STMT(MSPropertySubscriptExpr)
#undef MX_ENTER_SERIALIZE_MSPropertySubscriptExpr
#undef MX_EXIT_SERIALIZE_MSPropertySubscriptExpr

#ifndef MX_ENTER_SERIALIZE_MSPropertyRefExpr
#  define MX_ENTER_SERIALIZE_MSPropertyRefExpr
#endif
#ifndef MX_EXIT_SERIALIZE_MSPropertyRefExpr
#  define MX_EXIT_SERIALIZE_MSPropertyRefExpr
#endif

MX_BEGIN_SERIALIZE_STMT(MSPropertyRefExpr)
  MX_ENTER_SERIALIZE_MSPropertyRefExpr
  MX_SERIALIZE_BASE(MSPropertyRefExpr, Expr)
  MX_SERIALIZE_ENTITY(MSPropertyRefExpr, base_expression, getVal38, setVal38, initVal38, BaseExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(MSPropertyRefExpr, member_token, getVal39, setVal39, initVal39, MemberToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(MSPropertyRefExpr, property_declaration, getVal40, setVal40, initVal40, PropertyDeclaration, MSPropertyDecl, NthStmt)
  MX_SERIALIZE_BOOL(MSPropertyRefExpr, is_arrow, getVal98, setVal98, initVal98, IsArrow, bool, NthStmt)
  MX_SERIALIZE_BOOL(MSPropertyRefExpr, is_implicit_access, getVal99, setVal99, initVal99, IsImplicitAccess, bool, NthStmt)
  MX_EXIT_SERIALIZE_MSPropertyRefExpr
MX_END_SERIALIZE_STMT(MSPropertyRefExpr)
#undef MX_ENTER_SERIALIZE_MSPropertyRefExpr
#undef MX_EXIT_SERIALIZE_MSPropertyRefExpr

#ifndef MX_ENTER_SERIALIZE_LambdaExpr
#  define MX_ENTER_SERIALIZE_LambdaExpr
#endif
#ifndef MX_EXIT_SERIALIZE_LambdaExpr
#  define MX_EXIT_SERIALIZE_LambdaExpr
#endif

MX_BEGIN_SERIALIZE_STMT(LambdaExpr)
  MX_ENTER_SERIALIZE_LambdaExpr
  MX_SERIALIZE_BASE(LambdaExpr, Expr)
  MX_SERIALIZE_ENTITY(LambdaExpr, body, getVal38, setVal38, initVal38, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(LambdaExpr, call_operator, getVal39, setVal39, initVal39, CallOperator, CXXMethodDecl, NthStmt)
  MX_SERIALIZE_ENUM(LambdaExpr, capture_default, getVal103, setVal103, initVal103, CaptureDefault, LambdaCaptureDefault, NthStmt)
  MX_SERIALIZE_ENTITY(LambdaExpr, capture_default_token, getVal40, setVal40, initVal40, CaptureDefaultToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(LambdaExpr, compound_statement_body, getVal41, setVal41, initVal41, CompoundStatementBody, CompoundStmt, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(LambdaExpr, explicit_template_parameters, getVal17, setVal17, initVal17, ExplicitTemplateParameters, NamedDecl, NthStmt)
  MX_SERIALIZE_ENTITY(LambdaExpr, lambda_class, getVal44, setVal44, initVal44, LambdaClass, CXXRecordDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_PSEUDO(LambdaExpr, template_parameter_list, getVal112, setVal112, initVal112, TemplateParameterList, TemplateParameterList, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(LambdaExpr, trailing_requires_clause, getVal45, setVal45, initVal45, TrailingRequiresClause, Expr, NthStmt)
  MX_SERIALIZE_BOOL(LambdaExpr, has_explicit_parameters, getVal100, setVal100, initVal100, HasExplicitParameters, bool, NthStmt)
  MX_SERIALIZE_BOOL(LambdaExpr, has_explicit_result_type, getVal101, setVal101, initVal101, HasExplicitResultType, bool, NthStmt)
  MX_SERIALIZE_BOOL(LambdaExpr, is_generic_lambda, getVal102, setVal102, initVal102, IsGenericLambda, bool, NthStmt)
  MX_SERIALIZE_BOOL(LambdaExpr, is_mutable, getVal104, setVal104, initVal104, IsMutable, bool, NthStmt)
  MX_EXIT_SERIALIZE_LambdaExpr
MX_END_SERIALIZE_STMT(LambdaExpr)
#undef MX_ENTER_SERIALIZE_LambdaExpr
#undef MX_EXIT_SERIALIZE_LambdaExpr

#ifndef MX_ENTER_SERIALIZE_IntegerLiteral
#  define MX_ENTER_SERIALIZE_IntegerLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_IntegerLiteral
#  define MX_EXIT_SERIALIZE_IntegerLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(IntegerLiteral)
  MX_ENTER_SERIALIZE_IntegerLiteral
  MX_SERIALIZE_BASE(IntegerLiteral, Expr)
  MX_SERIALIZE_ENTITY(IntegerLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_EXIT_SERIALIZE_IntegerLiteral
MX_END_SERIALIZE_STMT(IntegerLiteral)
#undef MX_ENTER_SERIALIZE_IntegerLiteral
#undef MX_EXIT_SERIALIZE_IntegerLiteral

#ifndef MX_ENTER_SERIALIZE_InitListExpr
#  define MX_ENTER_SERIALIZE_InitListExpr
#endif
#ifndef MX_EXIT_SERIALIZE_InitListExpr
#  define MX_EXIT_SERIALIZE_InitListExpr
#endif

MX_BEGIN_SERIALIZE_STMT(InitListExpr)
  MX_ENTER_SERIALIZE_InitListExpr
  MX_SERIALIZE_BASE(InitListExpr, Expr)
  MX_SERIALIZE_OPTIONAL_ENTITY(InitListExpr, array_filler, getVal38, setVal38, initVal38, ArrayFiller, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(InitListExpr, initialized_field_in_union, getVal39, setVal39, initVal39, InitializedFieldInUnion, FieldDecl, NthStmt)
  MX_SERIALIZE_ENTITY(InitListExpr, l_brace_token, getVal40, setVal40, initVal40, LBraceToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(InitListExpr, r_brace_token, getVal41, setVal41, initVal41, RBraceToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(InitListExpr, semantic_form, getVal42, setVal42, initVal42, SemanticForm, InitListExpr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(InitListExpr, syntactic_form, getVal43, setVal43, initVal43, SyntacticForm, InitListExpr, NthStmt)
  MX_SERIALIZE_BOOL(InitListExpr, had_array_range_designator, getVal102, setVal102, initVal102, HadArrayRangeDesignator, bool, NthStmt)
  MX_SERIALIZE_BOOL(InitListExpr, has_array_filler, getVal104, setVal104, initVal104, HasArrayFiller, bool, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(InitListExpr, initializers, getVal17, setVal17, initVal17, Initializers, Expr, NthStmt)
  MX_SERIALIZE_BOOL(InitListExpr, is_explicit, getVal107, setVal107, initVal107, IsExplicit, bool, NthStmt)
  MX_SERIALIZE_BOOL(InitListExpr, is_semantic_form, getVal108, setVal108, initVal108, IsSemanticForm, bool, NthStmt)
  MX_SERIALIZE_BOOL(InitListExpr, is_string_literal_initializer, getVal109, setVal109, initVal109, IsStringLiteralInitializer, bool, NthStmt)
  MX_SERIALIZE_BOOL(InitListExpr, is_syntactic_form, getVal110, setVal110, initVal110, IsSyntacticForm, bool, NthStmt)
  MX_SERIALIZE_OPTIONAL_BOOL(InitListExpr, is_transparent, getVal111, setVal111, initVal111, IsTransparent, bool, NthStmt)
  MX_EXIT_SERIALIZE_InitListExpr
MX_END_SERIALIZE_STMT(InitListExpr)
#undef MX_ENTER_SERIALIZE_InitListExpr
#undef MX_EXIT_SERIALIZE_InitListExpr

#ifndef MX_ENTER_SERIALIZE_ImplicitValueInitExpr
#  define MX_ENTER_SERIALIZE_ImplicitValueInitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ImplicitValueInitExpr
#  define MX_EXIT_SERIALIZE_ImplicitValueInitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ImplicitValueInitExpr)
  MX_ENTER_SERIALIZE_ImplicitValueInitExpr
  MX_SERIALIZE_BASE(ImplicitValueInitExpr, Expr)
  MX_EXIT_SERIALIZE_ImplicitValueInitExpr
MX_END_SERIALIZE_STMT(ImplicitValueInitExpr)
#undef MX_ENTER_SERIALIZE_ImplicitValueInitExpr
#undef MX_EXIT_SERIALIZE_ImplicitValueInitExpr

#ifndef MX_ENTER_SERIALIZE_ImaginaryLiteral
#  define MX_ENTER_SERIALIZE_ImaginaryLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_ImaginaryLiteral
#  define MX_EXIT_SERIALIZE_ImaginaryLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(ImaginaryLiteral)
  MX_ENTER_SERIALIZE_ImaginaryLiteral
  MX_SERIALIZE_BASE(ImaginaryLiteral, Expr)
  MX_SERIALIZE_ENTITY(ImaginaryLiteral, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_ImaginaryLiteral
MX_END_SERIALIZE_STMT(ImaginaryLiteral)
#undef MX_ENTER_SERIALIZE_ImaginaryLiteral
#undef MX_EXIT_SERIALIZE_ImaginaryLiteral

#ifndef MX_ENTER_SERIALIZE_GenericSelectionExpr
#  define MX_ENTER_SERIALIZE_GenericSelectionExpr
#endif
#ifndef MX_EXIT_SERIALIZE_GenericSelectionExpr
#  define MX_EXIT_SERIALIZE_GenericSelectionExpr
#endif

MX_BEGIN_SERIALIZE_STMT(GenericSelectionExpr)
  MX_ENTER_SERIALIZE_GenericSelectionExpr
  MX_SERIALIZE_BASE(GenericSelectionExpr, Expr)
  MX_SERIALIZE_ENTITY_LIST(GenericSelectionExpr, association_expressions, getVal17, setVal17, initVal17, AssociationExpressions, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(GenericSelectionExpr, controlling_expression, getVal38, setVal38, initVal38, ControllingExpression, Expr, NthStmt)
  MX_SERIALIZE_ENTITY(GenericSelectionExpr, default_token, getVal39, setVal39, initVal39, DefaultToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(GenericSelectionExpr, generic_token, getVal40, setVal40, initVal40, GenericToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(GenericSelectionExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(GenericSelectionExpr, result_expression, getVal42, setVal42, initVal42, ResultExpression, Expr, NthStmt)
  MX_SERIALIZE_BOOL(GenericSelectionExpr, is_result_dependent, getVal98, setVal98, initVal98, IsResultDependent, bool, NthStmt)
  MX_EXIT_SERIALIZE_GenericSelectionExpr
MX_END_SERIALIZE_STMT(GenericSelectionExpr)
#undef MX_ENTER_SERIALIZE_GenericSelectionExpr
#undef MX_EXIT_SERIALIZE_GenericSelectionExpr

#ifndef MX_ENTER_SERIALIZE_GNUNullExpr
#  define MX_ENTER_SERIALIZE_GNUNullExpr
#endif
#ifndef MX_EXIT_SERIALIZE_GNUNullExpr
#  define MX_EXIT_SERIALIZE_GNUNullExpr
#endif

MX_BEGIN_SERIALIZE_STMT(GNUNullExpr)
  MX_ENTER_SERIALIZE_GNUNullExpr
  MX_SERIALIZE_BASE(GNUNullExpr, Expr)
  MX_SERIALIZE_ENTITY(GNUNullExpr, token_token, getVal38, setVal38, initVal38, TokenToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_GNUNullExpr
MX_END_SERIALIZE_STMT(GNUNullExpr)
#undef MX_ENTER_SERIALIZE_GNUNullExpr
#undef MX_EXIT_SERIALIZE_GNUNullExpr

#ifndef MX_ENTER_SERIALIZE_FunctionParmPackExpr
#  define MX_ENTER_SERIALIZE_FunctionParmPackExpr
#endif
#ifndef MX_EXIT_SERIALIZE_FunctionParmPackExpr
#  define MX_EXIT_SERIALIZE_FunctionParmPackExpr
#endif

MX_BEGIN_SERIALIZE_STMT(FunctionParmPackExpr)
  MX_ENTER_SERIALIZE_FunctionParmPackExpr
  MX_SERIALIZE_BASE(FunctionParmPackExpr, Expr)
  MX_SERIALIZE_ENTITY(FunctionParmPackExpr, parameter_pack, getVal38, setVal38, initVal38, ParameterPack, VarDecl, NthStmt)
  MX_SERIALIZE_ENTITY(FunctionParmPackExpr, parameter_pack_token, getVal39, setVal39, initVal39, ParameterPackToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY_LIST(FunctionParmPackExpr, expansions, getVal17, setVal17, initVal17, Expansions, VarDecl, NthStmt)
  MX_EXIT_SERIALIZE_FunctionParmPackExpr
MX_END_SERIALIZE_STMT(FunctionParmPackExpr)
#undef MX_ENTER_SERIALIZE_FunctionParmPackExpr
#undef MX_EXIT_SERIALIZE_FunctionParmPackExpr

#ifndef MX_ENTER_SERIALIZE_FullExpr
#  define MX_ENTER_SERIALIZE_FullExpr
#endif
#ifndef MX_EXIT_SERIALIZE_FullExpr
#  define MX_EXIT_SERIALIZE_FullExpr
#endif

MX_BEGIN_SERIALIZE_STMT(FullExpr)
  MX_ENTER_SERIALIZE_FullExpr
  MX_SERIALIZE_BASE(FullExpr, Expr)
  MX_SERIALIZE_ENTITY(FullExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt)
  MX_EXIT_SERIALIZE_FullExpr
MX_END_SERIALIZE_STMT(FullExpr)
#undef MX_ENTER_SERIALIZE_FullExpr
#undef MX_EXIT_SERIALIZE_FullExpr

#ifndef MX_ENTER_SERIALIZE_ExprWithCleanups
#  define MX_ENTER_SERIALIZE_ExprWithCleanups
#endif
#ifndef MX_EXIT_SERIALIZE_ExprWithCleanups
#  define MX_EXIT_SERIALIZE_ExprWithCleanups
#endif

MX_BEGIN_SERIALIZE_STMT(ExprWithCleanups)
  MX_ENTER_SERIALIZE_ExprWithCleanups
  MX_SERIALIZE_BASE(ExprWithCleanups, FullExpr)
  MX_SERIALIZE_BOOL(ExprWithCleanups, cleanups_have_side_effects, getVal98, setVal98, initVal98, CleanupsHaveSideEffects, bool, NthStmt)
  MX_EXIT_SERIALIZE_ExprWithCleanups
MX_END_SERIALIZE_STMT(ExprWithCleanups)
#undef MX_ENTER_SERIALIZE_ExprWithCleanups
#undef MX_EXIT_SERIALIZE_ExprWithCleanups

#ifndef MX_ENTER_SERIALIZE_ConstantExpr
#  define MX_ENTER_SERIALIZE_ConstantExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ConstantExpr
#  define MX_EXIT_SERIALIZE_ConstantExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ConstantExpr)
  MX_ENTER_SERIALIZE_ConstantExpr
  MX_SERIALIZE_BASE(ConstantExpr, FullExpr)
  MX_SERIALIZE_ENUM(ConstantExpr, result_storage_kind, getVal103, setVal103, initVal103, ResultStorageKind, ConstantExprResultStorageKind, NthStmt)
  MX_SERIALIZE_BOOL(ConstantExpr, has_ap_value_result, getVal98, setVal98, initVal98, HasAPValueResult, bool, NthStmt)
  MX_SERIALIZE_BOOL(ConstantExpr, is_immediate_invocation, getVal99, setVal99, initVal99, IsImmediateInvocation, bool, NthStmt)
  MX_EXIT_SERIALIZE_ConstantExpr
MX_END_SERIALIZE_STMT(ConstantExpr)
#undef MX_ENTER_SERIALIZE_ConstantExpr
#undef MX_EXIT_SERIALIZE_ConstantExpr

#ifndef MX_ENTER_SERIALIZE_FloatingLiteral
#  define MX_ENTER_SERIALIZE_FloatingLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_FloatingLiteral
#  define MX_EXIT_SERIALIZE_FloatingLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(FloatingLiteral)
  MX_ENTER_SERIALIZE_FloatingLiteral
  MX_SERIALIZE_BASE(FloatingLiteral, Expr)
  MX_SERIALIZE_ENTITY(FloatingLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_SERIALIZE_BOOL(FloatingLiteral, is_exact, getVal98, setVal98, initVal98, IsExact, bool, NthStmt)
  MX_EXIT_SERIALIZE_FloatingLiteral
MX_END_SERIALIZE_STMT(FloatingLiteral)
#undef MX_ENTER_SERIALIZE_FloatingLiteral
#undef MX_EXIT_SERIALIZE_FloatingLiteral

#ifndef MX_ENTER_SERIALIZE_FixedPointLiteral
#  define MX_ENTER_SERIALIZE_FixedPointLiteral
#endif
#ifndef MX_EXIT_SERIALIZE_FixedPointLiteral
#  define MX_EXIT_SERIALIZE_FixedPointLiteral
#endif

MX_BEGIN_SERIALIZE_STMT(FixedPointLiteral)
  MX_ENTER_SERIALIZE_FixedPointLiteral
  MX_SERIALIZE_BASE(FixedPointLiteral, Expr)
  MX_SERIALIZE_ENTITY(FixedPointLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt)
  MX_EXIT_SERIALIZE_FixedPointLiteral
MX_END_SERIALIZE_STMT(FixedPointLiteral)
#undef MX_ENTER_SERIALIZE_FixedPointLiteral
#undef MX_EXIT_SERIALIZE_FixedPointLiteral

#ifndef MX_ENTER_SERIALIZE_ExtVectorElementExpr
#  define MX_ENTER_SERIALIZE_ExtVectorElementExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ExtVectorElementExpr
#  define MX_EXIT_SERIALIZE_ExtVectorElementExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ExtVectorElementExpr)
  MX_ENTER_SERIALIZE_ExtVectorElementExpr
  MX_SERIALIZE_BASE(ExtVectorElementExpr, Expr)
  MX_SERIALIZE_BOOL(ExtVectorElementExpr, contains_duplicate_elements, getVal98, setVal98, initVal98, ContainsDuplicateElements, bool, NthStmt)
  MX_SERIALIZE_ENTITY(ExtVectorElementExpr, accessor_token, getVal38, setVal38, initVal38, AccessorToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(ExtVectorElementExpr, base, getVal39, setVal39, initVal39, Base, Expr, NthStmt)
  MX_SERIALIZE_BOOL(ExtVectorElementExpr, is_arrow, getVal99, setVal99, initVal99, IsArrow, bool, NthStmt)
  MX_EXIT_SERIALIZE_ExtVectorElementExpr
MX_END_SERIALIZE_STMT(ExtVectorElementExpr)
#undef MX_ENTER_SERIALIZE_ExtVectorElementExpr
#undef MX_EXIT_SERIALIZE_ExtVectorElementExpr

#ifndef MX_ENTER_SERIALIZE_ExpressionTraitExpr
#  define MX_ENTER_SERIALIZE_ExpressionTraitExpr
#endif
#ifndef MX_EXIT_SERIALIZE_ExpressionTraitExpr
#  define MX_EXIT_SERIALIZE_ExpressionTraitExpr
#endif

MX_BEGIN_SERIALIZE_STMT(ExpressionTraitExpr)
  MX_ENTER_SERIALIZE_ExpressionTraitExpr
  MX_SERIALIZE_BASE(ExpressionTraitExpr, Expr)
  MX_SERIALIZE_ENTITY(ExpressionTraitExpr, queried_expression, getVal38, setVal38, initVal38, QueriedExpression, Expr, NthStmt)
  MX_SERIALIZE_ENUM(ExpressionTraitExpr, trait, getVal103, setVal103, initVal103, Trait, ExpressionTrait, NthStmt)
  MX_SERIALIZE_BOOL(ExpressionTraitExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
  MX_EXIT_SERIALIZE_ExpressionTraitExpr
MX_END_SERIALIZE_STMT(ExpressionTraitExpr)
#undef MX_ENTER_SERIALIZE_ExpressionTraitExpr
#undef MX_EXIT_SERIALIZE_ExpressionTraitExpr

#ifndef MX_ENTER_SERIALIZE_AttributedStmt
#  define MX_ENTER_SERIALIZE_AttributedStmt
#endif
#ifndef MX_EXIT_SERIALIZE_AttributedStmt
#  define MX_EXIT_SERIALIZE_AttributedStmt
#endif

MX_BEGIN_SERIALIZE_STMT(AttributedStmt)
  MX_ENTER_SERIALIZE_AttributedStmt
  MX_SERIALIZE_BASE(AttributedStmt, ValueStmt)
  MX_SERIALIZE_ENTITY(AttributedStmt, attribute_token, getVal11, setVal11, initVal11, AttributeToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(AttributedStmt, sub_statement, getVal12, setVal12, initVal12, SubStatement, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_AttributedStmt
MX_END_SERIALIZE_STMT(AttributedStmt)
#undef MX_ENTER_SERIALIZE_AttributedStmt
#undef MX_EXIT_SERIALIZE_AttributedStmt

#ifndef MX_ENTER_SERIALIZE_SwitchStmt
#  define MX_ENTER_SERIALIZE_SwitchStmt
#endif
#ifndef MX_EXIT_SERIALIZE_SwitchStmt
#  define MX_EXIT_SERIALIZE_SwitchStmt
#endif

MX_BEGIN_SERIALIZE_STMT(SwitchStmt)
  MX_ENTER_SERIALIZE_SwitchStmt
  MX_SERIALIZE_BASE(SwitchStmt, Stmt)
  MX_SERIALIZE_ENTITY(SwitchStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(SwitchStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(SwitchStmt, condition_variable, getVal12, setVal12, initVal12, ConditionVariable, VarDecl, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(SwitchStmt, condition_variable_declaration_statement, getVal14, setVal14, initVal14, ConditionVariableDeclarationStatement, DeclStmt, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(SwitchStmt, initializer, getVal15, setVal15, initVal15, Initializer, Stmt, NthStmt)
  MX_SERIALIZE_ENTITY(SwitchStmt, l_paren_token, getVal18, setVal18, initVal18, LParenToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SwitchStmt, r_paren_token, getVal19, setVal19, initVal19, RParenToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(SwitchStmt, first_switch_case, getVal20, setVal20, initVal20, FirstSwitchCase, SwitchCase, NthStmt)
  MX_SERIALIZE_ENTITY(SwitchStmt, switch_token, getVal27, setVal27, initVal27, SwitchToken, Token, NthStmt)
  MX_SERIALIZE_BOOL(SwitchStmt, has_initializer_storage, getVal57, setVal57, initVal57, HasInitializerStorage, bool, NthStmt)
  MX_SERIALIZE_BOOL(SwitchStmt, has_variable_storage, getVal58, setVal58, initVal58, HasVariableStorage, bool, NthStmt)
  MX_SERIALIZE_BOOL(SwitchStmt, is_all_enum_cases_covered, getVal59, setVal59, initVal59, IsAllEnumCasesCovered, bool, NthStmt)
  MX_EXIT_SERIALIZE_SwitchStmt
MX_END_SERIALIZE_STMT(SwitchStmt)
#undef MX_ENTER_SERIALIZE_SwitchStmt
#undef MX_EXIT_SERIALIZE_SwitchStmt

#ifndef MX_ENTER_SERIALIZE_SwitchCase
#  define MX_ENTER_SERIALIZE_SwitchCase
#endif
#ifndef MX_EXIT_SERIALIZE_SwitchCase
#  define MX_EXIT_SERIALIZE_SwitchCase
#endif

MX_BEGIN_SERIALIZE_STMT(SwitchCase)
  MX_ENTER_SERIALIZE_SwitchCase
  MX_SERIALIZE_BASE(SwitchCase, Stmt)
  MX_SERIALIZE_ENTITY(SwitchCase, colon_token, getVal10, setVal10, initVal10, ColonToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(SwitchCase, keyword_token, getVal11, setVal11, initVal11, KeywordToken, Token, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(SwitchCase, next_switch_case, getVal12, setVal12, initVal12, NextSwitchCase, SwitchCase, NthStmt)
  MX_SERIALIZE_ENTITY(SwitchCase, sub_statement, getVal14, setVal14, initVal14, SubStatement, Stmt, NthStmt)
  MX_EXIT_SERIALIZE_SwitchCase
MX_END_SERIALIZE_STMT(SwitchCase)
#undef MX_ENTER_SERIALIZE_SwitchCase
#undef MX_EXIT_SERIALIZE_SwitchCase

#ifndef MX_ENTER_SERIALIZE_DefaultStmt
#  define MX_ENTER_SERIALIZE_DefaultStmt
#endif
#ifndef MX_EXIT_SERIALIZE_DefaultStmt
#  define MX_EXIT_SERIALIZE_DefaultStmt
#endif

MX_BEGIN_SERIALIZE_STMT(DefaultStmt)
  MX_ENTER_SERIALIZE_DefaultStmt
  MX_SERIALIZE_BASE(DefaultStmt, SwitchCase)
  MX_SERIALIZE_ENTITY(DefaultStmt, default_token, getVal15, setVal15, initVal15, DefaultToken, Token, NthStmt)
  MX_EXIT_SERIALIZE_DefaultStmt
MX_END_SERIALIZE_STMT(DefaultStmt)
#undef MX_ENTER_SERIALIZE_DefaultStmt
#undef MX_EXIT_SERIALIZE_DefaultStmt

#ifndef MX_ENTER_SERIALIZE_CaseStmt
#  define MX_ENTER_SERIALIZE_CaseStmt
#endif
#ifndef MX_EXIT_SERIALIZE_CaseStmt
#  define MX_EXIT_SERIALIZE_CaseStmt
#endif

MX_BEGIN_SERIALIZE_STMT(CaseStmt)
  MX_ENTER_SERIALIZE_CaseStmt
  MX_SERIALIZE_BASE(CaseStmt, SwitchCase)
  MX_SERIALIZE_BOOL(CaseStmt, case_statement_is_gnu_range, getVal16, setVal16, initVal16, CaseStatementIsGNURange, bool, NthStmt)
  MX_SERIALIZE_ENTITY(CaseStmt, case_token, getVal15, setVal15, initVal15, CaseToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CaseStmt, ellipsis_token, getVal18, setVal18, initVal18, EllipsisToken, Token, NthStmt)
  MX_SERIALIZE_ENTITY(CaseStmt, lhs, getVal19, setVal19, initVal19, LHS, Expr, NthStmt)
  MX_SERIALIZE_OPTIONAL_ENTITY(CaseStmt, rhs, getVal20, setVal20, initVal20, RHS, Expr, NthStmt)
  MX_EXIT_SERIALIZE_CaseStmt
MX_END_SERIALIZE_STMT(CaseStmt)
#undef MX_ENTER_SERIALIZE_CaseStmt
#undef MX_EXIT_SERIALIZE_CaseStmt

#ifndef MX_ENTER_SERIALIZE_Decl
#  define MX_ENTER_SERIALIZE_Decl
#endif
#ifndef MX_EXIT_SERIALIZE_Decl
#  define MX_EXIT_SERIALIZE_Decl
#endif

MX_BEGIN_SERIALIZE_DECL(Decl)
  MX_ENTER_SERIALIZE_Decl
  MX_SERIALIZE_DECL_LINK(Decl, parent_declaration, getVal0, setVal0, initVal0)
  MX_SERIALIZE_STMT_LINK(Decl, parent_statement, getVal1, setVal1, initVal1)
  MX_SERIALIZE_BOOL(Decl, is_definition, getVal2, setVal2, initVal2, IsThisDeclarationADefinition, bool, NthDecl)
  MX_SERIALIZE_ENUM(Decl, access, getVal3, setVal3, initVal3, Access, AccessSpecifier, NthDecl)
  MX_SERIALIZE_ENUM(Decl, availability, getVal4, setVal4, initVal4, Availability, AvailabilityResult, NthDecl)
  MX_SERIALIZE_ENTITY(Decl, begin_token, getVal5, setVal5, initVal5, BeginToken, Token, NthDecl)
  MX_SERIALIZE_OPTIONAL_PSEUDO(Decl, described_template_parameters, getVal6, setVal6, initVal6, DescribedTemplateParameters, TemplateParameterList, NthDecl)
  MX_SERIALIZE_ENTITY(Decl, end_token, getVal8, setVal8, initVal8, EndToken, Token, NthDecl)
  MX_SERIALIZE_ENUM(Decl, friend_object_kind, getVal9, setVal9, initVal9, FriendObjectKind, DeclFriendObjectKind, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(Decl, function_type, getVal10, setVal10, initVal10, FunctionType, FunctionType, NthDecl)
  MX_SERIALIZE_ENUM(Decl, module_ownership_kind, getVal12, setVal12, initVal12, ModuleOwnershipKind, DeclModuleOwnershipKind, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(Decl, non_closure_context, getVal13, setVal13, initVal13, NonClosureContext, Decl, NthDecl)
  MX_SERIALIZE_BOOL(Decl, has_attributes, getVal15, setVal15, initVal15, HasAttributes, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, has_defining_attribute, getVal16, setVal16, initVal16, HasDefiningAttribute, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, has_owning_module, getVal17, setVal17, initVal17, HasOwningModule, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, has_tag_identifier_namespace, getVal18, setVal18, initVal18, HasTagIdentifierNamespace, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_defined_outside_function_or_method, getVal19, setVal19, initVal19, IsDefinedOutsideFunctionOrMethod, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_deprecated, getVal20, setVal20, initVal20, IsDeprecated, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_function_or_function_template, getVal21, setVal21, initVal21, IsFunctionOrFunctionTemplate, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_implicit, getVal22, setVal22, initVal22, IsImplicit, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_in_anonymous_namespace, getVal23, setVal23, initVal23, IsInAnonymousNamespace, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_in_local_scope_for_instantiation, getVal24, setVal24, initVal24, IsInLocalScopeForInstantiation, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_in_std_namespace, getVal25, setVal25, initVal25, IsInStdNamespace, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_invalid_declaration, getVal26, setVal26, initVal26, IsInvalidDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_module_private, getVal27, setVal27, initVal27, IsModulePrivate, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_out_of_line, getVal28, setVal28, initVal28, IsOutOfLine, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_parameter_pack, getVal29, setVal29, initVal29, IsParameterPack, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_template_declaration, getVal30, setVal30, initVal30, IsTemplateDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_template_parameter, getVal31, setVal31, initVal31, IsTemplateParameter, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_template_parameter_pack, getVal32, setVal32, initVal32, IsTemplateParameterPack, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_templated, getVal33, setVal33, initVal33, IsTemplated, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_top_level_declaration_in_obj_c_container, getVal34, setVal34, initVal34, IsTopLevelDeclarationInObjCContainer, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_unavailable, getVal35, setVal35, initVal35, IsUnavailable, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_unconditionally_visible, getVal36, setVal36, initVal36, IsUnconditionallyVisible, bool, NthDecl)
  MX_SERIALIZE_BOOL(Decl, is_weak_imported, getVal37, setVal37, initVal37, IsWeakImported, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(Decl, redeclarations_visible_in_translation_unit, getVal38, setVal38, initVal38, Redeclarations, Decl, NthDecl)
  MX_SERIALIZE_ENUM(Decl, kind, getVal39, setVal39, initVal39, Kind, DeclKind, NthDecl)
  MX_SERIALIZE_ENTITY(Decl, token, getVal40, setVal40, initVal40, Token, Token, NthDecl)
  MX_EXIT_SERIALIZE_Decl
MX_END_SERIALIZE_DECL(Decl)
#undef MX_ENTER_SERIALIZE_Decl
#undef MX_EXIT_SERIALIZE_Decl

#ifndef MX_ENTER_SERIALIZE_ClassScopeFunctionSpecializationDecl
#  define MX_ENTER_SERIALIZE_ClassScopeFunctionSpecializationDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ClassScopeFunctionSpecializationDecl
#  define MX_EXIT_SERIALIZE_ClassScopeFunctionSpecializationDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ClassScopeFunctionSpecializationDecl)
  MX_ENTER_SERIALIZE_ClassScopeFunctionSpecializationDecl
  MX_SERIALIZE_BASE(ClassScopeFunctionSpecializationDecl, Decl)
  MX_SERIALIZE_ENTITY(ClassScopeFunctionSpecializationDecl, specialization, getVal43, setVal43, initVal43, Specialization, CXXMethodDecl, NthDecl)
  MX_SERIALIZE_BOOL(ClassScopeFunctionSpecializationDecl, has_explicit_template_arguments, getVal44, setVal44, initVal44, HasExplicitTemplateArguments, bool, NthDecl)
  MX_EXIT_SERIALIZE_ClassScopeFunctionSpecializationDecl
MX_END_SERIALIZE_DECL(ClassScopeFunctionSpecializationDecl)
#undef MX_ENTER_SERIALIZE_ClassScopeFunctionSpecializationDecl
#undef MX_EXIT_SERIALIZE_ClassScopeFunctionSpecializationDecl

#ifndef MX_ENTER_SERIALIZE_CapturedDecl
#  define MX_ENTER_SERIALIZE_CapturedDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CapturedDecl
#  define MX_EXIT_SERIALIZE_CapturedDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CapturedDecl)
  MX_ENTER_SERIALIZE_CapturedDecl
  MX_SERIALIZE_BASE(CapturedDecl, Decl)
  MX_SERIALIZE_ENTITY(CapturedDecl, context_parameter, getVal43, setVal43, initVal43, ContextParameter, ImplicitParamDecl, NthDecl)
  MX_SERIALIZE_BOOL(CapturedDecl, is_nothrow, getVal44, setVal44, initVal44, IsNothrow, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(CapturedDecl, parameters, getVal45, setVal45, initVal45, Parameters, ImplicitParamDecl, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(CapturedDecl, declarations_in_context, getVal46, setVal46, initVal46, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_CapturedDecl
MX_END_SERIALIZE_DECL(CapturedDecl)
#undef MX_ENTER_SERIALIZE_CapturedDecl
#undef MX_EXIT_SERIALIZE_CapturedDecl

#ifndef MX_ENTER_SERIALIZE_BlockDecl
#  define MX_ENTER_SERIALIZE_BlockDecl
#endif
#ifndef MX_EXIT_SERIALIZE_BlockDecl
#  define MX_EXIT_SERIALIZE_BlockDecl
#endif

MX_BEGIN_SERIALIZE_DECL(BlockDecl)
  MX_ENTER_SERIALIZE_BlockDecl
  MX_SERIALIZE_BASE(BlockDecl, Decl)
  MX_SERIALIZE_BOOL(BlockDecl, block_missing_return_type, getVal44, setVal44, initVal44, BlockMissingReturnType, bool, NthDecl)
  MX_SERIALIZE_BOOL(BlockDecl, can_avoid_copy_to_heap, getVal47, setVal47, initVal47, CanAvoidCopyToHeap, bool, NthDecl)
  MX_SERIALIZE_BOOL(BlockDecl, captures_cxx_this, getVal48, setVal48, initVal48, CapturesCXXThis, bool, NthDecl)
  MX_SERIALIZE_BOOL(BlockDecl, does_not_escape, getVal49, setVal49, initVal49, DoesNotEscape, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(BlockDecl, block_mangling_context_declaration, getVal43, setVal43, initVal43, BlockManglingContextDeclaration, Decl, NthDecl)
  MX_SERIALIZE_ENTITY(BlockDecl, caret_token, getVal51, setVal51, initVal51, CaretToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(BlockDecl, compound_body, getVal52, setVal52, initVal52, CompoundBody, CompoundStmt, NthDecl)
  MX_SERIALIZE_ENTITY(BlockDecl, signature_as_written, getVal53, setVal53, initVal53, SignatureAsWritten, Type, NthDecl)
  MX_SERIALIZE_BOOL(BlockDecl, has_captures, getVal54, setVal54, initVal54, HasCaptures, bool, NthDecl)
  MX_SERIALIZE_BOOL(BlockDecl, is_conversion_from_lambda, getVal55, setVal55, initVal55, IsConversionFromLambda, bool, NthDecl)
  MX_SERIALIZE_BOOL(BlockDecl, is_variadic, getVal56, setVal56, initVal56, IsVariadic, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(BlockDecl, parameters, getVal45, setVal45, initVal45, Parameters, ParmVarDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(BlockDecl, parameter_declarations, getVal46, setVal46, initVal46, ParameterDeclarations, ParmVarDecl, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(BlockDecl, declarations_in_context, getVal57, setVal57, initVal57, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_BlockDecl
MX_END_SERIALIZE_DECL(BlockDecl)
#undef MX_ENTER_SERIALIZE_BlockDecl
#undef MX_EXIT_SERIALIZE_BlockDecl

#ifndef MX_ENTER_SERIALIZE_AccessSpecDecl
#  define MX_ENTER_SERIALIZE_AccessSpecDecl
#endif
#ifndef MX_EXIT_SERIALIZE_AccessSpecDecl
#  define MX_EXIT_SERIALIZE_AccessSpecDecl
#endif

MX_BEGIN_SERIALIZE_DECL(AccessSpecDecl)
  MX_ENTER_SERIALIZE_AccessSpecDecl
  MX_SERIALIZE_BASE(AccessSpecDecl, Decl)
  MX_SERIALIZE_ENTITY(AccessSpecDecl, access_specifier_token, getVal43, setVal43, initVal43, AccessSpecifierToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(AccessSpecDecl, colon_token, getVal51, setVal51, initVal51, ColonToken, Token, NthDecl)
  MX_EXIT_SERIALIZE_AccessSpecDecl
MX_END_SERIALIZE_DECL(AccessSpecDecl)
#undef MX_ENTER_SERIALIZE_AccessSpecDecl
#undef MX_EXIT_SERIALIZE_AccessSpecDecl

#ifndef MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveDecl
#  define MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveDecl
#  define MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPDeclarativeDirectiveDecl)
  MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveDecl
  MX_SERIALIZE_BASE(OMPDeclarativeDirectiveDecl, Decl)
  MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveDecl
MX_END_SERIALIZE_DECL(OMPDeclarativeDirectiveDecl)
#undef MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveDecl
#undef MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveDecl

#ifndef MX_ENTER_SERIALIZE_OMPThreadPrivateDecl
#  define MX_ENTER_SERIALIZE_OMPThreadPrivateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPThreadPrivateDecl
#  define MX_EXIT_SERIALIZE_OMPThreadPrivateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPThreadPrivateDecl)
  MX_ENTER_SERIALIZE_OMPThreadPrivateDecl
  MX_SERIALIZE_BASE(OMPThreadPrivateDecl, OMPDeclarativeDirectiveDecl)
  MX_SERIALIZE_ENTITY_LIST(OMPThreadPrivateDecl, varlists, getVal45, setVal45, initVal45, Varlists, Expr, NthDecl)
  MX_EXIT_SERIALIZE_OMPThreadPrivateDecl
MX_END_SERIALIZE_DECL(OMPThreadPrivateDecl)
#undef MX_ENTER_SERIALIZE_OMPThreadPrivateDecl
#undef MX_EXIT_SERIALIZE_OMPThreadPrivateDecl

#ifndef MX_ENTER_SERIALIZE_OMPRequiresDecl
#  define MX_ENTER_SERIALIZE_OMPRequiresDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPRequiresDecl
#  define MX_EXIT_SERIALIZE_OMPRequiresDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPRequiresDecl)
  MX_ENTER_SERIALIZE_OMPRequiresDecl
  MX_SERIALIZE_BASE(OMPRequiresDecl, OMPDeclarativeDirectiveDecl)
  MX_EXIT_SERIALIZE_OMPRequiresDecl
MX_END_SERIALIZE_DECL(OMPRequiresDecl)
#undef MX_ENTER_SERIALIZE_OMPRequiresDecl
#undef MX_EXIT_SERIALIZE_OMPRequiresDecl

#ifndef MX_ENTER_SERIALIZE_OMPAllocateDecl
#  define MX_ENTER_SERIALIZE_OMPAllocateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPAllocateDecl
#  define MX_EXIT_SERIALIZE_OMPAllocateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPAllocateDecl)
  MX_ENTER_SERIALIZE_OMPAllocateDecl
  MX_SERIALIZE_BASE(OMPAllocateDecl, OMPDeclarativeDirectiveDecl)
  MX_SERIALIZE_ENTITY_LIST(OMPAllocateDecl, varlists, getVal45, setVal45, initVal45, Varlists, Expr, NthDecl)
  MX_EXIT_SERIALIZE_OMPAllocateDecl
MX_END_SERIALIZE_DECL(OMPAllocateDecl)
#undef MX_ENTER_SERIALIZE_OMPAllocateDecl
#undef MX_EXIT_SERIALIZE_OMPAllocateDecl

#ifndef MX_ENTER_SERIALIZE_TranslationUnitDecl
#  define MX_ENTER_SERIALIZE_TranslationUnitDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TranslationUnitDecl
#  define MX_EXIT_SERIALIZE_TranslationUnitDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TranslationUnitDecl)
  MX_ENTER_SERIALIZE_TranslationUnitDecl
  MX_SERIALIZE_DECL_CONTEXT(TranslationUnitDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_TranslationUnitDecl
MX_END_SERIALIZE_DECL(TranslationUnitDecl)
#undef MX_ENTER_SERIALIZE_TranslationUnitDecl
#undef MX_EXIT_SERIALIZE_TranslationUnitDecl

#ifndef MX_ENTER_SERIALIZE_StaticAssertDecl
#  define MX_ENTER_SERIALIZE_StaticAssertDecl
#endif
#ifndef MX_EXIT_SERIALIZE_StaticAssertDecl
#  define MX_EXIT_SERIALIZE_StaticAssertDecl
#endif

MX_BEGIN_SERIALIZE_DECL(StaticAssertDecl)
  MX_ENTER_SERIALIZE_StaticAssertDecl
  MX_SERIALIZE_BASE(StaticAssertDecl, Decl)
  MX_SERIALIZE_ENTITY(StaticAssertDecl, assert_expression, getVal43, setVal43, initVal43, AssertExpression, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(StaticAssertDecl, message, getVal51, setVal51, initVal51, Message, StringLiteral, NthDecl)
  MX_SERIALIZE_ENTITY(StaticAssertDecl, r_paren_token, getVal52, setVal52, initVal52, RParenToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(StaticAssertDecl, is_failed, getVal44, setVal44, initVal44, IsFailed, bool, NthDecl)
  MX_EXIT_SERIALIZE_StaticAssertDecl
MX_END_SERIALIZE_DECL(StaticAssertDecl)
#undef MX_ENTER_SERIALIZE_StaticAssertDecl
#undef MX_EXIT_SERIALIZE_StaticAssertDecl

#ifndef MX_ENTER_SERIALIZE_RequiresExprBodyDecl
#  define MX_ENTER_SERIALIZE_RequiresExprBodyDecl
#endif
#ifndef MX_EXIT_SERIALIZE_RequiresExprBodyDecl
#  define MX_EXIT_SERIALIZE_RequiresExprBodyDecl
#endif

MX_BEGIN_SERIALIZE_DECL(RequiresExprBodyDecl)
  MX_ENTER_SERIALIZE_RequiresExprBodyDecl
  MX_SERIALIZE_BASE(RequiresExprBodyDecl, Decl)
  MX_SERIALIZE_DECL_CONTEXT(RequiresExprBodyDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_RequiresExprBodyDecl
MX_END_SERIALIZE_DECL(RequiresExprBodyDecl)
#undef MX_ENTER_SERIALIZE_RequiresExprBodyDecl
#undef MX_EXIT_SERIALIZE_RequiresExprBodyDecl

#ifndef MX_ENTER_SERIALIZE_PragmaDetectMismatchDecl
#  define MX_ENTER_SERIALIZE_PragmaDetectMismatchDecl
#endif
#ifndef MX_EXIT_SERIALIZE_PragmaDetectMismatchDecl
#  define MX_EXIT_SERIALIZE_PragmaDetectMismatchDecl
#endif

MX_BEGIN_SERIALIZE_DECL(PragmaDetectMismatchDecl)
  MX_ENTER_SERIALIZE_PragmaDetectMismatchDecl
  MX_SERIALIZE_BASE(PragmaDetectMismatchDecl, Decl)
  MX_SERIALIZE_TEXT(PragmaDetectMismatchDecl, name, getVal58, setVal58, initVal58, Name, basic_string_view, NthDecl)
  MX_SERIALIZE_TEXT(PragmaDetectMismatchDecl, value, getVal59, setVal59, initVal59, Value, basic_string_view, NthDecl)
  MX_EXIT_SERIALIZE_PragmaDetectMismatchDecl
MX_END_SERIALIZE_DECL(PragmaDetectMismatchDecl)
#undef MX_ENTER_SERIALIZE_PragmaDetectMismatchDecl
#undef MX_EXIT_SERIALIZE_PragmaDetectMismatchDecl

#ifndef MX_ENTER_SERIALIZE_PragmaCommentDecl
#  define MX_ENTER_SERIALIZE_PragmaCommentDecl
#endif
#ifndef MX_EXIT_SERIALIZE_PragmaCommentDecl
#  define MX_EXIT_SERIALIZE_PragmaCommentDecl
#endif

MX_BEGIN_SERIALIZE_DECL(PragmaCommentDecl)
  MX_ENTER_SERIALIZE_PragmaCommentDecl
  MX_SERIALIZE_BASE(PragmaCommentDecl, Decl)
  MX_SERIALIZE_TEXT(PragmaCommentDecl, argument, getVal58, setVal58, initVal58, Argument, basic_string_view, NthDecl)
  MX_SERIALIZE_ENUM(PragmaCommentDecl, comment_kind, getVal60, setVal60, initVal60, CommentKind, PragmaMSCommentKind, NthDecl)
  MX_EXIT_SERIALIZE_PragmaCommentDecl
MX_END_SERIALIZE_DECL(PragmaCommentDecl)
#undef MX_ENTER_SERIALIZE_PragmaCommentDecl
#undef MX_EXIT_SERIALIZE_PragmaCommentDecl

#ifndef MX_ENTER_SERIALIZE_ObjCPropertyImplDecl
#  define MX_ENTER_SERIALIZE_ObjCPropertyImplDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCPropertyImplDecl
#  define MX_EXIT_SERIALIZE_ObjCPropertyImplDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCPropertyImplDecl)
  MX_ENTER_SERIALIZE_ObjCPropertyImplDecl
  MX_SERIALIZE_BASE(ObjCPropertyImplDecl, Decl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, getter_cxx_constructor, getVal43, setVal43, initVal43, GetterCXXConstructor, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, getter_method_declaration, getVal51, setVal51, initVal51, GetterMethodDeclaration, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, property_declaration, getVal52, setVal52, initVal52, PropertyDeclaration, ObjCPropertyDecl, NthDecl)
  MX_SERIALIZE_ENUM(ObjCPropertyImplDecl, property_implementation, getVal60, setVal60, initVal60, PropertyImplementation, ObjCPropertyImplDeclKind, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, property_instance_variable_declaration, getVal53, setVal53, initVal53, PropertyInstanceVariableDeclaration, ObjCIvarDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, property_instance_variable_declaration_token, getVal61, setVal61, initVal61, PropertyInstanceVariableDeclarationToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, setter_cxx_assignment, getVal62, setVal62, initVal62, SetterCXXAssignment, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyImplDecl, setter_method_declaration, getVal63, setVal63, initVal63, SetterMethodDeclaration, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyImplDecl, is_instance_variable_name_specified, getVal44, setVal44, initVal44, IsInstanceVariableNameSpecified, bool, NthDecl)
  MX_EXIT_SERIALIZE_ObjCPropertyImplDecl
MX_END_SERIALIZE_DECL(ObjCPropertyImplDecl)
#undef MX_ENTER_SERIALIZE_ObjCPropertyImplDecl
#undef MX_EXIT_SERIALIZE_ObjCPropertyImplDecl

#ifndef MX_ENTER_SERIALIZE_NamedDecl
#  define MX_ENTER_SERIALIZE_NamedDecl
#endif
#ifndef MX_EXIT_SERIALIZE_NamedDecl
#  define MX_EXIT_SERIALIZE_NamedDecl
#endif

MX_BEGIN_SERIALIZE_DECL(NamedDecl)
  MX_ENTER_SERIALIZE_NamedDecl
  MX_SERIALIZE_BASE(NamedDecl, Decl)
  MX_SERIALIZE_ENUM(NamedDecl, formal_linkage, getVal60, setVal60, initVal60, FormalLinkage, Linkage, NthDecl)
  MX_SERIALIZE_ENUM(NamedDecl, linkage_internal, getVal64, setVal64, initVal64, LinkageInternal, Linkage, NthDecl)
  MX_SERIALIZE_TEXT(NamedDecl, name, getVal58, setVal58, initVal58, Name, basic_string, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENUM(NamedDecl, obj_cf_string_formatting_family, getVal65, setVal65, initVal65, ObjCFStringFormattingFamily, ObjCStringFormatFamily, NthDecl)
  MX_SERIALIZE_TEXT(NamedDecl, qualified_name_as_string, getVal59, setVal59, initVal59, QualifiedNameAsString, basic_string, NthDecl)
  MX_SERIALIZE_ENTITY(NamedDecl, underlying_declaration, getVal43, setVal43, initVal43, UnderlyingDeclaration, NamedDecl, NthDecl)
  MX_SERIALIZE_ENUM(NamedDecl, visibility, getVal66, setVal66, initVal66, Visibility, Visibility, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, has_external_formal_linkage, getVal47, setVal47, initVal47, HasExternalFormalLinkage, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, has_linkage, getVal48, setVal48, initVal48, HasLinkage, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, has_linkage_been_computed, getVal49, setVal49, initVal49, HasLinkageBeenComputed, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, is_cxx_class_member, getVal50, setVal50, initVal50, IsCXXClassMember, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, is_cxx_instance_member, getVal54, setVal54, initVal54, IsCXXInstanceMember, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, is_externally_declarable, getVal55, setVal55, initVal55, IsExternallyDeclarable, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, is_externally_visible, getVal56, setVal56, initVal56, IsExternallyVisible, bool, NthDecl)
  MX_SERIALIZE_BOOL(NamedDecl, is_linkage_valid, getVal67, setVal67, initVal67, IsLinkageValid, bool, NthDecl)
  MX_EXIT_SERIALIZE_NamedDecl
MX_END_SERIALIZE_DECL(NamedDecl)
#undef MX_ENTER_SERIALIZE_NamedDecl
#undef MX_EXIT_SERIALIZE_NamedDecl

#ifndef MX_ENTER_SERIALIZE_LabelDecl
#  define MX_ENTER_SERIALIZE_LabelDecl
#endif
#ifndef MX_EXIT_SERIALIZE_LabelDecl
#  define MX_EXIT_SERIALIZE_LabelDecl
#endif

MX_BEGIN_SERIALIZE_DECL(LabelDecl)
  MX_ENTER_SERIALIZE_LabelDecl
  MX_SERIALIZE_BASE(LabelDecl, NamedDecl)
  MX_SERIALIZE_TEXT(LabelDecl, ms_assembly_label, getVal68, setVal68, initVal68, MSAssemblyLabel, basic_string_view, NthDecl)
  MX_SERIALIZE_ENTITY(LabelDecl, statement, getVal51, setVal51, initVal51, Statement, LabelStmt, NthDecl)
  MX_SERIALIZE_BOOL(LabelDecl, is_gnu_local, getVal69, setVal69, initVal69, IsGnuLocal, bool, NthDecl)
  MX_SERIALIZE_BOOL(LabelDecl, is_ms_assembly_label, getVal70, setVal70, initVal70, IsMSAssemblyLabel, bool, NthDecl)
  MX_SERIALIZE_BOOL(LabelDecl, is_resolved_ms_assembly_label, getVal71, setVal71, initVal71, IsResolvedMSAssemblyLabel, bool, NthDecl)
  MX_EXIT_SERIALIZE_LabelDecl
MX_END_SERIALIZE_DECL(LabelDecl)
#undef MX_ENTER_SERIALIZE_LabelDecl
#undef MX_EXIT_SERIALIZE_LabelDecl

#ifndef MX_ENTER_SERIALIZE_BaseUsingDecl
#  define MX_ENTER_SERIALIZE_BaseUsingDecl
#endif
#ifndef MX_EXIT_SERIALIZE_BaseUsingDecl
#  define MX_EXIT_SERIALIZE_BaseUsingDecl
#endif

MX_BEGIN_SERIALIZE_DECL(BaseUsingDecl)
  MX_ENTER_SERIALIZE_BaseUsingDecl
  MX_SERIALIZE_BASE(BaseUsingDecl, NamedDecl)
  MX_SERIALIZE_ENTITY_LIST(BaseUsingDecl, shadows, getVal45, setVal45, initVal45, Shadows, UsingShadowDecl, NthDecl)
  MX_EXIT_SERIALIZE_BaseUsingDecl
MX_END_SERIALIZE_DECL(BaseUsingDecl)
#undef MX_ENTER_SERIALIZE_BaseUsingDecl
#undef MX_EXIT_SERIALIZE_BaseUsingDecl

#ifndef MX_ENTER_SERIALIZE_UsingEnumDecl
#  define MX_ENTER_SERIALIZE_UsingEnumDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UsingEnumDecl
#  define MX_EXIT_SERIALIZE_UsingEnumDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UsingEnumDecl)
  MX_ENTER_SERIALIZE_UsingEnumDecl
  MX_SERIALIZE_BASE(UsingEnumDecl, BaseUsingDecl)
  MX_SERIALIZE_ENTITY(UsingEnumDecl, enum_declaration, getVal51, setVal51, initVal51, EnumDeclaration, EnumDecl, NthDecl)
  MX_SERIALIZE_ENTITY(UsingEnumDecl, enum_token, getVal52, setVal52, initVal52, EnumToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(UsingEnumDecl, using_token, getVal53, setVal53, initVal53, UsingToken, Token, NthDecl)
  MX_EXIT_SERIALIZE_UsingEnumDecl
MX_END_SERIALIZE_DECL(UsingEnumDecl)
#undef MX_ENTER_SERIALIZE_UsingEnumDecl
#undef MX_EXIT_SERIALIZE_UsingEnumDecl

#ifndef MX_ENTER_SERIALIZE_UsingDecl
#  define MX_ENTER_SERIALIZE_UsingDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UsingDecl
#  define MX_EXIT_SERIALIZE_UsingDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UsingDecl)
  MX_ENTER_SERIALIZE_UsingDecl
  MX_SERIALIZE_BASE(UsingDecl, BaseUsingDecl)
  MX_SERIALIZE_ENTITY(UsingDecl, using_token, getVal51, setVal51, initVal51, UsingToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(UsingDecl, has_typename, getVal69, setVal69, initVal69, HasTypename, bool, NthDecl)
  MX_SERIALIZE_BOOL(UsingDecl, is_access_declaration, getVal70, setVal70, initVal70, IsAccessDeclaration, bool, NthDecl)
  MX_EXIT_SERIALIZE_UsingDecl
MX_END_SERIALIZE_DECL(UsingDecl)
#undef MX_ENTER_SERIALIZE_UsingDecl
#undef MX_EXIT_SERIALIZE_UsingDecl

#ifndef MX_ENTER_SERIALIZE_ValueDecl
#  define MX_ENTER_SERIALIZE_ValueDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ValueDecl
#  define MX_EXIT_SERIALIZE_ValueDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ValueDecl)
  MX_ENTER_SERIALIZE_ValueDecl
  MX_SERIALIZE_BASE(ValueDecl, NamedDecl)
  MX_SERIALIZE_ENTITY(ValueDecl, type, getVal51, setVal51, initVal51, Type, Type, NthDecl)
  MX_SERIALIZE_BOOL(ValueDecl, is_weak, getVal69, setVal69, initVal69, IsWeak, bool, NthDecl)
  MX_EXIT_SERIALIZE_ValueDecl
MX_END_SERIALIZE_DECL(ValueDecl)
#undef MX_ENTER_SERIALIZE_ValueDecl
#undef MX_EXIT_SERIALIZE_ValueDecl

#ifndef MX_ENTER_SERIALIZE_UnresolvedUsingValueDecl
#  define MX_ENTER_SERIALIZE_UnresolvedUsingValueDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UnresolvedUsingValueDecl
#  define MX_EXIT_SERIALIZE_UnresolvedUsingValueDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UnresolvedUsingValueDecl)
  MX_ENTER_SERIALIZE_UnresolvedUsingValueDecl
  MX_SERIALIZE_BASE(UnresolvedUsingValueDecl, ValueDecl)
  MX_SERIALIZE_ENTITY(UnresolvedUsingValueDecl, ellipsis_token, getVal52, setVal52, initVal52, EllipsisToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(UnresolvedUsingValueDecl, using_token, getVal53, setVal53, initVal53, UsingToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(UnresolvedUsingValueDecl, is_access_declaration, getVal70, setVal70, initVal70, IsAccessDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(UnresolvedUsingValueDecl, is_pack_expansion, getVal71, setVal71, initVal71, IsPackExpansion, bool, NthDecl)
  MX_EXIT_SERIALIZE_UnresolvedUsingValueDecl
MX_END_SERIALIZE_DECL(UnresolvedUsingValueDecl)
#undef MX_ENTER_SERIALIZE_UnresolvedUsingValueDecl
#undef MX_EXIT_SERIALIZE_UnresolvedUsingValueDecl

#ifndef MX_ENTER_SERIALIZE_TemplateParamObjectDecl
#  define MX_ENTER_SERIALIZE_TemplateParamObjectDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateParamObjectDecl
#  define MX_EXIT_SERIALIZE_TemplateParamObjectDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TemplateParamObjectDecl)
  MX_ENTER_SERIALIZE_TemplateParamObjectDecl
  MX_SERIALIZE_BASE(TemplateParamObjectDecl, ValueDecl)
  MX_EXIT_SERIALIZE_TemplateParamObjectDecl
MX_END_SERIALIZE_DECL(TemplateParamObjectDecl)
#undef MX_ENTER_SERIALIZE_TemplateParamObjectDecl
#undef MX_EXIT_SERIALIZE_TemplateParamObjectDecl

#ifndef MX_ENTER_SERIALIZE_OMPDeclareReductionDecl
#  define MX_ENTER_SERIALIZE_OMPDeclareReductionDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDeclareReductionDecl
#  define MX_EXIT_SERIALIZE_OMPDeclareReductionDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPDeclareReductionDecl)
  MX_ENTER_SERIALIZE_OMPDeclareReductionDecl
  MX_SERIALIZE_BASE(OMPDeclareReductionDecl, ValueDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, combiner, getVal52, setVal52, initVal52, Combiner, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, combiner_in, getVal53, setVal53, initVal53, CombinerIn, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, combiner_out, getVal61, setVal61, initVal61, CombinerOut, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, initializer_original, getVal62, setVal62, initVal62, InitializerOriginal, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, initializer_private, getVal63, setVal63, initVal63, InitializerPrivate, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, initializer, getVal72, setVal72, initVal72, Initializer, Expr, NthDecl)
  MX_SERIALIZE_ENUM(OMPDeclareReductionDecl, initializer_kind, getVal73, setVal73, initVal73, InitializerKind, OMPDeclareReductionDeclInitKind, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareReductionDecl, prev_declaration_in_scope, getVal74, setVal74, initVal74, PrevDeclarationInScope, OMPDeclareReductionDecl, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(OMPDeclareReductionDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_OMPDeclareReductionDecl
MX_END_SERIALIZE_DECL(OMPDeclareReductionDecl)
#undef MX_ENTER_SERIALIZE_OMPDeclareReductionDecl
#undef MX_EXIT_SERIALIZE_OMPDeclareReductionDecl

#ifndef MX_ENTER_SERIALIZE_MSGuidDecl
#  define MX_ENTER_SERIALIZE_MSGuidDecl
#endif
#ifndef MX_EXIT_SERIALIZE_MSGuidDecl
#  define MX_EXIT_SERIALIZE_MSGuidDecl
#endif

MX_BEGIN_SERIALIZE_DECL(MSGuidDecl)
  MX_ENTER_SERIALIZE_MSGuidDecl
  MX_SERIALIZE_BASE(MSGuidDecl, ValueDecl)
  MX_EXIT_SERIALIZE_MSGuidDecl
MX_END_SERIALIZE_DECL(MSGuidDecl)
#undef MX_ENTER_SERIALIZE_MSGuidDecl
#undef MX_EXIT_SERIALIZE_MSGuidDecl

#ifndef MX_ENTER_SERIALIZE_IndirectFieldDecl
#  define MX_ENTER_SERIALIZE_IndirectFieldDecl
#endif
#ifndef MX_EXIT_SERIALIZE_IndirectFieldDecl
#  define MX_EXIT_SERIALIZE_IndirectFieldDecl
#endif

MX_BEGIN_SERIALIZE_DECL(IndirectFieldDecl)
  MX_ENTER_SERIALIZE_IndirectFieldDecl
  MX_SERIALIZE_BASE(IndirectFieldDecl, ValueDecl)
  MX_SERIALIZE_ENTITY_LIST(IndirectFieldDecl, chain, getVal45, setVal45, initVal45, Chain, NamedDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(IndirectFieldDecl, anonymous_field, getVal52, setVal52, initVal52, AnonymousField, FieldDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(IndirectFieldDecl, variable_declaration, getVal53, setVal53, initVal53, VariableDeclaration, VarDecl, NthDecl)
  MX_EXIT_SERIALIZE_IndirectFieldDecl
MX_END_SERIALIZE_DECL(IndirectFieldDecl)
#undef MX_ENTER_SERIALIZE_IndirectFieldDecl
#undef MX_EXIT_SERIALIZE_IndirectFieldDecl

#ifndef MX_ENTER_SERIALIZE_EnumConstantDecl
#  define MX_ENTER_SERIALIZE_EnumConstantDecl
#endif
#ifndef MX_EXIT_SERIALIZE_EnumConstantDecl
#  define MX_EXIT_SERIALIZE_EnumConstantDecl
#endif

MX_BEGIN_SERIALIZE_DECL(EnumConstantDecl)
  MX_ENTER_SERIALIZE_EnumConstantDecl
  MX_SERIALIZE_BASE(EnumConstantDecl, ValueDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(EnumConstantDecl, initializer_expression, getVal52, setVal52, initVal52, InitializerExpression, Expr, NthDecl)
  MX_EXIT_SERIALIZE_EnumConstantDecl
MX_END_SERIALIZE_DECL(EnumConstantDecl)
#undef MX_ENTER_SERIALIZE_EnumConstantDecl
#undef MX_EXIT_SERIALIZE_EnumConstantDecl

#ifndef MX_ENTER_SERIALIZE_DeclaratorDecl
#  define MX_ENTER_SERIALIZE_DeclaratorDecl
#endif
#ifndef MX_EXIT_SERIALIZE_DeclaratorDecl
#  define MX_EXIT_SERIALIZE_DeclaratorDecl
#endif

MX_BEGIN_SERIALIZE_DECL(DeclaratorDecl)
  MX_ENTER_SERIALIZE_DeclaratorDecl
  MX_SERIALIZE_BASE(DeclaratorDecl, ValueDecl)
  MX_SERIALIZE_ENTITY(DeclaratorDecl, inner_token_start, getVal52, setVal52, initVal52, InnerTokenStart, Token, NthDecl)
  MX_SERIALIZE_ENTITY(DeclaratorDecl, outer_token_start, getVal53, setVal53, initVal53, OuterTokenStart, Token, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(DeclaratorDecl, trailing_requires_clause, getVal61, setVal61, initVal61, TrailingRequiresClause, Expr, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(DeclaratorDecl, type_source_info, getVal62, setVal62, initVal62, TypeSourceInfo, Type, NthDecl)
  MX_SERIALIZE_ENTITY(DeclaratorDecl, type_spec_end_token, getVal63, setVal63, initVal63, TypeSpecEndToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(DeclaratorDecl, type_spec_start_token, getVal72, setVal72, initVal72, TypeSpecStartToken, Token, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(DeclaratorDecl, template_parameter_lists, getVal75, setVal75, initVal75, TemplateParameterLists, TemplateParameterList, NthDecl)
  MX_EXIT_SERIALIZE_DeclaratorDecl
MX_END_SERIALIZE_DECL(DeclaratorDecl)
#undef MX_ENTER_SERIALIZE_DeclaratorDecl
#undef MX_EXIT_SERIALIZE_DeclaratorDecl

#ifndef MX_ENTER_SERIALIZE_VarDecl
#  define MX_ENTER_SERIALIZE_VarDecl
#endif
#ifndef MX_EXIT_SERIALIZE_VarDecl
#  define MX_EXIT_SERIALIZE_VarDecl
#endif

MX_BEGIN_SERIALIZE_DECL(VarDecl)
  MX_ENTER_SERIALIZE_VarDecl
  MX_SERIALIZE_BASE(VarDecl, DeclaratorDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(VarDecl, acting_definition, getVal74, setVal74, initVal74, ActingDefinition, VarDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(VarDecl, initializer, getVal77, setVal77, initVal77, Initializer, Expr, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, initializer_style, getVal73, setVal73, initVal73, InitializerStyle, VarDeclInitializationStyle, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(VarDecl, initializing_declaration, getVal79, setVal79, initVal79, InitializingDeclaration, VarDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(VarDecl, instantiated_from_static_data_member, getVal81, setVal81, initVal81, InstantiatedFromStaticDataMember, VarDecl, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, language_linkage, getVal83, setVal83, initVal83, LanguageLinkage, LanguageLinkage, NthDecl)
  MX_SERIALIZE_ENTITY(VarDecl, point_of_instantiation, getVal84, setVal84, initVal84, PointOfInstantiation, Token, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, storage_class, getVal85, setVal85, initVal85, StorageClass, StorageClass, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, storage_duration, getVal86, setVal86, initVal86, StorageDuration, StorageDuration, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, tls_kind, getVal87, setVal87, initVal87, TLSKind, VarDeclTLSKind, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, tsc_spec, getVal88, setVal88, initVal88, TSCSpec, ThreadStorageClassSpecifier, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(VarDecl, template_instantiation_pattern, getVal89, setVal89, initVal89, TemplateInstantiationPattern, VarDecl, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, template_specialization_kind, getVal91, setVal91, initVal91, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, template_specialization_kind_for_instantiation, getVal92, setVal92, initVal92, TemplateSpecializationKindForInstantiation, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, has_constant_initialization, getVal93, setVal93, initVal93, HasConstantInitialization, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, has_dependent_alignment, getVal94, setVal94, initVal94, HasDependentAlignment, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, has_external_storage, getVal95, setVal95, initVal95, HasExternalStorage, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, has_global_storage, getVal96, setVal96, initVal96, HasGlobalStorage, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(VarDecl, has_ice_initializer, getVal97, setVal97, initVal97, HasICEInitializer, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, has_initializer, getVal99, setVal99, initVal99, HasInitializer, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, has_local_storage, getVal100, setVal100, initVal100, HasLocalStorage, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_arc_pseudo_strong, getVal101, setVal101, initVal101, IsARCPseudoStrong, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_cxx_for_range_declaration, getVal102, setVal102, initVal102, IsCXXForRangeDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_constexpr, getVal103, setVal103, initVal103, IsConstexpr, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_direct_initializer, getVal104, setVal104, initVal104, IsDirectInitializer, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_escaping_byref, getVal105, setVal105, initVal105, IsEscapingByref, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_exception_variable, getVal106, setVal106, initVal106, IsExceptionVariable, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_extern_c, getVal107, setVal107, initVal107, IsExternC, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_file_variable_declaration, getVal108, setVal108, initVal108, IsFileVariableDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_function_or_method_variable_declaration, getVal109, setVal109, initVal109, IsFunctionOrMethodVariableDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_in_extern_c_context, getVal110, setVal110, initVal110, IsInExternCContext, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_in_extern_cxx_context, getVal111, setVal111, initVal111, IsInExternCXXContext, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_initializer_capture, getVal112, setVal112, initVal112, IsInitializerCapture, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_inline, getVal113, setVal113, initVal113, IsInline, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_inline_specified, getVal114, setVal114, initVal114, IsInlineSpecified, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_known_to_be_defined, getVal115, setVal115, initVal115, IsKnownToBeDefined, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_local_variable_declaration, getVal116, setVal116, initVal116, IsLocalVariableDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_local_variable_declaration_or_parm, getVal117, setVal117, initVal117, IsLocalVariableDeclarationOrParm, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_nrvo_variable, getVal118, setVal118, initVal118, IsNRVOVariable, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_no_destroy, getVal119, setVal119, initVal119, IsNoDestroy, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_non_escaping_byref, getVal120, setVal120, initVal120, IsNonEscapingByref, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_obj_c_for_declaration, getVal121, setVal121, initVal121, IsObjCForDeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_previous_declaration_in_same_block_scope, getVal122, setVal122, initVal122, IsPreviousDeclarationInSameBlockScope, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_static_data_member, getVal123, setVal123, initVal123, IsStaticDataMember, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_static_local, getVal124, setVal124, initVal124, IsStaticLocal, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_this_declaration_a_demoted_definition, getVal125, setVal125, initVal125, IsThisDeclarationADemotedDefinition, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, is_usable_in_constant_expressions, getVal126, setVal126, initVal126, IsUsableInConstantExpressions, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarDecl, might_be_usable_in_constant_expressions, getVal127, setVal127, initVal127, MightBeUsableInConstantExpressions, bool, NthDecl)
  MX_SERIALIZE_ENUM(VarDecl, needs_destruction, getVal128, setVal128, initVal128, NeedsDestruction, QualTypeDestructionKind, NthDecl)
  MX_EXIT_SERIALIZE_VarDecl
MX_END_SERIALIZE_DECL(VarDecl)
#undef MX_ENTER_SERIALIZE_VarDecl
#undef MX_EXIT_SERIALIZE_VarDecl

#ifndef MX_ENTER_SERIALIZE_ParmVarDecl
#  define MX_ENTER_SERIALIZE_ParmVarDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ParmVarDecl
#  define MX_EXIT_SERIALIZE_ParmVarDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ParmVarDecl)
  MX_ENTER_SERIALIZE_ParmVarDecl
  MX_SERIALIZE_BASE(ParmVarDecl, VarDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ParmVarDecl, default_argument, getVal129, setVal129, initVal129, DefaultArgument, Expr, NthDecl)
  MX_SERIALIZE_ENUM(ParmVarDecl, obj_c_decl_qualifier, getVal133, setVal133, initVal133, ObjCDeclQualifier, DeclObjCDeclQualifier, NthDecl)
  MX_SERIALIZE_ENTITY(ParmVarDecl, original_type, getVal134, setVal134, initVal134, OriginalType, Type, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ParmVarDecl, uninstantiated_default_argument, getVal135, setVal135, initVal135, UninstantiatedDefaultArgument, Expr, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, has_default_argument, getVal137, setVal137, initVal137, HasDefaultArgument, bool, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, has_inherited_default_argument, getVal138, setVal138, initVal138, HasInheritedDefaultArgument, bool, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, has_uninstantiated_default_argument, getVal139, setVal139, initVal139, HasUninstantiatedDefaultArgument, bool, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, has_unparsed_default_argument, getVal140, setVal140, initVal140, HasUnparsedDefaultArgument, bool, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, is_destroyed_in_callee, getVal141, setVal141, initVal141, IsDestroyedInCallee, bool, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, is_knr_promoted, getVal142, setVal142, initVal142, IsKNRPromoted, bool, NthDecl)
  MX_SERIALIZE_BOOL(ParmVarDecl, is_obj_c_method_parameter, getVal143, setVal143, initVal143, IsObjCMethodParameter, bool, NthDecl)
  MX_EXIT_SERIALIZE_ParmVarDecl
MX_END_SERIALIZE_DECL(ParmVarDecl)
#undef MX_ENTER_SERIALIZE_ParmVarDecl
#undef MX_EXIT_SERIALIZE_ParmVarDecl

#ifndef MX_ENTER_SERIALIZE_OMPCapturedExprDecl
#  define MX_ENTER_SERIALIZE_OMPCapturedExprDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPCapturedExprDecl
#  define MX_EXIT_SERIALIZE_OMPCapturedExprDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPCapturedExprDecl)
  MX_ENTER_SERIALIZE_OMPCapturedExprDecl
  MX_SERIALIZE_BASE(OMPCapturedExprDecl, VarDecl)
  MX_EXIT_SERIALIZE_OMPCapturedExprDecl
MX_END_SERIALIZE_DECL(OMPCapturedExprDecl)
#undef MX_ENTER_SERIALIZE_OMPCapturedExprDecl
#undef MX_EXIT_SERIALIZE_OMPCapturedExprDecl

#ifndef MX_ENTER_SERIALIZE_ImplicitParamDecl
#  define MX_ENTER_SERIALIZE_ImplicitParamDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ImplicitParamDecl
#  define MX_EXIT_SERIALIZE_ImplicitParamDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ImplicitParamDecl)
  MX_ENTER_SERIALIZE_ImplicitParamDecl
  MX_SERIALIZE_BASE(ImplicitParamDecl, VarDecl)
  MX_SERIALIZE_ENUM(ImplicitParamDecl, parameter_kind, getVal133, setVal133, initVal133, ParameterKind, ImplicitParamDeclImplicitParamKind, NthDecl)
  MX_EXIT_SERIALIZE_ImplicitParamDecl
MX_END_SERIALIZE_DECL(ImplicitParamDecl)
#undef MX_ENTER_SERIALIZE_ImplicitParamDecl
#undef MX_EXIT_SERIALIZE_ImplicitParamDecl

#ifndef MX_ENTER_SERIALIZE_DecompositionDecl
#  define MX_ENTER_SERIALIZE_DecompositionDecl
#endif
#ifndef MX_EXIT_SERIALIZE_DecompositionDecl
#  define MX_EXIT_SERIALIZE_DecompositionDecl
#endif

MX_BEGIN_SERIALIZE_DECL(DecompositionDecl)
  MX_ENTER_SERIALIZE_DecompositionDecl
  MX_SERIALIZE_BASE(DecompositionDecl, VarDecl)
  MX_SERIALIZE_ENTITY_LIST(DecompositionDecl, bindings, getVal45, setVal45, initVal45, Bindings, BindingDecl, NthDecl)
  MX_EXIT_SERIALIZE_DecompositionDecl
MX_END_SERIALIZE_DECL(DecompositionDecl)
#undef MX_ENTER_SERIALIZE_DecompositionDecl
#undef MX_EXIT_SERIALIZE_DecompositionDecl

#ifndef MX_ENTER_SERIALIZE_VarTemplateSpecializationDecl
#  define MX_ENTER_SERIALIZE_VarTemplateSpecializationDecl
#endif
#ifndef MX_EXIT_SERIALIZE_VarTemplateSpecializationDecl
#  define MX_EXIT_SERIALIZE_VarTemplateSpecializationDecl
#endif

MX_BEGIN_SERIALIZE_DECL(VarTemplateSpecializationDecl)
  MX_ENTER_SERIALIZE_VarTemplateSpecializationDecl
  MX_SERIALIZE_BASE(VarTemplateSpecializationDecl, VarDecl)
  MX_SERIALIZE_ENTITY(VarTemplateSpecializationDecl, extern_token, getVal129, setVal129, initVal129, ExternToken, Token, NthDecl)
  MX_SERIALIZE_ENUM(VarTemplateSpecializationDecl, specialization_kind, getVal133, setVal133, initVal133, SpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(VarTemplateSpecializationDecl, template_arguments, getVal144, setVal144, initVal144, TemplateArguments, TemplateArgument, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(VarTemplateSpecializationDecl, template_instantiation_arguments, getVal145, setVal145, initVal145, TemplateInstantiationArguments, TemplateArgument, NthDecl)
  MX_SERIALIZE_ENTITY(VarTemplateSpecializationDecl, template_keyword_token, getVal131, setVal131, initVal131, TemplateKeywordToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(VarTemplateSpecializationDecl, type_as_written, getVal132, setVal132, initVal132, TypeAsWritten, Type, NthDecl)
  MX_SERIALIZE_BOOL(VarTemplateSpecializationDecl, is_class_scope_explicit_specialization, getVal130, setVal130, initVal130, IsClassScopeExplicitSpecialization, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarTemplateSpecializationDecl, is_explicit_instantiation_or_specialization, getVal136, setVal136, initVal136, IsExplicitInstantiationOrSpecialization, bool, NthDecl)
  MX_SERIALIZE_BOOL(VarTemplateSpecializationDecl, is_explicit_specialization, getVal137, setVal137, initVal137, IsExplicitSpecialization, bool, NthDecl)
  MX_EXIT_SERIALIZE_VarTemplateSpecializationDecl
MX_END_SERIALIZE_DECL(VarTemplateSpecializationDecl)
#undef MX_ENTER_SERIALIZE_VarTemplateSpecializationDecl
#undef MX_EXIT_SERIALIZE_VarTemplateSpecializationDecl

#ifndef MX_ENTER_SERIALIZE_VarTemplatePartialSpecializationDecl
#  define MX_ENTER_SERIALIZE_VarTemplatePartialSpecializationDecl
#endif
#ifndef MX_EXIT_SERIALIZE_VarTemplatePartialSpecializationDecl
#  define MX_EXIT_SERIALIZE_VarTemplatePartialSpecializationDecl
#endif

MX_BEGIN_SERIALIZE_DECL(VarTemplatePartialSpecializationDecl)
  MX_ENTER_SERIALIZE_VarTemplatePartialSpecializationDecl
  MX_EXIT_SERIALIZE_VarTemplatePartialSpecializationDecl
MX_END_SERIALIZE_DECL(VarTemplatePartialSpecializationDecl)
#undef MX_ENTER_SERIALIZE_VarTemplatePartialSpecializationDecl
#undef MX_EXIT_SERIALIZE_VarTemplatePartialSpecializationDecl

#ifndef MX_ENTER_SERIALIZE_NonTypeTemplateParmDecl
#  define MX_ENTER_SERIALIZE_NonTypeTemplateParmDecl
#endif
#ifndef MX_EXIT_SERIALIZE_NonTypeTemplateParmDecl
#  define MX_EXIT_SERIALIZE_NonTypeTemplateParmDecl
#endif

MX_BEGIN_SERIALIZE_DECL(NonTypeTemplateParmDecl)
  MX_ENTER_SERIALIZE_NonTypeTemplateParmDecl
  MX_SERIALIZE_BASE(NonTypeTemplateParmDecl, DeclaratorDecl)
  MX_SERIALIZE_BOOL(NonTypeTemplateParmDecl, default_argument_was_inherited, getVal76, setVal76, initVal76, DefaultArgumentWasInherited, bool, NthDecl)
  MX_SERIALIZE_ENTITY(NonTypeTemplateParmDecl, default_argument, getVal74, setVal74, initVal74, DefaultArgument, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(NonTypeTemplateParmDecl, default_argument_token, getVal77, setVal77, initVal77, DefaultArgumentToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(NonTypeTemplateParmDecl, placeholder_type_constraint, getVal79, setVal79, initVal79, PlaceholderTypeConstraint, Expr, NthDecl)
  MX_SERIALIZE_BOOL(NonTypeTemplateParmDecl, has_default_argument, getVal78, setVal78, initVal78, HasDefaultArgument, bool, NthDecl)
  MX_SERIALIZE_BOOL(NonTypeTemplateParmDecl, has_placeholder_type_constraint, getVal80, setVal80, initVal80, HasPlaceholderTypeConstraint, bool, NthDecl)
  MX_SERIALIZE_BOOL(NonTypeTemplateParmDecl, is_expanded_parameter_pack, getVal82, setVal82, initVal82, IsExpandedParameterPack, bool, NthDecl)
  MX_SERIALIZE_BOOL(NonTypeTemplateParmDecl, is_pack_expansion, getVal90, setVal90, initVal90, IsPackExpansion, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(NonTypeTemplateParmDecl, expansion_types, getVal45, setVal45, initVal45, ExpansionTypes, Type, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(NonTypeTemplateParmDecl, expansion_type_source_infos, getVal46, setVal46, initVal46, ExpansionTypeSourceInfos, Type, NthDecl)
  MX_EXIT_SERIALIZE_NonTypeTemplateParmDecl
MX_END_SERIALIZE_DECL(NonTypeTemplateParmDecl)
#undef MX_ENTER_SERIALIZE_NonTypeTemplateParmDecl
#undef MX_EXIT_SERIALIZE_NonTypeTemplateParmDecl

#ifndef MX_ENTER_SERIALIZE_MSPropertyDecl
#  define MX_ENTER_SERIALIZE_MSPropertyDecl
#endif
#ifndef MX_EXIT_SERIALIZE_MSPropertyDecl
#  define MX_EXIT_SERIALIZE_MSPropertyDecl
#endif

MX_BEGIN_SERIALIZE_DECL(MSPropertyDecl)
  MX_ENTER_SERIALIZE_MSPropertyDecl
  MX_SERIALIZE_BASE(MSPropertyDecl, DeclaratorDecl)
  MX_SERIALIZE_BOOL(MSPropertyDecl, has_getter, getVal76, setVal76, initVal76, HasGetter, bool, NthDecl)
  MX_SERIALIZE_BOOL(MSPropertyDecl, has_setter, getVal78, setVal78, initVal78, HasSetter, bool, NthDecl)
  MX_EXIT_SERIALIZE_MSPropertyDecl
MX_END_SERIALIZE_DECL(MSPropertyDecl)
#undef MX_ENTER_SERIALIZE_MSPropertyDecl
#undef MX_EXIT_SERIALIZE_MSPropertyDecl

#ifndef MX_ENTER_SERIALIZE_FunctionDecl
#  define MX_ENTER_SERIALIZE_FunctionDecl
#endif
#ifndef MX_EXIT_SERIALIZE_FunctionDecl
#  define MX_EXIT_SERIALIZE_FunctionDecl
#endif

MX_BEGIN_SERIALIZE_DECL(FunctionDecl)
  MX_ENTER_SERIALIZE_FunctionDecl
  MX_SERIALIZE_BASE(FunctionDecl, DeclaratorDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(FunctionDecl, does_declaration_force_externally_visible_definition, getVal76, setVal76, initVal76, DoesDeclarationForceExternallyVisibleDefinition, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, does_this_declaration_have_a_body, getVal80, setVal80, initVal80, DoesThisDeclarationHaveABody, bool, NthDecl)
  MX_SERIALIZE_ENTITY(FunctionDecl, call_result_type, getVal74, setVal74, initVal74, CallResultType, Type, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, constexpr_kind, getVal73, setVal73, initVal73, ConstexprKind, ConstexprSpecKind, NthDecl)
  MX_SERIALIZE_ENTITY(FunctionDecl, declared_return_type, getVal77, setVal77, initVal77, DeclaredReturnType, Type, NthDecl)
  MX_SERIALIZE_ENTITY(FunctionDecl, ellipsis_token, getVal79, setVal79, initVal79, EllipsisToken, Token, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, exception_spec_type, getVal83, setVal83, initVal83, ExceptionSpecType, ExceptionSpecificationType, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FunctionDecl, instantiated_from_member_function, getVal89, setVal89, initVal89, InstantiatedFromMemberFunction, FunctionDecl, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, language_linkage, getVal85, setVal85, initVal85, LanguageLinkage, LanguageLinkage, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, multi_version_kind, getVal86, setVal86, initVal86, MultiVersionKind, MultiVersionKind, NthDecl)
  MX_SERIALIZE_OPTIONAL_INT(FunctionDecl, odr_hash, getVal146, setVal146, initVal146, ODRHash, unsigned, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, overloaded_operator, getVal87, setVal87, initVal87, OverloadedOperator, OverloadedOperatorKind, NthDecl)
  MX_SERIALIZE_ENTITY(FunctionDecl, point_of_instantiation, getVal132, setVal132, initVal132, PointOfInstantiation, Token, NthDecl)
  MX_SERIALIZE_ENTITY(FunctionDecl, return_type, getVal134, setVal134, initVal134, ReturnType, Type, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, storage_class, getVal88, setVal88, initVal88, StorageClass, StorageClass, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FunctionDecl, template_instantiation_pattern, getVal148, setVal148, initVal148, TemplateInstantiationPattern, FunctionDecl, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, template_specialization_kind, getVal91, setVal91, initVal91, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, template_specialization_kind_for_instantiation, getVal92, setVal92, initVal92, TemplateSpecializationKindForInstantiation, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_ENUM(FunctionDecl, templated_kind, getVal128, setVal128, initVal128, TemplatedKind, FunctionDeclTemplatedKind, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_implicit_return_zero, getVal94, setVal94, initVal94, HasImplicitReturnZero, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_inherited_prototype, getVal95, setVal95, initVal95, HasInheritedPrototype, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_one_parameter_or_default_arguments, getVal96, setVal96, initVal96, HasOneParameterOrDefaultArguments, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_prototype, getVal97, setVal97, initVal97, HasPrototype, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_skipped_body, getVal98, setVal98, initVal98, HasSkippedBody, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_trivial_body, getVal99, setVal99, initVal99, HasTrivialBody, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, has_written_prototype, getVal100, setVal100, initVal100, HasWrittenPrototype, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, instantiation_is_pending, getVal101, setVal101, initVal101, InstantiationIsPending, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_cpu_dispatch_multi_version, getVal102, setVal102, initVal102, IsCPUDispatchMultiVersion, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_cpu_specific_multi_version, getVal103, setVal103, initVal103, IsCPUSpecificMultiVersion, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_consteval, getVal104, setVal104, initVal104, IsConsteval, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_constexpr, getVal105, setVal105, initVal105, IsConstexpr, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_constexpr_specified, getVal106, setVal106, initVal106, IsConstexprSpecified, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_defaulted, getVal107, setVal107, initVal107, IsDefaulted, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_deleted, getVal108, setVal108, initVal108, IsDeleted, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_deleted_as_written, getVal109, setVal109, initVal109, IsDeletedAsWritten, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_destroying_operator_delete, getVal110, setVal110, initVal110, IsDestroyingOperatorDelete, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_explicitly_defaulted, getVal111, setVal111, initVal111, IsExplicitlyDefaulted, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_extern_c, getVal112, setVal112, initVal112, IsExternC, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_function_template_specialization, getVal113, setVal113, initVal113, IsFunctionTemplateSpecialization, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_global, getVal114, setVal114, initVal114, IsGlobal, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_implicitly_instantiable, getVal115, setVal115, initVal115, IsImplicitlyInstantiable, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_in_extern_c_context, getVal116, setVal116, initVal116, IsInExternCContext, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_in_extern_cxx_context, getVal117, setVal117, initVal117, IsInExternCXXContext, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_inline_builtin_declaration, getVal118, setVal118, initVal118, IsInlineBuiltinDeclaration, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(FunctionDecl, is_inline_definition_externally_visible, getVal119, setVal119, initVal119, IsInlineDefinitionExternallyVisible, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_inline_specified, getVal121, setVal121, initVal121, IsInlineSpecified, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_inlined, getVal122, setVal122, initVal122, IsInlined, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_late_template_parsed, getVal123, setVal123, initVal123, IsLateTemplateParsed, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(FunctionDecl, is_ms_extern_inline, getVal124, setVal124, initVal124, IsMSExternInline, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_msvcrt_entry_point, getVal126, setVal126, initVal126, IsMSVCRTEntryPoint, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_main, getVal127, setVal127, initVal127, IsMain, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_multi_version, getVal130, setVal130, initVal130, IsMultiVersion, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_no_return, getVal136, setVal136, initVal136, IsNoReturn, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_overloaded_operator, getVal137, setVal137, initVal137, IsOverloadedOperator, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_pure, getVal138, setVal138, initVal138, IsPure, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_replaceable_global_allocation_function, getVal139, setVal139, initVal139, IsReplaceableGlobalAllocationFunction, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(FunctionDecl, is_reserved_global_placement_operator, getVal140, setVal140, initVal140, IsReservedGlobalPlacementOperator, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_static, getVal142, setVal142, initVal142, IsStatic, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_target_multi_version, getVal143, setVal143, initVal143, IsTargetMultiVersion, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_template_instantiation, getVal149, setVal149, initVal149, IsTemplateInstantiation, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_this_declaration_instantiated_from_a_friend_definition, getVal150, setVal150, initVal150, IsThisDeclarationInstantiatedFromAFriendDefinition, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_trivial, getVal151, setVal151, initVal151, IsTrivial, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_trivial_for_call, getVal152, setVal152, initVal152, IsTrivialForCall, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_user_provided, getVal153, setVal153, initVal153, IsUserProvided, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_variadic, getVal154, setVal154, initVal154, IsVariadic, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, is_virtual_as_written, getVal155, setVal155, initVal155, IsVirtualAsWritten, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(FunctionDecl, parameters, getVal45, setVal45, initVal45, Parameters, ParmVarDecl, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, uses_seh_try, getVal156, setVal156, initVal156, UsesSEHTry, bool, NthDecl)
  MX_SERIALIZE_BOOL(FunctionDecl, will_have_body, getVal157, setVal157, initVal157, WillHaveBody, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FunctionDecl, body, getVal158, setVal158, initVal158, Body, Stmt, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(FunctionDecl, declarations_in_context, getVal46, setVal46, initVal46, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_FunctionDecl
MX_END_SERIALIZE_DECL(FunctionDecl)
#undef MX_ENTER_SERIALIZE_FunctionDecl
#undef MX_EXIT_SERIALIZE_FunctionDecl

#ifndef MX_ENTER_SERIALIZE_CXXMethodDecl
#  define MX_ENTER_SERIALIZE_CXXMethodDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CXXMethodDecl
#  define MX_EXIT_SERIALIZE_CXXMethodDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CXXMethodDecl)
  MX_ENTER_SERIALIZE_CXXMethodDecl
  MX_SERIALIZE_BASE(CXXMethodDecl, FunctionDecl)
  MX_SERIALIZE_ENTITY(CXXMethodDecl, parent, getVal160, setVal160, initVal160, Parent, CXXRecordDecl, NthDecl)
  MX_SERIALIZE_ENUM(CXXMethodDecl, reference_qualifier, getVal133, setVal133, initVal133, ReferenceQualifier, RefQualifierKind, NthDecl)
  MX_SERIALIZE_ENTITY(CXXMethodDecl, this_object_type, getVal161, setVal161, initVal161, ThisObjectType, Type, NthDecl)
  MX_SERIALIZE_ENTITY(CXXMethodDecl, this_type, getVal162, setVal162, initVal162, ThisType, Type, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, has_inline_body, getVal163, setVal163, initVal163, HasInlineBody, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_const, getVal164, setVal164, initVal164, IsConst, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_copy_assignment_operator, getVal165, setVal165, initVal165, IsCopyAssignmentOperator, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_instance, getVal166, setVal166, initVal166, IsInstance, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_lambda_static_invoker, getVal167, setVal167, initVal167, IsLambdaStaticInvoker, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_move_assignment_operator, getVal168, setVal168, initVal168, IsMoveAssignmentOperator, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_virtual, getVal169, setVal169, initVal169, IsVirtual, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXMethodDecl, is_volatile, getVal170, setVal170, initVal170, IsVolatile, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(CXXMethodDecl, overridden_methods, getVal57, setVal57, initVal57, OverriddenMethods, CXXMethodDecl, NthDecl)
  MX_EXIT_SERIALIZE_CXXMethodDecl
MX_END_SERIALIZE_DECL(CXXMethodDecl)
#undef MX_ENTER_SERIALIZE_CXXMethodDecl
#undef MX_EXIT_SERIALIZE_CXXMethodDecl

#ifndef MX_ENTER_SERIALIZE_CXXDestructorDecl
#  define MX_ENTER_SERIALIZE_CXXDestructorDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDestructorDecl
#  define MX_EXIT_SERIALIZE_CXXDestructorDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CXXDestructorDecl)
  MX_ENTER_SERIALIZE_CXXDestructorDecl
  MX_SERIALIZE_BASE(CXXDestructorDecl, CXXMethodDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXDestructorDecl, operator_delete, getVal171, setVal171, initVal171, OperatorDelete, FunctionDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXDestructorDecl, operator_delete_this_argument, getVal173, setVal173, initVal173, OperatorDeleteThisArgument, Expr, NthDecl)
  MX_EXIT_SERIALIZE_CXXDestructorDecl
MX_END_SERIALIZE_DECL(CXXDestructorDecl)
#undef MX_ENTER_SERIALIZE_CXXDestructorDecl
#undef MX_EXIT_SERIALIZE_CXXDestructorDecl

#ifndef MX_ENTER_SERIALIZE_CXXConversionDecl
#  define MX_ENTER_SERIALIZE_CXXConversionDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CXXConversionDecl
#  define MX_EXIT_SERIALIZE_CXXConversionDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CXXConversionDecl)
  MX_ENTER_SERIALIZE_CXXConversionDecl
  MX_SERIALIZE_BASE(CXXConversionDecl, CXXMethodDecl)
  MX_SERIALIZE_ENTITY(CXXConversionDecl, conversion_type, getVal171, setVal171, initVal171, ConversionType, Type, NthDecl)
  MX_SERIALIZE_BOOL(CXXConversionDecl, is_explicit, getVal172, setVal172, initVal172, IsExplicit, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXConversionDecl, is_lambda_to_block_pointer_conversion, getVal174, setVal174, initVal174, IsLambdaToBlockPointerConversion, bool, NthDecl)
  MX_EXIT_SERIALIZE_CXXConversionDecl
MX_END_SERIALIZE_DECL(CXXConversionDecl)
#undef MX_ENTER_SERIALIZE_CXXConversionDecl
#undef MX_EXIT_SERIALIZE_CXXConversionDecl

#ifndef MX_ENTER_SERIALIZE_CXXConstructorDecl
#  define MX_ENTER_SERIALIZE_CXXConstructorDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CXXConstructorDecl
#  define MX_EXIT_SERIALIZE_CXXConstructorDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CXXConstructorDecl)
  MX_ENTER_SERIALIZE_CXXConstructorDecl
  MX_SERIALIZE_BASE(CXXConstructorDecl, CXXMethodDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXConstructorDecl, target_constructor, getVal171, setVal171, initVal171, TargetConstructor, CXXConstructorDecl, NthDecl)
  MX_SERIALIZE_BOOL(CXXConstructorDecl, is_default_constructor, getVal174, setVal174, initVal174, IsDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXConstructorDecl, is_delegating_constructor, getVal175, setVal175, initVal175, IsDelegatingConstructor, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXConstructorDecl, is_explicit, getVal176, setVal176, initVal176, IsExplicit, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXConstructorDecl, is_inheriting_constructor, getVal177, setVal177, initVal177, IsInheritingConstructor, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXConstructorDecl, is_specialization_copying_object, getVal178, setVal178, initVal178, IsSpecializationCopyingObject, bool, NthDecl)
  MX_EXIT_SERIALIZE_CXXConstructorDecl
MX_END_SERIALIZE_DECL(CXXConstructorDecl)
#undef MX_ENTER_SERIALIZE_CXXConstructorDecl
#undef MX_EXIT_SERIALIZE_CXXConstructorDecl

#ifndef MX_ENTER_SERIALIZE_CXXDeductionGuideDecl
#  define MX_ENTER_SERIALIZE_CXXDeductionGuideDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CXXDeductionGuideDecl
#  define MX_EXIT_SERIALIZE_CXXDeductionGuideDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CXXDeductionGuideDecl)
  MX_ENTER_SERIALIZE_CXXDeductionGuideDecl
  MX_SERIALIZE_BASE(CXXDeductionGuideDecl, FunctionDecl)
  MX_SERIALIZE_ENTITY(CXXDeductionGuideDecl, corresponding_constructor, getVal160, setVal160, initVal160, CorrespondingConstructor, CXXConstructorDecl, NthDecl)
  MX_SERIALIZE_BOOL(CXXDeductionGuideDecl, is_copy_deduction_candidate, getVal163, setVal163, initVal163, IsCopyDeductionCandidate, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXDeductionGuideDecl, is_explicit, getVal164, setVal164, initVal164, IsExplicit, bool, NthDecl)
  MX_EXIT_SERIALIZE_CXXDeductionGuideDecl
MX_END_SERIALIZE_DECL(CXXDeductionGuideDecl)
#undef MX_ENTER_SERIALIZE_CXXDeductionGuideDecl
#undef MX_EXIT_SERIALIZE_CXXDeductionGuideDecl

#ifndef MX_ENTER_SERIALIZE_FieldDecl
#  define MX_ENTER_SERIALIZE_FieldDecl
#endif
#ifndef MX_EXIT_SERIALIZE_FieldDecl
#  define MX_EXIT_SERIALIZE_FieldDecl
#endif

MX_BEGIN_SERIALIZE_DECL(FieldDecl)
  MX_ENTER_SERIALIZE_FieldDecl
  MX_SERIALIZE_BASE(FieldDecl, DeclaratorDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FieldDecl, bit_width, getVal74, setVal74, initVal74, BitWidth, Expr, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FieldDecl, captured_vla_type, getVal77, setVal77, initVal77, CapturedVLAType, VariableArrayType, NthDecl)
  MX_SERIALIZE_ENUM(FieldDecl, in_class_initializer_style, getVal73, setVal73, initVal73, InClassInitializerStyle, InClassInitStyle, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FieldDecl, in_class_initializer, getVal79, setVal79, initVal79, InClassInitializer, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(FieldDecl, parent, getVal81, setVal81, initVal81, Parent, RecordDecl, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, has_captured_vla_type, getVal82, setVal82, initVal82, HasCapturedVLAType, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, has_in_class_initializer, getVal90, setVal90, initVal90, HasInClassInitializer, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, is_anonymous_struct_or_union, getVal93, setVal93, initVal93, IsAnonymousStructOrUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, is_bit_field, getVal94, setVal94, initVal94, IsBitField, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, is_mutable, getVal95, setVal95, initVal95, IsMutable, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, is_unnamed_bitfield, getVal96, setVal96, initVal96, IsUnnamedBitfield, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, is_zero_length_bit_field, getVal97, setVal97, initVal97, IsZeroLengthBitField, bool, NthDecl)
  MX_SERIALIZE_BOOL(FieldDecl, is_zero_size, getVal98, setVal98, initVal98, IsZeroSize, bool, NthDecl)
  MX_EXIT_SERIALIZE_FieldDecl
MX_END_SERIALIZE_DECL(FieldDecl)
#undef MX_ENTER_SERIALIZE_FieldDecl
#undef MX_EXIT_SERIALIZE_FieldDecl

#ifndef MX_ENTER_SERIALIZE_ObjCIvarDecl
#  define MX_ENTER_SERIALIZE_ObjCIvarDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCIvarDecl
#  define MX_EXIT_SERIALIZE_ObjCIvarDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCIvarDecl)
  MX_ENTER_SERIALIZE_ObjCIvarDecl
  MX_SERIALIZE_BASE(ObjCIvarDecl, FieldDecl)
  MX_SERIALIZE_ENUM(ObjCIvarDecl, access_control, getVal83, setVal83, initVal83, AccessControl, ObjCIvarDeclAccessControl, NthDecl)
  MX_SERIALIZE_ENUM(ObjCIvarDecl, canonical_access_control, getVal85, setVal85, initVal85, CanonicalAccessControl, ObjCIvarDeclAccessControl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCIvarDecl, containing_interface, getVal84, setVal84, initVal84, ContainingInterface, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCIvarDecl, next_instance_variable, getVal89, setVal89, initVal89, NextInstanceVariable, ObjCIvarDecl, NthDecl)
  MX_SERIALIZE_BOOL(ObjCIvarDecl, synthesize, getVal99, setVal99, initVal99, Synthesize, bool, NthDecl)
  MX_EXIT_SERIALIZE_ObjCIvarDecl
MX_END_SERIALIZE_DECL(ObjCIvarDecl)
#undef MX_ENTER_SERIALIZE_ObjCIvarDecl
#undef MX_EXIT_SERIALIZE_ObjCIvarDecl

#ifndef MX_ENTER_SERIALIZE_ObjCAtDefsFieldDecl
#  define MX_ENTER_SERIALIZE_ObjCAtDefsFieldDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCAtDefsFieldDecl
#  define MX_EXIT_SERIALIZE_ObjCAtDefsFieldDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCAtDefsFieldDecl)
  MX_ENTER_SERIALIZE_ObjCAtDefsFieldDecl
  MX_SERIALIZE_BASE(ObjCAtDefsFieldDecl, FieldDecl)
  MX_EXIT_SERIALIZE_ObjCAtDefsFieldDecl
MX_END_SERIALIZE_DECL(ObjCAtDefsFieldDecl)
#undef MX_ENTER_SERIALIZE_ObjCAtDefsFieldDecl
#undef MX_EXIT_SERIALIZE_ObjCAtDefsFieldDecl

#ifndef MX_ENTER_SERIALIZE_BindingDecl
#  define MX_ENTER_SERIALIZE_BindingDecl
#endif
#ifndef MX_EXIT_SERIALIZE_BindingDecl
#  define MX_EXIT_SERIALIZE_BindingDecl
#endif

MX_BEGIN_SERIALIZE_DECL(BindingDecl)
  MX_ENTER_SERIALIZE_BindingDecl
  MX_SERIALIZE_BASE(BindingDecl, ValueDecl)
  MX_SERIALIZE_ENTITY(BindingDecl, binding, getVal52, setVal52, initVal52, Binding, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(BindingDecl, decomposed_declaration, getVal53, setVal53, initVal53, DecomposedDeclaration, ValueDecl, NthDecl)
  MX_SERIALIZE_ENTITY(BindingDecl, holding_variable, getVal61, setVal61, initVal61, HoldingVariable, VarDecl, NthDecl)
  MX_EXIT_SERIALIZE_BindingDecl
MX_END_SERIALIZE_DECL(BindingDecl)
#undef MX_ENTER_SERIALIZE_BindingDecl
#undef MX_EXIT_SERIALIZE_BindingDecl

#ifndef MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveValueDecl
#  define MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveValueDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveValueDecl
#  define MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveValueDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPDeclarativeDirectiveValueDecl)
  MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveValueDecl
  MX_SERIALIZE_BASE(OMPDeclarativeDirectiveValueDecl, ValueDecl)
  MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveValueDecl
MX_END_SERIALIZE_DECL(OMPDeclarativeDirectiveValueDecl)
#undef MX_ENTER_SERIALIZE_OMPDeclarativeDirectiveValueDecl
#undef MX_EXIT_SERIALIZE_OMPDeclarativeDirectiveValueDecl

#ifndef MX_ENTER_SERIALIZE_OMPDeclareMapperDecl
#  define MX_ENTER_SERIALIZE_OMPDeclareMapperDecl
#endif
#ifndef MX_EXIT_SERIALIZE_OMPDeclareMapperDecl
#  define MX_EXIT_SERIALIZE_OMPDeclareMapperDecl
#endif

MX_BEGIN_SERIALIZE_DECL(OMPDeclareMapperDecl)
  MX_ENTER_SERIALIZE_OMPDeclareMapperDecl
  MX_SERIALIZE_BASE(OMPDeclareMapperDecl, OMPDeclarativeDirectiveValueDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareMapperDecl, mapper_variable_reference, getVal52, setVal52, initVal52, MapperVariableReference, Expr, NthDecl)
  MX_SERIALIZE_ENTITY(OMPDeclareMapperDecl, prev_declaration_in_scope, getVal53, setVal53, initVal53, PrevDeclarationInScope, OMPDeclareMapperDecl, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(OMPDeclareMapperDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_OMPDeclareMapperDecl
MX_END_SERIALIZE_DECL(OMPDeclareMapperDecl)
#undef MX_ENTER_SERIALIZE_OMPDeclareMapperDecl
#undef MX_EXIT_SERIALIZE_OMPDeclareMapperDecl

#ifndef MX_ENTER_SERIALIZE_UsingShadowDecl
#  define MX_ENTER_SERIALIZE_UsingShadowDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UsingShadowDecl
#  define MX_EXIT_SERIALIZE_UsingShadowDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UsingShadowDecl)
  MX_ENTER_SERIALIZE_UsingShadowDecl
  MX_SERIALIZE_BASE(UsingShadowDecl, NamedDecl)
  MX_SERIALIZE_ENTITY(UsingShadowDecl, introducer, getVal51, setVal51, initVal51, Introducer, BaseUsingDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(UsingShadowDecl, next_using_shadow_declaration, getVal52, setVal52, initVal52, NextUsingShadowDeclaration, UsingShadowDecl, NthDecl)
  MX_SERIALIZE_ENTITY(UsingShadowDecl, target_declaration, getVal53, setVal53, initVal53, TargetDeclaration, NamedDecl, NthDecl)
  MX_EXIT_SERIALIZE_UsingShadowDecl
MX_END_SERIALIZE_DECL(UsingShadowDecl)
#undef MX_ENTER_SERIALIZE_UsingShadowDecl
#undef MX_EXIT_SERIALIZE_UsingShadowDecl

#ifndef MX_ENTER_SERIALIZE_ConstructorUsingShadowDecl
#  define MX_ENTER_SERIALIZE_ConstructorUsingShadowDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ConstructorUsingShadowDecl
#  define MX_EXIT_SERIALIZE_ConstructorUsingShadowDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ConstructorUsingShadowDecl)
  MX_ENTER_SERIALIZE_ConstructorUsingShadowDecl
  MX_SERIALIZE_BASE(ConstructorUsingShadowDecl, UsingShadowDecl)
  MX_SERIALIZE_BOOL(ConstructorUsingShadowDecl, constructs_virtual_base, getVal70, setVal70, initVal70, ConstructsVirtualBase, bool, NthDecl)
  MX_SERIALIZE_ENTITY(ConstructorUsingShadowDecl, constructed_base_class, getVal61, setVal61, initVal61, ConstructedBaseClass, CXXRecordDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ConstructorUsingShadowDecl, constructed_base_class_shadow_declaration, getVal62, setVal62, initVal62, ConstructedBaseClassShadowDeclaration, ConstructorUsingShadowDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ConstructorUsingShadowDecl, nominated_base_class, getVal63, setVal63, initVal63, NominatedBaseClass, CXXRecordDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ConstructorUsingShadowDecl, nominated_base_class_shadow_declaration, getVal72, setVal72, initVal72, NominatedBaseClassShadowDeclaration, ConstructorUsingShadowDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ConstructorUsingShadowDecl, parent, getVal74, setVal74, initVal74, Parent, CXXRecordDecl, NthDecl)
  MX_EXIT_SERIALIZE_ConstructorUsingShadowDecl
MX_END_SERIALIZE_DECL(ConstructorUsingShadowDecl)
#undef MX_ENTER_SERIALIZE_ConstructorUsingShadowDecl
#undef MX_EXIT_SERIALIZE_ConstructorUsingShadowDecl

#ifndef MX_ENTER_SERIALIZE_UsingPackDecl
#  define MX_ENTER_SERIALIZE_UsingPackDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UsingPackDecl
#  define MX_EXIT_SERIALIZE_UsingPackDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UsingPackDecl)
  MX_ENTER_SERIALIZE_UsingPackDecl
  MX_SERIALIZE_BASE(UsingPackDecl, NamedDecl)
  MX_SERIALIZE_ENTITY_LIST(UsingPackDecl, expansions, getVal45, setVal45, initVal45, Expansions, NamedDecl, NthDecl)
  MX_SERIALIZE_ENTITY(UsingPackDecl, instantiated_from_using_declaration, getVal51, setVal51, initVal51, InstantiatedFromUsingDeclaration, NamedDecl, NthDecl)
  MX_EXIT_SERIALIZE_UsingPackDecl
MX_END_SERIALIZE_DECL(UsingPackDecl)
#undef MX_ENTER_SERIALIZE_UsingPackDecl
#undef MX_EXIT_SERIALIZE_UsingPackDecl

#ifndef MX_ENTER_SERIALIZE_UsingDirectiveDecl
#  define MX_ENTER_SERIALIZE_UsingDirectiveDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UsingDirectiveDecl
#  define MX_EXIT_SERIALIZE_UsingDirectiveDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UsingDirectiveDecl)
  MX_ENTER_SERIALIZE_UsingDirectiveDecl
  MX_SERIALIZE_BASE(UsingDirectiveDecl, NamedDecl)
  MX_SERIALIZE_ENTITY(UsingDirectiveDecl, identifier_token, getVal51, setVal51, initVal51, IdentifierToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(UsingDirectiveDecl, namespace_key_token, getVal52, setVal52, initVal52, NamespaceKeyToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(UsingDirectiveDecl, nominated_namespace_as_written, getVal53, setVal53, initVal53, NominatedNamespaceAsWritten, NamedDecl, NthDecl)
  MX_SERIALIZE_ENTITY(UsingDirectiveDecl, using_token, getVal61, setVal61, initVal61, UsingToken, Token, NthDecl)
  MX_EXIT_SERIALIZE_UsingDirectiveDecl
MX_END_SERIALIZE_DECL(UsingDirectiveDecl)
#undef MX_ENTER_SERIALIZE_UsingDirectiveDecl
#undef MX_EXIT_SERIALIZE_UsingDirectiveDecl

#ifndef MX_ENTER_SERIALIZE_UnresolvedUsingIfExistsDecl
#  define MX_ENTER_SERIALIZE_UnresolvedUsingIfExistsDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UnresolvedUsingIfExistsDecl
#  define MX_EXIT_SERIALIZE_UnresolvedUsingIfExistsDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UnresolvedUsingIfExistsDecl)
  MX_ENTER_SERIALIZE_UnresolvedUsingIfExistsDecl
  MX_SERIALIZE_BASE(UnresolvedUsingIfExistsDecl, NamedDecl)
  MX_EXIT_SERIALIZE_UnresolvedUsingIfExistsDecl
MX_END_SERIALIZE_DECL(UnresolvedUsingIfExistsDecl)
#undef MX_ENTER_SERIALIZE_UnresolvedUsingIfExistsDecl
#undef MX_EXIT_SERIALIZE_UnresolvedUsingIfExistsDecl

#ifndef MX_ENTER_SERIALIZE_TypeDecl
#  define MX_ENTER_SERIALIZE_TypeDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TypeDecl
#  define MX_EXIT_SERIALIZE_TypeDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TypeDecl)
  MX_ENTER_SERIALIZE_TypeDecl
  MX_SERIALIZE_BASE(TypeDecl, NamedDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(TypeDecl, type_for_declaration, getVal51, setVal51, initVal51, TypeForDeclaration, Type, NthDecl)
  MX_EXIT_SERIALIZE_TypeDecl
MX_END_SERIALIZE_DECL(TypeDecl)
#undef MX_ENTER_SERIALIZE_TypeDecl
#undef MX_EXIT_SERIALIZE_TypeDecl

#ifndef MX_ENTER_SERIALIZE_TemplateTypeParmDecl
#  define MX_ENTER_SERIALIZE_TemplateTypeParmDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateTypeParmDecl
#  define MX_EXIT_SERIALIZE_TemplateTypeParmDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TemplateTypeParmDecl)
  MX_ENTER_SERIALIZE_TemplateTypeParmDecl
  MX_SERIALIZE_BASE(TemplateTypeParmDecl, TypeDecl)
  MX_SERIALIZE_BOOL(TemplateTypeParmDecl, default_argument_was_inherited, getVal70, setVal70, initVal70, DefaultArgumentWasInherited, bool, NthDecl)
  MX_SERIALIZE_ENTITY(TemplateTypeParmDecl, default_argument, getVal52, setVal52, initVal52, DefaultArgument, Type, NthDecl)
  MX_SERIALIZE_ENTITY(TemplateTypeParmDecl, default_argument_info, getVal53, setVal53, initVal53, DefaultArgumentInfo, Type, NthDecl)
  MX_SERIALIZE_ENTITY(TemplateTypeParmDecl, default_argument_token, getVal61, setVal61, initVal61, DefaultArgumentToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(TemplateTypeParmDecl, has_default_argument, getVal71, setVal71, initVal71, HasDefaultArgument, bool, NthDecl)
  MX_SERIALIZE_BOOL(TemplateTypeParmDecl, has_type_constraint, getVal76, setVal76, initVal76, HasTypeConstraint, bool, NthDecl)
  MX_SERIALIZE_BOOL(TemplateTypeParmDecl, is_expanded_parameter_pack, getVal78, setVal78, initVal78, IsExpandedParameterPack, bool, NthDecl)
  MX_SERIALIZE_BOOL(TemplateTypeParmDecl, is_pack_expansion, getVal80, setVal80, initVal80, IsPackExpansion, bool, NthDecl)
  MX_SERIALIZE_BOOL(TemplateTypeParmDecl, was_declared_with_typename, getVal82, setVal82, initVal82, WasDeclaredWithTypename, bool, NthDecl)
  MX_EXIT_SERIALIZE_TemplateTypeParmDecl
MX_END_SERIALIZE_DECL(TemplateTypeParmDecl)
#undef MX_ENTER_SERIALIZE_TemplateTypeParmDecl
#undef MX_EXIT_SERIALIZE_TemplateTypeParmDecl

#ifndef MX_ENTER_SERIALIZE_TagDecl
#  define MX_ENTER_SERIALIZE_TagDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TagDecl
#  define MX_EXIT_SERIALIZE_TagDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TagDecl)
  MX_ENTER_SERIALIZE_TagDecl
  MX_SERIALIZE_BASE(TagDecl, TypeDecl)
  MX_SERIALIZE_ENTITY(TagDecl, inner_token_start, getVal61, setVal61, initVal61, InnerTokenStart, Token, NthDecl)
  MX_SERIALIZE_ENTITY(TagDecl, outer_token_start, getVal62, setVal62, initVal62, OuterTokenStart, Token, NthDecl)
  MX_SERIALIZE_ENUM(TagDecl, tag_kind, getVal73, setVal73, initVal73, TagKind, TagTypeKind, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(TagDecl, typedef_name_for_anonymous_declaration, getVal63, setVal63, initVal63, TypedefNameForAnonymousDeclaration, TypedefNameDecl, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, has_name_for_linkage, getVal71, setVal71, initVal71, HasNameForLinkage, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_being_defined, getVal76, setVal76, initVal76, IsBeingDefined, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_class, getVal78, setVal78, initVal78, IsClass, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_complete_definition, getVal80, setVal80, initVal80, IsCompleteDefinition, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_complete_definition_required, getVal82, setVal82, initVal82, IsCompleteDefinitionRequired, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_dependent_type, getVal90, setVal90, initVal90, IsDependentType, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_embedded_in_declarator, getVal93, setVal93, initVal93, IsEmbeddedInDeclarator, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_enum, getVal94, setVal94, initVal94, IsEnum, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_free_standing, getVal95, setVal95, initVal95, IsFreeStanding, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_interface, getVal96, setVal96, initVal96, IsInterface, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_struct, getVal97, setVal97, initVal97, IsStruct, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, is_union, getVal98, setVal98, initVal98, IsUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(TagDecl, may_have_out_of_date_definition, getVal99, setVal99, initVal99, MayHaveOutOfDateDefinition, bool, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(TagDecl, template_parameter_lists, getVal75, setVal75, initVal75, TemplateParameterLists, TemplateParameterList, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(TagDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_TagDecl
MX_END_SERIALIZE_DECL(TagDecl)
#undef MX_ENTER_SERIALIZE_TagDecl
#undef MX_EXIT_SERIALIZE_TagDecl

#ifndef MX_ENTER_SERIALIZE_RecordDecl
#  define MX_ENTER_SERIALIZE_RecordDecl
#endif
#ifndef MX_EXIT_SERIALIZE_RecordDecl
#  define MX_EXIT_SERIALIZE_RecordDecl
#endif

MX_BEGIN_SERIALIZE_DECL(RecordDecl)
  MX_ENTER_SERIALIZE_RecordDecl
  MX_SERIALIZE_BASE(RecordDecl, TagDecl)
  MX_SERIALIZE_BOOL(RecordDecl, can_pass_in_registers, getVal100, setVal100, initVal100, CanPassInRegisters, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(RecordDecl, fields, getVal46, setVal46, initVal46, Fields, FieldDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(RecordDecl, find_first_named_data_member, getVal72, setVal72, initVal72, FindFirstNamedDataMember, FieldDecl, NthDecl)
  MX_SERIALIZE_ENUM(RecordDecl, argument_passing_restrictions, getVal83, setVal83, initVal83, ArgumentPassingRestrictions, RecordDeclArgPassingKind, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_flexible_array_member, getVal102, setVal102, initVal102, HasFlexibleArrayMember, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_loaded_fields_from_external_storage, getVal103, setVal103, initVal103, HasLoadedFieldsFromExternalStorage, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_non_trivial_to_primitive_copy_c_union, getVal104, setVal104, initVal104, HasNonTrivialToPrimitiveCopyCUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_non_trivial_to_primitive_default_initialize_c_union, getVal105, setVal105, initVal105, HasNonTrivialToPrimitiveDefaultInitializeCUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_non_trivial_to_primitive_destruct_c_union, getVal106, setVal106, initVal106, HasNonTrivialToPrimitiveDestructCUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_object_member, getVal107, setVal107, initVal107, HasObjectMember, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, has_volatile_member, getVal108, setVal108, initVal108, HasVolatileMember, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_anonymous_struct_or_union, getVal109, setVal109, initVal109, IsAnonymousStructOrUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_captured_record, getVal110, setVal110, initVal110, IsCapturedRecord, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_injected_class_name, getVal111, setVal111, initVal111, IsInjectedClassName, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_lambda, getVal112, setVal112, initVal112, IsLambda, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_ms_struct, getVal113, setVal113, initVal113, IsMsStruct, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_non_trivial_to_primitive_copy, getVal114, setVal114, initVal114, IsNonTrivialToPrimitiveCopy, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_non_trivial_to_primitive_default_initialize, getVal115, setVal115, initVal115, IsNonTrivialToPrimitiveDefaultInitialize, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_non_trivial_to_primitive_destroy, getVal116, setVal116, initVal116, IsNonTrivialToPrimitiveDestroy, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_or_contains_union, getVal117, setVal117, initVal117, IsOrContainsUnion, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, is_parameter_destroyed_in_callee, getVal118, setVal118, initVal118, IsParameterDestroyedInCallee, bool, NthDecl)
  MX_SERIALIZE_BOOL(RecordDecl, may_insert_extra_padding, getVal119, setVal119, initVal119, MayInsertExtraPadding, bool, NthDecl)
  MX_EXIT_SERIALIZE_RecordDecl
MX_END_SERIALIZE_DECL(RecordDecl)
#undef MX_ENTER_SERIALIZE_RecordDecl
#undef MX_EXIT_SERIALIZE_RecordDecl

#ifndef MX_ENTER_SERIALIZE_CXXRecordDecl
#  define MX_ENTER_SERIALIZE_CXXRecordDecl
#endif
#ifndef MX_EXIT_SERIALIZE_CXXRecordDecl
#  define MX_EXIT_SERIALIZE_CXXRecordDecl
#endif

MX_BEGIN_SERIALIZE_DECL(CXXRecordDecl)
  MX_ENTER_SERIALIZE_CXXRecordDecl
  MX_SERIALIZE_BASE(CXXRecordDecl, RecordDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, allow_const_default_initializer, getVal120, setVal120, initVal120, AllowConstDefaultInitializer, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_PSEUDO_LIST(CXXRecordDecl, bases, getVal144, setVal144, initVal144, Bases, CXXBaseSpecifier, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENUM(CXXRecordDecl, calculate_inheritance_model, getVal85, setVal85, initVal85, CalculateInheritanceModel, MSInheritanceModel, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(CXXRecordDecl, constructors, getVal57, setVal57, initVal57, Constructors, CXXConstructorDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY_LIST(CXXRecordDecl, friends, getVal179, setVal179, initVal179, Friends, FriendDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, destructor, getVal74, setVal74, initVal74, Destructor, CXXDestructorDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_PSEUDO(CXXRecordDecl, generic_lambda_template_parameter_list, getVal146, setVal146, initVal146, GenericLambdaTemplateParameterList, TemplateParameterList, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, instantiated_from_member_class, getVal77, setVal77, initVal77, InstantiatedFromMemberClass, CXXRecordDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, lambda_call_operator, getVal79, setVal79, initVal79, LambdaCallOperator, CXXMethodDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENUM(CXXRecordDecl, lambda_capture_default, getVal86, setVal86, initVal86, LambdaCaptureDefault, LambdaCaptureDefault, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, lambda_context_declaration, getVal81, setVal81, initVal81, LambdaContextDeclaration, Decl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY_LIST(CXXRecordDecl, lambda_explicit_template_parameters, getVal180, setVal180, initVal180, LambdaExplicitTemplateParameters, NamedDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_INT(CXXRecordDecl, lambda_mangling_number, getVal181, setVal181, initVal181, LambdaManglingNumber, unsigned, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, lambda_type_info, getVal84, setVal84, initVal84, LambdaTypeInfo, Type, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENUM(CXXRecordDecl, ms_inheritance_model, getVal87, setVal87, initVal87, MSInheritanceModel, MSInheritanceModel, NthDecl)
  MX_SERIALIZE_ENUM(CXXRecordDecl, ms_vtor_disp_mode, getVal88, setVal88, initVal88, MSVtorDispMode, MSVtorDispMode, NthDecl)
  MX_SERIALIZE_OPTIONAL_INT(CXXRecordDecl, num_bases, getVal182, setVal182, initVal182, NumBases, unsigned, NthDecl)
  MX_SERIALIZE_OPTIONAL_INT(CXXRecordDecl, num_virtual_bases, getVal183, setVal183, initVal183, NumVirtualBases, unsigned, NthDecl)
  MX_SERIALIZE_OPTIONAL_INT(CXXRecordDecl, odr_hash, getVal184, setVal184, initVal184, ODRHash, unsigned, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, template_instantiation_pattern, getVal89, setVal89, initVal89, TemplateInstantiationPattern, CXXRecordDecl, NthDecl)
  MX_SERIALIZE_ENUM(CXXRecordDecl, template_specialization_kind, getVal91, setVal91, initVal91, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_any_dependent_bases, getVal151, setVal151, initVal151, HasAnyDependentBases, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_default_constructor, getVal153, setVal153, initVal153, HasConstexprDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_destructor, getVal155, setVal155, initVal155, HasConstexprDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_non_copy_move_constructor, getVal157, setVal157, initVal157, HasConstexprNonCopyMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_copy_assignment_with_const_parameter, getVal163, setVal163, initVal163, HasCopyAssignmentWithConstParameter, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_copy_constructor_with_const_parameter, getVal165, setVal165, initVal165, HasCopyConstructorWithConstParameter, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_default_constructor, getVal167, setVal167, initVal167, HasDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_definition, getVal169, setVal169, initVal169, HasDefinition, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_direct_fields, getVal172, setVal172, initVal172, HasDirectFields, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_friends, getVal175, setVal175, initVal175, HasFriends, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_in_class_initializer, getVal177, setVal177, initVal177, HasInClassInitializer, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_inherited_assignment, getVal185, setVal185, initVal185, HasInheritedAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_inherited_constructor, getVal187, setVal187, initVal187, HasInheritedConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_irrelevant_destructor, getVal189, setVal189, initVal189, HasIrrelevantDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_known_lambda_internal_linkage, getVal191, setVal191, initVal191, HasKnownLambdaInternalLinkage, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_move_assignment, getVal193, setVal193, initVal193, HasMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_move_constructor, getVal195, setVal195, initVal195, HasMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_mutable_fields, getVal197, setVal197, initVal197, HasMutableFields, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_literal_type_fields_or_bases, getVal199, setVal199, initVal199, HasNonLiteralTypeFieldsOrBases, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_assignment, getVal201, setVal201, initVal201, HasNonTrivialCopyAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_constructor, getVal203, setVal203, initVal203, HasNonTrivialCopyConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_constructor_for_call, getVal205, setVal205, initVal205, HasNonTrivialCopyConstructorForCall, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_default_constructor, getVal207, setVal207, initVal207, HasNonTrivialDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_destructor, getVal209, setVal209, initVal209, HasNonTrivialDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_destructor_for_call, getVal211, setVal211, initVal211, HasNonTrivialDestructorForCall, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_assignment, getVal213, setVal213, initVal213, HasNonTrivialMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_constructor, getVal215, setVal215, initVal215, HasNonTrivialMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_constructor_for_call, getVal217, setVal217, initVal217, HasNonTrivialMoveConstructorForCall, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_private_fields, getVal219, setVal219, initVal219, HasPrivateFields, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_protected_fields, getVal221, setVal221, initVal221, HasProtectedFields, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_simple_copy_assignment, getVal223, setVal223, initVal223, HasSimpleCopyAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_simple_copy_constructor, getVal225, setVal225, initVal225, HasSimpleCopyConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_simple_destructor, getVal227, setVal227, initVal227, HasSimpleDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_simple_move_assignment, getVal229, setVal229, initVal229, HasSimpleMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_simple_move_constructor, getVal231, setVal231, initVal231, HasSimpleMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_assignment, getVal233, setVal233, initVal233, HasTrivialCopyAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_constructor, getVal235, setVal235, initVal235, HasTrivialCopyConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_constructor_for_call, getVal237, setVal237, initVal237, HasTrivialCopyConstructorForCall, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_default_constructor, getVal239, setVal239, initVal239, HasTrivialDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_destructor, getVal241, setVal241, initVal241, HasTrivialDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_destructor_for_call, getVal243, setVal243, initVal243, HasTrivialDestructorForCall, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_assignment, getVal245, setVal245, initVal245, HasTrivialMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_constructor, getVal247, setVal247, initVal247, HasTrivialMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_constructor_for_call, getVal249, setVal249, initVal249, HasTrivialMoveConstructorForCall, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_uninitialized_reference_member, getVal251, setVal251, initVal251, HasUninitializedReferenceMember, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_constructor, getVal253, setVal253, initVal253, HasUserDeclaredConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_copy_assignment, getVal255, setVal255, initVal255, HasUserDeclaredCopyAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_copy_constructor, getVal257, setVal257, initVal257, HasUserDeclaredCopyConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_destructor, getVal259, setVal259, initVal259, HasUserDeclaredDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_assignment, getVal261, setVal261, initVal261, HasUserDeclaredMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_constructor, getVal263, setVal263, initVal263, HasUserDeclaredMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_operation, getVal265, setVal265, initVal265, HasUserDeclaredMoveOperation, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_user_provided_default_constructor, getVal267, setVal267, initVal267, HasUserProvidedDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, has_variant_members, getVal269, setVal269, initVal269, HasVariantMembers, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, implicit_copy_assignment_has_const_parameter, getVal271, setVal271, initVal271, ImplicitCopyAssignmentHasConstParameter, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, implicit_copy_constructor_has_const_parameter, getVal273, setVal273, initVal273, ImplicitCopyConstructorHasConstParameter, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_abstract, getVal275, setVal275, initVal275, IsAbstract, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_aggregate, getVal277, setVal277, initVal277, IsAggregate, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_any_destructor_no_return, getVal279, setVal279, initVal279, IsAnyDestructorNoReturn, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_c_like, getVal281, setVal281, initVal281, IsCLike, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_cxx11_standard_layout, getVal283, setVal283, initVal283, IsCXX11StandardLayout, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXRecordDecl, is_dependent_lambda, getVal285, setVal285, initVal285, IsDependentLambda, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_dynamic_class, getVal286, setVal286, initVal286, IsDynamicClass, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_effectively_final, getVal288, setVal288, initVal288, IsEffectivelyFinal, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_empty, getVal290, setVal290, initVal290, IsEmpty, bool, NthDecl)
  MX_SERIALIZE_BOOL(CXXRecordDecl, is_generic_lambda, getVal292, setVal292, initVal292, IsGenericLambda, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_interface_like, getVal293, setVal293, initVal293, IsInterfaceLike, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_literal, getVal295, setVal295, initVal295, IsLiteral, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(CXXRecordDecl, is_local_class, getVal129, setVal129, initVal129, IsLocalClass, FunctionDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_pod, getVal298, setVal298, initVal298, IsPOD, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_polymorphic, getVal300, setVal300, initVal300, IsPolymorphic, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_standard_layout, getVal302, setVal302, initVal302, IsStandardLayout, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_structural, getVal304, setVal304, initVal304, IsStructural, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_trivial, getVal306, setVal306, initVal306, IsTrivial, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, is_trivially_copyable, getVal308, setVal308, initVal308, IsTriviallyCopyable, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, lambda_is_default_constructible_and_assignable, getVal310, setVal310, initVal310, LambdaIsDefaultConstructibleAndAssignable, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, may_be_abstract, getVal312, setVal312, initVal312, MayBeAbstract, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, may_be_dynamic_class, getVal314, setVal314, initVal314, MayBeDynamicClass, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, may_be_non_dynamic_class, getVal316, setVal316, initVal316, MayBeNonDynamicClass, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY_LIST(CXXRecordDecl, methods, getVal318, setVal318, initVal318, Methods, CXXMethodDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_copy_assignment, getVal320, setVal320, initVal320, NeedsImplicitCopyAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_copy_constructor, getVal322, setVal322, initVal322, NeedsImplicitCopyConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_default_constructor, getVal324, setVal324, initVal324, NeedsImplicitDefaultConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_destructor, getVal326, setVal326, initVal326, NeedsImplicitDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_move_assignment, getVal328, setVal328, initVal328, NeedsImplicitMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_move_constructor, getVal330, setVal330, initVal330, NeedsImplicitMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_copy_assignment, getVal332, setVal332, initVal332, NeedsOverloadResolutionForCopyAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_copy_constructor, getVal334, setVal334, initVal334, NeedsOverloadResolutionForCopyConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_destructor, getVal336, setVal336, initVal336, NeedsOverloadResolutionForDestructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_move_assignment, getVal338, setVal338, initVal338, NeedsOverloadResolutionForMoveAssignment, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_move_constructor, getVal340, setVal340, initVal340, NeedsOverloadResolutionForMoveConstructor, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_BOOL(CXXRecordDecl, null_field_offset_is_zero, getVal342, setVal342, initVal342, NullFieldOffsetIsZero, bool, NthDecl)
  MX_SERIALIZE_OPTIONAL_PSEUDO_LIST(CXXRecordDecl, virtual_bases, getVal145, setVal145, initVal145, VirtualBases, CXXBaseSpecifier, NthDecl)
  MX_EXIT_SERIALIZE_CXXRecordDecl
MX_END_SERIALIZE_DECL(CXXRecordDecl)
#undef MX_ENTER_SERIALIZE_CXXRecordDecl
#undef MX_EXIT_SERIALIZE_CXXRecordDecl

#ifndef MX_ENTER_SERIALIZE_ClassTemplateSpecializationDecl
#  define MX_ENTER_SERIALIZE_ClassTemplateSpecializationDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ClassTemplateSpecializationDecl
#  define MX_EXIT_SERIALIZE_ClassTemplateSpecializationDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ClassTemplateSpecializationDecl)
  MX_ENTER_SERIALIZE_ClassTemplateSpecializationDecl
  MX_SERIALIZE_BASE(ClassTemplateSpecializationDecl, CXXRecordDecl)
  MX_SERIALIZE_ENTITY(ClassTemplateSpecializationDecl, extern_token, getVal131, setVal131, initVal131, ExternToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ClassTemplateSpecializationDecl, point_of_instantiation, getVal132, setVal132, initVal132, PointOfInstantiation, Token, NthDecl)
  MX_SERIALIZE_ENUM(ClassTemplateSpecializationDecl, specialization_kind, getVal92, setVal92, initVal92, SpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(ClassTemplateSpecializationDecl, template_arguments, getVal345, setVal345, initVal345, TemplateArguments, TemplateArgument, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(ClassTemplateSpecializationDecl, template_instantiation_arguments, getVal346, setVal346, initVal346, TemplateInstantiationArguments, TemplateArgument, NthDecl)
  MX_SERIALIZE_ENTITY(ClassTemplateSpecializationDecl, template_keyword_token, getVal134, setVal134, initVal134, TemplateKeywordToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ClassTemplateSpecializationDecl, type_as_written, getVal135, setVal135, initVal135, TypeAsWritten, Type, NthDecl)
  MX_SERIALIZE_BOOL(ClassTemplateSpecializationDecl, is_class_scope_explicit_specialization, getVal347, setVal347, initVal347, IsClassScopeExplicitSpecialization, bool, NthDecl)
  MX_SERIALIZE_BOOL(ClassTemplateSpecializationDecl, is_explicit_instantiation_or_specialization, getVal348, setVal348, initVal348, IsExplicitInstantiationOrSpecialization, bool, NthDecl)
  MX_SERIALIZE_BOOL(ClassTemplateSpecializationDecl, is_explicit_specialization, getVal349, setVal349, initVal349, IsExplicitSpecialization, bool, NthDecl)
  MX_EXIT_SERIALIZE_ClassTemplateSpecializationDecl
MX_END_SERIALIZE_DECL(ClassTemplateSpecializationDecl)
#undef MX_ENTER_SERIALIZE_ClassTemplateSpecializationDecl
#undef MX_EXIT_SERIALIZE_ClassTemplateSpecializationDecl

#ifndef MX_ENTER_SERIALIZE_ClassTemplatePartialSpecializationDecl
#  define MX_ENTER_SERIALIZE_ClassTemplatePartialSpecializationDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ClassTemplatePartialSpecializationDecl
#  define MX_EXIT_SERIALIZE_ClassTemplatePartialSpecializationDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ClassTemplatePartialSpecializationDecl)
  MX_ENTER_SERIALIZE_ClassTemplatePartialSpecializationDecl
  MX_EXIT_SERIALIZE_ClassTemplatePartialSpecializationDecl
MX_END_SERIALIZE_DECL(ClassTemplatePartialSpecializationDecl)
#undef MX_ENTER_SERIALIZE_ClassTemplatePartialSpecializationDecl
#undef MX_EXIT_SERIALIZE_ClassTemplatePartialSpecializationDecl

#ifndef MX_ENTER_SERIALIZE_EnumDecl
#  define MX_ENTER_SERIALIZE_EnumDecl
#endif
#ifndef MX_EXIT_SERIALIZE_EnumDecl
#  define MX_EXIT_SERIALIZE_EnumDecl
#endif

MX_BEGIN_SERIALIZE_DECL(EnumDecl)
  MX_ENTER_SERIALIZE_EnumDecl
  MX_SERIALIZE_BASE(EnumDecl, TagDecl)
  MX_SERIALIZE_ENTITY_LIST(EnumDecl, enumerators, getVal46, setVal46, initVal46, Enumerators, EnumConstantDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(EnumDecl, instantiated_from_member_enum, getVal72, setVal72, initVal72, InstantiatedFromMemberEnum, EnumDecl, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(EnumDecl, integer_type, getVal74, setVal74, initVal74, IntegerType, Type, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(EnumDecl, integer_type_source_info, getVal81, setVal81, initVal81, IntegerTypeSourceInfo, Type, NthDecl)
  MX_SERIALIZE_OPTIONAL_INT(EnumDecl, odr_hash, getVal146, setVal146, initVal146, ODRHash, unsigned, NthDecl)
  MX_SERIALIZE_ENTITY(EnumDecl, promotion_type, getVal84, setVal84, initVal84, PromotionType, Type, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(EnumDecl, template_instantiation_pattern, getVal89, setVal89, initVal89, TemplateInstantiationPattern, EnumDecl, NthDecl)
  MX_SERIALIZE_ENUM(EnumDecl, template_specialization_kind, getVal83, setVal83, initVal83, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_closed, getVal105, setVal105, initVal105, IsClosed, bool, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_closed_flag, getVal106, setVal106, initVal106, IsClosedFlag, bool, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_closed_non_flag, getVal107, setVal107, initVal107, IsClosedNonFlag, bool, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_complete, getVal108, setVal108, initVal108, IsComplete, bool, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_fixed, getVal109, setVal109, initVal109, IsFixed, bool, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_scoped, getVal110, setVal110, initVal110, IsScoped, bool, NthDecl)
  MX_SERIALIZE_BOOL(EnumDecl, is_scoped_using_class_tag, getVal111, setVal111, initVal111, IsScopedUsingClassTag, bool, NthDecl)
  MX_EXIT_SERIALIZE_EnumDecl
MX_END_SERIALIZE_DECL(EnumDecl)
#undef MX_ENTER_SERIALIZE_EnumDecl
#undef MX_EXIT_SERIALIZE_EnumDecl

#ifndef MX_ENTER_SERIALIZE_UnresolvedUsingTypenameDecl
#  define MX_ENTER_SERIALIZE_UnresolvedUsingTypenameDecl
#endif
#ifndef MX_EXIT_SERIALIZE_UnresolvedUsingTypenameDecl
#  define MX_EXIT_SERIALIZE_UnresolvedUsingTypenameDecl
#endif

MX_BEGIN_SERIALIZE_DECL(UnresolvedUsingTypenameDecl)
  MX_ENTER_SERIALIZE_UnresolvedUsingTypenameDecl
  MX_SERIALIZE_BASE(UnresolvedUsingTypenameDecl, TypeDecl)
  MX_SERIALIZE_ENTITY(UnresolvedUsingTypenameDecl, ellipsis_token, getVal52, setVal52, initVal52, EllipsisToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(UnresolvedUsingTypenameDecl, typename_token, getVal53, setVal53, initVal53, TypenameToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(UnresolvedUsingTypenameDecl, using_token, getVal61, setVal61, initVal61, UsingToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(UnresolvedUsingTypenameDecl, is_pack_expansion, getVal70, setVal70, initVal70, IsPackExpansion, bool, NthDecl)
  MX_EXIT_SERIALIZE_UnresolvedUsingTypenameDecl
MX_END_SERIALIZE_DECL(UnresolvedUsingTypenameDecl)
#undef MX_ENTER_SERIALIZE_UnresolvedUsingTypenameDecl
#undef MX_EXIT_SERIALIZE_UnresolvedUsingTypenameDecl

#ifndef MX_ENTER_SERIALIZE_TypedefNameDecl
#  define MX_ENTER_SERIALIZE_TypedefNameDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TypedefNameDecl
#  define MX_EXIT_SERIALIZE_TypedefNameDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TypedefNameDecl)
  MX_ENTER_SERIALIZE_TypedefNameDecl
  MX_SERIALIZE_BASE(TypedefNameDecl, TypeDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(TypedefNameDecl, anonymous_declaration_with_typedef_name, getVal52, setVal52, initVal52, AnonymousDeclarationWithTypedefName, TagDecl, NthDecl)
  MX_SERIALIZE_ENTITY(TypedefNameDecl, type_source_info, getVal53, setVal53, initVal53, TypeSourceInfo, Type, NthDecl)
  MX_SERIALIZE_ENTITY(TypedefNameDecl, underlying_type, getVal61, setVal61, initVal61, UnderlyingType, Type, NthDecl)
  MX_SERIALIZE_BOOL(TypedefNameDecl, is_moded, getVal71, setVal71, initVal71, IsModed, bool, NthDecl)
  MX_SERIALIZE_BOOL(TypedefNameDecl, is_transparent_tag, getVal76, setVal76, initVal76, IsTransparentTag, bool, NthDecl)
  MX_EXIT_SERIALIZE_TypedefNameDecl
MX_END_SERIALIZE_DECL(TypedefNameDecl)
#undef MX_ENTER_SERIALIZE_TypedefNameDecl
#undef MX_EXIT_SERIALIZE_TypedefNameDecl

#ifndef MX_ENTER_SERIALIZE_TypedefDecl
#  define MX_ENTER_SERIALIZE_TypedefDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TypedefDecl
#  define MX_EXIT_SERIALIZE_TypedefDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TypedefDecl)
  MX_ENTER_SERIALIZE_TypedefDecl
  MX_SERIALIZE_BASE(TypedefDecl, TypedefNameDecl)
  MX_EXIT_SERIALIZE_TypedefDecl
MX_END_SERIALIZE_DECL(TypedefDecl)
#undef MX_ENTER_SERIALIZE_TypedefDecl
#undef MX_EXIT_SERIALIZE_TypedefDecl

#ifndef MX_ENTER_SERIALIZE_TypeAliasDecl
#  define MX_ENTER_SERIALIZE_TypeAliasDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TypeAliasDecl
#  define MX_EXIT_SERIALIZE_TypeAliasDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TypeAliasDecl)
  MX_ENTER_SERIALIZE_TypeAliasDecl
  MX_SERIALIZE_BASE(TypeAliasDecl, TypedefNameDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(TypeAliasDecl, described_alias_template, getVal62, setVal62, initVal62, DescribedAliasTemplate, TypeAliasTemplateDecl, NthDecl)
  MX_EXIT_SERIALIZE_TypeAliasDecl
MX_END_SERIALIZE_DECL(TypeAliasDecl)
#undef MX_ENTER_SERIALIZE_TypeAliasDecl
#undef MX_EXIT_SERIALIZE_TypeAliasDecl

#ifndef MX_ENTER_SERIALIZE_ObjCTypeParamDecl
#  define MX_ENTER_SERIALIZE_ObjCTypeParamDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCTypeParamDecl
#  define MX_EXIT_SERIALIZE_ObjCTypeParamDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCTypeParamDecl)
  MX_ENTER_SERIALIZE_ObjCTypeParamDecl
  MX_SERIALIZE_BASE(ObjCTypeParamDecl, TypedefNameDecl)
  MX_SERIALIZE_ENTITY(ObjCTypeParamDecl, colon_token, getVal62, setVal62, initVal62, ColonToken, Token, NthDecl)
  MX_SERIALIZE_ENUM(ObjCTypeParamDecl, variance, getVal73, setVal73, initVal73, Variance, ObjCTypeParamVariance, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCTypeParamDecl, variance_token, getVal63, setVal63, initVal63, VarianceToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(ObjCTypeParamDecl, has_explicit_bound, getVal78, setVal78, initVal78, HasExplicitBound, bool, NthDecl)
  MX_EXIT_SERIALIZE_ObjCTypeParamDecl
MX_END_SERIALIZE_DECL(ObjCTypeParamDecl)
#undef MX_ENTER_SERIALIZE_ObjCTypeParamDecl
#undef MX_EXIT_SERIALIZE_ObjCTypeParamDecl

#ifndef MX_ENTER_SERIALIZE_TemplateDecl
#  define MX_ENTER_SERIALIZE_TemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateDecl
#  define MX_EXIT_SERIALIZE_TemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TemplateDecl)
  MX_ENTER_SERIALIZE_TemplateDecl
  MX_EXIT_SERIALIZE_TemplateDecl
MX_END_SERIALIZE_DECL(TemplateDecl)
#undef MX_ENTER_SERIALIZE_TemplateDecl
#undef MX_EXIT_SERIALIZE_TemplateDecl

#ifndef MX_ENTER_SERIALIZE_RedeclarableTemplateDecl
#  define MX_ENTER_SERIALIZE_RedeclarableTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_RedeclarableTemplateDecl
#  define MX_EXIT_SERIALIZE_RedeclarableTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(RedeclarableTemplateDecl)
  MX_ENTER_SERIALIZE_RedeclarableTemplateDecl
  MX_EXIT_SERIALIZE_RedeclarableTemplateDecl
MX_END_SERIALIZE_DECL(RedeclarableTemplateDecl)
#undef MX_ENTER_SERIALIZE_RedeclarableTemplateDecl
#undef MX_EXIT_SERIALIZE_RedeclarableTemplateDecl

#ifndef MX_ENTER_SERIALIZE_FunctionTemplateDecl
#  define MX_ENTER_SERIALIZE_FunctionTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_FunctionTemplateDecl
#  define MX_EXIT_SERIALIZE_FunctionTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(FunctionTemplateDecl)
  MX_ENTER_SERIALIZE_FunctionTemplateDecl
  MX_EXIT_SERIALIZE_FunctionTemplateDecl
MX_END_SERIALIZE_DECL(FunctionTemplateDecl)
#undef MX_ENTER_SERIALIZE_FunctionTemplateDecl
#undef MX_EXIT_SERIALIZE_FunctionTemplateDecl

#ifndef MX_ENTER_SERIALIZE_ClassTemplateDecl
#  define MX_ENTER_SERIALIZE_ClassTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ClassTemplateDecl
#  define MX_EXIT_SERIALIZE_ClassTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ClassTemplateDecl)
  MX_ENTER_SERIALIZE_ClassTemplateDecl
  MX_EXIT_SERIALIZE_ClassTemplateDecl
MX_END_SERIALIZE_DECL(ClassTemplateDecl)
#undef MX_ENTER_SERIALIZE_ClassTemplateDecl
#undef MX_EXIT_SERIALIZE_ClassTemplateDecl

#ifndef MX_ENTER_SERIALIZE_VarTemplateDecl
#  define MX_ENTER_SERIALIZE_VarTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_VarTemplateDecl
#  define MX_EXIT_SERIALIZE_VarTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(VarTemplateDecl)
  MX_ENTER_SERIALIZE_VarTemplateDecl
  MX_EXIT_SERIALIZE_VarTemplateDecl
MX_END_SERIALIZE_DECL(VarTemplateDecl)
#undef MX_ENTER_SERIALIZE_VarTemplateDecl
#undef MX_EXIT_SERIALIZE_VarTemplateDecl

#ifndef MX_ENTER_SERIALIZE_TypeAliasTemplateDecl
#  define MX_ENTER_SERIALIZE_TypeAliasTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TypeAliasTemplateDecl
#  define MX_EXIT_SERIALIZE_TypeAliasTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TypeAliasTemplateDecl)
  MX_ENTER_SERIALIZE_TypeAliasTemplateDecl
  MX_SERIALIZE_BASE(TypeAliasTemplateDecl, RedeclarableTemplateDecl)
  MX_EXIT_SERIALIZE_TypeAliasTemplateDecl
MX_END_SERIALIZE_DECL(TypeAliasTemplateDecl)
#undef MX_ENTER_SERIALIZE_TypeAliasTemplateDecl
#undef MX_EXIT_SERIALIZE_TypeAliasTemplateDecl

#ifndef MX_ENTER_SERIALIZE_ConceptDecl
#  define MX_ENTER_SERIALIZE_ConceptDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ConceptDecl
#  define MX_EXIT_SERIALIZE_ConceptDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ConceptDecl)
  MX_ENTER_SERIALIZE_ConceptDecl
  MX_SERIALIZE_BASE(ConceptDecl, TemplateDecl)
  MX_SERIALIZE_ENTITY(ConceptDecl, constraint_expression, getVal51, setVal51, initVal51, ConstraintExpression, Expr, NthDecl)
  MX_SERIALIZE_BOOL(ConceptDecl, is_type_concept, getVal69, setVal69, initVal69, IsTypeConcept, bool, NthDecl)
  MX_EXIT_SERIALIZE_ConceptDecl
MX_END_SERIALIZE_DECL(ConceptDecl)
#undef MX_ENTER_SERIALIZE_ConceptDecl
#undef MX_EXIT_SERIALIZE_ConceptDecl

#ifndef MX_ENTER_SERIALIZE_BuiltinTemplateDecl
#  define MX_ENTER_SERIALIZE_BuiltinTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_BuiltinTemplateDecl
#  define MX_EXIT_SERIALIZE_BuiltinTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(BuiltinTemplateDecl)
  MX_ENTER_SERIALIZE_BuiltinTemplateDecl
  MX_EXIT_SERIALIZE_BuiltinTemplateDecl
MX_END_SERIALIZE_DECL(BuiltinTemplateDecl)
#undef MX_ENTER_SERIALIZE_BuiltinTemplateDecl
#undef MX_EXIT_SERIALIZE_BuiltinTemplateDecl

#ifndef MX_ENTER_SERIALIZE_TemplateTemplateParmDecl
#  define MX_ENTER_SERIALIZE_TemplateTemplateParmDecl
#endif
#ifndef MX_EXIT_SERIALIZE_TemplateTemplateParmDecl
#  define MX_EXIT_SERIALIZE_TemplateTemplateParmDecl
#endif

MX_BEGIN_SERIALIZE_DECL(TemplateTemplateParmDecl)
  MX_ENTER_SERIALIZE_TemplateTemplateParmDecl
  MX_EXIT_SERIALIZE_TemplateTemplateParmDecl
MX_END_SERIALIZE_DECL(TemplateTemplateParmDecl)
#undef MX_ENTER_SERIALIZE_TemplateTemplateParmDecl
#undef MX_EXIT_SERIALIZE_TemplateTemplateParmDecl

#ifndef MX_ENTER_SERIALIZE_ObjCPropertyDecl
#  define MX_ENTER_SERIALIZE_ObjCPropertyDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCPropertyDecl
#  define MX_EXIT_SERIALIZE_ObjCPropertyDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCPropertyDecl)
  MX_ENTER_SERIALIZE_ObjCPropertyDecl
  MX_SERIALIZE_BASE(ObjCPropertyDecl, NamedDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, at_token, getVal51, setVal51, initVal51, AtToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, getter_method_declaration, getVal52, setVal52, initVal52, GetterMethodDeclaration, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, getter_name_token, getVal53, setVal53, initVal53, GetterNameToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, l_paren_token, getVal61, setVal61, initVal61, LParenToken, Token, NthDecl)
  MX_SERIALIZE_ENUM(ObjCPropertyDecl, property_implementation, getVal73, setVal73, initVal73, PropertyImplementation, ObjCPropertyDeclPropertyControl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, property_instance_variable_declaration, getVal62, setVal62, initVal62, PropertyInstanceVariableDeclaration, ObjCIvarDecl, NthDecl)
  MX_SERIALIZE_ENUM(ObjCPropertyDecl, query_kind, getVal83, setVal83, initVal83, QueryKind, ObjCPropertyQueryKind, NthDecl)
  MX_SERIALIZE_ENUM(ObjCPropertyDecl, setter_kind, getVal85, setVal85, initVal85, SetterKind, ObjCPropertyDeclSetterKind, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, setter_method_declaration, getVal63, setVal63, initVal63, SetterMethodDeclaration, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, setter_name_token, getVal72, setVal72, initVal72, SetterNameToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, type, getVal74, setVal74, initVal74, Type, Type, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCPropertyDecl, type_source_info, getVal77, setVal77, initVal77, TypeSourceInfo, Type, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_atomic, getVal69, setVal69, initVal69, IsAtomic, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_class_property, getVal70, setVal70, initVal70, IsClassProperty, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_direct_property, getVal71, setVal71, initVal71, IsDirectProperty, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_instance_property, getVal76, setVal76, initVal76, IsInstanceProperty, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_optional, getVal78, setVal78, initVal78, IsOptional, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_read_only, getVal80, setVal80, initVal80, IsReadOnly, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCPropertyDecl, is_retaining, getVal82, setVal82, initVal82, IsRetaining, bool, NthDecl)
  MX_EXIT_SERIALIZE_ObjCPropertyDecl
MX_END_SERIALIZE_DECL(ObjCPropertyDecl)
#undef MX_ENTER_SERIALIZE_ObjCPropertyDecl
#undef MX_EXIT_SERIALIZE_ObjCPropertyDecl

#ifndef MX_ENTER_SERIALIZE_ObjCMethodDecl
#  define MX_ENTER_SERIALIZE_ObjCMethodDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCMethodDecl
#  define MX_EXIT_SERIALIZE_ObjCMethodDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCMethodDecl)
  MX_ENTER_SERIALIZE_ObjCMethodDecl
  MX_SERIALIZE_BASE(ObjCMethodDecl, NamedDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, defined_in_ns_object, getVal69, setVal69, initVal69, DefinedInNSObject, bool, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, find_property_declaration, getVal51, setVal51, initVal51, FindPropertyDeclaration, ObjCPropertyDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, category, getVal52, setVal52, initVal52, Category, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, class_interface, getVal53, setVal53, initVal53, ClassInterface, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, cmd_declaration, getVal61, setVal61, initVal61, CmdDeclaration, ImplicitParamDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, declarator_end_token, getVal62, setVal62, initVal62, DeclaratorEndToken, Token, NthDecl)
  MX_SERIALIZE_ENUM(ObjCMethodDecl, implementation_control, getVal73, setVal73, initVal73, ImplementationControl, ObjCMethodDeclImplementationControl, NthDecl)
  MX_SERIALIZE_ENUM(ObjCMethodDecl, method_family, getVal83, setVal83, initVal83, MethodFamily, ObjCMethodFamily, NthDecl)
  MX_SERIALIZE_ENUM(ObjCMethodDecl, obj_c_decl_qualifier, getVal85, setVal85, initVal85, ObjCDeclQualifier, DeclObjCDeclQualifier, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, return_type, getVal63, setVal63, initVal63, ReturnType, Type, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, return_type_source_info, getVal72, setVal72, initVal72, ReturnTypeSourceInfo, Type, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, selector_start_token, getVal79, setVal79, initVal79, SelectorStartToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCMethodDecl, self_declaration, getVal81, setVal81, initVal81, SelfDeclaration, ImplicitParamDecl, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, has_redeclaration, getVal70, setVal70, initVal70, HasRedeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, has_related_result_type, getVal71, setVal71, initVal71, HasRelatedResultType, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, has_skipped_body, getVal76, setVal76, initVal76, HasSkippedBody, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_class_method, getVal78, setVal78, initVal78, IsClassMethod, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_defined, getVal80, setVal80, initVal80, IsDefined, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_designated_initializer_for_the_interface, getVal82, setVal82, initVal82, IsDesignatedInitializerForTheInterface, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_direct_method, getVal90, setVal90, initVal90, IsDirectMethod, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_instance_method, getVal93, setVal93, initVal93, IsInstanceMethod, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_optional, getVal94, setVal94, initVal94, IsOptional, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_overriding, getVal95, setVal95, initVal95, IsOverriding, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_property_accessor, getVal96, setVal96, initVal96, IsPropertyAccessor, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_redeclaration, getVal97, setVal97, initVal97, IsRedeclaration, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_synthesized_accessor_stub, getVal98, setVal98, initVal98, IsSynthesizedAccessorStub, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_this_declaration_a_designated_initializer, getVal99, setVal99, initVal99, IsThisDeclarationADesignatedInitializer, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCMethodDecl, is_variadic, getVal100, setVal100, initVal100, IsVariadic, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCMethodDecl, parameters, getVal45, setVal45, initVal45, Parameters, ParmVarDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCMethodDecl, selector_tokens, getVal46, setVal46, initVal46, SelectorTokens, Token, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(ObjCMethodDecl, declarations_in_context, getVal57, setVal57, initVal57, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCMethodDecl
MX_END_SERIALIZE_DECL(ObjCMethodDecl)
#undef MX_ENTER_SERIALIZE_ObjCMethodDecl
#undef MX_EXIT_SERIALIZE_ObjCMethodDecl

#ifndef MX_ENTER_SERIALIZE_ObjCContainerDecl
#  define MX_ENTER_SERIALIZE_ObjCContainerDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCContainerDecl
#  define MX_EXIT_SERIALIZE_ObjCContainerDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCContainerDecl)
  MX_ENTER_SERIALIZE_ObjCContainerDecl
  MX_SERIALIZE_BASE(ObjCContainerDecl, NamedDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCContainerDecl, class_methods, getVal45, setVal45, initVal45, ClassMethods, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCContainerDecl, class_properties, getVal46, setVal46, initVal46, ClassProperties, ObjCPropertyDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCContainerDecl, at_start_token, getVal53, setVal53, initVal53, AtStartToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCContainerDecl, instance_methods, getVal57, setVal57, initVal57, InstanceMethods, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCContainerDecl, instance_properties, getVal179, setVal179, initVal179, InstanceProperties, ObjCPropertyDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCContainerDecl, methods, getVal180, setVal180, initVal180, Methods, ObjCMethodDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCContainerDecl, properties, getVal318, setVal318, initVal318, Properties, ObjCPropertyDecl, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(ObjCContainerDecl, declarations_in_context, getVal350, setVal350, initVal350, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCContainerDecl
MX_END_SERIALIZE_DECL(ObjCContainerDecl)
#undef MX_ENTER_SERIALIZE_ObjCContainerDecl
#undef MX_EXIT_SERIALIZE_ObjCContainerDecl

#ifndef MX_ENTER_SERIALIZE_ObjCCategoryDecl
#  define MX_ENTER_SERIALIZE_ObjCCategoryDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCCategoryDecl
#  define MX_EXIT_SERIALIZE_ObjCCategoryDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCCategoryDecl)
  MX_ENTER_SERIALIZE_ObjCCategoryDecl
  MX_SERIALIZE_BASE(ObjCCategoryDecl, ObjCContainerDecl)
  MX_SERIALIZE_BOOL(ObjCCategoryDecl, is_class_extension, getVal69, setVal69, initVal69, IsClassExtension, bool, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, category_name_token, getVal61, setVal61, initVal61, CategoryNameToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, class_interface, getVal62, setVal62, initVal62, ClassInterface, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, implementation, getVal63, setVal63, initVal63, Implementation, ObjCCategoryImplDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, instance_variable_l_brace_token, getVal72, setVal72, initVal72, InstanceVariableLBraceToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, instance_variable_r_brace_token, getVal74, setVal74, initVal74, InstanceVariableRBraceToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, next_class_category, getVal77, setVal77, initVal77, NextClassCategory, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryDecl, next_class_category_raw, getVal79, setVal79, initVal79, NextClassCategoryRaw, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCCategoryDecl, instance_variables, getVal351, setVal351, initVal351, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCCategoryDecl, protocol_tokens, getVal352, setVal352, initVal352, ProtocolTokens, Token, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCCategoryDecl, protocols, getVal353, setVal353, initVal353, Protocols, ObjCProtocolDecl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCCategoryDecl
MX_END_SERIALIZE_DECL(ObjCCategoryDecl)
#undef MX_ENTER_SERIALIZE_ObjCCategoryDecl
#undef MX_EXIT_SERIALIZE_ObjCCategoryDecl

#ifndef MX_ENTER_SERIALIZE_ObjCProtocolDecl
#  define MX_ENTER_SERIALIZE_ObjCProtocolDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCProtocolDecl
#  define MX_EXIT_SERIALIZE_ObjCProtocolDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCProtocolDecl)
  MX_ENTER_SERIALIZE_ObjCProtocolDecl
  MX_SERIALIZE_BASE(ObjCProtocolDecl, ObjCContainerDecl)
  MX_SERIALIZE_TEXT(ObjCProtocolDecl, obj_c_runtime_name_as_string, getVal68, setVal68, initVal68, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_SERIALIZE_BOOL(ObjCProtocolDecl, has_definition, getVal69, setVal69, initVal69, HasDefinition, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCProtocolDecl, is_non_runtime_protocol, getVal70, setVal70, initVal70, IsNonRuntimeProtocol, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCProtocolDecl, protocol_tokens, getVal351, setVal351, initVal351, ProtocolTokens, Token, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCProtocolDecl, protocols, getVal352, setVal352, initVal352, Protocols, ObjCProtocolDecl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCProtocolDecl
MX_END_SERIALIZE_DECL(ObjCProtocolDecl)
#undef MX_ENTER_SERIALIZE_ObjCProtocolDecl
#undef MX_EXIT_SERIALIZE_ObjCProtocolDecl

#ifndef MX_ENTER_SERIALIZE_ObjCInterfaceDecl
#  define MX_ENTER_SERIALIZE_ObjCInterfaceDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCInterfaceDecl
#  define MX_EXIT_SERIALIZE_ObjCInterfaceDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCInterfaceDecl)
  MX_ENTER_SERIALIZE_ObjCInterfaceDecl
  MX_SERIALIZE_BASE(ObjCInterfaceDecl, ObjCContainerDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, all_referenced_protocols, getVal351, setVal351, initVal351, AllReferencedProtocols, ObjCProtocolDecl, NthDecl)
  MX_SERIALIZE_BOOL(ObjCInterfaceDecl, declares_or_inherits_designated_initializers, getVal69, setVal69, initVal69, DeclaresOrInheritsDesignatedInitializers, bool, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCInterfaceDecl, category_list_raw, getVal61, setVal61, initVal61, CategoryListRaw, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCInterfaceDecl, end_of_definition_token, getVal62, setVal62, initVal62, EndOfDefinitionToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCInterfaceDecl, implementation, getVal63, setVal63, initVal63, Implementation, ObjCImplementationDecl, NthDecl)
  MX_SERIALIZE_TEXT(ObjCInterfaceDecl, obj_c_runtime_name_as_string, getVal68, setVal68, initVal68, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class, getVal72, setVal72, initVal72, SuperClass, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCInterfaceDecl, super_class_token, getVal74, setVal74, initVal74, SuperClassToken, Token, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class_type_info, getVal77, setVal77, initVal77, SuperClassTypeInfo, Type, NthDecl)
  MX_SERIALIZE_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class_type, getVal79, setVal79, initVal79, SuperClassType, ObjCObjectType, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCInterfaceDecl, type_for_declaration, getVal81, setVal81, initVal81, TypeForDeclaration, Type, NthDecl)
  MX_SERIALIZE_BOOL(ObjCInterfaceDecl, has_definition, getVal78, setVal78, initVal78, HasDefinition, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCInterfaceDecl, has_designated_initializers, getVal80, setVal80, initVal80, HasDesignatedInitializers, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCInterfaceDecl, is_arc_weakref_unavailable, getVal82, setVal82, initVal82, IsArcWeakrefUnavailable, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCInterfaceDecl, is_implicit_interface_declaration, getVal90, setVal90, initVal90, IsImplicitInterfaceDeclaration, bool, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCInterfaceDecl, is_obj_c_requires_property_definitions, getVal84, setVal84, initVal84, IsObjCRequiresPropertyDefinitions, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, instance_variables, getVal352, setVal352, initVal352, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, known_categories, getVal353, setVal353, initVal353, KnownCategories, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, known_extensions, getVal354, setVal354, initVal354, KnownExtensions, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, protocol_tokens, getVal355, setVal355, initVal355, ProtocolTokens, Token, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, protocols, getVal356, setVal356, initVal356, Protocols, ObjCProtocolDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, visible_categories, getVal357, setVal357, initVal357, VisibleCategories, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCInterfaceDecl, visible_extensions, getVal358, setVal358, initVal358, VisibleExtensions, ObjCCategoryDecl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCInterfaceDecl
MX_END_SERIALIZE_DECL(ObjCInterfaceDecl)
#undef MX_ENTER_SERIALIZE_ObjCInterfaceDecl
#undef MX_EXIT_SERIALIZE_ObjCInterfaceDecl

#ifndef MX_ENTER_SERIALIZE_ObjCImplDecl
#  define MX_ENTER_SERIALIZE_ObjCImplDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCImplDecl
#  define MX_EXIT_SERIALIZE_ObjCImplDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCImplDecl)
  MX_ENTER_SERIALIZE_ObjCImplDecl
  MX_SERIALIZE_BASE(ObjCImplDecl, ObjCContainerDecl)
  MX_SERIALIZE_ENTITY(ObjCImplDecl, class_interface, getVal61, setVal61, initVal61, ClassInterface, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCImplDecl, property_implementations, getVal351, setVal351, initVal351, PropertyImplementations, ObjCPropertyImplDecl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCImplDecl
MX_END_SERIALIZE_DECL(ObjCImplDecl)
#undef MX_ENTER_SERIALIZE_ObjCImplDecl
#undef MX_EXIT_SERIALIZE_ObjCImplDecl

#ifndef MX_ENTER_SERIALIZE_ObjCCategoryImplDecl
#  define MX_ENTER_SERIALIZE_ObjCCategoryImplDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCCategoryImplDecl
#  define MX_EXIT_SERIALIZE_ObjCCategoryImplDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCCategoryImplDecl)
  MX_ENTER_SERIALIZE_ObjCCategoryImplDecl
  MX_SERIALIZE_BASE(ObjCCategoryImplDecl, ObjCImplDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryImplDecl, category_declaration, getVal62, setVal62, initVal62, CategoryDeclaration, ObjCCategoryDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCCategoryImplDecl, category_name_token, getVal63, setVal63, initVal63, CategoryNameToken, Token, NthDecl)
  MX_EXIT_SERIALIZE_ObjCCategoryImplDecl
MX_END_SERIALIZE_DECL(ObjCCategoryImplDecl)
#undef MX_ENTER_SERIALIZE_ObjCCategoryImplDecl
#undef MX_EXIT_SERIALIZE_ObjCCategoryImplDecl

#ifndef MX_ENTER_SERIALIZE_ObjCImplementationDecl
#  define MX_ENTER_SERIALIZE_ObjCImplementationDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCImplementationDecl
#  define MX_EXIT_SERIALIZE_ObjCImplementationDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCImplementationDecl)
  MX_ENTER_SERIALIZE_ObjCImplementationDecl
  MX_SERIALIZE_BASE(ObjCImplementationDecl, ObjCImplDecl)
  MX_SERIALIZE_ENTITY(ObjCImplementationDecl, instance_variable_l_brace_token, getVal62, setVal62, initVal62, InstanceVariableLBraceToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCImplementationDecl, instance_variable_r_brace_token, getVal63, setVal63, initVal63, InstanceVariableRBraceToken, Token, NthDecl)
  MX_SERIALIZE_TEXT(ObjCImplementationDecl, obj_c_runtime_name_as_string, getVal68, setVal68, initVal68, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCImplementationDecl, super_class, getVal72, setVal72, initVal72, SuperClass, ObjCInterfaceDecl, NthDecl)
  MX_SERIALIZE_ENTITY(ObjCImplementationDecl, super_class_token, getVal74, setVal74, initVal74, SuperClassToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(ObjCImplementationDecl, has_destructors, getVal69, setVal69, initVal69, HasDestructors, bool, NthDecl)
  MX_SERIALIZE_BOOL(ObjCImplementationDecl, has_non_zero_constructors, getVal70, setVal70, initVal70, HasNonZeroConstructors, bool, NthDecl)
  MX_SERIALIZE_ENTITY_LIST(ObjCImplementationDecl, instance_variables, getVal352, setVal352, initVal352, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCImplementationDecl
MX_END_SERIALIZE_DECL(ObjCImplementationDecl)
#undef MX_ENTER_SERIALIZE_ObjCImplementationDecl
#undef MX_EXIT_SERIALIZE_ObjCImplementationDecl

#ifndef MX_ENTER_SERIALIZE_ObjCCompatibleAliasDecl
#  define MX_ENTER_SERIALIZE_ObjCCompatibleAliasDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ObjCCompatibleAliasDecl
#  define MX_EXIT_SERIALIZE_ObjCCompatibleAliasDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ObjCCompatibleAliasDecl)
  MX_ENTER_SERIALIZE_ObjCCompatibleAliasDecl
  MX_SERIALIZE_BASE(ObjCCompatibleAliasDecl, NamedDecl)
  MX_SERIALIZE_ENTITY(ObjCCompatibleAliasDecl, class_interface, getVal51, setVal51, initVal51, ClassInterface, ObjCInterfaceDecl, NthDecl)
  MX_EXIT_SERIALIZE_ObjCCompatibleAliasDecl
MX_END_SERIALIZE_DECL(ObjCCompatibleAliasDecl)
#undef MX_ENTER_SERIALIZE_ObjCCompatibleAliasDecl
#undef MX_EXIT_SERIALIZE_ObjCCompatibleAliasDecl

#ifndef MX_ENTER_SERIALIZE_NamespaceDecl
#  define MX_ENTER_SERIALIZE_NamespaceDecl
#endif
#ifndef MX_EXIT_SERIALIZE_NamespaceDecl
#  define MX_EXIT_SERIALIZE_NamespaceDecl
#endif

MX_BEGIN_SERIALIZE_DECL(NamespaceDecl)
  MX_ENTER_SERIALIZE_NamespaceDecl
  MX_SERIALIZE_DECL_CONTEXT(NamespaceDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_NamespaceDecl
MX_END_SERIALIZE_DECL(NamespaceDecl)
#undef MX_ENTER_SERIALIZE_NamespaceDecl
#undef MX_EXIT_SERIALIZE_NamespaceDecl

#ifndef MX_ENTER_SERIALIZE_NamespaceAliasDecl
#  define MX_ENTER_SERIALIZE_NamespaceAliasDecl
#endif
#ifndef MX_EXIT_SERIALIZE_NamespaceAliasDecl
#  define MX_EXIT_SERIALIZE_NamespaceAliasDecl
#endif

MX_BEGIN_SERIALIZE_DECL(NamespaceAliasDecl)
  MX_ENTER_SERIALIZE_NamespaceAliasDecl
  MX_SERIALIZE_BASE(NamespaceAliasDecl, NamedDecl)
  MX_SERIALIZE_ENTITY(NamespaceAliasDecl, alias_token, getVal51, setVal51, initVal51, AliasToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(NamespaceAliasDecl, aliased_namespace, getVal52, setVal52, initVal52, AliasedNamespace, NamedDecl, NthDecl)
  MX_SERIALIZE_ENTITY(NamespaceAliasDecl, namespace_token, getVal53, setVal53, initVal53, NamespaceToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(NamespaceAliasDecl, target_name_token, getVal61, setVal61, initVal61, TargetNameToken, Token, NthDecl)
  MX_EXIT_SERIALIZE_NamespaceAliasDecl
MX_END_SERIALIZE_DECL(NamespaceAliasDecl)
#undef MX_ENTER_SERIALIZE_NamespaceAliasDecl
#undef MX_EXIT_SERIALIZE_NamespaceAliasDecl

#ifndef MX_ENTER_SERIALIZE_LinkageSpecDecl
#  define MX_ENTER_SERIALIZE_LinkageSpecDecl
#endif
#ifndef MX_EXIT_SERIALIZE_LinkageSpecDecl
#  define MX_EXIT_SERIALIZE_LinkageSpecDecl
#endif

MX_BEGIN_SERIALIZE_DECL(LinkageSpecDecl)
  MX_ENTER_SERIALIZE_LinkageSpecDecl
  MX_SERIALIZE_DECL_CONTEXT(LinkageSpecDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_LinkageSpecDecl
MX_END_SERIALIZE_DECL(LinkageSpecDecl)
#undef MX_ENTER_SERIALIZE_LinkageSpecDecl
#undef MX_EXIT_SERIALIZE_LinkageSpecDecl

#ifndef MX_ENTER_SERIALIZE_LifetimeExtendedTemporaryDecl
#  define MX_ENTER_SERIALIZE_LifetimeExtendedTemporaryDecl
#endif
#ifndef MX_EXIT_SERIALIZE_LifetimeExtendedTemporaryDecl
#  define MX_EXIT_SERIALIZE_LifetimeExtendedTemporaryDecl
#endif

MX_BEGIN_SERIALIZE_DECL(LifetimeExtendedTemporaryDecl)
  MX_ENTER_SERIALIZE_LifetimeExtendedTemporaryDecl
  MX_SERIALIZE_BASE(LifetimeExtendedTemporaryDecl, Decl)
  MX_SERIALIZE_ENTITY_LIST(LifetimeExtendedTemporaryDecl, children_expression, getVal45, setVal45, initVal45, ChildrenExpression, Stmt, NthDecl)
  MX_SERIALIZE_ENTITY(LifetimeExtendedTemporaryDecl, extending_declaration, getVal43, setVal43, initVal43, ExtendingDeclaration, ValueDecl, NthDecl)
  MX_SERIALIZE_ENUM(LifetimeExtendedTemporaryDecl, storage_duration, getVal60, setVal60, initVal60, StorageDuration, StorageDuration, NthDecl)
  MX_SERIALIZE_ENTITY(LifetimeExtendedTemporaryDecl, temporary_expression, getVal51, setVal51, initVal51, TemporaryExpression, Expr, NthDecl)
  MX_EXIT_SERIALIZE_LifetimeExtendedTemporaryDecl
MX_END_SERIALIZE_DECL(LifetimeExtendedTemporaryDecl)
#undef MX_ENTER_SERIALIZE_LifetimeExtendedTemporaryDecl
#undef MX_EXIT_SERIALIZE_LifetimeExtendedTemporaryDecl

#ifndef MX_ENTER_SERIALIZE_ImportDecl
#  define MX_ENTER_SERIALIZE_ImportDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ImportDecl
#  define MX_EXIT_SERIALIZE_ImportDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ImportDecl)
  MX_ENTER_SERIALIZE_ImportDecl
  MX_SERIALIZE_BASE(ImportDecl, Decl)
  MX_SERIALIZE_ENTITY_LIST(ImportDecl, identifier_tokens, getVal45, setVal45, initVal45, IdentifierTokens, Token, NthDecl)
  MX_EXIT_SERIALIZE_ImportDecl
MX_END_SERIALIZE_DECL(ImportDecl)
#undef MX_ENTER_SERIALIZE_ImportDecl
#undef MX_EXIT_SERIALIZE_ImportDecl

#ifndef MX_ENTER_SERIALIZE_FriendTemplateDecl
#  define MX_ENTER_SERIALIZE_FriendTemplateDecl
#endif
#ifndef MX_EXIT_SERIALIZE_FriendTemplateDecl
#  define MX_EXIT_SERIALIZE_FriendTemplateDecl
#endif

MX_BEGIN_SERIALIZE_DECL(FriendTemplateDecl)
  MX_ENTER_SERIALIZE_FriendTemplateDecl
  MX_EXIT_SERIALIZE_FriendTemplateDecl
MX_END_SERIALIZE_DECL(FriendTemplateDecl)
#undef MX_ENTER_SERIALIZE_FriendTemplateDecl
#undef MX_EXIT_SERIALIZE_FriendTemplateDecl

#ifndef MX_ENTER_SERIALIZE_FriendDecl
#  define MX_ENTER_SERIALIZE_FriendDecl
#endif
#ifndef MX_EXIT_SERIALIZE_FriendDecl
#  define MX_EXIT_SERIALIZE_FriendDecl
#endif

MX_BEGIN_SERIALIZE_DECL(FriendDecl)
  MX_ENTER_SERIALIZE_FriendDecl
  MX_SERIALIZE_BASE(FriendDecl, Decl)
  MX_SERIALIZE_OPTIONAL_ENTITY(FriendDecl, friend_declaration, getVal43, setVal43, initVal43, FriendDeclaration, NamedDecl, NthDecl)
  MX_SERIALIZE_ENTITY(FriendDecl, friend_token, getVal51, setVal51, initVal51, FriendToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(FriendDecl, friend_type, getVal52, setVal52, initVal52, FriendType, Type, NthDecl)
  MX_SERIALIZE_BOOL(FriendDecl, is_unsupported_friend, getVal47, setVal47, initVal47, IsUnsupportedFriend, bool, NthDecl)
  MX_SERIALIZE_PSEUDO_LIST(FriendDecl, friend_type_template_parameter_lists, getVal75, setVal75, initVal75, FriendTypeTemplateParameterLists, TemplateParameterList, NthDecl)
  MX_EXIT_SERIALIZE_FriendDecl
MX_END_SERIALIZE_DECL(FriendDecl)
#undef MX_ENTER_SERIALIZE_FriendDecl
#undef MX_EXIT_SERIALIZE_FriendDecl

#ifndef MX_ENTER_SERIALIZE_FileScopeAsmDecl
#  define MX_ENTER_SERIALIZE_FileScopeAsmDecl
#endif
#ifndef MX_EXIT_SERIALIZE_FileScopeAsmDecl
#  define MX_EXIT_SERIALIZE_FileScopeAsmDecl
#endif

MX_BEGIN_SERIALIZE_DECL(FileScopeAsmDecl)
  MX_ENTER_SERIALIZE_FileScopeAsmDecl
  MX_SERIALIZE_BASE(FileScopeAsmDecl, Decl)
  MX_SERIALIZE_ENTITY(FileScopeAsmDecl, assembly_token, getVal43, setVal43, initVal43, AssemblyToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(FileScopeAsmDecl, assembly_string, getVal51, setVal51, initVal51, AssemblyString, StringLiteral, NthDecl)
  MX_SERIALIZE_ENTITY(FileScopeAsmDecl, r_paren_token, getVal52, setVal52, initVal52, RParenToken, Token, NthDecl)
  MX_EXIT_SERIALIZE_FileScopeAsmDecl
MX_END_SERIALIZE_DECL(FileScopeAsmDecl)
#undef MX_ENTER_SERIALIZE_FileScopeAsmDecl
#undef MX_EXIT_SERIALIZE_FileScopeAsmDecl

#ifndef MX_ENTER_SERIALIZE_ExternCContextDecl
#  define MX_ENTER_SERIALIZE_ExternCContextDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ExternCContextDecl
#  define MX_EXIT_SERIALIZE_ExternCContextDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ExternCContextDecl)
  MX_ENTER_SERIALIZE_ExternCContextDecl
  MX_SERIALIZE_DECL_CONTEXT(ExternCContextDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_ExternCContextDecl
MX_END_SERIALIZE_DECL(ExternCContextDecl)
#undef MX_ENTER_SERIALIZE_ExternCContextDecl
#undef MX_EXIT_SERIALIZE_ExternCContextDecl

#ifndef MX_ENTER_SERIALIZE_ExportDecl
#  define MX_ENTER_SERIALIZE_ExportDecl
#endif
#ifndef MX_EXIT_SERIALIZE_ExportDecl
#  define MX_EXIT_SERIALIZE_ExportDecl
#endif

MX_BEGIN_SERIALIZE_DECL(ExportDecl)
  MX_ENTER_SERIALIZE_ExportDecl
  MX_SERIALIZE_BASE(ExportDecl, Decl)
  MX_SERIALIZE_ENTITY(ExportDecl, export_token, getVal43, setVal43, initVal43, ExportToken, Token, NthDecl)
  MX_SERIALIZE_ENTITY(ExportDecl, r_brace_token, getVal51, setVal51, initVal51, RBraceToken, Token, NthDecl)
  MX_SERIALIZE_BOOL(ExportDecl, has_braces, getVal44, setVal44, initVal44, HasBraces, bool, NthDecl)
  MX_SERIALIZE_DECL_CONTEXT(ExportDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_SERIALIZE_ExportDecl
MX_END_SERIALIZE_DECL(ExportDecl)
#undef MX_ENTER_SERIALIZE_ExportDecl
#undef MX_EXIT_SERIALIZE_ExportDecl

#ifndef MX_ENTER_SERIALIZE_EmptyDecl
#  define MX_ENTER_SERIALIZE_EmptyDecl
#endif
#ifndef MX_EXIT_SERIALIZE_EmptyDecl
#  define MX_EXIT_SERIALIZE_EmptyDecl
#endif

MX_BEGIN_SERIALIZE_DECL(EmptyDecl)
  MX_ENTER_SERIALIZE_EmptyDecl
  MX_SERIALIZE_BASE(EmptyDecl, Decl)
  MX_EXIT_SERIALIZE_EmptyDecl
MX_END_SERIALIZE_DECL(EmptyDecl)
#undef MX_ENTER_SERIALIZE_EmptyDecl
#undef MX_EXIT_SERIALIZE_EmptyDecl

#undef MX_SERIALIZE_BOOL
#undef MX_SERIALIZE_INT
#undef MX_SERIALIZE_ENUM
#undef MX_SERIALIZE_TEXT
#undef MX_SERIALIZE_PATH
#undef MX_SERIALIZE_OPTIONAL_BOOL
#undef MX_SERIALIZE_OPTIONAL_INT
#undef MX_SERIALIZE_OPTIONAL_ENUM
#undef MX_SERIALIZE_OPTIONAL_TEXT
#undef MX_SERIALIZE_OPTIONAL_PATH
#undef MX_SERIALIZE_BOOL_LIST
#undef MX_SERIALIZE_INT_LIST
#undef MX_SERIALIZE_ENUM_LIST
#undef MX_SERIALIZE_TEXT_LIST
#undef MX_SERIALIZE_PATH_LIST
#undef MX_SERIALIZE_OPTIONAL_BOOL_LIST
#undef MX_SERIALIZE_OPTIONAL_INT_LIST
#undef MX_SERIALIZE_OPTIONAL_ENUM_LIST
#undef MX_SERIALIZE_OPTIONAL_TEXT_LIST
#undef MX_SERIALIZE_OPTIONAL_PATH_LIST
#undef MX_SERIALIZE_ENTITY
#undef MX_SERIALIZE_ENTITY_LIST
#undef MX_SERIALIZE_OPTIONAL_ENTITY
#undef MX_SERIALIZE_OPTIONAL_ENTITY_LIST
#undef MX_SERIALIZE_PSEUDO
#undef MX_SERIALIZE_PSEUDO_LIST
#undef MX_SERIALIZE_OPTIONAL_PSEUDO
#undef MX_SERIALIZE_OPTIONAL_PSEUDO_LIST
#undef MX_SERIALIZE_BASE
#undef MX_SERIALIZE_DECL_LINK
#undef MX_SERIALIZE_STMT_LINK
#undef MX_BEGIN_SERIALIZE_DECL
#undef MX_BEGIN_SERIALIZE_STMT
#undef MX_BEGIN_SERIALIZE_TYPE
#undef MX_BEGIN_SERIALIZE_PSEUDO
#undef MX_SERIALIZE_PSEUDO_KIND
#undef MX_END_SERIALIZE_DECL
#undef MX_END_SERIALIZE_STMT
#undef MX_END_SERIALIZE_TYPE
#undef MX_END_SERIALIZE_PSEUDO
