// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "FileView.h"

#include <QColor>
#include <QFont>
#include <QPainter>
#include <QSplitter>
#include <QString>
#include <QThreadPool>
#include <QVBoxLayout>
#include <iostream>
#include <map>
#include <vector>
#include <set>

namespace mx::gui {

struct FileView::PrivateData {
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
  CodeView *content;
};

FileView::~FileView(void) {}

FileView::FileView(Index index, std::filesystem::path file_path,
                   FileId file_id, const CodeTheme &theme, QWidget *parent)
    : QTabWidget(parent),
      d(std::make_unique<PrivateData>()) {

  QList<int> splitter_sizes;

  setMovable(true);
  setTabsClosable(true);
  setDocumentMode(true);
  setTabPosition(TabPosition::North);
  setWindowTitle(file_path.c_str());

  d->splitter = new QSplitter(Qt::Horizontal);
  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);
  d->layout->addWidget(d->splitter);
  setLayout(d->layout);

  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);

  d->content = new CodeView(theme);
  d->splitter->addWidget(d->content);
  d->content->SetFile(std::move(index), file_id);

  connect(d->content, &CodeView::DeclarationsClicked,
          this, &FileView::OnDeclarationsClicked);
}

void FileView::OnDeclarationsClicked(std::vector<RawEntityId> ids,
                                     Qt::MouseButton button) {
  emit DeclarationsClicked(std::move(ids), button);
}

}  // namespace mx::gui
