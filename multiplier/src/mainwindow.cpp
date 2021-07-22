/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "mainwindow.h"
#include "compilecommandsindex.h"

#include <tob/itextview.h>

#include <QAction>
#include <QCloseEvent>
#include <QDockWidget>
#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QSplitter>

namespace multiplier {

struct MainMindowMenus final {
  QMenu *file_menu{nullptr};
  QAction *file_open_action{nullptr};
  QAction *file_close_action{nullptr};
  QAction *file_exit_action{nullptr};

  QMenu *view_menu{nullptr};

  QMenu *help_menu{nullptr};
  QAction *help_about_action{nullptr};
};

struct MainMenuWidgets final {
  QMdiArea *mdi_area{nullptr};

  CompileCommandsIndex *compile_cmds_index{nullptr};
  QDockWidget *compile_cmds_index_dock{nullptr};
};

struct MainWindow::PrivateData final {
  MainMindowMenus menus;
  MainMenuWidgets widgets;
  bool is_open{false};
};

MainWindow::Ptr MainWindow::create() { return Ptr(new MainWindow()); }

MainWindow::~MainWindow() {}

void MainWindow::closeEvent(QCloseEvent *event) {
  if (d->is_open) {
    auto answer = QMessageBox::question(this, tr("Question"),
                                        tr("Are you sure you want to exit the program?"),
                                        QMessageBox::Yes | QMessageBox::No);
    if (answer != QMessageBox::Yes) {
      event->ignore();
      return;
    }

    onFileCloseAction();
  }

  event->accept();
}

MainWindow::MainWindow() : QMainWindow(nullptr), d(new PrivateData) {
  initializeUI();
  updateUI();
}

QDockWidget *MainWindow::createDockWidget(QWidget *widget) {
  auto dock_widget = new QDockWidget(widget->windowTitle());
  dock_widget->setWidget(widget);

  return dock_widget;
}

void MainWindow::initializeWidgets() {
  d->widgets.mdi_area = new QMdiArea();
  d->widgets.mdi_area->setTabsMovable(true);
  d->widgets.mdi_area->setTabsClosable(true);
  d->widgets.mdi_area->setDocumentMode(true);
  d->widgets.mdi_area->setViewMode(QMdiArea::TabbedView);

  setCentralWidget(d->widgets.mdi_area);

  d->widgets.compile_cmds_index = new CompileCommandsIndex();
  connect(d->widgets.compile_cmds_index, &CompileCommandsIndex::sourceFileDoubleClicked, this,
          &MainWindow::onCompileCommandsIndexItemActivated);

  d->widgets.compile_cmds_index_dock = createDockWidget(d->widgets.compile_cmds_index);
  addDockWidget(Qt::LeftDockWidgetArea, d->widgets.compile_cmds_index_dock);
}

void MainWindow::initializeMenus() {
  //
  // File menu
  //

  d->menus.file_open_action = new QAction(tr("&Open"));
  connect(d->menus.file_open_action, &QAction::triggered, this, &MainWindow::onFileOpenAction);

  d->menus.file_close_action = new QAction(tr("&Close"));
  connect(d->menus.file_close_action, &QAction::triggered, this, &MainWindow::onFileCloseAction);

  d->menus.file_exit_action = new QAction(tr("&Exit"));
  connect(d->menus.file_exit_action, &QAction::triggered, this, &MainWindow::onFileExitAction);

  d->menus.file_menu = menuBar()->addMenu(tr("File"));
  d->menus.file_menu->addAction(d->menus.file_open_action);
  d->menus.file_menu->addAction(d->menus.file_close_action);
  d->menus.file_menu->addSeparator();
  d->menus.file_menu->addAction(d->menus.file_exit_action);

  //
  // View menu
  //

  d->menus.view_menu = menuBar()->addMenu(tr("View"));
  d->menus.view_menu->addAction(d->widgets.compile_cmds_index_dock->toggleViewAction());

  //
  // Help menu
  //

  d->menus.help_about_action = new QAction(tr("&About"));
  connect(d->menus.help_about_action, &QAction::triggered, this, &MainWindow::onHelpAboutAction);

  d->menus.help_menu = menuBar()->addMenu(tr("Help"));
  d->menus.help_menu->addAction(d->menus.help_about_action);
}

void MainWindow::updateMenus() {
  const auto &is_open = d->is_open;

  d->menus.file_open_action->setEnabled(!is_open);
  d->menus.file_close_action->setEnabled(is_open);
}

void MainWindow::updateWidgets() {
  const auto &is_open = d->is_open;

  d->widgets.compile_cmds_index_dock->setEnabled(is_open);
  d->widgets.compile_cmds_index_dock->setHidden(!is_open);

  if (!is_open) {
    d->widgets.mdi_area->closeAllSubWindows();
  }
}

void MainWindow::updateUI() {
  updateMenus();
  updateWidgets();
}

void MainWindow::initializeUI() {
  setWindowTitle("Multiplier");
  resize(1280, 720);

  initializeWidgets();
  initializeMenus();
}

void MainWindow::onFileOpenAction() {
  QJsonDocument compile_commands;

  {
    auto input_file_path = QFileDialog::getOpenFileName(
        this, tr("Select a 'compile_commands.json' file"), QString(),
        tr("compile_commands.json;;JSON files (*.json);;All files (*.*)"));

    if (input_file_path.isEmpty()) {
      return;
    }

    QFile input_file(input_file_path);
    if (!input_file.open(QIODevice::ReadOnly)) {
      QMessageBox::critical(this, tr("IO Error"), tr("Failed to open the input file"));
      return;
    }

    auto json_data = input_file.readAll();

    QJsonParseError parser_errors;
    compile_commands = QJsonDocument::fromJson(json_data, &parser_errors);
    if (parser_errors.error != QJsonParseError::NoError) {
      auto error_message =
          parser_errors.errorString() + " at offset " + QString::number(parser_errors.offset);

      QMessageBox::critical(this, tr("JSON error"), error_message);
      return;
    }
  }

  if (!d->widgets.compile_cmds_index->setCompileCommands(compile_commands)) {
    QMessageBox::critical(this, tr("Error"), tr("Invalid JSON structure"));
    return;
  }

  d->is_open = true;
  updateUI();
}

void MainWindow::onFileCloseAction() {
  d->widgets.compile_cmds_index->reset();
  d->is_open = false;

  updateUI();
}

void MainWindow::onFileExitAction() { close(); }

void MainWindow::onHelpAboutAction() {}

void MainWindow::onCompileCommandsIndexItemActivated(const QString &working_directory,
                                                     const QString &source_file_path,
                                                     const QString &compile_command) {
  QFile source_code_file(source_file_path);
  if (!source_code_file.open(QIODevice::ReadOnly)) {
    QMessageBox::critical(this, tr("IO Error"),
                          tr("Failed to open the following source code file: ") + source_file_path);
    return;
  }

  auto source_code = QString(source_code_file.readAll());

  auto code_viewer = new QPlainTextEdit();
  code_viewer->setReadOnly(true);
  code_viewer->setPlainText(source_code);

  auto ast_viewer = new QPlainTextEdit();
  ast_viewer->setReadOnly(true);
  ast_viewer->setPlainText("AST HERE");

  auto splitter = new QSplitter();
  splitter->addWidget(code_viewer);
  splitter->addWidget(ast_viewer);

  auto window_title = source_file_path.split("/").takeLast();

  auto container = new QMdiSubWindow();
  container->setWidget(splitter);
  container->setWindowTitle(window_title);
  container->setAttribute(Qt::WA_DeleteOnClose);

  d->widgets.mdi_area->addSubWindow(container);
  container->show();
}

} // namespace multiplier
