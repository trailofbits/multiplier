/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <multiplier/widgets/itranslationunitindex.h>

#include <QTreeWidgetItem>

#include <memory>

namespace multiplier {

class TranslationUnitIndex final : public ITranslationUnitIndex {
  Q_OBJECT
  Q_INTERFACES(multiplier::ITranslationUnitIndex)

public:
  TranslationUnitIndex(QWidget *parent);
  virtual ~TranslationUnitIndex() override;

  virtual bool setCompileCommands(const QJsonDocument &json_document) override;
  virtual void reset() override;

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
