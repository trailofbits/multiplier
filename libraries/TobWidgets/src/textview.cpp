/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "textview.h"

#include <QApplication>
#include <QPainter>
#include <QResizeEvent>

namespace tob::widgets {

namespace {

QColor invertColor(const QColor &color) {
  auto red = 1.0 - color.redF();
  auto green = 1.0 - color.greenF();
  auto blue = 1.0 - color.blueF();

  return QColor::fromRgbF(red, green, blue);
}

} // namespace

struct TextView::PrivateData final {
  ITextModel::Ptr model;
  Context context;
};

TextView::TextView(QWidget *parent) : ITextView(parent), d(new PrivateData) {
#ifdef __linux__
  setFont(QFont("Hack"));
#else
  setFont(QFont("Monaco"));
#endif

  setFocusPolicy(Qt::StrongFocus);

  d->context.font_metrics = std::make_unique<QFontMetricsF>(font(), this);
  d->context.glyph_cache = GlyphCache::create(devicePixelRatio(), font(), 2048);

  d->context.theme.background = palette().color(QPalette::Base);
  d->context.theme.foreground = palette().color(QPalette::Text);
}

TextView::~TextView() {}

void TextView::setModel(ITextModel::Ptr model) {
  d->model = model;
  onModelReset();
}

void TextView::setTheme(const TextViewTheme &theme) { d->context.theme = theme; }

bool TextView::hasSelection() const { return d->context.opt_selection.has_value(); }

std::optional<QString> TextView::getSelection() {
  if (!d->context.opt_selection.has_value()) {
    return std::nullopt;
  }

  auto selection = d->context.opt_selection.value();
  sanitizeSelection(selection);

  QString output;
  for (auto token_id = selection.first_cursor.token_id; token_id <= selection.last_cursor.token_id;
       ++token_id) {

    auto token = d->model->tokenData(token_id);

    if (selection.first_cursor.token_id == token_id && selection.last_cursor.token_id == token_id) {
      auto length =
          static_cast<int>(selection.last_cursor.offset - selection.first_cursor.offset) + 1;
      output += token.mid(static_cast<int>(selection.first_cursor.offset), length);

    } else if (selection.first_cursor.token_id == token_id) {
      output += token.mid(static_cast<int>(selection.first_cursor.offset));

    } else if (selection.last_cursor.token_id == token_id) {
      output += token.mid(0, static_cast<int>(selection.last_cursor.offset) + 1);

    } else {
      output += token;
    }
  }

  if (output.isEmpty()) {
    return std::nullopt;
  }

  return output;
}

void TextView::resizeEvent(QResizeEvent *event) {
  auto width = static_cast<qreal>(event->size().width());
  auto height = static_cast<qreal>(event->size().height());

  resizeViewport(d->context, devicePixelRatio(), QSizeF(width, height));
  resetScene(d->context);
}

void TextView::paintEvent(QPaintEvent *event) {
  drawViewport(d->context, *d->model.get());

  QPainter painter(this);
  painter.fillRect(event->rect(), QBrush(d->context.theme.background));
  painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
  painter.drawPixmap(QPointF(0.0, 0.0), d->context.viewport_surface);
}

void TextView::mousePressEvent(QMouseEvent *event) {
  QPointF mouse_position(static_cast<qreal>(event->x()), static_cast<qreal>(event->y()));
  auto opt_cursor = createCursor(d->context, mouse_position);
  if (!opt_cursor.has_value()) {
    return;
  }

  auto cursor = std::move(opt_cursor.value());

  if (event->button() == Qt::LeftButton) {
    if ((QApplication::keyboardModifiers() & Qt::ControlModifier) != 0) {
      emit tokenClicked(event->globalPos(), event->button(), cursor.token_id);

    } else {
      Selection selection;
      selection.tracking = true;
      selection.first_cursor = std::move(cursor);

      d->context.opt_selection = selection;
    }

  } else {
    emit tokenClicked(event->globalPos(), event->button(), cursor.token_id);
  }
}

void TextView::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && d->context.opt_selection.has_value() &&
      d->context.opt_selection.value().tracking) {
    auto &selection = d->context.opt_selection.value();
    selection.tracking = false;
    sanitizeSelection(selection);
  }
}

void TextView::mouseMoveEvent(QMouseEvent *event) {
  if (!d->context.opt_selection.has_value()) {
    return;
  }

  auto &selection = d->context.opt_selection.value();
  if (!selection.tracking) {
    return;
  }

  QPointF mouse_position(static_cast<qreal>(event->x()), static_cast<qreal>(event->y()));

  auto opt_cursor = createCursor(d->context, mouse_position);
  if (opt_cursor.has_value()) {
    selection.last_cursor = opt_cursor.value();
  }

  update();
}

void TextView::focusOutEvent(QFocusEvent *event) {
  if (d->context.opt_selection.has_value()) {
    auto &selection = d->context.opt_selection.value();
    if (selection.tracking) {
      selection.tracking = false;
      update();
    }
  }
}

void TextView::onModelReset() {
  moveViewport(d->context, QPointF(0.0, 0.0));
  createTokenIndex(d->context, *d->model.get());
  resetScene(d->context);
}

void TextView::resizeViewport(Context &context, qreal pixel_ratio, const QSizeF &size) {
  context.viewport.setWidth(size.width());
  context.viewport.setHeight(size.height());

  auto device_width = static_cast<int>(size.width() * pixel_ratio);
  auto device_height = static_cast<int>(size.height() * pixel_ratio);

  context.viewport_surface = QPixmap(device_width, device_height);
  context.viewport_surface.setDevicePixelRatio(pixel_ratio);
}

void TextView::moveViewport(Context &context, const QPointF &point) {
  context.viewport.moveTo(point);
}

void TextView::drawViewport(Context &context, const ITextModel &model) {
  if (!context.opt_scene) {
    generateScene(context);
  }

  context.viewport_surface.fill(Qt::transparent);

  QPainter painter(&context.viewport_surface);
  painter.setRenderHint(QPainter::Antialiasing);

  QPointF translation(-context.viewport.x(), -context.viewport.y());
  auto font_width = context.font_metrics->horizontalAdvance(".");

  const auto &scene = context.opt_scene.value();
  for (const auto &row : scene.row_list) {
    if (!row.bounding_box.intersects(context.viewport)) {
      continue;
    }

    for (const auto &entity : row.entity_list) {
      QPointF pos(entity.bounding_box.x(), entity.bounding_box.y());
      pos += translation;

      const auto &token = model.tokenData(entity.token_id);
      std::size_t character_index = 0;

      for (const auto &c : token) {
        bool highlight{false};
        if (context.opt_selection.has_value()) {
          auto selection = context.opt_selection.value();
          sanitizeSelection(selection);

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

        const auto &glyph = context.glyph_cache->get(c);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.drawPixmap(pos, glyph);

        auto foreground = context.theme.foreground;
        if (auto color_id = model.tokenColor(entity.token_id);
            color_id != kInvalidTokenColorID && context.theme.color_map.count(color_id) > 0) {
          foreground = context.theme.color_map.at(color_id);
        }

        if (highlight) {
          foreground = invertColor(foreground);
        }

        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.fillRect(QRect((int)pos.x(), (int)pos.y(), glyph.width(), glyph.height()),
                         QBrush(foreground));

        if (highlight) {
          auto background = invertColor(context.theme.background);

          painter.setCompositionMode(QPainter::CompositionMode_DestinationAtop);
          painter.fillRect(QRect((int)pos.x(), (int)pos.y(), glyph.width(), glyph.height()),
                           QBrush(background));
        }

        pos.setX(pos.x() + font_width);

        ++character_index;
      }
    }
  }
}

void TextView::createTokenIndex(Context &context, ITextModel &model) {
  auto token_height = context.font_metrics->height();

  TokenEntityRowList token_index;
  TokenEntityList token_entity_row;

  for (auto token_id = model.firstTokenID(); token_id <= model.lastTokenID(); ++token_id) {
    const auto &token_data = model.tokenData(token_id);
    auto token_width = context.font_metrics->horizontalAdvance(token_data);

    TokenEntity token_entity;
    token_entity.token_id = token_id;
    token_entity.bounding_box = QRectF(0.0, 0.0, token_width, token_height);
    token_entity_row.push_back(std::move(token_entity));

    if (token_data.endsWith("\n")) {
      token_index.push_back(std::move(token_entity_row));
      token_entity_row = {};
    }
  }

  context.token_index = std::move(token_index);
}

void TextView::resetScene(Context &context) { context.opt_scene = {}; }

void TextView::generateScene(Context &context) {
  Scene scene;
  auto font_height = context.font_metrics->height();

  QPointF current_pos(font_height, font_height);
  auto right_margin = context.viewport.x() + context.viewport.width();

  for (const auto &token_entity_row : context.token_index) {
    SceneRow row;
    row.bounding_box.moveTo(current_pos);
    row.bounding_box.setHeight(font_height);

    for (auto token_entity : token_entity_row) {
      if (context.word_wrap) {
        if (current_pos.x() + token_entity.bounding_box.width() > right_margin) {
          current_pos.setX(font_height * 2);
          current_pos.setY(current_pos.y() + font_height);
        }
      }

      token_entity.bounding_box.moveTo(current_pos);
      current_pos.setX(current_pos.x() + token_entity.bounding_box.width());

      row.bounding_box = row.bounding_box.united(token_entity.bounding_box);
      row.entity_list.push_back(std::move(token_entity));
    }

    scene.row_list.push_back(std::move(row));
    row = {};

    current_pos.setX(font_height);
    current_pos.setY(current_pos.y() + font_height);
  }

  context.opt_scene = std::move(scene);
}

std::optional<TextView::Cursor> TextView::createCursor(Context &context, const QPointF &pos) {
  if (!context.opt_scene.has_value()) {
    return std::nullopt;
  }

  auto font_width = context.font_metrics->horizontalAdvance(".");
  const auto &scene = context.opt_scene.value();

  for (const auto &row : scene.row_list) {
    if (!row.bounding_box.contains(pos)) {
      continue;
    }

    for (const auto &entity : row.entity_list) {
      if (!entity.bounding_box.contains(pos)) {
        continue;
      }

      Cursor cursor;
      cursor.token_id = entity.token_id;
      cursor.offset = static_cast<std::size_t>((pos.x() - entity.bounding_box.x()) / font_width);

      return cursor;
    }
  }

  return std::nullopt;
}

void TextView::sanitizeSelection(Selection &selection) {
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

} // namespace tob::widgets
