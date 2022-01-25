// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <iostream>

namespace pasta {
class ArgumentVector;
}  // namespace pasta
namespace mx {

class Subprocess {
 public:

  // Execute the command specified in `args` with the ability to feed the
  // command input and capture output. Passing `nullptr` to any of `input`,
  // `output`, or `error` is acceptable.
  static int Execute(const pasta::ArgumentVector &args,
                     std::istream *input=nullptr,
                     std::ostream *output=nullptr,
                     std::ostream *error=nullptr);
};

}  // namespace mx
