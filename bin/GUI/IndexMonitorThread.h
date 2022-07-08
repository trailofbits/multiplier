// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QObject>

#include <multiplier/Index.h>

QT_BEGIN_NAMESPACE
class QThread;
QT_END_NAMESPACE
namespace mx::gui {

class IndexMonitorThread final : public QObject {
  Q_OBJECT

  QThread *worker;

 public:
  virtual ~IndexMonitorThread(void);
  explicit IndexMonitorThread(Index index_, QObject *parent_=nullptr);

  void Start(void);
  void Stop(void);

 signals:
  void VersionNumberChanged(Index index);
  void MonitorVersionNumber(void);
  void Stopped(void);

 private slots:
  void OnVersionNumberChanged(Index index);
};

class IndexMonitor final : public QObject {
  Q_OBJECT

  friend class IndexMonitorThread;

  const Index index;
  unsigned last_version_number;

 public:
  virtual ~IndexMonitor(void);
  IndexMonitor(Index index_);

 signals:
  void VersionNumberChanged(Index index);

 private slots:
  void CheckForVersionNumberChange(void);
};

}  // namespace mx::gui
