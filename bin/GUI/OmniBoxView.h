// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
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
  void ClearRegexResults(void);

 public:
  virtual ~OmniBoxView(void);

  OmniBoxView(Multiplier &multiplier, QWidget *parent = nullptr);
  void Clear(void);

  void Disconnected(void);
  void Connected(void);

 private slots:
  void BuildRegex(const QString &text);
  void RunRegex(void);
  void OnFoundFragmentsWithRegex(RegexQueryResultIterator *list,
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
