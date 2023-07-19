// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Compilation.h"

#include <multiplier/IR/MLIR/Builtin/ModuleOp.h>

#include "IR/SourceIR.h"

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

// The fragments owned by this compilation. This will be a subset of all
// observable fragments by this compilation, because some of them may be
// owned by a different compilation.
gap::generator<Fragment> Compilation::fragments(void) const & noexcept {
  co_return;  // TODO(pag): Implement me.
}

// The files parsed by this compilation.
gap::generator<File> Compilation::files(void) const & noexcept {
  co_return;  // TODO(pag): Implement me.
}

File Compilation::main_source_file(void) const noexcept {
  FileId fid(id().Unpack().file_id);
  return File(impl->ep->FileFor(impl->ep, fid));
}

// Returns source IR for the compilation.
std::optional<ir::builtin::ModuleOp> Compilation::ir(void) const noexcept {
  if (auto mlir = impl->SourceIR(); !mlir.empty()) {
    auto ir_obj = std::make_shared<const ir::SourceIRImpl>(
        id(), impl->ep, mlir);
    if (mlir::Operation *ptr = ir_obj->scope()) {
      ir::Operation op(std::move(ir_obj), ptr);
      return ir::builtin::ModuleOp::from(op);
    }
  }
  return std::nullopt;
}

}  // namespace mx
