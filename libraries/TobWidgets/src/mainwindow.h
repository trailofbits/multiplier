/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "textview.h"

#include <QMainWindow>

#include <memory>

namespace drgui {

class MainWindow final : public QMainWindow {
  Q_OBJECT

public:
  using Ptr = std::unique_ptr<MainWindow>;
  static Ptr create();

  virtual ~MainWindow() override;

  MainWindow(const MainWindow &) = delete;
  MainWindow &operator=(const MainWindow &) = delete;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  MainWindow();

private slots:
  void onTokenClicked(const QPoint mouse_position, const Qt::MouseButton &button, TokenID token_id);
};

} // namespace drgui
