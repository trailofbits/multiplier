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
#include <sstream>
#include <utility>

#include "Serialize.h"
#include "SQLiteStore.h"

namespace mx {
static constexpr const char* table_names[] = {
  "MetaNameToId",
  "FileIdToPath",
  "FileIdToHash",
  "FileIdToSerializedFile",
  "FileIdToFragmentId",
  "FileIdAndLineNumberToFragmentId",
  "FileHashToFileId",
  "FragmentHashToFragmentId",
  "FragmentIdToSerializedFragment",
  "FragmentIdToVersionNumber",
  "EntityIdRedecls",
  "EntityIdToMangledName",
  "MangledNameToEntityId",
  "EntityIdUseToFragmentId",
  "EntityIdReference",
};

class PersistentMapBase {
 private:
  sqlite::Connection& db;
  std::shared_ptr<sqlite::Statement> set_stmt;
  std::shared_ptr<sqlite::Statement> get_stmt;
  std::shared_ptr<sqlite::Statement> get_or_set_stmt;
  std::shared_ptr<sqlite::Statement> prefix_stmt;

  PersistentMapBase(void) = delete;
 public:
  ~PersistentMapBase(void);
  PersistentMapBase(sqlite::Connection& db, uint8_t id);

  template<typename K, typename V>
  void Set(const K& key, const V& val) const {
    set_stmt->BindValues(key, val);
    set_stmt->Execute();
  }

  template<typename K, typename V>
  bool GetOrSet(const K& key, V& val) const {
    get_or_set_stmt->BindValues(key, val);
    get_or_set_stmt->ExecuteStep();
    auto res = get_or_set_stmt->GetResult();
    K stored_key;
    V stored_value;
    res.Columns(stored_key, stored_value);
    get_or_set_stmt->ExecuteStep();
    bool inserted = stored_value != val;
    val = stored_value;
    return inserted;
  }

  template<typename K, typename V>
  bool TryGet(const K& key, V& val) const {
    get_stmt->BindValues(key);
    if(get_stmt->ExecuteStep()) {
      K stored_key;
      auto res = get_stmt->GetResult();
      res.Columns(stored_key, val);
      get_stmt->ExecuteStep();
      return true;
    }

    return false;
  }

  void MatchCommonPrefix(
      std::string key_prefix,
      std::function<bool(std::string_view, std::string_view)> cb) const;
};

template <uint8_t kId, typename... Keys>
class PersistentSet {
 private:
  sqlite::Connection& db;
  std::shared_ptr<sqlite::Statement> insert_stmt, test_stmt, scan_stmt;
  std::array<std::shared_ptr<sqlite::Statement>, sizeof...(Keys)> get_stmts;
  std::array<std::shared_ptr<sqlite::Statement>, sizeof...(Keys)> get_by_prefix_stmts;

  template <size_t I, typename K, typename C, size_t... Is>
  void GetByFieldImpl(const K& key, C callback, std::index_sequence<Is...>) const {
    get_stmts[I]->BindValues(key);
    while(get_stmts[I]->ExecuteStep()) {
      auto res = get_stmts[I]->GetResult();
      std::tuple<Keys...> elem;
      res.Columns(std::get<Is>(elem)...);
      if(!callback(std::get<Is>(elem)...)) {
        break;
      }
    }
    get_stmts[I]->Reset();
  }

  template <typename C, typename... Ks, size_t... Is1, size_t... Is2>
  void GetByPrefixImpl(const std::tuple<Ks...> prefix, C callback, std::index_sequence<Is1...>, std::index_sequence<Is2...>) const {
    size_t I = sizeof...(Ks) - 1;
    get_by_prefix_stmts[I]->BindValues(std::get<Is1>(prefix)...);
    while(get_stmts[I]->ExecuteStep()) {
      auto res = get_stmts[I]->GetResult();
      std::tuple<Keys...> elem;
      res.Columns(std::get<Is2>(elem)...);
      if(!callback(std::get<Is2>(elem)...)) {
        break;
      }
    }
    get_by_prefix_stmts[I]->Reset();
  }

  template <typename C, size_t... Is>
  void ScanImpl(C callback, std::index_sequence<Is...>) const {
    while(scan_stmt->ExecuteStep()) {
      auto res = scan_stmt->GetResult();
      std::tuple<Keys...> elem;
      res.Columns(std::get<Is>(elem)...);
      if(!callback(std::get<Is>(elem)...)) {
        break;
      }
    }
    scan_stmt->Reset();
  }

 public:
  PersistentSet(sqlite::Connection& db) : db(db) {
    std::stringstream table_desc;
    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      table_desc << "key" << i;
      if(i != sizeof...(Keys) - 1) {
        table_desc << ", ";
      }
    }

    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS " << table_names[kId] << "(";
    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      ss << "key" << i << ", ";
    }
    ss << "PRIMARY KEY(" << table_desc.str() << "))";
    db.Execute(ss.str());

    ss = {};
    ss << "INSERT OR IGNORE INTO " << table_names[kId] << '(' << table_desc.str() << ") VALUES(";
    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      ss << "?" << (i + 1);
      if(i != sizeof...(Keys) - 1) {
        ss << ", ";
      }
    }
    ss << ")";

    insert_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT (";
    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      ss << "?" << (i + 1);
      if(i != sizeof...(Keys) - 1) {
        ss << ", ";
      }
    }
    ss << ") IN " << table_names[kId];

    test_stmt = db.Prepare(ss.str());

    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      ss = {};
      ss << "SELECT " << table_desc.str() << " FROM " << table_names[kId] << " WHERE key" << i << " = ?1";
      get_stmts[i] = db.Prepare(ss.str());
    }

    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      ss = {};
      ss << "SELECT " << table_desc.str() << " FROM " << table_names[kId] << " WHERE ";
      for(size_t j = 0; j <= i; j++) {
        ss << "key" << j << " = ?" << (j + 1);
        if(j != i) {
          ss << " AND ";
        }
      }
      get_by_prefix_stmts[i] = db.Prepare(ss.str());
    }

    ss = {};
    ss << "SELECT " << table_desc.str() << " FROM " << table_names[kId];
    scan_stmt = db.Prepare(ss.str());
  }

  void Insert(Keys... keys) const {
    insert_stmt->BindValues(keys...);
    insert_stmt->Execute();
  }

  bool Test(Keys... keys) const {
    int res;
    test_stmt->BindValues(keys...);
    test_stmt->ExecuteStep();
    auto r = test_stmt->GetResult();
    r.Columns(res);
    test_stmt->ExecuteStep();
    return res;
  }

  template <size_t I, typename C,
    typename K = typename std::tuple_element<I, std::tuple<Keys...>>::type>
  void GetByField(const K& key, C callback) const {
    GetByFieldImpl<I>(key, callback, std::make_index_sequence<sizeof...(Keys)>());
  }

  template <typename C, typename... Ks>
  void GetByPrefix(const std::tuple<Ks...>& prefix, C callback) const {
    GetByPrefixImpl(prefix, callback, std::make_index_sequence<sizeof...(Ks)>(), std::make_index_sequence<sizeof...(Keys)>());
  }

  template <typename C>
  void Scan(C callback) const {
    ScanImpl(callback, std::make_index_sequence<sizeof...(Keys)>());
  }
};

// Persistent mapping from keys to values.
template <uint8_t kId, typename K, typename V>
class PersistentMap {
 private:

  PersistentMapBase impl;

 public:
  PersistentMap(sqlite::Connection& db) : impl(db, kId) {}

  V GetOrSet(K key, V val) const {
    impl.GetOrSet(key, val);
    return val;
  }

  void Set(K key, V val) const {
    impl.Set(key, val);
  }

  std::optional<V> TryGet(K key) const {
    V val;
    if(impl.TryGet(key, val)) {
      return val;
    } else {
      return std::nullopt;
    }
  }

  template <typename P, typename C>
  void ScanPrefix(const P& prefix, C callback) const {
    impl.MatchCommonPrefix(
        prefix,
        [cb = std::move(callback)] (std::string_view key_data,
                                    std::string_view val_data) -> bool {
          return cb(key_data, val_data);
        });
  }
};

}  // namespace mx
