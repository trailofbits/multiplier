/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#pragma once

#include <QString>

#include <sstream>

namespace multiplier {

bool generateAST(std::stringstream &ast, const QString &working_directory,
                 const QString &compile_command);

} // namespace multiplier
