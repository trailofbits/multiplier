/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <multiplier/widgets/idocument.h>

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

class Document final : public IDocument {
  Q_OBJECT
  Q_INTERFACES(multiplier::IDocument)

public:
  Document(const pasta::CompileJob &job, QWidget *parent);
  virtual ~Document() override;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onSourceCodeItemClicked(const QPoint &mouse_position, const Qt::MouseButton &button,
                               TokenID token_id);

  void onCopyAction();
  void highlightDecl(pasta::Decl decl);
  void displayParsedFile(pasta::File file);
};

} // namespace multiplier
