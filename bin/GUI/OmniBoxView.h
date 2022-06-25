// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Index.h>
#include <QRunnable>
#include <QWidget>

#include "Event.h"

namespace mx {
class RegexQuery;
class RegexQueryResultIterator;
class Index;
namespace gui {

class Multiplier;

// An omni-box search widget.
class OmniBoxView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);
  void ClearSymbolResults(void);
  void ClearRegexResults(void);

 public:
  virtual ~OmniBoxView(void);

  OmniBoxView(Multiplier &multiplier, QWidget *parent = nullptr);
  void Clear(void);

  void Disconnected(void);
  void Connected(void);

 private slots:
  void MaybeDisableSymbolSearch(int);
  void SetSymbolQueryString(const QString &text);
  void RunSymbolSearch(void);
  void OnFoundSymbols(SymbolList symbols, DeclCategory category,
                      unsigned counter);

  void BuildRegex(const QString &text);
  void RunRegex(void);
  void OnFoundFragmentsWithRegex(RegexQueryResultIterator *list,
                                 unsigned counter);
  void OnOpenRegexResultsInTab(void);
  void OnOpenRegexResultsInDock(void);

 signals:
  void OpenTab(QString title, QWidget *widget);
  void OpenDock(QString title, QWidget *widget);
};

// Downloads the file list in the background.
class SymbolSearchThread final : public QObject, public QRunnable {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~SymbolSearchThread(void);

  explicit SymbolSearchThread(const Index &index_, const QString &name,
                              DeclCategory category_, unsigned counter_);

 signals:
  void FoundSymbols(SymbolList symbols, DeclCategory category,
                    unsigned counter);
};

// Downloads the file list in the background.
class RegexQueryThread final : public QObject, public QRunnable {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~RegexQueryThread(void);

  explicit RegexQueryThread(const Index &index_, const RegexQuery &query_,
                            unsigned counter_);

 signals:
  void FoundFragments(RegexQueryResultIterator *list, unsigned counter);
};

}  // namespace gui
}  // namespace mx
