// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Memory.h"
#include "Value.h"
#include <unordered_map>
#include <vector>

namespace mx::ir::interpret {

// Concrete memory implementation: bump-allocator with flat byte backing store.
// Memory is just bytes — no pointer provenance tracking. The policy layer
// communicates intent (pointer vs scalar) through MemAccessHint and the
// write_pointer/read_pointer methods, but the memory itself is type-agnostic.
class MX_EXPORT ConcreteMemory final : public Memory {
 public:
  explicit ConcreteMemory(uint8_t address_width = 8,
                          uint64_t base_address = 0x10000);

  uint64_t allocate(uint64_t size_bytes, uint64_t align_bytes) override;
  void free(uint64_t address) override;

  // Pre-allocate a region at a chosen virtual address. Used by symbolic
  // execution layouts that mimic a real process map (named globals at
  // fixed addresses). Returns true on success, false if the request
  // overlaps an existing live region or violates alignment.
  // Bumps next_alloc_ past the placed region so future bump-allocations
  // don't collide.
  bool place_at(uint64_t address, uint64_t size_bytes, uint64_t align_bytes);

  bool read(uint64_t address, void *dest, uint32_t size) override;
  bool write(uint64_t address, const void *src, uint32_t size) override;
  bool memset(uint64_t address, uint8_t value, uint32_t size) override;
  bool memcpy(uint64_t dest_address, uint64_t src_address,
              uint32_t size) override;

  void poison(uint64_t address) override;
  void unpoison(uint64_t address) override;
  bool is_poisoned(uint64_t address) const override;

  std::unique_ptr<Memory> fork(void) const override;

  // Auto-grow: extend a region if a write exceeds its bounds.
  // Used for VLA-like objects with unknown compile-time size.
  void SetAutoGrow(bool enabled) { auto_grow_ = enabled; }

 private:
  struct Region {
    uint64_t base{0};
    uint64_t size{0};
    bool freed{false};
    bool poisoned{false};
  };

  uint8_t address_width_;
  uint64_t next_alloc_;
  bool auto_grow_{true};

  // Flat byte backing store: address → bytes.
  // Using a map of regions to support sparse address spaces.
  std::unordered_map<uint64_t, std::vector<uint8_t>> backing_;

  // Region metadata keyed by base address.
  std::unordered_map<uint64_t, Region> regions_;

  // Find the region containing an address. Returns nullptr if not found.
  const Region *find_region(uint64_t address) const;
  Region *find_region(uint64_t address);

  // Ensure backing store exists for a region and return a pointer to
  // the byte at the given offset within it.
  uint8_t *get_bytes(uint64_t region_base, uint64_t offset);
  const uint8_t *get_bytes(uint64_t region_base, uint64_t offset) const;
};

}  // namespace mx::ir::interpret
