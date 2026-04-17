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
// Supports pointer shadow tracking (which memory locations hold pointer values).
class MX_EXPORT ConcreteMemory final : public Memory {
 public:
  explicit ConcreteMemory(uint8_t address_width = 8,
                          uint64_t base_address = 0x10000);

  uint64_t Allocate(uint64_t size_bytes, uint64_t align_bytes) override;
  void Free(uint64_t address) override;
  bool Read(uint64_t address, void *dest, uint32_t size) override;
  bool Write(uint64_t address, const void *src, uint32_t size) override;
  bool Memset(uint64_t address, uint8_t value, uint32_t size) override;
  bool Memcpy(uint64_t dest_address, uint64_t src_address,
              uint32_t size) override;

  bool WritePointer(uint64_t address, uint64_t pointer_value) override;
  bool ReadPointer(uint64_t address, uint64_t &pointer_value) override;

  void Poison(uint64_t address) override;
  void Unpoison(uint64_t address) override;
  bool IsPoisoned(uint64_t address) const override;

  std::unique_ptr<Memory> Fork(void) const override;

  // Pointer shadow: tracks which memory locations hold pointer values.
  // The interpreter calls these when storing/loading pointer-typed values.
  void WritePointerShadow(uint64_t address, const Pointer &ptr);
  void ClearPointerShadow(uint64_t address);
  const Pointer *ReadPointerShadow(uint64_t address) const;

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

  // Pointer shadow map: address → stored pointer value.
  std::unordered_map<uint64_t, Pointer> pointer_shadow_;

  // Find the region containing an address. Returns nullptr if not found.
  const Region *FindRegion(uint64_t address) const;
  Region *FindRegion(uint64_t address);

  // Ensure backing store exists for a region and return a pointer to
  // the byte at the given offset within it.
  uint8_t *GetBytes(uint64_t region_base, uint64_t offset);
  const uint8_t *GetBytes(uint64_t region_base, uint64_t offset) const;
};

}  // namespace mx::ir::interpret
