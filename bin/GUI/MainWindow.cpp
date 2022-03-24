/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "MainWindow.h"

#ifdef __APPLE__
#include "MacOSUtils.h"
#endif

#include <glog/logging.h>

#include <QAction>
#include <QCloseEvent>
#include <QDockWidget>
#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QRunnable>
#include <QThreadPool>
#include <unordered_map>

#include <multiplier/API.h>

#include "FileListView.h"
#include "OpenConnectionDialog.h"

namespace mx::gui {

enum class ConnectionState : int { kNotConnected, kConnecting, kConnected };

namespace {

struct MainMindowMenus final {
  QAction *file_connect_action{nullptr};
  QAction *file_disconnect_action{nullptr};
  QAction *file_exit_action{nullptr};

  QMenu *file_menu{nullptr};
  QMenu *view_menu{nullptr};
  QMenu *help_menu{nullptr};
};

}  // namespace

void DownloadFileListThread::run(void) {
  emit DownloadedFileList(ep->list_files());
}

struct MainWindow::PrivateData final {
  MainMindowMenus menus;

  // The central widget is a bunch of tabs.
  QTabWidget *central_widget{nullptr};

  // File list. This shows files included in the build.
  FileListView *file_list_view{nullptr};
  QDockWidget *file_list_dock{nullptr};

  EntityProvider::Ptr entity_provider;

  ConnectionState connection_state{ConnectionState::kNotConnected};

  inline PrivateData(void) {}
};

MainWindow::~MainWindow(void) {}

void MainWindow::paintEvent(QPaintEvent *event) {
  QString message;
  if (d->connection_state == ConnectionState::kConnected) {
    this->QWidget::paintEvent(event);
    return;
  } else if (d->connection_state == ConnectionState::kConnecting) {
    message = tr("Connecting...");
  } else {
    message = tr("Not connected.");
  }

  static const auto kTextFlags = Qt::AlignCenter | Qt::TextSingleLine;

  auto message_font = font();
  message_font.setPointSizeF(message_font.pointSizeF() * 2.0);
  message_font.setBold(true);

  QFontMetrics font_metrics(message_font);
  auto message_rect = font_metrics.boundingRect(QRect(0, 0, 0xFFFF, 0xFFFF),
                                                kTextFlags, message);

  const auto &event_rec = event->rect();
  auto message_x_pos = (event_rec.width() / 2) - (message_rect.width() / 2);
  auto message_y_pos = (event_rec.height() / 2) - (message_rect.height() / 2);

  message_rect.moveTo(message_x_pos, message_y_pos);

  QPainter painter(this);
  painter.fillRect(event_rec, palette().color(QPalette::Window));

  painter.setFont(message_font);
  painter.setPen(QPen(palette().color(QPalette::WindowText)));
  painter.drawText(message_rect, kTextFlags, message);

  event->accept();
}

void MainWindow::closeEvent(QCloseEvent *event) {
  if (d->connection_state != ConnectionState::kNotConnected) {
    auto answer = QMessageBox::question(
        this, tr("Question"), tr("Are you sure you want to exit the program?"),
        QMessageBox::Yes | QMessageBox::No);
    if (answer != QMessageBox::Yes) {
      event->ignore();
      return;
    }

    OnFileDisconnectAction();
  }

  event->accept();
}

MainWindow::MainWindow(void)
    : QMainWindow(nullptr), d(new PrivateData) {
  InitializeUI();
  UpdateUI();
}

void MainWindow::InitializeWidgets(void ) {
  d->central_widget = new QTabWidget;

  d->file_list_view = new FileListView;
  d->file_list_dock = new QDockWidget(d->file_list_view->windowTitle());
  d->file_list_dock->setWidget(d->file_list_view);
  addDockWidget(Qt::LeftDockWidgetArea, d->file_list_dock);

  // Otherwise need to support an object list somewhere.
  d->central_widget->setTabsClosable(false);
  d->central_widget->setDocumentMode(true);
  d->central_widget->setUsesScrollButtons(true);
  setCentralWidget(d->central_widget);

#ifdef __APPLE__
  if (getenv("MX_NO_CUSTOM_THEME") == nullptr) {
    setTitleBarColor(winId(), palette().color(QPalette::Window), false);
  }
#endif
}

void MainWindow::InitializeMenus(void) {
  //
  // File menu
  //

  d->menus.file_connect_action = new QAction(tr("&Connect"));
  connect(d->menus.file_connect_action, &QAction::triggered, this,
          &MainWindow::OnFileConnectAction);

  d->menus.file_disconnect_action = new QAction(tr("&Disconnect"));
  connect(d->menus.file_disconnect_action, &QAction::triggered, this,
          &MainWindow::OnFileDisconnectAction);

  d->menus.file_exit_action = new QAction(tr("&Exit"));
  connect(d->menus.file_exit_action, &QAction::triggered, this,
          &MainWindow::OnFileExitAction);

  d->menus.file_menu = menuBar()->addMenu(tr("File"));
  d->menus.file_menu->addAction(d->menus.file_connect_action);
  d->menus.file_menu->addAction(d->menus.file_disconnect_action);
  d->menus.file_menu->addSeparator();
  d->menus.file_menu->addAction(d->menus.file_exit_action);
}

void MainWindow::UpdateMenus(void) {
  d->menus.file_connect_action->setEnabled(d->connection_state ==
                                           ConnectionState::kNotConnected);

  d->menus.file_disconnect_action->setEnabled(d->connection_state ==
                                              ConnectionState::kConnected);
}

void MainWindow::UpdateWidgets(void) {
  switch (d->connection_state) {
    case ConnectionState::kNotConnected:
    case ConnectionState::kConnecting:
      d->file_list_view->Clear();
      d->file_list_dock->hide();
      d->central_widget->clear();
      break;

    case ConnectionState::kConnected:
      d->file_list_dock->show();
      break;
  }
}

void MainWindow::UpdateUI(void) {
  UpdateMenus();
  UpdateWidgets();
  update();
}

void MainWindow::InitializeUI(void) {
  setWindowTitle("Multiplier");
  resize(1280, 720);

  InitializeWidgets();
  InitializeMenus();
}

void MainWindow::OnConnectionStateChange(ConnectionState state) {
  if (ConnectionState::kConnected == state) {
    d->connection_state = ConnectionState::kConnected;
  } else if (ConnectionState::kNotConnected == state) {
    d->connection_state = ConnectionState::kNotConnected;
  } else {
    assert(false);
  }
  UpdateUI();
}

void MainWindow::OnNewFileList(FileList files) {
  d->file_list_view->Set(std::move(files));
  d->connection_state = ConnectionState::kConnected;
  UpdateUI();
}

void MainWindow::OnSourceFileDoubleClicked(mx::FileId file_id) {

}

void MainWindow::OnFileConnectAction(void) {
  auto connect_settings = OpenConnectionDialog::Run();
  if (!connect_settings.has_value()) {
    return;
  }

  d->connection_state = ConnectionState::kConnecting;
  UpdateUI();

  d->entity_provider = EntityProvider::from_remote(
      connect_settings->host.toStdString(),
      connect_settings->port.toStdString());

  auto connector = new DownloadFileListThread(d->entity_provider);
  connector->setAutoDelete(true);

  connect(connector, &DownloadFileListThread::DownloadedFileList,
          this, &MainWindow::OnNewFileList);
  QThreadPool::globalInstance()->start(connector);
}

void MainWindow::OnFileDisconnectAction(void) {
  d->connection_state = ConnectionState::kNotConnected;
  d->entity_provider.reset();
  UpdateUI();
}

void MainWindow::OnFileExitAction(void) { close(); }

void MainWindow::OnHelpAboutAction(void) {}

}  // namespace mx::gui
