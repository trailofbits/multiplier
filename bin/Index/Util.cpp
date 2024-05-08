// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Util.h"

#include <algorithm>
#include <glog/logging.h>
#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/PrettyPrinter.h>
// NOTE(pag): We use the UTF-8 functions from the `llvm::json` namespace.
#include <llvm/Support/JSON.h>
#pragma clang diagnostic pop

#include <multiplier/AST.h>
#include <multiplier/Frontend.h>

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <sstream>
#include <capnp/common.h>
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <kj/io.h>
#include <xxhash.h>

#include "EntityMapper.h"
#include "PASTA.h"

namespace indexer {

// Return `true` of `tok` is in the context of `decl`.
bool TokenIsInContextOfDecl(const pasta::Token &tok, const pasta::Decl &decl) {
  return decl.Tokens().Contains(tok);
}

// Returns the `pasta::FileToken` if this is a top-level token in the parse.
std::optional<pasta::FileToken> AsTopLevelFileToken(const pasta::Token &tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kFileToken:
    case pasta::TokenRole::kInitialMacroUseToken:
    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
      return tok.FileLocation();
    default:
      return std::nullopt;
  }
}

// Tell us if this was a token that was actually parsed, and thus should have
// a fragment token ID.
//
// NOTE(pag): This logic is similarly reflected in `EntityLabeller::Label`.
bool IsParsedToken(const pasta::Token &tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kFileToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
      return !tok.Data().empty();

    default:
      return false;
  }
}

bool IsParsedToken(const pasta::PrintedToken &tok) {
  if (tok.Data().empty()) {
    return false;
  }

  if (auto pl = tok.DerivedLocation()) {
    return IsParsedToken(pl.value());
  }

  return true;
}

// Like `IsParsedToken`, but returns `false` for whitespace and comments that
// were made visible to Clang's preprocessor.
bool IsParsedTokenExcludingWhitespaceAndComments(const pasta::Token &tok) {
  switch (tok.Role()) {
    case pasta::TokenRole::kFileToken:
    case pasta::TokenRole::kFinalMacroExpansionToken:
      break;

    default:
      return false;
  }

  switch (tok.Kind()) {
    case pasta::TokenKind::kComment:
      return false;
    default:
      return !IsWhitespaceOrEmpty(tok.Data());
  }
}

namespace {

// Compute the last token of a macro.
static std::optional<pasta::MacroToken> EndTokenOfRange(pasta::MacroRange range,
                                                        const void *parent) {
  std::optional<pasta::MacroToken> last_tok;

  for (pasta::Macro child_node : range) {
    auto parent_of_child = child_node.Parent();
    if (!parent_of_child) {
      assert(false);
      break;
    }

    if (parent_of_child->RawMacro() != parent) {
      break;
    }

    if (auto new_end_tok = EndToken(child_node)) {
      last_tok = new_end_tok;
    }
  }

  return last_tok;
}

}  // namespace

// Compute the last token of a macro.
std::optional<pasta::MacroToken> EndToken(const pasta::Macro &macro) {

  auto parent = macro.RawMacro();

  if (auto sub = pasta::MacroSubstitution::From(macro)) {
    if (auto last_repl_tok = EndTokenOfRange(
            sub->ReplacementChildren(), parent)) {
      return last_repl_tok;
    }

    if (auto exp = pasta::MacroExpansion::From(macro)) {
      if (auto last_body_tok = EndTokenOfRange(
              exp->IntermediateChildren(), parent)) {
        return last_body_tok;
      }
    }
  }

  if (auto tok = pasta::MacroToken::From(macro)) {
    return tok;
  }

  // NOTE(pag): `pasta::Macro::EndToken` returns the last use token. That
  //            sometimes ends up being the right-corner of some internal left
  //            corner.
  return EndTokenOfRange(macro.Children(), parent);
}

// Print a declaration; useful for error reporting.
std::string DeclToString(const pasta::Decl &decl) {
  std::stringstream ss;
  for (pasta::PrintedToken ptok : pasta::PrintedTokenRange::Create(decl)) {
    ss << ' ' << ptok.Data();
  }
  return ss.str();
}

// Return the name of a declaration with a leading `prefix`, or nothing.
std::string PrefixedName(const pasta::Decl &decl, const char *prefix) {
  if (auto nd = pasta::NamedDecl::From(decl)) {
    auto name = nd->Name();
    if (!name.empty()) {
      return prefix + name;
    }
  }
  return "";
}

// Return the location of a declaration with a leading `prefix`, or nothing.
std::string PrefixedLocation(const pasta::Decl &decl, const char *prefix) {
  auto ft = decl.Token().FileLocation();
  if (!ft) {
    for (auto tok : decl.Tokens()) {
      ft = decl.Token().FileLocation();
      if (ft) {
        break;
      }
    }
  }
  if (ft) {
    auto file = pasta::File::Containing(*ft);
    std::stringstream ss;
    ss << prefix << file.Path().lexically_normal().generic_string()
       << ':' << ft->Line() << ':' << ft->Column();
    return ss.str();
  }
  return "";
}

// Return the location of a declaration with a leading `prefix`, or nothing.
std::string PrefixedLocation(const std::vector<pasta::Decl> &decls,
                             const char *prefix) {
  if (!decls.empty()) {
    return PrefixedLocation(decls.front(), prefix);
  }
  return "";
}

// Returns `true` if `data` contains only whitespace or is empty.
bool IsWhitespaceOrEmpty(std::string_view data) {
  for (auto ch : data) {
    switch (ch) {
      case ' ': case '\t': case '\r': case '\n': case '\\':
        continue;
      default:
        return false;
    }
  }
  return true;
}

mx::TokenKind TokenKindFromPasta(pasta::TokenKind kind, std::string_view data) {
  auto mx_kind = mx::FromPasta(kind);
  if (mx_kind == mx::TokenKind::UNKNOWN) {
    if (!data.empty() && IsWhitespaceOrEmpty(data)) {
      return mx::TokenKind::WHITESPACE;
    }
  }
  return mx_kind;
}

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::FileToken &entity) {
  switch (entity.PreProcessorKeywordKind()) {
    case pasta::PPKeywordKind::kNotKeyword:
      break;
    case pasta::PPKeywordKind::kIf:
      return mx::TokenKind::PP_IF;
    case pasta::PPKeywordKind::kIfdef:
      return mx::TokenKind::PP_IFDEF;
    case pasta::PPKeywordKind::kIfndef:
      return mx::TokenKind::PP_IFNDEF;
    case pasta::PPKeywordKind::kElif:
      return mx::TokenKind::PP_ELIF;
    case pasta::PPKeywordKind::kElifdef:
      return mx::TokenKind::PP_ELIFDEF;
    case pasta::PPKeywordKind::kElifndef:
      return mx::TokenKind::PP_ELIFNDEF;
    case pasta::PPKeywordKind::kElse:
      return mx::TokenKind::PP_ELSE;
    case pasta::PPKeywordKind::kEndif:
      return mx::TokenKind::PP_ENDIF;
    case pasta::PPKeywordKind::kDefined:
      return mx::TokenKind::PP_DEFINED;
    case pasta::PPKeywordKind::kInclude:
      return mx::TokenKind::PP_INCLUDE;
    case pasta::PPKeywordKind::k__IncludeMacros:
      return mx::TokenKind::PP___INCLUDE_MACROS;
    case pasta::PPKeywordKind::kDefine:
      return mx::TokenKind::PP_DEFINE;
    case pasta::PPKeywordKind::kUndef:
      return mx::TokenKind::PP_UNDEF;
    case pasta::PPKeywordKind::kLine:
      return mx::TokenKind::PP_LINE;
    case pasta::PPKeywordKind::kError:
      return mx::TokenKind::PP_ERROR;
    case pasta::PPKeywordKind::kPragma:
      return mx::TokenKind::PP_PRAGMA;
    case pasta::PPKeywordKind::kImport:
      return mx::TokenKind::PP_IMPORT;
    case pasta::PPKeywordKind::kIncludeNext:
      return mx::TokenKind::PP_INCLUDE_NEXT;
    case pasta::PPKeywordKind::kWarning:
      return mx::TokenKind::PP_WARNING;
    case pasta::PPKeywordKind::kIdentifier:
      return mx::TokenKind::PP_IDENTIFIER;
    case pasta::PPKeywordKind::kSccs:
      return mx::TokenKind::PP_SCCS;
    case pasta::PPKeywordKind::kAssert:
      return mx::TokenKind::PP_ASSERT;
    case pasta::PPKeywordKind::kUnassert:
      return mx::TokenKind::PP_UNASSERT;
    case pasta::PPKeywordKind::k__PublicMacro:
      return mx::TokenKind::PP___PUBLIC_MACRO;
    case pasta::PPKeywordKind::k__PrivateMacro:
      return mx::TokenKind::PP___PRIVATE_MACRO;
  }
  switch (entity.ObjectiveCAtKeywordKind()) {
    case pasta::ObjCKeywordKind::kNotKeyword:
      break;
    case pasta::ObjCKeywordKind::kClass:
      return mx::TokenKind::OBJC_AT_CLASS;
    case pasta::ObjCKeywordKind::kCompatibilityAlias:
      return mx::TokenKind::OBJC_AT_COMPATIBILITY_ALIAS;
    case pasta::ObjCKeywordKind::kDefinitions:
      return mx::TokenKind::OBJC_AT_DEFINITIONS;
    case pasta::ObjCKeywordKind::kEncode:
      return mx::TokenKind::OBJC_AT_ENCODE;
    case pasta::ObjCKeywordKind::kObjcEnd:
      return mx::TokenKind::OBJC_AT_OBJC_END;
    case pasta::ObjCKeywordKind::kImplementation:
      return mx::TokenKind::OBJC_AT_IMPLEMENTATION;
    case pasta::ObjCKeywordKind::kInterface:
      return mx::TokenKind::OBJC_AT_INTERFACE;
    case pasta::ObjCKeywordKind::kPrivate:
      return mx::TokenKind::OBJC_AT_PRIVATE;
    case pasta::ObjCKeywordKind::kProtected:
      return mx::TokenKind::OBJC_AT_PROTECTED;
    case pasta::ObjCKeywordKind::kProtocol:
      return mx::TokenKind::OBJC_AT_PROTOCOL;
    case pasta::ObjCKeywordKind::kPublic:
      return mx::TokenKind::OBJC_AT_PUBLIC;
    case pasta::ObjCKeywordKind::kSelector:
      return mx::TokenKind::OBJC_AT_SELECTOR;
    case pasta::ObjCKeywordKind::kThrow:
      return mx::TokenKind::OBJC_AT_THROW;
    case pasta::ObjCKeywordKind::kTry:
      return mx::TokenKind::OBJC_AT_TRY;
    case pasta::ObjCKeywordKind::kCatch:
      return mx::TokenKind::OBJC_AT_CATCH;
    case pasta::ObjCKeywordKind::kFinally:
      return mx::TokenKind::OBJC_AT_FINALLY;
    case pasta::ObjCKeywordKind::kSynchronized:
      return mx::TokenKind::OBJC_AT_SYNCHRONIZED;
    case pasta::ObjCKeywordKind::kAutoreleasepool:
      return mx::TokenKind::OBJC_AT_AUTORELEASEPOOL;
    case pasta::ObjCKeywordKind::kProperty:
      return mx::TokenKind::OBJC_AT_PROPERTY;
    case pasta::ObjCKeywordKind::kPackage:
      return mx::TokenKind::OBJC_AT_PACKAGE;
    case pasta::ObjCKeywordKind::kRequired:
      return mx::TokenKind::OBJC_AT_REQUIRED;
    case pasta::ObjCKeywordKind::kOptional:
      return mx::TokenKind::OBJC_AT_OPTIONAL;
    case pasta::ObjCKeywordKind::kSynthesize:
      return mx::TokenKind::OBJC_AT_SYNTHESIZE;
    case pasta::ObjCKeywordKind::kDynamic:
      return mx::TokenKind::OBJC_AT_DYNAMIC;
    case pasta::ObjCKeywordKind::kImport:
      return mx::TokenKind::OBJC_AT_IMPORT;
    case pasta::ObjCKeywordKind::kAvailable:
      return mx::TokenKind::OBJC_AT_AVAILABLE;
  }

  return TokenKindFromPasta(entity.Kind(), entity.Data());
}

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::Token &entity) {
  switch (entity.Role()) {
    default:
      break;

    // This comes up with things like PASTA's token splitter, where it will
    // inject tokens in an invalid role and potentially patch them into things
    // like `mx::TokenKind::L_ANGLE`.
    case pasta::TokenRole::kInvalid:

    // Self-explanatory: begin and end files.
    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:

    // Self-explanatory: begin and end macros.
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:

    // Pragmas often need to be retained, so we have this explicit token.
    // Besides pragmas, it's useful to know where all other directives are
    // relative to parsed tokens, as this helps us extend the bounds of entities
    // e.g. to handle Issue #457.
    case pasta::TokenRole::kMacroDirectiveMarker:
      LOG(FATAL)
          << "Should not be serializing marker tokens";
      return mx::TokenKind::UNKNOWN;
  }

  return TokenKindFromPasta(entity.Kind(), entity.Data());
}

namespace {

// Look for `asm("asm" : [identifier] "constraint" (input_or_output))` and
// try to make `identifier` into a `STRING_LITERAL` token kind, because
// logically it refers to to something inside of `"asm"`.
static mx::TokenKind ClassifyIdentifierToken(const pasta::PrintedToken &token,
                                             const pasta::Stmt &stmt) {
  auto gcc_asm = pasta::GCCAsmStmt::From(stmt);
  if (!gcc_asm) {
    return mx::TokenKind::IDENTIFIER;
  }

  for (auto name : gcc_asm->InputNames()) {
    if (token.Data() == name) {
      return mx::TokenKind::STRING_LITERAL;
    }
  }

  for (auto name : gcc_asm->OutputNames()) {
    if (token.Data() == name) {
      return mx::TokenKind::STRING_LITERAL;
    }
  }

  return mx::TokenKind::IDENTIFIER;
}

}  // namespace

// Return the token kind from printed token
mx::TokenKind TokenKindFromPasta(const pasta::PrintedToken &entity) {
  auto kind = mx::FromPasta(entity.Kind());
  if (kind == mx::TokenKind::UNKNOWN) {
    auto data = entity.Data();
    if (!data.empty() && IsWhitespaceOrEmpty(data)) {
      return mx::TokenKind::WHITESPACE;
    }
  }

  if (mx::TokenKind::IDENTIFIER != kind) {
    return kind;
  }

  // Try to do some context-specific specialization of token kinds.
  if (auto context = entity.Context()) {
    if (auto stmt = pasta::Stmt::From(context.value())) {
      return ClassifyIdentifierToken(entity, stmt.value());
    }
  }

  return mx::TokenKind::IDENTIFIER;
}

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::MacroToken &entity) {
  auto dtok = entity.DerivedLocation();
  if (std::holds_alternative<pasta::FileToken>(dtok)) {
    const auto &ft = std::get<pasta::FileToken>(dtok);

  // Try to get preprocessor kinds, if possible.
  if (ft.PreProcessorKeywordKind() != pasta::PPKeywordKind::kNotKeyword ||
      ft.ObjectiveCAtKeywordKind() != pasta::ObjCKeywordKind::kNotKeyword) {
    return TokenKindFromPasta(ft);
  }

    return TokenKindFromPasta(std::get<pasta::FileToken>(dtok));
  }
  return TokenKindFromPasta(entity.TokenKind(), entity.Data());
}

pasta::DerivedToken DerivedLocation(const pasta::DerivedToken &tok) {
  if (std::holds_alternative<pasta::MacroToken>(tok)) {
    return std::get<pasta::MacroToken>(tok).DerivedLocation();
  }
  return std::monostate{};
}

namespace {

// NOTE(pag): An `alias` attribute is considered a "defining attribute".
static bool FuncIsDefinition(clang::FunctionDecl *decl) {
  if (decl->isThisDeclarationADefinition()) {
    return !decl->hasAttr<clang::AliasAttr>();
  } else {
    const clang::FunctionDecl *def_decl = nullptr;
    return decl->getBody(def_decl) && def_decl == decl;
  }
}

// Treat parameters in function declarations/prototypes as just being
// declarations and not themselves definitions.
static bool ParamIsDefinition(clang::ParmVarDecl *decl) {
  clang::DeclContext *dc = decl->getDeclContext();
  clang::Decl *dc_decl = clang::Decl::castFromDeclContext(dc);
  if (auto func = clang::dyn_cast<clang::FunctionDecl>(dc_decl)) {
    return FuncIsDefinition(func);
  } else {
    return false;
  }
}

}  // namespace

// Does this look like a replaceable fragment? This happens when there's a
// method with an uninstantiated/unsubstitued body, or return type that isn't
// yet deduced.
bool IsReplaceableFragment(const std::vector<pasta::Decl> &decls) {
  if (decls.size() != 1u) {
    return false;
  }

  const pasta::Decl &decl = decls.front();
  switch (decl.Kind()) {
    case pasta::DeclKind::kFunction:
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod:
      break;
    default:
      return false;
  }

  if (decl.IsImplicit()) {
    return false;
  }

  const auto &func = reinterpret_cast<const pasta::FunctionDecl &>(decl);
  
  // We don't expect to be looking at the pattern definition itself. We should
  // really never hit this condition, because the top-level decl in `decls`
  // should instead be the `FunctionTemplateDecl`.
  if (func.DescribedFunctionTemplate()) {
    assert(false);
    return false;
  }

  // If we have a method with an unresolved/undeduced/etc return type then we
  // really hope that something better is going to come along.
  auto rt = func.ReturnType().UnqualifiedDesugaredType();
  if (rt.ContainsErrors() || rt.IsPlaceholderType() || rt.IsUnresolvedType() ||
      rt.IsUndeducedAutoType() || rt.IsUndeducedType()) {
    return true;
  }

  // NOTE(pag): Clang usually performs body substitution when a method is
  //            referenced, but not always. What we're looking for is that a
  //            method doesn't have a body, but that it is patterned on
  //            something that *does* have a body.
  if (func.DoesThisDeclarationHaveABody()) {
    return false;
  }

  auto pattern_decl = TemplateInstantiationPattern(func);
  if (!pattern_decl) {
    return true;
  }

  return pattern_decl->DoesThisDeclarationHaveABody();
}

// Returns `true` if `decl` is a definition.
bool IsDefinition(const pasta::Decl &decl_) {
  auto decl = const_cast<clang::Decl *>(decl_.RawDecl()->RemappedDecl);

  if (auto parm_decl = clang::dyn_cast<clang::ParmVarDecl>(decl)) {
    return ParamIsDefinition(parm_decl);

  } else if (auto func_decl = clang::dyn_cast<clang::FunctionDecl>(decl)) {
    return FuncIsDefinition(func_decl);

  } else if (clang::isa<clang::TypedefNameDecl>(decl)) {
    return true;

  } else if (clang::isa<clang::FieldDecl>(decl)) {
    return true;

  } else if (auto var_decl = clang::dyn_cast<clang::VarDecl>(decl)) {
    return (clang::VarDecl::DeclarationOnly !=
            var_decl->isThisDeclarationADefinition());

  } else if (auto method_decl = clang::dyn_cast<clang::ObjCMethodDecl>(decl)) {
    return method_decl->isThisDeclarationADefinition();

  } else if (auto proto_decl = clang::dyn_cast<clang::ObjCProtocolDecl>(decl)) {
    return proto_decl->isThisDeclarationADefinition();

  } else if (auto face_decl = clang::dyn_cast<clang::ObjCInterfaceDecl>(decl)) {
    return face_decl->isThisDeclarationADefinition();

  } else if (auto tag_decl = clang::dyn_cast<clang::TagDecl>(decl)) {
    return tag_decl->isThisDeclarationADefinition();

  } else if (auto ctpl_decl = clang::dyn_cast<clang::ClassTemplateDecl>(decl)) {
    return ctpl_decl->isThisDeclarationADefinition();

  } else if (auto ftpl_decl = clang::dyn_cast<clang::FunctionTemplateDecl>(decl)) {
    return ftpl_decl->isThisDeclarationADefinition();

  } else if (auto vtpl_decl = clang::dyn_cast<clang::VarTemplateDecl>(decl)) {
    return vtpl_decl->isThisDeclarationADefinition();

  } else if (clang::isa<clang::EnumConstantDecl>(decl)) {
    return true;

  } else {
    return false;
  }
}

// Checks if the declaration is valid and serializable
bool IsSerializableDecl(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kTranslationUnit:
    case pasta::DeclKind::kCXXDeductionGuide:
      return false;

    // Function templates can contain deduction guides.
    case pasta::DeclKind::kFunctionTemplate: {
      auto &ft = reinterpret_cast<const pasta::FunctionTemplateDecl &>(decl);
      return IsSerializableDecl(ft.TemplatedDeclaration());
    }

    default:
      return !decl.IsInvalidDeclaration();
  }
}

namespace {

static std::optional<pasta::FileToken> DeclStart(const pasta::Decl &decl) {
  auto ft = decl.Token().FileLocation();
  if (!ft) {
    for (auto tok : decl.Tokens()) {
        ft = decl.Token().FileLocation();
        if (ft) {
          break;
        }
    }
  }
  return ft;
}

static std::optional<pasta::FileToken> DeclEnd(const pasta::Decl &decl) {
  auto ft = decl.Token().FileLocation();
  for (auto tok : decl.Tokens()) {
    if (auto new_ft = decl.Token().FileLocation()) {
      ft = new_ft;
    }
  }
  return ft;
}

static bool IsLexicallyOutOfLine(const pasta::Decl &decl,
                                 const pasta::Decl &parent_decl) {

  auto loc = DeclStart(decl);
  auto parent_loc = DeclStart(parent_decl);
  auto parent_end_loc = DeclEnd(parent_decl);

  if (!(loc && parent_loc && parent_end_loc)) {
    return false;
  }

  return parent_loc->Index() < parent_end_loc->Index() &&
      loc->Index() >= parent_loc->Index() &&
      loc->Index() <= parent_end_loc->Index();
}

}  // namespace

bool IsOutOfLine(const pasta::Decl &decl) {
  if (decl.IsOutOfLine()){
    return true;
  }

  auto dc = decl.DeclarationContext();
  if (!dc) {
    return false;
  }

  switch (decl.Kind()) {
    case pasta::DeclKind::kClassTemplate:
    case pasta::DeclKind::kClassTemplateSpecialization:
    case pasta::DeclKind::kClassTemplatePartialSpecialization:
    case pasta::DeclKind::kCXXRecord:
    case pasta::DeclKind::kFunction:
    case pasta::DeclKind::kFunctionTemplate:
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod:
    case pasta::DeclKind::kVar:
    case pasta::DeclKind::kVarTemplate:
    case pasta::DeclKind::kVarTemplateSpecialization:
    case pasta::DeclKind::kVarTemplatePartialSpecialization:  {
      return IsLexicallyOutOfLine(decl, dc.value());
    }
    default:
      break;
  }

  return false;
}

// If `decl` is a declaration context, then this will return `true` if `decl`
// should be internalized into the fragment, otherwise `false`. Returns `false`
// if `decl` isn't a declaration context.
bool ShouldInternalizeDeclContextIntoFragment(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kExport:
    case pasta::DeclKind::kExternCContext:
    case pasta::DeclKind::kLinkageSpec:
    case pasta::DeclKind::kNamespace:
      return true;
    default:
      return false;
  }
}

// This the specialization kind explicit? This corresponds to something like
// `extern template class foo<type>;`.
bool IsExplicitInstantiation(const pasta::TemplateSpecializationKind &kind) {
  switch (kind) {
    case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration:
    case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition:
      return true;
    default:
      return false;
  }
}

// Is the specialization kind explicit? This corresponds to a template
// specialization being fully spelled out in the code, rather than being derived
// from a template pattern or a partial specialization pattern.
bool IsExplicitSpecialization(const pasta::TemplateSpecializationKind &kind) {
  return kind == pasta::TemplateSpecializationKind::kExplicitSpecialization;
}

// Is the specialization kind explicit? This corresponds to a template
// specialization being fully spelled out in the code, rather than being derived
// from a template pattern or a partial specialization pattern.
bool IsExplicitSpecialization(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kVarTemplateSpecialization:
      return IsExplicitSpecialization(
          reinterpret_cast<const pasta::VarTemplateSpecializationDecl &>(decl).
              TemplateSpecializationKind());
    case pasta::DeclKind::kClassTemplateSpecialization:
      return IsExplicitSpecialization(
          reinterpret_cast<const pasta::ClassTemplateSpecializationDecl &>(decl).
              TemplateSpecializationKind());
    case pasta::DeclKind::kFunction:
    case pasta::DeclKind::kCXXMethod:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXDeductionGuide:
      return IsExplicitSpecialization(
          reinterpret_cast<const pasta::FunctionDecl &>(decl).
              TemplateSpecializationKind());

    case pasta::DeclKind::kVarTemplatePartialSpecialization:
    case pasta::DeclKind::kClassTemplatePartialSpecialization:
      return true;

    default:
      return false;
  }
}

// Returns whether or not `decl` is a specialization of a template. Clang
// reports methods derived from methods inside of class templates as being
// specializations, but this function focuses on determining that something is
// actually derived from a template, i.e. a method is a specialization if it is
// derived from a method inside of a function template.
bool IsSpecialization(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    // Treat templates kind of like specializations if they exist inside of
    // another specialization. This is because they may actually use the outer
    // template arguments/parameters.
    case pasta::DeclKind::kVarTemplate:
    case pasta::DeclKind::kClassTemplate:
    case pasta::DeclKind::kFunctionTemplate:
    case pasta::DeclKind::kFriendTemplate:
    case pasta::DeclKind::kVarTemplatePartialSpecialization:
    case pasta::DeclKind::kClassTemplatePartialSpecialization:
    case pasta::DeclKind::kTypeAliasTemplate:
      return false;

    case pasta::DeclKind::kVarTemplateSpecialization:
    case pasta::DeclKind::kClassTemplateSpecialization:
    case pasta::DeclKind::kImplicitConceptSpecialization:
      return true;

    // NOTE(pag): Type alias templates cannot be explicitly specialized.
    case pasta::DeclKind::kTypeAlias:
      return false;

    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod: {
      auto func = reinterpret_cast<const pasta::CXXMethodDecl &>(decl);
      auto tsk = func.TemplateSpecializationKind();
      if (tsk == pasta::TemplateSpecializationKind::kUndeclared) {
        return false;
      }

      if (IsExplicitSpecialization(tsk)) {
        return true;
      }

      if (auto pattern = func.InstantiatedFromMemberFunction()) {
        return pattern->DescribedFunctionTemplate().has_value();
      }

      return TemplateInstantiationPattern(func).has_value();
    }

    case pasta::DeclKind::kFunction: {
      auto func = reinterpret_cast<const pasta::FunctionDecl &>(decl);
      auto tsk = func.TemplateSpecializationKind();
      if (tsk == pasta::TemplateSpecializationKind::kUndeclared) {
        return false;
      }

      if (IsExplicitSpecialization(tsk)) {
        return true;
      }

      if (auto pattern = func.InstantiatedFromDeclaration()) {
        return pattern->DescribedFunctionTemplate().has_value();
      }

      return TemplateInstantiationPattern(func).has_value();
    }

    default:
      return false;
  }
}

// Returns `true` if this declaration is a method inside of a class template
// specialization. We care about these because Clang doesn't always substitute
// the method bodies inside of class template specializations, and instead
// prefers to defer their substitution until they are first referenced. This
// behavior is depended upon by a lot of C++ code.
bool IsMethodLexicallyInSpecialization(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod:
      break;
    default:
      return false;
  }

  // NOTE(pag): Checking `decl.IsOutOfLine()` is not sufficient, as the out-of-
  //            line method definition may itself be defined within a class
  //            template specialization.

  auto func = reinterpret_cast<const pasta::CXXMethodDecl &>(decl);
  auto lc = func.LexicalDeclarationContext();
  if (!lc) {
    assert(false);
    return false;
  }

  auto parent_spec = pasta::ClassTemplateSpecializationDecl::From(lc.value());
  if (!parent_spec) {
    return false;
  }
  
  return parent_spec->Kind() != pasta::DeclKind::kClassTemplatePartialSpecialization;
}

// Return `true` if a method or function is lexically defined inside of a class.
bool IsMethodLexicallyInClass(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod:
      break;
    default:
      return false;
  }

  auto func = reinterpret_cast<const pasta::FunctionDecl &>(decl);
  auto ldc = func.LexicalDeclarationContext();
  if (!ldc) {
    return false;
  }

  return ldc->IsRecord();
}

// Return `true` if this is a friend declaration.
bool IsFriendDeclaration(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kFriendTemplate:
    case pasta::DeclKind::kFriend:
      return true;
    default:
      return false;
  }
}

// Is this decl a specialization of a template? If so, then we will want
// to render the printed tokens of the specialization into the fragment, rather
// than the parsed tokens.
bool IsSpecializationOrInSpecialization(const pasta::Decl &decl) {
  if (IsSpecialization(decl)) {
    return true;
  }
  switch (decl.Kind()) {
    case pasta::DeclKind::kVarTemplate:
    case pasta::DeclKind::kClassTemplate:
    case pasta::DeclKind::kFunctionTemplate:
    case pasta::DeclKind::kFriendTemplate:
    case pasta::DeclKind::kTypeAliasTemplate:
    case pasta::DeclKind::kFunction:
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod:
      if (auto dc = decl.LexicalDeclarationContext()) {
        if (auto dc_decl = pasta::Decl::From(dc.value())) {
          return IsSpecializationOrInSpecialization(dc_decl.value());
        }
      }
      return false;

    default:
      return false;
  }
}

// Is this decl a template or template pattern?
bool IsTemplateOrPattern(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kBuiltinTemplate:
    case pasta::DeclKind::kClassTemplate:
    case pasta::DeclKind::kClassTemplatePartialSpecialization:
    case pasta::DeclKind::kConcept:
    case pasta::DeclKind::kFunctionTemplate:
    case pasta::DeclKind::kFriendTemplate:
    case pasta::DeclKind::kVarTemplate:
    case pasta::DeclKind::kVarTemplatePartialSpecialization:
    case pasta::DeclKind::kTypeAliasTemplate:
      return true;

    case pasta::DeclKind::kCXXRecord: {
      auto cls = reinterpret_cast<const pasta::CXXRecordDecl &>(decl);
      return cls.DescribedClassTemplate().has_value();
    }

    case pasta::DeclKind::kFunction:
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod: {
      auto func = reinterpret_cast<const pasta::FunctionDecl &>(decl);
      return func.DescribedFunctionTemplate().has_value();
    }

    case pasta::DeclKind::kVar: {
      auto var = reinterpret_cast<const pasta::VarDecl &>(decl);
      return var.DescribedVariableTemplate().has_value();
    }

    default:
      assert(!pasta::TemplateDecl::From(decl));
      return false;
  }
}

// Returns `true` if this is a `#pragma` directive expanded from a `_Pragma`.
bool IsInlinePragmaDirective(const pasta::Macro &macro) {
  if (macro.Kind() != pasta::MacroKind::kPragmaDirective) {
    return false;
  }

  auto &pma = reinterpret_cast<const pasta::PragmaMacroDirective &>(macro);
  if (auto parent = pma.Parent()) {
    if (auto exp = pasta::MacroExpansion::From(parent.value())) {
      if (auto name = exp->NameOrOperator()) {
        if (name->Data() == "_Pragma") {
          return true;
        }
      }
    }
  }

  return false;
}

// Determines whether or not a TLM is likely to have to go into a floating
// fragment. This generally happens when a TLM is a directive. Some general
// thoughts:
//
// Define directives can appear inside of macro expansion calls, e.g.
//
//      CALL_MACRO(
//      #define FOO ...
//          )
//
// This is annoying because the macro `CALL_MACRO` or its use site may be
// polymorphic, and we don't want that introducing additional versions of
// the definition.
//
// Conditional directives can straddle declaration bounds, as is demonstrated
// by issue #457. We don't want to have to have so many redundant versions of
// each directive.
//
// Include directives that are themselves inside other fragments can cause those
// other fragments to expand to contain a lot of other stuff. For example, this
// is common with the x-macro pattern, which is how codebases like LLVM define
// things like token kinds.
//
// NOTE(pag): Must be kept in sync with `IsFloatingDirectiveFragment` in
//            `lib/TokenTree.cpp`.
bool ShouldGoInFloatingFragment(const pasta::Macro &macro) {
  auto dir = pasta::MacroDirective::From(macro);
  if (!dir) {
    return false;
  }

  switch (macro.Kind()) {
    case pasta::MacroKind::kIncludeDirective:
    case pasta::MacroKind::kIncludeNextDirective:
    case pasta::MacroKind::kIncludeMacrosDirective:
    case pasta::MacroKind::kImportDirective:
      return false;
    case pasta::MacroKind::kExpansion:
      assert(false);
      return false;

    // NOTE(pag): A `#pragma` generated from a `_Pragma` should be placed in
    //            the same fragment.
    case pasta::MacroKind::kPragmaDirective:
      return !IsInlinePragmaDirective(macro);

    default:
      return true;
  }
}

// Does this decl look like a lamabda?
bool IsLambda(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kCXXRecord:
      if (decl.IsImplicit()) {
        return reinterpret_cast<const pasta::CXXRecordDecl &>(decl).IsLambda();
      }
      return false;
    case pasta::DeclKind::kCXXMethod: {
      const auto &method = reinterpret_cast<const pasta::CXXMethodDecl &>(decl);
      if (method.IsLambdaStaticInvoker()) {
        return true;
      } else if (method.OverloadedOperator() == pasta::OverloadedOperatorKind::kCall) {
        return method.Parent().IsLambda();
      } else {
        return false;
      }
    }
    case pasta::DeclKind::kFunctionTemplate:
      return IsLambda(
          reinterpret_cast<const pasta::FunctionTemplateDecl &>(decl).TemplatedDeclaration());
    default:
      return false;
  }
}

// Lots of methods are auto-generated, e.g. constructors, conversion operators,
// etc. These superficially look like builtins, but we don't want to treat them
// as such.
bool IsImplicitMethod(const pasta::Decl &decl) {
  if (!decl.IsImplicit()) {
    return false;
  }

  switch (decl.Kind()) {
    case pasta::DeclKind::kCXXConversion:
    case pasta::DeclKind::kCXXConstructor:
    case pasta::DeclKind::kCXXDeductionGuide:
    case pasta::DeclKind::kCXXDestructor:
    case pasta::DeclKind::kCXXMethod:
      return true;

    case pasta::DeclKind::kFunctionTemplate:
      return IsImplicitMethod(
          reinterpret_cast<const pasta::FunctionTemplateDecl &>(decl).TemplatedDeclaration());
  
    default:
      return false;
  }
}

// Get the unqualified, non-parameterized name of a declaration.
std::string Name(const pasta::NamedDecl &decl) {
  return decl.Name();  // TODO(pag).
}

// Returns `true` if a macro is visible across fragments, and should have an
// entity id stored in the global mapper.
bool IsVisibleAcrossFragments(const pasta::Macro &macro) {
  return ShouldGoInFloatingFragment(macro) ||
         macro.Kind() == pasta::MacroKind::kParameter;
}

// Tells us if a given decl is probably a use that also acts as a forward
// declaration.
bool IsInjectedForwardDeclaration(const pasta::Decl &decl) {
  switch (decl.Kind()) {
    case pasta::DeclKind::kRecord:
    case pasta::DeclKind::kCXXRecord:
    case pasta::DeclKind::kEnum: {
      const auto &tag = reinterpret_cast<const pasta::TagDecl &>(decl);
      return tag.IsEmbeddedInDeclarator() && !IsDefinition(tag);
    }
    default:
      return false;
  }
}

// Should a declaration be hidden from the indexer?
// The function will go away in the final version as we are only
// hiding TranslationUnitDecl from the indexer.
bool ShouldHideFromIndexer(const pasta::Decl &decl) {
  if (!IsSerializableDecl(decl)) {
    return true;
  }

  // If, as a result of template specialization, we can tell that some template
  // is kind of an "empty shell" for another declaration, then we want to
  // hide this declaration and forward to the other one.
  auto raw_decl = decl.RawDecl();
  if (raw_decl->RemappedDecl != raw_decl) {
    return true;
  }

  switch (decl.Kind()) {
    case pasta::DeclKind::kUsingDirective:
      return decl.IsImplicit();

    default:
      break;
  }

  return false;
}

// List the indexable declarations in this declcontext.
std::vector<pasta::Decl> DeclarationsInDeclContext(
    const pasta::DeclContext &dc) {

  auto dc_decl = pasta::Decl::From(dc);
  auto decls = dc.AlreadyLoadedDeclarations();
  auto it = std::remove_if(decls.begin(), decls.end(),
                           [&] (const pasta::Decl &d) {
                             return ShouldHideFromIndexer(d) ||
                                    d == dc_decl;
                           });
  decls.erase(it, decls.end());
  return decls;
}

// Return the root macro containing `node`.
pasta::Macro RootMacroFrom(const pasta::Macro &node) {
  if (auto parent = node.Parent()) {
    return RootMacroFrom(parent.value());
  } else {
    return node;
  }
}

namespace {

class StringOutputStream final : public kj::OutputStream {
 private:
  std::string &str;

 public:
  virtual ~StringOutputStream(void) = default;

  explicit StringOutputStream(std::string &str_)
      : str(str_) {}

  void write(const void *buffer_, size_t size) final {
    auto ptr = reinterpret_cast<const char *>(buffer_);
    str.append(ptr, &(ptr[size]));
  }
};

}  // namespace

std::string GetSerializedData(capnp::MessageBuilder &builder) {
  std::string ret;
  ret.reserve(builder.sizeInWords() * sizeof(capnp::word));
  StringOutputStream os(ret);
  capnp::writeMessage(os, builder);

  // Pad it to a multiple of the word size. We pad it out so that we can
  // allocate an aligned array of `capnp::word` on the client side for
  // the readers.
  while (ret.size() % sizeof(capnp::word)) {
    ret.push_back('\0');
  }

  return ret;
}

// Accumulate the token data, stripping out some unwanted characters in the
// process.
void AccumulateUTF8Data(std::string &data, llvm::StringRef utf8_data) {
  data.reserve(data.size() + utf8_data.size());
  for (char ch : utf8_data) {
    if (ch != '\r') {
      data.push_back(ch);
    }
  }
}

// Accumulate the token data, encoded as UTF-8, into `data`.
template <typename Tok>
void AccumulateTokenData(std::string &data, const Tok &tok) {
  llvm::StringRef tok_data = tok.Data();
  if (llvm::json::isUTF8(tok_data)) {
    AccumulateUTF8Data(data, tok_data);

  } else {
    AccumulateUTF8Data(data, llvm::json::fixUTF8(tok_data));
  }
}

template void AccumulateTokenData<pasta::FileToken>(
    std::string &data, const pasta::FileToken &tok);

template void AccumulateTokenData<pasta::Token>(
    std::string &data, const pasta::Token &tok);

template void AccumulateTokenData<pasta::PrintedToken>(
    std::string &data, const pasta::PrintedToken &tok);

template void AccumulateTokenData<pasta::MacroToken>(
    std::string &data, const pasta::MacroToken &tok);

// Helpful function to be called from a debugger where a `std::ostream`
// argument is needed.
std::ostream &StdErr(void) {
  return std::cerr;
}

// Combine all parsed tokens into a string for diagnostic purposes.
std::string DiagnosePrintedTokens(
    const pasta::PrintedTokenRange &parsed_tokens) {
  std::stringstream ss;
  auto sep = "";
  for (pasta::PrintedToken tok : parsed_tokens) {
    ss << sep << tok.Data();
    sep = " ";
  }
  return ss.str();
}

// Generate the token contexts associated with a printed token.
gap::generator<pasta::TokenContext> TokenContexts(pasta::PrintedToken tok) {
  for (auto context = tok.Context(); context;
       context = context->Parent()) {
    co_yield context.value();
  }
}

// Returns `c` if `c` isn't an alias, otherwise `c.Aliasee().value()`.
pasta::TokenContext UnaliasedContext(const pasta::TokenContext &c) {
  if (auto alias = c.Aliasee()) {
    return alias.value();
  }
  return c;
}

const void *RawEntity(const pasta::Token &entity) {
  return entity.RawToken();
}

const void *RawEntity(const pasta::PrintedToken &entity) {
  return entity.RawToken();
}

const void *RawEntity(const pasta::File &entity) {
  return entity.RawFile();
}

const void *RawEntity(const pasta::FileToken &entity) {
  return entity.RawFileToken();
}

const void *RawEntity(const pasta::Decl &entity) {
  return entity.RawDecl();
}

const void *RemappedRawEntity(const pasta::Decl &entity) {
  return entity.RawDecl()->RemappedDecl;
}

const void *RawEntity(const pasta::DeclContext &entity) {
  return entity.RawDeclContext();
}

const void *RawEntity(const pasta::Stmt &entity) {
  return entity.RawStmt();
}

const void *RawEntity(const pasta::Attr &entity) {
  return entity.RawAttr();
}

const void *RawEntity(const pasta::Macro &entity) {
  return entity.RawMacro();
}

const void *RawEntity(const pasta::Designator &entity) {
  return entity.RawDesignator();
}

const void *RawEntity(const pasta::CXXBaseSpecifier &entity) {
  return entity.RawCXXBaseSpecifier();
}

const void *RawEntity(const pasta::CXXCtorInitializer &entity) {
  return entity.RawCXXCtorInitializer();
}

const void *RawEntity(const pasta::TemplateArgument &entity) {
  return entity.RawTemplateArgument();
}

const void *RawEntity(const pasta::TemplateParameterList &entity) {
  return entity.RawTemplateParameterList();
}

const void *RawEntity(const TokenTree &entity) {
  return entity.RawNode();
}

const void *RawEntity(const TokenTreeNode &entity) {
  return entity.RawNode();
}

const void *RawEntity(const pasta::DerivedToken &entity) {
  if (std::holds_alternative<pasta::FileToken>(entity)) {
    return RawEntity(std::get<pasta::FileToken>(entity));

  } else if (std::holds_alternative<pasta::MacroToken>(entity)) {
    return RawEntity(std::get<pasta::MacroToken>(entity));
  } else {
    return nullptr;
  }
}

// Get the instantiation pattern.
std::optional<pasta::FunctionDecl> TemplateInstantiationPattern(
    const pasta::FunctionDecl &decl) {
  auto is_def = decl.IsThisDeclarationADefinition();
  if (is_def) {
    if (auto ret = decl.TemplateInstantiationPattern()) {
      return ret;
    }
  }

  auto raw_decl = reinterpret_cast<const clang::FunctionDecl *>(decl.RawDecl());
  auto pattern = raw_decl->getTemplateInstantiationPattern(false);
  if (!pattern) {
    assert(!is_def || !raw_decl->getTemplateInstantiationPattern());
    return std::nullopt;
  }

  auto adopted = pasta::AST::From(decl).Adopt(pattern);
  return reinterpret_cast<const pasta::FunctionDecl &>(adopted);
}

uint32_t Hash32(std::string_view data) {
  if (data.empty()) {
    return 0u;
  }
  return XXH32(data.data(), data.size(), 0x00676170u);
}

uint64_t Hash64(std::string_view data) {
  if (data.empty()) {
    return 0u;
  }
  return XXH64(data.data(), data.size(), 0x7265746570626F74ull);
}

// If this is a debug build, then invoke Clang's `clang::Decl::dumpColor()` on
// `decl`.
void Dump(const pasta::Decl &decl) {
#ifndef NDEBUG
  decl.RawDecl()->dumpColor();
#endif
  (void) decl;
}

void Print(const pasta::Decl &decl) {
  std::cerr << decl.Tokens().Data() << '\n';
}

// Generate pairs of original and remapped decls in this decl context.
gap::generator<std::pair<pasta::Decl, pasta::Decl>>
OriginalDeclsInDeclContext(pasta::DeclContext dc) {
  auto ast = pasta::AST::From(dc);
  auto raw_dc = const_cast<clang::DeclContext *>(dc.RawDeclContext());
  auto raw_dc_decl = clang::Decl::castFromDeclContext(raw_dc);

  decltype(auto) val = raw_dc->noload_decls();
  for (auto raw_decl : val) {
    if (!raw_decl || raw_decl->isInvalidDecl() || raw_decl == raw_dc_decl ||
        raw_decl->RemappedDecl == raw_dc_decl) {
      continue;
    }

    co_yield std::make_pair<pasta::Decl, pasta::Decl>(
        ast.AdoptWithoutRemap(raw_decl),
        ast.Adopt(raw_decl));
  }
}

}  // namespace indexer
