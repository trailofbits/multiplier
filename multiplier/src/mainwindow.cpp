/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "mainwindow.h"

#include <QDebug>

namespace multiplier {

struct MainWindow::PrivateData final {};

MainWindow::Ptr MainWindow::create() { return Ptr(new MainWindow()); }

MainWindow::~MainWindow() {}

MainWindow::MainWindow() : QMainWindow(nullptr), d(new PrivateData) { resize(1920, 1080); }

} // namespace multiplier
