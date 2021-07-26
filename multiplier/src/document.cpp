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
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QSplitter>
#include <QTreeWidget>
#include <QVBoxLayout>

namespace multiplier {

struct Document::PrivateData final {
  QString original_compile_command;

  QLineEdit *source_file_path{nullptr};
  QLineEdit *working_directory{nullptr};
  QPlainTextEdit *compile_command{nullptr};
  QTreeWidget *tu_tree{nullptr};

  tob::widgets::ITextModel::Ptr code_model;
  tob::widgets::ITextView *code_view{nullptr};

  tob::widgets::ITextModel::Ptr ast_model;
  tob::widgets::ITextView *ast_view{nullptr};

  QMenu *context_menu{nullptr};
  QAction *copy_action{nullptr};
};

Document::Document(const QString &source_file_path, const QString &working_directory,
                   const QString &compile_command, QWidget *parent)
    : QFrame(parent), d(new PrivateData) {

  d->original_compile_command = compile_command;

  // Initialize the text view theme
  TextViewTheme theme;
  theme.background = QColor::fromRgba(0xFF101010);
  theme.foreground = QColor::fromRgba(0xFFC7C7C7);
  theme.color_map.insert({0, QColor::fromRgba(0xFFFF8272)});
  theme.color_map.insert({1, QColor::fromRgba(0xFFB4FA72)});
  theme.color_map.insert({2, QColor::fromRgba(0xFFFEFDC2)});
  theme.color_map.insert({3, QColor::fromRgba(0xFFA5D5FE)});
  theme.color_map.insert({4, QColor::fromRgba(0xFFFF8FFD)});
  theme.color_map.insert({5, QColor::fromRgba(0xFFD0D1FE)});
  theme.color_map.insert({6, QColor::fromRgba(0xFFF1F1F1)});

  // Create the AST view
  d->ast_model = std::make_shared<ASTModel>(working_directory, compile_command);
  d->ast_view = ITextView::create();
  d->ast_view->setTheme(theme);

  connect(d->ast_view, SIGNAL(tokenClicked(const QPoint &, const Qt::MouseButton &, TokenID)), this,
          SLOT(onASTItemClicked(const QPoint &, const Qt::MouseButton &, TokenID)));

  // Create the code view
  d->code_model = std::make_shared<SourceCodeModel>(source_file_path);

  d->code_view = ITextView::create();
  d->code_view->setTheme(theme);
  d->code_view->setModel(d->code_model);

  connect(d->code_view, SIGNAL(tokenClicked(const QPoint &, const Qt::MouseButton &, TokenID)),
          this, SLOT(onSourceCodeItemClicked(const QPoint &, const Qt::MouseButton &, TokenID)));

  // Create the compile command editor
  auto src_and_cwd_layout = new QFormLayout();

  d->source_file_path = new QLineEdit(source_file_path);
  d->source_file_path->setReadOnly(true);
  src_and_cwd_layout->addRow(tr("Source file"), d->source_file_path);

  d->working_directory = new QLineEdit(working_directory);
  d->working_directory->setReadOnly(true);
  src_and_cwd_layout->addRow(tr("Working directory"), d->working_directory);

  d->compile_command = new QPlainTextEdit();
  d->compile_command->setPlainText(compile_command);

  auto tu_settings_layout = new QVBoxLayout();
  tu_settings_layout->addLayout(src_and_cwd_layout);
  tu_settings_layout->addWidget(new QLabel(tr("Compile command")));
  tu_settings_layout->addWidget(d->compile_command);

  auto apply_button = new QPushButton(tr("Apply"));
  connect(apply_button, &QPushButton::clicked, this, &Document::onApplyCommandLineChanges);

  auto reset_button = new QPushButton(tr("Reset"));
  connect(reset_button, &QPushButton::clicked, this, &Document::onResetCommandLine);

  auto buttons_layout = new QHBoxLayout();
  buttons_layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding));
  buttons_layout->addWidget(reset_button);
  buttons_layout->addWidget(apply_button);

  tu_settings_layout->addLayout(buttons_layout);

  d->tu_tree = new QTreeWidget();
  d->tu_tree->setHeaderHidden(true);
  d->tu_tree->setExpandsOnDoubleClick(false);

  connect(d->tu_tree, &QTreeWidget::itemActivated, this,
          &Document::onTranslationUnitTreeItemClicked);

  auto compile_command_layout = new QHBoxLayout();
  compile_command_layout->addLayout(tu_settings_layout);
  compile_command_layout->addWidget(d->tu_tree);

  // Setup the layout
  auto main_layout = new QVBoxLayout();
  main_layout->setContentsMargins(0, 0, 0, 0);
  setLayout(main_layout);

  auto main_splitter = new QSplitter(Qt::Vertical);
  main_layout->addWidget(main_splitter);

  auto tu_cmd_splitter = new QSplitter();
  main_splitter->addWidget(tu_cmd_splitter);

  auto compile_command_editor = new QWidget();
  compile_command_editor->setLayout(compile_command_layout);

  tu_cmd_splitter->addWidget(compile_command_editor);
  tu_cmd_splitter->addWidget(d->tu_tree);

  auto code_ast_splitter = new QSplitter();
  main_splitter->addWidget(code_ast_splitter);

  code_ast_splitter->addWidget(d->ast_view);
  code_ast_splitter->addWidget(d->code_view);

  QList<int> size_list;
  size_list.push_back(main_splitter->height() / 4);
  size_list.push_back(main_splitter->height() - size_list.back());

  main_splitter->setSizes(size_list);

  // Initialize the context menu
  d->context_menu = new QMenu(tr("Context menu"));

  d->copy_action = new QAction(tr("Copy"));
  connect(d->copy_action, &QAction::triggered, this, &Document::onCopyAction);

  d->context_menu->addAction(d->copy_action);

  // Force a ui update
  onApplyCommandLineChanges();
}

Document::~Document() {}

void Document::onSourceCodeItemClicked(const QPoint &mouse_position, const Qt::MouseButton &button,
                                       TokenID token_id) {

  if (button == Qt::RightButton) {
    d->copy_action->setEnabled(d->code_view->hasSelection());

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

  } else if (button == Qt::LeftButton) {
    // Token group highlight example; you can also check `button` to only
    // handle left clicks
    auto token_group = d->code_model->tokenGroupID(token_id);
    if (token_group != kInvalidTokenGroupID) {
      d->ast_view->highlightTokenGroup(token_group);
      d->code_view->highlightTokenGroup(token_group);
    }
  }
}

void Document::onASTItemClicked(const QPoint &mouse_position, const Qt::MouseButton &button,
                                TokenID token_id) {
  if (button == Qt::RightButton) {
    d->copy_action->setEnabled(d->code_view->hasSelection());

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

  } else if (button == Qt::LeftButton) {
    // Token group highlight example; you can also check `button` to only
    // handle left clicks
    auto token_group = d->ast_model->tokenGroupID(token_id);
    if (token_group != kInvalidTokenGroupID) {
      d->code_view->highlightTokenGroup(token_group);
      d->ast_view->highlightTokenGroup(token_group);
    }
  }
}

void Document::onCopyAction() {
  auto opt_selection = d->code_view->getSelection();
  if (!opt_selection.has_value()) {
    return;
  }

  const auto &selection = opt_selection.value();
  QApplication::clipboard()->setText(selection);
}

void Document::onApplyCommandLineChanges() {
  auto compile_command = d->compile_command->toPlainText();

  d->ast_model = std::make_shared<ASTModel>(d->working_directory->text(), compile_command);
  d->ast_view->setModel(d->ast_model);

  // In case we want/need to wait for the AST model to finish
  // connect(d->model.get(), SIGNAL(modelReset()), this, SLOT(onModelReset()));

  d->tu_tree->clear();

  auto root_item = new QTreeWidgetItem({tr("Root"), d->source_file_path->text()});
  d->tu_tree->addTopLevelItem(root_item);

  root_item->addChild(new QTreeWidgetItem(root_item, {"File name 1", "File path"}));

  auto child2 = new QTreeWidgetItem(root_item, {"File name 2", "File path"});
  root_item->addChild(child2);
  root_item->addChild(new QTreeWidgetItem(child2, {"File name 3", "File path"}));

  d->tu_tree->expandAll();
}

void Document::onResetCommandLine() {
  d->compile_command->setPlainText(d->original_compile_command);
  onApplyCommandLineChanges();
}

void Document::onTranslationUnitTreeItemClicked(QTreeWidgetItem *item, int) {
  auto file_name = item->text(0);
  static_cast<void>(file_name);

  auto file_path = item->text(1);
  static_cast<void>(file_path);

  // Force opening the same file for now
  file_path = d->source_file_path->text();

  d->code_model = std::make_shared<SourceCodeModel>(file_path);
  d->code_view->setModel(d->code_model);
}

} // namespace multiplier
