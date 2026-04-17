// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <memory>

namespace mx::ir::interpret {

// Abstract memory model operating on a flat virtual address space.
//
// Implementations:
//   ConcreteMemory: bump allocator with flat byte backing store.
//   BoundsCheckingMemory: proxy that tracks regions and detects OOB/UAF.
//   COWMemory: proxy with copy-on-write for multi-path exploration.
//   DebuggerMemory: pulls pages on demand from a live session.
//   SnapshotMemory: mmaps a memory dump.
class Memory {
 public:
  virtual ~Memory(void) = default;

  // Allocate a new region. Returns the base address.
  // Returns 0 on failure.
  virtual uint64_t Allocate(uint64_t size_bytes, uint64_t align_bytes) = 0;

  // Free a previously allocated region by its base address.
  virtual void Free(uint64_t address) = 0;

  // Read raw bytes from an address.
  // Returns false if the access is invalid (unmapped, freed, etc.).
  virtual bool Read(uint64_t address, void *dest, uint32_t size) = 0;

  // Write raw bytes to an address.
  // Returns false if the access is invalid.
  virtual bool Write(uint64_t address, const void *src, uint32_t size) = 0;

  // Pointer-aware read/write. The concrete implementation stores/reads
  // the address as raw bytes (same as Write/Read with sizeof(uint64_t)).
  // A provenance-tracking proxy can additionally mark these bytes as
  // carrying pointer identity.
  virtual bool WritePointer(uint64_t address, uint64_t pointer_value);
  virtual bool ReadPointer(uint64_t address, uint64_t &pointer_value);

  // Bulk operations.
  virtual bool Memset(uint64_t address, uint8_t value, uint32_t size) = 0;
  virtual bool Memcpy(uint64_t dest_address, uint64_t src_address,
                      uint32_t size) = 0;

  // Scope-based poisoning: marks a region as temporarily inaccessible
  // (e.g., when a local variable goes out of scope). Default no-ops.
  virtual void Poison(uint64_t address) { (void) address; }
  virtual void Unpoison(uint64_t address) { (void) address; }
  virtual bool IsPoisoned(uint64_t address) const {
    (void) address;
    return false;
  }

  // Fork for multi-path exploration (COW).
  // Returns a new Memory that shares state until written.
  virtual std::unique_ptr<Memory> Fork(void) const = 0;
};

// Default implementations. WritePointer writes raw bytes; ReadPointer returns
// false (no pointer tracking). Override both in implementations that track
// pointer provenance (e.g., ConcreteMemory).
inline bool Memory::WritePointer(uint64_t address, uint64_t pointer_value) {
  return Write(address, &pointer_value, sizeof(pointer_value));
}

inline bool Memory::ReadPointer(uint64_t address, uint64_t &pointer_value) {
  (void) address;
  (void) pointer_value;
  return false;
}

}  // namespace mx::ir::interpret
