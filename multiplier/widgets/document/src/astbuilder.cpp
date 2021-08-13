/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "astbuilder.h"

#include <iostream>

namespace multiplier {

ASTBuilder::ASTBuilder(pasta::CompileJob job_) : job(std::move(job_)) { setAutoDelete(true); }

void ASTBuilder::run(void) {
  auto ast = job.Run();
  if (ast.Failed()) {
    std::cerr << ast.TakeError() << std::endl;
  } else {
    emit gotAST(std::make_shared<pasta::AST>(ast.TakeValue()));
  }
}

} // namespace multiplier
