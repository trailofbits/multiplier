/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "glyphcache.h"

#include <QFontMetrics>
#include <QMap>
#include <QPainter>

#include <list>
#include <unordered_map>

namespace tob::widgets {

struct GlyphCache::PrivateData final {
  qreal pixel_ratio{};
  QFont font;
  std::size_t cache_size{};

  QRectF glyph_rect;

  std::vector<QChar> glyph_list;
  std::size_t current_glyph_index{};

  QMap<QChar, QPixmap> glyph_map;
};

GlyphCache::Ptr GlyphCache::create(qreal pixel_ratio, const QFont &font, std::size_t cache_size) {
  return Ptr(new (std::nothrow) GlyphCache(pixel_ratio, font, cache_size));
}

GlyphCache::~GlyphCache() {}

const QPixmap &GlyphCache::get(QChar c) {
  auto glyph_map_it = d->glyph_map.find(c);
  if (glyph_map_it == d->glyph_map.end()) {

    auto pixmap = generatePixmap();
    generateGlyph(pixmap, c);

    glyph_map_it = d->glyph_map.insert(c, std::move(pixmap));

    if (!d->glyph_list[d->current_glyph_index].isNull()) {
      d->glyph_map.remove(d->glyph_list[d->current_glyph_index]);
    }

    d->glyph_list[d->current_glyph_index] = c;
    d->current_glyph_index = (d->current_glyph_index + 1) % d->cache_size;
  }

  return *glyph_map_it;
}

GlyphCache::GlyphCache(qreal pixel_ratio, const QFont &font, std::size_t cache_size)
    : d(new PrivateData) {
  d->pixel_ratio = pixel_ratio;
  d->font = font;
  d->cache_size = cache_size;

  QFontMetricsF font_metrics(d->font);
  d->glyph_rect = QRectF(0.0, 0.0, font_metrics.horizontalAdvance("."), font_metrics.height());
  d->glyph_list.resize(cache_size, QChar(0));
}

QPixmap GlyphCache::generatePixmap() {
  auto width = static_cast<int>(d->glyph_rect.width() * d->pixel_ratio);
  auto height = static_cast<int>(d->glyph_rect.height() * d->pixel_ratio);

  QPixmap pixmap(width, height);
  pixmap.setDevicePixelRatio(d->pixel_ratio);
  pixmap.fill(Qt::transparent);

  return pixmap;
}

void GlyphCache::generateGlyph(QPixmap &pixmap, QChar c) {
  QPainter painter(&pixmap);
  painter.setFont(d->font);
  painter.setPen(QPen(QColor::fromRgba(0xFFFFFFFF)));
  painter.setRenderHint(QPainter::Antialiasing);
  painter.drawText(d->glyph_rect, Qt::AlignCenter | Qt::TextSingleLine, c);
}

} // namespace tob::widgets
