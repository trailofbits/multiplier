/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QFrame>
#include <QJsonDocument>
#include <QTreeWidgetItem>

#include <memory>

namespace multiplier {

class CompileCommandsIndex final : public QFrame {
  Q_OBJECT

public:
  CompileCommandsIndex(QWidget *parent = nullptr);
  virtual ~CompileCommandsIndex() override;

  bool setCompileCommands(const QJsonDocument &json_document);
  void reset();

  CompileCommandsIndex(const CompileCommandsIndex &) = delete;
  CompileCommandsIndex &operator=(const CompileCommandsIndex &) = delete;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onTreeWidgetItemActivated(QTreeWidgetItem *item, int);

signals:
  void sourceFileDoubleClicked(const QString &working_directory, const QString &source_file_path,
                               const QString &compile_command);
};

} // namespace multiplier
