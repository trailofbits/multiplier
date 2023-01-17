// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Compress.h>

#include <functional>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <string>

namespace capnp {
class MessageBuilder;
class PackedMessageReader;
}  // namespace capnp
namespace mx {

// Compress a message.
std::string CompressedMessage(capnp::MessageBuilder &message);

void WithUncompressedMessageImpl(std::string data,
    std::function<void(capnp::PackedMessageReader &)> cb);

// Call `cb` with a `T::Reader` as an argument.
template <typename T, typename C>
void WithUncompressedMessage(std::string data, C cb) {
  WithUncompressedMessageImpl(
      std::move(data),
      [cb = std::move(cb)] (capnp::PackedMessageReader &reader) {
        cb(reader.getRoot<T>());
      });
}

}  // namespace mx
