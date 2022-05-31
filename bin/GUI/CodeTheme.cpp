// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeTheme.h"

#include <QColor>

#include <multiplier/AST.h>
#include <multiplier/Token.h>


namespace mx::gui {
namespace {

class PetersTheme final : public CodeTheme {
 public:
  PetersTheme(void) = default;

  virtual ~PetersTheme(void) = default;

  int NumSpacesInTable(void) const final {
    return 2;
  }

  bool LineWrap(void) const final {
    return false;
  }

  const QBrush &ForegroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      CodeTokenKind kind) const final {

    switch (kind) {
      case CodeTokenKind::kUnknown: {
        static const QBrush kColor(QColor::fromRgb(20, 20, 20));
        return kColor;
      }
      case CodeTokenKind::kIdentifier: {
        static const QBrush kColor(QColor::fromRgb(114, 114, 114));
        return kColor;
      }
      case CodeTokenKind::kMacroName: {
        static const QBrush kColor(QColor::fromRgb(121, 244, 241));
        return kColor;
      }
      case CodeTokenKind::kKeyword: {
        static const QBrush kColor(QColor::fromRgb(181, 116, 122));
        return kColor;
      }
      case CodeTokenKind::kObjectiveCKeyword: {
        static const QBrush kColor(QColor::fromRgb(181, 116, 122));
        return kColor;
      }
      case CodeTokenKind::kPreProcessorKeyword: {
        static const QBrush kColor(QColor::fromRgb(114, 111, 58));
        return kColor;
      }
      case CodeTokenKind::kBuiltinTypeName: {
        static const QBrush kColor(QColor::fromRgb(115, 61, 60));
        return kColor;
      }
      case CodeTokenKind::kPunctuation: {
        static const QBrush kColor(QColor::fromRgb(93, 93, 93));
        return kColor;
      }
      case CodeTokenKind::kLiteral: {
        static const QBrush kColor(QColor::fromRgb(226, 211, 148));
        return kColor;
      }
      case CodeTokenKind::kComment: {
        static const QBrush kColor(QColor::fromRgb(105, 104, 97));
        return kColor;
      }
      case CodeTokenKind::kLocalVariable: {
        static const QBrush kColor(QColor::fromRgb(198, 125, 237));
        return kColor;
      }
      case CodeTokenKind::kGlobalVariable: {
        static const QBrush kColor(QColor::fromRgb(198, 163, 73));
        return kColor;
      }
      case CodeTokenKind::kParameterVariable: {
        static const QBrush kColor(QColor::fromRgb(172, 122, 180));
        return kColor;
      }
      case CodeTokenKind::kInstanceMethod:
      case CodeTokenKind::kFunction: {
        static const QBrush kDefColor(QColor::fromRgb(126, 125, 186));
        static const QBrush kUseOfDefColor(QColor::fromRgb(97, 142, 149));
        static const QBrush kUseOfDeclColor(QColor::fromRgb(168, 82, 226));
        auto use_color = &kUseOfDeclColor;
        for (const Decl &decl : related_decls) {
          if (auto file_tok = decl.token().file_token();
              file_tok && file_tok->id() == tok.id()) {
            return kDefColor;
          } else if (decl.definition()) {
            use_color = &kUseOfDefColor;
          }
        }
        return *use_color;
      }
      case CodeTokenKind::kInstanceMember: {
        static const QBrush kColor(QColor::fromRgb(207, 130, 235));
        return kColor;
      }
      case CodeTokenKind::kClassMethod: {
        static const QBrush kColor(QColor::fromRgb(170, 129, 52));
        return kColor;
      }
      case CodeTokenKind::kClassMember: {
        static const QBrush kColor(QColor::fromRgb(170, 129, 52));
        return kColor;
      }
      case CodeTokenKind::kThis: {
        static const QBrush kColor(QColor::fromRgb(181, 116, 122));
        return kColor;
      }
      case CodeTokenKind::kClass: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case CodeTokenKind::kStruct: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case CodeTokenKind::kUnion: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case CodeTokenKind::kInterface: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case CodeTokenKind::kEnum: {
        static const QBrush kColor(QColor::fromRgb(175, 144, 65));
        return kColor;
      }
      case CodeTokenKind::kEnumerator: {
        static const QBrush kColor(QColor::fromRgb(113, 163, 98));
        return kColor;
      }
      case CodeTokenKind::kNamespace: {
        static const QBrush kColor(QColor::fromRgb(95, 154, 160));
        return kColor;
      }
      case CodeTokenKind::kTypeAlias: {
        static const QBrush kColor(QColor::fromRgb(3, 171, 108));
        return kColor;
      }
      case CodeTokenKind::kTemplateParameterType: {
        static const QBrush kColor(QColor::fromRgb(198, 117, 29));
        return kColor;
      }
      case CodeTokenKind::kTemplateParameterValue: {
        static const QBrush kColor(QColor::fromRgb(174, 144, 65));
        return kColor;
      }
      case CodeTokenKind::kLabel: {
        static const QBrush kColor(QColor::fromRgb(149, 149, 149));
        return kColor;
      }
    }
  }

  TokenFormat Format(
      const Token &, const std::vector<Decl> &,
      CodeTokenKind kind) const final {
    TokenFormat format = {false, false, false};
    switch (kind) {
      case CodeTokenKind::kPreProcessorKeyword:
      case CodeTokenKind::kTypeAlias:
      case CodeTokenKind::kClass:
      case CodeTokenKind::kStruct:
      case CodeTokenKind::kUnion:
      case CodeTokenKind::kInterface:
      case CodeTokenKind::kFunction:
      case CodeTokenKind::kInstanceMethod:
        format.bold = true;
        break;
      case CodeTokenKind::kGlobalVariable:
      case CodeTokenKind::kClassMethod:
        format.italic = true;
        format.bold = true;
        break;
      case CodeTokenKind::kEnumerator:
      case CodeTokenKind::kClassMember:
      case CodeTokenKind::kTemplateParameterValue:
        format.italic = true;
        break;
      default:
        break;
    }
    return format;
  }

  const QFont &Font(void) const final {
    static QFont font("Source Code Pro", 20);
    static bool initialized = false;
    if (!initialized) {
      font.setStyleHint(QFont::TypeWriter);
    }
    return font;
  }

  QColor BackgroundColor(void) const final {
    return QColor::fromRgb(20, 20, 20);
  }
};

}  // namespace

CodeTheme::~CodeTheme(void) {}

const CodeTheme &CodeTheme::DefaultTheme(void) {
  static const PetersTheme kTheme;
  return kTheme;
}

}  // namespace mx::gui
