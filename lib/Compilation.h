// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Frontend/Compilation.h>

#include "EntityProvider.h"

namespace mx {

class CompilationImpl final : public EntityImpl<rpc::Compilation> {
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
};

}  // namespace mx
