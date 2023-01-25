// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include "Compress.h"

#include <algorithm>
#include <capnp/message.h>
#include <kj/io.h>
#include <iostream>
#include <zlib.h>

namespace mx {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

std::variant<std::string, std::error_code> TryCompress(std::string_view input) {
  std::string compressed_output;
  auto source_len = static_cast<uLong>(input.size());
  auto source_data = reinterpret_cast<const Bytef *>(input.data());
  auto dest_len = compressBound(source_len);
  compressed_output.resize(static_cast<size_t>(dest_len));
  auto dest_data = reinterpret_cast<Bytef *>(&(compressed_output.front()));
  switch (compress2(dest_data, &dest_len, source_data, source_len,
                    Z_BEST_COMPRESSION)) {
    case Z_OK:
      compressed_output.resize(dest_len);
      return compressed_output;
    case Z_MEM_ERROR:
      return std::make_error_code(std::errc::not_enough_memory);
    case Z_BUF_ERROR:
      return std::make_error_code(std::errc::no_buffer_space);
    case Z_STREAM_ERROR:
      return std::make_error_code(std::errc::invalid_argument);
    default:
      return std::make_error_code(std::errc::not_supported);
  }
}

std::variant<std::string, std::error_code>
TryUncompress(std::string_view compressed_input, size_t output_size) {
  auto source_len = static_cast<uLong>(compressed_input.size());
  auto source_data = reinterpret_cast<const Bytef *>(compressed_input.data());

  std::string output;
  for (auto i = 1ull; i < 16u; ) {

    if (output_size) {
      output.resize(output_size);
      output_size = 0;
    } else {
      output.resize(compressed_input.size() << i);
      ++i;
    }

    auto dest_len = static_cast<uLong>(output.size());
    auto dest_data = reinterpret_cast<Bytef *>(&(output.front()));

    switch (uncompress(dest_data, &dest_len, source_data, source_len)) {
      case Z_OK:
        output.resize(dest_len);
        return output;
      case Z_MEM_ERROR:
        return std::make_error_code(std::errc::not_enough_memory);
      case Z_BUF_ERROR:
        continue;
      case Z_DATA_ERROR:
        return std::make_error_code(std::errc::invalid_argument);
      default:
        return std::make_error_code(std::errc::not_supported);
    }
  }
  return std::make_error_code(std::errc::no_buffer_space);
}

// Compress a message.
std::string CompressedMessage(capnp::MessageBuilder &message) {
  size_t old_size = message.sizeInWords() * sizeof(capnp::word);
  kj::VectorOutputStream os(old_size);
  capnp::writePackedMessage(os, message);
  kj::ArrayPtr<kj::byte> packed_data = os.getArray();
  auto packed_size = packed_data.size();

  std::string_view packed_data_sv(
      reinterpret_cast<const char *>(packed_data.begin()), packed_size);
  auto maybe_compressed = mx::TryCompress(packed_data_sv);
  std::string output;
  if (std::holds_alternative<std::string>(maybe_compressed)) {
    output = std::move(std::get<std::string>(maybe_compressed));
    if (output.size() >= packed_size) {
      output.clear();
      goto use_uncompressed;
    }
    output.push_back('\1');

  } else {
  use_uncompressed:
    output.reserve(packed_size + 1u);
    output.insert(output.end(), packed_data_sv.begin(), packed_data_sv.end());
    output.push_back('\0');
  }

  return output;
}

void WithUncompressedMessageImpl(std::string data,
    std::function<void(capnp::PackedMessageReader &)> cb) {
  auto begin = reinterpret_cast<const char *>(data.c_str());
  auto tag = data.back();
  data.pop_back();
  std::string_view untagged_data(begin, data.size());
  if (tag) {  // Compressed and packed.
    auto maybe_uncompressed = mx::TryUncompress(untagged_data);
    if (!std::holds_alternative<std::string>(maybe_uncompressed)) {
      return;
    }
    data = std::move(std::get<std::string>(maybe_uncompressed));
  }

  capnp::ReaderOptions options;
  options.traversalLimitInWords = ~0ull;
  kj::ArrayInputStream stream(kj::arrayPtr(
      reinterpret_cast<const kj::byte *>(&(data[0])), data.size()));
  capnp::PackedMessageReader packed_reader(stream, options);
  cb(packed_reader);
}

#pragma GCC diagnostic pop

}  // namespace mx
