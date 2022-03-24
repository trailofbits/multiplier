/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

//
// Swapping these two headers will cause the moc compiler to fail
//

// clang-format off
#include <optional>
#include <filesystem>
// clang-format on

#include <QDialog>
#include <QUrl>

namespace mx::gui {

struct ConnectionSettings final {
  QString host;
  QString port;
};

class OpenConnectionDialog final : public QDialog {
  Q_OBJECT

 public:
  static std::optional<ConnectionSettings> Run(void);

  OpenConnectionDialog(const OpenConnectionDialog &) = delete;
  OpenConnectionDialog &operator=(const OpenConnectionDialog &) = delete;

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  OpenConnectionDialog(void);
  virtual ~OpenConnectionDialog(void) final;

protected:
  virtual void keyPressEvent(QKeyEvent *event) override;

 private slots:
  void OnConnectButtonPress(void);
};

}  // namespace mx::gui
