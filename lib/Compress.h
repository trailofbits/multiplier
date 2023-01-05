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
std::string CompressedMessage(
    const char *what, capnp::MessageBuilder &message);

void WithUncompressedMessageImpl(
    const char *what, std::string data,
    std::function<void(capnp::PackedMessageReader &)> cb);

// Call `cb` with a `T::Reader` as an argument.
template <typename T, typename C>
void WithUncompressedMessage(
    const char *what, std::string data, C cb) {
  WithUncompressedMessageImpl(
      what,
      std::move(data),
      [cb = std::move(cb)] (capnp::PackedMessageReader &reader) {
        cb(reader.getRoot<T>());
      });
}

}  // namespace mx
