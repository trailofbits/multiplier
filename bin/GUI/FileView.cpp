// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "FileView.h"

#include <QColor>
#include <QFont>
#include <QPainter>
#include <QSplitter>
#include <QString>
#include <QThreadPool>
#include <QVBoxLayout>
#include <iostream>
#include <map>
#include <vector>
#include <set>

namespace mx::gui {
namespace {

enum class FileViewState {
  kInitialized,
  kDownloading,
  kRendering,
  kRendered,
  kFailed
};

static const QString peters_theme(R"(
.sc_area {
  font-size: 18px;
}

.sc_code_line {
  background-color: rgb(20,20,20);
  color: rgb(224,0,1);  /* Highlight what isn't colored */
  padding-left: 10px;
}

.sc_number_line {
  background-color: rgb(30,30,30);
  color: rgb(108,131,139);
  text-align: right;
  padding-right: 10px;
}

.sc_disabled {
  color: rgb(114,114,114);
}

.sc_comment {
  color: rgb(105,104,97);
}

.sc_keyword {
  color: rgb(181,116,122);
}

.sc_pp_keyword {
  color: rgb(114,111,58);
  font-weight: bold;
}

.sc_objc_keyword {
  color: rgb(181,116,122);
}

.sc_type_builtin {
  color: rgb(115,61,60);
}

.sc_type_alias {
  color: rgb(3,171,108);
  font-weight: bold;
}

.sc_namespace {
  color: rgb(95,154,160);
  font-style: italic;
}

.sc_function {
  color: rgb(126,125,186);
  font-weight: bold;
}

.sc_class {
  color: rgb(0,177,110);
  font-weight: bold;
}

.sc_struct {
  color: rgb(0,177,110);
  font-weight: bold;
}

.sc_union {
  color: rgb(0,177,110);
  font-weight: bold;
}

.sc_interface {
  color: rgb(0,177,110);
  font-weight: bold;
}

.sc_enum {
  color: rgb(175,144,65);
  font-style: italic;
}

.sc_enumerator {
  color: rgb(113,163,98);
  font-style: italic;
}

/* An entity that only has a declaration. */
.sc_declaration_only {
  color: rgb(167,81,226,255) !important;
  font-weight: bold !important;
}

.sc_macro {
  color: rgb(121,244,241);
}

.sc_literal {
  color: rgb(226,211,148);
}

.sc_label {
  color: rgb(149,149,149);
}

.sc_class_member {
  color: rgb(170,129,52);
  font-style: italic; 
}

.sc_instance_member {
  color: rgb(207,130,235);
}

.sc_class_method {
  color: rgb(170,129,52);
  font-style: italic; 
}

.sc_instance_method {
  color: rgb(126,125,186);
  font-weight: bold;
}

.sc_local_variable {
  color: rgb(198,125,237);
}

.sc_parameter_variable {
  color: rgb(172,122,180);
}

.sc_global_variable {
  color: rgb(198,163,73);
  font-weight: bold;
  font-style: italic;
}

.sc_template_parameter_type {
  color: rgb(202,120,29);
}

.sc_template_parameter_value {
  color: rgb(174,144,65);
  font-style: italic;
}

.sc_punctuation {
  color: rgb(93,93,93);
}
)");

static const QString css(R"(
<style type="text/css">
a, a:hover, a:visited, a:active {
  text-decoration: none;
}
%1
</style>
)");
static const QString table_begin(R"(
<table cellpadding="0" cellspacing="0" border="0" width="100%" class="sc_area">
<tr>
<td class="sc_number_line" id="line1">1</td>
<td class="sc_code_line" width="100%">)");

static const QString table_end("</td></tr></table>");

static const QString token_link("<a href=\"%1\" class=\"%2\">%3</a>");
static const QString token_nolink("<span class=\"%1\">%2</a>");

static const QString new_line(R"(
</td></tr><tr><td class="sc_number_line" id="line%1">%1</td><td class="sc_code_line">
)");

static const QString space("&nbsp;");
static const QString tab("&nbsp;&nbsp;&nbsp;&nbsp;");

namespace sc {
static const QString none;
static const QString disabled = "sc_disabled";
static const QString comment = "sc_comment";
static const QString literal = "sc_literal";
static const QString punctuation = "sc_punctuation";
static const QString type_builtin = "sc_type_builtin";
static const QString keyword = "sc_keyword";
static const QString pp_keyword = "sc_pp_keyword";
static const QString objc_keyword = "sc_objc_keyword";
static const QString macro = "sc_macro";
static const QString local_variable = "sc_local_variable";
static const QString global_variable = "sc_global_variable";
static const QString parameter_variable = "sc_parameter_variable";
static const QString function = "sc_function";
static const QString instance_method = "sc_instance_method";
static const QString instance_member = "sc_instance_member";
static const QString class_method = "sc_instance_method";
static const QString class_member = "sc_instance_member";
static const QString class_ = "sc_class";
static const QString struct_ = "sc_struct";
static const QString union_ = "sc_union";
static const QString interface_ = "sc_interface";
static const QString enum_ = "sc_enum";
static const QString enumerator = "sc_enumerator";
static const QString namespace_ = "sc_namespace";
static const QString type_alias = "sc_type_alias";
static const QString template_parameter_type = "sc_template_parameter_type";
static const QString template_parameter_value = "sc_template_parameter_value";
static const QString label = "sc_label";
}  // namespace sc

static const QString *BaselineTokenClass(TokenKind kind) {
  switch (kind) {
    default:
      return nullptr;
    case TokenKind::COMMENT:
      return &sc::comment;
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
      return &sc::literal;
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
      return &sc::punctuation;
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
      return &sc::type_builtin;

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
    case TokenKind::KEYWORD_IMAGE1_DT:
    case TokenKind::KEYWORD_IMAGE1_DARRAY_T:
    case TokenKind::KEYWORD_IMAGE1_DBUFFER_T:
    case TokenKind::KEYWORD_IMAGE2_DT:
    case TokenKind::KEYWORD_IMAGE2_DARRAY_T:
    case TokenKind::KEYWORD_IMAGE2_DDEPTH_T:
    case TokenKind::KEYWORD_IMAGE2_DARRAY_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE2_DMSAA_T:
    case TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_T:
    case TokenKind::KEYWORD_IMAGE2_DMSAA_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T:
    case TokenKind::KEYWORD_IMAGE3_DT:
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
      return &sc::keyword;
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
      return &sc::pp_keyword;
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
      return &sc::objc_keyword;
    case TokenKind::BEGIN_OF_MACRO_EXPANSION_MARKER:
      return &sc::macro;
  }
}

static const QString *DeclCategoryToSyntaxColor(DeclCategory category) {
  switch (category) {
    case DeclCategory::UNKNOWN:
      break;
    case DeclCategory::LOCAL_VARIABLE:
      return &sc::local_variable;
    case DeclCategory::GLOBAL_VARIABLE:
      return &sc::global_variable;
    case DeclCategory::PARAMETER_VARIABLE:
      return &sc::parameter_variable;
    case DeclCategory::FUNCTION:
      return &sc::function;
    case DeclCategory::INSTANCE_METHOD:
      return &sc::instance_method;
    case DeclCategory::INSTANCE_MEMBER:
      return &sc::instance_member;
    case DeclCategory::CLASS_METHOD:
      return &sc::class_method;
    case DeclCategory::CLASS_MEMBER:
      return &sc::class_member;
    case DeclCategory::THIS:
      return &sc::parameter_variable;
    case DeclCategory::CLASS:
      return &sc::class_;
    case DeclCategory::STRUCTURE:
      return &sc::struct_;
    case DeclCategory::UNION:
      return &sc::union_;
    case DeclCategory::INTERFACE:
      return &sc::interface_;
    case DeclCategory::ENUMERATION:
      return &sc::enum_;
    case DeclCategory::ENUMERATOR:
      return &sc::enumerator;
    case DeclCategory::NAMESPACE:
      return &sc::namespace_;
    case DeclCategory::TYPE_ALIAS:
      return &sc::type_alias;
    case DeclCategory::TEMPLATE_TYPE_PARAMETER:
      return &sc::template_parameter_type;
    case DeclCategory::TEMPLATE_VALUE_PARAMETER:
      return &sc::template_parameter_value;
    case DeclCategory::LABEL:
      return &sc::label;
  }
  return nullptr;
}

static const QString *VisitStmt(const Stmt &stmt, const Token &frag_token) {
  if (auto dre = DeclRefExpr::from(stmt)) {
    if (auto named_decl = NamedDecl::from(dre->declaration())) {
      if (named_decl->name() == frag_token.data() &&
          dre->expression_token().id() == frag_token.id()) {
        return DeclCategoryToSyntaxColor(named_decl->category());
      }
    }
  } else if (auto me = MemberExpr::from(stmt)) {
    auto member_decl = me->member_declaration();
    if (member_decl.name() == frag_token.data() &&
        me->member_token().id() == frag_token.id()) {
      return DeclCategoryToSyntaxColor(member_decl.category());
    } else {
      return VisitStmt(me->base(), frag_token);
    }
  } else if (auto ce = CXXConstructExpr::from(stmt)) {
    auto constructor_decl = ce->constructor();
    if (constructor_decl.name() == frag_token.data() &&
        ce->token().id() == frag_token.id()) {
      return DeclCategoryToSyntaxColor(constructor_decl.category());
    }
  }
  return nullptr;
}

static const QString *VisitType(const Type &type, const Token &frag_token) {
  if (auto typedef_type = TypedefType::from(type)) {
    auto typedef_decl = typedef_type->declaration();
    if (typedef_decl.name() == frag_token.data()) {
      return DeclCategoryToSyntaxColor(typedef_decl.category());
    }

  } else if (auto tag_type = TagType::from(type)) {
    auto tag_decl = tag_type->declaration();
    if (tag_decl.name() == frag_token.data()) {
      return DeclCategoryToSyntaxColor(tag_decl.category());
    }

  } else if (auto unqual_type = type.unqualified_type();
             unqual_type.id() != type.id()) {
    return VisitType(unqual_type, frag_token);
  }
  return nullptr;
}

static const QString *FragmentTokenClass(const Token &frag_token) {
  const QString *backup_sc = nullptr;

  for (auto context = TokenContext::of(frag_token); context;
       context = context->parent()) {
    if (auto stmt = context->as_statement()) {
      if (auto sc = VisitStmt(stmt.value(), frag_token)) {
        return sc;
      } else {
        return backup_sc;
      }
    }

    if (backup_sc) {
      continue;
    }

    if (auto decl = context->as_declaration()) {
      if (auto named_decl = NamedDecl::from(decl);
          named_decl && named_decl->name() == frag_token.data()) {
        backup_sc = DeclCategoryToSyntaxColor(decl->category());
      }
    } else if (auto type = context->as_type()) {
      backup_sc = VisitType(type.value(), frag_token);
    }
  }

  return backup_sc;
}

const QString &TokenClass(const Token &file_token,
                          const std::vector<Token> &frag_tokens) {

  const auto tok_kind = file_token.kind();

  // Fragments generally have better information on the identifiers.
  if (tok_kind == TokenKind::IDENTIFIER) {
    for (const Token &frag_token : frag_tokens) {
      if (auto sc = FragmentTokenClass(frag_token)) {
        return *sc;
      }
    }
  }

  for (const Token &frag_token : frag_tokens) {
    if (auto sc = BaselineTokenClass(frag_token.kind())) {
      return *sc;
    }
  }

  if (auto sc = BaselineTokenClass(tok_kind)) {
    return *sc;
  }

  // If it's a token in a fragment, then treat as null.
  if (!frag_tokens.empty()) {
    return sc::none;
  }

  return sc::disabled;
}

}  // namespace

struct FileView::PrivateData {
  FileLocationCache line_number_cache;
  FileViewState state{FileViewState::kInitialized};
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
};

DownloadFileThread::~DownloadFileThread(void) {}

void DownloadFileThread::run(void) {
  auto file = index.file(file_id);  // Download the file.
  if (!file) {
    emit DownloadedFile(true);
    return;
  }

  // Download all of the fragments and build an index of the starting
  // locations of each fragment in this file.
  std::map<RawEntityId, std::vector<TokenList>> fragment_tokens;
  for (auto fragment : Fragment::in(file.value())) {
    for (Token tok : fragment.file_tokens()) {
      fragment_tokens[tok.id()].emplace_back(fragment.parsed_tokens());
      break;
    }
  }

  // We've now downloaded basically everything we need to, so tell the main
  // thread that it can switch to the rendering state.
  emit DownloadedFile(false);

  QString os = css.arg(peters_theme);
  QString ids_os;
  QString tok_part;
  ids_os.reserve(16);
  os.reserve(static_cast<int>(file->data().size()) * 4);

  std::map<RawEntityId, std::vector<Token>> open_matches;

  int line_number = 1;
  os.append(table_begin);

  std::vector<Token> no_fragment_tokens;

  for (Token file_tok : file->tokens()) {
    RawEntityId file_tok_id = file_tok.id();

    // This token corresponds to the beginning of a fragment. We might have a
    // one-to-many mapping of file tokens to fragment tokens. So when we come
    // across the first token
    if (auto fragment_tokens_it = fragment_tokens.find(file_tok_id);
        fragment_tokens_it != fragment_tokens.end()) {
      for (const TokenList &parsed_toks : fragment_tokens_it->second) {
        for (Token parsed_tok : parsed_toks) {
          if (auto file_tok_of_parsed_tok = parsed_tok.file_token()) {
            open_matches[file_tok_of_parsed_tok->id()].push_back(parsed_tok);
          }
        }
      }

      fragment_tokens.erase(file_tok_id);  // Garbage collect.
    }

    ids_os.clear();

    const QString *sc = nullptr;

    if (auto fragment_tokens_it = open_matches.find(file_tok_id);
        fragment_tokens_it != open_matches.end()) {

      for (Token parsed_tok : fragment_tokens_it->second) {
        if (ids_os.size()) {
          ids_os.append('/');
        }
        ids_os.append(QString::number(parsed_tok.id()));
      }

      sc = &(TokenClass(file_tok, fragment_tokens_it->second));
      open_matches.erase(file_tok_id);  // Garbage collect.
    } else {
      sc = &(TokenClass(file_tok, no_fragment_tokens));
    }

    auto append_tok = [] (QString &buff, const QString &anchor,
                          const QString &data, const QString &sc, bool ws) {
      if (data.size()) {
        if (!ws && anchor.size()) {
          buff.append(token_link.arg(anchor).arg(sc).arg(data));
        } else if (!ws && sc.size()) {
          buff.append(token_nolink.arg(sc).arg(data));
        } else {
          buff.append(data);
        }
      }
    };

    bool is_whitespace = true;
    std::string_view utf8_tok = file_tok.data();
    int num_utf8_bytes = static_cast<int>(utf8_tok.size());
    for (QChar ch : QString::fromUtf8(utf8_tok.data(),
                                      num_utf8_bytes).toHtmlEscaped()) {
      switch (ch.unicode()) {
        case QChar::Tabulation:
          tok_part.append(tab);
          break;
        case QChar::Space:
        case QChar::Nbsp:
          tok_part.append(space);
          break;
        case QChar::ParagraphSeparator:
        case QChar::LineFeed:
        case QChar::LineSeparator:
          append_tok(os, ids_os, tok_part, *sc, is_whitespace);
          tok_part.clear();
          is_whitespace = true;
          line_number++;
          os.append(new_line.arg(QString::number(line_number)));
          break;
        case QChar::CarriageReturn:
          continue;
        default:
          tok_part.append(ch);
          is_whitespace = false;
          break;
      }
    }

    append_tok(os, ids_os, tok_part, *sc, is_whitespace);
    tok_part.clear();
  }

  os.append(table_end);

  // We've now rendered the HTML.
  emit RenderedFile(std::move(os));
}

FileView::~FileView(void) {}

FileView::FileView(Index index_, std::filesystem::path file_path,
                   FileId file_id, QWidget *parent)
    : QTabWidget(parent),
      d(std::make_unique<PrivateData>()) {

  d->layout = new QVBoxLayout;
  d->splitter = new QSplitter(Qt::Horizontal);

  d->layout->setContentsMargins(0, 0, 0, 0);
  d->layout->addWidget(d->splitter);

  setMovable(true);
  setTabsClosable(true);
  setDocumentMode(true);
  setTabPosition(TabPosition::North);

  setWindowTitle(file_path.c_str());
  setLayout(d->layout);

  InitializeWidgets();
  DownloadFileInBackground(std::move(index_), file_id);
}

void FileView::DownloadFileInBackground(Index index, FileId file_id) {
  if (d->state != FileViewState::kInitialized) {
    d->state = FileViewState::kFailed;
    return;
  }

  d->state = FileViewState::kDownloading;

  auto downloader = new DownloadFileThread(std::move(index), file_id);
  downloader->setAutoDelete(true);

  connect(downloader, &DownloadFileThread::DownloadedFile,
          this, &FileView::OnDownloadedFile);

  connect(downloader, &DownloadFileThread::RenderedFile,
          this, &FileView::OnRenderedFile);

  QThreadPool::globalInstance()->start(downloader);
}

void FileView::InitializeWidgets(void) {
  QList<int> splitter_sizes;
  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);
  update();
}

void FileView::OnDownloadedFile(bool failed) {
  if (failed) {
    d->state = FileViewState::kFailed;
  } else {
    d->state = FileViewState::kRendering;
  }
  update();
}

void FileView::OnRenderedFile(QString html) {
  QTextBrowser *content = new QTextBrowser;
#ifdef __linux__
  QFont font("Hack");
#else
  QFont font("Monaco");
#endif
  font.setStyleHint(QFont::TypeWriter);
  content->setCurrentFont(font);
  content->setFont(font);
  content->setAcceptRichText(true);
  content->setOpenLinks(false);
  content->setOpenExternalLinks(false);
  content->setHtml(html);

  connect(content, &QTextBrowser::anchorClicked,
          this, &FileView::OnClickToken);

  d->splitter->addWidget(content);
  d->state = FileViewState::kRendered;
  update();
}

void FileView::paintEvent(QPaintEvent *event) {
  QString message;
  switch (d->state) {
    case FileViewState::kInitialized:
      message = tr("Preparing to download...");
      break;
    case FileViewState::kDownloading:
      message = tr("Downloading...");
      break;
    case FileViewState::kRendering:
      message = tr("Rendering...");
      break;
    case FileViewState::kRendered:
      this->QWidget::paintEvent(event);
      return;
    case FileViewState::kFailed:
      message = tr("Failed");
      break;
  }

  static const auto kTextFlags = Qt::AlignCenter | Qt::TextSingleLine;

  QFont message_font = font();
  message_font.setPointSizeF(message_font.pointSizeF() * 2.0);
  message_font.setBold(true);

  QFontMetrics font_metrics(message_font);
  auto message_rect = font_metrics.boundingRect(QRect(0, 0, 0xFFFF, 0xFFFF),
                                                kTextFlags, message);

  const auto &event_rec = event->rect();
  auto message_x_pos = (event_rec.width() / 2) - (message_rect.width() / 2);
  auto message_y_pos = (event_rec.height() / 2) - (message_rect.height() / 2);

  message_rect.moveTo(message_x_pos, message_y_pos);

  QPainter painter(this);
  painter.fillRect(event_rec, palette().color(QPalette::Window));

  painter.setFont(message_font);
  painter.setPen(QPen(palette().color(QPalette::WindowText)));
  painter.drawText(message_rect, kTextFlags, message);

  event->accept();
}

void FileView::OnClickToken(const QUrl &url) {
  std::vector<RawEntityId> token_ids;
  for (QString tok_id_str : url.toString().split('/')) {
    bool ok = true;
    RawEntityId id = tok_id_str.toULongLong(&ok);
    if (!ok) {
      continue;
    }

    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FragmentTokenId>(vid)) {
      token_ids.emplace_back(id);
    }
  }

  if (!token_ids.empty()) {
    emit FragmentTokensClicked(std::move(token_ids));
  }
}

}  // namespace mx::gui
