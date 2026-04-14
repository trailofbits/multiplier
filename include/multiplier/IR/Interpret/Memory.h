// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Value.h"
#include <cstdint>
#include <optional>

namespace mx::ir::interpret {

// Abstract memory model. The interpreter handles endianness mechanics
// and calls Read/Write on this interface. Implementations own the storage.
//
// ConcreteMemory: flat byte arrays per object.
// ShadowMemory: tracks initialization, taint, allocation state.
// COW memory: O(1) fork for multi-path exploration.
class Memory {
 public:
  virtual ~Memory(void) = default;

  // Allocate a new memory object. Returns the object ID.
  virtual uint32_t Allocate(uint32_t size_bytes, uint32_t align_bytes) = 0;

  // Free a previously allocated object.
  virtual void Free(uint32_t object_id) = 0;

  // Read raw bytes from an object at an offset.
  // Returns false if the access is out of bounds or the object is freed.
  virtual bool Read(uint32_t object_id, int64_t offset,
                    void *dest, uint32_t size) = 0;

  // Write raw bytes to an object at an offset.
  virtual bool Write(uint32_t object_id, int64_t offset,
                     const void *src, uint32_t size) = 0;

  // Bulk operations.
  virtual bool Memset(uint32_t object_id, int64_t offset,
                      uint8_t value, uint32_t size) = 0;
  virtual bool Memcpy(uint32_t dest_obj, int64_t dest_offset,
                      uint32_t src_obj, int64_t src_offset,
                      uint32_t size) = 0;

  // Query object metadata.
  virtual uint32_t ObjectSize(uint32_t object_id) const = 0;
  virtual bool IsAllocated(uint32_t object_id) const = 0;

  // Fork for multi-path exploration (COW).
  // Returns a new Memory that shares state until written.
  virtual std::unique_ptr<Memory> Fork(void) const = 0;
};

}  // namespace mx::ir::interpret
