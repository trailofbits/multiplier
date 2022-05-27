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
#include <unordered_map>

#include <multiplier/Index.h>

#include "FileBrowserView.h"
#include "FileView.h"
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

struct MainWindow::PrivateData final {
  MainMindowMenus menus;

  // The central widget is a bunch of tabs.
  QTabWidget *central_widget{nullptr};

  // File list. This shows files included in the build.
  FileBrowserView *file_list_view{nullptr};
  QDockWidget *file_list_dock{nullptr};

  mx::Index index;

  std::unordered_map<FileId, FileView *> file_views;

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

void MainWindow::InitializeWidgets(void) {
  d->central_widget = new QTabWidget;

  d->file_list_view = new FileBrowserView(this);
  d->file_list_dock = new QDockWidget(d->file_list_view->windowTitle());
  d->file_list_dock->setWidget(d->file_list_view);

  addDockWidget(Qt::LeftDockWidgetArea, d->file_list_dock);

  d->central_widget->setTabsClosable(true);
  d->central_widget->setMovable(true);
  d->central_widget->setDocumentMode(true);
  d->central_widget->setUsesScrollButtons(true);
  setCentralWidget(d->central_widget);

#ifdef __APPLE__
  if (getenv("MX_NO_CUSTOM_THEME") == nullptr) {
    setTitleBarColor(winId(), palette().color(QPalette::Window), false);
  }
#endif

  connect(d->central_widget, &QTabWidget::tabCloseRequested,
          this, &MainWindow::OnCloseFileViewTab);
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

void MainWindow::OnCloseFileViewTab(int index) {
  d->central_widget->removeTab(index);
}

void MainWindow::OnConnected(void) {
  d->connection_state = ConnectionState::kConnected;
  UpdateUI();
}

void MainWindow::OnSourceFileDoubleClicked(
    std::filesystem::path path, mx::FileId file_id) {

  QTabWidget *file_view = new FileView(d->index, path, file_id);
  int tab_index = d->central_widget->addTab(
      file_view,
      QString("%1 (%2)").arg(path.filename().c_str()).arg(file_id));

#ifndef QT_NO_TOOLTIP
  d->central_widget->setTabToolTip(
      tab_index, QString::fromStdString(path.generic_string()));
#endif

  d->central_widget->setCurrentIndex(tab_index);
}

void MainWindow::OnFileConnectAction(void) {
  auto connect_settings = OpenConnectionDialog::Run();
  if (!connect_settings.has_value()) {
    return;
  }

  d->connection_state = ConnectionState::kConnecting;
  UpdateUI();

  d->index = EntityProvider::in_memory_cache(
      EntityProvider::from_remote(
          connect_settings->host.toStdString(),
          connect_settings->port.toStdString()),
      10u * 60u  /* 10 minutes */);

  d->file_list_view->DownloadFileListInBackground(d->index);
}

void MainWindow::OnFileDisconnectAction(void) {
  d->connection_state = ConnectionState::kNotConnected;
  d->index = mx::Index();
  UpdateUI();
}

void MainWindow::OnFileExitAction(void) { close(); }

void MainWindow::OnHelpAboutAction(void) {}

}  // namespace mx::gui
