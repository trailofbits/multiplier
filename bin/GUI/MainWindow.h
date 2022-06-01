// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <QMainWindow>

#include <memory>

#include <multiplier/Index.h>

namespace mx::gui {

enum class ConnectionState : int;

class MainWindow final : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(void);
  virtual ~MainWindow(void) override;

  MainWindow(const MainWindow &) = delete;
  MainWindow &operator=(const MainWindow &) = delete;

 protected:
  void paintEvent(QPaintEvent *event) Q_DECL_FINAL;
  void closeEvent(QCloseEvent *event) Q_DECL_FINAL;

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);
  void InitializeMenus(void);
  void InitializeUI(void);

  void UpdateMenus(void);
  void UpdateWidgets(void);
  void UpdateUI(void);

 public slots:
  void OnConnected(void);
  void OnSourceFileDoubleClicked(std::filesystem::path, mx::FileId file_id);

 private slots:
  void OnFileConnectAction(void);
  void OnFileDisconnectAction(void);
  void OnFileExitAction(void);
  void OnHelpAboutAction(void);
  void OnConnectionStateChange(ConnectionState state);
  void OnCloseFileViewTab(int index);
  void OnDeclarationsClicked(std::vector<RawEntityId> ids);
};

}  // namespace mx::gui
