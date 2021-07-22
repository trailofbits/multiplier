/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QPixmap>

#include <memory>

namespace tob::widgets {

class GlyphCache final {
public:
  using Ptr = std::unique_ptr<GlyphCache>;

  static Ptr create(qreal pixel_ratio, const QFont &font, std::size_t cache_size);
  ~GlyphCache();

  const QPixmap &get(QChar c);

  GlyphCache(const GlyphCache &) = delete;
  GlyphCache &operator=(const GlyphCache &) = delete;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  GlyphCache(qreal pixel_ratio, const QFont &font, std::size_t cache_size);

  QPixmap generatePixmap();
  void generateGlyph(QPixmap &pixmap, QChar c);
};

} // namespace tob::widgets
