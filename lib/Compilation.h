// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Frontend/Compilation.h>
#include <mutex>

#include "EntityProvider.h"

namespace mx {
namespace ir {
class SourceIRImpl;
}  // namespace ir

class CompilationImpl final : public EntityImpl<rpc::Compilation> {
 private:
  friend class ir::SourceIRImpl;

  mutable std::mutex source_ir_lock;
  mutable std::weak_ptr<const ir::SourceIRImpl> source_ir;

 public:
  using Ptr = CompilationImplPtr;
  using WeakPtr = WeakCompilationImplPtr;

  // NOTE(pag): This is a packed file id / entity ID representation, it
  //            is the raw ID that would go into a `FileId`.
  const PackedCompilationId compilation_id;

  ~CompilationImpl(void) noexcept;

  explicit CompilationImpl(EntityProviderPtr ep_, kj::Array<capnp::word> data_,
                           RawEntityId id_);

  // Return the source ir for the compilation.
  std::string_view SourceIR(void) const & noexcept;

  // Return a pointer to the source IR object.
  std::shared_ptr<const ir::SourceIRImpl> SourceIRPtr(
      PackedCompilationId id) const & noexcept;
};

}  // namespace mx
