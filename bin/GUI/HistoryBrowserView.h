// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QWidget>

#include <memory>
#include <multiplier/Index.h>
#include <vector>

#include "Event.h"

QT_BEGIN_NAMESPACE
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace mx {

class Index;

namespace gui {

class Multiplier;

// Shows a tree of the navigation history.
class HistoryBrowserView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  HistoryBrowserView(void) = delete;

  void InitializeWidgets(void);

  void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_FINAL;

  void FillRow(QTreeWidgetItem *item, const Decl &decl, const Token &frag_tok,
               const Token &file_tok) const;

 public:
  HistoryBrowserView(Multiplier &multiplier_, QWidget *parent=nullptr);
  virtual ~HistoryBrowserView(void);

  void Focus(void);

  // Add the declarations to the history as children of the last added item.
  void AddChildDeclarations(const EventLocations &locs);

  // Add the declarations to the history as siblings of the last added item.
  void AddSiblingDeclarations(const EventLocations &locs);

  // Add the declarations to the history view as top-level items.
  void AddRootDeclarations(const EventLocations &locs);

  // Add the declarations to the history nested under the current selected root.
  void AddDeclarationsUnderRoot(const EventLocations &locs);

  // Add the locations to the linear history.
  void AddToLinearHistory(const EventLocations &locs);

  // Go back one step in the linear history.
  bool GoBackInLinearHistory(void);

 public slots:
  void OnDownloadedFileList(FilePathList files);
  void Clear(void);

 private slots:

  // Single click goes to a history item.
  void OnTreeWidgetItemClicked(QTreeWidgetItem *item, int);

  // Double click re-roots the history at the selected item.
  void OnTreeWidgetItemDoubleClicked(QTreeWidgetItem *item, int);

  // Selecting a different item, e.g. with up/down arrows, should act like a
  // click.
  void OnTreeWidgetItemSelectionChanged(void);

  void OnFilterHistoryView(const QString &filter);

  void OnRootButton(void);

  // NOTE(pag): This doesn't clear the linear history.
  void OnClearButton(void);

 signals:
  void TokenPressEvent(EventSource source, EventLocations loc_ids);
};

}  // namespace gui
}  // namespace mx
