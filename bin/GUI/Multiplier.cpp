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

#include <iostream>

namespace mx::gui {

enum class ConnectionState : int { kNotConnected, kConnecting, kConnected };

namespace {

struct MainMindowMenus final {

  QMenu *file_menu{nullptr};
  QAction *file_connect_action{nullptr};
  QAction *file_disconnect_action{nullptr};
  QAction *file_exit_action{nullptr};

  QMenu *view_menu{nullptr};
  QAction *view_reference_browser_action{nullptr};
  QAction *view_history_browser_action{nullptr};
  QAction *view_file_browser_action{nullptr};

  QMenu *help_menu{nullptr};
};

static FileLocationConfiguration LineNumConfig(const CodeTheme &theme) {
  FileLocationConfiguration config;
  config.tab_width = static_cast<unsigned>(theme.NumSpacesInTab());
  return config;
}

}  // namespace

struct Multiplier::PrivateData final {
  struct Configuration &config;

  MainMindowMenus menus;

  class CodeBrowserView *code_browser_view{nullptr};

  class FileBrowserView *file_browser_view{nullptr};
  QDockWidget *file_browser_dock{nullptr};

  class ReferenceBrowserView *reference_browser_view{nullptr};
  QDockWidget *reference_browser_dock{nullptr};

  class HistoryBrowserView *history_browser_view{nullptr};
  QDockWidget *history_browser_dock{nullptr};

  Qt::KeyboardModifiers modifiers;
  Qt::Key key{Qt::Key_unknown};
  Qt::MouseButtons buttons;
  Qt::MouseButtons double_click_buttons;
  MouseClickKind click_kind{MouseClickKind::kNotClicked};

  // The last-pressed locations.
  std::unordered_map<EventSource, EventLocations> last_locations;

  mx::Index index;
  mx::FileLocationCache line_cache;

  ConnectionState connection_state{ConnectionState::kNotConnected};

  inline PrivateData(::mx::gui::Configuration &config_)
      : config(config_),
        line_cache(LineNumConfig(config.theme ?
                                 *config.theme :
                                 CodeTheme::DefaultTheme())) {}
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

// Return a cache of pre-computed file locations.
const ::mx::FileLocationCache &Multiplier::FileLocationCache(void) const {
  return d->line_cache;
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

#ifdef Q_OS_MAC
#  define IF_APPLE_ELSE(a, b) a
#else
#  define IF_APPLE_ELSE(a, b) b
#endif

bool Multiplier::eventFilter(QObject *watched, QEvent *event) {

//  std::cerr << "et=" << int(et) << '\n';
  switch (const QEvent::Type et = event->type(); et) {
//    case QEvent::Enter:
//      ++d->in_widget;
//      std::cerr << "enter=" << d->in_widget << '\n';
//      return false;
//    case QEvent::Leave:
//      d->in_widget = std::max(d->in_widget - 1, 0);
//      std::cerr << "leave=" << d->in_widget << '\n';
//      if (1 <= d->in_widget) {
//        d->modifiers = {};
//        d->click_kind = MouseClickKind::kNotClicked;
//        d->key = Qt::Key_unknown;
//        std::cerr << "outside of gui\n";
//      }
//      return false;
    case QEvent::KeyPress:
      d->key = Qt::Key_unknown;
      d->click_kind = MouseClickKind::kNotClicked;
      switch (auto key = dynamic_cast<QKeyEvent *>(event)->key(); key) {
        case IF_APPLE_ELSE(Qt::Key_Meta, Qt::Key_Control):
          d->modifiers.setFlag(Qt::KeyboardModifier::ControlModifier);
          break;
        case Qt::Key_Shift:
          d->modifiers.setFlag(Qt::KeyboardModifier::ShiftModifier);
          break;
        case Qt::Key_Alt:
        case Qt::Key_Option:
          d->modifiers.setFlag(Qt::KeyboardModifier::AltModifier);
          break;
        case IF_APPLE_ELSE(Qt::Key_Control, Qt::Key_Meta):
          d->modifiers.setFlag(Qt::KeyboardModifier::MetaModifier);
          break;
        default:
          d->key = static_cast<Qt::Key>(key);
          break;
      }
      break;

    case QEvent::KeyRelease:
      switch (auto key = dynamic_cast<QKeyEvent *>(event)->key(); key) {
        case IF_APPLE_ELSE(Qt::Key_Meta, Qt::Key_Control):
          d->modifiers.setFlag(Qt::KeyboardModifier::ControlModifier, false);
          break;
        case Qt::Key_Shift:
          d->modifiers.setFlag(Qt::KeyboardModifier::ShiftModifier, false);
          break;
        case Qt::Key_Alt:
        case Qt::Key_Option:
          d->modifiers.setFlag(Qt::KeyboardModifier::AltModifier, false);
          break;
        case IF_APPLE_ELSE(Qt::Key_Control, Qt::Key_Meta):
          d->modifiers.setFlag(Qt::KeyboardModifier::MetaModifier, false);
          break;
        default:
          if (d->key == key) {
            d->key = Qt::Key_unknown;
          }
          break;
      }
      break;

    case QEvent::MouseButtonPress:
    case QEvent::NonClientAreaMouseButtonPress:
    case QEvent::GraphicsSceneMousePress: {
      QMouseEvent *me = dynamic_cast<QMouseEvent *>(event);
      const Qt::MouseButton button = me->button();
      d->buttons.setFlag(button, true);
      d->double_click_buttons = {};
      d->click_kind = MouseClickKind::kNotClicked;
      d->last_locations.clear();
      return false;
    }

    case QEvent::MouseButtonRelease:
    case QEvent::NonClientAreaMouseButtonRelease:
    case QEvent::GraphicsSceneMouseRelease: {
      QMouseEvent *me = dynamic_cast<QMouseEvent *>(event);
      const Qt::MouseButton button = me->button();
      d->click_kind = MouseClickKind::kNotClicked;
      if (d->buttons.testFlag(button)) {
        d->buttons.setFlag(button, false);
        if (button == Qt::MouseButton::LeftButton) {
          d->click_kind = MouseClickKind::kLeftClick;
        } else if (button == Qt::MouseButton::RightButton) {
          d->click_kind = MouseClickKind::kRightClick;
        }
      } else if (d->double_click_buttons.testFlag(button)) {
        d->double_click_buttons.setFlag(button, false);
        if (button == Qt::MouseButton::LeftButton) {
          d->click_kind = MouseClickKind::kLeftDoubleClick;
        } else if (button == Qt::MouseButton::RightButton) {
          d->click_kind = MouseClickKind::kRightDoubleClick;
        }
      }
      break;
    }
    case QEvent::MouseButtonDblClick:
    case QEvent::NonClientAreaMouseButtonDblClick:
    case QEvent::GraphicsSceneMouseDoubleClick: {
      QMouseEvent *me = dynamic_cast<QMouseEvent *>(event);
      d->double_click_buttons.setFlag(me->button(), true);
      break;
    }

    default:
      return false;
  }

  auto ret = EmitEvent();
  d->key = Qt::Key_unknown;
  d->click_kind = MouseClickKind::kNotClicked;
  return ret;
}

Multiplier::Multiplier(struct Configuration &config_)
    : QMainWindow(nullptr),
      d(new PrivateData(config_)) {
  InitializeUI();
  UpdateUI();
}

void Multiplier::InitializeWidgets(void) {
  installEventFilter(this);

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

  connect(d->history_browser_dock, &QDockWidget::visibilityChanged,
          this, &Multiplier::FocusOnHistory);

  connect(d->file_browser_view, &FileBrowserView::Connected,
          this, &Multiplier::OnConnected);

  connect(d->file_browser_view, &FileBrowserView::SourceFileDoubleClicked,
          this, &Multiplier::OnSourceFileDoubleClicked);

  connect(d->reference_browser_dock, &QDockWidget::dockLocationChanged,
          this, &Multiplier::OnMoveReferenceBrowser);

  connect(d->history_browser_view, &HistoryBrowserView::TokenPressEvent,
          this, &Multiplier::ActOnTokenPressEvent);
}

void Multiplier::InitializeMenus(void) {
  //
  // File menu
  //

  d->menus.file_connect_action = new QAction(tr("&Connect"));
  connect(d->menus.file_connect_action, &QAction::triggered,
          this, &Multiplier::OnFileConnectAction);

  d->menus.file_disconnect_action = new QAction(tr("&Disconnect"));
  connect(d->menus.file_disconnect_action, &QAction::triggered,
          this, &Multiplier::OnFileDisconnectAction);

  d->menus.file_exit_action = new QAction(tr("&Exit"));
  connect(d->menus.file_exit_action, &QAction::triggered,
          this, &Multiplier::OnFileExitAction);

  d->menus.view_file_browser_action = new QAction(tr("File Browser"));
  connect(d->menus.view_file_browser_action, &QAction::triggered,
          this, &Multiplier::OnViewFileBrowserAction);

  d->menus.view_reference_browser_action = new QAction(tr("Reference Browser"));
  connect(d->menus.view_reference_browser_action, &QAction::triggered,
          this, &Multiplier::OnViewReferenceBrowserAction);

  d->menus.view_history_browser_action = new QAction(tr("History Browser"));
  connect(d->menus.view_history_browser_action, &QAction::triggered,
          this, &Multiplier::OnViewHistoryBrowserAction);

  d->menus.file_menu = menuBar()->addMenu(tr("File"));
  d->menus.file_menu->addAction(d->menus.file_connect_action);
  d->menus.file_menu->addAction(d->menus.file_disconnect_action);
  d->menus.file_menu->addSeparator();
  d->menus.file_menu->addAction(d->menus.file_exit_action);

  d->menus.view_menu = menuBar()->addMenu(tr("View"));
  d->menus.view_menu->addAction(d->menus.view_reference_browser_action);
  d->menus.view_menu->addAction(d->menus.view_history_browser_action);
  d->menus.view_menu->addAction(d->menus.view_file_browser_action);
}

void Multiplier::UpdateMenus(void) {
  bool is_connected = d->connection_state == ConnectionState::kConnected;
  d->menus.file_connect_action->setEnabled(!is_connected);
  d->menus.file_disconnect_action->setEnabled(is_connected);
  d->menus.view_reference_browser_action->setEnabled(is_connected);
  d->menus.view_history_browser_action->setEnabled(is_connected);
  d->menus.view_file_browser_action->setEnabled(is_connected);
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

void Multiplier::FocusOnHistory(bool visible) {
  if (visible) {
    d->history_browser_view->Focus();
  }
}

void Multiplier::OnConnected(void) {
  d->connection_state = ConnectionState::kConnected;
  UpdateUI();
}

void Multiplier::OnSourceFileDoubleClicked(
    std::filesystem::path path, FileId file_id) {
  d->code_browser_view->OpenFile(std::move(path), file_id, true);
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
          d->history_browser_view, &HistoryBrowserView::OnDownloadedFileList);

  connect(downloader, &DownloadFileListThread::DownloadedFileList,
          d->code_browser_view, &CodeBrowserView::OnDownloadedFileList);

  QThreadPool::globalInstance()->start(downloader);
}

void Multiplier::OnFileDisconnectAction(void) {
  d->connection_state = ConnectionState::kNotConnected;
  d->index = mx::Index();
  d->line_cache.clear();
  d->reference_browser_view->Clear();
  d->history_browser_view->Clear();
  d->code_browser_view->Clear();
  d->last_locations.clear();
  UpdateUI();
}

void Multiplier::OnFileExitAction(void) { close(); }

void Multiplier::OnViewFileBrowserAction(void) {
  d->file_browser_dock->setEnabled(true);
  d->file_browser_dock->toggleViewAction()->setChecked(true);
  d->file_browser_dock->setVisible(true);
  d->file_browser_view->Focus();
}

void Multiplier::OnViewReferenceBrowserAction(void) {
  d->reference_browser_dock->setEnabled(true);
  d->reference_browser_dock->toggleViewAction()->setChecked(true);
  d->reference_browser_dock->setVisible(true);
  d->reference_browser_view->Focus();
}

void Multiplier::OnViewHistoryBrowserAction(void) {
  d->history_browser_dock->setEnabled(true);
  d->history_browser_dock->toggleViewAction()->setChecked(true);
  d->history_browser_dock->setVisible(true);
  d->history_browser_view->Focus();
}

void Multiplier::OnHelpAboutAction(void) {}

bool Multiplier::DoActions(EventSource source, const EventAction &ea) {
  const EventLocations &locs = d->last_locations[source];

  if ((ea.match_sources & source) != EventSources(source)) {
//    std::cerr << "failed on sources: " << ea.description << "\n";
    return false;
  }

  auto has_locs = !locs.IsEmpty();

  switch (ea.do_action) {
    case Action::kDoNothing:
      break;
    case Action::kOpenCodeBrowser:
      if (has_locs) {
//        std::cerr << "> opening code browser\n";
        d->code_browser_view->OpenEntities(locs);
        return true;
      } else {
        return false;
      }
    case Action::kOpenReferenceBrowser:
      if (has_locs) {
//        std::cerr << "> opening ref browser\n";
        d->reference_browser_view->SetRoots(locs);
        if (d->reference_browser_dock->visibleRegion().isEmpty()) {
          d->reference_browser_dock->raise();
        }
        return true;
      } else {
        return false;
      }
    case Action::kAddToVisualHistoryAsChild:
      if (has_locs) {
//        std::cerr << "> adding to visual history as child\n";
        d->history_browser_view->AddChildDeclarations(locs);
        return true;
      } else {
        return false;
      }
    case Action::kAddToVisualHistoryAsSibling:
      if (has_locs) {
//        std::cerr << "> adding to visual history as sibling\n";
        d->history_browser_view->AddSiblingDeclarations(locs);
        return true;
      } else {
        return false;
      }
    case Action::kAddToVisualHistoryUnderRoot:
      if (has_locs) {
//        std::cerr << "> adding to visual history under root\n";
        d->history_browser_view->AddDeclarationsUnderRoot(locs);
        return true;
      } else {
        return false;
      }
    case Action::kAddToVisualHistoryAsRoots:
      if (has_locs) {
//        std::cerr << "> adding to visual history as root\n";
        d->history_browser_view->AddRootDeclarations(locs);
        return true;
      } else {
        return false;
      }
    case Action::kAddToLinearHistory:
      if (has_locs) {
//        std::cerr << "> adding to linear history\n";
        d->history_browser_view->AddToLinearHistory(locs);
        return true;
      } else {
        return false;
      }
    case Action::kGoBackLinearHistory:
//      std::cerr << "> going back in linear history\n";
      return d->history_browser_view->GoBackInLinearHistory();
  }

  return false;
}

bool Multiplier::EmitEvent(void) {
//  switch (d->click_kind) {
//    case MouseClickKind::kLeftClick: std::cerr << "left "; break;
//    case MouseClickKind::kLeftDoubleClick: std::cerr << "left-double "; break;
//    case MouseClickKind::kRightClick: std::cerr << "right "; break;
//    case MouseClickKind::kRightDoubleClick: std::cerr << "right-double "; break;
//    default: break;
//  }

  if (d->modifiers) {
//    std::cerr << "modifiers=" << std::hex << int(d->modifiers) << std::dec << ' ';
  }

  if (d->key != Qt::Key_unknown) {
//    std::cerr << "key=" << int(d->key) << ' ';
  }

//  std::cerr << '\n';

  auto acted = false;
  for (const EventAction &ea : d->config.actions) {
    if (ea.match_modifiers != d->modifiers) {
//      std::cerr << "failed on modifiers: " << ea.description << "\n";
      continue;
    }

    if (ea.match_key != d->key) {
//      std::cerr << "failed on key: " << ea.description << "\n";
      continue;
    }

    if (ea.match_click != d->click_kind) {
//      std::cerr << "failed on click kind: " << ea.description << "\n";
      continue;
    }

//    for (const auto &loc : d->last_locations) {
//      std::cerr
//          << "EmitEvent"
//          << "; decl_id=" << loc.DeclarationId()
//          << "; file_tok_id=" << loc.FileTokenId()
//          << "; frag_tok_id=" << loc.FragmentTokenId()
//          << ": " << ea.description << '\n';
//    }

    for (const auto &[source, locs] : d->last_locations) {
      if (DoActions(source, ea)) {
        acted = true;
      }
    }
  }

  return acted;
}

void Multiplier::ActOnTokenPressEvent(EventSource source, EventLocations locs) {
//  for (const EventLocation &loc : locs) {
//    std::cerr
//        << "\nActOnTokenPressEvent"
//        << "; decl_id=" << loc.DeclarationId()
//        << "; file_tok_id=" << loc.FileTokenId()
//        << "; frag_tok_id=" << loc.FragmentTokenId();
//    switch (source) {
//      case EventSource::kCodeBrowserClickSource: std::cerr << " (from code browser src)"; break;
//      case EventSource::kCodeBrowserClickDest: std::cerr << " (from code browser dest)"; break;
//      case EventSource::kReferenceBrowser: std::cerr << " (from ref browser)"; break;
//      case EventSource::kReferenceBrowserPreviewClickSource: std::cerr << " (from ref code browser src)"; break;
//      case EventSource::kReferenceBrowserPreviewClickDest: std::cerr << " (from ref code browser dest)"; break;
//      case EventSource::kHistoryBrowserVisualItemSelected: std::cerr << " (from history browser item sel)"; break;
//      case EventSource::kHistoryBrowserLinearItemChanged: std::cerr << " (from history browser linear change)"; break;
//    }
//    std::cerr << '\n';
//  }

  d->last_locations[source] = std::move(locs);
  d->key = Qt::Key_unknown;
  d->click_kind = MouseClickKind::kNotClicked;
  for (const EventAction &ea : d->config.immediate_actions) {
    DoActions(source, ea);
  }
}

}  // namespace mx::gui
