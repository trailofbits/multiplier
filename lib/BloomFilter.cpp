// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/BloomFilter.h>

#include <bitset>

namespace mx {

// 2MiB worth of bits, 24 bits.
static constexpr uint64_t kNumBits = (1ull << 20u) * 8u * 2u;

class BloomFilter::BitSet : public std::bitset<kNumBits> {};

BloomFilter::BloomFilter(void)
    : bits(new BitSet) {}

BloomFilter::~BloomFilter(void) {}

bool BloomFilter::TestAndSet(uint64_t hash) {
  auto index0 = hash % kNumBits;
  auto index1 = (hash >> 24u) % kNumBits;
  auto index2 = (hash >> 32u) % kNumBits;
  std::unique_lock<std::mutex> locker(bits_lock);
  auto new0 = bits->test(index0);
  bits->set(index0);
  auto new1 = bits->test(index1);
  bits->set(index1);
  auto new2 = bits->test(index2);
  bits->set(index2);
  return new0 & new1 & new2;
}

}  // namespace indexer
