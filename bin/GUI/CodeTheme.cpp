// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeTheme.h"

#include <QColor>

#include <multiplier/AST.h>
#include <multiplier/Index.h>
#include <multiplier/Token.h>
#include <mutex>
#include <unordered_map>

namespace mx::gui {
namespace {

static QColor InvertColor(const QColor &color) {
  auto red = 1.0f - color.redF();
  auto green = 1.0f - color.greenF();
  auto blue = 1.0f - color.blueF();
  return QColor::fromRgbF(red, green, blue);
}

class PetersTheme final : public CodeTheme {
 public:
  PetersTheme(void) = default;

  virtual ~PetersTheme(void) = default;

  // Prepare this theme for use. This may be called multiple times.
  void BeginTokens(void) const final {}
  void EndTokens(void) const final {}

  int NumSpacesInTab(void) const final {
    return 2;
  }

  bool LineWrap(void) const final {
    return false;
  }

  // Text color of line numbers.
  const QBrush &LineNumberForegroundColor(void) const final {
    static const QBrush kColor(QColor::fromRgb(115, 139, 148));
    return kColor;
  }

  // Background color of line numbers.
  QColor LineNumberBackgroundColor(void) const final {
    return QColor::fromRgb(30, 30, 30);
  }

  const QBrush &TokenBackgroundColor(
      const Token &, const std::vector<Decl> &, TokenCategory) const final {
    static const QBrush kColor(BackgroundColor());
    return kColor;
  }

  const QBrush &TokenForegroundColor(
      const Token &tok, const std::vector<Decl> &related_decls,
      TokenCategory kind) const final {

    switch (kind) {
      default:
        assert(false);
        [[clang::fallthrough]];
      case TokenCategory::kUnknown: {
        static const QBrush kColor(QColor::fromRgb(20, 20, 20));
        return kColor;
      }
      case TokenCategory::kIdentifier: {
        static const QBrush kColor(QColor::fromRgb(114, 114, 114));
        return kColor;
      }
      case TokenCategory::kMacroName: {
        static const QBrush kColor(QColor::fromRgb(121, 244, 241));
        return kColor;
      }
      case TokenCategory::kKeyword: {
        static const QBrush kColor(QColor::fromRgb(181, 116, 122));
        return kColor;
      }
      case TokenCategory::kObjectiveCKeyword: {
        static const QBrush kColor(QColor::fromRgb(181, 116, 122));
        return kColor;
      }
      case TokenCategory::kPreProcessorKeyword: {
        static const QBrush kColor(QColor::fromRgb(114, 111, 58));
        return kColor;
      }
      case TokenCategory::kBuiltinTypeName: {
        static const QBrush kColor(QColor::fromRgb(115, 61, 60));
        return kColor;
      }
      case TokenCategory::kPunctuation: {
        static const QBrush kColor(QColor::fromRgb(93, 93, 93));
        return kColor;
      }
      case TokenCategory::kLiteral: {
        static const QBrush kColor(QColor::fromRgb(226, 211, 148));
        return kColor;
      }
      case TokenCategory::kComment: {
        static const QBrush kColor(QColor::fromRgb(105, 104, 97));
        return kColor;
      }
      case TokenCategory::kLocalVariable: {
        static const QBrush kColor(QColor::fromRgb(198, 125, 237));
        return kColor;
      }
      case TokenCategory::kGlobalVariable: {
        static const QBrush kColor(QColor::fromRgb(198, 163, 73));
        return kColor;
      }
      case TokenCategory::kParameterVariable: {
        static const QBrush kColor(QColor::fromRgb(172, 122, 180));
        return kColor;
      }
      case TokenCategory::kInstanceMethod:
      case TokenCategory::kFunction: {
        static const QBrush kDefColor(QColor::fromRgb(126, 125, 186));
        static const QBrush kUseOfDefColor(QColor::fromRgb(97, 142, 149));
        static const QBrush kUseOfDeclColor(QColor::fromRgb(168, 82, 226));
        auto use_color = &kUseOfDeclColor;
        for (const Decl &decl : related_decls) {
          for (const Decl &redecl : decl.redeclarations()) {
            if (auto file_tok = redecl.token().file_token();
                file_tok && file_tok->id() == tok.id()) {
              return kDefColor;
            } else if (redecl.is_definition()) {
              use_color = &kUseOfDefColor;
            }
          }
        }
        return *use_color;
      }
      case TokenCategory::kInstanceMember: {
        static const QBrush kColor(QColor::fromRgb(207, 130, 235));
        return kColor;
      }
      case TokenCategory::kClassMethod: {
        static const QBrush kColor(QColor::fromRgb(170, 129, 52));
        return kColor;
      }
      case TokenCategory::kClassMember: {
        static const QBrush kColor(QColor::fromRgb(170, 129, 52));
        return kColor;
      }
      case TokenCategory::kThis: {
        static const QBrush kColor(QColor::fromRgb(181, 116, 122));
        return kColor;
      }
      case TokenCategory::kClass: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case TokenCategory::kStruct: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case TokenCategory::kUnion: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case TokenCategory::kInterface: {
        static const QBrush kColor(QColor::fromRgb(0, 177, 110));
        return kColor;
      }
      case TokenCategory::kEnum: {
        static const QBrush kColor(QColor::fromRgb(175, 144, 65));
        return kColor;
      }
      case TokenCategory::kEnumerator: {
        static const QBrush kColor(QColor::fromRgb(113, 163, 98));
        return kColor;
      }
      case TokenCategory::kNamespace: {
        static const QBrush kColor(QColor::fromRgb(95, 154, 160));
        return kColor;
      }
      case TokenCategory::kTypeAlias: {
        static const QBrush kColor(QColor::fromRgb(3, 171, 108));
        return kColor;
      }
      case TokenCategory::kTemplateParameterType: {
        static const QBrush kColor(QColor::fromRgb(198, 117, 29));
        return kColor;
      }
      case TokenCategory::kTemplateParameterValue: {
        static const QBrush kColor(QColor::fromRgb(174, 144, 65));
        return kColor;
      }
      case TokenCategory::kLabel: {
        static const QBrush kColor(QColor::fromRgb(149, 149, 149));
        return kColor;
      }
      case TokenCategory::kWhitespace: {
        static const QBrush kColor;
        return kColor;
      }
    }
  }

  TokenFormat Format(
      const Token &, const std::vector<Decl> &,
      TokenCategory kind) const final {
    TokenFormat format = {false, false, false};
    switch (kind) {
      case TokenCategory::kPreProcessorKeyword:
      case TokenCategory::kTypeAlias:
      case TokenCategory::kClass:
      case TokenCategory::kStruct:
      case TokenCategory::kUnion:
      case TokenCategory::kInterface:
      case TokenCategory::kFunction:
      case TokenCategory::kInstanceMethod:
        format.bold = true;
        break;
      case TokenCategory::kGlobalVariable:
      case TokenCategory::kClassMethod:
        format.italic = true;
        format.bold = true;
        break;
      case TokenCategory::kEnumerator:
      case TokenCategory::kClassMember:
      case TokenCategory::kTemplateParameterValue:
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
      assert(font.family() == "Source Code Pro");
    }
    return font;
  }

  QColor BackgroundColor(void) const final {
    return QColor::fromRgb(20, 20, 20);
  }

  QColor SelectedLineBackgroundColor(unsigned group) const final {

    static constexpr unsigned mul[3][3] = {
        {10, 15, 20},
        {15, 20, 10},
        {20, 10, 15}
    };

    return QColor::fromRgb(
        static_cast<int>(std::min(255u, group * mul[group % 3u][0u])),
        static_cast<int>(std::min(255u, group * mul[group % 3u][1u])),
        static_cast<int>(std::min(255u, group * mul[group % 3u][2u])));
  }
};

}  // namespace

CodeTheme::~CodeTheme(void) {}

const CodeTheme &CodeTheme::DefaultTheme(void) {
  static const PetersTheme kTheme;
  return kTheme;
}

ProxyCodeTheme::~ProxyCodeTheme(void) {}

// Prepare this theme for use. This may be called multiple times.
void ProxyCodeTheme::BeginTokens(void) const {
  next.BeginTokens();
}

void ProxyCodeTheme::EndTokens(void) const {
  next.EndTokens();
}

// The code font to be used, including its size.
const QFont &ProxyCodeTheme::Font(void) const {
  return next.Font();
}

// Number of spaces in a tab.
int ProxyCodeTheme::NumSpacesInTab(void) const {
  return next.NumSpacesInTab();
}

// Whether or not to wrap lines.
bool ProxyCodeTheme::LineWrap(void) const {
  return next.LineWrap();
}

// Text color of line numbers.
const QBrush &ProxyCodeTheme::LineNumberForegroundColor(void) const {
  return next.LineNumberForegroundColor();
}

// Background color of line numbers.
QColor ProxyCodeTheme::LineNumberBackgroundColor(void) const {
  return next.LineNumberBackgroundColor();
}

// Background color of the code area.
QColor ProxyCodeTheme::BackgroundColor(void) const {
  return next.BackgroundColor();
}

// The color to use as a highlight for the line containing the cursor.
QColor ProxyCodeTheme::SelectedLineBackgroundColor(unsigned group) const {
  return next.SelectedLineBackgroundColor(group);
}

// Background color for a specific token.
const QBrush &ProxyCodeTheme::TokenBackgroundColor(
    const Token &tok, const std::vector<Decl> &related_decls,
    TokenCategory kind) const {
  return next.TokenBackgroundColor(tok, related_decls, kind);
}

// Text color of a specific token.
const QBrush &ProxyCodeTheme::TokenForegroundColor(
    const Token &tok, const std::vector<Decl> &related_decls,
    TokenCategory kind) const {
  return next.TokenForegroundColor(tok, related_decls, kind);
}

// Format (bold, italic, underline) for a specific token.
TokenFormat ProxyCodeTheme::Format(
    const Token &tok, const std::vector<Decl> &related_decls,
    TokenCategory kind) const {
  return next.Format(tok, related_decls, kind);
}

struct HighlightRangeTheme::PrivateData {
  std::mutex lock;
  TokenRange tokens;
  std::unordered_map<const QBrush *, QBrush> inverted_colors;
  const QColor background;
  const QColor inverted_foreground;

  inline PrivateData(QColor bg_color)
      : background(bg_color),
        inverted_foreground(InvertColor(bg_color)) {}
};

HighlightRangeTheme::HighlightRangeTheme(const CodeTheme &next_)
    : ProxyCodeTheme(next_),
      d(new PrivateData(next_.SelectedLineBackgroundColor())) {}

HighlightRangeTheme::~HighlightRangeTheme(void) {}

// Set the entity to be highlighted.
void HighlightRangeTheme::HighlightFileTokenRange(const TokenRange &range) {
  std::unique_lock<std::mutex> locker(d->lock);
  d->tokens = range;
}

void HighlightRangeTheme::BeginTokens(void) const {
  this->ProxyCodeTheme::BeginTokens();
  d->lock.lock();
  d->inverted_colors.clear();
  d->tokens = d->tokens.file_tokens();
}

void HighlightRangeTheme::EndTokens(void) const {
  d->lock.unlock();
  this->ProxyCodeTheme::EndTokens();
}

// Background color for a specific token.
const QBrush &HighlightRangeTheme::TokenBackgroundColor(
    const Token &tok, const std::vector<Decl> &related_decls,
    TokenCategory kind) const {

  const QBrush &brush = this->ProxyCodeTheme::TokenBackgroundColor(
      tok, related_decls, kind);

  // If it's one of the tokens in our range, then invert its background color.
  if (d->tokens.index_of(tok)) {
    QBrush brush_inv(d->background, brush.style());
    return d->inverted_colors.emplace(&brush, brush_inv).first->second;
  } else {
    return brush;
  }
}

// Foreground color for a specific token.
const QBrush &HighlightRangeTheme::TokenForegroundColor(
    const Token &tok, const std::vector<Decl> &related_decls,
    TokenCategory kind) const {
  const QBrush &brush = this->ProxyCodeTheme::TokenForegroundColor(
      tok, related_decls, kind);

  // If it's one of the tokens in our range, then invert its background color.
  if (d->tokens.index_of(tok)) {
    if (brush.color().isValid()) {
      QBrush brush_inv(d->inverted_foreground, brush.style());
      return d->inverted_colors.emplace(&brush, brush_inv).first->second;
    }
  }
  return brush;
}

}  // namespace mx::gui
