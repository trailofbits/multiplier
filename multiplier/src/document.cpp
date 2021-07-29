/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "document.h"
#include "astbuilder.h"
#include "astindex.h"
#include "parsedfilesindex.h"
#include "sourcecodemodel.h"

#include <iostream>

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QFormLayout>
#include <QLabel>
#include <QMenu>
#include <QMetaType>
#include <QPlainTextEdit>
#include <QSplitter>
#include <QString>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

Q_DECLARE_METATYPE(std::shared_ptr<pasta::AST>)

namespace multiplier {

struct Document::PrivateData final {
  inline PrivateData(const pasta::CompileJob &job_) : job(job_) {}

  const pasta::CompileJob job;
  ParsedFilesIndex *tu_tree{nullptr};

  std::string current_open_path;
  tob::widgets::ITextModel::Ptr code_model;
  tob::widgets::ITextView *code_view{nullptr};

  ASTIndex *ast_tree{nullptr};

  QMenu *context_menu{nullptr};
  QAction *copy_action{nullptr};
};

Document::Document(const pasta::CompileJob &job, QWidget *parent)
    : QFrame(parent), d(new PrivateData(job)) {

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

  // Two custom tree views.
  d->ast_tree = new ASTIndex;
  d->tu_tree = new ParsedFilesIndex;

  // Create the code view
  d->code_model = std::make_shared<SourceCodeModel>();
  d->code_view = ITextView::create();
  d->code_view->setTheme(theme);
  d->code_view->setModel(d->code_model);

  // Create an AST builder that will run the compile job in a background thread
  // and then emit signals when it has been built.
  ASTBuilder *make_ast = new ASTBuilder(job);
  make_ast->setAutoDelete(true);

  // Tell the models when we get an AST.
  connect(make_ast, SIGNAL(gotAST(std::shared_ptr<pasta::AST>)), d->ast_tree,
          SLOT(gotAST(std::shared_ptr<pasta::AST>)));

  connect(make_ast, SIGNAL(gotAST(std::shared_ptr<pasta::AST>)), d->code_model.get(),
          SLOT(gotAST(std::shared_ptr<pasta::AST>)));

  connect(make_ast, SIGNAL(gotAST(std::shared_ptr<pasta::AST>)), d->tu_tree,
          SLOT(gotAST(std::shared_ptr<pasta::AST>)));

  // Start up AST construction in a background thread.
  connect(d->ast_tree, &ASTIndex::clickedDecl, this, &Document::highlightDecl);

  connect(d->tu_tree, &ParsedFilesIndex::parsedFileDoubleClicked, this,
          &Document::displayParsedFile);

  connect(d->code_view, SIGNAL(tokenClicked(const QPoint &, const Qt::MouseButton &, TokenID)),
          this, SLOT(onSourceCodeItemClicked(const QPoint &, const Qt::MouseButton &, TokenID)));

  auto tp = QThreadPool::globalInstance();
  tp->start(make_ast);

  // Setup the layout
  auto main_layout = new QVBoxLayout();
  main_layout->setContentsMargins(0, 0, 0, 0);
  setLayout(main_layout);

  auto tu_ast_splitter = new QSplitter(Qt::Vertical);
  tu_ast_splitter->addWidget(d->tu_tree);
  tu_ast_splitter->addWidget(d->ast_tree);

  auto main_splitter = new QSplitter(Qt::Horizontal);
  main_splitter->addWidget(tu_ast_splitter);
  main_splitter->addWidget(d->code_view);
  main_layout->addWidget(main_splitter);

  QList<int> main_splitter_size_list;
  main_splitter_size_list.push_back(main_splitter->width() / 5);
  main_splitter_size_list.push_back(main_splitter->width() - main_splitter_size_list.back());
  main_splitter->setSizes(main_splitter_size_list);

  // Initialize the context menu
  d->context_menu = new QMenu(tr("Context menu"));

  d->copy_action = new QAction(tr("Copy"));
  connect(d->copy_action, &QAction::triggered, this, &Document::onCopyAction);

  d->context_menu->addAction(d->copy_action);
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
      d->code_view->highlightTokenGroup(token_group);
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

void Document::highlightDecl(pasta::Decl decl) {

  std::optional<pasta::FileToken> opt_begin_loc;
  std::optional<pasta::FileToken> opt_end_loc;

  auto loc_range = decl.TokenRange();
  if (auto num_toks = loc_range.Size()) {
    opt_begin_loc = loc_range[0].FileLocation();
    opt_end_loc = loc_range[num_toks - 1u].FileLocation();
  } else {
    opt_begin_loc = decl.Token().FileLocation();
    opt_end_loc = opt_begin_loc;
  }

  if (!opt_begin_loc || !opt_end_loc) {
    return;
  }

  auto begin_loc = std::move(*opt_begin_loc);
  auto end_loc = std::move(*opt_end_loc);

  if (!(begin_loc <= end_loc)) {
    return;
  }

  // Make sure we're showing the right code.
  auto file = pasta::File::Containing(begin_loc);
  displayParsedFile(std::move(file));

  // Now go and highlight the correct tokens.
  std::unordered_set<TokenGroupID> token_groups;
  for (auto begin_id = begin_loc.Index(), end_id = end_loc.Index(); begin_id <= end_id;
       ++begin_id) {
    token_groups.insert(begin_id);
  }

  d->code_view->highlightTokenGroups(std::move(token_groups));
}

void Document::displayParsedFile(pasta::File file) {
  auto path = file.Path().generic_string();
  if (path != d->current_open_path) {
    d->current_open_path = std::move(path);
    d->code_model = std::make_shared<SourceCodeModel>(file);
    d->code_view->setModel(d->code_model);
  }
}

} // namespace multiplier
