// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#ifndef MX_APPLY_METHOD
#  define MX_APPLY_METHOD(obj, meth) obj.meth()
#endif
#ifndef MX_APPLY_FUNC
#  define MX_APPLY_FUNC(obj, meth) meth(obj)
#endif
#ifndef MX_VISIT_BOOL
#  define MX_VISIT_BOOL(...)
#endif
#ifndef MX_VISIT_INT
#  define MX_VISIT_INT(...)
#endif
#ifndef MX_VISIT_ENUM
#  define MX_VISIT_ENUM(...)
#endif
#ifndef MX_VISIT_TEXT
#  define MX_VISIT_TEXT(...)
#endif
#ifndef MX_VISIT_PATH
#  define MX_VISIT_PATH(...)
#endif
#ifndef MX_VISIT_OPTIONAL_BOOL
#  define MX_VISIT_OPTIONAL_BOOL(...)
#endif
#ifndef MX_VISIT_OPTIONAL_INT
#  define MX_VISIT_OPTIONAL_INT(...)
#endif
#ifndef MX_VISIT_OPTIONAL_ENUM
#  define MX_VISIT_OPTIONAL_ENUM(...)
#endif
#ifndef MX_VISIT_OPTIONAL_TEXT
#  define MX_VISIT_OPTIONAL_TEXT(...)
#endif
#ifndef MX_VISIT_OPTIONAL_PATH
#  define MX_VISIT_OPTIONAL_PATH(...)
#endif
#ifndef MX_VISIT_BOOL_LIST
#  define MX_VISIT_BOOL_LIST(...)
#endif
#ifndef MX_VISIT_INT_LIST
#  define MX_VISIT_INT_LIST(...)
#endif
#ifndef MX_VISIT_ENUM_LIST
#  define MX_VISIT_ENUM_LIST(...)
#endif
#ifndef MX_VISIT_TEXT_LIST
#  define MX_VISIT_TEXT_LIST(...)
#endif
#ifndef MX_VISIT_PATH_LIST
#  define MX_VISIT_PATH_LIST(...)
#endif
#ifndef MX_VISIT_OPTIONAL_BOOL_LIST
#  define MX_VISIT_OPTIONAL_BOOL_LIST(...)
#endif
#ifndef MX_VISIT_OPTIONAL_INT_LIST
#  define MX_VISIT_OPTIONAL_INT_LIST(...)
#endif
#ifndef MX_VISIT_OPTIONAL_ENUM_LIST
#  define MX_VISIT_OPTIONAL_ENUM_LIST(...)
#endif
#ifndef MX_VISIT_OPTIONAL_TEXT_LIST
#  define MX_VISIT_OPTIONAL_TEXT_LIST(...)
#endif
#ifndef MX_VISIT_OPTIONAL_PATH_LIST
#  define MX_VISIT_OPTIONAL_PATH_LIST(...)
#endif
#ifndef MX_VISIT_ENTITY
#  define MX_VISIT_ENTITY(...)
#endif
#ifndef MX_VISIT_OPTIONAL_ENTITY
#  define MX_VISIT_OPTIONAL_ENTITY(...)
#endif
#ifndef MX_VISIT_ENTITY_LIST
#  define MX_VISIT_ENTITY_LIST(...)
#endif
#ifndef MX_VISIT_OPTIONAL_ENTITY_LIST
#  define MX_VISIT_OPTIONAL_ENTITY_LIST(...)
#endif
#ifndef MX_VISIT_DECL_CONTEXT
#  define MX_VISIT_DECL_CONTEXT(...)
#endif
#ifndef MX_VISIT_PSEUDO
#  define MX_VISIT_PSEUDO(...)
#endif
#ifndef MX_VISIT_OPTIONAL_PSEUDO
#  define MX_VISIT_OPTIONAL_PSEUDO(...)
#endif
#ifndef MX_VISIT_OPTIONAL_PSEUDO_LIST
#  define MX_VISIT_OPTIONAL_PSEUDO_LIST(...)
#endif
#ifndef MX_VISIT_PSEUDO_LIST
#  define MX_VISIT_PSEUDO_LIST(...)
#endif
#ifndef MX_VISIT_BASE
#  define MX_VISIT_BASE(...)
#endif
#ifndef MX_VISIT_DECL_LINK
#  define MX_VISIT_DECL_LINK(...)
#endif
#ifndef MX_VISIT_STMT_LINK
#  define MX_VISIT_STMT_LINK(...)
#endif
#ifndef MX_BEGIN_VISIT_DECL
#  define MX_BEGIN_VISIT_DECL(...)
#endif
#ifndef MX_BEGIN_VISIT_STMT
#  define MX_BEGIN_VISIT_STMT(...)
#endif
#ifndef MX_BEGIN_VISIT_TYPE
#  define MX_BEGIN_VISIT_TYPE(...)
#endif
#ifndef MX_BEGIN_VISIT_ABSTRACT_DECL
#  define MX_BEGIN_VISIT_ABSTRACT_DECL MX_BEGIN_VISIT_DECL
#endif
#ifndef MX_BEGIN_VISIT_ABSTRACT_STMT
#  define MX_BEGIN_VISIT_ABSTRACT_STMT MX_BEGIN_VISIT_STMT
#endif
#ifndef MX_BEGIN_VISIT_ABSTRACT_TYPE
#  define MX_BEGIN_VISIT_ABSTRACT_TYPE MX_BEGIN_VISIT_TYPE
#endif
#ifndef MX_BEGIN_VISIT_PSEUDO
#  define MX_BEGIN_VISIT_PSEUDO(...)
#endif
#ifndef MX_END_VISIT_DECL
#  define MX_END_VISIT_DECL(...)
#endif
#ifndef MX_END_VISIT_STMT
#  define MX_END_VISIT_STMT(...)
#endif
#ifndef MX_END_VISIT_TYPE
#  define MX_END_VISIT_TYPE(...)
#endif
#ifndef MX_END_VISIT_PSEUDO
#  define MX_END_VISIT_PSEUDO(...)
#endif
#ifndef MX_VISIT_PSEUDO_KIND
#  define MX_VISIT_PSEUDO_KIND(...)
#endif

#ifndef MX_ENTER_VISIT_TemplateParameterList
#  define MX_ENTER_VISIT_TemplateParameterList
#endif
#ifndef MX_EXIT_VISIT_TemplateParameterList
#  define MX_EXIT_VISIT_TemplateParameterList
#endif

MX_BEGIN_VISIT_PSEUDO(TemplateParameterList)
  MX_ENTER_VISIT_TemplateParameterList
  MX_VISIT_PSEUDO_KIND(TemplateParameterList, 0)
  MX_VISIT_INT(TemplateParameterList, num_parameters, 1, MX_APPLY_METHOD, NumParameters, unsigned, NthPseudo)
  MX_VISIT_INT(TemplateParameterList, num_required_parameters, 2, MX_APPLY_METHOD, NumRequiredParameters, unsigned, NthPseudo)
  MX_VISIT_INT(TemplateParameterList, depth, 3, MX_APPLY_METHOD, Depth, unsigned, NthPseudo)
  MX_VISIT_BOOL(TemplateParameterList, has_unexpanded_parameter_pack, 4, MX_APPLY_METHOD, HasUnexpandedParameterPack, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateParameterList, has_parameter_pack, 5, MX_APPLY_METHOD, HasParameterPack, bool, NthPseudo)
  MX_VISIT_OPTIONAL_ENTITY(TemplateParameterList, requires_clause, 6, MX_APPLY_METHOD, RequiresClause, Expr, NthPseudo, StmtUseSelector::REQUIRES_CLAUSE)
  MX_VISIT_ENTITY(TemplateParameterList, template_keyword_token, 8, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthPseudo, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_ENTITY(TemplateParameterList, left_angle_token, 9, MX_APPLY_METHOD, LeftAngleToken, Token, NthPseudo, TokenUseSelector::LEFT_ANGLE_TOKEN)
  MX_VISIT_ENTITY(TemplateParameterList, right_angle_token, 10, MX_APPLY_METHOD, RightAngleToken, Token, NthPseudo, TokenUseSelector::RIGHT_ANGLE_TOKEN)
  MX_VISIT_ENTITY_LIST(TemplateParameterList, parameters, 13, MX_APPLY_METHOD, Parameters, NamedDecl, NthPseudo)
  MX_EXIT_VISIT_TemplateParameterList
MX_END_VISIT_PSEUDO(TemplateParameterList)

#ifndef MX_ENTER_VISIT_TemplateArgument
#  define MX_ENTER_VISIT_TemplateArgument
#endif
#ifndef MX_EXIT_VISIT_TemplateArgument
#  define MX_EXIT_VISIT_TemplateArgument
#endif

MX_BEGIN_VISIT_PSEUDO(TemplateArgument)
  MX_ENTER_VISIT_TemplateArgument
  MX_VISIT_PSEUDO_KIND(TemplateArgument, 0)
  MX_VISIT_ENUM(TemplateArgument, kind, 14, MX_APPLY_METHOD, Kind, TemplateArgumentKind, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_null, 4, MX_APPLY_METHOD, IsNull, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_dependent, 5, MX_APPLY_METHOD, IsDependent, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_instantiation_dependent, 7, MX_APPLY_METHOD, IsInstantiationDependent, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, contains_unexpanded_parameter_pack, 15, MX_APPLY_METHOD, ContainsUnexpandedParameterPack, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_pack_expansion, 16, MX_APPLY_METHOD, IsPackExpansion, bool, NthPseudo)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, as_declaration, 6, MX_APPLY_METHOD, AsDeclaration, ValueDecl, NthPseudo, DeclUseSelector::AS_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, as_type, 8, MX_APPLY_METHOD, AsType, Type, NthPseudo, TypeUseSelector::AS_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, parameter_type_for_declaration, 9, MX_APPLY_METHOD, ParameterTypeForDeclaration, Type, NthPseudo, TypeUseSelector::PARAMETER_TYPE_FOR_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, null_pointer_type, 10, MX_APPLY_METHOD, NullPointerType, Type, NthPseudo, TypeUseSelector::NULL_POINTER_TYPE)
  MX_EXIT_VISIT_TemplateArgument
MX_END_VISIT_PSEUDO(TemplateArgument)

#ifndef MX_ENTER_VISIT_CXXBaseSpecifier
#  define MX_ENTER_VISIT_CXXBaseSpecifier
#endif
#ifndef MX_EXIT_VISIT_CXXBaseSpecifier
#  define MX_EXIT_VISIT_CXXBaseSpecifier
#endif

MX_BEGIN_VISIT_PSEUDO(CXXBaseSpecifier)
  MX_ENTER_VISIT_CXXBaseSpecifier
  MX_VISIT_PSEUDO_KIND(CXXBaseSpecifier, 0)
  MX_VISIT_ENTITY(CXXBaseSpecifier, base_type_token, 9, MX_APPLY_METHOD, BaseTypeToken, Token, NthPseudo, TokenUseSelector::BASE_TYPE_TOKEN)
  MX_VISIT_BOOL(CXXBaseSpecifier, is_virtual, 4, MX_APPLY_METHOD, IsVirtual, bool, NthPseudo)
  MX_VISIT_ENUM(CXXBaseSpecifier, base_kind, 14, MX_APPLY_METHOD, BaseKind, TagTypeKind, NthPseudo)
  MX_VISIT_BOOL(CXXBaseSpecifier, is_pack_expansion, 5, MX_APPLY_METHOD, IsPackExpansion, bool, NthPseudo)
  MX_VISIT_BOOL(CXXBaseSpecifier, constructors_are_inherited, 7, MX_APPLY_METHOD, ConstructorsAreInherited, bool, NthPseudo)
  MX_VISIT_OPTIONAL_ENTITY(CXXBaseSpecifier, ellipsis_token, 10, MX_APPLY_METHOD, EllipsisToken, Token, NthPseudo, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENUM(CXXBaseSpecifier, semantic_access_specifier, 21, MX_APPLY_METHOD, SemanticAccessSpecifier, AccessSpecifier, NthPseudo)
  MX_VISIT_ENUM(CXXBaseSpecifier, lexical_access_specifier, 22, MX_APPLY_METHOD, LexicalAccessSpecifier, AccessSpecifier, NthPseudo)
  MX_VISIT_ENTITY(CXXBaseSpecifier, base_type, 11, MX_APPLY_METHOD, BaseType, Type, NthPseudo, TypeUseSelector::BASE_TYPE)
  MX_EXIT_VISIT_CXXBaseSpecifier
MX_END_VISIT_PSEUDO(CXXBaseSpecifier)

#ifndef MX_ENTER_VISIT_Type
#  define MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_Type
#  define MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(Type)
  MX_ENTER_VISIT_Type
  MX_VISIT_BOOL(Type, is_qualified, 0, MX_APPLY_METHOD, IsQualified, bool, NthType)
  MX_VISIT_ENTITY(Type, unqualified_type, 1, MX_APPLY_METHOD, UnqualifiedType, Type, NthType, TypeUseSelector::UNQUALIFIED_TYPE)
  MX_VISIT_BOOL(Type, accepts_obj_c_type_parameters, 2, MX_APPLY_METHOD, AcceptsObjCTypeParameters, bool, NthType)
  MX_VISIT_BOOL(Type, can_decay_to_pointer_type, 3, MX_APPLY_METHOD, CanDecayToPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, can_have_nullability, 4, MX_APPLY_METHOD, CanHaveNullability, bool, NthType)
  MX_VISIT_BOOL(Type, contains_errors, 5, MX_APPLY_METHOD, ContainsErrors, bool, NthType)
  MX_VISIT_BOOL(Type, contains_unexpanded_parameter_pack, 6, MX_APPLY_METHOD, ContainsUnexpandedParameterPack, bool, NthType)
  MX_VISIT_OPTIONAL_ENTITY(Type, array_element_type_no_type_qualified, 7, MX_APPLY_METHOD, ArrayElementTypeNoTypeQualified, Type, NthType, TypeUseSelector::ARRAY_ELEMENT_TYPE_NO_TYPE_QUALIFIED)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_cxx_record_declaration, 9, MX_APPLY_METHOD, AsCXXRecordDeclaration, CXXRecordDecl, NthType, DeclUseSelector::AS_CXX_RECORD_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_complex_integer_type, 11, MX_APPLY_METHOD, AsComplexIntegerType, ComplexType, NthType, TypeUseSelector::AS_COMPLEX_INTEGER_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_interface_pointer_type, 13, MX_APPLY_METHOD, AsObjCInterfacePointerType, ObjCObjectPointerType, NthType, TypeUseSelector::AS_OBJ_C_INTERFACE_POINTER_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_interface_type, 15, MX_APPLY_METHOD, AsObjCInterfaceType, ObjCObjectType, NthType, TypeUseSelector::AS_OBJ_C_INTERFACE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_qualified_class_type, 17, MX_APPLY_METHOD, AsObjCQualifiedClassType, ObjCObjectPointerType, NthType, TypeUseSelector::AS_OBJ_C_QUALIFIED_CLASS_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_qualified_id_type, 19, MX_APPLY_METHOD, AsObjCQualifiedIdType, ObjCObjectPointerType, NthType, TypeUseSelector::AS_OBJ_C_QUALIFIED_ID_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_qualified_interface_type, 21, MX_APPLY_METHOD, AsObjCQualifiedInterfaceType, ObjCObjectType, NthType, TypeUseSelector::AS_OBJ_C_QUALIFIED_INTERFACE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_placeholder_type, 23, MX_APPLY_METHOD, AsPlaceholderType, BuiltinType, NthType, TypeUseSelector::AS_PLACEHOLDER_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_record_declaration, 25, MX_APPLY_METHOD, AsRecordDeclaration, RecordDecl, NthType, DeclUseSelector::AS_RECORD_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_structure_type, 27, MX_APPLY_METHOD, AsStructureType, RecordType, NthType, TypeUseSelector::AS_STRUCTURE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_tag_declaration, 29, MX_APPLY_METHOD, AsTagDeclaration, TagDecl, NthType, DeclUseSelector::AS_TAG_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_union_type, 31, MX_APPLY_METHOD, AsUnionType, RecordType, NthType, TypeUseSelector::AS_UNION_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, contained_auto_type, 33, MX_APPLY_METHOD, ContainedAutoType, AutoType, NthType, TypeUseSelector::CONTAINED_AUTO_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, contained_deduced_type, 35, MX_APPLY_METHOD, ContainedDeducedType, DeducedType, NthType, TypeUseSelector::CONTAINED_DEDUCED_TYPE)
  MX_VISIT_ENUM(Type, linkage, 37, MX_APPLY_METHOD, Linkage, Linkage, NthType)
  MX_VISIT_ENTITY(Type, locally_unqualified_single_step_desugared_type, 38, MX_APPLY_METHOD, LocallyUnqualifiedSingleStepDesugaredType, Type, NthType, TypeUseSelector::LOCALLY_UNQUALIFIED_SINGLE_STEP_DESUGARED_TYPE)
  MX_VISIT_OPTIONAL_ENUM(Type, nullability, 39, MX_APPLY_METHOD, Nullability, NullabilityKind, NthType)
  MX_VISIT_OPTIONAL_ENTITY(Type, pointee_cxx_record_declaration, 41, MX_APPLY_METHOD, PointeeCXXRecordDeclaration, CXXRecordDecl, NthType, DeclUseSelector::POINTEE_CXX_RECORD_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, pointee_or_array_element_type, 43, MX_APPLY_METHOD, PointeeOrArrayElementType, Type, NthType, TypeUseSelector::POINTEE_OR_ARRAY_ELEMENT_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, pointee_type, 45, MX_APPLY_METHOD, PointeeType, Type, NthType, TypeUseSelector::POINTEE_TYPE)
  MX_VISIT_OPTIONAL_ENUM(Type, scalar_type_kind, 47, MX_APPLY_METHOD, ScalarTypeKind, TypeScalarTypeKind, NthType)
  MX_VISIT_OPTIONAL_ENTITY(Type, sve_element_type, 49, MX_APPLY_METHOD, SveElementType, Type, NthType, TypeUseSelector::SVE_ELEMENT_TYPE)
  MX_VISIT_ENUM(Type, kind, 51, MX_APPLY_METHOD, Kind, TypeKind, NthType)
  MX_VISIT_ENTITY(Type, unqualified_desugared_type, 52, MX_APPLY_METHOD, UnqualifiedDesugaredType, Type, NthType, TypeUseSelector::UNQUALIFIED_DESUGARED_TYPE)
  MX_VISIT_ENUM(Type, visibility, 53, MX_APPLY_METHOD, Visibility, Visibility, NthType)
  MX_VISIT_BOOL(Type, has_auto_for_trailing_return_type, 54, MX_APPLY_METHOD, HasAutoForTrailingReturnType, bool, NthType)
  MX_VISIT_BOOL(Type, has_floating_representation, 55, MX_APPLY_METHOD, HasFloatingRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_integer_representation, 56, MX_APPLY_METHOD, HasIntegerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_obj_c_pointer_representation, 57, MX_APPLY_METHOD, HasObjCPointerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_pointer_representation, 58, MX_APPLY_METHOD, HasPointerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_signed_integer_representation, 59, MX_APPLY_METHOD, HasSignedIntegerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_sized_vla_type, 60, MX_APPLY_METHOD, HasSizedVLAType, bool, NthType)
  MX_VISIT_BOOL(Type, has_unnamed_or_local_type, 61, MX_APPLY_METHOD, HasUnnamedOrLocalType, bool, NthType)
  MX_VISIT_BOOL(Type, has_unsigned_integer_representation, 62, MX_APPLY_METHOD, HasUnsignedIntegerRepresentation, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_aggregate_type, 63, MX_APPLY_METHOD, IsAggregateType, bool, NthType)
  MX_VISIT_BOOL(Type, is_align_value_t, 65, MX_APPLY_METHOD, IsAlignValueT, bool, NthType)
  MX_VISIT_BOOL(Type, is_any_character_type, 66, MX_APPLY_METHOD, IsAnyCharacterType, bool, NthType)
  MX_VISIT_BOOL(Type, is_any_complex_type, 67, MX_APPLY_METHOD, IsAnyComplexType, bool, NthType)
  MX_VISIT_BOOL(Type, is_any_pointer_type, 68, MX_APPLY_METHOD, IsAnyPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_arithmetic_type, 69, MX_APPLY_METHOD, IsArithmeticType, bool, NthType)
  MX_VISIT_BOOL(Type, is_array_type, 70, MX_APPLY_METHOD, IsArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_atomic_type, 71, MX_APPLY_METHOD, IsAtomicType, bool, NthType)
  MX_VISIT_BOOL(Type, is_b_float16_type, 72, MX_APPLY_METHOD, IsBFloat16Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_bit_int_type, 73, MX_APPLY_METHOD, IsBitIntType, bool, NthType)
  MX_VISIT_BOOL(Type, is_block_compatible_obj_c_pointer_type, 74, MX_APPLY_METHOD, IsBlockCompatibleObjCPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_block_pointer_type, 75, MX_APPLY_METHOD, IsBlockPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_boolean_type, 76, MX_APPLY_METHOD, IsBooleanType, bool, NthType)
  MX_VISIT_BOOL(Type, is_builtin_type, 77, MX_APPLY_METHOD, IsBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_carc_bridgable_type, 78, MX_APPLY_METHOD, IsCARCBridgableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cuda_device_builtin_surface_type, 79, MX_APPLY_METHOD, IsCUDADeviceBuiltinSurfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cuda_device_builtin_texture_type, 80, MX_APPLY_METHOD, IsCUDADeviceBuiltinTextureType, bool, NthType)
  MX_VISIT_BOOL(Type, is_canonical_unqualified, 81, MX_APPLY_METHOD, IsCanonicalUnqualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_char16_type, 82, MX_APPLY_METHOD, IsChar16Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_char32_type, 83, MX_APPLY_METHOD, IsChar32Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_char8_type, 84, MX_APPLY_METHOD, IsChar8Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_character_type, 85, MX_APPLY_METHOD, IsCharacterType, bool, NthType)
  MX_VISIT_BOOL(Type, is_class_type, 86, MX_APPLY_METHOD, IsClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_clk_event_t, 87, MX_APPLY_METHOD, IsClkEventT, bool, NthType)
  MX_VISIT_BOOL(Type, is_complex_integer_type, 88, MX_APPLY_METHOD, IsComplexIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_complex_type, 89, MX_APPLY_METHOD, IsComplexType, bool, NthType)
  MX_VISIT_BOOL(Type, is_compound_type, 90, MX_APPLY_METHOD, IsCompoundType, bool, NthType)
  MX_VISIT_BOOL(Type, is_constant_array_type, 91, MX_APPLY_METHOD, IsConstantArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_constant_matrix_type, 92, MX_APPLY_METHOD, IsConstantMatrixType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_constant_size_type, 93, MX_APPLY_METHOD, IsConstantSizeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_decltype_type, 95, MX_APPLY_METHOD, IsDecltypeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_dependent_address_space_type, 96, MX_APPLY_METHOD, IsDependentAddressSpaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_dependent_sized_array_type, 97, MX_APPLY_METHOD, IsDependentSizedArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_dependent_type, 98, MX_APPLY_METHOD, IsDependentType, bool, NthType)
  MX_VISIT_BOOL(Type, is_elaborated_type_specifier, 99, MX_APPLY_METHOD, IsElaboratedTypeSpecifier, bool, NthType)
  MX_VISIT_BOOL(Type, is_enumeral_type, 100, MX_APPLY_METHOD, IsEnumeralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_event_t, 101, MX_APPLY_METHOD, IsEventT, bool, NthType)
  MX_VISIT_BOOL(Type, is_ext_vector_type, 102, MX_APPLY_METHOD, IsExtVectorType, bool, NthType)
  MX_VISIT_BOOL(Type, is_fixed_point_or_integer_type, 103, MX_APPLY_METHOD, IsFixedPointOrIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_fixed_point_type, 104, MX_APPLY_METHOD, IsFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_float128_type, 105, MX_APPLY_METHOD, IsFloat128Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_float16_type, 106, MX_APPLY_METHOD, IsFloat16Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_floating_type, 107, MX_APPLY_METHOD, IsFloatingType, bool, NthType)
  MX_VISIT_BOOL(Type, is_from_ast, 108, MX_APPLY_METHOD, IsFromAST, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_no_proto_type, 109, MX_APPLY_METHOD, IsFunctionNoProtoType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_pointer_type, 110, MX_APPLY_METHOD, IsFunctionPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_proto_type, 111, MX_APPLY_METHOD, IsFunctionProtoType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_reference_type, 112, MX_APPLY_METHOD, IsFunctionReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_type, 113, MX_APPLY_METHOD, IsFunctionType, bool, NthType)
  MX_VISIT_BOOL(Type, is_fundamental_type, 114, MX_APPLY_METHOD, IsFundamentalType, bool, NthType)
  MX_VISIT_BOOL(Type, is_half_type, 115, MX_APPLY_METHOD, IsHalfType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ibm128_type, 116, MX_APPLY_METHOD, IsIbm128Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_image_type, 117, MX_APPLY_METHOD, IsImageType, bool, NthType)
  MX_VISIT_BOOL(Type, is_incomplete_array_type, 118, MX_APPLY_METHOD, IsIncompleteArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_incomplete_or_object_type, 119, MX_APPLY_METHOD, IsIncompleteOrObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_incomplete_type, 120, MX_APPLY_METHOD, IsIncompleteType, bool, NthType)
  MX_VISIT_BOOL(Type, is_instantiation_dependent_type, 121, MX_APPLY_METHOD, IsInstantiationDependentType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integer_type, 122, MX_APPLY_METHOD, IsIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integral_or_enumeration_type, 123, MX_APPLY_METHOD, IsIntegralOrEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integral_or_unscoped_enumeration_type, 124, MX_APPLY_METHOD, IsIntegralOrUnscopedEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integral_type, 125, MX_APPLY_METHOD, IsIntegralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_interface_type, 126, MX_APPLY_METHOD, IsInterfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_l_value_reference_type, 127, MX_APPLY_METHOD, IsLValueReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_linkage_valid, 128, MX_APPLY_METHOD, IsLinkageValid, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_literal_type, 129, MX_APPLY_METHOD, IsLiteralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_matrix_type, 131, MX_APPLY_METHOD, IsMatrixType, bool, NthType)
  MX_VISIT_BOOL(Type, is_member_data_pointer_type, 132, MX_APPLY_METHOD, IsMemberDataPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_member_function_pointer_type, 133, MX_APPLY_METHOD, IsMemberFunctionPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_member_pointer_type, 134, MX_APPLY_METHOD, IsMemberPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_non_overload_placeholder_type, 135, MX_APPLY_METHOD, IsNonOverloadPlaceholderType, bool, NthType)
  MX_VISIT_BOOL(Type, is_nothrow_t, 136, MX_APPLY_METHOD, IsNothrowT, bool, NthType)
  MX_VISIT_BOOL(Type, is_null_pointer_type, 137, MX_APPLY_METHOD, IsNullPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_ext_opaque_type, 138, MX_APPLY_METHOD, IsOCLExtOpaqueType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_darray_ro_type, 139, MX_APPLY_METHOD, IsOCLImage1dArrayROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_darray_rw_type, 140, MX_APPLY_METHOD, IsOCLImage1dArrayRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_darray_wo_type, 141, MX_APPLY_METHOD, IsOCLImage1dArrayWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dbuffer_ro_type, 142, MX_APPLY_METHOD, IsOCLImage1dBufferROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dbuffer_rw_type, 143, MX_APPLY_METHOD, IsOCLImage1dBufferRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dbuffer_wo_type, 144, MX_APPLY_METHOD, IsOCLImage1dBufferWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dro_type, 145, MX_APPLY_METHOD, IsOCLImage1dROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_drw_type, 146, MX_APPLY_METHOD, IsOCLImage1dRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dwo_type, 147, MX_APPLY_METHOD, IsOCLImage1dWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_depth_ro_type, 148, MX_APPLY_METHOD, IsOCLImage2dArrayDepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_depth_rw_type, 149, MX_APPLY_METHOD, IsOCLImage2dArrayDepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_depth_wo_type, 150, MX_APPLY_METHOD, IsOCLImage2dArrayDepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaa_depth_ro_type, 151, MX_APPLY_METHOD, IsOCLImage2dArrayMSAADepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaa_depth_rw_type, 152, MX_APPLY_METHOD, IsOCLImage2dArrayMSAADepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaa_depth_wo_type, 153, MX_APPLY_METHOD, IsOCLImage2dArrayMSAADepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaaro_type, 154, MX_APPLY_METHOD, IsOCLImage2dArrayMSAAROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaarw_type, 155, MX_APPLY_METHOD, IsOCLImage2dArrayMSAARWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaawo_type, 156, MX_APPLY_METHOD, IsOCLImage2dArrayMSAAWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_ro_type, 157, MX_APPLY_METHOD, IsOCLImage2dArrayROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_rw_type, 158, MX_APPLY_METHOD, IsOCLImage2dArrayRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_wo_type, 159, MX_APPLY_METHOD, IsOCLImage2dArrayWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_ddepth_ro_type, 160, MX_APPLY_METHOD, IsOCLImage2dDepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_ddepth_rw_type, 161, MX_APPLY_METHOD, IsOCLImage2dDepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_ddepth_wo_type, 162, MX_APPLY_METHOD, IsOCLImage2dDepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaa_depth_ro_type, 163, MX_APPLY_METHOD, IsOCLImage2dMSAADepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaa_depth_rw_type, 164, MX_APPLY_METHOD, IsOCLImage2dMSAADepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaa_depth_wo_type, 165, MX_APPLY_METHOD, IsOCLImage2dMSAADepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaaro_type, 166, MX_APPLY_METHOD, IsOCLImage2dMSAAROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaarw_type, 167, MX_APPLY_METHOD, IsOCLImage2dMSAARWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaawo_type, 168, MX_APPLY_METHOD, IsOCLImage2dMSAAWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dro_type, 169, MX_APPLY_METHOD, IsOCLImage2dROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_drw_type, 170, MX_APPLY_METHOD, IsOCLImage2dRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dwo_type, 171, MX_APPLY_METHOD, IsOCLImage2dWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image3_dro_type, 172, MX_APPLY_METHOD, IsOCLImage3dROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image3_drw_type, 173, MX_APPLY_METHOD, IsOCLImage3dRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image3_dwo_type, 174, MX_APPLY_METHOD, IsOCLImage3dWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type, 175, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCImeDualReferenceStreaminType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_payload_type, 176, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCImePayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type, 177, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type, 178, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_type, 179, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCImeResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type, 180, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_mce_payload_type, 181, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCMcePayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_mce_result_type, 182, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCMceResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ref_payload_type, 183, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCRefPayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ref_result_type, 184, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCRefResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_sic_payload_type, 185, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCSicPayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_sic_result_type, 186, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCSicResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_type, 187, MX_APPLY_METHOD, IsOCLIntelSubgroupAVCType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_carc_bridgable_type, 188, MX_APPLY_METHOD, IsObjCARCBridgableType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_obj_carc_implicitly_unretained_type, 189, MX_APPLY_METHOD, IsObjCARCImplicitlyUnretainedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_boxable_record_type, 191, MX_APPLY_METHOD, IsObjCBoxableRecordType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_builtin_type, 192, MX_APPLY_METHOD, IsObjCBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_class_or_class_kind_of_type, 193, MX_APPLY_METHOD, IsObjCClassOrClassKindOfType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_class_type, 194, MX_APPLY_METHOD, IsObjCClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_id_type, 195, MX_APPLY_METHOD, IsObjCIdType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_independent_class_type, 196, MX_APPLY_METHOD, IsObjCIndependentClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_indirect_lifetime_type, 197, MX_APPLY_METHOD, IsObjCIndirectLifetimeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_inert_unsafe_unretained_type, 198, MX_APPLY_METHOD, IsObjCInertUnsafeUnretainedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_lifetime_type, 199, MX_APPLY_METHOD, IsObjCLifetimeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_cns_object_type, 200, MX_APPLY_METHOD, IsObjCNSObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_object_or_interface_type, 201, MX_APPLY_METHOD, IsObjCObjectOrInterfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_object_pointer_type, 202, MX_APPLY_METHOD, IsObjCObjectPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_object_type, 203, MX_APPLY_METHOD, IsObjCObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_qualified_class_type, 204, MX_APPLY_METHOD, IsObjCQualifiedClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_qualified_id_type, 205, MX_APPLY_METHOD, IsObjCQualifiedIdType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_qualified_interface_type, 206, MX_APPLY_METHOD, IsObjCQualifiedInterfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_retainable_type, 207, MX_APPLY_METHOD, IsObjCRetainableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_sel_type, 208, MX_APPLY_METHOD, IsObjCSelType, bool, NthType)
  MX_VISIT_BOOL(Type, is_object_pointer_type, 209, MX_APPLY_METHOD, IsObjectPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_object_type, 210, MX_APPLY_METHOD, IsObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_open_cl_specific_type, 211, MX_APPLY_METHOD, IsOpenCLSpecificType, bool, NthType)
  MX_VISIT_BOOL(Type, is_overloadable_type, 212, MX_APPLY_METHOD, IsOverloadableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_pipe_type, 213, MX_APPLY_METHOD, IsPipeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_placeholder_type, 214, MX_APPLY_METHOD, IsPlaceholderType, bool, NthType)
  MX_VISIT_BOOL(Type, is_pointer_type, 215, MX_APPLY_METHOD, IsPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_promotable_integer_type, 216, MX_APPLY_METHOD, IsPromotableIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_queue_t, 217, MX_APPLY_METHOD, IsQueueT, bool, NthType)
  MX_VISIT_BOOL(Type, is_r_value_reference_type, 218, MX_APPLY_METHOD, IsRValueReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_real_floating_type, 219, MX_APPLY_METHOD, IsRealFloatingType, bool, NthType)
  MX_VISIT_BOOL(Type, is_real_type, 220, MX_APPLY_METHOD, IsRealType, bool, NthType)
  MX_VISIT_BOOL(Type, is_record_type, 221, MX_APPLY_METHOD, IsRecordType, bool, NthType)
  MX_VISIT_BOOL(Type, is_reference_type, 222, MX_APPLY_METHOD, IsReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_reserve_idt, 223, MX_APPLY_METHOD, IsReserveIDT, bool, NthType)
  MX_VISIT_BOOL(Type, is_sampler_t, 224, MX_APPLY_METHOD, IsSamplerT, bool, NthType)
  MX_VISIT_BOOL(Type, is_saturated_fixed_point_type, 225, MX_APPLY_METHOD, IsSaturatedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_scalar_type, 226, MX_APPLY_METHOD, IsScalarType, bool, NthType)
  MX_VISIT_BOOL(Type, is_scoped_enumeral_type, 227, MX_APPLY_METHOD, IsScopedEnumeralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_signed_fixed_point_type, 228, MX_APPLY_METHOD, IsSignedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_signed_integer_or_enumeration_type, 229, MX_APPLY_METHOD, IsSignedIntegerOrEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_signed_integer_type, 230, MX_APPLY_METHOD, IsSignedIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_sizeless_builtin_type, 231, MX_APPLY_METHOD, IsSizelessBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_sizeless_type, 232, MX_APPLY_METHOD, IsSizelessType, bool, NthType)
  MX_VISIT_BOOL(Type, is_specifier_type, 233, MX_APPLY_METHOD, IsSpecifierType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_standard_layout_type, 234, MX_APPLY_METHOD, IsStandardLayoutType, bool, NthType)
  MX_VISIT_BOOL(Type, is_std_byte_type, 236, MX_APPLY_METHOD, IsStdByteType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_structural_type, 237, MX_APPLY_METHOD, IsStructuralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_structure_or_class_type, 239, MX_APPLY_METHOD, IsStructureOrClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_structure_type, 240, MX_APPLY_METHOD, IsStructureType, bool, NthType)
  MX_VISIT_BOOL(Type, is_template_type_parm_type, 241, MX_APPLY_METHOD, IsTemplateTypeParmType, bool, NthType)
  MX_VISIT_BOOL(Type, is_typedef_name_type, 242, MX_APPLY_METHOD, IsTypedefNameType, bool, NthType)
  MX_VISIT_BOOL(Type, is_undeduced_auto_type, 243, MX_APPLY_METHOD, IsUndeducedAutoType, bool, NthType)
  MX_VISIT_BOOL(Type, is_undeduced_type, 244, MX_APPLY_METHOD, IsUndeducedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_union_type, 245, MX_APPLY_METHOD, IsUnionType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsaturated_fixed_point_type, 246, MX_APPLY_METHOD, IsUnsaturatedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unscoped_enumeration_type, 247, MX_APPLY_METHOD, IsUnscopedEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsigned_fixed_point_type, 248, MX_APPLY_METHOD, IsUnsignedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsigned_integer_or_enumeration_type, 249, MX_APPLY_METHOD, IsUnsignedIntegerOrEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsigned_integer_type, 250, MX_APPLY_METHOD, IsUnsignedIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_vlst_builtin_type, 251, MX_APPLY_METHOD, IsVLSTBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_variable_array_type, 252, MX_APPLY_METHOD, IsVariableArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_variably_modified_type, 253, MX_APPLY_METHOD, IsVariablyModifiedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_vector_type, 254, MX_APPLY_METHOD, IsVectorType, bool, NthType)
  MX_VISIT_BOOL(Type, is_visibility_explicit, 255, MX_APPLY_METHOD, IsVisibilityExplicit, bool, NthType)
  MX_VISIT_BOOL(Type, is_void_pointer_type, 256, MX_APPLY_METHOD, IsVoidPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_void_type, 257, MX_APPLY_METHOD, IsVoidType, bool, NthType)
  MX_VISIT_BOOL(Type, is_wide_character_type, 258, MX_APPLY_METHOD, IsWideCharacterType, bool, NthType)
  MX_VISIT_ENTITY(Type, ignore_parentheses, 259, MX_APPLY_METHOD, IgnoreParentheses, Type, NthType, TypeUseSelector::IGNORE_PARENTHESES)
  MX_VISIT_ENUM(Type, address_space, 260, MX_APPLY_METHOD, AddressSpace, LangAS, NthType)
  MX_VISIT_ENTITY(Type, atomic_unqualified_type, 261, MX_APPLY_METHOD, AtomicUnqualifiedType, Type, NthType, TypeUseSelector::ATOMIC_UNQUALIFIED_TYPE)
  MX_VISIT_ENTITY(Type, canonical_type, 262, MX_APPLY_METHOD, CanonicalType, Type, NthType, TypeUseSelector::CANONICAL_TYPE)
  MX_VISIT_ENTITY(Type, desugared_type, 263, MX_APPLY_METHOD, DesugaredType, Type, NthType, TypeUseSelector::DESUGARED_TYPE)
  MX_VISIT_ENTITY(Type, local_unqualified_type, 264, MX_APPLY_METHOD, LocalUnqualifiedType, Type, NthType, TypeUseSelector::LOCAL_UNQUALIFIED_TYPE)
  MX_VISIT_ENTITY(Type, non_l_value_expression_type, 265, MX_APPLY_METHOD, NonLValueExpressionType, Type, NthType, TypeUseSelector::NON_L_VALUE_EXPRESSION_TYPE)
  MX_VISIT_ENTITY(Type, non_pack_expansion_type, 266, MX_APPLY_METHOD, NonPackExpansionType, Type, NthType, TypeUseSelector::NON_PACK_EXPANSION_TYPE)
  MX_VISIT_ENTITY(Type, non_reference_type, 267, MX_APPLY_METHOD, NonReferenceType, Type, NthType, TypeUseSelector::NON_REFERENCE_TYPE)
  MX_VISIT_ENTITY(Type, single_step_desugared_type, 268, MX_APPLY_METHOD, SingleStepDesugaredType, Type, NthType, TypeUseSelector::SINGLE_STEP_DESUGARED_TYPE)
  MX_VISIT_BOOL(Type, has_address_space, 269, MX_APPLY_METHOD, HasAddressSpace, bool, NthType)
  MX_VISIT_BOOL(Type, has_local_non_fast_qualifiers, 270, MX_APPLY_METHOD, HasLocalNonFastQualifiers, bool, NthType)
  MX_VISIT_BOOL(Type, has_local_qualifiers, 271, MX_APPLY_METHOD, HasLocalQualifiers, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_obj_c_lifetime, 272, MX_APPLY_METHOD, HasNonTrivialObjCLifetime, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_to_primitive_copy_c_union, 273, MX_APPLY_METHOD, HasNonTrivialToPrimitiveCopyCUnion, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_to_primitive_default_initialize_c_union, 274, MX_APPLY_METHOD, HasNonTrivialToPrimitiveDefaultInitializeCUnion, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_to_primitive_destruct_c_union, 275, MX_APPLY_METHOD, HasNonTrivialToPrimitiveDestructCUnion, bool, NthType)
  MX_VISIT_BOOL(Type, has_qualifiers, 276, MX_APPLY_METHOD, HasQualifiers, bool, NthType)
  MX_VISIT_BOOL(Type, has_strong_or_weak_obj_c_lifetime, 277, MX_APPLY_METHOD, HasStrongOrWeakObjCLifetime, bool, NthType)
  MX_VISIT_BOOL(Type, is_c_forbidden_l_value_type, 278, MX_APPLY_METHOD, IsCForbiddenLValueType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cxx11_pod_type, 279, MX_APPLY_METHOD, IsCXX11PODType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cxx98_pod_type, 280, MX_APPLY_METHOD, IsCXX98PODType, bool, NthType)
  MX_VISIT_BOOL(Type, is_canonical, 281, MX_APPLY_METHOD, IsCanonical, bool, NthType)
  MX_VISIT_BOOL(Type, is_canonical_as_parameter, 282, MX_APPLY_METHOD, IsCanonicalAsParameter, bool, NthType)
  MX_VISIT_BOOL(Type, is_const_qualified, 283, MX_APPLY_METHOD, IsConstQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_constant, 284, MX_APPLY_METHOD, IsConstant, bool, NthType)
  MX_VISIT_ENUM(Type, is_destructed_type, 285, MX_APPLY_METHOD, IsDestructedType, QualTypeDestructionKind, NthType)
  MX_VISIT_BOOL(Type, is_local_const_qualified, 286, MX_APPLY_METHOD, IsLocalConstQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_local_restrict_qualified, 287, MX_APPLY_METHOD, IsLocalRestrictQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_local_volatile_qualified, 288, MX_APPLY_METHOD, IsLocalVolatileQualified, bool, NthType)
  MX_VISIT_ENUM(Type, is_non_trivial_to_primitive_copy, 289, MX_APPLY_METHOD, IsNonTrivialToPrimitiveCopy, QualTypePrimitiveCopyKind, NthType)
  MX_VISIT_ENUM(Type, is_non_trivial_to_primitive_default_initialize, 290, MX_APPLY_METHOD, IsNonTrivialToPrimitiveDefaultInitialize, QualTypePrimitiveDefaultInitializeKind, NthType)
  MX_VISIT_ENUM(Type, is_non_trivial_to_primitive_destructive_move, 291, MX_APPLY_METHOD, IsNonTrivialToPrimitiveDestructiveMove, QualTypePrimitiveCopyKind, NthType)
  MX_VISIT_BOOL(Type, is_non_weak_in_mrr_with_obj_c_weak, 292, MX_APPLY_METHOD, IsNonWeakInMRRWithObjCWeak, bool, NthType)
  MX_VISIT_BOOL(Type, is_null, 293, MX_APPLY_METHOD, IsNull, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_cgc_strong, 294, MX_APPLY_METHOD, IsObjCGCStrong, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_cgc_weak, 295, MX_APPLY_METHOD, IsObjCGCWeak, bool, NthType)
  MX_VISIT_BOOL(Type, is_pod_type, 296, MX_APPLY_METHOD, IsPODType, bool, NthType)
  MX_VISIT_BOOL(Type, is_restrict_qualified, 297, MX_APPLY_METHOD, IsRestrictQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_trivial_type, 298, MX_APPLY_METHOD, IsTrivialType, bool, NthType)
  MX_VISIT_BOOL(Type, is_trivially_copyable_type, 299, MX_APPLY_METHOD, IsTriviallyCopyableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_volatile_qualified, 300, MX_APPLY_METHOD, IsVolatileQualified, bool, NthType)
  MX_VISIT_BOOL(Type, may_be_dynamic_class, 301, MX_APPLY_METHOD, MayBeDynamicClass, bool, NthType)
  MX_VISIT_BOOL(Type, may_be_not_dynamic_class, 302, MX_APPLY_METHOD, MayBeNotDynamicClass, bool, NthType)
  MX_VISIT_ENTITY(Type, strip_obj_c_kind_of_type, 303, MX_APPLY_METHOD, StripObjCKindOfType, Type, NthType, TypeUseSelector::STRIP_OBJ_C_KIND_OF_TYPE)
  MX_VISIT_ENTITY(Type, with_const, 304, MX_APPLY_METHOD, WithConst, Type, NthType, TypeUseSelector::WITH_CONST)
  MX_VISIT_ENTITY(Type, with_restrict, 305, MX_APPLY_METHOD, WithRestrict, Type, NthType, TypeUseSelector::WITH_RESTRICT)
  MX_VISIT_ENTITY(Type, with_volatile, 306, MX_APPLY_METHOD, WithVolatile, Type, NthType, TypeUseSelector::WITH_VOLATILE)
  MX_VISIT_ENTITY(Type, without_local_fast_qualifiers, 307, MX_APPLY_METHOD, WithoutLocalFastQualifiers, Type, NthType, TypeUseSelector::WITHOUT_LOCAL_FAST_QUALIFIERS)
  MX_EXIT_VISIT_Type
MX_END_VISIT_TYPE(Type)

#ifndef MX_ENTER_VISIT_TemplateTypeParmType
#  define MX_ENTER_VISIT_TemplateTypeParmType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TemplateTypeParmType
#  define MX_EXIT_VISIT_TemplateTypeParmType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(TemplateTypeParmType)
  MX_ENTER_VISIT_TemplateTypeParmType
  MX_VISIT_BASE(TemplateTypeParmType, Type)
  MX_VISIT_ENTITY(TemplateTypeParmType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_ENTITY(TemplateTypeParmType, declaration, 309, MX_APPLY_METHOD, Declaration, TemplateTypeParmDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(TemplateTypeParmType, is_parameter_pack, 311, MX_APPLY_METHOD, IsParameterPack, bool, NthType)
  MX_VISIT_BOOL(TemplateTypeParmType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_TemplateTypeParmType
MX_END_VISIT_TYPE(TemplateTypeParmType)

#ifndef MX_ENTER_VISIT_TemplateSpecializationType
#  define MX_ENTER_VISIT_TemplateSpecializationType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TemplateSpecializationType
#  define MX_EXIT_VISIT_TemplateSpecializationType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(TemplateSpecializationType)
  MX_ENTER_VISIT_TemplateSpecializationType
  MX_VISIT_BASE(TemplateSpecializationType, Type)
  MX_VISIT_ENTITY(TemplateSpecializationType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_ENTITY(TemplateSpecializationType, aliased_type, 309, MX_APPLY_METHOD, AliasedType, Type, NthType, TypeUseSelector::ALIASED_TYPE)
  MX_VISIT_BOOL(TemplateSpecializationType, is_current_instantiation, 311, MX_APPLY_METHOD, IsCurrentInstantiation, bool, NthType)
  MX_VISIT_BOOL(TemplateSpecializationType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(TemplateSpecializationType, is_type_alias, 313, MX_APPLY_METHOD, IsTypeAlias, bool, NthType)
  MX_VISIT_PSEUDO_LIST(TemplateSpecializationType, template_arguments, 314, MX_APPLY_METHOD, TemplateArguments, TemplateArgument, NthType)
  MX_EXIT_VISIT_TemplateSpecializationType
MX_END_VISIT_TYPE(TemplateSpecializationType)

#ifndef MX_ENTER_VISIT_TagType
#  define MX_ENTER_VISIT_TagType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TagType
#  define MX_EXIT_VISIT_TagType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(TagType)
  MX_ENTER_VISIT_TagType
  MX_VISIT_BASE(TagType, Type)
  MX_VISIT_ENTITY(TagType, declaration, 308, MX_APPLY_METHOD, Declaration, TagDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(TagType, is_being_defined, 310, MX_APPLY_METHOD, IsBeingDefined, bool, NthType)
  MX_EXIT_VISIT_TagType
MX_END_VISIT_TYPE(TagType)

#ifndef MX_ENTER_VISIT_RecordType
#  define MX_ENTER_VISIT_RecordType MX_ENTER_VISIT_TagType
#endif
#ifndef MX_EXIT_VISIT_RecordType
#  define MX_EXIT_VISIT_RecordType MX_EXIT_VISIT_TagType
#endif

MX_BEGIN_VISIT_TYPE(RecordType)
  MX_ENTER_VISIT_RecordType
  MX_VISIT_BASE(RecordType, TagType)
  MX_VISIT_ENTITY(RecordType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(RecordType, has_const_fields, 311, MX_APPLY_METHOD, HasConstFields, bool, NthType)
  MX_VISIT_BOOL(RecordType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_RecordType
MX_END_VISIT_TYPE(RecordType)

#ifndef MX_ENTER_VISIT_EnumType
#  define MX_ENTER_VISIT_EnumType MX_ENTER_VISIT_TagType
#endif
#ifndef MX_EXIT_VISIT_EnumType
#  define MX_EXIT_VISIT_EnumType MX_EXIT_VISIT_TagType
#endif

MX_BEGIN_VISIT_TYPE(EnumType)
  MX_ENTER_VISIT_EnumType
  MX_VISIT_BASE(EnumType, TagType)
  MX_VISIT_ENTITY(EnumType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(EnumType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_EnumType
MX_END_VISIT_TYPE(EnumType)

#ifndef MX_ENTER_VISIT_SubstTemplateTypeParmType
#  define MX_ENTER_VISIT_SubstTemplateTypeParmType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_SubstTemplateTypeParmType
#  define MX_EXIT_VISIT_SubstTemplateTypeParmType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(SubstTemplateTypeParmType)
  MX_ENTER_VISIT_SubstTemplateTypeParmType
  MX_VISIT_BASE(SubstTemplateTypeParmType, Type)
  MX_VISIT_ENTITY(SubstTemplateTypeParmType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(SubstTemplateTypeParmType, replaced_parameter, 309, MX_APPLY_METHOD, ReplacedParameter, TemplateTypeParmType, NthType, TypeUseSelector::REPLACED_PARAMETER)
  MX_VISIT_ENTITY(SubstTemplateTypeParmType, replacement_type, 315, MX_APPLY_METHOD, ReplacementType, Type, NthType, TypeUseSelector::REPLACEMENT_TYPE)
  MX_VISIT_BOOL(SubstTemplateTypeParmType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_SubstTemplateTypeParmType
MX_END_VISIT_TYPE(SubstTemplateTypeParmType)

#ifndef MX_ENTER_VISIT_SubstTemplateTypeParmPackType
#  define MX_ENTER_VISIT_SubstTemplateTypeParmPackType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_SubstTemplateTypeParmPackType
#  define MX_EXIT_VISIT_SubstTemplateTypeParmPackType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(SubstTemplateTypeParmPackType)
  MX_ENTER_VISIT_SubstTemplateTypeParmPackType
  MX_VISIT_BASE(SubstTemplateTypeParmPackType, Type)
  MX_VISIT_ENTITY(SubstTemplateTypeParmPackType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(SubstTemplateTypeParmPackType, replaced_parameter, 309, MX_APPLY_METHOD, ReplacedParameter, TemplateTypeParmType, NthType, TypeUseSelector::REPLACED_PARAMETER)
  MX_VISIT_BOOL(SubstTemplateTypeParmPackType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_SubstTemplateTypeParmPackType
MX_END_VISIT_TYPE(SubstTemplateTypeParmPackType)

#ifndef MX_ENTER_VISIT_ReferenceType
#  define MX_ENTER_VISIT_ReferenceType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ReferenceType
#  define MX_EXIT_VISIT_ReferenceType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(ReferenceType)
  MX_ENTER_VISIT_ReferenceType
  MX_VISIT_BASE(ReferenceType, Type)
  MX_VISIT_ENTITY(ReferenceType, pointee_type_as_written, 308, MX_APPLY_METHOD, PointeeTypeAsWritten, Type, NthType, TypeUseSelector::POINTEE_TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(ReferenceType, is_inner_reference, 310, MX_APPLY_METHOD, IsInnerReference, bool, NthType)
  MX_VISIT_BOOL(ReferenceType, is_spelled_as_l_value, 311, MX_APPLY_METHOD, IsSpelledAsLValue, bool, NthType)
  MX_EXIT_VISIT_ReferenceType
MX_END_VISIT_TYPE(ReferenceType)

#ifndef MX_ENTER_VISIT_RValueReferenceType
#  define MX_ENTER_VISIT_RValueReferenceType MX_ENTER_VISIT_ReferenceType
#endif
#ifndef MX_EXIT_VISIT_RValueReferenceType
#  define MX_EXIT_VISIT_RValueReferenceType MX_EXIT_VISIT_ReferenceType
#endif

MX_BEGIN_VISIT_TYPE(RValueReferenceType)
  MX_ENTER_VISIT_RValueReferenceType
  MX_VISIT_BASE(RValueReferenceType, ReferenceType)
  MX_VISIT_ENTITY(RValueReferenceType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(RValueReferenceType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_RValueReferenceType
MX_END_VISIT_TYPE(RValueReferenceType)

#ifndef MX_ENTER_VISIT_LValueReferenceType
#  define MX_ENTER_VISIT_LValueReferenceType MX_ENTER_VISIT_ReferenceType
#endif
#ifndef MX_EXIT_VISIT_LValueReferenceType
#  define MX_EXIT_VISIT_LValueReferenceType MX_EXIT_VISIT_ReferenceType
#endif

MX_BEGIN_VISIT_TYPE(LValueReferenceType)
  MX_ENTER_VISIT_LValueReferenceType
  MX_VISIT_BASE(LValueReferenceType, ReferenceType)
  MX_VISIT_ENTITY(LValueReferenceType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(LValueReferenceType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_LValueReferenceType
MX_END_VISIT_TYPE(LValueReferenceType)

#ifndef MX_ENTER_VISIT_PointerType
#  define MX_ENTER_VISIT_PointerType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_PointerType
#  define MX_EXIT_VISIT_PointerType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(PointerType)
  MX_ENTER_VISIT_PointerType
  MX_VISIT_BASE(PointerType, Type)
  MX_VISIT_ENTITY(PointerType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(PointerType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_PointerType
MX_END_VISIT_TYPE(PointerType)

#ifndef MX_ENTER_VISIT_PipeType
#  define MX_ENTER_VISIT_PipeType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_PipeType
#  define MX_EXIT_VISIT_PipeType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(PipeType)
  MX_ENTER_VISIT_PipeType
  MX_VISIT_BASE(PipeType, Type)
  MX_VISIT_ENTITY(PipeType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(PipeType, element_type, 309, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_BOOL(PipeType, is_read_only, 310, MX_APPLY_METHOD, IsReadOnly, bool, NthType)
  MX_VISIT_BOOL(PipeType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_PipeType
MX_END_VISIT_TYPE(PipeType)

#ifndef MX_ENTER_VISIT_ParenType
#  define MX_ENTER_VISIT_ParenType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ParenType
#  define MX_EXIT_VISIT_ParenType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(ParenType)
  MX_ENTER_VISIT_ParenType
  MX_VISIT_BASE(ParenType, Type)
  MX_VISIT_ENTITY(ParenType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ParenType, inner_type, 309, MX_APPLY_METHOD, InnerType, Type, NthType, TypeUseSelector::INNER_TYPE)
  MX_VISIT_BOOL(ParenType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_ParenType
MX_END_VISIT_TYPE(ParenType)

#ifndef MX_ENTER_VISIT_PackExpansionType
#  define MX_ENTER_VISIT_PackExpansionType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_PackExpansionType
#  define MX_EXIT_VISIT_PackExpansionType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(PackExpansionType)
  MX_ENTER_VISIT_PackExpansionType
  MX_VISIT_BASE(PackExpansionType, Type)
  MX_VISIT_ENTITY(PackExpansionType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_INT(PackExpansionType, num_expansions, 316, MX_APPLY_METHOD, NumExpansions, unsigned, NthType)
  MX_VISIT_ENTITY(PackExpansionType, pattern, 309, MX_APPLY_METHOD, Pattern, Type, NthType, TypeUseSelector::PATTERN)
  MX_VISIT_BOOL(PackExpansionType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_PackExpansionType
MX_END_VISIT_TYPE(PackExpansionType)

#ifndef MX_ENTER_VISIT_ObjCTypeParamType
#  define MX_ENTER_VISIT_ObjCTypeParamType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ObjCTypeParamType
#  define MX_EXIT_VISIT_ObjCTypeParamType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(ObjCTypeParamType)
  MX_ENTER_VISIT_ObjCTypeParamType
  MX_VISIT_BASE(ObjCTypeParamType, Type)
  MX_VISIT_ENTITY(ObjCTypeParamType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ObjCTypeParamType, declaration, 309, MX_APPLY_METHOD, Declaration, ObjCTypeParamDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(ObjCTypeParamType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_ObjCTypeParamType
MX_END_VISIT_TYPE(ObjCTypeParamType)

#ifndef MX_ENTER_VISIT_ObjCObjectType
#  define MX_ENTER_VISIT_ObjCObjectType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ObjCObjectType
#  define MX_EXIT_VISIT_ObjCObjectType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(ObjCObjectType)
  MX_ENTER_VISIT_ObjCObjectType
  MX_VISIT_BASE(ObjCObjectType, Type)
  MX_VISIT_ENTITY(ObjCObjectType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ObjCObjectType, base_type, 309, MX_APPLY_METHOD, BaseType, Type, NthType, TypeUseSelector::BASE_TYPE)
  MX_VISIT_ENTITY(ObjCObjectType, interface, 315, MX_APPLY_METHOD, Interface, ObjCInterfaceDecl, NthType, DeclUseSelector::INTERFACE)
  MX_VISIT_OPTIONAL_ENTITY(ObjCObjectType, super_class_type, 317, MX_APPLY_METHOD, SuperClassType, Type, NthType, TypeUseSelector::SUPER_CLASS_TYPE)
  MX_VISIT_ENTITY_LIST(ObjCObjectType, type_arguments, 318, MX_APPLY_METHOD, TypeArguments, Type, NthType)
  MX_VISIT_ENTITY_LIST(ObjCObjectType, type_arguments_as_written, 319, MX_APPLY_METHOD, TypeArgumentsAsWritten, Type, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_kind_of_type, 311, MX_APPLY_METHOD, IsKindOfType, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_kind_of_type_as_written, 312, MX_APPLY_METHOD, IsKindOfTypeAsWritten, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_class, 313, MX_APPLY_METHOD, IsObjCClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_id, 320, MX_APPLY_METHOD, IsObjCId, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_qualified_class, 321, MX_APPLY_METHOD, IsObjCQualifiedClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_qualified_id, 322, MX_APPLY_METHOD, IsObjCQualifiedId, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_unqualified_class, 323, MX_APPLY_METHOD, IsObjCUnqualifiedClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_unqualified_id, 324, MX_APPLY_METHOD, IsObjCUnqualifiedId, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_unqualified_id_or_class, 325, MX_APPLY_METHOD, IsObjCUnqualifiedIdOrClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_specialized, 326, MX_APPLY_METHOD, IsSpecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_specialized_as_written, 327, MX_APPLY_METHOD, IsSpecializedAsWritten, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_sugared, 328, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_unspecialized, 329, MX_APPLY_METHOD, IsUnspecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_unspecialized_as_written, 330, MX_APPLY_METHOD, IsUnspecializedAsWritten, bool, NthType)
  MX_VISIT_ENTITY(ObjCObjectType, strip_obj_c_kind_of_type_and_qualifieds, 331, MX_APPLY_METHOD, StripObjCKindOfTypeAndQualifieds, Type, NthType, TypeUseSelector::STRIP_OBJ_C_KIND_OF_TYPE_AND_QUALIFIEDS)
  MX_EXIT_VISIT_ObjCObjectType
MX_END_VISIT_TYPE(ObjCObjectType)

#ifndef MX_ENTER_VISIT_ObjCInterfaceType
#  define MX_ENTER_VISIT_ObjCInterfaceType MX_ENTER_VISIT_ObjCObjectType
#endif
#ifndef MX_EXIT_VISIT_ObjCInterfaceType
#  define MX_EXIT_VISIT_ObjCInterfaceType MX_EXIT_VISIT_ObjCObjectType
#endif

MX_BEGIN_VISIT_TYPE(ObjCInterfaceType)
  MX_ENTER_VISIT_ObjCInterfaceType
  MX_VISIT_BASE(ObjCInterfaceType, ObjCObjectType)
  MX_VISIT_ENTITY(ObjCInterfaceType, declaration, 332, MX_APPLY_METHOD, Declaration, ObjCInterfaceDecl, NthType, DeclUseSelector::DECLARATION)
  MX_EXIT_VISIT_ObjCInterfaceType
MX_END_VISIT_TYPE(ObjCInterfaceType)

#ifndef MX_ENTER_VISIT_ObjCObjectPointerType
#  define MX_ENTER_VISIT_ObjCObjectPointerType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ObjCObjectPointerType
#  define MX_EXIT_VISIT_ObjCObjectPointerType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(ObjCObjectPointerType)
  MX_ENTER_VISIT_ObjCObjectPointerType
  MX_VISIT_BASE(ObjCObjectPointerType, Type)
  MX_VISIT_ENTITY(ObjCObjectPointerType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ObjCObjectPointerType, interface_declaration, 309, MX_APPLY_METHOD, InterfaceDeclaration, ObjCInterfaceDecl, NthType, DeclUseSelector::INTERFACE_DECLARATION)
  MX_VISIT_ENTITY(ObjCObjectPointerType, interface_type, 315, MX_APPLY_METHOD, InterfaceType, ObjCInterfaceType, NthType, TypeUseSelector::INTERFACE_TYPE)
  MX_VISIT_ENTITY(ObjCObjectPointerType, object_type, 317, MX_APPLY_METHOD, ObjectType, ObjCObjectType, NthType, TypeUseSelector::OBJECT_TYPE)
  MX_VISIT_ENTITY(ObjCObjectPointerType, super_class_type, 331, MX_APPLY_METHOD, SuperClassType, Type, NthType, TypeUseSelector::SUPER_CLASS_TYPE)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, type_arguments, 318, MX_APPLY_METHOD, TypeArguments, Type, NthType)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, type_arguments_as_written, 319, MX_APPLY_METHOD, TypeArgumentsAsWritten, Type, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_kind_of_type, 310, MX_APPLY_METHOD, IsKindOfType, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_obj_c_id_or_class_type, 311, MX_APPLY_METHOD, IsObjCIdOrClassType, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_specialized, 312, MX_APPLY_METHOD, IsSpecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_specialized_as_written, 313, MX_APPLY_METHOD, IsSpecializedAsWritten, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_sugared, 320, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_unspecialized, 321, MX_APPLY_METHOD, IsUnspecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_unspecialized_as_written, 322, MX_APPLY_METHOD, IsUnspecializedAsWritten, bool, NthType)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, qualifieds, 333, MX_APPLY_METHOD, Qualifieds, ObjCProtocolDecl, NthType)
  MX_VISIT_ENTITY(ObjCObjectPointerType, strip_obj_c_kind_of_type_and_qualifieds, 332, MX_APPLY_METHOD, StripObjCKindOfTypeAndQualifieds, ObjCObjectPointerType, NthType, TypeUseSelector::STRIP_OBJ_C_KIND_OF_TYPE_AND_QUALIFIEDS)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, protocols, 334, MX_APPLY_METHOD, Protocols, ObjCProtocolDecl, NthType)
  MX_EXIT_VISIT_ObjCObjectPointerType
MX_END_VISIT_TYPE(ObjCObjectPointerType)

#ifndef MX_ENTER_VISIT_MemberPointerType
#  define MX_ENTER_VISIT_MemberPointerType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_MemberPointerType
#  define MX_EXIT_VISIT_MemberPointerType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(MemberPointerType)
  MX_ENTER_VISIT_MemberPointerType
  MX_VISIT_BASE(MemberPointerType, Type)
  MX_VISIT_ENTITY(MemberPointerType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(MemberPointerType, class_, 309, MX_APPLY_METHOD, Class, Type, NthType, TypeUseSelector::CLASS_)
  MX_VISIT_ENTITY(MemberPointerType, most_recent_cxx_record_declaration, 315, MX_APPLY_METHOD, MostRecentCXXRecordDeclaration, CXXRecordDecl, NthType, DeclUseSelector::MOST_RECENT_CXX_RECORD_DECLARATION)
  MX_VISIT_BOOL(MemberPointerType, is_member_data_pointer, 310, MX_APPLY_METHOD, IsMemberDataPointer, bool, NthType)
  MX_VISIT_BOOL(MemberPointerType, is_member_function_pointer, 311, MX_APPLY_METHOD, IsMemberFunctionPointer, bool, NthType)
  MX_VISIT_BOOL(MemberPointerType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_MemberPointerType
MX_END_VISIT_TYPE(MemberPointerType)

#ifndef MX_ENTER_VISIT_MatrixType
#  define MX_ENTER_VISIT_MatrixType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_MatrixType
#  define MX_EXIT_VISIT_MatrixType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(MatrixType)
  MX_ENTER_VISIT_MatrixType
  MX_VISIT_BASE(MatrixType, Type)
  MX_VISIT_ENTITY(MatrixType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(MatrixType, element_type, 309, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_BOOL(MatrixType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_MatrixType
MX_END_VISIT_TYPE(MatrixType)

#ifndef MX_ENTER_VISIT_DependentSizedMatrixType
#  define MX_ENTER_VISIT_DependentSizedMatrixType MX_ENTER_VISIT_MatrixType
#endif
#ifndef MX_EXIT_VISIT_DependentSizedMatrixType
#  define MX_EXIT_VISIT_DependentSizedMatrixType MX_EXIT_VISIT_MatrixType
#endif

MX_BEGIN_VISIT_TYPE(DependentSizedMatrixType)
  MX_ENTER_VISIT_DependentSizedMatrixType
  MX_VISIT_BASE(DependentSizedMatrixType, MatrixType)
  MX_VISIT_ENTITY(DependentSizedMatrixType, attribute_token, 315, MX_APPLY_METHOD, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(DependentSizedMatrixType, column_expression, 317, MX_APPLY_METHOD, ColumnExpression, Expr, NthType, StmtUseSelector::COLUMN_EXPRESSION)
  MX_VISIT_ENTITY(DependentSizedMatrixType, row_expression, 331, MX_APPLY_METHOD, RowExpression, Expr, NthType, StmtUseSelector::ROW_EXPRESSION)
  MX_EXIT_VISIT_DependentSizedMatrixType
MX_END_VISIT_TYPE(DependentSizedMatrixType)

#ifndef MX_ENTER_VISIT_ConstantMatrixType
#  define MX_ENTER_VISIT_ConstantMatrixType MX_ENTER_VISIT_MatrixType
#endif
#ifndef MX_EXIT_VISIT_ConstantMatrixType
#  define MX_EXIT_VISIT_ConstantMatrixType MX_EXIT_VISIT_MatrixType
#endif

MX_BEGIN_VISIT_TYPE(ConstantMatrixType)
  MX_ENTER_VISIT_ConstantMatrixType
  MX_VISIT_BASE(ConstantMatrixType, MatrixType)
  MX_EXIT_VISIT_ConstantMatrixType
MX_END_VISIT_TYPE(ConstantMatrixType)

#ifndef MX_ENTER_VISIT_MacroQualifiedType
#  define MX_ENTER_VISIT_MacroQualifiedType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_MacroQualifiedType
#  define MX_EXIT_VISIT_MacroQualifiedType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(MacroQualifiedType)
  MX_ENTER_VISIT_MacroQualifiedType
  MX_VISIT_BASE(MacroQualifiedType, Type)
  MX_VISIT_ENTITY(MacroQualifiedType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(MacroQualifiedType, modified_type, 309, MX_APPLY_METHOD, ModifiedType, Type, NthType, TypeUseSelector::MODIFIED_TYPE)
  MX_VISIT_ENTITY(MacroQualifiedType, underlying_type, 315, MX_APPLY_METHOD, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(MacroQualifiedType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_MacroQualifiedType
MX_END_VISIT_TYPE(MacroQualifiedType)

#ifndef MX_ENTER_VISIT_InjectedClassNameType
#  define MX_ENTER_VISIT_InjectedClassNameType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_InjectedClassNameType
#  define MX_EXIT_VISIT_InjectedClassNameType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(InjectedClassNameType)
  MX_ENTER_VISIT_InjectedClassNameType
  MX_VISIT_BASE(InjectedClassNameType, Type)
  MX_VISIT_ENTITY(InjectedClassNameType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(InjectedClassNameType, declaration, 309, MX_APPLY_METHOD, Declaration, CXXRecordDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(InjectedClassNameType, injected_specialization_type, 315, MX_APPLY_METHOD, InjectedSpecializationType, Type, NthType, TypeUseSelector::INJECTED_SPECIALIZATION_TYPE)
  MX_VISIT_ENTITY(InjectedClassNameType, injected_tst, 317, MX_APPLY_METHOD, InjectedTST, TemplateSpecializationType, NthType, TypeUseSelector::INJECTED_TST)
  MX_VISIT_BOOL(InjectedClassNameType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_InjectedClassNameType
MX_END_VISIT_TYPE(InjectedClassNameType)

#ifndef MX_ENTER_VISIT_FunctionType
#  define MX_ENTER_VISIT_FunctionType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_FunctionType
#  define MX_EXIT_VISIT_FunctionType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(FunctionType)
  MX_ENTER_VISIT_FunctionType
  MX_VISIT_BASE(FunctionType, Type)
  MX_VISIT_ENUM(FunctionType, call_conv, 335, MX_APPLY_METHOD, CallConv, CallingConv, NthType)
  MX_VISIT_ENTITY(FunctionType, call_result_type, 308, MX_APPLY_METHOD, CallResultType, Type, NthType, TypeUseSelector::CALL_RESULT_TYPE)
  MX_VISIT_BOOL(FunctionType, cmse_ns_call_attribute, 310, MX_APPLY_METHOD, CmseNSCallAttribute, bool, NthType)
  MX_VISIT_BOOL(FunctionType, has_reg_parm, 311, MX_APPLY_METHOD, HasRegParm, bool, NthType)
  MX_VISIT_BOOL(FunctionType, no_return_attribute, 312, MX_APPLY_METHOD, NoReturnAttribute, bool, NthType)
  MX_VISIT_ENTITY(FunctionType, return_type, 309, MX_APPLY_METHOD, ReturnType, Type, NthType, TypeUseSelector::RETURN_TYPE)
  MX_VISIT_BOOL(FunctionType, is_const, 313, MX_APPLY_METHOD, IsConst, bool, NthType)
  MX_VISIT_BOOL(FunctionType, is_restrict, 320, MX_APPLY_METHOD, IsRestrict, bool, NthType)
  MX_VISIT_BOOL(FunctionType, is_volatile, 321, MX_APPLY_METHOD, IsVolatile, bool, NthType)
  MX_EXIT_VISIT_FunctionType
MX_END_VISIT_TYPE(FunctionType)

#ifndef MX_ENTER_VISIT_FunctionProtoType
#  define MX_ENTER_VISIT_FunctionProtoType MX_ENTER_VISIT_FunctionType
#endif
#ifndef MX_EXIT_VISIT_FunctionProtoType
#  define MX_EXIT_VISIT_FunctionProtoType MX_EXIT_VISIT_FunctionType
#endif

MX_BEGIN_VISIT_TYPE(FunctionProtoType)
  MX_ENTER_VISIT_FunctionProtoType
  MX_VISIT_BASE(FunctionProtoType, FunctionType)
  MX_VISIT_OPTIONAL_ENUM(FunctionProtoType, can_throw, 336, MX_APPLY_METHOD, CanThrow, CanThrowResult, NthType)
  MX_VISIT_ENTITY(FunctionProtoType, desugar, 315, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY_LIST(FunctionProtoType, exceptions, 318, MX_APPLY_METHOD, Exceptions, Type, NthType)
  MX_VISIT_ENTITY(FunctionProtoType, ellipsis_token, 317, MX_APPLY_METHOD, EllipsisToken, Token, NthType, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(FunctionProtoType, exception_spec_declaration, 331, MX_APPLY_METHOD, ExceptionSpecDeclaration, FunctionDecl, NthType, DeclUseSelector::EXCEPTION_SPEC_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(FunctionProtoType, exception_spec_template, 332, MX_APPLY_METHOD, ExceptionSpecTemplate, FunctionDecl, NthType, DeclUseSelector::EXCEPTION_SPEC_TEMPLATE)
  MX_VISIT_ENUM(FunctionProtoType, exception_spec_type, 337, MX_APPLY_METHOD, ExceptionSpecType, ExceptionSpecificationType, NthType)
  MX_VISIT_OPTIONAL_ENTITY(FunctionProtoType, noexcept_expression, 338, MX_APPLY_METHOD, NoexceptExpression, Expr, NthType, StmtUseSelector::NOEXCEPT_EXPRESSION)
  MX_VISIT_ENTITY_LIST(FunctionProtoType, parameter_types, 319, MX_APPLY_METHOD, ParameterTypes, Type, NthType)
  MX_VISIT_ENUM(FunctionProtoType, reference_qualifier, 339, MX_APPLY_METHOD, ReferenceQualifier, RefQualifierKind, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_dependent_exception_spec, 326, MX_APPLY_METHOD, HasDependentExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_dynamic_exception_spec, 327, MX_APPLY_METHOD, HasDynamicExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_exception_spec, 328, MX_APPLY_METHOD, HasExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_ext_parameter_infos, 329, MX_APPLY_METHOD, HasExtParameterInfos, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_instantiation_dependent_exception_spec, 330, MX_APPLY_METHOD, HasInstantiationDependentExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_noexcept_exception_spec, 340, MX_APPLY_METHOD, HasNoexceptExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_trailing_return, 341, MX_APPLY_METHOD, HasTrailingReturn, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(FunctionProtoType, is_nothrow, 342, MX_APPLY_METHOD, IsNothrow, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_sugared, 344, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_template_variadic, 345, MX_APPLY_METHOD, IsTemplateVariadic, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_variadic, 346, MX_APPLY_METHOD, IsVariadic, bool, NthType)
  MX_VISIT_ENTITY_LIST(FunctionProtoType, exception_types, 333, MX_APPLY_METHOD, ExceptionTypes, Type, NthType)
  MX_EXIT_VISIT_FunctionProtoType
MX_END_VISIT_TYPE(FunctionProtoType)

#ifndef MX_ENTER_VISIT_FunctionNoProtoType
#  define MX_ENTER_VISIT_FunctionNoProtoType MX_ENTER_VISIT_FunctionType
#endif
#ifndef MX_EXIT_VISIT_FunctionNoProtoType
#  define MX_EXIT_VISIT_FunctionNoProtoType MX_EXIT_VISIT_FunctionType
#endif

MX_BEGIN_VISIT_TYPE(FunctionNoProtoType)
  MX_ENTER_VISIT_FunctionNoProtoType
  MX_VISIT_BASE(FunctionNoProtoType, FunctionType)
  MX_VISIT_ENTITY(FunctionNoProtoType, desugar, 315, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(FunctionNoProtoType, is_sugared, 322, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_FunctionNoProtoType
MX_END_VISIT_TYPE(FunctionNoProtoType)

#ifndef MX_ENTER_VISIT_DependentVectorType
#  define MX_ENTER_VISIT_DependentVectorType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentVectorType
#  define MX_EXIT_VISIT_DependentVectorType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentVectorType)
  MX_ENTER_VISIT_DependentVectorType
  MX_VISIT_BASE(DependentVectorType, Type)
  MX_VISIT_ENTITY(DependentVectorType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentVectorType, attribute_token, 309, MX_APPLY_METHOD, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(DependentVectorType, element_type, 315, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENTITY(DependentVectorType, size_expression, 317, MX_APPLY_METHOD, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_ENUM(DependentVectorType, vector_kind, 335, MX_APPLY_METHOD, VectorKind, VectorTypeVectorKind, NthType)
  MX_VISIT_BOOL(DependentVectorType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DependentVectorType
MX_END_VISIT_TYPE(DependentVectorType)

#ifndef MX_ENTER_VISIT_DependentSizedExtVectorType
#  define MX_ENTER_VISIT_DependentSizedExtVectorType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentSizedExtVectorType
#  define MX_EXIT_VISIT_DependentSizedExtVectorType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentSizedExtVectorType)
  MX_ENTER_VISIT_DependentSizedExtVectorType
  MX_VISIT_BASE(DependentSizedExtVectorType, Type)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, attribute_token, 309, MX_APPLY_METHOD, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, element_type, 315, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, size_expression, 317, MX_APPLY_METHOD, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(DependentSizedExtVectorType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DependentSizedExtVectorType
MX_END_VISIT_TYPE(DependentSizedExtVectorType)

#ifndef MX_ENTER_VISIT_DependentBitIntType
#  define MX_ENTER_VISIT_DependentBitIntType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentBitIntType
#  define MX_EXIT_VISIT_DependentBitIntType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentBitIntType)
  MX_ENTER_VISIT_DependentBitIntType
  MX_VISIT_BASE(DependentBitIntType, Type)
  MX_VISIT_ENTITY(DependentBitIntType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentBitIntType, num_bits_expression, 309, MX_APPLY_METHOD, NumBitsExpression, Expr, NthType, StmtUseSelector::NUM_BITS_EXPRESSION)
  MX_VISIT_BOOL(DependentBitIntType, is_signed, 310, MX_APPLY_METHOD, IsSigned, bool, NthType)
  MX_VISIT_BOOL(DependentBitIntType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(DependentBitIntType, is_unsigned, 312, MX_APPLY_METHOD, IsUnsigned, bool, NthType)
  MX_EXIT_VISIT_DependentBitIntType
MX_END_VISIT_TYPE(DependentBitIntType)

#ifndef MX_ENTER_VISIT_DependentAddressSpaceType
#  define MX_ENTER_VISIT_DependentAddressSpaceType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentAddressSpaceType
#  define MX_EXIT_VISIT_DependentAddressSpaceType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentAddressSpaceType)
  MX_ENTER_VISIT_DependentAddressSpaceType
  MX_VISIT_BASE(DependentAddressSpaceType, Type)
  MX_VISIT_ENTITY(DependentAddressSpaceType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentAddressSpaceType, addr_space_expression, 309, MX_APPLY_METHOD, AddrSpaceExpression, Expr, NthType, StmtUseSelector::ADDR_SPACE_EXPRESSION)
  MX_VISIT_ENTITY(DependentAddressSpaceType, attribute_token, 315, MX_APPLY_METHOD, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_BOOL(DependentAddressSpaceType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DependentAddressSpaceType
MX_END_VISIT_TYPE(DependentAddressSpaceType)

#ifndef MX_ENTER_VISIT_DeducedType
#  define MX_ENTER_VISIT_DeducedType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DeducedType
#  define MX_EXIT_VISIT_DeducedType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(DeducedType)
  MX_ENTER_VISIT_DeducedType
  MX_VISIT_BASE(DeducedType, Type)
  MX_VISIT_ENTITY(DeducedType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_ENTITY(DeducedType, resolved_type, 309, MX_APPLY_METHOD, ResolvedType, Type, NthType, TypeUseSelector::RESOLVED_TYPE)
  MX_VISIT_BOOL(DeducedType, is_deduced, 311, MX_APPLY_METHOD, IsDeduced, bool, NthType)
  MX_VISIT_BOOL(DeducedType, is_sugared, 312, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DeducedType
MX_END_VISIT_TYPE(DeducedType)

#ifndef MX_ENTER_VISIT_DeducedTemplateSpecializationType
#  define MX_ENTER_VISIT_DeducedTemplateSpecializationType MX_ENTER_VISIT_DeducedType
#endif
#ifndef MX_EXIT_VISIT_DeducedTemplateSpecializationType
#  define MX_EXIT_VISIT_DeducedTemplateSpecializationType MX_EXIT_VISIT_DeducedType
#endif

MX_BEGIN_VISIT_TYPE(DeducedTemplateSpecializationType)
  MX_ENTER_VISIT_DeducedTemplateSpecializationType
  MX_VISIT_BASE(DeducedTemplateSpecializationType, DeducedType)
  MX_EXIT_VISIT_DeducedTemplateSpecializationType
MX_END_VISIT_TYPE(DeducedTemplateSpecializationType)

#ifndef MX_ENTER_VISIT_AutoType
#  define MX_ENTER_VISIT_AutoType MX_ENTER_VISIT_DeducedType
#endif
#ifndef MX_EXIT_VISIT_AutoType
#  define MX_EXIT_VISIT_AutoType MX_EXIT_VISIT_DeducedType
#endif

MX_BEGIN_VISIT_TYPE(AutoType)
  MX_ENTER_VISIT_AutoType
  MX_VISIT_BASE(AutoType, DeducedType)
  MX_VISIT_ENUM(AutoType, keyword, 335, MX_APPLY_METHOD, Keyword, AutoTypeKeyword, NthType)
  MX_VISIT_PSEUDO_LIST(AutoType, type_constraint_arguments, 314, MX_APPLY_METHOD, TypeConstraintArguments, TemplateArgument, NthType)
  MX_VISIT_OPTIONAL_ENTITY(AutoType, type_constraint_concept, 315, MX_APPLY_METHOD, TypeConstraintConcept, ConceptDecl, NthType, DeclUseSelector::TYPE_CONSTRAINT_CONCEPT)
  MX_VISIT_BOOL(AutoType, is_constrained, 320, MX_APPLY_METHOD, IsConstrained, bool, NthType)
  MX_VISIT_BOOL(AutoType, is_decltype_auto, 321, MX_APPLY_METHOD, IsDecltypeAuto, bool, NthType)
  MX_EXIT_VISIT_AutoType
MX_END_VISIT_TYPE(AutoType)

#ifndef MX_ENTER_VISIT_DecltypeType
#  define MX_ENTER_VISIT_DecltypeType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DecltypeType
#  define MX_EXIT_VISIT_DecltypeType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DecltypeType)
  MX_ENTER_VISIT_DecltypeType
  MX_VISIT_BASE(DecltypeType, Type)
  MX_VISIT_ENTITY(DecltypeType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DecltypeType, underlying_expression, 309, MX_APPLY_METHOD, UnderlyingExpression, Expr, NthType, StmtUseSelector::UNDERLYING_EXPRESSION)
  MX_VISIT_ENTITY(DecltypeType, underlying_type, 315, MX_APPLY_METHOD, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(DecltypeType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DecltypeType
MX_END_VISIT_TYPE(DecltypeType)

#ifndef MX_ENTER_VISIT_ComplexType
#  define MX_ENTER_VISIT_ComplexType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ComplexType
#  define MX_EXIT_VISIT_ComplexType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(ComplexType)
  MX_ENTER_VISIT_ComplexType
  MX_VISIT_BASE(ComplexType, Type)
  MX_VISIT_ENTITY(ComplexType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ComplexType, element_type, 309, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_BOOL(ComplexType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_ComplexType
MX_END_VISIT_TYPE(ComplexType)

#ifndef MX_ENTER_VISIT_BuiltinType
#  define MX_ENTER_VISIT_BuiltinType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_BuiltinType
#  define MX_EXIT_VISIT_BuiltinType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(BuiltinType)
  MX_ENTER_VISIT_BuiltinType
  MX_VISIT_BASE(BuiltinType, Type)
  MX_VISIT_ENTITY(BuiltinType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENUM(BuiltinType, builtin_kind, 335, MX_APPLY_METHOD, Kind, BuiltinTypeKind, NthType)
  MX_VISIT_BOOL(BuiltinType, is_floating_point, 310, MX_APPLY_METHOD, IsFloatingPoint, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_integer, 311, MX_APPLY_METHOD, IsInteger, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_signed_integer, 312, MX_APPLY_METHOD, IsSignedInteger, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_sugared, 313, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_unsigned_integer, 320, MX_APPLY_METHOD, IsUnsignedInteger, bool, NthType)
  MX_EXIT_VISIT_BuiltinType
MX_END_VISIT_TYPE(BuiltinType)

#ifndef MX_ENTER_VISIT_BlockPointerType
#  define MX_ENTER_VISIT_BlockPointerType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_BlockPointerType
#  define MX_EXIT_VISIT_BlockPointerType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(BlockPointerType)
  MX_ENTER_VISIT_BlockPointerType
  MX_VISIT_BASE(BlockPointerType, Type)
  MX_VISIT_ENTITY(BlockPointerType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(BlockPointerType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_BlockPointerType
MX_END_VISIT_TYPE(BlockPointerType)

#ifndef MX_ENTER_VISIT_BitIntType
#  define MX_ENTER_VISIT_BitIntType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_BitIntType
#  define MX_EXIT_VISIT_BitIntType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(BitIntType)
  MX_ENTER_VISIT_BitIntType
  MX_VISIT_BASE(BitIntType, Type)
  MX_VISIT_ENTITY(BitIntType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(BitIntType, is_signed, 310, MX_APPLY_METHOD, IsSigned, bool, NthType)
  MX_VISIT_BOOL(BitIntType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_BOOL(BitIntType, is_unsigned, 312, MX_APPLY_METHOD, IsUnsigned, bool, NthType)
  MX_EXIT_VISIT_BitIntType
MX_END_VISIT_TYPE(BitIntType)

#ifndef MX_ENTER_VISIT_AttributedType
#  define MX_ENTER_VISIT_AttributedType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_AttributedType
#  define MX_EXIT_VISIT_AttributedType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(AttributedType)
  MX_ENTER_VISIT_AttributedType
  MX_VISIT_BASE(AttributedType, Type)
  MX_VISIT_ENTITY(AttributedType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENUM(AttributedType, attribute_kind, 347, MX_APPLY_METHOD, AttributeKind, AttributeKind, NthType)
  MX_VISIT_ENTITY(AttributedType, equivalent_type, 309, MX_APPLY_METHOD, EquivalentType, Type, NthType, TypeUseSelector::EQUIVALENT_TYPE)
  MX_VISIT_OPTIONAL_ENUM(AttributedType, immediate_nullability, 335, MX_APPLY_METHOD, ImmediateNullability, NullabilityKind, NthType)
  MX_VISIT_ENTITY(AttributedType, modified_type, 315, MX_APPLY_METHOD, ModifiedType, Type, NthType, TypeUseSelector::MODIFIED_TYPE)
  MX_VISIT_BOOL(AttributedType, is_calling_conv, 311, MX_APPLY_METHOD, IsCallingConv, bool, NthType)
  MX_VISIT_BOOL(AttributedType, is_ms_type_spec, 312, MX_APPLY_METHOD, IsMSTypeSpec, bool, NthType)
  MX_VISIT_BOOL(AttributedType, is_qualifier, 313, MX_APPLY_METHOD, IsQualifier, bool, NthType)
  MX_VISIT_BOOL(AttributedType, is_sugared, 320, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_AttributedType
MX_END_VISIT_TYPE(AttributedType)

#ifndef MX_ENTER_VISIT_AtomicType
#  define MX_ENTER_VISIT_AtomicType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_AtomicType
#  define MX_EXIT_VISIT_AtomicType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(AtomicType)
  MX_ENTER_VISIT_AtomicType
  MX_VISIT_BASE(AtomicType, Type)
  MX_VISIT_ENTITY(AtomicType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(AtomicType, value_type, 309, MX_APPLY_METHOD, ValueType, Type, NthType, TypeUseSelector::VALUE_TYPE)
  MX_VISIT_BOOL(AtomicType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_AtomicType
MX_END_VISIT_TYPE(AtomicType)

#ifndef MX_ENTER_VISIT_ArrayType
#  define MX_ENTER_VISIT_ArrayType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ArrayType
#  define MX_EXIT_VISIT_ArrayType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(ArrayType)
  MX_ENTER_VISIT_ArrayType
  MX_VISIT_BASE(ArrayType, Type)
  MX_VISIT_ENTITY(ArrayType, element_type, 308, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENUM(ArrayType, size_modifier, 335, MX_APPLY_METHOD, SizeModifier, ArrayTypeArraySizeModifier, NthType)
  MX_EXIT_VISIT_ArrayType
MX_END_VISIT_TYPE(ArrayType)

#ifndef MX_ENTER_VISIT_VariableArrayType
#  define MX_ENTER_VISIT_VariableArrayType MX_ENTER_VISIT_ArrayType
#endif
#ifndef MX_EXIT_VISIT_VariableArrayType
#  define MX_EXIT_VISIT_VariableArrayType MX_EXIT_VISIT_ArrayType
#endif

MX_BEGIN_VISIT_TYPE(VariableArrayType)
  MX_ENTER_VISIT_VariableArrayType
  MX_VISIT_BASE(VariableArrayType, ArrayType)
  MX_VISIT_ENTITY(VariableArrayType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(VariableArrayType, l_bracket_token, 331, MX_APPLY_METHOD, LBracketToken, Token, NthType, TokenUseSelector::L_BRACKET_TOKEN)
  MX_VISIT_ENTITY(VariableArrayType, r_bracket_token, 332, MX_APPLY_METHOD, RBracketToken, Token, NthType, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(VariableArrayType, size_expression, 338, MX_APPLY_METHOD, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(VariableArrayType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_VariableArrayType
MX_END_VISIT_TYPE(VariableArrayType)

#ifndef MX_ENTER_VISIT_IncompleteArrayType
#  define MX_ENTER_VISIT_IncompleteArrayType MX_ENTER_VISIT_ArrayType
#endif
#ifndef MX_EXIT_VISIT_IncompleteArrayType
#  define MX_EXIT_VISIT_IncompleteArrayType MX_EXIT_VISIT_ArrayType
#endif

MX_BEGIN_VISIT_TYPE(IncompleteArrayType)
  MX_ENTER_VISIT_IncompleteArrayType
  MX_VISIT_BASE(IncompleteArrayType, ArrayType)
  MX_VISIT_ENTITY(IncompleteArrayType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(IncompleteArrayType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_IncompleteArrayType
MX_END_VISIT_TYPE(IncompleteArrayType)

#ifndef MX_ENTER_VISIT_DependentSizedArrayType
#  define MX_ENTER_VISIT_DependentSizedArrayType MX_ENTER_VISIT_ArrayType
#endif
#ifndef MX_EXIT_VISIT_DependentSizedArrayType
#  define MX_EXIT_VISIT_DependentSizedArrayType MX_EXIT_VISIT_ArrayType
#endif

MX_BEGIN_VISIT_TYPE(DependentSizedArrayType)
  MX_ENTER_VISIT_DependentSizedArrayType
  MX_VISIT_BASE(DependentSizedArrayType, ArrayType)
  MX_VISIT_ENTITY(DependentSizedArrayType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentSizedArrayType, l_bracket_token, 331, MX_APPLY_METHOD, LBracketToken, Token, NthType, TokenUseSelector::L_BRACKET_TOKEN)
  MX_VISIT_ENTITY(DependentSizedArrayType, r_bracket_token, 332, MX_APPLY_METHOD, RBracketToken, Token, NthType, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(DependentSizedArrayType, size_expression, 338, MX_APPLY_METHOD, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(DependentSizedArrayType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DependentSizedArrayType
MX_END_VISIT_TYPE(DependentSizedArrayType)

#ifndef MX_ENTER_VISIT_ConstantArrayType
#  define MX_ENTER_VISIT_ConstantArrayType MX_ENTER_VISIT_ArrayType
#endif
#ifndef MX_EXIT_VISIT_ConstantArrayType
#  define MX_EXIT_VISIT_ConstantArrayType MX_EXIT_VISIT_ArrayType
#endif

MX_BEGIN_VISIT_TYPE(ConstantArrayType)
  MX_ENTER_VISIT_ConstantArrayType
  MX_VISIT_BASE(ConstantArrayType, ArrayType)
  MX_VISIT_ENTITY(ConstantArrayType, desugar, 309, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_ENTITY(ConstantArrayType, size_expression, 315, MX_APPLY_METHOD, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(ConstantArrayType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_ConstantArrayType
MX_END_VISIT_TYPE(ConstantArrayType)

#ifndef MX_ENTER_VISIT_AdjustedType
#  define MX_ENTER_VISIT_AdjustedType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_AdjustedType
#  define MX_EXIT_VISIT_AdjustedType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(AdjustedType)
  MX_ENTER_VISIT_AdjustedType
  MX_VISIT_BASE(AdjustedType, Type)
  MX_VISIT_ENTITY(AdjustedType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(AdjustedType, resolved_type, 309, MX_APPLY_METHOD, ResolvedType, Type, NthType, TypeUseSelector::RESOLVED_TYPE)
  MX_VISIT_ENTITY(AdjustedType, original_type, 315, MX_APPLY_METHOD, OriginalType, Type, NthType, TypeUseSelector::ORIGINAL_TYPE)
  MX_VISIT_BOOL(AdjustedType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_AdjustedType
MX_END_VISIT_TYPE(AdjustedType)

#ifndef MX_ENTER_VISIT_DecayedType
#  define MX_ENTER_VISIT_DecayedType MX_ENTER_VISIT_AdjustedType
#endif
#ifndef MX_EXIT_VISIT_DecayedType
#  define MX_EXIT_VISIT_DecayedType MX_EXIT_VISIT_AdjustedType
#endif

MX_BEGIN_VISIT_TYPE(DecayedType)
  MX_ENTER_VISIT_DecayedType
  MX_VISIT_BASE(DecayedType, AdjustedType)
  MX_EXIT_VISIT_DecayedType
MX_END_VISIT_TYPE(DecayedType)

#ifndef MX_ENTER_VISIT_TypeWithKeyword
#  define MX_ENTER_VISIT_TypeWithKeyword MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TypeWithKeyword
#  define MX_EXIT_VISIT_TypeWithKeyword MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_ABSTRACT_TYPE(TypeWithKeyword)
  MX_ENTER_VISIT_TypeWithKeyword
  MX_VISIT_BASE(TypeWithKeyword, Type)
  MX_VISIT_ENUM(TypeWithKeyword, keyword, 335, MX_APPLY_METHOD, Keyword, ElaboratedTypeKeyword, NthType)
  MX_EXIT_VISIT_TypeWithKeyword
MX_END_VISIT_TYPE(TypeWithKeyword)

#ifndef MX_ENTER_VISIT_ElaboratedType
#  define MX_ENTER_VISIT_ElaboratedType MX_ENTER_VISIT_TypeWithKeyword
#endif
#ifndef MX_EXIT_VISIT_ElaboratedType
#  define MX_EXIT_VISIT_ElaboratedType MX_EXIT_VISIT_TypeWithKeyword
#endif

MX_BEGIN_VISIT_TYPE(ElaboratedType)
  MX_ENTER_VISIT_ElaboratedType
  MX_VISIT_BASE(ElaboratedType, TypeWithKeyword)
  MX_VISIT_ENTITY(ElaboratedType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ElaboratedType, named_type, 309, MX_APPLY_METHOD, NamedType, Type, NthType, TypeUseSelector::NAMED_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(ElaboratedType, owned_tag_declaration, 315, MX_APPLY_METHOD, OwnedTagDeclaration, TagDecl, NthType, DeclUseSelector::OWNED_TAG_DECLARATION)
  MX_VISIT_BOOL(ElaboratedType, is_sugared, 311, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_ElaboratedType
MX_END_VISIT_TYPE(ElaboratedType)

#ifndef MX_ENTER_VISIT_DependentTemplateSpecializationType
#  define MX_ENTER_VISIT_DependentTemplateSpecializationType MX_ENTER_VISIT_TypeWithKeyword
#endif
#ifndef MX_EXIT_VISIT_DependentTemplateSpecializationType
#  define MX_EXIT_VISIT_DependentTemplateSpecializationType MX_EXIT_VISIT_TypeWithKeyword
#endif

MX_BEGIN_VISIT_TYPE(DependentTemplateSpecializationType)
  MX_ENTER_VISIT_DependentTemplateSpecializationType
  MX_VISIT_BASE(DependentTemplateSpecializationType, TypeWithKeyword)
  MX_VISIT_ENTITY(DependentTemplateSpecializationType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(DependentTemplateSpecializationType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_VISIT_PSEUDO_LIST(DependentTemplateSpecializationType, template_arguments, 314, MX_APPLY_METHOD, TemplateArguments, TemplateArgument, NthType)
  MX_EXIT_VISIT_DependentTemplateSpecializationType
MX_END_VISIT_TYPE(DependentTemplateSpecializationType)

#ifndef MX_ENTER_VISIT_DependentNameType
#  define MX_ENTER_VISIT_DependentNameType MX_ENTER_VISIT_TypeWithKeyword
#endif
#ifndef MX_EXIT_VISIT_DependentNameType
#  define MX_EXIT_VISIT_DependentNameType MX_EXIT_VISIT_TypeWithKeyword
#endif

MX_BEGIN_VISIT_TYPE(DependentNameType)
  MX_ENTER_VISIT_DependentNameType
  MX_VISIT_BASE(DependentNameType, TypeWithKeyword)
  MX_VISIT_ENTITY(DependentNameType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(DependentNameType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DependentNameType
MX_END_VISIT_TYPE(DependentNameType)

#ifndef MX_ENTER_VISIT_VectorType
#  define MX_ENTER_VISIT_VectorType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_VectorType
#  define MX_EXIT_VISIT_VectorType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(VectorType)
  MX_ENTER_VISIT_VectorType
  MX_VISIT_BASE(VectorType, Type)
  MX_VISIT_ENTITY(VectorType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(VectorType, element_type, 309, MX_APPLY_METHOD, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENUM(VectorType, vector_kind, 335, MX_APPLY_METHOD, VectorKind, VectorTypeVectorKind, NthType)
  MX_VISIT_BOOL(VectorType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_VectorType
MX_END_VISIT_TYPE(VectorType)

#ifndef MX_ENTER_VISIT_ExtVectorType
#  define MX_ENTER_VISIT_ExtVectorType MX_ENTER_VISIT_VectorType
#endif
#ifndef MX_EXIT_VISIT_ExtVectorType
#  define MX_EXIT_VISIT_ExtVectorType MX_EXIT_VISIT_VectorType
#endif

MX_BEGIN_VISIT_TYPE(ExtVectorType)
  MX_ENTER_VISIT_ExtVectorType
  MX_VISIT_BASE(ExtVectorType, VectorType)
  MX_EXIT_VISIT_ExtVectorType
MX_END_VISIT_TYPE(ExtVectorType)

#ifndef MX_ENTER_VISIT_UsingType
#  define MX_ENTER_VISIT_UsingType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_UsingType
#  define MX_EXIT_VISIT_UsingType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(UsingType)
  MX_ENTER_VISIT_UsingType
  MX_VISIT_BASE(UsingType, Type)
  MX_VISIT_ENTITY(UsingType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(UsingType, found_declaration, 309, MX_APPLY_METHOD, FoundDeclaration, UsingShadowDecl, NthType, DeclUseSelector::FOUND_DECLARATION)
  MX_VISIT_ENTITY(UsingType, underlying_type, 315, MX_APPLY_METHOD, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(UsingType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_UsingType
MX_END_VISIT_TYPE(UsingType)

#ifndef MX_ENTER_VISIT_UnresolvedUsingType
#  define MX_ENTER_VISIT_UnresolvedUsingType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_UnresolvedUsingType
#  define MX_EXIT_VISIT_UnresolvedUsingType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(UnresolvedUsingType)
  MX_ENTER_VISIT_UnresolvedUsingType
  MX_VISIT_BASE(UnresolvedUsingType, Type)
  MX_VISIT_ENTITY(UnresolvedUsingType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(UnresolvedUsingType, declaration, 309, MX_APPLY_METHOD, Declaration, UnresolvedUsingTypenameDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(UnresolvedUsingType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_UnresolvedUsingType
MX_END_VISIT_TYPE(UnresolvedUsingType)

#ifndef MX_ENTER_VISIT_UnaryTransformType
#  define MX_ENTER_VISIT_UnaryTransformType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_UnaryTransformType
#  define MX_EXIT_VISIT_UnaryTransformType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(UnaryTransformType)
  MX_ENTER_VISIT_UnaryTransformType
  MX_VISIT_BASE(UnaryTransformType, Type)
  MX_VISIT_ENTITY(UnaryTransformType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(UnaryTransformType, base_type, 309, MX_APPLY_METHOD, BaseType, Type, NthType, TypeUseSelector::BASE_TYPE)
  MX_VISIT_ENUM(UnaryTransformType, utt_kind, 335, MX_APPLY_METHOD, UTTKind, UnaryTransformTypeUTTKind, NthType)
  MX_VISIT_ENTITY(UnaryTransformType, underlying_type, 315, MX_APPLY_METHOD, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(UnaryTransformType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_UnaryTransformType
MX_END_VISIT_TYPE(UnaryTransformType)

#ifndef MX_ENTER_VISIT_TypedefType
#  define MX_ENTER_VISIT_TypedefType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TypedefType
#  define MX_EXIT_VISIT_TypedefType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(TypedefType)
  MX_ENTER_VISIT_TypedefType
  MX_VISIT_BASE(TypedefType, Type)
  MX_VISIT_ENTITY(TypedefType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TypedefType, declaration, 309, MX_APPLY_METHOD, Declaration, TypedefNameDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(TypedefType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_TypedefType
MX_END_VISIT_TYPE(TypedefType)

#ifndef MX_ENTER_VISIT_TypeOfType
#  define MX_ENTER_VISIT_TypeOfType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TypeOfType
#  define MX_EXIT_VISIT_TypeOfType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(TypeOfType)
  MX_ENTER_VISIT_TypeOfType
  MX_VISIT_BASE(TypeOfType, Type)
  MX_VISIT_ENTITY(TypeOfType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TypeOfType, underlying_type, 309, MX_APPLY_METHOD, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(TypeOfType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_TypeOfType
MX_END_VISIT_TYPE(TypeOfType)

#ifndef MX_ENTER_VISIT_TypeOfExprType
#  define MX_ENTER_VISIT_TypeOfExprType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_TypeOfExprType
#  define MX_EXIT_VISIT_TypeOfExprType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(TypeOfExprType)
  MX_ENTER_VISIT_TypeOfExprType
  MX_VISIT_BASE(TypeOfExprType, Type)
  MX_VISIT_ENTITY(TypeOfExprType, desugar, 308, MX_APPLY_METHOD, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TypeOfExprType, underlying_expression, 309, MX_APPLY_METHOD, UnderlyingExpression, Expr, NthType, StmtUseSelector::UNDERLYING_EXPRESSION)
  MX_VISIT_BOOL(TypeOfExprType, is_sugared, 310, MX_APPLY_METHOD, IsSugared, bool, NthType)
  MX_EXIT_VISIT_TypeOfExprType
MX_END_VISIT_TYPE(TypeOfExprType)

#ifndef MX_ENTER_VISIT_Stmt
#  define MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_Stmt
#  define MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(Stmt)
  MX_ENTER_VISIT_Stmt
  MX_VISIT_DECL_LINK(Stmt, parent_declaration, 0)
  MX_VISIT_STMT_LINK(Stmt, parent_statement, 1)
  MX_VISIT_OPTIONAL_ENTITY(Stmt, referenced_declaration, 2, MX_APPLY_FUNC, ReferencedDecl, Decl, NthStmt, DeclUseSelector::REFERENCED_DECLARATION)
  MX_VISIT_ENTITY(Stmt, ignore_containers, 3, MX_APPLY_METHOD, IgnoreContainers, Stmt, NthStmt, StmtUseSelector::IGNORE_CONTAINERS)
  MX_VISIT_ENTITY_LIST(Stmt, children, 4, MX_APPLY_METHOD, Children, Stmt, NthStmt)
  MX_VISIT_ENUM(Stmt, kind, 7, MX_APPLY_METHOD, Kind, StmtKind, NthStmt)
  MX_VISIT_ENTITY(Stmt, strip_label_like_statements, 8, MX_APPLY_METHOD, StripLabelLikeStatements, Stmt, NthStmt, StmtUseSelector::STRIP_LABEL_LIKE_STATEMENTS)
  MX_EXIT_VISIT_Stmt
MX_END_VISIT_STMT(Stmt)

#ifndef MX_ENTER_VISIT_SEHTryStmt
#  define MX_ENTER_VISIT_SEHTryStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_SEHTryStmt
#  define MX_EXIT_VISIT_SEHTryStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(SEHTryStmt)
  MX_ENTER_VISIT_SEHTryStmt
  MX_VISIT_BASE(SEHTryStmt, Stmt)
  MX_VISIT_ENTITY(SEHTryStmt, except_handler, 9, MX_APPLY_METHOD, ExceptHandler, SEHExceptStmt, NthStmt, StmtUseSelector::EXCEPT_HANDLER)
  MX_VISIT_ENTITY(SEHTryStmt, finally_handler, 10, MX_APPLY_METHOD, FinallyHandler, SEHFinallyStmt, NthStmt, StmtUseSelector::FINALLY_HANDLER)
  MX_VISIT_ENTITY(SEHTryStmt, handler, 11, MX_APPLY_METHOD, Handler, Stmt, NthStmt, StmtUseSelector::HANDLER)
  MX_VISIT_BOOL(SEHTryStmt, is_cxx_try, 12, MX_APPLY_METHOD, IsCXXTry, bool, NthStmt)
  MX_VISIT_ENTITY(SEHTryStmt, try_block, 13, MX_APPLY_METHOD, TryBlock, CompoundStmt, NthStmt, StmtUseSelector::TRY_BLOCK)
  MX_VISIT_ENTITY(SEHTryStmt, try_token, 14, MX_APPLY_METHOD, TryToken, Token, NthStmt, TokenUseSelector::TRY_TOKEN)
  MX_EXIT_VISIT_SEHTryStmt
MX_END_VISIT_STMT(SEHTryStmt)

#ifndef MX_ENTER_VISIT_SEHLeaveStmt
#  define MX_ENTER_VISIT_SEHLeaveStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_SEHLeaveStmt
#  define MX_EXIT_VISIT_SEHLeaveStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(SEHLeaveStmt)
  MX_ENTER_VISIT_SEHLeaveStmt
  MX_VISIT_BASE(SEHLeaveStmt, Stmt)
  MX_VISIT_ENTITY(SEHLeaveStmt, leave_token, 9, MX_APPLY_METHOD, LeaveToken, Token, NthStmt, TokenUseSelector::LEAVE_TOKEN)
  MX_EXIT_VISIT_SEHLeaveStmt
MX_END_VISIT_STMT(SEHLeaveStmt)

#ifndef MX_ENTER_VISIT_SEHFinallyStmt
#  define MX_ENTER_VISIT_SEHFinallyStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_SEHFinallyStmt
#  define MX_EXIT_VISIT_SEHFinallyStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(SEHFinallyStmt)
  MX_ENTER_VISIT_SEHFinallyStmt
  MX_VISIT_BASE(SEHFinallyStmt, Stmt)
  MX_VISIT_ENTITY(SEHFinallyStmt, block, 9, MX_APPLY_METHOD, Block, CompoundStmt, NthStmt, StmtUseSelector::BLOCK)
  MX_VISIT_ENTITY(SEHFinallyStmt, finally_token, 10, MX_APPLY_METHOD, FinallyToken, Token, NthStmt, TokenUseSelector::FINALLY_TOKEN)
  MX_EXIT_VISIT_SEHFinallyStmt
MX_END_VISIT_STMT(SEHFinallyStmt)

#ifndef MX_ENTER_VISIT_SEHExceptStmt
#  define MX_ENTER_VISIT_SEHExceptStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_SEHExceptStmt
#  define MX_EXIT_VISIT_SEHExceptStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(SEHExceptStmt)
  MX_ENTER_VISIT_SEHExceptStmt
  MX_VISIT_BASE(SEHExceptStmt, Stmt)
  MX_VISIT_ENTITY(SEHExceptStmt, block, 9, MX_APPLY_METHOD, Block, CompoundStmt, NthStmt, StmtUseSelector::BLOCK)
  MX_VISIT_ENTITY(SEHExceptStmt, except_token, 10, MX_APPLY_METHOD, ExceptToken, Token, NthStmt, TokenUseSelector::EXCEPT_TOKEN)
  MX_VISIT_ENTITY(SEHExceptStmt, filter_expression, 11, MX_APPLY_METHOD, FilterExpression, Expr, NthStmt, StmtUseSelector::FILTER_EXPRESSION)
  MX_EXIT_VISIT_SEHExceptStmt
MX_END_VISIT_STMT(SEHExceptStmt)

#ifndef MX_ENTER_VISIT_ReturnStmt
#  define MX_ENTER_VISIT_ReturnStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ReturnStmt
#  define MX_EXIT_VISIT_ReturnStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ReturnStmt)
  MX_ENTER_VISIT_ReturnStmt
  MX_VISIT_BASE(ReturnStmt, Stmt)
  MX_VISIT_OPTIONAL_ENTITY(ReturnStmt, nrvo_candidate, 9, MX_APPLY_METHOD, NRVOCandidate, VarDecl, NthStmt, DeclUseSelector::NRVO_CANDIDATE)
  MX_VISIT_OPTIONAL_ENTITY(ReturnStmt, return_value, 10, MX_APPLY_METHOD, ReturnValue, Expr, NthStmt, StmtUseSelector::RETURN_VALUE)
  MX_VISIT_ENTITY(ReturnStmt, return_token, 11, MX_APPLY_METHOD, ReturnToken, Token, NthStmt, TokenUseSelector::RETURN_TOKEN)
  MX_EXIT_VISIT_ReturnStmt
MX_END_VISIT_STMT(ReturnStmt)

#ifndef MX_ENTER_VISIT_ObjCForCollectionStmt
#  define MX_ENTER_VISIT_ObjCForCollectionStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCForCollectionStmt
#  define MX_EXIT_VISIT_ObjCForCollectionStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCForCollectionStmt)
  MX_ENTER_VISIT_ObjCForCollectionStmt
  MX_VISIT_BASE(ObjCForCollectionStmt, Stmt)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, body, 9, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, collection, 10, MX_APPLY_METHOD, Collection, Expr, NthStmt, StmtUseSelector::COLLECTION)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, element, 11, MX_APPLY_METHOD, Element, Stmt, NthStmt, StmtUseSelector::ELEMENT)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, for_token, 13, MX_APPLY_METHOD, ForToken, Token, NthStmt, TokenUseSelector::FOR_TOKEN)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, r_paren_token, 14, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_ObjCForCollectionStmt
MX_END_VISIT_STMT(ObjCForCollectionStmt)

#ifndef MX_ENTER_VISIT_ObjCAutoreleasePoolStmt
#  define MX_ENTER_VISIT_ObjCAutoreleasePoolStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCAutoreleasePoolStmt
#  define MX_EXIT_VISIT_ObjCAutoreleasePoolStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCAutoreleasePoolStmt)
  MX_ENTER_VISIT_ObjCAutoreleasePoolStmt
  MX_VISIT_BASE(ObjCAutoreleasePoolStmt, Stmt)
  MX_VISIT_ENTITY(ObjCAutoreleasePoolStmt, at_token, 9, MX_APPLY_METHOD, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCAutoreleasePoolStmt, sub_statement, 10, MX_APPLY_METHOD, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_EXIT_VISIT_ObjCAutoreleasePoolStmt
MX_END_VISIT_STMT(ObjCAutoreleasePoolStmt)

#ifndef MX_ENTER_VISIT_ObjCAtTryStmt
#  define MX_ENTER_VISIT_ObjCAtTryStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCAtTryStmt
#  define MX_EXIT_VISIT_ObjCAtTryStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCAtTryStmt)
  MX_ENTER_VISIT_ObjCAtTryStmt
  MX_VISIT_BASE(ObjCAtTryStmt, Stmt)
  MX_VISIT_ENTITY(ObjCAtTryStmt, at_try_token, 9, MX_APPLY_METHOD, AtTryToken, Token, NthStmt, TokenUseSelector::AT_TRY_TOKEN)
  MX_VISIT_ENTITY(ObjCAtTryStmt, finally_statement, 10, MX_APPLY_METHOD, FinallyStatement, ObjCAtFinallyStmt, NthStmt, StmtUseSelector::FINALLY_STATEMENT)
  MX_VISIT_ENTITY(ObjCAtTryStmt, try_body, 11, MX_APPLY_METHOD, TryBody, Stmt, NthStmt, StmtUseSelector::TRY_BODY)
  MX_VISIT_ENTITY_LIST(ObjCAtTryStmt, catch_statements, 16, MX_APPLY_METHOD, CatchStatements, ObjCAtCatchStmt, NthStmt)
  MX_EXIT_VISIT_ObjCAtTryStmt
MX_END_VISIT_STMT(ObjCAtTryStmt)

#ifndef MX_ENTER_VISIT_ObjCAtThrowStmt
#  define MX_ENTER_VISIT_ObjCAtThrowStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCAtThrowStmt
#  define MX_EXIT_VISIT_ObjCAtThrowStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCAtThrowStmt)
  MX_ENTER_VISIT_ObjCAtThrowStmt
  MX_VISIT_BASE(ObjCAtThrowStmt, Stmt)
  MX_VISIT_ENTITY(ObjCAtThrowStmt, throw_expression, 9, MX_APPLY_METHOD, ThrowExpression, Expr, NthStmt, StmtUseSelector::THROW_EXPRESSION)
  MX_VISIT_ENTITY(ObjCAtThrowStmt, throw_token, 10, MX_APPLY_METHOD, ThrowToken, Token, NthStmt, TokenUseSelector::THROW_TOKEN)
  MX_EXIT_VISIT_ObjCAtThrowStmt
MX_END_VISIT_STMT(ObjCAtThrowStmt)

#ifndef MX_ENTER_VISIT_ObjCAtSynchronizedStmt
#  define MX_ENTER_VISIT_ObjCAtSynchronizedStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCAtSynchronizedStmt
#  define MX_EXIT_VISIT_ObjCAtSynchronizedStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCAtSynchronizedStmt)
  MX_ENTER_VISIT_ObjCAtSynchronizedStmt
  MX_VISIT_BASE(ObjCAtSynchronizedStmt, Stmt)
  MX_VISIT_ENTITY(ObjCAtSynchronizedStmt, at_synchronized_token, 9, MX_APPLY_METHOD, AtSynchronizedToken, Token, NthStmt, TokenUseSelector::AT_SYNCHRONIZED_TOKEN)
  MX_VISIT_ENTITY(ObjCAtSynchronizedStmt, synch_body, 10, MX_APPLY_METHOD, SynchBody, CompoundStmt, NthStmt, StmtUseSelector::SYNCH_BODY)
  MX_VISIT_ENTITY(ObjCAtSynchronizedStmt, synch_expression, 11, MX_APPLY_METHOD, SynchExpression, Expr, NthStmt, StmtUseSelector::SYNCH_EXPRESSION)
  MX_EXIT_VISIT_ObjCAtSynchronizedStmt
MX_END_VISIT_STMT(ObjCAtSynchronizedStmt)

#ifndef MX_ENTER_VISIT_ObjCAtFinallyStmt
#  define MX_ENTER_VISIT_ObjCAtFinallyStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCAtFinallyStmt
#  define MX_EXIT_VISIT_ObjCAtFinallyStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCAtFinallyStmt)
  MX_ENTER_VISIT_ObjCAtFinallyStmt
  MX_VISIT_BASE(ObjCAtFinallyStmt, Stmt)
  MX_VISIT_ENTITY(ObjCAtFinallyStmt, at_finally_token, 9, MX_APPLY_METHOD, AtFinallyToken, Token, NthStmt, TokenUseSelector::AT_FINALLY_TOKEN)
  MX_VISIT_ENTITY(ObjCAtFinallyStmt, finally_body, 10, MX_APPLY_METHOD, FinallyBody, Stmt, NthStmt, StmtUseSelector::FINALLY_BODY)
  MX_EXIT_VISIT_ObjCAtFinallyStmt
MX_END_VISIT_STMT(ObjCAtFinallyStmt)

#ifndef MX_ENTER_VISIT_ObjCAtCatchStmt
#  define MX_ENTER_VISIT_ObjCAtCatchStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ObjCAtCatchStmt
#  define MX_EXIT_VISIT_ObjCAtCatchStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ObjCAtCatchStmt)
  MX_ENTER_VISIT_ObjCAtCatchStmt
  MX_VISIT_BASE(ObjCAtCatchStmt, Stmt)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, at_catch_token, 9, MX_APPLY_METHOD, AtCatchToken, Token, NthStmt, TokenUseSelector::AT_CATCH_TOKEN)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, catch_body, 10, MX_APPLY_METHOD, CatchBody, Stmt, NthStmt, StmtUseSelector::CATCH_BODY)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, catch_parameter_declaration, 11, MX_APPLY_METHOD, CatchParameterDeclaration, VarDecl, NthStmt, DeclUseSelector::CATCH_PARAMETER_DECLARATION)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, r_paren_token, 13, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(ObjCAtCatchStmt, has_ellipsis, 12, MX_APPLY_METHOD, HasEllipsis, bool, NthStmt)
  MX_EXIT_VISIT_ObjCAtCatchStmt
MX_END_VISIT_STMT(ObjCAtCatchStmt)

#ifndef MX_ENTER_VISIT_OMPExecutableDirective
#  define MX_ENTER_VISIT_OMPExecutableDirective MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_OMPExecutableDirective
#  define MX_EXIT_VISIT_OMPExecutableDirective MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(OMPExecutableDirective)
  MX_ENTER_VISIT_OMPExecutableDirective
  MX_VISIT_BASE(OMPExecutableDirective, Stmt)
  MX_VISIT_ENTITY(OMPExecutableDirective, associated_statement, 9, MX_APPLY_METHOD, AssociatedStatement, Stmt, NthStmt, StmtUseSelector::ASSOCIATED_STATEMENT)
  MX_VISIT_ENTITY(OMPExecutableDirective, innermost_captured_statement, 10, MX_APPLY_METHOD, InnermostCapturedStatement, CapturedStmt, NthStmt, StmtUseSelector::INNERMOST_CAPTURED_STATEMENT)
  MX_VISIT_ENTITY(OMPExecutableDirective, raw_statement, 11, MX_APPLY_METHOD, RawStatement, Stmt, NthStmt, StmtUseSelector::RAW_STATEMENT)
  MX_VISIT_ENTITY(OMPExecutableDirective, structured_block, 13, MX_APPLY_METHOD, StructuredBlock, Stmt, NthStmt, StmtUseSelector::STRUCTURED_BLOCK)
  MX_VISIT_BOOL(OMPExecutableDirective, has_associated_statement, 12, MX_APPLY_METHOD, HasAssociatedStatement, bool, NthStmt)
  MX_VISIT_BOOL(OMPExecutableDirective, is_standalone_directive, 15, MX_APPLY_METHOD, IsStandaloneDirective, bool, NthStmt)
  MX_EXIT_VISIT_OMPExecutableDirective
MX_END_VISIT_STMT(OMPExecutableDirective)

#ifndef MX_ENTER_VISIT_OMPDispatchDirective
#  define MX_ENTER_VISIT_OMPDispatchDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPDispatchDirective
#  define MX_EXIT_VISIT_OMPDispatchDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPDispatchDirective)
  MX_ENTER_VISIT_OMPDispatchDirective
  MX_VISIT_BASE(OMPDispatchDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPDispatchDirective, target_call_token, 14, MX_APPLY_METHOD, TargetCallToken, Token, NthStmt, TokenUseSelector::TARGET_CALL_TOKEN)
  MX_EXIT_VISIT_OMPDispatchDirective
MX_END_VISIT_STMT(OMPDispatchDirective)

#ifndef MX_ENTER_VISIT_OMPDepobjDirective
#  define MX_ENTER_VISIT_OMPDepobjDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPDepobjDirective
#  define MX_EXIT_VISIT_OMPDepobjDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPDepobjDirective)
  MX_ENTER_VISIT_OMPDepobjDirective
  MX_VISIT_BASE(OMPDepobjDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPDepobjDirective
MX_END_VISIT_STMT(OMPDepobjDirective)

#ifndef MX_ENTER_VISIT_OMPCriticalDirective
#  define MX_ENTER_VISIT_OMPCriticalDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPCriticalDirective
#  define MX_EXIT_VISIT_OMPCriticalDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPCriticalDirective)
  MX_ENTER_VISIT_OMPCriticalDirective
  MX_VISIT_BASE(OMPCriticalDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPCriticalDirective
MX_END_VISIT_STMT(OMPCriticalDirective)

#ifndef MX_ENTER_VISIT_OMPCancellationPointDirective
#  define MX_ENTER_VISIT_OMPCancellationPointDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPCancellationPointDirective
#  define MX_EXIT_VISIT_OMPCancellationPointDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPCancellationPointDirective)
  MX_ENTER_VISIT_OMPCancellationPointDirective
  MX_VISIT_BASE(OMPCancellationPointDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPCancellationPointDirective
MX_END_VISIT_STMT(OMPCancellationPointDirective)

#ifndef MX_ENTER_VISIT_OMPCancelDirective
#  define MX_ENTER_VISIT_OMPCancelDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPCancelDirective
#  define MX_EXIT_VISIT_OMPCancelDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPCancelDirective)
  MX_ENTER_VISIT_OMPCancelDirective
  MX_VISIT_BASE(OMPCancelDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPCancelDirective
MX_END_VISIT_STMT(OMPCancelDirective)

#ifndef MX_ENTER_VISIT_OMPBarrierDirective
#  define MX_ENTER_VISIT_OMPBarrierDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPBarrierDirective
#  define MX_EXIT_VISIT_OMPBarrierDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPBarrierDirective)
  MX_ENTER_VISIT_OMPBarrierDirective
  MX_VISIT_BASE(OMPBarrierDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPBarrierDirective
MX_END_VISIT_STMT(OMPBarrierDirective)

#ifndef MX_ENTER_VISIT_OMPAtomicDirective
#  define MX_ENTER_VISIT_OMPAtomicDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPAtomicDirective
#  define MX_EXIT_VISIT_OMPAtomicDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPAtomicDirective)
  MX_ENTER_VISIT_OMPAtomicDirective
  MX_VISIT_BASE(OMPAtomicDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPAtomicDirective, expression, 14, MX_APPLY_METHOD, Expression, Expr, NthStmt, StmtUseSelector::EXPRESSION)
  MX_VISIT_ENTITY(OMPAtomicDirective, update_expression, 17, MX_APPLY_METHOD, UpdateExpression, Expr, NthStmt, StmtUseSelector::UPDATE_EXPRESSION)
  MX_VISIT_ENTITY(OMPAtomicDirective, v, 18, MX_APPLY_METHOD, V, Expr, NthStmt, StmtUseSelector::V)
  MX_VISIT_ENTITY(OMPAtomicDirective, x, 19, MX_APPLY_METHOD, X, Expr, NthStmt, StmtUseSelector::X)
  MX_VISIT_BOOL(OMPAtomicDirective, is_postfix_update, 20, MX_APPLY_METHOD, IsPostfixUpdate, bool, NthStmt)
  MX_VISIT_BOOL(OMPAtomicDirective, is_xlhs_in_rhs_part, 21, MX_APPLY_METHOD, IsXLHSInRHSPart, bool, NthStmt)
  MX_EXIT_VISIT_OMPAtomicDirective
MX_END_VISIT_STMT(OMPAtomicDirective)

#ifndef MX_ENTER_VISIT_OMPTeamsDirective
#  define MX_ENTER_VISIT_OMPTeamsDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTeamsDirective
#  define MX_EXIT_VISIT_OMPTeamsDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTeamsDirective)
  MX_ENTER_VISIT_OMPTeamsDirective
  MX_VISIT_BASE(OMPTeamsDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTeamsDirective
MX_END_VISIT_STMT(OMPTeamsDirective)

#ifndef MX_ENTER_VISIT_OMPTaskyieldDirective
#  define MX_ENTER_VISIT_OMPTaskyieldDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTaskyieldDirective
#  define MX_EXIT_VISIT_OMPTaskyieldDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTaskyieldDirective)
  MX_ENTER_VISIT_OMPTaskyieldDirective
  MX_VISIT_BASE(OMPTaskyieldDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTaskyieldDirective
MX_END_VISIT_STMT(OMPTaskyieldDirective)

#ifndef MX_ENTER_VISIT_OMPTaskwaitDirective
#  define MX_ENTER_VISIT_OMPTaskwaitDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTaskwaitDirective
#  define MX_EXIT_VISIT_OMPTaskwaitDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTaskwaitDirective)
  MX_ENTER_VISIT_OMPTaskwaitDirective
  MX_VISIT_BASE(OMPTaskwaitDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTaskwaitDirective
MX_END_VISIT_STMT(OMPTaskwaitDirective)

#ifndef MX_ENTER_VISIT_OMPTaskgroupDirective
#  define MX_ENTER_VISIT_OMPTaskgroupDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTaskgroupDirective
#  define MX_EXIT_VISIT_OMPTaskgroupDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTaskgroupDirective)
  MX_ENTER_VISIT_OMPTaskgroupDirective
  MX_VISIT_BASE(OMPTaskgroupDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPTaskgroupDirective, reduction_reference, 14, MX_APPLY_METHOD, ReductionReference, Expr, NthStmt, StmtUseSelector::REDUCTION_REFERENCE)
  MX_EXIT_VISIT_OMPTaskgroupDirective
MX_END_VISIT_STMT(OMPTaskgroupDirective)

#ifndef MX_ENTER_VISIT_OMPTaskDirective
#  define MX_ENTER_VISIT_OMPTaskDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTaskDirective
#  define MX_EXIT_VISIT_OMPTaskDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTaskDirective)
  MX_ENTER_VISIT_OMPTaskDirective
  MX_VISIT_BASE(OMPTaskDirective, OMPExecutableDirective)
  MX_VISIT_BOOL(OMPTaskDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPTaskDirective
MX_END_VISIT_STMT(OMPTaskDirective)

#ifndef MX_ENTER_VISIT_OMPTargetUpdateDirective
#  define MX_ENTER_VISIT_OMPTargetUpdateDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetUpdateDirective
#  define MX_EXIT_VISIT_OMPTargetUpdateDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetUpdateDirective)
  MX_ENTER_VISIT_OMPTargetUpdateDirective
  MX_VISIT_BASE(OMPTargetUpdateDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTargetUpdateDirective
MX_END_VISIT_STMT(OMPTargetUpdateDirective)

#ifndef MX_ENTER_VISIT_OMPTargetTeamsDirective
#  define MX_ENTER_VISIT_OMPTargetTeamsDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetTeamsDirective
#  define MX_EXIT_VISIT_OMPTargetTeamsDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetTeamsDirective)
  MX_ENTER_VISIT_OMPTargetTeamsDirective
  MX_VISIT_BASE(OMPTargetTeamsDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTargetTeamsDirective
MX_END_VISIT_STMT(OMPTargetTeamsDirective)

#ifndef MX_ENTER_VISIT_OMPTargetParallelDirective
#  define MX_ENTER_VISIT_OMPTargetParallelDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetParallelDirective
#  define MX_EXIT_VISIT_OMPTargetParallelDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetParallelDirective)
  MX_ENTER_VISIT_OMPTargetParallelDirective
  MX_VISIT_BASE(OMPTargetParallelDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPTargetParallelDirective, task_reduction_reference_expression, 14, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTargetParallelDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPTargetParallelDirective
MX_END_VISIT_STMT(OMPTargetParallelDirective)

#ifndef MX_ENTER_VISIT_OMPTargetExitDataDirective
#  define MX_ENTER_VISIT_OMPTargetExitDataDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetExitDataDirective
#  define MX_EXIT_VISIT_OMPTargetExitDataDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetExitDataDirective)
  MX_ENTER_VISIT_OMPTargetExitDataDirective
  MX_VISIT_BASE(OMPTargetExitDataDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTargetExitDataDirective
MX_END_VISIT_STMT(OMPTargetExitDataDirective)

#ifndef MX_ENTER_VISIT_OMPTargetEnterDataDirective
#  define MX_ENTER_VISIT_OMPTargetEnterDataDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetEnterDataDirective
#  define MX_EXIT_VISIT_OMPTargetEnterDataDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetEnterDataDirective)
  MX_ENTER_VISIT_OMPTargetEnterDataDirective
  MX_VISIT_BASE(OMPTargetEnterDataDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTargetEnterDataDirective
MX_END_VISIT_STMT(OMPTargetEnterDataDirective)

#ifndef MX_ENTER_VISIT_OMPTargetDirective
#  define MX_ENTER_VISIT_OMPTargetDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetDirective
#  define MX_EXIT_VISIT_OMPTargetDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetDirective)
  MX_ENTER_VISIT_OMPTargetDirective
  MX_VISIT_BASE(OMPTargetDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTargetDirective
MX_END_VISIT_STMT(OMPTargetDirective)

#ifndef MX_ENTER_VISIT_OMPTargetDataDirective
#  define MX_ENTER_VISIT_OMPTargetDataDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetDataDirective
#  define MX_EXIT_VISIT_OMPTargetDataDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetDataDirective)
  MX_ENTER_VISIT_OMPTargetDataDirective
  MX_VISIT_BASE(OMPTargetDataDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPTargetDataDirective
MX_END_VISIT_STMT(OMPTargetDataDirective)

#ifndef MX_ENTER_VISIT_OMPSingleDirective
#  define MX_ENTER_VISIT_OMPSingleDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPSingleDirective
#  define MX_EXIT_VISIT_OMPSingleDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPSingleDirective)
  MX_ENTER_VISIT_OMPSingleDirective
  MX_VISIT_BASE(OMPSingleDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPSingleDirective
MX_END_VISIT_STMT(OMPSingleDirective)

#ifndef MX_ENTER_VISIT_OMPSectionsDirective
#  define MX_ENTER_VISIT_OMPSectionsDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPSectionsDirective
#  define MX_EXIT_VISIT_OMPSectionsDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPSectionsDirective)
  MX_ENTER_VISIT_OMPSectionsDirective
  MX_VISIT_BASE(OMPSectionsDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPSectionsDirective, task_reduction_reference_expression, 14, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPSectionsDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPSectionsDirective
MX_END_VISIT_STMT(OMPSectionsDirective)

#ifndef MX_ENTER_VISIT_OMPSectionDirective
#  define MX_ENTER_VISIT_OMPSectionDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPSectionDirective
#  define MX_EXIT_VISIT_OMPSectionDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPSectionDirective)
  MX_ENTER_VISIT_OMPSectionDirective
  MX_VISIT_BASE(OMPSectionDirective, OMPExecutableDirective)
  MX_VISIT_BOOL(OMPSectionDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPSectionDirective
MX_END_VISIT_STMT(OMPSectionDirective)

#ifndef MX_ENTER_VISIT_OMPScanDirective
#  define MX_ENTER_VISIT_OMPScanDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPScanDirective
#  define MX_EXIT_VISIT_OMPScanDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPScanDirective)
  MX_ENTER_VISIT_OMPScanDirective
  MX_VISIT_BASE(OMPScanDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPScanDirective
MX_END_VISIT_STMT(OMPScanDirective)

#ifndef MX_ENTER_VISIT_OMPParallelSectionsDirective
#  define MX_ENTER_VISIT_OMPParallelSectionsDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelSectionsDirective
#  define MX_EXIT_VISIT_OMPParallelSectionsDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelSectionsDirective)
  MX_ENTER_VISIT_OMPParallelSectionsDirective
  MX_VISIT_BASE(OMPParallelSectionsDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPParallelSectionsDirective, task_reduction_reference_expression, 14, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPParallelSectionsDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPParallelSectionsDirective
MX_END_VISIT_STMT(OMPParallelSectionsDirective)

#ifndef MX_ENTER_VISIT_OMPParallelMasterDirective
#  define MX_ENTER_VISIT_OMPParallelMasterDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelMasterDirective
#  define MX_EXIT_VISIT_OMPParallelMasterDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelMasterDirective)
  MX_ENTER_VISIT_OMPParallelMasterDirective
  MX_VISIT_BASE(OMPParallelMasterDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPParallelMasterDirective, task_reduction_reference_expression, 14, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_EXIT_VISIT_OMPParallelMasterDirective
MX_END_VISIT_STMT(OMPParallelMasterDirective)

#ifndef MX_ENTER_VISIT_OMPParallelDirective
#  define MX_ENTER_VISIT_OMPParallelDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelDirective
#  define MX_EXIT_VISIT_OMPParallelDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelDirective)
  MX_ENTER_VISIT_OMPParallelDirective
  MX_VISIT_BASE(OMPParallelDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPParallelDirective, task_reduction_reference_expression, 14, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPParallelDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPParallelDirective
MX_END_VISIT_STMT(OMPParallelDirective)

#ifndef MX_ENTER_VISIT_OMPOrderedDirective
#  define MX_ENTER_VISIT_OMPOrderedDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPOrderedDirective
#  define MX_EXIT_VISIT_OMPOrderedDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPOrderedDirective)
  MX_ENTER_VISIT_OMPOrderedDirective
  MX_VISIT_BASE(OMPOrderedDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPOrderedDirective
MX_END_VISIT_STMT(OMPOrderedDirective)

#ifndef MX_ENTER_VISIT_OMPMetaDirective
#  define MX_ENTER_VISIT_OMPMetaDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPMetaDirective
#  define MX_EXIT_VISIT_OMPMetaDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPMetaDirective)
  MX_ENTER_VISIT_OMPMetaDirective
  MX_VISIT_BASE(OMPMetaDirective, OMPExecutableDirective)
  MX_VISIT_ENTITY(OMPMetaDirective, if_statement, 14, MX_APPLY_METHOD, IfStatement, Stmt, NthStmt, StmtUseSelector::IF_STATEMENT)
  MX_EXIT_VISIT_OMPMetaDirective
MX_END_VISIT_STMT(OMPMetaDirective)

#ifndef MX_ENTER_VISIT_OMPMasterDirective
#  define MX_ENTER_VISIT_OMPMasterDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPMasterDirective
#  define MX_EXIT_VISIT_OMPMasterDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPMasterDirective)
  MX_ENTER_VISIT_OMPMasterDirective
  MX_VISIT_BASE(OMPMasterDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPMasterDirective
MX_END_VISIT_STMT(OMPMasterDirective)

#ifndef MX_ENTER_VISIT_OMPMaskedDirective
#  define MX_ENTER_VISIT_OMPMaskedDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPMaskedDirective
#  define MX_EXIT_VISIT_OMPMaskedDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPMaskedDirective)
  MX_ENTER_VISIT_OMPMaskedDirective
  MX_VISIT_BASE(OMPMaskedDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPMaskedDirective
MX_END_VISIT_STMT(OMPMaskedDirective)

#ifndef MX_ENTER_VISIT_OMPLoopBasedDirective
#  define MX_ENTER_VISIT_OMPLoopBasedDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPLoopBasedDirective
#  define MX_EXIT_VISIT_OMPLoopBasedDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(OMPLoopBasedDirective)
  MX_ENTER_VISIT_OMPLoopBasedDirective
  MX_VISIT_BASE(OMPLoopBasedDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPLoopBasedDirective
MX_END_VISIT_STMT(OMPLoopBasedDirective)

#ifndef MX_ENTER_VISIT_OMPLoopTransformationDirective
#  define MX_ENTER_VISIT_OMPLoopTransformationDirective MX_ENTER_VISIT_OMPLoopBasedDirective
#endif
#ifndef MX_EXIT_VISIT_OMPLoopTransformationDirective
#  define MX_EXIT_VISIT_OMPLoopTransformationDirective MX_EXIT_VISIT_OMPLoopBasedDirective
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(OMPLoopTransformationDirective)
  MX_ENTER_VISIT_OMPLoopTransformationDirective
  MX_VISIT_BASE(OMPLoopTransformationDirective, OMPLoopBasedDirective)
  MX_VISIT_ENTITY(OMPLoopTransformationDirective, pre_initializers, 14, MX_APPLY_METHOD, PreInitializers, Stmt, NthStmt, StmtUseSelector::PRE_INITIALIZERS)
  MX_VISIT_ENTITY(OMPLoopTransformationDirective, transformed_statement, 17, MX_APPLY_METHOD, TransformedStatement, Stmt, NthStmt, StmtUseSelector::TRANSFORMED_STATEMENT)
  MX_EXIT_VISIT_OMPLoopTransformationDirective
MX_END_VISIT_STMT(OMPLoopTransformationDirective)

#ifndef MX_ENTER_VISIT_OMPUnrollDirective
#  define MX_ENTER_VISIT_OMPUnrollDirective MX_ENTER_VISIT_OMPLoopTransformationDirective
#endif
#ifndef MX_EXIT_VISIT_OMPUnrollDirective
#  define MX_EXIT_VISIT_OMPUnrollDirective MX_EXIT_VISIT_OMPLoopTransformationDirective
#endif

MX_BEGIN_VISIT_STMT(OMPUnrollDirective)
  MX_ENTER_VISIT_OMPUnrollDirective
  MX_VISIT_BASE(OMPUnrollDirective, OMPLoopTransformationDirective)
  MX_EXIT_VISIT_OMPUnrollDirective
MX_END_VISIT_STMT(OMPUnrollDirective)

#ifndef MX_ENTER_VISIT_OMPTileDirective
#  define MX_ENTER_VISIT_OMPTileDirective MX_ENTER_VISIT_OMPLoopTransformationDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTileDirective
#  define MX_EXIT_VISIT_OMPTileDirective MX_EXIT_VISIT_OMPLoopTransformationDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTileDirective)
  MX_ENTER_VISIT_OMPTileDirective
  MX_VISIT_BASE(OMPTileDirective, OMPLoopTransformationDirective)
  MX_EXIT_VISIT_OMPTileDirective
MX_END_VISIT_STMT(OMPTileDirective)

#ifndef MX_ENTER_VISIT_OMPLoopDirective
#  define MX_ENTER_VISIT_OMPLoopDirective MX_ENTER_VISIT_OMPLoopBasedDirective
#endif
#ifndef MX_EXIT_VISIT_OMPLoopDirective
#  define MX_EXIT_VISIT_OMPLoopDirective MX_EXIT_VISIT_OMPLoopBasedDirective
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(OMPLoopDirective)
  MX_ENTER_VISIT_OMPLoopDirective
  MX_VISIT_BASE(OMPLoopDirective, OMPLoopBasedDirective)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, counters, 16, MX_APPLY_METHOD, Counters, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, dependent_counters, 22, MX_APPLY_METHOD, DependentCounters, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, dependent_initializers, 23, MX_APPLY_METHOD, DependentInitializers, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, finals, 24, MX_APPLY_METHOD, Finals, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, finals_conditions, 25, MX_APPLY_METHOD, FinalsConditions, Expr, NthStmt)
  MX_VISIT_ENTITY(OMPLoopDirective, body, 14, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(OMPLoopDirective, calculate_last_iteration, 17, MX_APPLY_METHOD, CalculateLastIteration, Expr, NthStmt, StmtUseSelector::CALCULATE_LAST_ITERATION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_condition, 18, MX_APPLY_METHOD, CombinedCondition, Expr, NthStmt, StmtUseSelector::COMBINED_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_distance_condition, 19, MX_APPLY_METHOD, CombinedDistanceCondition, Expr, NthStmt, StmtUseSelector::COMBINED_DISTANCE_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_ensure_upper_bound, 26, MX_APPLY_METHOD, CombinedEnsureUpperBound, Expr, NthStmt, StmtUseSelector::COMBINED_ENSURE_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_initializer, 27, MX_APPLY_METHOD, CombinedInitializer, Expr, NthStmt, StmtUseSelector::COMBINED_INITIALIZER)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_lower_bound_variable, 28, MX_APPLY_METHOD, CombinedLowerBoundVariable, Expr, NthStmt, StmtUseSelector::COMBINED_LOWER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_next_lower_bound, 29, MX_APPLY_METHOD, CombinedNextLowerBound, Expr, NthStmt, StmtUseSelector::COMBINED_NEXT_LOWER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_next_upper_bound, 30, MX_APPLY_METHOD, CombinedNextUpperBound, Expr, NthStmt, StmtUseSelector::COMBINED_NEXT_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_parallel_for_in_distance_condition, 31, MX_APPLY_METHOD, CombinedParallelForInDistanceCondition, Expr, NthStmt, StmtUseSelector::COMBINED_PARALLEL_FOR_IN_DISTANCE_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_upper_bound_variable, 32, MX_APPLY_METHOD, CombinedUpperBoundVariable, Expr, NthStmt, StmtUseSelector::COMBINED_UPPER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, condition, 33, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, distance_increment, 34, MX_APPLY_METHOD, DistanceIncrement, Expr, NthStmt, StmtUseSelector::DISTANCE_INCREMENT)
  MX_VISIT_ENTITY(OMPLoopDirective, ensure_upper_bound, 35, MX_APPLY_METHOD, EnsureUpperBound, Expr, NthStmt, StmtUseSelector::ENSURE_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, increment, 36, MX_APPLY_METHOD, Increment, Expr, NthStmt, StmtUseSelector::INCREMENT)
  MX_VISIT_ENTITY(OMPLoopDirective, initializer, 37, MX_APPLY_METHOD, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(OMPLoopDirective, is_last_iteration_variable, 38, MX_APPLY_METHOD, IsLastIterationVariable, Expr, NthStmt, StmtUseSelector::IS_LAST_ITERATION_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, iteration_variable, 39, MX_APPLY_METHOD, IterationVariable, Expr, NthStmt, StmtUseSelector::ITERATION_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, last_iteration, 40, MX_APPLY_METHOD, LastIteration, Expr, NthStmt, StmtUseSelector::LAST_ITERATION)
  MX_VISIT_ENTITY(OMPLoopDirective, lower_bound_variable, 41, MX_APPLY_METHOD, LowerBoundVariable, Expr, NthStmt, StmtUseSelector::LOWER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, next_lower_bound, 42, MX_APPLY_METHOD, NextLowerBound, Expr, NthStmt, StmtUseSelector::NEXT_LOWER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, next_upper_bound, 43, MX_APPLY_METHOD, NextUpperBound, Expr, NthStmt, StmtUseSelector::NEXT_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, num_iterations, 44, MX_APPLY_METHOD, NumIterations, Expr, NthStmt, StmtUseSelector::NUM_ITERATIONS)
  MX_VISIT_ENTITY(OMPLoopDirective, pre_condition, 45, MX_APPLY_METHOD, PreCondition, Expr, NthStmt, StmtUseSelector::PRE_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, pre_initializers, 46, MX_APPLY_METHOD, PreInitializers, Stmt, NthStmt, StmtUseSelector::PRE_INITIALIZERS)
  MX_VISIT_ENTITY(OMPLoopDirective, prev_ensure_upper_bound, 47, MX_APPLY_METHOD, PrevEnsureUpperBound, Expr, NthStmt, StmtUseSelector::PREV_ENSURE_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, prev_lower_bound_variable, 48, MX_APPLY_METHOD, PrevLowerBoundVariable, Expr, NthStmt, StmtUseSelector::PREV_LOWER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, prev_upper_bound_variable, 49, MX_APPLY_METHOD, PrevUpperBoundVariable, Expr, NthStmt, StmtUseSelector::PREV_UPPER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, stride_variable, 50, MX_APPLY_METHOD, StrideVariable, Expr, NthStmt, StmtUseSelector::STRIDE_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, upper_bound_variable, 51, MX_APPLY_METHOD, UpperBoundVariable, Expr, NthStmt, StmtUseSelector::UPPER_BOUND_VARIABLE)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, initializers, 52, MX_APPLY_METHOD, Initializers, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, private_counters, 53, MX_APPLY_METHOD, PrivateCounters, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, updates, 54, MX_APPLY_METHOD, Updates, Expr, NthStmt)
  MX_EXIT_VISIT_OMPLoopDirective
MX_END_VISIT_STMT(OMPLoopDirective)

#ifndef MX_ENTER_VISIT_OMPGenericLoopDirective
#  define MX_ENTER_VISIT_OMPGenericLoopDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPGenericLoopDirective
#  define MX_EXIT_VISIT_OMPGenericLoopDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPGenericLoopDirective)
  MX_ENTER_VISIT_OMPGenericLoopDirective
  MX_VISIT_BASE(OMPGenericLoopDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPGenericLoopDirective
MX_END_VISIT_STMT(OMPGenericLoopDirective)

#ifndef MX_ENTER_VISIT_OMPForSimdDirective
#  define MX_ENTER_VISIT_OMPForSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPForSimdDirective
#  define MX_EXIT_VISIT_OMPForSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPForSimdDirective)
  MX_ENTER_VISIT_OMPForSimdDirective
  MX_VISIT_BASE(OMPForSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPForSimdDirective
MX_END_VISIT_STMT(OMPForSimdDirective)

#ifndef MX_ENTER_VISIT_OMPForDirective
#  define MX_ENTER_VISIT_OMPForDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPForDirective
#  define MX_EXIT_VISIT_OMPForDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPForDirective)
  MX_ENTER_VISIT_OMPForDirective
  MX_VISIT_BASE(OMPForDirective, OMPLoopDirective)
  MX_VISIT_ENTITY(OMPForDirective, task_reduction_reference_expression, 55, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPForDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPForDirective
MX_END_VISIT_STMT(OMPForDirective)

#ifndef MX_ENTER_VISIT_OMPDistributeSimdDirective
#  define MX_ENTER_VISIT_OMPDistributeSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPDistributeSimdDirective
#  define MX_EXIT_VISIT_OMPDistributeSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPDistributeSimdDirective)
  MX_ENTER_VISIT_OMPDistributeSimdDirective
  MX_VISIT_BASE(OMPDistributeSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPDistributeSimdDirective
MX_END_VISIT_STMT(OMPDistributeSimdDirective)

#ifndef MX_ENTER_VISIT_OMPDistributeParallelForSimdDirective
#  define MX_ENTER_VISIT_OMPDistributeParallelForSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPDistributeParallelForSimdDirective
#  define MX_EXIT_VISIT_OMPDistributeParallelForSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPDistributeParallelForSimdDirective)
  MX_ENTER_VISIT_OMPDistributeParallelForSimdDirective
  MX_VISIT_BASE(OMPDistributeParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPDistributeParallelForSimdDirective
MX_END_VISIT_STMT(OMPDistributeParallelForSimdDirective)

#ifndef MX_ENTER_VISIT_OMPDistributeParallelForDirective
#  define MX_ENTER_VISIT_OMPDistributeParallelForDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPDistributeParallelForDirective
#  define MX_EXIT_VISIT_OMPDistributeParallelForDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPDistributeParallelForDirective)
  MX_ENTER_VISIT_OMPDistributeParallelForDirective
  MX_VISIT_BASE(OMPDistributeParallelForDirective, OMPLoopDirective)
  MX_VISIT_ENTITY(OMPDistributeParallelForDirective, task_reduction_reference_expression, 55, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPDistributeParallelForDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPDistributeParallelForDirective
MX_END_VISIT_STMT(OMPDistributeParallelForDirective)

#ifndef MX_ENTER_VISIT_OMPDistributeDirective
#  define MX_ENTER_VISIT_OMPDistributeDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPDistributeDirective
#  define MX_EXIT_VISIT_OMPDistributeDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPDistributeDirective)
  MX_ENTER_VISIT_OMPDistributeDirective
  MX_VISIT_BASE(OMPDistributeDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPDistributeDirective
MX_END_VISIT_STMT(OMPDistributeDirective)

#ifndef MX_ENTER_VISIT_OMPTeamsDistributeSimdDirective
#  define MX_ENTER_VISIT_OMPTeamsDistributeSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTeamsDistributeSimdDirective
#  define MX_EXIT_VISIT_OMPTeamsDistributeSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTeamsDistributeSimdDirective)
  MX_ENTER_VISIT_OMPTeamsDistributeSimdDirective
  MX_VISIT_BASE(OMPTeamsDistributeSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTeamsDistributeSimdDirective
MX_END_VISIT_STMT(OMPTeamsDistributeSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTeamsDistributeParallelForSimdDirective
#  define MX_ENTER_VISIT_OMPTeamsDistributeParallelForSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTeamsDistributeParallelForSimdDirective
#  define MX_EXIT_VISIT_OMPTeamsDistributeParallelForSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTeamsDistributeParallelForSimdDirective)
  MX_ENTER_VISIT_OMPTeamsDistributeParallelForSimdDirective
  MX_VISIT_BASE(OMPTeamsDistributeParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTeamsDistributeParallelForSimdDirective
MX_END_VISIT_STMT(OMPTeamsDistributeParallelForSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTeamsDistributeParallelForDirective
#  define MX_ENTER_VISIT_OMPTeamsDistributeParallelForDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTeamsDistributeParallelForDirective
#  define MX_EXIT_VISIT_OMPTeamsDistributeParallelForDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTeamsDistributeParallelForDirective)
  MX_ENTER_VISIT_OMPTeamsDistributeParallelForDirective
  MX_VISIT_BASE(OMPTeamsDistributeParallelForDirective, OMPLoopDirective)
  MX_VISIT_ENTITY(OMPTeamsDistributeParallelForDirective, task_reduction_reference_expression, 55, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTeamsDistributeParallelForDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPTeamsDistributeParallelForDirective
MX_END_VISIT_STMT(OMPTeamsDistributeParallelForDirective)

#ifndef MX_ENTER_VISIT_OMPTeamsDistributeDirective
#  define MX_ENTER_VISIT_OMPTeamsDistributeDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTeamsDistributeDirective
#  define MX_EXIT_VISIT_OMPTeamsDistributeDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTeamsDistributeDirective)
  MX_ENTER_VISIT_OMPTeamsDistributeDirective
  MX_VISIT_BASE(OMPTeamsDistributeDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTeamsDistributeDirective
MX_END_VISIT_STMT(OMPTeamsDistributeDirective)

#ifndef MX_ENTER_VISIT_OMPTaskLoopSimdDirective
#  define MX_ENTER_VISIT_OMPTaskLoopSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTaskLoopSimdDirective
#  define MX_EXIT_VISIT_OMPTaskLoopSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTaskLoopSimdDirective)
  MX_ENTER_VISIT_OMPTaskLoopSimdDirective
  MX_VISIT_BASE(OMPTaskLoopSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTaskLoopSimdDirective
MX_END_VISIT_STMT(OMPTaskLoopSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTaskLoopDirective
#  define MX_ENTER_VISIT_OMPTaskLoopDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTaskLoopDirective
#  define MX_EXIT_VISIT_OMPTaskLoopDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTaskLoopDirective)
  MX_ENTER_VISIT_OMPTaskLoopDirective
  MX_VISIT_BASE(OMPTaskLoopDirective, OMPLoopDirective)
  MX_VISIT_BOOL(OMPTaskLoopDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPTaskLoopDirective
MX_END_VISIT_STMT(OMPTaskLoopDirective)

#ifndef MX_ENTER_VISIT_OMPTargetTeamsDistributeSimdDirective
#  define MX_ENTER_VISIT_OMPTargetTeamsDistributeSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetTeamsDistributeSimdDirective
#  define MX_EXIT_VISIT_OMPTargetTeamsDistributeSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetTeamsDistributeSimdDirective)
  MX_ENTER_VISIT_OMPTargetTeamsDistributeSimdDirective
  MX_VISIT_BASE(OMPTargetTeamsDistributeSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTargetTeamsDistributeSimdDirective
MX_END_VISIT_STMT(OMPTargetTeamsDistributeSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective
#  define MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective
#  define MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetTeamsDistributeParallelForSimdDirective)
  MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective
  MX_VISIT_BASE(OMPTargetTeamsDistributeParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective
MX_END_VISIT_STMT(OMPTargetTeamsDistributeParallelForSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForDirective
#  define MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForDirective
#  define MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetTeamsDistributeParallelForDirective)
  MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForDirective
  MX_VISIT_BASE(OMPTargetTeamsDistributeParallelForDirective, OMPLoopDirective)
  MX_VISIT_ENTITY(OMPTargetTeamsDistributeParallelForDirective, task_reduction_reference_expression, 55, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTargetTeamsDistributeParallelForDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForDirective
MX_END_VISIT_STMT(OMPTargetTeamsDistributeParallelForDirective)

#ifndef MX_ENTER_VISIT_OMPTargetTeamsDistributeDirective
#  define MX_ENTER_VISIT_OMPTargetTeamsDistributeDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetTeamsDistributeDirective
#  define MX_EXIT_VISIT_OMPTargetTeamsDistributeDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetTeamsDistributeDirective)
  MX_ENTER_VISIT_OMPTargetTeamsDistributeDirective
  MX_VISIT_BASE(OMPTargetTeamsDistributeDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTargetTeamsDistributeDirective
MX_END_VISIT_STMT(OMPTargetTeamsDistributeDirective)

#ifndef MX_ENTER_VISIT_OMPTargetSimdDirective
#  define MX_ENTER_VISIT_OMPTargetSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetSimdDirective
#  define MX_EXIT_VISIT_OMPTargetSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetSimdDirective)
  MX_ENTER_VISIT_OMPTargetSimdDirective
  MX_VISIT_BASE(OMPTargetSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTargetSimdDirective
MX_END_VISIT_STMT(OMPTargetSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTargetParallelForSimdDirective
#  define MX_ENTER_VISIT_OMPTargetParallelForSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetParallelForSimdDirective
#  define MX_EXIT_VISIT_OMPTargetParallelForSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetParallelForSimdDirective)
  MX_ENTER_VISIT_OMPTargetParallelForSimdDirective
  MX_VISIT_BASE(OMPTargetParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPTargetParallelForSimdDirective
MX_END_VISIT_STMT(OMPTargetParallelForSimdDirective)

#ifndef MX_ENTER_VISIT_OMPTargetParallelForDirective
#  define MX_ENTER_VISIT_OMPTargetParallelForDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTargetParallelForDirective
#  define MX_EXIT_VISIT_OMPTargetParallelForDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTargetParallelForDirective)
  MX_ENTER_VISIT_OMPTargetParallelForDirective
  MX_VISIT_BASE(OMPTargetParallelForDirective, OMPLoopDirective)
  MX_VISIT_ENTITY(OMPTargetParallelForDirective, task_reduction_reference_expression, 55, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTargetParallelForDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPTargetParallelForDirective
MX_END_VISIT_STMT(OMPTargetParallelForDirective)

#ifndef MX_ENTER_VISIT_OMPSimdDirective
#  define MX_ENTER_VISIT_OMPSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPSimdDirective
#  define MX_EXIT_VISIT_OMPSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPSimdDirective)
  MX_ENTER_VISIT_OMPSimdDirective
  MX_VISIT_BASE(OMPSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPSimdDirective
MX_END_VISIT_STMT(OMPSimdDirective)

#ifndef MX_ENTER_VISIT_OMPParallelMasterTaskLoopSimdDirective
#  define MX_ENTER_VISIT_OMPParallelMasterTaskLoopSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelMasterTaskLoopSimdDirective
#  define MX_EXIT_VISIT_OMPParallelMasterTaskLoopSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelMasterTaskLoopSimdDirective)
  MX_ENTER_VISIT_OMPParallelMasterTaskLoopSimdDirective
  MX_VISIT_BASE(OMPParallelMasterTaskLoopSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPParallelMasterTaskLoopSimdDirective
MX_END_VISIT_STMT(OMPParallelMasterTaskLoopSimdDirective)

#ifndef MX_ENTER_VISIT_OMPParallelMasterTaskLoopDirective
#  define MX_ENTER_VISIT_OMPParallelMasterTaskLoopDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelMasterTaskLoopDirective
#  define MX_EXIT_VISIT_OMPParallelMasterTaskLoopDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelMasterTaskLoopDirective)
  MX_ENTER_VISIT_OMPParallelMasterTaskLoopDirective
  MX_VISIT_BASE(OMPParallelMasterTaskLoopDirective, OMPLoopDirective)
  MX_VISIT_BOOL(OMPParallelMasterTaskLoopDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPParallelMasterTaskLoopDirective
MX_END_VISIT_STMT(OMPParallelMasterTaskLoopDirective)

#ifndef MX_ENTER_VISIT_OMPParallelForSimdDirective
#  define MX_ENTER_VISIT_OMPParallelForSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelForSimdDirective
#  define MX_EXIT_VISIT_OMPParallelForSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelForSimdDirective)
  MX_ENTER_VISIT_OMPParallelForSimdDirective
  MX_VISIT_BASE(OMPParallelForSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPParallelForSimdDirective
MX_END_VISIT_STMT(OMPParallelForSimdDirective)

#ifndef MX_ENTER_VISIT_OMPParallelForDirective
#  define MX_ENTER_VISIT_OMPParallelForDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPParallelForDirective
#  define MX_EXIT_VISIT_OMPParallelForDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPParallelForDirective)
  MX_ENTER_VISIT_OMPParallelForDirective
  MX_VISIT_BASE(OMPParallelForDirective, OMPLoopDirective)
  MX_VISIT_ENTITY(OMPParallelForDirective, task_reduction_reference_expression, 55, MX_APPLY_METHOD, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPParallelForDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPParallelForDirective
MX_END_VISIT_STMT(OMPParallelForDirective)

#ifndef MX_ENTER_VISIT_OMPMasterTaskLoopSimdDirective
#  define MX_ENTER_VISIT_OMPMasterTaskLoopSimdDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPMasterTaskLoopSimdDirective
#  define MX_EXIT_VISIT_OMPMasterTaskLoopSimdDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPMasterTaskLoopSimdDirective)
  MX_ENTER_VISIT_OMPMasterTaskLoopSimdDirective
  MX_VISIT_BASE(OMPMasterTaskLoopSimdDirective, OMPLoopDirective)
  MX_EXIT_VISIT_OMPMasterTaskLoopSimdDirective
MX_END_VISIT_STMT(OMPMasterTaskLoopSimdDirective)

#ifndef MX_ENTER_VISIT_OMPMasterTaskLoopDirective
#  define MX_ENTER_VISIT_OMPMasterTaskLoopDirective MX_ENTER_VISIT_OMPLoopDirective
#endif
#ifndef MX_EXIT_VISIT_OMPMasterTaskLoopDirective
#  define MX_EXIT_VISIT_OMPMasterTaskLoopDirective MX_EXIT_VISIT_OMPLoopDirective
#endif

MX_BEGIN_VISIT_STMT(OMPMasterTaskLoopDirective)
  MX_ENTER_VISIT_OMPMasterTaskLoopDirective
  MX_VISIT_BASE(OMPMasterTaskLoopDirective, OMPLoopDirective)
  MX_VISIT_BOOL(OMPMasterTaskLoopDirective, has_cancel, 20, MX_APPLY_METHOD, HasCancel, bool, NthStmt)
  MX_EXIT_VISIT_OMPMasterTaskLoopDirective
MX_END_VISIT_STMT(OMPMasterTaskLoopDirective)

#ifndef MX_ENTER_VISIT_OMPInteropDirective
#  define MX_ENTER_VISIT_OMPInteropDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPInteropDirective
#  define MX_EXIT_VISIT_OMPInteropDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPInteropDirective)
  MX_ENTER_VISIT_OMPInteropDirective
  MX_VISIT_BASE(OMPInteropDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPInteropDirective
MX_END_VISIT_STMT(OMPInteropDirective)

#ifndef MX_ENTER_VISIT_OMPFlushDirective
#  define MX_ENTER_VISIT_OMPFlushDirective MX_ENTER_VISIT_OMPExecutableDirective
#endif
#ifndef MX_EXIT_VISIT_OMPFlushDirective
#  define MX_EXIT_VISIT_OMPFlushDirective MX_EXIT_VISIT_OMPExecutableDirective
#endif

MX_BEGIN_VISIT_STMT(OMPFlushDirective)
  MX_ENTER_VISIT_OMPFlushDirective
  MX_VISIT_BASE(OMPFlushDirective, OMPExecutableDirective)
  MX_EXIT_VISIT_OMPFlushDirective
MX_END_VISIT_STMT(OMPFlushDirective)

#ifndef MX_ENTER_VISIT_OMPCanonicalLoop
#  define MX_ENTER_VISIT_OMPCanonicalLoop MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_OMPCanonicalLoop
#  define MX_EXIT_VISIT_OMPCanonicalLoop MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(OMPCanonicalLoop)
  MX_ENTER_VISIT_OMPCanonicalLoop
  MX_VISIT_BASE(OMPCanonicalLoop, Stmt)
  MX_VISIT_ENTITY(OMPCanonicalLoop, distance_func, 9, MX_APPLY_METHOD, DistanceFunc, CapturedStmt, NthStmt, StmtUseSelector::DISTANCE_FUNC)
  MX_VISIT_ENTITY(OMPCanonicalLoop, loop_statement, 10, MX_APPLY_METHOD, LoopStatement, Stmt, NthStmt, StmtUseSelector::LOOP_STATEMENT)
  MX_VISIT_ENTITY(OMPCanonicalLoop, loop_variable_func, 11, MX_APPLY_METHOD, LoopVariableFunc, CapturedStmt, NthStmt, StmtUseSelector::LOOP_VARIABLE_FUNC)
  MX_VISIT_ENTITY(OMPCanonicalLoop, loop_variable_reference, 13, MX_APPLY_METHOD, LoopVariableReference, DeclRefExpr, NthStmt, StmtUseSelector::LOOP_VARIABLE_REFERENCE)
  MX_EXIT_VISIT_OMPCanonicalLoop
MX_END_VISIT_STMT(OMPCanonicalLoop)

#ifndef MX_ENTER_VISIT_NullStmt
#  define MX_ENTER_VISIT_NullStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_NullStmt
#  define MX_EXIT_VISIT_NullStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(NullStmt)
  MX_ENTER_VISIT_NullStmt
  MX_VISIT_BASE(NullStmt, Stmt)
  MX_VISIT_ENTITY(NullStmt, semi_token, 9, MX_APPLY_METHOD, SemiToken, Token, NthStmt, TokenUseSelector::SEMI_TOKEN)
  MX_VISIT_BOOL(NullStmt, has_leading_empty_macro, 12, MX_APPLY_METHOD, HasLeadingEmptyMacro, bool, NthStmt)
  MX_EXIT_VISIT_NullStmt
MX_END_VISIT_STMT(NullStmt)

#ifndef MX_ENTER_VISIT_MSDependentExistsStmt
#  define MX_ENTER_VISIT_MSDependentExistsStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_MSDependentExistsStmt
#  define MX_EXIT_VISIT_MSDependentExistsStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(MSDependentExistsStmt)
  MX_ENTER_VISIT_MSDependentExistsStmt
  MX_VISIT_BASE(MSDependentExistsStmt, Stmt)
  MX_VISIT_ENTITY(MSDependentExistsStmt, keyword_token, 9, MX_APPLY_METHOD, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(MSDependentExistsStmt, sub_statement, 10, MX_APPLY_METHOD, SubStatement, CompoundStmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_VISIT_BOOL(MSDependentExistsStmt, is_if_exists, 12, MX_APPLY_METHOD, IsIfExists, bool, NthStmt)
  MX_VISIT_BOOL(MSDependentExistsStmt, is_if_not_exists, 15, MX_APPLY_METHOD, IsIfNotExists, bool, NthStmt)
  MX_EXIT_VISIT_MSDependentExistsStmt
MX_END_VISIT_STMT(MSDependentExistsStmt)

#ifndef MX_ENTER_VISIT_IndirectGotoStmt
#  define MX_ENTER_VISIT_IndirectGotoStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_IndirectGotoStmt
#  define MX_EXIT_VISIT_IndirectGotoStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(IndirectGotoStmt)
  MX_ENTER_VISIT_IndirectGotoStmt
  MX_VISIT_BASE(IndirectGotoStmt, Stmt)
  MX_VISIT_OPTIONAL_ENTITY(IndirectGotoStmt, constant_target, 9, MX_APPLY_METHOD, ConstantTarget, LabelDecl, NthStmt, DeclUseSelector::CONSTANT_TARGET)
  MX_VISIT_ENTITY(IndirectGotoStmt, goto_token, 10, MX_APPLY_METHOD, GotoToken, Token, NthStmt, TokenUseSelector::GOTO_TOKEN)
  MX_VISIT_ENTITY(IndirectGotoStmt, star_token, 11, MX_APPLY_METHOD, StarToken, Token, NthStmt, TokenUseSelector::STAR_TOKEN)
  MX_VISIT_ENTITY(IndirectGotoStmt, target, 13, MX_APPLY_METHOD, Target, Expr, NthStmt, StmtUseSelector::TARGET)
  MX_EXIT_VISIT_IndirectGotoStmt
MX_END_VISIT_STMT(IndirectGotoStmt)

#ifndef MX_ENTER_VISIT_IfStmt
#  define MX_ENTER_VISIT_IfStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_IfStmt
#  define MX_EXIT_VISIT_IfStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(IfStmt)
  MX_ENTER_VISIT_IfStmt
  MX_VISIT_BASE(IfStmt, Stmt)
  MX_VISIT_ENTITY(IfStmt, condition, 9, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, condition_variable, 10, MX_APPLY_METHOD, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, condition_variable_declaration_statement, 11, MX_APPLY_METHOD, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, else_, 13, MX_APPLY_METHOD, Else, Stmt, NthStmt, StmtUseSelector::ELSE_)
  MX_VISIT_ENTITY(IfStmt, else_token, 14, MX_APPLY_METHOD, ElseToken, Token, NthStmt, TokenUseSelector::ELSE_TOKEN)
  MX_VISIT_ENTITY(IfStmt, if_token, 17, MX_APPLY_METHOD, IfToken, Token, NthStmt, TokenUseSelector::IF_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, initializer, 18, MX_APPLY_METHOD, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(IfStmt, l_paren_token, 19, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(IfStmt, r_paren_token, 26, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENUM(IfStmt, statement_kind, 56, MX_APPLY_METHOD, StatementKind, IfStatementKind, NthStmt)
  MX_VISIT_ENTITY(IfStmt, then, 27, MX_APPLY_METHOD, Then, Stmt, NthStmt, StmtUseSelector::THEN)
  MX_VISIT_BOOL(IfStmt, has_else_storage, 57, MX_APPLY_METHOD, HasElseStorage, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, has_initializer_storage, 58, MX_APPLY_METHOD, HasInitializerStorage, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, has_variable_storage, 59, MX_APPLY_METHOD, HasVariableStorage, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_consteval, 60, MX_APPLY_METHOD, IsConsteval, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_constexpr, 61, MX_APPLY_METHOD, IsConstexpr, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_negated_consteval, 62, MX_APPLY_METHOD, IsNegatedConsteval, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_non_negated_consteval, 63, MX_APPLY_METHOD, IsNonNegatedConsteval, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_obj_c_availability_check, 64, MX_APPLY_METHOD, IsObjCAvailabilityCheck, bool, NthStmt)
  MX_EXIT_VISIT_IfStmt
MX_END_VISIT_STMT(IfStmt)

#ifndef MX_ENTER_VISIT_GotoStmt
#  define MX_ENTER_VISIT_GotoStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_GotoStmt
#  define MX_EXIT_VISIT_GotoStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(GotoStmt)
  MX_ENTER_VISIT_GotoStmt
  MX_VISIT_BASE(GotoStmt, Stmt)
  MX_VISIT_ENTITY(GotoStmt, goto_token, 9, MX_APPLY_METHOD, GotoToken, Token, NthStmt, TokenUseSelector::GOTO_TOKEN)
  MX_VISIT_ENTITY(GotoStmt, label, 10, MX_APPLY_METHOD, Label, LabelDecl, NthStmt, DeclUseSelector::LABEL)
  MX_VISIT_ENTITY(GotoStmt, label_token, 11, MX_APPLY_METHOD, LabelToken, Token, NthStmt, TokenUseSelector::LABEL_TOKEN)
  MX_EXIT_VISIT_GotoStmt
MX_END_VISIT_STMT(GotoStmt)

#ifndef MX_ENTER_VISIT_ForStmt
#  define MX_ENTER_VISIT_ForStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ForStmt
#  define MX_EXIT_VISIT_ForStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ForStmt)
  MX_ENTER_VISIT_ForStmt
  MX_VISIT_BASE(ForStmt, Stmt)
  MX_VISIT_ENTITY(ForStmt, body, 9, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, condition, 10, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, condition_variable, 11, MX_APPLY_METHOD, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, condition_variable_declaration_statement, 13, MX_APPLY_METHOD, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_ENTITY(ForStmt, for_token, 14, MX_APPLY_METHOD, ForToken, Token, NthStmt, TokenUseSelector::FOR_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, increment, 17, MX_APPLY_METHOD, Increment, Expr, NthStmt, StmtUseSelector::INCREMENT)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, initializer, 18, MX_APPLY_METHOD, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(ForStmt, l_paren_token, 19, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(ForStmt, r_paren_token, 26, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_ForStmt
MX_END_VISIT_STMT(ForStmt)

#ifndef MX_ENTER_VISIT_DoStmt
#  define MX_ENTER_VISIT_DoStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_DoStmt
#  define MX_EXIT_VISIT_DoStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(DoStmt)
  MX_ENTER_VISIT_DoStmt
  MX_VISIT_BASE(DoStmt, Stmt)
  MX_VISIT_ENTITY(DoStmt, body, 9, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(DoStmt, condition, 10, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(DoStmt, do_token, 11, MX_APPLY_METHOD, DoToken, Token, NthStmt, TokenUseSelector::DO_TOKEN)
  MX_VISIT_ENTITY(DoStmt, r_paren_token, 13, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(DoStmt, while_token, 14, MX_APPLY_METHOD, WhileToken, Token, NthStmt, TokenUseSelector::WHILE_TOKEN)
  MX_EXIT_VISIT_DoStmt
MX_END_VISIT_STMT(DoStmt)

#ifndef MX_ENTER_VISIT_DeclStmt
#  define MX_ENTER_VISIT_DeclStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_DeclStmt
#  define MX_EXIT_VISIT_DeclStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(DeclStmt)
  MX_ENTER_VISIT_DeclStmt
  MX_VISIT_BASE(DeclStmt, Stmt)
  MX_VISIT_ENTITY_LIST(DeclStmt, declarations, 16, MX_APPLY_METHOD, Declarations, Decl, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(DeclStmt, single_declaration, 9, MX_APPLY_METHOD, SingleDeclaration, Decl, NthStmt, DeclUseSelector::SINGLE_DECLARATION)
  MX_VISIT_BOOL(DeclStmt, is_single_declaration, 15, MX_APPLY_METHOD, IsSingleDeclaration, bool, NthStmt)
  MX_EXIT_VISIT_DeclStmt
MX_END_VISIT_STMT(DeclStmt)

#ifndef MX_ENTER_VISIT_CoroutineBodyStmt
#  define MX_ENTER_VISIT_CoroutineBodyStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CoroutineBodyStmt
#  define MX_EXIT_VISIT_CoroutineBodyStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CoroutineBodyStmt)
  MX_ENTER_VISIT_CoroutineBodyStmt
  MX_VISIT_BASE(CoroutineBodyStmt, Stmt)
  MX_VISIT_ENTITY(CoroutineBodyStmt, allocate, 9, MX_APPLY_METHOD, Allocate, Expr, NthStmt, StmtUseSelector::ALLOCATE)
  MX_VISIT_ENTITY(CoroutineBodyStmt, body, 10, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(CoroutineBodyStmt, deallocate, 11, MX_APPLY_METHOD, Deallocate, Expr, NthStmt, StmtUseSelector::DEALLOCATE)
  MX_VISIT_ENTITY(CoroutineBodyStmt, exception_handler, 13, MX_APPLY_METHOD, ExceptionHandler, Stmt, NthStmt, StmtUseSelector::EXCEPTION_HANDLER)
  MX_VISIT_ENTITY(CoroutineBodyStmt, fallthrough_handler, 14, MX_APPLY_METHOD, FallthroughHandler, Stmt, NthStmt, StmtUseSelector::FALLTHROUGH_HANDLER)
  MX_VISIT_ENTITY(CoroutineBodyStmt, final_suspend_statement, 17, MX_APPLY_METHOD, FinalSuspendStatement, Stmt, NthStmt, StmtUseSelector::FINAL_SUSPEND_STATEMENT)
  MX_VISIT_ENTITY(CoroutineBodyStmt, initializer_suspend_statement, 18, MX_APPLY_METHOD, InitializerSuspendStatement, Stmt, NthStmt, StmtUseSelector::INITIALIZER_SUSPEND_STATEMENT)
  MX_VISIT_ENTITY_LIST(CoroutineBodyStmt, parameter_moves, 16, MX_APPLY_METHOD, ParameterMoves, Stmt, NthStmt)
  MX_VISIT_ENTITY(CoroutineBodyStmt, promise_declaration, 19, MX_APPLY_METHOD, PromiseDeclaration, VarDecl, NthStmt, DeclUseSelector::PROMISE_DECLARATION)
  MX_VISIT_ENTITY(CoroutineBodyStmt, promise_declaration_statement, 26, MX_APPLY_METHOD, PromiseDeclarationStatement, Stmt, NthStmt, StmtUseSelector::PROMISE_DECLARATION_STATEMENT)
  MX_VISIT_ENTITY(CoroutineBodyStmt, result_declaration, 27, MX_APPLY_METHOD, ResultDeclaration, Stmt, NthStmt, StmtUseSelector::RESULT_DECLARATION)
  MX_VISIT_ENTITY(CoroutineBodyStmt, return_statement, 28, MX_APPLY_METHOD, ReturnStatement, Stmt, NthStmt, StmtUseSelector::RETURN_STATEMENT)
  MX_VISIT_ENTITY(CoroutineBodyStmt, return_statement_on_alloc_failure, 29, MX_APPLY_METHOD, ReturnStatementOnAllocFailure, Stmt, NthStmt, StmtUseSelector::RETURN_STATEMENT_ON_ALLOC_FAILURE)
  MX_VISIT_ENTITY(CoroutineBodyStmt, return_value_initializer, 30, MX_APPLY_METHOD, ReturnValueInitializer, Expr, NthStmt, StmtUseSelector::RETURN_VALUE_INITIALIZER)
  MX_VISIT_BOOL(CoroutineBodyStmt, has_dependent_promise_type, 12, MX_APPLY_METHOD, HasDependentPromiseType, bool, NthStmt)
  MX_EXIT_VISIT_CoroutineBodyStmt
MX_END_VISIT_STMT(CoroutineBodyStmt)

#ifndef MX_ENTER_VISIT_CoreturnStmt
#  define MX_ENTER_VISIT_CoreturnStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CoreturnStmt
#  define MX_EXIT_VISIT_CoreturnStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CoreturnStmt)
  MX_ENTER_VISIT_CoreturnStmt
  MX_VISIT_BASE(CoreturnStmt, Stmt)
  MX_VISIT_ENTITY(CoreturnStmt, keyword_token, 9, MX_APPLY_METHOD, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(CoreturnStmt, operand, 10, MX_APPLY_METHOD, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_ENTITY(CoreturnStmt, promise_call, 11, MX_APPLY_METHOD, PromiseCall, Expr, NthStmt, StmtUseSelector::PROMISE_CALL)
  MX_VISIT_BOOL(CoreturnStmt, is_implicit, 12, MX_APPLY_METHOD, IsImplicit, bool, NthStmt)
  MX_EXIT_VISIT_CoreturnStmt
MX_END_VISIT_STMT(CoreturnStmt)

#ifndef MX_ENTER_VISIT_ContinueStmt
#  define MX_ENTER_VISIT_ContinueStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ContinueStmt
#  define MX_EXIT_VISIT_ContinueStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(ContinueStmt)
  MX_ENTER_VISIT_ContinueStmt
  MX_VISIT_BASE(ContinueStmt, Stmt)
  MX_VISIT_ENTITY(ContinueStmt, continue_token, 9, MX_APPLY_METHOD, ContinueToken, Token, NthStmt, TokenUseSelector::CONTINUE_TOKEN)
  MX_EXIT_VISIT_ContinueStmt
MX_END_VISIT_STMT(ContinueStmt)

#ifndef MX_ENTER_VISIT_CompoundStmt
#  define MX_ENTER_VISIT_CompoundStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CompoundStmt
#  define MX_EXIT_VISIT_CompoundStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CompoundStmt)
  MX_ENTER_VISIT_CompoundStmt
  MX_VISIT_BASE(CompoundStmt, Stmt)
  MX_VISIT_ENTITY(CompoundStmt, left_brace_token, 9, MX_APPLY_METHOD, LeftBraceToken, Token, NthStmt, TokenUseSelector::LEFT_BRACE_TOKEN)
  MX_VISIT_ENTITY(CompoundStmt, right_brace_token, 10, MX_APPLY_METHOD, RightBraceToken, Token, NthStmt, TokenUseSelector::RIGHT_BRACE_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(CompoundStmt, statement_expression_result, 11, MX_APPLY_METHOD, StatementExpressionResult, Stmt, NthStmt, StmtUseSelector::STATEMENT_EXPRESSION_RESULT)
  MX_EXIT_VISIT_CompoundStmt
MX_END_VISIT_STMT(CompoundStmt)

#ifndef MX_ENTER_VISIT_CapturedStmt
#  define MX_ENTER_VISIT_CapturedStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CapturedStmt
#  define MX_EXIT_VISIT_CapturedStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CapturedStmt)
  MX_ENTER_VISIT_CapturedStmt
  MX_VISIT_BASE(CapturedStmt, Stmt)
  MX_VISIT_ENTITY(CapturedStmt, captured_declaration, 9, MX_APPLY_METHOD, CapturedDeclaration, CapturedDecl, NthStmt, DeclUseSelector::CAPTURED_DECLARATION)
  MX_VISIT_ENTITY(CapturedStmt, captured_record_declaration, 10, MX_APPLY_METHOD, CapturedRecordDeclaration, RecordDecl, NthStmt, DeclUseSelector::CAPTURED_RECORD_DECLARATION)
  MX_VISIT_ENUM(CapturedStmt, captured_region_kind, 56, MX_APPLY_METHOD, CapturedRegionKind, CapturedRegionKind, NthStmt)
  MX_VISIT_ENTITY(CapturedStmt, captured_statement, 11, MX_APPLY_METHOD, CapturedStatement, Stmt, NthStmt, StmtUseSelector::CAPTURED_STATEMENT)
  MX_EXIT_VISIT_CapturedStmt
MX_END_VISIT_STMT(CapturedStmt)

#ifndef MX_ENTER_VISIT_CXXTryStmt
#  define MX_ENTER_VISIT_CXXTryStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CXXTryStmt
#  define MX_EXIT_VISIT_CXXTryStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CXXTryStmt)
  MX_ENTER_VISIT_CXXTryStmt
  MX_VISIT_BASE(CXXTryStmt, Stmt)
  MX_VISIT_ENTITY(CXXTryStmt, try_block, 9, MX_APPLY_METHOD, TryBlock, CompoundStmt, NthStmt, StmtUseSelector::TRY_BLOCK)
  MX_VISIT_ENTITY(CXXTryStmt, try_token, 10, MX_APPLY_METHOD, TryToken, Token, NthStmt, TokenUseSelector::TRY_TOKEN)
  MX_VISIT_ENTITY_LIST(CXXTryStmt, handlers, 16, MX_APPLY_METHOD, Handlers, CXXCatchStmt, NthStmt)
  MX_EXIT_VISIT_CXXTryStmt
MX_END_VISIT_STMT(CXXTryStmt)

#ifndef MX_ENTER_VISIT_CXXForRangeStmt
#  define MX_ENTER_VISIT_CXXForRangeStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CXXForRangeStmt
#  define MX_EXIT_VISIT_CXXForRangeStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CXXForRangeStmt)
  MX_ENTER_VISIT_CXXForRangeStmt
  MX_VISIT_BASE(CXXForRangeStmt, Stmt)
  MX_VISIT_ENTITY(CXXForRangeStmt, begin_statement, 9, MX_APPLY_METHOD, BeginStatement, DeclStmt, NthStmt, StmtUseSelector::BEGIN_STATEMENT)
  MX_VISIT_ENTITY(CXXForRangeStmt, body, 10, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(CXXForRangeStmt, coawait_token, 11, MX_APPLY_METHOD, CoawaitToken, Token, NthStmt, TokenUseSelector::COAWAIT_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, colon_token, 13, MX_APPLY_METHOD, ColonToken, Token, NthStmt, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, condition, 14, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(CXXForRangeStmt, end_statement, 17, MX_APPLY_METHOD, EndStatement, DeclStmt, NthStmt, StmtUseSelector::END_STATEMENT)
  MX_VISIT_ENTITY(CXXForRangeStmt, for_token, 18, MX_APPLY_METHOD, ForToken, Token, NthStmt, TokenUseSelector::FOR_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, increment, 19, MX_APPLY_METHOD, Increment, Expr, NthStmt, StmtUseSelector::INCREMENT)
  MX_VISIT_OPTIONAL_ENTITY(CXXForRangeStmt, initializer, 26, MX_APPLY_METHOD, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CXXForRangeStmt, loop_variable_statement, 27, MX_APPLY_METHOD, LoopVariableStatement, DeclStmt, NthStmt, StmtUseSelector::LOOP_VARIABLE_STATEMENT)
  MX_VISIT_ENTITY(CXXForRangeStmt, loop_variable, 28, MX_APPLY_METHOD, LoopVariable, VarDecl, NthStmt, DeclUseSelector::LOOP_VARIABLE)
  MX_VISIT_ENTITY(CXXForRangeStmt, r_paren_token, 29, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, range_initializer, 30, MX_APPLY_METHOD, RangeInitializer, Expr, NthStmt, StmtUseSelector::RANGE_INITIALIZER)
  MX_VISIT_ENTITY(CXXForRangeStmt, range_statement, 31, MX_APPLY_METHOD, RangeStatement, DeclStmt, NthStmt, StmtUseSelector::RANGE_STATEMENT)
  MX_EXIT_VISIT_CXXForRangeStmt
MX_END_VISIT_STMT(CXXForRangeStmt)

#ifndef MX_ENTER_VISIT_CXXCatchStmt
#  define MX_ENTER_VISIT_CXXCatchStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_CXXCatchStmt
#  define MX_EXIT_VISIT_CXXCatchStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(CXXCatchStmt)
  MX_ENTER_VISIT_CXXCatchStmt
  MX_VISIT_BASE(CXXCatchStmt, Stmt)
  MX_VISIT_ENTITY(CXXCatchStmt, catch_token, 9, MX_APPLY_METHOD, CatchToken, Token, NthStmt, TokenUseSelector::CATCH_TOKEN)
  MX_VISIT_ENTITY(CXXCatchStmt, caught_type, 10, MX_APPLY_METHOD, CaughtType, Type, NthStmt, TypeUseSelector::CAUGHT_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXCatchStmt, exception_declaration, 11, MX_APPLY_METHOD, ExceptionDeclaration, VarDecl, NthStmt, DeclUseSelector::EXCEPTION_DECLARATION)
  MX_VISIT_ENTITY(CXXCatchStmt, handler_block, 13, MX_APPLY_METHOD, HandlerBlock, Stmt, NthStmt, StmtUseSelector::HANDLER_BLOCK)
  MX_EXIT_VISIT_CXXCatchStmt
MX_END_VISIT_STMT(CXXCatchStmt)

#ifndef MX_ENTER_VISIT_BreakStmt
#  define MX_ENTER_VISIT_BreakStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_BreakStmt
#  define MX_EXIT_VISIT_BreakStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(BreakStmt)
  MX_ENTER_VISIT_BreakStmt
  MX_VISIT_BASE(BreakStmt, Stmt)
  MX_VISIT_ENTITY(BreakStmt, break_token, 9, MX_APPLY_METHOD, BreakToken, Token, NthStmt, TokenUseSelector::BREAK_TOKEN)
  MX_EXIT_VISIT_BreakStmt
MX_END_VISIT_STMT(BreakStmt)

#ifndef MX_ENTER_VISIT_AsmStmt
#  define MX_ENTER_VISIT_AsmStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_AsmStmt
#  define MX_EXIT_VISIT_AsmStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(AsmStmt)
  MX_ENTER_VISIT_AsmStmt
  MX_VISIT_BASE(AsmStmt, Stmt)
  MX_VISIT_TEXT(AsmStmt, generate_assembly_string, 65, MX_APPLY_METHOD, GenerateAssemblyString, basic_string, NthStmt)
  MX_VISIT_ENTITY(AsmStmt, assembly_token, 9, MX_APPLY_METHOD, AssemblyToken, Token, NthStmt, TokenUseSelector::ASSEMBLY_TOKEN)
  MX_VISIT_ENTITY_LIST(AsmStmt, inputs, 16, MX_APPLY_METHOD, Inputs, Expr, NthStmt)
  MX_VISIT_BOOL(AsmStmt, is_simple, 12, MX_APPLY_METHOD, IsSimple, bool, NthStmt)
  MX_VISIT_BOOL(AsmStmt, is_volatile, 15, MX_APPLY_METHOD, IsVolatile, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(AsmStmt, outputs, 22, MX_APPLY_METHOD, Outputs, Expr, NthStmt)
  MX_VISIT_TEXT_LIST(AsmStmt, output_constraints, 66, MX_APPLY_METHOD, OutputConstraints, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(AsmStmt, output_expressions, 23, MX_APPLY_METHOD, OutputExpressions, Expr, NthStmt)
  MX_VISIT_TEXT_LIST(AsmStmt, input_constraints, 67, MX_APPLY_METHOD, InputConstraints, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(AsmStmt, input_expressions, 24, MX_APPLY_METHOD, InputExpressions, Expr, NthStmt)
  MX_VISIT_TEXT_LIST(AsmStmt, clobbers, 68, MX_APPLY_METHOD, Clobbers, basic_string_view, NthStmt)
  MX_EXIT_VISIT_AsmStmt
MX_END_VISIT_STMT(AsmStmt)

#ifndef MX_ENTER_VISIT_MSAsmStmt
#  define MX_ENTER_VISIT_MSAsmStmt MX_ENTER_VISIT_AsmStmt
#endif
#ifndef MX_EXIT_VISIT_MSAsmStmt
#  define MX_EXIT_VISIT_MSAsmStmt MX_EXIT_VISIT_AsmStmt
#endif

MX_BEGIN_VISIT_STMT(MSAsmStmt)
  MX_ENTER_VISIT_MSAsmStmt
  MX_VISIT_BASE(MSAsmStmt, AsmStmt)
  MX_VISIT_TEXT_LIST(MSAsmStmt, all_constraints, 69, MX_APPLY_METHOD, AllConstraints, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(MSAsmStmt, all_expressions, 25, MX_APPLY_METHOD, AllExpressions, Expr, NthStmt)
  MX_VISIT_TEXT(MSAsmStmt, assembly_string, 70, MX_APPLY_METHOD, AssemblyString, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(MSAsmStmt, l_brace_token, 10, MX_APPLY_METHOD, LBraceToken, Token, NthStmt, TokenUseSelector::L_BRACE_TOKEN)
  MX_VISIT_BOOL(MSAsmStmt, has_braces, 20, MX_APPLY_METHOD, HasBraces, bool, NthStmt)
  MX_EXIT_VISIT_MSAsmStmt
MX_END_VISIT_STMT(MSAsmStmt)

#ifndef MX_ENTER_VISIT_GCCAsmStmt
#  define MX_ENTER_VISIT_GCCAsmStmt MX_ENTER_VISIT_AsmStmt
#endif
#ifndef MX_EXIT_VISIT_GCCAsmStmt
#  define MX_EXIT_VISIT_GCCAsmStmt MX_EXIT_VISIT_AsmStmt
#endif

MX_BEGIN_VISIT_STMT(GCCAsmStmt)
  MX_ENTER_VISIT_GCCAsmStmt
  MX_VISIT_BASE(GCCAsmStmt, AsmStmt)
  MX_VISIT_ENTITY(GCCAsmStmt, assembly_string, 10, MX_APPLY_METHOD, AssemblyString, StringLiteral, NthStmt, StmtUseSelector::ASSEMBLY_STRING)
  MX_VISIT_ENTITY(GCCAsmStmt, r_paren_token, 11, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(GCCAsmStmt, is_assembly_goto, 20, MX_APPLY_METHOD, IsAssemblyGoto, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, labels, 25, MX_APPLY_METHOD, Labels, AddrLabelExpr, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, output_constraint_literals, 52, MX_APPLY_METHOD, OutputConstraintLiterals, StringLiteral, NthStmt)
  MX_VISIT_TEXT_LIST(GCCAsmStmt, output_names, 69, MX_APPLY_METHOD, OutputNames, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, input_constraint_literals, 53, MX_APPLY_METHOD, InputConstraintLiterals, StringLiteral, NthStmt)
  MX_VISIT_TEXT_LIST(GCCAsmStmt, input_names, 71, MX_APPLY_METHOD, InputNames, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, clobber_string_literals, 54, MX_APPLY_METHOD, ClobberStringLiterals, StringLiteral, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, label_expressions, 72, MX_APPLY_METHOD, LabelExpressions, AddrLabelExpr, NthStmt)
  MX_VISIT_TEXT_LIST(GCCAsmStmt, label_names, 73, MX_APPLY_METHOD, LabelNames, basic_string_view, NthStmt)
  MX_EXIT_VISIT_GCCAsmStmt
MX_END_VISIT_STMT(GCCAsmStmt)

#ifndef MX_ENTER_VISIT_WhileStmt
#  define MX_ENTER_VISIT_WhileStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_WhileStmt
#  define MX_EXIT_VISIT_WhileStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(WhileStmt)
  MX_ENTER_VISIT_WhileStmt
  MX_VISIT_BASE(WhileStmt, Stmt)
  MX_VISIT_ENTITY(WhileStmt, body, 9, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(WhileStmt, condition, 10, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(WhileStmt, condition_variable, 11, MX_APPLY_METHOD, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(WhileStmt, condition_variable_declaration_statement, 13, MX_APPLY_METHOD, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_ENTITY(WhileStmt, l_paren_token, 14, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(WhileStmt, r_paren_token, 17, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(WhileStmt, while_token, 18, MX_APPLY_METHOD, WhileToken, Token, NthStmt, TokenUseSelector::WHILE_TOKEN)
  MX_VISIT_BOOL(WhileStmt, has_variable_storage, 20, MX_APPLY_METHOD, HasVariableStorage, bool, NthStmt)
  MX_EXIT_VISIT_WhileStmt
MX_END_VISIT_STMT(WhileStmt)

#ifndef MX_ENTER_VISIT_ValueStmt
#  define MX_ENTER_VISIT_ValueStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_ValueStmt
#  define MX_EXIT_VISIT_ValueStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(ValueStmt)
  MX_ENTER_VISIT_ValueStmt
  MX_VISIT_BASE(ValueStmt, Stmt)
  MX_VISIT_OPTIONAL_ENTITY(ValueStmt, expression_statement, 9, MX_APPLY_METHOD, ExpressionStatement, Expr, NthStmt, StmtUseSelector::EXPRESSION_STATEMENT)
  MX_EXIT_VISIT_ValueStmt
MX_END_VISIT_STMT(ValueStmt)

#ifndef MX_ENTER_VISIT_LabelStmt
#  define MX_ENTER_VISIT_LabelStmt MX_ENTER_VISIT_ValueStmt
#endif
#ifndef MX_EXIT_VISIT_LabelStmt
#  define MX_EXIT_VISIT_LabelStmt MX_EXIT_VISIT_ValueStmt
#endif

MX_BEGIN_VISIT_STMT(LabelStmt)
  MX_ENTER_VISIT_LabelStmt
  MX_VISIT_BASE(LabelStmt, ValueStmt)
  MX_VISIT_ENTITY(LabelStmt, declaration, 10, MX_APPLY_METHOD, Declaration, LabelDecl, NthStmt, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(LabelStmt, identifier_token, 11, MX_APPLY_METHOD, IdentifierToken, Token, NthStmt, TokenUseSelector::IDENTIFIER_TOKEN)
  MX_VISIT_TEXT(LabelStmt, name, 65, MX_APPLY_METHOD, Name, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(LabelStmt, sub_statement, 13, MX_APPLY_METHOD, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_VISIT_BOOL(LabelStmt, is_side_entry, 15, MX_APPLY_METHOD, IsSideEntry, bool, NthStmt)
  MX_EXIT_VISIT_LabelStmt
MX_END_VISIT_STMT(LabelStmt)

#ifndef MX_ENTER_VISIT_Expr
#  define MX_ENTER_VISIT_Expr MX_ENTER_VISIT_ValueStmt
#endif
#ifndef MX_EXIT_VISIT_Expr
#  define MX_EXIT_VISIT_Expr MX_EXIT_VISIT_ValueStmt
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(Expr)
  MX_ENTER_VISIT_Expr
  MX_VISIT_BASE(Expr, ValueStmt)
  MX_VISIT_BOOL(Expr, has_side_effects, 15, MX_APPLY_METHOD, HasSideEffects, bool, NthStmt)
  MX_VISIT_ENTITY(Expr, ignore_casts, 10, MX_APPLY_METHOD, IgnoreCasts, Expr, NthStmt, StmtUseSelector::IGNORE_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_conversion_operator_single_step, 11, MX_APPLY_METHOD, IgnoreConversionOperatorSingleStep, Expr, NthStmt, StmtUseSelector::IGNORE_CONVERSION_OPERATOR_SINGLE_STEP)
  MX_VISIT_ENTITY(Expr, ignore_imp_casts, 13, MX_APPLY_METHOD, IgnoreImpCasts, Expr, NthStmt, StmtUseSelector::IGNORE_IMP_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_implicit, 14, MX_APPLY_METHOD, IgnoreImplicit, Expr, NthStmt, StmtUseSelector::IGNORE_IMPLICIT)
  MX_VISIT_ENTITY(Expr, ignore_implicit_as_written, 17, MX_APPLY_METHOD, IgnoreImplicitAsWritten, Expr, NthStmt, StmtUseSelector::IGNORE_IMPLICIT_AS_WRITTEN)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_base_casts, 18, MX_APPLY_METHOD, IgnoreParenthesisBaseCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_BASE_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_casts, 19, MX_APPLY_METHOD, IgnoreParenthesisCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_imp_casts, 26, MX_APPLY_METHOD, IgnoreParenthesisImpCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_IMP_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_l_value_casts, 27, MX_APPLY_METHOD, IgnoreParenthesisLValueCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_L_VALUE_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_noop_casts, 28, MX_APPLY_METHOD, IgnoreParenthesisNoopCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_NOOP_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parentheses, 29, MX_APPLY_METHOD, IgnoreParentheses, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESES)
  MX_VISIT_ENTITY(Expr, ignore_unless_spelled_in_source, 30, MX_APPLY_METHOD, IgnoreUnlessSpelledInSource, Expr, NthStmt, StmtUseSelector::IGNORE_UNLESS_SPELLED_IN_SOURCE)
  MX_VISIT_BOOL(Expr, contains_errors, 20, MX_APPLY_METHOD, ContainsErrors, bool, NthStmt)
  MX_VISIT_BOOL(Expr, contains_unexpanded_parameter_pack, 21, MX_APPLY_METHOD, ContainsUnexpandedParameterPack, bool, NthStmt)
  MX_VISIT_ENTITY(Expr, best_dynamic_class_type_expression, 31, MX_APPLY_METHOD, BestDynamicClassTypeExpression, Expr, NthStmt, StmtUseSelector::BEST_DYNAMIC_CLASS_TYPE_EXPRESSION)
  MX_VISIT_ENTITY(Expr, expression_token, 32, MX_APPLY_METHOD, ExpressionToken, Token, NthStmt, TokenUseSelector::EXPRESSION_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(Expr, obj_c_property, 33, MX_APPLY_METHOD, ObjCProperty, ObjCPropertyRefExpr, NthStmt, StmtUseSelector::OBJ_C_PROPERTY)
  MX_VISIT_ENUM(Expr, object_kind, 56, MX_APPLY_METHOD, ObjectKind, ExprObjectKind, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(Expr, referenced_declaration_of_callee, 34, MX_APPLY_METHOD, ReferencedDeclarationOfCallee, Decl, NthStmt, DeclUseSelector::REFERENCED_DECLARATION_OF_CALLEE)
  MX_VISIT_OPTIONAL_ENTITY(Expr, source_bit_field, 35, MX_APPLY_METHOD, SourceBitField, FieldDecl, NthStmt, DeclUseSelector::SOURCE_BIT_FIELD)
  MX_VISIT_OPTIONAL_ENTITY(Expr, type, 36, MX_APPLY_METHOD, Type, Type, NthStmt, TypeUseSelector::TYPE)
  MX_VISIT_ENUM(Expr, value_kind, 74, MX_APPLY_METHOD, ValueKind, ExprValueKind, NthStmt)
  MX_VISIT_BOOL(Expr, has_non_trivial_call, 61, MX_APPLY_METHOD, HasNonTrivialCall, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(Expr, is_cxx98_integral_constant_expression, 62, MX_APPLY_METHOD, IsCXX98IntegralConstantExpression, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_default_argument, 64, MX_APPLY_METHOD, IsDefaultArgument, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_gl_value, 75, MX_APPLY_METHOD, IsGLValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_implicit_cxx_this, 76, MX_APPLY_METHOD, IsImplicitCXXThis, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_instantiation_dependent, 77, MX_APPLY_METHOD, IsInstantiationDependent, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(Expr, is_integer_constant_expression, 78, MX_APPLY_METHOD, IsIntegerConstantExpression, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_known_to_have_boolean_value, 80, MX_APPLY_METHOD, IsKnownToHaveBooleanValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_l_value, 81, MX_APPLY_METHOD, IsLValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_objcgc_candidate, 82, MX_APPLY_METHOD, IsOBJCGCCandidate, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_obj_c_self_expression, 83, MX_APPLY_METHOD, IsObjCSelfExpression, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_ordinary_or_bit_field_object, 84, MX_APPLY_METHOD, IsOrdinaryOrBitFieldObject, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_pr_value, 85, MX_APPLY_METHOD, IsPRValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_read_if_discarded_in_c_plus_plus11, 86, MX_APPLY_METHOD, IsReadIfDiscardedInCPlusPlus11, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_type_dependent, 87, MX_APPLY_METHOD, IsTypeDependent, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_value_dependent, 88, MX_APPLY_METHOD, IsValueDependent, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_x_value, 89, MX_APPLY_METHOD, IsXValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_bit_field, 90, MX_APPLY_METHOD, RefersToBitField, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_global_register_variable, 91, MX_APPLY_METHOD, RefersToGlobalRegisterVariable, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_matrix_element, 92, MX_APPLY_METHOD, RefersToMatrixElement, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_vector_element, 93, MX_APPLY_METHOD, RefersToVectorElement, bool, NthStmt)
  MX_EXIT_VISIT_Expr
MX_END_VISIT_STMT(Expr)

#ifndef MX_ENTER_VISIT_DesignatedInitUpdateExpr
#  define MX_ENTER_VISIT_DesignatedInitUpdateExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_DesignatedInitUpdateExpr
#  define MX_EXIT_VISIT_DesignatedInitUpdateExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(DesignatedInitUpdateExpr)
  MX_ENTER_VISIT_DesignatedInitUpdateExpr
  MX_VISIT_BASE(DesignatedInitUpdateExpr, Expr)
  MX_VISIT_ENTITY(DesignatedInitUpdateExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(DesignatedInitUpdateExpr, updater, 38, MX_APPLY_METHOD, Updater, InitListExpr, NthStmt, StmtUseSelector::UPDATER)
  MX_EXIT_VISIT_DesignatedInitUpdateExpr
MX_END_VISIT_STMT(DesignatedInitUpdateExpr)

#ifndef MX_ENTER_VISIT_DesignatedInitExpr
#  define MX_ENTER_VISIT_DesignatedInitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_DesignatedInitExpr
#  define MX_EXIT_VISIT_DesignatedInitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(DesignatedInitExpr)
  MX_ENTER_VISIT_DesignatedInitExpr
  MX_VISIT_BASE(DesignatedInitExpr, Expr)
  MX_VISIT_ENTITY(DesignatedInitExpr, equal_or_colon_token, 39, MX_APPLY_METHOD, EqualOrColonToken, Token, NthStmt, TokenUseSelector::EQUAL_OR_COLON_TOKEN)
  MX_VISIT_ENTITY(DesignatedInitExpr, initializer, 40, MX_APPLY_METHOD, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_BOOL(DesignatedInitExpr, is_direct_initializer, 94, MX_APPLY_METHOD, IsDirectInitializer, bool, NthStmt)
  MX_VISIT_BOOL(DesignatedInitExpr, uses_gnu_syntax, 95, MX_APPLY_METHOD, UsesGNUSyntax, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(DesignatedInitExpr, sub_expressions, 16, MX_APPLY_METHOD, SubExpressions, Expr, NthStmt)
  MX_EXIT_VISIT_DesignatedInitExpr
MX_END_VISIT_STMT(DesignatedInitExpr)

#ifndef MX_ENTER_VISIT_DependentScopeDeclRefExpr
#  define MX_ENTER_VISIT_DependentScopeDeclRefExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_DependentScopeDeclRefExpr
#  define MX_EXIT_VISIT_DependentScopeDeclRefExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(DependentScopeDeclRefExpr)
  MX_ENTER_VISIT_DependentScopeDeclRefExpr
  MX_VISIT_BASE(DependentScopeDeclRefExpr, Expr)
  MX_VISIT_ENTITY(DependentScopeDeclRefExpr, l_angle_token, 37, MX_APPLY_METHOD, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DependentScopeDeclRefExpr, r_angle_token, 38, MX_APPLY_METHOD, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DependentScopeDeclRefExpr, template_keyword_token, 39, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(DependentScopeDeclRefExpr, has_explicit_template_arguments, 94, MX_APPLY_METHOD, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(DependentScopeDeclRefExpr, has_template_keyword, 95, MX_APPLY_METHOD, HasTemplateKeyword, bool, NthStmt)
  MX_EXIT_VISIT_DependentScopeDeclRefExpr
MX_END_VISIT_STMT(DependentScopeDeclRefExpr)

#ifndef MX_ENTER_VISIT_DependentCoawaitExpr
#  define MX_ENTER_VISIT_DependentCoawaitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_DependentCoawaitExpr
#  define MX_EXIT_VISIT_DependentCoawaitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(DependentCoawaitExpr)
  MX_ENTER_VISIT_DependentCoawaitExpr
  MX_VISIT_BASE(DependentCoawaitExpr, Expr)
  MX_VISIT_ENTITY(DependentCoawaitExpr, keyword_token, 37, MX_APPLY_METHOD, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(DependentCoawaitExpr, operand, 38, MX_APPLY_METHOD, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_ENTITY(DependentCoawaitExpr, operator_coawait_lookup, 39, MX_APPLY_METHOD, OperatorCoawaitLookup, UnresolvedLookupExpr, NthStmt, StmtUseSelector::OPERATOR_COAWAIT_LOOKUP)
  MX_EXIT_VISIT_DependentCoawaitExpr
MX_END_VISIT_STMT(DependentCoawaitExpr)

#ifndef MX_ENTER_VISIT_DeclRefExpr
#  define MX_ENTER_VISIT_DeclRefExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_DeclRefExpr
#  define MX_EXIT_VISIT_DeclRefExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(DeclRefExpr)
  MX_ENTER_VISIT_DeclRefExpr
  MX_VISIT_BASE(DeclRefExpr, Expr)
  MX_VISIT_ENTITY(DeclRefExpr, declaration, 37, MX_APPLY_METHOD, Declaration, ValueDecl, NthStmt, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(DeclRefExpr, found_declaration, 38, MX_APPLY_METHOD, FoundDeclaration, NamedDecl, NthStmt, DeclUseSelector::FOUND_DECLARATION)
  MX_VISIT_ENTITY(DeclRefExpr, l_angle_token, 39, MX_APPLY_METHOD, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DeclRefExpr, r_angle_token, 40, MX_APPLY_METHOD, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DeclRefExpr, template_keyword_token, 41, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(DeclRefExpr, had_multiple_candidates, 94, MX_APPLY_METHOD, HadMultipleCandidates, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_explicit_template_arguments, 95, MX_APPLY_METHOD, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_qualifier, 96, MX_APPLY_METHOD, HasQualifier, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_template_keyword_and_arguments_info, 97, MX_APPLY_METHOD, HasTemplateKeywordAndArgumentsInfo, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_template_keyword, 98, MX_APPLY_METHOD, HasTemplateKeyword, bool, NthStmt)
  MX_VISIT_ENUM(DeclRefExpr, is_non_odr_use, 99, MX_APPLY_METHOD, IsNonOdrUse, NonOdrUseReason, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, refers_to_enclosing_variable_or_capture, 100, MX_APPLY_METHOD, RefersToEnclosingVariableOrCapture, bool, NthStmt)
  MX_EXIT_VISIT_DeclRefExpr
MX_END_VISIT_STMT(DeclRefExpr)

#ifndef MX_ENTER_VISIT_CoroutineSuspendExpr
#  define MX_ENTER_VISIT_CoroutineSuspendExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CoroutineSuspendExpr
#  define MX_EXIT_VISIT_CoroutineSuspendExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(CoroutineSuspendExpr)
  MX_ENTER_VISIT_CoroutineSuspendExpr
  MX_VISIT_BASE(CoroutineSuspendExpr, Expr)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, common_expression, 37, MX_APPLY_METHOD, CommonExpression, Expr, NthStmt, StmtUseSelector::COMMON_EXPRESSION)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, keyword_token, 38, MX_APPLY_METHOD, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, opaque_value, 39, MX_APPLY_METHOD, OpaqueValue, OpaqueValueExpr, NthStmt, StmtUseSelector::OPAQUE_VALUE)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, ready_expression, 40, MX_APPLY_METHOD, ReadyExpression, Expr, NthStmt, StmtUseSelector::READY_EXPRESSION)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, resume_expression, 41, MX_APPLY_METHOD, ResumeExpression, Expr, NthStmt, StmtUseSelector::RESUME_EXPRESSION)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, suspend_expression, 42, MX_APPLY_METHOD, SuspendExpression, Expr, NthStmt, StmtUseSelector::SUSPEND_EXPRESSION)
  MX_EXIT_VISIT_CoroutineSuspendExpr
MX_END_VISIT_STMT(CoroutineSuspendExpr)

#ifndef MX_ENTER_VISIT_CoawaitExpr
#  define MX_ENTER_VISIT_CoawaitExpr MX_ENTER_VISIT_CoroutineSuspendExpr
#endif
#ifndef MX_EXIT_VISIT_CoawaitExpr
#  define MX_EXIT_VISIT_CoawaitExpr MX_EXIT_VISIT_CoroutineSuspendExpr
#endif

MX_BEGIN_VISIT_STMT(CoawaitExpr)
  MX_ENTER_VISIT_CoawaitExpr
  MX_VISIT_BASE(CoawaitExpr, CoroutineSuspendExpr)
  MX_VISIT_ENTITY(CoawaitExpr, operand, 43, MX_APPLY_METHOD, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_BOOL(CoawaitExpr, is_implicit, 94, MX_APPLY_METHOD, IsImplicit, bool, NthStmt)
  MX_EXIT_VISIT_CoawaitExpr
MX_END_VISIT_STMT(CoawaitExpr)

#ifndef MX_ENTER_VISIT_CoyieldExpr
#  define MX_ENTER_VISIT_CoyieldExpr MX_ENTER_VISIT_CoroutineSuspendExpr
#endif
#ifndef MX_EXIT_VISIT_CoyieldExpr
#  define MX_EXIT_VISIT_CoyieldExpr MX_EXIT_VISIT_CoroutineSuspendExpr
#endif

MX_BEGIN_VISIT_STMT(CoyieldExpr)
  MX_ENTER_VISIT_CoyieldExpr
  MX_VISIT_BASE(CoyieldExpr, CoroutineSuspendExpr)
  MX_VISIT_ENTITY(CoyieldExpr, operand, 43, MX_APPLY_METHOD, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_EXIT_VISIT_CoyieldExpr
MX_END_VISIT_STMT(CoyieldExpr)

#ifndef MX_ENTER_VISIT_ConvertVectorExpr
#  define MX_ENTER_VISIT_ConvertVectorExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ConvertVectorExpr
#  define MX_EXIT_VISIT_ConvertVectorExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ConvertVectorExpr)
  MX_ENTER_VISIT_ConvertVectorExpr
  MX_VISIT_BASE(ConvertVectorExpr, Expr)
  MX_VISIT_ENTITY(ConvertVectorExpr, builtin_token, 37, MX_APPLY_METHOD, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(ConvertVectorExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(ConvertVectorExpr, src_expression, 39, MX_APPLY_METHOD, SrcExpression, Expr, NthStmt, StmtUseSelector::SRC_EXPRESSION)
  MX_EXIT_VISIT_ConvertVectorExpr
MX_END_VISIT_STMT(ConvertVectorExpr)

#ifndef MX_ENTER_VISIT_ConceptSpecializationExpr
#  define MX_ENTER_VISIT_ConceptSpecializationExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ConceptSpecializationExpr
#  define MX_EXIT_VISIT_ConceptSpecializationExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ConceptSpecializationExpr)
  MX_ENTER_VISIT_ConceptSpecializationExpr
  MX_VISIT_BASE(ConceptSpecializationExpr, Expr)
  MX_VISIT_PSEUDO_LIST(ConceptSpecializationExpr, template_arguments, 101, MX_APPLY_METHOD, TemplateArguments, TemplateArgument, NthStmt)
  MX_VISIT_BOOL(ConceptSpecializationExpr, is_satisfied, 94, MX_APPLY_METHOD, IsSatisfied, bool, NthStmt)
  MX_EXIT_VISIT_ConceptSpecializationExpr
MX_END_VISIT_STMT(ConceptSpecializationExpr)

#ifndef MX_ENTER_VISIT_CompoundLiteralExpr
#  define MX_ENTER_VISIT_CompoundLiteralExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CompoundLiteralExpr
#  define MX_EXIT_VISIT_CompoundLiteralExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CompoundLiteralExpr)
  MX_ENTER_VISIT_CompoundLiteralExpr
  MX_VISIT_BASE(CompoundLiteralExpr, Expr)
  MX_VISIT_ENTITY(CompoundLiteralExpr, initializer, 37, MX_APPLY_METHOD, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CompoundLiteralExpr, l_paren_token, 38, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_BOOL(CompoundLiteralExpr, is_file_scope, 94, MX_APPLY_METHOD, IsFileScope, bool, NthStmt)
  MX_EXIT_VISIT_CompoundLiteralExpr
MX_END_VISIT_STMT(CompoundLiteralExpr)

#ifndef MX_ENTER_VISIT_ChooseExpr
#  define MX_ENTER_VISIT_ChooseExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ChooseExpr
#  define MX_EXIT_VISIT_ChooseExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ChooseExpr)
  MX_ENTER_VISIT_ChooseExpr
  MX_VISIT_BASE(ChooseExpr, Expr)
  MX_VISIT_ENTITY(ChooseExpr, builtin_token, 37, MX_APPLY_METHOD, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(ChooseExpr, chosen_sub_expression, 38, MX_APPLY_METHOD, ChosenSubExpression, Expr, NthStmt, StmtUseSelector::CHOSEN_SUB_EXPRESSION)
  MX_VISIT_ENTITY(ChooseExpr, condition, 39, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(ChooseExpr, lhs, 40, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(ChooseExpr, rhs, 41, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_ENTITY(ChooseExpr, r_paren_token, 42, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(ChooseExpr, is_condition_dependent, 94, MX_APPLY_METHOD, IsConditionDependent, bool, NthStmt)
  MX_VISIT_BOOL(ChooseExpr, is_condition_true, 95, MX_APPLY_METHOD, IsConditionTrue, bool, NthStmt)
  MX_EXIT_VISIT_ChooseExpr
MX_END_VISIT_STMT(ChooseExpr)

#ifndef MX_ENTER_VISIT_CharacterLiteral
#  define MX_ENTER_VISIT_CharacterLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CharacterLiteral
#  define MX_EXIT_VISIT_CharacterLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CharacterLiteral)
  MX_ENTER_VISIT_CharacterLiteral
  MX_VISIT_BASE(CharacterLiteral, Expr)
  MX_VISIT_ENUM(CharacterLiteral, character_kind, 99, MX_APPLY_METHOD, Kind, CharacterLiteralCharacterKind, NthStmt)
  MX_VISIT_ENTITY(CharacterLiteral, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_EXIT_VISIT_CharacterLiteral
MX_END_VISIT_STMT(CharacterLiteral)

#ifndef MX_ENTER_VISIT_CastExpr
#  define MX_ENTER_VISIT_CastExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CastExpr
#  define MX_EXIT_VISIT_CastExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(CastExpr)
  MX_ENTER_VISIT_CastExpr
  MX_VISIT_BASE(CastExpr, Expr)
  MX_VISIT_ENUM(CastExpr, cast_kind, 99, MX_APPLY_METHOD, CastKind, CastKind, NthStmt)
  MX_VISIT_TEXT(CastExpr, cast_kind_name, 65, MX_APPLY_METHOD, CastKindName, basic_string_view, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(CastExpr, conversion_function, 37, MX_APPLY_METHOD, ConversionFunction, NamedDecl, NthStmt, DeclUseSelector::CONVERSION_FUNCTION)
  MX_VISIT_ENTITY(CastExpr, sub_expression, 38, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_ENTITY(CastExpr, sub_expression_as_written, 39, MX_APPLY_METHOD, SubExpressionAsWritten, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION_AS_WRITTEN)
  MX_VISIT_OPTIONAL_ENTITY(CastExpr, target_union_field, 40, MX_APPLY_METHOD, TargetUnionField, FieldDecl, NthStmt, DeclUseSelector::TARGET_UNION_FIELD)
  MX_VISIT_BOOL(CastExpr, has_stored_fp_features, 96, MX_APPLY_METHOD, HasStoredFPFeatures, bool, NthStmt)
  MX_EXIT_VISIT_CastExpr
MX_END_VISIT_STMT(CastExpr)

#ifndef MX_ENTER_VISIT_ImplicitCastExpr
#  define MX_ENTER_VISIT_ImplicitCastExpr MX_ENTER_VISIT_CastExpr
#endif
#ifndef MX_EXIT_VISIT_ImplicitCastExpr
#  define MX_EXIT_VISIT_ImplicitCastExpr MX_EXIT_VISIT_CastExpr
#endif

MX_BEGIN_VISIT_STMT(ImplicitCastExpr)
  MX_ENTER_VISIT_ImplicitCastExpr
  MX_VISIT_BASE(ImplicitCastExpr, CastExpr)
  MX_VISIT_BOOL(ImplicitCastExpr, is_part_of_explicit_cast, 97, MX_APPLY_METHOD, IsPartOfExplicitCast, bool, NthStmt)
  MX_EXIT_VISIT_ImplicitCastExpr
MX_END_VISIT_STMT(ImplicitCastExpr)

#ifndef MX_ENTER_VISIT_ExplicitCastExpr
#  define MX_ENTER_VISIT_ExplicitCastExpr MX_ENTER_VISIT_CastExpr
#endif
#ifndef MX_EXIT_VISIT_ExplicitCastExpr
#  define MX_EXIT_VISIT_ExplicitCastExpr MX_EXIT_VISIT_CastExpr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(ExplicitCastExpr)
  MX_ENTER_VISIT_ExplicitCastExpr
  MX_VISIT_BASE(ExplicitCastExpr, CastExpr)
  MX_VISIT_ENTITY(ExplicitCastExpr, type_as_written, 41, MX_APPLY_METHOD, TypeAsWritten, Type, NthStmt, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_EXIT_VISIT_ExplicitCastExpr
MX_END_VISIT_STMT(ExplicitCastExpr)

#ifndef MX_ENTER_VISIT_CXXNamedCastExpr
#  define MX_ENTER_VISIT_CXXNamedCastExpr MX_ENTER_VISIT_ExplicitCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXNamedCastExpr
#  define MX_EXIT_VISIT_CXXNamedCastExpr MX_EXIT_VISIT_ExplicitCastExpr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(CXXNamedCastExpr)
  MX_ENTER_VISIT_CXXNamedCastExpr
  MX_VISIT_BASE(CXXNamedCastExpr, ExplicitCastExpr)
  MX_VISIT_TEXT(CXXNamedCastExpr, cast_name, 70, MX_APPLY_METHOD, CastName, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(CXXNamedCastExpr, operator_token, 44, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXNamedCastExpr, r_paren_token, 45, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_CXXNamedCastExpr
MX_END_VISIT_STMT(CXXNamedCastExpr)

#ifndef MX_ENTER_VISIT_CXXDynamicCastExpr
#  define MX_ENTER_VISIT_CXXDynamicCastExpr MX_ENTER_VISIT_CXXNamedCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXDynamicCastExpr
#  define MX_EXIT_VISIT_CXXDynamicCastExpr MX_EXIT_VISIT_CXXNamedCastExpr
#endif

MX_BEGIN_VISIT_STMT(CXXDynamicCastExpr)
  MX_ENTER_VISIT_CXXDynamicCastExpr
  MX_VISIT_BASE(CXXDynamicCastExpr, CXXNamedCastExpr)
  MX_VISIT_BOOL(CXXDynamicCastExpr, is_always_null, 97, MX_APPLY_METHOD, IsAlwaysNull, bool, NthStmt)
  MX_EXIT_VISIT_CXXDynamicCastExpr
MX_END_VISIT_STMT(CXXDynamicCastExpr)

#ifndef MX_ENTER_VISIT_CXXConstCastExpr
#  define MX_ENTER_VISIT_CXXConstCastExpr MX_ENTER_VISIT_CXXNamedCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXConstCastExpr
#  define MX_EXIT_VISIT_CXXConstCastExpr MX_EXIT_VISIT_CXXNamedCastExpr
#endif

MX_BEGIN_VISIT_STMT(CXXConstCastExpr)
  MX_ENTER_VISIT_CXXConstCastExpr
  MX_VISIT_BASE(CXXConstCastExpr, CXXNamedCastExpr)
  MX_EXIT_VISIT_CXXConstCastExpr
MX_END_VISIT_STMT(CXXConstCastExpr)

#ifndef MX_ENTER_VISIT_CXXAddrspaceCastExpr
#  define MX_ENTER_VISIT_CXXAddrspaceCastExpr MX_ENTER_VISIT_CXXNamedCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXAddrspaceCastExpr
#  define MX_EXIT_VISIT_CXXAddrspaceCastExpr MX_EXIT_VISIT_CXXNamedCastExpr
#endif

MX_BEGIN_VISIT_STMT(CXXAddrspaceCastExpr)
  MX_ENTER_VISIT_CXXAddrspaceCastExpr
  MX_VISIT_BASE(CXXAddrspaceCastExpr, CXXNamedCastExpr)
  MX_EXIT_VISIT_CXXAddrspaceCastExpr
MX_END_VISIT_STMT(CXXAddrspaceCastExpr)

#ifndef MX_ENTER_VISIT_CXXStaticCastExpr
#  define MX_ENTER_VISIT_CXXStaticCastExpr MX_ENTER_VISIT_CXXNamedCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXStaticCastExpr
#  define MX_EXIT_VISIT_CXXStaticCastExpr MX_EXIT_VISIT_CXXNamedCastExpr
#endif

MX_BEGIN_VISIT_STMT(CXXStaticCastExpr)
  MX_ENTER_VISIT_CXXStaticCastExpr
  MX_VISIT_BASE(CXXStaticCastExpr, CXXNamedCastExpr)
  MX_EXIT_VISIT_CXXStaticCastExpr
MX_END_VISIT_STMT(CXXStaticCastExpr)

#ifndef MX_ENTER_VISIT_CXXReinterpretCastExpr
#  define MX_ENTER_VISIT_CXXReinterpretCastExpr MX_ENTER_VISIT_CXXNamedCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXReinterpretCastExpr
#  define MX_EXIT_VISIT_CXXReinterpretCastExpr MX_EXIT_VISIT_CXXNamedCastExpr
#endif

MX_BEGIN_VISIT_STMT(CXXReinterpretCastExpr)
  MX_ENTER_VISIT_CXXReinterpretCastExpr
  MX_VISIT_BASE(CXXReinterpretCastExpr, CXXNamedCastExpr)
  MX_EXIT_VISIT_CXXReinterpretCastExpr
MX_END_VISIT_STMT(CXXReinterpretCastExpr)

#ifndef MX_ENTER_VISIT_CXXFunctionalCastExpr
#  define MX_ENTER_VISIT_CXXFunctionalCastExpr MX_ENTER_VISIT_ExplicitCastExpr
#endif
#ifndef MX_EXIT_VISIT_CXXFunctionalCastExpr
#  define MX_EXIT_VISIT_CXXFunctionalCastExpr MX_EXIT_VISIT_ExplicitCastExpr
#endif

MX_BEGIN_VISIT_STMT(CXXFunctionalCastExpr)
  MX_ENTER_VISIT_CXXFunctionalCastExpr
  MX_VISIT_BASE(CXXFunctionalCastExpr, ExplicitCastExpr)
  MX_VISIT_ENTITY(CXXFunctionalCastExpr, l_paren_token, 42, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXFunctionalCastExpr, r_paren_token, 43, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(CXXFunctionalCastExpr, is_list_initialization, 97, MX_APPLY_METHOD, IsListInitialization, bool, NthStmt)
  MX_EXIT_VISIT_CXXFunctionalCastExpr
MX_END_VISIT_STMT(CXXFunctionalCastExpr)

#ifndef MX_ENTER_VISIT_CStyleCastExpr
#  define MX_ENTER_VISIT_CStyleCastExpr MX_ENTER_VISIT_ExplicitCastExpr
#endif
#ifndef MX_EXIT_VISIT_CStyleCastExpr
#  define MX_EXIT_VISIT_CStyleCastExpr MX_EXIT_VISIT_ExplicitCastExpr
#endif

MX_BEGIN_VISIT_STMT(CStyleCastExpr)
  MX_ENTER_VISIT_CStyleCastExpr
  MX_VISIT_BASE(CStyleCastExpr, ExplicitCastExpr)
  MX_VISIT_ENTITY(CStyleCastExpr, l_paren_token, 42, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(CStyleCastExpr, r_paren_token, 43, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_CStyleCastExpr
MX_END_VISIT_STMT(CStyleCastExpr)

#ifndef MX_ENTER_VISIT_BuiltinBitCastExpr
#  define MX_ENTER_VISIT_BuiltinBitCastExpr MX_ENTER_VISIT_ExplicitCastExpr
#endif
#ifndef MX_EXIT_VISIT_BuiltinBitCastExpr
#  define MX_EXIT_VISIT_BuiltinBitCastExpr MX_EXIT_VISIT_ExplicitCastExpr
#endif

MX_BEGIN_VISIT_STMT(BuiltinBitCastExpr)
  MX_ENTER_VISIT_BuiltinBitCastExpr
  MX_VISIT_BASE(BuiltinBitCastExpr, ExplicitCastExpr)
  MX_EXIT_VISIT_BuiltinBitCastExpr
MX_END_VISIT_STMT(BuiltinBitCastExpr)

#ifndef MX_ENTER_VISIT_ObjCBridgedCastExpr
#  define MX_ENTER_VISIT_ObjCBridgedCastExpr MX_ENTER_VISIT_ExplicitCastExpr
#endif
#ifndef MX_EXIT_VISIT_ObjCBridgedCastExpr
#  define MX_EXIT_VISIT_ObjCBridgedCastExpr MX_EXIT_VISIT_ExplicitCastExpr
#endif

MX_BEGIN_VISIT_STMT(ObjCBridgedCastExpr)
  MX_ENTER_VISIT_ObjCBridgedCastExpr
  MX_VISIT_BASE(ObjCBridgedCastExpr, ExplicitCastExpr)
  MX_VISIT_ENTITY(ObjCBridgedCastExpr, bridge_keyword_token, 42, MX_APPLY_METHOD, BridgeKeywordToken, Token, NthStmt, TokenUseSelector::BRIDGE_KEYWORD_TOKEN)
  MX_VISIT_ENUM(ObjCBridgedCastExpr, bridge_kind, 102, MX_APPLY_METHOD, BridgeKind, ObjCBridgeCastKind, NthStmt)
  MX_VISIT_TEXT(ObjCBridgedCastExpr, bridge_kind_name, 70, MX_APPLY_METHOD, BridgeKindName, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(ObjCBridgedCastExpr, l_paren_token, 43, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_EXIT_VISIT_ObjCBridgedCastExpr
MX_END_VISIT_STMT(ObjCBridgedCastExpr)

#ifndef MX_ENTER_VISIT_CallExpr
#  define MX_ENTER_VISIT_CallExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CallExpr
#  define MX_EXIT_VISIT_CallExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CallExpr)
  MX_ENTER_VISIT_CallExpr
  MX_VISIT_BASE(CallExpr, Expr)
  MX_VISIT_ENTITY_LIST(CallExpr, arguments, 16, MX_APPLY_METHOD, Arguments, Expr, NthStmt)
  MX_VISIT_ENUM(CallExpr, adl_call_kind, 99, MX_APPLY_METHOD, ADLCallKind, CallExprADLCallKind, NthStmt)
  MX_VISIT_ENTITY(CallExpr, call_return_type, 37, MX_APPLY_METHOD, CallReturnType, Type, NthStmt, TypeUseSelector::CALL_RETURN_TYPE)
  MX_VISIT_ENTITY(CallExpr, callee, 38, MX_APPLY_METHOD, Callee, Expr, NthStmt, StmtUseSelector::CALLEE)
  MX_VISIT_OPTIONAL_ENTITY(CallExpr, callee_declaration, 39, MX_APPLY_METHOD, CalleeDeclaration, Decl, NthStmt, DeclUseSelector::CALLEE_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(CallExpr, direct_callee, 40, MX_APPLY_METHOD, DirectCallee, FunctionDecl, NthStmt, DeclUseSelector::DIRECT_CALLEE)
  MX_VISIT_ENTITY(CallExpr, r_paren_token, 41, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(CallExpr, has_stored_fp_features, 96, MX_APPLY_METHOD, HasStoredFPFeatures, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, has_unused_result_attribute, 97, MX_APPLY_METHOD, HasUnusedResultAttribute, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, is_builtin_assume_false, 98, MX_APPLY_METHOD, IsBuiltinAssumeFalse, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, is_call_to_std_move, 100, MX_APPLY_METHOD, IsCallToStdMove, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, is_unevaluated_builtin_call, 103, MX_APPLY_METHOD, IsUnevaluatedBuiltinCall, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, uses_adl, 104, MX_APPLY_METHOD, UsesADL, bool, NthStmt)
  MX_EXIT_VISIT_CallExpr
MX_END_VISIT_STMT(CallExpr)

#ifndef MX_ENTER_VISIT_CXXOperatorCallExpr
#  define MX_ENTER_VISIT_CXXOperatorCallExpr MX_ENTER_VISIT_CallExpr
#endif
#ifndef MX_EXIT_VISIT_CXXOperatorCallExpr
#  define MX_EXIT_VISIT_CXXOperatorCallExpr MX_EXIT_VISIT_CallExpr
#endif

MX_BEGIN_VISIT_STMT(CXXOperatorCallExpr)
  MX_ENTER_VISIT_CXXOperatorCallExpr
  MX_VISIT_BASE(CXXOperatorCallExpr, CallExpr)
  MX_VISIT_ENUM(CXXOperatorCallExpr, operator_, 102, MX_APPLY_METHOD, Operator, OverloadedOperatorKind, NthStmt)
  MX_VISIT_ENTITY(CXXOperatorCallExpr, operator_token, 42, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_BOOL(CXXOperatorCallExpr, is_assignment_operation, 105, MX_APPLY_METHOD, IsAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXOperatorCallExpr, is_comparison_operation, 106, MX_APPLY_METHOD, IsComparisonOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXOperatorCallExpr, is_infix_binary_operation, 107, MX_APPLY_METHOD, IsInfixBinaryOperation, bool, NthStmt)
  MX_EXIT_VISIT_CXXOperatorCallExpr
MX_END_VISIT_STMT(CXXOperatorCallExpr)

#ifndef MX_ENTER_VISIT_CXXMemberCallExpr
#  define MX_ENTER_VISIT_CXXMemberCallExpr MX_ENTER_VISIT_CallExpr
#endif
#ifndef MX_EXIT_VISIT_CXXMemberCallExpr
#  define MX_EXIT_VISIT_CXXMemberCallExpr MX_EXIT_VISIT_CallExpr
#endif

MX_BEGIN_VISIT_STMT(CXXMemberCallExpr)
  MX_ENTER_VISIT_CXXMemberCallExpr
  MX_VISIT_BASE(CXXMemberCallExpr, CallExpr)
  MX_VISIT_ENTITY(CXXMemberCallExpr, implicit_object_argument, 42, MX_APPLY_METHOD, ImplicitObjectArgument, Expr, NthStmt, StmtUseSelector::IMPLICIT_OBJECT_ARGUMENT)
  MX_VISIT_OPTIONAL_ENTITY(CXXMemberCallExpr, method_declaration, 43, MX_APPLY_METHOD, MethodDeclaration, CXXMethodDecl, NthStmt, DeclUseSelector::METHOD_DECLARATION)
  MX_VISIT_ENTITY(CXXMemberCallExpr, object_type, 44, MX_APPLY_METHOD, ObjectType, Type, NthStmt, TypeUseSelector::OBJECT_TYPE)
  MX_VISIT_ENTITY(CXXMemberCallExpr, record_declaration, 45, MX_APPLY_METHOD, RecordDeclaration, CXXRecordDecl, NthStmt, DeclUseSelector::RECORD_DECLARATION)
  MX_EXIT_VISIT_CXXMemberCallExpr
MX_END_VISIT_STMT(CXXMemberCallExpr)

#ifndef MX_ENTER_VISIT_CUDAKernelCallExpr
#  define MX_ENTER_VISIT_CUDAKernelCallExpr MX_ENTER_VISIT_CallExpr
#endif
#ifndef MX_EXIT_VISIT_CUDAKernelCallExpr
#  define MX_EXIT_VISIT_CUDAKernelCallExpr MX_EXIT_VISIT_CallExpr
#endif

MX_BEGIN_VISIT_STMT(CUDAKernelCallExpr)
  MX_ENTER_VISIT_CUDAKernelCallExpr
  MX_VISIT_BASE(CUDAKernelCallExpr, CallExpr)
  MX_VISIT_ENTITY(CUDAKernelCallExpr, config, 42, MX_APPLY_METHOD, Config, CallExpr, NthStmt, StmtUseSelector::CONFIG)
  MX_EXIT_VISIT_CUDAKernelCallExpr
MX_END_VISIT_STMT(CUDAKernelCallExpr)

#ifndef MX_ENTER_VISIT_UserDefinedLiteral
#  define MX_ENTER_VISIT_UserDefinedLiteral MX_ENTER_VISIT_CallExpr
#endif
#ifndef MX_EXIT_VISIT_UserDefinedLiteral
#  define MX_EXIT_VISIT_UserDefinedLiteral MX_EXIT_VISIT_CallExpr
#endif

MX_BEGIN_VISIT_STMT(UserDefinedLiteral)
  MX_ENTER_VISIT_UserDefinedLiteral
  MX_VISIT_BASE(UserDefinedLiteral, CallExpr)
  MX_VISIT_ENTITY(UserDefinedLiteral, cooked_literal, 42, MX_APPLY_METHOD, CookedLiteral, Expr, NthStmt, StmtUseSelector::COOKED_LITERAL)
  MX_VISIT_ENUM(UserDefinedLiteral, literal_operator_kind, 102, MX_APPLY_METHOD, LiteralOperatorKind, UserDefinedLiteralLiteralOperatorKind, NthStmt)
  MX_VISIT_ENTITY(UserDefinedLiteral, ud_suffix_token, 43, MX_APPLY_METHOD, UDSuffixToken, Token, NthStmt, TokenUseSelector::UD_SUFFIX_TOKEN)
  MX_EXIT_VISIT_UserDefinedLiteral
MX_END_VISIT_STMT(UserDefinedLiteral)

#ifndef MX_ENTER_VISIT_CXXUuidofExpr
#  define MX_ENTER_VISIT_CXXUuidofExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXUuidofExpr
#  define MX_EXIT_VISIT_CXXUuidofExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXUuidofExpr)
  MX_ENTER_VISIT_CXXUuidofExpr
  MX_VISIT_BASE(CXXUuidofExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(CXXUuidofExpr, expression_operand, 37, MX_APPLY_METHOD, ExpressionOperand, Expr, NthStmt, StmtUseSelector::EXPRESSION_OPERAND)
  MX_VISIT_ENTITY(CXXUuidofExpr, guid_declaration, 38, MX_APPLY_METHOD, GuidDeclaration, MSGuidDecl, NthStmt, DeclUseSelector::GUID_DECLARATION)
  MX_VISIT_ENTITY(CXXUuidofExpr, type_operand, 39, MX_APPLY_METHOD, TypeOperand, Type, NthStmt, TypeUseSelector::TYPE_OPERAND)
  MX_VISIT_ENTITY(CXXUuidofExpr, type_operand_source_info, 40, MX_APPLY_METHOD, TypeOperandSourceInfo, Type, NthStmt, TypeUseSelector::TYPE_OPERAND_SOURCE_INFO)
  MX_VISIT_BOOL(CXXUuidofExpr, is_type_operand, 95, MX_APPLY_METHOD, IsTypeOperand, bool, NthStmt)
  MX_EXIT_VISIT_CXXUuidofExpr
MX_END_VISIT_STMT(CXXUuidofExpr)

#ifndef MX_ENTER_VISIT_CXXUnresolvedConstructExpr
#  define MX_ENTER_VISIT_CXXUnresolvedConstructExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXUnresolvedConstructExpr
#  define MX_EXIT_VISIT_CXXUnresolvedConstructExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXUnresolvedConstructExpr)
  MX_ENTER_VISIT_CXXUnresolvedConstructExpr
  MX_VISIT_BASE(CXXUnresolvedConstructExpr, Expr)
  MX_VISIT_ENTITY_LIST(CXXUnresolvedConstructExpr, arguments, 16, MX_APPLY_METHOD, Arguments, Expr, NthStmt)
  MX_VISIT_ENTITY(CXXUnresolvedConstructExpr, l_paren_token, 37, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXUnresolvedConstructExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXUnresolvedConstructExpr, type_as_written, 39, MX_APPLY_METHOD, TypeAsWritten, Type, NthStmt, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(CXXUnresolvedConstructExpr, is_list_initialization, 94, MX_APPLY_METHOD, IsListInitialization, bool, NthStmt)
  MX_EXIT_VISIT_CXXUnresolvedConstructExpr
MX_END_VISIT_STMT(CXXUnresolvedConstructExpr)

#ifndef MX_ENTER_VISIT_CXXTypeidExpr
#  define MX_ENTER_VISIT_CXXTypeidExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXTypeidExpr
#  define MX_EXIT_VISIT_CXXTypeidExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXTypeidExpr)
  MX_ENTER_VISIT_CXXTypeidExpr
  MX_VISIT_BASE(CXXTypeidExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(CXXTypeidExpr, expression_operand, 37, MX_APPLY_METHOD, ExpressionOperand, Expr, NthStmt, StmtUseSelector::EXPRESSION_OPERAND)
  MX_VISIT_ENTITY(CXXTypeidExpr, type_operand, 38, MX_APPLY_METHOD, TypeOperand, Type, NthStmt, TypeUseSelector::TYPE_OPERAND)
  MX_VISIT_ENTITY(CXXTypeidExpr, type_operand_source_info, 39, MX_APPLY_METHOD, TypeOperandSourceInfo, Type, NthStmt, TypeUseSelector::TYPE_OPERAND_SOURCE_INFO)
  MX_VISIT_OPTIONAL_BOOL(CXXTypeidExpr, is_most_derived, 95, MX_APPLY_METHOD, IsMostDerived, bool, NthStmt)
  MX_VISIT_BOOL(CXXTypeidExpr, is_potentially_evaluated, 97, MX_APPLY_METHOD, IsPotentiallyEvaluated, bool, NthStmt)
  MX_VISIT_BOOL(CXXTypeidExpr, is_type_operand, 98, MX_APPLY_METHOD, IsTypeOperand, bool, NthStmt)
  MX_EXIT_VISIT_CXXTypeidExpr
MX_END_VISIT_STMT(CXXTypeidExpr)

#ifndef MX_ENTER_VISIT_CXXThrowExpr
#  define MX_ENTER_VISIT_CXXThrowExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXThrowExpr
#  define MX_EXIT_VISIT_CXXThrowExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXThrowExpr)
  MX_ENTER_VISIT_CXXThrowExpr
  MX_VISIT_BASE(CXXThrowExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(CXXThrowExpr, sub_expression, 37, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_ENTITY(CXXThrowExpr, throw_token, 38, MX_APPLY_METHOD, ThrowToken, Token, NthStmt, TokenUseSelector::THROW_TOKEN)
  MX_VISIT_BOOL(CXXThrowExpr, is_thrown_variable_in_scope, 95, MX_APPLY_METHOD, IsThrownVariableInScope, bool, NthStmt)
  MX_EXIT_VISIT_CXXThrowExpr
MX_END_VISIT_STMT(CXXThrowExpr)

#ifndef MX_ENTER_VISIT_CXXThisExpr
#  define MX_ENTER_VISIT_CXXThisExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXThisExpr
#  define MX_EXIT_VISIT_CXXThisExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXThisExpr)
  MX_ENTER_VISIT_CXXThisExpr
  MX_VISIT_BASE(CXXThisExpr, Expr)
  MX_VISIT_ENTITY(CXXThisExpr, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXThisExpr, is_implicit, 94, MX_APPLY_METHOD, IsImplicit, bool, NthStmt)
  MX_EXIT_VISIT_CXXThisExpr
MX_END_VISIT_STMT(CXXThisExpr)

#ifndef MX_ENTER_VISIT_CXXStdInitializerListExpr
#  define MX_ENTER_VISIT_CXXStdInitializerListExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXStdInitializerListExpr
#  define MX_EXIT_VISIT_CXXStdInitializerListExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXStdInitializerListExpr)
  MX_ENTER_VISIT_CXXStdInitializerListExpr
  MX_VISIT_BASE(CXXStdInitializerListExpr, Expr)
  MX_VISIT_ENTITY(CXXStdInitializerListExpr, sub_expression, 37, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_EXIT_VISIT_CXXStdInitializerListExpr
MX_END_VISIT_STMT(CXXStdInitializerListExpr)

#ifndef MX_ENTER_VISIT_CXXScalarValueInitExpr
#  define MX_ENTER_VISIT_CXXScalarValueInitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXScalarValueInitExpr
#  define MX_EXIT_VISIT_CXXScalarValueInitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXScalarValueInitExpr)
  MX_ENTER_VISIT_CXXScalarValueInitExpr
  MX_VISIT_BASE(CXXScalarValueInitExpr, Expr)
  MX_VISIT_ENTITY(CXXScalarValueInitExpr, r_paren_token, 37, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_CXXScalarValueInitExpr
MX_END_VISIT_STMT(CXXScalarValueInitExpr)

#ifndef MX_ENTER_VISIT_CXXRewrittenBinaryOperator
#  define MX_ENTER_VISIT_CXXRewrittenBinaryOperator MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXRewrittenBinaryOperator
#  define MX_EXIT_VISIT_CXXRewrittenBinaryOperator MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXRewrittenBinaryOperator)
  MX_ENTER_VISIT_CXXRewrittenBinaryOperator
  MX_VISIT_BASE(CXXRewrittenBinaryOperator, Expr)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, lhs, 37, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENUM(CXXRewrittenBinaryOperator, opcode, 99, MX_APPLY_METHOD, Opcode, BinaryOperatorKind, NthStmt)
  MX_VISIT_TEXT(CXXRewrittenBinaryOperator, opcode_string, 65, MX_APPLY_METHOD, OpcodeString, basic_string_view, NthStmt)
  MX_VISIT_ENUM(CXXRewrittenBinaryOperator, operator_, 102, MX_APPLY_METHOD, Operator, BinaryOperatorKind, NthStmt)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, operator_token, 38, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, rhs, 39, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, semantic_form, 40, MX_APPLY_METHOD, SemanticForm, Expr, NthStmt, StmtUseSelector::SEMANTIC_FORM)
  MX_VISIT_BOOL(CXXRewrittenBinaryOperator, is_assignment_operation, 94, MX_APPLY_METHOD, IsAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXRewrittenBinaryOperator, is_comparison_operation, 95, MX_APPLY_METHOD, IsComparisonOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXRewrittenBinaryOperator, is_reversed, 96, MX_APPLY_METHOD, IsReversed, bool, NthStmt)
  MX_EXIT_VISIT_CXXRewrittenBinaryOperator
MX_END_VISIT_STMT(CXXRewrittenBinaryOperator)

#ifndef MX_ENTER_VISIT_CXXPseudoDestructorExpr
#  define MX_ENTER_VISIT_CXXPseudoDestructorExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXPseudoDestructorExpr
#  define MX_EXIT_VISIT_CXXPseudoDestructorExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXPseudoDestructorExpr)
  MX_ENTER_VISIT_CXXPseudoDestructorExpr
  MX_VISIT_BASE(CXXPseudoDestructorExpr, Expr)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, colon_colon_token, 38, MX_APPLY_METHOD, ColonColonToken, Token, NthStmt, TokenUseSelector::COLON_COLON_TOKEN)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, destroyed_type, 39, MX_APPLY_METHOD, DestroyedType, Type, NthStmt, TypeUseSelector::DESTROYED_TYPE)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, destroyed_type_token, 40, MX_APPLY_METHOD, DestroyedTypeToken, Token, NthStmt, TokenUseSelector::DESTROYED_TYPE_TOKEN)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, operator_token, 41, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(CXXPseudoDestructorExpr, scope_type, 42, MX_APPLY_METHOD, ScopeType, Type, NthStmt, TypeUseSelector::SCOPE_TYPE)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, tilde_token, 43, MX_APPLY_METHOD, TildeToken, Token, NthStmt, TokenUseSelector::TILDE_TOKEN)
  MX_VISIT_BOOL(CXXPseudoDestructorExpr, has_qualifier, 95, MX_APPLY_METHOD, HasQualifier, bool, NthStmt)
  MX_VISIT_BOOL(CXXPseudoDestructorExpr, is_arrow, 96, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_EXIT_VISIT_CXXPseudoDestructorExpr
MX_END_VISIT_STMT(CXXPseudoDestructorExpr)

#ifndef MX_ENTER_VISIT_CXXNullPtrLiteralExpr
#  define MX_ENTER_VISIT_CXXNullPtrLiteralExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXNullPtrLiteralExpr
#  define MX_EXIT_VISIT_CXXNullPtrLiteralExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXNullPtrLiteralExpr)
  MX_ENTER_VISIT_CXXNullPtrLiteralExpr
  MX_VISIT_BASE(CXXNullPtrLiteralExpr, Expr)
  MX_VISIT_ENTITY(CXXNullPtrLiteralExpr, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_EXIT_VISIT_CXXNullPtrLiteralExpr
MX_END_VISIT_STMT(CXXNullPtrLiteralExpr)

#ifndef MX_ENTER_VISIT_CXXNoexceptExpr
#  define MX_ENTER_VISIT_CXXNoexceptExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXNoexceptExpr
#  define MX_EXIT_VISIT_CXXNoexceptExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXNoexceptExpr)
  MX_ENTER_VISIT_CXXNoexceptExpr
  MX_VISIT_BASE(CXXNoexceptExpr, Expr)
  MX_VISIT_ENTITY(CXXNoexceptExpr, operand, 37, MX_APPLY_METHOD, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_BOOL(CXXNoexceptExpr, value, 94, MX_APPLY_METHOD, Value, bool, NthStmt)
  MX_EXIT_VISIT_CXXNoexceptExpr
MX_END_VISIT_STMT(CXXNoexceptExpr)

#ifndef MX_ENTER_VISIT_CXXNewExpr
#  define MX_ENTER_VISIT_CXXNewExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXNewExpr
#  define MX_EXIT_VISIT_CXXNewExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXNewExpr)
  MX_ENTER_VISIT_CXXNewExpr
  MX_VISIT_BASE(CXXNewExpr, Expr)
  MX_VISIT_BOOL(CXXNewExpr, does_usual_array_delete_want_size, 94, MX_APPLY_METHOD, DoesUsualArrayDeleteWantSize, bool, NthStmt)
  MX_VISIT_ENTITY(CXXNewExpr, allocated_type, 37, MX_APPLY_METHOD, AllocatedType, Type, NthStmt, TypeUseSelector::ALLOCATED_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXNewExpr, array_size, 38, MX_APPLY_METHOD, ArraySize, Expr, NthStmt, StmtUseSelector::ARRAY_SIZE)
  MX_VISIT_OPTIONAL_ENTITY(CXXNewExpr, construct_expression, 39, MX_APPLY_METHOD, ConstructExpression, CXXConstructExpr, NthStmt, StmtUseSelector::CONSTRUCT_EXPRESSION)
  MX_VISIT_ENUM(CXXNewExpr, initialization_style, 99, MX_APPLY_METHOD, InitializationStyle, CXXNewExprInitializationStyle, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(CXXNewExpr, initializer, 42, MX_APPLY_METHOD, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CXXNewExpr, operator_delete, 43, MX_APPLY_METHOD, OperatorDelete, FunctionDecl, NthStmt, DeclUseSelector::OPERATOR_DELETE)
  MX_VISIT_ENTITY(CXXNewExpr, operator_new, 44, MX_APPLY_METHOD, OperatorNew, FunctionDecl, NthStmt, DeclUseSelector::OPERATOR_NEW)
  MX_VISIT_BOOL(CXXNewExpr, has_initializer, 98, MX_APPLY_METHOD, HasInitializer, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, is_array, 100, MX_APPLY_METHOD, IsArray, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, is_global_new, 103, MX_APPLY_METHOD, IsGlobalNew, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, is_parenthesis_type_id, 104, MX_APPLY_METHOD, IsParenthesisTypeId, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, pass_alignment, 105, MX_APPLY_METHOD, PassAlignment, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(CXXNewExpr, placement_arguments, 16, MX_APPLY_METHOD, PlacementArguments, Expr, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, should_null_check_allocation, 106, MX_APPLY_METHOD, ShouldNullCheckAllocation, bool, NthStmt)
  MX_EXIT_VISIT_CXXNewExpr
MX_END_VISIT_STMT(CXXNewExpr)

#ifndef MX_ENTER_VISIT_CXXInheritedCtorInitExpr
#  define MX_ENTER_VISIT_CXXInheritedCtorInitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXInheritedCtorInitExpr
#  define MX_EXIT_VISIT_CXXInheritedCtorInitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXInheritedCtorInitExpr)
  MX_ENTER_VISIT_CXXInheritedCtorInitExpr
  MX_VISIT_BASE(CXXInheritedCtorInitExpr, Expr)
  MX_VISIT_BOOL(CXXInheritedCtorInitExpr, constructs_virtual_base, 94, MX_APPLY_METHOD, ConstructsVirtualBase, bool, NthStmt)
  MX_VISIT_ENUM(CXXInheritedCtorInitExpr, construction_kind, 99, MX_APPLY_METHOD, ConstructionKind, CXXConstructExprConstructionKind, NthStmt)
  MX_VISIT_ENTITY(CXXInheritedCtorInitExpr, constructor, 37, MX_APPLY_METHOD, Constructor, CXXConstructorDecl, NthStmt, DeclUseSelector::CONSTRUCTOR)
  MX_VISIT_ENTITY(CXXInheritedCtorInitExpr, token, 38, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXInheritedCtorInitExpr, inherited_from_virtual_base, 95, MX_APPLY_METHOD, InheritedFromVirtualBase, bool, NthStmt)
  MX_EXIT_VISIT_CXXInheritedCtorInitExpr
MX_END_VISIT_STMT(CXXInheritedCtorInitExpr)

#ifndef MX_ENTER_VISIT_CXXFoldExpr
#  define MX_ENTER_VISIT_CXXFoldExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXFoldExpr
#  define MX_EXIT_VISIT_CXXFoldExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXFoldExpr)
  MX_ENTER_VISIT_CXXFoldExpr
  MX_VISIT_BASE(CXXFoldExpr, Expr)
  MX_VISIT_ENTITY(CXXFoldExpr, callee, 37, MX_APPLY_METHOD, Callee, UnresolvedLookupExpr, NthStmt, StmtUseSelector::CALLEE)
  MX_VISIT_ENTITY(CXXFoldExpr, ellipsis_token, 38, MX_APPLY_METHOD, EllipsisToken, Token, NthStmt, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(CXXFoldExpr, initializer, 39, MX_APPLY_METHOD, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CXXFoldExpr, lhs, 40, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(CXXFoldExpr, l_paren_token, 41, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_OPTIONAL_INT(CXXFoldExpr, num_expansions, 108, MX_APPLY_METHOD, NumExpansions, unsigned, NthStmt)
  MX_VISIT_ENUM(CXXFoldExpr, operator_, 99, MX_APPLY_METHOD, Operator, BinaryOperatorKind, NthStmt)
  MX_VISIT_ENTITY(CXXFoldExpr, pattern, 42, MX_APPLY_METHOD, Pattern, Expr, NthStmt, StmtUseSelector::PATTERN)
  MX_VISIT_ENTITY(CXXFoldExpr, rhs, 43, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_ENTITY(CXXFoldExpr, r_paren_token, 44, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(CXXFoldExpr, is_left_fold, 95, MX_APPLY_METHOD, IsLeftFold, bool, NthStmt)
  MX_VISIT_BOOL(CXXFoldExpr, is_right_fold, 96, MX_APPLY_METHOD, IsRightFold, bool, NthStmt)
  MX_EXIT_VISIT_CXXFoldExpr
MX_END_VISIT_STMT(CXXFoldExpr)

#ifndef MX_ENTER_VISIT_CXXDependentScopeMemberExpr
#  define MX_ENTER_VISIT_CXXDependentScopeMemberExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXDependentScopeMemberExpr
#  define MX_EXIT_VISIT_CXXDependentScopeMemberExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXDependentScopeMemberExpr)
  MX_ENTER_VISIT_CXXDependentScopeMemberExpr
  MX_VISIT_BASE(CXXDependentScopeMemberExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(CXXDependentScopeMemberExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, base_type, 38, MX_APPLY_METHOD, BaseType, Type, NthStmt, TypeUseSelector::BASE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXDependentScopeMemberExpr, first_qualifier_found_in_scope, 39, MX_APPLY_METHOD, FirstQualifierFoundInScope, NamedDecl, NthStmt, DeclUseSelector::FIRST_QUALIFIER_FOUND_IN_SCOPE)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, l_angle_token, 40, MX_APPLY_METHOD, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, member_token, 41, MX_APPLY_METHOD, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, operator_token, 42, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, r_angle_token, 43, MX_APPLY_METHOD, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, template_keyword_token, 44, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, has_explicit_template_arguments, 96, MX_APPLY_METHOD, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, has_template_keyword, 97, MX_APPLY_METHOD, HasTemplateKeyword, bool, NthStmt)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, is_arrow, 98, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, is_implicit_access, 100, MX_APPLY_METHOD, IsImplicitAccess, bool, NthStmt)
  MX_EXIT_VISIT_CXXDependentScopeMemberExpr
MX_END_VISIT_STMT(CXXDependentScopeMemberExpr)

#ifndef MX_ENTER_VISIT_CXXDeleteExpr
#  define MX_ENTER_VISIT_CXXDeleteExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXDeleteExpr
#  define MX_EXIT_VISIT_CXXDeleteExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXDeleteExpr)
  MX_ENTER_VISIT_CXXDeleteExpr
  MX_VISIT_BASE(CXXDeleteExpr, Expr)
  MX_VISIT_BOOL(CXXDeleteExpr, does_usual_array_delete_want_size, 94, MX_APPLY_METHOD, DoesUsualArrayDeleteWantSize, bool, NthStmt)
  MX_VISIT_ENTITY(CXXDeleteExpr, argument, 37, MX_APPLY_METHOD, Argument, Expr, NthStmt, StmtUseSelector::ARGUMENT)
  MX_VISIT_ENTITY(CXXDeleteExpr, destroyed_type, 38, MX_APPLY_METHOD, DestroyedType, Type, NthStmt, TypeUseSelector::DESTROYED_TYPE)
  MX_VISIT_ENTITY(CXXDeleteExpr, operator_delete, 39, MX_APPLY_METHOD, OperatorDelete, FunctionDecl, NthStmt, DeclUseSelector::OPERATOR_DELETE)
  MX_VISIT_BOOL(CXXDeleteExpr, is_array_form, 95, MX_APPLY_METHOD, IsArrayForm, bool, NthStmt)
  MX_VISIT_BOOL(CXXDeleteExpr, is_array_form_as_written, 96, MX_APPLY_METHOD, IsArrayFormAsWritten, bool, NthStmt)
  MX_VISIT_BOOL(CXXDeleteExpr, is_global_delete, 97, MX_APPLY_METHOD, IsGlobalDelete, bool, NthStmt)
  MX_EXIT_VISIT_CXXDeleteExpr
MX_END_VISIT_STMT(CXXDeleteExpr)

#ifndef MX_ENTER_VISIT_CXXDefaultInitExpr
#  define MX_ENTER_VISIT_CXXDefaultInitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXDefaultInitExpr
#  define MX_EXIT_VISIT_CXXDefaultInitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXDefaultInitExpr)
  MX_ENTER_VISIT_CXXDefaultInitExpr
  MX_VISIT_BASE(CXXDefaultInitExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(CXXDefaultInitExpr, expression, 37, MX_APPLY_METHOD, Expression, Expr, NthStmt, StmtUseSelector::EXPRESSION)
  MX_VISIT_ENTITY(CXXDefaultInitExpr, field, 38, MX_APPLY_METHOD, Field, FieldDecl, NthStmt, DeclUseSelector::FIELD)
  MX_VISIT_ENTITY(CXXDefaultInitExpr, used_token, 39, MX_APPLY_METHOD, UsedToken, Token, NthStmt, TokenUseSelector::USED_TOKEN)
  MX_EXIT_VISIT_CXXDefaultInitExpr
MX_END_VISIT_STMT(CXXDefaultInitExpr)

#ifndef MX_ENTER_VISIT_CXXDefaultArgExpr
#  define MX_ENTER_VISIT_CXXDefaultArgExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXDefaultArgExpr
#  define MX_EXIT_VISIT_CXXDefaultArgExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXDefaultArgExpr)
  MX_ENTER_VISIT_CXXDefaultArgExpr
  MX_VISIT_BASE(CXXDefaultArgExpr, Expr)
  MX_VISIT_ENTITY(CXXDefaultArgExpr, expression, 37, MX_APPLY_METHOD, Expression, Expr, NthStmt, StmtUseSelector::EXPRESSION)
  MX_VISIT_ENTITY(CXXDefaultArgExpr, parameter, 38, MX_APPLY_METHOD, Parameter, ParmVarDecl, NthStmt, DeclUseSelector::PARAMETER)
  MX_VISIT_ENTITY(CXXDefaultArgExpr, used_token, 39, MX_APPLY_METHOD, UsedToken, Token, NthStmt, TokenUseSelector::USED_TOKEN)
  MX_EXIT_VISIT_CXXDefaultArgExpr
MX_END_VISIT_STMT(CXXDefaultArgExpr)

#ifndef MX_ENTER_VISIT_CXXConstructExpr
#  define MX_ENTER_VISIT_CXXConstructExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXConstructExpr
#  define MX_EXIT_VISIT_CXXConstructExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXConstructExpr)
  MX_ENTER_VISIT_CXXConstructExpr
  MX_VISIT_BASE(CXXConstructExpr, Expr)
  MX_VISIT_ENTITY_LIST(CXXConstructExpr, arguments, 16, MX_APPLY_METHOD, Arguments, Expr, NthStmt)
  MX_VISIT_ENUM(CXXConstructExpr, construction_kind, 99, MX_APPLY_METHOD, ConstructionKind, CXXConstructExprConstructionKind, NthStmt)
  MX_VISIT_ENTITY(CXXConstructExpr, constructor, 37, MX_APPLY_METHOD, Constructor, CXXConstructorDecl, NthStmt, DeclUseSelector::CONSTRUCTOR)
  MX_VISIT_ENTITY(CXXConstructExpr, token, 38, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXConstructExpr, had_multiple_candidates, 94, MX_APPLY_METHOD, HadMultipleCandidates, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, is_elidable, 95, MX_APPLY_METHOD, IsElidable, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, is_list_initialization, 96, MX_APPLY_METHOD, IsListInitialization, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, is_std_initializer_list_initialization, 97, MX_APPLY_METHOD, IsStdInitializerListInitialization, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, requires_zero_initialization, 98, MX_APPLY_METHOD, RequiresZeroInitialization, bool, NthStmt)
  MX_EXIT_VISIT_CXXConstructExpr
MX_END_VISIT_STMT(CXXConstructExpr)

#ifndef MX_ENTER_VISIT_CXXTemporaryObjectExpr
#  define MX_ENTER_VISIT_CXXTemporaryObjectExpr MX_ENTER_VISIT_CXXConstructExpr
#endif
#ifndef MX_EXIT_VISIT_CXXTemporaryObjectExpr
#  define MX_EXIT_VISIT_CXXTemporaryObjectExpr MX_EXIT_VISIT_CXXConstructExpr
#endif

MX_BEGIN_VISIT_STMT(CXXTemporaryObjectExpr)
  MX_ENTER_VISIT_CXXTemporaryObjectExpr
  MX_VISIT_BASE(CXXTemporaryObjectExpr, CXXConstructExpr)
  MX_EXIT_VISIT_CXXTemporaryObjectExpr
MX_END_VISIT_STMT(CXXTemporaryObjectExpr)

#ifndef MX_ENTER_VISIT_CXXBoolLiteralExpr
#  define MX_ENTER_VISIT_CXXBoolLiteralExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXBoolLiteralExpr
#  define MX_EXIT_VISIT_CXXBoolLiteralExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXBoolLiteralExpr)
  MX_ENTER_VISIT_CXXBoolLiteralExpr
  MX_VISIT_BASE(CXXBoolLiteralExpr, Expr)
  MX_VISIT_ENTITY(CXXBoolLiteralExpr, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXBoolLiteralExpr, value, 94, MX_APPLY_METHOD, Value, bool, NthStmt)
  MX_EXIT_VISIT_CXXBoolLiteralExpr
MX_END_VISIT_STMT(CXXBoolLiteralExpr)

#ifndef MX_ENTER_VISIT_CXXBindTemporaryExpr
#  define MX_ENTER_VISIT_CXXBindTemporaryExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_CXXBindTemporaryExpr
#  define MX_EXIT_VISIT_CXXBindTemporaryExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(CXXBindTemporaryExpr)
  MX_ENTER_VISIT_CXXBindTemporaryExpr
  MX_VISIT_BASE(CXXBindTemporaryExpr, Expr)
  MX_VISIT_ENTITY(CXXBindTemporaryExpr, sub_expression, 37, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_EXIT_VISIT_CXXBindTemporaryExpr
MX_END_VISIT_STMT(CXXBindTemporaryExpr)

#ifndef MX_ENTER_VISIT_BlockExpr
#  define MX_ENTER_VISIT_BlockExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_BlockExpr
#  define MX_EXIT_VISIT_BlockExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(BlockExpr)
  MX_ENTER_VISIT_BlockExpr
  MX_VISIT_BASE(BlockExpr, Expr)
  MX_VISIT_ENTITY(BlockExpr, block_declaration, 37, MX_APPLY_METHOD, BlockDeclaration, BlockDecl, NthStmt, DeclUseSelector::BLOCK_DECLARATION)
  MX_VISIT_ENTITY(BlockExpr, body, 38, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(BlockExpr, caret_token, 39, MX_APPLY_METHOD, CaretToken, Token, NthStmt, TokenUseSelector::CARET_TOKEN)
  MX_VISIT_ENTITY(BlockExpr, function_type, 40, MX_APPLY_METHOD, FunctionType, FunctionProtoType, NthStmt, TypeUseSelector::FUNCTION_TYPE)
  MX_EXIT_VISIT_BlockExpr
MX_END_VISIT_STMT(BlockExpr)

#ifndef MX_ENTER_VISIT_BinaryOperator
#  define MX_ENTER_VISIT_BinaryOperator MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_BinaryOperator
#  define MX_EXIT_VISIT_BinaryOperator MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(BinaryOperator)
  MX_ENTER_VISIT_BinaryOperator
  MX_VISIT_BASE(BinaryOperator, Expr)
  MX_VISIT_ENTITY(BinaryOperator, lhs, 37, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENUM(BinaryOperator, opcode, 99, MX_APPLY_METHOD, Opcode, BinaryOperatorKind, NthStmt)
  MX_VISIT_TEXT(BinaryOperator, opcode_string, 65, MX_APPLY_METHOD, OpcodeString, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(BinaryOperator, operator_token, 38, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(BinaryOperator, rhs, 39, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_BOOL(BinaryOperator, has_stored_fp_features, 94, MX_APPLY_METHOD, HasStoredFPFeatures, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_additive_operation, 95, MX_APPLY_METHOD, IsAdditiveOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_assignment_operation, 96, MX_APPLY_METHOD, IsAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_bitwise_operation, 97, MX_APPLY_METHOD, IsBitwiseOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_comma_operation, 98, MX_APPLY_METHOD, IsCommaOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_comparison_operation, 100, MX_APPLY_METHOD, IsComparisonOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_compound_assignment_operation, 103, MX_APPLY_METHOD, IsCompoundAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_equality_operation, 104, MX_APPLY_METHOD, IsEqualityOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_logical_operation, 105, MX_APPLY_METHOD, IsLogicalOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_multiplicative_operation, 106, MX_APPLY_METHOD, IsMultiplicativeOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_pointer_memory_operation, 107, MX_APPLY_METHOD, IsPointerMemoryOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_relational_operation, 109, MX_APPLY_METHOD, IsRelationalOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_shift_assign_operation, 110, MX_APPLY_METHOD, IsShiftAssignOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_shift_operation, 111, MX_APPLY_METHOD, IsShiftOperation, bool, NthStmt)
  MX_EXIT_VISIT_BinaryOperator
MX_END_VISIT_STMT(BinaryOperator)

#ifndef MX_ENTER_VISIT_CompoundAssignOperator
#  define MX_ENTER_VISIT_CompoundAssignOperator MX_ENTER_VISIT_BinaryOperator
#endif
#ifndef MX_EXIT_VISIT_CompoundAssignOperator
#  define MX_EXIT_VISIT_CompoundAssignOperator MX_EXIT_VISIT_BinaryOperator
#endif

MX_BEGIN_VISIT_STMT(CompoundAssignOperator)
  MX_ENTER_VISIT_CompoundAssignOperator
  MX_VISIT_BASE(CompoundAssignOperator, BinaryOperator)
  MX_VISIT_ENTITY(CompoundAssignOperator, computation_lhs_type, 40, MX_APPLY_METHOD, ComputationLHSType, Type, NthStmt, TypeUseSelector::COMPUTATION_LHS_TYPE)
  MX_VISIT_ENTITY(CompoundAssignOperator, computation_result_type, 41, MX_APPLY_METHOD, ComputationResultType, Type, NthStmt, TypeUseSelector::COMPUTATION_RESULT_TYPE)
  MX_EXIT_VISIT_CompoundAssignOperator
MX_END_VISIT_STMT(CompoundAssignOperator)

#ifndef MX_ENTER_VISIT_AtomicExpr
#  define MX_ENTER_VISIT_AtomicExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_AtomicExpr
#  define MX_EXIT_VISIT_AtomicExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(AtomicExpr)
  MX_ENTER_VISIT_AtomicExpr
  MX_VISIT_BASE(AtomicExpr, Expr)
  MX_VISIT_ENTITY(AtomicExpr, builtin_token, 37, MX_APPLY_METHOD, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENUM(AtomicExpr, operation, 99, MX_APPLY_METHOD, Operation, AtomicExprAtomicOp, NthStmt)
  MX_VISIT_ENTITY(AtomicExpr, order, 38, MX_APPLY_METHOD, Order, Expr, NthStmt, StmtUseSelector::ORDER)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, order_fail, 39, MX_APPLY_METHOD, OrderFail, Expr, NthStmt, StmtUseSelector::ORDER_FAIL)
  MX_VISIT_ENTITY(AtomicExpr, pointer, 40, MX_APPLY_METHOD, Pointer, Expr, NthStmt, StmtUseSelector::POINTER)
  MX_VISIT_ENTITY(AtomicExpr, r_paren_token, 41, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, scope, 42, MX_APPLY_METHOD, Scope, Expr, NthStmt, StmtUseSelector::SCOPE)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, value1, 43, MX_APPLY_METHOD, Value1, Expr, NthStmt, StmtUseSelector::VALUE1)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, value2, 44, MX_APPLY_METHOD, Value2, Expr, NthStmt, StmtUseSelector::VALUE2)
  MX_VISIT_ENTITY(AtomicExpr, value_type, 45, MX_APPLY_METHOD, ValueType, Type, NthStmt, TypeUseSelector::VALUE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, weak, 46, MX_APPLY_METHOD, Weak, Expr, NthStmt, StmtUseSelector::WEAK)
  MX_VISIT_BOOL(AtomicExpr, is_cmp_x_chg, 100, MX_APPLY_METHOD, IsCmpXChg, bool, NthStmt)
  MX_VISIT_BOOL(AtomicExpr, is_open_cl, 103, MX_APPLY_METHOD, IsOpenCL, bool, NthStmt)
  MX_VISIT_BOOL(AtomicExpr, is_volatile, 104, MX_APPLY_METHOD, IsVolatile, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(AtomicExpr, sub_expressions, 16, MX_APPLY_METHOD, SubExpressions, Expr, NthStmt)
  MX_EXIT_VISIT_AtomicExpr
MX_END_VISIT_STMT(AtomicExpr)

#ifndef MX_ENTER_VISIT_AsTypeExpr
#  define MX_ENTER_VISIT_AsTypeExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_AsTypeExpr
#  define MX_EXIT_VISIT_AsTypeExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(AsTypeExpr)
  MX_ENTER_VISIT_AsTypeExpr
  MX_VISIT_BASE(AsTypeExpr, Expr)
  MX_VISIT_ENTITY(AsTypeExpr, builtin_token, 37, MX_APPLY_METHOD, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(AsTypeExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(AsTypeExpr, src_expression, 39, MX_APPLY_METHOD, SrcExpression, Expr, NthStmt, StmtUseSelector::SRC_EXPRESSION)
  MX_EXIT_VISIT_AsTypeExpr
MX_END_VISIT_STMT(AsTypeExpr)

#ifndef MX_ENTER_VISIT_ArrayTypeTraitExpr
#  define MX_ENTER_VISIT_ArrayTypeTraitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ArrayTypeTraitExpr
#  define MX_EXIT_VISIT_ArrayTypeTraitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ArrayTypeTraitExpr)
  MX_ENTER_VISIT_ArrayTypeTraitExpr
  MX_VISIT_BASE(ArrayTypeTraitExpr, Expr)
  MX_VISIT_ENTITY(ArrayTypeTraitExpr, dimension_expression, 37, MX_APPLY_METHOD, DimensionExpression, Expr, NthStmt, StmtUseSelector::DIMENSION_EXPRESSION)
  MX_VISIT_ENTITY(ArrayTypeTraitExpr, queried_type, 38, MX_APPLY_METHOD, QueriedType, Type, NthStmt, TypeUseSelector::QUERIED_TYPE)
  MX_VISIT_ENUM(ArrayTypeTraitExpr, trait, 99, MX_APPLY_METHOD, Trait, ArrayTypeTrait, NthStmt)
  MX_EXIT_VISIT_ArrayTypeTraitExpr
MX_END_VISIT_STMT(ArrayTypeTraitExpr)

#ifndef MX_ENTER_VISIT_ArraySubscriptExpr
#  define MX_ENTER_VISIT_ArraySubscriptExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ArraySubscriptExpr
#  define MX_EXIT_VISIT_ArraySubscriptExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ArraySubscriptExpr)
  MX_ENTER_VISIT_ArraySubscriptExpr
  MX_VISIT_BASE(ArraySubscriptExpr, Expr)
  MX_VISIT_ENTITY(ArraySubscriptExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ArraySubscriptExpr, index, 38, MX_APPLY_METHOD, Index, Expr, NthStmt, StmtUseSelector::INDEX)
  MX_VISIT_ENTITY(ArraySubscriptExpr, lhs, 39, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(ArraySubscriptExpr, r_bracket_token, 40, MX_APPLY_METHOD, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(ArraySubscriptExpr, rhs, 41, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_EXIT_VISIT_ArraySubscriptExpr
MX_END_VISIT_STMT(ArraySubscriptExpr)

#ifndef MX_ENTER_VISIT_ArrayInitLoopExpr
#  define MX_ENTER_VISIT_ArrayInitLoopExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ArrayInitLoopExpr
#  define MX_EXIT_VISIT_ArrayInitLoopExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ArrayInitLoopExpr)
  MX_ENTER_VISIT_ArrayInitLoopExpr
  MX_VISIT_BASE(ArrayInitLoopExpr, Expr)
  MX_VISIT_ENTITY(ArrayInitLoopExpr, common_expression, 37, MX_APPLY_METHOD, CommonExpression, OpaqueValueExpr, NthStmt, StmtUseSelector::COMMON_EXPRESSION)
  MX_VISIT_ENTITY(ArrayInitLoopExpr, sub_expression, 38, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_EXIT_VISIT_ArrayInitLoopExpr
MX_END_VISIT_STMT(ArrayInitLoopExpr)

#ifndef MX_ENTER_VISIT_ArrayInitIndexExpr
#  define MX_ENTER_VISIT_ArrayInitIndexExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ArrayInitIndexExpr
#  define MX_EXIT_VISIT_ArrayInitIndexExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ArrayInitIndexExpr)
  MX_ENTER_VISIT_ArrayInitIndexExpr
  MX_VISIT_BASE(ArrayInitIndexExpr, Expr)
  MX_EXIT_VISIT_ArrayInitIndexExpr
MX_END_VISIT_STMT(ArrayInitIndexExpr)

#ifndef MX_ENTER_VISIT_AddrLabelExpr
#  define MX_ENTER_VISIT_AddrLabelExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_AddrLabelExpr
#  define MX_EXIT_VISIT_AddrLabelExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(AddrLabelExpr)
  MX_ENTER_VISIT_AddrLabelExpr
  MX_VISIT_BASE(AddrLabelExpr, Expr)
  MX_VISIT_ENTITY(AddrLabelExpr, amp_amp_token, 37, MX_APPLY_METHOD, AmpAmpToken, Token, NthStmt, TokenUseSelector::AMP_AMP_TOKEN)
  MX_VISIT_ENTITY(AddrLabelExpr, label, 38, MX_APPLY_METHOD, Label, LabelDecl, NthStmt, DeclUseSelector::LABEL)
  MX_VISIT_ENTITY(AddrLabelExpr, label_token, 39, MX_APPLY_METHOD, LabelToken, Token, NthStmt, TokenUseSelector::LABEL_TOKEN)
  MX_EXIT_VISIT_AddrLabelExpr
MX_END_VISIT_STMT(AddrLabelExpr)

#ifndef MX_ENTER_VISIT_AbstractConditionalOperator
#  define MX_ENTER_VISIT_AbstractConditionalOperator MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_AbstractConditionalOperator
#  define MX_EXIT_VISIT_AbstractConditionalOperator MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(AbstractConditionalOperator)
  MX_ENTER_VISIT_AbstractConditionalOperator
  MX_VISIT_BASE(AbstractConditionalOperator, Expr)
  MX_VISIT_ENTITY(AbstractConditionalOperator, colon_token, 37, MX_APPLY_METHOD, ColonToken, Token, NthStmt, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENTITY(AbstractConditionalOperator, condition, 38, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(AbstractConditionalOperator, false_expression, 39, MX_APPLY_METHOD, FalseExpression, Expr, NthStmt, StmtUseSelector::FALSE_EXPRESSION)
  MX_VISIT_ENTITY(AbstractConditionalOperator, question_token, 40, MX_APPLY_METHOD, QuestionToken, Token, NthStmt, TokenUseSelector::QUESTION_TOKEN)
  MX_VISIT_ENTITY(AbstractConditionalOperator, true_expression, 41, MX_APPLY_METHOD, TrueExpression, Expr, NthStmt, StmtUseSelector::TRUE_EXPRESSION)
  MX_EXIT_VISIT_AbstractConditionalOperator
MX_END_VISIT_STMT(AbstractConditionalOperator)

#ifndef MX_ENTER_VISIT_ConditionalOperator
#  define MX_ENTER_VISIT_ConditionalOperator MX_ENTER_VISIT_AbstractConditionalOperator
#endif
#ifndef MX_EXIT_VISIT_ConditionalOperator
#  define MX_EXIT_VISIT_ConditionalOperator MX_EXIT_VISIT_AbstractConditionalOperator
#endif

MX_BEGIN_VISIT_STMT(ConditionalOperator)
  MX_ENTER_VISIT_ConditionalOperator
  MX_VISIT_BASE(ConditionalOperator, AbstractConditionalOperator)
  MX_VISIT_ENTITY(ConditionalOperator, lhs, 42, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(ConditionalOperator, rhs, 43, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_EXIT_VISIT_ConditionalOperator
MX_END_VISIT_STMT(ConditionalOperator)

#ifndef MX_ENTER_VISIT_BinaryConditionalOperator
#  define MX_ENTER_VISIT_BinaryConditionalOperator MX_ENTER_VISIT_AbstractConditionalOperator
#endif
#ifndef MX_EXIT_VISIT_BinaryConditionalOperator
#  define MX_EXIT_VISIT_BinaryConditionalOperator MX_EXIT_VISIT_AbstractConditionalOperator
#endif

MX_BEGIN_VISIT_STMT(BinaryConditionalOperator)
  MX_ENTER_VISIT_BinaryConditionalOperator
  MX_VISIT_BASE(BinaryConditionalOperator, AbstractConditionalOperator)
  MX_VISIT_ENTITY(BinaryConditionalOperator, common, 42, MX_APPLY_METHOD, Common, Expr, NthStmt, StmtUseSelector::COMMON)
  MX_VISIT_ENTITY(BinaryConditionalOperator, opaque_value, 43, MX_APPLY_METHOD, OpaqueValue, OpaqueValueExpr, NthStmt, StmtUseSelector::OPAQUE_VALUE)
  MX_EXIT_VISIT_BinaryConditionalOperator
MX_END_VISIT_STMT(BinaryConditionalOperator)

#ifndef MX_ENTER_VISIT_VAArgExpr
#  define MX_ENTER_VISIT_VAArgExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_VAArgExpr
#  define MX_EXIT_VISIT_VAArgExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(VAArgExpr)
  MX_ENTER_VISIT_VAArgExpr
  MX_VISIT_BASE(VAArgExpr, Expr)
  MX_VISIT_ENTITY(VAArgExpr, builtin_token, 37, MX_APPLY_METHOD, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(VAArgExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(VAArgExpr, sub_expression, 39, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_ENTITY(VAArgExpr, written_type, 40, MX_APPLY_METHOD, WrittenType, Type, NthStmt, TypeUseSelector::WRITTEN_TYPE)
  MX_VISIT_BOOL(VAArgExpr, is_microsoft_abi, 94, MX_APPLY_METHOD, IsMicrosoftABI, bool, NthStmt)
  MX_EXIT_VISIT_VAArgExpr
MX_END_VISIT_STMT(VAArgExpr)

#ifndef MX_ENTER_VISIT_UnaryOperator
#  define MX_ENTER_VISIT_UnaryOperator MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_UnaryOperator
#  define MX_EXIT_VISIT_UnaryOperator MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(UnaryOperator)
  MX_ENTER_VISIT_UnaryOperator
  MX_VISIT_BASE(UnaryOperator, Expr)
  MX_VISIT_BOOL(UnaryOperator, can_overflow, 94, MX_APPLY_METHOD, CanOverflow, bool, NthStmt)
  MX_VISIT_ENUM(UnaryOperator, opcode, 99, MX_APPLY_METHOD, Opcode, UnaryOperatorKind, NthStmt)
  MX_VISIT_ENTITY(UnaryOperator, operator_token, 37, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(UnaryOperator, sub_expression, 38, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(UnaryOperator, has_stored_fp_features, 95, MX_APPLY_METHOD, HasStoredFPFeatures, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_arithmetic_operation, 96, MX_APPLY_METHOD, IsArithmeticOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_decrement_operation, 97, MX_APPLY_METHOD, IsDecrementOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_increment_decrement_operation, 98, MX_APPLY_METHOD, IsIncrementDecrementOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_increment_operation, 100, MX_APPLY_METHOD, IsIncrementOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_postfix, 103, MX_APPLY_METHOD, IsPostfix, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_prefix, 104, MX_APPLY_METHOD, IsPrefix, bool, NthStmt)
  MX_EXIT_VISIT_UnaryOperator
MX_END_VISIT_STMT(UnaryOperator)

#ifndef MX_ENTER_VISIT_UnaryExprOrTypeTraitExpr
#  define MX_ENTER_VISIT_UnaryExprOrTypeTraitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_UnaryExprOrTypeTraitExpr
#  define MX_EXIT_VISIT_UnaryExprOrTypeTraitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(UnaryExprOrTypeTraitExpr)
  MX_ENTER_VISIT_UnaryExprOrTypeTraitExpr
  MX_VISIT_BASE(UnaryExprOrTypeTraitExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_expression, 37, MX_APPLY_METHOD, ArgumentExpression, Expr, NthStmt, StmtUseSelector::ARGUMENT_EXPRESSION)
  MX_VISIT_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_type, 38, MX_APPLY_METHOD, ArgumentType, Type, NthStmt, TypeUseSelector::ARGUMENT_TYPE)
  MX_VISIT_ENUM(UnaryExprOrTypeTraitExpr, expression_or_trait_kind, 99, MX_APPLY_METHOD, Kind, UnaryExprOrTypeTrait, NthStmt)
  MX_VISIT_ENTITY(UnaryExprOrTypeTraitExpr, operator_token, 39, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(UnaryExprOrTypeTraitExpr, r_paren_token, 40, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(UnaryExprOrTypeTraitExpr, type_of_argument, 41, MX_APPLY_METHOD, TypeOfArgument, Type, NthStmt, TypeUseSelector::TYPE_OF_ARGUMENT)
  MX_VISIT_BOOL(UnaryExprOrTypeTraitExpr, is_argument_type, 96, MX_APPLY_METHOD, IsArgumentType, bool, NthStmt)
  MX_EXIT_VISIT_UnaryExprOrTypeTraitExpr
MX_END_VISIT_STMT(UnaryExprOrTypeTraitExpr)

#ifndef MX_ENTER_VISIT_TypoExpr
#  define MX_ENTER_VISIT_TypoExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_TypoExpr
#  define MX_EXIT_VISIT_TypoExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(TypoExpr)
  MX_ENTER_VISIT_TypoExpr
  MX_VISIT_BASE(TypoExpr, Expr)
  MX_EXIT_VISIT_TypoExpr
MX_END_VISIT_STMT(TypoExpr)

#ifndef MX_ENTER_VISIT_TypeTraitExpr
#  define MX_ENTER_VISIT_TypeTraitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_TypeTraitExpr
#  define MX_EXIT_VISIT_TypeTraitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(TypeTraitExpr)
  MX_ENTER_VISIT_TypeTraitExpr
  MX_VISIT_BASE(TypeTraitExpr, Expr)
  MX_VISIT_ENUM(TypeTraitExpr, trait, 99, MX_APPLY_METHOD, Trait, TypeTrait, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(TypeTraitExpr, value, 94, MX_APPLY_METHOD, Value, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(TypeTraitExpr, arguments, 16, MX_APPLY_METHOD, Arguments, Type, NthStmt)
  MX_EXIT_VISIT_TypeTraitExpr
MX_END_VISIT_STMT(TypeTraitExpr)

#ifndef MX_ENTER_VISIT_SubstNonTypeTemplateParmPackExpr
#  define MX_ENTER_VISIT_SubstNonTypeTemplateParmPackExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_SubstNonTypeTemplateParmPackExpr
#  define MX_EXIT_VISIT_SubstNonTypeTemplateParmPackExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(SubstNonTypeTemplateParmPackExpr)
  MX_ENTER_VISIT_SubstNonTypeTemplateParmPackExpr
  MX_VISIT_BASE(SubstNonTypeTemplateParmPackExpr, Expr)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmPackExpr, parameter_pack, 37, MX_APPLY_METHOD, ParameterPack, NonTypeTemplateParmDecl, NthStmt, DeclUseSelector::PARAMETER_PACK)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmPackExpr, parameter_pack_token, 38, MX_APPLY_METHOD, ParameterPackToken, Token, NthStmt, TokenUseSelector::PARAMETER_PACK_TOKEN)
  MX_EXIT_VISIT_SubstNonTypeTemplateParmPackExpr
MX_END_VISIT_STMT(SubstNonTypeTemplateParmPackExpr)

#ifndef MX_ENTER_VISIT_SubstNonTypeTemplateParmExpr
#  define MX_ENTER_VISIT_SubstNonTypeTemplateParmExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_SubstNonTypeTemplateParmExpr
#  define MX_EXIT_VISIT_SubstNonTypeTemplateParmExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(SubstNonTypeTemplateParmExpr)
  MX_ENTER_VISIT_SubstNonTypeTemplateParmExpr
  MX_VISIT_BASE(SubstNonTypeTemplateParmExpr, Expr)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, name_token, 37, MX_APPLY_METHOD, NameToken, Token, NthStmt, TokenUseSelector::NAME_TOKEN)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, parameter, 38, MX_APPLY_METHOD, Parameter, NonTypeTemplateParmDecl, NthStmt, DeclUseSelector::PARAMETER)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, parameter_type, 39, MX_APPLY_METHOD, ParameterType, Type, NthStmt, TypeUseSelector::PARAMETER_TYPE)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, replacement, 40, MX_APPLY_METHOD, Replacement, Expr, NthStmt, StmtUseSelector::REPLACEMENT)
  MX_VISIT_BOOL(SubstNonTypeTemplateParmExpr, is_reference_parameter, 94, MX_APPLY_METHOD, IsReferenceParameter, bool, NthStmt)
  MX_EXIT_VISIT_SubstNonTypeTemplateParmExpr
MX_END_VISIT_STMT(SubstNonTypeTemplateParmExpr)

#ifndef MX_ENTER_VISIT_StringLiteral
#  define MX_ENTER_VISIT_StringLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_StringLiteral
#  define MX_EXIT_VISIT_StringLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(StringLiteral)
  MX_ENTER_VISIT_StringLiteral
  MX_VISIT_BASE(StringLiteral, Expr)
  MX_VISIT_OPTIONAL_BOOL(StringLiteral, contains_non_ascii, 94, MX_APPLY_METHOD, ContainsNonAscii, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(StringLiteral, contains_non_ascii_or_null, 96, MX_APPLY_METHOD, ContainsNonAsciiOrNull, bool, NthStmt)
  MX_VISIT_TEXT(StringLiteral, bytes, 65, MX_APPLY_METHOD, Bytes, basic_string_view, NthStmt)
  MX_VISIT_ENUM(StringLiteral, string_kind, 99, MX_APPLY_METHOD, Kind, StringLiteralStringKind, NthStmt)
  MX_VISIT_OPTIONAL_TEXT(StringLiteral, string, 70, MX_APPLY_METHOD, String, basic_string_view, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_ascii, 100, MX_APPLY_METHOD, IsAscii, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_pascal, 103, MX_APPLY_METHOD, IsPascal, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_utf16, 104, MX_APPLY_METHOD, IsUTF16, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_utf32, 105, MX_APPLY_METHOD, IsUTF32, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_utf8, 106, MX_APPLY_METHOD, IsUTF8, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_wide, 107, MX_APPLY_METHOD, IsWide, bool, NthStmt)
  MX_EXIT_VISIT_StringLiteral
MX_END_VISIT_STMT(StringLiteral)

#ifndef MX_ENTER_VISIT_StmtExpr
#  define MX_ENTER_VISIT_StmtExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_StmtExpr
#  define MX_EXIT_VISIT_StmtExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(StmtExpr)
  MX_ENTER_VISIT_StmtExpr
  MX_VISIT_BASE(StmtExpr, Expr)
  MX_VISIT_ENTITY(StmtExpr, l_paren_token, 37, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(StmtExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(StmtExpr, sub_statement, 39, MX_APPLY_METHOD, SubStatement, CompoundStmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_EXIT_VISIT_StmtExpr
MX_END_VISIT_STMT(StmtExpr)

#ifndef MX_ENTER_VISIT_SourceLocExpr
#  define MX_ENTER_VISIT_SourceLocExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_SourceLocExpr
#  define MX_EXIT_VISIT_SourceLocExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(SourceLocExpr)
  MX_ENTER_VISIT_SourceLocExpr
  MX_VISIT_BASE(SourceLocExpr, Expr)
  MX_VISIT_TEXT(SourceLocExpr, builtin_string, 65, MX_APPLY_METHOD, BuiltinString, basic_string_view, NthStmt)
  MX_VISIT_ENUM(SourceLocExpr, identifier_kind, 99, MX_APPLY_METHOD, IdentifierKind, SourceLocExprIdentKind, NthStmt)
  MX_VISIT_ENTITY(SourceLocExpr, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(SourceLocExpr, is_int_type, 94, MX_APPLY_METHOD, IsIntType, bool, NthStmt)
  MX_VISIT_BOOL(SourceLocExpr, is_string_type, 95, MX_APPLY_METHOD, IsStringType, bool, NthStmt)
  MX_EXIT_VISIT_SourceLocExpr
MX_END_VISIT_STMT(SourceLocExpr)

#ifndef MX_ENTER_VISIT_SizeOfPackExpr
#  define MX_ENTER_VISIT_SizeOfPackExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_SizeOfPackExpr
#  define MX_EXIT_VISIT_SizeOfPackExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(SizeOfPackExpr)
  MX_ENTER_VISIT_SizeOfPackExpr
  MX_VISIT_BASE(SizeOfPackExpr, Expr)
  MX_VISIT_ENTITY(SizeOfPackExpr, operator_token, 37, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(SizeOfPackExpr, pack, 38, MX_APPLY_METHOD, Pack, NamedDecl, NthStmt, DeclUseSelector::PACK)
  MX_VISIT_OPTIONAL_INT(SizeOfPackExpr, pack_length, 108, MX_APPLY_METHOD, PackLength, unsigned, NthStmt)
  MX_VISIT_ENTITY(SizeOfPackExpr, pack_token, 39, MX_APPLY_METHOD, PackToken, Token, NthStmt, TokenUseSelector::PACK_TOKEN)
  MX_VISIT_OPTIONAL_PSEUDO_LIST(SizeOfPackExpr, partial_arguments, 101, MX_APPLY_METHOD, PartialArguments, TemplateArgument, NthStmt)
  MX_VISIT_ENTITY(SizeOfPackExpr, r_paren_token, 40, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(SizeOfPackExpr, is_partially_substituted, 96, MX_APPLY_METHOD, IsPartiallySubstituted, bool, NthStmt)
  MX_EXIT_VISIT_SizeOfPackExpr
MX_END_VISIT_STMT(SizeOfPackExpr)

#ifndef MX_ENTER_VISIT_ShuffleVectorExpr
#  define MX_ENTER_VISIT_ShuffleVectorExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ShuffleVectorExpr
#  define MX_EXIT_VISIT_ShuffleVectorExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ShuffleVectorExpr)
  MX_ENTER_VISIT_ShuffleVectorExpr
  MX_VISIT_BASE(ShuffleVectorExpr, Expr)
  MX_VISIT_ENTITY(ShuffleVectorExpr, builtin_token, 37, MX_APPLY_METHOD, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(ShuffleVectorExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_ShuffleVectorExpr
MX_END_VISIT_STMT(ShuffleVectorExpr)

#ifndef MX_ENTER_VISIT_SYCLUniqueStableNameExpr
#  define MX_ENTER_VISIT_SYCLUniqueStableNameExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_SYCLUniqueStableNameExpr
#  define MX_EXIT_VISIT_SYCLUniqueStableNameExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(SYCLUniqueStableNameExpr)
  MX_ENTER_VISIT_SYCLUniqueStableNameExpr
  MX_VISIT_BASE(SYCLUniqueStableNameExpr, Expr)
  MX_VISIT_TEXT(SYCLUniqueStableNameExpr, compute_name, 65, MX_APPLY_METHOD, ComputeName, basic_string, NthStmt)
  MX_VISIT_ENTITY(SYCLUniqueStableNameExpr, l_paren_token, 37, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(SYCLUniqueStableNameExpr, token, 38, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(SYCLUniqueStableNameExpr, r_paren_token, 39, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_SYCLUniqueStableNameExpr
MX_END_VISIT_STMT(SYCLUniqueStableNameExpr)

#ifndef MX_ENTER_VISIT_RequiresExpr
#  define MX_ENTER_VISIT_RequiresExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_RequiresExpr
#  define MX_EXIT_VISIT_RequiresExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(RequiresExpr)
  MX_ENTER_VISIT_RequiresExpr
  MX_VISIT_BASE(RequiresExpr, Expr)
  MX_VISIT_ENTITY(RequiresExpr, body, 37, MX_APPLY_METHOD, Body, RequiresExprBodyDecl, NthStmt, DeclUseSelector::BODY)
  MX_VISIT_ENTITY_LIST(RequiresExpr, local_parameters, 16, MX_APPLY_METHOD, LocalParameters, ParmVarDecl, NthStmt)
  MX_VISIT_ENTITY(RequiresExpr, r_brace_token, 38, MX_APPLY_METHOD, RBraceToken, Token, NthStmt, TokenUseSelector::R_BRACE_TOKEN)
  MX_VISIT_ENTITY(RequiresExpr, requires_keyword_token, 39, MX_APPLY_METHOD, RequiresKeywordToken, Token, NthStmt, TokenUseSelector::REQUIRES_KEYWORD_TOKEN)
  MX_VISIT_BOOL(RequiresExpr, is_satisfied, 94, MX_APPLY_METHOD, IsSatisfied, bool, NthStmt)
  MX_EXIT_VISIT_RequiresExpr
MX_END_VISIT_STMT(RequiresExpr)

#ifndef MX_ENTER_VISIT_RecoveryExpr
#  define MX_ENTER_VISIT_RecoveryExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_RecoveryExpr
#  define MX_EXIT_VISIT_RecoveryExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(RecoveryExpr)
  MX_ENTER_VISIT_RecoveryExpr
  MX_VISIT_BASE(RecoveryExpr, Expr)
  MX_VISIT_ENTITY_LIST(RecoveryExpr, sub_expressions, 16, MX_APPLY_METHOD, SubExpressions, Expr, NthStmt)
  MX_EXIT_VISIT_RecoveryExpr
MX_END_VISIT_STMT(RecoveryExpr)

#ifndef MX_ENTER_VISIT_PseudoObjectExpr
#  define MX_ENTER_VISIT_PseudoObjectExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_PseudoObjectExpr
#  define MX_EXIT_VISIT_PseudoObjectExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(PseudoObjectExpr)
  MX_ENTER_VISIT_PseudoObjectExpr
  MX_VISIT_BASE(PseudoObjectExpr, Expr)
  MX_VISIT_ENTITY(PseudoObjectExpr, result_expression, 37, MX_APPLY_METHOD, ResultExpression, Expr, NthStmt, StmtUseSelector::RESULT_EXPRESSION)
  MX_VISIT_ENTITY(PseudoObjectExpr, syntactic_form, 38, MX_APPLY_METHOD, SyntacticForm, Expr, NthStmt, StmtUseSelector::SYNTACTIC_FORM)
  MX_VISIT_ENTITY_LIST(PseudoObjectExpr, semantics, 16, MX_APPLY_METHOD, Semantics, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(PseudoObjectExpr, semantic_expressions, 22, MX_APPLY_METHOD, SemanticExpressions, Expr, NthStmt)
  MX_EXIT_VISIT_PseudoObjectExpr
MX_END_VISIT_STMT(PseudoObjectExpr)

#ifndef MX_ENTER_VISIT_PredefinedExpr
#  define MX_ENTER_VISIT_PredefinedExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_PredefinedExpr
#  define MX_EXIT_VISIT_PredefinedExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(PredefinedExpr)
  MX_ENTER_VISIT_PredefinedExpr
  MX_VISIT_BASE(PredefinedExpr, Expr)
  MX_VISIT_ENTITY(PredefinedExpr, function_name, 37, MX_APPLY_METHOD, FunctionName, StringLiteral, NthStmt, StmtUseSelector::FUNCTION_NAME)
  MX_VISIT_ENUM(PredefinedExpr, identifier_kind, 99, MX_APPLY_METHOD, IdentifierKind, PredefinedExprIdentKind, NthStmt)
  MX_VISIT_TEXT(PredefinedExpr, identifier_kind_name, 65, MX_APPLY_METHOD, IdentifierKindName, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(PredefinedExpr, token, 38, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_EXIT_VISIT_PredefinedExpr
MX_END_VISIT_STMT(PredefinedExpr)

#ifndef MX_ENTER_VISIT_ParenListExpr
#  define MX_ENTER_VISIT_ParenListExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ParenListExpr
#  define MX_EXIT_VISIT_ParenListExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ParenListExpr)
  MX_ENTER_VISIT_ParenListExpr
  MX_VISIT_BASE(ParenListExpr, Expr)
  MX_VISIT_ENTITY(ParenListExpr, l_paren_token, 37, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(ParenListExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY_LIST(ParenListExpr, expressions, 16, MX_APPLY_METHOD, Expressions, Expr, NthStmt)
  MX_EXIT_VISIT_ParenListExpr
MX_END_VISIT_STMT(ParenListExpr)

#ifndef MX_ENTER_VISIT_ParenExpr
#  define MX_ENTER_VISIT_ParenExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ParenExpr
#  define MX_EXIT_VISIT_ParenExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ParenExpr)
  MX_ENTER_VISIT_ParenExpr
  MX_VISIT_BASE(ParenExpr, Expr)
  MX_VISIT_ENTITY(ParenExpr, l_paren_token, 37, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(ParenExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(ParenExpr, sub_expression, 39, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_EXIT_VISIT_ParenExpr
MX_END_VISIT_STMT(ParenExpr)

#ifndef MX_ENTER_VISIT_PackExpansionExpr
#  define MX_ENTER_VISIT_PackExpansionExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_PackExpansionExpr
#  define MX_EXIT_VISIT_PackExpansionExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(PackExpansionExpr)
  MX_ENTER_VISIT_PackExpansionExpr
  MX_VISIT_BASE(PackExpansionExpr, Expr)
  MX_VISIT_ENTITY(PackExpansionExpr, ellipsis_token, 37, MX_APPLY_METHOD, EllipsisToken, Token, NthStmt, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_OPTIONAL_INT(PackExpansionExpr, num_expansions, 108, MX_APPLY_METHOD, NumExpansions, unsigned, NthStmt)
  MX_VISIT_ENTITY(PackExpansionExpr, pattern, 38, MX_APPLY_METHOD, Pattern, Expr, NthStmt, StmtUseSelector::PATTERN)
  MX_EXIT_VISIT_PackExpansionExpr
MX_END_VISIT_STMT(PackExpansionExpr)

#ifndef MX_ENTER_VISIT_OverloadExpr
#  define MX_ENTER_VISIT_OverloadExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_OverloadExpr
#  define MX_EXIT_VISIT_OverloadExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(OverloadExpr)
  MX_ENTER_VISIT_OverloadExpr
  MX_VISIT_BASE(OverloadExpr, Expr)
  MX_VISIT_ENTITY(OverloadExpr, l_angle_token, 37, MX_APPLY_METHOD, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(OverloadExpr, name_token, 38, MX_APPLY_METHOD, NameToken, Token, NthStmt, TokenUseSelector::NAME_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(OverloadExpr, naming_class, 39, MX_APPLY_METHOD, NamingClass, CXXRecordDecl, NthStmt, DeclUseSelector::NAMING_CLASS)
  MX_VISIT_ENTITY(OverloadExpr, r_angle_token, 40, MX_APPLY_METHOD, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(OverloadExpr, template_keyword_token, 41, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(OverloadExpr, has_explicit_template_arguments, 95, MX_APPLY_METHOD, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(OverloadExpr, has_template_keyword, 96, MX_APPLY_METHOD, HasTemplateKeyword, bool, NthStmt)
  MX_EXIT_VISIT_OverloadExpr
MX_END_VISIT_STMT(OverloadExpr)

#ifndef MX_ENTER_VISIT_UnresolvedMemberExpr
#  define MX_ENTER_VISIT_UnresolvedMemberExpr MX_ENTER_VISIT_OverloadExpr
#endif
#ifndef MX_EXIT_VISIT_UnresolvedMemberExpr
#  define MX_EXIT_VISIT_UnresolvedMemberExpr MX_EXIT_VISIT_OverloadExpr
#endif

MX_BEGIN_VISIT_STMT(UnresolvedMemberExpr)
  MX_ENTER_VISIT_UnresolvedMemberExpr
  MX_VISIT_BASE(UnresolvedMemberExpr, OverloadExpr)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, base, 42, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, base_type, 43, MX_APPLY_METHOD, BaseType, Type, NthStmt, TypeUseSelector::BASE_TYPE)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, member_token, 44, MX_APPLY_METHOD, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, operator_token, 45, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_BOOL(UnresolvedMemberExpr, has_unresolved_using, 97, MX_APPLY_METHOD, HasUnresolvedUsing, bool, NthStmt)
  MX_VISIT_BOOL(UnresolvedMemberExpr, is_arrow, 98, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(UnresolvedMemberExpr, is_implicit_access, 100, MX_APPLY_METHOD, IsImplicitAccess, bool, NthStmt)
  MX_EXIT_VISIT_UnresolvedMemberExpr
MX_END_VISIT_STMT(UnresolvedMemberExpr)

#ifndef MX_ENTER_VISIT_UnresolvedLookupExpr
#  define MX_ENTER_VISIT_UnresolvedLookupExpr MX_ENTER_VISIT_OverloadExpr
#endif
#ifndef MX_EXIT_VISIT_UnresolvedLookupExpr
#  define MX_EXIT_VISIT_UnresolvedLookupExpr MX_EXIT_VISIT_OverloadExpr
#endif

MX_BEGIN_VISIT_STMT(UnresolvedLookupExpr)
  MX_ENTER_VISIT_UnresolvedLookupExpr
  MX_VISIT_BASE(UnresolvedLookupExpr, OverloadExpr)
  MX_VISIT_BOOL(UnresolvedLookupExpr, is_overloaded, 97, MX_APPLY_METHOD, IsOverloaded, bool, NthStmt)
  MX_VISIT_BOOL(UnresolvedLookupExpr, requires_adl, 98, MX_APPLY_METHOD, RequiresADL, bool, NthStmt)
  MX_EXIT_VISIT_UnresolvedLookupExpr
MX_END_VISIT_STMT(UnresolvedLookupExpr)

#ifndef MX_ENTER_VISIT_OpaqueValueExpr
#  define MX_ENTER_VISIT_OpaqueValueExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_OpaqueValueExpr
#  define MX_EXIT_VISIT_OpaqueValueExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(OpaqueValueExpr)
  MX_ENTER_VISIT_OpaqueValueExpr
  MX_VISIT_BASE(OpaqueValueExpr, Expr)
  MX_VISIT_ENTITY(OpaqueValueExpr, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(OpaqueValueExpr, source_expression, 38, MX_APPLY_METHOD, SourceExpression, Expr, NthStmt, StmtUseSelector::SOURCE_EXPRESSION)
  MX_VISIT_BOOL(OpaqueValueExpr, is_unique, 94, MX_APPLY_METHOD, IsUnique, bool, NthStmt)
  MX_EXIT_VISIT_OpaqueValueExpr
MX_END_VISIT_STMT(OpaqueValueExpr)

#ifndef MX_ENTER_VISIT_OffsetOfExpr
#  define MX_ENTER_VISIT_OffsetOfExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_OffsetOfExpr
#  define MX_EXIT_VISIT_OffsetOfExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(OffsetOfExpr)
  MX_ENTER_VISIT_OffsetOfExpr
  MX_VISIT_BASE(OffsetOfExpr, Expr)
  MX_VISIT_ENTITY(OffsetOfExpr, operator_token, 37, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(OffsetOfExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_OffsetOfExpr
MX_END_VISIT_STMT(OffsetOfExpr)

#ifndef MX_ENTER_VISIT_ObjCSubscriptRefExpr
#  define MX_ENTER_VISIT_ObjCSubscriptRefExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCSubscriptRefExpr
#  define MX_EXIT_VISIT_ObjCSubscriptRefExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCSubscriptRefExpr)
  MX_ENTER_VISIT_ObjCSubscriptRefExpr
  MX_VISIT_BASE(ObjCSubscriptRefExpr, Expr)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, at_index_method_declaration, 37, MX_APPLY_METHOD, AtIndexMethodDeclaration, ObjCMethodDecl, NthStmt, DeclUseSelector::AT_INDEX_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, base_expression, 38, MX_APPLY_METHOD, BaseExpression, Expr, NthStmt, StmtUseSelector::BASE_EXPRESSION)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, key_expression, 39, MX_APPLY_METHOD, KeyExpression, Expr, NthStmt, StmtUseSelector::KEY_EXPRESSION)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, r_bracket_token, 40, MX_APPLY_METHOD, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_BOOL(ObjCSubscriptRefExpr, is_array_subscript_reference_expression, 94, MX_APPLY_METHOD, IsArraySubscriptReferenceExpression, bool, NthStmt)
  MX_EXIT_VISIT_ObjCSubscriptRefExpr
MX_END_VISIT_STMT(ObjCSubscriptRefExpr)

#ifndef MX_ENTER_VISIT_ObjCStringLiteral
#  define MX_ENTER_VISIT_ObjCStringLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCStringLiteral
#  define MX_EXIT_VISIT_ObjCStringLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCStringLiteral)
  MX_ENTER_VISIT_ObjCStringLiteral
  MX_VISIT_BASE(ObjCStringLiteral, Expr)
  MX_VISIT_ENTITY(ObjCStringLiteral, at_token, 37, MX_APPLY_METHOD, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCStringLiteral, string, 38, MX_APPLY_METHOD, String, StringLiteral, NthStmt, StmtUseSelector::STRING)
  MX_EXIT_VISIT_ObjCStringLiteral
MX_END_VISIT_STMT(ObjCStringLiteral)

#ifndef MX_ENTER_VISIT_ObjCSelectorExpr
#  define MX_ENTER_VISIT_ObjCSelectorExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCSelectorExpr
#  define MX_EXIT_VISIT_ObjCSelectorExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCSelectorExpr)
  MX_ENTER_VISIT_ObjCSelectorExpr
  MX_VISIT_BASE(ObjCSelectorExpr, Expr)
  MX_VISIT_ENTITY(ObjCSelectorExpr, at_token, 37, MX_APPLY_METHOD, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCSelectorExpr, r_paren_token, 38, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_ObjCSelectorExpr
MX_END_VISIT_STMT(ObjCSelectorExpr)

#ifndef MX_ENTER_VISIT_ObjCProtocolExpr
#  define MX_ENTER_VISIT_ObjCProtocolExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCProtocolExpr
#  define MX_EXIT_VISIT_ObjCProtocolExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCProtocolExpr)
  MX_ENTER_VISIT_ObjCProtocolExpr
  MX_VISIT_BASE(ObjCProtocolExpr, Expr)
  MX_VISIT_ENTITY(ObjCProtocolExpr, at_token, 37, MX_APPLY_METHOD, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCProtocolExpr, protocol, 38, MX_APPLY_METHOD, Protocol, ObjCProtocolDecl, NthStmt, DeclUseSelector::PROTOCOL)
  MX_VISIT_ENTITY(ObjCProtocolExpr, protocol_id_token, 39, MX_APPLY_METHOD, ProtocolIdToken, Token, NthStmt, TokenUseSelector::PROTOCOL_ID_TOKEN)
  MX_VISIT_ENTITY(ObjCProtocolExpr, r_paren_token, 40, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_ObjCProtocolExpr
MX_END_VISIT_STMT(ObjCProtocolExpr)

#ifndef MX_ENTER_VISIT_ObjCPropertyRefExpr
#  define MX_ENTER_VISIT_ObjCPropertyRefExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCPropertyRefExpr
#  define MX_EXIT_VISIT_ObjCPropertyRefExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCPropertyRefExpr)
  MX_ENTER_VISIT_ObjCPropertyRefExpr
  MX_VISIT_BASE(ObjCPropertyRefExpr, Expr)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, class_receiver, 38, MX_APPLY_METHOD, ClassReceiver, ObjCInterfaceDecl, NthStmt, DeclUseSelector::CLASS_RECEIVER)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, explicit_property, 39, MX_APPLY_METHOD, ExplicitProperty, ObjCPropertyDecl, NthStmt, DeclUseSelector::EXPLICIT_PROPERTY)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, implicit_property_getter, 40, MX_APPLY_METHOD, ImplicitPropertyGetter, ObjCMethodDecl, NthStmt, DeclUseSelector::IMPLICIT_PROPERTY_GETTER)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, implicit_property_setter, 41, MX_APPLY_METHOD, ImplicitPropertySetter, ObjCMethodDecl, NthStmt, DeclUseSelector::IMPLICIT_PROPERTY_SETTER)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, token, 42, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, receiver_token, 43, MX_APPLY_METHOD, ReceiverToken, Token, NthStmt, TokenUseSelector::RECEIVER_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, receiver_type, 44, MX_APPLY_METHOD, ReceiverType, Type, NthStmt, TypeUseSelector::RECEIVER_TYPE)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, super_receiver_type, 45, MX_APPLY_METHOD, SuperReceiverType, Type, NthStmt, TypeUseSelector::SUPER_RECEIVER_TYPE)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_class_receiver, 94, MX_APPLY_METHOD, IsClassReceiver, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_explicit_property, 95, MX_APPLY_METHOD, IsExplicitProperty, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_implicit_property, 96, MX_APPLY_METHOD, IsImplicitProperty, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_messaging_getter, 97, MX_APPLY_METHOD, IsMessagingGetter, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_messaging_setter, 98, MX_APPLY_METHOD, IsMessagingSetter, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_object_receiver, 100, MX_APPLY_METHOD, IsObjectReceiver, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_super_receiver, 103, MX_APPLY_METHOD, IsSuperReceiver, bool, NthStmt)
  MX_EXIT_VISIT_ObjCPropertyRefExpr
MX_END_VISIT_STMT(ObjCPropertyRefExpr)

#ifndef MX_ENTER_VISIT_ObjCMessageExpr
#  define MX_ENTER_VISIT_ObjCMessageExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCMessageExpr
#  define MX_EXIT_VISIT_ObjCMessageExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCMessageExpr)
  MX_ENTER_VISIT_ObjCMessageExpr
  MX_VISIT_BASE(ObjCMessageExpr, Expr)
  MX_VISIT_ENTITY_LIST(ObjCMessageExpr, arguments, 16, MX_APPLY_METHOD, Arguments, Expr, NthStmt)
  MX_VISIT_ENTITY(ObjCMessageExpr, call_return_type, 37, MX_APPLY_METHOD, CallReturnType, Type, NthStmt, TypeUseSelector::CALL_RETURN_TYPE)
  MX_VISIT_ENTITY(ObjCMessageExpr, class_receiver, 38, MX_APPLY_METHOD, ClassReceiver, Type, NthStmt, TypeUseSelector::CLASS_RECEIVER)
  MX_VISIT_ENTITY(ObjCMessageExpr, class_receiver_type, 39, MX_APPLY_METHOD, ClassReceiverType, Type, NthStmt, TypeUseSelector::CLASS_RECEIVER_TYPE)
  MX_VISIT_ENTITY(ObjCMessageExpr, instance_receiver, 40, MX_APPLY_METHOD, InstanceReceiver, Expr, NthStmt, StmtUseSelector::INSTANCE_RECEIVER)
  MX_VISIT_ENTITY(ObjCMessageExpr, left_token, 41, MX_APPLY_METHOD, LeftToken, Token, NthStmt, TokenUseSelector::LEFT_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, method_declaration, 42, MX_APPLY_METHOD, MethodDeclaration, ObjCMethodDecl, NthStmt, DeclUseSelector::METHOD_DECLARATION)
  MX_VISIT_ENUM(ObjCMessageExpr, method_family, 99, MX_APPLY_METHOD, MethodFamily, ObjCMethodFamily, NthStmt)
  MX_VISIT_ENTITY(ObjCMessageExpr, receiver_interface, 43, MX_APPLY_METHOD, ReceiverInterface, ObjCInterfaceDecl, NthStmt, DeclUseSelector::RECEIVER_INTERFACE)
  MX_VISIT_ENUM(ObjCMessageExpr, receiver_kind, 102, MX_APPLY_METHOD, ReceiverKind, ObjCMessageExprReceiverKind, NthStmt)
  MX_VISIT_ENTITY(ObjCMessageExpr, receiver_type, 46, MX_APPLY_METHOD, ReceiverType, Type, NthStmt, TypeUseSelector::RECEIVER_TYPE)
  MX_VISIT_ENTITY(ObjCMessageExpr, right_token, 47, MX_APPLY_METHOD, RightToken, Token, NthStmt, TokenUseSelector::RIGHT_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, selector_start_token, 48, MX_APPLY_METHOD, SelectorStartToken, Token, NthStmt, TokenUseSelector::SELECTOR_START_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, super_token, 49, MX_APPLY_METHOD, SuperToken, Token, NthStmt, TokenUseSelector::SUPER_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, super_type, 50, MX_APPLY_METHOD, SuperType, Type, NthStmt, TypeUseSelector::SUPER_TYPE)
  MX_VISIT_BOOL(ObjCMessageExpr, is_class_message, 94, MX_APPLY_METHOD, IsClassMessage, bool, NthStmt)
  MX_VISIT_BOOL(ObjCMessageExpr, is_delegate_initializer_call, 95, MX_APPLY_METHOD, IsDelegateInitializerCall, bool, NthStmt)
  MX_VISIT_BOOL(ObjCMessageExpr, is_implicit, 96, MX_APPLY_METHOD, IsImplicit, bool, NthStmt)
  MX_VISIT_BOOL(ObjCMessageExpr, is_instance_message, 97, MX_APPLY_METHOD, IsInstanceMessage, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(ObjCMessageExpr, selector_tokens, 22, MX_APPLY_METHOD, SelectorTokens, Token, NthStmt)
  MX_EXIT_VISIT_ObjCMessageExpr
MX_END_VISIT_STMT(ObjCMessageExpr)

#ifndef MX_ENTER_VISIT_ObjCIvarRefExpr
#  define MX_ENTER_VISIT_ObjCIvarRefExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCIvarRefExpr
#  define MX_EXIT_VISIT_ObjCIvarRefExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCIvarRefExpr)
  MX_ENTER_VISIT_ObjCIvarRefExpr
  MX_VISIT_BASE(ObjCIvarRefExpr, Expr)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, declaration, 38, MX_APPLY_METHOD, Declaration, ObjCIvarDecl, NthStmt, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, token, 39, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, operation_token, 40, MX_APPLY_METHOD, OperationToken, Token, NthStmt, TokenUseSelector::OPERATION_TOKEN)
  MX_VISIT_BOOL(ObjCIvarRefExpr, is_arrow, 94, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(ObjCIvarRefExpr, is_free_instance_variable, 95, MX_APPLY_METHOD, IsFreeInstanceVariable, bool, NthStmt)
  MX_EXIT_VISIT_ObjCIvarRefExpr
MX_END_VISIT_STMT(ObjCIvarRefExpr)

#ifndef MX_ENTER_VISIT_ObjCIsaExpr
#  define MX_ENTER_VISIT_ObjCIsaExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCIsaExpr
#  define MX_EXIT_VISIT_ObjCIsaExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCIsaExpr)
  MX_ENTER_VISIT_ObjCIsaExpr
  MX_VISIT_BASE(ObjCIsaExpr, Expr)
  MX_VISIT_ENTITY(ObjCIsaExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ObjCIsaExpr, base_token_end, 38, MX_APPLY_METHOD, BaseTokenEnd, Token, NthStmt, TokenUseSelector::BASE_TOKEN_END)
  MX_VISIT_ENTITY(ObjCIsaExpr, isa_member_token, 39, MX_APPLY_METHOD, IsaMemberToken, Token, NthStmt, TokenUseSelector::ISA_MEMBER_TOKEN)
  MX_VISIT_ENTITY(ObjCIsaExpr, operation_token, 40, MX_APPLY_METHOD, OperationToken, Token, NthStmt, TokenUseSelector::OPERATION_TOKEN)
  MX_VISIT_BOOL(ObjCIsaExpr, is_arrow, 94, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_EXIT_VISIT_ObjCIsaExpr
MX_END_VISIT_STMT(ObjCIsaExpr)

#ifndef MX_ENTER_VISIT_ObjCIndirectCopyRestoreExpr
#  define MX_ENTER_VISIT_ObjCIndirectCopyRestoreExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCIndirectCopyRestoreExpr
#  define MX_EXIT_VISIT_ObjCIndirectCopyRestoreExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCIndirectCopyRestoreExpr)
  MX_ENTER_VISIT_ObjCIndirectCopyRestoreExpr
  MX_VISIT_BASE(ObjCIndirectCopyRestoreExpr, Expr)
  MX_VISIT_ENTITY(ObjCIndirectCopyRestoreExpr, sub_expression, 37, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(ObjCIndirectCopyRestoreExpr, should_copy, 94, MX_APPLY_METHOD, ShouldCopy, bool, NthStmt)
  MX_EXIT_VISIT_ObjCIndirectCopyRestoreExpr
MX_END_VISIT_STMT(ObjCIndirectCopyRestoreExpr)

#ifndef MX_ENTER_VISIT_ObjCEncodeExpr
#  define MX_ENTER_VISIT_ObjCEncodeExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCEncodeExpr
#  define MX_EXIT_VISIT_ObjCEncodeExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCEncodeExpr)
  MX_ENTER_VISIT_ObjCEncodeExpr
  MX_VISIT_BASE(ObjCEncodeExpr, Expr)
  MX_VISIT_ENTITY(ObjCEncodeExpr, at_token, 37, MX_APPLY_METHOD, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCEncodeExpr, encoded_type, 38, MX_APPLY_METHOD, EncodedType, Type, NthStmt, TypeUseSelector::ENCODED_TYPE)
  MX_VISIT_ENTITY(ObjCEncodeExpr, r_paren_token, 39, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_ObjCEncodeExpr
MX_END_VISIT_STMT(ObjCEncodeExpr)

#ifndef MX_ENTER_VISIT_ObjCDictionaryLiteral
#  define MX_ENTER_VISIT_ObjCDictionaryLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCDictionaryLiteral
#  define MX_EXIT_VISIT_ObjCDictionaryLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCDictionaryLiteral)
  MX_ENTER_VISIT_ObjCDictionaryLiteral
  MX_VISIT_BASE(ObjCDictionaryLiteral, Expr)
  MX_VISIT_ENTITY(ObjCDictionaryLiteral, dictionary_with_objects_method, 37, MX_APPLY_METHOD, DictionaryWithObjectsMethod, ObjCMethodDecl, NthStmt, DeclUseSelector::DICTIONARY_WITH_OBJECTS_METHOD)
  MX_EXIT_VISIT_ObjCDictionaryLiteral
MX_END_VISIT_STMT(ObjCDictionaryLiteral)

#ifndef MX_ENTER_VISIT_ObjCBoxedExpr
#  define MX_ENTER_VISIT_ObjCBoxedExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCBoxedExpr
#  define MX_EXIT_VISIT_ObjCBoxedExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCBoxedExpr)
  MX_ENTER_VISIT_ObjCBoxedExpr
  MX_VISIT_BASE(ObjCBoxedExpr, Expr)
  MX_VISIT_ENTITY(ObjCBoxedExpr, at_token, 37, MX_APPLY_METHOD, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCBoxedExpr, boxing_method, 38, MX_APPLY_METHOD, BoxingMethod, ObjCMethodDecl, NthStmt, DeclUseSelector::BOXING_METHOD)
  MX_VISIT_ENTITY(ObjCBoxedExpr, sub_expression, 39, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(ObjCBoxedExpr, is_expressible_as_constant_initializer, 94, MX_APPLY_METHOD, IsExpressibleAsConstantInitializer, bool, NthStmt)
  MX_EXIT_VISIT_ObjCBoxedExpr
MX_END_VISIT_STMT(ObjCBoxedExpr)

#ifndef MX_ENTER_VISIT_ObjCBoolLiteralExpr
#  define MX_ENTER_VISIT_ObjCBoolLiteralExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCBoolLiteralExpr
#  define MX_EXIT_VISIT_ObjCBoolLiteralExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCBoolLiteralExpr)
  MX_ENTER_VISIT_ObjCBoolLiteralExpr
  MX_VISIT_BASE(ObjCBoolLiteralExpr, Expr)
  MX_VISIT_ENTITY(ObjCBoolLiteralExpr, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(ObjCBoolLiteralExpr, value, 94, MX_APPLY_METHOD, Value, bool, NthStmt)
  MX_EXIT_VISIT_ObjCBoolLiteralExpr
MX_END_VISIT_STMT(ObjCBoolLiteralExpr)

#ifndef MX_ENTER_VISIT_ObjCAvailabilityCheckExpr
#  define MX_ENTER_VISIT_ObjCAvailabilityCheckExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCAvailabilityCheckExpr
#  define MX_EXIT_VISIT_ObjCAvailabilityCheckExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCAvailabilityCheckExpr)
  MX_ENTER_VISIT_ObjCAvailabilityCheckExpr
  MX_VISIT_BASE(ObjCAvailabilityCheckExpr, Expr)
  MX_VISIT_BOOL(ObjCAvailabilityCheckExpr, has_version, 94, MX_APPLY_METHOD, HasVersion, bool, NthStmt)
  MX_EXIT_VISIT_ObjCAvailabilityCheckExpr
MX_END_VISIT_STMT(ObjCAvailabilityCheckExpr)

#ifndef MX_ENTER_VISIT_ObjCArrayLiteral
#  define MX_ENTER_VISIT_ObjCArrayLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ObjCArrayLiteral
#  define MX_EXIT_VISIT_ObjCArrayLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ObjCArrayLiteral)
  MX_ENTER_VISIT_ObjCArrayLiteral
  MX_VISIT_BASE(ObjCArrayLiteral, Expr)
  MX_VISIT_ENTITY(ObjCArrayLiteral, array_with_objects_method, 37, MX_APPLY_METHOD, ArrayWithObjectsMethod, ObjCMethodDecl, NthStmt, DeclUseSelector::ARRAY_WITH_OBJECTS_METHOD)
  MX_VISIT_ENTITY_LIST(ObjCArrayLiteral, elements, 16, MX_APPLY_METHOD, Elements, Expr, NthStmt)
  MX_EXIT_VISIT_ObjCArrayLiteral
MX_END_VISIT_STMT(ObjCArrayLiteral)

#ifndef MX_ENTER_VISIT_OMPIteratorExpr
#  define MX_ENTER_VISIT_OMPIteratorExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_OMPIteratorExpr
#  define MX_EXIT_VISIT_OMPIteratorExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(OMPIteratorExpr)
  MX_ENTER_VISIT_OMPIteratorExpr
  MX_VISIT_BASE(OMPIteratorExpr, Expr)
  MX_VISIT_ENTITY(OMPIteratorExpr, iterator_kw_token, 37, MX_APPLY_METHOD, IteratorKwToken, Token, NthStmt, TokenUseSelector::ITERATOR_KW_TOKEN)
  MX_VISIT_ENTITY(OMPIteratorExpr, l_paren_token, 38, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(OMPIteratorExpr, r_paren_token, 39, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_OMPIteratorExpr
MX_END_VISIT_STMT(OMPIteratorExpr)

#ifndef MX_ENTER_VISIT_OMPArrayShapingExpr
#  define MX_ENTER_VISIT_OMPArrayShapingExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_OMPArrayShapingExpr
#  define MX_EXIT_VISIT_OMPArrayShapingExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(OMPArrayShapingExpr)
  MX_ENTER_VISIT_OMPArrayShapingExpr
  MX_VISIT_BASE(OMPArrayShapingExpr, Expr)
  MX_VISIT_ENTITY(OMPArrayShapingExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY_LIST(OMPArrayShapingExpr, dimensions, 16, MX_APPLY_METHOD, Dimensions, Expr, NthStmt)
  MX_VISIT_ENTITY(OMPArrayShapingExpr, l_paren_token, 38, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(OMPArrayShapingExpr, r_paren_token, 39, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_OMPArrayShapingExpr
MX_END_VISIT_STMT(OMPArrayShapingExpr)

#ifndef MX_ENTER_VISIT_OMPArraySectionExpr
#  define MX_ENTER_VISIT_OMPArraySectionExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_OMPArraySectionExpr
#  define MX_EXIT_VISIT_OMPArraySectionExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(OMPArraySectionExpr)
  MX_ENTER_VISIT_OMPArraySectionExpr
  MX_VISIT_BASE(OMPArraySectionExpr, Expr)
  MX_VISIT_ENTITY(OMPArraySectionExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(OMPArraySectionExpr, first_colon_token, 38, MX_APPLY_METHOD, FirstColonToken, Token, NthStmt, TokenUseSelector::FIRST_COLON_TOKEN)
  MX_VISIT_ENTITY(OMPArraySectionExpr, second_colon_token, 39, MX_APPLY_METHOD, SecondColonToken, Token, NthStmt, TokenUseSelector::SECOND_COLON_TOKEN)
  MX_VISIT_ENTITY(OMPArraySectionExpr, length, 40, MX_APPLY_METHOD, Length, Expr, NthStmt, StmtUseSelector::LENGTH)
  MX_VISIT_ENTITY(OMPArraySectionExpr, lower_bound, 41, MX_APPLY_METHOD, LowerBound, Expr, NthStmt, StmtUseSelector::LOWER_BOUND)
  MX_VISIT_ENTITY(OMPArraySectionExpr, r_bracket_token, 42, MX_APPLY_METHOD, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(OMPArraySectionExpr, stride, 43, MX_APPLY_METHOD, Stride, Expr, NthStmt, StmtUseSelector::STRIDE)
  MX_EXIT_VISIT_OMPArraySectionExpr
MX_END_VISIT_STMT(OMPArraySectionExpr)

#ifndef MX_ENTER_VISIT_NoInitExpr
#  define MX_ENTER_VISIT_NoInitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_NoInitExpr
#  define MX_EXIT_VISIT_NoInitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(NoInitExpr)
  MX_ENTER_VISIT_NoInitExpr
  MX_VISIT_BASE(NoInitExpr, Expr)
  MX_EXIT_VISIT_NoInitExpr
MX_END_VISIT_STMT(NoInitExpr)

#ifndef MX_ENTER_VISIT_MemberExpr
#  define MX_ENTER_VISIT_MemberExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_MemberExpr
#  define MX_EXIT_VISIT_MemberExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(MemberExpr)
  MX_ENTER_VISIT_MemberExpr
  MX_VISIT_BASE(MemberExpr, Expr)
  MX_VISIT_ENTITY(MemberExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(MemberExpr, l_angle_token, 38, MX_APPLY_METHOD, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, member_declaration, 39, MX_APPLY_METHOD, MemberDeclaration, ValueDecl, NthStmt, DeclUseSelector::MEMBER_DECLARATION)
  MX_VISIT_ENTITY(MemberExpr, member_token, 40, MX_APPLY_METHOD, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, operator_token, 41, MX_APPLY_METHOD, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, r_angle_token, 42, MX_APPLY_METHOD, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, template_keyword_token, 43, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(MemberExpr, had_multiple_candidates, 94, MX_APPLY_METHOD, HadMultipleCandidates, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, has_explicit_template_arguments, 95, MX_APPLY_METHOD, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, has_qualifier, 96, MX_APPLY_METHOD, HasQualifier, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, has_template_keyword, 97, MX_APPLY_METHOD, HasTemplateKeyword, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, is_arrow, 98, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, is_implicit_access, 100, MX_APPLY_METHOD, IsImplicitAccess, bool, NthStmt)
  MX_VISIT_ENUM(MemberExpr, is_non_odr_use, 99, MX_APPLY_METHOD, IsNonOdrUse, NonOdrUseReason, NthStmt)
  MX_EXIT_VISIT_MemberExpr
MX_END_VISIT_STMT(MemberExpr)

#ifndef MX_ENTER_VISIT_MatrixSubscriptExpr
#  define MX_ENTER_VISIT_MatrixSubscriptExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_MatrixSubscriptExpr
#  define MX_EXIT_VISIT_MatrixSubscriptExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(MatrixSubscriptExpr)
  MX_ENTER_VISIT_MatrixSubscriptExpr
  MX_VISIT_BASE(MatrixSubscriptExpr, Expr)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, column_index, 38, MX_APPLY_METHOD, ColumnIndex, Expr, NthStmt, StmtUseSelector::COLUMN_INDEX)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, r_bracket_token, 39, MX_APPLY_METHOD, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, row_index, 40, MX_APPLY_METHOD, RowIndex, Expr, NthStmt, StmtUseSelector::ROW_INDEX)
  MX_VISIT_BOOL(MatrixSubscriptExpr, is_incomplete, 94, MX_APPLY_METHOD, IsIncomplete, bool, NthStmt)
  MX_EXIT_VISIT_MatrixSubscriptExpr
MX_END_VISIT_STMT(MatrixSubscriptExpr)

#ifndef MX_ENTER_VISIT_MaterializeTemporaryExpr
#  define MX_ENTER_VISIT_MaterializeTemporaryExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_MaterializeTemporaryExpr
#  define MX_EXIT_VISIT_MaterializeTemporaryExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(MaterializeTemporaryExpr)
  MX_ENTER_VISIT_MaterializeTemporaryExpr
  MX_VISIT_BASE(MaterializeTemporaryExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(MaterializeTemporaryExpr, extending_declaration, 37, MX_APPLY_METHOD, ExtendingDeclaration, ValueDecl, NthStmt, DeclUseSelector::EXTENDING_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(MaterializeTemporaryExpr, lifetime_extended_temporary_declaration, 38, MX_APPLY_METHOD, LifetimeExtendedTemporaryDeclaration, LifetimeExtendedTemporaryDecl, NthStmt, DeclUseSelector::LIFETIME_EXTENDED_TEMPORARY_DECLARATION)
  MX_VISIT_ENUM(MaterializeTemporaryExpr, storage_duration, 99, MX_APPLY_METHOD, StorageDuration, StorageDuration, NthStmt)
  MX_VISIT_ENTITY(MaterializeTemporaryExpr, sub_expression, 39, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(MaterializeTemporaryExpr, is_bound_to_lvalue_reference, 96, MX_APPLY_METHOD, IsBoundToLvalueReference, bool, NthStmt)
  MX_VISIT_BOOL(MaterializeTemporaryExpr, is_usable_in_constant_expressions, 97, MX_APPLY_METHOD, IsUsableInConstantExpressions, bool, NthStmt)
  MX_EXIT_VISIT_MaterializeTemporaryExpr
MX_END_VISIT_STMT(MaterializeTemporaryExpr)

#ifndef MX_ENTER_VISIT_MSPropertySubscriptExpr
#  define MX_ENTER_VISIT_MSPropertySubscriptExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_MSPropertySubscriptExpr
#  define MX_EXIT_VISIT_MSPropertySubscriptExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(MSPropertySubscriptExpr)
  MX_ENTER_VISIT_MSPropertySubscriptExpr
  MX_VISIT_BASE(MSPropertySubscriptExpr, Expr)
  MX_VISIT_ENTITY(MSPropertySubscriptExpr, base, 37, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(MSPropertySubscriptExpr, index, 38, MX_APPLY_METHOD, Index, Expr, NthStmt, StmtUseSelector::INDEX)
  MX_VISIT_ENTITY(MSPropertySubscriptExpr, r_bracket_token, 39, MX_APPLY_METHOD, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_EXIT_VISIT_MSPropertySubscriptExpr
MX_END_VISIT_STMT(MSPropertySubscriptExpr)

#ifndef MX_ENTER_VISIT_MSPropertyRefExpr
#  define MX_ENTER_VISIT_MSPropertyRefExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_MSPropertyRefExpr
#  define MX_EXIT_VISIT_MSPropertyRefExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(MSPropertyRefExpr)
  MX_ENTER_VISIT_MSPropertyRefExpr
  MX_VISIT_BASE(MSPropertyRefExpr, Expr)
  MX_VISIT_ENTITY(MSPropertyRefExpr, base_expression, 37, MX_APPLY_METHOD, BaseExpression, Expr, NthStmt, StmtUseSelector::BASE_EXPRESSION)
  MX_VISIT_ENTITY(MSPropertyRefExpr, member_token, 38, MX_APPLY_METHOD, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(MSPropertyRefExpr, property_declaration, 39, MX_APPLY_METHOD, PropertyDeclaration, MSPropertyDecl, NthStmt, DeclUseSelector::PROPERTY_DECLARATION)
  MX_VISIT_BOOL(MSPropertyRefExpr, is_arrow, 94, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(MSPropertyRefExpr, is_implicit_access, 95, MX_APPLY_METHOD, IsImplicitAccess, bool, NthStmt)
  MX_EXIT_VISIT_MSPropertyRefExpr
MX_END_VISIT_STMT(MSPropertyRefExpr)

#ifndef MX_ENTER_VISIT_LambdaExpr
#  define MX_ENTER_VISIT_LambdaExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_LambdaExpr
#  define MX_EXIT_VISIT_LambdaExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(LambdaExpr)
  MX_ENTER_VISIT_LambdaExpr
  MX_VISIT_BASE(LambdaExpr, Expr)
  MX_VISIT_ENTITY(LambdaExpr, body, 37, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(LambdaExpr, call_operator, 38, MX_APPLY_METHOD, CallOperator, CXXMethodDecl, NthStmt, DeclUseSelector::CALL_OPERATOR)
  MX_VISIT_ENUM(LambdaExpr, capture_default, 99, MX_APPLY_METHOD, CaptureDefault, LambdaCaptureDefault, NthStmt)
  MX_VISIT_ENTITY(LambdaExpr, capture_default_token, 39, MX_APPLY_METHOD, CaptureDefaultToken, Token, NthStmt, TokenUseSelector::CAPTURE_DEFAULT_TOKEN)
  MX_VISIT_ENTITY(LambdaExpr, compound_statement_body, 40, MX_APPLY_METHOD, CompoundStatementBody, CompoundStmt, NthStmt, StmtUseSelector::COMPOUND_STATEMENT_BODY)
  MX_VISIT_ENTITY_LIST(LambdaExpr, explicit_template_parameters, 16, MX_APPLY_METHOD, ExplicitTemplateParameters, NamedDecl, NthStmt)
  MX_VISIT_ENTITY(LambdaExpr, lambda_class, 43, MX_APPLY_METHOD, LambdaClass, CXXRecordDecl, NthStmt, DeclUseSelector::LAMBDA_CLASS)
  MX_VISIT_OPTIONAL_PSEUDO(LambdaExpr, template_parameter_list, 108, MX_APPLY_METHOD, TemplateParameterList, TemplateParameterList, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(LambdaExpr, trailing_requires_clause, 44, MX_APPLY_METHOD, TrailingRequiresClause, Expr, NthStmt, StmtUseSelector::TRAILING_REQUIRES_CLAUSE)
  MX_VISIT_BOOL(LambdaExpr, has_explicit_parameters, 96, MX_APPLY_METHOD, HasExplicitParameters, bool, NthStmt)
  MX_VISIT_BOOL(LambdaExpr, has_explicit_result_type, 97, MX_APPLY_METHOD, HasExplicitResultType, bool, NthStmt)
  MX_VISIT_BOOL(LambdaExpr, is_generic_lambda, 98, MX_APPLY_METHOD, IsGenericLambda, bool, NthStmt)
  MX_VISIT_BOOL(LambdaExpr, is_mutable, 100, MX_APPLY_METHOD, IsMutable, bool, NthStmt)
  MX_EXIT_VISIT_LambdaExpr
MX_END_VISIT_STMT(LambdaExpr)

#ifndef MX_ENTER_VISIT_IntegerLiteral
#  define MX_ENTER_VISIT_IntegerLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_IntegerLiteral
#  define MX_EXIT_VISIT_IntegerLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(IntegerLiteral)
  MX_ENTER_VISIT_IntegerLiteral
  MX_VISIT_BASE(IntegerLiteral, Expr)
  MX_VISIT_ENTITY(IntegerLiteral, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_EXIT_VISIT_IntegerLiteral
MX_END_VISIT_STMT(IntegerLiteral)

#ifndef MX_ENTER_VISIT_InitListExpr
#  define MX_ENTER_VISIT_InitListExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_InitListExpr
#  define MX_EXIT_VISIT_InitListExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(InitListExpr)
  MX_ENTER_VISIT_InitListExpr
  MX_VISIT_BASE(InitListExpr, Expr)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, array_filler, 37, MX_APPLY_METHOD, ArrayFiller, Expr, NthStmt, StmtUseSelector::ARRAY_FILLER)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, initialized_field_in_union, 38, MX_APPLY_METHOD, InitializedFieldInUnion, FieldDecl, NthStmt, DeclUseSelector::INITIALIZED_FIELD_IN_UNION)
  MX_VISIT_ENTITY(InitListExpr, l_brace_token, 39, MX_APPLY_METHOD, LBraceToken, Token, NthStmt, TokenUseSelector::L_BRACE_TOKEN)
  MX_VISIT_ENTITY(InitListExpr, r_brace_token, 40, MX_APPLY_METHOD, RBraceToken, Token, NthStmt, TokenUseSelector::R_BRACE_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, semantic_form, 41, MX_APPLY_METHOD, SemanticForm, InitListExpr, NthStmt, StmtUseSelector::SEMANTIC_FORM)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, syntactic_form, 42, MX_APPLY_METHOD, SyntacticForm, InitListExpr, NthStmt, StmtUseSelector::SYNTACTIC_FORM)
  MX_VISIT_BOOL(InitListExpr, had_array_range_designator, 98, MX_APPLY_METHOD, HadArrayRangeDesignator, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, has_array_filler, 100, MX_APPLY_METHOD, HasArrayFiller, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(InitListExpr, initializers, 16, MX_APPLY_METHOD, Initializers, Expr, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_explicit, 103, MX_APPLY_METHOD, IsExplicit, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_semantic_form, 104, MX_APPLY_METHOD, IsSemanticForm, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_string_literal_initializer, 105, MX_APPLY_METHOD, IsStringLiteralInitializer, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_syntactic_form, 106, MX_APPLY_METHOD, IsSyntacticForm, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(InitListExpr, is_transparent, 107, MX_APPLY_METHOD, IsTransparent, bool, NthStmt)
  MX_EXIT_VISIT_InitListExpr
MX_END_VISIT_STMT(InitListExpr)

#ifndef MX_ENTER_VISIT_ImplicitValueInitExpr
#  define MX_ENTER_VISIT_ImplicitValueInitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ImplicitValueInitExpr
#  define MX_EXIT_VISIT_ImplicitValueInitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ImplicitValueInitExpr)
  MX_ENTER_VISIT_ImplicitValueInitExpr
  MX_VISIT_BASE(ImplicitValueInitExpr, Expr)
  MX_EXIT_VISIT_ImplicitValueInitExpr
MX_END_VISIT_STMT(ImplicitValueInitExpr)

#ifndef MX_ENTER_VISIT_ImaginaryLiteral
#  define MX_ENTER_VISIT_ImaginaryLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ImaginaryLiteral
#  define MX_EXIT_VISIT_ImaginaryLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ImaginaryLiteral)
  MX_ENTER_VISIT_ImaginaryLiteral
  MX_VISIT_BASE(ImaginaryLiteral, Expr)
  MX_VISIT_ENTITY(ImaginaryLiteral, sub_expression, 37, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_EXIT_VISIT_ImaginaryLiteral
MX_END_VISIT_STMT(ImaginaryLiteral)

#ifndef MX_ENTER_VISIT_GenericSelectionExpr
#  define MX_ENTER_VISIT_GenericSelectionExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_GenericSelectionExpr
#  define MX_EXIT_VISIT_GenericSelectionExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(GenericSelectionExpr)
  MX_ENTER_VISIT_GenericSelectionExpr
  MX_VISIT_BASE(GenericSelectionExpr, Expr)
  MX_VISIT_ENTITY_LIST(GenericSelectionExpr, association_expressions, 16, MX_APPLY_METHOD, AssociationExpressions, Expr, NthStmt)
  MX_VISIT_ENTITY(GenericSelectionExpr, controlling_expression, 37, MX_APPLY_METHOD, ControllingExpression, Expr, NthStmt, StmtUseSelector::CONTROLLING_EXPRESSION)
  MX_VISIT_ENTITY(GenericSelectionExpr, default_token, 38, MX_APPLY_METHOD, DefaultToken, Token, NthStmt, TokenUseSelector::DEFAULT_TOKEN)
  MX_VISIT_ENTITY(GenericSelectionExpr, generic_token, 39, MX_APPLY_METHOD, GenericToken, Token, NthStmt, TokenUseSelector::GENERIC_TOKEN)
  MX_VISIT_ENTITY(GenericSelectionExpr, r_paren_token, 40, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(GenericSelectionExpr, result_expression, 41, MX_APPLY_METHOD, ResultExpression, Expr, NthStmt, StmtUseSelector::RESULT_EXPRESSION)
  MX_VISIT_BOOL(GenericSelectionExpr, is_result_dependent, 94, MX_APPLY_METHOD, IsResultDependent, bool, NthStmt)
  MX_EXIT_VISIT_GenericSelectionExpr
MX_END_VISIT_STMT(GenericSelectionExpr)

#ifndef MX_ENTER_VISIT_GNUNullExpr
#  define MX_ENTER_VISIT_GNUNullExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_GNUNullExpr
#  define MX_EXIT_VISIT_GNUNullExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(GNUNullExpr)
  MX_ENTER_VISIT_GNUNullExpr
  MX_VISIT_BASE(GNUNullExpr, Expr)
  MX_VISIT_ENTITY(GNUNullExpr, token_token, 37, MX_APPLY_METHOD, TokenToken, Token, NthStmt, TokenUseSelector::TOKEN_TOKEN)
  MX_EXIT_VISIT_GNUNullExpr
MX_END_VISIT_STMT(GNUNullExpr)

#ifndef MX_ENTER_VISIT_FunctionParmPackExpr
#  define MX_ENTER_VISIT_FunctionParmPackExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_FunctionParmPackExpr
#  define MX_EXIT_VISIT_FunctionParmPackExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(FunctionParmPackExpr)
  MX_ENTER_VISIT_FunctionParmPackExpr
  MX_VISIT_BASE(FunctionParmPackExpr, Expr)
  MX_VISIT_ENTITY(FunctionParmPackExpr, parameter_pack, 37, MX_APPLY_METHOD, ParameterPack, VarDecl, NthStmt, DeclUseSelector::PARAMETER_PACK)
  MX_VISIT_ENTITY(FunctionParmPackExpr, parameter_pack_token, 38, MX_APPLY_METHOD, ParameterPackToken, Token, NthStmt, TokenUseSelector::PARAMETER_PACK_TOKEN)
  MX_VISIT_ENTITY_LIST(FunctionParmPackExpr, expansions, 16, MX_APPLY_METHOD, Expansions, VarDecl, NthStmt)
  MX_EXIT_VISIT_FunctionParmPackExpr
MX_END_VISIT_STMT(FunctionParmPackExpr)

#ifndef MX_ENTER_VISIT_FullExpr
#  define MX_ENTER_VISIT_FullExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_FullExpr
#  define MX_EXIT_VISIT_FullExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(FullExpr)
  MX_ENTER_VISIT_FullExpr
  MX_VISIT_BASE(FullExpr, Expr)
  MX_VISIT_ENTITY(FullExpr, sub_expression, 37, MX_APPLY_METHOD, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_EXIT_VISIT_FullExpr
MX_END_VISIT_STMT(FullExpr)

#ifndef MX_ENTER_VISIT_ExprWithCleanups
#  define MX_ENTER_VISIT_ExprWithCleanups MX_ENTER_VISIT_FullExpr
#endif
#ifndef MX_EXIT_VISIT_ExprWithCleanups
#  define MX_EXIT_VISIT_ExprWithCleanups MX_EXIT_VISIT_FullExpr
#endif

MX_BEGIN_VISIT_STMT(ExprWithCleanups)
  MX_ENTER_VISIT_ExprWithCleanups
  MX_VISIT_BASE(ExprWithCleanups, FullExpr)
  MX_VISIT_BOOL(ExprWithCleanups, cleanups_have_side_effects, 94, MX_APPLY_METHOD, CleanupsHaveSideEffects, bool, NthStmt)
  MX_EXIT_VISIT_ExprWithCleanups
MX_END_VISIT_STMT(ExprWithCleanups)

#ifndef MX_ENTER_VISIT_ConstantExpr
#  define MX_ENTER_VISIT_ConstantExpr MX_ENTER_VISIT_FullExpr
#endif
#ifndef MX_EXIT_VISIT_ConstantExpr
#  define MX_EXIT_VISIT_ConstantExpr MX_EXIT_VISIT_FullExpr
#endif

MX_BEGIN_VISIT_STMT(ConstantExpr)
  MX_ENTER_VISIT_ConstantExpr
  MX_VISIT_BASE(ConstantExpr, FullExpr)
  MX_VISIT_ENUM(ConstantExpr, result_storage_kind, 99, MX_APPLY_METHOD, ResultStorageKind, ConstantExprResultStorageKind, NthStmt)
  MX_VISIT_BOOL(ConstantExpr, has_ap_value_result, 94, MX_APPLY_METHOD, HasAPValueResult, bool, NthStmt)
  MX_VISIT_BOOL(ConstantExpr, is_immediate_invocation, 95, MX_APPLY_METHOD, IsImmediateInvocation, bool, NthStmt)
  MX_EXIT_VISIT_ConstantExpr
MX_END_VISIT_STMT(ConstantExpr)

#ifndef MX_ENTER_VISIT_FloatingLiteral
#  define MX_ENTER_VISIT_FloatingLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_FloatingLiteral
#  define MX_EXIT_VISIT_FloatingLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(FloatingLiteral)
  MX_ENTER_VISIT_FloatingLiteral
  MX_VISIT_BASE(FloatingLiteral, Expr)
  MX_VISIT_ENTITY(FloatingLiteral, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(FloatingLiteral, is_exact, 94, MX_APPLY_METHOD, IsExact, bool, NthStmt)
  MX_EXIT_VISIT_FloatingLiteral
MX_END_VISIT_STMT(FloatingLiteral)

#ifndef MX_ENTER_VISIT_FixedPointLiteral
#  define MX_ENTER_VISIT_FixedPointLiteral MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_FixedPointLiteral
#  define MX_EXIT_VISIT_FixedPointLiteral MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(FixedPointLiteral)
  MX_ENTER_VISIT_FixedPointLiteral
  MX_VISIT_BASE(FixedPointLiteral, Expr)
  MX_VISIT_ENTITY(FixedPointLiteral, token, 37, MX_APPLY_METHOD, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_EXIT_VISIT_FixedPointLiteral
MX_END_VISIT_STMT(FixedPointLiteral)

#ifndef MX_ENTER_VISIT_ExtVectorElementExpr
#  define MX_ENTER_VISIT_ExtVectorElementExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ExtVectorElementExpr
#  define MX_EXIT_VISIT_ExtVectorElementExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ExtVectorElementExpr)
  MX_ENTER_VISIT_ExtVectorElementExpr
  MX_VISIT_BASE(ExtVectorElementExpr, Expr)
  MX_VISIT_BOOL(ExtVectorElementExpr, contains_duplicate_elements, 94, MX_APPLY_METHOD, ContainsDuplicateElements, bool, NthStmt)
  MX_VISIT_ENTITY(ExtVectorElementExpr, accessor_token, 37, MX_APPLY_METHOD, AccessorToken, Token, NthStmt, TokenUseSelector::ACCESSOR_TOKEN)
  MX_VISIT_ENTITY(ExtVectorElementExpr, base, 38, MX_APPLY_METHOD, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_BOOL(ExtVectorElementExpr, is_arrow, 95, MX_APPLY_METHOD, IsArrow, bool, NthStmt)
  MX_EXIT_VISIT_ExtVectorElementExpr
MX_END_VISIT_STMT(ExtVectorElementExpr)

#ifndef MX_ENTER_VISIT_ExpressionTraitExpr
#  define MX_ENTER_VISIT_ExpressionTraitExpr MX_ENTER_VISIT_Expr
#endif
#ifndef MX_EXIT_VISIT_ExpressionTraitExpr
#  define MX_EXIT_VISIT_ExpressionTraitExpr MX_EXIT_VISIT_Expr
#endif

MX_BEGIN_VISIT_STMT(ExpressionTraitExpr)
  MX_ENTER_VISIT_ExpressionTraitExpr
  MX_VISIT_BASE(ExpressionTraitExpr, Expr)
  MX_VISIT_ENTITY(ExpressionTraitExpr, queried_expression, 37, MX_APPLY_METHOD, QueriedExpression, Expr, NthStmt, StmtUseSelector::QUERIED_EXPRESSION)
  MX_VISIT_ENUM(ExpressionTraitExpr, trait, 99, MX_APPLY_METHOD, Trait, ExpressionTrait, NthStmt)
  MX_VISIT_BOOL(ExpressionTraitExpr, value, 94, MX_APPLY_METHOD, Value, bool, NthStmt)
  MX_EXIT_VISIT_ExpressionTraitExpr
MX_END_VISIT_STMT(ExpressionTraitExpr)

#ifndef MX_ENTER_VISIT_AttributedStmt
#  define MX_ENTER_VISIT_AttributedStmt MX_ENTER_VISIT_ValueStmt
#endif
#ifndef MX_EXIT_VISIT_AttributedStmt
#  define MX_EXIT_VISIT_AttributedStmt MX_EXIT_VISIT_ValueStmt
#endif

MX_BEGIN_VISIT_STMT(AttributedStmt)
  MX_ENTER_VISIT_AttributedStmt
  MX_VISIT_BASE(AttributedStmt, ValueStmt)
  MX_VISIT_ENTITY(AttributedStmt, attribute_token, 10, MX_APPLY_METHOD, AttributeToken, Token, NthStmt, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(AttributedStmt, sub_statement, 11, MX_APPLY_METHOD, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_EXIT_VISIT_AttributedStmt
MX_END_VISIT_STMT(AttributedStmt)

#ifndef MX_ENTER_VISIT_SwitchStmt
#  define MX_ENTER_VISIT_SwitchStmt MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_SwitchStmt
#  define MX_EXIT_VISIT_SwitchStmt MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_STMT(SwitchStmt)
  MX_ENTER_VISIT_SwitchStmt
  MX_VISIT_BASE(SwitchStmt, Stmt)
  MX_VISIT_ENTITY(SwitchStmt, body, 9, MX_APPLY_METHOD, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(SwitchStmt, condition, 10, MX_APPLY_METHOD, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, condition_variable, 11, MX_APPLY_METHOD, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, condition_variable_declaration_statement, 13, MX_APPLY_METHOD, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, initializer, 14, MX_APPLY_METHOD, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(SwitchStmt, l_paren_token, 17, MX_APPLY_METHOD, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(SwitchStmt, r_paren_token, 18, MX_APPLY_METHOD, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, first_switch_case, 19, MX_APPLY_METHOD, FirstSwitchCase, SwitchCase, NthStmt, StmtUseSelector::FIRST_SWITCH_CASE)
  MX_VISIT_ENTITY(SwitchStmt, switch_token, 26, MX_APPLY_METHOD, SwitchToken, Token, NthStmt, TokenUseSelector::SWITCH_TOKEN)
  MX_VISIT_BOOL(SwitchStmt, has_initializer_storage, 57, MX_APPLY_METHOD, HasInitializerStorage, bool, NthStmt)
  MX_VISIT_BOOL(SwitchStmt, has_variable_storage, 58, MX_APPLY_METHOD, HasVariableStorage, bool, NthStmt)
  MX_VISIT_BOOL(SwitchStmt, is_all_enum_cases_covered, 59, MX_APPLY_METHOD, IsAllEnumCasesCovered, bool, NthStmt)
  MX_EXIT_VISIT_SwitchStmt
MX_END_VISIT_STMT(SwitchStmt)

#ifndef MX_ENTER_VISIT_SwitchCase
#  define MX_ENTER_VISIT_SwitchCase MX_ENTER_VISIT_Stmt
#endif
#ifndef MX_EXIT_VISIT_SwitchCase
#  define MX_EXIT_VISIT_SwitchCase MX_EXIT_VISIT_Stmt
#endif

MX_BEGIN_VISIT_ABSTRACT_STMT(SwitchCase)
  MX_ENTER_VISIT_SwitchCase
  MX_VISIT_BASE(SwitchCase, Stmt)
  MX_VISIT_ENTITY(SwitchCase, colon_token, 9, MX_APPLY_METHOD, ColonToken, Token, NthStmt, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENTITY(SwitchCase, keyword_token, 10, MX_APPLY_METHOD, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(SwitchCase, next_switch_case, 11, MX_APPLY_METHOD, NextSwitchCase, SwitchCase, NthStmt, StmtUseSelector::NEXT_SWITCH_CASE)
  MX_VISIT_ENTITY(SwitchCase, sub_statement, 13, MX_APPLY_METHOD, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_EXIT_VISIT_SwitchCase
MX_END_VISIT_STMT(SwitchCase)

#ifndef MX_ENTER_VISIT_DefaultStmt
#  define MX_ENTER_VISIT_DefaultStmt MX_ENTER_VISIT_SwitchCase
#endif
#ifndef MX_EXIT_VISIT_DefaultStmt
#  define MX_EXIT_VISIT_DefaultStmt MX_EXIT_VISIT_SwitchCase
#endif

MX_BEGIN_VISIT_STMT(DefaultStmt)
  MX_ENTER_VISIT_DefaultStmt
  MX_VISIT_BASE(DefaultStmt, SwitchCase)
  MX_VISIT_ENTITY(DefaultStmt, default_token, 14, MX_APPLY_METHOD, DefaultToken, Token, NthStmt, TokenUseSelector::DEFAULT_TOKEN)
  MX_EXIT_VISIT_DefaultStmt
MX_END_VISIT_STMT(DefaultStmt)

#ifndef MX_ENTER_VISIT_CaseStmt
#  define MX_ENTER_VISIT_CaseStmt MX_ENTER_VISIT_SwitchCase
#endif
#ifndef MX_EXIT_VISIT_CaseStmt
#  define MX_EXIT_VISIT_CaseStmt MX_EXIT_VISIT_SwitchCase
#endif

MX_BEGIN_VISIT_STMT(CaseStmt)
  MX_ENTER_VISIT_CaseStmt
  MX_VISIT_BASE(CaseStmt, SwitchCase)
  MX_VISIT_BOOL(CaseStmt, case_statement_is_gnu_range, 15, MX_APPLY_METHOD, CaseStatementIsGNURange, bool, NthStmt)
  MX_VISIT_ENTITY(CaseStmt, case_token, 14, MX_APPLY_METHOD, CaseToken, Token, NthStmt, TokenUseSelector::CASE_TOKEN)
  MX_VISIT_ENTITY(CaseStmt, ellipsis_token, 17, MX_APPLY_METHOD, EllipsisToken, Token, NthStmt, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(CaseStmt, lhs, 18, MX_APPLY_METHOD, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_OPTIONAL_ENTITY(CaseStmt, rhs, 19, MX_APPLY_METHOD, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_EXIT_VISIT_CaseStmt
MX_END_VISIT_STMT(CaseStmt)

#ifndef MX_ENTER_VISIT_Decl
#  define MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_Decl
#  define MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_ABSTRACT_DECL(Decl)
  MX_ENTER_VISIT_Decl
  MX_VISIT_DECL_LINK(Decl, parent_declaration, 0)
  MX_VISIT_STMT_LINK(Decl, parent_statement, 1)
  MX_VISIT_BOOL(Decl, is_definition, 2, MX_APPLY_FUNC, IsDefinition, bool, NthDecl)
  MX_VISIT_ENUM(Decl, access, 3, MX_APPLY_METHOD, Access, AccessSpecifier, NthDecl)
  MX_VISIT_ENUM(Decl, availability, 4, MX_APPLY_METHOD, Availability, AvailabilityResult, NthDecl)
  MX_VISIT_OPTIONAL_PSEUDO(Decl, described_template_parameters, 5, MX_APPLY_METHOD, DescribedTemplateParameters, TemplateParameterList, NthDecl)
  MX_VISIT_ENUM(Decl, friend_object_kind, 7, MX_APPLY_METHOD, FriendObjectKind, DeclFriendObjectKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(Decl, function_type, 8, MX_APPLY_METHOD, FunctionType, FunctionType, NthDecl, TypeUseSelector::FUNCTION_TYPE)
  MX_VISIT_ENUM(Decl, module_ownership_kind, 10, MX_APPLY_METHOD, ModuleOwnershipKind, DeclModuleOwnershipKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(Decl, non_closure_context, 11, MX_APPLY_METHOD, NonClosureContext, Decl, NthDecl, DeclUseSelector::NON_CLOSURE_CONTEXT)
  MX_VISIT_BOOL(Decl, has_attributes, 13, MX_APPLY_METHOD, HasAttributes, bool, NthDecl)
  MX_VISIT_BOOL(Decl, has_defining_attribute, 14, MX_APPLY_METHOD, HasDefiningAttribute, bool, NthDecl)
  MX_VISIT_BOOL(Decl, has_owning_module, 15, MX_APPLY_METHOD, HasOwningModule, bool, NthDecl)
  MX_VISIT_BOOL(Decl, has_tag_identifier_namespace, 16, MX_APPLY_METHOD, HasTagIdentifierNamespace, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_defined_outside_function_or_method, 17, MX_APPLY_METHOD, IsDefinedOutsideFunctionOrMethod, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_deprecated, 18, MX_APPLY_METHOD, IsDeprecated, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_function_or_function_template, 19, MX_APPLY_METHOD, IsFunctionOrFunctionTemplate, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_implicit, 20, MX_APPLY_METHOD, IsImplicit, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_anonymous_namespace, 21, MX_APPLY_METHOD, IsInAnonymousNamespace, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_export_declaration_context, 22, MX_APPLY_METHOD, IsInExportDeclarationContext, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_local_scope_for_instantiation, 23, MX_APPLY_METHOD, IsInLocalScopeForInstantiation, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_std_namespace, 24, MX_APPLY_METHOD, IsInStdNamespace, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_invalid_declaration, 25, MX_APPLY_METHOD, IsInvalidDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_module_private, 26, MX_APPLY_METHOD, IsModulePrivate, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_out_of_line, 27, MX_APPLY_METHOD, IsOutOfLine, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_parameter_pack, 28, MX_APPLY_METHOD, IsParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_template_declaration, 29, MX_APPLY_METHOD, IsTemplateDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_template_parameter, 30, MX_APPLY_METHOD, IsTemplateParameter, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_template_parameter_pack, 31, MX_APPLY_METHOD, IsTemplateParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_templated, 32, MX_APPLY_METHOD, IsTemplated, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_top_level_declaration_in_obj_c_container, 33, MX_APPLY_METHOD, IsTopLevelDeclarationInObjCContainer, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_unavailable, 34, MX_APPLY_METHOD, IsUnavailable, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_unconditionally_visible, 35, MX_APPLY_METHOD, IsUnconditionallyVisible, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_weak_imported, 36, MX_APPLY_METHOD, IsWeakImported, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(Decl, redeclarations_visible_in_translation_unit, 37, MX_APPLY_METHOD, Redeclarations, Decl, NthDecl)
  MX_VISIT_ENUM(Decl, kind, 38, MX_APPLY_METHOD, Kind, DeclKind, NthDecl)
  MX_VISIT_ENUM(Decl, category, 39, MX_APPLY_METHOD, Category, DeclCategory, NthDecl)
  MX_VISIT_ENTITY(Decl, token, 40, MX_APPLY_METHOD, Token, Token, NthDecl, TokenUseSelector::TOKEN)
  MX_EXIT_VISIT_Decl
MX_END_VISIT_DECL(Decl)

#ifndef MX_ENTER_VISIT_ClassScopeFunctionSpecializationDecl
#  define MX_ENTER_VISIT_ClassScopeFunctionSpecializationDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_ClassScopeFunctionSpecializationDecl
#  define MX_EXIT_VISIT_ClassScopeFunctionSpecializationDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(ClassScopeFunctionSpecializationDecl)
  MX_ENTER_VISIT_ClassScopeFunctionSpecializationDecl
  MX_VISIT_BASE(ClassScopeFunctionSpecializationDecl, Decl)
  MX_VISIT_ENTITY(ClassScopeFunctionSpecializationDecl, specialization, 43, MX_APPLY_METHOD, Specialization, CXXMethodDecl, NthDecl, DeclUseSelector::SPECIALIZATION)
  MX_VISIT_BOOL(ClassScopeFunctionSpecializationDecl, has_explicit_template_arguments, 44, MX_APPLY_METHOD, HasExplicitTemplateArguments, bool, NthDecl)
  MX_EXIT_VISIT_ClassScopeFunctionSpecializationDecl
MX_END_VISIT_DECL(ClassScopeFunctionSpecializationDecl)

#ifndef MX_ENTER_VISIT_CapturedDecl
#  define MX_ENTER_VISIT_CapturedDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_CapturedDecl
#  define MX_EXIT_VISIT_CapturedDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(CapturedDecl)
  MX_ENTER_VISIT_CapturedDecl
  MX_VISIT_BASE(CapturedDecl, Decl)
  MX_VISIT_ENTITY(CapturedDecl, context_parameter, 43, MX_APPLY_METHOD, ContextParameter, ImplicitParamDecl, NthDecl, DeclUseSelector::CONTEXT_PARAMETER)
  MX_VISIT_BOOL(CapturedDecl, is_nothrow, 44, MX_APPLY_METHOD, IsNothrow, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(CapturedDecl, parameters, 45, MX_APPLY_METHOD, Parameters, ImplicitParamDecl, NthDecl)
  MX_VISIT_DECL_CONTEXT(CapturedDecl, declarations_in_context, 46, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_CapturedDecl
MX_END_VISIT_DECL(CapturedDecl)

#ifndef MX_ENTER_VISIT_BlockDecl
#  define MX_ENTER_VISIT_BlockDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_BlockDecl
#  define MX_EXIT_VISIT_BlockDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(BlockDecl)
  MX_ENTER_VISIT_BlockDecl
  MX_VISIT_BASE(BlockDecl, Decl)
  MX_VISIT_BOOL(BlockDecl, block_missing_return_type, 44, MX_APPLY_METHOD, BlockMissingReturnType, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, can_avoid_copy_to_heap, 47, MX_APPLY_METHOD, CanAvoidCopyToHeap, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, captures_cxx_this, 48, MX_APPLY_METHOD, CapturesCXXThis, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, does_not_escape, 49, MX_APPLY_METHOD, DoesNotEscape, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(BlockDecl, block_mangling_context_declaration, 43, MX_APPLY_METHOD, BlockManglingContextDeclaration, Decl, NthDecl, DeclUseSelector::BLOCK_MANGLING_CONTEXT_DECLARATION)
  MX_VISIT_ENTITY(BlockDecl, caret_token, 51, MX_APPLY_METHOD, CaretToken, Token, NthDecl, TokenUseSelector::CARET_TOKEN)
  MX_VISIT_ENTITY(BlockDecl, compound_body, 52, MX_APPLY_METHOD, CompoundBody, CompoundStmt, NthDecl, StmtUseSelector::COMPOUND_BODY)
  MX_VISIT_ENTITY(BlockDecl, signature_as_written, 53, MX_APPLY_METHOD, SignatureAsWritten, Type, NthDecl, TypeUseSelector::SIGNATURE_AS_WRITTEN)
  MX_VISIT_BOOL(BlockDecl, has_captures, 54, MX_APPLY_METHOD, HasCaptures, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, is_conversion_from_lambda, 55, MX_APPLY_METHOD, IsConversionFromLambda, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, is_variadic, 56, MX_APPLY_METHOD, IsVariadic, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(BlockDecl, parameters, 45, MX_APPLY_METHOD, Parameters, ParmVarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(BlockDecl, parameter_declarations, 46, MX_APPLY_METHOD, ParameterDeclarations, ParmVarDecl, NthDecl)
  MX_VISIT_DECL_CONTEXT(BlockDecl, declarations_in_context, 57, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_BlockDecl
MX_END_VISIT_DECL(BlockDecl)

#ifndef MX_ENTER_VISIT_AccessSpecDecl
#  define MX_ENTER_VISIT_AccessSpecDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_AccessSpecDecl
#  define MX_EXIT_VISIT_AccessSpecDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(AccessSpecDecl)
  MX_ENTER_VISIT_AccessSpecDecl
  MX_VISIT_BASE(AccessSpecDecl, Decl)
  MX_VISIT_ENTITY(AccessSpecDecl, access_specifier_token, 43, MX_APPLY_METHOD, AccessSpecifierToken, Token, NthDecl, TokenUseSelector::ACCESS_SPECIFIER_TOKEN)
  MX_VISIT_ENTITY(AccessSpecDecl, colon_token, 51, MX_APPLY_METHOD, ColonToken, Token, NthDecl, TokenUseSelector::COLON_TOKEN)
  MX_EXIT_VISIT_AccessSpecDecl
MX_END_VISIT_DECL(AccessSpecDecl)

#ifndef MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl
#  define MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl
#  define MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_ABSTRACT_DECL(OMPDeclarativeDirectiveDecl)
  MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl
  MX_VISIT_BASE(OMPDeclarativeDirectiveDecl, Decl)
  MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl
MX_END_VISIT_DECL(OMPDeclarativeDirectiveDecl)

#ifndef MX_ENTER_VISIT_OMPThreadPrivateDecl
#  define MX_ENTER_VISIT_OMPThreadPrivateDecl MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl
#endif
#ifndef MX_EXIT_VISIT_OMPThreadPrivateDecl
#  define MX_EXIT_VISIT_OMPThreadPrivateDecl MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl
#endif

MX_BEGIN_VISIT_DECL(OMPThreadPrivateDecl)
  MX_ENTER_VISIT_OMPThreadPrivateDecl
  MX_VISIT_BASE(OMPThreadPrivateDecl, OMPDeclarativeDirectiveDecl)
  MX_VISIT_ENTITY_LIST(OMPThreadPrivateDecl, varlists, 45, MX_APPLY_METHOD, Varlists, Expr, NthDecl)
  MX_EXIT_VISIT_OMPThreadPrivateDecl
MX_END_VISIT_DECL(OMPThreadPrivateDecl)

#ifndef MX_ENTER_VISIT_OMPRequiresDecl
#  define MX_ENTER_VISIT_OMPRequiresDecl MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl
#endif
#ifndef MX_EXIT_VISIT_OMPRequiresDecl
#  define MX_EXIT_VISIT_OMPRequiresDecl MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl
#endif

MX_BEGIN_VISIT_DECL(OMPRequiresDecl)
  MX_ENTER_VISIT_OMPRequiresDecl
  MX_VISIT_BASE(OMPRequiresDecl, OMPDeclarativeDirectiveDecl)
  MX_EXIT_VISIT_OMPRequiresDecl
MX_END_VISIT_DECL(OMPRequiresDecl)

#ifndef MX_ENTER_VISIT_OMPAllocateDecl
#  define MX_ENTER_VISIT_OMPAllocateDecl MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl
#endif
#ifndef MX_EXIT_VISIT_OMPAllocateDecl
#  define MX_EXIT_VISIT_OMPAllocateDecl MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl
#endif

MX_BEGIN_VISIT_DECL(OMPAllocateDecl)
  MX_ENTER_VISIT_OMPAllocateDecl
  MX_VISIT_BASE(OMPAllocateDecl, OMPDeclarativeDirectiveDecl)
  MX_VISIT_ENTITY_LIST(OMPAllocateDecl, varlists, 45, MX_APPLY_METHOD, Varlists, Expr, NthDecl)
  MX_EXIT_VISIT_OMPAllocateDecl
MX_END_VISIT_DECL(OMPAllocateDecl)

#ifndef MX_ENTER_VISIT_TranslationUnitDecl
#  define MX_ENTER_VISIT_TranslationUnitDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_TranslationUnitDecl
#  define MX_EXIT_VISIT_TranslationUnitDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(TranslationUnitDecl)
  MX_ENTER_VISIT_TranslationUnitDecl
  MX_VISIT_DECL_CONTEXT(TranslationUnitDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_TranslationUnitDecl
MX_END_VISIT_DECL(TranslationUnitDecl)

#ifndef MX_ENTER_VISIT_StaticAssertDecl
#  define MX_ENTER_VISIT_StaticAssertDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_StaticAssertDecl
#  define MX_EXIT_VISIT_StaticAssertDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(StaticAssertDecl)
  MX_ENTER_VISIT_StaticAssertDecl
  MX_VISIT_BASE(StaticAssertDecl, Decl)
  MX_VISIT_ENTITY(StaticAssertDecl, assert_expression, 43, MX_APPLY_METHOD, AssertExpression, Expr, NthDecl, StmtUseSelector::ASSERT_EXPRESSION)
  MX_VISIT_ENTITY(StaticAssertDecl, message, 51, MX_APPLY_METHOD, Message, StringLiteral, NthDecl, StmtUseSelector::MESSAGE)
  MX_VISIT_ENTITY(StaticAssertDecl, r_paren_token, 52, MX_APPLY_METHOD, RParenToken, Token, NthDecl, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(StaticAssertDecl, is_failed, 44, MX_APPLY_METHOD, IsFailed, bool, NthDecl)
  MX_EXIT_VISIT_StaticAssertDecl
MX_END_VISIT_DECL(StaticAssertDecl)

#ifndef MX_ENTER_VISIT_RequiresExprBodyDecl
#  define MX_ENTER_VISIT_RequiresExprBodyDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_RequiresExprBodyDecl
#  define MX_EXIT_VISIT_RequiresExprBodyDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(RequiresExprBodyDecl)
  MX_ENTER_VISIT_RequiresExprBodyDecl
  MX_VISIT_BASE(RequiresExprBodyDecl, Decl)
  MX_VISIT_DECL_CONTEXT(RequiresExprBodyDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_RequiresExprBodyDecl
MX_END_VISIT_DECL(RequiresExprBodyDecl)

#ifndef MX_ENTER_VISIT_PragmaDetectMismatchDecl
#  define MX_ENTER_VISIT_PragmaDetectMismatchDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_PragmaDetectMismatchDecl
#  define MX_EXIT_VISIT_PragmaDetectMismatchDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(PragmaDetectMismatchDecl)
  MX_ENTER_VISIT_PragmaDetectMismatchDecl
  MX_VISIT_BASE(PragmaDetectMismatchDecl, Decl)
  MX_VISIT_TEXT(PragmaDetectMismatchDecl, name, 58, MX_APPLY_METHOD, Name, basic_string_view, NthDecl)
  MX_VISIT_TEXT(PragmaDetectMismatchDecl, value, 59, MX_APPLY_METHOD, Value, basic_string_view, NthDecl)
  MX_EXIT_VISIT_PragmaDetectMismatchDecl
MX_END_VISIT_DECL(PragmaDetectMismatchDecl)

#ifndef MX_ENTER_VISIT_PragmaCommentDecl
#  define MX_ENTER_VISIT_PragmaCommentDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_PragmaCommentDecl
#  define MX_EXIT_VISIT_PragmaCommentDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(PragmaCommentDecl)
  MX_ENTER_VISIT_PragmaCommentDecl
  MX_VISIT_BASE(PragmaCommentDecl, Decl)
  MX_VISIT_TEXT(PragmaCommentDecl, argument, 58, MX_APPLY_METHOD, Argument, basic_string_view, NthDecl)
  MX_VISIT_ENUM(PragmaCommentDecl, comment_kind, 60, MX_APPLY_METHOD, CommentKind, PragmaMSCommentKind, NthDecl)
  MX_EXIT_VISIT_PragmaCommentDecl
MX_END_VISIT_DECL(PragmaCommentDecl)

#ifndef MX_ENTER_VISIT_ObjCPropertyImplDecl
#  define MX_ENTER_VISIT_ObjCPropertyImplDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_ObjCPropertyImplDecl
#  define MX_EXIT_VISIT_ObjCPropertyImplDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(ObjCPropertyImplDecl)
  MX_ENTER_VISIT_ObjCPropertyImplDecl
  MX_VISIT_BASE(ObjCPropertyImplDecl, Decl)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, getter_cxx_constructor, 43, MX_APPLY_METHOD, GetterCXXConstructor, Expr, NthDecl, StmtUseSelector::GETTER_CXX_CONSTRUCTOR)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, getter_method_declaration, 51, MX_APPLY_METHOD, GetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::GETTER_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, property_declaration, 52, MX_APPLY_METHOD, PropertyDeclaration, ObjCPropertyDecl, NthDecl, DeclUseSelector::PROPERTY_DECLARATION)
  MX_VISIT_ENUM(ObjCPropertyImplDecl, property_implementation, 60, MX_APPLY_METHOD, PropertyImplementation, ObjCPropertyImplDeclKind, NthDecl)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, property_instance_variable_declaration, 53, MX_APPLY_METHOD, PropertyInstanceVariableDeclaration, ObjCIvarDecl, NthDecl, DeclUseSelector::PROPERTY_INSTANCE_VARIABLE_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, property_instance_variable_declaration_token, 61, MX_APPLY_METHOD, PropertyInstanceVariableDeclarationToken, Token, NthDecl, TokenUseSelector::PROPERTY_INSTANCE_VARIABLE_DECLARATION_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, setter_cxx_assignment, 62, MX_APPLY_METHOD, SetterCXXAssignment, Expr, NthDecl, StmtUseSelector::SETTER_CXX_ASSIGNMENT)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, setter_method_declaration, 63, MX_APPLY_METHOD, SetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::SETTER_METHOD_DECLARATION)
  MX_VISIT_BOOL(ObjCPropertyImplDecl, is_instance_variable_name_specified, 44, MX_APPLY_METHOD, IsInstanceVariableNameSpecified, bool, NthDecl)
  MX_EXIT_VISIT_ObjCPropertyImplDecl
MX_END_VISIT_DECL(ObjCPropertyImplDecl)

#ifndef MX_ENTER_VISIT_NamedDecl
#  define MX_ENTER_VISIT_NamedDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_NamedDecl
#  define MX_EXIT_VISIT_NamedDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(NamedDecl)
  MX_ENTER_VISIT_NamedDecl
  MX_VISIT_BASE(NamedDecl, Decl)
  MX_VISIT_ENUM(NamedDecl, formal_linkage, 60, MX_APPLY_METHOD, FormalLinkage, Linkage, NthDecl)
  MX_VISIT_TEXT(NamedDecl, name, 58, MX_APPLY_METHOD, Name, basic_string, NthDecl)
  MX_VISIT_OPTIONAL_ENUM(NamedDecl, obj_cf_string_formatting_family, 64, MX_APPLY_METHOD, ObjCFStringFormattingFamily, ObjCStringFormatFamily, NthDecl)
  MX_VISIT_TEXT(NamedDecl, qualified_name_as_string, 59, MX_APPLY_METHOD, QualifiedNameAsString, basic_string, NthDecl)
  MX_VISIT_ENTITY(NamedDecl, underlying_declaration, 43, MX_APPLY_METHOD, UnderlyingDeclaration, NamedDecl, NthDecl, DeclUseSelector::UNDERLYING_DECLARATION)
  MX_VISIT_ENUM(NamedDecl, visibility, 65, MX_APPLY_METHOD, Visibility, Visibility, NthDecl)
  MX_VISIT_BOOL(NamedDecl, has_external_formal_linkage, 47, MX_APPLY_METHOD, HasExternalFormalLinkage, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, has_linkage, 48, MX_APPLY_METHOD, HasLinkage, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, has_linkage_been_computed, 49, MX_APPLY_METHOD, HasLinkageBeenComputed, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_cxx_class_member, 50, MX_APPLY_METHOD, IsCXXClassMember, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_cxx_instance_member, 54, MX_APPLY_METHOD, IsCXXInstanceMember, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_externally_declarable, 55, MX_APPLY_METHOD, IsExternallyDeclarable, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_externally_visible, 56, MX_APPLY_METHOD, IsExternallyVisible, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_linkage_valid, 66, MX_APPLY_METHOD, IsLinkageValid, bool, NthDecl)
  MX_EXIT_VISIT_NamedDecl
MX_END_VISIT_DECL(NamedDecl)

#ifndef MX_ENTER_VISIT_LabelDecl
#  define MX_ENTER_VISIT_LabelDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_LabelDecl
#  define MX_EXIT_VISIT_LabelDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(LabelDecl)
  MX_ENTER_VISIT_LabelDecl
  MX_VISIT_BASE(LabelDecl, NamedDecl)
  MX_VISIT_TEXT(LabelDecl, ms_assembly_label, 67, MX_APPLY_METHOD, MSAssemblyLabel, basic_string_view, NthDecl)
  MX_VISIT_ENTITY(LabelDecl, statement, 51, MX_APPLY_METHOD, Statement, LabelStmt, NthDecl, StmtUseSelector::STATEMENT)
  MX_VISIT_BOOL(LabelDecl, is_gnu_local, 68, MX_APPLY_METHOD, IsGnuLocal, bool, NthDecl)
  MX_VISIT_BOOL(LabelDecl, is_ms_assembly_label, 69, MX_APPLY_METHOD, IsMSAssemblyLabel, bool, NthDecl)
  MX_VISIT_BOOL(LabelDecl, is_resolved_ms_assembly_label, 70, MX_APPLY_METHOD, IsResolvedMSAssemblyLabel, bool, NthDecl)
  MX_EXIT_VISIT_LabelDecl
MX_END_VISIT_DECL(LabelDecl)

#ifndef MX_ENTER_VISIT_BaseUsingDecl
#  define MX_ENTER_VISIT_BaseUsingDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_BaseUsingDecl
#  define MX_EXIT_VISIT_BaseUsingDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(BaseUsingDecl)
  MX_ENTER_VISIT_BaseUsingDecl
  MX_VISIT_BASE(BaseUsingDecl, NamedDecl)
  MX_VISIT_ENTITY_LIST(BaseUsingDecl, shadows, 45, MX_APPLY_METHOD, Shadows, UsingShadowDecl, NthDecl)
  MX_EXIT_VISIT_BaseUsingDecl
MX_END_VISIT_DECL(BaseUsingDecl)

#ifndef MX_ENTER_VISIT_UsingEnumDecl
#  define MX_ENTER_VISIT_UsingEnumDecl MX_ENTER_VISIT_BaseUsingDecl
#endif
#ifndef MX_EXIT_VISIT_UsingEnumDecl
#  define MX_EXIT_VISIT_UsingEnumDecl MX_EXIT_VISIT_BaseUsingDecl
#endif

MX_BEGIN_VISIT_DECL(UsingEnumDecl)
  MX_ENTER_VISIT_UsingEnumDecl
  MX_VISIT_BASE(UsingEnumDecl, BaseUsingDecl)
  MX_VISIT_ENTITY(UsingEnumDecl, enum_declaration, 51, MX_APPLY_METHOD, EnumDeclaration, EnumDecl, NthDecl, DeclUseSelector::ENUM_DECLARATION)
  MX_VISIT_ENTITY(UsingEnumDecl, enum_token, 52, MX_APPLY_METHOD, EnumToken, Token, NthDecl, TokenUseSelector::ENUM_TOKEN)
  MX_VISIT_ENTITY(UsingEnumDecl, using_token, 53, MX_APPLY_METHOD, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_EXIT_VISIT_UsingEnumDecl
MX_END_VISIT_DECL(UsingEnumDecl)

#ifndef MX_ENTER_VISIT_UsingDecl
#  define MX_ENTER_VISIT_UsingDecl MX_ENTER_VISIT_BaseUsingDecl
#endif
#ifndef MX_EXIT_VISIT_UsingDecl
#  define MX_EXIT_VISIT_UsingDecl MX_EXIT_VISIT_BaseUsingDecl
#endif

MX_BEGIN_VISIT_DECL(UsingDecl)
  MX_ENTER_VISIT_UsingDecl
  MX_VISIT_BASE(UsingDecl, BaseUsingDecl)
  MX_VISIT_ENTITY(UsingDecl, using_token, 51, MX_APPLY_METHOD, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_VISIT_BOOL(UsingDecl, has_typename, 68, MX_APPLY_METHOD, HasTypename, bool, NthDecl)
  MX_VISIT_BOOL(UsingDecl, is_access_declaration, 69, MX_APPLY_METHOD, IsAccessDeclaration, bool, NthDecl)
  MX_EXIT_VISIT_UsingDecl
MX_END_VISIT_DECL(UsingDecl)

#ifndef MX_ENTER_VISIT_ValueDecl
#  define MX_ENTER_VISIT_ValueDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_ValueDecl
#  define MX_EXIT_VISIT_ValueDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(ValueDecl)
  MX_ENTER_VISIT_ValueDecl
  MX_VISIT_BASE(ValueDecl, NamedDecl)
  MX_VISIT_ENTITY(ValueDecl, type, 51, MX_APPLY_METHOD, Type, Type, NthDecl, TypeUseSelector::TYPE)
  MX_VISIT_BOOL(ValueDecl, is_weak, 68, MX_APPLY_METHOD, IsWeak, bool, NthDecl)
  MX_EXIT_VISIT_ValueDecl
MX_END_VISIT_DECL(ValueDecl)

#ifndef MX_ENTER_VISIT_UnresolvedUsingValueDecl
#  define MX_ENTER_VISIT_UnresolvedUsingValueDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_UnresolvedUsingValueDecl
#  define MX_EXIT_VISIT_UnresolvedUsingValueDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(UnresolvedUsingValueDecl)
  MX_ENTER_VISIT_UnresolvedUsingValueDecl
  MX_VISIT_BASE(UnresolvedUsingValueDecl, ValueDecl)
  MX_VISIT_ENTITY(UnresolvedUsingValueDecl, ellipsis_token, 52, MX_APPLY_METHOD, EllipsisToken, Token, NthDecl, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(UnresolvedUsingValueDecl, using_token, 53, MX_APPLY_METHOD, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_VISIT_BOOL(UnresolvedUsingValueDecl, is_access_declaration, 69, MX_APPLY_METHOD, IsAccessDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(UnresolvedUsingValueDecl, is_pack_expansion, 70, MX_APPLY_METHOD, IsPackExpansion, bool, NthDecl)
  MX_EXIT_VISIT_UnresolvedUsingValueDecl
MX_END_VISIT_DECL(UnresolvedUsingValueDecl)

#ifndef MX_ENTER_VISIT_TemplateParamObjectDecl
#  define MX_ENTER_VISIT_TemplateParamObjectDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_TemplateParamObjectDecl
#  define MX_EXIT_VISIT_TemplateParamObjectDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(TemplateParamObjectDecl)
  MX_ENTER_VISIT_TemplateParamObjectDecl
  MX_VISIT_BASE(TemplateParamObjectDecl, ValueDecl)
  MX_EXIT_VISIT_TemplateParamObjectDecl
MX_END_VISIT_DECL(TemplateParamObjectDecl)

#ifndef MX_ENTER_VISIT_OMPDeclareReductionDecl
#  define MX_ENTER_VISIT_OMPDeclareReductionDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_OMPDeclareReductionDecl
#  define MX_EXIT_VISIT_OMPDeclareReductionDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(OMPDeclareReductionDecl)
  MX_ENTER_VISIT_OMPDeclareReductionDecl
  MX_VISIT_BASE(OMPDeclareReductionDecl, ValueDecl)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, combiner, 52, MX_APPLY_METHOD, Combiner, Expr, NthDecl, StmtUseSelector::COMBINER)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, combiner_in, 53, MX_APPLY_METHOD, CombinerIn, Expr, NthDecl, StmtUseSelector::COMBINER_IN)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, combiner_out, 61, MX_APPLY_METHOD, CombinerOut, Expr, NthDecl, StmtUseSelector::COMBINER_OUT)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, initializer_original, 62, MX_APPLY_METHOD, InitializerOriginal, Expr, NthDecl, StmtUseSelector::INITIALIZER_ORIGINAL)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, initializer_private, 63, MX_APPLY_METHOD, InitializerPrivate, Expr, NthDecl, StmtUseSelector::INITIALIZER_PRIVATE)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, initializer, 71, MX_APPLY_METHOD, Initializer, Expr, NthDecl, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENUM(OMPDeclareReductionDecl, initializer_kind, 72, MX_APPLY_METHOD, InitializerKind, OMPDeclareReductionDeclInitKind, NthDecl)
  MX_VISIT_DECL_CONTEXT(OMPDeclareReductionDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_OMPDeclareReductionDecl
MX_END_VISIT_DECL(OMPDeclareReductionDecl)

#ifndef MX_ENTER_VISIT_MSGuidDecl
#  define MX_ENTER_VISIT_MSGuidDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_MSGuidDecl
#  define MX_EXIT_VISIT_MSGuidDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(MSGuidDecl)
  MX_ENTER_VISIT_MSGuidDecl
  MX_VISIT_BASE(MSGuidDecl, ValueDecl)
  MX_EXIT_VISIT_MSGuidDecl
MX_END_VISIT_DECL(MSGuidDecl)

#ifndef MX_ENTER_VISIT_IndirectFieldDecl
#  define MX_ENTER_VISIT_IndirectFieldDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_IndirectFieldDecl
#  define MX_EXIT_VISIT_IndirectFieldDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(IndirectFieldDecl)
  MX_ENTER_VISIT_IndirectFieldDecl
  MX_VISIT_BASE(IndirectFieldDecl, ValueDecl)
  MX_VISIT_ENTITY_LIST(IndirectFieldDecl, chain, 45, MX_APPLY_METHOD, Chain, NamedDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(IndirectFieldDecl, anonymous_field, 52, MX_APPLY_METHOD, AnonymousField, FieldDecl, NthDecl, DeclUseSelector::ANONYMOUS_FIELD)
  MX_VISIT_OPTIONAL_ENTITY(IndirectFieldDecl, variable_declaration, 53, MX_APPLY_METHOD, VariableDeclaration, VarDecl, NthDecl, DeclUseSelector::VARIABLE_DECLARATION)
  MX_EXIT_VISIT_IndirectFieldDecl
MX_END_VISIT_DECL(IndirectFieldDecl)

#ifndef MX_ENTER_VISIT_EnumConstantDecl
#  define MX_ENTER_VISIT_EnumConstantDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_EnumConstantDecl
#  define MX_EXIT_VISIT_EnumConstantDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(EnumConstantDecl)
  MX_ENTER_VISIT_EnumConstantDecl
  MX_VISIT_BASE(EnumConstantDecl, ValueDecl)
  MX_VISIT_OPTIONAL_ENTITY(EnumConstantDecl, initializer_expression, 52, MX_APPLY_METHOD, InitializerExpression, Expr, NthDecl, StmtUseSelector::INITIALIZER_EXPRESSION)
  MX_EXIT_VISIT_EnumConstantDecl
MX_END_VISIT_DECL(EnumConstantDecl)

#ifndef MX_ENTER_VISIT_DeclaratorDecl
#  define MX_ENTER_VISIT_DeclaratorDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_DeclaratorDecl
#  define MX_EXIT_VISIT_DeclaratorDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(DeclaratorDecl)
  MX_ENTER_VISIT_DeclaratorDecl
  MX_VISIT_BASE(DeclaratorDecl, ValueDecl)
  MX_VISIT_ENTITY(DeclaratorDecl, first_inner_token, 52, MX_APPLY_METHOD, FirstInnerToken, Token, NthDecl, TokenUseSelector::FIRST_INNER_TOKEN)
  MX_VISIT_ENTITY(DeclaratorDecl, first_outer_token, 53, MX_APPLY_METHOD, FirstOuterToken, Token, NthDecl, TokenUseSelector::FIRST_OUTER_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(DeclaratorDecl, trailing_requires_clause, 61, MX_APPLY_METHOD, TrailingRequiresClause, Expr, NthDecl, StmtUseSelector::TRAILING_REQUIRES_CLAUSE)
  MX_VISIT_ENTITY(DeclaratorDecl, type_spec_end_token, 62, MX_APPLY_METHOD, TypeSpecEndToken, Token, NthDecl, TokenUseSelector::TYPE_SPEC_END_TOKEN)
  MX_VISIT_ENTITY(DeclaratorDecl, type_spec_start_token, 63, MX_APPLY_METHOD, TypeSpecStartToken, Token, NthDecl, TokenUseSelector::TYPE_SPEC_START_TOKEN)
  MX_VISIT_PSEUDO_LIST(DeclaratorDecl, template_parameter_lists, 73, MX_APPLY_METHOD, TemplateParameterLists, TemplateParameterList, NthDecl)
  MX_EXIT_VISIT_DeclaratorDecl
MX_END_VISIT_DECL(DeclaratorDecl)

#ifndef MX_ENTER_VISIT_VarDecl
#  define MX_ENTER_VISIT_VarDecl MX_ENTER_VISIT_DeclaratorDecl
#endif
#ifndef MX_EXIT_VISIT_VarDecl
#  define MX_EXIT_VISIT_VarDecl MX_EXIT_VISIT_DeclaratorDecl
#endif

MX_BEGIN_VISIT_DECL(VarDecl)
  MX_ENTER_VISIT_VarDecl
  MX_VISIT_BASE(VarDecl, DeclaratorDecl)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, acting_definition, 71, MX_APPLY_METHOD, ActingDefinition, VarDecl, NthDecl, DeclUseSelector::ACTING_DEFINITION)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, initializer, 74, MX_APPLY_METHOD, Initializer, Expr, NthDecl, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENUM(VarDecl, initializer_style, 72, MX_APPLY_METHOD, InitializerStyle, VarDeclInitializationStyle, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, initializing_declaration, 76, MX_APPLY_METHOD, InitializingDeclaration, VarDecl, NthDecl, DeclUseSelector::INITIALIZING_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, instantiated_from_static_data_member, 78, MX_APPLY_METHOD, InstantiatedFromStaticDataMember, VarDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_STATIC_DATA_MEMBER)
  MX_VISIT_ENUM(VarDecl, language_linkage, 80, MX_APPLY_METHOD, LanguageLinkage, LanguageLinkage, NthDecl)
  MX_VISIT_ENTITY(VarDecl, point_of_instantiation, 81, MX_APPLY_METHOD, PointOfInstantiation, Token, NthDecl, TokenUseSelector::POINT_OF_INSTANTIATION)
  MX_VISIT_ENUM(VarDecl, storage_class, 82, MX_APPLY_METHOD, StorageClass, StorageClass, NthDecl)
  MX_VISIT_ENUM(VarDecl, storage_duration, 83, MX_APPLY_METHOD, StorageDuration, StorageDuration, NthDecl)
  MX_VISIT_ENUM(VarDecl, tls_kind, 84, MX_APPLY_METHOD, TLSKind, VarDeclTLSKind, NthDecl)
  MX_VISIT_ENUM(VarDecl, tsc_spec, 85, MX_APPLY_METHOD, TSCSpec, ThreadStorageClassSpecifier, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, template_instantiation_pattern, 86, MX_APPLY_METHOD, TemplateInstantiationPattern, VarDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(VarDecl, template_specialization_kind, 88, MX_APPLY_METHOD, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_ENUM(VarDecl, template_specialization_kind_for_instantiation, 89, MX_APPLY_METHOD, TemplateSpecializationKindForInstantiation, TemplateSpecializationKind, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_constant_initialization, 90, MX_APPLY_METHOD, HasConstantInitialization, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_dependent_alignment, 91, MX_APPLY_METHOD, HasDependentAlignment, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_external_storage, 92, MX_APPLY_METHOD, HasExternalStorage, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_global_storage, 93, MX_APPLY_METHOD, HasGlobalStorage, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(VarDecl, has_ice_initializer, 94, MX_APPLY_METHOD, HasICEInitializer, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_initializer, 96, MX_APPLY_METHOD, HasInitializer, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_local_storage, 97, MX_APPLY_METHOD, HasLocalStorage, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_arc_pseudo_strong, 98, MX_APPLY_METHOD, IsARCPseudoStrong, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_cxx_for_range_declaration, 99, MX_APPLY_METHOD, IsCXXForRangeDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_constexpr, 100, MX_APPLY_METHOD, IsConstexpr, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_direct_initializer, 101, MX_APPLY_METHOD, IsDirectInitializer, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_escaping_byref, 102, MX_APPLY_METHOD, IsEscapingByref, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_exception_variable, 103, MX_APPLY_METHOD, IsExceptionVariable, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_extern_c, 104, MX_APPLY_METHOD, IsExternC, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_file_variable_declaration, 105, MX_APPLY_METHOD, IsFileVariableDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_function_or_method_variable_declaration, 106, MX_APPLY_METHOD, IsFunctionOrMethodVariableDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_in_extern_c_context, 107, MX_APPLY_METHOD, IsInExternCContext, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_in_extern_cxx_context, 108, MX_APPLY_METHOD, IsInExternCXXContext, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_initializer_capture, 109, MX_APPLY_METHOD, IsInitializerCapture, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_inline, 110, MX_APPLY_METHOD, IsInline, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_inline_specified, 111, MX_APPLY_METHOD, IsInlineSpecified, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_known_to_be_defined, 112, MX_APPLY_METHOD, IsKnownToBeDefined, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_local_variable_declaration, 113, MX_APPLY_METHOD, IsLocalVariableDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_local_variable_declaration_or_parm, 114, MX_APPLY_METHOD, IsLocalVariableDeclarationOrParm, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_nrvo_variable, 115, MX_APPLY_METHOD, IsNRVOVariable, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_no_destroy, 116, MX_APPLY_METHOD, IsNoDestroy, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_non_escaping_byref, 117, MX_APPLY_METHOD, IsNonEscapingByref, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_obj_c_for_declaration, 118, MX_APPLY_METHOD, IsObjCForDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_previous_declaration_in_same_block_scope, 119, MX_APPLY_METHOD, IsPreviousDeclarationInSameBlockScope, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_static_data_member, 120, MX_APPLY_METHOD, IsStaticDataMember, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_static_local, 121, MX_APPLY_METHOD, IsStaticLocal, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_demoted_definition, 122, MX_APPLY_METHOD, IsThisDeclarationADemotedDefinition, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_usable_in_constant_expressions, 123, MX_APPLY_METHOD, IsUsableInConstantExpressions, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, might_be_usable_in_constant_expressions, 124, MX_APPLY_METHOD, MightBeUsableInConstantExpressions, bool, NthDecl)
  MX_VISIT_ENUM(VarDecl, needs_destruction, 125, MX_APPLY_METHOD, NeedsDestruction, QualTypeDestructionKind, NthDecl)
  MX_EXIT_VISIT_VarDecl
MX_END_VISIT_DECL(VarDecl)

#ifndef MX_ENTER_VISIT_ParmVarDecl
#  define MX_ENTER_VISIT_ParmVarDecl MX_ENTER_VISIT_VarDecl
#endif
#ifndef MX_EXIT_VISIT_ParmVarDecl
#  define MX_EXIT_VISIT_ParmVarDecl MX_EXIT_VISIT_VarDecl
#endif

MX_BEGIN_VISIT_DECL(ParmVarDecl)
  MX_ENTER_VISIT_ParmVarDecl
  MX_VISIT_BASE(ParmVarDecl, VarDecl)
  MX_VISIT_OPTIONAL_ENTITY(ParmVarDecl, default_argument, 126, MX_APPLY_METHOD, DefaultArgument, Expr, NthDecl, StmtUseSelector::DEFAULT_ARGUMENT)
  MX_VISIT_ENUM(ParmVarDecl, obj_c_decl_qualifier, 130, MX_APPLY_METHOD, ObjCDeclQualifier, DeclObjCDeclQualifier, NthDecl)
  MX_VISIT_ENTITY(ParmVarDecl, original_type, 131, MX_APPLY_METHOD, OriginalType, Type, NthDecl, TypeUseSelector::ORIGINAL_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(ParmVarDecl, uninstantiated_default_argument, 132, MX_APPLY_METHOD, UninstantiatedDefaultArgument, Expr, NthDecl, StmtUseSelector::UNINSTANTIATED_DEFAULT_ARGUMENT)
  MX_VISIT_BOOL(ParmVarDecl, has_default_argument, 134, MX_APPLY_METHOD, HasDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, has_inherited_default_argument, 135, MX_APPLY_METHOD, HasInheritedDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, has_uninstantiated_default_argument, 136, MX_APPLY_METHOD, HasUninstantiatedDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, has_unparsed_default_argument, 137, MX_APPLY_METHOD, HasUnparsedDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, is_destroyed_in_callee, 138, MX_APPLY_METHOD, IsDestroyedInCallee, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, is_knr_promoted, 139, MX_APPLY_METHOD, IsKNRPromoted, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, is_obj_c_method_parameter, 140, MX_APPLY_METHOD, IsObjCMethodParameter, bool, NthDecl)
  MX_EXIT_VISIT_ParmVarDecl
MX_END_VISIT_DECL(ParmVarDecl)

#ifndef MX_ENTER_VISIT_OMPCapturedExprDecl
#  define MX_ENTER_VISIT_OMPCapturedExprDecl MX_ENTER_VISIT_VarDecl
#endif
#ifndef MX_EXIT_VISIT_OMPCapturedExprDecl
#  define MX_EXIT_VISIT_OMPCapturedExprDecl MX_EXIT_VISIT_VarDecl
#endif

MX_BEGIN_VISIT_DECL(OMPCapturedExprDecl)
  MX_ENTER_VISIT_OMPCapturedExprDecl
  MX_VISIT_BASE(OMPCapturedExprDecl, VarDecl)
  MX_EXIT_VISIT_OMPCapturedExprDecl
MX_END_VISIT_DECL(OMPCapturedExprDecl)

#ifndef MX_ENTER_VISIT_ImplicitParamDecl
#  define MX_ENTER_VISIT_ImplicitParamDecl MX_ENTER_VISIT_VarDecl
#endif
#ifndef MX_EXIT_VISIT_ImplicitParamDecl
#  define MX_EXIT_VISIT_ImplicitParamDecl MX_EXIT_VISIT_VarDecl
#endif

MX_BEGIN_VISIT_DECL(ImplicitParamDecl)
  MX_ENTER_VISIT_ImplicitParamDecl
  MX_VISIT_BASE(ImplicitParamDecl, VarDecl)
  MX_VISIT_ENUM(ImplicitParamDecl, parameter_kind, 130, MX_APPLY_METHOD, ParameterKind, ImplicitParamDeclImplicitParamKind, NthDecl)
  MX_EXIT_VISIT_ImplicitParamDecl
MX_END_VISIT_DECL(ImplicitParamDecl)

#ifndef MX_ENTER_VISIT_DecompositionDecl
#  define MX_ENTER_VISIT_DecompositionDecl MX_ENTER_VISIT_VarDecl
#endif
#ifndef MX_EXIT_VISIT_DecompositionDecl
#  define MX_EXIT_VISIT_DecompositionDecl MX_EXIT_VISIT_VarDecl
#endif

MX_BEGIN_VISIT_DECL(DecompositionDecl)
  MX_ENTER_VISIT_DecompositionDecl
  MX_VISIT_BASE(DecompositionDecl, VarDecl)
  MX_VISIT_ENTITY_LIST(DecompositionDecl, bindings, 45, MX_APPLY_METHOD, Bindings, BindingDecl, NthDecl)
  MX_EXIT_VISIT_DecompositionDecl
MX_END_VISIT_DECL(DecompositionDecl)

#ifndef MX_ENTER_VISIT_VarTemplateSpecializationDecl
#  define MX_ENTER_VISIT_VarTemplateSpecializationDecl MX_ENTER_VISIT_VarDecl
#endif
#ifndef MX_EXIT_VISIT_VarTemplateSpecializationDecl
#  define MX_EXIT_VISIT_VarTemplateSpecializationDecl MX_EXIT_VISIT_VarDecl
#endif

MX_BEGIN_VISIT_DECL(VarTemplateSpecializationDecl)
  MX_ENTER_VISIT_VarTemplateSpecializationDecl
  MX_VISIT_BASE(VarTemplateSpecializationDecl, VarDecl)
  MX_VISIT_ENTITY(VarTemplateSpecializationDecl, extern_token, 126, MX_APPLY_METHOD, ExternToken, Token, NthDecl, TokenUseSelector::EXTERN_TOKEN)
  MX_VISIT_ENUM(VarTemplateSpecializationDecl, specialization_kind, 130, MX_APPLY_METHOD, SpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_PSEUDO_LIST(VarTemplateSpecializationDecl, template_arguments, 141, MX_APPLY_METHOD, TemplateArguments, TemplateArgument, NthDecl)
  MX_VISIT_PSEUDO_LIST(VarTemplateSpecializationDecl, template_instantiation_arguments, 142, MX_APPLY_METHOD, TemplateInstantiationArguments, TemplateArgument, NthDecl)
  MX_VISIT_ENTITY(VarTemplateSpecializationDecl, template_keyword_token, 128, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthDecl, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_ENTITY(VarTemplateSpecializationDecl, type_as_written, 129, MX_APPLY_METHOD, TypeAsWritten, Type, NthDecl, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(VarTemplateSpecializationDecl, is_class_scope_explicit_specialization, 127, MX_APPLY_METHOD, IsClassScopeExplicitSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(VarTemplateSpecializationDecl, is_explicit_instantiation_or_specialization, 133, MX_APPLY_METHOD, IsExplicitInstantiationOrSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(VarTemplateSpecializationDecl, is_explicit_specialization, 134, MX_APPLY_METHOD, IsExplicitSpecialization, bool, NthDecl)
  MX_EXIT_VISIT_VarTemplateSpecializationDecl
MX_END_VISIT_DECL(VarTemplateSpecializationDecl)

#ifndef MX_ENTER_VISIT_VarTemplatePartialSpecializationDecl
#  define MX_ENTER_VISIT_VarTemplatePartialSpecializationDecl MX_ENTER_VISIT_VarTemplateSpecializationDecl
#endif
#ifndef MX_EXIT_VISIT_VarTemplatePartialSpecializationDecl
#  define MX_EXIT_VISIT_VarTemplatePartialSpecializationDecl MX_EXIT_VISIT_VarTemplateSpecializationDecl
#endif

MX_BEGIN_VISIT_DECL(VarTemplatePartialSpecializationDecl)
  MX_ENTER_VISIT_VarTemplatePartialSpecializationDecl
  MX_EXIT_VISIT_VarTemplatePartialSpecializationDecl
MX_END_VISIT_DECL(VarTemplatePartialSpecializationDecl)

#ifndef MX_ENTER_VISIT_NonTypeTemplateParmDecl
#  define MX_ENTER_VISIT_NonTypeTemplateParmDecl MX_ENTER_VISIT_DeclaratorDecl
#endif
#ifndef MX_EXIT_VISIT_NonTypeTemplateParmDecl
#  define MX_EXIT_VISIT_NonTypeTemplateParmDecl MX_EXIT_VISIT_DeclaratorDecl
#endif

MX_BEGIN_VISIT_DECL(NonTypeTemplateParmDecl)
  MX_ENTER_VISIT_NonTypeTemplateParmDecl
  MX_VISIT_BASE(NonTypeTemplateParmDecl, DeclaratorDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, default_argument_was_inherited, 70, MX_APPLY_METHOD, DefaultArgumentWasInherited, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(NonTypeTemplateParmDecl, default_argument, 71, MX_APPLY_METHOD, DefaultArgument, Expr, NthDecl, StmtUseSelector::DEFAULT_ARGUMENT)
  MX_VISIT_ENTITY(NonTypeTemplateParmDecl, default_argument_token, 74, MX_APPLY_METHOD, DefaultArgumentToken, Token, NthDecl, TokenUseSelector::DEFAULT_ARGUMENT_TOKEN)
  MX_VISIT_OPTIONAL_INT(NonTypeTemplateParmDecl, num_expansion_types, 143, MX_APPLY_METHOD, NumExpansionTypes, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(NonTypeTemplateParmDecl, placeholder_type_constraint, 76, MX_APPLY_METHOD, PlaceholderTypeConstraint, Expr, NthDecl, StmtUseSelector::PLACEHOLDER_TYPE_CONSTRAINT)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, has_default_argument, 87, MX_APPLY_METHOD, HasDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, has_placeholder_type_constraint, 90, MX_APPLY_METHOD, HasPlaceholderTypeConstraint, bool, NthDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, is_expanded_parameter_pack, 91, MX_APPLY_METHOD, IsExpandedParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, is_pack_expansion, 92, MX_APPLY_METHOD, IsPackExpansion, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(NonTypeTemplateParmDecl, expansion_types, 45, MX_APPLY_METHOD, ExpansionTypes, Type, NthDecl)
  MX_EXIT_VISIT_NonTypeTemplateParmDecl
MX_END_VISIT_DECL(NonTypeTemplateParmDecl)

#ifndef MX_ENTER_VISIT_MSPropertyDecl
#  define MX_ENTER_VISIT_MSPropertyDecl MX_ENTER_VISIT_DeclaratorDecl
#endif
#ifndef MX_EXIT_VISIT_MSPropertyDecl
#  define MX_EXIT_VISIT_MSPropertyDecl MX_EXIT_VISIT_DeclaratorDecl
#endif

MX_BEGIN_VISIT_DECL(MSPropertyDecl)
  MX_ENTER_VISIT_MSPropertyDecl
  MX_VISIT_BASE(MSPropertyDecl, DeclaratorDecl)
  MX_VISIT_BOOL(MSPropertyDecl, has_getter, 70, MX_APPLY_METHOD, HasGetter, bool, NthDecl)
  MX_VISIT_BOOL(MSPropertyDecl, has_setter, 75, MX_APPLY_METHOD, HasSetter, bool, NthDecl)
  MX_EXIT_VISIT_MSPropertyDecl
MX_END_VISIT_DECL(MSPropertyDecl)

#ifndef MX_ENTER_VISIT_FunctionDecl
#  define MX_ENTER_VISIT_FunctionDecl MX_ENTER_VISIT_DeclaratorDecl
#endif
#ifndef MX_EXIT_VISIT_FunctionDecl
#  define MX_EXIT_VISIT_FunctionDecl MX_EXIT_VISIT_DeclaratorDecl
#endif

MX_BEGIN_VISIT_DECL(FunctionDecl)
  MX_ENTER_VISIT_FunctionDecl
  MX_VISIT_BASE(FunctionDecl, DeclaratorDecl)
  MX_VISIT_BOOL(FunctionDecl, uses_fp_intrin, 70, MX_APPLY_METHOD, UsesFPIntrin, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, does_declaration_force_externally_visible_definition, 75, MX_APPLY_METHOD, DoesDeclarationForceExternallyVisibleDefinition, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, does_this_declaration_have_a_body, 79, MX_APPLY_METHOD, DoesThisDeclarationHaveABody, bool, NthDecl)
  MX_VISIT_ENTITY(FunctionDecl, call_result_type, 71, MX_APPLY_METHOD, CallResultType, Type, NthDecl, TypeUseSelector::CALL_RESULT_TYPE)
  MX_VISIT_ENUM(FunctionDecl, constexpr_kind, 72, MX_APPLY_METHOD, ConstexprKind, ConstexprSpecKind, NthDecl)
  MX_VISIT_ENTITY(FunctionDecl, declared_return_type, 74, MX_APPLY_METHOD, DeclaredReturnType, Type, NthDecl, TypeUseSelector::DECLARED_RETURN_TYPE)
  MX_VISIT_ENTITY(FunctionDecl, ellipsis_token, 76, MX_APPLY_METHOD, EllipsisToken, Token, NthDecl, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENUM(FunctionDecl, exception_spec_type, 80, MX_APPLY_METHOD, ExceptionSpecType, ExceptionSpecificationType, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FunctionDecl, instantiated_from_member_function, 86, MX_APPLY_METHOD, InstantiatedFromMemberFunction, FunctionDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_FUNCTION)
  MX_VISIT_ENUM(FunctionDecl, language_linkage, 82, MX_APPLY_METHOD, LanguageLinkage, LanguageLinkage, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, multi_version_kind, 83, MX_APPLY_METHOD, MultiVersionKind, MultiVersionKind, NthDecl)
  MX_VISIT_OPTIONAL_INT(FunctionDecl, odr_hash, 143, MX_APPLY_METHOD, ODRHash, unsigned, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, overloaded_operator, 84, MX_APPLY_METHOD, OverloadedOperator, OverloadedOperatorKind, NthDecl)
  MX_VISIT_ENTITY(FunctionDecl, point_of_instantiation, 129, MX_APPLY_METHOD, PointOfInstantiation, Token, NthDecl, TokenUseSelector::POINT_OF_INSTANTIATION)
  MX_VISIT_ENTITY(FunctionDecl, return_type, 131, MX_APPLY_METHOD, ReturnType, Type, NthDecl, TypeUseSelector::RETURN_TYPE)
  MX_VISIT_ENUM(FunctionDecl, storage_class, 85, MX_APPLY_METHOD, StorageClass, StorageClass, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FunctionDecl, template_instantiation_pattern, 145, MX_APPLY_METHOD, TemplateInstantiationPattern, FunctionDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(FunctionDecl, template_specialization_kind, 88, MX_APPLY_METHOD, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, template_specialization_kind_for_instantiation, 89, MX_APPLY_METHOD, TemplateSpecializationKindForInstantiation, TemplateSpecializationKind, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, templated_kind, 125, MX_APPLY_METHOD, TemplatedKind, FunctionDeclTemplatedKind, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_implicit_return_zero, 92, MX_APPLY_METHOD, HasImplicitReturnZero, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_inherited_prototype, 93, MX_APPLY_METHOD, HasInheritedPrototype, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_one_parameter_or_default_arguments, 94, MX_APPLY_METHOD, HasOneParameterOrDefaultArguments, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_prototype, 95, MX_APPLY_METHOD, HasPrototype, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_skipped_body, 96, MX_APPLY_METHOD, HasSkippedBody, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_trivial_body, 97, MX_APPLY_METHOD, HasTrivialBody, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_written_prototype, 98, MX_APPLY_METHOD, HasWrittenPrototype, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, instantiation_is_pending, 99, MX_APPLY_METHOD, InstantiationIsPending, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_cpu_dispatch_multi_version, 100, MX_APPLY_METHOD, IsCPUDispatchMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_cpu_specific_multi_version, 101, MX_APPLY_METHOD, IsCPUSpecificMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_consteval, 102, MX_APPLY_METHOD, IsConsteval, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_constexpr, 103, MX_APPLY_METHOD, IsConstexpr, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_constexpr_specified, 104, MX_APPLY_METHOD, IsConstexprSpecified, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_defaulted, 105, MX_APPLY_METHOD, IsDefaulted, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_deleted, 106, MX_APPLY_METHOD, IsDeleted, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_deleted_as_written, 107, MX_APPLY_METHOD, IsDeletedAsWritten, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_destroying_operator_delete, 108, MX_APPLY_METHOD, IsDestroyingOperatorDelete, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_explicitly_defaulted, 109, MX_APPLY_METHOD, IsExplicitlyDefaulted, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_extern_c, 110, MX_APPLY_METHOD, IsExternC, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_function_template_specialization, 111, MX_APPLY_METHOD, IsFunctionTemplateSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_global, 112, MX_APPLY_METHOD, IsGlobal, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_implicitly_instantiable, 113, MX_APPLY_METHOD, IsImplicitlyInstantiable, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_in_extern_c_context, 114, MX_APPLY_METHOD, IsInExternCContext, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_in_extern_cxx_context, 115, MX_APPLY_METHOD, IsInExternCXXContext, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_inline_builtin_declaration, 116, MX_APPLY_METHOD, IsInlineBuiltinDeclaration, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, is_inline_definition_externally_visible, 117, MX_APPLY_METHOD, IsInlineDefinitionExternallyVisible, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_inline_specified, 119, MX_APPLY_METHOD, IsInlineSpecified, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_inlined, 120, MX_APPLY_METHOD, IsInlined, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_late_template_parsed, 121, MX_APPLY_METHOD, IsLateTemplateParsed, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, is_ms_extern_inline, 122, MX_APPLY_METHOD, IsMSExternInline, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_msvcrt_entry_point, 124, MX_APPLY_METHOD, IsMSVCRTEntryPoint, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_main, 127, MX_APPLY_METHOD, IsMain, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_multi_version, 133, MX_APPLY_METHOD, IsMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_no_return, 134, MX_APPLY_METHOD, IsNoReturn, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_overloaded_operator, 135, MX_APPLY_METHOD, IsOverloadedOperator, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_pure, 136, MX_APPLY_METHOD, IsPure, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_replaceable_global_allocation_function, 137, MX_APPLY_METHOD, IsReplaceableGlobalAllocationFunction, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, is_reserved_global_placement_operator, 138, MX_APPLY_METHOD, IsReservedGlobalPlacementOperator, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_static, 140, MX_APPLY_METHOD, IsStatic, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_target_clones_multi_version, 146, MX_APPLY_METHOD, IsTargetClonesMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_target_multi_version, 147, MX_APPLY_METHOD, IsTargetMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_template_instantiation, 148, MX_APPLY_METHOD, IsTemplateInstantiation, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_this_declaration_instantiated_from_a_friend_definition, 149, MX_APPLY_METHOD, IsThisDeclarationInstantiatedFromAFriendDefinition, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_trivial, 150, MX_APPLY_METHOD, IsTrivial, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_trivial_for_call, 151, MX_APPLY_METHOD, IsTrivialForCall, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_user_provided, 152, MX_APPLY_METHOD, IsUserProvided, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_variadic, 153, MX_APPLY_METHOD, IsVariadic, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_virtual_as_written, 154, MX_APPLY_METHOD, IsVirtualAsWritten, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(FunctionDecl, parameters, 45, MX_APPLY_METHOD, Parameters, ParmVarDecl, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, uses_seh_try, 155, MX_APPLY_METHOD, UsesSEHTry, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, will_have_body, 156, MX_APPLY_METHOD, WillHaveBody, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FunctionDecl, body, 157, MX_APPLY_METHOD, Body, Stmt, NthDecl, StmtUseSelector::BODY)
  MX_VISIT_DECL_CONTEXT(FunctionDecl, declarations_in_context, 46, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_FunctionDecl
MX_END_VISIT_DECL(FunctionDecl)

#ifndef MX_ENTER_VISIT_CXXMethodDecl
#  define MX_ENTER_VISIT_CXXMethodDecl MX_ENTER_VISIT_FunctionDecl
#endif
#ifndef MX_EXIT_VISIT_CXXMethodDecl
#  define MX_EXIT_VISIT_CXXMethodDecl MX_EXIT_VISIT_FunctionDecl
#endif

MX_BEGIN_VISIT_DECL(CXXMethodDecl)
  MX_ENTER_VISIT_CXXMethodDecl
  MX_VISIT_BASE(CXXMethodDecl, FunctionDecl)
  MX_VISIT_ENUM(CXXMethodDecl, reference_qualifier, 130, MX_APPLY_METHOD, ReferenceQualifier, RefQualifierKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXMethodDecl, this_object_type, 159, MX_APPLY_METHOD, ThisObjectType, Type, NthDecl, TypeUseSelector::THIS_OBJECT_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXMethodDecl, this_type, 161, MX_APPLY_METHOD, ThisType, Type, NthDecl, TypeUseSelector::THIS_TYPE)
  MX_VISIT_BOOL(CXXMethodDecl, has_inline_body, 163, MX_APPLY_METHOD, HasInlineBody, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_const, 164, MX_APPLY_METHOD, IsConst, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_copy_assignment_operator, 165, MX_APPLY_METHOD, IsCopyAssignmentOperator, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_instance, 166, MX_APPLY_METHOD, IsInstance, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_lambda_static_invoker, 167, MX_APPLY_METHOD, IsLambdaStaticInvoker, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_move_assignment_operator, 168, MX_APPLY_METHOD, IsMoveAssignmentOperator, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_virtual, 169, MX_APPLY_METHOD, IsVirtual, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_volatile, 170, MX_APPLY_METHOD, IsVolatile, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXMethodDecl, overridden_methods, 57, MX_APPLY_METHOD, OverriddenMethods, CXXMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXMethodDecl, parameter_declarations, 171, MX_APPLY_METHOD, ParameterDeclarations, ParmVarDecl, NthDecl)
  MX_EXIT_VISIT_CXXMethodDecl
MX_END_VISIT_DECL(CXXMethodDecl)

#ifndef MX_ENTER_VISIT_CXXDestructorDecl
#  define MX_ENTER_VISIT_CXXDestructorDecl MX_ENTER_VISIT_CXXMethodDecl
#endif
#ifndef MX_EXIT_VISIT_CXXDestructorDecl
#  define MX_EXIT_VISIT_CXXDestructorDecl MX_EXIT_VISIT_CXXMethodDecl
#endif

MX_BEGIN_VISIT_DECL(CXXDestructorDecl)
  MX_ENTER_VISIT_CXXDestructorDecl
  MX_VISIT_BASE(CXXDestructorDecl, CXXMethodDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXDestructorDecl, operator_delete, 172, MX_APPLY_METHOD, OperatorDelete, FunctionDecl, NthDecl, DeclUseSelector::OPERATOR_DELETE)
  MX_VISIT_OPTIONAL_ENTITY(CXXDestructorDecl, operator_delete_this_argument, 174, MX_APPLY_METHOD, OperatorDeleteThisArgument, Expr, NthDecl, StmtUseSelector::OPERATOR_DELETE_THIS_ARGUMENT)
  MX_EXIT_VISIT_CXXDestructorDecl
MX_END_VISIT_DECL(CXXDestructorDecl)

#ifndef MX_ENTER_VISIT_CXXConversionDecl
#  define MX_ENTER_VISIT_CXXConversionDecl MX_ENTER_VISIT_CXXMethodDecl
#endif
#ifndef MX_EXIT_VISIT_CXXConversionDecl
#  define MX_EXIT_VISIT_CXXConversionDecl MX_EXIT_VISIT_CXXMethodDecl
#endif

MX_BEGIN_VISIT_DECL(CXXConversionDecl)
  MX_ENTER_VISIT_CXXConversionDecl
  MX_VISIT_BASE(CXXConversionDecl, CXXMethodDecl)
  MX_VISIT_ENTITY(CXXConversionDecl, conversion_type, 172, MX_APPLY_METHOD, ConversionType, Type, NthDecl, TypeUseSelector::CONVERSION_TYPE)
  MX_VISIT_BOOL(CXXConversionDecl, is_explicit, 173, MX_APPLY_METHOD, IsExplicit, bool, NthDecl)
  MX_VISIT_BOOL(CXXConversionDecl, is_lambda_to_block_pointer_conversion, 175, MX_APPLY_METHOD, IsLambdaToBlockPointerConversion, bool, NthDecl)
  MX_EXIT_VISIT_CXXConversionDecl
MX_END_VISIT_DECL(CXXConversionDecl)

#ifndef MX_ENTER_VISIT_CXXConstructorDecl
#  define MX_ENTER_VISIT_CXXConstructorDecl MX_ENTER_VISIT_CXXMethodDecl
#endif
#ifndef MX_EXIT_VISIT_CXXConstructorDecl
#  define MX_EXIT_VISIT_CXXConstructorDecl MX_EXIT_VISIT_CXXMethodDecl
#endif

MX_BEGIN_VISIT_DECL(CXXConstructorDecl)
  MX_ENTER_VISIT_CXXConstructorDecl
  MX_VISIT_BASE(CXXConstructorDecl, CXXMethodDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXConstructorDecl, target_constructor, 172, MX_APPLY_METHOD, TargetConstructor, CXXConstructorDecl, NthDecl, DeclUseSelector::TARGET_CONSTRUCTOR)
  MX_VISIT_BOOL(CXXConstructorDecl, is_default_constructor, 175, MX_APPLY_METHOD, IsDefaultConstructor, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_delegating_constructor, 176, MX_APPLY_METHOD, IsDelegatingConstructor, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_explicit, 177, MX_APPLY_METHOD, IsExplicit, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_inheriting_constructor, 178, MX_APPLY_METHOD, IsInheritingConstructor, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_specialization_copying_object, 179, MX_APPLY_METHOD, IsSpecializationCopyingObject, bool, NthDecl)
  MX_EXIT_VISIT_CXXConstructorDecl
MX_END_VISIT_DECL(CXXConstructorDecl)

#ifndef MX_ENTER_VISIT_CXXDeductionGuideDecl
#  define MX_ENTER_VISIT_CXXDeductionGuideDecl MX_ENTER_VISIT_FunctionDecl
#endif
#ifndef MX_EXIT_VISIT_CXXDeductionGuideDecl
#  define MX_EXIT_VISIT_CXXDeductionGuideDecl MX_EXIT_VISIT_FunctionDecl
#endif

MX_BEGIN_VISIT_DECL(CXXDeductionGuideDecl)
  MX_ENTER_VISIT_CXXDeductionGuideDecl
  MX_VISIT_BASE(CXXDeductionGuideDecl, FunctionDecl)
  MX_VISIT_ENTITY(CXXDeductionGuideDecl, corresponding_constructor, 159, MX_APPLY_METHOD, CorrespondingConstructor, CXXConstructorDecl, NthDecl, DeclUseSelector::CORRESPONDING_CONSTRUCTOR)
  MX_VISIT_BOOL(CXXDeductionGuideDecl, is_copy_deduction_candidate, 160, MX_APPLY_METHOD, IsCopyDeductionCandidate, bool, NthDecl)
  MX_VISIT_BOOL(CXXDeductionGuideDecl, is_explicit, 162, MX_APPLY_METHOD, IsExplicit, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXDeductionGuideDecl, parameter_declarations, 57, MX_APPLY_METHOD, ParameterDeclarations, ParmVarDecl, NthDecl)
  MX_EXIT_VISIT_CXXDeductionGuideDecl
MX_END_VISIT_DECL(CXXDeductionGuideDecl)

#ifndef MX_ENTER_VISIT_FieldDecl
#  define MX_ENTER_VISIT_FieldDecl MX_ENTER_VISIT_DeclaratorDecl
#endif
#ifndef MX_EXIT_VISIT_FieldDecl
#  define MX_EXIT_VISIT_FieldDecl MX_EXIT_VISIT_DeclaratorDecl
#endif

MX_BEGIN_VISIT_DECL(FieldDecl)
  MX_ENTER_VISIT_FieldDecl
  MX_VISIT_BASE(FieldDecl, DeclaratorDecl)
  MX_VISIT_OPTIONAL_ENTITY(FieldDecl, bit_width, 71, MX_APPLY_METHOD, BitWidth, Expr, NthDecl, StmtUseSelector::BIT_WIDTH)
  MX_VISIT_OPTIONAL_ENTITY(FieldDecl, captured_vla_type, 74, MX_APPLY_METHOD, CapturedVLAType, VariableArrayType, NthDecl, TypeUseSelector::CAPTURED_VLA_TYPE)
  MX_VISIT_ENUM(FieldDecl, in_class_initializer_style, 72, MX_APPLY_METHOD, InClassInitializerStyle, InClassInitStyle, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FieldDecl, in_class_initializer, 76, MX_APPLY_METHOD, InClassInitializer, Expr, NthDecl, StmtUseSelector::IN_CLASS_INITIALIZER)
  MX_VISIT_BOOL(FieldDecl, has_captured_vla_type, 79, MX_APPLY_METHOD, HasCapturedVLAType, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, has_in_class_initializer, 87, MX_APPLY_METHOD, HasInClassInitializer, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_anonymous_struct_or_union, 90, MX_APPLY_METHOD, IsAnonymousStructOrUnion, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_bit_field, 91, MX_APPLY_METHOD, IsBitField, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_mutable, 92, MX_APPLY_METHOD, IsMutable, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_unnamed_bitfield, 93, MX_APPLY_METHOD, IsUnnamedBitfield, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_zero_length_bit_field, 94, MX_APPLY_METHOD, IsZeroLengthBitField, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_zero_size, 95, MX_APPLY_METHOD, IsZeroSize, bool, NthDecl)
  MX_EXIT_VISIT_FieldDecl
MX_END_VISIT_DECL(FieldDecl)

#ifndef MX_ENTER_VISIT_ObjCIvarDecl
#  define MX_ENTER_VISIT_ObjCIvarDecl MX_ENTER_VISIT_FieldDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCIvarDecl
#  define MX_EXIT_VISIT_ObjCIvarDecl MX_EXIT_VISIT_FieldDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCIvarDecl)
  MX_ENTER_VISIT_ObjCIvarDecl
  MX_VISIT_BASE(ObjCIvarDecl, FieldDecl)
  MX_VISIT_ENUM(ObjCIvarDecl, access_control, 80, MX_APPLY_METHOD, AccessControl, ObjCIvarDeclAccessControl, NthDecl)
  MX_VISIT_ENUM(ObjCIvarDecl, canonical_access_control, 82, MX_APPLY_METHOD, CanonicalAccessControl, ObjCIvarDeclAccessControl, NthDecl)
  MX_VISIT_ENTITY(ObjCIvarDecl, containing_interface, 78, MX_APPLY_METHOD, ContainingInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CONTAINING_INTERFACE)
  MX_VISIT_ENTITY(ObjCIvarDecl, next_instance_variable, 81, MX_APPLY_METHOD, NextInstanceVariable, ObjCIvarDecl, NthDecl, DeclUseSelector::NEXT_INSTANCE_VARIABLE)
  MX_VISIT_BOOL(ObjCIvarDecl, synthesize, 96, MX_APPLY_METHOD, Synthesize, bool, NthDecl)
  MX_EXIT_VISIT_ObjCIvarDecl
MX_END_VISIT_DECL(ObjCIvarDecl)

#ifndef MX_ENTER_VISIT_ObjCAtDefsFieldDecl
#  define MX_ENTER_VISIT_ObjCAtDefsFieldDecl MX_ENTER_VISIT_FieldDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCAtDefsFieldDecl
#  define MX_EXIT_VISIT_ObjCAtDefsFieldDecl MX_EXIT_VISIT_FieldDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCAtDefsFieldDecl)
  MX_ENTER_VISIT_ObjCAtDefsFieldDecl
  MX_VISIT_BASE(ObjCAtDefsFieldDecl, FieldDecl)
  MX_EXIT_VISIT_ObjCAtDefsFieldDecl
MX_END_VISIT_DECL(ObjCAtDefsFieldDecl)

#ifndef MX_ENTER_VISIT_BindingDecl
#  define MX_ENTER_VISIT_BindingDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_BindingDecl
#  define MX_EXIT_VISIT_BindingDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_DECL(BindingDecl)
  MX_ENTER_VISIT_BindingDecl
  MX_VISIT_BASE(BindingDecl, ValueDecl)
  MX_VISIT_ENTITY(BindingDecl, binding, 52, MX_APPLY_METHOD, Binding, Expr, NthDecl, StmtUseSelector::BINDING)
  MX_VISIT_ENTITY(BindingDecl, decomposed_declaration, 53, MX_APPLY_METHOD, DecomposedDeclaration, ValueDecl, NthDecl, DeclUseSelector::DECOMPOSED_DECLARATION)
  MX_VISIT_ENTITY(BindingDecl, holding_variable, 61, MX_APPLY_METHOD, HoldingVariable, VarDecl, NthDecl, DeclUseSelector::HOLDING_VARIABLE)
  MX_EXIT_VISIT_BindingDecl
MX_END_VISIT_DECL(BindingDecl)

#ifndef MX_ENTER_VISIT_OMPDeclarativeDirectiveValueDecl
#  define MX_ENTER_VISIT_OMPDeclarativeDirectiveValueDecl MX_ENTER_VISIT_ValueDecl
#endif
#ifndef MX_EXIT_VISIT_OMPDeclarativeDirectiveValueDecl
#  define MX_EXIT_VISIT_OMPDeclarativeDirectiveValueDecl MX_EXIT_VISIT_ValueDecl
#endif

MX_BEGIN_VISIT_ABSTRACT_DECL(OMPDeclarativeDirectiveValueDecl)
  MX_ENTER_VISIT_OMPDeclarativeDirectiveValueDecl
  MX_VISIT_BASE(OMPDeclarativeDirectiveValueDecl, ValueDecl)
  MX_EXIT_VISIT_OMPDeclarativeDirectiveValueDecl
MX_END_VISIT_DECL(OMPDeclarativeDirectiveValueDecl)

#ifndef MX_ENTER_VISIT_OMPDeclareMapperDecl
#  define MX_ENTER_VISIT_OMPDeclareMapperDecl MX_ENTER_VISIT_OMPDeclarativeDirectiveValueDecl
#endif
#ifndef MX_EXIT_VISIT_OMPDeclareMapperDecl
#  define MX_EXIT_VISIT_OMPDeclareMapperDecl MX_EXIT_VISIT_OMPDeclarativeDirectiveValueDecl
#endif

MX_BEGIN_VISIT_DECL(OMPDeclareMapperDecl)
  MX_ENTER_VISIT_OMPDeclareMapperDecl
  MX_VISIT_BASE(OMPDeclareMapperDecl, OMPDeclarativeDirectiveValueDecl)
  MX_VISIT_ENTITY(OMPDeclareMapperDecl, mapper_variable_reference, 52, MX_APPLY_METHOD, MapperVariableReference, Expr, NthDecl, StmtUseSelector::MAPPER_VARIABLE_REFERENCE)
  MX_VISIT_DECL_CONTEXT(OMPDeclareMapperDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_OMPDeclareMapperDecl
MX_END_VISIT_DECL(OMPDeclareMapperDecl)

#ifndef MX_ENTER_VISIT_UsingShadowDecl
#  define MX_ENTER_VISIT_UsingShadowDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_UsingShadowDecl
#  define MX_EXIT_VISIT_UsingShadowDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(UsingShadowDecl)
  MX_ENTER_VISIT_UsingShadowDecl
  MX_VISIT_BASE(UsingShadowDecl, NamedDecl)
  MX_VISIT_ENTITY(UsingShadowDecl, introducer, 51, MX_APPLY_METHOD, Introducer, BaseUsingDecl, NthDecl, DeclUseSelector::INTRODUCER)
  MX_VISIT_OPTIONAL_ENTITY(UsingShadowDecl, next_using_shadow_declaration, 52, MX_APPLY_METHOD, NextUsingShadowDeclaration, UsingShadowDecl, NthDecl, DeclUseSelector::NEXT_USING_SHADOW_DECLARATION)
  MX_VISIT_ENTITY(UsingShadowDecl, target_declaration, 53, MX_APPLY_METHOD, TargetDeclaration, NamedDecl, NthDecl, DeclUseSelector::TARGET_DECLARATION)
  MX_EXIT_VISIT_UsingShadowDecl
MX_END_VISIT_DECL(UsingShadowDecl)

#ifndef MX_ENTER_VISIT_ConstructorUsingShadowDecl
#  define MX_ENTER_VISIT_ConstructorUsingShadowDecl MX_ENTER_VISIT_UsingShadowDecl
#endif
#ifndef MX_EXIT_VISIT_ConstructorUsingShadowDecl
#  define MX_EXIT_VISIT_ConstructorUsingShadowDecl MX_EXIT_VISIT_UsingShadowDecl
#endif

MX_BEGIN_VISIT_DECL(ConstructorUsingShadowDecl)
  MX_ENTER_VISIT_ConstructorUsingShadowDecl
  MX_VISIT_BASE(ConstructorUsingShadowDecl, UsingShadowDecl)
  MX_VISIT_BOOL(ConstructorUsingShadowDecl, constructs_virtual_base, 69, MX_APPLY_METHOD, ConstructsVirtualBase, bool, NthDecl)
  MX_VISIT_ENTITY(ConstructorUsingShadowDecl, constructed_base_class, 61, MX_APPLY_METHOD, ConstructedBaseClass, CXXRecordDecl, NthDecl, DeclUseSelector::CONSTRUCTED_BASE_CLASS)
  MX_VISIT_OPTIONAL_ENTITY(ConstructorUsingShadowDecl, constructed_base_class_shadow_declaration, 62, MX_APPLY_METHOD, ConstructedBaseClassShadowDeclaration, ConstructorUsingShadowDecl, NthDecl, DeclUseSelector::CONSTRUCTED_BASE_CLASS_SHADOW_DECLARATION)
  MX_VISIT_ENTITY(ConstructorUsingShadowDecl, nominated_base_class, 63, MX_APPLY_METHOD, NominatedBaseClass, CXXRecordDecl, NthDecl, DeclUseSelector::NOMINATED_BASE_CLASS)
  MX_VISIT_OPTIONAL_ENTITY(ConstructorUsingShadowDecl, nominated_base_class_shadow_declaration, 71, MX_APPLY_METHOD, NominatedBaseClassShadowDeclaration, ConstructorUsingShadowDecl, NthDecl, DeclUseSelector::NOMINATED_BASE_CLASS_SHADOW_DECLARATION)
  MX_EXIT_VISIT_ConstructorUsingShadowDecl
MX_END_VISIT_DECL(ConstructorUsingShadowDecl)

#ifndef MX_ENTER_VISIT_UsingPackDecl
#  define MX_ENTER_VISIT_UsingPackDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_UsingPackDecl
#  define MX_EXIT_VISIT_UsingPackDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(UsingPackDecl)
  MX_ENTER_VISIT_UsingPackDecl
  MX_VISIT_BASE(UsingPackDecl, NamedDecl)
  MX_VISIT_ENTITY_LIST(UsingPackDecl, expansions, 45, MX_APPLY_METHOD, Expansions, NamedDecl, NthDecl)
  MX_VISIT_ENTITY(UsingPackDecl, instantiated_from_using_declaration, 51, MX_APPLY_METHOD, InstantiatedFromUsingDeclaration, NamedDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_USING_DECLARATION)
  MX_EXIT_VISIT_UsingPackDecl
MX_END_VISIT_DECL(UsingPackDecl)

#ifndef MX_ENTER_VISIT_UsingDirectiveDecl
#  define MX_ENTER_VISIT_UsingDirectiveDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_UsingDirectiveDecl
#  define MX_EXIT_VISIT_UsingDirectiveDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(UsingDirectiveDecl)
  MX_ENTER_VISIT_UsingDirectiveDecl
  MX_VISIT_BASE(UsingDirectiveDecl, NamedDecl)
  MX_VISIT_ENTITY(UsingDirectiveDecl, identifier_token, 51, MX_APPLY_METHOD, IdentifierToken, Token, NthDecl, TokenUseSelector::IDENTIFIER_TOKEN)
  MX_VISIT_ENTITY(UsingDirectiveDecl, namespace_key_token, 52, MX_APPLY_METHOD, NamespaceKeyToken, Token, NthDecl, TokenUseSelector::NAMESPACE_KEY_TOKEN)
  MX_VISIT_ENTITY(UsingDirectiveDecl, nominated_namespace_as_written, 53, MX_APPLY_METHOD, NominatedNamespaceAsWritten, NamedDecl, NthDecl, DeclUseSelector::NOMINATED_NAMESPACE_AS_WRITTEN)
  MX_VISIT_ENTITY(UsingDirectiveDecl, using_token, 61, MX_APPLY_METHOD, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_EXIT_VISIT_UsingDirectiveDecl
MX_END_VISIT_DECL(UsingDirectiveDecl)

#ifndef MX_ENTER_VISIT_UnresolvedUsingIfExistsDecl
#  define MX_ENTER_VISIT_UnresolvedUsingIfExistsDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_UnresolvedUsingIfExistsDecl
#  define MX_EXIT_VISIT_UnresolvedUsingIfExistsDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(UnresolvedUsingIfExistsDecl)
  MX_ENTER_VISIT_UnresolvedUsingIfExistsDecl
  MX_VISIT_BASE(UnresolvedUsingIfExistsDecl, NamedDecl)
  MX_EXIT_VISIT_UnresolvedUsingIfExistsDecl
MX_END_VISIT_DECL(UnresolvedUsingIfExistsDecl)

#ifndef MX_ENTER_VISIT_TypeDecl
#  define MX_ENTER_VISIT_TypeDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_TypeDecl
#  define MX_EXIT_VISIT_TypeDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(TypeDecl)
  MX_ENTER_VISIT_TypeDecl
  MX_VISIT_BASE(TypeDecl, NamedDecl)
  MX_VISIT_OPTIONAL_ENTITY(TypeDecl, type_for_declaration, 51, MX_APPLY_METHOD, TypeForDeclaration, Type, NthDecl, TypeUseSelector::TYPE_FOR_DECLARATION)
  MX_EXIT_VISIT_TypeDecl
MX_END_VISIT_DECL(TypeDecl)

#ifndef MX_ENTER_VISIT_TemplateTypeParmDecl
#  define MX_ENTER_VISIT_TemplateTypeParmDecl MX_ENTER_VISIT_TypeDecl
#endif
#ifndef MX_EXIT_VISIT_TemplateTypeParmDecl
#  define MX_EXIT_VISIT_TemplateTypeParmDecl MX_EXIT_VISIT_TypeDecl
#endif

MX_BEGIN_VISIT_DECL(TemplateTypeParmDecl)
  MX_ENTER_VISIT_TemplateTypeParmDecl
  MX_VISIT_BASE(TemplateTypeParmDecl, TypeDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, default_argument_was_inherited, 69, MX_APPLY_METHOD, DefaultArgumentWasInherited, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(TemplateTypeParmDecl, default_argument, 52, MX_APPLY_METHOD, DefaultArgument, Type, NthDecl, TypeUseSelector::DEFAULT_ARGUMENT)
  MX_VISIT_OPTIONAL_ENTITY(TemplateTypeParmDecl, default_argument_info, 53, MX_APPLY_METHOD, DefaultArgumentInfo, Type, NthDecl, TypeUseSelector::DEFAULT_ARGUMENT_INFO)
  MX_VISIT_ENTITY(TemplateTypeParmDecl, default_argument_token, 61, MX_APPLY_METHOD, DefaultArgumentToken, Token, NthDecl, TokenUseSelector::DEFAULT_ARGUMENT_TOKEN)
  MX_VISIT_BOOL(TemplateTypeParmDecl, has_default_argument, 77, MX_APPLY_METHOD, HasDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, has_type_constraint, 79, MX_APPLY_METHOD, HasTypeConstraint, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, is_expanded_parameter_pack, 87, MX_APPLY_METHOD, IsExpandedParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, is_pack_expansion, 90, MX_APPLY_METHOD, IsPackExpansion, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, was_declared_with_typename, 91, MX_APPLY_METHOD, WasDeclaredWithTypename, bool, NthDecl)
  MX_EXIT_VISIT_TemplateTypeParmDecl
MX_END_VISIT_DECL(TemplateTypeParmDecl)

#ifndef MX_ENTER_VISIT_TagDecl
#  define MX_ENTER_VISIT_TagDecl MX_ENTER_VISIT_TypeDecl
#endif
#ifndef MX_EXIT_VISIT_TagDecl
#  define MX_EXIT_VISIT_TagDecl MX_EXIT_VISIT_TypeDecl
#endif

MX_BEGIN_VISIT_DECL(TagDecl)
  MX_ENTER_VISIT_TagDecl
  MX_VISIT_BASE(TagDecl, TypeDecl)
  MX_VISIT_ENTITY(TagDecl, first_inner_token, 61, MX_APPLY_METHOD, FirstInnerToken, Token, NthDecl, TokenUseSelector::FIRST_INNER_TOKEN)
  MX_VISIT_ENTITY(TagDecl, first_outer_token, 62, MX_APPLY_METHOD, FirstOuterToken, Token, NthDecl, TokenUseSelector::FIRST_OUTER_TOKEN)
  MX_VISIT_ENUM(TagDecl, tag_kind, 72, MX_APPLY_METHOD, TagKind, TagTypeKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(TagDecl, typedef_name_for_anonymous_declaration, 63, MX_APPLY_METHOD, TypedefNameForAnonymousDeclaration, TypedefNameDecl, NthDecl, DeclUseSelector::TYPEDEF_NAME_FOR_ANONYMOUS_DECLARATION)
  MX_VISIT_BOOL(TagDecl, has_name_for_linkage, 70, MX_APPLY_METHOD, HasNameForLinkage, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_being_defined, 75, MX_APPLY_METHOD, IsBeingDefined, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_class, 77, MX_APPLY_METHOD, IsClass, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_complete_definition, 79, MX_APPLY_METHOD, IsCompleteDefinition, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_complete_definition_required, 87, MX_APPLY_METHOD, IsCompleteDefinitionRequired, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_dependent_type, 90, MX_APPLY_METHOD, IsDependentType, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_embedded_in_declarator, 91, MX_APPLY_METHOD, IsEmbeddedInDeclarator, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_enum, 92, MX_APPLY_METHOD, IsEnum, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_free_standing, 93, MX_APPLY_METHOD, IsFreeStanding, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_interface, 94, MX_APPLY_METHOD, IsInterface, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_struct, 95, MX_APPLY_METHOD, IsStruct, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_union, 96, MX_APPLY_METHOD, IsUnion, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, may_have_out_of_date_definition, 97, MX_APPLY_METHOD, MayHaveOutOfDateDefinition, bool, NthDecl)
  MX_VISIT_PSEUDO_LIST(TagDecl, template_parameter_lists, 73, MX_APPLY_METHOD, TemplateParameterLists, TemplateParameterList, NthDecl)
  MX_VISIT_DECL_CONTEXT(TagDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_TagDecl
MX_END_VISIT_DECL(TagDecl)

#ifndef MX_ENTER_VISIT_RecordDecl
#  define MX_ENTER_VISIT_RecordDecl MX_ENTER_VISIT_TagDecl
#endif
#ifndef MX_EXIT_VISIT_RecordDecl
#  define MX_EXIT_VISIT_RecordDecl MX_EXIT_VISIT_TagDecl
#endif

MX_BEGIN_VISIT_DECL(RecordDecl)
  MX_ENTER_VISIT_RecordDecl
  MX_VISIT_BASE(RecordDecl, TagDecl)
  MX_VISIT_BOOL(RecordDecl, can_pass_in_registers, 98, MX_APPLY_METHOD, CanPassInRegisters, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(RecordDecl, fields, 46, MX_APPLY_METHOD, Fields, FieldDecl, NthDecl)
  MX_VISIT_ENUM(RecordDecl, argument_passing_restrictions, 80, MX_APPLY_METHOD, ArgumentPassingRestrictions, RecordDeclArgPassingKind, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_flexible_array_member, 99, MX_APPLY_METHOD, HasFlexibleArrayMember, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_loaded_fields_from_external_storage, 100, MX_APPLY_METHOD, HasLoadedFieldsFromExternalStorage, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_non_trivial_to_primitive_copy_c_union, 101, MX_APPLY_METHOD, HasNonTrivialToPrimitiveCopyCUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_non_trivial_to_primitive_default_initialize_c_union, 102, MX_APPLY_METHOD, HasNonTrivialToPrimitiveDefaultInitializeCUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_non_trivial_to_primitive_destruct_c_union, 103, MX_APPLY_METHOD, HasNonTrivialToPrimitiveDestructCUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_object_member, 104, MX_APPLY_METHOD, HasObjectMember, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_volatile_member, 105, MX_APPLY_METHOD, HasVolatileMember, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_anonymous_struct_or_union, 106, MX_APPLY_METHOD, IsAnonymousStructOrUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_captured_record, 107, MX_APPLY_METHOD, IsCapturedRecord, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_injected_class_name, 108, MX_APPLY_METHOD, IsInjectedClassName, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_lambda, 109, MX_APPLY_METHOD, IsLambda, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_ms_struct, 110, MX_APPLY_METHOD, IsMsStruct, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_non_trivial_to_primitive_copy, 111, MX_APPLY_METHOD, IsNonTrivialToPrimitiveCopy, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_non_trivial_to_primitive_default_initialize, 112, MX_APPLY_METHOD, IsNonTrivialToPrimitiveDefaultInitialize, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_non_trivial_to_primitive_destroy, 113, MX_APPLY_METHOD, IsNonTrivialToPrimitiveDestroy, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_or_contains_union, 114, MX_APPLY_METHOD, IsOrContainsUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_parameter_destroyed_in_callee, 115, MX_APPLY_METHOD, IsParameterDestroyedInCallee, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, may_insert_extra_padding, 116, MX_APPLY_METHOD, MayInsertExtraPadding, bool, NthDecl)
  MX_EXIT_VISIT_RecordDecl
MX_END_VISIT_DECL(RecordDecl)

#ifndef MX_ENTER_VISIT_CXXRecordDecl
#  define MX_ENTER_VISIT_CXXRecordDecl MX_ENTER_VISIT_RecordDecl
#endif
#ifndef MX_EXIT_VISIT_CXXRecordDecl
#  define MX_EXIT_VISIT_CXXRecordDecl MX_EXIT_VISIT_RecordDecl
#endif

MX_BEGIN_VISIT_DECL(CXXRecordDecl)
  MX_ENTER_VISIT_CXXRecordDecl
  MX_VISIT_BASE(CXXRecordDecl, RecordDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, allow_const_default_initializer, 117, MX_APPLY_METHOD, AllowConstDefaultInitializer, bool, NthDecl)
  MX_VISIT_OPTIONAL_PSEUDO_LIST(CXXRecordDecl, bases, 141, MX_APPLY_METHOD, Bases, CXXBaseSpecifier, NthDecl)
  MX_VISIT_OPTIONAL_ENUM(CXXRecordDecl, calculate_inheritance_model, 82, MX_APPLY_METHOD, CalculateInheritanceModel, MSInheritanceModel, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXRecordDecl, constructors, 57, MX_APPLY_METHOD, Constructors, CXXConstructorDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY_LIST(CXXRecordDecl, friends, 171, MX_APPLY_METHOD, Friends, FriendDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, destructor, 71, MX_APPLY_METHOD, Destructor, CXXDestructorDecl, NthDecl, DeclUseSelector::DESTRUCTOR)
  MX_VISIT_OPTIONAL_PSEUDO(CXXRecordDecl, generic_lambda_template_parameter_list, 143, MX_APPLY_METHOD, GenericLambdaTemplateParameterList, TemplateParameterList, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, instantiated_from_member_class, 74, MX_APPLY_METHOD, InstantiatedFromMemberClass, CXXRecordDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_CLASS)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, lambda_call_operator, 76, MX_APPLY_METHOD, LambdaCallOperator, CXXMethodDecl, NthDecl, DeclUseSelector::LAMBDA_CALL_OPERATOR)
  MX_VISIT_OPTIONAL_ENUM(CXXRecordDecl, lambda_capture_default, 83, MX_APPLY_METHOD, LambdaCaptureDefault, LambdaCaptureDefault, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, lambda_context_declaration, 78, MX_APPLY_METHOD, LambdaContextDeclaration, Decl, NthDecl, DeclUseSelector::LAMBDA_CONTEXT_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY_LIST(CXXRecordDecl, lambda_explicit_template_parameters, 180, MX_APPLY_METHOD, LambdaExplicitTemplateParameters, NamedDecl, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, lambda_mangling_number, 181, MX_APPLY_METHOD, LambdaManglingNumber, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, lambda_type, 81, MX_APPLY_METHOD, LambdaType, Type, NthDecl, TypeUseSelector::LAMBDA_TYPE)
  MX_VISIT_OPTIONAL_ENUM(CXXRecordDecl, ms_inheritance_model, 84, MX_APPLY_METHOD, MSInheritanceModel, MSInheritanceModel, NthDecl)
  MX_VISIT_ENUM(CXXRecordDecl, ms_vtor_disp_mode, 85, MX_APPLY_METHOD, MSVtorDispMode, MSVtorDispMode, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, num_bases, 182, MX_APPLY_METHOD, NumBases, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, num_virtual_bases, 183, MX_APPLY_METHOD, NumVirtualBases, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, odr_hash, 184, MX_APPLY_METHOD, ODRHash, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, template_instantiation_pattern, 86, MX_APPLY_METHOD, TemplateInstantiationPattern, CXXRecordDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(CXXRecordDecl, template_specialization_kind, 88, MX_APPLY_METHOD, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_any_dependent_bases, 148, MX_APPLY_METHOD, HasAnyDependentBases, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_default_constructor, 150, MX_APPLY_METHOD, HasConstexprDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_destructor, 152, MX_APPLY_METHOD, HasConstexprDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_non_copy_move_constructor, 154, MX_APPLY_METHOD, HasConstexprNonCopyMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_copy_assignment_with_const_parameter, 156, MX_APPLY_METHOD, HasCopyAssignmentWithConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_copy_constructor_with_const_parameter, 160, MX_APPLY_METHOD, HasCopyConstructorWithConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_default_constructor, 163, MX_APPLY_METHOD, HasDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_definition, 165, MX_APPLY_METHOD, HasDefinition, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_direct_fields, 167, MX_APPLY_METHOD, HasDirectFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_friends, 169, MX_APPLY_METHOD, HasFriends, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_in_class_initializer, 173, MX_APPLY_METHOD, HasInClassInitializer, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_inherited_assignment, 176, MX_APPLY_METHOD, HasInheritedAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_inherited_constructor, 178, MX_APPLY_METHOD, HasInheritedConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_initializer_method, 185, MX_APPLY_METHOD, HasInitializerMethod, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_irrelevant_destructor, 187, MX_APPLY_METHOD, HasIrrelevantDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_known_lambda_internal_linkage, 189, MX_APPLY_METHOD, HasKnownLambdaInternalLinkage, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_move_assignment, 191, MX_APPLY_METHOD, HasMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_move_constructor, 193, MX_APPLY_METHOD, HasMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_mutable_fields, 195, MX_APPLY_METHOD, HasMutableFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_literal_type_fields_or_bases, 197, MX_APPLY_METHOD, HasNonLiteralTypeFieldsOrBases, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_assignment, 199, MX_APPLY_METHOD, HasNonTrivialCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_constructor, 201, MX_APPLY_METHOD, HasNonTrivialCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_constructor_for_call, 203, MX_APPLY_METHOD, HasNonTrivialCopyConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_default_constructor, 205, MX_APPLY_METHOD, HasNonTrivialDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_destructor, 207, MX_APPLY_METHOD, HasNonTrivialDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_destructor_for_call, 209, MX_APPLY_METHOD, HasNonTrivialDestructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_assignment, 211, MX_APPLY_METHOD, HasNonTrivialMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_constructor, 213, MX_APPLY_METHOD, HasNonTrivialMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_constructor_for_call, 215, MX_APPLY_METHOD, HasNonTrivialMoveConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_private_fields, 217, MX_APPLY_METHOD, HasPrivateFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_protected_fields, 219, MX_APPLY_METHOD, HasProtectedFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_copy_assignment, 221, MX_APPLY_METHOD, HasSimpleCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_copy_constructor, 223, MX_APPLY_METHOD, HasSimpleCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_destructor, 225, MX_APPLY_METHOD, HasSimpleDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_move_assignment, 227, MX_APPLY_METHOD, HasSimpleMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_move_constructor, 229, MX_APPLY_METHOD, HasSimpleMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_assignment, 231, MX_APPLY_METHOD, HasTrivialCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_constructor, 233, MX_APPLY_METHOD, HasTrivialCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_constructor_for_call, 235, MX_APPLY_METHOD, HasTrivialCopyConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_default_constructor, 237, MX_APPLY_METHOD, HasTrivialDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_destructor, 239, MX_APPLY_METHOD, HasTrivialDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_destructor_for_call, 241, MX_APPLY_METHOD, HasTrivialDestructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_assignment, 243, MX_APPLY_METHOD, HasTrivialMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_constructor, 245, MX_APPLY_METHOD, HasTrivialMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_constructor_for_call, 247, MX_APPLY_METHOD, HasTrivialMoveConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_uninitialized_reference_member, 249, MX_APPLY_METHOD, HasUninitializedReferenceMember, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_constructor, 251, MX_APPLY_METHOD, HasUserDeclaredConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_copy_assignment, 253, MX_APPLY_METHOD, HasUserDeclaredCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_copy_constructor, 255, MX_APPLY_METHOD, HasUserDeclaredCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_destructor, 257, MX_APPLY_METHOD, HasUserDeclaredDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_assignment, 259, MX_APPLY_METHOD, HasUserDeclaredMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_constructor, 261, MX_APPLY_METHOD, HasUserDeclaredMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_operation, 263, MX_APPLY_METHOD, HasUserDeclaredMoveOperation, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_provided_default_constructor, 265, MX_APPLY_METHOD, HasUserProvidedDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_variant_members, 267, MX_APPLY_METHOD, HasVariantMembers, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, implicit_copy_assignment_has_const_parameter, 269, MX_APPLY_METHOD, ImplicitCopyAssignmentHasConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, implicit_copy_constructor_has_const_parameter, 271, MX_APPLY_METHOD, ImplicitCopyConstructorHasConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_abstract, 273, MX_APPLY_METHOD, IsAbstract, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_aggregate, 275, MX_APPLY_METHOD, IsAggregate, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_any_destructor_no_return, 277, MX_APPLY_METHOD, IsAnyDestructorNoReturn, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_c_like, 279, MX_APPLY_METHOD, IsCLike, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_cxx11_standard_layout, 281, MX_APPLY_METHOD, IsCXX11StandardLayout, bool, NthDecl)
  MX_VISIT_BOOL(CXXRecordDecl, is_dependent_lambda, 283, MX_APPLY_METHOD, IsDependentLambda, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_dynamic_class, 284, MX_APPLY_METHOD, IsDynamicClass, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_effectively_final, 286, MX_APPLY_METHOD, IsEffectivelyFinal, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_empty, 288, MX_APPLY_METHOD, IsEmpty, bool, NthDecl)
  MX_VISIT_BOOL(CXXRecordDecl, is_generic_lambda, 290, MX_APPLY_METHOD, IsGenericLambda, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_interface_like, 291, MX_APPLY_METHOD, IsInterfaceLike, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_literal, 293, MX_APPLY_METHOD, IsLiteral, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, is_local_class, 126, MX_APPLY_METHOD, IsLocalClass, FunctionDecl, NthDecl, DeclUseSelector::IS_LOCAL_CLASS)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_pod, 296, MX_APPLY_METHOD, IsPOD, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_polymorphic, 298, MX_APPLY_METHOD, IsPolymorphic, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_standard_layout, 300, MX_APPLY_METHOD, IsStandardLayout, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_structural, 302, MX_APPLY_METHOD, IsStructural, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_trivial, 304, MX_APPLY_METHOD, IsTrivial, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_trivially_copyable, 306, MX_APPLY_METHOD, IsTriviallyCopyable, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, lambda_is_default_constructible_and_assignable, 308, MX_APPLY_METHOD, LambdaIsDefaultConstructibleAndAssignable, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, may_be_abstract, 310, MX_APPLY_METHOD, MayBeAbstract, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, may_be_dynamic_class, 312, MX_APPLY_METHOD, MayBeDynamicClass, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, may_be_non_dynamic_class, 314, MX_APPLY_METHOD, MayBeNonDynamicClass, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY_LIST(CXXRecordDecl, methods, 316, MX_APPLY_METHOD, Methods, CXXMethodDecl, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_copy_assignment, 318, MX_APPLY_METHOD, NeedsImplicitCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_copy_constructor, 320, MX_APPLY_METHOD, NeedsImplicitCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_default_constructor, 322, MX_APPLY_METHOD, NeedsImplicitDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_destructor, 324, MX_APPLY_METHOD, NeedsImplicitDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_move_assignment, 326, MX_APPLY_METHOD, NeedsImplicitMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_move_constructor, 328, MX_APPLY_METHOD, NeedsImplicitMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_copy_assignment, 330, MX_APPLY_METHOD, NeedsOverloadResolutionForCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_copy_constructor, 332, MX_APPLY_METHOD, NeedsOverloadResolutionForCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_destructor, 334, MX_APPLY_METHOD, NeedsOverloadResolutionForDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_move_assignment, 336, MX_APPLY_METHOD, NeedsOverloadResolutionForMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_move_constructor, 338, MX_APPLY_METHOD, NeedsOverloadResolutionForMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, null_field_offset_is_zero, 340, MX_APPLY_METHOD, NullFieldOffsetIsZero, bool, NthDecl)
  MX_VISIT_OPTIONAL_PSEUDO_LIST(CXXRecordDecl, virtual_bases, 142, MX_APPLY_METHOD, VirtualBases, CXXBaseSpecifier, NthDecl)
  MX_EXIT_VISIT_CXXRecordDecl
MX_END_VISIT_DECL(CXXRecordDecl)

#ifndef MX_ENTER_VISIT_ClassTemplateSpecializationDecl
#  define MX_ENTER_VISIT_ClassTemplateSpecializationDecl MX_ENTER_VISIT_CXXRecordDecl
#endif
#ifndef MX_EXIT_VISIT_ClassTemplateSpecializationDecl
#  define MX_EXIT_VISIT_ClassTemplateSpecializationDecl MX_EXIT_VISIT_CXXRecordDecl
#endif

MX_BEGIN_VISIT_DECL(ClassTemplateSpecializationDecl)
  MX_ENTER_VISIT_ClassTemplateSpecializationDecl
  MX_VISIT_BASE(ClassTemplateSpecializationDecl, CXXRecordDecl)
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, extern_token, 128, MX_APPLY_METHOD, ExternToken, Token, NthDecl, TokenUseSelector::EXTERN_TOKEN)
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, point_of_instantiation, 129, MX_APPLY_METHOD, PointOfInstantiation, Token, NthDecl, TokenUseSelector::POINT_OF_INSTANTIATION)
  MX_VISIT_ENUM(ClassTemplateSpecializationDecl, specialization_kind, 89, MX_APPLY_METHOD, SpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_PSEUDO_LIST(ClassTemplateSpecializationDecl, template_arguments, 343, MX_APPLY_METHOD, TemplateArguments, TemplateArgument, NthDecl)
  MX_VISIT_PSEUDO_LIST(ClassTemplateSpecializationDecl, template_instantiation_arguments, 344, MX_APPLY_METHOD, TemplateInstantiationArguments, TemplateArgument, NthDecl)
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, template_keyword_token, 131, MX_APPLY_METHOD, TemplateKeywordToken, Token, NthDecl, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(ClassTemplateSpecializationDecl, type_as_written, 132, MX_APPLY_METHOD, TypeAsWritten, Type, NthDecl, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(ClassTemplateSpecializationDecl, is_class_scope_explicit_specialization, 346, MX_APPLY_METHOD, IsClassScopeExplicitSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(ClassTemplateSpecializationDecl, is_explicit_instantiation_or_specialization, 347, MX_APPLY_METHOD, IsExplicitInstantiationOrSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(ClassTemplateSpecializationDecl, is_explicit_specialization, 348, MX_APPLY_METHOD, IsExplicitSpecialization, bool, NthDecl)
  MX_EXIT_VISIT_ClassTemplateSpecializationDecl
MX_END_VISIT_DECL(ClassTemplateSpecializationDecl)

#ifndef MX_ENTER_VISIT_ClassTemplatePartialSpecializationDecl
#  define MX_ENTER_VISIT_ClassTemplatePartialSpecializationDecl MX_ENTER_VISIT_ClassTemplateSpecializationDecl
#endif
#ifndef MX_EXIT_VISIT_ClassTemplatePartialSpecializationDecl
#  define MX_EXIT_VISIT_ClassTemplatePartialSpecializationDecl MX_EXIT_VISIT_ClassTemplateSpecializationDecl
#endif

MX_BEGIN_VISIT_DECL(ClassTemplatePartialSpecializationDecl)
  MX_ENTER_VISIT_ClassTemplatePartialSpecializationDecl
  MX_EXIT_VISIT_ClassTemplatePartialSpecializationDecl
MX_END_VISIT_DECL(ClassTemplatePartialSpecializationDecl)

#ifndef MX_ENTER_VISIT_EnumDecl
#  define MX_ENTER_VISIT_EnumDecl MX_ENTER_VISIT_TagDecl
#endif
#ifndef MX_EXIT_VISIT_EnumDecl
#  define MX_EXIT_VISIT_EnumDecl MX_EXIT_VISIT_TagDecl
#endif

MX_BEGIN_VISIT_DECL(EnumDecl)
  MX_ENTER_VISIT_EnumDecl
  MX_VISIT_BASE(EnumDecl, TagDecl)
  MX_VISIT_ENTITY_LIST(EnumDecl, enumerators, 46, MX_APPLY_METHOD, Enumerators, EnumConstantDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(EnumDecl, instantiated_from_member_enum, 71, MX_APPLY_METHOD, InstantiatedFromMemberEnum, EnumDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_ENUM)
  MX_VISIT_OPTIONAL_ENTITY(EnumDecl, integer_type, 74, MX_APPLY_METHOD, IntegerType, Type, NthDecl, TypeUseSelector::INTEGER_TYPE)
  MX_VISIT_OPTIONAL_INT(EnumDecl, odr_hash, 143, MX_APPLY_METHOD, ODRHash, unsigned, NthDecl)
  MX_VISIT_ENTITY(EnumDecl, promotion_type, 81, MX_APPLY_METHOD, PromotionType, Type, NthDecl, TypeUseSelector::PROMOTION_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(EnumDecl, template_instantiation_pattern, 86, MX_APPLY_METHOD, TemplateInstantiationPattern, EnumDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(EnumDecl, template_specialization_kind, 80, MX_APPLY_METHOD, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_closed, 102, MX_APPLY_METHOD, IsClosed, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_closed_flag, 103, MX_APPLY_METHOD, IsClosedFlag, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_closed_non_flag, 104, MX_APPLY_METHOD, IsClosedNonFlag, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_complete, 105, MX_APPLY_METHOD, IsComplete, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_fixed, 106, MX_APPLY_METHOD, IsFixed, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_scoped, 107, MX_APPLY_METHOD, IsScoped, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_scoped_using_class_tag, 108, MX_APPLY_METHOD, IsScopedUsingClassTag, bool, NthDecl)
  MX_EXIT_VISIT_EnumDecl
MX_END_VISIT_DECL(EnumDecl)

#ifndef MX_ENTER_VISIT_UnresolvedUsingTypenameDecl
#  define MX_ENTER_VISIT_UnresolvedUsingTypenameDecl MX_ENTER_VISIT_TypeDecl
#endif
#ifndef MX_EXIT_VISIT_UnresolvedUsingTypenameDecl
#  define MX_EXIT_VISIT_UnresolvedUsingTypenameDecl MX_EXIT_VISIT_TypeDecl
#endif

MX_BEGIN_VISIT_DECL(UnresolvedUsingTypenameDecl)
  MX_ENTER_VISIT_UnresolvedUsingTypenameDecl
  MX_VISIT_BASE(UnresolvedUsingTypenameDecl, TypeDecl)
  MX_VISIT_ENTITY(UnresolvedUsingTypenameDecl, ellipsis_token, 52, MX_APPLY_METHOD, EllipsisToken, Token, NthDecl, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(UnresolvedUsingTypenameDecl, typename_token, 53, MX_APPLY_METHOD, TypenameToken, Token, NthDecl, TokenUseSelector::TYPENAME_TOKEN)
  MX_VISIT_ENTITY(UnresolvedUsingTypenameDecl, using_token, 61, MX_APPLY_METHOD, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_VISIT_BOOL(UnresolvedUsingTypenameDecl, is_pack_expansion, 69, MX_APPLY_METHOD, IsPackExpansion, bool, NthDecl)
  MX_EXIT_VISIT_UnresolvedUsingTypenameDecl
MX_END_VISIT_DECL(UnresolvedUsingTypenameDecl)

#ifndef MX_ENTER_VISIT_TypedefNameDecl
#  define MX_ENTER_VISIT_TypedefNameDecl MX_ENTER_VISIT_TypeDecl
#endif
#ifndef MX_EXIT_VISIT_TypedefNameDecl
#  define MX_EXIT_VISIT_TypedefNameDecl MX_EXIT_VISIT_TypeDecl
#endif

MX_BEGIN_VISIT_DECL(TypedefNameDecl)
  MX_ENTER_VISIT_TypedefNameDecl
  MX_VISIT_BASE(TypedefNameDecl, TypeDecl)
  MX_VISIT_OPTIONAL_ENTITY(TypedefNameDecl, anonymous_declaration_with_typedef_name, 52, MX_APPLY_METHOD, AnonymousDeclarationWithTypedefName, TagDecl, NthDecl, DeclUseSelector::ANONYMOUS_DECLARATION_WITH_TYPEDEF_NAME)
  MX_VISIT_ENTITY(TypedefNameDecl, underlying_type, 53, MX_APPLY_METHOD, UnderlyingType, Type, NthDecl, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(TypedefNameDecl, is_moded, 70, MX_APPLY_METHOD, IsModed, bool, NthDecl)
  MX_VISIT_BOOL(TypedefNameDecl, is_transparent_tag, 75, MX_APPLY_METHOD, IsTransparentTag, bool, NthDecl)
  MX_EXIT_VISIT_TypedefNameDecl
MX_END_VISIT_DECL(TypedefNameDecl)

#ifndef MX_ENTER_VISIT_TypedefDecl
#  define MX_ENTER_VISIT_TypedefDecl MX_ENTER_VISIT_TypedefNameDecl
#endif
#ifndef MX_EXIT_VISIT_TypedefDecl
#  define MX_EXIT_VISIT_TypedefDecl MX_EXIT_VISIT_TypedefNameDecl
#endif

MX_BEGIN_VISIT_DECL(TypedefDecl)
  MX_ENTER_VISIT_TypedefDecl
  MX_VISIT_BASE(TypedefDecl, TypedefNameDecl)
  MX_EXIT_VISIT_TypedefDecl
MX_END_VISIT_DECL(TypedefDecl)

#ifndef MX_ENTER_VISIT_TypeAliasDecl
#  define MX_ENTER_VISIT_TypeAliasDecl MX_ENTER_VISIT_TypedefNameDecl
#endif
#ifndef MX_EXIT_VISIT_TypeAliasDecl
#  define MX_EXIT_VISIT_TypeAliasDecl MX_EXIT_VISIT_TypedefNameDecl
#endif

MX_BEGIN_VISIT_DECL(TypeAliasDecl)
  MX_ENTER_VISIT_TypeAliasDecl
  MX_VISIT_BASE(TypeAliasDecl, TypedefNameDecl)
  MX_VISIT_OPTIONAL_ENTITY(TypeAliasDecl, described_alias_template, 61, MX_APPLY_METHOD, DescribedAliasTemplate, TypeAliasTemplateDecl, NthDecl, DeclUseSelector::DESCRIBED_ALIAS_TEMPLATE)
  MX_EXIT_VISIT_TypeAliasDecl
MX_END_VISIT_DECL(TypeAliasDecl)

#ifndef MX_ENTER_VISIT_ObjCTypeParamDecl
#  define MX_ENTER_VISIT_ObjCTypeParamDecl MX_ENTER_VISIT_TypedefNameDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCTypeParamDecl
#  define MX_EXIT_VISIT_ObjCTypeParamDecl MX_EXIT_VISIT_TypedefNameDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCTypeParamDecl)
  MX_ENTER_VISIT_ObjCTypeParamDecl
  MX_VISIT_BASE(ObjCTypeParamDecl, TypedefNameDecl)
  MX_VISIT_ENTITY(ObjCTypeParamDecl, colon_token, 61, MX_APPLY_METHOD, ColonToken, Token, NthDecl, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENUM(ObjCTypeParamDecl, variance, 72, MX_APPLY_METHOD, Variance, ObjCTypeParamVariance, NthDecl)
  MX_VISIT_ENTITY(ObjCTypeParamDecl, variance_token, 62, MX_APPLY_METHOD, VarianceToken, Token, NthDecl, TokenUseSelector::VARIANCE_TOKEN)
  MX_VISIT_BOOL(ObjCTypeParamDecl, has_explicit_bound, 77, MX_APPLY_METHOD, HasExplicitBound, bool, NthDecl)
  MX_EXIT_VISIT_ObjCTypeParamDecl
MX_END_VISIT_DECL(ObjCTypeParamDecl)

#ifndef MX_ENTER_VISIT_TemplateDecl
#  define MX_ENTER_VISIT_TemplateDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_TemplateDecl
#  define MX_EXIT_VISIT_TemplateDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(TemplateDecl)
  MX_ENTER_VISIT_TemplateDecl
  MX_EXIT_VISIT_TemplateDecl
MX_END_VISIT_DECL(TemplateDecl)

#ifndef MX_ENTER_VISIT_RedeclarableTemplateDecl
#  define MX_ENTER_VISIT_RedeclarableTemplateDecl MX_ENTER_VISIT_TemplateDecl
#endif
#ifndef MX_EXIT_VISIT_RedeclarableTemplateDecl
#  define MX_EXIT_VISIT_RedeclarableTemplateDecl MX_EXIT_VISIT_TemplateDecl
#endif

MX_BEGIN_VISIT_DECL(RedeclarableTemplateDecl)
  MX_ENTER_VISIT_RedeclarableTemplateDecl
  MX_EXIT_VISIT_RedeclarableTemplateDecl
MX_END_VISIT_DECL(RedeclarableTemplateDecl)

#ifndef MX_ENTER_VISIT_FunctionTemplateDecl
#  define MX_ENTER_VISIT_FunctionTemplateDecl MX_ENTER_VISIT_RedeclarableTemplateDecl
#endif
#ifndef MX_EXIT_VISIT_FunctionTemplateDecl
#  define MX_EXIT_VISIT_FunctionTemplateDecl MX_EXIT_VISIT_RedeclarableTemplateDecl
#endif

MX_BEGIN_VISIT_DECL(FunctionTemplateDecl)
  MX_ENTER_VISIT_FunctionTemplateDecl
  MX_EXIT_VISIT_FunctionTemplateDecl
MX_END_VISIT_DECL(FunctionTemplateDecl)

#ifndef MX_ENTER_VISIT_ClassTemplateDecl
#  define MX_ENTER_VISIT_ClassTemplateDecl MX_ENTER_VISIT_RedeclarableTemplateDecl
#endif
#ifndef MX_EXIT_VISIT_ClassTemplateDecl
#  define MX_EXIT_VISIT_ClassTemplateDecl MX_EXIT_VISIT_RedeclarableTemplateDecl
#endif

MX_BEGIN_VISIT_DECL(ClassTemplateDecl)
  MX_ENTER_VISIT_ClassTemplateDecl
  MX_EXIT_VISIT_ClassTemplateDecl
MX_END_VISIT_DECL(ClassTemplateDecl)

#ifndef MX_ENTER_VISIT_VarTemplateDecl
#  define MX_ENTER_VISIT_VarTemplateDecl MX_ENTER_VISIT_RedeclarableTemplateDecl
#endif
#ifndef MX_EXIT_VISIT_VarTemplateDecl
#  define MX_EXIT_VISIT_VarTemplateDecl MX_EXIT_VISIT_RedeclarableTemplateDecl
#endif

MX_BEGIN_VISIT_DECL(VarTemplateDecl)
  MX_ENTER_VISIT_VarTemplateDecl
  MX_EXIT_VISIT_VarTemplateDecl
MX_END_VISIT_DECL(VarTemplateDecl)

#ifndef MX_ENTER_VISIT_TypeAliasTemplateDecl
#  define MX_ENTER_VISIT_TypeAliasTemplateDecl MX_ENTER_VISIT_RedeclarableTemplateDecl
#endif
#ifndef MX_EXIT_VISIT_TypeAliasTemplateDecl
#  define MX_EXIT_VISIT_TypeAliasTemplateDecl MX_EXIT_VISIT_RedeclarableTemplateDecl
#endif

MX_BEGIN_VISIT_DECL(TypeAliasTemplateDecl)
  MX_ENTER_VISIT_TypeAliasTemplateDecl
  MX_VISIT_BASE(TypeAliasTemplateDecl, RedeclarableTemplateDecl)
  MX_VISIT_OPTIONAL_ENTITY(TypeAliasTemplateDecl, instantiated_from_member_template, 51, MX_APPLY_METHOD, InstantiatedFromMemberTemplate, TypeAliasTemplateDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_TEMPLATE)
  MX_VISIT_ENTITY(TypeAliasTemplateDecl, templated_declaration, 52, MX_APPLY_METHOD, TemplatedDeclaration, TypeAliasDecl, NthDecl, DeclUseSelector::TEMPLATED_DECLARATION)
  MX_EXIT_VISIT_TypeAliasTemplateDecl
MX_END_VISIT_DECL(TypeAliasTemplateDecl)

#ifndef MX_ENTER_VISIT_ConceptDecl
#  define MX_ENTER_VISIT_ConceptDecl MX_ENTER_VISIT_TemplateDecl
#endif
#ifndef MX_EXIT_VISIT_ConceptDecl
#  define MX_EXIT_VISIT_ConceptDecl MX_EXIT_VISIT_TemplateDecl
#endif

MX_BEGIN_VISIT_DECL(ConceptDecl)
  MX_ENTER_VISIT_ConceptDecl
  MX_VISIT_BASE(ConceptDecl, TemplateDecl)
  MX_VISIT_ENTITY(ConceptDecl, constraint_expression, 51, MX_APPLY_METHOD, ConstraintExpression, Expr, NthDecl, StmtUseSelector::CONSTRAINT_EXPRESSION)
  MX_VISIT_BOOL(ConceptDecl, is_type_concept, 68, MX_APPLY_METHOD, IsTypeConcept, bool, NthDecl)
  MX_EXIT_VISIT_ConceptDecl
MX_END_VISIT_DECL(ConceptDecl)

#ifndef MX_ENTER_VISIT_BuiltinTemplateDecl
#  define MX_ENTER_VISIT_BuiltinTemplateDecl MX_ENTER_VISIT_TemplateDecl
#endif
#ifndef MX_EXIT_VISIT_BuiltinTemplateDecl
#  define MX_EXIT_VISIT_BuiltinTemplateDecl MX_EXIT_VISIT_TemplateDecl
#endif

MX_BEGIN_VISIT_DECL(BuiltinTemplateDecl)
  MX_ENTER_VISIT_BuiltinTemplateDecl
  MX_EXIT_VISIT_BuiltinTemplateDecl
MX_END_VISIT_DECL(BuiltinTemplateDecl)

#ifndef MX_ENTER_VISIT_TemplateTemplateParmDecl
#  define MX_ENTER_VISIT_TemplateTemplateParmDecl MX_ENTER_VISIT_TemplateDecl
#endif
#ifndef MX_EXIT_VISIT_TemplateTemplateParmDecl
#  define MX_EXIT_VISIT_TemplateTemplateParmDecl MX_EXIT_VISIT_TemplateDecl
#endif

MX_BEGIN_VISIT_DECL(TemplateTemplateParmDecl)
  MX_ENTER_VISIT_TemplateTemplateParmDecl
  MX_EXIT_VISIT_TemplateTemplateParmDecl
MX_END_VISIT_DECL(TemplateTemplateParmDecl)

#ifndef MX_ENTER_VISIT_ObjCPropertyDecl
#  define MX_ENTER_VISIT_ObjCPropertyDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCPropertyDecl
#  define MX_EXIT_VISIT_ObjCPropertyDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCPropertyDecl)
  MX_ENTER_VISIT_ObjCPropertyDecl
  MX_VISIT_BASE(ObjCPropertyDecl, NamedDecl)
  MX_VISIT_ENTITY(ObjCPropertyDecl, at_token, 51, MX_APPLY_METHOD, AtToken, Token, NthDecl, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyDecl, getter_method_declaration, 52, MX_APPLY_METHOD, GetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::GETTER_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyDecl, getter_name_token, 53, MX_APPLY_METHOD, GetterNameToken, Token, NthDecl, TokenUseSelector::GETTER_NAME_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyDecl, l_paren_token, 61, MX_APPLY_METHOD, LParenToken, Token, NthDecl, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENUM(ObjCPropertyDecl, property_implementation, 72, MX_APPLY_METHOD, PropertyImplementation, ObjCPropertyDeclPropertyControl, NthDecl)
  MX_VISIT_ENTITY(ObjCPropertyDecl, property_instance_variable_declaration, 62, MX_APPLY_METHOD, PropertyInstanceVariableDeclaration, ObjCIvarDecl, NthDecl, DeclUseSelector::PROPERTY_INSTANCE_VARIABLE_DECLARATION)
  MX_VISIT_ENUM(ObjCPropertyDecl, query_kind, 80, MX_APPLY_METHOD, QueryKind, ObjCPropertyQueryKind, NthDecl)
  MX_VISIT_ENUM(ObjCPropertyDecl, setter_kind, 82, MX_APPLY_METHOD, SetterKind, ObjCPropertyDeclSetterKind, NthDecl)
  MX_VISIT_ENTITY(ObjCPropertyDecl, setter_method_declaration, 63, MX_APPLY_METHOD, SetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::SETTER_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyDecl, setter_name_token, 71, MX_APPLY_METHOD, SetterNameToken, Token, NthDecl, TokenUseSelector::SETTER_NAME_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyDecl, type, 74, MX_APPLY_METHOD, Type, Type, NthDecl, TypeUseSelector::TYPE)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_atomic, 68, MX_APPLY_METHOD, IsAtomic, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_class_property, 69, MX_APPLY_METHOD, IsClassProperty, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_direct_property, 70, MX_APPLY_METHOD, IsDirectProperty, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_instance_property, 75, MX_APPLY_METHOD, IsInstanceProperty, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_optional, 77, MX_APPLY_METHOD, IsOptional, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_read_only, 79, MX_APPLY_METHOD, IsReadOnly, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_retaining, 87, MX_APPLY_METHOD, IsRetaining, bool, NthDecl)
  MX_EXIT_VISIT_ObjCPropertyDecl
MX_END_VISIT_DECL(ObjCPropertyDecl)

#ifndef MX_ENTER_VISIT_ObjCMethodDecl
#  define MX_ENTER_VISIT_ObjCMethodDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCMethodDecl
#  define MX_EXIT_VISIT_ObjCMethodDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCMethodDecl)
  MX_ENTER_VISIT_ObjCMethodDecl
  MX_VISIT_BASE(ObjCMethodDecl, NamedDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, defined_in_ns_object, 68, MX_APPLY_METHOD, DefinedInNSObject, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCMethodDecl, find_property_declaration, 51, MX_APPLY_METHOD, FindPropertyDeclaration, ObjCPropertyDecl, NthDecl, DeclUseSelector::FIND_PROPERTY_DECLARATION)
  MX_VISIT_ENTITY(ObjCMethodDecl, class_interface, 52, MX_APPLY_METHOD, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_VISIT_ENTITY(ObjCMethodDecl, command_declaration, 53, MX_APPLY_METHOD, CommandDeclaration, ImplicitParamDecl, NthDecl, DeclUseSelector::COMMAND_DECLARATION)
  MX_VISIT_ENTITY(ObjCMethodDecl, declarator_end_token, 61, MX_APPLY_METHOD, DeclaratorEndToken, Token, NthDecl, TokenUseSelector::DECLARATOR_END_TOKEN)
  MX_VISIT_ENUM(ObjCMethodDecl, implementation_control, 72, MX_APPLY_METHOD, ImplementationControl, ObjCMethodDeclImplementationControl, NthDecl)
  MX_VISIT_ENUM(ObjCMethodDecl, method_family, 80, MX_APPLY_METHOD, MethodFamily, ObjCMethodFamily, NthDecl)
  MX_VISIT_ENUM(ObjCMethodDecl, obj_c_decl_qualifier, 82, MX_APPLY_METHOD, ObjCDeclQualifier, DeclObjCDeclQualifier, NthDecl)
  MX_VISIT_ENTITY(ObjCMethodDecl, return_type, 62, MX_APPLY_METHOD, ReturnType, Type, NthDecl, TypeUseSelector::RETURN_TYPE)
  MX_VISIT_ENTITY(ObjCMethodDecl, selector_start_token, 74, MX_APPLY_METHOD, SelectorStartToken, Token, NthDecl, TokenUseSelector::SELECTOR_START_TOKEN)
  MX_VISIT_ENTITY(ObjCMethodDecl, self_declaration, 76, MX_APPLY_METHOD, SelfDeclaration, ImplicitParamDecl, NthDecl, DeclUseSelector::SELF_DECLARATION)
  MX_VISIT_BOOL(ObjCMethodDecl, has_parameter_destroyed_in_callee, 69, MX_APPLY_METHOD, HasParameterDestroyedInCallee, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, has_redeclaration, 70, MX_APPLY_METHOD, HasRedeclaration, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, has_related_result_type, 75, MX_APPLY_METHOD, HasRelatedResultType, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, has_skipped_body, 77, MX_APPLY_METHOD, HasSkippedBody, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_class_method, 79, MX_APPLY_METHOD, IsClassMethod, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_defined, 87, MX_APPLY_METHOD, IsDefined, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_designated_initializer_for_the_interface, 90, MX_APPLY_METHOD, IsDesignatedInitializerForTheInterface, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_direct_method, 91, MX_APPLY_METHOD, IsDirectMethod, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_instance_method, 92, MX_APPLY_METHOD, IsInstanceMethod, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_optional, 93, MX_APPLY_METHOD, IsOptional, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_overriding, 94, MX_APPLY_METHOD, IsOverriding, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_property_accessor, 95, MX_APPLY_METHOD, IsPropertyAccessor, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_redeclaration, 96, MX_APPLY_METHOD, IsRedeclaration, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_synthesized_accessor_stub, 97, MX_APPLY_METHOD, IsSynthesizedAccessorStub, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_this_declaration_a_designated_initializer, 98, MX_APPLY_METHOD, IsThisDeclarationADesignatedInitializer, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_variadic, 99, MX_APPLY_METHOD, IsVariadic, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCMethodDecl, parameters, 45, MX_APPLY_METHOD, Parameters, ParmVarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCMethodDecl, selector_tokens, 46, MX_APPLY_METHOD, SelectorTokens, Token, NthDecl)
  MX_VISIT_DECL_CONTEXT(ObjCMethodDecl, declarations_in_context, 57, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_ObjCMethodDecl
MX_END_VISIT_DECL(ObjCMethodDecl)

#ifndef MX_ENTER_VISIT_ObjCContainerDecl
#  define MX_ENTER_VISIT_ObjCContainerDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCContainerDecl
#  define MX_EXIT_VISIT_ObjCContainerDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCContainerDecl)
  MX_ENTER_VISIT_ObjCContainerDecl
  MX_VISIT_BASE(ObjCContainerDecl, NamedDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, class_methods, 45, MX_APPLY_METHOD, ClassMethods, ObjCMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, class_properties, 46, MX_APPLY_METHOD, ClassProperties, ObjCPropertyDecl, NthDecl)
  MX_VISIT_ENTITY(ObjCContainerDecl, at_start_token, 53, MX_APPLY_METHOD, AtStartToken, Token, NthDecl, TokenUseSelector::AT_START_TOKEN)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, instance_methods, 57, MX_APPLY_METHOD, InstanceMethods, ObjCMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, instance_properties, 171, MX_APPLY_METHOD, InstanceProperties, ObjCPropertyDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, methods, 180, MX_APPLY_METHOD, Methods, ObjCMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, properties, 316, MX_APPLY_METHOD, Properties, ObjCPropertyDecl, NthDecl)
  MX_VISIT_DECL_CONTEXT(ObjCContainerDecl, declarations_in_context, 349, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_ObjCContainerDecl
MX_END_VISIT_DECL(ObjCContainerDecl)

#ifndef MX_ENTER_VISIT_ObjCCategoryDecl
#  define MX_ENTER_VISIT_ObjCCategoryDecl MX_ENTER_VISIT_ObjCContainerDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCCategoryDecl
#  define MX_EXIT_VISIT_ObjCCategoryDecl MX_EXIT_VISIT_ObjCContainerDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCCategoryDecl)
  MX_ENTER_VISIT_ObjCCategoryDecl
  MX_VISIT_BASE(ObjCCategoryDecl, ObjCContainerDecl)
  MX_VISIT_BOOL(ObjCCategoryDecl, is_class_extension, 68, MX_APPLY_METHOD, IsClassExtension, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCCategoryDecl, category_name_token, 61, MX_APPLY_METHOD, CategoryNameToken, Token, NthDecl, TokenUseSelector::CATEGORY_NAME_TOKEN)
  MX_VISIT_ENTITY(ObjCCategoryDecl, class_interface, 62, MX_APPLY_METHOD, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_VISIT_ENTITY(ObjCCategoryDecl, implementation, 63, MX_APPLY_METHOD, Implementation, ObjCCategoryImplDecl, NthDecl, DeclUseSelector::IMPLEMENTATION)
  MX_VISIT_ENTITY(ObjCCategoryDecl, instance_variable_l_brace_token, 71, MX_APPLY_METHOD, InstanceVariableLBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_L_BRACE_TOKEN)
  MX_VISIT_ENTITY(ObjCCategoryDecl, instance_variable_r_brace_token, 74, MX_APPLY_METHOD, InstanceVariableRBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_R_BRACE_TOKEN)
  MX_VISIT_ENTITY(ObjCCategoryDecl, next_class_category, 76, MX_APPLY_METHOD, NextClassCategory, ObjCCategoryDecl, NthDecl, DeclUseSelector::NEXT_CLASS_CATEGORY)
  MX_VISIT_ENTITY_LIST(ObjCCategoryDecl, instance_variables, 350, MX_APPLY_METHOD, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCCategoryDecl, protocol_tokens, 351, MX_APPLY_METHOD, ProtocolTokens, Token, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCCategoryDecl, protocols, 352, MX_APPLY_METHOD, Protocols, ObjCProtocolDecl, NthDecl)
  MX_EXIT_VISIT_ObjCCategoryDecl
MX_END_VISIT_DECL(ObjCCategoryDecl)

#ifndef MX_ENTER_VISIT_ObjCProtocolDecl
#  define MX_ENTER_VISIT_ObjCProtocolDecl MX_ENTER_VISIT_ObjCContainerDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCProtocolDecl
#  define MX_EXIT_VISIT_ObjCProtocolDecl MX_EXIT_VISIT_ObjCContainerDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCProtocolDecl)
  MX_ENTER_VISIT_ObjCProtocolDecl
  MX_VISIT_BASE(ObjCProtocolDecl, ObjCContainerDecl)
  MX_VISIT_TEXT(ObjCProtocolDecl, obj_c_runtime_name_as_string, 67, MX_APPLY_METHOD, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_VISIT_BOOL(ObjCProtocolDecl, has_definition, 68, MX_APPLY_METHOD, HasDefinition, bool, NthDecl)
  MX_VISIT_BOOL(ObjCProtocolDecl, is_non_runtime_protocol, 69, MX_APPLY_METHOD, IsNonRuntimeProtocol, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCProtocolDecl, protocol_tokens, 350, MX_APPLY_METHOD, ProtocolTokens, Token, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCProtocolDecl, protocols, 351, MX_APPLY_METHOD, Protocols, ObjCProtocolDecl, NthDecl)
  MX_EXIT_VISIT_ObjCProtocolDecl
MX_END_VISIT_DECL(ObjCProtocolDecl)

#ifndef MX_ENTER_VISIT_ObjCInterfaceDecl
#  define MX_ENTER_VISIT_ObjCInterfaceDecl MX_ENTER_VISIT_ObjCContainerDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCInterfaceDecl
#  define MX_EXIT_VISIT_ObjCInterfaceDecl MX_EXIT_VISIT_ObjCContainerDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCInterfaceDecl)
  MX_ENTER_VISIT_ObjCInterfaceDecl
  MX_VISIT_BASE(ObjCInterfaceDecl, ObjCContainerDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, all_referenced_protocols, 350, MX_APPLY_METHOD, AllReferencedProtocols, ObjCProtocolDecl, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, declares_or_inherits_designated_initializers, 68, MX_APPLY_METHOD, DeclaresOrInheritsDesignatedInitializers, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, end_of_definition_token, 61, MX_APPLY_METHOD, EndOfDefinitionToken, Token, NthDecl, TokenUseSelector::END_OF_DEFINITION_TOKEN)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, implementation, 62, MX_APPLY_METHOD, Implementation, ObjCImplementationDecl, NthDecl, DeclUseSelector::IMPLEMENTATION)
  MX_VISIT_TEXT(ObjCInterfaceDecl, obj_c_runtime_name_as_string, 67, MX_APPLY_METHOD, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class, 63, MX_APPLY_METHOD, SuperClass, ObjCInterfaceDecl, NthDecl, DeclUseSelector::SUPER_CLASS)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, super_class_token, 71, MX_APPLY_METHOD, SuperClassToken, Token, NthDecl, TokenUseSelector::SUPER_CLASS_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class_type, 74, MX_APPLY_METHOD, SuperClassTypeInfo, Type, NthDecl, TypeUseSelector::SUPER_CLASS_TYPE)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, type_for_declaration, 76, MX_APPLY_METHOD, TypeForDeclaration, Type, NthDecl, TypeUseSelector::TYPE_FOR_DECLARATION)
  MX_VISIT_BOOL(ObjCInterfaceDecl, has_definition, 75, MX_APPLY_METHOD, HasDefinition, bool, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, has_designated_initializers, 77, MX_APPLY_METHOD, HasDesignatedInitializers, bool, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, is_arc_weakref_unavailable, 79, MX_APPLY_METHOD, IsArcWeakrefUnavailable, bool, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, is_implicit_interface_declaration, 87, MX_APPLY_METHOD, IsImplicitInterfaceDeclaration, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, is_obj_c_requires_property_definitions, 78, MX_APPLY_METHOD, IsObjCRequiresPropertyDefinitions, ObjCInterfaceDecl, NthDecl, DeclUseSelector::IS_OBJ_C_REQUIRES_PROPERTY_DEFINITIONS)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, instance_variables, 351, MX_APPLY_METHOD, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, known_categories, 352, MX_APPLY_METHOD, KnownCategories, ObjCCategoryDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, known_extensions, 353, MX_APPLY_METHOD, KnownExtensions, ObjCCategoryDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, protocol_tokens, 354, MX_APPLY_METHOD, ProtocolTokens, Token, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, protocols, 355, MX_APPLY_METHOD, Protocols, ObjCProtocolDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, visible_categories, 356, MX_APPLY_METHOD, VisibleCategories, ObjCCategoryDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, visible_extensions, 357, MX_APPLY_METHOD, VisibleExtensions, ObjCCategoryDecl, NthDecl)
  MX_EXIT_VISIT_ObjCInterfaceDecl
MX_END_VISIT_DECL(ObjCInterfaceDecl)

#ifndef MX_ENTER_VISIT_ObjCImplDecl
#  define MX_ENTER_VISIT_ObjCImplDecl MX_ENTER_VISIT_ObjCContainerDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCImplDecl
#  define MX_EXIT_VISIT_ObjCImplDecl MX_EXIT_VISIT_ObjCContainerDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCImplDecl)
  MX_ENTER_VISIT_ObjCImplDecl
  MX_VISIT_BASE(ObjCImplDecl, ObjCContainerDecl)
  MX_VISIT_ENTITY(ObjCImplDecl, class_interface, 61, MX_APPLY_METHOD, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_VISIT_ENTITY_LIST(ObjCImplDecl, property_implementations, 350, MX_APPLY_METHOD, PropertyImplementations, ObjCPropertyImplDecl, NthDecl)
  MX_EXIT_VISIT_ObjCImplDecl
MX_END_VISIT_DECL(ObjCImplDecl)

#ifndef MX_ENTER_VISIT_ObjCCategoryImplDecl
#  define MX_ENTER_VISIT_ObjCCategoryImplDecl MX_ENTER_VISIT_ObjCImplDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCCategoryImplDecl
#  define MX_EXIT_VISIT_ObjCCategoryImplDecl MX_EXIT_VISIT_ObjCImplDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCCategoryImplDecl)
  MX_ENTER_VISIT_ObjCCategoryImplDecl
  MX_VISIT_BASE(ObjCCategoryImplDecl, ObjCImplDecl)
  MX_VISIT_ENTITY(ObjCCategoryImplDecl, category_declaration, 62, MX_APPLY_METHOD, CategoryDeclaration, ObjCCategoryDecl, NthDecl, DeclUseSelector::CATEGORY_DECLARATION)
  MX_VISIT_ENTITY(ObjCCategoryImplDecl, category_name_token, 63, MX_APPLY_METHOD, CategoryNameToken, Token, NthDecl, TokenUseSelector::CATEGORY_NAME_TOKEN)
  MX_EXIT_VISIT_ObjCCategoryImplDecl
MX_END_VISIT_DECL(ObjCCategoryImplDecl)

#ifndef MX_ENTER_VISIT_ObjCImplementationDecl
#  define MX_ENTER_VISIT_ObjCImplementationDecl MX_ENTER_VISIT_ObjCImplDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCImplementationDecl
#  define MX_EXIT_VISIT_ObjCImplementationDecl MX_EXIT_VISIT_ObjCImplDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCImplementationDecl)
  MX_ENTER_VISIT_ObjCImplementationDecl
  MX_VISIT_BASE(ObjCImplementationDecl, ObjCImplDecl)
  MX_VISIT_ENTITY(ObjCImplementationDecl, instance_variable_l_brace_token, 62, MX_APPLY_METHOD, InstanceVariableLBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_L_BRACE_TOKEN)
  MX_VISIT_ENTITY(ObjCImplementationDecl, instance_variable_r_brace_token, 63, MX_APPLY_METHOD, InstanceVariableRBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_R_BRACE_TOKEN)
  MX_VISIT_TEXT(ObjCImplementationDecl, obj_c_runtime_name_as_string, 67, MX_APPLY_METHOD, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_VISIT_ENTITY(ObjCImplementationDecl, super_class, 71, MX_APPLY_METHOD, SuperClass, ObjCInterfaceDecl, NthDecl, DeclUseSelector::SUPER_CLASS)
  MX_VISIT_ENTITY(ObjCImplementationDecl, super_class_token, 74, MX_APPLY_METHOD, SuperClassToken, Token, NthDecl, TokenUseSelector::SUPER_CLASS_TOKEN)
  MX_VISIT_BOOL(ObjCImplementationDecl, has_destructors, 68, MX_APPLY_METHOD, HasDestructors, bool, NthDecl)
  MX_VISIT_BOOL(ObjCImplementationDecl, has_non_zero_constructors, 69, MX_APPLY_METHOD, HasNonZeroConstructors, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCImplementationDecl, instance_variables, 351, MX_APPLY_METHOD, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_EXIT_VISIT_ObjCImplementationDecl
MX_END_VISIT_DECL(ObjCImplementationDecl)

#ifndef MX_ENTER_VISIT_ObjCCompatibleAliasDecl
#  define MX_ENTER_VISIT_ObjCCompatibleAliasDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_ObjCCompatibleAliasDecl
#  define MX_EXIT_VISIT_ObjCCompatibleAliasDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(ObjCCompatibleAliasDecl)
  MX_ENTER_VISIT_ObjCCompatibleAliasDecl
  MX_VISIT_BASE(ObjCCompatibleAliasDecl, NamedDecl)
  MX_VISIT_ENTITY(ObjCCompatibleAliasDecl, class_interface, 51, MX_APPLY_METHOD, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_EXIT_VISIT_ObjCCompatibleAliasDecl
MX_END_VISIT_DECL(ObjCCompatibleAliasDecl)

#ifndef MX_ENTER_VISIT_NamespaceDecl
#  define MX_ENTER_VISIT_NamespaceDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_NamespaceDecl
#  define MX_EXIT_VISIT_NamespaceDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(NamespaceDecl)
  MX_ENTER_VISIT_NamespaceDecl
  MX_VISIT_DECL_CONTEXT(NamespaceDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_NamespaceDecl
MX_END_VISIT_DECL(NamespaceDecl)

#ifndef MX_ENTER_VISIT_NamespaceAliasDecl
#  define MX_ENTER_VISIT_NamespaceAliasDecl MX_ENTER_VISIT_NamedDecl
#endif
#ifndef MX_EXIT_VISIT_NamespaceAliasDecl
#  define MX_EXIT_VISIT_NamespaceAliasDecl MX_EXIT_VISIT_NamedDecl
#endif

MX_BEGIN_VISIT_DECL(NamespaceAliasDecl)
  MX_ENTER_VISIT_NamespaceAliasDecl
  MX_VISIT_BASE(NamespaceAliasDecl, NamedDecl)
  MX_VISIT_ENTITY(NamespaceAliasDecl, alias_token, 51, MX_APPLY_METHOD, AliasToken, Token, NthDecl, TokenUseSelector::ALIAS_TOKEN)
  MX_VISIT_ENTITY(NamespaceAliasDecl, aliased_namespace, 52, MX_APPLY_METHOD, AliasedNamespace, NamedDecl, NthDecl, DeclUseSelector::ALIASED_NAMESPACE)
  MX_VISIT_ENTITY(NamespaceAliasDecl, namespace_token, 53, MX_APPLY_METHOD, NamespaceToken, Token, NthDecl, TokenUseSelector::NAMESPACE_TOKEN)
  MX_VISIT_ENTITY(NamespaceAliasDecl, target_name_token, 61, MX_APPLY_METHOD, TargetNameToken, Token, NthDecl, TokenUseSelector::TARGET_NAME_TOKEN)
  MX_EXIT_VISIT_NamespaceAliasDecl
MX_END_VISIT_DECL(NamespaceAliasDecl)

#ifndef MX_ENTER_VISIT_LinkageSpecDecl
#  define MX_ENTER_VISIT_LinkageSpecDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_LinkageSpecDecl
#  define MX_EXIT_VISIT_LinkageSpecDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(LinkageSpecDecl)
  MX_ENTER_VISIT_LinkageSpecDecl
  MX_VISIT_DECL_CONTEXT(LinkageSpecDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_LinkageSpecDecl
MX_END_VISIT_DECL(LinkageSpecDecl)

#ifndef MX_ENTER_VISIT_LifetimeExtendedTemporaryDecl
#  define MX_ENTER_VISIT_LifetimeExtendedTemporaryDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_LifetimeExtendedTemporaryDecl
#  define MX_EXIT_VISIT_LifetimeExtendedTemporaryDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(LifetimeExtendedTemporaryDecl)
  MX_ENTER_VISIT_LifetimeExtendedTemporaryDecl
  MX_VISIT_BASE(LifetimeExtendedTemporaryDecl, Decl)
  MX_VISIT_ENTITY_LIST(LifetimeExtendedTemporaryDecl, children_expression, 45, MX_APPLY_METHOD, ChildrenExpression, Stmt, NthDecl)
  MX_VISIT_ENTITY(LifetimeExtendedTemporaryDecl, extending_declaration, 43, MX_APPLY_METHOD, ExtendingDeclaration, ValueDecl, NthDecl, DeclUseSelector::EXTENDING_DECLARATION)
  MX_VISIT_ENUM(LifetimeExtendedTemporaryDecl, storage_duration, 60, MX_APPLY_METHOD, StorageDuration, StorageDuration, NthDecl)
  MX_VISIT_ENTITY(LifetimeExtendedTemporaryDecl, temporary_expression, 51, MX_APPLY_METHOD, TemporaryExpression, Expr, NthDecl, StmtUseSelector::TEMPORARY_EXPRESSION)
  MX_EXIT_VISIT_LifetimeExtendedTemporaryDecl
MX_END_VISIT_DECL(LifetimeExtendedTemporaryDecl)

#ifndef MX_ENTER_VISIT_ImportDecl
#  define MX_ENTER_VISIT_ImportDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_ImportDecl
#  define MX_EXIT_VISIT_ImportDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(ImportDecl)
  MX_ENTER_VISIT_ImportDecl
  MX_VISIT_BASE(ImportDecl, Decl)
  MX_VISIT_ENTITY_LIST(ImportDecl, identifier_tokens, 45, MX_APPLY_METHOD, IdentifierTokens, Token, NthDecl)
  MX_EXIT_VISIT_ImportDecl
MX_END_VISIT_DECL(ImportDecl)

#ifndef MX_ENTER_VISIT_FriendTemplateDecl
#  define MX_ENTER_VISIT_FriendTemplateDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_FriendTemplateDecl
#  define MX_EXIT_VISIT_FriendTemplateDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(FriendTemplateDecl)
  MX_ENTER_VISIT_FriendTemplateDecl
  MX_EXIT_VISIT_FriendTemplateDecl
MX_END_VISIT_DECL(FriendTemplateDecl)

#ifndef MX_ENTER_VISIT_FriendDecl
#  define MX_ENTER_VISIT_FriendDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_FriendDecl
#  define MX_EXIT_VISIT_FriendDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(FriendDecl)
  MX_ENTER_VISIT_FriendDecl
  MX_VISIT_BASE(FriendDecl, Decl)
  MX_VISIT_OPTIONAL_ENTITY(FriendDecl, friend_declaration, 43, MX_APPLY_METHOD, FriendDeclaration, NamedDecl, NthDecl, DeclUseSelector::FRIEND_DECLARATION)
  MX_VISIT_ENTITY(FriendDecl, friend_token, 51, MX_APPLY_METHOD, FriendToken, Token, NthDecl, TokenUseSelector::FRIEND_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(FriendDecl, friend_type, 52, MX_APPLY_METHOD, FriendType, Type, NthDecl, TypeUseSelector::FRIEND_TYPE)
  MX_VISIT_BOOL(FriendDecl, is_unsupported_friend, 48, MX_APPLY_METHOD, IsUnsupportedFriend, bool, NthDecl)
  MX_VISIT_PSEUDO_LIST(FriendDecl, friend_type_template_parameter_lists, 73, MX_APPLY_METHOD, FriendTypeTemplateParameterLists, TemplateParameterList, NthDecl)
  MX_EXIT_VISIT_FriendDecl
MX_END_VISIT_DECL(FriendDecl)

#ifndef MX_ENTER_VISIT_FileScopeAsmDecl
#  define MX_ENTER_VISIT_FileScopeAsmDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_FileScopeAsmDecl
#  define MX_EXIT_VISIT_FileScopeAsmDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(FileScopeAsmDecl)
  MX_ENTER_VISIT_FileScopeAsmDecl
  MX_VISIT_BASE(FileScopeAsmDecl, Decl)
  MX_VISIT_ENTITY(FileScopeAsmDecl, assembly_token, 43, MX_APPLY_METHOD, AssemblyToken, Token, NthDecl, TokenUseSelector::ASSEMBLY_TOKEN)
  MX_VISIT_ENTITY(FileScopeAsmDecl, assembly_string, 51, MX_APPLY_METHOD, AssemblyString, StringLiteral, NthDecl, StmtUseSelector::ASSEMBLY_STRING)
  MX_VISIT_ENTITY(FileScopeAsmDecl, r_paren_token, 52, MX_APPLY_METHOD, RParenToken, Token, NthDecl, TokenUseSelector::R_PAREN_TOKEN)
  MX_EXIT_VISIT_FileScopeAsmDecl
MX_END_VISIT_DECL(FileScopeAsmDecl)

#ifndef MX_ENTER_VISIT_ExternCContextDecl
#  define MX_ENTER_VISIT_ExternCContextDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_ExternCContextDecl
#  define MX_EXIT_VISIT_ExternCContextDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(ExternCContextDecl)
  MX_ENTER_VISIT_ExternCContextDecl
  MX_VISIT_DECL_CONTEXT(ExternCContextDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_ExternCContextDecl
MX_END_VISIT_DECL(ExternCContextDecl)

#ifndef MX_ENTER_VISIT_ExportDecl
#  define MX_ENTER_VISIT_ExportDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_ExportDecl
#  define MX_EXIT_VISIT_ExportDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(ExportDecl)
  MX_ENTER_VISIT_ExportDecl
  MX_VISIT_BASE(ExportDecl, Decl)
  MX_VISIT_ENTITY(ExportDecl, export_token, 43, MX_APPLY_METHOD, ExportToken, Token, NthDecl, TokenUseSelector::EXPORT_TOKEN)
  MX_VISIT_ENTITY(ExportDecl, r_brace_token, 51, MX_APPLY_METHOD, RBraceToken, Token, NthDecl, TokenUseSelector::R_BRACE_TOKEN)
  MX_VISIT_BOOL(ExportDecl, has_braces, 44, MX_APPLY_METHOD, HasBraces, bool, NthDecl)
  MX_VISIT_DECL_CONTEXT(ExportDecl, declarations_in_context, 45, MX_APPLY_METHOD, AlreadyLoadedDeclarations, Decl, NthDecl)
  MX_EXIT_VISIT_ExportDecl
MX_END_VISIT_DECL(ExportDecl)

#ifndef MX_ENTER_VISIT_EmptyDecl
#  define MX_ENTER_VISIT_EmptyDecl MX_ENTER_VISIT_Decl
#endif
#ifndef MX_EXIT_VISIT_EmptyDecl
#  define MX_EXIT_VISIT_EmptyDecl MX_EXIT_VISIT_Decl
#endif

MX_BEGIN_VISIT_DECL(EmptyDecl)
  MX_ENTER_VISIT_EmptyDecl
  MX_VISIT_BASE(EmptyDecl, Decl)
  MX_EXIT_VISIT_EmptyDecl
MX_END_VISIT_DECL(EmptyDecl)

#undef MX_ENTER_VISIT_TemplateParameterList
#undef MX_EXIT_VISIT_TemplateParameterList
#undef MX_ENTER_VISIT_TemplateArgument
#undef MX_EXIT_VISIT_TemplateArgument
#undef MX_ENTER_VISIT_CXXBaseSpecifier
#undef MX_EXIT_VISIT_CXXBaseSpecifier
#undef MX_ENTER_VISIT_Type
#undef MX_EXIT_VISIT_Type
#undef MX_ENTER_VISIT_TemplateTypeParmType
#undef MX_EXIT_VISIT_TemplateTypeParmType
#undef MX_ENTER_VISIT_TemplateSpecializationType
#undef MX_EXIT_VISIT_TemplateSpecializationType
#undef MX_ENTER_VISIT_TagType
#undef MX_EXIT_VISIT_TagType
#undef MX_ENTER_VISIT_RecordType
#undef MX_EXIT_VISIT_RecordType
#undef MX_ENTER_VISIT_EnumType
#undef MX_EXIT_VISIT_EnumType
#undef MX_ENTER_VISIT_SubstTemplateTypeParmType
#undef MX_EXIT_VISIT_SubstTemplateTypeParmType
#undef MX_ENTER_VISIT_SubstTemplateTypeParmPackType
#undef MX_EXIT_VISIT_SubstTemplateTypeParmPackType
#undef MX_ENTER_VISIT_ReferenceType
#undef MX_EXIT_VISIT_ReferenceType
#undef MX_ENTER_VISIT_RValueReferenceType
#undef MX_EXIT_VISIT_RValueReferenceType
#undef MX_ENTER_VISIT_LValueReferenceType
#undef MX_EXIT_VISIT_LValueReferenceType
#undef MX_ENTER_VISIT_PointerType
#undef MX_EXIT_VISIT_PointerType
#undef MX_ENTER_VISIT_PipeType
#undef MX_EXIT_VISIT_PipeType
#undef MX_ENTER_VISIT_ParenType
#undef MX_EXIT_VISIT_ParenType
#undef MX_ENTER_VISIT_PackExpansionType
#undef MX_EXIT_VISIT_PackExpansionType
#undef MX_ENTER_VISIT_ObjCTypeParamType
#undef MX_EXIT_VISIT_ObjCTypeParamType
#undef MX_ENTER_VISIT_ObjCObjectType
#undef MX_EXIT_VISIT_ObjCObjectType
#undef MX_ENTER_VISIT_ObjCInterfaceType
#undef MX_EXIT_VISIT_ObjCInterfaceType
#undef MX_ENTER_VISIT_ObjCObjectPointerType
#undef MX_EXIT_VISIT_ObjCObjectPointerType
#undef MX_ENTER_VISIT_MemberPointerType
#undef MX_EXIT_VISIT_MemberPointerType
#undef MX_ENTER_VISIT_MatrixType
#undef MX_EXIT_VISIT_MatrixType
#undef MX_ENTER_VISIT_DependentSizedMatrixType
#undef MX_EXIT_VISIT_DependentSizedMatrixType
#undef MX_ENTER_VISIT_ConstantMatrixType
#undef MX_EXIT_VISIT_ConstantMatrixType
#undef MX_ENTER_VISIT_MacroQualifiedType
#undef MX_EXIT_VISIT_MacroQualifiedType
#undef MX_ENTER_VISIT_InjectedClassNameType
#undef MX_EXIT_VISIT_InjectedClassNameType
#undef MX_ENTER_VISIT_FunctionType
#undef MX_EXIT_VISIT_FunctionType
#undef MX_ENTER_VISIT_FunctionProtoType
#undef MX_EXIT_VISIT_FunctionProtoType
#undef MX_ENTER_VISIT_FunctionNoProtoType
#undef MX_EXIT_VISIT_FunctionNoProtoType
#undef MX_ENTER_VISIT_DependentVectorType
#undef MX_EXIT_VISIT_DependentVectorType
#undef MX_ENTER_VISIT_DependentSizedExtVectorType
#undef MX_EXIT_VISIT_DependentSizedExtVectorType
#undef MX_ENTER_VISIT_DependentBitIntType
#undef MX_EXIT_VISIT_DependentBitIntType
#undef MX_ENTER_VISIT_DependentAddressSpaceType
#undef MX_EXIT_VISIT_DependentAddressSpaceType
#undef MX_ENTER_VISIT_DeducedType
#undef MX_EXIT_VISIT_DeducedType
#undef MX_ENTER_VISIT_DeducedTemplateSpecializationType
#undef MX_EXIT_VISIT_DeducedTemplateSpecializationType
#undef MX_ENTER_VISIT_AutoType
#undef MX_EXIT_VISIT_AutoType
#undef MX_ENTER_VISIT_DecltypeType
#undef MX_EXIT_VISIT_DecltypeType
#undef MX_ENTER_VISIT_ComplexType
#undef MX_EXIT_VISIT_ComplexType
#undef MX_ENTER_VISIT_BuiltinType
#undef MX_EXIT_VISIT_BuiltinType
#undef MX_ENTER_VISIT_BlockPointerType
#undef MX_EXIT_VISIT_BlockPointerType
#undef MX_ENTER_VISIT_BitIntType
#undef MX_EXIT_VISIT_BitIntType
#undef MX_ENTER_VISIT_AttributedType
#undef MX_EXIT_VISIT_AttributedType
#undef MX_ENTER_VISIT_AtomicType
#undef MX_EXIT_VISIT_AtomicType
#undef MX_ENTER_VISIT_ArrayType
#undef MX_EXIT_VISIT_ArrayType
#undef MX_ENTER_VISIT_VariableArrayType
#undef MX_EXIT_VISIT_VariableArrayType
#undef MX_ENTER_VISIT_IncompleteArrayType
#undef MX_EXIT_VISIT_IncompleteArrayType
#undef MX_ENTER_VISIT_DependentSizedArrayType
#undef MX_EXIT_VISIT_DependentSizedArrayType
#undef MX_ENTER_VISIT_ConstantArrayType
#undef MX_EXIT_VISIT_ConstantArrayType
#undef MX_ENTER_VISIT_AdjustedType
#undef MX_EXIT_VISIT_AdjustedType
#undef MX_ENTER_VISIT_DecayedType
#undef MX_EXIT_VISIT_DecayedType
#undef MX_ENTER_VISIT_TypeWithKeyword
#undef MX_EXIT_VISIT_TypeWithKeyword
#undef MX_ENTER_VISIT_ElaboratedType
#undef MX_EXIT_VISIT_ElaboratedType
#undef MX_ENTER_VISIT_DependentTemplateSpecializationType
#undef MX_EXIT_VISIT_DependentTemplateSpecializationType
#undef MX_ENTER_VISIT_DependentNameType
#undef MX_EXIT_VISIT_DependentNameType
#undef MX_ENTER_VISIT_VectorType
#undef MX_EXIT_VISIT_VectorType
#undef MX_ENTER_VISIT_ExtVectorType
#undef MX_EXIT_VISIT_ExtVectorType
#undef MX_ENTER_VISIT_UsingType
#undef MX_EXIT_VISIT_UsingType
#undef MX_ENTER_VISIT_UnresolvedUsingType
#undef MX_EXIT_VISIT_UnresolvedUsingType
#undef MX_ENTER_VISIT_UnaryTransformType
#undef MX_EXIT_VISIT_UnaryTransformType
#undef MX_ENTER_VISIT_TypedefType
#undef MX_EXIT_VISIT_TypedefType
#undef MX_ENTER_VISIT_TypeOfType
#undef MX_EXIT_VISIT_TypeOfType
#undef MX_ENTER_VISIT_TypeOfExprType
#undef MX_EXIT_VISIT_TypeOfExprType
#undef MX_ENTER_VISIT_Stmt
#undef MX_EXIT_VISIT_Stmt
#undef MX_ENTER_VISIT_SEHTryStmt
#undef MX_EXIT_VISIT_SEHTryStmt
#undef MX_ENTER_VISIT_SEHLeaveStmt
#undef MX_EXIT_VISIT_SEHLeaveStmt
#undef MX_ENTER_VISIT_SEHFinallyStmt
#undef MX_EXIT_VISIT_SEHFinallyStmt
#undef MX_ENTER_VISIT_SEHExceptStmt
#undef MX_EXIT_VISIT_SEHExceptStmt
#undef MX_ENTER_VISIT_ReturnStmt
#undef MX_EXIT_VISIT_ReturnStmt
#undef MX_ENTER_VISIT_ObjCForCollectionStmt
#undef MX_EXIT_VISIT_ObjCForCollectionStmt
#undef MX_ENTER_VISIT_ObjCAutoreleasePoolStmt
#undef MX_EXIT_VISIT_ObjCAutoreleasePoolStmt
#undef MX_ENTER_VISIT_ObjCAtTryStmt
#undef MX_EXIT_VISIT_ObjCAtTryStmt
#undef MX_ENTER_VISIT_ObjCAtThrowStmt
#undef MX_EXIT_VISIT_ObjCAtThrowStmt
#undef MX_ENTER_VISIT_ObjCAtSynchronizedStmt
#undef MX_EXIT_VISIT_ObjCAtSynchronizedStmt
#undef MX_ENTER_VISIT_ObjCAtFinallyStmt
#undef MX_EXIT_VISIT_ObjCAtFinallyStmt
#undef MX_ENTER_VISIT_ObjCAtCatchStmt
#undef MX_EXIT_VISIT_ObjCAtCatchStmt
#undef MX_ENTER_VISIT_OMPExecutableDirective
#undef MX_EXIT_VISIT_OMPExecutableDirective
#undef MX_ENTER_VISIT_OMPDispatchDirective
#undef MX_EXIT_VISIT_OMPDispatchDirective
#undef MX_ENTER_VISIT_OMPDepobjDirective
#undef MX_EXIT_VISIT_OMPDepobjDirective
#undef MX_ENTER_VISIT_OMPCriticalDirective
#undef MX_EXIT_VISIT_OMPCriticalDirective
#undef MX_ENTER_VISIT_OMPCancellationPointDirective
#undef MX_EXIT_VISIT_OMPCancellationPointDirective
#undef MX_ENTER_VISIT_OMPCancelDirective
#undef MX_EXIT_VISIT_OMPCancelDirective
#undef MX_ENTER_VISIT_OMPBarrierDirective
#undef MX_EXIT_VISIT_OMPBarrierDirective
#undef MX_ENTER_VISIT_OMPAtomicDirective
#undef MX_EXIT_VISIT_OMPAtomicDirective
#undef MX_ENTER_VISIT_OMPTeamsDirective
#undef MX_EXIT_VISIT_OMPTeamsDirective
#undef MX_ENTER_VISIT_OMPTaskyieldDirective
#undef MX_EXIT_VISIT_OMPTaskyieldDirective
#undef MX_ENTER_VISIT_OMPTaskwaitDirective
#undef MX_EXIT_VISIT_OMPTaskwaitDirective
#undef MX_ENTER_VISIT_OMPTaskgroupDirective
#undef MX_EXIT_VISIT_OMPTaskgroupDirective
#undef MX_ENTER_VISIT_OMPTaskDirective
#undef MX_EXIT_VISIT_OMPTaskDirective
#undef MX_ENTER_VISIT_OMPTargetUpdateDirective
#undef MX_EXIT_VISIT_OMPTargetUpdateDirective
#undef MX_ENTER_VISIT_OMPTargetTeamsDirective
#undef MX_EXIT_VISIT_OMPTargetTeamsDirective
#undef MX_ENTER_VISIT_OMPTargetParallelDirective
#undef MX_EXIT_VISIT_OMPTargetParallelDirective
#undef MX_ENTER_VISIT_OMPTargetExitDataDirective
#undef MX_EXIT_VISIT_OMPTargetExitDataDirective
#undef MX_ENTER_VISIT_OMPTargetEnterDataDirective
#undef MX_EXIT_VISIT_OMPTargetEnterDataDirective
#undef MX_ENTER_VISIT_OMPTargetDirective
#undef MX_EXIT_VISIT_OMPTargetDirective
#undef MX_ENTER_VISIT_OMPTargetDataDirective
#undef MX_EXIT_VISIT_OMPTargetDataDirective
#undef MX_ENTER_VISIT_OMPSingleDirective
#undef MX_EXIT_VISIT_OMPSingleDirective
#undef MX_ENTER_VISIT_OMPSectionsDirective
#undef MX_EXIT_VISIT_OMPSectionsDirective
#undef MX_ENTER_VISIT_OMPSectionDirective
#undef MX_EXIT_VISIT_OMPSectionDirective
#undef MX_ENTER_VISIT_OMPScanDirective
#undef MX_EXIT_VISIT_OMPScanDirective
#undef MX_ENTER_VISIT_OMPParallelSectionsDirective
#undef MX_EXIT_VISIT_OMPParallelSectionsDirective
#undef MX_ENTER_VISIT_OMPParallelMasterDirective
#undef MX_EXIT_VISIT_OMPParallelMasterDirective
#undef MX_ENTER_VISIT_OMPParallelDirective
#undef MX_EXIT_VISIT_OMPParallelDirective
#undef MX_ENTER_VISIT_OMPOrderedDirective
#undef MX_EXIT_VISIT_OMPOrderedDirective
#undef MX_ENTER_VISIT_OMPMetaDirective
#undef MX_EXIT_VISIT_OMPMetaDirective
#undef MX_ENTER_VISIT_OMPMasterDirective
#undef MX_EXIT_VISIT_OMPMasterDirective
#undef MX_ENTER_VISIT_OMPMaskedDirective
#undef MX_EXIT_VISIT_OMPMaskedDirective
#undef MX_ENTER_VISIT_OMPLoopBasedDirective
#undef MX_EXIT_VISIT_OMPLoopBasedDirective
#undef MX_ENTER_VISIT_OMPLoopTransformationDirective
#undef MX_EXIT_VISIT_OMPLoopTransformationDirective
#undef MX_ENTER_VISIT_OMPUnrollDirective
#undef MX_EXIT_VISIT_OMPUnrollDirective
#undef MX_ENTER_VISIT_OMPTileDirective
#undef MX_EXIT_VISIT_OMPTileDirective
#undef MX_ENTER_VISIT_OMPLoopDirective
#undef MX_EXIT_VISIT_OMPLoopDirective
#undef MX_ENTER_VISIT_OMPGenericLoopDirective
#undef MX_EXIT_VISIT_OMPGenericLoopDirective
#undef MX_ENTER_VISIT_OMPForSimdDirective
#undef MX_EXIT_VISIT_OMPForSimdDirective
#undef MX_ENTER_VISIT_OMPForDirective
#undef MX_EXIT_VISIT_OMPForDirective
#undef MX_ENTER_VISIT_OMPDistributeSimdDirective
#undef MX_EXIT_VISIT_OMPDistributeSimdDirective
#undef MX_ENTER_VISIT_OMPDistributeParallelForSimdDirective
#undef MX_EXIT_VISIT_OMPDistributeParallelForSimdDirective
#undef MX_ENTER_VISIT_OMPDistributeParallelForDirective
#undef MX_EXIT_VISIT_OMPDistributeParallelForDirective
#undef MX_ENTER_VISIT_OMPDistributeDirective
#undef MX_EXIT_VISIT_OMPDistributeDirective
#undef MX_ENTER_VISIT_OMPTeamsDistributeSimdDirective
#undef MX_EXIT_VISIT_OMPTeamsDistributeSimdDirective
#undef MX_ENTER_VISIT_OMPTeamsDistributeParallelForSimdDirective
#undef MX_EXIT_VISIT_OMPTeamsDistributeParallelForSimdDirective
#undef MX_ENTER_VISIT_OMPTeamsDistributeParallelForDirective
#undef MX_EXIT_VISIT_OMPTeamsDistributeParallelForDirective
#undef MX_ENTER_VISIT_OMPTeamsDistributeDirective
#undef MX_EXIT_VISIT_OMPTeamsDistributeDirective
#undef MX_ENTER_VISIT_OMPTaskLoopSimdDirective
#undef MX_EXIT_VISIT_OMPTaskLoopSimdDirective
#undef MX_ENTER_VISIT_OMPTaskLoopDirective
#undef MX_EXIT_VISIT_OMPTaskLoopDirective
#undef MX_ENTER_VISIT_OMPTargetTeamsDistributeSimdDirective
#undef MX_EXIT_VISIT_OMPTargetTeamsDistributeSimdDirective
#undef MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective
#undef MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForSimdDirective
#undef MX_ENTER_VISIT_OMPTargetTeamsDistributeParallelForDirective
#undef MX_EXIT_VISIT_OMPTargetTeamsDistributeParallelForDirective
#undef MX_ENTER_VISIT_OMPTargetTeamsDistributeDirective
#undef MX_EXIT_VISIT_OMPTargetTeamsDistributeDirective
#undef MX_ENTER_VISIT_OMPTargetSimdDirective
#undef MX_EXIT_VISIT_OMPTargetSimdDirective
#undef MX_ENTER_VISIT_OMPTargetParallelForSimdDirective
#undef MX_EXIT_VISIT_OMPTargetParallelForSimdDirective
#undef MX_ENTER_VISIT_OMPTargetParallelForDirective
#undef MX_EXIT_VISIT_OMPTargetParallelForDirective
#undef MX_ENTER_VISIT_OMPSimdDirective
#undef MX_EXIT_VISIT_OMPSimdDirective
#undef MX_ENTER_VISIT_OMPParallelMasterTaskLoopSimdDirective
#undef MX_EXIT_VISIT_OMPParallelMasterTaskLoopSimdDirective
#undef MX_ENTER_VISIT_OMPParallelMasterTaskLoopDirective
#undef MX_EXIT_VISIT_OMPParallelMasterTaskLoopDirective
#undef MX_ENTER_VISIT_OMPParallelForSimdDirective
#undef MX_EXIT_VISIT_OMPParallelForSimdDirective
#undef MX_ENTER_VISIT_OMPParallelForDirective
#undef MX_EXIT_VISIT_OMPParallelForDirective
#undef MX_ENTER_VISIT_OMPMasterTaskLoopSimdDirective
#undef MX_EXIT_VISIT_OMPMasterTaskLoopSimdDirective
#undef MX_ENTER_VISIT_OMPMasterTaskLoopDirective
#undef MX_EXIT_VISIT_OMPMasterTaskLoopDirective
#undef MX_ENTER_VISIT_OMPInteropDirective
#undef MX_EXIT_VISIT_OMPInteropDirective
#undef MX_ENTER_VISIT_OMPFlushDirective
#undef MX_EXIT_VISIT_OMPFlushDirective
#undef MX_ENTER_VISIT_OMPCanonicalLoop
#undef MX_EXIT_VISIT_OMPCanonicalLoop
#undef MX_ENTER_VISIT_NullStmt
#undef MX_EXIT_VISIT_NullStmt
#undef MX_ENTER_VISIT_MSDependentExistsStmt
#undef MX_EXIT_VISIT_MSDependentExistsStmt
#undef MX_ENTER_VISIT_IndirectGotoStmt
#undef MX_EXIT_VISIT_IndirectGotoStmt
#undef MX_ENTER_VISIT_IfStmt
#undef MX_EXIT_VISIT_IfStmt
#undef MX_ENTER_VISIT_GotoStmt
#undef MX_EXIT_VISIT_GotoStmt
#undef MX_ENTER_VISIT_ForStmt
#undef MX_EXIT_VISIT_ForStmt
#undef MX_ENTER_VISIT_DoStmt
#undef MX_EXIT_VISIT_DoStmt
#undef MX_ENTER_VISIT_DeclStmt
#undef MX_EXIT_VISIT_DeclStmt
#undef MX_ENTER_VISIT_CoroutineBodyStmt
#undef MX_EXIT_VISIT_CoroutineBodyStmt
#undef MX_ENTER_VISIT_CoreturnStmt
#undef MX_EXIT_VISIT_CoreturnStmt
#undef MX_ENTER_VISIT_ContinueStmt
#undef MX_EXIT_VISIT_ContinueStmt
#undef MX_ENTER_VISIT_CompoundStmt
#undef MX_EXIT_VISIT_CompoundStmt
#undef MX_ENTER_VISIT_CapturedStmt
#undef MX_EXIT_VISIT_CapturedStmt
#undef MX_ENTER_VISIT_CXXTryStmt
#undef MX_EXIT_VISIT_CXXTryStmt
#undef MX_ENTER_VISIT_CXXForRangeStmt
#undef MX_EXIT_VISIT_CXXForRangeStmt
#undef MX_ENTER_VISIT_CXXCatchStmt
#undef MX_EXIT_VISIT_CXXCatchStmt
#undef MX_ENTER_VISIT_BreakStmt
#undef MX_EXIT_VISIT_BreakStmt
#undef MX_ENTER_VISIT_AsmStmt
#undef MX_EXIT_VISIT_AsmStmt
#undef MX_ENTER_VISIT_MSAsmStmt
#undef MX_EXIT_VISIT_MSAsmStmt
#undef MX_ENTER_VISIT_GCCAsmStmt
#undef MX_EXIT_VISIT_GCCAsmStmt
#undef MX_ENTER_VISIT_WhileStmt
#undef MX_EXIT_VISIT_WhileStmt
#undef MX_ENTER_VISIT_ValueStmt
#undef MX_EXIT_VISIT_ValueStmt
#undef MX_ENTER_VISIT_LabelStmt
#undef MX_EXIT_VISIT_LabelStmt
#undef MX_ENTER_VISIT_Expr
#undef MX_EXIT_VISIT_Expr
#undef MX_ENTER_VISIT_DesignatedInitUpdateExpr
#undef MX_EXIT_VISIT_DesignatedInitUpdateExpr
#undef MX_ENTER_VISIT_DesignatedInitExpr
#undef MX_EXIT_VISIT_DesignatedInitExpr
#undef MX_ENTER_VISIT_DependentScopeDeclRefExpr
#undef MX_EXIT_VISIT_DependentScopeDeclRefExpr
#undef MX_ENTER_VISIT_DependentCoawaitExpr
#undef MX_EXIT_VISIT_DependentCoawaitExpr
#undef MX_ENTER_VISIT_DeclRefExpr
#undef MX_EXIT_VISIT_DeclRefExpr
#undef MX_ENTER_VISIT_CoroutineSuspendExpr
#undef MX_EXIT_VISIT_CoroutineSuspendExpr
#undef MX_ENTER_VISIT_CoawaitExpr
#undef MX_EXIT_VISIT_CoawaitExpr
#undef MX_ENTER_VISIT_CoyieldExpr
#undef MX_EXIT_VISIT_CoyieldExpr
#undef MX_ENTER_VISIT_ConvertVectorExpr
#undef MX_EXIT_VISIT_ConvertVectorExpr
#undef MX_ENTER_VISIT_ConceptSpecializationExpr
#undef MX_EXIT_VISIT_ConceptSpecializationExpr
#undef MX_ENTER_VISIT_CompoundLiteralExpr
#undef MX_EXIT_VISIT_CompoundLiteralExpr
#undef MX_ENTER_VISIT_ChooseExpr
#undef MX_EXIT_VISIT_ChooseExpr
#undef MX_ENTER_VISIT_CharacterLiteral
#undef MX_EXIT_VISIT_CharacterLiteral
#undef MX_ENTER_VISIT_CastExpr
#undef MX_EXIT_VISIT_CastExpr
#undef MX_ENTER_VISIT_ImplicitCastExpr
#undef MX_EXIT_VISIT_ImplicitCastExpr
#undef MX_ENTER_VISIT_ExplicitCastExpr
#undef MX_EXIT_VISIT_ExplicitCastExpr
#undef MX_ENTER_VISIT_CXXNamedCastExpr
#undef MX_EXIT_VISIT_CXXNamedCastExpr
#undef MX_ENTER_VISIT_CXXDynamicCastExpr
#undef MX_EXIT_VISIT_CXXDynamicCastExpr
#undef MX_ENTER_VISIT_CXXConstCastExpr
#undef MX_EXIT_VISIT_CXXConstCastExpr
#undef MX_ENTER_VISIT_CXXAddrspaceCastExpr
#undef MX_EXIT_VISIT_CXXAddrspaceCastExpr
#undef MX_ENTER_VISIT_CXXStaticCastExpr
#undef MX_EXIT_VISIT_CXXStaticCastExpr
#undef MX_ENTER_VISIT_CXXReinterpretCastExpr
#undef MX_EXIT_VISIT_CXXReinterpretCastExpr
#undef MX_ENTER_VISIT_CXXFunctionalCastExpr
#undef MX_EXIT_VISIT_CXXFunctionalCastExpr
#undef MX_ENTER_VISIT_CStyleCastExpr
#undef MX_EXIT_VISIT_CStyleCastExpr
#undef MX_ENTER_VISIT_BuiltinBitCastExpr
#undef MX_EXIT_VISIT_BuiltinBitCastExpr
#undef MX_ENTER_VISIT_ObjCBridgedCastExpr
#undef MX_EXIT_VISIT_ObjCBridgedCastExpr
#undef MX_ENTER_VISIT_CallExpr
#undef MX_EXIT_VISIT_CallExpr
#undef MX_ENTER_VISIT_CXXOperatorCallExpr
#undef MX_EXIT_VISIT_CXXOperatorCallExpr
#undef MX_ENTER_VISIT_CXXMemberCallExpr
#undef MX_EXIT_VISIT_CXXMemberCallExpr
#undef MX_ENTER_VISIT_CUDAKernelCallExpr
#undef MX_EXIT_VISIT_CUDAKernelCallExpr
#undef MX_ENTER_VISIT_UserDefinedLiteral
#undef MX_EXIT_VISIT_UserDefinedLiteral
#undef MX_ENTER_VISIT_CXXUuidofExpr
#undef MX_EXIT_VISIT_CXXUuidofExpr
#undef MX_ENTER_VISIT_CXXUnresolvedConstructExpr
#undef MX_EXIT_VISIT_CXXUnresolvedConstructExpr
#undef MX_ENTER_VISIT_CXXTypeidExpr
#undef MX_EXIT_VISIT_CXXTypeidExpr
#undef MX_ENTER_VISIT_CXXThrowExpr
#undef MX_EXIT_VISIT_CXXThrowExpr
#undef MX_ENTER_VISIT_CXXThisExpr
#undef MX_EXIT_VISIT_CXXThisExpr
#undef MX_ENTER_VISIT_CXXStdInitializerListExpr
#undef MX_EXIT_VISIT_CXXStdInitializerListExpr
#undef MX_ENTER_VISIT_CXXScalarValueInitExpr
#undef MX_EXIT_VISIT_CXXScalarValueInitExpr
#undef MX_ENTER_VISIT_CXXRewrittenBinaryOperator
#undef MX_EXIT_VISIT_CXXRewrittenBinaryOperator
#undef MX_ENTER_VISIT_CXXPseudoDestructorExpr
#undef MX_EXIT_VISIT_CXXPseudoDestructorExpr
#undef MX_ENTER_VISIT_CXXNullPtrLiteralExpr
#undef MX_EXIT_VISIT_CXXNullPtrLiteralExpr
#undef MX_ENTER_VISIT_CXXNoexceptExpr
#undef MX_EXIT_VISIT_CXXNoexceptExpr
#undef MX_ENTER_VISIT_CXXNewExpr
#undef MX_EXIT_VISIT_CXXNewExpr
#undef MX_ENTER_VISIT_CXXInheritedCtorInitExpr
#undef MX_EXIT_VISIT_CXXInheritedCtorInitExpr
#undef MX_ENTER_VISIT_CXXFoldExpr
#undef MX_EXIT_VISIT_CXXFoldExpr
#undef MX_ENTER_VISIT_CXXDependentScopeMemberExpr
#undef MX_EXIT_VISIT_CXXDependentScopeMemberExpr
#undef MX_ENTER_VISIT_CXXDeleteExpr
#undef MX_EXIT_VISIT_CXXDeleteExpr
#undef MX_ENTER_VISIT_CXXDefaultInitExpr
#undef MX_EXIT_VISIT_CXXDefaultInitExpr
#undef MX_ENTER_VISIT_CXXDefaultArgExpr
#undef MX_EXIT_VISIT_CXXDefaultArgExpr
#undef MX_ENTER_VISIT_CXXConstructExpr
#undef MX_EXIT_VISIT_CXXConstructExpr
#undef MX_ENTER_VISIT_CXXTemporaryObjectExpr
#undef MX_EXIT_VISIT_CXXTemporaryObjectExpr
#undef MX_ENTER_VISIT_CXXBoolLiteralExpr
#undef MX_EXIT_VISIT_CXXBoolLiteralExpr
#undef MX_ENTER_VISIT_CXXBindTemporaryExpr
#undef MX_EXIT_VISIT_CXXBindTemporaryExpr
#undef MX_ENTER_VISIT_BlockExpr
#undef MX_EXIT_VISIT_BlockExpr
#undef MX_ENTER_VISIT_BinaryOperator
#undef MX_EXIT_VISIT_BinaryOperator
#undef MX_ENTER_VISIT_CompoundAssignOperator
#undef MX_EXIT_VISIT_CompoundAssignOperator
#undef MX_ENTER_VISIT_AtomicExpr
#undef MX_EXIT_VISIT_AtomicExpr
#undef MX_ENTER_VISIT_AsTypeExpr
#undef MX_EXIT_VISIT_AsTypeExpr
#undef MX_ENTER_VISIT_ArrayTypeTraitExpr
#undef MX_EXIT_VISIT_ArrayTypeTraitExpr
#undef MX_ENTER_VISIT_ArraySubscriptExpr
#undef MX_EXIT_VISIT_ArraySubscriptExpr
#undef MX_ENTER_VISIT_ArrayInitLoopExpr
#undef MX_EXIT_VISIT_ArrayInitLoopExpr
#undef MX_ENTER_VISIT_ArrayInitIndexExpr
#undef MX_EXIT_VISIT_ArrayInitIndexExpr
#undef MX_ENTER_VISIT_AddrLabelExpr
#undef MX_EXIT_VISIT_AddrLabelExpr
#undef MX_ENTER_VISIT_AbstractConditionalOperator
#undef MX_EXIT_VISIT_AbstractConditionalOperator
#undef MX_ENTER_VISIT_ConditionalOperator
#undef MX_EXIT_VISIT_ConditionalOperator
#undef MX_ENTER_VISIT_BinaryConditionalOperator
#undef MX_EXIT_VISIT_BinaryConditionalOperator
#undef MX_ENTER_VISIT_VAArgExpr
#undef MX_EXIT_VISIT_VAArgExpr
#undef MX_ENTER_VISIT_UnaryOperator
#undef MX_EXIT_VISIT_UnaryOperator
#undef MX_ENTER_VISIT_UnaryExprOrTypeTraitExpr
#undef MX_EXIT_VISIT_UnaryExprOrTypeTraitExpr
#undef MX_ENTER_VISIT_TypoExpr
#undef MX_EXIT_VISIT_TypoExpr
#undef MX_ENTER_VISIT_TypeTraitExpr
#undef MX_EXIT_VISIT_TypeTraitExpr
#undef MX_ENTER_VISIT_SubstNonTypeTemplateParmPackExpr
#undef MX_EXIT_VISIT_SubstNonTypeTemplateParmPackExpr
#undef MX_ENTER_VISIT_SubstNonTypeTemplateParmExpr
#undef MX_EXIT_VISIT_SubstNonTypeTemplateParmExpr
#undef MX_ENTER_VISIT_StringLiteral
#undef MX_EXIT_VISIT_StringLiteral
#undef MX_ENTER_VISIT_StmtExpr
#undef MX_EXIT_VISIT_StmtExpr
#undef MX_ENTER_VISIT_SourceLocExpr
#undef MX_EXIT_VISIT_SourceLocExpr
#undef MX_ENTER_VISIT_SizeOfPackExpr
#undef MX_EXIT_VISIT_SizeOfPackExpr
#undef MX_ENTER_VISIT_ShuffleVectorExpr
#undef MX_EXIT_VISIT_ShuffleVectorExpr
#undef MX_ENTER_VISIT_SYCLUniqueStableNameExpr
#undef MX_EXIT_VISIT_SYCLUniqueStableNameExpr
#undef MX_ENTER_VISIT_RequiresExpr
#undef MX_EXIT_VISIT_RequiresExpr
#undef MX_ENTER_VISIT_RecoveryExpr
#undef MX_EXIT_VISIT_RecoveryExpr
#undef MX_ENTER_VISIT_PseudoObjectExpr
#undef MX_EXIT_VISIT_PseudoObjectExpr
#undef MX_ENTER_VISIT_PredefinedExpr
#undef MX_EXIT_VISIT_PredefinedExpr
#undef MX_ENTER_VISIT_ParenListExpr
#undef MX_EXIT_VISIT_ParenListExpr
#undef MX_ENTER_VISIT_ParenExpr
#undef MX_EXIT_VISIT_ParenExpr
#undef MX_ENTER_VISIT_PackExpansionExpr
#undef MX_EXIT_VISIT_PackExpansionExpr
#undef MX_ENTER_VISIT_OverloadExpr
#undef MX_EXIT_VISIT_OverloadExpr
#undef MX_ENTER_VISIT_UnresolvedMemberExpr
#undef MX_EXIT_VISIT_UnresolvedMemberExpr
#undef MX_ENTER_VISIT_UnresolvedLookupExpr
#undef MX_EXIT_VISIT_UnresolvedLookupExpr
#undef MX_ENTER_VISIT_OpaqueValueExpr
#undef MX_EXIT_VISIT_OpaqueValueExpr
#undef MX_ENTER_VISIT_OffsetOfExpr
#undef MX_EXIT_VISIT_OffsetOfExpr
#undef MX_ENTER_VISIT_ObjCSubscriptRefExpr
#undef MX_EXIT_VISIT_ObjCSubscriptRefExpr
#undef MX_ENTER_VISIT_ObjCStringLiteral
#undef MX_EXIT_VISIT_ObjCStringLiteral
#undef MX_ENTER_VISIT_ObjCSelectorExpr
#undef MX_EXIT_VISIT_ObjCSelectorExpr
#undef MX_ENTER_VISIT_ObjCProtocolExpr
#undef MX_EXIT_VISIT_ObjCProtocolExpr
#undef MX_ENTER_VISIT_ObjCPropertyRefExpr
#undef MX_EXIT_VISIT_ObjCPropertyRefExpr
#undef MX_ENTER_VISIT_ObjCMessageExpr
#undef MX_EXIT_VISIT_ObjCMessageExpr
#undef MX_ENTER_VISIT_ObjCIvarRefExpr
#undef MX_EXIT_VISIT_ObjCIvarRefExpr
#undef MX_ENTER_VISIT_ObjCIsaExpr
#undef MX_EXIT_VISIT_ObjCIsaExpr
#undef MX_ENTER_VISIT_ObjCIndirectCopyRestoreExpr
#undef MX_EXIT_VISIT_ObjCIndirectCopyRestoreExpr
#undef MX_ENTER_VISIT_ObjCEncodeExpr
#undef MX_EXIT_VISIT_ObjCEncodeExpr
#undef MX_ENTER_VISIT_ObjCDictionaryLiteral
#undef MX_EXIT_VISIT_ObjCDictionaryLiteral
#undef MX_ENTER_VISIT_ObjCBoxedExpr
#undef MX_EXIT_VISIT_ObjCBoxedExpr
#undef MX_ENTER_VISIT_ObjCBoolLiteralExpr
#undef MX_EXIT_VISIT_ObjCBoolLiteralExpr
#undef MX_ENTER_VISIT_ObjCAvailabilityCheckExpr
#undef MX_EXIT_VISIT_ObjCAvailabilityCheckExpr
#undef MX_ENTER_VISIT_ObjCArrayLiteral
#undef MX_EXIT_VISIT_ObjCArrayLiteral
#undef MX_ENTER_VISIT_OMPIteratorExpr
#undef MX_EXIT_VISIT_OMPIteratorExpr
#undef MX_ENTER_VISIT_OMPArrayShapingExpr
#undef MX_EXIT_VISIT_OMPArrayShapingExpr
#undef MX_ENTER_VISIT_OMPArraySectionExpr
#undef MX_EXIT_VISIT_OMPArraySectionExpr
#undef MX_ENTER_VISIT_NoInitExpr
#undef MX_EXIT_VISIT_NoInitExpr
#undef MX_ENTER_VISIT_MemberExpr
#undef MX_EXIT_VISIT_MemberExpr
#undef MX_ENTER_VISIT_MatrixSubscriptExpr
#undef MX_EXIT_VISIT_MatrixSubscriptExpr
#undef MX_ENTER_VISIT_MaterializeTemporaryExpr
#undef MX_EXIT_VISIT_MaterializeTemporaryExpr
#undef MX_ENTER_VISIT_MSPropertySubscriptExpr
#undef MX_EXIT_VISIT_MSPropertySubscriptExpr
#undef MX_ENTER_VISIT_MSPropertyRefExpr
#undef MX_EXIT_VISIT_MSPropertyRefExpr
#undef MX_ENTER_VISIT_LambdaExpr
#undef MX_EXIT_VISIT_LambdaExpr
#undef MX_ENTER_VISIT_IntegerLiteral
#undef MX_EXIT_VISIT_IntegerLiteral
#undef MX_ENTER_VISIT_InitListExpr
#undef MX_EXIT_VISIT_InitListExpr
#undef MX_ENTER_VISIT_ImplicitValueInitExpr
#undef MX_EXIT_VISIT_ImplicitValueInitExpr
#undef MX_ENTER_VISIT_ImaginaryLiteral
#undef MX_EXIT_VISIT_ImaginaryLiteral
#undef MX_ENTER_VISIT_GenericSelectionExpr
#undef MX_EXIT_VISIT_GenericSelectionExpr
#undef MX_ENTER_VISIT_GNUNullExpr
#undef MX_EXIT_VISIT_GNUNullExpr
#undef MX_ENTER_VISIT_FunctionParmPackExpr
#undef MX_EXIT_VISIT_FunctionParmPackExpr
#undef MX_ENTER_VISIT_FullExpr
#undef MX_EXIT_VISIT_FullExpr
#undef MX_ENTER_VISIT_ExprWithCleanups
#undef MX_EXIT_VISIT_ExprWithCleanups
#undef MX_ENTER_VISIT_ConstantExpr
#undef MX_EXIT_VISIT_ConstantExpr
#undef MX_ENTER_VISIT_FloatingLiteral
#undef MX_EXIT_VISIT_FloatingLiteral
#undef MX_ENTER_VISIT_FixedPointLiteral
#undef MX_EXIT_VISIT_FixedPointLiteral
#undef MX_ENTER_VISIT_ExtVectorElementExpr
#undef MX_EXIT_VISIT_ExtVectorElementExpr
#undef MX_ENTER_VISIT_ExpressionTraitExpr
#undef MX_EXIT_VISIT_ExpressionTraitExpr
#undef MX_ENTER_VISIT_AttributedStmt
#undef MX_EXIT_VISIT_AttributedStmt
#undef MX_ENTER_VISIT_SwitchStmt
#undef MX_EXIT_VISIT_SwitchStmt
#undef MX_ENTER_VISIT_SwitchCase
#undef MX_EXIT_VISIT_SwitchCase
#undef MX_ENTER_VISIT_DefaultStmt
#undef MX_EXIT_VISIT_DefaultStmt
#undef MX_ENTER_VISIT_CaseStmt
#undef MX_EXIT_VISIT_CaseStmt
#undef MX_ENTER_VISIT_Decl
#undef MX_EXIT_VISIT_Decl
#undef MX_ENTER_VISIT_ClassScopeFunctionSpecializationDecl
#undef MX_EXIT_VISIT_ClassScopeFunctionSpecializationDecl
#undef MX_ENTER_VISIT_CapturedDecl
#undef MX_EXIT_VISIT_CapturedDecl
#undef MX_ENTER_VISIT_BlockDecl
#undef MX_EXIT_VISIT_BlockDecl
#undef MX_ENTER_VISIT_AccessSpecDecl
#undef MX_EXIT_VISIT_AccessSpecDecl
#undef MX_ENTER_VISIT_OMPDeclarativeDirectiveDecl
#undef MX_EXIT_VISIT_OMPDeclarativeDirectiveDecl
#undef MX_ENTER_VISIT_OMPThreadPrivateDecl
#undef MX_EXIT_VISIT_OMPThreadPrivateDecl
#undef MX_ENTER_VISIT_OMPRequiresDecl
#undef MX_EXIT_VISIT_OMPRequiresDecl
#undef MX_ENTER_VISIT_OMPAllocateDecl
#undef MX_EXIT_VISIT_OMPAllocateDecl
#undef MX_ENTER_VISIT_TranslationUnitDecl
#undef MX_EXIT_VISIT_TranslationUnitDecl
#undef MX_ENTER_VISIT_StaticAssertDecl
#undef MX_EXIT_VISIT_StaticAssertDecl
#undef MX_ENTER_VISIT_RequiresExprBodyDecl
#undef MX_EXIT_VISIT_RequiresExprBodyDecl
#undef MX_ENTER_VISIT_PragmaDetectMismatchDecl
#undef MX_EXIT_VISIT_PragmaDetectMismatchDecl
#undef MX_ENTER_VISIT_PragmaCommentDecl
#undef MX_EXIT_VISIT_PragmaCommentDecl
#undef MX_ENTER_VISIT_ObjCPropertyImplDecl
#undef MX_EXIT_VISIT_ObjCPropertyImplDecl
#undef MX_ENTER_VISIT_NamedDecl
#undef MX_EXIT_VISIT_NamedDecl
#undef MX_ENTER_VISIT_LabelDecl
#undef MX_EXIT_VISIT_LabelDecl
#undef MX_ENTER_VISIT_BaseUsingDecl
#undef MX_EXIT_VISIT_BaseUsingDecl
#undef MX_ENTER_VISIT_UsingEnumDecl
#undef MX_EXIT_VISIT_UsingEnumDecl
#undef MX_ENTER_VISIT_UsingDecl
#undef MX_EXIT_VISIT_UsingDecl
#undef MX_ENTER_VISIT_ValueDecl
#undef MX_EXIT_VISIT_ValueDecl
#undef MX_ENTER_VISIT_UnresolvedUsingValueDecl
#undef MX_EXIT_VISIT_UnresolvedUsingValueDecl
#undef MX_ENTER_VISIT_TemplateParamObjectDecl
#undef MX_EXIT_VISIT_TemplateParamObjectDecl
#undef MX_ENTER_VISIT_OMPDeclareReductionDecl
#undef MX_EXIT_VISIT_OMPDeclareReductionDecl
#undef MX_ENTER_VISIT_MSGuidDecl
#undef MX_EXIT_VISIT_MSGuidDecl
#undef MX_ENTER_VISIT_IndirectFieldDecl
#undef MX_EXIT_VISIT_IndirectFieldDecl
#undef MX_ENTER_VISIT_EnumConstantDecl
#undef MX_EXIT_VISIT_EnumConstantDecl
#undef MX_ENTER_VISIT_DeclaratorDecl
#undef MX_EXIT_VISIT_DeclaratorDecl
#undef MX_ENTER_VISIT_VarDecl
#undef MX_EXIT_VISIT_VarDecl
#undef MX_ENTER_VISIT_ParmVarDecl
#undef MX_EXIT_VISIT_ParmVarDecl
#undef MX_ENTER_VISIT_OMPCapturedExprDecl
#undef MX_EXIT_VISIT_OMPCapturedExprDecl
#undef MX_ENTER_VISIT_ImplicitParamDecl
#undef MX_EXIT_VISIT_ImplicitParamDecl
#undef MX_ENTER_VISIT_DecompositionDecl
#undef MX_EXIT_VISIT_DecompositionDecl
#undef MX_ENTER_VISIT_VarTemplateSpecializationDecl
#undef MX_EXIT_VISIT_VarTemplateSpecializationDecl
#undef MX_ENTER_VISIT_VarTemplatePartialSpecializationDecl
#undef MX_EXIT_VISIT_VarTemplatePartialSpecializationDecl
#undef MX_ENTER_VISIT_NonTypeTemplateParmDecl
#undef MX_EXIT_VISIT_NonTypeTemplateParmDecl
#undef MX_ENTER_VISIT_MSPropertyDecl
#undef MX_EXIT_VISIT_MSPropertyDecl
#undef MX_ENTER_VISIT_FunctionDecl
#undef MX_EXIT_VISIT_FunctionDecl
#undef MX_ENTER_VISIT_CXXMethodDecl
#undef MX_EXIT_VISIT_CXXMethodDecl
#undef MX_ENTER_VISIT_CXXDestructorDecl
#undef MX_EXIT_VISIT_CXXDestructorDecl
#undef MX_ENTER_VISIT_CXXConversionDecl
#undef MX_EXIT_VISIT_CXXConversionDecl
#undef MX_ENTER_VISIT_CXXConstructorDecl
#undef MX_EXIT_VISIT_CXXConstructorDecl
#undef MX_ENTER_VISIT_CXXDeductionGuideDecl
#undef MX_EXIT_VISIT_CXXDeductionGuideDecl
#undef MX_ENTER_VISIT_FieldDecl
#undef MX_EXIT_VISIT_FieldDecl
#undef MX_ENTER_VISIT_ObjCIvarDecl
#undef MX_EXIT_VISIT_ObjCIvarDecl
#undef MX_ENTER_VISIT_ObjCAtDefsFieldDecl
#undef MX_EXIT_VISIT_ObjCAtDefsFieldDecl
#undef MX_ENTER_VISIT_BindingDecl
#undef MX_EXIT_VISIT_BindingDecl
#undef MX_ENTER_VISIT_OMPDeclarativeDirectiveValueDecl
#undef MX_EXIT_VISIT_OMPDeclarativeDirectiveValueDecl
#undef MX_ENTER_VISIT_OMPDeclareMapperDecl
#undef MX_EXIT_VISIT_OMPDeclareMapperDecl
#undef MX_ENTER_VISIT_UsingShadowDecl
#undef MX_EXIT_VISIT_UsingShadowDecl
#undef MX_ENTER_VISIT_ConstructorUsingShadowDecl
#undef MX_EXIT_VISIT_ConstructorUsingShadowDecl
#undef MX_ENTER_VISIT_UsingPackDecl
#undef MX_EXIT_VISIT_UsingPackDecl
#undef MX_ENTER_VISIT_UsingDirectiveDecl
#undef MX_EXIT_VISIT_UsingDirectiveDecl
#undef MX_ENTER_VISIT_UnresolvedUsingIfExistsDecl
#undef MX_EXIT_VISIT_UnresolvedUsingIfExistsDecl
#undef MX_ENTER_VISIT_TypeDecl
#undef MX_EXIT_VISIT_TypeDecl
#undef MX_ENTER_VISIT_TemplateTypeParmDecl
#undef MX_EXIT_VISIT_TemplateTypeParmDecl
#undef MX_ENTER_VISIT_TagDecl
#undef MX_EXIT_VISIT_TagDecl
#undef MX_ENTER_VISIT_RecordDecl
#undef MX_EXIT_VISIT_RecordDecl
#undef MX_ENTER_VISIT_CXXRecordDecl
#undef MX_EXIT_VISIT_CXXRecordDecl
#undef MX_ENTER_VISIT_ClassTemplateSpecializationDecl
#undef MX_EXIT_VISIT_ClassTemplateSpecializationDecl
#undef MX_ENTER_VISIT_ClassTemplatePartialSpecializationDecl
#undef MX_EXIT_VISIT_ClassTemplatePartialSpecializationDecl
#undef MX_ENTER_VISIT_EnumDecl
#undef MX_EXIT_VISIT_EnumDecl
#undef MX_ENTER_VISIT_UnresolvedUsingTypenameDecl
#undef MX_EXIT_VISIT_UnresolvedUsingTypenameDecl
#undef MX_ENTER_VISIT_TypedefNameDecl
#undef MX_EXIT_VISIT_TypedefNameDecl
#undef MX_ENTER_VISIT_TypedefDecl
#undef MX_EXIT_VISIT_TypedefDecl
#undef MX_ENTER_VISIT_TypeAliasDecl
#undef MX_EXIT_VISIT_TypeAliasDecl
#undef MX_ENTER_VISIT_ObjCTypeParamDecl
#undef MX_EXIT_VISIT_ObjCTypeParamDecl
#undef MX_ENTER_VISIT_TemplateDecl
#undef MX_EXIT_VISIT_TemplateDecl
#undef MX_ENTER_VISIT_RedeclarableTemplateDecl
#undef MX_EXIT_VISIT_RedeclarableTemplateDecl
#undef MX_ENTER_VISIT_FunctionTemplateDecl
#undef MX_EXIT_VISIT_FunctionTemplateDecl
#undef MX_ENTER_VISIT_ClassTemplateDecl
#undef MX_EXIT_VISIT_ClassTemplateDecl
#undef MX_ENTER_VISIT_VarTemplateDecl
#undef MX_EXIT_VISIT_VarTemplateDecl
#undef MX_ENTER_VISIT_TypeAliasTemplateDecl
#undef MX_EXIT_VISIT_TypeAliasTemplateDecl
#undef MX_ENTER_VISIT_ConceptDecl
#undef MX_EXIT_VISIT_ConceptDecl
#undef MX_ENTER_VISIT_BuiltinTemplateDecl
#undef MX_EXIT_VISIT_BuiltinTemplateDecl
#undef MX_ENTER_VISIT_TemplateTemplateParmDecl
#undef MX_EXIT_VISIT_TemplateTemplateParmDecl
#undef MX_ENTER_VISIT_ObjCPropertyDecl
#undef MX_EXIT_VISIT_ObjCPropertyDecl
#undef MX_ENTER_VISIT_ObjCMethodDecl
#undef MX_EXIT_VISIT_ObjCMethodDecl
#undef MX_ENTER_VISIT_ObjCContainerDecl
#undef MX_EXIT_VISIT_ObjCContainerDecl
#undef MX_ENTER_VISIT_ObjCCategoryDecl
#undef MX_EXIT_VISIT_ObjCCategoryDecl
#undef MX_ENTER_VISIT_ObjCProtocolDecl
#undef MX_EXIT_VISIT_ObjCProtocolDecl
#undef MX_ENTER_VISIT_ObjCInterfaceDecl
#undef MX_EXIT_VISIT_ObjCInterfaceDecl
#undef MX_ENTER_VISIT_ObjCImplDecl
#undef MX_EXIT_VISIT_ObjCImplDecl
#undef MX_ENTER_VISIT_ObjCCategoryImplDecl
#undef MX_EXIT_VISIT_ObjCCategoryImplDecl
#undef MX_ENTER_VISIT_ObjCImplementationDecl
#undef MX_EXIT_VISIT_ObjCImplementationDecl
#undef MX_ENTER_VISIT_ObjCCompatibleAliasDecl
#undef MX_EXIT_VISIT_ObjCCompatibleAliasDecl
#undef MX_ENTER_VISIT_NamespaceDecl
#undef MX_EXIT_VISIT_NamespaceDecl
#undef MX_ENTER_VISIT_NamespaceAliasDecl
#undef MX_EXIT_VISIT_NamespaceAliasDecl
#undef MX_ENTER_VISIT_LinkageSpecDecl
#undef MX_EXIT_VISIT_LinkageSpecDecl
#undef MX_ENTER_VISIT_LifetimeExtendedTemporaryDecl
#undef MX_EXIT_VISIT_LifetimeExtendedTemporaryDecl
#undef MX_ENTER_VISIT_ImportDecl
#undef MX_EXIT_VISIT_ImportDecl
#undef MX_ENTER_VISIT_FriendTemplateDecl
#undef MX_EXIT_VISIT_FriendTemplateDecl
#undef MX_ENTER_VISIT_FriendDecl
#undef MX_EXIT_VISIT_FriendDecl
#undef MX_ENTER_VISIT_FileScopeAsmDecl
#undef MX_EXIT_VISIT_FileScopeAsmDecl
#undef MX_ENTER_VISIT_ExternCContextDecl
#undef MX_EXIT_VISIT_ExternCContextDecl
#undef MX_ENTER_VISIT_ExportDecl
#undef MX_EXIT_VISIT_ExportDecl
#undef MX_ENTER_VISIT_EmptyDecl
#undef MX_EXIT_VISIT_EmptyDecl
#undef MX_APPLY_METHOD
#undef MX_APPLY_FUNC
#undef MX_VISIT_BOOL
#undef MX_VISIT_INT
#undef MX_VISIT_ENUM
#undef MX_VISIT_TEXT
#undef MX_VISIT_PATH
#undef MX_VISIT_OPTIONAL_BOOL
#undef MX_VISIT_OPTIONAL_INT
#undef MX_VISIT_OPTIONAL_ENUM
#undef MX_VISIT_OPTIONAL_TEXT
#undef MX_VISIT_OPTIONAL_PATH
#undef MX_VISIT_BOOL_LIST
#undef MX_VISIT_INT_LIST
#undef MX_VISIT_ENUM_LIST
#undef MX_VISIT_TEXT_LIST
#undef MX_VISIT_PATH_LIST
#undef MX_VISIT_OPTIONAL_BOOL_LIST
#undef MX_VISIT_OPTIONAL_INT_LIST
#undef MX_VISIT_OPTIONAL_ENUM_LIST
#undef MX_VISIT_OPTIONAL_TEXT_LIST
#undef MX_VISIT_OPTIONAL_PATH_LIST
#undef MX_VISIT_ENTITY
#undef MX_VISIT_ENTITY_LIST
#undef MX_VISIT_OPTIONAL_ENTITY
#undef MX_VISIT_OPTIONAL_ENTITY_LIST
#undef MX_VISIT_PSEUDO
#undef MX_VISIT_PSEUDO_LIST
#undef MX_VISIT_OPTIONAL_PSEUDO
#undef MX_VISIT_OPTIONAL_PSEUDO_LIST
#undef MX_VISIT_BASE
#undef MX_VISIT_DECL_LINK
#undef MX_VISIT_STMT_LINK
#undef MX_BEGIN_VISIT_DECL
#undef MX_BEGIN_VISIT_STMT
#undef MX_BEGIN_VISIT_TYPE
#undef MX_BEGIN_VISIT_ABSTRACT_DECL
#undef MX_BEGIN_VISIT_ABSTRACT_STMT
#undef MX_BEGIN_VISIT_ABSTRACT_TYPE
#undef MX_BEGIN_VISIT_PSEUDO
#undef MX_VISIT_PSEUDO_KIND
#undef MX_END_VISIT_DECL
#undef MX_END_VISIT_STMT
#undef MX_END_VISIT_TYPE
#undef MX_END_VISIT_PSEUDO
