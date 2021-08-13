/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "astindex.h"

#include <QDebug>
#include <QHeaderView>
#include <QMap>
#include <QString>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <array>
#include <iostream>

namespace multiplier {

class IndexBuilder final : public pasta::DeclVisitor {
  QMap<QTreeWidgetItem *, pasta::Decl> &decls;
  QTreeWidget *const widget;
  QTreeWidgetItem *parent{nullptr};
  QTreeWidgetItem *node{nullptr};

public:
  virtual ~IndexBuilder(void) = default;

  explicit IndexBuilder(QMap<QTreeWidgetItem *, pasta::Decl> &decls_, QTreeWidget *widget_)
      : decls(decls_), widget(widget_) {}

  void AddNode(const pasta::Decl &decl) {
    node = new QTreeWidgetItem();
    if (parent) {
      parent->addChild(node);
    }
    auto kind_name = decl.KindName();
    node->setText(0, QString::fromLocal8Bit(kind_name.data(), static_cast<int>(kind_name.size())));

    decls.insert(node, decl);
  }

  void VisitDeclContext(const pasta::DeclContext &dc) {
    const auto old_parent = parent;
    parent = node;
    for (const auto &decl : dc.AlreadyLoadedDecls()) {
      Accept(decl);
    }
    parent = old_parent;
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    AddNode(decl);
    widget->addTopLevelItem(node);
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    AddNode(decl);
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    AddNode(decl);
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    AddNode(decl);
    VisitDeclContext(decl);
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    AddNode(decl);
    VisitDeclContext(decl);
  }

  void VisitTagDecl(const pasta::TagDecl &decl) final {
    AddNode(decl);
    VisitDeclContext(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final { AddNode(decl); }
};

struct ASTIndex::PrivateData final {
  QTreeWidget *ast_tree{nullptr};
  QMap<QTreeWidgetItem *, pasta::Decl> decls;
};

ASTIndex::ASTIndex(QWidget *parent) : QFrame(parent), d(new PrivateData) {
  setWindowTitle(tr("Abstract Syntax Tree"));

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  d->ast_tree = new QTreeWidget();
  d->ast_tree->setHeaderHidden(true);
  d->ast_tree->setExpandsOnDoubleClick(false);
  d->ast_tree->setColumnCount(1);
  d->ast_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->ast_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->ast_tree->header()->setStretchLastSection(false);
  layout->addWidget(d->ast_tree);

  connect(d->ast_tree, &QTreeWidget::itemActivated, this, &ASTIndex::onTreeWidgetItemActivated);
}

ASTIndex::~ASTIndex() {}

void ASTIndex::reset() {
  d->decls.clear();
  d->ast_tree->reset();
}

void ASTIndex::setAST(std::shared_ptr<pasta::AST> ast) {
  IndexBuilder builder(d->decls, d->ast_tree);
  builder.Accept(ast->TranslationUnit());
  d->ast_tree->expandAll();
}

void ASTIndex::onTreeWidgetItemActivated(QTreeWidgetItem *item, int) {

  auto decl_it = d->decls.find(item);
  if (decl_it != d->decls.end()) {
    emit clickedDecl(*decl_it);
  }
}

} // namespace multiplier
