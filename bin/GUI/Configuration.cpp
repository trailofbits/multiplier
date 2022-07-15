// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Configuration.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>

#include "CodeTheme.h"

#include <cstdlib>

namespace mx::gui {
namespace {

static void LocateIndexerAndImporter(mx::gui::Configuration &config) {
  QFileInfo exe_path(QCoreApplication::applicationFilePath());
  QFileInfo indexer_path;
  QFileInfo importer_path;

  if (!exe_path.isExecutable()) {
    return;
  }

  config.gui_exe_path = exe_path.absoluteFilePath();

#ifdef __APPLE__
  // macOS application bundle.
  if (config.gui_exe_path.contains(
      QLatin1String(".app/Contents/MacOS/Multiplier"))) {

    QDir macos_dir = exe_path.dir();
    indexer_path =
        QFileInfo(macos_dir.absoluteFilePath(QLatin1String("../bin/mx-index")));

    importer_path =
        QFileInfo(macos_dir.absoluteFilePath(QLatin1String("../bin/mx-import")));
  }
#endif

  // Install.
  if (!indexer_path.isExecutable() &&
      config.gui_exe_path.endsWith(QLatin1String("bin/mx-gui"))) {
    QDir bin_dir = exe_path.dir();
    indexer_path =
        QFileInfo(bin_dir.absoluteFilePath(QLatin1String("../mx-index")));

    importer_path =
        QFileInfo(bin_dir.absoluteFilePath(QLatin1String("../mx-import")));
  }

  // Build.
  if (!indexer_path.isExecutable() &&
      config.gui_exe_path.endsWith(QLatin1String("bin/GUI/mx-gui"))) {
    QDir gui_dir = exe_path.dir();
    indexer_path =
        QFileInfo(gui_dir.absoluteFilePath(QLatin1String("../Index/mx-index")));
    importer_path =
        QFileInfo(gui_dir.absoluteFilePath(QLatin1String("../Import/mx-import")));
  }

  if (indexer_path.isExecutable()) {
    config.indexer_exe_path = indexer_path.absoluteFilePath();
  }

  if (importer_path.isExecutable()) {
    config.importer_exe_path = importer_path.absoluteFilePath();
  }
}

} // namespace
Configuration::Configuration(void)
    : theme(&(CodeTheme::DefaultTheme())) {
  LocateIndexerAndImporter(*this);
}

}  // namespace mx::gui
