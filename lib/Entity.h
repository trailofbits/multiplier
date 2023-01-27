// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <capnp/message.h>
#include <capnp/serialize.h>
#include <memory>
#include <string>
#include <multiplier/Types.h>

namespace mx {

class EntityProvider;

// Base class for a serialized entity, taken from the database.
class EntityImpl {
 private:

  // Stores the Cap'n-Proto serialized data.
  const std::string data;
  capnp::FlatArrayMessageReader message;

 public:

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const std::shared_ptr<EntityProvider> ep;

  explicit EntityImpl(std::shared_ptr<EntityProvider> ep_, std::string data_);

  template <typename T>
  inline auto Reader(void) & noexcept -> typename T::Reader {
    return message.getRoot<T>();
  }
};

class OffsetEntityImpl : public EntityImpl {
 public:
  const PackedFragmentId fragment_id;
  const EntityOffset offset;

  explicit inline OffsetEntityImpl(std::shared_ptr<EntityProvider> ep_,
                                   std::string data_,
                                   PackedFragmentId fragment_id_,
                                   EntityOffset offset_)
      : EntityImpl(std::move(ep_), std::move(data_)),
        fragment_id(fragment_id_),
        offset(offset_) {}
};

}  // namespace mx
