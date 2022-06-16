// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <optional>
#include <QPlainTextEdit>
#include <QRunnable>
#include <vector>

#include "Event.h"

QT_BEGIN_NAMESPACE
class QMouseEvent;
class QPaintEvent;
QT_END_NAMESPACE
namespace mx {
class File;
class Fragment;
class Index;
class Token;
class TokenRange;
namespace gui {

class CodeTheme;

// A view for code. Code views have baked-in themes once initialized. Themes
// have access to rich data only available during render-time, such as whether
// or not a declaration has a definition.
class CodeView final : public QPlainTextEdit {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~CodeView(void);
  CodeView(const CodeTheme &theme_, QWidget *parent = nullptr);

  void ScrollToToken(const TokenRange &tok);
  void ScrollToToken(const Token &tok);
  void ScrollToToken(RawEntityId file_tok_id);

  // Change the underlying data of this view.
  void SetFile(const File &file);
  void SetFile(const Index &index, FileId file_id);
  void SetFragment(const Fragment &fragment);
  void SetFragment(const Index &index, FragmentId fragment_id);
  void SetTokenRange(const Index &index, RawEntityId begin_tok_id,
                     RawEntityId end_tok_id);

  void Clear(void);

 protected:
  void scrollContentsBy(int dx, int dy) Q_DECL_FINAL;
  void paintEvent(QPaintEvent *event) Q_DECL_FINAL;
  void mousePressEvent(QMouseEvent *event) Q_DECL_FINAL;

 private:
  void InitializeWidgets(void);
  std::optional<std::pair<unsigned, int>>
  TokenIndexForPosition(const QPoint &pos) const;

  void EmitEventsForIndex(unsigned index);

 private slots:
  void OnDownloadFailed(void);
  void OnHighlightLine(void);
  void OnRenderCode(void *code, uint64_t counter);

 signals:
  void TokenPressEvent(EventLocations loc_ids);
};

// Thread that goes and downloads and structures the relevant code in the
// background.
class DownloadCodeThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) Q_DECL_FINAL;

  DownloadCodeThread(PrivateData *d_);

 public:
  virtual ~DownloadCodeThread(void);

  static DownloadCodeThread *CreateFileDownloader(
      const Index &index_, const CodeTheme &theme_, uint64_t counter,
      FileId file_id_);

  static DownloadCodeThread *CreateFragmentDownloader(
      const Index &index_, const CodeTheme &theme_, uint64_t counter,
      FragmentId frag_id_);

  static DownloadCodeThread *CreateTokenRangeDownloader(
      const Index &index_, const CodeTheme &theme_, uint64_t counter,
      RawEntityId begin_tok_id, RawEntityId end_tok_id);

 signals:
  void DownloadFailed(void);
  void RenderCode(void *code, uint64_t counter);
};

}  // namespace gui
}  // namespace mx
