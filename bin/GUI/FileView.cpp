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

#include <multiplier/Index.h>

#include "CodeView.h"
#include "Configuration.h"
#include "Multiplier.h"

namespace mx::gui {

struct FileView::PrivateData {
  FileConfiguration &config;
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
  CodeView *content{nullptr};

  inline PrivateData(FileConfiguration &config_)
      : config(config_) {}
};

FileView::~FileView(void) {}

FileView::FileView(Multiplier &multiplier,
                   std::filesystem::path file_path,
                   FileId file_id, QWidget *parent)
    : QTabWidget(parent),
      d(std::make_unique<PrivateData>(multiplier.Configuration().file)) {

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

  d->content = new CodeView(multiplier.CodeTheme());
  d->splitter->addWidget(d->content);
  d->content->SetFile(multiplier.Index(), file_id);

  MX_CONNECT_CHILD_ACTIONS(d->config, FileView, CodeView)
  MX_ROUTE_ACTIONS(d->config, FileView, multiplier)
}

MX_DEFINE_DECLARATION_SLOTS(FileView, d->config)

}  // namespace mx::gui
