// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Compress.h"

#include <capnp/message.h>
#include <glog/logging.h>
#include <kj/io.h>
#include <multiplier/Compress.h>
#include <iostream>

namespace indexer {

// Compress a message.
std::string CompressedMessage(capnp::MessageBuilder &message) {
  size_t old_size = message.sizeInWords() * sizeof(capnp::word);
  kj::VectorOutputStream os(old_size);
  capnp::writePackedMessage(os, message);
  kj::ArrayPtr<kj::byte> packed_data = os.getArray();
  auto packed_size = packed_data.size();
  CHECK_LE(packed_size, old_size);

  std::string_view packed_data_sv(
      reinterpret_cast<const char *>(packed_data.begin()), packed_size);
  auto maybe_compressed = mx::TryCompress(packed_data_sv);
  std::string output;
  if (maybe_compressed.Succeeded()) {
    output = maybe_compressed.TakeValue();
    if (output.size() >= packed_size) {
      output.clear();
      goto use_uncompressed;
    }
    output.push_back('\1');

  } else {
    LOG(ERROR)
        << "Unable to compress: "
        << maybe_compressed.TakeError().message();
  use_uncompressed:
    output.reserve(packed_size + 1u);
    output.insert(output.end(), packed_data_sv.begin(), packed_data_sv.end());
    output.push_back('\0');
  }

  return output;
}

void WithUncompressedMessageImpl(
    std::string data,
    std::function<void(capnp::PackedMessageReader &)> cb) {
  CHECK(!data.empty());
  auto begin = reinterpret_cast<const char *>(data.c_str());
  auto tag = data.back();
  data.pop_back();
  std::string_view untagged_data(begin, data.size());
  if (tag) {  // Compressed and packed.
    auto maybe_uncompressed = mx::TryUncompress(untagged_data);
    CHECK(maybe_uncompressed.Succeeded())
        << "Unable to uncompress: "
        << maybe_uncompressed.TakeError().message();

    data = maybe_uncompressed.TakeValue();
  }

  capnp::ReaderOptions options;
  options.traversalLimitInWords = ~0ull;
  kj::ArrayInputStream stream(kj::arrayPtr(
      reinterpret_cast<const kj::byte *>(&(data[0])), data.size()));
  capnp::PackedMessageReader packed_reader(stream, options);
  cb(packed_reader);
}

}  // namespace indexer
