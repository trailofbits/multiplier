// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "OmniBoxView.h"

#include <QPushButton>
#include <QFont>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTabWidget>
#include <QThreadPool>
#include <QLabel>
#include <QLineEdit>

#include <multiplier/Index.h>
#include <multiplier/Re2.h>

#include <iostream>
#include <string>

#include "CodeSearchResults.h"
#include "CodeTheme.h"
#include "Multiplier.h"

namespace mx::gui {
namespace {

static constexpr int kNumEntriesPerRefresh = 5;

}  // namespace

struct OmniBoxView::PrivateData {
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QTabWidget *content{nullptr};

  QWidget *regex_box{nullptr};
  QGridLayout *regex_layout{nullptr};
  QLineEdit *regex_input{nullptr};
  QPushButton *regex_button{nullptr};
  QWidget *regex_results{nullptr};
  RegexQuery regex_query;
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

  d->regex_box = new QWidget;
  d->regex_layout = new QGridLayout;
  d->regex_input = new QLineEdit;
  d->regex_button = new QPushButton(tr("Query"));

  QFont input_font = d->multiplier.CodeTheme().Font();
  d->regex_input->setFont(input_font);

  QFont button_font = d->regex_button->font();
  button_font.setPointSize(input_font.pointSize());
  d->regex_button->setFont(button_font);

  d->regex_box->setLayout(d->regex_layout);
  d->regex_layout->addWidget(d->regex_button, 0, 0, 1, 1, Qt::AlignTop);
  d->regex_layout->addWidget(d->regex_input, 0, 1, 1, 1, Qt::AlignTop);
  d->content->addTab(d->regex_box, tr("Code Search"));
  d->regex_button->setDisabled(true);

  d->regex_layout->installEventFilter(&d->multiplier);

  connect(d->regex_input, &QLineEdit::textChanged,
          this, &OmniBoxView::BuildRegex);

  connect(d->regex_input, &QLineEdit::returnPressed,
          this, &OmniBoxView::RunRegex);

  connect(d->regex_button, &QPushButton::pressed,
          this, &OmniBoxView::RunRegex);

  d->content->hide();
}

void OmniBoxView::Clear(void) {
  d->regex_button->setDisabled(true);
  d->regex_input->setText(QString());
  d->regex_counter++;
  ClearRegexResults();
}

void OmniBoxView::ClearRegexResults(void) {
  if (d->regex_results) {
    d->regex_layout->removeWidget(d->regex_results);
    d->regex_results->disconnect();
    d->regex_results->deleteLater();
    d->regex_results = nullptr;
    update();
  }
}

void OmniBoxView::Disconnected(void) {
  d->content->hide();
  d->regex_counter++;
  update();
}

void OmniBoxView::Connected(void) {
  d->content->show();
  update();
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
  d->regex_layout->addWidget(d->regex_results, 1, 1, 1, 2,
                             Qt::AlignmentFlag::AlignHCenter);

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

//  size_t num_captures = 0;

  auto model = new CodeSearchResultsModel(d->multiplier);
  auto table = new CodeSearchResultsView(model);

  connect(table, &CodeSearchResultsView::TokenPressEvent,
          &d->multiplier, &Multiplier::ActOnTokenPressEvent);

  for (auto j = 1; *list != IteratorEnd{}; ++*list, ++j) {
    const RegexQueryMatch &match = **list;
    if (!d->regex_results) {

      d->regex_results = table;
      d->regex_layout->addWidget(d->regex_results, 1, 0, 1, 2);
//
//      num_captures = match.num_captures();
//      table->setColumnCount(static_cast<int>(num_captures));
//      for (auto i = 0u; i < num_captures; ++i) {
//        table->setHorizontalHeaderItem(
//            static_cast<int>(i),
//            new QTableWidgetItem(QString::number(i)));
//      }
//
//      for (const std::string &var : match.captured_variables()) {
//        if (auto index = match.index_of_captured_variable(var)) {
//          auto item = table->horizontalHeaderItem(static_cast<int>(*index));
//          item->setText(QString::fromStdString(var));
//        }
//      }
    }

    model->AddResult(match);

//    auto rc = table->rowCount();
//    table->insertRow(rc);
//
//    for (auto i = 0u; i < num_captures; ++i) {
//      auto data = match.captured_data(i);
//      if (!data) {
//        continue;
//      }
//
//      QTableWidgetItem *item = new QTableWidgetItem(
//          QString::fromUtf8(data->data(), static_cast<int>(data->size())));
//      item->setFont(theme.Font());
//      item->setBackground(theme.BackgroundColor());
//      table->setItem(rc, static_cast<int>(i), item);
//    }
//
//    if (j >= kNumEntriesPerRefresh) {
//      update();
//      j = 1;
//    }
  }

  theme.EndTokens();

  if (!d->regex_results) {
    d->regex_results = new QLabel(tr("No matches"));
    d->regex_layout->addWidget(d->regex_results, 1, 1, 1, 2,
                               Qt::AlignmentFlag::AlignHCenter);
  }
  update();
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
