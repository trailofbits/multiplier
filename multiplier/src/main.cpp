/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "mainwindow.h"

#include <QApplication>

namespace {

QPalette getPalette() {
  QPalette palette;
  palette.setColor(QPalette::WindowText, QColor::fromRgba(0xFFFFFFFF));
  palette.setColor(QPalette::Button, QColor::fromRgba(0xFF424245));
  palette.setColor(QPalette::Light, QColor::fromRgba(0xFF979797));
  palette.setColor(QPalette::Midlight, QColor::fromRgba(0xFF5E5C5B));
  palette.setColor(QPalette::Dark, QColor::fromRgba(0xFF302F2E));
  palette.setColor(QPalette::Mid, QColor::fromRgba(0xFF4A4947));
  palette.setColor(QPalette::Text, QColor::fromRgba(0xFFFFFFFF));
  palette.setColor(QPalette::BrightText, QColor::fromRgba(0xFFFFFFFF));
  palette.setColor(QPalette::ButtonText, QColor::fromRgba(0xFFFFFFFF));
  palette.setColor(QPalette::Base, QColor::fromRgba(0xFF3D3D3D));
  palette.setColor(QPalette::Window, QColor::fromRgba(0xFF222020));
  palette.setColor(QPalette::Shadow, QColor::fromRgba(0xFFE7E4E0));
  palette.setColor(QPalette::Highlight, QColor::fromRgba(0xFF12608A));
  palette.setColor(QPalette::HighlightedText, QColor::fromRgba(0xFFF9F9F9));
  palette.setColor(QPalette::Link, QColor::fromRgba(0xFF0986D3));
  palette.setColor(QPalette::LinkVisited, QColor::fromRgba(0xFFA70B06));
  palette.setColor(QPalette::AlternateBase, QColor::fromRgba(0xFF5C5B5A));
  palette.setColor(QPalette::NoRole, QColor::fromRgba(0xFFFFFFFF));
  palette.setColor(QPalette::ToolTipBase, QColor::fromRgba(0xFF3F3F36));
  palette.setColor(QPalette::ToolTipText, QColor::fromRgba(0xFFFFFFFF));

  return palette;
}

void initializeTheme() {
#ifdef __APPLE__
  qApp->setStyle("Fusion");
#endif

  qApp->setPalette(getPalette());
}

} // namespace

int main(int argc, char *argv[]) {
  QApplication application(argc, argv);
  initializeTheme();

  auto main_window = multiplier::MainWindow::create();
  main_window->show();

  return application.exec();
}
