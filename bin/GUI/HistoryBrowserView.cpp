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

}  // namespace

struct HistoryBrowserView::PrivateData {
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QLineEdit *filter_box{nullptr};

  QTreeWidget *history_tree{nullptr};

  QTreeWidgetItem *current_root{nullptr};

  QPushButton *clear_button{nullptr};
  QPushButton *root_button{nullptr};

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

  d->history_tree->setHeaderHidden(true);
  d->history_tree->expandAll();
  d->history_tree->setItemsExpandable(false);
  d->history_tree->setColumnCount(1);
  d->history_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->history_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->history_tree->header()->setStretchLastSection(false);

  // Disallow selection.
  d->history_tree->setSelectionMode(
      QAbstractItemView::SelectionMode::NoSelection);

  d->history_tree->setAutoScroll(true);

  connect(d->history_tree, &QTreeWidget::itemClicked,
          this, &HistoryBrowserView::OnTreeWidgetItemClicked);

  connect(d->history_tree, &QTreeWidget::itemDoubleClicked,
          this, &HistoryBrowserView::OnTreeWidgetItemDoubleClicked);

  connect(d->filter_box, &QLineEdit::textChanged,
          this, &HistoryBrowserView::OnFilterHistoryView);

  connect(d->filter_box, &QLineEdit::textChanged,
          this, &HistoryBrowserView::OnFilterHistoryView);

  connect(d->clear_button, &QPushButton::pressed,
          this, &HistoryBrowserView::OnClearButton);

  connect(d->root_button, &QPushButton::pressed,
          this, &HistoryBrowserView::OnRootButton);
}

// Add the declarations to the history view.
void HistoryBrowserView::AddDeclarations(std::vector<RawEntityId> ids) const {

//  d->filter_box->clear();
//  for (auto &[item, eid] : d->item_to_decl) {
//    item->setHidden(false);
//  }

  // Double check its sanity.
  if (d->current_root) {
    auto root_it = d->item_to_decl.find(d->current_root);
    if (root_it == d->item_to_decl.end()) {
      d->current_root = nullptr;
    }
  }

  for (RawEntityId eid : ids) {
    auto entity = d->multiplier.Index().entity(eid);
    if (!std::holds_alternative<Decl>(entity)) {
      continue;
    }

    Decl decl(std::move(std::get<Decl>(entity)));
    auto *item = new QTreeWidgetItem;
    item->setText(0, DeclName(decl));

    d->item_to_decl.emplace(item, eid);

    if (!d->current_root) {
      d->history_tree->addTopLevelItem(item);
    } else {
      d->current_root->addChild(item);
      d->current_root->setExpanded(true);
    }

    d->history_tree->scrollToItem(item);
  }
}

void HistoryBrowserView::Clear(void) {
  d->filter_box->clear();
  d->history_tree->clear();
  d->current_root = nullptr;
  d->item_to_decl.clear();
}

void HistoryBrowserView::OnTreeWidgetItemClicked(
    QTreeWidgetItem *item, int) {
  auto decl_it = d->item_to_decl.find(item);
  if (decl_it != d->item_to_decl.end()) {
    emit HistoryDeclarationClicked(decl_it->second);
  }
}

void HistoryBrowserView::mouseDoubleClickEvent(QMouseEvent *event) {
  this->QWidget::mouseDoubleClickEvent(event);
}

void HistoryBrowserView::OnTreeWidgetItemDoubleClicked(
    QTreeWidgetItem *item, int) {
  auto decl_it = d->item_to_decl.find(item);
  if (decl_it == d->item_to_decl.end()) {
    return;
  }

  d->current_root = item;
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
}

void HistoryBrowserView::OnRootButton(void) {
  d->current_root = nullptr;
}

}  // namespace mx::gui
