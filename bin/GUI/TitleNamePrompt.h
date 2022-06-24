// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>

#include <QDialog>

namespace mx::gui {

class TitleNamePrompt final : public QDialog {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void Vacillate(void);

 public:
  TitleNamePrompt(const QString &prompt, QWidget *parent = nullptr);
  virtual ~TitleNamePrompt(void);

  QString NewName(void) const;

  TitleNamePrompt(const TitleNamePrompt &) = delete;
  TitleNamePrompt *operator=(const TitleNamePrompt &) = delete;

 private slots:
  void accept(void) Q_DECL_FINAL;
  void Shake(void);

 private:
  void InitializeWidgets(void);
};

}  // namespace mx::gui
