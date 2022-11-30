// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "SQLiteStore.h"
#include <glog/logging.h>
#include <memory>
#include <sstream>

namespace mx {

template <size_t key, typename T> class PersistentAtomicStorage {
 private:
  sqlite::Connection &db;
  sqlite::Query<std::uint64_t> load_stmt;
  sqlite::Query<> store_stmt;
  sqlite::Query<T> fetch_add_stmt;
  sqlite::Query<> store_if_empty_stmt;

 public:
  PersistentAtomicStorage(sqlite::Connection &db)
      : db((db.Execute("CREATE TABLE IF NOT EXISTS 'mx::atomic_storage'(key "
                       "INTEGER PRIMARY KEY, value INTEGER)"),
            db)),
        load_stmt(db.Prepare<std::uint64_t>(
            "SELECT value FROM 'mx::atomic_storage' WHERE key = ?1")),
        store_stmt(
            db.Prepare("INSERT OR REPLACE INTO 'mx::atomic_storage'(key, "
                       "value) VALUES (?1, ?2)")),
        fetch_add_stmt(
            db.Prepare<T>("INSERT INTO 'mx::atomic_storage'(key, value) VALUES "
                       "(?1, ?2) ON CONFLICT DO UPDATE SET value=(value + ?2) "
                       "RETURNING (value - ?2)")),
        store_if_empty_stmt(
            db.Prepare("INSERT OR IGNORE INTO 'mx::atomic_storage'(key, value) "
                       "VALUES (?1, ?2)")) {}

  T load(void) {
    load_stmt.Bind(std::uint64_t{key});
    auto cur = load_stmt.begin();
    if (cur) {
      return *cur;
    }
    return {};
  }

  void store(const T &value) {
    store_stmt.Bind(std::uint64_t{key}, value);
    store_stmt.Execute();
  }

  void store_if_empty(const T &value) {
    store_if_empty_stmt.Bind(std::uint64_t{key}, value);
    store_if_empty_stmt.Execute();
  }

  T fetch_add(const T &value) {
    fetch_add_stmt.Bind(std::uint64_t{key}, value);
    return *fetch_add_stmt.begin();
  }

  operator T(void) { return load(); }

  PersistentAtomicStorage &operator=(const T &value) {
    store(value);
    return *this;
  }
};

template <size_t key, typename T>
using PersistentAtomic = PersistentAtomicStorage<key, T>;

} // namespace mx
