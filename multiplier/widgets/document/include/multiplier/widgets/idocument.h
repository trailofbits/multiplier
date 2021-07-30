/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QFrame>
#include <QTreeWidgetItem>

#include <memory>

#include <tob/itextview.h>

#include <pasta/AST/Decl.h>
#include <pasta/Util/File.h>

using namespace tob::widgets;

namespace pasta {
class CompileJob;
} // namespace pasta

namespace multiplier {

class IDocument : public QFrame {
  Q_OBJECT

public:
  static IDocument *create(const pasta::CompileJob &job, QWidget *parent = nullptr);
  virtual ~IDocument() = default;

  IDocument(const IDocument &) = delete;
  IDocument &operator=(const IDocument &) = delete;

protected:
  IDocument(QWidget *parent) : QFrame(parent) {}
};

} // namespace multiplier

Q_DECLARE_INTERFACE(multiplier::IDocument, "IDocument")
