// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>
#include <QString>
#include <QBrush>
#include <utility>
#include <vector>

QT_BEGIN_NAMESPACE
class QPainter;
class QRectF;
QT_END_NAMESPACE
namespace mx::gui {

class Code {
 public:
  QString data;
  std::vector<int> start_of_token;
  std::vector<bool> italic;
  std::vector<bool> bold;
  std::vector<bool> underline;
  std::vector<const QBrush *> foreground;
  std::vector<const QBrush *> background;
  std::vector<RawEntityId> file_token_ids;
  std::vector<std::pair<RawEntityId, RawEntityId>> tok_decl_ids;
  std::vector<unsigned> tok_decl_ids_begin;

  // Line number of the first character of the first token.
  unsigned first_line{0u};

  // Line number of the last character of the last token.
  unsigned last_line{0u};

//  // Paint the tokens in the range `[begin_index, end_index)`.
//  void PaintTokens(const QRectF &rect, QPainter *painter, unsigned begin_index,
//                   unsigned end_index) const;
};

}  // namespace mx::gui
