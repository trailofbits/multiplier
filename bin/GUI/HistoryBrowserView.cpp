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

  int event_suppress{0};

  std::unordered_map<QTreeWidgetItem *, RawEntityId> item_to_decl;

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

  d->history_tree->setSelectionMode(
      QAbstractItemView::SelectionMode::SingleSelection);
  d->history_tree->setHeaderHidden(true);
  d->history_tree->expandAll();
  d->history_tree->setItemsExpandable(false);
  d->history_tree->setColumnCount(1);
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
          this, &HistoryBrowserView::OnClearButton);

  connect(d->root_button, &QPushButton::pressed,
          this, &HistoryBrowserView::OnRootButton);
}

// Add the declarations to the history nested under the current selected root.
void HistoryBrowserView::AddDeclarationsUnderRoot(
    std::vector<RawEntityId> ids) const {

  // Double check its sanity.
  if (d->current_root) {
    auto root_it = d->item_to_decl.find(d->current_root);
    if (root_it == d->item_to_decl.end()) {
      d->current_root = nullptr;
    }
  }

  for (RawEntityId eid : ids) {
    std::optional<Decl> decl = NearestDeclFor(d->multiplier.Index(), eid);
    if (!decl) {
      continue;
    }

    auto *item = new QTreeWidgetItem;
    item->setText(0, DeclName(decl.value()));

    ScopeReferenceCounted suppress_event(d->event_suppress);

    d->item_to_decl.emplace(item, eid);

    if (!d->current_root) {
      d->history_tree->addTopLevelItem(item);
    } else {
      d->current_root->addChild(item);
      d->current_root->setExpanded(true);
    }

    d->history_tree->scrollToItem(item);
    d->history_tree->clearSelection();
    d->history_tree->setCurrentItem(item);
    d->history_tree->setItemSelected(item, true);
    d->last_added = item;
  }
}

// Add the declarations to the history as siblings of the last added item.
void HistoryBrowserView::AddSiblingDeclarations(
    std::vector<RawEntityId> ids) const {

  auto prev_root = d->current_root;
  if (d->last_added) {
    d->current_root = d->last_added->parent();
  } else {
    d->current_root = nullptr;
  }

  AddDeclarationsUnderRoot(std::move(ids));
  d->current_root = prev_root;
}

// Add the declarations to the history as children of the last added item.
void HistoryBrowserView::AddChildDeclarations(
    std::vector<RawEntityId> ids) const {

  auto prev_root = d->current_root;
  d->current_root = d->last_added;
  AddDeclarationsUnderRoot(std::move(ids));
  d->current_root = prev_root;
}

// Add the declarations to the history view as top-level items.
void HistoryBrowserView::AddRootDeclarations(
    std::vector<RawEntityId> ids) const {
  auto prev_root = d->current_root;
  d->current_root = nullptr;
  AddDeclarationsUnderRoot(std::move(ids));
  d->current_root = prev_root;
}

void HistoryBrowserView::Clear(void) {
  d->filter_box->clear();
  d->history_tree->clear();
  d->current_root = nullptr;
  d->last_added = nullptr;
  d->item_to_decl.clear();
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
  auto decl_it = d->item_to_decl.find(item);
  if (decl_it != d->item_to_decl.end()) {
    emit HistoryDeclarationClicked(decl_it->second);
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

  auto decl_it = d->item_to_decl.find(item);
  if (decl_it == d->item_to_decl.end()) {
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
    for (auto &[item, eid] : d->item_to_decl) {
      item->setHidden(false);
    }
  } else {
    for (auto &[item, eid] : d->item_to_decl) {
      item->setHidden(true);
    }

    for (auto &[item, eid] : d->item_to_decl) {
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

void HistoryBrowserView::OnClearButton(void) {
  d->filter_box->clear();
  d->history_tree->clear();
  d->item_to_decl.clear();
  d->current_root = nullptr;
  d->last_added = nullptr;
}

void HistoryBrowserView::OnRootButton(void) {
  d->current_root = nullptr;
}

}  // namespace mx::gui
