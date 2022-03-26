// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "FileView.h"

#include <QPainter>
#include <QSplitter>
#include <QThreadPool>
#include <QVBoxLayout>

namespace mx::gui {

struct FileView::PrivateData {
  std::optional<File> file;

  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
};

DownloadFileThread::~DownloadFileThread(void) {}

void DownloadFileThread::run(void) {
  emit DownloadedFile(ep->file(file_id));
}

FileView::~FileView(void) {}

FileView::FileView(EntityProvider::Ptr ep, std::filesystem::path file_path,
                   FileId file_id, QWidget *parent)
    : QTabWidget(parent),
      d(std::make_unique<PrivateData>()) {

  DownloadFileInBackground(std::move(ep), file_id);

  d->layout = new QVBoxLayout;
  d->splitter = new QSplitter(Qt::Horizontal);

  d->layout->setContentsMargins(0, 0, 0, 0);
  d->layout->addWidget(d->splitter);

  setMovable(true);
  setTabsClosable(true);
  setDocumentMode(true);
  setTabPosition(TabPosition::North);

  setWindowTitle(file_path.c_str());
  setLayout(d->layout);

  InitializeWidgets();
}

void FileView::DownloadFileInBackground(
    EntityProvider::Ptr ep, FileId file_id) {
  auto downloader = new DownloadFileThread(std::move(ep), file_id);
  downloader->setAutoDelete(true);

  connect(downloader, &DownloadFileThread::DownloadedFile,
          this, &FileView::OnDownloadedFile);
  QThreadPool::globalInstance()->start(downloader);
}

void FileView::InitializeWidgets(void) {
  QList<int> splitter_sizes;
  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);

  update();
}

void FileView::OnDownloadedFile(std::optional<File> file) {
  if (file.has_value()) {
    d->file = std::move(file.value());
    update();
  }
}

void FileView::paintEvent(QPaintEvent *event) {
  if (d->file.has_value()) {
    this->QWidget::paintEvent(event);
    return;
  }

  static const auto kTextFlags = Qt::AlignCenter | Qt::TextSingleLine;

  QString message = tr("Downloading...");
  QFont message_font = font();
  message_font.setPointSizeF(message_font.pointSizeF() * 2.0);
  message_font.setBold(true);

  QFontMetrics font_metrics(message_font);
  auto message_rect = font_metrics.boundingRect(QRect(0, 0, 0xFFFF, 0xFFFF),
                                                kTextFlags, message);

  const auto &event_rec = event->rect();
  auto message_x_pos = (event_rec.width() / 2) - (message_rect.width() / 2);
  auto message_y_pos = (event_rec.height() / 2) - (message_rect.height() / 2);

  message_rect.moveTo(message_x_pos, message_y_pos);

  QPainter painter(this);
  painter.fillRect(event_rec, palette().color(QPalette::Window));

  painter.setFont(message_font);
  painter.setPen(QPen(palette().color(QPalette::WindowText)));
  painter.drawText(message_rect, kTextFlags, message);

  event->accept();
}

}  // namespace mx::gui
