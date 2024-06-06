// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Token.h"

#include <cassert>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/DeclCategory.h>
#include <multiplier/AST/DeclKind.h>
#include <multiplier/AST/FriendDecl.h>
#include <multiplier/AST/ImplicitParamDecl.h>
#include <multiplier/AST/ObjCMethodDecl.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/AST/TagTypeKind.h>
#include <multiplier/AST/TemplateDecl.h>
#include <multiplier/AST/VarDecl.h>

#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Frontend/TokenCategory.h>
#include <multiplier/Frontend/TokenKind.h>

#include "File.h"
#include "Fragment.h"
#include "Reference.h"
#include "Type.h"
#include "Util.h"

namespace mx {
namespace {

// A zero-sized string view that nontheless has a valid `.data()` pointer.
static const std::string_view kEmptyStringView("");

// A dummy token reader allowing us to categorize a given entity into a token
// category.
class CategorizableEntityTokenReader final : public TokenReader {
 public:
  const VariantEntity &entity;

  virtual ~CategorizableEntityTokenReader(void) noexcept = default;

  inline CategorizableEntityTokenReader(const VariantEntity &entity_)
      : entity(entity_) {}

  // Return the number of tokens accessible to this reader.
  EntityOffset NumTokens(void) const override {
    return 0;
  }

  TokenKind NthTokenKind(EntityOffset) const override {
    return TokenKind::UNKNOWN;
  }

  [[noreturn]]
  std::string_view NthTokenData(EntityOffset) const override {
    __builtin_unreachable();
  }

  [[noreturn]]
  EntityId NthDerivedTokenId(EntityOffset) const override {
    __builtin_unreachable();
  }

  [[noreturn]]
  EntityId NthParsedTokenId(EntityOffset) const override {
    __builtin_unreachable();
  }

  [[noreturn]]
  EntityId NthContainingMacroId(EntityOffset) const override {
    __builtin_unreachable();
  }

  EntityId NthRelatedEntityId(EntityOffset) const override {
    return EntityId(entity);
  }

  VariantEntity NthRelatedEntity(EntityOffset) const override {
    return entity;
  }

  [[noreturn]]
  EntityId NthTokenId(EntityOffset) const override {
    __builtin_unreachable();
  }

  [[noreturn]]
  EntityId NthFileTokenId(EntityOffset) const override {
    __builtin_unreachable();
  }

  [[noreturn]]
  bool Equals(const TokenReader *) const override {
    __builtin_unreachable();
  }
};

static const std::shared_ptr<InvalidTokenReader> kInvalidTokenReader =
    std::make_shared<InvalidTokenReader>();

// Classify a token kind into a baseline token category. These are good baseline
// indicators for syntax coloring.
static TokenCategory ClassifyToken(TokenKind kind) {
  switch (kind) {
    case TokenKind::COMMENT: return TokenCategory::COMMENT;
    case TokenKind::HEADER_NAME: return TokenCategory::FILE_NAME;
    case TokenKind::NUMERIC_CONSTANT:
    case TokenKind::CHARACTER_CONSTANT:
    case TokenKind::WIDE_CHARACTER_CONSTANT:
    case TokenKind::UTF8_CHARACTER_CONSTANT:
    case TokenKind::UTF16_CHARACTER_CONSTANT:
    case TokenKind::UTF32_CHARACTER_CONSTANT:
    case TokenKind::STRING_LITERAL:
    case TokenKind::WIDE_STRING_LITERAL:
    case TokenKind::UTF8_STRING_LITERAL:
    case TokenKind::UTF16_STRING_LITERAL:
    case TokenKind::UTF32_STRING_LITERAL:
      return TokenCategory::LITERAL;
    case TokenKind::L_SQUARE:
    case TokenKind::R_SQUARE:
    case TokenKind::L_PARENTHESIS:
    case TokenKind::R_PARENTHESIS:
    case TokenKind::L_BRACE:
    case TokenKind::R_BRACE:
    case TokenKind::L_ANGLE:
    case TokenKind::R_ANGLE:
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
    case TokenKind::HASH_AT:
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
    case TokenKind::KEYWORD___BUILTIN_PTRAUTH_TYPE_DISCRIMINATOR:
    case TokenKind::KEYWORD___BUILTIN_XNU_TYPE_SIGNATURE:
    case TokenKind::KEYWORD___BUILTIN_XNU_TYPE_SUMMARY:
    case TokenKind::KEYWORD___BUILTIN_TMO_TYPE_METADATA:
    case TokenKind::KEYWORD___BUILTIN_XNU_TYPES_COMPATIBLE:
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

static TokenCategory ClassifyMacro(TokenKind kind, MacroId id,
                                   TokenCategory baseline_category) {
  switch (kind) {
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

    case TokenKind::ELLIPSIS:
      goto try_param;
    default:
      break;
  }
  switch (baseline_category) {
    case TokenCategory::IDENTIFIER:
    case TokenCategory::KEYWORD:
    case TokenCategory::OBJECTIVE_C_KEYWORD:
    case TokenCategory::BUILTIN_TYPE_NAME:
    case TokenCategory::THIS:
    try_param:
      switch (id.kind) {
        case MacroKind::STRINGIFY:
          return TokenCategory::LITERAL;
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
  return baseline_category;
}

static TokenCategory ClassifyDecl(const TokenReader *reader, EntityOffset index,
                                  DeclId id, TokenCategory baseline_category) {
  switch (id.kind) {
    // For this set, we don't need to ask for a related entity.
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

    case DeclKind::ENUM:
      return TokenCategory::ENUM;
    case DeclKind::ENUM_CONSTANT:
      return TokenCategory::ENUMERATOR;

    case DeclKind::USING_ENUM:
      return TokenCategory::ENUM;

    case DeclKind::TYPE_ALIAS:
    case DeclKind::TYPEDEF:
    case DeclKind::USING:
    case DeclKind::UNRESOLVED_USING_TYPENAME:
    case DeclKind::UNRESOLVED_USING_IF_EXISTS:
    case DeclKind::UNRESOLVED_USING_VALUE:  // Might not be a type.
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

    // For the next set, we can make a good reasonable guess at the category,
    // but we'll try to be more precise by fetching the actual decl.

    case DeclKind::CONCEPT:
      return TokenCategory::CONCEPT;

    // E.g. `__make_integer_seq`.
    case DeclKind::BUILTIN_TEMPLATE:
      return TokenCategory::BUILTIN_TYPE_NAME;
    
    case DeclKind::CLASS_TEMPLATE:
      return TokenCategory::CLASS;

    case DeclKind::VAR_TEMPLATE:
      return TokenCategory::GLOBAL_VARIABLE;

    // Could be a method.
    case DeclKind::FUNCTION_TEMPLATE:
      baseline_category = TokenCategory::FUNCTION;
      break;

    case DeclKind::TYPE_ALIAS_TEMPLATE:
      baseline_category = TokenCategory::TYPE_ALIAS;
      break;

    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
    case DeclKind::VAR_TEMPLATE_SPECIALIZATION:
      return TokenCategory::GLOBAL_VARIABLE;

    case DeclKind::RECORD:
      baseline_category = TokenCategory::STRUCT;
      break;

    case DeclKind::ACCESS_SPEC:
    case DeclKind::LINKAGE_SPEC:
    case DeclKind::FRIEND:
    case DeclKind::FRIEND_TEMPLATE:
    case DeclKind::STATIC_ASSERT:
    case DeclKind::FILE_SCOPE_ASM:
    case DeclKind::EXTERN_C_CONTEXT:
      return TokenCategory::KEYWORD;

    case DeclKind::EMPTY:
      return TokenCategory::PUNCTUATION;

    case DeclKind::CXX_METHOD:
    case DeclKind::OBJ_C_METHOD:
      baseline_category = TokenCategory::INSTANCE_METHOD;
      break;

    case DeclKind::IMPLICIT_PARAM:
      baseline_category = TokenCategory::PARAMETER_VARIABLE;
      break;

    case DeclKind::VAR:
      baseline_category = TokenCategory::LOCAL_VARIABLE;
      break;

    default:
      break;
  }

  // The related entity ID is a `DeclId`, so the related entity should be
  // a valid `Decl`.
  VariantEntity ent = reader->NthRelatedEntity(index);
  if (!std::holds_alternative<Decl>(ent)) {
    assert(false);
    return baseline_category;
  }

  return ConvertDeclCategoryToTokenCategory(std::get<Decl>(ent).category());
}

static TokenCategory ClassifyStmt(StmtId id, TokenKind kind,
                                  TokenCategory baseline_category) {
  switch (id.kind) {
    case StmtKind::STRING_LITERAL:
    case StmtKind::INTEGER_LITERAL:
    case StmtKind::CHARACTER_LITERAL:
    case StmtKind::FLOATING_LITERAL:
    case StmtKind::FIXED_POINT_LITERAL:
      return TokenCategory::LITERAL;

    // E.g. `__c11_atomic_load(...)`.
    case StmtKind::ATOMIC_EXPR:
      if (kind == TokenKind::IDENTIFIER) {
        return TokenCategory::KEYWORD;
      }
      break;

    // E.g. `__func__`.
    case StmtKind::PREDEFINED_EXPR:
      if (kind == TokenKind::KEYWORD___FUNC__) {
        return TokenCategory::LITERAL;
      } else {
        return TokenCategory::KEYWORD;
      }

    default:
      break;
  }
  return baseline_category;
}

static TokenCategory ClassifyType(TypeId id, TokenKind,
                                  TokenCategory baseline_category) {
  switch (baseline_category) {
    case TokenCategory::IDENTIFIER:
    case TokenCategory::UNKNOWN:
      break;
    default:
      return baseline_category;
  }

  switch (id.kind) {
    case TypeKind::ENUM:
      return TokenCategory::ENUM;

    case TypeKind::RECORD:
      return TokenCategory::STRUCT;  // Could also be a union.

    case TypeKind::TEMPLATE_SPECIALIZATION:
      return TokenCategory::CLASS;

    case TypeKind::TEMPLATE_TYPE_PARM:
      return TokenCategory::TEMPLATE_PARAMETER_TYPE;

    case TypeKind::TYPEDEF:
    case TypeKind::USING:
      return TokenCategory::TYPE_ALIAS;

    case TypeKind::BUILTIN:
      return TokenCategory::BUILTIN_TYPE_NAME;

    // Try to force unrecognized identifiers inside of function prototypes
    // to be interpreted as function parameter names.
    //
    // XREF: https://github.com/trailofbits/multiplier/issues/344
    case TypeKind::FUNCTION_PROTO:
      return TokenCategory::PARAMETER_VARIABLE;

    default:
      break;
  }
  return baseline_category;
}

static TokenCategory ClassifyFile(TokenKind kind,
                                  TokenCategory baseline_category) {
  switch (kind) {
    case TokenKind::PP_IMPORT:
    case TokenKind::PP_INCLUDE:
    case TokenKind::PP_INCLUDE_NEXT:
    case TokenKind::PP___INCLUDE_MACROS:
    case TokenKind::HASH:
    case TokenKind::HASH_HASH:
    case TokenKind::HASH_AT:
    case TokenKind::COMMA:
    case TokenKind::L_PARENTHESIS:
    case TokenKind::R_PARENTHESIS:
      return baseline_category;
    default:
      return TokenCategory::FILE_NAME;
  }
}

}  // namespace

TokenReader::~TokenReader(void) noexcept {}

// Return the kind of the Nth token.
TokenCategory TokenReader::NthTokenCategory(EntityOffset token_index) const {
  VariantId vid = NthRelatedEntityId(token_index).Unpack();
  TokenKind kind = NthTokenKind(token_index);
  TokenCategory baseline_category = ClassifyToken(kind);

  if (std::holds_alternative<MacroId>(vid)) {
    return ClassifyMacro(kind, std::get<MacroId>(vid), baseline_category);
  }

  if (std::holds_alternative<DeclId>(vid)) {
    return ClassifyDecl(this, token_index, std::get<DeclId>(vid),
                        baseline_category);
  }

  if (std::holds_alternative<StmtId>(vid)) {
    return ClassifyStmt(std::get<StmtId>(vid), kind, baseline_category);
  }

  if (std::holds_alternative<TypeId>(vid)) {
    return ClassifyType(std::get<TypeId>(vid), kind, baseline_category);
  }

  if (std::holds_alternative<FileId>(vid)) {
    return ClassifyFile(kind, baseline_category);
  }

  // Issue #343: Make identifiers inside of attributes look like keywords.
  if (std::holds_alternative<AttrId>(vid) &&
      baseline_category == TokenCategory::IDENTIFIER) {
    return TokenCategory::KEYWORD;
  }

  return baseline_category;
}

const FragmentImpl *TokenReader::OwningFragment(void) const noexcept {
  return nullptr;
}

const FileImpl *TokenReader::OwningFile(void) const noexcept {
  return nullptr;
}

const TypeImpl *TokenReader::OwningType(void) const noexcept {
  return nullptr;
}

const FragmentImpl *
TokenReader::NthOwningFragment(EntityOffset) const noexcept {
  return OwningFragment();
}

const FileImpl *TokenReader::NthOwningFile(EntityOffset) const noexcept {
  return OwningFile();
}

const TypeImpl *TokenReader::NthOwningType(EntityOffset) const noexcept {
  return OwningType();
}

Token TokenReader::TokenFor(const Ptr &self, RawEntityId eid) noexcept {
  if (auto frag = self->OwningFragment()) {
    return frag->ep->TokenFor(frag->ep, self, eid);

  } else if (auto file = self->OwningFile()) {
    return file->ep->TokenFor(file->ep, self, eid);

  } else {
    return Token();
  }
}

TokenContextReaderPtr TokenReader::TokenContextReaderFor(
    const Ptr &self, EntityOffset offset, EntityId eid) const noexcept {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    if (auto frag = self->NthOwningFragment(offset)) {

      if (offset >= frag->num_parsed_tokens) {
        return nullptr;
      }

      return frag->TokenContextReader(self);
    }
  } else if (std::holds_alternative<TypeTokenId>(vid)) {
    if (auto type = self->NthOwningType(offset)) {

      if (offset >= type->num_type_tokens) {
        return nullptr;
      }

      return type->TokenContextReader(self);
    }
  }

  return nullptr;
}

EntityProviderPtr TokenReader::EntityProviderFor(const Token &token) {
  if (auto frag = token.impl->NthOwningFragment(token.offset)) {
    return frag->ep;
  } else if (auto file = token.impl->NthOwningFile(token.offset)) {
    return file->ep;
  } else if (auto any_frag = token.impl->OwningFragment()) {
    return any_frag->ep;
  } else if (auto any_file = token.impl->OwningFile()) {
    return any_file->ep;
  } else {
    return {};
  }
}

TokenReaderPtr TokenReader::ReaderForToken(
    const TokenReaderPtr &self, const EntityProviderPtr &ep, EntityId eid) {

  VariantId vid = eid.Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    FileTokenId tid = std::get<FileTokenId>(vid);

    FileImplPtr file;
    if (auto self_file = self->OwningFile();
        self_file && self_file->file_id == tid.file_id) {
      file = FileImplPtr(self, self_file);
    } else {
      FileId fid(tid.file_id);
      file = ep->FileFor(ep, fid);
    }

    if (file && tid.offset < file->num_tokens) {
      return file->TokenReader(file);
    }

  } else if (std::holds_alternative<ParsedTokenId>(vid)) {
    ParsedTokenId tid = std::get<ParsedTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    FragmentImplPtr frag;
    if (auto self_frag = self->OwningFragment();
        self_frag && self_frag->fragment_id == tid.fragment_id) {
      frag = FragmentImplPtr(self, self_frag);
    } else {
      frag = ep->FragmentFor(ep, fid);
    }

    if (frag && tid.offset < frag->num_parsed_tokens) {
      return frag->ParsedTokenReader(frag);
    }

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    MacroTokenId tid = std::get<MacroTokenId>(vid);
    FragmentId fid(tid.fragment_id);

    FragmentImplPtr frag;
    if (auto self_frag = self->OwningFragment();
        self_frag && self_frag->fragment_id == tid.fragment_id) {
      frag = FragmentImplPtr(self, self_frag);
    } else {
      frag = ep->FragmentFor(ep, fid);
    }

    if (frag && tid.offset < frag->num_tokens) {
      return frag->MacroTokenReader(frag);
    }
  } else if (std::holds_alternative<TypeTokenId>(vid)) {
    TypeTokenId ttid = std::get<TypeTokenId>(vid);
    TypeId tid(ttid);

    TypeImplPtr type;
    if (auto self_type = self->OwningType();
        self_type && self_type->type_id == tid.type_id) {
      type = TypeImplPtr(self, self_type);
    } else {
      type = ep->TypeFor(ep, tid);
    }

    if (type && ttid.offset < type->num_type_tokens) {
      return type->TypeTokenReader(type);
    }
  }

  return kInvalidTokenReader;
}

// Returns the singleton instance of the invalid token reader.
TokenReaderPtr InvalidTokenReader::Singleton(void) {
  return kInvalidTokenReader;
}

// Returns the singleton instance of the invalid token reader.
const TokenReader *InvalidTokenReader::RawSingleton(void) {
  return kInvalidTokenReader.get();
}

InvalidTokenReader::~InvalidTokenReader(void) noexcept {}

// Return the number of tokens accessible to this reader.
EntityOffset InvalidTokenReader::NumTokens(void) const {
  return 0u;
}

// Return the kind of the Nth token.
TokenKind InvalidTokenReader::NthTokenKind(EntityOffset) const {
  return TokenKind::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view InvalidTokenReader::NthTokenData(EntityOffset) const {
  return kEmptyStringView;
}

// Return the id of the token from which the Nth token is derived.
EntityId InvalidTokenReader::NthDerivedTokenId(EntityOffset) const {
  return kInvalidEntityId;
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId InvalidTokenReader::NthParsedTokenId(EntityOffset) const {
  return kInvalidEntityId;
}

// Return the id of the macro containing the Nth token.
EntityId InvalidTokenReader::NthContainingMacroId(EntityOffset) const {
  return kInvalidEntityId;
}

// Return an entity id associated with the Nth token.
EntityId InvalidTokenReader::NthRelatedEntityId(EntityOffset) const {
  return kInvalidEntityId;
}

// Return the entity associated with the Nth token.
VariantEntity InvalidTokenReader::NthRelatedEntity(EntityOffset) const {
  return NotAnEntity{};
}

// Return the id of the Nth token.
EntityId InvalidTokenReader::NthTokenId(EntityOffset) const {
  return kInvalidEntityId;
}

EntityId InvalidTokenReader::NthFileTokenId(EntityOffset) const {
  return kInvalidEntityId;
}

// Returns `true` if `this` is logically equivalent to `that`.
bool InvalidTokenReader::Equals(const TokenReader *) const {
  return false;
}

ProxyTokenReader::~ProxyTokenReader(void) noexcept {}

// Return the number of tokens accessible to this reader.
EntityOffset ProxyTokenReader::NumTokens(void) const {
  return next->NumTokens();
}

// Return the kind of the Nth token.
TokenKind ProxyTokenReader::NthTokenKind(EntityOffset to) const {
  return next->NthTokenKind(to);
}

// Return the data of the Nth token.
std::string_view ProxyTokenReader::NthTokenData(EntityOffset to) const {
  return next->NthTokenData(to);
}

// Return the id of the token from which the Nth token is derived.
EntityId ProxyTokenReader::NthDerivedTokenId(EntityOffset to) const {
  return next->NthDerivedTokenId(to);
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId ProxyTokenReader::NthParsedTokenId(EntityOffset to) const {
  return next->NthParsedTokenId(to);
}

// Return the id of the macro containing the Nth token.
EntityId ProxyTokenReader::NthContainingMacroId(EntityOffset to) const {
  return next->NthContainingMacroId(to);
}

// Return an entity id associated with the Nth token.
EntityId ProxyTokenReader::NthRelatedEntityId(EntityOffset to) const {
  return next->NthRelatedEntityId(to);
}

// Return the entity associated with the Nth token.
VariantEntity ProxyTokenReader::NthRelatedEntity(EntityOffset to) const {
  return next->NthRelatedEntity(to);
}

// Return the id of the Nth token.
EntityId ProxyTokenReader::NthTokenId(EntityOffset to) const {
  return next->NthTokenId(to);
}

EntityId ProxyTokenReader::NthFileTokenId(EntityOffset to) const {
  return next->NthFileTokenId(to);
}

// Returns `true` if `this` is logically equivalent to `that`.
bool ProxyTokenReader::Equals(const TokenReader *that) const {
  return this == that || next->Equals(that);
}

const FragmentImpl *
ProxyTokenReader::NthOwningFragment(EntityOffset to) const noexcept {
  return next->NthOwningFragment(to);
}

const FileImpl *
ProxyTokenReader::NthOwningFile(EntityOffset to) const noexcept {
  return next->NthOwningFile(to);
}

const TypeImpl *
ProxyTokenReader::NthOwningType(EntityOffset to) const noexcept {
  return next->NthOwningType(to);
}

const FragmentImpl *ProxyTokenReader::OwningFragment(void) const noexcept {
  return next->OwningFragment();
}

const FileImpl *ProxyTokenReader::OwningFile(void) const noexcept {
  return next->OwningFile();
}

const TypeImpl *ProxyTokenReader::OwningType(void) const noexcept {
  return next->OwningType();
}

TokenContextReaderPtr ProxyTokenReader::TokenContextReaderFor(
    const Ptr &self, EntityOffset offset, EntityId eid) const noexcept {
  return next->TokenContextReaderFor(self, offset, eid);
}

CustomTokenReader::CustomTokenReader(
    std::shared_ptr<const FragmentImpl> fragment_)
    : fragment(std::move(fragment_)) {
  data_offset.push_back(0u);
}

CustomTokenReader::~CustomTokenReader(void) noexcept {}

// Append a token into this reader.
void CustomTokenReader::Append(TokenImplPtr tr, EntityOffset to) noexcept {
  std::string_view tok_data = tr->NthTokenData(to);
  if (!tok_data.empty()) {
    data.insert(data.end(), tok_data.begin(), tok_data.end());
  }

  data_offset.push_back(static_cast<EntityOffset>(data.size()));
  derived_token_ids.push_back(tr->NthDerivedTokenId(to).Pack());
  parsed_token_ids.push_back(tr->NthParsedTokenId(to).Pack());
  containing_macro_ids.push_back(tr->NthContainingMacroId(to).Pack());
  related_entities.emplace_back(tr->NthRelatedEntity(to));
  token_ids.push_back(tr->NthTokenId(to).Pack());
  token_kinds.push_back(tr->NthTokenKind(to));
  token_categories.push_back(tr->NthTokenCategory(to));
  file_token_ids.push_back(tr->NthFileTokenId(to).Pack());
}

// Append a simple token into this reader.
void CustomTokenReader::Append(UserToken stok) noexcept {
  if (stok.data.empty()) {
    return;
  }

  data.insert(data.end(), stok.data.begin(), stok.data.end());
  data_offset.push_back(static_cast<EntityOffset>(data.size()));

  derived_token_ids.push_back(kInvalidEntityId);
  parsed_token_ids.push_back(kInvalidEntityId);
  containing_macro_ids.push_back(kInvalidEntityId);
  token_ids.push_back(kInvalidEntityId);
  token_kinds.push_back(stok.kind);
  token_categories.push_back(stok.category);
  file_token_ids.push_back(kInvalidEntityId);
  related_entities.emplace_back(std::move(stok.related_entity));
}

// Return the number of tokens accessible to this reader.
EntityOffset CustomTokenReader::NumTokens(void) const {
  return static_cast<EntityOffset>(token_ids.size());
}

// Return the kind of the Nth token.
TokenKind CustomTokenReader::NthTokenKind(EntityOffset to) const {
  if (to < token_kinds.size()) {
    return token_kinds[to];
  }
  return TokenKind::UNKNOWN;
}

// Return the category of the Nth token.
TokenCategory CustomTokenReader::NthTokenCategory(EntityOffset to) const {
  if (to < token_categories.size()) {
    return token_categories[to];
  }
  return TokenCategory::UNKNOWN;
}

// Return the data of the Nth token.
std::string_view CustomTokenReader::NthTokenData(EntityOffset to) const {
  if ((to + 1u) >= data_offset.size()) {
    return kEmptyStringView;
  }

  auto begin_offset = data_offset[to];
  auto end_offset = data_offset[to + 1u];
  if (end_offset < begin_offset ||
      begin_offset > data.size() ||
      end_offset > data.size()) {
    assert(false);
    return kEmptyStringView;
  }

  return std::string_view(data).substr(
      begin_offset, end_offset - begin_offset);
}

// Return the id of the token from which the Nth token is derived.
EntityId CustomTokenReader::NthDerivedTokenId(EntityOffset to) const {
  if (to < derived_token_ids.size()) {
    return derived_token_ids[to];
  }
  return kInvalidEntityId;
}

// Return the id of the parsed token which is derived from the Nth token.
EntityId CustomTokenReader::NthParsedTokenId(EntityOffset to) const {
  if (to < parsed_token_ids.size()) {
    return parsed_token_ids[to];
  }
  return kInvalidEntityId;
}

// Return the id of the macro containing the Nth token.
EntityId CustomTokenReader::NthContainingMacroId(EntityOffset to) const {
  if (to < containing_macro_ids.size()) {
    return containing_macro_ids[to];
  }
  return kInvalidEntityId;
}

// Return an entity id associated with the Nth token.
EntityId CustomTokenReader::NthRelatedEntityId(EntityOffset to) const {
  if (to < related_entities.size()) {
    return EntityId(related_entities[to]);
  }
  return kInvalidEntityId;
}

// Return the entity associated with the Nth token.
VariantEntity CustomTokenReader::NthRelatedEntity(EntityOffset to) const {
  if (to < related_entities.size()) {
    return related_entities[to];
  } else {
    return NotAnEntity{};
  }
}

// Return the id of the Nth token.
EntityId CustomTokenReader::NthTokenId(EntityOffset to) const {
  if (to < token_ids.size()) {
    return token_ids[to];
  }
  return kInvalidEntityId;
}

EntityId CustomTokenReader::NthFileTokenId(EntityOffset to) const {
  if (to < file_token_ids.size()) {
    return file_token_ids[to];
  }
  return kInvalidEntityId;
}

// Returns `true` if `this` is logically equivalent to `that`.
bool CustomTokenReader::Equals(const TokenReader *that_) const {
  if (this == that_) {
    return true;
  }

  auto that = dynamic_cast<const CustomTokenReader *>(that_);
  if (!that) {
    return false;
  }

  return token_ids == that->token_ids;
}

const FragmentImpl *CustomTokenReader::OwningFragment(void) const noexcept {
  return fragment.get();
}

Token::Token(void)
    : impl(kInvalidTokenReader),
      offset(0) {}

// Try to convert a variant entity into a token.
std::optional<Token> Token::from(const VariantEntity &entity) {
  if (!std::holds_alternative<Token>(entity)) {
    return std::nullopt;
  }

  return std::get<Token>(entity);
}

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
Token Token::parsed_token(void) const {
  EntityId eid = impl->NthParsedTokenId(offset);
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<ParsedTokenId>(vid)) {
    return TokenReader::TokenFor(impl, eid.Pack());

  } else if (std::holds_alternative<MacroTokenId>(vid)) {
    assert(eid == id());
    assert(false);  // Really, this is unreasonable.
    return Token();

  } else {
    return Token();
  }
}

// Return the token from which this token was derived. This can be a macro
// token or a file token.
Token Token::derived_token(void) const {
  return TokenReader::TokenFor(impl, impl->NthDerivedTokenId(offset).Pack());
}

// Return the version of this token from a file, if any. If this is a parsed
// or macro token, then this will walk the derivation chain back to a file
// token.
Token Token::file_token(void) const {
  EntityId eid = impl->NthFileTokenId(offset);
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    return TokenReader::TokenFor(impl, eid.Pack());

  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
    return Token();

  } else {
    assert(false);
    return Token();
  }
}

// Return the version of this token from a file, if any. If there isn't a
// one-to-one correspondence between this token and a file token, then it
// likely means this token exists inside of a macro expansion. If that is the
// case, then this will return the beginning token of the macro expansion.
Token Token::nearest_file_token(void) const {
  for (auto i = 0u; i <= offset; ++i) {
    EntityId eid(impl->NthFileTokenId(offset - i));
    VariantId vid = eid.Unpack();
    if (!std::holds_alternative<FileTokenId>(vid)) {
      if (std::holds_alternative<InvalidId>(vid)) {
        assert(eid.Pack() == kInvalidEntityId);
        continue;

      } else {
        assert(false);
        continue;
      }
    }

    return TokenReader::TokenFor(impl, eid.Pack());
  }

  return Token();
}

// The category of this token. This takes into account any related entities.
TokenCategory Token::category(void) const {
  return impl->NthTokenCategory(offset);
}

// Categorize an entity into a token category. This is useful for creating
// `UserToken`s.
TokenCategory Token::categorize(const VariantEntity &entity) noexcept {
  CategorizableEntityTokenReader reader(entity);
  return reader.NthTokenCategory(0);
}

// The macro that immediately contains this token, if any.
std::optional<Macro> Token::containing_macro(void) const {
  if (EntityProviderPtr ep = TokenReader::EntityProviderFor(*this)) {
    VariantId vid = impl->NthContainingMacroId(offset).Unpack();
    if (std::holds_alternative<MacroId>(vid)) {
      if (MacroImplPtr eptr = ep->MacroFor(ep, std::get<MacroId>(vid))) {
        return Macro(std::move(eptr));
      }
      assert(false);
    }
  }
  return std::nullopt;
}

// Return the ID entity associated with this token.
//
// NOTE(pag): This is only meaningful for parsed tokens and macro tokens.
EntityId Token::related_entity_id(void) const {
  return impl->NthRelatedEntityId(offset);
}

// Return the entity associated with this token.
VariantEntity Token::related_entity(void) const {
  return impl->NthRelatedEntity(offset);
}

TokenRange::TokenRange(void)
    : impl(kInvalidTokenReader),
      index(0),
      num_tokens(0) {}

TokenRange::TokenRange(const Token &tok)
    : impl(tok.impl),
      index(tok.offset),
      num_tokens(tok.impl ? (tok.offset + 1u) : 0u) {}

TokenRange TokenRange::create(std::vector<CustomToken> tokens) {

  if (tokens.size() == 1 && std::holds_alternative<Token>(tokens[0])) {
    return TokenRange(std::get<Token>(tokens[0]));
  }

  auto reader = std::make_shared<CustomTokenReader>(FragmentImpl::Ptr());
  auto num_tokens = 0u;
  for (CustomToken &ctok : tokens) {
    if (std::holds_alternative<Token>(ctok)) {
      Token tok = std::move(std::get<Token>(ctok));
      reader->Append(std::move(tok.impl), tok.offset);
      ++num_tokens;

    } else if (std::holds_alternative<UserToken>(ctok)) {
      reader->Append(std::move(std::get<UserToken>(ctok)));
      ++num_tokens;

    } else {
      assert(false);
    }
  }

  return TokenRange(std::move(reader), 0u, num_tokens);
}

TokenRange TokenRange::create(const Token &first, const Token &last) {
  // if token readers are null or they have different reader, return
  // empty token range
  if (!first.impl || !last.impl || first.impl != last.impl) {
    return TokenRange();
  }

  // If tokens are macro token, don't create a token range from it. They
  // may not be in the order.
  if (auto reader = dynamic_cast<const ReadMacroTokensFromFragment*>(first.impl.get())) {
    return TokenRange();
  }


  auto start = std::min(first.offset, last.offset);
  auto end = std::max(first.offset, last.offset);
  return TokenRange(first.impl, start, (end - start) + 1u);
}

bool TokenRange::operator==(const TokenRange &that) const noexcept {
  if (num_tokens == that.num_tokens && index == that.index) {
    if (impl && that.impl) {
      return impl->Equals(that.impl.get());
    } else {
      return !impl && !that.impl;
    }
  }
  return false;
}

// Return the token at index `index`.
Token TokenRange::operator[](size_t relative_index) const {
  size_t effective_index = (index + relative_index);
  if (effective_index >= num_tokens) {
    throw std::out_of_range(
        "Index " + std::to_string(relative_index) +
        " is out of range on mx::TokenRange");
  } else {
    return Token(impl, static_cast<EntityOffset>(effective_index));
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
      static_cast<EntityOffset>(index + start_index) != (index + start_index) ||
      static_cast<EntityOffset>(index + end_index) != (index + end_index)) {
    return TokenRange();
  } else {
    return TokenRange(impl, static_cast<EntityOffset>(index + start_index),
                      static_cast<EntityOffset>(index + end_index));
  }
}

// Returns the index of `that` in this range, or `std::nullopt`.
std::optional<unsigned> TokenRange::index_of(const Token &that) const noexcept {
  if (!impl || !impl->Equals(that.impl.get())) {
    return std::nullopt;
  }

  VariantId vid = that.id().Unpack();
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
    return kEmptyStringView;
  }

  auto data_begin = impl->NthTokenData(index);
  auto data_end = impl->NthTokenData(num_tokens - 1u);

  if (data_begin.data() > data_end.data()) {
    assert(false);
    return kEmptyStringView;
  }

  auto size = static_cast<size_t>(data_end.data() - data_begin.data()) +
              data_end.size();

  if (static_cast<EntityOffset>(size) != size) {
    assert(false);
    return kEmptyStringView;
  }

  return std::string_view(data_begin.data(), size);
}

namespace {

// Return the leftmost and rightmost use tokens of a macro.
//
// NOTE(pag): This won't handle the case of a non-tree tail expansion at the
//            root, where some of the tokens in the expansion are part of a
//            sub-expansion's replacement tokens.
static std::pair<Token, Token> CornersOfUse(const Macro &exp) {
  Token first_tok;
  Token last_tok;
  for (Token tok : exp.generate_use_tokens()) {
    if (!last_tok) {
      first_tok = tok;
    }
    last_tok = tok;
  }
  return std::make_pair<Token, Token>(std::move(first_tok),
                                      std::move(last_tok));
}

// If `tok` originates from a root macro argument or parameter, then return
// that argument/parameter.
static std::optional<Macro> OriginatingMacroArgumentOrParameter(mx::Token dt) {
  std::optional<Macro> last_macro;
  Token last_token;
  for (; dt; dt = dt.derived_token()) {
    if (auto cm = dt.containing_macro()) {
      last_macro = std::move(cm);
      last_token = dt;
    }
  }

  if (!last_macro) {
    return std::nullopt;
  }

  if (auto lmk = last_macro->kind();
      lmk == MacroKind::PARAMETER || lmk == MacroKind::ARGUMENT) {
    return last_macro;
  }

  return std::nullopt;
}

}  // namespace

// Convert this token range into a file token range.
TokenRange TokenRange::file_tokens(void) const noexcept {
  TokenRange ret;
  if (!impl || impl.get() == kInvalidTokenReader.get() || !num_tokens) {
    return ret;
  }

  std::optional<File> last_file;
  EntityOffset min_offset = std::numeric_limits<EntityOffset>::max();
  EntityOffset max_offset = 0u;

  auto widen = [&] (Token file_tok) {
    if (!file_tok) {
      return false;
    }

    std::optional<File> tok_file = File::containing(file_tok);
    if (!last_file) {
      last_file = std::move(tok_file);

    } else if (last_file.value() != tok_file.value()) {
      return false;
    }

    min_offset = std::min(min_offset, file_tok.offset);
    max_offset = std::max(max_offset, file_tok.offset);
    return true;
  };

  for (Token tok : *this) {

    // If the token is contained inside of a macro, then we need to be careful
    // because the derivation chain leading back to a file token may lead us to
    // anywhere or nowhere, but if we ascent the macro graph, then we'll likely
    // find ourselves within the macro use in the file, which is where we want
    // to be.
    if (std::optional<Macro> parent_macro = tok.containing_macro()) {

      Macro root_macro = parent_macro->root();
      std::optional<File> root_file = File::containing(root_macro);
      if (!root_file) {
        return ret;
      }

      if (!last_file) {
        last_file = std::move(root_file);

      } else if (last_file.value() != root_file.value()) {
        return ret;
      }

      // If this token is derived from a top-level token of a `MacroArgument`,
      // then treat it as a top-level token. Similarly, if we're in a
      // `MacroParameter`, then the parent must be a `DefineMacroDirective`,
      // which is a top-level thing.
      if (auto arg_macro = OriginatingMacroArgumentOrParameter(tok)) {
        if (auto arg_parent_macro = arg_macro->parent()) {
          if (arg_parent_macro.value() == root_macro) {
            root_macro = std::move(arg_macro.value());
          }
        } else {
          assert(false);
        }
      }

      auto [min_tok, max_tok] = CornersOfUse(root_macro);

      if (!widen(min_tok.file_token()) || !widen(max_tok.file_token())) {
        return ret;
      }

    // If we can't widen for the file token, then we probably have an issue.
    } else if (!widen(tok.file_token())) {
      return ret;
    }
  }

  if (!last_file) {
    return ret;
  }

  ret.impl = last_file->impl->TokenReader(last_file->impl);
  ret.index = min_offset;
  ret.num_tokens = max_offset + 1u;
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

std::shared_ptr<TokenTreeImpl> TokenTreeImplCache::Get(void) const {
  std::unique_lock<std::mutex> locker(lock);
  return impl.lock();
}

std::shared_ptr<TokenTreeImpl> TokenTreeImplCache::Put(
    std::shared_ptr<TokenTreeImpl> new_impl) const {
  std::unique_lock<std::mutex> locker(lock);
  if (auto old_impl = impl.lock()) {
    return old_impl;
  } else {
    impl = new_impl;
    return new_impl;
  }
}

}  // namespace mx
