// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <gap/core/generator.hpp>
#include <memory>

#include "Types.h"

namespace mx {
namespace ir {
class SourceIRImpl;
namespace builtin {
class ModuleOp;
}  // namespace builtin
}  // namespace ir

class CompilationImpl;
class EntityProvider;
class File;
class Fragment;
class FragmentImpl;
class Index;
class Reference;

using CompilationImplPtr = std::shared_ptr<const CompilationImpl>;

// Represents a single compile command.
class Compilation {
 private:
  friend class CompilationImpl;
  friend class EntityProvider;
  friend class FragmentImpl;
  friend class Index;
  friend class Reference;
  friend class ir::SourceIRImpl;

  CompilationImplPtr impl;

 public:
  /* implicit */ inline Compilation(CompilationImplPtr impl_)
      : impl(std::move(impl_)) {}

  // The compilation containing/owning a fragment.
  static Compilation containing(const Fragment &);

  // Return the unique ID of this compilation.
  PackedCompilationId id(void) const noexcept;

  // Returns source IR for the compilation.
  std::optional<ir::builtin::ModuleOp> ir(void) const noexcept;

  // The fragments owned by this compilation. This will be a subset of all
  // observable fragments by this compilation, because some of them may be
  // owned by a different compilation.
  gap::generator<Fragment> fragments(void) const & noexcept;

  // The files parsed by this compilation.
  gap::generator<File> files(void) const & noexcept;

  // The main source file of this compilation.
  File main_source_file(void) const noexcept;
};

}  // namespace mx
