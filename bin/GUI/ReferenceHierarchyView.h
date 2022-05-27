// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QRunnable>
#include <QTreeWidgetItem>
#include <QWidget>

#include <multiplier/Index.h>
#include <multiplier/Types.h>

#include <vector>

namespace mx::gui {

class ExpandReferenceHierarchyThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  Index index;
  const RawEntityId id;
  QTreeWidgetItem * const item_parent;

  void run(void) final;

 public:
  virtual ~ExpandReferenceHierarchyThread(void);
  inline explicit ExpandReferenceHierarchyThread(Index index_, RawEntityId id_,
                                                 QTreeWidgetItem *parent_)
      : index(std::move(index_)),
        id(id_),
        item_parent(parent_) {}

 signals:
  void UsersOfLevel(QTreeWidgetItem *item_parent, RawEntityId use_id,
                    std::vector<RawEntityId> users);
};

class ReferenceHierarchyView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);

 public:
  virtual ~ReferenceHierarchyView(void);

  ReferenceHierarchyView(QWidget *parent = nullptr);

  void Clear(void);
  void SetIndex(Index index);
  void AddRoot(RawEntityId id);

 private slots:
  void OnTreeWidgetItemExpanded(QTreeWidgetItem *item);
  void OnUsersOfFirstLevel(QTreeWidgetItem *parent, RawEntityId use_id,
                           std::vector<RawEntityId> users);
  void OnUsersOfLevel(QTreeWidgetItem *parent, RawEntityId use_id,
                      std::vector<RawEntityId> users);
};

}  // namespace mx::gui
