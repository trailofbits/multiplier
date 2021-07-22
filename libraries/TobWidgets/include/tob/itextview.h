/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <tob/itextmodel.h>

#include <QFrame>

#include <optional>
#include <unordered_map>

namespace tob::widgets {

struct TextViewTheme final {
  QColor background;
  QColor foreground;
  std::unordered_map<TokenColorID, QColor> color_map;
};

class ITextView : public QFrame {
  Q_OBJECT

public:
  static ITextView *create(QWidget *parent = nullptr);

  ITextView(QWidget *parent) : QFrame(parent) {}
  virtual ~ITextView() = default;

  virtual void setModel(ITextModel::Ptr model) = 0;
  virtual void setTheme(const TextViewTheme &theme) = 0;
  virtual std::optional<QString> getSelection() = 0;

  ITextView(const ITextView &) = delete;
  ITextView &operator=(const ITextView &) = delete;

signals:
  void tokenClicked(const QPoint &mouse_position, const Qt::MouseButton &button, TokenID token_id);
};

} // namespace tob::widgets

Q_DECLARE_INTERFACE(tob::widgets::ITextView, "ITextView")
