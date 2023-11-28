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

#include <multiplier/RPC.capnp.h>

#include "Types.h"

#pragma GCC visibility push(hidden)
namespace mx {
namespace {
static const capnp::ReaderOptions kOptions = {
  .traversalLimitInWords = ~0ull,
  .nestingLimit = 64
};
}  // namespace

class EntityProvider;

// Base class for a serialized entity, taken from the database.
template <typename Root>
class EntityImpl {
 private:
  // Stores the Cap'n-Proto serialized data.;
  const kj::Array<capnp::word> data;
  capnp::FlatArrayMessageReader message;

  using Reader = typename Root::Reader;

 public:

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  const std::shared_ptr<EntityProvider> ep;

  // The reader used to read all things from inside of this entity.
  const Reader reader;

  explicit EntityImpl(std::shared_ptr<EntityProvider> ep_,
                      kj::Array<capnp::word> data_)
      : data(kj::mv(data_)),
        message(data, kOptions),
        ep(std::move(ep_)),
        reader(message.getRoot<Root>()) {}
};

}  // namespace mx
#pragma GCC visibility pop
