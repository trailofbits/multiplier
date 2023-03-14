// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Util.h"

#include <glog/logging.h>

#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/PrettyPrinter.h>

#include <multiplier/AST.h>
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

#include "EntityMapper.h"
#include "PASTA.h"

namespace indexer {

// Return `true` of `tok` is in the context of `decl`.
bool TokenIsInContextOfDecl(const pasta::Token &tok, const pasta::Decl &decl) {
  auto cdecl = decl.CanonicalDeclaration();
  for (auto context = tok.Context(); context; context = context->Parent()) {
    switch (context->Kind()) {
      case pasta::TokenContextKind::kTemplateArgument:
      case pasta::TokenContextKind::kTemplateParameterList:
        return true;
      case pasta::TokenContextKind::kDecl:
        if (auto maybe_decl = pasta::Decl::From(*context)) {
          pasta::DeclKind dk = maybe_decl->Kind();
          if (*maybe_decl == cdecl) {
            return true;
          } else if (dk == pasta::DeclKind::kClassTemplateSpecialization ||
                     dk == pasta::DeclKind::kClassTemplatePartialSpecialization ||
                     dk == pasta::DeclKind::kVarTemplateSpecialization ||
                     dk == pasta::DeclKind::kVarTemplatePartialSpecialization ||
                     dk == pasta::DeclKind::kClassScopeFunctionSpecialization) {
            return true;
          }
        }
        break;  // Keep looking.
      case pasta::TokenContextKind::kType:
        if (auto maybe_type = pasta::Type::From(*context)) {
          pasta::TypeKind tk = maybe_type->Kind();
          if (tk == pasta::TypeKind::kTemplateSpecialization ||
              tk == pasta::TypeKind::kElaborated) {
            return true;
          }
        }
        break;  // Keep looking.
      default:
        break;  // Keep looking.
    }
  }
  return false;
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

// Print a declaration; useful for error reporting.
std::string DeclToString(const pasta::Decl &decl) {
  std::stringstream ss;
  for (pasta::PrintedToken ptok : pasta::PrintedTokenRange::Create(decl)) {
    for (auto i = 0u, max_i = ptok.NumLeadingNewLines(); i < max_i; ++i) {
      ss << '\n';
    }
    for (auto i = 0u, max_i = ptok.NumleadingSpaces(); i < max_i; ++i) {
      ss << ' ';
    }
    ss << ptok.Data();
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
  auto kind = mx::FromPasta(entity.Kind());
  if (kind == mx::TokenKind::UNKNOWN) {
    auto data = entity.Data();
    if (!data.empty() && IsWhitespaceOrEmpty(data)) {
      return mx::TokenKind::WHITESPACE;
    }
  }
  return kind;
}

// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::Token &entity) {
  switch (entity.Role()) {
    default:
      break;

    case pasta::TokenRole::kBeginOfFileMarker:
    case pasta::TokenRole::kEndOfFileMarker:
    case pasta::TokenRole::kBeginOfMacroExpansionMarker:
    case pasta::TokenRole::kEndOfMacroExpansionMarker:
    case pasta::TokenRole::kEndOfInternalMacroEventMarker:
      LOG(ERROR)
          << "Should not be serializing marker tokens";
      return mx::TokenKind::UNKNOWN;
  }

  // Try to get preprocessor kinds, if possible.
  //
  // NOTE(pag): File tokens show `IDENTIFIER` (due to `raw_identifier`) from
  //            the raw lexer, whereas fragments do better.
  if (auto ft = entity.FileLocation()) {
    if (ft->PreProcessorKeywordKind() != pasta::PPKeywordKind::kNotKeyword ||
        ft->ObjectiveCAtKeywordKind() != pasta::ObjCKeywordKind::kNotKeyword) {
      if (auto ret = TokenKindFromPasta(ft.value());
          ret != mx::TokenKind::IDENTIFIER) {
        return ret;
      }
    }
  }

  auto kind = mx::FromPasta(entity.Kind());
  if (kind == mx::TokenKind::UNKNOWN) {
    auto data = entity.Data();
    if (!data.empty() && IsWhitespaceOrEmpty(data)) {
      return mx::TokenKind::WHITESPACE;
    }
  }
  return kind;
}


// Return the token kind.
mx::TokenKind TokenKindFromPasta(const pasta::MacroToken &entity) {
  return TokenKindFromPasta(entity.ParsedLocation());
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

// Returns `true` if `decl` is a definition.
bool IsDefinition(const pasta::Decl &decl_) {
  auto decl = const_cast<clang::Decl *>(decl_.RawDecl());

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

// Try to find the `Decl` referenced by a particular `type`.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Type &type_) {
  auto type = type_;
  for (const void *prev_raw = nullptr; prev_raw != type.RawType();
       prev_raw = type.RawType()) {
    type = type.UnqualifiedType();
    if (auto paren = pasta::ParenType::From(type)) {
      type = paren->InnerType().UnqualifiedType();
    }
    if (auto nt = type.PointeeOrArrayElementType()) {
      type = std::move(nt.value());
    }
  }

  if (auto tdt = pasta::TypedefType::From(type)) {
    return tdt->Declaration();

  } else if (auto ttt = pasta::TagType::From(type)) {
    return ttt->Declaration();

  } else if (auto tut = pasta::UsingType::From(type)) {
    if (auto ret = ReferencedDecl(tut->UnderlyingType())) {
      return ret;
    } else {
      return tut->FoundDeclaration();
    }
  
  } else if (auto dtt = pasta::DecltypeType::From(type)) {
    return ReferencedDecl(dtt->UnderlyingType());  
  
  } else if (auto ddt = pasta::DeducedType::From(type)) {
    if (auto rt = ddt->ResolvedType()) {
      return ReferencedDecl(std::move(rt.value()));
    }
  }

  return std::nullopt;
}

// Try to find the `Decl` referenced by a particular `decl`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Decl decl) {

  // NOTE(pag): We'll get the parameter type references through visiting the
  //            `ParmVarDecl`s.
  if (auto func = pasta::FunctionDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(func->ReturnType())) {
      co_yield ref;
    }
  } else if (auto field = pasta::FieldDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(field->Type())) {
      co_yield ref;
    }
  } else if (auto var = pasta::VarDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(var->Type())) {
      co_yield ref;
    }
  } else if (auto enum_ = pasta::EnumDecl::From(decl)) {
    if (auto base_type = enum_->IntegerType()) {
      for (auto ref : DeclReferencesFrom(base_type.value())) {
        co_yield ref;
      }
    }
  } else if (auto td_ = pasta::TypedefNameDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(td_->UnderlyingType())) {
      co_yield ref;
    }
  }
}

// Try to find the `Decl` referenced by a particular `stmt`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Stmt stmt) {
  // E.g. `a` or `a()` where `a` is a `Decl`. This also covers things like
  // `a + b` where `+` is a `T::operator+`.
  if (auto dre = pasta::DeclRefExpr::From(stmt)) {
    co_yield dre->Declaration();

  // `foo->bar`, mark `bar` as being referenced. `foo` will be handled as
  // a `DeclRefExpr`.
  } else if (auto me = pasta::MemberExpr::From(stmt)) {
    co_yield me->MemberDeclaration();

  // If we have `a = X()` for class name `X`, then mark the constructor as
  // used in this fragment.
  } else if (auto ce = pasta::CXXConstructExpr::From(stmt)) {
    co_yield ce->Constructor();

  // If we have `new T`, then mark `T` as being referenced in this fragment.
  } else if (auto cxx_new = pasta::CXXNewExpr::From(stmt)) {
    for (auto ref : DeclReferencesFrom(cxx_new->AllocatedType())) {
      co_yield ref;
    }

    co_yield cxx_new->OperatorNew();

  // If we have `delete x`, then mark `` as being referenced in this fragment.
  } else if (auto cxx_del = pasta::CXXDeleteExpr::From(stmt)) {
    co_yield cxx_del->OperatorDelete();

  // If we have `(T *) b` then mark `T` as being referenced in this fragment.
  } else if (auto cast = pasta::CastExpr::From(stmt)) {

    // TODO(pag): If we want to allow implicit casts, then update
    //            `ReferenceIterator::Advance`.
    if (stmt.Kind() != pasta::StmtKind::kImplicitCastExpr) {
      if (auto tt = cast->Type()) {
        for (auto ref : DeclReferencesFrom(tt.value())) {
          co_yield ref;
        }
      }
    }

  // If we have `sizeof(T)` or `alignof(T)` or something like these then
  // mark `T` as being referenced in this fragment.
  } else if (auto unary = pasta::UnaryExprOrTypeTraitExpr::From(stmt)) {
    if (auto arg_type = unary->ArgumentType()) {
      for (auto ref : DeclReferencesFrom(arg_type.value())) {
        co_yield ref;
      }
    }

  // XREF(pag): Issue #185. Make sure we record references to labels.
  } else if (auto goto_ = pasta::GotoStmt::From(stmt)) {
    co_yield goto_->Label();

  } else if (auto addr_label = pasta::AddrLabelExpr::From(stmt)) {
    co_yield addr_label->Label();
  }
}

#define GEN(x) for (auto ref : DeclReferencesFrom(x)) { co_yield ref; }

// Try to find the `Decl` referenced by a particular `type`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Type type) {
  switch (type.Kind()) {
    case pasta::TypeKind::kAdjusted:
    case pasta::TypeKind::kDecayed: {
      auto &tt = reinterpret_cast<const pasta::AdjustedType &>(type);
      GEN(tt.OriginalType());
      break;
    }
    case pasta::TypeKind::kConstantArray: {
      auto &tt = reinterpret_cast<const pasta::ConstantArrayType &>(type);
      if (auto expr = tt.SizeExpression()) {
        GEN(expr.value());
      }
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kDependentSizedArray: {
      auto &tt = reinterpret_cast<const pasta::DependentSizedArrayType &>(type);
      GEN(tt.SizeExpression());
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kIncompleteArray:
    case pasta::TypeKind::kVariableArray: {
      auto &tt = reinterpret_cast<const pasta::ArrayType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kAtomic: {
      auto &tt = reinterpret_cast<const pasta::AtomicType &>(type);
      GEN(tt.ValueType());
      break;
    }
    case pasta::TypeKind::kAttributed: {
      auto &tt = reinterpret_cast<const pasta::AttributedType &>(type);
      GEN(tt.EquivalentType());
      break;
    }
    case pasta::TypeKind::kBTFTagAttributed: {
      auto &tt = reinterpret_cast<const pasta::BTFTagAttributedType &>(type);
      GEN(tt.WrappedType());
      break;
    }
    case pasta::TypeKind::kBitInt: {
      break;
    }
    case pasta::TypeKind::kBlockPointer: {
      auto &tt = reinterpret_cast<const pasta::BlockPointerType &>(type);
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kBuiltin: {
      break;
    }
    case pasta::TypeKind::kComplex: {
      auto &tt = reinterpret_cast<const pasta::ComplexType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kDecltype: {
      auto &tt = reinterpret_cast<const pasta::DecltypeType &>(type);
      GEN(tt.UnderlyingType());
      GEN(tt.UnderlyingExpression());
      break;
    }
    case pasta::TypeKind::kAuto:
    case pasta::TypeKind::kDeducedTemplateSpecialization: {
      auto &tt = reinterpret_cast<const pasta::DeducedType &>(type);
      if (auto dt = tt.ResolvedType()) {
        GEN(dt.value());
      }
      break;
    }
    case pasta::TypeKind::kDependentAddressSpace: {
      auto &tt = reinterpret_cast<const pasta::DependentAddressSpaceType &>(type);
      GEN(tt.AddressSpaceExpression());
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kDependentBitInt: {
      auto &tt = reinterpret_cast<const pasta::DependentBitIntType &>(type);
      GEN(tt.NumBitsExpression());
      break;
    }
    case pasta::TypeKind::kDependentName: {
      break;
    }
    case pasta::TypeKind::kDependentSizedExtVector: {
      auto &tt = reinterpret_cast<const pasta::DependentSizedExtVectorType &>(type);
      GEN(tt.SizeExpression());
      GEN(tt.ElementType());
      break;
    }

    // TODO(pag): Reference template arguments?
    case pasta::TypeKind::kDependentTemplateSpecialization: {
      break;
    }
    case pasta::TypeKind::kDependentVector: {
      auto &tt = reinterpret_cast<const pasta::DependentVectorType &>(type);
      GEN(tt.SizeExpression());
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kElaborated: {
      auto &tt = reinterpret_cast<const pasta::ElaboratedType &>(type);
      GEN(tt.NamedType());
      break;
    }
    case pasta::TypeKind::kFunctionNoProto: {
      auto &tt = reinterpret_cast<const pasta::FunctionNoProtoType &>(type);
      GEN(tt.ReturnType());
      break;
    }
    case pasta::TypeKind::kFunctionProto: {
      auto &tt = reinterpret_cast<const pasta::FunctionProtoType &>(type);
      GEN(tt.ReturnType());
      if (auto esd = tt.ExceptionSpecDeclaration()) {
        co_yield esd.value();
      }
      if (auto est = tt.ExceptionSpecTemplate()) {
        co_yield est.value();
      }
      if (auto nee = tt.NoexceptExpression()) {
        GEN(nee.value());
      }
      for (auto pt : tt.ParameterTypes()) {
        GEN(pt);
      }
      for (auto et : tt.ExceptionTypes()) {
        GEN(et);
      }
      break;
    }
    // TODO(pag): Think more about these.
    case pasta::TypeKind::kInjectedClassName: {
      auto &tt = reinterpret_cast<const pasta::InjectedClassNameType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kMacroQualified: {
      auto &tt = reinterpret_cast<const pasta::MacroQualifiedType &>(type);
      GEN(tt.UnderlyingType());
      break;
    }
    case pasta::TypeKind::kConstantMatrix: {
      break;
    }
    case pasta::TypeKind::kDependentSizedMatrix: {
      auto &tt = reinterpret_cast<const pasta::DependentSizedMatrixType &>(type);
      GEN(tt.ColumnExpression());
      GEN(tt.RowExpression());
      break;
    }
    case pasta::TypeKind::kMemberPointer: {
      auto &tt = reinterpret_cast<const pasta::MemberPointerType &>(type);
      GEN(tt.Class());
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kObjCObjectPointer: {
      auto &tt = reinterpret_cast<const pasta::ObjCObjectPointerType &>(type);
      GEN(tt.ObjectType());
      GEN(tt.PointeeType());
      for (auto arg : tt.TypeArgumentsAsWritten()) {
        GEN(arg);
      }

      // TODO(pag): Include these?
      for (auto arg : tt.Qualifiers()) {
        GEN(arg);
      }
      for (auto arg : tt.Protocols()) {
        GEN(arg);
      }
      break;
    }
    case pasta::TypeKind::kObjCObject: {
      auto &tt = reinterpret_cast<const pasta::ObjCObjectType &>(type);
      co_yield tt.Interface();
      if (auto sct = tt.SuperClassType()) {
        GEN(sct.value());  // TODO(pag): Include this?
      }
      for (auto arg : tt.TypeArgumentsAsWritten()) {
        GEN(arg);
      }
      // TODO(pag): Other methods?
      break;
    }
    case pasta::TypeKind::kObjCInterface: {
      auto &tt = reinterpret_cast<const pasta::ObjCInterfaceType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kObjCTypeParam: {
      auto &tt = reinterpret_cast<const pasta::ObjCTypeParamType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kPackExpansion: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kParen: {
      auto &tt = reinterpret_cast<const pasta::ParenType &>(type);
      GEN(tt.InnerType());
      break;
    }
    case pasta::TypeKind::kPipe: {
      auto &tt = reinterpret_cast<const pasta::PipeType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kPointer: {
      auto &tt = reinterpret_cast<const pasta::PointerType &>(type);
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kLValueReference:
    case pasta::TypeKind::kRValueReference: {
      auto &tt = reinterpret_cast<const pasta::ReferenceType &>(type);
      GEN(tt.PointeeTypeAsWritten());
      break;
    }
    case pasta::TypeKind::kSubstTemplateTypeParmPack: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kSubstTemplateTypeParm: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kEnum: {
      auto &tt = reinterpret_cast<const pasta::EnumType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kRecord: {
      auto &tt = reinterpret_cast<const pasta::RecordType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kTemplateSpecialization: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kTemplateTypeParm: {
      auto &tt = reinterpret_cast<const pasta::TemplateTypeParmType &>(type);
      if (auto d = tt.Declaration()) {
        co_yield d.value();
      }
      break;
    }
    case pasta::TypeKind::kTypeOfExpr: {
      auto &tt = reinterpret_cast<const pasta::TypeOfExprType &>(type);
      GEN(tt.UnderlyingExpression());
      break;
    }
    case pasta::TypeKind::kTypeOf: {
      auto &tt = reinterpret_cast<const pasta::TypeOfType &>(type);
      GEN(tt.UnderlyingType());
      break;
    }
    case pasta::TypeKind::kTypedef: {
      auto &tt = reinterpret_cast<const pasta::TypedefType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kUnaryTransform: {
      auto &tt = reinterpret_cast<const pasta::UnaryTransformType &>(type);
      GEN(tt.UnderlyingType());
      break;
    }
    case pasta::TypeKind::kUnresolvedUsing: {
      auto &tt = reinterpret_cast<const pasta::UnresolvedUsingType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kUsing: {
      auto &tt = reinterpret_cast<const pasta::UsingType &>(type);
      co_yield tt.FoundDeclaration();
      break;
    }
    case pasta::TypeKind::kVector: {
      auto &tt = reinterpret_cast<const pasta::VectorType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kExtVector: {
      auto &tt = reinterpret_cast<const pasta::ExtVectorType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kQualified: {
      auto &tt = reinterpret_cast<const pasta::QualifiedType &>(type);
      GEN(tt.UnqualifiedType());
      break;
    }
  }
}

// Try to identify the declaration referenced by a statement.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Stmt &stmt) {
  
  // E.g. `a` or `a()` where `a` is a `Decl`. This also covers things like
  // `a + b` where `+` is a `T::operator+`.
  if (auto dre = pasta::DeclRefExpr::From(stmt)) {
    return dre->Declaration();

  // `foo->bar`, mark `bar` as being referenced. `foo` will be handled as
  // a `DeclRefExpr`.
  } else if (auto me = pasta::MemberExpr::From(stmt)) {
    return me->MemberDeclaration();
  
  // If we have `a = X()` for class name `X`, then mark the constructor as
  // used in this fragment.
  } else if (auto ce = pasta::CXXConstructExpr::From(stmt)) {
    return ce->Constructor();
  
  // If we have `new T`, then mark `T` as being referenced in this fragment.
  } else if (auto cxx_new = pasta::CXXNewExpr::From(stmt)) {
    return cxx_new->OperatorNew();

  // If we have `delete x`, then mark `the `operator delete`` as being
  // referenced in this fragment.
  } else if (auto cxx_del = pasta::CXXDeleteExpr::From(stmt)) {
    return cxx_del->OperatorDelete();
  
  // If we have `(T *) b` then mark `T` as being referenced in this fragment.
  } else if (auto cast = pasta::CastExpr::From(stmt)) {

    // TODO(pag): If we want to allow implicit casts, then update
    //            `ReferenceIterator::Advance`.
    if (stmt.Kind() != pasta::StmtKind::kImplicitCastExpr) {
      if (auto casted_type = cast->Type()) {
        if (auto used_decl = ReferencedDecl(casted_type.value())) {
          return used_decl.value();
        }
      }
    }
  
  // If we have `sizeof(T)` or `alignof(T)` or something like these then
  // mark `T` as being referenced in this fragment.
  } else if (auto unary = pasta::UnaryExprOrTypeTraitExpr::From(stmt)) {
    if (auto arg_type = unary->ArgumentType()) {
      if (auto used_decl = ReferencedDecl(arg_type.value())) {
        return used_decl.value();
      }
    }

  // XREF(pag): Issue #185. Make sure we record references to labels.
  } else if (auto goto_ = pasta::GotoStmt::From(stmt)) {
    return goto_->Label();

  } else if (auto addr_label = pasta::AddrLabelExpr::From(stmt)) {
    return addr_label->Label();
  }

  return std::nullopt;
}

namespace {

static mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::MacroToken &tok, bool &found,
    RelatedEntityIds &related_ids);

static mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::Token &token, bool &found,
    RelatedEntityIds &related_ids);

static mx::RawEntityId RelatedEntityIdToDerived(
    const EntityMapper &em, const pasta::Token &token, bool &found,
    RelatedEntityIds &related_ids) {

  mx::RawEntityId eid = mx::kInvalidEntityId;

  if (std::optional<pasta::Token> dtok = token.DerivedLocation()) {
    eid = RelatedEntityId(em, dtok.value(), found, related_ids);
  }
  return eid;
}

static std::optional<pasta::Decl> VisitStmt(const pasta::Stmt &stmt,
                                            const pasta::Token &token) {
  if (auto dre = pasta::DeclRefExpr::From(stmt)) {
    if (auto named_decl = pasta::NamedDecl::From(dre->Declaration())) {
      if (dre->ExpressionToken().RawToken() == token.RawToken()) {
        return named_decl;
      }
    }
  } else if (auto me = pasta::MemberExpr::From(stmt)) {
    auto member_decl = me->MemberDeclaration();
    if (me->MemberToken().RawToken() == token.RawToken()) {
      return member_decl;
    } else {
      return VisitStmt(me->Base(), token);
    }
  } else if (auto ce = pasta::CXXConstructExpr::From(stmt)) {
    auto constructor_decl = ce->Constructor();
    if (ce->Token().RawToken() == token.RawToken()) {
      return constructor_decl;
    }
  } else if (auto gt = pasta::GotoStmt::From(stmt)) {
    if (gt->LabelToken().RawToken() == token.RawToken()) {
      return gt->Label();
    }
  } else if (auto di = pasta::DesignatedInitExpr::From(stmt)) {
    // TODO(pag): need support in pasta.

  } else if (auto ili = pasta::InitListExpr::From(stmt)) {
    // TODO(pag): Issue #192.

  } else if (auto ls = pasta::LabelStmt::From(stmt)) {
    if (ls->IdentifierToken().RawToken() == token.RawToken()) {
      return ls->Declaration();
    }

  // Backup.
  } else if (auto call = pasta::CallExpr::From(stmt)) {
    if (call->ExpressionToken().RawToken() == token.RawToken()) {
      if (auto called_decl = call->CalleeDeclaration()) {
        return called_decl;
      }
    }
  }

  return std::nullopt;
}

static std::optional<pasta::Decl> VisitType(const pasta::Type &type,
                                            const pasta::Token &token) {
  if (auto typedef_type = pasta::TypedefType::From(type)) {
    auto typedef_decl = typedef_type->Declaration();
    if (typedef_decl.Name() == token.Data()) {
      return typedef_decl;
    }

  } else if (auto tag_type = pasta::TagType::From(type)) {
    auto tag_decl = tag_type->Declaration();
    if (tag_decl.Name() == token.Data()) {
      return tag_decl;
    }

  } else if (auto deduced_type = pasta::DeducedType::From(type)) {
    return VisitType(deduced_type.value(), token);

  } else if (auto unqual_type = type.UnqualifiedType();
             unqual_type.RawType() != type.RawType()) {
    return VisitType(unqual_type, token);
  }

  return std::nullopt;
}

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::Token &token, bool &found,
    RelatedEntityIds &related_ids) {

  const void *self = token.RawToken();
  if (auto it = related_ids.find(self); it != related_ids.end()) {
    found = true;
    assert(it->second != mx::kInvalidEntityId);
    return it->second;
  }

  std::optional<pasta::Decl> related_decl;

  switch (mx::FromPasta(token.Kind())) {
    default:
      goto fallback;

    case mx::TokenKind::L_SQUARE:
    case mx::TokenKind::R_SQUARE:
    case mx::TokenKind::L_PARENTHESIS:
    case mx::TokenKind::R_PARENTHESIS:
    case mx::TokenKind::L_BRACE_TOKEN:
    case mx::TokenKind::R_BRACE_TOKEN:
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
    case mx::TokenKind::IDENTIFIER: break;
  }

  for (auto context = token.Context(); !related_decl && context;
       context = context->Parent()) {
    switch (context->Kind()) {
      case pasta::TokenContextKind::kStmt:
        if (std::optional<pasta::Stmt> stmt =
                pasta::Stmt::From(context.value())) {
          related_decl = VisitStmt(stmt.value(), token);
        }
        break;
      case pasta::TokenContextKind::kType:
        related_decl = VisitType(
            pasta::Type::From(context.value()).value(),
            token);
        break;
      case pasta::TokenContextKind::kDecl:
        if (std::optional<pasta::Decl> decl =
                pasta::Decl::From(context.value())) {
          if (auto nd = pasta::NamedDecl::From(decl.value());
              nd && nd->Name() == token.Data()) {
            related_decl = nd.value();
          }
          if (!related_decl &&
              decl->Token().RawToken() == self) {
            related_decl = std::move(decl);
          }
        }
        break;
      case pasta::TokenContextKind::kAttr:
        if (std::optional<pasta::Attr> attr =
                pasta::Attr::From(context.value()).value();
            attr && attr->Token().RawToken() == self) {
          return mx::kInvalidEntityId;
        }
        break;
      case pasta::TokenContextKind::kDesignator:
        if (std::optional<pasta::Designator> d =
                pasta::Designator::From(context.value())) {
          if (d->FieldToken().RawToken() == self) {
            if (auto field = d->Field()) {
              related_decl = field.value();
              break;
            }
          }
        }
        break;

      default:
        break;
    }
  }

  if (related_decl) {
    if (auto eid = em.EntityId(related_decl.value());
        eid != mx::kInvalidEntityId) {
      related_ids.emplace(self, eid);
      found = true;
      return eid;
    }
  }

fallback:
  if (auto mtok = token.MacroLocation()) {
    auto eid = RelatedEntityId(em, mtok.value(), found, related_ids);
    if (found) {
      assert(eid != mx::kInvalidEntityId);
      related_ids.emplace(self, eid);
    }
    return eid;
  } else {
    auto eid = RelatedEntityIdToDerived(em, token, found, related_ids);
    if (found) {
      assert(eid != mx::kInvalidEntityId);
      related_ids.emplace(self, eid);
    }
    return eid;
  }
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

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::MacroToken &mtok, bool &found,
    RelatedEntityIds &related_ids) {

  auto tok = mtok.ParsedLocation();
  if (auto it = related_ids.find(tok.RawToken()); it != related_ids.end()) {
    found = true;
    return it->second;
  }

  pasta::TokenKind tk = mtok.TokenKind();
  bool is_definable_name = IsDefinableToken(tk);

  // In the good case, we have:
  //
  //     EXP_0
  //     /   \
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
  // try to deal with the former case.
  std::optional<unsigned> child_index;

  auto self = mtok.RawMacro();
  auto parent = mtok.Parent();
  while (parent) {  // NOTE(pag): We don't ascend, we just want `break`ability.

    // Figure out if we're inside of the expansion side.
    auto index = 0u;
    for (pasta::Macro child : parent->Children()) {
      if (child.RawMacro() == self) {
        child_index.emplace(index);
        break;
      }
      ++index;
    }

    // Only let us find the first thing, i.e. the macro name.
    if (!child_index.has_value() || index) {
      break;
    }

    if (auto exp = pasta::MacroExpansion::From(parent.value())) {

      // If the macro token is the name of the macro definition used, then
      // make the related entity be the defined macro itself.
      if (auto def = exp->Definition(); def && is_definable_name) {
        if (auto name = def->Name(); name && name->Data() == mtok.Data()) {
          if (mx::RawEntityId eid = em.EntityId(def.value());
              eid != mx::kInvalidEntityId) {
            found = true;
            return eid;
          }
        }
      }

      // If it's the first token in an expansion, then reference the expansion
      // instead. Sometimes we have macro expansions but no definitions.
      if (mx::RawEntityId eid = em.EntityId(exp.value());
          eid != mx::kInvalidEntityId && is_definable_name) {
        found = true;
        return eid;
      }

    // If it's the first token in a substitution, and if the token is an
    // identifier name, then reference the substitution itself.
    } else if (auto sub = pasta::MacroSubstitution::From(parent.value())) {
      if (mx::RawEntityId eid = em.EntityId(sub.value());
          eid != mx::kInvalidEntityId && is_definable_name) {
        found = true;
        return eid;
      }

    // It's a macro parameter.
    } else if (auto param = pasta::MacroParameter::From(parent.value())) {
      if (mx::RawEntityId eid = em.EntityId(param.value());
          eid != mx::kInvalidEntityId &&
          (is_definable_name || tk == pasta::TokenKind::kEllipsis)) {
        found = true;
        return eid;
      }

    // Point the defined macro name at the macro itself.
    } else if (auto def = pasta::DefineMacroDirective::From(parent.value())) {
      if (auto name = def->Name(); name && is_definable_name) {
        if (name->RawMacro() == self) {
          if (mx::RawEntityId eid = em.EntityId(def.value());
              eid != mx::kInvalidEntityId) {
            found = true;
            return eid;
          }
        }
      }
    }

    // Point the macro directive at the macro itself.
    if (auto dir = pasta::MacroDirective::From(parent.value())) {
      if (auto dir_name = dir->DirectiveName(); dir_name && is_definable_name) {
        if (dir_name->RawMacro() == self) {
          if (mx::RawEntityId eid = em.EntityId(dir.value());
              eid != mx::kInvalidEntityId) {
            found = true;
            return eid;
          }
        }
      }
    }
    break;
  }

  // If it's a header name then we're probably inside of the substitution of
  // sequence of tokens for a header name, and that is inside of an inclusion
  // directive, so we want to point at the included file.
  if (tk == pasta::TokenKind::kHeaderName) {
    for (; parent; parent = parent->Parent()) {
      if (auto inc = pasta::IncludeLikeMacroDirective::From(parent.value())) {
        if (auto file = inc->IncludedFile()) {
          if (mx::RawEntityId eid = em.EntityId(file.value());
              eid != mx::kInvalidEntityId) {
            found = true;
            return eid;
          }
        }
      }
    }
  }

  return RelatedEntityIdToDerived(em, tok, found, related_ids);
}

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

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::Token &tok,
    RelatedEntityIds &related_ids) {
  bool found = false;
  auto eid = RelatedEntityId(em, tok, found, related_ids);
  if (!found) {
    return eid;
  }

  // Back-propagate.
  if (auto dloc = tok.DerivedLocation()) {
    auto prop_eid = eid;
    do {
      found = false;
      auto eid_dloc = RelatedEntityId(em, dloc.value(), found, related_ids);
      if (found) {
        prop_eid = eid_dloc;
      }
      if (prop_eid != mx::kInvalidEntityId) {
        related_ids.emplace(dloc->RawToken(), prop_eid);
      }
      dloc = dloc->DerivedLocation();
    } while (dloc);
  }

  return eid;
}

// Find the entity ID of the declaration that is most related to a particular
// token.
mx::RawEntityId RelatedEntityId(
    const EntityMapper &em, const pasta::MacroToken &tok,
    RelatedEntityIds &related_ids) {
  return RelatedEntityId(em, tok.ParsedLocation(), related_ids);
}

std::string GetSerializedData(capnp::MessageBuilder &builder) {
  std::string ret;
  ret.reserve(builder.sizeInWords() * sizeof(capnp::word));
  StringOutputStream os(ret);
  capnp::writeMessage(os, builder);

  // Pad it to a multiple of the word size.
  while (ret.size() % sizeof(capnp::word)) {
    ret.push_back('\0');
  }

  return ret;
}

}  // namespace indexer
