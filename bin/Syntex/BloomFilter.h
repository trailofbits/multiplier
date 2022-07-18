// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Serialize.h>

namespace syntex {

// This is a very very small bloom filter that we'll use to track "features"
// of fragments, i.e. whether or not a fragment might have a match for a
// particular rule.
struct SmallBloomFilter {
  static constexpr auto kNumWords = 4u;

  uint64_t words[kNumWords];

  SmallBloomFilter(void) {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      words[i] = 0;
    }
  }

  void Add(uint64_t hash) {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      words[i] |= 1ull << (hash & 0x3Full);
      hash >>= 6u;
    }
  }

  void Add(const SmallBloomFilter &that) {
    for (auto i = 0u; i < kNumWords; ++i)
      words[i] |= that.words[i];
  }

  bool Contains(const SmallBloomFilter &that) const noexcept {
    _Pragma("unroll") for (auto i = 0u; i < kNumWords; ++i) {
      if ((words[i] & that.words[i]) != that.words[i]) {
        return false;
      }
    }
    return true;
  }
};

} // namespace syntex

#include <iostream>

namespace mx {

// Serialize a small bloom filter.
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, syntex::SmallBloomFilter> {

  static constexpr bool kIsFixedSize = true;

  MX_FLATTEN static void Write(Writer &writer, const syntex::SmallBloomFilter &bf) {
    for (auto word : bf.words) {
      Serializer<NullReader, Writer, uint64_t>::Write(writer, word);
    }
  }

  MX_FLATTEN static void Read(Reader &reader, syntex::SmallBloomFilter &bf) {
    for (auto &word : bf.words) {
      Serializer<Reader, NullWriter, uint64_t>::Read(reader, word);
    }
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return sizeof(syntex::SmallBloomFilter);
  }
};

} // namespace mx
