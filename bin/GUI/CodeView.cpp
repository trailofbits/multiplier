// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeView.h"

#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QFontMetrics>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
#include <QString>
#include <QStringRef>
#include <QTextDocument>
#include <QThreadPool>

#include <atomic>
#include <cassert>
#include <iostream>
#include <map>
#include <multiplier/Index.h>
#include <optional>
#include <unordered_map>
#include <vector>

#include "CodeTheme.h"
#include "Util.h"

namespace mx::gui {
namespace {

enum class CodeViewState {
  kInitialized,
  kDownloading,
  kRendering,
  kRendered,
  kFailed
};

}  // namespace

class Code {
 public:
  QString data;
  std::vector<int> start_of_token;
  std::vector<bool> italic;
  std::vector<bool> bold;
  std::vector<bool> underline;
  std::vector<const QBrush *> foreground;
  std::vector<const QBrush *> background;
  std::vector<unsigned> declaration_ids_begin;
  std::vector<RawEntityId> declaration_ids;
  std::vector<RawEntityId> file_token_ids;
};

struct CodeView::PrivateData {

  // Current rendering state for the code view.
  CodeViewState state{CodeViewState::kInitialized};

  // Used to track re-entrancy issues, e.g. if in the process of rendering one
  // code, we've started to try to render another code.
  std::atomic<uint64_t> counter;

  // Thread-safe cache for figuring out line/column numbers.
  std::unique_ptr<Code> code;

  const CodeTheme &theme;

  // How to mark events form this code view.
  const EventSource source;

  // The entity id of a file token that we'll target for scrolling.
  RawEntityId scroll_target_eid{kInvalidEntityId};

  unsigned last_mouse_move_index{~0u};

  // Keep track of the last clicked block number. If we click to go somewhere
  // in our own file, and where we're going is on the same line or a nearby
  // line, then we don't want to have to scroll, as that can be jarring.
  int last_block{-1};

  std::vector<RawEntityId> last_entity_ids;

  inline PrivateData(const CodeTheme &theme_, EventSource source_)
      : theme(theme_),
        source(source_) {}
};

struct DownloadCodeThread::PrivateData {
  const Index index;
  const CodeTheme &theme;
  const uint64_t counter;

  std::optional<FileId> file_id;
  std::optional<FragmentId> fragment_id;
  std::optional<std::pair<RawEntityId, RawEntityId>> token_range;

  std::map<RawEntityId, std::vector<TokenList>> fragment_tokens;
  TokenRange file_tokens;

  inline explicit PrivateData(Index index_, const CodeTheme &theme_,
                              uint64_t counter_)
      : index(std::move(index_)),
        theme(theme_),
        counter(counter_) {}

  bool DownloadFileTokens(void);
  bool DownloadFragmentTokens(void);
  bool DownloadRangeTokens(void);
};

DownloadCodeThread::DownloadCodeThread(PrivateData *d_)
    : d(std::move(d_)) {
  setAutoDelete(true);
}

DownloadCodeThread::~DownloadCodeThread(void) {}

DownloadCodeThread *DownloadCodeThread::CreateFileDownloader(
    const Index &index_, const CodeTheme &theme_, uint64_t counter_,
    FileId file_id_) {
  auto d = new PrivateData(index_, theme_, counter_);
  d->file_id.emplace(file_id_);
  return new DownloadCodeThread(d);
}

DownloadCodeThread *DownloadCodeThread::CreateFragmentDownloader(
    const Index &index_, const CodeTheme &theme_, uint64_t counter_,
    FragmentId frag_id_) {
  auto d = new PrivateData(index_, theme_, counter_);
  d->fragment_id.emplace(frag_id_);
  return new DownloadCodeThread(d);
}

DownloadCodeThread *DownloadCodeThread::CreateTokenRangeDownloader(
    const Index &index_, const CodeTheme &theme_, uint64_t counter_,
    RawEntityId begin_tok_id, RawEntityId end_tok_id) {

  auto d = new PrivateData(index_, theme_, counter_);
  d->token_range.emplace(begin_tok_id, end_tok_id);
  return new DownloadCodeThread(d);
}

bool DownloadCodeThread::PrivateData::DownloadFileTokens(void) {
  auto file = index.file(file_id.value());
  if (!file) {
    return false;
  }

  file_tokens = file->tokens();

  // Download all of the fragments and build an index of the starting
  // locations of each fragment in this file.
  for (auto fragment : Fragment::in(file.value())) {
    for (Token tok : fragment.file_tokens()) {
      fragment_tokens[tok.id()].emplace_back(fragment.parsed_tokens());
      break;
    }
  }

  return true;
}

bool DownloadCodeThread::PrivateData::DownloadFragmentTokens(void) {
  auto fragment = index.fragment(fragment_id.value());
  if (!fragment) {
    return false;
  }

  file_tokens = fragment->file_tokens();
  for (const Token &tok : file_tokens) {
    fragment_tokens[tok.id()].emplace_back(fragment->parsed_tokens());
    break;
  }

  return true;
}

bool DownloadCodeThread::PrivateData::DownloadRangeTokens(void) {
  VariantId begin_vid = EntityId(token_range->first).Unpack();
  VariantId end_vid = EntityId(token_range->second).Unpack();

  if (begin_vid.index() != end_vid.index()) {
    return false;
  }

  unsigned begin_offset = 0;
  unsigned end_offset = 0;

  // Show a range of file tokens.
  if (std::holds_alternative<FileTokenId>(begin_vid) &&
      std::holds_alternative<FileTokenId>(end_vid)) {

    FileTokenId begin_fid = std::get<FileTokenId>(begin_vid);
    FileTokenId end_fid = std::get<FileTokenId>(end_vid);

    if (begin_fid.file_id != end_fid.file_id ||
        begin_fid.offset > end_fid.offset) {
      return false;
    }

    file_id.emplace(begin_fid.file_id);
    if (!DownloadFileTokens()) {
      return false;
    }

    file_tokens = file_tokens.slice(begin_fid.offset, end_fid.offset + 1u);
    return true;

  // Show a range of fragment tokens.
  } else if (std::holds_alternative<FragmentTokenId>(begin_vid) &&
             std::holds_alternative<FragmentTokenId>(end_vid)) {

    FragmentTokenId begin_fid = std::get<FragmentTokenId>(begin_vid);
    FragmentTokenId end_fid = std::get<FragmentTokenId>(end_vid);

    if (begin_fid.fragment_id != end_fid.fragment_id ||
        begin_fid.offset > end_fid.offset) {
      return false;
    }

    fragment_id.emplace(begin_fid.fragment_id);
    if (!DownloadFragmentTokens()) {
      return false;
    }

    file_tokens = file_tokens.slice(begin_fid.offset, end_fid.offset + 1u);
    return true;

  } else {
    return false;
  }
}

void DownloadCodeThread::run(void) {

  if (d->file_id) {
    if (!d->DownloadFileTokens()) {
      emit DownloadFailed();
      return;
    }
  } else if (d->fragment_id) {
    if (!d->DownloadFragmentTokens()) {
      emit DownloadFailed();
      return;
    }
  } else if (d->token_range) {
    if (!d->DownloadRangeTokens()) {
      emit DownloadFailed();
      return;
    }
  }

  const auto num_file_tokens = d->file_tokens.size();
  if (!num_file_tokens) {
    emit DownloadFailed();
    return;
  }

  auto code = new Code;

  d->theme.BeginTokens();

  code->data.reserve(static_cast<int>(d->file_tokens.data().size()));
  code->bold.reserve(num_file_tokens);
  code->italic.reserve(num_file_tokens);
  code->underline.reserve(num_file_tokens);
  code->foreground.reserve(num_file_tokens);
  code->background.reserve(num_file_tokens);
  code->start_of_token.reserve(num_file_tokens + 1u);
  code->declaration_ids_begin.reserve(num_file_tokens + 1u);
  code->file_token_ids.reserve(num_file_tokens);

  std::map<RawEntityId, std::vector<Token>> file_to_frag_toks;
  std::vector<Decl> tok_decls;

  RawEntityId last_file_tok_id = kInvalidEntityId;
  for (Token file_tok : d->file_tokens) {
    RawEntityId file_tok_id = file_tok.id();

    // Sortedness needed for `CodeView::ScrollToToken`.
    assert(last_file_tok_id < file_tok_id);
    last_file_tok_id = file_tok_id;

    // This token corresponds to the beginning of a fragment. We might have a
    // one-to-many mapping of file tokens to fragment tokens. So when we come
    // across the first token
    if (auto fragment_tokens_it = d->fragment_tokens.find(file_tok_id);
        fragment_tokens_it != d->fragment_tokens.end()) {
      for (const TokenList &parsed_toks : fragment_tokens_it->second) {
        for (Token parsed_tok : parsed_toks) {
          if (auto file_tok_of_parsed_tok = parsed_tok.file_token()) {
            file_to_frag_toks[file_tok_of_parsed_tok->id()].push_back(parsed_tok);
          }
        }
      }

      d->fragment_tokens.erase(file_tok_id);  // Garbage collect.
    }

    auto tok_start = code->data.size();

    bool is_empty = true;
    bool is_whitespace = true;
    std::string_view utf8_tok = file_tok.data();
    int num_utf8_bytes = static_cast<int>(utf8_tok.size());
    for (QChar ch : QString::fromUtf8(utf8_tok.data(), num_utf8_bytes)) {
      switch (ch.unicode()) {
        case QChar::Tabulation:
          is_empty = false;
          code->data.append(QChar::Tabulation);
          break;
        case QChar::Space:
        case QChar::Nbsp:
          is_empty = false;
          code->data.append(QChar::Space);
          break;
        case QChar::ParagraphSeparator:
        case QChar::LineFeed:
        case QChar::LineSeparator:
          is_empty = false;
          code->data.append(QChar::LineSeparator);
          break;
        case QChar::CarriageReturn:
          continue;
        default:
          code->data.append(ch);
          is_empty = false;
          is_whitespace = false;
          break;
      }
    }

    if (is_empty) {
      continue;
    }

    code->file_token_ids.push_back(file_tok_id);

    code->declaration_ids_begin.push_back(
        static_cast<unsigned>(code->declaration_ids.size()));

    tok_decls.clear();

    DeclCategory category = DeclCategory::UNKNOWN;
    TokenClass file_tok_class = ClassifyToken(file_tok);

    // Try to find all declarations associated with this token. There could be
    // multiple if there are multiple fragments overlapping this specific piece
    // of code. However, just because there are multiple fragments, doesn't mean
    // the related declarations are unique.
    if (auto frag_tok_it = file_to_frag_toks.find(file_tok_id);
        frag_tok_it != file_to_frag_toks.end()) {
      for (const Token &frag_tok : frag_tok_it->second) {
        if (auto related_decl = DeclForToken(frag_tok)) {
          tok_decls.emplace_back(related_decl.value());

          // Take the first category we get.
          if (category == DeclCategory::UNKNOWN) {
            category = related_decl->category();
          }
        }

        // Try to make a better default classification of this token (for syntax
        // coloring in the absence of declaration info).
        if (TokenClass frag_tok_class = ClassifyToken(frag_tok);
            frag_tok_class != file_tok_class &&
            frag_tok_class != TokenClass::kUnknown &&
            frag_tok_class != TokenClass::kIdentifier) {
          file_tok_class = frag_tok_class;
        }
      }

      file_to_frag_toks.erase(file_tok_id);  // Garbage collect.
    }

    CodeTokenKind kind = CodeTokenKind::kUnknown;

    if (is_whitespace) {
      kind = CodeTokenKind::kWhitespace;

    } else if (category == DeclCategory::UNKNOWN) {
      kind = static_cast<CodeTokenKind>(file_tok_class);

    } else {
      kind = static_cast<CodeTokenKind>(
          static_cast<int>(CodeTokenKind::kComment) +
          static_cast<int>(category));
    }

    code->start_of_token.push_back(tok_start);
    auto [b, i, u] = d->theme.Format(file_tok, tok_decls, kind);
    code->bold.push_back(b);
    code->italic.push_back(i);
    code->underline.push_back(u);
    code->foreground.push_back(&(d->theme.TokenForegroundColor(
        file_tok, tok_decls, kind)));
    code->background.push_back(&(d->theme.TokenBackgroundColor(
        file_tok, tok_decls, kind)));

    // We might have found multiple declarations associated with this token, but
    // they might not be unique (e.g. different template instantiations that
    // all call the same global function).
    if (!tok_decls.empty()) {
      static constexpr auto decl_sort = +[] (const Decl &a, const Decl &b) {
        return a.id() < b.id();
      };
      static constexpr auto decl_eq = +[] (const Decl &a, const Decl &b) {
        return a.id() == b.id();
      };
      std::sort(tok_decls.begin(), tok_decls.end(), decl_sort);
      auto it = std::unique(tok_decls.begin(), tok_decls.end(), decl_eq);
      tok_decls.erase(it, tok_decls.end());
      for (const Decl &decl : tok_decls) {
        code->declaration_ids.push_back(decl.id());
      }
    }
  }

  code->start_of_token.push_back(code->data.size());
  code->declaration_ids_begin.push_back(
      static_cast<unsigned>(code->declaration_ids.size()));

  d->theme.EndTokens();

  // We've now rendered the HTML.
  emit RenderCode(std::move(code), d->counter);
}

CodeView::~CodeView(void) {}

CodeView::CodeView(const CodeTheme &theme_, EventSource source_,
                   QWidget *parent)
    : QPlainTextEdit(parent),
      d(std::make_unique<PrivateData>(theme_, source_)) {
  InitializeWidgets();
}

void CodeView::ScrollToToken(const TokenRange &range) {
  if (range) {
    ScrollToToken(range[0].id());
  } else {
    ScrollToToken(kInvalidEntityId);
  }
}

void CodeView::ScrollToToken(const Token &tok) {
  if (tok) {
    ScrollToToken(tok.id());
  } else {
    ScrollToToken(kInvalidEntityId);
  }
}

void CodeView::ScrollToToken(RawEntityId file_tok_id) {
  if (d->state != CodeViewState::kRendered) {
    d->scroll_target_eid = file_tok_id;
    return;
  }

  if (file_tok_id == kInvalidEntityId) {
    return;
  }

  auto begin_it = d->code->file_token_ids.begin();
  auto end_it = d->code->file_token_ids.end();
  auto it = std::lower_bound(begin_it, end_it, file_tok_id);
  if (it == end_it || *it != file_tok_id) {
    return;
  }

  auto tok_index = static_cast<unsigned>((it - begin_it));
  if (tok_index >= d->code->start_of_token.size()) {
    return;
  }

  OnHighlightLine();

  int desired_position = d->code->start_of_token[tok_index];

  // Figure out if we can avoid scrolling due to the text being (probably)
  // visible. If we have a `last_block`, then we clicked on something in here,
  // so it must have been visible.
  if (d->last_block != -1) {
    d->last_block = -1;

    int start_pos = cursorForPosition(QPoint(0, 0)).position();
    QPoint bottom_right(viewport()->width() - 1, viewport()->height() - 1);
    int end_pos = cursorForPosition(bottom_right).position();
    if (start_pos < desired_position && desired_position < end_pos) {
      return;
    }
  }

  QTextCursor loc = textCursor();
  loc.setPosition(desired_position,
                  QTextCursor::MoveMode::MoveAnchor);

  moveCursor(QTextCursor::MoveOperation::End);
  setTextCursor(loc);
  ensureCursorVisible();
  centerCursor();
}

void CodeView::SetFile(const File &file) {
  SetFile(Index::containing(file), file.id());
}

void CodeView::SetFile(const Index &index, FileId file_id) {
  d->state = CodeViewState::kDownloading;
  d->scroll_target_eid = kInvalidEntityId;
  auto prev_counter = d->counter.fetch_add(1u);  // Go to the next version.

  auto downloader = DownloadCodeThread::CreateFileDownloader(
      index, d->theme, prev_counter + 1u, file_id);

  connect(downloader, &DownloadCodeThread::DownloadFailed,
          this, &CodeView::OnDownloadFailed);

  connect(downloader, &DownloadCodeThread::RenderCode,
          this, &CodeView::OnRenderCode);

  QThreadPool::globalInstance()->start(downloader);
  update();
}

void CodeView::SetFragment(const Fragment &fragment) {
  SetFragment(Index::containing(fragment), fragment.id());
}

void CodeView::SetFragment(const Index &index, FragmentId fragment_id) {
  d->state = CodeViewState::kDownloading;
  d->scroll_target_eid = kInvalidEntityId;
  auto prev_counter = d->counter.fetch_add(1u);  // Go to the next version.

  auto downloader = DownloadCodeThread::CreateFragmentDownloader(
      index, d->theme, prev_counter + 1u, fragment_id);

  connect(downloader, &DownloadCodeThread::DownloadFailed,
          this, &CodeView::OnDownloadFailed);

  connect(downloader, &DownloadCodeThread::RenderCode,
          this, &CodeView::OnRenderCode);

  QThreadPool::globalInstance()->start(downloader);
  update();
}

void CodeView::SetTokenRange(const Index &index, RawEntityId begin_tok_id,
                             RawEntityId end_tok_id) {
  d->state = CodeViewState::kDownloading;
  d->scroll_target_eid = kInvalidEntityId;
  auto prev_counter = d->counter.fetch_add(1u);  // Go to the next version.

  auto downloader = DownloadCodeThread::CreateTokenRangeDownloader(
      index, d->theme, prev_counter + 1u, begin_tok_id, end_tok_id);

  connect(downloader, &DownloadCodeThread::DownloadFailed,
          this, &CodeView::OnDownloadFailed);

  connect(downloader, &DownloadCodeThread::RenderCode,
          this, &CodeView::OnRenderCode);

  QThreadPool::globalInstance()->start(downloader);
  update();
}

void CodeView::Clear(void) {
  d->counter.fetch_add(1u);
  d->state = CodeViewState::kInitialized;
  d->code.reset();
  d->last_mouse_move_index = ~0u;
  d->last_block = -1;
  d->last_entity_ids.clear();
  d->scroll_target_eid = kInvalidEntityId;
  this->QPlainTextEdit::clear();
}

void CodeView::InitializeWidgets(void) {

  setReadOnly(true);
  setOverwriteMode(false);
  setMouseTracking(true);  // Enable `mouseMoveEvent`.
  setTextInteractionFlags(Qt::TextSelectableByMouse);
  viewport()->setCursor(Qt::ArrowCursor);
  setFont(d->theme.Font());

  QFontMetrics fm(font());
  setLineWrapMode(d->theme.LineWrap() ?
                  QPlainTextEdit::LineWrapMode::WidgetWidth :
                  QPlainTextEdit::LineWrapMode::NoWrap);
  setTabStopDistance(d->theme.NumSpacesInTab() * fm.width(QChar::Space));

  auto p = palette();
  p.setColor(QPalette::All, QPalette::Base, d->theme.BackgroundColor());
  setPalette(p);
  setBackgroundVisible(false);

  connect(this, &CodeView::cursorPositionChanged,
          this, &CodeView::OnHighlightLine);

  update();
}

void CodeView::OnDownloadFailed(void) {
  d->state = CodeViewState::kFailed;
  update();
}

void CodeView::OnHighlightLine(void) {
  if (d->state != CodeViewState::kRendered) {
    return;
  }

  QList<QTextEdit::ExtraSelection> extra_selections;
  QTextEdit::ExtraSelection selection;

  selection.format.setBackground(d->theme.SelectedLineBackgroundColor());
  selection.format.setProperty(QTextFormat::FullWidthSelection, true);
  selection.cursor = textCursor();
  selection.cursor.clearSelection();
  extra_selections.append(selection);
  setExtraSelections(extra_selections);
}

void CodeView::OnRenderCode(void *code_, uint64_t counter) {
  std::unique_ptr<Code> code(reinterpret_cast<Code *>(code_));
  if (d->counter.load() != counter) {
    return;
  }

  d->state = CodeViewState::kRendering;
  d->last_mouse_move_index = ~0u;
  d->last_block = ~0u;
  d->last_entity_ids.clear();

  // An event may have asked for a new rendering; check re-entrancy.
  update();
  if (d->counter.load() != counter) {
    return;
  }

  d->code.swap(code);
  setPlainText(d->code->data);

  QTextCharFormat format;

  auto num_tokens = d->code->foreground.size();
  const auto &start_of_token = d->code->start_of_token;
  const auto &foreground_color = d->code->foreground;
  const auto &background_color = d->code->background;
  const auto &is_bold = d->code->bold;
  const auto &is_italic = d->code->italic;
  const auto &is_underlined = d->code->underline;

  QTextCursor cursor = textCursor();

  cursor.beginEditBlock();
  for (auto i = 0u; i < num_tokens; ++i) {
    cursor.setPosition(start_of_token[i], QTextCursor::MoveMode::MoveAnchor);
    cursor.setPosition(start_of_token[i + 1], QTextCursor::MoveMode::KeepAnchor);
    format.setForeground(*(foreground_color[i]));
    format.setBackground(*(background_color[i]));
    format.setFontItalic(is_italic[i]);
    format.setFontWeight(is_bold[i] ? QFont::DemiBold : QFont::Normal);
    format.setFontUnderline(is_underlined[i]);
    cursor.setCharFormat(format);
  }
  cursor.endEditBlock();

  d->state = CodeViewState::kRendered;
  ScrollToToken(d->scroll_target_eid);

  assert(d->counter.load() == counter);
  update();
}

std::optional<std::pair<unsigned, int>> CodeView::TokenIndexForPosition(
    const QPoint &pos) const {

  if (d->state != CodeViewState::kRendered) {
    return std::nullopt;
  }

  QTextCursor cursor = cursorForPosition(pos);
  if (cursor.isNull()) {
    return std::nullopt;
  }

  const auto position = cursor.position();
  if (0 > position || position >= d->code->start_of_token.back()) {
    return std::nullopt;
  }

  auto begin_it = d->code->start_of_token.begin();
  auto end_it = d->code->start_of_token.end();
  auto it = std::lower_bound(begin_it, end_it, position);
  if (it == begin_it || it == end_it) {
    return std::nullopt;
  }

  return std::make_pair<unsigned, int>(
      static_cast<unsigned>((it - begin_it) - 1), cursor.blockNumber());
}

std::vector<RawEntityId> CodeView::DeclsForToken(unsigned index) const {
  std::vector<RawEntityId> decl_ids;
  auto decls_begin_index = d->code->declaration_ids_begin[index];
  auto decls_end_index = d->code->declaration_ids_begin[index + 1u];
  if (auto num_decls = decls_end_index - decls_begin_index) {
    decl_ids.reserve(num_decls);
    for (auto i = decls_begin_index; i < decls_end_index; ++i) {
      decl_ids.push_back(d->code->declaration_ids[i]);
    }
  }
  return decl_ids;
}

void CodeView::mouseMoveEvent(QMouseEvent *event) {
  if (auto pos = TokenIndexForPosition(event->pos())) {
    auto [index, block] = pos.value();
    if (index != d->last_mouse_move_index) {
      d->last_mouse_move_index = index;
      d->last_block = block;
      d->last_entity_ids = DeclsForToken(index);
      if (!d->last_entity_ids.empty()) {
        emit DeclarationEvent(d->source, {event->modifiers(), event->buttons(),
                               EventKind::kHover}, d->last_entity_ids);
      }
    }
  } else {
    d->last_mouse_move_index = ~0u;
    d->last_block = -1;
    d->last_entity_ids.clear();
  }

  this->QPlainTextEdit::mouseMoveEvent(event);
}

void CodeView::mousePressEvent(QMouseEvent *event) {
  if (auto pos = TokenIndexForPosition(event->pos())) {
    auto [index, block] = pos.value();
    d->last_block = block;
    d->last_entity_ids = DeclsForToken(index);
    if (!d->last_entity_ids.empty()) {
      emit DeclarationEvent(d->source, {event->modifiers(), event->buttons(),
                             EventKind::kClick}, d->last_entity_ids);
    }
  } else {
    d->last_block = -1;
    d->last_entity_ids.clear();
  }
  this->QPlainTextEdit::mousePressEvent(event);
}

void CodeView::mouseDoubleClickEvent(QMouseEvent *event) {
  if (auto pos = TokenIndexForPosition(event->pos())) {
    auto [index, block] = pos.value();
    d->last_block = block;
    d->last_entity_ids = DeclsForToken(index);
    if (!d->last_entity_ids.empty()) {
      emit DeclarationEvent(d->source, {event->modifiers(), event->buttons(),
                             EventKind::kDoubleClick}, d->last_entity_ids);
    }
  } else {
    d->last_block = -1;
    d->last_entity_ids.clear();
  }
  this->QPlainTextEdit::mouseDoubleClickEvent(event);
}

void CodeView::scrollContentsBy(int dx, int dy) {
  d->last_block = -1;
  d->last_entity_ids.clear();
  this->QPlainTextEdit::scrollContentsBy(dx, dy);
}

void CodeView::paintEvent(QPaintEvent *event) {
  QString message;
  switch (d->state) {
    case CodeViewState::kInitialized:
      message = tr("Preparing to download...");
      break;
    case CodeViewState::kDownloading:
      message = tr("Downloading...");
      break;
    case CodeViewState::kRendering:
      message = tr("Rendering...");
      break;
    case CodeViewState::kRendered:
      this->QPlainTextEdit::paintEvent(event);
      return;
    case CodeViewState::kFailed:
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

  QPainter painter(viewport());
  painter.fillRect(event_rec, d->theme.BackgroundColor());

  painter.setFont(message_font);
  painter.setPen(QPen(palette().color(QPalette::WindowText)));
  painter.drawText(message_rect, kTextFlags, message);
  painter.end();

  event->accept();
}

}  // namespace mx::gui
