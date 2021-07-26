/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <tob/itextmodel.h>

#include <memory>

using namespace tob::widgets;

namespace multiplier {

class SourceCodeModel final : public ITextModel {
  Q_OBJECT
  Q_INTERFACES(tob::widgets::ITextModel)

public:
  SourceCodeModel(const QString &path, QObject *parent = nullptr);
  virtual ~SourceCodeModel();

  void generateTestData(const QString &path);

  virtual TokenID firstTokenID() const override;
  virtual TokenID lastTokenID() const override;

  virtual TokenGroupID tokenGroupID(TokenID token_id) const override;
  virtual QString tokenData(TokenID token_id) const override;
  virtual TokenColorID tokenColor(TokenID token_id) const override;
  virtual QVariant tokenProperty(TokenID token_id, int property_id) const override;
  virtual TokenAttribute tokenAttributes(TokenID token_id) const override;

  SourceCodeModel(const SourceCodeModel &) = delete;
  SourceCodeModel &operator=(const SourceCodeModel &) = delete;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

signals:
  void modelReset();
};

} // namespace multiplier
