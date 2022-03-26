// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QObject>
#include <QVariant>

#include <limits>
#include <memory>

namespace mx::gui {

using TokenColorId = std::uint16_t;
constexpr TokenColorId kInvalidTokenColorId{
  std::numeric_limits<uint16_t>::max()};

class ITextModel : public QObject {
  Q_OBJECT

 public:
  using Ptr = std::shared_ptr<ITextModel>;

  ITextModel(QObject *parent=nullptr) : QObject(parent) {};
  virtual ~ITextModel(void) = default;

  // Return the number of tokens.
  virtual unsigned TabWidth(void) const = 0;
  virtual unsigned NumTokens(void) const = 0;
  virtual unsigned FirstLineNumber(void) const = 0;

  virtual unsigned TokenGroup(unsigned token_index) const = 0;
  virtual QString TokenData(unsigned token_index) const = 0;
  virtual TokenColorId TokenColor(unsigned token_index) const = 0;
  virtual QVariant TokenProperty(unsigned token_index,
                                 unsigned property_id) const = 0;

  ITextModel(const ITextModel &) = delete;
  ITextModel &operator=(const ITextModel &) = delete;

 signals:
  void ModelReset(void);
};

}  // namespace mx::gui

Q_DECLARE_INTERFACE(mx::gui::ITextModel, "ITextModel")
