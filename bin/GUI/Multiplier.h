// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <memory>
#include <multiplier/Index.h>
#include <multiplier/Types.h>
#include <QMainWindow>
#include <QProcess>

#include "Event.h"

// NOTE(pag): Put last for Qt.
#include <filesystem>

namespace mx {
class FileLocationCache;
class Index;
namespace gui {

class CodeTheme;
struct Configuration;
enum class ConnectionState : int;

class Multiplier final : public QMainWindow {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  Multiplier(void) = delete;
  Multiplier(const Multiplier &) = delete;
  Multiplier &operator=(const Multiplier &) = delete;

 public:
  explicit Multiplier(struct Configuration &config);
  virtual ~Multiplier(void);

  // Return the current configuration.
  ::mx::gui::Configuration &Configuration(void) const;

  // Return the current connected index.
  const ::mx::Index &Index(void) const;

  // Return the current code theme.
  const ::mx::gui::CodeTheme &CodeTheme(void) const;

  // Return a cache of pre-computed file locations.
  const ::mx::FileLocationCache &FileLocationCache(void) const;

  bool eventFilter(QObject *watched, QEvent *event) Q_DECL_FINAL;

  void Connect(QString host, QString port);

 protected:
  void paintEvent(QPaintEvent *event) Q_DECL_FINAL;
  void closeEvent(QCloseEvent *event) Q_DECL_FINAL;

 private:
  void InitializeWidgets(void);
  void InitializeMenus(void);
  void InitializeUI(void);

  void UpdateMenus(void);
  void UpdateWidgets(void);
  void UpdateUI(void);

  bool DoActions(EventSource source, const EventAction &ea);
  bool EmitEvent(void);
  void ClearLastLocations(void);

 public slots:
  void FocusOnHistory(bool);
  void OnConnected(void);
  void OnSourceFileDoubleClicked(std::filesystem::path, RawEntityId file_id);
  void OnOpenTab(QString title, QWidget *widget);
  void OnOpenDock(QString title, QWidget *widget);

 private slots:
  void OnVersionNumberChanged(::mx::Index index);
  void OnLaunchStarted(void);
  void OnLaunchedIndexerReady(void);
  void OnLaunchExited(int);
  void OnLaunchFailed(QProcess::ProcessError error);
  void OnFileNewInstanceAction(void);
  void OnFileImportAction(void);
  void OnFileLaunchAction(void);
  void OnFileConnectAction(void);
  void OnFileDisconnectAction(void);
  void OnFileExitAction(void);
  void OnViewFileBrowserAction(void);
  void OnViewReferenceBrowserAction(void);
  void OnViewHistoryBrowserAction(void);
  void OnHelpAboutAction(void);
  void OnMoveReferenceBrowser(Qt::DockWidgetArea area);

 public slots:
  void ActOnTokenPressEvent(EventSource source, EventLocations locs);
};

}  // namespace gui
}  // namespace mx
