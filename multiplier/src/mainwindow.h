/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include <tob/itextview.h>

#include <QMainWindow>

#include <memory>

namespace multiplier {

class MainWindow final : public QMainWindow {
  Q_OBJECT

public:
  using Ptr = std::unique_ptr<MainWindow>;
  static Ptr create();

  virtual ~MainWindow() override;

  MainWindow(const MainWindow &) = delete;
  MainWindow &operator=(const MainWindow &) = delete;

protected:
  virtual void closeEvent(QCloseEvent *event) override;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  MainWindow();
  QDockWidget *createDockWidget(QWidget *widget);

  void initializeWidgets();
  void initializeMenus();
  void initializeUI();
  bool initializePasta();

  void updateMenus();
  void updateWidgets();
  void updateUI();

private slots:
  void onFileOpenAction();
  void onFileCloseAction();
  void onFileExitAction();

  void onHelpAboutAction();

  void onCompileCommandsIndexItemActivated(const QString &working_directory,
                                           const QString &source_file_path,
                                           const QString &compile_command);
};

} // namespace multiplier
