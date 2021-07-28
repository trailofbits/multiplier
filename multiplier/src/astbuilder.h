/*
 Copyright (c) 2021-present, Trail of Bits, Inc.
 All rights reserved.

 This source code is licensed in accordance with the terms specified in
 the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <pasta/AST/AST.h>
#include <pasta/Compile/Job.h>

#include <QObject>
#include <QRunnable>

#include <memory>
#include <optional>

namespace multiplier {

class ASTBuilder final : public QObject, public QRunnable {
  Q_OBJECT

  const pasta::CompileJob job;

 public:
  explicit ASTBuilder(pasta::CompileJob job_);

  void run(void) final;

 signals:
  void gotAST(std::shared_ptr<pasta::AST> ast);
};

}  // namespace multiplier
