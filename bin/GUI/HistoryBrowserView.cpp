// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "HistoryBrowserView.h"

#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

#include <multiplier/Index.h>
#include <unordered_map>

#include "Multiplier.h"
#include "Util.h"

#include <iostream>

namespace mx::gui {
namespace {

// Make a button as small as possible.
static void MakeSmall(QPushButton *button) {
  auto s = button->fontMetrics().size(Qt::TextShowMnemonic, button->text());
  QStyleOptionButton opt;
  opt.initFrom(button);
  opt.rect.setSize(s);
  button->setMaximumSize(
      button->style()->sizeFromContents(QStyle::CT_PushButton, &opt,
                                        s, button));
}

class ScopeReferenceCounted {
  int &ref;

 public:
  ScopeReferenceCounted(int &ref_)
      : ref(ref_) {
    ++ref;
  }

  ~ScopeReferenceCounted(void) {
    --ref;
  }
};

enum : int {
  kDeclaratioNameColumn,
  kBreadCrumbsColumn,
  kNumColumns
};

//struct HistoryItem {
//  EventLocation loc;
//  QTreeWidgetItem *item{nullptr};
//  unsigned version{0};
//
//  HistoryItem **next_ptr_to_self{nullptr};
//  HistoryItem *prev{nullptr};
//
//  explicit HistoryItem(const EventLocation &loc_)
//      : loc(loc_) {}
//};

static constexpr size_t kDefaultReadHead = 2;

}  // namespace

struct HistoryBrowserView::PrivateData {
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QLineEdit *filter_box{nullptr};

  QTreeWidget *history_tree{nullptr};

  QTreeWidgetItem *current_root{nullptr};
  QTreeWidgetItem *last_added{nullptr};

  QPushButton *clear_button{nullptr};
  QPushButton *root_button{nullptr};

  std::vector<QTreeWidgetItem *> linear_history;
  size_t read_head{kDefaultReadHead};

  int event_suppress{0};
  unsigned counter{1u};  // Version of this history view.

  std::unordered_map<QTreeWidgetItem *, EventLocation> item_to_loc;

  inline PrivateData(Multiplier &multiplier_)
      : multiplier(multiplier_) {}
};

HistoryBrowserView::~HistoryBrowserView(void) {}

HistoryBrowserView::HistoryBrowserView(Multiplier &multiplier_, QWidget *parent)
    : d(new PrivateData(multiplier_)) {
  InitializeWidgets();
}

void HistoryBrowserView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);

  // Create a filter widget area so that we can filter down on specific files.
  auto filter_area = new QWidget;
  auto filter_layout = new QHBoxLayout;
  filter_area->setLayout(filter_layout);

  d->filter_box = new QLineEdit;
  auto label = new QLabel(tr("Filter:"));
  filter_layout->addWidget(label);
  filter_layout->addWidget(d->filter_box);

  QSizePolicy sp(QSizePolicy::Maximum, QSizePolicy::Minimum);
  label->setSizePolicy(sp);

  sp.setHorizontalPolicy(QSizePolicy::Minimum);
  d->filter_box->setSizePolicy(sp);

  d->clear_button = new QPushButton("Х");
  d->root_button = new QPushButton("⇡");
  MakeSmall(d->clear_button);
  MakeSmall(d->root_button);
  filter_layout->addWidget(d->clear_button);
  filter_layout->addWidget(d->root_button);

  d->layout->addWidget(filter_area);

  // Below the filter put the source tree.
  d->history_tree = new QTreeWidget;
  d->layout->addWidget(d->history_tree);

  setWindowTitle(tr("History Browser"));
  setLayout(d->layout);

  // Try to capture keypresses when items are selected.
  d->history_tree->viewport()->installEventFilter(&(d->multiplier));

  d->history_tree->setSelectionMode(
      QAbstractItemView::SelectionMode::SingleSelection);
  d->history_tree->setHeaderHidden(true);
  d->history_tree->expandAll();
  d->history_tree->setItemsExpandable(false);
  d->history_tree->setColumnCount(kNumColumns);
  d->history_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->history_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->history_tree->header()->setStretchLastSection(true);
  d->history_tree->setAutoScroll(true);

  connect(d->history_tree, &QTreeWidget::itemPressed,
          this, &HistoryBrowserView::OnTreeWidgetItemClicked);

  connect(d->history_tree, &QTreeWidget::itemDoubleClicked,
          this, &HistoryBrowserView::OnTreeWidgetItemDoubleClicked);

  connect(d->history_tree, &QTreeWidget::itemSelectionChanged,
          this, &HistoryBrowserView::OnTreeWidgetItemSelectionChanged);

  connect(d->filter_box, &QLineEdit::textChanged,
          this, &HistoryBrowserView::OnFilterHistoryView);

  connect(d->filter_box, &QLineEdit::textChanged,
          this, &HistoryBrowserView::OnFilterHistoryView);

  connect(d->clear_button, &QPushButton::pressed,
          this, &HistoryBrowserView::Clear);

  connect(d->root_button, &QPushButton::pressed,
          this, &HistoryBrowserView::OnRootButton);
}

// Add the declarations to the history nested under the current selected root.
void HistoryBrowserView::AddDeclarationsUnderRoot(const EventLocations &locs) {

  // Double check its sanity.
  if (d->current_root) {
    auto root_it = d->item_to_loc.find(d->current_root);
    if (root_it == d->item_to_loc.end()) {
      d->current_root = nullptr;
    }
  }

  bool is_first = true;
  for (EventLocation loc : locs) {

    ScopeReferenceCounted suppress_event(d->event_suppress);

    QTreeWidgetItem *item = nullptr;
    auto history_index = loc.HistoryItem();
    loc.SetHistoryItem(static_cast<unsigned>(d->linear_history.size()));

    if (history_index && *history_index < d->linear_history.size()) {
      item = d->linear_history[*history_index];

    } else {
      auto &index = d->multiplier.Index();
      auto entity = index.entity(loc.DeclarationId());
      if (!std::holds_alternative<Decl>(entity)) {
        continue;
      }

      // Fix up any missing info in the location using the decl as our anchor.
      Decl decl = std::move(std::get<Decl>(entity));
      if (std::optional<Token> frag_tok = DeclFragmentToken(decl)) {
        if (!loc.UnpackFragmentTokenId()) {
          loc.SetFragmentTokenId(frag_tok->id());
        }
        if (!loc.UnpackFileTokenId()) {
          if (auto file_tok = frag_tok->nearest_file_token()) {
            loc.SetFileTokenId(file_tok->id());
          }
        }
      }

      item = new QTreeWidgetItem;
      item->setText(kDeclaratioNameColumn, DeclName(decl));
      item->setText(kBreadCrumbsColumn, "");

      d->item_to_loc.emplace(item, loc);

      if (!d->current_root) {
        d->history_tree->addTopLevelItem(item);
      } else {
        d->current_root->addChild(item);
        d->current_root->setExpanded(true);
      }
    }

    d->read_head = kDefaultReadHead;
    d->linear_history.push_back(item);

    d->history_tree->scrollToItem(item);
    d->history_tree->clearSelection();
    d->history_tree->setCurrentItem(item);
    d->history_tree->setItemSelected(item, is_first);
    d->last_added = item;

    if (is_first) {
      emit TokenPressEvent(EventSource::kHistoryBrowser, loc);
      is_first = false;
    }
  }
}

// Go back one step in the linear history.
bool HistoryBrowserView::GoBackInLinearHistory(void) {
  auto history_size = d->linear_history.size();
  if (d->read_head > history_size) {
    return false;
  }

  assert(0 < d->read_head);

  auto item = d->linear_history[history_size - d->read_head];
  auto it = d->item_to_loc.find(item);
  if (it == d->item_to_loc.end()) {
    return false;
  }

  EventLocations loc = it->second;
  auto old_read_head = d->read_head;
  AddDeclarationsUnderRoot(loc);
  d->read_head = old_read_head + 2;  // One for previous, one for just added.
  return true;
}

// Add the declarations to the history as siblings of the last added item.
void HistoryBrowserView::AddSiblingDeclarations(const EventLocations &locs) {

  auto prev_root = d->current_root;
  if (d->last_added) {
    d->current_root = d->last_added->parent();
  } else {
    d->current_root = nullptr;
  }

  AddDeclarationsUnderRoot(locs);
  d->current_root = prev_root;
}

// Add the declarations to the history as children of the last added item.
void HistoryBrowserView::AddChildDeclarations(const EventLocations &locs) {
  auto prev_root = d->current_root;
  d->current_root = d->last_added;
  AddDeclarationsUnderRoot(locs);
  d->current_root = prev_root;
}

// Add the declarations to the history view as top-level items.
void HistoryBrowserView::AddRootDeclarations(const EventLocations &locs) {
  auto prev_root = d->current_root;
  d->current_root = nullptr;
  AddDeclarationsUnderRoot(locs);
  d->current_root = prev_root;
}

void HistoryBrowserView::Clear(void) {
  d->filter_box->clear();
  d->history_tree->clear();
  d->current_root = nullptr;
  d->last_added = nullptr;
  d->item_to_loc.clear();
  d->counter++;
  d->read_head = kDefaultReadHead;
  d->linear_history.clear();
}

void HistoryBrowserView::Focus(void) {
  d->history_tree->setFocus();
}

void HistoryBrowserView::OnTreeWidgetItemClicked(
    QTreeWidgetItem *item, int) {
  if (d->event_suppress) {
    return;
  }

  ScopeReferenceCounted suppress_event(d->event_suppress);
  auto decl_it = d->item_to_loc.find(item);
  if (decl_it != d->item_to_loc.end()) {
    emit TokenPressEvent(EventSource::kHistoryBrowser, decl_it->second);
  }

  d->history_tree->setFocus();
  d->history_tree->setCurrentItem(item);
}

void HistoryBrowserView::mouseDoubleClickEvent(QMouseEvent *event) {
  this->QWidget::mouseDoubleClickEvent(event);
}

void HistoryBrowserView::OnTreeWidgetItemDoubleClicked(
    QTreeWidgetItem *item, int) {
  ScopeReferenceCounted suppress_event(d->event_suppress);

  auto decl_it = d->item_to_loc.find(item);
  if (decl_it == d->item_to_loc.end()) {
    return;
  }

  d->current_root = item;
}

// Selecting a different item, e.g. with up/down arrows, should act like a
// click.
void HistoryBrowserView::OnTreeWidgetItemSelectionChanged(void) {
  if (d->event_suppress) {
    return;
  }

  for (QTreeWidgetItem *item : d->history_tree->selectedItems()) {
    OnTreeWidgetItemClicked(item, 0);
    return;
  }
}

void HistoryBrowserView::OnFilterHistoryView(const QString &text) {
  if (!text.size()) {
    for (auto &[item, eid] : d->item_to_loc) {
      item->setHidden(false);
    }
  } else {
    for (auto &[item, eid] : d->item_to_loc) {
      item->setHidden(true);
    }

    for (auto &[item, eid] : d->item_to_loc) {
      if (item->text(0).contains(text)) {

        // Show all of the parents leading to a visible item.
        for (auto parent = item->parent(); parent; parent = parent->parent()) {
          parent->setHidden(false);
        }
        item->setHidden(false);
      }
    }
  }

  update();
}

void HistoryBrowserView::OnRootButton(void) {
  d->current_root = nullptr;
}

}  // namespace mx::gui
