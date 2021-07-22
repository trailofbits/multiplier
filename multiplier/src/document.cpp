/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "document.h"
#include "textmodel.h"

#include <tob/itextview.h>

#include <QPlainTextEdit>
#include <QSplitter>
#include <QVBoxLayout>

namespace multiplier {

struct Document::PrivateData final {
  tob::widgets::ITextModel::Ptr model;
  tob::widgets::ITextView *text_view{nullptr};
  QPlainTextEdit *ast_view{nullptr};
};

Document::Document(const QString &source_file_path, QWidget *parent)
    : QFrame(parent), d(new PrivateData) {
  d->model = std::make_shared<TextModel>(source_file_path);

  auto layout = new QVBoxLayout();
  setLayout(layout);

  auto splitter = new QSplitter();
  layout->addWidget(splitter);

  d->text_view = ITextView::create();
  d->text_view->setModel(d->model);
  splitter->addWidget(d->text_view);

  d->ast_view = new QPlainTextEdit();
  d->ast_view->setPlainText(tr("TODO"));
  d->ast_view->setReadOnly(true);
  splitter->addWidget(d->ast_view);
}

Document::~Document() {}

} // namespace multiplier
