// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

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
  MX_VISIT_PSEUDO_KIND(TemplateParameterList, getVal0, setVal0)
  MX_VISIT_INT(TemplateParameterList, num_parameters, getVal1, setVal1, initVal1, NumParameters, unsigned, NthPseudo)
  MX_VISIT_INT(TemplateParameterList, num_required_parameters, getVal2, setVal2, initVal2, NumRequiredParameters, unsigned, NthPseudo)
  MX_VISIT_INT(TemplateParameterList, depth, getVal3, setVal3, initVal3, Depth, unsigned, NthPseudo)
  MX_VISIT_BOOL(TemplateParameterList, has_unexpanded_parameter_pack, getVal4, setVal4, initVal4, HasUnexpandedParameterPack, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateParameterList, has_parameter_pack, getVal5, setVal5, initVal5, HasParameterPack, bool, NthPseudo)
  MX_VISIT_OPTIONAL_ENTITY(TemplateParameterList, requires_clause, getVal6, setVal6, initVal6, RequiresClause, Expr, NthPseudo, StmtUseSelector::REQUIRES_CLAUSE)
  MX_VISIT_ENTITY(TemplateParameterList, template_keyword_token, getVal8, setVal8, initVal8, TemplateKeywordToken, Token, NthPseudo, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_ENTITY(TemplateParameterList, left_angle_token, getVal9, setVal9, initVal9, LeftAngleToken, Token, NthPseudo, TokenUseSelector::LEFT_ANGLE_TOKEN)
  MX_VISIT_ENTITY(TemplateParameterList, right_angle_token, getVal10, setVal10, initVal10, RightAngleToken, Token, NthPseudo, TokenUseSelector::RIGHT_ANGLE_TOKEN)
  MX_VISIT_ENTITY_LIST(TemplateParameterList, parameters, getVal13, setVal13, initVal13, Parameters, NamedDecl, NthPseudo)
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
  MX_VISIT_PSEUDO_KIND(TemplateArgument, getVal0, setVal0)
  MX_VISIT_ENUM(TemplateArgument, kind, getVal14, setVal14, initVal14, Kind, TemplateArgumentKind, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_null, getVal4, setVal4, initVal4, IsNull, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_dependent, getVal5, setVal5, initVal5, IsDependent, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_instantiation_dependent, getVal7, setVal7, initVal7, IsInstantiationDependent, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, contains_unexpanded_parameter_pack, getVal15, setVal15, initVal15, ContainsUnexpandedParameterPack, bool, NthPseudo)
  MX_VISIT_BOOL(TemplateArgument, is_pack_expansion, getVal16, setVal16, initVal16, IsPackExpansion, bool, NthPseudo)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, as_declaration, getVal6, setVal6, initVal6, AsDeclaration, ValueDecl, NthPseudo, DeclUseSelector::AS_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, as_type, getVal8, setVal8, initVal8, AsType, Type, NthPseudo, TypeUseSelector::AS_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, parameter_type_for_declaration, getVal9, setVal9, initVal9, ParameterTypeForDeclaration, Type, NthPseudo, TypeUseSelector::PARAMETER_TYPE_FOR_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(TemplateArgument, null_pointer_type, getVal10, setVal10, initVal10, NullPointerType, Type, NthPseudo, TypeUseSelector::NULL_POINTER_TYPE)
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
  MX_VISIT_PSEUDO_KIND(CXXBaseSpecifier, getVal0, setVal0)
  MX_VISIT_ENTITY(CXXBaseSpecifier, base_type_token, getVal9, setVal9, initVal9, BaseTypeToken, Token, NthPseudo, TokenUseSelector::BASE_TYPE_TOKEN)
  MX_VISIT_BOOL(CXXBaseSpecifier, is_virtual, getVal4, setVal4, initVal4, IsVirtual, bool, NthPseudo)
  MX_VISIT_ENUM(CXXBaseSpecifier, base_kind, getVal14, setVal14, initVal14, BaseKind, TagTypeKind, NthPseudo)
  MX_VISIT_BOOL(CXXBaseSpecifier, is_pack_expansion, getVal5, setVal5, initVal5, IsPackExpansion, bool, NthPseudo)
  MX_VISIT_BOOL(CXXBaseSpecifier, constructors_are_inherited, getVal7, setVal7, initVal7, ConstructorsAreInherited, bool, NthPseudo)
  MX_VISIT_OPTIONAL_ENTITY(CXXBaseSpecifier, ellipsis_token, getVal10, setVal10, initVal10, EllipsisToken, Token, NthPseudo, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENUM(CXXBaseSpecifier, semantic_access_specifier, getVal21, setVal21, initVal21, SemanticAccessSpecifier, AccessSpecifier, NthPseudo)
  MX_VISIT_ENUM(CXXBaseSpecifier, lexical_access_specifier, getVal22, setVal22, initVal22, LexicalAccessSpecifier, AccessSpecifier, NthPseudo)
  MX_VISIT_ENTITY(CXXBaseSpecifier, base_type, getVal11, setVal11, initVal11, BaseType, Type, NthPseudo, TypeUseSelector::BASE_TYPE)
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
  MX_VISIT_BOOL(Type, is_qualified, getVal0, setVal0, initVal0, IsQualified, bool, NthType)
  MX_VISIT_ENTITY(Type, unqualified_type, getVal1, setVal1, initVal1, UnqualifiedType, Type, NthType, TypeUseSelector::UNQUALIFIED_TYPE)
  MX_VISIT_BOOL(Type, accepts_obj_c_type_parameters, getVal2, setVal2, initVal2, AcceptsObjCTypeParameters, bool, NthType)
  MX_VISIT_BOOL(Type, can_decay_to_pointer_type, getVal3, setVal3, initVal3, CanDecayToPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, can_have_nullability, getVal4, setVal4, initVal4, CanHaveNullability, bool, NthType)
  MX_VISIT_BOOL(Type, contains_errors, getVal5, setVal5, initVal5, ContainsErrors, bool, NthType)
  MX_VISIT_BOOL(Type, contains_unexpanded_parameter_pack, getVal6, setVal6, initVal6, ContainsUnexpandedParameterPack, bool, NthType)
  MX_VISIT_OPTIONAL_ENTITY(Type, array_element_type_no_type_qualified, getVal7, setVal7, initVal7, ArrayElementTypeNoTypeQualified, Type, NthType, TypeUseSelector::ARRAY_ELEMENT_TYPE_NO_TYPE_QUALIFIED)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_cxx_record_declaration, getVal9, setVal9, initVal9, AsCXXRecordDeclaration, CXXRecordDecl, NthType, DeclUseSelector::AS_CXX_RECORD_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_complex_integer_type, getVal11, setVal11, initVal11, AsComplexIntegerType, ComplexType, NthType, TypeUseSelector::AS_COMPLEX_INTEGER_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_interface_pointer_type, getVal13, setVal13, initVal13, AsObjCInterfacePointerType, ObjCObjectPointerType, NthType, TypeUseSelector::AS_OBJ_C_INTERFACE_POINTER_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_interface_type, getVal15, setVal15, initVal15, AsObjCInterfaceType, ObjCObjectType, NthType, TypeUseSelector::AS_OBJ_C_INTERFACE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_qualified_class_type, getVal17, setVal17, initVal17, AsObjCQualifiedClassType, ObjCObjectPointerType, NthType, TypeUseSelector::AS_OBJ_C_QUALIFIED_CLASS_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_qualified_id_type, getVal19, setVal19, initVal19, AsObjCQualifiedIdType, ObjCObjectPointerType, NthType, TypeUseSelector::AS_OBJ_C_QUALIFIED_ID_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_obj_c_qualified_interface_type, getVal21, setVal21, initVal21, AsObjCQualifiedInterfaceType, ObjCObjectType, NthType, TypeUseSelector::AS_OBJ_C_QUALIFIED_INTERFACE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_placeholder_type, getVal23, setVal23, initVal23, AsPlaceholderType, BuiltinType, NthType, TypeUseSelector::AS_PLACEHOLDER_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_record_declaration, getVal25, setVal25, initVal25, AsRecordDeclaration, RecordDecl, NthType, DeclUseSelector::AS_RECORD_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_structure_type, getVal27, setVal27, initVal27, AsStructureType, RecordType, NthType, TypeUseSelector::AS_STRUCTURE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_tag_declaration, getVal29, setVal29, initVal29, AsTagDeclaration, TagDecl, NthType, DeclUseSelector::AS_TAG_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, as_union_type, getVal31, setVal31, initVal31, AsUnionType, RecordType, NthType, TypeUseSelector::AS_UNION_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, contained_auto_type, getVal33, setVal33, initVal33, ContainedAutoType, AutoType, NthType, TypeUseSelector::CONTAINED_AUTO_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, contained_deduced_type, getVal35, setVal35, initVal35, ContainedDeducedType, DeducedType, NthType, TypeUseSelector::CONTAINED_DEDUCED_TYPE)
  MX_VISIT_ENUM(Type, linkage, getVal37, setVal37, initVal37, Linkage, Linkage, NthType)
  MX_VISIT_ENTITY(Type, locally_unqualified_single_step_desugared_type, getVal38, setVal38, initVal38, LocallyUnqualifiedSingleStepDesugaredType, Type, NthType, TypeUseSelector::LOCALLY_UNQUALIFIED_SINGLE_STEP_DESUGARED_TYPE)
  MX_VISIT_OPTIONAL_ENUM(Type, nullability, getVal39, setVal39, initVal39, Nullability, NullabilityKind, NthType)
  MX_VISIT_OPTIONAL_ENTITY(Type, pointee_cxx_record_declaration, getVal41, setVal41, initVal41, PointeeCXXRecordDeclaration, CXXRecordDecl, NthType, DeclUseSelector::POINTEE_CXX_RECORD_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(Type, pointee_or_array_element_type, getVal43, setVal43, initVal43, PointeeOrArrayElementType, Type, NthType, TypeUseSelector::POINTEE_OR_ARRAY_ELEMENT_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(Type, pointee_type, getVal45, setVal45, initVal45, PointeeType, Type, NthType, TypeUseSelector::POINTEE_TYPE)
  MX_VISIT_OPTIONAL_ENUM(Type, scalar_type_kind, getVal47, setVal47, initVal47, ScalarTypeKind, TypeScalarTypeKind, NthType)
  MX_VISIT_OPTIONAL_ENTITY(Type, sve_element_type, getVal49, setVal49, initVal49, SveElementType, Type, NthType, TypeUseSelector::SVE_ELEMENT_TYPE)
  MX_VISIT_ENUM(Type, kind, getVal51, setVal51, initVal51, Kind, TypeKind, NthType)
  MX_VISIT_ENTITY(Type, unqualified_desugared_type, getVal52, setVal52, initVal52, UnqualifiedDesugaredType, Type, NthType, TypeUseSelector::UNQUALIFIED_DESUGARED_TYPE)
  MX_VISIT_ENUM(Type, visibility, getVal53, setVal53, initVal53, Visibility, Visibility, NthType)
  MX_VISIT_BOOL(Type, has_auto_for_trailing_return_type, getVal54, setVal54, initVal54, HasAutoForTrailingReturnType, bool, NthType)
  MX_VISIT_BOOL(Type, has_floating_representation, getVal55, setVal55, initVal55, HasFloatingRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_integer_representation, getVal56, setVal56, initVal56, HasIntegerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_obj_c_pointer_representation, getVal57, setVal57, initVal57, HasObjCPointerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_pointer_representation, getVal58, setVal58, initVal58, HasPointerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_signed_integer_representation, getVal59, setVal59, initVal59, HasSignedIntegerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, has_sized_vla_type, getVal60, setVal60, initVal60, HasSizedVLAType, bool, NthType)
  MX_VISIT_BOOL(Type, has_unnamed_or_local_type, getVal61, setVal61, initVal61, HasUnnamedOrLocalType, bool, NthType)
  MX_VISIT_BOOL(Type, has_unsigned_integer_representation, getVal62, setVal62, initVal62, HasUnsignedIntegerRepresentation, bool, NthType)
  MX_VISIT_BOOL(Type, is_aggregate_type, getVal63, setVal63, initVal63, IsAggregateType, bool, NthType)
  MX_VISIT_BOOL(Type, is_align_value_t, getVal64, setVal64, initVal64, IsAlignValueT, bool, NthType)
  MX_VISIT_BOOL(Type, is_any_character_type, getVal65, setVal65, initVal65, IsAnyCharacterType, bool, NthType)
  MX_VISIT_BOOL(Type, is_any_complex_type, getVal66, setVal66, initVal66, IsAnyComplexType, bool, NthType)
  MX_VISIT_BOOL(Type, is_any_pointer_type, getVal67, setVal67, initVal67, IsAnyPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_arithmetic_type, getVal68, setVal68, initVal68, IsArithmeticType, bool, NthType)
  MX_VISIT_BOOL(Type, is_array_type, getVal69, setVal69, initVal69, IsArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_atomic_type, getVal70, setVal70, initVal70, IsAtomicType, bool, NthType)
  MX_VISIT_BOOL(Type, is_b_float16_type, getVal71, setVal71, initVal71, IsBFloat16Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_block_compatible_obj_c_pointer_type, getVal72, setVal72, initVal72, IsBlockCompatibleObjCPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_block_pointer_type, getVal73, setVal73, initVal73, IsBlockPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_boolean_type, getVal74, setVal74, initVal74, IsBooleanType, bool, NthType)
  MX_VISIT_BOOL(Type, is_builtin_type, getVal75, setVal75, initVal75, IsBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_carc_bridgable_type, getVal76, setVal76, initVal76, IsCARCBridgableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cuda_device_builtin_surface_type, getVal77, setVal77, initVal77, IsCUDADeviceBuiltinSurfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cuda_device_builtin_texture_type, getVal78, setVal78, initVal78, IsCUDADeviceBuiltinTextureType, bool, NthType)
  MX_VISIT_BOOL(Type, is_canonical_unqualified, getVal79, setVal79, initVal79, IsCanonicalUnqualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_char16_type, getVal80, setVal80, initVal80, IsChar16Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_char32_type, getVal81, setVal81, initVal81, IsChar32Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_char8_type, getVal82, setVal82, initVal82, IsChar8Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_character_type, getVal83, setVal83, initVal83, IsCharacterType, bool, NthType)
  MX_VISIT_BOOL(Type, is_class_type, getVal84, setVal84, initVal84, IsClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_clk_event_t, getVal85, setVal85, initVal85, IsClkEventT, bool, NthType)
  MX_VISIT_BOOL(Type, is_complex_integer_type, getVal86, setVal86, initVal86, IsComplexIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_complex_type, getVal87, setVal87, initVal87, IsComplexType, bool, NthType)
  MX_VISIT_BOOL(Type, is_compound_type, getVal88, setVal88, initVal88, IsCompoundType, bool, NthType)
  MX_VISIT_BOOL(Type, is_constant_array_type, getVal89, setVal89, initVal89, IsConstantArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_constant_matrix_type, getVal90, setVal90, initVal90, IsConstantMatrixType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_constant_size_type, getVal91, setVal91, initVal91, IsConstantSizeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_decltype_type, getVal93, setVal93, initVal93, IsDecltypeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_dependent_address_space_type, getVal94, setVal94, initVal94, IsDependentAddressSpaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_dependent_sized_array_type, getVal95, setVal95, initVal95, IsDependentSizedArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_dependent_type, getVal96, setVal96, initVal96, IsDependentType, bool, NthType)
  MX_VISIT_BOOL(Type, is_elaborated_type_specifier, getVal97, setVal97, initVal97, IsElaboratedTypeSpecifier, bool, NthType)
  MX_VISIT_BOOL(Type, is_enumeral_type, getVal98, setVal98, initVal98, IsEnumeralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_event_t, getVal99, setVal99, initVal99, IsEventT, bool, NthType)
  MX_VISIT_BOOL(Type, is_ext_int_type, getVal100, setVal100, initVal100, IsExtIntType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ext_vector_type, getVal101, setVal101, initVal101, IsExtVectorType, bool, NthType)
  MX_VISIT_BOOL(Type, is_fixed_point_or_integer_type, getVal102, setVal102, initVal102, IsFixedPointOrIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_fixed_point_type, getVal103, setVal103, initVal103, IsFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_float128_type, getVal104, setVal104, initVal104, IsFloat128Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_float16_type, getVal105, setVal105, initVal105, IsFloat16Type, bool, NthType)
  MX_VISIT_BOOL(Type, is_floating_type, getVal106, setVal106, initVal106, IsFloatingType, bool, NthType)
  MX_VISIT_BOOL(Type, is_from_ast, getVal107, setVal107, initVal107, IsFromAST, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_no_proto_type, getVal108, setVal108, initVal108, IsFunctionNoProtoType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_pointer_type, getVal109, setVal109, initVal109, IsFunctionPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_proto_type, getVal110, setVal110, initVal110, IsFunctionProtoType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_reference_type, getVal111, setVal111, initVal111, IsFunctionReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_function_type, getVal112, setVal112, initVal112, IsFunctionType, bool, NthType)
  MX_VISIT_BOOL(Type, is_fundamental_type, getVal113, setVal113, initVal113, IsFundamentalType, bool, NthType)
  MX_VISIT_BOOL(Type, is_half_type, getVal114, setVal114, initVal114, IsHalfType, bool, NthType)
  MX_VISIT_BOOL(Type, is_image_type, getVal115, setVal115, initVal115, IsImageType, bool, NthType)
  MX_VISIT_BOOL(Type, is_incomplete_array_type, getVal116, setVal116, initVal116, IsIncompleteArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_incomplete_or_object_type, getVal117, setVal117, initVal117, IsIncompleteOrObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_incomplete_type, getVal118, setVal118, initVal118, IsIncompleteType, bool, NthType)
  MX_VISIT_BOOL(Type, is_instantiation_dependent_type, getVal119, setVal119, initVal119, IsInstantiationDependentType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integer_type, getVal120, setVal120, initVal120, IsIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integral_or_enumeration_type, getVal121, setVal121, initVal121, IsIntegralOrEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integral_or_unscoped_enumeration_type, getVal122, setVal122, initVal122, IsIntegralOrUnscopedEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_integral_type, getVal123, setVal123, initVal123, IsIntegralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_interface_type, getVal124, setVal124, initVal124, IsInterfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_l_value_reference_type, getVal125, setVal125, initVal125, IsLValueReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_linkage_valid, getVal126, setVal126, initVal126, IsLinkageValid, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_literal_type, getVal127, setVal127, initVal127, IsLiteralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_matrix_type, getVal129, setVal129, initVal129, IsMatrixType, bool, NthType)
  MX_VISIT_BOOL(Type, is_member_data_pointer_type, getVal130, setVal130, initVal130, IsMemberDataPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_member_function_pointer_type, getVal131, setVal131, initVal131, IsMemberFunctionPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_member_pointer_type, getVal132, setVal132, initVal132, IsMemberPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_non_overload_placeholder_type, getVal133, setVal133, initVal133, IsNonOverloadPlaceholderType, bool, NthType)
  MX_VISIT_BOOL(Type, is_nothrow_t, getVal134, setVal134, initVal134, IsNothrowT, bool, NthType)
  MX_VISIT_BOOL(Type, is_null_pointer_type, getVal135, setVal135, initVal135, IsNullPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_ext_opaque_type, getVal136, setVal136, initVal136, IsOCLExtOpaqueType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_darray_ro_type, getVal137, setVal137, initVal137, IsOCLImage1dArrayROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_darray_rw_type, getVal138, setVal138, initVal138, IsOCLImage1dArrayRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_darray_wo_type, getVal139, setVal139, initVal139, IsOCLImage1dArrayWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dbuffer_ro_type, getVal140, setVal140, initVal140, IsOCLImage1dBufferROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dbuffer_rw_type, getVal141, setVal141, initVal141, IsOCLImage1dBufferRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dbuffer_wo_type, getVal142, setVal142, initVal142, IsOCLImage1dBufferWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dro_type, getVal143, setVal143, initVal143, IsOCLImage1dROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_drw_type, getVal144, setVal144, initVal144, IsOCLImage1dRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image1_dwo_type, getVal145, setVal145, initVal145, IsOCLImage1dWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_depth_ro_type, getVal146, setVal146, initVal146, IsOCLImage2dArrayDepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_depth_rw_type, getVal147, setVal147, initVal147, IsOCLImage2dArrayDepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_depth_wo_type, getVal148, setVal148, initVal148, IsOCLImage2dArrayDepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaa_depth_ro_type, getVal149, setVal149, initVal149, IsOCLImage2dArrayMSAADepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaa_depth_rw_type, getVal150, setVal150, initVal150, IsOCLImage2dArrayMSAADepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaa_depth_wo_type, getVal151, setVal151, initVal151, IsOCLImage2dArrayMSAADepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaaro_type, getVal152, setVal152, initVal152, IsOCLImage2dArrayMSAAROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaarw_type, getVal153, setVal153, initVal153, IsOCLImage2dArrayMSAARWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_msaawo_type, getVal154, setVal154, initVal154, IsOCLImage2dArrayMSAAWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_ro_type, getVal155, setVal155, initVal155, IsOCLImage2dArrayROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_rw_type, getVal156, setVal156, initVal156, IsOCLImage2dArrayRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_darray_wo_type, getVal157, setVal157, initVal157, IsOCLImage2dArrayWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_ddepth_ro_type, getVal158, setVal158, initVal158, IsOCLImage2dDepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_ddepth_rw_type, getVal159, setVal159, initVal159, IsOCLImage2dDepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_ddepth_wo_type, getVal160, setVal160, initVal160, IsOCLImage2dDepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaa_depth_ro_type, getVal161, setVal161, initVal161, IsOCLImage2dMSAADepthROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaa_depth_rw_type, getVal162, setVal162, initVal162, IsOCLImage2dMSAADepthRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaa_depth_wo_type, getVal163, setVal163, initVal163, IsOCLImage2dMSAADepthWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaaro_type, getVal164, setVal164, initVal164, IsOCLImage2dMSAAROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaarw_type, getVal165, setVal165, initVal165, IsOCLImage2dMSAARWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dmsaawo_type, getVal166, setVal166, initVal166, IsOCLImage2dMSAAWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dro_type, getVal167, setVal167, initVal167, IsOCLImage2dROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_drw_type, getVal168, setVal168, initVal168, IsOCLImage2dRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image2_dwo_type, getVal169, setVal169, initVal169, IsOCLImage2dWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image3_dro_type, getVal170, setVal170, initVal170, IsOCLImage3dROType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image3_drw_type, getVal171, setVal171, initVal171, IsOCLImage3dRWType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_image3_dwo_type, getVal172, setVal172, initVal172, IsOCLImage3dWOType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_dual_reference_streamin_type, getVal173, setVal173, initVal173, IsOCLIntelSubgroupAVCImeDualReferenceStreaminType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_payload_type, getVal174, setVal174, initVal174, IsOCLIntelSubgroupAVCImePayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_dual_reference_streamout_type, getVal175, setVal175, initVal175, IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_single_reference_streamout_type, getVal176, setVal176, initVal176, IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_result_type, getVal177, setVal177, initVal177, IsOCLIntelSubgroupAVCImeResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ime_single_reference_streamin_type, getVal178, setVal178, initVal178, IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_mce_payload_type, getVal179, setVal179, initVal179, IsOCLIntelSubgroupAVCMcePayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_mce_result_type, getVal180, setVal180, initVal180, IsOCLIntelSubgroupAVCMceResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ref_payload_type, getVal181, setVal181, initVal181, IsOCLIntelSubgroupAVCRefPayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_ref_result_type, getVal182, setVal182, initVal182, IsOCLIntelSubgroupAVCRefResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_sic_payload_type, getVal183, setVal183, initVal183, IsOCLIntelSubgroupAVCSicPayloadType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_sic_result_type, getVal184, setVal184, initVal184, IsOCLIntelSubgroupAVCSicResultType, bool, NthType)
  MX_VISIT_BOOL(Type, is_ocl_intel_subgroup_avc_type, getVal185, setVal185, initVal185, IsOCLIntelSubgroupAVCType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_carc_bridgable_type, getVal186, setVal186, initVal186, IsObjCARCBridgableType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_obj_carc_implicitly_unretained_type, getVal187, setVal187, initVal187, IsObjCARCImplicitlyUnretainedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_boxable_record_type, getVal189, setVal189, initVal189, IsObjCBoxableRecordType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_builtin_type, getVal190, setVal190, initVal190, IsObjCBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_class_or_class_kind_of_type, getVal191, setVal191, initVal191, IsObjCClassOrClassKindOfType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_class_type, getVal192, setVal192, initVal192, IsObjCClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_id_type, getVal193, setVal193, initVal193, IsObjCIdType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_independent_class_type, getVal194, setVal194, initVal194, IsObjCIndependentClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_indirect_lifetime_type, getVal195, setVal195, initVal195, IsObjCIndirectLifetimeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_inert_unsafe_unretained_type, getVal196, setVal196, initVal196, IsObjCInertUnsafeUnretainedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_lifetime_type, getVal197, setVal197, initVal197, IsObjCLifetimeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_cns_object_type, getVal198, setVal198, initVal198, IsObjCNSObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_object_or_interface_type, getVal199, setVal199, initVal199, IsObjCObjectOrInterfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_object_pointer_type, getVal200, setVal200, initVal200, IsObjCObjectPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_object_type, getVal201, setVal201, initVal201, IsObjCObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_qualified_class_type, getVal202, setVal202, initVal202, IsObjCQualifiedClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_qualified_id_type, getVal203, setVal203, initVal203, IsObjCQualifiedIdType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_qualified_interface_type, getVal204, setVal204, initVal204, IsObjCQualifiedInterfaceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_retainable_type, getVal205, setVal205, initVal205, IsObjCRetainableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_c_sel_type, getVal206, setVal206, initVal206, IsObjCSelType, bool, NthType)
  MX_VISIT_BOOL(Type, is_object_pointer_type, getVal207, setVal207, initVal207, IsObjectPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_object_type, getVal208, setVal208, initVal208, IsObjectType, bool, NthType)
  MX_VISIT_BOOL(Type, is_open_cl_specific_type, getVal209, setVal209, initVal209, IsOpenCLSpecificType, bool, NthType)
  MX_VISIT_BOOL(Type, is_overloadable_type, getVal210, setVal210, initVal210, IsOverloadableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_pipe_type, getVal211, setVal211, initVal211, IsPipeType, bool, NthType)
  MX_VISIT_BOOL(Type, is_placeholder_type, getVal212, setVal212, initVal212, IsPlaceholderType, bool, NthType)
  MX_VISIT_BOOL(Type, is_pointer_type, getVal213, setVal213, initVal213, IsPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_promotable_integer_type, getVal214, setVal214, initVal214, IsPromotableIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_queue_t, getVal215, setVal215, initVal215, IsQueueT, bool, NthType)
  MX_VISIT_BOOL(Type, is_r_value_reference_type, getVal216, setVal216, initVal216, IsRValueReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_real_floating_type, getVal217, setVal217, initVal217, IsRealFloatingType, bool, NthType)
  MX_VISIT_BOOL(Type, is_real_type, getVal218, setVal218, initVal218, IsRealType, bool, NthType)
  MX_VISIT_BOOL(Type, is_record_type, getVal219, setVal219, initVal219, IsRecordType, bool, NthType)
  MX_VISIT_BOOL(Type, is_reference_type, getVal220, setVal220, initVal220, IsReferenceType, bool, NthType)
  MX_VISIT_BOOL(Type, is_reserve_idt, getVal221, setVal221, initVal221, IsReserveIDT, bool, NthType)
  MX_VISIT_BOOL(Type, is_sampler_t, getVal222, setVal222, initVal222, IsSamplerT, bool, NthType)
  MX_VISIT_BOOL(Type, is_saturated_fixed_point_type, getVal223, setVal223, initVal223, IsSaturatedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_scalar_type, getVal224, setVal224, initVal224, IsScalarType, bool, NthType)
  MX_VISIT_BOOL(Type, is_scoped_enumeral_type, getVal225, setVal225, initVal225, IsScopedEnumeralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_signed_fixed_point_type, getVal226, setVal226, initVal226, IsSignedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_signed_integer_or_enumeration_type, getVal227, setVal227, initVal227, IsSignedIntegerOrEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_signed_integer_type, getVal228, setVal228, initVal228, IsSignedIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_sizeless_builtin_type, getVal229, setVal229, initVal229, IsSizelessBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_sizeless_type, getVal230, setVal230, initVal230, IsSizelessType, bool, NthType)
  MX_VISIT_BOOL(Type, is_specifier_type, getVal231, setVal231, initVal231, IsSpecifierType, bool, NthType)
  MX_VISIT_OPTIONAL_BOOL(Type, is_standard_layout_type, getVal232, setVal232, initVal232, IsStandardLayoutType, bool, NthType)
  MX_VISIT_BOOL(Type, is_std_byte_type, getVal234, setVal234, initVal234, IsStdByteType, bool, NthType)
  MX_VISIT_BOOL(Type, is_structural_type, getVal235, setVal235, initVal235, IsStructuralType, bool, NthType)
  MX_VISIT_BOOL(Type, is_structure_or_class_type, getVal236, setVal236, initVal236, IsStructureOrClassType, bool, NthType)
  MX_VISIT_BOOL(Type, is_structure_type, getVal237, setVal237, initVal237, IsStructureType, bool, NthType)
  MX_VISIT_BOOL(Type, is_template_type_parm_type, getVal238, setVal238, initVal238, IsTemplateTypeParmType, bool, NthType)
  MX_VISIT_BOOL(Type, is_typedef_name_type, getVal239, setVal239, initVal239, IsTypedefNameType, bool, NthType)
  MX_VISIT_BOOL(Type, is_undeduced_auto_type, getVal240, setVal240, initVal240, IsUndeducedAutoType, bool, NthType)
  MX_VISIT_BOOL(Type, is_undeduced_type, getVal241, setVal241, initVal241, IsUndeducedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_union_type, getVal242, setVal242, initVal242, IsUnionType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsaturated_fixed_point_type, getVal243, setVal243, initVal243, IsUnsaturatedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unscoped_enumeration_type, getVal244, setVal244, initVal244, IsUnscopedEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsigned_fixed_point_type, getVal245, setVal245, initVal245, IsUnsignedFixedPointType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsigned_integer_or_enumeration_type, getVal246, setVal246, initVal246, IsUnsignedIntegerOrEnumerationType, bool, NthType)
  MX_VISIT_BOOL(Type, is_unsigned_integer_type, getVal247, setVal247, initVal247, IsUnsignedIntegerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_vlst_builtin_type, getVal248, setVal248, initVal248, IsVLSTBuiltinType, bool, NthType)
  MX_VISIT_BOOL(Type, is_variable_array_type, getVal249, setVal249, initVal249, IsVariableArrayType, bool, NthType)
  MX_VISIT_BOOL(Type, is_variably_modified_type, getVal250, setVal250, initVal250, IsVariablyModifiedType, bool, NthType)
  MX_VISIT_BOOL(Type, is_vector_type, getVal251, setVal251, initVal251, IsVectorType, bool, NthType)
  MX_VISIT_BOOL(Type, is_visibility_explicit, getVal252, setVal252, initVal252, IsVisibilityExplicit, bool, NthType)
  MX_VISIT_BOOL(Type, is_void_pointer_type, getVal253, setVal253, initVal253, IsVoidPointerType, bool, NthType)
  MX_VISIT_BOOL(Type, is_void_type, getVal254, setVal254, initVal254, IsVoidType, bool, NthType)
  MX_VISIT_BOOL(Type, is_wide_character_type, getVal255, setVal255, initVal255, IsWideCharacterType, bool, NthType)
  MX_VISIT_ENTITY(Type, ignore_parentheses, getVal256, setVal256, initVal256, IgnoreParentheses, Type, NthType, TypeUseSelector::IGNORE_PARENTHESES)
  MX_VISIT_ENUM(Type, address_space, getVal257, setVal257, initVal257, AddressSpace, LangAS, NthType)
  MX_VISIT_ENTITY(Type, atomic_unqualified_type, getVal258, setVal258, initVal258, AtomicUnqualifiedType, Type, NthType, TypeUseSelector::ATOMIC_UNQUALIFIED_TYPE)
  MX_VISIT_ENTITY(Type, canonical_type, getVal259, setVal259, initVal259, CanonicalType, Type, NthType, TypeUseSelector::CANONICAL_TYPE)
  MX_VISIT_ENTITY(Type, desugared_type, getVal260, setVal260, initVal260, DesugaredType, Type, NthType, TypeUseSelector::DESUGARED_TYPE)
  MX_VISIT_ENTITY(Type, local_unqualified_type, getVal261, setVal261, initVal261, LocalUnqualifiedType, Type, NthType, TypeUseSelector::LOCAL_UNQUALIFIED_TYPE)
  MX_VISIT_ENTITY(Type, non_l_value_expression_type, getVal262, setVal262, initVal262, NonLValueExpressionType, Type, NthType, TypeUseSelector::NON_L_VALUE_EXPRESSION_TYPE)
  MX_VISIT_ENTITY(Type, non_pack_expansion_type, getVal263, setVal263, initVal263, NonPackExpansionType, Type, NthType, TypeUseSelector::NON_PACK_EXPANSION_TYPE)
  MX_VISIT_ENTITY(Type, non_reference_type, getVal264, setVal264, initVal264, NonReferenceType, Type, NthType, TypeUseSelector::NON_REFERENCE_TYPE)
  MX_VISIT_ENTITY(Type, single_step_desugared_type, getVal265, setVal265, initVal265, SingleStepDesugaredType, Type, NthType, TypeUseSelector::SINGLE_STEP_DESUGARED_TYPE)
  MX_VISIT_BOOL(Type, has_address_space, getVal266, setVal266, initVal266, HasAddressSpace, bool, NthType)
  MX_VISIT_BOOL(Type, has_local_non_fast_qualifiers, getVal267, setVal267, initVal267, HasLocalNonFastQualifiers, bool, NthType)
  MX_VISIT_BOOL(Type, has_local_qualifiers, getVal268, setVal268, initVal268, HasLocalQualifiers, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_obj_c_lifetime, getVal269, setVal269, initVal269, HasNonTrivialObjCLifetime, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_to_primitive_copy_c_union, getVal270, setVal270, initVal270, HasNonTrivialToPrimitiveCopyCUnion, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_to_primitive_default_initialize_c_union, getVal271, setVal271, initVal271, HasNonTrivialToPrimitiveDefaultInitializeCUnion, bool, NthType)
  MX_VISIT_BOOL(Type, has_non_trivial_to_primitive_destruct_c_union, getVal272, setVal272, initVal272, HasNonTrivialToPrimitiveDestructCUnion, bool, NthType)
  MX_VISIT_BOOL(Type, has_qualifiers, getVal273, setVal273, initVal273, HasQualifiers, bool, NthType)
  MX_VISIT_BOOL(Type, has_strong_or_weak_obj_c_lifetime, getVal274, setVal274, initVal274, HasStrongOrWeakObjCLifetime, bool, NthType)
  MX_VISIT_BOOL(Type, is_c_forbidden_l_value_type, getVal275, setVal275, initVal275, IsCForbiddenLValueType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cxx11_pod_type, getVal276, setVal276, initVal276, IsCXX11PODType, bool, NthType)
  MX_VISIT_BOOL(Type, is_cxx98_pod_type, getVal277, setVal277, initVal277, IsCXX98PODType, bool, NthType)
  MX_VISIT_BOOL(Type, is_canonical, getVal278, setVal278, initVal278, IsCanonical, bool, NthType)
  MX_VISIT_BOOL(Type, is_canonical_as_parameter, getVal279, setVal279, initVal279, IsCanonicalAsParameter, bool, NthType)
  MX_VISIT_BOOL(Type, is_const_qualified, getVal280, setVal280, initVal280, IsConstQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_constant, getVal281, setVal281, initVal281, IsConstant, bool, NthType)
  MX_VISIT_ENUM(Type, is_destructed_type, getVal282, setVal282, initVal282, IsDestructedType, QualTypeDestructionKind, NthType)
  MX_VISIT_BOOL(Type, is_local_const_qualified, getVal283, setVal283, initVal283, IsLocalConstQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_local_restrict_qualified, getVal284, setVal284, initVal284, IsLocalRestrictQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_local_volatile_qualified, getVal285, setVal285, initVal285, IsLocalVolatileQualified, bool, NthType)
  MX_VISIT_ENUM(Type, is_non_trivial_to_primitive_copy, getVal286, setVal286, initVal286, IsNonTrivialToPrimitiveCopy, QualTypePrimitiveCopyKind, NthType)
  MX_VISIT_ENUM(Type, is_non_trivial_to_primitive_default_initialize, getVal287, setVal287, initVal287, IsNonTrivialToPrimitiveDefaultInitialize, QualTypePrimitiveDefaultInitializeKind, NthType)
  MX_VISIT_ENUM(Type, is_non_trivial_to_primitive_destructive_move, getVal288, setVal288, initVal288, IsNonTrivialToPrimitiveDestructiveMove, QualTypePrimitiveCopyKind, NthType)
  MX_VISIT_BOOL(Type, is_non_weak_in_mrr_with_obj_c_weak, getVal289, setVal289, initVal289, IsNonWeakInMRRWithObjCWeak, bool, NthType)
  MX_VISIT_BOOL(Type, is_null, getVal290, setVal290, initVal290, IsNull, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_cgc_strong, getVal291, setVal291, initVal291, IsObjCGCStrong, bool, NthType)
  MX_VISIT_BOOL(Type, is_obj_cgc_weak, getVal292, setVal292, initVal292, IsObjCGCWeak, bool, NthType)
  MX_VISIT_BOOL(Type, is_pod_type, getVal293, setVal293, initVal293, IsPODType, bool, NthType)
  MX_VISIT_BOOL(Type, is_restrict_qualified, getVal294, setVal294, initVal294, IsRestrictQualified, bool, NthType)
  MX_VISIT_BOOL(Type, is_trivial_type, getVal295, setVal295, initVal295, IsTrivialType, bool, NthType)
  MX_VISIT_BOOL(Type, is_trivially_copyable_type, getVal296, setVal296, initVal296, IsTriviallyCopyableType, bool, NthType)
  MX_VISIT_BOOL(Type, is_volatile_qualified, getVal297, setVal297, initVal297, IsVolatileQualified, bool, NthType)
  MX_VISIT_BOOL(Type, may_be_dynamic_class, getVal298, setVal298, initVal298, MayBeDynamicClass, bool, NthType)
  MX_VISIT_BOOL(Type, may_be_not_dynamic_class, getVal299, setVal299, initVal299, MayBeNotDynamicClass, bool, NthType)
  MX_VISIT_ENTITY(Type, strip_obj_c_kind_of_type, getVal300, setVal300, initVal300, StripObjCKindOfType, Type, NthType, TypeUseSelector::STRIP_OBJ_C_KIND_OF_TYPE)
  MX_VISIT_ENTITY(Type, with_const, getVal301, setVal301, initVal301, WithConst, Type, NthType, TypeUseSelector::WITH_CONST)
  MX_VISIT_ENTITY(Type, with_restrict, getVal302, setVal302, initVal302, WithRestrict, Type, NthType, TypeUseSelector::WITH_RESTRICT)
  MX_VISIT_ENTITY(Type, with_volatile, getVal303, setVal303, initVal303, WithVolatile, Type, NthType, TypeUseSelector::WITH_VOLATILE)
  MX_VISIT_ENTITY(Type, without_local_fast_qualifiers, getVal304, setVal304, initVal304, WithoutLocalFastQualifiers, Type, NthType, TypeUseSelector::WITHOUT_LOCAL_FAST_QUALIFIERS)
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
  MX_VISIT_ENTITY(TemplateTypeParmType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TemplateTypeParmType, declaration, getVal306, setVal306, initVal306, Declaration, TemplateTypeParmDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(TemplateTypeParmType, is_parameter_pack, getVal307, setVal307, initVal307, IsParameterPack, bool, NthType)
  MX_VISIT_BOOL(TemplateTypeParmType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(TemplateSpecializationType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TemplateSpecializationType, aliased_type, getVal306, setVal306, initVal306, AliasedType, Type, NthType, TypeUseSelector::ALIASED_TYPE)
  MX_VISIT_BOOL(TemplateSpecializationType, is_current_instantiation, getVal307, setVal307, initVal307, IsCurrentInstantiation, bool, NthType)
  MX_VISIT_BOOL(TemplateSpecializationType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_VISIT_BOOL(TemplateSpecializationType, is_type_alias, getVal309, setVal309, initVal309, IsTypeAlias, bool, NthType)
  MX_VISIT_PSEUDO_LIST(TemplateSpecializationType, template_arguments, getVal310, setVal310, initVal310, TemplateArguments, TemplateArgument, NthType)
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
  MX_VISIT_ENTITY(TagType, declaration, getVal305, setVal305, initVal305, Declaration, TagDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(TagType, is_being_defined, getVal307, setVal307, initVal307, IsBeingDefined, bool, NthType)
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
  MX_VISIT_ENTITY(RecordType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(RecordType, has_const_fields, getVal308, setVal308, initVal308, HasConstFields, bool, NthType)
  MX_VISIT_BOOL(RecordType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(EnumType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(EnumType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(SubstTemplateTypeParmType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(SubstTemplateTypeParmType, replaced_parameter, getVal306, setVal306, initVal306, ReplacedParameter, TemplateTypeParmType, NthType, TypeUseSelector::REPLACED_PARAMETER)
  MX_VISIT_ENTITY(SubstTemplateTypeParmType, replacement_type, getVal311, setVal311, initVal311, ReplacementType, Type, NthType, TypeUseSelector::REPLACEMENT_TYPE)
  MX_VISIT_BOOL(SubstTemplateTypeParmType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(SubstTemplateTypeParmPackType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(SubstTemplateTypeParmPackType, replaced_parameter, getVal306, setVal306, initVal306, ReplacedParameter, TemplateTypeParmType, NthType, TypeUseSelector::REPLACED_PARAMETER)
  MX_VISIT_BOOL(SubstTemplateTypeParmPackType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ReferenceType, pointee_type_as_written, getVal305, setVal305, initVal305, PointeeTypeAsWritten, Type, NthType, TypeUseSelector::POINTEE_TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(ReferenceType, is_inner_reference, getVal307, setVal307, initVal307, IsInnerReference, bool, NthType)
  MX_VISIT_BOOL(ReferenceType, is_spelled_as_l_value, getVal308, setVal308, initVal308, IsSpelledAsLValue, bool, NthType)
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
  MX_VISIT_ENTITY(RValueReferenceType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(RValueReferenceType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(LValueReferenceType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(LValueReferenceType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(PointerType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(PointerType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(PipeType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(PipeType, element_type, getVal306, setVal306, initVal306, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_BOOL(PipeType, is_read_only, getVal307, setVal307, initVal307, IsReadOnly, bool, NthType)
  MX_VISIT_BOOL(PipeType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ParenType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ParenType, inner_type, getVal306, setVal306, initVal306, InnerType, Type, NthType, TypeUseSelector::INNER_TYPE)
  MX_VISIT_BOOL(ParenType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(PackExpansionType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_INT(PackExpansionType, num_expansions, getVal312, setVal312, initVal312, NumExpansions, unsigned, NthType)
  MX_VISIT_ENTITY(PackExpansionType, pattern, getVal306, setVal306, initVal306, Pattern, Type, NthType, TypeUseSelector::PATTERN)
  MX_VISIT_BOOL(PackExpansionType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ObjCTypeParamType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ObjCTypeParamType, declaration, getVal306, setVal306, initVal306, Declaration, ObjCTypeParamDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(ObjCTypeParamType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ObjCObjectType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ObjCObjectType, base_type, getVal306, setVal306, initVal306, BaseType, Type, NthType, TypeUseSelector::BASE_TYPE)
  MX_VISIT_ENTITY(ObjCObjectType, interface, getVal311, setVal311, initVal311, Interface, ObjCInterfaceDecl, NthType, DeclUseSelector::INTERFACE)
  MX_VISIT_OPTIONAL_ENTITY(ObjCObjectType, super_class_type, getVal313, setVal313, initVal313, SuperClassType, Type, NthType, TypeUseSelector::SUPER_CLASS_TYPE)
  MX_VISIT_ENTITY_LIST(ObjCObjectType, type_arguments, getVal314, setVal314, initVal314, TypeArguments, Type, NthType)
  MX_VISIT_ENTITY_LIST(ObjCObjectType, type_arguments_as_written, getVal315, setVal315, initVal315, TypeArgumentsAsWritten, Type, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_kind_of_type, getVal308, setVal308, initVal308, IsKindOfType, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_kind_of_type_as_written, getVal309, setVal309, initVal309, IsKindOfTypeAsWritten, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_class, getVal316, setVal316, initVal316, IsObjCClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_id, getVal317, setVal317, initVal317, IsObjCId, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_qualified_class, getVal318, setVal318, initVal318, IsObjCQualifiedClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_qualified_id, getVal319, setVal319, initVal319, IsObjCQualifiedId, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_unqualified_class, getVal320, setVal320, initVal320, IsObjCUnqualifiedClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_unqualified_id, getVal321, setVal321, initVal321, IsObjCUnqualifiedId, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_obj_c_unqualified_id_or_class, getVal322, setVal322, initVal322, IsObjCUnqualifiedIdOrClass, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_specialized, getVal323, setVal323, initVal323, IsSpecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_specialized_as_written, getVal324, setVal324, initVal324, IsSpecializedAsWritten, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_sugared, getVal325, setVal325, initVal325, IsSugared, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_unspecialized, getVal326, setVal326, initVal326, IsUnspecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectType, is_unspecialized_as_written, getVal327, setVal327, initVal327, IsUnspecializedAsWritten, bool, NthType)
  MX_VISIT_ENTITY(ObjCObjectType, strip_obj_c_kind_of_type_and_qualifieds, getVal328, setVal328, initVal328, StripObjCKindOfTypeAndQualifieds, Type, NthType, TypeUseSelector::STRIP_OBJ_C_KIND_OF_TYPE_AND_QUALIFIEDS)
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
  MX_VISIT_ENTITY(ObjCInterfaceType, declaration, getVal329, setVal329, initVal329, Declaration, ObjCInterfaceDecl, NthType, DeclUseSelector::DECLARATION)
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
  MX_VISIT_ENTITY(ObjCObjectPointerType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ObjCObjectPointerType, interface_declaration, getVal306, setVal306, initVal306, InterfaceDeclaration, ObjCInterfaceDecl, NthType, DeclUseSelector::INTERFACE_DECLARATION)
  MX_VISIT_ENTITY(ObjCObjectPointerType, interface_type, getVal311, setVal311, initVal311, InterfaceType, ObjCInterfaceType, NthType, TypeUseSelector::INTERFACE_TYPE)
  MX_VISIT_ENTITY(ObjCObjectPointerType, object_type, getVal313, setVal313, initVal313, ObjectType, ObjCObjectType, NthType, TypeUseSelector::OBJECT_TYPE)
  MX_VISIT_ENTITY(ObjCObjectPointerType, super_class_type, getVal328, setVal328, initVal328, SuperClassType, Type, NthType, TypeUseSelector::SUPER_CLASS_TYPE)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, type_arguments, getVal314, setVal314, initVal314, TypeArguments, Type, NthType)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, type_arguments_as_written, getVal315, setVal315, initVal315, TypeArgumentsAsWritten, Type, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_kind_of_type, getVal307, setVal307, initVal307, IsKindOfType, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_obj_c_id_or_class_type, getVal308, setVal308, initVal308, IsObjCIdOrClassType, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_specialized, getVal309, setVal309, initVal309, IsSpecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_specialized_as_written, getVal316, setVal316, initVal316, IsSpecializedAsWritten, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_sugared, getVal317, setVal317, initVal317, IsSugared, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_unspecialized, getVal318, setVal318, initVal318, IsUnspecialized, bool, NthType)
  MX_VISIT_BOOL(ObjCObjectPointerType, is_unspecialized_as_written, getVal319, setVal319, initVal319, IsUnspecializedAsWritten, bool, NthType)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, qualifieds, getVal330, setVal330, initVal330, Qualifieds, ObjCProtocolDecl, NthType)
  MX_VISIT_ENTITY(ObjCObjectPointerType, strip_obj_c_kind_of_type_and_qualifieds, getVal329, setVal329, initVal329, StripObjCKindOfTypeAndQualifieds, ObjCObjectPointerType, NthType, TypeUseSelector::STRIP_OBJ_C_KIND_OF_TYPE_AND_QUALIFIEDS)
  MX_VISIT_ENTITY_LIST(ObjCObjectPointerType, protocols, getVal331, setVal331, initVal331, Protocols, ObjCProtocolDecl, NthType)
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
  MX_VISIT_ENTITY(MemberPointerType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(MemberPointerType, class_, getVal306, setVal306, initVal306, Class, Type, NthType, TypeUseSelector::CLASS_)
  MX_VISIT_ENTITY(MemberPointerType, most_recent_cxx_record_declaration, getVal311, setVal311, initVal311, MostRecentCXXRecordDeclaration, CXXRecordDecl, NthType, DeclUseSelector::MOST_RECENT_CXX_RECORD_DECLARATION)
  MX_VISIT_BOOL(MemberPointerType, is_member_data_pointer, getVal307, setVal307, initVal307, IsMemberDataPointer, bool, NthType)
  MX_VISIT_BOOL(MemberPointerType, is_member_function_pointer, getVal308, setVal308, initVal308, IsMemberFunctionPointer, bool, NthType)
  MX_VISIT_BOOL(MemberPointerType, is_sugared, getVal309, setVal309, initVal309, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(MatrixType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(MatrixType, element_type, getVal306, setVal306, initVal306, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_BOOL(MatrixType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(DependentSizedMatrixType, attribute_token, getVal311, setVal311, initVal311, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(DependentSizedMatrixType, column_expression, getVal313, setVal313, initVal313, ColumnExpression, Expr, NthType, StmtUseSelector::COLUMN_EXPRESSION)
  MX_VISIT_ENTITY(DependentSizedMatrixType, row_expression, getVal328, setVal328, initVal328, RowExpression, Expr, NthType, StmtUseSelector::ROW_EXPRESSION)
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
  MX_VISIT_ENTITY(MacroQualifiedType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(MacroQualifiedType, modified_type, getVal306, setVal306, initVal306, ModifiedType, Type, NthType, TypeUseSelector::MODIFIED_TYPE)
  MX_VISIT_ENTITY(MacroQualifiedType, underlying_type, getVal311, setVal311, initVal311, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(MacroQualifiedType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(InjectedClassNameType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(InjectedClassNameType, declaration, getVal306, setVal306, initVal306, Declaration, CXXRecordDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(InjectedClassNameType, injected_specialization_type, getVal311, setVal311, initVal311, InjectedSpecializationType, Type, NthType, TypeUseSelector::INJECTED_SPECIALIZATION_TYPE)
  MX_VISIT_ENTITY(InjectedClassNameType, injected_tst, getVal313, setVal313, initVal313, InjectedTST, TemplateSpecializationType, NthType, TypeUseSelector::INJECTED_TST)
  MX_VISIT_BOOL(InjectedClassNameType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENUM(FunctionType, call_conv, getVal332, setVal332, initVal332, CallConv, CallingConv, NthType)
  MX_VISIT_ENTITY(FunctionType, call_result_type, getVal305, setVal305, initVal305, CallResultType, Type, NthType, TypeUseSelector::CALL_RESULT_TYPE)
  MX_VISIT_BOOL(FunctionType, cmse_ns_call_attribute, getVal307, setVal307, initVal307, CmseNSCallAttribute, bool, NthType)
  MX_VISIT_BOOL(FunctionType, has_reg_parm, getVal308, setVal308, initVal308, HasRegParm, bool, NthType)
  MX_VISIT_BOOL(FunctionType, no_return_attribute, getVal309, setVal309, initVal309, NoReturnAttribute, bool, NthType)
  MX_VISIT_ENTITY(FunctionType, return_type, getVal306, setVal306, initVal306, ReturnType, Type, NthType, TypeUseSelector::RETURN_TYPE)
  MX_VISIT_BOOL(FunctionType, is_const, getVal316, setVal316, initVal316, IsConst, bool, NthType)
  MX_VISIT_BOOL(FunctionType, is_restrict, getVal317, setVal317, initVal317, IsRestrict, bool, NthType)
  MX_VISIT_BOOL(FunctionType, is_volatile, getVal318, setVal318, initVal318, IsVolatile, bool, NthType)
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
  MX_VISIT_ENUM(FunctionProtoType, can_throw, getVal333, setVal333, initVal333, CanThrow, CanThrowResult, NthType)
  MX_VISIT_ENTITY(FunctionProtoType, desugar, getVal311, setVal311, initVal311, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY_LIST(FunctionProtoType, exceptions, getVal314, setVal314, initVal314, Exceptions, Type, NthType)
  MX_VISIT_ENTITY(FunctionProtoType, ellipsis_token, getVal313, setVal313, initVal313, EllipsisToken, Token, NthType, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(FunctionProtoType, exception_spec_declaration, getVal328, setVal328, initVal328, ExceptionSpecDeclaration, FunctionDecl, NthType, DeclUseSelector::EXCEPTION_SPEC_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(FunctionProtoType, exception_spec_template, getVal329, setVal329, initVal329, ExceptionSpecTemplate, FunctionDecl, NthType, DeclUseSelector::EXCEPTION_SPEC_TEMPLATE)
  MX_VISIT_ENUM(FunctionProtoType, exception_spec_type, getVal334, setVal334, initVal334, ExceptionSpecType, ExceptionSpecificationType, NthType)
  MX_VISIT_OPTIONAL_ENTITY(FunctionProtoType, noexcept_expression, getVal335, setVal335, initVal335, NoexceptExpression, Expr, NthType, StmtUseSelector::NOEXCEPT_EXPRESSION)
  MX_VISIT_ENTITY_LIST(FunctionProtoType, parameter_types, getVal315, setVal315, initVal315, ParameterTypes, Type, NthType)
  MX_VISIT_ENUM(FunctionProtoType, reference_qualifier, getVal336, setVal336, initVal336, ReferenceQualifier, RefQualifierKind, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_dependent_exception_spec, getVal322, setVal322, initVal322, HasDependentExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_dynamic_exception_spec, getVal323, setVal323, initVal323, HasDynamicExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_exception_spec, getVal324, setVal324, initVal324, HasExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_ext_parameter_infos, getVal325, setVal325, initVal325, HasExtParameterInfos, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_instantiation_dependent_exception_spec, getVal326, setVal326, initVal326, HasInstantiationDependentExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_noexcept_exception_spec, getVal327, setVal327, initVal327, HasNoexceptExceptionSpec, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, has_trailing_return, getVal337, setVal337, initVal337, HasTrailingReturn, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_nothrow, getVal338, setVal338, initVal338, IsNothrow, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_sugared, getVal339, setVal339, initVal339, IsSugared, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_template_variadic, getVal340, setVal340, initVal340, IsTemplateVariadic, bool, NthType)
  MX_VISIT_BOOL(FunctionProtoType, is_variadic, getVal341, setVal341, initVal341, IsVariadic, bool, NthType)
  MX_VISIT_ENTITY_LIST(FunctionProtoType, exception_types, getVal330, setVal330, initVal330, ExceptionTypes, Type, NthType)
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
  MX_VISIT_ENTITY(FunctionNoProtoType, desugar, getVal311, setVal311, initVal311, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(FunctionNoProtoType, is_sugared, getVal319, setVal319, initVal319, IsSugared, bool, NthType)
  MX_EXIT_VISIT_FunctionNoProtoType
MX_END_VISIT_TYPE(FunctionNoProtoType)

#ifndef MX_ENTER_VISIT_ExtIntType
#  define MX_ENTER_VISIT_ExtIntType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_ExtIntType
#  define MX_EXIT_VISIT_ExtIntType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(ExtIntType)
  MX_ENTER_VISIT_ExtIntType
  MX_VISIT_BASE(ExtIntType, Type)
  MX_VISIT_ENTITY(ExtIntType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(ExtIntType, is_signed, getVal307, setVal307, initVal307, IsSigned, bool, NthType)
  MX_VISIT_BOOL(ExtIntType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_VISIT_BOOL(ExtIntType, is_unsigned, getVal309, setVal309, initVal309, IsUnsigned, bool, NthType)
  MX_EXIT_VISIT_ExtIntType
MX_END_VISIT_TYPE(ExtIntType)

#ifndef MX_ENTER_VISIT_DependentVectorType
#  define MX_ENTER_VISIT_DependentVectorType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentVectorType
#  define MX_EXIT_VISIT_DependentVectorType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentVectorType)
  MX_ENTER_VISIT_DependentVectorType
  MX_VISIT_BASE(DependentVectorType, Type)
  MX_VISIT_ENTITY(DependentVectorType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentVectorType, attribute_token, getVal306, setVal306, initVal306, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(DependentVectorType, element_type, getVal311, setVal311, initVal311, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENTITY(DependentVectorType, size_expression, getVal313, setVal313, initVal313, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_ENUM(DependentVectorType, vector_kind, getVal332, setVal332, initVal332, VectorKind, VectorTypeVectorKind, NthType)
  MX_VISIT_BOOL(DependentVectorType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(DependentSizedExtVectorType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, attribute_token, getVal306, setVal306, initVal306, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, element_type, getVal311, setVal311, initVal311, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENTITY(DependentSizedExtVectorType, size_expression, getVal313, setVal313, initVal313, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(DependentSizedExtVectorType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
  MX_EXIT_VISIT_DependentSizedExtVectorType
MX_END_VISIT_TYPE(DependentSizedExtVectorType)

#ifndef MX_ENTER_VISIT_DependentExtIntType
#  define MX_ENTER_VISIT_DependentExtIntType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentExtIntType
#  define MX_EXIT_VISIT_DependentExtIntType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentExtIntType)
  MX_ENTER_VISIT_DependentExtIntType
  MX_VISIT_BASE(DependentExtIntType, Type)
  MX_VISIT_ENTITY(DependentExtIntType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentExtIntType, num_bits_expression, getVal306, setVal306, initVal306, NumBitsExpression, Expr, NthType, StmtUseSelector::NUM_BITS_EXPRESSION)
  MX_VISIT_BOOL(DependentExtIntType, is_signed, getVal307, setVal307, initVal307, IsSigned, bool, NthType)
  MX_VISIT_BOOL(DependentExtIntType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
  MX_VISIT_BOOL(DependentExtIntType, is_unsigned, getVal309, setVal309, initVal309, IsUnsigned, bool, NthType)
  MX_EXIT_VISIT_DependentExtIntType
MX_END_VISIT_TYPE(DependentExtIntType)

#ifndef MX_ENTER_VISIT_DependentAddressSpaceType
#  define MX_ENTER_VISIT_DependentAddressSpaceType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_DependentAddressSpaceType
#  define MX_EXIT_VISIT_DependentAddressSpaceType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(DependentAddressSpaceType)
  MX_ENTER_VISIT_DependentAddressSpaceType
  MX_VISIT_BASE(DependentAddressSpaceType, Type)
  MX_VISIT_ENTITY(DependentAddressSpaceType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentAddressSpaceType, addr_space_expression, getVal306, setVal306, initVal306, AddrSpaceExpression, Expr, NthType, StmtUseSelector::ADDR_SPACE_EXPRESSION)
  MX_VISIT_ENTITY(DependentAddressSpaceType, attribute_token, getVal311, setVal311, initVal311, AttributeToken, Token, NthType, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_BOOL(DependentAddressSpaceType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(DeducedType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DeducedType, resolved_type, getVal306, setVal306, initVal306, ResolvedType, Type, NthType, TypeUseSelector::RESOLVED_TYPE)
  MX_VISIT_BOOL(DeducedType, is_deduced, getVal307, setVal307, initVal307, IsDeduced, bool, NthType)
  MX_VISIT_BOOL(DeducedType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENUM(AutoType, keyword, getVal332, setVal332, initVal332, Keyword, AutoTypeKeyword, NthType)
  MX_VISIT_PSEUDO_LIST(AutoType, type_constraint_arguments, getVal310, setVal310, initVal310, TypeConstraintArguments, TemplateArgument, NthType)
  MX_VISIT_ENTITY(AutoType, type_constraint_concept, getVal311, setVal311, initVal311, TypeConstraintConcept, ConceptDecl, NthType, DeclUseSelector::TYPE_CONSTRAINT_CONCEPT)
  MX_VISIT_BOOL(AutoType, is_constrained, getVal309, setVal309, initVal309, IsConstrained, bool, NthType)
  MX_VISIT_BOOL(AutoType, is_decltype_auto, getVal316, setVal316, initVal316, IsDecltypeAuto, bool, NthType)
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
  MX_VISIT_ENTITY(DecltypeType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DecltypeType, underlying_expression, getVal306, setVal306, initVal306, UnderlyingExpression, Expr, NthType, StmtUseSelector::UNDERLYING_EXPRESSION)
  MX_VISIT_ENTITY(DecltypeType, underlying_type, getVal311, setVal311, initVal311, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(DecltypeType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ComplexType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ComplexType, element_type, getVal306, setVal306, initVal306, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_BOOL(ComplexType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(BuiltinType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(BuiltinType, is_floating_point, getVal307, setVal307, initVal307, IsFloatingPoint, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_integer, getVal308, setVal308, initVal308, IsInteger, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_signed_integer, getVal309, setVal309, initVal309, IsSignedInteger, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_sugared, getVal316, setVal316, initVal316, IsSugared, bool, NthType)
  MX_VISIT_BOOL(BuiltinType, is_unsigned_integer, getVal317, setVal317, initVal317, IsUnsignedInteger, bool, NthType)
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
  MX_VISIT_ENTITY(BlockPointerType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(BlockPointerType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
  MX_EXIT_VISIT_BlockPointerType
MX_END_VISIT_TYPE(BlockPointerType)

#ifndef MX_ENTER_VISIT_AttributedType
#  define MX_ENTER_VISIT_AttributedType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_AttributedType
#  define MX_EXIT_VISIT_AttributedType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(AttributedType)
  MX_ENTER_VISIT_AttributedType
  MX_VISIT_BASE(AttributedType, Type)
  MX_VISIT_ENTITY(AttributedType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENUM(AttributedType, attribute_kind, getVal342, setVal342, initVal342, AttributeKind, AttributeKind, NthType)
  MX_VISIT_ENTITY(AttributedType, equivalent_type, getVal306, setVal306, initVal306, EquivalentType, Type, NthType, TypeUseSelector::EQUIVALENT_TYPE)
  MX_VISIT_OPTIONAL_ENUM(AttributedType, immediate_nullability, getVal332, setVal332, initVal332, ImmediateNullability, NullabilityKind, NthType)
  MX_VISIT_ENTITY(AttributedType, modified_type, getVal311, setVal311, initVal311, ModifiedType, Type, NthType, TypeUseSelector::MODIFIED_TYPE)
  MX_VISIT_BOOL(AttributedType, is_calling_conv, getVal308, setVal308, initVal308, IsCallingConv, bool, NthType)
  MX_VISIT_BOOL(AttributedType, is_ms_type_spec, getVal309, setVal309, initVal309, IsMSTypeSpec, bool, NthType)
  MX_VISIT_BOOL(AttributedType, is_qualifier, getVal316, setVal316, initVal316, IsQualifier, bool, NthType)
  MX_VISIT_BOOL(AttributedType, is_sugared, getVal317, setVal317, initVal317, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(AtomicType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(AtomicType, value_type, getVal306, setVal306, initVal306, ValueType, Type, NthType, TypeUseSelector::VALUE_TYPE)
  MX_VISIT_BOOL(AtomicType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ArrayType, element_type, getVal305, setVal305, initVal305, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENUM(ArrayType, size_modifier, getVal332, setVal332, initVal332, SizeModifier, ArrayTypeArraySizeModifier, NthType)
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
  MX_VISIT_ENTITY(VariableArrayType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(VariableArrayType, l_bracket_token, getVal328, setVal328, initVal328, LBracketToken, Token, NthType, TokenUseSelector::L_BRACKET_TOKEN)
  MX_VISIT_ENTITY(VariableArrayType, r_bracket_token, getVal329, setVal329, initVal329, RBracketToken, Token, NthType, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(VariableArrayType, size_expression, getVal335, setVal335, initVal335, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(VariableArrayType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(IncompleteArrayType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(IncompleteArrayType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(DependentSizedArrayType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(DependentSizedArrayType, l_bracket_token, getVal328, setVal328, initVal328, LBracketToken, Token, NthType, TokenUseSelector::L_BRACKET_TOKEN)
  MX_VISIT_ENTITY(DependentSizedArrayType, r_bracket_token, getVal329, setVal329, initVal329, RBracketToken, Token, NthType, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(DependentSizedArrayType, size_expression, getVal335, setVal335, initVal335, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(DependentSizedArrayType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(ConstantArrayType, desugar, getVal306, setVal306, initVal306, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_OPTIONAL_ENTITY(ConstantArrayType, size_expression, getVal311, setVal311, initVal311, SizeExpression, Expr, NthType, StmtUseSelector::SIZE_EXPRESSION)
  MX_VISIT_BOOL(ConstantArrayType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(AdjustedType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(AdjustedType, resolved_type, getVal306, setVal306, initVal306, ResolvedType, Type, NthType, TypeUseSelector::RESOLVED_TYPE)
  MX_VISIT_ENTITY(AdjustedType, original_type, getVal311, setVal311, initVal311, OriginalType, Type, NthType, TypeUseSelector::ORIGINAL_TYPE)
  MX_VISIT_BOOL(AdjustedType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENUM(TypeWithKeyword, keyword, getVal332, setVal332, initVal332, Keyword, ElaboratedTypeKeyword, NthType)
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
  MX_VISIT_ENTITY(ElaboratedType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(ElaboratedType, named_type, getVal306, setVal306, initVal306, NamedType, Type, NthType, TypeUseSelector::NAMED_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(ElaboratedType, owned_tag_declaration, getVal311, setVal311, initVal311, OwnedTagDeclaration, TagDecl, NthType, DeclUseSelector::OWNED_TAG_DECLARATION)
  MX_VISIT_BOOL(ElaboratedType, is_sugared, getVal308, setVal308, initVal308, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(DependentTemplateSpecializationType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(DependentTemplateSpecializationType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
  MX_VISIT_PSEUDO_LIST(DependentTemplateSpecializationType, template_arguments, getVal310, setVal310, initVal310, TemplateArguments, TemplateArgument, NthType)
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
  MX_VISIT_ENTITY(DependentNameType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_BOOL(DependentNameType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(VectorType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(VectorType, element_type, getVal306, setVal306, initVal306, ElementType, Type, NthType, TypeUseSelector::ELEMENT_TYPE)
  MX_VISIT_ENUM(VectorType, vector_kind, getVal332, setVal332, initVal332, VectorKind, VectorTypeVectorKind, NthType)
  MX_VISIT_BOOL(VectorType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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

#ifndef MX_ENTER_VISIT_UnresolvedUsingType
#  define MX_ENTER_VISIT_UnresolvedUsingType MX_ENTER_VISIT_Type
#endif
#ifndef MX_EXIT_VISIT_UnresolvedUsingType
#  define MX_EXIT_VISIT_UnresolvedUsingType MX_EXIT_VISIT_Type
#endif

MX_BEGIN_VISIT_TYPE(UnresolvedUsingType)
  MX_ENTER_VISIT_UnresolvedUsingType
  MX_VISIT_BASE(UnresolvedUsingType, Type)
  MX_VISIT_ENTITY(UnresolvedUsingType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(UnresolvedUsingType, declaration, getVal306, setVal306, initVal306, Declaration, UnresolvedUsingTypenameDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(UnresolvedUsingType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(UnaryTransformType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(UnaryTransformType, base_type, getVal306, setVal306, initVal306, BaseType, Type, NthType, TypeUseSelector::BASE_TYPE)
  MX_VISIT_ENUM(UnaryTransformType, utt_kind, getVal332, setVal332, initVal332, UTTKind, UnaryTransformTypeUTTKind, NthType)
  MX_VISIT_ENTITY(UnaryTransformType, underlying_type, getVal311, setVal311, initVal311, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(UnaryTransformType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(TypedefType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TypedefType, declaration, getVal306, setVal306, initVal306, Declaration, TypedefNameDecl, NthType, DeclUseSelector::DECLARATION)
  MX_VISIT_BOOL(TypedefType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(TypeOfType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TypeOfType, underlying_type, getVal306, setVal306, initVal306, UnderlyingType, Type, NthType, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(TypeOfType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_ENTITY(TypeOfExprType, desugar, getVal305, setVal305, initVal305, Desugar, Type, NthType, TypeUseSelector::DESUGAR)
  MX_VISIT_ENTITY(TypeOfExprType, underlying_expression, getVal306, setVal306, initVal306, UnderlyingExpression, Expr, NthType, StmtUseSelector::UNDERLYING_EXPRESSION)
  MX_VISIT_BOOL(TypeOfExprType, is_sugared, getVal307, setVal307, initVal307, IsSugared, bool, NthType)
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
  MX_VISIT_DECL_LINK(Stmt, parent_declaration, getVal0, setVal0, initVal0)
  MX_VISIT_STMT_LINK(Stmt, parent_statement, getVal1, setVal1, initVal1)
  MX_VISIT_ENTITY(Stmt, ignore_containers, getVal2, setVal2, initVal2, IgnoreContainers, Stmt, NthStmt, StmtUseSelector::IGNORE_CONTAINERS)
  MX_VISIT_ENTITY_LIST(Stmt, children, getVal3, setVal3, initVal3, Children, Stmt, NthStmt)
  MX_VISIT_ENTITY(Stmt, begin_token, getVal4, setVal4, initVal4, BeginToken, Token, NthStmt, TokenUseSelector::BEGIN_TOKEN)
  MX_VISIT_ENTITY(Stmt, end_token, getVal5, setVal5, initVal5, EndToken, Token, NthStmt, TokenUseSelector::END_TOKEN)
  MX_VISIT_ENUM(Stmt, kind, getVal8, setVal8, initVal8, Kind, StmtKind, NthStmt)
  MX_VISIT_ENTITY(Stmt, strip_label_like_statements, getVal9, setVal9, initVal9, StripLabelLikeStatements, Stmt, NthStmt, StmtUseSelector::STRIP_LABEL_LIKE_STATEMENTS)
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
  MX_VISIT_ENTITY(SEHTryStmt, except_handler, getVal10, setVal10, initVal10, ExceptHandler, SEHExceptStmt, NthStmt, StmtUseSelector::EXCEPT_HANDLER)
  MX_VISIT_ENTITY(SEHTryStmt, finally_handler, getVal11, setVal11, initVal11, FinallyHandler, SEHFinallyStmt, NthStmt, StmtUseSelector::FINALLY_HANDLER)
  MX_VISIT_ENTITY(SEHTryStmt, handler, getVal12, setVal12, initVal12, Handler, Stmt, NthStmt, StmtUseSelector::HANDLER)
  MX_VISIT_BOOL(SEHTryStmt, is_cxx_try, getVal13, setVal13, initVal13, IsCXXTry, bool, NthStmt)
  MX_VISIT_ENTITY(SEHTryStmt, try_block, getVal14, setVal14, initVal14, TryBlock, CompoundStmt, NthStmt, StmtUseSelector::TRY_BLOCK)
  MX_VISIT_ENTITY(SEHTryStmt, try_token, getVal15, setVal15, initVal15, TryToken, Token, NthStmt, TokenUseSelector::TRY_TOKEN)
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
  MX_VISIT_ENTITY(SEHLeaveStmt, leave_token, getVal10, setVal10, initVal10, LeaveToken, Token, NthStmt, TokenUseSelector::LEAVE_TOKEN)
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
  MX_VISIT_ENTITY(SEHFinallyStmt, block, getVal10, setVal10, initVal10, Block, CompoundStmt, NthStmt, StmtUseSelector::BLOCK)
  MX_VISIT_ENTITY(SEHFinallyStmt, finally_token, getVal11, setVal11, initVal11, FinallyToken, Token, NthStmt, TokenUseSelector::FINALLY_TOKEN)
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
  MX_VISIT_ENTITY(SEHExceptStmt, block, getVal10, setVal10, initVal10, Block, CompoundStmt, NthStmt, StmtUseSelector::BLOCK)
  MX_VISIT_ENTITY(SEHExceptStmt, except_token, getVal11, setVal11, initVal11, ExceptToken, Token, NthStmt, TokenUseSelector::EXCEPT_TOKEN)
  MX_VISIT_ENTITY(SEHExceptStmt, filter_expression, getVal12, setVal12, initVal12, FilterExpression, Expr, NthStmt, StmtUseSelector::FILTER_EXPRESSION)
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
  MX_VISIT_OPTIONAL_ENTITY(ReturnStmt, nrvo_candidate, getVal10, setVal10, initVal10, NRVOCandidate, VarDecl, NthStmt, DeclUseSelector::NRVO_CANDIDATE)
  MX_VISIT_OPTIONAL_ENTITY(ReturnStmt, return_value, getVal11, setVal11, initVal11, ReturnValue, Expr, NthStmt, StmtUseSelector::RETURN_VALUE)
  MX_VISIT_ENTITY(ReturnStmt, return_token, getVal12, setVal12, initVal12, ReturnToken, Token, NthStmt, TokenUseSelector::RETURN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCForCollectionStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, collection, getVal11, setVal11, initVal11, Collection, Expr, NthStmt, StmtUseSelector::COLLECTION)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, element, getVal12, setVal12, initVal12, Element, Stmt, NthStmt, StmtUseSelector::ELEMENT)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, for_token, getVal14, setVal14, initVal14, ForToken, Token, NthStmt, TokenUseSelector::FOR_TOKEN)
  MX_VISIT_ENTITY(ObjCForCollectionStmt, r_paren_token, getVal15, setVal15, initVal15, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCAutoreleasePoolStmt, at_token, getVal10, setVal10, initVal10, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCAutoreleasePoolStmt, sub_statement, getVal11, setVal11, initVal11, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
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
  MX_VISIT_ENTITY(ObjCAtTryStmt, at_try_token, getVal10, setVal10, initVal10, AtTryToken, Token, NthStmt, TokenUseSelector::AT_TRY_TOKEN)
  MX_VISIT_ENTITY(ObjCAtTryStmt, finally_statement, getVal11, setVal11, initVal11, FinallyStatement, ObjCAtFinallyStmt, NthStmt, StmtUseSelector::FINALLY_STATEMENT)
  MX_VISIT_ENTITY(ObjCAtTryStmt, try_body, getVal12, setVal12, initVal12, TryBody, Stmt, NthStmt, StmtUseSelector::TRY_BODY)
  MX_VISIT_ENTITY_LIST(ObjCAtTryStmt, catch_statements, getVal17, setVal17, initVal17, CatchStatements, ObjCAtCatchStmt, NthStmt)
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
  MX_VISIT_ENTITY(ObjCAtThrowStmt, throw_expression, getVal10, setVal10, initVal10, ThrowExpression, Expr, NthStmt, StmtUseSelector::THROW_EXPRESSION)
  MX_VISIT_ENTITY(ObjCAtThrowStmt, throw_token, getVal11, setVal11, initVal11, ThrowToken, Token, NthStmt, TokenUseSelector::THROW_TOKEN)
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
  MX_VISIT_ENTITY(ObjCAtSynchronizedStmt, at_synchronized_token, getVal10, setVal10, initVal10, AtSynchronizedToken, Token, NthStmt, TokenUseSelector::AT_SYNCHRONIZED_TOKEN)
  MX_VISIT_ENTITY(ObjCAtSynchronizedStmt, synch_body, getVal11, setVal11, initVal11, SynchBody, CompoundStmt, NthStmt, StmtUseSelector::SYNCH_BODY)
  MX_VISIT_ENTITY(ObjCAtSynchronizedStmt, synch_expression, getVal12, setVal12, initVal12, SynchExpression, Expr, NthStmt, StmtUseSelector::SYNCH_EXPRESSION)
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
  MX_VISIT_ENTITY(ObjCAtFinallyStmt, at_finally_token, getVal10, setVal10, initVal10, AtFinallyToken, Token, NthStmt, TokenUseSelector::AT_FINALLY_TOKEN)
  MX_VISIT_ENTITY(ObjCAtFinallyStmt, finally_body, getVal11, setVal11, initVal11, FinallyBody, Stmt, NthStmt, StmtUseSelector::FINALLY_BODY)
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
  MX_VISIT_ENTITY(ObjCAtCatchStmt, at_catch_token, getVal10, setVal10, initVal10, AtCatchToken, Token, NthStmt, TokenUseSelector::AT_CATCH_TOKEN)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, catch_body, getVal11, setVal11, initVal11, CatchBody, Stmt, NthStmt, StmtUseSelector::CATCH_BODY)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, catch_parameter_declaration, getVal12, setVal12, initVal12, CatchParameterDeclaration, VarDecl, NthStmt, DeclUseSelector::CATCH_PARAMETER_DECLARATION)
  MX_VISIT_ENTITY(ObjCAtCatchStmt, r_paren_token, getVal14, setVal14, initVal14, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(ObjCAtCatchStmt, has_ellipsis, getVal13, setVal13, initVal13, HasEllipsis, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPExecutableDirective, associated_statement, getVal10, setVal10, initVal10, AssociatedStatement, Stmt, NthStmt, StmtUseSelector::ASSOCIATED_STATEMENT)
  MX_VISIT_ENTITY(OMPExecutableDirective, innermost_captured_statement, getVal11, setVal11, initVal11, InnermostCapturedStatement, CapturedStmt, NthStmt, StmtUseSelector::INNERMOST_CAPTURED_STATEMENT)
  MX_VISIT_ENTITY(OMPExecutableDirective, raw_statement, getVal12, setVal12, initVal12, RawStatement, Stmt, NthStmt, StmtUseSelector::RAW_STATEMENT)
  MX_VISIT_ENTITY(OMPExecutableDirective, structured_block, getVal14, setVal14, initVal14, StructuredBlock, Stmt, NthStmt, StmtUseSelector::STRUCTURED_BLOCK)
  MX_VISIT_BOOL(OMPExecutableDirective, has_associated_statement, getVal13, setVal13, initVal13, HasAssociatedStatement, bool, NthStmt)
  MX_VISIT_BOOL(OMPExecutableDirective, is_standalone_directive, getVal16, setVal16, initVal16, IsStandaloneDirective, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPDispatchDirective, target_call_token, getVal15, setVal15, initVal15, TargetCallToken, Token, NthStmt, TokenUseSelector::TARGET_CALL_TOKEN)
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
  MX_VISIT_ENTITY(OMPAtomicDirective, expression, getVal15, setVal15, initVal15, Expression, Expr, NthStmt, StmtUseSelector::EXPRESSION)
  MX_VISIT_ENTITY(OMPAtomicDirective, update_expression, getVal18, setVal18, initVal18, UpdateExpression, Expr, NthStmt, StmtUseSelector::UPDATE_EXPRESSION)
  MX_VISIT_ENTITY(OMPAtomicDirective, v, getVal19, setVal19, initVal19, V, Expr, NthStmt, StmtUseSelector::V)
  MX_VISIT_ENTITY(OMPAtomicDirective, x, getVal20, setVal20, initVal20, X, Expr, NthStmt, StmtUseSelector::X)
  MX_VISIT_BOOL(OMPAtomicDirective, is_postfix_update, getVal21, setVal21, initVal21, IsPostfixUpdate, bool, NthStmt)
  MX_VISIT_BOOL(OMPAtomicDirective, is_xlhs_in_rhs_part, getVal22, setVal22, initVal22, IsXLHSInRHSPart, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPTaskgroupDirective, reduction_reference, getVal15, setVal15, initVal15, ReductionReference, Expr, NthStmt, StmtUseSelector::REDUCTION_REFERENCE)
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
  MX_VISIT_BOOL(OMPTaskDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPTargetParallelDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTargetParallelDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPSectionsDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPSectionsDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_BOOL(OMPSectionDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPParallelSectionsDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPParallelSectionsDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPParallelMasterDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
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
  MX_VISIT_ENTITY(OMPParallelDirective, task_reduction_reference_expression, getVal15, setVal15, initVal15, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPParallelDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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

#ifndef MX_ENTER_VISIT_OMPUnrollDirective
#  define MX_ENTER_VISIT_OMPUnrollDirective MX_ENTER_VISIT_OMPLoopBasedDirective
#endif
#ifndef MX_EXIT_VISIT_OMPUnrollDirective
#  define MX_EXIT_VISIT_OMPUnrollDirective MX_EXIT_VISIT_OMPLoopBasedDirective
#endif

MX_BEGIN_VISIT_STMT(OMPUnrollDirective)
  MX_ENTER_VISIT_OMPUnrollDirective
  MX_VISIT_BASE(OMPUnrollDirective, OMPLoopBasedDirective)
  MX_VISIT_ENTITY(OMPUnrollDirective, pre_initializers, getVal15, setVal15, initVal15, PreInitializers, Stmt, NthStmt, StmtUseSelector::PRE_INITIALIZERS)
  MX_VISIT_ENTITY(OMPUnrollDirective, transformed_statement, getVal18, setVal18, initVal18, TransformedStatement, Stmt, NthStmt, StmtUseSelector::TRANSFORMED_STATEMENT)
  MX_EXIT_VISIT_OMPUnrollDirective
MX_END_VISIT_STMT(OMPUnrollDirective)

#ifndef MX_ENTER_VISIT_OMPTileDirective
#  define MX_ENTER_VISIT_OMPTileDirective MX_ENTER_VISIT_OMPLoopBasedDirective
#endif
#ifndef MX_EXIT_VISIT_OMPTileDirective
#  define MX_EXIT_VISIT_OMPTileDirective MX_EXIT_VISIT_OMPLoopBasedDirective
#endif

MX_BEGIN_VISIT_STMT(OMPTileDirective)
  MX_ENTER_VISIT_OMPTileDirective
  MX_VISIT_BASE(OMPTileDirective, OMPLoopBasedDirective)
  MX_VISIT_ENTITY(OMPTileDirective, pre_initializers, getVal15, setVal15, initVal15, PreInitializers, Stmt, NthStmt, StmtUseSelector::PRE_INITIALIZERS)
  MX_VISIT_ENTITY(OMPTileDirective, transformed_statement, getVal18, setVal18, initVal18, TransformedStatement, Stmt, NthStmt, StmtUseSelector::TRANSFORMED_STATEMENT)
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
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, counters, getVal17, setVal17, initVal17, Counters, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, dependent_counters, getVal23, setVal23, initVal23, DependentCounters, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, dependent_initializers, getVal24, setVal24, initVal24, DependentInitializers, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, finals, getVal25, setVal25, initVal25, Finals, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, finals_conditions, getVal26, setVal26, initVal26, FinalsConditions, Expr, NthStmt)
  MX_VISIT_ENTITY(OMPLoopDirective, body, getVal15, setVal15, initVal15, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(OMPLoopDirective, calculate_last_iteration, getVal18, setVal18, initVal18, CalculateLastIteration, Expr, NthStmt, StmtUseSelector::CALCULATE_LAST_ITERATION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_condition, getVal19, setVal19, initVal19, CombinedCondition, Expr, NthStmt, StmtUseSelector::COMBINED_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_distance_condition, getVal20, setVal20, initVal20, CombinedDistanceCondition, Expr, NthStmt, StmtUseSelector::COMBINED_DISTANCE_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_ensure_upper_bound, getVal27, setVal27, initVal27, CombinedEnsureUpperBound, Expr, NthStmt, StmtUseSelector::COMBINED_ENSURE_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_initializer, getVal28, setVal28, initVal28, CombinedInitializer, Expr, NthStmt, StmtUseSelector::COMBINED_INITIALIZER)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_lower_bound_variable, getVal29, setVal29, initVal29, CombinedLowerBoundVariable, Expr, NthStmt, StmtUseSelector::COMBINED_LOWER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_next_lower_bound, getVal30, setVal30, initVal30, CombinedNextLowerBound, Expr, NthStmt, StmtUseSelector::COMBINED_NEXT_LOWER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_next_upper_bound, getVal31, setVal31, initVal31, CombinedNextUpperBound, Expr, NthStmt, StmtUseSelector::COMBINED_NEXT_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_parallel_for_in_distance_condition, getVal32, setVal32, initVal32, CombinedParallelForInDistanceCondition, Expr, NthStmt, StmtUseSelector::COMBINED_PARALLEL_FOR_IN_DISTANCE_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, combined_upper_bound_variable, getVal33, setVal33, initVal33, CombinedUpperBoundVariable, Expr, NthStmt, StmtUseSelector::COMBINED_UPPER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, condition, getVal34, setVal34, initVal34, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, distance_increment, getVal35, setVal35, initVal35, DistanceIncrement, Expr, NthStmt, StmtUseSelector::DISTANCE_INCREMENT)
  MX_VISIT_ENTITY(OMPLoopDirective, ensure_upper_bound, getVal36, setVal36, initVal36, EnsureUpperBound, Expr, NthStmt, StmtUseSelector::ENSURE_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, increment, getVal37, setVal37, initVal37, Increment, Expr, NthStmt, StmtUseSelector::INCREMENT)
  MX_VISIT_ENTITY(OMPLoopDirective, initializer, getVal38, setVal38, initVal38, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(OMPLoopDirective, is_last_iteration_variable, getVal39, setVal39, initVal39, IsLastIterationVariable, Expr, NthStmt, StmtUseSelector::IS_LAST_ITERATION_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, iteration_variable, getVal40, setVal40, initVal40, IterationVariable, Expr, NthStmt, StmtUseSelector::ITERATION_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, last_iteration, getVal41, setVal41, initVal41, LastIteration, Expr, NthStmt, StmtUseSelector::LAST_ITERATION)
  MX_VISIT_ENTITY(OMPLoopDirective, lower_bound_variable, getVal42, setVal42, initVal42, LowerBoundVariable, Expr, NthStmt, StmtUseSelector::LOWER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, next_lower_bound, getVal43, setVal43, initVal43, NextLowerBound, Expr, NthStmt, StmtUseSelector::NEXT_LOWER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, next_upper_bound, getVal44, setVal44, initVal44, NextUpperBound, Expr, NthStmt, StmtUseSelector::NEXT_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, num_iterations, getVal45, setVal45, initVal45, NumIterations, Expr, NthStmt, StmtUseSelector::NUM_ITERATIONS)
  MX_VISIT_ENTITY(OMPLoopDirective, pre_condition, getVal46, setVal46, initVal46, PreCondition, Expr, NthStmt, StmtUseSelector::PRE_CONDITION)
  MX_VISIT_ENTITY(OMPLoopDirective, pre_initializers, getVal47, setVal47, initVal47, PreInitializers, Stmt, NthStmt, StmtUseSelector::PRE_INITIALIZERS)
  MX_VISIT_ENTITY(OMPLoopDirective, prev_ensure_upper_bound, getVal48, setVal48, initVal48, PrevEnsureUpperBound, Expr, NthStmt, StmtUseSelector::PREV_ENSURE_UPPER_BOUND)
  MX_VISIT_ENTITY(OMPLoopDirective, prev_lower_bound_variable, getVal49, setVal49, initVal49, PrevLowerBoundVariable, Expr, NthStmt, StmtUseSelector::PREV_LOWER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, prev_upper_bound_variable, getVal50, setVal50, initVal50, PrevUpperBoundVariable, Expr, NthStmt, StmtUseSelector::PREV_UPPER_BOUND_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, stride_variable, getVal51, setVal51, initVal51, StrideVariable, Expr, NthStmt, StmtUseSelector::STRIDE_VARIABLE)
  MX_VISIT_ENTITY(OMPLoopDirective, upper_bound_variable, getVal52, setVal52, initVal52, UpperBoundVariable, Expr, NthStmt, StmtUseSelector::UPPER_BOUND_VARIABLE)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, initializers, getVal53, setVal53, initVal53, Initializers, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, private_counters, getVal54, setVal54, initVal54, PrivateCounters, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(OMPLoopDirective, updates, getVal55, setVal55, initVal55, Updates, Expr, NthStmt)
  MX_EXIT_VISIT_OMPLoopDirective
MX_END_VISIT_STMT(OMPLoopDirective)

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
  MX_VISIT_ENTITY(OMPForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPDistributeParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPDistributeParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPTeamsDistributeParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTeamsDistributeParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_BOOL(OMPTaskLoopDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPTargetTeamsDistributeParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTargetTeamsDistributeParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPTargetParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPTargetParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_BOOL(OMPParallelMasterTaskLoopDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPParallelForDirective, task_reduction_reference_expression, getVal56, setVal56, initVal56, TaskReductionReferenceExpression, Expr, NthStmt, StmtUseSelector::TASK_REDUCTION_REFERENCE_EXPRESSION)
  MX_VISIT_BOOL(OMPParallelForDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_BOOL(OMPMasterTaskLoopDirective, has_cancel, getVal21, setVal21, initVal21, HasCancel, bool, NthStmt)
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
  MX_VISIT_ENTITY(OMPCanonicalLoop, distance_func, getVal10, setVal10, initVal10, DistanceFunc, CapturedStmt, NthStmt, StmtUseSelector::DISTANCE_FUNC)
  MX_VISIT_ENTITY(OMPCanonicalLoop, loop_statement, getVal11, setVal11, initVal11, LoopStatement, Stmt, NthStmt, StmtUseSelector::LOOP_STATEMENT)
  MX_VISIT_ENTITY(OMPCanonicalLoop, loop_variable_func, getVal12, setVal12, initVal12, LoopVariableFunc, CapturedStmt, NthStmt, StmtUseSelector::LOOP_VARIABLE_FUNC)
  MX_VISIT_ENTITY(OMPCanonicalLoop, loop_variable_reference, getVal14, setVal14, initVal14, LoopVariableReference, DeclRefExpr, NthStmt, StmtUseSelector::LOOP_VARIABLE_REFERENCE)
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
  MX_VISIT_ENTITY(NullStmt, semi_token, getVal10, setVal10, initVal10, SemiToken, Token, NthStmt, TokenUseSelector::SEMI_TOKEN)
  MX_VISIT_BOOL(NullStmt, has_leading_empty_macro, getVal13, setVal13, initVal13, HasLeadingEmptyMacro, bool, NthStmt)
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
  MX_VISIT_ENTITY(MSDependentExistsStmt, keyword_token, getVal10, setVal10, initVal10, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(MSDependentExistsStmt, sub_statement, getVal11, setVal11, initVal11, SubStatement, CompoundStmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_VISIT_BOOL(MSDependentExistsStmt, is_if_exists, getVal13, setVal13, initVal13, IsIfExists, bool, NthStmt)
  MX_VISIT_BOOL(MSDependentExistsStmt, is_if_not_exists, getVal16, setVal16, initVal16, IsIfNotExists, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(IndirectGotoStmt, constant_target, getVal10, setVal10, initVal10, ConstantTarget, LabelDecl, NthStmt, DeclUseSelector::CONSTANT_TARGET)
  MX_VISIT_ENTITY(IndirectGotoStmt, goto_token, getVal11, setVal11, initVal11, GotoToken, Token, NthStmt, TokenUseSelector::GOTO_TOKEN)
  MX_VISIT_ENTITY(IndirectGotoStmt, star_token, getVal12, setVal12, initVal12, StarToken, Token, NthStmt, TokenUseSelector::STAR_TOKEN)
  MX_VISIT_ENTITY(IndirectGotoStmt, target, getVal14, setVal14, initVal14, Target, Expr, NthStmt, StmtUseSelector::TARGET)
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
  MX_VISIT_ENTITY(IfStmt, condition, getVal10, setVal10, initVal10, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, condition_variable, getVal11, setVal11, initVal11, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, condition_variable_declaration_statement, getVal12, setVal12, initVal12, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, else_, getVal14, setVal14, initVal14, Else, Stmt, NthStmt, StmtUseSelector::ELSE_)
  MX_VISIT_ENTITY(IfStmt, else_token, getVal15, setVal15, initVal15, ElseToken, Token, NthStmt, TokenUseSelector::ELSE_TOKEN)
  MX_VISIT_ENTITY(IfStmt, if_token, getVal18, setVal18, initVal18, IfToken, Token, NthStmt, TokenUseSelector::IF_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(IfStmt, initializer, getVal19, setVal19, initVal19, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(IfStmt, l_paren_token, getVal20, setVal20, initVal20, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(IfStmt, r_paren_token, getVal27, setVal27, initVal27, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(IfStmt, then, getVal28, setVal28, initVal28, Then, Stmt, NthStmt, StmtUseSelector::THEN)
  MX_VISIT_BOOL(IfStmt, has_else_storage, getVal57, setVal57, initVal57, HasElseStorage, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, has_initializer_storage, getVal58, setVal58, initVal58, HasInitializerStorage, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, has_variable_storage, getVal59, setVal59, initVal59, HasVariableStorage, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_constexpr, getVal60, setVal60, initVal60, IsConstexpr, bool, NthStmt)
  MX_VISIT_BOOL(IfStmt, is_obj_c_availability_check, getVal61, setVal61, initVal61, IsObjCAvailabilityCheck, bool, NthStmt)
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
  MX_VISIT_ENTITY(GotoStmt, goto_token, getVal10, setVal10, initVal10, GotoToken, Token, NthStmt, TokenUseSelector::GOTO_TOKEN)
  MX_VISIT_ENTITY(GotoStmt, label, getVal11, setVal11, initVal11, Label, LabelDecl, NthStmt, DeclUseSelector::LABEL)
  MX_VISIT_ENTITY(GotoStmt, label_token, getVal12, setVal12, initVal12, LabelToken, Token, NthStmt, TokenUseSelector::LABEL_TOKEN)
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
  MX_VISIT_ENTITY(ForStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, condition_variable, getVal12, setVal12, initVal12, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, condition_variable_declaration_statement, getVal14, setVal14, initVal14, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_ENTITY(ForStmt, for_token, getVal15, setVal15, initVal15, ForToken, Token, NthStmt, TokenUseSelector::FOR_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, increment, getVal18, setVal18, initVal18, Increment, Expr, NthStmt, StmtUseSelector::INCREMENT)
  MX_VISIT_OPTIONAL_ENTITY(ForStmt, initializer, getVal19, setVal19, initVal19, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(ForStmt, l_paren_token, getVal20, setVal20, initVal20, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(ForStmt, r_paren_token, getVal27, setVal27, initVal27, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(DoStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(DoStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(DoStmt, do_token, getVal12, setVal12, initVal12, DoToken, Token, NthStmt, TokenUseSelector::DO_TOKEN)
  MX_VISIT_ENTITY(DoStmt, r_paren_token, getVal14, setVal14, initVal14, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(DoStmt, while_token, getVal15, setVal15, initVal15, WhileToken, Token, NthStmt, TokenUseSelector::WHILE_TOKEN)
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
  MX_VISIT_ENTITY_LIST(DeclStmt, declarations, getVal17, setVal17, initVal17, Declarations, Decl, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(DeclStmt, single_declaration, getVal10, setVal10, initVal10, SingleDeclaration, Decl, NthStmt, DeclUseSelector::SINGLE_DECLARATION)
  MX_VISIT_BOOL(DeclStmt, is_single_declaration, getVal16, setVal16, initVal16, IsSingleDeclaration, bool, NthStmt)
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
  MX_VISIT_ENTITY(CoroutineBodyStmt, allocate, getVal10, setVal10, initVal10, Allocate, Expr, NthStmt, StmtUseSelector::ALLOCATE)
  MX_VISIT_ENTITY(CoroutineBodyStmt, body, getVal11, setVal11, initVal11, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(CoroutineBodyStmt, deallocate, getVal12, setVal12, initVal12, Deallocate, Expr, NthStmt, StmtUseSelector::DEALLOCATE)
  MX_VISIT_ENTITY(CoroutineBodyStmt, exception_handler, getVal14, setVal14, initVal14, ExceptionHandler, Stmt, NthStmt, StmtUseSelector::EXCEPTION_HANDLER)
  MX_VISIT_ENTITY(CoroutineBodyStmt, fallthrough_handler, getVal15, setVal15, initVal15, FallthroughHandler, Stmt, NthStmt, StmtUseSelector::FALLTHROUGH_HANDLER)
  MX_VISIT_ENTITY(CoroutineBodyStmt, final_suspend_statement, getVal18, setVal18, initVal18, FinalSuspendStatement, Stmt, NthStmt, StmtUseSelector::FINAL_SUSPEND_STATEMENT)
  MX_VISIT_ENTITY(CoroutineBodyStmt, initializer_suspend_statement, getVal19, setVal19, initVal19, InitializerSuspendStatement, Stmt, NthStmt, StmtUseSelector::INITIALIZER_SUSPEND_STATEMENT)
  MX_VISIT_ENTITY_LIST(CoroutineBodyStmt, parameter_moves, getVal17, setVal17, initVal17, ParameterMoves, Stmt, NthStmt)
  MX_VISIT_ENTITY(CoroutineBodyStmt, promise_declaration, getVal20, setVal20, initVal20, PromiseDeclaration, VarDecl, NthStmt, DeclUseSelector::PROMISE_DECLARATION)
  MX_VISIT_ENTITY(CoroutineBodyStmt, promise_declaration_statement, getVal27, setVal27, initVal27, PromiseDeclarationStatement, Stmt, NthStmt, StmtUseSelector::PROMISE_DECLARATION_STATEMENT)
  MX_VISIT_ENTITY(CoroutineBodyStmt, result_declaration, getVal28, setVal28, initVal28, ResultDeclaration, Stmt, NthStmt, StmtUseSelector::RESULT_DECLARATION)
  MX_VISIT_ENTITY(CoroutineBodyStmt, return_statement, getVal29, setVal29, initVal29, ReturnStatement, Stmt, NthStmt, StmtUseSelector::RETURN_STATEMENT)
  MX_VISIT_ENTITY(CoroutineBodyStmt, return_statement_on_alloc_failure, getVal30, setVal30, initVal30, ReturnStatementOnAllocFailure, Stmt, NthStmt, StmtUseSelector::RETURN_STATEMENT_ON_ALLOC_FAILURE)
  MX_VISIT_ENTITY(CoroutineBodyStmt, return_value_initializer, getVal31, setVal31, initVal31, ReturnValueInitializer, Expr, NthStmt, StmtUseSelector::RETURN_VALUE_INITIALIZER)
  MX_VISIT_BOOL(CoroutineBodyStmt, has_dependent_promise_type, getVal13, setVal13, initVal13, HasDependentPromiseType, bool, NthStmt)
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
  MX_VISIT_ENTITY(CoreturnStmt, keyword_token, getVal10, setVal10, initVal10, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(CoreturnStmt, operand, getVal11, setVal11, initVal11, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_ENTITY(CoreturnStmt, promise_call, getVal12, setVal12, initVal12, PromiseCall, Expr, NthStmt, StmtUseSelector::PROMISE_CALL)
  MX_VISIT_BOOL(CoreturnStmt, is_implicit, getVal13, setVal13, initVal13, IsImplicit, bool, NthStmt)
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
  MX_VISIT_ENTITY(ContinueStmt, continue_token, getVal10, setVal10, initVal10, ContinueToken, Token, NthStmt, TokenUseSelector::CONTINUE_TOKEN)
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
  MX_VISIT_ENTITY(CompoundStmt, left_brace_token, getVal10, setVal10, initVal10, LeftBraceToken, Token, NthStmt, TokenUseSelector::LEFT_BRACE_TOKEN)
  MX_VISIT_ENTITY(CompoundStmt, right_brace_token, getVal11, setVal11, initVal11, RightBraceToken, Token, NthStmt, TokenUseSelector::RIGHT_BRACE_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(CompoundStmt, statement_expression_result, getVal12, setVal12, initVal12, StatementExpressionResult, Stmt, NthStmt, StmtUseSelector::STATEMENT_EXPRESSION_RESULT)
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
  MX_VISIT_ENTITY(CapturedStmt, captured_declaration, getVal10, setVal10, initVal10, CapturedDeclaration, CapturedDecl, NthStmt, DeclUseSelector::CAPTURED_DECLARATION)
  MX_VISIT_ENTITY(CapturedStmt, captured_record_declaration, getVal11, setVal11, initVal11, CapturedRecordDeclaration, RecordDecl, NthStmt, DeclUseSelector::CAPTURED_RECORD_DECLARATION)
  MX_VISIT_ENUM(CapturedStmt, captured_region_kind, getVal62, setVal62, initVal62, CapturedRegionKind, CapturedRegionKind, NthStmt)
  MX_VISIT_ENTITY(CapturedStmt, captured_statement, getVal12, setVal12, initVal12, CapturedStatement, Stmt, NthStmt, StmtUseSelector::CAPTURED_STATEMENT)
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
  MX_VISIT_ENTITY(CXXTryStmt, try_block, getVal10, setVal10, initVal10, TryBlock, CompoundStmt, NthStmt, StmtUseSelector::TRY_BLOCK)
  MX_VISIT_ENTITY(CXXTryStmt, try_token, getVal11, setVal11, initVal11, TryToken, Token, NthStmt, TokenUseSelector::TRY_TOKEN)
  MX_VISIT_ENTITY_LIST(CXXTryStmt, handlers, getVal17, setVal17, initVal17, Handlers, CXXCatchStmt, NthStmt)
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
  MX_VISIT_ENTITY(CXXForRangeStmt, begin_statement, getVal10, setVal10, initVal10, BeginStatement, DeclStmt, NthStmt, StmtUseSelector::BEGIN_STATEMENT)
  MX_VISIT_ENTITY(CXXForRangeStmt, body, getVal11, setVal11, initVal11, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(CXXForRangeStmt, coawait_token, getVal12, setVal12, initVal12, CoawaitToken, Token, NthStmt, TokenUseSelector::COAWAIT_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, colon_token, getVal14, setVal14, initVal14, ColonToken, Token, NthStmt, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, condition, getVal15, setVal15, initVal15, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(CXXForRangeStmt, end_statement, getVal18, setVal18, initVal18, EndStatement, DeclStmt, NthStmt, StmtUseSelector::END_STATEMENT)
  MX_VISIT_ENTITY(CXXForRangeStmt, for_token, getVal19, setVal19, initVal19, ForToken, Token, NthStmt, TokenUseSelector::FOR_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, increment, getVal20, setVal20, initVal20, Increment, Expr, NthStmt, StmtUseSelector::INCREMENT)
  MX_VISIT_OPTIONAL_ENTITY(CXXForRangeStmt, initializer, getVal27, setVal27, initVal27, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CXXForRangeStmt, loop_variable_statement, getVal28, setVal28, initVal28, LoopVariableStatement, DeclStmt, NthStmt, StmtUseSelector::LOOP_VARIABLE_STATEMENT)
  MX_VISIT_ENTITY(CXXForRangeStmt, loop_variable, getVal29, setVal29, initVal29, LoopVariable, VarDecl, NthStmt, DeclUseSelector::LOOP_VARIABLE)
  MX_VISIT_ENTITY(CXXForRangeStmt, r_paren_token, getVal30, setVal30, initVal30, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXForRangeStmt, range_initializer, getVal31, setVal31, initVal31, RangeInitializer, Expr, NthStmt, StmtUseSelector::RANGE_INITIALIZER)
  MX_VISIT_ENTITY(CXXForRangeStmt, range_statement, getVal32, setVal32, initVal32, RangeStatement, DeclStmt, NthStmt, StmtUseSelector::RANGE_STATEMENT)
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
  MX_VISIT_ENTITY(CXXCatchStmt, catch_token, getVal10, setVal10, initVal10, CatchToken, Token, NthStmt, TokenUseSelector::CATCH_TOKEN)
  MX_VISIT_ENTITY(CXXCatchStmt, caught_type, getVal11, setVal11, initVal11, CaughtType, Type, NthStmt, TypeUseSelector::CAUGHT_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXCatchStmt, exception_declaration, getVal12, setVal12, initVal12, ExceptionDeclaration, VarDecl, NthStmt, DeclUseSelector::EXCEPTION_DECLARATION)
  MX_VISIT_ENTITY(CXXCatchStmt, handler_block, getVal14, setVal14, initVal14, HandlerBlock, Stmt, NthStmt, StmtUseSelector::HANDLER_BLOCK)
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
  MX_VISIT_ENTITY(BreakStmt, break_token, getVal10, setVal10, initVal10, BreakToken, Token, NthStmt, TokenUseSelector::BREAK_TOKEN)
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
  MX_VISIT_TEXT(AsmStmt, generate_assembly_string, getVal63, setVal63, initVal63, GenerateAssemblyString, basic_string, NthStmt)
  MX_VISIT_ENTITY(AsmStmt, assembly_token, getVal10, setVal10, initVal10, AssemblyToken, Token, NthStmt, TokenUseSelector::ASSEMBLY_TOKEN)
  MX_VISIT_ENTITY_LIST(AsmStmt, inputs, getVal17, setVal17, initVal17, Inputs, Expr, NthStmt)
  MX_VISIT_BOOL(AsmStmt, is_simple, getVal13, setVal13, initVal13, IsSimple, bool, NthStmt)
  MX_VISIT_BOOL(AsmStmt, is_volatile, getVal16, setVal16, initVal16, IsVolatile, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(AsmStmt, outputs, getVal23, setVal23, initVal23, Outputs, Expr, NthStmt)
  MX_VISIT_TEXT_LIST(AsmStmt, output_constraints, getVal64, setVal64, initVal64, OutputConstraints, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(AsmStmt, output_expressions, getVal24, setVal24, initVal24, OutputExpressions, Expr, NthStmt)
  MX_VISIT_TEXT_LIST(AsmStmt, input_constraints, getVal65, setVal65, initVal65, InputConstraints, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(AsmStmt, input_expressions, getVal25, setVal25, initVal25, InputExpressions, Expr, NthStmt)
  MX_VISIT_TEXT_LIST(AsmStmt, clobbers, getVal66, setVal66, initVal66, Clobbers, basic_string_view, NthStmt)
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
  MX_VISIT_TEXT_LIST(MSAsmStmt, all_constraints, getVal67, setVal67, initVal67, AllConstraints, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(MSAsmStmt, all_expressions, getVal26, setVal26, initVal26, AllExpressions, Expr, NthStmt)
  MX_VISIT_TEXT(MSAsmStmt, assembly_string, getVal68, setVal68, initVal68, AssemblyString, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(MSAsmStmt, l_brace_token, getVal11, setVal11, initVal11, LBraceToken, Token, NthStmt, TokenUseSelector::L_BRACE_TOKEN)
  MX_VISIT_BOOL(MSAsmStmt, has_braces, getVal21, setVal21, initVal21, HasBraces, bool, NthStmt)
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
  MX_VISIT_ENTITY(GCCAsmStmt, assembly_string, getVal11, setVal11, initVal11, AssemblyString, StringLiteral, NthStmt, StmtUseSelector::ASSEMBLY_STRING)
  MX_VISIT_ENTITY(GCCAsmStmt, r_paren_token, getVal12, setVal12, initVal12, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(GCCAsmStmt, is_assembly_goto, getVal21, setVal21, initVal21, IsAssemblyGoto, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, labels, getVal26, setVal26, initVal26, Labels, AddrLabelExpr, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, output_constraint_literals, getVal53, setVal53, initVal53, OutputConstraintLiterals, StringLiteral, NthStmt)
  MX_VISIT_TEXT_LIST(GCCAsmStmt, output_names, getVal67, setVal67, initVal67, OutputNames, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, input_constraint_literals, getVal54, setVal54, initVal54, InputConstraintLiterals, StringLiteral, NthStmt)
  MX_VISIT_TEXT_LIST(GCCAsmStmt, input_names, getVal69, setVal69, initVal69, InputNames, basic_string_view, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, clobber_string_literals, getVal55, setVal55, initVal55, ClobberStringLiterals, StringLiteral, NthStmt)
  MX_VISIT_ENTITY_LIST(GCCAsmStmt, label_expressions, getVal70, setVal70, initVal70, LabelExpressions, AddrLabelExpr, NthStmt)
  MX_VISIT_TEXT_LIST(GCCAsmStmt, label_names, getVal71, setVal71, initVal71, LabelNames, basic_string_view, NthStmt)
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
  MX_VISIT_ENTITY(WhileStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(WhileStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(WhileStmt, condition_variable, getVal12, setVal12, initVal12, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(WhileStmt, condition_variable_declaration_statement, getVal14, setVal14, initVal14, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_ENTITY(WhileStmt, l_paren_token, getVal15, setVal15, initVal15, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(WhileStmt, r_paren_token, getVal18, setVal18, initVal18, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(WhileStmt, while_token, getVal19, setVal19, initVal19, WhileToken, Token, NthStmt, TokenUseSelector::WHILE_TOKEN)
  MX_VISIT_BOOL(WhileStmt, has_variable_storage, getVal21, setVal21, initVal21, HasVariableStorage, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(ValueStmt, expression_statement, getVal10, setVal10, initVal10, ExpressionStatement, Expr, NthStmt, StmtUseSelector::EXPRESSION_STATEMENT)
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
  MX_VISIT_ENTITY(LabelStmt, declaration, getVal11, setVal11, initVal11, Declaration, LabelDecl, NthStmt, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(LabelStmt, identifier_token, getVal12, setVal12, initVal12, IdentifierToken, Token, NthStmt, TokenUseSelector::IDENTIFIER_TOKEN)
  MX_VISIT_TEXT(LabelStmt, name, getVal63, setVal63, initVal63, Name, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(LabelStmt, sub_statement, getVal14, setVal14, initVal14, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
  MX_VISIT_BOOL(LabelStmt, is_side_entry, getVal16, setVal16, initVal16, IsSideEntry, bool, NthStmt)
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
  MX_VISIT_BOOL(Expr, has_side_effects, getVal16, setVal16, initVal16, HasSideEffects, bool, NthStmt)
  MX_VISIT_ENTITY(Expr, ignore_casts, getVal11, setVal11, initVal11, IgnoreCasts, Expr, NthStmt, StmtUseSelector::IGNORE_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_conversion_operator_single_step, getVal12, setVal12, initVal12, IgnoreConversionOperatorSingleStep, Expr, NthStmt, StmtUseSelector::IGNORE_CONVERSION_OPERATOR_SINGLE_STEP)
  MX_VISIT_ENTITY(Expr, ignore_imp_casts, getVal14, setVal14, initVal14, IgnoreImpCasts, Expr, NthStmt, StmtUseSelector::IGNORE_IMP_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_implicit, getVal15, setVal15, initVal15, IgnoreImplicit, Expr, NthStmt, StmtUseSelector::IGNORE_IMPLICIT)
  MX_VISIT_ENTITY(Expr, ignore_implicit_as_written, getVal18, setVal18, initVal18, IgnoreImplicitAsWritten, Expr, NthStmt, StmtUseSelector::IGNORE_IMPLICIT_AS_WRITTEN)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_base_casts, getVal19, setVal19, initVal19, IgnoreParenthesisBaseCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_BASE_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_casts, getVal20, setVal20, initVal20, IgnoreParenthesisCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_imp_casts, getVal27, setVal27, initVal27, IgnoreParenthesisImpCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_IMP_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_l_value_casts, getVal28, setVal28, initVal28, IgnoreParenthesisLValueCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_L_VALUE_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parenthesis_noop_casts, getVal29, setVal29, initVal29, IgnoreParenthesisNoopCasts, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESIS_NOOP_CASTS)
  MX_VISIT_ENTITY(Expr, ignore_parentheses, getVal30, setVal30, initVal30, IgnoreParentheses, Expr, NthStmt, StmtUseSelector::IGNORE_PARENTHESES)
  MX_VISIT_ENTITY(Expr, ignore_unless_spelled_in_source, getVal31, setVal31, initVal31, IgnoreUnlessSpelledInSource, Expr, NthStmt, StmtUseSelector::IGNORE_UNLESS_SPELLED_IN_SOURCE)
  MX_VISIT_BOOL(Expr, contains_errors, getVal21, setVal21, initVal21, ContainsErrors, bool, NthStmt)
  MX_VISIT_BOOL(Expr, contains_unexpanded_parameter_pack, getVal22, setVal22, initVal22, ContainsUnexpandedParameterPack, bool, NthStmt)
  MX_VISIT_ENTITY(Expr, best_dynamic_class_type_expression, getVal32, setVal32, initVal32, BestDynamicClassTypeExpression, Expr, NthStmt, StmtUseSelector::BEST_DYNAMIC_CLASS_TYPE_EXPRESSION)
  MX_VISIT_ENTITY(Expr, expression_token, getVal33, setVal33, initVal33, ExpressionToken, Token, NthStmt, TokenUseSelector::EXPRESSION_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(Expr, obj_c_property, getVal34, setVal34, initVal34, ObjCProperty, ObjCPropertyRefExpr, NthStmt, StmtUseSelector::OBJ_C_PROPERTY)
  MX_VISIT_ENUM(Expr, object_kind, getVal62, setVal62, initVal62, ObjectKind, ExprObjectKind, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(Expr, referenced_declaration_of_callee, getVal35, setVal35, initVal35, ReferencedDeclarationOfCallee, Decl, NthStmt, DeclUseSelector::REFERENCED_DECLARATION_OF_CALLEE)
  MX_VISIT_OPTIONAL_ENTITY(Expr, source_bit_field, getVal36, setVal36, initVal36, SourceBitField, FieldDecl, NthStmt, DeclUseSelector::SOURCE_BIT_FIELD)
  MX_VISIT_ENTITY(Expr, type, getVal37, setVal37, initVal37, Type, Type, NthStmt, TypeUseSelector::TYPE)
  MX_VISIT_ENUM(Expr, value_kind, getVal72, setVal72, initVal72, ValueKind, ExprValueKind, NthStmt)
  MX_VISIT_BOOL(Expr, has_non_trivial_call, getVal60, setVal60, initVal60, HasNonTrivialCall, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(Expr, is_cxx11_constant_expression, getVal61, setVal61, initVal61, IsCXX11ConstantExpression, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(Expr, is_cxx98_integral_constant_expression, getVal74, setVal74, initVal74, IsCXX98IntegralConstantExpression, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_default_argument, getVal76, setVal76, initVal76, IsDefaultArgument, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(Expr, is_evaluatable, getVal77, setVal77, initVal77, IsEvaluatable, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_gl_value, getVal79, setVal79, initVal79, IsGLValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_implicit_cxx_this, getVal80, setVal80, initVal80, IsImplicitCXXThis, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_instantiation_dependent, getVal81, setVal81, initVal81, IsInstantiationDependent, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(Expr, is_integer_constant_expression, getVal82, setVal82, initVal82, IsIntegerConstantExpression, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_known_to_have_boolean_value, getVal84, setVal84, initVal84, IsKnownToHaveBooleanValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_l_value, getVal85, setVal85, initVal85, IsLValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_objcgc_candidate, getVal86, setVal86, initVal86, IsOBJCGCCandidate, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_obj_c_self_expression, getVal87, setVal87, initVal87, IsObjCSelfExpression, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_ordinary_or_bit_field_object, getVal88, setVal88, initVal88, IsOrdinaryOrBitFieldObject, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_pr_value, getVal89, setVal89, initVal89, IsPRValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_read_if_discarded_in_c_plus_plus11, getVal90, setVal90, initVal90, IsReadIfDiscardedInCPlusPlus11, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_type_dependent, getVal91, setVal91, initVal91, IsTypeDependent, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_value_dependent, getVal92, setVal92, initVal92, IsValueDependent, bool, NthStmt)
  MX_VISIT_BOOL(Expr, is_x_value, getVal93, setVal93, initVal93, IsXValue, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_bit_field, getVal94, setVal94, initVal94, RefersToBitField, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_global_register_variable, getVal95, setVal95, initVal95, RefersToGlobalRegisterVariable, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_matrix_element, getVal96, setVal96, initVal96, RefersToMatrixElement, bool, NthStmt)
  MX_VISIT_BOOL(Expr, refers_to_vector_element, getVal97, setVal97, initVal97, RefersToVectorElement, bool, NthStmt)
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
  MX_VISIT_ENTITY(DesignatedInitUpdateExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(DesignatedInitUpdateExpr, updater, getVal39, setVal39, initVal39, Updater, InitListExpr, NthStmt, StmtUseSelector::UPDATER)
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
  MX_VISIT_ENTITY(DesignatedInitExpr, equal_or_colon_token, getVal40, setVal40, initVal40, EqualOrColonToken, Token, NthStmt, TokenUseSelector::EQUAL_OR_COLON_TOKEN)
  MX_VISIT_ENTITY(DesignatedInitExpr, initializer, getVal41, setVal41, initVal41, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_BOOL(DesignatedInitExpr, is_direct_initializer, getVal98, setVal98, initVal98, IsDirectInitializer, bool, NthStmt)
  MX_VISIT_BOOL(DesignatedInitExpr, uses_gnu_syntax, getVal99, setVal99, initVal99, UsesGNUSyntax, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(DesignatedInitExpr, sub_expressions, getVal17, setVal17, initVal17, SubExpressions, Expr, NthStmt)
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
  MX_VISIT_ENTITY(DependentScopeDeclRefExpr, l_angle_token, getVal38, setVal38, initVal38, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DependentScopeDeclRefExpr, r_angle_token, getVal39, setVal39, initVal39, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DependentScopeDeclRefExpr, template_keyword_token, getVal40, setVal40, initVal40, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(DependentScopeDeclRefExpr, has_explicit_template_arguments, getVal98, setVal98, initVal98, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(DependentScopeDeclRefExpr, has_template_keyword, getVal99, setVal99, initVal99, HasTemplateKeyword, bool, NthStmt)
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
  MX_VISIT_ENTITY(DependentCoawaitExpr, keyword_token, getVal38, setVal38, initVal38, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(DependentCoawaitExpr, operand, getVal39, setVal39, initVal39, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_ENTITY(DependentCoawaitExpr, operator_coawait_lookup, getVal40, setVal40, initVal40, OperatorCoawaitLookup, UnresolvedLookupExpr, NthStmt, StmtUseSelector::OPERATOR_COAWAIT_LOOKUP)
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
  MX_VISIT_ENTITY(DeclRefExpr, declaration, getVal38, setVal38, initVal38, Declaration, ValueDecl, NthStmt, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(DeclRefExpr, found_declaration, getVal39, setVal39, initVal39, FoundDeclaration, NamedDecl, NthStmt, DeclUseSelector::FOUND_DECLARATION)
  MX_VISIT_ENTITY(DeclRefExpr, l_angle_token, getVal40, setVal40, initVal40, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DeclRefExpr, r_angle_token, getVal41, setVal41, initVal41, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(DeclRefExpr, template_keyword_token, getVal42, setVal42, initVal42, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(DeclRefExpr, had_multiple_candidates, getVal98, setVal98, initVal98, HadMultipleCandidates, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_explicit_template_arguments, getVal99, setVal99, initVal99, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_qualifier, getVal100, setVal100, initVal100, HasQualifier, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_template_kw_and_arguments_info, getVal101, setVal101, initVal101, HasTemplateKWAndArgumentsInfo, bool, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, has_template_keyword, getVal102, setVal102, initVal102, HasTemplateKeyword, bool, NthStmt)
  MX_VISIT_ENUM(DeclRefExpr, is_non_odr_use, getVal103, setVal103, initVal103, IsNonOdrUse, NonOdrUseReason, NthStmt)
  MX_VISIT_BOOL(DeclRefExpr, refers_to_enclosing_variable_or_capture, getVal104, setVal104, initVal104, RefersToEnclosingVariableOrCapture, bool, NthStmt)
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
  MX_VISIT_ENTITY(CoroutineSuspendExpr, common_expression, getVal38, setVal38, initVal38, CommonExpression, Expr, NthStmt, StmtUseSelector::COMMON_EXPRESSION)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, keyword_token, getVal39, setVal39, initVal39, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, opaque_value, getVal40, setVal40, initVal40, OpaqueValue, OpaqueValueExpr, NthStmt, StmtUseSelector::OPAQUE_VALUE)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, ready_expression, getVal41, setVal41, initVal41, ReadyExpression, Expr, NthStmt, StmtUseSelector::READY_EXPRESSION)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, resume_expression, getVal42, setVal42, initVal42, ResumeExpression, Expr, NthStmt, StmtUseSelector::RESUME_EXPRESSION)
  MX_VISIT_ENTITY(CoroutineSuspendExpr, suspend_expression, getVal43, setVal43, initVal43, SuspendExpression, Expr, NthStmt, StmtUseSelector::SUSPEND_EXPRESSION)
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
  MX_VISIT_ENTITY(CoawaitExpr, operand, getVal44, setVal44, initVal44, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_BOOL(CoawaitExpr, is_implicit, getVal98, setVal98, initVal98, IsImplicit, bool, NthStmt)
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
  MX_VISIT_ENTITY(CoyieldExpr, operand, getVal44, setVal44, initVal44, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
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
  MX_VISIT_ENTITY(ConvertVectorExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(ConvertVectorExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(ConvertVectorExpr, src_expression, getVal40, setVal40, initVal40, SrcExpression, Expr, NthStmt, StmtUseSelector::SRC_EXPRESSION)
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
  MX_VISIT_PSEUDO_LIST(ConceptSpecializationExpr, template_arguments, getVal105, setVal105, initVal105, TemplateArguments, TemplateArgument, NthStmt)
  MX_VISIT_BOOL(ConceptSpecializationExpr, is_satisfied, getVal98, setVal98, initVal98, IsSatisfied, bool, NthStmt)
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
  MX_VISIT_ENTITY(CompoundLiteralExpr, initializer, getVal38, setVal38, initVal38, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CompoundLiteralExpr, l_paren_token, getVal39, setVal39, initVal39, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_BOOL(CompoundLiteralExpr, is_file_scope, getVal98, setVal98, initVal98, IsFileScope, bool, NthStmt)
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
  MX_VISIT_ENTITY(ChooseExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(ChooseExpr, chosen_sub_expression, getVal39, setVal39, initVal39, ChosenSubExpression, Expr, NthStmt, StmtUseSelector::CHOSEN_SUB_EXPRESSION)
  MX_VISIT_ENTITY(ChooseExpr, condition, getVal40, setVal40, initVal40, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(ChooseExpr, lhs, getVal41, setVal41, initVal41, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(ChooseExpr, rhs, getVal42, setVal42, initVal42, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_ENTITY(ChooseExpr, r_paren_token, getVal43, setVal43, initVal43, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(ChooseExpr, is_condition_dependent, getVal98, setVal98, initVal98, IsConditionDependent, bool, NthStmt)
  MX_VISIT_BOOL(ChooseExpr, is_condition_true, getVal99, setVal99, initVal99, IsConditionTrue, bool, NthStmt)
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
  MX_VISIT_ENTITY(CharacterLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
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
  MX_VISIT_ENUM(CastExpr, cast_kind, getVal103, setVal103, initVal103, CastKind, CastKind, NthStmt)
  MX_VISIT_TEXT(CastExpr, cast_kind_name, getVal63, setVal63, initVal63, CastKindName, basic_string_view, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(CastExpr, conversion_function, getVal38, setVal38, initVal38, ConversionFunction, NamedDecl, NthStmt, DeclUseSelector::CONVERSION_FUNCTION)
  MX_VISIT_ENTITY(CastExpr, sub_expression, getVal39, setVal39, initVal39, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_ENTITY(CastExpr, sub_expression_as_written, getVal40, setVal40, initVal40, SubExpressionAsWritten, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION_AS_WRITTEN)
  MX_VISIT_OPTIONAL_ENTITY(CastExpr, target_union_field, getVal41, setVal41, initVal41, TargetUnionField, FieldDecl, NthStmt, DeclUseSelector::TARGET_UNION_FIELD)
  MX_VISIT_BOOL(CastExpr, has_stored_fp_features, getVal100, setVal100, initVal100, HasStoredFPFeatures, bool, NthStmt)
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
  MX_VISIT_BOOL(ImplicitCastExpr, is_part_of_explicit_cast, getVal101, setVal101, initVal101, IsPartOfExplicitCast, bool, NthStmt)
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
  MX_VISIT_ENTITY(ExplicitCastExpr, type_as_written, getVal42, setVal42, initVal42, TypeAsWritten, Type, NthStmt, TypeUseSelector::TYPE_AS_WRITTEN)
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
  MX_VISIT_TEXT(CXXNamedCastExpr, cast_name, getVal68, setVal68, initVal68, CastName, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(CXXNamedCastExpr, operator_token, getVal45, setVal45, initVal45, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXNamedCastExpr, r_paren_token, getVal46, setVal46, initVal46, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_BOOL(CXXDynamicCastExpr, is_always_null, getVal101, setVal101, initVal101, IsAlwaysNull, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXFunctionalCastExpr, l_paren_token, getVal43, setVal43, initVal43, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXFunctionalCastExpr, r_paren_token, getVal44, setVal44, initVal44, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(CXXFunctionalCastExpr, is_list_initialization, getVal101, setVal101, initVal101, IsListInitialization, bool, NthStmt)
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
  MX_VISIT_ENTITY(CStyleCastExpr, l_paren_token, getVal43, setVal43, initVal43, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(CStyleCastExpr, r_paren_token, getVal44, setVal44, initVal44, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCBridgedCastExpr, bridge_keyword_token, getVal43, setVal43, initVal43, BridgeKeywordToken, Token, NthStmt, TokenUseSelector::BRIDGE_KEYWORD_TOKEN)
  MX_VISIT_ENUM(ObjCBridgedCastExpr, bridge_kind, getVal106, setVal106, initVal106, BridgeKind, ObjCBridgeCastKind, NthStmt)
  MX_VISIT_TEXT(ObjCBridgedCastExpr, bridge_kind_name, getVal68, setVal68, initVal68, BridgeKindName, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(ObjCBridgedCastExpr, l_paren_token, getVal44, setVal44, initVal44, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
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
  MX_VISIT_ENTITY_LIST(CallExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_VISIT_ENUM(CallExpr, adl_call_kind, getVal103, setVal103, initVal103, ADLCallKind, CallExprADLCallKind, NthStmt)
  MX_VISIT_ENTITY(CallExpr, call_return_type, getVal38, setVal38, initVal38, CallReturnType, Type, NthStmt, TypeUseSelector::CALL_RETURN_TYPE)
  MX_VISIT_ENTITY(CallExpr, callee, getVal39, setVal39, initVal39, Callee, Expr, NthStmt, StmtUseSelector::CALLEE)
  MX_VISIT_OPTIONAL_ENTITY(CallExpr, callee_declaration, getVal40, setVal40, initVal40, CalleeDeclaration, Decl, NthStmt, DeclUseSelector::CALLEE_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(CallExpr, direct_callee, getVal41, setVal41, initVal41, DirectCallee, FunctionDecl, NthStmt, DeclUseSelector::DIRECT_CALLEE)
  MX_VISIT_ENTITY(CallExpr, r_paren_token, getVal42, setVal42, initVal42, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(CallExpr, has_stored_fp_features, getVal100, setVal100, initVal100, HasStoredFPFeatures, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, has_unused_result_attribute, getVal101, setVal101, initVal101, HasUnusedResultAttribute, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, is_builtin_assume_false, getVal102, setVal102, initVal102, IsBuiltinAssumeFalse, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, is_call_to_std_move, getVal104, setVal104, initVal104, IsCallToStdMove, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, is_unevaluated_builtin_call, getVal107, setVal107, initVal107, IsUnevaluatedBuiltinCall, bool, NthStmt)
  MX_VISIT_BOOL(CallExpr, uses_adl, getVal108, setVal108, initVal108, UsesADL, bool, NthStmt)
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
  MX_VISIT_ENUM(CXXOperatorCallExpr, operator_, getVal106, setVal106, initVal106, Operator, OverloadedOperatorKind, NthStmt)
  MX_VISIT_ENTITY(CXXOperatorCallExpr, operator_token, getVal43, setVal43, initVal43, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_BOOL(CXXOperatorCallExpr, is_assignment_operation, getVal109, setVal109, initVal109, IsAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXOperatorCallExpr, is_comparison_operation, getVal110, setVal110, initVal110, IsComparisonOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXOperatorCallExpr, is_infix_binary_operation, getVal111, setVal111, initVal111, IsInfixBinaryOperation, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXMemberCallExpr, implicit_object_argument, getVal43, setVal43, initVal43, ImplicitObjectArgument, Expr, NthStmt, StmtUseSelector::IMPLICIT_OBJECT_ARGUMENT)
  MX_VISIT_OPTIONAL_ENTITY(CXXMemberCallExpr, method_declaration, getVal44, setVal44, initVal44, MethodDeclaration, CXXMethodDecl, NthStmt, DeclUseSelector::METHOD_DECLARATION)
  MX_VISIT_ENTITY(CXXMemberCallExpr, object_type, getVal45, setVal45, initVal45, ObjectType, Type, NthStmt, TypeUseSelector::OBJECT_TYPE)
  MX_VISIT_ENTITY(CXXMemberCallExpr, record_declaration, getVal46, setVal46, initVal46, RecordDeclaration, CXXRecordDecl, NthStmt, DeclUseSelector::RECORD_DECLARATION)
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
  MX_VISIT_ENTITY(CUDAKernelCallExpr, config, getVal43, setVal43, initVal43, Config, CallExpr, NthStmt, StmtUseSelector::CONFIG)
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
  MX_VISIT_ENTITY(UserDefinedLiteral, cooked_literal, getVal43, setVal43, initVal43, CookedLiteral, Expr, NthStmt, StmtUseSelector::COOKED_LITERAL)
  MX_VISIT_ENUM(UserDefinedLiteral, literal_operator_kind, getVal106, setVal106, initVal106, LiteralOperatorKind, UserDefinedLiteralLiteralOperatorKind, NthStmt)
  MX_VISIT_ENTITY(UserDefinedLiteral, ud_suffix_token, getVal44, setVal44, initVal44, UDSuffixToken, Token, NthStmt, TokenUseSelector::UD_SUFFIX_TOKEN)
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
  MX_VISIT_OPTIONAL_ENTITY(CXXUuidofExpr, expression_operand, getVal38, setVal38, initVal38, ExpressionOperand, Expr, NthStmt, StmtUseSelector::EXPRESSION_OPERAND)
  MX_VISIT_ENTITY(CXXUuidofExpr, guid_declaration, getVal39, setVal39, initVal39, GuidDeclaration, MSGuidDecl, NthStmt, DeclUseSelector::GUID_DECLARATION)
  MX_VISIT_ENTITY(CXXUuidofExpr, type_operand, getVal40, setVal40, initVal40, TypeOperand, Type, NthStmt, TypeUseSelector::TYPE_OPERAND)
  MX_VISIT_ENTITY(CXXUuidofExpr, type_operand_source_info, getVal41, setVal41, initVal41, TypeOperandSourceInfo, Type, NthStmt, TypeUseSelector::TYPE_OPERAND_SOURCE_INFO)
  MX_VISIT_BOOL(CXXUuidofExpr, is_type_operand, getVal99, setVal99, initVal99, IsTypeOperand, bool, NthStmt)
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
  MX_VISIT_ENTITY_LIST(CXXUnresolvedConstructExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_VISIT_ENTITY(CXXUnresolvedConstructExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXUnresolvedConstructExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(CXXUnresolvedConstructExpr, type_as_written, getVal40, setVal40, initVal40, TypeAsWritten, Type, NthStmt, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(CXXUnresolvedConstructExpr, is_list_initialization, getVal98, setVal98, initVal98, IsListInitialization, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(CXXTypeidExpr, expression_operand, getVal38, setVal38, initVal38, ExpressionOperand, Expr, NthStmt, StmtUseSelector::EXPRESSION_OPERAND)
  MX_VISIT_ENTITY(CXXTypeidExpr, type_operand, getVal39, setVal39, initVal39, TypeOperand, Type, NthStmt, TypeUseSelector::TYPE_OPERAND)
  MX_VISIT_ENTITY(CXXTypeidExpr, type_operand_source_info, getVal40, setVal40, initVal40, TypeOperandSourceInfo, Type, NthStmt, TypeUseSelector::TYPE_OPERAND_SOURCE_INFO)
  MX_VISIT_OPTIONAL_BOOL(CXXTypeidExpr, is_most_derived, getVal99, setVal99, initVal99, IsMostDerived, bool, NthStmt)
  MX_VISIT_BOOL(CXXTypeidExpr, is_potentially_evaluated, getVal101, setVal101, initVal101, IsPotentiallyEvaluated, bool, NthStmt)
  MX_VISIT_BOOL(CXXTypeidExpr, is_type_operand, getVal102, setVal102, initVal102, IsTypeOperand, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(CXXThrowExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_ENTITY(CXXThrowExpr, throw_token, getVal39, setVal39, initVal39, ThrowToken, Token, NthStmt, TokenUseSelector::THROW_TOKEN)
  MX_VISIT_BOOL(CXXThrowExpr, is_thrown_variable_in_scope, getVal99, setVal99, initVal99, IsThrownVariableInScope, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXThisExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXThisExpr, is_implicit, getVal98, setVal98, initVal98, IsImplicit, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXStdInitializerListExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
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
  MX_VISIT_ENTITY(CXXScalarValueInitExpr, r_paren_token, getVal38, setVal38, initVal38, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, lhs, getVal38, setVal38, initVal38, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENUM(CXXRewrittenBinaryOperator, opcode, getVal103, setVal103, initVal103, Opcode, BinaryOperatorKind, NthStmt)
  MX_VISIT_TEXT(CXXRewrittenBinaryOperator, opcode_string, getVal63, setVal63, initVal63, OpcodeString, basic_string_view, NthStmt)
  MX_VISIT_ENUM(CXXRewrittenBinaryOperator, operator_, getVal106, setVal106, initVal106, Operator, BinaryOperatorKind, NthStmt)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, operator_token, getVal39, setVal39, initVal39, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, rhs, getVal40, setVal40, initVal40, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_ENTITY(CXXRewrittenBinaryOperator, semantic_form, getVal41, setVal41, initVal41, SemanticForm, Expr, NthStmt, StmtUseSelector::SEMANTIC_FORM)
  MX_VISIT_BOOL(CXXRewrittenBinaryOperator, is_assignment_operation, getVal98, setVal98, initVal98, IsAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXRewrittenBinaryOperator, is_comparison_operation, getVal99, setVal99, initVal99, IsComparisonOperation, bool, NthStmt)
  MX_VISIT_BOOL(CXXRewrittenBinaryOperator, is_reversed, getVal100, setVal100, initVal100, IsReversed, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, colon_colon_token, getVal39, setVal39, initVal39, ColonColonToken, Token, NthStmt, TokenUseSelector::COLON_COLON_TOKEN)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, destroyed_type, getVal40, setVal40, initVal40, DestroyedType, Type, NthStmt, TypeUseSelector::DESTROYED_TYPE)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, destroyed_type_token, getVal41, setVal41, initVal41, DestroyedTypeToken, Token, NthStmt, TokenUseSelector::DESTROYED_TYPE_TOKEN)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, operator_token, getVal42, setVal42, initVal42, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, scope_type, getVal43, setVal43, initVal43, ScopeTypeInfo, Type, NthStmt, TypeUseSelector::SCOPE_TYPE)
  MX_VISIT_ENTITY(CXXPseudoDestructorExpr, tilde_token, getVal44, setVal44, initVal44, TildeToken, Token, NthStmt, TokenUseSelector::TILDE_TOKEN)
  MX_VISIT_BOOL(CXXPseudoDestructorExpr, has_qualifier, getVal98, setVal98, initVal98, HasQualifier, bool, NthStmt)
  MX_VISIT_BOOL(CXXPseudoDestructorExpr, is_arrow, getVal99, setVal99, initVal99, IsArrow, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXNullPtrLiteralExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
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
  MX_VISIT_ENTITY(CXXNoexceptExpr, operand, getVal38, setVal38, initVal38, Operand, Expr, NthStmt, StmtUseSelector::OPERAND)
  MX_VISIT_BOOL(CXXNoexceptExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
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
  MX_VISIT_BOOL(CXXNewExpr, does_usual_array_delete_want_size, getVal98, setVal98, initVal98, DoesUsualArrayDeleteWantSize, bool, NthStmt)
  MX_VISIT_ENTITY(CXXNewExpr, allocated_type, getVal38, setVal38, initVal38, AllocatedType, Type, NthStmt, TypeUseSelector::ALLOCATED_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXNewExpr, array_size, getVal39, setVal39, initVal39, ArraySize, Expr, NthStmt, StmtUseSelector::ARRAY_SIZE)
  MX_VISIT_OPTIONAL_ENTITY(CXXNewExpr, construct_expression, getVal40, setVal40, initVal40, ConstructExpression, CXXConstructExpr, NthStmt, StmtUseSelector::CONSTRUCT_EXPRESSION)
  MX_VISIT_ENUM(CXXNewExpr, initialization_style, getVal103, setVal103, initVal103, InitializationStyle, CXXNewExprInitializationStyle, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(CXXNewExpr, initializer, getVal43, setVal43, initVal43, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CXXNewExpr, operator_delete, getVal44, setVal44, initVal44, OperatorDelete, FunctionDecl, NthStmt, DeclUseSelector::OPERATOR_DELETE)
  MX_VISIT_ENTITY(CXXNewExpr, operator_new, getVal45, setVal45, initVal45, OperatorNew, FunctionDecl, NthStmt, DeclUseSelector::OPERATOR_NEW)
  MX_VISIT_BOOL(CXXNewExpr, has_initializer, getVal102, setVal102, initVal102, HasInitializer, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, is_array, getVal104, setVal104, initVal104, IsArray, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, is_global_new, getVal107, setVal107, initVal107, IsGlobalNew, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, is_parenthesis_type_id, getVal108, setVal108, initVal108, IsParenthesisTypeId, bool, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, pass_alignment, getVal109, setVal109, initVal109, PassAlignment, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(CXXNewExpr, placement_arguments, getVal17, setVal17, initVal17, PlacementArguments, Expr, NthStmt)
  MX_VISIT_BOOL(CXXNewExpr, should_null_check_allocation, getVal110, setVal110, initVal110, ShouldNullCheckAllocation, bool, NthStmt)
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
  MX_VISIT_BOOL(CXXInheritedCtorInitExpr, constructs_virtual_base, getVal98, setVal98, initVal98, ConstructsVirtualBase, bool, NthStmt)
  MX_VISIT_ENUM(CXXInheritedCtorInitExpr, construction_kind, getVal103, setVal103, initVal103, ConstructionKind, CXXConstructExprConstructionKind, NthStmt)
  MX_VISIT_ENTITY(CXXInheritedCtorInitExpr, constructor, getVal38, setVal38, initVal38, Constructor, CXXConstructorDecl, NthStmt, DeclUseSelector::CONSTRUCTOR)
  MX_VISIT_ENTITY(CXXInheritedCtorInitExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXInheritedCtorInitExpr, inherited_from_virtual_base, getVal99, setVal99, initVal99, InheritedFromVirtualBase, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXFoldExpr, callee, getVal38, setVal38, initVal38, Callee, UnresolvedLookupExpr, NthStmt, StmtUseSelector::CALLEE)
  MX_VISIT_ENTITY(CXXFoldExpr, ellipsis_token, getVal39, setVal39, initVal39, EllipsisToken, Token, NthStmt, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(CXXFoldExpr, initializer, getVal40, setVal40, initVal40, Initializer, Expr, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(CXXFoldExpr, lhs, getVal41, setVal41, initVal41, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(CXXFoldExpr, l_paren_token, getVal42, setVal42, initVal42, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_OPTIONAL_INT(CXXFoldExpr, num_expansions, getVal112, setVal112, initVal112, NumExpansions, unsigned, NthStmt)
  MX_VISIT_ENUM(CXXFoldExpr, operator_, getVal103, setVal103, initVal103, Operator, BinaryOperatorKind, NthStmt)
  MX_VISIT_ENTITY(CXXFoldExpr, pattern, getVal43, setVal43, initVal43, Pattern, Expr, NthStmt, StmtUseSelector::PATTERN)
  MX_VISIT_ENTITY(CXXFoldExpr, rhs, getVal44, setVal44, initVal44, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_ENTITY(CXXFoldExpr, r_paren_token, getVal45, setVal45, initVal45, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(CXXFoldExpr, is_left_fold, getVal99, setVal99, initVal99, IsLeftFold, bool, NthStmt)
  MX_VISIT_BOOL(CXXFoldExpr, is_right_fold, getVal100, setVal100, initVal100, IsRightFold, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, base_type, getVal39, setVal39, initVal39, BaseType, Type, NthStmt, TypeUseSelector::BASE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(CXXDependentScopeMemberExpr, first_qualifier_found_in_scope, getVal40, setVal40, initVal40, FirstQualifierFoundInScope, NamedDecl, NthStmt, DeclUseSelector::FIRST_QUALIFIER_FOUND_IN_SCOPE)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, l_angle_token, getVal41, setVal41, initVal41, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, member_token, getVal42, setVal42, initVal42, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, operator_token, getVal43, setVal43, initVal43, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, r_angle_token, getVal44, setVal44, initVal44, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(CXXDependentScopeMemberExpr, template_keyword_token, getVal45, setVal45, initVal45, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, has_explicit_template_arguments, getVal99, setVal99, initVal99, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, has_template_keyword, getVal100, setVal100, initVal100, HasTemplateKeyword, bool, NthStmt)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, is_arrow, getVal101, setVal101, initVal101, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(CXXDependentScopeMemberExpr, is_implicit_access, getVal102, setVal102, initVal102, IsImplicitAccess, bool, NthStmt)
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
  MX_VISIT_BOOL(CXXDeleteExpr, does_usual_array_delete_want_size, getVal98, setVal98, initVal98, DoesUsualArrayDeleteWantSize, bool, NthStmt)
  MX_VISIT_ENTITY(CXXDeleteExpr, argument, getVal38, setVal38, initVal38, Argument, Expr, NthStmt, StmtUseSelector::ARGUMENT)
  MX_VISIT_ENTITY(CXXDeleteExpr, destroyed_type, getVal39, setVal39, initVal39, DestroyedType, Type, NthStmt, TypeUseSelector::DESTROYED_TYPE)
  MX_VISIT_ENTITY(CXXDeleteExpr, operator_delete, getVal40, setVal40, initVal40, OperatorDelete, FunctionDecl, NthStmt, DeclUseSelector::OPERATOR_DELETE)
  MX_VISIT_BOOL(CXXDeleteExpr, is_array_form, getVal99, setVal99, initVal99, IsArrayForm, bool, NthStmt)
  MX_VISIT_BOOL(CXXDeleteExpr, is_array_form_as_written, getVal100, setVal100, initVal100, IsArrayFormAsWritten, bool, NthStmt)
  MX_VISIT_BOOL(CXXDeleteExpr, is_global_delete, getVal101, setVal101, initVal101, IsGlobalDelete, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(CXXDefaultInitExpr, expression, getVal38, setVal38, initVal38, Expression, Expr, NthStmt, StmtUseSelector::EXPRESSION)
  MX_VISIT_ENTITY(CXXDefaultInitExpr, field, getVal39, setVal39, initVal39, Field, FieldDecl, NthStmt, DeclUseSelector::FIELD)
  MX_VISIT_ENTITY(CXXDefaultInitExpr, used_token, getVal40, setVal40, initVal40, UsedToken, Token, NthStmt, TokenUseSelector::USED_TOKEN)
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
  MX_VISIT_ENTITY(CXXDefaultArgExpr, expression, getVal38, setVal38, initVal38, Expression, Expr, NthStmt, StmtUseSelector::EXPRESSION)
  MX_VISIT_ENTITY(CXXDefaultArgExpr, parameter, getVal39, setVal39, initVal39, Parameter, ParmVarDecl, NthStmt, DeclUseSelector::PARAMETER)
  MX_VISIT_ENTITY(CXXDefaultArgExpr, used_token, getVal40, setVal40, initVal40, UsedToken, Token, NthStmt, TokenUseSelector::USED_TOKEN)
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
  MX_VISIT_ENTITY_LIST(CXXConstructExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_VISIT_ENUM(CXXConstructExpr, construction_kind, getVal103, setVal103, initVal103, ConstructionKind, CXXConstructExprConstructionKind, NthStmt)
  MX_VISIT_ENTITY(CXXConstructExpr, constructor, getVal38, setVal38, initVal38, Constructor, CXXConstructorDecl, NthStmt, DeclUseSelector::CONSTRUCTOR)
  MX_VISIT_ENTITY(CXXConstructExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXConstructExpr, had_multiple_candidates, getVal98, setVal98, initVal98, HadMultipleCandidates, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, is_elidable, getVal99, setVal99, initVal99, IsElidable, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, is_list_initialization, getVal100, setVal100, initVal100, IsListInitialization, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, is_std_initializer_list_initialization, getVal101, setVal101, initVal101, IsStdInitializerListInitialization, bool, NthStmt)
  MX_VISIT_BOOL(CXXConstructExpr, requires_zero_initialization, getVal102, setVal102, initVal102, RequiresZeroInitialization, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXBoolLiteralExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(CXXBoolLiteralExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
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
  MX_VISIT_ENTITY(CXXBindTemporaryExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
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
  MX_VISIT_ENTITY(BlockExpr, block_declaration, getVal38, setVal38, initVal38, BlockDeclaration, BlockDecl, NthStmt, DeclUseSelector::BLOCK_DECLARATION)
  MX_VISIT_ENTITY(BlockExpr, body, getVal39, setVal39, initVal39, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(BlockExpr, caret_token, getVal40, setVal40, initVal40, CaretToken, Token, NthStmt, TokenUseSelector::CARET_TOKEN)
  MX_VISIT_ENTITY(BlockExpr, function_type, getVal41, setVal41, initVal41, FunctionType, FunctionProtoType, NthStmt, TypeUseSelector::FUNCTION_TYPE)
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
  MX_VISIT_ENTITY(BinaryOperator, lhs, getVal38, setVal38, initVal38, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENUM(BinaryOperator, opcode, getVal103, setVal103, initVal103, Opcode, BinaryOperatorKind, NthStmt)
  MX_VISIT_TEXT(BinaryOperator, opcode_string, getVal63, setVal63, initVal63, OpcodeString, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(BinaryOperator, operator_token, getVal39, setVal39, initVal39, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(BinaryOperator, rhs, getVal40, setVal40, initVal40, RHS, Expr, NthStmt, StmtUseSelector::RHS)
  MX_VISIT_BOOL(BinaryOperator, has_stored_fp_features, getVal98, setVal98, initVal98, HasStoredFPFeatures, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_additive_operation, getVal99, setVal99, initVal99, IsAdditiveOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_assignment_operation, getVal100, setVal100, initVal100, IsAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_bitwise_operation, getVal101, setVal101, initVal101, IsBitwiseOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_comma_operation, getVal102, setVal102, initVal102, IsCommaOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_comparison_operation, getVal104, setVal104, initVal104, IsComparisonOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_compound_assignment_operation, getVal107, setVal107, initVal107, IsCompoundAssignmentOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_equality_operation, getVal108, setVal108, initVal108, IsEqualityOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_logical_operation, getVal109, setVal109, initVal109, IsLogicalOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_multiplicative_operation, getVal110, setVal110, initVal110, IsMultiplicativeOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_pointer_memory_operation, getVal111, setVal111, initVal111, IsPointerMemoryOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_relational_operation, getVal113, setVal113, initVal113, IsRelationalOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_shift_assign_operation, getVal114, setVal114, initVal114, IsShiftAssignOperation, bool, NthStmt)
  MX_VISIT_BOOL(BinaryOperator, is_shift_operation, getVal115, setVal115, initVal115, IsShiftOperation, bool, NthStmt)
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
  MX_VISIT_ENTITY(CompoundAssignOperator, computation_lhs_type, getVal41, setVal41, initVal41, ComputationLHSType, Type, NthStmt, TypeUseSelector::COMPUTATION_LHS_TYPE)
  MX_VISIT_ENTITY(CompoundAssignOperator, computation_result_type, getVal42, setVal42, initVal42, ComputationResultType, Type, NthStmt, TypeUseSelector::COMPUTATION_RESULT_TYPE)
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
  MX_VISIT_ENTITY(AtomicExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENUM(AtomicExpr, operation, getVal103, setVal103, initVal103, Operation, AtomicExprAtomicOp, NthStmt)
  MX_VISIT_ENTITY(AtomicExpr, order, getVal39, setVal39, initVal39, Order, Expr, NthStmt, StmtUseSelector::ORDER)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, order_fail, getVal40, setVal40, initVal40, OrderFail, Expr, NthStmt, StmtUseSelector::ORDER_FAIL)
  MX_VISIT_ENTITY(AtomicExpr, pointer, getVal41, setVal41, initVal41, Pointer, Expr, NthStmt, StmtUseSelector::POINTER)
  MX_VISIT_ENTITY(AtomicExpr, r_paren_token, getVal42, setVal42, initVal42, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, scope, getVal43, setVal43, initVal43, Scope, Expr, NthStmt, StmtUseSelector::SCOPE)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, value1, getVal44, setVal44, initVal44, Value1, Expr, NthStmt, StmtUseSelector::VALUE1)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, value2, getVal45, setVal45, initVal45, Value2, Expr, NthStmt, StmtUseSelector::VALUE2)
  MX_VISIT_ENTITY(AtomicExpr, value_type, getVal46, setVal46, initVal46, ValueType, Type, NthStmt, TypeUseSelector::VALUE_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(AtomicExpr, weak, getVal47, setVal47, initVal47, Weak, Expr, NthStmt, StmtUseSelector::WEAK)
  MX_VISIT_BOOL(AtomicExpr, is_cmp_x_chg, getVal104, setVal104, initVal104, IsCmpXChg, bool, NthStmt)
  MX_VISIT_BOOL(AtomicExpr, is_open_cl, getVal107, setVal107, initVal107, IsOpenCL, bool, NthStmt)
  MX_VISIT_BOOL(AtomicExpr, is_volatile, getVal108, setVal108, initVal108, IsVolatile, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(AtomicExpr, sub_expressions, getVal17, setVal17, initVal17, SubExpressions, Expr, NthStmt)
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
  MX_VISIT_ENTITY(AsTypeExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(AsTypeExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(AsTypeExpr, src_expression, getVal40, setVal40, initVal40, SrcExpression, Expr, NthStmt, StmtUseSelector::SRC_EXPRESSION)
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
  MX_VISIT_ENTITY(ArrayTypeTraitExpr, dimension_expression, getVal38, setVal38, initVal38, DimensionExpression, Expr, NthStmt, StmtUseSelector::DIMENSION_EXPRESSION)
  MX_VISIT_ENTITY(ArrayTypeTraitExpr, queried_type, getVal39, setVal39, initVal39, QueriedType, Type, NthStmt, TypeUseSelector::QUERIED_TYPE)
  MX_VISIT_ENUM(ArrayTypeTraitExpr, trait, getVal103, setVal103, initVal103, Trait, ArrayTypeTrait, NthStmt)
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
  MX_VISIT_ENTITY(ArraySubscriptExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ArraySubscriptExpr, index, getVal39, setVal39, initVal39, Index, Expr, NthStmt, StmtUseSelector::INDEX)
  MX_VISIT_ENTITY(ArraySubscriptExpr, lhs, getVal40, setVal40, initVal40, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(ArraySubscriptExpr, r_bracket_token, getVal41, setVal41, initVal41, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(ArraySubscriptExpr, rhs, getVal42, setVal42, initVal42, RHS, Expr, NthStmt, StmtUseSelector::RHS)
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
  MX_VISIT_ENTITY(ArrayInitLoopExpr, common_expression, getVal38, setVal38, initVal38, CommonExpression, OpaqueValueExpr, NthStmt, StmtUseSelector::COMMON_EXPRESSION)
  MX_VISIT_ENTITY(ArrayInitLoopExpr, sub_expression, getVal39, setVal39, initVal39, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
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
  MX_VISIT_ENTITY(AddrLabelExpr, amp_amp_token, getVal38, setVal38, initVal38, AmpAmpToken, Token, NthStmt, TokenUseSelector::AMP_AMP_TOKEN)
  MX_VISIT_ENTITY(AddrLabelExpr, label, getVal39, setVal39, initVal39, Label, LabelDecl, NthStmt, DeclUseSelector::LABEL)
  MX_VISIT_ENTITY(AddrLabelExpr, label_token, getVal40, setVal40, initVal40, LabelToken, Token, NthStmt, TokenUseSelector::LABEL_TOKEN)
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
  MX_VISIT_ENTITY(AbstractConditionalOperator, colon_token, getVal38, setVal38, initVal38, ColonToken, Token, NthStmt, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENTITY(AbstractConditionalOperator, condition, getVal39, setVal39, initVal39, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_ENTITY(AbstractConditionalOperator, false_expression, getVal40, setVal40, initVal40, FalseExpression, Expr, NthStmt, StmtUseSelector::FALSE_EXPRESSION)
  MX_VISIT_ENTITY(AbstractConditionalOperator, question_token, getVal41, setVal41, initVal41, QuestionToken, Token, NthStmt, TokenUseSelector::QUESTION_TOKEN)
  MX_VISIT_ENTITY(AbstractConditionalOperator, true_expression, getVal42, setVal42, initVal42, TrueExpression, Expr, NthStmt, StmtUseSelector::TRUE_EXPRESSION)
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
  MX_VISIT_ENTITY(ConditionalOperator, lhs, getVal43, setVal43, initVal43, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_ENTITY(ConditionalOperator, rhs, getVal44, setVal44, initVal44, RHS, Expr, NthStmt, StmtUseSelector::RHS)
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
  MX_VISIT_ENTITY(BinaryConditionalOperator, common, getVal43, setVal43, initVal43, Common, Expr, NthStmt, StmtUseSelector::COMMON)
  MX_VISIT_ENTITY(BinaryConditionalOperator, opaque_value, getVal44, setVal44, initVal44, OpaqueValue, OpaqueValueExpr, NthStmt, StmtUseSelector::OPAQUE_VALUE)
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
  MX_VISIT_ENTITY(VAArgExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(VAArgExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(VAArgExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_ENTITY(VAArgExpr, written_type, getVal41, setVal41, initVal41, WrittenTypeInfo, Type, NthStmt, TypeUseSelector::WRITTEN_TYPE)
  MX_VISIT_BOOL(VAArgExpr, is_microsoft_abi, getVal98, setVal98, initVal98, IsMicrosoftABI, bool, NthStmt)
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
  MX_VISIT_BOOL(UnaryOperator, can_overflow, getVal98, setVal98, initVal98, CanOverflow, bool, NthStmt)
  MX_VISIT_ENUM(UnaryOperator, opcode, getVal103, setVal103, initVal103, Opcode, UnaryOperatorKind, NthStmt)
  MX_VISIT_ENTITY(UnaryOperator, operator_token, getVal38, setVal38, initVal38, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(UnaryOperator, sub_expression, getVal39, setVal39, initVal39, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(UnaryOperator, has_stored_fp_features, getVal99, setVal99, initVal99, HasStoredFPFeatures, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_arithmetic_operation, getVal100, setVal100, initVal100, IsArithmeticOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_decrement_operation, getVal101, setVal101, initVal101, IsDecrementOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_increment_decrement_operation, getVal102, setVal102, initVal102, IsIncrementDecrementOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_increment_operation, getVal104, setVal104, initVal104, IsIncrementOperation, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_postfix, getVal107, setVal107, initVal107, IsPostfix, bool, NthStmt)
  MX_VISIT_BOOL(UnaryOperator, is_prefix, getVal108, setVal108, initVal108, IsPrefix, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_expression, getVal38, setVal38, initVal38, ArgumentExpression, Expr, NthStmt, StmtUseSelector::ARGUMENT_EXPRESSION)
  MX_VISIT_OPTIONAL_ENTITY(UnaryExprOrTypeTraitExpr, argument_type, getVal39, setVal39, initVal39, ArgumentType, Type, NthStmt, TypeUseSelector::ARGUMENT_TYPE)
  MX_VISIT_ENTITY(UnaryExprOrTypeTraitExpr, operator_token, getVal40, setVal40, initVal40, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(UnaryExprOrTypeTraitExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(UnaryExprOrTypeTraitExpr, type_of_argument, getVal42, setVal42, initVal42, TypeOfArgument, Type, NthStmt, TypeUseSelector::TYPE_OF_ARGUMENT)
  MX_VISIT_BOOL(UnaryExprOrTypeTraitExpr, is_argument_type, getVal100, setVal100, initVal100, IsArgumentType, bool, NthStmt)
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
  MX_VISIT_ENUM(TypeTraitExpr, trait, getVal103, setVal103, initVal103, Trait, TypeTrait, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(TypeTraitExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(TypeTraitExpr, arguments, getVal17, setVal17, initVal17, Arguments, Type, NthStmt)
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
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmPackExpr, parameter_pack, getVal38, setVal38, initVal38, ParameterPack, NonTypeTemplateParmDecl, NthStmt, DeclUseSelector::PARAMETER_PACK)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmPackExpr, parameter_pack_token, getVal39, setVal39, initVal39, ParameterPackToken, Token, NthStmt, TokenUseSelector::PARAMETER_PACK_TOKEN)
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
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, name_token, getVal38, setVal38, initVal38, NameToken, Token, NthStmt, TokenUseSelector::NAME_TOKEN)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, parameter, getVal39, setVal39, initVal39, Parameter, NonTypeTemplateParmDecl, NthStmt, DeclUseSelector::PARAMETER)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, parameter_type, getVal40, setVal40, initVal40, ParameterType, Type, NthStmt, TypeUseSelector::PARAMETER_TYPE)
  MX_VISIT_ENTITY(SubstNonTypeTemplateParmExpr, replacement, getVal41, setVal41, initVal41, Replacement, Expr, NthStmt, StmtUseSelector::REPLACEMENT)
  MX_VISIT_BOOL(SubstNonTypeTemplateParmExpr, is_reference_parameter, getVal98, setVal98, initVal98, IsReferenceParameter, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_BOOL(StringLiteral, contains_non_ascii, getVal98, setVal98, initVal98, ContainsNonAscii, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(StringLiteral, contains_non_ascii_or_null, getVal100, setVal100, initVal100, ContainsNonAsciiOrNull, bool, NthStmt)
  MX_VISIT_TEXT(StringLiteral, bytes, getVal63, setVal63, initVal63, Bytes, basic_string_view, NthStmt)
  MX_VISIT_OPTIONAL_TEXT(StringLiteral, string, getVal68, setVal68, initVal68, String, basic_string_view, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_ascii, getVal104, setVal104, initVal104, IsAscii, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_pascal, getVal107, setVal107, initVal107, IsPascal, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_utf16, getVal108, setVal108, initVal108, IsUTF16, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_utf32, getVal109, setVal109, initVal109, IsUTF32, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_utf8, getVal110, setVal110, initVal110, IsUTF8, bool, NthStmt)
  MX_VISIT_BOOL(StringLiteral, is_wide, getVal111, setVal111, initVal111, IsWide, bool, NthStmt)
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
  MX_VISIT_ENTITY(StmtExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(StmtExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(StmtExpr, sub_statement, getVal40, setVal40, initVal40, SubStatement, CompoundStmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
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
  MX_VISIT_TEXT(SourceLocExpr, builtin_string, getVal63, setVal63, initVal63, BuiltinString, basic_string_view, NthStmt)
  MX_VISIT_ENUM(SourceLocExpr, identifier_kind, getVal103, setVal103, initVal103, IdentifierKind, SourceLocExprIdentKind, NthStmt)
  MX_VISIT_ENTITY(SourceLocExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(SourceLocExpr, is_int_type, getVal98, setVal98, initVal98, IsIntType, bool, NthStmt)
  MX_VISIT_BOOL(SourceLocExpr, is_string_type, getVal99, setVal99, initVal99, IsStringType, bool, NthStmt)
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
  MX_VISIT_ENTITY(SizeOfPackExpr, operator_token, getVal38, setVal38, initVal38, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(SizeOfPackExpr, pack, getVal39, setVal39, initVal39, Pack, NamedDecl, NthStmt, DeclUseSelector::PACK)
  MX_VISIT_OPTIONAL_INT(SizeOfPackExpr, pack_length, getVal112, setVal112, initVal112, PackLength, unsigned, NthStmt)
  MX_VISIT_ENTITY(SizeOfPackExpr, pack_token, getVal40, setVal40, initVal40, PackToken, Token, NthStmt, TokenUseSelector::PACK_TOKEN)
  MX_VISIT_OPTIONAL_PSEUDO_LIST(SizeOfPackExpr, partial_arguments, getVal105, setVal105, initVal105, PartialArguments, TemplateArgument, NthStmt)
  MX_VISIT_ENTITY(SizeOfPackExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(SizeOfPackExpr, is_partially_substituted, getVal100, setVal100, initVal100, IsPartiallySubstituted, bool, NthStmt)
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
  MX_VISIT_ENTITY(ShuffleVectorExpr, builtin_token, getVal38, setVal38, initVal38, BuiltinToken, Token, NthStmt, TokenUseSelector::BUILTIN_TOKEN)
  MX_VISIT_ENTITY(ShuffleVectorExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_TEXT(SYCLUniqueStableNameExpr, compute_name, getVal63, setVal63, initVal63, ComputeName, basic_string, NthStmt)
  MX_VISIT_ENTITY(SYCLUniqueStableNameExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(SYCLUniqueStableNameExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(SYCLUniqueStableNameExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(RequiresExpr, body, getVal38, setVal38, initVal38, Body, RequiresExprBodyDecl, NthStmt, DeclUseSelector::BODY)
  MX_VISIT_ENTITY_LIST(RequiresExpr, local_parameters, getVal17, setVal17, initVal17, LocalParameters, ParmVarDecl, NthStmt)
  MX_VISIT_ENTITY(RequiresExpr, r_brace_token, getVal39, setVal39, initVal39, RBraceToken, Token, NthStmt, TokenUseSelector::R_BRACE_TOKEN)
  MX_VISIT_ENTITY(RequiresExpr, requires_kw_token, getVal40, setVal40, initVal40, RequiresKWToken, Token, NthStmt, TokenUseSelector::REQUIRES_KW_TOKEN)
  MX_VISIT_BOOL(RequiresExpr, is_satisfied, getVal98, setVal98, initVal98, IsSatisfied, bool, NthStmt)
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
  MX_VISIT_ENTITY_LIST(RecoveryExpr, sub_expressions, getVal17, setVal17, initVal17, SubExpressions, Expr, NthStmt)
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
  MX_VISIT_ENTITY(PseudoObjectExpr, result_expression, getVal38, setVal38, initVal38, ResultExpression, Expr, NthStmt, StmtUseSelector::RESULT_EXPRESSION)
  MX_VISIT_ENTITY(PseudoObjectExpr, syntactic_form, getVal39, setVal39, initVal39, SyntacticForm, Expr, NthStmt, StmtUseSelector::SYNTACTIC_FORM)
  MX_VISIT_ENTITY_LIST(PseudoObjectExpr, semantics, getVal17, setVal17, initVal17, Semantics, Expr, NthStmt)
  MX_VISIT_ENTITY_LIST(PseudoObjectExpr, semantic_expressions, getVal23, setVal23, initVal23, SemanticExpressions, Expr, NthStmt)
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
  MX_VISIT_ENTITY(PredefinedExpr, function_name, getVal38, setVal38, initVal38, FunctionName, StringLiteral, NthStmt, StmtUseSelector::FUNCTION_NAME)
  MX_VISIT_ENUM(PredefinedExpr, identifier_kind, getVal103, setVal103, initVal103, IdentifierKind, PredefinedExprIdentKind, NthStmt)
  MX_VISIT_TEXT(PredefinedExpr, identifier_kind_name, getVal63, setVal63, initVal63, IdentifierKindName, basic_string_view, NthStmt)
  MX_VISIT_ENTITY(PredefinedExpr, token, getVal39, setVal39, initVal39, Token, Token, NthStmt, TokenUseSelector::TOKEN)
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
  MX_VISIT_ENTITY(ParenListExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(ParenListExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY_LIST(ParenListExpr, expressions, getVal17, setVal17, initVal17, Expressions, Expr, NthStmt)
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
  MX_VISIT_ENTITY(ParenExpr, l_paren_token, getVal38, setVal38, initVal38, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(ParenExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(ParenExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
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
  MX_VISIT_ENTITY(PackExpansionExpr, ellipsis_token, getVal38, setVal38, initVal38, EllipsisToken, Token, NthStmt, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_OPTIONAL_INT(PackExpansionExpr, num_expansions, getVal112, setVal112, initVal112, NumExpansions, unsigned, NthStmt)
  MX_VISIT_ENTITY(PackExpansionExpr, pattern, getVal39, setVal39, initVal39, Pattern, Expr, NthStmt, StmtUseSelector::PATTERN)
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
  MX_VISIT_ENTITY(OverloadExpr, l_angle_token, getVal38, setVal38, initVal38, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(OverloadExpr, name_token, getVal39, setVal39, initVal39, NameToken, Token, NthStmt, TokenUseSelector::NAME_TOKEN)
  MX_VISIT_ENTITY(OverloadExpr, naming_class, getVal40, setVal40, initVal40, NamingClass, CXXRecordDecl, NthStmt, DeclUseSelector::NAMING_CLASS)
  MX_VISIT_ENTITY(OverloadExpr, r_angle_token, getVal41, setVal41, initVal41, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(OverloadExpr, template_keyword_token, getVal42, setVal42, initVal42, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(OverloadExpr, has_explicit_template_arguments, getVal98, setVal98, initVal98, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(OverloadExpr, has_template_keyword, getVal99, setVal99, initVal99, HasTemplateKeyword, bool, NthStmt)
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
  MX_VISIT_ENTITY(UnresolvedMemberExpr, base, getVal43, setVal43, initVal43, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, base_type, getVal44, setVal44, initVal44, BaseType, Type, NthStmt, TypeUseSelector::BASE_TYPE)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, member_token, getVal45, setVal45, initVal45, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(UnresolvedMemberExpr, operator_token, getVal46, setVal46, initVal46, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_BOOL(UnresolvedMemberExpr, has_unresolved_using, getVal100, setVal100, initVal100, HasUnresolvedUsing, bool, NthStmt)
  MX_VISIT_BOOL(UnresolvedMemberExpr, is_arrow, getVal101, setVal101, initVal101, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(UnresolvedMemberExpr, is_implicit_access, getVal102, setVal102, initVal102, IsImplicitAccess, bool, NthStmt)
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
  MX_VISIT_BOOL(UnresolvedLookupExpr, is_overloaded, getVal100, setVal100, initVal100, IsOverloaded, bool, NthStmt)
  MX_VISIT_BOOL(UnresolvedLookupExpr, requires_adl, getVal101, setVal101, initVal101, RequiresADL, bool, NthStmt)
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
  MX_VISIT_ENTITY(OpaqueValueExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(OpaqueValueExpr, source_expression, getVal39, setVal39, initVal39, SourceExpression, Expr, NthStmt, StmtUseSelector::SOURCE_EXPRESSION)
  MX_VISIT_BOOL(OpaqueValueExpr, is_unique, getVal98, setVal98, initVal98, IsUnique, bool, NthStmt)
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
  MX_VISIT_ENTITY(OffsetOfExpr, operator_token, getVal38, setVal38, initVal38, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(OffsetOfExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, at_index_method_declaration, getVal38, setVal38, initVal38, AtIndexMethodDeclaration, ObjCMethodDecl, NthStmt, DeclUseSelector::AT_INDEX_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, base_expression, getVal39, setVal39, initVal39, BaseExpression, Expr, NthStmt, StmtUseSelector::BASE_EXPRESSION)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, key_expression, getVal40, setVal40, initVal40, KeyExpression, Expr, NthStmt, StmtUseSelector::KEY_EXPRESSION)
  MX_VISIT_ENTITY(ObjCSubscriptRefExpr, r_bracket_token, getVal41, setVal41, initVal41, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_BOOL(ObjCSubscriptRefExpr, is_array_subscript_reference_expression, getVal98, setVal98, initVal98, IsArraySubscriptReferenceExpression, bool, NthStmt)
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
  MX_VISIT_ENTITY(ObjCStringLiteral, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCStringLiteral, string, getVal39, setVal39, initVal39, String, StringLiteral, NthStmt, StmtUseSelector::STRING)
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
  MX_VISIT_ENTITY(ObjCSelectorExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCSelectorExpr, r_paren_token, getVal39, setVal39, initVal39, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCProtocolExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCProtocolExpr, protocol, getVal39, setVal39, initVal39, Protocol, ObjCProtocolDecl, NthStmt, DeclUseSelector::PROTOCOL)
  MX_VISIT_ENTITY(ObjCProtocolExpr, protocol_id_token, getVal40, setVal40, initVal40, ProtocolIdToken, Token, NthStmt, TokenUseSelector::PROTOCOL_ID_TOKEN)
  MX_VISIT_ENTITY(ObjCProtocolExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, class_receiver, getVal39, setVal39, initVal39, ClassReceiver, ObjCInterfaceDecl, NthStmt, DeclUseSelector::CLASS_RECEIVER)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, explicit_property, getVal40, setVal40, initVal40, ExplicitProperty, ObjCPropertyDecl, NthStmt, DeclUseSelector::EXPLICIT_PROPERTY)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, implicit_property_getter, getVal41, setVal41, initVal41, ImplicitPropertyGetter, ObjCMethodDecl, NthStmt, DeclUseSelector::IMPLICIT_PROPERTY_GETTER)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, implicit_property_setter, getVal42, setVal42, initVal42, ImplicitPropertySetter, ObjCMethodDecl, NthStmt, DeclUseSelector::IMPLICIT_PROPERTY_SETTER)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, token, getVal43, setVal43, initVal43, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, receiver_token, getVal44, setVal44, initVal44, ReceiverToken, Token, NthStmt, TokenUseSelector::RECEIVER_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, receiver_type, getVal45, setVal45, initVal45, ReceiverType, Type, NthStmt, TypeUseSelector::RECEIVER_TYPE)
  MX_VISIT_ENTITY(ObjCPropertyRefExpr, super_receiver_type, getVal46, setVal46, initVal46, SuperReceiverType, Type, NthStmt, TypeUseSelector::SUPER_RECEIVER_TYPE)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_class_receiver, getVal98, setVal98, initVal98, IsClassReceiver, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_explicit_property, getVal99, setVal99, initVal99, IsExplicitProperty, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_implicit_property, getVal100, setVal100, initVal100, IsImplicitProperty, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_messaging_getter, getVal101, setVal101, initVal101, IsMessagingGetter, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_messaging_setter, getVal102, setVal102, initVal102, IsMessagingSetter, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_object_receiver, getVal104, setVal104, initVal104, IsObjectReceiver, bool, NthStmt)
  MX_VISIT_BOOL(ObjCPropertyRefExpr, is_super_receiver, getVal107, setVal107, initVal107, IsSuperReceiver, bool, NthStmt)
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
  MX_VISIT_ENTITY_LIST(ObjCMessageExpr, arguments, getVal17, setVal17, initVal17, Arguments, Expr, NthStmt)
  MX_VISIT_ENTITY(ObjCMessageExpr, call_return_type, getVal38, setVal38, initVal38, CallReturnType, Type, NthStmt, TypeUseSelector::CALL_RETURN_TYPE)
  MX_VISIT_ENTITY(ObjCMessageExpr, class_receiver, getVal39, setVal39, initVal39, ClassReceiver, Type, NthStmt, TypeUseSelector::CLASS_RECEIVER)
  MX_VISIT_ENTITY(ObjCMessageExpr, class_receiver_type, getVal40, setVal40, initVal40, ClassReceiverTypeInfo, Type, NthStmt, TypeUseSelector::CLASS_RECEIVER_TYPE)
  MX_VISIT_ENTITY(ObjCMessageExpr, instance_receiver, getVal41, setVal41, initVal41, InstanceReceiver, Expr, NthStmt, StmtUseSelector::INSTANCE_RECEIVER)
  MX_VISIT_ENTITY(ObjCMessageExpr, left_token, getVal42, setVal42, initVal42, LeftToken, Token, NthStmt, TokenUseSelector::LEFT_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, method_declaration, getVal43, setVal43, initVal43, MethodDeclaration, ObjCMethodDecl, NthStmt, DeclUseSelector::METHOD_DECLARATION)
  MX_VISIT_ENUM(ObjCMessageExpr, method_family, getVal103, setVal103, initVal103, MethodFamily, ObjCMethodFamily, NthStmt)
  MX_VISIT_ENTITY(ObjCMessageExpr, receiver_interface, getVal44, setVal44, initVal44, ReceiverInterface, ObjCInterfaceDecl, NthStmt, DeclUseSelector::RECEIVER_INTERFACE)
  MX_VISIT_ENUM(ObjCMessageExpr, receiver_kind, getVal106, setVal106, initVal106, ReceiverKind, ObjCMessageExprReceiverKind, NthStmt)
  MX_VISIT_ENTITY(ObjCMessageExpr, receiver_type, getVal47, setVal47, initVal47, ReceiverType, Type, NthStmt, TypeUseSelector::RECEIVER_TYPE)
  MX_VISIT_ENTITY(ObjCMessageExpr, right_token, getVal48, setVal48, initVal48, RightToken, Token, NthStmt, TokenUseSelector::RIGHT_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, selector_start_token, getVal49, setVal49, initVal49, SelectorStartToken, Token, NthStmt, TokenUseSelector::SELECTOR_START_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, super_token, getVal50, setVal50, initVal50, SuperToken, Token, NthStmt, TokenUseSelector::SUPER_TOKEN)
  MX_VISIT_ENTITY(ObjCMessageExpr, super_type, getVal51, setVal51, initVal51, SuperType, Type, NthStmt, TypeUseSelector::SUPER_TYPE)
  MX_VISIT_BOOL(ObjCMessageExpr, is_class_message, getVal98, setVal98, initVal98, IsClassMessage, bool, NthStmt)
  MX_VISIT_BOOL(ObjCMessageExpr, is_delegate_initializer_call, getVal99, setVal99, initVal99, IsDelegateInitializerCall, bool, NthStmt)
  MX_VISIT_BOOL(ObjCMessageExpr, is_implicit, getVal100, setVal100, initVal100, IsImplicit, bool, NthStmt)
  MX_VISIT_BOOL(ObjCMessageExpr, is_instance_message, getVal101, setVal101, initVal101, IsInstanceMessage, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(ObjCMessageExpr, selector_tokens, getVal23, setVal23, initVal23, SelectorTokens, Token, NthStmt)
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
  MX_VISIT_ENTITY(ObjCIvarRefExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, declaration, getVal39, setVal39, initVal39, Declaration, ObjCIvarDecl, NthStmt, DeclUseSelector::DECLARATION)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, token, getVal40, setVal40, initVal40, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_ENTITY(ObjCIvarRefExpr, operation_token, getVal41, setVal41, initVal41, OperationToken, Token, NthStmt, TokenUseSelector::OPERATION_TOKEN)
  MX_VISIT_BOOL(ObjCIvarRefExpr, is_arrow, getVal98, setVal98, initVal98, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(ObjCIvarRefExpr, is_free_instance_variable, getVal99, setVal99, initVal99, IsFreeInstanceVariable, bool, NthStmt)
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
  MX_VISIT_ENTITY(ObjCIsaExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(ObjCIsaExpr, base_token_end, getVal39, setVal39, initVal39, BaseTokenEnd, Token, NthStmt, TokenUseSelector::BASE_TOKEN_END)
  MX_VISIT_ENTITY(ObjCIsaExpr, isa_member_token, getVal40, setVal40, initVal40, IsaMemberToken, Token, NthStmt, TokenUseSelector::ISA_MEMBER_TOKEN)
  MX_VISIT_ENTITY(ObjCIsaExpr, operation_token, getVal41, setVal41, initVal41, OperationToken, Token, NthStmt, TokenUseSelector::OPERATION_TOKEN)
  MX_VISIT_BOOL(ObjCIsaExpr, is_arrow, getVal98, setVal98, initVal98, IsArrow, bool, NthStmt)
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
  MX_VISIT_ENTITY(ObjCIndirectCopyRestoreExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(ObjCIndirectCopyRestoreExpr, should_copy, getVal98, setVal98, initVal98, ShouldCopy, bool, NthStmt)
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
  MX_VISIT_ENTITY(ObjCEncodeExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCEncodeExpr, encoded_type, getVal39, setVal39, initVal39, EncodedType, Type, NthStmt, TypeUseSelector::ENCODED_TYPE)
  MX_VISIT_ENTITY(ObjCEncodeExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(ObjCDictionaryLiteral, dictionary_with_objects_method, getVal38, setVal38, initVal38, DictionaryWithObjectsMethod, ObjCMethodDecl, NthStmt, DeclUseSelector::DICTIONARY_WITH_OBJECTS_METHOD)
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
  MX_VISIT_ENTITY(ObjCBoxedExpr, at_token, getVal38, setVal38, initVal38, AtToken, Token, NthStmt, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCBoxedExpr, boxing_method, getVal39, setVal39, initVal39, BoxingMethod, ObjCMethodDecl, NthStmt, DeclUseSelector::BOXING_METHOD)
  MX_VISIT_ENTITY(ObjCBoxedExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(ObjCBoxedExpr, is_expressible_as_constant_initializer, getVal98, setVal98, initVal98, IsExpressibleAsConstantInitializer, bool, NthStmt)
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
  MX_VISIT_ENTITY(ObjCBoolLiteralExpr, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(ObjCBoolLiteralExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
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
  MX_VISIT_BOOL(ObjCAvailabilityCheckExpr, has_version, getVal98, setVal98, initVal98, HasVersion, bool, NthStmt)
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
  MX_VISIT_ENTITY(ObjCArrayLiteral, array_with_objects_method, getVal38, setVal38, initVal38, ArrayWithObjectsMethod, ObjCMethodDecl, NthStmt, DeclUseSelector::ARRAY_WITH_OBJECTS_METHOD)
  MX_VISIT_ENTITY_LIST(ObjCArrayLiteral, elements, getVal17, setVal17, initVal17, Elements, Expr, NthStmt)
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
  MX_VISIT_ENTITY(OMPIteratorExpr, iterator_kw_token, getVal38, setVal38, initVal38, IteratorKwToken, Token, NthStmt, TokenUseSelector::ITERATOR_KW_TOKEN)
  MX_VISIT_ENTITY(OMPIteratorExpr, l_paren_token, getVal39, setVal39, initVal39, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(OMPIteratorExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(OMPArrayShapingExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY_LIST(OMPArrayShapingExpr, dimensions, getVal17, setVal17, initVal17, Dimensions, Expr, NthStmt)
  MX_VISIT_ENTITY(OMPArrayShapingExpr, l_paren_token, getVal39, setVal39, initVal39, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(OMPArrayShapingExpr, r_paren_token, getVal40, setVal40, initVal40, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_ENTITY(OMPArraySectionExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(OMPArraySectionExpr, first_colon_token, getVal39, setVal39, initVal39, FirstColonToken, Token, NthStmt, TokenUseSelector::FIRST_COLON_TOKEN)
  MX_VISIT_ENTITY(OMPArraySectionExpr, second_colon_token, getVal40, setVal40, initVal40, SecondColonToken, Token, NthStmt, TokenUseSelector::SECOND_COLON_TOKEN)
  MX_VISIT_ENTITY(OMPArraySectionExpr, length, getVal41, setVal41, initVal41, Length, Expr, NthStmt, StmtUseSelector::LENGTH)
  MX_VISIT_ENTITY(OMPArraySectionExpr, lower_bound, getVal42, setVal42, initVal42, LowerBound, Expr, NthStmt, StmtUseSelector::LOWER_BOUND)
  MX_VISIT_ENTITY(OMPArraySectionExpr, r_bracket_token, getVal43, setVal43, initVal43, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(OMPArraySectionExpr, stride, getVal44, setVal44, initVal44, Stride, Expr, NthStmt, StmtUseSelector::STRIDE)
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
  MX_VISIT_ENTITY(MemberExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(MemberExpr, l_angle_token, getVal39, setVal39, initVal39, LAngleToken, Token, NthStmt, TokenUseSelector::L_ANGLE_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, member_declaration, getVal40, setVal40, initVal40, MemberDeclaration, ValueDecl, NthStmt, DeclUseSelector::MEMBER_DECLARATION)
  MX_VISIT_ENTITY(MemberExpr, member_token, getVal41, setVal41, initVal41, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, operator_token, getVal42, setVal42, initVal42, OperatorToken, Token, NthStmt, TokenUseSelector::OPERATOR_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, r_angle_token, getVal43, setVal43, initVal43, RAngleToken, Token, NthStmt, TokenUseSelector::R_ANGLE_TOKEN)
  MX_VISIT_ENTITY(MemberExpr, template_keyword_token, getVal44, setVal44, initVal44, TemplateKeywordToken, Token, NthStmt, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_BOOL(MemberExpr, had_multiple_candidates, getVal98, setVal98, initVal98, HadMultipleCandidates, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, has_explicit_template_arguments, getVal99, setVal99, initVal99, HasExplicitTemplateArguments, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, has_qualifier, getVal100, setVal100, initVal100, HasQualifier, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, has_template_keyword, getVal101, setVal101, initVal101, HasTemplateKeyword, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, is_arrow, getVal102, setVal102, initVal102, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(MemberExpr, is_implicit_access, getVal104, setVal104, initVal104, IsImplicitAccess, bool, NthStmt)
  MX_VISIT_ENUM(MemberExpr, is_non_odr_use, getVal103, setVal103, initVal103, IsNonOdrUse, NonOdrUseReason, NthStmt)
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
  MX_VISIT_ENTITY(MatrixSubscriptExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, column_index, getVal39, setVal39, initVal39, ColumnIndex, Expr, NthStmt, StmtUseSelector::COLUMN_INDEX)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, r_bracket_token, getVal40, setVal40, initVal40, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
  MX_VISIT_ENTITY(MatrixSubscriptExpr, row_index, getVal41, setVal41, initVal41, RowIndex, Expr, NthStmt, StmtUseSelector::ROW_INDEX)
  MX_VISIT_BOOL(MatrixSubscriptExpr, is_incomplete, getVal98, setVal98, initVal98, IsIncomplete, bool, NthStmt)
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
  MX_VISIT_OPTIONAL_ENTITY(MaterializeTemporaryExpr, extending_declaration, getVal38, setVal38, initVal38, ExtendingDeclaration, ValueDecl, NthStmt, DeclUseSelector::EXTENDING_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(MaterializeTemporaryExpr, lifetime_extended_temporary_declaration, getVal39, setVal39, initVal39, LifetimeExtendedTemporaryDeclaration, LifetimeExtendedTemporaryDecl, NthStmt, DeclUseSelector::LIFETIME_EXTENDED_TEMPORARY_DECLARATION)
  MX_VISIT_ENUM(MaterializeTemporaryExpr, storage_duration, getVal103, setVal103, initVal103, StorageDuration, StorageDuration, NthStmt)
  MX_VISIT_ENTITY(MaterializeTemporaryExpr, sub_expression, getVal40, setVal40, initVal40, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
  MX_VISIT_BOOL(MaterializeTemporaryExpr, is_bound_to_lvalue_reference, getVal100, setVal100, initVal100, IsBoundToLvalueReference, bool, NthStmt)
  MX_VISIT_BOOL(MaterializeTemporaryExpr, is_usable_in_constant_expressions, getVal101, setVal101, initVal101, IsUsableInConstantExpressions, bool, NthStmt)
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
  MX_VISIT_ENTITY(MSPropertySubscriptExpr, base, getVal38, setVal38, initVal38, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_ENTITY(MSPropertySubscriptExpr, index, getVal39, setVal39, initVal39, Index, Expr, NthStmt, StmtUseSelector::INDEX)
  MX_VISIT_ENTITY(MSPropertySubscriptExpr, r_bracket_token, getVal40, setVal40, initVal40, RBracketToken, Token, NthStmt, TokenUseSelector::R_BRACKET_TOKEN)
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
  MX_VISIT_ENTITY(MSPropertyRefExpr, base_expression, getVal38, setVal38, initVal38, BaseExpression, Expr, NthStmt, StmtUseSelector::BASE_EXPRESSION)
  MX_VISIT_ENTITY(MSPropertyRefExpr, member_token, getVal39, setVal39, initVal39, MemberToken, Token, NthStmt, TokenUseSelector::MEMBER_TOKEN)
  MX_VISIT_ENTITY(MSPropertyRefExpr, property_declaration, getVal40, setVal40, initVal40, PropertyDeclaration, MSPropertyDecl, NthStmt, DeclUseSelector::PROPERTY_DECLARATION)
  MX_VISIT_BOOL(MSPropertyRefExpr, is_arrow, getVal98, setVal98, initVal98, IsArrow, bool, NthStmt)
  MX_VISIT_BOOL(MSPropertyRefExpr, is_implicit_access, getVal99, setVal99, initVal99, IsImplicitAccess, bool, NthStmt)
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
  MX_VISIT_ENTITY(LambdaExpr, body, getVal38, setVal38, initVal38, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(LambdaExpr, call_operator, getVal39, setVal39, initVal39, CallOperator, CXXMethodDecl, NthStmt, DeclUseSelector::CALL_OPERATOR)
  MX_VISIT_ENUM(LambdaExpr, capture_default, getVal103, setVal103, initVal103, CaptureDefault, LambdaCaptureDefault, NthStmt)
  MX_VISIT_ENTITY(LambdaExpr, capture_default_token, getVal40, setVal40, initVal40, CaptureDefaultToken, Token, NthStmt, TokenUseSelector::CAPTURE_DEFAULT_TOKEN)
  MX_VISIT_ENTITY(LambdaExpr, compound_statement_body, getVal41, setVal41, initVal41, CompoundStatementBody, CompoundStmt, NthStmt, StmtUseSelector::COMPOUND_STATEMENT_BODY)
  MX_VISIT_ENTITY_LIST(LambdaExpr, explicit_template_parameters, getVal17, setVal17, initVal17, ExplicitTemplateParameters, NamedDecl, NthStmt)
  MX_VISIT_ENTITY(LambdaExpr, lambda_class, getVal44, setVal44, initVal44, LambdaClass, CXXRecordDecl, NthStmt, DeclUseSelector::LAMBDA_CLASS)
  MX_VISIT_OPTIONAL_PSEUDO(LambdaExpr, template_parameter_list, getVal112, setVal112, initVal112, TemplateParameterList, TemplateParameterList, NthStmt)
  MX_VISIT_OPTIONAL_ENTITY(LambdaExpr, trailing_requires_clause, getVal45, setVal45, initVal45, TrailingRequiresClause, Expr, NthStmt, StmtUseSelector::TRAILING_REQUIRES_CLAUSE)
  MX_VISIT_BOOL(LambdaExpr, has_explicit_parameters, getVal100, setVal100, initVal100, HasExplicitParameters, bool, NthStmt)
  MX_VISIT_BOOL(LambdaExpr, has_explicit_result_type, getVal101, setVal101, initVal101, HasExplicitResultType, bool, NthStmt)
  MX_VISIT_BOOL(LambdaExpr, is_generic_lambda, getVal102, setVal102, initVal102, IsGenericLambda, bool, NthStmt)
  MX_VISIT_BOOL(LambdaExpr, is_mutable, getVal104, setVal104, initVal104, IsMutable, bool, NthStmt)
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
  MX_VISIT_ENTITY(IntegerLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
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
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, array_filler, getVal38, setVal38, initVal38, ArrayFiller, Expr, NthStmt, StmtUseSelector::ARRAY_FILLER)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, initialized_field_in_union, getVal39, setVal39, initVal39, InitializedFieldInUnion, FieldDecl, NthStmt, DeclUseSelector::INITIALIZED_FIELD_IN_UNION)
  MX_VISIT_ENTITY(InitListExpr, l_brace_token, getVal40, setVal40, initVal40, LBraceToken, Token, NthStmt, TokenUseSelector::L_BRACE_TOKEN)
  MX_VISIT_ENTITY(InitListExpr, r_brace_token, getVal41, setVal41, initVal41, RBraceToken, Token, NthStmt, TokenUseSelector::R_BRACE_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, semantic_form, getVal42, setVal42, initVal42, SemanticForm, InitListExpr, NthStmt, StmtUseSelector::SEMANTIC_FORM)
  MX_VISIT_OPTIONAL_ENTITY(InitListExpr, syntactic_form, getVal43, setVal43, initVal43, SyntacticForm, InitListExpr, NthStmt, StmtUseSelector::SYNTACTIC_FORM)
  MX_VISIT_BOOL(InitListExpr, had_array_range_designator, getVal102, setVal102, initVal102, HadArrayRangeDesignator, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, has_array_filler, getVal104, setVal104, initVal104, HasArrayFiller, bool, NthStmt)
  MX_VISIT_ENTITY_LIST(InitListExpr, initializers, getVal17, setVal17, initVal17, Initializers, Expr, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_explicit, getVal107, setVal107, initVal107, IsExplicit, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_semantic_form, getVal108, setVal108, initVal108, IsSemanticForm, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_string_literal_initializer, getVal109, setVal109, initVal109, IsStringLiteralInitializer, bool, NthStmt)
  MX_VISIT_BOOL(InitListExpr, is_syntactic_form, getVal110, setVal110, initVal110, IsSyntacticForm, bool, NthStmt)
  MX_VISIT_OPTIONAL_BOOL(InitListExpr, is_transparent, getVal111, setVal111, initVal111, IsTransparent, bool, NthStmt)
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
  MX_VISIT_ENTITY(ImaginaryLiteral, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
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
  MX_VISIT_ENTITY_LIST(GenericSelectionExpr, association_expressions, getVal17, setVal17, initVal17, AssociationExpressions, Expr, NthStmt)
  MX_VISIT_ENTITY(GenericSelectionExpr, controlling_expression, getVal38, setVal38, initVal38, ControllingExpression, Expr, NthStmt, StmtUseSelector::CONTROLLING_EXPRESSION)
  MX_VISIT_ENTITY(GenericSelectionExpr, default_token, getVal39, setVal39, initVal39, DefaultToken, Token, NthStmt, TokenUseSelector::DEFAULT_TOKEN)
  MX_VISIT_ENTITY(GenericSelectionExpr, generic_token, getVal40, setVal40, initVal40, GenericToken, Token, NthStmt, TokenUseSelector::GENERIC_TOKEN)
  MX_VISIT_ENTITY(GenericSelectionExpr, r_paren_token, getVal41, setVal41, initVal41, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_ENTITY(GenericSelectionExpr, result_expression, getVal42, setVal42, initVal42, ResultExpression, Expr, NthStmt, StmtUseSelector::RESULT_EXPRESSION)
  MX_VISIT_BOOL(GenericSelectionExpr, is_result_dependent, getVal98, setVal98, initVal98, IsResultDependent, bool, NthStmt)
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
  MX_VISIT_ENTITY(GNUNullExpr, token_token, getVal38, setVal38, initVal38, TokenToken, Token, NthStmt, TokenUseSelector::TOKEN_TOKEN)
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
  MX_VISIT_ENTITY(FunctionParmPackExpr, parameter_pack, getVal38, setVal38, initVal38, ParameterPack, VarDecl, NthStmt, DeclUseSelector::PARAMETER_PACK)
  MX_VISIT_ENTITY(FunctionParmPackExpr, parameter_pack_token, getVal39, setVal39, initVal39, ParameterPackToken, Token, NthStmt, TokenUseSelector::PARAMETER_PACK_TOKEN)
  MX_VISIT_ENTITY_LIST(FunctionParmPackExpr, expansions, getVal17, setVal17, initVal17, Expansions, VarDecl, NthStmt)
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
  MX_VISIT_ENTITY(FullExpr, sub_expression, getVal38, setVal38, initVal38, SubExpression, Expr, NthStmt, StmtUseSelector::SUB_EXPRESSION)
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
  MX_VISIT_BOOL(ExprWithCleanups, cleanups_have_side_effects, getVal98, setVal98, initVal98, CleanupsHaveSideEffects, bool, NthStmt)
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
  MX_VISIT_ENUM(ConstantExpr, result_storage_kind, getVal103, setVal103, initVal103, ResultStorageKind, ConstantExprResultStorageKind, NthStmt)
  MX_VISIT_BOOL(ConstantExpr, has_ap_value_result, getVal98, setVal98, initVal98, HasAPValueResult, bool, NthStmt)
  MX_VISIT_BOOL(ConstantExpr, is_immediate_invocation, getVal99, setVal99, initVal99, IsImmediateInvocation, bool, NthStmt)
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
  MX_VISIT_ENTITY(FloatingLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
  MX_VISIT_BOOL(FloatingLiteral, is_exact, getVal98, setVal98, initVal98, IsExact, bool, NthStmt)
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
  MX_VISIT_ENTITY(FixedPointLiteral, token, getVal38, setVal38, initVal38, Token, Token, NthStmt, TokenUseSelector::TOKEN)
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
  MX_VISIT_BOOL(ExtVectorElementExpr, contains_duplicate_elements, getVal98, setVal98, initVal98, ContainsDuplicateElements, bool, NthStmt)
  MX_VISIT_ENTITY(ExtVectorElementExpr, accessor_token, getVal38, setVal38, initVal38, AccessorToken, Token, NthStmt, TokenUseSelector::ACCESSOR_TOKEN)
  MX_VISIT_ENTITY(ExtVectorElementExpr, base, getVal39, setVal39, initVal39, Base, Expr, NthStmt, StmtUseSelector::BASE)
  MX_VISIT_BOOL(ExtVectorElementExpr, is_arrow, getVal99, setVal99, initVal99, IsArrow, bool, NthStmt)
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
  MX_VISIT_ENTITY(ExpressionTraitExpr, queried_expression, getVal38, setVal38, initVal38, QueriedExpression, Expr, NthStmt, StmtUseSelector::QUERIED_EXPRESSION)
  MX_VISIT_ENUM(ExpressionTraitExpr, trait, getVal103, setVal103, initVal103, Trait, ExpressionTrait, NthStmt)
  MX_VISIT_BOOL(ExpressionTraitExpr, value, getVal98, setVal98, initVal98, Value, bool, NthStmt)
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
  MX_VISIT_ENTITY(AttributedStmt, attribute_token, getVal11, setVal11, initVal11, AttributeToken, Token, NthStmt, TokenUseSelector::ATTRIBUTE_TOKEN)
  MX_VISIT_ENTITY(AttributedStmt, sub_statement, getVal12, setVal12, initVal12, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
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
  MX_VISIT_ENTITY(SwitchStmt, body, getVal10, setVal10, initVal10, Body, Stmt, NthStmt, StmtUseSelector::BODY)
  MX_VISIT_ENTITY(SwitchStmt, condition, getVal11, setVal11, initVal11, Condition, Expr, NthStmt, StmtUseSelector::CONDITION)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, condition_variable, getVal12, setVal12, initVal12, ConditionVariable, VarDecl, NthStmt, DeclUseSelector::CONDITION_VARIABLE)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, condition_variable_declaration_statement, getVal14, setVal14, initVal14, ConditionVariableDeclarationStatement, DeclStmt, NthStmt, StmtUseSelector::CONDITION_VARIABLE_DECLARATION_STATEMENT)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, initializer, getVal15, setVal15, initVal15, Initializer, Stmt, NthStmt, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENTITY(SwitchStmt, l_paren_token, getVal18, setVal18, initVal18, LParenToken, Token, NthStmt, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENTITY(SwitchStmt, r_paren_token, getVal19, setVal19, initVal19, RParenToken, Token, NthStmt, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(SwitchStmt, first_switch_case, getVal20, setVal20, initVal20, FirstSwitchCase, SwitchCase, NthStmt, StmtUseSelector::FIRST_SWITCH_CASE)
  MX_VISIT_ENTITY(SwitchStmt, switch_token, getVal27, setVal27, initVal27, SwitchToken, Token, NthStmt, TokenUseSelector::SWITCH_TOKEN)
  MX_VISIT_BOOL(SwitchStmt, has_initializer_storage, getVal57, setVal57, initVal57, HasInitializerStorage, bool, NthStmt)
  MX_VISIT_BOOL(SwitchStmt, has_variable_storage, getVal58, setVal58, initVal58, HasVariableStorage, bool, NthStmt)
  MX_VISIT_BOOL(SwitchStmt, is_all_enum_cases_covered, getVal59, setVal59, initVal59, IsAllEnumCasesCovered, bool, NthStmt)
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
  MX_VISIT_ENTITY(SwitchCase, colon_token, getVal10, setVal10, initVal10, ColonToken, Token, NthStmt, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENTITY(SwitchCase, keyword_token, getVal11, setVal11, initVal11, KeywordToken, Token, NthStmt, TokenUseSelector::KEYWORD_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(SwitchCase, next_switch_case, getVal12, setVal12, initVal12, NextSwitchCase, SwitchCase, NthStmt, StmtUseSelector::NEXT_SWITCH_CASE)
  MX_VISIT_ENTITY(SwitchCase, sub_statement, getVal14, setVal14, initVal14, SubStatement, Stmt, NthStmt, StmtUseSelector::SUB_STATEMENT)
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
  MX_VISIT_ENTITY(DefaultStmt, default_token, getVal15, setVal15, initVal15, DefaultToken, Token, NthStmt, TokenUseSelector::DEFAULT_TOKEN)
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
  MX_VISIT_BOOL(CaseStmt, case_statement_is_gnu_range, getVal16, setVal16, initVal16, CaseStatementIsGNURange, bool, NthStmt)
  MX_VISIT_ENTITY(CaseStmt, case_token, getVal15, setVal15, initVal15, CaseToken, Token, NthStmt, TokenUseSelector::CASE_TOKEN)
  MX_VISIT_ENTITY(CaseStmt, ellipsis_token, getVal18, setVal18, initVal18, EllipsisToken, Token, NthStmt, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(CaseStmt, lhs, getVal19, setVal19, initVal19, LHS, Expr, NthStmt, StmtUseSelector::LHS)
  MX_VISIT_OPTIONAL_ENTITY(CaseStmt, rhs, getVal20, setVal20, initVal20, RHS, Expr, NthStmt, StmtUseSelector::RHS)
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
  MX_VISIT_DECL_LINK(Decl, parent_declaration, getVal0, setVal0, initVal0)
  MX_VISIT_STMT_LINK(Decl, parent_statement, getVal1, setVal1, initVal1)
  MX_VISIT_BOOL(Decl, is_definition, getVal2, setVal2, initVal2, IsThisDeclarationADefinition, bool, NthDecl)
  MX_VISIT_ENUM(Decl, access, getVal3, setVal3, initVal3, Access, AccessSpecifier, NthDecl)
  MX_VISIT_ENUM(Decl, availability, getVal4, setVal4, initVal4, Availability, AvailabilityResult, NthDecl)
  MX_VISIT_ENTITY(Decl, begin_token, getVal5, setVal5, initVal5, BeginToken, Token, NthDecl, TokenUseSelector::BEGIN_TOKEN)
  MX_VISIT_OPTIONAL_PSEUDO(Decl, described_template_parameters, getVal6, setVal6, initVal6, DescribedTemplateParameters, TemplateParameterList, NthDecl)
  MX_VISIT_ENTITY(Decl, end_token, getVal8, setVal8, initVal8, EndToken, Token, NthDecl, TokenUseSelector::END_TOKEN)
  MX_VISIT_ENUM(Decl, friend_object_kind, getVal9, setVal9, initVal9, FriendObjectKind, DeclFriendObjectKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(Decl, function_type, getVal10, setVal10, initVal10, FunctionType, FunctionType, NthDecl, TypeUseSelector::FUNCTION_TYPE)
  MX_VISIT_ENUM(Decl, module_ownership_kind, getVal12, setVal12, initVal12, ModuleOwnershipKind, DeclModuleOwnershipKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(Decl, non_closure_context, getVal13, setVal13, initVal13, NonClosureContext, Decl, NthDecl, DeclUseSelector::NON_CLOSURE_CONTEXT)
  MX_VISIT_BOOL(Decl, has_attributes, getVal15, setVal15, initVal15, HasAttributes, bool, NthDecl)
  MX_VISIT_BOOL(Decl, has_defining_attribute, getVal16, setVal16, initVal16, HasDefiningAttribute, bool, NthDecl)
  MX_VISIT_BOOL(Decl, has_owning_module, getVal17, setVal17, initVal17, HasOwningModule, bool, NthDecl)
  MX_VISIT_BOOL(Decl, has_tag_identifier_namespace, getVal18, setVal18, initVal18, HasTagIdentifierNamespace, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_defined_outside_function_or_method, getVal19, setVal19, initVal19, IsDefinedOutsideFunctionOrMethod, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_deprecated, getVal20, setVal20, initVal20, IsDeprecated, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_function_or_function_template, getVal21, setVal21, initVal21, IsFunctionOrFunctionTemplate, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_implicit, getVal22, setVal22, initVal22, IsImplicit, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_anonymous_namespace, getVal23, setVal23, initVal23, IsInAnonymousNamespace, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_local_scope_for_instantiation, getVal24, setVal24, initVal24, IsInLocalScopeForInstantiation, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_in_std_namespace, getVal25, setVal25, initVal25, IsInStdNamespace, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_invalid_declaration, getVal26, setVal26, initVal26, IsInvalidDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_module_private, getVal27, setVal27, initVal27, IsModulePrivate, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_out_of_line, getVal28, setVal28, initVal28, IsOutOfLine, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_parameter_pack, getVal29, setVal29, initVal29, IsParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_template_declaration, getVal30, setVal30, initVal30, IsTemplateDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_template_parameter, getVal31, setVal31, initVal31, IsTemplateParameter, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_template_parameter_pack, getVal32, setVal32, initVal32, IsTemplateParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_templated, getVal33, setVal33, initVal33, IsTemplated, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_top_level_declaration_in_obj_c_container, getVal34, setVal34, initVal34, IsTopLevelDeclarationInObjCContainer, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_unavailable, getVal35, setVal35, initVal35, IsUnavailable, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_unconditionally_visible, getVal36, setVal36, initVal36, IsUnconditionallyVisible, bool, NthDecl)
  MX_VISIT_BOOL(Decl, is_weak_imported, getVal37, setVal37, initVal37, IsWeakImported, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(Decl, redeclarations_visible_in_translation_unit, getVal38, setVal38, initVal38, Redeclarations, Decl, NthDecl)
  MX_VISIT_ENUM(Decl, kind, getVal39, setVal39, initVal39, Kind, DeclKind, NthDecl)
  MX_VISIT_ENTITY(Decl, token, getVal40, setVal40, initVal40, Token, Token, NthDecl, TokenUseSelector::TOKEN)
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
  MX_VISIT_ENTITY(ClassScopeFunctionSpecializationDecl, specialization, getVal43, setVal43, initVal43, Specialization, CXXMethodDecl, NthDecl, DeclUseSelector::SPECIALIZATION)
  MX_VISIT_BOOL(ClassScopeFunctionSpecializationDecl, has_explicit_template_arguments, getVal44, setVal44, initVal44, HasExplicitTemplateArguments, bool, NthDecl)
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
  MX_VISIT_ENTITY(CapturedDecl, context_parameter, getVal43, setVal43, initVal43, ContextParameter, ImplicitParamDecl, NthDecl, DeclUseSelector::CONTEXT_PARAMETER)
  MX_VISIT_BOOL(CapturedDecl, is_nothrow, getVal44, setVal44, initVal44, IsNothrow, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(CapturedDecl, parameters, getVal45, setVal45, initVal45, Parameters, ImplicitParamDecl, NthDecl)
  MX_VISIT_DECL_CONTEXT(CapturedDecl, declarations_in_context, getVal46, setVal46, initVal46, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_BOOL(BlockDecl, block_missing_return_type, getVal44, setVal44, initVal44, BlockMissingReturnType, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, can_avoid_copy_to_heap, getVal47, setVal47, initVal47, CanAvoidCopyToHeap, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, captures_cxx_this, getVal48, setVal48, initVal48, CapturesCXXThis, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, does_not_escape, getVal49, setVal49, initVal49, DoesNotEscape, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(BlockDecl, block_mangling_context_declaration, getVal43, setVal43, initVal43, BlockManglingContextDeclaration, Decl, NthDecl, DeclUseSelector::BLOCK_MANGLING_CONTEXT_DECLARATION)
  MX_VISIT_ENTITY(BlockDecl, caret_token, getVal51, setVal51, initVal51, CaretToken, Token, NthDecl, TokenUseSelector::CARET_TOKEN)
  MX_VISIT_ENTITY(BlockDecl, compound_body, getVal52, setVal52, initVal52, CompoundBody, CompoundStmt, NthDecl, StmtUseSelector::COMPOUND_BODY)
  MX_VISIT_ENTITY(BlockDecl, signature_as_written, getVal53, setVal53, initVal53, SignatureAsWritten, Type, NthDecl, TypeUseSelector::SIGNATURE_AS_WRITTEN)
  MX_VISIT_BOOL(BlockDecl, has_captures, getVal54, setVal54, initVal54, HasCaptures, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, is_conversion_from_lambda, getVal55, setVal55, initVal55, IsConversionFromLambda, bool, NthDecl)
  MX_VISIT_BOOL(BlockDecl, is_variadic, getVal56, setVal56, initVal56, IsVariadic, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(BlockDecl, parameters, getVal45, setVal45, initVal45, Parameters, ParmVarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(BlockDecl, parameter_declarations, getVal46, setVal46, initVal46, ParameterDeclarations, ParmVarDecl, NthDecl)
  MX_VISIT_DECL_CONTEXT(BlockDecl, declarations_in_context, getVal57, setVal57, initVal57, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY(AccessSpecDecl, access_specifier_token, getVal43, setVal43, initVal43, AccessSpecifierToken, Token, NthDecl, TokenUseSelector::ACCESS_SPECIFIER_TOKEN)
  MX_VISIT_ENTITY(AccessSpecDecl, colon_token, getVal51, setVal51, initVal51, ColonToken, Token, NthDecl, TokenUseSelector::COLON_TOKEN)
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
  MX_VISIT_ENTITY_LIST(OMPThreadPrivateDecl, varlists, getVal45, setVal45, initVal45, Varlists, Expr, NthDecl)
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
  MX_VISIT_ENTITY_LIST(OMPAllocateDecl, varlists, getVal45, setVal45, initVal45, Varlists, Expr, NthDecl)
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
  MX_VISIT_DECL_CONTEXT(TranslationUnitDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY(StaticAssertDecl, assert_expression, getVal43, setVal43, initVal43, AssertExpression, Expr, NthDecl, StmtUseSelector::ASSERT_EXPRESSION)
  MX_VISIT_ENTITY(StaticAssertDecl, message, getVal51, setVal51, initVal51, Message, StringLiteral, NthDecl, StmtUseSelector::MESSAGE)
  MX_VISIT_ENTITY(StaticAssertDecl, r_paren_token, getVal52, setVal52, initVal52, RParenToken, Token, NthDecl, TokenUseSelector::R_PAREN_TOKEN)
  MX_VISIT_BOOL(StaticAssertDecl, is_failed, getVal44, setVal44, initVal44, IsFailed, bool, NthDecl)
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
  MX_VISIT_DECL_CONTEXT(RequiresExprBodyDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_TEXT(PragmaDetectMismatchDecl, name, getVal58, setVal58, initVal58, Name, basic_string_view, NthDecl)
  MX_VISIT_TEXT(PragmaDetectMismatchDecl, value, getVal59, setVal59, initVal59, Value, basic_string_view, NthDecl)
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
  MX_VISIT_TEXT(PragmaCommentDecl, argument, getVal58, setVal58, initVal58, Argument, basic_string_view, NthDecl)
  MX_VISIT_ENUM(PragmaCommentDecl, comment_kind, getVal60, setVal60, initVal60, CommentKind, PragmaMSCommentKind, NthDecl)
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
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, getter_cxx_constructor, getVal43, setVal43, initVal43, GetterCXXConstructor, Expr, NthDecl, StmtUseSelector::GETTER_CXX_CONSTRUCTOR)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, getter_method_declaration, getVal51, setVal51, initVal51, GetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::GETTER_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, property_declaration, getVal52, setVal52, initVal52, PropertyDeclaration, ObjCPropertyDecl, NthDecl, DeclUseSelector::PROPERTY_DECLARATION)
  MX_VISIT_ENUM(ObjCPropertyImplDecl, property_implementation, getVal60, setVal60, initVal60, PropertyImplementation, ObjCPropertyImplDeclKind, NthDecl)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, property_instance_variable_declaration, getVal53, setVal53, initVal53, PropertyInstanceVariableDeclaration, ObjCIvarDecl, NthDecl, DeclUseSelector::PROPERTY_INSTANCE_VARIABLE_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, property_instance_variable_declaration_token, getVal61, setVal61, initVal61, PropertyInstanceVariableDeclarationToken, Token, NthDecl, TokenUseSelector::PROPERTY_INSTANCE_VARIABLE_DECLARATION_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, setter_cxx_assignment, getVal62, setVal62, initVal62, SetterCXXAssignment, Expr, NthDecl, StmtUseSelector::SETTER_CXX_ASSIGNMENT)
  MX_VISIT_ENTITY(ObjCPropertyImplDecl, setter_method_declaration, getVal63, setVal63, initVal63, SetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::SETTER_METHOD_DECLARATION)
  MX_VISIT_BOOL(ObjCPropertyImplDecl, is_instance_variable_name_specified, getVal44, setVal44, initVal44, IsInstanceVariableNameSpecified, bool, NthDecl)
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
  MX_VISIT_ENUM(NamedDecl, formal_linkage, getVal60, setVal60, initVal60, FormalLinkage, Linkage, NthDecl)
  MX_VISIT_TEXT(NamedDecl, name, getVal58, setVal58, initVal58, Name, basic_string, NthDecl)
  MX_VISIT_OPTIONAL_ENUM(NamedDecl, obj_cf_string_formatting_family, getVal64, setVal64, initVal64, ObjCFStringFormattingFamily, ObjCStringFormatFamily, NthDecl)
  MX_VISIT_TEXT(NamedDecl, qualified_name_as_string, getVal59, setVal59, initVal59, QualifiedNameAsString, basic_string, NthDecl)
  MX_VISIT_ENTITY(NamedDecl, underlying_declaration, getVal43, setVal43, initVal43, UnderlyingDeclaration, NamedDecl, NthDecl, DeclUseSelector::UNDERLYING_DECLARATION)
  MX_VISIT_ENUM(NamedDecl, visibility, getVal65, setVal65, initVal65, Visibility, Visibility, NthDecl)
  MX_VISIT_BOOL(NamedDecl, has_external_formal_linkage, getVal47, setVal47, initVal47, HasExternalFormalLinkage, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, has_linkage, getVal48, setVal48, initVal48, HasLinkage, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, has_linkage_been_computed, getVal49, setVal49, initVal49, HasLinkageBeenComputed, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_cxx_class_member, getVal50, setVal50, initVal50, IsCXXClassMember, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_cxx_instance_member, getVal54, setVal54, initVal54, IsCXXInstanceMember, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_externally_declarable, getVal55, setVal55, initVal55, IsExternallyDeclarable, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_externally_visible, getVal56, setVal56, initVal56, IsExternallyVisible, bool, NthDecl)
  MX_VISIT_BOOL(NamedDecl, is_linkage_valid, getVal66, setVal66, initVal66, IsLinkageValid, bool, NthDecl)
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
  MX_VISIT_TEXT(LabelDecl, ms_assembly_label, getVal67, setVal67, initVal67, MSAssemblyLabel, basic_string_view, NthDecl)
  MX_VISIT_ENTITY(LabelDecl, statement, getVal51, setVal51, initVal51, Statement, LabelStmt, NthDecl, StmtUseSelector::STATEMENT)
  MX_VISIT_BOOL(LabelDecl, is_gnu_local, getVal68, setVal68, initVal68, IsGnuLocal, bool, NthDecl)
  MX_VISIT_BOOL(LabelDecl, is_ms_assembly_label, getVal69, setVal69, initVal69, IsMSAssemblyLabel, bool, NthDecl)
  MX_VISIT_BOOL(LabelDecl, is_resolved_ms_assembly_label, getVal70, setVal70, initVal70, IsResolvedMSAssemblyLabel, bool, NthDecl)
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
  MX_VISIT_ENTITY_LIST(BaseUsingDecl, shadows, getVal45, setVal45, initVal45, Shadows, UsingShadowDecl, NthDecl)
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
  MX_VISIT_ENTITY(UsingEnumDecl, enum_declaration, getVal51, setVal51, initVal51, EnumDeclaration, EnumDecl, NthDecl, DeclUseSelector::ENUM_DECLARATION)
  MX_VISIT_ENTITY(UsingEnumDecl, enum_token, getVal52, setVal52, initVal52, EnumToken, Token, NthDecl, TokenUseSelector::ENUM_TOKEN)
  MX_VISIT_ENTITY(UsingEnumDecl, using_token, getVal53, setVal53, initVal53, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
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
  MX_VISIT_ENTITY(UsingDecl, using_token, getVal51, setVal51, initVal51, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_VISIT_BOOL(UsingDecl, has_typename, getVal68, setVal68, initVal68, HasTypename, bool, NthDecl)
  MX_VISIT_BOOL(UsingDecl, is_access_declaration, getVal69, setVal69, initVal69, IsAccessDeclaration, bool, NthDecl)
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
  MX_VISIT_ENTITY(ValueDecl, type, getVal51, setVal51, initVal51, Type, Type, NthDecl, TypeUseSelector::TYPE)
  MX_VISIT_BOOL(ValueDecl, is_weak, getVal68, setVal68, initVal68, IsWeak, bool, NthDecl)
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
  MX_VISIT_ENTITY(UnresolvedUsingValueDecl, ellipsis_token, getVal52, setVal52, initVal52, EllipsisToken, Token, NthDecl, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(UnresolvedUsingValueDecl, using_token, getVal53, setVal53, initVal53, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_VISIT_BOOL(UnresolvedUsingValueDecl, is_access_declaration, getVal69, setVal69, initVal69, IsAccessDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(UnresolvedUsingValueDecl, is_pack_expansion, getVal70, setVal70, initVal70, IsPackExpansion, bool, NthDecl)
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
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, combiner, getVal52, setVal52, initVal52, Combiner, Expr, NthDecl, StmtUseSelector::COMBINER)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, combiner_in, getVal53, setVal53, initVal53, CombinerIn, Expr, NthDecl, StmtUseSelector::COMBINER_IN)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, combiner_out, getVal61, setVal61, initVal61, CombinerOut, Expr, NthDecl, StmtUseSelector::COMBINER_OUT)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, initializer_original, getVal62, setVal62, initVal62, InitializerOriginal, Expr, NthDecl, StmtUseSelector::INITIALIZER_ORIGINAL)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, initializer_private, getVal63, setVal63, initVal63, InitializerPrivate, Expr, NthDecl, StmtUseSelector::INITIALIZER_PRIVATE)
  MX_VISIT_ENTITY(OMPDeclareReductionDecl, initializer, getVal71, setVal71, initVal71, Initializer, Expr, NthDecl, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENUM(OMPDeclareReductionDecl, initializer_kind, getVal72, setVal72, initVal72, InitializerKind, OMPDeclareReductionDeclInitKind, NthDecl)
  MX_VISIT_DECL_CONTEXT(OMPDeclareReductionDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY_LIST(IndirectFieldDecl, chain, getVal45, setVal45, initVal45, Chain, NamedDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(IndirectFieldDecl, anonymous_field, getVal52, setVal52, initVal52, AnonymousField, FieldDecl, NthDecl, DeclUseSelector::ANONYMOUS_FIELD)
  MX_VISIT_OPTIONAL_ENTITY(IndirectFieldDecl, variable_declaration, getVal53, setVal53, initVal53, VariableDeclaration, VarDecl, NthDecl, DeclUseSelector::VARIABLE_DECLARATION)
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
  MX_VISIT_OPTIONAL_ENTITY(EnumConstantDecl, initializer_expression, getVal52, setVal52, initVal52, InitializerExpression, Expr, NthDecl, StmtUseSelector::INITIALIZER_EXPRESSION)
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
  MX_VISIT_ENTITY(DeclaratorDecl, first_inner_token, getVal52, setVal52, initVal52, FirstInnerToken, Token, NthDecl, TokenUseSelector::FIRST_INNER_TOKEN)
  MX_VISIT_ENTITY(DeclaratorDecl, first_outer_token, getVal53, setVal53, initVal53, FirstOuterToken, Token, NthDecl, TokenUseSelector::FIRST_OUTER_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(DeclaratorDecl, trailing_requires_clause, getVal61, setVal61, initVal61, TrailingRequiresClause, Expr, NthDecl, StmtUseSelector::TRAILING_REQUIRES_CLAUSE)
  MX_VISIT_ENTITY(DeclaratorDecl, type_spec_end_token, getVal62, setVal62, initVal62, TypeSpecEndToken, Token, NthDecl, TokenUseSelector::TYPE_SPEC_END_TOKEN)
  MX_VISIT_ENTITY(DeclaratorDecl, type_spec_start_token, getVal63, setVal63, initVal63, TypeSpecStartToken, Token, NthDecl, TokenUseSelector::TYPE_SPEC_START_TOKEN)
  MX_VISIT_PSEUDO_LIST(DeclaratorDecl, template_parameter_lists, getVal73, setVal73, initVal73, TemplateParameterLists, TemplateParameterList, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, acting_definition, getVal71, setVal71, initVal71, ActingDefinition, VarDecl, NthDecl, DeclUseSelector::ACTING_DEFINITION)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, initializer, getVal74, setVal74, initVal74, Initializer, Expr, NthDecl, StmtUseSelector::INITIALIZER)
  MX_VISIT_ENUM(VarDecl, initializer_style, getVal72, setVal72, initVal72, InitializerStyle, VarDeclInitializationStyle, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, initializing_declaration, getVal76, setVal76, initVal76, InitializingDeclaration, VarDecl, NthDecl, DeclUseSelector::INITIALIZING_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, instantiated_from_static_data_member, getVal78, setVal78, initVal78, InstantiatedFromStaticDataMember, VarDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_STATIC_DATA_MEMBER)
  MX_VISIT_ENUM(VarDecl, language_linkage, getVal80, setVal80, initVal80, LanguageLinkage, LanguageLinkage, NthDecl)
  MX_VISIT_ENTITY(VarDecl, point_of_instantiation, getVal81, setVal81, initVal81, PointOfInstantiation, Token, NthDecl, TokenUseSelector::POINT_OF_INSTANTIATION)
  MX_VISIT_ENUM(VarDecl, storage_class, getVal82, setVal82, initVal82, StorageClass, StorageClass, NthDecl)
  MX_VISIT_ENUM(VarDecl, storage_duration, getVal83, setVal83, initVal83, StorageDuration, StorageDuration, NthDecl)
  MX_VISIT_ENUM(VarDecl, tls_kind, getVal84, setVal84, initVal84, TLSKind, VarDeclTLSKind, NthDecl)
  MX_VISIT_ENUM(VarDecl, tsc_spec, getVal85, setVal85, initVal85, TSCSpec, ThreadStorageClassSpecifier, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(VarDecl, template_instantiation_pattern, getVal86, setVal86, initVal86, TemplateInstantiationPattern, VarDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(VarDecl, template_specialization_kind, getVal88, setVal88, initVal88, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_ENUM(VarDecl, template_specialization_kind_for_instantiation, getVal89, setVal89, initVal89, TemplateSpecializationKindForInstantiation, TemplateSpecializationKind, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_constant_initialization, getVal90, setVal90, initVal90, HasConstantInitialization, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_dependent_alignment, getVal91, setVal91, initVal91, HasDependentAlignment, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_external_storage, getVal92, setVal92, initVal92, HasExternalStorage, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_global_storage, getVal93, setVal93, initVal93, HasGlobalStorage, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(VarDecl, has_ice_initializer, getVal94, setVal94, initVal94, HasICEInitializer, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_initializer, getVal96, setVal96, initVal96, HasInitializer, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, has_local_storage, getVal97, setVal97, initVal97, HasLocalStorage, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_arc_pseudo_strong, getVal98, setVal98, initVal98, IsARCPseudoStrong, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_cxx_for_range_declaration, getVal99, setVal99, initVal99, IsCXXForRangeDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_constexpr, getVal100, setVal100, initVal100, IsConstexpr, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_direct_initializer, getVal101, setVal101, initVal101, IsDirectInitializer, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_escaping_byref, getVal102, setVal102, initVal102, IsEscapingByref, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_exception_variable, getVal103, setVal103, initVal103, IsExceptionVariable, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_extern_c, getVal104, setVal104, initVal104, IsExternC, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_file_variable_declaration, getVal105, setVal105, initVal105, IsFileVariableDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_function_or_method_variable_declaration, getVal106, setVal106, initVal106, IsFunctionOrMethodVariableDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_in_extern_c_context, getVal107, setVal107, initVal107, IsInExternCContext, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_in_extern_cxx_context, getVal108, setVal108, initVal108, IsInExternCXXContext, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_initializer_capture, getVal109, setVal109, initVal109, IsInitializerCapture, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_inline, getVal110, setVal110, initVal110, IsInline, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_inline_specified, getVal111, setVal111, initVal111, IsInlineSpecified, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_known_to_be_defined, getVal112, setVal112, initVal112, IsKnownToBeDefined, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_local_variable_declaration, getVal113, setVal113, initVal113, IsLocalVariableDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_local_variable_declaration_or_parm, getVal114, setVal114, initVal114, IsLocalVariableDeclarationOrParm, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_nrvo_variable, getVal115, setVal115, initVal115, IsNRVOVariable, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_no_destroy, getVal116, setVal116, initVal116, IsNoDestroy, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_non_escaping_byref, getVal117, setVal117, initVal117, IsNonEscapingByref, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_obj_c_for_declaration, getVal118, setVal118, initVal118, IsObjCForDeclaration, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_previous_declaration_in_same_block_scope, getVal119, setVal119, initVal119, IsPreviousDeclarationInSameBlockScope, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_static_data_member, getVal120, setVal120, initVal120, IsStaticDataMember, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_static_local, getVal121, setVal121, initVal121, IsStaticLocal, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_this_declaration_a_demoted_definition, getVal122, setVal122, initVal122, IsThisDeclarationADemotedDefinition, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, is_usable_in_constant_expressions, getVal123, setVal123, initVal123, IsUsableInConstantExpressions, bool, NthDecl)
  MX_VISIT_BOOL(VarDecl, might_be_usable_in_constant_expressions, getVal124, setVal124, initVal124, MightBeUsableInConstantExpressions, bool, NthDecl)
  MX_VISIT_ENUM(VarDecl, needs_destruction, getVal125, setVal125, initVal125, NeedsDestruction, QualTypeDestructionKind, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(ParmVarDecl, default_argument, getVal126, setVal126, initVal126, DefaultArgument, Expr, NthDecl, StmtUseSelector::DEFAULT_ARGUMENT)
  MX_VISIT_ENUM(ParmVarDecl, obj_c_decl_qualifier, getVal130, setVal130, initVal130, ObjCDeclQualifier, DeclObjCDeclQualifier, NthDecl)
  MX_VISIT_ENTITY(ParmVarDecl, original_type, getVal131, setVal131, initVal131, OriginalType, Type, NthDecl, TypeUseSelector::ORIGINAL_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(ParmVarDecl, uninstantiated_default_argument, getVal132, setVal132, initVal132, UninstantiatedDefaultArgument, Expr, NthDecl, StmtUseSelector::UNINSTANTIATED_DEFAULT_ARGUMENT)
  MX_VISIT_BOOL(ParmVarDecl, has_default_argument, getVal134, setVal134, initVal134, HasDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, has_inherited_default_argument, getVal135, setVal135, initVal135, HasInheritedDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, has_uninstantiated_default_argument, getVal136, setVal136, initVal136, HasUninstantiatedDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, has_unparsed_default_argument, getVal137, setVal137, initVal137, HasUnparsedDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, is_destroyed_in_callee, getVal138, setVal138, initVal138, IsDestroyedInCallee, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, is_knr_promoted, getVal139, setVal139, initVal139, IsKNRPromoted, bool, NthDecl)
  MX_VISIT_BOOL(ParmVarDecl, is_obj_c_method_parameter, getVal140, setVal140, initVal140, IsObjCMethodParameter, bool, NthDecl)
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
  MX_VISIT_ENUM(ImplicitParamDecl, parameter_kind, getVal130, setVal130, initVal130, ParameterKind, ImplicitParamDeclImplicitParamKind, NthDecl)
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
  MX_VISIT_ENTITY_LIST(DecompositionDecl, bindings, getVal45, setVal45, initVal45, Bindings, BindingDecl, NthDecl)
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
  MX_VISIT_ENTITY(VarTemplateSpecializationDecl, extern_token, getVal126, setVal126, initVal126, ExternToken, Token, NthDecl, TokenUseSelector::EXTERN_TOKEN)
  MX_VISIT_ENUM(VarTemplateSpecializationDecl, specialization_kind, getVal130, setVal130, initVal130, SpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_PSEUDO_LIST(VarTemplateSpecializationDecl, template_arguments, getVal141, setVal141, initVal141, TemplateArguments, TemplateArgument, NthDecl)
  MX_VISIT_PSEUDO_LIST(VarTemplateSpecializationDecl, template_instantiation_arguments, getVal142, setVal142, initVal142, TemplateInstantiationArguments, TemplateArgument, NthDecl)
  MX_VISIT_ENTITY(VarTemplateSpecializationDecl, template_keyword_token, getVal128, setVal128, initVal128, TemplateKeywordToken, Token, NthDecl, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_ENTITY(VarTemplateSpecializationDecl, type_as_written, getVal129, setVal129, initVal129, TypeAsWritten, Type, NthDecl, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(VarTemplateSpecializationDecl, is_class_scope_explicit_specialization, getVal127, setVal127, initVal127, IsClassScopeExplicitSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(VarTemplateSpecializationDecl, is_explicit_instantiation_or_specialization, getVal133, setVal133, initVal133, IsExplicitInstantiationOrSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(VarTemplateSpecializationDecl, is_explicit_specialization, getVal134, setVal134, initVal134, IsExplicitSpecialization, bool, NthDecl)
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
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, default_argument_was_inherited, getVal70, setVal70, initVal70, DefaultArgumentWasInherited, bool, NthDecl)
  MX_VISIT_ENTITY(NonTypeTemplateParmDecl, default_argument, getVal71, setVal71, initVal71, DefaultArgument, Expr, NthDecl, StmtUseSelector::DEFAULT_ARGUMENT)
  MX_VISIT_ENTITY(NonTypeTemplateParmDecl, default_argument_token, getVal74, setVal74, initVal74, DefaultArgumentToken, Token, NthDecl, TokenUseSelector::DEFAULT_ARGUMENT_TOKEN)
  MX_VISIT_ENTITY(NonTypeTemplateParmDecl, placeholder_type_constraint, getVal76, setVal76, initVal76, PlaceholderTypeConstraint, Expr, NthDecl, StmtUseSelector::PLACEHOLDER_TYPE_CONSTRAINT)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, has_default_argument, getVal75, setVal75, initVal75, HasDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, has_placeholder_type_constraint, getVal77, setVal77, initVal77, HasPlaceholderTypeConstraint, bool, NthDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, is_expanded_parameter_pack, getVal79, setVal79, initVal79, IsExpandedParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(NonTypeTemplateParmDecl, is_pack_expansion, getVal87, setVal87, initVal87, IsPackExpansion, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(NonTypeTemplateParmDecl, expansion_types, getVal45, setVal45, initVal45, ExpansionTypes, Type, NthDecl)
  MX_VISIT_ENTITY_LIST(NonTypeTemplateParmDecl, expansion_type_source_infos, getVal46, setVal46, initVal46, ExpansionTypeSourceInfos, Type, NthDecl)
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
  MX_VISIT_BOOL(MSPropertyDecl, has_getter, getVal70, setVal70, initVal70, HasGetter, bool, NthDecl)
  MX_VISIT_BOOL(MSPropertyDecl, has_setter, getVal75, setVal75, initVal75, HasSetter, bool, NthDecl)
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
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, does_declaration_force_externally_visible_definition, getVal70, setVal70, initVal70, DoesDeclarationForceExternallyVisibleDefinition, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, does_this_declaration_have_a_body, getVal77, setVal77, initVal77, DoesThisDeclarationHaveABody, bool, NthDecl)
  MX_VISIT_ENTITY(FunctionDecl, call_result_type, getVal71, setVal71, initVal71, CallResultType, Type, NthDecl, TypeUseSelector::CALL_RESULT_TYPE)
  MX_VISIT_ENUM(FunctionDecl, constexpr_kind, getVal72, setVal72, initVal72, ConstexprKind, ConstexprSpecKind, NthDecl)
  MX_VISIT_ENTITY(FunctionDecl, declared_return_type, getVal74, setVal74, initVal74, DeclaredReturnType, Type, NthDecl, TypeUseSelector::DECLARED_RETURN_TYPE)
  MX_VISIT_ENTITY(FunctionDecl, ellipsis_token, getVal76, setVal76, initVal76, EllipsisToken, Token, NthDecl, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENUM(FunctionDecl, exception_spec_type, getVal80, setVal80, initVal80, ExceptionSpecType, ExceptionSpecificationType, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FunctionDecl, instantiated_from_member_function, getVal86, setVal86, initVal86, InstantiatedFromMemberFunction, FunctionDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_FUNCTION)
  MX_VISIT_ENUM(FunctionDecl, language_linkage, getVal82, setVal82, initVal82, LanguageLinkage, LanguageLinkage, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, multi_version_kind, getVal83, setVal83, initVal83, MultiVersionKind, MultiVersionKind, NthDecl)
  MX_VISIT_OPTIONAL_INT(FunctionDecl, odr_hash, getVal143, setVal143, initVal143, ODRHash, unsigned, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, overloaded_operator, getVal84, setVal84, initVal84, OverloadedOperator, OverloadedOperatorKind, NthDecl)
  MX_VISIT_ENTITY(FunctionDecl, point_of_instantiation, getVal129, setVal129, initVal129, PointOfInstantiation, Token, NthDecl, TokenUseSelector::POINT_OF_INSTANTIATION)
  MX_VISIT_ENTITY(FunctionDecl, return_type, getVal131, setVal131, initVal131, ReturnType, Type, NthDecl, TypeUseSelector::RETURN_TYPE)
  MX_VISIT_ENUM(FunctionDecl, storage_class, getVal85, setVal85, initVal85, StorageClass, StorageClass, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FunctionDecl, template_instantiation_pattern, getVal145, setVal145, initVal145, TemplateInstantiationPattern, FunctionDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(FunctionDecl, template_specialization_kind, getVal88, setVal88, initVal88, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, template_specialization_kind_for_instantiation, getVal89, setVal89, initVal89, TemplateSpecializationKindForInstantiation, TemplateSpecializationKind, NthDecl)
  MX_VISIT_ENUM(FunctionDecl, templated_kind, getVal125, setVal125, initVal125, TemplatedKind, FunctionDeclTemplatedKind, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_implicit_return_zero, getVal91, setVal91, initVal91, HasImplicitReturnZero, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_inherited_prototype, getVal92, setVal92, initVal92, HasInheritedPrototype, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_one_parameter_or_default_arguments, getVal93, setVal93, initVal93, HasOneParameterOrDefaultArguments, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_prototype, getVal94, setVal94, initVal94, HasPrototype, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_skipped_body, getVal95, setVal95, initVal95, HasSkippedBody, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_trivial_body, getVal96, setVal96, initVal96, HasTrivialBody, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, has_written_prototype, getVal97, setVal97, initVal97, HasWrittenPrototype, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, instantiation_is_pending, getVal98, setVal98, initVal98, InstantiationIsPending, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_cpu_dispatch_multi_version, getVal99, setVal99, initVal99, IsCPUDispatchMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_cpu_specific_multi_version, getVal100, setVal100, initVal100, IsCPUSpecificMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_consteval, getVal101, setVal101, initVal101, IsConsteval, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_constexpr, getVal102, setVal102, initVal102, IsConstexpr, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_constexpr_specified, getVal103, setVal103, initVal103, IsConstexprSpecified, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_defaulted, getVal104, setVal104, initVal104, IsDefaulted, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_deleted, getVal105, setVal105, initVal105, IsDeleted, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_deleted_as_written, getVal106, setVal106, initVal106, IsDeletedAsWritten, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_destroying_operator_delete, getVal107, setVal107, initVal107, IsDestroyingOperatorDelete, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_explicitly_defaulted, getVal108, setVal108, initVal108, IsExplicitlyDefaulted, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_extern_c, getVal109, setVal109, initVal109, IsExternC, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_function_template_specialization, getVal110, setVal110, initVal110, IsFunctionTemplateSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_global, getVal111, setVal111, initVal111, IsGlobal, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_implicitly_instantiable, getVal112, setVal112, initVal112, IsImplicitlyInstantiable, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_in_extern_c_context, getVal113, setVal113, initVal113, IsInExternCContext, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_in_extern_cxx_context, getVal114, setVal114, initVal114, IsInExternCXXContext, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_inline_builtin_declaration, getVal115, setVal115, initVal115, IsInlineBuiltinDeclaration, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, is_inline_definition_externally_visible, getVal116, setVal116, initVal116, IsInlineDefinitionExternallyVisible, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_inline_specified, getVal118, setVal118, initVal118, IsInlineSpecified, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_inlined, getVal119, setVal119, initVal119, IsInlined, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_late_template_parsed, getVal120, setVal120, initVal120, IsLateTemplateParsed, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, is_ms_extern_inline, getVal121, setVal121, initVal121, IsMSExternInline, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_msvcrt_entry_point, getVal123, setVal123, initVal123, IsMSVCRTEntryPoint, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_main, getVal124, setVal124, initVal124, IsMain, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_multi_version, getVal127, setVal127, initVal127, IsMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_no_return, getVal133, setVal133, initVal133, IsNoReturn, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_overloaded_operator, getVal134, setVal134, initVal134, IsOverloadedOperator, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_pure, getVal135, setVal135, initVal135, IsPure, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_replaceable_global_allocation_function, getVal136, setVal136, initVal136, IsReplaceableGlobalAllocationFunction, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(FunctionDecl, is_reserved_global_placement_operator, getVal137, setVal137, initVal137, IsReservedGlobalPlacementOperator, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_static, getVal139, setVal139, initVal139, IsStatic, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_target_multi_version, getVal140, setVal140, initVal140, IsTargetMultiVersion, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_template_instantiation, getVal146, setVal146, initVal146, IsTemplateInstantiation, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_definition, getVal147, setVal147, initVal147, IsThisDeclarationADefinition, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_this_declaration_instantiated_from_a_friend_definition, getVal148, setVal148, initVal148, IsThisDeclarationInstantiatedFromAFriendDefinition, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_trivial, getVal149, setVal149, initVal149, IsTrivial, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_trivial_for_call, getVal150, setVal150, initVal150, IsTrivialForCall, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_user_provided, getVal151, setVal151, initVal151, IsUserProvided, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_variadic, getVal152, setVal152, initVal152, IsVariadic, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, is_virtual_as_written, getVal153, setVal153, initVal153, IsVirtualAsWritten, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(FunctionDecl, parameters, getVal45, setVal45, initVal45, Parameters, ParmVarDecl, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, uses_seh_try, getVal154, setVal154, initVal154, UsesSEHTry, bool, NthDecl)
  MX_VISIT_BOOL(FunctionDecl, will_have_body, getVal155, setVal155, initVal155, WillHaveBody, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FunctionDecl, body, getVal156, setVal156, initVal156, Body, Stmt, NthDecl, StmtUseSelector::BODY)
  MX_VISIT_DECL_CONTEXT(FunctionDecl, declarations_in_context, getVal46, setVal46, initVal46, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENUM(CXXMethodDecl, reference_qualifier, getVal130, setVal130, initVal130, ReferenceQualifier, RefQualifierKind, NthDecl)
  MX_VISIT_ENTITY(CXXMethodDecl, this_object_type, getVal158, setVal158, initVal158, ThisObjectType, Type, NthDecl, TypeUseSelector::THIS_OBJECT_TYPE)
  MX_VISIT_ENTITY(CXXMethodDecl, this_type, getVal159, setVal159, initVal159, ThisType, Type, NthDecl, TypeUseSelector::THIS_TYPE)
  MX_VISIT_BOOL(CXXMethodDecl, has_inline_body, getVal160, setVal160, initVal160, HasInlineBody, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_const, getVal161, setVal161, initVal161, IsConst, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_copy_assignment_operator, getVal162, setVal162, initVal162, IsCopyAssignmentOperator, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_instance, getVal163, setVal163, initVal163, IsInstance, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_lambda_static_invoker, getVal164, setVal164, initVal164, IsLambdaStaticInvoker, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_move_assignment_operator, getVal165, setVal165, initVal165, IsMoveAssignmentOperator, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_virtual, getVal166, setVal166, initVal166, IsVirtual, bool, NthDecl)
  MX_VISIT_BOOL(CXXMethodDecl, is_volatile, getVal167, setVal167, initVal167, IsVolatile, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXMethodDecl, overridden_methods, getVal57, setVal57, initVal57, OverriddenMethods, CXXMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXMethodDecl, parameter_declarations, getVal168, setVal168, initVal168, ParameterDeclarations, ParmVarDecl, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(CXXDestructorDecl, operator_delete, getVal169, setVal169, initVal169, OperatorDelete, FunctionDecl, NthDecl, DeclUseSelector::OPERATOR_DELETE)
  MX_VISIT_OPTIONAL_ENTITY(CXXDestructorDecl, operator_delete_this_argument, getVal171, setVal171, initVal171, OperatorDeleteThisArgument, Expr, NthDecl, StmtUseSelector::OPERATOR_DELETE_THIS_ARGUMENT)
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
  MX_VISIT_ENTITY(CXXConversionDecl, conversion_type, getVal169, setVal169, initVal169, ConversionType, Type, NthDecl, TypeUseSelector::CONVERSION_TYPE)
  MX_VISIT_BOOL(CXXConversionDecl, is_explicit, getVal170, setVal170, initVal170, IsExplicit, bool, NthDecl)
  MX_VISIT_BOOL(CXXConversionDecl, is_lambda_to_block_pointer_conversion, getVal172, setVal172, initVal172, IsLambdaToBlockPointerConversion, bool, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(CXXConstructorDecl, target_constructor, getVal169, setVal169, initVal169, TargetConstructor, CXXConstructorDecl, NthDecl, DeclUseSelector::TARGET_CONSTRUCTOR)
  MX_VISIT_BOOL(CXXConstructorDecl, is_default_constructor, getVal172, setVal172, initVal172, IsDefaultConstructor, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_delegating_constructor, getVal173, setVal173, initVal173, IsDelegatingConstructor, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_explicit, getVal174, setVal174, initVal174, IsExplicit, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_inheriting_constructor, getVal175, setVal175, initVal175, IsInheritingConstructor, bool, NthDecl)
  MX_VISIT_BOOL(CXXConstructorDecl, is_specialization_copying_object, getVal176, setVal176, initVal176, IsSpecializationCopyingObject, bool, NthDecl)
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
  MX_VISIT_ENTITY(CXXDeductionGuideDecl, corresponding_constructor, getVal158, setVal158, initVal158, CorrespondingConstructor, CXXConstructorDecl, NthDecl, DeclUseSelector::CORRESPONDING_CONSTRUCTOR)
  MX_VISIT_BOOL(CXXDeductionGuideDecl, is_copy_deduction_candidate, getVal160, setVal160, initVal160, IsCopyDeductionCandidate, bool, NthDecl)
  MX_VISIT_BOOL(CXXDeductionGuideDecl, is_explicit, getVal161, setVal161, initVal161, IsExplicit, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXDeductionGuideDecl, parameter_declarations, getVal57, setVal57, initVal57, ParameterDeclarations, ParmVarDecl, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(FieldDecl, bit_width, getVal71, setVal71, initVal71, BitWidth, Expr, NthDecl, StmtUseSelector::BIT_WIDTH)
  MX_VISIT_OPTIONAL_ENTITY(FieldDecl, captured_vla_type, getVal74, setVal74, initVal74, CapturedVLAType, VariableArrayType, NthDecl, TypeUseSelector::CAPTURED_VLA_TYPE)
  MX_VISIT_ENUM(FieldDecl, in_class_initializer_style, getVal72, setVal72, initVal72, InClassInitializerStyle, InClassInitStyle, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(FieldDecl, in_class_initializer, getVal76, setVal76, initVal76, InClassInitializer, Expr, NthDecl, StmtUseSelector::IN_CLASS_INITIALIZER)
  MX_VISIT_BOOL(FieldDecl, has_captured_vla_type, getVal79, setVal79, initVal79, HasCapturedVLAType, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, has_in_class_initializer, getVal87, setVal87, initVal87, HasInClassInitializer, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_anonymous_struct_or_union, getVal90, setVal90, initVal90, IsAnonymousStructOrUnion, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_bit_field, getVal91, setVal91, initVal91, IsBitField, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_mutable, getVal92, setVal92, initVal92, IsMutable, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_unnamed_bitfield, getVal93, setVal93, initVal93, IsUnnamedBitfield, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_zero_length_bit_field, getVal94, setVal94, initVal94, IsZeroLengthBitField, bool, NthDecl)
  MX_VISIT_BOOL(FieldDecl, is_zero_size, getVal95, setVal95, initVal95, IsZeroSize, bool, NthDecl)
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
  MX_VISIT_ENUM(ObjCIvarDecl, access_control, getVal80, setVal80, initVal80, AccessControl, ObjCIvarDeclAccessControl, NthDecl)
  MX_VISIT_ENUM(ObjCIvarDecl, canonical_access_control, getVal82, setVal82, initVal82, CanonicalAccessControl, ObjCIvarDeclAccessControl, NthDecl)
  MX_VISIT_ENTITY(ObjCIvarDecl, containing_interface, getVal78, setVal78, initVal78, ContainingInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CONTAINING_INTERFACE)
  MX_VISIT_ENTITY(ObjCIvarDecl, next_instance_variable, getVal81, setVal81, initVal81, NextInstanceVariable, ObjCIvarDecl, NthDecl, DeclUseSelector::NEXT_INSTANCE_VARIABLE)
  MX_VISIT_BOOL(ObjCIvarDecl, synthesize, getVal96, setVal96, initVal96, Synthesize, bool, NthDecl)
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
  MX_VISIT_ENTITY(BindingDecl, binding, getVal52, setVal52, initVal52, Binding, Expr, NthDecl, StmtUseSelector::BINDING)
  MX_VISIT_ENTITY(BindingDecl, decomposed_declaration, getVal53, setVal53, initVal53, DecomposedDeclaration, ValueDecl, NthDecl, DeclUseSelector::DECOMPOSED_DECLARATION)
  MX_VISIT_ENTITY(BindingDecl, holding_variable, getVal61, setVal61, initVal61, HoldingVariable, VarDecl, NthDecl, DeclUseSelector::HOLDING_VARIABLE)
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
  MX_VISIT_ENTITY(OMPDeclareMapperDecl, mapper_variable_reference, getVal52, setVal52, initVal52, MapperVariableReference, Expr, NthDecl, StmtUseSelector::MAPPER_VARIABLE_REFERENCE)
  MX_VISIT_DECL_CONTEXT(OMPDeclareMapperDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY(UsingShadowDecl, introducer, getVal51, setVal51, initVal51, Introducer, BaseUsingDecl, NthDecl, DeclUseSelector::INTRODUCER)
  MX_VISIT_OPTIONAL_ENTITY(UsingShadowDecl, next_using_shadow_declaration, getVal52, setVal52, initVal52, NextUsingShadowDeclaration, UsingShadowDecl, NthDecl, DeclUseSelector::NEXT_USING_SHADOW_DECLARATION)
  MX_VISIT_ENTITY(UsingShadowDecl, target_declaration, getVal53, setVal53, initVal53, TargetDeclaration, NamedDecl, NthDecl, DeclUseSelector::TARGET_DECLARATION)
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
  MX_VISIT_BOOL(ConstructorUsingShadowDecl, constructs_virtual_base, getVal69, setVal69, initVal69, ConstructsVirtualBase, bool, NthDecl)
  MX_VISIT_ENTITY(ConstructorUsingShadowDecl, constructed_base_class, getVal61, setVal61, initVal61, ConstructedBaseClass, CXXRecordDecl, NthDecl, DeclUseSelector::CONSTRUCTED_BASE_CLASS)
  MX_VISIT_OPTIONAL_ENTITY(ConstructorUsingShadowDecl, constructed_base_class_shadow_declaration, getVal62, setVal62, initVal62, ConstructedBaseClassShadowDeclaration, ConstructorUsingShadowDecl, NthDecl, DeclUseSelector::CONSTRUCTED_BASE_CLASS_SHADOW_DECLARATION)
  MX_VISIT_ENTITY(ConstructorUsingShadowDecl, nominated_base_class, getVal63, setVal63, initVal63, NominatedBaseClass, CXXRecordDecl, NthDecl, DeclUseSelector::NOMINATED_BASE_CLASS)
  MX_VISIT_OPTIONAL_ENTITY(ConstructorUsingShadowDecl, nominated_base_class_shadow_declaration, getVal71, setVal71, initVal71, NominatedBaseClassShadowDeclaration, ConstructorUsingShadowDecl, NthDecl, DeclUseSelector::NOMINATED_BASE_CLASS_SHADOW_DECLARATION)
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
  MX_VISIT_ENTITY_LIST(UsingPackDecl, expansions, getVal45, setVal45, initVal45, Expansions, NamedDecl, NthDecl)
  MX_VISIT_ENTITY(UsingPackDecl, instantiated_from_using_declaration, getVal51, setVal51, initVal51, InstantiatedFromUsingDeclaration, NamedDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_USING_DECLARATION)
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
  MX_VISIT_ENTITY(UsingDirectiveDecl, identifier_token, getVal51, setVal51, initVal51, IdentifierToken, Token, NthDecl, TokenUseSelector::IDENTIFIER_TOKEN)
  MX_VISIT_ENTITY(UsingDirectiveDecl, namespace_key_token, getVal52, setVal52, initVal52, NamespaceKeyToken, Token, NthDecl, TokenUseSelector::NAMESPACE_KEY_TOKEN)
  MX_VISIT_ENTITY(UsingDirectiveDecl, nominated_namespace_as_written, getVal53, setVal53, initVal53, NominatedNamespaceAsWritten, NamedDecl, NthDecl, DeclUseSelector::NOMINATED_NAMESPACE_AS_WRITTEN)
  MX_VISIT_ENTITY(UsingDirectiveDecl, using_token, getVal61, setVal61, initVal61, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
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
  MX_VISIT_OPTIONAL_ENTITY(TypeDecl, type_for_declaration, getVal51, setVal51, initVal51, TypeForDeclaration, Type, NthDecl, TypeUseSelector::TYPE_FOR_DECLARATION)
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
  MX_VISIT_BOOL(TemplateTypeParmDecl, default_argument_was_inherited, getVal69, setVal69, initVal69, DefaultArgumentWasInherited, bool, NthDecl)
  MX_VISIT_ENTITY(TemplateTypeParmDecl, default_argument, getVal52, setVal52, initVal52, DefaultArgument, Type, NthDecl, TypeUseSelector::DEFAULT_ARGUMENT)
  MX_VISIT_ENTITY(TemplateTypeParmDecl, default_argument_info, getVal53, setVal53, initVal53, DefaultArgumentInfo, Type, NthDecl, TypeUseSelector::DEFAULT_ARGUMENT_INFO)
  MX_VISIT_ENTITY(TemplateTypeParmDecl, default_argument_token, getVal61, setVal61, initVal61, DefaultArgumentToken, Token, NthDecl, TokenUseSelector::DEFAULT_ARGUMENT_TOKEN)
  MX_VISIT_BOOL(TemplateTypeParmDecl, has_default_argument, getVal70, setVal70, initVal70, HasDefaultArgument, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, has_type_constraint, getVal75, setVal75, initVal75, HasTypeConstraint, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, is_expanded_parameter_pack, getVal77, setVal77, initVal77, IsExpandedParameterPack, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, is_pack_expansion, getVal79, setVal79, initVal79, IsPackExpansion, bool, NthDecl)
  MX_VISIT_BOOL(TemplateTypeParmDecl, was_declared_with_typename, getVal87, setVal87, initVal87, WasDeclaredWithTypename, bool, NthDecl)
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
  MX_VISIT_ENTITY(TagDecl, first_inner_token, getVal61, setVal61, initVal61, FirstInnerToken, Token, NthDecl, TokenUseSelector::FIRST_INNER_TOKEN)
  MX_VISIT_ENTITY(TagDecl, first_outer_token, getVal62, setVal62, initVal62, FirstOuterToken, Token, NthDecl, TokenUseSelector::FIRST_OUTER_TOKEN)
  MX_VISIT_ENUM(TagDecl, tag_kind, getVal72, setVal72, initVal72, TagKind, TagTypeKind, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(TagDecl, typedef_name_for_anonymous_declaration, getVal63, setVal63, initVal63, TypedefNameForAnonymousDeclaration, TypedefNameDecl, NthDecl, DeclUseSelector::TYPEDEF_NAME_FOR_ANONYMOUS_DECLARATION)
  MX_VISIT_BOOL(TagDecl, has_name_for_linkage, getVal70, setVal70, initVal70, HasNameForLinkage, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_being_defined, getVal75, setVal75, initVal75, IsBeingDefined, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_class, getVal77, setVal77, initVal77, IsClass, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_complete_definition, getVal79, setVal79, initVal79, IsCompleteDefinition, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_complete_definition_required, getVal87, setVal87, initVal87, IsCompleteDefinitionRequired, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_dependent_type, getVal90, setVal90, initVal90, IsDependentType, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_embedded_in_declarator, getVal91, setVal91, initVal91, IsEmbeddedInDeclarator, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_enum, getVal92, setVal92, initVal92, IsEnum, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_free_standing, getVal93, setVal93, initVal93, IsFreeStanding, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_interface, getVal94, setVal94, initVal94, IsInterface, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_struct, getVal95, setVal95, initVal95, IsStruct, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_definition, getVal96, setVal96, initVal96, IsThisDeclarationADefinition, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, is_union, getVal97, setVal97, initVal97, IsUnion, bool, NthDecl)
  MX_VISIT_BOOL(TagDecl, may_have_out_of_date_definition, getVal98, setVal98, initVal98, MayHaveOutOfDateDefinition, bool, NthDecl)
  MX_VISIT_PSEUDO_LIST(TagDecl, template_parameter_lists, getVal73, setVal73, initVal73, TemplateParameterLists, TemplateParameterList, NthDecl)
  MX_VISIT_DECL_CONTEXT(TagDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_BOOL(RecordDecl, can_pass_in_registers, getVal99, setVal99, initVal99, CanPassInRegisters, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(RecordDecl, fields, getVal46, setVal46, initVal46, Fields, FieldDecl, NthDecl)
  MX_VISIT_ENUM(RecordDecl, argument_passing_restrictions, getVal80, setVal80, initVal80, ArgumentPassingRestrictions, RecordDeclArgPassingKind, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_flexible_array_member, getVal100, setVal100, initVal100, HasFlexibleArrayMember, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_loaded_fields_from_external_storage, getVal101, setVal101, initVal101, HasLoadedFieldsFromExternalStorage, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_non_trivial_to_primitive_copy_c_union, getVal102, setVal102, initVal102, HasNonTrivialToPrimitiveCopyCUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_non_trivial_to_primitive_default_initialize_c_union, getVal103, setVal103, initVal103, HasNonTrivialToPrimitiveDefaultInitializeCUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_non_trivial_to_primitive_destruct_c_union, getVal104, setVal104, initVal104, HasNonTrivialToPrimitiveDestructCUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_object_member, getVal105, setVal105, initVal105, HasObjectMember, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, has_volatile_member, getVal106, setVal106, initVal106, HasVolatileMember, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_anonymous_struct_or_union, getVal107, setVal107, initVal107, IsAnonymousStructOrUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_captured_record, getVal108, setVal108, initVal108, IsCapturedRecord, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_injected_class_name, getVal109, setVal109, initVal109, IsInjectedClassName, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_lambda, getVal110, setVal110, initVal110, IsLambda, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_ms_struct, getVal111, setVal111, initVal111, IsMsStruct, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_non_trivial_to_primitive_copy, getVal112, setVal112, initVal112, IsNonTrivialToPrimitiveCopy, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_non_trivial_to_primitive_default_initialize, getVal113, setVal113, initVal113, IsNonTrivialToPrimitiveDefaultInitialize, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_non_trivial_to_primitive_destroy, getVal114, setVal114, initVal114, IsNonTrivialToPrimitiveDestroy, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_or_contains_union, getVal115, setVal115, initVal115, IsOrContainsUnion, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, is_parameter_destroyed_in_callee, getVal116, setVal116, initVal116, IsParameterDestroyedInCallee, bool, NthDecl)
  MX_VISIT_BOOL(RecordDecl, may_insert_extra_padding, getVal117, setVal117, initVal117, MayInsertExtraPadding, bool, NthDecl)
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
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, allow_const_default_initializer, getVal118, setVal118, initVal118, AllowConstDefaultInitializer, bool, NthDecl)
  MX_VISIT_OPTIONAL_PSEUDO_LIST(CXXRecordDecl, bases, getVal141, setVal141, initVal141, Bases, CXXBaseSpecifier, NthDecl)
  MX_VISIT_OPTIONAL_ENUM(CXXRecordDecl, calculate_inheritance_model, getVal82, setVal82, initVal82, CalculateInheritanceModel, MSInheritanceModel, NthDecl)
  MX_VISIT_ENTITY_LIST(CXXRecordDecl, constructors, getVal57, setVal57, initVal57, Constructors, CXXConstructorDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY_LIST(CXXRecordDecl, friends, getVal168, setVal168, initVal168, Friends, FriendDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, destructor, getVal71, setVal71, initVal71, Destructor, CXXDestructorDecl, NthDecl, DeclUseSelector::DESTRUCTOR)
  MX_VISIT_OPTIONAL_PSEUDO(CXXRecordDecl, generic_lambda_template_parameter_list, getVal143, setVal143, initVal143, GenericLambdaTemplateParameterList, TemplateParameterList, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, instantiated_from_member_class, getVal74, setVal74, initVal74, InstantiatedFromMemberClass, CXXRecordDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_CLASS)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, lambda_call_operator, getVal76, setVal76, initVal76, LambdaCallOperator, CXXMethodDecl, NthDecl, DeclUseSelector::LAMBDA_CALL_OPERATOR)
  MX_VISIT_OPTIONAL_ENUM(CXXRecordDecl, lambda_capture_default, getVal83, setVal83, initVal83, LambdaCaptureDefault, LambdaCaptureDefault, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, lambda_context_declaration, getVal78, setVal78, initVal78, LambdaContextDeclaration, Decl, NthDecl, DeclUseSelector::LAMBDA_CONTEXT_DECLARATION)
  MX_VISIT_OPTIONAL_ENTITY_LIST(CXXRecordDecl, lambda_explicit_template_parameters, getVal177, setVal177, initVal177, LambdaExplicitTemplateParameters, NamedDecl, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, lambda_mangling_number, getVal178, setVal178, initVal178, LambdaManglingNumber, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, lambda_type, getVal81, setVal81, initVal81, LambdaTypeInfo, Type, NthDecl, TypeUseSelector::LAMBDA_TYPE)
  MX_VISIT_OPTIONAL_ENUM(CXXRecordDecl, ms_inheritance_model, getVal84, setVal84, initVal84, MSInheritanceModel, MSInheritanceModel, NthDecl)
  MX_VISIT_ENUM(CXXRecordDecl, ms_vtor_disp_mode, getVal85, setVal85, initVal85, MSVtorDispMode, MSVtorDispMode, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, num_bases, getVal179, setVal179, initVal179, NumBases, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, num_virtual_bases, getVal180, setVal180, initVal180, NumVirtualBases, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_INT(CXXRecordDecl, odr_hash, getVal181, setVal181, initVal181, ODRHash, unsigned, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, template_instantiation_pattern, getVal86, setVal86, initVal86, TemplateInstantiationPattern, CXXRecordDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(CXXRecordDecl, template_specialization_kind, getVal88, setVal88, initVal88, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_any_dependent_bases, getVal149, setVal149, initVal149, HasAnyDependentBases, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_default_constructor, getVal151, setVal151, initVal151, HasConstexprDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_destructor, getVal153, setVal153, initVal153, HasConstexprDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_constexpr_non_copy_move_constructor, getVal155, setVal155, initVal155, HasConstexprNonCopyMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_copy_assignment_with_const_parameter, getVal160, setVal160, initVal160, HasCopyAssignmentWithConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_copy_constructor_with_const_parameter, getVal162, setVal162, initVal162, HasCopyConstructorWithConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_default_constructor, getVal164, setVal164, initVal164, HasDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_definition, getVal166, setVal166, initVal166, HasDefinition, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_direct_fields, getVal170, setVal170, initVal170, HasDirectFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_friends, getVal173, setVal173, initVal173, HasFriends, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_in_class_initializer, getVal175, setVal175, initVal175, HasInClassInitializer, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_inherited_assignment, getVal182, setVal182, initVal182, HasInheritedAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_inherited_constructor, getVal184, setVal184, initVal184, HasInheritedConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_irrelevant_destructor, getVal186, setVal186, initVal186, HasIrrelevantDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_known_lambda_internal_linkage, getVal188, setVal188, initVal188, HasKnownLambdaInternalLinkage, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_move_assignment, getVal190, setVal190, initVal190, HasMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_move_constructor, getVal192, setVal192, initVal192, HasMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_mutable_fields, getVal194, setVal194, initVal194, HasMutableFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_literal_type_fields_or_bases, getVal196, setVal196, initVal196, HasNonLiteralTypeFieldsOrBases, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_assignment, getVal198, setVal198, initVal198, HasNonTrivialCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_constructor, getVal200, setVal200, initVal200, HasNonTrivialCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_copy_constructor_for_call, getVal202, setVal202, initVal202, HasNonTrivialCopyConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_default_constructor, getVal204, setVal204, initVal204, HasNonTrivialDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_destructor, getVal206, setVal206, initVal206, HasNonTrivialDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_destructor_for_call, getVal208, setVal208, initVal208, HasNonTrivialDestructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_assignment, getVal210, setVal210, initVal210, HasNonTrivialMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_constructor, getVal212, setVal212, initVal212, HasNonTrivialMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_non_trivial_move_constructor_for_call, getVal214, setVal214, initVal214, HasNonTrivialMoveConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_private_fields, getVal216, setVal216, initVal216, HasPrivateFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_protected_fields, getVal218, setVal218, initVal218, HasProtectedFields, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_copy_assignment, getVal220, setVal220, initVal220, HasSimpleCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_copy_constructor, getVal222, setVal222, initVal222, HasSimpleCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_destructor, getVal224, setVal224, initVal224, HasSimpleDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_move_assignment, getVal226, setVal226, initVal226, HasSimpleMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_simple_move_constructor, getVal228, setVal228, initVal228, HasSimpleMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_assignment, getVal230, setVal230, initVal230, HasTrivialCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_constructor, getVal232, setVal232, initVal232, HasTrivialCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_copy_constructor_for_call, getVal234, setVal234, initVal234, HasTrivialCopyConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_default_constructor, getVal236, setVal236, initVal236, HasTrivialDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_destructor, getVal238, setVal238, initVal238, HasTrivialDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_destructor_for_call, getVal240, setVal240, initVal240, HasTrivialDestructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_assignment, getVal242, setVal242, initVal242, HasTrivialMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_constructor, getVal244, setVal244, initVal244, HasTrivialMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_trivial_move_constructor_for_call, getVal246, setVal246, initVal246, HasTrivialMoveConstructorForCall, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_uninitialized_reference_member, getVal248, setVal248, initVal248, HasUninitializedReferenceMember, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_constructor, getVal250, setVal250, initVal250, HasUserDeclaredConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_copy_assignment, getVal252, setVal252, initVal252, HasUserDeclaredCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_copy_constructor, getVal254, setVal254, initVal254, HasUserDeclaredCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_destructor, getVal256, setVal256, initVal256, HasUserDeclaredDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_assignment, getVal258, setVal258, initVal258, HasUserDeclaredMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_constructor, getVal260, setVal260, initVal260, HasUserDeclaredMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_declared_move_operation, getVal262, setVal262, initVal262, HasUserDeclaredMoveOperation, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_user_provided_default_constructor, getVal264, setVal264, initVal264, HasUserProvidedDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, has_variant_members, getVal266, setVal266, initVal266, HasVariantMembers, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, implicit_copy_assignment_has_const_parameter, getVal268, setVal268, initVal268, ImplicitCopyAssignmentHasConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, implicit_copy_constructor_has_const_parameter, getVal270, setVal270, initVal270, ImplicitCopyConstructorHasConstParameter, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_abstract, getVal272, setVal272, initVal272, IsAbstract, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_aggregate, getVal274, setVal274, initVal274, IsAggregate, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_any_destructor_no_return, getVal276, setVal276, initVal276, IsAnyDestructorNoReturn, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_c_like, getVal278, setVal278, initVal278, IsCLike, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_cxx11_standard_layout, getVal280, setVal280, initVal280, IsCXX11StandardLayout, bool, NthDecl)
  MX_VISIT_BOOL(CXXRecordDecl, is_dependent_lambda, getVal282, setVal282, initVal282, IsDependentLambda, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_dynamic_class, getVal283, setVal283, initVal283, IsDynamicClass, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_effectively_final, getVal285, setVal285, initVal285, IsEffectivelyFinal, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_empty, getVal287, setVal287, initVal287, IsEmpty, bool, NthDecl)
  MX_VISIT_BOOL(CXXRecordDecl, is_generic_lambda, getVal289, setVal289, initVal289, IsGenericLambda, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_interface_like, getVal290, setVal290, initVal290, IsInterfaceLike, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_literal, getVal292, setVal292, initVal292, IsLiteral, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(CXXRecordDecl, is_local_class, getVal126, setVal126, initVal126, IsLocalClass, FunctionDecl, NthDecl, DeclUseSelector::IS_LOCAL_CLASS)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_pod, getVal295, setVal295, initVal295, IsPOD, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_polymorphic, getVal297, setVal297, initVal297, IsPolymorphic, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_standard_layout, getVal299, setVal299, initVal299, IsStandardLayout, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_structural, getVal301, setVal301, initVal301, IsStructural, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_trivial, getVal303, setVal303, initVal303, IsTrivial, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, is_trivially_copyable, getVal305, setVal305, initVal305, IsTriviallyCopyable, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, lambda_is_default_constructible_and_assignable, getVal307, setVal307, initVal307, LambdaIsDefaultConstructibleAndAssignable, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, may_be_abstract, getVal309, setVal309, initVal309, MayBeAbstract, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, may_be_dynamic_class, getVal311, setVal311, initVal311, MayBeDynamicClass, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, may_be_non_dynamic_class, getVal313, setVal313, initVal313, MayBeNonDynamicClass, bool, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY_LIST(CXXRecordDecl, methods, getVal315, setVal315, initVal315, Methods, CXXMethodDecl, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_copy_assignment, getVal317, setVal317, initVal317, NeedsImplicitCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_copy_constructor, getVal319, setVal319, initVal319, NeedsImplicitCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_default_constructor, getVal321, setVal321, initVal321, NeedsImplicitDefaultConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_destructor, getVal323, setVal323, initVal323, NeedsImplicitDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_move_assignment, getVal325, setVal325, initVal325, NeedsImplicitMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_implicit_move_constructor, getVal327, setVal327, initVal327, NeedsImplicitMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_copy_assignment, getVal329, setVal329, initVal329, NeedsOverloadResolutionForCopyAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_copy_constructor, getVal331, setVal331, initVal331, NeedsOverloadResolutionForCopyConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_destructor, getVal333, setVal333, initVal333, NeedsOverloadResolutionForDestructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_move_assignment, getVal335, setVal335, initVal335, NeedsOverloadResolutionForMoveAssignment, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, needs_overload_resolution_for_move_constructor, getVal337, setVal337, initVal337, NeedsOverloadResolutionForMoveConstructor, bool, NthDecl)
  MX_VISIT_OPTIONAL_BOOL(CXXRecordDecl, null_field_offset_is_zero, getVal339, setVal339, initVal339, NullFieldOffsetIsZero, bool, NthDecl)
  MX_VISIT_OPTIONAL_PSEUDO_LIST(CXXRecordDecl, virtual_bases, getVal142, setVal142, initVal142, VirtualBases, CXXBaseSpecifier, NthDecl)
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
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, extern_token, getVal128, setVal128, initVal128, ExternToken, Token, NthDecl, TokenUseSelector::EXTERN_TOKEN)
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, point_of_instantiation, getVal129, setVal129, initVal129, PointOfInstantiation, Token, NthDecl, TokenUseSelector::POINT_OF_INSTANTIATION)
  MX_VISIT_ENUM(ClassTemplateSpecializationDecl, specialization_kind, getVal89, setVal89, initVal89, SpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_PSEUDO_LIST(ClassTemplateSpecializationDecl, template_arguments, getVal342, setVal342, initVal342, TemplateArguments, TemplateArgument, NthDecl)
  MX_VISIT_PSEUDO_LIST(ClassTemplateSpecializationDecl, template_instantiation_arguments, getVal343, setVal343, initVal343, TemplateInstantiationArguments, TemplateArgument, NthDecl)
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, template_keyword_token, getVal131, setVal131, initVal131, TemplateKeywordToken, Token, NthDecl, TokenUseSelector::TEMPLATE_KEYWORD_TOKEN)
  MX_VISIT_ENTITY(ClassTemplateSpecializationDecl, type_as_written, getVal132, setVal132, initVal132, TypeAsWritten, Type, NthDecl, TypeUseSelector::TYPE_AS_WRITTEN)
  MX_VISIT_BOOL(ClassTemplateSpecializationDecl, is_class_scope_explicit_specialization, getVal344, setVal344, initVal344, IsClassScopeExplicitSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(ClassTemplateSpecializationDecl, is_explicit_instantiation_or_specialization, getVal345, setVal345, initVal345, IsExplicitInstantiationOrSpecialization, bool, NthDecl)
  MX_VISIT_BOOL(ClassTemplateSpecializationDecl, is_explicit_specialization, getVal346, setVal346, initVal346, IsExplicitSpecialization, bool, NthDecl)
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
  MX_VISIT_ENTITY_LIST(EnumDecl, enumerators, getVal46, setVal46, initVal46, Enumerators, EnumConstantDecl, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(EnumDecl, instantiated_from_member_enum, getVal71, setVal71, initVal71, InstantiatedFromMemberEnum, EnumDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_ENUM)
  MX_VISIT_OPTIONAL_ENTITY(EnumDecl, integer_type, getVal74, setVal74, initVal74, IntegerType, Type, NthDecl, TypeUseSelector::INTEGER_TYPE)
  MX_VISIT_OPTIONAL_INT(EnumDecl, odr_hash, getVal143, setVal143, initVal143, ODRHash, unsigned, NthDecl)
  MX_VISIT_ENTITY(EnumDecl, promotion_type, getVal81, setVal81, initVal81, PromotionType, Type, NthDecl, TypeUseSelector::PROMOTION_TYPE)
  MX_VISIT_OPTIONAL_ENTITY(EnumDecl, template_instantiation_pattern, getVal86, setVal86, initVal86, TemplateInstantiationPattern, EnumDecl, NthDecl, DeclUseSelector::TEMPLATE_INSTANTIATION_PATTERN)
  MX_VISIT_ENUM(EnumDecl, template_specialization_kind, getVal80, setVal80, initVal80, TemplateSpecializationKind, TemplateSpecializationKind, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_closed, getVal103, setVal103, initVal103, IsClosed, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_closed_flag, getVal104, setVal104, initVal104, IsClosedFlag, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_closed_non_flag, getVal105, setVal105, initVal105, IsClosedNonFlag, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_complete, getVal106, setVal106, initVal106, IsComplete, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_fixed, getVal107, setVal107, initVal107, IsFixed, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_scoped, getVal108, setVal108, initVal108, IsScoped, bool, NthDecl)
  MX_VISIT_BOOL(EnumDecl, is_scoped_using_class_tag, getVal109, setVal109, initVal109, IsScopedUsingClassTag, bool, NthDecl)
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
  MX_VISIT_ENTITY(UnresolvedUsingTypenameDecl, ellipsis_token, getVal52, setVal52, initVal52, EllipsisToken, Token, NthDecl, TokenUseSelector::ELLIPSIS_TOKEN)
  MX_VISIT_ENTITY(UnresolvedUsingTypenameDecl, typename_token, getVal53, setVal53, initVal53, TypenameToken, Token, NthDecl, TokenUseSelector::TYPENAME_TOKEN)
  MX_VISIT_ENTITY(UnresolvedUsingTypenameDecl, using_token, getVal61, setVal61, initVal61, UsingToken, Token, NthDecl, TokenUseSelector::USING_TOKEN)
  MX_VISIT_BOOL(UnresolvedUsingTypenameDecl, is_pack_expansion, getVal69, setVal69, initVal69, IsPackExpansion, bool, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(TypedefNameDecl, anonymous_declaration_with_typedef_name, getVal52, setVal52, initVal52, AnonymousDeclarationWithTypedefName, TagDecl, NthDecl, DeclUseSelector::ANONYMOUS_DECLARATION_WITH_TYPEDEF_NAME)
  MX_VISIT_ENTITY(TypedefNameDecl, type, getVal53, setVal53, initVal53, TypeSourceInfo, Type, NthDecl, TypeUseSelector::TYPE)
  MX_VISIT_ENTITY(TypedefNameDecl, underlying_type, getVal61, setVal61, initVal61, UnderlyingType, Type, NthDecl, TypeUseSelector::UNDERLYING_TYPE)
  MX_VISIT_BOOL(TypedefNameDecl, is_moded, getVal70, setVal70, initVal70, IsModed, bool, NthDecl)
  MX_VISIT_BOOL(TypedefNameDecl, is_transparent_tag, getVal75, setVal75, initVal75, IsTransparentTag, bool, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(TypeAliasDecl, described_alias_template, getVal62, setVal62, initVal62, DescribedAliasTemplate, TypeAliasTemplateDecl, NthDecl, DeclUseSelector::DESCRIBED_ALIAS_TEMPLATE)
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
  MX_VISIT_ENTITY(ObjCTypeParamDecl, colon_token, getVal62, setVal62, initVal62, ColonToken, Token, NthDecl, TokenUseSelector::COLON_TOKEN)
  MX_VISIT_ENUM(ObjCTypeParamDecl, variance, getVal72, setVal72, initVal72, Variance, ObjCTypeParamVariance, NthDecl)
  MX_VISIT_ENTITY(ObjCTypeParamDecl, variance_token, getVal63, setVal63, initVal63, VarianceToken, Token, NthDecl, TokenUseSelector::VARIANCE_TOKEN)
  MX_VISIT_BOOL(ObjCTypeParamDecl, has_explicit_bound, getVal77, setVal77, initVal77, HasExplicitBound, bool, NthDecl)
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
  MX_VISIT_ENTITY(TypeAliasTemplateDecl, instantiated_from_member_template, getVal51, setVal51, initVal51, InstantiatedFromMemberTemplate, TypeAliasTemplateDecl, NthDecl, DeclUseSelector::INSTANTIATED_FROM_MEMBER_TEMPLATE)
  MX_VISIT_ENTITY(TypeAliasTemplateDecl, templated_declaration, getVal52, setVal52, initVal52, TemplatedDeclaration, TypeAliasDecl, NthDecl, DeclUseSelector::TEMPLATED_DECLARATION)
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
  MX_VISIT_ENTITY(ConceptDecl, constraint_expression, getVal51, setVal51, initVal51, ConstraintExpression, Expr, NthDecl, StmtUseSelector::CONSTRAINT_EXPRESSION)
  MX_VISIT_BOOL(ConceptDecl, is_type_concept, getVal68, setVal68, initVal68, IsTypeConcept, bool, NthDecl)
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
  MX_VISIT_ENTITY(ObjCPropertyDecl, at_token, getVal51, setVal51, initVal51, AtToken, Token, NthDecl, TokenUseSelector::AT_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyDecl, getter_method_declaration, getVal52, setVal52, initVal52, GetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::GETTER_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyDecl, getter_name_token, getVal53, setVal53, initVal53, GetterNameToken, Token, NthDecl, TokenUseSelector::GETTER_NAME_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyDecl, l_paren_token, getVal61, setVal61, initVal61, LParenToken, Token, NthDecl, TokenUseSelector::L_PAREN_TOKEN)
  MX_VISIT_ENUM(ObjCPropertyDecl, property_implementation, getVal72, setVal72, initVal72, PropertyImplementation, ObjCPropertyDeclPropertyControl, NthDecl)
  MX_VISIT_ENTITY(ObjCPropertyDecl, property_instance_variable_declaration, getVal62, setVal62, initVal62, PropertyInstanceVariableDeclaration, ObjCIvarDecl, NthDecl, DeclUseSelector::PROPERTY_INSTANCE_VARIABLE_DECLARATION)
  MX_VISIT_ENUM(ObjCPropertyDecl, query_kind, getVal80, setVal80, initVal80, QueryKind, ObjCPropertyQueryKind, NthDecl)
  MX_VISIT_ENUM(ObjCPropertyDecl, setter_kind, getVal82, setVal82, initVal82, SetterKind, ObjCPropertyDeclSetterKind, NthDecl)
  MX_VISIT_ENTITY(ObjCPropertyDecl, setter_method_declaration, getVal63, setVal63, initVal63, SetterMethodDeclaration, ObjCMethodDecl, NthDecl, DeclUseSelector::SETTER_METHOD_DECLARATION)
  MX_VISIT_ENTITY(ObjCPropertyDecl, setter_name_token, getVal71, setVal71, initVal71, SetterNameToken, Token, NthDecl, TokenUseSelector::SETTER_NAME_TOKEN)
  MX_VISIT_ENTITY(ObjCPropertyDecl, type, getVal74, setVal74, initVal74, Type, Type, NthDecl, TypeUseSelector::TYPE)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_atomic, getVal68, setVal68, initVal68, IsAtomic, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_class_property, getVal69, setVal69, initVal69, IsClassProperty, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_direct_property, getVal70, setVal70, initVal70, IsDirectProperty, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_instance_property, getVal75, setVal75, initVal75, IsInstanceProperty, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_optional, getVal77, setVal77, initVal77, IsOptional, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_read_only, getVal79, setVal79, initVal79, IsReadOnly, bool, NthDecl)
  MX_VISIT_BOOL(ObjCPropertyDecl, is_retaining, getVal87, setVal87, initVal87, IsRetaining, bool, NthDecl)
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
  MX_VISIT_BOOL(ObjCMethodDecl, defined_in_ns_object, getVal68, setVal68, initVal68, DefinedInNSObject, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCMethodDecl, find_property_declaration, getVal51, setVal51, initVal51, FindPropertyDeclaration, ObjCPropertyDecl, NthDecl, DeclUseSelector::FIND_PROPERTY_DECLARATION)
  MX_VISIT_ENTITY(ObjCMethodDecl, category, getVal52, setVal52, initVal52, Category, ObjCCategoryDecl, NthDecl, DeclUseSelector::CATEGORY)
  MX_VISIT_ENTITY(ObjCMethodDecl, class_interface, getVal53, setVal53, initVal53, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_VISIT_ENTITY(ObjCMethodDecl, command_declaration, getVal61, setVal61, initVal61, CommandDeclaration, ImplicitParamDecl, NthDecl, DeclUseSelector::COMMAND_DECLARATION)
  MX_VISIT_ENTITY(ObjCMethodDecl, declarator_end_token, getVal62, setVal62, initVal62, DeclaratorEndToken, Token, NthDecl, TokenUseSelector::DECLARATOR_END_TOKEN)
  MX_VISIT_ENUM(ObjCMethodDecl, implementation_control, getVal72, setVal72, initVal72, ImplementationControl, ObjCMethodDeclImplementationControl, NthDecl)
  MX_VISIT_ENUM(ObjCMethodDecl, method_family, getVal80, setVal80, initVal80, MethodFamily, ObjCMethodFamily, NthDecl)
  MX_VISIT_ENUM(ObjCMethodDecl, obj_c_decl_qualifier, getVal82, setVal82, initVal82, ObjCDeclQualifier, DeclObjCDeclQualifier, NthDecl)
  MX_VISIT_ENTITY(ObjCMethodDecl, return_type, getVal63, setVal63, initVal63, ReturnType, Type, NthDecl, TypeUseSelector::RETURN_TYPE)
  MX_VISIT_ENTITY(ObjCMethodDecl, selector_start_token, getVal76, setVal76, initVal76, SelectorStartToken, Token, NthDecl, TokenUseSelector::SELECTOR_START_TOKEN)
  MX_VISIT_ENTITY(ObjCMethodDecl, self_declaration, getVal78, setVal78, initVal78, SelfDeclaration, ImplicitParamDecl, NthDecl, DeclUseSelector::SELF_DECLARATION)
  MX_VISIT_BOOL(ObjCMethodDecl, has_redeclaration, getVal69, setVal69, initVal69, HasRedeclaration, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, has_related_result_type, getVal70, setVal70, initVal70, HasRelatedResultType, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, has_skipped_body, getVal75, setVal75, initVal75, HasSkippedBody, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_class_method, getVal77, setVal77, initVal77, IsClassMethod, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_defined, getVal79, setVal79, initVal79, IsDefined, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_designated_initializer_for_the_interface, getVal87, setVal87, initVal87, IsDesignatedInitializerForTheInterface, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_direct_method, getVal90, setVal90, initVal90, IsDirectMethod, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_instance_method, getVal91, setVal91, initVal91, IsInstanceMethod, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_optional, getVal92, setVal92, initVal92, IsOptional, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_overriding, getVal93, setVal93, initVal93, IsOverriding, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_property_accessor, getVal94, setVal94, initVal94, IsPropertyAccessor, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_redeclaration, getVal95, setVal95, initVal95, IsRedeclaration, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_synthesized_accessor_stub, getVal96, setVal96, initVal96, IsSynthesizedAccessorStub, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_definition, getVal97, setVal97, initVal97, IsThisDeclarationADefinition, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_this_declaration_a_designated_initializer, getVal98, setVal98, initVal98, IsThisDeclarationADesignatedInitializer, bool, NthDecl)
  MX_VISIT_BOOL(ObjCMethodDecl, is_variadic, getVal99, setVal99, initVal99, IsVariadic, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCMethodDecl, parameters, getVal45, setVal45, initVal45, Parameters, ParmVarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCMethodDecl, selector_tokens, getVal46, setVal46, initVal46, SelectorTokens, Token, NthDecl)
  MX_VISIT_DECL_CONTEXT(ObjCMethodDecl, declarations_in_context, getVal57, setVal57, initVal57, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, class_methods, getVal45, setVal45, initVal45, ClassMethods, ObjCMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, class_properties, getVal46, setVal46, initVal46, ClassProperties, ObjCPropertyDecl, NthDecl)
  MX_VISIT_ENTITY(ObjCContainerDecl, at_start_token, getVal53, setVal53, initVal53, AtStartToken, Token, NthDecl, TokenUseSelector::AT_START_TOKEN)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, instance_methods, getVal57, setVal57, initVal57, InstanceMethods, ObjCMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, instance_properties, getVal168, setVal168, initVal168, InstanceProperties, ObjCPropertyDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, methods, getVal177, setVal177, initVal177, Methods, ObjCMethodDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCContainerDecl, properties, getVal315, setVal315, initVal315, Properties, ObjCPropertyDecl, NthDecl)
  MX_VISIT_DECL_CONTEXT(ObjCContainerDecl, declarations_in_context, getVal347, setVal347, initVal347, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_BOOL(ObjCCategoryDecl, is_class_extension, getVal68, setVal68, initVal68, IsClassExtension, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCCategoryDecl, category_name_token, getVal61, setVal61, initVal61, CategoryNameToken, Token, NthDecl, TokenUseSelector::CATEGORY_NAME_TOKEN)
  MX_VISIT_ENTITY(ObjCCategoryDecl, class_interface, getVal62, setVal62, initVal62, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_VISIT_ENTITY(ObjCCategoryDecl, implementation, getVal63, setVal63, initVal63, Implementation, ObjCCategoryImplDecl, NthDecl, DeclUseSelector::IMPLEMENTATION)
  MX_VISIT_ENTITY(ObjCCategoryDecl, instance_variable_l_brace_token, getVal71, setVal71, initVal71, InstanceVariableLBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_L_BRACE_TOKEN)
  MX_VISIT_ENTITY(ObjCCategoryDecl, instance_variable_r_brace_token, getVal74, setVal74, initVal74, InstanceVariableRBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_R_BRACE_TOKEN)
  MX_VISIT_ENTITY(ObjCCategoryDecl, next_class_category, getVal76, setVal76, initVal76, NextClassCategory, ObjCCategoryDecl, NthDecl, DeclUseSelector::NEXT_CLASS_CATEGORY)
  MX_VISIT_ENTITY_LIST(ObjCCategoryDecl, instance_variables, getVal348, setVal348, initVal348, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCCategoryDecl, protocol_tokens, getVal349, setVal349, initVal349, ProtocolTokens, Token, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCCategoryDecl, protocols, getVal350, setVal350, initVal350, Protocols, ObjCProtocolDecl, NthDecl)
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
  MX_VISIT_TEXT(ObjCProtocolDecl, obj_c_runtime_name_as_string, getVal67, setVal67, initVal67, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_VISIT_BOOL(ObjCProtocolDecl, has_definition, getVal68, setVal68, initVal68, HasDefinition, bool, NthDecl)
  MX_VISIT_BOOL(ObjCProtocolDecl, is_non_runtime_protocol, getVal69, setVal69, initVal69, IsNonRuntimeProtocol, bool, NthDecl)
  MX_VISIT_BOOL(ObjCProtocolDecl, is_definition, getVal70, setVal70, initVal70, IsThisDeclarationADefinition, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCProtocolDecl, protocol_tokens, getVal348, setVal348, initVal348, ProtocolTokens, Token, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCProtocolDecl, protocols, getVal349, setVal349, initVal349, Protocols, ObjCProtocolDecl, NthDecl)
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
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, all_referenced_protocols, getVal348, setVal348, initVal348, AllReferencedProtocols, ObjCProtocolDecl, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, declares_or_inherits_designated_initializers, getVal68, setVal68, initVal68, DeclaresOrInheritsDesignatedInitializers, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, end_of_definition_token, getVal61, setVal61, initVal61, EndOfDefinitionToken, Token, NthDecl, TokenUseSelector::END_OF_DEFINITION_TOKEN)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, implementation, getVal62, setVal62, initVal62, Implementation, ObjCImplementationDecl, NthDecl, DeclUseSelector::IMPLEMENTATION)
  MX_VISIT_TEXT(ObjCInterfaceDecl, obj_c_runtime_name_as_string, getVal67, setVal67, initVal67, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_VISIT_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class, getVal63, setVal63, initVal63, SuperClass, ObjCInterfaceDecl, NthDecl, DeclUseSelector::SUPER_CLASS)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, super_class_token, getVal71, setVal71, initVal71, SuperClassToken, Token, NthDecl, TokenUseSelector::SUPER_CLASS_TOKEN)
  MX_VISIT_OPTIONAL_ENTITY(ObjCInterfaceDecl, super_class_type, getVal74, setVal74, initVal74, SuperClassTypeInfo, Type, NthDecl, TypeUseSelector::SUPER_CLASS_TYPE)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, type_for_declaration, getVal76, setVal76, initVal76, TypeForDeclaration, Type, NthDecl, TypeUseSelector::TYPE_FOR_DECLARATION)
  MX_VISIT_BOOL(ObjCInterfaceDecl, has_definition, getVal75, setVal75, initVal75, HasDefinition, bool, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, has_designated_initializers, getVal77, setVal77, initVal77, HasDesignatedInitializers, bool, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, is_arc_weakref_unavailable, getVal79, setVal79, initVal79, IsArcWeakrefUnavailable, bool, NthDecl)
  MX_VISIT_BOOL(ObjCInterfaceDecl, is_implicit_interface_declaration, getVal87, setVal87, initVal87, IsImplicitInterfaceDeclaration, bool, NthDecl)
  MX_VISIT_ENTITY(ObjCInterfaceDecl, is_obj_c_requires_property_definitions, getVal78, setVal78, initVal78, IsObjCRequiresPropertyDefinitions, ObjCInterfaceDecl, NthDecl, DeclUseSelector::IS_OBJ_C_REQUIRES_PROPERTY_DEFINITIONS)
  MX_VISIT_BOOL(ObjCInterfaceDecl, is_definition, getVal90, setVal90, initVal90, IsThisDeclarationADefinition, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, instance_variables, getVal349, setVal349, initVal349, InstanceVariables, ObjCIvarDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, known_categories, getVal350, setVal350, initVal350, KnownCategories, ObjCCategoryDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, known_extensions, getVal351, setVal351, initVal351, KnownExtensions, ObjCCategoryDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, protocol_tokens, getVal352, setVal352, initVal352, ProtocolTokens, Token, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, protocols, getVal353, setVal353, initVal353, Protocols, ObjCProtocolDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, visible_categories, getVal354, setVal354, initVal354, VisibleCategories, ObjCCategoryDecl, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCInterfaceDecl, visible_extensions, getVal355, setVal355, initVal355, VisibleExtensions, ObjCCategoryDecl, NthDecl)
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
  MX_VISIT_ENTITY(ObjCImplDecl, class_interface, getVal61, setVal61, initVal61, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
  MX_VISIT_ENTITY_LIST(ObjCImplDecl, property_implementations, getVal348, setVal348, initVal348, PropertyImplementations, ObjCPropertyImplDecl, NthDecl)
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
  MX_VISIT_ENTITY(ObjCCategoryImplDecl, category_declaration, getVal62, setVal62, initVal62, CategoryDeclaration, ObjCCategoryDecl, NthDecl, DeclUseSelector::CATEGORY_DECLARATION)
  MX_VISIT_ENTITY(ObjCCategoryImplDecl, category_name_token, getVal63, setVal63, initVal63, CategoryNameToken, Token, NthDecl, TokenUseSelector::CATEGORY_NAME_TOKEN)
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
  MX_VISIT_ENTITY(ObjCImplementationDecl, instance_variable_l_brace_token, getVal62, setVal62, initVal62, InstanceVariableLBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_L_BRACE_TOKEN)
  MX_VISIT_ENTITY(ObjCImplementationDecl, instance_variable_r_brace_token, getVal63, setVal63, initVal63, InstanceVariableRBraceToken, Token, NthDecl, TokenUseSelector::INSTANCE_VARIABLE_R_BRACE_TOKEN)
  MX_VISIT_TEXT(ObjCImplementationDecl, obj_c_runtime_name_as_string, getVal67, setVal67, initVal67, ObjCRuntimeNameAsString, basic_string_view, NthDecl)
  MX_VISIT_ENTITY(ObjCImplementationDecl, super_class, getVal71, setVal71, initVal71, SuperClass, ObjCInterfaceDecl, NthDecl, DeclUseSelector::SUPER_CLASS)
  MX_VISIT_ENTITY(ObjCImplementationDecl, super_class_token, getVal74, setVal74, initVal74, SuperClassToken, Token, NthDecl, TokenUseSelector::SUPER_CLASS_TOKEN)
  MX_VISIT_BOOL(ObjCImplementationDecl, has_destructors, getVal68, setVal68, initVal68, HasDestructors, bool, NthDecl)
  MX_VISIT_BOOL(ObjCImplementationDecl, has_non_zero_constructors, getVal69, setVal69, initVal69, HasNonZeroConstructors, bool, NthDecl)
  MX_VISIT_ENTITY_LIST(ObjCImplementationDecl, instance_variables, getVal349, setVal349, initVal349, InstanceVariables, ObjCIvarDecl, NthDecl)
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
  MX_VISIT_ENTITY(ObjCCompatibleAliasDecl, class_interface, getVal51, setVal51, initVal51, ClassInterface, ObjCInterfaceDecl, NthDecl, DeclUseSelector::CLASS_INTERFACE)
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
  MX_VISIT_DECL_CONTEXT(NamespaceDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY(NamespaceAliasDecl, alias_token, getVal51, setVal51, initVal51, AliasToken, Token, NthDecl, TokenUseSelector::ALIAS_TOKEN)
  MX_VISIT_ENTITY(NamespaceAliasDecl, aliased_namespace, getVal52, setVal52, initVal52, AliasedNamespace, NamedDecl, NthDecl, DeclUseSelector::ALIASED_NAMESPACE)
  MX_VISIT_ENTITY(NamespaceAliasDecl, namespace_token, getVal53, setVal53, initVal53, NamespaceToken, Token, NthDecl, TokenUseSelector::NAMESPACE_TOKEN)
  MX_VISIT_ENTITY(NamespaceAliasDecl, target_name_token, getVal61, setVal61, initVal61, TargetNameToken, Token, NthDecl, TokenUseSelector::TARGET_NAME_TOKEN)
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
  MX_VISIT_DECL_CONTEXT(LinkageSpecDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY_LIST(LifetimeExtendedTemporaryDecl, children_expression, getVal45, setVal45, initVal45, ChildrenExpression, Stmt, NthDecl)
  MX_VISIT_ENTITY(LifetimeExtendedTemporaryDecl, extending_declaration, getVal43, setVal43, initVal43, ExtendingDeclaration, ValueDecl, NthDecl, DeclUseSelector::EXTENDING_DECLARATION)
  MX_VISIT_ENUM(LifetimeExtendedTemporaryDecl, storage_duration, getVal60, setVal60, initVal60, StorageDuration, StorageDuration, NthDecl)
  MX_VISIT_ENTITY(LifetimeExtendedTemporaryDecl, temporary_expression, getVal51, setVal51, initVal51, TemporaryExpression, Expr, NthDecl, StmtUseSelector::TEMPORARY_EXPRESSION)
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
  MX_VISIT_ENTITY_LIST(ImportDecl, identifier_tokens, getVal45, setVal45, initVal45, IdentifierTokens, Token, NthDecl)
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
  MX_VISIT_OPTIONAL_ENTITY(FriendDecl, friend_declaration, getVal43, setVal43, initVal43, FriendDeclaration, NamedDecl, NthDecl, DeclUseSelector::FRIEND_DECLARATION)
  MX_VISIT_ENTITY(FriendDecl, friend_token, getVal51, setVal51, initVal51, FriendToken, Token, NthDecl, TokenUseSelector::FRIEND_TOKEN)
  MX_VISIT_ENTITY(FriendDecl, friend_type, getVal52, setVal52, initVal52, FriendType, Type, NthDecl, TypeUseSelector::FRIEND_TYPE)
  MX_VISIT_BOOL(FriendDecl, is_unsupported_friend, getVal47, setVal47, initVal47, IsUnsupportedFriend, bool, NthDecl)
  MX_VISIT_PSEUDO_LIST(FriendDecl, friend_type_template_parameter_lists, getVal73, setVal73, initVal73, FriendTypeTemplateParameterLists, TemplateParameterList, NthDecl)
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
  MX_VISIT_ENTITY(FileScopeAsmDecl, assembly_token, getVal43, setVal43, initVal43, AssemblyToken, Token, NthDecl, TokenUseSelector::ASSEMBLY_TOKEN)
  MX_VISIT_ENTITY(FileScopeAsmDecl, assembly_string, getVal51, setVal51, initVal51, AssemblyString, StringLiteral, NthDecl, StmtUseSelector::ASSEMBLY_STRING)
  MX_VISIT_ENTITY(FileScopeAsmDecl, r_paren_token, getVal52, setVal52, initVal52, RParenToken, Token, NthDecl, TokenUseSelector::R_PAREN_TOKEN)
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
  MX_VISIT_DECL_CONTEXT(ExternCContextDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
  MX_VISIT_ENTITY(ExportDecl, export_token, getVal43, setVal43, initVal43, ExportToken, Token, NthDecl, TokenUseSelector::EXPORT_TOKEN)
  MX_VISIT_ENTITY(ExportDecl, r_brace_token, getVal51, setVal51, initVal51, RBraceToken, Token, NthDecl, TokenUseSelector::R_BRACE_TOKEN)
  MX_VISIT_BOOL(ExportDecl, has_braces, getVal44, setVal44, initVal44, HasBraces, bool, NthDecl)
  MX_VISIT_DECL_CONTEXT(ExportDecl, declarations_in_context, getVal45, setVal45, initVal45, AlreadyLoadedDeclarations, Decl, NthDecl)
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
#undef MX_ENTER_VISIT_ExtIntType
#undef MX_EXIT_VISIT_ExtIntType
#undef MX_ENTER_VISIT_DependentVectorType
#undef MX_EXIT_VISIT_DependentVectorType
#undef MX_ENTER_VISIT_DependentSizedExtVectorType
#undef MX_EXIT_VISIT_DependentSizedExtVectorType
#undef MX_ENTER_VISIT_DependentExtIntType
#undef MX_EXIT_VISIT_DependentExtIntType
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
#undef MX_ENTER_VISIT_OMPMasterDirective
#undef MX_EXIT_VISIT_OMPMasterDirective
#undef MX_ENTER_VISIT_OMPMaskedDirective
#undef MX_EXIT_VISIT_OMPMaskedDirective
#undef MX_ENTER_VISIT_OMPLoopBasedDirective
#undef MX_EXIT_VISIT_OMPLoopBasedDirective
#undef MX_ENTER_VISIT_OMPUnrollDirective
#undef MX_EXIT_VISIT_OMPUnrollDirective
#undef MX_ENTER_VISIT_OMPTileDirective
#undef MX_EXIT_VISIT_OMPTileDirective
#undef MX_ENTER_VISIT_OMPLoopDirective
#undef MX_EXIT_VISIT_OMPLoopDirective
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
