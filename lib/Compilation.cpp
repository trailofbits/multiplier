// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Compilation.h"

#include <multiplier/Entities/IncludePathLocation.h>
#include <multiplier/Fragment.h>

#if !defined(MX_DISABLE_VAST) && !defined(__CDT_PARSER__)
#include <multiplier/IR/MLIR/Builtin/ModuleOp.h>
#include "IR/SourceIR.h"
#endif

#include "Reference.h"
#include "Token.h"

namespace mx {

CompilationImpl::~CompilationImpl(void) noexcept {}

CompilationImpl::CompilationImpl(
    EntityProviderPtr ep_, kj::Array<capnp::word> data_, RawEntityId id_)
    : EntityImpl<rpc::Compilation>(std::move(ep_), kj::mv(data_)),
      compilation_id(EntityId(id_).Extract<CompilationId>().value()) {}

std::string_view CompilationImpl::SourceIR(void) const & noexcept {
  if (reader.hasMlir()) {
    if (auto mlir = reader.getMlir(); auto size = mlir.size()) {
      return std::string_view(mlir.cStr(), size);
    }
  }
  return {};
}

PackedCompilationId Compilation::id(void) const noexcept {
  return impl->compilation_id;
}

// The compilation containing/owning a fragment.
Compilation Compilation::containing(const Fragment &frag) {
  return frag.compilation();
}

std::optional<Compilation> Compilation::containing(
    const std::optional<Fragment> &frag) {
  if (frag) {
    return Compilation::containing(frag.value());
  } else {
    return std::nullopt;
  }
}

Compilation Compilation::containing(const Decl &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const Stmt &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const Attr &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const TemplateArgument &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const TemplateParameterList &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const CXXBaseSpecifier &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const Designator &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

Compilation Compilation::containing(const Macro &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

std::optional<Compilation> Compilation::containing(const Token &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

std::optional<Compilation> Compilation::containing(
    const VariantEntity &entity) {
  return Compilation::containing(Fragment::containing(entity));
}

// The fragments owned by this compilation. This will be a subset of all
// observable fragments by this compilation, because some of them may be
// owned by a different compilation.
gap::generator<Fragment> Compilation::fragments(void) const & noexcept {
  auto ep = impl->ep;
  for (RawEntityId eid : impl->reader.getFragmentIds()) {
    if (FragmentImplPtr fptr = ep->FragmentFor(ep, eid)) {
      co_yield Fragment(std::move(fptr));
    } else {
      assert(false);
    }
  }
}

// The files parsed by this compilation.
gap::generator<File> Compilation::files(void) const & noexcept {
  auto ep = impl->ep;
  for (RawEntityId eid : impl->reader.getFileIds()) {
    if (FileImplPtr fptr = ep->FileFor(ep, eid)) {
      co_yield File(std::move(fptr));
    } else {
      assert(false);
    }
  }
}

File Compilation::main_source_file(void) const noexcept {
  FileId fid(id().Unpack().file_id);
  return File(impl->ep->FileFor(impl->ep, fid));
}

// The path of the main source file for this job. This should be one of the
// paths in teh `main_source_file().paths()` list.
std::filesystem::path Compilation::main_source_file_path(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getSourcePath();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// Path oo the compiler's executable.
std::filesystem::path
Compilation::compiler_executable_path(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getCompilerPath();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// Path of the compiler's installation directory. The compiler uses this
// when locating runtime libraries.
std::filesystem::path
Compilation::compiler_installation_directory(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getInstallationDirectory();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// Path of the working directory in which this compilation was executed.
std::filesystem::path Compilation::working_directory(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getWorkingDirectory();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// Path of the system root directory. This is relevant to cross-compilations,
// where sometimes one will instruct the compiler to treat something as an
// alternate system root.
std::filesystem::path
Compilation::system_root_directory(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getSystemRootDirectory();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// Path of the system root directory for include resolution.
std::filesystem::path
Compilation::system_root_directory_include_path(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getSystemRootIncludeDirectory();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// Path of the compiler's resource directory. This is where things like
// `stdarg.h` come from.
std::filesystem::path
Compilation::resource_directory(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getResourceDirectory();
  std::string_view fp_view(fp.cStr(), fp.size());
  return fp_view;
}

// The target triple used by the compiler. This selects the target
// architecture, operating system, platform, etc.
std::string_view Compilation::target_triple(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getTargetTriple();
  return std::string_view(fp.cStr(), fp.size());
}

// The auxiliary target triple used by the compiler. This selects sub-target
// features, e.g. for a GPU.
std::optional<std::string_view>
Compilation::auxiliary_target_triple(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  capnp::Text::Reader fp = reader.getAuxTargetTriple();
  if (fp.size()) {
    return std::string_view(fp.cStr(), fp.size());
  } else {
    return std::nullopt;
  }
}

// Arguments to this compile command.
gap::generator<std::string_view> Compilation::arguments(void) const noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  for (capnp::Text::Reader arg : reader.getArguments()) {
    co_yield std::string_view(arg.cStr(), arg.size());
  }
}

namespace {

inline static std::pair<IncludePathLocation, std::filesystem::path>
ReadIncludePath(rpc::IncludePath::Reader ip) {
  IncludePathLocation ipl = IncludePathLocation::ABSOLUTE;
  switch (ip.getLocation()) {
    case rpc::IncludePathLocation::ABSOLUTE:
      ipl = IncludePathLocation::ABSOLUTE;
      break;
    case rpc::IncludePathLocation::SYSROOT_RELATIVE:
      ipl = IncludePathLocation::SYSROOT_RELATIVE;
      break;
  }

  capnp::Text::Reader fp = ip.getDirectory();
  std::string_view fp_view(fp.cStr(), fp.size());

  return std::pair<IncludePathLocation, std::filesystem::path>(ipl, fp);
}

}  // namespace

// List of system include directories that influenced parsing. These can be
// built-in or specified with command-line options like `-isystem /path`.
gap::generator<std::pair<IncludePathLocation, std::filesystem::path>>
Compilation::system_include_directories(void) const & noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  for (rpc::IncludePath::Reader ip : reader.getSystemIncludePaths()) {
    co_yield ReadIncludePath(std::move(ip));
  }
}

// List of system include directories that influenced parsing. These are
// usually specified with command-line options like `-I /path`.
gap::generator<std::pair<IncludePathLocation, std::filesystem::path>>
Compilation::user_include_directories(void) const & noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  for (rpc::IncludePath::Reader ip : reader.getUserIncludePaths()) {
    co_yield ReadIncludePath(std::move(ip));
  }
}

// List of framework directories that influenced parsing. These are relevant
// on macOS.
gap::generator<std::pair<IncludePathLocation, std::filesystem::path>>
Compilation::framework_directories(void) const & noexcept {
  rpc::CompileCommand::Reader reader = impl->reader.getCommand();
  for (rpc::IncludePath::Reader ip : reader.getFrameworkPaths()) {
    co_yield ReadIncludePath(std::move(ip));
  }
}

// Returns source IR for the compilation.
std::optional<ir::builtin::ModuleOp> Compilation::ir(void) const noexcept {
#if !defined(MX_DISABLE_VAST) && !defined(__CDT_PARSER__)
  if (auto mlir = impl->SourceIR(); !mlir.empty()) {
    auto ir_obj = std::make_shared<const ir::SourceIRImpl>(
        id(), impl->ep, mlir);
    if (mlir::Operation *ptr = ir_obj->scope()) {
      ir::Operation op(std::move(ir_obj), ptr);
      return ir::builtin::ModuleOp::from(op);
    }
  }
#endif

  return std::nullopt;
}

// References to this compilation.
gap::generator<Reference> Compilation::references(void) const & {
  return References(impl->ep, id().Pack());
}

}  // namespace mx
