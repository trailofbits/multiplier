// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <gap/coro/generator.hpp>
#include <memory>
#include <optional>
#include <string_view>
#include <utility>

#include "../Entity.h"

namespace mx {
namespace ir {
class Operation;
class SourceIRImpl;
namespace builtin {
class ModuleOp;
}  // namespace builtin
}  // namespace ir

class CompilationImpl;
class Decl;
class DefineMacroDirective;
class EntityProvider;
class File;
class Fragment;
class FragmentImpl;
class Index;
class Reference;
class Stmt;

using CompilationImplPtr = std::shared_ptr<const CompilationImpl>;

enum class IncludePathLocation : unsigned char;

// Represents a single compile command.
class MX_EXPORT Compilation {
 private:
  friend class CompilationImpl;
  friend class Decl;
  friend class EntityProvider;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Reference;
  friend class Stmt;
  friend class ir::SourceIRImpl;
  friend class ir::Operation;

  CompilationImplPtr impl;

 public:
  /* implicit */ inline Compilation(CompilationImplPtr impl_)
      : impl(std::move(impl_)) {}

  // The compilation containing/owning a fragment.
  static Compilation containing(const Fragment &);
  static std::optional<Compilation> containing(const std::optional<Fragment> &);

  static Compilation containing(const Decl &);
  static Compilation containing(const Stmt &);
  static Compilation containing(const Attr &);
  static Compilation containing(const TemplateArgument &);
  static Compilation containing(const TemplateParameterList &);
  static Compilation containing(const CXXBaseSpecifier &);
  static Compilation containing(const CXXCtorInitializer &);
  static Compilation containing(const Designator &);
  static std::optional<Compilation> containing(const Token &);
  static Compilation containing(const Macro &);
  static std::optional<Compilation> containing(const VariantEntity &);

  // Generate all compilations in the index.
  static gap::generator<Compilation> in(const Index &index);

  // Return the unique ID of this compilation.
  PackedCompilationId id(void) const noexcept;

  // Returns source IR for the compilation.
  std::optional<ir::builtin::ModuleOp> ir(void) const noexcept;

  // The fragments owned by this compilation. This will be a subset of all
  // observable fragments by this compilation, because some of them may be
  // owned by a different compilation.
  gap::generator<Fragment> fragments(void) const &;

  // The files parsed by this compilation.
  gap::generator<File> files(void) const &;

  // All defines that were used in this compilation.
  gap::generator<DefineMacroDirective> defines(void) const &;

  // All builtin defines that were used in this compilation.
  gap::generator<DefineMacroDirective> builtin_defines(void) const &;

  // All command-line defines that were used in this compilation.
  gap::generator<DefineMacroDirective> command_line_defines(void) const &;

  // All written (in code) defines that were used in this compilation.
  gap::generator<DefineMacroDirective> written_defines(void) const &;

  // The main source file of this compilation.
  File main_source_file(void) const noexcept;

  // The path of the main source file for this job. This should be one of the
  // paths in teh `main_source_file().paths()` list.
  std::filesystem::path main_source_file_path(void) const noexcept;

  // Path of the compiler's executable.
  std::filesystem::path compiler_executable_path(void) const noexcept;

  // Path of the compiler's installation directory. The compiler uses this
  // when locating runtime libraries.
  std::filesystem::path compiler_installation_directory(void) const noexcept;

  // Path of the working directory in which this compilation was executed.
  std::filesystem::path working_directory(void) const noexcept;

  // Path of the system root directory. This is relevant to cross-compilations,
  // where sometimes one will instruct the compiler to treat something as an
  // alternate system root.
  std::filesystem::path system_root_directory(void) const noexcept;

  // Path of the system root directory for include resolution.
  std::filesystem::path system_root_directory_include_path(void) const noexcept;

  // Path of the compiler's resource directory. This is where things like
  // `stdarg.h` come from.
  std::filesystem::path resource_directory(void) const noexcept;

  // The target triple used by the compiler. This selects the target
  // architecture, operating system, platform, etc.
  std::string_view target_triple(void) const noexcept;

  // The auxiliary target triple used by the compiler. This selects sub-target
  // features, e.g. for a GPU.
  std::optional<std::string_view> auxiliary_target_triple(void) const noexcept;

  // Arguments to this compile command.
  gap::generator<std::string_view> arguments(void) const &;

  // List of system include directories that influenced parsing. These can be
  // built-in or specified with command-line options like `-isystem /path`.
  gap::generator<std::pair<IncludePathLocation, std::filesystem::path>>
  system_include_directories(void) const &;

  // List of system include directories that influenced parsing. These are
  // usually specified with command-line options like `-I /path`.
  gap::generator<std::pair<IncludePathLocation, std::filesystem::path>>
  user_include_directories(void) const &;

  // List of framework directories that influenced parsing. These are relevant
  // on macOS.
  gap::generator<std::pair<IncludePathLocation, std::filesystem::path>>
  framework_directories(void) const &;
};

}  // namespace mx
