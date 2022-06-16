// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeBrowserView.h"

#include <QSplitter>
#include <QTabWidget>
#include <QThreadPool>
#include <QVBoxLayout>

#include <algorithm>
#include <atomic>
#include <cassert>
#include <unordered_map>

#include "CodeView.h"
#include "FileView.h"
#include "Multiplier.h"
#include "Util.h"

#include <iostream>

namespace mx::gui {

struct CodeBrowserView::PrivateData {
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
  QTabWidget *content{nullptr};

  std::unordered_map<FileId, FileView *> file_id_to_view;
  std::unordered_map<QWidget *, FileId> view_to_file_id;
  std::unordered_map<FileId, std::filesystem::path> file_id_to_path;

  std::atomic<unsigned> counter;

  PrivateData(Multiplier &multiplier_)
      : multiplier(multiplier_) {}
};

struct LocateEntitiesThread::PrivateData {
  const Index index;
  const EventLocations locs;
  const unsigned counter;
  std::vector<FileId> seen_file_ids;

  inline PrivateData(const Index &index_, const EventLocations &ids_,
                     unsigned counter_)
      : index(index_),
        locs(ids_),
        counter(counter_) {}
};

LocateEntitiesThread::~LocateEntitiesThread(void) {}

LocateEntitiesThread::LocateEntitiesThread(
    const Index &index_, const EventLocations &ids_, unsigned counter_)
    : d(new PrivateData(index_, ids_, counter_)) {}

void LocateEntitiesThread::RunOnToken(Token file_tok) {
  FileId file_id = File::containing(file_tok)->id();
  if (std::find(d->seen_file_ids.begin(), d->seen_file_ids.end(), file_id) ==
      d->seen_file_ids.end()) {
    emit OpenEntityInFile(file_id, file_tok.id(), d->counter);
    d->seen_file_ids.push_back(file_id);
  }
}

void LocateEntitiesThread::run(void) {
  d->seen_file_ids.reserve(d->locs.Size());

  for (const EventLocation &loc : d->locs) {

    auto entity = d->index.entity(loc.FileTokenId());
    if (std::holds_alternative<Token>(entity)) {
      if (auto file_tok = std::get<Token>(entity).nearest_file_token()) {

        RunOnToken(std::move(file_tok.value()));
        continue;
      }
    }

    entity = d->index.entity(loc.FragmentTokenId());
    if (std::holds_alternative<Token>(entity)) {
      if (auto file_tok = std::get<Token>(entity).nearest_file_token()) {
        RunOnToken(std::move(file_tok.value()));
        continue;
      }
    }

    entity = d->index.entity(loc.DeclarationId());
    if (std::holds_alternative<Decl>(entity)) {
      if (auto file_tok = DeclFileToken(std::get<Decl>(entity))) {
        RunOnToken(std::move(file_tok.value()));
        continue;
      }
    }
  }
}

CodeBrowserView::~CodeBrowserView(void) {}

CodeBrowserView::CodeBrowserView(Multiplier &multiplier_, QWidget *parent_)
    : QWidget(parent_),
      d(new PrivateData(multiplier_)) {

  setWindowTitle(tr("Code Browser"));
  InitializeWidgets();
}

void CodeBrowserView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);
  setLayout(d->layout);

  d->splitter = new QSplitter(Qt::Horizontal);
  d->layout->addWidget(d->splitter);

  QList<int> splitter_sizes;
  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);

  d->content = new QTabWidget;
  d->content->setTabsClosable(true);
  d->content->setMovable(true);
  d->content->setDocumentMode(true);
  d->content->setUsesScrollButtons(true);

  d->splitter->addWidget(d->content);

  connect(d->content, &QTabWidget::tabCloseRequested,
          this, &CodeBrowserView::OnCloseFileViewTab);

  connect(d->content, &QTabWidget::currentChanged,
          this, &CodeBrowserView::OnChangeTab);
}

// When a tab is changed.
void CodeBrowserView::OnChangeTab(int index) {
  if (auto view = d->content->widget(index)) {
    if (auto it = d->view_to_file_id.find(view);
        it != d->view_to_file_id.end()) {
      emit CurrentFile(it->second);
    }
  }
}

void CodeBrowserView::OnCloseFileViewTab(int index) {
  if (QWidget *view = d->content->widget(index)) {
    const FileId file_id = d->view_to_file_id[view];
    assert(file_id != kInvalidEntityId);

    d->view_to_file_id.erase(view);
    d->file_id_to_view.erase(file_id);
    d->content->removeTab(index);
  }
}

void CodeBrowserView::OnDownloadedFileList(FilePathList files) {
  Clear();
  d->file_id_to_path.clear();
  for (auto &[path_, file_id_] : files) {
    std::filesystem::path path = path_;
    FileId file_id = file_id_;
    d->file_id_to_path.emplace(file_id, std::move(path));
  }
}

// Scroll to a specific target location in a file. If the file isn't open yet
// then open it. If it is open but not the active view, then set it to the
// active view.
void CodeBrowserView::ScrollToTokenInFile(
    FileId file_id, RawEntityId scroll_target, unsigned counter) {

  std::filesystem::path path;
  auto path_it = d->file_id_to_path.find(file_id);
  if (path_it == d->file_id_to_path.end()) {
    static const std::filesystem::path kUnknown = tr("unknown").toStdString();
    path = kUnknown;
  } else {
    path = path_it->second;
  }

  auto current_tab = d->content->currentWidget();
  auto out_of_order = counter != d->counter.load();

  OpenFile(std::move(path), file_id);

  auto view_it = d->file_id_to_view.find(file_id);
  if (view_it == d->file_id_to_view.end()) {
    return;  // Strange.
  }

  // If this scroll request came out of order, then ignore it.
  if (out_of_order) {
    d->content->setCurrentWidget(current_tab);

  // Otherwise,  open it up and scroll to the specified location.
  } else {
    d->content->setCurrentWidget(view_it->second);

    if (scroll_target != kInvalidEntityId) {
      view_it->second->ScrollToToken(scroll_target);
    }
  }
}

void CodeBrowserView::Clear(void) {
  d->file_id_to_view.clear();
  d->view_to_file_id.clear();
  d->content->clear();
}

// Open a file in a tab.
//
// NOTE(pag): This does not set the file to be the active widget.
void CodeBrowserView::OpenFile(std::filesystem::path path, mx::FileId file_id,
                               bool show) {
  FileView *&file_view = d->file_id_to_view[file_id];
  if (!file_view) {
    file_view = new FileView(d->multiplier, path, file_id,
                             EventSource::kCodeBrowser);

    d->view_to_file_id.emplace(file_view, file_id);

    auto tab_index = d->content->addTab(
        file_view, QString("%1").arg(path.filename().c_str()));

#ifndef QT_NO_TOOLTIP
    d->content->setTabToolTip(
        tab_index, QString::fromStdString(path.generic_string()));
#endif
  }

  if (show) {
    d->content->setCurrentWidget(file_view);
  }
}

// Request for one or more entities to be opened.
void CodeBrowserView::OpenEntities(const EventLocations &locs) {
  auto locator = new LocateEntitiesThread(
      d->multiplier.Index(), locs, d->counter.fetch_add(1u) + 1u);

  locator->setAutoDelete(true);

  connect(locator, &LocateEntitiesThread::OpenEntityInFile,
          this, &CodeBrowserView::ScrollToTokenInFile);

  QThreadPool::globalInstance()->start(locator);
  update();
}

}  // namespace mx::gui
