// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Index.h>
#include <QBrush>
#include <QPaintEvent>
#include <QPlainTextEdit>
#include <QRunnable>
#include <vector>

#include "CodeTheme.h"

namespace mx::gui {

// Structured code, ready for rendering.
struct Code {
  QString data;
  std::vector<int> start_of_token;
  std::vector<bool> italic;
  std::vector<bool> bold;
  std::vector<bool> underline;
  std::vector<const QBrush *> foreground;
  std::vector<unsigned> fragment_token_ids_begin;
  std::vector<unsigned> declaration_ids_begin;

  std::vector<RawEntityId> fragment_token_ids;
  std::vector<RawEntityId> declaration_ids;
};

using CodePtr = Code *;

// Thread that goes and downloads and structures the relevant code in the
// background.
class DownloadCodeThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  void run(void) final;

  DownloadCodeThread(PrivateData *d_);

 public:
  virtual ~DownloadCodeThread(void);

  static DownloadCodeThread *CreateFileDownloader(
      Index index_, const CodeTheme &theme_, FileId file_id_);

  static DownloadCodeThread *CreateFragmentDownloader(
      Index index_, const CodeTheme &theme_, FragmentId frag_id_);

  static DownloadCodeThread *CreateTokenRangeDownloader(
      Index index_, const CodeTheme &theme_, RawEntityId begin_tok_id,
      RawEntityId end_tok_id);

 signals:
  void DownloadFailed(void);
  void RenderCode(CodePtr code);
};

enum class CodeViewKind {
  kInLine,
  kMultiLine
};

// A view for code. Code views have baked-in themes once initialized. Themes
// have access to rich data only available during render-time, such as whether
// or not a declaration has a definition.
class CodeView final : public QPlainTextEdit {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~CodeView(void);
  CodeView(CodeViewKind kind_,
           const CodeTheme &theme_=CodeTheme::DefaultTheme(),
           QWidget *parent = nullptr);

//  // Should line numbers be shown?
//  void SetLineNumbersEnabled(bool);
//
//  // Should we render this as a mutli-line code view, or a single-line code
//  // view? Turning multi-line off disables line numbers.
//  void SetMultiLine(bool);

  // Change the underlying data of this view.
  void SetFile(Index index, FileId file_id);
  void SetFragment(Index index, FragmentId fragment_id);
  void SetTokenRange(Index index, RawEntityId begin_tok_id,
                     RawEntityId end_tok_id);

 protected:
  void paintEvent(QPaintEvent *event) final;
  void mousePressEvent(QMouseEvent *event) final;

 private:
  void InitializeWidgets(void);

 private slots:
  void OnDownloadFailed(void);
  void OnRenderCode(CodePtr code);

//  void OnBlockCountChanged(int new_block_count);
//  void OnHighlightCurrentLine(void);
//  void updateLineNumberArea(const QRect &rect, int dy);

 signals:
  void DeclarationsClicked(std::vector<RawEntityId> ids);
};

}  // namespace mx::gui
