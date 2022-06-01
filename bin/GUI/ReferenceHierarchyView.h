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

#include "CodeTheme.h"

namespace mx::gui {

using UserLocation = std::pair<Decl, TokenRange>;
using UserLocations = std::vector<UserLocation>;

class InitReferenceHierarchyThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  Index index;
  const RawEntityId id;
  FileLocationCache &line_cache;
  QTreeWidgetItem * const item_parent;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~InitReferenceHierarchyThread(void);
  inline explicit InitReferenceHierarchyThread(Index index_, RawEntityId id_,
                                               FileLocationCache &line_cache_,
                                               QTreeWidgetItem *parent_)
      : index(std::move(index_)),
        id(id_),
        line_cache(line_cache_),
        item_parent(parent_) {}

 signals:
  void UsersOfRoot(QTreeWidgetItem *item_parent, std::optional<Decl> root_decl,
                   UserLocations users);
};


class ExpandReferenceHierarchyThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  Index index;
  const RawEntityId id;
  FileLocationCache &line_cache;
  QTreeWidgetItem * const item_parent;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~ExpandReferenceHierarchyThread(void);
  inline explicit ExpandReferenceHierarchyThread(Index index_, RawEntityId id_,
                                                 FileLocationCache &line_cache_,
                                                 QTreeWidgetItem *parent_)
      : index(std::move(index_)),
        id(id_),
        line_cache(line_cache_),
        item_parent(parent_) {}

 signals:
  void UsersOfLevel(QTreeWidgetItem *item_parent, UserLocations users);
};

class ReferenceHierarchyView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);
  void FillRow(QTreeWidgetItem *item, const Decl &decl, const Token &use) const;
  QString FormatBreadcrumbs(const Token &use) const;

 public:
  virtual ~ReferenceHierarchyView(void);

  ReferenceHierarchyView(const CodeTheme &theme_=CodeTheme::DefaultTheme(),
                         QWidget *parent = nullptr);

  void Clear(void);
  void SetIndex(Index index);
  void AddRoot(RawEntityId id);
  void SetRoots(const std::vector<RawEntityId> &new_root_ids);

  // Should we group references by file path? Defaults to `true`.
  void SetGroupByFilePath(bool);

  // Should we show line and column numbers? Defaults to `true`.
  void SetShowLineColumnNumbers(bool);

  // Should we show a preview of the code associated with the reference?
  // Defaults to `true`.
  void SetShowCodePreview(bool);

  // Should we show token context breadcrumbs? These can be useful for a quick
  // diagnosis of the context of a use? Defaults to `true`.
  void SetShowContextBreadcrumbs(bool);

 private slots:
  void OnTreeWidgetItemExpanded(QTreeWidgetItem *item);
  void OnUsersOfFirstLevel(QTreeWidgetItem *parent,
                           std::optional<Decl> root_decl,
                           UserLocations users);
  void OnUsersOfLevel(QTreeWidgetItem *parent, UserLocations users);
  void OnItemPressed(QTreeWidgetItem *item, int column);
  void OnItemSelectionChanged(void);
};

}  // namespace mx::gui
