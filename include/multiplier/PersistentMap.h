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
  "'mx::MetaNameToId'",
  "'mx::FileIdToPath'",
  "'mx::FileIdToHash'",
  "'mx::FileIdToSerializedFile'",
  "'mx::FileIdToFragmentId'",
  "'mx::FileIdAndLineNumberToFragmentId'",
  "'mx::FileHashToFileId'",
  "'mx::FragmentHashToFragmentId'",
  "'mx::FragmentIdToSerializedFragment'",
  "'mx::FragmentIdToVersionNumber'",
  "'mx::EntityIdRedecls'",
  "'mx::EntityIdToMangledName'",
  "'mx::MangledNameToEntityId'",
  "'mx::EntityIdUseToFragmentId'",
  "'mx::EntityIdReference'",
  "'mx::syntex::Tokens'",
  "'mx::syntex::GrammarRoot'",
  "'mx::syntex::GrammarNodes'",
  "'mx::syntex::GrammarChildren'",
};

template <uint8_t kId, typename... Keys>
class PersistentSet {
 private:
  sqlite::Connection &db;
  std::shared_ptr<sqlite::Statement> insert_stmt, test_stmt, scan_stmt;
  std::array<std::shared_ptr<sqlite::Statement>, sizeof...(Keys)> get_stmts;
  std::array<std::shared_ptr<sqlite::Statement>, sizeof...(Keys)> get_by_prefix_stmts;

  template <size_t I, typename K, typename C, size_t... Is>
  void GetByFieldImpl(const K &key, C callback, std::index_sequence<Is...>) const {
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
  void GetByPrefixImpl(const std::tuple<Ks...> prefix, C callback,
      std::index_sequence<Is1...>, std::index_sequence<Is2...>) const {
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
  PersistentSet(sqlite::Connection &db) : db(db) {
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
    ss << "INSERT OR IGNORE INTO " << table_names[kId]
       << '(' << table_desc.str() << ") VALUES(";
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
      ss << "SELECT " << table_desc.str()
         << " FROM " << table_names[kId]
         << " WHERE key" << i << " = ?1";
      get_stmts[i] = db.Prepare(ss.str());
    }

    for(size_t i = 0; i < sizeof...(Keys); ++i) {
      ss = {};
      ss << "SELECT " << table_desc.str()
         << " FROM " << table_names[kId] << " WHERE ";
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
  void GetByField(const K &key, C callback) const {
    GetByFieldImpl<I>(key, callback, std::make_index_sequence<sizeof...(Keys)>());
  }

  template <typename C, typename... Ks>
  void GetByPrefix(const std::tuple<Ks...> &prefix, C callback) const {
    GetByPrefixImpl(prefix, callback,
      std::make_index_sequence<sizeof...(Ks)>(),
      std::make_index_sequence<sizeof...(Keys)>());
  }

  template <typename C>
  void Scan(C callback) const {
    ScanImpl(callback, std::make_index_sequence<sizeof...(Keys)>());
  }
};

template<typename... Ts>
class Iterator {
 private:
  std::shared_ptr<sqlite::Statement> stmt;
  std::tuple<Ts...> value;

  template<size_t... Is>
  void Read(std::index_sequence<Is...>) {
    auto res = stmt->GetResult();
    res.Columns(std::get<Is>(value)...);
  }

 public:
  Iterator(std::shared_ptr<sqlite::Statement> stmt)
    : stmt(std::move(stmt)) {
    this->operator++();
  }

  bool operator==(const Iterator& b) const {
    return stmt == b.stmt;
  }

  bool operator!=(const Iterator& b) const {
    return stmt != b.stmt;
  }

  Iterator& operator++(void) {
    if(!stmt->ExecuteStep()) {
      stmt = nullptr;
      return *this;
    }

    Read(std::make_index_sequence<sizeof...(Ts)>());
    return *this;
  }

  const std::tuple<Ts...> &operator*(void) const {
    return value;
  }

  const std::tuple<Ts...> *operator->(void) const {
    return &value;
  }
};

// Persistent mapping from keys to values.
template <uint8_t kId, typename K, typename V>
class PersistentMap {
 private:
  sqlite::Connection &db;
  std::shared_ptr<sqlite::Statement> set_stmt;
  std::shared_ptr<sqlite::Statement> get_stmt;
  std::shared_ptr<sqlite::Statement> get_or_set_stmt;
  std::shared_ptr<sqlite::Statement> enum_stmt;

 public:
  PersistentMap(sqlite::Connection &db) : db(db) {
    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS " << table_names[kId]
       << "(key, value, PRIMARY KEY(key))";
    db.Execute(ss.str());

    ss = {};
    ss << "INSERT OR REPLACE INTO " << table_names[kId]
       << "(key, value) VALUES (?1, ?2)";
    set_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT key, value FROM " << table_names[kId]
       << " WHERE key = ?1";
    get_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "INSERT INTO " << table_names[kId]
       << "(key, value) VALUES(?1, ?2) "
       << "ON CONFLICT DO UPDATE SET value=value RETURNING key, value";
    get_or_set_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT key, value FROM " << table_names;
    enum_stmt = db.Prepare(ss.str());
  }

  V GetOrSet(K key, V val) const {
    get_or_set_stmt->BindValues(key, val);
    get_or_set_stmt->ExecuteStep();
    auto res = get_or_set_stmt->GetResult();
    K stored_key;
    V stored_value;
    res.Columns(stored_key, stored_value);
    get_or_set_stmt->ExecuteStep();
    return stored_value;
  }

  void Set(K key, V val) const {
    set_stmt->BindValues(key, val);
    set_stmt->Execute();
  }

  std::optional<V> TryGet(K key) const {
    get_stmt->BindValues(key);
    if(get_stmt->ExecuteStep()) {
      K stored_key;
      V stored_value;
      auto res = get_stmt->GetResult();
      res.Columns(stored_key, stored_value);
      get_stmt->ExecuteStep();
      return stored_value;
    }

    return std::nullopt;
  }

  Iterator<K, V> begin() {
    return Iterator<K, V>(enum_stmt);
  }

  Iterator<K, V> end() {
    return Iterator<K, V>(nullptr);
  }
};

template <uint8_t kId, typename K1, typename K2, typename V>
class PersistentMap2 {
 private:
  sqlite::Connection &db;
  std::shared_ptr<sqlite::Statement> set_stmt;
  std::shared_ptr<sqlite::Statement> get_stmt;
  std::shared_ptr<sqlite::Statement> get_or_set_stmt;
  std::shared_ptr<sqlite::Statement> enum_stmt;
  std::shared_ptr<sqlite::Statement> enum_k1_stmt;
  std::shared_ptr<sqlite::Statement> enum_k2_stmt;

 public:
  PersistentMap2(sqlite::Connection &db) : db(db) {
    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS "
       << table_names[kId] << "(key1, key2, value, PRIMARY KEY(key1, key2))";
    db.Execute(ss.str());

    ss = {};
    ss << "INSERT OR REPLACE INTO "
       << table_names[kId] << "(key1, key2, value) VALUES (?1, ?2, ?3)";
    set_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT key1, key2, value FROM "
       << table_names[kId] << " WHERE key1 = ?1 AND key2 = ?2";
    get_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "INSERT INTO " << table_names[kId]
       << "(key1, key2, value) VALUES(?1, ?2, ?3) "
       << "ON CONFLICT DO UPDATE SET value=value RETURNING key1, key2, value";
    get_or_set_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT key1, key2, value FROM " << table_names;
    enum_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT key1, key2, value FROM " << table_names[kId]
       << " WHERE key1 = ?1";
    enum_k1_stmt = db.Prepare(ss.str());

    ss = {};
    ss << "SELECT key1, key2, value FROM " << table_names[kId]
       << " WHERE key2 = ?1";
    enum_k1_stmt = db.Prepare(ss.str());
  }

  V GetOrSet(K1 key1, K2 key2, V val) const {
    get_or_set_stmt->BindValues(key1, key2, val);
    get_or_set_stmt->ExecuteStep();
    auto res = get_or_set_stmt->GetResult();
    K1 stored_key1;
    K2 stored_key2;
    V stored_value;
    res.Columns(stored_key1, stored_key2, stored_value);
    get_or_set_stmt->ExecuteStep();
    return stored_value;
  }

  void Set(K1 key1, K2 key2, V val) const {
    set_stmt->BindValues(key1, key2, val);
    set_stmt->Execute();
  }

  std::optional<V> TryGet(K1 key1, K2 key2) const {
    get_stmt->BindValues(key1, key2);
    if(get_stmt->ExecuteStep()) {
      K1 stored_key1;
      K2 stored_key2;
      V stored_value;
      auto res = get_stmt->GetResult();
      res.Columns(stored_key1, stored_key2, stored_value);
      get_stmt->ExecuteStep();
      return stored_value;
    }

    return std::nullopt;
  }

  Iterator<K1, K2, V> begin() {
    return Iterator<K1, K2, V>(enum_stmt);
  }

  Iterator<K1, K2, V> key1_equals(K1 key) {
    enum_k1_stmt->BindValues(key);
    return Iterator<K1, K2, V>(enum_k1_stmt);
  }

  Iterator<K1, K2, V> key2_equals(K2 key) {
    enum_k2_stmt->BindValues(key);
    return Iterator<K1, K2, V>(enum_k1_stmt);
  }

  Iterator<K1, K2, V> end() {
    return Iterator<K1, K2, V>(nullptr);
  }
};

}  // namespace mx
