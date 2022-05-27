// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <memory>
#include <multiplier/Index.h>
#include <QApplication>
#include <QMetaType>

#include "MainWindow.h"

namespace {

void initializeTheme(void) {
#ifdef __APPLE__
  qApp->setStyle("Fusion");
#endif
}

} // namespace

int main(int argc, char *argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);
  QApplication application(argc, argv);

  if (getenv("MX_NO_CUSTOM_THEME") == nullptr) {
    initializeTheme();
  }

  qRegisterMetaType<mx::FilePathList>("FilePathList");
  qRegisterMetaType<mx::Token>("Token");
  qRegisterMetaType<mx::TokenRange>("TokenRange");
  qRegisterMetaType<mx::TokenList>("TokenList");
  qRegisterMetaType<std::optional<mx::File>>("std::optional<File>");
  qRegisterMetaType<std::optional<mx::Fragment>>("std::optional<Fragment>");
  qRegisterMetaType<std::optional<mx::Decl>>("std::optional<Decl>");
  qRegisterMetaType<std::optional<mx::Stmt>>("std::optional<Stmt>");
  qRegisterMetaType<std::optional<mx::Type>>("std::optional<Type>");
  qRegisterMetaType<std::optional<mx::Token>>("std::optional<Token>");
  qRegisterMetaType<std::vector<mx::Fragment>>("std::vector<Fragment>");

  mx::gui::MainWindow main_window;
  main_window.show();

  return application.exec();
}
