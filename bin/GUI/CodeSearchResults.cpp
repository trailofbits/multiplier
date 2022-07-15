// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "CodeSearchResults.h"

#include <QApplication>
#include <QColor>
#include <QFont>
#include <QFontMetricsF>
#include <QHeaderView>
#include <QList>
#include <QModelIndex>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>
#include <QRectF>
#include <QSortFilterProxyModel>
#include <QSplitter>
#include <QStyle>
#include <QTableView>
#include <QThreadPool>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

#include <cassert>
#include <multiplier/Index.h>
#include <multiplier/Re2.h>
#include <multiplier/Weggli.h>
#include <variant>
#include <vector>

#include "Code.h"
#include "CodeTheme.h"
#include "CodeView.h"
#include "Configuration.h"
#include "Multiplier.h"
#include "Util.h"

#include <iostream>

namespace mx::gui {

enum class ModelMode {
  kNoData,
  kRegex,
  kWeggli
};

struct RowData {

  // Indexes into `CodeSearchResultsModelImpl::files` and
  // `CodeSearchResultsModelImpl::fragments`.
  const unsigned file_index;
  const unsigned frag_index;

  unsigned file_tokens_begin{0u};
  unsigned file_tokens_end{0u};

  // Indexes into tokens inside of `CodeSearchResultsModelImpl::code`.
  unsigned code_tokens_begin{1u};
  unsigned code_tokens_end{0u};

  explicit RowData(CodeSearchResultsModelImpl &d,
                   const RegexQueryMatch &, unsigned file_index_,
                   unsigned frag_index_);

  explicit RowData(CodeSearchResultsModelImpl &d,
                   const WeggliQueryMatch &, unsigned file_index_,
                   unsigned frag_index_);

  std::pair<unsigned, unsigned> Tokens(CodeSearchResultsModelImpl &d);
};

class CodeSearchResultsModelImpl {
 public:
  Multiplier &multiplier;
  const CodeTheme &theme;
  const QFont font;
  const QColor bg_color_even;
  const QColor bg_color_odd;

  std::vector<Decl> related_decls;
  std::vector<uint8_t> capture_indexes;
  int last_capture_indexes_row{-1};

  // Formatted tokens from the results. Also used by `CodeView`.
  Code code;

  int num_columns{0};
  int num_rows{0};

  std::vector<std::variant<Token, TokenSubstitution>> toks;

  QVector<QString> headers;
  std::vector<RowData> rows;
  std::vector<QSize> sizes;

  // These are per-row things.

  std::vector<std::string_view> captured_data;

  // `(offset, len)` for utf-16 characters of the sub-ranges of covered token
  // data within the entire range of matched token data.
  std::vector<std::pair<int, int>> token_sub_ranges;

  // `(offset, len)` for utf-16 characters of the sub-ranges of covered data
  // within the entire range of matched data, which is often a subsequence of
  // token data.
  std::vector<std::pair<int, int>> capture_sub_ranges;

  std::vector<File> files;
  std::unordered_map<RawEntityId, unsigned> file_indexes;

  std::vector<Fragment> fragments;
  std::unordered_map<RawEntityId, unsigned> fragment_indexes;

  ModelMode mode{ModelMode::kNoData};

  inline CodeSearchResultsModelImpl(Multiplier &multiplier_)
      : multiplier(multiplier_),
        theme(multiplier.CodeTheme()),
        font(theme.Font()),
        bg_color_even(theme.BackgroundColor()),
        bg_color_odd(bg_color_even.lighter()) {}
};

// Try to recover the details to render the tokens. This goes and accumulates
// stuff into `d.code`, which is the same backing datastructure used by
// `CodeView`. This approach mostly just lets us keep data in a small number of
// giant linear containers, rather than a large number of small-to-medium sized
// linear containers.
std::pair<unsigned, unsigned> RowData::Tokens(CodeSearchResultsModelImpl &d) {
  if (code_tokens_end >= code_tokens_begin) {
    return {code_tokens_begin, code_tokens_end};
  }

  auto j = 0u;

  // We'll end up pushing on the same values all over, so don't keep the
  // redundancy.
  if (!d.code.start_of_token.empty()) {
    d.code.start_of_token.pop_back();
    d.code.tok_decl_ids_begin.pop_back();
  }

  code_tokens_begin = static_cast<unsigned>(d.code.start_of_token.size());

  TokenList file_tokens = d.files[file_index].tokens();
  TokenList frag_tokens = d.fragments[frag_index].parsed_tokens();
  auto max_j = frag_tokens.size();

  for (auto i = file_tokens_begin; i < file_tokens_end; ++i) {
    const Token file_tok = file_tokens[i];
    auto tok_data = file_tok.data();
    if (tok_data.empty()) {
      continue;
    }

    FileTokenId file_tok_id =
        std::get<FileTokenId>(EntityId(file_tok.id()).Unpack());

    d.code.start_of_token.push_back(d.code.data.size());
    d.code.data += QString::fromUtf8(
        tok_data.data(), static_cast<int>(tok_data.size()));
    d.code.file_token_ids.push_back(file_tok.id());
    d.code.tok_decl_ids_begin.push_back(d.code.tok_decl_ids.size());

    d.related_decls.clear();
    DeclCategory decl_category = DeclCategory::UNKNOWN;
    TokenCategory tok_category = CategorizeToken(file_tok, decl_category);
    for (; j < max_j; ) {
      Token frag_tok = frag_tokens[j];
      if (frag_tok.data().empty()) {
        if (frag_tok.kind() != TokenKind::BEGIN_OF_MACRO_EXPANSION_MARKER) {
          ++j;
          continue;
        }
      }

      std::optional<Token> file_for_frag_tok = frag_tok.file_token();
      if (!file_for_frag_tok) {
        ++j;
        continue;
      }

      FileTokenId file_for_frag_tok_id =
          std::get<FileTokenId>(EntityId(file_for_frag_tok->id()).Unpack());

      d.related_decls.clear();

      // This can happen if there was an `#include` expansion nested inside
      // of something else.
      if (file_for_frag_tok_id.file_id != file_tok_id.file_id) {
        ++j;
        continue;

      // Not far enough along yet.
      } else if (file_for_frag_tok_id.offset < file_tok_id.offset) {
        ++j;
        continue;

      // Went too far ahead.
      } else if (file_for_frag_tok_id.offset > file_tok_id.offset) {
        break;

      // Matched.
      } else {
        assert(file_for_frag_tok_id.offset == file_tok_id.offset);

        RawEntityId decl_id = kInvalidEntityId;
        if (auto related_decl = DeclForToken(frag_tok)) {
          decl_id = related_decl->id();
          decl_category = related_decl->category();
          d.related_decls.emplace_back(std::move(related_decl.value()));
        }

        tok_category = CategorizeToken(frag_tok, decl_category);
        d.code.tok_decl_ids.emplace_back(frag_tok.id(), decl_id);
        ++j;
        break;
      }
    }

    TokenFormat format = d.theme.Format(file_tok, d.related_decls, tok_category);
    d.code.background.push_back(
        &(d.theme.TokenBackgroundColor(file_tok, d.related_decls, tok_category)));
    d.code.foreground.push_back(
        &(d.theme.TokenForegroundColor(file_tok, d.related_decls, tok_category)));
    d.code.bold.push_back(format.bold);
    d.code.italic.push_back(format.italic);
    d.code.underline.push_back(format.underline);
  }

  code_tokens_end = static_cast<unsigned>(d.code.start_of_token.size());
  d.code.start_of_token.push_back(d.code.data.size());
  d.code.tok_decl_ids_begin.push_back(d.code.tok_decl_ids.size());

  return {code_tokens_begin, code_tokens_end};
}

RowData::RowData(CodeSearchResultsModelImpl &d,
                 const RegexQueryMatch &match, unsigned file_index_,
                 unsigned frag_index_)
    : file_index(file_index_),
      frag_index(frag_index_) {

  VariantId first_vid = EntityId(match.front().id()).Unpack();
  VariantId last_vid = EntityId(match.back().id()).Unpack();

  assert(std::holds_alternative<FileTokenId>(first_vid));
  assert(std::holds_alternative<FileTokenId>(last_vid));

  file_tokens_begin = std::get<FileTokenId>(first_vid).offset;
  file_tokens_end = std::get<FileTokenId>(last_vid).offset + 1u;

  const char *begin_utf8 = match.TokenRange::data().data();
  for (size_t i = 0u, max_i = match.num_captures(); i < max_i; ++i) {

    auto &capture_sub_range = d.capture_sub_ranges.emplace_back(0, 0);
    auto &token_sub_range = d.token_sub_ranges.emplace_back(0, 0);
    auto &captured_data = d.captured_data.emplace_back();

    auto capture = match.captured_data(i);
    if (!capture) {
      continue;
    }

    captured_data = capture.value();

    const ptrdiff_t len_utf8 = captured_data.data() - begin_utf8;
    assert(0 <= len_utf8);

    capture_sub_range.first =
        QString::fromUtf8(begin_utf8, static_cast<int>(len_utf8)).size();

    capture_sub_range.second =
        QString::fromUtf8(capture->data(),
                          static_cast<int>(capture->size())).size();

    if (auto captured_tokens = match.captured_tokens(i)) {
      const std::string_view tok_data = captured_tokens->data();
      const ptrdiff_t tok_len_utf8 = tok_data.data() - begin_utf8;

      token_sub_range.first =
          QString::fromUtf8(begin_utf8, static_cast<int>(tok_len_utf8)).size();

      token_sub_range.second =
          QString::fromUtf8(tok_data.data(),
                            static_cast<int>(tok_data.size())).size();

    } else if (!capture->empty()) {
      assert(false);
      token_sub_range.first = capture_sub_range.first;
      token_sub_range.second = capture_sub_range.second;
    }
  }
}

RowData::RowData(CodeSearchResultsModelImpl &d,
                 const WeggliQueryMatch &match, unsigned file_index_,
                 unsigned frag_index_)
    : file_index(file_index_),
      frag_index(frag_index_) {

  VariantId first_vid = EntityId(match.front().id()).Unpack();
  VariantId last_vid = EntityId(match.back().id()).Unpack();

  assert(std::holds_alternative<FileTokenId>(first_vid));
  assert(std::holds_alternative<FileTokenId>(last_vid));

  file_tokens_begin = std::get<FileTokenId>(first_vid).offset;
  file_tokens_end = std::get<FileTokenId>(last_vid).offset + 1u;

  const char *begin_utf8 = match.TokenRange::data().data();
  for (size_t i = 0u, max_i = match.num_captures(); i < max_i; ++i) {

    auto &capture_sub_range = d.capture_sub_ranges.emplace_back(0, 0);
    auto &token_sub_range = d.token_sub_ranges.emplace_back(0, 0);
    auto &captured_data = d.captured_data.emplace_back();

    auto capture = match.captured_data(i);
    if (!capture) {
      continue;
    }

    captured_data = capture.value();

    const ptrdiff_t len_utf8 = captured_data.data() - begin_utf8;
    assert(0 <= len_utf8);

    capture_sub_range.first =
        QString::fromUtf8(begin_utf8, static_cast<int>(len_utf8)).size();

    capture_sub_range.second =
        QString::fromUtf8(capture->data(),
                          static_cast<int>(capture->size())).size();

    if (auto captured_tokens = match.captured_tokens(i)) {
      const std::string_view tok_data = captured_tokens->data();
      const ptrdiff_t tok_len_utf8 = tok_data.data() - begin_utf8;

      token_sub_range.first =
          QString::fromUtf8(begin_utf8, static_cast<int>(tok_len_utf8)).size();

      token_sub_range.second =
          QString::fromUtf8(tok_data.data(),
                            static_cast<int>(tok_data.size())).size();

    } else if (!capture->empty()) {
      assert(false);
      token_sub_range.first = capture_sub_range.first;
      token_sub_range.second = capture_sub_range.second;
    }
  }
}

CodeSearchResultsItemDelegate::~CodeSearchResultsItemDelegate(void) {}

CodeSearchResultsItemDelegate::CodeSearchResultsItemDelegate(
      CodeSearchResultsModel *model_,
      SortableCodeSearchResultsModel *proxy_,
      QObject *parent_)
    : QStyledItemDelegate(parent_),
      model(model_),
      proxy(proxy_) {}

QSize CodeSearchResultsItemDelegate::sizeHint(
    const QStyleOptionViewItem &option,
    const QModelIndex &index) const {

  CodeSearchResultsModelImpl * const d = model->d.get();
  const QModelIndex real_index = proxy->mapToSource(index);
  const int row = real_index.row();
  const int col = real_index.column();
  if (0 > row || 0 > col || row >= d->num_rows ||
      col >= d->num_columns) {
    return QStyledItemDelegate::sizeHint(option, index);
  }

  size_t size_index = static_cast<size_t>((row * d->num_columns) + col);
  if (d->sizes.size() <= size_index) {
    d->sizes.resize(size_index + 1u);
  }

  QSize &size = d->sizes[size_index];
  if (!size.isEmpty()) {
    return size;
  }

  // The begin/end indices of tokens in `CodeSearchResultsModelImpl::code`
  // for all the matched tokens.
  RowData &result = d->rows[static_cast<size_t>(row)];
  auto [begin_index, end_index] = result.Tokens(*d);
  auto capture_offset = row * d->num_columns;
  auto capture_index = static_cast<unsigned>(col);
  auto [num_chars_to_skip, num_chars_to_print] =
      d->token_sub_ranges[static_cast<unsigned>(capture_offset + col)];

  QFont font = d->font;
  QFontMetricsF font_metrics(font);
  CodeSearchResultsConfiguration &config =
      d->multiplier.Configuration().code_search_results;

  qreal curr_width = 0;
  qreal width = 0;
  qreal num_lines = 1;

  int num_skipped_chars = 0;
  int num_printed_chars = 0;
  auto c = 0u;
  for (unsigned i = begin_index; i < end_index; ++i) {

    // Recalculate font metrics; bold/italic might take more or less space.
    if (config.highlight_syntax) {
      font.setItalic(d->code.italic[i]);
      font.setUnderline(d->code.underline[i]);
      font.setWeight(d->code.bold[i] ? QFont::DemiBold : QFont::Normal);
      font_metrics = QFontMetricsF(font);
    }

    auto j = d->code.start_of_token[i];
    const auto max_j = d->code.start_of_token[i + 1u];

    for (; j < max_j && num_printed_chars < num_chars_to_print; ++j, ++c) {

      // If we're in the Nth column, then we only want to show the tokens
      // and matched data for the Nth capture group, but all of our info
      // relating printed characters to capture indices is based on the entire
      // match, so we might need to skip open some stuff.
      if (num_skipped_chars++ < num_chars_to_skip) {
        continue;
      }

      // If we're not in skipping mode, then we need to count how many
      // characters have been rendered, because if we're in the Nth column,
      // then we will want to limit ourselves to rendering just the token
      // data associated with the Nth capture group.
      ++num_printed_chars;

      const QChar ch = d->code.data[j];
      switch (ch.unicode()) {
        case QChar::Tabulation:
        case QChar::Space:
        case QChar::Nbsp:
        default:
          curr_width += font_metrics.horizontalAdvance(ch);
          width = std::max(curr_width, width);
          break;
        case QChar::ParagraphSeparator:
        case QChar::LineFeed:
        case QChar::LineSeparator:
          num_lines++;
          curr_width = 0;
          break;
        case QChar::CarriageReturn:
          continue;
      }
    }
  }

  QStyleOptionViewItem opt = option;
  initStyleOption(&opt, index);
  QSize contents_size = QSizeF(width, font_metrics.height() * num_lines).toSize();
  QStyle *style = opt.widget ? opt.widget->style() : qApp->style();
  size = style->sizeFromContents(QStyle::ContentsType::CT_ItemViewItem,
                                 &opt, contents_size, opt.widget);

//  size.setWidth(size.width() + contents_size.width());
//  size.setHeight(contents_size.height());
  return size;
}

void CodeSearchResultsItemDelegate::paint(
    QPainter *painter, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {

  CodeSearchResultsModelImpl * const d = model->d.get();
  const QModelIndex real_index = proxy->mapToSource(index);
  const int row = real_index.row();
  const int col = real_index.column();

  if (0 > row || 0 > col || row >= d->num_rows || col >= d->num_columns) {
    QStyledItemDelegate::paint(painter, option, index);
    return;
  }

  CodeSearchResultsConfiguration &config =
      d->multiplier.Configuration().code_search_results;

  RowData &result = d->rows[static_cast<size_t>(row)];

  // Try to get the background color from the model; we want to get the right
  // alternating color, if any.
  QVariant bg_color;
  unsigned disp = 1u;
  if (option.state & QStyle::State_Selected) {
    bg_color = d->theme.SelectedLineBackgroundColor();
    disp = 0u;
  } else {
    if (proxy) {
      bg_color = proxy->data(index, Qt::BackgroundRole);
    } else {
      bg_color = model->data(index, Qt::BackgroundRole);
    }
  }

  painter->save();

  // Fill the background color of the cell. `setBackground` doesn't really
  // do this.
  auto has_bg = false;
  if (bg_color.userType() == QMetaType::QColor) {
    QColor color = qvariant_cast<QColor>(bg_color);
    painter->fillRect(option.rect, color);
    has_bg = true;
  }

  auto capture_offset = row * d->num_columns;
  auto capture_index = static_cast<unsigned>(col);

  // Figure out to which capture group a character belongs. Try to not have to
  // recompute this.
  //
  // Note that the tokens enclose the capture, including the first capture.
  if (config.highlight_captures) {
    if (d->capture_indexes.empty() ||
        d->last_capture_indexes_row != row) {
      uint8_t c = 1;
      d->capture_indexes.clear();
      d->last_capture_indexes_row = row;
      for (auto i = 0; i < d->num_columns; ++i) {
        auto [num_chars_to_skip, num_chars_to_print] =
            d->token_sub_ranges[static_cast<unsigned>(capture_offset + i)];
        auto [prefix_len, capture_len] =
            d->capture_sub_ranges[static_cast<unsigned>(capture_offset + i)];

        auto needed = static_cast<size_t>(prefix_len + capture_len);
        needed = std::max<size_t>(
            needed, static_cast<unsigned>(num_chars_to_print));
        d->capture_indexes.resize(
            std::max<size_t>(needed + 1u, d->capture_indexes.size()));
        for (int k = 0; k < capture_len; ++k) {
          d->capture_indexes[static_cast<unsigned>(prefix_len + k)] = c;
        }
        ++c;
      }
    }
  }

  if (config.highlight_syntax) {
    painter->setRenderHint(QPainter::Antialiasing, true);
  }

  if (!config.highlight_syntax && !config.highlight_captures) {
    QStyledItemDelegate::paint(painter, option, index);

  } else {
    QFont font = d->font;
    QFontMetricsF font_metrics(font);
    QPointF pos = option.rect.topLeft();

    // The begin/end indices of tokens in `CodeSearchResultsModelImpl::code`
    // for all the matched tokens.
    auto [begin_index, end_index] = result.Tokens(*d);

    auto [num_chars_to_skip, num_chars_to_print] =
        d->token_sub_ranges[static_cast<unsigned>(capture_offset + col)];

    int num_skipped_chars = 0;
    int num_printed_chars = 0;
    auto c = 0u;
    for (unsigned i = begin_index; i < end_index; ++i) {

      // Recalculate font metrics; bold/italic might take more or less space.
      if (config.highlight_syntax) {
        painter->setPen(d->code.foreground[i]->color());
        font.setItalic(d->code.italic[i]);
        font.setUnderline(d->code.underline[i]);
        font.setWeight(d->code.bold[i] ? QFont::DemiBold : QFont::Normal);
        font_metrics = QFontMetricsF(font);
      }

      painter->setFont(font);

      auto j = d->code.start_of_token[i];
      const auto max_j = d->code.start_of_token[i + 1u];

      for (; j < max_j && num_printed_chars < num_chars_to_print; ++j, ++c) {

        // If we're in the Nth column, then we only want to show the tokens
        // and matched data for the Nth capture group, but all of our info
        // relating printed characters to capture indices is based on the entire
        // match, so we might need to skip open some stuff.
        if (num_skipped_chars++ < num_chars_to_skip) {
          continue;
        }

        // If we're not in skipping mode, then we need to count how many
        // characters have been rendered, because if we're in the Nth column,
        // then we will want to limit ourselves to rendering just the token
        // data associated with the Nth capture group.
        ++num_printed_chars;

        const QChar ch = d->code.data[j];
        QRectF glyph_rect(0.0, 0.0, font_metrics.horizontalAdvance(ch),
                          font_metrics.height());
        glyph_rect.moveTo(pos);

        // Optionally fill behind the character-to-be-printed with the highlight
        // color for this capture group.
        if (config.highlight_captures) {
          const int sel_index = d->capture_indexes[c];
          if (!sel_index) {
            if (!has_bg) {
              assert(i < d->code.background.size());
              painter->fillRect(glyph_rect, *(d->code.background[i]));
            }
          } else {
            assert(0 < sel_index);
            assert(sel_index <= d->num_columns);
            painter->fillRect(
                glyph_rect, d->theme.SelectedLineBackgroundColor(
                    static_cast<unsigned>(sel_index)));
          }
        }

        switch (ch.unicode()) {
          case QChar::Tabulation:
          case QChar::Space:
          case QChar::Nbsp:
            pos.setX(glyph_rect.right());
            break;
          case QChar::ParagraphSeparator:
          case QChar::LineFeed:
          case QChar::LineSeparator:
            pos.setX(option.rect.x());
            pos.setY(glyph_rect.bottom());
            break;
          case QChar::CarriageReturn:
            continue;
          default: {
            painter->drawText(glyph_rect, option.displayAlignment, ch);
            pos.setX(glyph_rect.right());
            break;
          }
        }
      }
    }
  }

  painter->restore();
}

CodeSearchResultsModel::~CodeSearchResultsModel(void) {}

CodeSearchResultsModel::CodeSearchResultsModel(Multiplier &multiplier_,
                                               QObject *parent_)
    : QAbstractTableModel(parent_),
      d(std::make_unique<CodeSearchResultsModelImpl>(multiplier_)) {}

int CodeSearchResultsModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return d->num_columns;
}

int CodeSearchResultsModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return d->num_rows;
}

QVariant CodeSearchResultsModel::headerData(
    int section, Qt::Orientation orientation, int role) const {
  if (orientation != Qt::Orientation::Horizontal) {
    return {};
  } else if (role != Qt::DisplayRole) {
    return {};
  } else if (0 > section || section >= d->headers.size()) {
    return {};
  } else {
    return d->headers[section];
  }
}

QVariant CodeSearchResultsModel::data(
    const QModelIndex &index, int role) const {
  switch (role) {
    case Qt::BackgroundRole:
      if (index.row() % 2) {
        return d->bg_color_odd;
      } else {
        return d->bg_color_even;
      }
    case Qt::FontRole:
      return d->font;
    default:
      return {};
    case Qt::DisplayRole:
      break;
  }

  auto row = index.row();
  auto col = index.column();
  if (0 > row || row >= d->num_rows ||
      0 > col || col >= d->num_columns) {
    return {};
  }

  auto &result = d->rows[static_cast<unsigned>(row)];
  auto view = d->captured_data[static_cast<unsigned>(row * d->num_columns + col)];
  return QString::fromUtf8(view.data(), static_cast<int>(view.size()));
}

// Overload the implementation of alternating background colors.
QVariant SortableCodeSearchResultsModel::data(
    const QModelIndex &index, int role) const {
  if (role == Qt::BackgroundRole) {
    if (auto model = dynamic_cast<CodeSearchResultsModel *>(sourceModel())) {
      if (auto d = model->d.get()) {
        if (index.row() % 2) {
          return d->bg_color_odd;
        } else {
          return d->bg_color_even;
        }
      }
    }
  }
  return QSortFilterProxyModel::data(index, role);
}

void CodeSearchResultsModel::AddHeader(const RegexQueryMatch &match) {
  auto num_captures = match.num_captures();

  beginInsertColumns(QModelIndex(), 0, static_cast<int>(num_captures - 1));
  d->num_columns = static_cast<int>(num_captures);
  insertColumns(0, d->num_columns);

  for (auto i = 0u; i < num_captures; ++i) {
    if (!i) {
      d->headers.push_back(tr("Match"));  // The whole match.
    } else {
      d->headers.push_back(QString::number(i));
    }
  }

  for (const std::string &var : match.captured_variables()) {
    if (auto index = match.index_of_captured_variable(var)) {
      d->headers[static_cast<int>(*index)] = QString::fromStdString(var);
    }
  }

  emit headerDataChanged(Qt::Orientation::Vertical, 0, d->num_columns - 1);
  endInsertColumns();
}

void CodeSearchResultsModel::AddHeader(const WeggliQueryMatch &match) {
  auto num_captures = match.num_captures();

  beginInsertColumns(QModelIndex(), 0, static_cast<int>(num_captures - 1));
  d->num_columns = 1u;
  d->headers.push_back(tr("Match"));
  for (const std::string &var : match.captured_variables()) {
    if (!var.empty() && var[0] == '$') {
      d->headers.push_back(QString::fromStdString(var.substr(1)));
    } else {
      d->headers.push_back(QString::fromStdString(var));
    }
    ++d->num_columns;
  }
  insertColumns(0, d->num_columns);

  emit headerDataChanged(Qt::Orientation::Vertical, 0, d->num_columns - 1);
  endInsertColumns();
}

void CodeSearchResultsModel::AddResult(const RegexQueryMatch &match) {
  if (d->mode == ModelMode::kNoData) {
    d->mode = ModelMode::kRegex;
    AddHeader(match);

  } else if (d->mode != ModelMode::kRegex) {
    return;
  }

  beginInsertRows(QModelIndex(), d->num_rows, d->num_rows);

  Fragment frag = Fragment::containing(match);
  File file = File::containing(match);

  unsigned file_index;
  unsigned frag_index;

  if (auto file_index_it = d->file_indexes.find(file.id());
      file_index_it != d->file_indexes.end()) {
    file_index = file_index_it->second;
  } else {
    file_index = static_cast<unsigned>(d->files.size());
    d->file_indexes.emplace(file.id(), file_index);
    d->files.emplace_back(std::move(file));
  }

  if (auto frag_index_it = d->fragment_indexes.find(frag.id());
      frag_index_it != d->fragment_indexes.end()) {
    frag_index = frag_index_it->second;
  } else {
    frag_index = static_cast<unsigned>(d->fragments.size());
    d->fragment_indexes.emplace(frag.id(), frag_index);
    d->fragments.emplace_back(std::move(frag));
  }

  d->rows.emplace_back(*d, match, file_index, frag_index);
  ++d->num_rows;
  endInsertRows();

  emit AddedRows();
}

void CodeSearchResultsModel::AddResult(const WeggliQueryMatch &match) {
  if (d->mode == ModelMode::kNoData) {
    d->mode = ModelMode::kWeggli;
    AddHeader(match);

  } else if (d->mode != ModelMode::kWeggli) {
    return;
  }

  beginInsertRows(QModelIndex(), d->num_rows, d->num_rows);

  Fragment frag = Fragment::containing(match);
  File file = File::containing(match);

  unsigned file_index;
  unsigned frag_index;

  if (auto file_index_it = d->file_indexes.find(file.id());
      file_index_it != d->file_indexes.end()) {
    file_index = file_index_it->second;
  } else {
    file_index = static_cast<unsigned>(d->files.size());
    d->file_indexes.emplace(file.id(), file_index);
    d->files.emplace_back(std::move(file));
  }

  if (auto frag_index_it = d->fragment_indexes.find(frag.id());
      frag_index_it != d->fragment_indexes.end()) {
    frag_index = frag_index_it->second;
  } else {
    frag_index = static_cast<unsigned>(d->fragments.size());
    d->fragment_indexes.emplace(frag.id(), frag_index);
    d->fragments.emplace_back(std::move(frag));
  }

  d->rows.emplace_back(*d, match, file_index, frag_index);
  ++d->num_rows;
  endInsertRows();

  emit AddedRows();
}

SortableCodeSearchResultsModel::~SortableCodeSearchResultsModel(void) {}

struct CodeSearchResultsView::PrivateData {
  const std::unique_ptr<CodeSearchResultsModel> model;
  CodeSearchResultsModelImpl * const model_data;
  const std::unique_ptr<SortableCodeSearchResultsModel> proxy;
  const std::unique_ptr<CodeSearchResultsItemDelegate> delegate;
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
  QTableView *table{nullptr};
  CodeView *code{nullptr};
  HighlightRangeTheme theme;

  inline PrivateData(CodeSearchResultsModel *model_)
      : model(model_),
        model_data(model->d.get()),
        proxy(new SortableCodeSearchResultsModel),
        delegate(new CodeSearchResultsItemDelegate(model.get(), proxy.get())),
        theme(model_data->theme) {
    proxy->setSourceModel(model.get());
  }
};

CodeSearchResultsView::~CodeSearchResultsView(void) {}

CodeSearchResultsView::CodeSearchResultsView(CodeSearchResultsModel *model_,
                                             QWidget *parent_)
    : QWidget(parent_),
      d(std::make_unique<PrivateData>(model_)) {
  InitializeWidgets();
}

void CodeSearchResultsView::OnRowsAdded(void) {
  d->table->resizeColumnsToContents();
  d->table->resizeRowsToContents();
}

bool CodeSearchResultsView::eventFilter(QObject *watched, QEvent *event) {
  auto ret = d->model_data->multiplier.eventFilter(watched, event);
  switch (event->type()) {
    default:
      break;
    case QEvent::MouseButtonPress:
    case QEvent::NonClientAreaMouseButtonPress:
    case QEvent::GraphicsSceneMousePress: {
      auto mevent = dynamic_cast<QMouseEvent *>(event);
      QPoint last_click_loc = mevent->pos();
      QModelIndex index = d->table->indexAt(last_click_loc);
      if (index.isValid()) {
        MapClickToToken(last_click_loc, index);
      }
      break;
    }
  }

  return ret;
}

void CodeSearchResultsView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  setLayout(d->layout);

  d->splitter = new QSplitter(Qt::Orientation::Vertical);
  d->layout->addWidget(d->splitter);

  d->table = new QTableView;

  d->splitter->addWidget(d->table);

  // Make it possible to capture mouse events on the table.
  d->table->viewport()->installEventFilter(this);

  // Make a proxy model for sorting, and an item delegate for painting syntax-
  // colored text.
  d->table->setItemDelegate(d->delegate.get());
  d->table->setModel(d->proxy.get());

  // Allow sorting; this works in conjunction with the proxy model. Without
  // the proxy model, if we used sorting, then it would do nothing :-/
  d->table->setSortingEnabled(true);

  // Only allow one cell to be selected at a time.
  d->table->setSelectionBehavior(
      QAbstractItemView::SelectionBehavior::SelectItems);
  d->table->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
  d->table->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

  // Magic from StackOverflow to enable multi-line cells that also auto add
  // `...` when the cell isn't wide enough. This only really works when the
  // cells contain text. When we render syntax-highlighted code, this has
  // no effect.
  auto &config = d->model_data->multiplier.Configuration().code_search_results;
  d->table->setWordWrap(true);
  d->table->setTextElideMode(Qt::ElideMiddle);
//  d->table->horizontalHeader()->setStretchLastSection(true);
//  d->table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

  // Resize for the current contents as they are now. This has an
  // "isntantaneous" and isn't a persistent setting, so any time we add more
  // stuff, we need to call these again.
  d->table->resizeColumnsToContents();
  d->table->resizeRowsToContents();

  // When scrolling, scroll by pixel. Vertically this doesn't matter too much,
  // unless a result is really large. Horizontally, scrolling by item means
  // jumping to show the next cell, and that ends up being very jarring.
  d->table->setVerticalScrollMode(
      QAbstractItemView::ScrollMode::ScrollPerPixel);
  d->table->setHorizontalScrollMode(
      QAbstractItemView::ScrollMode::ScrollPerPixel);

  // When the viewport is looking partially at an item, and you click on the
  // item, then DON'T automatically scroll to left-adjust the item to the
  // viewport.
  d->table->setAutoScroll(false);

  // Create and connect the code preview.
  if (config.code_preview.visible) {
    d->code = new CodeView(
        d->theme, d->model_data->multiplier.FileLocationCache());
    d->code->viewport()->installEventFilter(&(d->model_data->multiplier));
    d->splitter->addWidget(d->code);
    d->code->hide();

    connect(d->code, &CodeView::TokenPressEvent,
            this, &CodeSearchResultsView::ActOnTokenPressEvent);
  }

  connect(d->model.get(), &CodeSearchResultsModel::AddedRows,
          this, &CodeSearchResultsView::OnRowsAdded);

  connect(d->table->selectionModel(), &QItemSelectionModel::currentChanged,
          this, &CodeSearchResultsView::OnCurrentChanged);
}

void CodeSearchResultsView::OnCurrentChanged(const QModelIndex &index,
                                             const QModelIndex &) {
  const QModelIndex real_index = d->proxy->mapToSource(index);
  const int row = real_index.row();
  const int col = real_index.column();
  CodeSearchResultsModelImpl * const model_data = d->model_data;
  if (0 > row || 0 > col || row >= model_data->num_rows ||
      col >= model_data->num_columns) {
    return;
  }

  auto &config = d->model_data->multiplier.Configuration().code_search_results;
  if (!config.code_preview.visible || !d->code) {
    return;
  }

  const RowData &result = d->model_data->rows[row];
  const File &file = d->model_data->files[result.file_index];
  TokenRange toks = file.tokens().slice(result.file_tokens_begin,
                                        result.file_tokens_end);
  d->code->show();
  d->theme.HighlightFileTokenRange(toks);
  d->code->SetFile(file);
  d->code->ScrollToFileToken(toks.front().id());
}

void CodeSearchResultsView::ActOnTokenPressEvent(EventLocations locs) {
  for (EventLocation loc : locs) {
    emit TokenPressEvent(EventSource::kCodeSearchResultPreviewClickSource, loc);
    if (loc.UnpackDeclarationId()) {
      loc.SetFragmentTokenId(kInvalidEntityId);
      loc.SetFileTokenId(kInvalidEntityId);
      emit TokenPressEvent(EventSource::kCodeSearchResultPreviewClickDest, loc);
    }
  }
}

void CodeSearchResultsView::ShowFragmentToken(unsigned row,
                                              RawEntityId file_tok_id,
                                              RawEntityId frag_tok_id) {
  auto &config = d->model_data->multiplier.Configuration().code_search_results;
  if (!config.code_preview.visible || !d->code ||
      !!QApplication::keyboardModifiers()) {
    return;
  }

  const RowData &result = d->model_data->rows[row];
  const File &file = d->model_data->files[result.file_index];
  const Fragment &frag = d->model_data->fragments[result.frag_index];

  d->code->show();
  d->theme.HighlightFileTokenRange(
      file.tokens().slice(result.file_tokens_begin, result.file_tokens_end));
  d->code->SetFragment(frag);
  d->code->ScrollToFileToken(file_tok_id);
}

void CodeSearchResultsView::ShowFileToken(unsigned row,
                                          RawEntityId file_tok_id) {
  auto &config = d->model_data->multiplier.Configuration().code_search_results;
  if (!config.code_preview.visible || !d->code ||
      !!QApplication::keyboardModifiers()) {
    return;
  }

  const RowData &result = d->model_data->rows[row];
  const File &file = d->model_data->files[result.file_index];

  d->code->show();
  d->theme.HighlightFileTokenRange(
      file.tokens().slice(result.file_tokens_begin, result.file_tokens_end));
  d->code->SetFile(file);
  d->code->ScrollToFileToken(file_tok_id);
}

void CodeSearchResultsView::ClickedOnToken(unsigned row, unsigned index) {
  CodeSearchResultsModelImpl * const model_data = d->model_data;
  assert((index + 1u) < model_data->code.tok_decl_ids_begin.size());
  auto locs_begin_index = model_data->code.tok_decl_ids_begin[index];
  auto locs_end_index = model_data->code.tok_decl_ids_begin[index + 1u];
  EventLocation loc;
  RawEntityId file_tok_id = model_data->code.file_token_ids[index];
  assert(file_tok_id != kInvalidEntityId);
  loc.SetFileTokenId(file_tok_id);

  if (auto num_locs = locs_end_index - locs_begin_index) {
    if (num_locs == 1u) {
      auto [frag_tok_id, decl_id] = model_data->code.tok_decl_ids[locs_begin_index];
      assert(frag_tok_id != kInvalidEntityId);
      loc.SetFragmentTokenId(frag_tok_id);
      loc.SetReferencedDeclarationId(decl_id);
      emit TokenPressEvent(EventSource::kCodeSearchResult, loc);
//      ShowFragmentToken(row, file_tok_id, frag_tok_id);

    } else {
      std::vector<EventLocation> locs(num_locs);
      for (auto i = locs_begin_index; i < locs_end_index; ++i) {
        auto [frag_tok_id, decl_id] = model_data->code.tok_decl_ids[i];
        assert(frag_tok_id != kInvalidEntityId);
        loc.SetFragmentTokenId(frag_tok_id);
        loc.SetReferencedDeclarationId(decl_id);
        locs[i - locs_begin_index] = loc;
      }
      emit TokenPressEvent(EventSource::kCodeSearchResult, locs);
//      ShowFileToken(row, file_tok_id);
    }
  }
}

// This method pretends to re-render the tokens, so as to find the specific
// character containing the last clicked point.
void CodeSearchResultsView::MapClickToToken(QPoint last_click_loc,
                                            const QModelIndex &index) {
  QRect visual_rect = d->table->visualRect(index);
  if (!visual_rect.contains(last_click_loc)) {
    return;
  }

  const QModelIndex real_index = d->proxy->mapToSource(index);
  const int row = real_index.row();
  const int col = real_index.column();
  CodeSearchResultsModelImpl * const model_data = d->model_data;
  if (0 > row || 0 > col || row >= model_data->num_rows ||
      col >= model_data->num_columns) {
    return;
  }

  QPointF pos = visual_rect.topLeft();

  // The begin/end indices of tokens in `CodeSearchResultsModelImpl::code`
  // for all the matched tokens.
  RowData &result = model_data->rows[static_cast<size_t>(row)];
  auto [begin_index, end_index] = result.Tokens(*model_data);
  auto capture_offset = row * model_data->num_columns;
  auto capture_index = static_cast<unsigned>(col);
  auto [num_chars_to_skip, num_chars_to_print] =
      model_data->token_sub_ranges[static_cast<unsigned>(capture_offset + col)];

  QFont font = model_data->font;
  QFontMetricsF font_metrics(font);
  CodeSearchResultsConfiguration &config =
      model_data->multiplier.Configuration().code_search_results;

  int num_skipped_chars = 0;
  int num_printed_chars = 0;
  auto c = 0u;
  for (unsigned i = begin_index; i < end_index; ++i) {

    // Recalculate font metrics; bold/italic might take more or less space.
    if (config.highlight_syntax) {
      font.setItalic(model_data->code.italic[i]);
      font.setUnderline(model_data->code.underline[i]);
      font.setWeight(model_data->code.bold[i] ? QFont::DemiBold : QFont::Normal);
      font_metrics = QFontMetricsF(font);
    }

    auto j = model_data->code.start_of_token[i];
    const auto max_j = model_data->code.start_of_token[i + 1u];

    for (; j < max_j && num_printed_chars < num_chars_to_print; ++j, ++c) {

      // If we're in the Nth column, then we only want to show the tokens
      // and matched data for the Nth capture group, but all of our info
      // relating printed characters to capture indices is based on the entire
      // match, so we might need to skip open some stuff.
      if (num_skipped_chars++ < num_chars_to_skip) {
        continue;
      }

      // If we're not in skipping mode, then we need to count how many
      // characters have been rendered, because if we're in the Nth column,
      // then we will want to limit ourselves to rendering just the token
      // data associated with the Nth capture group.
      ++num_printed_chars;

      const QChar ch = model_data->code.data[j];
      QRectF glyph_rect(0.0, 0.0, font_metrics.horizontalAdvance(ch),
                        font_metrics.height());
      glyph_rect.moveTo(pos);

      if (glyph_rect.contains(last_click_loc)) {
        ClickedOnToken(static_cast<unsigned>(row), i);
        return;
      }

      switch (ch.unicode()) {
        case QChar::Tabulation:
        case QChar::Space:
        case QChar::Nbsp:
          pos.setX(glyph_rect.right());
          break;
        case QChar::ParagraphSeparator:
        case QChar::LineFeed:
        case QChar::LineSeparator:
          pos.setX(visual_rect.x());
          pos.setY(glyph_rect.bottom());
          break;
        case QChar::CarriageReturn:
          continue;
        default: {
          pos.setX(glyph_rect.right());
          break;
        }
      }
    }
  }
}

}  // namespace mx::gui
