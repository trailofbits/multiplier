/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QFrame>
#include <QJsonDocument>

namespace multiplier {

class ITranslationUnitIndex : public QFrame {
  Q_OBJECT

public:
  static ITranslationUnitIndex *create(QWidget *parent = nullptr);

  virtual bool setCompileCommands(const QJsonDocument &json_document) = 0;
  virtual void reset() = 0;

  ITranslationUnitIndex(QWidget *parent) : QFrame(parent) {}
  virtual ~ITranslationUnitIndex() override{};

  ITranslationUnitIndex(const ITranslationUnitIndex &) = delete;
  ITranslationUnitIndex &operator=(const ITranslationUnitIndex &) = delete;

signals:
  void sourceFileDoubleClicked(const QString &working_directory, const QString &source_file_path,
                               const QString &compile_command);
};

} // namespace multiplier

Q_DECLARE_INTERFACE(multiplier::ITranslationUnitIndex, "ITranslationUnitIndex")
