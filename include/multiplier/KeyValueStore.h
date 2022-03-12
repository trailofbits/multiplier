// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <sstream>
#include <type_traits>

#include <glog/logging.h>
#include <google/protobuf/message.h>

namespace mx {

// Persistent key value storage for workspaces.
class KeyValueStore {
 public:
  enum KeyValueStoreID {
    kHashToFileId,
    kPathToFileId,
    kHashToCodeId
  };

  ~KeyValueStore(void);

  // Initialize the key-value store. If an empty path is specified then
  // the current working directory is used.
  explicit KeyValueStore(KeyValueStoreID id_, std::filesystem::path path);

  // Erase a key/value pair with the key `key`.
  void Erase(const std::string &key);

  // Erase all key/value pair with whose key matches the prefix `key_prefix`.
  void EraseMatchingPrefix(const std::string &key_prefix);

  // Try to get the value associated with `key` in the store. If the value
  // exists, then `val` is updated, and `true` is returned. Otherwise `false`
  // is returned.
  inline bool TryGet(const std::string &key, std::string *val) {
    return TryGetImpl(key, val);
  }

  // Set the value associated with `key` in the store to `val`.
  inline void Set(const std::string &key, const std::string &val) {
    return SetImpl(key, val);
  }

  // Implements an atomic set if the value is missing. Returns `true` if the
  // value was missing.
  //
  // NOTE(pag): This is only atomic with respect to other `GetOrSet` calls.
  bool SetIfMissing(const std::string &key,
                    std::function<std::string(void)> get_val_for_set);

  // Implements an atomic get or set.
  //
  // NOTE(pag): This is only atomic with respect to other `GetOrSet` calls.
  // NOTE(ppalka): And with respect to `UpdateOrSet` calls.
  std::string GetOrSet(const std::string &key,
                       std::function<std::string(void)> get_val_for_set);

  template <typename T, typename C>
  inline T GetOrSet(const std::string &key, C get_val_for_set) {
    auto do_get_val_for_set = [this, &get_val_for_set] (void) -> std::string {
      const T ret1 = get_val_for_set();
      return this->ToString<T>(ret1);
    };
    T ret2;
    CHECK(FromString<T>(GetOrSet(key, do_get_val_for_set), ret2));
    return ret2;
  }

  // Implements an atomic update or set.
  std::string UpdateOrSet(const std::string &key,
                          std::function<std::string(const std::string *)> update_val);

  template <typename T, typename C>
  inline T UpdateOrSet(const std::string &key, C update_val) {
    auto do_update_val = [this, &update_val] (const std::string *sval) {
      T val;
      const T *val_ptr = nullptr;
      if (val != nullptr) {
        CHECK(FromString<T>(sval, val));
        val_ptr = &val;
        return this->ToString<T>(update_val(val_ptr));
      }
    };
    T ret;
    CHECK(FromString<T>(UpdateOrSet(key, do_update_val), ret));
    return ret;
  }

  template <typename T>
  inline bool TryGet(const std::string &key, T *val) {
    std::string data;
    if (TryGetImpl(key, &data)) {
      LOG_IF(FATAL, !this->FromString<T>(data, *val))
          << "Unable to decode data for key '" << key << "'";
      return true;
    } else {
      return false;
    }
  }

  template <typename T>
  inline void Set(const std::string &key, T &val) {
    SetImpl(key, this->ToString<T>(val));
  }

  // Invoke a callback for each key/value pair.
  void MatchAll(
      std::function<bool(const std::string &, const std::string &)> cb);

  template <typename T>
  inline void MatchAll(
      std::function<bool(const std::string &, T &)> cb) {
    std::function<bool(const std::string &, const std::string &)> adaptor =
        [&] (const std::string &key, const std::string &val_str) -> bool{
          T val;
          CHECK(FromString<T>(val_str, val));
          return cb(key, val);
        };
    return MatchAll(adaptor);
  }

  // Invoke a callback for each key/value pair, where all the keys share a
  // common prefix.
  void MatchCommonPrefix(
      const std::string &key_prefix_,
      std::function<bool(const std::string &, const std::string &)> cb);

  template <typename T>
  inline void MatchCommonPrefix(
      const std::string &key_prefix_,
      std::function<bool(const std::string &, T &)> cb) {
    std::function<bool(const std::string &, const std::string &)> adaptor =
        [&] (const std::string &key, const std::string &val_str) -> bool{
          T val;
          CHECK(FromString<T>(val_str, val));
          return cb(key, val);
        };
    return MatchCommonPrefix(key_prefix_, adaptor);
  }

  // Given a `search_key` of length N, invoke a callback for each key/value
  // pair (key,value) such that
  //   1. `key` has the prefix HI:LO: where HI and LO are strings also of
  //      length N, and
  //   2. it holds that HI >= search_key >= LO lexicographically.
  void MatchRangesContainingKey(
      const std::string &search_key,
      std::function<bool(std::string_view low,
                         std::string_view high,
                         std::string_view key_suffix,
                         std::string_view value)> cb);

  class KeyValueEngine;

 private:
  KeyValueStore(void) = delete;

  template <typename T>
  inline static std::string ToString(const T &data) {
    if constexpr (std::is_base_of_v<google::protobuf::Message, T>) {
      std::string ret;
      CHECK(data.AppendToString(&ret));
      return ret;
    } else if constexpr (std::is_convertible_v<T, std::string>) {
      return data;
    } else if constexpr (std::is_scalar_v<T>) {
      std::stringstream ss;
      CHECK(ss << data);
      return ss.str();
    } else {
      static_assert(std::is_same_v<T, void>);
    }
  }

  template <typename T>
  inline static bool FromString(const std::string &data, T &out) {
    if constexpr (std::is_base_of_v<google::protobuf::Message, T>) {
      return out.ParseFromString(data);
    } else if constexpr (std::is_same_v<std::string, T>) {
      out = data;
      return true;
    } else if constexpr (std::is_scalar_v<T>) {
      std::stringstream ss;
      CHECK(ss << data);
      if (ss >> out) {
        return ss.eof();
      } else {
        return false;
      }
    } else {
      static_assert(std::is_same_v<T, void>);
    }
  }

  // Try to get the value associated with `key` in the store. If the value
  // exists, then `val` is updated, and `true` is returned. Otherwise `false`
  // is returned.
  bool TryGetImpl(const std::string &key, std::string *val);

  // Set the value associated with `key` in the store to `val`.
  void SetImpl(const std::string &key, const std::string &val);

  std::shared_ptr<KeyValueEngine> engine;
  std::string key_prefix;
};

}  // namespace mu
