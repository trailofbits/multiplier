// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <optional>
#include <QColor>
#include <QFont>
#include <QBrush>
#include <vector>

namespace mx {
class Decl;
class Index;
class Token;
class TokenRange;
namespace gui {

enum class TokenCategory : unsigned char {
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

  // Extra.
  kWhitespace
};

struct TokenFormat {
  bool bold;
  bool italic;
  bool underline;
};

// Logic for figuring out the color of things.
//
// NOTE(pag): CodeTheme's should be thread-safe.
class CodeTheme {
 protected:
  CodeTheme(void) = default;

 public:
  static const CodeTheme &DefaultTheme(void);

  virtual ~CodeTheme(void);

  // Signal to the theme that it's about to start coloring tokens.
  virtual void BeginTokens(void) const = 0;

  // Signal to the theme that it's about to end coloring tokens.
  virtual void EndTokens(void) const = 0;

  // The code font to be used, including its size.
  virtual const QFont &Font(void) const = 0;

  // Number of spaces in a tab.
  virtual int NumSpacesInTab(void) const = 0;

  // Whether or not to wrap lines.
  virtual bool LineWrap(void) const = 0;

  // Background color of the code area.
  virtual QColor BackgroundColor(void) const = 0;

  // The color to use as a highlight for the line containing the cursor.
  virtual QColor SelectedLineBackgroundColor(unsigned group=0) const = 0;

  // Text color of line numbers.
  virtual const QBrush &LineNumberForegroundColor(void) const = 0;

  // Background color of line numbers.
  virtual QColor LineNumberBackgroundColor(void) const = 0;

  // Background color for a specific token.
  //
  // NOTE(pag): The lifetime of the returned `QBrush` references must match or
  //            exceed the lifetime of theme itself.
  virtual const QBrush &TokenBackgroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const = 0;

  // Text color of a specific token.
  //
  // NOTE(pag): The lifetime of the returned `QBrush` references must match or
  //            exceed the lifetime of theme itself.
  virtual const QBrush &TokenForegroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const = 0;

  // Format (bold, italic, underline) for a specific token.
  virtual TokenFormat Format(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const = 0;
};

class ProxyCodeTheme : public CodeTheme {
 protected:
  const CodeTheme &next;

 public:
  inline explicit ProxyCodeTheme(const CodeTheme &next_)
      : next(next_) {}

  virtual ~ProxyCodeTheme(void);

  // Signal to the theme that it's about to start coloring tokens.
  void BeginTokens(void) const override;

  // Signal to the theme that it's about to end coloring tokens.
  void EndTokens(void) const override;

  // The code font to be used, including its size.
  const QFont &Font(void) const override;

  // Number of spaces in a tab.
  int NumSpacesInTab(void) const override;

  // Whether or not to wrap lines.
  bool LineWrap(void) const override;

  // Text color of line numbers.
  const QBrush &LineNumberForegroundColor(void) const override;

  // Background color of line numbers.
  QColor LineNumberBackgroundColor(void) const override;

  // Background color of the code area.
  QColor BackgroundColor(void) const override;

  // The color to use as a highlight for the line containing the cursor.
  QColor SelectedLineBackgroundColor(unsigned group) const override;

  // Background color for a specific token.
  const QBrush &TokenBackgroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const override;

  // Text color of a specific token.
  const QBrush &TokenForegroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const override;

  // Format (bold, italic, underline) for a specific token.
  TokenFormat Format(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const override;
};

// Wraps around a theme to let us highlight a range of tokens.
class HighlightRangeTheme final : public ProxyCodeTheme {
 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:

  virtual ~HighlightRangeTheme(void);

  HighlightRangeTheme(const CodeTheme &next_);

  // Set the entity to be highlighted.
  void HighlightFileTokenRange(const TokenRange &range_);

  void BeginTokens(void) const override;
  void EndTokens(void) const override;

  // Background color for a specific token.
  const QBrush &TokenBackgroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const override;

  // Foreground color for a specific token.
  const QBrush &TokenForegroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const override;
};

}  // namespace gui
}  // namespace mx
