/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QFrame>
#include <QTreeWidgetItem>

#include <memory>

#include <pasta/AST/AST.h>
#include <pasta/Util/File.h>

namespace multiplier {

class ParsedFilesIndex final : public QFrame {
  Q_OBJECT

public:
  ParsedFilesIndex(QWidget *parent = nullptr);
  virtual ~ParsedFilesIndex() override;

  void reset();

  ParsedFilesIndex(const ParsedFilesIndex &) = delete;
  ParsedFilesIndex &operator=(const ParsedFilesIndex &) = delete;

public slots:
  void gotAST(std::shared_ptr<pasta::AST> ast);

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onTreeWidgetItemActivated(QTreeWidgetItem *item, int);

signals:
  void parsedFileDoubleClicked(pasta::File file);
};

} // namespace multiplier
