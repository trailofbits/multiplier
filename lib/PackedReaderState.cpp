// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <atomic>
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <set>

#include "API.h"

namespace mx {

PackedReaderState::PackedReaderState(const std::string& data) : storage(data) {
  capnp::ReaderOptions options;
  options.traversalLimitInWords = ~0ull;
  stream.emplace(kj::arrayPtr(
      reinterpret_cast<const kj::byte *>(&(storage[0])), storage.size()));
  packed_reader.emplace(stream.value(), options);
}

}  // namespace mx
