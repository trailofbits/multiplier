// Copyright 2021, Trail of Bits, Inc. All rights reserved.

#pragma once

#include <array>
#include <capnp/message.h>
#include <cstdint>
#include <kj/array.h>
#include <kj/string.h>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "Compiler.h"
#include "Endian.h"
#include "Int.h"

namespace mx {

// Represents an empty key/value.
struct Empty {};

// An unserializer that always returns default-initialzied values.
struct NullReader {
 public:
  MX_ALWAYS_INLINE uint32_t ReadSize(void) {
    return {};
  }
  MX_ALWAYS_INLINE double ReadF64(void) {
    return {};
  }
  MX_ALWAYS_INLINE float ReadF32(void) {
    return {};
  }
  MX_ALWAYS_INLINE uint64_t ReadU64(void) {
    return {};
  }
  MX_ALWAYS_INLINE uint32_t ReadU32(void) {
    return {};
  }
  MX_ALWAYS_INLINE uint16_t ReadU16(void) {
    return {};
  }
  MX_ALWAYS_INLINE uint8_t ReadU8(void) {
    return {};
  }
  MX_ALWAYS_INLINE bool ReadB(void) {
    return {};
  }
  MX_ALWAYS_INLINE int64_t ReadI64(void) {
    return {};
  }
  MX_ALWAYS_INLINE uint32_t ReadI32(void) {
    return {};
  }
  MX_ALWAYS_INLINE int16_t ReadI16(void) {
    return {};
  }
  MX_ALWAYS_INLINE int8_t ReadI8(void) {
    return {};
  }
  MX_ALWAYS_INLINE void Skip(uint32_t) {
  }
};

// A serializer that writes out nothing.
struct NullWriter {
 public:
  MX_ALWAYS_INLINE uint8_t *Current(void) const noexcept {
    return nullptr;
  }
  MX_ALWAYS_INLINE uint8_t *WriteSize(uint32_t) noexcept {
    return nullptr;
  }
  MX_ALWAYS_INLINE uint8_t *WriteF64(double) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteF32(float) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteU64(uint64_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteU32(uint32_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteU16(uint16_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteU8(uint8_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteB(bool) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteI64(int64_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteI32(int32_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteI16(int16_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *WriteI8(int8_t) noexcept { return nullptr; }
  MX_ALWAYS_INLINE uint8_t *Skip(uint32_t) noexcept {
    return nullptr;
  }
  MX_ALWAYS_INLINE void EnterFixedSizeComposite(uint32_t) noexcept {}
  MX_ALWAYS_INLINE void EnterVariableSizedComposite(uint32_t) noexcept {}
  MX_ALWAYS_INLINE void ExitComposite(void) noexcept {}
};

// A writer for writing bytes into a continuous backing buffer. No bounds
// checking is performed.
template <typename Self>
class ByteWriter {
 public:
  MX_ALWAYS_INLINE explicit ByteWriter(char *write_ptr_)
      : write_ptr(reinterpret_cast<uint8_t *>(write_ptr_)) {}

  MX_ALWAYS_INLINE explicit ByteWriter(uint8_t *write_ptr_)
      : write_ptr(write_ptr_) {}

  MX_ALWAYS_INLINE uint8_t *Current(void) const noexcept {
    return write_ptr;
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE
  void WriteF64(double d) noexcept {
    alignas(double) uint8_t data[sizeof(double)];
    *(new (data) double) = d;
    auto self = static_cast<Self *>(this);

    // Serialize data to big-endian byte order for lexicographic sorting
    // using `memcmp`.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      self->WriteU8(data[0]);
      self->WriteU8(data[1]);
      self->WriteU8(data[2]);
      self->WriteU8(data[3]);
      self->WriteU8(data[4]);
      self->WriteU8(data[5]);
      self->WriteU8(data[6]);
      self->WriteU8(data[7]);

    } else {
      self->WriteU8(data[7]);
      self->WriteU8(data[6]);
      self->WriteU8(data[5]);
      self->WriteU8(data[4]);
      self->WriteU8(data[3]);
      self->WriteU8(data[2]);
      self->WriteU8(data[1]);
      self->WriteU8(data[0]);
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteF32(float f) noexcept {
    alignas(float) uint8_t data[sizeof(float)];
    *(new (data) float) = f;
    auto self = static_cast<Self *>(this);

    // Serialize data to big-endian byte order for lexicographic sorting
    // using `memcmp`.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      self->WriteU8(data[0]);
      self->WriteU8(data[1]);
      self->WriteU8(data[2]);
      self->WriteU8(data[3]);

    } else {
      self->WriteU8(data[3]);
      self->WriteU8(data[2]);
      self->WriteU8(data[1]);
      self->WriteU8(data[0]);
    }
  }

  [[gnu::hot]] MX_ALWAYS_INLINE void WriteU64(uint64_t q) noexcept {
    alignas(uint64_t) uint8_t data[sizeof(uint64_t)];
    *(new (data) uint64_t) = q;
    auto self = static_cast<Self *>(this);

    // Serialize data to big-endian byte order for lexicographic sorting
    // using `memcmp`.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      self->WriteU8(data[0]);
      self->WriteU8(data[1]);
      self->WriteU8(data[2]);
      self->WriteU8(data[3]);
      self->WriteU8(data[4]);
      self->WriteU8(data[5]);
      self->WriteU8(data[6]);
      self->WriteU8(data[7]);

    } else {
      self->WriteU8(data[7]);
      self->WriteU8(data[6]);
      self->WriteU8(data[5]);
      self->WriteU8(data[4]);
      self->WriteU8(data[3]);
      self->WriteU8(data[2]);
      self->WriteU8(data[1]);
      self->WriteU8(data[0]);
    }
  }

  [[gnu::hot]] MX_ALWAYS_INLINE void WriteU32(uint32_t d) noexcept {
    alignas(uint32_t) uint8_t data[sizeof(uint32_t)];
    *(new (data) uint32_t) = d;
    auto self = static_cast<Self *>(this);

    // Serialize data to big-endian byte order for lexicographic sorting
    // using `memcmp`.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      self->WriteU8(data[0]);
      self->WriteU8(data[1]);
      self->WriteU8(data[2]);
      self->WriteU8(data[3]);

    } else {
      self->WriteU8(data[3]);
      self->WriteU8(data[2]);
      self->WriteU8(data[1]);
      self->WriteU8(data[0]);
    }
  }

  [[gnu::hot]] MX_ALWAYS_INLINE void WriteU16(uint16_t h) noexcept {
    alignas(uint16_t) uint8_t data[sizeof(uint16_t)];
    *(new (data) uint16_t) = h;
    auto self = static_cast<Self *>(this);

    // Serialize data to big-endian byte order for lexicographic sorting
    // using `memcmp`.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      self->WriteU8(data[0]);
      self->WriteU8(data[1]);

    } else {
      self->WriteU8(data[1]);
      self->WriteU8(data[0]);
    }
  }

  [[gnu::hot]] MX_ALWAYS_INLINE void WriteU8(uint8_t b) noexcept {
    *write_ptr++ = b;
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteI64(int64_t q) noexcept {
    WriteU64(static_cast<uint64_t>(q));
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteI32(int32_t w) noexcept {
    WriteU32(static_cast<uint32_t>(w));
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteI16(int16_t h) noexcept {
    WriteU16(static_cast<uint16_t>(h));
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteI8(int8_t b) noexcept {
    WriteU8(static_cast<uint8_t>(b));
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteB(bool b) noexcept {
    WriteU8(static_cast<uint8_t>(!!b));
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE void WriteSize(uint32_t d) noexcept {
    WriteU32(d);
  }

  [[gnu::hot]] MX_ALWAYS_INLINE void Skip(uint32_t num_bytes) noexcept {
    write_ptr += num_bytes;
  }

  MX_ALWAYS_INLINE void EnterFixedSizeComposite(uint32_t) {}
  MX_ALWAYS_INLINE void EnterVariableSizedComposite(uint32_t) {}
  MX_ALWAYS_INLINE void ExitComposite(void) {}

  uint8_t *write_ptr{nullptr};
};

// A writer for writing bytes into a continuous backing buffer. No bounds
// checking is performed.
class UnsafeByteWriter : public ByteWriter<UnsafeByteWriter> {
 public:
  using ByteWriter<UnsafeByteWriter>::WriteU8;

  MX_ALWAYS_INLINE explicit UnsafeByteWriter(std::string &data)
      : ByteWriter(&(data[0])) {}

  MX_ALWAYS_INLINE explicit UnsafeByteWriter(char *write_ptr_)
      : ByteWriter(write_ptr_) {}

  MX_ALWAYS_INLINE explicit UnsafeByteWriter(uint8_t *write_ptr_)
      : ByteWriter(write_ptr_) {}
};

template <typename Self>
class ByteReader {
 public:
  explicit ByteReader(const char *read_ptr_) noexcept
      : read_ptr(reinterpret_cast<const uint8_t *>(read_ptr_)) {}

  explicit ByteReader(const uint8_t *read_ptr_) noexcept
      : read_ptr(read_ptr_) {}

  [[gnu::hot]] MX_ALWAYS_INLINE double ReadF64(void) noexcept {
    alignas(double) uint8_t data[8u];
    auto self = static_cast<Self *>(this);

    // Data is serialized in big-endian byte order, we need to deserialize it
    // into the host byte order.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      data[0] = self->ReadU8();
      data[1] = self->ReadU8();
      data[2] = self->ReadU8();
      data[3] = self->ReadU8();
      data[4] = self->ReadU8();
      data[5] = self->ReadU8();
      data[6] = self->ReadU8();
      data[7] = self->ReadU8();

    // Host is little endian, serialized data is big endian, so the first byte
    // read is the high-order byte, so we need to store it at `data[7]`, as
    // `data[0]` is our low-order byte.
    } else {
      data[7] = self->ReadU8();
      data[6] = self->ReadU8();
      data[5] = self->ReadU8();
      data[4] = self->ReadU8();
      data[3] = self->ReadU8();
      data[2] = self->ReadU8();
      data[1] = self->ReadU8();
      data[0] = self->ReadU8();
    }

    return *(new (data) double);
  }

  [[gnu::hot]] MX_ALWAYS_INLINE float ReadF32(void) noexcept {
    alignas(float) uint8_t data[4u];
    auto self = static_cast<Self *>(this);

    // Data is serialized in big-endian byte order, we need to deserialize it
    // into the host byte order.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      data[0] = self->ReadU8();
      data[1] = self->ReadU8();
      data[2] = self->ReadU8();
      data[3] = self->ReadU8();

    // Host is little endian, serialized data is big endian, so the first byte
    // read is the high-order byte, so we need to store it at `data[3]`, as
    // `data[0]` is our low-order byte.
    } else {
      data[3] = self->ReadU8();
      data[2] = self->ReadU8();
      data[1] = self->ReadU8();
      data[0] = self->ReadU8();
    }

    return *(new (data) float);
  }

  [[gnu::hot]] MX_ALWAYS_INLINE uint64_t ReadU64(void) noexcept {
    alignas(uint64_t) uint8_t data[8u];
    auto self = static_cast<Self *>(this);

    // Data is serialized in big-endian byte order, we need to deserialize it
    // into the host byte order.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      data[0] = self->ReadU8();
      data[1] = self->ReadU8();
      data[2] = self->ReadU8();
      data[3] = self->ReadU8();
      data[4] = self->ReadU8();
      data[5] = self->ReadU8();
      data[6] = self->ReadU8();
      data[7] = self->ReadU8();

    // Host is little endian, serialized data is big endian, so the first byte
    // read is the high-order byte, so we need to store it at `data[7]`, as
    // `data[0]` is our low-order byte.
    } else {
      data[7] = self->ReadU8();
      data[6] = self->ReadU8();
      data[5] = self->ReadU8();
      data[4] = self->ReadU8();
      data[3] = self->ReadU8();
      data[2] = self->ReadU8();
      data[1] = self->ReadU8();
      data[0] = self->ReadU8();
    }
    return *(new (data) uint64_t);
  }

  [[gnu::hot]] MX_ALWAYS_INLINE uint32_t ReadU32(void) noexcept {
    alignas(uint32_t) uint8_t data[4u];
    auto self = static_cast<Self *>(this);

    // Data is serialized in big-endian byte order, we need to deserialize it
    // into the host byte order.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      data[0] = self->ReadU8();
      data[1] = self->ReadU8();
      data[2] = self->ReadU8();
      data[3] = self->ReadU8();

    // Host is little endian, serialized data is big endian, so the first byte
    // read is the high-order byte, so we need to store it at `data[3]`, as
    // `data[0]` is our low-order byte.
    } else {
      data[3] = self->ReadU8();
      data[2] = self->ReadU8();
      data[1] = self->ReadU8();
      data[0] = self->ReadU8();
    }

    return *(new (data) uint32_t);
  }

  [[gnu::hot]] MX_ALWAYS_INLINE uint16_t ReadU16(void) noexcept {
    alignas(uint16_t) uint8_t data[2];
    auto self = static_cast<Self *>(this);

    // Data is serialized in big-endian byte order, we need to deserialize it
    // into the host byte order.
    if MX_CONSTEXPR_ENDIAN (MX_BIG_ENDIAN) {
      data[0] = self->ReadU8();
      data[1] = self->ReadU8();

    // Host is little endian, serialized data is big endian, so the first byte
    // read is the high-order byte, so we need to store it at `data[1]`, as
    // `data[0]` is our low-order byte.
    } else {
      data[1] = self->ReadU8();
      data[0] = self->ReadU8();
    }

    return *(new (data) uint16_t);
  }

  [[gnu::hot]] MX_ALWAYS_INLINE uint8_t ReadU8(void) noexcept {
    return *read_ptr++;
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int64_t
  ReadI64(void) noexcept {
    return static_cast<int64_t>(ReadU64());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int32_t
  ReadI32(void) noexcept {
    return static_cast<int32_t>(ReadU32());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int16_t
  ReadI16(void) noexcept {
    return static_cast<int16_t>(ReadU16());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int8_t
  ReadI8(void) noexcept {
    return static_cast<int8_t>(ReadU8());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE bool ReadB(void) noexcept {
    return !!ReadU8();
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE uint32_t
  ReadSize(void) noexcept {
    return ReadU32();
  }

  [[gnu::hot]] MX_ALWAYS_INLINE void Skip(uint32_t num_bytes) noexcept {
    read_ptr += num_bytes;
  }

  const uint8_t *read_ptr;
};

// A reader for reading continuous data starting from `read_ptr_`; no bounds
// checking is performed.
class UnsafeByteReader : public ByteReader<UnsafeByteReader> {
 public:
  using ByteReader<UnsafeByteReader>::ReadU8;

  MX_ALWAYS_INLINE UnsafeByteReader(const std::string &data) noexcept
      : UnsafeByteReader(data.data()) {}

  MX_ALWAYS_INLINE UnsafeByteReader(std::string_view data) noexcept
      : UnsafeByteReader(data.data()) {}

  MX_ALWAYS_INLINE explicit UnsafeByteReader(const char *read_ptr_)
      : ByteReader(read_ptr_) {}

  MX_ALWAYS_INLINE explicit UnsafeByteReader(const uint8_t *read_ptr_)
      : ByteReader(read_ptr_) {}
};

// A reader for reading at most `num_bytes` of data starting at `read_ptr_`.
// Bounds checking is performed.
class ByteRangeReader : public UnsafeByteReader {
 public:
  explicit ByteRangeReader(const std::string &data) noexcept
      : UnsafeByteReader(data.data()),
        max_read_ptr(&(read_ptr[data.size()])) {}

  explicit ByteRangeReader(std::string_view data) noexcept
      : UnsafeByteReader(data.data()),
        max_read_ptr(&(read_ptr[data.size()])) {}

  explicit ByteRangeReader(const char *read_ptr_, size_t num_bytes) noexcept
      : UnsafeByteReader(read_ptr_),
        max_read_ptr(&(read_ptr[num_bytes])) {}

  explicit ByteRangeReader(const uint8_t *read_ptr_, size_t num_bytes) noexcept
      : UnsafeByteReader(read_ptr_),
        max_read_ptr(&(read_ptr[num_bytes])) {}

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE double
  ReadF64(void) noexcept {
    if (&(read_ptr[7]) >= max_read_ptr) {
      error = true;
      return {};
    } else {
      return UnsafeByteReader::ReadF64();
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE float
  ReadF32(void) noexcept {
    if (&(read_ptr[3]) >= max_read_ptr) {
      error = true;
      return {};
    } else {
      return UnsafeByteReader::ReadF32();
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE uint64_t
  ReadU64(void) noexcept {
    if (&(read_ptr[7]) >= max_read_ptr) {
      error = true;
      return {};
    } else {
      return UnsafeByteReader::ReadU64();
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE uint32_t
  ReadU32(void) noexcept {
    if (&(read_ptr[3]) >= max_read_ptr) {
      error = true;
      return {};
    } else {
      return UnsafeByteReader::ReadU32();
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE uint16_t
  ReadU16(void) noexcept {
    if (&(read_ptr[1]) >= max_read_ptr) {
      error = true;
      return {};
    } else {
      return UnsafeByteReader::ReadU16();
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE uint8_t
  ReadU8(void) noexcept {
    if (read_ptr >= max_read_ptr) {
      error = true;
      return {};
    } else {
      return UnsafeByteReader::ReadU8();
    }
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int64_t
  ReadI64(void) noexcept {
    return static_cast<int64_t>(ReadU64());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int32_t
  ReadI32(void) noexcept {
    return static_cast<int32_t>(ReadU32());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int16_t
  ReadI16(void) noexcept {
    return static_cast<int16_t>(ReadU16());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE int8_t
  ReadI8(void) noexcept {
    return static_cast<int8_t>(ReadU8());
  }

  [[gnu::hot]] MX_FLATTEN MX_ALWAYS_INLINE bool ReadB(void) noexcept {
    return !!ReadU8();
  }

  [[gnu::hot]] void Skip(uint32_t num_bytes) noexcept {
    read_ptr = &(read_ptr[num_bytes]);
    if (read_ptr > max_read_ptr) {
      error = true;
    }
  }

  const uint8_t *max_read_ptr;
  bool error{false};
};

// A serializing writer that ignores the values being written, and instead
// counts the number of bytes that will be written.
template <typename SubWriter>
struct ByteCountingWriterProxy : public SubWriter {
 public:
  using SubWriter::SubWriter;

  MX_ALWAYS_INLINE void WriteSize(uint32_t v) {
    num_bytes += 4;
    SubWriter::WriteSize(v);
  }

  MX_ALWAYS_INLINE void WriteF64(double v) {
    num_bytes += 8;
    SubWriter::WriteF64(v);
  }

  MX_ALWAYS_INLINE void WriteF32(float v) {
    num_bytes += 4;
    SubWriter::WriteF32(v);
  }

  MX_ALWAYS_INLINE void WriteU64(uint64_t v) {
    num_bytes += 8;
    SubWriter::WriteU64(v);
  }

  MX_ALWAYS_INLINE void WriteU32(uint32_t v) {
    num_bytes += 4;
    SubWriter::WriteU32(v);
  }

  MX_ALWAYS_INLINE void WriteU16(uint16_t v) {
    num_bytes += 2;
    SubWriter::WriteU16(v);
  }

  MX_ALWAYS_INLINE void WriteU8(uint8_t v) {
    num_bytes += 1;
    SubWriter::WriteU8(v);
  }

  MX_ALWAYS_INLINE void WriteB(bool v) {
    num_bytes += 1;
    SubWriter::WriteB(v);
  }

  MX_ALWAYS_INLINE void WriteI64(int64_t v) {
    num_bytes += 8;
    SubWriter::WriteI64(v);
  }

  MX_ALWAYS_INLINE void WriteI32(int32_t v) {
    num_bytes += 4;
    SubWriter::WriteI32(v);
  }

  MX_ALWAYS_INLINE void WriteI16(int16_t v) {
    num_bytes += 2;
    SubWriter::WriteI16(v);
  }

  MX_ALWAYS_INLINE void WriteI8(int8_t v) {
    num_bytes += 1;
    SubWriter::WriteI8(v);
  }

  MX_ALWAYS_INLINE void Skip(uint32_t n) {
    num_bytes += n;
    SubWriter::Skip(n);
  }

  uint32_t num_bytes{0};
};

using ByteCountingWriter = ByteCountingWriterProxy<NullWriter>;

template <typename T>
static constexpr bool kIsByteCountingWriter = false;

template <>
inline constexpr bool kIsByteCountingWriter<ByteCountingWriter> = true;

// A reader that actually figures out how many serialized bytes something will
// require (`NullReader`), or that something occupied (using a real `Reader`)
template <typename SubReader>
struct ByteCountingReader : public SubReader {
 public:
  using SubReader::SubReader;

  // This is the one special case where we actual do the read.
  MX_ALWAYS_INLINE uint32_t ReadSize(void) {
    num_bytes += 4u;
    return SubReader::ReadSize();
  }

  MX_ALWAYS_INLINE double ReadF64(void) {
    num_bytes += 8u;
    SubReader::Skip(8u);
    return {};
  }

  MX_ALWAYS_INLINE float ReadF32(void) {
    num_bytes += 4u;
    SubReader::Skip(4u);
    return {};
  }

  MX_ALWAYS_INLINE uint64_t ReadU64(void) {
    num_bytes += 8u;
    SubReader::Skip(8u);
    return {};
  }

  MX_ALWAYS_INLINE uint32_t ReadU32(void) {
    num_bytes += 4u;
    SubReader::Skip(4u);
    return {};
  }

  MX_ALWAYS_INLINE uint16_t ReadU16(void) {
    num_bytes += 2u;
    SubReader::Skip(2u);
    return {};
  }

  MX_ALWAYS_INLINE uint8_t ReadU8(void) {
    num_bytes += 1u;
    SubReader::Skip(1u);
    return {};
  }

  MX_ALWAYS_INLINE bool ReadB(void) {
    num_bytes += 1u;
    SubReader::Skip(1u);
    return {};
  }

  MX_ALWAYS_INLINE int64_t ReadI64(void) {
    num_bytes += 8u;
    SubReader::Skip(8u);
    return {};
  }

  MX_ALWAYS_INLINE int32_t ReadI32(void) {
    num_bytes += 4u;
    SubReader::Skip(4u);
    return {};
  }

  MX_ALWAYS_INLINE int16_t ReadI16(void) {
    num_bytes += 2u;
    SubReader::Skip(2u);
    return {};
  }

  MX_ALWAYS_INLINE int8_t ReadI8(void) {
    num_bytes += 1u;
    SubReader::Skip(1u);
    return {};
  }

  MX_ALWAYS_INLINE void Skip(uint32_t n) {
    num_bytes += n;
    SubReader::Skip(n);
  }

  size_t num_bytes{0};
};

template <typename T>
static constexpr bool kIsByteCountingReader = false;

template <typename T>
static constexpr bool kIsByteCountingReader<ByteCountingReader<T>> = true;

// Serialize enumerations in terms of their underlying type.
template <typename Reader, typename Writer, typename T>
struct Serializer {

  static_assert(std::is_enum_v<T>);
  using UT = std::underlying_type_t<T>;

  static constexpr bool kIsFixedSize = true;
  MX_FLATTEN MX_INLINE static void Write(Writer &writer, T data) {
    Serializer<Reader, Writer, UT>::Write(writer, static_cast<UT>(data));
  }
  MX_FLATTEN MX_INLINE static void Read(Reader &reader, T &out) {
    Serializer<Reader, Writer, UT>::Read(
        reader, reinterpret_cast<UT &>(out));
  }
  static constexpr uint32_t SizeInBytes(void) noexcept {
    return static_cast<uint32_t>(sizeof(T));
  }
};

template <typename T>
static constexpr bool kHasTrivialFixedSizeSerialization =
    Serializer<NullReader, NullWriter, T>::kIsFixedSize;

template <typename T>
static constexpr size_t kFixedSerializationSize =
    Serializer<NullReader, NullWriter, T>::SizeInBytes();

// Methods to overload for serializing data
template <typename Reader, typename Writer, typename DataT>
struct Serializer<Reader, Writer, const DataT>
    : Serializer<Reader, Writer, DataT> {};

#define MX_SERIALIZER_NAMESPACE_BEGIN
#define MX_SERIALIZER_NAMESPACE_END
#define MX_DEFINE_UNSAFE_SERIALIZER_PRIV(type) \
  template <> \
  inline constexpr bool kCanReadWriteUnsafely<type> = true

#define MX_MAKE_FUNDAMENTAL_SERIALIZER(type, cast_op, cast_type, \
                                       method_suffix, size) \
  MX_SERIALIZER_NAMESPACE_BEGIN \
  template <typename Reader, typename Writer> \
  struct Serializer<Reader, Writer, type> { \
    static constexpr bool kIsFixedSize = true; \
    MX_FLATTEN MX_INLINE static void Write(Writer &writer, type data) { \
      writer.Write##method_suffix(cast_op<cast_type>(data)); \
    } \
    MX_FLATTEN MX_INLINE static void Read(Reader &reader, type &out) { \
      out = cast_op<type>(reader.Read##method_suffix()); \
    } \
    static constexpr uint32_t SizeInBytes(void) noexcept { \
      return size; \
    } \
  }; \
  MX_DEFINE_UNSAFE_SERIALIZER_PRIV(type); \
  MX_SERIALIZER_NAMESPACE_END

template <typename T>
inline constexpr bool kCanReadWriteUnsafely =
    std::is_enum_v<T> || std::is_arithmetic_v<T>;

template <>
inline constexpr bool kCanReadWriteUnsafely<Empty> = true;

template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, Empty> {
  static constexpr bool kIsFixedSize = true;
  MX_INLINE static void Write(Writer &writer, Empty) {}
  MX_INLINE static void Read(Reader &reader, Empty &) {}
  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0u;
  }
};

#if CHAR_MIN < 0
MX_MAKE_FUNDAMENTAL_SERIALIZER(char, static_cast, int8_t, I8, 1)
#else
MX_MAKE_FUNDAMENTAL_SERIALIZER(char, static_cast, uint8_t, U8, 1)
#endif

MX_MAKE_FUNDAMENTAL_SERIALIZER(bool, static_cast, bool, B, 1)

MX_MAKE_FUNDAMENTAL_SERIALIZER(uint8_t, static_cast, uint8_t, U8, 1)
MX_MAKE_FUNDAMENTAL_SERIALIZER(int8_t, static_cast, int8_t, I8, 1)

MX_MAKE_FUNDAMENTAL_SERIALIZER(uint16_t, static_cast, uint16_t, U16, 2)
MX_MAKE_FUNDAMENTAL_SERIALIZER(int16_t, static_cast, int16_t, I16, 2)

MX_MAKE_FUNDAMENTAL_SERIALIZER(uint32_t, static_cast, uint32_t, U32, 4)
MX_MAKE_FUNDAMENTAL_SERIALIZER(int32_t, static_cast, int32_t, I32, 4)

MX_MAKE_FUNDAMENTAL_SERIALIZER(uint64_t, static_cast, uint64_t, U64, 8)
MX_MAKE_FUNDAMENTAL_SERIALIZER(int64_t, static_cast, int64_t, I64, 8)

MX_MAKE_FUNDAMENTAL_SERIALIZER(float, static_cast, float, F32, 4)
MX_MAKE_FUNDAMENTAL_SERIALIZER(double, static_cast, double, F64, 8)


template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, capnp::word> {
  static constexpr bool kIsFixedSize = true;
  MX_FLATTEN MX_INLINE static void Write(
      Writer &writer, const capnp::word &data) {
    writer.WriteU64(reinterpret_cast<const uint64_t &>(data));
  }
  MX_FLATTEN MX_INLINE static void Read(Reader &reader, capnp::word &out) {
    new (&out) uint64_t(reader.ReadU64());
  }
  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 8;
  }
};
template <>
inline constexpr bool kCanReadWriteUnsafely<capnp::word> = true;

#ifndef MX_MISSING_INT128
template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, int128_t> {
  static constexpr bool kIsFixedSize = true;
  static void Write(Writer &writer, int128_t val) {
    alignas(int128_t) uint8_t data[16u];
    *(new (data) int128_t) = val;

    if MX_CONSTEXPR_ENDIAN (MX_LITTLE_ENDIAN) {
      writer.WriteU8(data[0]);
      for (auto i = 1u; i < 16u; ++i) {
        writer.WriteU8(data[i]);
      }
    } else {
      writer.WriteU8(data[16u - 1u]);
      for (auto i = 2u; i <= 16u; ++i) {
        writer.WriteU8(data[16u - i]);
      }
    }
  }

  static void Read(Reader &reader, int128_t &out) {
    alignas(int128_t) uint8_t data[16u];
    for (auto i = 0u; i < 16u; ++i) {
      data[i] = reader.ReadU8();
    }
    out = *(new (data) int128_t);
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return static_cast<unsigned>(sizeof(int32_t));
  }
};

template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, uint128_t> {
  static constexpr bool kIsFixedSize = true;

  static void Write(Writer &writer, uint128_t val) {
    alignas(uint128_t) uint8_t data[16u];
    *(new (data) uint128_t) = val;

    if MX_CONSTEXPR_ENDIAN (MX_LITTLE_ENDIAN) {
      writer.WriteU8(data[0]);
      for (auto i = 1u; i < 16u; ++i) {
        writer.WriteU8(data[i]);
      }
    } else {
      writer.WriteU8(data[16u - 1u]);
      for (auto i = 2u; i <= 16u; ++i) {
        writer.WriteU8(data[16u - i]);
      }
    }
  }

  static void Read(Reader &reader, uint128_t &out) {
    alignas(uint128_t) uint8_t data[16];
    for (auto i = 0u; i < 16u; ++i) {
      data[i] = reader.ReadU8();
    }
    out = *(new (data) uint128_t);
  }

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return static_cast<unsigned>(sizeof(uint32_t));
  }
};
#endif  // MX_MISSING_INT128

#undef MX_DEFINE_UNSAFE_SERIALIZER_PRIV
#define MX_DEFINE_UNSAFE_SERIALIZER_PRIV(type)

#undef MX_SERIALIZER_NAMESPACE_BEGIN
#undef MX_SERIALIZER_NAMESPACE_END

template <typename Reader, typename ContainerType, typename ElementType>
struct LinearContainerReader {
 public:
  MX_FLATTEN MX_INLINE static void Read(Reader &reader, ContainerType &ret) {
    const auto size = reader.ReadSize();
    ret.resize(size);
    if (size) {
      ElementType *const begin = &(ret[0]);
      for (uint32_t i = 0; i < size; ++i) {
        Serializer<Reader, NullWriter, ElementType>::Read(reader, begin[i]);
      }
    }
  }
};

// Special case for the byte counting reader: we don't want to really have to
// construct any actual containers or anything like that, and instead just
// count the bytes.
template <typename SubReader, typename ContainerType, typename ElementType>
struct LinearContainerReader<ByteCountingReader<SubReader>, ContainerType,
                             ElementType> {
 public:
  using Reader = ByteCountingReader<SubReader>;

  MX_FLATTEN MX_INLINE static void Read(Reader &reader, ContainerType &) {
    if (const auto size = reader.ReadSize(); size) {
      if constexpr (kHasTrivialFixedSizeSerialization<ElementType>) {
        reader.Skip(
            static_cast<uint32_t>(size * kFixedSerializationSize<ElementType>));
      } else {
        alignas(ElementType) char dummy_data[sizeof(ElementType)];
        for (uint32_t i = 0; i < size; ++i) {
          Serializer<Reader, NullWriter, ElementType>::Read(
              reader, *reinterpret_cast<ElementType *>(dummy_data));
        }
      }
    }
  }
};

// The generic linear container writer.
template <typename Writer, typename ContainerType, typename ElementType>
struct LinearContainerWriter {
 public:
  MX_FLATTEN MX_INLINE static void Write(
      Writer &writer, const ContainerType &data) {
    const auto size = static_cast<uint32_t>(data.size());
    writer.EnterVariableSizedComposite(size);
    writer.WriteSize(size);

    // NOTE(pag): Induction variable based `for` loop so that a a byte counting
    //            writer can elide the `for` loop entirely and count `size`.
    if (size) {
      const ElementType *const begin = &(data[0]);
      for (uint32_t i = 0; i < size; ++i) {
        Serializer<NullReader, Writer, ElementType>::Write(writer, begin[i]);
      }
    }

    writer.ExitComposite();
  }
};

// A specialization of a linear container writer that knows that all we want
// to do is count bytes.
template <typename ContainerType, typename ElementType>
struct LinearContainerWriter<ByteCountingWriter, ContainerType, ElementType> {
 public:
  MX_FLATTEN MX_INLINE static void Write(
      ByteCountingWriter &writer, const ContainerType &data) {
    const auto size = static_cast<uint32_t>(data.size());
    writer.EnterVariableSizedComposite(size);
    writer.WriteSize(size);
    if (size) {
      if constexpr (kHasTrivialFixedSizeSerialization<ElementType>) {
        writer.Skip(
            static_cast<uint32_t>(size * kFixedSerializationSize<ElementType>));

      } else {
        const ElementType *const begin = &(data[0]);
        for (uint32_t i = 0; i < size; ++i) {
          Serializer<NullReader, ByteCountingWriter, ElementType>::Write(
              writer, begin[i]);
        }
      }
    }
    writer.ExitComposite();
  }
};

template <typename Reader, typename Writer, typename ContainerType,
          typename ElementType>
struct LinearContainerSerializer
    : public LinearContainerReader<Reader, ContainerType, ElementType>,
      public LinearContainerWriter<Writer, ContainerType, ElementType> {
  static constexpr bool kIsFixedSize = false;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0u;
  }
};

template <typename Reader, typename Writer, typename T,
          typename VectorAllocator>
struct Serializer<Reader, Writer, std::vector<T, VectorAllocator>>
    : public LinearContainerSerializer<Reader, Writer,
                                       std::vector<T, VectorAllocator>, T> {};

template <typename Reader, typename Writer, typename T, typename StringTraits,
          typename StringAllocator>
struct Serializer<Reader, Writer,
                  std::basic_string<T, StringTraits, StringAllocator>>
    : public LinearContainerSerializer<
          Reader, Writer, std::basic_string<T, StringTraits, StringAllocator>,
          T> {};

template <typename Reader, typename Writer, typename T, typename StringTraits>
struct Serializer<Reader, Writer, std::basic_string_view<T, StringTraits>>
    : public LinearContainerWriter<
          Writer, std::basic_string_view<T, StringTraits>, T> {
  static constexpr bool kIsFixedSize = false;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0u;
  }
};

template <typename Reader, typename Writer, typename T>
struct Serializer<Reader, Writer, kj::ArrayPtr<T>>
    : public LinearContainerWriter<Writer, kj::ArrayPtr<T>, T> {
  static constexpr bool kIsFixedSize = false;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0u;
  }
};

template <typename Reader, typename Writer, typename T>
struct Serializer<Reader, Writer, kj::Array<T>>
    : public LinearContainerWriter<Writer, kj::Array<T>, T> {
  static constexpr bool kIsFixedSize = false;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0u;
  }

  MX_FLATTEN MX_INLINE static void Read(Reader &reader, kj::Array<T> &ret) {
    const auto size = reader.ReadSize();
    if (!size) {
      return;
    }
    if constexpr (kIsByteCountingReader<Reader>) {
      if constexpr (kHasTrivialFixedSizeSerialization<T>) {
        reader.Skip(
            static_cast<uint32_t>(size * kFixedSerializationSize<T>));
      } else {
        alignas(T) char dummy_data[sizeof(T)];
        for (uint32_t i = 0; i < size; ++i) {
          Serializer<Reader, NullWriter, T>::Read(
              reader, *reinterpret_cast<T *>(dummy_data));
        }
      }

    } else {
      auto new_ret = kj::heapArray<T>(size);
      for (uint32_t i = 0; i < size; ++i) {
        Serializer<Reader, NullWriter, T>::Read(reader, new_ret[i]);
      }
      ret = std::move(new_ret);
    }
  }
};

// Serialize an indexed type like `std::tuple`, `std::pair`, or `std::array`.
template <typename Reader, typename Writer, typename Val, size_t kIndex,
          size_t kMaxIndex>
struct IndexedSerializer {

  MX_FLATTEN MX_INLINE static void Write(Writer &writer, const Val &data) {
    if constexpr (kIndex == 0u) {
      writer.EnterFixedSizeComposite(kMaxIndex);
    }
    if constexpr (kIndex < kMaxIndex) {
      const auto &elem = std::get<kIndex>(data);
      using ElemT =
          std::remove_const_t<std::remove_reference_t<decltype(elem)>>;
      Serializer<Reader, Writer, ElemT>::Write(writer, elem);
      if constexpr ((kIndex + 1u) < kMaxIndex) {
        IndexedSerializer<NullReader, Writer, Val, kIndex + 1u,
                          kMaxIndex>::Write(writer, data);
      } else {
        writer.ExitComposite();
      }
    }
  }

  MX_FLATTEN MX_INLINE static void Read(Reader &writer, Val &data) {
    if constexpr (kIndex < kMaxIndex) {
      auto &elem = std::get<kIndex>(data);
      using ElemT = std::remove_reference_t<decltype(elem)>;
      Serializer<Reader, Writer, ElemT>::Read(writer, elem);
      if constexpr ((kIndex + 1u) < kMaxIndex) {
        IndexedSerializer<Reader, NullWriter, Val, kIndex + 1u,
                          kMaxIndex>::Read(writer, data);
      }
    }
  }
};

template <typename Reader, typename Writer, typename A, typename B>
struct Serializer<Reader, Writer, std::pair<A, B>>
    : public IndexedSerializer<Reader, Writer, std::pair<A, B>, 0, 2> {

  static constexpr bool kIsFixedSize = kHasTrivialFixedSizeSerialization<A> &&
                                       kHasTrivialFixedSizeSerialization<B>;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    if constexpr (kIsFixedSize) {
      return kFixedSerializationSize<A> + kFixedSerializationSize<B>;
    } else {
      return 0u;
    }
  }
};

template <typename Reader, typename Writer, typename Elem, typename... Elems>
struct Serializer<Reader, Writer, std::tuple<Elem, Elems...>>
    : public IndexedSerializer<Reader, Writer, std::tuple<Elem, Elems...>, 0,
                               std::tuple_size_v<std::tuple<Elem, Elems...>>> {

  static constexpr bool kIsFixedSize =
      kHasTrivialFixedSizeSerialization<Elem> &&
      (kHasTrivialFixedSizeSerialization<Elems> && ... && true);

  static constexpr uint32_t SizeInBytes(void) noexcept {
    if constexpr (kIsFixedSize) {
      return kFixedSerializationSize<Elem> +
             (kFixedSerializationSize<Elems> + ... + 0u);
    } else {
      return 0u;
    }
  }
};

template <typename Reader, typename Writer>
struct Serializer<Reader, Writer, std::tuple<>> {

  static constexpr bool kIsFixedSize = true;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    return 0u;
  }

  MX_FLATTEN MX_INLINE static void Write(Writer &writer, std::tuple<>) {}
  MX_FLATTEN MX_INLINE static void Read(Reader &writer, std::tuple<> &) {}
};

template <typename Reader, typename Writer, typename ElemT, size_t kSize>
struct Serializer<Reader, Writer, std::array<ElemT, kSize>>
    : public IndexedSerializer<Reader, Writer, std::array<ElemT, kSize>, 0,
                               kSize> {
  static constexpr bool kIsFixedSize = kHasTrivialFixedSizeSerialization<ElemT>;

  static constexpr uint32_t SizeInBytes(void) noexcept {
    if constexpr (kHasTrivialFixedSizeSerialization<ElemT>) {
      return static_cast<uint32_t>(kFixedSerializationSize<ElemT> * kSize);
    } else {
      return 0u;
    }
  }
};

}  // namespace mx

#define MX_SERIALIZER_NAMESPACE_BEGIN namespace mx {
#define MX_SERIALIZER_NAMESPACE_END }
