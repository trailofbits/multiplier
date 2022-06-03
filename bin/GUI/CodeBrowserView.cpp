// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeBrowserView.h"

#include <multiplier/Index.h>
#include <QSplitter>
#include <QTabWidget>
#include <QVBoxLayout>

#include "CodeView.h"
#include "FileView.h"

namespace mx::gui {

struct CodeBrowserView::PrivateData {
  const Index index;
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
  QTabWidget *content{nullptr};

  PrivateData(const Index &index_)
      : index(index_) {}
};

CodeBrowserView::~CodeBrowserView(void) {}

CodeBrowserView::CodeBrowserView(const Index &index_, QWidget *parent_)
    : QWidget(parent_),
      d(new PrivateData(index_)) {}

}  // namespace mx::gui
