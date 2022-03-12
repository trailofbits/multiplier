# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

# Auto-generated file; do not modify!

@0xa04be7b45e95b659;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("mx::ast");

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
  keywordUcImage1dUcT @298 $Cxx.name("keyword_image1d_t");
  keywordUcImage1dUcArrayUcT @299 $Cxx.name("keyword_image1d_array_t");
  keywordUcImage1dUcBufferUcT @300 $Cxx.name("keyword_image1d_buffer_t");
  keywordUcImage2dUcT @301 $Cxx.name("keyword_image2d_t");
  keywordUcImage2dUcArrayUcT @302 $Cxx.name("keyword_image2d_array_t");
  keywordUcImage2dUcDepthUcT @303 $Cxx.name("keyword_image2d_depth_t");
  keywordUcImage2dUcArrayUcDepthUcT @304 $Cxx.name("keyword_image2d_array_depth_t");
  keywordUcImage2dUcMsaaUcT @305 $Cxx.name("keyword_image2d_msaa_t");
  keywordUcImage2dUcArrayUcMsaaUcT @306 $Cxx.name("keyword_image2d_array_msaa_t");
  keywordUcImage2dUcMsaaUcDepthUcT @307 $Cxx.name("keyword_image2d_msaa_depth_t");
  keywordUcImage2dUcArrayUcMsaaUcDepthUcT @308 $Cxx.name("keyword_image2d_array_msaa_depth_t");
  keywordUcImage3dUcT @309 $Cxx.name("keyword_image3d_t");
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
  numEnumerators @389 $Cxx.name("num_enumerators");
}

enum TokenRole @0x9951b825ce993408 {
  invalid @0 $Cxx.name("invalid");
  beginUcOfUcFileUcMarker @1 $Cxx.name("begin_of_file_marker");
  fileUcToken @2 $Cxx.name("file_token");
  endUcOfUcFileUcMarker @3 $Cxx.name("end_of_file_marker");
  beginUcOfUcMacroUcExpansionUcMarker @4 $Cxx.name("begin_of_macro_expansion_marker");
  macroUcExpansionUcToken @5 $Cxx.name("macro_expansion_token");
  endUcOfUcMacroUcExpansionUcMarker @6 $Cxx.name("end_of_macro_expansion_marker");
  printedUcToken @7 $Cxx.name("printed_token");
  numEnumerators @8 $Cxx.name("num_enumerators");
}

enum AccessSpecifier @0xea31fabcef869ac6 {
  public @0 $Cxx.name("public");
  protected @1 $Cxx.name("protected");
  private @2 $Cxx.name("private");
  none @3 $Cxx.name("none");
  numEnumerators @4 $Cxx.name("num_enumerators");
}

enum AvailabilityResult @0xe8c6cd388f86c217 {
  available @0 $Cxx.name("available");
  notUcYetUcIntroduced @1 $Cxx.name("not_yet_introduced");
  deprecated @2 $Cxx.name("deprecated");
  unavailable @3 $Cxx.name("unavailable");
  numEnumerators @4 $Cxx.name("num_enumerators");
}

enum FriendObjectKind @0xc74745b68a910aa9 {
  none @0 $Cxx.name("none");
  declared @1 $Cxx.name("declared");
  undeclared @2 $Cxx.name("undeclared");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ModuleOwnershipKind @0x94f1123366f439d2 {
  unowned @0 $Cxx.name("unowned");
  visible @1 $Cxx.name("visible");
  visibleUcWhenUcImported @2 $Cxx.name("visible_when_imported");
  moduleUcPrivate @3 $Cxx.name("module_private");
  numEnumerators @4 $Cxx.name("num_enumerators");
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
  numEnumerators @94 $Cxx.name("num_enumerators");
}

enum PragmaMSCommentKind @0xe09b297844ff08bb {
  unknown @0 $Cxx.name("unknown");
  linker @1 $Cxx.name("linker");
  lib @2 $Cxx.name("lib");
  compiler @3 $Cxx.name("compiler");
  exeUcString @4 $Cxx.name("exe_string");
  user @5 $Cxx.name("user");
  numEnumerators @6 $Cxx.name("num_enumerators");
}

enum Linkage @0xd7f90485cbd67b8c {
  noUcLinkage @0 $Cxx.name("no_linkage");
  internalUcLinkage @1 $Cxx.name("internal_linkage");
  uniqueUcExternalUcLinkage @2 $Cxx.name("unique_external_linkage");
  visibleUcNoUcLinkage @3 $Cxx.name("visible_no_linkage");
  moduleUcInternalUcLinkage @4 $Cxx.name("module_internal_linkage");
  moduleUcLinkage @5 $Cxx.name("module_linkage");
  externalUcLinkage @6 $Cxx.name("external_linkage");
  numEnumerators @7 $Cxx.name("num_enumerators");
}

enum ObjCStringFormatFamily @0xdde65f902899f0f0 {
  none @0 $Cxx.name("none");
  nsUcString @1 $Cxx.name("ns_string");
  cfUcString @2 $Cxx.name("cf_string");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum Visibility @0x9f55e79df4f9996e {
  hiddenUcVisibility @0 $Cxx.name("hidden_visibility");
  protectedUcVisibility @1 $Cxx.name("protected_visibility");
  defaultUcVisibility @2 $Cxx.name("default_visibility");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum LanguageLinkage @0xa1e45a6941f17018 {
  cUcLanguageUcLinkage @0 $Cxx.name("c_language_linkage");
  cxxUcLanguageUcLinkage @1 $Cxx.name("cxx_language_linkage");
  noUcLanguageUcLinkage @2 $Cxx.name("no_language_linkage");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum StorageClass @0xda0542391be3aa63 {
  none @0 $Cxx.name("none");
  extern @1 $Cxx.name("extern");
  static @2 $Cxx.name("static");
  privateUcExtern @3 $Cxx.name("private_extern");
  auto @4 $Cxx.name("auto");
  register @5 $Cxx.name("register");
  numEnumerators @6 $Cxx.name("num_enumerators");
}

enum StorageDuration @0xe1a5462cfd90bc60 {
  fullUcExpression @0 $Cxx.name("full_expression");
  automatic @1 $Cxx.name("automatic");
  thread @2 $Cxx.name("thread");
  static @3 $Cxx.name("static");
  dynamic @4 $Cxx.name("dynamic");
  numEnumerators @5 $Cxx.name("num_enumerators");
}

enum ThreadStorageClassSpecifier @0xa5e43d0340490a97 {
  unspecified @0 $Cxx.name("unspecified");
  ucUcThread @1 $Cxx.name("__thread");
  threadUcLocal @2 $Cxx.name("thread_local");
  ucThreadUcLocal @3 $Cxx.name("_thread_local");
  numEnumerators @4 $Cxx.name("num_enumerators");
}

enum TemplateSpecializationKind @0xc45c2bfe2b2d2105 {
  undeclared @0 $Cxx.name("undeclared");
  implicitUcInstantiation @1 $Cxx.name("implicit_instantiation");
  explicitUcSpecialization @2 $Cxx.name("explicit_specialization");
  explicitUcInstantiationUcDeclaration @3 $Cxx.name("explicit_instantiation_declaration");
  explicitUcInstantiationUcDefinition @4 $Cxx.name("explicit_instantiation_definition");
  numEnumerators @5 $Cxx.name("num_enumerators");
}

enum ImplicitParamKind @0xab95d72fdf3ce08d {
  objUcCUcSelf @0 $Cxx.name("obj_c_self");
  objUcCUcCmd @1 $Cxx.name("obj_c_cmd");
  cxxUcThis @2 $Cxx.name("cxx_this");
  cxxvtt @3 $Cxx.name("cxxvtt");
  capturedUcContext @4 $Cxx.name("captured_context");
  other @5 $Cxx.name("other");
  numEnumerators @6 $Cxx.name("num_enumerators");
}

enum ConstexprSpecKind @0x9b968674fb4c29be {
  unspecified @0 $Cxx.name("unspecified");
  constexpr @1 $Cxx.name("constexpr");
  consteval @2 $Cxx.name("consteval");
  constinit @3 $Cxx.name("constinit");
  numEnumerators @4 $Cxx.name("num_enumerators");
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
  numEnumerators @12 $Cxx.name("num_enumerators");
}

enum MultiVersionKind @0xd6aa1ba55a8d79af {
  none @0 $Cxx.name("none");
  target @1 $Cxx.name("target");
  cpuUcSpecific @2 $Cxx.name("cpu_specific");
  cpuUcDispatch @3 $Cxx.name("cpu_dispatch");
  numEnumerators @4 $Cxx.name("num_enumerators");
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
  numEnumerators @46 $Cxx.name("num_enumerators");
}

enum RefQualifierKind @0xe49bd7951a6ae539 {
  none @0 $Cxx.name("none");
  lUcValue @1 $Cxx.name("l_value");
  rUcValue @2 $Cxx.name("r_value");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum InClassInitStyle @0xfd30164f4a13d25c {
  noUcInitializer @0 $Cxx.name("no_initializer");
  copyUcInitializer @1 $Cxx.name("copy_initializer");
  listUcInitializer @2 $Cxx.name("list_initializer");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum TagTypeKind @0xbfa845fcdbd00864 {
  struct @0 $Cxx.name("struct");
  interface @1 $Cxx.name("interface");
  union @2 $Cxx.name("union");
  class @3 $Cxx.name("class");
  enum @4 $Cxx.name("enum");
  numEnumerators @5 $Cxx.name("num_enumerators");
}

enum ArgPassingKind @0xfc581c2eded85fa9 {
  canUcPassUcInUcRegs @0 $Cxx.name("can_pass_in_regs");
  cannotUcPassUcInUcRegs @1 $Cxx.name("cannot_pass_in_regs");
  canUcNeverUcPassUcInUcRegs @2 $Cxx.name("can_never_pass_in_regs");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum MSInheritanceModel @0x9e63c392cec08405 {
  single @0 $Cxx.name("single");
  multiple @1 $Cxx.name("multiple");
  virtual @2 $Cxx.name("virtual");
  unspecified @3 $Cxx.name("unspecified");
  numEnumerators @4 $Cxx.name("num_enumerators");
}

enum LambdaCaptureDefault @0xc5ffb9f76dbfab4d {
  none @0 $Cxx.name("none");
  byUcCopy @1 $Cxx.name("by_copy");
  byUcReference @2 $Cxx.name("by_reference");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum MSVtorDispMode @0xd30e950dab28014f {
  never @0 $Cxx.name("never");
  forUcVirtualUcBaseUcOverride @1 $Cxx.name("for_virtual_base_override");
  forUcVfUcTable @2 $Cxx.name("for_vf_table");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ObjCTypeParamVariance @0x922a77f8ad69d2ca {
  invariant @0 $Cxx.name("invariant");
  covariant @1 $Cxx.name("covariant");
  contravariant @2 $Cxx.name("contravariant");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum PropertyControl @0x80dbe303a4591128 {
  none @0 $Cxx.name("none");
  required @1 $Cxx.name("required");
  optional @2 $Cxx.name("optional");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ObjCPropertyQueryKind @0xa276e57d28cfccfe {
  queryUcUnknown @0 $Cxx.name("query_unknown");
  queryUcInstance @1 $Cxx.name("query_instance");
  queryUcClass @2 $Cxx.name("query_class");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum SetterKind @0x9b24373b205d21f4 {
  assign @0 $Cxx.name("assign");
  retain @1 $Cxx.name("retain");
  copy @2 $Cxx.name("copy");
  weak @3 $Cxx.name("weak");
  numEnumerators @4 $Cxx.name("num_enumerators");
}

enum ImplementationControl @0x8d100537007bc5a0 {
  none @0 $Cxx.name("none");
  required @1 $Cxx.name("required");
  optional @2 $Cxx.name("optional");
  numEnumerators @3 $Cxx.name("num_enumerators");
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
  numEnumerators @15 $Cxx.name("num_enumerators");
}

enum LanguageIDs @0xe48de286671b0833 {
  c @0 $Cxx.name("c");
  cxx @1 $Cxx.name("cxx");
  numEnumerators @2 $Cxx.name("num_enumerators");
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
  numEnumerators @220 $Cxx.name("num_enumerators");
}

enum CapturedRegionKind @0x9c1102e218ed4271 {
  default @0 $Cxx.name("default");
  objUcCUcAtUcFinally @1 $Cxx.name("obj_c_at_finally");
  openUcMp @2 $Cxx.name("open_mp");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ExprObjectKind @0xf9211f9356023995 {
  ordinary @0 $Cxx.name("ordinary");
  bitUcField @1 $Cxx.name("bit_field");
  vectorUcComponent @2 $Cxx.name("vector_component");
  objUcCUcProperty @3 $Cxx.name("obj_c_property");
  objUcCUcSubscript @4 $Cxx.name("obj_c_subscript");
  matrixUcComponent @5 $Cxx.name("matrix_component");
  numEnumerators @6 $Cxx.name("num_enumerators");
}

enum ExprValueKind @0xb10e40f0a807354a {
  prUcValue @0 $Cxx.name("pr_value");
  lUcValue @1 $Cxx.name("l_value");
  xUcValue @2 $Cxx.name("x_value");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum NonOdrUseReason @0xbc90b6da0c76be85 {
  none @0 $Cxx.name("none");
  unevaluated @1 $Cxx.name("unevaluated");
  constant @2 $Cxx.name("constant");
  discarded @3 $Cxx.name("discarded");
  numEnumerators @4 $Cxx.name("num_enumerators");
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
  numEnumerators @65 $Cxx.name("num_enumerators");
}

enum ObjCBridgeCastKind @0xfe79ee651274349f {
  bridge @0 $Cxx.name("bridge");
  bridgeUcTransfer @1 $Cxx.name("bridge_transfer");
  bridgeUcRetained @2 $Cxx.name("bridge_retained");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ADLCallKind @0xc8253fdf892ab117 {
  notUcAdl @0 $Cxx.name("not_adl");
  usesUcAdl @1 $Cxx.name("uses_adl");
  numEnumerators @2 $Cxx.name("num_enumerators");
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
  numEnumerators @33 $Cxx.name("num_enumerators");
}

enum InitializationStyle @0x8ec30c1abc0c19a6 {
  cUcInit @0 $Cxx.name("c_init");
  callUcInitializer @1 $Cxx.name("call_initializer");
  listUcInitializer @2 $Cxx.name("list_initializer");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ConstructionKind @0xda989eff233a33e2 {
  complete @0 $Cxx.name("complete");
  nonUcVirtualUcBase @1 $Cxx.name("non_virtual_base");
  virtualUcBase @2 $Cxx.name("virtual_base");
  delegating @3 $Cxx.name("delegating");
  numEnumerators @4 $Cxx.name("num_enumerators");
}

enum ArrayTypeTrait @0xd6960ffdc6f9f29f {
  arrayUcRank @0 $Cxx.name("array_rank");
  arrayUcExtent @1 $Cxx.name("array_extent");
  numEnumerators @2 $Cxx.name("num_enumerators");
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
  numEnumerators @14 $Cxx.name("num_enumerators");
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
  numEnumerators @64 $Cxx.name("num_enumerators");
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
  numEnumerators @14 $Cxx.name("num_enumerators");
}

enum ResultStorageKind @0xbb78b2b258534591 {
  none @0 $Cxx.name("none");
  int64 @1 $Cxx.name("int64");
  apUcValue @2 $Cxx.name("ap_value");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum ExpressionTrait @0xc0206beabf974c92 {
  isUcLUcValueUcExpression @0 $Cxx.name("is_l_value_expression");
  isUcRUcValueUcExpression @1 $Cxx.name("is_r_value_expression");
  numEnumerators @2 $Cxx.name("num_enumerators");
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
  numEnumerators @8 $Cxx.name("num_enumerators");
}

enum ObjCLifetime @0xa408eab661edd8cd {
  none @0 $Cxx.name("none");
  explicitUcNone @1 $Cxx.name("explicit_none");
  strong @2 $Cxx.name("strong");
  weak @3 $Cxx.name("weak");
  autoreleasing @4 $Cxx.name("autoreleasing");
  numEnumerators @5 $Cxx.name("num_enumerators");
}

enum ScalarTypeKind @0xdacaafd6791835aa {
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
  numEnumerators @10 $Cxx.name("num_enumerators");
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
  numEnumerators @52 $Cxx.name("num_enumerators");
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
  numEnumerators @19 $Cxx.name("num_enumerators");
}

enum PrimitiveCopyKind @0xd987c4779543007c {
  trivial @0 $Cxx.name("trivial");
  volatileUcTrivial @1 $Cxx.name("volatile_trivial");
  arcUcStrong @2 $Cxx.name("arc_strong");
  arcUcWeak @3 $Cxx.name("arc_weak");
  struct @4 $Cxx.name("struct");
  numEnumerators @5 $Cxx.name("num_enumerators");
}

enum PrimitiveDefaultInitializeKind @0x8939975a5b04dbb3 {
  trivial @0 $Cxx.name("trivial");
  arcUcStrong @1 $Cxx.name("arc_strong");
  arcUcWeak @2 $Cxx.name("arc_weak");
  struct @3 $Cxx.name("struct");
  numEnumerators @4 $Cxx.name("num_enumerators");
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
  numEnumerators @19 $Cxx.name("num_enumerators");
}

enum CanThrowResult @0xade719c14c0fa1a7 {
  cannot @0 $Cxx.name("cannot");
  dependent @1 $Cxx.name("dependent");
  can @2 $Cxx.name("can");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum VectorKind @0xa2946b86ad43cc82 {
  genericUcVector @0 $Cxx.name("generic_vector");
  altiUcVecUcVector @1 $Cxx.name("alti_vec_vector");
  altiUcVecUcPixel @2 $Cxx.name("alti_vec_pixel");
  altiUcVecUcBoolean @3 $Cxx.name("alti_vec_boolean");
  neonUcVector @4 $Cxx.name("neon_vector");
  neonUcPolyUcVector @5 $Cxx.name("neon_poly_vector");
  sveUcFixedUcLengthUcDataUcVector @6 $Cxx.name("sve_fixed_length_data_vector");
  sveUcFixedUcLengthUcPredicateUcVector @7 $Cxx.name("sve_fixed_length_predicate_vector");
  numEnumerators @8 $Cxx.name("num_enumerators");
}

enum AutoTypeKeyword @0x8f3df89531320c02 {
  auto @0 $Cxx.name("auto");
  decltypeUcAuto @1 $Cxx.name("decltype_auto");
  gnuUcAutoUcType @2 $Cxx.name("gnu_auto_type");
  numEnumerators @3 $Cxx.name("num_enumerators");
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
  alignUcMac68k @73 $Cxx.name("align_mac68k");
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
  cxx11UcNoUcReturn @115 $Cxx.name("cxx11_no_return");
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
  m68kUcInterrupt @168 $Cxx.name("m68k_interrupt");
  migUcServerUcRoutine @169 $Cxx.name("mig_server_routine");
  msUcAllocator @170 $Cxx.name("ms_allocator");
  msUcInheritance @171 $Cxx.name("ms_inheritance");
  msUcNoUcVUcTable @172 $Cxx.name("ms_no_v_table");
  msp430UcInterrupt @173 $Cxx.name("msp430_interrupt");
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
  numEnumerators @341 $Cxx.name("num_enumerators");
}

enum ArraySizeModifier @0xf6f70035a2bc22f6 {
  normal @0 $Cxx.name("normal");
  static @1 $Cxx.name("static");
  star @2 $Cxx.name("star");
  numEnumerators @3 $Cxx.name("num_enumerators");
}

enum UTTKind @0xe3ac3858dbe51a16 {
  enumUcUnderlyingUcType @0 $Cxx.name("enum_underlying_type");
  numEnumerators @1 $Cxx.name("num_enumerators");
}

struct TokenOffset @0x8a47d77b57b46cd5 {
  offset @0 :UInt32 $Cxx.name("offset");
}

struct TokenRange @0xfaaa666ba10b6696 {
  beginOffset @0 :UInt32 $Cxx.name("begin_offset");
  endOffset @1 :UInt32 $Cxx.name("end_offset");  # Inclusive.
}

struct Token @0xdf7bccc629d6dcf9 {
  data @0 :Text;
  kind @1 :TokenKind;
  role @2 :TokenRole;
  macroUcExpandedUcTokens @3 :TokenRange;
}

struct Decl @0xfb5879761ffaedb6 {
  access @0 :AccessSpecifier;
  accessUcUnsafe @1 :AccessSpecifier;
  availability @2 :AvailabilityResult;
  beginUcToken @3 :TokenOffset;
  bodyUcRUcBrace @4 :TokenOffset;
  endUcToken @5 :TokenOffset;
  friendUcObjectUcKind @6 :FriendObjectKind;
  moduleUcOwnershipUcKind @7 :ModuleOwnershipKind;
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
  token @39 :TokenOffset;
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
  caretUcToken @5 :TokenOffset;
  hasUcCaptures @6 :Bool;
  isUcConversionUcFromUcLambda @7 :Bool;
  isUcVariadic @8 :Bool;
}

struct AccessSpecDecl @0xe671324616f83d3c {
  decl @0:Decl;
  accessUcSpecifierUcToken @1 :TokenOffset;
  colonUcToken @2 :TokenOffset;
}

struct TranslationUnitDecl @0x84ba694d5be7caa3 {
  decl @0:Decl;
}

struct StaticAssertDecl @0xe3ab98945466226a {
  decl @0:Decl;
  rUcParenUcToken @1 :TokenOffset;
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
  propertyUcInstanceUcVariableUcDeclarationUcToken @1 :TokenOffset;
  isUcInstanceUcVariableUcNameUcSpecified @2 :Bool;
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
  enumUcToken @1 :TokenOffset;
  usingUcToken @2 :TokenOffset;
}

struct UsingDecl @0xb8602dcb3f95c179 {
  baseUcUsingUcDecl @0:BaseUsingDecl;
  usingUcToken @1 :TokenOffset;
  hasUcTypename @2 :Bool;
  isUcAccessUcDeclaration @3 :Bool;
}

struct ValueDecl @0xe2704a366b05e616 {
  namedUcDecl @0:NamedDecl;
  isUcWeak @1 :Bool;
}

struct UnresolvedUsingValueDecl @0x8ad2fc298aa43ab1 {
  valueUcDecl @0:ValueDecl;
  ellipsisUcToken @1 :TokenOffset;
  usingUcToken @2 :TokenOffset;
  isUcAccessUcDeclaration @3 :Bool;
  isUcPackUcExpansion @4 :Bool;
}

struct TemplateParamObjectDecl @0xd09f17939d7cc847 {
  valueUcDecl @0:ValueDecl;
}

struct OMPDeclareReductionDecl @0xf59daefbeeafc092 {
  valueUcDecl @0:ValueDecl;
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
  innerUcTokenUcStart @1 :TokenOffset;
  outerUcTokenUcStart @2 :TokenOffset;
  typeUcSpecUcEndUcToken @3 :TokenOffset;
  typeUcSpecUcStartUcToken @4 :TokenOffset;
}

struct VarDecl @0xcf9adcbc59a4e339 {
  declaratorUcDecl @0:DeclaratorDecl;
  languageUcLinkage @1 :LanguageLinkage;
  pointUcOfUcInstantiation @2 :TokenOffset;
  storageUcClass @3 :StorageClass;
  storageUcDuration @4 :StorageDuration;
  tscUcSpec @5 :ThreadStorageClassSpecifier;
  templateUcSpecializationUcKind @6 :TemplateSpecializationKind;
  templateUcSpecializationUcKindUcForUcInstantiation @7 :TemplateSpecializationKind;
  hasUcConstantUcInitialization @8 :Bool;
  hasUcDependentUcAlignment @9 :Bool;
  hasUcExternalUcStorage @10 :Bool;
  hasUcGlobalUcStorage @11 :Bool;
  hasUcIceUcInitializer @12 :Bool;
  hasUcInitializer @13 :Bool;
  hasUcLocalUcStorage @14 :Bool;
  isUcArcUcPseudoUcStrong @15 :Bool;
  isUcCxxUcForUcRangeUcDeclaration @16 :Bool;
  isUcConstexpr @17 :Bool;
  isUcDirectUcInitializer @18 :Bool;
  isUcEscapingUcByref @19 :Bool;
  isUcExceptionUcVariable @20 :Bool;
  isUcExternUcC @21 :Bool;
  isUcFileUcVariableUcDeclaration @22 :Bool;
  isUcFunctionUcOrUcMethodUcVariableUcDeclaration @23 :Bool;
  isUcInUcExternUcCUcContext @24 :Bool;
  isUcInUcExternUcCxxUcContext @25 :Bool;
  isUcInitializerUcCapture @26 :Bool;
  isUcInline @27 :Bool;
  isUcInlineUcSpecified @28 :Bool;
  isUcKnownUcToUcBeUcDefined @29 :Bool;
  isUcLocalUcVariableUcDeclaration @30 :Bool;
  isUcLocalUcVariableUcDeclarationUcOrUcParm @31 :Bool;
  isUcNrvoUcVariable @32 :Bool;
  isUcNoUcDestroy @33 :Bool;
  isUcNonUcEscapingUcByref @34 :Bool;
  isUcObjUcCUcForUcDeclaration @35 :Bool;
  isUcPreviousUcDeclarationUcInUcSameUcBlockUcScope @36 :Bool;
  isUcStaticUcDataUcMember @37 :Bool;
  isUcStaticUcLocal @38 :Bool;
  isUcThisUcDeclarationUcAUcDemotedUcDefinition @39 :Bool;
  isUcUsableUcInUcConstantUcExpressions @40 :Bool;
  mightUcBeUcUsableUcInUcConstantUcExpressions @41 :Bool;
}

struct ParmVarDecl @0xedf01c1d7684de38 {
  varUcDecl @0:VarDecl;
  defaultUcArgumentUcRange @1 :TokenRange;
  hasUcDefaultUcArgument @2 :Bool;
  hasUcInheritedUcDefaultUcArgument @3 :Bool;
  hasUcUninstantiatedUcDefaultUcArgument @4 :Bool;
  hasUcUnparsedUcDefaultUcArgument @5 :Bool;
  isUcDestroyedUcInUcCallee @6 :Bool;
  isUcKnrUcPromoted @7 :Bool;
  isUcObjUcCUcMethodUcParameter @8 :Bool;
}

struct OMPCapturedExprDecl @0x8dae8ad443b5cf77 {
  varUcDecl @0:VarDecl;
}

struct ImplicitParamDecl @0x9482ac8d963f562c {
  varUcDecl @0:VarDecl;
  parameterUcKind @1 :ImplicitParamKind;
}

struct DecompositionDecl @0xd32bcfb0d1a2facb {
  varUcDecl @0:VarDecl;
}

struct VarTemplateSpecializationDecl @0xbaf3e3ed90ea85e0 {
  varUcDecl @0:VarDecl;
  externUcToken @1 :TokenOffset;
  specializationUcKind @2 :TemplateSpecializationKind;
  templateUcKeywordUcToken @3 :TokenOffset;
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
  defaultUcArgumentUcToken @2 :TokenOffset;
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
  ellipsisUcToken @4 :TokenOffset;
  exceptionUcSpecUcSourceUcRange @5 :TokenRange;
  exceptionUcSpecUcType @6 :ExceptionSpecificationType;
  languageUcLinkage @7 :LanguageLinkage;
  multiUcVersionUcKind @8 :MultiVersionKind;
  overloadedUcOperator @9 :OverloadedOperatorKind;
  parametersUcSourceUcRange @10 :TokenRange;
  pointUcOfUcInstantiation @11 :TokenOffset;
  returnUcTypeUcSourceUcRange @12 :TokenRange;
  storageUcClass @13 :StorageClass;
  templateUcSpecializationUcKind @14 :TemplateSpecializationKind;
  templateUcSpecializationUcKindUcForUcInstantiation @15 :TemplateSpecializationKind;
  hasUcImplicitUcReturnUcZero @16 :Bool;
  hasUcInheritedUcPrototype @17 :Bool;
  hasUcOneUcParamUcOrUcDefaultUcArguments @18 :Bool;
  hasUcPrototype @19 :Bool;
  hasUcSkippedUcBody @20 :Bool;
  hasUcTrivialUcBody @21 :Bool;
  hasUcWrittenUcPrototype @22 :Bool;
  instantiationUcIsUcPending @23 :Bool;
  isUcCpuUcDispatchUcMultiUcVersion @24 :Bool;
  isUcCpuUcSpecificUcMultiUcVersion @25 :Bool;
  isUcConsteval @26 :Bool;
  isUcConstexpr @27 :Bool;
  isUcConstexprUcSpecified @28 :Bool;
  isUcDefaulted @29 :Bool;
  isUcDeleted @30 :Bool;
  isUcDeletedUcAsUcWritten @31 :Bool;
  isUcDestroyingUcOperatorUcDelete @32 :Bool;
  isUcExplicitlyUcDefaulted @33 :Bool;
  isUcExternUcC @34 :Bool;
  isUcFunctionUcTemplateUcSpecialization @35 :Bool;
  isUcGlobal @36 :Bool;
  isUcImplicitlyUcInstantiable @37 :Bool;
  isUcInUcExternUcCUcContext @38 :Bool;
  isUcInUcExternUcCxxUcContext @39 :Bool;
  isUcInlineUcBuiltinUcDeclaration @40 :Bool;
  isUcInlineUcDefinitionUcExternallyUcVisible @41 :Bool;
  isUcInlineUcSpecified @42 :Bool;
  isUcInlined @43 :Bool;
  isUcLateUcTemplateUcParsed @44 :Bool;
  isUcMsUcExternUcInline @45 :Bool;
  isUcMsvcrtUcEntryUcPoint @46 :Bool;
  isUcMain @47 :Bool;
  isUcMultiUcVersion @48 :Bool;
  isUcNoUcReturn @49 :Bool;
  isUcOverloadedUcOperator @50 :Bool;
  isUcPure @51 :Bool;
  isUcReplaceableUcGlobalUcAllocationUcFunction @52 :Bool;
  isUcReservedUcGlobalUcPlacementUcOperator @53 :Bool;
  isUcStatic @54 :Bool;
  isUcTargetUcMultiUcVersion @55 :Bool;
  isUcTemplateUcInstantiation @56 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @57 :Bool;
  isUcThisUcDeclarationUcInstantiatedUcFromUcAUcFriendUcDefinition @58 :Bool;
  isUcTrivial @59 :Bool;
  isUcTrivialUcForUcCall @60 :Bool;
  isUcUserUcProvided @61 :Bool;
  isUcVariadic @62 :Bool;
  isUcVirtualUcAsUcWritten @63 :Bool;
  usesUcSehUcTry @64 :Bool;
  willUcHaveUcBody @65 :Bool;
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
  synthesize @1 :Bool;
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
  identifierUcToken @1 :TokenOffset;
  namespaceUcKeyUcToken @2 :TokenOffset;
  usingUcToken @3 :TokenOffset;
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
  defaultUcArgumentUcToken @2 :TokenOffset;
  hasUcDefaultUcArgument @3 :Bool;
  hasUcTypeUcConstraint @4 :Bool;
  isUcExpandedUcParameterUcPack @5 :Bool;
  isUcPackUcExpansion @6 :Bool;
  wasUcDeclaredUcWithUcTypename @7 :Bool;
}

struct TagDecl @0x8e30dcc81a0377d1 {
  typeUcDecl @0:TypeDecl;
  braceUcRange @1 :TokenRange;
  innerUcTokenUcStart @2 :TokenOffset;
  outerUcTokenUcStart @3 :TokenOffset;
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
  argumentUcPassingUcRestrictions @2 :ArgPassingKind;
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
  isUcCxx11UcStandardUcLayout @72 :Bool;
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
  externUcToken @1 :TokenOffset;
  pointUcOfUcInstantiation @2 :TokenOffset;
  specializationUcKind @3 :TemplateSpecializationKind;
  templateUcKeywordUcToken @4 :TokenOffset;
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
  ellipsisUcToken @1 :TokenOffset;
  typenameUcToken @2 :TokenOffset;
  usingUcToken @3 :TokenOffset;
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
  colonUcToken @1 :TokenOffset;
  variance @2 :ObjCTypeParamVariance;
  varianceUcToken @3 :TokenOffset;
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
  defaultUcArgumentUcToken @2 :TokenOffset;
  hasUcDefaultUcArgument @3 :Bool;
  isUcExpandedUcParameterUcPack @4 :Bool;
  isUcPackUcExpansion @5 :Bool;
}

struct ObjCPropertyDecl @0x9eb7f76b62290548 {
  namedUcDecl @0:NamedDecl;
  atUcToken @1 :TokenOffset;
  getterUcNameUcToken @2 :TokenOffset;
  lUcParenUcToken @3 :TokenOffset;
  propertyUcImplementation @4 :PropertyControl;
  queryUcKind @5 :ObjCPropertyQueryKind;
  setterUcKind @6 :SetterKind;
  setterUcNameUcToken @7 :TokenOffset;
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
  declaratorUcEndUcToken @2 :TokenOffset;
  implementationUcControl @3 :ImplementationControl;
  methodUcFamily @4 :ObjCMethodFamily;
  returnUcTypeUcSourceUcRange @5 :TokenRange;
  selectorUcStartUcToken @6 :TokenOffset;
  hasUcRedeclaration @7 :Bool;
  hasUcRelatedUcResultUcType @8 :Bool;
  hasUcSkippedUcBody @9 :Bool;
  isUcClassUcMethod @10 :Bool;
  isUcDefined @11 :Bool;
  isUcDesignatedUcInitializerUcForUcTheUcInterface @12 :Bool;
  isUcDirectUcMethod @13 :Bool;
  isUcInstanceUcMethod @14 :Bool;
  isUcOptional @15 :Bool;
  isUcOverriding @16 :Bool;
  isUcPropertyUcAccessor @17 :Bool;
  isUcRedeclaration @18 :Bool;
  isUcSynthesizedUcAccessorUcStub @19 :Bool;
  isUcThisUcDeclarationUcAUcDefinition @20 :Bool;
  isUcThisUcDeclarationUcAUcDesignatedUcInitializer @21 :Bool;
  isUcVariadic @22 :Bool;
}

struct ObjCContainerDecl @0xaf9db5ae0b65ce9e {
  namedUcDecl @0:NamedDecl;
  atUcEndUcRange @1 :TokenRange;
  atUcStartUcToken @2 :TokenOffset;
}

struct ObjCCategoryDecl @0xb673566cbe41a76d {
  objUcCUcContainerUcDecl @0:ObjCContainerDecl;
  isUcClassUcExtension @1 :Bool;
  categoryUcNameUcToken @2 :TokenOffset;
  instanceUcVariableUcLUcBraceUcToken @3 :TokenOffset;
  instanceUcVariableUcRUcBraceUcToken @4 :TokenOffset;
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
  endUcOfUcDefinitionUcToken @2 :TokenOffset;
  objUcCUcRuntimeUcNameUcAsUcString @3 :Text;
  superUcClassUcToken @4 :TokenOffset;
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
  categoryUcNameUcToken @1 :TokenOffset;
}

struct ObjCImplementationDecl @0xf2e56fe062561acd {
  objUcCUcImplUcDecl @0:ObjCImplDecl;
  instanceUcVariableUcLUcBraceUcToken @1 :TokenOffset;
  instanceUcVariableUcRUcBraceUcToken @2 :TokenOffset;
  objUcCUcRuntimeUcNameUcAsUcString @3 :Text;
  superUcClassUcToken @4 :TokenOffset;
  hasUcDestructors @5 :Bool;
  hasUcNonUcZeroUcConstructors @6 :Bool;
}

struct ObjCCompatibleAliasDecl @0xc484be73cf6be95b {
  namedUcDecl @0:NamedDecl;
}

struct NamespaceDecl @0xd4713edcad196585 {
  namedUcDecl @0:NamedDecl;
  rUcBraceUcToken @1 :TokenOffset;
  isUcAnonymousUcNamespace @2 :Bool;
  isUcInline @3 :Bool;
  isUcOriginalUcNamespace @4 :Bool;
}

struct NamespaceAliasDecl @0xd8966652a484c480 {
  namedUcDecl @0:NamedDecl;
  aliasUcToken @1 :TokenOffset;
  namespaceUcToken @2 :TokenOffset;
  targetUcNameUcToken @3 :TokenOffset;
}

struct LinkageSpecDecl @0xb0f84c4a56c95eec {
  decl @0:Decl;
  externUcToken @1 :TokenOffset;
  language @2 :LanguageIDs;
  rUcBraceUcToken @3 :TokenOffset;
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
  friendUcToken @1 :TokenOffset;
}

struct FriendDecl @0xe6545eb838d810d0 {
  decl @0:Decl;
  friendUcToken @1 :TokenOffset;
  isUcUnsupportedUcFriend @2 :Bool;
}

struct FileScopeAsmDecl @0xa91b82b590024228 {
  decl @0:Decl;
  assemblyUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ExternCContextDecl @0xd79e4560c3f80cbd {
  decl @0:Decl;
}

struct ExportDecl @0xb9bc9642842c6d81 {
  decl @0:Decl;
  exportUcToken @1 :TokenOffset;
  rUcBraceUcToken @2 :TokenOffset;
  hasUcBraces @3 :Bool;
}

struct EmptyDecl @0xdb55f7b2f60fd2a7 {
  decl @0:Decl;
}

struct Stmt @0x91127d30fade9a32 {
  beginUcToken @0 :TokenOffset;
  endUcToken @1 :TokenOffset;
  tokenUcRange @2 :TokenRange;
  kind @3 :StmtKind;
}

struct SEHTryStmt @0xf24201c85c654a91 {
  stmt @0:Stmt;
  isUcCxxUcTry @1 :Bool;
  tryUcToken @2 :TokenOffset;
}

struct SEHLeaveStmt @0xc4e4ea7e9d86c292 {
  stmt @0:Stmt;
  leaveUcToken @1 :TokenOffset;
}

struct SEHFinallyStmt @0x8331103206247bcd {
  stmt @0:Stmt;
  finallyUcToken @1 :TokenOffset;
}

struct SEHExceptStmt @0xec2050c67aa8fa46 {
  stmt @0:Stmt;
  exceptUcToken @1 :TokenOffset;
}

struct ReturnStmt @0xa64f08dfd7dbc80a {
  stmt @0:Stmt;
  returnUcToken @1 :TokenOffset;
}

struct ObjCForCollectionStmt @0x9eba75a6b3c891a0 {
  stmt @0:Stmt;
  forUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ObjCAutoreleasePoolStmt @0x9762e1f9121378d2 {
  stmt @0:Stmt;
  atUcToken @1 :TokenOffset;
}

struct ObjCAtTryStmt @0x8a11f497922c60fa {
  stmt @0:Stmt;
  atUcTryUcToken @1 :TokenOffset;
}

struct ObjCAtThrowStmt @0xd0de9b13bfbb829d {
  stmt @0:Stmt;
  throwUcToken @1 :TokenOffset;
}

struct ObjCAtSynchronizedStmt @0xc002bd58ce946b42 {
  stmt @0:Stmt;
  atUcSynchronizedUcToken @1 :TokenOffset;
}

struct ObjCAtFinallyStmt @0xb4641f5dbb7b9c51 {
  stmt @0:Stmt;
  atUcFinallyUcToken @1 :TokenOffset;
}

struct ObjCAtCatchStmt @0xea4d614d29e03f4e {
  stmt @0:Stmt;
  atUcCatchUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  hasUcEllipsis @3 :Bool;
}

struct OMPExecutableDirective @0xd9ecc0e6e88a888e {
  stmt @0:Stmt;
  hasUcAssociatedUcStatement @1 :Bool;
  isUcStandaloneUcDirective @2 :Bool;
}

struct OMPDispatchDirective @0xf2ebe316be280493 {
  ompUcExecutableUcDirective @0:OMPExecutableDirective;
  targetUcCallUcToken @1 :TokenOffset;
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
  semiUcToken @1 :TokenOffset;
  hasUcLeadingUcEmptyUcMacro @2 :Bool;
}

struct MSDependentExistsStmt @0xb5d9dfc73eeb0939 {
  stmt @0:Stmt;
  keywordUcToken @1 :TokenOffset;
  isUcIfUcExists @2 :Bool;
  isUcIfUcNotUcExists @3 :Bool;
}

struct IndirectGotoStmt @0xca063608491ba1fa {
  stmt @0:Stmt;
  gotoUcToken @1 :TokenOffset;
  starUcToken @2 :TokenOffset;
}

struct IfStmt @0xfc829da66c4e6bb1 {
  stmt @0:Stmt;
  elseUcToken @1 :TokenOffset;
  ifUcToken @2 :TokenOffset;
  lUcParenUcToken @3 :TokenOffset;
  rUcParenUcToken @4 :TokenOffset;
  hasUcElseUcStorage @5 :Bool;
  hasUcInitializerUcStorage @6 :Bool;
  hasUcVariableUcStorage @7 :Bool;
  isUcConstexpr @8 :Bool;
  isUcObjUcCUcAvailabilityUcCheck @9 :Bool;
}

struct GotoStmt @0xf542902873fc6c2b {
  stmt @0:Stmt;
  gotoUcToken @1 :TokenOffset;
  labelUcToken @2 :TokenOffset;
}

struct ForStmt @0xb6591c23541f6a1e {
  stmt @0:Stmt;
  forUcToken @1 :TokenOffset;
  lUcParenUcToken @2 :TokenOffset;
  rUcParenUcToken @3 :TokenOffset;
}

struct DoStmt @0xf6407ae4f3214356 {
  stmt @0:Stmt;
  doUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  whileUcToken @3 :TokenOffset;
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
  keywordUcToken @1 :TokenOffset;
  isUcImplicit @2 :Bool;
}

struct ContinueStmt @0xb364bd3d9a19cd05 {
  stmt @0:Stmt;
  continueUcToken @1 :TokenOffset;
}

struct CompoundStmt @0xd080c9192fa41c92 {
  stmt @0:Stmt;
  lUcBracUcToken @1 :TokenOffset;
  rUcBracUcToken @2 :TokenOffset;
}

struct CapturedStmt @0xa60fffc1366b48e6 {
  stmt @0:Stmt;
  capturedUcRegionUcKind @1 :CapturedRegionKind;
}

struct CXXTryStmt @0xf98f02d4cdc2dd3b {
  stmt @0:Stmt;
  tryUcToken @1 :TokenOffset;
}

struct CXXForRangeStmt @0xa23a75b3c0fa7d86 {
  stmt @0:Stmt;
  coawaitUcToken @1 :TokenOffset;
  colonUcToken @2 :TokenOffset;
  forUcToken @3 :TokenOffset;
  rUcParenUcToken @4 :TokenOffset;
}

struct CXXCatchStmt @0xac4b9e8390fd3a85 {
  stmt @0:Stmt;
  catchUcToken @1 :TokenOffset;
}

struct BreakStmt @0x940efd4e9770cb41 {
  stmt @0:Stmt;
  breakUcToken @1 :TokenOffset;
}

struct AsmStmt @0xa47714ac2d00fb21 {
  stmt @0:Stmt;
  generateUcAssemblyUcString @1 :Text;
  assemblyUcToken @2 :TokenOffset;
  isUcSimple @3 :Bool;
  isUcVolatile @4 :Bool;
}

struct MSAsmStmt @0xc504268dee34a98f {
  asmUcStmt @0:AsmStmt;
  assemblyUcString @1 :Text;
  lUcBraceUcToken @2 :TokenOffset;
  hasUcBraces @3 :Bool;
}

struct GCCAsmStmt @0x9d046a0d94b425db {
  asmUcStmt @0:AsmStmt;
  rUcParenUcToken @1 :TokenOffset;
  isUcAssemblyUcGoto @2 :Bool;
}

struct WhileStmt @0x8f0fb0e808ef8cd3 {
  stmt @0:Stmt;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  whileUcToken @3 :TokenOffset;
  hasUcVariableUcStorage @4 :Bool;
}

struct ValueStmt @0xc78a8bda41f72525 {
  stmt @0:Stmt;
}

struct LabelStmt @0xed2b87febf6a7cc9 {
  valueUcStmt @0:ValueStmt;
  identifierUcToken @1 :TokenOffset;
  name @2 :Text;
  isUcSideUcEntry @3 :Bool;
}

struct Expr @0x9e4316b5a505b8d6 {
  valueUcStmt @0:ValueStmt;
  hasUcSideUcEffects @1 :Bool;
  containsUcErrors @2 :Bool;
  containsUcUnexpandedUcParameterUcPack @3 :Bool;
  expressionUcToken @4 :TokenOffset;
  objectUcKind @5 :ExprObjectKind;
  valueUcKind @6 :ExprValueKind;
  hasUcNonUcTrivialUcCall @7 :Bool;
  isUcBoundUcMemberUcFunction @8 :Bool;
  isUcCxx11UcConstantUcExpression @9 :Bool;
  isUcCxx98UcIntegralUcConstantUcExpression @10 :Bool;
  isUcDefaultUcArgument @11 :Bool;
  isUcEvaluatable @12 :Bool;
  isUcGlUcValue @13 :Bool;
  isUcImplicitUcCxxUcThis @14 :Bool;
  isUcInstantiationUcDependent @15 :Bool;
  isUcIntegerUcConstantUcExpression @16 :Bool;
  isUcKnownUcToUcHaveUcBooleanUcValue @17 :Bool;
  isUcLUcValue @18 :Bool;
  isUcObjcgcUcCandidate @19 :Bool;
  isUcObjUcCUcSelfUcExpression @20 :Bool;
  isUcOrdinaryUcOrUcBitUcFieldUcObject @21 :Bool;
  isUcPrUcValue @22 :Bool;
  isUcReadUcIfUcDiscardedUcInUcCUcPlusUcPlus11 @23 :Bool;
  isUcTypeUcDependent @24 :Bool;
  isUcValueUcDependent @25 :Bool;
  isUcXUcValue @26 :Bool;
  refersUcToUcBitUcField @27 :Bool;
  refersUcToUcGlobalUcRegisterUcVariable @28 :Bool;
  refersUcToUcMatrixUcElement @29 :Bool;
  refersUcToUcVectorUcElement @30 :Bool;
}

struct DesignatedInitUpdateExpr @0xaa6c77a8da7c4fba {
  expr @0:Expr;
}

struct DesignatedInitExpr @0xeff2c52d9c942ab2 {
  expr @0:Expr;
  designatorsUcSourceUcRange @1 :TokenRange;
  equalUcOrUcColonUcToken @2 :TokenOffset;
  isUcDirectUcInitializer @3 :Bool;
  usesUcGnuUcSyntax @4 :Bool;
}

struct DependentScopeDeclRefExpr @0x8fbb6ccb95a3509d {
  expr @0:Expr;
  lUcAngleUcToken @1 :TokenOffset;
  rUcAngleUcToken @2 :TokenOffset;
  templateUcKeywordUcToken @3 :TokenOffset;
  hasUcExplicitUcTemplateUcArguments @4 :Bool;
  hasUcTemplateUcKeyword @5 :Bool;
}

struct DependentCoawaitExpr @0x8fd8a27becb59315 {
  expr @0:Expr;
  keywordUcToken @1 :TokenOffset;
}

struct DeclRefExpr @0xec5119d27610b166 {
  expr @0:Expr;
  lUcAngleUcToken @1 :TokenOffset;
  rUcAngleUcToken @2 :TokenOffset;
  templateUcKeywordUcToken @3 :TokenOffset;
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
  keywordUcToken @1 :TokenOffset;
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
  builtinUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ConceptSpecializationExpr @0xfed5bd9e47227653 {
  expr @0:Expr;
  isUcSatisfied @1 :Bool;
}

struct CompoundLiteralExpr @0x9865eabaf4e2ef8c {
  expr @0:Expr;
  lUcParenUcToken @1 :TokenOffset;
  isUcFileUcScope @2 :Bool;
}

struct ChooseExpr @0xd4a658caf5a1339e {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  isUcConditionUcDependent @3 :Bool;
  isUcConditionUcTrue @4 :Bool;
}

struct CharacterLiteral @0xbe144b3e9bdba5d9 {
  expr @0:Expr;
  token @1 :TokenOffset;
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
  operatorUcToken @3 :TokenOffset;
  rUcParenUcToken @4 :TokenOffset;
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
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  isUcListUcInitialization @3 :Bool;
}

struct CStyleCastExpr @0xddb96d0ba671cd89 {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct BuiltinBitCastExpr @0xc4d665f00ba3fa8b {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
}

struct ObjCBridgedCastExpr @0xad38ef321a1ce1e3 {
  explicitUcCastUcExpr @0:ExplicitCastExpr;
  bridgeUcKeywordUcToken @1 :TokenOffset;
  bridgeUcKind @2 :ObjCBridgeCastKind;
  bridgeUcKindUcName @3 :Text;
  lUcParenUcToken @4 :TokenOffset;
}

struct CallExpr @0x8cff24c7f68e334b {
  expr @0:Expr;
  adlUcCallUcKind @1 :ADLCallKind;
  rUcParenUcToken @2 :TokenOffset;
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
  operatorUcToken @2 :TokenOffset;
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
  udUcSuffixUcToken @1 :TokenOffset;
}

struct CXXUuidofExpr @0xcdde7d28fc7931f6 {
  expr @0:Expr;
  isUcTypeUcOperand @1 :Bool;
}

struct CXXUnresolvedConstructExpr @0x9fbb7e373f171f86 {
  expr @0:Expr;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
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
  throwUcToken @1 :TokenOffset;
  isUcThrownUcVariableUcInUcScope @2 :Bool;
}

struct CXXThisExpr @0x959ba6d5fec8b422 {
  expr @0:Expr;
  token @1 :TokenOffset;
  isUcImplicit @2 :Bool;
}

struct CXXStdInitializerListExpr @0xd199eb3b19c592fa {
  expr @0:Expr;
}

struct CXXScalarValueInitExpr @0x9fd4b7d4985831e7 {
  expr @0:Expr;
  rUcParenUcToken @1 :TokenOffset;
}

struct CXXRewrittenBinaryOperator @0xd00648fa0bd5ccc4 {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeUcString @2 :Text;
  operator @3 :BinaryOperatorKind;
  operatorUcToken @4 :TokenOffset;
  isUcAssignmentUcOperation @5 :Bool;
  isUcComparisonUcOperation @6 :Bool;
  isUcReversed @7 :Bool;
}

struct CXXPseudoDestructorExpr @0xfb788932e740ac07 {
  expr @0:Expr;
  colonUcColonUcToken @1 :TokenOffset;
  destroyedUcTypeUcToken @2 :TokenOffset;
  operatorUcToken @3 :TokenOffset;
  tildeUcToken @4 :TokenOffset;
  hasUcQualifier @5 :Bool;
  isUcArrow @6 :Bool;
}

struct CXXNullPtrLiteralExpr @0x80352ea6175b520f {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct CXXNoexceptExpr @0x97e76c7f0648cbe4 {
  expr @0:Expr;
  value @1 :Bool;
}

struct CXXNewExpr @0x9dca0c0f9404e2b5 {
  expr @0:Expr;
  doesUcUsualUcArrayUcDeleteUcWantUcSize @1 :Bool;
  directUcInitializerUcRange @2 :TokenRange;
  initializationUcStyle @3 :InitializationStyle;
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
  constructionUcKind @2 :ConstructionKind;
  token @3 :TokenOffset;
  inheritedUcFromUcVirtualUcBase @4 :Bool;
}

struct CXXFoldExpr @0x8a593922e3ea9d50 {
  expr @0:Expr;
  ellipsisUcToken @1 :TokenOffset;
  lUcParenUcToken @2 :TokenOffset;
  operator @3 :BinaryOperatorKind;
  rUcParenUcToken @4 :TokenOffset;
  isUcLeftUcFold @5 :Bool;
  isUcRightUcFold @6 :Bool;
}

struct CXXDependentScopeMemberExpr @0xa1a21ac74e691c1f {
  expr @0:Expr;
  lUcAngleUcToken @1 :TokenOffset;
  memberUcToken @2 :TokenOffset;
  operatorUcToken @3 :TokenOffset;
  rUcAngleUcToken @4 :TokenOffset;
  templateUcKeywordUcToken @5 :TokenOffset;
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
  usedUcToken @1 :TokenOffset;
}

struct CXXDefaultArgExpr @0x9f9ee9dcf349cbcf {
  expr @0:Expr;
  usedUcToken @1 :TokenOffset;
}

struct CXXConstructExpr @0xb3d036394c09ed48 {
  expr @0:Expr;
  constructionUcKind @1 :ConstructionKind;
  token @2 :TokenOffset;
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
  token @1 :TokenOffset;
  value @2 :Bool;
}

struct CXXBindTemporaryExpr @0xc6a96978d42dc702 {
  expr @0:Expr;
}

struct BlockExpr @0xc2ae5be0934c61f3 {
  expr @0:Expr;
  caretUcToken @1 :TokenOffset;
}

struct BinaryOperator @0xd858b89bd116f05f {
  expr @0:Expr;
  opcode @1 :BinaryOperatorKind;
  opcodeUcString @2 :Text;
  operatorUcToken @3 :TokenOffset;
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
  builtinUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  isUcCmpUcXUcChg @3 :Bool;
  isUcOpenUcCl @4 :Bool;
  isUcVolatile @5 :Bool;
}

struct AsTypeExpr @0xf646590167dcf1ab {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ArrayTypeTraitExpr @0xcbcb35a78956a3cc {
  expr @0:Expr;
  trait @1 :ArrayTypeTrait;
}

struct ArraySubscriptExpr @0xb5bb680da7ccce33 {
  expr @0:Expr;
  rUcBracketUcToken @1 :TokenOffset;
}

struct ArrayInitLoopExpr @0xbe95601783117ebe {
  expr @0:Expr;
}

struct ArrayInitIndexExpr @0xc9bc62bebe2cdbb8 {
  expr @0:Expr;
}

struct AddrLabelExpr @0xc1abc55fece6aa91 {
  expr @0:Expr;
  ampUcAmpUcToken @1 :TokenOffset;
  labelUcToken @2 :TokenOffset;
}

struct AbstractConditionalOperator @0xee7097774f7aaa45 {
  expr @0:Expr;
  colonUcToken @1 :TokenOffset;
  questionUcToken @2 :TokenOffset;
}

struct ConditionalOperator @0xd3810312a3bd13c7 {
  abstractUcConditionalUcOperator @0:AbstractConditionalOperator;
}

struct BinaryConditionalOperator @0xde5f047672b1ac84 {
  abstractUcConditionalUcOperator @0:AbstractConditionalOperator;
}

struct VAArgExpr @0x8fa746d782ee27c9 {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  isUcMicrosoftUcAbi @3 :Bool;
}

struct UnaryOperator @0xaa78820aaa7f22b8 {
  expr @0:Expr;
  canUcOverflow @1 :Bool;
  opcode @2 :UnaryOperatorKind;
  operatorUcToken @3 :TokenOffset;
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
  operatorUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
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
  parameterUcPackUcToken @1 :TokenOffset;
}

struct SubstNonTypeTemplateParmExpr @0xad38ba4bfe617a6f {
  expr @0:Expr;
  nameUcToken @1 :TokenOffset;
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
  isUcUtf16 @7 :Bool;
  isUcUtf32 @8 :Bool;
  isUcUtf8 @9 :Bool;
  isUcWide @10 :Bool;
}

struct StmtExpr @0xe3606abe04461b8a {
  expr @0:Expr;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct SourceLocExpr @0xd4bebb374e1e6d58 {
  expr @0:Expr;
  builtinUcString @1 :Text;
  token @2 :TokenOffset;
  isUcIntUcType @3 :Bool;
  isUcStringUcType @4 :Bool;
}

struct SizeOfPackExpr @0xa4f777d7b3ce890c {
  expr @0:Expr;
  operatorUcToken @1 :TokenOffset;
  packUcToken @2 :TokenOffset;
  rUcParenUcToken @3 :TokenOffset;
  isUcPartiallyUcSubstituted @4 :Bool;
}

struct ShuffleVectorExpr @0xdfa87964ccc4abd6 {
  expr @0:Expr;
  builtinUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct SYCLUniqueStableNameExpr @0xfa67d59d16f9a78a {
  expr @0:Expr;
  computeUcName @1 :Text;
  lUcParenUcToken @2 :TokenOffset;
  token @3 :TokenOffset;
  rUcParenUcToken @4 :TokenOffset;
}

struct RequiresExpr @0xe4f5db5ba506ab26 {
  expr @0:Expr;
  rUcBraceUcToken @1 :TokenOffset;
  requiresUcKwUcToken @2 :TokenOffset;
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
  identifierUcKindUcName @1 :Text;
  token @2 :TokenOffset;
}

struct ParenListExpr @0xc7ba76bb20cf6201 {
  expr @0:Expr;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ParenExpr @0x821bf890921895cd {
  expr @0:Expr;
  lUcParen @1 :TokenOffset;
  rUcParen @2 :TokenOffset;
}

struct PackExpansionExpr @0xbf1eafc846bba2e0 {
  expr @0:Expr;
  ellipsisUcToken @1 :TokenOffset;
}

struct OverloadExpr @0xe1320ca92341cff5 {
  expr @0:Expr;
  lUcAngleUcToken @1 :TokenOffset;
  nameUcToken @2 :TokenOffset;
  rUcAngleUcToken @3 :TokenOffset;
  templateUcKeywordUcToken @4 :TokenOffset;
  hasUcExplicitUcTemplateUcArguments @5 :Bool;
  hasUcTemplateUcKeyword @6 :Bool;
}

struct UnresolvedMemberExpr @0xbd4aeea6486879d1 {
  overloadUcExpr @0:OverloadExpr;
  memberUcToken @1 :TokenOffset;
  operatorUcToken @2 :TokenOffset;
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
  token @1 :TokenOffset;
  isUcUnique @2 :Bool;
}

struct OffsetOfExpr @0xe74e51b681474f08 {
  expr @0:Expr;
  operatorUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ObjCSubscriptRefExpr @0x827d6564c3126c7a {
  expr @0:Expr;
  rUcBracket @1 :TokenOffset;
  isUcArrayUcSubscriptUcReferenceUcExpression @2 :Bool;
}

struct ObjCStringLiteral @0x84470e968f7365fb {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
}

struct ObjCSelectorExpr @0xa6687e4a6275988d {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ObjCProtocolExpr @0xb07709e6d6281804 {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  protocolUcIdUcToken @2 :TokenOffset;
  rUcParenUcToken @3 :TokenOffset;
}

struct ObjCPropertyRefExpr @0x9f75c18ee7f1c7a2 {
  expr @0:Expr;
  token @1 :TokenOffset;
  receiverUcToken @2 :TokenOffset;
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
  leftUcToken @1 :TokenOffset;
  methodUcFamily @2 :ObjCMethodFamily;
  receiverUcRange @3 :TokenRange;
  rightUcToken @4 :TokenOffset;
  selectorUcStartUcToken @5 :TokenOffset;
  superUcToken @6 :TokenOffset;
  isUcClassUcMessage @7 :Bool;
  isUcDelegateUcInitializerUcCall @8 :Bool;
  isUcImplicit @9 :Bool;
  isUcInstanceUcMessage @10 :Bool;
}

struct ObjCIvarRefExpr @0xec7058b5b38773dd {
  expr @0:Expr;
  token @1 :TokenOffset;
  operationUcToken @2 :TokenOffset;
  isUcArrow @3 :Bool;
  isUcFreeUcInstanceUcVariable @4 :Bool;
}

struct ObjCIsaExpr @0xe3c04c83aef329c8 {
  expr @0:Expr;
  baseUcTokenUcEnd @1 :TokenOffset;
  isaUcMemberUcToken @2 :TokenOffset;
  operationUcToken @3 :TokenOffset;
  isUcArrow @4 :Bool;
}

struct ObjCIndirectCopyRestoreExpr @0x9475cc6d12ba1afb {
  expr @0:Expr;
  shouldUcCopy @1 :Bool;
}

struct ObjCEncodeExpr @0x911855b6fa2d9812 {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct ObjCDictionaryLiteral @0xaef4d291186415b7 {
  expr @0:Expr;
}

struct ObjCBoxedExpr @0xae80861f1a63c950 {
  expr @0:Expr;
  atUcToken @1 :TokenOffset;
  isUcExpressibleUcAsUcConstantUcInitializer @2 :Bool;
}

struct ObjCBoolLiteralExpr @0xb2d027f2c8cad1fb {
  expr @0:Expr;
  token @1 :TokenOffset;
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
  iteratorUcKwUcToken @1 :TokenOffset;
  lUcParenUcToken @2 :TokenOffset;
  rUcParenUcToken @3 :TokenOffset;
}

struct OMPArrayShapingExpr @0xcddd3cf38d603be1 {
  expr @0:Expr;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
}

struct OMPArraySectionExpr @0xca2808db37aea2e0 {
  expr @0:Expr;
  colonUcTokenUcFirst @1 :TokenOffset;
  colonUcTokenUcSecond @2 :TokenOffset;
  rUcBracketUcToken @3 :TokenOffset;
}

struct NoInitExpr @0xadedf240a5b5d3d1 {
  expr @0:Expr;
}

struct MemberExpr @0xd8c89de1fe446ed0 {
  expr @0:Expr;
  lUcAngleUcToken @1 :TokenOffset;
  memberUcToken @2 :TokenOffset;
  operatorUcToken @3 :TokenOffset;
  rUcAngleUcToken @4 :TokenOffset;
  templateUcKeywordUcToken @5 :TokenOffset;
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
  rUcBracketUcToken @1 :TokenOffset;
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
  rUcBracketUcToken @1 :TokenOffset;
}

struct MSPropertyRefExpr @0xb14da9f10b21425d {
  expr @0:Expr;
  memberUcToken @1 :TokenOffset;
  isUcArrow @2 :Bool;
  isUcImplicitUcAccess @3 :Bool;
}

struct LambdaExpr @0xd1773aeaaf57de49 {
  expr @0:Expr;
  captureUcDefault @1 :LambdaCaptureDefault;
  captureUcDefaultUcToken @2 :TokenOffset;
  introducerUcRange @3 :TokenRange;
  hasUcExplicitUcParameters @4 :Bool;
  hasUcExplicitUcResultUcType @5 :Bool;
  isUcGenericUcLambda @6 :Bool;
  isUcMutable @7 :Bool;
}

struct IntegerLiteral @0x9555503bb691c665 {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct InitListExpr @0xee5bc39a46a85bfd {
  expr @0:Expr;
  lUcBraceUcToken @1 :TokenOffset;
  rUcBraceUcToken @2 :TokenOffset;
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
  defaultUcToken @1 :TokenOffset;
  genericUcToken @2 :TokenOffset;
  rUcParenUcToken @3 :TokenOffset;
  isUcResultUcDependent @4 :Bool;
}

struct GNUNullExpr @0xed67a32bfb3e1820 {
  expr @0:Expr;
  tokenUcToken @1 :TokenOffset;
}

struct FunctionParmPackExpr @0x9b1418ed71492c60 {
  expr @0:Expr;
  parameterUcPackUcToken @1 :TokenOffset;
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
  resultUcApUcValueUcKind @1 :APValueKind;
  resultUcStorageUcKind @2 :ResultStorageKind;
  hasUcApUcValueUcResult @3 :Bool;
  isUcImmediateUcInvocation @4 :Bool;
}

struct FloatingLiteral @0xf9afab4b69f8f504 {
  expr @0:Expr;
  token @1 :TokenOffset;
  isUcExact @2 :Bool;
}

struct FixedPointLiteral @0xb376f274c18baf5a {
  expr @0:Expr;
  token @1 :TokenOffset;
}

struct ExtVectorElementExpr @0xba6c9e86786ed31a {
  expr @0:Expr;
  containsUcDuplicateUcElements @1 :Bool;
  accessorUcToken @2 :TokenOffset;
  isUcArrow @3 :Bool;
}

struct ExpressionTraitExpr @0xf53890283fc830c0 {
  expr @0:Expr;
  trait @1 :ExpressionTrait;
  value @2 :Bool;
}

struct AttributedStmt @0xc33cd79cc9238608 {
  valueUcStmt @0:ValueStmt;
  attributeUcToken @1 :TokenOffset;
}

struct SwitchStmt @0x8f2566a2d81612cd {
  stmt @0:Stmt;
  lUcParenUcToken @1 :TokenOffset;
  rUcParenUcToken @2 :TokenOffset;
  switchUcToken @3 :TokenOffset;
  hasUcInitializerUcStorage @4 :Bool;
  hasUcVariableUcStorage @5 :Bool;
  isUcAllUcEnumUcCasesUcCovered @6 :Bool;
}

struct SwitchCase @0xeecb8bb11e4c8ed7 {
  stmt @0:Stmt;
  colonUcToken @1 :TokenOffset;
  keywordUcToken @2 :TokenOffset;
}

struct DefaultStmt @0xf8ae119f01317845 {
  switchUcCase @0:SwitchCase;
  defaultUcToken @1 :TokenOffset;
}

struct CaseStmt @0x829897c890006599 {
  switchUcCase @0:SwitchCase;
  caseUcStatementUcIsUcGnuUcRange @1 :Bool;
  caseUcToken @2 :TokenOffset;
  ellipsisUcToken @3 :TokenOffset;
}

struct Type @0xd739e808bc1b3fd7 {
  acceptsUcObjUcCUcTypeUcParams @0 :Bool;
  canUcDecayUcToUcPointerUcType @1 :Bool;
  canUcHaveUcNullability @2 :Bool;
  containsUcErrors @3 :Bool;
  containsUcUnexpandedUcParameterUcPack @4 :Bool;
  dependence @5 :TypeDependence;
  linkage @6 :Linkage;
  objUcCarcUcImplicitUcLifetime @7 :ObjCLifetime;
  scalarUcTypeUcKind @8 :ScalarTypeKind;
  kind @9 :TypeKind;
  visibility @10 :Visibility;
  hasUcAutoUcForUcTrailingUcReturnUcType @11 :Bool;
  hasUcFloatingUcRepresentation @12 :Bool;
  hasUcIntegerUcRepresentation @13 :Bool;
  hasUcObjUcCUcPointerUcRepresentation @14 :Bool;
  hasUcPointerUcRepresentation @15 :Bool;
  hasUcSignedUcIntegerUcRepresentation @16 :Bool;
  hasUcSizedUcVlaUcType @17 :Bool;
  hasUcUnnamedUcOrUcLocalUcType @18 :Bool;
  hasUcUnsignedUcIntegerUcRepresentation @19 :Bool;
  isUcAggregateUcType @20 :Bool;
  isUcAlignUcValUcT @21 :Bool;
  isUcAnyUcCharacterUcType @22 :Bool;
  isUcAnyUcComplexUcType @23 :Bool;
  isUcAnyUcPointerUcType @24 :Bool;
  isUcArithmeticUcType @25 :Bool;
  isUcArrayUcType @26 :Bool;
  isUcAtomicUcType @27 :Bool;
  isUcBUcFloat16UcType @28 :Bool;
  isUcBlockUcCompatibleUcObjUcCUcPointerUcType @29 :Bool;
  isUcBlockUcPointerUcType @30 :Bool;
  isUcBooleanUcType @31 :Bool;
  isUcBuiltinUcType @32 :Bool;
  isUcCarcUcBridgableUcType @33 :Bool;
  isUcCudaUcDeviceUcBuiltinUcSurfaceUcType @34 :Bool;
  isUcCudaUcDeviceUcBuiltinUcTextureUcType @35 :Bool;
  isUcCanonicalUcUnqualified @36 :Bool;
  isUcChar16UcType @37 :Bool;
  isUcChar32UcType @38 :Bool;
  isUcChar8UcType @39 :Bool;
  isUcCharacterUcType @40 :Bool;
  isUcClassUcType @41 :Bool;
  isUcClkUcEventUcT @42 :Bool;
  isUcComplexUcIntegerUcType @43 :Bool;
  isUcComplexUcType @44 :Bool;
  isUcCompoundUcType @45 :Bool;
  isUcConstantUcArrayUcType @46 :Bool;
  isUcConstantUcMatrixUcType @47 :Bool;
  isUcConstantUcSizeUcType @48 :Bool;
  isUcDecltypeUcType @49 :Bool;
  isUcDependentUcAddressUcSpaceUcType @50 :Bool;
  isUcDependentUcSizedUcArrayUcType @51 :Bool;
  isUcDependentUcType @52 :Bool;
  isUcElaboratedUcTypeUcSpecifier @53 :Bool;
  isUcEnumeralUcType @54 :Bool;
  isUcEventUcT @55 :Bool;
  isUcExtUcIntUcType @56 :Bool;
  isUcExtUcVectorUcType @57 :Bool;
  isUcFixedUcPointUcOrUcIntegerUcType @58 :Bool;
  isUcFixedUcPointUcType @59 :Bool;
  isUcFloat128UcType @60 :Bool;
  isUcFloat16UcType @61 :Bool;
  isUcFloatingUcType @62 :Bool;
  isUcFromUcAst @63 :Bool;
  isUcFunctionUcNoUcProtoUcType @64 :Bool;
  isUcFunctionUcPointerUcType @65 :Bool;
  isUcFunctionUcProtoUcType @66 :Bool;
  isUcFunctionUcReferenceUcType @67 :Bool;
  isUcFunctionUcType @68 :Bool;
  isUcFundamentalUcType @69 :Bool;
  isUcHalfUcType @70 :Bool;
  isUcImageUcType @71 :Bool;
  isUcIncompleteUcArrayUcType @72 :Bool;
  isUcIncompleteUcOrUcObjectUcType @73 :Bool;
  isUcIncompleteUcType @74 :Bool;
  isUcInstantiationUcDependentUcType @75 :Bool;
  isUcIntegerUcType @76 :Bool;
  isUcIntegralUcOrUcEnumerationUcType @77 :Bool;
  isUcIntegralUcOrUcUnscopedUcEnumerationUcType @78 :Bool;
  isUcIntegralUcType @79 :Bool;
  isUcInterfaceUcType @80 :Bool;
  isUcLUcValueUcReferenceUcType @81 :Bool;
  isUcLinkageUcValid @82 :Bool;
  isUcLiteralUcType @83 :Bool;
  isUcMatrixUcType @84 :Bool;
  isUcMemberUcDataUcPointerUcType @85 :Bool;
  isUcMemberUcFunctionUcPointerUcType @86 :Bool;
  isUcMemberUcPointerUcType @87 :Bool;
  isUcNonUcOverloadUcPlaceholderUcType @88 :Bool;
  isUcNothrowUcT @89 :Bool;
  isUcNullUcPointerUcType @90 :Bool;
  isUcOclUcExtUcOpaqueUcType @91 :Bool;
  isUcOclUcImage1dUcArrayUcRoUcType @92 :Bool;
  isUcOclUcImage1dUcArrayUcRwUcType @93 :Bool;
  isUcOclUcImage1dUcArrayUcWoUcType @94 :Bool;
  isUcOclUcImage1dUcBufferUcRoUcType @95 :Bool;
  isUcOclUcImage1dUcBufferUcRwUcType @96 :Bool;
  isUcOclUcImage1dUcBufferUcWoUcType @97 :Bool;
  isUcOclUcImage1dUcRoUcType @98 :Bool;
  isUcOclUcImage1dUcRwUcType @99 :Bool;
  isUcOclUcImage1dUcWoUcType @100 :Bool;
  isUcOclUcImage2dUcArrayUcDepthUcRoUcType @101 :Bool;
  isUcOclUcImage2dUcArrayUcDepthUcRwUcType @102 :Bool;
  isUcOclUcImage2dUcArrayUcDepthUcWoUcType @103 :Bool;
  isUcOclUcImage2dUcArrayUcMsaaUcDepthUcRoUcType @104 :Bool;
  isUcOclUcImage2dUcArrayUcMsaaUcDepthUcRwUcType @105 :Bool;
  isUcOclUcImage2dUcArrayUcMsaaUcDepthUcWoUcType @106 :Bool;
  isUcOclUcImage2dUcArrayUcMsaaroUcType @107 :Bool;
  isUcOclUcImage2dUcArrayUcMsaarwUcType @108 :Bool;
  isUcOclUcImage2dUcArrayUcMsaawoUcType @109 :Bool;
  isUcOclUcImage2dUcArrayUcRoUcType @110 :Bool;
  isUcOclUcImage2dUcArrayUcRwUcType @111 :Bool;
  isUcOclUcImage2dUcArrayUcWoUcType @112 :Bool;
  isUcOclUcImage2dUcDepthUcRoUcType @113 :Bool;
  isUcOclUcImage2dUcDepthUcRwUcType @114 :Bool;
  isUcOclUcImage2dUcDepthUcWoUcType @115 :Bool;
  isUcOclUcImage2dUcMsaaUcDepthUcRoUcType @116 :Bool;
  isUcOclUcImage2dUcMsaaUcDepthUcRwUcType @117 :Bool;
  isUcOclUcImage2dUcMsaaUcDepthUcWoUcType @118 :Bool;
  isUcOclUcImage2dUcMsaaroUcType @119 :Bool;
  isUcOclUcImage2dUcMsaarwUcType @120 :Bool;
  isUcOclUcImage2dUcMsaawoUcType @121 :Bool;
  isUcOclUcImage2dUcRoUcType @122 :Bool;
  isUcOclUcImage2dUcRwUcType @123 :Bool;
  isUcOclUcImage2dUcWoUcType @124 :Bool;
  isUcOclUcImage3dUcRoUcType @125 :Bool;
  isUcOclUcImage3dUcRwUcType @126 :Bool;
  isUcOclUcImage3dUcWoUcType @127 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcDualUcReferenceUcStreaminUcType @128 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcPayloadUcType @129 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcResultUcDualUcReferenceUcStreamoutUcType @130 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcResultUcSingleUcReferenceUcStreamoutUcType @131 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcResultUcType @132 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcImeUcSingleUcReferenceUcStreaminUcType @133 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcMceUcPayloadUcType @134 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcMceUcResultUcType @135 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcRefUcPayloadUcType @136 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcRefUcResultUcType @137 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcSicUcPayloadUcType @138 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcSicUcResultUcType @139 :Bool;
  isUcOclUcIntelUcSubgroupUcAvcUcType @140 :Bool;
  isUcObjUcCarcUcBridgableUcType @141 :Bool;
  isUcObjUcCarcUcImplicitlyUcUnretainedUcType @142 :Bool;
  isUcObjUcCUcBoxableUcRecordUcType @143 :Bool;
  isUcObjUcCUcBuiltinUcType @144 :Bool;
  isUcObjUcCUcClassUcOrUcClassUcKindUcOfUcType @145 :Bool;
  isUcObjUcCUcClassUcType @146 :Bool;
  isUcObjUcCUcIdUcType @147 :Bool;
  isUcObjUcCUcIndependentUcClassUcType @148 :Bool;
  isUcObjUcCUcIndirectUcLifetimeUcType @149 :Bool;
  isUcObjUcCUcInertUcUnsafeUcUnretainedUcType @150 :Bool;
  isUcObjUcCUcLifetimeUcType @151 :Bool;
  isUcObjUcCnsUcObjectUcType @152 :Bool;
  isUcObjUcCUcObjectUcOrUcInterfaceUcType @153 :Bool;
  isUcObjUcCUcObjectUcPointerUcType @154 :Bool;
  isUcObjUcCUcObjectUcType @155 :Bool;
  isUcObjUcCUcQualifiedUcClassUcType @156 :Bool;
  isUcObjUcCUcQualifiedUcIdUcType @157 :Bool;
  isUcObjUcCUcQualifiedUcInterfaceUcType @158 :Bool;
  isUcObjUcCUcRetainableUcType @159 :Bool;
  isUcObjUcCUcSelUcType @160 :Bool;
  isUcObjectUcPointerUcType @161 :Bool;
  isUcObjectUcType @162 :Bool;
  isUcOpenUcClUcSpecificUcType @163 :Bool;
  isUcOverloadableUcType @164 :Bool;
  isUcPipeUcType @165 :Bool;
  isUcPlaceholderUcType @166 :Bool;
  isUcPointerUcType @167 :Bool;
  isUcPromotableUcIntegerUcType @168 :Bool;
  isUcQueueUcT @169 :Bool;
  isUcRUcValueUcReferenceUcType @170 :Bool;
  isUcRealUcFloatingUcType @171 :Bool;
  isUcRealUcType @172 :Bool;
  isUcRecordUcType @173 :Bool;
  isUcReferenceUcType @174 :Bool;
  isUcReserveUcIdt @175 :Bool;
  isUcSamplerUcT @176 :Bool;
  isUcSaturatedUcFixedUcPointUcType @177 :Bool;
  isUcScalarUcType @178 :Bool;
  isUcScopedUcEnumeralUcType @179 :Bool;
  isUcSignedUcFixedUcPointUcType @180 :Bool;
  isUcSignedUcIntegerUcOrUcEnumerationUcType @181 :Bool;
  isUcSignedUcIntegerUcType @182 :Bool;
  isUcSizelessUcBuiltinUcType @183 :Bool;
  isUcSizelessUcType @184 :Bool;
  isUcSpecifierUcType @185 :Bool;
  isUcStandardUcLayoutUcType @186 :Bool;
  isUcStdUcByteUcType @187 :Bool;
  isUcStructuralUcType @188 :Bool;
  isUcStructureUcOrUcClassUcType @189 :Bool;
  isUcStructureUcType @190 :Bool;
  isUcTemplateUcTypeUcParmUcType @191 :Bool;
  isUcTypedefUcNameUcType @192 :Bool;
  isUcUndeducedUcAutoUcType @193 :Bool;
  isUcUndeducedUcType @194 :Bool;
  isUcUnionUcType @195 :Bool;
  isUcUnsaturatedUcFixedUcPointUcType @196 :Bool;
  isUcUnscopedUcEnumerationUcType @197 :Bool;
  isUcUnsignedUcFixedUcPointUcType @198 :Bool;
  isUcUnsignedUcIntegerUcOrUcEnumerationUcType @199 :Bool;
  isUcUnsignedUcIntegerUcType @200 :Bool;
  isUcVlstUcBuiltinUcType @201 :Bool;
  isUcVariableUcArrayUcType @202 :Bool;
  isUcVariablyUcModifiedUcType @203 :Bool;
  isUcVectorUcType @204 :Bool;
  isUcVisibilityUcExplicit @205 :Bool;
  isUcVoidUcPointerUcType @206 :Bool;
  isUcVoidUcType @207 :Bool;
  isUcWideUcCharacterUcType @208 :Bool;
  isUcQualified @209 :Bool;
  addressUcSpace @210 :LangAS;
  objUcCUcLifetime @211 :ObjCLifetime;
  hasUcAddressUcSpace @212 :Bool;
  hasUcLocalUcNonUcFastUcQualifiers @213 :Bool;
  hasUcLocalUcQualifiers @214 :Bool;
  hasUcNonUcTrivialUcObjUcCUcLifetime @215 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcCopyUcCUcUnion @216 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitializeUcCUcUnion @217 :Bool;
  hasUcNonUcTrivialUcToUcPrimitiveUcDestructUcCUcUnion @218 :Bool;
  hasUcQualifiers @219 :Bool;
  hasUcStrongUcOrUcWeakUcObjUcCUcLifetime @220 :Bool;
  isUcCUcForbiddenUcLUcValueUcType @221 :Bool;
  isUcCxx11UcPodUcType @222 :Bool;
  isUcCxx98UcPodUcType @223 :Bool;
  isUcCanonical @224 :Bool;
  isUcCanonicalUcAsUcParam @225 :Bool;
  isUcConstUcQualified @226 :Bool;
  isUcConstant @227 :Bool;
  isUcLocalUcConstUcQualified @228 :Bool;
  isUcLocalUcRestrictUcQualified @229 :Bool;
  isUcLocalUcVolatileUcQualified @230 :Bool;
  isUcNonUcTrivialUcToUcPrimitiveUcCopy @231 :PrimitiveCopyKind;
  isUcNonUcTrivialUcToUcPrimitiveUcDefaultUcInitialize @232 :PrimitiveDefaultInitializeKind;
  isUcNonUcTrivialUcToUcPrimitiveUcDestructiveUcMove @233 :PrimitiveCopyKind;
  isUcNonUcWeakUcInUcMrrUcWithUcObjUcCUcWeak @234 :Bool;
  isUcNull @235 :Bool;
  isUcObjUcCgcUcStrong @236 :Bool;
  isUcObjUcCgcUcWeak @237 :Bool;
  isUcPodUcType @238 :Bool;
  isUcRestrictUcQualified @239 :Bool;
  isUcTrivialUcType @240 :Bool;
  isUcTriviallyUcCopyableUcType @241 :Bool;
  isUcVolatileUcQualified @242 :Bool;
  mayUcBeUcDynamicUcClass @243 :Bool;
  mayUcBeUcNotUcDynamicUcClass @244 :Bool;
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
  attributeUcToken @1 :TokenOffset;
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
  ellipsisUcToken @2 :TokenOffset;
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
  attributeUcToken @1 :TokenOffset;
  vectorUcKind @2 :VectorKind;
  isUcSugared @3 :Bool;
}

struct DependentSizedExtVectorType @0xd1e2872240f527b7 {
  type @0:Type;
  attributeUcToken @1 :TokenOffset;
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
  attributeUcToken @1 :TokenOffset;
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
  sizeUcModifier @1 :ArraySizeModifier;
}

struct VariableArrayType @0x82d4d76c013109f5 {
  arrayUcType @0:ArrayType;
  bracketsUcRange @1 :TokenRange;
  lUcBracketUcToken @2 :TokenOffset;
  rUcBracketUcToken @3 :TokenOffset;
  isUcSugared @4 :Bool;
}

struct IncompleteArrayType @0xd4f7a93527ce975e {
  arrayUcType @0:ArrayType;
  isUcSugared @1 :Bool;
}

struct DependentSizedArrayType @0xeb3238fd4299c322 {
  arrayUcType @0:ArrayType;
  bracketsUcRange @1 :TokenRange;
  lUcBracketUcToken @2 :TokenOffset;
  rUcBracketUcToken @3 :TokenOffset;
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
  vectorUcKind @1 :VectorKind;
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
  uttUcKind @1 :UTTKind;
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
  token @0 :List(Token);
  decl @1 :List(Decl);
  classUcScopeUcFunctionUcSpecializationUcDecl @2 :List(ClassScopeFunctionSpecializationDecl);
  capturedUcDecl @3 :List(CapturedDecl);
  blockUcDecl @4 :List(BlockDecl);
  accessUcSpecUcDecl @5 :List(AccessSpecDecl);
  translationUcUnitUcDecl @6 :List(TranslationUnitDecl);
  staticUcAssertUcDecl @7 :List(StaticAssertDecl);
  requiresUcExprUcBodyUcDecl @8 :List(RequiresExprBodyDecl);
  pragmaUcDetectUcMismatchUcDecl @9 :List(PragmaDetectMismatchDecl);
  pragmaUcCommentUcDecl @10 :List(PragmaCommentDecl);
  objUcCUcPropertyUcImplUcDecl @11 :List(ObjCPropertyImplDecl);
  namedUcDecl @12 :List(NamedDecl);
  labelUcDecl @13 :List(LabelDecl);
  baseUcUsingUcDecl @14 :List(BaseUsingDecl);
  usingUcEnumUcDecl @15 :List(UsingEnumDecl);
  usingUcDecl @16 :List(UsingDecl);
  valueUcDecl @17 :List(ValueDecl);
  unresolvedUcUsingUcValueUcDecl @18 :List(UnresolvedUsingValueDecl);
  templateUcParamUcObjectUcDecl @19 :List(TemplateParamObjectDecl);
  ompUcDeclareUcReductionUcDecl @20 :List(OMPDeclareReductionDecl);
  msUcGuidUcDecl @21 :List(MSGuidDecl);
  indirectUcFieldUcDecl @22 :List(IndirectFieldDecl);
  enumUcConstantUcDecl @23 :List(EnumConstantDecl);
  declaratorUcDecl @24 :List(DeclaratorDecl);
  varUcDecl @25 :List(VarDecl);
  parmUcVarUcDecl @26 :List(ParmVarDecl);
  ompUcCapturedUcExprUcDecl @27 :List(OMPCapturedExprDecl);
  implicitUcParamUcDecl @28 :List(ImplicitParamDecl);
  decompositionUcDecl @29 :List(DecompositionDecl);
  varUcTemplateUcSpecializationUcDecl @30 :List(VarTemplateSpecializationDecl);
  varUcTemplateUcPartialUcSpecializationUcDecl @31 :List(VarTemplatePartialSpecializationDecl);
  nonUcTypeUcTemplateUcParmUcDecl @32 :List(NonTypeTemplateParmDecl);
  msUcPropertyUcDecl @33 :List(MSPropertyDecl);
  functionUcDecl @34 :List(FunctionDecl);
  cxxUcMethodUcDecl @35 :List(CXXMethodDecl);
  cxxUcDestructorUcDecl @36 :List(CXXDestructorDecl);
  cxxUcConversionUcDecl @37 :List(CXXConversionDecl);
  cxxUcConstructorUcDecl @38 :List(CXXConstructorDecl);
  cxxUcDeductionUcGuideUcDecl @39 :List(CXXDeductionGuideDecl);
  fieldUcDecl @40 :List(FieldDecl);
  objUcCUcIvarUcDecl @41 :List(ObjCIvarDecl);
  objUcCUcAtUcDefsUcFieldUcDecl @42 :List(ObjCAtDefsFieldDecl);
  bindingUcDecl @43 :List(BindingDecl);
  usingUcShadowUcDecl @44 :List(UsingShadowDecl);
  constructorUcUsingUcShadowUcDecl @45 :List(ConstructorUsingShadowDecl);
  usingUcPackUcDecl @46 :List(UsingPackDecl);
  usingUcDirectiveUcDecl @47 :List(UsingDirectiveDecl);
  unresolvedUcUsingUcIfUcExistsUcDecl @48 :List(UnresolvedUsingIfExistsDecl);
  typeUcDecl @49 :List(TypeDecl);
  templateUcTypeUcParmUcDecl @50 :List(TemplateTypeParmDecl);
  tagUcDecl @51 :List(TagDecl);
  recordUcDecl @52 :List(RecordDecl);
  cxxUcRecordUcDecl @53 :List(CXXRecordDecl);
  classUcTemplateUcSpecializationUcDecl @54 :List(ClassTemplateSpecializationDecl);
  classUcTemplateUcPartialUcSpecializationUcDecl @55 :List(ClassTemplatePartialSpecializationDecl);
  enumUcDecl @56 :List(EnumDecl);
  unresolvedUcUsingUcTypenameUcDecl @57 :List(UnresolvedUsingTypenameDecl);
  typedefUcNameUcDecl @58 :List(TypedefNameDecl);
  typedefUcDecl @59 :List(TypedefDecl);
  typeUcAliasUcDecl @60 :List(TypeAliasDecl);
  objUcCUcTypeUcParamUcDecl @61 :List(ObjCTypeParamDecl);
  templateUcDecl @62 :List(TemplateDecl);
  redeclarableUcTemplateUcDecl @63 :List(RedeclarableTemplateDecl);
  functionUcTemplateUcDecl @64 :List(FunctionTemplateDecl);
  classUcTemplateUcDecl @65 :List(ClassTemplateDecl);
  varUcTemplateUcDecl @66 :List(VarTemplateDecl);
  typeUcAliasUcTemplateUcDecl @67 :List(TypeAliasTemplateDecl);
  conceptUcDecl @68 :List(ConceptDecl);
  builtinUcTemplateUcDecl @69 :List(BuiltinTemplateDecl);
  templateUcTemplateUcParmUcDecl @70 :List(TemplateTemplateParmDecl);
  objUcCUcPropertyUcDecl @71 :List(ObjCPropertyDecl);
  objUcCUcMethodUcDecl @72 :List(ObjCMethodDecl);
  objUcCUcContainerUcDecl @73 :List(ObjCContainerDecl);
  objUcCUcCategoryUcDecl @74 :List(ObjCCategoryDecl);
  objUcCUcProtocolUcDecl @75 :List(ObjCProtocolDecl);
  objUcCUcInterfaceUcDecl @76 :List(ObjCInterfaceDecl);
  objUcCUcImplUcDecl @77 :List(ObjCImplDecl);
  objUcCUcCategoryUcImplUcDecl @78 :List(ObjCCategoryImplDecl);
  objUcCUcImplementationUcDecl @79 :List(ObjCImplementationDecl);
  objUcCUcCompatibleUcAliasUcDecl @80 :List(ObjCCompatibleAliasDecl);
  namespaceUcDecl @81 :List(NamespaceDecl);
  namespaceUcAliasUcDecl @82 :List(NamespaceAliasDecl);
  linkageUcSpecUcDecl @83 :List(LinkageSpecDecl);
  lifetimeUcExtendedUcTemporaryUcDecl @84 :List(LifetimeExtendedTemporaryDecl);
  importUcDecl @85 :List(ImportDecl);
  friendUcTemplateUcDecl @86 :List(FriendTemplateDecl);
  friendUcDecl @87 :List(FriendDecl);
  fileUcScopeUcAsmUcDecl @88 :List(FileScopeAsmDecl);
  externUcCUcContextUcDecl @89 :List(ExternCContextDecl);
  exportUcDecl @90 :List(ExportDecl);
  emptyUcDecl @91 :List(EmptyDecl);
  stmt @92 :List(Stmt);
  sehUcTryUcStmt @93 :List(SEHTryStmt);
  sehUcLeaveUcStmt @94 :List(SEHLeaveStmt);
  sehUcFinallyUcStmt @95 :List(SEHFinallyStmt);
  sehUcExceptUcStmt @96 :List(SEHExceptStmt);
  returnUcStmt @97 :List(ReturnStmt);
  objUcCUcForUcCollectionUcStmt @98 :List(ObjCForCollectionStmt);
  objUcCUcAutoreleaseUcPoolUcStmt @99 :List(ObjCAutoreleasePoolStmt);
  objUcCUcAtUcTryUcStmt @100 :List(ObjCAtTryStmt);
  objUcCUcAtUcThrowUcStmt @101 :List(ObjCAtThrowStmt);
  objUcCUcAtUcSynchronizedUcStmt @102 :List(ObjCAtSynchronizedStmt);
  objUcCUcAtUcFinallyUcStmt @103 :List(ObjCAtFinallyStmt);
  objUcCUcAtUcCatchUcStmt @104 :List(ObjCAtCatchStmt);
  ompUcExecutableUcDirective @105 :List(OMPExecutableDirective);
  ompUcDispatchUcDirective @106 :List(OMPDispatchDirective);
  ompUcDepobjUcDirective @107 :List(OMPDepobjDirective);
  ompUcCriticalUcDirective @108 :List(OMPCriticalDirective);
  ompUcCancellationUcPointUcDirective @109 :List(OMPCancellationPointDirective);
  ompUcCancelUcDirective @110 :List(OMPCancelDirective);
  ompUcBarrierUcDirective @111 :List(OMPBarrierDirective);
  ompUcAtomicUcDirective @112 :List(OMPAtomicDirective);
  ompUcTeamsUcDirective @113 :List(OMPTeamsDirective);
  ompUcTaskyieldUcDirective @114 :List(OMPTaskyieldDirective);
  ompUcTaskwaitUcDirective @115 :List(OMPTaskwaitDirective);
  ompUcTaskgroupUcDirective @116 :List(OMPTaskgroupDirective);
  ompUcTaskUcDirective @117 :List(OMPTaskDirective);
  ompUcTargetUcUpdateUcDirective @118 :List(OMPTargetUpdateDirective);
  ompUcTargetUcTeamsUcDirective @119 :List(OMPTargetTeamsDirective);
  ompUcTargetUcParallelUcDirective @120 :List(OMPTargetParallelDirective);
  ompUcTargetUcExitUcDataUcDirective @121 :List(OMPTargetExitDataDirective);
  ompUcTargetUcEnterUcDataUcDirective @122 :List(OMPTargetEnterDataDirective);
  ompUcTargetUcDirective @123 :List(OMPTargetDirective);
  ompUcTargetUcDataUcDirective @124 :List(OMPTargetDataDirective);
  ompUcSingleUcDirective @125 :List(OMPSingleDirective);
  ompUcSectionsUcDirective @126 :List(OMPSectionsDirective);
  ompUcSectionUcDirective @127 :List(OMPSectionDirective);
  ompUcScanUcDirective @128 :List(OMPScanDirective);
  ompUcParallelUcSectionsUcDirective @129 :List(OMPParallelSectionsDirective);
  ompUcParallelUcMasterUcDirective @130 :List(OMPParallelMasterDirective);
  ompUcParallelUcDirective @131 :List(OMPParallelDirective);
  ompUcOrderedUcDirective @132 :List(OMPOrderedDirective);
  ompUcMasterUcDirective @133 :List(OMPMasterDirective);
  ompUcMaskedUcDirective @134 :List(OMPMaskedDirective);
  ompUcLoopUcBasedUcDirective @135 :List(OMPLoopBasedDirective);
  ompUcUnrollUcDirective @136 :List(OMPUnrollDirective);
  ompUcTileUcDirective @137 :List(OMPTileDirective);
  ompUcLoopUcDirective @138 :List(OMPLoopDirective);
  ompUcForUcSimdUcDirective @139 :List(OMPForSimdDirective);
  ompUcForUcDirective @140 :List(OMPForDirective);
  ompUcDistributeUcSimdUcDirective @141 :List(OMPDistributeSimdDirective);
  ompUcDistributeUcParallelUcForUcSimdUcDirective @142 :List(OMPDistributeParallelForSimdDirective);
  ompUcDistributeUcParallelUcForUcDirective @143 :List(OMPDistributeParallelForDirective);
  ompUcDistributeUcDirective @144 :List(OMPDistributeDirective);
  ompUcTeamsUcDistributeUcSimdUcDirective @145 :List(OMPTeamsDistributeSimdDirective);
  ompUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @146 :List(OMPTeamsDistributeParallelForSimdDirective);
  ompUcTeamsUcDistributeUcParallelUcForUcDirective @147 :List(OMPTeamsDistributeParallelForDirective);
  ompUcTeamsUcDistributeUcDirective @148 :List(OMPTeamsDistributeDirective);
  ompUcTaskUcLoopUcSimdUcDirective @149 :List(OMPTaskLoopSimdDirective);
  ompUcTaskUcLoopUcDirective @150 :List(OMPTaskLoopDirective);
  ompUcTargetUcTeamsUcDistributeUcSimdUcDirective @151 :List(OMPTargetTeamsDistributeSimdDirective);
  ompUcTargetUcTeamsUcDistributeUcParallelUcForUcSimdUcDirective @152 :List(OMPTargetTeamsDistributeParallelForSimdDirective);
  ompUcTargetUcTeamsUcDistributeUcParallelUcForUcDirective @153 :List(OMPTargetTeamsDistributeParallelForDirective);
  ompUcTargetUcTeamsUcDistributeUcDirective @154 :List(OMPTargetTeamsDistributeDirective);
  ompUcTargetUcSimdUcDirective @155 :List(OMPTargetSimdDirective);
  ompUcTargetUcParallelUcForUcSimdUcDirective @156 :List(OMPTargetParallelForSimdDirective);
  ompUcTargetUcParallelUcForUcDirective @157 :List(OMPTargetParallelForDirective);
  ompUcSimdUcDirective @158 :List(OMPSimdDirective);
  ompUcParallelUcMasterUcTaskUcLoopUcSimdUcDirective @159 :List(OMPParallelMasterTaskLoopSimdDirective);
  ompUcParallelUcMasterUcTaskUcLoopUcDirective @160 :List(OMPParallelMasterTaskLoopDirective);
  ompUcParallelUcForUcSimdUcDirective @161 :List(OMPParallelForSimdDirective);
  ompUcParallelUcForUcDirective @162 :List(OMPParallelForDirective);
  ompUcMasterUcTaskUcLoopUcSimdUcDirective @163 :List(OMPMasterTaskLoopSimdDirective);
  ompUcMasterUcTaskUcLoopUcDirective @164 :List(OMPMasterTaskLoopDirective);
  ompUcInteropUcDirective @165 :List(OMPInteropDirective);
  ompUcFlushUcDirective @166 :List(OMPFlushDirective);
  ompUcCanonicalUcLoop @167 :List(OMPCanonicalLoop);
  nullUcStmt @168 :List(NullStmt);
  msUcDependentUcExistsUcStmt @169 :List(MSDependentExistsStmt);
  indirectUcGotoUcStmt @170 :List(IndirectGotoStmt);
  ifUcStmt @171 :List(IfStmt);
  gotoUcStmt @172 :List(GotoStmt);
  forUcStmt @173 :List(ForStmt);
  doUcStmt @174 :List(DoStmt);
  declUcStmt @175 :List(DeclStmt);
  coroutineUcBodyUcStmt @176 :List(CoroutineBodyStmt);
  coreturnUcStmt @177 :List(CoreturnStmt);
  continueUcStmt @178 :List(ContinueStmt);
  compoundUcStmt @179 :List(CompoundStmt);
  capturedUcStmt @180 :List(CapturedStmt);
  cxxUcTryUcStmt @181 :List(CXXTryStmt);
  cxxUcForUcRangeUcStmt @182 :List(CXXForRangeStmt);
  cxxUcCatchUcStmt @183 :List(CXXCatchStmt);
  breakUcStmt @184 :List(BreakStmt);
  asmUcStmt @185 :List(AsmStmt);
  msUcAsmUcStmt @186 :List(MSAsmStmt);
  gccUcAsmUcStmt @187 :List(GCCAsmStmt);
  whileUcStmt @188 :List(WhileStmt);
  valueUcStmt @189 :List(ValueStmt);
  labelUcStmt @190 :List(LabelStmt);
  expr @191 :List(Expr);
  designatedUcInitUcUpdateUcExpr @192 :List(DesignatedInitUpdateExpr);
  designatedUcInitUcExpr @193 :List(DesignatedInitExpr);
  dependentUcScopeUcDeclUcRefUcExpr @194 :List(DependentScopeDeclRefExpr);
  dependentUcCoawaitUcExpr @195 :List(DependentCoawaitExpr);
  declUcRefUcExpr @196 :List(DeclRefExpr);
  coroutineUcSuspendUcExpr @197 :List(CoroutineSuspendExpr);
  coawaitUcExpr @198 :List(CoawaitExpr);
  coyieldUcExpr @199 :List(CoyieldExpr);
  convertUcVectorUcExpr @200 :List(ConvertVectorExpr);
  conceptUcSpecializationUcExpr @201 :List(ConceptSpecializationExpr);
  compoundUcLiteralUcExpr @202 :List(CompoundLiteralExpr);
  chooseUcExpr @203 :List(ChooseExpr);
  characterUcLiteral @204 :List(CharacterLiteral);
  castUcExpr @205 :List(CastExpr);
  implicitUcCastUcExpr @206 :List(ImplicitCastExpr);
  explicitUcCastUcExpr @207 :List(ExplicitCastExpr);
  cxxUcNamedUcCastUcExpr @208 :List(CXXNamedCastExpr);
  cxxUcDynamicUcCastUcExpr @209 :List(CXXDynamicCastExpr);
  cxxUcConstUcCastUcExpr @210 :List(CXXConstCastExpr);
  cxxUcAddrspaceUcCastUcExpr @211 :List(CXXAddrspaceCastExpr);
  cxxUcStaticUcCastUcExpr @212 :List(CXXStaticCastExpr);
  cxxUcReinterpretUcCastUcExpr @213 :List(CXXReinterpretCastExpr);
  cxxUcFunctionalUcCastUcExpr @214 :List(CXXFunctionalCastExpr);
  cUcStyleUcCastUcExpr @215 :List(CStyleCastExpr);
  builtinUcBitUcCastUcExpr @216 :List(BuiltinBitCastExpr);
  objUcCUcBridgedUcCastUcExpr @217 :List(ObjCBridgedCastExpr);
  callUcExpr @218 :List(CallExpr);
  cxxUcOperatorUcCallUcExpr @219 :List(CXXOperatorCallExpr);
  cxxUcMemberUcCallUcExpr @220 :List(CXXMemberCallExpr);
  cudaUcKernelUcCallUcExpr @221 :List(CUDAKernelCallExpr);
  userUcDefinedUcLiteral @222 :List(UserDefinedLiteral);
  cxxUcUuidofUcExpr @223 :List(CXXUuidofExpr);
  cxxUcUnresolvedUcConstructUcExpr @224 :List(CXXUnresolvedConstructExpr);
  cxxUcTypeidUcExpr @225 :List(CXXTypeidExpr);
  cxxUcThrowUcExpr @226 :List(CXXThrowExpr);
  cxxUcThisUcExpr @227 :List(CXXThisExpr);
  cxxUcStdUcInitializerUcListUcExpr @228 :List(CXXStdInitializerListExpr);
  cxxUcScalarUcValueUcInitUcExpr @229 :List(CXXScalarValueInitExpr);
  cxxUcRewrittenUcBinaryUcOperator @230 :List(CXXRewrittenBinaryOperator);
  cxxUcPseudoUcDestructorUcExpr @231 :List(CXXPseudoDestructorExpr);
  cxxUcNullUcPtrUcLiteralUcExpr @232 :List(CXXNullPtrLiteralExpr);
  cxxUcNoexceptUcExpr @233 :List(CXXNoexceptExpr);
  cxxUcNewUcExpr @234 :List(CXXNewExpr);
  cxxUcInheritedUcCtorUcInitUcExpr @235 :List(CXXInheritedCtorInitExpr);
  cxxUcFoldUcExpr @236 :List(CXXFoldExpr);
  cxxUcDependentUcScopeUcMemberUcExpr @237 :List(CXXDependentScopeMemberExpr);
  cxxUcDeleteUcExpr @238 :List(CXXDeleteExpr);
  cxxUcDefaultUcInitUcExpr @239 :List(CXXDefaultInitExpr);
  cxxUcDefaultUcArgUcExpr @240 :List(CXXDefaultArgExpr);
  cxxUcConstructUcExpr @241 :List(CXXConstructExpr);
  cxxUcTemporaryUcObjectUcExpr @242 :List(CXXTemporaryObjectExpr);
  cxxUcBoolUcLiteralUcExpr @243 :List(CXXBoolLiteralExpr);
  cxxUcBindUcTemporaryUcExpr @244 :List(CXXBindTemporaryExpr);
  blockUcExpr @245 :List(BlockExpr);
  binaryUcOperator @246 :List(BinaryOperator);
  compoundUcAssignUcOperator @247 :List(CompoundAssignOperator);
  atomicUcExpr @248 :List(AtomicExpr);
  asUcTypeUcExpr @249 :List(AsTypeExpr);
  arrayUcTypeUcTraitUcExpr @250 :List(ArrayTypeTraitExpr);
  arrayUcSubscriptUcExpr @251 :List(ArraySubscriptExpr);
  arrayUcInitUcLoopUcExpr @252 :List(ArrayInitLoopExpr);
  arrayUcInitUcIndexUcExpr @253 :List(ArrayInitIndexExpr);
  addrUcLabelUcExpr @254 :List(AddrLabelExpr);
  abstractUcConditionalUcOperator @255 :List(AbstractConditionalOperator);
  conditionalUcOperator @256 :List(ConditionalOperator);
  binaryUcConditionalUcOperator @257 :List(BinaryConditionalOperator);
  vaUcArgUcExpr @258 :List(VAArgExpr);
  unaryUcOperator @259 :List(UnaryOperator);
  unaryUcExprUcOrUcTypeUcTraitUcExpr @260 :List(UnaryExprOrTypeTraitExpr);
  typoUcExpr @261 :List(TypoExpr);
  typeUcTraitUcExpr @262 :List(TypeTraitExpr);
  substUcNonUcTypeUcTemplateUcParmUcPackUcExpr @263 :List(SubstNonTypeTemplateParmPackExpr);
  substUcNonUcTypeUcTemplateUcParmUcExpr @264 :List(SubstNonTypeTemplateParmExpr);
  stringUcLiteral @265 :List(StringLiteral);
  stmtUcExpr @266 :List(StmtExpr);
  sourceUcLocUcExpr @267 :List(SourceLocExpr);
  sizeUcOfUcPackUcExpr @268 :List(SizeOfPackExpr);
  shuffleUcVectorUcExpr @269 :List(ShuffleVectorExpr);
  syclUcUniqueUcStableUcNameUcExpr @270 :List(SYCLUniqueStableNameExpr);
  requiresUcExpr @271 :List(RequiresExpr);
  recoveryUcExpr @272 :List(RecoveryExpr);
  pseudoUcObjectUcExpr @273 :List(PseudoObjectExpr);
  predefinedUcExpr @274 :List(PredefinedExpr);
  parenUcListUcExpr @275 :List(ParenListExpr);
  parenUcExpr @276 :List(ParenExpr);
  packUcExpansionUcExpr @277 :List(PackExpansionExpr);
  overloadUcExpr @278 :List(OverloadExpr);
  unresolvedUcMemberUcExpr @279 :List(UnresolvedMemberExpr);
  unresolvedUcLookupUcExpr @280 :List(UnresolvedLookupExpr);
  opaqueUcValueUcExpr @281 :List(OpaqueValueExpr);
  offsetUcOfUcExpr @282 :List(OffsetOfExpr);
  objUcCUcSubscriptUcRefUcExpr @283 :List(ObjCSubscriptRefExpr);
  objUcCUcStringUcLiteral @284 :List(ObjCStringLiteral);
  objUcCUcSelectorUcExpr @285 :List(ObjCSelectorExpr);
  objUcCUcProtocolUcExpr @286 :List(ObjCProtocolExpr);
  objUcCUcPropertyUcRefUcExpr @287 :List(ObjCPropertyRefExpr);
  objUcCUcMessageUcExpr @288 :List(ObjCMessageExpr);
  objUcCUcIvarUcRefUcExpr @289 :List(ObjCIvarRefExpr);
  objUcCUcIsaUcExpr @290 :List(ObjCIsaExpr);
  objUcCUcIndirectUcCopyUcRestoreUcExpr @291 :List(ObjCIndirectCopyRestoreExpr);
  objUcCUcEncodeUcExpr @292 :List(ObjCEncodeExpr);
  objUcCUcDictionaryUcLiteral @293 :List(ObjCDictionaryLiteral);
  objUcCUcBoxedUcExpr @294 :List(ObjCBoxedExpr);
  objUcCUcBoolUcLiteralUcExpr @295 :List(ObjCBoolLiteralExpr);
  objUcCUcAvailabilityUcCheckUcExpr @296 :List(ObjCAvailabilityCheckExpr);
  objUcCUcArrayUcLiteral @297 :List(ObjCArrayLiteral);
  ompUcIteratorUcExpr @298 :List(OMPIteratorExpr);
  ompUcArrayUcShapingUcExpr @299 :List(OMPArrayShapingExpr);
  ompUcArrayUcSectionUcExpr @300 :List(OMPArraySectionExpr);
  noUcInitUcExpr @301 :List(NoInitExpr);
  memberUcExpr @302 :List(MemberExpr);
  matrixUcSubscriptUcExpr @303 :List(MatrixSubscriptExpr);
  materializeUcTemporaryUcExpr @304 :List(MaterializeTemporaryExpr);
  msUcPropertyUcSubscriptUcExpr @305 :List(MSPropertySubscriptExpr);
  msUcPropertyUcRefUcExpr @306 :List(MSPropertyRefExpr);
  lambdaUcExpr @307 :List(LambdaExpr);
  integerUcLiteral @308 :List(IntegerLiteral);
  initUcListUcExpr @309 :List(InitListExpr);
  implicitUcValueUcInitUcExpr @310 :List(ImplicitValueInitExpr);
  imaginaryUcLiteral @311 :List(ImaginaryLiteral);
  genericUcSelectionUcExpr @312 :List(GenericSelectionExpr);
  gnuUcNullUcExpr @313 :List(GNUNullExpr);
  functionUcParmUcPackUcExpr @314 :List(FunctionParmPackExpr);
  fullUcExpr @315 :List(FullExpr);
  exprUcWithUcCleanups @316 :List(ExprWithCleanups);
  constantUcExpr @317 :List(ConstantExpr);
  floatingUcLiteral @318 :List(FloatingLiteral);
  fixedUcPointUcLiteral @319 :List(FixedPointLiteral);
  extUcVectorUcElementUcExpr @320 :List(ExtVectorElementExpr);
  expressionUcTraitUcExpr @321 :List(ExpressionTraitExpr);
  attributedUcStmt @322 :List(AttributedStmt);
  switchUcStmt @323 :List(SwitchStmt);
  switchUcCase @324 :List(SwitchCase);
  defaultUcStmt @325 :List(DefaultStmt);
  caseUcStmt @326 :List(CaseStmt);
  type @327 :List(Type);
  templateUcTypeUcParmUcType @328 :List(TemplateTypeParmType);
  templateUcSpecializationUcType @329 :List(TemplateSpecializationType);
  tagUcType @330 :List(TagType);
  recordUcType @331 :List(RecordType);
  enumUcType @332 :List(EnumType);
  substUcTemplateUcTypeUcParmUcType @333 :List(SubstTemplateTypeParmType);
  substUcTemplateUcTypeUcParmUcPackUcType @334 :List(SubstTemplateTypeParmPackType);
  referenceUcType @335 :List(ReferenceType);
  rUcValueUcReferenceUcType @336 :List(RValueReferenceType);
  lUcValueUcReferenceUcType @337 :List(LValueReferenceType);
  pointerUcType @338 :List(PointerType);
  pipeUcType @339 :List(PipeType);
  parenUcType @340 :List(ParenType);
  packUcExpansionUcType @341 :List(PackExpansionType);
  objUcCUcTypeUcParamUcType @342 :List(ObjCTypeParamType);
  objUcCUcObjectUcType @343 :List(ObjCObjectType);
  objUcCUcInterfaceUcType @344 :List(ObjCInterfaceType);
  objUcCUcObjectUcPointerUcType @345 :List(ObjCObjectPointerType);
  memberUcPointerUcType @346 :List(MemberPointerType);
  matrixUcType @347 :List(MatrixType);
  dependentUcSizedUcMatrixUcType @348 :List(DependentSizedMatrixType);
  constantUcMatrixUcType @349 :List(ConstantMatrixType);
  macroUcQualifiedUcType @350 :List(MacroQualifiedType);
  injectedUcClassUcNameUcType @351 :List(InjectedClassNameType);
  functionUcType @352 :List(FunctionType);
  functionUcProtoUcType @353 :List(FunctionProtoType);
  functionUcNoUcProtoUcType @354 :List(FunctionNoProtoType);
  extUcIntUcType @355 :List(ExtIntType);
  dependentUcVectorUcType @356 :List(DependentVectorType);
  dependentUcSizedUcExtUcVectorUcType @357 :List(DependentSizedExtVectorType);
  dependentUcExtUcIntUcType @358 :List(DependentExtIntType);
  dependentUcAddressUcSpaceUcType @359 :List(DependentAddressSpaceType);
  deducedUcType @360 :List(DeducedType);
  deducedUcTemplateUcSpecializationUcType @361 :List(DeducedTemplateSpecializationType);
  autoUcType @362 :List(AutoType);
  decltypeUcType @363 :List(DecltypeType);
  complexUcType @364 :List(ComplexType);
  builtinUcType @365 :List(BuiltinType);
  blockUcPointerUcType @366 :List(BlockPointerType);
  attributedUcType @367 :List(AttributedType);
  atomicUcType @368 :List(AtomicType);
  arrayUcType @369 :List(ArrayType);
  variableUcArrayUcType @370 :List(VariableArrayType);
  incompleteUcArrayUcType @371 :List(IncompleteArrayType);
  dependentUcSizedUcArrayUcType @372 :List(DependentSizedArrayType);
  constantUcArrayUcType @373 :List(ConstantArrayType);
  adjustedUcType @374 :List(AdjustedType);
  decayedUcType @375 :List(DecayedType);
  vectorUcType @376 :List(VectorType);
  extUcVectorUcType @377 :List(ExtVectorType);
  unresolvedUcUsingUcType @378 :List(UnresolvedUsingType);
  unaryUcTransformUcType @379 :List(UnaryTransformType);
  typedefUcType @380 :List(TypedefType);
  typeUcOfUcType @381 :List(TypeOfType);
  typeUcOfUcExprUcType @382 :List(TypeOfExprType);
}
