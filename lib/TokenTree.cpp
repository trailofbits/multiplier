// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TokenTree.h"

#include <algorithm>
#include <functional>
#include <iterator>
#include <type_traits>
#include <unordered_set>
#include <vector>

#include <multiplier/Frontend/IncludeLikeMacroDirective.h>
#include <multiplier/Frontend/MacroParameterSubstitution.h>
#include <multiplier/Frontend/MacroParameter.h>

#include "File.h"
#include "Fragment.h"

// #define D(...) __VA_ARGS__
#ifndef D
# define D(...)
#else
# include <iostream>
#endif

#define INDENT std::string(static_cast<size_t>(depth), ' ')
#define BOUNDS(b) "[reader=" << reinterpret_cast<const void *>(b.reader) << ", " << b.begin_index << ", " << b.end_index << ']' 
#define TOKEN_INDEX(ti) "[reader=" << reinterpret_cast<const void *>(ti.first) << ", index=" << ti.second << ", data=" << (ti.first->NthTokenData(ti.second)) << ']' 


namespace mx {
namespace {

static const std::hash<std::string> kHasher;

class SaveRestoreLastSequence final {
  TokenTreeImpl::SequenceNode *&last_sequence;
  TokenTreeImpl::SequenceNode * const old_val;

 public:

  inline SaveRestoreLastSequence(
      TokenTreeImpl::SequenceNode *&last_sequence_,
      TokenTreeImpl::SequenceNode *new_val_)
      : last_sequence(last_sequence_),
        old_val(last_sequence) {
    if (new_val_) {
      last_sequence = new_val_;
    }
  }

  inline ~SaveRestoreLastSequence(void) {
    last_sequence = old_val;
  }
};

#define FILL_MACRO_CHILREN(generator, children_name, file_tokens_name) \
  std::vector<MacroOrToken> children_name; \
  std::vector<Token> file_tokens_name; \
  for (MacroOrToken mt : generator) { \
    if (std::holds_alternative<Token>(mt)) { \
      file_tokens_name.emplace_back(std::get<Token>(mt).file_token()); \
    } else { \
      file_tokens_name.emplace_back(LeftCornerOfUse(std::get<Macro>(mt)).file_token()); \
    } \
    children_name.emplace_back(std::move(mt)); \
  }

// Return the leftmost use tokens of a macro.
static Token LeftCornerOfExpansion(const Macro &exp) {
  for (Token tok : exp.generate_expansion_tokens()) {
    return tok;
  }
  return Token();
}

// Return the leftmost use tokens of a macro.
static Token LeftCornerOfUse(const Macro &exp) {
  for (Token tok : exp.generate_use_tokens()) {
    return tok;
  }
  return Token();
}

// Return the rightmost use tokens of a macro.
static Token RightCornerOfUse(const Macro &exp) {
  Token ret;
  for (Token tok : exp.generate_use_tokens()) {
    ret = std::move(tok);
  }
  return ret;
}

// If the `i`th thing of `before` is a `, ## __VA_ARGS__` then return `true`
// if the `__VA_ARGS__` expands to something, and `false` if it expands to
// nothing. If it's not a paste of `__VA_ARGS__` then return `std::nullopt`.
static std::optional<bool> EndsWithEmptyVAArgs(
    const std::vector<MacroOrToken> &before) {
  auto num_entries = before.size();
  if (3u > num_entries) {
    return std::nullopt;
  }

  const Token *comma = std::get_if<Token>(&(before[num_entries - 3u]));
  const Token *hash_hash = std::get_if<Token>(&(before[num_entries - 2u]));
  const Macro *param_sub = std::get_if<Macro>(&(before[num_entries - 1u]));

  if (!comma || !hash_hash || !param_sub) {
    return std::nullopt;
  }

  if (comma->kind() != TokenKind::COMMA ||
      hash_hash->kind() != TokenKind::HASH_HASH ||
      param_sub->kind() != MacroKind::PARAMETER_SUBSTITUTION) {
    return std::nullopt;
  }

  // Not a `...` or a GNU named variadic argument, e.g. `args...`.
  auto param = MacroParameterSubstitution::from(*param_sub);
  if (!param) {
    return std::nullopt;
  }

  Token va_args = LeftCornerOfUse(param.value());
  if (va_args.data() != "__VA_ARGS__") {

    // If it's not `__VA_ARGS__`, then it might be a GNU named variadic
    // argument.
    //
    // TODO(pag): Eventually just use this method. Old indexers had issues
    //            serializing parameter references.
    if (!param->parameter().variadic_dots()) {
      return std::nullopt;
    }
  }

  return !LeftCornerOfExpansion(*param_sub);
}

// Go look for a macro expansion at the end of another macro expansion. This
// is indicative of a specific corner case with macros, e.g.:
//
//      #define HEAD if (1) TAIL
//      #define TAIL(...) {__VA_ARGS__}
//      ...
//      HEAD(return 1;)
//
// Here, the `(return 1;)` are macro use tokens, but they only appear in the
// expansion of `TAIL`, which itself only appears in the expansion of `HEAD`.
static std::optional<MacroExpansion> TrailingExpansionInExpansion(
    const MacroExpansion &exp) {
  std::optional<MacroExpansion> ret;
  for (MacroOrToken mt : exp.replacement_children()) {
    ret.reset();
    if (std::holds_alternative<Macro>(mt)) {
      ret = MacroExpansion::from(std::get<Macro>(mt));
    }
  }

  return ret;
}

// We want to match the body of a macro, or the intermediate children of a macro
// with the expansion of a macro. To best do this, we need to match the actual
// uses of an expansion themselves, and align on those. This does the flattening
// in a way that maximizes our chances of merging against a macro body or an
// intermediate macro body.
static void FlattenExpansionUses(
    MacroOrToken mt, unsigned depth, std::vector<MacroOrToken> &out,
    std::vector<std::optional<MacroOrToken>> &out_orig) {

  if (std::holds_alternative<Token>(mt)) {
    if (!depth) {
      out_orig.emplace_back(mt);

    } else if (out_orig.size() == out.size()) {
      out_orig.emplace_back();
    }

    out.emplace_back(std::move(mt));

  } else if (std::holds_alternative<Macro>(mt)) {
    Macro m = std::move(std::get<Macro>(mt));
    switch (m.kind()) {
      case MacroKind::EXPANSION:
      case MacroKind::CONCATENATE:
      case MacroKind::SUBSTITUTION:
        if (!depth) {
          out_orig.emplace_back(m);

        } else if (out_orig.size() == out.size()) {
          out_orig.emplace_back();
        }
        for (MacroOrToken sub_mt : m.children()) {
          FlattenExpansionUses(std::move(sub_mt), depth + 1u, out, out_orig);
        }
        break;
      case MacroKind::ARGUMENT:
        for (MacroOrToken sub_mt : m.children()) {
          FlattenExpansionUses(std::move(sub_mt), depth, out, out_orig);
        }
        break;
      default:
        if (!depth) {
          out_orig.emplace_back(m);

        } else if (out_orig.size() == out.size()) {
          out_orig.emplace_back();
        }
        out.emplace_back(std::move(m));
        break;
    }
  } else {
    assert(false);
  }

  assert(out_orig.size() == out.size());
}

static std::optional<MacroVAOpt> AsMacroVAOpt(const MacroOrToken &mt) {
  if (!std::holds_alternative<Macro>(mt)) {
    return std::nullopt;
  }
  return MacroVAOpt::from(std::get<Macro>(mt));
}

// Conditionally take the `...` of a `__VA_OPT__(...)` and put it into `out`.
// This will be more likely to match against an expanded macro body.
//
// TODO(pag): Think about whitespace prior to the `__VA_OPT__`. Maybe have a
//            way of "drilling up" to the relevant thing in the logic that
//            injects whitespace?
static void GenerateVAOptChildrenInto(
    MacroVAOpt va_opt, std::vector<MacroOrToken> &out,
    std::vector<std::optional<MacroOrToken>> &out_orig) {

  if (va_opt.contents_are_elided()) {
    return;
  }

  for (MacroOrToken mt : va_opt.children()) {
    if (Macro *m = std::get_if<Macro>(&mt);
        m && m->kind() == MacroKind::VA_OPT_ARGUMENT) {
      out_orig.emplace_back(mt);
      out.emplace_back(std::move(mt));
    }
  }
}


// Tries to figure out if we're in an obscure non-tree trailing macro
// expansion case. This happens with things like:
//
//      #define HEAD TAIL(
//      #define TAIL(x) x
//      ...
//        return HEAD 1);
//
// This can be complicated by recursive use of tail-macros, e.g.:
//
//      #define HEAD DO_TAIL
//      #define DO_TAIL TAIL(
//      #define TAIL(x) x
//      ...
//        return HEAD 1);
static std::optional<MacroExpansion> NonTreeTailExpansion(
    const DefineMacroDirective &def_containing_te_use,
    const MacroExpansion &exp_containing_te_use,
    const MacroExpansion &te) {

  // Get the right corner of the macro use for the trailing expansion. We want
  // to identify if the `)` of a function-like macro call isn't from inside
  // `bounds`.
  Token rc_use = RightCornerOfUse(te);
  D( std::cerr << " rc_use " << rc_use.id() << ": " << rc_use.data() << '\n'; )
  if (!rc_use) {
    return std::nullopt;
  }

  std::optional<MacroExpansion> next_te = TrailingExpansionInExpansion(te);

  if (!next_te) {
    Token rc_def = RightCornerOfUse(def_containing_te_use);
    D( std::cerr << " rc_def " << rc_def.id() << ": " << rc_def.data() << '\n'; )

    // If this is the deepest macro expansion, and if the right corner of the
    // macro use, which is presumably a `)`, is directly derived from the
    // right corner of the macro definition, then we're in a simple expansion.
    if (rc_use.file_token() == rc_def.file_token()) {
      return std::nullopt;
    }

    // Next, try to figure out if the `)` came from an argument, e.g. in the
    // case of the `_Pragma`s `)` in `MACRO(_Pragma(...))`.
    std::optional<Macro> parent = rc_use.derived_token().containing_macro();
    for (; parent; parent = parent->parent()) {
      if (parent.value() == exp_containing_te_use) {
        return std::nullopt;
      }
    }

    return te;
  }

  // We probably have a trailing expansion. One corner case that gets in the
  // way is `_Pragma`s, which are not subjected to the argument pre-expansion
  // phase, and so their expansions show up in the `.replacement_children()`,
  // not in the `MacroArgument`s.

  // If `te` is a trailing expansion that itself contains a trailing expansion
  // `next_te`, then we can only really do analysis if we can locate elements of
  // `next_te`s use in the defintion of `te`. If we have no such definition,
  // then bail out.
  std::optional<DefineMacroDirective> te_def = te.definition();
  if (!te_def) {
    return std::nullopt;
  }

  D( std::cerr << "Recursing into " << te_def->name().data()
               << "'s trailing expansion\n"; )

  std::optional<MacroExpansion> nte = NonTreeTailExpansion(
      te_def.value(), te, next_te.value());
  if (!nte.has_value()) {
    return std::nullopt;
  }

  D( std::cerr << "Found non-tree trailing " << nte->definition()->name().data()
               << '\n'; )

  // Need to detect the case of a `_Pragma` expansion. We do this by checking if
  // the nested expansion `)` matches the current expansion `)`.
  Token nte_rc_use = RightCornerOfUse(nte.value());
  if (nte_rc_use.derived_token() == rc_use) {
    return std::nullopt;
  }

  return nte;
}

struct BodyTokenForChild {
  // The child from the replacement body of a macro substitution.
  MacroOrToken mt;

  // A token from a macro's definition body that we have matched against `mt`.
  // We use this to determine whitespace injection.
  Token definition_token;

  // Tells us if the tokens are from the usage site, i.e. argument tokens.
  std::optional<MacroParameterSubstitution> param_sub;

  BodyTokenForChild(void) = delete;

  inline BodyTokenForChild(MacroOrToken mt_, Token definition_token_,
                           std::optional<MacroParameterSubstitution> param_sub_)
      : mt(std::move(mt_)),
        definition_token(std::move(definition_token_)),
        param_sub(std::move(param_sub_)) {}

  // Figure out the right corner token of the node we're about to add, so that
  // in the next iteration, we can use it for the sake of calculating what
  // tokens (whitespace, comments) to add before the next thing that shows up
  // in the macro body.
  Token RightCornerOfUseFromBody(void) const {
    if (param_sub) {
      return RightCornerOfUse(param_sub.value()).file_token();

    } else if (std::holds_alternative<Token>(mt)) {
      return definition_token;

    } else {
      return RightCornerOfUse(std::get<Macro>(mt)).file_token();
    }
  }
};


static bool IsKeyword(TokenKind tk) {
  switch (tk) {
    case TokenKind::KEYWORD_AUTO:
    case TokenKind::KEYWORD_BREAK:
    case TokenKind::KEYWORD_CASE:
    case TokenKind::KEYWORD_CHARACTER:
    case TokenKind::KEYWORD_CONST:
    case TokenKind::KEYWORD_CONTINUE:
    case TokenKind::KEYWORD_DEFAULT:
    case TokenKind::KEYWORD_DO:
    case TokenKind::KEYWORD_DOUBLE:
    case TokenKind::KEYWORD_ELSE:
    case TokenKind::KEYWORD_ENUM:
    case TokenKind::KEYWORD_EXTERN:
    case TokenKind::KEYWORD_FLOAT:
    case TokenKind::KEYWORD_FOR:
    case TokenKind::KEYWORD_GOTO:
    case TokenKind::KEYWORD_IF:
    case TokenKind::KEYWORD_INT:
    case TokenKind::KEYWORD__EXT_INT:
    case TokenKind::KEYWORD__BIT_INT:
    case TokenKind::KEYWORD_LONG:
    case TokenKind::KEYWORD_REGISTER:
    case TokenKind::KEYWORD_RETURN:
    case TokenKind::KEYWORD_SHORT:
    case TokenKind::KEYWORD_SIGNED:
    case TokenKind::KEYWORD_SIZEOF:
    case TokenKind::KEYWORD_STATIC:
    case TokenKind::KEYWORD_STRUCT:
    case TokenKind::KEYWORD_SWITCH:
    case TokenKind::KEYWORD_TYPEDEF:
    case TokenKind::KEYWORD_UNION:
    case TokenKind::KEYWORD_UNSIGNED:
    case TokenKind::KEYWORD_VOID:
    case TokenKind::KEYWORD_VOLATILE:
    case TokenKind::KEYWORD_WHILE:
    case TokenKind::KEYWORD__ALIGNAS:
    case TokenKind::KEYWORD__ALIGNOF:
    case TokenKind::KEYWORD__ATOMIC:
    case TokenKind::KEYWORD__BOOLEAN:
    case TokenKind::KEYWORD__COMPLEX:
    case TokenKind::KEYWORD__GENERIC:
    case TokenKind::KEYWORD__IMAGINARY:
    case TokenKind::KEYWORD__NORETURN:
    case TokenKind::KEYWORD__STATIC_ASSERT:
    case TokenKind::KEYWORD__THREAD_LOCAL:
    case TokenKind::KEYWORD___FUNC__:
    case TokenKind::KEYWORD___OBJC_YES:
    case TokenKind::KEYWORD___OBJC_NO:
    case TokenKind::KEYWORD_ASSEMBLY:
    case TokenKind::KEYWORD_BOOLEAN:
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
    case TokenKind::KEYWORD_WCHAR_T:
    case TokenKind::KEYWORD_RESTRICT:
    case TokenKind::KEYWORD_INLINE:
    case TokenKind::KEYWORD_ALIGNAS:
    case TokenKind::KEYWORD_ALIGNOF:
    case TokenKind::KEYWORD_CHAR16_T:
    case TokenKind::KEYWORD_CHAR32_T:
    case TokenKind::KEYWORD_CONSTEXPR:
    case TokenKind::KEYWORD_DECLTYPE:
    case TokenKind::KEYWORD_NOEXCEPT:
    case TokenKind::KEYWORD_NULLPTR:
    case TokenKind::KEYWORD_STATIC_ASSERT:
    case TokenKind::KEYWORD_THREAD_LOCAL:
    case TokenKind::KEYWORD_CO_AWAIT:
    case TokenKind::KEYWORD_CO_RETURN:
    case TokenKind::KEYWORD_CO_YIELD:
    case TokenKind::KEYWORD_MODULE:
    case TokenKind::KEYWORD_IMPORT:
    case TokenKind::KEYWORD_CONSTEVAL:
    case TokenKind::KEYWORD_CONSTINIT:
    case TokenKind::KEYWORD_CONCEPT:
    case TokenKind::KEYWORD_REQUIRES:
    case TokenKind::KEYWORD_CHAR8_T:
    case TokenKind::KEYWORD__FLOAT16:
    case TokenKind::KEYWORD_TYPEOF:
    case TokenKind::KEYWORD_TYPEOF_UNQUALIFIED:
    case TokenKind::KEYWORD__ACCUM:
    case TokenKind::KEYWORD__FRACT:
    case TokenKind::KEYWORD__SAT:
    case TokenKind::KEYWORD__DECIMAL32:
    case TokenKind::KEYWORD__DECIMAL64:
    case TokenKind::KEYWORD__DECIMAL128:
    case TokenKind::KEYWORD___NULL:
    case TokenKind::KEYWORD___ALIGNOF:
    case TokenKind::KEYWORD___ATTRIBUTE:
    case TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION:
    case TokenKind::KEYWORD___BUILTIN_OFFSETOF:
    case TokenKind::KEYWORD___BUILTIN_FILE:
    case TokenKind::KEYWORD___BUILTIN_FUNCTION:
    case TokenKind::KEYWORD___BUILTIN_LINE:
    case TokenKind::KEYWORD___BUILTIN_COLUMN:
    case TokenKind::KEYWORD___BUILTIN_SOURCE_TOKEN:
    case TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P:
    case TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT:
    case TokenKind::KEYWORD___EXTENSION__:
    case TokenKind::KEYWORD___FLOAT128:
    case TokenKind::KEYWORD___IBM128:
    case TokenKind::KEYWORD___IMAG:
    case TokenKind::KEYWORD___INT128:
    case TokenKind::KEYWORD___LABEL__:
    case TokenKind::KEYWORD___REAL:
    case TokenKind::KEYWORD___THREAD:
    case TokenKind::KEYWORD___FUNCTION__:
    case TokenKind::KEYWORD___PRETTYFUNCTION__:
    case TokenKind::KEYWORD___AUTO_TYPE:
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
    case TokenKind::KEYWORD___ADD_LVALUE_REFERENCE:
    case TokenKind::KEYWORD___ADD_POINTER:
    case TokenKind::KEYWORD___ADD_RVALUE_REFERENCE:
    case TokenKind::KEYWORD___DECAY:
    case TokenKind::KEYWORD___MAKE_SIGNED:
    case TokenKind::KEYWORD___MAKE_UNSIGNED:
    case TokenKind::KEYWORD___REMOVE_ALL_EXTENTS:
    case TokenKind::KEYWORD___REMOVE_CONST:
    case TokenKind::KEYWORD___REMOVE_CV:
    case TokenKind::KEYWORD___REMOVE_CVREF:
    case TokenKind::KEYWORD___REMOVE_EXTENT:
    case TokenKind::KEYWORD___REMOVE_POINTER:
    case TokenKind::KEYWORD___REMOVE_REFERENCE_T:
    case TokenKind::KEYWORD___REMOVE_RESTRICT:
    case TokenKind::KEYWORD___REMOVE_VOLATILE:
    case TokenKind::KEYWORD___UNDERLYING_TYPE:
    case TokenKind::KEYWORD___IS_TRIVIALLY_RELOCATABLE:
    case TokenKind::KEYWORD___IS_BOUNDED_ARRAY:
    case TokenKind::KEYWORD___IS_UNBOUNDED_ARRAY:
    case TokenKind::KEYWORD___IS_NULLPTR:
    case TokenKind::KEYWORD___IS_SCOPED_ENUM:
    case TokenKind::KEYWORD___IS_REFERENCEABLE:
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
    case TokenKind::KEYWORD___NOINLINE__:
    case TokenKind::KEYWORD_CBUFFER:
    case TokenKind::KEYWORD_TBUFFER:
    case TokenKind::KEYWORD_GROUPSHARED:
    case TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN:
    case TokenKind::KEYWORD___PASCAL:
    case TokenKind::KEYWORD___VECTOR:
    case TokenKind::KEYWORD___PIXEL:
    case TokenKind::KEYWORD___BOOLEAN:
    case TokenKind::KEYWORD___BF16:
    case TokenKind::KEYWORD_HALF:
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
    case TokenKind::KEYWORD___PTR64:
    case TokenKind::KEYWORD___PTR32:
    case TokenKind::KEYWORD___SPTR:
    case TokenKind::KEYWORD___UPTR:
    case TokenKind::KEYWORD___W64:
    case TokenKind::KEYWORD___UUIDOF:
    case TokenKind::KEYWORD___TRY:
    case TokenKind::KEYWORD___FINALLY:
    case TokenKind::KEYWORD___LEAVE:
    case TokenKind::KEYWORD___INT64:
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
      return true;
    default:
      return false;
  }
}

static bool AddLeadingWhitespace(TokenKind tk) {
  switch (tk) {
    case TokenKind::WHITESPACE:
      return false;
//    case TokenKind::NUMERIC_CONSTANT:
//    case TokenKind::CHARACTER_CONSTANT:
//    case TokenKind::WIDE_CHARACTER_CONSTANT:
//    case TokenKind::UTF8_CHARACTER_CONSTANT:
//    case TokenKind::UTF16_CHARACTER_CONSTANT:
//    case TokenKind::UTF32_CHARACTER_CONSTANT:
//    case TokenKind::STRING_LITERAL:
//    case TokenKind::WIDE_STRING_LITERAL:
//    case TokenKind::HEADER_NAME:
//    case TokenKind::UTF8_STRING_LITERAL:
//    case TokenKind::UTF16_STRING_LITERAL:
//    case TokenKind::UTF32_STRING_LITERAL:

    case TokenKind::AMP:
    case TokenKind::AMP_AMP:
    case TokenKind::AMP_EQUAL:
    case TokenKind::STAR:
    case TokenKind::STAR_EQUAL:
    case TokenKind::PLUS:
//    case TokenKind::PLUS_PLUS:
    case TokenKind::PLUS_EQUAL:
    case TokenKind::MINUS:
//    case TokenKind::ARROW:
//    case TokenKind::MINUS_MINUS:
    case TokenKind::MINUS_EQUAL:
    case TokenKind::TILDE:
    case TokenKind::EXCLAIM:
    case TokenKind::EXCLAIM_EQUAL:
    case TokenKind::SLASH:
    case TokenKind::SLASH_EQUAL:
    case TokenKind::PERCENT:
    case TokenKind::PERCENT_EQUAL:
    case TokenKind::LESS:  // TODO(pag): Templates.
    case TokenKind::LESS_LESS:  // TODO(pag): Templates.
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
//    case TokenKind::COLON:
//    case TokenKind::SEMI:
    case TokenKind::EQUAL:
    case TokenKind::EQUAL_EQUAL:
//    case TokenKind::COMMA:
    case TokenKind::LESS_LESS_LESS:
    case TokenKind::GREATER_GREATER_GREATER:
    case TokenKind::L_BRACE:
    case TokenKind::R_BRACE:
      return true;
    default:
      return IsKeyword(tk);
  }
}

static bool IsFirst(TokenKind tk) {
  switch (tk) {
    case TokenKind::WHITESPACE:
    case TokenKind::L_PARENTHESIS:
    case TokenKind::L_SQUARE:
    case TokenKind::L_BRACE:
    case TokenKind::R_BRACE:
    case TokenKind::SEMI:
    case TokenKind::COMMA:
      return true;
    default:
      return false;
  }
}

static bool AddTrailingWhitespace(TokenKind tk) {
  switch (tk) {
    case TokenKind::WHITESPACE:
      return false;
    case TokenKind::AMP:
    case TokenKind::AMP_AMP:
    case TokenKind::AMP_EQUAL:
    case TokenKind::STAR:
    case TokenKind::STAR_EQUAL:
    case TokenKind::PLUS:
//    case TokenKind::PLUS_PLUS:
    case TokenKind::PLUS_EQUAL:
    case TokenKind::MINUS:
//    case TokenKind::ARROW:
//    case TokenKind::MINUS_MINUS:
    case TokenKind::MINUS_EQUAL:
//    case TokenKind::TILDE:
//    case TokenKind::EXCLAIM:
    case TokenKind::EXCLAIM_EQUAL:
    case TokenKind::SLASH:
    case TokenKind::SLASH_EQUAL:
    case TokenKind::PERCENT:
    case TokenKind::PERCENT_EQUAL:
    case TokenKind::LESS:  // TODO(pag): Templates.
    case TokenKind::LESS_LESS:  // TODO(pag): Templates.
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
    case TokenKind::LESS_LESS_LESS:
    case TokenKind::GREATER_GREATER_GREATER:
    case TokenKind::R_BRACE:
      return true;
    default:
      return IsKeyword(tk);
  }
}

static bool AddTrailingWhitespaceAsFirst(TokenKind tk) {
  switch (tk) {
    case TokenKind::WHITESPACE:
    case TokenKind::STAR:
    case TokenKind::AMP:
    case TokenKind::PLUS:
    case TokenKind::MINUS:
      return false;
    default:
      return AddTrailingWhitespace(tk);
  }
}

static bool SuppressLeadingWhitespace(TokenKind tk) {
  switch (tk) {
    case TokenKind::WHITESPACE:
    case TokenKind::COMMA:
    case TokenKind::R_PARENTHESIS:
    case TokenKind::R_SQUARE:
      return true;
    default:
      return false;
  }
}

static bool ForceLeadingWhitespace(bool prev_is_first, TokenKind prev,
                                   TokenKind curr, bool curr_is_first) {
  auto prev_is_ident_kw = prev == TokenKind::IDENTIFIER || IsKeyword(prev);
  auto curr_is_ident_kw = curr == TokenKind::IDENTIFIER || IsKeyword(curr);
  if (prev_is_ident_kw && curr_is_ident_kw) {
    return true;
  }
  (void) prev_is_first;
  (void) curr_is_first;
  return false;
}

}  // namespace

struct TokenTreeImpl::MacroExpansionProcessor {

  // Adjusted children from a macro definition body.
  std::vector<MacroOrToken> body_children;

  // Tokens or macros from the expansion of a macro, expanded out in a way that
  // can be compared against `body_children`.
  std::vector<MacroOrToken> after_children;

  // Non-expanded versions of `before_children` and `after_children`, where we
  // need to keep track of the unexpanded forms in order for `merged_children`
  // to be able to represent a complete expansion tree, otherwise
  // `merged_children` will only represent a single level deep of an expansion.
  std::vector<std::optional<MacroOrToken>> body_use;
  std::vector<std::optional<MacroOrToken>> after_use;

  // The result of aligning `body_children` with `after_children`, and then
  // selecting values from `body_children` or `after_use` to form up a proper
  // "view" of what the expanded children should look like.
  std::vector<BodyTokenForChild> merged_children;

  bool body_has_trailing_comment{false};

  void Init(const MacroExpansion &me, const DefineMacroDirective &def,
            const Bounds &def_bounds);
  bool Run(bool is_non_tree);

  inline bool HasAfterChildren(void) const {
    return !after_children.empty();
  }

  inline const std::vector<BodyTokenForChild> &ReplacementChildren(void) const {
    return merged_children;
  }
};

void TokenTreeImpl::MacroExpansionProcessor::Init(
    const MacroExpansion &me, const DefineMacroDirective &def,
    const Bounds &def_bounds) {

  body_children.clear();
  after_children.clear();
  body_use.clear();
  after_use.clear();
  merged_children.clear();
  body_has_trailing_comment = false;

  for (MacroOrToken mt : me.replacement_children()) {
    FlattenExpansionUses(std::move(mt), 0u, after_children, after_use);
  }

  for (MacroOrToken mt : me.intermediate_children()) {

    // Expand or eliminate a `__VA_OPT__`.
    //
    // TODO(pag): Leading whitespace? Maybe have a new variant that can hold
    //            on to some token for whitespace purposes, or a new vector
    //            for leading whitespace.
    if (std::optional<MacroVAOpt> va_opt = AsMacroVAOpt(mt)) {
      GenerateVAOptChildrenInto(std::move(va_opt.value()), body_children,
                                body_use);

      // NOTE(pag): `__VA_OPT__` can contain `, ## __VA_ARGS__`.

    } else {
      body_use.emplace_back(mt);
      body_children.emplace_back(std::move(mt));
    }

    // If the thing has a use of `## , __VA_ARGS__`, then we need to convert
    // this into `, <stuff>` or nothing.
    if (auto is_empty = EndsWithEmptyVAArgs(body_children)) {
      D( std::cerr << "BT(" << (body_children.size() - 3)
                   << ") has `, ## __VA_ARGS__`\n"; )

      assert(body_children.size() == body_use.size());

      mt = std::move(body_children.back());
      body_children.pop_back();
      body_children.pop_back();  // `##`.
      MacroOrToken comma = std::move(body_children.back());
      body_children.pop_back();

      body_use.pop_back();
      body_use.pop_back();
      body_use.pop_back();

      if (!is_empty.value()) {
        body_use.emplace_back(comma);
        body_children.push_back(std::move(comma));

        FlattenExpansionUses(std::move(mt), 0u, body_children, body_use);
      }
    }
  }

  assert(after_children.size() == after_use.size());
  assert(body_children.size() == body_use.size());

  // If `body_children` is empty, then there was probably nothing interesting
  // in the macro body, i.e. no token concatenation, no parameter-to-argument
  // substitution, etc. So, we'll just collect the raw tokens from the macro
  // body.
  if (body_children.empty()) {
    for (MacroOrToken mt : def.body()) {
      body_use.emplace_back(mt);
      body_children.emplace_back(std::move(mt));
    }
  }

  // We may be missing a trailing comment, so try to capture that.
  if (auto file_of_def = File::containing(def)) {
    Token last_body_tok = file_of_def->tokens()[def_bounds.end_index];
    if (last_body_tok.kind() == TokenKind::COMMENT) {
      D( std::cerr << "Adding trailing macro body comment\n"; )
      body_use.emplace_back(last_body_tok);
      body_children.emplace_back(std::move(last_body_tok));
      body_has_trailing_comment = true;
    }
  }
}

bool TokenTreeImpl::MacroExpansionProcessor::Run(bool is_non_tree) {
  size_t i = 0u;
  size_t j = 0u;

  size_t max_i = body_children.size();
  size_t max_j = after_children.size();

  Token bt_lc;
  Token bt_param_lc;
  Token at_lc;

  D( std::cerr << "max_i = " << max_i << "; max_j = " << max_j << '\n'; )

  while (i < max_i && j < max_j) {
    const MacroOrToken &bt = body_children[i];
    const MacroOrToken &at = after_children[j];

    const Token *bt_tok = std::get_if<Token>(&bt);
    const Token *at_tok = std::get_if<Token>(&at);
    const Token *bt_def_tok = bt_tok;

    std::optional<MacroParameterSubstitution> param_sub;

    if (!bt_tok) {
      assert(std::holds_alternative<Macro>(bt));
      const Macro &bt_macro = std::get<Macro>(bt);
      MacroKind btk = bt_macro.kind();
      param_sub = MacroParameterSubstitution::from(bt_macro);
      bt_lc = LeftCornerOfExpansion(bt_macro);
      bt_param_lc = LeftCornerOfUse(bt_macro);
      bt_tok = &bt_lc;
      bt_def_tok = &bt_param_lc;
    }

    if (!at_tok) {
      assert(std::holds_alternative<Macro>(at));
      at_lc = LeftCornerOfUse(std::get<Macro>(at));
      at_tok = &at_lc;
      assert(*at_tok);
    }

    assert(bt_tok && at_tok);

    D( std::cerr << "BT(" << i;
       if (param_sub) {
         std::cerr << "; PARAM=" << bt_def_tok->data();
       }
       std::cerr << "): " << bt_tok->id() << ' ' << bt_tok->data()
                 << "\nAT(" << j << "): " << at_tok->id() << ' '
                 << at_tok->data() << "\n\n"; )

    // A parameter was substituted with nothing.
    if (!bt_tok || !*bt_tok) {
      if (param_sub) {
        merged_children.emplace_back(
            Token(), Token(), std::move(param_sub));
      }
      ++i;

    } else if (bt_tok->data() == at_tok->data()) {
      if (auto au = std::move(after_use[j])) {
        assert(au.has_value());
        merged_children.emplace_back(
            std::move(au.value()), bt_def_tok->file_token(),
            std::move(param_sub));
      }
      ++i;
      ++j;

    // Skip over stuff in expansions.
    } else {
      if (auto au = std::move(after_use[j])) {
        assert(au.has_value());
        merged_children.emplace_back(
            std::move(au.value()), Token(), std::move(param_sub));
      }
      ++j;
    }
  }

#if D( 1 + ) 0
  for (auto missing_j = j; missing_j < max_j; ++missing_j) {
    const MacroOrToken &at = after_children[missing_j];
    const Token *at_tok = std::get_if<Token>(&at);
    if (!at_tok) {
      at_lc = LeftCornerOfExpansion(std::get<Macro>(at));
      at_tok = &at_lc;
    }
    std::cerr << "MISSING_AT(" << missing_j << "): "
              << at_tok->id() << ' ' << at_tok->data() << "\n";
  }
#endif

  // Collect the trailing comment, if we made it there.
  if (body_has_trailing_comment && (i + 1u) == max_i) {
    merged_children.emplace_back(
        std::move(body_children.back()), Token(), std::nullopt);
    ++i;
  }

  if (is_non_tree) {
    return j == max_j || i == max_i;
  }

  for (; j < max_j; ++j) {
    if (auto au = std::move(after_use[j])) {
      assert(au.has_value());
      merged_children.emplace_back(std::move(au.value()), Token(),
                                   std::nullopt);
    }
  }

#if D( 1 + ) 0
  for (auto missing_i = i; missing_i < max_i; ++missing_i) {
    const MacroOrToken &bt = body_children[missing_i];
    const Token *bt_tok = std::get_if<Token>(&bt);
    if (!bt_tok) {
      bt_lc = LeftCornerOfExpansion(std::get<Macro>(bt));
      bt_tok = &bt_lc;
    }
    std::cerr << "MISSING_BT(" << missing_i << "): "
              << bt_tok->id() << ' ' << bt_tok->data() << "\n";
  }
#endif

  return i == max_i && j == max_j;
}

// NOTE(pag): This will reset `curr_leaf` if `that == curr_leaf` and
//            `curr_leaf` is empty.
template <typename T>
TokenTreeImpl::SequenceNode *TokenTreeImpl::AddToSequence(
    SequenceNode *seq, T *that, const TrailingTokens &trailing_tokens) {
  if (!that) {
    return seq;
  }

  if constexpr (std::is_same_v<SequenceNode, T>) {
    if (seq == that) {
      return seq;
    } else if (!seq) {
      return that;
    } else if (seq->children.empty()) {
      return that;
    } else if (that->children.empty()) {
      return seq;
    } else {
      seq->children.insert(seq->children.end(), that->children.begin(),
                           that->children.end());
      goto end;
    }

  // Try to fold single-item choice nodes.
  } else if constexpr (std::is_same_v<ChoiceNode, T>) {
    // if (that->children.size() == 1u) {
    //   return AddNodeToSequence(seq, that->children.front(), trailing_tokens);
    // }
  }

  if (!seq) {
    seq = &(sequences.emplace_back());
  }

  seq->children.emplace_back(that);

end:
  return AddTrailingTokensToSequence(seq, trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTokenToSequence(
    SequenceNode *seq, const Token &tok,
    const TrailingTokens &trailing_tokens) {
  return AddTrailingTokensToSequence(
      AddTokenToSequence(seq, GetOrCreateIndex(tok)),
      trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTokenToSequence(
    SequenceNode *seq, TokenIndex ti) {
  if (!seq) {
    seq = &(sequences.emplace_back());
  }

  D( std::cerr << INDENT << "AddTokenToSequence: " << TOKEN_INDEX(ti) << '\n'; )

  seq->children.push_back(ti);
  return seq;
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddNodeToSequence(
    SequenceNode *seq, const Node &node,
    const TrailingTokens &trailing_tokens) {
  return std::visit<SequenceNode *>(
      [=, this, &trailing_tokens] (auto &&arg) -> SequenceNode * {
        using arg_t = std::decay_t<decltype(arg)>;
        if constexpr (std::is_pointer_v<arg_t>) {
          return AddToSequence(seq, arg, trailing_tokens);
        } else if constexpr (std::is_same_v<arg_t, TokenIndex>) {
          return AddTrailingTokensToSequence(AddTokenToSequence(seq, arg),
                                             trailing_tokens);
        } else {
          return seq;
        }
      },
      node);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddTrailingTokensToSequence(
    SequenceNode *seq, const TrailingTokens &trailing_tokens) {

  auto prev_depth = depth;
  for (const Token &tok : trailing_tokens.tokens) {
    depth = trailing_tokens.depth;
    seq = AddLeadingTokensInBounds(seq, tok.file_token(), trailing_tokens.bounds);
    seq = AddTokenToSequence(seq, GetOrCreateIndex(tok));
  }

  if (trailing_tokens.next_trailing) {
    seq = AddTrailingTokensToSequence(seq, *(trailing_tokens.next_trailing));
  }

  depth = prev_depth;
  return seq;
}

// Find the bounds of a top-level macro use.
std::optional<TokenTreeImpl::Bounds> TokenTreeImpl::TopLevelUseBounds(
    const Macro &exp) {
  Bounds ret = {};
  Token last_tok;
  for (Token tok : exp.generate_use_tokens()) {
    if (Token file_tok = tok.file_token()) {
      if (!last_tok) {
        TokenIndex ti = GetOrCreateIndex(file_tok);
        ret.reader = ti.first;
        ret.begin_index = ti.second + 1u;
        ret.end_index = ret.begin_index;
      }

      last_tok = std::move(file_tok);
    }
  }

  TokenIndex ti = GetOrCreateIndex(last_tok);
  ret.end_index = ti.second;
  if (ret.begin_index > ret.end_index) {
    assert(false);
    return std::nullopt;
  }

  if (!ti.first->Equals(ret.reader)) {
    assert(false);
    return std::nullopt;
  }

  return ret;
}

TokenTreeImpl::Bounds TokenTreeImpl::FragmentBounds(const TokenRange &tokens) {
  Bounds ret = {};
  if (!tokens.empty()) {
    auto [ri_begin, ti_begin] = GetOrCreateIndex(tokens.front());
    auto [ri_end, ti_end] = GetOrCreateIndex(tokens.back());
    if (ri_begin != ri_end) {
      assert(false);
      return ret;
    }

    if (ti_begin > ti_end) {
      assert(false);
      return ret;
    }

    ret.reader = ri_begin;
    ret.begin_index = ti_begin;
    ret.end_index = ti_end;
  }
  return ret;
}

// Widen bounds to cover leading/trailing comments.
TokenTreeImpl::Bounds TokenTreeImpl::WidenBounds(Bounds ret) {
  // Try to widen to encompass leading comments.
  for (auto i = ret.begin_index; i; ) {
    switch (ret.reader->NthTokenKind(--i)) {
      case TokenKind::COMMENT:
        ret.begin_index = i;
        continue;
      case TokenKind::WHITESPACE:
        continue;
      default:
        i = 0u;
        break;
    }
  }

  // Try to widen to encompass trailing comments.
  auto saw_lc = false;
  auto good = true;
  for (auto i = ret.end_index; good; ) {
    switch (ret.reader->NthTokenKind(++i)) {
      case TokenKind::COMMENT:
        ret.end_index = i;
        continue;
      case TokenKind::WHITESPACE:
        saw_lc = false;
        for (auto ch : ret.reader->NthTokenData(i)) {
          if (ch == '\\') {
            saw_lc = true;
          } else if (ch == '\r') {
            continue;
          } else if (ch == '\n') {
            if (!saw_lc) {
              good = false;
              break;
            } else {
              saw_lc = false;
              break;
            }
          } else {
            saw_lc = false;
          }
        }
        continue;
      default:
        good = false;
        continue;
    }
  }

  return ret;
}

// Find the bounds of a macro definition body.
std::optional<TokenTreeImpl::Bounds> TokenTreeImpl::MacroBodyBounds(
    const DefineMacroDirective &def) {

  Bounds ret = {};
  Token last_tok;

  for (MacroOrToken mt : def.body()) {
    if (std::holds_alternative<Token>(mt)) {
      if (Token file_tok = std::get<Token>(mt).file_token()) {
        if (!last_tok) {
          TokenIndex ti = GetOrCreateIndex(file_tok);
          ret.reader = ti.first;
          ret.begin_index = ti.second;
          ret.end_index = ret.begin_index;
        } else {
          assert(ret.reader->Equals(GetOrCreateIndex(file_tok).first));
        }
        last_tok = std::move(file_tok);
      }

    } else if (std::holds_alternative<Macro>(mt)) {
      const Macro &m = std::get<Macro>(mt);
      if (Token file_tok = LeftCornerOfUse(m).file_token()) {
        if (!last_tok) {
          TokenIndex ti = GetOrCreateIndex(file_tok);
          ret.reader = ti.first;
          ret.begin_index = ti.second;
          ret.end_index = ret.begin_index;
        } else {
          assert(ret.reader->Equals(GetOrCreateIndex(file_tok).first));
        }

        last_tok = std::move(file_tok);
        if (auto rc_file_tok = RightCornerOfUse(m).file_token()) {
          assert(ret.reader->Equals(GetOrCreateIndex(rc_file_tok).first));
          last_tok = std::move(rc_file_tok);
        }
      }
    }
  }

  if (!last_tok) {
    return std::nullopt;
  }

  TokenIndex ti = GetOrCreateIndex(last_tok);
  assert(ti.first->Equals(ret.reader));
  assert(ti.second >= ret.begin_index);
  ret.end_index = ti.second;
  return WidenBounds(ret);
}

// Get a `TokenIndex` for `tok`. This will save the reader into the token tree
// if it can't be found, formulating a new token index position for that reader.
TokenTreeImpl::TokenIndex TokenTreeImpl::GetOrCreateIndex(const Token &tok) {
  if (!tok) {
    return TokenIndex(InvalidTokenReader::RawSingleton(), 0u);
  }

  nested_readers.emplace(tok.impl.get(), tok.impl);
  return TokenIndex(tok.impl.get(), tok.offset);
}

// Get the `TokenIndex` that is the right corner of an existing use.
static std::optional<TokenTreeImpl::TokenIndex> RightCornerOfUse(
    const TokenTreeImpl::Node &node) {
  if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
    return std::get<TokenTreeImpl::TokenIndex>(node);

  } else if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    return RightCornerOfUse(
        std::get<TokenTreeImpl::ChoiceNode *>(node)->children.front());

  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (auto seq = std::get<TokenTreeImpl::SequenceNode *>(node);
        seq && !seq->children.empty()) {
      return RightCornerOfUse(seq->children.back());
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (auto sub = std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      return RightCornerOfUse(sub->before);
    }
  }
  return std::nullopt;
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddLeadingTokensInBounds(
    SequenceNode *seq, TokenIndex fti, EntityId fti_id, const Bounds &bounds) {

  D( std::cerr << INDENT << "AddLeadingTokensInBounds: bounds="
               << BOUNDS(bounds) << " fti=" << TOKEN_INDEX(fti) << '\n'; )

  auto maybe_rci = RightCornerOfUse(seq);
  if (!maybe_rci) {
    return seq;
  }

  return AddLeadingTokensInBounds(seq, fti, fti_id, maybe_rci.value(), bounds);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::AddLeadingTokensInBounds(
    SequenceNode *seq, TokenIndex fti, EntityId fti_id, TokenIndex rci,
    const Bounds &bounds) {

  if (!fti.second || fti.second <= bounds.begin_index ||
      (fti.second - 1u) > bounds.end_index ||
      !fti.first->Equals(bounds.reader)) {
    return seq;
  }

  D( std::cerr << INDENT << "AddLeadingTokensInBounds: rci="
               << TOKEN_INDEX(rci) << '\n'; )

  // The right corner of `seq` might be in a different token tree, and it might
  // not be a file token.
  if (!rci.first->Equals(fti.first)) {
    auto rci_ft_id = rci.first->NthFileTokenId(rci.second).Extract<FileTokenId>();
    if (!rci_ft_id) {
      return seq;
    }

    auto fti_ft_id = fti_id.Extract<FileTokenId>();
    if (rci_ft_id->file_id != fti_ft_id->file_id) {
      return seq;
    }

    rci.first = fti.first;
    rci.second = rci_ft_id->offset;
  }

  D( std::cerr << INDENT << "AddLeadingTokensInBounds: adjusted rci=" << TOKEN_INDEX(rci) << '\n'; )
  if (!rci.first->Equals(fti.first)) {
    return seq;
  }

  auto begin = std::max(bounds.begin_index, rci.second + 1u);
  auto end = std::min(bounds.end_index, fti.second - 1u);

  D( std::cerr << INDENT << "AddLeadingTokensInBounds: begin=" << begin << ", end=" << end << '\n'; )
  for (auto i = begin; i <= end; ++i) {
    seq = AddTokenToSequence(seq, TokenIndex(fti.first, i));
  }

  return seq;
}

// Try to add leading file tokens into `node` that should logically come from
// before `tok`.
TokenTreeImpl::SequenceNode *TokenTreeImpl::AddLeadingTokensInBounds(
    SequenceNode *seq, const Token &tok, const Bounds &bounds) {

  auto use_seq = seq ? seq : last_sequence;
  if (!use_seq) {
    return seq;
  }

  Token file_tok = tok.file_token();
  if (!file_tok) {
    return seq;
  }

  auto out_seq = AddLeadingTokensInBounds(
      use_seq, GetOrCreateIndex(file_tok), file_tok.id(), bounds);
  return use_seq == seq ? out_seq : seq;
}

namespace {

static unsigned NumPrecedingWhitespaceComments(TokenTreeImpl::TokenIndex fti) {
  auto num = 0u;
  for (auto i = 1u; i <= fti.second; ++i) {
    switch (fti.first->NthTokenKind(fti.second - i)) {
      case TokenKind::COMMENT:
      case TokenKind::WHITESPACE:
        ++num;
        continue;
      default:
        return num;
    }
  }
  return num;
}

}  // namespace

// Backup function for adding missing whitespace/comments that precede a
// parameter before the substitution of that parameter.
TokenTreeImpl::SequenceNode *TokenTreeImpl::AddLeadingTokensBeforeParam(
    SequenceNode *seq, TokenIndex fti, const Bounds &bounds) {

  if (fti.second && fti.second < bounds.begin_index ||
      fti.second > bounds.end_index || !fti.first->Equals(bounds.reader)) {
    return seq;
  }

  auto num_ws = NumPrecedingWhitespaceComments(fti);

  D( std::cerr << INDENT << "AddLeadingTokensBeforeParam: fti="
               << TOKEN_INDEX(fti) << " num_ws=" << num_ws << '\n'; )

  for (auto i = 0u; i < num_ws; ++i) {
    seq = AddTokenToSequence(
        seq, TokenIndex(fti.first, fti.second - (num_ws - i)));
  }

  return seq;
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacroChild(
    SequenceNode *seq, const MacroOrToken &mt, const Bounds &bounds,
    const TrailingTokens &trailing_tokens) {

  if (std::holds_alternative<Token>(mt)) {
    return AddTokenToSequence(seq, std::get<Token>(mt), trailing_tokens);

  } else if (std::holds_alternative<Macro>(mt)) {
    return ExtendWithMacro(seq, std::get<Macro>(mt), bounds, trailing_tokens);

  } else {
    assert(false);
    return seq;
  }
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacroChildren(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds,
    const TrailingTokens &trailing_toks) {

  FILL_MACRO_CHILREN(macro.children(), mts, fts)
  return ProcessMacroChildren(seq, bounds, std::move(mts), std::move(fts),
                              trailing_toks);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithSimpleExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const DefineMacroDirective &me_def, const Bounds &user_bounds,
    const Bounds &def_bounds, const TrailingTokens &trailing_tokens) {

  MacroExpansionProcessor mep;
  mep.Init(me, me_def, def_bounds);
  if (!mep.Run(false)) {
    assert(!mep.HasAfterChildren());  // Probably a bug.
    return ExtendWithSubstitution(seq, me, user_bounds, trailing_tokens);
  }

  SaveRestoreLastSequence seq_raii(last_sequence, seq);

  FILL_MACRO_CHILREN(me.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, user_bounds, std::move(mts), std::move(fts), trailing_tokens);

  if (!before) {
    assert(trailing_tokens.tokens.empty());
    return nullptr;
  }

  auto prev_depth = depth;
  auto next_depth = depth + 1;

  D( std::cerr << INDENT << "ExtendWithSimpleExpansion: user_bounds="
               << BOUNDS(user_bounds) << " def_bounds="
               << BOUNDS(def_bounds) << '\n'; )

  Token prev_rc;

  last_sequence = &dummy_sequence;
  SequenceNode *after = nullptr;
  for (const BodyTokenForChild &node : mep.ReplacementChildren()) {
    depth = next_depth;

    const size_t old_size = after ? after->children.size() : 0u;

    // Try to inject whitespace/comments before things like parameter uses.
    if (after && prev_rc && node.definition_token) {
      TokenIndex prev_rci = GetOrCreateIndex(prev_rc);
      TokenIndex dti = GetOrCreateIndex(node.definition_token);

      D( std::cerr << INDENT
                   << "ExtendWithSimpleExpansion: Injecting body tokens before "
                   << node.definition_token.id() << '\n'; )
      if ((prev_rci.second + 1u) < dti.second &&
          prev_rci.first->Equals(dti.first) &&
          prev_rci.first->Equals(def_bounds.reader)) {
        after = AddLeadingTokensInBounds(after, dti, node.definition_token.id(),
                                         prev_rci, def_bounds);
      }
    }

    if (after && node.definition_token && old_size == after->children.size()) {
      after = AddLeadingTokensBeforeParam(
          after, GetOrCreateIndex(node.definition_token), def_bounds);
    }

    if (node.param_sub) {
      after = ExtendWithMacroChild(after, node.mt, user_bounds,
                                   dummy_trailing_tokens);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds,
                                   dummy_trailing_tokens);
    }

    prev_rc = node.RightCornerOfUseFromBody();

    assert(depth == next_depth);
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  sub->before = before;
  if (after) {
    sub->after = after;
  }

  depth = prev_depth;
  return AddToSequence(seq, sub, dummy_trailing_tokens);
}

// Process `mts`, a list of children of some kind. There is a one-to-one
// correspondence between `mts` and `fts`. `fts[i]` is the left corner of
// `mts[i]`. The purpose of `fts` is to help us find bounds for injecting
// stuff like whitespace.
TokenTreeImpl::SequenceNode *TokenTreeImpl::ProcessMacroChildren(
    TokenTreeImpl::SequenceNode *seq, const Bounds &bounds,
    std::vector<MacroOrToken> mts, std::vector<Token> fts,
    const TrailingTokens &trailing_tokens) {

  size_t num_mts = mts.size();

  D( std::cerr << INDENT << "ProcessMacroChildren: bounds="
               << BOUNDS(bounds) << '\n'; )

  for (auto i = 0u; i < num_mts; ++i) {
    const MacroOrToken &mt = mts[i];
    auto &tt = (i + 1u) == num_mts ? trailing_tokens : dummy_trailing_tokens;

    if (std::holds_alternative<Token>(mt)) {
      const Token &tok = std::get<Token>(mt);
      seq = AddLeadingTokensInBounds(seq, fts[i], bounds);
      seq = AddTokenToSequence(seq, tok, tt);
      continue;
    }

    if (!std::holds_alternative<Macro>(mt)) {
      assert(false);
      continue;
    }

    const Macro &m = std::get<Macro>(mt);
    const Token &lc_ft = fts[i];

    // Try to get stricter bounds on the macro use.
    if (!lc_ft) {
      seq = ExtendWithMacro(seq, m, bounds, tt);
      continue;
    }

    TokenIndex lc_index = GetOrCreateIndex(lc_ft);
    Bounds new_bounds = bounds;

    D( std::cerr << INDENT << "ProcessMacroChildren(" << i << "): lc_index="
                 << TOKEN_INDEX(lc_index) << '\n'; )

    if (lc_index.second < bounds.begin_index ||
        lc_index.second > bounds.end_index ||
        !new_bounds.reader->Equals(lc_index.first)) {

      D( std::cerr << INDENT << "\tFailed to tighten bounds\n"; )
      seq = ExtendWithMacro(seq, m, bounds, tt);
      continue;
    }

    assert(new_bounds.begin_index <= lc_index.second);
    new_bounds.begin_index = lc_index.second;

    // Try to look at the new thing we want to add in order to tighten the
    // upper bounds.
    if ((i + 1u) < num_mts) {
      const Token &rc_ft = fts[i + 1u];
      if (rc_ft) {
        TokenIndex rc_index = GetOrCreateIndex(rc_ft);
        if (rc_index.second >= new_bounds.begin_index &&
            rc_index.second <= new_bounds.end_index &&
            new_bounds.reader->Equals(rc_index.first)) {
          assert(new_bounds.begin_index <= rc_index.second);
          assert(rc_index.second <= new_bounds.end_index);
          new_bounds.end_index = rc_index.second - 1u;
        }
      }
    }

    seq = AddLeadingTokensInBounds(seq, lc_ft, bounds);

    D( std::cerr << INDENT << "ProcessMacroChildren(" << i << "): new_bounds="
                 << BOUNDS(new_bounds) << '\n'; )
    seq = ExtendWithMacro(seq, m, new_bounds, tt);
  }

  if (!num_mts) {
    seq = AddTrailingTokensToSequence(seq, trailing_tokens);
  }

  return seq;
}

// Extend with a "non-tree" macro expansion, e.g. something like:
//
//    #define TAIL(...) __VA_ARGS__
//    #define HEAD if (1) TAIL(
//    ...
//    HEAD a, b, c)
//
// In older versions of PASTA, the following also was sometimes a non-tree
// case:
//
//    #define TAIL(...) __VA_ARGS__
//    #define HEAD if (1) TAIL
//    ...
//    HEAD(a, b, c)
//
// Our detection logic in `ExtendWithExpansion` generally works for both. We
// are primarily concerned with meaningfully renderable tokens, and what happens
// in the non-tree cases is that `a, b, c)` in the former example or `(a, b, c)`
// in the latter example end up in the nested macro use of the top-level
// expansion of `HEAD`. This breaks our "meaningfulness" criteria, because
// these tokens are top-level tokens, and so while they should appear in the
// use of the expansion, they should also show up in the use itself.
TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithNonTreeExpansion(
    SequenceNode *seq, const MacroExpansion &me, const Bounds &me_bounds,
    const DefineMacroDirective &def, const Bounds &def_bounds,
    const MacroExpansion &dte, const TrailingTokens &prev_trailing_tokens) {

  D( std::cerr << "Non-tree " << def.name().data() << "\n"; )
  TrailingTokens trailing_tokens;
  trailing_tokens.depth = depth;  // Use this.
  trailing_tokens.bounds = me_bounds;
  trailing_tokens.next_trailing = &prev_trailing_tokens;

  for (Token te_tok : dte.generate_use_tokens()) {
    Token te_file_tok = te_tok.file_token();
    if (!te_file_tok) {
      trailing_tokens.tokens.clear();
      continue;
    }

    TokenIndex ti = GetOrCreateIndex(te_file_tok);
    if (ti.second < me_bounds.begin_index ||
        ti.second > me_bounds.end_index ||
        !ti.first->Equals(me_bounds.reader)) {
      trailing_tokens.tokens.clear();
      continue;
    }

    D( std::cerr << " - Trailing token: " << te_tok.data() << '\n'; )
    trailing_tokens.tokens.emplace_back(std::move(te_tok));
  }

  auto prev_depth = depth;
  auto next_depth = depth + 1;

  MacroExpansionProcessor mep;
  mep.Init(me, def, def_bounds);
  if (!mep.Run(true)) {
    assert(false);  // Probably not a bug, just something sketchy/odd.
    return ExtendWithSubstitution(seq, me, me_bounds, trailing_tokens);
  }

  SaveRestoreLastSequence seq_raii(last_sequence, seq);

  FILL_MACRO_CHILREN(me.children(), mts, fts)
  SequenceNode *before = ProcessMacroChildren(
      nullptr, me_bounds, std::move(mts), std::move(fts),
      trailing_tokens);

  assert(depth == prev_depth);

  if (!before) {
    return seq;
  }

  SequenceNode *after = nullptr;
  last_sequence = &dummy_sequence;
  Token prev_rc;

  for (const BodyTokenForChild &node : mep.ReplacementChildren()) {
    depth = next_depth;

    const size_t old_size = after ? after->children.size() : 0u;

    // Try to inject whitespace/comments before things like parameter uses.
    if (after && prev_rc && node.definition_token) {
      TokenIndex prev_rci = GetOrCreateIndex(prev_rc);
      TokenIndex dti = GetOrCreateIndex(node.definition_token);

      if ((prev_rci.second + 1u) < dti.second &&
          prev_rci.first->Equals(dti.first) &&
          prev_rci.first->Equals(def_bounds.reader)) {
        D( std::cerr << INDENT
                     << "ExtendWithNonTreeExpansion: Injecting body tokens\n"; )
        after = AddLeadingTokensInBounds(after, dti, node.definition_token.id(),
                                         prev_rci, def_bounds);
      }
    }

    if (after && node.definition_token && old_size == after->children.size()) {
      after = AddLeadingTokensBeforeParam(
          after, GetOrCreateIndex(node.definition_token), def_bounds);
    }

    after = AddLeadingTokensInBounds(after, node.definition_token, def_bounds);
    if (node.param_sub) {
      after = ExtendWithMacroChild(after, node.mt, me_bounds,
                                   dummy_trailing_tokens);
    } else {
      after = ExtendWithMacroChild(after, node.mt, def_bounds,
                                   dummy_trailing_tokens);
    }

    depth = prev_depth;
    prev_rc = node.RightCornerOfUseFromBody();
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(me));
  sub->before = before;
  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub, dummy_trailing_tokens);
}

// Extend with a macro expansion. The work here is in figuring out whether or
// not we're in a "non-tree" case.
TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithExpansion(
    SequenceNode *seq, const MacroExpansion &me,
    const Bounds &user_bounds, const TrailingTokens &trailing_tokens) {

  std::optional<Bounds> def_bounds;
  std::optional<DefineMacroDirective> def = me.definition();
  if (!def) {
    return ExtendWithSubstitution(seq, me, user_bounds, trailing_tokens);
  }

  def_bounds = MacroBodyBounds(def.value());
  if (!def_bounds) {
    return ExtendWithSubstitution(seq, me, user_bounds, trailing_tokens);
  }

  // If there isn't a trailing expansion, then that is fine.
  std::optional<MacroExpansion> te = TrailingExpansionInExpansion(me);
  if (!te) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value(), trailing_tokens);
  }

  auto dte = NonTreeTailExpansion(def.value(), me, te.value());
  if (!dte) {
    return ExtendWithSimpleExpansion(seq, me, def.value(), user_bounds,
                                     def_bounds.value(), trailing_tokens);
  }

  return ExtendWithNonTreeExpansion(
      seq, me, user_bounds, def.value(), def_bounds.value(), dte.value(),
      trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithSubstitution(
    SequenceNode *seq, const MacroSubstitution &macro,
    const Bounds &use_bounds, const TrailingTokens &trailing_tokens) {

  Bounds bounds = use_bounds;

  auto prev_depth = depth;
  auto next_depth = depth + 1;

  SaveRestoreLastSequence seq_raii(last_sequence, seq);

  FILL_MACRO_CHILREN(macro.children(), mts, fts)

  std::optional<IncludeLikeMacroDirective> include_dir;
  if (mts.size() == 1u && std::holds_alternative<Macro>(mts.front())) {
    include_dir = IncludeLikeMacroDirective::from(std::get<Macro>(mts.front()));
  }

  SequenceNode *before = ProcessMacroChildren(
      nullptr, bounds, std::move(mts), std::move(fts), trailing_tokens);

  if (!before) {
    return seq;
  }

  SubstitutionNode *sub = &(substitutions.emplace_back(macro));
  sub->before = before;

  TokenIndex lft;

  if (include_dir) {
    if (auto file = include_dir->included_file()) {
      D( std::cerr << INDENT << "Changing file; old bounds=" << BOUNDS(bounds); )
      auto tokens = file->tokens();
      lft = GetOrCreateIndex(tokens.back());
      bounds.reader = lft.first;
      bounds.begin_index = 0u;
      bounds.end_index = lft.second;
      D( std::cerr << "; new bounds=" << BOUNDS(bounds) << '\n'; )
    }
  }

  SequenceNode *after = nullptr;
  last_sequence = &dummy_sequence;
  for (MacroOrToken mt : macro.replacement_children()) {
    depth = include_dir ? 0u : next_depth;
    after = ExtendWithMacroChild(after, mt, bounds, dummy_trailing_tokens);
    depth = prev_depth;
  }

  // Make sure to capture the end of the included file.
  if (include_dir) {
    lft.second += 1u;  // Beyond the last token.
    after = AddLeadingTokensInBounds(
        after, lft, lft.first->NthFileTokenId(lft.second - 1u), bounds);
  }

  if (after) {
    sub->after = after;
  }

  return AddToSequence(seq, sub, dummy_trailing_tokens);
}

TokenTreeImpl::SequenceNode *TokenTreeImpl::ExtendWithMacro(
    SequenceNode *seq, const Macro &macro, const Bounds &bounds,
    const TrailingTokens &trailing_tokens) {

  // It's possible that this macro is from a floating fragment, e.g. an
  // `#endif`. Go and pull it in as a fragment token tree, rather than
  // integrating it manually.
  if (macro.id().Unpack().fragment_id != fragment->fragment_id) {
    auto frag = Fragment::containing(macro);
    if (auto file_toks = frag.file_tokens()) {

      auto first_file_tok = file_toks.front();
      D( auto fft_index = GetOrCreateIndex(first_file_tok);
         std::cerr << INDENT << "ExtendWithMacro: bounds=" << BOUNDS(bounds)
                   << " fft_index=" << TOKEN_INDEX(fft_index) << '\n'; )

      // Mark us as being at the top level.
      auto prev_depth = depth;
      depth = 0;
      seq = AddLeadingTokensInBounds(seq, first_file_tok, bounds);
      depth = prev_depth;

      D( std::cerr << INDENT << "\tDone prefixing fragment\n"; )

      TokenTree frag_tree = TokenTree::create(frag);

      TokenTreeImpl::Node frag_node = *NodeFromPublic(frag_tree.root());
      nested_trees.emplace_back(ImplFromPublic(std::move(frag_tree)));

      auto alt = &(choices.emplace_back());
      alt->fragments.emplace_back(std::move(frag));
      alt->children.emplace_back(std::move(frag_node));
      alt->first_file_token.emplace_back(first_file_tok.id().Pack());
      return AddNodeToSequence(seq, alt, dummy_trailing_tokens);
    }
  }

  if (auto ms = MacroSubstitution::from(macro)) {
    if (auto me = MacroExpansion::from(macro)) {
      seq = ExtendWithExpansion(seq, me.value(), bounds, trailing_tokens);
    } else {
      seq = ExtendWithSubstitution(seq, ms.value(), bounds, trailing_tokens);
    }

  } else {
    seq = ExtendWithMacroChildren(seq, macro, bounds, trailing_tokens);
  }

  return seq;
}

// Create a node for a fragment. If the fragment has file tokens, then the
// returned node will "expand" out to include the file tokens.
TokenTreeImpl::Node TokenTreeImpl::CreateFragmentNode(
    const Fragment &entity, const Bounds &bounds) {

  FILL_MACRO_CHILREN(entity.preprocessed_code(), mts, fts)
  SequenceNode *seq = ProcessMacroChildren(
      nullptr, bounds, std::move(mts), std::move(fts),
      dummy_trailing_tokens);

  if (!seq) {
    return {};
  }

  return seq;
}

namespace {

// Returns `true` if this looks like a floating macro directive.
//
// NOTE(pag): Must be kept in sync with `ShouldGoInFloatingFragment` in
//            `bin/Index/Util.*`
static bool IsFloatingDirectiveFragment(const Fragment &frag) {
  auto num_directives = 0u;
  for (MacroOrToken &mt : frag.preprocessed_code()) {
    if (!std::holds_alternative<Macro>(mt)) {
      return false;
    }

    auto dir = MacroDirective::from(std::get<Macro>(mt));
    if (!dir) {
      return false;
    }

    switch (dir->kind()) {
      case MacroKind::INCLUDE_DIRECTIVE:
      case MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case MacroKind::IMPORT_DIRECTIVE:
        return false;
      default:
        ++num_directives;
        continue;
    }
  }

  return num_directives == 1u;
}

struct FillerContext {
  std::unordered_map<RawEntityId, TokenTreeImpl::ChoiceNode *> file_frags;
  std::unordered_map<RawEntityId, RawEntityId> frag_begin;
  std::unordered_map<RawEntityId, RawEntityId> frag_end;
  std::unordered_map<RawEntityId, RawEntityId> last_frag;

  void CollectFragment(TokenTreeImpl *impl, Fragment frag);

  TokenTreeImpl::SequenceNode *FillFileRange(
      TokenTreeImpl *impl, const TokenRange &all_file_toks,
      TokenRange sub_file_toks, int depth);
};

// Collect a fragment into the context. This tries to keep track of the
// bounds of overlapping fragments, and collect overlapping fragments into
// alternations, as represented by `ChoiceNode`s.
void FillerContext::CollectFragment(TokenTreeImpl *impl, Fragment frag) {
  TokenRange file_toks = frag.file_tokens();
  if (file_toks.empty()) {
    return;
  }

  RawEntityId first_file_tok_id = file_toks.front().id().Pack();
  RawEntityId last_file_tok_id = file_toks.back().id().Pack();

#ifndef NDEBUG
  VariantId first_file_tok_vid = EntityId(first_file_tok_id).Unpack();
  VariantId last_file_tok_vid = EntityId(last_file_tok_id).Unpack();
  assert(std::holds_alternative<FileTokenId>(first_file_tok_vid));
  assert(std::holds_alternative<FileTokenId>(last_file_tok_vid));
  assert(std::get<FileTokenId>(first_file_tok_vid).file_id ==
         std::get<FileTokenId>(last_file_tok_vid).file_id);
  assert(std::get<FileTokenId>(first_file_tok_vid).offset <=
         std::get<FileTokenId>(last_file_tok_vid).offset);
#endif

  // Create an independent tree for the fragment, and reference it directly.
  TokenTree frag_tree = TokenTree::create(frag);
  TokenTreeImpl::Node frag_node = *impl->NodeFromPublic(frag_tree.root());

  // Steal the nested tree.
  impl->nested_trees.emplace_back(impl->ImplFromPublic(std::move(frag_tree)));

  TokenTreeImpl::ChoiceNode *&alt = file_frags[last_file_tok_id];
  if (!alt) {
    alt = &(impl->choices.emplace_back());
    frag_begin.emplace(last_file_tok_id, first_file_tok_id);
    frag_end.emplace(first_file_tok_id, last_file_tok_id);
  }

  alt->fragments.emplace_back(std::move(frag));
  alt->children.emplace_back(std::move(frag_node));
  alt->first_file_token.emplace_back(first_file_tok_id);

  // Keep track of the minimum/maximum beginning file token id. In the case
  // of something like:
  //
  //      #if ...
  //      static
  //      #endif
  //      void func(...) { ... }
  //
  // We have two or more fragments sharing the same end location, but
  // having different begin locations. We also have floating fragments for
  // the directives, which may also share the same beginning/ending
  // locations.
  auto &min_first_file_tok_id = frag_begin[last_file_tok_id];
  min_first_file_tok_id = std::min(first_file_tok_id, min_first_file_tok_id);

  auto &max_last_file_tok_id = frag_end[first_file_tok_id];
  max_last_file_tok_id = std::max(last_file_tok_id, max_last_file_tok_id);
}

TokenTreeImpl::SequenceNode *FillerContext::FillFileRange(
    TokenTreeImpl *impl, const TokenRange &all_file_toks,
    TokenRange sub_file_toks, int depth) {

  (void) depth;

  TokenTreeImpl::SequenceNode *seq = nullptr;
  std::optional<RawEntityId> stop_skip_after;

  auto is_first = true;

  // Combine the file tokens and alternations of the fragment tokens.
  for (Token file_tok : sub_file_toks) {
    const RawEntityId file_tok_id = file_tok.id().Pack();
    D( std::cerr << depth << "\tAT FILE TOKEN: " << file_tok_id << " "
                 << file_tok.data() << '\n'; )

    // We're inside a fragment, so skip file tokens.
    if (stop_skip_after) {
      auto skip_stop_file_tok_id = stop_skip_after.value();
      D( std::cerr << "\t\tSTOP SKIP AFTER: " << skip_stop_file_tok_id << '\n';)

      // We might have floating fragments inside of some larger fragments. Go
      // and double check that they are indeed floating.
      if (skip_stop_file_tok_id > file_tok_id) {
#ifndef NDEBUG
        auto frag_it = file_frags.find(file_tok_id);
        if (frag_it != file_frags.end()) {
          for (const Fragment &frag : frag_it->second->fragments) {
            assert(IsFloatingDirectiveFragment(frag));
          }
        }
#endif

      // We've hit the end of our outermost fragment.
      } else if (skip_stop_file_tok_id == file_tok_id) {
        stop_skip_after.reset();
        
      } else {
        assert(false);
      }
      continue;
    }

    // This file token doesn't correspond to the beginning of any fragment, so
    // add it to a top-level sequence.
    auto end_it = frag_end.find(file_tok_id);
    if (end_it == frag_end.end()) {
      D( std::cerr << "\t\tADDING TO SEQ: " << file_tok_id << '\n'; )
      seq = impl->AddTokenToSequence(
          seq, file_tok, impl->dummy_trailing_tokens);
      continue;
    }

    D( std::cerr << "\t\tFRAGMENT BEGINS AT: " << file_tok_id << " ENDS AT "
                 << end_it->second << '\n'; )

    // We've just got to the beginning of a fragmnet. Compute the end location
    // of the fragment, then look up the fragment by its end location.
    auto max_last_file_tok_id = end_it->second;
    assert(frag_begin[max_last_file_tok_id] == file_tok_id);

    auto frag_it = file_frags.find(max_last_file_tok_id);
    if (frag_it == file_frags.end()) {
      assert(false);
      continue;
    }

    // Don't add `stop_skip_after` if this fragment is represented by a
    // single file token, e.g. the `__BEGIN_DECLS` macro in libc.
    if (file_tok_id != max_last_file_tok_id) {
      stop_skip_after.emplace(max_last_file_tok_id);
    }

    // This file token corresponds to a choice among one or more
    // overlapping fragments. Add the fragment to the top-level sequence.
    TokenTreeImpl::ChoiceNode *frag_node = frag_it->second;
    assert(frag_node != nullptr);

    seq = impl->AddToSequence(seq, frag_node, impl->dummy_trailing_tokens);

    // Detect if we need to prefix the tokens of one or more of the fragment
    // variants.
    auto i = 0u;
    for (auto frag_fft : frag_node->first_file_token) {
      auto &node = frag_node->children[i++];
      if (frag_fft == file_tok_id) {
        continue;
      }

      auto begin_id = EntityId(file_tok_id).Extract<FileTokenId>();
      auto end_id = EntityId(frag_fft).Extract<FileTokenId>();
      if (!begin_id || !end_id || begin_id->file_id != end_id->file_id ||
          begin_id->offset >= end_id->offset) {
        assert(false);
        continue;
      }

      // Prevent infinite recursion.
      D( std::cerr << depth << "\t\t{Erasing " << file_tok_id << '\n'; )
      frag_end.erase(file_tok_id);

      TokenTreeImpl::SequenceNode *prefix_seq = FillFileRange(
          impl, all_file_toks,
          all_file_toks.slice(begin_id->offset, end_id->offset),
          depth + 1);

      // Restore for another sub-fragment.
      frag_end.emplace(file_tok_id, max_last_file_tok_id);
      
      D( std::cerr << depth << "\t\t}Adding " << file_tok_id << '\n'; )

      if (prefix_seq) {
        node = impl->AddNodeToSequence(
            prefix_seq, node, impl->dummy_trailing_tokens);
      }
    }
  }

  if (!seq) {
    return {};
  }

  assert(!stop_skip_after.has_value());

  return seq;
}

}  // namespace

// Create a node for a file. If there are overlapping fragments in this file,
// then this will include them.
TokenTreeImpl::Node TokenTreeImpl::CreateFileNode(const File &entity) {

  FillerContext context;

  // Collect all overlapping fragments into alternations.
  std::vector<Fragment> floating_frags;
  for (Fragment frag : entity.fragments()) {
    if (IsFloatingDirectiveFragment(frag)) {
      floating_frags.emplace_back(std::move(frag));
    } else {
      context.CollectFragment(this, std::move(frag));
    }
  }

  // Process floating fragments last. We want our "bigger", i.e. normal
  // fragments to show up in the `ChoiceNode`s first, rather than floating
  // fragments.
  for (Fragment &frag : floating_frags) {
    context.CollectFragment(this, std::move(frag));
  }

  auto file_toks = entity.tokens();
  return context.FillFileRange(this, file_toks, file_toks, 0);
}

// Return `true` if the input substitution should be expanded or not.
bool TokenTreeVisitor::should_expand(const MacroSubstitution &) const {
  return false;
}

// Choose which fragment to show.
Fragment TokenTreeVisitor::choose(const std::vector<Fragment> &frags) const {
  return frags.front();
}

static std::shared_ptr<TokenReader> CreateWhitespaceReader(void) {
  auto reader = std::make_shared<CustomTokenReader>(FragmentImplPtr{});
  reader->Append({TokenKind::WHITESPACE, TokenCategory::WHITESPACE,
                  " ", NotAnEntity{}});
  return reader;
}

static const std::shared_ptr<TokenTreeImpl> kInvalidTree =
    std::make_shared<TokenTreeImpl>();

static const std::shared_ptr<TokenReader> kWhitespaceReader =
    CreateWhitespaceReader();

TokenTree::TokenTree(void)
    : TokenTree(kInvalidTree) {}

// Returns `false` if this is an empty, default-initialized token tree.
TokenTree::operator bool(void) const noexcept {
  return impl != kInvalidTree;
}

TokenTree TokenTree::create(const File &file) {
  auto self = file.impl->cached_token_tree.Get();
  if (self) {
    return TokenTree(std::move(self));
  }

  self = std::make_shared<TokenTreeImpl>();
  auto file_tokens = file.tokens();
  self->file = file.impl;
  self->root = self->CreateFileNode(file);

  return TokenTree(file.impl->cached_token_tree.Put(std::move(self)));
}

TokenTree TokenTree::create(const Fragment &frag) {
  auto self = frag.impl->cached_token_tree.Get();
  if (self) {
    return TokenTree(std::move(self));
  }

  self = std::make_shared<TokenTreeImpl>();
  self->fragment = frag.impl;

  if (auto opt_file = File::containing(frag)) {
    self->file = opt_file->impl;
  }

  TokenTreeImpl::Bounds frag_bounds = self->FragmentBounds(frag.file_tokens());
  D( std::cerr << "FRAGMENT{id=" << frag.id().Pack() << ' ' << BOUNDS(frag_bounds) << '\n'; )

  self->root = self->CreateFragmentNode(frag, frag_bounds);

  D( std::cerr << "}FRAGMENT id=" << frag.id().Pack() << ' ' << BOUNDS(frag_bounds) << '\n'; )

  return TokenTree(frag.impl->cached_token_tree.Put(std::move(self)));
}

// Create a "flat" token tree for a token range.
TokenTree TokenTree::create(const TokenRange &range) {
  if (!range) {
    return TokenTree();
  }

  auto self = std::make_shared<TokenTreeImpl>();

  TokenTreeImpl::SequenceNode *seq = nullptr;
  for (auto tok : range) {
    seq = self->AddTokenToSequence(seq, self->GetOrCreateIndex(tok));
  }

  self->root = seq;
  return TokenTree(std::move(self));
}

TokenTree TokenTree::create(std::vector<CustomTokenTreeNode> elems) {
  if (elems.empty()) {
    return TokenTree();
  }

  auto self = std::make_shared<TokenTreeImpl>();
  TokenTreeImpl::SequenceNode *seq = nullptr;
  for (auto elem : elems) {
    if (std::holds_alternative<TokenRange>(elem)) {
      for (auto tok : std::get<TokenRange>(elem)) {
        seq = self->AddTokenToSequence(seq, self->GetOrCreateIndex(tok));
      }
    } else {
      auto &node = std::get<TokenTreeNode>(elem);
      self->nested_trees.emplace_back(node.impl);
      seq = self->AddNodeToSequence(
          seq, *reinterpret_cast<const TokenTreeImpl::Node *>(node.opaque_node),
          self->dummy_trailing_tokens);
    }
  }

  self->root = seq;
  return TokenTree(std::move(self));
}

namespace {

// Used to read tokens from the token tree.
class TokenTreeReader final : public TokenReader {
 public:
  const std::shared_ptr<TokenTreeImpl> impl;
  std::vector<TokenTreeImpl::TokenIndex> tokens;

  // Offset of the first byte of data from the Nth token. This has one extra
  // element at the end that contains the size of `data`.
  std::vector<EntityOffset> token_offset;

  // A single string representing the serialized token tree token data.
  std::string data;

  std::uint64_t data_hash{0u};

  // Capture the sequence of choices made by a token tree visitor.
  std::vector<RawEntityId> visitor_choices;

  // State for whitespace injection.
  bool add_leading_ws{false};
  bool is_first{true};
  TokenKind last_tk{TokenKind::UNKNOWN};

  virtual ~TokenTreeReader(void) noexcept = default;

  inline TokenTreeReader(std::shared_ptr<TokenTreeImpl> impl_)
      : impl(std::move(impl_)) {}

  void Append(TokenTreeImpl::TokenIndex ti);

  const FragmentImpl *OwningFragment(void) const noexcept override {
    return impl->fragment.get();
  }

  const FileImpl *OwningFile(void) const noexcept override {
    return impl->file.get();
  }

  const FragmentImpl *NthOwningFragment(EntityOffset ti) const noexcept override {
    if (ti >= tokens.size()) {
      return OwningFragment();
    }
    auto [reader, to] = tokens[ti];
    return reader->NthOwningFragment(to);
  }

  const FileImpl *NthOwningFile(EntityOffset ti) const noexcept override {
    if (ti >= tokens.size()) {
      return OwningFile();
    }
    auto [reader, to] = tokens[ti];
    return reader->NthOwningFile(to);
  }

  // Return the number of tokens accessible to this reader.
  EntityOffset NumTokens(void) const override {
    return static_cast<EntityOffset>(tokens.size());
  }

  // Return the kind of the Nth token.
  TokenKind NthTokenKind(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return TokenKind::UNKNOWN;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthTokenKind(to);
  }

  // Return the data of the Nth token.
  std::string_view NthTokenData(EntityOffset ti) const override {
    if ((ti + 1u) >= token_offset.size()) {
      return {};
    }
    EntityOffset bo = token_offset[ti];
    EntityOffset eo = token_offset[ti + 1u];
    auto len = eo - bo;
    return std::string_view(data).substr(bo, len);
  }

  // Return the id of the token from which the Nth token is derived.
  EntityId NthDerivedTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthDerivedTokenId(to);
  }

  // Return the id of the parsed token which is derived from the Nth token.
  EntityId NthParsedTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthParsedTokenId(to);
  }

  // Return the id of the macro containing the Nth token.
  EntityId NthContainingMacroId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthContainingMacroId(to);
  }

  // Return an entity id associated with the Nth token.
  EntityId NthRelatedEntityId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthRelatedEntityId(to);
  }

  // Return the entity associated with the Nth token.
  VariantEntity NthRelatedEntity(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return NotAnEntity{};
    }
    auto [reader, to] = tokens[ti];
    return reader->NthRelatedEntity(to);
  }

  // Return the id of the Nth token.
  EntityId NthTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthTokenId(to);
  }

  EntityId NthFileTokenId(EntityOffset ti) const override {
    if (ti >= tokens.size()) {
      return mx::kInvalidEntityId;
    }
    auto [reader, to] = tokens[ti];
    return reader->NthFileTokenId(to);
  }

  // Returns `true` if `this` is logically equivalent to `that`.
  bool Equals(const TokenReader *that_) const override {
    if (this == that_) {
      return true;
    }

    auto that = dynamic_cast<const TokenTreeReader *>(that_);
    if (!that) {
      return false;
    }

    // Different data is being shown, easy to count as different.
    if (data_hash != that->data_hash ||
        tokens.size() != that->tokens.size()) {
      return false;
    }

    if (impl != that->impl) {

      // Not configured to look at the same high-level entities.
      if (impl->file != that->impl->file ||
          impl->fragment != that->impl->fragment ||
          impl->nested_readers.size() != that->impl->nested_readers.size() ||
          impl->nested_trees.size() != that->impl->nested_trees.size()) {
        return false;
      }
    }

    // Compare the choices made by the two visitors.
    return tokens.size() == that->tokens.size() &&
           visitor_choices == that->visitor_choices;
  }
};

void TokenTreeReader::Append(TokenTreeImpl::TokenIndex ti) {

  auto [tok_reader, to] = ti;

  TokenKind tk = tok_reader->NthTokenKind(to);
  VariantId rel_id = tok_reader->NthRelatedEntityId(to).Unpack();
  bool is_include_tok = std::holds_alternative<FileId>(rel_id);
  if (std::holds_alternative<MacroId>(rel_id)) {
    switch (std::get<MacroId>(rel_id).kind) {
      case MacroKind::INCLUDE_DIRECTIVE:
      case MacroKind::INCLUDE_NEXT_DIRECTIVE:
      case MacroKind::INCLUDE_MACROS_DIRECTIVE:
      case MacroKind::IMPORT_DIRECTIVE:
        is_include_tok = true;
        break;
      default:
        break;
    }
  }

  if (last_tk == TokenKind::WHITESPACE && tk == TokenKind::WHITESPACE &&
      !is_include_tok) {
    TokenTreeImpl::TokenIndex last_ti = tokens.back();
    if ((last_ti.second + 1u) != to || !last_ti.first->Equals(tok_reader)) {
      return;  // Don't add two whitespaces side-by-side.
    }
  }

  const bool will_be_first = IsFirst(tk);
  if (!add_leading_ws && !is_include_tok) {
    add_leading_ws = ForceLeadingWhitespace(is_first, last_tk, tk,
                                            will_be_first);
  }

  if (add_leading_ws && is_first && will_be_first) {
    add_leading_ws = false;  // E.g. `};`.
  }

  EntityOffset data_size = static_cast<EntityOffset>(data.size());

  // Force inject whitespace between two tokens.
  if (add_leading_ws || (!is_first && AddLeadingWhitespace(tk))) {
    if (!is_include_tok && !SuppressLeadingWhitespace(tk)) {
      tokens.emplace_back(kWhitespaceReader.get(), 0u);
      data.push_back(' ');
      token_offset.emplace_back(data_size++);
    }
  }

  // Copy in the token data.
  std::string_view tok_data = tok_reader->NthTokenData(to);
  if (!tok_data.empty()) {
    data.insert(data.end(), tok_data.begin(), tok_data.end());
  }

  tokens.emplace_back(ti);
  token_offset.emplace_back(static_cast<EntityOffset>(data.size()));

  // Update state tracking for whitespace injection.
  last_tk = tk;
  if (is_first) {
    add_leading_ws = AddTrailingWhitespaceAsFirst(tk);
  } else {
    add_leading_ws = AddTrailingWhitespace(tk);
  }
  is_first = will_be_first;
}

static void CollectTokens(const TokenTreeImpl::Node &node,
                          const TokenTreeVisitor &vis,
                          TokenTreeReader &reader) {
  if (std::holds_alternative<std::monostate>(node)) {
    return;

  } else if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
    reader.Append(std::get<TokenTreeImpl::TokenIndex>(node));

  } else if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    if (TokenTreeImpl::ChoiceNode *choice =
            std::get<TokenTreeImpl::ChoiceNode *>(node)) {
      PackedFragmentId chosen_frag = vis.choose(choice->fragments).id();
      reader.visitor_choices.emplace_back(chosen_frag.Pack());

      auto i = 0u;
      for (const Fragment &frag : choice->fragments) {
        if (chosen_frag == frag.id()) {
          const TokenTreeImpl::Node &frag_node = choice->children[i];
          CollectTokens(frag_node, vis, reader);
        }
        ++i;
      }
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (TokenTreeImpl::SubstitutionNode *sub =
            std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      auto should_expand = false;
      RawEntityId choice_id = kInvalidEntityId;
      if (std::holds_alternative<MacroSubstitution>(sub->macro)) {
        const MacroSubstitution &msub = std::get<MacroSubstitution>(sub->macro);
        should_expand = vis.should_expand(msub);
        choice_id = msub.id().Pack();
      } else {
        assert(false);
      }

      if (should_expand) {
        reader.visitor_choices.emplace_back(choice_id);
      }
      if (should_expand) {
        CollectTokens(sub->after, vis, reader);
      } else {
        CollectTokens(sub->before, vis, reader);
      }
    }
  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (TokenTreeImpl::SequenceNode *seq =
            std::get<TokenTreeImpl::SequenceNode *>(node)) {
      for (const TokenTreeImpl::Node &sub_node : seq->children) {
        CollectTokens(sub_node, vis, reader);
      }
    }
  } else {
    assert(false);
  }
}

static void StreamTokData(std::ostream &os, std::string_view tok) {
  for (auto ch : tok) {
    switch (ch) {
      case '<': os << "&lt;"; break;
      case '>': os << "&gt;"; break;
      case '"': os << "&quot;"; break;
      case '\'': os << "&apos;"; break;
      case '\r': os << " "; break;
      case '\n': os << " "; break;
      case '&': os << "&amp;"; break;
      case '\\': os << '|'; break;
      default: os << ch; break;
    }
  }
}

}  // namespace

// Serialize the token tree into a linear range.
TokenRange TokenTree::serialize(const TokenTreeVisitor &vis) const {
  auto reader = std::make_shared<TokenTreeReader>(impl);
  reader->token_offset.push_back(0u);
  CollectTokens(impl->root, vis, *reader);

  EntityOffset num_tokens = static_cast<EntityOffset>(reader->tokens.size());
  reader->data_hash = kHasher(reader->data);
  return TokenRange(std::move(reader), 0u, num_tokens);
}

namespace {

static void DumpChoice(std::ostream &os, const TokenTreeImpl::ChoiceNode &node,
                       std::unordered_set<uintptr_t> &seen);

static void DumpSubstitution(
    std::ostream &os, const TokenTreeImpl::SubstitutionNode &node,
                       std::unordered_set<uintptr_t> &seen);

static void DumpSequence(
    std::ostream &os, const TokenTreeImpl::SequenceNode &node,
    std::unordered_set<uintptr_t> &seen);

static void DumpNode(
    std::ostream &os, const TokenTreeImpl::Node &node,
    std::unordered_set<uintptr_t> &seen) {

  if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    if (TokenTreeImpl::ChoiceNode *choice =
            std::get<TokenTreeImpl::ChoiceNode *>(node)) {
      DumpChoice(os, *choice, seen);
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (TokenTreeImpl::SubstitutionNode *sub =
            std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      DumpSubstitution(os, *sub, seen);
    }
  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (TokenTreeImpl::SequenceNode *seq =
            std::get<TokenTreeImpl::SequenceNode *>(node)) {
      DumpSequence(os, *seq, seen);
    }
  }
}

static void DumpLink(std::ostream &ss, uintptr_t s_id, unsigned i,
                     const TokenTreeImpl::Node &node,
                     std::unordered_set<uintptr_t> &seen) {
  if (std::holds_alternative<std::monostate>(node)) {
    return;

  } else if (std::holds_alternative<TokenTreeImpl::TokenIndex>(node)) {
    return;
  }

  DumpNode(ss, node, seen);

  if (std::holds_alternative<TokenTreeImpl::ChoiceNode *>(node)) {
    if (TokenTreeImpl::ChoiceNode *choice =
            std::get<TokenTreeImpl::ChoiceNode *>(node)) {
      auto d_id = reinterpret_cast<uintptr_t>(choice);
      ss << "n" << s_id << ":c" << i << " -> n" << d_id << ";\n";
    }
  } else if (std::holds_alternative<TokenTreeImpl::SubstitutionNode *>(node)) {
    if (TokenTreeImpl::SubstitutionNode *sub =
            std::get<TokenTreeImpl::SubstitutionNode *>(node)) {
      auto d_id = reinterpret_cast<uintptr_t>(sub);
      ss << "n" << s_id << ":c" << i << " -> n" << d_id << ";\n";
    }
  } else if (std::holds_alternative<TokenTreeImpl::SequenceNode *>(node)) {
    if (TokenTreeImpl::SequenceNode *seq =
            std::get<TokenTreeImpl::SequenceNode *>(node)) {
      auto d_id = reinterpret_cast<uintptr_t>(seq);
      ss << "n" << s_id << ":c" << i << " -> n" << d_id << ";\n";
    }
  } else {
    assert(false);
  }
}

void DumpChoice(std::ostream &os, const TokenTreeImpl::ChoiceNode &node,
                std::unordered_set<uintptr_t> &seen) {
  auto id = reinterpret_cast<uintptr_t>(&node);
  if (!seen.emplace(id).second) {
    return;
  }

  os << "n" << id
     << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"azure2\"><TR>";

  auto i = 0u;
  for (const TokenTreeImpl::Node &child : node.children) {
    (void) child;
    os << "<TD port=\"c" << i << "\">" << node.fragments[i].id().Pack() << "</TD>";
    ++i;
  }
  os << "</TR></TABLE>>];\n";

  i = 0u;
  for (const TokenTreeImpl::Node &child : node.children) {
    DumpLink(os, id, i++, child, seen);
  }
}

void DumpSubstitution(std::ostream &os,
                      const TokenTreeImpl::SubstitutionNode &node,
                      std::unordered_set<uintptr_t> &seen) {
  auto id = reinterpret_cast<uintptr_t>(&node);
  if (!seen.emplace(id).second) {
    return;
  }

  EntityId eid;
  if (std::holds_alternative<MacroSubstitution>(node.macro)) {
    eid = std::get<MacroSubstitution>(node.macro).id();
  } else if (std::holds_alternative<MacroVAOpt>(node.macro)) {
    eid = std::get<MacroVAOpt>(node.macro).id();
  } else {
    assert(false);
  }

  os << "n" << id
     << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"beige\"><TR>"
     << "<TD colspan=\"2\">" << eid.Pack() << "</TD></TR><TR>"
     << "<TD port=\"c0\">before</TD>"
     << "<TD port=\"c1\">after</TD>"
     << "</TR></TABLE>>];\n";

  DumpLink(os, id, 0, node.before, seen);
  DumpLink(os, id, 1, node.after, seen);
}

void DumpSequence(std::ostream &os, const TokenTreeImpl::SequenceNode &node,
                  std::unordered_set<uintptr_t> &seen) {
  auto id = reinterpret_cast<uintptr_t>(&node);
  if (!seen.emplace(id).second) {
    return;
  }

  os << "n" << id
     << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\" bgcolor=\"goldenrod\"><TR>";

  auto i = 0u;
  for (const TokenTreeImpl::Node &child : node.children) {
    if (std::holds_alternative<TokenTreeImpl::TokenIndex>(child)) {
      auto [reader, to] = std::get<TokenTreeImpl::TokenIndex>(child);
      os << "<TD>";
      StreamTokData(os, reader->NthTokenData(to));
      os << "</TD>";
    } else {
      os << "<TD port=\"c" << i << "\"> </TD>";
      ++i;
    }
  }
  os << "</TR></TABLE>>];\n";

  i = 0u;
  for (const TokenTreeImpl::Node &child : node.children) {
    if (!std::holds_alternative<TokenTreeImpl::TokenIndex>(child)) {
      DumpLink(os, id, i++, child, seen);
    }
  }
}

}  // namespace

// Dump the token tree into a DOT digraph.
void TokenTree::dump(std::ostream &os) {
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  std::unordered_set<uintptr_t> seen;
  DumpNode(os, impl->root, seen);

  os << "}\n";
}

const char *EnumeratorName(TokenTreeNodeKind kind) {
  switch (kind) {
    case TokenTreeNodeKind::EMPTY: return "EMPTY";
    case TokenTreeNodeKind::TOKEN: return "TOKEN";
    case TokenTreeNodeKind::CHOICE: return "CHOICE";
    case TokenTreeNodeKind::SUBSTITUTION: return "SUBSTITUTION";
    case TokenTreeNodeKind::SEQUENCE: return "SEQUENCE";
    default: return "<invalid>";
  }
}

#define MX_MAKE_TT_FROM(class_) \
    std::optional<class_> class_::from(const TokenTreeNode &that) { \
      if (that.kind() == class_::static_kind()) { \
        return reinterpret_cast<const class_ &>(that); \
      } \
      return std::nullopt; \
    }

MX_MAKE_TT_FROM(EmptyTokenTreeNode)
MX_MAKE_TT_FROM(TokenTokenTreeNode)
MX_MAKE_TT_FROM(ChoiceTokenTreeNode)
MX_MAKE_TT_FROM(SubstitutionTokenTreeNode)
MX_MAKE_TT_FROM(SequenceTokenTreeNode)

#undef MX_MAKE_TT_FROM

uintptr_t hash_code(const TokenTreeNode &ttn) noexcept {
  return reinterpret_cast<uintptr_t>(ttn.opaque_node);
}

// Get the root token tree node.
TokenTreeNode TokenTree::root(void) const noexcept {
  return TokenTreeNode(impl, &(impl->root));
}

namespace {

template <typename T>
static const T *TryExtract(const void *opaque_node) {
  auto node = reinterpret_cast<const TokenTreeImpl::Node *>(opaque_node);
  return node ? std::get_if<T>(node) : nullptr;
}

}  // namespace

std::shared_ptr<TokenTreeImpl> TokenTreeImpl::ImplFromPublic(TokenTree tree) {
  return std::move(tree.impl);
}

const TokenTreeImpl::Node *TokenTreeImpl::NodeFromPublic(TokenTreeNode node) {
  return reinterpret_cast<const TokenTreeImpl::Node *>(node.opaque_node);
}

// Return the kind of this token tree node.
TokenTreeNodeKind TokenTreeNode::kind(void) const noexcept {
  auto node = reinterpret_cast<const TokenTreeImpl::Node *>(opaque_node);
  return static_cast<TokenTreeNodeKind>(node->index());
}

Token TokenTokenTreeNode::token(void) const noexcept {
  auto index = TryExtract<TokenTreeImpl::TokenIndex>(opaque_node);
  auto [reader, to] = *index;
  return Token(TokenReaderPtr(impl, reader), to);
}

gap::generator<std::pair<Fragment, TokenTreeNode>>
ChoiceTokenTreeNode::children(void) const & noexcept {
  auto choice_ptr = TryExtract<TokenTreeImpl::ChoiceNode *>(opaque_node);
  if (!choice_ptr) {
    assert(false);
    co_return;
  }

  const auto &choice = **choice_ptr;
  auto num_children = choice.children.size();
  for (auto i = 0ull; i < num_children; ++i) {
    auto child = &(choice.children[i]);
    co_yield {choice.fragments[i], TokenTreeNode(impl, child)};
  }
}

std::variant<MacroSubstitution, MacroVAOpt>
SubstitutionTokenTreeNode::macro(void) const noexcept {
  auto sub_ptr = TryExtract<TokenTreeImpl::SubstitutionNode *>(opaque_node);
  return (*sub_ptr)->macro;
}

TokenTreeNode SubstitutionTokenTreeNode::before(void) const noexcept {
  auto sub_ptr = TryExtract<TokenTreeImpl::SubstitutionNode *>(opaque_node);
  return TokenTreeNode(impl, &((*sub_ptr)->before));
}

TokenTreeNode SubstitutionTokenTreeNode::after(void) const noexcept {
  auto sub_ptr = TryExtract<TokenTreeImpl::SubstitutionNode *>(opaque_node);
  return TokenTreeNode(impl, &((*sub_ptr)->after));
}

gap::generator<TokenTreeNode>
SequenceTokenTreeNode::children(void) const & noexcept {
  auto seq_ptr = TryExtract<TokenTreeImpl::SequenceNode *>(opaque_node);
  if (!seq_ptr) {
    assert(false);
    co_return;
  }

  const auto &seq = **seq_ptr;
  for (const auto &child_node : seq.children) {
    co_yield TokenTreeNode(impl, &child_node);
  }
}

}  // namespace mx
