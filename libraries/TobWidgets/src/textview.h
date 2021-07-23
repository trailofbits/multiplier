/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <tob/itextmodel.h>
#include <tob/itextview.h>

#include <memory>

#include <QFontMetricsF>
#include <QRectF>

namespace tob::widgets {

class TextView final : public ITextView {
  Q_OBJECT
  Q_INTERFACES(tob::widgets::ITextView)

public:
  TextView(QWidget *parent);
  virtual ~TextView() override;

  virtual void setModel(ITextModel::Ptr model) override;
  virtual void setTheme(const TextViewTheme &theme) override;

  virtual bool hasSelection() const override;
  virtual std::optional<QString> getSelection() override;

protected:
  virtual void resizeEvent(QResizeEvent *event) override;
  virtual void paintEvent(QPaintEvent *event) override;
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  virtual void focusOutEvent(QFocusEvent *event) override;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onModelReset();

public:
  struct TokenEntity final {
    QRectF bounding_box;
    TokenID token_id;
  };

  using TokenEntityList = std::vector<TokenEntity>;
  using TokenEntityRowList = std::vector<TokenEntityList>;

  struct SceneRow final {
    QRectF bounding_box;
    TokenEntityList entity_list;
  };

  using SceneRowList = std::vector<SceneRow>;

  struct Cursor final {
    TokenID token_id;
    std::size_t offset{};
  };

  struct Selection final {
    bool tracking{false};
    Cursor first_cursor;
    Cursor last_cursor;
  };

  using OptionalSelection = std::optional<Selection>;

  struct Scene final {
    SceneRowList row_list;
  };

  using OptionalScene = std::optional<Scene>;

  struct Context final {
    QRectF viewport;
    TextViewTheme theme;

    std::unique_ptr<QFontMetricsF> font_metrics;
    TokenEntityRowList token_index;

    OptionalScene opt_scene;
    OptionalSelection opt_selection;
    bool word_wrap{true};
  };

  static void resizeViewport(Context &context, const QSizeF &size);
  static void moveViewport(Context &context, const QPointF &point);
  static void createTokenIndex(Context &context, ITextModel &model);
  static void resetScene(Context &context);
  static void generateScene(Context &context);
  static std::optional<Cursor> createCursor(Context &context, const QPointF &pos);
  static void sanitizeSelection(Selection &selection);

signals:
  void tokenClicked(const QPoint &mouse_position, const Qt::MouseButton &button, TokenID token_id);
};

} // namespace tob::widgets
