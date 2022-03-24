/*
  Copyright (c) 2022-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include <QMainWindow>
#include <QRunnable>

#include <memory>

#include <multiplier/API.h>

namespace mx::gui {

enum class ConnectionState : int;

class DownloadFileListThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  const EntityProvider::Ptr ep;
  void run(void);

 public:
  inline explicit DownloadFileListThread(EntityProvider::Ptr ep_)
      : ep(std::move(ep_)) {}

 signals:
  void DownloadedFileList(FileList list);
};

class MainWindow final : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(void);
  virtual ~MainWindow(void) override;

  MainWindow(const MainWindow &) = delete;
  MainWindow &operator=(const MainWindow &) = delete;

 protected:
  void paintEvent(QPaintEvent *event) override;

  virtual void closeEvent(QCloseEvent *event) override;

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);
  void InitializeMenus(void);
  void InitializeUI(void);

  void UpdateMenus(void);
  void UpdateWidgets(void);
  void UpdateUI(void);

 private slots:
  void OnNewFileList(FileList files);
  void OnSourceFileDoubleClicked(mx::FileId file_id);
  void OnFileConnectAction(void);
  void OnFileDisconnectAction(void);
  void OnFileExitAction(void);
  void OnHelpAboutAction(void);
  void OnConnectionStateChange(ConnectionState state);
};

}  // namespace mx::gui
