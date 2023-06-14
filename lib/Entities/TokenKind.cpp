// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TokenKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TokenKind e) {
  switch (e) {
    case TokenKind::UNKNOWN: return "UNKNOWN";
    case TokenKind::END_OF_FILE: return "END_OF_FILE";
    case TokenKind::END_OF_DIRECTIVE: return "END_OF_DIRECTIVE";
    case TokenKind::CODE_COMPLETION: return "CODE_COMPLETION";
    case TokenKind::COMMENT: return "COMMENT";
    case TokenKind::IDENTIFIER: return "IDENTIFIER";
    case TokenKind::WHITESPACE: return "WHITESPACE";
    case TokenKind::NUMERIC_CONSTANT: return "NUMERIC_CONSTANT";
    case TokenKind::CHARACTER_CONSTANT: return "CHARACTER_CONSTANT";
    case TokenKind::WIDE_CHARACTER_CONSTANT: return "WIDE_CHARACTER_CONSTANT";
    case TokenKind::UTF8_CHARACTER_CONSTANT: return "UTF8_CHARACTER_CONSTANT";
    case TokenKind::UTF16_CHARACTER_CONSTANT: return "UTF16_CHARACTER_CONSTANT";
    case TokenKind::UTF32_CHARACTER_CONSTANT: return "UTF32_CHARACTER_CONSTANT";
    case TokenKind::STRING_LITERAL: return "STRING_LITERAL";
    case TokenKind::WIDE_STRING_LITERAL: return "WIDE_STRING_LITERAL";
    case TokenKind::HEADER_NAME: return "HEADER_NAME";
    case TokenKind::UTF8_STRING_LITERAL: return "UTF8_STRING_LITERAL";
    case TokenKind::UTF16_STRING_LITERAL: return "UTF16_STRING_LITERAL";
    case TokenKind::UTF32_STRING_LITERAL: return "UTF32_STRING_LITERAL";
    case TokenKind::L_SQUARE: return "L_SQUARE";
    case TokenKind::R_SQUARE: return "R_SQUARE";
    case TokenKind::L_PARENTHESIS: return "L_PARENTHESIS";
    case TokenKind::R_PARENTHESIS: return "R_PARENTHESIS";
    case TokenKind::L_BRACE: return "L_BRACE";
    case TokenKind::R_BRACE: return "R_BRACE";
    case TokenKind::PERIOD: return "PERIOD";
    case TokenKind::ELLIPSIS: return "ELLIPSIS";
    case TokenKind::AMP: return "AMP";
    case TokenKind::AMP_AMP: return "AMP_AMP";
    case TokenKind::AMP_EQUAL: return "AMP_EQUAL";
    case TokenKind::STAR: return "STAR";
    case TokenKind::STAR_EQUAL: return "STAR_EQUAL";
    case TokenKind::PLUS: return "PLUS";
    case TokenKind::PLUS_PLUS: return "PLUS_PLUS";
    case TokenKind::PLUS_EQUAL: return "PLUS_EQUAL";
    case TokenKind::MINUS: return "MINUS";
    case TokenKind::ARROW: return "ARROW";
    case TokenKind::MINUS_MINUS: return "MINUS_MINUS";
    case TokenKind::MINUS_EQUAL: return "MINUS_EQUAL";
    case TokenKind::TILDE: return "TILDE";
    case TokenKind::EXCLAIM: return "EXCLAIM";
    case TokenKind::EXCLAIM_EQUAL: return "EXCLAIM_EQUAL";
    case TokenKind::SLASH: return "SLASH";
    case TokenKind::SLASH_EQUAL: return "SLASH_EQUAL";
    case TokenKind::PERCENT: return "PERCENT";
    case TokenKind::PERCENT_EQUAL: return "PERCENT_EQUAL";
    case TokenKind::LESS: return "LESS";
    case TokenKind::LESS_LESS: return "LESS_LESS";
    case TokenKind::LESS_EQUAL: return "LESS_EQUAL";
    case TokenKind::LESS_LESS_EQUAL: return "LESS_LESS_EQUAL";
    case TokenKind::SPACESHIP: return "SPACESHIP";
    case TokenKind::GREATER: return "GREATER";
    case TokenKind::GREATER_GREATER: return "GREATER_GREATER";
    case TokenKind::GREATER_EQUAL: return "GREATER_EQUAL";
    case TokenKind::GREATER_GREATER_EQUAL: return "GREATER_GREATER_EQUAL";
    case TokenKind::CARET: return "CARET";
    case TokenKind::CARET_EQUAL: return "CARET_EQUAL";
    case TokenKind::PIPE: return "PIPE";
    case TokenKind::PIPE_PIPE: return "PIPE_PIPE";
    case TokenKind::PIPE_EQUAL: return "PIPE_EQUAL";
    case TokenKind::QUESTION: return "QUESTION";
    case TokenKind::COLON: return "COLON";
    case TokenKind::SEMI: return "SEMI";
    case TokenKind::EQUAL: return "EQUAL";
    case TokenKind::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case TokenKind::COMMA: return "COMMA";
    case TokenKind::HASH: return "HASH";
    case TokenKind::HASH_HASH: return "HASH_HASH";
    case TokenKind::HASHAT: return "HASHAT";
    case TokenKind::PERIOD_STAR: return "PERIOD_STAR";
    case TokenKind::ARROW_STAR: return "ARROW_STAR";
    case TokenKind::COLON_COLON: return "COLON_COLON";
    case TokenKind::AT: return "AT";
    case TokenKind::LESS_LESS_LESS: return "LESS_LESS_LESS";
    case TokenKind::GREATER_GREATER_GREATER: return "GREATER_GREATER_GREATER";
    case TokenKind::CARETCARET: return "CARETCARET";
    case TokenKind::KEYWORD_AUTO: return "KEYWORD_AUTO";
    case TokenKind::KEYWORD_BREAK: return "KEYWORD_BREAK";
    case TokenKind::KEYWORD_CASE: return "KEYWORD_CASE";
    case TokenKind::KEYWORD_CHARACTER: return "KEYWORD_CHARACTER";
    case TokenKind::KEYWORD_CONST: return "KEYWORD_CONST";
    case TokenKind::KEYWORD_CONTINUE: return "KEYWORD_CONTINUE";
    case TokenKind::KEYWORD_DEFAULT: return "KEYWORD_DEFAULT";
    case TokenKind::KEYWORD_DO: return "KEYWORD_DO";
    case TokenKind::KEYWORD_DOUBLE: return "KEYWORD_DOUBLE";
    case TokenKind::KEYWORD_ELSE: return "KEYWORD_ELSE";
    case TokenKind::KEYWORD_ENUM: return "KEYWORD_ENUM";
    case TokenKind::KEYWORD_EXTERN: return "KEYWORD_EXTERN";
    case TokenKind::KEYWORD_FLOAT: return "KEYWORD_FLOAT";
    case TokenKind::KEYWORD_FOR: return "KEYWORD_FOR";
    case TokenKind::KEYWORD_GOTO: return "KEYWORD_GOTO";
    case TokenKind::KEYWORD_IF: return "KEYWORD_IF";
    case TokenKind::KEYWORD_INT: return "KEYWORD_INT";
    case TokenKind::KEYWORD__EXT_INT: return "KEYWORD__EXT_INT";
    case TokenKind::KEYWORD__BIT_INT: return "KEYWORD__BIT_INT";
    case TokenKind::KEYWORD_LONG: return "KEYWORD_LONG";
    case TokenKind::KEYWORD_REGISTER: return "KEYWORD_REGISTER";
    case TokenKind::KEYWORD_RETURN: return "KEYWORD_RETURN";
    case TokenKind::KEYWORD_SHORT: return "KEYWORD_SHORT";
    case TokenKind::KEYWORD_SIGNED: return "KEYWORD_SIGNED";
    case TokenKind::KEYWORD_SIZEOF: return "KEYWORD_SIZEOF";
    case TokenKind::KEYWORD_STATIC: return "KEYWORD_STATIC";
    case TokenKind::KEYWORD_STRUCT: return "KEYWORD_STRUCT";
    case TokenKind::KEYWORD_SWITCH: return "KEYWORD_SWITCH";
    case TokenKind::KEYWORD_TYPEDEF: return "KEYWORD_TYPEDEF";
    case TokenKind::KEYWORD_UNION: return "KEYWORD_UNION";
    case TokenKind::KEYWORD_UNSIGNED: return "KEYWORD_UNSIGNED";
    case TokenKind::KEYWORD_VOID: return "KEYWORD_VOID";
    case TokenKind::KEYWORD_VOLATILE: return "KEYWORD_VOLATILE";
    case TokenKind::KEYWORD_WHILE: return "KEYWORD_WHILE";
    case TokenKind::KEYWORD__ALIGNAS: return "KEYWORD__ALIGNAS";
    case TokenKind::KEYWORD__ALIGNOF: return "KEYWORD__ALIGNOF";
    case TokenKind::KEYWORD__ATOMIC: return "KEYWORD__ATOMIC";
    case TokenKind::KEYWORD__BOOLEAN: return "KEYWORD__BOOLEAN";
    case TokenKind::KEYWORD__COMPLEX: return "KEYWORD__COMPLEX";
    case TokenKind::KEYWORD__GENERIC: return "KEYWORD__GENERIC";
    case TokenKind::KEYWORD__IMAGINARY: return "KEYWORD__IMAGINARY";
    case TokenKind::KEYWORD__NORETURN: return "KEYWORD__NORETURN";
    case TokenKind::KEYWORD__STATIC_ASSERT: return "KEYWORD__STATIC_ASSERT";
    case TokenKind::KEYWORD__THREAD_LOCAL: return "KEYWORD__THREAD_LOCAL";
    case TokenKind::KEYWORD___FUNC__: return "KEYWORD___FUNC__";
    case TokenKind::KEYWORD___OBJC_YES: return "KEYWORD___OBJC_YES";
    case TokenKind::KEYWORD___OBJC_NO: return "KEYWORD___OBJC_NO";
    case TokenKind::KEYWORD_ASSEMBLY: return "KEYWORD_ASSEMBLY";
    case TokenKind::KEYWORD_BOOLEAN: return "KEYWORD_BOOLEAN";
    case TokenKind::KEYWORD_CATCH: return "KEYWORD_CATCH";
    case TokenKind::KEYWORD_CLASS: return "KEYWORD_CLASS";
    case TokenKind::KEYWORD_CONST_CAST: return "KEYWORD_CONST_CAST";
    case TokenKind::KEYWORD_DELETE: return "KEYWORD_DELETE";
    case TokenKind::KEYWORD_DYNAMIC_CAST: return "KEYWORD_DYNAMIC_CAST";
    case TokenKind::KEYWORD_EXPLICIT: return "KEYWORD_EXPLICIT";
    case TokenKind::KEYWORD_EXPORT: return "KEYWORD_EXPORT";
    case TokenKind::KEYWORD_FALSE: return "KEYWORD_FALSE";
    case TokenKind::KEYWORD_FRIEND: return "KEYWORD_FRIEND";
    case TokenKind::KEYWORD_MUTABLE: return "KEYWORD_MUTABLE";
    case TokenKind::KEYWORD_NAMESPACE: return "KEYWORD_NAMESPACE";
    case TokenKind::KEYWORD_NEW: return "KEYWORD_NEW";
    case TokenKind::KEYWORD_OPERATOR: return "KEYWORD_OPERATOR";
    case TokenKind::KEYWORD_PRIVATE: return "KEYWORD_PRIVATE";
    case TokenKind::KEYWORD_PROTECTED: return "KEYWORD_PROTECTED";
    case TokenKind::KEYWORD_PUBLIC: return "KEYWORD_PUBLIC";
    case TokenKind::KEYWORD_REINTERPRET_CAST: return "KEYWORD_REINTERPRET_CAST";
    case TokenKind::KEYWORD_STATIC_CAST: return "KEYWORD_STATIC_CAST";
    case TokenKind::KEYWORD_TEMPLATE: return "KEYWORD_TEMPLATE";
    case TokenKind::KEYWORD_THIS: return "KEYWORD_THIS";
    case TokenKind::KEYWORD_THROW: return "KEYWORD_THROW";
    case TokenKind::KEYWORD_TRUE: return "KEYWORD_TRUE";
    case TokenKind::KEYWORD_TRY: return "KEYWORD_TRY";
    case TokenKind::KEYWORD_TYPENAME: return "KEYWORD_TYPENAME";
    case TokenKind::KEYWORD_TYPEID: return "KEYWORD_TYPEID";
    case TokenKind::KEYWORD_USING: return "KEYWORD_USING";
    case TokenKind::KEYWORD_VIRTUAL: return "KEYWORD_VIRTUAL";
    case TokenKind::KEYWORD_WCHAR_T: return "KEYWORD_WCHAR_T";
    case TokenKind::KEYWORD_RESTRICT: return "KEYWORD_RESTRICT";
    case TokenKind::KEYWORD_INLINE: return "KEYWORD_INLINE";
    case TokenKind::KEYWORD_ALIGNAS: return "KEYWORD_ALIGNAS";
    case TokenKind::KEYWORD_ALIGNOF: return "KEYWORD_ALIGNOF";
    case TokenKind::KEYWORD_CHAR16_T: return "KEYWORD_CHAR16_T";
    case TokenKind::KEYWORD_CHAR32_T: return "KEYWORD_CHAR32_T";
    case TokenKind::KEYWORD_CONSTEXPR: return "KEYWORD_CONSTEXPR";
    case TokenKind::KEYWORD_DECLTYPE: return "KEYWORD_DECLTYPE";
    case TokenKind::KEYWORD_NOEXCEPT: return "KEYWORD_NOEXCEPT";
    case TokenKind::KEYWORD_NULLPTR: return "KEYWORD_NULLPTR";
    case TokenKind::KEYWORD_STATIC_ASSERT: return "KEYWORD_STATIC_ASSERT";
    case TokenKind::KEYWORD_THREAD_LOCAL: return "KEYWORD_THREAD_LOCAL";
    case TokenKind::KEYWORD_CO_AWAIT: return "KEYWORD_CO_AWAIT";
    case TokenKind::KEYWORD_CO_RETURN: return "KEYWORD_CO_RETURN";
    case TokenKind::KEYWORD_CO_YIELD: return "KEYWORD_CO_YIELD";
    case TokenKind::KEYWORD_MODULE: return "KEYWORD_MODULE";
    case TokenKind::KEYWORD_IMPORT: return "KEYWORD_IMPORT";
    case TokenKind::KEYWORD_CONSTEVAL: return "KEYWORD_CONSTEVAL";
    case TokenKind::KEYWORD_CONSTINIT: return "KEYWORD_CONSTINIT";
    case TokenKind::KEYWORD_CONCEPT: return "KEYWORD_CONCEPT";
    case TokenKind::KEYWORD_REQUIRES: return "KEYWORD_REQUIRES";
    case TokenKind::KEYWORD_CHAR8_T: return "KEYWORD_CHAR8_T";
    case TokenKind::KEYWORD__FLOAT16: return "KEYWORD__FLOAT16";
    case TokenKind::KEYWORD_TYPEOF: return "KEYWORD_TYPEOF";
    case TokenKind::KEYWORD_TYPEOF_UNQUALIFIED: return "KEYWORD_TYPEOF_UNQUALIFIED";
    case TokenKind::KEYWORD__ACCUM: return "KEYWORD__ACCUM";
    case TokenKind::KEYWORD__FRACT: return "KEYWORD__FRACT";
    case TokenKind::KEYWORD__SAT: return "KEYWORD__SAT";
    case TokenKind::KEYWORD__DECIMAL32: return "KEYWORD__DECIMAL32";
    case TokenKind::KEYWORD__DECIMAL64: return "KEYWORD__DECIMAL64";
    case TokenKind::KEYWORD__DECIMAL128: return "KEYWORD__DECIMAL128";
    case TokenKind::KEYWORD___NULL: return "KEYWORD___NULL";
    case TokenKind::KEYWORD___ALIGNOF: return "KEYWORD___ALIGNOF";
    case TokenKind::KEYWORD___ATTRIBUTE: return "KEYWORD___ATTRIBUTE";
    case TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION: return "KEYWORD___BUILTIN_CHOOSE_EXPRESSION";
    case TokenKind::KEYWORD___BUILTIN_OFFSETOF: return "KEYWORD___BUILTIN_OFFSETOF";
    case TokenKind::KEYWORD___BUILTIN_FILE: return "KEYWORD___BUILTIN_FILE";
    case TokenKind::KEYWORD___BUILTIN_FUNCTION: return "KEYWORD___BUILTIN_FUNCTION";
    case TokenKind::KEYWORD___BUILTIN_LINE: return "KEYWORD___BUILTIN_LINE";
    case TokenKind::KEYWORD___BUILTIN_COLUMN: return "KEYWORD___BUILTIN_COLUMN";
    case TokenKind::KEYWORD___BUILTIN_SOURCE_TOKEN: return "KEYWORD___BUILTIN_SOURCE_TOKEN";
    case TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P: return "KEYWORD___BUILTIN_TYPES_COMPATIBLE_P";
    case TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT: return "KEYWORD___BUILTIN_VA_ARGUMENT";
    case TokenKind::KEYWORD___EXTENSION__: return "KEYWORD___EXTENSION__";
    case TokenKind::KEYWORD___FLOAT128: return "KEYWORD___FLOAT128";
    case TokenKind::KEYWORD___IBM128: return "KEYWORD___IBM128";
    case TokenKind::KEYWORD___IMAG: return "KEYWORD___IMAG";
    case TokenKind::KEYWORD___INT128: return "KEYWORD___INT128";
    case TokenKind::KEYWORD___LABEL__: return "KEYWORD___LABEL__";
    case TokenKind::KEYWORD___REAL: return "KEYWORD___REAL";
    case TokenKind::KEYWORD___THREAD: return "KEYWORD___THREAD";
    case TokenKind::KEYWORD___FUNCTION__: return "KEYWORD___FUNCTION__";
    case TokenKind::KEYWORD___PRETTYFUNCTION__: return "KEYWORD___PRETTYFUNCTION__";
    case TokenKind::KEYWORD___AUTO_TYPE: return "KEYWORD___AUTO_TYPE";
    case TokenKind::KEYWORD___FUNCDNAME__: return "KEYWORD___FUNCDNAME__";
    case TokenKind::KEYWORD___FUNCSIG__: return "KEYWORD___FUNCSIG__";
    case TokenKind::KEYWORD_LFUNCTION__: return "KEYWORD_LFUNCTION__";
    case TokenKind::KEYWORD_LFUNCSIG__: return "KEYWORD_LFUNCSIG__";
    case TokenKind::KEYWORD___IS_INTERFACE_CLASS: return "KEYWORD___IS_INTERFACE_CLASS";
    case TokenKind::KEYWORD___IS_SEALED: return "KEYWORD___IS_SEALED";
    case TokenKind::KEYWORD___IS_DESTRUCTIBLE: return "KEYWORD___IS_DESTRUCTIBLE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE: return "KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE";
    case TokenKind::KEYWORD___IS_NOTHROW_DESTRUCTIBLE: return "KEYWORD___IS_NOTHROW_DESTRUCTIBLE";
    case TokenKind::KEYWORD___IS_NOTHROW_ASSIGNABLE: return "KEYWORD___IS_NOTHROW_ASSIGNABLE";
    case TokenKind::KEYWORD___IS_CONSTRUCTIBLE: return "KEYWORD___IS_CONSTRUCTIBLE";
    case TokenKind::KEYWORD___IS_NOTHROW_CONSTRUCTIBLE: return "KEYWORD___IS_NOTHROW_CONSTRUCTIBLE";
    case TokenKind::KEYWORD___IS_ASSIGNABLE: return "KEYWORD___IS_ASSIGNABLE";
    case TokenKind::KEYWORD___HAS_NOTHROW_MOVE_ASSIGN: return "KEYWORD___HAS_NOTHROW_MOVE_ASSIGN";
    case TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN: return "KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN";
    case TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR: return "KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR";
    case TokenKind::KEYWORD___HAS_NOTHROW_ASSIGN: return "KEYWORD___HAS_NOTHROW_ASSIGN";
    case TokenKind::KEYWORD___HAS_NOTHROW_COPY: return "KEYWORD___HAS_NOTHROW_COPY";
    case TokenKind::KEYWORD___HAS_NOTHROW_CONSTRUCTOR: return "KEYWORD___HAS_NOTHROW_CONSTRUCTOR";
    case TokenKind::KEYWORD___HAS_TRIVIAL_ASSIGN: return "KEYWORD___HAS_TRIVIAL_ASSIGN";
    case TokenKind::KEYWORD___HAS_TRIVIAL_COPY: return "KEYWORD___HAS_TRIVIAL_COPY";
    case TokenKind::KEYWORD___HAS_TRIVIAL_CONSTRUCTOR: return "KEYWORD___HAS_TRIVIAL_CONSTRUCTOR";
    case TokenKind::KEYWORD___HAS_TRIVIAL_DESTRUCTOR: return "KEYWORD___HAS_TRIVIAL_DESTRUCTOR";
    case TokenKind::KEYWORD___HAS_VIRTUAL_DESTRUCTOR: return "KEYWORD___HAS_VIRTUAL_DESTRUCTOR";
    case TokenKind::KEYWORD___IS_ABSTRACT: return "KEYWORD___IS_ABSTRACT";
    case TokenKind::KEYWORD___IS_AGGREGATE: return "KEYWORD___IS_AGGREGATE";
    case TokenKind::KEYWORD___IS_BASE_OF: return "KEYWORD___IS_BASE_OF";
    case TokenKind::KEYWORD___IS_CLASS: return "KEYWORD___IS_CLASS";
    case TokenKind::KEYWORD___IS_CONVERTIBLE_TO: return "KEYWORD___IS_CONVERTIBLE_TO";
    case TokenKind::KEYWORD___IS_EMPTY: return "KEYWORD___IS_EMPTY";
    case TokenKind::KEYWORD___IS_ENUM: return "KEYWORD___IS_ENUM";
    case TokenKind::KEYWORD___IS_FINAL: return "KEYWORD___IS_FINAL";
    case TokenKind::KEYWORD___IS_LITERAL: return "KEYWORD___IS_LITERAL";
    case TokenKind::KEYWORD___IS_POD: return "KEYWORD___IS_POD";
    case TokenKind::KEYWORD___IS_POLYMORPHIC: return "KEYWORD___IS_POLYMORPHIC";
    case TokenKind::KEYWORD___IS_STANDARD_LAYOUT: return "KEYWORD___IS_STANDARD_LAYOUT";
    case TokenKind::KEYWORD___IS_TRIVIAL: return "KEYWORD___IS_TRIVIAL";
    case TokenKind::KEYWORD___IS_TRIVIALLY_ASSIGNABLE: return "KEYWORD___IS_TRIVIALLY_ASSIGNABLE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE: return "KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_COPYABLE: return "KEYWORD___IS_TRIVIALLY_COPYABLE";
    case TokenKind::KEYWORD___IS_UNION: return "KEYWORD___IS_UNION";
    case TokenKind::KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS: return "KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS";
    case TokenKind::KEYWORD___ADD_LVALUE_REFERENCE: return "KEYWORD___ADD_LVALUE_REFERENCE";
    case TokenKind::KEYWORD___ADD_POINTER: return "KEYWORD___ADD_POINTER";
    case TokenKind::KEYWORD___ADD_RVALUE_REFERENCE: return "KEYWORD___ADD_RVALUE_REFERENCE";
    case TokenKind::KEYWORD___DECAY: return "KEYWORD___DECAY";
    case TokenKind::KEYWORD___MAKE_SIGNED: return "KEYWORD___MAKE_SIGNED";
    case TokenKind::KEYWORD___MAKE_UNSIGNED: return "KEYWORD___MAKE_UNSIGNED";
    case TokenKind::KEYWORD___REMOVE_ALL_EXTENTS: return "KEYWORD___REMOVE_ALL_EXTENTS";
    case TokenKind::KEYWORD___REMOVE_CONST: return "KEYWORD___REMOVE_CONST";
    case TokenKind::KEYWORD___REMOVE_CV: return "KEYWORD___REMOVE_CV";
    case TokenKind::KEYWORD___REMOVE_CVREF: return "KEYWORD___REMOVE_CVREF";
    case TokenKind::KEYWORD___REMOVE_EXTENT: return "KEYWORD___REMOVE_EXTENT";
    case TokenKind::KEYWORD___REMOVE_POINTER: return "KEYWORD___REMOVE_POINTER";
    case TokenKind::KEYWORD___REMOVE_REFERENCE_T: return "KEYWORD___REMOVE_REFERENCE_T";
    case TokenKind::KEYWORD___REMOVE_RESTRICT: return "KEYWORD___REMOVE_RESTRICT";
    case TokenKind::KEYWORD___REMOVE_VOLATILE: return "KEYWORD___REMOVE_VOLATILE";
    case TokenKind::KEYWORD___UNDERLYING_TYPE: return "KEYWORD___UNDERLYING_TYPE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_RELOCATABLE: return "KEYWORD___IS_TRIVIALLY_RELOCATABLE";
    case TokenKind::KEYWORD___IS_BOUNDED_ARRAY: return "KEYWORD___IS_BOUNDED_ARRAY";
    case TokenKind::KEYWORD___IS_UNBOUNDED_ARRAY: return "KEYWORD___IS_UNBOUNDED_ARRAY";
    case TokenKind::KEYWORD___IS_NULLPTR: return "KEYWORD___IS_NULLPTR";
    case TokenKind::KEYWORD___IS_SCOPED_ENUM: return "KEYWORD___IS_SCOPED_ENUM";
    case TokenKind::KEYWORD___IS_REFERENCEABLE: return "KEYWORD___IS_REFERENCEABLE";
    case TokenKind::KEYWORD___REFERENCE_BINDS_TO_TEMPORARY: return "KEYWORD___REFERENCE_BINDS_TO_TEMPORARY";
    case TokenKind::KEYWORD___IS_LVALUE_EXPRESSION: return "KEYWORD___IS_LVALUE_EXPRESSION";
    case TokenKind::KEYWORD___IS_RVALUE_EXPRESSION: return "KEYWORD___IS_RVALUE_EXPRESSION";
    case TokenKind::KEYWORD___IS_ARITHMETIC: return "KEYWORD___IS_ARITHMETIC";
    case TokenKind::KEYWORD___IS_FLOATING_POINT: return "KEYWORD___IS_FLOATING_POINT";
    case TokenKind::KEYWORD___IS_INTEGRAL: return "KEYWORD___IS_INTEGRAL";
    case TokenKind::KEYWORD___IS_COMPLETE_TYPE: return "KEYWORD___IS_COMPLETE_TYPE";
    case TokenKind::KEYWORD___IS_VOID: return "KEYWORD___IS_VOID";
    case TokenKind::KEYWORD___IS_ARRAY: return "KEYWORD___IS_ARRAY";
    case TokenKind::KEYWORD___IS_FUNCTION: return "KEYWORD___IS_FUNCTION";
    case TokenKind::KEYWORD___IS_REFERENCE: return "KEYWORD___IS_REFERENCE";
    case TokenKind::KEYWORD___IS_LVALUE_REFERENCE: return "KEYWORD___IS_LVALUE_REFERENCE";
    case TokenKind::KEYWORD___IS_RVALUE_REFERENCE: return "KEYWORD___IS_RVALUE_REFERENCE";
    case TokenKind::KEYWORD___IS_FUNDAMENTAL: return "KEYWORD___IS_FUNDAMENTAL";
    case TokenKind::KEYWORD___IS_OBJECT: return "KEYWORD___IS_OBJECT";
    case TokenKind::KEYWORD___IS_SCALAR: return "KEYWORD___IS_SCALAR";
    case TokenKind::KEYWORD___IS_COMPOUND: return "KEYWORD___IS_COMPOUND";
    case TokenKind::KEYWORD___IS_POINTER: return "KEYWORD___IS_POINTER";
    case TokenKind::KEYWORD___IS_MEMBER_OBJECT_POINTER: return "KEYWORD___IS_MEMBER_OBJECT_POINTER";
    case TokenKind::KEYWORD___IS_MEMBER_FUNCTION_POINTER: return "KEYWORD___IS_MEMBER_FUNCTION_POINTER";
    case TokenKind::KEYWORD___IS_MEMBER_POINTER: return "KEYWORD___IS_MEMBER_POINTER";
    case TokenKind::KEYWORD___IS_CONST: return "KEYWORD___IS_CONST";
    case TokenKind::KEYWORD___IS_VOLATILE: return "KEYWORD___IS_VOLATILE";
    case TokenKind::KEYWORD___IS_SIGNED: return "KEYWORD___IS_SIGNED";
    case TokenKind::KEYWORD___IS_UNSIGNED: return "KEYWORD___IS_UNSIGNED";
    case TokenKind::KEYWORD___IS_SAME: return "KEYWORD___IS_SAME";
    case TokenKind::KEYWORD___IS_CONVERTIBLE: return "KEYWORD___IS_CONVERTIBLE";
    case TokenKind::KEYWORD___ARRAY_RANK: return "KEYWORD___ARRAY_RANK";
    case TokenKind::KEYWORD___ARRAY_EXTENT: return "KEYWORD___ARRAY_EXTENT";
    case TokenKind::KEYWORD___PRIVATE_EXTERN__: return "KEYWORD___PRIVATE_EXTERN__";
    case TokenKind::KEYWORD___MODULE_PRIVATE__: return "KEYWORD___MODULE_PRIVATE__";
    case TokenKind::KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR: return "KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR";
    case TokenKind::KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE: return "KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE";
    case TokenKind::KEYWORD___BUILTIN_XNU_TYPE_SUMMARY: return "KEYWORD___BUILTIN_XNU_TYPE_SUMMARY";
    case TokenKind::KEYWORD___BUILTIN_TMO_TYPE_METADATA: return "KEYWORD___BUILTIN_TMO_TYPE_METADATA";
    case TokenKind::KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE: return "KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE";
    case TokenKind::KEYWORD___DECLSPEC: return "KEYWORD___DECLSPEC";
    case TokenKind::KEYWORD___CDECL: return "KEYWORD___CDECL";
    case TokenKind::KEYWORD___STDCALL: return "KEYWORD___STDCALL";
    case TokenKind::KEYWORD___FASTCALL: return "KEYWORD___FASTCALL";
    case TokenKind::KEYWORD___THISCALL: return "KEYWORD___THISCALL";
    case TokenKind::KEYWORD___REGCALL: return "KEYWORD___REGCALL";
    case TokenKind::KEYWORD___VECTORCALL: return "KEYWORD___VECTORCALL";
    case TokenKind::KEYWORD___FORCEINLINE: return "KEYWORD___FORCEINLINE";
    case TokenKind::KEYWORD___UNALIGNED: return "KEYWORD___UNALIGNED";
    case TokenKind::KEYWORD___SUPER: return "KEYWORD___SUPER";
    case TokenKind::KEYWORD___GLOBAL: return "KEYWORD___GLOBAL";
    case TokenKind::KEYWORD___LOCAL: return "KEYWORD___LOCAL";
    case TokenKind::KEYWORD___CONSTANT: return "KEYWORD___CONSTANT";
    case TokenKind::KEYWORD___PRIVATE: return "KEYWORD___PRIVATE";
    case TokenKind::KEYWORD___GENERIC: return "KEYWORD___GENERIC";
    case TokenKind::KEYWORD___KERNEL: return "KEYWORD___KERNEL";
    case TokenKind::KEYWORD___READ_ONLY: return "KEYWORD___READ_ONLY";
    case TokenKind::KEYWORD___WRITE_ONLY: return "KEYWORD___WRITE_ONLY";
    case TokenKind::KEYWORD___READ_WRITE: return "KEYWORD___READ_WRITE";
    case TokenKind::KEYWORD___BUILTIN_ASTYPE: return "KEYWORD___BUILTIN_ASTYPE";
    case TokenKind::KEYWORD_VEC_STEP: return "KEYWORD_VEC_STEP";
    case TokenKind::KEYWORD_IMAGE_1D_T: return "KEYWORD_IMAGE_1D_T";
    case TokenKind::KEYWORD_IMAGE_1D_ARRAY_T: return "KEYWORD_IMAGE_1D_ARRAY_T";
    case TokenKind::KEYWORD_IMAGE_1D_BUFFER_T: return "KEYWORD_IMAGE_1D_BUFFER_T";
    case TokenKind::KEYWORD_IMAGE_2D_T: return "KEYWORD_IMAGE_2D_T";
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_T: return "KEYWORD_IMAGE_2D_ARRAY_T";
    case TokenKind::KEYWORD_IMAGE_2D_DEPTH_T: return "KEYWORD_IMAGE_2D_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_DEPTH_T: return "KEYWORD_IMAGE_2D_ARRAY_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE_2D_MSAA_T: return "KEYWORD_IMAGE_2D_MSAA_T";
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_MSAA_T: return "KEYWORD_IMAGE_2D_ARRAY_MSAA_T";
    case TokenKind::KEYWORD_IMAGE_2D_MSAA_DEPTH_T: return "KEYWORD_IMAGE_2D_MSAA_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T: return "KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE_3D_T: return "KEYWORD_IMAGE_3D_T";
    case TokenKind::KEYWORD_PIPE: return "KEYWORD_PIPE";
    case TokenKind::KEYWORD_ADDRSPACE_CAST: return "KEYWORD_ADDRSPACE_CAST";
    case TokenKind::KEYWORD___NOINLINE__: return "KEYWORD___NOINLINE__";
    case TokenKind::KEYWORD_CBUFFER: return "KEYWORD_CBUFFER";
    case TokenKind::KEYWORD_TBUFFER: return "KEYWORD_TBUFFER";
    case TokenKind::KEYWORD_GROUPSHARED: return "KEYWORD_GROUPSHARED";
    case TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN: return "KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN";
    case TokenKind::KEYWORD___PASCAL: return "KEYWORD___PASCAL";
    case TokenKind::KEYWORD___VECTOR: return "KEYWORD___VECTOR";
    case TokenKind::KEYWORD___PIXEL: return "KEYWORD___PIXEL";
    case TokenKind::KEYWORD___BOOLEAN: return "KEYWORD___BOOLEAN";
    case TokenKind::KEYWORD___BF16: return "KEYWORD___BF16";
    case TokenKind::KEYWORD_HALF: return "KEYWORD_HALF";
    case TokenKind::KEYWORD___BRIDGE: return "KEYWORD___BRIDGE";
    case TokenKind::KEYWORD___BRIDGE_TRANSFER: return "KEYWORD___BRIDGE_TRANSFER";
    case TokenKind::KEYWORD___BRIDGE_RETAINED: return "KEYWORD___BRIDGE_RETAINED";
    case TokenKind::KEYWORD___BRIDGE_RETAIN: return "KEYWORD___BRIDGE_RETAIN";
    case TokenKind::KEYWORD___COVARIANT: return "KEYWORD___COVARIANT";
    case TokenKind::KEYWORD___CONTRAVARIANT: return "KEYWORD___CONTRAVARIANT";
    case TokenKind::KEYWORD___KINDOF: return "KEYWORD___KINDOF";
    case TokenKind::KEYWORD__NONNULL: return "KEYWORD__NONNULL";
    case TokenKind::KEYWORD__NULLABLE: return "KEYWORD__NULLABLE";
    case TokenKind::KEYWORD__NULLABLE_RESULT: return "KEYWORD__NULLABLE_RESULT";
    case TokenKind::KEYWORD__NULL_UNSPECIFIED: return "KEYWORD__NULL_UNSPECIFIED";
    case TokenKind::KEYWORD___PTR64: return "KEYWORD___PTR64";
    case TokenKind::KEYWORD___PTR32: return "KEYWORD___PTR32";
    case TokenKind::KEYWORD___SPTR: return "KEYWORD___SPTR";
    case TokenKind::KEYWORD___UPTR: return "KEYWORD___UPTR";
    case TokenKind::KEYWORD___W64: return "KEYWORD___W64";
    case TokenKind::KEYWORD___UUIDOF: return "KEYWORD___UUIDOF";
    case TokenKind::KEYWORD___TRY: return "KEYWORD___TRY";
    case TokenKind::KEYWORD___FINALLY: return "KEYWORD___FINALLY";
    case TokenKind::KEYWORD___LEAVE: return "KEYWORD___LEAVE";
    case TokenKind::KEYWORD___INT64: return "KEYWORD___INT64";
    case TokenKind::KEYWORD___IF_EXISTS: return "KEYWORD___IF_EXISTS";
    case TokenKind::KEYWORD___IF_NOT_EXISTS: return "KEYWORD___IF_NOT_EXISTS";
    case TokenKind::KEYWORD___SINGLE_INHERITANCE: return "KEYWORD___SINGLE_INHERITANCE";
    case TokenKind::KEYWORD___MULTIPLE_INHERITANCE: return "KEYWORD___MULTIPLE_INHERITANCE";
    case TokenKind::KEYWORD___VIRTUAL_INHERITANCE: return "KEYWORD___VIRTUAL_INHERITANCE";
    case TokenKind::KEYWORD___INTERFACE: return "KEYWORD___INTERFACE";
    case TokenKind::KEYWORD___BUILTIN_CONVERTVECTOR: return "KEYWORD___BUILTIN_CONVERTVECTOR";
    case TokenKind::KEYWORD___BUILTIN_BIT_CAST: return "KEYWORD___BUILTIN_BIT_CAST";
    case TokenKind::KEYWORD___BUILTIN_AVAILABLE: return "KEYWORD___BUILTIN_AVAILABLE";
    case TokenKind::KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME: return "KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME";
    case TokenKind::KEYWORD___UNKNOWN_ANYTYPE: return "KEYWORD___UNKNOWN_ANYTYPE";
    case TokenKind::ANNOT_CXXSCOPE: return "ANNOT_CXXSCOPE";
    case TokenKind::ANNOT_TYPENAME: return "ANNOT_TYPENAME";
    case TokenKind::ANNOT_TEMPLATE_ID: return "ANNOT_TEMPLATE_ID";
    case TokenKind::ANNOT_NON_TYPE: return "ANNOT_NON_TYPE";
    case TokenKind::ANNOT_NON_TYPE_UNDECLARED: return "ANNOT_NON_TYPE_UNDECLARED";
    case TokenKind::ANNOT_NON_TYPE_DEPENDENT: return "ANNOT_NON_TYPE_DEPENDENT";
    case TokenKind::ANNOT_OVERLOAD: return "ANNOT_OVERLOAD";
    case TokenKind::ANNOT_PRIMARY_EXPRESSION: return "ANNOT_PRIMARY_EXPRESSION";
    case TokenKind::ANNOT_DECLTYPE: return "ANNOT_DECLTYPE";
    case TokenKind::ANNOT_PRAGMA_UNUSED: return "ANNOT_PRAGMA_UNUSED";
    case TokenKind::ANNOT_PRAGMA_VIS: return "ANNOT_PRAGMA_VIS";
    case TokenKind::ANNOT_PRAGMA_PACK: return "ANNOT_PRAGMA_PACK";
    case TokenKind::ANNOT_PRAGMA_PARSER_CRASH: return "ANNOT_PRAGMA_PARSER_CRASH";
    case TokenKind::ANNOT_PRAGMA_CAPTURED: return "ANNOT_PRAGMA_CAPTURED";
    case TokenKind::ANNOT_PRAGMA_DUMP: return "ANNOT_PRAGMA_DUMP";
    case TokenKind::ANNOT_PRAGMA_MSSTRUCT: return "ANNOT_PRAGMA_MSSTRUCT";
    case TokenKind::ANNOT_PRAGMA_ALIGN: return "ANNOT_PRAGMA_ALIGN";
    case TokenKind::ANNOT_PRAGMA_WEAK: return "ANNOT_PRAGMA_WEAK";
    case TokenKind::ANNOT_PRAGMA_WEAKALIAS: return "ANNOT_PRAGMA_WEAKALIAS";
    case TokenKind::ANNOT_PRAGMA_REDEFINE_EXTNAME: return "ANNOT_PRAGMA_REDEFINE_EXTNAME";
    case TokenKind::ANNOT_PRAGMA_FP_CONTRACT: return "ANNOT_PRAGMA_FP_CONTRACT";
    case TokenKind::ANNOT_PRAGMA_FENV_ACCESS: return "ANNOT_PRAGMA_FENV_ACCESS";
    case TokenKind::ANNOT_PRAGMA_FENV_ACCESS_MS: return "ANNOT_PRAGMA_FENV_ACCESS_MS";
    case TokenKind::ANNOT_PRAGMA_FENV_ROUND: return "ANNOT_PRAGMA_FENV_ROUND";
    case TokenKind::ANNOT_PRAGMA_FLOAT_CONTROL: return "ANNOT_PRAGMA_FLOAT_CONTROL";
    case TokenKind::ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS: return "ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS";
    case TokenKind::ANNOT_PRAGMA_MS_VTORDISP: return "ANNOT_PRAGMA_MS_VTORDISP";
    case TokenKind::ANNOT_PRAGMA_MS_PRAGMA: return "ANNOT_PRAGMA_MS_PRAGMA";
    case TokenKind::ANNOT_PRAGMA_OPENCL_EXTENSION: return "ANNOT_PRAGMA_OPENCL_EXTENSION";
    case TokenKind::ANNOT_ATTRIBUTE_OPENMP: return "ANNOT_ATTRIBUTE_OPENMP";
    case TokenKind::ANNOT_PRAGMA_OPENMP: return "ANNOT_PRAGMA_OPENMP";
    case TokenKind::ANNOT_PRAGMA_OPENMP_END: return "ANNOT_PRAGMA_OPENMP_END";
    case TokenKind::ANNOT_PRAGMA_LOOP_HINT: return "ANNOT_PRAGMA_LOOP_HINT";
    case TokenKind::ANNOT_PRAGMA_FP: return "ANNOT_PRAGMA_FP";
    case TokenKind::ANNOT_PRAGMA_ATTRIBUTE: return "ANNOT_PRAGMA_ATTRIBUTE";
    case TokenKind::ANNOT_PRAGMA_RISCV: return "ANNOT_PRAGMA_RISCV";
    case TokenKind::ANNOT_MODULE_INCLUDE: return "ANNOT_MODULE_INCLUDE";
    case TokenKind::ANNOT_MODULE_BEGIN: return "ANNOT_MODULE_BEGIN";
    case TokenKind::ANNOT_MODULE_END: return "ANNOT_MODULE_END";
    case TokenKind::ANNOT_HEADER_UNIT: return "ANNOT_HEADER_UNIT";
    case TokenKind::PP_IF: return "PP_IF";
    case TokenKind::PP_IFDEF: return "PP_IFDEF";
    case TokenKind::PP_IFNDEF: return "PP_IFNDEF";
    case TokenKind::PP_ELIF: return "PP_ELIF";
    case TokenKind::PP_ELIFDEF: return "PP_ELIFDEF";
    case TokenKind::PP_ELIFNDEF: return "PP_ELIFNDEF";
    case TokenKind::PP_ELSE: return "PP_ELSE";
    case TokenKind::PP_ENDIF: return "PP_ENDIF";
    case TokenKind::PP_DEFINED: return "PP_DEFINED";
    case TokenKind::PP_INCLUDE: return "PP_INCLUDE";
    case TokenKind::PP___INCLUDE_MACROS: return "PP___INCLUDE_MACROS";
    case TokenKind::PP_DEFINE: return "PP_DEFINE";
    case TokenKind::PP_UNDEF: return "PP_UNDEF";
    case TokenKind::PP_LINE: return "PP_LINE";
    case TokenKind::PP_ERROR: return "PP_ERROR";
    case TokenKind::PP_PRAGMA: return "PP_PRAGMA";
    case TokenKind::PP_IMPORT: return "PP_IMPORT";
    case TokenKind::PP_INCLUDE_NEXT: return "PP_INCLUDE_NEXT";
    case TokenKind::PP_WARNING: return "PP_WARNING";
    case TokenKind::PP_IDENTIFIER: return "PP_IDENTIFIER";
    case TokenKind::PP_SCCS: return "PP_SCCS";
    case TokenKind::PP_ASSERT: return "PP_ASSERT";
    case TokenKind::PP_UNASSERT: return "PP_UNASSERT";
    case TokenKind::PP___PUBLIC_MACRO: return "PP___PUBLIC_MACRO";
    case TokenKind::PP___PRIVATE_MACRO: return "PP___PRIVATE_MACRO";
    case TokenKind::OBJC_AT_CLASS: return "OBJC_AT_CLASS";
    case TokenKind::OBJC_AT_COMPATIBILITY_ALIAS: return "OBJC_AT_COMPATIBILITY_ALIAS";
    case TokenKind::OBJC_AT_DEFINITIONS: return "OBJC_AT_DEFINITIONS";
    case TokenKind::OBJC_AT_ENCODE: return "OBJC_AT_ENCODE";
    case TokenKind::OBJC_AT_OBJC_END: return "OBJC_AT_OBJC_END";
    case TokenKind::OBJC_AT_IMPLEMENTATION: return "OBJC_AT_IMPLEMENTATION";
    case TokenKind::OBJC_AT_INTERFACE: return "OBJC_AT_INTERFACE";
    case TokenKind::OBJC_AT_PRIVATE: return "OBJC_AT_PRIVATE";
    case TokenKind::OBJC_AT_PROTECTED: return "OBJC_AT_PROTECTED";
    case TokenKind::OBJC_AT_PROTOCOL: return "OBJC_AT_PROTOCOL";
    case TokenKind::OBJC_AT_PUBLIC: return "OBJC_AT_PUBLIC";
    case TokenKind::OBJC_AT_SELECTOR: return "OBJC_AT_SELECTOR";
    case TokenKind::OBJC_AT_THROW: return "OBJC_AT_THROW";
    case TokenKind::OBJC_AT_TRY: return "OBJC_AT_TRY";
    case TokenKind::OBJC_AT_CATCH: return "OBJC_AT_CATCH";
    case TokenKind::OBJC_AT_FINALLY: return "OBJC_AT_FINALLY";
    case TokenKind::OBJC_AT_SYNCHRONIZED: return "OBJC_AT_SYNCHRONIZED";
    case TokenKind::OBJC_AT_AUTORELEASEPOOL: return "OBJC_AT_AUTORELEASEPOOL";
    case TokenKind::OBJC_AT_PROPERTY: return "OBJC_AT_PROPERTY";
    case TokenKind::OBJC_AT_PACKAGE: return "OBJC_AT_PACKAGE";
    case TokenKind::OBJC_AT_REQUIRED: return "OBJC_AT_REQUIRED";
    case TokenKind::OBJC_AT_OPTIONAL: return "OBJC_AT_OPTIONAL";
    case TokenKind::OBJC_AT_SYNTHESIZE: return "OBJC_AT_SYNTHESIZE";
    case TokenKind::OBJC_AT_DYNAMIC: return "OBJC_AT_DYNAMIC";
    case TokenKind::OBJC_AT_IMPORT: return "OBJC_AT_IMPORT";
    case TokenKind::OBJC_AT_AVAILABLE: return "OBJC_AT_AVAILABLE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
