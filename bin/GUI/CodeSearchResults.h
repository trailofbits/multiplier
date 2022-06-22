// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QStyledItemDelegate>
#include <QTableView>

#include <memory>

namespace mx {
class RegexQueryMatch;
namespace gui {

class CodeSearchResultsModel;
class CodeSearchResultsModelImpl;
class CodeSearchResultsView;
class Multiplier;
class SortableCodeSearchResultsModel;

class CodeSearchResultsItemDelegate final : public QStyledItemDelegate {
  Q_OBJECT

  CodeSearchResultsModel * const model;
  SortableCodeSearchResultsModel * const proxy;

  explicit CodeSearchResultsItemDelegate(
      CodeSearchResultsModel *model_,
      SortableCodeSearchResultsModel *proxy_=nullptr,
      QObject *parent_=nullptr);

 public:
  friend class CodeSearchResultsView;
  virtual ~CodeSearchResultsItemDelegate(void);

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const Q_DECL_FINAL;
};

class CodeSearchResultsModel final : public QAbstractTableModel {
  Q_OBJECT

  std::unique_ptr<CodeSearchResultsModelImpl> d;

  void AddHeader(const RegexQueryMatch &match);

 public:
  friend class CodeSearchResultsItemDelegate;
  friend class CodeSearchResultsView;
  friend class SortableCodeSearchResultsModel;

  virtual ~CodeSearchResultsModel(void);

  explicit CodeSearchResultsModel(Multiplier &multiplier_,
                                  QObject *parent_=nullptr);

  void AddResult(const RegexQueryMatch &match);

  int columnCount(const QModelIndex &parent) const Q_DECL_FINAL;
  int rowCount(const QModelIndex &parent) const Q_DECL_FINAL;

  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const Q_DECL_FINAL;
  QVariant data(const QModelIndex &index, int role) const Q_DECL_FINAL;

 signals:
  void AddedRows(void);
};

class SortableCodeSearchResultsModel final : public QSortFilterProxyModel {
  Q_OBJECT

  virtual ~SortableCodeSearchResultsModel(void);

 public:
  QVariant data(const QModelIndex &index, int role) const Q_DECL_FINAL;
};

class CodeSearchResultsView : public QTableView {
  Q_OBJECT

  using QTableView::setModel;
  using QTableView::setRootIndex;
  using QTableView::setSelectionMode;
  using QTableView::setSelectionBehavior;
  using QTableView::setEditTriggers;

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);

 public:
  virtual ~CodeSearchResultsView(void);

  explicit CodeSearchResultsView(CodeSearchResultsModel *model_,
                                 QWidget *parent_=nullptr);

  int columnCount(void) const;
  int rowCount(void) const;

 private slots:
  void OnRowsAdded(void);
};

}  // namespace gui
}  // namespace mx
