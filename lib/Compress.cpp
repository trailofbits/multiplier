// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Compress.h>

#include <zlib.h>

#include <algorithm>

namespace mx {

Result<std::string, std::error_code> TryCompress(std::string_view input) {
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

Result<std::string, std::error_code>
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

}  // namespace mx
