// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Interpret/ConcreteMemory.h>

#include <cassert>
#include <cstring>

namespace mx::ir::interpret {

static constexpr uint64_t kMask32 = 0xFFFFFFFFull;

ConcreteMemory::ConcreteMemory(uint8_t address_width, uint64_t base_address)
    : address_width_(address_width),
      next_alloc_(base_address) {
  assert((address_width_ == 4 || address_width_ == 8) &&
         "address_width must be 4 or 8");
  if (address_width_ == 4) {
    next_alloc_ &= kMask32;
  }
}

uint64_t ConcreteMemory::Allocate(uint64_t size_bytes, uint64_t align_bytes) {
  if (size_bytes == 0) {
    size_bytes = 8;
  }
  if (align_bytes == 0) {
    align_bytes = 8;
  }

  // Align next_alloc_ up to align_bytes.
  uint64_t mask = align_bytes - 1u;
  next_alloc_ = (next_alloc_ + mask) & ~mask;

  uint64_t base = next_alloc_;
  next_alloc_ += size_bytes;

  if (address_width_ == 4) {
    base &= kMask32;
    next_alloc_ &= kMask32;
  }

  regions_[base] = Region{base, size_bytes, false, false};
  backing_[base].resize(size_bytes, 0);

  return base;
}

void ConcreteMemory::Free(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    it->second.freed = true;
  }
}

const ConcreteMemory::Region *ConcreteMemory::FindRegion(
    uint64_t address) const {
  // Fast path: exact base address match.
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    return &it->second;
  }

  // Slow path: scan for containing region.
  for (auto &[base, region] : regions_) {
    if (address >= region.base && address < region.base + region.size) {
      return &region;
    }
  }
  return nullptr;
}

ConcreteMemory::Region *ConcreteMemory::FindRegion(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    return &it->second;
  }

  for (auto &[base, region] : regions_) {
    if (address >= region.base && address < region.base + region.size) {
      return &region;
    }
  }
  return nullptr;
}

uint8_t *ConcreteMemory::GetBytes(uint64_t region_base, uint64_t offset) {
  auto it = backing_.find(region_base);
  assert(it != backing_.end() && "backing store missing for region");
  assert(offset < it->second.size() && "offset out of bounds");
  return it->second.data() + offset;
}

const uint8_t *ConcreteMemory::GetBytes(uint64_t region_base,
                                        uint64_t offset) const {
  auto it = backing_.find(region_base);
  assert(it != backing_.end() && "backing store missing for region");
  assert(offset < it->second.size() && "offset out of bounds");
  return it->second.data() + offset;
}

bool ConcreteMemory::Read(uint64_t address, void *dest, uint32_t size) {
  const Region *region = FindRegion(address);
  if (!region || region->freed) {
    std::memset(dest, 0, size);
    return false;
  }

  uint64_t offset = address - region->base;

  // Auto-grow if the read extends past the current backing.
  if (offset + size > region->size && auto_grow_) {
    uint64_t new_size = offset + size;
    auto &r = regions_[region->base];
    r.size = new_size;
    backing_[region->base].resize(new_size, 0);
    region = &r;
  }

  auto bit = backing_.find(region->base);
  if (bit == backing_.end() || offset + size > bit->second.size()) {
    std::memset(dest, 0, size);
    return false;
  }

  std::memcpy(dest, bit->second.data() + offset, size);
  return true;
}

bool ConcreteMemory::WritePointer(uint64_t address, uint64_t pointer_value) {
  // Write raw bytes first (this clears any stale shadow), then set the
  // new shadow entry so ReadPointer can recover the pointer identity.
  bool ok = Write(address, &pointer_value, sizeof(pointer_value));
  pointer_shadow_[address] = Pointer(pointer_value);
  return ok;
}

bool ConcreteMemory::ReadPointer(uint64_t address, uint64_t &pointer_value) {
  auto it = pointer_shadow_.find(address);
  if (it != pointer_shadow_.end()) {
    pointer_value = ConcreteAddress(it->second);
    return true;
  }
  return false;
}

bool ConcreteMemory::Write(uint64_t address, const void *src, uint32_t size) {
  // Clear pointer shadow: a raw write overwrites any pointer provenance.
  pointer_shadow_.erase(address);

  Region *region = FindRegion(address);
  if (!region || region->freed) {
    return false;
  }

  uint64_t offset = address - region->base;

  // Auto-grow if the write extends past the current region.
  if (offset + size > region->size && auto_grow_) {
    uint64_t new_size = offset + size;
    region->size = new_size;
    backing_[region->base].resize(new_size, 0);
  }

  if (offset + size > region->size) {
    return false;
  }

  std::memcpy(backing_[region->base].data() + offset, src, size);
  return true;
}

bool ConcreteMemory::Memset(uint64_t address, uint8_t value, uint32_t size) {
  Region *region = FindRegion(address);
  if (!region || region->freed) {
    return false;
  }

  uint64_t offset = address - region->base;

  if (offset + size > region->size && auto_grow_) {
    uint64_t new_size = offset + size;
    region->size = new_size;
    backing_[region->base].resize(new_size, 0);
  }

  if (offset + size > region->size) {
    return false;
  }

  std::memset(backing_[region->base].data() + offset, value, size);
  return true;
}

bool ConcreteMemory::Memcpy(uint64_t dest_address, uint64_t src_address,
                            uint32_t size) {
  std::vector<uint8_t> temp(size);
  if (!Read(src_address, temp.data(), size)) {
    return false;
  }
  return Write(dest_address, temp.data(), size);
}

void ConcreteMemory::Poison(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    it->second.poisoned = true;
  }
}

void ConcreteMemory::Unpoison(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    it->second.poisoned = false;
  }
}

bool ConcreteMemory::IsPoisoned(uint64_t address) const {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    return it->second.poisoned;
  }
  return false;
}

std::unique_ptr<Memory> ConcreteMemory::Fork(void) const {
  auto copy = std::make_unique<ConcreteMemory>(address_width_, 0);
  copy->next_alloc_ = next_alloc_;
  copy->auto_grow_ = auto_grow_;
  copy->backing_ = backing_;
  copy->regions_ = regions_;
  copy->pointer_shadow_ = pointer_shadow_;
  return copy;
}

void ConcreteMemory::WritePointerShadow(uint64_t address,
                                        const Pointer &ptr) {
  pointer_shadow_[address] = ptr;
}

void ConcreteMemory::ClearPointerShadow(uint64_t address) {
  pointer_shadow_.erase(address);
}

const Pointer *ConcreteMemory::ReadPointerShadow(uint64_t address) const {
  auto it = pointer_shadow_.find(address);
  if (it != pointer_shadow_.end()) {
    return &it->second;
  }
  return nullptr;
}

}  // namespace mx::ir::interpret
