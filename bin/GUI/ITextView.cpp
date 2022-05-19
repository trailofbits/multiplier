// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ITextView.h"

#include <QApplication>
#include <QFontDatabase>
#include <QHBoxLayout>
#include <QPainter>
#include <QResizeEvent>
#include <QScrollBar>
#include <QSpacerItem>
#include <QVBoxLayout>

namespace mx::gui {
namespace {

#ifdef __APPLE__
static constexpr float kFontWidthPadding = 1.0;
static constexpr float kFontHeightPadding = 1.0;
#else
static constexpr float kFontWidthPadding = 0.0;
static constexpr float kFontHeightPadding = 0.0;
#endif

const auto kNewLineGlyph{L'\u23CE'};

static QColor InvertColor(const QColor &color) {
  auto red = 1.0f - color.redF();
  auto green = 1.0f - color.greenF();
  auto blue = 1.0f - color.blueF();

  return QColor::fromRgbF(red, green, blue);
}

} // namespace

struct TokenEntity final {
  QRectF bounding_box;
  unsigned token_id;
  QString text;
};

using TokenEntityList = std::vector<TokenEntity>;
using TokenEntityRowList = std::vector<TokenEntityList>;

struct SceneRow final {
  QRectF bounding_box;
  TokenEntityList entity_list;
};

using SceneRowList = std::vector<SceneRow>;

struct ITextView::Cursor final {
  unsigned token_id;
  std::size_t offset{};
};

struct ITextView::Selection final {
  bool tracking{false};
  Cursor first_cursor;
  Cursor last_cursor;
};

using OptionalSelection = std::optional<ITextView::Selection>;

struct LineNumber final {
  QRectF bounding_box;
  QString str;
};

using LineNumberList = std::vector<LineNumber>;

struct Scene final {
  QRectF bounding_box;
  LineNumberList line_number_list;

  qreal gutter_margin{};
  SceneRowList row_list;
};

using OptionalScene = std::optional<Scene>;

struct ITextView::Context final {
  QRectF viewport;
  TextViewTheme theme;

  std::unique_ptr<QFontMetricsF> font_metrics;
  TokenEntityRowList token_index;

  OptionalScene opt_scene;
  OptionalSelection opt_selection;
  bool word_wrap{true};
  bool line_numbers{true};
  std::unordered_set<unsigned> highlighted_token_groups;
};

struct ITextView::PrivateData final {
  ITextModel::Ptr model;
  Context context;

  QScrollBar *horizontal_scrollbar{nullptr};
  QScrollBar *vertical_scrollbar{nullptr};
};

ITextView::~ITextView(void) {}

ITextView::ITextView(QWidget *parent) : QFrame(parent), d(new PrivateData) {
  setFocusPolicy(Qt::StrongFocus);

  SetTheme(GetDefaultTheme());

  d->vertical_scrollbar = new QScrollBar(Qt::Vertical);
  d->vertical_scrollbar->setSingleStep(1);
  connect(d->vertical_scrollbar, &QScrollBar::valueChanged, this,
          &ITextView::OnScrollBarValueChange);

  d->horizontal_scrollbar = new QScrollBar(Qt::Horizontal);
  d->horizontal_scrollbar->setSingleStep(1);
  connect(d->horizontal_scrollbar, &QScrollBar::valueChanged, this,
          &ITextView::OnScrollBarValueChange);

  auto vertical_layout = new QVBoxLayout();
  vertical_layout->setContentsMargins(0, 0, 0, 0);
  vertical_layout->setSpacing(0);
  vertical_layout->addSpacerItem(
      new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));

  vertical_layout->addWidget(d->horizontal_scrollbar);

  auto horizontal_layout = new QHBoxLayout();
  horizontal_layout->setContentsMargins(0, 0, 0, 0);
  horizontal_layout->setSpacing(0);
  horizontal_layout->addLayout(vertical_layout);
  horizontal_layout->addWidget(d->vertical_scrollbar);
  setLayout(horizontal_layout);

  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ITextView::SetModel(ITextModel::Ptr model) {
  d->model = model;

  connect(d->model.get(), SIGNAL(ModelReset()), this, SLOT(OnModelReset()));
  OnModelReset();
}

void ITextView::SetTheme(const TextViewTheme &theme) {
  d->context.theme = theme;
  d->context.font_metrics =
      std::make_unique<QFontMetricsF>(d->context.theme.monospaced_font, this);

  setFont(d->context.theme.monospaced_font);
  update();
}

void ITextView::SetWordWrapping(bool enabled) {
  d->context.word_wrap = enabled;
  ResetScene(d->context);
  update();
}

void ITextView::SetLineNumbers(bool enabled) {
  d->context.line_numbers = enabled;
  ResetScene(d->context);
  update();
}

bool ITextView::HasSelection() const {
  return d->context.opt_selection.has_value();
}

std::optional<QString> ITextView::GetSelection() const {
  if (!d->context.opt_selection.has_value()) {
    return std::nullopt;
  }

  auto selection = d->context.opt_selection.value();
  SanitizeSelection(selection);

  QString output;
  for (auto token_id = selection.first_cursor.token_id;
       token_id <= selection.last_cursor.token_id; ++token_id) {

    auto token = d->model->TokenData(token_id);

    if (selection.first_cursor.token_id == token_id &&
        selection.last_cursor.token_id == token_id) {
      auto length = static_cast<int>(selection.last_cursor.offset -
                                     selection.first_cursor.offset) + 1;
      output += token.mid(static_cast<int>(selection.first_cursor.offset),
                          length);

    } else if (selection.first_cursor.token_id == token_id) {
      output += token.mid(static_cast<int>(selection.first_cursor.offset));

    } else if (selection.last_cursor.token_id == token_id) {
      output +=
          token.mid(0, static_cast<int>(selection.last_cursor.offset) + 1);

    } else {
      output += token;
    }
  }

  if (output.isEmpty()) {
    return std::nullopt;
  }

  return output;
}

void ITextView::HighlightTokenGroups(
    std::unordered_set<unsigned> new_groups) {
  d->context.highlighted_token_groups = std::move(new_groups);
  update();
}

void ITextView::HighlightTokenGroup(unsigned group_id) {
  d->context.highlighted_token_groups.clear();
  if (group_id) {
    d->context.highlighted_token_groups.insert(group_id);
  }
  update();
}

void ITextView::DisableTokenGroupHighlight() {
  if (!d->context.highlighted_token_groups.empty()) {
    d->context.highlighted_token_groups.clear();
    update();
  }
}

void ITextView::resizeEvent(QResizeEvent *event) {
  auto width = static_cast<qreal>(event->size().width());
  auto height = static_cast<qreal>(event->size().height());

  ResizeViewport(d->context, QSizeF(width, height));
  UpdateScrollbars();
  ResetScene(d->context);
}

void ITextView::paintEvent(QPaintEvent *event) {
  auto &context = d->context;

  if (!context.opt_scene) {
    GenerateScene(context, *d->model.get());
    assert(context.opt_scene.has_value());
  }

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.fillRect(painter.viewport(), QBrush(context.theme.background));

  QPointF translation(-context.viewport.x(), -context.viewport.y());

  auto font_width =
      context.font_metrics->horizontalAdvance(".") + kFontWidthPadding;
  auto font_height = context.font_metrics->height() + kFontHeightPadding;

  QRectF glyph_rect(0.0, 0.0, font_width, font_height);

  auto standard_font = font();
  auto group_highlight_font = font();
  group_highlight_font.setBold(true);

  const auto &scene = context.opt_scene.value();

  for (const auto &row : scene.row_list) {
    if (!row.bounding_box.intersects(context.viewport)) {
      continue;
    }

    for (const auto &entity : row.entity_list) {
      QPointF pos(entity.bounding_box.x(), entity.bounding_box.y());
      pos += translation;

      const QString &token = entity.text;
      std::size_t character_index = 0;

      for (QChar c : token) {
        bool highlight{false};
        if (context.opt_selection.has_value()) {
          auto selection = context.opt_selection.value();
          SanitizeSelection(selection);

          if (selection.first_cursor.token_id == entity.token_id &&
              selection.last_cursor.token_id == entity.token_id) {
            highlight = character_index >= selection.first_cursor.offset &&
                        character_index <= selection.last_cursor.offset;

          } else if (selection.first_cursor.token_id == entity.token_id) {
            highlight = character_index >= selection.first_cursor.offset;

          } else if (selection.last_cursor.token_id == entity.token_id) {
            highlight = character_index <= selection.last_cursor.offset;

          } else {
            highlight = (entity.token_id > selection.first_cursor.token_id &&
                         entity.token_id < selection.last_cursor.token_id);
          }
        }

        auto token_group = d->model->TokenGroup(entity.token_id);
        bool highlighted_group =
            !!d->context.highlighted_token_groups.count(token_group);

        auto background = context.theme.background;
        if (highlighted_group) {
          // TODO: Implement a better color selection logic
          background = background.lighter(550);
        }

        auto foreground = context.theme.foreground;
        if (auto color_id = d->model->TokenColor(entity.token_id);
            color_id != kInvalidTokenColorId &&
            context.theme.color_map.count(color_id) > 0) {
          foreground = context.theme.color_map.at(color_id);
        }

        if (highlight) {
          background = InvertColor(background);
          foreground = InvertColor(foreground);
        }

        if (c == '\n') {
          if (highlight) {
            foreground = InvertColor(context.theme.foreground);
            c = kNewLineGlyph;
          } else {
            continue;
          }
        }

        glyph_rect.moveTo(pos);
        painter.fillRect(glyph_rect.adjusted(-1.0, -1.0, 0.0, 0.0),
                         QBrush(background));
        painter.setPen(QPen(foreground));

        if (highlighted_group) {
          painter.setFont(group_highlight_font);
        } else {
          painter.setFont(standard_font);
        }

        painter.drawText(glyph_rect, Qt::AlignCenter | Qt::TextSingleLine, c);
        pos.setX(pos.x() + font_width);
        ++character_index;
      }
    }
  }

  painter.setPen(QPen(context.theme.line_numbers));

  qreal lowest_line_number = std::numeric_limits<qreal>::max();
  qreal highest_line_number = std::numeric_limits<qreal>::min();

  for (const auto &line_number : scene.line_number_list) {
    if (!line_number.bounding_box.intersects(context.viewport)) {
      continue;
    }

    auto rect = line_number.bounding_box.translated(translation);
    painter.drawText(rect, Qt::AlignRight | Qt::TextSingleLine,
                     line_number.str);

    lowest_line_number = std::min(lowest_line_number, rect.y());
    highest_line_number = std::max(highest_line_number,
                                   rect.y() + glyph_rect.height());
  }

  if (!scene.line_number_list.empty() && context.line_numbers) {
    painter.drawLine(QPointF(scene.gutter_margin, lowest_line_number),
                     QPointF(scene.gutter_margin, highest_line_number));
  }
  
  UpdateScrollbars();
}

void ITextView::mousePressEvent(QMouseEvent *event) {
  QPointF mouse_position(
      static_cast<qreal>(event->x() + d->context.viewport.x()),
      static_cast<qreal>(event->y() + d->context.viewport.y()));

  auto opt_cursor = CreateCursor(d->context, mouse_position);
  if (!opt_cursor.has_value()) {
    return;
  }

  auto cursor = std::move(opt_cursor.value());

  if (event->button() == Qt::LeftButton) {
    if ((QApplication::keyboardModifiers() & Qt::ShiftModifier) != 0 &&
        d->context.opt_selection.has_value()) {

      auto &selection = d->context.opt_selection.value();
      selection.tracking = false;
      selection.last_cursor = std::move(cursor);

    } else {
      Selection selection;
      selection.tracking = true;
      selection.last_cursor = selection.first_cursor = std::move(cursor);

      d->context.opt_selection = selection;
    }

  } else {
    emit TokenClicked(event->globalPos(), event->button(), cursor.token_id);
  }

  update();
}

void ITextView::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton &&
      d->context.opt_selection.has_value() &&
      d->context.opt_selection.value().tracking) {
    auto &selection = d->context.opt_selection.value();
    selection.tracking = false;
    SanitizeSelection(selection);

    if (selection.first_cursor.token_id == selection.last_cursor.token_id &&
        selection.first_cursor.offset == selection.last_cursor.offset) {
      emit TokenClicked(event->globalPos(), event->button(),
                        selection.first_cursor.token_id);
    }
  }
}

void ITextView::mouseMoveEvent(QMouseEvent *event) {
  if (!d->context.opt_selection.has_value()) {
    return;
  }

  auto &selection = d->context.opt_selection.value();
  if (!selection.tracking) {
    return;
  }

  QPointF mouse_position(
      static_cast<qreal>(event->x() + d->context.viewport.x()),
      static_cast<qreal>(event->y() + d->context.viewport.y()));

  auto opt_cursor = CreateCursor(d->context, mouse_position);
  if (opt_cursor.has_value()) {
    selection.last_cursor = opt_cursor.value();
  }

  update();
}

void ITextView::focusOutEvent(QFocusEvent *event) {
  if (d->context.opt_selection.has_value()) {
    auto &selection = d->context.opt_selection.value();
    if (selection.tracking) {
      selection.tracking = false;
      update();
    }
  }
}

void ITextView::wheelEvent(QWheelEvent *event) {
  // On macOS, the most precise way to implement scrolling is to use pixelDelta;
  // it is however not available on other platforms, so if that value is empty
  // we should fallback to angleDelta instead
  //
  // NOTE: This also handles touchpad scrolling!

  int vertical_pixel_delta{};
  int horizontal_pixel_delta{};

  if (auto pixel_delta_point = event->pixelDelta();
      !pixel_delta_point.isNull()) {
    vertical_pixel_delta = pixel_delta_point.y();
    horizontal_pixel_delta = pixel_delta_point.x();

  } else {
    // High resolution gaming mice are capable of returning fractions of what is
    // usually considered a single mouse wheel turn
    auto vertical_angle_delta = event->angleDelta().y();
    auto horizontal_angle_delta = event->angleDelta().x();

    auto line_height = QFontMetrics(font(), this).height();

    vertical_pixel_delta =
        line_height * static_cast<int>(vertical_angle_delta * 1.0 / 120.0);

    horizontal_pixel_delta =
        line_height * static_cast<int>(horizontal_angle_delta * 1.0 / 120.0);
  }

  vertical_pixel_delta *= -1;
  horizontal_pixel_delta *= -1;

  // Get the next vertical scrollbar value
  auto next_vertical_scrollbar_value = d->vertical_scrollbar->value() +
                                       vertical_pixel_delta;

  if (next_vertical_scrollbar_value < d->vertical_scrollbar->minimum()) {
    next_vertical_scrollbar_value = d->vertical_scrollbar->minimum();

  } else if (next_vertical_scrollbar_value > d->vertical_scrollbar->maximum()) {
    next_vertical_scrollbar_value = d->vertical_scrollbar->maximum();
  }

  d->vertical_scrollbar->setValue(next_vertical_scrollbar_value);

  // Get the next horizontal scrollbar value
  auto next_horizontal_scrollbar_value = d->horizontal_scrollbar->value() +
                                         horizontal_pixel_delta;

  if (next_horizontal_scrollbar_value < d->horizontal_scrollbar->minimum()) {
    next_horizontal_scrollbar_value = d->horizontal_scrollbar->minimum();

  } else if (next_horizontal_scrollbar_value >
             d->horizontal_scrollbar->maximum()) {
    next_horizontal_scrollbar_value = d->horizontal_scrollbar->maximum();
  }

  d->horizontal_scrollbar->setValue(next_horizontal_scrollbar_value);

  OnScrollBarValueChange(0);
}

void ITextView::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Escape && d->context.opt_selection.has_value()) {
    d->context.opt_selection = std::nullopt;
    update();
  }
  emit KeyPressed(event);
}


void ITextView::keyReleaseEvent(QKeyEvent *event) {
  emit KeyReleased(event);
}

void ITextView::UpdateScrollbars() {
  if (!d->context.opt_scene.has_value()) {
    return;
  }

  const auto &scene = d->context.opt_scene.value();
  auto scene_width = scene.bounding_box.width();
  auto scene_height = scene.bounding_box.height();

  if (d->context.viewport.width() < scene_width) {
    d->horizontal_scrollbar->show();
    d->horizontal_scrollbar->setMaximum(
        static_cast<int>(scene_width - d->context.viewport.width()));

  } else {
    d->horizontal_scrollbar->hide();
    d->horizontal_scrollbar->setMaximum(0);
  }

  if (d->context.viewport.height() < scene_height) {
    d->vertical_scrollbar->show();
    d->vertical_scrollbar->setMaximum(
        static_cast<int>(scene_height - d->context.viewport.height()));

  } else {
    d->vertical_scrollbar->hide();
    d->vertical_scrollbar->setMaximum(0);
  }
}

TextViewTheme ITextView::GetDefaultTheme() {
  auto system_font = QFontDatabase::systemFont(QFontDatabase::FixedFont);

  TextViewTheme output;
  output.monospaced_font = system_font;
  output.background = palette().color(QPalette::Base);
  output.foreground = palette().color(QPalette::Text);
  output.line_numbers = output.foreground;

  return output;
}

void ITextView::OnModelReset() {
  MoveViewport(d->context, QPointF(0.0, 0.0));
  CreateTokenIndex(d->context, *d->model.get());
  UpdateScrollbars();
  ResetScene(d->context);
  update();
}

void ITextView::OnScrollBarValueChange(int) {
  auto vertical_scroll_value =
      static_cast<qreal>(d->vertical_scrollbar->value());
  auto horizontal_scroll_value =
      static_cast<qreal>(d->horizontal_scrollbar->value());

  ScrollViewportTo(d->context, QPointF(horizontal_scroll_value,
                                       vertical_scroll_value));
  update();
}

void ITextView::ScrollViewportTo(Context &context, const QPointF &point) {
  if (!context.opt_scene.has_value()) {
    return;
  }

  context.viewport.moveTo(point);

  const auto &scene = context.opt_scene.value();
  auto max_x = scene.bounding_box.x() + scene.bounding_box.width();
  if (context.viewport.x() > max_x) {
    context.viewport.setX(max_x);
  }

  auto max_y = scene.bounding_box.y() + scene.bounding_box.height();
  if (context.viewport.y() > max_y) {
    context.viewport.setY(max_y);
  }

  if (context.viewport.x() < 0) {
    context.viewport.moveTo(0.0, context.viewport.y());
  }

  if (context.viewport.y() < 0) {
    context.viewport.moveTo(context.viewport.x(), 0.0);
  }
}

void ITextView::ResizeViewport(Context &context, const QSizeF &size) {
  context.viewport.setWidth(size.width());
  context.viewport.setHeight(size.height());
}

void ITextView::MoveViewport(Context &context, const QPointF &point) {
  context.viewport.moveTo(point);
}

void ITextView::CreateTokenIndex(Context &context, ITextModel &model) {
  auto token_height = context.font_metrics->height() + kFontHeightPadding;
  auto font_width = context.font_metrics->horizontalAdvance(".") +
                    kFontWidthPadding;

  TokenEntityRowList token_index;
  TokenEntityList token_entity_row;

  QString chunk_data;
  auto L_add_token = [&](unsigned token_id) {
    if (auto len = chunk_data.size()) {
      auto token_width = context.font_metrics->horizontalAdvance(chunk_data);
      if (token_width == 0.0) {
        token_width = font_width;
      } else {
        token_width += static_cast<qreal>(
            kFontWidthPadding * static_cast<float>(len));
      }

      TokenEntity token_entity;
      token_entity.token_id = token_id;
      token_entity.text = std::move(chunk_data);
      token_entity.bounding_box = QRectF(0.0, 0.0, token_width, token_height);
      token_entity_row.push_back(std::move(token_entity));
    }
  };

  auto tab_size = model.TabWidth();

  for (auto token_id = 0u, num_tokens = model.NumTokens();
       token_id < num_tokens; ++token_id) {
    const QString token_data = model.TokenData(token_id);

    chunk_data.clear();
    chunk_data.reserve(token_data.size());

    for (auto ch : token_data) {
      if (ch == '\n') {
        L_add_token(token_id);
        token_index.push_back(std::move(token_entity_row));
        token_entity_row = {};

      } else if (ch == '\r') {
        continue;

      // Turn tabs into spaces.
      } else if (ch == '\t') {
        for (auto t = 0u; t < tab_size; ++t) {
          chunk_data += ' ';
        }

      } else {
        chunk_data += ch;
      }
    }

    L_add_token(token_id);
  }

  context.token_index = std::move(token_index);
}

void ITextView::ResetScene(Context &context) { context.opt_scene = {}; }

void ITextView::GenerateScene(Context &context, ITextModel &model) {
  Scene scene;

  auto font_height = context.font_metrics->height() + kFontHeightPadding;
  scene.bounding_box.setWidth(font_height);
  scene.bounding_box.setHeight(font_height);

  auto right_margin = context.viewport.x() + context.viewport.width();
  auto left_margin = font_height;

  QRectF line_number_rect;
  auto line_number = model.FirstLineNumber();

  if (context.line_numbers) {
    auto highest_line_number =
        QString::number(context.token_index.size() + model.FirstLineNumber());

    auto line_number_length =
        context.font_metrics->horizontalAdvance(highest_line_number) +
        font_height;

    scene.gutter_margin = left_margin += line_number_length + font_height;
    left_margin = scene.gutter_margin + font_height;

    line_number_rect = QRectF(0.0, 0.0, line_number_length, font_height);
  }

  QPointF current_pos(left_margin, font_height);

  for (const auto &token_entity_row : context.token_index) {
    SceneRow row;
    row.bounding_box.moveTo(current_pos);
    row.bounding_box.setHeight(font_height);

    if (context.line_numbers) {
      LineNumber ln;
      ln.bounding_box = line_number_rect;
      ln.bounding_box.moveTo(QPointF(font_height, current_pos.y()));
      ln.str = QString::number(line_number);

      scene.line_number_list.push_back(std::move(ln));
      ++line_number;
    }

    for (auto token_entity : token_entity_row) {
      if (context.word_wrap) {
        if ((current_pos.x() + token_entity.bounding_box.width()) >
            right_margin) {
          current_pos.setX(left_margin + (font_height * 2));
          current_pos.setY(current_pos.y() + font_height);
        }
      }

      token_entity.bounding_box.moveTo(current_pos);
      current_pos.setX(current_pos.x() + token_entity.bounding_box.width());

      row.bounding_box = row.bounding_box.united(token_entity.bounding_box);
      row.entity_list.push_back(std::move(token_entity));
    }

    scene.bounding_box = scene.bounding_box.united(row.bounding_box);
    scene.row_list.push_back(std::move(row));
    row = {};

    current_pos.setX(left_margin);
    current_pos.setY(current_pos.y() + font_height);
  }

  scene.bounding_box.adjust(0.0, 0.0, font_height, font_height);

  context.opt_scene = std::move(scene);
}

std::optional<ITextView::Cursor> ITextView::CreateCursor(
    Context &context, QPointF pos) {
  if (!context.opt_scene.has_value()) {
    return std::nullopt;
  }

  auto font_width = context.font_metrics->horizontalAdvance(".") + kFontWidthPadding;
  auto font_height = context.font_metrics->height() + kFontHeightPadding;

  const auto &scene = context.opt_scene.value();

  if (pos.x() < font_height) {
    pos.setX(font_height);
  }

  if (pos.y() < font_height) {
    pos.setY(font_height);
  }

  if (pos.y() >= scene.bounding_box.y() + scene.bounding_box.height()) {
    pos.setX(scene.bounding_box.x() + scene.bounding_box.width() -
             font_height - 1.0);
    pos.setY(scene.bounding_box.y() + scene.bounding_box.height() -
             font_height - 1.0);
  }

  for (const auto &row : scene.row_list) {
    for (auto entity_it = row.entity_list.begin(); entity_it != row.entity_list.end();
         ++entity_it) {

      const auto &entity = *entity_it;

      auto adjusted_pos = pos;
      if (std::next(entity_it, 1) == row.entity_list.end()) {
        auto max_x_pos = entity.bounding_box.x() +
                         entity.bounding_box.width() - 1.0;

        if (adjusted_pos.x() >= max_x_pos) {
          adjusted_pos.setX(max_x_pos);
        }
      }

      if (!entity.bounding_box.contains(adjusted_pos)) {
        continue;
      }

      Cursor cursor;
      cursor.token_id = entity.token_id;
      cursor.offset = static_cast<std::size_t>(
          (adjusted_pos.x() - entity.bounding_box.x()) / font_width);

      return cursor;
    }
  }

  return std::nullopt;
}

void ITextView::SanitizeSelection(Selection &selection) {
  auto swap_cursors{false};
  if (selection.first_cursor.token_id == selection.last_cursor.token_id) {
    swap_cursors = selection.last_cursor.offset < selection.first_cursor.offset;
  } else if (selection.first_cursor.token_id > selection.last_cursor.token_id) {
    swap_cursors = true;
  }

  if (swap_cursors) {
    std::swap(selection.first_cursor, selection.last_cursor);
  }
}

} // namespace mx::gui
