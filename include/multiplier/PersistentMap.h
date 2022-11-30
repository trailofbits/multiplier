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
#include <sstream>
#include <string_view>
#include <utility>

#include "SQLiteStore.h"
#include "Serialize.h"

namespace mx {
static constexpr const char *table_names[] = {
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
};

template <uint8_t kId, typename... Keys> class PersistentSet {
 private:
  std::string table_desc;
  sqlite::Connection &db;
  sqlite::Query<> insert_stmt;
  sqlite::Query<int> test_stmt;
  sqlite::Query<Keys...> scan_stmt;

  std::vector<sqlite::Query<Keys...>> get_stmts;
  std::vector<sqlite::Query<Keys...>> get_by_prefix_stmts;

  template <size_t I, typename K, typename C, size_t... Is>
  void GetByFieldImpl(const K &key, C callback,
                      std::index_sequence<Is...>) const {
    get_stmts[I].Bind(key);
    for (auto &elem : get_stmts[I]) {
      if (!callback(std::get<Is>(elem)...)) {
        break;
      }
    }
  }

  template <typename C, typename... Ks, size_t... Is1, size_t... Is2>
  void GetByPrefixImpl(const std::tuple<Ks...> prefix, C callback,
                       std::index_sequence<Is1...>,
                       std::index_sequence<Is2...>) const {
    size_t I = sizeof...(Ks) - 1;
    get_by_prefix_stmts[I].Bind(std::get<Is1>(prefix)...);
    for (auto &elem : get_by_prefix_stmts[I]) {
      if (!callback(std::get<Is2>(elem)...)) {
        break;
      }
    }
  }

  template <typename C, size_t... Is>
  void ScanImpl(C callback, std::index_sequence<Is...>) const {
    for (auto &res : scan_stmt) {
      if (!callback(std::get<Is>(res)...)) {
        break;
      }
    }
  }

  std::string getTableDesc() {
    std::stringstream table_desc;
    for (size_t i = 0; i < sizeof...(Keys); ++i) {
      table_desc << "key" << i;
      if (i != sizeof...(Keys) - 1) {
        table_desc << ", ";
      }
    }
    return table_desc.str();
  }

  std::string getCreateStmt() {
    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS " << table_names[kId] << "(";
    for (size_t i = 0; i < sizeof...(Keys); ++i) {
      ss << "key" << i << ", ";
    }
    ss << "PRIMARY KEY(" << table_desc << "))";
    return ss.str();
  }

  std::string getInsertStmt() {
    std::stringstream ss;
    ss << "INSERT OR IGNORE INTO " << table_names[kId] << '(' << table_desc
       << ") VALUES(";
    for (size_t i = 0; i < sizeof...(Keys); ++i) {
      ss << "?" << (i + 1);
      if (i != sizeof...(Keys) - 1) {
        ss << ", ";
      }
    }
    ss << ")";
    return ss.str();
  }

  std::string getTestStmt() {
    std::stringstream ss;
    ss << "SELECT (";
    for (size_t i = 0; i < sizeof...(Keys); ++i) {
      ss << "?" << (i + 1);
      if (i != sizeof...(Keys) - 1) {
        ss << ", ";
      }
    }
    ss << ") IN " << table_names[kId];
    return ss.str();
  }

  std::string getScanStmt() {
    std::stringstream ss;
    ss << "SELECT " << table_desc << " FROM " << table_names[kId];
    return ss.str();
  }

 public:
  PersistentSet(sqlite::Connection &db)
      : table_desc(getTableDesc()), db((db.Execute(getCreateStmt()), db)),
        insert_stmt(db.Prepare(getInsertStmt())),
        test_stmt(db.Prepare<int>(getTestStmt())),
        scan_stmt(db.Prepare<Keys...>(getScanStmt())) {

    std::stringstream ss;
    for (size_t i = 0; i < sizeof...(Keys); ++i) {
      ss = {};
      ss << "SELECT " << table_desc << " FROM " << table_names[kId]
         << " WHERE key" << i << " = ?1";
      get_stmts.emplace_back(db.Prepare<Keys...>(ss.str()));
    }

    for (size_t i = 0; i < sizeof...(Keys); ++i) {
      ss = {};
      ss << "SELECT " << table_desc << " FROM " << table_names[kId]
         << " WHERE ";
      for (size_t j = 0; j <= i; j++) {
        ss << "key" << j << " = ?" << (j + 1);
        if (j != i) {
          ss << " AND ";
        }
      }
      get_by_prefix_stmts.emplace_back(db.Prepare<Keys...>(ss.str()));
    }
  }

  void Insert(Keys... keys) const {
    insert_stmt.Bind(keys...);
    insert_stmt.Execute();
  }

  bool Test(Keys... keys) const {
    test_stmt.Bind(keys...);
    return *test_stmt.begin();
  }

  template <
      size_t I, typename C,
      typename K = typename std::tuple_element<I, std::tuple<Keys...>>::type>
  void GetByField(const K &key, C callback) const {
    GetByFieldImpl<I>(key, callback,
                      std::make_index_sequence<sizeof...(Keys)>());
  }

  template <typename C, typename... Ks>
  void GetByPrefix(const std::tuple<Ks...> &prefix, C callback) const {
    GetByPrefixImpl(prefix, callback, std::make_index_sequence<sizeof...(Ks)>(),
                    std::make_index_sequence<sizeof...(Keys)>());
  }

  template <typename C> void Scan(C callback) const {
    ScanImpl(callback, std::make_index_sequence<sizeof...(Keys)>());
  }
};

// Persistent mapping from keys to values.
template <uint8_t kId, typename K, typename V> class PersistentMap {
 private:
  sqlite::Connection &db;
  sqlite::Query<> set_stmt;
  sqlite::Query<V> get_stmt;
  sqlite::Query<V> get_or_set_stmt;

  static std::string getCreateStmt() {
    std::stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS " << table_names[kId]
       << "(key, value, PRIMARY KEY(key))";
    return ss.str();
  }

  static std::string getSetStmt() {
    std::stringstream ss;
    ss << "INSERT OR REPLACE INTO " << table_names[kId]
       << "(key, value) VALUES (?1, ?2)";
    return ss.str();
  }

  static std::string getGetStmt() {
    std::stringstream ss;
    ss << "SELECT value FROM " << table_names[kId] << " WHERE key = ?1";
    return ss.str();
  }

  static std::string getGetOrSetStmt() {
    std::stringstream ss;
    ss << "INSERT INTO " << table_names[kId]
       << "(key, value) VALUES(?1, ?2) ON CONFLICT DO UPDATE SET value=value "
          "RETURNING value";
    return ss.str();
  }

 public:
  PersistentMap(sqlite::Connection &db)
      : db((db.Execute(getCreateStmt()), db)),
        set_stmt(db.Prepare(getSetStmt())),
        get_stmt(db.Prepare<V>(getGetStmt())),
        get_or_set_stmt(db.Prepare<V>(getGetOrSetStmt())) {}

  V GetOrSet(K key, V val) const {
    get_or_set_stmt.Bind(key, val);
    return *get_or_set_stmt.begin();
  }

  void Set(K key, V val) const {
    set_stmt.Bind(key, val);
    set_stmt.Execute();
  }

  std::optional<V> TryGet(K key) const {
    get_stmt.Bind(key);
    auto cur = get_stmt.begin();
    if (cur) {
      return *cur;
    }
    return std::nullopt;
  }
};

} // namespace mx
