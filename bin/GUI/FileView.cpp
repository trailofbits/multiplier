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

FileView::FileView(Multiplier &multiplier, std::filesystem::path file_path,
                   RawEntityId file_id, QWidget *parent)
    : QWidget(parent),
      d(std::make_unique<PrivateData>(multiplier.Configuration().file)) {

  setWindowTitle(file_path.c_str());

  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);
  setLayout(d->layout);

  d->content = new CodeView(multiplier.CodeTheme(),
                            multiplier.FileLocationCache());
  d->layout->addWidget(d->content);
  d->content->SetFile(multiplier.Index(), file_id);
  d->content->viewport()->installEventFilter(&multiplier);

  connect(d->content, &CodeView::TokenPressEvent,
          this, &FileView::ActOnTokenPressEvent);

  connect(this, &FileView::TokenPressEvent,
          &multiplier, &Multiplier::ActOnTokenPressEvent);
}

void FileView::ScrollToToken(RawEntityId file_tok_id) const {
  d->content->ScrollToFileToken(file_tok_id);
}

void FileView::ActOnTokenPressEvent(EventLocations locs) {

  // NOTE(pag): This is ugly. Often, we want a click in the code view to
  //            go to the referenced declaration, not just go back to
  //            itself. Therefore, we need to "mute" some of the components
  //            that we actually have data for.

  for (EventLocation loc : locs) {
    emit TokenPressEvent(EventSource::kCodeBrowserClickSource, loc);
    if (loc.UnpackDeclarationId()) {
      loc.SetFragmentTokenId(kInvalidEntityId);
      loc.SetFileTokenId(kInvalidEntityId);
      emit TokenPressEvent(EventSource::kCodeBrowserClickDest, loc);
    }
  }
}

}  // namespace mx::gui
