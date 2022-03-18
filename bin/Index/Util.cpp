// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Util.h"

#include <multiplier/AST.h>
#include <pasta/AST/Forward.h>
#include <pasta/Util/File.h>

namespace indexer {

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
    if (IsWhitespaceOrEmpty(entity.Data())) {
      return mx::TokenKind::WHITESPACE;
    }
  }
  return kind;
}

}  // namespace indexer
