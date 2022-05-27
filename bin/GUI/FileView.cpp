// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "FileView.h"

#include <QApplication>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QSplitter>
#include <QString>
#include <QThreadPool>
#include <QVBoxLayout>
#include <iostream>
#include <map>
#include <vector>
#include <set>

namespace mx::gui {
namespace {

enum class FileViewState {
  kInitialized,
  kDownloading,
  kRendering,
  kRendered,
  kFailed
};

static const QString css(R"(
<style type="text/css">
a, a:hover, a:visited, a:active {
  color: rgb(%1, %2, %3);
  text-decoration: none;
}
td.number {
  text-align: right;
  padding-right: 10px;
}
td.code {
  color: rgb(%1, %2, %3);
}
</style>
)");
static const QString table_begin(R"(
<table cellpadding="0" cellspacing="0" border="0">
<tr>
<td class="number" id="line1">1</td>
<td class="code">)");

static const QString table_end("</td></tr></table>");

static const QString anchor_format("%1%2");

static const QString token_link("<a href=\"%1\">%2</a>");

static const QString new_line(R"(
</td></tr><tr><td class="number" id="line%1">%1</td><td class="code">
)");

static const QString space("&nbsp;");
static const QString tab("&nbsp;&nbsp;&nbsp;&nbsp;");

}  // namespace

struct FileView::PrivateData {
  FileLocationCache line_number_cache;
  FileViewState state{FileViewState::kInitialized};
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
};

DownloadFileThread::~DownloadFileThread(void) {}

void DownloadFileThread::run(void) {
  auto file = index.file(file_id);  // Download the file.
  if (!file) {
    emit DownloadedFile(true);
    return;
  }

  // Download all of the fragments and build an index of the starting
  // locations of each fragment in this file.
  std::map<RawEntityId, std::vector<TokenList>> fragment_tokens;
  for (auto fragment : Fragment::in(file.value())) {
    for (Token tok : fragment.file_tokens()) {
      fragment_tokens[tok.id()].emplace_back(fragment.parsed_tokens());
      break;
    }
  }

  // We've now downloaded basically everything we need to, so tell the main
  // thread that it can switch to the rendering state.
  emit DownloadedFile(false);

  QColor color = qApp->palette().brush(QPalette::Text).color();
  QString os = css.arg(color.red()).arg(color.green()).arg(color.blue());
  QString ids_os;
  QString tok_part;
  ids_os.reserve(16);
  os.reserve(static_cast<int>(file->data().size()) * 4);

  std::map<RawEntityId, std::vector<Token>> open_matches;

  int line_number = 1;
  os.append(table_begin);

  for (Token file_tok : file->tokens()) {
    RawEntityId file_tok_id = file_tok.id();

    // This token corresponds to the beginning of a fragment. We might have a
    // one-to-many mapping of file tokens to fragment tokens. So when we come
    // across the first token
    if (auto fragment_tokens_it = fragment_tokens.find(file_tok_id);
        fragment_tokens_it != fragment_tokens.end()) {
      for (const TokenList &parsed_toks : fragment_tokens_it->second) {
        for (Token parsed_tok : parsed_toks) {
          if (auto file_tok_of_parsed_tok = parsed_tok.file_token()) {
            open_matches[file_tok_of_parsed_tok->id()].push_back(parsed_tok);
          }
        }
      }

      fragment_tokens.erase(file_tok_id);  // Garbage collect.
    }

    auto sep = "#";
    ids_os.clear();
    if (auto fragment_tokens_it = open_matches.find(file_tok_id);
        fragment_tokens_it != open_matches.end()) {

      for (Token parsed_tok : fragment_tokens_it->second) {
        ids_os.append(anchor_format.arg(sep).arg(parsed_tok.id()));
        sep = "_";
      }

      open_matches.erase(file_tok_id);  // Garbage collect.
    }

    auto append_tok = [] (QString &buff, const QString &anchor,
                          const QString &data, bool ws) {
      if (data.size()) {
        if (!ws && anchor.size()) {
          buff.append(token_link.arg(anchor).arg(data));
        } else {
          buff.append(data);
        }
      }
    };

    bool is_whitespace = true;
    std::string_view utf8_tok = file_tok.data();
    int num_utf8_bytes = static_cast<int>(utf8_tok.size());
    for (QChar ch : QString::fromUtf8(utf8_tok.data(),
                                      num_utf8_bytes).toHtmlEscaped()) {
      switch (ch.unicode()) {
        case QChar::Tabulation:
          tok_part.append(tab);
          break;
        case QChar::Space:
        case QChar::Nbsp:
          tok_part.append(space);
          break;
        case QChar::ParagraphSeparator:
        case QChar::LineFeed:
        case QChar::LineSeparator:
          append_tok(os, ids_os, tok_part, is_whitespace);
          tok_part.clear();
          is_whitespace = true;
          line_number++;
          os.append(new_line.arg(QString::number(line_number)));
          break;
        case QChar::CarriageReturn:
          continue;
        default:
          tok_part.append(ch);
          is_whitespace = false;
          break;
      }
    }

    append_tok(os, ids_os, tok_part, is_whitespace);
    tok_part.clear();
  }

  os.append(table_end);

  // We've now rendered the HTML.
  emit RenderedFile(std::move(os));
}

FileView::~FileView(void) {}

FileView::FileView(Index index_, std::filesystem::path file_path,
                   FileId file_id, QWidget *parent)
    : QTabWidget(parent),
      d(std::make_unique<PrivateData>()) {

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
  DownloadFileInBackground(std::move(index_), file_id);
}

void FileView::DownloadFileInBackground(Index index, FileId file_id) {
  if (d->state != FileViewState::kInitialized) {
    d->state = FileViewState::kFailed;
    return;
  }

  d->state = FileViewState::kDownloading;

  auto downloader = new DownloadFileThread(std::move(index), file_id);
  downloader->setAutoDelete(true);

  connect(downloader, &DownloadFileThread::DownloadedFile,
          this, &FileView::OnDownloadedFile);

  connect(downloader, &DownloadFileThread::RenderedFile,
          this, &FileView::OnRenderedFile);

  QThreadPool::globalInstance()->start(downloader);
}

void FileView::InitializeWidgets(void) {
  QList<int> splitter_sizes;
  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);
  update();
}

void FileView::OnDownloadedFile(bool failed) {
  if (failed) {
    d->state = FileViewState::kFailed;
  } else {
    d->state = FileViewState::kRendering;
  }
  update();
}

void FileView::OnRenderedFile(QString html) {
  QTextBrowser *content = new QTextBrowser;
#ifdef __linux__
  QFont font("Hack");
#else
  QFont font("Monaco");
#endif
  font.setStyleHint(QFont::TypeWriter);
  content->setCurrentFont(font);
  content->setFont(font);
  content->setAcceptRichText(true);
  content->setHtml(html);

  d->splitter->addWidget(content);
  d->state = FileViewState::kRendered;
  update();
}

void FileView::paintEvent(QPaintEvent *event) {
  QString message;
  switch (d->state) {
    case FileViewState::kInitialized:
      message = tr("Preparing to download...");
      break;
    case FileViewState::kDownloading:
      message = tr("Downloading...");
      break;
    case FileViewState::kRendering:
      message = tr("Rendering...");
      break;
    case FileViewState::kRendered:
      this->QWidget::paintEvent(event);
      return;
    case FileViewState::kFailed:
      message = tr("Failed");
      break;
  }

  static const auto kTextFlags = Qt::AlignCenter | Qt::TextSingleLine;

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
