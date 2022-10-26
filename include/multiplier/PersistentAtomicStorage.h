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

template<size_t key, typename T>
class PersistentAtomicStorage {
 private:
  sqlite::Connection &db;
  std::shared_ptr<sqlite::Statement> load_stmt, store_stmt, fetch_add_stmt;

 public:
  PersistentAtomicStorage(sqlite::Connection& db) : db(db) {
    db.Execute("CREATE TABLE IF NOT EXISTS atomic_storage(key INTEGER PRIMARY KEY, value INTEGER)");
    load_stmt = db.Prepare("SELECT value FROM atomic_storage WHERE key = ?1");
    store_stmt = db.Prepare("INSERT OR REPLACE INTO atomic_storage(key, value) VALUES (?1, ?2)");
    fetch_add_stmt = db.Prepare("INSERT INTO atomic_storage(key, value) VALUES (?1, ?2) ON CONFLICT DO UPDATE SET value=(value + ?2) RETURNING (value - ?2)");
  }

  T load() {
    load_stmt->BindValues(std::uint64_t{key});
    if(load_stmt->ExecuteStep()) {
        auto res = load_stmt->GetResult();
        T value;
        res.Columns(value);
        load_stmt->ExecuteStep();
        return value;
    }
    return {};
  }

  void store(const T& value) {
    store_stmt->BindValues(std::uint64_t{key}, value);
    store_stmt->Execute();
  }

  T fetch_add(const T& value) {
    fetch_add_stmt->BindValues(std::uint64_t{key}, value);
    fetch_add_stmt->ExecuteStep();
    auto res = fetch_add_stmt->GetResult();
    T new_value;
    res.Columns(new_value);
    fetch_add_stmt->ExecuteStep();
    return new_value;
  }

  operator T() {
    return load();
  }

  PersistentAtomicStorage& operator=(const T& value) {
    store(value);
  }
};

template<size_t key, typename T>
using atomic = PersistentAtomicStorage<key, T>;

}