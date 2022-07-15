// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeBrowserView.h"

#include <QTabBar>
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
#include "OmniBoxView.h"
#include "Util.h"

#include <iostream>

namespace mx::gui {

struct CodeBrowserView::PrivateData {
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QTabWidget *content{nullptr};
  OmniBoxView *omnibox{nullptr};

  std::unordered_map<RawEntityId, FileView *> file_id_to_view;
  std::unordered_map<QWidget *, RawEntityId> view_to_file_id;
  std::unordered_map<RawEntityId, std::filesystem::path> file_id_to_path;

  std::atomic<unsigned> counter;

  PrivateData(Multiplier &multiplier_)
      : multiplier(multiplier_) {}
};

struct LocateEntitiesThread::PrivateData {
  const Index index;
  const EventLocations locs;
  const unsigned counter;
  std::vector<RawEntityId> seen_file_ids;

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
  RawEntityId file_id = File::containing(file_tok)->id();
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

    assert(false);  // Hrmm...
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

  d->content = new QTabWidget;
  d->content->setTabsClosable(true);
  d->content->setMovable(true);
  d->content->setDocumentMode(true);
  d->content->setUsesScrollButtons(true);
  d->layout->addWidget(d->content);

  auto tab_bar = d->content->tabBar();

  // Make the omnibox, and make it non-closable.
  d->omnibox = new OmniBoxView(d->multiplier);
  auto omni_index = d->content->addTab(d->omnibox, d->omnibox->windowTitle());
#ifndef QT_NO_TOOLTIP
  d->content->setTabToolTip(omni_index, d->omnibox->windowTitle());
#endif
  d->content->setCurrentWidget(d->omnibox);
  tab_bar->setTabButton(omni_index, QTabBar::LeftSide, nullptr);
  tab_bar->setTabButton(omni_index, QTabBar::RightSide, nullptr);

  d->content->hide();

  connect(d->content, &QTabWidget::tabCloseRequested,
          this, &CodeBrowserView::OnCloseFileViewTab);

  connect(d->content, &QTabWidget::currentChanged,
          this, &CodeBrowserView::OnChangeTab);
}

// When a tab is changed.
void CodeBrowserView::OnChangeTab(int index) {
  if (auto view = d->content->widget(index); view) {
    if (view == d->omnibox) {
      d->omnibox->Focus();

    } else if (auto it = d->view_to_file_id.find(view);
        it != d->view_to_file_id.end()) {
      emit CurrentFile(it->second);
    }
  }
}

void CodeBrowserView::OnCloseFileViewTab(int index) {
  if (QWidget *view = d->content->widget(index); view && view != d->omnibox) {
    if (auto file_it = d->view_to_file_id.find(view);
        file_it != d->view_to_file_id.end()) {
      const RawEntityId file_id = file_it->second;
      assert(file_id != kInvalidEntityId);

      d->view_to_file_id.erase(view);
      d->file_id_to_view.erase(file_id);
    }

    d->content->removeTab(index);
  }
}

void CodeBrowserView::OnDownloadedFileList(FilePathList files) {
  for (auto &[path_, file_id_] : files) {
    std::filesystem::path path = path_;
    RawEntityId file_id = file_id_;
    d->file_id_to_path.emplace(file_id, std::move(path));
  }
}

// Scroll to a specific target location in a file. If the file isn't open yet
// then open it. If it is open but not the active view, then set it to the
// active view.
void CodeBrowserView::ScrollToTokenInFile(
    RawEntityId file_id, RawEntityId file_token_id, unsigned counter) {

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

    if (file_token_id != kInvalidEntityId) {
      view_it->second->ScrollToToken(file_token_id);
    }
  }
}

void CodeBrowserView::Clear(void) {
  d->file_id_to_view.clear();
  d->view_to_file_id.clear();
  d->omnibox->Clear();

  for (auto i = 0, max_i = d->content->count(); i < max_i;) {
    if (auto item = d->content->widget(i)) {
      if (item == d->omnibox) {
        ++i;
      } else {
        d->content->removeTab(i);
        item->disconnect();
        item->deleteLater();
        i = 0;
        max_i -= 1;
      }
    }
  }
}

void CodeBrowserView::Disconnected(void) {
  d->omnibox->Disconnected();
  d->content->hide();
  update();
}

void CodeBrowserView::Connected(void) {
  d->omnibox->Connected();
  d->content->show();
  update();
}

// Return the omnibox.
OmniBoxView *CodeBrowserView::OmniBox(void) {
  return d->omnibox;
}

void CodeBrowserView::OpenWeggliSearch(void) {
  d->content->setCurrentWidget(d->omnibox);
  d->omnibox->raise();
  d->omnibox->OpenWeggliSearch();
}

void CodeBrowserView::OpenRegexSearch(void) {
  d->content->setCurrentWidget(d->omnibox);
  d->omnibox->raise();
  d->omnibox->OpenRegexSearch();
}

void CodeBrowserView::OpenEntitySearch(void) {
  d->content->setCurrentWidget(d->omnibox);
  d->omnibox->raise();
  d->omnibox->OpenEntitySearch();
}

// Open a file in a tab.
//
// NOTE(pag): This does not set the file to be the active widget.
void CodeBrowserView::OpenFile(std::filesystem::path path,
                               mx::RawEntityId file_id,
                               bool show) {
  FileView *&file_view = d->file_id_to_view[file_id];
  if (!file_view) {
    file_view = new FileView(d->multiplier, path, file_id);

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

// Open a custom tab.
void CodeBrowserView::OpenCustom(const QString &tab_name, QWidget *contents) {
  auto tab_index = d->content->addTab(contents, tab_name);

#ifndef QT_NO_TOOLTIP
  d->content->setTabToolTip(tab_index, tab_name);
#endif

  d->content->setCurrentWidget(contents);
}

}  // namespace mx::gui
