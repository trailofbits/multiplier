// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/PersistentMap.h>

#include <mutex>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <unordered_map>

namespace mx {
PersistentMapBase::~PersistentMapBase(void) {}

PersistentMapBase::PersistentMapBase(sqlite::Connection& db, uint8_t id) : db(db) {
  auto create_stmt = db.Prepare("CREATE TABLE IF NOT EXISTS " + std::string(table_names[id]) + "(key, value, PRIMARY KEY(key))");
  create_stmt->Execute();

  set_stmt = db.Prepare("INSERT OR REPLACE INTO " + std::string(table_names[id]) + "(key, value) VALUES (?1, ?2)");
  get_stmt = db.Prepare("SELECT key, value FROM " + std::string(table_names[id]) + " WHERE key = ?1");
  get_or_set_stmt = db.Prepare("INSERT INTO " + std::string(table_names[id]) + "(key, value) VALUES(?1, ?2) ON CONFLICT DO UPDATE SET value=value RETURNING key, value");
  prefix_stmt = db.Prepare("SELECT key, value FROM " + std::string(table_names[id]) + " WHERE key >= ?1 ORDER BY key ASC");
}

void PersistentMapBase::MatchCommonPrefix(
    std::string key_prefix_,
    std::function<bool(std::string_view, std::string_view)> cb) const {
  prefix_stmt->BindValues(key_prefix_);
  while(prefix_stmt->ExecuteStep()) {
    auto res = prefix_stmt->GetResult();
    std::string_view key, value;
    res.Columns(key, value);
    if(!key.starts_with(key_prefix_)) {
      break;
    }
    if(!cb(key, value)) {
      break;
    }
  }
}

}  // namespace mx
