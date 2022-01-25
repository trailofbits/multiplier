// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <memory>
#include <mutex>

namespace mx {

class BloomFilter {
 private:
  class BitSet;

  std::mutex bits_lock;
  std::unique_ptr<BitSet> bits;

 public:
  BloomFilter(void);
  ~BloomFilter(void);

  // Returns `true` if `hash` appears to be present in the filter.
  bool TestAndSet(uint64_t hash);
};

}  // namespace mx
