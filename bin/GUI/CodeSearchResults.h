// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QAbstractTableModel>
#include <QPoint>
#include <QSortFilterProxyModel>
#include <QStyledItemDelegate>
#include <QWidget>

#include <memory>

#include "Event.h"

namespace mx {
class RegexQueryMatch;
class WeggliQueryMatch;
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

  QSize sizeHint(const QStyleOptionViewItem &option,
                 const QModelIndex &index) const Q_DECL_FINAL;
};

class CodeSearchResultsModel final : public QAbstractTableModel {
  Q_OBJECT

  std::unique_ptr<CodeSearchResultsModelImpl> d;

  void AddHeader(const RegexQueryMatch &match);
  void AddHeader(const WeggliQueryMatch &match);

 public:
  friend class CodeSearchResultsItemDelegate;
  friend class CodeSearchResultsView;
  friend class SortableCodeSearchResultsModel;

  virtual ~CodeSearchResultsModel(void);

  explicit CodeSearchResultsModel(Multiplier &multiplier_,
                                  QObject *parent_=nullptr);

  void AddResult(const RegexQueryMatch &match);
  void AddResult(const WeggliQueryMatch &match);

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

 public:
  virtual ~SortableCodeSearchResultsModel(void);

  QVariant data(const QModelIndex &index, int role) const Q_DECL_FINAL;
};

class CodeSearchResultsView : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void InitializeWidgets(void);
  void ClickedOnToken(unsigned row, unsigned tok_index);
  void ShowFragmentToken(unsigned row, RawEntityId file_tok_id,
                         RawEntityId frag_tok_id);
  void ShowFileToken(unsigned row, RawEntityId file_tok_id);
  void MapClickToToken(QPoint last_click_loc, const QModelIndex &index);
  bool eventFilter(QObject *watched, QEvent *event) Q_DECL_FINAL;

 public:
  virtual ~CodeSearchResultsView(void);

  explicit CodeSearchResultsView(CodeSearchResultsModel *model_,
                                 QWidget *parent_=nullptr);

 private slots:
  void OnCurrentChanged(const QModelIndex &index, const QModelIndex &);
  void ActOnTokenPressEvent(EventLocations locs);
  void OnRowsAdded(void);

 signals:
  void TokenPressEvent(EventSource source, EventLocations loc_ids);
};

}  // namespace gui
}  // namespace mx
