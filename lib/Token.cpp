// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"

#include <cassert>
#include <multiplier/Entities/ClassScopeFunctionSpecializationDecl.h>
#include <multiplier/Entities/CXXMethodDecl.h>
#include <multiplier/Entities/DeclCategory.h>
#include <multiplier/Entities/DeclKind.h>
#include <multiplier/Entities/ImplicitParamDecl.h>
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/TagTypeKind.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/TokenCategory.h>
#include <multiplier/Entities/TokenKind.h>
#include <multiplier/Entities/VarDecl.h>

#include "File.h"
#include "Fragment.h"
#include "Use.h"

namespace mx {

class TemplateDecl;

namespace {

static const std::shared_ptr<InvalidTokenReader> kInvalidTokenReader =
    std::make_shared<InvalidTokenReader>();

// Classify a token kind into a baseline token category. These are good baseline
// indicators for syntax coloring.
static TokenCategory ClassifyToken(const Token &tok) {
  switch (tok.kind()) {
    case TokenKind::COMMENT: return TokenCategory::COMMENT;
    case TokenKind::NUMERIC_CONSTANT:
    case TokenKind::CHARACTER_CONSTANT:
    case TokenKind::WIDE_CHARACTER_CONSTANT:
    case TokenKind::UTF8_CHARACTER_CONSTANT:
    case TokenKind::UTF16_CHARACTER_CONSTANT:
    case TokenKind::UTF32_CHARACTER_CONSTANT:
    case TokenKind::STRING_LITERAL:
    case TokenKind::WIDE_STRING_LITERAL:
    case TokenKind::HEADER_NAME:
    case TokenKind::UTF8_STRING_LITERAL:
    case TokenKind::UTF16_STRING_LITERAL:
    case TokenKind::UTF32_STRING_LITERAL:
      return TokenCategory::LITERAL;
    case TokenKind::L_SQUARE:
    case TokenKind::R_SQUARE:
    case TokenKind::L_PARENTHESIS:
    case TokenKind::R_PARENTHESIS:
    case TokenKind::L_BRACE_TOKEN:
    case TokenKind::R_BRACE_TOKEN:
    case TokenKind::PERIOD:
    case TokenKind::ELLIPSIS:
    case TokenKind::AMP:
    case TokenKind::AMP_AMP:
    case TokenKind::AMP_EQUAL:
    case TokenKind::STAR:
    case TokenKind::STAR_EQUAL:
    case TokenKind::PLUS:
    case TokenKind::PLUS_PLUS:
    case TokenKind::PLUS_EQUAL:
    case TokenKind::MINUS:
    case TokenKind::ARROW:
    case TokenKind::MINUS_MINUS:
    case TokenKind::MINUS_EQUAL:
    case TokenKind::TILDE:
    case TokenKind::EXCLAIM:
    case TokenKind::EXCLAIM_EQUAL:
    case TokenKind::SLASH:
    case TokenKind::SLASH_EQUAL:
    case TokenKind::PERCENT:
    case TokenKind::PERCENT_EQUAL:
    case TokenKind::LESS:
    case TokenKind::LESS_LESS:
    case TokenKind::LESS_EQUAL:
    case TokenKind::LESS_LESS_EQUAL:
    case TokenKind::SPACESHIP:
    case TokenKind::GREATER:
    case TokenKind::GREATER_GREATER:
    case TokenKind::GREATER_EQUAL:
    case TokenKind::GREATER_GREATER_EQUAL:
    case TokenKind::CARET:
    case TokenKind::CARET_EQUAL:
    case TokenKind::PIPE:
    case TokenKind::PIPE_PIPE:
    case TokenKind::PIPE_EQUAL:
    case TokenKind::QUESTION:
    case TokenKind::COLON:
    case TokenKind::SEMI:
    case TokenKind::EQUAL:
    case TokenKind::EQUAL_EQUAL:
    case TokenKind::COMMA:
    case TokenKind::HASH:
    case TokenKind::HASH_HASH:
    case TokenKind::HASHAT:
    case TokenKind::PERIOD_STAR:
    case TokenKind::ARROW_STAR:
    case TokenKind::COLON_COLON:
    case TokenKind::AT:
    case TokenKind::LESS_LESS_LESS:
    case TokenKind::GREATER_GREATER_GREATER:
    case TokenKind::CARETCARET:
      return TokenCategory::PUNCTUATION;
    case TokenKind::KEYWORD_DOUBLE:
    case TokenKind::KEYWORD_LONG:
    case TokenKind::KEYWORD_FLOAT:
    case TokenKind::KEYWORD_CHARACTER:
    case TokenKind::KEYWORD_SHORT:
    case TokenKind::KEYWORD_SIGNED:
    case TokenKind::KEYWORD_UNSIGNED:
    case TokenKind::KEYWORD__BOOLEAN:
    case TokenKind::KEYWORD_BOOLEAN:
    case TokenKind::KEYWORD_WCHAR_T:
    case TokenKind::KEYWORD_CHAR16_T:
    case TokenKind::KEYWORD_CHAR32_T:
    case TokenKind::KEYWORD_CHAR8_T:
    case TokenKind::KEYWORD__FLOAT16:
    case TokenKind::KEYWORD__DECIMAL32:
    case TokenKind::KEYWORD__DECIMAL64:
    case TokenKind::KEYWORD__DECIMAL128:
    case TokenKind::KEYWORD_INT:
    case TokenKind::KEYWORD_VOID:
    case TokenKind::KEYWORD___FLOAT128:
    case TokenKind::KEYWORD___INT128:
    case TokenKind::KEYWORD___BOOLEAN:
    case TokenKind::KEYWORD___BF16:
    case TokenKind::KEYWORD_HALF:
    case TokenKind::KEYWORD___PTR64:
    case TokenKind::KEYWORD___PTR32:
    case TokenKind::KEYWORD___SPTR:
    case TokenKind::KEYWORD___UPTR:
    case TokenKind::KEYWORD___W64:
    case TokenKind::KEYWORD___INT64:
      return TokenCategory::BUILTIN_TYPE_NAME;
    case TokenKind::KEYWORD__EXT_INT:
    case TokenKind::KEYWORD__BIT_INT:
    case TokenKind::KEYWORD__COMPLEX:
    case TokenKind::KEYWORD_AUTO:
    case TokenKind::KEYWORD_BREAK:
    case TokenKind::KEYWORD_CASE:
    case TokenKind::KEYWORD_CONST:
    case TokenKind::KEYWORD_CONTINUE:
    case TokenKind::KEYWORD_DEFAULT:
    case TokenKind::KEYWORD_DO:
    case TokenKind::KEYWORD_ELSE:
    case TokenKind::KEYWORD_ENUM:
    case TokenKind::KEYWORD_EXTERN:
    case TokenKind::KEYWORD_FOR:
    case TokenKind::KEYWORD_GOTO:
    case TokenKind::KEYWORD_IF:
    case TokenKind::KEYWORD_INLINE:
    case TokenKind::KEYWORD_REGISTER:
    case TokenKind::KEYWORD_RESTRICT:
    case TokenKind::KEYWORD_RETURN:
    case TokenKind::KEYWORD_SIZEOF:
    case TokenKind::KEYWORD_STATIC:
    case TokenKind::KEYWORD_STRUCT:
    case TokenKind::KEYWORD_SWITCH:
    case TokenKind::KEYWORD_TYPEDEF:
    case TokenKind::KEYWORD_UNION:
    case TokenKind::KEYWORD_VOLATILE:
    case TokenKind::KEYWORD_WHILE:
    case TokenKind::KEYWORD__ALIGNAS:
    case TokenKind::KEYWORD__ALIGNOF:
    case TokenKind::KEYWORD__ATOMIC:
    case TokenKind::KEYWORD__GENERIC:
    case TokenKind::KEYWORD__IMAGINARY:
    case TokenKind::KEYWORD__NORETURN:
    case TokenKind::KEYWORD__STATIC_ASSERT:
    case TokenKind::KEYWORD__THREAD_LOCAL:
    case TokenKind::KEYWORD___FUNC__:
    case TokenKind::KEYWORD___OBJC_YES:
    case TokenKind::KEYWORD___OBJC_NO:
    case TokenKind::KEYWORD_ASSEMBLY:
    case TokenKind::KEYWORD_CATCH:
    case TokenKind::KEYWORD_CLASS:
    case TokenKind::KEYWORD_CONST_CAST:
    case TokenKind::KEYWORD_DELETE:
    case TokenKind::KEYWORD_DYNAMIC_CAST:
    case TokenKind::KEYWORD_EXPLICIT:
    case TokenKind::KEYWORD_EXPORT:
    case TokenKind::KEYWORD_FALSE:
    case TokenKind::KEYWORD_FRIEND:
    case TokenKind::KEYWORD_MUTABLE:
    case TokenKind::KEYWORD_NAMESPACE:
    case TokenKind::KEYWORD_NEW:
    case TokenKind::KEYWORD_OPERATOR:
    case TokenKind::KEYWORD_PRIVATE:
    case TokenKind::KEYWORD_PROTECTED:
    case TokenKind::KEYWORD_PUBLIC:
    case TokenKind::KEYWORD_REINTERPRET_CAST:
    case TokenKind::KEYWORD_STATIC_CAST:
    case TokenKind::KEYWORD_TEMPLATE:
    case TokenKind::KEYWORD_THIS:
    case TokenKind::KEYWORD_THROW:
    case TokenKind::KEYWORD_TRUE:
    case TokenKind::KEYWORD_TRY:
    case TokenKind::KEYWORD_TYPENAME:
    case TokenKind::KEYWORD_TYPEID:
    case TokenKind::KEYWORD_USING:
    case TokenKind::KEYWORD_VIRTUAL:
    case TokenKind::KEYWORD_ALIGNAS:
    case TokenKind::KEYWORD_ALIGNOF:
    case TokenKind::KEYWORD_CONSTEXPR:
    case TokenKind::KEYWORD_DECLTYPE:
    case TokenKind::KEYWORD_NOEXCEPT:
    case TokenKind::KEYWORD_NULLPTR:
    case TokenKind::KEYWORD_STATIC_ASSERT:
    case TokenKind::KEYWORD_THREAD_LOCAL:
    case TokenKind::KEYWORD_CONCEPT:
    case TokenKind::KEYWORD_REQUIRES:
    case TokenKind::KEYWORD_CO_AWAIT:
    case TokenKind::KEYWORD_CO_RETURN:
    case TokenKind::KEYWORD_CO_YIELD:
    case TokenKind::KEYWORD_MODULE:
    case TokenKind::KEYWORD_IMPORT:
    case TokenKind::KEYWORD_CONSTEVAL:
    case TokenKind::KEYWORD_CONSTINIT:
    case TokenKind::KEYWORD__ACCUM:
    case TokenKind::KEYWORD__FRACT:
    case TokenKind::KEYWORD__SAT:
    case TokenKind::KEYWORD___NULL:
    case TokenKind::KEYWORD___ALIGNOF:
    case TokenKind::KEYWORD___ATTRIBUTE:
    case TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION:
    case TokenKind::KEYWORD___BUILTIN_OFFSETOF:
    case TokenKind::KEYWORD___BUILTIN_FILE:
    case TokenKind::KEYWORD___BUILTIN_FUNCTION:
    case TokenKind::KEYWORD___BUILTIN_LINE:
    case TokenKind::KEYWORD___BUILTIN_COLUMN:
    case TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P:
    case TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT:
    case TokenKind::KEYWORD___EXTENSION__:
    case TokenKind::KEYWORD___IBM128:
    case TokenKind::KEYWORD___IMAG:
    case TokenKind::KEYWORD___LABEL__:
    case TokenKind::KEYWORD___REAL:
    case TokenKind::KEYWORD___THREAD:
    case TokenKind::KEYWORD___FUNCTION__:
    case TokenKind::KEYWORD___PRETTYFUNCTION__:
    case TokenKind::KEYWORD___AUTO_TYPE:
    case TokenKind::KEYWORD_TYPEOF:
    case TokenKind::KEYWORD___FUNCDNAME__:
    case TokenKind::KEYWORD___FUNCSIG__:
    case TokenKind::KEYWORD_LFUNCTION__:
    case TokenKind::KEYWORD_LFUNCSIG__:
    case TokenKind::KEYWORD___IS_INTERFACE_CLASS:
    case TokenKind::KEYWORD___IS_SEALED:
    case TokenKind::KEYWORD___IS_DESTRUCTIBLE:
    case TokenKind::KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE:
    case TokenKind::KEYWORD___IS_NOTHROW_DESTRUCTIBLE:
    case TokenKind::KEYWORD___IS_NOTHROW_ASSIGNABLE:
    case TokenKind::KEYWORD___IS_CONSTRUCTIBLE:
    case TokenKind::KEYWORD___IS_NOTHROW_CONSTRUCTIBLE:
    case TokenKind::KEYWORD___IS_ASSIGNABLE:
    case TokenKind::KEYWORD___HAS_NOTHROW_MOVE_ASSIGN:
    case TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN:
    case TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR:
    case TokenKind::KEYWORD___HAS_NOTHROW_ASSIGN:
    case TokenKind::KEYWORD___HAS_NOTHROW_COPY:
    case TokenKind::KEYWORD___HAS_NOTHROW_CONSTRUCTOR:
    case TokenKind::KEYWORD___HAS_TRIVIAL_ASSIGN:
    case TokenKind::KEYWORD___HAS_TRIVIAL_COPY:
    case TokenKind::KEYWORD___HAS_TRIVIAL_CONSTRUCTOR:
    case TokenKind::KEYWORD___HAS_TRIVIAL_DESTRUCTOR:
    case TokenKind::KEYWORD___HAS_VIRTUAL_DESTRUCTOR:
    case TokenKind::KEYWORD___IS_ABSTRACT:
    case TokenKind::KEYWORD___IS_AGGREGATE:
    case TokenKind::KEYWORD___IS_BASE_OF:
    case TokenKind::KEYWORD___IS_CLASS:
    case TokenKind::KEYWORD___IS_CONVERTIBLE_TO:
    case TokenKind::KEYWORD___IS_EMPTY:
    case TokenKind::KEYWORD___IS_ENUM:
    case TokenKind::KEYWORD___IS_FINAL:
    case TokenKind::KEYWORD___IS_LITERAL:
    case TokenKind::KEYWORD___IS_POD:
    case TokenKind::KEYWORD___IS_POLYMORPHIC:
    case TokenKind::KEYWORD___IS_STANDARD_LAYOUT:
    case TokenKind::KEYWORD___IS_TRIVIAL:
    case TokenKind::KEYWORD___IS_TRIVIALLY_ASSIGNABLE:
    case TokenKind::KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE:
    case TokenKind::KEYWORD___IS_TRIVIALLY_COPYABLE:
    case TokenKind::KEYWORD___IS_UNION:
    case TokenKind::KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS:
    case TokenKind::KEYWORD___UNDERLYING_TYPE:
    case TokenKind::KEYWORD___REFERENCE_BINDS_TO_TEMPORARY:
    case TokenKind::KEYWORD___IS_LVALUE_EXPRESSION:
    case TokenKind::KEYWORD___IS_RVALUE_EXPRESSION:
    case TokenKind::KEYWORD___IS_ARITHMETIC:
    case TokenKind::KEYWORD___IS_FLOATING_POINT:
    case TokenKind::KEYWORD___IS_INTEGRAL:
    case TokenKind::KEYWORD___IS_COMPLETE_TYPE:
    case TokenKind::KEYWORD___IS_VOID:
    case TokenKind::KEYWORD___IS_ARRAY:
    case TokenKind::KEYWORD___IS_FUNCTION:
    case TokenKind::KEYWORD___IS_REFERENCE:
    case TokenKind::KEYWORD___IS_LVALUE_REFERENCE:
    case TokenKind::KEYWORD___IS_RVALUE_REFERENCE:
    case TokenKind::KEYWORD___IS_FUNDAMENTAL:
    case TokenKind::KEYWORD___IS_OBJECT:
    case TokenKind::KEYWORD___IS_SCALAR:
    case TokenKind::KEYWORD___IS_COMPOUND:
    case TokenKind::KEYWORD___IS_POINTER:
    case TokenKind::KEYWORD___IS_MEMBER_OBJECT_POINTER:
    case TokenKind::KEYWORD___IS_MEMBER_FUNCTION_POINTER:
    case TokenKind::KEYWORD___IS_MEMBER_POINTER:
    case TokenKind::KEYWORD___IS_CONST:
    case TokenKind::KEYWORD___IS_VOLATILE:
    case TokenKind::KEYWORD___IS_SIGNED:
    case TokenKind::KEYWORD___IS_UNSIGNED:
    case TokenKind::KEYWORD___IS_SAME:
    case TokenKind::KEYWORD___IS_CONVERTIBLE:
    case TokenKind::KEYWORD___ARRAY_RANK:
    case TokenKind::KEYWORD___ARRAY_EXTENT:
    case TokenKind::KEYWORD___PRIVATE_EXTERN__:
    case TokenKind::KEYWORD___MODULE_PRIVATE__:
    case TokenKind::KEYWORD___DECLSPEC:
    case TokenKind::KEYWORD___CDECL:
    case TokenKind::KEYWORD___STDCALL:
    case TokenKind::KEYWORD___FASTCALL:
    case TokenKind::KEYWORD___THISCALL:
    case TokenKind::KEYWORD___REGCALL:
    case TokenKind::KEYWORD___VECTORCALL:
    case TokenKind::KEYWORD___FORCEINLINE:
    case TokenKind::KEYWORD___UNALIGNED:
    case TokenKind::KEYWORD___SUPER:
    case TokenKind::KEYWORD___GLOBAL:
    case TokenKind::KEYWORD___LOCAL:
    case TokenKind::KEYWORD___CONSTANT:
    case TokenKind::KEYWORD___PRIVATE:
    case TokenKind::KEYWORD___GENERIC:
    case TokenKind::KEYWORD___KERNEL:
    case TokenKind::KEYWORD___READ_ONLY:
    case TokenKind::KEYWORD___WRITE_ONLY:
    case TokenKind::KEYWORD___READ_WRITE:
    case TokenKind::KEYWORD___BUILTIN_ASTYPE:
    case TokenKind::KEYWORD_VEC_STEP:
    case TokenKind::KEYWORD_IMAGE_1D_T:
    case TokenKind::KEYWORD_IMAGE_1D_ARRAY_T:
    case TokenKind::KEYWORD_IMAGE_1D_BUFFER_T:
    case TokenKind::KEYWORD_IMAGE_2D_T:
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_T:
    case TokenKind::KEYWORD_IMAGE_2D_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE_2D_MSAA_T:
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_MSAA_T:
    case TokenKind::KEYWORD_IMAGE_2D_MSAA_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE_2D_ARRAY_MSAA_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE_3D_T:
    case TokenKind::KEYWORD_PIPE:
    case TokenKind::KEYWORD_ADDRSPACE_CAST:
    case TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN:
    case TokenKind::KEYWORD___PASCAL:
    case TokenKind::KEYWORD___VECTOR:
    case TokenKind::KEYWORD___PIXEL:
    case TokenKind::KEYWORD___BRIDGE:
    case TokenKind::KEYWORD___BRIDGE_TRANSFER:
    case TokenKind::KEYWORD___BRIDGE_RETAINED:
    case TokenKind::KEYWORD___BRIDGE_RETAIN:
    case TokenKind::KEYWORD___COVARIANT:
    case TokenKind::KEYWORD___CONTRAVARIANT:
    case TokenKind::KEYWORD___KINDOF:
    case TokenKind::KEYWORD__NONNULL:
    case TokenKind::KEYWORD__NULLABLE:
    case TokenKind::KEYWORD__NULLABLE_RESULT:
    case TokenKind::KEYWORD__NULL_UNSPECIFIED:
    case TokenKind::KEYWORD___UUIDOF:
    case TokenKind::KEYWORD___TRY:
    case TokenKind::KEYWORD___FINALLY:
    case TokenKind::KEYWORD___LEAVE:
    case TokenKind::KEYWORD___IF_EXISTS:
    case TokenKind::KEYWORD___IF_NOT_EXISTS:
    case TokenKind::KEYWORD___SINGLE_INHERITANCE:
    case TokenKind::KEYWORD___MULTIPLE_INHERITANCE:
    case TokenKind::KEYWORD___VIRTUAL_INHERITANCE:
    case TokenKind::KEYWORD___INTERFACE:
    case TokenKind::KEYWORD___BUILTIN_CONVERTVECTOR:
    case TokenKind::KEYWORD___BUILTIN_BIT_CAST:
    case TokenKind::KEYWORD___BUILTIN_AVAILABLE:
    case TokenKind::KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME:
    case TokenKind::KEYWORD___UNKNOWN_ANYTYPE:
      return TokenCategory::KEYWORD;
    case TokenKind::PP_IF:
    case TokenKind::PP_IFDEF:
    case TokenKind::PP_IFNDEF:
    case TokenKind::PP_ELIF:
    case TokenKind::PP_ELIFDEF:
    case TokenKind::PP_ELIFNDEF:
    case TokenKind::PP_ELSE:
    case TokenKind::PP_ENDIF:
    case TokenKind::PP_DEFINED:
    case TokenKind::PP_INCLUDE:
    case TokenKind::PP___INCLUDE_MACROS:
    case TokenKind::PP_DEFINE:
    case TokenKind::PP_UNDEF:
    case TokenKind::PP_LINE:
    case TokenKind::PP_ERROR:
    case TokenKind::PP_PRAGMA:
    case TokenKind::PP_IMPORT:
    case TokenKind::PP_INCLUDE_NEXT:
    case TokenKind::PP_WARNING:
    case TokenKind::PP_IDENTIFIER:
    case TokenKind::PP_SCCS:
    case TokenKind::PP_ASSERT:
    case TokenKind::PP_UNASSERT:
    case TokenKind::PP___PUBLIC_MACRO:
    case TokenKind::PP___PRIVATE_MACRO:
      return TokenCategory::MACRO_DIRECTIVE_NAME;
    case TokenKind::OBJC_AT_CLASS:
    case TokenKind::OBJC_AT_COMPATIBILITY_ALIAS:
    case TokenKind::OBJC_AT_DEFINITIONS:
    case TokenKind::OBJC_AT_ENCODE:
    case TokenKind::OBJC_AT_OBJC_END:
    case TokenKind::OBJC_AT_IMPLEMENTATION:
    case TokenKind::OBJC_AT_INTERFACE:
    case TokenKind::OBJC_AT_PRIVATE:
    case TokenKind::OBJC_AT_PROTECTED:
    case TokenKind::OBJC_AT_PROTOCOL:
    case TokenKind::OBJC_AT_PUBLIC:
    case TokenKind::OBJC_AT_SELECTOR:
    case TokenKind::OBJC_AT_THROW:
    case TokenKind::OBJC_AT_TRY:
    case TokenKind::OBJC_AT_CATCH:
    case TokenKind::OBJC_AT_FINALLY:
    case TokenKind::OBJC_AT_SYNCHRONIZED:
    case TokenKind::OBJC_AT_AUTORELEASEPOOL:
    case TokenKind::OBJC_AT_PROPERTY:
    case TokenKind::OBJC_AT_PACKAGE:
    case TokenKind::OBJC_AT_REQUIRED:
    case TokenKind::OBJC_AT_OPTIONAL:
    case TokenKind::OBJC_AT_SYNTHESIZE:
    case TokenKind::OBJC_AT_DYNAMIC:
    case TokenKind::OBJC_AT_IMPORT:
    case TokenKind::OBJC_AT_AVAILABLE:
      return TokenCategory::OBJECTIVE_C_KEYWORD;
    case TokenKind::IDENTIFIER:
      return TokenCategory::IDENTIFIER;
    default:
      return TokenCategory::UNKNOWN;
  }
}

static TokenCategory ClassifyMacro(const Token &tok, MacroId id) {
  switch (tok.kind()) {
    case TokenKind::PP_IF:
    case TokenKind::PP_IFDEF:
    case TokenKind::PP_IFNDEF:
    case TokenKind::PP_ELIF:
    case TokenKind::PP_ELIFDEF:
    case TokenKind::PP_ELIFNDEF:
    case TokenKind::PP_ELSE:
    case TokenKind::PP_ENDIF:
    case TokenKind::PP_DEFINED:
    case TokenKind::PP_INCLUDE:
    case TokenKind::PP___INCLUDE_MACROS:
    case TokenKind::PP_DEFINE:
    case TokenKind::PP_UNDEF:
    case TokenKind::PP_LINE:
    case TokenKind::PP_ERROR:
    case TokenKind::PP_PRAGMA:
    case TokenKind::PP_IMPORT:
    case TokenKind::PP_INCLUDE_NEXT:
    case TokenKind::PP_WARNING:
    case TokenKind::PP_IDENTIFIER:
    case TokenKind::PP_SCCS:
    case TokenKind::PP_ASSERT:
    case TokenKind::PP_UNASSERT:
    case TokenKind::PP___PUBLIC_MACRO:
    case TokenKind::PP___PRIVATE_MACRO:
      return TokenCategory::MACRO_DIRECTIVE_NAME;

    case TokenKind::IDENTIFIER:
    case TokenKind::ELLIPSIS:  // For variadic parameters.
      switch (id.kind) {
        case MacroKind::DEFINE_DIRECTIVE:
        case MacroKind::EXPANSION:
        case MacroKind::SUBSTITUTION:
          return TokenCategory::MACRO_NAME;
        case MacroKind::PARAMETER:
          return TokenCategory::MACRO_PARAMETER_NAME;
        default:
          break;
      }
      break;
    default:
      break;
  }
  return ClassifyToken(tok);
}

static inline TokenCategory Rebase(DeclCategory category) {
  return static_cast<TokenCategory>(
      int(category) + int(TokenCategory::COMMENT));
}

static TokenCategory ClassifyDecl(const Token &tok, DeclarationId id) {
  switch (id.kind) {
    case DeclKind::NAMESPACE:
    case DeclKind::NAMESPACE_ALIAS:
    case DeclKind::USING_DIRECTIVE:
      return TokenCategory::NAMESPACE;

    case DeclKind::NON_TYPE_TEMPLATE_PARM:
      return TokenCategory::TEMPLATE_PARAMETER_VALUE;

    case DeclKind::TEMPLATE_TEMPLATE_PARM:
      return TokenCategory::TEMPLATE_PARAMETER_TYPE;

    case DeclKind::TEMPLATE_PARAM_OBJECT:
      return TokenCategory::TEMPLATE_PARAMETER_VALUE;

    case DeclKind::TEMPLATE_TYPE_PARM:
      return TokenCategory::TEMPLATE_PARAMETER_TYPE;

    case DeclKind::CONCEPT:
    case DeclKind::BUILTIN_TEMPLATE:
    case DeclKind::CLASS_TEMPLATE:
    case DeclKind::VAR_TEMPLATE:
    case DeclKind::FUNCTION_TEMPLATE:
    case DeclKind::TYPE_ALIAS_TEMPLATE: {
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }

      switch (id.kind) {
        case DeclKind::CONCEPT:
          return TokenCategory::CONCEPT;
        case DeclKind::BUILTIN_TEMPLATE:
          return TokenCategory::BUILTIN_TYPE_NAME;
        case DeclKind::CLASS_TEMPLATE:
          return TokenCategory::CLASS;
        case DeclKind::VAR_TEMPLATE:
          return TokenCategory::GLOBAL_VARIABLE;
        case DeclKind::FUNCTION_TEMPLATE:
          return TokenCategory::FUNCTION;
        case DeclKind::TYPE_ALIAS_TEMPLATE:
          return TokenCategory::TYPE_ALIAS;
        default:
          break;
      }
      break;
    }
    case DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        if (auto spec = ClassScopeFunctionSpecializationDecl::from(
                std::get<Decl>(ent))) {
          return Rebase(spec->specialization().category());
        }
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::INSTANCE_METHOD;

    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
    case DeclKind::VAR_TEMPLATE_SPECIALIZATION:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::STRUCT;

    case DeclKind::ENUM:
      return TokenCategory::ENUM;
    case DeclKind::ENUM_CONSTANT:
      return TokenCategory::ENUMERATOR;
    case DeclKind::RECORD:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::STRUCT;

    case DeclKind::USING_ENUM:
      return TokenCategory::ENUM;

    case DeclKind::TYPEDEF:
    case DeclKind::USING:
    case DeclKind::UNRESOLVED_USING_TYPENAME:
    case DeclKind::UNRESOLVED_USING_IF_EXISTS:
      return TokenCategory::TYPE_ALIAS;

    case DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
      return TokenCategory::CLASS;

    case DeclKind::FUNCTION:
      return TokenCategory::FUNCTION;

    case DeclKind::CXX_CONSTRUCTOR:
    case DeclKind::CXX_CONVERSION:
    case DeclKind::CXX_DEDUCTION_GUIDE:
    case DeclKind::CXX_DESTRUCTOR:
      return TokenCategory::INSTANCE_METHOD;

    case DeclKind::CXX_METHOD:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::INSTANCE_METHOD;

    case DeclKind::OBJ_C_METHOD:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::INSTANCE_METHOD;

    case DeclKind::LABEL:
      return TokenCategory::LABEL;

    case DeclKind::USING_PACK:
    case DeclKind::USING_SHADOW:
      return TokenCategory::TEMPLATE_PARAMETER_TYPE;

    case DeclKind::BINDING:
      return TokenCategory::LOCAL_VARIABLE;

    case DeclKind::INDIRECT_FIELD:
    case DeclKind::FIELD:
      return TokenCategory::INSTANCE_MEMBER;

    case DeclKind::PARM_VAR:
      return TokenCategory::PARAMETER_VARIABLE;
    case DeclKind::IMPLICIT_PARAM:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::PARAMETER_VARIABLE;
    case DeclKind::VAR:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      return TokenCategory::LOCAL_VARIABLE;

    default:
      if (auto ent = tok.related_entity(); std::holds_alternative<Decl>(ent)) {
        return Rebase(std::get<Decl>(ent).category());
      }
      break;
  }

done:
  return ClassifyToken(tok);
}

static TokenCategory ClassifyEntity(const Token &tok) {
  VariantId vid = tok.related_entity_id().Unpack();
  if (std::holds_alternative<MacroId>(vid)) {
    return ClassifyMacro(tok, std::get<MacroId>(vid));

  } else if (std::holds_alternative<DeclarationId>(vid)) {
    return ClassifyDecl(tok, std::get<DeclarationId>(vid));

  } else {
    return ClassifyToken(tok);
  }
}

}  // namespace

TokenReader::~TokenReader(void) noexcept {}

const FragmentImpl *TokenReader::OwningFragment(void) const noexcept {
  return nullptr;
}

const FileImpl *TokenReader::OwningFile(void) const noexcept {
  return nullptr;
}

TokenReader::Ptr TokenReader::ReaderForToken(
    const TokenReader::Ptr &self, const EntityProvider::Ptr &ep, EntityId eid) {

  VariantId vid = eid.Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);

    FileImpl::Ptr file;
    if (auto self_file = self->OwningFile();
        self_file && self_file->file_id == tid.file_id) {
      file = FileImpl::Ptr(self, self_file);
    } else {
      FileId fid(tid.file_id);
      file = ep->FileFor(ep, SpecificEntityId<FileId>(fid));
    }

    if (file && tid.offset < file->num_tokens) {
      return file->TokenReader(file);
    }

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    FragmentImpl::Ptr frag;
    if (auto self_frag = self->OwningFragment();
        self_frag && self_frag->fragment_id == tid.fragment_id) {
      frag = FragmentImpl::Ptr(self, self_frag);
    } else {
      frag = ep->FragmentFor(ep, fid);
    }

    if (frag && tid.offset < frag->num_parsed_tokens) {
      return frag->ParsedTokenReader(frag);
    }

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    FragmentImpl::Ptr frag;
    if (auto self_frag = self->OwningFragment();
        self_frag && self_frag->fragment_id == tid.fragment_id) {
      frag = FragmentImpl::Ptr(self, self_frag);
    } else {
      frag = ep->FragmentFor(ep, fid);
    }

    if (frag && tid.offset < frag->num_tokens) {
      return frag->MacroTokenReader(frag);
    }
  }

  return kInvalidTokenReader;
}

InvalidTokenReader::~InvalidTokenReader(void) noexcept {}

// Return the number of tokens accessible to this reader.
unsigned InvalidTokenReader::NumTokens(void) const {
  return 0u;
}

// Return the kind of the Nth token.
TokenKind InvalidTokenReader::NthTokenKind(unsigned) const {
  return TokenKind::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view InvalidTokenReader::NthTokenData(unsigned) const {
  return {};
}

// Return the id of the token from which the Nth token is derived.
EntityId InvalidTokenReader::NthDerivedTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId InvalidTokenReader::NthParsedTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the macro containing the Nth token.
EntityId InvalidTokenReader::NthContainingMacroId(unsigned) const {
  return kInvalidEntityId;
}

// Return an entity id associated with the Nth token.
EntityId InvalidTokenReader::NthRelatedEntityId(unsigned) const {
  return kInvalidEntityId;
}

// Return the id of the Nth token.
EntityId InvalidTokenReader::NthTokenId(unsigned) const {
  return kInvalidEntityId;
}

EntityId InvalidTokenReader::NthFileTokenId(unsigned) const {
  return kInvalidEntityId;
}

// Return the token reader for another file.
TokenReader::Ptr InvalidTokenReader::ReaderForToken(
    const Ptr &self, RawEntityId id) const {
  return {};
}

// Returns `true` if `this` is logically equivalent to `that`.
bool InvalidTokenReader::Equals(const TokenReader *) const {
  return false;
}

Token::Token(void)
    : impl(kInvalidTokenReader),
      offset(0) {}

// Return `true` if this is a valid token.
Token::operator bool(void) const {
  return !dynamic_cast<const InvalidTokenReader *>(impl.get());
}

// Kind of this token.
TokenKind Token::kind(void) const {
  return impl->NthTokenKind(offset);
}

// Return the data of this token.
std::string_view Token::data(void) const & {
  return impl->NthTokenData(offset);
}

// Return the ID of this token.
EntityId Token::id(void) const {
  return impl->NthTokenId(offset);
}

// Return the version of this token that was actually parsed. If this was a
// macro token that only relates to a single parsed token, then that is
// returned. If this is a macro token that doesn't relate to any parsed
// tokens, or relates to more than one, then nothing is returned.
std::optional<Token> Token::parsed_token(void) const {
  VariantId vid = impl->NthParsedTokenId(offset).Unpack();
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    return *this;
  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    FragmentImpl::Ptr frag(impl, impl->OwningFragment());
    return Token(frag->MacroTokenReader(frag),
                 std::get<MacroTokenId>(vid).offset);
  } else {
    return std::nullopt;
  }
}

// Return the token from which this token was derived. This can be a macro
// token or a file token.
std::optional<Token> Token::derived_token(void) const {
  EntityId eid = impl->NthDerivedTokenId(offset);
  VariantId vid = eid.Unpack();

  unsigned offset = 0u;

  if (std::holds_alternative<FileTokenId>(vid)) {
    offset = std::get<FileTokenId>(vid).offset;

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    offset = std::get<ParsedTokenId>(vid).offset;

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    offset = std::get<MacroTokenId>(vid).offset;

  } else {
    return std::nullopt;
  }

  auto reader = impl->ReaderForToken(impl, eid.Pack());
  if (!reader) {
    assert(false);  // Should always get a reader.
    return std::nullopt;
  }

  auto num_tokens = reader->NumTokens();
  if (offset >= num_tokens) {
    assert(false);
    return std::nullopt;
  }

  return Token(std::move(reader), offset);
}

// Return the version of this token from a file, if any. If this is a parsed
// or macro token, then this will walk the derivation chain back to a file
// token.
std::optional<Token> Token::file_token(void) const {
  EntityId eid(impl->NthFileTokenId(offset));
  VariantId vid = eid.Unpack();
  if (!std::holds_alternative<FileTokenId>(vid)) {
    return std::nullopt;
  }

  FileTokenId fid = std::get<FileTokenId>(vid);
  auto fr = impl->ReaderForToken(impl, eid.Pack());
  if (!fr) {
    return std::nullopt;
  }

  return Token(std::move(fr), fid.offset);
}

// Return the version of this token from a file, if any. If there isn't a
// one-to-one correspondence between this token and a file token, then it
// likely means this token exists inside of a macro expansion. If that is the
// case, then this will return the beginning token of the macro expansion.
std::optional<Token> Token::nearest_file_token(void) const {
  for (auto i = 0u; i <= offset; ++i) {
    EntityId eid(impl->NthFileTokenId(offset - i));
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (auto fr = impl->ReaderForToken(impl, eid.Pack())) {
        return Token(std::move(fr), fid.offset);
      }
    }
  }

  return std::nullopt;
}

// The category of this token. This takes into account any related entities.
TokenCategory Token::category(void) const {
  return ClassifyEntity(*this);
}

// Return the ID entity associated with this token.
//
// NOTE(pag): This is only meaningful for parsed tokens and macro tokens.
EntityId Token::related_entity_id(void) const {
  return impl->NthRelatedEntityId(offset);
}

// Return the entity associated with this token.
VariantEntity Token::related_entity(void) const {
  EntityId eid = impl->NthRelatedEntityId(offset);
  if (auto tok_frag = impl->OwningFragment()) {
    return Index(tok_frag->ep).entity(eid);
  } else if (auto tok_file = impl->OwningFile()) {
    return Index(tok_file->ep).entity(eid);
  } else {
    return {};
  }
}

// Return the set of all uses of this token within its fragment (if it's a
// fragment token).
UseRange<TokenUseSelector> Token::uses(void) const {
  if (auto frag = Fragment::containing(*this)) {
    FragmentImpl::Ptr frag_ptr = std::move(frag->impl);
    return std::make_shared<UseIteratorImpl>(std::move(frag_ptr), *this);
  } else {
    return {};
  }
}

TokenRange::TokenRange(void)
    : impl(kInvalidTokenReader),
      index(0),
      num_tokens(0) {}

TokenRange::TokenRange(const Token &tok)
    : impl(tok.impl),
      index(tok.offset),
      num_tokens(tok.impl ? (tok.offset + 1u) : 0u) {}

// Return the token at index `index`.
Token TokenRange::operator[](size_t relative_index) const {
  auto effective_index = (index + relative_index);
  if (effective_index >= num_tokens) {
    throw std::out_of_range(
        "Index " + std::to_string(relative_index) +
        " is out of range on mx::TokenRange");
  } else {
    return Token(impl, effective_index);
  }
}

// Return the first token.
Token TokenRange::front(void) const {
  return Token(impl, index);
}

// Return the last token.
Token TokenRange::back(void) const {
  return Token(impl, num_tokens - 1u);
}

// Return a slice of this token range. If the indices given are invalid, then
// an empty token range is returned. The indices cover the tokens in the
// exclusive range `[start_index, end_index)`.
TokenRange TokenRange::slice(size_t start_index,
                             size_t end_index) const noexcept {
  if (end_index <= start_index || start_index >= num_tokens ||
      end_index > num_tokens || (index + start_index) >= num_tokens ||
      (index + end_index) > num_tokens ||
      static_cast<unsigned>(index + start_index) != (index + start_index) ||
      static_cast<unsigned>(index + end_index) != (index + end_index)) {
    return TokenRange();
  } else {
    return TokenRange(impl, static_cast<unsigned>(index + start_index),
                      static_cast<unsigned>(index + end_index));
  }
}

// Returns the index of `that` in this range, or `std::nullopt`.
std::optional<unsigned> TokenRange::index_of(const Token &that) const noexcept {
  if (!impl || !impl->Equals(that.impl.get())) {
    return std::nullopt;
  }

  VariantId vid = EntityId(that.id()).Unpack();
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    auto id = std::get<ParsedTokenId>(vid);
    if (id.offset < index) {
      return std::nullopt;
    }

    if (id.offset >= num_tokens) {
      return std::nullopt;
    }

    return id.offset - index;

  } else if (std::holds_alternative<FileTokenId>(vid)) {
    auto id = std::get<FileTokenId>(vid);
    if (id.offset < index) {
      return std::nullopt;
    }

    if (id.offset >= num_tokens) {
      return std::nullopt;
    }

    return id.offset - index;

  } else {
    return std::nullopt;
  }
}

// Return the underlying token data associated with the tokens covered by this
// token range.
std::string_view TokenRange::data(void) const & {
  if (!impl || impl.get() == kInvalidTokenReader.get() || !num_tokens) {
    return {};
  }

  auto data_begin = impl->NthTokenData(index);
  auto data_end = impl->NthTokenData(num_tokens - 1u);
  auto size = static_cast<size_t>(data_end.data() - data_begin.data()) +
              data_end.size();

  if (static_cast<uint32_t>(size) != size) {
    assert(false);
    return {};
  }

  return std::string_view(data_begin.data(), size);
}

// Convert this token range into a file token range.
TokenRange TokenRange::file_tokens(void) const noexcept {
  TokenRange ret;
  if (!impl || impl.get() == kInvalidTokenReader.get() || !num_tokens) {
    return ret;
  }

  // It's already a file token range.
  if (impl->OwningFile()) {
    return *this;
  }

  RawEntityId file_id = kInvalidEntityId;

  // Find the nearest file token for the first token.
  for (auto i = 0u; i <= index; ++i) {
    EntityId eid(impl->NthFileTokenId(index - i));
    VariantId vid = eid.Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (auto fr = impl->ReaderForToken(impl, eid.Pack())) {
        ret.impl = std::move(fr);
        ret.index = fid.offset;
        file_id = fid.file_id;
        break;
      }
    }
  }

  if (file_id == kInvalidEntityId) {
    return ret;
  }

  // Hope for an exact match with the last token in the range.
  if (auto last_fid = impl->NthFileTokenId(num_tokens - 1u);
      last_fid != EntityId{}) {
    VariantId vid = EntityId(last_fid).Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (fid.file_id == file_id) {
        ret.num_tokens = std::max(ret.index, fid.offset) + 1u;
        ret.index = std::min(ret.index, fid.offset);
        return ret;
      }
    }
  }

  // Try to find the file token for one-past-the-end of this token range, then
  // we'll take the file token from before that. Failing that, we'll need to
  // match up on the exact token, then mark the num tokens as that token's
  // offset plus one.
  auto offset_shift = 0u;
  for (auto i = 0u; i <= num_tokens; ++i) {
    VariantId vid = EntityId(impl->NthFileTokenId(num_tokens - i)).Unpack();
    if (std::holds_alternative<FileTokenId>(vid)) {
      FileTokenId fid = std::get<FileTokenId>(vid);
      if (fid.file_id == file_id) {
        if (fid.offset >= ret.index) {
          ret.num_tokens = fid.offset + offset_shift;
          return ret;
        } else {
          break;  // TODO(pag): Come up with a better thing.
        }
      }
    }
    offset_shift = 1u;
  }

  // Worst case, the range of the only token :-/
  ret.num_tokens = ret.index + 1u;
  return ret;
}

// Strip leading and trailing whitespace.
TokenRange TokenRange::strip_whitespace(void) const noexcept {
  TokenRange ret(*this);
  for (; ret.index < ret.num_tokens; ++ret.index) {
    const TokenKind kind = impl->NthTokenKind(ret.index);
    if (kind == TokenKind::WHITESPACE) {
      continue;
    } else if (kind == TokenKind::UNKNOWN &&
               impl->NthTokenData(ret.index).empty()) {
      continue;
    } else {
      break;
    }
  }

  for (; ret.num_tokens > ret.index; --ret.num_tokens) {
    const TokenKind kind = impl->NthTokenKind(ret.num_tokens - 1u);
    if (kind == TokenKind::WHITESPACE) {
      continue;
    } else if (kind == TokenKind::UNKNOWN &&
               impl->NthTokenData(ret.num_tokens - 1u).empty()) {
      continue;
    } else {
      break;
    }
  }

  if (ret.num_tokens <= ret.index) {
    ret.num_tokens = 0;
    ret.index = 0;
  }

  return ret;
}

}  // namespace mx