/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QObject>
#include <QVariant>

#include <limits>
#include <memory>

namespace tob::widgets {

using TokenID = std::uint64_t;
constexpr TokenID kInvalidTokenID{std::numeric_limits<uint64_t>::max()};

using TokenGroupID = std::uint64_t;
constexpr TokenGroupID kInvalidTokenGroupID{std::numeric_limits<uint64_t>::max()};

using TokenColorID = std::uint64_t;
constexpr TokenColorID kInvalidTokenColorID{0};

enum TokenAttribute : std::uint32_t {
  TokenAttribute_Interactive = 1,
  TokenAttribute_DisplayOnGutter = 2,
};

using TokenIDList = std::vector<TokenID>;

class ITextModel : public QObject {
  Q_OBJECT

public:
  using Ptr = std::shared_ptr<ITextModel>;

  ITextModel(QObject *parent) : QObject(parent){};
  virtual ~ITextModel() = default;

  virtual std::size_t firstLineNumber() const = 0;
  virtual TokenID firstTokenID() const = 0;
  virtual TokenID lastTokenID() const = 0;

  virtual TokenGroupID tokenGroupID(TokenID token_id) const = 0;
  virtual QString tokenData(TokenID token_id) const = 0;
  virtual TokenColorID tokenColor(TokenID token_id) const = 0;
  virtual QVariant tokenProperty(TokenID token_id, int property_id) const = 0;
  virtual TokenAttribute tokenAttributes(TokenID token_id) const = 0;

  ITextModel(const ITextModel &) = delete;
  ITextModel &operator=(const ITextModel &) = delete;

signals:
  void modelReset();
};

} // namespace tob::widgets

Q_DECLARE_INTERFACE(tob::widgets::ITextModel, "ITextModel")
