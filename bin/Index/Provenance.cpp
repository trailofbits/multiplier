// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Provenance.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <clang/Basic/TokenKinds.h>
#include <clang/AST/TemplateBase.h>
#include <clang/AST/TemplateName.h>
#include <clang/AST/Type.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <multiplier/AST/StmtKind.h>
#include <multiplier/Frontend/TokenKind.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <variant>

#include "PASTA.h"
#include "PendingFragment.h"
#include "TokenTree.h"
#include "Util.h"

namespace indexer {
namespace {

static bool Update(mx::RawEntityId *val, mx::RawEntityId new_val,
                   bool changed) {
  if (*val != new_val) {
    *val = new_val;
    return true;
  }
  return changed;
}

static bool IsDefinableToken(pasta::TokenKind kind) {
  auto clang_kind = static_cast<clang::tok::TokenKind>(kind);
  switch (clang_kind) {
    default:
      if (clang::tok::getKeywordSpelling(clang_kind)) {
        return true;
      } else {
        return false;
      }
    case clang::tok::identifier:
    case clang::tok::raw_identifier:
      return true;
  }
}

// Figure out of a given token kind could plausibly be part of a specific
// overloaded operator kind.
static bool AcceptOOK(pasta::OverloadedOperatorKind ook, pasta::TokenKind tk) {
  switch (tk) {
    case pasta::TokenKind::kKeywordOperator:
      return ook != pasta::OverloadedOperatorKind::kNone;
    case pasta::TokenKind::kLSquare:
    case pasta::TokenKind::kRSquare:
      return ook == pasta::OverloadedOperatorKind::kArrayNew ||
             ook == pasta::OverloadedOperatorKind::kArrayDelete ||
             ook == pasta::OverloadedOperatorKind::kSubscript;
    case pasta::TokenKind::kLParenthesis:
    case pasta::TokenKind::kRParenthesis:
      return ook == pasta::OverloadedOperatorKind::kCall;
    case pasta::TokenKind::kKeywordNew:
      return ook == pasta::OverloadedOperatorKind::kNew ||
             ook == pasta::OverloadedOperatorKind::kArrayNew;
    case pasta::TokenKind::kKeywordDelete:
      return ook == pasta::OverloadedOperatorKind::kDelete ||
             ook == pasta::OverloadedOperatorKind::kArrayDelete;
    case pasta::TokenKind::kPlus:
      return ook == pasta::OverloadedOperatorKind::kPlus;
    case pasta::TokenKind::kMinus:
      return ook == pasta::OverloadedOperatorKind::kMinus;
    case pasta::TokenKind::kStar:
      return ook == pasta::OverloadedOperatorKind::kStar;
    case pasta::TokenKind::kSlash:
      return ook == pasta::OverloadedOperatorKind::kSlash;
    case pasta::TokenKind::kPercent:
      return ook == pasta::OverloadedOperatorKind::kPercent;
    case pasta::TokenKind::kCaret:
      return ook == pasta::OverloadedOperatorKind::kCaret;
    case pasta::TokenKind::kAmp:
      return ook == pasta::OverloadedOperatorKind::kAmp;
    case pasta::TokenKind::kPipe:
      return ook == pasta::OverloadedOperatorKind::kPipe;
    case pasta::TokenKind::kTilde:
      return ook == pasta::OverloadedOperatorKind::kTilde;
    case pasta::TokenKind::kExclaim:
      return ook == pasta::OverloadedOperatorKind::kExclaim;
    case pasta::TokenKind::kEqual:
      return ook == pasta::OverloadedOperatorKind::kEqual;
    case pasta::TokenKind::kLess:
      return ook == pasta::OverloadedOperatorKind::kLess;
    case pasta::TokenKind::kGreater:
      return ook == pasta::OverloadedOperatorKind::kGreater;
    case pasta::TokenKind::kPlusEqual:
      return ook == pasta::OverloadedOperatorKind::kPlusEqual;
    case pasta::TokenKind::kMinusEqual:
      return ook == pasta::OverloadedOperatorKind::kMinusEqual;
    case pasta::TokenKind::kStarEqual:
      return ook == pasta::OverloadedOperatorKind::kStarEqual;
    case pasta::TokenKind::kSlashEqual:
      return ook == pasta::OverloadedOperatorKind::kSlashEqual;
    case pasta::TokenKind::kPercentEqual:
      return ook == pasta::OverloadedOperatorKind::kPercentEqual;
    case pasta::TokenKind::kCaretEqual:
      return ook == pasta::OverloadedOperatorKind::kCaretEqual;
    case pasta::TokenKind::kAmpEqual:
      return ook == pasta::OverloadedOperatorKind::kAmpEqual;
    case pasta::TokenKind::kPipeEqual:
      return ook == pasta::OverloadedOperatorKind::kPipeEqual;
    case pasta::TokenKind::kLessLess:
      return ook == pasta::OverloadedOperatorKind::kLessLess;
    case pasta::TokenKind::kGreaterGreater:
      return ook == pasta::OverloadedOperatorKind::kGreaterGreater;
    case pasta::TokenKind::kLessLessEqual:
      return ook == pasta::OverloadedOperatorKind::kLessLessEqual;
    case pasta::TokenKind::kGreaterGreaterEqual:
      return ook == pasta::OverloadedOperatorKind::kGreaterGreaterEqual;
    case pasta::TokenKind::kEqualEqual:
      return ook == pasta::OverloadedOperatorKind::kEqualEqual;
    case pasta::TokenKind::kExclaimEqual:
      return ook == pasta::OverloadedOperatorKind::kExclaimEqual;
    case pasta::TokenKind::kLessEqual:
      return ook == pasta::OverloadedOperatorKind::kLessEqual;
    case pasta::TokenKind::kGreaterEqual:
      return ook == pasta::OverloadedOperatorKind::kGreaterEqual;
    case pasta::TokenKind::kSpaceship:
      return ook == pasta::OverloadedOperatorKind::kSpaceship;
    case pasta::TokenKind::kAmpAmp:
      return ook == pasta::OverloadedOperatorKind::kAmpAmp;
    case pasta::TokenKind::kPipePipe:
      return ook == pasta::OverloadedOperatorKind::kPipePipe;
    case pasta::TokenKind::kPlusPlus:
      return ook == pasta::OverloadedOperatorKind::kPlusPlus;
    case pasta::TokenKind::kMinusMinus:
      return ook == pasta::OverloadedOperatorKind::kMinusMinus;
    case pasta::TokenKind::kComma:
      return ook == pasta::OverloadedOperatorKind::kComma;
    case pasta::TokenKind::kArrowStar:
      return ook == pasta::OverloadedOperatorKind::kArrowStar;
    case pasta::TokenKind::kArrow:
      return ook == pasta::OverloadedOperatorKind::kArrow;
    case pasta::TokenKind::kQuestion:
    case pasta::TokenKind::kColon:
      return ook == pasta::OverloadedOperatorKind::kConditional;
    case pasta::TokenKind::kKeywordCoAwait:
      return ook == pasta::OverloadedOperatorKind::kCoawait;
    default:
      return false;
  }
}

static mx::RawEntityId VisitType(
    const EntityMapper &em, const pasta::Type &type, std::string_view tok_data,
    int context_depth);

// Visit the `stmt` and try to make `raw_token` or the token data in it.
// Depending on the quality of information we have, we might go for exact
// matches (against `raw_token`), or in-name-only matches, e.g. the field is
// called `foo` and the data of the token is also `foo`.
static mx::RawEntityId VisitStmt(const EntityMapper &em,
                                 const pasta::Stmt &stmt,
                                 const void *raw_token,
                                 std::string_view token_data,
                                 pasta::TokenKind token_kind,
                                 bool is_identifier) {

  auto check_token = [=] (const pasta::Token &et) {
    if (raw_token) {
      return RawEntity(et) == raw_token;
    } else {
      return et.Data() == token_data;
    }
  };

  const auto raw_stmt = em.EntityId(stmt);

  // Try to match the named declaration referenced by a `DeclRefExpr`.
  if (auto dre = pasta::DeclRefExpr::From(stmt)) {
    auto decl = dre->Declaration();
    if (is_identifier) {

      if (auto nd = pasta::NamedDecl::From(decl)) {
        if (nd->Name() == token_data) {
          return em.EntityId(nd.value());
        }

        // Common case for C code.
        if (check_token(dre->ExpressionToken())) {
          return em.EntityId(nd.value());
        }

        // Sometimes the expression token is waaaay off, e.g. in the
        // `tests/Cxx/NoExceptSplitTokenTest.cpp` test case, the expression
        // token for `__and_<....>::value` is `__and_`. In this case, we use
        // the end token.
        if (check_token(dre->EndToken())) {
          return em.EntityId(nd.value());
        }

        // For C++ code, something like `B::name<...>` where `B` is the
        // `ExpressionToken`, `>` is the `EndToken`, `<` is the `LAngeToken`,
        // and `name` is the token previous to the `LAngleToken`.
        if (auto before_l_angle = dre->LAngleToken().PreviousLocation()) {
          if (check_token(before_l_angle.value())) {
            return em.EntityId(nd.value());
          }
        }
      }
    }

    // TODO(pag): Use `std::ispunct` on `token_data[0]`?
    if (auto meth = pasta::CXXMethodDecl::From(decl)) {
      if (AcceptOOK(meth->OverloadedOperator(), token_kind)) {
        return em.EntityId(meth.value());
      }
    }

  // Try to match on `member` in `base->member` or `base.member`.
  } else if (auto me = pasta::MemberExpr::From(stmt)) {
    if (token_kind == pasta::TokenKind::kPeriod ||
        token_kind == pasta::TokenKind::kArrow) {
      if (check_token(me->OperatorToken())) {
        return raw_stmt;
      }
      return mx::kInvalidEntityId;
    }

    if (!is_identifier) {
      return mx::kInvalidEntityId;
    }

    pasta::ValueDecl md = me->MemberDeclaration();

    // With a `CxxMemberCallExpr` to an overloaded operator, we might see the
    // full spelling, e.g. `operator<<`, which is two tokens: `operator` and
    // `<<`.
    if (auto func = pasta::FunctionDecl::From(md)) {
      auto ook = func->OverloadedOperator();
      if (AcceptOOK(ook, token_kind)) {
        return em.EntityId(md);
      }
    }

    if (check_token(me->MemberToken())) {
      return em.EntityId(md);
    }

    // Failing this, try to match on `base` in `base->member` or `base.member`.
    return VisitStmt(em, me->Base(), raw_token, token_data, token_kind,
                     is_identifier);

  // Something like `__c11_atomic_load(...)` of an `_Atomic`-qualified variable.
  } else if (auto atomic = pasta::AtomicExpr::From(stmt)) {
    if (is_identifier) {
      if (token_data == atomic->BuiltinToken().Data()) {
        return raw_stmt;
      }
    } else if (token_kind == pasta::TokenKind::kRParenthesis ||
               token_kind == pasta::TokenKind::kLParenthesis) {
      auto r_paren = atomic->RParenToken();
      if (r_paren.Kind() == pasta::TokenKind::kRParenthesis) {
        if (check_token(r_paren)) {
          return raw_stmt;
        }

        if (auto l_paren = r_paren.BalancedLocation()) {
          if (check_token(l_paren.value())) {
            return raw_stmt;
          }
        }
      }
    }

  // The label name in an `asm goto`.
  } else if (auto addr = pasta::AddrLabelExpr::From(stmt)) {
    if (check_token(addr->LabelToken())) {
      return em.EntityId(addr->Label());
    }

  } else if (auto ce = pasta::CXXConstructExpr::From(stmt)) {
    pasta::CXXConstructorDecl cd = ce->Constructor();
    if (check_token(ce->Token())) {
      return em.EntityId(cd);
    }

  // Try to match on `label` in `goto label;`.
  } else if (auto gt = pasta::GotoStmt::From(stmt)) {
    if (check_token(gt->LabelToken())) {
      return em.EntityId(gt->Label());
    }

  // Try to match on `member` in `{ .member = ... }`.
  } else if (auto di = pasta::DesignatedInitExpr::From(stmt)) {
    for (pasta::Designator de : di->Designators()) {
      if (auto f = de.Field()) {
        if (check_token(de.FieldToken())) {
          return em.EntityId(f.value());
        }
      }
    }

  } else if (auto ili = pasta::InitListExpr::From(stmt)) {
    if (token_kind == pasta::TokenKind::kLBrace) {
      if (check_token(ili->BeginToken())) {
        return raw_stmt;
      }
    } else if (token_kind == pasta::TokenKind::kRBrace) {
      if (check_token(ili->EndToken())) {
        return raw_stmt;
      }
    }

  // Try to match on `label` in `label:`.
  } else if (auto ls = pasta::LabelStmt::From(stmt)) {
    if (check_token(ls->IdentifierToken())) {
      return em.EntityId(ls->Declaration());
    }

  } else if (auto pde = pasta::PredefinedExpr::From(stmt)) {
    if (is_identifier && check_token(pde->ExpressionToken())) {
      return raw_stmt;
    }

  // Try to match on `func`, `(`, or `)` in `func()`.
  } else if (auto call = pasta::CallExpr::From(stmt)) {
    if (auto oc = pasta::CXXOperatorCallExpr::From(stmt)) {
      // Try to match the operator token itself, or the `operator` keyword.
      if (AcceptOOK(oc->Operator(), token_kind) || token_data == "operator") {
        return em.EntityId(call->CalleeDeclaration());
      }
    }

    if (token_kind != pasta::TokenKind::kLParenthesis &&
        token_kind != pasta::TokenKind::kRParenthesis) {
      return VisitStmt(em, call->Callee(), raw_token, token_data, token_kind,
                       is_identifier);
    }

    // Try to match the `)` in `func()`.
    auto r_paren = call->RParenToken();
    if (r_paren.Kind() != pasta::TokenKind::kRParenthesis) {
      return mx::kInvalidEntityId;
    }

    if (token_kind == pasta::TokenKind::kRParenthesis) {
      if (check_token(r_paren)) {
        return raw_stmt;
      }

    } else if (token_kind == pasta::TokenKind::kLParenthesis) {
      auto l_paren = r_paren.BalancedLocation();
      if (!l_paren || l_paren->Kind() != pasta::TokenKind::kLParenthesis) {
        assert(false);
        return mx::kInvalidEntityId;
      }

      if (check_token(l_paren.value())) {
        return raw_stmt;
      }
    }

  } else if (auto fce = pasta::CXXFunctionalCastExpr::From(stmt)) {

    if (is_identifier) {
      return VisitType(em, fce->TypeAsWritten(), token_data, 0u);

    } else if (token_kind == pasta::TokenKind::kLParenthesis) {
      if (check_token(fce->LParenToken())) {
        return raw_stmt;
      }
    } else if (token_kind == pasta::TokenKind::kRParenthesis) {
      if (check_token(fce->RParenToken())) {
        return raw_stmt;
      }
    }

  } else if (auto ece = pasta::ExplicitCastExpr::From(stmt)) {
    if (token_kind != pasta::TokenKind::kLParenthesis &&
        token_kind != pasta::TokenKind::kRParenthesis) {
      return mx::kInvalidEntityId;
    }

    auto begin_tok = ece->BeginToken();
    if (begin_tok.Kind() != pasta::TokenKind::kLParenthesis) {
      return mx::kInvalidEntityId;
    }

    if (token_kind == pasta::TokenKind::kLParenthesis) {
      if (check_token(begin_tok)) {
        return raw_stmt;
      }
    } else if (auto balanced = begin_tok.BalancedLocation()) {
      if (check_token(balanced.value())) {
        return raw_stmt;
      }
    }

  // Parentheses.
  } else if (auto paren = pasta::ParenExpr::From(stmt)) {
    if (token_kind == pasta::TokenKind::kLParenthesis) {
      if (check_token(paren->BeginToken())) {
        return raw_stmt;
      }
    } else if (token_kind == pasta::TokenKind::kRParenthesis) {
      if (check_token(paren->EndToken())) {
        return raw_stmt;
      }
    }

  } else if (auto sexpr = pasta::StmtExpr::From(stmt)) {
    if (token_kind == pasta::TokenKind::kLParenthesis) {
      if (check_token(sexpr->LParenToken())) {
        return raw_stmt;
      }
    } else if (token_kind == pasta::TokenKind::kRParenthesis) {
      if (check_token(sexpr->RParenToken())) {
        return raw_stmt;
      }
    }

  // TODO(pag): CoroutineBodyStmt.

  // Braces.
  } else if (auto comp = pasta::CompoundStmt::From(stmt)) {
    if (token_kind == pasta::TokenKind::kLBrace) {
      if (check_token(comp->LeftBraceToken())) {
        return raw_stmt;
      }

    } else if (token_kind == pasta::TokenKind::kRBrace) {
      if (check_token(comp->RightBraceToken())) {
        return raw_stmt;
      }
    }

  // // Declaration statement, which might have an assignment.
  // } else if (auto dstmt = pasta::DeclStmt::From(stmt)) {

  // Binary operator.
  } else if (auto binary = pasta::BinaryOperator::From(stmt)) {
    if (check_token(binary->OperatorToken())) {
      return raw_stmt;
    }

  // Unary operator.
  } else if (auto unary = pasta::UnaryOperator::From(stmt)) {
    if (check_token(unary->OperatorToken())) {
      return raw_stmt;
    }
  }

  return mx::kInvalidEntityId;
}

// Try to see if a token matches a declaration. As above, sometimes we have
// the raw parsed token and want an exact match, whereas other times we only
// have token data, and will accept an in-name-only match.
static bool TokenMatchesDecl(
    pasta::TokenKind tk, const void *raw_token, const pasta::Decl &decl,
    std::string_view token_data);

// Try to match some token data against a `clang::TemplateName`.
static mx::RawEntityId VisitTemplateName(
    const EntityMapper &em, const pasta::AST &ast, clang::TemplateName tn,
    std::string_view tok_data) {

  if (auto raw_tpl = tn.getAsTemplateDecl()) {
    auto decl = ast.Adopt(
        reinterpret_cast<const clang::Decl *>(raw_tpl));
    if (TokenMatchesDecl(pasta::TokenKind::kIdentifier, nullptr,
                         decl, tok_data)) {
      return em.EntityId(decl);
    }
  }

  return mx::kInvalidEntityId;
}

// Try to match some token data, e.g. identifier data `foo`, against the name of
// a type, e.g. `foo` in `struct foo`. We don't use raw token pointers here
// because types are usually independent of fragments, and type deduplication
// inside of Clang means that locations embedded in `Type`s (e.g. via `Expr`s)
// can't be relied upon to be related to this specific fragment. In a lot of
// ways, we use PASTA's pretty printer and logic in this and other functions
// to emulate the kinds of information gleaned from `clang::TypeLoc`s. PASTA
// doesn't wrap `clang::TypeLoc`s, though.
mx::RawEntityId VisitType(
    const EntityMapper &em, const pasta::Type &type, std::string_view tok_data,
    int context_depth) {

  if (auto typedef_type = pasta::TypedefType::From(type)) {
    auto typedef_decl = typedef_type->Declaration();
    if (typedef_decl.Name() == tok_data) {
      return em.EntityId(typedef_decl);
    }

  } else if (auto tag_type = pasta::TagType::From(type)) {
    auto tag_decl = tag_type->Declaration();
    if (TokenMatchesDecl(pasta::TokenKind::kIdentifier, nullptr,
                         tag_decl, tok_data)) {
      return em.EntityId(tag_decl);
    }

  } else if (auto spec = pasta::TemplateSpecializationType::From(type)) {
    if (!context_depth && spec->IsSugared()) {
      auto eid = VisitType(em, spec->Desugar(), tok_data, context_depth);
      if (eid != mx::kInvalidEntityId) {
        return eid;
      }
    }

    // This might find a builtin template decl.
    auto raw_type = clang::dyn_cast<clang::TemplateSpecializationType>(
        spec->RawType());
    return VisitTemplateName(em, pasta::AST::From(type),
                             raw_type->getTemplateName(), tok_data);

  } else if (auto param = pasta::TemplateTypeParmType::From(type)) {

    if (auto decl = param->Declaration()) {
      if (TokenMatchesDecl(pasta::TokenKind::kIdentifier, nullptr,
                           decl.value(), tok_data)) {
        return em.EntityId(decl.value());
      }
    }

    // PASTA's pretty printer ensures that this won't get split up into
    // a bunch of individual tokens.
    if (tok_data.starts_with("type-parameter-")) {
      return em.EntityId(type);
    }

  } else if (auto inj_type = pasta::InjectedClassNameType::From(type)) {
    auto decl = inj_type->Declaration();
    if (TokenMatchesDecl(pasta::TokenKind::kIdentifier, nullptr,
                         decl, tok_data)) {
      return em.EntityId(decl);
    }

    if (!context_depth) {
      auto tst = inj_type->InjectedSpecializationType();
      if (tst != type) {
        return VisitType(em, tst, tok_data, context_depth);
      }
    }

  } else if (auto builtin_type = pasta::BuiltinType::From(type)) {
    if (tok_data.starts_with("__")) {
      if (tok_data.ends_with("_t") ||
          tok_data == "__make_integer_seq" ||
          tok_data == "__type_pack_element") {
        return em.EntityId(type);
      }
    }

  // // Handle issue #344, where parameter names in function type prototypes
  // // don't have related entities.
  // //
  // // XREF: https://github.com/trailofbits/multiplier/issues/344.
  // } else if (auto func_type = pasta::FunctionProtoType::From(type);
  //            func_type && !context_depth) {
  //   return type.RawType();
  } else if (!context_depth) {
    if (auto unqual_type = type.UnqualifiedType(); unqual_type != type) {
      return VisitType(em, unqual_type, tok_data, context_depth);

    } else if (auto elaborated_type = pasta::ElaboratedType::From(type)) {
      return VisitType(em, elaborated_type->NamedType(), tok_data,
                       context_depth);

    } else if (auto deduced_type = pasta::DeducedType::From(type)) {
      if (deduced_type->IsDeduced()) {
        auto resolved_type = deduced_type->ResolvedType();
        if (resolved_type) {
          return VisitType(em, resolved_type.value(), tok_data, context_depth);
        }
      }
    }
  }

  return mx::kInvalidEntityId;
}

static std::optional<pasta::IncludeLikeMacroDirective>
ContainingInclude(const pasta::Macro &macro) {
  if (auto inc = pasta::IncludeLikeMacroDirective::From(macro)) {
    return inc;
  } else if (auto parent = macro.Parent()) {
    return ContainingInclude(parent.value());
  } else {
    return std::nullopt;
  }
}

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityIdToMacroToken(
    const EntityMapper &em, const pasta::MacroToken &mtok,
    bool force=false) {

  // In the good case, we have:
  //
  //     EXP_0
  //     /   \            .
  //   mtok  ...
  //
  // But in the harder cases, we have:
  //
  //         EXP_0
  //         /   \        .
  //      EXP_1  ...
  //      /  \            .
  //    ...  mtok
  //
  // Where `mtok` is the name of the macro expanded for `EXP_0`. Here, we only
  // try to deal with the former case. We rely on the associated macro with
  // the parsed token.
  std::optional<unsigned> child_index;

  auto self = RawEntity(mtok);
  auto parent = mtok.Parent();
  if (!parent) {
    assert(false);
    return mx::kInvalidEntityId;
  }

  // Figure out if we're inside of the expansion side.
  auto index = 0u;
  for (pasta::Macro child : parent->Children()) {
    if (RawEntity(child) == self) {
      child_index.emplace(index);
      break;
    }
    ++index;
  }

  // A definable name must be the first thing inside of the macro.
  pasta::TokenKind tk = mtok.TokenKind();
  bool is_definable_tk = IsDefinableToken(tk);
  bool is_definable_name = child_index.has_value() &&
                           !child_index.value() &&  // First token.
                           is_definable_tk;

  switch (parent->Kind()) {
    case pasta::MacroKind::kToken:
      assert(false);  // Should be impossible.
      parent.reset();
      break;

    case pasta::MacroKind::kExpansion: {
      auto &exp = reinterpret_cast<pasta::MacroExpansion &>(parent.value());

      // If the macro token is the name of the macro definition used, then
      // make the related entity be the defined macro itself.
      if (auto def = exp.Definition(); def && is_definable_name) {
        if (auto name = def->Name(); name && name->Data() == mtok.Data()) {
          if (mx::RawEntityId eid = em.EntityId(def.value());
              eid != mx::kInvalidEntityId) {
            return eid;
          }
        }
      }

      // If it's the first token in an expansion, then reference the expansion
      // instead. Sometimes we have macro expansions but no definitions.
      if (force) {
        if (mx::RawEntityId eid = em.EntityId(exp);
            eid != mx::kInvalidEntityId && is_definable_name) {
          return eid;
        }
      }

      break;
    }

    case pasta::MacroKind::kStringify:
      if (mtok.Data() == "#") {
        if (mx::RawEntityId eid = em.EntityId(parent.value());
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }
      break;

    case pasta::MacroKind::kConcatenate:
      if (mtok.Data() == "##") {
        if (mx::RawEntityId eid = em.EntityId(parent.value());
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }
      break;
    case pasta::MacroKind::kVAOptArgument:
    case pasta::MacroKind::kArgument:
      break;

    // If it's a parameter substitution, and if the token is the parameter
    // name, then mark the token's related entity ID as the parameter itself.
    case pasta::MacroKind::kParameterSubstitution: {
      auto &sub = reinterpret_cast<pasta::MacroParameterSubstitution &>(
          parent.value());
      if (RawEntity(sub.ParameterUse()) == self ||
          mtok.Data() == "__VA_ARGS__") {
        pasta::MacroParameter param = sub.Parameter();
        if (mx::RawEntityId eid = em.EntityId(param);
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }

      break;
    }

    // If the parent is a `__VA_OPT__` substitution, and if the token is the
    // `__VA_OPT__` itself, the connect the token to the substitution.
    case pasta::MacroKind::kVAOpt:
      if (mtok.Data() == "__VA_OPT__") {
        if (mx::RawEntityId eid = em.EntityId(parent.value());
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }
      break;

    // If it's the first token in a substitution, and if the token is an
    // identifier name, then reference the substitution itself.
    case pasta::MacroKind::kSubstitution: {
      if (force) {
        if (mx::RawEntityId eid = em.EntityId(parent.value());
            eid != mx::kInvalidEntityId && is_definable_name) {
          return eid;
        }
      }
      break;
    }

    // If we found an identifier name, or the ellipsis, then use that.
    case pasta::MacroKind::kParameter: {
      if (mx::RawEntityId eid = em.EntityId(parent.value());
          eid != mx::kInvalidEntityId &&
          (is_definable_name || tk == pasta::TokenKind::kEllipsis)) {
        return eid;
      }
      break;
    }

    case pasta::MacroKind::kDefineDirective: {
      if (!is_definable_tk) {
        goto directive_case;
      }

      // Try to match with the macro name itself.
      auto &def =
          reinterpret_cast<pasta::DefineMacroDirective &>(parent.value());
      if (auto name = def.Name(); name && RawEntity(name.value()) == self) {
        if (mx::RawEntityId eid = em.EntityId(def);
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }

      // Try to match with a macro parameter.
      std::string_view mtok_data = mtok.Data();
      bool is_va_args = mtok_data == "__VA_ARGS__";
      for (pasta::Macro p_ : def.Parameters()) {
        const auto &p = reinterpret_cast<const pasta::MacroParameter &>(p_);
        auto matches = false;
        if (auto name = p.Name()) {
          matches = name->Data() == mtok_data;

        } else if (is_va_args) {
          matches = p.VariadicDots().has_value();
        }

        if (matches) {
          if (mx::RawEntityId eid = em.EntityId(p);
              eid != mx::kInvalidEntityId) {
            return eid;
          }
          assert(false);
        }
      }

      goto directive_case;
    }

    // If this is a token in `#pragma` directive derived from a `_Pragma` macro,
    // and if it's not the `#` or the directive name (`pragma`), then link it to
    // the tokens in the argment to the `_Pragma`.
    case pasta::MacroKind::kPragmaDirective:
      if (std::optional<pasta::Macro> pragma_parent = parent->Parent();
          pragma_parent &&
          pragma_parent->Kind() == pasta::MacroKind::kExpansion) {
        auto found_at = 0u;
        for (pasta::Macro pragma_dir_child : parent->Children()) {
          if (RawEntity(pragma_dir_child) == self) {
            break;
          }
          ++found_at;
        }
        if (found_at < 2u) { // Not after `#` and `pragma`.
          goto directive_case;
        }
        for (pasta::Macro ppc : pragma_parent->Children()) {
          if (ppc.Kind() != pasta::MacroKind::kArgument) {
            continue;
          }

          // Assume first argument to `_Pragma` is a token.
          if (std::optional<pasta::MacroToken> str_tok = ppc.BeginToken();
              str_tok &&
              str_tok->TokenKind() == pasta::TokenKind::kStringLiteral) {
            if (mx::RawEntityId eid = em.EntityId(str_tok.value());
                eid != mx::kInvalidEntityId) {
              return eid;
            }
          }

          // Associate the provenance with the argument itself if we failed
          // to find the token (probably a string) in the argument).
          if (mx::RawEntityId eid = em.EntityId(ppc);
              eid != mx::kInvalidEntityId) {
            return eid;
          }
        }
      }
      goto directive_case;

    // Point the macro directive at the macro itself.
    case pasta::MacroKind::kOtherDirective:
    case pasta::MacroKind::kIfDirective:
    case pasta::MacroKind::kIfDefinedDirective:
    case pasta::MacroKind::kIfNotDefinedDirective:
    case pasta::MacroKind::kElseIfDirective:
    case pasta::MacroKind::kElseIfDefinedDirective:
    case pasta::MacroKind::kElseIfNotDefinedDirective:
    case pasta::MacroKind::kElseDirective:
    case pasta::MacroKind::kEndIfDirective:
    case pasta::MacroKind::kIncludeDirective:
    case pasta::MacroKind::kIncludeNextDirective:
    case pasta::MacroKind::kIncludeMacrosDirective:
    case pasta::MacroKind::kImportDirective:
    case pasta::MacroKind::kUndefineDirective:
    directive_case: {
      auto &dir =
          reinterpret_cast<pasta::MacroDirective &>(parent.value());
      if (auto dir_name = dir.DirectiveName();
          dir_name && RawEntity(dir_name.value()) == self) {
        if (mx::RawEntityId eid = em.EntityId(dir);
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }
      break;
    }
  }

  // If it's a header name then we're probably inside of the substitution of
  // sequence of tokens for a header name, and that is inside of an inclusion
  // directive, so we want to point at the included file.
  if (tk == pasta::TokenKind::kHeaderName ||
      tk == pasta::TokenKind::kStringLiteral) {
    if (auto inc = ContainingInclude(parent.value())) {
      if (auto file = inc->IncludedFile()) {
        if (mx::RawEntityId eid = em.EntityId(file.value());
            eid != mx::kInvalidEntityId) {
          return eid;
        }
      }
    }
  }

  if (force) {
    if (auto assoc_macro = mtok.AssociatedMacro()) {
      return em.EntityId(assoc_macro.value());
    }
  }

  return mx::kInvalidEntityId;
}

// If `name` represents the name of a destructor (`is_cxx_destructor`), then
// strip off the leading `~`. When lexing, the leading `~` is a separate token,
// but Clang forms the destructor name with it. When we ask for the location of
// destructor, we get a token pointing to the name token, i.e. the token after
// the `~`, and so we want to compare the token's data against the stripped
// name.
static std::string_view NameWithoutTilde(const std::string &name,
                                         bool is_cxx_destructor) {
  std::string_view stripped_name = name;

  if (is_cxx_destructor && stripped_name.starts_with('~')) {
    stripped_name.remove_prefix(1);
  }

  return stripped_name;
}

// Try to see if a token matches a declaration. As above, sometimes we have
// the raw parsed token and want an exact match, whereas other times we only
// have token data, and will accept an in-name-only match.
bool TokenMatchesDecl(pasta::TokenKind tk, const void *raw_token,
                      const pasta::Decl &decl, std::string_view token_data) {
  if (token_data == "Bar") {
    (void) decl.Token();
  }

  auto is_cxx_destructor = decl.Kind() == pasta::DeclKind::kCXXDestructor;

  if (auto func = pasta::FunctionDecl::From(decl)) {

    // Try to match the operator token itself, or the `operator` keyword.
    auto ook = func->OverloadedOperator();
    if (AcceptOOK(ook, tk)) {
      return true;
    }

    if (ook != pasta::OverloadedOperatorKind::kNone) {
      return false;
    }

    // Match the `~` in a destructor name to the destructor.
    if (tk == pasta::TokenKind::kTilde && is_cxx_destructor) {
      return true;
    }
  }

  if (auto nd = pasta::NamedDecl::From(decl)) {
    auto nd_name = nd->Name();

    // E.g. Issue #439, empty parameter names.
    if (nd_name.empty()) {
      return false;
    }

    if (token_data == NameWithoutTilde(nd_name, is_cxx_destructor)) {
      return true;
    }

    // Template specialization.
    return nd_name.ends_with('>') &&
           token_data.size() < nd_name.size() &&
           nd_name.starts_with(token_data) &&
           nd_name[token_data.size()] == '<';
  }

  if (raw_token && RawEntity(decl.Token()) == raw_token) {
    return true;
  }

  return false;
}

static mx::RawEntityId VisitTemplateArgument(
    const EntityMapper &em, const pasta::TemplateArgument &arg,
    std::string_view tok_data) {

  switch (arg.Kind()) {
    case pasta::TemplateArgumentKind::kType:
      if (auto t = arg.Type()) {
        return VisitType(em, t.value(), tok_data, 0u);
      }
      break;

    case pasta::TemplateArgumentKind::kDeclaration:
      if (auto d = arg.Declaration()) {
        if (TokenMatchesDecl(pasta::TokenKind::kIdentifier, nullptr, d.value(),
                             tok_data)) {
          return em.EntityId(d.value());
        }
      }

      if (auto t = arg.ParameterTypeForDeclaration()) {
        return VisitType(em, t.value(), tok_data, 0u);
      }
      break;

    case pasta::TemplateArgumentKind::kTemplate:
    case pasta::TemplateArgumentKind::kTemplateExpansion: {
      auto raw_arg = reinterpret_cast<const clang::TemplateArgument *>(
          arg.RawTemplateArgument());
      return VisitTemplateName(em, pasta::AST::From(arg),
                               raw_arg->getAsTemplateOrTemplatePattern(),
                               tok_data);
    }

    case pasta::TemplateArgumentKind::kEmpty:
    case pasta::TemplateArgumentKind::kNullPointer:
    case pasta::TemplateArgumentKind::kIntegral:
    case pasta::TemplateArgumentKind::kExpression:
    case pasta::TemplateArgumentKind::kPack:
    case pasta::TemplateArgumentKind::kStructuralValue:
      break;
  }
  return mx::kInvalidEntityId;
}

}  // namespace

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityIdToPrintedToken(
    const EntityMapper &em, const pasta::PrintedToken &printed_tok,
    const std::optional<pasta::Token> &parsed_tok) {

  pasta::TokenKind tk = printed_tok.Kind();
  std::string_view token_data = printed_tok.Data();
  const void *self = nullptr;
  if (parsed_tok) {
    tk = parsed_tok->Kind();
    self = RawEntity(parsed_tok.value());
    token_data = parsed_tok->Data();
  }

  const void *related_entity = nullptr;
  mx::RawEntityId eid = mx::kInvalidEntityId;
  bool is_literal = false;
  bool is_identifier = false;

  switch (mx::FromPasta(tk)) {
    default:
      return eid;

    case mx::TokenKind::NUMERIC_CONSTANT:
    case mx::TokenKind::CHARACTER_CONSTANT:
    case mx::TokenKind::WIDE_CHARACTER_CONSTANT:
    case mx::TokenKind::UTF8_CHARACTER_CONSTANT:
    case mx::TokenKind::UTF16_CHARACTER_CONSTANT:
    case mx::TokenKind::UTF32_CHARACTER_CONSTANT:
    case mx::TokenKind::STRING_LITERAL:
    case mx::TokenKind::WIDE_STRING_LITERAL:
    case mx::TokenKind::UTF8_STRING_LITERAL:
    case mx::TokenKind::UTF16_STRING_LITERAL:
    case mx::TokenKind::UTF32_STRING_LITERAL:
    case mx::TokenKind::KEYWORD___FUNC__:
    case mx::TokenKind::KEYWORD___FUNCTION__:
    case mx::TokenKind::KEYWORD___FUNCDNAME__:
    case mx::TokenKind::KEYWORD___FUNCSIG__:
    case mx::TokenKind::KEYWORD_LFUNCTION__:  // TODO(pag): Fix name.
    case mx::TokenKind::KEYWORD_LFUNCSIG__:  // TODO(pag): Fix name.
      is_literal = true;
      break;

    case mx::TokenKind::L_SQUARE:
    case mx::TokenKind::R_SQUARE:
    case mx::TokenKind::L_PARENTHESIS:
    case mx::TokenKind::R_PARENTHESIS:
    case mx::TokenKind::L_BRACE:
    case mx::TokenKind::R_BRACE:
    case mx::TokenKind::AMP:
    case mx::TokenKind::AMP_AMP:
    case mx::TokenKind::AMP_EQUAL:
    case mx::TokenKind::STAR:
    case mx::TokenKind::STAR_EQUAL:
    case mx::TokenKind::PLUS:
    case mx::TokenKind::PLUS_PLUS:
    case mx::TokenKind::PLUS_EQUAL:
    case mx::TokenKind::MINUS:
    case mx::TokenKind::ARROW:
    case mx::TokenKind::MINUS_MINUS:
    case mx::TokenKind::MINUS_EQUAL:
    case mx::TokenKind::TILDE:
    case mx::TokenKind::EXCLAIM:
    case mx::TokenKind::EXCLAIM_EQUAL:
    case mx::TokenKind::SLASH:
    case mx::TokenKind::SLASH_EQUAL:
    case mx::TokenKind::PERCENT:
    case mx::TokenKind::PERCENT_EQUAL:
    case mx::TokenKind::LESS:
    case mx::TokenKind::LESS_LESS:
    case mx::TokenKind::LESS_EQUAL:
    case mx::TokenKind::LESS_LESS_EQUAL:
    case mx::TokenKind::SPACESHIP:
    case mx::TokenKind::GREATER:
    case mx::TokenKind::GREATER_GREATER:
    case mx::TokenKind::GREATER_EQUAL:
    case mx::TokenKind::GREATER_GREATER_EQUAL:
    case mx::TokenKind::CARET:
    case mx::TokenKind::CARET_EQUAL:
    case mx::TokenKind::PIPE:
    case mx::TokenKind::PIPE_PIPE:
    case mx::TokenKind::PIPE_EQUAL:
    case mx::TokenKind::EQUAL:
    case mx::TokenKind::EQUAL_EQUAL:
    case mx::TokenKind::COMMA:
    case mx::TokenKind::PERIOD_STAR:
    case mx::TokenKind::ARROW_STAR:
    case mx::TokenKind::LESS_LESS_LESS:
    case mx::TokenKind::GREATER_GREATER_GREATER:
    case mx::TokenKind::CARETCARET:
    case mx::TokenKind::KEYWORD_DELETE:
    case mx::TokenKind::KEYWORD_NEW:
    case mx::TokenKind::KEYWORD_OPERATOR:
      break;
    case mx::TokenKind::IDENTIFIER:
      is_identifier = true;
      break;
  }

  int depth = -1;
  for (auto context : TokenContexts(printed_tok)) {
    if (related_entity || eid != mx::kInvalidEntityId) {
      break;
    }

    ++depth;

    switch (context.Kind()) {
      case pasta::TokenContextKind::kStmt:
        if (auto stmt = pasta::Stmt::From(context)) {
          if (is_literal) {
            switch (stmt->Kind()) {
              default: break;
              case pasta::StmtKind::kUserDefinedLiteral:
              case pasta::StmtKind::kCharacterLiteral:
              case pasta::StmtKind::kIntegerLiteral:
              case pasta::StmtKind::kFixedPointLiteral:
              case pasta::StmtKind::kFloatingLiteral:
              case pasta::StmtKind::kStringLiteral:
              case pasta::StmtKind::kPredefinedExpr:
                related_entity = RawEntity(stmt.value());
                break;
            }
          } else {
            auto eid = VisitStmt(em, stmt.value(), self, token_data, tk,
                                 is_identifier);
            if (eid != mx::kInvalidEntityId) {
              return eid;
            }
          }
        }
        break;

      case pasta::TokenContextKind::kType:
        if (is_identifier) {
          auto eid = VisitType(
              em, pasta::Type::From(context).value(), token_data, depth);
          if (eid != mx::kInvalidEntityId) {
            return eid;
          }
        }
        break;

      case pasta::TokenContextKind::kDecl: {
        if (is_literal) {
          break;
        }

        std::optional<pasta::Decl> decl = pasta::Decl::From(context);
        if (!decl) {
          break;
        }

        if (TokenMatchesDecl(tk, self, decl.value(), token_data)) {
          related_entity = RawEntity(decl.value());
        }
        break;
      }

      case pasta::TokenContextKind::kAttr:
        if (auto attr = pasta::Attr::From(context)) {

          if (RawEntity(attr->Token()) == self) {
            eid = em.EntityId(attr.value());
          } else {
            for (pasta::Token tok : attr->Tokens()) {
              if (RawEntity(tok) == self) {
                eid = em.EntityId(attr.value());
                break;
              }
            }
          }
        }
        break;

      case pasta::TokenContextKind::kDesignator:
        if (!is_literal) {
          if (auto d = pasta::Designator::From(context)) {
            if (RawEntity(d->FieldToken()) == self) {
              if (auto field = d->Field()) {
                related_entity = RawEntity(field.value());
              }
            }
          }
        }
        break;

      case pasta::TokenContextKind::kTemplateArgument:
        if (is_identifier) {
          if (auto a = pasta::TemplateArgument::From(context)) {
            auto eid = VisitTemplateArgument(em, a.value(), token_data);
            if (eid != mx::kInvalidEntityId) {
              return eid;
            }
          }
        }
        break;

      default:
        break;
    }
  }

  if (related_entity && eid == mx::kInvalidEntityId) {
    eid = em.EntityId(related_entity);
  }

  return eid;
}

// Go and try to find the entity ID to be used for `Decl::Token`. We might
// not have any return values for that for builtin types/declarations, and
// that prevents a lot of API users (especially the GUI) from using the
// declaration token to render the entity name.
mx::RawEntityId PendingFragment::DeclTokenEntityId(
    const pasta::Decl &decl) const {

  auto decl_id = em.EntityId(decl);

  // If we have a name for this entity, then try to find it.
  if (auto nd = pasta::NamedDecl::From(decl)) {
    auto dt = decl.Token();
    if (!dt.Data().empty() && dt.Data() == nd->Name()) {
      auto loc_tok_id = em.EntityId(dt);
      auto pl = mx::EntityId(loc_tok_id).Extract<mx::ParsedTokenId>();
      if (pl && pl->fragment_id == fragment_index) {
        return loc_tok_id;
      }
    }
  }

  // Otherwise, scan.
  for (pasta::PrintedToken tok : parsed_tokens) {
    auto dt = tok.DerivedLocation();
    auto rel_id = RelatedEntityIdToPrintedToken(em, tok, dt);
    if (decl_id == rel_id) {
      return em.EntityId(tok);
    }
  }

  return mx::kInvalidEntityId;
}

unsigned TokenProvenanceCalculator::TokenInfo::Depth(
    TokenProvenanceCalculator &self) {
  if (depth) {
    return depth;
  }

  depth = ~0u;

  // Make an estimate for our base case. This is also a cycle breaker.
  for (TokenInfo *c : Children(self)) {
    depth = std::min(depth, c->depth - 1u);
  }

  // Next, get a better version via recursion.
  for (TokenInfo *c : Children(self)) {
    depth = std::min(c->Depth(self) - 1u, depth);
  }

  return depth;
}

TokenProvenanceCalculator::TokenInfo *
TokenProvenanceCalculator::TokenInfo::OnlyChild(
    const TokenProvenanceCalculator &self) const noexcept {
  if (!child) {
    return nullptr;
  } else if (child < self.infos.size()) {
    return nullptr;
  } else {
    return reinterpret_cast<TokenInfo *>(child);
  }
}

gap::generator<TokenProvenanceCalculator::TokenInfo *>
TokenProvenanceCalculator::TokenInfo::Children(
    const TokenProvenanceCalculator &self) const & {
  if (!child) {
    co_return;
  } else if (child < self.infos.size()) {
    auto it = self.multiple_children.find(this);
    auto end = self.multiple_children.end();
    if (it != end) {
      for (auto tok : it->second) {
        co_yield tok;
      }
    }
  } else {
    co_yield reinterpret_cast<TokenInfo *>(child);
  }
}

gap::generator<TokenProvenanceCalculator::TokenInfo *>
TokenProvenanceCalculator::TokenInfo::MultipleChildren(
    const TokenProvenanceCalculator &self) const & {
  auto it = self.multiple_children.find(this);
  auto end = self.multiple_children.end();
  if (it != end) {
    for (auto tok : it->second) {
      co_yield tok;
    }
  }
}

bool TokenProvenanceCalculator::TokenInfo::DeriveFrom(
    TokenProvenanceCalculator &self, TokenInfo *new_parent) {

  if (new_parent == &(self.empty.value())) {
    return false;
  }

  if (new_parent == this) {
    return false;
  }

  // Collect the children. We may have more than one child.
  if (!new_parent->child) {
    new_parent->child = reinterpret_cast<uintptr_t>(this);

  } else {
    std::vector<TokenInfo *> &others = self.multiple_children[new_parent];
    if (others.empty()) {
      assert(self.infos.size() < new_parent->child);
      others.push_back(
          reinterpret_cast<TokenInfo *>(new_parent->child));
    }

    others.push_back(this);
    new_parent->child = others.size();
  }
  return true;
}

TokenProvenanceCalculator::TokenProvenanceCalculator(const EntityMapper &em_)
    : em(em_) {
  empty.emplace(mx::kInvalidEntityId, 0u, mx::kInvalidEntityId,
                mx::kInvalidEntityId);
}

TokenProvenanceCalculator::~TokenProvenanceCalculator(void) {}

void TokenProvenanceCalculator::Clear(void) {
  infos.clear();
  info_map.clear();
  expansion_toks.clear();
  multiple_children.clear();
  ordered_tokens.clear();
  parsed_tokens.clear();
  fragment_index = mx::kInvalidEntityId;
}

template <typename T>
bool TokenProvenanceCalculator::TryConnect(TokenInfo *child_info,
                                           const T &dt) {
  auto dt_it = info_map.find(RawEntity(dt));
  if (dt_it == info_map.end()) {
    return false;
  }

  TokenInfo *parent_info = dt_it->second;
  if (!child_info->DeriveFrom(*this, parent_info)) {
    return false;
  }

  child_info->derived_token_id = parent_info->entity_id;
  return true;
}

static void FillExpansionTokens(const pasta::Macro &macro,
                                std::vector<pasta::MacroToken> &toks) {
  if (auto mtok = pasta::MacroToken::From(macro)) {
    toks.emplace_back(std::move(mtok.value()));
  } else if (auto sub = pasta::MacroSubstitution::From(macro)) {
    for (pasta::Macro n : sub->ReplacementChildren()) {
      FillExpansionTokens(n, toks);
    }
  } else {
    for (pasta::Macro n : macro.Children()) {
      FillExpansionTokens(n, toks);
    }
  }
}

// Connect `info`, corresponding to `mtok`, to other `TokenInfo`s from which it
// is derived. By default, we try to follow the direct derivation link, i.e.
// `info->derived_token_id`. However, there are more subtle cases, such as a
// number being derived from `__COUNTER__`, or an identifier being derived from
// token concatenations.
bool TokenProvenanceCalculator::BackupConnectToDerived(
    TokenInfo *info, const pasta::MacroToken &mtok) {

  std::optional<pasta::Macro> parent = mtok.Parent();
  if (!parent) {
    assert(false);
    return false;
  }

  // If this token is derived from the body of a macro, and we failed to
  // connect it above, then that generally means the current fragment is
  // not the macro definition itself.
  auto parent_kind = parent->Kind();
  if (parent_kind == pasta::MacroKind::kDefineDirective ||
      parent_kind == pasta::MacroKind::kParameterSubstitution) {
    return false;
  }

  auto sub = pasta::MacroSubstitution::From(parent.value());
  if (!sub) {
    return false;
  }

  const void *self = RawEntity(mtok);

  // Don't connect us into intermediate body tokens.
  if (parent_kind == pasta::MacroKind::kExpansion) {
    auto &exp = reinterpret_cast<pasta::MacroExpansion &>(parent.value());
    for (pasta::Macro n : exp.IntermediateChildren()) {
      if (RawEntity(n) == self) {
        return false;
      }
    }
  }

  // We want to connect expansion tokens back to expansions of the use tokens,
  // so don't connect anything if we're actually looking at a use token.
  expansion_toks.clear();
  for (pasta::Macro n : parent->Children()) {
    if (RawEntity(n) == self) {
      return false;
    }

    FillExpansionTokens(n, expansion_toks);
  }

#ifndef NDEBUG
  // We want to connect expansion tokens back to use tokens, so don't connect
  // anything if we're actually looking at a use token.
  for (const pasta::MacroToken &n : expansion_toks) {
    assert(RawEntity(n) != self);
  }
#endif

  for (const pasta::MacroToken &n : expansion_toks) {
    switch (n.TokenKind()) {
      case pasta::TokenKind::kHash:
      case pasta::TokenKind::kHashHash:
      case pasta::TokenKind::kHashAt:
      case pasta::TokenKind::kUnknown:
        continue;
      default:
        if (TryConnect(info, n)) {
          return true;
        }
        break;
    }
  }

  return false;
}

// Order token `a` before token `b` if:
//
//    1) `a` is a parsed token and `b` isn't.
//    2) if both `a` and `b` are parsed tokens, then if the offset of `a` is
//       less than `b`, then `a` first.
//    3) if neither is a parsed token, and the depth of `a` is greater than
//       the depth of `b`.
static bool SortTokens(TokenProvenanceCalculator::TokenInfo *a,
                       TokenProvenanceCalculator::TokenInfo *b) {
  if (a == b) {
    return false;
  }

  mx::VariantId a_vid = mx::EntityId(a->entity_id).Unpack();
  mx::VariantId b_vid = mx::EntityId(b->entity_id).Unpack();

  auto a_is_parsed = std::holds_alternative<mx::ParsedTokenId>(a_vid);
  auto b_is_parsed = std::holds_alternative<mx::ParsedTokenId>(b_vid);

  if (a_is_parsed && !b_is_parsed) {
    return true;

  } else if (!a_is_parsed && b_is_parsed) {
    return false;

  } else if (!a_is_parsed && !b_is_parsed) {
    return a->depth > b->depth;

  } else {
    return std::get<mx::ParsedTokenId>(a_vid).offset <
           std::get<mx::ParsedTokenId>(b_vid).offset;
  }
}

void TokenProvenanceCalculator::Sort(void) {
  for (TokenInfo *tok : ordered_tokens) {
    (void) tok->Depth(*this);
  }

  std::stable_sort(ordered_tokens.begin(), ordered_tokens.end(), SortTokens);

  for (auto &info_children : multiple_children) {
    std::vector<TokenInfo *> &children = info_children.second;
    std::stable_sort(children.begin(), children.end(), SortTokens);
  }
}

// Out-of-fragment scores higher than in-fragment.
// Decls score higher than macros score higher than statements.
static int Score(mx::RawEntityId fragment_index, mx::EntityId eid) {
  mx::VariantId vid = eid.Unpack();

  int score = 0;

  if (std::holds_alternative<mx::DeclId>(vid)) {
    if (std::get<mx::DeclId>(vid).fragment_id != fragment_index) {
      score += 1;
    }
    score += 40;

  } else if (std::holds_alternative<mx::MacroId>(vid)) {
    if (std::get<mx::MacroId>(vid).fragment_id != fragment_index) {
      score += 1;
    }
    switch (std::get<mx::MacroId>(vid).kind) {
      case mx::MacroKind::DEFINE_DIRECTIVE:
        score += 3;
        break;
      case mx::MacroKind::EXPANSION:
        score += 2;
        break;
      default:
        break;
    }
    score += 30;

  } else if (std::holds_alternative<mx::StmtId>(vid)) {
    if (std::get<mx::StmtId>(vid).fragment_id != fragment_index) {
      score += 2;
    }

    // Often times, e.g. with `assert`-like macros, the input will be
    // stringified, and we'd rather associate input tokens (especially
    // punctuation) with teh statements themselves rather than the string
    // literal.
    switch (std::get<mx::StmtId>(vid).kind) {
      case mx::StmtKind::STRING_LITERAL:
        break;

      // We might have things that are strong signals of declarations.
      case mx::StmtKind::DECL_REF_EXPR:
      case mx::StmtKind::MEMBER_EXPR:
      case mx::StmtKind::ADDR_LABEL_EXPR:
      case mx::StmtKind::GOTO_STMT:
      case mx::StmtKind::LABEL_STMT:
      case mx::StmtKind::DESIGNATED_INIT_EXPR:
      case mx::StmtKind::PREDEFINED_EXPR:
        score += 15;
        break;
      default:
        score += 1;
        break;
    }

    score += 20;

  } else if (!std::holds_alternative<mx::InvalidId>(vid)) {
    score += 10;
  }

  return score;
}

// Pull information from children into a node.
bool TokenProvenanceCalculator::Pull(void) {
  bool changed = false;
  for (TokenInfo *tok : ordered_tokens) {
    if (tok->parsed_token_id != mx::kInvalidEntityId) {
      continue;
    }

    if (tok->related_entity_id != mx::kInvalidEntityId) {
      continue;
    }

    // No children.
    if (!tok->child) {
      continue;
    }

    // One child.
    if (auto only_child = tok->OnlyChild(*this)) {
      changed = Update(&(tok->parsed_token_id),
                       only_child->parsed_token_id, changed);
      changed = Update(&(tok->related_entity_id),
                       only_child->related_entity_id, changed);
      continue;
    }

    // Multiple children; score them for the sake of propagation.

    TokenInfo *matching_parsed = nullptr;
    TokenInfo *matching_rel = nullptr;
    TokenInfo *other_parsed = nullptr;
    TokenInfo *other_rel = nullptr;

    int matching_parsed_score = -1;
    int matching_rel_score = -1;
    int other_parsed_score = -1;
    int other_rel_score = -1;

    for (TokenInfo *derived_tok : tok->MultipleChildren(*this)) {
      auto score = Score(fragment_index, derived_tok->related_entity_id);

      if (tok->data_hash == derived_tok->data_hash) {
        if (derived_tok->parsed_token_id != mx::kInvalidEntityId) {
          if (score > matching_parsed_score) {
            matching_parsed = derived_tok;
            matching_parsed_score = score;
          }
        }

        if (derived_tok->related_entity_id != mx::kInvalidEntityId) {
          if (score > matching_rel_score) {
            matching_rel = derived_tok;
            matching_rel_score = score;
          }
        }
      } else {
        if (derived_tok->parsed_token_id != mx::kInvalidEntityId) {
          if (score > other_parsed_score) {
            other_parsed = derived_tok;
            other_parsed_score = score;
          }
        }

        if (derived_tok->related_entity_id != mx::kInvalidEntityId) {
          if (score > other_rel_score) {
            other_rel = derived_tok;
            other_rel_score = score;
          }
        }
      }
    }

    if (matching_parsed) {
      tok->parsed_token_id = matching_parsed->parsed_token_id;
      tok->related_entity_id = matching_parsed->related_entity_id;
      matching_parsed->derived_token_id = tok->entity_id;
      changed = true;
      continue;
    }

    if (other_parsed) {
      tok->parsed_token_id = other_parsed->parsed_token_id;
      tok->related_entity_id = other_parsed->related_entity_id;
      other_parsed->derived_token_id = tok->entity_id;
      changed = true;
      continue;
    }

    if (matching_rel) {
      assert(matching_rel->parsed_token_id == mx::kInvalidEntityId);
      tok->related_entity_id = matching_rel->related_entity_id;
      changed = true;
      continue;
    }

    if (other_rel) {
      assert(other_rel->parsed_token_id == mx::kInvalidEntityId);
      tok->related_entity_id = other_rel->related_entity_id;
      changed = true;
      continue;
    }
  }

  return changed;
}

void TokenProvenanceCalculator::FallbackInitMacroProvenance(
    const std::vector<TokenTreeNode> &tokens) {

  // Try to force in some extra macro connections. If we do these too early
  // then we'll miss opportunities to connect things to their parsed tokens.
  for (const TokenTreeNode &node : tokens) {
    TokenInfo *info = info_map[RawEntity(node)];
    if (info->related_entity_id != mx::kInvalidEntityId) {
      continue;
    }

    auto ml = node.MacroToken();
    if (!ml) {
      if (auto pl = node.Token()) {
        ml = pl->MacroLocation();
      }
    }

    // NOTE(pag): The `force` option exists to say: if this macro token looks
    //            like the name of a defined macro, the use that defined macro
    //            if all else fails.
    if (ml) {
      info->related_entity_id =
          RelatedEntityIdToMacroToken(em, ml.value(), true  /* force */);
    }
  }
}

// Push information from originating tokens down to derived tokens.
bool TokenProvenanceCalculator::Push(void) {
  auto it = ordered_tokens.rbegin();
  auto it_end = ordered_tokens.rend();
  auto changed = false;

  for (; it != it_end; ++it) {
    TokenInfo *tok = *it;

    const auto parsed_id = tok->parsed_token_id;
    if (parsed_id == mx::kInvalidEntityId || !tok->child) {
      continue;
    }

    auto rel_id = tok->related_entity_id;

    for (TokenInfo *derived_tok : tok->Children(*this)) {
      if (derived_tok->parsed_token_id != mx::kInvalidEntityId ||
          derived_tok->related_entity_id != mx::kInvalidEntityId) {
        continue;
      }

      derived_tok->parsed_token_id = parsed_id;
      derived_tok->related_entity_id = rel_id;
      changed = true;
    }
  }

  return changed;
}


// Push information from originating tokens down to derived tokens.
bool TokenProvenanceCalculator::FinalPush(void) {
  auto it = ordered_tokens.rbegin();
  auto it_end = ordered_tokens.rend();
  auto changed = false;

  for (; it != it_end; ++it) {
    TokenInfo *tok = *it;

    // We would have pushed this in `Push()`.
    if (tok->parsed_token_id != mx::kInvalidEntityId) {
      continue;
    }

    const auto rel_id = tok->related_entity_id;
    if (rel_id == mx::kInvalidEntityId || !tok->child) {
      continue;
    }

    for (TokenInfo *derived_tok : tok->Children(*this)) {
      if (derived_tok->related_entity_id != mx::kInvalidEntityId) {
        continue;
      }

      derived_tok->related_entity_id = rel_id;
      changed = true;
    }
  }

  return changed;
}

// Try to connect the macro token resulting from a token paste to the original
// tokens that were pasted.
void TokenProvenanceCalculator::TryConnectToConcatenatedTokens(
    TokenInfo *child, const pasta::MacroToken &mt, const pasta::Macro &parent) {
  if (parent.Kind() != pasta::MacroKind::kConcatenate) {
    return;
  }

  auto concat = reinterpret_cast<const pasta::MacroConcatenate &>(parent);
  if (concat.PastedToken() != mt) {
    return;
  }

  for (auto lhs : concat.Children()) {
    if (lhs.Kind() != pasta::MacroKind::kToken) {
      assert(false);
      continue;
    }

    const auto &lhs_tok = reinterpret_cast<const pasta::MacroToken &>(lhs);

    auto parent_it = info_map.find(RawEntity(lhs_tok));
    if (parent_it == info_map.end()) {
      continue;
    }

    if (parent_it->second->entity_id == child->derived_token_id) {
      continue;
    }

    if (!child->DeriveFrom(*this, parent_it->second)) {
      continue;
    }

    if (child->derived_token_id == mx::kInvalidEntityId) {
      child->derived_token_id = parent_it->second->entity_id;
    }
  }
}

// This is the version containing all token tree nodes. `tokens` is generally
// already in the order we want it to be in, but we can't guarantee this long
// term, so we implement a sorting procedure.
void TokenProvenanceCalculator::Run(
    mx::RawEntityId fragment_index_, const std::vector<TokenTreeNode> &tokens) {

  fragment_index = fragment_index_;

  // Collect all of our tokens.
  for (const TokenTreeNode &node : tokens) {

    std::optional<pasta::Token> pl = node.Token();
    std::optional<pasta::PrintedToken> cl = node.PrintedToken();
    std::optional<pasta::MacroToken> ml = node.MacroToken();

    const mx::RawEntityId tok_id = em.EntityId(node);
    assert(tok_id != mx::kInvalidEntityId);

    uint64_t data_hash = 0u;

    if (!pl && cl) {
      pl = cl->DerivedLocation();
    }

    if (pl && !ml) {
      ml = pl->MacroLocation();
    }

    mx::RawEntityId parsed_id = mx::kInvalidEntityId;
    mx::RawEntityId rel_id = mx::kInvalidEntityId;
    if (cl) {
      parsed_id = em.EntityId(cl.value());
      if (auto it = parsed_tokens.find(RawEntity(cl.value()));
          it != parsed_tokens.end()) {
        rel_id = RelatedEntityIdToPrintedToken(em, cl.value(), it->second);
      } else {
        rel_id = RelatedEntityIdToPrintedToken(em, cl.value(), pl);
      }
    }

    if (pl && parsed_id == mx::kInvalidEntityId) {
      parsed_id = em.EntityId(pl.value());
    }

    // It's possible that the parsed location is technically different than
    // the printed one, e.g. due to deduplication in places in clang (see
    // `EntityLabeller::Label(const pasta::PrintedToken &entity)` for additional
    // details). In those cases, we want to give preference to the parsed ID
    // that we have from the fragment.
    if (parsed_id == mx::kInvalidEntityId &&
        mx::EntityId(tok_id).Extract<mx::ParsedTokenId>()) {
      parsed_id = tok_id;
    }

    if (!cl && !pl && ml && rel_id == mx::kInvalidEntityId) {
      rel_id = RelatedEntityIdToMacroToken(em, ml.value());
    }

    // Hash the data. Data equivalence helps to prioritize the propagation of
    // info.
    if (pl) {
      data_hash = Hash64(pl->Data());
    } else if (ml) {
      data_hash = Hash64(ml->Data());
    } else if (cl) {
      data_hash = Hash64(cl->Data());
    } else {
      assert(false);
    }

    TokenInfo &info = infos.emplace_back(tok_id, data_hash, rel_id, parsed_id);

#ifndef NDEBUG
    if (pl) {
      info.data = pl->Data();
    } else if (ml) {
      info.data = ml->Data();
    }
#endif

    info_map.emplace(RawEntity(node), &info);
    if (ml) {
      info_map.emplace(RawEntity(ml.value()), &info);
    }

    ordered_tokens.push_back(&info);
  }

  info_map.erase(nullptr);

  // Do single-step connections between the tokens and the what they are
  // derived from.
  for (const TokenTreeNode &node : tokens) {
    TokenInfo *child = info_map[RawEntity(node)];
    assert(child != nullptr);
    assert(child->derived_token_id == mx::kInvalidEntityId);

    auto pl = node.Token();
    auto cl = node.PrintedToken();
    auto ml = node.MacroToken();

    if (!pl && cl) {
      pl = cl->DerivedLocation();
    }

    if (pl && !ml) {
      ml = pl->MacroLocation();
    }

    pasta::DerivedToken dl;
    if (pl) {
      dl = pl->DerivedLocation();
    } else if (ml) {
      dl = ml->DerivedLocation();
    }

    TokenInfo *prev_child = child;

    while (!std::holds_alternative<std::monostate>(dl)) {
      if (auto it = info_map.find(RawEntity(dl)); it != info_map.end()) {
        if (prev_child->DeriveFrom(*this, it->second)) {
          child->derived_token_id = it->second->entity_id;
          break;
        }
      }

      // Synthesize a file token node.
      if (std::holds_alternative<pasta::FileToken>(dl)) {
        const auto &ft = std::get<pasta::FileToken>(dl);
        auto found_eid = em.EntityId(ft);
        TokenInfo &finfo = infos.emplace_back(
            found_eid, child->data_hash, child->related_entity_id,
            child->parsed_token_id);
#ifndef NDEBUG
        finfo.data = ft.Data();
#endif
        info_map.emplace(RawEntity(ft), &finfo);
        if (prev_child->DeriveFrom(*this, &finfo)) {
          ordered_tokens.push_back(&finfo);
          child->derived_token_id = found_eid;
          break;
        }

      // NOTE(pag): With macro tokens, we might find that we are missing some
      //            "in-between" tokens due to the token tree process eliminating
      //            tokens belonging to argument pre-expansion phases. In these
      //            situations, we need to make an extra hop.
      } else if (std::holds_alternative<pasta::MacroToken>(dl)) {
        auto &mt = std::get<pasta::MacroToken>(dl);
        auto found_eid = em.EntityId(mt); 
        TokenInfo &minfo = infos.emplace_back(
            found_eid, child->data_hash, child->related_entity_id,
            child->parsed_token_id);

#ifndef NDEBUG
        minfo.data = child->data;
#endif

        // NOTE(pag): We *don't* add `minfo` into `info_map`, so that nothing
        //            else finds it, as it's entity info is not complete.
        if (!prev_child->DeriveFrom(*this, &minfo)) {
          ordered_tokens.push_back(&minfo);
          
          if (found_eid != mx::kInvalidEntityId) {
            child->derived_token_id = found_eid;
            child = &minfo;
          }

          prev_child = &minfo;
        }

        dl = mt.DerivedLocation();

      } else {
        assert(false);
        break;
      }
    }

    if (ml) {
      if (auto parent = ml->Parent()) {
        TryConnectToConcatenatedTokens(child, ml.value(), parent.value());
      }
    }

    if (child->derived_token_id != mx::kInvalidEntityId) {
      continue;
    }

    while (ml) {
      if (BackupConnectToDerived(child, ml.value())) {
        break;
      }

      dl = ml->DerivedLocation();
      if (!std::holds_alternative<pasta::MacroToken>(dl)) {
        break;
      }

      ml = std::move(std::get<pasta::MacroToken>(dl));
    }

    if (child->derived_token_id == mx::kInvalidEntityId) {
      child->DeriveFrom(*this, &(empty.value()));
    }
  }

  info_map.emplace(nullptr, &(empty.value()));

  // NOTE(pag): Depth values are actually very very large positive numbers.
  auto min_depth = ~0u;
  for (auto t : ordered_tokens) {
    min_depth = std::max(min_depth, t->Depth(*this));
  }

  Sort();

  auto max_depth = (~0u - min_depth) + 1u;
  auto iter = 0u;

  // Iteratively improve connections.
  for (auto changed = true; changed && iter <= max_depth; ++iter) {
    changed = Pull();
  }

  FallbackInitMacroProvenance(tokens);

  iter = 0u;
  for (auto changed = true; changed && iter <= max_depth;) {
    changed = false;
    if (!Push()) {
      break;
    }

    changed = true;
    if (!Pull()) {
      ++iter;
    }
  }

  FinalPush();
}

// This is the backup version when `tokens` only contains parsed tokens.
void TokenProvenanceCalculator::Run(
    mx::RawEntityId fragment_index_,
    const pasta::PrintedTokenRange &tokens) {

  fragment_index = fragment_index_;

  for (pasta::PrintedToken tok : tokens) {
    std::optional<pasta::Token> pl = tok.DerivedLocation();

    mx::RawEntityId tok_id = em.EntityId(tok);
    mx::RawEntityId rel_id = mx::kInvalidEntityId;
    mx::RawEntityId parsed_id = mx::kInvalidEntityId;

    if (pl) {
      const pasta::Token &parsed_tok = pl.value();

      parsed_id = em.EntityId(parsed_tok);
      rel_id = RelatedEntityIdToPrintedToken(em, tok, parsed_tok);
      if (rel_id == mx::kInvalidEntityId) {
        rel_id = RelatedEntityIdToPrintedToken(em, tok, std::nullopt);
      }
    }

    TokenInfo &info = infos.emplace_back(
        tok_id, Hash64(tok.Data()), rel_id, parsed_id);

#ifndef NDEBUG
    info.data = tok.Data();
#endif

    info_map.emplace(RawEntity(tok), &info);

    if (pl) {
      info.derived_token_id = em.EntityId(pl->FileLocation());
    }

    ordered_tokens.push_back(&info);
  }

  info_map.erase(nullptr);
  info_map.emplace(nullptr, &(empty.value()));

  Sort();

  for (auto changed = true; changed; ) {
    changed = Pull();
  }
}

void TokenProvenanceCalculator::Init(
    const pasta::PrintedTokenRange &printed_toks) {
  Clear();

  for (pasta::PrintedToken tok : printed_toks) {
    if (std::optional<pasta::Token> parsed_tok = tok.DerivedLocation()) {
      parsed_tokens.emplace(RawEntity(tok), std::move(parsed_tok.value()));
    }
  }
}

#ifndef NDEBUG
namespace {

static std::string TokData(std::string_view data) {
  std::stringstream ss;
  for (auto ch : data) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\r': ss << ' '; break;
      case '\n': ss << ' '; break;
      case '&': ss << "&amp;"; break;
      case '\\': ss << '|'; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

}  // namespace

void TokenProvenanceCalculator::Dump(std::ostream &os) {
  os << "digraph {\n"
     << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  auto order = 0u;
  for (TokenInfo &t : infos) {
    auto id = reinterpret_cast<uintptr_t>(&t);
    os << "n" << id
       << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
       << "<TD>depth=" << (~0u - t.Depth(*this)) << "</TD></TR><TR><TD>order="
       << order << "</TD></TR><TR><TD>id=" << t.entity_id
       << "</TD></TR><TR><TD>derived=" << t.derived_token_id
       << "</TD></TR><TR><TD>rel=" << t.related_entity_id
       << "</TD></TR><TR><TD>parsed=" << t.parsed_token_id
       << "</TD></TR><TR><TD>" << TokData(t.data) << "</TD></TR></TABLE>>];\n";

    for (TokenInfo *c : t.Children(*this)) {
      os << "n" << id << " -> n" << reinterpret_cast<uintptr_t>(c) << ";\n";
    }

    ++order;
  }
  os << "}\n";
}
#endif

}  // namespace indexer
