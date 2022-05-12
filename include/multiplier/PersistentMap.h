// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <functional>
#include <memory>
#include <optional>
#include <string_view>

#include "Serialize.h"

namespace rocksdb {
class ColumnFamilyHandle;
class DB;
}  // namespace rocksdb
namespace mx {

class PersistentMapBase {
 private:
  std::shared_ptr<rocksdb::DB> impl;
  rocksdb::ColumnFamilyHandle *cf_handle;

  PersistentMapBase(void) = delete;

 public:
  ~PersistentMapBase(void);
  PersistentMapBase(std::filesystem::path workspace_dir);

  void Set(std::string_view key, std::string_view val) const;
  bool LazyGetOrSet(std::string_view key, std::string *val) const;
  bool GetOrSet(std::string_view key, std::string *val) const;
  bool TryGet(std::string_view key, std::string *val) const;
  void MatchCommonPrefix(
      std::string key_prefix,
      std::function<bool(std::string_view, std::string_view)> cb) const;
};

template <uint8_t kId, typename... Keys>
class PersistentSet {
 private:
  using K = std::tuple<Keys...>;
  using KeyCountingSerializer = Serializer<NullReader, ByteCountingWriter, K>;
  using KeySerializer = Serializer<NullReader, UnsafeByteWriter, K>;

#ifndef NDEBUG
  using SerializedKeyReader = ByteRangeReader;
#else
  using SerializedKeyReader = UnsafeByteReader;
#endif

  using KeyDeserializer = Serializer<SerializedKeyReader, NullWriter, K>;

  PersistentMapBase impl;

 public:
  PersistentSet(std::filesystem::path workspace_dir)
      : impl(std::move(workspace_dir)) {}

  void Insert(Keys... keys) const {
    K key(std::forward<Keys>(keys)...);

    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    KeyCountingSerializer::Write(counting_writer, key);
    const auto key_size = counting_writer.num_bytes;
    std::string key_data(key_size, char{});
    UnsafeByteWriter writer(key_data);

    writer.WriteI8(kId);
    KeySerializer::Write(writer, key);

    impl.Set(key_data, {});
  }

  bool Test(Keys... keys) const {
    K key(std::forward<Keys>(keys)...);

    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    KeyCountingSerializer::Write(counting_writer, key);
    const auto key_size = counting_writer.num_bytes;
    std::string key_data(key_size, char{});
    UnsafeByteWriter writer(key_data);

    writer.WriteI8(kId);
    KeySerializer::Write(writer, key);

    return impl.TryGet(key, &key_data);
  }

  template <typename P, typename C>
  void ScanPrefix(P prefix, C callback) const {
    using PrefixCountingSerializer =
        Serializer<NullReader, ByteCountingWriter, P>;

    using PrefixSerializer = Serializer<NullReader, UnsafeByteWriter, P>;

    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    PrefixCountingSerializer::Write(counting_writer, prefix);
    const auto prefix_size = counting_writer.num_bytes;
    std::string prefix_data(prefix_size, char{});
    UnsafeByteWriter writer(prefix_data);

    writer.WriteI8(kId);
    PrefixSerializer::Write(writer, prefix);

    impl.MatchCommonPrefix(
        std::move(prefix_data),
        [cb = std::move(callback)] (std::string_view key_data,
                                    std::string_view) -> bool {
          K key;
          SerializedKeyReader key_reader(key_data);
          key_reader.Skip(sizeof(kId));
          KeyDeserializer::Read(key_reader, key);

          return std::apply(cb, std::move(key));
        });
  }
};

// Persistent mapping from keys to values.
template <uint8_t kId, typename K, typename V>
class PersistentMap {
 private:
  using KeyCountingSerializer = Serializer<NullReader, ByteCountingWriter, K>;
  using ValueCountingSerializer = Serializer<NullReader, ByteCountingWriter, V>;

  using KeySerializer = Serializer<NullReader, UnsafeByteWriter, K>;
  using ValueSerializer = Serializer<NullReader, UnsafeByteWriter, V>;

#ifndef NDEBUG
  using SerializedKeyReader = ByteRangeReader;
  using SerializedValueReader = ByteRangeReader;
#else
  using SerializedKeyReader = UnsafeByteReader;
  using SerializedValueReader = UnsafeByteReader;
#endif

  using KeyDeserializer = Serializer<SerializedKeyReader, NullWriter, K>;
  using ValueDeserializer = Serializer<SerializedValueReader, NullWriter, V>;

  PersistentMapBase impl;

 public:
  PersistentMap(std::filesystem::path workspace_dir)
      : impl(std::move(workspace_dir)) {}

  V GetOrSet(K key, V val) const {
    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    KeyCountingSerializer::Write(counting_writer, key);
    const auto key_size = counting_writer.num_bytes;
    counting_writer.num_bytes = 0u;
    ValueCountingSerializer::Write(counting_writer, val);
    const auto val_size = counting_writer.num_bytes;
    std::string key_data(key_size, char{});
    std::string val_data(val_size, char{});
    UnsafeByteWriter key_writer(key_data);
    UnsafeByteWriter val_writer(val_data);

    key_writer.WriteI8(kId);
    KeySerializer::Write(key_writer, key);
    ValueSerializer::Write(val_writer, val);

    if (!impl.GetOrSet(key_data, &val_data)) {
      SerializedValueReader reader(val_data);
      ValueDeserializer::Read(reader, val);
    }

    return val;
  }

  void Set(K key, V val) const {
    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    KeyCountingSerializer::Write(counting_writer, key);
    const auto key_size = counting_writer.num_bytes;
    counting_writer.num_bytes = 0u;
    ValueCountingSerializer::Write(counting_writer, val);
    const auto val_size = counting_writer.num_bytes;
    std::string data(key_size + val_size, char{});
    UnsafeByteWriter writer(data);

    writer.WriteI8(kId);
    KeySerializer::Write(writer, key);
    ValueSerializer::Write(writer, val);

    std::string_view k(data.data(), key_size);
    std::string_view v(&(data[key_size]), val_size);
    impl.Set(k, v);
  }

  std::optional<V> TryGet(K key) const {
    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    KeyCountingSerializer::Write(counting_writer, key);
    const auto key_size = counting_writer.num_bytes;
    std::string key_data(key_size, char{});
    UnsafeByteWriter writer(key_data);

    writer.WriteI8(kId);
    KeySerializer::Write(writer, key);

    std::string val_data;
    if (!impl.TryGet(key_data, &val_data)) {
      return std::nullopt;
    }

    V val;
    SerializedValueReader reader(val_data);
    ValueDeserializer::Read(reader, val);
    return val;
  }

  template <typename C>
  V LazyGetOrSet(K key, C callback) const {
    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    KeyCountingSerializer::Write(counting_writer, key);
    const auto key_size = counting_writer.num_bytes;
    std::string key_data(key_size, char{});
    UnsafeByteWriter writer(key_data);

    writer.WriteI8(kId);
    KeySerializer::Write(writer, key);

    std::string val_data;

    V val;
    if (impl.TryGet(key_data, &val_data)) {
      SerializedValueReader reader(val_data);
      ValueDeserializer::Read(reader, val);
      return val;
    }

    val = callback();

    counting_writer.num_bytes = 0u;
    ValueCountingSerializer::Write(counting_writer, val);
    val_data.resize(counting_writer.num_bytes);
    UnsafeByteWriter val_writer(val_data);
    ValueSerializer::Write(val_writer, val);
    if (!impl.GetOrSet(key_data, &val_data)) {
      SerializedValueReader reader(val_data);
      ValueDeserializer::Read(reader, val);
    }

    return val;
  }

  template <typename P, typename C>
  void ScanPrefix(P prefix, C callback) const {
    using PrefixCountingSerializer =
        Serializer<NullReader, ByteCountingWriter, P>;

    using PrefixSerializer = Serializer<NullReader, UnsafeByteWriter, P>;

    ByteCountingWriter counting_writer;
    counting_writer.Skip(sizeof(kId));
    PrefixCountingSerializer::Write(counting_writer, prefix);
    const auto prefix_size = counting_writer.num_bytes;
    std::string prefix_data(prefix_size, char{});
    UnsafeByteWriter writer(prefix_data);

    writer.WriteI8(kId);
    PrefixSerializer::Write(writer, prefix);

    impl.MatchCommonPrefix(
        std::move(prefix_data),
        [cb = std::move(callback)] (std::string_view key_data,
                                    std::string_view val_data) -> bool {
          K key;
          V val;
          SerializedKeyReader key_reader(key_data);
          key_reader.Skip(sizeof(kId));
          KeyDeserializer::Read(key_reader, key);

          SerializedValueReader val_reader(val_data);
          ValueDeserializer::Read(val_reader, val);

          return cb(std::move(key), std::move(val));
        });
  }
};

}  // namespace mx
