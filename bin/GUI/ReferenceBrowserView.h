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

#include <optional>
#include <vector>

#include "Event.h"

namespace mx {
class Decl;
class FileLocationCache;
class Index;
class Token;
namespace gui {

class Multiplier;
class CodeTheme;

using UserLocation = std::pair<Decl, TokenRange>;
using UserLocations = std::vector<UserLocation>;
using UserLocationsPtr = std::shared_ptr<std::vector<UserLocation>>;

// Implements the reference browser view. This view presents a tree of users
// of some entity. At the N+1th level, you see the users of items at the Nth
// level.
class ReferenceBrowserView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);
  void FillRow(QTreeWidgetItem *item, const Decl &decl, const Token &use) const;
  QString FormatBreadcrumbs(const Token &use, bool run_length_encode) const;

 public:
  virtual ~ReferenceBrowserView(void);

  ReferenceBrowserView(Multiplier &multiplier, QWidget *parent = nullptr);

  void Clear(void);
  void AddRoot(RawEntityId id);
  void SetRoots(std::vector<RawEntityId> new_root_ids);
  void SetCodePreviewHorizontal(void);
  void SetCodePreviewVertical(void);

 public slots:
  void OnDownloadedFileList(FilePathList files);

 private slots:
  MX_DECLARE_DECLARATION_SLOTS

  void OnTreeWidgetItemExpanded(QTreeWidgetItem *item);
  void OnUsersOfFirstLevel(QTreeWidgetItem *parent, uint64_t counter,
                           std::optional<Decl> root_decl,
                           UserLocationsPtr users);
  void OnUsersOfLevel(QTreeWidgetItem *parent, uint64_t counter,
                      UserLocationsPtr users);
  void OnItemPressed(QTreeWidgetItem *item, int column);
  void OnItemSelectionChanged(void);

 signals:
  MX_DECLARE_DECLARATION_SIGNALS
};

// A background thread that downloads the first level of references for one
// of the roots of the tree.
class InitReferenceHierarchyThread final : public QObject, public QRunnable {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~InitReferenceHierarchyThread(void);
  explicit InitReferenceHierarchyThread(const Index &index_, RawEntityId id_,
                                        const FileLocationCache &line_cache_,
                                        QTreeWidgetItem *parent_,
                                        uint64_t counter);

 signals:
  void UsersOfRoot(QTreeWidgetItem *item_parent, uint64_t counter,
                   std::optional<Decl> root_decl, UserLocationsPtr users);
};

// A background thread that downloads the Nth level of references for one
// of the items of the tree.
class ExpandReferenceHierarchyThread final : public QObject, public QRunnable {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

 public:
  virtual ~ExpandReferenceHierarchyThread(void);
  explicit ExpandReferenceHierarchyThread(const Index &index_, RawEntityId id_,
                                          const FileLocationCache &line_cache_,
                                          QTreeWidgetItem *parent_,
                                          uint64_t counter);

 signals:
  void UsersOfLevel(QTreeWidgetItem *item_parent, uint64_t counter,
                    UserLocationsPtr users);
};

}  // namespace gui
}  // namespace mx
