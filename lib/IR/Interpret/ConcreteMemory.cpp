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

uint64_t ConcreteMemory::allocate(uint64_t size_bytes, uint64_t align_bytes) {
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

void ConcreteMemory::free(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    it->second.freed = true;
  }
}

const ConcreteMemory::Region *ConcreteMemory::find_region(
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

ConcreteMemory::Region *ConcreteMemory::find_region(uint64_t address) {
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

uint8_t *ConcreteMemory::get_bytes(uint64_t region_base, uint64_t offset) {
  auto it = backing_.find(region_base);
  assert(it != backing_.end() && "backing store missing for region");
  assert(offset < it->second.size() && "offset out of bounds");
  return it->second.data() + offset;
}

const uint8_t *ConcreteMemory::get_bytes(uint64_t region_base,
                                        uint64_t offset) const {
  auto it = backing_.find(region_base);
  assert(it != backing_.end() && "backing store missing for region");
  assert(offset < it->second.size() && "offset out of bounds");
  return it->second.data() + offset;
}

bool ConcreteMemory::read(uint64_t address, void *dest, uint32_t size) {
  const Region *region = find_region(address);
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

bool ConcreteMemory::write(uint64_t address, const void *src, uint32_t size) {
  Region *region = find_region(address);
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

bool ConcreteMemory::memset(uint64_t address, uint8_t value, uint32_t size) {
  Region *region = find_region(address);
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

bool ConcreteMemory::memcpy(uint64_t dest_address, uint64_t src_address,
                            uint32_t size) {
  std::vector<uint8_t> temp(size);
  if (!read(src_address, temp.data(), size)) {
    return false;
  }
  return write(dest_address, temp.data(), size);
}

void ConcreteMemory::poison(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    it->second.poisoned = true;
  }
}

void ConcreteMemory::unpoison(uint64_t address) {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    it->second.poisoned = false;
  }
}

bool ConcreteMemory::is_poisoned(uint64_t address) const {
  auto it = regions_.find(address);
  if (it != regions_.end()) {
    return it->second.poisoned;
  }
  return false;
}

std::unique_ptr<Memory> ConcreteMemory::fork(void) const {
  auto copy = std::make_unique<ConcreteMemory>(address_width_, 0);
  copy->next_alloc_ = next_alloc_;
  copy->auto_grow_ = auto_grow_;
  copy->backing_ = backing_;
  copy->regions_ = regions_;
  return copy;
}

}  // namespace mx::ir::interpret
