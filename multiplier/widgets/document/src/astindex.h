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

namespace multiplier {

class ASTIndex final : public QFrame {
  Q_OBJECT

public:
  ASTIndex(QWidget *parent = nullptr);
  virtual ~ASTIndex() override;

  void reset();

  ASTIndex(const ASTIndex &) = delete;
  ASTIndex &operator=(const ASTIndex &) = delete;

public slots:
  void gotAST(std::shared_ptr<pasta::AST> ast);

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onTreeWidgetItemActivated(QTreeWidgetItem *item, int);

signals:
  void clickedDecl(pasta::Decl decl);
};

} // namespace multiplier
