// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <QColor>
#include <QFont>
#include <QBrush>
#include <vector>

namespace mx {
class Decl;
class Token;
namespace gui {

enum class CodeTokenKind : unsigned char {
  // These line up with `TokenClass`.
  kUnknown,
  kIdentifier,
  kMacroName,
  kKeyword,
  kObjectiveCKeyword,
  kPreProcessorKeyword,
  kBuiltinTypeName,
  kPunctuation,
  kLiteral,
  kComment,

  // These line up with `DeclCategory`.
  kLocalVariable,
  kGlobalVariable,
  kParameterVariable,
  kFunction,
  kInstanceMethod,
  kInstanceMember,
  kClassMethod,
  kClassMember,
  kThis,
  kClass,
  kStruct,
  kUnion,
  kInterface,
  kEnum,
  kEnumerator,
  kNamespace,
  kTypeAlias,
  kTemplateParameterType,
  kTemplateParameterValue,
  kLabel,
};

struct TokenFormat {
  bool bold;
  bool italic;
  bool underline;
};

class CodeTheme {
 protected:
  CodeTheme(void) = default;

 public:
  static const CodeTheme &DefaultTheme(void);

  virtual ~CodeTheme(void);

  virtual const QFont &Font(void) const = 0;

  virtual int NumSpacesInTable(void) const = 0;
  virtual bool LineWrap(void) const = 0;

  virtual QColor BackgroundColor(void) const = 0;

  virtual const QBrush &ForegroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      CodeTokenKind kind) const = 0;

  virtual TokenFormat Format(
      const Token &tok, const std::vector<Decl> &related_decls,
      CodeTokenKind kind) const = 0;
};

}  // namespace gui
}  // namespace mx
