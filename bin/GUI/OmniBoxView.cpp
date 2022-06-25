// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "OmniBoxView.h"

#include <QCheckBox>
#include <QFont>
#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTabWidget>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <multiplier/Index.h>
#include <multiplier/Re2.h>

#include <iostream>
#include <string>

#include "CodeSearchResults.h"
#include "CodeTheme.h"
#include "Multiplier.h"
#include "TitleNamePrompt.h"

namespace mx::gui {
namespace {

QString EnumeratorToLabelName(const char *enumerator) {
  QString ret;
  auto uppercase = true;

  for (QChar ch : QString::fromUtf8(enumerator)) {
    if (ch == '_') {
      uppercase = true;
      ret.push_back(QChar::Space);

    } else if (uppercase) {
      ret.push_back(ch.toUpper());
      uppercase = false;

    } else {
      ret.push_back(ch.toLower());
    }
  }
  return ret;
}

}  // namespace

struct OmniBoxView::PrivateData {
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QTabWidget *content{nullptr};

  QWidget *symbol_box{nullptr};
  QGridLayout *symbol_layout{nullptr};
  QLineEdit *symbol_input{nullptr};
  QPushButton *symbol_button{nullptr};
  QCheckBox *symbol_categories[NumEnumerators(DeclCategory{})];
  QTreeWidget *symbol_results{nullptr};
  QTreeWidgetItem *category_results[NumEnumerators(DeclCategory{})];

  QWidget *regex_box{nullptr};
  QGridLayout *regex_layout{nullptr};
  QLineEdit *regex_input{nullptr};
  QPushButton *regex_button{nullptr};
  QPushButton *regex_to_tab_button{nullptr};
  QPushButton *regex_to_dock_button{nullptr};
  QWidget *regex_results{nullptr};
  RegexQuery regex_query;

  unsigned symbol_counter{0};
  unsigned regex_counter{0};

  inline PrivateData(Multiplier &multiplier_)
      : multiplier(multiplier_) {}
};

OmniBoxView::~OmniBoxView(void) {}

OmniBoxView::OmniBoxView(Multiplier &multiplier_, QWidget *parent_)
    : QWidget(parent_),
      d(std::make_unique<PrivateData>(multiplier_)) {
  InitializeWidgets();
}

void OmniBoxView::InitializeWidgets(void) {
  setWindowTitle(tr("Search"));

  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);
  setLayout(d->layout);

  d->content = new QTabWidget;
  d->content->setDocumentMode(false);
  d->content->setTabBarAutoHide(false);
  d->layout->addWidget(d->content);

  // ---------------------------------------------------------------------------
  // Entity name search
  d->symbol_box = new QWidget;
  d->symbol_layout = new QGridLayout;
  d->symbol_input = new QLineEdit;
  d->symbol_button = new QPushButton(tr("Query"));
  for (auto category : EnumerationRange<DeclCategory>()) {
    auto c = static_cast<unsigned>(category);
    d->symbol_categories[c] = new QCheckBox;

    // Possibly disable
    connect(d->symbol_categories[c], &QCheckBox::stateChanged,
            this, &OmniBoxView::MaybeDisableSymbolSearch);
  }

  QFont input_font = d->multiplier.CodeTheme().Font();
  QFont button_font = d->symbol_button->font();
  button_font.setPointSize(input_font.pointSize());

  d->symbol_input->setFont(input_font);
  d->symbol_button->setFont(button_font);
  d->symbol_button->setDisabled(true);

  auto num_categories = NumEnumerators(DeclCategory{});
  QFormLayout *column_layouts[3] = {new QFormLayout, new QFormLayout,
                                    new QFormLayout};

  auto columns_widget = new QWidget;
  auto columns_layout = new QHBoxLayout;
  columns_widget->setLayout(columns_layout);
  columns_layout->addLayout(column_layouts[0]);
  columns_layout->addLayout(column_layouts[1]);
  columns_layout->addLayout(column_layouts[2]);

  d->symbol_box->setLayout(d->symbol_layout);
  d->symbol_layout->addWidget(d->symbol_button, 0, 0, 1, 1, Qt::AlignTop);
  d->symbol_layout->addWidget(d->symbol_input, 0, 1, 1, 1, Qt::AlignTop);
  d->symbol_layout->addWidget(columns_widget, 1, 0, 1, 2, Qt::AlignTop);
  d->symbol_layout->setRowStretch(0, 0);
  d->symbol_layout->setRowStretch(1, 0);
  d->symbol_layout->setRowStretch(2, 1);

  for (auto i = 0u; i < num_categories; ++i) {
    auto enumerator_name = EnumeratorName(static_cast<DeclCategory>(i));
    column_layouts[i % 3]->addRow(
        EnumeratorToLabelName(enumerator_name) + ": ",
        d->symbol_categories[i]);
  }

  d->symbol_categories[static_cast<unsigned>(DeclCategory::GLOBAL_VARIABLE)]->setChecked(true);
  d->symbol_categories[static_cast<unsigned>(DeclCategory::FUNCTION)]->setChecked(true);
  d->symbol_categories[static_cast<unsigned>(DeclCategory::CLASS_METHOD)]->setChecked(true);
  d->symbol_categories[static_cast<unsigned>(DeclCategory::CLASS_MEMBER)]->setChecked(true);
  d->symbol_categories[static_cast<unsigned>(DeclCategory::INSTANCE_METHOD)]->setChecked(true);
  d->symbol_categories[static_cast<unsigned>(DeclCategory::INSTANCE_MEMBER)]->setChecked(true);
  d->content->addTab(d->symbol_box, tr("Symbol Search"));

  connect(d->symbol_input, &QLineEdit::textChanged,
          this, &OmniBoxView::SetSymbolQueryString);

  connect(d->symbol_input, &QLineEdit::returnPressed,
          this, &OmniBoxView::RunSymbolSearch);

  connect(d->symbol_button, &QPushButton::pressed,
          this, &OmniBoxView::RunSymbolSearch);

  // ---------------------------------------------------------------------------
  // Regex search
  d->regex_box = new QWidget;
  d->regex_layout = new QGridLayout;
  d->regex_input = new QLineEdit;
  d->regex_button = new QPushButton(tr("Query"));
  d->regex_to_tab_button = new QPushButton(tr("⍐ tab"));
  d->regex_to_dock_button = new QPushButton(tr("⍇ dock"));

  d->regex_input->setFont(input_font);
  d->regex_button->setFont(button_font);
  d->regex_to_tab_button->setFont(button_font);
  d->regex_to_dock_button->setFont(button_font);

  d->regex_box->setLayout(d->regex_layout);
  d->regex_layout->addWidget(d->regex_button, 0, 0, 1, 1, Qt::AlignTop);
  d->regex_layout->addWidget(d->regex_to_tab_button, 0, 2, 1, 1, Qt::AlignTop);
  d->regex_layout->addWidget(d->regex_to_dock_button, 0, 3, 1, 1, Qt::AlignTop);
  d->regex_layout->addWidget(d->regex_input, 0, 1, 1, 1, Qt::AlignTop);
  d->regex_layout->setRowStretch(0, 0);
  d->regex_layout->setRowStretch(1, 1);
  d->content->addTab(d->regex_box, tr("Regex Search"));
  d->regex_button->setDisabled(true);
  d->regex_to_dock_button->setDisabled(true);
  d->regex_to_tab_button->setDisabled(true);

  d->regex_layout->installEventFilter(&d->multiplier);

  connect(d->regex_input, &QLineEdit::textChanged,
          this, &OmniBoxView::BuildRegex);

  connect(d->regex_input, &QLineEdit::returnPressed,
          this, &OmniBoxView::RunRegex);

  connect(d->regex_button, &QPushButton::pressed,
          this, &OmniBoxView::RunRegex);

  connect(d->regex_to_dock_button, &QPushButton::pressed,
          this, &OmniBoxView::OnOpenRegexResultsInDock);

  connect(d->regex_to_tab_button, &QPushButton::pressed,
          this, &OmniBoxView::OnOpenRegexResultsInTab);

  connect(this, &OmniBoxView::OpenTab,
          &d->multiplier, &Multiplier::OnOpenTab);

  connect(this, &OmniBoxView::OpenDock,
          &d->multiplier, &Multiplier::OnOpenDock);

  d->content->hide();
}

void OmniBoxView::Clear(void) {
  d->regex_button->setDisabled(true);
  d->regex_input->setText(QString());
  d->regex_counter++;
  ClearRegexResults();

  d->symbol_button->setDisabled(true);
  d->symbol_input->setText(QString());
  d->symbol_counter++;
  ClearSymbolResults();
}

void OmniBoxView::ClearSymbolResults(void) {
  if (d->symbol_results) {
    d->symbol_layout->removeWidget(d->symbol_results);
    d->symbol_results->disconnect();
    d->symbol_results->deleteLater();
    d->symbol_results = nullptr;
    update();
  }
}

void OmniBoxView::ClearRegexResults(void) {
  if (d->regex_results) {
    d->regex_layout->removeWidget(d->regex_results);
    d->regex_results->disconnect();
    d->regex_results->deleteLater();
    d->regex_results = nullptr;
    d->regex_to_dock_button->setDisabled(true);
    d->regex_to_tab_button->setDisabled(true);
    update();
  }
}

void OmniBoxView::Disconnected(void) {
  d->content->hide();
  d->regex_counter++;
  d->symbol_counter++;
  update();
}

void OmniBoxView::Connected(void) {
  d->content->show();
  update();
}

void OmniBoxView::MaybeDisableSymbolSearch(int) {
  auto text = d->symbol_input->text();
  if (0 >= text.size()) {
    d->symbol_button->setDisabled(true);
    return;
  }

  // Make sure at least one declaration kind is checked.
  for (auto category : EnumerationRange<DeclCategory>()) {
    auto box = d->symbol_categories[static_cast<unsigned>(category)];
    if (box->isChecked()) {
      d->symbol_button->setEnabled(true);
      return;
    }
  }

  d->symbol_button->setDisabled(true);
}

void OmniBoxView::SetSymbolQueryString(const QString &) {
  MaybeDisableSymbolSearch(0);
}

void OmniBoxView::RunSymbolSearch(void) {
  QString query = d->symbol_input->text();
  if (0 >= query.size()) {
    return;
  }

  d->symbol_counter++;
  ClearSymbolResults();
  d->symbol_results =

  d->symbol_results = new QTreeWidget;
  d->symbol_results->setColumnCount(2);
  d->symbol_results->setSortingEnabled(true);
  d->symbol_results->setSelectionMode(
      QAbstractItemView::SelectionMode::SingleSelection);
  d->symbol_results->setHeaderHidden(false);
  d->symbol_results->setAutoScroll(false);
  d->symbol_results->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->symbol_results->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

  QTreeWidgetItem *header_item = d->symbol_results->headerItem();
  header_item->setText(0, tr("Symbol Name"));
  header_item->setText(1, tr("Declaration Kind"));

  QHeaderView *header = d->symbol_results->header();
  header->setStretchLastSection(true);
  header->setSectionResizeMode(QHeaderView::ResizeToContents);

  d->symbol_layout->addWidget(d->symbol_results, 2, 0, 1, 2);

  // Make sure at least one declaration kind is checked.
  for (auto category : EnumerationRange<DeclCategory>()) {
    auto c = static_cast<unsigned>(category);
    auto box = d->symbol_categories[c];
    if (!box->isChecked()) {
      d->category_results[c] = nullptr;
      continue;
    }

    d->category_results[c] = new QTreeWidgetItem;
    d->category_results[c]->setText(
        0, EnumeratorToLabelName(EnumeratorName(category)) + "s");
    d->symbol_results->addTopLevelItem(d->category_results[c]);

    auto loading_child = new QTreeWidgetItem;
    loading_child->setText(0, tr("Querying..."));
    d->category_results[c]->addChild(loading_child);

    auto runnable = new SymbolSearchThread(
        d->multiplier.Index(), query, category, d->symbol_counter);
    runnable->setAutoDelete(true);

    connect(runnable, &SymbolSearchThread::FoundSymbols,
            this, &OmniBoxView::OnFoundSymbols);

    QThreadPool::globalInstance()->start(runnable);
  }

  d->symbol_results->expandAll();
  update();
}

void OmniBoxView::OnFoundSymbols(SymbolList symbols, DeclCategory category,
                                 unsigned counter) {
  if (counter != d->symbol_counter) {
    return;  // Query returned too late.
  }

  auto c = static_cast<unsigned>(category);
  auto parent_item = d->category_results[c];

  // Remove the `Querying...` item.
  while (parent_item->childCount()) {
    parent_item->removeChild(parent_item->child(0));
  }

  if (symbols.empty()) {
    auto loading_child = new QTreeWidgetItem;
    loading_child->setText(0, tr("No results"));
    d->category_results[c]->addChild(loading_child);
    return;
  }

  QFont code_font = d->multiplier.CodeTheme().Font();

  for (const std::pair<RawEntityId, std::string> &item : symbols) {
    VariantId vid = EntityId(item.first).Unpack();
    if (!std::holds_alternative<DeclarationId>(vid)) {
      continue;
    }

    DeclarationId eid = std::get<DeclarationId>(vid);
    auto decl_child = new QTreeWidgetItem;
    decl_child->setText(0, QString::fromStdString(item.second));
    decl_child->setFont(0, code_font);
    decl_child->setText(1, EnumeratorToLabelName(EnumeratorName(eid.kind)));
    d->category_results[c]->addChild(decl_child);
  }
}

void OmniBoxView::BuildRegex(const QString &text) {
  if (text.isEmpty()) {
    d->regex_query = RegexQuery();
    d->regex_button->setDisabled(true);

  } else {
    auto arr = text.toUtf8();
    d->regex_query = RegexQuery(
        std::string(arr.data(), static_cast<size_t>(arr.size())));
    d->regex_button->setDisabled(!d->regex_query.IsValid());
  }
}

void OmniBoxView::RunRegex(void) {
  if (!d->regex_query.IsValid()) {
    return;
  }

  d->regex_counter++;

  ClearRegexResults();
  d->regex_results = new QLabel(tr("Querying..."));
  d->regex_layout->addWidget(d->regex_results, 1, 0, 1, 4,
                             Qt::AlignmentFlag::AlignHCenter |
                             Qt::AlignmentFlag::AlignVCenter);

  auto runnable = new RegexQueryThread(
      d->multiplier.Index(), d->regex_query, d->regex_counter);
  runnable->setAutoDelete(true);

  connect(runnable, &RegexQueryThread::FoundFragments,
          this, &OmniBoxView::OnFoundFragmentsWithRegex);

  QThreadPool::globalInstance()->start(runnable);
}

void OmniBoxView::OnFoundFragmentsWithRegex(RegexQueryResultIterator *list_,
                                            unsigned counter) {
  std::unique_ptr<RegexQueryResultIterator> list(list_);
  if (d->regex_counter != counter) {
    return;
  }

  ClearRegexResults();

  const CodeTheme &theme = d->multiplier.CodeTheme();
  theme.BeginTokens();

  auto model = new CodeSearchResultsModel(d->multiplier);
  auto table = new CodeSearchResultsView(model);

  connect(table, &CodeSearchResultsView::TokenPressEvent,
          &d->multiplier, &Multiplier::ActOnTokenPressEvent);

  for (auto j = 1; *list != IteratorEnd{}; ++*list, ++j) {
    const RegexQueryMatch &match = **list;
    if (!d->regex_results) {
      d->regex_results = table;
      d->regex_to_dock_button->setEnabled(true);
      d->regex_to_tab_button->setEnabled(true);
      d->regex_layout->addWidget(d->regex_results, 1, 0, 1, 4);
    }
    model->AddResult(match);
  }

  theme.EndTokens();

  if (!d->regex_results) {
    d->regex_results = new QLabel(tr("No matches"));
    d->regex_layout->addWidget(d->regex_results, 1, 0, 1, 4,
                               Qt::AlignmentFlag::AlignHCenter |
                               Qt::AlignmentFlag::AlignVCenter);
  }
  update();
}

void OmniBoxView::OnOpenRegexResultsInTab(void) {
  if (!d->regex_results) {
    return;
  }

  TitleNamePrompt dialog(tr("Set tab name"), this);
  if (dialog.exec() != QDialog::Accepted) {
    return;
  }

  d->regex_layout->removeWidget(d->regex_results);
  d->regex_results->setParent(nullptr);
  emit OpenTab(dialog.NewName(), d->regex_results);
  d->regex_results = nullptr;
  d->regex_to_dock_button->setDisabled(true);
  d->regex_to_tab_button->setDisabled(true);
  update();
}

void OmniBoxView::OnOpenRegexResultsInDock(void) {
  if (!d->regex_results) {
    return;
  }

  TitleNamePrompt dialog(tr("Set dock name"), this);
  if (dialog.exec() != QDialog::Accepted) {
    return;
  }

  d->regex_layout->removeWidget(d->regex_results);
  d->regex_results->setParent(nullptr);
  emit OpenDock(dialog.NewName(), d->regex_results);
  d->regex_results = nullptr;
  d->regex_to_dock_button->setDisabled(true);
  d->regex_to_tab_button->setDisabled(true);
  update();
}

struct SymbolSearchThread::PrivateData {
  const Index index;
  const QString query;
  const DeclCategory category;
  const unsigned counter;

  inline PrivateData(const Index &index_, const QString &query_,
                     DeclCategory category_, unsigned counter_)
      : index(index_),
        query(query_),
        category(category_),
        counter(counter_) {}
};

SymbolSearchThread::~SymbolSearchThread(void) {}

SymbolSearchThread::SymbolSearchThread(
    const Index &index_, const QString &query_,
    DeclCategory category_, unsigned counter_)
    : d(std::make_unique<PrivateData>(index_, query_, category_, counter_)) {}

void SymbolSearchThread::run(void) {
  emit FoundSymbols(
      d->index.query_entities(d->query.toStdString(), d->category),
      d->category, d->counter);
}

struct RegexQueryThread::PrivateData {
  const Index index;
  const RegexQuery query;
  const unsigned counter;

  inline PrivateData(const Index &index_, const RegexQuery &query_,
                     unsigned counter_)
      : index(index_),
        query(query_),
        counter(counter_) {}
};

RegexQueryThread::~RegexQueryThread(void) {}

RegexQueryThread::RegexQueryThread(const Index &index_,
                                   const RegexQuery &query_,
                                   unsigned counter_)
    : d(std::make_unique<PrivateData>(index_, query_, counter_)) {}

void RegexQueryThread::run(void) {
  emit FoundFragments(
      new RegexQueryResultIterator(d->index.query_fragments(d->query).begin()),
      d->counter);
}

}  // namespace mx::gui
