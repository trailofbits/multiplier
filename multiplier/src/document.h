/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QFrame>

#include <memory>

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
};

} // namespace multiplier
