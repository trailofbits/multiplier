// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QWidget>

#include <memory>
#include <multiplier/Types.h>
#include <vector>

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

 public:
  HistoryBrowserView(Multiplier &multiplier_, QWidget *parent=nullptr);
  virtual ~HistoryBrowserView(void);

  void Clear(void);

  // Add the declarations to the history as children of the last added item.
  void AddChildDeclarations(std::vector<RawEntityId> ids) const;

  // Add the declarations to the history as siblings of the last added item.
  void AddSiblingDeclarations(std::vector<RawEntityId> ids) const;

  // Add the declarations to the history view as top-level items.
  void AddRootDeclarations(std::vector<RawEntityId> ids) const;

  // Add the declarations to the history nested under the current selected root.
  void AddDeclarationsUnderRoot(std::vector<RawEntityId> ids) const;

 private slots:

  // Single click goes to a history item.
  void OnTreeWidgetItemClicked(QTreeWidgetItem *item, int);

  // Double click re-roots the history at the selected item.
  void OnTreeWidgetItemDoubleClicked(QTreeWidgetItem *item, int);

  void OnFilterHistoryView(const QString &filter);

  void OnClearButton(void);
  void OnRootButton(void);

 signals:
  void HistoryDeclarationClicked(RawEntityId eid);
};

}  // namespace gui
}  // namespace mx
