// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "FileView.h"

#include <QColor>
#include <QFont>
#include <QPainter>
#include <QString>
#include <QVBoxLayout>

#include <multiplier/Index.h>

#include "CodeView.h"
#include "Configuration.h"
#include "Multiplier.h"

namespace mx::gui {

struct FileView::PrivateData {
  FileConfiguration &config;
  QVBoxLayout *layout{nullptr};
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


  setMovable(true);
  setTabsClosable(true);
  setDocumentMode(true);
  setTabPosition(TabPosition::North);
  setWindowTitle(file_path.c_str());

  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);
  setLayout(d->layout);

  d->content = new CodeView(multiplier.CodeTheme());
  d->layout->addWidget(d->content);
  d->content->SetFile(multiplier.Index(), file_id);

  MX_CONNECT_CHILD_ACTIONS(d->config, FileView, d->content, CodeView)
  MX_ROUTE_ACTIONS(d->config, FileView, multiplier)
}

void FileView::ScrollToToken(RawEntityId file_tok_id) const {
  d->content->ScrollToToken(file_tok_id);
}

MX_DEFINE_DECLARATION_SLOTS(FileView, d->config)

}  // namespace mx::gui
