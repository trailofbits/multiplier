// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "HistoryBrowserView.h"

#include <QApplication>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

#include <deque>
#include <multiplier/Index.h>
#include <unordered_map>

#include "Configuration.h"
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
  kEntityColumnIndex,
  kPathColumnIndex,
  kFileColumnIndex,
  kLineColumnIndex,
  kColumnColumnIndex,
  kContextColumnIndex,

  kNumColumns
};

static constexpr size_t kDefaultReadHead = 1;

struct HistoryItem {
  const EventLocation loc;
  QTreeWidgetItem *item{nullptr};
  unsigned item_version{0};

  HistoryItem(EventLocation loc_, QTreeWidgetItem *item_, unsigned version_)
      : loc(std::move(loc_)),
        item(item_),
        item_version(version_) {}
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

  std::deque<HistoryItem> linear_history;
  size_t read_head{kDefaultReadHead};

  int event_suppress{0};
  unsigned counter{1u};  // Version of this history view.

  std::unordered_map<QTreeWidgetItem *, EventLocation> item_to_loc;
  std::unordered_map<RawEntityId, std::filesystem::path> file_id_to_path;

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
  d->history_tree->setHeaderHidden(false);
  d->history_tree->expandAll();
  d->history_tree->setItemsExpandable(false);
  d->history_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->history_tree->setAutoScroll(true);

  // Add the column headers.
  QHeaderView *header = d->history_tree->header();
  header->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  header->setStretchLastSection(true);
  QTreeWidgetItem *header_item = d->history_tree->headerItem();
  d->history_tree->setColumnCount(kNumColumns);
  header_item->setText(kEntityColumnIndex, tr("Entity"));
  header_item->setText(kPathColumnIndex, tr("Path"));
  header_item->setText(kFileColumnIndex, tr("File"));
  header_item->setText(kLineColumnIndex, tr("Line"));
  header_item->setText(kColumnColumnIndex, tr("Column"));
  header_item->setText(kContextColumnIndex, tr("Context"));

  // Customize visibility of columns.
  HistoryBrowserConfiguration &config =
      d->multiplier.Configuration().history_browser;
  d->history_tree->setColumnHidden(kPathColumnIndex, !config.show_file_path);
  d->history_tree->setColumnHidden(kFileColumnIndex, !config.show_file_name);
  d->history_tree->setColumnHidden(kLineColumnIndex, !config.show_line_numbers);
  d->history_tree->setColumnHidden(kColumnColumnIndex,
                                   !config.show_column_numbers);
  d->history_tree->setColumnHidden(kContextColumnIndex,
                                   !config.breadcrumbs.visible);

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

void HistoryBrowserView::OnDownloadedFileList(FilePathList files) {
  for (auto &[path, index] : files) {
    d->file_id_to_path.emplace(index, std::move(path));
  }
}

void HistoryBrowserView::FillRow(
    QTreeWidgetItem *item, const Decl &decl, const Token &frag_tok,
    const Token &file_tok) const {

  HistoryBrowserConfiguration &config =
      d->multiplier.Configuration().history_browser;

  // Format the declaration column. If we have a name then use it, otherwise
  // use the stringized enumerator name for the declaration kind, coupled with
  // the entity ID.
  //
  // TODO(pag): Eventually use symbol names in here.
  item->setText(0, DeclName(decl));

  auto color = qApp->palette().text().color();
  color = QColor::fromRgbF(
      color.redF(), color.greenF(), color.blueF(), color.alphaF() * 0.75);

  // Show the line and column numbers.
  if (auto loc = file_tok.nearest_location(d->multiplier.FileLocationCache())) {
    auto file = File::containing(file_tok);
    RawEntityId file_id = file ? file->id() : kInvalidEntityId;

    if (auto fp_it = d->file_id_to_path.find(file_id);
        fp_it != d->file_id_to_path.end()) {
      item->setForeground(kPathColumnIndex, color);
      item->setTextAlignment(kPathColumnIndex, Qt::AlignRight);
      item->setText(
          kPathColumnIndex,
          QString::fromStdString(fp_it->second.generic_string()));
      assert(!item->text(kPathColumnIndex).startsWith(QChar::Space));

      item->setForeground(kFileColumnIndex, color);
      item->setTextAlignment(kFileColumnIndex, Qt::AlignRight);
      item->setText(
          kFileColumnIndex,
          QString::fromStdString(fp_it->second.filename().string()));

#ifndef QT_NO_TOOLTIP
      item->setToolTip(
          kFileColumnIndex,
          QString::fromStdString(fp_it->second.generic_string()));
#endif
    }

    item->setForeground(kLineColumnIndex, color);
    item->setText(kLineColumnIndex, QString::number(loc->first));  // Line.
#ifndef QT_NO_TOOLTIP
    item->setToolTip(kLineColumnIndex, tr("Line %1").arg(loc->first));
#endif

    item->setForeground(kColumnColumnIndex, color);
    item->setText(kColumnColumnIndex, QString::number(loc->second));  // Column.
#ifndef QT_NO_TOOLTIP
    item->setToolTip(kColumnColumnIndex, tr("Column %1").arg(loc->second));
#endif
  }

  // Show the context breadcrumbs. This is a chain of stringized enumerators
  // derived from the token contexts.
  item->setForeground(kContextColumnIndex, color);
  item->setText(
      kContextColumnIndex,
      TokenBreadCrumbs(frag_tok, config.breadcrumbs.run_length_encode));
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

  for (EventLocation loc : locs) {
    ScopeReferenceCounted suppress_event(d->event_suppress);

    QTreeWidgetItem *item = nullptr;
    auto history_index = loc.HistoryItem();
    loc.SetHistoryItem(static_cast<unsigned>(d->linear_history.size()));

    HistoryItem *history_item = nullptr;
    if (history_index && *history_index < d->linear_history.size()) {
      history_item = &(d->linear_history[*history_index]);
      item = history_item->item;
      if (history_item->item_version != d->counter ||
          !d->item_to_loc.count(history_item->item)) {
        history_item->item = nullptr;
        item = nullptr;
      }
    }

    if (!item) {
      auto &index = d->multiplier.Index();
      auto entity = index.entity(loc.DeclarationId());
      if (!std::holds_alternative<Decl>(entity)) {
        continue;
      }

      // Fix up any missing info in the location using the decl as our anchor.
      Decl decl = std::move(std::get<Decl>(entity));
      Token frag_tok;
      Token file_tok;

      if (loc.UnpackFragmentTokenId()) {
        auto tok_ent = index.entity(loc.FragmentTokenId());
        if (std::holds_alternative<Token>(tok_ent)) {
          frag_tok = std::move(std::get<Token>(tok_ent));
        }
      }

      if (!frag_tok) {
        frag_tok = DeclFragmentToken(decl).value();
        loc.SetFragmentTokenId(frag_tok.id());
      }

      if (loc.UnpackFileTokenId()) {
        auto tok_ent = index.entity(loc.FileTokenId());
        if (std::holds_alternative<Token>(tok_ent)) {
          file_tok = std::move(std::get<Token>(tok_ent));
        }
      }

      if (!file_tok) {
        file_tok = frag_tok.nearest_file_token().value();
        loc.SetFileTokenId(file_tok.id());
      }

      item = new QTreeWidgetItem;
      FillRow(item, decl, frag_tok, file_tok);

      d->item_to_loc.emplace(item, loc);

      if (!d->current_root) {
        d->history_tree->addTopLevelItem(item);
      } else {
        d->current_root->addChild(item);
        d->current_root->setExpanded(true);
      }
    }

    // Update the old one.
    if (history_item && !history_item->item) {
      history_item->item = item;
      history_item->item_version = d->counter;
    }

    // Make a new one.
    history_item = &(d->linear_history.emplace_back(loc, item, d->counter));

    d->read_head = kDefaultReadHead;
    d->history_tree->scrollToItem(item);
    d->history_tree->clearSelection();
    d->history_tree->setCurrentItem(item);
    item->setSelected(true);
    d->last_added = item;
  }
}

// Go back one step in the linear history.
bool HistoryBrowserView::GoBackInLinearHistory(void) {
  auto history_size = d->linear_history.size();
  if (d->read_head > history_size) {
    return false;
  }

  assert(0 < d->read_head);

  HistoryItem *history_item = &(d->linear_history[history_size - d->read_head]);
  if (history_item->item) {
    if (history_item->item_version != d->counter ||
        !d->item_to_loc.count(history_item->item)) {
      history_item->item = nullptr;
    }
  }

//  EventLocation loc = history_item->loc;
//  loc.SetHistoryItem(static_cast<unsigned>(d->linear_history.size()));
//  d->linear_history.emplace_back(loc, history_item->item, d->counter);
  d->read_head += 1;

  if (history_item->item) {
    d->history_tree->scrollToItem(history_item->item);
    d->history_tree->clearSelection();
    d->history_tree->setCurrentItem(history_item->item);
    history_item->item->setSelected(true);
  }

  emit TokenPressEvent(EventSource::kHistoryBrowserLinearItemChanged,
                       history_item->loc);

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

void HistoryBrowserView::AddToLinearHistory(const EventLocations &locs) {
  for (EventLocation loc : locs) {
    auto history_index = loc.HistoryItem();
    loc.SetHistoryItem(static_cast<unsigned>(d->linear_history.size()));

    QTreeWidgetItem *item = nullptr;
    if (history_index && *history_index < d->linear_history.size()) {
      auto history_item = &(d->linear_history[*history_index]);
      if (history_item->item_version == d->counter &&
          d->item_to_loc.count(history_item->item)) {
        item = history_item->item;
      } else {
        history_item->item = nullptr;
      }
    }

    d->linear_history.emplace_back(loc, item, d->counter);
    d->read_head = kDefaultReadHead;
  }
}

void HistoryBrowserView::Clear(void) {
  OnClearButton();
  d->read_head = kDefaultReadHead;
  d->linear_history.clear();
  d->file_id_to_path.clear();
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
    emit TokenPressEvent(EventSource::kHistoryBrowserVisualItemSelected,
                         decl_it->second);
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

// NOTE(pag): This doesn't clear the linear history.
void HistoryBrowserView::OnClearButton(void) {
  d->filter_box->clear();
  d->history_tree->clear();
  d->current_root = nullptr;
  d->last_added = nullptr;
  d->item_to_loc.clear();
  d->counter++;
}

}  // namespace mx::gui
