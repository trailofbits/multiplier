// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Util.h"

#include <cassert>
#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Index.h>
#include <multiplier/Iterator.h>
#include <multiplier/Token.h>
#include <multiplier/Use.h>

#include "CodeTheme.h"

#include <iostream>

namespace mx::gui {

// Classify a token kind into a `TokenClass`. Token classes are good baseline
// indicators for syntax coloring.
TokenClass ClassifyToken(const Token &tok) {
  switch (tok.kind()) {
    case TokenKind::COMMENT:
      return TokenClass::kComment;
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
      return TokenClass::kLiteral;
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
      return TokenClass::kPunctuation;
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
      return TokenClass::kBuiltinTypeName;

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
      return TokenClass::kKeyword;
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
      return TokenClass::kPreProcessorKeyword;
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
      return TokenClass::kObjectiveCKeyword;
    case TokenKind::BEGIN_OF_MACRO_EXPANSION_MARKER:
      return TokenClass::kMacroName;
    case TokenKind::IDENTIFIER:
      return TokenClass::kIdentifier;
    default:
      return TokenClass::kUnknown;
  }
}

// Categorize a token.
TokenCategory CategorizeToken(const Token &token, TokenClass tok_class,
                              DeclCategory decl_category) {
  TokenCategory kind = TokenCategory::kUnknown;

  auto is_whitespace = token.kind() == TokenKind::WHITESPACE;
  for (auto ch : token.data()) {
    switch (ch) {
      case ' ':
      case '\t':
      case '\r':
      case '\n':
        continue;
      default:
        is_whitespace = false;
        break;
    }
  }

  if (is_whitespace) {
    return TokenCategory::kWhitespace;

  } else if (decl_category == DeclCategory::UNKNOWN) {
    return static_cast<TokenCategory>(tok_class);

  } else {
    return static_cast<TokenCategory>(
        static_cast<int>(TokenCategory::kComment) +
        static_cast<int>(decl_category));
  }
}

// Categorize a token.
TokenCategory CategorizeToken(const Token &token, DeclCategory category) {
  return CategorizeToken(token, ClassifyToken(token), category);
}

namespace {

static std::optional<Decl> VisitStmt(const Stmt &stmt, const Token &token) {
  if (auto dre = DeclRefExpr::from(stmt)) {
    if (auto named_decl = NamedDecl::from(dre->declaration())) {
      if (named_decl->name() == token.data() &&
          dre->expression_token().id() == token.id()) {
        return named_decl;
      }
    }
  } else if (auto me = MemberExpr::from(stmt)) {
    auto member_decl = me->member_declaration();
    if (member_decl.name() == token.data() &&
        me->member_token().id() == token.id()) {
      return member_decl;
    } else {
      return VisitStmt(me->base(), token);
    }
  } else if (auto ce = CXXConstructExpr::from(stmt)) {
    auto constructor_decl = ce->constructor();
    if (constructor_decl.name() == token.data() &&
        ce->token().id() == token.id()) {
      return constructor_decl;
    }
  } else if (auto gt = GotoStmt::from(stmt)) {
    if (gt->label_token().id() == token.id()) {
      return gt->label();
    }
  } else if (auto di = DesignatedInitExpr::from(stmt)) {
    // TODO(pag): need support in pasta.

  } else if (auto ls = LabelStmt::from(stmt)) {
    if (ls->identifier_token().id() == token.id()) {
      return ls->declaration();
    }

  // Backup.
  } else if (auto call = CallExpr::from(stmt)) {
    if (call->expression_token().id() == token.id()) {
      if (auto called_decl = call->callee_declaration()) {
        return called_decl;
      }
    }
  }

  return std::nullopt;
}

static std::optional<Decl> VisitType(const Type &type, const Token &token) {
  if (auto typedef_type = TypedefType::from(type)) {
    auto typedef_decl = typedef_type->declaration();
    if (typedef_decl.name() == token.data()) {
      return typedef_decl;
    }

  } else if (auto tag_type = TagType::from(type)) {
    auto tag_decl = tag_type->declaration();
    if (tag_decl.name() == token.data()) {
      return tag_decl;
    }

  } else if (auto deduced_type = DeducedType::from(type)) {
    return VisitType(deduced_type.value(), token);

  } else if (auto unqual_type = type.unqualified_type();
             unqual_type.id() != type.id()) {
    return VisitType(unqual_type, token);
  }

  return std::nullopt;
}

}  // namespace

// Try to determine the declarations associated with this token.
std::optional<Decl> DeclForToken(const Token &token) {
  switch (token.kind()) {
    default:
    case TokenKind::BEGIN_OF_FILE_MARKER:
    case TokenKind::END_OF_FILE_MARKER:
    case TokenKind::BEGIN_OF_MACRO_EXPANSION_MARKER:
    case TokenKind::END_OF_MACRO_EXPANSION_MARKER:
      return std::nullopt;

    case TokenKind::L_SQUARE:
    case TokenKind::R_SQUARE:
    case TokenKind::L_PARENTHESIS:
    case TokenKind::R_PARENTHESIS:
    case TokenKind::L_BRACE_TOKEN:
    case TokenKind::R_BRACE_TOKEN:
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
    case TokenKind::EQUAL:
    case TokenKind::EQUAL_EQUAL:
    case TokenKind::COMMA:
    case TokenKind::PERIOD_STAR:
    case TokenKind::ARROW_STAR:
    case TokenKind::LESS_LESS_LESS:
    case TokenKind::GREATER_GREATER_GREATER:
    case TokenKind::CARETCARET:
    case TokenKind::KEYWORD_DELETE:
    case TokenKind::KEYWORD_NEW:
    case TokenKind::KEYWORD_OPERATOR:
    case TokenKind::IDENTIFIER:
      break;
  }

  for (auto context = TokenContext::of(token); context;
       context = context->parent()) {

    if (auto stmt = context->as_statement()) {
      if (auto decl = VisitStmt(stmt.value(), token)) {
        return CanonicalDecl(decl.value());
      }
    } else if (auto type = context->as_type()) {
      if (auto decl = VisitType(type.value(), token)) {
        return CanonicalDecl(decl.value());
      }
    } else if (auto decl = context->as_declaration()) {
      if (auto named_decl = NamedDecl::from(decl);
          named_decl && named_decl->name() == token.data()) {
        return CanonicalDecl(decl.value());
      }

    } else if (auto attr = context->as_attribute()) {
      if (attr->token().id() == token.id()) {
        return std::nullopt;  // No way to find a decl.
      }

    } else if (auto designator = context->as_designator()) {
      if (designator->field_token().id() == token.id()) {
        if (auto field = designator->field()) {
          return field.value();  // No redeclarations?
        }
      }
    }
  }

#if 1
  if (ClassifyToken(token) == TokenClass::kIdentifier) {
    if (std::optional<Fragment> frag = Fragment::containing(token)) {
      std::cerr << "Missing decl for '" << token.data() << "': " << token.id() << ":\n";
      std::cerr << "\tFragment ID: " << frag->id() << '\n';
      if (auto file = File::containing(token)) {
        std::cerr << "\tFile ID: " << file->id() << '\n';
      }
      std::cerr << "\tContext:";
      for (auto context = TokenContext::of(token); context;
           context = context->parent()) {

        if (auto stmt = context->as_statement()) {
          std::cerr << " -> " << EnumeratorName(stmt->kind()) << "(" << stmt->id() << ")";

        } else if (auto type = context->as_type()) {
          std::cerr << " -> " << EnumeratorName(type->kind()) << "(" << type->id() << ")";

        } else if (auto decl = context->as_declaration()) {
          std::cerr << " -> " << EnumeratorName(decl->kind()) << "(" << decl->id() << ")";
        
        } else if (auto attr = context->as_attribute()) {
          std::cerr << " -> ATTRIBUTE(" << attr->token().data() << ")";

        } else if (auto designator = context->as_designator()) {
          std::cerr << " -> DESIGNATOR(";
          if (auto field = designator->field()) {
            std::cerr << field->name();
          }
          std::cerr << ")";
        }
      }
      std::cerr << '\n';

      for (Use<TokenUseSelector> use : token.uses()) {
        if (auto decl = use.as_declaration()) {
          for (auto sel : EnumerationRange<TokenUseSelector>()) {
            if (use.has_selector(sel)) {
              std::cerr << '\t' << EnumeratorName(decl->kind()) << "::" << EnumeratorName(sel) << '\n';
            }
          }
        } else if (auto stmt = use.as_statement()) {
          for (auto sel : EnumerationRange<TokenUseSelector>()) {
            if (use.has_selector(sel)) {
              std::cerr << '\t' << EnumeratorName(stmt->kind()) << "::" << EnumeratorName(sel) << '\n';
            }
          }
        }
      }
    }
  }
#endif

  return std::nullopt;
}

// Returns a pair of `(fragment_id, offset)` or `(kInvalidEntityId, 0)` for a
// given raw entity id.
EntityBaseOffsetPair GetFragmentOffset(RawEntityId id) {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<DeclarationId>(vid)) {
    auto eid = std::get<DeclarationId>(vid);
    return {EntityId(FragmentId(eid.fragment_id)), eid.offset};

  } else if (std::holds_alternative<StatementId>(vid)) {
    auto eid = std::get<StatementId>(vid);
    return {EntityId(FragmentId(eid.fragment_id)), eid.offset};

  } else if (std::holds_alternative<TypeId>(vid)) {
    auto eid = std::get<TypeId>(vid);
    return {EntityId(FragmentId(eid.fragment_id)), eid.offset};

  } else if (std::holds_alternative<FragmentTokenId>(vid)) {
    auto eid = std::get<FragmentTokenId>(vid);
    return {EntityId(FragmentId(eid.fragment_id)), eid.offset};

  } else if (std::holds_alternative<TokenSubstitutionId>(vid)) {
    auto eid = std::get<TokenSubstitutionId>(vid);
    return {EntityId(FragmentId(eid.fragment_id)), eid.offset};

  } else {
    return {kInvalidEntityId, 0u};
  }
}

// Returns a pair of `(file_id, offset)` or `(kInvalidEntityId, 0)` for a
// given raw entity id.
EntityBaseOffsetPair GetFileOffset(RawEntityId id) {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<FileTokenId>(vid)) {
    auto eid = std::get<FileTokenId>(vid);
    return {eid.file_id, eid.offset};

  } else {
    return {kInvalidEntityId, 0u};
  }
}

// Return the "canonical" version of a declaration. This tries to get us the
// definition when possible.
Decl CanonicalDecl(const Decl &decl) {
  for (const Decl &redecl : decl.redeclarations()) {
    return redecl;
  }
  return decl;
}

// Return the "canonical" ID of a declaration. This tries to get us the
// definition when possible.
RawEntityId CanonicalId(const Decl &decl) {
  return CanonicalDecl(decl).id();
}

// Return some kind of name for a declaration.
QString DeclName(const Decl &decl) {
  if (auto nd = NamedDecl::from(decl)) {
    if (auto name_data = nd->name(); !name_data.empty()) {
      return QString::fromUtf8(name_data.data(),
                               static_cast<int>(name_data.size()));
    }
  }
  return QString("%1(%2)").arg(EnumeratorName(decl.category())).arg(decl.id());
}

// Return the file location of an entity.
RawEntityId EntityFileLocation(const Index &index, RawEntityId eid) {
  auto entity = index.entity(eid);
  if (std::holds_alternative<Decl>(entity)) {
    return DeclFileLocation(std::get<Decl>(entity));

  // Statement, walk to the first fragent token, or the beginning of the
  // fragment.
  } if (std::holds_alternative<Stmt>(entity)) {
    Stmt stmt = std::get<Stmt>(entity);
    for (Token token : stmt.tokens()) {
      if (auto nearest_file_loc = token.nearest_file_token()) {
        return nearest_file_loc->id();
      }
    }

    return Fragment::containing(stmt).file_tokens().begin()->id();

  // Type; walk to the containing fragment.
  } else if (std::holds_alternative<Type>(entity)) {
    Type type = std::get<Type>(entity);
    return Fragment::containing(type).file_tokens().begin()->id();

  // Token substitution; walk up to the file location.
  } else if (std::holds_alternative<TokenSubstitution>(entity)) {
    auto sub = std::get<TokenSubstitution>(entity);
    for (;;) {
      for (auto tok_sub : sub.before()) {
        if (std::holds_alternative<Token>(tok_sub)) {
          Token tok = std::get<Token>(tok_sub);
          if (auto nearest_file_loc = tok.nearest_file_token()) {
            return nearest_file_loc->id();
          }

        } else if (std::holds_alternative<TokenSubstitution>(tok_sub)) {
          sub = std::get<TokenSubstitution>(tok_sub);
          goto next_sub;
        }
      }
      return kInvalidEntityId;
    next_sub:
      continue;
    }
  } else if (std::holds_alternative<Token>(entity)) {
    if (auto file_tok = std::get<Token>(entity).nearest_file_token()) {
      return file_tok->id();
    }
  }
  return kInvalidEntityId;
}

// Return the optional nearest fragment token associated with this declaration.
std::optional<Token> DeclFragmentToken(const Decl &decl) {

  // Structs and enums and such can often be defined inside of a typedef so we
  // want to go to the beginning of them.
  if (TypeDecl::from(decl)) {
    goto skip_name_match;
  }

  if (auto nd = NamedDecl::from(decl)) {
    if (auto tok = nd->token()) {
      if (tok.data() == nd->name()) {
        return tok;
      }
    }
  }

skip_name_match:
  for (Token decl_tok : decl.tokens()) {
    return decl_tok;
  }

  for (Token parsed_tok : Fragment::containing(decl).parsed_tokens()) {
    return parsed_tok;
  }

  return std::nullopt;
}

// Return the optional nearest file token associated with this declaration.
std::optional<Token> DeclFileToken(const Decl &decl) {
  if (auto frag_tok = DeclFragmentToken(decl)) {
    return frag_tok->nearest_file_token();
  } else {
    return std::nullopt;
  }
}

// Return the entity ID of the nearest file token associated with this
// declaration.
RawEntityId DeclFileLocation(const Decl &decl) {
  if (auto tok = DeclFileToken(decl)) {
    return tok->id();
  } else {
    return kInvalidEntityId;
  }
}

// Try to get the nearest declaration for `id`. Ideally, `id` is a declaration
// ID. Otherwise, it will find the nearest enclosing declaration, and return
// that.
std::optional<Decl> NearestDeclFor(const Index &index, RawEntityId id) {
  auto entity = index.entity(id);
  if (std::holds_alternative<Decl>(entity)) {
    return std::get<Decl>(entity);
  } else if (std::holds_alternative<Stmt>(entity)) {
    for (Decl decl : Decl::containing(std::get<Stmt>(entity))) {
      return decl;
    }
  } else if (std::holds_alternative<Token>(entity)) {
    for (Decl decl : Decl::containing(std::get<Token>(entity))) {
      return decl;
    }
  }
  return std::nullopt;
}

namespace {

static const QString kBreadCrumb("%1%2%3");
static const QString kReps[] = {"", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};
static const QString kTooManyReps("⁺");
static const QString kNextSep(" → ");

struct BreadCrumbs {

  QString sep;
  QString breadcrumbs;

  int repetitions{0};
  const bool run_length_encode;

  BreadCrumbs(bool run_length_encode_)
      : run_length_encode(run_length_encode_) {}

  QString Release(void) {
    repetitions = 0;
    return std::move(breadcrumbs);
  }

  template <typename T>
  void AddEnum(T enumerator) {
    std::string_view ret = EnumeratorName(enumerator);
    if (ret.ends_with("_EXPR") || ret.ends_with("_STMT") ||
        ret.ends_with("_DECL") || ret.ends_with("_TYPE")) {
      AddStringView(ret.substr(0u, ret.size() - 5u));
    } else if (ret.ends_with("_OPERATOR")) {
      AddStringView(ret.substr(0u, ret.size() - 9u));
    } else if (ret.ends_with("_DIRECTIVE")) {
      AddStringView(ret.substr(0u, ret.size() - 10u));
    } else {
      AddStringView(ret);
    }
  }

  void AddStringView(std::string_view ret) {
    AddString(QString::fromUtf8(ret.data(), static_cast<int>(ret.size())));
  }

  void AddString(QString name) {
    if (run_length_encode && breadcrumbs.endsWith(name)) {
      ++repetitions;

    } else if (repetitions < 9) {
      breadcrumbs.append(kBreadCrumb.arg(kReps[repetitions]).arg(sep).arg(name));
      repetitions = 0;

    } else {
      breadcrumbs.append(kBreadCrumb.arg(kTooManyReps).arg(sep).arg(name));
      repetitions = 0;
    }

    sep = kNextSep;
  }
};

}  // namespace

// Create a breadcrumbs string of the token contexts.
QString TokenBreadCrumbs(const Token &ent, bool run_length_encode) {
  auto i = -1;

  BreadCrumbs crumbs(run_length_encode);

  for (auto context = TokenContext::of(ent);
       context; context = context->parent()) {
    ++i;

    if (auto cdecl = context->as_declaration()) {
      crumbs.AddEnum(cdecl->kind());

    } else if (auto ctype = context->as_type()) {
      crumbs.AddEnum(ctype->kind());

    } else if (auto cstmt = context->as_statement()) {
      switch (cstmt->kind()) {
        case StmtKind::DECL_REF_EXPR:
        case StmtKind::COMPOUND_STMT:
        case StmtKind::PAREN_EXPR:
          break;
        case StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR: {
          auto &expr = reinterpret_cast<const UnaryExprOrTypeTraitExpr &>(
              cstmt.value());
          crumbs.AddEnum(expr.expression_or_trait_kind());
          continue;
        }

        case StmtKind::IMPLICIT_CAST_EXPR: {
          auto &cast = reinterpret_cast<const ImplicitCastExpr &>(cstmt.value());
          auto ck = cast.cast_kind();
          if (ck != CastKind::L_VALUE_TO_R_VALUE && ck != CastKind::BIT_CAST &&
              ck != CastKind::FUNCTION_TO_POINTER_DECAY &&
              ck != CastKind::ARRAY_TO_POINTER_DECAY) {
            crumbs.AddEnum(ck);
          }
          break;
        }

        case StmtKind::UNARY_OPERATOR: {
          auto &op = reinterpret_cast<const UnaryOperator &>(cstmt.value());
          crumbs.AddEnum(op.opcode());
          continue;
        }

        case StmtKind::BINARY_OPERATOR: {
          auto &op = reinterpret_cast<const BinaryOperator &>(cstmt.value());
          crumbs.AddEnum(op.opcode());
          continue;
        }

        case StmtKind::MEMBER_EXPR:
          // If we're asking for the use of a field, then every use will start
          // with `MEMBER_EXPR`.
          if (!i) {
            continue;
          }
          [[clang::fallthrough]];

        default:
          crumbs.AddEnum(cstmt->kind());
          break;
      }
    }
  }
  return crumbs.Release();
}

}  // namespace mx::gui
