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
#include <QPainter>
#include <QRect>
#include <QRectF>
#include <QSortFilterProxyModel>
#include <QStyle>
#include <QVector>

#include <multiplier/Index.h>
#include <multiplier/Re2.h>
#include <variant>
#include <vector>

#include "Code.h"
#include "CodeTheme.h"
#include "Multiplier.h"
#include "Util.h"

namespace mx::gui {

enum class ModelMode {
  kNoData,
  kRegex,
  kWeggli
};

struct Result {
  const TokenRange file_tokens;
  const Fragment frag;

  // A mix of fragment tokens and file tokens. Ideally, we want as many fragment
  // tokens as possible.
  unsigned tokens_begin{1u};
  unsigned tokens_end{0u};

  const std::string_view token_data;
  std::vector<std::string_view> captures;

  explicit Result(const RegexQueryMatch &);

  std::pair<unsigned, unsigned> Tokens(CodeSearchResultsModelImpl &d);
};

class CodeSearchResultsModelImpl {
 public:
  Multiplier &multiplier;
  const CodeTheme &theme;
  const QFont font;
  const QFontMetricsF font_metrics;
  const QColor bg_color_even;
  const QColor bg_color_odd;

  std::vector<Decl> related_decls;

  // Formatted tokens from the results. Also used by `CodeView`.
  Code code;

  int num_columns{0};
  int num_rows{0};

  std::vector<std::variant<Token, TokenSubstitution>> toks;

  QVector<QString> headers;
  std::vector<Result> rows;

  ModelMode mode{ModelMode::kNoData};

  inline CodeSearchResultsModelImpl(Multiplier &multiplier_)
      : multiplier(multiplier_),
        theme(multiplier.CodeTheme()),
        font(theme.Font()),
        font_metrics(font),
        bg_color_even(theme.BackgroundColor()),
        bg_color_odd(bg_color_even.lighter()) {}
};

// Try to recover the details to render the tokens. This goes and accumulates
// stuff into `d.code`, which is the same backing datastructure used by
// `CodeView`. This approach mostly just lets us keep data in a small number of
// giant linear containers, rather than a large number of small-to-medium sized
// linear containers.
std::pair<unsigned, unsigned> Result::Tokens(CodeSearchResultsModelImpl &d) {
  if (tokens_end >= tokens_begin) {
    return {tokens_begin, tokens_end};
  }

  auto j = 0u;

  // We'll end up pushing on the same values all over, so don't keep the
  // redundancy.
  if (!d.code.start_of_token.empty()) {
    d.code.start_of_token.pop_back();
    d.code.tok_decl_ids_begin.pop_back();
  }

  tokens_begin = static_cast<unsigned>(d.code.start_of_token.size());

  TokenList frag_tokens = frag.parsed_tokens();
  auto max_j = frag_tokens.size();

  for (Token file_tok : file_tokens) {
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

  tokens_end = static_cast<unsigned>(d.code.start_of_token.size());
  d.code.start_of_token.push_back(d.code.data.size());
  d.code.tok_decl_ids_begin.push_back(d.code.tok_decl_ids.size());

  return {tokens_begin, tokens_end};
}

Result::Result(const RegexQueryMatch &match)
    : file_tokens(match),
      frag(Fragment::containing(match)),
      token_data(match.data()),
      captures(match.num_captures()) {

  for (size_t i = 0u, max_i = captures.size(); i < max_i; ++i) {
    if (auto capture = match.captured_data(i)) {
      captures[i] = capture.value();
    }
  }
}

struct CodeSearchResultsView::PrivateData {
  CodeSearchResultsModel * const model;

  inline PrivateData(CodeSearchResultsModel *model_)
      : model(model_) {}
};

CodeSearchResultsItemDelegate::~CodeSearchResultsItemDelegate(void) {}

CodeSearchResultsItemDelegate::CodeSearchResultsItemDelegate(
      CodeSearchResultsModel *model_,
      SortableCodeSearchResultsModel *proxy_,
      QObject *parent_)
    : QStyledItemDelegate(parent_),
      model(model_),
      proxy(proxy_) {}

void CodeSearchResultsItemDelegate::paint(
    QPainter *painter, const QStyleOptionViewItem &option,
    const QModelIndex &index) const {

  auto row = index.row();
  auto col = index.column();

  if (proxy) {
    auto real_index = proxy->mapToSource(index);
    row = real_index.row();
    col = real_index.column();
  }

  auto d = model->d.get();
  if (0 > row || 0 > col || row >= d->num_rows || col >= d->num_columns) {
    return;

  // TODO(pag): Only syntax highlight column 0.
  } else if (0 < col) {
    QStyledItemDelegate::paint(painter, option, index);
    return;
  }

  auto &result = d->rows[static_cast<size_t>(row)];

  if (option.state & QStyle::State_Selected) {

  } else {

  }

  QStyleOptionViewItem opt = option;
  QStyledItemDelegate::initStyleOption(&opt, index);
  QStyle *style = opt.widget ? opt.widget->style() : QApplication::style();
  QRectF rect = style->subElementRect(QStyle::SE_ItemViewItemText, &opt);
  QPointF pos = rect.topLeft();

  painter->save();
  painter->resetTransform();
  painter->translate(rect.topLeft());
  painter->setRenderHint(QPainter::Antialiasing, true);

  // Try to get the background color from the model; we want to get the right
  // alternating color, if any.
  QVariant bg_color;
  if (proxy) {
    bg_color = proxy->data(index, Qt::BackgroundColorRole);
  } else {
    bg_color = model->data(index, Qt::BackgroundColorRole);
  }

  auto has_bg = false;
  if (bg_color.userType() == QMetaType::QColor) {
    painter->setBackground(qvariant_cast<QColor>(bg_color));
    has_bg = true;
  }

  auto [begin_index, end_index] = result.Tokens(*d);
  for (unsigned i = begin_index; i < end_index; ++i) {

    if (!has_bg) {
      painter->setBackground(*(d->code.background[i]));
    }

    painter->setPen(d->code.foreground[i]->color());

    QFont font = d->font;
    font.setItalic(d->code.italic[i]);
    font.setUnderline(d->code.underline[i]);
    font.setWeight(d->code.bold[i] ? QFont::DemiBold : QFont::Normal);
    painter->setFont(font);

    auto j = d->code.start_of_token[i];
    auto max_j = d->code.start_of_token[i + 1u];

    for (; j < max_j; ++j) {
      switch (QChar ch = d->code.data[j]; ch.unicode()) {
        case QChar::Tabulation:
        case QChar::Space:
        case QChar::Nbsp:
          pos.setX(pos.x() + d->font_metrics.width(ch));
          break;
        case QChar::ParagraphSeparator:
        case QChar::LineFeed:
        case QChar::LineSeparator:
          pos.setX(option.rect.x());
          pos.setY(pos.y() + d->font_metrics.height());
          break;
        case QChar::CarriageReturn:
          continue;
        default: {
          qreal width = d->font_metrics.width(ch);
          QRectF glyph_rect(0.0, 0.0, width, d->font_metrics.height());
          glyph_rect.moveTo(pos);
          painter->drawText(glyph_rect, option.displayAlignment, ch);
          pos.setX(pos.x() + width);
          break;
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
    case Qt::BackgroundColorRole:
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
//  result.FillTokens();

  auto view = result.captures[static_cast<unsigned>(col)];
  return QString::fromUtf8(view.data(), static_cast<int>(view.size()));
}

// Overload the implementation of alternating background colors.
QVariant SortableCodeSearchResultsModel::data(
    const QModelIndex &index, int role) const {
  if (role == Qt::BackgroundColorRole) {
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
    d->headers.push_back(QString::number(i));
  }

  for (const std::string &var : match.captured_variables()) {
    if (auto index = match.index_of_captured_variable(var)) {
      d->headers[static_cast<int>(*index)] = QString::fromStdString(var);
    }
  }

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
  d->rows.emplace_back(match);
  ++d->num_rows;
  endInsertRows();

  emit AddedRows();
}

SortableCodeSearchResultsModel::~SortableCodeSearchResultsModel(void) {}

CodeSearchResultsView::~CodeSearchResultsView(void) {}

CodeSearchResultsView::CodeSearchResultsView(CodeSearchResultsModel *model_,
                                             QWidget *parent_)
    : QTableView(parent_),
      d(std::make_unique<PrivateData>(model_)) {
  InitializeWidgets();
}

int CodeSearchResultsView::columnCount(void) const {
  return d->model->columnCount(QModelIndex());
}

int CodeSearchResultsView::rowCount(void) const {
  return d->model->rowCount(QModelIndex());
}

void CodeSearchResultsView::OnRowsAdded(void) {
  resizeColumnsToContents();
  resizeRowsToContents();
}

void CodeSearchResultsView::InitializeWidgets(void) {

  // Make a proxy model for sorting, and an item delegate for painting syntax-
  // colored text.
  auto proxy_model = new SortableCodeSearchResultsModel;
  setItemDelegate(new CodeSearchResultsItemDelegate(d->model, proxy_model));
  proxy_model->setSourceModel(d->model);
  setModel(proxy_model);
  connect(d->model, &CodeSearchResultsModel::AddedRows,
          this, &CodeSearchResultsView::OnRowsAdded);

  // Allow sorting; this works in conjunction with the proxy model. Without
  // the proxy model, if we used sorting, then it would do nothing :-/
  setSortingEnabled(true);

  // Only allow one cell to be selected at a time.
  setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
  setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
  setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

  // Magic from StackOverflow to enable multi-line cells that also auto add
  // `...` when the cell isn't wide enough.
  setWordWrap(true);
  setTextElideMode(Qt::ElideMiddle);
  verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

  // Resize for the current contents as they are now. This has an
  // "isntantaneous" and isn't a persistent setting, so any time we add more
  // stuff, we need to call these again.
  resizeColumnsToContents();
  resizeRowsToContents();

  // When scrolling, scroll by pixel. Vertically this doesn't matter too much,
  // unless a result is really large. Horizontally, scrolling by item means
  // jumping to show the next cell, and that ends up being very jarring.
  setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
  setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

  // When the viewport is looking partially at an item, and you click on the
  // item, then DON'T automatically scroll to left-adjust the item to the
  // viewport.
  setAutoScroll(false);
}

}  // namespace mx::gui
