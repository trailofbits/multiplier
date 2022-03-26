// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "ITextModel.h"

#include <QFontMetricsF>
#include <QFrame>
#include <QRectF>
#include <QWidget>

#include <memory>
#include <optional>
#include <unordered_map>
#include <unordered_set>

namespace mx::gui {

struct TextViewTheme final {
  QFont monospaced_font;
  QColor background;
  QColor foreground;
  QColor line_numbers;
  std::unordered_map<TokenColorId, QColor> color_map;
};

class ITextView : public QFrame {
  Q_OBJECT

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void UpdateScrollbars(void);
  TextViewTheme GetDefaultTheme(void);

 public:
  struct Context;
  struct Cursor;
  struct Selection;

  ITextView(QWidget *parent);
  virtual ~ITextView();

  virtual void SetModel(ITextModel::Ptr model);
  virtual void SetTheme(const TextViewTheme &theme);
  virtual void SetWordWrapping(bool enabled);
  virtual void SetLineNumbers(bool enabled);

  virtual bool HasSelection(void) const;
  virtual std::optional<QString> GetSelection(void) const;

  virtual void HighlightTokenGroups(std::unordered_set<unsigned> new_groups);
  virtual void HighlightTokenGroup(unsigned group_id);
  virtual void DisableTokenGroupHighlight(void);

  ITextView(const ITextView &) = delete;
  ITextView &operator=(const ITextView &) = delete;

 protected:
  virtual void resizeEvent(QResizeEvent *event) override;
  virtual void paintEvent(QPaintEvent *event) override;
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  virtual void focusOutEvent(QFocusEvent *event) override;
  virtual void wheelEvent(QWheelEvent *event) override;
  virtual void keyPressEvent(QKeyEvent *event) override;
  virtual void keyReleaseEvent(QKeyEvent *event) override;

 private:
  static void ScrollViewportTo(Context &context, const QPointF &point);
  static void ResizeViewport(Context &context, const QSizeF &size);
  static void MoveViewport(Context &context, const QPointF &point);
  static void CreateTokenIndex(Context &context, ITextModel &model);
  static void ResetScene(Context &context);
  static void GenerateScene(Context &context, ITextModel &model);
  static std::optional<Cursor> CreateCursor(Context &context, QPointF pos);
  static void SanitizeSelection(Selection &selection);

 signals:
  void TokenClicked(const QPoint &mouse_position,
                    const Qt::MouseButton &button,
                    unsigned token_index);

  void KeyPressed(QKeyEvent *event);
  void KeyReleased(QKeyEvent *event);

 private slots:
  void OnModelReset(void);
  void OnScrollBarValueChange(int);
};

}  // namespace mx::gui

Q_DECLARE_INTERFACE(mx::gui::ITextView, "ITextView")
