// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "IndexMonitorThread.h"

#include <QThread>
#include <QTimer>

#include <multiplier/Index.h>

namespace mx::gui {

IndexMonitorThread::~IndexMonitorThread(void) {
  if (worker) {
    worker->quit();
    worker->wait();
    worker->deleteLater();
  }
}

IndexMonitorThread::IndexMonitorThread(Index index_, QObject *parent_)
    : QObject(parent_),
      worker(new QThread) {

  auto monitor = new IndexMonitor(std::move(index_));
  monitor->moveToThread(worker);

  connect(this, &IndexMonitorThread::Stopped,
          this, &IndexMonitorThread::deleteLater);

  connect(monitor, &IndexMonitor::VersionNumberChanged,
          this, &IndexMonitorThread::OnVersionNumberChanged);

  connect(this, &IndexMonitorThread::MonitorVersionNumber,
          monitor, &IndexMonitor::CheckForVersionNumberChange);
}

void IndexMonitorThread::OnVersionNumberChanged(Index index) {
  emit VersionNumberChanged(std::move(index));

  QTimer::singleShot(1000, this,
                     &IndexMonitorThread::MonitorVersionNumber);
}

void IndexMonitorThread::Start(void) {
  worker->start();
  emit MonitorVersionNumber();
}

void IndexMonitorThread::Stop(void) {
  worker->quit();
  worker->wait();
  worker->deleteLater();
  worker = nullptr;
  emit Stopped();
}

IndexMonitor::~IndexMonitor(void) {}

IndexMonitor::IndexMonitor(Index index_)
    : index(std::move(index_)),
      last_version_number(0u) {}

void IndexMonitor::CheckForVersionNumberChange(void) {
  auto new_version_number = index.version_number(true);
  if (new_version_number != last_version_number) {
    last_version_number = new_version_number;
    emit VersionNumberChanged(index);

  // Re-check in one second.
  } else {
    QTimer::singleShot(1000, this,
                       &IndexMonitor::CheckForVersionNumberChange);
  }
}

}  // namespace mx::gui
