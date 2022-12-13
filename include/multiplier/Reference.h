// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

#include "Entities/Stmt.h"

namespace mx {

class Decl;

class Reference {
 private:
  friend class Fragment;
  friend class Decl;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0u};

  Reference(void) = default;

 public:

  Stmt statement(void) && noexcept;
  Stmt statement(void) const & noexcept;
  operator Stmt(void) && noexcept;
  operator Stmt(void) const & noexcept;
};

}  // namespace mx
