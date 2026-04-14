// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <multiplier/IR.capnp.h>
#include <multiplier/RPC.capnp.h>

namespace mx {

class FragmentImpl;
class EntityProvider;
using FragmentImplPtr = std::shared_ptr<const FragmentImpl>;

// All IR entity impls hold a reference to the containing fragment
// (keeps capnp data alive) plus the offset into the fragment's flat list.
// The pools (entityPool, intPool) are accessed via frag->reader.

class IRFunctionImpl {
 public:
  const FragmentImplPtr frag;
  const unsigned offset;
  const RawEntityId fragment_id;

  IRFunctionImpl(FragmentImplPtr frag_, unsigned offset_,
                 RawEntityId fragment_id_)
      : frag(std::move(frag_)), offset(offset_),
        fragment_id(fragment_id_) {}

  rpc::ir::Function::Reader reader() const;
  virtual ~IRFunctionImpl() = default;
};

class IRBlockImpl {
 public:
  const FragmentImplPtr frag;
  const unsigned offset;
  const RawEntityId fragment_id;

  IRBlockImpl(FragmentImplPtr frag_, unsigned offset_,
              RawEntityId fragment_id_)
      : frag(std::move(frag_)), offset(offset_),
        fragment_id(fragment_id_) {}

  rpc::ir::Block::Reader reader() const;
  virtual ~IRBlockImpl() = default;
};

class IRInstructionImpl {
 public:
  const FragmentImplPtr frag;
  const unsigned offset;
  const RawEntityId fragment_id;

  IRInstructionImpl(FragmentImplPtr frag_, unsigned offset_,
                    RawEntityId fragment_id_)
      : frag(std::move(frag_)), offset(offset_),
        fragment_id(fragment_id_) {}

  rpc::ir::Instruction::Reader reader() const;
  virtual ~IRInstructionImpl() = default;
};

class IRObjectImpl {
 public:
  const FragmentImplPtr frag;
  const unsigned offset;
  const RawEntityId fragment_id;

  IRObjectImpl(FragmentImplPtr frag_, unsigned offset_,
               RawEntityId fragment_id_)
      : frag(std::move(frag_)), offset(offset_),
        fragment_id(fragment_id_) {}

  rpc::ir::Object::Reader reader() const;
  virtual ~IRObjectImpl() = default;
};

class IRStructureImpl {
 public:
  const FragmentImplPtr frag;
  const unsigned offset;
  const RawEntityId fragment_id;

  IRStructureImpl(FragmentImplPtr frag_, unsigned offset_,
                  RawEntityId fragment_id_)
      : frag(std::move(frag_)), offset(offset_),
        fragment_id(fragment_id_) {}

  rpc::ir::Structure::Reader reader() const;
  virtual ~IRStructureImpl() = default;
};

}  // namespace mx
