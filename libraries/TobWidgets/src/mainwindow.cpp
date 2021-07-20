/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "mainwindow.h"

#include <QDebug>

namespace drgui {

struct MainWindow::PrivateData final {
  TextView *text_view{nullptr};
};

MainWindow::Ptr MainWindow::create() { return Ptr(new MainWindow()); }

MainWindow::~MainWindow() {}

MainWindow::MainWindow() : QMainWindow(nullptr), d(new PrivateData) {
  static TextModel model;
  d->text_view = new TextView(model);
  setCentralWidget(d->text_view);

  TextViewTheme theme;
  theme.background = QColor::fromRgba(0xFF272822);
  theme.foreground = QColor::fromRgba(0xFFf4f4ee);

  theme.color_map.insert({0, QColor::fromRgba(0xFFe59b9b)});
  theme.color_map.insert({1, QColor::fromRgba(0xFF9cd42c)});
  theme.color_map.insert({2, QColor::fromRgba(0xFFf72571)});
  theme.color_map.insert({3, QColor::fromRgba(0xFF9671d9)});
  theme.color_map.insert({4, QColor::fromRgba(0xFFd0d971)});
  theme.color_map.insert({5, QColor::fromRgba(0xFFff0000)});
  theme.color_map.insert({6, QColor::fromRgba(0xFFff6a00)});
  theme.color_map.insert({7, QColor::fromRgba(0xFF00ffe5)});
  theme.color_map.insert({8, QColor::fromRgba(0xFF5c5c5c)});
  theme.color_map.insert({9, QColor::fromRgba(0xFF5a470d)});

  d->text_view->setTheme(theme);

  connect(d->text_view, &TextView::tokenClicked, this, &MainWindow::onTokenClicked);

  resize(1920, 1080);
}

void MainWindow::onTokenClicked(const QPoint mouse_position, const Qt::MouseButton &button,
                                TokenID token_id) {
  qDebug() << "Token" << token_id << "clicked with button" << button << "at coordinates"
           << mouse_position;

  auto opt_selection = d->text_view->getSelection();
  if (!opt_selection.has_value()) {
    return;
  }

  const auto &selection = opt_selection.value();
  qDebug() << "Selection is " << selection;
}

} // namespace drgui
