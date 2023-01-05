// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>

#include "Entities/Macro.h"
#include "Entities/Stmt.h"

namespace mx {

class Decl;
class File;
class ReferenceIteratorImpl;

// A reference from a statement to a declaration.
class StmtReference {
 private:
  friend class Fragment;
  friend class Decl;
  friend class ReferenceIteratorImpl;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0u};

  StmtReference(void) = default;

 public:

  Stmt statement(void) && noexcept;
  Stmt statement(void) const & noexcept;
  operator Stmt(void) && noexcept;
  operator Stmt(void) const & noexcept;
};

// A reference
class MacroReference {
 private:
  friend class Fragment;
  friend class File;
  friend class ReferenceIteratorImpl;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset{0u};

  MacroReference(void) = default;

 public:
  Macro macro(void) && noexcept;
  Macro macro(void) const & noexcept;
  operator Macro(void) && noexcept;
  operator Macro(void) const & noexcept;
};

}  // namespace mx
