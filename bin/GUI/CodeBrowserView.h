// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QWidget>

namespace mx {
class Index;
namespace gui {

// The code browser is responsible for displaying one or more files of code.
class CodeBrowserView final : public QWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~CodeBrowserView(void);

  CodeBrowserView(const Index &index_, QWidget *parent=nullptr);
};

}  // namespace gui
}  // namespace mx
