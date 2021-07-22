/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QFrame>

#include <memory>

#include <tob/itextview.h>

using namespace tob::widgets;

namespace multiplier {

class Document : public QFrame {
  Q_OBJECT

public:
  Document(const QString &source_file_path, QWidget *parent = nullptr);
  virtual ~Document();

  Document(const Document &) = delete;
  Document &operator=(const Document &) = delete;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onTokenClicked(const QPoint &mouse_position, const Qt::MouseButton &button,
                      TokenID token_id);

  void onCopyAction();
};

} // namespace multiplier
