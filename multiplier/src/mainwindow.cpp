/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "mainwindow.h"

#ifdef __APPLE__
#include "macos_utils.h"
#endif

#include <multiplier/widgets/idocument.h>
#include <multiplier/widgets/itranslationunitindex.h>

#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>

#include <QAction>
#include <QCloseEvent>
#include <QDockWidget>
#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenuBar>
#include <QMessageBox>

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

  ITranslationUnitIndex *tu_index{nullptr};
  QDockWidget *tu_index_dock{nullptr};
};

struct PastaState final {
  std::shared_ptr<pasta::FileSystem> file_system;
  pasta::FileManager file_manager;
  pasta::Compiler c_compiler;
  pasta::Compiler cxx_compiler;
};

struct MainWindow::PrivateData final {
  MainMindowMenus menus;
  MainMenuWidgets widgets;
  bool is_open{false};
  std::optional<PastaState> opt_pasta;
};

bool MainWindow::initializePasta() {
  auto file_system = pasta::FileSystem::CreateNative();
  auto file_manager = pasta::FileManager(file_system);

  auto c_compiler_res =
      pasta::Compiler::CreateHostCompiler(file_manager, pasta::TargetLanguage::kC);
  if (c_compiler_res.Failed()) {
    return false;
  }

  auto cxx_compiler_res =
      pasta::Compiler::CreateHostCompiler(file_manager, pasta::TargetLanguage::kCXX);
  if (cxx_compiler_res.Failed()) {
    return false;
  }

  d->opt_pasta = PastaState{
      file_system,
      std::move(file_manager),
      c_compiler_res.TakeValue(),
      cxx_compiler_res.TakeValue(),
  };

  return true;
}

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

  if (!initializePasta()) {
    QMessageBox::critical(this, tr("Error"), tr("Failed to initialise libpasta"));
    abort();
  }
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

  d->widgets.tu_index = ITranslationUnitIndex::create();
  connect(
      d->widgets.tu_index,
      SIGNAL(sourceFileDoubleClicked(const QString &, const QString &, const QString &)), this,
      SLOT(onCompileCommandsIndexItemActivated(const QString &, const QString &, const QString &)));

  d->widgets.tu_index_dock = createDockWidget(d->widgets.tu_index);
  addDockWidget(Qt::RightDockWidgetArea, d->widgets.tu_index_dock);

#ifdef __APPLE__
  if (getenv("MULTIPLIER_NO_CUSTOM_THEME") == nullptr) {
    setTitleBarColor(winId(), palette().color(QPalette::Window), false);
  }
#endif
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
  d->menus.view_menu->addAction(d->widgets.tu_index_dock->toggleViewAction());

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

  d->widgets.tu_index_dock->widget()->setEnabled(is_open);
  d->widgets.tu_index_dock->setHidden(!is_open);

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

  if (!d->widgets.tu_index->setCompileCommands(compile_commands)) {
    QMessageBox::critical(this, tr("Error"), tr("Invalid JSON structure"));
    return;
  }

  d->is_open = true;
  updateUI();
}

void MainWindow::onFileCloseAction() {
  d->widgets.tu_index->reset();
  d->is_open = false;

  updateUI();
}

void MainWindow::onFileExitAction() { close(); }

void MainWindow::onHelpAboutAction() {}

void MainWindow::onCompileCommandsIndexItemActivated(const QString &working_directory,
                                                     const QString &source_file_path,
                                                     const QString &compile_command) {

  auto &pasta = d->opt_pasta.value();

  auto cwd_res = pasta.file_system->CurrentWorkingDirectory();
  if (cwd_res.Failed()) {
    QMessageBox::critical(this, tr("Error"), QString::fromStdString(cwd_res.TakeError().message()));
    return;
  }

  auto working_directory_path = pasta.file_system->ParsePath(
      working_directory.toStdString(), cwd_res.TakeValue(), pasta.file_system->PathKind());

  pasta::ArgumentVector argv(compile_command.toStdString());
  auto cmd_res = pasta::CompileCommand::CreateFromArguments(argv, working_directory_path);

  if (cmd_res.Failed()) {
    std::string error_message(cmd_res.Error());
    QMessageBox::critical(this, tr("Error"), QString::fromStdString(error_message));
    return;
  }

  auto compiler = pasta.c_compiler;
  if (source_file_path.endsWith(".cc", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".cp", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".cpp", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".cxx", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".c++", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".C", Qt::CaseSensitive)) {
    compiler = pasta.cxx_compiler;
  }

  auto jobs_res = compiler.CreateJobsForCommand(cmd_res.TakeValue());
  if (jobs_res.Failed()) {
    std::string error_message(jobs_res.Error());
    QMessageBox::critical(this, tr("Error"), QString::fromStdString(error_message));
    return;
  }

  for (auto job : jobs_res.TakeValue()) {
    auto document_container = new QMdiSubWindow();
    document_container->setWidget(IDocument::create(job));
    document_container->setAttribute(Qt::WA_DeleteOnClose);

    auto window_title = QString::fromStdString(job.SourceFile().Path().filename().generic_string());
    document_container->setWindowTitle(window_title);

    d->widgets.mdi_area->addSubWindow(document_container);
    document_container->show();
  }
}

} // namespace multiplier
