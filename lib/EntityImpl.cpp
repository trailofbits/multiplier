// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <atomic>
#include <cassert>
#include <iostream>
#include <multiplier/Compress.h>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <set>

#include "Entity.h"

namespace mx {
namespace {
static const capnp::ReaderOptions kOptions = {
  .traversalLimitInWords = ~0ull,
  .nestingLimit = 64
};
}  // namespace

EntityImpl::EntityImpl(std::shared_ptr<EntityProvider> ep_, std::string data_)
    : data(std::move(data_)),
      message(
          capnp::arrayPtr(
              reinterpret_cast<const capnp::word *>(data.data()),
              data.size()),
          kOptions),
      ep(std::move(ep_)) {}

}  // namespace mx
