/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "Multiplier.h"

#ifdef __APPLE__
#include "MacOSUtils.h"
#endif

#include <QAction>
#include <QApplication>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QThreadPool>

#include <multiplier/Index.h>

#include "Configuration.h"
#include "CodeBrowserView.h"
#include "CodeTheme.h"
#include "FileBrowserView.h"
#include "FileView.h"
#include "HistoryBrowserView.h"
#include "OpenConnectionDialog.h"
#include "ReferenceBrowserView.h"

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

struct Multiplier::PrivateData final {
  struct Configuration &config;

  MainMindowMenus menus;

  CodeBrowserView *code_browser_view{nullptr};

  FileBrowserView *file_browser_view{nullptr};
  QDockWidget *file_browser_dock{nullptr};

  ReferenceBrowserView *reference_browser_view{nullptr};
  QDockWidget *reference_browser_dock{nullptr};

  HistoryBrowserView *history_browser_view{nullptr};
  QDockWidget *history_browser_dock{nullptr};

  mx::Index index;

  ConnectionState connection_state{ConnectionState::kNotConnected};

  inline PrivateData(::mx::gui::Configuration &config_)
      : config(config_) {}
};

Multiplier::~Multiplier(void) {}

// Return the current configuration.
::mx::gui::Configuration &Multiplier::Configuration(void) const {
  return d->config;
}

// Return the current connected index.
const ::mx::Index &Multiplier::Index(void) const {
  return d->index;
}

// Return the current code theme.
const ::mx::gui::CodeTheme &Multiplier::CodeTheme(void) const {
  if (d->config.theme) {
    return *(d->config.theme);
  } else {
    return CodeTheme::DefaultTheme();
  }
}

void Multiplier::paintEvent(QPaintEvent *event) {
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

void Multiplier::closeEvent(QCloseEvent *event) {
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

Multiplier::Multiplier(struct Configuration &config_)
    : QMainWindow(nullptr),
      d(new PrivateData(config_)) {
  InitializeUI();
  UpdateUI();
}

void Multiplier::InitializeWidgets(void) {
  d->code_browser_view = new CodeBrowserView(*this);

  d->file_browser_view = new FileBrowserView(d->config.file_browser);
  d->file_browser_dock = new QDockWidget(d->file_browser_view->windowTitle());
  d->file_browser_dock->setWidget(d->file_browser_view);

  d->reference_browser_view = new ReferenceBrowserView(*this);
  d->reference_browser_dock = new QDockWidget(d->reference_browser_view->windowTitle());
  d->reference_browser_dock->setWidget(d->reference_browser_view);

  d->history_browser_view = new HistoryBrowserView(*this);
  d->history_browser_dock = new QDockWidget(d->history_browser_view->windowTitle());
  d->history_browser_dock->setWidget(d->history_browser_view);

  setTabPosition(Qt::LeftDockWidgetArea, QTabWidget::East);
  setTabPosition(Qt::BottomDockWidgetArea, QTabWidget::North);

  addDockWidget(Qt::LeftDockWidgetArea, d->file_browser_dock);
  addDockWidget(Qt::LeftDockWidgetArea, d->history_browser_dock);
  addDockWidget(Qt::LeftDockWidgetArea, d->reference_browser_dock);
  tabifyDockWidget(d->file_browser_dock, d->history_browser_dock);
  tabifyDockWidget(d->history_browser_dock, d->reference_browser_dock);


  setCentralWidget(d->code_browser_view);

#ifdef __APPLE__
  if (getenv("MX_NO_CUSTOM_THEME") == nullptr) {
    setTitleBarColor(winId(), palette().color(QPalette::Window), false);
  }
#endif

  connect(d->file_browser_view, &FileBrowserView::Connected,
          this, &Multiplier::OnConnected);

  connect(d->file_browser_view, &FileBrowserView::SourceFileDoubleClicked,
          this, &Multiplier::OnSourceFileDoubleClicked);

  connect(d->reference_browser_dock, &QDockWidget::dockLocationChanged,
          this, &Multiplier::OnMoveReferenceBrowser);

  connect(d->history_browser_view, &HistoryBrowserView::HistoryDeclarationClicked,
          this, &Multiplier::OnHistoryDeclarationClicked);
}

void Multiplier::InitializeMenus(void) {
  //
  // File menu
  //

  d->menus.file_connect_action = new QAction(tr("&Connect"));
  connect(d->menus.file_connect_action, &QAction::triggered, this,
          &Multiplier::OnFileConnectAction);

  d->menus.file_disconnect_action = new QAction(tr("&Disconnect"));
  connect(d->menus.file_disconnect_action, &QAction::triggered, this,
          &Multiplier::OnFileDisconnectAction);

  d->menus.file_exit_action = new QAction(tr("&Exit"));
  connect(d->menus.file_exit_action, &QAction::triggered, this,
          &Multiplier::OnFileExitAction);

  d->menus.file_menu = menuBar()->addMenu(tr("File"));
  d->menus.file_menu->addAction(d->menus.file_connect_action);
  d->menus.file_menu->addAction(d->menus.file_disconnect_action);
  d->menus.file_menu->addSeparator();
  d->menus.file_menu->addAction(d->menus.file_exit_action);
}

void Multiplier::UpdateMenus(void) {
  d->menus.file_connect_action->setEnabled(d->connection_state ==
                                           ConnectionState::kNotConnected);

  d->menus.file_disconnect_action->setEnabled(d->connection_state ==
                                              ConnectionState::kConnected);
}

void Multiplier::UpdateWidgets(void) {
  switch (d->connection_state) {
    case ConnectionState::kNotConnected:
    case ConnectionState::kConnecting:
      d->file_browser_view->Clear();
      d->history_browser_view->Clear();
      d->reference_browser_view->Clear();
      d->code_browser_view->Clear();
      d->file_browser_dock->hide();
      d->history_browser_dock->hide();
      d->reference_browser_dock->hide();
      break;

    case ConnectionState::kConnected:
      d->file_browser_dock->show();
      d->history_browser_dock->show();
      d->reference_browser_dock->show();
      break;
  }
}

void Multiplier::UpdateUI(void) {
  UpdateMenus();
  UpdateWidgets();
  update();
}

void Multiplier::InitializeUI(void) {
  setWindowTitle("Multiplier");
  QRect rect = QApplication::desktop()->screenGeometry();

  resize(rect.width(), rect.height());

  InitializeWidgets();
  InitializeMenus();
}

void Multiplier::OnConnectionStateChange(ConnectionState state) {
  if (ConnectionState::kConnected == state) {
    d->connection_state = ConnectionState::kConnected;
  } else if (ConnectionState::kNotConnected == state) {
    d->connection_state = ConnectionState::kNotConnected;
  } else {
    assert(false);
  }
  UpdateUI();
}

void Multiplier::OnMoveReferenceBrowser(Qt::DockWidgetArea area) {
  UpdateUI();
  switch (area) {
    case Qt::DockWidgetArea::LeftDockWidgetArea:
    case Qt::DockWidgetArea::RightDockWidgetArea:
      d->reference_browser_view->SetCodePreviewVertical();
      break;
    default:
      d->reference_browser_view->SetCodePreviewHorizontal();
      break;
  }
}

void Multiplier::OnHistoryDeclarationClicked(RawEntityId eid) {
  std::vector<RawEntityId> ids;
  ids.push_back(eid);
  d->code_browser_view->OpenDeclarations(std::move(ids));
}

void Multiplier::OnConnected(void) {
  d->connection_state = ConnectionState::kConnected;
  UpdateUI();
}

void Multiplier::OnSourceFileDoubleClicked(
    std::filesystem::path path, FileId file_id) {
  d->code_browser_view->OpenFile(std::move(path), file_id);
}

void Multiplier::OnFileConnectAction(void) {
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

  auto downloader = new DownloadFileListThread(Index());
  downloader->setAutoDelete(true);

  connect(downloader, &DownloadFileListThread::DownloadedFileList,
          d->file_browser_view, &FileBrowserView::OnDownloadedFileList);

  connect(downloader, &DownloadFileListThread::DownloadedFileList,
          d->reference_browser_view, &ReferenceBrowserView::OnDownloadedFileList);

  connect(downloader, &DownloadFileListThread::DownloadedFileList,
          d->code_browser_view, &CodeBrowserView::OnDownloadedFileList);

  QThreadPool::globalInstance()->start(downloader);
}

void Multiplier::OnFileDisconnectAction(void) {
  d->connection_state = ConnectionState::kNotConnected;
  d->index = mx::Index();
  d->reference_browser_view->Clear();
  UpdateUI();
}

void Multiplier::OnFileExitAction(void) { close(); }

void Multiplier::OnHelpAboutAction(void) {}

void Multiplier::OnActOnDeclarations(
    Action action, std::vector<RawEntityId> ids) {

  switch (action) {
    case Action::kDoNothing: return;
    case Action::kPropagate: return;
    case Action::kOpenCodeBrowser:
      d->code_browser_view->OpenDeclarations(std::move(ids));
      break;
    case Action::kOpenReferenceBrowser:
      if (d->reference_browser_dock->isEnabled()) {
        d->reference_browser_view->SetRoots(std::move(ids));
        if (d->reference_browser_dock->visibleRegion().isEmpty()) {
          d->reference_browser_dock->raise();
        }
      }
      return;
    case Action::kAddToHistory:
      d->history_browser_view->AddDeclarations(std::move(ids));
      return;
  }
}

}  // namespace mx::gui
