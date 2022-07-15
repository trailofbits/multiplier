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

QT_BEGIN_NAMESPACE
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace mx {
class FileLocationCache;
class Index;
class RegexQuery;
class RegexQueryResultIterator;
class WeggliQuery;
class WeggliQueryResultIterator;
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
  void ClearWeggliResults(void);

  void FillRow(QTreeWidgetItem *item, const NamedDecl &decl) const;

 public:
  virtual ~OmniBoxView(void);

  OmniBoxView(Multiplier &multiplier, QWidget *parent = nullptr);
  void Clear(void);
  void OpenWeggliSearch(void);
  void OpenRegexSearch(void);
  void OpenEntitySearch(void);

  void Disconnected(void);
  void Connected(void);

 public slots:
  void Focus(void);
  void OnDownloadedFileList(FilePathList files);

 private slots:
  void MaybeDisableSymbolSearch(int);
  void SetSymbolQueryString(const QString &text);
  void RunSymbolSearch(void);
  void OnFoundSymbols(NamedDeclList symbols, DeclCategory category,
                      unsigned counter);
  void OnSymbolItemClicked(QTreeWidgetItem *item, int column);

  void BuildRegex(const QString &text);
  void RunRegex(void);
  void OnFoundFragmentsWithRegex(RegexQueryResultIterator *list,
                                 unsigned counter);
  void OnOpenRegexResultsInTab(void);
  void OnOpenRegexResultsInDock(void);

  void BuildWeggli(const QString &text);
  void RunWeggli(void);
  void OnFoundFragmentsWithWeggli(WeggliQueryResultIterator *list,
                                  unsigned counter);
  void OnOpenWeggliResultsInTab(void);
  void OnOpenWeggliResultsInDock(void);

 signals:
  void OpenTab(QString title, QWidget *widget);
  void OpenDock(QString title, QWidget *widget);
  void TokenPressEvent(EventSource source, EventLocations loc_ids);
};

// Downloads the symbol search results in the background.
class SymbolSearchThread final : public QObject, public QRunnable {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~SymbolSearchThread(void);

  explicit SymbolSearchThread(
      const Index &index_, const FileLocationCache &cache_, const QString &name,
      DeclCategory category_, unsigned counter_);

 signals:
  void FoundSymbols(NamedDeclList symbols, DeclCategory category,
                    unsigned counter);
};

// Downloads the regex search results in the background.
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

// Downloads the Weggli search results in the background.
class WeggliQueryThread final : public QObject, public QRunnable {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~WeggliQueryThread(void);

  explicit WeggliQueryThread(const Index &index_, const WeggliQuery &query_,
                            unsigned counter_);

 signals:
  void FoundFragments(WeggliQueryResultIterator *list, unsigned counter);
};

}  // namespace gui
}  // namespace mx
