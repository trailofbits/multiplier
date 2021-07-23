/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "document.h"
#include "astmodel.h"
#include "sourcecodemodel.h"

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QMenu>
#include <QSplitter>
#include <QVBoxLayout>

namespace multiplier {

struct Document::PrivateData final {
  tob::widgets::ITextModel::Ptr code_model;
  tob::widgets::ITextView *text_view{nullptr};

  tob::widgets::ITextModel::Ptr ast_model;
  tob::widgets::ITextView *ast_view{nullptr};

  QMenu *context_menu{nullptr};
  QAction *copy_action{nullptr};
};

Document::Document(const QString &source_file_path, const QString &working_directory,
                   const QString &compile_command, QWidget *parent)
    : QFrame(parent), d(new PrivateData) {
  d->ast_model = std::make_shared<ASTModel>(working_directory, compile_command);
  d->code_model = std::make_shared<SourceCodeModel>(source_file_path);

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  auto splitter = new QSplitter();
  layout->addWidget(splitter);

  TextViewTheme theme;
  theme.background = QColor::fromRgba(0xFF000000);
  theme.foreground = QColor::fromRgba(0xFFC7C7C7);
  theme.color_map.insert({0, QColor::fromRgba(0xFFFF8272)});
  theme.color_map.insert({1, QColor::fromRgba(0xFFB4FA72)});
  theme.color_map.insert({2, QColor::fromRgba(0xFFFEFDC2)});
  theme.color_map.insert({3, QColor::fromRgba(0xFFA5D5FE)});
  theme.color_map.insert({4, QColor::fromRgba(0xFFFF8FFD)});
  theme.color_map.insert({5, QColor::fromRgba(0xFFD0D1FE)});
  theme.color_map.insert({6, QColor::fromRgba(0xFFF1F1F1)});

  d->text_view = ITextView::create();
  d->text_view->setTheme(theme);
  d->text_view->setModel(d->code_model);
  connect(d->text_view, SIGNAL(tokenClicked(const QPoint &, const Qt::MouseButton &, TokenID)),
          this, SLOT(onSourceCodeItemClicked(const QPoint &, const Qt::MouseButton &, TokenID)));

  splitter->addWidget(d->text_view);

  d->ast_view = ITextView::create();
  d->ast_view->setTheme(theme);
  d->ast_view->setModel(d->ast_model);
  splitter->addWidget(d->ast_view);
  connect(d->ast_view, SIGNAL(tokenClicked(const QPoint &, const Qt::MouseButton &, TokenID)), this,
          SLOT(onASTItemClicked(const QPoint &, const Qt::MouseButton &, TokenID)));

  d->context_menu = new QMenu(tr("Context menu"));

  d->copy_action = new QAction(tr("Copy"));
  connect(d->copy_action, &QAction::triggered, this, &Document::onCopyAction);

  d->context_menu->addAction(d->copy_action);
}

Document::~Document() {}

void Document::onSourceCodeItemClicked(const QPoint &mouse_position, const Qt::MouseButton &button,
                                       TokenID token_id) {
  d->copy_action->setEnabled(d->text_view->hasSelection());

  // Custom menu example
  QMenu *additional_menu{nullptr};
  if (token_id != kInvalidTokenID) {
    additional_menu = new QMenu(tr("Test menu"));
    d->context_menu->addMenu(additional_menu);

    auto token_data = d->code_model->tokenData(token_id);
    auto test_action = new QAction(tr("Test action for ") + token_data);
    additional_menu->addAction(test_action);
  }

  d->context_menu->exec(mouse_position);

  if (additional_menu != nullptr) {
    d->context_menu->removeAction(additional_menu->menuAction());
  }
}

void Document::onASTItemClicked(const QPoint &mouse_position, const Qt::MouseButton &button,
                                TokenID token_id) {
  d->copy_action->setEnabled(d->text_view->hasSelection());

  // Custom menu example
  QMenu *additional_menu{nullptr};
  if (token_id != kInvalidTokenID) {
    additional_menu = new QMenu(tr("Test menu"));
    d->context_menu->addMenu(additional_menu);

    auto token_data = d->ast_model->tokenData(token_id);
    auto test_action = new QAction(tr("Test action for ") + token_data);
    additional_menu->addAction(test_action);
  }

  d->context_menu->exec(mouse_position);

  if (additional_menu != nullptr) {
    d->context_menu->removeAction(additional_menu->menuAction());
  }
}

void Document::onCopyAction() {
  auto opt_selection = d->text_view->getSelection();
  if (!opt_selection.has_value()) {
    return;
  }

  const auto &selection = opt_selection.value();
  QApplication::clipboard()->setText(selection);
}

} // namespace multiplier
